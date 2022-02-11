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
V_14 = V_43 -> V_48 -> V_49 ( V_45 , V_42 , V_46 , V_51 ) ;
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
switch ( V_1 ) {
case V_75 :
return V_4 ;
case V_76 :
return V_77 ;
}
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
if ( ( V_1 & V_76 ) &&
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
V_14 = F_31 ( V_94 , V_47 , V_76 , V_93 ) ;
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
if ( V_153 -> V_156 )
return 0 ;
V_153 -> V_156 = 1 ;
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
V_29 -> V_31 |= V_159 ;
return 0 ;
}
static int F_61 ( struct V_98 * V_99 , int V_160 , void * V_161 )
{
int V_14 = 0 ;
char * V_119 = V_161 ;
struct V_120 V_121 ;
F_62 ( & V_121 ) ;
if ( ! V_119 )
goto V_162;
V_14 = F_51 ( V_119 , & V_121 ) ;
if ( V_14 )
goto V_134;
V_162:
V_14 = F_57 ( V_99 , & V_121 , 0 , NULL ) ;
V_134:
F_63 ( & V_121 ) ;
return V_14 ;
}
static int F_64 ( struct V_44 * V_44 )
{
struct V_100 * V_163 = V_44 -> V_164 -> V_108 ;
int V_14 ;
struct V_81 V_82 ;
F_32 ( & V_82 , V_93 , V_165 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( V_163 -> V_105 , V_4 , & V_82 ) ;
V_14 = F_4 ( L_10 , V_163 -> V_105 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_67 ( struct V_166 * V_167 )
{
struct V_27 * V_27 = F_10 ( V_167 -> V_38 ) ;
struct V_20 * V_168 = V_167 -> V_39 -> V_40 ;
struct V_28 * V_29 ;
int V_14 ;
if ( V_167 -> V_169 )
return 0 ;
V_29 = V_27 -> V_30 ;
if ( V_29 -> V_22 == NULL || V_29 -> V_22 == V_168 -> V_22 )
return 0 ;
if ( V_167 -> V_170 & ( V_171 | V_172 ) ) {
struct V_25 * V_78 ;
V_14 = 0 ;
F_34 () ;
V_78 = F_68 ( V_23 ) ;
if ( F_69 ( V_78 != NULL ) )
V_14 = F_31 ( V_78 ,
V_29 -> V_22 ,
V_76 ,
V_93 ) ;
F_39 () ;
if ( V_14 != 0 )
return V_14 ;
} else if ( V_167 -> V_170 )
return - V_158 ;
V_168 -> V_22 = V_29 -> V_22 ;
V_167 -> V_173 |= V_174 ;
return 0 ;
}
static void F_70 ( struct V_166 * V_167 )
{
struct V_20 * V_168 = V_167 -> V_39 -> V_40 ;
if ( V_168 -> V_22 != V_168 -> V_60 )
V_23 -> V_175 = 0 ;
}
static int F_71 ( struct V_166 * V_167 )
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
static int F_75 ( struct V_27 * V_27 , struct V_27 * V_176 ,
const struct V_177 * V_177 , const char * * V_42 ,
void * * V_178 , T_3 * V_179 )
{
struct V_28 * V_180 = V_27 -> V_30 ;
struct V_11 * V_47 = F_44 () ;
struct V_11 * V_29 = F_11 ( V_27 ) ;
struct V_11 * V_181 = F_11 ( V_176 ) ;
int V_182 ;
if ( V_42 )
* V_42 = V_183 ;
if ( V_178 && V_179 ) {
F_34 () ;
V_182 = F_76 ( V_47 -> V_19 , V_181 -> V_19 ,
& V_47 -> V_61 ) ;
F_39 () ;
if ( V_182 > 0 && ( ( V_182 & V_8 ) != 0 ) &&
F_77 ( V_176 ) ) {
V_29 = V_181 ;
V_180 -> V_31 |= V_184 ;
}
* V_178 = F_78 ( V_29 -> V_19 , V_55 ) ;
if ( * V_178 == NULL )
return - V_53 ;
* V_179 = strlen ( V_29 -> V_19 ) ;
}
return 0 ;
}
static int F_79 ( struct V_44 * V_185 , struct V_27 * V_176 ,
struct V_44 * V_186 )
{
struct V_11 * V_29 ;
struct V_81 V_82 ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_165 ) ;
F_65 ( & V_82 , V_185 ) ;
V_29 = F_11 ( F_58 ( V_185 ) ) ;
V_14 = F_66 ( V_29 , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_185 ) , V_5 , V_14 ) ;
if ( V_14 == 0 && F_80 ( V_186 ) ) {
V_29 = F_11 ( F_58 ( V_186 ) ) ;
F_65 ( & V_82 , V_186 ) ;
V_14 = F_66 ( V_29 , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_186 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_81 ( struct V_27 * V_176 , struct V_44 * V_44 )
{
struct V_27 * V_43 = F_58 ( V_44 ) ;
struct V_81 V_82 ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_165 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( F_11 ( V_43 ) , V_5 , & V_82 ) ;
V_14 = F_8 ( V_43 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_32 ( & V_82 , V_93 , V_187 ) ;
F_82 ( & V_82 , V_176 ) ;
V_14 = F_66 ( F_11 ( V_176 ) , V_5 , & V_82 ) ;
V_14 = F_8 ( V_176 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_83 ( struct V_27 * V_176 , struct V_44 * V_44 )
{
struct V_81 V_82 ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_165 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( F_11 ( F_58 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_32 ( & V_82 , V_93 , V_187 ) ;
F_82 ( & V_82 , V_176 ) ;
V_14 = F_66 ( F_11 ( V_176 ) , V_5 , & V_82 ) ;
V_14 = F_8 ( V_176 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_84 ( struct V_27 * V_188 ,
struct V_44 * V_185 ,
struct V_27 * V_189 ,
struct V_44 * V_186 )
{
int V_14 ;
struct V_11 * V_29 ;
struct V_81 V_82 ;
F_32 ( & V_82 , V_93 , V_165 ) ;
F_65 ( & V_82 , V_185 ) ;
V_29 = F_11 ( F_58 ( V_185 ) ) ;
V_14 = F_66 ( V_29 , V_77 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_185 ) , V_77 , V_14 ) ;
if ( V_14 == 0 && F_80 ( V_186 ) ) {
V_29 = F_11 ( F_58 ( V_186 ) ) ;
F_65 ( & V_82 , V_186 ) ;
V_14 = F_66 ( V_29 , V_77 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_186 ) , V_77 , V_14 ) ;
}
return V_14 ;
}
static int F_85 ( struct V_27 * V_27 , int V_190 )
{
struct V_81 V_82 ;
int V_191 = V_190 & V_192 ;
int V_14 ;
V_190 &= ( V_4 | V_5 | V_6 | V_7 ) ;
if ( V_190 == 0 )
return 0 ;
if ( V_191 )
return - V_193 ;
F_32 ( & V_82 , V_93 , V_187 ) ;
F_82 ( & V_82 , V_27 ) ;
V_14 = F_66 ( F_11 ( V_27 ) , V_190 , & V_82 ) ;
V_14 = F_8 ( V_27 , V_190 , V_14 ) ;
return V_14 ;
}
static int F_86 ( struct V_44 * V_44 , struct V_194 * V_194 )
{
struct V_81 V_82 ;
int V_14 ;
if ( V_194 -> V_195 & V_196 )
return 0 ;
F_32 ( & V_82 , V_93 , V_165 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( F_11 ( F_58 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_44 ) , V_5 , V_14 ) ;
return V_14 ;
}
static int F_87 ( const struct V_197 * V_197 )
{
struct V_81 V_82 ;
struct V_27 * V_27 = F_58 ( V_197 -> V_44 ) ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_198 ) ;
F_88 ( & V_82 , * V_197 ) ;
V_14 = F_66 ( F_11 ( V_27 ) , V_4 , & V_82 ) ;
V_14 = F_8 ( V_27 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_89 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_178 , T_3 V_199 , int V_160 )
{
struct V_81 V_82 ;
struct V_11 * V_47 ;
int V_200 = 0 ;
int V_201 = 0 ;
int V_202 = 0 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_203 ) == 0 ||
strcmp ( V_42 , V_204 ) == 0 ||
strcmp ( V_42 , V_205 ) == 0 ) {
V_200 = 1 ;
V_201 = 1 ;
} else if ( strcmp ( V_42 , V_206 ) == 0 ||
strcmp ( V_42 , V_207 ) == 0 ) {
V_200 = 1 ;
V_201 = 1 ;
V_202 = 1 ;
} else if ( strcmp ( V_42 , V_208 ) == 0 ) {
V_200 = 1 ;
if ( V_199 != V_209 ||
strncmp ( V_178 , V_210 , V_209 ) != 0 )
V_14 = - V_139 ;
} else
V_14 = F_90 ( V_44 , V_42 , V_178 , V_199 , V_160 ) ;
if ( V_200 && ! F_45 ( V_157 ) )
V_14 = - V_158 ;
if ( V_14 == 0 && V_201 ) {
V_47 = V_199 ? F_16 ( V_178 , V_199 ) : NULL ;
if ( F_59 ( V_47 ) )
V_14 = F_60 ( V_47 ) ;
else if ( V_47 == NULL || ( V_202 &&
( V_47 == & V_211 || V_47 == & V_212 ) ) )
V_14 = - V_139 ;
}
F_32 ( & V_82 , V_93 , V_165 ) ;
F_65 ( & V_82 , V_44 ) ;
if ( V_14 == 0 ) {
V_14 = F_66 ( F_11 ( F_58 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_44 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static void F_91 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_178 , T_3 V_199 , int V_160 )
{
struct V_11 * V_47 ;
struct V_28 * V_29 = F_58 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_208 ) == 0 ) {
V_29 -> V_31 |= V_159 ;
return;
}
if ( strcmp ( V_42 , V_203 ) == 0 ) {
V_47 = F_16 ( V_178 , V_199 ) ;
if ( ! F_59 ( V_47 ) )
V_29 -> V_37 = V_47 ;
else
V_29 -> V_37 = & V_213 ;
} else if ( strcmp ( V_42 , V_206 ) == 0 ) {
V_47 = F_16 ( V_178 , V_199 ) ;
if ( ! F_59 ( V_47 ) )
V_29 -> V_22 = V_47 ;
else
V_29 -> V_22 = & V_213 ;
} else if ( strcmp ( V_42 , V_207 ) == 0 ) {
V_47 = F_16 ( V_178 , V_199 ) ;
if ( ! F_59 ( V_47 ) )
V_29 -> V_214 = V_47 ;
else
V_29 -> V_214 = & V_213 ;
}
return;
}
static int F_92 ( struct V_44 * V_44 , const char * V_42 )
{
struct V_81 V_82 ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_165 ) ;
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
if ( strcmp ( V_42 , V_203 ) == 0 ||
strcmp ( V_42 , V_204 ) == 0 ||
strcmp ( V_42 , V_205 ) == 0 ||
strcmp ( V_42 , V_206 ) == 0 ||
strcmp ( V_42 , V_208 ) == 0 ||
strcmp ( V_42 , V_207 ) == 0 ) {
if ( ! F_45 ( V_157 ) )
V_14 = - V_158 ;
} else
V_14 = F_94 ( V_44 , V_42 ) ;
if ( V_14 != 0 )
return V_14 ;
F_32 ( & V_82 , V_93 , V_165 ) ;
F_65 ( & V_82 , V_44 ) ;
V_14 = F_66 ( F_11 ( F_58 ( V_44 ) ) , V_5 , & V_82 ) ;
V_14 = F_8 ( F_58 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_29 = F_58 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_203 ) == 0 )
V_29 -> V_22 = NULL ;
else if ( strcmp ( V_42 , V_207 ) == 0 )
V_29 -> V_214 = NULL ;
else if ( strcmp ( V_42 , V_208 ) == 0 )
V_29 -> V_31 &= ~ V_159 ;
return 0 ;
}
static int F_95 ( const struct V_27 * V_27 ,
const char * V_42 , void * * V_46 ,
bool V_215 )
{
struct V_216 * V_217 ;
struct V_218 * V_219 ;
struct V_98 * V_163 ;
struct V_27 * V_43 = (struct V_27 * ) V_27 ;
struct V_11 * V_29 ;
int V_220 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_183 ) == 0 ) {
V_29 = F_11 ( V_27 ) ;
V_220 = strlen ( V_29 -> V_19 ) ;
* V_46 = V_29 -> V_19 ;
return V_220 ;
}
V_163 = V_43 -> V_33 ;
if ( V_163 -> V_221 != V_222 )
return - V_50 ;
V_219 = F_96 ( V_43 ) ;
if ( V_219 == NULL || V_219 -> V_223 == NULL )
return - V_50 ;
V_217 = V_219 -> V_223 -> V_224 ;
if ( strcmp ( V_42 , V_225 ) == 0 )
V_29 = V_217 -> V_226 ;
else if ( strcmp ( V_42 , V_227 ) == 0 )
V_29 = V_217 -> V_228 ;
else
return - V_50 ;
V_220 = strlen ( V_29 -> V_19 ) ;
if ( V_14 == 0 ) {
* V_46 = V_29 -> V_19 ;
V_14 = V_220 ;
}
return V_14 ;
}
static int F_97 ( struct V_27 * V_27 , char * V_46 ,
T_3 V_229 )
{
int V_179 = sizeof( V_203 ) ;
if ( V_46 != NULL && V_179 <= V_229 )
memcpy ( V_46 , V_203 , V_179 ) ;
return V_179 ;
}
static void F_98 ( const struct V_27 * V_27 , T_4 * V_230 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
* V_230 = V_29 -> V_37 -> V_231 ;
}
static int F_99 ( struct V_38 * V_38 , int V_190 )
{
return 0 ;
}
static int F_100 ( struct V_38 * V_38 )
{
struct V_11 * V_47 = F_44 () ;
V_38 -> V_232 = V_47 ;
return 0 ;
}
static void F_101 ( struct V_38 * V_38 )
{
V_38 -> V_232 = NULL ;
}
static int F_102 ( struct V_38 * V_38 , unsigned int V_233 ,
unsigned long V_234 )
{
int V_14 = 0 ;
struct V_81 V_82 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_32 ( & V_82 , V_93 , V_198 ) ;
F_88 ( & V_82 , V_38 -> V_235 ) ;
if ( F_103 ( V_233 ) & V_236 ) {
V_14 = F_66 ( F_11 ( V_27 ) , V_5 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_103 ( V_233 ) & V_237 ) ) {
V_14 = F_66 ( F_11 ( V_27 ) , V_4 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_104 ( struct V_38 * V_38 , unsigned int V_233 )
{
struct V_81 V_82 ;
int V_14 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_32 ( & V_82 , V_93 , V_198 ) ;
F_88 ( & V_82 , V_38 -> V_235 ) ;
V_14 = F_66 ( F_11 ( V_27 ) , V_9 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_105 ( struct V_38 * V_38 , unsigned int V_233 ,
unsigned long V_234 )
{
struct V_81 V_82 ;
int V_14 = 0 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
switch ( V_233 ) {
case V_238 :
break;
case V_239 :
case V_240 :
F_32 ( & V_82 , V_93 , V_198 ) ;
F_88 ( & V_82 , V_38 -> V_235 ) ;
V_14 = F_66 ( F_11 ( V_27 ) , V_9 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
break;
case V_241 :
case V_242 :
F_32 ( & V_82 , V_93 , V_198 ) ;
F_88 ( & V_82 , V_38 -> V_235 ) ;
V_14 = F_66 ( F_11 ( V_27 ) , V_5 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_106 ( struct V_38 * V_38 ,
unsigned long V_243 , unsigned long V_244 ,
unsigned long V_160 )
{
struct V_11 * V_47 ;
struct V_11 * V_245 ;
struct V_67 * V_246 ;
struct V_20 * V_21 ;
struct V_11 * V_247 ;
struct V_28 * V_29 ;
int V_182 ;
int V_248 ;
int V_249 ;
int V_14 ;
if ( V_38 == NULL )
return 0 ;
V_29 = F_10 ( V_38 ) -> V_30 ;
if ( V_29 -> V_214 == NULL )
return 0 ;
V_245 = V_29 -> V_214 ;
V_21 = F_5 () ;
V_47 = F_44 () ;
V_14 = 0 ;
F_34 () ;
F_24 (srp, &skp->smk_rules, list) {
V_247 = V_246 -> V_250 ;
if ( V_245 -> V_19 == V_247 -> V_19 )
continue;
V_182 = F_76 ( V_246 -> V_251 -> V_19 ,
V_247 -> V_19 ,
& V_21 -> V_61 ) ;
if ( V_182 == - V_252 )
V_182 = V_246 -> V_253 ;
else
V_182 &= V_246 -> V_253 ;
if ( V_182 == 0 )
continue;
V_248 = F_76 ( V_245 -> V_19 , V_247 -> V_19 ,
& V_245 -> V_61 ) ;
if ( V_248 == - V_252 ) {
V_14 = - V_90 ;
break;
}
V_249 = F_76 ( V_245 -> V_19 , V_247 -> V_19 ,
& V_21 -> V_61 ) ;
if ( V_249 != - V_252 )
V_248 &= V_249 ;
if ( ( V_182 | V_248 ) != V_248 ) {
V_14 = - V_90 ;
break;
}
}
F_39 () ;
return V_14 ;
}
static void F_107 ( struct V_38 * V_38 )
{
V_38 -> V_232 = F_44 () ;
}
static int F_108 ( struct V_25 * V_254 ,
struct V_255 * V_256 , int V_257 )
{
struct V_11 * V_47 ;
struct V_11 * V_258 = F_36 ( V_254 -> V_39 -> V_40 ) ;
struct V_38 * V_38 ;
int V_14 ;
struct V_81 V_82 ;
V_38 = F_109 ( V_256 , struct V_38 , V_259 ) ;
V_47 = V_38 -> V_232 ;
V_14 = V_253 ( V_47 , V_258 , V_5 , NULL ) ;
V_14 = F_2 ( L_11 , V_47 , V_258 , V_5 , V_14 ) ;
if ( V_14 != 0 && F_110 ( V_254 , V_96 ) )
V_14 = 0 ;
F_32 ( & V_82 , V_93 , V_86 ) ;
F_33 ( & V_82 , V_254 ) ;
F_38 ( V_47 -> V_19 , V_258 -> V_19 , V_5 , V_14 , & V_82 ) ;
return V_14 ;
}
static int F_111 ( struct V_38 * V_38 )
{
int V_14 ;
int V_182 = 0 ;
struct V_81 V_82 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
if ( F_112 ( F_113 ( V_27 ) ) )
return 0 ;
F_32 ( & V_82 , V_93 , V_198 ) ;
F_88 ( & V_82 , V_38 -> V_235 ) ;
if ( V_38 -> V_260 & V_261 )
V_182 = V_4 ;
if ( V_38 -> V_260 & V_262 )
V_182 |= V_5 ;
V_14 = F_66 ( F_11 ( V_27 ) , V_182 , & V_82 ) ;
V_14 = F_9 ( V_38 , V_182 , V_14 ) ;
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
F_32 ( & V_82 , V_93 , V_198 ) ;
F_88 ( & V_82 , V_38 -> V_235 ) ;
V_14 = V_253 ( V_21 -> V_22 , F_11 ( V_27 ) , V_4 , & V_82 ) ;
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
struct V_67 * V_263 ;
struct V_64 * V_264 ;
struct V_64 * V_265 ;
if ( V_21 == NULL )
return;
V_39 -> V_40 = NULL ;
F_28 ( & V_21 -> V_62 ) ;
F_117 (l, n, &tsp->smk_rules) {
V_263 = F_118 ( V_264 , struct V_67 , V_70 ) ;
F_119 ( & V_263 -> V_70 ) ;
F_17 ( V_263 ) ;
}
F_17 ( V_21 ) ;
}
static int F_120 ( struct V_39 * V_266 , const struct V_39 * V_267 ,
T_1 V_59 )
{
struct V_20 * V_268 = V_267 -> V_40 ;
struct V_20 * V_269 ;
int V_14 ;
V_269 = F_21 ( V_268 -> V_22 , V_268 -> V_22 , V_59 ) ;
if ( V_269 == NULL )
return - V_53 ;
V_14 = F_23 ( & V_269 -> V_61 , & V_268 -> V_61 , V_59 ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_26 ( & V_269 -> V_62 , & V_268 -> V_62 ,
V_59 ) ;
if ( V_14 != 0 )
return V_14 ;
V_266 -> V_40 = V_269 ;
return 0 ;
}
static void F_121 ( struct V_39 * V_266 , const struct V_39 * V_267 )
{
struct V_20 * V_268 = V_267 -> V_40 ;
struct V_20 * V_269 = V_266 -> V_40 ;
V_269 -> V_22 = V_268 -> V_22 ;
V_269 -> V_60 = V_268 -> V_22 ;
F_20 ( & V_269 -> V_63 ) ;
F_22 ( & V_269 -> V_61 ) ;
}
static int F_122 ( struct V_39 * V_266 , T_4 V_230 )
{
struct V_20 * V_269 = V_266 -> V_40 ;
struct V_11 * V_47 = F_123 ( V_230 ) ;
if ( V_47 == NULL )
return - V_139 ;
V_269 -> V_22 = V_47 ;
return 0 ;
}
static int F_124 ( struct V_39 * V_266 ,
struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_20 * V_21 = V_266 -> V_40 ;
V_21 -> V_60 = V_29 -> V_37 ;
V_21 -> V_22 = V_21 -> V_60 ;
return 0 ;
}
static int F_125 ( struct V_25 * V_122 , int V_270 ,
const char * V_271 )
{
struct V_81 V_82 ;
struct V_11 * V_47 = F_7 ( V_122 ) ;
int V_14 ;
F_32 ( & V_82 , V_271 , V_86 ) ;
F_33 ( & V_82 , V_122 ) ;
V_14 = F_66 ( V_47 , V_270 , & V_82 ) ;
V_14 = F_6 ( V_122 , V_270 , V_14 ) ;
return V_14 ;
}
static int F_126 ( struct V_25 * V_122 , T_5 V_272 )
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
static void F_129 ( struct V_25 * V_122 , T_4 * V_230 )
{
struct V_11 * V_47 = F_7 ( V_122 ) ;
* V_230 = V_47 -> V_231 ;
}
static int F_130 ( struct V_25 * V_122 , int V_273 )
{
return F_125 ( V_122 , V_5 , V_93 ) ;
}
static int F_131 ( struct V_25 * V_122 , int V_274 )
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
static int F_136 ( struct V_25 * V_122 , struct V_275 * V_276 ,
int V_277 , T_4 V_230 )
{
struct V_81 V_82 ;
struct V_11 * V_47 ;
struct V_11 * V_258 = F_7 ( V_122 ) ;
int V_14 ;
F_32 ( & V_82 , V_93 , V_86 ) ;
F_33 ( & V_82 , V_122 ) ;
if ( V_230 == 0 ) {
V_14 = F_66 ( V_258 , V_5 , & V_82 ) ;
V_14 = F_6 ( V_122 , V_5 , V_14 ) ;
return V_14 ;
}
V_47 = F_123 ( V_230 ) ;
V_14 = V_253 ( V_47 , V_258 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_12 , V_47 , V_258 , V_5 , V_14 ) ;
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
static int F_139 ( struct V_219 * V_223 , int V_278 , T_1 V_279 )
{
struct V_11 * V_47 = F_44 () ;
struct V_216 * V_217 ;
V_217 = F_15 ( sizeof( struct V_216 ) , V_279 ) ;
if ( V_217 == NULL )
return - V_53 ;
V_217 -> V_226 = V_47 ;
V_217 -> V_228 = V_47 ;
V_217 -> V_280 = NULL ;
V_223 -> V_224 = V_217 ;
return 0 ;
}
static void F_140 ( struct V_219 * V_223 )
{
F_17 ( V_223 -> V_224 ) ;
}
static struct V_11 * F_141 ( struct V_281 * V_282 )
{
struct V_283 * V_284 ;
struct V_285 * V_286 = & V_282 -> V_287 ;
if ( V_286 -> V_288 == 0 )
return NULL ;
F_24 (snp, &smk_net4addr_list, list)
if ( V_284 -> V_289 . V_288 ==
( V_286 -> V_288 & V_284 -> V_290 . V_288 ) )
return V_284 -> V_74 ;
return NULL ;
}
static bool F_142 ( struct V_291 * V_282 )
{
T_6 * V_292 = ( T_6 * ) & V_282 -> V_293 ;
T_7 * V_294 = ( T_7 * ) & V_282 -> V_293 ;
if ( V_294 [ 0 ] == 0 && V_294 [ 1 ] == 0 && V_294 [ 2 ] == 0 && V_292 [ 6 ] == 0 &&
F_143 ( V_292 [ 7 ] ) == 1 )
return true ;
return false ;
}
static struct V_11 * F_144 ( struct V_291 * V_282 )
{
struct V_295 * V_284 ;
struct V_296 * V_297 = & V_282 -> V_293 ;
int V_3 ;
int V_298 = 0 ;
if ( F_142 ( V_282 ) )
return NULL ;
F_24 (snp, &smk_net6addr_list, list) {
for ( V_298 = 1 , V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( V_284 -> V_74 == NULL )
continue;
if ( ( V_297 -> V_299 [ V_3 ] & V_284 -> V_290 . V_299 [ V_3 ] ) !=
V_284 -> V_289 . V_299 [ V_3 ] ) {
V_298 = 0 ;
break;
}
}
if ( V_298 )
return V_284 -> V_74 ;
}
return NULL ;
}
static int F_145 ( struct V_219 * V_223 , int V_300 )
{
struct V_11 * V_47 ;
struct V_216 * V_217 = V_223 -> V_224 ;
int V_14 = 0 ;
F_146 () ;
F_147 ( V_223 ) ;
if ( V_217 -> V_228 == V_301 ||
V_300 == V_302 )
F_148 ( V_223 ) ;
else {
V_47 = V_217 -> V_228 ;
V_14 = F_149 ( V_223 , V_223 -> V_303 , & V_47 -> V_304 ) ;
}
F_150 ( V_223 ) ;
F_151 () ;
return V_14 ;
}
static int F_152 ( struct V_219 * V_223 , struct V_281 * V_297 )
{
struct V_11 * V_47 ;
int V_14 ;
int V_305 ;
struct V_11 * V_306 ;
struct V_216 * V_217 = V_223 -> V_224 ;
struct V_81 V_82 ;
F_34 () ;
V_306 = F_141 ( V_297 ) ;
if ( V_306 != NULL ) {
#ifdef F_153
struct V_307 V_308 ;
F_154 ( & V_82 , V_93 , V_309 , & V_308 ) ;
V_82 . V_310 . V_311 . V_308 -> V_278 = V_297 -> V_312 ;
V_82 . V_310 . V_311 . V_308 -> V_313 = V_297 -> V_314 ;
V_82 . V_310 . V_311 . V_308 -> V_315 . V_316 = V_297 -> V_287 . V_288 ;
#endif
V_305 = V_302 ;
V_47 = V_217 -> V_228 ;
V_14 = V_253 ( V_47 , V_306 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_13 , V_47 , V_306 , V_5 , V_14 ) ;
} else {
V_305 = V_317 ;
V_14 = 0 ;
}
F_39 () ;
if ( V_14 != 0 )
return V_14 ;
return F_145 ( V_223 , V_305 ) ;
}
static int F_155 ( struct V_11 * V_318 ,
struct V_11 * V_319 ,
struct V_291 * V_320 , int V_321 )
{
#ifdef F_153
struct V_307 V_308 ;
#endif
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
F_154 ( & V_82 , V_93 , V_309 , & V_308 ) ;
V_82 . V_310 . V_311 . V_308 -> V_278 = V_322 ;
V_82 . V_310 . V_311 . V_308 -> V_313 = F_143 ( V_320 -> V_323 ) ;
if ( V_321 == V_324 )
V_82 . V_310 . V_311 . V_308 -> V_325 . V_326 = V_320 -> V_293 ;
else
V_82 . V_310 . V_311 . V_308 -> V_325 . V_316 = V_320 -> V_293 ;
#endif
V_14 = V_253 ( V_318 , V_319 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_14 , V_318 , V_319 , V_5 , V_14 ) ;
return V_14 ;
}
static void F_156 ( struct V_218 * V_219 , struct V_327 * V_320 )
{
struct V_219 * V_223 = V_219 -> V_223 ;
struct V_291 * V_328 ;
struct V_216 * V_217 = V_219 -> V_223 -> V_224 ;
struct V_329 * V_330 ;
unsigned short V_331 = 0 ;
if ( V_320 == NULL ) {
F_27 (spp, &smk_ipv6_port_list, list) {
if ( V_223 != V_330 -> V_332 )
continue;
V_330 -> V_226 = V_217 -> V_226 ;
V_330 -> V_228 = V_217 -> V_228 ;
return;
}
return;
}
V_328 = (struct V_291 * ) V_320 ;
V_331 = F_143 ( V_328 -> V_323 ) ;
if ( V_331 == 0 )
return;
F_27 (spp, &smk_ipv6_port_list, list) {
if ( V_330 -> V_333 != V_331 )
continue;
V_330 -> V_333 = V_331 ;
V_330 -> V_332 = V_223 ;
V_330 -> V_226 = V_217 -> V_226 ;
V_330 -> V_228 = V_217 -> V_228 ;
return;
}
V_330 = F_15 ( sizeof( * V_330 ) , V_52 ) ;
if ( V_330 == NULL )
return;
V_330 -> V_333 = V_331 ;
V_330 -> V_332 = V_223 ;
V_330 -> V_226 = V_217 -> V_226 ;
V_330 -> V_228 = V_217 -> V_228 ;
F_29 ( & V_330 -> V_70 , & V_334 ) ;
return;
}
static int F_157 ( struct V_219 * V_223 , struct V_291 * V_320 ,
int V_321 )
{
struct V_329 * V_330 ;
struct V_216 * V_217 = V_223 -> V_224 ;
struct V_11 * V_47 = NULL ;
unsigned short V_331 ;
struct V_11 * V_319 ;
if ( V_321 == V_324 ) {
V_47 = F_144 ( V_320 ) ;
V_319 = V_217 -> V_226 ;
} else {
V_47 = V_217 -> V_228 ;
V_319 = F_144 ( V_320 ) ;
}
if ( V_47 != NULL && V_319 != NULL )
return F_155 ( V_47 , V_319 , V_320 , V_321 ) ;
if ( V_47 == NULL )
V_47 = V_301 ;
if ( V_319 == NULL )
V_319 = V_301 ;
if ( ! F_142 ( V_320 ) )
return F_155 ( V_47 , V_319 , V_320 , V_321 ) ;
if ( V_321 == V_324 )
return 0 ;
V_331 = F_143 ( V_320 -> V_323 ) ;
F_27 (spp, &smk_ipv6_port_list, list) {
if ( V_330 -> V_333 != V_331 )
continue;
V_319 = V_330 -> V_226 ;
if ( V_321 == V_335 )
V_217 -> V_280 = V_330 -> V_228 ;
break;
}
return F_155 ( V_47 , V_319 , V_320 , V_321 ) ;
}
static int F_158 ( struct V_27 * V_27 , const char * V_42 ,
const void * V_178 , T_3 V_199 , int V_160 )
{
struct V_11 * V_47 ;
struct V_28 * V_336 = V_27 -> V_30 ;
struct V_216 * V_217 ;
struct V_218 * V_219 ;
int V_14 = 0 ;
if ( V_178 == NULL || V_199 > V_51 || V_199 == 0 )
return - V_139 ;
V_47 = F_16 ( V_178 , V_199 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
if ( strcmp ( V_42 , V_183 ) == 0 ) {
V_336 -> V_37 = V_47 ;
V_336 -> V_31 |= V_337 ;
return 0 ;
}
if ( V_27 -> V_33 -> V_221 != V_222 )
return - V_50 ;
V_219 = F_96 ( V_27 ) ;
if ( V_219 == NULL || V_219 -> V_223 == NULL )
return - V_50 ;
V_217 = V_219 -> V_223 -> V_224 ;
if ( strcmp ( V_42 , V_225 ) == 0 )
V_217 -> V_226 = V_47 ;
else if ( strcmp ( V_42 , V_227 ) == 0 ) {
V_217 -> V_228 = V_47 ;
if ( V_219 -> V_223 -> V_303 == V_338 ) {
V_14 = F_145 ( V_219 -> V_223 , V_317 ) ;
if ( V_14 != 0 )
F_159 ( V_339
L_15 ,
V_93 , - V_14 ) ;
}
} else
return - V_50 ;
#ifdef F_160
if ( V_219 -> V_223 -> V_303 == V_322 )
F_156 ( V_219 , NULL ) ;
#endif
return 0 ;
}
static int F_161 ( struct V_218 * V_219 , int V_278 ,
int type , int V_340 , int V_341 )
{
struct V_216 * V_217 ;
if ( V_219 -> V_223 == NULL )
return 0 ;
if ( F_112 ( V_23 -> V_160 & V_342 ) ) {
V_217 = V_219 -> V_223 -> V_224 ;
V_217 -> V_226 = & V_212 ;
V_217 -> V_228 = & V_212 ;
}
if ( V_278 != V_338 )
return 0 ;
return F_145 ( V_219 -> V_223 , V_317 ) ;
}
static int F_162 ( struct V_218 * V_219 , struct V_327 * V_320 ,
int V_343 )
{
if ( V_219 -> V_223 != NULL && V_219 -> V_223 -> V_303 == V_322 )
F_156 ( V_219 , V_320 ) ;
return 0 ;
}
static int F_163 ( struct V_218 * V_219 , struct V_327 * V_297 ,
int V_343 )
{
int V_14 = 0 ;
#if F_164 ( V_344 )
struct V_291 * V_282 = (struct V_291 * ) V_297 ;
#endif
#ifdef F_165
struct V_11 * V_345 ;
struct V_216 * V_217 = V_219 -> V_223 -> V_224 ;
#endif
if ( V_219 -> V_223 == NULL )
return 0 ;
switch ( V_219 -> V_223 -> V_303 ) {
case V_338 :
if ( V_343 < sizeof( struct V_281 ) )
return - V_139 ;
V_14 = F_152 ( V_219 -> V_223 , (struct V_281 * ) V_297 ) ;
break;
case V_322 :
if ( V_343 < sizeof( struct V_291 ) )
return - V_139 ;
#ifdef F_165
V_345 = F_144 ( V_282 ) ;
if ( V_345 != NULL )
V_14 = F_155 ( V_217 -> V_228 , V_345 , V_282 ,
V_335 ) ;
#endif
#ifdef F_160
V_14 = F_157 ( V_219 -> V_223 , V_282 , V_335 ) ;
#endif
break;
}
return V_14 ;
}
static int F_166 ( int V_160 )
{
int V_182 = 0 ;
if ( V_160 & V_346 )
V_182 |= V_4 ;
if ( V_160 & V_347 )
V_182 |= V_5 ;
if ( V_160 & V_348 )
V_182 |= V_6 ;
return V_182 ;
}
static int F_167 ( struct V_349 * V_350 )
{
struct V_11 * V_47 = F_44 () ;
V_350 -> V_40 = V_47 ;
return 0 ;
}
static void F_168 ( struct V_349 * V_350 )
{
V_350 -> V_40 = NULL ;
}
static struct V_11 * F_169 ( struct V_351 * V_352 )
{
return (struct V_11 * ) V_352 -> V_353 . V_40 ;
}
static int F_170 ( struct V_351 * V_352 )
{
struct V_354 * V_29 = & V_352 -> V_353 ;
struct V_11 * V_47 = F_44 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_171 ( struct V_351 * V_352 )
{
struct V_354 * V_29 = & V_352 -> V_353 ;
V_29 -> V_40 = NULL ;
}
static int F_172 ( struct V_351 * V_352 , int V_270 )
{
struct V_11 * V_217 = F_169 ( V_352 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
F_32 ( & V_82 , V_93 , V_355 ) ;
V_82 . V_310 . V_311 . V_356 = V_352 -> V_353 . V_357 ;
#endif
V_14 = F_66 ( V_217 , V_270 , & V_82 ) ;
V_14 = F_4 ( L_16 , V_217 , V_270 , V_14 ) ;
return V_14 ;
}
static int F_173 ( struct V_351 * V_352 , int V_358 )
{
int V_182 ;
V_182 = F_166 ( V_358 ) ;
return F_172 ( V_352 , V_182 ) ;
}
static int F_174 ( struct V_351 * V_352 , int V_233 )
{
int V_182 ;
switch ( V_233 ) {
case V_359 :
case V_360 :
V_182 = V_4 ;
break;
case V_361 :
case V_362 :
case V_363 :
case V_364 :
V_182 = V_77 ;
break;
case V_365 :
case V_366 :
return 0 ;
default:
return - V_139 ;
}
return F_172 ( V_352 , V_182 ) ;
}
static int F_175 ( struct V_351 * V_352 , char T_8 * V_367 ,
int V_358 )
{
int V_182 ;
V_182 = F_166 ( V_358 ) ;
return F_172 ( V_352 , V_182 ) ;
}
static struct V_11 * F_176 ( struct V_368 * V_369 )
{
return (struct V_11 * ) V_369 -> V_370 . V_40 ;
}
static int F_177 ( struct V_368 * V_369 )
{
struct V_354 * V_29 = & V_369 -> V_370 ;
struct V_11 * V_47 = F_44 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_178 ( struct V_368 * V_369 )
{
struct V_354 * V_29 = & V_369 -> V_370 ;
V_29 -> V_40 = NULL ;
}
static int F_179 ( struct V_368 * V_369 , int V_270 )
{
struct V_11 * V_217 = F_176 ( V_369 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
F_32 ( & V_82 , V_93 , V_355 ) ;
V_82 . V_310 . V_311 . V_356 = V_369 -> V_370 . V_357 ;
#endif
V_14 = F_66 ( V_217 , V_270 , & V_82 ) ;
V_14 = F_4 ( L_17 , V_217 , V_270 , V_14 ) ;
return V_14 ;
}
static int F_180 ( struct V_368 * V_369 , int V_371 )
{
int V_182 ;
V_182 = F_166 ( V_371 ) ;
return F_179 ( V_369 , V_182 ) ;
}
static int F_181 ( struct V_368 * V_369 , int V_233 )
{
int V_182 ;
switch ( V_233 ) {
case V_372 :
case V_373 :
case V_374 :
case V_375 :
case V_376 :
case V_359 :
case V_377 :
V_182 = V_4 ;
break;
case V_378 :
case V_379 :
case V_364 :
case V_361 :
V_182 = V_77 ;
break;
case V_365 :
case V_380 :
return 0 ;
default:
return - V_139 ;
}
return F_179 ( V_369 , V_182 ) ;
}
static int F_182 ( struct V_368 * V_369 , struct V_381 * V_382 ,
unsigned V_383 , int V_384 )
{
return F_179 ( V_369 , V_77 ) ;
}
static int F_183 ( struct V_385 * V_386 )
{
struct V_354 * V_387 = & V_386 -> V_388 ;
struct V_11 * V_47 = F_44 () ;
V_387 -> V_40 = V_47 ;
return 0 ;
}
static void F_184 ( struct V_385 * V_386 )
{
struct V_354 * V_387 = & V_386 -> V_388 ;
V_387 -> V_40 = NULL ;
}
static struct V_11 * F_185 ( struct V_385 * V_386 )
{
return (struct V_11 * ) V_386 -> V_388 . V_40 ;
}
static int F_186 ( struct V_385 * V_386 , int V_270 )
{
struct V_11 * V_389 = F_185 ( V_386 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
F_32 ( & V_82 , V_93 , V_355 ) ;
V_82 . V_310 . V_311 . V_356 = V_386 -> V_388 . V_357 ;
#endif
V_14 = F_66 ( V_389 , V_270 , & V_82 ) ;
V_14 = F_4 ( L_18 , V_389 , V_270 , V_14 ) ;
return V_14 ;
}
static int F_187 ( struct V_385 * V_386 , int V_390 )
{
int V_182 ;
V_182 = F_166 ( V_390 ) ;
return F_186 ( V_386 , V_182 ) ;
}
static int F_188 ( struct V_385 * V_386 , int V_233 )
{
int V_182 ;
switch ( V_233 ) {
case V_359 :
case V_391 :
V_182 = V_4 ;
break;
case V_361 :
case V_364 :
V_182 = V_77 ;
break;
case V_365 :
case V_392 :
return 0 ;
default:
return - V_139 ;
}
return F_186 ( V_386 , V_182 ) ;
}
static int F_189 ( struct V_385 * V_386 , struct V_349 * V_350 ,
int V_390 )
{
int V_182 ;
V_182 = F_166 ( V_390 ) ;
return F_186 ( V_386 , V_182 ) ;
}
static int F_190 ( struct V_385 * V_386 , struct V_349 * V_350 ,
struct V_25 * V_393 , long type , int V_1 )
{
return F_186 ( V_386 , V_77 ) ;
}
static int F_191 ( struct V_354 * V_394 , short V_395 )
{
struct V_11 * V_396 = V_394 -> V_40 ;
int V_182 = F_166 ( V_395 ) ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
F_32 ( & V_82 , V_93 , V_355 ) ;
V_82 . V_310 . V_311 . V_356 = V_394 -> V_357 ;
#endif
V_14 = F_66 ( V_396 , V_182 , & V_82 ) ;
V_14 = F_4 ( L_19 , V_396 , V_182 , V_14 ) ;
return V_14 ;
}
static void F_192 ( struct V_354 * V_394 , T_4 * V_230 )
{
struct V_11 * V_396 = V_394 -> V_40 ;
* V_230 = V_396 -> V_231 ;
}
static void F_193 ( struct V_44 * V_397 , struct V_27 * V_27 )
{
struct V_98 * V_163 ;
struct V_100 * V_101 ;
struct V_28 * V_29 ;
struct V_11 * V_47 ;
struct V_11 * V_398 = F_44 () ;
struct V_11 * V_399 ;
char V_400 [ V_209 ] ;
int V_401 = 0 ;
int V_14 ;
struct V_44 * V_45 ;
if ( V_27 == NULL )
return;
V_29 = V_27 -> V_30 ;
F_194 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_31 & V_337 )
goto V_402;
V_163 = V_27 -> V_33 ;
V_101 = V_163 -> V_108 ;
V_399 = V_101 -> V_104 ;
if ( V_397 -> V_403 == V_397 ) {
switch ( V_163 -> V_221 ) {
case V_404 :
V_101 -> V_102 = & V_211 ;
V_101 -> V_104 = & V_211 ;
V_29 -> V_37 = V_101 -> V_102 ;
break;
case V_405 :
V_29 -> V_37 = F_44 () ;
break;
case V_406 :
V_29 -> V_37 = F_44 () ;
break;
default:
V_29 -> V_37 = V_101 -> V_102 ;
break;
}
V_29 -> V_31 |= V_337 ;
goto V_402;
}
switch ( V_163 -> V_221 ) {
case V_407 :
case V_406 :
case V_222 :
case V_404 :
V_399 = & V_211 ;
break;
case V_408 :
V_399 = V_398 ;
break;
case V_409 :
break;
case V_405 :
V_399 = & V_211 ;
default:
if ( F_195 ( V_27 -> V_410 ) ) {
V_399 = & V_211 ;
break;
}
if ( V_27 -> V_48 -> V_49 == NULL )
break;
V_45 = F_196 ( V_397 ) ;
V_47 = F_13 ( V_203 , V_27 , V_45 ) ;
if ( ! F_197 ( V_47 ) )
V_399 = V_47 ;
if ( F_198 ( V_27 -> V_410 ) ) {
if ( V_29 -> V_31 & V_184 ) {
V_29 -> V_31 &= ~ V_184 ;
V_14 = V_27 -> V_48 -> V_411 ( V_45 ,
V_208 ,
V_210 , V_209 ,
0 ) ;
} else {
V_14 = V_27 -> V_48 -> V_49 ( V_45 ,
V_208 , V_400 ,
V_209 ) ;
if ( V_14 >= 0 && strncmp ( V_400 , V_210 ,
V_209 ) != 0 )
V_14 = - V_139 ;
}
if ( V_14 >= 0 )
V_401 = V_159 ;
}
V_47 = F_13 ( V_206 , V_27 , V_45 ) ;
if ( F_59 ( V_47 ) || V_47 == & V_211 ||
V_47 == & V_212 )
V_47 = NULL ;
V_29 -> V_22 = V_47 ;
V_47 = F_13 ( V_207 , V_27 , V_45 ) ;
if ( F_59 ( V_47 ) || V_47 == & V_211 ||
V_47 == & V_212 )
V_47 = NULL ;
V_29 -> V_214 = V_47 ;
F_199 ( V_45 ) ;
break;
}
if ( V_399 == NULL )
V_29 -> V_37 = V_398 ;
else
V_29 -> V_37 = V_399 ;
V_29 -> V_31 |= ( V_337 | V_401 ) ;
V_402:
F_200 ( & V_29 -> V_56 ) ;
return;
}
static int F_201 ( struct V_25 * V_122 , char * V_42 , char * * V_178 )
{
struct V_11 * V_47 = F_7 ( V_122 ) ;
char * V_111 ;
int V_412 ;
if ( strcmp ( V_42 , L_20 ) != 0 )
return - V_139 ;
V_111 = F_78 ( V_47 -> V_19 , V_52 ) ;
if ( V_111 == NULL )
return - V_53 ;
V_412 = strlen ( V_111 ) ;
* V_178 = V_111 ;
return V_412 ;
}
static int F_202 ( struct V_25 * V_122 , char * V_42 ,
void * V_178 , T_3 V_199 )
{
struct V_20 * V_21 = F_5 () ;
struct V_39 * V_266 ;
struct V_11 * V_47 ;
struct V_71 * V_413 ;
int V_14 ;
if ( V_122 != V_23 )
return - V_158 ;
if ( ! F_45 ( V_157 ) && F_203 ( & V_21 -> V_62 ) )
return - V_158 ;
if ( V_178 == NULL || V_199 == 0 || V_199 >= V_51 )
return - V_139 ;
if ( strcmp ( V_42 , L_20 ) != 0 )
return - V_139 ;
V_47 = F_16 ( V_178 , V_199 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
if ( V_47 == & V_212 )
return - V_158 ;
if ( ! F_45 ( V_157 ) ) {
V_14 = - V_158 ;
F_27 (sklep, &tsp->smk_relabel, list)
if ( V_413 -> V_74 == V_47 ) {
V_14 = 0 ;
break;
}
if ( V_14 )
return V_14 ;
}
V_266 = F_204 () ;
if ( V_266 == NULL )
return - V_53 ;
V_21 = V_266 -> V_40 ;
V_21 -> V_22 = V_47 ;
F_28 ( & V_21 -> V_62 ) ;
F_205 ( V_266 ) ;
return V_199 ;
}
static int F_206 ( struct V_219 * V_219 ,
struct V_219 * V_414 , struct V_219 * V_415 )
{
struct V_11 * V_47 ;
struct V_11 * V_247 ;
struct V_216 * V_217 = V_219 -> V_224 ;
struct V_216 * V_416 = V_414 -> V_224 ;
struct V_216 * V_336 = V_415 -> V_224 ;
struct V_81 V_82 ;
int V_14 = 0 ;
#ifdef F_153
struct V_307 V_308 ;
#endif
if ( ! F_45 ( V_96 ) ) {
V_47 = V_217 -> V_228 ;
V_247 = V_416 -> V_226 ;
#ifdef F_153
F_154 ( & V_82 , V_93 , V_309 , & V_308 ) ;
F_207 ( & V_82 , V_414 ) ;
#endif
V_14 = V_253 ( V_47 , V_247 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_21 , V_47 , V_247 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_247 = V_416 -> V_228 ;
V_47 = V_217 -> V_226 ;
V_14 = V_253 ( V_247 , V_47 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_21 , V_247 , V_47 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_336 -> V_280 = V_217 -> V_228 ;
V_217 -> V_280 = V_416 -> V_228 ;
}
return V_14 ;
}
static int F_208 ( struct V_218 * V_219 , struct V_218 * V_414 )
{
struct V_216 * V_217 = V_219 -> V_223 -> V_224 ;
struct V_216 * V_416 = V_414 -> V_223 -> V_224 ;
struct V_81 V_82 ;
int V_14 ;
#ifdef F_153
struct V_307 V_308 ;
F_154 ( & V_82 , V_93 , V_309 , & V_308 ) ;
F_207 ( & V_82 , V_414 -> V_223 ) ;
#endif
if ( F_45 ( V_96 ) )
return 0 ;
V_14 = V_253 ( V_217 -> V_228 , V_416 -> V_226 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_22 , V_217 -> V_228 , V_416 -> V_226 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_209 ( struct V_218 * V_219 , struct V_417 * V_350 ,
int V_199 )
{
struct V_281 * V_282 = (struct V_281 * ) V_350 -> V_418 ;
#if F_164 ( V_344 )
struct V_291 * V_297 = (struct V_291 * ) V_350 -> V_418 ;
#endif
#ifdef F_165
struct V_216 * V_217 = V_219 -> V_223 -> V_224 ;
struct V_11 * V_345 ;
#endif
int V_14 = 0 ;
if ( V_282 == NULL )
return 0 ;
switch ( V_282 -> V_312 ) {
case V_419 :
V_14 = F_152 ( V_219 -> V_223 , V_282 ) ;
break;
case V_420 :
#ifdef F_165
V_345 = F_144 ( V_297 ) ;
if ( V_345 != NULL )
V_14 = F_155 ( V_217 -> V_228 , V_345 , V_297 ,
V_335 ) ;
#endif
#ifdef F_160
V_14 = F_157 ( V_219 -> V_223 , V_297 , V_421 ) ;
#endif
break;
}
return V_14 ;
}
static struct V_11 * F_210 ( struct V_422 * V_297 ,
struct V_216 * V_217 )
{
struct V_11 * V_47 ;
int V_298 = 0 ;
int V_423 ;
int V_424 ;
if ( ( V_297 -> V_160 & V_425 ) != 0 ) {
F_34 () ;
F_27 (skp, &smack_known_list, list) {
if ( V_297 -> V_426 . V_427 . V_428 != V_47 -> V_304 . V_426 . V_427 . V_428 )
continue;
if ( ( V_297 -> V_160 & V_429 ) == 0 ) {
if ( ( V_47 -> V_304 . V_160 &
V_429 ) == 0 )
V_298 = 1 ;
break;
}
for ( V_423 = - 1 , V_424 = - 1 ; V_423 == V_424 ; ) {
V_423 = F_211 ( V_297 -> V_426 . V_427 . V_430 ,
V_423 + 1 ) ;
V_424 = F_211 (
V_47 -> V_304 . V_426 . V_427 . V_430 ,
V_424 + 1 ) ;
if ( V_423 < 0 || V_424 < 0 )
break;
}
if ( V_423 == V_424 ) {
V_298 = 1 ;
break;
}
}
F_39 () ;
if ( V_298 )
return V_47 ;
if ( V_217 != NULL && V_217 -> V_226 == & V_211 )
return & V_212 ;
return & V_211 ;
}
if ( ( V_297 -> V_160 & V_431 ) != 0 ) {
V_47 = F_123 ( V_297 -> V_426 . V_230 ) ;
F_212 ( V_47 == NULL ) ;
return V_47 ;
}
return V_301 ;
}
static int F_213 ( struct V_432 * V_433 , struct V_291 * V_282 )
{
T_9 V_434 ;
int V_435 ;
int V_436 = - V_139 ;
struct V_437 V_438 ;
struct V_437 * V_439 ;
T_6 V_440 ;
struct V_441 V_442 , * V_443 ;
struct V_444 V_445 , * V_446 ;
struct V_447 V_448 , * V_449 ;
V_282 -> V_323 = 0 ;
V_435 = F_214 ( V_433 ) ;
V_439 = F_215 ( V_433 , V_435 , sizeof( V_438 ) , & V_438 ) ;
if ( V_439 == NULL )
return - V_139 ;
V_282 -> V_293 = V_439 -> V_326 ;
V_434 = V_439 -> V_434 ;
V_435 += sizeof( V_438 ) ;
V_435 = F_216 ( V_433 , V_435 , & V_434 , & V_440 ) ;
if ( V_435 < 0 )
return - V_139 ;
V_436 = V_434 ;
switch ( V_436 ) {
case V_450 :
V_443 = F_215 ( V_433 , V_435 , sizeof( V_442 ) , & V_442 ) ;
if ( V_443 != NULL )
V_282 -> V_323 = V_443 -> V_451 ;
break;
case V_452 :
V_446 = F_215 ( V_433 , V_435 , sizeof( V_445 ) , & V_445 ) ;
if ( V_446 != NULL )
V_282 -> V_323 = V_446 -> V_451 ;
break;
case V_453 :
V_449 = F_215 ( V_433 , V_435 , sizeof( V_448 ) , & V_448 ) ;
if ( V_449 != NULL )
V_282 -> V_323 = V_449 -> V_454 ;
break;
}
return V_436 ;
}
static int F_217 ( struct V_219 * V_223 , struct V_432 * V_433 )
{
struct V_422 V_455 ;
struct V_216 * V_217 = V_223 -> V_224 ;
struct V_11 * V_47 = NULL ;
int V_14 = 0 ;
struct V_81 V_82 ;
#ifdef F_153
struct V_307 V_308 ;
#endif
#if F_164 ( V_344 )
struct V_291 V_456 ;
int V_436 ;
#endif
switch ( V_223 -> V_303 ) {
case V_338 :
#ifdef F_218
if ( V_433 && V_433 -> V_457 != 0 ) {
V_47 = F_123 ( V_433 -> V_457 ) ;
goto V_458;
}
#endif
F_219 ( & V_455 ) ;
V_14 = F_220 ( V_433 , V_223 -> V_303 , & V_455 ) ;
if ( V_14 == 0 )
V_47 = F_210 ( & V_455 , V_217 ) ;
else
V_47 = V_301 ;
F_221 ( & V_455 ) ;
#ifdef F_218
V_458:
#endif
#ifdef F_153
F_154 ( & V_82 , V_93 , V_309 , & V_308 ) ;
V_82 . V_310 . V_311 . V_308 -> V_278 = V_223 -> V_303 ;
V_82 . V_310 . V_311 . V_308 -> V_459 = V_433 -> V_460 ;
F_222 ( V_433 , & V_82 . V_310 , NULL ) ;
#endif
V_14 = V_253 ( V_47 , V_217 -> V_226 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_23 , V_47 , V_217 -> V_226 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_223 ( V_433 , V_14 , 0 ) ;
break;
#if F_164 ( V_344 )
case V_322 :
V_436 = F_213 ( V_433 , & V_456 ) ;
if ( V_436 != V_452 && V_436 != V_450 )
break;
#ifdef F_165
if ( V_433 && V_433 -> V_457 != 0 )
V_47 = F_123 ( V_433 -> V_457 ) ;
else
V_47 = F_144 ( & V_456 ) ;
if ( V_47 == NULL )
V_47 = V_301 ;
#ifdef F_153
F_154 ( & V_82 , V_93 , V_309 , & V_308 ) ;
V_82 . V_310 . V_311 . V_308 -> V_278 = V_223 -> V_303 ;
V_82 . V_310 . V_311 . V_308 -> V_459 = V_433 -> V_460 ;
F_224 ( V_433 , & V_82 . V_310 , NULL ) ;
#endif
V_14 = V_253 ( V_47 , V_217 -> V_226 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_24 , V_47 , V_217 -> V_226 ,
V_5 , V_14 ) ;
#endif
#ifdef F_160
V_14 = F_157 ( V_223 , & V_456 , V_324 ) ;
#endif
break;
#endif
}
return V_14 ;
}
static int F_225 ( struct V_218 * V_219 ,
char T_8 * V_461 ,
int T_8 * V_462 , unsigned V_179 )
{
struct V_216 * V_217 ;
char * V_463 = L_25 ;
int V_412 = 1 ;
int V_14 = 0 ;
V_217 = V_219 -> V_223 -> V_224 ;
if ( V_217 -> V_280 != NULL ) {
V_463 = V_217 -> V_280 -> V_19 ;
V_412 = strlen ( V_463 ) + 1 ;
}
if ( V_412 > V_179 )
V_14 = - V_464 ;
else if ( F_226 ( V_461 , V_463 , V_412 ) != 0 )
V_14 = - V_465 ;
if ( F_227 ( V_412 , V_462 ) != 0 )
V_14 = - V_465 ;
return V_14 ;
}
static int F_228 ( struct V_218 * V_219 ,
struct V_432 * V_433 , T_4 * V_230 )
{
struct V_422 V_455 ;
struct V_216 * V_217 = NULL ;
struct V_11 * V_47 ;
int V_278 = V_466 ;
T_4 V_2 = 0 ;
int V_14 ;
if ( V_433 != NULL ) {
if ( V_433 -> V_340 == F_229 ( V_467 ) )
V_278 = V_338 ;
#if F_164 ( V_344 )
else if ( V_433 -> V_340 == F_229 ( V_468 ) )
V_278 = V_322 ;
#endif
}
if ( V_278 == V_466 && V_219 != NULL )
V_278 = V_219 -> V_223 -> V_303 ;
switch ( V_278 ) {
case V_469 :
V_217 = V_219 -> V_223 -> V_224 ;
V_2 = V_217 -> V_228 -> V_231 ;
break;
case V_338 :
#ifdef F_218
V_2 = V_433 -> V_457 ;
if ( V_2 != 0 )
break;
#endif
if ( V_219 != NULL && V_219 -> V_223 != NULL )
V_217 = V_219 -> V_223 -> V_224 ;
F_219 ( & V_455 ) ;
V_14 = F_220 ( V_433 , V_278 , & V_455 ) ;
if ( V_14 == 0 ) {
V_47 = F_210 ( & V_455 , V_217 ) ;
V_2 = V_47 -> V_231 ;
}
F_221 ( & V_455 ) ;
break;
case V_322 :
#ifdef F_165
V_2 = V_433 -> V_457 ;
#endif
break;
}
* V_230 = V_2 ;
if ( V_2 == 0 )
return - V_139 ;
return 0 ;
}
static void F_230 ( struct V_219 * V_223 , struct V_218 * V_470 )
{
struct V_216 * V_217 ;
struct V_11 * V_47 = F_44 () ;
if ( V_223 == NULL ||
( V_223 -> V_303 != V_338 && V_223 -> V_303 != V_322 ) )
return;
V_217 = V_223 -> V_224 ;
V_217 -> V_226 = V_47 ;
V_217 -> V_228 = V_47 ;
}
static int F_231 ( struct V_219 * V_223 , struct V_432 * V_433 ,
struct V_471 * V_472 )
{
T_10 V_278 = V_223 -> V_303 ;
struct V_11 * V_47 ;
struct V_216 * V_217 = V_223 -> V_224 ;
struct V_422 V_455 ;
struct V_281 V_473 ;
struct V_474 * V_475 ;
struct V_11 * V_476 ;
int V_14 ;
struct V_81 V_82 ;
#ifdef F_153
struct V_307 V_308 ;
#endif
#if F_164 ( V_344 )
if ( V_278 == V_322 ) {
if ( V_433 -> V_340 == F_229 ( V_467 ) )
V_278 = V_338 ;
else
return 0 ;
}
#endif
#ifdef F_218
if ( V_433 && V_433 -> V_457 != 0 ) {
V_47 = F_123 ( V_433 -> V_457 ) ;
goto V_458;
}
#endif
F_219 ( & V_455 ) ;
V_14 = F_220 ( V_433 , V_278 , & V_455 ) ;
if ( V_14 == 0 )
V_47 = F_210 ( & V_455 , V_217 ) ;
else
V_47 = & V_477 ;
F_221 ( & V_455 ) ;
#ifdef F_218
V_458:
#endif
#ifdef F_153
F_154 ( & V_82 , V_93 , V_309 , & V_308 ) ;
V_82 . V_310 . V_311 . V_308 -> V_278 = V_278 ;
V_82 . V_310 . V_311 . V_308 -> V_459 = V_433 -> V_460 ;
F_222 ( V_433 , & V_82 . V_310 , NULL ) ;
#endif
V_14 = V_253 ( V_47 , V_217 -> V_226 , V_5 , & V_82 ) ;
V_14 = F_2 ( L_26 , V_47 , V_217 -> V_226 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_472 -> V_478 = V_47 -> V_231 ;
V_475 = F_232 ( V_433 ) ;
V_473 . V_287 . V_288 = V_475 -> V_326 ;
F_34 () ;
V_476 = F_141 ( & V_473 ) ;
F_39 () ;
if ( V_476 == NULL )
V_14 = F_233 ( V_472 , & V_47 -> V_304 ) ;
else
F_234 ( V_472 ) ;
return V_14 ;
}
static void F_235 ( struct V_219 * V_223 ,
const struct V_471 * V_472 )
{
struct V_216 * V_217 = V_223 -> V_224 ;
struct V_11 * V_47 ;
if ( V_472 -> V_478 != 0 ) {
V_47 = F_123 ( V_472 -> V_478 ) ;
V_217 -> V_280 = V_47 ;
} else
V_217 -> V_280 = NULL ;
}
static int F_236 ( struct V_479 * V_479 , const struct V_39 * V_39 ,
unsigned long V_160 )
{
struct V_11 * V_47 = F_36 ( V_39 -> V_40 ) ;
V_479 -> V_40 = V_47 ;
return 0 ;
}
static void F_237 ( struct V_479 * V_479 )
{
V_479 -> V_40 = NULL ;
}
static int F_238 ( T_11 V_480 ,
const struct V_39 * V_39 , unsigned V_481 )
{
struct V_479 * V_482 ;
struct V_81 V_82 ;
struct V_11 * V_258 = F_36 ( V_39 -> V_40 ) ;
int V_483 = 0 ;
int V_14 ;
V_482 = F_239 ( V_480 ) ;
if ( V_482 == NULL )
return - V_139 ;
if ( V_482 -> V_40 == NULL )
return 0 ;
if ( V_258 == NULL )
return - V_90 ;
#ifdef F_153
F_32 ( & V_82 , V_93 , V_484 ) ;
V_82 . V_310 . V_311 . V_485 . V_479 = V_482 -> V_486 ;
V_82 . V_310 . V_311 . V_485 . V_487 = V_482 -> V_488 ;
#endif
if ( V_481 & V_489 )
V_483 = V_4 ;
if ( V_481 & ( V_490 | V_491 | V_492 ) )
V_483 = V_5 ;
V_14 = V_253 ( V_258 , V_482 -> V_40 , V_483 , & V_82 ) ;
V_14 = F_2 ( L_27 , V_258 , V_482 -> V_40 , V_483 , V_14 ) ;
return V_14 ;
}
static int F_240 ( struct V_479 * V_479 , char * * V_493 )
{
struct V_11 * V_47 = V_479 -> V_40 ;
T_3 V_494 ;
char * V_495 ;
if ( V_479 -> V_40 == NULL ) {
* V_493 = NULL ;
return 0 ;
}
V_495 = F_78 ( V_47 -> V_19 , V_52 ) ;
if ( V_495 == NULL )
return - V_53 ;
V_494 = strlen ( V_495 ) + 1 ;
* V_493 = V_495 ;
return V_494 ;
}
static int F_241 ( T_4 V_496 , T_4 V_497 , char * V_498 , void * * V_499 )
{
struct V_11 * V_47 ;
char * * V_500 = ( char * * ) V_499 ;
* V_500 = NULL ;
if ( V_496 != V_501 && V_496 != V_502 )
return - V_139 ;
if ( V_497 != V_503 && V_497 != V_504 )
return - V_139 ;
V_47 = F_16 ( V_498 , 0 ) ;
if ( F_59 ( V_47 ) )
return F_60 ( V_47 ) ;
* V_500 = V_47 -> V_19 ;
return 0 ;
}
static int F_242 ( struct V_505 * V_506 )
{
struct V_507 * V_508 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_506 -> V_509 ; V_3 ++ ) {
V_508 = & V_506 -> V_510 [ V_3 ] ;
if ( V_508 -> type == V_501 || V_508 -> type == V_502 )
return 1 ;
}
return 0 ;
}
static int F_243 ( T_4 V_230 , T_4 V_496 , T_4 V_497 , void * V_499 ,
struct V_511 * V_512 )
{
struct V_11 * V_47 ;
char * V_500 = V_499 ;
if ( F_112 ( ! V_500 ) ) {
F_244 ( 1 , L_28 ) ;
return - V_252 ;
}
if ( V_496 != V_501 && V_496 != V_502 )
return 0 ;
V_47 = F_123 ( V_230 ) ;
if ( V_497 == V_503 )
return ( V_500 == V_47 -> V_19 ) ;
if ( V_497 == V_504 )
return ( V_500 != V_47 -> V_19 ) ;
return 0 ;
}
static void F_245 ( void * V_499 )
{
}
static int F_246 ( const char * V_42 )
{
return ( strcmp ( V_42 , V_183 ) == 0 ) ;
}
static int F_247 ( T_4 V_230 , char * * V_513 , T_4 * V_514 )
{
struct V_11 * V_47 = F_123 ( V_230 ) ;
if ( V_513 )
* V_513 = V_47 -> V_19 ;
* V_514 = strlen ( V_47 -> V_19 ) ;
return 0 ;
}
static int F_248 ( const char * V_513 , T_4 V_514 , T_4 * V_230 )
{
struct V_11 * V_47 = F_249 ( V_513 ) ;
if ( V_47 )
* V_230 = V_47 -> V_231 ;
else
* V_230 = 0 ;
return 0 ;
}
static void F_250 ( char * V_513 , T_4 V_514 )
{
}
static int F_251 ( struct V_27 * V_27 , void * V_515 , T_4 V_516 )
{
return F_158 ( V_27 , V_183 , V_515 , V_516 , 0 ) ;
}
static int F_252 ( struct V_44 * V_44 , void * V_515 , T_4 V_516 )
{
return F_253 ( V_44 , V_203 , V_515 , V_516 , 0 ) ;
}
static int F_254 ( struct V_27 * V_27 , void * * V_515 , T_4 * V_516 )
{
int V_179 = 0 ;
V_179 = F_95 ( V_27 , V_183 , V_515 , true ) ;
if ( V_179 < 0 )
return V_179 ;
* V_516 = V_179 ;
return 0 ;
}
static T_12 void F_255 ( void )
{
F_20 ( & V_477 . V_63 ) ;
F_20 ( & V_107 . V_63 ) ;
F_20 ( & V_103 . V_63 ) ;
F_20 ( & V_211 . V_63 ) ;
F_20 ( & V_213 . V_63 ) ;
F_20 ( & V_212 . V_63 ) ;
F_22 ( & V_477 . V_61 ) ;
F_22 ( & V_107 . V_61 ) ;
F_22 ( & V_211 . V_61 ) ;
F_22 ( & V_103 . V_61 ) ;
F_22 ( & V_213 . V_61 ) ;
F_22 ( & V_212 . V_61 ) ;
F_256 ( & V_477 ) ;
F_256 ( & V_107 ) ;
F_256 ( & V_211 ) ;
F_256 ( & V_103 ) ;
F_256 ( & V_213 ) ;
F_256 ( & V_212 ) ;
}
static T_12 int F_257 ( void )
{
struct V_39 * V_39 ;
struct V_20 * V_21 ;
if ( ! F_258 ( L_29 ) )
return 0 ;
V_54 = F_259 ( V_28 , 0 ) ;
if ( ! V_54 )
return - V_53 ;
V_21 = F_21 ( & V_103 , & V_103 ,
V_52 ) ;
if ( V_21 == NULL ) {
F_260 ( V_54 ) ;
return - V_53 ;
}
V_517 = 1 ;
F_3 ( L_30 ) ;
#ifdef F_218
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
F_255 () ;
F_261 ( V_518 , F_262 ( V_518 ) ) ;
return 0 ;
}

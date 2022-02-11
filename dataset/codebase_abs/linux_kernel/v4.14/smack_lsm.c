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
static struct V_11 * F_13 ( const char * V_41 , struct V_27 * V_42 ,
struct V_43 * V_44 )
{
int V_14 ;
char * V_45 ;
struct V_11 * V_46 = NULL ;
if ( ! ( V_42 -> V_47 & V_48 ) )
return F_14 ( - V_49 ) ;
V_45 = F_15 ( V_50 , V_51 ) ;
if ( V_45 == NULL )
return F_14 ( - V_52 ) ;
V_14 = F_16 ( V_44 , V_42 , V_41 , V_45 , V_50 ) ;
if ( V_14 < 0 )
V_46 = F_14 ( V_14 ) ;
else if ( V_14 == 0 )
V_46 = NULL ;
else
V_46 = F_17 ( V_45 , V_14 ) ;
F_18 ( V_45 ) ;
return V_46 ;
}
static struct V_28 * F_19 ( struct V_11 * V_46 )
{
struct V_28 * V_29 ;
V_29 = F_20 ( V_53 , V_54 ) ;
if ( V_29 == NULL )
return NULL ;
V_29 -> V_37 = V_46 ;
V_29 -> V_31 = 0 ;
F_21 ( & V_29 -> V_55 ) ;
return V_29 ;
}
static struct V_20 * F_22 ( struct V_11 * V_56 ,
struct V_11 * V_57 , T_1 V_58 )
{
struct V_20 * V_21 ;
V_21 = F_15 ( sizeof( struct V_20 ) , V_58 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_22 = V_56 ;
V_21 -> V_59 = V_57 ;
F_23 ( & V_21 -> V_60 ) ;
F_23 ( & V_21 -> V_61 ) ;
F_21 ( & V_21 -> V_62 ) ;
return V_21 ;
}
static int F_24 ( struct V_63 * V_64 , struct V_63 * V_65 ,
T_1 V_58 )
{
struct V_66 * V_67 ;
struct V_66 * V_68 ;
int V_14 = 0 ;
F_25 (orp, ohead, list) {
V_67 = F_15 ( sizeof( struct V_66 ) , V_58 ) ;
if ( V_67 == NULL ) {
V_14 = - V_52 ;
break;
}
* V_67 = * V_68 ;
F_26 ( & V_67 -> V_69 , V_64 ) ;
}
return V_14 ;
}
static int F_27 ( struct V_63 * V_64 , struct V_63 * V_65 ,
T_1 V_58 )
{
struct V_70 * V_71 ;
struct V_70 * V_72 ;
F_28 (oklep, ohead, list) {
V_71 = F_15 ( sizeof( struct V_70 ) , V_58 ) ;
if ( V_71 == NULL ) {
F_29 ( V_64 ) ;
return - V_52 ;
}
V_71 -> V_73 = V_72 -> V_73 ;
F_30 ( & V_71 -> V_69 , V_64 ) ;
}
return 0 ;
}
static inline unsigned int F_31 ( unsigned int V_1 )
{
if ( V_1 & V_74 )
return V_75 ;
if ( V_1 & V_76 )
return V_4 ;
return 0 ;
}
static int F_32 ( struct V_25 * V_77 ,
struct V_11 * V_78 ,
unsigned int V_1 , const char * V_79 )
{
int V_14 ;
struct V_80 V_81 , * V_82 = NULL ;
struct V_20 * V_21 ;
struct V_11 * V_83 ;
if ( ( V_1 & V_84 ) == 0 ) {
F_33 ( & V_81 , V_79 , V_85 ) ;
F_34 ( & V_81 , V_77 ) ;
V_82 = & V_81 ;
}
F_35 () ;
V_21 = F_36 ( V_77 ) -> V_40 ;
V_83 = F_37 ( V_21 ) ;
if ( ( V_1 & V_74 ) &&
( V_86 == V_87 ||
V_86 == V_88 ) ) {
if ( V_83 -> V_19 == V_78 -> V_19 )
V_14 = 0 ;
else if ( V_86 == V_88 )
V_14 = - V_89 ;
else if ( F_38 ( V_90 ) )
V_14 = 0 ;
else
V_14 = - V_89 ;
if ( V_82 )
F_39 ( V_83 -> V_19 ,
V_78 -> V_19 ,
0 , V_14 , V_82 ) ;
F_40 () ;
return V_14 ;
}
V_14 = F_41 ( V_21 , V_78 , F_31 ( V_1 ) , V_82 ) ;
F_40 () ;
return V_14 ;
}
static int F_42 ( struct V_25 * V_91 , unsigned int V_1 )
{
struct V_11 * V_46 ;
V_46 = F_7 ( V_91 ) ;
return F_32 ( V_23 , V_46 , V_1 , V_92 ) ;
}
static int F_43 ( struct V_25 * V_93 )
{
int V_14 ;
struct V_11 * V_46 ;
V_46 = F_37 ( F_5 () ) ;
V_14 = F_32 ( V_93 , V_46 , V_74 , V_92 ) ;
return V_14 ;
}
static int F_44 ( int V_94 )
{
int V_14 = 0 ;
struct V_11 * V_46 = F_45 () ;
if ( F_46 ( V_95 ) )
return 0 ;
if ( V_96 != NULL && V_96 != V_46 )
V_14 = - V_89 ;
return V_14 ;
}
static int F_47 ( struct V_97 * V_98 )
{
struct V_99 * V_100 ;
V_100 = F_15 ( sizeof( struct V_99 ) , V_51 ) ;
if ( V_100 == NULL )
return - V_52 ;
V_100 -> V_101 = & V_102 ;
V_100 -> V_103 = & V_102 ;
V_100 -> V_104 = & V_102 ;
V_100 -> V_105 = & V_106 ;
V_98 -> V_107 = V_100 ;
return 0 ;
}
static void F_48 ( struct V_97 * V_98 )
{
F_18 ( V_98 -> V_107 ) ;
V_98 -> V_107 = NULL ;
}
static int F_49 ( char * V_108 , char * V_109 )
{
char * V_110 , * V_111 , * V_112 , * V_44 ;
V_112 = ( char * ) F_50 ( V_51 ) ;
if ( V_112 == NULL )
return - V_52 ;
for ( V_110 = V_108 , V_111 = V_108 ; V_111 != NULL ; V_110 = V_111 + 1 ) {
if ( strstr ( V_110 , V_113 ) == V_110 )
V_44 = V_109 ;
else if ( strstr ( V_110 , V_114 ) == V_110 )
V_44 = V_109 ;
else if ( strstr ( V_110 , V_115 ) == V_110 )
V_44 = V_109 ;
else if ( strstr ( V_110 , V_116 ) == V_110 )
V_44 = V_109 ;
else if ( strstr ( V_110 , V_117 ) == V_110 )
V_44 = V_109 ;
else
V_44 = V_112 ;
V_111 = strchr ( V_110 , ',' ) ;
if ( V_111 != NULL )
* V_111 = '\0' ;
if ( * V_44 != '\0' )
strcat ( V_44 , L_7 ) ;
strcat ( V_44 , V_110 ) ;
}
strcpy ( V_108 , V_112 ) ;
F_51 ( ( unsigned long ) V_112 ) ;
return 0 ;
}
static int F_52 ( char * V_118 ,
struct V_119 * V_120 )
{
char * V_121 ;
char * V_122 = NULL ;
char * V_123 = NULL ;
char * V_124 = NULL ;
char * V_125 = NULL ;
char * V_126 = NULL ;
int V_14 = - V_52 ;
int V_127 = 0 ;
int V_128 ;
V_120 -> V_127 = 0 ;
if ( ! V_118 )
return 0 ;
while ( ( V_121 = F_53 ( & V_118 , L_7 ) ) != NULL ) {
T_2 args [ V_129 ] ;
if ( ! * V_121 )
continue;
V_128 = F_54 ( V_121 , V_130 , args ) ;
switch ( V_128 ) {
case V_131 :
if ( V_122 )
goto V_132;
V_122 = F_55 ( & args [ 0 ] ) ;
if ( ! V_122 )
goto V_133;
break;
case V_134 :
if ( V_123 )
goto V_132;
V_123 = F_55 ( & args [ 0 ] ) ;
if ( ! V_123 )
goto V_133;
break;
case V_135 :
if ( V_124 )
goto V_132;
V_124 = F_55 ( & args [ 0 ] ) ;
if ( ! V_124 )
goto V_133;
break;
case V_136 :
if ( V_125 )
goto V_132;
V_125 = F_55 ( & args [ 0 ] ) ;
if ( ! V_125 )
goto V_133;
break;
case V_137 :
if ( V_126 )
goto V_132;
V_126 = F_55 ( & args [ 0 ] ) ;
if ( ! V_126 )
goto V_133;
break;
default:
V_14 = - V_138 ;
F_56 ( L_8 ) ;
goto V_133;
}
}
V_120 -> V_139 = F_57 ( V_140 , sizeof( char * ) , V_51 ) ;
if ( ! V_120 -> V_139 )
goto V_133;
V_120 -> V_141 = F_57 ( V_140 , sizeof( int ) ,
V_51 ) ;
if ( ! V_120 -> V_141 )
goto V_133;
if ( V_122 ) {
V_120 -> V_139 [ V_127 ] = V_122 ;
V_120 -> V_141 [ V_127 ++ ] = V_142 ;
}
if ( V_123 ) {
V_120 -> V_139 [ V_127 ] = V_123 ;
V_120 -> V_141 [ V_127 ++ ] = V_143 ;
}
if ( V_124 ) {
V_120 -> V_139 [ V_127 ] = V_124 ;
V_120 -> V_141 [ V_127 ++ ] = V_144 ;
}
if ( V_125 ) {
V_120 -> V_139 [ V_127 ] = V_125 ;
V_120 -> V_141 [ V_127 ++ ] = V_145 ;
}
if ( V_126 ) {
V_120 -> V_139 [ V_127 ] = V_126 ;
V_120 -> V_141 [ V_127 ++ ] = V_146 ;
}
V_120 -> V_127 = V_127 ;
return 0 ;
V_132:
V_14 = - V_138 ;
F_56 ( L_9 ) ;
V_133:
F_18 ( V_122 ) ;
F_18 ( V_123 ) ;
F_18 ( V_124 ) ;
F_18 ( V_125 ) ;
F_18 ( V_126 ) ;
return V_14 ;
}
static int F_58 ( struct V_97 * V_98 ,
struct V_119 * V_120 ,
unsigned long V_147 ,
unsigned long * V_148 )
{
struct V_43 * V_149 = V_98 -> V_150 ;
struct V_27 * V_27 = F_59 ( V_149 ) ;
struct V_99 * V_151 = V_98 -> V_107 ;
struct V_28 * V_29 ;
struct V_11 * V_46 ;
int V_3 ;
int V_152 = V_120 -> V_127 ;
int V_153 = 0 ;
if ( V_151 -> V_31 & V_154 )
return 0 ;
if ( ! F_46 ( V_155 ) ) {
if ( V_152 )
return - V_156 ;
V_46 = F_45 () ;
V_151 -> V_101 = V_46 ;
V_151 -> V_103 = V_46 ;
if ( V_98 -> V_157 != & V_158 &&
V_98 -> V_159 != V_160 && V_98 -> V_159 != V_161 &&
V_98 -> V_159 != V_162 ) {
V_153 = 1 ;
V_151 -> V_31 |= V_163 ;
}
}
V_151 -> V_31 |= V_154 ;
for ( V_3 = 0 ; V_3 < V_152 ; V_3 ++ ) {
switch ( V_120 -> V_141 [ V_3 ] ) {
case V_142 :
V_46 = F_17 ( V_120 -> V_139 [ V_3 ] , 0 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
V_151 -> V_103 = V_46 ;
break;
case V_143 :
V_46 = F_17 ( V_120 -> V_139 [ V_3 ] , 0 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
V_151 -> V_104 = V_46 ;
break;
case V_144 :
V_46 = F_17 ( V_120 -> V_139 [ V_3 ] , 0 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
V_151 -> V_105 = V_46 ;
break;
case V_145 :
V_46 = F_17 ( V_120 -> V_139 [ V_3 ] , 0 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
V_151 -> V_101 = V_46 ;
break;
case V_146 :
V_46 = F_17 ( V_120 -> V_139 [ V_3 ] , 0 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
V_151 -> V_101 = V_46 ;
V_153 = 1 ;
break;
default:
break;
}
}
V_29 = V_27 -> V_30 ;
if ( V_29 == NULL ) {
V_29 = F_19 ( V_151 -> V_101 ) ;
if ( V_29 == NULL )
return - V_52 ;
V_27 -> V_30 = V_29 ;
} else
V_29 -> V_37 = V_151 -> V_101 ;
if ( V_153 )
V_29 -> V_31 |= V_164 ;
return 0 ;
}
static int F_62 ( struct V_97 * V_98 , int V_165 , void * V_166 )
{
int V_14 = 0 ;
char * V_118 = V_166 ;
struct V_119 V_120 ;
F_63 ( & V_120 ) ;
if ( ! V_118 )
goto V_167;
V_14 = F_52 ( V_118 , & V_120 ) ;
if ( V_14 )
goto V_133;
V_167:
V_14 = F_58 ( V_98 , & V_120 , 0 , NULL ) ;
V_133:
F_64 ( & V_120 ) ;
return V_14 ;
}
static int F_65 ( struct V_43 * V_43 )
{
struct V_99 * V_168 = V_43 -> V_169 -> V_107 ;
int V_14 ;
struct V_80 V_81 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( V_168 -> V_104 , V_4 , & V_81 ) ;
V_14 = F_4 ( L_10 , V_168 -> V_104 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_68 ( struct V_171 * V_172 )
{
struct V_27 * V_27 = F_10 ( V_172 -> V_38 ) ;
struct V_20 * V_173 = V_172 -> V_39 -> V_40 ;
struct V_28 * V_29 ;
struct V_99 * V_100 ;
int V_14 ;
if ( V_172 -> V_174 )
return 0 ;
V_29 = V_27 -> V_30 ;
if ( V_29 -> V_22 == NULL || V_29 -> V_22 == V_173 -> V_22 )
return 0 ;
V_100 = V_27 -> V_33 -> V_107 ;
if ( ( V_100 -> V_31 & V_163 ) &&
V_29 -> V_22 != V_100 -> V_101 )
return 0 ;
if ( V_172 -> V_175 & V_176 ) {
struct V_25 * V_77 ;
V_14 = 0 ;
F_35 () ;
V_77 = F_69 ( V_23 ) ;
if ( F_70 ( V_77 != NULL ) )
V_14 = F_32 ( V_77 ,
V_29 -> V_22 ,
V_74 ,
V_92 ) ;
F_40 () ;
if ( V_14 != 0 )
return V_14 ;
} else if ( V_172 -> V_175 )
return - V_156 ;
V_173 -> V_22 = V_29 -> V_22 ;
V_172 -> V_177 |= V_178 ;
if ( V_173 -> V_22 != V_173 -> V_59 )
V_172 -> V_179 = 1 ;
return 0 ;
}
static int F_71 ( struct V_27 * V_27 )
{
struct V_11 * V_46 = F_45 () ;
V_27 -> V_30 = F_19 ( V_46 ) ;
if ( V_27 -> V_30 == NULL )
return - V_52 ;
return 0 ;
}
static void F_72 ( struct V_180 * V_181 )
{
struct V_28 * V_182 ;
V_182 = F_73 ( V_181 , struct V_28 , V_183 ) ;
F_74 ( V_53 , V_182 ) ;
}
static void F_75 ( struct V_27 * V_27 )
{
struct V_28 * V_182 = V_27 -> V_30 ;
F_76 ( & V_182 -> V_183 , F_72 ) ;
}
static int F_77 ( struct V_27 * V_27 , struct V_27 * V_184 ,
const struct V_185 * V_185 , const char * * V_41 ,
void * * V_186 , T_3 * V_187 )
{
struct V_28 * V_182 = V_27 -> V_30 ;
struct V_11 * V_46 = F_45 () ;
struct V_11 * V_29 = F_11 ( V_27 ) ;
struct V_11 * V_188 = F_11 ( V_184 ) ;
int V_189 ;
if ( V_41 )
* V_41 = V_190 ;
if ( V_186 && V_187 ) {
F_35 () ;
V_189 = F_78 ( V_46 -> V_19 , V_188 -> V_19 ,
& V_46 -> V_60 ) ;
F_40 () ;
if ( V_189 > 0 && ( ( V_189 & V_8 ) != 0 ) &&
F_79 ( V_184 ) ) {
V_29 = V_188 ;
V_182 -> V_31 |= V_191 ;
}
* V_186 = F_80 ( V_29 -> V_19 , V_54 ) ;
if ( * V_186 == NULL )
return - V_52 ;
* V_187 = strlen ( V_29 -> V_19 ) ;
}
return 0 ;
}
static int F_81 ( struct V_43 * V_192 , struct V_27 * V_184 ,
struct V_43 * V_193 )
{
struct V_11 * V_29 ;
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_192 ) ;
V_29 = F_11 ( F_59 ( V_192 ) ) ;
V_14 = F_67 ( V_29 , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_192 ) , V_5 , V_14 ) ;
if ( V_14 == 0 && F_82 ( V_193 ) ) {
V_29 = F_11 ( F_59 ( V_193 ) ) ;
F_66 ( & V_81 , V_193 ) ;
V_14 = F_67 ( V_29 , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_193 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_83 ( struct V_27 * V_184 , struct V_43 * V_43 )
{
struct V_27 * V_42 = F_59 ( V_43 ) ;
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( V_42 ) , V_5 , & V_81 ) ;
V_14 = F_8 ( V_42 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_33 ( & V_81 , V_92 , V_194 ) ;
F_84 ( & V_81 , V_184 ) ;
V_14 = F_67 ( F_11 ( V_184 ) , V_5 , & V_81 ) ;
V_14 = F_8 ( V_184 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_85 ( struct V_27 * V_184 , struct V_43 * V_43 )
{
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_33 ( & V_81 , V_92 , V_194 ) ;
F_84 ( & V_81 , V_184 ) ;
V_14 = F_67 ( F_11 ( V_184 ) , V_5 , & V_81 ) ;
V_14 = F_8 ( V_184 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_86 ( struct V_27 * V_195 ,
struct V_43 * V_192 ,
struct V_27 * V_196 ,
struct V_43 * V_193 )
{
int V_14 ;
struct V_11 * V_29 ;
struct V_80 V_81 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_192 ) ;
V_29 = F_11 ( F_59 ( V_192 ) ) ;
V_14 = F_67 ( V_29 , V_75 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_192 ) , V_75 , V_14 ) ;
if ( V_14 == 0 && F_82 ( V_193 ) ) {
V_29 = F_11 ( F_59 ( V_193 ) ) ;
F_66 ( & V_81 , V_193 ) ;
V_14 = F_67 ( V_29 , V_75 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_193 ) , V_75 , V_14 ) ;
}
return V_14 ;
}
static int F_87 ( struct V_27 * V_27 , int V_197 )
{
struct V_99 * V_100 = V_27 -> V_33 -> V_107 ;
struct V_80 V_81 ;
int V_198 = V_197 & V_199 ;
int V_14 ;
V_197 &= ( V_4 | V_5 | V_6 | V_7 ) ;
if ( V_197 == 0 )
return 0 ;
if ( V_100 -> V_31 & V_163 ) {
if ( F_11 ( V_27 ) != V_100 -> V_101 )
return - V_89 ;
}
if ( V_198 )
return - V_200 ;
F_33 ( & V_81 , V_92 , V_194 ) ;
F_84 ( & V_81 , V_27 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_197 , & V_81 ) ;
V_14 = F_8 ( V_27 , V_197 , V_14 ) ;
return V_14 ;
}
static int F_88 ( struct V_43 * V_43 , struct V_201 * V_201 )
{
struct V_80 V_81 ;
int V_14 ;
if ( V_201 -> V_202 & V_203 )
return 0 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_5 , V_14 ) ;
return V_14 ;
}
static int F_89 ( const struct V_204 * V_204 )
{
struct V_80 V_81 ;
struct V_27 * V_27 = F_59 ( V_204 -> V_43 ) ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_205 ) ;
F_90 ( & V_81 , * V_204 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_4 , & V_81 ) ;
V_14 = F_8 ( V_27 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_91 ( struct V_43 * V_43 , const char * V_41 ,
const void * V_186 , T_3 V_206 , int V_165 )
{
struct V_80 V_81 ;
struct V_11 * V_46 ;
int V_207 = 0 ;
int V_208 = 0 ;
int V_209 = 0 ;
int V_14 = 0 ;
if ( strcmp ( V_41 , V_210 ) == 0 ||
strcmp ( V_41 , V_211 ) == 0 ||
strcmp ( V_41 , V_212 ) == 0 ) {
V_207 = 1 ;
V_208 = 1 ;
} else if ( strcmp ( V_41 , V_213 ) == 0 ||
strcmp ( V_41 , V_214 ) == 0 ) {
V_207 = 1 ;
V_208 = 1 ;
V_209 = 1 ;
} else if ( strcmp ( V_41 , V_215 ) == 0 ) {
V_207 = 1 ;
if ( V_206 != V_216 ||
strncmp ( V_186 , V_217 , V_216 ) != 0 )
V_14 = - V_138 ;
} else
V_14 = F_92 ( V_43 , V_41 , V_186 , V_206 , V_165 ) ;
if ( V_207 && ! F_46 ( V_155 ) )
V_14 = - V_156 ;
if ( V_14 == 0 && V_208 ) {
V_46 = V_206 ? F_17 ( V_186 , V_206 ) : NULL ;
if ( F_60 ( V_46 ) )
V_14 = F_61 ( V_46 ) ;
else if ( V_46 == NULL || ( V_209 &&
( V_46 == & V_218 || V_46 == & V_219 ) ) )
V_14 = - V_138 ;
}
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
if ( V_14 == 0 ) {
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static void F_93 ( struct V_43 * V_43 , const char * V_41 ,
const void * V_186 , T_3 V_206 , int V_165 )
{
struct V_11 * V_46 ;
struct V_28 * V_29 = F_59 ( V_43 ) -> V_30 ;
if ( strcmp ( V_41 , V_215 ) == 0 ) {
V_29 -> V_31 |= V_164 ;
return;
}
if ( strcmp ( V_41 , V_210 ) == 0 ) {
V_46 = F_17 ( V_186 , V_206 ) ;
if ( ! F_60 ( V_46 ) )
V_29 -> V_37 = V_46 ;
} else if ( strcmp ( V_41 , V_213 ) == 0 ) {
V_46 = F_17 ( V_186 , V_206 ) ;
if ( ! F_60 ( V_46 ) )
V_29 -> V_22 = V_46 ;
} else if ( strcmp ( V_41 , V_214 ) == 0 ) {
V_46 = F_17 ( V_186 , V_206 ) ;
if ( ! F_60 ( V_46 ) )
V_29 -> V_220 = V_46 ;
}
return;
}
static int F_94 ( struct V_43 * V_43 , const char * V_41 )
{
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_4 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_4 , V_14 ) ;
return V_14 ;
}
static int F_95 ( struct V_43 * V_43 , const char * V_41 )
{
struct V_28 * V_29 ;
struct V_80 V_81 ;
int V_14 = 0 ;
if ( strcmp ( V_41 , V_210 ) == 0 ||
strcmp ( V_41 , V_211 ) == 0 ||
strcmp ( V_41 , V_212 ) == 0 ||
strcmp ( V_41 , V_213 ) == 0 ||
strcmp ( V_41 , V_215 ) == 0 ||
strcmp ( V_41 , V_214 ) == 0 ) {
if ( ! F_46 ( V_155 ) )
V_14 = - V_156 ;
} else
V_14 = F_96 ( V_43 , V_41 ) ;
if ( V_14 != 0 )
return V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_29 = F_59 ( V_43 ) -> V_30 ;
if ( strcmp ( V_41 , V_210 ) == 0 ) {
struct V_97 * V_168 = V_43 -> V_169 ;
struct V_99 * V_100 = V_168 -> V_107 ;
V_29 -> V_37 = V_100 -> V_103 ;
} else if ( strcmp ( V_41 , V_213 ) == 0 )
V_29 -> V_22 = NULL ;
else if ( strcmp ( V_41 , V_214 ) == 0 )
V_29 -> V_220 = NULL ;
else if ( strcmp ( V_41 , V_215 ) == 0 )
V_29 -> V_31 &= ~ V_164 ;
return 0 ;
}
static int F_97 ( struct V_27 * V_27 ,
const char * V_41 , void * * V_45 ,
bool V_221 )
{
struct V_222 * V_223 ;
struct V_224 * V_225 ;
struct V_97 * V_168 ;
struct V_27 * V_42 = (struct V_27 * ) V_27 ;
struct V_11 * V_29 ;
if ( strcmp ( V_41 , V_190 ) == 0 )
V_29 = F_11 ( V_27 ) ;
else {
V_168 = V_42 -> V_33 ;
if ( V_168 -> V_159 != V_226 )
return - V_49 ;
V_225 = F_98 ( V_42 ) ;
if ( V_225 == NULL || V_225 -> V_227 == NULL )
return - V_49 ;
V_223 = V_225 -> V_227 -> V_228 ;
if ( strcmp ( V_41 , V_229 ) == 0 )
V_29 = V_223 -> V_230 ;
else if ( strcmp ( V_41 , V_231 ) == 0 )
V_29 = V_223 -> V_232 ;
else
return - V_49 ;
}
if ( V_221 ) {
* V_45 = F_80 ( V_29 -> V_19 , V_51 ) ;
if ( * V_45 == NULL )
return - V_52 ;
}
return strlen ( V_29 -> V_19 ) ;
}
static int F_99 ( struct V_27 * V_27 , char * V_45 ,
T_3 V_233 )
{
int V_187 = sizeof( V_210 ) ;
if ( V_45 != NULL && V_187 <= V_233 )
memcpy ( V_45 , V_210 , V_187 ) ;
return V_187 ;
}
static void F_100 ( struct V_27 * V_27 , T_4 * V_234 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
* V_234 = V_29 -> V_37 -> V_235 ;
}
static int F_101 ( struct V_38 * V_38 )
{
struct V_11 * V_46 = F_45 () ;
V_38 -> V_236 = V_46 ;
return 0 ;
}
static void F_102 ( struct V_38 * V_38 )
{
V_38 -> V_236 = NULL ;
}
static int F_103 ( struct V_38 * V_38 , unsigned int V_237 ,
unsigned long V_238 )
{
int V_14 = 0 ;
struct V_80 V_81 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
if ( F_104 ( F_105 ( V_27 ) ) )
return 0 ;
F_33 ( & V_81 , V_92 , V_205 ) ;
F_90 ( & V_81 , V_38 -> V_239 ) ;
if ( F_106 ( V_237 ) & V_240 ) {
V_14 = F_67 ( F_11 ( V_27 ) , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_106 ( V_237 ) & V_241 ) ) {
V_14 = F_67 ( F_11 ( V_27 ) , V_4 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_107 ( struct V_38 * V_38 , unsigned int V_237 )
{
struct V_80 V_81 ;
int V_14 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
if ( F_104 ( F_105 ( V_27 ) ) )
return 0 ;
F_33 ( & V_81 , V_92 , V_205 ) ;
F_90 ( & V_81 , V_38 -> V_239 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_9 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_108 ( struct V_38 * V_38 , unsigned int V_237 ,
unsigned long V_238 )
{
struct V_80 V_81 ;
int V_14 = 0 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
if ( F_104 ( F_105 ( V_27 ) ) )
return 0 ;
switch ( V_237 ) {
case V_242 :
break;
case V_243 :
case V_244 :
F_33 ( & V_81 , V_92 , V_205 ) ;
F_90 ( & V_81 , V_38 -> V_239 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_9 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
break;
case V_245 :
case V_246 :
F_33 ( & V_81 , V_92 , V_205 ) ;
F_90 ( & V_81 , V_38 -> V_239 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_109 ( struct V_38 * V_38 ,
unsigned long V_247 , unsigned long V_248 ,
unsigned long V_165 )
{
struct V_11 * V_46 ;
struct V_11 * V_249 ;
struct V_66 * V_250 ;
struct V_20 * V_21 ;
struct V_11 * V_251 ;
struct V_28 * V_29 ;
struct V_99 * V_100 ;
int V_189 ;
int V_252 ;
int V_253 ;
int V_14 ;
if ( V_38 == NULL )
return 0 ;
if ( F_104 ( F_105 ( F_10 ( V_38 ) ) ) )
return 0 ;
V_29 = F_10 ( V_38 ) -> V_30 ;
if ( V_29 -> V_220 == NULL )
return 0 ;
V_100 = F_10 ( V_38 ) -> V_33 -> V_107 ;
if ( V_100 -> V_31 & V_163 &&
V_29 -> V_220 != V_100 -> V_101 )
return - V_89 ;
V_249 = V_29 -> V_220 ;
V_21 = F_5 () ;
V_46 = F_45 () ;
V_14 = 0 ;
F_35 () ;
F_25 (srp, &skp->smk_rules, list) {
V_251 = V_250 -> V_254 ;
if ( V_249 -> V_19 == V_251 -> V_19 )
continue;
V_189 = F_78 ( V_250 -> V_255 -> V_19 ,
V_251 -> V_19 ,
& V_21 -> V_60 ) ;
if ( V_189 == - V_256 )
V_189 = V_250 -> V_257 ;
else
V_189 &= V_250 -> V_257 ;
if ( V_189 == 0 )
continue;
V_252 = F_78 ( V_249 -> V_19 , V_251 -> V_19 ,
& V_249 -> V_60 ) ;
if ( V_252 == - V_256 ) {
V_14 = - V_89 ;
break;
}
V_253 = F_78 ( V_249 -> V_19 , V_251 -> V_19 ,
& V_21 -> V_60 ) ;
if ( V_253 != - V_256 )
V_252 &= V_253 ;
if ( ( V_189 | V_252 ) != V_252 ) {
V_14 = - V_89 ;
break;
}
}
F_40 () ;
return V_14 ;
}
static void F_110 ( struct V_38 * V_38 )
{
V_38 -> V_236 = F_45 () ;
}
static int F_111 ( struct V_25 * V_258 ,
struct V_259 * V_260 , int V_261 )
{
struct V_11 * V_46 ;
struct V_11 * V_262 = F_37 ( V_258 -> V_39 -> V_40 ) ;
struct V_38 * V_38 ;
int V_14 ;
struct V_80 V_81 ;
V_38 = F_73 ( V_260 , struct V_38 , V_263 ) ;
V_46 = V_38 -> V_236 ;
V_14 = V_257 ( V_46 , V_262 , V_264 , NULL ) ;
V_14 = F_2 ( L_11 , V_46 , V_262 , V_264 , V_14 ) ;
if ( V_14 != 0 && F_112 ( V_258 , V_95 ) )
V_14 = 0 ;
F_33 ( & V_81 , V_92 , V_85 ) ;
F_34 ( & V_81 , V_258 ) ;
F_39 ( V_46 -> V_19 , V_262 -> V_19 , V_264 , V_14 , & V_81 ) ;
return V_14 ;
}
static int F_113 ( struct V_38 * V_38 )
{
int V_14 ;
int V_189 = 0 ;
struct V_80 V_81 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_224 * V_225 ;
struct V_20 * V_21 ;
struct V_222 * V_223 ;
if ( F_104 ( F_105 ( V_27 ) ) )
return 0 ;
F_33 ( & V_81 , V_92 , V_205 ) ;
F_90 ( & V_81 , V_38 -> V_239 ) ;
if ( V_27 -> V_33 -> V_159 == V_226 ) {
V_225 = F_98 ( V_27 ) ;
V_223 = V_225 -> V_227 -> V_228 ;
V_21 = F_5 () ;
V_14 = V_257 ( V_21 -> V_22 , V_223 -> V_232 , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_189 , V_14 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = V_257 ( V_223 -> V_230 , V_21 -> V_22 , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_189 , V_14 ) ;
return V_14 ;
}
if ( V_38 -> V_265 & V_266 )
V_189 = V_4 ;
if ( V_38 -> V_265 & V_267 )
V_189 |= V_5 ;
V_14 = F_67 ( F_11 ( V_27 ) , V_189 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_189 , V_14 ) ;
return V_14 ;
}
static int F_114 ( struct V_38 * V_38 , const struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_205 ) ;
F_90 ( & V_81 , V_38 -> V_239 ) ;
V_14 = F_41 ( V_21 , F_11 ( V_27 ) , V_4 , & V_81 ) ;
V_14 = F_12 ( V_39 , V_38 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_115 ( struct V_39 * V_39 , T_1 V_58 )
{
struct V_20 * V_21 ;
V_21 = F_22 ( NULL , NULL , V_58 ) ;
if ( V_21 == NULL )
return - V_52 ;
V_39 -> V_40 = V_21 ;
return 0 ;
}
static void F_116 ( struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_66 * V_268 ;
struct V_63 * V_269 ;
struct V_63 * V_270 ;
if ( V_21 == NULL )
return;
V_39 -> V_40 = NULL ;
F_29 ( & V_21 -> V_61 ) ;
F_117 (l, n, &tsp->smk_rules) {
V_268 = F_118 ( V_269 , struct V_66 , V_69 ) ;
F_119 ( & V_268 -> V_69 ) ;
F_18 ( V_268 ) ;
}
F_18 ( V_21 ) ;
}
static int F_120 ( struct V_39 * V_271 , const struct V_39 * V_272 ,
T_1 V_58 )
{
struct V_20 * V_273 = V_272 -> V_40 ;
struct V_20 * V_274 ;
int V_14 ;
V_274 = F_22 ( V_273 -> V_22 , V_273 -> V_22 , V_58 ) ;
if ( V_274 == NULL )
return - V_52 ;
V_271 -> V_40 = V_274 ;
V_14 = F_24 ( & V_274 -> V_60 , & V_273 -> V_60 , V_58 ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_27 ( & V_274 -> V_61 , & V_273 -> V_61 ,
V_58 ) ;
if ( V_14 != 0 )
return V_14 ;
return 0 ;
}
static void F_121 ( struct V_39 * V_271 , const struct V_39 * V_272 )
{
struct V_20 * V_273 = V_272 -> V_40 ;
struct V_20 * V_274 = V_271 -> V_40 ;
V_274 -> V_22 = V_273 -> V_22 ;
V_274 -> V_59 = V_273 -> V_22 ;
F_21 ( & V_274 -> V_62 ) ;
F_23 ( & V_274 -> V_60 ) ;
}
static int F_122 ( struct V_39 * V_271 , T_4 V_234 )
{
struct V_20 * V_274 = V_271 -> V_40 ;
V_274 -> V_22 = F_123 ( V_234 ) ;
return 0 ;
}
static int F_124 ( struct V_39 * V_271 ,
struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_20 * V_21 = V_271 -> V_40 ;
V_21 -> V_59 = V_29 -> V_37 ;
V_21 -> V_22 = V_21 -> V_59 ;
return 0 ;
}
static int F_125 ( struct V_25 * V_121 , int V_275 ,
const char * V_276 )
{
struct V_80 V_81 ;
struct V_11 * V_46 = F_7 ( V_121 ) ;
int V_14 ;
F_33 ( & V_81 , V_276 , V_85 ) ;
F_34 ( & V_81 , V_121 ) ;
V_14 = F_67 ( V_46 , V_275 , & V_81 ) ;
V_14 = F_6 ( V_121 , V_275 , V_14 ) ;
return V_14 ;
}
static int F_126 ( struct V_25 * V_121 , T_5 V_277 )
{
return F_125 ( V_121 , V_5 , V_92 ) ;
}
static int F_127 ( struct V_25 * V_121 )
{
return F_125 ( V_121 , V_4 , V_92 ) ;
}
static int F_128 ( struct V_25 * V_121 )
{
return F_125 ( V_121 , V_4 , V_92 ) ;
}
static void F_129 ( struct V_25 * V_121 , T_4 * V_234 )
{
struct V_11 * V_46 = F_7 ( V_121 ) ;
* V_234 = V_46 -> V_235 ;
}
static int F_130 ( struct V_25 * V_121 , int V_278 )
{
return F_125 ( V_121 , V_5 , V_92 ) ;
}
static int F_131 ( struct V_25 * V_121 , int V_279 )
{
return F_125 ( V_121 , V_5 , V_92 ) ;
}
static int F_132 ( struct V_25 * V_121 )
{
return F_125 ( V_121 , V_4 , V_92 ) ;
}
static int F_133 ( struct V_25 * V_121 )
{
return F_125 ( V_121 , V_5 , V_92 ) ;
}
static int F_134 ( struct V_25 * V_121 )
{
return F_125 ( V_121 , V_4 , V_92 ) ;
}
static int F_135 ( struct V_25 * V_121 )
{
return F_125 ( V_121 , V_5 , V_92 ) ;
}
static int F_136 ( struct V_25 * V_121 , struct V_280 * V_281 ,
int V_282 , T_4 V_234 )
{
struct V_80 V_81 ;
struct V_11 * V_46 ;
struct V_11 * V_262 = F_7 ( V_121 ) ;
int V_14 ;
if ( ! V_282 )
return 0 ;
F_33 ( & V_81 , V_92 , V_85 ) ;
F_34 ( & V_81 , V_121 ) ;
if ( V_234 == 0 ) {
V_14 = F_67 ( V_262 , V_264 , & V_81 ) ;
V_14 = F_6 ( V_121 , V_264 , V_14 ) ;
return V_14 ;
}
V_46 = F_123 ( V_234 ) ;
V_14 = V_257 ( V_46 , V_262 , V_264 , & V_81 ) ;
V_14 = F_2 ( L_12 , V_46 , V_262 , V_264 , V_14 ) ;
return V_14 ;
}
static void F_137 ( struct V_25 * V_121 , struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_11 * V_46 = F_7 ( V_121 ) ;
V_29 -> V_37 = V_46 ;
}
static int F_138 ( struct V_225 * V_227 , int V_283 , T_1 V_284 )
{
struct V_11 * V_46 = F_45 () ;
struct V_222 * V_223 ;
V_223 = F_15 ( sizeof( struct V_222 ) , V_284 ) ;
if ( V_223 == NULL )
return - V_52 ;
if ( F_104 ( V_23 -> V_165 & V_285 ) ) {
V_223 -> V_230 = & V_219 ;
V_223 -> V_232 = & V_219 ;
} else {
V_223 -> V_230 = V_46 ;
V_223 -> V_232 = V_46 ;
}
V_223 -> V_286 = NULL ;
V_227 -> V_228 = V_223 ;
return 0 ;
}
static void F_139 ( struct V_225 * V_227 )
{
#ifdef F_140
struct V_287 * V_288 ;
if ( V_227 -> V_289 == V_290 ) {
F_35 () ;
F_25 (spp, &smk_ipv6_port_list, list) {
if ( V_288 -> V_291 != V_227 )
continue;
V_288 -> V_292 = 1 ;
break;
}
F_40 () ;
}
#endif
F_18 ( V_227 -> V_228 ) ;
}
static struct V_11 * F_141 ( struct V_293 * V_294 )
{
struct V_295 * V_296 ;
struct V_297 * V_298 = & V_294 -> V_299 ;
if ( V_298 -> V_300 == 0 )
return NULL ;
F_25 (snp, &smk_net4addr_list, list)
if ( V_296 -> V_301 . V_300 ==
( V_298 -> V_300 & V_296 -> V_302 . V_300 ) )
return V_296 -> V_73 ;
return NULL ;
}
static bool F_142 ( struct V_303 * V_294 )
{
T_6 * V_304 = ( T_6 * ) & V_294 -> V_305 ;
T_7 * V_306 = ( T_7 * ) & V_294 -> V_305 ;
if ( V_306 [ 0 ] == 0 && V_306 [ 1 ] == 0 && V_306 [ 2 ] == 0 && V_304 [ 6 ] == 0 &&
F_143 ( V_304 [ 7 ] ) == 1 )
return true ;
return false ;
}
static struct V_11 * F_144 ( struct V_303 * V_294 )
{
struct V_307 * V_296 ;
struct V_308 * V_309 = & V_294 -> V_305 ;
int V_3 ;
int V_310 = 0 ;
if ( F_142 ( V_294 ) )
return NULL ;
F_25 (snp, &smk_net6addr_list, list) {
if ( V_296 -> V_73 == NULL )
continue;
for ( V_310 = 1 , V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( ( V_309 -> V_311 [ V_3 ] & V_296 -> V_302 . V_311 [ V_3 ] ) !=
V_296 -> V_301 . V_311 [ V_3 ] ) {
V_310 = 0 ;
break;
}
}
if ( V_310 )
return V_296 -> V_73 ;
}
return NULL ;
}
static int F_145 ( struct V_225 * V_227 , int V_312 )
{
struct V_11 * V_46 ;
struct V_222 * V_223 = V_227 -> V_228 ;
int V_14 = 0 ;
F_146 () ;
F_147 ( V_227 ) ;
if ( V_223 -> V_232 == V_313 ||
V_312 == V_314 )
F_148 ( V_227 ) ;
else {
V_46 = V_223 -> V_232 ;
V_14 = F_149 ( V_227 , V_227 -> V_289 , & V_46 -> V_315 ) ;
}
F_150 ( V_227 ) ;
F_151 () ;
return V_14 ;
}
static int F_152 ( struct V_225 * V_227 , struct V_293 * V_309 )
{
struct V_11 * V_46 ;
int V_14 ;
int V_316 ;
struct V_11 * V_317 ;
struct V_222 * V_223 = V_227 -> V_228 ;
struct V_80 V_81 ;
F_35 () ;
V_317 = F_141 ( V_309 ) ;
if ( V_317 != NULL ) {
#ifdef F_153
struct V_318 V_319 ;
F_154 ( & V_81 , V_92 , V_320 , & V_319 ) ;
V_81 . V_321 . V_322 . V_319 -> V_283 = V_309 -> V_323 ;
V_81 . V_321 . V_322 . V_319 -> V_324 = V_309 -> V_325 ;
V_81 . V_321 . V_322 . V_319 -> V_326 . V_327 = V_309 -> V_299 . V_300 ;
#endif
V_316 = V_314 ;
V_46 = V_223 -> V_232 ;
V_14 = V_257 ( V_46 , V_317 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_13 , V_46 , V_317 , V_5 , V_14 ) ;
} else {
V_316 = V_328 ;
V_14 = 0 ;
}
F_40 () ;
if ( V_14 != 0 )
return V_14 ;
return F_145 ( V_227 , V_316 ) ;
}
static int F_155 ( struct V_11 * V_329 ,
struct V_11 * V_330 ,
struct V_303 * V_331 , int V_332 )
{
#ifdef F_153
struct V_318 V_319 ;
#endif
struct V_80 V_81 ;
int V_14 ;
#ifdef F_153
F_154 ( & V_81 , V_92 , V_320 , & V_319 ) ;
V_81 . V_321 . V_322 . V_319 -> V_283 = V_290 ;
V_81 . V_321 . V_322 . V_319 -> V_324 = F_143 ( V_331 -> V_333 ) ;
if ( V_332 == V_334 )
V_81 . V_321 . V_322 . V_319 -> V_335 . V_336 = V_331 -> V_305 ;
else
V_81 . V_321 . V_322 . V_319 -> V_335 . V_327 = V_331 -> V_305 ;
#endif
V_14 = V_257 ( V_329 , V_330 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_14 , V_329 , V_330 , V_5 , V_14 ) ;
return V_14 ;
}
static void F_156 ( struct V_224 * V_225 , struct V_337 * V_331 )
{
struct V_225 * V_227 = V_225 -> V_227 ;
struct V_303 * V_338 ;
struct V_222 * V_223 = V_225 -> V_227 -> V_228 ;
struct V_287 * V_288 ;
unsigned short V_339 = 0 ;
if ( V_331 == NULL ) {
F_35 () ;
F_25 (spp, &smk_ipv6_port_list, list) {
if ( V_227 != V_288 -> V_291 )
continue;
V_288 -> V_230 = V_223 -> V_230 ;
V_288 -> V_232 = V_223 -> V_232 ;
F_40 () ;
return;
}
F_40 () ;
return;
}
V_338 = (struct V_303 * ) V_331 ;
V_339 = F_143 ( V_338 -> V_333 ) ;
if ( V_339 == 0 )
return;
F_35 () ;
F_25 (spp, &smk_ipv6_port_list, list) {
if ( V_288 -> V_340 != V_339 || V_288 -> V_341 != V_225 -> type )
continue;
if ( V_288 -> V_292 != 1 ) {
F_40 () ;
return;
}
V_288 -> V_340 = V_339 ;
V_288 -> V_291 = V_227 ;
V_288 -> V_230 = V_223 -> V_230 ;
V_288 -> V_232 = V_223 -> V_232 ;
V_288 -> V_292 = 0 ;
F_40 () ;
return;
}
F_40 () ;
V_288 = F_15 ( sizeof( * V_288 ) , V_51 ) ;
if ( V_288 == NULL )
return;
V_288 -> V_340 = V_339 ;
V_288 -> V_291 = V_227 ;
V_288 -> V_230 = V_223 -> V_230 ;
V_288 -> V_232 = V_223 -> V_232 ;
V_288 -> V_341 = V_225 -> type ;
V_288 -> V_292 = 0 ;
F_157 ( & V_342 ) ;
F_26 ( & V_288 -> V_69 , & V_343 ) ;
F_158 ( & V_342 ) ;
return;
}
static int F_159 ( struct V_225 * V_227 , struct V_303 * V_331 ,
int V_332 )
{
struct V_287 * V_288 ;
struct V_222 * V_223 = V_227 -> V_228 ;
struct V_11 * V_46 = NULL ;
unsigned short V_339 ;
struct V_11 * V_330 ;
if ( V_332 == V_334 ) {
V_46 = F_144 ( V_331 ) ;
V_330 = V_223 -> V_230 ;
} else {
V_46 = V_223 -> V_232 ;
V_330 = F_144 ( V_331 ) ;
}
if ( V_46 != NULL && V_330 != NULL )
return F_155 ( V_46 , V_330 , V_331 , V_332 ) ;
if ( V_46 == NULL )
V_46 = V_313 ;
if ( V_330 == NULL )
V_330 = V_313 ;
if ( ! F_142 ( V_331 ) )
return F_155 ( V_46 , V_330 , V_331 , V_332 ) ;
if ( V_332 == V_334 )
return 0 ;
V_339 = F_143 ( V_331 -> V_333 ) ;
F_35 () ;
F_25 (spp, &smk_ipv6_port_list, list) {
if ( V_288 -> V_340 != V_339 || V_288 -> V_341 != V_227 -> V_344 )
continue;
V_330 = V_288 -> V_230 ;
if ( V_332 == V_345 )
V_223 -> V_286 = V_288 -> V_232 ;
break;
}
F_40 () ;
return F_155 ( V_46 , V_330 , V_331 , V_332 ) ;
}
static int F_160 ( struct V_27 * V_27 , const char * V_41 ,
const void * V_186 , T_3 V_206 , int V_165 )
{
struct V_11 * V_46 ;
struct V_28 * V_346 = V_27 -> V_30 ;
struct V_222 * V_223 ;
struct V_224 * V_225 ;
int V_14 = 0 ;
if ( V_186 == NULL || V_206 > V_50 || V_206 == 0 )
return - V_138 ;
V_46 = F_17 ( V_186 , V_206 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
if ( strcmp ( V_41 , V_190 ) == 0 ) {
V_346 -> V_37 = V_46 ;
V_346 -> V_31 |= V_347 ;
return 0 ;
}
if ( V_27 -> V_33 -> V_159 != V_226 )
return - V_49 ;
V_225 = F_98 ( V_27 ) ;
if ( V_225 == NULL || V_225 -> V_227 == NULL )
return - V_49 ;
V_223 = V_225 -> V_227 -> V_228 ;
if ( strcmp ( V_41 , V_229 ) == 0 )
V_223 -> V_230 = V_46 ;
else if ( strcmp ( V_41 , V_231 ) == 0 ) {
V_223 -> V_232 = V_46 ;
if ( V_225 -> V_227 -> V_289 == V_348 ) {
V_14 = F_145 ( V_225 -> V_227 , V_328 ) ;
if ( V_14 != 0 )
F_161 ( V_349
L_15 ,
V_92 , - V_14 ) ;
}
} else
return - V_49 ;
#ifdef F_140
if ( V_225 -> V_227 -> V_289 == V_290 )
F_156 ( V_225 , NULL ) ;
#endif
return 0 ;
}
static int F_162 ( struct V_224 * V_225 , int V_283 ,
int type , int V_350 , int V_351 )
{
struct V_222 * V_223 ;
if ( V_225 -> V_227 == NULL )
return 0 ;
if ( F_104 ( V_23 -> V_165 & V_285 ) ) {
V_223 = V_225 -> V_227 -> V_228 ;
V_223 -> V_230 = & V_219 ;
V_223 -> V_232 = & V_219 ;
}
if ( V_283 != V_348 )
return 0 ;
return F_145 ( V_225 -> V_227 , V_328 ) ;
}
static int F_163 ( struct V_224 * V_225 , struct V_337 * V_331 ,
int V_352 )
{
if ( V_225 -> V_227 != NULL && V_225 -> V_227 -> V_289 == V_290 )
F_156 ( V_225 , V_331 ) ;
return 0 ;
}
static int F_164 ( struct V_224 * V_225 , struct V_337 * V_309 ,
int V_352 )
{
int V_14 = 0 ;
#if F_165 ( V_353 )
struct V_303 * V_294 = (struct V_303 * ) V_309 ;
#endif
#ifdef F_166
struct V_11 * V_354 ;
struct V_222 * V_223 = V_225 -> V_227 -> V_228 ;
#endif
if ( V_225 -> V_227 == NULL )
return 0 ;
switch ( V_225 -> V_227 -> V_289 ) {
case V_348 :
if ( V_352 < sizeof( struct V_293 ) )
return - V_138 ;
V_14 = F_152 ( V_225 -> V_227 , (struct V_293 * ) V_309 ) ;
break;
case V_290 :
if ( V_352 < sizeof( struct V_303 ) )
return - V_138 ;
#ifdef F_166
V_354 = F_144 ( V_294 ) ;
if ( V_354 != NULL )
V_14 = F_155 ( V_223 -> V_232 , V_354 , V_294 ,
V_345 ) ;
#endif
#ifdef F_140
V_14 = F_159 ( V_225 -> V_227 , V_294 , V_345 ) ;
#endif
break;
}
return V_14 ;
}
static int F_167 ( int V_165 )
{
int V_189 = 0 ;
if ( V_165 & V_355 )
V_189 |= V_4 ;
if ( V_165 & V_356 )
V_189 |= V_5 ;
if ( V_165 & V_357 )
V_189 |= V_6 ;
return V_189 ;
}
static int F_168 ( struct V_358 * V_359 )
{
struct V_11 * V_46 = F_45 () ;
V_359 -> V_40 = V_46 ;
return 0 ;
}
static void F_169 ( struct V_358 * V_359 )
{
V_359 -> V_40 = NULL ;
}
static struct V_11 * F_170 ( struct V_360 * V_361 )
{
return (struct V_11 * ) V_361 -> V_362 . V_40 ;
}
static int F_171 ( struct V_360 * V_361 )
{
struct V_363 * V_29 = & V_361 -> V_362 ;
struct V_11 * V_46 = F_45 () ;
V_29 -> V_40 = V_46 ;
return 0 ;
}
static void F_172 ( struct V_360 * V_361 )
{
struct V_363 * V_29 = & V_361 -> V_362 ;
V_29 -> V_40 = NULL ;
}
static int F_173 ( struct V_360 * V_361 , int V_275 )
{
struct V_11 * V_223 = F_170 ( V_361 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_153
F_33 ( & V_81 , V_92 , V_364 ) ;
V_81 . V_321 . V_322 . V_365 = V_361 -> V_362 . V_366 ;
#endif
V_14 = F_67 ( V_223 , V_275 , & V_81 ) ;
V_14 = F_4 ( L_16 , V_223 , V_275 , V_14 ) ;
return V_14 ;
}
static int F_174 ( struct V_360 * V_361 , int V_367 )
{
int V_189 ;
V_189 = F_167 ( V_367 ) ;
return F_173 ( V_361 , V_189 ) ;
}
static int F_175 ( struct V_360 * V_361 , int V_237 )
{
int V_189 ;
switch ( V_237 ) {
case V_368 :
case V_369 :
V_189 = V_4 ;
break;
case V_370 :
case V_371 :
case V_372 :
case V_373 :
V_189 = V_75 ;
break;
case V_374 :
case V_375 :
return 0 ;
default:
return - V_138 ;
}
return F_173 ( V_361 , V_189 ) ;
}
static int F_176 ( struct V_360 * V_361 , char T_8 * V_376 ,
int V_367 )
{
int V_189 ;
V_189 = F_167 ( V_367 ) ;
return F_173 ( V_361 , V_189 ) ;
}
static struct V_11 * F_177 ( struct V_377 * V_378 )
{
return (struct V_11 * ) V_378 -> V_379 . V_40 ;
}
static int F_178 ( struct V_377 * V_378 )
{
struct V_363 * V_29 = & V_378 -> V_379 ;
struct V_11 * V_46 = F_45 () ;
V_29 -> V_40 = V_46 ;
return 0 ;
}
static void F_179 ( struct V_377 * V_378 )
{
struct V_363 * V_29 = & V_378 -> V_379 ;
V_29 -> V_40 = NULL ;
}
static int F_180 ( struct V_377 * V_378 , int V_275 )
{
struct V_11 * V_223 = F_177 ( V_378 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_153
F_33 ( & V_81 , V_92 , V_364 ) ;
V_81 . V_321 . V_322 . V_365 = V_378 -> V_379 . V_366 ;
#endif
V_14 = F_67 ( V_223 , V_275 , & V_81 ) ;
V_14 = F_4 ( L_17 , V_223 , V_275 , V_14 ) ;
return V_14 ;
}
static int F_181 ( struct V_377 * V_378 , int V_380 )
{
int V_189 ;
V_189 = F_167 ( V_380 ) ;
return F_180 ( V_378 , V_189 ) ;
}
static int F_182 ( struct V_377 * V_378 , int V_237 )
{
int V_189 ;
switch ( V_237 ) {
case V_381 :
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_368 :
case V_386 :
V_189 = V_4 ;
break;
case V_387 :
case V_388 :
case V_373 :
case V_370 :
V_189 = V_75 ;
break;
case V_374 :
case V_389 :
return 0 ;
default:
return - V_138 ;
}
return F_180 ( V_378 , V_189 ) ;
}
static int F_183 ( struct V_377 * V_378 , struct V_390 * V_391 ,
unsigned V_392 , int V_393 )
{
return F_180 ( V_378 , V_75 ) ;
}
static int F_184 ( struct V_394 * V_395 )
{
struct V_363 * V_396 = & V_395 -> V_397 ;
struct V_11 * V_46 = F_45 () ;
V_396 -> V_40 = V_46 ;
return 0 ;
}
static void F_185 ( struct V_394 * V_395 )
{
struct V_363 * V_396 = & V_395 -> V_397 ;
V_396 -> V_40 = NULL ;
}
static struct V_11 * F_186 ( struct V_394 * V_395 )
{
return (struct V_11 * ) V_395 -> V_397 . V_40 ;
}
static int F_187 ( struct V_394 * V_395 , int V_275 )
{
struct V_11 * V_398 = F_186 ( V_395 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_153
F_33 ( & V_81 , V_92 , V_364 ) ;
V_81 . V_321 . V_322 . V_365 = V_395 -> V_397 . V_366 ;
#endif
V_14 = F_67 ( V_398 , V_275 , & V_81 ) ;
V_14 = F_4 ( L_18 , V_398 , V_275 , V_14 ) ;
return V_14 ;
}
static int F_188 ( struct V_394 * V_395 , int V_399 )
{
int V_189 ;
V_189 = F_167 ( V_399 ) ;
return F_187 ( V_395 , V_189 ) ;
}
static int F_189 ( struct V_394 * V_395 , int V_237 )
{
int V_189 ;
switch ( V_237 ) {
case V_368 :
case V_400 :
V_189 = V_4 ;
break;
case V_370 :
case V_373 :
V_189 = V_75 ;
break;
case V_374 :
case V_401 :
return 0 ;
default:
return - V_138 ;
}
return F_187 ( V_395 , V_189 ) ;
}
static int F_190 ( struct V_394 * V_395 , struct V_358 * V_359 ,
int V_399 )
{
int V_189 ;
V_189 = F_167 ( V_399 ) ;
return F_187 ( V_395 , V_189 ) ;
}
static int F_191 ( struct V_394 * V_395 , struct V_358 * V_359 ,
struct V_25 * V_402 , long type , int V_1 )
{
return F_187 ( V_395 , V_75 ) ;
}
static int F_192 ( struct V_363 * V_403 , short V_404 )
{
struct V_11 * V_405 = V_403 -> V_40 ;
int V_189 = F_167 ( V_404 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_153
F_33 ( & V_81 , V_92 , V_364 ) ;
V_81 . V_321 . V_322 . V_365 = V_403 -> V_366 ;
#endif
V_14 = F_67 ( V_405 , V_189 , & V_81 ) ;
V_14 = F_4 ( L_19 , V_405 , V_189 , V_14 ) ;
return V_14 ;
}
static void F_193 ( struct V_363 * V_403 , T_4 * V_234 )
{
struct V_11 * V_405 = V_403 -> V_40 ;
* V_234 = V_405 -> V_235 ;
}
static void F_194 ( struct V_43 * V_406 , struct V_27 * V_27 )
{
struct V_97 * V_168 ;
struct V_99 * V_100 ;
struct V_28 * V_29 ;
struct V_11 * V_46 ;
struct V_11 * V_407 = F_45 () ;
struct V_11 * V_408 ;
char V_409 [ V_216 ] ;
int V_410 = 0 ;
int V_14 ;
struct V_43 * V_44 ;
if ( V_27 == NULL )
return;
V_29 = V_27 -> V_30 ;
F_157 ( & V_29 -> V_55 ) ;
if ( V_29 -> V_31 & V_347 )
goto V_411;
V_168 = V_27 -> V_33 ;
V_100 = V_168 -> V_107 ;
V_408 = V_100 -> V_103 ;
if ( V_406 -> V_412 == V_406 ) {
switch ( V_168 -> V_159 ) {
case V_413 :
V_100 -> V_101 = & V_218 ;
V_100 -> V_103 = & V_218 ;
V_29 -> V_37 = V_100 -> V_101 ;
break;
case V_161 :
V_29 -> V_37 = F_45 () ;
break;
case V_414 :
V_29 -> V_37 = F_45 () ;
break;
case V_226 :
V_29 -> V_37 = & V_218 ;
break;
default:
V_29 -> V_37 = V_100 -> V_101 ;
break;
}
V_29 -> V_31 |= V_347 ;
goto V_411;
}
switch ( V_168 -> V_159 ) {
case V_415 :
case V_413 :
V_408 = & V_218 ;
break;
case V_416 :
V_408 = V_407 ;
break;
case V_417 :
break;
case V_161 :
V_408 = & V_218 ;
default:
if ( F_195 ( V_27 -> V_418 ) ) {
V_408 = & V_218 ;
break;
}
if ( ! ( V_27 -> V_47 & V_48 ) )
break;
V_44 = F_196 ( V_406 ) ;
V_46 = F_13 ( V_210 , V_27 , V_44 ) ;
if ( ! F_197 ( V_46 ) )
V_408 = V_46 ;
if ( F_198 ( V_27 -> V_418 ) ) {
if ( V_29 -> V_31 & V_191 ) {
V_29 -> V_31 &= ~ V_191 ;
V_14 = F_199 ( V_44 , V_27 ,
V_215 ,
V_217 , V_216 ,
0 ) ;
} else {
V_14 = F_16 ( V_44 , V_27 ,
V_215 , V_409 ,
V_216 ) ;
if ( V_14 >= 0 && strncmp ( V_409 , V_217 ,
V_216 ) != 0 )
V_14 = - V_138 ;
}
if ( V_14 >= 0 )
V_410 = V_164 ;
}
V_46 = F_13 ( V_213 , V_27 , V_44 ) ;
if ( F_60 ( V_46 ) || V_46 == & V_218 ||
V_46 == & V_219 )
V_46 = NULL ;
V_29 -> V_22 = V_46 ;
V_46 = F_13 ( V_214 , V_27 , V_44 ) ;
if ( F_60 ( V_46 ) || V_46 == & V_218 ||
V_46 == & V_219 )
V_46 = NULL ;
V_29 -> V_220 = V_46 ;
F_200 ( V_44 ) ;
break;
}
if ( V_408 == NULL )
V_29 -> V_37 = V_407 ;
else
V_29 -> V_37 = V_408 ;
V_29 -> V_31 |= ( V_347 | V_410 ) ;
V_411:
F_158 ( & V_29 -> V_55 ) ;
return;
}
static int F_201 ( struct V_25 * V_121 , char * V_41 , char * * V_186 )
{
struct V_11 * V_46 = F_7 ( V_121 ) ;
char * V_110 ;
int V_419 ;
if ( strcmp ( V_41 , L_20 ) != 0 )
return - V_138 ;
V_110 = F_80 ( V_46 -> V_19 , V_51 ) ;
if ( V_110 == NULL )
return - V_52 ;
V_419 = strlen ( V_110 ) ;
* V_186 = V_110 ;
return V_419 ;
}
static int F_202 ( const char * V_41 , void * V_186 , T_3 V_206 )
{
struct V_20 * V_21 = F_5 () ;
struct V_39 * V_271 ;
struct V_11 * V_46 ;
struct V_70 * V_420 ;
int V_14 ;
if ( ! F_46 ( V_155 ) && F_203 ( & V_21 -> V_61 ) )
return - V_156 ;
if ( V_186 == NULL || V_206 == 0 || V_206 >= V_50 )
return - V_138 ;
if ( strcmp ( V_41 , L_20 ) != 0 )
return - V_138 ;
V_46 = F_17 ( V_186 , V_206 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
if ( V_46 == & V_219 || V_46 == & V_218 )
return - V_138 ;
if ( ! F_46 ( V_155 ) ) {
V_14 = - V_156 ;
F_28 (sklep, &tsp->smk_relabel, list)
if ( V_420 -> V_73 == V_46 ) {
V_14 = 0 ;
break;
}
if ( V_14 )
return V_14 ;
}
V_271 = F_204 () ;
if ( V_271 == NULL )
return - V_52 ;
V_21 = V_271 -> V_40 ;
V_21 -> V_22 = V_46 ;
F_29 ( & V_21 -> V_61 ) ;
F_205 ( V_271 ) ;
return V_206 ;
}
static int F_206 ( struct V_225 * V_225 ,
struct V_225 * V_421 , struct V_225 * V_422 )
{
struct V_11 * V_46 ;
struct V_11 * V_251 ;
struct V_222 * V_223 = V_225 -> V_228 ;
struct V_222 * V_423 = V_421 -> V_228 ;
struct V_222 * V_346 = V_422 -> V_228 ;
struct V_80 V_81 ;
int V_14 = 0 ;
#ifdef F_153
struct V_318 V_319 ;
#endif
if ( ! F_46 ( V_95 ) ) {
V_46 = V_223 -> V_232 ;
V_251 = V_423 -> V_230 ;
#ifdef F_153
F_154 ( & V_81 , V_92 , V_320 , & V_319 ) ;
F_207 ( & V_81 , V_421 ) ;
#endif
V_14 = V_257 ( V_46 , V_251 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_21 , V_46 , V_251 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_251 = V_423 -> V_232 ;
V_46 = V_223 -> V_230 ;
V_14 = V_257 ( V_251 , V_46 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_21 , V_251 , V_46 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_346 -> V_286 = V_223 -> V_232 ;
V_223 -> V_286 = V_423 -> V_232 ;
}
return V_14 ;
}
static int F_208 ( struct V_224 * V_225 , struct V_224 * V_421 )
{
struct V_222 * V_223 = V_225 -> V_227 -> V_228 ;
struct V_222 * V_423 = V_421 -> V_227 -> V_228 ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_153
struct V_318 V_319 ;
F_154 ( & V_81 , V_92 , V_320 , & V_319 ) ;
F_207 ( & V_81 , V_421 -> V_227 ) ;
#endif
if ( F_46 ( V_95 ) )
return 0 ;
V_14 = V_257 ( V_223 -> V_232 , V_423 -> V_230 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_22 , V_223 -> V_232 , V_423 -> V_230 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_209 ( struct V_224 * V_225 , struct V_424 * V_359 ,
int V_206 )
{
struct V_293 * V_294 = (struct V_293 * ) V_359 -> V_425 ;
#if F_165 ( V_353 )
struct V_303 * V_309 = (struct V_303 * ) V_359 -> V_425 ;
#endif
#ifdef F_166
struct V_222 * V_223 = V_225 -> V_227 -> V_228 ;
struct V_11 * V_354 ;
#endif
int V_14 = 0 ;
if ( V_294 == NULL )
return 0 ;
switch ( V_225 -> V_227 -> V_289 ) {
case V_426 :
V_14 = F_152 ( V_225 -> V_227 , V_294 ) ;
break;
case V_427 :
#ifdef F_166
V_354 = F_144 ( V_309 ) ;
if ( V_354 != NULL )
V_14 = F_155 ( V_223 -> V_232 , V_354 , V_309 ,
V_345 ) ;
#endif
#ifdef F_140
V_14 = F_159 ( V_225 -> V_227 , V_309 , V_428 ) ;
#endif
break;
}
return V_14 ;
}
static struct V_11 * F_210 ( struct V_429 * V_309 ,
struct V_222 * V_223 )
{
struct V_11 * V_46 ;
int V_310 = 0 ;
int V_430 ;
int V_431 ;
if ( ( V_309 -> V_165 & V_432 ) != 0 ) {
F_35 () ;
F_25 (skp, &smack_known_list, list) {
if ( V_309 -> V_433 . V_434 . V_435 != V_46 -> V_315 . V_433 . V_434 . V_435 )
continue;
if ( ( V_309 -> V_165 & V_436 ) == 0 ) {
if ( ( V_46 -> V_315 . V_165 &
V_436 ) == 0 )
V_310 = 1 ;
break;
}
for ( V_430 = - 1 , V_431 = - 1 ; V_430 == V_431 ; ) {
V_430 = F_211 ( V_309 -> V_433 . V_434 . V_437 ,
V_430 + 1 ) ;
V_431 = F_211 (
V_46 -> V_315 . V_433 . V_434 . V_437 ,
V_431 + 1 ) ;
if ( V_430 < 0 || V_431 < 0 )
break;
}
if ( V_430 == V_431 ) {
V_310 = 1 ;
break;
}
}
F_40 () ;
if ( V_310 )
return V_46 ;
if ( V_223 != NULL && V_223 -> V_230 == & V_218 )
return & V_219 ;
return & V_218 ;
}
if ( ( V_309 -> V_165 & V_438 ) != 0 )
return F_123 ( V_309 -> V_433 . V_234 ) ;
return V_313 ;
}
static int F_212 ( struct V_439 * V_440 , struct V_303 * V_294 )
{
T_9 V_441 ;
int V_442 ;
int V_443 = - V_138 ;
struct V_444 V_445 ;
struct V_444 * V_446 ;
T_6 V_447 ;
struct V_448 V_449 , * V_450 ;
struct V_451 V_452 , * V_453 ;
struct V_454 V_455 , * V_456 ;
V_294 -> V_333 = 0 ;
V_442 = F_213 ( V_440 ) ;
V_446 = F_214 ( V_440 , V_442 , sizeof( V_445 ) , & V_445 ) ;
if ( V_446 == NULL )
return - V_138 ;
V_294 -> V_305 = V_446 -> V_336 ;
V_441 = V_446 -> V_441 ;
V_442 += sizeof( V_445 ) ;
V_442 = F_215 ( V_440 , V_442 , & V_441 , & V_447 ) ;
if ( V_442 < 0 )
return - V_138 ;
V_443 = V_441 ;
switch ( V_443 ) {
case V_457 :
V_450 = F_214 ( V_440 , V_442 , sizeof( V_449 ) , & V_449 ) ;
if ( V_450 != NULL )
V_294 -> V_333 = V_450 -> V_458 ;
break;
case V_459 :
V_453 = F_214 ( V_440 , V_442 , sizeof( V_452 ) , & V_452 ) ;
if ( V_453 != NULL )
V_294 -> V_333 = V_453 -> V_458 ;
break;
case V_460 :
V_456 = F_214 ( V_440 , V_442 , sizeof( V_455 ) , & V_455 ) ;
if ( V_456 != NULL )
V_294 -> V_333 = V_456 -> V_461 ;
break;
}
return V_443 ;
}
static int F_216 ( struct V_225 * V_227 , struct V_439 * V_440 )
{
struct V_429 V_462 ;
struct V_222 * V_223 = V_227 -> V_228 ;
struct V_11 * V_46 = NULL ;
int V_14 = 0 ;
struct V_80 V_81 ;
#ifdef F_153
struct V_318 V_319 ;
#endif
#if F_165 ( V_353 )
struct V_303 V_463 ;
int V_443 ;
#endif
switch ( V_227 -> V_289 ) {
case V_348 :
#ifdef F_217
if ( V_440 && V_440 -> V_464 != 0 ) {
V_46 = F_123 ( V_440 -> V_464 ) ;
goto V_465;
}
#endif
F_218 ( & V_462 ) ;
V_14 = F_219 ( V_440 , V_227 -> V_289 , & V_462 ) ;
if ( V_14 == 0 )
V_46 = F_210 ( & V_462 , V_223 ) ;
else
V_46 = V_313 ;
F_220 ( & V_462 ) ;
#ifdef F_217
V_465:
#endif
#ifdef F_153
F_154 ( & V_81 , V_92 , V_320 , & V_319 ) ;
V_81 . V_321 . V_322 . V_319 -> V_283 = V_227 -> V_289 ;
V_81 . V_321 . V_322 . V_319 -> V_466 = V_440 -> V_467 ;
F_221 ( V_440 , & V_81 . V_321 , NULL ) ;
#endif
V_14 = V_257 ( V_46 , V_223 -> V_230 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_23 , V_46 , V_223 -> V_230 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_222 ( V_440 , V_227 -> V_289 , V_14 , 0 ) ;
break;
#if F_165 ( V_353 )
case V_290 :
V_443 = F_212 ( V_440 , & V_463 ) ;
if ( V_443 != V_459 && V_443 != V_457 )
break;
#ifdef F_166
if ( V_440 && V_440 -> V_464 != 0 )
V_46 = F_123 ( V_440 -> V_464 ) ;
else
V_46 = F_144 ( & V_463 ) ;
if ( V_46 == NULL )
V_46 = V_313 ;
#ifdef F_153
F_154 ( & V_81 , V_92 , V_320 , & V_319 ) ;
V_81 . V_321 . V_322 . V_319 -> V_283 = V_227 -> V_289 ;
V_81 . V_321 . V_322 . V_319 -> V_466 = V_440 -> V_467 ;
F_223 ( V_440 , & V_81 . V_321 , NULL ) ;
#endif
V_14 = V_257 ( V_46 , V_223 -> V_230 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_24 , V_46 , V_223 -> V_230 ,
V_5 , V_14 ) ;
#endif
#ifdef F_140
V_14 = F_159 ( V_227 , & V_463 , V_334 ) ;
#endif
break;
#endif
}
return V_14 ;
}
static int F_224 ( struct V_224 * V_225 ,
char T_8 * V_468 ,
int T_8 * V_469 , unsigned V_187 )
{
struct V_222 * V_223 ;
char * V_470 = L_25 ;
int V_419 = 1 ;
int V_14 = 0 ;
V_223 = V_225 -> V_227 -> V_228 ;
if ( V_223 -> V_286 != NULL ) {
V_470 = V_223 -> V_286 -> V_19 ;
V_419 = strlen ( V_470 ) + 1 ;
}
if ( V_419 > V_187 )
V_14 = - V_471 ;
else if ( F_225 ( V_468 , V_470 , V_419 ) != 0 )
V_14 = - V_472 ;
if ( F_226 ( V_419 , V_469 ) != 0 )
V_14 = - V_472 ;
return V_14 ;
}
static int F_227 ( struct V_224 * V_225 ,
struct V_439 * V_440 , T_4 * V_234 )
{
struct V_429 V_462 ;
struct V_222 * V_223 = NULL ;
struct V_11 * V_46 ;
int V_283 = V_473 ;
T_4 V_2 = 0 ;
int V_14 ;
if ( V_440 != NULL ) {
if ( V_440 -> V_350 == F_228 ( V_474 ) )
V_283 = V_348 ;
#if F_165 ( V_353 )
else if ( V_440 -> V_350 == F_228 ( V_475 ) )
V_283 = V_290 ;
#endif
}
if ( V_283 == V_473 && V_225 != NULL )
V_283 = V_225 -> V_227 -> V_289 ;
switch ( V_283 ) {
case V_476 :
V_223 = V_225 -> V_227 -> V_228 ;
V_2 = V_223 -> V_232 -> V_235 ;
break;
case V_348 :
#ifdef F_217
V_2 = V_440 -> V_464 ;
if ( V_2 != 0 )
break;
#endif
if ( V_225 != NULL && V_225 -> V_227 != NULL )
V_223 = V_225 -> V_227 -> V_228 ;
F_218 ( & V_462 ) ;
V_14 = F_219 ( V_440 , V_283 , & V_462 ) ;
if ( V_14 == 0 ) {
V_46 = F_210 ( & V_462 , V_223 ) ;
V_2 = V_46 -> V_235 ;
}
F_220 ( & V_462 ) ;
break;
case V_290 :
#ifdef F_166
V_2 = V_440 -> V_464 ;
#endif
break;
}
* V_234 = V_2 ;
if ( V_2 == 0 )
return - V_138 ;
return 0 ;
}
static void F_229 ( struct V_225 * V_227 , struct V_224 * V_477 )
{
struct V_222 * V_223 ;
struct V_11 * V_46 = F_45 () ;
if ( V_227 == NULL ||
( V_227 -> V_289 != V_348 && V_227 -> V_289 != V_290 ) )
return;
V_223 = V_227 -> V_228 ;
V_223 -> V_230 = V_46 ;
V_223 -> V_232 = V_46 ;
}
static int F_230 ( struct V_225 * V_227 , struct V_439 * V_440 ,
struct V_478 * V_479 )
{
T_10 V_283 = V_227 -> V_289 ;
struct V_11 * V_46 ;
struct V_222 * V_223 = V_227 -> V_228 ;
struct V_429 V_462 ;
struct V_293 V_480 ;
struct V_481 * V_482 ;
struct V_11 * V_483 ;
int V_14 ;
struct V_80 V_81 ;
#ifdef F_153
struct V_318 V_319 ;
#endif
#if F_165 ( V_353 )
if ( V_283 == V_290 ) {
if ( V_440 -> V_350 == F_228 ( V_474 ) )
V_283 = V_348 ;
else
return 0 ;
}
#endif
#ifdef F_217
if ( V_440 && V_440 -> V_464 != 0 ) {
V_46 = F_123 ( V_440 -> V_464 ) ;
goto V_465;
}
#endif
F_218 ( & V_462 ) ;
V_14 = F_219 ( V_440 , V_283 , & V_462 ) ;
if ( V_14 == 0 )
V_46 = F_210 ( & V_462 , V_223 ) ;
else
V_46 = & V_484 ;
F_220 ( & V_462 ) ;
#ifdef F_217
V_465:
#endif
#ifdef F_153
F_154 ( & V_81 , V_92 , V_320 , & V_319 ) ;
V_81 . V_321 . V_322 . V_319 -> V_283 = V_283 ;
V_81 . V_321 . V_322 . V_319 -> V_466 = V_440 -> V_467 ;
F_221 ( V_440 , & V_81 . V_321 , NULL ) ;
#endif
V_14 = V_257 ( V_46 , V_223 -> V_230 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_26 , V_46 , V_223 -> V_230 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_479 -> V_485 = V_46 -> V_235 ;
V_482 = F_231 ( V_440 ) ;
V_480 . V_299 . V_300 = V_482 -> V_336 ;
F_35 () ;
V_483 = F_141 ( & V_480 ) ;
F_40 () ;
if ( V_483 == NULL )
V_14 = F_232 ( V_479 , & V_46 -> V_315 ) ;
else
F_233 ( V_479 ) ;
return V_14 ;
}
static void F_234 ( struct V_225 * V_227 ,
const struct V_478 * V_479 )
{
struct V_222 * V_223 = V_227 -> V_228 ;
struct V_11 * V_46 ;
if ( V_479 -> V_485 != 0 ) {
V_46 = F_123 ( V_479 -> V_485 ) ;
V_223 -> V_286 = V_46 ;
} else
V_223 -> V_286 = NULL ;
}
static int F_235 ( struct V_486 * V_486 , const struct V_39 * V_39 ,
unsigned long V_165 )
{
struct V_11 * V_46 = F_37 ( V_39 -> V_40 ) ;
V_486 -> V_40 = V_46 ;
return 0 ;
}
static void F_236 ( struct V_486 * V_486 )
{
V_486 -> V_40 = NULL ;
}
static int F_237 ( T_11 V_487 ,
const struct V_39 * V_39 , unsigned V_488 )
{
struct V_486 * V_489 ;
struct V_80 V_81 ;
struct V_11 * V_262 = F_37 ( V_39 -> V_40 ) ;
int V_490 = 0 ;
int V_14 ;
V_489 = F_238 ( V_487 ) ;
if ( V_489 == NULL )
return - V_138 ;
if ( V_489 -> V_40 == NULL )
return 0 ;
if ( V_262 == NULL )
return - V_89 ;
#ifdef F_153
F_33 ( & V_81 , V_92 , V_491 ) ;
V_81 . V_321 . V_322 . V_492 . V_486 = V_489 -> V_493 ;
V_81 . V_321 . V_322 . V_492 . V_494 = V_489 -> V_495 ;
#endif
if ( V_488 & V_496 )
V_490 = V_4 ;
if ( V_488 & ( V_497 | V_498 | V_499 ) )
V_490 = V_5 ;
V_14 = V_257 ( V_262 , V_489 -> V_40 , V_490 , & V_81 ) ;
V_14 = F_2 ( L_27 , V_262 , V_489 -> V_40 , V_490 , V_14 ) ;
return V_14 ;
}
static int F_239 ( struct V_486 * V_486 , char * * V_500 )
{
struct V_11 * V_46 = V_486 -> V_40 ;
T_3 V_501 ;
char * V_502 ;
if ( V_486 -> V_40 == NULL ) {
* V_500 = NULL ;
return 0 ;
}
V_502 = F_80 ( V_46 -> V_19 , V_51 ) ;
if ( V_502 == NULL )
return - V_52 ;
V_501 = strlen ( V_502 ) + 1 ;
* V_500 = V_502 ;
return V_501 ;
}
static int F_240 ( T_4 V_503 , T_4 V_504 , char * V_505 , void * * V_506 )
{
struct V_11 * V_46 ;
char * * V_507 = ( char * * ) V_506 ;
* V_507 = NULL ;
if ( V_503 != V_508 && V_503 != V_509 )
return - V_138 ;
if ( V_504 != V_510 && V_504 != V_511 )
return - V_138 ;
V_46 = F_17 ( V_505 , 0 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
* V_507 = V_46 -> V_19 ;
return 0 ;
}
static int F_241 ( struct V_512 * V_513 )
{
struct V_514 * V_515 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_513 -> V_516 ; V_3 ++ ) {
V_515 = & V_513 -> V_517 [ V_3 ] ;
if ( V_515 -> type == V_508 || V_515 -> type == V_509 )
return 1 ;
}
return 0 ;
}
static int F_242 ( T_4 V_234 , T_4 V_503 , T_4 V_504 , void * V_506 ,
struct V_518 * V_519 )
{
struct V_11 * V_46 ;
char * V_507 = V_506 ;
if ( F_104 ( ! V_507 ) ) {
F_243 ( 1 , L_28 ) ;
return - V_256 ;
}
if ( V_503 != V_508 && V_503 != V_509 )
return 0 ;
V_46 = F_123 ( V_234 ) ;
if ( V_504 == V_510 )
return ( V_507 == V_46 -> V_19 ) ;
if ( V_504 == V_511 )
return ( V_507 != V_46 -> V_19 ) ;
return 0 ;
}
static int F_244 ( const char * V_41 )
{
return ( strcmp ( V_41 , V_190 ) == 0 ) ;
}
static int F_245 ( T_4 V_234 , char * * V_520 , T_4 * V_521 )
{
struct V_11 * V_46 = F_123 ( V_234 ) ;
if ( V_520 )
* V_520 = V_46 -> V_19 ;
* V_521 = strlen ( V_46 -> V_19 ) ;
return 0 ;
}
static int F_246 ( const char * V_520 , T_4 V_521 , T_4 * V_234 )
{
struct V_11 * V_46 = F_247 ( V_520 ) ;
if ( V_46 )
* V_234 = V_46 -> V_235 ;
else
* V_234 = 0 ;
return 0 ;
}
static int F_248 ( struct V_27 * V_27 , void * V_522 , T_4 V_523 )
{
return F_160 ( V_27 , V_190 , V_522 , V_523 , 0 ) ;
}
static int F_249 ( struct V_43 * V_43 , void * V_522 , T_4 V_523 )
{
return F_250 ( V_43 , V_210 , V_522 , V_523 , 0 ) ;
}
static int F_251 ( struct V_27 * V_27 , void * * V_522 , T_4 * V_523 )
{
int V_187 = 0 ;
V_187 = F_97 ( V_27 , V_190 , V_522 , true ) ;
if ( V_187 < 0 )
return V_187 ;
* V_523 = V_187 ;
return 0 ;
}
static T_12 void F_252 ( void )
{
F_21 ( & V_484 . V_62 ) ;
F_21 ( & V_106 . V_62 ) ;
F_21 ( & V_102 . V_62 ) ;
F_21 ( & V_218 . V_62 ) ;
F_21 ( & V_219 . V_62 ) ;
F_23 ( & V_484 . V_60 ) ;
F_23 ( & V_106 . V_60 ) ;
F_23 ( & V_218 . V_60 ) ;
F_23 ( & V_102 . V_60 ) ;
F_23 ( & V_219 . V_60 ) ;
F_253 ( & V_484 ) ;
F_253 ( & V_106 ) ;
F_253 ( & V_218 ) ;
F_253 ( & V_102 ) ;
F_253 ( & V_219 ) ;
}
static T_12 int F_254 ( void )
{
struct V_39 * V_39 ;
struct V_20 * V_21 ;
if ( ! F_255 ( L_29 ) )
return 0 ;
V_53 = F_256 ( V_28 , 0 ) ;
if ( ! V_53 )
return - V_52 ;
V_21 = F_22 ( & V_102 , & V_102 ,
V_51 ) ;
if ( V_21 == NULL ) {
F_257 ( V_53 ) ;
return - V_52 ;
}
V_524 = 1 ;
F_3 ( L_30 ) ;
#ifdef F_217
F_3 ( L_31 ) ;
#endif
#ifdef F_140
F_3 ( L_32 ) ;
#endif
#ifdef F_166
F_3 ( L_33 ) ;
#endif
V_39 = (struct V_39 * ) V_23 -> V_39 ;
V_39 -> V_40 = V_21 ;
F_252 () ;
F_258 ( V_525 , F_259 ( V_525 ) , L_29 ) ;
return 0 ;
}

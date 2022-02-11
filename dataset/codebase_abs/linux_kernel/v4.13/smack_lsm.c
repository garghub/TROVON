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
return 0 ;
}
static void F_71 ( struct V_171 * V_172 )
{
struct V_20 * V_173 = V_172 -> V_39 -> V_40 ;
if ( V_173 -> V_22 != V_173 -> V_59 )
V_23 -> V_179 = 0 ;
}
static int F_72 ( struct V_171 * V_172 )
{
struct V_20 * V_21 = F_5 () ;
if ( V_21 -> V_22 != V_21 -> V_59 )
return 1 ;
return 0 ;
}
static int F_73 ( struct V_27 * V_27 )
{
struct V_11 * V_46 = F_45 () ;
V_27 -> V_30 = F_19 ( V_46 ) ;
if ( V_27 -> V_30 == NULL )
return - V_52 ;
return 0 ;
}
static void F_74 ( struct V_180 * V_181 )
{
struct V_28 * V_182 ;
V_182 = F_75 ( V_181 , struct V_28 , V_183 ) ;
F_76 ( V_53 , V_182 ) ;
}
static void F_77 ( struct V_27 * V_27 )
{
struct V_28 * V_182 = V_27 -> V_30 ;
F_78 ( & V_182 -> V_183 , F_74 ) ;
}
static int F_79 ( struct V_27 * V_27 , struct V_27 * V_184 ,
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
V_189 = F_80 ( V_46 -> V_19 , V_188 -> V_19 ,
& V_46 -> V_60 ) ;
F_40 () ;
if ( V_189 > 0 && ( ( V_189 & V_8 ) != 0 ) &&
F_81 ( V_184 ) ) {
V_29 = V_188 ;
V_182 -> V_31 |= V_191 ;
}
* V_186 = F_82 ( V_29 -> V_19 , V_54 ) ;
if ( * V_186 == NULL )
return - V_52 ;
* V_187 = strlen ( V_29 -> V_19 ) ;
}
return 0 ;
}
static int F_83 ( struct V_43 * V_192 , struct V_27 * V_184 ,
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
if ( V_14 == 0 && F_84 ( V_193 ) ) {
V_29 = F_11 ( F_59 ( V_193 ) ) ;
F_66 ( & V_81 , V_193 ) ;
V_14 = F_67 ( V_29 , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_193 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_85 ( struct V_27 * V_184 , struct V_43 * V_43 )
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
F_86 ( & V_81 , V_184 ) ;
V_14 = F_67 ( F_11 ( V_184 ) , V_5 , & V_81 ) ;
V_14 = F_8 ( V_184 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_87 ( struct V_27 * V_184 , struct V_43 * V_43 )
{
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_33 ( & V_81 , V_92 , V_194 ) ;
F_86 ( & V_81 , V_184 ) ;
V_14 = F_67 ( F_11 ( V_184 ) , V_5 , & V_81 ) ;
V_14 = F_8 ( V_184 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_88 ( struct V_27 * V_195 ,
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
if ( V_14 == 0 && F_84 ( V_193 ) ) {
V_29 = F_11 ( F_59 ( V_193 ) ) ;
F_66 ( & V_81 , V_193 ) ;
V_14 = F_67 ( V_29 , V_75 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_193 ) , V_75 , V_14 ) ;
}
return V_14 ;
}
static int F_89 ( struct V_27 * V_27 , int V_197 )
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
F_86 ( & V_81 , V_27 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_197 , & V_81 ) ;
V_14 = F_8 ( V_27 , V_197 , V_14 ) ;
return V_14 ;
}
static int F_90 ( struct V_43 * V_43 , struct V_201 * V_201 )
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
static int F_91 ( const struct V_204 * V_204 )
{
struct V_80 V_81 ;
struct V_27 * V_27 = F_59 ( V_204 -> V_43 ) ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_205 ) ;
F_92 ( & V_81 , * V_204 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_4 , & V_81 ) ;
V_14 = F_8 ( V_27 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_93 ( struct V_43 * V_43 , const char * V_41 ,
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
V_14 = F_94 ( V_43 , V_41 , V_186 , V_206 , V_165 ) ;
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
static void F_95 ( struct V_43 * V_43 , const char * V_41 ,
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
static int F_96 ( struct V_43 * V_43 , const char * V_41 )
{
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_4 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_4 , V_14 ) ;
return V_14 ;
}
static int F_97 ( struct V_43 * V_43 , const char * V_41 )
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
V_14 = F_98 ( V_43 , V_41 ) ;
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
static int F_99 ( struct V_27 * V_27 ,
const char * V_41 , void * * V_45 ,
bool V_221 )
{
struct V_222 * V_223 ;
struct V_224 * V_225 ;
struct V_97 * V_168 ;
struct V_27 * V_42 = (struct V_27 * ) V_27 ;
struct V_11 * V_29 ;
int V_226 ;
int V_14 = 0 ;
if ( strcmp ( V_41 , V_190 ) == 0 ) {
V_29 = F_11 ( V_27 ) ;
V_226 = strlen ( V_29 -> V_19 ) ;
* V_45 = V_29 -> V_19 ;
return V_226 ;
}
V_168 = V_42 -> V_33 ;
if ( V_168 -> V_159 != V_227 )
return - V_49 ;
V_225 = F_100 ( V_42 ) ;
if ( V_225 == NULL || V_225 -> V_228 == NULL )
return - V_49 ;
V_223 = V_225 -> V_228 -> V_229 ;
if ( strcmp ( V_41 , V_230 ) == 0 )
V_29 = V_223 -> V_231 ;
else if ( strcmp ( V_41 , V_232 ) == 0 )
V_29 = V_223 -> V_233 ;
else
return - V_49 ;
V_226 = strlen ( V_29 -> V_19 ) ;
if ( V_14 == 0 ) {
* V_45 = V_29 -> V_19 ;
V_14 = V_226 ;
}
return V_14 ;
}
static int F_101 ( struct V_27 * V_27 , char * V_45 ,
T_3 V_234 )
{
int V_187 = sizeof( V_210 ) ;
if ( V_45 != NULL && V_187 <= V_234 )
memcpy ( V_45 , V_210 , V_187 ) ;
return V_187 ;
}
static void F_102 ( struct V_27 * V_27 , T_4 * V_235 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
* V_235 = V_29 -> V_37 -> V_236 ;
}
static int F_103 ( struct V_38 * V_38 )
{
struct V_11 * V_46 = F_45 () ;
V_38 -> V_237 = V_46 ;
return 0 ;
}
static void F_104 ( struct V_38 * V_38 )
{
V_38 -> V_237 = NULL ;
}
static int F_105 ( struct V_38 * V_38 , unsigned int V_238 ,
unsigned long V_239 )
{
int V_14 = 0 ;
struct V_80 V_81 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
if ( F_106 ( F_107 ( V_27 ) ) )
return 0 ;
F_33 ( & V_81 , V_92 , V_205 ) ;
F_92 ( & V_81 , V_38 -> V_240 ) ;
if ( F_108 ( V_238 ) & V_241 ) {
V_14 = F_67 ( F_11 ( V_27 ) , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_108 ( V_238 ) & V_242 ) ) {
V_14 = F_67 ( F_11 ( V_27 ) , V_4 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_109 ( struct V_38 * V_38 , unsigned int V_238 )
{
struct V_80 V_81 ;
int V_14 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
if ( F_106 ( F_107 ( V_27 ) ) )
return 0 ;
F_33 ( & V_81 , V_92 , V_205 ) ;
F_92 ( & V_81 , V_38 -> V_240 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_9 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_110 ( struct V_38 * V_38 , unsigned int V_238 ,
unsigned long V_239 )
{
struct V_80 V_81 ;
int V_14 = 0 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
if ( F_106 ( F_107 ( V_27 ) ) )
return 0 ;
switch ( V_238 ) {
case V_243 :
break;
case V_244 :
case V_245 :
F_33 ( & V_81 , V_92 , V_205 ) ;
F_92 ( & V_81 , V_38 -> V_240 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_9 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
break;
case V_246 :
case V_247 :
F_33 ( & V_81 , V_92 , V_205 ) ;
F_92 ( & V_81 , V_38 -> V_240 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_111 ( struct V_38 * V_38 ,
unsigned long V_248 , unsigned long V_249 ,
unsigned long V_165 )
{
struct V_11 * V_46 ;
struct V_11 * V_250 ;
struct V_66 * V_251 ;
struct V_20 * V_21 ;
struct V_11 * V_252 ;
struct V_28 * V_29 ;
struct V_99 * V_100 ;
int V_189 ;
int V_253 ;
int V_254 ;
int V_14 ;
if ( V_38 == NULL )
return 0 ;
if ( F_106 ( F_107 ( F_10 ( V_38 ) ) ) )
return 0 ;
V_29 = F_10 ( V_38 ) -> V_30 ;
if ( V_29 -> V_220 == NULL )
return 0 ;
V_100 = F_10 ( V_38 ) -> V_33 -> V_107 ;
if ( V_100 -> V_31 & V_163 &&
V_29 -> V_220 != V_100 -> V_101 )
return - V_89 ;
V_250 = V_29 -> V_220 ;
V_21 = F_5 () ;
V_46 = F_45 () ;
V_14 = 0 ;
F_35 () ;
F_25 (srp, &skp->smk_rules, list) {
V_252 = V_251 -> V_255 ;
if ( V_250 -> V_19 == V_252 -> V_19 )
continue;
V_189 = F_80 ( V_251 -> V_256 -> V_19 ,
V_252 -> V_19 ,
& V_21 -> V_60 ) ;
if ( V_189 == - V_257 )
V_189 = V_251 -> V_258 ;
else
V_189 &= V_251 -> V_258 ;
if ( V_189 == 0 )
continue;
V_253 = F_80 ( V_250 -> V_19 , V_252 -> V_19 ,
& V_250 -> V_60 ) ;
if ( V_253 == - V_257 ) {
V_14 = - V_89 ;
break;
}
V_254 = F_80 ( V_250 -> V_19 , V_252 -> V_19 ,
& V_21 -> V_60 ) ;
if ( V_254 != - V_257 )
V_253 &= V_254 ;
if ( ( V_189 | V_253 ) != V_253 ) {
V_14 = - V_89 ;
break;
}
}
F_40 () ;
return V_14 ;
}
static void F_112 ( struct V_38 * V_38 )
{
V_38 -> V_237 = F_45 () ;
}
static int F_113 ( struct V_25 * V_259 ,
struct V_260 * V_261 , int V_262 )
{
struct V_11 * V_46 ;
struct V_11 * V_263 = F_37 ( V_259 -> V_39 -> V_40 ) ;
struct V_38 * V_38 ;
int V_14 ;
struct V_80 V_81 ;
V_38 = F_75 ( V_261 , struct V_38 , V_264 ) ;
V_46 = V_38 -> V_237 ;
V_14 = V_258 ( V_46 , V_263 , V_265 , NULL ) ;
V_14 = F_2 ( L_11 , V_46 , V_263 , V_265 , V_14 ) ;
if ( V_14 != 0 && F_114 ( V_259 , V_95 ) )
V_14 = 0 ;
F_33 ( & V_81 , V_92 , V_85 ) ;
F_34 ( & V_81 , V_259 ) ;
F_39 ( V_46 -> V_19 , V_263 -> V_19 , V_265 , V_14 , & V_81 ) ;
return V_14 ;
}
static int F_115 ( struct V_38 * V_38 )
{
int V_14 ;
int V_189 = 0 ;
struct V_80 V_81 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_224 * V_225 ;
struct V_20 * V_21 ;
struct V_222 * V_223 ;
if ( F_106 ( F_107 ( V_27 ) ) )
return 0 ;
F_33 ( & V_81 , V_92 , V_205 ) ;
F_92 ( & V_81 , V_38 -> V_240 ) ;
if ( V_27 -> V_33 -> V_159 == V_227 ) {
V_225 = F_100 ( V_27 ) ;
V_223 = V_225 -> V_228 -> V_229 ;
V_21 = F_5 () ;
V_14 = V_258 ( V_21 -> V_22 , V_223 -> V_233 , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_189 , V_14 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = V_258 ( V_223 -> V_231 , V_21 -> V_22 , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_189 , V_14 ) ;
return V_14 ;
}
if ( V_38 -> V_266 & V_267 )
V_189 = V_4 ;
if ( V_38 -> V_266 & V_268 )
V_189 |= V_5 ;
V_14 = F_67 ( F_11 ( V_27 ) , V_189 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_189 , V_14 ) ;
return V_14 ;
}
static int F_116 ( struct V_38 * V_38 , const struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_205 ) ;
F_92 ( & V_81 , V_38 -> V_240 ) ;
V_14 = F_41 ( V_21 , F_11 ( V_27 ) , V_4 , & V_81 ) ;
V_14 = F_12 ( V_39 , V_38 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_117 ( struct V_39 * V_39 , T_1 V_58 )
{
struct V_20 * V_21 ;
V_21 = F_22 ( NULL , NULL , V_58 ) ;
if ( V_21 == NULL )
return - V_52 ;
V_39 -> V_40 = V_21 ;
return 0 ;
}
static void F_118 ( struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_66 * V_269 ;
struct V_63 * V_270 ;
struct V_63 * V_271 ;
if ( V_21 == NULL )
return;
V_39 -> V_40 = NULL ;
F_29 ( & V_21 -> V_61 ) ;
F_119 (l, n, &tsp->smk_rules) {
V_269 = F_120 ( V_270 , struct V_66 , V_69 ) ;
F_121 ( & V_269 -> V_69 ) ;
F_18 ( V_269 ) ;
}
F_18 ( V_21 ) ;
}
static int F_122 ( struct V_39 * V_272 , const struct V_39 * V_273 ,
T_1 V_58 )
{
struct V_20 * V_274 = V_273 -> V_40 ;
struct V_20 * V_275 ;
int V_14 ;
V_275 = F_22 ( V_274 -> V_22 , V_274 -> V_22 , V_58 ) ;
if ( V_275 == NULL )
return - V_52 ;
V_272 -> V_40 = V_275 ;
V_14 = F_24 ( & V_275 -> V_60 , & V_274 -> V_60 , V_58 ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_27 ( & V_275 -> V_61 , & V_274 -> V_61 ,
V_58 ) ;
if ( V_14 != 0 )
return V_14 ;
return 0 ;
}
static void F_123 ( struct V_39 * V_272 , const struct V_39 * V_273 )
{
struct V_20 * V_274 = V_273 -> V_40 ;
struct V_20 * V_275 = V_272 -> V_40 ;
V_275 -> V_22 = V_274 -> V_22 ;
V_275 -> V_59 = V_274 -> V_22 ;
F_21 ( & V_275 -> V_62 ) ;
F_23 ( & V_275 -> V_60 ) ;
}
static int F_124 ( struct V_39 * V_272 , T_4 V_235 )
{
struct V_20 * V_275 = V_272 -> V_40 ;
V_275 -> V_22 = F_125 ( V_235 ) ;
return 0 ;
}
static int F_126 ( struct V_39 * V_272 ,
struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_20 * V_21 = V_272 -> V_40 ;
V_21 -> V_59 = V_29 -> V_37 ;
V_21 -> V_22 = V_21 -> V_59 ;
return 0 ;
}
static int F_127 ( struct V_25 * V_121 , int V_276 ,
const char * V_277 )
{
struct V_80 V_81 ;
struct V_11 * V_46 = F_7 ( V_121 ) ;
int V_14 ;
F_33 ( & V_81 , V_277 , V_85 ) ;
F_34 ( & V_81 , V_121 ) ;
V_14 = F_67 ( V_46 , V_276 , & V_81 ) ;
V_14 = F_6 ( V_121 , V_276 , V_14 ) ;
return V_14 ;
}
static int F_128 ( struct V_25 * V_121 , T_5 V_278 )
{
return F_127 ( V_121 , V_5 , V_92 ) ;
}
static int F_129 ( struct V_25 * V_121 )
{
return F_127 ( V_121 , V_4 , V_92 ) ;
}
static int F_130 ( struct V_25 * V_121 )
{
return F_127 ( V_121 , V_4 , V_92 ) ;
}
static void F_131 ( struct V_25 * V_121 , T_4 * V_235 )
{
struct V_11 * V_46 = F_7 ( V_121 ) ;
* V_235 = V_46 -> V_236 ;
}
static int F_132 ( struct V_25 * V_121 , int V_279 )
{
return F_127 ( V_121 , V_5 , V_92 ) ;
}
static int F_133 ( struct V_25 * V_121 , int V_280 )
{
return F_127 ( V_121 , V_5 , V_92 ) ;
}
static int F_134 ( struct V_25 * V_121 )
{
return F_127 ( V_121 , V_4 , V_92 ) ;
}
static int F_135 ( struct V_25 * V_121 )
{
return F_127 ( V_121 , V_5 , V_92 ) ;
}
static int F_136 ( struct V_25 * V_121 )
{
return F_127 ( V_121 , V_4 , V_92 ) ;
}
static int F_137 ( struct V_25 * V_121 )
{
return F_127 ( V_121 , V_5 , V_92 ) ;
}
static int F_138 ( struct V_25 * V_121 , struct V_281 * V_282 ,
int V_283 , T_4 V_235 )
{
struct V_80 V_81 ;
struct V_11 * V_46 ;
struct V_11 * V_263 = F_7 ( V_121 ) ;
int V_14 ;
if ( ! V_283 )
return 0 ;
F_33 ( & V_81 , V_92 , V_85 ) ;
F_34 ( & V_81 , V_121 ) ;
if ( V_235 == 0 ) {
V_14 = F_67 ( V_263 , V_265 , & V_81 ) ;
V_14 = F_6 ( V_121 , V_265 , V_14 ) ;
return V_14 ;
}
V_46 = F_125 ( V_235 ) ;
V_14 = V_258 ( V_46 , V_263 , V_265 , & V_81 ) ;
V_14 = F_2 ( L_12 , V_46 , V_263 , V_265 , V_14 ) ;
return V_14 ;
}
static void F_139 ( struct V_25 * V_121 , struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_11 * V_46 = F_7 ( V_121 ) ;
V_29 -> V_37 = V_46 ;
}
static int F_140 ( struct V_225 * V_228 , int V_284 , T_1 V_285 )
{
struct V_11 * V_46 = F_45 () ;
struct V_222 * V_223 ;
V_223 = F_15 ( sizeof( struct V_222 ) , V_285 ) ;
if ( V_223 == NULL )
return - V_52 ;
if ( F_106 ( V_23 -> V_165 & V_286 ) ) {
V_223 -> V_231 = & V_219 ;
V_223 -> V_233 = & V_219 ;
} else {
V_223 -> V_231 = V_46 ;
V_223 -> V_233 = V_46 ;
}
V_223 -> V_287 = NULL ;
V_228 -> V_229 = V_223 ;
return 0 ;
}
static void F_141 ( struct V_225 * V_228 )
{
#ifdef F_142
struct V_288 * V_289 ;
if ( V_228 -> V_290 == V_291 ) {
F_35 () ;
F_25 (spp, &smk_ipv6_port_list, list) {
if ( V_289 -> V_292 != V_228 )
continue;
V_289 -> V_293 = 1 ;
break;
}
F_40 () ;
}
#endif
F_18 ( V_228 -> V_229 ) ;
}
static struct V_11 * F_143 ( struct V_294 * V_295 )
{
struct V_296 * V_297 ;
struct V_298 * V_299 = & V_295 -> V_300 ;
if ( V_299 -> V_301 == 0 )
return NULL ;
F_25 (snp, &smk_net4addr_list, list)
if ( V_297 -> V_302 . V_301 ==
( V_299 -> V_301 & V_297 -> V_303 . V_301 ) )
return V_297 -> V_73 ;
return NULL ;
}
static bool F_144 ( struct V_304 * V_295 )
{
T_6 * V_305 = ( T_6 * ) & V_295 -> V_306 ;
T_7 * V_307 = ( T_7 * ) & V_295 -> V_306 ;
if ( V_307 [ 0 ] == 0 && V_307 [ 1 ] == 0 && V_307 [ 2 ] == 0 && V_305 [ 6 ] == 0 &&
F_145 ( V_305 [ 7 ] ) == 1 )
return true ;
return false ;
}
static struct V_11 * F_146 ( struct V_304 * V_295 )
{
struct V_308 * V_297 ;
struct V_309 * V_310 = & V_295 -> V_306 ;
int V_3 ;
int V_311 = 0 ;
if ( F_144 ( V_295 ) )
return NULL ;
F_25 (snp, &smk_net6addr_list, list) {
if ( V_297 -> V_73 == NULL )
continue;
for ( V_311 = 1 , V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( ( V_310 -> V_312 [ V_3 ] & V_297 -> V_303 . V_312 [ V_3 ] ) !=
V_297 -> V_302 . V_312 [ V_3 ] ) {
V_311 = 0 ;
break;
}
}
if ( V_311 )
return V_297 -> V_73 ;
}
return NULL ;
}
static int F_147 ( struct V_225 * V_228 , int V_313 )
{
struct V_11 * V_46 ;
struct V_222 * V_223 = V_228 -> V_229 ;
int V_14 = 0 ;
F_148 () ;
F_149 ( V_228 ) ;
if ( V_223 -> V_233 == V_314 ||
V_313 == V_315 )
F_150 ( V_228 ) ;
else {
V_46 = V_223 -> V_233 ;
V_14 = F_151 ( V_228 , V_228 -> V_290 , & V_46 -> V_316 ) ;
}
F_152 ( V_228 ) ;
F_153 () ;
return V_14 ;
}
static int F_154 ( struct V_225 * V_228 , struct V_294 * V_310 )
{
struct V_11 * V_46 ;
int V_14 ;
int V_317 ;
struct V_11 * V_318 ;
struct V_222 * V_223 = V_228 -> V_229 ;
struct V_80 V_81 ;
F_35 () ;
V_318 = F_143 ( V_310 ) ;
if ( V_318 != NULL ) {
#ifdef F_155
struct V_319 V_320 ;
F_156 ( & V_81 , V_92 , V_321 , & V_320 ) ;
V_81 . V_322 . V_323 . V_320 -> V_284 = V_310 -> V_324 ;
V_81 . V_322 . V_323 . V_320 -> V_325 = V_310 -> V_326 ;
V_81 . V_322 . V_323 . V_320 -> V_327 . V_328 = V_310 -> V_300 . V_301 ;
#endif
V_317 = V_315 ;
V_46 = V_223 -> V_233 ;
V_14 = V_258 ( V_46 , V_318 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_13 , V_46 , V_318 , V_5 , V_14 ) ;
} else {
V_317 = V_329 ;
V_14 = 0 ;
}
F_40 () ;
if ( V_14 != 0 )
return V_14 ;
return F_147 ( V_228 , V_317 ) ;
}
static int F_157 ( struct V_11 * V_330 ,
struct V_11 * V_331 ,
struct V_304 * V_332 , int V_333 )
{
#ifdef F_155
struct V_319 V_320 ;
#endif
struct V_80 V_81 ;
int V_14 ;
#ifdef F_155
F_156 ( & V_81 , V_92 , V_321 , & V_320 ) ;
V_81 . V_322 . V_323 . V_320 -> V_284 = V_291 ;
V_81 . V_322 . V_323 . V_320 -> V_325 = F_145 ( V_332 -> V_334 ) ;
if ( V_333 == V_335 )
V_81 . V_322 . V_323 . V_320 -> V_336 . V_337 = V_332 -> V_306 ;
else
V_81 . V_322 . V_323 . V_320 -> V_336 . V_328 = V_332 -> V_306 ;
#endif
V_14 = V_258 ( V_330 , V_331 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_14 , V_330 , V_331 , V_5 , V_14 ) ;
return V_14 ;
}
static void F_158 ( struct V_224 * V_225 , struct V_338 * V_332 )
{
struct V_225 * V_228 = V_225 -> V_228 ;
struct V_304 * V_339 ;
struct V_222 * V_223 = V_225 -> V_228 -> V_229 ;
struct V_288 * V_289 ;
unsigned short V_340 = 0 ;
if ( V_332 == NULL ) {
F_35 () ;
F_25 (spp, &smk_ipv6_port_list, list) {
if ( V_228 != V_289 -> V_292 )
continue;
V_289 -> V_231 = V_223 -> V_231 ;
V_289 -> V_233 = V_223 -> V_233 ;
F_40 () ;
return;
}
F_40 () ;
return;
}
V_339 = (struct V_304 * ) V_332 ;
V_340 = F_145 ( V_339 -> V_334 ) ;
if ( V_340 == 0 )
return;
F_35 () ;
F_25 (spp, &smk_ipv6_port_list, list) {
if ( V_289 -> V_341 != V_340 || V_289 -> V_342 != V_225 -> type )
continue;
if ( V_289 -> V_293 != 1 ) {
F_40 () ;
return;
}
V_289 -> V_341 = V_340 ;
V_289 -> V_292 = V_228 ;
V_289 -> V_231 = V_223 -> V_231 ;
V_289 -> V_233 = V_223 -> V_233 ;
V_289 -> V_293 = 0 ;
F_40 () ;
return;
}
F_40 () ;
V_289 = F_15 ( sizeof( * V_289 ) , V_51 ) ;
if ( V_289 == NULL )
return;
V_289 -> V_341 = V_340 ;
V_289 -> V_292 = V_228 ;
V_289 -> V_231 = V_223 -> V_231 ;
V_289 -> V_233 = V_223 -> V_233 ;
V_289 -> V_342 = V_225 -> type ;
V_289 -> V_293 = 0 ;
F_159 ( & V_343 ) ;
F_26 ( & V_289 -> V_69 , & V_344 ) ;
F_160 ( & V_343 ) ;
return;
}
static int F_161 ( struct V_225 * V_228 , struct V_304 * V_332 ,
int V_333 )
{
struct V_288 * V_289 ;
struct V_222 * V_223 = V_228 -> V_229 ;
struct V_11 * V_46 = NULL ;
unsigned short V_340 ;
struct V_11 * V_331 ;
if ( V_333 == V_335 ) {
V_46 = F_146 ( V_332 ) ;
V_331 = V_223 -> V_231 ;
} else {
V_46 = V_223 -> V_233 ;
V_331 = F_146 ( V_332 ) ;
}
if ( V_46 != NULL && V_331 != NULL )
return F_157 ( V_46 , V_331 , V_332 , V_333 ) ;
if ( V_46 == NULL )
V_46 = V_314 ;
if ( V_331 == NULL )
V_331 = V_314 ;
if ( ! F_144 ( V_332 ) )
return F_157 ( V_46 , V_331 , V_332 , V_333 ) ;
if ( V_333 == V_335 )
return 0 ;
V_340 = F_145 ( V_332 -> V_334 ) ;
F_35 () ;
F_25 (spp, &smk_ipv6_port_list, list) {
if ( V_289 -> V_341 != V_340 || V_289 -> V_342 != V_228 -> V_345 )
continue;
V_331 = V_289 -> V_231 ;
if ( V_333 == V_346 )
V_223 -> V_287 = V_289 -> V_233 ;
break;
}
F_40 () ;
return F_157 ( V_46 , V_331 , V_332 , V_333 ) ;
}
static int F_162 ( struct V_27 * V_27 , const char * V_41 ,
const void * V_186 , T_3 V_206 , int V_165 )
{
struct V_11 * V_46 ;
struct V_28 * V_347 = V_27 -> V_30 ;
struct V_222 * V_223 ;
struct V_224 * V_225 ;
int V_14 = 0 ;
if ( V_186 == NULL || V_206 > V_50 || V_206 == 0 )
return - V_138 ;
V_46 = F_17 ( V_186 , V_206 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
if ( strcmp ( V_41 , V_190 ) == 0 ) {
V_347 -> V_37 = V_46 ;
V_347 -> V_31 |= V_348 ;
return 0 ;
}
if ( V_27 -> V_33 -> V_159 != V_227 )
return - V_49 ;
V_225 = F_100 ( V_27 ) ;
if ( V_225 == NULL || V_225 -> V_228 == NULL )
return - V_49 ;
V_223 = V_225 -> V_228 -> V_229 ;
if ( strcmp ( V_41 , V_230 ) == 0 )
V_223 -> V_231 = V_46 ;
else if ( strcmp ( V_41 , V_232 ) == 0 ) {
V_223 -> V_233 = V_46 ;
if ( V_225 -> V_228 -> V_290 == V_349 ) {
V_14 = F_147 ( V_225 -> V_228 , V_329 ) ;
if ( V_14 != 0 )
F_163 ( V_350
L_15 ,
V_92 , - V_14 ) ;
}
} else
return - V_49 ;
#ifdef F_142
if ( V_225 -> V_228 -> V_290 == V_291 )
F_158 ( V_225 , NULL ) ;
#endif
return 0 ;
}
static int F_164 ( struct V_224 * V_225 , int V_284 ,
int type , int V_351 , int V_352 )
{
struct V_222 * V_223 ;
if ( V_225 -> V_228 == NULL )
return 0 ;
if ( F_106 ( V_23 -> V_165 & V_286 ) ) {
V_223 = V_225 -> V_228 -> V_229 ;
V_223 -> V_231 = & V_219 ;
V_223 -> V_233 = & V_219 ;
}
if ( V_284 != V_349 )
return 0 ;
return F_147 ( V_225 -> V_228 , V_329 ) ;
}
static int F_165 ( struct V_224 * V_225 , struct V_338 * V_332 ,
int V_353 )
{
if ( V_225 -> V_228 != NULL && V_225 -> V_228 -> V_290 == V_291 )
F_158 ( V_225 , V_332 ) ;
return 0 ;
}
static int F_166 ( struct V_224 * V_225 , struct V_338 * V_310 ,
int V_353 )
{
int V_14 = 0 ;
#if F_167 ( V_354 )
struct V_304 * V_295 = (struct V_304 * ) V_310 ;
#endif
#ifdef F_168
struct V_11 * V_355 ;
struct V_222 * V_223 = V_225 -> V_228 -> V_229 ;
#endif
if ( V_225 -> V_228 == NULL )
return 0 ;
switch ( V_225 -> V_228 -> V_290 ) {
case V_349 :
if ( V_353 < sizeof( struct V_294 ) )
return - V_138 ;
V_14 = F_154 ( V_225 -> V_228 , (struct V_294 * ) V_310 ) ;
break;
case V_291 :
if ( V_353 < sizeof( struct V_304 ) )
return - V_138 ;
#ifdef F_168
V_355 = F_146 ( V_295 ) ;
if ( V_355 != NULL )
V_14 = F_157 ( V_223 -> V_233 , V_355 , V_295 ,
V_346 ) ;
#endif
#ifdef F_142
V_14 = F_161 ( V_225 -> V_228 , V_295 , V_346 ) ;
#endif
break;
}
return V_14 ;
}
static int F_169 ( int V_165 )
{
int V_189 = 0 ;
if ( V_165 & V_356 )
V_189 |= V_4 ;
if ( V_165 & V_357 )
V_189 |= V_5 ;
if ( V_165 & V_358 )
V_189 |= V_6 ;
return V_189 ;
}
static int F_170 ( struct V_359 * V_360 )
{
struct V_11 * V_46 = F_45 () ;
V_360 -> V_40 = V_46 ;
return 0 ;
}
static void F_171 ( struct V_359 * V_360 )
{
V_360 -> V_40 = NULL ;
}
static struct V_11 * F_172 ( struct V_361 * V_362 )
{
return (struct V_11 * ) V_362 -> V_363 . V_40 ;
}
static int F_173 ( struct V_361 * V_362 )
{
struct V_364 * V_29 = & V_362 -> V_363 ;
struct V_11 * V_46 = F_45 () ;
V_29 -> V_40 = V_46 ;
return 0 ;
}
static void F_174 ( struct V_361 * V_362 )
{
struct V_364 * V_29 = & V_362 -> V_363 ;
V_29 -> V_40 = NULL ;
}
static int F_175 ( struct V_361 * V_362 , int V_276 )
{
struct V_11 * V_223 = F_172 ( V_362 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_155
F_33 ( & V_81 , V_92 , V_365 ) ;
V_81 . V_322 . V_323 . V_366 = V_362 -> V_363 . V_367 ;
#endif
V_14 = F_67 ( V_223 , V_276 , & V_81 ) ;
V_14 = F_4 ( L_16 , V_223 , V_276 , V_14 ) ;
return V_14 ;
}
static int F_176 ( struct V_361 * V_362 , int V_368 )
{
int V_189 ;
V_189 = F_169 ( V_368 ) ;
return F_175 ( V_362 , V_189 ) ;
}
static int F_177 ( struct V_361 * V_362 , int V_238 )
{
int V_189 ;
switch ( V_238 ) {
case V_369 :
case V_370 :
V_189 = V_4 ;
break;
case V_371 :
case V_372 :
case V_373 :
case V_374 :
V_189 = V_75 ;
break;
case V_375 :
case V_376 :
return 0 ;
default:
return - V_138 ;
}
return F_175 ( V_362 , V_189 ) ;
}
static int F_178 ( struct V_361 * V_362 , char T_8 * V_377 ,
int V_368 )
{
int V_189 ;
V_189 = F_169 ( V_368 ) ;
return F_175 ( V_362 , V_189 ) ;
}
static struct V_11 * F_179 ( struct V_378 * V_379 )
{
return (struct V_11 * ) V_379 -> V_380 . V_40 ;
}
static int F_180 ( struct V_378 * V_379 )
{
struct V_364 * V_29 = & V_379 -> V_380 ;
struct V_11 * V_46 = F_45 () ;
V_29 -> V_40 = V_46 ;
return 0 ;
}
static void F_181 ( struct V_378 * V_379 )
{
struct V_364 * V_29 = & V_379 -> V_380 ;
V_29 -> V_40 = NULL ;
}
static int F_182 ( struct V_378 * V_379 , int V_276 )
{
struct V_11 * V_223 = F_179 ( V_379 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_155
F_33 ( & V_81 , V_92 , V_365 ) ;
V_81 . V_322 . V_323 . V_366 = V_379 -> V_380 . V_367 ;
#endif
V_14 = F_67 ( V_223 , V_276 , & V_81 ) ;
V_14 = F_4 ( L_17 , V_223 , V_276 , V_14 ) ;
return V_14 ;
}
static int F_183 ( struct V_378 * V_379 , int V_381 )
{
int V_189 ;
V_189 = F_169 ( V_381 ) ;
return F_182 ( V_379 , V_189 ) ;
}
static int F_184 ( struct V_378 * V_379 , int V_238 )
{
int V_189 ;
switch ( V_238 ) {
case V_382 :
case V_383 :
case V_384 :
case V_385 :
case V_386 :
case V_369 :
case V_387 :
V_189 = V_4 ;
break;
case V_388 :
case V_389 :
case V_374 :
case V_371 :
V_189 = V_75 ;
break;
case V_375 :
case V_390 :
return 0 ;
default:
return - V_138 ;
}
return F_182 ( V_379 , V_189 ) ;
}
static int F_185 ( struct V_378 * V_379 , struct V_391 * V_392 ,
unsigned V_393 , int V_394 )
{
return F_182 ( V_379 , V_75 ) ;
}
static int F_186 ( struct V_395 * V_396 )
{
struct V_364 * V_397 = & V_396 -> V_398 ;
struct V_11 * V_46 = F_45 () ;
V_397 -> V_40 = V_46 ;
return 0 ;
}
static void F_187 ( struct V_395 * V_396 )
{
struct V_364 * V_397 = & V_396 -> V_398 ;
V_397 -> V_40 = NULL ;
}
static struct V_11 * F_188 ( struct V_395 * V_396 )
{
return (struct V_11 * ) V_396 -> V_398 . V_40 ;
}
static int F_189 ( struct V_395 * V_396 , int V_276 )
{
struct V_11 * V_399 = F_188 ( V_396 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_155
F_33 ( & V_81 , V_92 , V_365 ) ;
V_81 . V_322 . V_323 . V_366 = V_396 -> V_398 . V_367 ;
#endif
V_14 = F_67 ( V_399 , V_276 , & V_81 ) ;
V_14 = F_4 ( L_18 , V_399 , V_276 , V_14 ) ;
return V_14 ;
}
static int F_190 ( struct V_395 * V_396 , int V_400 )
{
int V_189 ;
V_189 = F_169 ( V_400 ) ;
return F_189 ( V_396 , V_189 ) ;
}
static int F_191 ( struct V_395 * V_396 , int V_238 )
{
int V_189 ;
switch ( V_238 ) {
case V_369 :
case V_401 :
V_189 = V_4 ;
break;
case V_371 :
case V_374 :
V_189 = V_75 ;
break;
case V_375 :
case V_402 :
return 0 ;
default:
return - V_138 ;
}
return F_189 ( V_396 , V_189 ) ;
}
static int F_192 ( struct V_395 * V_396 , struct V_359 * V_360 ,
int V_400 )
{
int V_189 ;
V_189 = F_169 ( V_400 ) ;
return F_189 ( V_396 , V_189 ) ;
}
static int F_193 ( struct V_395 * V_396 , struct V_359 * V_360 ,
struct V_25 * V_403 , long type , int V_1 )
{
return F_189 ( V_396 , V_75 ) ;
}
static int F_194 ( struct V_364 * V_404 , short V_405 )
{
struct V_11 * V_406 = V_404 -> V_40 ;
int V_189 = F_169 ( V_405 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_155
F_33 ( & V_81 , V_92 , V_365 ) ;
V_81 . V_322 . V_323 . V_366 = V_404 -> V_367 ;
#endif
V_14 = F_67 ( V_406 , V_189 , & V_81 ) ;
V_14 = F_4 ( L_19 , V_406 , V_189 , V_14 ) ;
return V_14 ;
}
static void F_195 ( struct V_364 * V_404 , T_4 * V_235 )
{
struct V_11 * V_406 = V_404 -> V_40 ;
* V_235 = V_406 -> V_236 ;
}
static void F_196 ( struct V_43 * V_407 , struct V_27 * V_27 )
{
struct V_97 * V_168 ;
struct V_99 * V_100 ;
struct V_28 * V_29 ;
struct V_11 * V_46 ;
struct V_11 * V_408 = F_45 () ;
struct V_11 * V_409 ;
char V_410 [ V_216 ] ;
int V_411 = 0 ;
int V_14 ;
struct V_43 * V_44 ;
if ( V_27 == NULL )
return;
V_29 = V_27 -> V_30 ;
F_159 ( & V_29 -> V_55 ) ;
if ( V_29 -> V_31 & V_348 )
goto V_412;
V_168 = V_27 -> V_33 ;
V_100 = V_168 -> V_107 ;
V_409 = V_100 -> V_103 ;
if ( V_407 -> V_413 == V_407 ) {
switch ( V_168 -> V_159 ) {
case V_414 :
V_100 -> V_101 = & V_218 ;
V_100 -> V_103 = & V_218 ;
V_29 -> V_37 = V_100 -> V_101 ;
break;
case V_161 :
V_29 -> V_37 = F_45 () ;
break;
case V_415 :
V_29 -> V_37 = F_45 () ;
break;
case V_227 :
V_29 -> V_37 = & V_218 ;
break;
default:
V_29 -> V_37 = V_100 -> V_101 ;
break;
}
V_29 -> V_31 |= V_348 ;
goto V_412;
}
switch ( V_168 -> V_159 ) {
case V_416 :
case V_414 :
V_409 = & V_218 ;
break;
case V_417 :
V_409 = V_408 ;
break;
case V_418 :
break;
case V_161 :
V_409 = & V_218 ;
default:
if ( F_197 ( V_27 -> V_419 ) ) {
V_409 = & V_218 ;
break;
}
if ( ! ( V_27 -> V_47 & V_48 ) )
break;
V_44 = F_198 ( V_407 ) ;
V_46 = F_13 ( V_210 , V_27 , V_44 ) ;
if ( ! F_199 ( V_46 ) )
V_409 = V_46 ;
if ( F_200 ( V_27 -> V_419 ) ) {
if ( V_29 -> V_31 & V_191 ) {
V_29 -> V_31 &= ~ V_191 ;
V_14 = F_201 ( V_44 , V_27 ,
V_215 ,
V_217 , V_216 ,
0 ) ;
} else {
V_14 = F_16 ( V_44 , V_27 ,
V_215 , V_410 ,
V_216 ) ;
if ( V_14 >= 0 && strncmp ( V_410 , V_217 ,
V_216 ) != 0 )
V_14 = - V_138 ;
}
if ( V_14 >= 0 )
V_411 = V_164 ;
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
F_202 ( V_44 ) ;
break;
}
if ( V_409 == NULL )
V_29 -> V_37 = V_408 ;
else
V_29 -> V_37 = V_409 ;
V_29 -> V_31 |= ( V_348 | V_411 ) ;
V_412:
F_160 ( & V_29 -> V_55 ) ;
return;
}
static int F_203 ( struct V_25 * V_121 , char * V_41 , char * * V_186 )
{
struct V_11 * V_46 = F_7 ( V_121 ) ;
char * V_110 ;
int V_420 ;
if ( strcmp ( V_41 , L_20 ) != 0 )
return - V_138 ;
V_110 = F_82 ( V_46 -> V_19 , V_51 ) ;
if ( V_110 == NULL )
return - V_52 ;
V_420 = strlen ( V_110 ) ;
* V_186 = V_110 ;
return V_420 ;
}
static int F_204 ( const char * V_41 , void * V_186 , T_3 V_206 )
{
struct V_20 * V_21 = F_5 () ;
struct V_39 * V_272 ;
struct V_11 * V_46 ;
struct V_70 * V_421 ;
int V_14 ;
if ( ! F_46 ( V_155 ) && F_205 ( & V_21 -> V_61 ) )
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
if ( V_421 -> V_73 == V_46 ) {
V_14 = 0 ;
break;
}
if ( V_14 )
return V_14 ;
}
V_272 = F_206 () ;
if ( V_272 == NULL )
return - V_52 ;
V_21 = V_272 -> V_40 ;
V_21 -> V_22 = V_46 ;
F_29 ( & V_21 -> V_61 ) ;
F_207 ( V_272 ) ;
return V_206 ;
}
static int F_208 ( struct V_225 * V_225 ,
struct V_225 * V_422 , struct V_225 * V_423 )
{
struct V_11 * V_46 ;
struct V_11 * V_252 ;
struct V_222 * V_223 = V_225 -> V_229 ;
struct V_222 * V_424 = V_422 -> V_229 ;
struct V_222 * V_347 = V_423 -> V_229 ;
struct V_80 V_81 ;
int V_14 = 0 ;
#ifdef F_155
struct V_319 V_320 ;
#endif
if ( ! F_46 ( V_95 ) ) {
V_46 = V_223 -> V_233 ;
V_252 = V_424 -> V_231 ;
#ifdef F_155
F_156 ( & V_81 , V_92 , V_321 , & V_320 ) ;
F_209 ( & V_81 , V_422 ) ;
#endif
V_14 = V_258 ( V_46 , V_252 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_21 , V_46 , V_252 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_252 = V_424 -> V_233 ;
V_46 = V_223 -> V_231 ;
V_14 = V_258 ( V_252 , V_46 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_21 , V_252 , V_46 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_347 -> V_287 = V_223 -> V_233 ;
V_223 -> V_287 = V_424 -> V_233 ;
}
return V_14 ;
}
static int F_210 ( struct V_224 * V_225 , struct V_224 * V_422 )
{
struct V_222 * V_223 = V_225 -> V_228 -> V_229 ;
struct V_222 * V_424 = V_422 -> V_228 -> V_229 ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_155
struct V_319 V_320 ;
F_156 ( & V_81 , V_92 , V_321 , & V_320 ) ;
F_209 ( & V_81 , V_422 -> V_228 ) ;
#endif
if ( F_46 ( V_95 ) )
return 0 ;
V_14 = V_258 ( V_223 -> V_233 , V_424 -> V_231 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_22 , V_223 -> V_233 , V_424 -> V_231 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_211 ( struct V_224 * V_225 , struct V_425 * V_360 ,
int V_206 )
{
struct V_294 * V_295 = (struct V_294 * ) V_360 -> V_426 ;
#if F_167 ( V_354 )
struct V_304 * V_310 = (struct V_304 * ) V_360 -> V_426 ;
#endif
#ifdef F_168
struct V_222 * V_223 = V_225 -> V_228 -> V_229 ;
struct V_11 * V_355 ;
#endif
int V_14 = 0 ;
if ( V_295 == NULL )
return 0 ;
switch ( V_225 -> V_228 -> V_290 ) {
case V_427 :
V_14 = F_154 ( V_225 -> V_228 , V_295 ) ;
break;
case V_428 :
#ifdef F_168
V_355 = F_146 ( V_310 ) ;
if ( V_355 != NULL )
V_14 = F_157 ( V_223 -> V_233 , V_355 , V_310 ,
V_346 ) ;
#endif
#ifdef F_142
V_14 = F_161 ( V_225 -> V_228 , V_310 , V_429 ) ;
#endif
break;
}
return V_14 ;
}
static struct V_11 * F_212 ( struct V_430 * V_310 ,
struct V_222 * V_223 )
{
struct V_11 * V_46 ;
int V_311 = 0 ;
int V_431 ;
int V_432 ;
if ( ( V_310 -> V_165 & V_433 ) != 0 ) {
F_35 () ;
F_25 (skp, &smack_known_list, list) {
if ( V_310 -> V_434 . V_435 . V_436 != V_46 -> V_316 . V_434 . V_435 . V_436 )
continue;
if ( ( V_310 -> V_165 & V_437 ) == 0 ) {
if ( ( V_46 -> V_316 . V_165 &
V_437 ) == 0 )
V_311 = 1 ;
break;
}
for ( V_431 = - 1 , V_432 = - 1 ; V_431 == V_432 ; ) {
V_431 = F_213 ( V_310 -> V_434 . V_435 . V_438 ,
V_431 + 1 ) ;
V_432 = F_213 (
V_46 -> V_316 . V_434 . V_435 . V_438 ,
V_432 + 1 ) ;
if ( V_431 < 0 || V_432 < 0 )
break;
}
if ( V_431 == V_432 ) {
V_311 = 1 ;
break;
}
}
F_40 () ;
if ( V_311 )
return V_46 ;
if ( V_223 != NULL && V_223 -> V_231 == & V_218 )
return & V_219 ;
return & V_218 ;
}
if ( ( V_310 -> V_165 & V_439 ) != 0 )
return F_125 ( V_310 -> V_434 . V_235 ) ;
return V_314 ;
}
static int F_214 ( struct V_440 * V_441 , struct V_304 * V_295 )
{
T_9 V_442 ;
int V_443 ;
int V_444 = - V_138 ;
struct V_445 V_446 ;
struct V_445 * V_447 ;
T_6 V_448 ;
struct V_449 V_450 , * V_451 ;
struct V_452 V_453 , * V_454 ;
struct V_455 V_456 , * V_457 ;
V_295 -> V_334 = 0 ;
V_443 = F_215 ( V_441 ) ;
V_447 = F_216 ( V_441 , V_443 , sizeof( V_446 ) , & V_446 ) ;
if ( V_447 == NULL )
return - V_138 ;
V_295 -> V_306 = V_447 -> V_337 ;
V_442 = V_447 -> V_442 ;
V_443 += sizeof( V_446 ) ;
V_443 = F_217 ( V_441 , V_443 , & V_442 , & V_448 ) ;
if ( V_443 < 0 )
return - V_138 ;
V_444 = V_442 ;
switch ( V_444 ) {
case V_458 :
V_451 = F_216 ( V_441 , V_443 , sizeof( V_450 ) , & V_450 ) ;
if ( V_451 != NULL )
V_295 -> V_334 = V_451 -> V_459 ;
break;
case V_460 :
V_454 = F_216 ( V_441 , V_443 , sizeof( V_453 ) , & V_453 ) ;
if ( V_454 != NULL )
V_295 -> V_334 = V_454 -> V_459 ;
break;
case V_461 :
V_457 = F_216 ( V_441 , V_443 , sizeof( V_456 ) , & V_456 ) ;
if ( V_457 != NULL )
V_295 -> V_334 = V_457 -> V_462 ;
break;
}
return V_444 ;
}
static int F_218 ( struct V_225 * V_228 , struct V_440 * V_441 )
{
struct V_430 V_463 ;
struct V_222 * V_223 = V_228 -> V_229 ;
struct V_11 * V_46 = NULL ;
int V_14 = 0 ;
struct V_80 V_81 ;
#ifdef F_155
struct V_319 V_320 ;
#endif
#if F_167 ( V_354 )
struct V_304 V_464 ;
int V_444 ;
#endif
switch ( V_228 -> V_290 ) {
case V_349 :
#ifdef F_219
if ( V_441 && V_441 -> V_465 != 0 ) {
V_46 = F_125 ( V_441 -> V_465 ) ;
goto V_466;
}
#endif
F_220 ( & V_463 ) ;
V_14 = F_221 ( V_441 , V_228 -> V_290 , & V_463 ) ;
if ( V_14 == 0 )
V_46 = F_212 ( & V_463 , V_223 ) ;
else
V_46 = V_314 ;
F_222 ( & V_463 ) ;
#ifdef F_219
V_466:
#endif
#ifdef F_155
F_156 ( & V_81 , V_92 , V_321 , & V_320 ) ;
V_81 . V_322 . V_323 . V_320 -> V_284 = V_228 -> V_290 ;
V_81 . V_322 . V_323 . V_320 -> V_467 = V_441 -> V_468 ;
F_223 ( V_441 , & V_81 . V_322 , NULL ) ;
#endif
V_14 = V_258 ( V_46 , V_223 -> V_231 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_23 , V_46 , V_223 -> V_231 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_224 ( V_441 , V_228 -> V_290 , V_14 , 0 ) ;
break;
#if F_167 ( V_354 )
case V_291 :
V_444 = F_214 ( V_441 , & V_464 ) ;
if ( V_444 != V_460 && V_444 != V_458 )
break;
#ifdef F_168
if ( V_441 && V_441 -> V_465 != 0 )
V_46 = F_125 ( V_441 -> V_465 ) ;
else
V_46 = F_146 ( & V_464 ) ;
if ( V_46 == NULL )
V_46 = V_314 ;
#ifdef F_155
F_156 ( & V_81 , V_92 , V_321 , & V_320 ) ;
V_81 . V_322 . V_323 . V_320 -> V_284 = V_228 -> V_290 ;
V_81 . V_322 . V_323 . V_320 -> V_467 = V_441 -> V_468 ;
F_225 ( V_441 , & V_81 . V_322 , NULL ) ;
#endif
V_14 = V_258 ( V_46 , V_223 -> V_231 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_24 , V_46 , V_223 -> V_231 ,
V_5 , V_14 ) ;
#endif
#ifdef F_142
V_14 = F_161 ( V_228 , & V_464 , V_335 ) ;
#endif
break;
#endif
}
return V_14 ;
}
static int F_226 ( struct V_224 * V_225 ,
char T_8 * V_469 ,
int T_8 * V_470 , unsigned V_187 )
{
struct V_222 * V_223 ;
char * V_471 = L_25 ;
int V_420 = 1 ;
int V_14 = 0 ;
V_223 = V_225 -> V_228 -> V_229 ;
if ( V_223 -> V_287 != NULL ) {
V_471 = V_223 -> V_287 -> V_19 ;
V_420 = strlen ( V_471 ) + 1 ;
}
if ( V_420 > V_187 )
V_14 = - V_472 ;
else if ( F_227 ( V_469 , V_471 , V_420 ) != 0 )
V_14 = - V_473 ;
if ( F_228 ( V_420 , V_470 ) != 0 )
V_14 = - V_473 ;
return V_14 ;
}
static int F_229 ( struct V_224 * V_225 ,
struct V_440 * V_441 , T_4 * V_235 )
{
struct V_430 V_463 ;
struct V_222 * V_223 = NULL ;
struct V_11 * V_46 ;
int V_284 = V_474 ;
T_4 V_2 = 0 ;
int V_14 ;
if ( V_441 != NULL ) {
if ( V_441 -> V_351 == F_230 ( V_475 ) )
V_284 = V_349 ;
#if F_167 ( V_354 )
else if ( V_441 -> V_351 == F_230 ( V_476 ) )
V_284 = V_291 ;
#endif
}
if ( V_284 == V_474 && V_225 != NULL )
V_284 = V_225 -> V_228 -> V_290 ;
switch ( V_284 ) {
case V_477 :
V_223 = V_225 -> V_228 -> V_229 ;
V_2 = V_223 -> V_233 -> V_236 ;
break;
case V_349 :
#ifdef F_219
V_2 = V_441 -> V_465 ;
if ( V_2 != 0 )
break;
#endif
if ( V_225 != NULL && V_225 -> V_228 != NULL )
V_223 = V_225 -> V_228 -> V_229 ;
F_220 ( & V_463 ) ;
V_14 = F_221 ( V_441 , V_284 , & V_463 ) ;
if ( V_14 == 0 ) {
V_46 = F_212 ( & V_463 , V_223 ) ;
V_2 = V_46 -> V_236 ;
}
F_222 ( & V_463 ) ;
break;
case V_291 :
#ifdef F_168
V_2 = V_441 -> V_465 ;
#endif
break;
}
* V_235 = V_2 ;
if ( V_2 == 0 )
return - V_138 ;
return 0 ;
}
static void F_231 ( struct V_225 * V_228 , struct V_224 * V_478 )
{
struct V_222 * V_223 ;
struct V_11 * V_46 = F_45 () ;
if ( V_228 == NULL ||
( V_228 -> V_290 != V_349 && V_228 -> V_290 != V_291 ) )
return;
V_223 = V_228 -> V_229 ;
V_223 -> V_231 = V_46 ;
V_223 -> V_233 = V_46 ;
}
static int F_232 ( struct V_225 * V_228 , struct V_440 * V_441 ,
struct V_479 * V_480 )
{
T_10 V_284 = V_228 -> V_290 ;
struct V_11 * V_46 ;
struct V_222 * V_223 = V_228 -> V_229 ;
struct V_430 V_463 ;
struct V_294 V_481 ;
struct V_482 * V_483 ;
struct V_11 * V_484 ;
int V_14 ;
struct V_80 V_81 ;
#ifdef F_155
struct V_319 V_320 ;
#endif
#if F_167 ( V_354 )
if ( V_284 == V_291 ) {
if ( V_441 -> V_351 == F_230 ( V_475 ) )
V_284 = V_349 ;
else
return 0 ;
}
#endif
#ifdef F_219
if ( V_441 && V_441 -> V_465 != 0 ) {
V_46 = F_125 ( V_441 -> V_465 ) ;
goto V_466;
}
#endif
F_220 ( & V_463 ) ;
V_14 = F_221 ( V_441 , V_284 , & V_463 ) ;
if ( V_14 == 0 )
V_46 = F_212 ( & V_463 , V_223 ) ;
else
V_46 = & V_485 ;
F_222 ( & V_463 ) ;
#ifdef F_219
V_466:
#endif
#ifdef F_155
F_156 ( & V_81 , V_92 , V_321 , & V_320 ) ;
V_81 . V_322 . V_323 . V_320 -> V_284 = V_284 ;
V_81 . V_322 . V_323 . V_320 -> V_467 = V_441 -> V_468 ;
F_223 ( V_441 , & V_81 . V_322 , NULL ) ;
#endif
V_14 = V_258 ( V_46 , V_223 -> V_231 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_26 , V_46 , V_223 -> V_231 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_480 -> V_486 = V_46 -> V_236 ;
V_483 = F_233 ( V_441 ) ;
V_481 . V_300 . V_301 = V_483 -> V_337 ;
F_35 () ;
V_484 = F_143 ( & V_481 ) ;
F_40 () ;
if ( V_484 == NULL )
V_14 = F_234 ( V_480 , & V_46 -> V_316 ) ;
else
F_235 ( V_480 ) ;
return V_14 ;
}
static void F_236 ( struct V_225 * V_228 ,
const struct V_479 * V_480 )
{
struct V_222 * V_223 = V_228 -> V_229 ;
struct V_11 * V_46 ;
if ( V_480 -> V_486 != 0 ) {
V_46 = F_125 ( V_480 -> V_486 ) ;
V_223 -> V_287 = V_46 ;
} else
V_223 -> V_287 = NULL ;
}
static int F_237 ( struct V_487 * V_487 , const struct V_39 * V_39 ,
unsigned long V_165 )
{
struct V_11 * V_46 = F_37 ( V_39 -> V_40 ) ;
V_487 -> V_40 = V_46 ;
return 0 ;
}
static void F_238 ( struct V_487 * V_487 )
{
V_487 -> V_40 = NULL ;
}
static int F_239 ( T_11 V_488 ,
const struct V_39 * V_39 , unsigned V_489 )
{
struct V_487 * V_490 ;
struct V_80 V_81 ;
struct V_11 * V_263 = F_37 ( V_39 -> V_40 ) ;
int V_491 = 0 ;
int V_14 ;
V_490 = F_240 ( V_488 ) ;
if ( V_490 == NULL )
return - V_138 ;
if ( V_490 -> V_40 == NULL )
return 0 ;
if ( V_263 == NULL )
return - V_89 ;
#ifdef F_155
F_33 ( & V_81 , V_92 , V_492 ) ;
V_81 . V_322 . V_323 . V_493 . V_487 = V_490 -> V_494 ;
V_81 . V_322 . V_323 . V_493 . V_495 = V_490 -> V_496 ;
#endif
if ( V_489 & V_497 )
V_491 = V_4 ;
if ( V_489 & ( V_498 | V_499 | V_500 ) )
V_491 = V_5 ;
V_14 = V_258 ( V_263 , V_490 -> V_40 , V_491 , & V_81 ) ;
V_14 = F_2 ( L_27 , V_263 , V_490 -> V_40 , V_491 , V_14 ) ;
return V_14 ;
}
static int F_241 ( struct V_487 * V_487 , char * * V_501 )
{
struct V_11 * V_46 = V_487 -> V_40 ;
T_3 V_502 ;
char * V_503 ;
if ( V_487 -> V_40 == NULL ) {
* V_501 = NULL ;
return 0 ;
}
V_503 = F_82 ( V_46 -> V_19 , V_51 ) ;
if ( V_503 == NULL )
return - V_52 ;
V_502 = strlen ( V_503 ) + 1 ;
* V_501 = V_503 ;
return V_502 ;
}
static int F_242 ( T_4 V_504 , T_4 V_505 , char * V_506 , void * * V_507 )
{
struct V_11 * V_46 ;
char * * V_508 = ( char * * ) V_507 ;
* V_508 = NULL ;
if ( V_504 != V_509 && V_504 != V_510 )
return - V_138 ;
if ( V_505 != V_511 && V_505 != V_512 )
return - V_138 ;
V_46 = F_17 ( V_506 , 0 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
* V_508 = V_46 -> V_19 ;
return 0 ;
}
static int F_243 ( struct V_513 * V_514 )
{
struct V_515 * V_516 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_514 -> V_517 ; V_3 ++ ) {
V_516 = & V_514 -> V_518 [ V_3 ] ;
if ( V_516 -> type == V_509 || V_516 -> type == V_510 )
return 1 ;
}
return 0 ;
}
static int F_244 ( T_4 V_235 , T_4 V_504 , T_4 V_505 , void * V_507 ,
struct V_519 * V_520 )
{
struct V_11 * V_46 ;
char * V_508 = V_507 ;
if ( F_106 ( ! V_508 ) ) {
F_245 ( 1 , L_28 ) ;
return - V_257 ;
}
if ( V_504 != V_509 && V_504 != V_510 )
return 0 ;
V_46 = F_125 ( V_235 ) ;
if ( V_505 == V_511 )
return ( V_508 == V_46 -> V_19 ) ;
if ( V_505 == V_512 )
return ( V_508 != V_46 -> V_19 ) ;
return 0 ;
}
static int F_246 ( const char * V_41 )
{
return ( strcmp ( V_41 , V_190 ) == 0 ) ;
}
static int F_247 ( T_4 V_235 , char * * V_521 , T_4 * V_522 )
{
struct V_11 * V_46 = F_125 ( V_235 ) ;
if ( V_521 )
* V_521 = V_46 -> V_19 ;
* V_522 = strlen ( V_46 -> V_19 ) ;
return 0 ;
}
static int F_248 ( const char * V_521 , T_4 V_522 , T_4 * V_235 )
{
struct V_11 * V_46 = F_249 ( V_521 ) ;
if ( V_46 )
* V_235 = V_46 -> V_236 ;
else
* V_235 = 0 ;
return 0 ;
}
static int F_250 ( struct V_27 * V_27 , void * V_523 , T_4 V_524 )
{
return F_162 ( V_27 , V_190 , V_523 , V_524 , 0 ) ;
}
static int F_251 ( struct V_43 * V_43 , void * V_523 , T_4 V_524 )
{
return F_252 ( V_43 , V_210 , V_523 , V_524 , 0 ) ;
}
static int F_253 ( struct V_27 * V_27 , void * * V_523 , T_4 * V_524 )
{
int V_187 = 0 ;
V_187 = F_99 ( V_27 , V_190 , V_523 , true ) ;
if ( V_187 < 0 )
return V_187 ;
* V_524 = V_187 ;
return 0 ;
}
static T_12 void F_254 ( void )
{
F_21 ( & V_485 . V_62 ) ;
F_21 ( & V_106 . V_62 ) ;
F_21 ( & V_102 . V_62 ) ;
F_21 ( & V_218 . V_62 ) ;
F_21 ( & V_219 . V_62 ) ;
F_23 ( & V_485 . V_60 ) ;
F_23 ( & V_106 . V_60 ) ;
F_23 ( & V_218 . V_60 ) ;
F_23 ( & V_102 . V_60 ) ;
F_23 ( & V_219 . V_60 ) ;
F_255 ( & V_485 ) ;
F_255 ( & V_106 ) ;
F_255 ( & V_218 ) ;
F_255 ( & V_102 ) ;
F_255 ( & V_219 ) ;
}
static T_12 int F_256 ( void )
{
struct V_39 * V_39 ;
struct V_20 * V_21 ;
if ( ! F_257 ( L_29 ) )
return 0 ;
V_53 = F_258 ( V_28 , 0 ) ;
if ( ! V_53 )
return - V_52 ;
V_21 = F_22 ( & V_102 , & V_102 ,
V_51 ) ;
if ( V_21 == NULL ) {
F_259 ( V_53 ) ;
return - V_52 ;
}
V_525 = 1 ;
F_3 ( L_30 ) ;
#ifdef F_219
F_3 ( L_31 ) ;
#endif
#ifdef F_142
F_3 ( L_32 ) ;
#endif
#ifdef F_168
F_3 ( L_33 ) ;
#endif
V_39 = (struct V_39 * ) V_23 -> V_39 ;
V_39 -> V_40 = V_21 ;
F_254 () ;
F_260 ( V_526 , F_261 ( V_526 ) , L_29 ) ;
return 0 ;
}

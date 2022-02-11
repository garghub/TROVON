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
F_23 ( V_64 ) ;
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
F_23 ( V_64 ) ;
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
if ( ! V_120 -> V_141 ) {
F_18 ( V_120 -> V_139 ) ;
goto V_133;
}
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
if ( V_172 -> V_175 & ( V_176 | V_177 ) ) {
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
V_172 -> V_178 |= V_179 ;
return 0 ;
}
static void F_71 ( struct V_171 * V_172 )
{
struct V_20 * V_173 = V_172 -> V_39 -> V_40 ;
if ( V_173 -> V_22 != V_173 -> V_59 )
V_23 -> V_180 = 0 ;
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
static void F_74 ( struct V_27 * V_27 )
{
F_75 ( V_53 , V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
static int F_76 ( struct V_27 * V_27 , struct V_27 * V_181 ,
const struct V_182 * V_182 , const char * * V_41 ,
void * * V_183 , T_3 * V_184 )
{
struct V_28 * V_185 = V_27 -> V_30 ;
struct V_11 * V_46 = F_45 () ;
struct V_11 * V_29 = F_11 ( V_27 ) ;
struct V_11 * V_186 = F_11 ( V_181 ) ;
int V_187 ;
if ( V_41 )
* V_41 = V_188 ;
if ( V_183 && V_184 ) {
F_35 () ;
V_187 = F_77 ( V_46 -> V_19 , V_186 -> V_19 ,
& V_46 -> V_60 ) ;
F_40 () ;
if ( V_187 > 0 && ( ( V_187 & V_8 ) != 0 ) &&
F_78 ( V_181 ) ) {
V_29 = V_186 ;
V_185 -> V_31 |= V_189 ;
}
* V_183 = F_79 ( V_29 -> V_19 , V_54 ) ;
if ( * V_183 == NULL )
return - V_52 ;
* V_184 = strlen ( V_29 -> V_19 ) ;
}
return 0 ;
}
static int F_80 ( struct V_43 * V_190 , struct V_27 * V_181 ,
struct V_43 * V_191 )
{
struct V_11 * V_29 ;
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_190 ) ;
V_29 = F_11 ( F_59 ( V_190 ) ) ;
V_14 = F_67 ( V_29 , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_190 ) , V_5 , V_14 ) ;
if ( V_14 == 0 && F_81 ( V_191 ) ) {
V_29 = F_11 ( F_59 ( V_191 ) ) ;
F_66 ( & V_81 , V_191 ) ;
V_14 = F_67 ( V_29 , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_191 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_82 ( struct V_27 * V_181 , struct V_43 * V_43 )
{
struct V_27 * V_42 = F_59 ( V_43 ) ;
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( V_42 ) , V_5 , & V_81 ) ;
V_14 = F_8 ( V_42 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_33 ( & V_81 , V_92 , V_192 ) ;
F_83 ( & V_81 , V_181 ) ;
V_14 = F_67 ( F_11 ( V_181 ) , V_5 , & V_81 ) ;
V_14 = F_8 ( V_181 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_84 ( struct V_27 * V_181 , struct V_43 * V_43 )
{
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_33 ( & V_81 , V_92 , V_192 ) ;
F_83 ( & V_81 , V_181 ) ;
V_14 = F_67 ( F_11 ( V_181 ) , V_5 , & V_81 ) ;
V_14 = F_8 ( V_181 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_85 ( struct V_27 * V_193 ,
struct V_43 * V_190 ,
struct V_27 * V_194 ,
struct V_43 * V_191 )
{
int V_14 ;
struct V_11 * V_29 ;
struct V_80 V_81 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_190 ) ;
V_29 = F_11 ( F_59 ( V_190 ) ) ;
V_14 = F_67 ( V_29 , V_75 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_190 ) , V_75 , V_14 ) ;
if ( V_14 == 0 && F_81 ( V_191 ) ) {
V_29 = F_11 ( F_59 ( V_191 ) ) ;
F_66 ( & V_81 , V_191 ) ;
V_14 = F_67 ( V_29 , V_75 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_191 ) , V_75 , V_14 ) ;
}
return V_14 ;
}
static int F_86 ( struct V_27 * V_27 , int V_195 )
{
struct V_99 * V_100 = V_27 -> V_33 -> V_107 ;
struct V_80 V_81 ;
int V_196 = V_195 & V_197 ;
int V_14 ;
V_195 &= ( V_4 | V_5 | V_6 | V_7 ) ;
if ( V_195 == 0 )
return 0 ;
if ( V_100 -> V_31 & V_163 ) {
if ( F_11 ( V_27 ) != V_100 -> V_101 )
return - V_89 ;
}
if ( V_196 )
return - V_198 ;
F_33 ( & V_81 , V_92 , V_192 ) ;
F_83 ( & V_81 , V_27 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_195 , & V_81 ) ;
V_14 = F_8 ( V_27 , V_195 , V_14 ) ;
return V_14 ;
}
static int F_87 ( struct V_43 * V_43 , struct V_199 * V_199 )
{
struct V_80 V_81 ;
int V_14 ;
if ( V_199 -> V_200 & V_201 )
return 0 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_5 , V_14 ) ;
return V_14 ;
}
static int F_88 ( const struct V_202 * V_202 )
{
struct V_80 V_81 ;
struct V_27 * V_27 = F_59 ( V_202 -> V_43 ) ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_203 ) ;
F_89 ( & V_81 , * V_202 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_4 , & V_81 ) ;
V_14 = F_8 ( V_27 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_90 ( struct V_43 * V_43 , const char * V_41 ,
const void * V_183 , T_3 V_204 , int V_165 )
{
struct V_80 V_81 ;
struct V_11 * V_46 ;
int V_205 = 0 ;
int V_206 = 0 ;
int V_207 = 0 ;
int V_14 = 0 ;
if ( strcmp ( V_41 , V_208 ) == 0 ||
strcmp ( V_41 , V_209 ) == 0 ||
strcmp ( V_41 , V_210 ) == 0 ) {
V_205 = 1 ;
V_206 = 1 ;
} else if ( strcmp ( V_41 , V_211 ) == 0 ||
strcmp ( V_41 , V_212 ) == 0 ) {
V_205 = 1 ;
V_206 = 1 ;
V_207 = 1 ;
} else if ( strcmp ( V_41 , V_213 ) == 0 ) {
V_205 = 1 ;
if ( V_204 != V_214 ||
strncmp ( V_183 , V_215 , V_214 ) != 0 )
V_14 = - V_138 ;
} else
V_14 = F_91 ( V_43 , V_41 , V_183 , V_204 , V_165 ) ;
if ( V_205 && ! F_46 ( V_155 ) )
V_14 = - V_156 ;
if ( V_14 == 0 && V_206 ) {
V_46 = V_204 ? F_17 ( V_183 , V_204 ) : NULL ;
if ( F_60 ( V_46 ) )
V_14 = F_61 ( V_46 ) ;
else if ( V_46 == NULL || ( V_207 &&
( V_46 == & V_216 || V_46 == & V_217 ) ) )
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
static void F_92 ( struct V_43 * V_43 , const char * V_41 ,
const void * V_183 , T_3 V_204 , int V_165 )
{
struct V_11 * V_46 ;
struct V_28 * V_29 = F_59 ( V_43 ) -> V_30 ;
if ( strcmp ( V_41 , V_213 ) == 0 ) {
V_29 -> V_31 |= V_164 ;
return;
}
if ( strcmp ( V_41 , V_208 ) == 0 ) {
V_46 = F_17 ( V_183 , V_204 ) ;
if ( ! F_60 ( V_46 ) )
V_29 -> V_37 = V_46 ;
} else if ( strcmp ( V_41 , V_211 ) == 0 ) {
V_46 = F_17 ( V_183 , V_204 ) ;
if ( ! F_60 ( V_46 ) )
V_29 -> V_22 = V_46 ;
} else if ( strcmp ( V_41 , V_212 ) == 0 ) {
V_46 = F_17 ( V_183 , V_204 ) ;
if ( ! F_60 ( V_46 ) )
V_29 -> V_218 = V_46 ;
}
return;
}
static int F_93 ( struct V_43 * V_43 , const char * V_41 )
{
struct V_80 V_81 ;
int V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_4 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_4 , V_14 ) ;
return V_14 ;
}
static int F_94 ( struct V_43 * V_43 , const char * V_41 )
{
struct V_28 * V_29 ;
struct V_80 V_81 ;
int V_14 = 0 ;
if ( strcmp ( V_41 , V_208 ) == 0 ||
strcmp ( V_41 , V_209 ) == 0 ||
strcmp ( V_41 , V_210 ) == 0 ||
strcmp ( V_41 , V_211 ) == 0 ||
strcmp ( V_41 , V_213 ) == 0 ||
strcmp ( V_41 , V_212 ) == 0 ) {
if ( ! F_46 ( V_155 ) )
V_14 = - V_156 ;
} else
V_14 = F_95 ( V_43 , V_41 ) ;
if ( V_14 != 0 )
return V_14 ;
F_33 ( & V_81 , V_92 , V_170 ) ;
F_66 ( & V_81 , V_43 ) ;
V_14 = F_67 ( F_11 ( F_59 ( V_43 ) ) , V_5 , & V_81 ) ;
V_14 = F_8 ( F_59 ( V_43 ) , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_29 = F_59 ( V_43 ) -> V_30 ;
if ( strcmp ( V_41 , V_208 ) == 0 ) {
struct V_97 * V_168 = V_43 -> V_169 ;
struct V_99 * V_100 = V_168 -> V_107 ;
V_29 -> V_37 = V_100 -> V_103 ;
} else if ( strcmp ( V_41 , V_211 ) == 0 )
V_29 -> V_22 = NULL ;
else if ( strcmp ( V_41 , V_212 ) == 0 )
V_29 -> V_218 = NULL ;
else if ( strcmp ( V_41 , V_213 ) == 0 )
V_29 -> V_31 &= ~ V_164 ;
return 0 ;
}
static int F_96 ( struct V_27 * V_27 ,
const char * V_41 , void * * V_45 ,
bool V_219 )
{
struct V_220 * V_221 ;
struct V_222 * V_223 ;
struct V_97 * V_168 ;
struct V_27 * V_42 = (struct V_27 * ) V_27 ;
struct V_11 * V_29 ;
int V_224 ;
int V_14 = 0 ;
if ( strcmp ( V_41 , V_188 ) == 0 ) {
V_29 = F_11 ( V_27 ) ;
V_224 = strlen ( V_29 -> V_19 ) ;
* V_45 = V_29 -> V_19 ;
return V_224 ;
}
V_168 = V_42 -> V_33 ;
if ( V_168 -> V_159 != V_225 )
return - V_49 ;
V_223 = F_97 ( V_42 ) ;
if ( V_223 == NULL || V_223 -> V_226 == NULL )
return - V_49 ;
V_221 = V_223 -> V_226 -> V_227 ;
if ( strcmp ( V_41 , V_228 ) == 0 )
V_29 = V_221 -> V_229 ;
else if ( strcmp ( V_41 , V_230 ) == 0 )
V_29 = V_221 -> V_231 ;
else
return - V_49 ;
V_224 = strlen ( V_29 -> V_19 ) ;
if ( V_14 == 0 ) {
* V_45 = V_29 -> V_19 ;
V_14 = V_224 ;
}
return V_14 ;
}
static int F_98 ( struct V_27 * V_27 , char * V_45 ,
T_3 V_232 )
{
int V_184 = sizeof( V_208 ) ;
if ( V_45 != NULL && V_184 <= V_232 )
memcpy ( V_45 , V_208 , V_184 ) ;
return V_184 ;
}
static void F_99 ( struct V_27 * V_27 , T_4 * V_233 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
* V_233 = V_29 -> V_37 -> V_234 ;
}
static int F_100 ( struct V_38 * V_38 )
{
struct V_11 * V_46 = F_45 () ;
V_38 -> V_235 = V_46 ;
return 0 ;
}
static void F_101 ( struct V_38 * V_38 )
{
V_38 -> V_235 = NULL ;
}
static int F_102 ( struct V_38 * V_38 , unsigned int V_236 ,
unsigned long V_237 )
{
int V_14 = 0 ;
struct V_80 V_81 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_33 ( & V_81 , V_92 , V_203 ) ;
F_89 ( & V_81 , V_38 -> V_238 ) ;
if ( F_103 ( V_236 ) & V_239 ) {
V_14 = F_67 ( F_11 ( V_27 ) , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_103 ( V_236 ) & V_240 ) ) {
V_14 = F_67 ( F_11 ( V_27 ) , V_4 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_104 ( struct V_38 * V_38 , unsigned int V_236 )
{
struct V_80 V_81 ;
int V_14 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_33 ( & V_81 , V_92 , V_203 ) ;
F_89 ( & V_81 , V_38 -> V_238 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_9 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_105 ( struct V_38 * V_38 , unsigned int V_236 ,
unsigned long V_237 )
{
struct V_80 V_81 ;
int V_14 = 0 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
switch ( V_236 ) {
case V_241 :
break;
case V_242 :
case V_243 :
F_33 ( & V_81 , V_92 , V_203 ) ;
F_89 ( & V_81 , V_38 -> V_238 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_9 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
break;
case V_244 :
case V_245 :
F_33 ( & V_81 , V_92 , V_203 ) ;
F_89 ( & V_81 , V_38 -> V_238 ) ;
V_14 = F_67 ( F_11 ( V_27 ) , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_106 ( struct V_38 * V_38 ,
unsigned long V_246 , unsigned long V_247 ,
unsigned long V_165 )
{
struct V_11 * V_46 ;
struct V_11 * V_248 ;
struct V_66 * V_249 ;
struct V_20 * V_21 ;
struct V_11 * V_250 ;
struct V_28 * V_29 ;
struct V_99 * V_100 ;
int V_187 ;
int V_251 ;
int V_252 ;
int V_14 ;
if ( V_38 == NULL )
return 0 ;
V_29 = F_10 ( V_38 ) -> V_30 ;
if ( V_29 -> V_218 == NULL )
return 0 ;
V_100 = F_10 ( V_38 ) -> V_33 -> V_107 ;
if ( V_100 -> V_31 & V_163 &&
V_29 -> V_218 != V_100 -> V_101 )
return - V_89 ;
V_248 = V_29 -> V_218 ;
V_21 = F_5 () ;
V_46 = F_45 () ;
V_14 = 0 ;
F_35 () ;
F_25 (srp, &skp->smk_rules, list) {
V_250 = V_249 -> V_253 ;
if ( V_248 -> V_19 == V_250 -> V_19 )
continue;
V_187 = F_77 ( V_249 -> V_254 -> V_19 ,
V_250 -> V_19 ,
& V_21 -> V_60 ) ;
if ( V_187 == - V_255 )
V_187 = V_249 -> V_256 ;
else
V_187 &= V_249 -> V_256 ;
if ( V_187 == 0 )
continue;
V_251 = F_77 ( V_248 -> V_19 , V_250 -> V_19 ,
& V_248 -> V_60 ) ;
if ( V_251 == - V_255 ) {
V_14 = - V_89 ;
break;
}
V_252 = F_77 ( V_248 -> V_19 , V_250 -> V_19 ,
& V_21 -> V_60 ) ;
if ( V_252 != - V_255 )
V_251 &= V_252 ;
if ( ( V_187 | V_251 ) != V_251 ) {
V_14 = - V_89 ;
break;
}
}
F_40 () ;
return V_14 ;
}
static void F_107 ( struct V_38 * V_38 )
{
V_38 -> V_235 = F_45 () ;
}
static int F_108 ( struct V_25 * V_257 ,
struct V_258 * V_259 , int V_260 )
{
struct V_11 * V_46 ;
struct V_11 * V_261 = F_37 ( V_257 -> V_39 -> V_40 ) ;
struct V_38 * V_38 ;
int V_14 ;
struct V_80 V_81 ;
V_38 = F_109 ( V_259 , struct V_38 , V_262 ) ;
V_46 = V_38 -> V_235 ;
V_14 = V_256 ( V_46 , V_261 , V_263 , NULL ) ;
V_14 = F_2 ( L_11 , V_46 , V_261 , V_263 , V_14 ) ;
if ( V_14 != 0 && F_110 ( V_257 , V_95 ) )
V_14 = 0 ;
F_33 ( & V_81 , V_92 , V_85 ) ;
F_34 ( & V_81 , V_257 ) ;
F_39 ( V_46 -> V_19 , V_261 -> V_19 , V_263 , V_14 , & V_81 ) ;
return V_14 ;
}
static int F_111 ( struct V_38 * V_38 )
{
int V_14 ;
int V_187 = 0 ;
struct V_80 V_81 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_222 * V_223 ;
struct V_20 * V_21 ;
struct V_220 * V_221 ;
if ( F_112 ( F_113 ( V_27 ) ) )
return 0 ;
F_33 ( & V_81 , V_92 , V_203 ) ;
F_89 ( & V_81 , V_38 -> V_238 ) ;
if ( F_114 ( V_27 -> V_264 ) ) {
V_223 = F_97 ( V_27 ) ;
V_221 = V_223 -> V_226 -> V_227 ;
V_21 = F_5 () ;
V_14 = V_256 ( V_21 -> V_22 , V_221 -> V_231 , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_187 , V_14 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = V_256 ( V_221 -> V_229 , V_21 -> V_22 , V_5 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_187 , V_14 ) ;
return V_14 ;
}
if ( V_38 -> V_265 & V_266 )
V_187 = V_4 ;
if ( V_38 -> V_265 & V_267 )
V_187 |= V_5 ;
V_14 = F_67 ( F_11 ( V_27 ) , V_187 , & V_81 ) ;
V_14 = F_9 ( V_38 , V_187 , V_14 ) ;
return V_14 ;
}
static int F_115 ( struct V_38 * V_38 , const struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_80 V_81 ;
int V_14 ;
if ( F_46 ( V_95 ) )
return 0 ;
F_33 ( & V_81 , V_92 , V_203 ) ;
F_89 ( & V_81 , V_38 -> V_238 ) ;
V_14 = V_256 ( V_21 -> V_22 , F_11 ( V_27 ) , V_4 , & V_81 ) ;
V_14 = F_12 ( V_39 , V_38 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_116 ( struct V_39 * V_39 , T_1 V_58 )
{
struct V_20 * V_21 ;
V_21 = F_22 ( NULL , NULL , V_58 ) ;
if ( V_21 == NULL )
return - V_52 ;
V_39 -> V_40 = V_21 ;
return 0 ;
}
static void F_117 ( struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_66 * V_268 ;
struct V_63 * V_269 ;
struct V_63 * V_270 ;
if ( V_21 == NULL )
return;
V_39 -> V_40 = NULL ;
F_29 ( & V_21 -> V_61 ) ;
F_118 (l, n, &tsp->smk_rules) {
V_268 = F_119 ( V_269 , struct V_66 , V_69 ) ;
F_120 ( & V_268 -> V_69 ) ;
F_18 ( V_268 ) ;
}
F_18 ( V_21 ) ;
}
static int F_121 ( struct V_39 * V_271 , const struct V_39 * V_272 ,
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
static void F_122 ( struct V_39 * V_271 , const struct V_39 * V_272 )
{
struct V_20 * V_273 = V_272 -> V_40 ;
struct V_20 * V_274 = V_271 -> V_40 ;
V_274 -> V_22 = V_273 -> V_22 ;
V_274 -> V_59 = V_273 -> V_22 ;
F_21 ( & V_274 -> V_62 ) ;
F_23 ( & V_274 -> V_60 ) ;
}
static int F_123 ( struct V_39 * V_271 , T_4 V_233 )
{
struct V_20 * V_274 = V_271 -> V_40 ;
V_274 -> V_22 = F_124 ( V_233 ) ;
return 0 ;
}
static int F_125 ( struct V_39 * V_271 ,
struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_20 * V_21 = V_271 -> V_40 ;
V_21 -> V_59 = V_29 -> V_37 ;
V_21 -> V_22 = V_21 -> V_59 ;
return 0 ;
}
static int F_126 ( struct V_25 * V_121 , int V_275 ,
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
static int F_127 ( struct V_25 * V_121 , T_5 V_277 )
{
return F_126 ( V_121 , V_5 , V_92 ) ;
}
static int F_128 ( struct V_25 * V_121 )
{
return F_126 ( V_121 , V_4 , V_92 ) ;
}
static int F_129 ( struct V_25 * V_121 )
{
return F_126 ( V_121 , V_4 , V_92 ) ;
}
static void F_130 ( struct V_25 * V_121 , T_4 * V_233 )
{
struct V_11 * V_46 = F_7 ( V_121 ) ;
* V_233 = V_46 -> V_234 ;
}
static int F_131 ( struct V_25 * V_121 , int V_278 )
{
return F_126 ( V_121 , V_5 , V_92 ) ;
}
static int F_132 ( struct V_25 * V_121 , int V_279 )
{
return F_126 ( V_121 , V_5 , V_92 ) ;
}
static int F_133 ( struct V_25 * V_121 )
{
return F_126 ( V_121 , V_4 , V_92 ) ;
}
static int F_134 ( struct V_25 * V_121 )
{
return F_126 ( V_121 , V_5 , V_92 ) ;
}
static int F_135 ( struct V_25 * V_121 )
{
return F_126 ( V_121 , V_4 , V_92 ) ;
}
static int F_136 ( struct V_25 * V_121 )
{
return F_126 ( V_121 , V_5 , V_92 ) ;
}
static int F_137 ( struct V_25 * V_121 , struct V_280 * V_281 ,
int V_282 , T_4 V_233 )
{
struct V_80 V_81 ;
struct V_11 * V_46 ;
struct V_11 * V_261 = F_7 ( V_121 ) ;
int V_14 ;
if ( ! V_282 )
return 0 ;
F_33 ( & V_81 , V_92 , V_85 ) ;
F_34 ( & V_81 , V_121 ) ;
if ( V_233 == 0 ) {
V_14 = F_67 ( V_261 , V_263 , & V_81 ) ;
V_14 = F_6 ( V_121 , V_263 , V_14 ) ;
return V_14 ;
}
V_46 = F_124 ( V_233 ) ;
V_14 = V_256 ( V_46 , V_261 , V_263 , & V_81 ) ;
V_14 = F_2 ( L_12 , V_46 , V_261 , V_263 , V_14 ) ;
return V_14 ;
}
static int F_138 ( struct V_25 * V_121 )
{
return 0 ;
}
static void F_139 ( struct V_25 * V_121 , struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_11 * V_46 = F_7 ( V_121 ) ;
V_29 -> V_37 = V_46 ;
}
static int F_140 ( struct V_223 * V_226 , int V_283 , T_1 V_284 )
{
struct V_11 * V_46 = F_45 () ;
struct V_220 * V_221 ;
V_221 = F_15 ( sizeof( struct V_220 ) , V_284 ) ;
if ( V_221 == NULL )
return - V_52 ;
if ( F_112 ( V_23 -> V_165 & V_285 ) ) {
V_221 -> V_229 = & V_217 ;
V_221 -> V_231 = & V_217 ;
} else {
V_221 -> V_229 = V_46 ;
V_221 -> V_231 = V_46 ;
}
V_221 -> V_286 = NULL ;
V_226 -> V_227 = V_221 ;
return 0 ;
}
static void F_141 ( struct V_223 * V_226 )
{
F_18 ( V_226 -> V_227 ) ;
}
static struct V_11 * F_142 ( struct V_287 * V_288 )
{
struct V_289 * V_290 ;
struct V_291 * V_292 = & V_288 -> V_293 ;
if ( V_292 -> V_294 == 0 )
return NULL ;
F_25 (snp, &smk_net4addr_list, list)
if ( V_290 -> V_295 . V_294 ==
( V_292 -> V_294 & V_290 -> V_296 . V_294 ) )
return V_290 -> V_73 ;
return NULL ;
}
static bool F_143 ( struct V_297 * V_288 )
{
T_6 * V_298 = ( T_6 * ) & V_288 -> V_299 ;
T_7 * V_300 = ( T_7 * ) & V_288 -> V_299 ;
if ( V_300 [ 0 ] == 0 && V_300 [ 1 ] == 0 && V_300 [ 2 ] == 0 && V_298 [ 6 ] == 0 &&
F_144 ( V_298 [ 7 ] ) == 1 )
return true ;
return false ;
}
static struct V_11 * F_145 ( struct V_297 * V_288 )
{
struct V_301 * V_290 ;
struct V_302 * V_303 = & V_288 -> V_299 ;
int V_3 ;
int V_304 = 0 ;
if ( F_143 ( V_288 ) )
return NULL ;
F_25 (snp, &smk_net6addr_list, list) {
if ( V_290 -> V_73 == NULL )
continue;
for ( V_304 = 1 , V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( ( V_303 -> V_305 [ V_3 ] & V_290 -> V_296 . V_305 [ V_3 ] ) !=
V_290 -> V_295 . V_305 [ V_3 ] ) {
V_304 = 0 ;
break;
}
}
if ( V_304 )
return V_290 -> V_73 ;
}
return NULL ;
}
static int F_146 ( struct V_223 * V_226 , int V_306 )
{
struct V_11 * V_46 ;
struct V_220 * V_221 = V_226 -> V_227 ;
int V_14 = 0 ;
F_147 () ;
F_148 ( V_226 ) ;
if ( V_221 -> V_231 == V_307 ||
V_306 == V_308 )
F_149 ( V_226 ) ;
else {
V_46 = V_221 -> V_231 ;
V_14 = F_150 ( V_226 , V_226 -> V_309 , & V_46 -> V_310 ) ;
}
F_151 ( V_226 ) ;
F_152 () ;
return V_14 ;
}
static int F_153 ( struct V_223 * V_226 , struct V_287 * V_303 )
{
struct V_11 * V_46 ;
int V_14 ;
int V_311 ;
struct V_11 * V_312 ;
struct V_220 * V_221 = V_226 -> V_227 ;
struct V_80 V_81 ;
F_35 () ;
V_312 = F_142 ( V_303 ) ;
if ( V_312 != NULL ) {
#ifdef F_154
struct V_313 V_314 ;
F_155 ( & V_81 , V_92 , V_315 , & V_314 ) ;
V_81 . V_316 . V_317 . V_314 -> V_283 = V_303 -> V_318 ;
V_81 . V_316 . V_317 . V_314 -> V_319 = V_303 -> V_320 ;
V_81 . V_316 . V_317 . V_314 -> V_321 . V_322 = V_303 -> V_293 . V_294 ;
#endif
V_311 = V_308 ;
V_46 = V_221 -> V_231 ;
V_14 = V_256 ( V_46 , V_312 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_13 , V_46 , V_312 , V_5 , V_14 ) ;
} else {
V_311 = V_323 ;
V_14 = 0 ;
}
F_40 () ;
if ( V_14 != 0 )
return V_14 ;
return F_146 ( V_226 , V_311 ) ;
}
static int F_156 ( struct V_11 * V_324 ,
struct V_11 * V_325 ,
struct V_297 * V_326 , int V_327 )
{
#ifdef F_154
struct V_313 V_314 ;
#endif
struct V_80 V_81 ;
int V_14 ;
#ifdef F_154
F_155 ( & V_81 , V_92 , V_315 , & V_314 ) ;
V_81 . V_316 . V_317 . V_314 -> V_283 = V_328 ;
V_81 . V_316 . V_317 . V_314 -> V_319 = F_144 ( V_326 -> V_329 ) ;
if ( V_327 == V_330 )
V_81 . V_316 . V_317 . V_314 -> V_331 . V_332 = V_326 -> V_299 ;
else
V_81 . V_316 . V_317 . V_314 -> V_331 . V_322 = V_326 -> V_299 ;
#endif
V_14 = V_256 ( V_324 , V_325 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_14 , V_324 , V_325 , V_5 , V_14 ) ;
return V_14 ;
}
static void F_157 ( struct V_222 * V_223 , struct V_333 * V_326 )
{
struct V_223 * V_226 = V_223 -> V_226 ;
struct V_297 * V_334 ;
struct V_220 * V_221 = V_223 -> V_226 -> V_227 ;
struct V_335 * V_336 ;
unsigned short V_337 = 0 ;
if ( V_326 == NULL ) {
F_28 (spp, &smk_ipv6_port_list, list) {
if ( V_226 != V_336 -> V_338 )
continue;
V_336 -> V_229 = V_221 -> V_229 ;
V_336 -> V_231 = V_221 -> V_231 ;
return;
}
return;
}
V_334 = (struct V_297 * ) V_326 ;
V_337 = F_144 ( V_334 -> V_329 ) ;
if ( V_337 == 0 )
return;
F_28 (spp, &smk_ipv6_port_list, list) {
if ( V_336 -> V_339 != V_337 )
continue;
V_336 -> V_339 = V_337 ;
V_336 -> V_338 = V_226 ;
V_336 -> V_229 = V_221 -> V_229 ;
V_336 -> V_231 = V_221 -> V_231 ;
return;
}
V_336 = F_15 ( sizeof( * V_336 ) , V_51 ) ;
if ( V_336 == NULL )
return;
V_336 -> V_339 = V_337 ;
V_336 -> V_338 = V_226 ;
V_336 -> V_229 = V_221 -> V_229 ;
V_336 -> V_231 = V_221 -> V_231 ;
F_30 ( & V_336 -> V_69 , & V_340 ) ;
return;
}
static int F_158 ( struct V_223 * V_226 , struct V_297 * V_326 ,
int V_327 )
{
struct V_335 * V_336 ;
struct V_220 * V_221 = V_226 -> V_227 ;
struct V_11 * V_46 = NULL ;
unsigned short V_337 ;
struct V_11 * V_325 ;
if ( V_327 == V_330 ) {
V_46 = F_145 ( V_326 ) ;
V_325 = V_221 -> V_229 ;
} else {
V_46 = V_221 -> V_231 ;
V_325 = F_145 ( V_326 ) ;
}
if ( V_46 != NULL && V_325 != NULL )
return F_156 ( V_46 , V_325 , V_326 , V_327 ) ;
if ( V_46 == NULL )
V_46 = V_307 ;
if ( V_325 == NULL )
V_325 = V_307 ;
if ( ! F_143 ( V_326 ) )
return F_156 ( V_46 , V_325 , V_326 , V_327 ) ;
if ( V_327 == V_330 )
return 0 ;
V_337 = F_144 ( V_326 -> V_329 ) ;
F_28 (spp, &smk_ipv6_port_list, list) {
if ( V_336 -> V_339 != V_337 )
continue;
V_325 = V_336 -> V_229 ;
if ( V_327 == V_341 )
V_221 -> V_286 = V_336 -> V_231 ;
break;
}
return F_156 ( V_46 , V_325 , V_326 , V_327 ) ;
}
static int F_159 ( struct V_27 * V_27 , const char * V_41 ,
const void * V_183 , T_3 V_204 , int V_165 )
{
struct V_11 * V_46 ;
struct V_28 * V_342 = V_27 -> V_30 ;
struct V_220 * V_221 ;
struct V_222 * V_223 ;
int V_14 = 0 ;
if ( V_183 == NULL || V_204 > V_50 || V_204 == 0 )
return - V_138 ;
V_46 = F_17 ( V_183 , V_204 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
if ( strcmp ( V_41 , V_188 ) == 0 ) {
V_342 -> V_37 = V_46 ;
V_342 -> V_31 |= V_343 ;
return 0 ;
}
if ( V_27 -> V_33 -> V_159 != V_225 )
return - V_49 ;
V_223 = F_97 ( V_27 ) ;
if ( V_223 == NULL || V_223 -> V_226 == NULL )
return - V_49 ;
V_221 = V_223 -> V_226 -> V_227 ;
if ( strcmp ( V_41 , V_228 ) == 0 )
V_221 -> V_229 = V_46 ;
else if ( strcmp ( V_41 , V_230 ) == 0 ) {
V_221 -> V_231 = V_46 ;
if ( V_223 -> V_226 -> V_309 == V_344 ) {
V_14 = F_146 ( V_223 -> V_226 , V_323 ) ;
if ( V_14 != 0 )
F_160 ( V_345
L_15 ,
V_92 , - V_14 ) ;
}
} else
return - V_49 ;
#ifdef F_161
if ( V_223 -> V_226 -> V_309 == V_328 )
F_157 ( V_223 , NULL ) ;
#endif
return 0 ;
}
static int F_162 ( struct V_222 * V_223 , int V_283 ,
int type , int V_346 , int V_347 )
{
struct V_220 * V_221 ;
if ( V_223 -> V_226 == NULL )
return 0 ;
if ( F_112 ( V_23 -> V_165 & V_285 ) ) {
V_221 = V_223 -> V_226 -> V_227 ;
V_221 -> V_229 = & V_217 ;
V_221 -> V_231 = & V_217 ;
}
if ( V_283 != V_344 )
return 0 ;
return F_146 ( V_223 -> V_226 , V_323 ) ;
}
static int F_163 ( struct V_222 * V_223 , struct V_333 * V_326 ,
int V_348 )
{
if ( V_223 -> V_226 != NULL && V_223 -> V_226 -> V_309 == V_328 )
F_157 ( V_223 , V_326 ) ;
return 0 ;
}
static int F_164 ( struct V_222 * V_223 , struct V_333 * V_303 ,
int V_348 )
{
int V_14 = 0 ;
#if F_165 ( V_349 )
struct V_297 * V_288 = (struct V_297 * ) V_303 ;
#endif
#ifdef F_166
struct V_11 * V_350 ;
struct V_220 * V_221 = V_223 -> V_226 -> V_227 ;
#endif
if ( V_223 -> V_226 == NULL )
return 0 ;
switch ( V_223 -> V_226 -> V_309 ) {
case V_344 :
if ( V_348 < sizeof( struct V_287 ) )
return - V_138 ;
V_14 = F_153 ( V_223 -> V_226 , (struct V_287 * ) V_303 ) ;
break;
case V_328 :
if ( V_348 < sizeof( struct V_297 ) )
return - V_138 ;
#ifdef F_166
V_350 = F_145 ( V_288 ) ;
if ( V_350 != NULL )
V_14 = F_156 ( V_221 -> V_231 , V_350 , V_288 ,
V_341 ) ;
#endif
#ifdef F_161
V_14 = F_158 ( V_223 -> V_226 , V_288 , V_341 ) ;
#endif
break;
}
return V_14 ;
}
static int F_167 ( int V_165 )
{
int V_187 = 0 ;
if ( V_165 & V_351 )
V_187 |= V_4 ;
if ( V_165 & V_352 )
V_187 |= V_5 ;
if ( V_165 & V_353 )
V_187 |= V_6 ;
return V_187 ;
}
static int F_168 ( struct V_354 * V_355 )
{
struct V_11 * V_46 = F_45 () ;
V_355 -> V_40 = V_46 ;
return 0 ;
}
static void F_169 ( struct V_354 * V_355 )
{
V_355 -> V_40 = NULL ;
}
static struct V_11 * F_170 ( struct V_356 * V_357 )
{
return (struct V_11 * ) V_357 -> V_358 . V_40 ;
}
static int F_171 ( struct V_356 * V_357 )
{
struct V_359 * V_29 = & V_357 -> V_358 ;
struct V_11 * V_46 = F_45 () ;
V_29 -> V_40 = V_46 ;
return 0 ;
}
static void F_172 ( struct V_356 * V_357 )
{
struct V_359 * V_29 = & V_357 -> V_358 ;
V_29 -> V_40 = NULL ;
}
static int F_173 ( struct V_356 * V_357 , int V_275 )
{
struct V_11 * V_221 = F_170 ( V_357 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_154
F_33 ( & V_81 , V_92 , V_360 ) ;
V_81 . V_316 . V_317 . V_361 = V_357 -> V_358 . V_362 ;
#endif
V_14 = F_67 ( V_221 , V_275 , & V_81 ) ;
V_14 = F_4 ( L_16 , V_221 , V_275 , V_14 ) ;
return V_14 ;
}
static int F_174 ( struct V_356 * V_357 , int V_363 )
{
int V_187 ;
V_187 = F_167 ( V_363 ) ;
return F_173 ( V_357 , V_187 ) ;
}
static int F_175 ( struct V_356 * V_357 , int V_236 )
{
int V_187 ;
switch ( V_236 ) {
case V_364 :
case V_365 :
V_187 = V_4 ;
break;
case V_366 :
case V_367 :
case V_368 :
case V_369 :
V_187 = V_75 ;
break;
case V_370 :
case V_371 :
return 0 ;
default:
return - V_138 ;
}
return F_173 ( V_357 , V_187 ) ;
}
static int F_176 ( struct V_356 * V_357 , char T_8 * V_372 ,
int V_363 )
{
int V_187 ;
V_187 = F_167 ( V_363 ) ;
return F_173 ( V_357 , V_187 ) ;
}
static struct V_11 * F_177 ( struct V_373 * V_374 )
{
return (struct V_11 * ) V_374 -> V_375 . V_40 ;
}
static int F_178 ( struct V_373 * V_374 )
{
struct V_359 * V_29 = & V_374 -> V_375 ;
struct V_11 * V_46 = F_45 () ;
V_29 -> V_40 = V_46 ;
return 0 ;
}
static void F_179 ( struct V_373 * V_374 )
{
struct V_359 * V_29 = & V_374 -> V_375 ;
V_29 -> V_40 = NULL ;
}
static int F_180 ( struct V_373 * V_374 , int V_275 )
{
struct V_11 * V_221 = F_177 ( V_374 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_154
F_33 ( & V_81 , V_92 , V_360 ) ;
V_81 . V_316 . V_317 . V_361 = V_374 -> V_375 . V_362 ;
#endif
V_14 = F_67 ( V_221 , V_275 , & V_81 ) ;
V_14 = F_4 ( L_17 , V_221 , V_275 , V_14 ) ;
return V_14 ;
}
static int F_181 ( struct V_373 * V_374 , int V_376 )
{
int V_187 ;
V_187 = F_167 ( V_376 ) ;
return F_180 ( V_374 , V_187 ) ;
}
static int F_182 ( struct V_373 * V_374 , int V_236 )
{
int V_187 ;
switch ( V_236 ) {
case V_377 :
case V_378 :
case V_379 :
case V_380 :
case V_381 :
case V_364 :
case V_382 :
V_187 = V_4 ;
break;
case V_383 :
case V_384 :
case V_369 :
case V_366 :
V_187 = V_75 ;
break;
case V_370 :
case V_385 :
return 0 ;
default:
return - V_138 ;
}
return F_180 ( V_374 , V_187 ) ;
}
static int F_183 ( struct V_373 * V_374 , struct V_386 * V_387 ,
unsigned V_388 , int V_389 )
{
return F_180 ( V_374 , V_75 ) ;
}
static int F_184 ( struct V_390 * V_391 )
{
struct V_359 * V_392 = & V_391 -> V_393 ;
struct V_11 * V_46 = F_45 () ;
V_392 -> V_40 = V_46 ;
return 0 ;
}
static void F_185 ( struct V_390 * V_391 )
{
struct V_359 * V_392 = & V_391 -> V_393 ;
V_392 -> V_40 = NULL ;
}
static struct V_11 * F_186 ( struct V_390 * V_391 )
{
return (struct V_11 * ) V_391 -> V_393 . V_40 ;
}
static int F_187 ( struct V_390 * V_391 , int V_275 )
{
struct V_11 * V_394 = F_186 ( V_391 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_154
F_33 ( & V_81 , V_92 , V_360 ) ;
V_81 . V_316 . V_317 . V_361 = V_391 -> V_393 . V_362 ;
#endif
V_14 = F_67 ( V_394 , V_275 , & V_81 ) ;
V_14 = F_4 ( L_18 , V_394 , V_275 , V_14 ) ;
return V_14 ;
}
static int F_188 ( struct V_390 * V_391 , int V_395 )
{
int V_187 ;
V_187 = F_167 ( V_395 ) ;
return F_187 ( V_391 , V_187 ) ;
}
static int F_189 ( struct V_390 * V_391 , int V_236 )
{
int V_187 ;
switch ( V_236 ) {
case V_364 :
case V_396 :
V_187 = V_4 ;
break;
case V_366 :
case V_369 :
V_187 = V_75 ;
break;
case V_370 :
case V_397 :
return 0 ;
default:
return - V_138 ;
}
return F_187 ( V_391 , V_187 ) ;
}
static int F_190 ( struct V_390 * V_391 , struct V_354 * V_355 ,
int V_395 )
{
int V_187 ;
V_187 = F_167 ( V_395 ) ;
return F_187 ( V_391 , V_187 ) ;
}
static int F_191 ( struct V_390 * V_391 , struct V_354 * V_355 ,
struct V_25 * V_398 , long type , int V_1 )
{
return F_187 ( V_391 , V_75 ) ;
}
static int F_192 ( struct V_359 * V_399 , short V_400 )
{
struct V_11 * V_401 = V_399 -> V_40 ;
int V_187 = F_167 ( V_400 ) ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_154
F_33 ( & V_81 , V_92 , V_360 ) ;
V_81 . V_316 . V_317 . V_361 = V_399 -> V_362 ;
#endif
V_14 = F_67 ( V_401 , V_187 , & V_81 ) ;
V_14 = F_4 ( L_19 , V_401 , V_187 , V_14 ) ;
return V_14 ;
}
static void F_193 ( struct V_359 * V_399 , T_4 * V_233 )
{
struct V_11 * V_401 = V_399 -> V_40 ;
* V_233 = V_401 -> V_234 ;
}
static void F_194 ( struct V_43 * V_402 , struct V_27 * V_27 )
{
struct V_97 * V_168 ;
struct V_99 * V_100 ;
struct V_28 * V_29 ;
struct V_11 * V_46 ;
struct V_11 * V_403 = F_45 () ;
struct V_11 * V_404 ;
char V_405 [ V_214 ] ;
int V_406 = 0 ;
int V_14 ;
struct V_43 * V_44 ;
if ( V_27 == NULL )
return;
V_29 = V_27 -> V_30 ;
F_195 ( & V_29 -> V_55 ) ;
if ( V_29 -> V_31 & V_343 )
goto V_407;
V_168 = V_27 -> V_33 ;
V_100 = V_168 -> V_107 ;
V_404 = V_100 -> V_103 ;
if ( V_402 -> V_408 == V_402 ) {
switch ( V_168 -> V_159 ) {
case V_409 :
V_100 -> V_101 = & V_216 ;
V_100 -> V_103 = & V_216 ;
V_29 -> V_37 = V_100 -> V_101 ;
break;
case V_161 :
V_29 -> V_37 = F_45 () ;
break;
case V_410 :
V_29 -> V_37 = F_45 () ;
break;
default:
V_29 -> V_37 = V_100 -> V_101 ;
break;
}
V_29 -> V_31 |= V_343 ;
goto V_407;
}
switch ( V_168 -> V_159 ) {
case V_411 :
case V_410 :
case V_225 :
case V_409 :
V_404 = & V_216 ;
break;
case V_412 :
V_404 = V_403 ;
break;
case V_413 :
break;
case V_161 :
V_404 = & V_216 ;
default:
if ( F_114 ( V_27 -> V_264 ) ) {
V_404 = & V_216 ;
break;
}
if ( ! ( V_27 -> V_47 & V_48 ) )
break;
V_44 = F_196 ( V_402 ) ;
V_46 = F_13 ( V_208 , V_27 , V_44 ) ;
if ( ! F_197 ( V_46 ) )
V_404 = V_46 ;
if ( F_198 ( V_27 -> V_264 ) ) {
if ( V_29 -> V_31 & V_189 ) {
V_29 -> V_31 &= ~ V_189 ;
V_14 = F_199 ( V_44 , V_27 ,
V_213 ,
V_215 , V_214 ,
0 ) ;
} else {
V_14 = F_16 ( V_44 , V_27 ,
V_213 , V_405 ,
V_214 ) ;
if ( V_14 >= 0 && strncmp ( V_405 , V_215 ,
V_214 ) != 0 )
V_14 = - V_138 ;
}
if ( V_14 >= 0 )
V_406 = V_164 ;
}
V_46 = F_13 ( V_211 , V_27 , V_44 ) ;
if ( F_60 ( V_46 ) || V_46 == & V_216 ||
V_46 == & V_217 )
V_46 = NULL ;
V_29 -> V_22 = V_46 ;
V_46 = F_13 ( V_212 , V_27 , V_44 ) ;
if ( F_60 ( V_46 ) || V_46 == & V_216 ||
V_46 == & V_217 )
V_46 = NULL ;
V_29 -> V_218 = V_46 ;
F_200 ( V_44 ) ;
break;
}
if ( V_404 == NULL )
V_29 -> V_37 = V_403 ;
else
V_29 -> V_37 = V_404 ;
V_29 -> V_31 |= ( V_343 | V_406 ) ;
V_407:
F_201 ( & V_29 -> V_55 ) ;
return;
}
static int F_202 ( struct V_25 * V_121 , char * V_41 , char * * V_183 )
{
struct V_11 * V_46 = F_7 ( V_121 ) ;
char * V_110 ;
int V_414 ;
if ( strcmp ( V_41 , L_20 ) != 0 )
return - V_138 ;
V_110 = F_79 ( V_46 -> V_19 , V_51 ) ;
if ( V_110 == NULL )
return - V_52 ;
V_414 = strlen ( V_110 ) ;
* V_183 = V_110 ;
return V_414 ;
}
static int F_203 ( struct V_25 * V_121 , char * V_41 ,
void * V_183 , T_3 V_204 )
{
struct V_20 * V_21 = F_5 () ;
struct V_39 * V_271 ;
struct V_11 * V_46 ;
struct V_70 * V_415 ;
int V_14 ;
if ( V_121 != V_23 )
return - V_156 ;
if ( ! F_46 ( V_155 ) && F_204 ( & V_21 -> V_61 ) )
return - V_156 ;
if ( V_183 == NULL || V_204 == 0 || V_204 >= V_50 )
return - V_138 ;
if ( strcmp ( V_41 , L_20 ) != 0 )
return - V_138 ;
V_46 = F_17 ( V_183 , V_204 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
if ( V_46 == & V_217 || V_46 == & V_216 )
return - V_138 ;
if ( ! F_46 ( V_155 ) ) {
V_14 = - V_156 ;
F_28 (sklep, &tsp->smk_relabel, list)
if ( V_415 -> V_73 == V_46 ) {
V_14 = 0 ;
break;
}
if ( V_14 )
return V_14 ;
}
V_271 = F_205 () ;
if ( V_271 == NULL )
return - V_52 ;
V_21 = V_271 -> V_40 ;
V_21 -> V_22 = V_46 ;
F_29 ( & V_21 -> V_61 ) ;
F_206 ( V_271 ) ;
return V_204 ;
}
static int F_207 ( struct V_223 * V_223 ,
struct V_223 * V_416 , struct V_223 * V_417 )
{
struct V_11 * V_46 ;
struct V_11 * V_250 ;
struct V_220 * V_221 = V_223 -> V_227 ;
struct V_220 * V_418 = V_416 -> V_227 ;
struct V_220 * V_342 = V_417 -> V_227 ;
struct V_80 V_81 ;
int V_14 = 0 ;
#ifdef F_154
struct V_313 V_314 ;
#endif
if ( ! F_46 ( V_95 ) ) {
V_46 = V_221 -> V_231 ;
V_250 = V_418 -> V_229 ;
#ifdef F_154
F_155 ( & V_81 , V_92 , V_315 , & V_314 ) ;
F_208 ( & V_81 , V_416 ) ;
#endif
V_14 = V_256 ( V_46 , V_250 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_21 , V_46 , V_250 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_250 = V_418 -> V_231 ;
V_46 = V_221 -> V_229 ;
V_14 = V_256 ( V_250 , V_46 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_21 , V_250 , V_46 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_342 -> V_286 = V_221 -> V_231 ;
V_221 -> V_286 = V_418 -> V_231 ;
}
return V_14 ;
}
static int F_209 ( struct V_222 * V_223 , struct V_222 * V_416 )
{
struct V_220 * V_221 = V_223 -> V_226 -> V_227 ;
struct V_220 * V_418 = V_416 -> V_226 -> V_227 ;
struct V_80 V_81 ;
int V_14 ;
#ifdef F_154
struct V_313 V_314 ;
F_155 ( & V_81 , V_92 , V_315 , & V_314 ) ;
F_208 ( & V_81 , V_416 -> V_226 ) ;
#endif
if ( F_46 ( V_95 ) )
return 0 ;
V_14 = V_256 ( V_221 -> V_231 , V_418 -> V_229 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_22 , V_221 -> V_231 , V_418 -> V_229 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_210 ( struct V_222 * V_223 , struct V_419 * V_355 ,
int V_204 )
{
struct V_287 * V_288 = (struct V_287 * ) V_355 -> V_420 ;
#if F_165 ( V_349 )
struct V_297 * V_303 = (struct V_297 * ) V_355 -> V_420 ;
#endif
#ifdef F_166
struct V_220 * V_221 = V_223 -> V_226 -> V_227 ;
struct V_11 * V_350 ;
#endif
int V_14 = 0 ;
if ( V_288 == NULL )
return 0 ;
switch ( V_223 -> V_226 -> V_309 ) {
case V_421 :
V_14 = F_153 ( V_223 -> V_226 , V_288 ) ;
break;
case V_422 :
#ifdef F_166
V_350 = F_145 ( V_303 ) ;
if ( V_350 != NULL )
V_14 = F_156 ( V_221 -> V_231 , V_350 , V_303 ,
V_341 ) ;
#endif
#ifdef F_161
V_14 = F_158 ( V_223 -> V_226 , V_303 , V_423 ) ;
#endif
break;
}
return V_14 ;
}
static struct V_11 * F_211 ( struct V_424 * V_303 ,
struct V_220 * V_221 )
{
struct V_11 * V_46 ;
int V_304 = 0 ;
int V_425 ;
int V_426 ;
if ( ( V_303 -> V_165 & V_427 ) != 0 ) {
F_35 () ;
F_28 (skp, &smack_known_list, list) {
if ( V_303 -> V_428 . V_429 . V_430 != V_46 -> V_310 . V_428 . V_429 . V_430 )
continue;
if ( ( V_303 -> V_165 & V_431 ) == 0 ) {
if ( ( V_46 -> V_310 . V_165 &
V_431 ) == 0 )
V_304 = 1 ;
break;
}
for ( V_425 = - 1 , V_426 = - 1 ; V_425 == V_426 ; ) {
V_425 = F_212 ( V_303 -> V_428 . V_429 . V_432 ,
V_425 + 1 ) ;
V_426 = F_212 (
V_46 -> V_310 . V_428 . V_429 . V_432 ,
V_426 + 1 ) ;
if ( V_425 < 0 || V_426 < 0 )
break;
}
if ( V_425 == V_426 ) {
V_304 = 1 ;
break;
}
}
F_40 () ;
if ( V_304 )
return V_46 ;
if ( V_221 != NULL && V_221 -> V_229 == & V_216 )
return & V_217 ;
return & V_216 ;
}
if ( ( V_303 -> V_165 & V_433 ) != 0 )
return F_124 ( V_303 -> V_428 . V_233 ) ;
return V_307 ;
}
static int F_213 ( struct V_434 * V_435 , struct V_297 * V_288 )
{
T_9 V_436 ;
int V_437 ;
int V_438 = - V_138 ;
struct V_439 V_440 ;
struct V_439 * V_441 ;
T_6 V_442 ;
struct V_443 V_444 , * V_445 ;
struct V_446 V_447 , * V_448 ;
struct V_449 V_450 , * V_451 ;
V_288 -> V_329 = 0 ;
V_437 = F_214 ( V_435 ) ;
V_441 = F_215 ( V_435 , V_437 , sizeof( V_440 ) , & V_440 ) ;
if ( V_441 == NULL )
return - V_138 ;
V_288 -> V_299 = V_441 -> V_332 ;
V_436 = V_441 -> V_436 ;
V_437 += sizeof( V_440 ) ;
V_437 = F_216 ( V_435 , V_437 , & V_436 , & V_442 ) ;
if ( V_437 < 0 )
return - V_138 ;
V_438 = V_436 ;
switch ( V_438 ) {
case V_452 :
V_445 = F_215 ( V_435 , V_437 , sizeof( V_444 ) , & V_444 ) ;
if ( V_445 != NULL )
V_288 -> V_329 = V_445 -> V_453 ;
break;
case V_454 :
V_448 = F_215 ( V_435 , V_437 , sizeof( V_447 ) , & V_447 ) ;
if ( V_448 != NULL )
V_288 -> V_329 = V_448 -> V_453 ;
break;
case V_455 :
V_451 = F_215 ( V_435 , V_437 , sizeof( V_450 ) , & V_450 ) ;
if ( V_451 != NULL )
V_288 -> V_329 = V_451 -> V_456 ;
break;
}
return V_438 ;
}
static int F_217 ( struct V_223 * V_226 , struct V_434 * V_435 )
{
struct V_424 V_457 ;
struct V_220 * V_221 = V_226 -> V_227 ;
struct V_11 * V_46 = NULL ;
int V_14 = 0 ;
struct V_80 V_81 ;
#ifdef F_154
struct V_313 V_314 ;
#endif
#if F_165 ( V_349 )
struct V_297 V_458 ;
int V_438 ;
#endif
switch ( V_226 -> V_309 ) {
case V_344 :
#ifdef F_218
if ( V_435 && V_435 -> V_459 != 0 ) {
V_46 = F_124 ( V_435 -> V_459 ) ;
goto V_460;
}
#endif
F_219 ( & V_457 ) ;
V_14 = F_220 ( V_435 , V_226 -> V_309 , & V_457 ) ;
if ( V_14 == 0 )
V_46 = F_211 ( & V_457 , V_221 ) ;
else
V_46 = V_307 ;
F_221 ( & V_457 ) ;
#ifdef F_218
V_460:
#endif
#ifdef F_154
F_155 ( & V_81 , V_92 , V_315 , & V_314 ) ;
V_81 . V_316 . V_317 . V_314 -> V_283 = V_226 -> V_309 ;
V_81 . V_316 . V_317 . V_314 -> V_461 = V_435 -> V_462 ;
F_222 ( V_435 , & V_81 . V_316 , NULL ) ;
#endif
V_14 = V_256 ( V_46 , V_221 -> V_229 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_23 , V_46 , V_221 -> V_229 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_223 ( V_435 , V_226 -> V_309 , V_14 , 0 ) ;
break;
#if F_165 ( V_349 )
case V_328 :
V_438 = F_213 ( V_435 , & V_458 ) ;
if ( V_438 != V_454 && V_438 != V_452 )
break;
#ifdef F_166
if ( V_435 && V_435 -> V_459 != 0 )
V_46 = F_124 ( V_435 -> V_459 ) ;
else
V_46 = F_145 ( & V_458 ) ;
if ( V_46 == NULL )
V_46 = V_307 ;
#ifdef F_154
F_155 ( & V_81 , V_92 , V_315 , & V_314 ) ;
V_81 . V_316 . V_317 . V_314 -> V_283 = V_226 -> V_309 ;
V_81 . V_316 . V_317 . V_314 -> V_461 = V_435 -> V_462 ;
F_224 ( V_435 , & V_81 . V_316 , NULL ) ;
#endif
V_14 = V_256 ( V_46 , V_221 -> V_229 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_24 , V_46 , V_221 -> V_229 ,
V_5 , V_14 ) ;
#endif
#ifdef F_161
V_14 = F_158 ( V_226 , & V_458 , V_330 ) ;
#endif
break;
#endif
}
return V_14 ;
}
static int F_225 ( struct V_222 * V_223 ,
char T_8 * V_463 ,
int T_8 * V_464 , unsigned V_184 )
{
struct V_220 * V_221 ;
char * V_465 = L_25 ;
int V_414 = 1 ;
int V_14 = 0 ;
V_221 = V_223 -> V_226 -> V_227 ;
if ( V_221 -> V_286 != NULL ) {
V_465 = V_221 -> V_286 -> V_19 ;
V_414 = strlen ( V_465 ) + 1 ;
}
if ( V_414 > V_184 )
V_14 = - V_466 ;
else if ( F_226 ( V_463 , V_465 , V_414 ) != 0 )
V_14 = - V_467 ;
if ( F_227 ( V_414 , V_464 ) != 0 )
V_14 = - V_467 ;
return V_14 ;
}
static int F_228 ( struct V_222 * V_223 ,
struct V_434 * V_435 , T_4 * V_233 )
{
struct V_424 V_457 ;
struct V_220 * V_221 = NULL ;
struct V_11 * V_46 ;
int V_283 = V_468 ;
T_4 V_2 = 0 ;
int V_14 ;
if ( V_435 != NULL ) {
if ( V_435 -> V_346 == F_229 ( V_469 ) )
V_283 = V_344 ;
#if F_165 ( V_349 )
else if ( V_435 -> V_346 == F_229 ( V_470 ) )
V_283 = V_328 ;
#endif
}
if ( V_283 == V_468 && V_223 != NULL )
V_283 = V_223 -> V_226 -> V_309 ;
switch ( V_283 ) {
case V_471 :
V_221 = V_223 -> V_226 -> V_227 ;
V_2 = V_221 -> V_231 -> V_234 ;
break;
case V_344 :
#ifdef F_218
V_2 = V_435 -> V_459 ;
if ( V_2 != 0 )
break;
#endif
if ( V_223 != NULL && V_223 -> V_226 != NULL )
V_221 = V_223 -> V_226 -> V_227 ;
F_219 ( & V_457 ) ;
V_14 = F_220 ( V_435 , V_283 , & V_457 ) ;
if ( V_14 == 0 ) {
V_46 = F_211 ( & V_457 , V_221 ) ;
V_2 = V_46 -> V_234 ;
}
F_221 ( & V_457 ) ;
break;
case V_328 :
#ifdef F_166
V_2 = V_435 -> V_459 ;
#endif
break;
}
* V_233 = V_2 ;
if ( V_2 == 0 )
return - V_138 ;
return 0 ;
}
static void F_230 ( struct V_223 * V_226 , struct V_222 * V_472 )
{
struct V_220 * V_221 ;
struct V_11 * V_46 = F_45 () ;
if ( V_226 == NULL ||
( V_226 -> V_309 != V_344 && V_226 -> V_309 != V_328 ) )
return;
V_221 = V_226 -> V_227 ;
V_221 -> V_229 = V_46 ;
V_221 -> V_231 = V_46 ;
}
static int F_231 ( struct V_223 * V_226 , struct V_434 * V_435 ,
struct V_473 * V_474 )
{
T_10 V_283 = V_226 -> V_309 ;
struct V_11 * V_46 ;
struct V_220 * V_221 = V_226 -> V_227 ;
struct V_424 V_457 ;
struct V_287 V_475 ;
struct V_476 * V_477 ;
struct V_11 * V_478 ;
int V_14 ;
struct V_80 V_81 ;
#ifdef F_154
struct V_313 V_314 ;
#endif
#if F_165 ( V_349 )
if ( V_283 == V_328 ) {
if ( V_435 -> V_346 == F_229 ( V_469 ) )
V_283 = V_344 ;
else
return 0 ;
}
#endif
#ifdef F_218
if ( V_435 && V_435 -> V_459 != 0 ) {
V_46 = F_124 ( V_435 -> V_459 ) ;
goto V_460;
}
#endif
F_219 ( & V_457 ) ;
V_14 = F_220 ( V_435 , V_283 , & V_457 ) ;
if ( V_14 == 0 )
V_46 = F_211 ( & V_457 , V_221 ) ;
else
V_46 = & V_479 ;
F_221 ( & V_457 ) ;
#ifdef F_218
V_460:
#endif
#ifdef F_154
F_155 ( & V_81 , V_92 , V_315 , & V_314 ) ;
V_81 . V_316 . V_317 . V_314 -> V_283 = V_283 ;
V_81 . V_316 . V_317 . V_314 -> V_461 = V_435 -> V_462 ;
F_222 ( V_435 , & V_81 . V_316 , NULL ) ;
#endif
V_14 = V_256 ( V_46 , V_221 -> V_229 , V_5 , & V_81 ) ;
V_14 = F_2 ( L_26 , V_46 , V_221 -> V_229 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_474 -> V_480 = V_46 -> V_234 ;
V_477 = F_232 ( V_435 ) ;
V_475 . V_293 . V_294 = V_477 -> V_332 ;
F_35 () ;
V_478 = F_142 ( & V_475 ) ;
F_40 () ;
if ( V_478 == NULL )
V_14 = F_233 ( V_474 , & V_46 -> V_310 ) ;
else
F_234 ( V_474 ) ;
return V_14 ;
}
static void F_235 ( struct V_223 * V_226 ,
const struct V_473 * V_474 )
{
struct V_220 * V_221 = V_226 -> V_227 ;
struct V_11 * V_46 ;
if ( V_474 -> V_480 != 0 ) {
V_46 = F_124 ( V_474 -> V_480 ) ;
V_221 -> V_286 = V_46 ;
} else
V_221 -> V_286 = NULL ;
}
static int F_236 ( struct V_481 * V_481 , const struct V_39 * V_39 ,
unsigned long V_165 )
{
struct V_11 * V_46 = F_37 ( V_39 -> V_40 ) ;
V_481 -> V_40 = V_46 ;
return 0 ;
}
static void F_237 ( struct V_481 * V_481 )
{
V_481 -> V_40 = NULL ;
}
static int F_238 ( T_11 V_482 ,
const struct V_39 * V_39 , unsigned V_483 )
{
struct V_481 * V_484 ;
struct V_80 V_81 ;
struct V_11 * V_261 = F_37 ( V_39 -> V_40 ) ;
int V_485 = 0 ;
int V_14 ;
V_484 = F_239 ( V_482 ) ;
if ( V_484 == NULL )
return - V_138 ;
if ( V_484 -> V_40 == NULL )
return 0 ;
if ( V_261 == NULL )
return - V_89 ;
#ifdef F_154
F_33 ( & V_81 , V_92 , V_486 ) ;
V_81 . V_316 . V_317 . V_487 . V_481 = V_484 -> V_488 ;
V_81 . V_316 . V_317 . V_487 . V_489 = V_484 -> V_490 ;
#endif
if ( V_483 & V_491 )
V_485 = V_4 ;
if ( V_483 & ( V_492 | V_493 | V_494 ) )
V_485 = V_5 ;
V_14 = V_256 ( V_261 , V_484 -> V_40 , V_485 , & V_81 ) ;
V_14 = F_2 ( L_27 , V_261 , V_484 -> V_40 , V_485 , V_14 ) ;
return V_14 ;
}
static int F_240 ( struct V_481 * V_481 , char * * V_495 )
{
struct V_11 * V_46 = V_481 -> V_40 ;
T_3 V_496 ;
char * V_497 ;
if ( V_481 -> V_40 == NULL ) {
* V_495 = NULL ;
return 0 ;
}
V_497 = F_79 ( V_46 -> V_19 , V_51 ) ;
if ( V_497 == NULL )
return - V_52 ;
V_496 = strlen ( V_497 ) + 1 ;
* V_495 = V_497 ;
return V_496 ;
}
static int F_241 ( T_4 V_498 , T_4 V_499 , char * V_500 , void * * V_501 )
{
struct V_11 * V_46 ;
char * * V_502 = ( char * * ) V_501 ;
* V_502 = NULL ;
if ( V_498 != V_503 && V_498 != V_504 )
return - V_138 ;
if ( V_499 != V_505 && V_499 != V_506 )
return - V_138 ;
V_46 = F_17 ( V_500 , 0 ) ;
if ( F_60 ( V_46 ) )
return F_61 ( V_46 ) ;
* V_502 = V_46 -> V_19 ;
return 0 ;
}
static int F_242 ( struct V_507 * V_508 )
{
struct V_509 * V_510 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_508 -> V_511 ; V_3 ++ ) {
V_510 = & V_508 -> V_512 [ V_3 ] ;
if ( V_510 -> type == V_503 || V_510 -> type == V_504 )
return 1 ;
}
return 0 ;
}
static int F_243 ( T_4 V_233 , T_4 V_498 , T_4 V_499 , void * V_501 ,
struct V_513 * V_514 )
{
struct V_11 * V_46 ;
char * V_502 = V_501 ;
if ( F_112 ( ! V_502 ) ) {
F_244 ( 1 , L_28 ) ;
return - V_255 ;
}
if ( V_498 != V_503 && V_498 != V_504 )
return 0 ;
V_46 = F_124 ( V_233 ) ;
if ( V_499 == V_505 )
return ( V_502 == V_46 -> V_19 ) ;
if ( V_499 == V_506 )
return ( V_502 != V_46 -> V_19 ) ;
return 0 ;
}
static int F_245 ( const char * V_41 )
{
return ( strcmp ( V_41 , V_188 ) == 0 ) ;
}
static int F_246 ( T_4 V_233 , char * * V_515 , T_4 * V_516 )
{
struct V_11 * V_46 = F_124 ( V_233 ) ;
if ( V_515 )
* V_515 = V_46 -> V_19 ;
* V_516 = strlen ( V_46 -> V_19 ) ;
return 0 ;
}
static int F_247 ( const char * V_515 , T_4 V_516 , T_4 * V_233 )
{
struct V_11 * V_46 = F_248 ( V_515 ) ;
if ( V_46 )
* V_233 = V_46 -> V_234 ;
else
* V_233 = 0 ;
return 0 ;
}
static int F_249 ( struct V_27 * V_27 , void * V_517 , T_4 V_518 )
{
return F_159 ( V_27 , V_188 , V_517 , V_518 , 0 ) ;
}
static int F_250 ( struct V_43 * V_43 , void * V_517 , T_4 V_518 )
{
return F_251 ( V_43 , V_208 , V_517 , V_518 , 0 ) ;
}
static int F_252 ( struct V_27 * V_27 , void * * V_517 , T_4 * V_518 )
{
int V_184 = 0 ;
V_184 = F_96 ( V_27 , V_188 , V_517 , true ) ;
if ( V_184 < 0 )
return V_184 ;
* V_518 = V_184 ;
return 0 ;
}
static T_12 void F_253 ( void )
{
F_21 ( & V_479 . V_62 ) ;
F_21 ( & V_106 . V_62 ) ;
F_21 ( & V_102 . V_62 ) ;
F_21 ( & V_216 . V_62 ) ;
F_21 ( & V_217 . V_62 ) ;
F_23 ( & V_479 . V_60 ) ;
F_23 ( & V_106 . V_60 ) ;
F_23 ( & V_216 . V_60 ) ;
F_23 ( & V_102 . V_60 ) ;
F_23 ( & V_217 . V_60 ) ;
F_254 ( & V_479 ) ;
F_254 ( & V_106 ) ;
F_254 ( & V_216 ) ;
F_254 ( & V_102 ) ;
F_254 ( & V_217 ) ;
}
static T_12 int F_255 ( void )
{
struct V_39 * V_39 ;
struct V_20 * V_21 ;
if ( ! F_256 ( L_29 ) )
return 0 ;
V_53 = F_257 ( V_28 , 0 ) ;
if ( ! V_53 )
return - V_52 ;
V_21 = F_22 ( & V_102 , & V_102 ,
V_51 ) ;
if ( V_21 == NULL ) {
F_258 ( V_53 ) ;
return - V_52 ;
}
V_519 = 1 ;
F_3 ( L_30 ) ;
#ifdef F_218
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
F_253 () ;
F_259 ( V_520 , F_260 ( V_520 ) ) ;
return 0 ;
}

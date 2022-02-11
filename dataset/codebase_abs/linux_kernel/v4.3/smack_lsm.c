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
F_20 ( & V_21 -> V_62 ) ;
return V_21 ;
}
static int F_23 ( struct V_63 * V_64 , struct V_63 * V_65 ,
T_1 V_59 )
{
struct V_66 * V_67 ;
struct V_66 * V_68 ;
int V_14 = 0 ;
F_22 ( V_64 ) ;
F_24 (orp, ohead, list) {
V_67 = F_15 ( sizeof( struct V_66 ) , V_59 ) ;
if ( V_67 == NULL ) {
V_14 = - V_53 ;
break;
}
* V_67 = * V_68 ;
F_25 ( & V_67 -> V_69 , V_64 ) ;
}
return V_14 ;
}
static inline unsigned int F_26 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_70 :
return V_4 ;
case V_71 :
return V_72 ;
}
return 0 ;
}
static int F_27 ( struct V_25 * V_73 ,
struct V_11 * V_74 ,
unsigned int V_1 , const char * V_75 )
{
int V_14 ;
struct V_76 V_77 , * V_78 = NULL ;
struct V_20 * V_21 ;
struct V_11 * V_79 ;
if ( ( V_1 & V_80 ) == 0 ) {
F_28 ( & V_77 , V_75 , V_81 ) ;
F_29 ( & V_77 , V_73 ) ;
V_78 = & V_77 ;
}
F_30 () ;
V_21 = F_31 ( V_73 ) -> V_40 ;
V_79 = F_32 ( V_21 ) ;
if ( ( V_1 & V_71 ) &&
( V_82 == V_83 ||
V_82 == V_84 ) ) {
if ( V_79 -> V_19 == V_74 -> V_19 )
V_14 = 0 ;
else if ( V_82 == V_84 )
V_14 = - V_85 ;
else if ( F_33 ( V_86 ) )
V_14 = 0 ;
else
V_14 = - V_85 ;
if ( V_78 )
F_34 ( V_79 -> V_19 ,
V_74 -> V_19 ,
0 , V_14 , V_78 ) ;
F_35 () ;
return V_14 ;
}
V_14 = F_36 ( V_21 , V_74 , F_26 ( V_1 ) , V_78 ) ;
F_35 () ;
return V_14 ;
}
static int F_37 ( struct V_25 * V_87 , unsigned int V_1 )
{
struct V_11 * V_47 ;
V_47 = F_7 ( V_87 ) ;
return F_27 ( V_23 , V_47 , V_1 , V_88 ) ;
}
static int F_38 ( struct V_25 * V_89 )
{
int V_14 ;
struct V_11 * V_47 ;
V_47 = F_32 ( F_5 () ) ;
V_14 = F_27 ( V_89 , V_47 , V_71 , V_88 ) ;
return V_14 ;
}
static int F_39 ( int V_90 )
{
int V_14 = 0 ;
struct V_11 * V_47 = F_40 () ;
if ( F_41 ( V_91 ) )
return 0 ;
if ( V_92 != NULL && V_92 != V_47 )
V_14 = - V_85 ;
return V_14 ;
}
static int F_42 ( struct V_93 * V_94 )
{
struct V_95 * V_96 ;
V_96 = F_15 ( sizeof( struct V_95 ) , V_52 ) ;
if ( V_96 == NULL )
return - V_53 ;
V_96 -> V_97 = & V_98 ;
V_96 -> V_99 = & V_98 ;
V_96 -> V_100 = & V_98 ;
V_96 -> V_101 = & V_102 ;
V_94 -> V_103 = V_96 ;
return 0 ;
}
static void F_43 ( struct V_93 * V_94 )
{
F_17 ( V_94 -> V_103 ) ;
V_94 -> V_103 = NULL ;
}
static int F_44 ( char * V_104 , char * V_105 )
{
char * V_106 , * V_107 , * V_108 , * V_45 ;
V_108 = ( char * ) F_45 ( V_52 ) ;
if ( V_108 == NULL )
return - V_53 ;
for ( V_106 = V_104 , V_107 = V_104 ; V_107 != NULL ; V_106 = V_107 + 1 ) {
if ( strstr ( V_106 , V_109 ) == V_106 )
V_45 = V_105 ;
else if ( strstr ( V_106 , V_110 ) == V_106 )
V_45 = V_105 ;
else if ( strstr ( V_106 , V_111 ) == V_106 )
V_45 = V_105 ;
else if ( strstr ( V_106 , V_112 ) == V_106 )
V_45 = V_105 ;
else if ( strstr ( V_106 , V_113 ) == V_106 )
V_45 = V_105 ;
else
V_45 = V_108 ;
V_107 = strchr ( V_106 , ',' ) ;
if ( V_107 != NULL )
* V_107 = '\0' ;
if ( * V_45 != '\0' )
strcat ( V_45 , L_7 ) ;
strcat ( V_45 , V_106 ) ;
}
strcpy ( V_104 , V_108 ) ;
F_46 ( ( unsigned long ) V_108 ) ;
return 0 ;
}
static int F_47 ( char * V_114 ,
struct V_115 * V_116 )
{
char * V_117 ;
char * V_118 = NULL ;
char * V_119 = NULL ;
char * V_120 = NULL ;
char * V_121 = NULL ;
char * V_122 = NULL ;
int V_14 = - V_53 ;
int V_123 = 0 ;
int V_124 ;
V_116 -> V_123 = 0 ;
if ( ! V_114 )
return 0 ;
while ( ( V_117 = F_48 ( & V_114 , L_7 ) ) != NULL ) {
T_2 args [ V_125 ] ;
if ( ! * V_117 )
continue;
V_124 = F_49 ( V_117 , V_126 , args ) ;
switch ( V_124 ) {
case V_127 :
if ( V_118 )
goto V_128;
V_118 = F_50 ( & args [ 0 ] ) ;
if ( ! V_118 )
goto V_129;
break;
case V_130 :
if ( V_119 )
goto V_128;
V_119 = F_50 ( & args [ 0 ] ) ;
if ( ! V_119 )
goto V_129;
break;
case V_131 :
if ( V_120 )
goto V_128;
V_120 = F_50 ( & args [ 0 ] ) ;
if ( ! V_120 )
goto V_129;
break;
case V_132 :
if ( V_121 )
goto V_128;
V_121 = F_50 ( & args [ 0 ] ) ;
if ( ! V_121 )
goto V_129;
break;
case V_133 :
if ( V_122 )
goto V_128;
V_122 = F_50 ( & args [ 0 ] ) ;
if ( ! V_122 )
goto V_129;
break;
default:
V_14 = - V_134 ;
F_51 ( L_8 ) ;
goto V_129;
}
}
V_116 -> V_135 = F_52 ( V_136 , sizeof( char * ) , V_137 ) ;
if ( ! V_116 -> V_135 )
goto V_129;
V_116 -> V_138 = F_52 ( V_136 , sizeof( int ) ,
V_137 ) ;
if ( ! V_116 -> V_138 ) {
F_17 ( V_116 -> V_135 ) ;
goto V_129;
}
if ( V_118 ) {
V_116 -> V_135 [ V_123 ] = V_118 ;
V_116 -> V_138 [ V_123 ++ ] = V_139 ;
}
if ( V_119 ) {
V_116 -> V_135 [ V_123 ] = V_119 ;
V_116 -> V_138 [ V_123 ++ ] = V_140 ;
}
if ( V_120 ) {
V_116 -> V_135 [ V_123 ] = V_120 ;
V_116 -> V_138 [ V_123 ++ ] = V_141 ;
}
if ( V_121 ) {
V_116 -> V_135 [ V_123 ] = V_121 ;
V_116 -> V_138 [ V_123 ++ ] = V_142 ;
}
if ( V_122 ) {
V_116 -> V_135 [ V_123 ] = V_122 ;
V_116 -> V_138 [ V_123 ++ ] = V_143 ;
}
V_116 -> V_123 = V_123 ;
return 0 ;
V_128:
V_14 = - V_134 ;
F_51 ( L_9 ) ;
V_129:
F_17 ( V_118 ) ;
F_17 ( V_119 ) ;
F_17 ( V_120 ) ;
F_17 ( V_121 ) ;
F_17 ( V_122 ) ;
return V_14 ;
}
static int F_53 ( struct V_93 * V_94 ,
struct V_115 * V_116 ,
unsigned long V_144 ,
unsigned long * V_145 )
{
struct V_44 * V_146 = V_94 -> V_147 ;
struct V_27 * V_27 = F_54 ( V_146 ) ;
struct V_95 * V_148 = V_94 -> V_103 ;
struct V_28 * V_29 ;
struct V_11 * V_47 ;
int V_3 ;
int V_149 = V_116 -> V_123 ;
int V_150 = 0 ;
if ( V_148 -> V_151 )
return 0 ;
V_148 -> V_151 = 1 ;
for ( V_3 = 0 ; V_3 < V_149 ; V_3 ++ ) {
switch ( V_116 -> V_138 [ V_3 ] ) {
case V_139 :
V_47 = F_16 ( V_116 -> V_135 [ V_3 ] , 0 ) ;
if ( F_55 ( V_47 ) )
return F_56 ( V_47 ) ;
V_148 -> V_99 = V_47 ;
break;
case V_140 :
V_47 = F_16 ( V_116 -> V_135 [ V_3 ] , 0 ) ;
if ( F_55 ( V_47 ) )
return F_56 ( V_47 ) ;
V_148 -> V_100 = V_47 ;
break;
case V_141 :
V_47 = F_16 ( V_116 -> V_135 [ V_3 ] , 0 ) ;
if ( F_55 ( V_47 ) )
return F_56 ( V_47 ) ;
V_148 -> V_101 = V_47 ;
break;
case V_142 :
V_47 = F_16 ( V_116 -> V_135 [ V_3 ] , 0 ) ;
if ( F_55 ( V_47 ) )
return F_56 ( V_47 ) ;
V_148 -> V_97 = V_47 ;
break;
case V_143 :
V_47 = F_16 ( V_116 -> V_135 [ V_3 ] , 0 ) ;
if ( F_55 ( V_47 ) )
return F_56 ( V_47 ) ;
V_148 -> V_97 = V_47 ;
V_150 = 1 ;
break;
default:
break;
}
}
if ( ! F_41 ( V_152 ) ) {
if ( V_149 )
return - V_153 ;
V_47 = F_40 () ;
V_148 -> V_97 = V_47 ;
V_148 -> V_99 = V_47 ;
}
V_29 = V_27 -> V_30 ;
if ( V_29 == NULL ) {
V_29 = F_18 ( V_148 -> V_97 ) ;
if ( V_29 == NULL )
return - V_53 ;
V_27 -> V_30 = V_29 ;
} else
V_29 -> V_37 = V_148 -> V_97 ;
if ( V_150 )
V_29 -> V_31 |= V_154 ;
return 0 ;
}
static int F_57 ( struct V_93 * V_94 , int V_155 , void * V_156 )
{
int V_14 = 0 ;
char * V_114 = V_156 ;
struct V_115 V_116 ;
F_58 ( & V_116 ) ;
if ( ! V_114 )
goto V_157;
V_14 = F_47 ( V_114 , & V_116 ) ;
if ( V_14 )
goto V_129;
V_157:
V_14 = F_53 ( V_94 , & V_116 , 0 , NULL ) ;
V_129:
F_59 ( & V_116 ) ;
return V_14 ;
}
static int F_60 ( struct V_44 * V_44 )
{
struct V_95 * V_158 = V_44 -> V_159 -> V_103 ;
int V_14 ;
struct V_76 V_77 ;
F_28 ( & V_77 , V_88 , V_160 ) ;
F_61 ( & V_77 , V_44 ) ;
V_14 = F_62 ( V_158 -> V_100 , V_4 , & V_77 ) ;
V_14 = F_4 ( L_10 , V_158 -> V_100 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_63 ( struct V_161 * V_162 )
{
struct V_27 * V_27 = F_10 ( V_162 -> V_38 ) ;
struct V_20 * V_163 = V_162 -> V_39 -> V_40 ;
struct V_28 * V_29 ;
int V_14 ;
if ( V_162 -> V_164 )
return 0 ;
V_29 = V_27 -> V_30 ;
if ( V_29 -> V_22 == NULL || V_29 -> V_22 == V_163 -> V_22 )
return 0 ;
if ( V_162 -> V_165 & ( V_166 | V_167 ) ) {
struct V_25 * V_73 ;
V_14 = 0 ;
F_30 () ;
V_73 = F_64 ( V_23 ) ;
if ( F_65 ( V_73 != NULL ) )
V_14 = F_27 ( V_73 ,
V_29 -> V_22 ,
V_71 ,
V_88 ) ;
F_35 () ;
if ( V_14 != 0 )
return V_14 ;
} else if ( V_162 -> V_165 )
return - V_153 ;
V_163 -> V_22 = V_29 -> V_22 ;
V_162 -> V_168 |= V_169 ;
return 0 ;
}
static void F_66 ( struct V_161 * V_162 )
{
struct V_20 * V_163 = V_162 -> V_39 -> V_40 ;
if ( V_163 -> V_22 != V_163 -> V_60 )
V_23 -> V_170 = 0 ;
}
static int F_67 ( struct V_161 * V_162 )
{
struct V_20 * V_21 = F_5 () ;
if ( V_21 -> V_22 != V_21 -> V_60 )
return 1 ;
return 0 ;
}
static int F_68 ( struct V_27 * V_27 )
{
struct V_11 * V_47 = F_40 () ;
V_27 -> V_30 = F_18 ( V_47 ) ;
if ( V_27 -> V_30 == NULL )
return - V_53 ;
return 0 ;
}
static void F_69 ( struct V_27 * V_27 )
{
F_70 ( V_54 , V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
static int F_71 ( struct V_27 * V_27 , struct V_27 * V_171 ,
const struct V_172 * V_172 , const char * * V_42 ,
void * * V_173 , T_3 * V_174 )
{
struct V_28 * V_175 = V_27 -> V_30 ;
struct V_11 * V_47 = F_40 () ;
struct V_11 * V_29 = F_11 ( V_27 ) ;
struct V_11 * V_176 = F_11 ( V_171 ) ;
int V_177 ;
if ( V_42 )
* V_42 = V_178 ;
if ( V_173 && V_174 ) {
F_30 () ;
V_177 = F_72 ( V_47 -> V_19 , V_176 -> V_19 ,
& V_47 -> V_61 ) ;
F_35 () ;
if ( V_177 > 0 && ( ( V_177 & V_8 ) != 0 ) &&
F_73 ( V_171 ) ) {
V_29 = V_176 ;
V_175 -> V_31 |= V_179 ;
}
* V_173 = F_74 ( V_29 -> V_19 , V_55 ) ;
if ( * V_173 == NULL )
return - V_53 ;
* V_174 = strlen ( V_29 -> V_19 ) ;
}
return 0 ;
}
static int F_75 ( struct V_44 * V_180 , struct V_27 * V_171 ,
struct V_44 * V_181 )
{
struct V_11 * V_29 ;
struct V_76 V_77 ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_160 ) ;
F_61 ( & V_77 , V_180 ) ;
V_29 = F_11 ( F_54 ( V_180 ) ) ;
V_14 = F_62 ( V_29 , V_5 , & V_77 ) ;
V_14 = F_8 ( F_54 ( V_180 ) , V_5 , V_14 ) ;
if ( V_14 == 0 && F_76 ( V_181 ) ) {
V_29 = F_11 ( F_54 ( V_181 ) ) ;
F_61 ( & V_77 , V_181 ) ;
V_14 = F_62 ( V_29 , V_5 , & V_77 ) ;
V_14 = F_8 ( F_54 ( V_181 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_77 ( struct V_27 * V_171 , struct V_44 * V_44 )
{
struct V_27 * V_43 = F_54 ( V_44 ) ;
struct V_76 V_77 ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_160 ) ;
F_61 ( & V_77 , V_44 ) ;
V_14 = F_62 ( F_11 ( V_43 ) , V_5 , & V_77 ) ;
V_14 = F_8 ( V_43 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_28 ( & V_77 , V_88 , V_182 ) ;
F_78 ( & V_77 , V_171 ) ;
V_14 = F_62 ( F_11 ( V_171 ) , V_5 , & V_77 ) ;
V_14 = F_8 ( V_171 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_79 ( struct V_27 * V_171 , struct V_44 * V_44 )
{
struct V_76 V_77 ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_160 ) ;
F_61 ( & V_77 , V_44 ) ;
V_14 = F_62 ( F_11 ( F_54 ( V_44 ) ) , V_5 , & V_77 ) ;
V_14 = F_8 ( F_54 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_28 ( & V_77 , V_88 , V_182 ) ;
F_78 ( & V_77 , V_171 ) ;
V_14 = F_62 ( F_11 ( V_171 ) , V_5 , & V_77 ) ;
V_14 = F_8 ( V_171 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_80 ( struct V_27 * V_183 ,
struct V_44 * V_180 ,
struct V_27 * V_184 ,
struct V_44 * V_181 )
{
int V_14 ;
struct V_11 * V_29 ;
struct V_76 V_77 ;
F_28 ( & V_77 , V_88 , V_160 ) ;
F_61 ( & V_77 , V_180 ) ;
V_29 = F_11 ( F_54 ( V_180 ) ) ;
V_14 = F_62 ( V_29 , V_72 , & V_77 ) ;
V_14 = F_8 ( F_54 ( V_180 ) , V_72 , V_14 ) ;
if ( V_14 == 0 && F_76 ( V_181 ) ) {
V_29 = F_11 ( F_54 ( V_181 ) ) ;
F_61 ( & V_77 , V_181 ) ;
V_14 = F_62 ( V_29 , V_72 , & V_77 ) ;
V_14 = F_8 ( F_54 ( V_181 ) , V_72 , V_14 ) ;
}
return V_14 ;
}
static int F_81 ( struct V_27 * V_27 , int V_185 )
{
struct V_76 V_77 ;
int V_186 = V_185 & V_187 ;
int V_14 ;
V_185 &= ( V_4 | V_5 | V_6 | V_7 ) ;
if ( V_185 == 0 )
return 0 ;
if ( V_186 )
return - V_188 ;
F_28 ( & V_77 , V_88 , V_182 ) ;
F_78 ( & V_77 , V_27 ) ;
V_14 = F_62 ( F_11 ( V_27 ) , V_185 , & V_77 ) ;
V_14 = F_8 ( V_27 , V_185 , V_14 ) ;
return V_14 ;
}
static int F_82 ( struct V_44 * V_44 , struct V_189 * V_189 )
{
struct V_76 V_77 ;
int V_14 ;
if ( V_189 -> V_190 & V_191 )
return 0 ;
F_28 ( & V_77 , V_88 , V_160 ) ;
F_61 ( & V_77 , V_44 ) ;
V_14 = F_62 ( F_11 ( F_54 ( V_44 ) ) , V_5 , & V_77 ) ;
V_14 = F_8 ( F_54 ( V_44 ) , V_5 , V_14 ) ;
return V_14 ;
}
static int F_83 ( const struct V_192 * V_192 )
{
struct V_76 V_77 ;
struct V_27 * V_27 = F_54 ( V_192 -> V_44 ) ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_193 ) ;
F_84 ( & V_77 , * V_192 ) ;
V_14 = F_62 ( F_11 ( V_27 ) , V_4 , & V_77 ) ;
V_14 = F_8 ( V_27 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_85 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_173 , T_3 V_194 , int V_155 )
{
struct V_76 V_77 ;
struct V_11 * V_47 ;
int V_195 = 0 ;
int V_196 = 0 ;
int V_197 = 0 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_198 ) == 0 ||
strcmp ( V_42 , V_199 ) == 0 ||
strcmp ( V_42 , V_200 ) == 0 ) {
V_195 = 1 ;
V_196 = 1 ;
} else if ( strcmp ( V_42 , V_201 ) == 0 ||
strcmp ( V_42 , V_202 ) == 0 ) {
V_195 = 1 ;
V_196 = 1 ;
V_197 = 1 ;
} else if ( strcmp ( V_42 , V_203 ) == 0 ) {
V_195 = 1 ;
if ( V_194 != V_204 ||
strncmp ( V_173 , V_205 , V_204 ) != 0 )
V_14 = - V_134 ;
} else
V_14 = F_86 ( V_44 , V_42 , V_173 , V_194 , V_155 ) ;
if ( V_195 && ! F_41 ( V_152 ) )
V_14 = - V_153 ;
if ( V_14 == 0 && V_196 ) {
V_47 = V_194 ? F_16 ( V_173 , V_194 ) : NULL ;
if ( F_55 ( V_47 ) )
V_14 = F_56 ( V_47 ) ;
else if ( V_47 == NULL || ( V_197 &&
( V_47 == & V_206 || V_47 == & V_207 ) ) )
V_14 = - V_134 ;
}
F_28 ( & V_77 , V_88 , V_160 ) ;
F_61 ( & V_77 , V_44 ) ;
if ( V_14 == 0 ) {
V_14 = F_62 ( F_11 ( F_54 ( V_44 ) ) , V_5 , & V_77 ) ;
V_14 = F_8 ( F_54 ( V_44 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static void F_87 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_173 , T_3 V_194 , int V_155 )
{
struct V_11 * V_47 ;
struct V_28 * V_29 = F_54 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_203 ) == 0 ) {
V_29 -> V_31 |= V_154 ;
return;
}
if ( strcmp ( V_42 , V_198 ) == 0 ) {
V_47 = F_16 ( V_173 , V_194 ) ;
if ( ! F_55 ( V_47 ) )
V_29 -> V_37 = V_47 ;
else
V_29 -> V_37 = & V_208 ;
} else if ( strcmp ( V_42 , V_201 ) == 0 ) {
V_47 = F_16 ( V_173 , V_194 ) ;
if ( ! F_55 ( V_47 ) )
V_29 -> V_22 = V_47 ;
else
V_29 -> V_22 = & V_208 ;
} else if ( strcmp ( V_42 , V_202 ) == 0 ) {
V_47 = F_16 ( V_173 , V_194 ) ;
if ( ! F_55 ( V_47 ) )
V_29 -> V_209 = V_47 ;
else
V_29 -> V_209 = & V_208 ;
}
return;
}
static int F_88 ( struct V_44 * V_44 , const char * V_42 )
{
struct V_76 V_77 ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_160 ) ;
F_61 ( & V_77 , V_44 ) ;
V_14 = F_62 ( F_11 ( F_54 ( V_44 ) ) , V_4 , & V_77 ) ;
V_14 = F_8 ( F_54 ( V_44 ) , V_4 , V_14 ) ;
return V_14 ;
}
static int F_89 ( struct V_44 * V_44 , const char * V_42 )
{
struct V_28 * V_29 ;
struct V_76 V_77 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_198 ) == 0 ||
strcmp ( V_42 , V_199 ) == 0 ||
strcmp ( V_42 , V_200 ) == 0 ||
strcmp ( V_42 , V_201 ) == 0 ||
strcmp ( V_42 , V_203 ) == 0 ||
strcmp ( V_42 , V_202 ) == 0 ) {
if ( ! F_41 ( V_152 ) )
V_14 = - V_153 ;
} else
V_14 = F_90 ( V_44 , V_42 ) ;
if ( V_14 != 0 )
return V_14 ;
F_28 ( & V_77 , V_88 , V_160 ) ;
F_61 ( & V_77 , V_44 ) ;
V_14 = F_62 ( F_11 ( F_54 ( V_44 ) ) , V_5 , & V_77 ) ;
V_14 = F_8 ( F_54 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_29 = F_54 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_198 ) == 0 )
V_29 -> V_22 = NULL ;
else if ( strcmp ( V_42 , V_202 ) == 0 )
V_29 -> V_209 = NULL ;
else if ( strcmp ( V_42 , V_203 ) == 0 )
V_29 -> V_31 &= ~ V_154 ;
return 0 ;
}
static int F_91 ( const struct V_27 * V_27 ,
const char * V_42 , void * * V_46 ,
bool V_210 )
{
struct V_211 * V_212 ;
struct V_213 * V_214 ;
struct V_93 * V_158 ;
struct V_27 * V_43 = (struct V_27 * ) V_27 ;
struct V_11 * V_29 ;
int V_215 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_178 ) == 0 ) {
V_29 = F_11 ( V_27 ) ;
V_215 = strlen ( V_29 -> V_19 ) ;
* V_46 = V_29 -> V_19 ;
return V_215 ;
}
V_158 = V_43 -> V_33 ;
if ( V_158 -> V_216 != V_217 )
return - V_50 ;
V_214 = F_92 ( V_43 ) ;
if ( V_214 == NULL || V_214 -> V_218 == NULL )
return - V_50 ;
V_212 = V_214 -> V_218 -> V_219 ;
if ( strcmp ( V_42 , V_220 ) == 0 )
V_29 = V_212 -> V_221 ;
else if ( strcmp ( V_42 , V_222 ) == 0 )
V_29 = V_212 -> V_223 ;
else
return - V_50 ;
V_215 = strlen ( V_29 -> V_19 ) ;
if ( V_14 == 0 ) {
* V_46 = V_29 -> V_19 ;
V_14 = V_215 ;
}
return V_14 ;
}
static int F_93 ( struct V_27 * V_27 , char * V_46 ,
T_3 V_224 )
{
int V_174 = sizeof( V_198 ) ;
if ( V_46 != NULL && V_174 <= V_224 )
memcpy ( V_46 , V_198 , V_174 ) ;
return V_174 ;
}
static void F_94 ( const struct V_27 * V_27 , T_4 * V_225 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
* V_225 = V_29 -> V_37 -> V_226 ;
}
static int F_95 ( struct V_38 * V_38 , int V_185 )
{
return 0 ;
}
static int F_96 ( struct V_38 * V_38 )
{
struct V_11 * V_47 = F_40 () ;
V_38 -> V_227 = V_47 ;
return 0 ;
}
static void F_97 ( struct V_38 * V_38 )
{
V_38 -> V_227 = NULL ;
}
static int F_98 ( struct V_38 * V_38 , unsigned int V_228 ,
unsigned long V_229 )
{
int V_14 = 0 ;
struct V_76 V_77 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_28 ( & V_77 , V_88 , V_193 ) ;
F_84 ( & V_77 , V_38 -> V_230 ) ;
if ( F_99 ( V_228 ) & V_231 ) {
V_14 = F_62 ( F_11 ( V_27 ) , V_5 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_99 ( V_228 ) & V_232 ) ) {
V_14 = F_62 ( F_11 ( V_27 ) , V_4 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_100 ( struct V_38 * V_38 , unsigned int V_228 )
{
struct V_76 V_77 ;
int V_14 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_28 ( & V_77 , V_88 , V_193 ) ;
F_84 ( & V_77 , V_38 -> V_230 ) ;
V_14 = F_62 ( F_11 ( V_27 ) , V_9 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_101 ( struct V_38 * V_38 , unsigned int V_228 ,
unsigned long V_229 )
{
struct V_76 V_77 ;
int V_14 = 0 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
switch ( V_228 ) {
case V_233 :
break;
case V_234 :
case V_235 :
F_28 ( & V_77 , V_88 , V_193 ) ;
F_84 ( & V_77 , V_38 -> V_230 ) ;
V_14 = F_62 ( F_11 ( V_27 ) , V_9 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
break;
case V_236 :
case V_237 :
F_28 ( & V_77 , V_88 , V_193 ) ;
F_84 ( & V_77 , V_38 -> V_230 ) ;
V_14 = F_62 ( F_11 ( V_27 ) , V_5 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_102 ( struct V_38 * V_38 ,
unsigned long V_238 , unsigned long V_239 ,
unsigned long V_155 )
{
struct V_11 * V_47 ;
struct V_11 * V_240 ;
struct V_66 * V_241 ;
struct V_20 * V_21 ;
struct V_11 * V_242 ;
struct V_28 * V_29 ;
int V_177 ;
int V_243 ;
int V_244 ;
int V_14 ;
if ( V_38 == NULL )
return 0 ;
V_29 = F_10 ( V_38 ) -> V_30 ;
if ( V_29 -> V_209 == NULL )
return 0 ;
V_240 = V_29 -> V_209 ;
V_21 = F_5 () ;
V_47 = F_40 () ;
V_14 = 0 ;
F_30 () ;
F_24 (srp, &skp->smk_rules, list) {
V_242 = V_241 -> V_245 ;
if ( V_240 -> V_19 == V_242 -> V_19 )
continue;
V_177 = F_72 ( V_241 -> V_246 -> V_19 ,
V_242 -> V_19 ,
& V_21 -> V_61 ) ;
if ( V_177 == - V_247 )
V_177 = V_241 -> V_248 ;
else
V_177 &= V_241 -> V_248 ;
if ( V_177 == 0 )
continue;
V_243 = F_72 ( V_240 -> V_19 , V_242 -> V_19 ,
& V_240 -> V_61 ) ;
if ( V_243 == - V_247 ) {
V_14 = - V_85 ;
break;
}
V_244 = F_72 ( V_240 -> V_19 , V_242 -> V_19 ,
& V_21 -> V_61 ) ;
if ( V_244 != - V_247 )
V_243 &= V_244 ;
if ( ( V_177 | V_243 ) != V_243 ) {
V_14 = - V_85 ;
break;
}
}
F_35 () ;
return V_14 ;
}
static void F_103 ( struct V_38 * V_38 )
{
V_38 -> V_227 = F_40 () ;
}
static int F_104 ( struct V_25 * V_249 ,
struct V_250 * V_251 , int V_252 )
{
struct V_11 * V_47 ;
struct V_11 * V_253 = F_32 ( V_249 -> V_39 -> V_40 ) ;
struct V_38 * V_38 ;
int V_14 ;
struct V_76 V_77 ;
V_38 = F_105 ( V_251 , struct V_38 , V_254 ) ;
V_47 = V_38 -> V_227 ;
V_14 = V_248 ( V_47 , V_253 , V_5 , NULL ) ;
V_14 = F_2 ( L_11 , V_47 , V_253 , V_5 , V_14 ) ;
if ( V_14 != 0 && F_106 ( V_249 , V_91 ) )
V_14 = 0 ;
F_28 ( & V_77 , V_88 , V_81 ) ;
F_29 ( & V_77 , V_249 ) ;
F_34 ( V_47 -> V_19 , V_253 -> V_19 , V_5 , V_14 , & V_77 ) ;
return V_14 ;
}
static int F_107 ( struct V_38 * V_38 )
{
int V_14 ;
int V_177 = 0 ;
struct V_76 V_77 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
if ( F_108 ( F_109 ( V_27 ) ) )
return 0 ;
F_28 ( & V_77 , V_88 , V_193 ) ;
F_84 ( & V_77 , V_38 -> V_230 ) ;
if ( V_38 -> V_255 & V_256 )
V_177 = V_4 ;
if ( V_38 -> V_255 & V_257 )
V_177 |= V_5 ;
V_14 = F_62 ( F_11 ( V_27 ) , V_177 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_177 , V_14 ) ;
return V_14 ;
}
static int F_110 ( struct V_38 * V_38 , const struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_76 V_77 ;
int V_14 ;
if ( F_41 ( V_91 ) )
return 0 ;
F_28 ( & V_77 , V_88 , V_193 ) ;
F_84 ( & V_77 , V_38 -> V_230 ) ;
V_14 = V_248 ( V_21 -> V_22 , F_11 ( V_27 ) , V_4 , & V_77 ) ;
V_14 = F_12 ( V_39 , V_38 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_111 ( struct V_39 * V_39 , T_1 V_59 )
{
struct V_20 * V_21 ;
V_21 = F_21 ( NULL , NULL , V_59 ) ;
if ( V_21 == NULL )
return - V_53 ;
V_39 -> V_40 = V_21 ;
return 0 ;
}
static void F_112 ( struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_66 * V_258 ;
struct V_63 * V_259 ;
struct V_63 * V_260 ;
if ( V_21 == NULL )
return;
V_39 -> V_40 = NULL ;
F_113 (l, n, &tsp->smk_rules) {
V_258 = F_114 ( V_259 , struct V_66 , V_69 ) ;
F_115 ( & V_258 -> V_69 ) ;
F_17 ( V_258 ) ;
}
F_17 ( V_21 ) ;
}
static int F_116 ( struct V_39 * V_261 , const struct V_39 * V_262 ,
T_1 V_59 )
{
struct V_20 * V_263 = V_262 -> V_40 ;
struct V_20 * V_264 ;
int V_14 ;
V_264 = F_21 ( V_263 -> V_22 , V_263 -> V_22 , V_59 ) ;
if ( V_264 == NULL )
return - V_53 ;
V_14 = F_23 ( & V_264 -> V_61 , & V_263 -> V_61 , V_59 ) ;
if ( V_14 != 0 )
return V_14 ;
V_261 -> V_40 = V_264 ;
return 0 ;
}
static void F_117 ( struct V_39 * V_261 , const struct V_39 * V_262 )
{
struct V_20 * V_263 = V_262 -> V_40 ;
struct V_20 * V_264 = V_261 -> V_40 ;
V_264 -> V_22 = V_263 -> V_22 ;
V_264 -> V_60 = V_263 -> V_22 ;
F_20 ( & V_264 -> V_62 ) ;
F_22 ( & V_264 -> V_61 ) ;
}
static int F_118 ( struct V_39 * V_261 , T_4 V_225 )
{
struct V_20 * V_264 = V_261 -> V_40 ;
struct V_11 * V_47 = F_119 ( V_225 ) ;
if ( V_47 == NULL )
return - V_134 ;
V_264 -> V_22 = V_47 ;
return 0 ;
}
static int F_120 ( struct V_39 * V_261 ,
struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_20 * V_21 = V_261 -> V_40 ;
V_21 -> V_60 = V_29 -> V_37 ;
V_21 -> V_22 = V_21 -> V_60 ;
return 0 ;
}
static int F_121 ( struct V_25 * V_117 , int V_265 ,
const char * V_266 )
{
struct V_76 V_77 ;
struct V_11 * V_47 = F_7 ( V_117 ) ;
int V_14 ;
F_28 ( & V_77 , V_266 , V_81 ) ;
F_29 ( & V_77 , V_117 ) ;
V_14 = F_62 ( V_47 , V_265 , & V_77 ) ;
V_14 = F_6 ( V_117 , V_265 , V_14 ) ;
return V_14 ;
}
static int F_122 ( struct V_25 * V_117 , T_5 V_267 )
{
return F_121 ( V_117 , V_5 , V_88 ) ;
}
static int F_123 ( struct V_25 * V_117 )
{
return F_121 ( V_117 , V_4 , V_88 ) ;
}
static int F_124 ( struct V_25 * V_117 )
{
return F_121 ( V_117 , V_4 , V_88 ) ;
}
static void F_125 ( struct V_25 * V_117 , T_4 * V_225 )
{
struct V_11 * V_47 = F_7 ( V_117 ) ;
* V_225 = V_47 -> V_226 ;
}
static int F_126 ( struct V_25 * V_117 , int V_268 )
{
return F_121 ( V_117 , V_5 , V_88 ) ;
}
static int F_127 ( struct V_25 * V_117 , int V_269 )
{
return F_121 ( V_117 , V_5 , V_88 ) ;
}
static int F_128 ( struct V_25 * V_117 )
{
return F_121 ( V_117 , V_4 , V_88 ) ;
}
static int F_129 ( struct V_25 * V_117 )
{
return F_121 ( V_117 , V_5 , V_88 ) ;
}
static int F_130 ( struct V_25 * V_117 )
{
return F_121 ( V_117 , V_4 , V_88 ) ;
}
static int F_131 ( struct V_25 * V_117 )
{
return F_121 ( V_117 , V_5 , V_88 ) ;
}
static int F_132 ( struct V_25 * V_117 , struct V_270 * V_271 ,
int V_272 , T_4 V_225 )
{
struct V_76 V_77 ;
struct V_11 * V_47 ;
struct V_11 * V_253 = F_7 ( V_117 ) ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_81 ) ;
F_29 ( & V_77 , V_117 ) ;
if ( V_225 == 0 ) {
V_14 = F_62 ( V_253 , V_5 , & V_77 ) ;
V_14 = F_6 ( V_117 , V_5 , V_14 ) ;
return V_14 ;
}
V_47 = F_119 ( V_225 ) ;
V_14 = V_248 ( V_47 , V_253 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_12 , V_47 , V_253 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_133 ( struct V_25 * V_117 )
{
return 0 ;
}
static void F_134 ( struct V_25 * V_117 , struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_11 * V_47 = F_7 ( V_117 ) ;
V_29 -> V_37 = V_47 ;
}
static int F_135 ( struct V_214 * V_218 , int V_273 , T_1 V_274 )
{
struct V_11 * V_47 = F_40 () ;
struct V_211 * V_212 ;
V_212 = F_15 ( sizeof( struct V_211 ) , V_274 ) ;
if ( V_212 == NULL )
return - V_53 ;
V_212 -> V_221 = V_47 ;
V_212 -> V_223 = V_47 ;
V_212 -> V_275 = NULL ;
V_218 -> V_219 = V_212 ;
return 0 ;
}
static void F_136 ( struct V_214 * V_218 )
{
F_17 ( V_218 -> V_219 ) ;
}
static struct V_11 * F_137 ( struct V_276 * V_277 )
{
struct V_278 * V_279 ;
struct V_280 * V_281 = & V_277 -> V_282 ;
if ( V_281 -> V_283 == 0 )
return NULL ;
F_24 (snp, &smk_net4addr_list, list)
if ( V_279 -> V_284 . V_283 ==
( V_281 -> V_283 & V_279 -> V_285 . V_283 ) )
return V_279 -> V_286 ;
return NULL ;
}
static bool F_138 ( struct V_287 * V_277 )
{
T_6 * V_288 = ( T_6 * ) & V_277 -> V_289 ;
T_7 * V_290 = ( T_7 * ) & V_277 -> V_289 ;
if ( V_290 [ 0 ] == 0 && V_290 [ 1 ] == 0 && V_290 [ 2 ] == 0 && V_288 [ 6 ] == 0 &&
F_139 ( V_288 [ 7 ] ) == 1 )
return true ;
return false ;
}
static struct V_11 * F_140 ( struct V_287 * V_277 )
{
struct V_291 * V_279 ;
struct V_292 * V_293 = & V_277 -> V_289 ;
int V_3 ;
int V_294 = 0 ;
if ( F_138 ( V_277 ) )
return NULL ;
F_24 (snp, &smk_net6addr_list, list) {
for ( V_294 = 1 , V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
if ( V_279 -> V_286 == NULL )
continue;
if ( ( V_293 -> V_295 [ V_3 ] & V_279 -> V_285 . V_295 [ V_3 ] ) !=
V_279 -> V_284 . V_295 [ V_3 ] ) {
V_294 = 0 ;
break;
}
}
if ( V_294 )
return V_279 -> V_286 ;
}
return NULL ;
}
static int F_141 ( struct V_214 * V_218 , int V_296 )
{
struct V_11 * V_47 ;
struct V_211 * V_212 = V_218 -> V_219 ;
int V_14 = 0 ;
F_142 () ;
F_143 ( V_218 ) ;
if ( V_212 -> V_223 == V_297 ||
V_296 == V_298 )
F_144 ( V_218 ) ;
else {
V_47 = V_212 -> V_223 ;
V_14 = F_145 ( V_218 , V_218 -> V_299 , & V_47 -> V_300 ) ;
}
F_146 ( V_218 ) ;
F_147 () ;
return V_14 ;
}
static int F_148 ( struct V_214 * V_218 , struct V_276 * V_293 )
{
struct V_11 * V_47 ;
int V_14 ;
int V_301 ;
struct V_11 * V_302 ;
struct V_211 * V_212 = V_218 -> V_219 ;
struct V_76 V_77 ;
F_30 () ;
V_302 = F_137 ( V_293 ) ;
if ( V_302 != NULL ) {
#ifdef F_149
struct V_303 V_304 ;
F_150 ( & V_77 , V_88 , V_305 , & V_304 ) ;
V_77 . V_306 . V_307 . V_304 -> V_273 = V_293 -> V_308 ;
V_77 . V_306 . V_307 . V_304 -> V_309 = V_293 -> V_310 ;
V_77 . V_306 . V_307 . V_304 -> V_311 . V_312 = V_293 -> V_282 . V_283 ;
#endif
V_301 = V_298 ;
V_47 = V_212 -> V_223 ;
V_14 = V_248 ( V_47 , V_302 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_13 , V_47 , V_302 , V_5 , V_14 ) ;
} else {
V_301 = V_313 ;
V_14 = 0 ;
}
F_35 () ;
if ( V_14 != 0 )
return V_14 ;
return F_141 ( V_218 , V_301 ) ;
}
static int F_151 ( struct V_11 * V_314 ,
struct V_11 * V_315 ,
struct V_287 * V_316 , int V_317 )
{
#ifdef F_149
struct V_303 V_304 ;
#endif
struct V_76 V_77 ;
int V_14 ;
#ifdef F_149
F_150 ( & V_77 , V_88 , V_305 , & V_304 ) ;
V_77 . V_306 . V_307 . V_304 -> V_273 = V_318 ;
V_77 . V_306 . V_307 . V_304 -> V_309 = F_139 ( V_316 -> V_319 ) ;
if ( V_317 == V_320 )
V_77 . V_306 . V_307 . V_304 -> V_321 . V_322 = V_316 -> V_289 ;
else
V_77 . V_306 . V_307 . V_304 -> V_321 . V_312 = V_316 -> V_289 ;
#endif
V_14 = V_248 ( V_314 , V_315 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_14 , V_314 , V_315 , V_5 , V_14 ) ;
return V_14 ;
}
static void F_152 ( struct V_213 * V_214 , struct V_323 * V_316 )
{
struct V_214 * V_218 = V_214 -> V_218 ;
struct V_287 * V_324 ;
struct V_211 * V_212 = V_214 -> V_218 -> V_219 ;
struct V_325 * V_326 ;
unsigned short V_327 = 0 ;
if ( V_316 == NULL ) {
F_153 (spp, &smk_ipv6_port_list, list) {
if ( V_218 != V_326 -> V_328 )
continue;
V_326 -> V_221 = V_212 -> V_221 ;
V_326 -> V_223 = V_212 -> V_223 ;
return;
}
return;
}
V_324 = (struct V_287 * ) V_316 ;
V_327 = F_139 ( V_324 -> V_319 ) ;
if ( V_327 == 0 )
return;
F_153 (spp, &smk_ipv6_port_list, list) {
if ( V_326 -> V_329 != V_327 )
continue;
V_326 -> V_329 = V_327 ;
V_326 -> V_328 = V_218 ;
V_326 -> V_221 = V_212 -> V_221 ;
V_326 -> V_223 = V_212 -> V_223 ;
return;
}
V_326 = F_15 ( sizeof( * V_326 ) , V_52 ) ;
if ( V_326 == NULL )
return;
V_326 -> V_329 = V_327 ;
V_326 -> V_328 = V_218 ;
V_326 -> V_221 = V_212 -> V_221 ;
V_326 -> V_223 = V_212 -> V_223 ;
F_154 ( & V_326 -> V_69 , & V_330 ) ;
return;
}
static int F_155 ( struct V_214 * V_218 , struct V_287 * V_316 ,
int V_317 )
{
struct V_325 * V_326 ;
struct V_211 * V_212 = V_218 -> V_219 ;
struct V_11 * V_47 = NULL ;
unsigned short V_327 ;
struct V_11 * V_315 ;
if ( V_317 == V_320 ) {
V_47 = F_140 ( V_316 ) ;
V_315 = V_212 -> V_221 ;
} else {
V_47 = V_212 -> V_223 ;
V_315 = F_140 ( V_316 ) ;
}
if ( V_47 != NULL && V_315 != NULL )
return F_151 ( V_47 , V_315 , V_316 , V_317 ) ;
if ( V_47 == NULL )
V_47 = V_297 ;
if ( V_315 == NULL )
V_315 = V_297 ;
if ( ! F_138 ( V_316 ) )
return F_151 ( V_47 , V_315 , V_316 , V_317 ) ;
if ( V_317 == V_320 )
return 0 ;
V_327 = F_139 ( V_316 -> V_319 ) ;
F_153 (spp, &smk_ipv6_port_list, list) {
if ( V_326 -> V_329 != V_327 )
continue;
V_315 = V_326 -> V_221 ;
if ( V_317 == V_331 )
V_212 -> V_275 = V_326 -> V_223 ;
break;
}
return F_151 ( V_47 , V_315 , V_316 , V_317 ) ;
}
static int F_156 ( struct V_27 * V_27 , const char * V_42 ,
const void * V_173 , T_3 V_194 , int V_155 )
{
struct V_11 * V_47 ;
struct V_28 * V_332 = V_27 -> V_30 ;
struct V_211 * V_212 ;
struct V_213 * V_214 ;
int V_14 = 0 ;
if ( V_173 == NULL || V_194 > V_51 || V_194 == 0 )
return - V_134 ;
V_47 = F_16 ( V_173 , V_194 ) ;
if ( F_55 ( V_47 ) )
return F_56 ( V_47 ) ;
if ( strcmp ( V_42 , V_178 ) == 0 ) {
V_332 -> V_37 = V_47 ;
V_332 -> V_31 |= V_333 ;
return 0 ;
}
if ( V_27 -> V_33 -> V_216 != V_217 )
return - V_50 ;
V_214 = F_92 ( V_27 ) ;
if ( V_214 == NULL || V_214 -> V_218 == NULL )
return - V_50 ;
V_212 = V_214 -> V_218 -> V_219 ;
if ( strcmp ( V_42 , V_220 ) == 0 )
V_212 -> V_221 = V_47 ;
else if ( strcmp ( V_42 , V_222 ) == 0 ) {
V_212 -> V_223 = V_47 ;
if ( V_214 -> V_218 -> V_299 == V_334 ) {
V_14 = F_141 ( V_214 -> V_218 , V_313 ) ;
if ( V_14 != 0 )
F_157 ( V_335
L_15 ,
V_88 , - V_14 ) ;
}
} else
return - V_50 ;
#ifdef F_158
if ( V_214 -> V_218 -> V_299 == V_318 )
F_152 ( V_214 , NULL ) ;
#endif
return 0 ;
}
static int F_159 ( struct V_213 * V_214 , int V_273 ,
int type , int V_336 , int V_337 )
{
struct V_211 * V_212 ;
if ( V_214 -> V_218 == NULL )
return 0 ;
if ( F_108 ( V_23 -> V_155 & V_338 ) ) {
V_212 = V_214 -> V_218 -> V_219 ;
V_212 -> V_221 = & V_207 ;
V_212 -> V_223 = & V_207 ;
}
if ( V_273 != V_334 )
return 0 ;
return F_141 ( V_214 -> V_218 , V_313 ) ;
}
static int F_160 ( struct V_213 * V_214 , struct V_323 * V_316 ,
int V_339 )
{
if ( V_214 -> V_218 != NULL && V_214 -> V_218 -> V_299 == V_318 )
F_152 ( V_214 , V_316 ) ;
return 0 ;
}
static int F_161 ( struct V_213 * V_214 , struct V_323 * V_293 ,
int V_339 )
{
int V_14 = 0 ;
#if F_162 ( V_340 )
struct V_287 * V_277 = (struct V_287 * ) V_293 ;
#endif
#ifdef F_163
struct V_11 * V_341 ;
struct V_211 * V_212 = V_214 -> V_218 -> V_219 ;
#endif
if ( V_214 -> V_218 == NULL )
return 0 ;
switch ( V_214 -> V_218 -> V_299 ) {
case V_334 :
if ( V_339 < sizeof( struct V_276 ) )
return - V_134 ;
V_14 = F_148 ( V_214 -> V_218 , (struct V_276 * ) V_293 ) ;
break;
case V_318 :
if ( V_339 < sizeof( struct V_287 ) )
return - V_134 ;
#ifdef F_163
V_341 = F_140 ( V_277 ) ;
if ( V_341 != NULL )
V_14 = F_151 ( V_212 -> V_223 , V_341 , V_277 ,
V_331 ) ;
#endif
#ifdef F_158
V_14 = F_155 ( V_214 -> V_218 , V_277 , V_331 ) ;
#endif
break;
}
return V_14 ;
}
static int F_164 ( int V_155 )
{
int V_177 = 0 ;
if ( V_155 & V_342 )
V_177 |= V_4 ;
if ( V_155 & V_343 )
V_177 |= V_5 ;
if ( V_155 & V_344 )
V_177 |= V_6 ;
return V_177 ;
}
static int F_165 ( struct V_345 * V_346 )
{
struct V_11 * V_47 = F_40 () ;
V_346 -> V_40 = V_47 ;
return 0 ;
}
static void F_166 ( struct V_345 * V_346 )
{
V_346 -> V_40 = NULL ;
}
static struct V_11 * F_167 ( struct V_347 * V_348 )
{
return (struct V_11 * ) V_348 -> V_349 . V_40 ;
}
static int F_168 ( struct V_347 * V_348 )
{
struct V_350 * V_29 = & V_348 -> V_349 ;
struct V_11 * V_47 = F_40 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_169 ( struct V_347 * V_348 )
{
struct V_350 * V_29 = & V_348 -> V_349 ;
V_29 -> V_40 = NULL ;
}
static int F_170 ( struct V_347 * V_348 , int V_265 )
{
struct V_11 * V_212 = F_167 ( V_348 ) ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_149
F_28 ( & V_77 , V_88 , V_351 ) ;
V_77 . V_306 . V_307 . V_352 = V_348 -> V_349 . V_353 ;
#endif
V_14 = F_62 ( V_212 , V_265 , & V_77 ) ;
V_14 = F_4 ( L_16 , V_212 , V_265 , V_14 ) ;
return V_14 ;
}
static int F_171 ( struct V_347 * V_348 , int V_354 )
{
int V_177 ;
V_177 = F_164 ( V_354 ) ;
return F_170 ( V_348 , V_177 ) ;
}
static int F_172 ( struct V_347 * V_348 , int V_228 )
{
int V_177 ;
switch ( V_228 ) {
case V_355 :
case V_356 :
V_177 = V_4 ;
break;
case V_357 :
case V_358 :
case V_359 :
case V_360 :
V_177 = V_72 ;
break;
case V_361 :
case V_362 :
return 0 ;
default:
return - V_134 ;
}
return F_170 ( V_348 , V_177 ) ;
}
static int F_173 ( struct V_347 * V_348 , char T_8 * V_363 ,
int V_354 )
{
int V_177 ;
V_177 = F_164 ( V_354 ) ;
return F_170 ( V_348 , V_177 ) ;
}
static struct V_11 * F_174 ( struct V_364 * V_365 )
{
return (struct V_11 * ) V_365 -> V_366 . V_40 ;
}
static int F_175 ( struct V_364 * V_365 )
{
struct V_350 * V_29 = & V_365 -> V_366 ;
struct V_11 * V_47 = F_40 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_176 ( struct V_364 * V_365 )
{
struct V_350 * V_29 = & V_365 -> V_366 ;
V_29 -> V_40 = NULL ;
}
static int F_177 ( struct V_364 * V_365 , int V_265 )
{
struct V_11 * V_212 = F_174 ( V_365 ) ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_149
F_28 ( & V_77 , V_88 , V_351 ) ;
V_77 . V_306 . V_307 . V_352 = V_365 -> V_366 . V_353 ;
#endif
V_14 = F_62 ( V_212 , V_265 , & V_77 ) ;
V_14 = F_4 ( L_17 , V_212 , V_265 , V_14 ) ;
return V_14 ;
}
static int F_178 ( struct V_364 * V_365 , int V_367 )
{
int V_177 ;
V_177 = F_164 ( V_367 ) ;
return F_177 ( V_365 , V_177 ) ;
}
static int F_179 ( struct V_364 * V_365 , int V_228 )
{
int V_177 ;
switch ( V_228 ) {
case V_368 :
case V_369 :
case V_370 :
case V_371 :
case V_372 :
case V_355 :
case V_373 :
V_177 = V_4 ;
break;
case V_374 :
case V_375 :
case V_360 :
case V_357 :
V_177 = V_72 ;
break;
case V_361 :
case V_376 :
return 0 ;
default:
return - V_134 ;
}
return F_177 ( V_365 , V_177 ) ;
}
static int F_180 ( struct V_364 * V_365 , struct V_377 * V_378 ,
unsigned V_379 , int V_380 )
{
return F_177 ( V_365 , V_72 ) ;
}
static int F_181 ( struct V_381 * V_382 )
{
struct V_350 * V_383 = & V_382 -> V_384 ;
struct V_11 * V_47 = F_40 () ;
V_383 -> V_40 = V_47 ;
return 0 ;
}
static void F_182 ( struct V_381 * V_382 )
{
struct V_350 * V_383 = & V_382 -> V_384 ;
V_383 -> V_40 = NULL ;
}
static struct V_11 * F_183 ( struct V_381 * V_382 )
{
return (struct V_11 * ) V_382 -> V_384 . V_40 ;
}
static int F_184 ( struct V_381 * V_382 , int V_265 )
{
struct V_11 * V_385 = F_183 ( V_382 ) ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_149
F_28 ( & V_77 , V_88 , V_351 ) ;
V_77 . V_306 . V_307 . V_352 = V_382 -> V_384 . V_353 ;
#endif
V_14 = F_62 ( V_385 , V_265 , & V_77 ) ;
V_14 = F_4 ( L_18 , V_385 , V_265 , V_14 ) ;
return V_14 ;
}
static int F_185 ( struct V_381 * V_382 , int V_386 )
{
int V_177 ;
V_177 = F_164 ( V_386 ) ;
return F_184 ( V_382 , V_177 ) ;
}
static int F_186 ( struct V_381 * V_382 , int V_228 )
{
int V_177 ;
switch ( V_228 ) {
case V_355 :
case V_387 :
V_177 = V_4 ;
break;
case V_357 :
case V_360 :
V_177 = V_72 ;
break;
case V_361 :
case V_388 :
return 0 ;
default:
return - V_134 ;
}
return F_184 ( V_382 , V_177 ) ;
}
static int F_187 ( struct V_381 * V_382 , struct V_345 * V_346 ,
int V_386 )
{
int V_177 ;
V_177 = F_164 ( V_386 ) ;
return F_184 ( V_382 , V_177 ) ;
}
static int F_188 ( struct V_381 * V_382 , struct V_345 * V_346 ,
struct V_25 * V_389 , long type , int V_1 )
{
return F_184 ( V_382 , V_72 ) ;
}
static int F_189 ( struct V_350 * V_390 , short V_391 )
{
struct V_11 * V_392 = V_390 -> V_40 ;
int V_177 = F_164 ( V_391 ) ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_149
F_28 ( & V_77 , V_88 , V_351 ) ;
V_77 . V_306 . V_307 . V_352 = V_390 -> V_353 ;
#endif
V_14 = F_62 ( V_392 , V_177 , & V_77 ) ;
V_14 = F_4 ( L_19 , V_392 , V_177 , V_14 ) ;
return V_14 ;
}
static void F_190 ( struct V_350 * V_390 , T_4 * V_225 )
{
struct V_11 * V_392 = V_390 -> V_40 ;
* V_225 = V_392 -> V_226 ;
}
static void F_191 ( struct V_44 * V_393 , struct V_27 * V_27 )
{
struct V_93 * V_158 ;
struct V_95 * V_96 ;
struct V_28 * V_29 ;
struct V_11 * V_47 ;
struct V_11 * V_394 = F_40 () ;
struct V_11 * V_395 ;
char V_396 [ V_204 ] ;
int V_397 = 0 ;
int V_14 ;
struct V_44 * V_45 ;
if ( V_27 == NULL )
return;
V_29 = V_27 -> V_30 ;
F_192 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_31 & V_333 )
goto V_398;
V_158 = V_27 -> V_33 ;
V_96 = V_158 -> V_103 ;
V_395 = V_96 -> V_99 ;
if ( V_393 -> V_399 == V_393 ) {
switch ( V_158 -> V_216 ) {
case V_400 :
V_96 -> V_97 = & V_206 ;
V_96 -> V_99 = & V_206 ;
V_29 -> V_37 = V_96 -> V_97 ;
break;
case V_401 :
V_29 -> V_37 = F_40 () ;
break;
default:
V_29 -> V_37 = V_96 -> V_97 ;
break;
}
V_29 -> V_31 |= V_333 ;
goto V_398;
}
switch ( V_158 -> V_216 ) {
case V_402 :
case V_403 :
case V_217 :
case V_400 :
V_395 = & V_206 ;
break;
case V_404 :
V_395 = V_394 ;
break;
case V_405 :
break;
case V_401 :
V_395 = & V_206 ;
default:
if ( F_193 ( V_27 -> V_406 ) ) {
V_395 = & V_206 ;
break;
}
if ( V_27 -> V_48 -> V_49 == NULL )
break;
V_45 = F_194 ( V_393 ) ;
V_47 = F_13 ( V_198 , V_27 , V_45 ) ;
if ( ! F_195 ( V_47 ) )
V_395 = V_47 ;
if ( F_196 ( V_27 -> V_406 ) ) {
if ( V_29 -> V_31 & V_179 ) {
V_29 -> V_31 &= ~ V_179 ;
V_14 = V_27 -> V_48 -> V_407 ( V_45 ,
V_203 ,
V_205 , V_204 ,
0 ) ;
} else {
V_14 = V_27 -> V_48 -> V_49 ( V_45 ,
V_203 , V_396 ,
V_204 ) ;
if ( V_14 >= 0 && strncmp ( V_396 , V_205 ,
V_204 ) != 0 )
V_14 = - V_134 ;
}
if ( V_14 >= 0 )
V_397 = V_154 ;
}
V_47 = F_13 ( V_201 , V_27 , V_45 ) ;
if ( F_55 ( V_47 ) || V_47 == & V_206 ||
V_47 == & V_207 )
V_47 = NULL ;
V_29 -> V_22 = V_47 ;
V_47 = F_13 ( V_202 , V_27 , V_45 ) ;
if ( F_55 ( V_47 ) || V_47 == & V_206 ||
V_47 == & V_207 )
V_47 = NULL ;
V_29 -> V_209 = V_47 ;
F_197 ( V_45 ) ;
break;
}
if ( V_395 == NULL )
V_29 -> V_37 = V_394 ;
else
V_29 -> V_37 = V_395 ;
V_29 -> V_31 |= ( V_333 | V_397 ) ;
V_398:
F_198 ( & V_29 -> V_56 ) ;
return;
}
static int F_199 ( struct V_25 * V_117 , char * V_42 , char * * V_173 )
{
struct V_11 * V_47 = F_7 ( V_117 ) ;
char * V_106 ;
int V_408 ;
if ( strcmp ( V_42 , L_20 ) != 0 )
return - V_134 ;
V_106 = F_74 ( V_47 -> V_19 , V_52 ) ;
if ( V_106 == NULL )
return - V_53 ;
V_408 = strlen ( V_106 ) ;
* V_173 = V_106 ;
return V_408 ;
}
static int F_200 ( struct V_25 * V_117 , char * V_42 ,
void * V_173 , T_3 V_194 )
{
struct V_20 * V_21 ;
struct V_39 * V_261 ;
struct V_11 * V_47 ;
if ( V_117 != V_23 )
return - V_153 ;
if ( ! F_41 ( V_152 ) )
return - V_153 ;
if ( V_173 == NULL || V_194 == 0 || V_194 >= V_51 )
return - V_134 ;
if ( strcmp ( V_42 , L_20 ) != 0 )
return - V_134 ;
V_47 = F_16 ( V_173 , V_194 ) ;
if ( F_55 ( V_47 ) )
return F_56 ( V_47 ) ;
if ( V_47 == & V_207 )
return - V_153 ;
V_261 = F_201 () ;
if ( V_261 == NULL )
return - V_53 ;
V_21 = V_261 -> V_40 ;
V_21 -> V_22 = V_47 ;
F_202 ( V_261 ) ;
return V_194 ;
}
static int F_203 ( struct V_214 * V_214 ,
struct V_214 * V_409 , struct V_214 * V_410 )
{
struct V_11 * V_47 ;
struct V_11 * V_242 ;
struct V_211 * V_212 = V_214 -> V_219 ;
struct V_211 * V_411 = V_409 -> V_219 ;
struct V_211 * V_332 = V_410 -> V_219 ;
struct V_76 V_77 ;
int V_14 = 0 ;
#ifdef F_149
struct V_303 V_304 ;
#endif
if ( ! F_41 ( V_91 ) ) {
V_47 = V_212 -> V_223 ;
V_242 = V_411 -> V_221 ;
#ifdef F_149
F_150 ( & V_77 , V_88 , V_305 , & V_304 ) ;
F_204 ( & V_77 , V_409 ) ;
#endif
V_14 = V_248 ( V_47 , V_242 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_21 , V_47 , V_242 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_242 = V_411 -> V_223 ;
V_47 = V_212 -> V_221 ;
V_14 = V_248 ( V_242 , V_47 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_21 , V_242 , V_47 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_332 -> V_275 = V_212 -> V_223 ;
V_212 -> V_275 = V_411 -> V_223 ;
}
return V_14 ;
}
static int F_205 ( struct V_213 * V_214 , struct V_213 * V_409 )
{
struct V_211 * V_212 = V_214 -> V_218 -> V_219 ;
struct V_211 * V_411 = V_409 -> V_218 -> V_219 ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_149
struct V_303 V_304 ;
F_150 ( & V_77 , V_88 , V_305 , & V_304 ) ;
F_204 ( & V_77 , V_409 -> V_218 ) ;
#endif
if ( F_41 ( V_91 ) )
return 0 ;
V_14 = V_248 ( V_212 -> V_223 , V_411 -> V_221 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_22 , V_212 -> V_223 , V_411 -> V_221 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_206 ( struct V_213 * V_214 , struct V_412 * V_346 ,
int V_194 )
{
struct V_276 * V_277 = (struct V_276 * ) V_346 -> V_413 ;
#if F_162 ( V_340 )
struct V_287 * V_293 = (struct V_287 * ) V_346 -> V_413 ;
#endif
#ifdef F_163
struct V_211 * V_212 = V_214 -> V_218 -> V_219 ;
struct V_11 * V_341 ;
#endif
int V_14 = 0 ;
if ( V_277 == NULL )
return 0 ;
switch ( V_277 -> V_308 ) {
case V_414 :
V_14 = F_148 ( V_214 -> V_218 , V_277 ) ;
break;
case V_415 :
#ifdef F_163
V_341 = F_140 ( V_293 ) ;
if ( V_341 != NULL )
V_14 = F_151 ( V_212 -> V_223 , V_341 , V_293 ,
V_331 ) ;
#endif
#ifdef F_158
V_14 = F_155 ( V_214 -> V_218 , V_293 , V_416 ) ;
#endif
break;
}
return V_14 ;
}
static struct V_11 * F_207 ( struct V_417 * V_293 ,
struct V_211 * V_212 )
{
struct V_11 * V_47 ;
int V_294 = 0 ;
int V_418 ;
int V_419 ;
if ( ( V_293 -> V_155 & V_420 ) != 0 ) {
F_30 () ;
F_153 (skp, &smack_known_list, list) {
if ( V_293 -> V_421 . V_422 . V_423 != V_47 -> V_300 . V_421 . V_422 . V_423 )
continue;
if ( ( V_293 -> V_155 & V_424 ) == 0 ) {
if ( ( V_47 -> V_300 . V_155 &
V_424 ) == 0 )
V_294 = 1 ;
break;
}
for ( V_418 = - 1 , V_419 = - 1 ; V_418 == V_419 ; ) {
V_418 = F_208 ( V_293 -> V_421 . V_422 . V_425 ,
V_418 + 1 ) ;
V_419 = F_208 (
V_47 -> V_300 . V_421 . V_422 . V_425 ,
V_419 + 1 ) ;
if ( V_418 < 0 || V_419 < 0 )
break;
}
if ( V_418 == V_419 ) {
V_294 = 1 ;
break;
}
}
F_35 () ;
if ( V_294 )
return V_47 ;
if ( V_212 != NULL && V_212 -> V_221 == & V_206 )
return & V_207 ;
return & V_206 ;
}
if ( ( V_293 -> V_155 & V_426 ) != 0 ) {
V_47 = F_119 ( V_293 -> V_421 . V_225 ) ;
F_209 ( V_47 == NULL ) ;
return V_47 ;
}
return V_297 ;
}
static int F_210 ( struct V_427 * V_428 , struct V_287 * V_277 )
{
T_9 V_429 ;
int V_430 ;
int V_431 = - V_134 ;
struct V_432 V_433 ;
struct V_432 * V_434 ;
T_6 V_435 ;
struct V_436 V_437 , * V_438 ;
struct V_439 V_440 , * V_441 ;
struct V_442 V_443 , * V_444 ;
V_277 -> V_319 = 0 ;
V_430 = F_211 ( V_428 ) ;
V_434 = F_212 ( V_428 , V_430 , sizeof( V_433 ) , & V_433 ) ;
if ( V_434 == NULL )
return - V_134 ;
V_277 -> V_289 = V_434 -> V_322 ;
V_429 = V_434 -> V_429 ;
V_430 += sizeof( V_433 ) ;
V_430 = F_213 ( V_428 , V_430 , & V_429 , & V_435 ) ;
if ( V_430 < 0 )
return - V_134 ;
V_431 = V_429 ;
switch ( V_431 ) {
case V_445 :
V_438 = F_212 ( V_428 , V_430 , sizeof( V_437 ) , & V_437 ) ;
if ( V_438 != NULL )
V_277 -> V_319 = V_438 -> V_446 ;
break;
case V_447 :
V_441 = F_212 ( V_428 , V_430 , sizeof( V_440 ) , & V_440 ) ;
if ( V_441 != NULL )
V_277 -> V_319 = V_441 -> V_446 ;
break;
case V_448 :
V_444 = F_212 ( V_428 , V_430 , sizeof( V_443 ) , & V_443 ) ;
if ( V_444 != NULL )
V_277 -> V_319 = V_444 -> V_449 ;
break;
}
return V_431 ;
}
static int F_214 ( struct V_214 * V_218 , struct V_427 * V_428 )
{
struct V_417 V_450 ;
struct V_211 * V_212 = V_218 -> V_219 ;
struct V_11 * V_47 = NULL ;
int V_14 = 0 ;
struct V_76 V_77 ;
#ifdef F_149
struct V_303 V_304 ;
#endif
#if F_162 ( V_340 )
struct V_287 V_451 ;
int V_431 ;
#endif
switch ( V_218 -> V_299 ) {
case V_334 :
#ifdef F_215
if ( V_428 && V_428 -> V_452 != 0 ) {
V_47 = F_119 ( V_428 -> V_452 ) ;
goto V_453;
}
#endif
F_216 ( & V_450 ) ;
V_14 = F_217 ( V_428 , V_218 -> V_299 , & V_450 ) ;
if ( V_14 == 0 )
V_47 = F_207 ( & V_450 , V_212 ) ;
else
V_47 = V_297 ;
F_218 ( & V_450 ) ;
#ifdef F_215
V_453:
#endif
#ifdef F_149
F_150 ( & V_77 , V_88 , V_305 , & V_304 ) ;
V_77 . V_306 . V_307 . V_304 -> V_273 = V_218 -> V_299 ;
V_77 . V_306 . V_307 . V_304 -> V_454 = V_428 -> V_455 ;
F_219 ( V_428 , & V_77 . V_306 , NULL ) ;
#endif
V_14 = V_248 ( V_47 , V_212 -> V_221 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_23 , V_47 , V_212 -> V_221 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_220 ( V_428 , V_14 , 0 ) ;
break;
#if F_162 ( V_340 )
case V_318 :
V_431 = F_210 ( V_428 , & V_451 ) ;
if ( V_431 != V_447 && V_431 != V_445 )
break;
#ifdef F_163
if ( V_428 && V_428 -> V_452 != 0 )
V_47 = F_119 ( V_428 -> V_452 ) ;
else
V_47 = F_140 ( & V_451 ) ;
if ( V_47 == NULL )
V_47 = V_297 ;
#ifdef F_149
F_150 ( & V_77 , V_88 , V_305 , & V_304 ) ;
V_77 . V_306 . V_307 . V_304 -> V_273 = V_218 -> V_299 ;
V_77 . V_306 . V_307 . V_304 -> V_454 = V_428 -> V_455 ;
F_221 ( V_428 , & V_77 . V_306 , NULL ) ;
#endif
V_14 = V_248 ( V_47 , V_212 -> V_221 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_24 , V_47 , V_212 -> V_221 ,
V_5 , V_14 ) ;
#endif
#ifdef F_158
V_14 = F_155 ( V_218 , & V_451 , V_320 ) ;
#endif
break;
#endif
}
return V_14 ;
}
static int F_222 ( struct V_213 * V_214 ,
char T_8 * V_456 ,
int T_8 * V_457 , unsigned V_174 )
{
struct V_211 * V_212 ;
char * V_458 = L_25 ;
int V_408 = 1 ;
int V_14 = 0 ;
V_212 = V_214 -> V_218 -> V_219 ;
if ( V_212 -> V_275 != NULL ) {
V_458 = V_212 -> V_275 -> V_19 ;
V_408 = strlen ( V_458 ) + 1 ;
}
if ( V_408 > V_174 )
V_14 = - V_459 ;
else if ( F_223 ( V_456 , V_458 , V_408 ) != 0 )
V_14 = - V_460 ;
if ( F_224 ( V_408 , V_457 ) != 0 )
V_14 = - V_460 ;
return V_14 ;
}
static int F_225 ( struct V_213 * V_214 ,
struct V_427 * V_428 , T_4 * V_225 )
{
struct V_417 V_450 ;
struct V_211 * V_212 = NULL ;
struct V_11 * V_47 ;
int V_273 = V_461 ;
T_4 V_2 = 0 ;
int V_14 ;
if ( V_428 != NULL ) {
if ( V_428 -> V_336 == F_226 ( V_462 ) )
V_273 = V_334 ;
#if F_162 ( V_340 )
else if ( V_428 -> V_336 == F_226 ( V_463 ) )
V_273 = V_318 ;
#endif
}
if ( V_273 == V_461 && V_214 != NULL )
V_273 = V_214 -> V_218 -> V_299 ;
switch ( V_273 ) {
case V_464 :
V_212 = V_214 -> V_218 -> V_219 ;
V_2 = V_212 -> V_223 -> V_226 ;
break;
case V_334 :
#ifdef F_215
V_2 = V_428 -> V_452 ;
if ( V_2 != 0 )
break;
#endif
if ( V_214 != NULL && V_214 -> V_218 != NULL )
V_212 = V_214 -> V_218 -> V_219 ;
F_216 ( & V_450 ) ;
V_14 = F_217 ( V_428 , V_273 , & V_450 ) ;
if ( V_14 == 0 ) {
V_47 = F_207 ( & V_450 , V_212 ) ;
V_2 = V_47 -> V_226 ;
}
F_218 ( & V_450 ) ;
break;
case V_318 :
#ifdef F_163
V_2 = V_428 -> V_452 ;
#endif
break;
}
* V_225 = V_2 ;
if ( V_2 == 0 )
return - V_134 ;
return 0 ;
}
static void F_227 ( struct V_214 * V_218 , struct V_213 * V_465 )
{
struct V_211 * V_212 ;
struct V_11 * V_47 = F_40 () ;
if ( V_218 == NULL ||
( V_218 -> V_299 != V_334 && V_218 -> V_299 != V_318 ) )
return;
V_212 = V_218 -> V_219 ;
V_212 -> V_221 = V_47 ;
V_212 -> V_223 = V_47 ;
}
static int F_228 ( struct V_214 * V_218 , struct V_427 * V_428 ,
struct V_466 * V_467 )
{
T_10 V_273 = V_218 -> V_299 ;
struct V_11 * V_47 ;
struct V_211 * V_212 = V_218 -> V_219 ;
struct V_417 V_450 ;
struct V_276 V_468 ;
struct V_469 * V_470 ;
struct V_11 * V_471 ;
int V_14 ;
struct V_76 V_77 ;
#ifdef F_149
struct V_303 V_304 ;
#endif
#if F_162 ( V_340 )
if ( V_273 == V_318 ) {
if ( V_428 -> V_336 == F_226 ( V_462 ) )
V_273 = V_334 ;
else
return 0 ;
}
#endif
#ifdef F_215
if ( V_428 && V_428 -> V_452 != 0 ) {
V_47 = F_119 ( V_428 -> V_452 ) ;
goto V_453;
}
#endif
F_216 ( & V_450 ) ;
V_14 = F_217 ( V_428 , V_273 , & V_450 ) ;
if ( V_14 == 0 )
V_47 = F_207 ( & V_450 , V_212 ) ;
else
V_47 = & V_472 ;
F_218 ( & V_450 ) ;
#ifdef F_215
V_453:
#endif
#ifdef F_149
F_150 ( & V_77 , V_88 , V_305 , & V_304 ) ;
V_77 . V_306 . V_307 . V_304 -> V_273 = V_273 ;
V_77 . V_306 . V_307 . V_304 -> V_454 = V_428 -> V_455 ;
F_219 ( V_428 , & V_77 . V_306 , NULL ) ;
#endif
V_14 = V_248 ( V_47 , V_212 -> V_221 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_26 , V_47 , V_212 -> V_221 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_467 -> V_473 = V_47 -> V_226 ;
V_470 = F_229 ( V_428 ) ;
V_468 . V_282 . V_283 = V_470 -> V_322 ;
F_30 () ;
V_471 = F_137 ( & V_468 ) ;
F_35 () ;
if ( V_471 == NULL )
V_14 = F_230 ( V_467 , & V_47 -> V_300 ) ;
else
F_231 ( V_467 ) ;
return V_14 ;
}
static void F_232 ( struct V_214 * V_218 ,
const struct V_466 * V_467 )
{
struct V_211 * V_212 = V_218 -> V_219 ;
struct V_11 * V_47 ;
if ( V_467 -> V_473 != 0 ) {
V_47 = F_119 ( V_467 -> V_473 ) ;
V_212 -> V_275 = V_47 ;
} else
V_212 -> V_275 = NULL ;
}
static int F_233 ( struct V_474 * V_474 , const struct V_39 * V_39 ,
unsigned long V_155 )
{
struct V_11 * V_47 = F_32 ( V_39 -> V_40 ) ;
V_474 -> V_40 = V_47 ;
return 0 ;
}
static void F_234 ( struct V_474 * V_474 )
{
V_474 -> V_40 = NULL ;
}
static int F_235 ( T_11 V_475 ,
const struct V_39 * V_39 , unsigned V_476 )
{
struct V_474 * V_477 ;
struct V_76 V_77 ;
struct V_11 * V_253 = F_32 ( V_39 -> V_40 ) ;
int V_478 = 0 ;
int V_14 ;
V_477 = F_236 ( V_475 ) ;
if ( V_477 == NULL )
return - V_134 ;
if ( V_477 -> V_40 == NULL )
return 0 ;
if ( V_253 == NULL )
return - V_85 ;
#ifdef F_149
F_28 ( & V_77 , V_88 , V_479 ) ;
V_77 . V_306 . V_307 . V_480 . V_474 = V_477 -> V_481 ;
V_77 . V_306 . V_307 . V_480 . V_482 = V_477 -> V_483 ;
#endif
if ( V_476 & V_484 )
V_478 = V_4 ;
if ( V_476 & ( V_485 | V_486 | V_487 ) )
V_478 = V_5 ;
V_14 = V_248 ( V_253 , V_477 -> V_40 , V_478 , & V_77 ) ;
V_14 = F_2 ( L_27 , V_253 , V_477 -> V_40 , V_478 , V_14 ) ;
return V_14 ;
}
static int F_237 ( struct V_474 * V_474 , char * * V_488 )
{
struct V_11 * V_47 = V_474 -> V_40 ;
T_3 V_489 ;
char * V_490 ;
if ( V_474 -> V_40 == NULL ) {
* V_488 = NULL ;
return 0 ;
}
V_490 = F_74 ( V_47 -> V_19 , V_52 ) ;
if ( V_490 == NULL )
return - V_53 ;
V_489 = strlen ( V_490 ) + 1 ;
* V_488 = V_490 ;
return V_489 ;
}
static int F_238 ( T_4 V_491 , T_4 V_492 , char * V_493 , void * * V_494 )
{
struct V_11 * V_47 ;
char * * V_495 = ( char * * ) V_494 ;
* V_495 = NULL ;
if ( V_491 != V_496 && V_491 != V_497 )
return - V_134 ;
if ( V_492 != V_498 && V_492 != V_499 )
return - V_134 ;
V_47 = F_16 ( V_493 , 0 ) ;
if ( F_55 ( V_47 ) )
return F_56 ( V_47 ) ;
* V_495 = V_47 -> V_19 ;
return 0 ;
}
static int F_239 ( struct V_500 * V_501 )
{
struct V_502 * V_503 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_501 -> V_504 ; V_3 ++ ) {
V_503 = & V_501 -> V_505 [ V_3 ] ;
if ( V_503 -> type == V_496 || V_503 -> type == V_497 )
return 1 ;
}
return 0 ;
}
static int F_240 ( T_4 V_225 , T_4 V_491 , T_4 V_492 , void * V_494 ,
struct V_506 * V_507 )
{
struct V_11 * V_47 ;
char * V_495 = V_494 ;
if ( F_108 ( ! V_495 ) ) {
F_241 ( 1 , L_28 ) ;
return - V_247 ;
}
if ( V_491 != V_496 && V_491 != V_497 )
return 0 ;
V_47 = F_119 ( V_225 ) ;
if ( V_492 == V_498 )
return ( V_495 == V_47 -> V_19 ) ;
if ( V_492 == V_499 )
return ( V_495 != V_47 -> V_19 ) ;
return 0 ;
}
static void F_242 ( void * V_494 )
{
}
static int F_243 ( const char * V_42 )
{
return ( strcmp ( V_42 , V_178 ) == 0 ) ;
}
static int F_244 ( T_4 V_225 , char * * V_508 , T_4 * V_509 )
{
struct V_11 * V_47 = F_119 ( V_225 ) ;
if ( V_508 )
* V_508 = V_47 -> V_19 ;
* V_509 = strlen ( V_47 -> V_19 ) ;
return 0 ;
}
static int F_245 ( const char * V_508 , T_4 V_509 , T_4 * V_225 )
{
struct V_11 * V_47 = F_246 ( V_508 ) ;
if ( V_47 )
* V_225 = V_47 -> V_226 ;
else
* V_225 = 0 ;
return 0 ;
}
static void F_247 ( char * V_508 , T_4 V_509 )
{
}
static int F_248 ( struct V_27 * V_27 , void * V_510 , T_4 V_511 )
{
return F_156 ( V_27 , V_178 , V_510 , V_511 , 0 ) ;
}
static int F_249 ( struct V_44 * V_44 , void * V_510 , T_4 V_511 )
{
return F_250 ( V_44 , V_198 , V_510 , V_511 , 0 ) ;
}
static int F_251 ( struct V_27 * V_27 , void * * V_510 , T_4 * V_511 )
{
int V_174 = 0 ;
V_174 = F_91 ( V_27 , V_178 , V_510 , true ) ;
if ( V_174 < 0 )
return V_174 ;
* V_511 = V_174 ;
return 0 ;
}
static T_12 void F_252 ( void )
{
F_20 ( & V_472 . V_62 ) ;
F_20 ( & V_102 . V_62 ) ;
F_20 ( & V_98 . V_62 ) ;
F_20 ( & V_206 . V_62 ) ;
F_20 ( & V_208 . V_62 ) ;
F_20 ( & V_207 . V_62 ) ;
F_22 ( & V_472 . V_61 ) ;
F_22 ( & V_102 . V_61 ) ;
F_22 ( & V_206 . V_61 ) ;
F_22 ( & V_98 . V_61 ) ;
F_22 ( & V_208 . V_61 ) ;
F_22 ( & V_207 . V_61 ) ;
F_253 ( & V_472 ) ;
F_253 ( & V_102 ) ;
F_253 ( & V_206 ) ;
F_253 ( & V_98 ) ;
F_253 ( & V_208 ) ;
F_253 ( & V_207 ) ;
}
static T_12 int F_254 ( void )
{
struct V_39 * V_39 ;
struct V_20 * V_21 ;
if ( ! F_255 ( L_29 ) )
return 0 ;
V_512 = 1 ;
V_54 = F_256 ( V_28 , 0 ) ;
if ( ! V_54 )
return - V_53 ;
V_21 = F_21 ( & V_98 , & V_98 ,
V_52 ) ;
if ( V_21 == NULL ) {
F_257 ( V_54 ) ;
return - V_53 ;
}
F_3 ( L_30 ) ;
#ifdef F_215
F_3 ( L_31 ) ;
#endif
#ifdef F_158
F_3 ( L_32 ) ;
#endif
#ifdef F_163
F_3 ( L_33 ) ;
#endif
V_39 = (struct V_39 * ) V_23 -> V_39 ;
V_39 -> V_40 = V_21 ;
F_252 () ;
F_258 ( V_513 , F_259 ( V_513 ) ) ;
return 0 ;
}

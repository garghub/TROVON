static char * F_1 ( const char * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_6 ;
char * V_7 ;
char * V_8 = NULL ;
if ( V_3 -> V_9 -> V_10 == NULL )
return NULL ;
V_7 = F_2 ( V_11 , V_12 ) ;
if ( V_7 == NULL )
return NULL ;
V_6 = V_3 -> V_9 -> V_10 ( V_5 , V_1 , V_7 , V_11 ) ;
if ( V_6 > 0 )
V_8 = F_3 ( V_7 , V_6 ) ;
F_4 ( V_7 ) ;
return V_8 ;
}
struct V_13 * F_5 ( char * V_14 )
{
struct V_13 * V_15 ;
V_15 = F_2 ( sizeof( struct V_13 ) , V_16 ) ;
if ( V_15 == NULL )
return NULL ;
V_15 -> V_17 = V_14 ;
V_15 -> V_18 = 0 ;
F_6 ( & V_15 -> V_19 ) ;
return V_15 ;
}
static struct V_20 * F_7 ( char * V_21 , char * V_22 , T_1 V_23 )
{
struct V_20 * V_24 ;
V_24 = F_2 ( sizeof( struct V_20 ) , V_23 ) ;
if ( V_24 == NULL )
return NULL ;
V_24 -> V_25 = V_21 ;
V_24 -> V_26 = V_22 ;
F_8 ( & V_24 -> V_27 ) ;
F_6 ( & V_24 -> V_28 ) ;
return V_24 ;
}
static int F_9 ( struct V_29 * V_30 , struct V_29 * V_31 ,
T_1 V_23 )
{
struct V_32 * V_33 ;
struct V_32 * V_34 ;
int V_6 = 0 ;
F_8 ( V_30 ) ;
F_10 (orp, ohead, list) {
V_33 = F_2 ( sizeof( struct V_32 ) , V_23 ) ;
if ( V_33 == NULL ) {
V_6 = - V_35 ;
break;
}
* V_33 = * V_34 ;
F_11 ( & V_33 -> V_36 , V_30 ) ;
}
return V_6 ;
}
static int F_12 ( struct V_37 * V_38 , unsigned int V_39 )
{
int V_6 ;
struct V_40 V_41 ;
char * V_24 ;
V_6 = F_13 ( V_38 , V_39 ) ;
if ( V_6 != 0 )
return V_6 ;
V_24 = F_14 ( F_15 ( V_38 ) ) ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_17 ( & V_41 , V_38 ) ;
V_6 = F_18 ( V_24 , V_44 , & V_41 ) ;
return V_6 ;
}
static int F_19 ( struct V_37 * V_45 )
{
int V_6 ;
struct V_40 V_41 ;
char * V_24 ;
V_6 = F_20 ( V_45 ) ;
if ( V_6 != 0 )
return V_6 ;
V_24 = F_14 ( F_15 ( V_45 ) ) ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_17 ( & V_41 , V_45 ) ;
V_6 = F_18 ( V_24 , V_44 , & V_41 ) ;
return V_6 ;
}
static int F_21 ( int V_46 )
{
int V_6 = 0 ;
char * V_47 = F_22 () ;
if ( F_23 ( V_48 ) )
return 0 ;
if ( V_47 != V_49 . V_50 )
V_6 = - V_51 ;
return V_6 ;
}
static int F_24 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
V_55 = F_2 ( sizeof( struct V_54 ) , V_12 ) ;
if ( V_55 == NULL )
return - V_35 ;
V_55 -> V_56 = V_49 . V_50 ;
V_55 -> V_57 = V_49 . V_50 ;
V_55 -> V_58 = V_49 . V_50 ;
V_55 -> V_59 = V_60 . V_50 ;
V_55 -> V_61 = 0 ;
V_53 -> V_62 = V_55 ;
return 0 ;
}
static void F_25 ( struct V_52 * V_53 )
{
F_4 ( V_53 -> V_62 ) ;
V_53 -> V_62 = NULL ;
}
static int F_26 ( char * V_63 , char * V_64 )
{
char * V_65 , * V_66 , * V_67 , * V_5 ;
V_67 = ( char * ) F_27 ( V_12 ) ;
if ( V_67 == NULL )
return - V_35 ;
for ( V_65 = V_63 , V_66 = V_63 ; V_66 != NULL ; V_65 = V_66 + 1 ) {
if ( strstr ( V_65 , V_68 ) == V_65 )
V_5 = V_64 ;
else if ( strstr ( V_65 , V_69 ) == V_65 )
V_5 = V_64 ;
else if ( strstr ( V_65 , V_70 ) == V_65 )
V_5 = V_64 ;
else if ( strstr ( V_65 , V_71 ) == V_65 )
V_5 = V_64 ;
else
V_5 = V_67 ;
V_66 = strchr ( V_65 , ',' ) ;
if ( V_66 != NULL )
* V_66 = '\0' ;
if ( * V_5 != '\0' )
strcat ( V_5 , L_1 ) ;
strcat ( V_5 , V_65 ) ;
}
strcpy ( V_63 , V_67 ) ;
F_28 ( ( unsigned long ) V_67 ) ;
return 0 ;
}
static int F_29 ( struct V_52 * V_53 , int V_72 , void * V_73 )
{
struct V_4 * V_74 = V_53 -> V_75 ;
struct V_2 * V_2 = V_74 -> V_76 ;
struct V_54 * V_47 = V_53 -> V_62 ;
struct V_13 * V_15 ;
char * V_77 ;
char * V_66 ;
char * V_78 ;
if ( V_47 -> V_61 != 0 )
return 0 ;
V_47 -> V_61 = 1 ;
for ( V_77 = V_73 ; V_77 != NULL ; V_77 = V_66 ) {
V_66 = strchr ( V_77 , ',' ) ;
if ( V_66 != NULL )
* V_66 ++ = '\0' ;
if ( strncmp ( V_77 , V_70 , strlen ( V_70 ) ) == 0 ) {
V_77 += strlen ( V_70 ) ;
V_78 = F_3 ( V_77 , 0 ) ;
if ( V_78 != NULL )
V_47 -> V_59 = V_78 ;
} else if ( strncmp ( V_77 , V_69 , strlen ( V_69 ) ) == 0 ) {
V_77 += strlen ( V_69 ) ;
V_78 = F_3 ( V_77 , 0 ) ;
if ( V_78 != NULL )
V_47 -> V_58 = V_78 ;
} else if ( strncmp ( V_77 , V_68 ,
strlen ( V_68 ) ) == 0 ) {
V_77 += strlen ( V_68 ) ;
V_78 = F_3 ( V_77 , 0 ) ;
if ( V_78 != NULL )
V_47 -> V_57 = V_78 ;
} else if ( strncmp ( V_77 , V_71 , strlen ( V_71 ) ) == 0 ) {
V_77 += strlen ( V_71 ) ;
V_78 = F_3 ( V_77 , 0 ) ;
if ( V_78 != NULL )
V_47 -> V_56 = V_78 ;
}
}
V_15 = V_2 -> V_79 ;
if ( V_15 == NULL )
V_2 -> V_79 = F_5 ( V_47 -> V_56 ) ;
else
V_15 -> V_17 = V_47 -> V_56 ;
return 0 ;
}
static int F_30 ( struct V_4 * V_4 )
{
struct V_54 * V_80 = V_4 -> V_81 -> V_62 ;
int V_6 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
V_6 = F_18 ( V_80 -> V_58 , V_83 , & V_41 ) ;
return V_6 ;
}
static int F_32 ( const char * V_84 , struct V_85 * V_85 ,
const char * type , unsigned long V_72 , void * V_73 )
{
struct V_54 * V_80 = V_85 -> V_4 -> V_81 -> V_62 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_86 ) ;
F_33 ( & V_41 , * V_85 ) ;
return F_18 ( V_80 -> V_58 , V_87 , & V_41 ) ;
}
static int F_34 ( struct V_88 * V_89 , int V_72 )
{
struct V_54 * V_80 ;
struct V_40 V_41 ;
struct V_85 V_85 ;
V_85 . V_4 = V_89 -> V_90 ;
V_85 . V_89 = V_89 ;
F_16 ( & V_41 , V_42 , V_86 ) ;
F_33 ( & V_41 , V_85 ) ;
V_80 = V_85 . V_4 -> V_81 -> V_62 ;
return F_18 ( V_80 -> V_58 , V_87 , & V_41 ) ;
}
static int F_35 ( struct V_91 * V_92 )
{
struct V_2 * V_2 = V_92 -> V_93 -> V_94 . V_4 -> V_76 ;
struct V_20 * V_95 = V_92 -> V_96 -> V_97 ;
struct V_13 * V_15 ;
int V_6 ;
V_6 = F_36 ( V_92 ) ;
if ( V_6 != 0 )
return V_6 ;
if ( V_92 -> V_98 )
return 0 ;
V_15 = V_2 -> V_79 ;
if ( V_15 -> V_25 == NULL || V_15 -> V_25 == V_95 -> V_25 )
return 0 ;
if ( V_92 -> V_99 )
return - V_100 ;
V_95 -> V_25 = V_15 -> V_25 ;
V_92 -> V_101 |= V_102 ;
return 0 ;
}
static void F_37 ( struct V_91 * V_92 )
{
struct V_20 * V_95 = V_92 -> V_96 -> V_97 ;
if ( V_95 -> V_25 != V_95 -> V_26 )
V_103 -> V_104 = 0 ;
}
static int F_38 ( struct V_91 * V_92 )
{
struct V_20 * V_24 = F_39 () ;
int V_105 = F_40 ( V_92 ) ;
if ( ! V_105 && ( V_24 -> V_25 != V_24 -> V_26 ) )
V_105 = 1 ;
return V_105 ;
}
static int F_41 ( struct V_2 * V_2 )
{
V_2 -> V_79 = F_5 ( F_22 () ) ;
if ( V_2 -> V_79 == NULL )
return - V_35 ;
return 0 ;
}
static void F_42 ( struct V_2 * V_2 )
{
F_4 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
}
static int F_43 ( struct V_2 * V_2 , struct V_2 * V_106 ,
const struct V_107 * V_107 , char * * V_1 ,
void * * V_108 , T_2 * V_109 )
{
struct V_110 * V_111 ;
struct V_13 * V_112 = V_2 -> V_79 ;
char * V_113 = F_22 () ;
char * V_15 = F_44 ( V_2 ) ;
char * V_114 = F_44 ( V_106 ) ;
int V_115 ;
if ( V_1 ) {
* V_1 = F_45 ( V_116 , V_16 ) ;
if ( * V_1 == NULL )
return - V_35 ;
}
if ( V_108 ) {
V_111 = F_46 ( V_113 ) ;
F_47 () ;
V_115 = F_48 ( V_113 , V_114 , & V_111 -> V_27 ) ;
F_49 () ;
if ( V_115 > 0 && ( ( V_115 & V_117 ) != 0 ) &&
F_50 ( V_106 ) ) {
V_15 = V_114 ;
V_112 -> V_18 |= V_118 ;
}
* V_108 = F_45 ( V_15 , V_16 ) ;
if ( * V_108 == NULL )
return - V_35 ;
}
if ( V_109 )
* V_109 = strlen ( V_15 ) + 1 ;
return 0 ;
}
static int F_51 ( struct V_4 * V_119 , struct V_2 * V_106 ,
struct V_4 * V_120 )
{
char * V_15 ;
struct V_40 V_41 ;
int V_6 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_119 ) ;
V_15 = F_44 ( V_119 -> V_76 ) ;
V_6 = F_18 ( V_15 , V_87 , & V_41 ) ;
if ( V_6 == 0 && V_120 -> V_76 != NULL ) {
V_15 = F_44 ( V_120 -> V_76 ) ;
F_31 ( & V_41 , V_120 ) ;
V_6 = F_18 ( V_15 , V_87 , & V_41 ) ;
}
return V_6 ;
}
static int F_52 ( struct V_2 * V_106 , struct V_4 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_76 ;
struct V_40 V_41 ;
int V_6 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
V_6 = F_18 ( F_44 ( V_3 ) , V_87 , & V_41 ) ;
if ( V_6 == 0 ) {
F_31 ( & V_41 , NULL ) ;
F_53 ( & V_41 , V_106 ) ;
V_6 = F_18 ( F_44 ( V_106 ) , V_87 , & V_41 ) ;
}
return V_6 ;
}
static int F_54 ( struct V_2 * V_106 , struct V_4 * V_4 )
{
struct V_40 V_41 ;
int V_6 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
V_6 = F_18 ( F_44 ( V_4 -> V_76 ) , V_87 , & V_41 ) ;
if ( V_6 == 0 ) {
F_31 ( & V_41 , NULL ) ;
F_53 ( & V_41 , V_106 ) ;
V_6 = F_18 ( F_44 ( V_106 ) , V_87 , & V_41 ) ;
}
return V_6 ;
}
static int F_55 ( struct V_2 * V_121 ,
struct V_4 * V_119 ,
struct V_2 * V_122 ,
struct V_4 * V_120 )
{
int V_6 ;
char * V_15 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_119 ) ;
V_15 = F_44 ( V_119 -> V_76 ) ;
V_6 = F_18 ( V_15 , V_44 , & V_41 ) ;
if ( V_6 == 0 && V_120 -> V_76 != NULL ) {
V_15 = F_44 ( V_120 -> V_76 ) ;
F_31 ( & V_41 , V_120 ) ;
V_6 = F_18 ( V_15 , V_44 , & V_41 ) ;
}
return V_6 ;
}
static int F_56 ( struct V_2 * V_2 , int V_123 )
{
struct V_40 V_41 ;
int V_124 = V_123 & V_125 ;
V_123 &= ( V_83 | V_87 | V_126 | V_127 ) ;
if ( V_123 == 0 )
return 0 ;
if ( V_124 )
return - V_128 ;
F_16 ( & V_41 , V_42 , V_129 ) ;
F_53 ( & V_41 , V_2 ) ;
return F_18 ( F_44 ( V_2 ) , V_123 , & V_41 ) ;
}
static int F_57 ( struct V_4 * V_4 , struct V_130 * V_130 )
{
struct V_40 V_41 ;
if ( V_130 -> V_131 & V_132 )
return 0 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
return F_18 ( F_44 ( V_4 -> V_76 ) , V_87 , & V_41 ) ;
}
static int F_58 ( struct V_88 * V_89 , struct V_4 * V_4 )
{
struct V_40 V_41 ;
struct V_85 V_85 ;
V_85 . V_4 = V_4 ;
V_85 . V_89 = V_89 ;
F_16 ( & V_41 , V_42 , V_86 ) ;
F_33 ( & V_41 , V_85 ) ;
return F_18 ( F_44 ( V_4 -> V_76 ) , V_83 , & V_41 ) ;
}
static int F_59 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_108 , T_2 V_133 , int V_72 )
{
struct V_40 V_41 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_134 ) == 0 ||
strcmp ( V_1 , V_135 ) == 0 ||
strcmp ( V_1 , V_136 ) == 0 ||
strcmp ( V_1 , V_137 ) == 0 ||
strcmp ( V_1 , V_138 ) == 0 ) {
if ( ! F_23 ( V_139 ) )
V_6 = - V_100 ;
if ( V_133 == 0 || V_133 >= V_11 ||
F_3 ( V_108 , V_133 ) == NULL )
V_6 = - V_140 ;
} else if ( strcmp ( V_1 , V_141 ) == 0 ) {
if ( ! F_23 ( V_139 ) )
V_6 = - V_100 ;
if ( V_133 != V_142 ||
strncmp ( V_108 , V_143 , V_142 ) != 0 )
V_6 = - V_140 ;
} else
V_6 = F_60 ( V_4 , V_1 , V_108 , V_133 , V_72 ) ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_18 ( F_44 ( V_4 -> V_76 ) , V_87 , & V_41 ) ;
return V_6 ;
}
static void F_61 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_108 , T_2 V_133 , int V_72 )
{
char * V_78 ;
struct V_13 * V_15 = V_4 -> V_76 -> V_79 ;
if ( strcmp ( V_1 , V_134 ) == 0 ) {
V_78 = F_3 ( V_108 , V_133 ) ;
if ( V_78 != NULL )
V_15 -> V_17 = V_78 ;
else
V_15 -> V_17 = V_144 . V_50 ;
} else if ( strcmp ( V_1 , V_137 ) == 0 ) {
V_78 = F_3 ( V_108 , V_133 ) ;
if ( V_78 != NULL )
V_15 -> V_25 = V_78 ;
else
V_15 -> V_25 = V_144 . V_50 ;
} else if ( strcmp ( V_1 , V_138 ) == 0 ) {
V_78 = F_3 ( V_108 , V_133 ) ;
if ( V_78 != NULL )
V_15 -> V_145 = V_78 ;
else
V_15 -> V_145 = V_144 . V_50 ;
} else if ( strcmp ( V_1 , V_141 ) == 0 )
V_15 -> V_18 |= V_146 ;
return;
}
static int F_62 ( struct V_4 * V_4 , const char * V_1 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
return F_18 ( F_44 ( V_4 -> V_76 ) , V_83 , & V_41 ) ;
}
static int F_63 ( struct V_4 * V_4 , const char * V_1 )
{
struct V_13 * V_15 ;
struct V_40 V_41 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_134 ) == 0 ||
strcmp ( V_1 , V_135 ) == 0 ||
strcmp ( V_1 , V_136 ) == 0 ||
strcmp ( V_1 , V_137 ) == 0 ||
strcmp ( V_1 , V_141 ) == 0 ||
strcmp ( V_1 , V_138 ) ) {
if ( ! F_23 ( V_139 ) )
V_6 = - V_100 ;
} else
V_6 = F_64 ( V_4 , V_1 ) ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_18 ( F_44 ( V_4 -> V_76 ) , V_87 , & V_41 ) ;
if ( V_6 == 0 ) {
V_15 = V_4 -> V_76 -> V_79 ;
V_15 -> V_25 = NULL ;
V_15 -> V_145 = NULL ;
}
return V_6 ;
}
static int F_65 ( const struct V_2 * V_2 ,
const char * V_1 , void * * V_7 ,
bool V_147 )
{
struct V_148 * V_149 ;
struct V_150 * V_151 ;
struct V_52 * V_80 ;
struct V_2 * V_3 = (struct V_2 * ) V_2 ;
char * V_15 ;
int V_152 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_116 ) == 0 ) {
V_15 = F_44 ( V_2 ) ;
V_152 = strlen ( V_15 ) + 1 ;
* V_7 = V_15 ;
return V_152 ;
}
V_80 = V_3 -> V_153 ;
if ( V_80 -> V_154 != V_155 )
return - V_156 ;
V_151 = F_66 ( V_3 ) ;
if ( V_151 == NULL || V_151 -> V_157 == NULL )
return - V_156 ;
V_149 = V_151 -> V_157 -> V_158 ;
if ( strcmp ( V_1 , V_159 ) == 0 )
V_15 = V_149 -> V_160 ;
else if ( strcmp ( V_1 , V_161 ) == 0 )
V_15 = V_149 -> V_162 ;
else
return - V_156 ;
V_152 = strlen ( V_15 ) + 1 ;
if ( V_6 == 0 ) {
* V_7 = V_15 ;
V_6 = V_152 ;
}
return V_6 ;
}
static int F_67 ( struct V_2 * V_2 , char * V_7 ,
T_2 V_163 )
{
int V_109 = strlen ( V_134 ) ;
if ( V_7 != NULL && V_109 <= V_163 ) {
memcpy ( V_7 , V_134 , V_109 ) ;
return V_109 ;
}
return - V_140 ;
}
static void F_68 ( const struct V_2 * V_2 , T_3 * V_164 )
{
struct V_13 * V_15 = V_2 -> V_79 ;
* V_164 = F_69 ( V_15 -> V_17 ) ;
}
static int F_70 ( struct V_93 * V_93 , int V_123 )
{
return 0 ;
}
static int F_71 ( struct V_93 * V_93 )
{
V_93 -> V_165 = F_22 () ;
return 0 ;
}
static void F_72 ( struct V_93 * V_93 )
{
V_93 -> V_165 = NULL ;
}
static int F_73 ( struct V_93 * V_93 , unsigned int V_166 ,
unsigned long V_167 )
{
int V_6 = 0 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_86 ) ;
F_33 ( & V_41 , V_93 -> V_94 ) ;
if ( F_74 ( V_166 ) & V_168 )
V_6 = F_18 ( V_93 -> V_165 , V_87 , & V_41 ) ;
if ( V_6 == 0 && ( F_74 ( V_166 ) & V_169 ) )
V_6 = F_18 ( V_93 -> V_165 , V_83 , & V_41 ) ;
return V_6 ;
}
static int F_75 ( struct V_93 * V_93 , unsigned int V_166 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_86 ) ;
F_33 ( & V_41 , V_93 -> V_94 ) ;
return F_18 ( V_93 -> V_165 , V_87 , & V_41 ) ;
}
static int F_76 ( struct V_93 * V_93 , unsigned int V_166 ,
unsigned long V_167 )
{
struct V_40 V_41 ;
int V_6 = 0 ;
switch ( V_166 ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
F_16 ( & V_41 , V_42 , V_86 ) ;
F_33 ( & V_41 , V_93 -> V_94 ) ;
V_6 = F_18 ( V_93 -> V_165 , V_87 , & V_41 ) ;
break;
default:
break;
}
return V_6 ;
}
static int F_77 ( struct V_93 * V_93 ,
unsigned long V_175 , unsigned long V_176 ,
unsigned long V_72 )
{
struct V_110 * V_111 ;
struct V_32 * V_177 ;
struct V_20 * V_24 ;
char * V_47 ;
char * V_178 ;
char * V_179 ;
struct V_13 * V_15 ;
struct V_4 * V_5 ;
int V_115 ;
int V_180 ;
int V_181 ;
int V_6 ;
if ( V_93 == NULL || V_93 -> V_182 == NULL )
return 0 ;
V_5 = V_93 -> V_182 ;
if ( V_5 -> V_76 == NULL )
return 0 ;
V_15 = V_5 -> V_76 -> V_79 ;
if ( V_15 -> V_145 == NULL )
return 0 ;
V_178 = V_15 -> V_145 ;
V_24 = F_39 () ;
V_47 = F_22 () ;
V_111 = F_46 ( V_47 ) ;
V_6 = 0 ;
F_47 () ;
F_10 (srp, &skp->smk_rules, list) {
V_179 = V_177 -> V_183 ;
if ( V_178 == V_179 )
continue;
V_115 = F_48 ( V_177 -> V_184 , V_179 ,
& V_24 -> V_27 ) ;
if ( V_115 == - V_185 )
V_115 = V_177 -> V_186 ;
else
V_115 &= V_177 -> V_186 ;
if ( V_115 == 0 )
continue;
V_111 = F_46 ( V_178 ) ;
V_180 = F_48 ( V_178 , V_179 , & V_111 -> V_27 ) ;
if ( V_180 == - V_185 ) {
V_6 = - V_51 ;
break;
}
V_181 = F_48 ( V_178 , V_179 , & V_24 -> V_27 ) ;
if ( V_181 != - V_185 )
V_180 &= V_181 ;
if ( ( V_115 | V_180 ) != V_180 ) {
V_6 = - V_51 ;
break;
}
}
F_49 () ;
return V_6 ;
}
static int F_78 ( struct V_93 * V_93 )
{
V_93 -> V_165 = F_22 () ;
return 0 ;
}
static int F_79 ( struct V_37 * V_187 ,
struct V_188 * V_189 , int V_190 )
{
struct V_93 * V_93 ;
int V_6 ;
char * V_24 = F_14 ( V_187 -> V_96 -> V_97 ) ;
struct V_40 V_41 ;
V_93 = F_80 ( V_189 , struct V_93 , V_191 ) ;
V_6 = V_186 ( V_93 -> V_165 , V_24 , V_87 , NULL ) ;
if ( V_6 != 0 && F_81 ( V_187 , V_48 ) )
V_6 = 0 ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_17 ( & V_41 , V_187 ) ;
F_82 ( V_93 -> V_165 , V_24 , V_87 , V_6 , & V_41 ) ;
return V_6 ;
}
static int F_83 ( struct V_93 * V_93 )
{
int V_115 = 0 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_33 ( & V_41 , V_93 -> V_94 ) ;
if ( V_93 -> V_192 & V_193 )
V_115 = V_83 ;
if ( V_93 -> V_192 & V_194 )
V_115 |= V_87 ;
return F_18 ( V_93 -> V_165 , V_115 , & V_41 ) ;
}
static int F_84 ( struct V_93 * V_93 , const struct V_96 * V_96 )
{
struct V_13 * V_15 = V_93 -> V_94 . V_4 -> V_76 -> V_79 ;
V_93 -> V_165 = V_15 -> V_17 ;
return 0 ;
}
static int F_85 ( struct V_96 * V_96 , T_1 V_23 )
{
struct V_20 * V_24 ;
V_24 = F_7 ( NULL , NULL , V_23 ) ;
if ( V_24 == NULL )
return - V_35 ;
V_96 -> V_97 = V_24 ;
return 0 ;
}
static void F_86 ( struct V_96 * V_96 )
{
struct V_20 * V_24 = V_96 -> V_97 ;
struct V_32 * V_195 ;
struct V_29 * V_196 ;
struct V_29 * V_197 ;
if ( V_24 == NULL )
return;
V_96 -> V_97 = NULL ;
F_87 (l, n, &tsp->smk_rules) {
V_195 = F_88 ( V_196 , struct V_32 , V_36 ) ;
F_89 ( & V_195 -> V_36 ) ;
F_4 ( V_195 ) ;
}
F_4 ( V_24 ) ;
}
static int F_90 ( struct V_96 * V_198 , const struct V_96 * V_199 ,
T_1 V_23 )
{
struct V_20 * V_200 = V_199 -> V_97 ;
struct V_20 * V_201 ;
int V_6 ;
V_201 = F_7 ( V_200 -> V_25 , V_200 -> V_25 , V_23 ) ;
if ( V_201 == NULL )
return - V_35 ;
V_6 = F_9 ( & V_201 -> V_27 , & V_200 -> V_27 , V_23 ) ;
if ( V_6 != 0 )
return V_6 ;
V_198 -> V_97 = V_201 ;
return 0 ;
}
static void F_91 ( struct V_96 * V_198 , const struct V_96 * V_199 )
{
struct V_20 * V_200 = V_199 -> V_97 ;
struct V_20 * V_201 = V_198 -> V_97 ;
V_201 -> V_25 = V_200 -> V_25 ;
V_201 -> V_26 = V_200 -> V_25 ;
F_6 ( & V_201 -> V_28 ) ;
F_8 ( & V_201 -> V_27 ) ;
}
static int F_92 ( struct V_96 * V_198 , T_3 V_164 )
{
struct V_20 * V_201 = V_198 -> V_97 ;
char * V_14 = F_93 ( V_164 ) ;
if ( V_14 == NULL )
return - V_140 ;
V_201 -> V_25 = V_14 ;
return 0 ;
}
static int F_94 ( struct V_96 * V_198 ,
struct V_2 * V_2 )
{
struct V_13 * V_15 = V_2 -> V_79 ;
struct V_20 * V_24 = V_198 -> V_97 ;
V_24 -> V_26 = V_15 -> V_17 ;
V_24 -> V_25 = V_15 -> V_17 ;
return 0 ;
}
static int F_95 ( struct V_37 * V_202 , int V_203 ,
const char * V_204 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_204 , V_43 ) ;
F_17 ( & V_41 , V_202 ) ;
return F_18 ( F_14 ( F_15 ( V_202 ) ) , V_203 , & V_41 ) ;
}
static int F_96 ( struct V_37 * V_202 , T_4 V_205 )
{
return F_95 ( V_202 , V_87 , V_42 ) ;
}
static int F_97 ( struct V_37 * V_202 )
{
return F_95 ( V_202 , V_83 , V_42 ) ;
}
static int F_98 ( struct V_37 * V_202 )
{
return F_95 ( V_202 , V_83 , V_42 ) ;
}
static void F_99 ( struct V_37 * V_202 , T_3 * V_164 )
{
* V_164 = F_69 ( F_14 ( F_15 ( V_202 ) ) ) ;
}
static int F_100 ( struct V_37 * V_202 , int V_206 )
{
int V_6 ;
V_6 = F_101 ( V_202 , V_206 ) ;
if ( V_6 == 0 )
V_6 = F_95 ( V_202 , V_87 , V_42 ) ;
return V_6 ;
}
static int F_102 ( struct V_37 * V_202 , int V_207 )
{
int V_6 ;
V_6 = F_103 ( V_202 , V_207 ) ;
if ( V_6 == 0 )
V_6 = F_95 ( V_202 , V_87 , V_42 ) ;
return V_6 ;
}
static int F_104 ( struct V_37 * V_202 )
{
return F_95 ( V_202 , V_83 , V_42 ) ;
}
static int F_105 ( struct V_37 * V_202 )
{
int V_6 ;
V_6 = F_106 ( V_202 ) ;
if ( V_6 == 0 )
V_6 = F_95 ( V_202 , V_87 , V_42 ) ;
return V_6 ;
}
static int F_107 ( struct V_37 * V_202 )
{
return F_95 ( V_202 , V_83 , V_42 ) ;
}
static int F_108 ( struct V_37 * V_202 )
{
return F_95 ( V_202 , V_87 , V_42 ) ;
}
static int F_109 ( struct V_37 * V_202 , struct V_208 * V_209 ,
int V_210 , T_3 V_164 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_17 ( & V_41 , V_202 ) ;
if ( V_164 == 0 )
return F_18 ( F_14 ( F_15 ( V_202 ) ) , V_87 ,
& V_41 ) ;
return V_186 ( F_93 ( V_164 ) ,
F_14 ( F_15 ( V_202 ) ) , V_87 , & V_41 ) ;
}
static int F_110 ( struct V_37 * V_202 )
{
return 0 ;
}
static void F_111 ( struct V_37 * V_202 , struct V_2 * V_2 )
{
struct V_13 * V_15 = V_2 -> V_79 ;
V_15 -> V_17 = F_14 ( F_15 ( V_202 ) ) ;
}
static int F_112 ( struct V_151 * V_157 , int V_211 , T_1 V_212 )
{
char * V_113 = F_22 () ;
struct V_148 * V_149 ;
V_149 = F_2 ( sizeof( struct V_148 ) , V_212 ) ;
if ( V_149 == NULL )
return - V_35 ;
V_149 -> V_160 = V_113 ;
V_149 -> V_162 = V_113 ;
V_149 -> V_213 = NULL ;
V_157 -> V_158 = V_149 ;
return 0 ;
}
static void F_113 ( struct V_151 * V_157 )
{
F_4 ( V_157 -> V_158 ) ;
}
static char * F_114 ( struct V_214 * V_215 )
{
struct V_216 * V_217 ;
struct V_218 * V_219 = & V_215 -> V_220 ;
if ( V_219 -> V_221 == 0 )
return NULL ;
F_10 (snp, &smk_netlbladdr_list, list)
if ( ( & V_217 -> V_222 . V_220 ) -> V_221 ==
( V_219 -> V_221 & ( & V_217 -> V_223 ) -> V_221 ) ) {
if ( V_217 -> V_224 == V_225 )
return NULL ;
return V_217 -> V_224 ;
}
return NULL ;
}
static int F_115 ( struct V_151 * V_157 , int V_226 )
{
struct V_110 * V_111 ;
struct V_148 * V_149 = V_157 -> V_158 ;
int V_6 = 0 ;
F_116 () ;
F_117 ( V_157 ) ;
if ( V_149 -> V_162 == V_227 ||
V_226 == V_228 )
F_118 ( V_157 ) ;
else {
V_111 = F_46 ( V_149 -> V_162 ) ;
V_6 = F_119 ( V_157 , V_157 -> V_229 , & V_111 -> V_230 ) ;
}
F_120 ( V_157 ) ;
F_121 () ;
return V_6 ;
}
static int F_122 ( struct V_151 * V_157 , struct V_214 * V_231 )
{
int V_6 ;
int V_232 ;
char * V_233 ;
struct V_148 * V_149 = V_157 -> V_158 ;
struct V_40 V_41 ;
F_47 () ;
V_233 = F_114 ( V_231 ) ;
if ( V_233 != NULL ) {
#ifdef F_123
struct V_234 V_235 ;
F_124 ( & V_41 , V_42 , V_236 , & V_235 ) ;
V_41 . V_237 . V_238 . V_235 -> V_211 = V_231 -> V_239 ;
V_41 . V_237 . V_238 . V_235 -> V_240 = V_231 -> V_241 ;
V_41 . V_237 . V_238 . V_235 -> V_242 . V_243 = V_231 -> V_220 . V_221 ;
#endif
V_232 = V_228 ;
V_6 = V_186 ( V_149 -> V_162 , V_233 , V_87 , & V_41 ) ;
} else {
V_232 = V_244 ;
V_6 = 0 ;
}
F_49 () ;
if ( V_6 != 0 )
return V_6 ;
return F_115 ( V_157 , V_232 ) ;
}
static int F_125 ( struct V_2 * V_2 , const char * V_1 ,
const void * V_108 , T_2 V_133 , int V_72 )
{
char * V_47 ;
struct V_13 * V_78 = V_2 -> V_79 ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
int V_6 = 0 ;
if ( V_108 == NULL || V_133 > V_11 || V_133 == 0 )
return - V_51 ;
V_47 = F_3 ( V_108 , V_133 ) ;
if ( V_47 == NULL )
return - V_140 ;
if ( strcmp ( V_1 , V_116 ) == 0 ) {
V_78 -> V_17 = V_47 ;
V_78 -> V_18 |= V_245 ;
return 0 ;
}
if ( V_2 -> V_153 -> V_154 != V_155 )
return - V_156 ;
V_151 = F_66 ( V_2 ) ;
if ( V_151 == NULL || V_151 -> V_157 == NULL )
return - V_156 ;
V_149 = V_151 -> V_157 -> V_158 ;
if ( strcmp ( V_1 , V_159 ) == 0 )
V_149 -> V_160 = V_47 ;
else if ( strcmp ( V_1 , V_161 ) == 0 ) {
V_149 -> V_162 = V_47 ;
if ( V_151 -> V_157 -> V_229 != V_246 ) {
V_6 = F_115 ( V_151 -> V_157 , V_244 ) ;
if ( V_6 != 0 )
F_126 ( V_247
L_2 ,
V_42 , - V_6 ) ;
}
} else
return - V_156 ;
return 0 ;
}
static int F_127 ( struct V_150 * V_151 , int V_211 ,
int type , int V_248 , int V_249 )
{
if ( V_211 != V_250 || V_151 -> V_157 == NULL )
return 0 ;
return F_115 ( V_151 -> V_157 , V_244 ) ;
}
static int F_128 ( struct V_150 * V_151 , struct V_251 * V_231 ,
int V_252 )
{
if ( V_151 -> V_157 == NULL || V_151 -> V_157 -> V_229 != V_250 )
return 0 ;
if ( V_252 < sizeof( struct V_214 ) )
return - V_140 ;
return F_122 ( V_151 -> V_157 , (struct V_214 * ) V_231 ) ;
}
static int F_129 ( int V_72 )
{
int V_115 = 0 ;
if ( V_72 & V_253 )
V_115 |= V_83 ;
if ( V_72 & V_254 )
V_115 |= V_87 ;
if ( V_72 & V_255 )
V_115 |= V_126 ;
return V_115 ;
}
static int F_130 ( struct V_256 * V_257 )
{
V_257 -> V_97 = F_22 () ;
return 0 ;
}
static void F_131 ( struct V_256 * V_257 )
{
V_257 -> V_97 = NULL ;
}
static char * F_132 ( struct V_258 * V_259 )
{
return ( char * ) V_259 -> V_260 . V_97 ;
}
static int F_133 ( struct V_258 * V_259 )
{
struct V_261 * V_15 = & V_259 -> V_260 ;
V_15 -> V_97 = F_22 () ;
return 0 ;
}
static void F_134 ( struct V_258 * V_259 )
{
struct V_261 * V_15 = & V_259 -> V_260 ;
V_15 -> V_97 = NULL ;
}
static int F_135 ( struct V_258 * V_259 , int V_203 )
{
char * V_149 = F_132 ( V_259 ) ;
struct V_40 V_41 ;
#ifdef F_123
F_16 ( & V_41 , V_42 , V_262 ) ;
V_41 . V_237 . V_238 . V_263 = V_259 -> V_260 . V_264 ;
#endif
return F_18 ( V_149 , V_203 , & V_41 ) ;
}
static int F_136 ( struct V_258 * V_259 , int V_265 )
{
int V_115 ;
V_115 = F_129 ( V_265 ) ;
return F_135 ( V_259 , V_115 ) ;
}
static int F_137 ( struct V_258 * V_259 , int V_166 )
{
int V_115 ;
switch ( V_166 ) {
case V_266 :
case V_267 :
V_115 = V_83 ;
break;
case V_268 :
case V_269 :
case V_270 :
case V_271 :
V_115 = V_44 ;
break;
case V_272 :
case V_273 :
return 0 ;
default:
return - V_140 ;
}
return F_135 ( V_259 , V_115 ) ;
}
static int F_138 ( struct V_258 * V_259 , char T_5 * V_274 ,
int V_265 )
{
int V_115 ;
V_115 = F_129 ( V_265 ) ;
return F_135 ( V_259 , V_115 ) ;
}
static char * F_139 ( struct V_275 * V_276 )
{
return ( char * ) V_276 -> V_277 . V_97 ;
}
static int F_140 ( struct V_275 * V_276 )
{
struct V_261 * V_15 = & V_276 -> V_277 ;
V_15 -> V_97 = F_22 () ;
return 0 ;
}
static void F_141 ( struct V_275 * V_276 )
{
struct V_261 * V_15 = & V_276 -> V_277 ;
V_15 -> V_97 = NULL ;
}
static int F_142 ( struct V_275 * V_276 , int V_203 )
{
char * V_149 = F_139 ( V_276 ) ;
struct V_40 V_41 ;
#ifdef F_123
F_16 ( & V_41 , V_42 , V_262 ) ;
V_41 . V_237 . V_238 . V_263 = V_276 -> V_277 . V_264 ;
#endif
return F_18 ( V_149 , V_203 , & V_41 ) ;
}
static int F_143 ( struct V_275 * V_276 , int V_278 )
{
int V_115 ;
V_115 = F_129 ( V_278 ) ;
return F_142 ( V_276 , V_115 ) ;
}
static int F_144 ( struct V_275 * V_276 , int V_166 )
{
int V_115 ;
switch ( V_166 ) {
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_266 :
case V_284 :
V_115 = V_83 ;
break;
case V_285 :
case V_286 :
case V_271 :
case V_268 :
V_115 = V_44 ;
break;
case V_272 :
case V_287 :
return 0 ;
default:
return - V_140 ;
}
return F_142 ( V_276 , V_115 ) ;
}
static int F_145 ( struct V_275 * V_276 , struct V_288 * V_289 ,
unsigned V_290 , int V_291 )
{
return F_142 ( V_276 , V_44 ) ;
}
static int F_146 ( struct V_292 * V_293 )
{
struct V_261 * V_294 = & V_293 -> V_295 ;
V_294 -> V_97 = F_22 () ;
return 0 ;
}
static void F_147 ( struct V_292 * V_293 )
{
struct V_261 * V_294 = & V_293 -> V_295 ;
V_294 -> V_97 = NULL ;
}
static char * F_148 ( struct V_292 * V_293 )
{
return ( char * ) V_293 -> V_295 . V_97 ;
}
static int F_149 ( struct V_292 * V_293 , int V_203 )
{
char * V_296 = F_148 ( V_293 ) ;
struct V_40 V_41 ;
#ifdef F_123
F_16 ( & V_41 , V_42 , V_262 ) ;
V_41 . V_237 . V_238 . V_263 = V_293 -> V_295 . V_264 ;
#endif
return F_18 ( V_296 , V_203 , & V_41 ) ;
}
static int F_150 ( struct V_292 * V_293 , int V_297 )
{
int V_115 ;
V_115 = F_129 ( V_297 ) ;
return F_149 ( V_293 , V_115 ) ;
}
static int F_151 ( struct V_292 * V_293 , int V_166 )
{
int V_115 ;
switch ( V_166 ) {
case V_266 :
case V_298 :
V_115 = V_83 ;
break;
case V_268 :
case V_271 :
V_115 = V_44 ;
break;
case V_272 :
case V_299 :
return 0 ;
default:
return - V_140 ;
}
return F_149 ( V_293 , V_115 ) ;
}
static int F_152 ( struct V_292 * V_293 , struct V_256 * V_257 ,
int V_297 )
{
int V_115 ;
V_115 = F_129 ( V_297 ) ;
return F_149 ( V_293 , V_115 ) ;
}
static int F_153 ( struct V_292 * V_293 , struct V_256 * V_257 ,
struct V_37 * V_300 , long type , int V_39 )
{
return F_149 ( V_293 , V_44 ) ;
}
static int F_154 ( struct V_261 * V_301 , short V_302 )
{
char * V_15 = V_301 -> V_97 ;
int V_115 = F_129 ( V_302 ) ;
struct V_40 V_41 ;
#ifdef F_123
F_16 ( & V_41 , V_42 , V_262 ) ;
V_41 . V_237 . V_238 . V_263 = V_301 -> V_264 ;
#endif
return F_18 ( V_15 , V_115 , & V_41 ) ;
}
static void F_155 ( struct V_261 * V_301 , T_3 * V_164 )
{
char * V_14 = V_301 -> V_97 ;
* V_164 = F_69 ( V_14 ) ;
}
static void F_156 ( struct V_4 * V_303 , struct V_2 * V_2 )
{
struct V_52 * V_80 ;
struct V_54 * V_55 ;
struct V_13 * V_15 ;
char * V_113 = F_22 () ;
char * V_304 ;
char * V_305 ;
char V_306 [ V_142 ] ;
int V_307 = 0 ;
int V_6 ;
struct V_4 * V_5 ;
if ( V_2 == NULL )
return;
V_15 = V_2 -> V_79 ;
F_157 ( & V_15 -> V_19 ) ;
if ( V_15 -> V_18 & V_245 )
goto V_308;
V_80 = V_2 -> V_153 ;
V_55 = V_80 -> V_62 ;
V_305 = V_55 -> V_57 ;
if ( V_303 -> V_309 == V_303 ) {
V_15 -> V_17 = V_55 -> V_56 ;
V_15 -> V_18 |= V_245 ;
goto V_308;
}
switch ( V_80 -> V_154 ) {
case V_310 :
V_305 = V_311 . V_50 ;
break;
case V_312 :
V_305 = V_311 . V_50 ;
break;
case V_313 :
V_305 = V_113 ;
break;
case V_155 :
V_305 = V_311 . V_50 ;
break;
case V_314 :
break;
case V_315 :
V_305 = V_311 . V_50 ;
default:
if ( F_158 ( V_2 -> V_316 ) ) {
V_305 = V_311 . V_50 ;
break;
}
if ( V_2 -> V_9 -> V_10 == NULL )
break;
V_5 = F_159 ( V_303 ) ;
V_304 = F_1 ( V_134 , V_2 , V_5 ) ;
if ( V_304 != NULL )
V_305 = V_304 ;
if ( F_160 ( V_2 -> V_316 ) ) {
if ( V_15 -> V_18 & V_118 ) {
V_15 -> V_18 &= ~ V_118 ;
V_6 = V_2 -> V_9 -> V_317 ( V_5 ,
V_141 ,
V_143 , V_142 ,
0 ) ;
} else {
V_6 = V_2 -> V_9 -> V_10 ( V_5 ,
V_141 , V_306 ,
V_142 ) ;
if ( V_6 >= 0 && strncmp ( V_306 , V_143 ,
V_142 ) != 0 )
V_6 = - V_140 ;
}
if ( V_6 >= 0 )
V_307 = V_146 ;
}
V_15 -> V_25 = F_1 ( V_137 , V_2 , V_5 ) ;
V_15 -> V_145 = F_1 ( V_138 , V_2 , V_5 ) ;
F_161 ( V_5 ) ;
break;
}
if ( V_305 == NULL )
V_15 -> V_17 = V_113 ;
else
V_15 -> V_17 = V_305 ;
V_15 -> V_18 |= ( V_245 | V_307 ) ;
V_308:
F_162 ( & V_15 -> V_19 ) ;
return;
}
static int F_163 ( struct V_37 * V_202 , char * V_1 , char * * V_108 )
{
char * V_65 ;
int V_318 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_140 ;
V_65 = F_45 ( F_14 ( F_15 ( V_202 ) ) , V_12 ) ;
if ( V_65 == NULL )
return - V_35 ;
V_318 = strlen ( V_65 ) ;
* V_108 = V_65 ;
return V_318 ;
}
static int F_164 ( struct V_37 * V_202 , char * V_1 ,
void * V_108 , T_2 V_133 )
{
struct V_20 * V_24 ;
struct V_96 * V_198 ;
char * V_319 ;
if ( V_202 != V_103 )
return - V_100 ;
if ( ! F_23 ( V_139 ) )
return - V_100 ;
if ( V_108 == NULL || V_133 == 0 || V_133 >= V_11 )
return - V_140 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_140 ;
V_319 = F_3 ( V_108 , V_133 ) ;
if ( V_319 == NULL )
return - V_140 ;
if ( V_319 == V_320 . V_50 )
return - V_100 ;
V_198 = F_165 () ;
if ( V_198 == NULL )
return - V_35 ;
V_24 = V_198 -> V_97 ;
V_24 -> V_25 = V_319 ;
F_166 ( V_198 ) ;
return V_133 ;
}
static int F_167 ( struct V_151 * V_151 ,
struct V_151 * V_321 , struct V_151 * V_322 )
{
struct V_148 * V_149 = V_151 -> V_158 ;
struct V_148 * V_323 = V_321 -> V_158 ;
struct V_148 * V_78 = V_322 -> V_158 ;
struct V_40 V_41 ;
int V_6 = 0 ;
#ifdef F_123
struct V_234 V_235 ;
F_124 ( & V_41 , V_42 , V_236 , & V_235 ) ;
F_168 ( & V_41 , V_321 ) ;
#endif
if ( ! F_23 ( V_48 ) )
V_6 = V_186 ( V_149 -> V_162 , V_323 -> V_160 , V_87 , & V_41 ) ;
if ( V_6 == 0 ) {
V_78 -> V_213 = V_149 -> V_162 ;
V_149 -> V_213 = V_323 -> V_162 ;
}
return V_6 ;
}
static int F_169 ( struct V_150 * V_151 , struct V_150 * V_321 )
{
struct V_148 * V_149 = V_151 -> V_157 -> V_158 ;
struct V_148 * V_323 = V_321 -> V_157 -> V_158 ;
struct V_40 V_41 ;
int V_6 = 0 ;
#ifdef F_123
struct V_234 V_235 ;
F_124 ( & V_41 , V_42 , V_236 , & V_235 ) ;
F_168 ( & V_41 , V_321 -> V_157 ) ;
#endif
if ( ! F_23 ( V_48 ) )
V_6 = V_186 ( V_149 -> V_162 , V_323 -> V_160 , V_87 , & V_41 ) ;
return V_6 ;
}
static int F_170 ( struct V_150 * V_151 , struct V_324 * V_257 ,
int V_133 )
{
struct V_214 * V_215 = (struct V_214 * ) V_257 -> V_325 ;
if ( V_215 == NULL || V_215 -> V_239 != V_326 )
return 0 ;
return F_122 ( V_151 -> V_157 , V_215 ) ;
}
static char * F_171 ( struct V_327 * V_231 ,
struct V_148 * V_149 )
{
struct V_110 * V_328 ;
char * V_47 ;
int V_329 = 0 ;
if ( ( V_231 -> V_72 & V_330 ) != 0 ) {
F_47 () ;
F_172 (kp, &smack_known_list, list) {
if ( V_231 -> V_331 . V_332 . V_333 != V_328 -> V_230 . V_331 . V_332 . V_333 )
continue;
if ( memcmp ( V_231 -> V_331 . V_332 . V_334 ,
V_328 -> V_230 . V_331 . V_332 . V_334 ,
V_335 ) != 0 )
continue;
V_329 = 1 ;
break;
}
F_49 () ;
if ( V_329 )
return V_328 -> V_50 ;
if ( V_149 != NULL && V_149 -> V_160 == V_311 . V_50 )
return V_320 . V_50 ;
return V_311 . V_50 ;
}
if ( ( V_231 -> V_72 & V_336 ) != 0 ) {
V_47 = F_93 ( V_231 -> V_331 . V_164 ) ;
F_173 ( V_47 == NULL ) ;
return V_47 ;
}
return V_227 ;
}
static int F_174 ( struct V_151 * V_157 , struct V_337 * V_338 )
{
struct V_327 V_339 ;
struct V_148 * V_149 = V_157 -> V_158 ;
char * V_113 ;
int V_6 ;
struct V_40 V_41 ;
#ifdef F_123
struct V_234 V_235 ;
#endif
if ( V_157 -> V_229 != V_250 && V_157 -> V_229 != V_340 )
return 0 ;
F_175 ( & V_339 ) ;
V_6 = F_176 ( V_338 , V_157 -> V_229 , & V_339 ) ;
if ( V_6 == 0 )
V_113 = F_171 ( & V_339 , V_149 ) ;
else
V_113 = V_227 ;
F_177 ( & V_339 ) ;
#ifdef F_123
F_124 ( & V_41 , V_42 , V_236 , & V_235 ) ;
V_41 . V_237 . V_238 . V_235 -> V_211 = V_157 -> V_229 ;
V_41 . V_237 . V_238 . V_235 -> V_341 = V_338 -> V_342 ;
F_178 ( V_338 , & V_41 . V_237 , NULL ) ;
#endif
V_6 = V_186 ( V_113 , V_149 -> V_160 , V_87 , & V_41 ) ;
if ( V_6 != 0 )
F_179 ( V_338 , V_6 , 0 ) ;
return V_6 ;
}
static int F_180 ( struct V_150 * V_151 ,
char T_5 * V_343 ,
int T_5 * V_344 , unsigned V_109 )
{
struct V_148 * V_149 ;
char * V_345 = L_4 ;
int V_318 = 1 ;
int V_6 = 0 ;
V_149 = V_151 -> V_157 -> V_158 ;
if ( V_149 -> V_213 != NULL ) {
V_345 = V_149 -> V_213 ;
V_318 = strlen ( V_345 ) + 1 ;
}
if ( V_318 > V_109 )
V_6 = - V_346 ;
else if ( F_181 ( V_343 , V_345 , V_318 ) != 0 )
V_6 = - V_347 ;
if ( F_182 ( V_318 , V_344 ) != 0 )
V_6 = - V_347 ;
return V_6 ;
}
static int F_183 ( struct V_150 * V_151 ,
struct V_337 * V_338 , T_3 * V_164 )
{
struct V_327 V_339 ;
struct V_148 * V_149 = NULL ;
char * V_47 ;
int V_211 = V_348 ;
T_3 V_349 = 0 ;
int V_6 ;
if ( V_338 != NULL ) {
if ( V_338 -> V_248 == F_184 ( V_350 ) )
V_211 = V_250 ;
else if ( V_338 -> V_248 == F_184 ( V_351 ) )
V_211 = V_340 ;
}
if ( V_211 == V_348 && V_151 != NULL )
V_211 = V_151 -> V_157 -> V_229 ;
if ( V_211 == V_246 ) {
V_149 = V_151 -> V_157 -> V_158 ;
V_349 = F_69 ( V_149 -> V_162 ) ;
} else if ( V_211 == V_250 || V_211 == V_340 ) {
if ( V_151 != NULL && V_151 -> V_157 != NULL )
V_149 = V_151 -> V_157 -> V_158 ;
F_175 ( & V_339 ) ;
V_6 = F_176 ( V_338 , V_211 , & V_339 ) ;
if ( V_6 == 0 ) {
V_47 = F_171 ( & V_339 , V_149 ) ;
V_349 = F_69 ( V_47 ) ;
}
F_177 ( & V_339 ) ;
}
* V_164 = V_349 ;
if ( V_349 == 0 )
return - V_140 ;
return 0 ;
}
static void F_185 ( struct V_151 * V_157 , struct V_150 * V_352 )
{
struct V_148 * V_149 ;
if ( V_157 == NULL ||
( V_157 -> V_229 != V_250 && V_157 -> V_229 != V_340 ) )
return;
V_149 = V_157 -> V_158 ;
V_149 -> V_160 = V_149 -> V_162 = F_22 () ;
}
static int F_186 ( struct V_151 * V_157 , struct V_337 * V_338 ,
struct V_353 * V_354 )
{
T_6 V_211 = V_157 -> V_229 ;
struct V_110 * V_111 ;
struct V_148 * V_149 = V_157 -> V_158 ;
struct V_327 V_339 ;
struct V_214 V_355 ;
struct V_356 * V_357 ;
char * V_47 ;
char * V_358 ;
int V_6 ;
struct V_40 V_41 ;
#ifdef F_123
struct V_234 V_235 ;
#endif
if ( V_211 == V_340 && V_338 -> V_248 == F_184 ( V_350 ) )
V_211 = V_250 ;
F_175 ( & V_339 ) ;
V_6 = F_176 ( V_338 , V_211 , & V_339 ) ;
if ( V_6 == 0 )
V_47 = F_171 ( & V_339 , V_149 ) ;
else
V_47 = V_359 . V_50 ;
F_177 ( & V_339 ) ;
#ifdef F_123
F_124 ( & V_41 , V_42 , V_236 , & V_235 ) ;
V_41 . V_237 . V_238 . V_235 -> V_211 = V_211 ;
V_41 . V_237 . V_238 . V_235 -> V_341 = V_338 -> V_342 ;
F_178 ( V_338 , & V_41 . V_237 , NULL ) ;
#endif
V_6 = V_186 ( V_47 , V_149 -> V_160 , V_87 , & V_41 ) ;
if ( V_6 != 0 )
return V_6 ;
V_354 -> V_360 = F_69 ( V_47 ) ;
V_357 = F_187 ( V_338 ) ;
V_355 . V_220 . V_221 = V_357 -> V_361 ;
F_47 () ;
V_358 = F_114 ( & V_355 ) ;
F_49 () ;
if ( V_358 == NULL ) {
V_111 = F_46 ( V_47 ) ;
V_6 = F_188 ( V_354 , & V_111 -> V_230 ) ;
} else
F_189 ( V_354 ) ;
return V_6 ;
}
static void F_190 ( struct V_151 * V_157 ,
const struct V_353 * V_354 )
{
struct V_148 * V_149 = V_157 -> V_158 ;
if ( V_354 -> V_360 != 0 )
V_149 -> V_213 = F_93 ( V_354 -> V_360 ) ;
else
V_149 -> V_213 = NULL ;
}
static int F_191 ( struct V_362 * V_362 , const struct V_96 * V_96 ,
unsigned long V_72 )
{
V_362 -> V_97 = F_14 ( V_96 -> V_97 ) ;
return 0 ;
}
static void F_192 ( struct V_362 * V_362 )
{
V_362 -> V_97 = NULL ;
}
static int F_193 ( T_7 V_363 ,
const struct V_96 * V_96 , T_8 V_364 )
{
struct V_362 * V_365 ;
struct V_40 V_41 ;
char * V_24 = F_14 ( V_96 -> V_97 ) ;
V_365 = F_194 ( V_363 ) ;
if ( V_365 == NULL )
return - V_140 ;
if ( V_365 -> V_97 == NULL )
return 0 ;
if ( V_24 == NULL )
return - V_51 ;
#ifdef F_123
F_16 ( & V_41 , V_42 , V_366 ) ;
V_41 . V_237 . V_238 . V_367 . V_362 = V_365 -> V_368 ;
V_41 . V_237 . V_238 . V_367 . V_369 = V_365 -> V_370 ;
#endif
return V_186 ( V_24 , V_365 -> V_97 ,
V_44 , & V_41 ) ;
}
static int F_195 ( T_3 V_371 , T_3 V_77 , char * V_372 , void * * V_373 )
{
char * * V_374 = ( char * * ) V_373 ;
* V_374 = NULL ;
if ( V_371 != V_375 && V_371 != V_376 )
return - V_140 ;
if ( V_77 != V_377 && V_77 != V_378 )
return - V_140 ;
* V_374 = F_3 ( V_372 , 0 ) ;
return 0 ;
}
static int F_196 ( struct V_379 * V_380 )
{
struct V_381 * V_382 ;
int V_383 ;
for ( V_383 = 0 ; V_383 < V_380 -> V_384 ; V_383 ++ ) {
V_382 = & V_380 -> V_385 [ V_383 ] ;
if ( V_382 -> type == V_375 || V_382 -> type == V_376 )
return 1 ;
}
return 0 ;
}
static int F_197 ( T_3 V_164 , T_3 V_371 , T_3 V_77 , void * V_373 ,
struct V_386 * V_387 )
{
char * V_14 ;
char * V_374 = V_373 ;
if ( ! V_374 ) {
F_198 ( V_387 , V_388 , V_389 ,
L_5 ) ;
return - V_185 ;
}
if ( V_371 != V_375 && V_371 != V_376 )
return 0 ;
V_14 = F_93 ( V_164 ) ;
if ( V_77 == V_377 )
return ( V_374 == V_14 ) ;
if ( V_77 == V_378 )
return ( V_374 != V_14 ) ;
return 0 ;
}
static void F_199 ( void * V_373 )
{
}
static int F_200 ( T_3 V_164 , char * * V_390 , T_3 * V_391 )
{
char * V_47 = F_93 ( V_164 ) ;
if ( V_390 )
* V_390 = V_47 ;
* V_391 = strlen ( V_47 ) ;
return 0 ;
}
static int F_201 ( const char * V_390 , T_3 V_391 , T_3 * V_164 )
{
* V_164 = F_69 ( V_390 ) ;
return 0 ;
}
static void F_202 ( char * V_390 , T_3 V_391 )
{
}
static int F_203 ( struct V_2 * V_2 , void * V_392 , T_3 V_393 )
{
return F_125 ( V_2 , V_116 , V_392 , V_393 , 0 ) ;
}
static int F_204 ( struct V_4 * V_4 , void * V_392 , T_3 V_393 )
{
return F_205 ( V_4 , V_134 , V_392 , V_393 , 0 ) ;
}
static int F_206 ( struct V_2 * V_2 , void * * V_392 , T_3 * V_393 )
{
int V_109 = 0 ;
V_109 = F_65 ( V_2 , V_116 , V_392 , true ) ;
if ( V_109 < 0 )
return V_109 ;
* V_393 = V_109 ;
return 0 ;
}
static T_9 void F_207 ( void )
{
F_6 ( & V_359 . V_28 ) ;
F_6 ( & V_60 . V_28 ) ;
F_6 ( & V_49 . V_28 ) ;
F_6 ( & V_311 . V_28 ) ;
F_6 ( & V_144 . V_28 ) ;
F_6 ( & V_320 . V_28 ) ;
F_8 ( & V_359 . V_27 ) ;
F_8 ( & V_60 . V_27 ) ;
F_8 ( & V_311 . V_27 ) ;
F_8 ( & V_49 . V_27 ) ;
F_8 ( & V_144 . V_27 ) ;
F_8 ( & V_320 . V_27 ) ;
F_208 ( & V_359 . V_36 , & V_394 ) ;
F_208 ( & V_60 . V_36 , & V_394 ) ;
F_208 ( & V_311 . V_36 , & V_394 ) ;
F_208 ( & V_49 . V_36 , & V_394 ) ;
F_208 ( & V_144 . V_36 , & V_394 ) ;
F_208 ( & V_320 . V_36 , & V_394 ) ;
}
static T_9 int F_209 ( void )
{
struct V_96 * V_96 ;
struct V_20 * V_24 ;
if ( ! F_210 ( & V_395 ) )
return 0 ;
V_24 = F_7 ( V_49 . V_50 ,
V_49 . V_50 , V_12 ) ;
if ( V_24 == NULL )
return - V_35 ;
F_126 ( V_396 L_6 ) ;
V_96 = (struct V_96 * ) V_103 -> V_96 ;
V_96 -> V_97 = V_24 ;
F_207 () ;
if ( F_211 ( & V_395 ) )
F_212 ( L_7 ) ;
return 0 ;
}

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
F_25 ( & V_55 -> V_62 ) ;
V_53 -> V_63 = V_55 ;
return 0 ;
}
static void F_26 ( struct V_52 * V_53 )
{
F_4 ( V_53 -> V_63 ) ;
V_53 -> V_63 = NULL ;
}
static int F_27 ( char * V_64 , char * V_65 )
{
char * V_66 , * V_67 , * V_68 , * V_5 ;
V_68 = ( char * ) F_28 ( V_12 ) ;
if ( V_68 == NULL )
return - V_35 ;
for ( V_66 = V_64 , V_67 = V_64 ; V_67 != NULL ; V_66 = V_67 + 1 ) {
if ( strstr ( V_66 , V_69 ) == V_66 )
V_5 = V_65 ;
else if ( strstr ( V_66 , V_70 ) == V_66 )
V_5 = V_65 ;
else if ( strstr ( V_66 , V_71 ) == V_66 )
V_5 = V_65 ;
else if ( strstr ( V_66 , V_72 ) == V_66 )
V_5 = V_65 ;
else
V_5 = V_68 ;
V_67 = strchr ( V_66 , ',' ) ;
if ( V_67 != NULL )
* V_67 = '\0' ;
if ( * V_5 != '\0' )
strcat ( V_5 , L_1 ) ;
strcat ( V_5 , V_66 ) ;
}
strcpy ( V_64 , V_68 ) ;
F_29 ( ( unsigned long ) V_68 ) ;
return 0 ;
}
static int F_30 ( struct V_52 * V_53 , int V_73 , void * V_74 )
{
struct V_4 * V_75 = V_53 -> V_76 ;
struct V_2 * V_2 = V_75 -> V_77 ;
struct V_54 * V_47 = V_53 -> V_63 ;
struct V_13 * V_15 ;
char * V_78 ;
char * V_67 ;
char * V_79 ;
F_31 ( & V_47 -> V_62 ) ;
if ( V_47 -> V_61 != 0 ) {
F_32 ( & V_47 -> V_62 ) ;
return 0 ;
}
V_47 -> V_61 = 1 ;
F_32 ( & V_47 -> V_62 ) ;
for ( V_78 = V_74 ; V_78 != NULL ; V_78 = V_67 ) {
V_67 = strchr ( V_78 , ',' ) ;
if ( V_67 != NULL )
* V_67 ++ = '\0' ;
if ( strncmp ( V_78 , V_71 , strlen ( V_71 ) ) == 0 ) {
V_78 += strlen ( V_71 ) ;
V_79 = F_3 ( V_78 , 0 ) ;
if ( V_79 != NULL )
V_47 -> V_59 = V_79 ;
} else if ( strncmp ( V_78 , V_70 , strlen ( V_70 ) ) == 0 ) {
V_78 += strlen ( V_70 ) ;
V_79 = F_3 ( V_78 , 0 ) ;
if ( V_79 != NULL )
V_47 -> V_58 = V_79 ;
} else if ( strncmp ( V_78 , V_69 ,
strlen ( V_69 ) ) == 0 ) {
V_78 += strlen ( V_69 ) ;
V_79 = F_3 ( V_78 , 0 ) ;
if ( V_79 != NULL )
V_47 -> V_57 = V_79 ;
} else if ( strncmp ( V_78 , V_72 , strlen ( V_72 ) ) == 0 ) {
V_78 += strlen ( V_72 ) ;
V_79 = F_3 ( V_78 , 0 ) ;
if ( V_79 != NULL )
V_47 -> V_56 = V_79 ;
}
}
V_15 = V_2 -> V_80 ;
if ( V_15 == NULL )
V_2 -> V_80 = F_5 ( V_47 -> V_56 ) ;
else
V_15 -> V_17 = V_47 -> V_56 ;
return 0 ;
}
static int F_33 ( struct V_4 * V_4 )
{
struct V_54 * V_81 = V_4 -> V_82 -> V_63 ;
int V_6 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_83 ) ;
F_34 ( & V_41 , V_4 ) ;
V_6 = F_18 ( V_81 -> V_58 , V_84 , & V_41 ) ;
return V_6 ;
}
static int F_35 ( char * V_85 , struct V_86 * V_86 ,
char * type , unsigned long V_73 , void * V_74 )
{
struct V_54 * V_81 = V_86 -> V_4 -> V_82 -> V_63 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_87 ) ;
F_36 ( & V_41 , * V_86 ) ;
return F_18 ( V_81 -> V_58 , V_88 , & V_41 ) ;
}
static int F_37 ( struct V_89 * V_90 , int V_73 )
{
struct V_54 * V_81 ;
struct V_40 V_41 ;
struct V_86 V_86 ;
V_86 . V_4 = V_90 -> V_91 ;
V_86 . V_90 = V_90 ;
F_16 ( & V_41 , V_42 , V_87 ) ;
F_36 ( & V_41 , V_86 ) ;
V_81 = V_86 . V_4 -> V_82 -> V_63 ;
return F_18 ( V_81 -> V_58 , V_88 , & V_41 ) ;
}
static int F_38 ( struct V_92 * V_93 )
{
struct V_2 * V_2 = V_93 -> V_94 -> V_95 . V_4 -> V_77 ;
struct V_20 * V_96 = V_93 -> V_97 -> V_98 ;
struct V_13 * V_15 ;
int V_6 ;
V_6 = F_39 ( V_93 ) ;
if ( V_6 != 0 )
return V_6 ;
if ( V_93 -> V_99 )
return 0 ;
V_15 = V_2 -> V_80 ;
if ( V_15 -> V_25 == NULL || V_15 -> V_25 == V_96 -> V_25 )
return 0 ;
if ( V_93 -> V_100 )
return - V_101 ;
V_96 -> V_25 = V_15 -> V_25 ;
V_93 -> V_102 |= V_103 ;
return 0 ;
}
static void F_40 ( struct V_92 * V_93 )
{
struct V_20 * V_96 = V_93 -> V_97 -> V_98 ;
if ( V_96 -> V_25 != V_96 -> V_26 )
V_104 -> V_105 = 0 ;
}
static int F_41 ( struct V_92 * V_93 )
{
struct V_20 * V_24 = F_42 () ;
int V_106 = F_43 ( V_93 ) ;
if ( ! V_106 && ( V_24 -> V_25 != V_24 -> V_26 ) )
V_106 = 1 ;
return V_106 ;
}
static int F_44 ( struct V_2 * V_2 )
{
V_2 -> V_80 = F_5 ( F_22 () ) ;
if ( V_2 -> V_80 == NULL )
return - V_35 ;
return 0 ;
}
static void F_45 ( struct V_2 * V_2 )
{
F_4 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
}
static int F_46 ( struct V_2 * V_2 , struct V_2 * V_107 ,
const struct V_108 * V_108 , char * * V_1 ,
void * * V_109 , T_2 * V_110 )
{
struct V_111 * V_112 ;
struct V_13 * V_113 = V_2 -> V_80 ;
char * V_114 = F_22 () ;
char * V_15 = F_47 ( V_2 ) ;
char * V_115 = F_47 ( V_107 ) ;
int V_116 ;
if ( V_1 ) {
* V_1 = F_48 ( V_117 , V_16 ) ;
if ( * V_1 == NULL )
return - V_35 ;
}
if ( V_109 ) {
V_112 = F_49 ( V_114 ) ;
F_50 () ;
V_116 = F_51 ( V_114 , V_115 , & V_112 -> V_27 ) ;
F_52 () ;
if ( V_116 > 0 && ( ( V_116 & V_118 ) != 0 ) &&
F_53 ( V_107 ) ) {
V_15 = V_115 ;
V_113 -> V_18 |= V_119 ;
}
* V_109 = F_48 ( V_15 , V_16 ) ;
if ( * V_109 == NULL )
return - V_35 ;
}
if ( V_110 )
* V_110 = strlen ( V_15 ) + 1 ;
return 0 ;
}
static int F_54 ( struct V_4 * V_120 , struct V_2 * V_107 ,
struct V_4 * V_121 )
{
char * V_15 ;
struct V_40 V_41 ;
int V_6 ;
F_16 ( & V_41 , V_42 , V_83 ) ;
F_34 ( & V_41 , V_120 ) ;
V_15 = F_47 ( V_120 -> V_77 ) ;
V_6 = F_18 ( V_15 , V_88 , & V_41 ) ;
if ( V_6 == 0 && V_121 -> V_77 != NULL ) {
V_15 = F_47 ( V_121 -> V_77 ) ;
F_34 ( & V_41 , V_121 ) ;
V_6 = F_18 ( V_15 , V_88 , & V_41 ) ;
}
return V_6 ;
}
static int F_55 ( struct V_2 * V_107 , struct V_4 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_77 ;
struct V_40 V_41 ;
int V_6 ;
F_16 ( & V_41 , V_42 , V_83 ) ;
F_34 ( & V_41 , V_4 ) ;
V_6 = F_18 ( F_47 ( V_3 ) , V_88 , & V_41 ) ;
if ( V_6 == 0 ) {
F_34 ( & V_41 , NULL ) ;
F_56 ( & V_41 , V_107 ) ;
V_6 = F_18 ( F_47 ( V_107 ) , V_88 , & V_41 ) ;
}
return V_6 ;
}
static int F_57 ( struct V_2 * V_107 , struct V_4 * V_4 )
{
struct V_40 V_41 ;
int V_6 ;
F_16 ( & V_41 , V_42 , V_83 ) ;
F_34 ( & V_41 , V_4 ) ;
V_6 = F_18 ( F_47 ( V_4 -> V_77 ) , V_88 , & V_41 ) ;
if ( V_6 == 0 ) {
F_34 ( & V_41 , NULL ) ;
F_56 ( & V_41 , V_107 ) ;
V_6 = F_18 ( F_47 ( V_107 ) , V_88 , & V_41 ) ;
}
return V_6 ;
}
static int F_58 ( struct V_2 * V_122 ,
struct V_4 * V_120 ,
struct V_2 * V_123 ,
struct V_4 * V_121 )
{
int V_6 ;
char * V_15 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_83 ) ;
F_34 ( & V_41 , V_120 ) ;
V_15 = F_47 ( V_120 -> V_77 ) ;
V_6 = F_18 ( V_15 , V_44 , & V_41 ) ;
if ( V_6 == 0 && V_121 -> V_77 != NULL ) {
V_15 = F_47 ( V_121 -> V_77 ) ;
F_34 ( & V_41 , V_121 ) ;
V_6 = F_18 ( V_15 , V_44 , & V_41 ) ;
}
return V_6 ;
}
static int F_59 ( struct V_2 * V_2 , int V_124 )
{
struct V_40 V_41 ;
int V_125 = V_124 & V_126 ;
V_124 &= ( V_84 | V_88 | V_127 | V_128 ) ;
if ( V_124 == 0 )
return 0 ;
if ( V_125 )
return - V_129 ;
F_16 ( & V_41 , V_42 , V_130 ) ;
F_56 ( & V_41 , V_2 ) ;
return F_18 ( F_47 ( V_2 ) , V_124 , & V_41 ) ;
}
static int F_60 ( struct V_4 * V_4 , struct V_131 * V_131 )
{
struct V_40 V_41 ;
if ( V_131 -> V_132 & V_133 )
return 0 ;
F_16 ( & V_41 , V_42 , V_83 ) ;
F_34 ( & V_41 , V_4 ) ;
return F_18 ( F_47 ( V_4 -> V_77 ) , V_88 , & V_41 ) ;
}
static int F_61 ( struct V_89 * V_90 , struct V_4 * V_4 )
{
struct V_40 V_41 ;
struct V_86 V_86 ;
V_86 . V_4 = V_4 ;
V_86 . V_90 = V_90 ;
F_16 ( & V_41 , V_42 , V_87 ) ;
F_36 ( & V_41 , V_86 ) ;
return F_18 ( F_47 ( V_4 -> V_77 ) , V_84 , & V_41 ) ;
}
static int F_62 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_109 , T_2 V_134 , int V_73 )
{
struct V_40 V_41 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_135 ) == 0 ||
strcmp ( V_1 , V_136 ) == 0 ||
strcmp ( V_1 , V_137 ) == 0 ||
strcmp ( V_1 , V_138 ) == 0 ||
strcmp ( V_1 , V_139 ) == 0 ) {
if ( ! F_23 ( V_140 ) )
V_6 = - V_101 ;
if ( V_134 == 0 || V_134 >= V_11 ||
F_3 ( V_109 , V_134 ) == NULL )
V_6 = - V_141 ;
} else if ( strcmp ( V_1 , V_142 ) == 0 ) {
if ( ! F_23 ( V_140 ) )
V_6 = - V_101 ;
if ( V_134 != V_143 ||
strncmp ( V_109 , V_144 , V_143 ) != 0 )
V_6 = - V_141 ;
} else
V_6 = F_63 ( V_4 , V_1 , V_109 , V_134 , V_73 ) ;
F_16 ( & V_41 , V_42 , V_83 ) ;
F_34 ( & V_41 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_18 ( F_47 ( V_4 -> V_77 ) , V_88 , & V_41 ) ;
return V_6 ;
}
static void F_64 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_109 , T_2 V_134 , int V_73 )
{
char * V_79 ;
struct V_13 * V_15 = V_4 -> V_77 -> V_80 ;
if ( strcmp ( V_1 , V_135 ) == 0 ) {
V_79 = F_3 ( V_109 , V_134 ) ;
if ( V_79 != NULL )
V_15 -> V_17 = V_79 ;
else
V_15 -> V_17 = V_145 . V_50 ;
} else if ( strcmp ( V_1 , V_138 ) == 0 ) {
V_79 = F_3 ( V_109 , V_134 ) ;
if ( V_79 != NULL )
V_15 -> V_25 = V_79 ;
else
V_15 -> V_25 = V_145 . V_50 ;
} else if ( strcmp ( V_1 , V_139 ) == 0 ) {
V_79 = F_3 ( V_109 , V_134 ) ;
if ( V_79 != NULL )
V_15 -> V_146 = V_79 ;
else
V_15 -> V_146 = V_145 . V_50 ;
} else if ( strcmp ( V_1 , V_142 ) == 0 )
V_15 -> V_18 |= V_147 ;
return;
}
static int F_65 ( struct V_4 * V_4 , const char * V_1 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_83 ) ;
F_34 ( & V_41 , V_4 ) ;
return F_18 ( F_47 ( V_4 -> V_77 ) , V_84 , & V_41 ) ;
}
static int F_66 ( struct V_4 * V_4 , const char * V_1 )
{
struct V_13 * V_15 ;
struct V_40 V_41 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_135 ) == 0 ||
strcmp ( V_1 , V_136 ) == 0 ||
strcmp ( V_1 , V_137 ) == 0 ||
strcmp ( V_1 , V_138 ) == 0 ||
strcmp ( V_1 , V_142 ) == 0 ||
strcmp ( V_1 , V_139 ) ) {
if ( ! F_23 ( V_140 ) )
V_6 = - V_101 ;
} else
V_6 = F_67 ( V_4 , V_1 ) ;
F_16 ( & V_41 , V_42 , V_83 ) ;
F_34 ( & V_41 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_18 ( F_47 ( V_4 -> V_77 ) , V_88 , & V_41 ) ;
if ( V_6 == 0 ) {
V_15 = V_4 -> V_77 -> V_80 ;
V_15 -> V_25 = NULL ;
V_15 -> V_146 = NULL ;
}
return V_6 ;
}
static int F_68 ( const struct V_2 * V_2 ,
const char * V_1 , void * * V_7 ,
bool V_148 )
{
struct V_149 * V_150 ;
struct V_151 * V_152 ;
struct V_52 * V_81 ;
struct V_2 * V_3 = (struct V_2 * ) V_2 ;
char * V_15 ;
int V_153 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_117 ) == 0 ) {
V_15 = F_47 ( V_2 ) ;
V_153 = strlen ( V_15 ) + 1 ;
* V_7 = V_15 ;
return V_153 ;
}
V_81 = V_3 -> V_154 ;
if ( V_81 -> V_155 != V_156 )
return - V_157 ;
V_152 = F_69 ( V_3 ) ;
if ( V_152 == NULL || V_152 -> V_158 == NULL )
return - V_157 ;
V_150 = V_152 -> V_158 -> V_159 ;
if ( strcmp ( V_1 , V_160 ) == 0 )
V_15 = V_150 -> V_161 ;
else if ( strcmp ( V_1 , V_162 ) == 0 )
V_15 = V_150 -> V_163 ;
else
return - V_157 ;
V_153 = strlen ( V_15 ) + 1 ;
if ( V_6 == 0 ) {
* V_7 = V_15 ;
V_6 = V_153 ;
}
return V_6 ;
}
static int F_70 ( struct V_2 * V_2 , char * V_7 ,
T_2 V_164 )
{
int V_110 = strlen ( V_135 ) ;
if ( V_7 != NULL && V_110 <= V_164 ) {
memcpy ( V_7 , V_135 , V_110 ) ;
return V_110 ;
}
return - V_141 ;
}
static void F_71 ( const struct V_2 * V_2 , T_3 * V_165 )
{
struct V_13 * V_15 = V_2 -> V_80 ;
* V_165 = F_72 ( V_15 -> V_17 ) ;
}
static int F_73 ( struct V_94 * V_94 , int V_124 )
{
return 0 ;
}
static int F_74 ( struct V_94 * V_94 )
{
V_94 -> V_166 = F_22 () ;
return 0 ;
}
static void F_75 ( struct V_94 * V_94 )
{
V_94 -> V_166 = NULL ;
}
static int F_76 ( struct V_94 * V_94 , unsigned int V_167 ,
unsigned long V_168 )
{
int V_6 = 0 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_87 ) ;
F_36 ( & V_41 , V_94 -> V_95 ) ;
if ( F_77 ( V_167 ) & V_169 )
V_6 = F_18 ( V_94 -> V_166 , V_88 , & V_41 ) ;
if ( V_6 == 0 && ( F_77 ( V_167 ) & V_170 ) )
V_6 = F_18 ( V_94 -> V_166 , V_84 , & V_41 ) ;
return V_6 ;
}
static int F_78 ( struct V_94 * V_94 , unsigned int V_167 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_87 ) ;
F_36 ( & V_41 , V_94 -> V_95 ) ;
return F_18 ( V_94 -> V_166 , V_88 , & V_41 ) ;
}
static int F_79 ( struct V_94 * V_94 , unsigned int V_167 ,
unsigned long V_168 )
{
struct V_40 V_41 ;
int V_6 = 0 ;
switch ( V_167 ) {
case V_171 :
case V_172 :
case V_173 :
case V_174 :
case V_175 :
F_16 ( & V_41 , V_42 , V_87 ) ;
F_36 ( & V_41 , V_94 -> V_95 ) ;
V_6 = F_18 ( V_94 -> V_166 , V_88 , & V_41 ) ;
break;
default:
break;
}
return V_6 ;
}
static int F_80 ( struct V_94 * V_94 ,
unsigned long V_176 , unsigned long V_177 ,
unsigned long V_73 )
{
struct V_111 * V_112 ;
struct V_32 * V_178 ;
struct V_20 * V_24 ;
char * V_47 ;
char * V_179 ;
char * V_180 ;
struct V_13 * V_15 ;
struct V_4 * V_5 ;
int V_116 ;
int V_181 ;
int V_182 ;
int V_6 ;
if ( V_94 == NULL || V_94 -> V_183 == NULL )
return 0 ;
V_5 = V_94 -> V_183 ;
if ( V_5 -> V_77 == NULL )
return 0 ;
V_15 = V_5 -> V_77 -> V_80 ;
if ( V_15 -> V_146 == NULL )
return 0 ;
V_179 = V_15 -> V_146 ;
V_24 = F_42 () ;
V_47 = F_22 () ;
V_112 = F_49 ( V_47 ) ;
V_6 = 0 ;
F_50 () ;
F_10 (srp, &skp->smk_rules, list) {
V_180 = V_178 -> V_184 ;
if ( V_179 == V_180 )
continue;
V_116 = F_51 ( V_178 -> V_185 , V_180 ,
& V_24 -> V_27 ) ;
if ( V_116 == - V_186 )
V_116 = V_178 -> V_187 ;
else
V_116 &= V_178 -> V_187 ;
if ( V_116 == 0 )
continue;
V_112 = F_49 ( V_179 ) ;
V_181 = F_51 ( V_179 , V_180 , & V_112 -> V_27 ) ;
if ( V_181 == - V_186 ) {
V_6 = - V_51 ;
break;
}
V_182 = F_51 ( V_179 , V_180 , & V_24 -> V_27 ) ;
if ( V_182 != - V_186 )
V_181 &= V_182 ;
if ( ( V_116 | V_181 ) != V_181 ) {
V_6 = - V_51 ;
break;
}
}
F_52 () ;
return V_6 ;
}
static int F_81 ( struct V_94 * V_94 )
{
V_94 -> V_166 = F_22 () ;
return 0 ;
}
static int F_82 ( struct V_37 * V_188 ,
struct V_189 * V_190 , int V_191 )
{
struct V_94 * V_94 ;
int V_6 ;
char * V_24 = F_14 ( V_188 -> V_97 -> V_98 ) ;
struct V_40 V_41 ;
V_94 = F_83 ( V_190 , struct V_94 , V_192 ) ;
V_6 = V_187 ( V_94 -> V_166 , V_24 , V_88 , NULL ) ;
if ( V_6 != 0 && F_84 ( V_188 , V_48 ) )
V_6 = 0 ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_17 ( & V_41 , V_188 ) ;
F_85 ( V_94 -> V_166 , V_24 , V_88 , V_6 , & V_41 ) ;
return V_6 ;
}
static int F_86 ( struct V_94 * V_94 )
{
int V_116 = 0 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_36 ( & V_41 , V_94 -> V_95 ) ;
if ( V_94 -> V_193 & V_194 )
V_116 = V_84 ;
if ( V_94 -> V_193 & V_195 )
V_116 |= V_88 ;
return F_18 ( V_94 -> V_166 , V_116 , & V_41 ) ;
}
static int F_87 ( struct V_94 * V_94 , const struct V_97 * V_97 )
{
struct V_13 * V_15 = V_94 -> V_95 . V_4 -> V_77 -> V_80 ;
V_94 -> V_166 = V_15 -> V_17 ;
return 0 ;
}
static int F_88 ( struct V_97 * V_97 , T_1 V_23 )
{
struct V_20 * V_24 ;
V_24 = F_7 ( NULL , NULL , V_23 ) ;
if ( V_24 == NULL )
return - V_35 ;
V_97 -> V_98 = V_24 ;
return 0 ;
}
static void F_89 ( struct V_97 * V_97 )
{
struct V_20 * V_24 = V_97 -> V_98 ;
struct V_32 * V_196 ;
struct V_29 * V_197 ;
struct V_29 * V_198 ;
if ( V_24 == NULL )
return;
V_97 -> V_98 = NULL ;
F_90 (l, n, &tsp->smk_rules) {
V_196 = F_91 ( V_197 , struct V_32 , V_36 ) ;
F_92 ( & V_196 -> V_36 ) ;
F_4 ( V_196 ) ;
}
F_4 ( V_24 ) ;
}
static int F_93 ( struct V_97 * V_199 , const struct V_97 * V_200 ,
T_1 V_23 )
{
struct V_20 * V_201 = V_200 -> V_98 ;
struct V_20 * V_202 ;
int V_6 ;
V_202 = F_7 ( V_201 -> V_25 , V_201 -> V_25 , V_23 ) ;
if ( V_202 == NULL )
return - V_35 ;
V_6 = F_9 ( & V_202 -> V_27 , & V_201 -> V_27 , V_23 ) ;
if ( V_6 != 0 )
return V_6 ;
V_199 -> V_98 = V_202 ;
return 0 ;
}
static void F_94 ( struct V_97 * V_199 , const struct V_97 * V_200 )
{
struct V_20 * V_201 = V_200 -> V_98 ;
struct V_20 * V_202 = V_199 -> V_98 ;
V_202 -> V_25 = V_201 -> V_25 ;
V_202 -> V_26 = V_201 -> V_25 ;
F_6 ( & V_202 -> V_28 ) ;
F_8 ( & V_202 -> V_27 ) ;
}
static int F_95 ( struct V_97 * V_199 , T_3 V_165 )
{
struct V_20 * V_202 = V_199 -> V_98 ;
char * V_14 = F_96 ( V_165 ) ;
if ( V_14 == NULL )
return - V_141 ;
V_202 -> V_25 = V_14 ;
return 0 ;
}
static int F_97 ( struct V_97 * V_199 ,
struct V_2 * V_2 )
{
struct V_13 * V_15 = V_2 -> V_80 ;
struct V_20 * V_24 = V_199 -> V_98 ;
V_24 -> V_26 = V_15 -> V_17 ;
V_24 -> V_25 = V_15 -> V_17 ;
return 0 ;
}
static int F_98 ( struct V_37 * V_203 , int V_204 ,
const char * V_205 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_205 , V_43 ) ;
F_17 ( & V_41 , V_203 ) ;
return F_18 ( F_14 ( F_15 ( V_203 ) ) , V_204 , & V_41 ) ;
}
static int F_99 ( struct V_37 * V_203 , T_4 V_206 )
{
return F_98 ( V_203 , V_88 , V_42 ) ;
}
static int F_100 ( struct V_37 * V_203 )
{
return F_98 ( V_203 , V_84 , V_42 ) ;
}
static int F_101 ( struct V_37 * V_203 )
{
return F_98 ( V_203 , V_84 , V_42 ) ;
}
static void F_102 ( struct V_37 * V_203 , T_3 * V_165 )
{
* V_165 = F_72 ( F_14 ( F_15 ( V_203 ) ) ) ;
}
static int F_103 ( struct V_37 * V_203 , int V_207 )
{
int V_6 ;
V_6 = F_104 ( V_203 , V_207 ) ;
if ( V_6 == 0 )
V_6 = F_98 ( V_203 , V_88 , V_42 ) ;
return V_6 ;
}
static int F_105 ( struct V_37 * V_203 , int V_208 )
{
int V_6 ;
V_6 = F_106 ( V_203 , V_208 ) ;
if ( V_6 == 0 )
V_6 = F_98 ( V_203 , V_88 , V_42 ) ;
return V_6 ;
}
static int F_107 ( struct V_37 * V_203 )
{
return F_98 ( V_203 , V_84 , V_42 ) ;
}
static int F_108 ( struct V_37 * V_203 )
{
int V_6 ;
V_6 = F_109 ( V_203 ) ;
if ( V_6 == 0 )
V_6 = F_98 ( V_203 , V_88 , V_42 ) ;
return V_6 ;
}
static int F_110 ( struct V_37 * V_203 )
{
return F_98 ( V_203 , V_84 , V_42 ) ;
}
static int F_111 ( struct V_37 * V_203 )
{
return F_98 ( V_203 , V_88 , V_42 ) ;
}
static int F_112 ( struct V_37 * V_203 , struct V_209 * V_210 ,
int V_211 , T_3 V_165 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_17 ( & V_41 , V_203 ) ;
if ( V_165 == 0 )
return F_18 ( F_14 ( F_15 ( V_203 ) ) , V_88 ,
& V_41 ) ;
return V_187 ( F_96 ( V_165 ) ,
F_14 ( F_15 ( V_203 ) ) , V_88 , & V_41 ) ;
}
static int F_113 ( struct V_37 * V_203 )
{
struct V_40 V_41 ;
char * V_47 = F_22 () ;
char * V_24 = F_114 ( F_15 ( V_203 ) ) ;
int V_6 ;
V_6 = V_187 ( V_24 , V_47 , V_88 , NULL ) ;
if ( V_6 == 0 )
goto V_212;
if ( F_23 ( V_48 ) || F_84 ( V_203 , V_48 ) )
V_6 = 0 ;
V_212:
F_16 ( & V_41 , V_42 , V_43 ) ;
F_17 ( & V_41 , V_203 ) ;
F_85 ( V_24 , V_47 , V_88 , V_6 , & V_41 ) ;
return V_6 ;
}
static void F_115 ( struct V_37 * V_203 , struct V_2 * V_2 )
{
struct V_13 * V_15 = V_2 -> V_80 ;
V_15 -> V_17 = F_14 ( F_15 ( V_203 ) ) ;
}
static int F_116 ( struct V_152 * V_158 , int V_213 , T_1 V_214 )
{
char * V_114 = F_22 () ;
struct V_149 * V_150 ;
V_150 = F_2 ( sizeof( struct V_149 ) , V_214 ) ;
if ( V_150 == NULL )
return - V_35 ;
V_150 -> V_161 = V_114 ;
V_150 -> V_163 = V_114 ;
V_150 -> V_215 = NULL ;
V_158 -> V_159 = V_150 ;
return 0 ;
}
static void F_117 ( struct V_152 * V_158 )
{
F_4 ( V_158 -> V_159 ) ;
}
static char * F_118 ( struct V_216 * V_217 )
{
struct V_218 * V_219 ;
struct V_220 * V_221 = & V_217 -> V_222 ;
if ( V_221 -> V_223 == 0 )
return NULL ;
F_10 (snp, &smk_netlbladdr_list, list)
if ( ( & V_219 -> V_224 . V_222 ) -> V_223 ==
( V_221 -> V_223 & ( & V_219 -> V_225 ) -> V_223 ) ) {
if ( V_219 -> V_226 == V_227 )
return NULL ;
return V_219 -> V_226 ;
}
return NULL ;
}
static int F_119 ( struct V_152 * V_158 , int V_228 )
{
struct V_111 * V_112 ;
struct V_149 * V_150 = V_158 -> V_159 ;
int V_6 = 0 ;
F_120 () ;
F_121 ( V_158 ) ;
if ( V_150 -> V_163 == V_229 ||
V_228 == V_230 )
F_122 ( V_158 ) ;
else {
V_112 = F_49 ( V_150 -> V_163 ) ;
V_6 = F_123 ( V_158 , V_158 -> V_231 , & V_112 -> V_232 ) ;
}
F_124 ( V_158 ) ;
F_125 () ;
return V_6 ;
}
static int F_126 ( struct V_152 * V_158 , struct V_216 * V_233 )
{
int V_6 ;
int V_234 ;
char * V_235 ;
struct V_149 * V_150 = V_158 -> V_159 ;
struct V_40 V_41 ;
F_50 () ;
V_235 = F_118 ( V_233 ) ;
if ( V_235 != NULL ) {
#ifdef F_127
struct V_236 V_237 ;
F_128 ( & V_41 , V_42 , V_238 , & V_237 ) ;
V_41 . V_239 . V_240 . V_237 -> V_213 = V_233 -> V_241 ;
V_41 . V_239 . V_240 . V_237 -> V_242 = V_233 -> V_243 ;
V_41 . V_239 . V_240 . V_237 -> V_244 . V_245 = V_233 -> V_222 . V_223 ;
#endif
V_234 = V_230 ;
V_6 = V_187 ( V_150 -> V_163 , V_235 , V_88 , & V_41 ) ;
} else {
V_234 = V_246 ;
V_6 = 0 ;
}
F_52 () ;
if ( V_6 != 0 )
return V_6 ;
return F_119 ( V_158 , V_234 ) ;
}
static int F_129 ( struct V_2 * V_2 , const char * V_1 ,
const void * V_109 , T_2 V_134 , int V_73 )
{
char * V_47 ;
struct V_13 * V_79 = V_2 -> V_80 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
int V_6 = 0 ;
if ( V_109 == NULL || V_134 > V_11 || V_134 == 0 )
return - V_51 ;
V_47 = F_3 ( V_109 , V_134 ) ;
if ( V_47 == NULL )
return - V_141 ;
if ( strcmp ( V_1 , V_117 ) == 0 ) {
V_79 -> V_17 = V_47 ;
V_79 -> V_18 |= V_247 ;
return 0 ;
}
if ( V_2 -> V_154 -> V_155 != V_156 )
return - V_157 ;
V_152 = F_69 ( V_2 ) ;
if ( V_152 == NULL || V_152 -> V_158 == NULL )
return - V_157 ;
V_150 = V_152 -> V_158 -> V_159 ;
if ( strcmp ( V_1 , V_160 ) == 0 )
V_150 -> V_161 = V_47 ;
else if ( strcmp ( V_1 , V_162 ) == 0 ) {
V_150 -> V_163 = V_47 ;
if ( V_152 -> V_158 -> V_231 != V_248 ) {
V_6 = F_119 ( V_152 -> V_158 , V_246 ) ;
if ( V_6 != 0 )
F_130 ( V_249
L_2 ,
V_42 , - V_6 ) ;
}
} else
return - V_157 ;
return 0 ;
}
static int F_131 ( struct V_151 * V_152 , int V_213 ,
int type , int V_250 , int V_251 )
{
if ( V_213 != V_252 || V_152 -> V_158 == NULL )
return 0 ;
return F_119 ( V_152 -> V_158 , V_246 ) ;
}
static int F_132 ( struct V_151 * V_152 , struct V_253 * V_233 ,
int V_254 )
{
if ( V_152 -> V_158 == NULL || V_152 -> V_158 -> V_231 != V_252 )
return 0 ;
if ( V_254 < sizeof( struct V_216 ) )
return - V_141 ;
return F_126 ( V_152 -> V_158 , (struct V_216 * ) V_233 ) ;
}
static int F_133 ( int V_73 )
{
int V_116 = 0 ;
if ( V_73 & V_255 )
V_116 |= V_84 ;
if ( V_73 & V_256 )
V_116 |= V_88 ;
if ( V_73 & V_257 )
V_116 |= V_127 ;
return V_116 ;
}
static int F_134 ( struct V_258 * V_259 )
{
V_259 -> V_98 = F_22 () ;
return 0 ;
}
static void F_135 ( struct V_258 * V_259 )
{
V_259 -> V_98 = NULL ;
}
static char * F_136 ( struct V_260 * V_261 )
{
return ( char * ) V_261 -> V_262 . V_98 ;
}
static int F_137 ( struct V_260 * V_261 )
{
struct V_263 * V_15 = & V_261 -> V_262 ;
V_15 -> V_98 = F_22 () ;
return 0 ;
}
static void F_138 ( struct V_260 * V_261 )
{
struct V_263 * V_15 = & V_261 -> V_262 ;
V_15 -> V_98 = NULL ;
}
static int F_139 ( struct V_260 * V_261 , int V_204 )
{
char * V_150 = F_136 ( V_261 ) ;
struct V_40 V_41 ;
#ifdef F_127
F_16 ( & V_41 , V_42 , V_264 ) ;
V_41 . V_239 . V_240 . V_265 = V_261 -> V_262 . V_266 ;
#endif
return F_18 ( V_150 , V_204 , & V_41 ) ;
}
static int F_140 ( struct V_260 * V_261 , int V_267 )
{
int V_116 ;
V_116 = F_133 ( V_267 ) ;
return F_139 ( V_261 , V_116 ) ;
}
static int F_141 ( struct V_260 * V_261 , int V_167 )
{
int V_116 ;
switch ( V_167 ) {
case V_268 :
case V_269 :
V_116 = V_84 ;
break;
case V_270 :
case V_271 :
case V_272 :
case V_273 :
V_116 = V_44 ;
break;
case V_274 :
case V_275 :
return 0 ;
default:
return - V_141 ;
}
return F_139 ( V_261 , V_116 ) ;
}
static int F_142 ( struct V_260 * V_261 , char T_5 * V_276 ,
int V_267 )
{
int V_116 ;
V_116 = F_133 ( V_267 ) ;
return F_139 ( V_261 , V_116 ) ;
}
static char * F_143 ( struct V_277 * V_278 )
{
return ( char * ) V_278 -> V_279 . V_98 ;
}
static int F_144 ( struct V_277 * V_278 )
{
struct V_263 * V_15 = & V_278 -> V_279 ;
V_15 -> V_98 = F_22 () ;
return 0 ;
}
static void F_145 ( struct V_277 * V_278 )
{
struct V_263 * V_15 = & V_278 -> V_279 ;
V_15 -> V_98 = NULL ;
}
static int F_146 ( struct V_277 * V_278 , int V_204 )
{
char * V_150 = F_143 ( V_278 ) ;
struct V_40 V_41 ;
#ifdef F_127
F_16 ( & V_41 , V_42 , V_264 ) ;
V_41 . V_239 . V_240 . V_265 = V_278 -> V_279 . V_266 ;
#endif
return F_18 ( V_150 , V_204 , & V_41 ) ;
}
static int F_147 ( struct V_277 * V_278 , int V_280 )
{
int V_116 ;
V_116 = F_133 ( V_280 ) ;
return F_146 ( V_278 , V_116 ) ;
}
static int F_148 ( struct V_277 * V_278 , int V_167 )
{
int V_116 ;
switch ( V_167 ) {
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_285 :
case V_268 :
case V_286 :
V_116 = V_84 ;
break;
case V_287 :
case V_288 :
case V_273 :
case V_270 :
V_116 = V_44 ;
break;
case V_274 :
case V_289 :
return 0 ;
default:
return - V_141 ;
}
return F_146 ( V_278 , V_116 ) ;
}
static int F_149 ( struct V_277 * V_278 , struct V_290 * V_291 ,
unsigned V_292 , int V_293 )
{
return F_146 ( V_278 , V_44 ) ;
}
static int F_150 ( struct V_294 * V_295 )
{
struct V_263 * V_296 = & V_295 -> V_297 ;
V_296 -> V_98 = F_22 () ;
return 0 ;
}
static void F_151 ( struct V_294 * V_295 )
{
struct V_263 * V_296 = & V_295 -> V_297 ;
V_296 -> V_98 = NULL ;
}
static char * F_152 ( struct V_294 * V_295 )
{
return ( char * ) V_295 -> V_297 . V_98 ;
}
static int F_153 ( struct V_294 * V_295 , int V_204 )
{
char * V_298 = F_152 ( V_295 ) ;
struct V_40 V_41 ;
#ifdef F_127
F_16 ( & V_41 , V_42 , V_264 ) ;
V_41 . V_239 . V_240 . V_265 = V_295 -> V_297 . V_266 ;
#endif
return F_18 ( V_298 , V_204 , & V_41 ) ;
}
static int F_154 ( struct V_294 * V_295 , int V_299 )
{
int V_116 ;
V_116 = F_133 ( V_299 ) ;
return F_153 ( V_295 , V_116 ) ;
}
static int F_155 ( struct V_294 * V_295 , int V_167 )
{
int V_116 ;
switch ( V_167 ) {
case V_268 :
case V_300 :
V_116 = V_84 ;
break;
case V_270 :
case V_273 :
V_116 = V_44 ;
break;
case V_274 :
case V_301 :
return 0 ;
default:
return - V_141 ;
}
return F_153 ( V_295 , V_116 ) ;
}
static int F_156 ( struct V_294 * V_295 , struct V_258 * V_259 ,
int V_299 )
{
int V_116 ;
V_116 = F_133 ( V_299 ) ;
return F_153 ( V_295 , V_116 ) ;
}
static int F_157 ( struct V_294 * V_295 , struct V_258 * V_259 ,
struct V_37 * V_302 , long type , int V_39 )
{
return F_153 ( V_295 , V_44 ) ;
}
static int F_158 ( struct V_263 * V_303 , short V_304 )
{
char * V_15 = V_303 -> V_98 ;
int V_116 = F_133 ( V_304 ) ;
struct V_40 V_41 ;
#ifdef F_127
F_16 ( & V_41 , V_42 , V_264 ) ;
V_41 . V_239 . V_240 . V_265 = V_303 -> V_266 ;
#endif
return F_18 ( V_15 , V_116 , & V_41 ) ;
}
static void F_159 ( struct V_263 * V_303 , T_3 * V_165 )
{
char * V_14 = V_303 -> V_98 ;
* V_165 = F_72 ( V_14 ) ;
}
static void F_160 ( struct V_4 * V_305 , struct V_2 * V_2 )
{
struct V_52 * V_81 ;
struct V_54 * V_55 ;
struct V_13 * V_15 ;
char * V_114 = F_22 () ;
char * V_306 ;
char * V_307 ;
char V_308 [ V_143 ] ;
int V_309 = 0 ;
int V_6 ;
struct V_4 * V_5 ;
if ( V_2 == NULL )
return;
V_15 = V_2 -> V_80 ;
F_161 ( & V_15 -> V_19 ) ;
if ( V_15 -> V_18 & V_247 )
goto V_310;
V_81 = V_2 -> V_154 ;
V_55 = V_81 -> V_63 ;
V_307 = V_55 -> V_57 ;
if ( V_305 -> V_311 == V_305 ) {
V_15 -> V_17 = V_55 -> V_56 ;
V_15 -> V_18 |= V_247 ;
goto V_310;
}
switch ( V_81 -> V_155 ) {
case V_312 :
V_307 = V_313 . V_50 ;
break;
case V_314 :
V_307 = V_313 . V_50 ;
break;
case V_315 :
V_307 = V_114 ;
break;
case V_156 :
V_307 = V_313 . V_50 ;
break;
case V_316 :
break;
case V_317 :
V_307 = V_313 . V_50 ;
default:
if ( F_162 ( V_2 -> V_318 ) ) {
V_307 = V_313 . V_50 ;
break;
}
if ( V_2 -> V_9 -> V_10 == NULL )
break;
V_5 = F_163 ( V_305 ) ;
V_306 = F_1 ( V_135 , V_2 , V_5 ) ;
if ( V_306 != NULL )
V_307 = V_306 ;
if ( F_164 ( V_2 -> V_318 ) ) {
if ( V_15 -> V_18 & V_119 ) {
V_15 -> V_18 &= ~ V_119 ;
V_6 = V_2 -> V_9 -> V_319 ( V_5 ,
V_142 ,
V_144 , V_143 ,
0 ) ;
} else {
V_6 = V_2 -> V_9 -> V_10 ( V_5 ,
V_142 , V_308 ,
V_143 ) ;
if ( V_6 >= 0 && strncmp ( V_308 , V_144 ,
V_143 ) != 0 )
V_6 = - V_141 ;
}
if ( V_6 >= 0 )
V_309 = V_147 ;
}
V_15 -> V_25 = F_1 ( V_138 , V_2 , V_5 ) ;
V_15 -> V_146 = F_1 ( V_139 , V_2 , V_5 ) ;
F_165 ( V_5 ) ;
break;
}
if ( V_307 == NULL )
V_15 -> V_17 = V_114 ;
else
V_15 -> V_17 = V_307 ;
V_15 -> V_18 |= ( V_247 | V_309 ) ;
V_310:
F_166 ( & V_15 -> V_19 ) ;
return;
}
static int F_167 ( struct V_37 * V_203 , char * V_1 , char * * V_109 )
{
char * V_66 ;
int V_320 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_141 ;
V_66 = F_48 ( F_14 ( F_15 ( V_203 ) ) , V_12 ) ;
if ( V_66 == NULL )
return - V_35 ;
V_320 = strlen ( V_66 ) ;
* V_109 = V_66 ;
return V_320 ;
}
static int F_168 ( struct V_37 * V_203 , char * V_1 ,
void * V_109 , T_2 V_134 )
{
int V_6 ;
struct V_20 * V_24 ;
struct V_20 * V_321 ;
struct V_97 * V_199 ;
char * V_322 ;
if ( V_203 != V_104 )
return - V_101 ;
if ( ! F_23 ( V_140 ) )
return - V_101 ;
if ( V_109 == NULL || V_134 == 0 || V_134 >= V_11 )
return - V_141 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_141 ;
V_322 = F_3 ( V_109 , V_134 ) ;
if ( V_322 == NULL )
return - V_141 ;
if ( V_322 == V_323 . V_50 )
return - V_101 ;
V_321 = V_203 -> V_97 -> V_98 ;
V_199 = F_169 () ;
if ( V_199 == NULL )
return - V_35 ;
V_24 = F_7 ( V_322 , V_321 -> V_26 , V_12 ) ;
if ( V_24 == NULL ) {
F_4 ( V_199 ) ;
return - V_35 ;
}
V_6 = F_9 ( & V_24 -> V_27 , & V_321 -> V_27 , V_12 ) ;
if ( V_6 != 0 )
return V_6 ;
V_199 -> V_98 = V_24 ;
F_170 ( V_199 ) ;
return V_134 ;
}
static int F_171 ( struct V_152 * V_152 ,
struct V_152 * V_324 , struct V_152 * V_325 )
{
struct V_149 * V_150 = V_152 -> V_159 ;
struct V_149 * V_326 = V_324 -> V_159 ;
struct V_149 * V_79 = V_325 -> V_159 ;
struct V_40 V_41 ;
int V_6 = 0 ;
#ifdef F_127
struct V_236 V_237 ;
F_128 ( & V_41 , V_42 , V_238 , & V_237 ) ;
F_172 ( & V_41 , V_324 ) ;
#endif
if ( ! F_23 ( V_48 ) )
V_6 = V_187 ( V_150 -> V_163 , V_326 -> V_161 , V_88 , & V_41 ) ;
if ( V_6 == 0 ) {
V_79 -> V_215 = V_150 -> V_163 ;
V_150 -> V_215 = V_326 -> V_163 ;
}
return V_6 ;
}
static int F_173 ( struct V_151 * V_152 , struct V_151 * V_324 )
{
struct V_149 * V_150 = V_152 -> V_158 -> V_159 ;
struct V_149 * V_326 = V_324 -> V_158 -> V_159 ;
struct V_40 V_41 ;
int V_6 = 0 ;
#ifdef F_127
struct V_236 V_237 ;
F_128 ( & V_41 , V_42 , V_238 , & V_237 ) ;
F_172 ( & V_41 , V_324 -> V_158 ) ;
#endif
if ( ! F_23 ( V_48 ) )
V_6 = V_187 ( V_150 -> V_163 , V_326 -> V_161 , V_88 , & V_41 ) ;
return V_6 ;
}
static int F_174 ( struct V_151 * V_152 , struct V_327 * V_259 ,
int V_134 )
{
struct V_216 * V_217 = (struct V_216 * ) V_259 -> V_328 ;
if ( V_217 == NULL || V_217 -> V_241 != V_329 )
return 0 ;
return F_126 ( V_152 -> V_158 , V_217 ) ;
}
static char * F_175 ( struct V_330 * V_233 ,
struct V_149 * V_150 )
{
struct V_111 * V_331 ;
char * V_47 ;
int V_332 = 0 ;
if ( ( V_233 -> V_73 & V_333 ) != 0 ) {
F_50 () ;
F_176 (kp, &smack_known_list, list) {
if ( V_233 -> V_334 . V_335 . V_336 != V_331 -> V_232 . V_334 . V_335 . V_336 )
continue;
if ( memcmp ( V_233 -> V_334 . V_335 . V_337 ,
V_331 -> V_232 . V_334 . V_335 . V_337 ,
V_338 ) != 0 )
continue;
V_332 = 1 ;
break;
}
F_52 () ;
if ( V_332 )
return V_331 -> V_50 ;
if ( V_150 != NULL && V_150 -> V_161 == V_313 . V_50 )
return V_323 . V_50 ;
return V_313 . V_50 ;
}
if ( ( V_233 -> V_73 & V_339 ) != 0 ) {
V_47 = F_96 ( V_233 -> V_334 . V_165 ) ;
F_177 ( V_47 == NULL ) ;
return V_47 ;
}
return V_229 ;
}
static int F_178 ( struct V_152 * V_158 , struct V_340 * V_341 )
{
struct V_330 V_342 ;
struct V_149 * V_150 = V_158 -> V_159 ;
char * V_114 ;
int V_6 ;
struct V_40 V_41 ;
#ifdef F_127
struct V_236 V_237 ;
#endif
if ( V_158 -> V_231 != V_252 && V_158 -> V_231 != V_343 )
return 0 ;
F_179 ( & V_342 ) ;
V_6 = F_180 ( V_341 , V_158 -> V_231 , & V_342 ) ;
if ( V_6 == 0 )
V_114 = F_175 ( & V_342 , V_150 ) ;
else
V_114 = V_229 ;
F_181 ( & V_342 ) ;
#ifdef F_127
F_128 ( & V_41 , V_42 , V_238 , & V_237 ) ;
V_41 . V_239 . V_240 . V_237 -> V_213 = V_158 -> V_231 ;
V_41 . V_239 . V_240 . V_237 -> V_344 = V_341 -> V_345 ;
F_182 ( V_341 , & V_41 . V_239 , NULL ) ;
#endif
V_6 = V_187 ( V_114 , V_150 -> V_161 , V_88 , & V_41 ) ;
if ( V_6 != 0 )
F_183 ( V_341 , V_6 , 0 ) ;
return V_6 ;
}
static int F_184 ( struct V_151 * V_152 ,
char T_5 * V_346 ,
int T_5 * V_347 , unsigned V_110 )
{
struct V_149 * V_150 ;
char * V_348 = L_4 ;
int V_320 = 1 ;
int V_6 = 0 ;
V_150 = V_152 -> V_158 -> V_159 ;
if ( V_150 -> V_215 != NULL ) {
V_348 = V_150 -> V_215 ;
V_320 = strlen ( V_348 ) + 1 ;
}
if ( V_320 > V_110 )
V_6 = - V_349 ;
else if ( F_185 ( V_346 , V_348 , V_320 ) != 0 )
V_6 = - V_350 ;
if ( F_186 ( V_320 , V_347 ) != 0 )
V_6 = - V_350 ;
return V_6 ;
}
static int F_187 ( struct V_151 * V_152 ,
struct V_340 * V_341 , T_3 * V_165 )
{
struct V_330 V_342 ;
struct V_149 * V_150 = NULL ;
char * V_47 ;
int V_213 = V_351 ;
T_3 V_352 = 0 ;
int V_6 ;
if ( V_341 != NULL ) {
if ( V_341 -> V_250 == F_188 ( V_353 ) )
V_213 = V_252 ;
else if ( V_341 -> V_250 == F_188 ( V_354 ) )
V_213 = V_343 ;
}
if ( V_213 == V_351 && V_152 != NULL )
V_213 = V_152 -> V_158 -> V_231 ;
if ( V_213 == V_248 ) {
V_150 = V_152 -> V_158 -> V_159 ;
V_352 = F_72 ( V_150 -> V_163 ) ;
} else if ( V_213 == V_252 || V_213 == V_343 ) {
if ( V_152 != NULL && V_152 -> V_158 != NULL )
V_150 = V_152 -> V_158 -> V_159 ;
F_179 ( & V_342 ) ;
V_6 = F_180 ( V_341 , V_213 , & V_342 ) ;
if ( V_6 == 0 ) {
V_47 = F_175 ( & V_342 , V_150 ) ;
V_352 = F_72 ( V_47 ) ;
}
F_181 ( & V_342 ) ;
}
* V_165 = V_352 ;
if ( V_352 == 0 )
return - V_141 ;
return 0 ;
}
static void F_189 ( struct V_152 * V_158 , struct V_151 * V_355 )
{
struct V_149 * V_150 ;
if ( V_158 == NULL ||
( V_158 -> V_231 != V_252 && V_158 -> V_231 != V_343 ) )
return;
V_150 = V_158 -> V_159 ;
V_150 -> V_161 = V_150 -> V_163 = F_22 () ;
}
static int F_190 ( struct V_152 * V_158 , struct V_340 * V_341 ,
struct V_356 * V_357 )
{
T_6 V_213 = V_158 -> V_231 ;
struct V_111 * V_112 ;
struct V_149 * V_150 = V_158 -> V_159 ;
struct V_330 V_342 ;
struct V_216 V_358 ;
struct V_359 * V_360 ;
char * V_47 ;
char * V_361 ;
int V_6 ;
struct V_40 V_41 ;
#ifdef F_127
struct V_236 V_237 ;
#endif
if ( V_213 == V_343 && V_341 -> V_250 == F_188 ( V_353 ) )
V_213 = V_252 ;
F_179 ( & V_342 ) ;
V_6 = F_180 ( V_341 , V_213 , & V_342 ) ;
if ( V_6 == 0 )
V_47 = F_175 ( & V_342 , V_150 ) ;
else
V_47 = V_362 . V_50 ;
F_181 ( & V_342 ) ;
#ifdef F_127
F_128 ( & V_41 , V_42 , V_238 , & V_237 ) ;
V_41 . V_239 . V_240 . V_237 -> V_213 = V_213 ;
V_41 . V_239 . V_240 . V_237 -> V_344 = V_341 -> V_345 ;
F_182 ( V_341 , & V_41 . V_239 , NULL ) ;
#endif
V_6 = V_187 ( V_47 , V_150 -> V_161 , V_88 , & V_41 ) ;
if ( V_6 != 0 )
return V_6 ;
V_357 -> V_363 = F_72 ( V_47 ) ;
V_360 = F_191 ( V_341 ) ;
V_358 . V_222 . V_223 = V_360 -> V_364 ;
F_50 () ;
V_361 = F_118 ( & V_358 ) ;
F_52 () ;
if ( V_361 == NULL ) {
V_112 = F_49 ( V_47 ) ;
V_6 = F_192 ( V_357 , & V_112 -> V_232 ) ;
} else
F_193 ( V_357 ) ;
return V_6 ;
}
static void F_194 ( struct V_152 * V_158 ,
const struct V_356 * V_357 )
{
struct V_149 * V_150 = V_158 -> V_159 ;
if ( V_357 -> V_363 != 0 )
V_150 -> V_215 = F_96 ( V_357 -> V_363 ) ;
else
V_150 -> V_215 = NULL ;
}
static int F_195 ( struct V_365 * V_365 , const struct V_97 * V_97 ,
unsigned long V_73 )
{
V_365 -> V_98 = F_14 ( V_97 -> V_98 ) ;
return 0 ;
}
static void F_196 ( struct V_365 * V_365 )
{
V_365 -> V_98 = NULL ;
}
static int F_197 ( T_7 V_366 ,
const struct V_97 * V_97 , T_8 V_367 )
{
struct V_365 * V_368 ;
struct V_40 V_41 ;
char * V_24 = F_14 ( V_97 -> V_98 ) ;
V_368 = F_198 ( V_366 ) ;
if ( V_368 == NULL )
return - V_141 ;
if ( V_368 -> V_98 == NULL )
return 0 ;
if ( V_24 == NULL )
return - V_51 ;
#ifdef F_127
F_16 ( & V_41 , V_42 , V_369 ) ;
V_41 . V_239 . V_240 . V_370 . V_365 = V_368 -> V_371 ;
V_41 . V_239 . V_240 . V_370 . V_372 = V_368 -> V_373 ;
#endif
return V_187 ( V_24 , V_368 -> V_98 ,
V_44 , & V_41 ) ;
}
static int F_199 ( T_3 V_374 , T_3 V_78 , char * V_375 , void * * V_376 )
{
char * * V_377 = ( char * * ) V_376 ;
* V_377 = NULL ;
if ( V_374 != V_378 && V_374 != V_379 )
return - V_141 ;
if ( V_78 != V_380 && V_78 != V_381 )
return - V_141 ;
* V_377 = F_3 ( V_375 , 0 ) ;
return 0 ;
}
static int F_200 ( struct V_382 * V_383 )
{
struct V_384 * V_385 ;
int V_386 ;
for ( V_386 = 0 ; V_386 < V_383 -> V_387 ; V_386 ++ ) {
V_385 = & V_383 -> V_388 [ V_386 ] ;
if ( V_385 -> type == V_378 || V_385 -> type == V_379 )
return 1 ;
}
return 0 ;
}
static int F_201 ( T_3 V_165 , T_3 V_374 , T_3 V_78 , void * V_376 ,
struct V_389 * V_390 )
{
char * V_14 ;
char * V_377 = V_376 ;
if ( ! V_377 ) {
F_202 ( V_390 , V_391 , V_392 ,
L_5 ) ;
return - V_186 ;
}
if ( V_374 != V_378 && V_374 != V_379 )
return 0 ;
V_14 = F_96 ( V_165 ) ;
if ( V_78 == V_380 )
return ( V_377 == V_14 ) ;
if ( V_78 == V_381 )
return ( V_377 != V_14 ) ;
return 0 ;
}
static void F_203 ( void * V_376 )
{
}
static int F_204 ( T_3 V_165 , char * * V_393 , T_3 * V_394 )
{
char * V_47 = F_96 ( V_165 ) ;
if ( V_393 )
* V_393 = V_47 ;
* V_394 = strlen ( V_47 ) ;
return 0 ;
}
static int F_205 ( const char * V_393 , T_3 V_394 , T_3 * V_165 )
{
* V_165 = F_72 ( V_393 ) ;
return 0 ;
}
static void F_206 ( char * V_393 , T_3 V_394 )
{
}
static int F_207 ( struct V_2 * V_2 , void * V_395 , T_3 V_396 )
{
return F_129 ( V_2 , V_117 , V_395 , V_396 , 0 ) ;
}
static int F_208 ( struct V_4 * V_4 , void * V_395 , T_3 V_396 )
{
return F_209 ( V_4 , V_135 , V_395 , V_396 , 0 ) ;
}
static int F_210 ( struct V_2 * V_2 , void * * V_395 , T_3 * V_396 )
{
int V_110 = 0 ;
V_110 = F_68 ( V_2 , V_117 , V_395 , true ) ;
if ( V_110 < 0 )
return V_110 ;
* V_396 = V_110 ;
return 0 ;
}
static T_9 void F_211 ( void )
{
F_6 ( & V_362 . V_28 ) ;
F_6 ( & V_60 . V_28 ) ;
F_6 ( & V_49 . V_28 ) ;
F_6 ( & V_313 . V_28 ) ;
F_6 ( & V_145 . V_28 ) ;
F_6 ( & V_323 . V_28 ) ;
F_8 ( & V_362 . V_27 ) ;
F_8 ( & V_60 . V_27 ) ;
F_8 ( & V_313 . V_27 ) ;
F_8 ( & V_49 . V_27 ) ;
F_8 ( & V_145 . V_27 ) ;
F_8 ( & V_323 . V_27 ) ;
F_212 ( & V_362 . V_36 , & V_397 ) ;
F_212 ( & V_60 . V_36 , & V_397 ) ;
F_212 ( & V_313 . V_36 , & V_397 ) ;
F_212 ( & V_49 . V_36 , & V_397 ) ;
F_212 ( & V_145 . V_36 , & V_397 ) ;
F_212 ( & V_323 . V_36 , & V_397 ) ;
}
static T_9 int F_213 ( void )
{
struct V_97 * V_97 ;
struct V_20 * V_24 ;
if ( ! F_214 ( & V_398 ) )
return 0 ;
V_24 = F_7 ( V_49 . V_50 ,
V_49 . V_50 , V_12 ) ;
if ( V_24 == NULL )
return - V_35 ;
F_130 ( V_399 L_6 ) ;
V_97 = (struct V_97 * ) V_104 -> V_97 ;
V_97 -> V_98 = V_24 ;
F_211 () ;
if ( F_215 ( & V_398 ) )
F_216 ( L_7 ) ;
return 0 ;
}

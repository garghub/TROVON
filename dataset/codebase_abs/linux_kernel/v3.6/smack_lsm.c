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
static int F_32 ( char * V_84 , struct V_85 * V_85 ,
char * type , unsigned long V_72 , void * V_73 )
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
struct V_40 V_41 ;
char * V_47 = F_22 () ;
char * V_24 = F_111 ( F_15 ( V_202 ) ) ;
int V_6 ;
V_6 = V_186 ( V_24 , V_47 , V_87 , NULL ) ;
if ( V_6 == 0 )
goto V_211;
if ( F_23 ( V_48 ) ||
F_81 ( V_202 , V_48 ) )
V_6 = 0 ;
V_211:
F_16 ( & V_41 , V_42 , V_43 ) ;
F_17 ( & V_41 , V_202 ) ;
F_82 ( V_24 , V_47 , V_87 , V_6 , & V_41 ) ;
return V_6 ;
}
static void F_112 ( struct V_37 * V_202 , struct V_2 * V_2 )
{
struct V_13 * V_15 = V_2 -> V_79 ;
V_15 -> V_17 = F_14 ( F_15 ( V_202 ) ) ;
}
static int F_113 ( struct V_151 * V_157 , int V_212 , T_1 V_213 )
{
char * V_113 = F_22 () ;
struct V_148 * V_149 ;
V_149 = F_2 ( sizeof( struct V_148 ) , V_213 ) ;
if ( V_149 == NULL )
return - V_35 ;
V_149 -> V_160 = V_113 ;
V_149 -> V_162 = V_113 ;
V_149 -> V_214 = NULL ;
V_157 -> V_158 = V_149 ;
return 0 ;
}
static void F_114 ( struct V_151 * V_157 )
{
F_4 ( V_157 -> V_158 ) ;
}
static char * F_115 ( struct V_215 * V_216 )
{
struct V_217 * V_218 ;
struct V_219 * V_220 = & V_216 -> V_221 ;
if ( V_220 -> V_222 == 0 )
return NULL ;
F_10 (snp, &smk_netlbladdr_list, list)
if ( ( & V_218 -> V_223 . V_221 ) -> V_222 ==
( V_220 -> V_222 & ( & V_218 -> V_224 ) -> V_222 ) ) {
if ( V_218 -> V_225 == V_226 )
return NULL ;
return V_218 -> V_225 ;
}
return NULL ;
}
static int F_116 ( struct V_151 * V_157 , int V_227 )
{
struct V_110 * V_111 ;
struct V_148 * V_149 = V_157 -> V_158 ;
int V_6 = 0 ;
F_117 () ;
F_118 ( V_157 ) ;
if ( V_149 -> V_162 == V_228 ||
V_227 == V_229 )
F_119 ( V_157 ) ;
else {
V_111 = F_46 ( V_149 -> V_162 ) ;
V_6 = F_120 ( V_157 , V_157 -> V_230 , & V_111 -> V_231 ) ;
}
F_121 ( V_157 ) ;
F_122 () ;
return V_6 ;
}
static int F_123 ( struct V_151 * V_157 , struct V_215 * V_232 )
{
int V_6 ;
int V_233 ;
char * V_234 ;
struct V_148 * V_149 = V_157 -> V_158 ;
struct V_40 V_41 ;
F_47 () ;
V_234 = F_115 ( V_232 ) ;
if ( V_234 != NULL ) {
#ifdef F_124
struct V_235 V_236 ;
F_125 ( & V_41 , V_42 , V_237 , & V_236 ) ;
V_41 . V_238 . V_239 . V_236 -> V_212 = V_232 -> V_240 ;
V_41 . V_238 . V_239 . V_236 -> V_241 = V_232 -> V_242 ;
V_41 . V_238 . V_239 . V_236 -> V_243 . V_244 = V_232 -> V_221 . V_222 ;
#endif
V_233 = V_229 ;
V_6 = V_186 ( V_149 -> V_162 , V_234 , V_87 , & V_41 ) ;
} else {
V_233 = V_245 ;
V_6 = 0 ;
}
F_49 () ;
if ( V_6 != 0 )
return V_6 ;
return F_116 ( V_157 , V_233 ) ;
}
static int F_126 ( struct V_2 * V_2 , const char * V_1 ,
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
V_78 -> V_18 |= V_246 ;
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
if ( V_151 -> V_157 -> V_230 != V_247 ) {
V_6 = F_116 ( V_151 -> V_157 , V_245 ) ;
if ( V_6 != 0 )
F_127 ( V_248
L_2 ,
V_42 , - V_6 ) ;
}
} else
return - V_156 ;
return 0 ;
}
static int F_128 ( struct V_150 * V_151 , int V_212 ,
int type , int V_249 , int V_250 )
{
if ( V_212 != V_251 || V_151 -> V_157 == NULL )
return 0 ;
return F_116 ( V_151 -> V_157 , V_245 ) ;
}
static int F_129 ( struct V_150 * V_151 , struct V_252 * V_232 ,
int V_253 )
{
if ( V_151 -> V_157 == NULL || V_151 -> V_157 -> V_230 != V_251 )
return 0 ;
if ( V_253 < sizeof( struct V_215 ) )
return - V_140 ;
return F_123 ( V_151 -> V_157 , (struct V_215 * ) V_232 ) ;
}
static int F_130 ( int V_72 )
{
int V_115 = 0 ;
if ( V_72 & V_254 )
V_115 |= V_83 ;
if ( V_72 & V_255 )
V_115 |= V_87 ;
if ( V_72 & V_256 )
V_115 |= V_126 ;
return V_115 ;
}
static int F_131 ( struct V_257 * V_258 )
{
V_258 -> V_97 = F_22 () ;
return 0 ;
}
static void F_132 ( struct V_257 * V_258 )
{
V_258 -> V_97 = NULL ;
}
static char * F_133 ( struct V_259 * V_260 )
{
return ( char * ) V_260 -> V_261 . V_97 ;
}
static int F_134 ( struct V_259 * V_260 )
{
struct V_262 * V_15 = & V_260 -> V_261 ;
V_15 -> V_97 = F_22 () ;
return 0 ;
}
static void F_135 ( struct V_259 * V_260 )
{
struct V_262 * V_15 = & V_260 -> V_261 ;
V_15 -> V_97 = NULL ;
}
static int F_136 ( struct V_259 * V_260 , int V_203 )
{
char * V_149 = F_133 ( V_260 ) ;
struct V_40 V_41 ;
#ifdef F_124
F_16 ( & V_41 , V_42 , V_263 ) ;
V_41 . V_238 . V_239 . V_264 = V_260 -> V_261 . V_265 ;
#endif
return F_18 ( V_149 , V_203 , & V_41 ) ;
}
static int F_137 ( struct V_259 * V_260 , int V_266 )
{
int V_115 ;
V_115 = F_130 ( V_266 ) ;
return F_136 ( V_260 , V_115 ) ;
}
static int F_138 ( struct V_259 * V_260 , int V_166 )
{
int V_115 ;
switch ( V_166 ) {
case V_267 :
case V_268 :
V_115 = V_83 ;
break;
case V_269 :
case V_270 :
case V_271 :
case V_272 :
V_115 = V_44 ;
break;
case V_273 :
case V_274 :
return 0 ;
default:
return - V_140 ;
}
return F_136 ( V_260 , V_115 ) ;
}
static int F_139 ( struct V_259 * V_260 , char T_5 * V_275 ,
int V_266 )
{
int V_115 ;
V_115 = F_130 ( V_266 ) ;
return F_136 ( V_260 , V_115 ) ;
}
static char * F_140 ( struct V_276 * V_277 )
{
return ( char * ) V_277 -> V_278 . V_97 ;
}
static int F_141 ( struct V_276 * V_277 )
{
struct V_262 * V_15 = & V_277 -> V_278 ;
V_15 -> V_97 = F_22 () ;
return 0 ;
}
static void F_142 ( struct V_276 * V_277 )
{
struct V_262 * V_15 = & V_277 -> V_278 ;
V_15 -> V_97 = NULL ;
}
static int F_143 ( struct V_276 * V_277 , int V_203 )
{
char * V_149 = F_140 ( V_277 ) ;
struct V_40 V_41 ;
#ifdef F_124
F_16 ( & V_41 , V_42 , V_263 ) ;
V_41 . V_238 . V_239 . V_264 = V_277 -> V_278 . V_265 ;
#endif
return F_18 ( V_149 , V_203 , & V_41 ) ;
}
static int F_144 ( struct V_276 * V_277 , int V_279 )
{
int V_115 ;
V_115 = F_130 ( V_279 ) ;
return F_143 ( V_277 , V_115 ) ;
}
static int F_145 ( struct V_276 * V_277 , int V_166 )
{
int V_115 ;
switch ( V_166 ) {
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
case V_267 :
case V_285 :
V_115 = V_83 ;
break;
case V_286 :
case V_287 :
case V_272 :
case V_269 :
V_115 = V_44 ;
break;
case V_273 :
case V_288 :
return 0 ;
default:
return - V_140 ;
}
return F_143 ( V_277 , V_115 ) ;
}
static int F_146 ( struct V_276 * V_277 , struct V_289 * V_290 ,
unsigned V_291 , int V_292 )
{
return F_143 ( V_277 , V_44 ) ;
}
static int F_147 ( struct V_293 * V_294 )
{
struct V_262 * V_295 = & V_294 -> V_296 ;
V_295 -> V_97 = F_22 () ;
return 0 ;
}
static void F_148 ( struct V_293 * V_294 )
{
struct V_262 * V_295 = & V_294 -> V_296 ;
V_295 -> V_97 = NULL ;
}
static char * F_149 ( struct V_293 * V_294 )
{
return ( char * ) V_294 -> V_296 . V_97 ;
}
static int F_150 ( struct V_293 * V_294 , int V_203 )
{
char * V_297 = F_149 ( V_294 ) ;
struct V_40 V_41 ;
#ifdef F_124
F_16 ( & V_41 , V_42 , V_263 ) ;
V_41 . V_238 . V_239 . V_264 = V_294 -> V_296 . V_265 ;
#endif
return F_18 ( V_297 , V_203 , & V_41 ) ;
}
static int F_151 ( struct V_293 * V_294 , int V_298 )
{
int V_115 ;
V_115 = F_130 ( V_298 ) ;
return F_150 ( V_294 , V_115 ) ;
}
static int F_152 ( struct V_293 * V_294 , int V_166 )
{
int V_115 ;
switch ( V_166 ) {
case V_267 :
case V_299 :
V_115 = V_83 ;
break;
case V_269 :
case V_272 :
V_115 = V_44 ;
break;
case V_273 :
case V_300 :
return 0 ;
default:
return - V_140 ;
}
return F_150 ( V_294 , V_115 ) ;
}
static int F_153 ( struct V_293 * V_294 , struct V_257 * V_258 ,
int V_298 )
{
int V_115 ;
V_115 = F_130 ( V_298 ) ;
return F_150 ( V_294 , V_115 ) ;
}
static int F_154 ( struct V_293 * V_294 , struct V_257 * V_258 ,
struct V_37 * V_301 , long type , int V_39 )
{
return F_150 ( V_294 , V_44 ) ;
}
static int F_155 ( struct V_262 * V_302 , short V_303 )
{
char * V_15 = V_302 -> V_97 ;
int V_115 = F_130 ( V_303 ) ;
struct V_40 V_41 ;
#ifdef F_124
F_16 ( & V_41 , V_42 , V_263 ) ;
V_41 . V_238 . V_239 . V_264 = V_302 -> V_265 ;
#endif
return F_18 ( V_15 , V_115 , & V_41 ) ;
}
static void F_156 ( struct V_262 * V_302 , T_3 * V_164 )
{
char * V_14 = V_302 -> V_97 ;
* V_164 = F_69 ( V_14 ) ;
}
static void F_157 ( struct V_4 * V_304 , struct V_2 * V_2 )
{
struct V_52 * V_80 ;
struct V_54 * V_55 ;
struct V_13 * V_15 ;
char * V_113 = F_22 () ;
char * V_305 ;
char * V_306 ;
char V_307 [ V_142 ] ;
int V_308 = 0 ;
int V_6 ;
struct V_4 * V_5 ;
if ( V_2 == NULL )
return;
V_15 = V_2 -> V_79 ;
F_158 ( & V_15 -> V_19 ) ;
if ( V_15 -> V_18 & V_246 )
goto V_309;
V_80 = V_2 -> V_153 ;
V_55 = V_80 -> V_62 ;
V_306 = V_55 -> V_57 ;
if ( V_304 -> V_310 == V_304 ) {
V_15 -> V_17 = V_55 -> V_56 ;
V_15 -> V_18 |= V_246 ;
goto V_309;
}
switch ( V_80 -> V_154 ) {
case V_311 :
V_306 = V_312 . V_50 ;
break;
case V_313 :
V_306 = V_312 . V_50 ;
break;
case V_314 :
V_306 = V_113 ;
break;
case V_155 :
V_306 = V_312 . V_50 ;
break;
case V_315 :
break;
case V_316 :
V_306 = V_312 . V_50 ;
default:
if ( F_159 ( V_2 -> V_317 ) ) {
V_306 = V_312 . V_50 ;
break;
}
if ( V_2 -> V_9 -> V_10 == NULL )
break;
V_5 = F_160 ( V_304 ) ;
V_305 = F_1 ( V_134 , V_2 , V_5 ) ;
if ( V_305 != NULL )
V_306 = V_305 ;
if ( F_161 ( V_2 -> V_317 ) ) {
if ( V_15 -> V_18 & V_118 ) {
V_15 -> V_18 &= ~ V_118 ;
V_6 = V_2 -> V_9 -> V_318 ( V_5 ,
V_141 ,
V_143 , V_142 ,
0 ) ;
} else {
V_6 = V_2 -> V_9 -> V_10 ( V_5 ,
V_141 , V_307 ,
V_142 ) ;
if ( V_6 >= 0 && strncmp ( V_307 , V_143 ,
V_142 ) != 0 )
V_6 = - V_140 ;
}
if ( V_6 >= 0 )
V_308 = V_146 ;
}
V_15 -> V_25 = F_1 ( V_137 , V_2 , V_5 ) ;
V_15 -> V_145 = F_1 ( V_138 , V_2 , V_5 ) ;
F_162 ( V_5 ) ;
break;
}
if ( V_306 == NULL )
V_15 -> V_17 = V_113 ;
else
V_15 -> V_17 = V_306 ;
V_15 -> V_18 |= ( V_246 | V_308 ) ;
V_309:
F_163 ( & V_15 -> V_19 ) ;
return;
}
static int F_164 ( struct V_37 * V_202 , char * V_1 , char * * V_108 )
{
char * V_65 ;
int V_319 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_140 ;
V_65 = F_45 ( F_14 ( F_15 ( V_202 ) ) , V_12 ) ;
if ( V_65 == NULL )
return - V_35 ;
V_319 = strlen ( V_65 ) ;
* V_108 = V_65 ;
return V_319 ;
}
static int F_165 ( struct V_37 * V_202 , char * V_1 ,
void * V_108 , T_2 V_133 )
{
int V_6 ;
struct V_20 * V_24 ;
struct V_20 * V_320 ;
struct V_96 * V_198 ;
char * V_321 ;
if ( V_202 != V_103 )
return - V_100 ;
if ( ! F_23 ( V_139 ) )
return - V_100 ;
if ( V_108 == NULL || V_133 == 0 || V_133 >= V_11 )
return - V_140 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_140 ;
V_321 = F_3 ( V_108 , V_133 ) ;
if ( V_321 == NULL )
return - V_140 ;
if ( V_321 == V_322 . V_50 )
return - V_100 ;
V_320 = V_202 -> V_96 -> V_97 ;
V_198 = F_166 () ;
if ( V_198 == NULL )
return - V_35 ;
V_24 = F_7 ( V_321 , V_320 -> V_26 , V_12 ) ;
if ( V_24 == NULL ) {
F_4 ( V_198 ) ;
return - V_35 ;
}
V_6 = F_9 ( & V_24 -> V_27 , & V_320 -> V_27 , V_12 ) ;
if ( V_6 != 0 )
return V_6 ;
V_198 -> V_97 = V_24 ;
F_167 ( V_198 ) ;
return V_133 ;
}
static int F_168 ( struct V_151 * V_151 ,
struct V_151 * V_323 , struct V_151 * V_324 )
{
struct V_148 * V_149 = V_151 -> V_158 ;
struct V_148 * V_325 = V_323 -> V_158 ;
struct V_148 * V_78 = V_324 -> V_158 ;
struct V_40 V_41 ;
int V_6 = 0 ;
#ifdef F_124
struct V_235 V_236 ;
F_125 ( & V_41 , V_42 , V_237 , & V_236 ) ;
F_169 ( & V_41 , V_323 ) ;
#endif
if ( ! F_23 ( V_48 ) )
V_6 = V_186 ( V_149 -> V_162 , V_325 -> V_160 , V_87 , & V_41 ) ;
if ( V_6 == 0 ) {
V_78 -> V_214 = V_149 -> V_162 ;
V_149 -> V_214 = V_325 -> V_162 ;
}
return V_6 ;
}
static int F_170 ( struct V_150 * V_151 , struct V_150 * V_323 )
{
struct V_148 * V_149 = V_151 -> V_157 -> V_158 ;
struct V_148 * V_325 = V_323 -> V_157 -> V_158 ;
struct V_40 V_41 ;
int V_6 = 0 ;
#ifdef F_124
struct V_235 V_236 ;
F_125 ( & V_41 , V_42 , V_237 , & V_236 ) ;
F_169 ( & V_41 , V_323 -> V_157 ) ;
#endif
if ( ! F_23 ( V_48 ) )
V_6 = V_186 ( V_149 -> V_162 , V_325 -> V_160 , V_87 , & V_41 ) ;
return V_6 ;
}
static int F_171 ( struct V_150 * V_151 , struct V_326 * V_258 ,
int V_133 )
{
struct V_215 * V_216 = (struct V_215 * ) V_258 -> V_327 ;
if ( V_216 == NULL || V_216 -> V_240 != V_328 )
return 0 ;
return F_123 ( V_151 -> V_157 , V_216 ) ;
}
static char * F_172 ( struct V_329 * V_232 ,
struct V_148 * V_149 )
{
struct V_110 * V_330 ;
char * V_47 ;
int V_331 = 0 ;
if ( ( V_232 -> V_72 & V_332 ) != 0 ) {
F_47 () ;
F_173 (kp, &smack_known_list, list) {
if ( V_232 -> V_333 . V_334 . V_335 != V_330 -> V_231 . V_333 . V_334 . V_335 )
continue;
if ( memcmp ( V_232 -> V_333 . V_334 . V_336 ,
V_330 -> V_231 . V_333 . V_334 . V_336 ,
V_337 ) != 0 )
continue;
V_331 = 1 ;
break;
}
F_49 () ;
if ( V_331 )
return V_330 -> V_50 ;
if ( V_149 != NULL && V_149 -> V_160 == V_312 . V_50 )
return V_322 . V_50 ;
return V_312 . V_50 ;
}
if ( ( V_232 -> V_72 & V_338 ) != 0 ) {
V_47 = F_93 ( V_232 -> V_333 . V_164 ) ;
F_174 ( V_47 == NULL ) ;
return V_47 ;
}
return V_228 ;
}
static int F_175 ( struct V_151 * V_157 , struct V_339 * V_340 )
{
struct V_329 V_341 ;
struct V_148 * V_149 = V_157 -> V_158 ;
char * V_113 ;
int V_6 ;
struct V_40 V_41 ;
#ifdef F_124
struct V_235 V_236 ;
#endif
if ( V_157 -> V_230 != V_251 && V_157 -> V_230 != V_342 )
return 0 ;
F_176 ( & V_341 ) ;
V_6 = F_177 ( V_340 , V_157 -> V_230 , & V_341 ) ;
if ( V_6 == 0 )
V_113 = F_172 ( & V_341 , V_149 ) ;
else
V_113 = V_228 ;
F_178 ( & V_341 ) ;
#ifdef F_124
F_125 ( & V_41 , V_42 , V_237 , & V_236 ) ;
V_41 . V_238 . V_239 . V_236 -> V_212 = V_157 -> V_230 ;
V_41 . V_238 . V_239 . V_236 -> V_343 = V_340 -> V_344 ;
F_179 ( V_340 , & V_41 . V_238 , NULL ) ;
#endif
V_6 = V_186 ( V_113 , V_149 -> V_160 , V_87 , & V_41 ) ;
if ( V_6 != 0 )
F_180 ( V_340 , V_6 , 0 ) ;
return V_6 ;
}
static int F_181 ( struct V_150 * V_151 ,
char T_5 * V_345 ,
int T_5 * V_346 , unsigned V_109 )
{
struct V_148 * V_149 ;
char * V_347 = L_4 ;
int V_319 = 1 ;
int V_6 = 0 ;
V_149 = V_151 -> V_157 -> V_158 ;
if ( V_149 -> V_214 != NULL ) {
V_347 = V_149 -> V_214 ;
V_319 = strlen ( V_347 ) + 1 ;
}
if ( V_319 > V_109 )
V_6 = - V_348 ;
else if ( F_182 ( V_345 , V_347 , V_319 ) != 0 )
V_6 = - V_349 ;
if ( F_183 ( V_319 , V_346 ) != 0 )
V_6 = - V_349 ;
return V_6 ;
}
static int F_184 ( struct V_150 * V_151 ,
struct V_339 * V_340 , T_3 * V_164 )
{
struct V_329 V_341 ;
struct V_148 * V_149 = NULL ;
char * V_47 ;
int V_212 = V_350 ;
T_3 V_351 = 0 ;
int V_6 ;
if ( V_340 != NULL ) {
if ( V_340 -> V_249 == F_185 ( V_352 ) )
V_212 = V_251 ;
else if ( V_340 -> V_249 == F_185 ( V_353 ) )
V_212 = V_342 ;
}
if ( V_212 == V_350 && V_151 != NULL )
V_212 = V_151 -> V_157 -> V_230 ;
if ( V_212 == V_247 ) {
V_149 = V_151 -> V_157 -> V_158 ;
V_351 = F_69 ( V_149 -> V_162 ) ;
} else if ( V_212 == V_251 || V_212 == V_342 ) {
if ( V_151 != NULL && V_151 -> V_157 != NULL )
V_149 = V_151 -> V_157 -> V_158 ;
F_176 ( & V_341 ) ;
V_6 = F_177 ( V_340 , V_212 , & V_341 ) ;
if ( V_6 == 0 ) {
V_47 = F_172 ( & V_341 , V_149 ) ;
V_351 = F_69 ( V_47 ) ;
}
F_178 ( & V_341 ) ;
}
* V_164 = V_351 ;
if ( V_351 == 0 )
return - V_140 ;
return 0 ;
}
static void F_186 ( struct V_151 * V_157 , struct V_150 * V_354 )
{
struct V_148 * V_149 ;
if ( V_157 == NULL ||
( V_157 -> V_230 != V_251 && V_157 -> V_230 != V_342 ) )
return;
V_149 = V_157 -> V_158 ;
V_149 -> V_160 = V_149 -> V_162 = F_22 () ;
}
static int F_187 ( struct V_151 * V_157 , struct V_339 * V_340 ,
struct V_355 * V_356 )
{
T_6 V_212 = V_157 -> V_230 ;
struct V_110 * V_111 ;
struct V_148 * V_149 = V_157 -> V_158 ;
struct V_329 V_341 ;
struct V_215 V_357 ;
struct V_358 * V_359 ;
char * V_47 ;
char * V_360 ;
int V_6 ;
struct V_40 V_41 ;
#ifdef F_124
struct V_235 V_236 ;
#endif
if ( V_212 == V_342 && V_340 -> V_249 == F_185 ( V_352 ) )
V_212 = V_251 ;
F_176 ( & V_341 ) ;
V_6 = F_177 ( V_340 , V_212 , & V_341 ) ;
if ( V_6 == 0 )
V_47 = F_172 ( & V_341 , V_149 ) ;
else
V_47 = V_361 . V_50 ;
F_178 ( & V_341 ) ;
#ifdef F_124
F_125 ( & V_41 , V_42 , V_237 , & V_236 ) ;
V_41 . V_238 . V_239 . V_236 -> V_212 = V_212 ;
V_41 . V_238 . V_239 . V_236 -> V_343 = V_340 -> V_344 ;
F_179 ( V_340 , & V_41 . V_238 , NULL ) ;
#endif
V_6 = V_186 ( V_47 , V_149 -> V_160 , V_87 , & V_41 ) ;
if ( V_6 != 0 )
return V_6 ;
V_356 -> V_362 = F_69 ( V_47 ) ;
V_359 = F_188 ( V_340 ) ;
V_357 . V_221 . V_222 = V_359 -> V_363 ;
F_47 () ;
V_360 = F_115 ( & V_357 ) ;
F_49 () ;
if ( V_360 == NULL ) {
V_111 = F_46 ( V_47 ) ;
V_6 = F_189 ( V_356 , & V_111 -> V_231 ) ;
} else
F_190 ( V_356 ) ;
return V_6 ;
}
static void F_191 ( struct V_151 * V_157 ,
const struct V_355 * V_356 )
{
struct V_148 * V_149 = V_157 -> V_158 ;
if ( V_356 -> V_362 != 0 )
V_149 -> V_214 = F_93 ( V_356 -> V_362 ) ;
else
V_149 -> V_214 = NULL ;
}
static int F_192 ( struct V_364 * V_364 , const struct V_96 * V_96 ,
unsigned long V_72 )
{
V_364 -> V_97 = F_14 ( V_96 -> V_97 ) ;
return 0 ;
}
static void F_193 ( struct V_364 * V_364 )
{
V_364 -> V_97 = NULL ;
}
static int F_194 ( T_7 V_365 ,
const struct V_96 * V_96 , T_8 V_366 )
{
struct V_364 * V_367 ;
struct V_40 V_41 ;
char * V_24 = F_14 ( V_96 -> V_97 ) ;
V_367 = F_195 ( V_365 ) ;
if ( V_367 == NULL )
return - V_140 ;
if ( V_367 -> V_97 == NULL )
return 0 ;
if ( V_24 == NULL )
return - V_51 ;
#ifdef F_124
F_16 ( & V_41 , V_42 , V_368 ) ;
V_41 . V_238 . V_239 . V_369 . V_364 = V_367 -> V_370 ;
V_41 . V_238 . V_239 . V_369 . V_371 = V_367 -> V_372 ;
#endif
return V_186 ( V_24 , V_367 -> V_97 ,
V_44 , & V_41 ) ;
}
static int F_196 ( T_3 V_373 , T_3 V_77 , char * V_374 , void * * V_375 )
{
char * * V_376 = ( char * * ) V_375 ;
* V_376 = NULL ;
if ( V_373 != V_377 && V_373 != V_378 )
return - V_140 ;
if ( V_77 != V_379 && V_77 != V_380 )
return - V_140 ;
* V_376 = F_3 ( V_374 , 0 ) ;
return 0 ;
}
static int F_197 ( struct V_381 * V_382 )
{
struct V_383 * V_384 ;
int V_385 ;
for ( V_385 = 0 ; V_385 < V_382 -> V_386 ; V_385 ++ ) {
V_384 = & V_382 -> V_387 [ V_385 ] ;
if ( V_384 -> type == V_377 || V_384 -> type == V_378 )
return 1 ;
}
return 0 ;
}
static int F_198 ( T_3 V_164 , T_3 V_373 , T_3 V_77 , void * V_375 ,
struct V_388 * V_389 )
{
char * V_14 ;
char * V_376 = V_375 ;
if ( ! V_376 ) {
F_199 ( V_389 , V_390 , V_391 ,
L_5 ) ;
return - V_185 ;
}
if ( V_373 != V_377 && V_373 != V_378 )
return 0 ;
V_14 = F_93 ( V_164 ) ;
if ( V_77 == V_379 )
return ( V_376 == V_14 ) ;
if ( V_77 == V_380 )
return ( V_376 != V_14 ) ;
return 0 ;
}
static void F_200 ( void * V_375 )
{
}
static int F_201 ( T_3 V_164 , char * * V_392 , T_3 * V_393 )
{
char * V_47 = F_93 ( V_164 ) ;
if ( V_392 )
* V_392 = V_47 ;
* V_393 = strlen ( V_47 ) ;
return 0 ;
}
static int F_202 ( const char * V_392 , T_3 V_393 , T_3 * V_164 )
{
* V_164 = F_69 ( V_392 ) ;
return 0 ;
}
static void F_203 ( char * V_392 , T_3 V_393 )
{
}
static int F_204 ( struct V_2 * V_2 , void * V_394 , T_3 V_395 )
{
return F_126 ( V_2 , V_116 , V_394 , V_395 , 0 ) ;
}
static int F_205 ( struct V_4 * V_4 , void * V_394 , T_3 V_395 )
{
return F_206 ( V_4 , V_134 , V_394 , V_395 , 0 ) ;
}
static int F_207 ( struct V_2 * V_2 , void * * V_394 , T_3 * V_395 )
{
int V_109 = 0 ;
V_109 = F_65 ( V_2 , V_116 , V_394 , true ) ;
if ( V_109 < 0 )
return V_109 ;
* V_395 = V_109 ;
return 0 ;
}
static T_9 void F_208 ( void )
{
F_6 ( & V_361 . V_28 ) ;
F_6 ( & V_60 . V_28 ) ;
F_6 ( & V_49 . V_28 ) ;
F_6 ( & V_312 . V_28 ) ;
F_6 ( & V_144 . V_28 ) ;
F_6 ( & V_322 . V_28 ) ;
F_8 ( & V_361 . V_27 ) ;
F_8 ( & V_60 . V_27 ) ;
F_8 ( & V_312 . V_27 ) ;
F_8 ( & V_49 . V_27 ) ;
F_8 ( & V_144 . V_27 ) ;
F_8 ( & V_322 . V_27 ) ;
F_209 ( & V_361 . V_36 , & V_396 ) ;
F_209 ( & V_60 . V_36 , & V_396 ) ;
F_209 ( & V_312 . V_36 , & V_396 ) ;
F_209 ( & V_49 . V_36 , & V_396 ) ;
F_209 ( & V_144 . V_36 , & V_396 ) ;
F_209 ( & V_322 . V_36 , & V_396 ) ;
}
static T_9 int F_210 ( void )
{
struct V_96 * V_96 ;
struct V_20 * V_24 ;
if ( ! F_211 ( & V_397 ) )
return 0 ;
V_24 = F_7 ( V_49 . V_50 ,
V_49 . V_50 , V_12 ) ;
if ( V_24 == NULL )
return - V_35 ;
F_127 ( V_398 L_6 ) ;
V_96 = (struct V_96 * ) V_103 -> V_96 ;
V_96 -> V_97 = V_24 ;
F_208 () ;
if ( F_212 ( & V_397 ) )
F_213 ( L_7 ) ;
return 0 ;
}

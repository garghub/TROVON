static struct V_1 * F_1 ( const char * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
char * V_8 ;
struct V_1 * V_9 = NULL ;
if ( V_4 -> V_10 -> V_11 == NULL )
return NULL ;
V_8 = F_2 ( V_12 , V_13 ) ;
if ( V_8 == NULL )
return NULL ;
V_7 = V_4 -> V_10 -> V_11 ( V_6 , V_2 , V_8 , V_12 ) ;
if ( V_7 > 0 )
V_9 = F_3 ( V_8 , V_7 ) ;
F_4 ( V_8 ) ;
return V_9 ;
}
struct V_14 * F_5 ( char * V_15 )
{
struct V_14 * V_16 ;
V_16 = F_2 ( sizeof( struct V_14 ) , V_17 ) ;
if ( V_16 == NULL )
return NULL ;
V_16 -> V_18 = V_15 ;
V_16 -> V_19 = 0 ;
F_6 ( & V_16 -> V_20 ) ;
return V_16 ;
}
static struct V_21 * F_7 ( struct V_1 * V_22 ,
struct V_1 * V_23 , T_1 V_24 )
{
struct V_21 * V_25 ;
V_25 = F_2 ( sizeof( struct V_21 ) , V_24 ) ;
if ( V_25 == NULL )
return NULL ;
V_25 -> V_26 = V_22 ;
V_25 -> V_27 = V_23 ;
F_8 ( & V_25 -> V_28 ) ;
F_6 ( & V_25 -> V_29 ) ;
return V_25 ;
}
static int F_9 ( struct V_30 * V_31 , struct V_30 * V_32 ,
T_1 V_24 )
{
struct V_33 * V_34 ;
struct V_33 * V_35 ;
int V_7 = 0 ;
F_8 ( V_31 ) ;
F_10 (orp, ohead, list) {
V_34 = F_2 ( sizeof( struct V_33 ) , V_24 ) ;
if ( V_34 == NULL ) {
V_7 = - V_36 ;
break;
}
* V_34 = * V_35 ;
F_11 ( & V_34 -> V_37 , V_31 ) ;
}
return V_7 ;
}
static int F_12 ( struct V_38 * V_39 , unsigned int V_40 )
{
int V_7 ;
struct V_41 V_42 ;
struct V_1 * V_9 ;
V_7 = F_13 ( V_39 , V_40 ) ;
if ( V_7 != 0 )
return V_7 ;
V_9 = F_14 ( F_15 ( V_39 ) ) ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_17 ( & V_42 , V_39 ) ;
V_7 = F_18 ( V_9 -> V_45 , V_40 , & V_42 ) ;
return V_7 ;
}
static int F_19 ( struct V_38 * V_46 )
{
int V_7 ;
struct V_41 V_42 ;
struct V_1 * V_9 ;
V_7 = F_20 ( V_46 ) ;
if ( V_7 != 0 )
return V_7 ;
V_9 = F_14 ( F_15 ( V_46 ) ) ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_17 ( & V_42 , V_46 ) ;
V_7 = F_18 ( V_9 -> V_45 , V_47 , & V_42 ) ;
return V_7 ;
}
static int F_21 ( int V_48 )
{
int V_7 = 0 ;
struct V_1 * V_9 = F_22 () ;
if ( F_23 ( V_49 ) )
return 0 ;
if ( V_50 != NULL && V_50 != V_9 )
V_7 = - V_51 ;
return V_7 ;
}
static int F_24 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
V_55 = F_2 ( sizeof( struct V_54 ) , V_13 ) ;
if ( V_55 == NULL )
return - V_36 ;
V_55 -> V_56 = V_57 . V_45 ;
V_55 -> V_58 = V_57 . V_45 ;
V_55 -> V_59 = V_57 . V_45 ;
V_55 -> V_60 = V_61 . V_45 ;
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
char * V_65 , * V_66 , * V_67 , * V_6 ;
V_67 = ( char * ) F_27 ( V_13 ) ;
if ( V_67 == NULL )
return - V_36 ;
for ( V_65 = V_63 , V_66 = V_63 ; V_66 != NULL ; V_65 = V_66 + 1 ) {
if ( strstr ( V_65 , V_68 ) == V_65 )
V_6 = V_64 ;
else if ( strstr ( V_65 , V_69 ) == V_65 )
V_6 = V_64 ;
else if ( strstr ( V_65 , V_70 ) == V_65 )
V_6 = V_64 ;
else if ( strstr ( V_65 , V_71 ) == V_65 )
V_6 = V_64 ;
else if ( strstr ( V_65 , V_72 ) == V_65 )
V_6 = V_64 ;
else
V_6 = V_67 ;
V_66 = strchr ( V_65 , ',' ) ;
if ( V_66 != NULL )
* V_66 = '\0' ;
if ( * V_6 != '\0' )
strcat ( V_6 , L_1 ) ;
strcat ( V_6 , V_65 ) ;
}
strcpy ( V_63 , V_67 ) ;
F_28 ( ( unsigned long ) V_67 ) ;
return 0 ;
}
static int F_29 ( struct V_52 * V_53 , int V_73 , void * V_74 )
{
struct V_5 * V_75 = V_53 -> V_76 ;
struct V_3 * V_3 = V_75 -> V_77 ;
struct V_54 * V_78 = V_53 -> V_62 ;
struct V_14 * V_16 ;
struct V_1 * V_9 ;
char * V_79 ;
char * V_66 ;
char * V_80 ;
int V_81 = 0 ;
int V_82 = 0 ;
if ( V_78 -> V_83 )
return 0 ;
V_78 -> V_83 = 1 ;
for ( V_79 = V_74 ; V_79 != NULL ; V_79 = V_66 ) {
V_66 = strchr ( V_79 , ',' ) ;
if ( V_66 != NULL )
* V_66 ++ = '\0' ;
if ( strncmp ( V_79 , V_70 , strlen ( V_70 ) ) == 0 ) {
V_79 += strlen ( V_70 ) ;
V_80 = F_30 ( V_79 , 0 ) ;
if ( V_80 != NULL ) {
V_78 -> V_60 = V_80 ;
V_82 = 1 ;
}
} else if ( strncmp ( V_79 , V_69 , strlen ( V_69 ) ) == 0 ) {
V_79 += strlen ( V_69 ) ;
V_80 = F_30 ( V_79 , 0 ) ;
if ( V_80 != NULL ) {
V_78 -> V_59 = V_80 ;
V_82 = 1 ;
}
} else if ( strncmp ( V_79 , V_68 ,
strlen ( V_68 ) ) == 0 ) {
V_79 += strlen ( V_68 ) ;
V_80 = F_30 ( V_79 , 0 ) ;
if ( V_80 != NULL ) {
V_78 -> V_58 = V_80 ;
V_82 = 1 ;
}
} else if ( strncmp ( V_79 , V_71 , strlen ( V_71 ) ) == 0 ) {
V_79 += strlen ( V_71 ) ;
V_80 = F_30 ( V_79 , 0 ) ;
if ( V_80 != NULL ) {
V_78 -> V_56 = V_80 ;
V_82 = 1 ;
}
} else if ( strncmp ( V_79 , V_72 , strlen ( V_72 ) ) == 0 ) {
V_79 += strlen ( V_72 ) ;
V_80 = F_30 ( V_79 , 0 ) ;
if ( V_80 != NULL ) {
V_78 -> V_56 = V_80 ;
V_81 = 1 ;
V_82 = 1 ;
}
}
}
if ( ! F_23 ( V_84 ) ) {
if ( V_82 )
return - V_85 ;
V_9 = F_22 () ;
V_78 -> V_56 = V_9 -> V_45 ;
V_78 -> V_58 = V_9 -> V_45 ;
}
V_16 = V_3 -> V_86 ;
if ( V_3 -> V_86 == NULL ) {
V_3 -> V_86 = F_5 ( V_78 -> V_56 ) ;
V_16 = V_3 -> V_86 ;
} else
V_16 -> V_18 = V_78 -> V_56 ;
if ( V_81 )
V_16 -> V_19 |= V_87 ;
return 0 ;
}
static int F_31 ( struct V_5 * V_5 )
{
struct V_54 * V_88 = V_5 -> V_89 -> V_62 ;
int V_7 ;
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_32 ( & V_42 , V_5 ) ;
V_7 = F_18 ( V_88 -> V_59 , V_91 , & V_42 ) ;
return V_7 ;
}
static int F_33 ( struct V_92 * V_93 )
{
struct V_3 * V_3 = F_34 ( V_93 -> V_94 ) ;
struct V_21 * V_95 = V_93 -> V_96 -> V_97 ;
struct V_14 * V_16 ;
int V_7 ;
V_7 = F_35 ( V_93 ) ;
if ( V_7 != 0 )
return V_7 ;
if ( V_93 -> V_98 )
return 0 ;
V_16 = V_3 -> V_86 ;
if ( V_16 -> V_26 == NULL || V_16 -> V_26 == V_95 -> V_26 )
return 0 ;
if ( V_93 -> V_99 )
return - V_85 ;
V_95 -> V_26 = V_16 -> V_26 ;
V_93 -> V_100 |= V_101 ;
return 0 ;
}
static void F_36 ( struct V_92 * V_93 )
{
struct V_21 * V_95 = V_93 -> V_96 -> V_97 ;
if ( V_95 -> V_26 != V_95 -> V_27 )
V_102 -> V_103 = 0 ;
}
static int F_37 ( struct V_92 * V_93 )
{
struct V_21 * V_25 = F_38 () ;
int V_104 = F_39 ( V_93 ) ;
if ( ! V_104 && ( V_25 -> V_26 != V_25 -> V_27 ) )
V_104 = 1 ;
return V_104 ;
}
static int F_40 ( struct V_3 * V_3 )
{
struct V_1 * V_9 = F_22 () ;
V_3 -> V_86 = F_5 ( V_9 -> V_45 ) ;
if ( V_3 -> V_86 == NULL )
return - V_36 ;
return 0 ;
}
static void F_41 ( struct V_3 * V_3 )
{
F_4 ( V_3 -> V_86 ) ;
V_3 -> V_86 = NULL ;
}
static int F_42 ( struct V_3 * V_3 , struct V_3 * V_105 ,
const struct V_106 * V_106 , const char * * V_2 ,
void * * V_107 , T_2 * V_108 )
{
struct V_14 * V_109 = V_3 -> V_86 ;
struct V_1 * V_9 = F_22 () ;
char * V_16 = F_43 ( V_3 ) ;
char * V_110 = F_43 ( V_105 ) ;
int V_111 ;
if ( V_2 )
* V_2 = V_112 ;
if ( V_107 ) {
F_44 () ;
V_111 = F_45 ( V_9 -> V_45 , V_110 , & V_9 -> V_28 ) ;
F_46 () ;
if ( V_111 > 0 && ( ( V_111 & V_113 ) != 0 ) &&
F_47 ( V_105 ) ) {
V_16 = V_110 ;
V_109 -> V_19 |= V_114 ;
}
* V_107 = F_48 ( V_16 , V_17 ) ;
if ( * V_107 == NULL )
return - V_36 ;
}
if ( V_108 )
* V_108 = strlen ( V_16 ) + 1 ;
return 0 ;
}
static int F_49 ( struct V_5 * V_115 , struct V_3 * V_105 ,
struct V_5 * V_116 )
{
char * V_16 ;
struct V_41 V_42 ;
int V_7 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_32 ( & V_42 , V_115 ) ;
V_16 = F_43 ( V_115 -> V_77 ) ;
V_7 = F_18 ( V_16 , V_117 , & V_42 ) ;
if ( V_7 == 0 && V_116 -> V_77 != NULL ) {
V_16 = F_43 ( V_116 -> V_77 ) ;
F_32 ( & V_42 , V_116 ) ;
V_7 = F_18 ( V_16 , V_117 , & V_42 ) ;
}
return V_7 ;
}
static int F_50 ( struct V_3 * V_105 , struct V_5 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_77 ;
struct V_41 V_42 ;
int V_7 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_32 ( & V_42 , V_5 ) ;
V_7 = F_18 ( F_43 ( V_4 ) , V_117 , & V_42 ) ;
if ( V_7 == 0 ) {
F_16 ( & V_42 , V_43 , V_118 ) ;
F_51 ( & V_42 , V_105 ) ;
V_7 = F_18 ( F_43 ( V_105 ) , V_117 , & V_42 ) ;
}
return V_7 ;
}
static int F_52 ( struct V_3 * V_105 , struct V_5 * V_5 )
{
struct V_41 V_42 ;
int V_7 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_32 ( & V_42 , V_5 ) ;
V_7 = F_18 ( F_43 ( V_5 -> V_77 ) , V_117 , & V_42 ) ;
if ( V_7 == 0 ) {
F_16 ( & V_42 , V_43 , V_118 ) ;
F_51 ( & V_42 , V_105 ) ;
V_7 = F_18 ( F_43 ( V_105 ) , V_117 , & V_42 ) ;
}
return V_7 ;
}
static int F_53 ( struct V_3 * V_119 ,
struct V_5 * V_115 ,
struct V_3 * V_120 ,
struct V_5 * V_116 )
{
int V_7 ;
char * V_16 ;
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_32 ( & V_42 , V_115 ) ;
V_16 = F_43 ( V_115 -> V_77 ) ;
V_7 = F_18 ( V_16 , V_47 , & V_42 ) ;
if ( V_7 == 0 && V_116 -> V_77 != NULL ) {
V_16 = F_43 ( V_116 -> V_77 ) ;
F_32 ( & V_42 , V_116 ) ;
V_7 = F_18 ( V_16 , V_47 , & V_42 ) ;
}
return V_7 ;
}
static int F_54 ( struct V_3 * V_3 , int V_121 )
{
struct V_41 V_42 ;
int V_122 = V_121 & V_123 ;
V_121 &= ( V_91 | V_117 | V_124 | V_125 ) ;
if ( V_121 == 0 )
return 0 ;
if ( V_122 )
return - V_126 ;
F_16 ( & V_42 , V_43 , V_118 ) ;
F_51 ( & V_42 , V_3 ) ;
return F_18 ( F_43 ( V_3 ) , V_121 , & V_42 ) ;
}
static int F_55 ( struct V_5 * V_5 , struct V_127 * V_127 )
{
struct V_41 V_42 ;
if ( V_127 -> V_128 & V_129 )
return 0 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_32 ( & V_42 , V_5 ) ;
return F_18 ( F_43 ( V_5 -> V_77 ) , V_117 , & V_42 ) ;
}
static int F_56 ( struct V_130 * V_131 , struct V_5 * V_5 )
{
struct V_41 V_42 ;
struct V_132 V_132 ;
V_132 . V_5 = V_5 ;
V_132 . V_131 = V_131 ;
F_16 ( & V_42 , V_43 , V_133 ) ;
F_57 ( & V_42 , V_132 ) ;
return F_18 ( F_43 ( V_5 -> V_77 ) , V_91 , & V_42 ) ;
}
static int F_58 ( struct V_5 * V_5 , const char * V_2 ,
const void * V_107 , T_2 V_134 , int V_73 )
{
struct V_41 V_42 ;
struct V_1 * V_9 ;
int V_135 = 0 ;
int V_136 = 0 ;
int V_137 = 0 ;
int V_7 = 0 ;
if ( strcmp ( V_2 , V_138 ) == 0 ||
strcmp ( V_2 , V_139 ) == 0 ||
strcmp ( V_2 , V_140 ) == 0 ) {
V_135 = 1 ;
V_136 = 1 ;
} else if ( strcmp ( V_2 , V_141 ) == 0 ||
strcmp ( V_2 , V_142 ) == 0 ) {
V_135 = 1 ;
V_136 = 1 ;
V_137 = 1 ;
} else if ( strcmp ( V_2 , V_143 ) == 0 ) {
V_135 = 1 ;
if ( V_134 != V_144 ||
strncmp ( V_107 , V_145 , V_144 ) != 0 )
V_7 = - V_146 ;
} else
V_7 = F_59 ( V_5 , V_2 , V_107 , V_134 , V_73 ) ;
if ( V_135 && ! F_23 ( V_84 ) )
V_7 = - V_85 ;
if ( V_7 == 0 && V_136 ) {
V_9 = F_3 ( V_107 , V_134 ) ;
if ( V_9 == NULL || ( V_137 &&
( V_9 == & V_147 || V_9 == & V_148 ) ) )
V_7 = - V_146 ;
}
F_16 ( & V_42 , V_43 , V_90 ) ;
F_32 ( & V_42 , V_5 ) ;
if ( V_7 == 0 )
V_7 = F_18 ( F_43 ( V_5 -> V_77 ) , V_117 , & V_42 ) ;
return V_7 ;
}
static void F_60 ( struct V_5 * V_5 , const char * V_2 ,
const void * V_107 , T_2 V_134 , int V_73 )
{
struct V_1 * V_9 ;
struct V_14 * V_16 = V_5 -> V_77 -> V_86 ;
if ( strcmp ( V_2 , V_143 ) == 0 ) {
V_16 -> V_19 |= V_87 ;
return;
}
V_9 = F_3 ( V_107 , V_134 ) ;
if ( strcmp ( V_2 , V_138 ) == 0 ) {
if ( V_9 != NULL )
V_16 -> V_18 = V_9 -> V_45 ;
else
V_16 -> V_18 = V_149 . V_45 ;
} else if ( strcmp ( V_2 , V_141 ) == 0 ) {
if ( V_9 != NULL )
V_16 -> V_26 = V_9 ;
else
V_16 -> V_26 = & V_149 ;
} else if ( strcmp ( V_2 , V_142 ) == 0 ) {
if ( V_9 != NULL )
V_16 -> V_150 = V_9 ;
else
V_16 -> V_150 = & V_149 ;
}
return;
}
static int F_61 ( struct V_5 * V_5 , const char * V_2 )
{
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_32 ( & V_42 , V_5 ) ;
return F_18 ( F_43 ( V_5 -> V_77 ) , V_91 , & V_42 ) ;
}
static int F_62 ( struct V_5 * V_5 , const char * V_2 )
{
struct V_14 * V_16 ;
struct V_41 V_42 ;
int V_7 = 0 ;
if ( strcmp ( V_2 , V_138 ) == 0 ||
strcmp ( V_2 , V_139 ) == 0 ||
strcmp ( V_2 , V_140 ) == 0 ||
strcmp ( V_2 , V_141 ) == 0 ||
strcmp ( V_2 , V_143 ) == 0 ||
strcmp ( V_2 , V_142 ) ) {
if ( ! F_23 ( V_84 ) )
V_7 = - V_85 ;
} else
V_7 = F_63 ( V_5 , V_2 ) ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_32 ( & V_42 , V_5 ) ;
if ( V_7 == 0 )
V_7 = F_18 ( F_43 ( V_5 -> V_77 ) , V_117 , & V_42 ) ;
if ( V_7 == 0 ) {
V_16 = V_5 -> V_77 -> V_86 ;
V_16 -> V_26 = NULL ;
V_16 -> V_150 = NULL ;
}
return V_7 ;
}
static int F_64 ( const struct V_3 * V_3 ,
const char * V_2 , void * * V_8 ,
bool V_151 )
{
struct V_152 * V_153 ;
struct V_154 * V_155 ;
struct V_52 * V_88 ;
struct V_3 * V_4 = (struct V_3 * ) V_3 ;
char * V_16 ;
int V_156 ;
int V_7 = 0 ;
if ( strcmp ( V_2 , V_112 ) == 0 ) {
V_16 = F_43 ( V_3 ) ;
V_156 = strlen ( V_16 ) + 1 ;
* V_8 = V_16 ;
return V_156 ;
}
V_88 = V_4 -> V_157 ;
if ( V_88 -> V_158 != V_159 )
return - V_160 ;
V_155 = F_65 ( V_4 ) ;
if ( V_155 == NULL || V_155 -> V_161 == NULL )
return - V_160 ;
V_153 = V_155 -> V_161 -> V_162 ;
if ( strcmp ( V_2 , V_163 ) == 0 )
V_16 = V_153 -> V_164 ;
else if ( strcmp ( V_2 , V_165 ) == 0 )
V_16 = V_153 -> V_166 -> V_45 ;
else
return - V_160 ;
V_156 = strlen ( V_16 ) + 1 ;
if ( V_7 == 0 ) {
* V_8 = V_16 ;
V_7 = V_156 ;
}
return V_7 ;
}
static int F_66 ( struct V_3 * V_3 , char * V_8 ,
T_2 V_167 )
{
int V_108 = strlen ( V_138 ) ;
if ( V_8 != NULL && V_108 <= V_167 ) {
memcpy ( V_8 , V_138 , V_108 ) ;
return V_108 ;
}
return - V_146 ;
}
static void F_67 ( const struct V_3 * V_3 , T_3 * V_168 )
{
struct V_14 * V_16 = V_3 -> V_86 ;
* V_168 = F_68 ( V_16 -> V_18 ) ;
}
static int F_69 ( struct V_94 * V_94 , int V_121 )
{
return 0 ;
}
static int F_70 ( struct V_94 * V_94 )
{
struct V_1 * V_9 = F_22 () ;
V_94 -> V_169 = V_9 -> V_45 ;
return 0 ;
}
static void F_71 ( struct V_94 * V_94 )
{
V_94 -> V_169 = NULL ;
}
static int F_72 ( struct V_94 * V_94 , unsigned int V_170 ,
unsigned long V_171 )
{
int V_7 = 0 ;
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_133 ) ;
F_57 ( & V_42 , V_94 -> V_172 ) ;
if ( F_73 ( V_170 ) & V_173 )
V_7 = F_18 ( V_94 -> V_169 , V_117 , & V_42 ) ;
if ( V_7 == 0 && ( F_73 ( V_170 ) & V_174 ) )
V_7 = F_18 ( V_94 -> V_169 , V_91 , & V_42 ) ;
return V_7 ;
}
static int F_74 ( struct V_94 * V_94 , unsigned int V_170 )
{
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_133 ) ;
F_57 ( & V_42 , V_94 -> V_172 ) ;
return F_18 ( V_94 -> V_169 , V_175 , & V_42 ) ;
}
static int F_75 ( struct V_94 * V_94 , unsigned int V_170 ,
unsigned long V_171 )
{
struct V_41 V_42 ;
int V_7 = 0 ;
switch ( V_170 ) {
case V_176 :
break;
case V_177 :
case V_178 :
F_16 ( & V_42 , V_43 , V_133 ) ;
F_57 ( & V_42 , V_94 -> V_172 ) ;
V_7 = F_18 ( V_94 -> V_169 , V_175 , & V_42 ) ;
break;
case V_179 :
case V_180 :
F_16 ( & V_42 , V_43 , V_133 ) ;
F_57 ( & V_42 , V_94 -> V_172 ) ;
V_7 = F_18 ( V_94 -> V_169 , V_117 , & V_42 ) ;
break;
default:
break;
}
return V_7 ;
}
static int F_76 ( struct V_94 * V_94 ,
unsigned long V_181 , unsigned long V_182 ,
unsigned long V_73 )
{
struct V_1 * V_9 ;
struct V_1 * V_183 ;
struct V_33 * V_184 ;
struct V_21 * V_25 ;
char * V_185 ;
struct V_14 * V_16 ;
int V_111 ;
int V_186 ;
int V_187 ;
int V_7 ;
if ( V_94 == NULL )
return 0 ;
V_16 = F_34 ( V_94 ) -> V_86 ;
if ( V_16 -> V_150 == NULL )
return 0 ;
V_183 = V_16 -> V_150 ;
V_25 = F_38 () ;
V_9 = F_22 () ;
V_7 = 0 ;
F_44 () ;
F_10 (srp, &skp->smk_rules, list) {
V_185 = V_184 -> V_188 ;
if ( V_183 -> V_45 == V_185 )
continue;
V_111 = F_45 ( V_184 -> V_189 -> V_45 , V_185 ,
& V_25 -> V_28 ) ;
if ( V_111 == - V_190 )
V_111 = V_184 -> V_191 ;
else
V_111 &= V_184 -> V_191 ;
if ( V_111 == 0 )
continue;
V_186 = F_45 ( V_183 -> V_45 , V_185 ,
& V_183 -> V_28 ) ;
if ( V_186 == - V_190 ) {
V_7 = - V_51 ;
break;
}
V_187 = F_45 ( V_183 -> V_45 , V_185 ,
& V_25 -> V_28 ) ;
if ( V_187 != - V_190 )
V_186 &= V_187 ;
if ( ( V_111 | V_186 ) != V_186 ) {
V_7 = - V_51 ;
break;
}
}
F_46 () ;
return V_7 ;
}
static int F_77 ( struct V_94 * V_94 )
{
struct V_1 * V_9 = F_22 () ;
V_94 -> V_169 = V_9 -> V_45 ;
return 0 ;
}
static int F_78 ( struct V_38 * V_192 ,
struct V_193 * V_194 , int V_195 )
{
struct V_1 * V_9 ;
struct V_1 * V_196 = F_14 ( V_192 -> V_96 -> V_97 ) ;
struct V_94 * V_94 ;
int V_7 ;
struct V_41 V_42 ;
V_94 = F_79 ( V_194 , struct V_94 , V_197 ) ;
V_9 = F_80 ( V_94 -> V_169 ) ;
V_7 = V_191 ( V_9 , V_196 -> V_45 , V_117 , NULL ) ;
if ( V_7 != 0 && F_81 ( V_192 , V_49 ) )
V_7 = 0 ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_17 ( & V_42 , V_192 ) ;
F_82 ( V_94 -> V_169 , V_196 -> V_45 , V_117 , V_7 , & V_42 ) ;
return V_7 ;
}
static int F_83 ( struct V_94 * V_94 )
{
int V_111 = 0 ;
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_133 ) ;
F_57 ( & V_42 , V_94 -> V_172 ) ;
if ( V_94 -> V_198 & V_199 )
V_111 = V_91 ;
if ( V_94 -> V_198 & V_200 )
V_111 |= V_117 ;
return F_18 ( V_94 -> V_169 , V_111 , & V_42 ) ;
}
static int F_84 ( struct V_94 * V_94 , const struct V_96 * V_96 )
{
struct V_14 * V_16 = F_34 ( V_94 ) -> V_86 ;
V_94 -> V_169 = V_16 -> V_18 ;
return 0 ;
}
static int F_85 ( struct V_96 * V_96 , T_1 V_24 )
{
struct V_21 * V_25 ;
V_25 = F_7 ( NULL , NULL , V_24 ) ;
if ( V_25 == NULL )
return - V_36 ;
V_96 -> V_97 = V_25 ;
return 0 ;
}
static void F_86 ( struct V_96 * V_96 )
{
struct V_21 * V_25 = V_96 -> V_97 ;
struct V_33 * V_201 ;
struct V_30 * V_202 ;
struct V_30 * V_203 ;
if ( V_25 == NULL )
return;
V_96 -> V_97 = NULL ;
F_87 (l, n, &tsp->smk_rules) {
V_201 = F_88 ( V_202 , struct V_33 , V_37 ) ;
F_89 ( & V_201 -> V_37 ) ;
F_4 ( V_201 ) ;
}
F_4 ( V_25 ) ;
}
static int F_90 ( struct V_96 * V_204 , const struct V_96 * V_205 ,
T_1 V_24 )
{
struct V_21 * V_206 = V_205 -> V_97 ;
struct V_21 * V_207 ;
int V_7 ;
V_207 = F_7 ( V_206 -> V_26 , V_206 -> V_26 , V_24 ) ;
if ( V_207 == NULL )
return - V_36 ;
V_7 = F_9 ( & V_207 -> V_28 , & V_206 -> V_28 , V_24 ) ;
if ( V_7 != 0 )
return V_7 ;
V_204 -> V_97 = V_207 ;
return 0 ;
}
static void F_91 ( struct V_96 * V_204 , const struct V_96 * V_205 )
{
struct V_21 * V_206 = V_205 -> V_97 ;
struct V_21 * V_207 = V_204 -> V_97 ;
V_207 -> V_26 = V_206 -> V_26 ;
V_207 -> V_27 = V_206 -> V_26 ;
F_6 ( & V_207 -> V_29 ) ;
F_8 ( & V_207 -> V_28 ) ;
}
static int F_92 ( struct V_96 * V_204 , T_3 V_168 )
{
struct V_21 * V_207 = V_204 -> V_97 ;
struct V_1 * V_9 = F_93 ( V_168 ) ;
if ( V_9 == NULL )
return - V_146 ;
V_207 -> V_26 = V_9 ;
return 0 ;
}
static int F_94 ( struct V_96 * V_204 ,
struct V_3 * V_3 )
{
struct V_14 * V_16 = V_3 -> V_86 ;
struct V_21 * V_25 = V_204 -> V_97 ;
V_25 -> V_27 = F_80 ( V_16 -> V_18 ) ;
V_25 -> V_26 = V_25 -> V_27 ;
return 0 ;
}
static int F_95 ( struct V_38 * V_208 , int V_209 ,
const char * V_210 )
{
struct V_41 V_42 ;
struct V_1 * V_9 = F_14 ( F_15 ( V_208 ) ) ;
F_16 ( & V_42 , V_210 , V_44 ) ;
F_17 ( & V_42 , V_208 ) ;
return F_18 ( V_9 -> V_45 , V_209 , & V_42 ) ;
}
static int F_96 ( struct V_38 * V_208 , T_4 V_211 )
{
return F_95 ( V_208 , V_117 , V_43 ) ;
}
static int F_97 ( struct V_38 * V_208 )
{
return F_95 ( V_208 , V_91 , V_43 ) ;
}
static int F_98 ( struct V_38 * V_208 )
{
return F_95 ( V_208 , V_91 , V_43 ) ;
}
static void F_99 ( struct V_38 * V_208 , T_3 * V_168 )
{
struct V_1 * V_9 = F_14 ( F_15 ( V_208 ) ) ;
* V_168 = V_9 -> V_212 ;
}
static int F_100 ( struct V_38 * V_208 , int V_213 )
{
int V_7 ;
V_7 = F_101 ( V_208 , V_213 ) ;
if ( V_7 == 0 )
V_7 = F_95 ( V_208 , V_117 , V_43 ) ;
return V_7 ;
}
static int F_102 ( struct V_38 * V_208 , int V_214 )
{
int V_7 ;
V_7 = F_103 ( V_208 , V_214 ) ;
if ( V_7 == 0 )
V_7 = F_95 ( V_208 , V_117 , V_43 ) ;
return V_7 ;
}
static int F_104 ( struct V_38 * V_208 )
{
return F_95 ( V_208 , V_91 , V_43 ) ;
}
static int F_105 ( struct V_38 * V_208 )
{
int V_7 ;
V_7 = F_106 ( V_208 ) ;
if ( V_7 == 0 )
V_7 = F_95 ( V_208 , V_117 , V_43 ) ;
return V_7 ;
}
static int F_107 ( struct V_38 * V_208 )
{
return F_95 ( V_208 , V_91 , V_43 ) ;
}
static int F_108 ( struct V_38 * V_208 )
{
return F_95 ( V_208 , V_117 , V_43 ) ;
}
static int F_109 ( struct V_38 * V_208 , struct V_215 * V_216 ,
int V_217 , T_3 V_168 )
{
struct V_41 V_42 ;
struct V_1 * V_9 ;
struct V_1 * V_196 = F_14 ( F_15 ( V_208 ) ) ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_17 ( & V_42 , V_208 ) ;
if ( V_168 == 0 )
return F_18 ( V_196 -> V_45 , V_117 , & V_42 ) ;
V_9 = F_93 ( V_168 ) ;
return V_191 ( V_9 , V_196 -> V_45 , V_117 , & V_42 ) ;
}
static int F_110 ( struct V_38 * V_208 )
{
return 0 ;
}
static void F_111 ( struct V_38 * V_208 , struct V_3 * V_3 )
{
struct V_14 * V_16 = V_3 -> V_86 ;
struct V_1 * V_9 = F_14 ( F_15 ( V_208 ) ) ;
V_16 -> V_18 = V_9 -> V_45 ;
}
static int F_112 ( struct V_155 * V_161 , int V_218 , T_1 V_219 )
{
struct V_1 * V_9 = F_22 () ;
struct V_152 * V_153 ;
V_153 = F_2 ( sizeof( struct V_152 ) , V_219 ) ;
if ( V_153 == NULL )
return - V_36 ;
V_153 -> V_164 = V_9 -> V_45 ;
V_153 -> V_166 = V_9 ;
V_153 -> V_220 = NULL ;
V_161 -> V_162 = V_153 ;
return 0 ;
}
static void F_113 ( struct V_155 * V_161 )
{
F_4 ( V_161 -> V_162 ) ;
}
static char * F_114 ( struct V_221 * V_222 )
{
struct V_223 * V_224 ;
struct V_225 * V_226 = & V_222 -> V_227 ;
if ( V_226 -> V_228 == 0 )
return NULL ;
F_10 (snp, &smk_netlbladdr_list, list)
if ( ( & V_224 -> V_229 . V_227 ) -> V_228 ==
( V_226 -> V_228 & ( & V_224 -> V_230 ) -> V_228 ) ) {
if ( V_224 -> V_231 == V_232 )
return NULL ;
return V_224 -> V_231 ;
}
return NULL ;
}
static int F_115 ( struct V_155 * V_161 , int V_233 )
{
struct V_1 * V_9 ;
struct V_152 * V_153 = V_161 -> V_162 ;
int V_7 = 0 ;
F_116 () ;
F_117 ( V_161 ) ;
if ( V_153 -> V_166 == V_234 ||
V_233 == V_235 )
F_118 ( V_161 ) ;
else {
V_9 = V_153 -> V_166 ;
V_7 = F_119 ( V_161 , V_161 -> V_236 , & V_9 -> V_237 ) ;
}
F_120 ( V_161 ) ;
F_121 () ;
return V_7 ;
}
static int F_122 ( struct V_155 * V_161 , struct V_221 * V_238 )
{
struct V_1 * V_9 ;
int V_7 ;
int V_239 ;
char * V_240 ;
struct V_152 * V_153 = V_161 -> V_162 ;
struct V_41 V_42 ;
F_44 () ;
V_240 = F_114 ( V_238 ) ;
if ( V_240 != NULL ) {
#ifdef F_123
struct V_241 V_242 ;
F_124 ( & V_42 , V_43 , V_243 , & V_242 ) ;
V_42 . V_244 . V_245 . V_242 -> V_218 = V_238 -> V_246 ;
V_42 . V_244 . V_245 . V_242 -> V_247 = V_238 -> V_248 ;
V_42 . V_244 . V_245 . V_242 -> V_249 . V_250 = V_238 -> V_227 . V_228 ;
#endif
V_239 = V_235 ;
V_9 = V_153 -> V_166 ;
V_7 = V_191 ( V_9 , V_240 , V_117 , & V_42 ) ;
} else {
V_239 = V_251 ;
V_7 = 0 ;
}
F_46 () ;
if ( V_7 != 0 )
return V_7 ;
return F_115 ( V_161 , V_239 ) ;
}
static void F_125 ( struct V_154 * V_155 , struct V_252 * V_253 )
{
struct V_155 * V_161 = V_155 -> V_161 ;
struct V_254 * V_255 ;
struct V_152 * V_153 = V_155 -> V_161 -> V_162 ;
struct V_256 * V_257 ;
unsigned short V_258 = 0 ;
if ( V_253 == NULL ) {
F_126 (spp, &smk_ipv6_port_list, list) {
if ( V_161 != V_257 -> V_259 )
continue;
V_257 -> V_164 = V_153 -> V_164 ;
V_257 -> V_166 = V_153 -> V_166 ;
return;
}
return;
}
V_255 = (struct V_254 * ) V_253 ;
V_258 = F_127 ( V_255 -> V_260 ) ;
if ( V_258 == 0 )
return;
F_126 (spp, &smk_ipv6_port_list, list) {
if ( V_257 -> V_261 != V_258 )
continue;
V_257 -> V_261 = V_258 ;
V_257 -> V_259 = V_161 ;
V_257 -> V_164 = V_153 -> V_164 ;
V_257 -> V_166 = V_153 -> V_166 ;
return;
}
V_257 = F_2 ( sizeof( * V_257 ) , V_13 ) ;
if ( V_257 == NULL )
return;
V_257 -> V_261 = V_258 ;
V_257 -> V_259 = V_161 ;
V_257 -> V_164 = V_153 -> V_164 ;
V_257 -> V_166 = V_153 -> V_166 ;
F_128 ( & V_257 -> V_37 , & V_262 ) ;
return;
}
static int F_129 ( struct V_155 * V_161 , struct V_254 * V_253 ,
int V_263 )
{
T_5 * V_264 ;
T_6 * V_265 ;
struct V_256 * V_257 ;
struct V_152 * V_153 = V_161 -> V_162 ;
struct V_1 * V_9 ;
unsigned short V_258 = 0 ;
char * V_266 ;
struct V_41 V_42 ;
#ifdef F_123
struct V_241 V_242 ;
#endif
if ( V_263 == V_267 ) {
V_9 = V_234 ;
V_266 = V_153 -> V_164 ;
} else {
V_9 = V_153 -> V_166 ;
V_266 = V_234 -> V_45 ;
}
V_258 = F_127 ( V_253 -> V_260 ) ;
V_264 = ( T_5 * ) ( & V_253 -> V_268 ) ;
V_265 = ( T_6 * ) ( & V_253 -> V_268 ) ;
if ( V_265 [ 0 ] || V_265 [ 1 ] || V_265 [ 2 ] || V_264 [ 6 ] || F_127 ( V_264 [ 7 ] ) != 1 )
goto V_269;
if ( V_263 == V_267 ) {
V_9 = & V_148 ;
goto V_269;
}
F_126 (spp, &smk_ipv6_port_list, list) {
if ( V_257 -> V_261 != V_258 )
continue;
V_266 = V_257 -> V_164 ;
if ( V_263 == V_270 )
V_153 -> V_220 = V_257 -> V_166 -> V_45 ;
break;
}
V_269:
#ifdef F_123
F_124 ( & V_42 , V_43 , V_243 , & V_242 ) ;
V_42 . V_244 . V_245 . V_242 -> V_218 = V_161 -> V_236 ;
V_42 . V_244 . V_245 . V_242 -> V_247 = V_258 ;
if ( V_263 == V_267 )
V_42 . V_244 . V_245 . V_242 -> V_271 . V_272 = V_253 -> V_268 ;
else
V_42 . V_244 . V_245 . V_242 -> V_271 . V_250 = V_253 -> V_268 ;
#endif
return V_191 ( V_9 , V_266 , V_117 , & V_42 ) ;
}
static int F_130 ( struct V_3 * V_3 , const char * V_2 ,
const void * V_107 , T_2 V_134 , int V_73 )
{
struct V_1 * V_9 ;
struct V_14 * V_80 = V_3 -> V_86 ;
struct V_152 * V_153 ;
struct V_154 * V_155 ;
int V_7 = 0 ;
if ( V_107 == NULL || V_134 > V_12 || V_134 == 0 )
return - V_51 ;
V_9 = F_3 ( V_107 , V_134 ) ;
if ( V_9 == NULL )
return - V_146 ;
if ( strcmp ( V_2 , V_112 ) == 0 ) {
V_80 -> V_18 = V_9 -> V_45 ;
V_80 -> V_19 |= V_273 ;
return 0 ;
}
if ( V_3 -> V_157 -> V_158 != V_159 )
return - V_160 ;
V_155 = F_65 ( V_3 ) ;
if ( V_155 == NULL || V_155 -> V_161 == NULL )
return - V_160 ;
V_153 = V_155 -> V_161 -> V_162 ;
if ( strcmp ( V_2 , V_163 ) == 0 )
V_153 -> V_164 = V_9 -> V_45 ;
else if ( strcmp ( V_2 , V_165 ) == 0 ) {
V_153 -> V_166 = V_9 ;
if ( V_155 -> V_161 -> V_236 == V_274 ) {
V_7 = F_115 ( V_155 -> V_161 , V_251 ) ;
if ( V_7 != 0 )
F_131 ( V_275
L_2 ,
V_43 , - V_7 ) ;
}
} else
return - V_160 ;
if ( V_155 -> V_161 -> V_236 == V_276 )
F_125 ( V_155 , NULL ) ;
return 0 ;
}
static int F_132 ( struct V_154 * V_155 , int V_218 ,
int type , int V_277 , int V_278 )
{
if ( V_218 != V_274 || V_155 -> V_161 == NULL )
return 0 ;
return F_115 ( V_155 -> V_161 , V_251 ) ;
}
static int F_133 ( struct V_154 * V_155 , struct V_252 * V_253 ,
int V_279 )
{
if ( V_155 -> V_161 != NULL && V_155 -> V_161 -> V_236 == V_276 )
F_125 ( V_155 , V_253 ) ;
return 0 ;
}
static int F_134 ( struct V_154 * V_155 , struct V_252 * V_238 ,
int V_279 )
{
int V_7 = 0 ;
if ( V_155 -> V_161 == NULL )
return 0 ;
switch ( V_155 -> V_161 -> V_236 ) {
case V_274 :
if ( V_279 < sizeof( struct V_221 ) )
return - V_146 ;
V_7 = F_122 ( V_155 -> V_161 , (struct V_221 * ) V_238 ) ;
break;
case V_276 :
if ( V_279 < sizeof( struct V_254 ) )
return - V_146 ;
V_7 = F_129 ( V_155 -> V_161 , (struct V_254 * ) V_238 ,
V_270 ) ;
break;
}
return V_7 ;
}
static int F_135 ( int V_73 )
{
int V_111 = 0 ;
if ( V_73 & V_280 )
V_111 |= V_91 ;
if ( V_73 & V_281 )
V_111 |= V_117 ;
if ( V_73 & V_282 )
V_111 |= V_124 ;
return V_111 ;
}
static int F_136 ( struct V_283 * V_284 )
{
struct V_1 * V_9 = F_22 () ;
V_284 -> V_97 = V_9 -> V_45 ;
return 0 ;
}
static void F_137 ( struct V_283 * V_284 )
{
V_284 -> V_97 = NULL ;
}
static char * F_138 ( struct V_285 * V_286 )
{
return ( char * ) V_286 -> V_287 . V_97 ;
}
static int F_139 ( struct V_285 * V_286 )
{
struct V_288 * V_16 = & V_286 -> V_287 ;
struct V_1 * V_9 = F_22 () ;
V_16 -> V_97 = V_9 -> V_45 ;
return 0 ;
}
static void F_140 ( struct V_285 * V_286 )
{
struct V_288 * V_16 = & V_286 -> V_287 ;
V_16 -> V_97 = NULL ;
}
static int F_141 ( struct V_285 * V_286 , int V_209 )
{
char * V_153 = F_138 ( V_286 ) ;
struct V_41 V_42 ;
#ifdef F_123
F_16 ( & V_42 , V_43 , V_289 ) ;
V_42 . V_244 . V_245 . V_290 = V_286 -> V_287 . V_291 ;
#endif
return F_18 ( V_153 , V_209 , & V_42 ) ;
}
static int F_142 ( struct V_285 * V_286 , int V_292 )
{
int V_111 ;
V_111 = F_135 ( V_292 ) ;
return F_141 ( V_286 , V_111 ) ;
}
static int F_143 ( struct V_285 * V_286 , int V_170 )
{
int V_111 ;
switch ( V_170 ) {
case V_293 :
case V_294 :
V_111 = V_91 ;
break;
case V_295 :
case V_296 :
case V_297 :
case V_298 :
V_111 = V_47 ;
break;
case V_299 :
case V_300 :
return 0 ;
default:
return - V_146 ;
}
return F_141 ( V_286 , V_111 ) ;
}
static int F_144 ( struct V_285 * V_286 , char T_7 * V_301 ,
int V_292 )
{
int V_111 ;
V_111 = F_135 ( V_292 ) ;
return F_141 ( V_286 , V_111 ) ;
}
static char * F_145 ( struct V_302 * V_303 )
{
return ( char * ) V_303 -> V_304 . V_97 ;
}
static int F_146 ( struct V_302 * V_303 )
{
struct V_288 * V_16 = & V_303 -> V_304 ;
struct V_1 * V_9 = F_22 () ;
V_16 -> V_97 = V_9 -> V_45 ;
return 0 ;
}
static void F_147 ( struct V_302 * V_303 )
{
struct V_288 * V_16 = & V_303 -> V_304 ;
V_16 -> V_97 = NULL ;
}
static int F_148 ( struct V_302 * V_303 , int V_209 )
{
char * V_153 = F_145 ( V_303 ) ;
struct V_41 V_42 ;
#ifdef F_123
F_16 ( & V_42 , V_43 , V_289 ) ;
V_42 . V_244 . V_245 . V_290 = V_303 -> V_304 . V_291 ;
#endif
return F_18 ( V_153 , V_209 , & V_42 ) ;
}
static int F_149 ( struct V_302 * V_303 , int V_305 )
{
int V_111 ;
V_111 = F_135 ( V_305 ) ;
return F_148 ( V_303 , V_111 ) ;
}
static int F_150 ( struct V_302 * V_303 , int V_170 )
{
int V_111 ;
switch ( V_170 ) {
case V_306 :
case V_307 :
case V_308 :
case V_309 :
case V_310 :
case V_293 :
case V_311 :
V_111 = V_91 ;
break;
case V_312 :
case V_313 :
case V_298 :
case V_295 :
V_111 = V_47 ;
break;
case V_299 :
case V_314 :
return 0 ;
default:
return - V_146 ;
}
return F_148 ( V_303 , V_111 ) ;
}
static int F_151 ( struct V_302 * V_303 , struct V_315 * V_316 ,
unsigned V_317 , int V_318 )
{
return F_148 ( V_303 , V_47 ) ;
}
static int F_152 ( struct V_319 * V_320 )
{
struct V_288 * V_321 = & V_320 -> V_322 ;
struct V_1 * V_9 = F_22 () ;
V_321 -> V_97 = V_9 -> V_45 ;
return 0 ;
}
static void F_153 ( struct V_319 * V_320 )
{
struct V_288 * V_321 = & V_320 -> V_322 ;
V_321 -> V_97 = NULL ;
}
static char * F_154 ( struct V_319 * V_320 )
{
return ( char * ) V_320 -> V_322 . V_97 ;
}
static int F_155 ( struct V_319 * V_320 , int V_209 )
{
char * V_323 = F_154 ( V_320 ) ;
struct V_41 V_42 ;
#ifdef F_123
F_16 ( & V_42 , V_43 , V_289 ) ;
V_42 . V_244 . V_245 . V_290 = V_320 -> V_322 . V_291 ;
#endif
return F_18 ( V_323 , V_209 , & V_42 ) ;
}
static int F_156 ( struct V_319 * V_320 , int V_324 )
{
int V_111 ;
V_111 = F_135 ( V_324 ) ;
return F_155 ( V_320 , V_111 ) ;
}
static int F_157 ( struct V_319 * V_320 , int V_170 )
{
int V_111 ;
switch ( V_170 ) {
case V_293 :
case V_325 :
V_111 = V_91 ;
break;
case V_295 :
case V_298 :
V_111 = V_47 ;
break;
case V_299 :
case V_326 :
return 0 ;
default:
return - V_146 ;
}
return F_155 ( V_320 , V_111 ) ;
}
static int F_158 ( struct V_319 * V_320 , struct V_283 * V_284 ,
int V_324 )
{
int V_111 ;
V_111 = F_135 ( V_324 ) ;
return F_155 ( V_320 , V_111 ) ;
}
static int F_159 ( struct V_319 * V_320 , struct V_283 * V_284 ,
struct V_38 * V_327 , long type , int V_40 )
{
return F_155 ( V_320 , V_47 ) ;
}
static int F_160 ( struct V_288 * V_328 , short V_329 )
{
char * V_16 = V_328 -> V_97 ;
int V_111 = F_135 ( V_329 ) ;
struct V_41 V_42 ;
#ifdef F_123
F_16 ( & V_42 , V_43 , V_289 ) ;
V_42 . V_244 . V_245 . V_290 = V_328 -> V_291 ;
#endif
return F_18 ( V_16 , V_111 , & V_42 ) ;
}
static void F_161 ( struct V_288 * V_328 , T_3 * V_168 )
{
char * V_15 = V_328 -> V_97 ;
* V_168 = F_68 ( V_15 ) ;
}
static void F_162 ( struct V_5 * V_330 , struct V_3 * V_3 )
{
struct V_52 * V_88 ;
struct V_54 * V_55 ;
struct V_14 * V_16 ;
struct V_1 * V_9 ;
struct V_1 * V_331 = F_22 () ;
char * V_332 ;
char V_333 [ V_144 ] ;
int V_334 = 0 ;
int V_7 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return;
V_16 = V_3 -> V_86 ;
F_163 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_19 & V_273 )
goto V_335;
V_88 = V_3 -> V_157 ;
V_55 = V_88 -> V_62 ;
V_332 = V_55 -> V_58 ;
if ( V_330 -> V_336 == V_330 ) {
V_16 -> V_18 = V_55 -> V_56 ;
V_16 -> V_19 |= V_273 ;
goto V_335;
}
switch ( V_88 -> V_158 ) {
case V_337 :
V_332 = V_147 . V_45 ;
break;
case V_338 :
V_332 = V_147 . V_45 ;
break;
case V_339 :
V_332 = V_331 -> V_45 ;
break;
case V_159 :
V_332 = V_147 . V_45 ;
break;
case V_340 :
break;
case V_341 :
V_332 = V_147 . V_45 ;
default:
if ( F_164 ( V_3 -> V_342 ) ) {
V_332 = V_147 . V_45 ;
break;
}
if ( V_3 -> V_10 -> V_11 == NULL )
break;
V_6 = F_165 ( V_330 ) ;
V_9 = F_1 ( V_138 , V_3 , V_6 ) ;
if ( V_9 != NULL )
V_332 = V_9 -> V_45 ;
if ( F_166 ( V_3 -> V_342 ) ) {
if ( V_16 -> V_19 & V_114 ) {
V_16 -> V_19 &= ~ V_114 ;
V_7 = V_3 -> V_10 -> V_343 ( V_6 ,
V_143 ,
V_145 , V_144 ,
0 ) ;
} else {
V_7 = V_3 -> V_10 -> V_11 ( V_6 ,
V_143 , V_333 ,
V_144 ) ;
if ( V_7 >= 0 && strncmp ( V_333 , V_145 ,
V_144 ) != 0 )
V_7 = - V_146 ;
}
if ( V_7 >= 0 )
V_334 = V_87 ;
}
V_9 = F_1 ( V_141 , V_3 , V_6 ) ;
if ( V_9 == & V_147 || V_9 == & V_148 )
V_9 = NULL ;
V_16 -> V_26 = V_9 ;
V_9 = F_1 ( V_142 , V_3 , V_6 ) ;
if ( V_9 == & V_147 || V_9 == & V_148 )
V_9 = NULL ;
V_16 -> V_150 = V_9 ;
F_167 ( V_6 ) ;
break;
}
if ( V_332 == NULL )
V_16 -> V_18 = V_331 -> V_45 ;
else
V_16 -> V_18 = V_332 ;
V_16 -> V_19 |= ( V_273 | V_334 ) ;
V_335:
F_168 ( & V_16 -> V_20 ) ;
return;
}
static int F_169 ( struct V_38 * V_208 , char * V_2 , char * * V_107 )
{
struct V_1 * V_9 = F_14 ( F_15 ( V_208 ) ) ;
char * V_65 ;
int V_344 ;
if ( strcmp ( V_2 , L_3 ) != 0 )
return - V_146 ;
V_65 = F_48 ( V_9 -> V_45 , V_13 ) ;
if ( V_65 == NULL )
return - V_36 ;
V_344 = strlen ( V_65 ) ;
* V_107 = V_65 ;
return V_344 ;
}
static int F_170 ( struct V_38 * V_208 , char * V_2 ,
void * V_107 , T_2 V_134 )
{
struct V_21 * V_25 ;
struct V_96 * V_204 ;
struct V_1 * V_9 ;
if ( V_208 != V_102 )
return - V_85 ;
if ( ! F_23 ( V_84 ) )
return - V_85 ;
if ( V_107 == NULL || V_134 == 0 || V_134 >= V_12 )
return - V_146 ;
if ( strcmp ( V_2 , L_3 ) != 0 )
return - V_146 ;
V_9 = F_3 ( V_107 , V_134 ) ;
if ( V_9 == NULL )
return - V_146 ;
if ( V_9 == & V_148 )
return - V_85 ;
V_204 = F_171 () ;
if ( V_204 == NULL )
return - V_36 ;
V_25 = V_204 -> V_97 ;
V_25 -> V_26 = V_9 ;
F_172 ( V_204 ) ;
return V_134 ;
}
static int F_173 ( struct V_155 * V_155 ,
struct V_155 * V_345 , struct V_155 * V_346 )
{
struct V_1 * V_9 ;
struct V_152 * V_153 = V_155 -> V_162 ;
struct V_152 * V_347 = V_345 -> V_162 ;
struct V_152 * V_80 = V_346 -> V_162 ;
struct V_41 V_42 ;
int V_7 = 0 ;
#ifdef F_123
struct V_241 V_242 ;
F_124 ( & V_42 , V_43 , V_243 , & V_242 ) ;
F_174 ( & V_42 , V_345 ) ;
#endif
if ( ! F_23 ( V_49 ) ) {
V_9 = V_153 -> V_166 ;
V_7 = V_191 ( V_9 , V_347 -> V_164 , V_117 , & V_42 ) ;
}
if ( V_7 == 0 ) {
V_80 -> V_220 = V_153 -> V_166 -> V_45 ;
V_153 -> V_220 = V_347 -> V_166 -> V_45 ;
}
return V_7 ;
}
static int F_175 ( struct V_154 * V_155 , struct V_154 * V_345 )
{
struct V_152 * V_153 = V_155 -> V_161 -> V_162 ;
struct V_152 * V_347 = V_345 -> V_161 -> V_162 ;
struct V_1 * V_9 ;
struct V_41 V_42 ;
#ifdef F_123
struct V_241 V_242 ;
F_124 ( & V_42 , V_43 , V_243 , & V_242 ) ;
F_174 ( & V_42 , V_345 -> V_161 ) ;
#endif
if ( F_23 ( V_49 ) )
return 0 ;
V_9 = V_153 -> V_166 ;
return V_191 ( V_9 , V_347 -> V_164 , V_117 , & V_42 ) ;
}
static int F_176 ( struct V_154 * V_155 , struct V_348 * V_284 ,
int V_134 )
{
struct V_221 * V_222 = (struct V_221 * ) V_284 -> V_349 ;
struct V_254 * V_238 = (struct V_254 * ) V_284 -> V_349 ;
int V_7 = 0 ;
if ( V_222 == NULL )
return 0 ;
switch ( V_222 -> V_246 ) {
case V_350 :
V_7 = F_122 ( V_155 -> V_161 , V_222 ) ;
break;
case V_351 :
V_7 = F_129 ( V_155 -> V_161 , V_238 , V_352 ) ;
break;
}
return V_7 ;
}
static struct V_1 * F_177 ( struct V_353 * V_238 ,
struct V_152 * V_153 )
{
struct V_1 * V_9 ;
int V_354 = 0 ;
int V_355 ;
int V_356 ;
if ( ( V_238 -> V_73 & V_357 ) != 0 ) {
F_44 () ;
F_126 (skp, &smack_known_list, list) {
if ( V_238 -> V_358 . V_359 . V_360 != V_9 -> V_237 . V_358 . V_359 . V_360 )
continue;
if ( ( V_238 -> V_73 & V_361 ) == 0 ) {
if ( ( V_9 -> V_237 . V_73 &
V_361 ) == 0 )
V_354 = 1 ;
break;
}
for ( V_355 = - 1 , V_356 = - 1 ; V_355 == V_356 ; ) {
V_355 = F_178 (
V_238 -> V_358 . V_359 . V_362 , V_355 + 1 ) ;
V_356 = F_178 (
V_9 -> V_237 . V_358 . V_359 . V_362 ,
V_356 + 1 ) ;
if ( V_355 < 0 || V_356 < 0 )
break;
}
if ( V_355 == V_356 ) {
V_354 = 1 ;
break;
}
}
F_46 () ;
if ( V_354 )
return V_9 ;
if ( V_153 != NULL && V_153 -> V_164 == V_147 . V_45 )
return & V_148 ;
return & V_147 ;
}
if ( ( V_238 -> V_73 & V_363 ) != 0 ) {
V_9 = F_93 ( V_238 -> V_358 . V_168 ) ;
F_179 ( V_9 == NULL ) ;
return V_9 ;
}
return V_234 ;
}
static int F_180 ( struct V_364 * V_365 , struct V_254 * V_222 )
{
T_8 V_366 ;
int V_367 ;
int V_368 = - V_146 ;
struct V_369 V_370 ;
struct V_369 * V_371 ;
T_5 V_372 ;
struct V_373 V_374 , * V_375 ;
struct V_376 V_377 , * V_378 ;
struct V_379 V_380 , * V_381 ;
V_222 -> V_260 = 0 ;
V_367 = F_181 ( V_365 ) ;
V_371 = F_182 ( V_365 , V_367 , sizeof( V_370 ) , & V_370 ) ;
if ( V_371 == NULL )
return - V_146 ;
V_222 -> V_268 = V_371 -> V_272 ;
V_366 = V_371 -> V_366 ;
V_367 += sizeof( V_370 ) ;
V_367 = F_183 ( V_365 , V_367 , & V_366 , & V_372 ) ;
if ( V_367 < 0 )
return - V_146 ;
V_368 = V_366 ;
switch ( V_368 ) {
case V_382 :
V_375 = F_182 ( V_365 , V_367 , sizeof( V_374 ) , & V_374 ) ;
if ( V_375 != NULL )
V_222 -> V_260 = V_375 -> V_383 ;
break;
case V_384 :
V_378 = F_182 ( V_365 , V_367 , sizeof( V_377 ) , & V_377 ) ;
if ( V_378 != NULL )
V_222 -> V_260 = V_378 -> V_383 ;
break;
case V_385 :
V_381 = F_182 ( V_365 , V_367 , sizeof( V_380 ) , & V_380 ) ;
if ( V_381 != NULL )
V_222 -> V_260 = V_381 -> V_386 ;
break;
}
return V_368 ;
}
static int F_184 ( struct V_155 * V_161 , struct V_364 * V_365 )
{
struct V_353 V_387 ;
struct V_152 * V_153 = V_161 -> V_162 ;
struct V_1 * V_9 ;
struct V_254 V_388 ;
int V_7 = 0 ;
struct V_41 V_42 ;
#ifdef F_123
struct V_241 V_242 ;
#endif
switch ( V_161 -> V_236 ) {
case V_274 :
F_185 ( & V_387 ) ;
V_7 = F_186 ( V_365 , V_161 -> V_236 , & V_387 ) ;
if ( V_7 == 0 )
V_9 = F_177 ( & V_387 , V_153 ) ;
else
V_9 = V_234 ;
F_187 ( & V_387 ) ;
#ifdef F_123
F_124 ( & V_42 , V_43 , V_243 , & V_242 ) ;
V_42 . V_244 . V_245 . V_242 -> V_218 = V_161 -> V_236 ;
V_42 . V_244 . V_245 . V_242 -> V_389 = V_365 -> V_390 ;
F_188 ( V_365 , & V_42 . V_244 , NULL ) ;
#endif
V_7 = V_191 ( V_9 , V_153 -> V_164 , V_117 , & V_42 ) ;
if ( V_7 != 0 )
F_189 ( V_365 , V_7 , 0 ) ;
break;
case V_276 :
V_7 = F_180 ( V_365 , & V_388 ) ;
if ( V_7 == V_384 || V_7 == V_382 )
V_7 = F_129 ( V_161 , & V_388 , V_267 ) ;
else
V_7 = 0 ;
break;
}
return V_7 ;
}
static int F_190 ( struct V_154 * V_155 ,
char T_7 * V_391 ,
int T_7 * V_392 , unsigned V_108 )
{
struct V_152 * V_153 ;
char * V_393 = L_4 ;
int V_344 = 1 ;
int V_7 = 0 ;
V_153 = V_155 -> V_161 -> V_162 ;
if ( V_153 -> V_220 != NULL ) {
V_393 = V_153 -> V_220 ;
V_344 = strlen ( V_393 ) + 1 ;
}
if ( V_344 > V_108 )
V_7 = - V_394 ;
else if ( F_191 ( V_391 , V_393 , V_344 ) != 0 )
V_7 = - V_395 ;
if ( F_192 ( V_344 , V_392 ) != 0 )
V_7 = - V_395 ;
return V_7 ;
}
static int F_193 ( struct V_154 * V_155 ,
struct V_364 * V_365 , T_3 * V_168 )
{
struct V_353 V_387 ;
struct V_152 * V_153 = NULL ;
struct V_1 * V_9 ;
int V_218 = V_396 ;
T_3 V_397 = 0 ;
int V_7 ;
if ( V_365 != NULL ) {
if ( V_365 -> V_277 == F_194 ( V_398 ) )
V_218 = V_274 ;
else if ( V_365 -> V_277 == F_194 ( V_399 ) )
V_218 = V_276 ;
}
if ( V_218 == V_396 && V_155 != NULL )
V_218 = V_155 -> V_161 -> V_236 ;
if ( V_218 == V_400 ) {
V_153 = V_155 -> V_161 -> V_162 ;
V_397 = V_153 -> V_166 -> V_212 ;
} else if ( V_218 == V_274 || V_218 == V_276 ) {
if ( V_155 != NULL && V_155 -> V_161 != NULL )
V_153 = V_155 -> V_161 -> V_162 ;
F_185 ( & V_387 ) ;
V_7 = F_186 ( V_365 , V_218 , & V_387 ) ;
if ( V_7 == 0 ) {
V_9 = F_177 ( & V_387 , V_153 ) ;
V_397 = V_9 -> V_212 ;
}
F_187 ( & V_387 ) ;
}
* V_168 = V_397 ;
if ( V_397 == 0 )
return - V_146 ;
return 0 ;
}
static void F_195 ( struct V_155 * V_161 , struct V_154 * V_401 )
{
struct V_152 * V_153 ;
struct V_1 * V_9 = F_22 () ;
if ( V_161 == NULL ||
( V_161 -> V_236 != V_274 && V_161 -> V_236 != V_276 ) )
return;
V_153 = V_161 -> V_162 ;
V_153 -> V_164 = V_9 -> V_45 ;
V_153 -> V_166 = V_9 ;
}
static int F_196 ( struct V_155 * V_161 , struct V_364 * V_365 ,
struct V_402 * V_403 )
{
T_9 V_218 = V_161 -> V_236 ;
struct V_1 * V_9 ;
struct V_152 * V_153 = V_161 -> V_162 ;
struct V_353 V_387 ;
struct V_221 V_404 ;
struct V_405 * V_406 ;
char * V_407 ;
int V_7 ;
struct V_41 V_42 ;
#ifdef F_123
struct V_241 V_242 ;
#endif
if ( V_218 == V_276 ) {
if ( V_365 -> V_277 == F_194 ( V_398 ) )
V_218 = V_274 ;
else
return 0 ;
}
F_185 ( & V_387 ) ;
V_7 = F_186 ( V_365 , V_218 , & V_387 ) ;
if ( V_7 == 0 )
V_9 = F_177 ( & V_387 , V_153 ) ;
else
V_9 = & V_408 ;
F_187 ( & V_387 ) ;
#ifdef F_123
F_124 ( & V_42 , V_43 , V_243 , & V_242 ) ;
V_42 . V_244 . V_245 . V_242 -> V_218 = V_218 ;
V_42 . V_244 . V_245 . V_242 -> V_389 = V_365 -> V_390 ;
F_188 ( V_365 , & V_42 . V_244 , NULL ) ;
#endif
V_7 = V_191 ( V_9 , V_153 -> V_164 , V_117 , & V_42 ) ;
if ( V_7 != 0 )
return V_7 ;
V_403 -> V_409 = V_9 -> V_212 ;
V_406 = F_197 ( V_365 ) ;
V_404 . V_227 . V_228 = V_406 -> V_272 ;
F_44 () ;
V_407 = F_114 ( & V_404 ) ;
F_46 () ;
if ( V_407 == NULL )
V_7 = F_198 ( V_403 , & V_9 -> V_237 ) ;
else
F_199 ( V_403 ) ;
return V_7 ;
}
static void F_200 ( struct V_155 * V_161 ,
const struct V_402 * V_403 )
{
struct V_152 * V_153 = V_161 -> V_162 ;
struct V_1 * V_9 ;
if ( V_403 -> V_409 != 0 ) {
V_9 = F_93 ( V_403 -> V_409 ) ;
V_153 -> V_220 = V_9 -> V_45 ;
} else
V_153 -> V_220 = NULL ;
}
static int F_201 ( struct V_410 * V_410 , const struct V_96 * V_96 ,
unsigned long V_73 )
{
struct V_1 * V_9 = F_14 ( V_96 -> V_97 ) ;
V_410 -> V_97 = V_9 -> V_45 ;
return 0 ;
}
static void F_202 ( struct V_410 * V_410 )
{
V_410 -> V_97 = NULL ;
}
static int F_203 ( T_10 V_411 ,
const struct V_96 * V_96 , T_11 V_412 )
{
struct V_410 * V_413 ;
struct V_41 V_42 ;
struct V_1 * V_196 = F_14 ( V_96 -> V_97 ) ;
V_413 = F_204 ( V_411 ) ;
if ( V_413 == NULL )
return - V_146 ;
if ( V_413 -> V_97 == NULL )
return 0 ;
if ( V_196 == NULL )
return - V_51 ;
#ifdef F_123
F_16 ( & V_42 , V_43 , V_414 ) ;
V_42 . V_244 . V_245 . V_415 . V_410 = V_413 -> V_416 ;
V_42 . V_244 . V_245 . V_415 . V_417 = V_413 -> V_418 ;
#endif
return V_191 ( V_196 , V_413 -> V_97 , V_47 , & V_42 ) ;
}
static int F_205 ( T_3 V_419 , T_3 V_79 , char * V_420 , void * * V_421 )
{
char * * V_422 = ( char * * ) V_421 ;
* V_422 = NULL ;
if ( V_419 != V_423 && V_419 != V_424 )
return - V_146 ;
if ( V_79 != V_425 && V_79 != V_426 )
return - V_146 ;
* V_422 = F_30 ( V_420 , 0 ) ;
return 0 ;
}
static int F_206 ( struct V_427 * V_428 )
{
struct V_429 * V_430 ;
int V_431 ;
for ( V_431 = 0 ; V_431 < V_428 -> V_432 ; V_431 ++ ) {
V_430 = & V_428 -> V_433 [ V_431 ] ;
if ( V_430 -> type == V_423 || V_430 -> type == V_424 )
return 1 ;
}
return 0 ;
}
static int F_207 ( T_3 V_168 , T_3 V_419 , T_3 V_79 , void * V_421 ,
struct V_434 * V_435 )
{
struct V_1 * V_9 ;
char * V_422 = V_421 ;
if ( F_208 ( ! V_422 ) ) {
F_209 ( 1 , L_5 ) ;
return - V_190 ;
}
if ( V_419 != V_423 && V_419 != V_424 )
return 0 ;
V_9 = F_93 ( V_168 ) ;
if ( V_79 == V_425 )
return ( V_422 == V_9 -> V_45 ) ;
if ( V_79 == V_426 )
return ( V_422 != V_9 -> V_45 ) ;
return 0 ;
}
static void F_210 ( void * V_421 )
{
}
static int F_211 ( const char * V_2 )
{
return ( strcmp ( V_2 , V_112 ) == 0 ) ;
}
static int F_212 ( T_3 V_168 , char * * V_436 , T_3 * V_437 )
{
struct V_1 * V_9 = F_93 ( V_168 ) ;
if ( V_436 )
* V_436 = V_9 -> V_45 ;
* V_437 = strlen ( V_9 -> V_45 ) ;
return 0 ;
}
static int F_213 ( const char * V_436 , T_3 V_437 , T_3 * V_168 )
{
* V_168 = F_68 ( V_436 ) ;
return 0 ;
}
static void F_214 ( char * V_436 , T_3 V_437 )
{
}
static int F_215 ( struct V_3 * V_3 , void * V_438 , T_3 V_439 )
{
return F_130 ( V_3 , V_112 , V_438 , V_439 , 0 ) ;
}
static int F_216 ( struct V_5 * V_5 , void * V_438 , T_3 V_439 )
{
return F_217 ( V_5 , V_138 , V_438 , V_439 , 0 ) ;
}
static int F_218 ( struct V_3 * V_3 , void * * V_438 , T_3 * V_439 )
{
int V_108 = 0 ;
V_108 = F_64 ( V_3 , V_112 , V_438 , true ) ;
if ( V_108 < 0 )
return V_108 ;
* V_439 = V_108 ;
return 0 ;
}
static T_12 void F_219 ( void )
{
F_6 ( & V_408 . V_29 ) ;
F_6 ( & V_61 . V_29 ) ;
F_6 ( & V_57 . V_29 ) ;
F_6 ( & V_147 . V_29 ) ;
F_6 ( & V_149 . V_29 ) ;
F_6 ( & V_148 . V_29 ) ;
F_8 ( & V_408 . V_28 ) ;
F_8 ( & V_61 . V_28 ) ;
F_8 ( & V_147 . V_28 ) ;
F_8 ( & V_57 . V_28 ) ;
F_8 ( & V_149 . V_28 ) ;
F_8 ( & V_148 . V_28 ) ;
F_220 ( & V_408 ) ;
F_220 ( & V_61 ) ;
F_220 ( & V_147 ) ;
F_220 ( & V_57 ) ;
F_220 ( & V_149 ) ;
F_220 ( & V_148 ) ;
}
static T_12 int F_221 ( void )
{
struct V_96 * V_96 ;
struct V_21 * V_25 ;
if ( ! F_222 ( & V_440 ) )
return 0 ;
V_25 = F_7 ( & V_57 , & V_57 ,
V_13 ) ;
if ( V_25 == NULL )
return - V_36 ;
F_131 ( V_441 L_6 ) ;
V_96 = (struct V_96 * ) V_102 -> V_96 ;
V_96 -> V_97 = V_25 ;
F_219 () ;
if ( F_223 ( & V_440 ) )
F_224 ( L_7 ) ;
return 0 ;
}

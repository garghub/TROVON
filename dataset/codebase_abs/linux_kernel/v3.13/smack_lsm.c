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
if ( V_9 != & V_50 )
V_7 = - V_51 ;
return V_7 ;
}
static int F_24 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
V_55 = F_2 ( sizeof( struct V_54 ) , V_13 ) ;
if ( V_55 == NULL )
return - V_36 ;
V_55 -> V_56 = V_50 . V_45 ;
V_55 -> V_57 = V_50 . V_45 ;
V_55 -> V_58 = V_50 . V_45 ;
V_55 -> V_59 = V_60 . V_45 ;
V_53 -> V_61 = V_55 ;
return 0 ;
}
static void F_25 ( struct V_52 * V_53 )
{
F_4 ( V_53 -> V_61 ) ;
V_53 -> V_61 = NULL ;
}
static int F_26 ( char * V_62 , char * V_63 )
{
char * V_64 , * V_65 , * V_66 , * V_6 ;
V_66 = ( char * ) F_27 ( V_13 ) ;
if ( V_66 == NULL )
return - V_36 ;
for ( V_64 = V_62 , V_65 = V_62 ; V_65 != NULL ; V_64 = V_65 + 1 ) {
if ( strstr ( V_64 , V_67 ) == V_64 )
V_6 = V_63 ;
else if ( strstr ( V_64 , V_68 ) == V_64 )
V_6 = V_63 ;
else if ( strstr ( V_64 , V_69 ) == V_64 )
V_6 = V_63 ;
else if ( strstr ( V_64 , V_70 ) == V_64 )
V_6 = V_63 ;
else if ( strstr ( V_64 , V_71 ) == V_64 )
V_6 = V_63 ;
else
V_6 = V_66 ;
V_65 = strchr ( V_64 , ',' ) ;
if ( V_65 != NULL )
* V_65 = '\0' ;
if ( * V_6 != '\0' )
strcat ( V_6 , L_1 ) ;
strcat ( V_6 , V_64 ) ;
}
strcpy ( V_62 , V_66 ) ;
F_28 ( ( unsigned long ) V_66 ) ;
return 0 ;
}
static int F_29 ( struct V_52 * V_53 , int V_72 , void * V_73 )
{
struct V_5 * V_74 = V_53 -> V_75 ;
struct V_3 * V_3 = V_74 -> V_76 ;
struct V_54 * V_77 = V_53 -> V_61 ;
struct V_14 * V_16 ;
char * V_78 ;
char * V_65 ;
char * V_79 ;
int V_80 = 0 ;
if ( V_77 -> V_81 )
return 0 ;
V_77 -> V_81 = 1 ;
for ( V_78 = V_73 ; V_78 != NULL ; V_78 = V_65 ) {
V_65 = strchr ( V_78 , ',' ) ;
if ( V_65 != NULL )
* V_65 ++ = '\0' ;
if ( strncmp ( V_78 , V_69 , strlen ( V_69 ) ) == 0 ) {
V_78 += strlen ( V_69 ) ;
V_79 = F_30 ( V_78 , 0 ) ;
if ( V_79 != NULL )
V_77 -> V_59 = V_79 ;
} else if ( strncmp ( V_78 , V_68 , strlen ( V_68 ) ) == 0 ) {
V_78 += strlen ( V_68 ) ;
V_79 = F_30 ( V_78 , 0 ) ;
if ( V_79 != NULL )
V_77 -> V_58 = V_79 ;
} else if ( strncmp ( V_78 , V_67 ,
strlen ( V_67 ) ) == 0 ) {
V_78 += strlen ( V_67 ) ;
V_79 = F_30 ( V_78 , 0 ) ;
if ( V_79 != NULL )
V_77 -> V_57 = V_79 ;
} else if ( strncmp ( V_78 , V_70 , strlen ( V_70 ) ) == 0 ) {
V_78 += strlen ( V_70 ) ;
V_79 = F_30 ( V_78 , 0 ) ;
if ( V_79 != NULL )
V_77 -> V_56 = V_79 ;
} else if ( strncmp ( V_78 , V_71 , strlen ( V_71 ) ) == 0 ) {
V_78 += strlen ( V_71 ) ;
V_79 = F_30 ( V_78 , 0 ) ;
if ( V_79 != NULL ) {
V_77 -> V_56 = V_79 ;
V_80 = 1 ;
}
}
}
V_16 = V_3 -> V_82 ;
if ( V_3 -> V_82 == NULL ) {
V_3 -> V_82 = F_5 ( V_77 -> V_56 ) ;
V_16 = V_3 -> V_82 ;
} else
V_16 -> V_18 = V_77 -> V_56 ;
if ( V_80 )
V_16 -> V_19 |= V_83 ;
return 0 ;
}
static int F_31 ( struct V_5 * V_5 )
{
struct V_54 * V_84 = V_5 -> V_85 -> V_61 ;
int V_7 ;
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_86 ) ;
F_32 ( & V_42 , V_5 ) ;
V_7 = F_18 ( V_84 -> V_58 , V_87 , & V_42 ) ;
return V_7 ;
}
static int F_33 ( const char * V_88 , struct V_89 * V_89 ,
const char * type , unsigned long V_72 , void * V_73 )
{
struct V_54 * V_84 = V_89 -> V_5 -> V_85 -> V_61 ;
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_34 ( & V_42 , * V_89 ) ;
return F_18 ( V_84 -> V_58 , V_91 , & V_42 ) ;
}
static int F_35 ( struct V_92 * V_93 , int V_72 )
{
struct V_54 * V_84 ;
struct V_41 V_42 ;
struct V_89 V_89 ;
V_89 . V_5 = V_93 -> V_94 ;
V_89 . V_93 = V_93 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_34 ( & V_42 , V_89 ) ;
V_84 = V_89 . V_5 -> V_85 -> V_61 ;
return F_18 ( V_84 -> V_58 , V_91 , & V_42 ) ;
}
static int F_36 ( struct V_95 * V_96 )
{
struct V_3 * V_3 = F_37 ( V_96 -> V_97 ) ;
struct V_21 * V_98 = V_96 -> V_99 -> V_100 ;
struct V_14 * V_16 ;
int V_7 ;
V_7 = F_38 ( V_96 ) ;
if ( V_7 != 0 )
return V_7 ;
if ( V_96 -> V_101 )
return 0 ;
V_16 = V_3 -> V_82 ;
if ( V_16 -> V_26 == NULL || V_16 -> V_26 == V_98 -> V_26 )
return 0 ;
if ( V_96 -> V_102 )
return - V_103 ;
V_98 -> V_26 = V_16 -> V_26 ;
V_96 -> V_104 |= V_105 ;
return 0 ;
}
static void F_39 ( struct V_95 * V_96 )
{
struct V_21 * V_98 = V_96 -> V_99 -> V_100 ;
if ( V_98 -> V_26 != V_98 -> V_27 )
V_106 -> V_107 = 0 ;
}
static int F_40 ( struct V_95 * V_96 )
{
struct V_21 * V_25 = F_41 () ;
int V_108 = F_42 ( V_96 ) ;
if ( ! V_108 && ( V_25 -> V_26 != V_25 -> V_27 ) )
V_108 = 1 ;
return V_108 ;
}
static int F_43 ( struct V_3 * V_3 )
{
struct V_1 * V_9 = F_22 () ;
V_3 -> V_82 = F_5 ( V_9 -> V_45 ) ;
if ( V_3 -> V_82 == NULL )
return - V_36 ;
return 0 ;
}
static void F_44 ( struct V_3 * V_3 )
{
F_4 ( V_3 -> V_82 ) ;
V_3 -> V_82 = NULL ;
}
static int F_45 ( struct V_3 * V_3 , struct V_3 * V_109 ,
const struct V_110 * V_110 , const char * * V_2 ,
void * * V_111 , T_2 * V_112 )
{
struct V_14 * V_113 = V_3 -> V_82 ;
struct V_1 * V_9 = F_22 () ;
char * V_16 = F_46 ( V_3 ) ;
char * V_114 = F_46 ( V_109 ) ;
int V_115 ;
if ( V_2 )
* V_2 = V_116 ;
if ( V_111 ) {
F_47 () ;
V_115 = F_48 ( V_9 -> V_45 , V_114 , & V_9 -> V_28 ) ;
F_49 () ;
if ( V_115 > 0 && ( ( V_115 & V_117 ) != 0 ) &&
F_50 ( V_109 ) ) {
V_16 = V_114 ;
V_113 -> V_19 |= V_118 ;
}
* V_111 = F_51 ( V_16 , V_17 ) ;
if ( * V_111 == NULL )
return - V_36 ;
}
if ( V_112 )
* V_112 = strlen ( V_16 ) + 1 ;
return 0 ;
}
static int F_52 ( struct V_5 * V_119 , struct V_3 * V_109 ,
struct V_5 * V_120 )
{
char * V_16 ;
struct V_41 V_42 ;
int V_7 ;
F_16 ( & V_42 , V_43 , V_86 ) ;
F_32 ( & V_42 , V_119 ) ;
V_16 = F_46 ( V_119 -> V_76 ) ;
V_7 = F_18 ( V_16 , V_91 , & V_42 ) ;
if ( V_7 == 0 && V_120 -> V_76 != NULL ) {
V_16 = F_46 ( V_120 -> V_76 ) ;
F_32 ( & V_42 , V_120 ) ;
V_7 = F_18 ( V_16 , V_91 , & V_42 ) ;
}
return V_7 ;
}
static int F_53 ( struct V_3 * V_109 , struct V_5 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_76 ;
struct V_41 V_42 ;
int V_7 ;
F_16 ( & V_42 , V_43 , V_86 ) ;
F_32 ( & V_42 , V_5 ) ;
V_7 = F_18 ( F_46 ( V_4 ) , V_91 , & V_42 ) ;
if ( V_7 == 0 ) {
F_16 ( & V_42 , V_43 , V_121 ) ;
F_54 ( & V_42 , V_109 ) ;
V_7 = F_18 ( F_46 ( V_109 ) , V_91 , & V_42 ) ;
}
return V_7 ;
}
static int F_55 ( struct V_3 * V_109 , struct V_5 * V_5 )
{
struct V_41 V_42 ;
int V_7 ;
F_16 ( & V_42 , V_43 , V_86 ) ;
F_32 ( & V_42 , V_5 ) ;
V_7 = F_18 ( F_46 ( V_5 -> V_76 ) , V_91 , & V_42 ) ;
if ( V_7 == 0 ) {
F_16 ( & V_42 , V_43 , V_121 ) ;
F_54 ( & V_42 , V_109 ) ;
V_7 = F_18 ( F_46 ( V_109 ) , V_91 , & V_42 ) ;
}
return V_7 ;
}
static int F_56 ( struct V_3 * V_122 ,
struct V_5 * V_119 ,
struct V_3 * V_123 ,
struct V_5 * V_120 )
{
int V_7 ;
char * V_16 ;
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_86 ) ;
F_32 ( & V_42 , V_119 ) ;
V_16 = F_46 ( V_119 -> V_76 ) ;
V_7 = F_18 ( V_16 , V_47 , & V_42 ) ;
if ( V_7 == 0 && V_120 -> V_76 != NULL ) {
V_16 = F_46 ( V_120 -> V_76 ) ;
F_32 ( & V_42 , V_120 ) ;
V_7 = F_18 ( V_16 , V_47 , & V_42 ) ;
}
return V_7 ;
}
static int F_57 ( struct V_3 * V_3 , int V_124 )
{
struct V_41 V_42 ;
int V_125 = V_124 & V_126 ;
V_124 &= ( V_87 | V_91 | V_127 | V_128 ) ;
if ( V_124 == 0 )
return 0 ;
if ( V_125 )
return - V_129 ;
F_16 ( & V_42 , V_43 , V_121 ) ;
F_54 ( & V_42 , V_3 ) ;
return F_18 ( F_46 ( V_3 ) , V_124 , & V_42 ) ;
}
static int F_58 ( struct V_5 * V_5 , struct V_130 * V_130 )
{
struct V_41 V_42 ;
if ( V_130 -> V_131 & V_132 )
return 0 ;
F_16 ( & V_42 , V_43 , V_86 ) ;
F_32 ( & V_42 , V_5 ) ;
return F_18 ( F_46 ( V_5 -> V_76 ) , V_91 , & V_42 ) ;
}
static int F_59 ( struct V_92 * V_93 , struct V_5 * V_5 )
{
struct V_41 V_42 ;
struct V_89 V_89 ;
V_89 . V_5 = V_5 ;
V_89 . V_93 = V_93 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_34 ( & V_42 , V_89 ) ;
return F_18 ( F_46 ( V_5 -> V_76 ) , V_87 , & V_42 ) ;
}
static int F_60 ( struct V_5 * V_5 , const char * V_2 ,
const void * V_111 , T_2 V_133 , int V_72 )
{
struct V_41 V_42 ;
int V_7 = 0 ;
if ( strcmp ( V_2 , V_134 ) == 0 ||
strcmp ( V_2 , V_135 ) == 0 ||
strcmp ( V_2 , V_136 ) == 0 ||
strcmp ( V_2 , V_137 ) == 0 ||
strcmp ( V_2 , V_138 ) == 0 ) {
if ( ! F_23 ( V_139 ) )
V_7 = - V_103 ;
if ( V_133 == 0 || V_133 >= V_12 ||
F_30 ( V_111 , V_133 ) == NULL )
V_7 = - V_140 ;
} else if ( strcmp ( V_2 , V_141 ) == 0 ) {
if ( ! F_23 ( V_139 ) )
V_7 = - V_103 ;
if ( V_133 != V_142 ||
strncmp ( V_111 , V_143 , V_142 ) != 0 )
V_7 = - V_140 ;
} else
V_7 = F_61 ( V_5 , V_2 , V_111 , V_133 , V_72 ) ;
F_16 ( & V_42 , V_43 , V_86 ) ;
F_32 ( & V_42 , V_5 ) ;
if ( V_7 == 0 )
V_7 = F_18 ( F_46 ( V_5 -> V_76 ) , V_91 , & V_42 ) ;
return V_7 ;
}
static void F_62 ( struct V_5 * V_5 , const char * V_2 ,
const void * V_111 , T_2 V_133 , int V_72 )
{
struct V_1 * V_9 ;
struct V_14 * V_16 = V_5 -> V_76 -> V_82 ;
if ( strcmp ( V_2 , V_141 ) == 0 ) {
V_16 -> V_19 |= V_83 ;
return;
}
V_9 = F_3 ( V_111 , V_133 ) ;
if ( strcmp ( V_2 , V_134 ) == 0 ) {
if ( V_9 != NULL )
V_16 -> V_18 = V_9 -> V_45 ;
else
V_16 -> V_18 = V_144 . V_45 ;
} else if ( strcmp ( V_2 , V_137 ) == 0 ) {
if ( V_9 != NULL )
V_16 -> V_26 = V_9 ;
else
V_16 -> V_26 = & V_144 ;
} else if ( strcmp ( V_2 , V_138 ) == 0 ) {
if ( V_9 != NULL )
V_16 -> V_145 = V_9 ;
else
V_16 -> V_145 = & V_144 ;
}
return;
}
static int F_63 ( struct V_5 * V_5 , const char * V_2 )
{
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_86 ) ;
F_32 ( & V_42 , V_5 ) ;
return F_18 ( F_46 ( V_5 -> V_76 ) , V_87 , & V_42 ) ;
}
static int F_64 ( struct V_5 * V_5 , const char * V_2 )
{
struct V_14 * V_16 ;
struct V_41 V_42 ;
int V_7 = 0 ;
if ( strcmp ( V_2 , V_134 ) == 0 ||
strcmp ( V_2 , V_135 ) == 0 ||
strcmp ( V_2 , V_136 ) == 0 ||
strcmp ( V_2 , V_137 ) == 0 ||
strcmp ( V_2 , V_141 ) == 0 ||
strcmp ( V_2 , V_138 ) ) {
if ( ! F_23 ( V_139 ) )
V_7 = - V_103 ;
} else
V_7 = F_65 ( V_5 , V_2 ) ;
F_16 ( & V_42 , V_43 , V_86 ) ;
F_32 ( & V_42 , V_5 ) ;
if ( V_7 == 0 )
V_7 = F_18 ( F_46 ( V_5 -> V_76 ) , V_91 , & V_42 ) ;
if ( V_7 == 0 ) {
V_16 = V_5 -> V_76 -> V_82 ;
V_16 -> V_26 = NULL ;
V_16 -> V_145 = NULL ;
}
return V_7 ;
}
static int F_66 ( const struct V_3 * V_3 ,
const char * V_2 , void * * V_8 ,
bool V_146 )
{
struct V_147 * V_148 ;
struct V_149 * V_150 ;
struct V_52 * V_84 ;
struct V_3 * V_4 = (struct V_3 * ) V_3 ;
char * V_16 ;
int V_151 ;
int V_7 = 0 ;
if ( strcmp ( V_2 , V_116 ) == 0 ) {
V_16 = F_46 ( V_3 ) ;
V_151 = strlen ( V_16 ) + 1 ;
* V_8 = V_16 ;
return V_151 ;
}
V_84 = V_4 -> V_152 ;
if ( V_84 -> V_153 != V_154 )
return - V_155 ;
V_150 = F_67 ( V_4 ) ;
if ( V_150 == NULL || V_150 -> V_156 == NULL )
return - V_155 ;
V_148 = V_150 -> V_156 -> V_157 ;
if ( strcmp ( V_2 , V_158 ) == 0 )
V_16 = V_148 -> V_159 ;
else if ( strcmp ( V_2 , V_160 ) == 0 )
V_16 = V_148 -> V_161 -> V_45 ;
else
return - V_155 ;
V_151 = strlen ( V_16 ) + 1 ;
if ( V_7 == 0 ) {
* V_8 = V_16 ;
V_7 = V_151 ;
}
return V_7 ;
}
static int F_68 ( struct V_3 * V_3 , char * V_8 ,
T_2 V_162 )
{
int V_112 = strlen ( V_134 ) ;
if ( V_8 != NULL && V_112 <= V_162 ) {
memcpy ( V_8 , V_134 , V_112 ) ;
return V_112 ;
}
return - V_140 ;
}
static void F_69 ( const struct V_3 * V_3 , T_3 * V_163 )
{
struct V_14 * V_16 = V_3 -> V_82 ;
* V_163 = F_70 ( V_16 -> V_18 ) ;
}
static int F_71 ( struct V_97 * V_97 , int V_124 )
{
return 0 ;
}
static int F_72 ( struct V_97 * V_97 )
{
struct V_1 * V_9 = F_22 () ;
V_97 -> V_164 = V_9 -> V_45 ;
return 0 ;
}
static void F_73 ( struct V_97 * V_97 )
{
V_97 -> V_164 = NULL ;
}
static int F_74 ( struct V_97 * V_97 , unsigned int V_165 ,
unsigned long V_166 )
{
int V_7 = 0 ;
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_34 ( & V_42 , V_97 -> V_167 ) ;
if ( F_75 ( V_165 ) & V_168 )
V_7 = F_18 ( V_97 -> V_164 , V_91 , & V_42 ) ;
if ( V_7 == 0 && ( F_75 ( V_165 ) & V_169 ) )
V_7 = F_18 ( V_97 -> V_164 , V_87 , & V_42 ) ;
return V_7 ;
}
static int F_76 ( struct V_97 * V_97 , unsigned int V_165 )
{
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_90 ) ;
F_34 ( & V_42 , V_97 -> V_167 ) ;
return F_18 ( V_97 -> V_164 , V_170 , & V_42 ) ;
}
static int F_77 ( struct V_97 * V_97 , unsigned int V_165 ,
unsigned long V_166 )
{
struct V_41 V_42 ;
int V_7 = 0 ;
switch ( V_165 ) {
case V_171 :
break;
case V_172 :
case V_173 :
F_16 ( & V_42 , V_43 , V_90 ) ;
F_34 ( & V_42 , V_97 -> V_167 ) ;
V_7 = F_18 ( V_97 -> V_164 , V_170 , & V_42 ) ;
break;
case V_174 :
case V_175 :
F_16 ( & V_42 , V_43 , V_90 ) ;
F_34 ( & V_42 , V_97 -> V_167 ) ;
V_7 = F_18 ( V_97 -> V_164 , V_91 , & V_42 ) ;
break;
default:
break;
}
return V_7 ;
}
static int F_78 ( struct V_97 * V_97 ,
unsigned long V_176 , unsigned long V_177 ,
unsigned long V_72 )
{
struct V_1 * V_9 ;
struct V_1 * V_178 ;
struct V_33 * V_179 ;
struct V_21 * V_25 ;
char * V_180 ;
struct V_14 * V_16 ;
int V_115 ;
int V_181 ;
int V_182 ;
int V_7 ;
if ( V_97 == NULL )
return 0 ;
V_16 = F_37 ( V_97 ) -> V_82 ;
if ( V_16 -> V_145 == NULL )
return 0 ;
V_178 = V_16 -> V_145 ;
V_25 = F_41 () ;
V_9 = F_22 () ;
V_7 = 0 ;
F_47 () ;
F_10 (srp, &skp->smk_rules, list) {
V_180 = V_179 -> V_183 ;
if ( V_178 -> V_45 == V_180 )
continue;
V_115 = F_48 ( V_179 -> V_184 -> V_45 , V_180 ,
& V_25 -> V_28 ) ;
if ( V_115 == - V_185 )
V_115 = V_179 -> V_186 ;
else
V_115 &= V_179 -> V_186 ;
if ( V_115 == 0 )
continue;
V_181 = F_48 ( V_178 -> V_45 , V_180 ,
& V_178 -> V_28 ) ;
if ( V_181 == - V_185 ) {
V_7 = - V_51 ;
break;
}
V_182 = F_48 ( V_178 -> V_45 , V_180 ,
& V_25 -> V_28 ) ;
if ( V_182 != - V_185 )
V_181 &= V_182 ;
if ( ( V_115 | V_181 ) != V_181 ) {
V_7 = - V_51 ;
break;
}
}
F_49 () ;
return V_7 ;
}
static int F_79 ( struct V_97 * V_97 )
{
struct V_1 * V_9 = F_22 () ;
V_97 -> V_164 = V_9 -> V_45 ;
return 0 ;
}
static int F_80 ( struct V_38 * V_187 ,
struct V_188 * V_189 , int V_190 )
{
struct V_1 * V_9 ;
struct V_1 * V_191 = F_14 ( V_187 -> V_99 -> V_100 ) ;
struct V_97 * V_97 ;
int V_7 ;
struct V_41 V_42 ;
V_97 = F_81 ( V_189 , struct V_97 , V_192 ) ;
V_9 = F_82 ( V_97 -> V_164 ) ;
V_7 = V_186 ( V_9 , V_191 -> V_45 , V_91 , NULL ) ;
if ( V_7 != 0 && F_83 ( V_187 , V_49 ) )
V_7 = 0 ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_17 ( & V_42 , V_187 ) ;
F_84 ( V_97 -> V_164 , V_191 -> V_45 , V_91 , V_7 , & V_42 ) ;
return V_7 ;
}
static int F_85 ( struct V_97 * V_97 )
{
int V_115 = 0 ;
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_34 ( & V_42 , V_97 -> V_167 ) ;
if ( V_97 -> V_193 & V_194 )
V_115 = V_87 ;
if ( V_97 -> V_193 & V_195 )
V_115 |= V_91 ;
return F_18 ( V_97 -> V_164 , V_115 , & V_42 ) ;
}
static int F_86 ( struct V_97 * V_97 , const struct V_99 * V_99 )
{
struct V_14 * V_16 = F_37 ( V_97 ) -> V_82 ;
V_97 -> V_164 = V_16 -> V_18 ;
return 0 ;
}
static int F_87 ( struct V_99 * V_99 , T_1 V_24 )
{
struct V_21 * V_25 ;
V_25 = F_7 ( NULL , NULL , V_24 ) ;
if ( V_25 == NULL )
return - V_36 ;
V_99 -> V_100 = V_25 ;
return 0 ;
}
static void F_88 ( struct V_99 * V_99 )
{
struct V_21 * V_25 = V_99 -> V_100 ;
struct V_33 * V_196 ;
struct V_30 * V_197 ;
struct V_30 * V_198 ;
if ( V_25 == NULL )
return;
V_99 -> V_100 = NULL ;
F_89 (l, n, &tsp->smk_rules) {
V_196 = F_90 ( V_197 , struct V_33 , V_37 ) ;
F_91 ( & V_196 -> V_37 ) ;
F_4 ( V_196 ) ;
}
F_4 ( V_25 ) ;
}
static int F_92 ( struct V_99 * V_199 , const struct V_99 * V_200 ,
T_1 V_24 )
{
struct V_21 * V_201 = V_200 -> V_100 ;
struct V_21 * V_202 ;
int V_7 ;
V_202 = F_7 ( V_201 -> V_26 , V_201 -> V_26 , V_24 ) ;
if ( V_202 == NULL )
return - V_36 ;
V_7 = F_9 ( & V_202 -> V_28 , & V_201 -> V_28 , V_24 ) ;
if ( V_7 != 0 )
return V_7 ;
V_199 -> V_100 = V_202 ;
return 0 ;
}
static void F_93 ( struct V_99 * V_199 , const struct V_99 * V_200 )
{
struct V_21 * V_201 = V_200 -> V_100 ;
struct V_21 * V_202 = V_199 -> V_100 ;
V_202 -> V_26 = V_201 -> V_26 ;
V_202 -> V_27 = V_201 -> V_26 ;
F_6 ( & V_202 -> V_29 ) ;
F_8 ( & V_202 -> V_28 ) ;
}
static int F_94 ( struct V_99 * V_199 , T_3 V_163 )
{
struct V_21 * V_202 = V_199 -> V_100 ;
struct V_1 * V_9 = F_95 ( V_163 ) ;
if ( V_9 == NULL )
return - V_140 ;
V_202 -> V_26 = V_9 ;
return 0 ;
}
static int F_96 ( struct V_99 * V_199 ,
struct V_3 * V_3 )
{
struct V_14 * V_16 = V_3 -> V_82 ;
struct V_21 * V_25 = V_199 -> V_100 ;
V_25 -> V_27 = F_82 ( V_16 -> V_18 ) ;
V_25 -> V_26 = V_25 -> V_27 ;
return 0 ;
}
static int F_97 ( struct V_38 * V_203 , int V_204 ,
const char * V_205 )
{
struct V_41 V_42 ;
struct V_1 * V_9 = F_14 ( F_15 ( V_203 ) ) ;
F_16 ( & V_42 , V_205 , V_44 ) ;
F_17 ( & V_42 , V_203 ) ;
return F_18 ( V_9 -> V_45 , V_204 , & V_42 ) ;
}
static int F_98 ( struct V_38 * V_203 , T_4 V_206 )
{
return F_97 ( V_203 , V_91 , V_43 ) ;
}
static int F_99 ( struct V_38 * V_203 )
{
return F_97 ( V_203 , V_87 , V_43 ) ;
}
static int F_100 ( struct V_38 * V_203 )
{
return F_97 ( V_203 , V_87 , V_43 ) ;
}
static void F_101 ( struct V_38 * V_203 , T_3 * V_163 )
{
struct V_1 * V_9 = F_14 ( F_15 ( V_203 ) ) ;
* V_163 = V_9 -> V_207 ;
}
static int F_102 ( struct V_38 * V_203 , int V_208 )
{
int V_7 ;
V_7 = F_103 ( V_203 , V_208 ) ;
if ( V_7 == 0 )
V_7 = F_97 ( V_203 , V_91 , V_43 ) ;
return V_7 ;
}
static int F_104 ( struct V_38 * V_203 , int V_209 )
{
int V_7 ;
V_7 = F_105 ( V_203 , V_209 ) ;
if ( V_7 == 0 )
V_7 = F_97 ( V_203 , V_91 , V_43 ) ;
return V_7 ;
}
static int F_106 ( struct V_38 * V_203 )
{
return F_97 ( V_203 , V_87 , V_43 ) ;
}
static int F_107 ( struct V_38 * V_203 )
{
int V_7 ;
V_7 = F_108 ( V_203 ) ;
if ( V_7 == 0 )
V_7 = F_97 ( V_203 , V_91 , V_43 ) ;
return V_7 ;
}
static int F_109 ( struct V_38 * V_203 )
{
return F_97 ( V_203 , V_87 , V_43 ) ;
}
static int F_110 ( struct V_38 * V_203 )
{
return F_97 ( V_203 , V_91 , V_43 ) ;
}
static int F_111 ( struct V_38 * V_203 , struct V_210 * V_211 ,
int V_212 , T_3 V_163 )
{
struct V_41 V_42 ;
struct V_1 * V_9 ;
struct V_1 * V_191 = F_14 ( F_15 ( V_203 ) ) ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_17 ( & V_42 , V_203 ) ;
if ( V_163 == 0 )
return F_18 ( V_191 -> V_45 , V_91 , & V_42 ) ;
V_9 = F_95 ( V_163 ) ;
return V_186 ( V_9 , V_191 -> V_45 , V_91 , & V_42 ) ;
}
static int F_112 ( struct V_38 * V_203 )
{
return 0 ;
}
static void F_113 ( struct V_38 * V_203 , struct V_3 * V_3 )
{
struct V_14 * V_16 = V_3 -> V_82 ;
struct V_1 * V_9 = F_14 ( F_15 ( V_203 ) ) ;
V_16 -> V_18 = V_9 -> V_45 ;
}
static int F_114 ( struct V_150 * V_156 , int V_213 , T_1 V_214 )
{
struct V_1 * V_9 = F_22 () ;
struct V_147 * V_148 ;
V_148 = F_2 ( sizeof( struct V_147 ) , V_214 ) ;
if ( V_148 == NULL )
return - V_36 ;
V_148 -> V_159 = V_9 -> V_45 ;
V_148 -> V_161 = V_9 ;
V_148 -> V_215 = NULL ;
V_156 -> V_157 = V_148 ;
return 0 ;
}
static void F_115 ( struct V_150 * V_156 )
{
F_4 ( V_156 -> V_157 ) ;
}
static char * F_116 ( struct V_216 * V_217 )
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
static int F_117 ( struct V_150 * V_156 , int V_228 )
{
struct V_1 * V_9 ;
struct V_147 * V_148 = V_156 -> V_157 ;
int V_7 = 0 ;
F_118 () ;
F_119 ( V_156 ) ;
if ( V_148 -> V_161 == V_229 ||
V_228 == V_230 )
F_120 ( V_156 ) ;
else {
V_9 = V_148 -> V_161 ;
V_7 = F_121 ( V_156 , V_156 -> V_231 , & V_9 -> V_232 ) ;
}
F_122 ( V_156 ) ;
F_123 () ;
return V_7 ;
}
static int F_124 ( struct V_150 * V_156 , struct V_216 * V_233 )
{
struct V_1 * V_9 ;
int V_7 ;
int V_234 ;
char * V_235 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_41 V_42 ;
F_47 () ;
V_235 = F_116 ( V_233 ) ;
if ( V_235 != NULL ) {
#ifdef F_125
struct V_236 V_237 ;
F_126 ( & V_42 , V_43 , V_238 , & V_237 ) ;
V_42 . V_239 . V_240 . V_237 -> V_213 = V_233 -> V_241 ;
V_42 . V_239 . V_240 . V_237 -> V_242 = V_233 -> V_243 ;
V_42 . V_239 . V_240 . V_237 -> V_244 . V_245 = V_233 -> V_222 . V_223 ;
#endif
V_234 = V_230 ;
V_9 = V_148 -> V_161 ;
V_7 = V_186 ( V_9 , V_235 , V_91 , & V_42 ) ;
} else {
V_234 = V_246 ;
V_7 = 0 ;
}
F_49 () ;
if ( V_7 != 0 )
return V_7 ;
return F_117 ( V_156 , V_234 ) ;
}
static void F_127 ( struct V_149 * V_150 , struct V_247 * V_248 )
{
struct V_150 * V_156 = V_150 -> V_156 ;
struct V_249 * V_250 ;
struct V_147 * V_148 = V_150 -> V_156 -> V_157 ;
struct V_251 * V_252 ;
unsigned short V_253 = 0 ;
if ( V_248 == NULL ) {
F_128 (spp, &smk_ipv6_port_list, list) {
if ( V_156 != V_252 -> V_254 )
continue;
V_252 -> V_159 = V_148 -> V_159 ;
V_252 -> V_161 = V_148 -> V_161 ;
return;
}
return;
}
V_250 = (struct V_249 * ) V_248 ;
V_253 = F_129 ( V_250 -> V_255 ) ;
if ( V_253 == 0 )
return;
F_128 (spp, &smk_ipv6_port_list, list) {
if ( V_252 -> V_256 != V_253 )
continue;
V_252 -> V_256 = V_253 ;
V_252 -> V_254 = V_156 ;
V_252 -> V_159 = V_148 -> V_159 ;
V_252 -> V_161 = V_148 -> V_161 ;
return;
}
V_252 = F_2 ( sizeof( * V_252 ) , V_13 ) ;
if ( V_252 == NULL )
return;
V_252 -> V_256 = V_253 ;
V_252 -> V_254 = V_156 ;
V_252 -> V_159 = V_148 -> V_159 ;
V_252 -> V_161 = V_148 -> V_161 ;
F_130 ( & V_252 -> V_37 , & V_257 ) ;
return;
}
static int F_131 ( struct V_150 * V_156 , struct V_249 * V_248 ,
int V_258 )
{
T_5 * V_259 ;
T_6 * V_260 ;
struct V_251 * V_252 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_1 * V_9 ;
unsigned short V_253 = 0 ;
char * V_261 ;
struct V_41 V_42 ;
#ifdef F_125
struct V_236 V_237 ;
#endif
if ( V_258 == V_262 ) {
V_9 = V_229 ;
V_261 = V_148 -> V_159 ;
} else {
V_9 = V_148 -> V_161 ;
V_261 = V_229 -> V_45 ;
}
V_253 = F_129 ( V_248 -> V_255 ) ;
V_259 = ( T_5 * ) ( & V_248 -> V_263 ) ;
V_260 = ( T_6 * ) ( & V_248 -> V_263 ) ;
if ( V_260 [ 0 ] || V_260 [ 1 ] || V_260 [ 2 ] || V_259 [ 6 ] || F_129 ( V_259 [ 7 ] ) != 1 )
goto V_264;
if ( V_258 == V_262 ) {
V_9 = & V_265 ;
goto V_264;
}
F_128 (spp, &smk_ipv6_port_list, list) {
if ( V_252 -> V_256 != V_253 )
continue;
V_261 = V_252 -> V_159 ;
if ( V_258 == V_266 )
V_148 -> V_215 = V_252 -> V_161 -> V_45 ;
break;
}
V_264:
#ifdef F_125
F_126 ( & V_42 , V_43 , V_238 , & V_237 ) ;
V_42 . V_239 . V_240 . V_237 -> V_213 = V_156 -> V_231 ;
V_42 . V_239 . V_240 . V_237 -> V_242 = V_253 ;
if ( V_258 == V_262 )
V_42 . V_239 . V_240 . V_237 -> V_267 . V_268 = V_248 -> V_263 ;
else
V_42 . V_239 . V_240 . V_237 -> V_267 . V_245 = V_248 -> V_263 ;
#endif
return V_186 ( V_9 , V_261 , V_91 , & V_42 ) ;
}
static int F_132 ( struct V_3 * V_3 , const char * V_2 ,
const void * V_111 , T_2 V_133 , int V_72 )
{
struct V_1 * V_9 ;
struct V_14 * V_79 = V_3 -> V_82 ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
int V_7 = 0 ;
if ( V_111 == NULL || V_133 > V_12 || V_133 == 0 )
return - V_51 ;
V_9 = F_3 ( V_111 , V_133 ) ;
if ( V_9 == NULL )
return - V_140 ;
if ( strcmp ( V_2 , V_116 ) == 0 ) {
V_79 -> V_18 = V_9 -> V_45 ;
V_79 -> V_19 |= V_269 ;
return 0 ;
}
if ( V_3 -> V_152 -> V_153 != V_154 )
return - V_155 ;
V_150 = F_67 ( V_3 ) ;
if ( V_150 == NULL || V_150 -> V_156 == NULL )
return - V_155 ;
V_148 = V_150 -> V_156 -> V_157 ;
if ( strcmp ( V_2 , V_158 ) == 0 )
V_148 -> V_159 = V_9 -> V_45 ;
else if ( strcmp ( V_2 , V_160 ) == 0 ) {
V_148 -> V_161 = V_9 ;
if ( V_150 -> V_156 -> V_231 == V_270 ) {
V_7 = F_117 ( V_150 -> V_156 , V_246 ) ;
if ( V_7 != 0 )
F_133 ( V_271
L_2 ,
V_43 , - V_7 ) ;
}
} else
return - V_155 ;
if ( V_150 -> V_156 -> V_231 == V_272 )
F_127 ( V_150 , NULL ) ;
return 0 ;
}
static int F_134 ( struct V_149 * V_150 , int V_213 ,
int type , int V_273 , int V_274 )
{
if ( V_213 != V_270 || V_150 -> V_156 == NULL )
return 0 ;
return F_117 ( V_150 -> V_156 , V_246 ) ;
}
static int F_135 ( struct V_149 * V_150 , struct V_247 * V_248 ,
int V_275 )
{
if ( V_150 -> V_156 != NULL && V_150 -> V_156 -> V_231 == V_272 )
F_127 ( V_150 , V_248 ) ;
return 0 ;
}
static int F_136 ( struct V_149 * V_150 , struct V_247 * V_233 ,
int V_275 )
{
int V_7 = 0 ;
if ( V_150 -> V_156 == NULL )
return 0 ;
switch ( V_150 -> V_156 -> V_231 ) {
case V_270 :
if ( V_275 < sizeof( struct V_216 ) )
return - V_140 ;
V_7 = F_124 ( V_150 -> V_156 , (struct V_216 * ) V_233 ) ;
break;
case V_272 :
if ( V_275 < sizeof( struct V_249 ) )
return - V_140 ;
V_7 = F_131 ( V_150 -> V_156 , (struct V_249 * ) V_233 ,
V_266 ) ;
break;
}
return V_7 ;
}
static int F_137 ( int V_72 )
{
int V_115 = 0 ;
if ( V_72 & V_276 )
V_115 |= V_87 ;
if ( V_72 & V_277 )
V_115 |= V_91 ;
if ( V_72 & V_278 )
V_115 |= V_127 ;
return V_115 ;
}
static int F_138 ( struct V_279 * V_280 )
{
struct V_1 * V_9 = F_22 () ;
V_280 -> V_100 = V_9 -> V_45 ;
return 0 ;
}
static void F_139 ( struct V_279 * V_280 )
{
V_280 -> V_100 = NULL ;
}
static char * F_140 ( struct V_281 * V_282 )
{
return ( char * ) V_282 -> V_283 . V_100 ;
}
static int F_141 ( struct V_281 * V_282 )
{
struct V_284 * V_16 = & V_282 -> V_283 ;
struct V_1 * V_9 = F_22 () ;
V_16 -> V_100 = V_9 -> V_45 ;
return 0 ;
}
static void F_142 ( struct V_281 * V_282 )
{
struct V_284 * V_16 = & V_282 -> V_283 ;
V_16 -> V_100 = NULL ;
}
static int F_143 ( struct V_281 * V_282 , int V_204 )
{
char * V_148 = F_140 ( V_282 ) ;
struct V_41 V_42 ;
#ifdef F_125
F_16 ( & V_42 , V_43 , V_285 ) ;
V_42 . V_239 . V_240 . V_286 = V_282 -> V_283 . V_287 ;
#endif
return F_18 ( V_148 , V_204 , & V_42 ) ;
}
static int F_144 ( struct V_281 * V_282 , int V_288 )
{
int V_115 ;
V_115 = F_137 ( V_288 ) ;
return F_143 ( V_282 , V_115 ) ;
}
static int F_145 ( struct V_281 * V_282 , int V_165 )
{
int V_115 ;
switch ( V_165 ) {
case V_289 :
case V_290 :
V_115 = V_87 ;
break;
case V_291 :
case V_292 :
case V_293 :
case V_294 :
V_115 = V_47 ;
break;
case V_295 :
case V_296 :
return 0 ;
default:
return - V_140 ;
}
return F_143 ( V_282 , V_115 ) ;
}
static int F_146 ( struct V_281 * V_282 , char T_7 * V_297 ,
int V_288 )
{
int V_115 ;
V_115 = F_137 ( V_288 ) ;
return F_143 ( V_282 , V_115 ) ;
}
static char * F_147 ( struct V_298 * V_299 )
{
return ( char * ) V_299 -> V_300 . V_100 ;
}
static int F_148 ( struct V_298 * V_299 )
{
struct V_284 * V_16 = & V_299 -> V_300 ;
struct V_1 * V_9 = F_22 () ;
V_16 -> V_100 = V_9 -> V_45 ;
return 0 ;
}
static void F_149 ( struct V_298 * V_299 )
{
struct V_284 * V_16 = & V_299 -> V_300 ;
V_16 -> V_100 = NULL ;
}
static int F_150 ( struct V_298 * V_299 , int V_204 )
{
char * V_148 = F_147 ( V_299 ) ;
struct V_41 V_42 ;
#ifdef F_125
F_16 ( & V_42 , V_43 , V_285 ) ;
V_42 . V_239 . V_240 . V_286 = V_299 -> V_300 . V_287 ;
#endif
return F_18 ( V_148 , V_204 , & V_42 ) ;
}
static int F_151 ( struct V_298 * V_299 , int V_301 )
{
int V_115 ;
V_115 = F_137 ( V_301 ) ;
return F_150 ( V_299 , V_115 ) ;
}
static int F_152 ( struct V_298 * V_299 , int V_165 )
{
int V_115 ;
switch ( V_165 ) {
case V_302 :
case V_303 :
case V_304 :
case V_305 :
case V_306 :
case V_289 :
case V_307 :
V_115 = V_87 ;
break;
case V_308 :
case V_309 :
case V_294 :
case V_291 :
V_115 = V_47 ;
break;
case V_295 :
case V_310 :
return 0 ;
default:
return - V_140 ;
}
return F_150 ( V_299 , V_115 ) ;
}
static int F_153 ( struct V_298 * V_299 , struct V_311 * V_312 ,
unsigned V_313 , int V_314 )
{
return F_150 ( V_299 , V_47 ) ;
}
static int F_154 ( struct V_315 * V_316 )
{
struct V_284 * V_317 = & V_316 -> V_318 ;
struct V_1 * V_9 = F_22 () ;
V_317 -> V_100 = V_9 -> V_45 ;
return 0 ;
}
static void F_155 ( struct V_315 * V_316 )
{
struct V_284 * V_317 = & V_316 -> V_318 ;
V_317 -> V_100 = NULL ;
}
static char * F_156 ( struct V_315 * V_316 )
{
return ( char * ) V_316 -> V_318 . V_100 ;
}
static int F_157 ( struct V_315 * V_316 , int V_204 )
{
char * V_319 = F_156 ( V_316 ) ;
struct V_41 V_42 ;
#ifdef F_125
F_16 ( & V_42 , V_43 , V_285 ) ;
V_42 . V_239 . V_240 . V_286 = V_316 -> V_318 . V_287 ;
#endif
return F_18 ( V_319 , V_204 , & V_42 ) ;
}
static int F_158 ( struct V_315 * V_316 , int V_320 )
{
int V_115 ;
V_115 = F_137 ( V_320 ) ;
return F_157 ( V_316 , V_115 ) ;
}
static int F_159 ( struct V_315 * V_316 , int V_165 )
{
int V_115 ;
switch ( V_165 ) {
case V_289 :
case V_321 :
V_115 = V_87 ;
break;
case V_291 :
case V_294 :
V_115 = V_47 ;
break;
case V_295 :
case V_322 :
return 0 ;
default:
return - V_140 ;
}
return F_157 ( V_316 , V_115 ) ;
}
static int F_160 ( struct V_315 * V_316 , struct V_279 * V_280 ,
int V_320 )
{
int V_115 ;
V_115 = F_137 ( V_320 ) ;
return F_157 ( V_316 , V_115 ) ;
}
static int F_161 ( struct V_315 * V_316 , struct V_279 * V_280 ,
struct V_38 * V_323 , long type , int V_40 )
{
return F_157 ( V_316 , V_47 ) ;
}
static int F_162 ( struct V_284 * V_324 , short V_325 )
{
char * V_16 = V_324 -> V_100 ;
int V_115 = F_137 ( V_325 ) ;
struct V_41 V_42 ;
#ifdef F_125
F_16 ( & V_42 , V_43 , V_285 ) ;
V_42 . V_239 . V_240 . V_286 = V_324 -> V_287 ;
#endif
return F_18 ( V_16 , V_115 , & V_42 ) ;
}
static void F_163 ( struct V_284 * V_324 , T_3 * V_163 )
{
char * V_15 = V_324 -> V_100 ;
* V_163 = F_70 ( V_15 ) ;
}
static void F_164 ( struct V_5 * V_326 , struct V_3 * V_3 )
{
struct V_52 * V_84 ;
struct V_54 * V_55 ;
struct V_14 * V_16 ;
struct V_1 * V_9 ;
struct V_1 * V_327 = F_22 () ;
char * V_328 ;
char V_329 [ V_142 ] ;
int V_330 = 0 ;
int V_7 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return;
V_16 = V_3 -> V_82 ;
F_165 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_19 & V_269 )
goto V_331;
V_84 = V_3 -> V_152 ;
V_55 = V_84 -> V_61 ;
V_328 = V_55 -> V_57 ;
if ( V_326 -> V_332 == V_326 ) {
V_16 -> V_18 = V_55 -> V_56 ;
V_16 -> V_19 |= V_269 ;
goto V_331;
}
switch ( V_84 -> V_153 ) {
case V_333 :
V_328 = V_334 . V_45 ;
break;
case V_335 :
V_328 = V_334 . V_45 ;
break;
case V_336 :
V_328 = V_327 -> V_45 ;
break;
case V_154 :
V_328 = V_334 . V_45 ;
break;
case V_337 :
break;
case V_338 :
V_328 = V_334 . V_45 ;
default:
if ( F_166 ( V_3 -> V_339 ) ) {
V_328 = V_334 . V_45 ;
break;
}
if ( V_3 -> V_10 -> V_11 == NULL )
break;
V_6 = F_167 ( V_326 ) ;
V_9 = F_1 ( V_134 , V_3 , V_6 ) ;
if ( V_9 != NULL )
V_328 = V_9 -> V_45 ;
if ( F_168 ( V_3 -> V_339 ) ) {
if ( V_16 -> V_19 & V_118 ) {
V_16 -> V_19 &= ~ V_118 ;
V_7 = V_3 -> V_10 -> V_340 ( V_6 ,
V_141 ,
V_143 , V_142 ,
0 ) ;
} else {
V_7 = V_3 -> V_10 -> V_11 ( V_6 ,
V_141 , V_329 ,
V_142 ) ;
if ( V_7 >= 0 && strncmp ( V_329 , V_143 ,
V_142 ) != 0 )
V_7 = - V_140 ;
}
if ( V_7 >= 0 )
V_330 = V_83 ;
}
V_16 -> V_26 = F_1 ( V_137 , V_3 , V_6 ) ;
V_16 -> V_145 = F_1 ( V_138 , V_3 , V_6 ) ;
F_169 ( V_6 ) ;
break;
}
if ( V_328 == NULL )
V_16 -> V_18 = V_327 -> V_45 ;
else
V_16 -> V_18 = V_328 ;
V_16 -> V_19 |= ( V_269 | V_330 ) ;
V_331:
F_170 ( & V_16 -> V_20 ) ;
return;
}
static int F_171 ( struct V_38 * V_203 , char * V_2 , char * * V_111 )
{
struct V_1 * V_9 = F_14 ( F_15 ( V_203 ) ) ;
char * V_64 ;
int V_341 ;
if ( strcmp ( V_2 , L_3 ) != 0 )
return - V_140 ;
V_64 = F_51 ( V_9 -> V_45 , V_13 ) ;
if ( V_64 == NULL )
return - V_36 ;
V_341 = strlen ( V_64 ) ;
* V_111 = V_64 ;
return V_341 ;
}
static int F_172 ( struct V_38 * V_203 , char * V_2 ,
void * V_111 , T_2 V_133 )
{
struct V_21 * V_25 ;
struct V_99 * V_199 ;
struct V_1 * V_9 ;
if ( V_203 != V_106 )
return - V_103 ;
if ( ! F_23 ( V_139 ) )
return - V_103 ;
if ( V_111 == NULL || V_133 == 0 || V_133 >= V_12 )
return - V_140 ;
if ( strcmp ( V_2 , L_3 ) != 0 )
return - V_140 ;
V_9 = F_3 ( V_111 , V_133 ) ;
if ( V_9 == NULL )
return - V_140 ;
if ( V_9 == & V_265 )
return - V_103 ;
V_199 = F_173 () ;
if ( V_199 == NULL )
return - V_36 ;
V_25 = V_199 -> V_100 ;
V_25 -> V_26 = V_9 ;
F_174 ( V_199 ) ;
return V_133 ;
}
static int F_175 ( struct V_150 * V_150 ,
struct V_150 * V_342 , struct V_150 * V_343 )
{
struct V_1 * V_9 ;
struct V_147 * V_148 = V_150 -> V_157 ;
struct V_147 * V_344 = V_342 -> V_157 ;
struct V_147 * V_79 = V_343 -> V_157 ;
struct V_41 V_42 ;
int V_7 = 0 ;
#ifdef F_125
struct V_236 V_237 ;
F_126 ( & V_42 , V_43 , V_238 , & V_237 ) ;
F_176 ( & V_42 , V_342 ) ;
#endif
if ( ! F_23 ( V_49 ) ) {
V_9 = V_148 -> V_161 ;
V_7 = V_186 ( V_9 , V_344 -> V_159 , V_91 , & V_42 ) ;
}
if ( V_7 == 0 ) {
V_79 -> V_215 = V_148 -> V_161 -> V_45 ;
V_148 -> V_215 = V_344 -> V_161 -> V_45 ;
}
return V_7 ;
}
static int F_177 ( struct V_149 * V_150 , struct V_149 * V_342 )
{
struct V_147 * V_148 = V_150 -> V_156 -> V_157 ;
struct V_147 * V_344 = V_342 -> V_156 -> V_157 ;
struct V_1 * V_9 ;
struct V_41 V_42 ;
#ifdef F_125
struct V_236 V_237 ;
F_126 ( & V_42 , V_43 , V_238 , & V_237 ) ;
F_176 ( & V_42 , V_342 -> V_156 ) ;
#endif
if ( F_23 ( V_49 ) )
return 0 ;
V_9 = V_148 -> V_161 ;
return V_186 ( V_9 , V_344 -> V_159 , V_91 , & V_42 ) ;
}
static int F_178 ( struct V_149 * V_150 , struct V_345 * V_280 ,
int V_133 )
{
struct V_216 * V_217 = (struct V_216 * ) V_280 -> V_346 ;
struct V_249 * V_233 = (struct V_249 * ) V_280 -> V_346 ;
int V_7 = 0 ;
if ( V_217 == NULL )
return 0 ;
switch ( V_217 -> V_241 ) {
case V_347 :
V_7 = F_124 ( V_150 -> V_156 , V_217 ) ;
break;
case V_348 :
V_7 = F_131 ( V_150 -> V_156 , V_233 , V_349 ) ;
break;
}
return V_7 ;
}
static struct V_1 * F_179 ( struct V_350 * V_233 ,
struct V_147 * V_148 )
{
struct V_1 * V_9 ;
int V_351 = 0 ;
int V_352 ;
int V_353 ;
if ( ( V_233 -> V_72 & V_354 ) != 0 ) {
F_47 () ;
F_128 (skp, &smack_known_list, list) {
if ( V_233 -> V_355 . V_356 . V_357 != V_9 -> V_232 . V_355 . V_356 . V_357 )
continue;
if ( ( V_233 -> V_72 & V_358 ) == 0 ) {
if ( ( V_9 -> V_232 . V_72 &
V_358 ) == 0 )
V_351 = 1 ;
break;
}
for ( V_352 = - 1 , V_353 = - 1 ; V_352 == V_353 ; ) {
V_352 = F_180 (
V_233 -> V_355 . V_356 . V_359 , V_352 + 1 ) ;
V_353 = F_180 (
V_9 -> V_232 . V_355 . V_356 . V_359 ,
V_353 + 1 ) ;
if ( V_352 < 0 || V_353 < 0 )
break;
}
if ( V_352 == V_353 ) {
V_351 = 1 ;
break;
}
}
F_49 () ;
if ( V_351 )
return V_9 ;
if ( V_148 != NULL && V_148 -> V_159 == V_334 . V_45 )
return & V_265 ;
return & V_334 ;
}
if ( ( V_233 -> V_72 & V_360 ) != 0 ) {
V_9 = F_95 ( V_233 -> V_355 . V_163 ) ;
F_181 ( V_9 == NULL ) ;
return V_9 ;
}
return V_229 ;
}
static int F_182 ( struct V_361 * V_362 , struct V_249 * V_217 )
{
T_8 V_363 ;
int V_364 ;
int V_365 = - V_140 ;
struct V_366 V_367 ;
struct V_366 * V_368 ;
T_5 V_369 ;
struct V_370 V_371 , * V_372 ;
struct V_373 V_374 , * V_375 ;
struct V_376 V_377 , * V_378 ;
V_217 -> V_255 = 0 ;
V_364 = F_183 ( V_362 ) ;
V_368 = F_184 ( V_362 , V_364 , sizeof( V_367 ) , & V_367 ) ;
if ( V_368 == NULL )
return - V_140 ;
V_217 -> V_263 = V_368 -> V_268 ;
V_363 = V_368 -> V_363 ;
V_364 += sizeof( V_367 ) ;
V_364 = F_185 ( V_362 , V_364 , & V_363 , & V_369 ) ;
if ( V_364 < 0 )
return - V_140 ;
V_365 = V_363 ;
switch ( V_365 ) {
case V_379 :
V_372 = F_184 ( V_362 , V_364 , sizeof( V_371 ) , & V_371 ) ;
if ( V_372 != NULL )
V_217 -> V_255 = V_372 -> V_380 ;
break;
case V_381 :
V_375 = F_184 ( V_362 , V_364 , sizeof( V_374 ) , & V_374 ) ;
if ( V_375 != NULL )
V_217 -> V_255 = V_375 -> V_380 ;
break;
case V_382 :
V_378 = F_184 ( V_362 , V_364 , sizeof( V_377 ) , & V_377 ) ;
if ( V_378 != NULL )
V_217 -> V_255 = V_378 -> V_383 ;
break;
}
return V_365 ;
}
static int F_186 ( struct V_150 * V_156 , struct V_361 * V_362 )
{
struct V_350 V_384 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_1 * V_9 ;
struct V_249 V_385 ;
int V_7 = 0 ;
struct V_41 V_42 ;
#ifdef F_125
struct V_236 V_237 ;
#endif
switch ( V_156 -> V_231 ) {
case V_270 :
F_187 ( & V_384 ) ;
V_7 = F_188 ( V_362 , V_156 -> V_231 , & V_384 ) ;
if ( V_7 == 0 )
V_9 = F_179 ( & V_384 , V_148 ) ;
else
V_9 = V_229 ;
F_189 ( & V_384 ) ;
#ifdef F_125
F_126 ( & V_42 , V_43 , V_238 , & V_237 ) ;
V_42 . V_239 . V_240 . V_237 -> V_213 = V_156 -> V_231 ;
V_42 . V_239 . V_240 . V_237 -> V_386 = V_362 -> V_387 ;
F_190 ( V_362 , & V_42 . V_239 , NULL ) ;
#endif
V_7 = V_186 ( V_9 , V_148 -> V_159 , V_91 , & V_42 ) ;
if ( V_7 != 0 )
F_191 ( V_362 , V_7 , 0 ) ;
break;
case V_272 :
V_7 = F_182 ( V_362 , & V_385 ) ;
if ( V_7 == V_381 || V_7 == V_379 )
V_7 = F_131 ( V_156 , & V_385 , V_262 ) ;
else
V_7 = 0 ;
break;
}
return V_7 ;
}
static int F_192 ( struct V_149 * V_150 ,
char T_7 * V_388 ,
int T_7 * V_389 , unsigned V_112 )
{
struct V_147 * V_148 ;
char * V_390 = L_4 ;
int V_341 = 1 ;
int V_7 = 0 ;
V_148 = V_150 -> V_156 -> V_157 ;
if ( V_148 -> V_215 != NULL ) {
V_390 = V_148 -> V_215 ;
V_341 = strlen ( V_390 ) + 1 ;
}
if ( V_341 > V_112 )
V_7 = - V_391 ;
else if ( F_193 ( V_388 , V_390 , V_341 ) != 0 )
V_7 = - V_392 ;
if ( F_194 ( V_341 , V_389 ) != 0 )
V_7 = - V_392 ;
return V_7 ;
}
static int F_195 ( struct V_149 * V_150 ,
struct V_361 * V_362 , T_3 * V_163 )
{
struct V_350 V_384 ;
struct V_147 * V_148 = NULL ;
struct V_1 * V_9 ;
int V_213 = V_393 ;
T_3 V_394 = 0 ;
int V_7 ;
if ( V_362 != NULL ) {
if ( V_362 -> V_273 == F_196 ( V_395 ) )
V_213 = V_270 ;
else if ( V_362 -> V_273 == F_196 ( V_396 ) )
V_213 = V_272 ;
}
if ( V_213 == V_393 && V_150 != NULL )
V_213 = V_150 -> V_156 -> V_231 ;
if ( V_213 == V_397 ) {
V_148 = V_150 -> V_156 -> V_157 ;
V_394 = V_148 -> V_161 -> V_207 ;
} else if ( V_213 == V_270 || V_213 == V_272 ) {
if ( V_150 != NULL && V_150 -> V_156 != NULL )
V_148 = V_150 -> V_156 -> V_157 ;
F_187 ( & V_384 ) ;
V_7 = F_188 ( V_362 , V_213 , & V_384 ) ;
if ( V_7 == 0 ) {
V_9 = F_179 ( & V_384 , V_148 ) ;
V_394 = V_9 -> V_207 ;
}
F_189 ( & V_384 ) ;
}
* V_163 = V_394 ;
if ( V_394 == 0 )
return - V_140 ;
return 0 ;
}
static void F_197 ( struct V_150 * V_156 , struct V_149 * V_398 )
{
struct V_147 * V_148 ;
struct V_1 * V_9 = F_22 () ;
if ( V_156 == NULL ||
( V_156 -> V_231 != V_270 && V_156 -> V_231 != V_272 ) )
return;
V_148 = V_156 -> V_157 ;
V_148 -> V_159 = V_9 -> V_45 ;
V_148 -> V_161 = V_9 ;
}
static int F_198 ( struct V_150 * V_156 , struct V_361 * V_362 ,
struct V_399 * V_400 )
{
T_9 V_213 = V_156 -> V_231 ;
struct V_1 * V_9 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_350 V_384 ;
struct V_216 V_401 ;
struct V_402 * V_403 ;
char * V_404 ;
int V_7 ;
struct V_41 V_42 ;
#ifdef F_125
struct V_236 V_237 ;
#endif
if ( V_213 == V_272 ) {
if ( V_362 -> V_273 == F_196 ( V_395 ) )
V_213 = V_270 ;
else
return 0 ;
}
F_187 ( & V_384 ) ;
V_7 = F_188 ( V_362 , V_213 , & V_384 ) ;
if ( V_7 == 0 )
V_9 = F_179 ( & V_384 , V_148 ) ;
else
V_9 = & V_405 ;
F_189 ( & V_384 ) ;
#ifdef F_125
F_126 ( & V_42 , V_43 , V_238 , & V_237 ) ;
V_42 . V_239 . V_240 . V_237 -> V_213 = V_213 ;
V_42 . V_239 . V_240 . V_237 -> V_386 = V_362 -> V_387 ;
F_190 ( V_362 , & V_42 . V_239 , NULL ) ;
#endif
V_7 = V_186 ( V_9 , V_148 -> V_159 , V_91 , & V_42 ) ;
if ( V_7 != 0 )
return V_7 ;
V_400 -> V_406 = V_9 -> V_207 ;
V_403 = F_199 ( V_362 ) ;
V_401 . V_222 . V_223 = V_403 -> V_268 ;
F_47 () ;
V_404 = F_116 ( & V_401 ) ;
F_49 () ;
if ( V_404 == NULL )
V_7 = F_200 ( V_400 , & V_9 -> V_232 ) ;
else
F_201 ( V_400 ) ;
return V_7 ;
}
static void F_202 ( struct V_150 * V_156 ,
const struct V_399 * V_400 )
{
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_1 * V_9 ;
if ( V_400 -> V_406 != 0 ) {
V_9 = F_95 ( V_400 -> V_406 ) ;
V_148 -> V_215 = V_9 -> V_45 ;
} else
V_148 -> V_215 = NULL ;
}
static int F_203 ( struct V_407 * V_407 , const struct V_99 * V_99 ,
unsigned long V_72 )
{
struct V_1 * V_9 = F_14 ( V_99 -> V_100 ) ;
V_407 -> V_100 = V_9 -> V_45 ;
return 0 ;
}
static void F_204 ( struct V_407 * V_407 )
{
V_407 -> V_100 = NULL ;
}
static int F_205 ( T_10 V_408 ,
const struct V_99 * V_99 , T_11 V_409 )
{
struct V_407 * V_410 ;
struct V_41 V_42 ;
struct V_1 * V_191 = F_14 ( V_99 -> V_100 ) ;
V_410 = F_206 ( V_408 ) ;
if ( V_410 == NULL )
return - V_140 ;
if ( V_410 -> V_100 == NULL )
return 0 ;
if ( V_191 == NULL )
return - V_51 ;
#ifdef F_125
F_16 ( & V_42 , V_43 , V_411 ) ;
V_42 . V_239 . V_240 . V_412 . V_407 = V_410 -> V_413 ;
V_42 . V_239 . V_240 . V_412 . V_414 = V_410 -> V_415 ;
#endif
return V_186 ( V_191 , V_410 -> V_100 , V_47 , & V_42 ) ;
}
static int F_207 ( T_3 V_416 , T_3 V_78 , char * V_417 , void * * V_418 )
{
char * * V_419 = ( char * * ) V_418 ;
* V_419 = NULL ;
if ( V_416 != V_420 && V_416 != V_421 )
return - V_140 ;
if ( V_78 != V_422 && V_78 != V_423 )
return - V_140 ;
* V_419 = F_30 ( V_417 , 0 ) ;
return 0 ;
}
static int F_208 ( struct V_424 * V_425 )
{
struct V_426 * V_427 ;
int V_428 ;
for ( V_428 = 0 ; V_428 < V_425 -> V_429 ; V_428 ++ ) {
V_427 = & V_425 -> V_430 [ V_428 ] ;
if ( V_427 -> type == V_420 || V_427 -> type == V_421 )
return 1 ;
}
return 0 ;
}
static int F_209 ( T_3 V_163 , T_3 V_416 , T_3 V_78 , void * V_418 ,
struct V_431 * V_432 )
{
struct V_1 * V_9 ;
char * V_419 = V_418 ;
if ( ! V_419 ) {
F_210 ( V_432 , V_433 , V_434 ,
L_5 ) ;
return - V_185 ;
}
if ( V_416 != V_420 && V_416 != V_421 )
return 0 ;
V_9 = F_95 ( V_163 ) ;
if ( V_78 == V_422 )
return ( V_419 == V_9 -> V_45 ) ;
if ( V_78 == V_423 )
return ( V_419 != V_9 -> V_45 ) ;
return 0 ;
}
static void F_211 ( void * V_418 )
{
}
static int F_212 ( const char * V_2 )
{
return ( strcmp ( V_2 , V_116 ) == 0 ) ;
}
static int F_213 ( T_3 V_163 , char * * V_435 , T_3 * V_436 )
{
struct V_1 * V_9 = F_95 ( V_163 ) ;
if ( V_435 )
* V_435 = V_9 -> V_45 ;
* V_436 = strlen ( V_9 -> V_45 ) ;
return 0 ;
}
static int F_214 ( const char * V_435 , T_3 V_436 , T_3 * V_163 )
{
* V_163 = F_70 ( V_435 ) ;
return 0 ;
}
static void F_215 ( char * V_435 , T_3 V_436 )
{
}
static int F_216 ( struct V_3 * V_3 , void * V_437 , T_3 V_438 )
{
return F_132 ( V_3 , V_116 , V_437 , V_438 , 0 ) ;
}
static int F_217 ( struct V_5 * V_5 , void * V_437 , T_3 V_438 )
{
return F_218 ( V_5 , V_134 , V_437 , V_438 , 0 ) ;
}
static int F_219 ( struct V_3 * V_3 , void * * V_437 , T_3 * V_438 )
{
int V_112 = 0 ;
V_112 = F_66 ( V_3 , V_116 , V_437 , true ) ;
if ( V_112 < 0 )
return V_112 ;
* V_438 = V_112 ;
return 0 ;
}
static T_12 void F_220 ( void )
{
F_6 ( & V_405 . V_29 ) ;
F_6 ( & V_60 . V_29 ) ;
F_6 ( & V_50 . V_29 ) ;
F_6 ( & V_334 . V_29 ) ;
F_6 ( & V_144 . V_29 ) ;
F_6 ( & V_265 . V_29 ) ;
F_8 ( & V_405 . V_28 ) ;
F_8 ( & V_60 . V_28 ) ;
F_8 ( & V_334 . V_28 ) ;
F_8 ( & V_50 . V_28 ) ;
F_8 ( & V_144 . V_28 ) ;
F_8 ( & V_265 . V_28 ) ;
F_221 ( & V_405 ) ;
F_221 ( & V_60 ) ;
F_221 ( & V_334 ) ;
F_221 ( & V_50 ) ;
F_221 ( & V_144 ) ;
F_221 ( & V_265 ) ;
}
static T_12 int F_222 ( void )
{
struct V_99 * V_99 ;
struct V_21 * V_25 ;
if ( ! F_223 ( & V_439 ) )
return 0 ;
V_25 = F_7 ( & V_50 , & V_50 ,
V_13 ) ;
if ( V_25 == NULL )
return - V_36 ;
F_133 ( V_440 L_6 ) ;
V_99 = (struct V_99 * ) V_106 -> V_99 ;
V_99 -> V_100 = V_25 ;
F_220 () ;
if ( F_224 ( & V_439 ) )
F_225 ( L_7 ) ;
return 0 ;
}

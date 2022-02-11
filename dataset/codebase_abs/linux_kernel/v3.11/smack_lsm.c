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
V_7 = F_18 ( V_9 -> V_45 , V_46 , & V_42 ) ;
return V_7 ;
}
static int F_19 ( struct V_38 * V_47 )
{
int V_7 ;
struct V_41 V_42 ;
struct V_1 * V_9 ;
V_7 = F_20 ( V_47 ) ;
if ( V_7 != 0 )
return V_7 ;
V_9 = F_14 ( F_15 ( V_47 ) ) ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_17 ( & V_42 , V_47 ) ;
V_7 = F_18 ( V_9 -> V_45 , V_46 , & V_42 ) ;
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
const struct V_110 * V_110 , char * * V_2 ,
void * * V_111 , T_2 * V_112 )
{
struct V_14 * V_113 = V_3 -> V_82 ;
struct V_1 * V_9 = F_22 () ;
char * V_16 = F_46 ( V_3 ) ;
char * V_114 = F_46 ( V_109 ) ;
int V_115 ;
if ( V_2 ) {
* V_2 = F_47 ( V_116 , V_17 ) ;
if ( * V_2 == NULL )
return - V_36 ;
}
if ( V_111 ) {
F_48 () ;
V_115 = F_49 ( V_9 -> V_45 , V_114 , & V_9 -> V_28 ) ;
F_50 () ;
if ( V_115 > 0 && ( ( V_115 & V_117 ) != 0 ) &&
F_51 ( V_109 ) ) {
V_16 = V_114 ;
V_113 -> V_19 |= V_118 ;
}
* V_111 = F_47 ( V_16 , V_17 ) ;
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
V_7 = F_18 ( V_16 , V_46 , & V_42 ) ;
if ( V_7 == 0 && V_120 -> V_76 != NULL ) {
V_16 = F_46 ( V_120 -> V_76 ) ;
F_32 ( & V_42 , V_120 ) ;
V_7 = F_18 ( V_16 , V_46 , & V_42 ) ;
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
return F_18 ( V_97 -> V_164 , V_91 , & V_42 ) ;
}
static int F_77 ( struct V_97 * V_97 , unsigned int V_165 ,
unsigned long V_166 )
{
struct V_41 V_42 ;
int V_7 = 0 ;
switch ( V_165 ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
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
unsigned long V_175 , unsigned long V_176 ,
unsigned long V_72 )
{
struct V_1 * V_9 ;
struct V_1 * V_177 ;
struct V_33 * V_178 ;
struct V_21 * V_25 ;
char * V_179 ;
struct V_14 * V_16 ;
int V_115 ;
int V_180 ;
int V_181 ;
int V_7 ;
if ( V_97 == NULL )
return 0 ;
V_16 = F_37 ( V_97 ) -> V_82 ;
if ( V_16 -> V_145 == NULL )
return 0 ;
V_177 = V_16 -> V_145 ;
V_25 = F_41 () ;
V_9 = F_22 () ;
V_7 = 0 ;
F_48 () ;
F_10 (srp, &skp->smk_rules, list) {
V_179 = V_178 -> V_182 ;
if ( V_177 -> V_45 == V_179 )
continue;
V_115 = F_49 ( V_178 -> V_183 -> V_45 , V_179 ,
& V_25 -> V_28 ) ;
if ( V_115 == - V_184 )
V_115 = V_178 -> V_185 ;
else
V_115 &= V_178 -> V_185 ;
if ( V_115 == 0 )
continue;
V_180 = F_49 ( V_177 -> V_45 , V_179 ,
& V_177 -> V_28 ) ;
if ( V_180 == - V_184 ) {
V_7 = - V_51 ;
break;
}
V_181 = F_49 ( V_177 -> V_45 , V_179 ,
& V_25 -> V_28 ) ;
if ( V_181 != - V_184 )
V_180 &= V_181 ;
if ( ( V_115 | V_180 ) != V_180 ) {
V_7 = - V_51 ;
break;
}
}
F_50 () ;
return V_7 ;
}
static int F_79 ( struct V_97 * V_97 )
{
struct V_1 * V_9 = F_22 () ;
V_97 -> V_164 = V_9 -> V_45 ;
return 0 ;
}
static int F_80 ( struct V_38 * V_186 ,
struct V_187 * V_188 , int V_189 )
{
struct V_1 * V_9 ;
struct V_1 * V_190 = F_14 ( V_186 -> V_99 -> V_100 ) ;
struct V_97 * V_97 ;
int V_7 ;
struct V_41 V_42 ;
V_97 = F_81 ( V_188 , struct V_97 , V_191 ) ;
V_9 = F_82 ( V_97 -> V_164 ) ;
V_7 = V_185 ( V_9 , V_190 -> V_45 , V_91 , NULL ) ;
if ( V_7 != 0 && F_83 ( V_186 , V_49 ) )
V_7 = 0 ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_17 ( & V_42 , V_186 ) ;
F_84 ( V_97 -> V_164 , V_190 -> V_45 , V_91 , V_7 , & V_42 ) ;
return V_7 ;
}
static int F_85 ( struct V_97 * V_97 )
{
int V_115 = 0 ;
struct V_41 V_42 ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_34 ( & V_42 , V_97 -> V_167 ) ;
if ( V_97 -> V_192 & V_193 )
V_115 = V_87 ;
if ( V_97 -> V_192 & V_194 )
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
struct V_33 * V_195 ;
struct V_30 * V_196 ;
struct V_30 * V_197 ;
if ( V_25 == NULL )
return;
V_99 -> V_100 = NULL ;
F_89 (l, n, &tsp->smk_rules) {
V_195 = F_90 ( V_196 , struct V_33 , V_37 ) ;
F_91 ( & V_195 -> V_37 ) ;
F_4 ( V_195 ) ;
}
F_4 ( V_25 ) ;
}
static int F_92 ( struct V_99 * V_198 , const struct V_99 * V_199 ,
T_1 V_24 )
{
struct V_21 * V_200 = V_199 -> V_100 ;
struct V_21 * V_201 ;
int V_7 ;
V_201 = F_7 ( V_200 -> V_26 , V_200 -> V_26 , V_24 ) ;
if ( V_201 == NULL )
return - V_36 ;
V_7 = F_9 ( & V_201 -> V_28 , & V_200 -> V_28 , V_24 ) ;
if ( V_7 != 0 )
return V_7 ;
V_198 -> V_100 = V_201 ;
return 0 ;
}
static void F_93 ( struct V_99 * V_198 , const struct V_99 * V_199 )
{
struct V_21 * V_200 = V_199 -> V_100 ;
struct V_21 * V_201 = V_198 -> V_100 ;
V_201 -> V_26 = V_200 -> V_26 ;
V_201 -> V_27 = V_200 -> V_26 ;
F_6 ( & V_201 -> V_29 ) ;
F_8 ( & V_201 -> V_28 ) ;
}
static int F_94 ( struct V_99 * V_198 , T_3 V_163 )
{
struct V_21 * V_201 = V_198 -> V_100 ;
struct V_1 * V_9 = F_95 ( V_163 ) ;
if ( V_9 == NULL )
return - V_140 ;
V_201 -> V_26 = V_9 ;
return 0 ;
}
static int F_96 ( struct V_99 * V_198 ,
struct V_3 * V_3 )
{
struct V_14 * V_16 = V_3 -> V_82 ;
struct V_21 * V_25 = V_198 -> V_100 ;
V_25 -> V_27 = F_82 ( V_16 -> V_18 ) ;
V_25 -> V_26 = V_25 -> V_27 ;
return 0 ;
}
static int F_97 ( struct V_38 * V_202 , int V_203 ,
const char * V_204 )
{
struct V_41 V_42 ;
struct V_1 * V_9 = F_14 ( F_15 ( V_202 ) ) ;
F_16 ( & V_42 , V_204 , V_44 ) ;
F_17 ( & V_42 , V_202 ) ;
return F_18 ( V_9 -> V_45 , V_203 , & V_42 ) ;
}
static int F_98 ( struct V_38 * V_202 , T_4 V_205 )
{
return F_97 ( V_202 , V_91 , V_43 ) ;
}
static int F_99 ( struct V_38 * V_202 )
{
return F_97 ( V_202 , V_87 , V_43 ) ;
}
static int F_100 ( struct V_38 * V_202 )
{
return F_97 ( V_202 , V_87 , V_43 ) ;
}
static void F_101 ( struct V_38 * V_202 , T_3 * V_163 )
{
struct V_1 * V_9 = F_14 ( F_15 ( V_202 ) ) ;
* V_163 = V_9 -> V_206 ;
}
static int F_102 ( struct V_38 * V_202 , int V_207 )
{
int V_7 ;
V_7 = F_103 ( V_202 , V_207 ) ;
if ( V_7 == 0 )
V_7 = F_97 ( V_202 , V_91 , V_43 ) ;
return V_7 ;
}
static int F_104 ( struct V_38 * V_202 , int V_208 )
{
int V_7 ;
V_7 = F_105 ( V_202 , V_208 ) ;
if ( V_7 == 0 )
V_7 = F_97 ( V_202 , V_91 , V_43 ) ;
return V_7 ;
}
static int F_106 ( struct V_38 * V_202 )
{
return F_97 ( V_202 , V_87 , V_43 ) ;
}
static int F_107 ( struct V_38 * V_202 )
{
int V_7 ;
V_7 = F_108 ( V_202 ) ;
if ( V_7 == 0 )
V_7 = F_97 ( V_202 , V_91 , V_43 ) ;
return V_7 ;
}
static int F_109 ( struct V_38 * V_202 )
{
return F_97 ( V_202 , V_87 , V_43 ) ;
}
static int F_110 ( struct V_38 * V_202 )
{
return F_97 ( V_202 , V_91 , V_43 ) ;
}
static int F_111 ( struct V_38 * V_202 , struct V_209 * V_210 ,
int V_211 , T_3 V_163 )
{
struct V_41 V_42 ;
struct V_1 * V_9 ;
struct V_1 * V_190 = F_14 ( F_15 ( V_202 ) ) ;
F_16 ( & V_42 , V_43 , V_44 ) ;
F_17 ( & V_42 , V_202 ) ;
if ( V_163 == 0 )
return F_18 ( V_190 -> V_45 , V_91 , & V_42 ) ;
V_9 = F_95 ( V_163 ) ;
return V_185 ( V_9 , V_190 -> V_45 , V_91 , & V_42 ) ;
}
static int F_112 ( struct V_38 * V_202 )
{
return 0 ;
}
static void F_113 ( struct V_38 * V_202 , struct V_3 * V_3 )
{
struct V_14 * V_16 = V_3 -> V_82 ;
struct V_1 * V_9 = F_14 ( F_15 ( V_202 ) ) ;
V_16 -> V_18 = V_9 -> V_45 ;
}
static int F_114 ( struct V_150 * V_156 , int V_212 , T_1 V_213 )
{
struct V_1 * V_9 = F_22 () ;
struct V_147 * V_148 ;
V_148 = F_2 ( sizeof( struct V_147 ) , V_213 ) ;
if ( V_148 == NULL )
return - V_36 ;
V_148 -> V_159 = V_9 -> V_45 ;
V_148 -> V_161 = V_9 ;
V_148 -> V_214 = NULL ;
V_156 -> V_157 = V_148 ;
return 0 ;
}
static void F_115 ( struct V_150 * V_156 )
{
F_4 ( V_156 -> V_157 ) ;
}
static char * F_116 ( struct V_215 * V_216 )
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
static int F_117 ( struct V_150 * V_156 , int V_227 )
{
struct V_1 * V_9 ;
struct V_147 * V_148 = V_156 -> V_157 ;
int V_7 = 0 ;
F_118 () ;
F_119 ( V_156 ) ;
if ( V_148 -> V_161 == V_228 ||
V_227 == V_229 )
F_120 ( V_156 ) ;
else {
V_9 = V_148 -> V_161 ;
V_7 = F_121 ( V_156 , V_156 -> V_230 , & V_9 -> V_231 ) ;
}
F_122 ( V_156 ) ;
F_123 () ;
return V_7 ;
}
static int F_124 ( struct V_150 * V_156 , struct V_215 * V_232 )
{
struct V_1 * V_9 ;
int V_7 ;
int V_233 ;
char * V_234 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_41 V_42 ;
F_48 () ;
V_234 = F_116 ( V_232 ) ;
if ( V_234 != NULL ) {
#ifdef F_125
struct V_235 V_236 ;
F_126 ( & V_42 , V_43 , V_237 , & V_236 ) ;
V_42 . V_238 . V_239 . V_236 -> V_212 = V_232 -> V_240 ;
V_42 . V_238 . V_239 . V_236 -> V_241 = V_232 -> V_242 ;
V_42 . V_238 . V_239 . V_236 -> V_243 . V_244 = V_232 -> V_221 . V_222 ;
#endif
V_233 = V_229 ;
V_9 = V_148 -> V_161 ;
V_7 = V_185 ( V_9 , V_234 , V_91 , & V_42 ) ;
} else {
V_233 = V_245 ;
V_7 = 0 ;
}
F_50 () ;
if ( V_7 != 0 )
return V_7 ;
return F_117 ( V_156 , V_233 ) ;
}
static void F_127 ( struct V_149 * V_150 , struct V_246 * V_247 )
{
struct V_150 * V_156 = V_150 -> V_156 ;
struct V_248 * V_249 ;
struct V_147 * V_148 = V_150 -> V_156 -> V_157 ;
struct V_250 * V_251 ;
unsigned short V_252 = 0 ;
if ( V_247 == NULL ) {
F_128 (spp, &smk_ipv6_port_list, list) {
if ( V_156 != V_251 -> V_253 )
continue;
V_251 -> V_159 = V_148 -> V_159 ;
V_251 -> V_161 = V_148 -> V_161 ;
return;
}
return;
}
V_249 = (struct V_248 * ) V_247 ;
V_252 = F_129 ( V_249 -> V_254 ) ;
if ( V_252 == 0 )
return;
F_128 (spp, &smk_ipv6_port_list, list) {
if ( V_251 -> V_255 != V_252 )
continue;
V_251 -> V_255 = V_252 ;
V_251 -> V_253 = V_156 ;
V_251 -> V_159 = V_148 -> V_159 ;
V_251 -> V_161 = V_148 -> V_161 ;
return;
}
V_251 = F_2 ( sizeof( * V_251 ) , V_13 ) ;
if ( V_251 == NULL )
return;
V_251 -> V_255 = V_252 ;
V_251 -> V_253 = V_156 ;
V_251 -> V_159 = V_148 -> V_159 ;
V_251 -> V_161 = V_148 -> V_161 ;
F_130 ( & V_251 -> V_37 , & V_256 ) ;
return;
}
static int F_131 ( struct V_150 * V_156 , struct V_248 * V_247 ,
int V_257 )
{
T_5 * V_258 ;
T_6 * V_259 ;
struct V_250 * V_251 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_1 * V_9 ;
unsigned short V_252 = 0 ;
char * V_260 ;
struct V_41 V_42 ;
#ifdef F_125
struct V_235 V_236 ;
#endif
if ( V_257 == V_261 ) {
V_9 = V_228 ;
V_260 = V_148 -> V_159 ;
} else {
V_9 = V_148 -> V_161 ;
V_260 = V_228 -> V_45 ;
}
V_252 = F_129 ( V_247 -> V_254 ) ;
V_258 = ( T_5 * ) ( & V_247 -> V_262 ) ;
V_259 = ( T_6 * ) ( & V_247 -> V_262 ) ;
if ( V_259 [ 0 ] || V_259 [ 1 ] || V_259 [ 2 ] || V_258 [ 6 ] || F_129 ( V_258 [ 7 ] ) != 1 )
goto V_263;
if ( V_257 == V_261 ) {
V_9 = & V_264 ;
goto V_263;
}
F_128 (spp, &smk_ipv6_port_list, list) {
if ( V_251 -> V_255 != V_252 )
continue;
V_260 = V_251 -> V_159 ;
if ( V_257 == V_265 )
V_148 -> V_214 = V_251 -> V_161 -> V_45 ;
break;
}
V_263:
#ifdef F_125
F_126 ( & V_42 , V_43 , V_237 , & V_236 ) ;
V_42 . V_238 . V_239 . V_236 -> V_212 = V_156 -> V_230 ;
V_42 . V_238 . V_239 . V_236 -> V_241 = V_252 ;
if ( V_257 == V_261 )
V_42 . V_238 . V_239 . V_236 -> V_266 . V_267 = V_247 -> V_262 ;
else
V_42 . V_238 . V_239 . V_236 -> V_266 . V_244 = V_247 -> V_262 ;
#endif
return V_185 ( V_9 , V_260 , V_91 , & V_42 ) ;
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
V_79 -> V_19 |= V_268 ;
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
if ( V_150 -> V_156 -> V_230 == V_269 ) {
V_7 = F_117 ( V_150 -> V_156 , V_245 ) ;
if ( V_7 != 0 )
F_133 ( V_270
L_2 ,
V_43 , - V_7 ) ;
}
} else
return - V_155 ;
if ( V_150 -> V_156 -> V_230 == V_271 )
F_127 ( V_150 , NULL ) ;
return 0 ;
}
static int F_134 ( struct V_149 * V_150 , int V_212 ,
int type , int V_272 , int V_273 )
{
if ( V_212 != V_269 || V_150 -> V_156 == NULL )
return 0 ;
return F_117 ( V_150 -> V_156 , V_245 ) ;
}
static int F_135 ( struct V_149 * V_150 , struct V_246 * V_247 ,
int V_274 )
{
if ( V_150 -> V_156 != NULL && V_150 -> V_156 -> V_230 == V_271 )
F_127 ( V_150 , V_247 ) ;
return 0 ;
}
static int F_136 ( struct V_149 * V_150 , struct V_246 * V_232 ,
int V_274 )
{
int V_7 = 0 ;
if ( V_150 -> V_156 == NULL )
return 0 ;
switch ( V_150 -> V_156 -> V_230 ) {
case V_269 :
if ( V_274 < sizeof( struct V_215 ) )
return - V_140 ;
V_7 = F_124 ( V_150 -> V_156 , (struct V_215 * ) V_232 ) ;
break;
case V_271 :
if ( V_274 < sizeof( struct V_248 ) )
return - V_140 ;
V_7 = F_131 ( V_150 -> V_156 , (struct V_248 * ) V_232 ,
V_265 ) ;
break;
}
return V_7 ;
}
static int F_137 ( int V_72 )
{
int V_115 = 0 ;
if ( V_72 & V_275 )
V_115 |= V_87 ;
if ( V_72 & V_276 )
V_115 |= V_91 ;
if ( V_72 & V_277 )
V_115 |= V_127 ;
return V_115 ;
}
static int F_138 ( struct V_278 * V_279 )
{
struct V_1 * V_9 = F_22 () ;
V_279 -> V_100 = V_9 -> V_45 ;
return 0 ;
}
static void F_139 ( struct V_278 * V_279 )
{
V_279 -> V_100 = NULL ;
}
static char * F_140 ( struct V_280 * V_281 )
{
return ( char * ) V_281 -> V_282 . V_100 ;
}
static int F_141 ( struct V_280 * V_281 )
{
struct V_283 * V_16 = & V_281 -> V_282 ;
struct V_1 * V_9 = F_22 () ;
V_16 -> V_100 = V_9 -> V_45 ;
return 0 ;
}
static void F_142 ( struct V_280 * V_281 )
{
struct V_283 * V_16 = & V_281 -> V_282 ;
V_16 -> V_100 = NULL ;
}
static int F_143 ( struct V_280 * V_281 , int V_203 )
{
char * V_148 = F_140 ( V_281 ) ;
struct V_41 V_42 ;
#ifdef F_125
F_16 ( & V_42 , V_43 , V_284 ) ;
V_42 . V_238 . V_239 . V_285 = V_281 -> V_282 . V_286 ;
#endif
return F_18 ( V_148 , V_203 , & V_42 ) ;
}
static int F_144 ( struct V_280 * V_281 , int V_287 )
{
int V_115 ;
V_115 = F_137 ( V_287 ) ;
return F_143 ( V_281 , V_115 ) ;
}
static int F_145 ( struct V_280 * V_281 , int V_165 )
{
int V_115 ;
switch ( V_165 ) {
case V_288 :
case V_289 :
V_115 = V_87 ;
break;
case V_290 :
case V_291 :
case V_292 :
case V_293 :
V_115 = V_46 ;
break;
case V_294 :
case V_295 :
return 0 ;
default:
return - V_140 ;
}
return F_143 ( V_281 , V_115 ) ;
}
static int F_146 ( struct V_280 * V_281 , char T_7 * V_296 ,
int V_287 )
{
int V_115 ;
V_115 = F_137 ( V_287 ) ;
return F_143 ( V_281 , V_115 ) ;
}
static char * F_147 ( struct V_297 * V_298 )
{
return ( char * ) V_298 -> V_299 . V_100 ;
}
static int F_148 ( struct V_297 * V_298 )
{
struct V_283 * V_16 = & V_298 -> V_299 ;
struct V_1 * V_9 = F_22 () ;
V_16 -> V_100 = V_9 -> V_45 ;
return 0 ;
}
static void F_149 ( struct V_297 * V_298 )
{
struct V_283 * V_16 = & V_298 -> V_299 ;
V_16 -> V_100 = NULL ;
}
static int F_150 ( struct V_297 * V_298 , int V_203 )
{
char * V_148 = F_147 ( V_298 ) ;
struct V_41 V_42 ;
#ifdef F_125
F_16 ( & V_42 , V_43 , V_284 ) ;
V_42 . V_238 . V_239 . V_285 = V_298 -> V_299 . V_286 ;
#endif
return F_18 ( V_148 , V_203 , & V_42 ) ;
}
static int F_151 ( struct V_297 * V_298 , int V_300 )
{
int V_115 ;
V_115 = F_137 ( V_300 ) ;
return F_150 ( V_298 , V_115 ) ;
}
static int F_152 ( struct V_297 * V_298 , int V_165 )
{
int V_115 ;
switch ( V_165 ) {
case V_301 :
case V_302 :
case V_303 :
case V_304 :
case V_305 :
case V_288 :
case V_306 :
V_115 = V_87 ;
break;
case V_307 :
case V_308 :
case V_293 :
case V_290 :
V_115 = V_46 ;
break;
case V_294 :
case V_309 :
return 0 ;
default:
return - V_140 ;
}
return F_150 ( V_298 , V_115 ) ;
}
static int F_153 ( struct V_297 * V_298 , struct V_310 * V_311 ,
unsigned V_312 , int V_313 )
{
return F_150 ( V_298 , V_46 ) ;
}
static int F_154 ( struct V_314 * V_315 )
{
struct V_283 * V_316 = & V_315 -> V_317 ;
struct V_1 * V_9 = F_22 () ;
V_316 -> V_100 = V_9 -> V_45 ;
return 0 ;
}
static void F_155 ( struct V_314 * V_315 )
{
struct V_283 * V_316 = & V_315 -> V_317 ;
V_316 -> V_100 = NULL ;
}
static char * F_156 ( struct V_314 * V_315 )
{
return ( char * ) V_315 -> V_317 . V_100 ;
}
static int F_157 ( struct V_314 * V_315 , int V_203 )
{
char * V_318 = F_156 ( V_315 ) ;
struct V_41 V_42 ;
#ifdef F_125
F_16 ( & V_42 , V_43 , V_284 ) ;
V_42 . V_238 . V_239 . V_285 = V_315 -> V_317 . V_286 ;
#endif
return F_18 ( V_318 , V_203 , & V_42 ) ;
}
static int F_158 ( struct V_314 * V_315 , int V_319 )
{
int V_115 ;
V_115 = F_137 ( V_319 ) ;
return F_157 ( V_315 , V_115 ) ;
}
static int F_159 ( struct V_314 * V_315 , int V_165 )
{
int V_115 ;
switch ( V_165 ) {
case V_288 :
case V_320 :
V_115 = V_87 ;
break;
case V_290 :
case V_293 :
V_115 = V_46 ;
break;
case V_294 :
case V_321 :
return 0 ;
default:
return - V_140 ;
}
return F_157 ( V_315 , V_115 ) ;
}
static int F_160 ( struct V_314 * V_315 , struct V_278 * V_279 ,
int V_319 )
{
int V_115 ;
V_115 = F_137 ( V_319 ) ;
return F_157 ( V_315 , V_115 ) ;
}
static int F_161 ( struct V_314 * V_315 , struct V_278 * V_279 ,
struct V_38 * V_322 , long type , int V_40 )
{
return F_157 ( V_315 , V_46 ) ;
}
static int F_162 ( struct V_283 * V_323 , short V_324 )
{
char * V_16 = V_323 -> V_100 ;
int V_115 = F_137 ( V_324 ) ;
struct V_41 V_42 ;
#ifdef F_125
F_16 ( & V_42 , V_43 , V_284 ) ;
V_42 . V_238 . V_239 . V_285 = V_323 -> V_286 ;
#endif
return F_18 ( V_16 , V_115 , & V_42 ) ;
}
static void F_163 ( struct V_283 * V_323 , T_3 * V_163 )
{
char * V_15 = V_323 -> V_100 ;
* V_163 = F_70 ( V_15 ) ;
}
static void F_164 ( struct V_5 * V_325 , struct V_3 * V_3 )
{
struct V_52 * V_84 ;
struct V_54 * V_55 ;
struct V_14 * V_16 ;
struct V_1 * V_9 ;
struct V_1 * V_326 = F_22 () ;
char * V_327 ;
char V_328 [ V_142 ] ;
int V_329 = 0 ;
int V_7 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return;
V_16 = V_3 -> V_82 ;
F_165 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_19 & V_268 )
goto V_330;
V_84 = V_3 -> V_152 ;
V_55 = V_84 -> V_61 ;
V_327 = V_55 -> V_57 ;
if ( V_325 -> V_331 == V_325 ) {
V_16 -> V_18 = V_55 -> V_56 ;
V_16 -> V_19 |= V_268 ;
goto V_330;
}
switch ( V_84 -> V_153 ) {
case V_332 :
V_327 = V_333 . V_45 ;
break;
case V_334 :
V_327 = V_333 . V_45 ;
break;
case V_335 :
V_327 = V_326 -> V_45 ;
break;
case V_154 :
V_327 = V_333 . V_45 ;
break;
case V_336 :
break;
case V_337 :
V_327 = V_333 . V_45 ;
default:
if ( F_166 ( V_3 -> V_338 ) ) {
V_327 = V_333 . V_45 ;
break;
}
if ( V_3 -> V_10 -> V_11 == NULL )
break;
V_6 = F_167 ( V_325 ) ;
V_9 = F_1 ( V_134 , V_3 , V_6 ) ;
if ( V_9 != NULL )
V_327 = V_9 -> V_45 ;
if ( F_168 ( V_3 -> V_338 ) ) {
if ( V_16 -> V_19 & V_118 ) {
V_16 -> V_19 &= ~ V_118 ;
V_7 = V_3 -> V_10 -> V_339 ( V_6 ,
V_141 ,
V_143 , V_142 ,
0 ) ;
} else {
V_7 = V_3 -> V_10 -> V_11 ( V_6 ,
V_141 , V_328 ,
V_142 ) ;
if ( V_7 >= 0 && strncmp ( V_328 , V_143 ,
V_142 ) != 0 )
V_7 = - V_140 ;
}
if ( V_7 >= 0 )
V_329 = V_83 ;
}
V_16 -> V_26 = F_1 ( V_137 , V_3 , V_6 ) ;
V_16 -> V_145 = F_1 ( V_138 , V_3 , V_6 ) ;
F_169 ( V_6 ) ;
break;
}
if ( V_327 == NULL )
V_16 -> V_18 = V_326 -> V_45 ;
else
V_16 -> V_18 = V_327 ;
V_16 -> V_19 |= ( V_268 | V_329 ) ;
V_330:
F_170 ( & V_16 -> V_20 ) ;
return;
}
static int F_171 ( struct V_38 * V_202 , char * V_2 , char * * V_111 )
{
struct V_1 * V_9 = F_14 ( F_15 ( V_202 ) ) ;
char * V_64 ;
int V_340 ;
if ( strcmp ( V_2 , L_3 ) != 0 )
return - V_140 ;
V_64 = F_47 ( V_9 -> V_45 , V_13 ) ;
if ( V_64 == NULL )
return - V_36 ;
V_340 = strlen ( V_64 ) ;
* V_111 = V_64 ;
return V_340 ;
}
static int F_172 ( struct V_38 * V_202 , char * V_2 ,
void * V_111 , T_2 V_133 )
{
struct V_21 * V_25 ;
struct V_99 * V_198 ;
struct V_1 * V_9 ;
if ( V_202 != V_106 )
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
if ( V_9 == & V_264 )
return - V_103 ;
V_198 = F_173 () ;
if ( V_198 == NULL )
return - V_36 ;
V_25 = V_198 -> V_100 ;
V_25 -> V_26 = V_9 ;
F_174 ( V_198 ) ;
return V_133 ;
}
static int F_175 ( struct V_150 * V_150 ,
struct V_150 * V_341 , struct V_150 * V_342 )
{
struct V_1 * V_9 ;
struct V_147 * V_148 = V_150 -> V_157 ;
struct V_147 * V_343 = V_341 -> V_157 ;
struct V_147 * V_79 = V_342 -> V_157 ;
struct V_41 V_42 ;
int V_7 = 0 ;
#ifdef F_125
struct V_235 V_236 ;
F_126 ( & V_42 , V_43 , V_237 , & V_236 ) ;
F_176 ( & V_42 , V_341 ) ;
#endif
if ( ! F_23 ( V_49 ) ) {
V_9 = V_148 -> V_161 ;
V_7 = V_185 ( V_9 , V_343 -> V_159 , V_91 , & V_42 ) ;
}
if ( V_7 == 0 ) {
V_79 -> V_214 = V_148 -> V_161 -> V_45 ;
V_148 -> V_214 = V_343 -> V_161 -> V_45 ;
}
return V_7 ;
}
static int F_177 ( struct V_149 * V_150 , struct V_149 * V_341 )
{
struct V_147 * V_148 = V_150 -> V_156 -> V_157 ;
struct V_147 * V_343 = V_341 -> V_156 -> V_157 ;
struct V_1 * V_9 ;
struct V_41 V_42 ;
#ifdef F_125
struct V_235 V_236 ;
F_126 ( & V_42 , V_43 , V_237 , & V_236 ) ;
F_176 ( & V_42 , V_341 -> V_156 ) ;
#endif
if ( F_23 ( V_49 ) )
return 0 ;
V_9 = V_148 -> V_161 ;
return V_185 ( V_9 , V_343 -> V_159 , V_91 , & V_42 ) ;
}
static int F_178 ( struct V_149 * V_150 , struct V_344 * V_279 ,
int V_133 )
{
struct V_215 * V_216 = (struct V_215 * ) V_279 -> V_345 ;
struct V_248 * V_232 = (struct V_248 * ) V_279 -> V_345 ;
int V_7 = 0 ;
if ( V_216 == NULL )
return 0 ;
switch ( V_216 -> V_240 ) {
case V_346 :
V_7 = F_124 ( V_150 -> V_156 , V_216 ) ;
break;
case V_347 :
V_7 = F_131 ( V_150 -> V_156 , V_232 , V_348 ) ;
break;
}
return V_7 ;
}
static struct V_1 * F_179 ( struct V_349 * V_232 ,
struct V_147 * V_148 )
{
struct V_1 * V_9 ;
int V_350 = 0 ;
if ( ( V_232 -> V_72 & V_351 ) != 0 ) {
F_48 () ;
F_128 (skp, &smack_known_list, list) {
if ( V_232 -> V_352 . V_353 . V_354 != V_9 -> V_231 . V_352 . V_353 . V_354 )
continue;
if ( memcmp ( V_232 -> V_352 . V_353 . V_355 ,
V_9 -> V_231 . V_352 . V_353 . V_355 ,
V_356 ) != 0 )
continue;
V_350 = 1 ;
break;
}
F_50 () ;
if ( V_350 )
return V_9 ;
if ( V_148 != NULL && V_148 -> V_159 == V_333 . V_45 )
return & V_264 ;
return & V_333 ;
}
if ( ( V_232 -> V_72 & V_357 ) != 0 ) {
V_9 = F_95 ( V_232 -> V_352 . V_163 ) ;
F_180 ( V_9 == NULL ) ;
return V_9 ;
}
return V_228 ;
}
static int F_181 ( struct V_358 * V_359 , struct V_248 * V_216 )
{
T_8 V_360 ;
int V_361 ;
int V_362 = - V_140 ;
struct V_363 V_364 ;
struct V_363 * V_365 ;
T_5 V_366 ;
struct V_367 V_368 , * V_369 ;
struct V_370 V_371 , * V_372 ;
struct V_373 V_374 , * V_375 ;
V_216 -> V_254 = 0 ;
V_361 = F_182 ( V_359 ) ;
V_365 = F_183 ( V_359 , V_361 , sizeof( V_364 ) , & V_364 ) ;
if ( V_365 == NULL )
return - V_140 ;
V_216 -> V_262 = V_365 -> V_267 ;
V_360 = V_365 -> V_360 ;
V_361 += sizeof( V_364 ) ;
V_361 = F_184 ( V_359 , V_361 , & V_360 , & V_366 ) ;
if ( V_361 < 0 )
return - V_140 ;
V_362 = V_360 ;
switch ( V_362 ) {
case V_376 :
V_369 = F_183 ( V_359 , V_361 , sizeof( V_368 ) , & V_368 ) ;
if ( V_369 != NULL )
V_216 -> V_254 = V_369 -> V_377 ;
break;
case V_378 :
V_372 = F_183 ( V_359 , V_361 , sizeof( V_371 ) , & V_371 ) ;
if ( V_372 != NULL )
V_216 -> V_254 = V_372 -> V_377 ;
break;
case V_379 :
V_375 = F_183 ( V_359 , V_361 , sizeof( V_374 ) , & V_374 ) ;
if ( V_375 != NULL )
V_216 -> V_254 = V_375 -> V_380 ;
break;
}
return V_362 ;
}
static int F_185 ( struct V_150 * V_156 , struct V_358 * V_359 )
{
struct V_349 V_381 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_1 * V_9 ;
struct V_248 V_382 ;
int V_7 = 0 ;
struct V_41 V_42 ;
#ifdef F_125
struct V_235 V_236 ;
#endif
switch ( V_156 -> V_230 ) {
case V_269 :
F_186 ( & V_381 ) ;
V_7 = F_187 ( V_359 , V_156 -> V_230 , & V_381 ) ;
if ( V_7 == 0 )
V_9 = F_179 ( & V_381 , V_148 ) ;
else
V_9 = V_228 ;
F_188 ( & V_381 ) ;
#ifdef F_125
F_126 ( & V_42 , V_43 , V_237 , & V_236 ) ;
V_42 . V_238 . V_239 . V_236 -> V_212 = V_156 -> V_230 ;
V_42 . V_238 . V_239 . V_236 -> V_383 = V_359 -> V_384 ;
F_189 ( V_359 , & V_42 . V_238 , NULL ) ;
#endif
V_7 = V_185 ( V_9 , V_148 -> V_159 , V_91 , & V_42 ) ;
if ( V_7 != 0 )
F_190 ( V_359 , V_7 , 0 ) ;
break;
case V_271 :
V_7 = F_181 ( V_359 , & V_382 ) ;
if ( V_7 == V_378 || V_7 == V_376 )
V_7 = F_131 ( V_156 , & V_382 , V_261 ) ;
else
V_7 = 0 ;
break;
}
return V_7 ;
}
static int F_191 ( struct V_149 * V_150 ,
char T_7 * V_385 ,
int T_7 * V_386 , unsigned V_112 )
{
struct V_147 * V_148 ;
char * V_387 = L_4 ;
int V_340 = 1 ;
int V_7 = 0 ;
V_148 = V_150 -> V_156 -> V_157 ;
if ( V_148 -> V_214 != NULL ) {
V_387 = V_148 -> V_214 ;
V_340 = strlen ( V_387 ) + 1 ;
}
if ( V_340 > V_112 )
V_7 = - V_388 ;
else if ( F_192 ( V_385 , V_387 , V_340 ) != 0 )
V_7 = - V_389 ;
if ( F_193 ( V_340 , V_386 ) != 0 )
V_7 = - V_389 ;
return V_7 ;
}
static int F_194 ( struct V_149 * V_150 ,
struct V_358 * V_359 , T_3 * V_163 )
{
struct V_349 V_381 ;
struct V_147 * V_148 = NULL ;
struct V_1 * V_9 ;
int V_212 = V_390 ;
T_3 V_391 = 0 ;
int V_7 ;
if ( V_359 != NULL ) {
if ( V_359 -> V_272 == F_195 ( V_392 ) )
V_212 = V_269 ;
else if ( V_359 -> V_272 == F_195 ( V_393 ) )
V_212 = V_271 ;
}
if ( V_212 == V_390 && V_150 != NULL )
V_212 = V_150 -> V_156 -> V_230 ;
if ( V_212 == V_394 ) {
V_148 = V_150 -> V_156 -> V_157 ;
V_391 = V_148 -> V_161 -> V_206 ;
} else if ( V_212 == V_269 || V_212 == V_271 ) {
if ( V_150 != NULL && V_150 -> V_156 != NULL )
V_148 = V_150 -> V_156 -> V_157 ;
F_186 ( & V_381 ) ;
V_7 = F_187 ( V_359 , V_212 , & V_381 ) ;
if ( V_7 == 0 ) {
V_9 = F_179 ( & V_381 , V_148 ) ;
V_391 = V_9 -> V_206 ;
}
F_188 ( & V_381 ) ;
}
* V_163 = V_391 ;
if ( V_391 == 0 )
return - V_140 ;
return 0 ;
}
static void F_196 ( struct V_150 * V_156 , struct V_149 * V_395 )
{
struct V_147 * V_148 ;
struct V_1 * V_9 = F_22 () ;
if ( V_156 == NULL ||
( V_156 -> V_230 != V_269 && V_156 -> V_230 != V_271 ) )
return;
V_148 = V_156 -> V_157 ;
V_148 -> V_159 = V_9 -> V_45 ;
V_148 -> V_161 = V_9 ;
}
static int F_197 ( struct V_150 * V_156 , struct V_358 * V_359 ,
struct V_396 * V_397 )
{
T_9 V_212 = V_156 -> V_230 ;
struct V_1 * V_9 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_349 V_381 ;
struct V_215 V_398 ;
struct V_399 * V_400 ;
char * V_401 ;
int V_7 ;
struct V_41 V_42 ;
#ifdef F_125
struct V_235 V_236 ;
#endif
if ( V_212 == V_271 ) {
if ( V_359 -> V_272 == F_195 ( V_392 ) )
V_212 = V_269 ;
else
return 0 ;
}
F_186 ( & V_381 ) ;
V_7 = F_187 ( V_359 , V_212 , & V_381 ) ;
if ( V_7 == 0 )
V_9 = F_179 ( & V_381 , V_148 ) ;
else
V_9 = & V_402 ;
F_188 ( & V_381 ) ;
#ifdef F_125
F_126 ( & V_42 , V_43 , V_237 , & V_236 ) ;
V_42 . V_238 . V_239 . V_236 -> V_212 = V_212 ;
V_42 . V_238 . V_239 . V_236 -> V_383 = V_359 -> V_384 ;
F_189 ( V_359 , & V_42 . V_238 , NULL ) ;
#endif
V_7 = V_185 ( V_9 , V_148 -> V_159 , V_91 , & V_42 ) ;
if ( V_7 != 0 )
return V_7 ;
V_397 -> V_403 = V_9 -> V_206 ;
V_400 = F_198 ( V_359 ) ;
V_398 . V_221 . V_222 = V_400 -> V_267 ;
F_48 () ;
V_401 = F_116 ( & V_398 ) ;
F_50 () ;
if ( V_401 == NULL )
V_7 = F_199 ( V_397 , & V_9 -> V_231 ) ;
else
F_200 ( V_397 ) ;
return V_7 ;
}
static void F_201 ( struct V_150 * V_156 ,
const struct V_396 * V_397 )
{
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_1 * V_9 ;
if ( V_397 -> V_403 != 0 ) {
V_9 = F_95 ( V_397 -> V_403 ) ;
V_148 -> V_214 = V_9 -> V_45 ;
} else
V_148 -> V_214 = NULL ;
}
static int F_202 ( struct V_404 * V_404 , const struct V_99 * V_99 ,
unsigned long V_72 )
{
struct V_1 * V_9 = F_14 ( V_99 -> V_100 ) ;
V_404 -> V_100 = V_9 -> V_45 ;
return 0 ;
}
static void F_203 ( struct V_404 * V_404 )
{
V_404 -> V_100 = NULL ;
}
static int F_204 ( T_10 V_405 ,
const struct V_99 * V_99 , T_11 V_406 )
{
struct V_404 * V_407 ;
struct V_41 V_42 ;
struct V_1 * V_190 = F_14 ( V_99 -> V_100 ) ;
V_407 = F_205 ( V_405 ) ;
if ( V_407 == NULL )
return - V_140 ;
if ( V_407 -> V_100 == NULL )
return 0 ;
if ( V_190 == NULL )
return - V_51 ;
#ifdef F_125
F_16 ( & V_42 , V_43 , V_408 ) ;
V_42 . V_238 . V_239 . V_409 . V_404 = V_407 -> V_410 ;
V_42 . V_238 . V_239 . V_409 . V_411 = V_407 -> V_412 ;
#endif
return V_185 ( V_190 , V_407 -> V_100 , V_46 , & V_42 ) ;
}
static int F_206 ( T_3 V_413 , T_3 V_78 , char * V_414 , void * * V_415 )
{
char * * V_416 = ( char * * ) V_415 ;
* V_416 = NULL ;
if ( V_413 != V_417 && V_413 != V_418 )
return - V_140 ;
if ( V_78 != V_419 && V_78 != V_420 )
return - V_140 ;
* V_416 = F_30 ( V_414 , 0 ) ;
return 0 ;
}
static int F_207 ( struct V_421 * V_422 )
{
struct V_423 * V_424 ;
int V_425 ;
for ( V_425 = 0 ; V_425 < V_422 -> V_426 ; V_425 ++ ) {
V_424 = & V_422 -> V_427 [ V_425 ] ;
if ( V_424 -> type == V_417 || V_424 -> type == V_418 )
return 1 ;
}
return 0 ;
}
static int F_208 ( T_3 V_163 , T_3 V_413 , T_3 V_78 , void * V_415 ,
struct V_428 * V_429 )
{
struct V_1 * V_9 ;
char * V_416 = V_415 ;
if ( ! V_416 ) {
F_209 ( V_429 , V_430 , V_431 ,
L_5 ) ;
return - V_184 ;
}
if ( V_413 != V_417 && V_413 != V_418 )
return 0 ;
V_9 = F_95 ( V_163 ) ;
if ( V_78 == V_419 )
return ( V_416 == V_9 -> V_45 ) ;
if ( V_78 == V_420 )
return ( V_416 != V_9 -> V_45 ) ;
return 0 ;
}
static void F_210 ( void * V_415 )
{
}
static int F_211 ( const char * V_2 )
{
return ( strcmp ( V_2 , V_116 ) == 0 ) ;
}
static int F_212 ( T_3 V_163 , char * * V_432 , T_3 * V_433 )
{
struct V_1 * V_9 = F_95 ( V_163 ) ;
if ( V_432 )
* V_432 = V_9 -> V_45 ;
* V_433 = strlen ( V_9 -> V_45 ) ;
return 0 ;
}
static int F_213 ( const char * V_432 , T_3 V_433 , T_3 * V_163 )
{
* V_163 = F_70 ( V_432 ) ;
return 0 ;
}
static void F_214 ( char * V_432 , T_3 V_433 )
{
}
static int F_215 ( struct V_3 * V_3 , void * V_434 , T_3 V_435 )
{
return F_132 ( V_3 , V_116 , V_434 , V_435 , 0 ) ;
}
static int F_216 ( struct V_5 * V_5 , void * V_434 , T_3 V_435 )
{
return F_217 ( V_5 , V_134 , V_434 , V_435 , 0 ) ;
}
static int F_218 ( struct V_3 * V_3 , void * * V_434 , T_3 * V_435 )
{
int V_112 = 0 ;
V_112 = F_66 ( V_3 , V_116 , V_434 , true ) ;
if ( V_112 < 0 )
return V_112 ;
* V_435 = V_112 ;
return 0 ;
}
static T_12 void F_219 ( void )
{
F_6 ( & V_402 . V_29 ) ;
F_6 ( & V_60 . V_29 ) ;
F_6 ( & V_50 . V_29 ) ;
F_6 ( & V_333 . V_29 ) ;
F_6 ( & V_144 . V_29 ) ;
F_6 ( & V_264 . V_29 ) ;
F_8 ( & V_402 . V_28 ) ;
F_8 ( & V_60 . V_28 ) ;
F_8 ( & V_333 . V_28 ) ;
F_8 ( & V_50 . V_28 ) ;
F_8 ( & V_144 . V_28 ) ;
F_8 ( & V_264 . V_28 ) ;
F_130 ( & V_402 . V_37 , & V_436 ) ;
F_130 ( & V_60 . V_37 , & V_436 ) ;
F_130 ( & V_333 . V_37 , & V_436 ) ;
F_130 ( & V_50 . V_37 , & V_436 ) ;
F_130 ( & V_144 . V_37 , & V_436 ) ;
F_130 ( & V_264 . V_37 , & V_436 ) ;
}
static T_12 int F_220 ( void )
{
struct V_99 * V_99 ;
struct V_21 * V_25 ;
if ( ! F_221 ( & V_437 ) )
return 0 ;
V_25 = F_7 ( & V_50 , & V_50 ,
V_13 ) ;
if ( V_25 == NULL )
return - V_36 ;
F_133 ( V_438 L_6 ) ;
V_99 = (struct V_99 * ) V_106 -> V_99 ;
V_99 -> V_100 = V_25 ;
F_219 () ;
if ( F_222 ( & V_437 ) )
F_223 ( L_7 ) ;
return 0 ;
}

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
struct V_2 * V_2 = F_36 ( V_92 -> V_93 ) ;
struct V_20 * V_94 = V_92 -> V_95 -> V_96 ;
struct V_13 * V_15 ;
int V_6 ;
V_6 = F_37 ( V_92 ) ;
if ( V_6 != 0 )
return V_6 ;
if ( V_92 -> V_97 )
return 0 ;
V_15 = V_2 -> V_79 ;
if ( V_15 -> V_25 == NULL || V_15 -> V_25 == V_94 -> V_25 )
return 0 ;
if ( V_92 -> V_98 )
return - V_99 ;
V_94 -> V_25 = V_15 -> V_25 ;
V_92 -> V_100 |= V_101 ;
return 0 ;
}
static void F_38 ( struct V_91 * V_92 )
{
struct V_20 * V_94 = V_92 -> V_95 -> V_96 ;
if ( V_94 -> V_25 != V_94 -> V_26 )
V_102 -> V_103 = 0 ;
}
static int F_39 ( struct V_91 * V_92 )
{
struct V_20 * V_24 = F_40 () ;
int V_104 = F_41 ( V_92 ) ;
if ( ! V_104 && ( V_24 -> V_25 != V_24 -> V_26 ) )
V_104 = 1 ;
return V_104 ;
}
static int F_42 ( struct V_2 * V_2 )
{
V_2 -> V_79 = F_5 ( F_22 () ) ;
if ( V_2 -> V_79 == NULL )
return - V_35 ;
return 0 ;
}
static void F_43 ( struct V_2 * V_2 )
{
F_4 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
}
static int F_44 ( struct V_2 * V_2 , struct V_2 * V_105 ,
const struct V_106 * V_106 , char * * V_1 ,
void * * V_107 , T_2 * V_108 )
{
struct V_109 * V_110 ;
struct V_13 * V_111 = V_2 -> V_79 ;
char * V_112 = F_22 () ;
char * V_15 = F_45 ( V_2 ) ;
char * V_113 = F_45 ( V_105 ) ;
int V_114 ;
if ( V_1 ) {
* V_1 = F_46 ( V_115 , V_16 ) ;
if ( * V_1 == NULL )
return - V_35 ;
}
if ( V_107 ) {
V_110 = F_47 ( V_112 ) ;
F_48 () ;
V_114 = F_49 ( V_112 , V_113 , & V_110 -> V_27 ) ;
F_50 () ;
if ( V_114 > 0 && ( ( V_114 & V_116 ) != 0 ) &&
F_51 ( V_105 ) ) {
V_15 = V_113 ;
V_111 -> V_18 |= V_117 ;
}
* V_107 = F_46 ( V_15 , V_16 ) ;
if ( * V_107 == NULL )
return - V_35 ;
}
if ( V_108 )
* V_108 = strlen ( V_15 ) + 1 ;
return 0 ;
}
static int F_52 ( struct V_4 * V_118 , struct V_2 * V_105 ,
struct V_4 * V_119 )
{
char * V_15 ;
struct V_40 V_41 ;
int V_6 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_118 ) ;
V_15 = F_45 ( V_118 -> V_76 ) ;
V_6 = F_18 ( V_15 , V_87 , & V_41 ) ;
if ( V_6 == 0 && V_119 -> V_76 != NULL ) {
V_15 = F_45 ( V_119 -> V_76 ) ;
F_31 ( & V_41 , V_119 ) ;
V_6 = F_18 ( V_15 , V_87 , & V_41 ) ;
}
return V_6 ;
}
static int F_53 ( struct V_2 * V_105 , struct V_4 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_76 ;
struct V_40 V_41 ;
int V_6 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
V_6 = F_18 ( F_45 ( V_3 ) , V_87 , & V_41 ) ;
if ( V_6 == 0 ) {
F_16 ( & V_41 , V_42 , V_120 ) ;
F_54 ( & V_41 , V_105 ) ;
V_6 = F_18 ( F_45 ( V_105 ) , V_87 , & V_41 ) ;
}
return V_6 ;
}
static int F_55 ( struct V_2 * V_105 , struct V_4 * V_4 )
{
struct V_40 V_41 ;
int V_6 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
V_6 = F_18 ( F_45 ( V_4 -> V_76 ) , V_87 , & V_41 ) ;
if ( V_6 == 0 ) {
F_16 ( & V_41 , V_42 , V_120 ) ;
F_54 ( & V_41 , V_105 ) ;
V_6 = F_18 ( F_45 ( V_105 ) , V_87 , & V_41 ) ;
}
return V_6 ;
}
static int F_56 ( struct V_2 * V_121 ,
struct V_4 * V_118 ,
struct V_2 * V_122 ,
struct V_4 * V_119 )
{
int V_6 ;
char * V_15 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_118 ) ;
V_15 = F_45 ( V_118 -> V_76 ) ;
V_6 = F_18 ( V_15 , V_44 , & V_41 ) ;
if ( V_6 == 0 && V_119 -> V_76 != NULL ) {
V_15 = F_45 ( V_119 -> V_76 ) ;
F_31 ( & V_41 , V_119 ) ;
V_6 = F_18 ( V_15 , V_44 , & V_41 ) ;
}
return V_6 ;
}
static int F_57 ( struct V_2 * V_2 , int V_123 )
{
struct V_40 V_41 ;
int V_124 = V_123 & V_125 ;
V_123 &= ( V_83 | V_87 | V_126 | V_127 ) ;
if ( V_123 == 0 )
return 0 ;
if ( V_124 )
return - V_128 ;
F_16 ( & V_41 , V_42 , V_120 ) ;
F_54 ( & V_41 , V_2 ) ;
return F_18 ( F_45 ( V_2 ) , V_123 , & V_41 ) ;
}
static int F_58 ( struct V_4 * V_4 , struct V_129 * V_129 )
{
struct V_40 V_41 ;
if ( V_129 -> V_130 & V_131 )
return 0 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
return F_18 ( F_45 ( V_4 -> V_76 ) , V_87 , & V_41 ) ;
}
static int F_59 ( struct V_88 * V_89 , struct V_4 * V_4 )
{
struct V_40 V_41 ;
struct V_85 V_85 ;
V_85 . V_4 = V_4 ;
V_85 . V_89 = V_89 ;
F_16 ( & V_41 , V_42 , V_86 ) ;
F_33 ( & V_41 , V_85 ) ;
return F_18 ( F_45 ( V_4 -> V_76 ) , V_83 , & V_41 ) ;
}
static int F_60 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_107 , T_2 V_132 , int V_72 )
{
struct V_40 V_41 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_133 ) == 0 ||
strcmp ( V_1 , V_134 ) == 0 ||
strcmp ( V_1 , V_135 ) == 0 ||
strcmp ( V_1 , V_136 ) == 0 ||
strcmp ( V_1 , V_137 ) == 0 ) {
if ( ! F_23 ( V_138 ) )
V_6 = - V_99 ;
if ( V_132 == 0 || V_132 >= V_11 ||
F_3 ( V_107 , V_132 ) == NULL )
V_6 = - V_139 ;
} else if ( strcmp ( V_1 , V_140 ) == 0 ) {
if ( ! F_23 ( V_138 ) )
V_6 = - V_99 ;
if ( V_132 != V_141 ||
strncmp ( V_107 , V_142 , V_141 ) != 0 )
V_6 = - V_139 ;
} else
V_6 = F_61 ( V_4 , V_1 , V_107 , V_132 , V_72 ) ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_18 ( F_45 ( V_4 -> V_76 ) , V_87 , & V_41 ) ;
return V_6 ;
}
static void F_62 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_107 , T_2 V_132 , int V_72 )
{
char * V_78 ;
struct V_13 * V_15 = V_4 -> V_76 -> V_79 ;
if ( strcmp ( V_1 , V_133 ) == 0 ) {
V_78 = F_3 ( V_107 , V_132 ) ;
if ( V_78 != NULL )
V_15 -> V_17 = V_78 ;
else
V_15 -> V_17 = V_143 . V_50 ;
} else if ( strcmp ( V_1 , V_136 ) == 0 ) {
V_78 = F_3 ( V_107 , V_132 ) ;
if ( V_78 != NULL )
V_15 -> V_25 = V_78 ;
else
V_15 -> V_25 = V_143 . V_50 ;
} else if ( strcmp ( V_1 , V_137 ) == 0 ) {
V_78 = F_3 ( V_107 , V_132 ) ;
if ( V_78 != NULL )
V_15 -> V_144 = V_78 ;
else
V_15 -> V_144 = V_143 . V_50 ;
} else if ( strcmp ( V_1 , V_140 ) == 0 )
V_15 -> V_18 |= V_145 ;
return;
}
static int F_63 ( struct V_4 * V_4 , const char * V_1 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
return F_18 ( F_45 ( V_4 -> V_76 ) , V_83 , & V_41 ) ;
}
static int F_64 ( struct V_4 * V_4 , const char * V_1 )
{
struct V_13 * V_15 ;
struct V_40 V_41 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_133 ) == 0 ||
strcmp ( V_1 , V_134 ) == 0 ||
strcmp ( V_1 , V_135 ) == 0 ||
strcmp ( V_1 , V_136 ) == 0 ||
strcmp ( V_1 , V_140 ) == 0 ||
strcmp ( V_1 , V_137 ) ) {
if ( ! F_23 ( V_138 ) )
V_6 = - V_99 ;
} else
V_6 = F_65 ( V_4 , V_1 ) ;
F_16 ( & V_41 , V_42 , V_82 ) ;
F_31 ( & V_41 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_18 ( F_45 ( V_4 -> V_76 ) , V_87 , & V_41 ) ;
if ( V_6 == 0 ) {
V_15 = V_4 -> V_76 -> V_79 ;
V_15 -> V_25 = NULL ;
V_15 -> V_144 = NULL ;
}
return V_6 ;
}
static int F_66 ( const struct V_2 * V_2 ,
const char * V_1 , void * * V_7 ,
bool V_146 )
{
struct V_147 * V_148 ;
struct V_149 * V_150 ;
struct V_52 * V_80 ;
struct V_2 * V_3 = (struct V_2 * ) V_2 ;
char * V_15 ;
int V_151 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_115 ) == 0 ) {
V_15 = F_45 ( V_2 ) ;
V_151 = strlen ( V_15 ) + 1 ;
* V_7 = V_15 ;
return V_151 ;
}
V_80 = V_3 -> V_152 ;
if ( V_80 -> V_153 != V_154 )
return - V_155 ;
V_150 = F_67 ( V_3 ) ;
if ( V_150 == NULL || V_150 -> V_156 == NULL )
return - V_155 ;
V_148 = V_150 -> V_156 -> V_157 ;
if ( strcmp ( V_1 , V_158 ) == 0 )
V_15 = V_148 -> V_159 ;
else if ( strcmp ( V_1 , V_160 ) == 0 )
V_15 = V_148 -> V_161 ;
else
return - V_155 ;
V_151 = strlen ( V_15 ) + 1 ;
if ( V_6 == 0 ) {
* V_7 = V_15 ;
V_6 = V_151 ;
}
return V_6 ;
}
static int F_68 ( struct V_2 * V_2 , char * V_7 ,
T_2 V_162 )
{
int V_108 = strlen ( V_133 ) ;
if ( V_7 != NULL && V_108 <= V_162 ) {
memcpy ( V_7 , V_133 , V_108 ) ;
return V_108 ;
}
return - V_139 ;
}
static void F_69 ( const struct V_2 * V_2 , T_3 * V_163 )
{
struct V_13 * V_15 = V_2 -> V_79 ;
* V_163 = F_70 ( V_15 -> V_17 ) ;
}
static int F_71 ( struct V_93 * V_93 , int V_123 )
{
return 0 ;
}
static int F_72 ( struct V_93 * V_93 )
{
V_93 -> V_164 = F_22 () ;
return 0 ;
}
static void F_73 ( struct V_93 * V_93 )
{
V_93 -> V_164 = NULL ;
}
static int F_74 ( struct V_93 * V_93 , unsigned int V_165 ,
unsigned long V_166 )
{
int V_6 = 0 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_86 ) ;
F_33 ( & V_41 , V_93 -> V_167 ) ;
if ( F_75 ( V_165 ) & V_168 )
V_6 = F_18 ( V_93 -> V_164 , V_87 , & V_41 ) ;
if ( V_6 == 0 && ( F_75 ( V_165 ) & V_169 ) )
V_6 = F_18 ( V_93 -> V_164 , V_83 , & V_41 ) ;
return V_6 ;
}
static int F_76 ( struct V_93 * V_93 , unsigned int V_165 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_86 ) ;
F_33 ( & V_41 , V_93 -> V_167 ) ;
return F_18 ( V_93 -> V_164 , V_87 , & V_41 ) ;
}
static int F_77 ( struct V_93 * V_93 , unsigned int V_165 ,
unsigned long V_166 )
{
struct V_40 V_41 ;
int V_6 = 0 ;
switch ( V_165 ) {
case V_170 :
case V_171 :
case V_172 :
case V_173 :
case V_174 :
F_16 ( & V_41 , V_42 , V_86 ) ;
F_33 ( & V_41 , V_93 -> V_167 ) ;
V_6 = F_18 ( V_93 -> V_164 , V_87 , & V_41 ) ;
break;
default:
break;
}
return V_6 ;
}
static int F_78 ( struct V_93 * V_93 ,
unsigned long V_175 , unsigned long V_176 ,
unsigned long V_72 )
{
struct V_109 * V_110 ;
struct V_32 * V_177 ;
struct V_20 * V_24 ;
char * V_47 ;
char * V_178 ;
char * V_179 ;
struct V_13 * V_15 ;
int V_114 ;
int V_180 ;
int V_181 ;
int V_6 ;
if ( V_93 == NULL )
return 0 ;
V_15 = F_36 ( V_93 ) -> V_79 ;
if ( V_15 -> V_144 == NULL )
return 0 ;
V_178 = V_15 -> V_144 ;
V_24 = F_40 () ;
V_47 = F_22 () ;
V_110 = F_47 ( V_47 ) ;
V_6 = 0 ;
F_48 () ;
F_10 (srp, &skp->smk_rules, list) {
V_179 = V_177 -> V_182 ;
if ( V_178 == V_179 )
continue;
V_114 = F_49 ( V_177 -> V_183 , V_179 ,
& V_24 -> V_27 ) ;
if ( V_114 == - V_184 )
V_114 = V_177 -> V_185 ;
else
V_114 &= V_177 -> V_185 ;
if ( V_114 == 0 )
continue;
V_110 = F_47 ( V_178 ) ;
V_180 = F_49 ( V_178 , V_179 , & V_110 -> V_27 ) ;
if ( V_180 == - V_184 ) {
V_6 = - V_51 ;
break;
}
V_181 = F_49 ( V_178 , V_179 , & V_24 -> V_27 ) ;
if ( V_181 != - V_184 )
V_180 &= V_181 ;
if ( ( V_114 | V_180 ) != V_180 ) {
V_6 = - V_51 ;
break;
}
}
F_50 () ;
return V_6 ;
}
static int F_79 ( struct V_93 * V_93 )
{
V_93 -> V_164 = F_22 () ;
return 0 ;
}
static int F_80 ( struct V_37 * V_186 ,
struct V_187 * V_188 , int V_189 )
{
struct V_93 * V_93 ;
int V_6 ;
char * V_24 = F_14 ( V_186 -> V_95 -> V_96 ) ;
struct V_40 V_41 ;
V_93 = F_81 ( V_188 , struct V_93 , V_190 ) ;
V_6 = V_185 ( V_93 -> V_164 , V_24 , V_87 , NULL ) ;
if ( V_6 != 0 && F_82 ( V_186 , V_48 ) )
V_6 = 0 ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_17 ( & V_41 , V_186 ) ;
F_83 ( V_93 -> V_164 , V_24 , V_87 , V_6 , & V_41 ) ;
return V_6 ;
}
static int F_84 ( struct V_93 * V_93 )
{
int V_114 = 0 ;
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_33 ( & V_41 , V_93 -> V_167 ) ;
if ( V_93 -> V_191 & V_192 )
V_114 = V_83 ;
if ( V_93 -> V_191 & V_193 )
V_114 |= V_87 ;
return F_18 ( V_93 -> V_164 , V_114 , & V_41 ) ;
}
static int F_85 ( struct V_93 * V_93 , const struct V_95 * V_95 )
{
struct V_13 * V_15 = F_36 ( V_93 ) -> V_79 ;
V_93 -> V_164 = V_15 -> V_17 ;
return 0 ;
}
static int F_86 ( struct V_95 * V_95 , T_1 V_23 )
{
struct V_20 * V_24 ;
V_24 = F_7 ( NULL , NULL , V_23 ) ;
if ( V_24 == NULL )
return - V_35 ;
V_95 -> V_96 = V_24 ;
return 0 ;
}
static void F_87 ( struct V_95 * V_95 )
{
struct V_20 * V_24 = V_95 -> V_96 ;
struct V_32 * V_194 ;
struct V_29 * V_195 ;
struct V_29 * V_196 ;
if ( V_24 == NULL )
return;
V_95 -> V_96 = NULL ;
F_88 (l, n, &tsp->smk_rules) {
V_194 = F_89 ( V_195 , struct V_32 , V_36 ) ;
F_90 ( & V_194 -> V_36 ) ;
F_4 ( V_194 ) ;
}
F_4 ( V_24 ) ;
}
static int F_91 ( struct V_95 * V_197 , const struct V_95 * V_198 ,
T_1 V_23 )
{
struct V_20 * V_199 = V_198 -> V_96 ;
struct V_20 * V_200 ;
int V_6 ;
V_200 = F_7 ( V_199 -> V_25 , V_199 -> V_25 , V_23 ) ;
if ( V_200 == NULL )
return - V_35 ;
V_6 = F_9 ( & V_200 -> V_27 , & V_199 -> V_27 , V_23 ) ;
if ( V_6 != 0 )
return V_6 ;
V_197 -> V_96 = V_200 ;
return 0 ;
}
static void F_92 ( struct V_95 * V_197 , const struct V_95 * V_198 )
{
struct V_20 * V_199 = V_198 -> V_96 ;
struct V_20 * V_200 = V_197 -> V_96 ;
V_200 -> V_25 = V_199 -> V_25 ;
V_200 -> V_26 = V_199 -> V_25 ;
F_6 ( & V_200 -> V_28 ) ;
F_8 ( & V_200 -> V_27 ) ;
}
static int F_93 ( struct V_95 * V_197 , T_3 V_163 )
{
struct V_20 * V_200 = V_197 -> V_96 ;
char * V_14 = F_94 ( V_163 ) ;
if ( V_14 == NULL )
return - V_139 ;
V_200 -> V_25 = V_14 ;
return 0 ;
}
static int F_95 ( struct V_95 * V_197 ,
struct V_2 * V_2 )
{
struct V_13 * V_15 = V_2 -> V_79 ;
struct V_20 * V_24 = V_197 -> V_96 ;
V_24 -> V_26 = V_15 -> V_17 ;
V_24 -> V_25 = V_15 -> V_17 ;
return 0 ;
}
static int F_96 ( struct V_37 * V_201 , int V_202 ,
const char * V_203 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_203 , V_43 ) ;
F_17 ( & V_41 , V_201 ) ;
return F_18 ( F_14 ( F_15 ( V_201 ) ) , V_202 , & V_41 ) ;
}
static int F_97 ( struct V_37 * V_201 , T_4 V_204 )
{
return F_96 ( V_201 , V_87 , V_42 ) ;
}
static int F_98 ( struct V_37 * V_201 )
{
return F_96 ( V_201 , V_83 , V_42 ) ;
}
static int F_99 ( struct V_37 * V_201 )
{
return F_96 ( V_201 , V_83 , V_42 ) ;
}
static void F_100 ( struct V_37 * V_201 , T_3 * V_163 )
{
* V_163 = F_70 ( F_14 ( F_15 ( V_201 ) ) ) ;
}
static int F_101 ( struct V_37 * V_201 , int V_205 )
{
int V_6 ;
V_6 = F_102 ( V_201 , V_205 ) ;
if ( V_6 == 0 )
V_6 = F_96 ( V_201 , V_87 , V_42 ) ;
return V_6 ;
}
static int F_103 ( struct V_37 * V_201 , int V_206 )
{
int V_6 ;
V_6 = F_104 ( V_201 , V_206 ) ;
if ( V_6 == 0 )
V_6 = F_96 ( V_201 , V_87 , V_42 ) ;
return V_6 ;
}
static int F_105 ( struct V_37 * V_201 )
{
return F_96 ( V_201 , V_83 , V_42 ) ;
}
static int F_106 ( struct V_37 * V_201 )
{
int V_6 ;
V_6 = F_107 ( V_201 ) ;
if ( V_6 == 0 )
V_6 = F_96 ( V_201 , V_87 , V_42 ) ;
return V_6 ;
}
static int F_108 ( struct V_37 * V_201 )
{
return F_96 ( V_201 , V_83 , V_42 ) ;
}
static int F_109 ( struct V_37 * V_201 )
{
return F_96 ( V_201 , V_87 , V_42 ) ;
}
static int F_110 ( struct V_37 * V_201 , struct V_207 * V_208 ,
int V_209 , T_3 V_163 )
{
struct V_40 V_41 ;
F_16 ( & V_41 , V_42 , V_43 ) ;
F_17 ( & V_41 , V_201 ) ;
if ( V_163 == 0 )
return F_18 ( F_14 ( F_15 ( V_201 ) ) , V_87 ,
& V_41 ) ;
return V_185 ( F_94 ( V_163 ) ,
F_14 ( F_15 ( V_201 ) ) , V_87 , & V_41 ) ;
}
static int F_111 ( struct V_37 * V_201 )
{
return 0 ;
}
static void F_112 ( struct V_37 * V_201 , struct V_2 * V_2 )
{
struct V_13 * V_15 = V_2 -> V_79 ;
V_15 -> V_17 = F_14 ( F_15 ( V_201 ) ) ;
}
static int F_113 ( struct V_150 * V_156 , int V_210 , T_1 V_211 )
{
char * V_112 = F_22 () ;
struct V_147 * V_148 ;
V_148 = F_2 ( sizeof( struct V_147 ) , V_211 ) ;
if ( V_148 == NULL )
return - V_35 ;
V_148 -> V_159 = V_112 ;
V_148 -> V_161 = V_112 ;
V_148 -> V_212 = NULL ;
V_156 -> V_157 = V_148 ;
return 0 ;
}
static void F_114 ( struct V_150 * V_156 )
{
F_4 ( V_156 -> V_157 ) ;
}
static char * F_115 ( struct V_213 * V_214 )
{
struct V_215 * V_216 ;
struct V_217 * V_218 = & V_214 -> V_219 ;
if ( V_218 -> V_220 == 0 )
return NULL ;
F_10 (snp, &smk_netlbladdr_list, list)
if ( ( & V_216 -> V_221 . V_219 ) -> V_220 ==
( V_218 -> V_220 & ( & V_216 -> V_222 ) -> V_220 ) ) {
if ( V_216 -> V_223 == V_224 )
return NULL ;
return V_216 -> V_223 ;
}
return NULL ;
}
static int F_116 ( struct V_150 * V_156 , int V_225 )
{
struct V_109 * V_110 ;
struct V_147 * V_148 = V_156 -> V_157 ;
int V_6 = 0 ;
F_117 () ;
F_118 ( V_156 ) ;
if ( V_148 -> V_161 == V_226 ||
V_225 == V_227 )
F_119 ( V_156 ) ;
else {
V_110 = F_47 ( V_148 -> V_161 ) ;
V_6 = F_120 ( V_156 , V_156 -> V_228 , & V_110 -> V_229 ) ;
}
F_121 ( V_156 ) ;
F_122 () ;
return V_6 ;
}
static int F_123 ( struct V_150 * V_156 , struct V_213 * V_230 )
{
int V_6 ;
int V_231 ;
char * V_232 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_40 V_41 ;
F_48 () ;
V_232 = F_115 ( V_230 ) ;
if ( V_232 != NULL ) {
#ifdef F_124
struct V_233 V_234 ;
F_125 ( & V_41 , V_42 , V_235 , & V_234 ) ;
V_41 . V_236 . V_237 . V_234 -> V_210 = V_230 -> V_238 ;
V_41 . V_236 . V_237 . V_234 -> V_239 = V_230 -> V_240 ;
V_41 . V_236 . V_237 . V_234 -> V_241 . V_242 = V_230 -> V_219 . V_220 ;
#endif
V_231 = V_227 ;
V_6 = V_185 ( V_148 -> V_161 , V_232 , V_87 , & V_41 ) ;
} else {
V_231 = V_243 ;
V_6 = 0 ;
}
F_50 () ;
if ( V_6 != 0 )
return V_6 ;
return F_116 ( V_156 , V_231 ) ;
}
static int F_126 ( struct V_2 * V_2 , const char * V_1 ,
const void * V_107 , T_2 V_132 , int V_72 )
{
char * V_47 ;
struct V_13 * V_78 = V_2 -> V_79 ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
int V_6 = 0 ;
if ( V_107 == NULL || V_132 > V_11 || V_132 == 0 )
return - V_51 ;
V_47 = F_3 ( V_107 , V_132 ) ;
if ( V_47 == NULL )
return - V_139 ;
if ( strcmp ( V_1 , V_115 ) == 0 ) {
V_78 -> V_17 = V_47 ;
V_78 -> V_18 |= V_244 ;
return 0 ;
}
if ( V_2 -> V_152 -> V_153 != V_154 )
return - V_155 ;
V_150 = F_67 ( V_2 ) ;
if ( V_150 == NULL || V_150 -> V_156 == NULL )
return - V_155 ;
V_148 = V_150 -> V_156 -> V_157 ;
if ( strcmp ( V_1 , V_158 ) == 0 )
V_148 -> V_159 = V_47 ;
else if ( strcmp ( V_1 , V_160 ) == 0 ) {
V_148 -> V_161 = V_47 ;
if ( V_150 -> V_156 -> V_228 != V_245 ) {
V_6 = F_116 ( V_150 -> V_156 , V_243 ) ;
if ( V_6 != 0 )
F_127 ( V_246
L_2 ,
V_42 , - V_6 ) ;
}
} else
return - V_155 ;
return 0 ;
}
static int F_128 ( struct V_149 * V_150 , int V_210 ,
int type , int V_247 , int V_248 )
{
if ( V_210 != V_249 || V_150 -> V_156 == NULL )
return 0 ;
return F_116 ( V_150 -> V_156 , V_243 ) ;
}
static int F_129 ( struct V_149 * V_150 , struct V_250 * V_230 ,
int V_251 )
{
if ( V_150 -> V_156 == NULL || V_150 -> V_156 -> V_228 != V_249 )
return 0 ;
if ( V_251 < sizeof( struct V_213 ) )
return - V_139 ;
return F_123 ( V_150 -> V_156 , (struct V_213 * ) V_230 ) ;
}
static int F_130 ( int V_72 )
{
int V_114 = 0 ;
if ( V_72 & V_252 )
V_114 |= V_83 ;
if ( V_72 & V_253 )
V_114 |= V_87 ;
if ( V_72 & V_254 )
V_114 |= V_126 ;
return V_114 ;
}
static int F_131 ( struct V_255 * V_256 )
{
V_256 -> V_96 = F_22 () ;
return 0 ;
}
static void F_132 ( struct V_255 * V_256 )
{
V_256 -> V_96 = NULL ;
}
static char * F_133 ( struct V_257 * V_258 )
{
return ( char * ) V_258 -> V_259 . V_96 ;
}
static int F_134 ( struct V_257 * V_258 )
{
struct V_260 * V_15 = & V_258 -> V_259 ;
V_15 -> V_96 = F_22 () ;
return 0 ;
}
static void F_135 ( struct V_257 * V_258 )
{
struct V_260 * V_15 = & V_258 -> V_259 ;
V_15 -> V_96 = NULL ;
}
static int F_136 ( struct V_257 * V_258 , int V_202 )
{
char * V_148 = F_133 ( V_258 ) ;
struct V_40 V_41 ;
#ifdef F_124
F_16 ( & V_41 , V_42 , V_261 ) ;
V_41 . V_236 . V_237 . V_262 = V_258 -> V_259 . V_263 ;
#endif
return F_18 ( V_148 , V_202 , & V_41 ) ;
}
static int F_137 ( struct V_257 * V_258 , int V_264 )
{
int V_114 ;
V_114 = F_130 ( V_264 ) ;
return F_136 ( V_258 , V_114 ) ;
}
static int F_138 ( struct V_257 * V_258 , int V_165 )
{
int V_114 ;
switch ( V_165 ) {
case V_265 :
case V_266 :
V_114 = V_83 ;
break;
case V_267 :
case V_268 :
case V_269 :
case V_270 :
V_114 = V_44 ;
break;
case V_271 :
case V_272 :
return 0 ;
default:
return - V_139 ;
}
return F_136 ( V_258 , V_114 ) ;
}
static int F_139 ( struct V_257 * V_258 , char T_5 * V_273 ,
int V_264 )
{
int V_114 ;
V_114 = F_130 ( V_264 ) ;
return F_136 ( V_258 , V_114 ) ;
}
static char * F_140 ( struct V_274 * V_275 )
{
return ( char * ) V_275 -> V_276 . V_96 ;
}
static int F_141 ( struct V_274 * V_275 )
{
struct V_260 * V_15 = & V_275 -> V_276 ;
V_15 -> V_96 = F_22 () ;
return 0 ;
}
static void F_142 ( struct V_274 * V_275 )
{
struct V_260 * V_15 = & V_275 -> V_276 ;
V_15 -> V_96 = NULL ;
}
static int F_143 ( struct V_274 * V_275 , int V_202 )
{
char * V_148 = F_140 ( V_275 ) ;
struct V_40 V_41 ;
#ifdef F_124
F_16 ( & V_41 , V_42 , V_261 ) ;
V_41 . V_236 . V_237 . V_262 = V_275 -> V_276 . V_263 ;
#endif
return F_18 ( V_148 , V_202 , & V_41 ) ;
}
static int F_144 ( struct V_274 * V_275 , int V_277 )
{
int V_114 ;
V_114 = F_130 ( V_277 ) ;
return F_143 ( V_275 , V_114 ) ;
}
static int F_145 ( struct V_274 * V_275 , int V_165 )
{
int V_114 ;
switch ( V_165 ) {
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_265 :
case V_283 :
V_114 = V_83 ;
break;
case V_284 :
case V_285 :
case V_270 :
case V_267 :
V_114 = V_44 ;
break;
case V_271 :
case V_286 :
return 0 ;
default:
return - V_139 ;
}
return F_143 ( V_275 , V_114 ) ;
}
static int F_146 ( struct V_274 * V_275 , struct V_287 * V_288 ,
unsigned V_289 , int V_290 )
{
return F_143 ( V_275 , V_44 ) ;
}
static int F_147 ( struct V_291 * V_292 )
{
struct V_260 * V_293 = & V_292 -> V_294 ;
V_293 -> V_96 = F_22 () ;
return 0 ;
}
static void F_148 ( struct V_291 * V_292 )
{
struct V_260 * V_293 = & V_292 -> V_294 ;
V_293 -> V_96 = NULL ;
}
static char * F_149 ( struct V_291 * V_292 )
{
return ( char * ) V_292 -> V_294 . V_96 ;
}
static int F_150 ( struct V_291 * V_292 , int V_202 )
{
char * V_295 = F_149 ( V_292 ) ;
struct V_40 V_41 ;
#ifdef F_124
F_16 ( & V_41 , V_42 , V_261 ) ;
V_41 . V_236 . V_237 . V_262 = V_292 -> V_294 . V_263 ;
#endif
return F_18 ( V_295 , V_202 , & V_41 ) ;
}
static int F_151 ( struct V_291 * V_292 , int V_296 )
{
int V_114 ;
V_114 = F_130 ( V_296 ) ;
return F_150 ( V_292 , V_114 ) ;
}
static int F_152 ( struct V_291 * V_292 , int V_165 )
{
int V_114 ;
switch ( V_165 ) {
case V_265 :
case V_297 :
V_114 = V_83 ;
break;
case V_267 :
case V_270 :
V_114 = V_44 ;
break;
case V_271 :
case V_298 :
return 0 ;
default:
return - V_139 ;
}
return F_150 ( V_292 , V_114 ) ;
}
static int F_153 ( struct V_291 * V_292 , struct V_255 * V_256 ,
int V_296 )
{
int V_114 ;
V_114 = F_130 ( V_296 ) ;
return F_150 ( V_292 , V_114 ) ;
}
static int F_154 ( struct V_291 * V_292 , struct V_255 * V_256 ,
struct V_37 * V_299 , long type , int V_39 )
{
return F_150 ( V_292 , V_44 ) ;
}
static int F_155 ( struct V_260 * V_300 , short V_301 )
{
char * V_15 = V_300 -> V_96 ;
int V_114 = F_130 ( V_301 ) ;
struct V_40 V_41 ;
#ifdef F_124
F_16 ( & V_41 , V_42 , V_261 ) ;
V_41 . V_236 . V_237 . V_262 = V_300 -> V_263 ;
#endif
return F_18 ( V_15 , V_114 , & V_41 ) ;
}
static void F_156 ( struct V_260 * V_300 , T_3 * V_163 )
{
char * V_14 = V_300 -> V_96 ;
* V_163 = F_70 ( V_14 ) ;
}
static void F_157 ( struct V_4 * V_302 , struct V_2 * V_2 )
{
struct V_52 * V_80 ;
struct V_54 * V_55 ;
struct V_13 * V_15 ;
char * V_112 = F_22 () ;
char * V_303 ;
char * V_304 ;
char V_305 [ V_141 ] ;
int V_306 = 0 ;
int V_6 ;
struct V_4 * V_5 ;
if ( V_2 == NULL )
return;
V_15 = V_2 -> V_79 ;
F_158 ( & V_15 -> V_19 ) ;
if ( V_15 -> V_18 & V_244 )
goto V_307;
V_80 = V_2 -> V_152 ;
V_55 = V_80 -> V_62 ;
V_304 = V_55 -> V_57 ;
if ( V_302 -> V_308 == V_302 ) {
V_15 -> V_17 = V_55 -> V_56 ;
V_15 -> V_18 |= V_244 ;
goto V_307;
}
switch ( V_80 -> V_153 ) {
case V_309 :
V_304 = V_310 . V_50 ;
break;
case V_311 :
V_304 = V_310 . V_50 ;
break;
case V_312 :
V_304 = V_112 ;
break;
case V_154 :
V_304 = V_310 . V_50 ;
break;
case V_313 :
break;
case V_314 :
V_304 = V_310 . V_50 ;
default:
if ( F_159 ( V_2 -> V_315 ) ) {
V_304 = V_310 . V_50 ;
break;
}
if ( V_2 -> V_9 -> V_10 == NULL )
break;
V_5 = F_160 ( V_302 ) ;
V_303 = F_1 ( V_133 , V_2 , V_5 ) ;
if ( V_303 != NULL )
V_304 = V_303 ;
if ( F_161 ( V_2 -> V_315 ) ) {
if ( V_15 -> V_18 & V_117 ) {
V_15 -> V_18 &= ~ V_117 ;
V_6 = V_2 -> V_9 -> V_316 ( V_5 ,
V_140 ,
V_142 , V_141 ,
0 ) ;
} else {
V_6 = V_2 -> V_9 -> V_10 ( V_5 ,
V_140 , V_305 ,
V_141 ) ;
if ( V_6 >= 0 && strncmp ( V_305 , V_142 ,
V_141 ) != 0 )
V_6 = - V_139 ;
}
if ( V_6 >= 0 )
V_306 = V_145 ;
}
V_15 -> V_25 = F_1 ( V_136 , V_2 , V_5 ) ;
V_15 -> V_144 = F_1 ( V_137 , V_2 , V_5 ) ;
F_162 ( V_5 ) ;
break;
}
if ( V_304 == NULL )
V_15 -> V_17 = V_112 ;
else
V_15 -> V_17 = V_304 ;
V_15 -> V_18 |= ( V_244 | V_306 ) ;
V_307:
F_163 ( & V_15 -> V_19 ) ;
return;
}
static int F_164 ( struct V_37 * V_201 , char * V_1 , char * * V_107 )
{
char * V_65 ;
int V_317 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_139 ;
V_65 = F_46 ( F_14 ( F_15 ( V_201 ) ) , V_12 ) ;
if ( V_65 == NULL )
return - V_35 ;
V_317 = strlen ( V_65 ) ;
* V_107 = V_65 ;
return V_317 ;
}
static int F_165 ( struct V_37 * V_201 , char * V_1 ,
void * V_107 , T_2 V_132 )
{
struct V_20 * V_24 ;
struct V_95 * V_197 ;
char * V_318 ;
if ( V_201 != V_102 )
return - V_99 ;
if ( ! F_23 ( V_138 ) )
return - V_99 ;
if ( V_107 == NULL || V_132 == 0 || V_132 >= V_11 )
return - V_139 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_139 ;
V_318 = F_3 ( V_107 , V_132 ) ;
if ( V_318 == NULL )
return - V_139 ;
if ( V_318 == V_319 . V_50 )
return - V_99 ;
V_197 = F_166 () ;
if ( V_197 == NULL )
return - V_35 ;
V_24 = V_197 -> V_96 ;
V_24 -> V_25 = V_318 ;
F_167 ( V_197 ) ;
return V_132 ;
}
static int F_168 ( struct V_150 * V_150 ,
struct V_150 * V_320 , struct V_150 * V_321 )
{
struct V_147 * V_148 = V_150 -> V_157 ;
struct V_147 * V_322 = V_320 -> V_157 ;
struct V_147 * V_78 = V_321 -> V_157 ;
struct V_40 V_41 ;
int V_6 = 0 ;
#ifdef F_124
struct V_233 V_234 ;
F_125 ( & V_41 , V_42 , V_235 , & V_234 ) ;
F_169 ( & V_41 , V_320 ) ;
#endif
if ( ! F_23 ( V_48 ) )
V_6 = V_185 ( V_148 -> V_161 , V_322 -> V_159 , V_87 , & V_41 ) ;
if ( V_6 == 0 ) {
V_78 -> V_212 = V_148 -> V_161 ;
V_148 -> V_212 = V_322 -> V_161 ;
}
return V_6 ;
}
static int F_170 ( struct V_149 * V_150 , struct V_149 * V_320 )
{
struct V_147 * V_148 = V_150 -> V_156 -> V_157 ;
struct V_147 * V_322 = V_320 -> V_156 -> V_157 ;
struct V_40 V_41 ;
int V_6 = 0 ;
#ifdef F_124
struct V_233 V_234 ;
F_125 ( & V_41 , V_42 , V_235 , & V_234 ) ;
F_169 ( & V_41 , V_320 -> V_156 ) ;
#endif
if ( ! F_23 ( V_48 ) )
V_6 = V_185 ( V_148 -> V_161 , V_322 -> V_159 , V_87 , & V_41 ) ;
return V_6 ;
}
static int F_171 ( struct V_149 * V_150 , struct V_323 * V_256 ,
int V_132 )
{
struct V_213 * V_214 = (struct V_213 * ) V_256 -> V_324 ;
if ( V_214 == NULL || V_214 -> V_238 != V_325 )
return 0 ;
return F_123 ( V_150 -> V_156 , V_214 ) ;
}
static char * F_172 ( struct V_326 * V_230 ,
struct V_147 * V_148 )
{
struct V_109 * V_327 ;
char * V_47 ;
int V_328 = 0 ;
if ( ( V_230 -> V_72 & V_329 ) != 0 ) {
F_48 () ;
F_173 (kp, &smack_known_list, list) {
if ( V_230 -> V_330 . V_331 . V_332 != V_327 -> V_229 . V_330 . V_331 . V_332 )
continue;
if ( memcmp ( V_230 -> V_330 . V_331 . V_333 ,
V_327 -> V_229 . V_330 . V_331 . V_333 ,
V_334 ) != 0 )
continue;
V_328 = 1 ;
break;
}
F_50 () ;
if ( V_328 )
return V_327 -> V_50 ;
if ( V_148 != NULL && V_148 -> V_159 == V_310 . V_50 )
return V_319 . V_50 ;
return V_310 . V_50 ;
}
if ( ( V_230 -> V_72 & V_335 ) != 0 ) {
V_47 = F_94 ( V_230 -> V_330 . V_163 ) ;
F_174 ( V_47 == NULL ) ;
return V_47 ;
}
return V_226 ;
}
static int F_175 ( struct V_150 * V_156 , struct V_336 * V_337 )
{
struct V_326 V_338 ;
struct V_147 * V_148 = V_156 -> V_157 ;
char * V_112 ;
int V_6 ;
struct V_40 V_41 ;
#ifdef F_124
struct V_233 V_234 ;
#endif
if ( V_156 -> V_228 != V_249 && V_156 -> V_228 != V_339 )
return 0 ;
F_176 ( & V_338 ) ;
V_6 = F_177 ( V_337 , V_156 -> V_228 , & V_338 ) ;
if ( V_6 == 0 )
V_112 = F_172 ( & V_338 , V_148 ) ;
else
V_112 = V_226 ;
F_178 ( & V_338 ) ;
#ifdef F_124
F_125 ( & V_41 , V_42 , V_235 , & V_234 ) ;
V_41 . V_236 . V_237 . V_234 -> V_210 = V_156 -> V_228 ;
V_41 . V_236 . V_237 . V_234 -> V_340 = V_337 -> V_341 ;
F_179 ( V_337 , & V_41 . V_236 , NULL ) ;
#endif
V_6 = V_185 ( V_112 , V_148 -> V_159 , V_87 , & V_41 ) ;
if ( V_6 != 0 )
F_180 ( V_337 , V_6 , 0 ) ;
return V_6 ;
}
static int F_181 ( struct V_149 * V_150 ,
char T_5 * V_342 ,
int T_5 * V_343 , unsigned V_108 )
{
struct V_147 * V_148 ;
char * V_344 = L_4 ;
int V_317 = 1 ;
int V_6 = 0 ;
V_148 = V_150 -> V_156 -> V_157 ;
if ( V_148 -> V_212 != NULL ) {
V_344 = V_148 -> V_212 ;
V_317 = strlen ( V_344 ) + 1 ;
}
if ( V_317 > V_108 )
V_6 = - V_345 ;
else if ( F_182 ( V_342 , V_344 , V_317 ) != 0 )
V_6 = - V_346 ;
if ( F_183 ( V_317 , V_343 ) != 0 )
V_6 = - V_346 ;
return V_6 ;
}
static int F_184 ( struct V_149 * V_150 ,
struct V_336 * V_337 , T_3 * V_163 )
{
struct V_326 V_338 ;
struct V_147 * V_148 = NULL ;
char * V_47 ;
int V_210 = V_347 ;
T_3 V_348 = 0 ;
int V_6 ;
if ( V_337 != NULL ) {
if ( V_337 -> V_247 == F_185 ( V_349 ) )
V_210 = V_249 ;
else if ( V_337 -> V_247 == F_185 ( V_350 ) )
V_210 = V_339 ;
}
if ( V_210 == V_347 && V_150 != NULL )
V_210 = V_150 -> V_156 -> V_228 ;
if ( V_210 == V_245 ) {
V_148 = V_150 -> V_156 -> V_157 ;
V_348 = F_70 ( V_148 -> V_161 ) ;
} else if ( V_210 == V_249 || V_210 == V_339 ) {
if ( V_150 != NULL && V_150 -> V_156 != NULL )
V_148 = V_150 -> V_156 -> V_157 ;
F_176 ( & V_338 ) ;
V_6 = F_177 ( V_337 , V_210 , & V_338 ) ;
if ( V_6 == 0 ) {
V_47 = F_172 ( & V_338 , V_148 ) ;
V_348 = F_70 ( V_47 ) ;
}
F_178 ( & V_338 ) ;
}
* V_163 = V_348 ;
if ( V_348 == 0 )
return - V_139 ;
return 0 ;
}
static void F_186 ( struct V_150 * V_156 , struct V_149 * V_351 )
{
struct V_147 * V_148 ;
if ( V_156 == NULL ||
( V_156 -> V_228 != V_249 && V_156 -> V_228 != V_339 ) )
return;
V_148 = V_156 -> V_157 ;
V_148 -> V_159 = V_148 -> V_161 = F_22 () ;
}
static int F_187 ( struct V_150 * V_156 , struct V_336 * V_337 ,
struct V_352 * V_353 )
{
T_6 V_210 = V_156 -> V_228 ;
struct V_109 * V_110 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_326 V_338 ;
struct V_213 V_354 ;
struct V_355 * V_356 ;
char * V_47 ;
char * V_357 ;
int V_6 ;
struct V_40 V_41 ;
#ifdef F_124
struct V_233 V_234 ;
#endif
if ( V_210 == V_339 && V_337 -> V_247 == F_185 ( V_349 ) )
V_210 = V_249 ;
F_176 ( & V_338 ) ;
V_6 = F_177 ( V_337 , V_210 , & V_338 ) ;
if ( V_6 == 0 )
V_47 = F_172 ( & V_338 , V_148 ) ;
else
V_47 = V_358 . V_50 ;
F_178 ( & V_338 ) ;
#ifdef F_124
F_125 ( & V_41 , V_42 , V_235 , & V_234 ) ;
V_41 . V_236 . V_237 . V_234 -> V_210 = V_210 ;
V_41 . V_236 . V_237 . V_234 -> V_340 = V_337 -> V_341 ;
F_179 ( V_337 , & V_41 . V_236 , NULL ) ;
#endif
V_6 = V_185 ( V_47 , V_148 -> V_159 , V_87 , & V_41 ) ;
if ( V_6 != 0 )
return V_6 ;
V_353 -> V_359 = F_70 ( V_47 ) ;
V_356 = F_188 ( V_337 ) ;
V_354 . V_219 . V_220 = V_356 -> V_360 ;
F_48 () ;
V_357 = F_115 ( & V_354 ) ;
F_50 () ;
if ( V_357 == NULL ) {
V_110 = F_47 ( V_47 ) ;
V_6 = F_189 ( V_353 , & V_110 -> V_229 ) ;
} else
F_190 ( V_353 ) ;
return V_6 ;
}
static void F_191 ( struct V_150 * V_156 ,
const struct V_352 * V_353 )
{
struct V_147 * V_148 = V_156 -> V_157 ;
if ( V_353 -> V_359 != 0 )
V_148 -> V_212 = F_94 ( V_353 -> V_359 ) ;
else
V_148 -> V_212 = NULL ;
}
static int F_192 ( struct V_361 * V_361 , const struct V_95 * V_95 ,
unsigned long V_72 )
{
V_361 -> V_96 = F_14 ( V_95 -> V_96 ) ;
return 0 ;
}
static void F_193 ( struct V_361 * V_361 )
{
V_361 -> V_96 = NULL ;
}
static int F_194 ( T_7 V_362 ,
const struct V_95 * V_95 , T_8 V_363 )
{
struct V_361 * V_364 ;
struct V_40 V_41 ;
char * V_24 = F_14 ( V_95 -> V_96 ) ;
V_364 = F_195 ( V_362 ) ;
if ( V_364 == NULL )
return - V_139 ;
if ( V_364 -> V_96 == NULL )
return 0 ;
if ( V_24 == NULL )
return - V_51 ;
#ifdef F_124
F_16 ( & V_41 , V_42 , V_365 ) ;
V_41 . V_236 . V_237 . V_366 . V_361 = V_364 -> V_367 ;
V_41 . V_236 . V_237 . V_366 . V_368 = V_364 -> V_369 ;
#endif
return V_185 ( V_24 , V_364 -> V_96 ,
V_44 , & V_41 ) ;
}
static int F_196 ( T_3 V_370 , T_3 V_77 , char * V_371 , void * * V_372 )
{
char * * V_373 = ( char * * ) V_372 ;
* V_373 = NULL ;
if ( V_370 != V_374 && V_370 != V_375 )
return - V_139 ;
if ( V_77 != V_376 && V_77 != V_377 )
return - V_139 ;
* V_373 = F_3 ( V_371 , 0 ) ;
return 0 ;
}
static int F_197 ( struct V_378 * V_379 )
{
struct V_380 * V_381 ;
int V_382 ;
for ( V_382 = 0 ; V_382 < V_379 -> V_383 ; V_382 ++ ) {
V_381 = & V_379 -> V_384 [ V_382 ] ;
if ( V_381 -> type == V_374 || V_381 -> type == V_375 )
return 1 ;
}
return 0 ;
}
static int F_198 ( T_3 V_163 , T_3 V_370 , T_3 V_77 , void * V_372 ,
struct V_385 * V_386 )
{
char * V_14 ;
char * V_373 = V_372 ;
if ( ! V_373 ) {
F_199 ( V_386 , V_387 , V_388 ,
L_5 ) ;
return - V_184 ;
}
if ( V_370 != V_374 && V_370 != V_375 )
return 0 ;
V_14 = F_94 ( V_163 ) ;
if ( V_77 == V_376 )
return ( V_373 == V_14 ) ;
if ( V_77 == V_377 )
return ( V_373 != V_14 ) ;
return 0 ;
}
static void F_200 ( void * V_372 )
{
}
static int F_201 ( T_3 V_163 , char * * V_389 , T_3 * V_390 )
{
char * V_47 = F_94 ( V_163 ) ;
if ( V_389 )
* V_389 = V_47 ;
* V_390 = strlen ( V_47 ) ;
return 0 ;
}
static int F_202 ( const char * V_389 , T_3 V_390 , T_3 * V_163 )
{
* V_163 = F_70 ( V_389 ) ;
return 0 ;
}
static void F_203 ( char * V_389 , T_3 V_390 )
{
}
static int F_204 ( struct V_2 * V_2 , void * V_391 , T_3 V_392 )
{
return F_126 ( V_2 , V_115 , V_391 , V_392 , 0 ) ;
}
static int F_205 ( struct V_4 * V_4 , void * V_391 , T_3 V_392 )
{
return F_206 ( V_4 , V_133 , V_391 , V_392 , 0 ) ;
}
static int F_207 ( struct V_2 * V_2 , void * * V_391 , T_3 * V_392 )
{
int V_108 = 0 ;
V_108 = F_66 ( V_2 , V_115 , V_391 , true ) ;
if ( V_108 < 0 )
return V_108 ;
* V_392 = V_108 ;
return 0 ;
}
static T_9 void F_208 ( void )
{
F_6 ( & V_358 . V_28 ) ;
F_6 ( & V_60 . V_28 ) ;
F_6 ( & V_49 . V_28 ) ;
F_6 ( & V_310 . V_28 ) ;
F_6 ( & V_143 . V_28 ) ;
F_6 ( & V_319 . V_28 ) ;
F_8 ( & V_358 . V_27 ) ;
F_8 ( & V_60 . V_27 ) ;
F_8 ( & V_310 . V_27 ) ;
F_8 ( & V_49 . V_27 ) ;
F_8 ( & V_143 . V_27 ) ;
F_8 ( & V_319 . V_27 ) ;
F_209 ( & V_358 . V_36 , & V_393 ) ;
F_209 ( & V_60 . V_36 , & V_393 ) ;
F_209 ( & V_310 . V_36 , & V_393 ) ;
F_209 ( & V_49 . V_36 , & V_393 ) ;
F_209 ( & V_143 . V_36 , & V_393 ) ;
F_209 ( & V_319 . V_36 , & V_393 ) ;
}
static T_9 int F_210 ( void )
{
struct V_95 * V_95 ;
struct V_20 * V_24 ;
if ( ! F_211 ( & V_394 ) )
return 0 ;
V_24 = F_7 ( V_49 . V_50 ,
V_49 . V_50 , V_12 ) ;
if ( V_24 == NULL )
return - V_35 ;
F_127 ( V_395 L_6 ) ;
V_95 = (struct V_95 * ) V_102 -> V_95 ;
V_95 -> V_96 = V_24 ;
F_208 () ;
if ( F_212 ( & V_394 ) )
F_213 ( L_7 ) ;
return 0 ;
}

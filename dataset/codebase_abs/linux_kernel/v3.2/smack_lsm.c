static char * F_1 ( const char * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
int V_6 ;
char V_7 [ V_8 ] ;
if ( V_3 -> V_9 -> V_10 == NULL )
return NULL ;
V_6 = V_3 -> V_9 -> V_10 ( V_5 , V_1 , V_7 , V_8 ) ;
if ( V_6 < 0 )
return NULL ;
return F_2 ( V_7 , V_6 ) ;
}
struct V_11 * F_3 ( char * V_12 )
{
struct V_11 * V_13 ;
V_13 = F_4 ( sizeof( struct V_11 ) , V_14 ) ;
if ( V_13 == NULL )
return NULL ;
V_13 -> V_15 = V_12 ;
V_13 -> V_16 = 0 ;
F_5 ( & V_13 -> V_17 ) ;
return V_13 ;
}
static struct V_18 * F_6 ( char * V_19 , char * V_20 , T_1 V_21 )
{
struct V_18 * V_22 ;
V_22 = F_4 ( sizeof( struct V_18 ) , V_21 ) ;
if ( V_22 == NULL )
return NULL ;
V_22 -> V_23 = V_19 ;
V_22 -> V_24 = V_20 ;
F_7 ( & V_22 -> V_25 ) ;
F_5 ( & V_22 -> V_26 ) ;
return V_22 ;
}
static int F_8 ( struct V_27 * V_28 , struct V_27 * V_29 ,
T_1 V_21 )
{
struct V_30 * V_31 ;
struct V_30 * V_32 ;
int V_6 = 0 ;
F_7 ( V_28 ) ;
F_9 (orp, ohead, list) {
V_31 = F_4 ( sizeof( struct V_30 ) , V_21 ) ;
if ( V_31 == NULL ) {
V_6 = - V_33 ;
break;
}
* V_31 = * V_32 ;
F_10 ( & V_31 -> V_34 , V_28 ) ;
}
return V_6 ;
}
static int F_11 ( struct V_35 * V_36 , unsigned int V_37 )
{
int V_6 ;
struct V_38 V_39 ;
char * V_22 ;
V_6 = F_12 ( V_36 , V_37 ) ;
if ( V_6 != 0 )
return V_6 ;
V_22 = F_13 ( F_14 ( V_36 ) ) ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_36 ) ;
V_6 = F_17 ( V_22 , V_42 , & V_39 ) ;
return V_6 ;
}
static int F_18 ( struct V_35 * V_43 )
{
int V_6 ;
struct V_38 V_39 ;
char * V_22 ;
V_6 = F_19 ( V_43 ) ;
if ( V_6 != 0 )
return V_6 ;
V_22 = F_13 ( F_14 ( V_43 ) ) ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_43 ) ;
V_6 = F_17 ( V_22 , V_42 , & V_39 ) ;
return V_6 ;
}
static int F_20 ( int V_44 )
{
int V_6 = 0 ;
char * V_45 = F_21 () ;
if ( F_22 ( V_46 ) )
return 0 ;
if ( V_45 != V_47 . V_48 )
V_6 = - V_49 ;
return V_6 ;
}
static int F_23 ( struct V_50 * V_51 )
{
struct V_52 * V_53 ;
V_53 = F_4 ( sizeof( struct V_52 ) , V_14 ) ;
if ( V_53 == NULL )
return - V_33 ;
V_53 -> V_54 = V_47 . V_48 ;
V_53 -> V_55 = V_47 . V_48 ;
V_53 -> V_56 = V_47 . V_48 ;
V_53 -> V_57 = V_58 . V_48 ;
V_53 -> V_59 = 0 ;
F_24 ( & V_53 -> V_60 ) ;
V_51 -> V_61 = V_53 ;
return 0 ;
}
static void F_25 ( struct V_50 * V_51 )
{
F_26 ( V_51 -> V_61 ) ;
V_51 -> V_61 = NULL ;
}
static int F_27 ( char * V_62 , char * V_63 )
{
char * V_64 , * V_65 , * V_66 , * V_5 ;
V_66 = ( char * ) F_28 ( V_14 ) ;
if ( V_66 == NULL )
return - V_33 ;
for ( V_64 = V_62 , V_65 = V_62 ; V_65 != NULL ; V_64 = V_65 + 1 ) {
if ( strstr ( V_64 , V_67 ) == V_64 )
V_5 = V_63 ;
else if ( strstr ( V_64 , V_68 ) == V_64 )
V_5 = V_63 ;
else if ( strstr ( V_64 , V_69 ) == V_64 )
V_5 = V_63 ;
else if ( strstr ( V_64 , V_70 ) == V_64 )
V_5 = V_63 ;
else
V_5 = V_66 ;
V_65 = strchr ( V_64 , ',' ) ;
if ( V_65 != NULL )
* V_65 = '\0' ;
if ( * V_5 != '\0' )
strcat ( V_5 , L_1 ) ;
strcat ( V_5 , V_64 ) ;
}
strcpy ( V_62 , V_66 ) ;
F_29 ( ( unsigned long ) V_66 ) ;
return 0 ;
}
static int F_30 ( struct V_50 * V_51 , int V_71 , void * V_72 )
{
struct V_4 * V_73 = V_51 -> V_74 ;
struct V_2 * V_2 = V_73 -> V_75 ;
struct V_52 * V_45 = V_51 -> V_61 ;
struct V_11 * V_13 ;
char * V_76 ;
char * V_65 ;
char * V_77 ;
F_31 ( & V_45 -> V_60 ) ;
if ( V_45 -> V_59 != 0 ) {
F_32 ( & V_45 -> V_60 ) ;
return 0 ;
}
V_45 -> V_59 = 1 ;
F_32 ( & V_45 -> V_60 ) ;
for ( V_76 = V_72 ; V_76 != NULL ; V_76 = V_65 ) {
V_65 = strchr ( V_76 , ',' ) ;
if ( V_65 != NULL )
* V_65 ++ = '\0' ;
if ( strncmp ( V_76 , V_69 , strlen ( V_69 ) ) == 0 ) {
V_76 += strlen ( V_69 ) ;
V_77 = F_2 ( V_76 , 0 ) ;
if ( V_77 != NULL )
V_45 -> V_57 = V_77 ;
} else if ( strncmp ( V_76 , V_68 , strlen ( V_68 ) ) == 0 ) {
V_76 += strlen ( V_68 ) ;
V_77 = F_2 ( V_76 , 0 ) ;
if ( V_77 != NULL )
V_45 -> V_56 = V_77 ;
} else if ( strncmp ( V_76 , V_67 ,
strlen ( V_67 ) ) == 0 ) {
V_76 += strlen ( V_67 ) ;
V_77 = F_2 ( V_76 , 0 ) ;
if ( V_77 != NULL )
V_45 -> V_55 = V_77 ;
} else if ( strncmp ( V_76 , V_70 , strlen ( V_70 ) ) == 0 ) {
V_76 += strlen ( V_70 ) ;
V_77 = F_2 ( V_76 , 0 ) ;
if ( V_77 != NULL )
V_45 -> V_54 = V_77 ;
}
}
V_13 = V_2 -> V_78 ;
if ( V_13 == NULL )
V_2 -> V_78 = F_3 ( V_45 -> V_54 ) ;
else
V_13 -> V_15 = V_45 -> V_54 ;
return 0 ;
}
static int F_33 ( struct V_4 * V_4 )
{
struct V_52 * V_79 = V_4 -> V_80 -> V_61 ;
int V_6 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
V_6 = F_17 ( V_79 -> V_56 , V_82 , & V_39 ) ;
return V_6 ;
}
static int F_35 ( char * V_83 , struct V_84 * V_84 ,
char * type , unsigned long V_71 , void * V_72 )
{
struct V_52 * V_79 = V_84 -> V_85 -> V_86 -> V_61 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , * V_84 ) ;
return F_17 ( V_79 -> V_56 , V_88 , & V_39 ) ;
}
static int F_37 ( struct V_89 * V_85 , int V_71 )
{
struct V_52 * V_79 ;
struct V_38 V_39 ;
struct V_84 V_84 ;
V_84 . V_4 = V_85 -> V_90 ;
V_84 . V_85 = V_85 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_84 ) ;
V_79 = V_85 -> V_86 -> V_61 ;
return F_17 ( V_79 -> V_56 , V_88 , & V_39 ) ;
}
static int F_38 ( struct V_91 * V_92 )
{
struct V_2 * V_2 = V_92 -> V_93 -> V_94 . V_4 -> V_75 ;
struct V_18 * V_95 = V_92 -> V_96 -> V_97 ;
struct V_11 * V_13 ;
int V_6 ;
V_6 = F_39 ( V_92 ) ;
if ( V_6 != 0 )
return V_6 ;
if ( V_92 -> V_98 )
return 0 ;
V_13 = V_2 -> V_78 ;
if ( V_13 -> V_23 == NULL || V_13 -> V_23 == V_95 -> V_23 )
return 0 ;
if ( V_92 -> V_99 )
return - V_100 ;
V_95 -> V_23 = V_13 -> V_23 ;
V_92 -> V_101 |= V_102 ;
return 0 ;
}
static void F_40 ( struct V_91 * V_92 )
{
struct V_18 * V_95 = V_92 -> V_96 -> V_97 ;
if ( V_95 -> V_23 != V_95 -> V_24 )
V_103 -> V_104 = 0 ;
}
static int F_41 ( struct V_91 * V_92 )
{
struct V_18 * V_22 = F_42 () ;
int V_105 = F_43 ( V_92 ) ;
if ( ! V_105 && ( V_22 -> V_23 != V_22 -> V_24 ) )
V_105 = 1 ;
return V_105 ;
}
static int F_44 ( struct V_2 * V_2 )
{
V_2 -> V_78 = F_3 ( F_21 () ) ;
if ( V_2 -> V_78 == NULL )
return - V_33 ;
return 0 ;
}
static void F_45 ( struct V_2 * V_2 )
{
F_26 ( V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
}
static int F_46 ( struct V_2 * V_2 , struct V_2 * V_106 ,
const struct V_107 * V_107 , char * * V_1 ,
void * * V_108 , T_2 * V_109 )
{
struct V_110 * V_111 ;
char * V_112 = F_21 () ;
char * V_13 = F_47 ( V_2 ) ;
char * V_113 = F_47 ( V_106 ) ;
int V_114 ;
if ( V_1 ) {
* V_1 = F_48 ( V_115 , V_14 ) ;
if ( * V_1 == NULL )
return - V_33 ;
}
if ( V_108 ) {
V_111 = F_49 ( V_112 ) ;
F_50 () ;
V_114 = F_51 ( V_112 , V_113 , & V_111 -> V_25 ) ;
F_52 () ;
if ( V_114 > 0 && ( ( V_114 & V_116 ) != 0 ) &&
F_53 ( V_106 ) )
V_13 = V_113 ;
* V_108 = F_48 ( V_13 , V_14 ) ;
if ( * V_108 == NULL )
return - V_33 ;
}
if ( V_109 )
* V_109 = strlen ( V_13 ) + 1 ;
return 0 ;
}
static int F_54 ( struct V_4 * V_117 , struct V_2 * V_106 ,
struct V_4 * V_118 )
{
char * V_13 ;
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_117 ) ;
V_13 = F_47 ( V_117 -> V_75 ) ;
V_6 = F_17 ( V_13 , V_88 , & V_39 ) ;
if ( V_6 == 0 && V_118 -> V_75 != NULL ) {
V_13 = F_47 ( V_118 -> V_75 ) ;
F_34 ( & V_39 , V_118 ) ;
V_6 = F_17 ( V_13 , V_88 , & V_39 ) ;
}
return V_6 ;
}
static int F_55 ( struct V_2 * V_106 , struct V_4 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_75 ;
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
V_6 = F_17 ( F_47 ( V_3 ) , V_88 , & V_39 ) ;
if ( V_6 == 0 ) {
F_34 ( & V_39 , NULL ) ;
F_56 ( & V_39 , V_106 ) ;
V_6 = F_17 ( F_47 ( V_106 ) , V_88 , & V_39 ) ;
}
return V_6 ;
}
static int F_57 ( struct V_2 * V_106 , struct V_4 * V_4 )
{
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
V_6 = F_17 ( F_47 ( V_4 -> V_75 ) , V_88 , & V_39 ) ;
if ( V_6 == 0 ) {
F_34 ( & V_39 , NULL ) ;
F_56 ( & V_39 , V_106 ) ;
V_6 = F_17 ( F_47 ( V_106 ) , V_88 , & V_39 ) ;
}
return V_6 ;
}
static int F_58 ( struct V_2 * V_119 ,
struct V_4 * V_117 ,
struct V_2 * V_120 ,
struct V_4 * V_118 )
{
int V_6 ;
char * V_13 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_117 ) ;
V_13 = F_47 ( V_117 -> V_75 ) ;
V_6 = F_17 ( V_13 , V_42 , & V_39 ) ;
if ( V_6 == 0 && V_118 -> V_75 != NULL ) {
V_13 = F_47 ( V_118 -> V_75 ) ;
F_34 ( & V_39 , V_118 ) ;
V_6 = F_17 ( V_13 , V_42 , & V_39 ) ;
}
return V_6 ;
}
static int F_59 ( struct V_2 * V_2 , int V_121 )
{
struct V_38 V_39 ;
int V_122 = V_121 & V_123 ;
V_121 &= ( V_82 | V_88 | V_124 | V_125 ) ;
if ( V_121 == 0 )
return 0 ;
if ( V_122 )
return - V_126 ;
F_15 ( & V_39 , V_40 , V_127 ) ;
F_56 ( & V_39 , V_2 ) ;
return F_17 ( F_47 ( V_2 ) , V_121 , & V_39 ) ;
}
static int F_60 ( struct V_4 * V_4 , struct V_128 * V_128 )
{
struct V_38 V_39 ;
if ( V_128 -> V_129 & V_130 )
return 0 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
return F_17 ( F_47 ( V_4 -> V_75 ) , V_88 , & V_39 ) ;
}
static int F_61 ( struct V_89 * V_85 , struct V_4 * V_4 )
{
struct V_38 V_39 ;
struct V_84 V_84 ;
V_84 . V_4 = V_4 ;
V_84 . V_85 = V_85 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_84 ) ;
return F_17 ( F_47 ( V_4 -> V_75 ) , V_82 , & V_39 ) ;
}
static int F_62 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_108 , T_2 V_131 , int V_71 )
{
struct V_38 V_39 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_132 ) == 0 ||
strcmp ( V_1 , V_133 ) == 0 ||
strcmp ( V_1 , V_134 ) == 0 ||
strcmp ( V_1 , V_135 ) == 0 ||
strcmp ( V_1 , V_136 ) == 0 ) {
if ( ! F_22 ( V_137 ) )
V_6 = - V_100 ;
if ( V_131 == 0 || V_131 >= V_8 ||
F_2 ( V_108 , V_131 ) == NULL )
V_6 = - V_138 ;
} else if ( strcmp ( V_1 , V_139 ) == 0 ) {
if ( ! F_22 ( V_137 ) )
V_6 = - V_100 ;
if ( V_131 != V_140 ||
strncmp ( V_108 , V_141 , V_140 ) != 0 )
V_6 = - V_138 ;
} else
V_6 = F_63 ( V_4 , V_1 , V_108 , V_131 , V_71 ) ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_17 ( F_47 ( V_4 -> V_75 ) , V_88 , & V_39 ) ;
return V_6 ;
}
static void F_64 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_108 , T_2 V_131 , int V_71 )
{
char * V_77 ;
struct V_11 * V_13 = V_4 -> V_75 -> V_78 ;
if ( strcmp ( V_1 , V_132 ) == 0 ) {
V_77 = F_2 ( V_108 , V_131 ) ;
if ( V_77 != NULL )
V_13 -> V_15 = V_77 ;
else
V_13 -> V_15 = V_142 . V_48 ;
} else if ( strcmp ( V_1 , V_135 ) == 0 ) {
V_77 = F_2 ( V_108 , V_131 ) ;
if ( V_77 != NULL )
V_13 -> V_23 = V_77 ;
else
V_13 -> V_23 = V_142 . V_48 ;
} else if ( strcmp ( V_1 , V_136 ) == 0 ) {
V_77 = F_2 ( V_108 , V_131 ) ;
if ( V_77 != NULL )
V_13 -> V_143 = V_77 ;
else
V_13 -> V_143 = V_142 . V_48 ;
} else if ( strcmp ( V_1 , V_139 ) == 0 )
V_13 -> V_16 |= V_144 ;
return;
}
static int F_65 ( struct V_4 * V_4 , const char * V_1 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
return F_17 ( F_47 ( V_4 -> V_75 ) , V_82 , & V_39 ) ;
}
static int F_66 ( struct V_4 * V_4 , const char * V_1 )
{
struct V_11 * V_13 ;
struct V_38 V_39 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_132 ) == 0 ||
strcmp ( V_1 , V_133 ) == 0 ||
strcmp ( V_1 , V_134 ) == 0 ||
strcmp ( V_1 , V_135 ) == 0 ||
strcmp ( V_1 , V_139 ) == 0 ||
strcmp ( V_1 , V_136 ) ) {
if ( ! F_22 ( V_137 ) )
V_6 = - V_100 ;
} else
V_6 = F_67 ( V_4 , V_1 ) ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_17 ( F_47 ( V_4 -> V_75 ) , V_88 , & V_39 ) ;
if ( V_6 == 0 ) {
V_13 = V_4 -> V_75 -> V_78 ;
V_13 -> V_23 = NULL ;
V_13 -> V_143 = NULL ;
}
return V_6 ;
}
static int F_68 ( const struct V_2 * V_2 ,
const char * V_1 , void * * V_145 ,
bool V_146 )
{
struct V_147 * V_148 ;
struct V_149 * V_150 ;
struct V_50 * V_79 ;
struct V_2 * V_3 = (struct V_2 * ) V_2 ;
char * V_13 ;
int V_151 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_115 ) == 0 ) {
V_13 = F_47 ( V_2 ) ;
V_151 = strlen ( V_13 ) + 1 ;
* V_145 = V_13 ;
return V_151 ;
}
V_79 = V_3 -> V_152 ;
if ( V_79 -> V_153 != V_154 )
return - V_155 ;
V_150 = F_69 ( V_3 ) ;
if ( V_150 == NULL || V_150 -> V_156 == NULL )
return - V_155 ;
V_148 = V_150 -> V_156 -> V_157 ;
if ( strcmp ( V_1 , V_158 ) == 0 )
V_13 = V_148 -> V_159 ;
else if ( strcmp ( V_1 , V_160 ) == 0 )
V_13 = V_148 -> V_161 ;
else
return - V_155 ;
V_151 = strlen ( V_13 ) + 1 ;
if ( V_6 == 0 ) {
* V_145 = V_13 ;
V_6 = V_151 ;
}
return V_6 ;
}
static int F_70 ( struct V_2 * V_2 , char * V_145 ,
T_2 V_162 )
{
int V_109 = strlen ( V_132 ) ;
if ( V_145 != NULL && V_109 <= V_162 ) {
memcpy ( V_145 , V_132 , V_109 ) ;
return V_109 ;
}
return - V_138 ;
}
static void F_71 ( const struct V_2 * V_2 , T_3 * V_163 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
* V_163 = F_72 ( V_13 -> V_15 ) ;
}
static int F_73 ( struct V_93 * V_93 , int V_121 )
{
return 0 ;
}
static int F_74 ( struct V_93 * V_93 )
{
V_93 -> V_164 = F_21 () ;
return 0 ;
}
static void F_75 ( struct V_93 * V_93 )
{
V_93 -> V_164 = NULL ;
}
static int F_76 ( struct V_93 * V_93 , unsigned int V_165 ,
unsigned long V_166 )
{
int V_6 = 0 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_93 -> V_94 ) ;
if ( F_77 ( V_165 ) & V_167 )
V_6 = F_17 ( V_93 -> V_164 , V_88 , & V_39 ) ;
if ( V_6 == 0 && ( F_77 ( V_165 ) & V_168 ) )
V_6 = F_17 ( V_93 -> V_164 , V_82 , & V_39 ) ;
return V_6 ;
}
static int F_78 ( struct V_93 * V_93 , unsigned int V_165 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_93 -> V_94 ) ;
return F_17 ( V_93 -> V_164 , V_88 , & V_39 ) ;
}
static int F_79 ( struct V_93 * V_93 , unsigned int V_165 ,
unsigned long V_166 )
{
struct V_38 V_39 ;
int V_6 = 0 ;
switch ( V_165 ) {
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_93 -> V_94 ) ;
V_6 = F_17 ( V_93 -> V_164 , V_88 , & V_39 ) ;
break;
default:
break;
}
return V_6 ;
}
static int F_80 ( struct V_93 * V_93 ,
unsigned long V_174 , unsigned long V_175 ,
unsigned long V_71 , unsigned long V_176 ,
unsigned long V_177 )
{
struct V_110 * V_111 ;
struct V_30 * V_178 ;
struct V_18 * V_22 ;
char * V_45 ;
char * V_179 ;
char * V_180 ;
struct V_11 * V_13 ;
struct V_4 * V_5 ;
int V_114 ;
int V_181 ;
int V_182 ;
int V_6 ;
V_6 = F_81 ( V_93 , V_174 , V_175 , V_71 , V_176 , V_177 ) ;
if ( V_6 || V_177 )
return V_6 ;
if ( V_93 == NULL || V_93 -> V_183 == NULL )
return 0 ;
V_5 = V_93 -> V_183 ;
if ( V_5 -> V_75 == NULL )
return 0 ;
V_13 = V_5 -> V_75 -> V_78 ;
if ( V_13 -> V_143 == NULL )
return 0 ;
V_179 = V_13 -> V_143 ;
V_22 = F_42 () ;
V_45 = F_21 () ;
V_111 = F_49 ( V_45 ) ;
V_6 = 0 ;
F_50 () ;
F_9 (srp, &skp->smk_rules, list) {
V_180 = V_178 -> V_184 ;
if ( V_179 == V_180 )
continue;
V_114 = F_51 ( V_178 -> V_185 , V_180 ,
& V_22 -> V_25 ) ;
if ( V_114 == - V_186 )
V_114 = V_178 -> V_187 ;
else
V_114 &= V_178 -> V_187 ;
if ( V_114 == 0 )
continue;
V_111 = F_49 ( V_179 ) ;
V_181 = F_51 ( V_179 , V_180 , & V_111 -> V_25 ) ;
if ( V_181 == - V_186 ) {
V_6 = - V_49 ;
break;
}
V_182 = F_51 ( V_179 , V_180 , & V_22 -> V_25 ) ;
if ( V_182 != - V_186 )
V_181 &= V_182 ;
if ( ( V_114 | V_181 ) != V_181 ) {
V_6 = - V_49 ;
break;
}
}
F_52 () ;
return V_6 ;
}
static int F_82 ( struct V_93 * V_93 )
{
V_93 -> V_164 = F_21 () ;
return 0 ;
}
static int F_83 ( struct V_35 * V_188 ,
struct V_189 * V_190 , int V_191 )
{
struct V_93 * V_93 ;
int V_6 ;
char * V_22 = F_13 ( V_188 -> V_96 -> V_97 ) ;
struct V_38 V_39 ;
V_93 = F_84 ( V_190 , struct V_93 , V_192 ) ;
V_6 = V_187 ( V_93 -> V_164 , V_22 , V_88 , NULL ) ;
if ( V_6 != 0 && F_85 ( V_188 , V_46 ) )
V_6 = 0 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_188 ) ;
F_86 ( V_93 -> V_164 , V_22 , V_88 , V_6 , & V_39 ) ;
return V_6 ;
}
static int F_87 ( struct V_93 * V_93 )
{
int V_114 = 0 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_36 ( & V_39 , V_93 -> V_94 ) ;
if ( V_93 -> V_193 & V_194 )
V_114 = V_82 ;
if ( V_93 -> V_193 & V_195 )
V_114 |= V_88 ;
return F_17 ( V_93 -> V_164 , V_114 , & V_39 ) ;
}
static int F_88 ( struct V_93 * V_93 , const struct V_96 * V_96 )
{
struct V_11 * V_13 = V_93 -> V_94 . V_4 -> V_75 -> V_78 ;
V_93 -> V_164 = V_13 -> V_15 ;
return 0 ;
}
static int F_89 ( struct V_96 * V_96 , T_1 V_21 )
{
struct V_18 * V_22 ;
V_22 = F_6 ( NULL , NULL , V_21 ) ;
if ( V_22 == NULL )
return - V_33 ;
V_96 -> V_97 = V_22 ;
return 0 ;
}
static void F_90 ( struct V_96 * V_96 )
{
struct V_18 * V_22 = V_96 -> V_97 ;
struct V_30 * V_196 ;
struct V_27 * V_197 ;
struct V_27 * V_198 ;
if ( V_22 == NULL )
return;
V_96 -> V_97 = NULL ;
F_91 (l, n, &tsp->smk_rules) {
V_196 = F_92 ( V_197 , struct V_30 , V_34 ) ;
F_93 ( & V_196 -> V_34 ) ;
F_26 ( V_196 ) ;
}
F_26 ( V_22 ) ;
}
static int F_94 ( struct V_96 * V_199 , const struct V_96 * V_200 ,
T_1 V_21 )
{
struct V_18 * V_201 = V_200 -> V_97 ;
struct V_18 * V_202 ;
int V_6 ;
V_202 = F_6 ( V_201 -> V_23 , V_201 -> V_23 , V_21 ) ;
if ( V_202 == NULL )
return - V_33 ;
V_6 = F_8 ( & V_202 -> V_25 , & V_201 -> V_25 , V_21 ) ;
if ( V_6 != 0 )
return V_6 ;
V_199 -> V_97 = V_202 ;
return 0 ;
}
static void F_95 ( struct V_96 * V_199 , const struct V_96 * V_200 )
{
struct V_18 * V_201 = V_200 -> V_97 ;
struct V_18 * V_202 = V_199 -> V_97 ;
V_202 -> V_23 = V_201 -> V_23 ;
V_202 -> V_24 = V_201 -> V_23 ;
F_5 ( & V_202 -> V_26 ) ;
F_7 ( & V_202 -> V_25 ) ;
}
static int F_96 ( struct V_96 * V_199 , T_3 V_163 )
{
struct V_18 * V_202 = V_199 -> V_97 ;
char * V_12 = F_97 ( V_163 ) ;
if ( V_12 == NULL )
return - V_138 ;
V_202 -> V_23 = V_12 ;
return 0 ;
}
static int F_98 ( struct V_96 * V_199 ,
struct V_2 * V_2 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
struct V_18 * V_22 = V_199 -> V_97 ;
V_22 -> V_24 = V_13 -> V_15 ;
V_22 -> V_23 = V_13 -> V_15 ;
return 0 ;
}
static int F_99 ( struct V_35 * V_203 , int V_204 ,
const char * V_205 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_205 , V_41 ) ;
F_16 ( & V_39 , V_203 ) ;
return F_17 ( F_13 ( F_14 ( V_203 ) ) , V_204 , & V_39 ) ;
}
static int F_100 ( struct V_35 * V_203 , T_4 V_206 )
{
return F_99 ( V_203 , V_88 , V_40 ) ;
}
static int F_101 ( struct V_35 * V_203 )
{
return F_99 ( V_203 , V_82 , V_40 ) ;
}
static int F_102 ( struct V_35 * V_203 )
{
return F_99 ( V_203 , V_82 , V_40 ) ;
}
static void F_103 ( struct V_35 * V_203 , T_3 * V_163 )
{
* V_163 = F_72 ( F_13 ( F_14 ( V_203 ) ) ) ;
}
static int F_104 ( struct V_35 * V_203 , int V_207 )
{
int V_6 ;
V_6 = F_105 ( V_203 , V_207 ) ;
if ( V_6 == 0 )
V_6 = F_99 ( V_203 , V_88 , V_40 ) ;
return V_6 ;
}
static int F_106 ( struct V_35 * V_203 , int V_208 )
{
int V_6 ;
V_6 = F_107 ( V_203 , V_208 ) ;
if ( V_6 == 0 )
V_6 = F_99 ( V_203 , V_88 , V_40 ) ;
return V_6 ;
}
static int F_108 ( struct V_35 * V_203 )
{
return F_99 ( V_203 , V_82 , V_40 ) ;
}
static int F_109 ( struct V_35 * V_203 )
{
int V_6 ;
V_6 = F_110 ( V_203 ) ;
if ( V_6 == 0 )
V_6 = F_99 ( V_203 , V_88 , V_40 ) ;
return V_6 ;
}
static int F_111 ( struct V_35 * V_203 )
{
return F_99 ( V_203 , V_82 , V_40 ) ;
}
static int F_112 ( struct V_35 * V_203 )
{
return F_99 ( V_203 , V_88 , V_40 ) ;
}
static int F_113 ( struct V_35 * V_203 , struct V_209 * V_210 ,
int V_211 , T_3 V_163 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_203 ) ;
if ( V_163 == 0 )
return F_17 ( F_13 ( F_14 ( V_203 ) ) , V_88 ,
& V_39 ) ;
return V_187 ( F_97 ( V_163 ) ,
F_13 ( F_14 ( V_203 ) ) , V_88 , & V_39 ) ;
}
static int F_114 ( struct V_35 * V_203 )
{
struct V_38 V_39 ;
char * V_45 = F_21 () ;
char * V_22 = F_115 ( F_14 ( V_203 ) ) ;
int V_6 ;
V_6 = V_187 ( V_22 , V_45 , V_88 , NULL ) ;
if ( V_6 == 0 )
goto V_212;
if ( F_22 ( V_46 ) || F_85 ( V_203 , V_46 ) )
V_6 = 0 ;
V_212:
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_203 ) ;
F_86 ( V_22 , V_45 , V_88 , V_6 , & V_39 ) ;
return V_6 ;
}
static void F_116 ( struct V_35 * V_203 , struct V_2 * V_2 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
V_13 -> V_15 = F_13 ( F_14 ( V_203 ) ) ;
}
static int F_117 ( struct V_150 * V_156 , int V_213 , T_1 V_214 )
{
char * V_112 = F_21 () ;
struct V_147 * V_148 ;
V_148 = F_4 ( sizeof( struct V_147 ) , V_214 ) ;
if ( V_148 == NULL )
return - V_33 ;
V_148 -> V_159 = V_112 ;
V_148 -> V_161 = V_112 ;
V_148 -> V_215 = NULL ;
V_156 -> V_157 = V_148 ;
return 0 ;
}
static void F_118 ( struct V_150 * V_156 )
{
F_26 ( V_156 -> V_157 ) ;
}
static char * F_119 ( struct V_216 * V_217 )
{
struct V_218 * V_219 ;
struct V_220 * V_221 = & V_217 -> V_222 ;
if ( V_221 -> V_223 == 0 )
return NULL ;
F_9 (snp, &smk_netlbladdr_list, list)
if ( ( & V_219 -> V_224 . V_222 ) -> V_223 ==
( V_221 -> V_223 & ( & V_219 -> V_225 ) -> V_223 ) ) {
if ( V_219 -> V_226 == V_227 )
return NULL ;
return V_219 -> V_226 ;
}
return NULL ;
}
static void F_120 ( char * V_228 , struct V_229 * V_230 )
{
unsigned char * V_64 ;
unsigned char V_231 ;
int V_232 ;
int V_6 ;
int V_233 ;
if ( ! V_228 )
return;
V_230 -> V_71 |= V_234 ;
V_230 -> V_235 . V_236 . V_232 = F_121 ( V_237 ) ;
V_230 -> V_235 . V_236 . V_232 -> V_238 = 0 ;
for ( V_232 = 1 , V_64 = V_228 , V_233 = 0 ; V_233 < V_8 ; V_64 ++ , V_233 ++ )
for ( V_231 = 0x80 ; V_231 != 0 ; V_231 >>= 1 , V_232 ++ ) {
if ( ( V_231 & * V_64 ) == 0 )
continue;
V_6 = F_122 ( V_230 -> V_235 . V_236 . V_232 ,
V_232 , V_237 ) ;
}
}
static void F_123 ( char * V_12 , struct V_229 * V_239 )
{
struct V_240 V_241 ;
int V_6 ;
V_239 -> V_242 = V_12 ;
V_239 -> V_71 = V_243 | V_244 ;
V_6 = F_124 ( V_12 , & V_241 ) ;
if ( V_6 == 0 ) {
V_239 -> V_235 . V_236 . V_245 = V_241 . V_246 ;
F_120 ( V_241 . V_247 , V_239 ) ;
} else {
V_239 -> V_235 . V_236 . V_245 = V_248 ;
F_120 ( V_12 , V_239 ) ;
}
}
static int F_125 ( struct V_150 * V_156 , int V_249 )
{
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_229 V_250 ;
int V_6 = 0 ;
F_126 () ;
F_127 ( V_156 ) ;
if ( V_148 -> V_161 == V_251 ||
V_249 == V_252 )
F_128 ( V_156 ) ;
else {
F_129 ( & V_250 ) ;
F_123 ( V_148 -> V_161 , & V_250 ) ;
V_6 = F_130 ( V_156 , V_156 -> V_253 , & V_250 ) ;
F_131 ( & V_250 ) ;
}
F_132 ( V_156 ) ;
F_133 () ;
return V_6 ;
}
static int F_134 ( struct V_150 * V_156 , struct V_216 * V_230 )
{
int V_6 ;
int V_254 ;
char * V_255 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_38 V_39 ;
F_50 () ;
V_255 = F_119 ( V_230 ) ;
if ( V_255 != NULL ) {
V_254 = V_252 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_256 ) ;
V_39 . V_257 . V_258 . V_259 . V_213 = V_230 -> V_260 ;
V_39 . V_257 . V_258 . V_259 . V_261 = V_230 -> V_262 ;
V_39 . V_257 . V_258 . V_259 . V_263 . V_264 = V_230 -> V_222 . V_223 ;
#endif
V_6 = V_187 ( V_148 -> V_161 , V_255 , V_88 , & V_39 ) ;
} else {
V_254 = V_265 ;
V_6 = 0 ;
}
F_52 () ;
if ( V_6 != 0 )
return V_6 ;
return F_125 ( V_156 , V_254 ) ;
}
static int F_136 ( struct V_2 * V_2 , const char * V_1 ,
const void * V_108 , T_2 V_131 , int V_71 )
{
char * V_45 ;
struct V_11 * V_77 = V_2 -> V_78 ;
struct V_147 * V_148 ;
struct V_149 * V_150 ;
int V_6 = 0 ;
if ( V_108 == NULL || V_131 > V_8 || V_131 == 0 )
return - V_49 ;
V_45 = F_2 ( V_108 , V_131 ) ;
if ( V_45 == NULL )
return - V_138 ;
if ( strcmp ( V_1 , V_115 ) == 0 ) {
V_77 -> V_15 = V_45 ;
V_77 -> V_16 |= V_266 ;
return 0 ;
}
if ( V_2 -> V_152 -> V_153 != V_154 )
return - V_155 ;
V_150 = F_69 ( V_2 ) ;
if ( V_150 == NULL || V_150 -> V_156 == NULL )
return - V_155 ;
V_148 = V_150 -> V_156 -> V_157 ;
if ( strcmp ( V_1 , V_158 ) == 0 )
V_148 -> V_159 = V_45 ;
else if ( strcmp ( V_1 , V_160 ) == 0 ) {
V_148 -> V_161 = V_45 ;
if ( V_150 -> V_156 -> V_253 != V_267 ) {
V_6 = F_125 ( V_150 -> V_156 , V_265 ) ;
if ( V_6 != 0 )
F_137 ( V_268
L_2 ,
V_40 , - V_6 ) ;
}
} else
return - V_155 ;
return 0 ;
}
static int F_138 ( struct V_149 * V_150 , int V_213 ,
int type , int V_269 , int V_270 )
{
if ( V_213 != V_271 || V_150 -> V_156 == NULL )
return 0 ;
return F_125 ( V_150 -> V_156 , V_265 ) ;
}
static int F_139 ( struct V_149 * V_150 , struct V_272 * V_230 ,
int V_273 )
{
if ( V_150 -> V_156 == NULL || V_150 -> V_156 -> V_253 != V_271 )
return 0 ;
if ( V_273 < sizeof( struct V_216 ) )
return - V_138 ;
return F_134 ( V_150 -> V_156 , (struct V_216 * ) V_230 ) ;
}
static int F_140 ( int V_71 )
{
int V_114 = 0 ;
if ( V_71 & V_274 )
V_114 |= V_82 ;
if ( V_71 & V_275 )
V_114 |= V_88 ;
if ( V_71 & V_276 )
V_114 |= V_124 ;
return V_114 ;
}
static int F_141 ( struct V_277 * V_278 )
{
V_278 -> V_97 = F_21 () ;
return 0 ;
}
static void F_142 ( struct V_277 * V_278 )
{
V_278 -> V_97 = NULL ;
}
static char * F_143 ( struct V_279 * V_280 )
{
return ( char * ) V_280 -> V_281 . V_97 ;
}
static int F_144 ( struct V_279 * V_280 )
{
struct V_282 * V_13 = & V_280 -> V_281 ;
V_13 -> V_97 = F_21 () ;
return 0 ;
}
static void F_145 ( struct V_279 * V_280 )
{
struct V_282 * V_13 = & V_280 -> V_281 ;
V_13 -> V_97 = NULL ;
}
static int F_146 ( struct V_279 * V_280 , int V_204 )
{
char * V_148 = F_143 ( V_280 ) ;
struct V_38 V_39 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_283 ) ;
V_39 . V_257 . V_258 . V_284 = V_280 -> V_281 . V_285 ;
#endif
return F_17 ( V_148 , V_204 , & V_39 ) ;
}
static int F_147 ( struct V_279 * V_280 , int V_286 )
{
int V_114 ;
V_114 = F_140 ( V_286 ) ;
return F_146 ( V_280 , V_114 ) ;
}
static int F_148 ( struct V_279 * V_280 , int V_165 )
{
int V_114 ;
switch ( V_165 ) {
case V_287 :
case V_288 :
V_114 = V_82 ;
break;
case V_289 :
case V_290 :
case V_291 :
case V_292 :
V_114 = V_42 ;
break;
case V_293 :
case V_294 :
return 0 ;
default:
return - V_138 ;
}
return F_146 ( V_280 , V_114 ) ;
}
static int F_149 ( struct V_279 * V_280 , char T_5 * V_295 ,
int V_286 )
{
int V_114 ;
V_114 = F_140 ( V_286 ) ;
return F_146 ( V_280 , V_114 ) ;
}
static char * F_150 ( struct V_296 * V_297 )
{
return ( char * ) V_297 -> V_298 . V_97 ;
}
static int F_151 ( struct V_296 * V_297 )
{
struct V_282 * V_13 = & V_297 -> V_298 ;
V_13 -> V_97 = F_21 () ;
return 0 ;
}
static void F_152 ( struct V_296 * V_297 )
{
struct V_282 * V_13 = & V_297 -> V_298 ;
V_13 -> V_97 = NULL ;
}
static int F_153 ( struct V_296 * V_297 , int V_204 )
{
char * V_148 = F_150 ( V_297 ) ;
struct V_38 V_39 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_283 ) ;
V_39 . V_257 . V_258 . V_284 = V_297 -> V_298 . V_285 ;
#endif
return F_17 ( V_148 , V_204 , & V_39 ) ;
}
static int F_154 ( struct V_296 * V_297 , int V_299 )
{
int V_114 ;
V_114 = F_140 ( V_299 ) ;
return F_153 ( V_297 , V_114 ) ;
}
static int F_155 ( struct V_296 * V_297 , int V_165 )
{
int V_114 ;
switch ( V_165 ) {
case V_300 :
case V_301 :
case V_302 :
case V_303 :
case V_304 :
case V_287 :
case V_305 :
V_114 = V_82 ;
break;
case V_306 :
case V_307 :
case V_292 :
case V_289 :
V_114 = V_42 ;
break;
case V_293 :
case V_308 :
return 0 ;
default:
return - V_138 ;
}
return F_153 ( V_297 , V_114 ) ;
}
static int F_156 ( struct V_296 * V_297 , struct V_309 * V_310 ,
unsigned V_311 , int V_312 )
{
return F_153 ( V_297 , V_42 ) ;
}
static int F_157 ( struct V_313 * V_314 )
{
struct V_282 * V_315 = & V_314 -> V_316 ;
V_315 -> V_97 = F_21 () ;
return 0 ;
}
static void F_158 ( struct V_313 * V_314 )
{
struct V_282 * V_315 = & V_314 -> V_316 ;
V_315 -> V_97 = NULL ;
}
static char * F_159 ( struct V_313 * V_314 )
{
return ( char * ) V_314 -> V_316 . V_97 ;
}
static int F_160 ( struct V_313 * V_314 , int V_204 )
{
char * V_317 = F_159 ( V_314 ) ;
struct V_38 V_39 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_283 ) ;
V_39 . V_257 . V_258 . V_284 = V_314 -> V_316 . V_285 ;
#endif
return F_17 ( V_317 , V_204 , & V_39 ) ;
}
static int F_161 ( struct V_313 * V_314 , int V_318 )
{
int V_114 ;
V_114 = F_140 ( V_318 ) ;
return F_160 ( V_314 , V_114 ) ;
}
static int F_162 ( struct V_313 * V_314 , int V_165 )
{
int V_114 ;
switch ( V_165 ) {
case V_287 :
case V_319 :
V_114 = V_82 ;
break;
case V_289 :
case V_292 :
V_114 = V_42 ;
break;
case V_293 :
case V_320 :
return 0 ;
default:
return - V_138 ;
}
return F_160 ( V_314 , V_114 ) ;
}
static int F_163 ( struct V_313 * V_314 , struct V_277 * V_278 ,
int V_318 )
{
int V_114 ;
V_114 = F_140 ( V_318 ) ;
return F_160 ( V_314 , V_114 ) ;
}
static int F_164 ( struct V_313 * V_314 , struct V_277 * V_278 ,
struct V_35 * V_321 , long type , int V_37 )
{
return F_160 ( V_314 , V_42 ) ;
}
static int F_165 ( struct V_282 * V_322 , short V_323 )
{
char * V_13 = V_322 -> V_97 ;
int V_114 = F_140 ( V_323 ) ;
struct V_38 V_39 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_283 ) ;
V_39 . V_257 . V_258 . V_284 = V_322 -> V_285 ;
#endif
return F_17 ( V_13 , V_114 , & V_39 ) ;
}
static void F_166 ( struct V_282 * V_322 , T_3 * V_163 )
{
char * V_12 = V_322 -> V_97 ;
* V_163 = F_72 ( V_12 ) ;
}
static void F_167 ( struct V_4 * V_324 , struct V_2 * V_2 )
{
struct V_50 * V_79 ;
struct V_52 * V_53 ;
struct V_11 * V_13 ;
char * V_112 = F_21 () ;
char * V_325 ;
char * V_326 ;
char V_327 [ V_140 ] ;
int V_328 = 0 ;
struct V_4 * V_5 ;
if ( V_2 == NULL )
return;
V_13 = V_2 -> V_78 ;
F_168 ( & V_13 -> V_17 ) ;
if ( V_13 -> V_16 & V_266 )
goto V_329;
V_79 = V_2 -> V_152 ;
V_53 = V_79 -> V_61 ;
V_326 = V_53 -> V_55 ;
if ( V_324 -> V_330 == V_324 ) {
V_13 -> V_15 = V_53 -> V_54 ;
V_13 -> V_16 |= V_266 ;
goto V_329;
}
switch ( V_79 -> V_153 ) {
case V_331 :
V_326 = V_332 . V_48 ;
break;
case V_333 :
V_326 = V_332 . V_48 ;
break;
case V_334 :
V_326 = V_112 ;
break;
case V_154 :
V_326 = V_332 . V_48 ;
break;
case V_335 :
break;
case V_336 :
V_326 = V_332 . V_48 ;
default:
if ( F_169 ( V_2 -> V_337 ) ) {
V_326 = V_332 . V_48 ;
break;
}
if ( V_2 -> V_9 -> V_10 == NULL )
break;
V_5 = F_170 ( V_324 ) ;
V_325 = F_1 ( V_132 , V_2 , V_5 ) ;
if ( V_325 != NULL ) {
V_326 = V_325 ;
if ( F_171 ( V_2 -> V_337 ) ) {
V_327 [ 0 ] = '\0' ;
V_2 -> V_9 -> V_10 ( V_5 ,
V_139 ,
V_327 , V_140 ) ;
if ( strncmp ( V_327 , V_141 ,
V_140 ) == 0 )
V_328 = V_144 ;
}
}
V_13 -> V_23 = F_1 ( V_135 , V_2 , V_5 ) ;
V_13 -> V_143 = F_1 ( V_136 , V_2 , V_5 ) ;
F_172 ( V_5 ) ;
break;
}
if ( V_326 == NULL )
V_13 -> V_15 = V_112 ;
else
V_13 -> V_15 = V_326 ;
V_13 -> V_16 |= ( V_266 | V_328 ) ;
V_329:
F_173 ( & V_13 -> V_17 ) ;
return;
}
static int F_174 ( struct V_35 * V_203 , char * V_1 , char * * V_108 )
{
char * V_64 ;
int V_338 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_138 ;
V_64 = F_48 ( F_13 ( F_14 ( V_203 ) ) , V_14 ) ;
if ( V_64 == NULL )
return - V_33 ;
V_338 = strlen ( V_64 ) ;
* V_108 = V_64 ;
return V_338 ;
}
static int F_175 ( struct V_35 * V_203 , char * V_1 ,
void * V_108 , T_2 V_131 )
{
int V_6 ;
struct V_18 * V_22 ;
struct V_18 * V_339 ;
struct V_96 * V_199 ;
char * V_340 ;
if ( V_203 != V_103 )
return - V_100 ;
if ( ! F_22 ( V_137 ) )
return - V_100 ;
if ( V_108 == NULL || V_131 == 0 || V_131 >= V_8 )
return - V_138 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_138 ;
V_340 = F_2 ( V_108 , V_131 ) ;
if ( V_340 == NULL )
return - V_138 ;
if ( V_340 == V_341 . V_48 )
return - V_100 ;
V_339 = V_203 -> V_96 -> V_97 ;
V_199 = F_176 () ;
if ( V_199 == NULL )
return - V_33 ;
V_22 = F_6 ( V_340 , V_339 -> V_24 , V_14 ) ;
if ( V_22 == NULL ) {
F_26 ( V_199 ) ;
return - V_33 ;
}
V_6 = F_8 ( & V_22 -> V_25 , & V_339 -> V_25 , V_14 ) ;
if ( V_6 != 0 )
return V_6 ;
V_199 -> V_97 = V_22 ;
F_177 ( V_199 ) ;
return V_131 ;
}
static int F_178 ( struct V_150 * V_150 ,
struct V_150 * V_342 , struct V_150 * V_343 )
{
struct V_147 * V_148 = V_150 -> V_157 ;
struct V_147 * V_344 = V_342 -> V_157 ;
struct V_147 * V_77 = V_343 -> V_157 ;
struct V_38 V_39 ;
int V_6 = 0 ;
F_15 ( & V_39 , V_40 , V_256 ) ;
F_179 ( & V_39 , V_342 ) ;
if ( ! F_22 ( V_46 ) )
V_6 = V_187 ( V_148 -> V_161 , V_344 -> V_159 , V_88 , & V_39 ) ;
if ( V_6 == 0 ) {
V_77 -> V_215 = V_148 -> V_161 ;
V_148 -> V_215 = V_344 -> V_161 ;
}
return V_6 ;
}
static int F_180 ( struct V_149 * V_150 , struct V_149 * V_342 )
{
struct V_147 * V_148 = V_150 -> V_156 -> V_157 ;
struct V_147 * V_344 = V_342 -> V_156 -> V_157 ;
struct V_38 V_39 ;
int V_6 = 0 ;
F_15 ( & V_39 , V_40 , V_256 ) ;
F_179 ( & V_39 , V_342 -> V_156 ) ;
if ( ! F_22 ( V_46 ) )
V_6 = V_187 ( V_148 -> V_161 , V_344 -> V_159 , V_88 , & V_39 ) ;
return V_6 ;
}
static int F_181 ( struct V_149 * V_150 , struct V_345 * V_278 ,
int V_131 )
{
struct V_216 * V_217 = (struct V_216 * ) V_278 -> V_346 ;
if ( V_217 == NULL || V_217 -> V_260 != V_347 )
return 0 ;
return F_134 ( V_150 -> V_156 , V_217 ) ;
}
static char * F_182 ( struct V_229 * V_230 ,
struct V_147 * V_148 )
{
struct V_110 * V_111 ;
char V_12 [ V_8 ] ;
char * V_45 ;
int V_348 ;
if ( ( V_230 -> V_71 & V_244 ) != 0 ) {
memset ( V_12 , '\0' , V_8 ) ;
if ( ( V_230 -> V_71 & V_234 ) != 0 )
for ( V_348 = - 1 ; ; ) {
V_348 = F_183 (
V_230 -> V_235 . V_236 . V_232 , V_348 + 1 ) ;
if ( V_348 < 0 )
break;
F_184 ( V_348 , V_12 ) ;
}
if ( V_230 -> V_235 . V_236 . V_245 == V_248 ) {
V_111 = F_49 ( V_12 ) ;
if ( V_111 != NULL )
return V_111 -> V_48 ;
if ( V_148 != NULL &&
V_148 -> V_159 == V_332 . V_48 )
return V_341 . V_48 ;
return V_332 . V_48 ;
}
V_45 = F_185 ( V_230 -> V_235 . V_236 . V_245 , V_12 ) ;
if ( V_45 != NULL )
return V_45 ;
if ( V_148 != NULL && V_148 -> V_159 == V_332 . V_48 )
return V_341 . V_48 ;
return V_332 . V_48 ;
}
if ( ( V_230 -> V_71 & V_349 ) != 0 ) {
V_45 = F_97 ( V_230 -> V_235 . V_163 ) ;
F_186 ( V_45 == NULL ) ;
return V_45 ;
}
return V_251 ;
}
static int F_187 ( struct V_150 * V_156 , struct V_350 * V_351 )
{
struct V_229 V_250 ;
struct V_147 * V_148 = V_156 -> V_157 ;
char * V_112 ;
int V_6 ;
struct V_38 V_39 ;
if ( V_156 -> V_253 != V_271 && V_156 -> V_253 != V_352 )
return 0 ;
F_129 ( & V_250 ) ;
V_6 = F_188 ( V_351 , V_156 -> V_253 , & V_250 ) ;
if ( V_6 == 0 )
V_112 = F_182 ( & V_250 , V_148 ) ;
else
V_112 = V_251 ;
F_131 ( & V_250 ) ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_256 ) ;
V_39 . V_257 . V_258 . V_259 . V_213 = V_156 -> V_253 ;
V_39 . V_257 . V_258 . V_259 . V_353 = V_351 -> V_354 ;
F_189 ( V_351 , & V_39 . V_257 , NULL ) ;
#endif
V_6 = V_187 ( V_112 , V_148 -> V_159 , V_88 , & V_39 ) ;
if ( V_6 != 0 )
F_190 ( V_351 , V_6 , 0 ) ;
return V_6 ;
}
static int F_191 ( struct V_149 * V_150 ,
char T_5 * V_355 ,
int T_5 * V_356 , unsigned V_109 )
{
struct V_147 * V_148 ;
char * V_357 = L_4 ;
int V_338 = 1 ;
int V_6 = 0 ;
V_148 = V_150 -> V_156 -> V_157 ;
if ( V_148 -> V_215 != NULL ) {
V_357 = V_148 -> V_215 ;
V_338 = strlen ( V_357 ) + 1 ;
}
if ( V_338 > V_109 )
V_6 = - V_358 ;
else if ( F_192 ( V_355 , V_357 , V_338 ) != 0 )
V_6 = - V_359 ;
if ( F_193 ( V_338 , V_356 ) != 0 )
V_6 = - V_359 ;
return V_6 ;
}
static int F_194 ( struct V_149 * V_150 ,
struct V_350 * V_351 , T_3 * V_163 )
{
struct V_229 V_250 ;
struct V_147 * V_148 = NULL ;
char * V_45 ;
int V_213 = V_360 ;
T_3 V_361 = 0 ;
int V_6 ;
if ( V_351 != NULL ) {
if ( V_351 -> V_269 == F_195 ( V_362 ) )
V_213 = V_271 ;
else if ( V_351 -> V_269 == F_195 ( V_363 ) )
V_213 = V_352 ;
}
if ( V_213 == V_360 && V_150 != NULL )
V_213 = V_150 -> V_156 -> V_253 ;
if ( V_213 == V_267 ) {
V_148 = V_150 -> V_156 -> V_157 ;
V_361 = F_72 ( V_148 -> V_161 ) ;
} else if ( V_213 == V_271 || V_213 == V_352 ) {
if ( V_150 != NULL && V_150 -> V_156 != NULL )
V_148 = V_150 -> V_156 -> V_157 ;
F_129 ( & V_250 ) ;
V_6 = F_188 ( V_351 , V_213 , & V_250 ) ;
if ( V_6 == 0 ) {
V_45 = F_182 ( & V_250 , V_148 ) ;
V_361 = F_72 ( V_45 ) ;
}
F_131 ( & V_250 ) ;
}
* V_163 = V_361 ;
if ( V_361 == 0 )
return - V_138 ;
return 0 ;
}
static void F_196 ( struct V_150 * V_156 , struct V_149 * V_364 )
{
struct V_147 * V_148 ;
if ( V_156 == NULL ||
( V_156 -> V_253 != V_271 && V_156 -> V_253 != V_352 ) )
return;
V_148 = V_156 -> V_157 ;
V_148 -> V_159 = V_148 -> V_161 = F_21 () ;
}
static int F_197 ( struct V_150 * V_156 , struct V_350 * V_351 ,
struct V_365 * V_366 )
{
T_6 V_213 = V_156 -> V_253 ;
struct V_147 * V_148 = V_156 -> V_157 ;
struct V_229 V_250 ;
struct V_216 V_176 ;
struct V_367 * V_368 ;
char * V_45 ;
int V_6 ;
struct V_38 V_39 ;
if ( V_213 == V_352 && V_351 -> V_269 == F_195 ( V_362 ) )
V_213 = V_271 ;
F_129 ( & V_250 ) ;
V_6 = F_188 ( V_351 , V_213 , & V_250 ) ;
if ( V_6 == 0 )
V_45 = F_182 ( & V_250 , V_148 ) ;
else
V_45 = V_369 . V_48 ;
F_131 ( & V_250 ) ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_256 ) ;
V_39 . V_257 . V_258 . V_259 . V_213 = V_213 ;
V_39 . V_257 . V_258 . V_259 . V_353 = V_351 -> V_354 ;
F_189 ( V_351 , & V_39 . V_257 , NULL ) ;
#endif
V_6 = V_187 ( V_45 , V_148 -> V_159 , V_88 , & V_39 ) ;
if ( V_6 != 0 )
return V_6 ;
V_366 -> V_370 = F_72 ( V_45 ) ;
V_368 = F_198 ( V_351 ) ;
V_176 . V_222 . V_223 = V_368 -> V_371 ;
F_50 () ;
if ( F_119 ( & V_176 ) == NULL ) {
F_52 () ;
F_129 ( & V_250 ) ;
F_123 ( V_45 , & V_250 ) ;
V_6 = F_199 ( V_366 , & V_250 ) ;
F_131 ( & V_250 ) ;
} else {
F_52 () ;
F_200 ( V_366 ) ;
}
return V_6 ;
}
static void F_201 ( struct V_150 * V_156 ,
const struct V_365 * V_366 )
{
struct V_147 * V_148 = V_156 -> V_157 ;
if ( V_366 -> V_370 != 0 )
V_148 -> V_215 = F_97 ( V_366 -> V_370 ) ;
else
V_148 -> V_215 = NULL ;
}
static int F_202 ( struct V_372 * V_372 , const struct V_96 * V_96 ,
unsigned long V_71 )
{
V_372 -> V_97 = F_13 ( V_96 -> V_97 ) ;
return 0 ;
}
static void F_203 ( struct V_372 * V_372 )
{
V_372 -> V_97 = NULL ;
}
static int F_204 ( T_7 V_373 ,
const struct V_96 * V_96 , T_8 V_374 )
{
struct V_372 * V_375 ;
struct V_38 V_39 ;
char * V_22 = F_13 ( V_96 -> V_97 ) ;
V_375 = F_205 ( V_373 ) ;
if ( V_375 == NULL )
return - V_138 ;
if ( V_375 -> V_97 == NULL )
return 0 ;
if ( V_22 == NULL )
return - V_49 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_376 ) ;
V_39 . V_257 . V_258 . V_377 . V_372 = V_375 -> V_378 ;
V_39 . V_257 . V_258 . V_377 . V_379 = V_375 -> V_380 ;
#endif
return V_187 ( V_22 , V_375 -> V_97 ,
V_42 , & V_39 ) ;
}
static int F_206 ( T_3 V_381 , T_3 V_76 , char * V_382 , void * * V_383 )
{
char * * V_384 = ( char * * ) V_383 ;
* V_384 = NULL ;
if ( V_381 != V_385 && V_381 != V_386 )
return - V_138 ;
if ( V_76 != V_387 && V_76 != V_388 )
return - V_138 ;
* V_384 = F_2 ( V_382 , 0 ) ;
return 0 ;
}
static int F_207 ( struct V_389 * V_390 )
{
struct V_391 * V_392 ;
int V_393 ;
for ( V_393 = 0 ; V_393 < V_390 -> V_394 ; V_393 ++ ) {
V_392 = & V_390 -> V_395 [ V_393 ] ;
if ( V_392 -> type == V_385 || V_392 -> type == V_386 )
return 1 ;
}
return 0 ;
}
static int F_208 ( T_3 V_163 , T_3 V_381 , T_3 V_76 , void * V_383 ,
struct V_396 * V_397 )
{
char * V_12 ;
char * V_384 = V_383 ;
if ( ! V_384 ) {
F_209 ( V_397 , V_14 , V_398 ,
L_5 ) ;
return - V_186 ;
}
if ( V_381 != V_385 && V_381 != V_386 )
return 0 ;
V_12 = F_97 ( V_163 ) ;
if ( V_76 == V_387 )
return ( V_384 == V_12 ) ;
if ( V_76 == V_388 )
return ( V_384 != V_12 ) ;
return 0 ;
}
static void F_210 ( void * V_383 )
{
}
static int F_211 ( T_3 V_163 , char * * V_399 , T_3 * V_400 )
{
char * V_45 = F_97 ( V_163 ) ;
if ( V_399 )
* V_399 = V_45 ;
* V_400 = strlen ( V_45 ) ;
return 0 ;
}
static int F_212 ( const char * V_399 , T_3 V_400 , T_3 * V_163 )
{
* V_163 = F_72 ( V_399 ) ;
return 0 ;
}
static void F_213 ( char * V_399 , T_3 V_400 )
{
}
static int F_214 ( struct V_2 * V_2 , void * V_401 , T_3 V_402 )
{
return F_136 ( V_2 , V_115 , V_401 , V_402 , 0 ) ;
}
static int F_215 ( struct V_4 * V_4 , void * V_401 , T_3 V_402 )
{
return F_216 ( V_4 , V_132 , V_401 , V_402 , 0 ) ;
}
static int F_217 ( struct V_2 * V_2 , void * * V_401 , T_3 * V_402 )
{
int V_109 = 0 ;
V_109 = F_68 ( V_2 , V_115 , V_401 , true ) ;
if ( V_109 < 0 )
return V_109 ;
* V_402 = V_109 ;
return 0 ;
}
static T_9 void F_218 ( void )
{
F_219 ( & V_369 . V_34 , & V_403 ) ;
F_219 ( & V_58 . V_34 , & V_403 ) ;
F_219 ( & V_332 . V_34 , & V_403 ) ;
F_219 ( & V_47 . V_34 , & V_403 ) ;
F_219 ( & V_142 . V_34 , & V_403 ) ;
F_219 ( & V_341 . V_34 , & V_403 ) ;
}
static T_9 int F_220 ( void )
{
struct V_96 * V_96 ;
struct V_18 * V_22 ;
if ( ! F_221 ( & V_404 ) )
return 0 ;
V_22 = F_6 ( V_47 . V_48 ,
V_47 . V_48 , V_14 ) ;
if ( V_22 == NULL )
return - V_33 ;
F_137 ( V_405 L_6 ) ;
V_96 = (struct V_96 * ) V_103 -> V_96 ;
V_96 -> V_97 = V_22 ;
F_218 () ;
F_24 ( & V_369 . V_406 ) ;
F_24 ( & V_58 . V_406 ) ;
F_24 ( & V_332 . V_406 ) ;
F_24 ( & V_47 . V_406 ) ;
F_24 ( & V_142 . V_406 ) ;
if ( F_222 ( & V_404 ) )
F_223 ( L_7 ) ;
return 0 ;
}

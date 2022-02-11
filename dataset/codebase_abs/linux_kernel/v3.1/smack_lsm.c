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
struct V_18 * V_22 = V_92 -> V_93 -> V_94 ;
struct V_11 * V_13 ;
struct V_4 * V_5 ;
int V_6 ;
V_6 = F_39 ( V_92 ) ;
if ( V_6 != 0 )
return V_6 ;
if ( V_92 -> V_95 )
return 0 ;
if ( V_92 -> V_96 == NULL || V_92 -> V_96 -> V_97 == NULL )
return 0 ;
V_5 = V_92 -> V_96 -> V_97 ;
if ( V_5 -> V_75 == NULL )
return 0 ;
V_13 = V_5 -> V_75 -> V_78 ;
if ( V_13 -> V_23 != NULL )
V_22 -> V_23 = V_13 -> V_23 ;
return 0 ;
}
static int F_40 ( struct V_2 * V_2 )
{
V_2 -> V_78 = F_3 ( F_21 () ) ;
if ( V_2 -> V_78 == NULL )
return - V_33 ;
return 0 ;
}
static void F_41 ( struct V_2 * V_2 )
{
F_26 ( V_2 -> V_78 ) ;
V_2 -> V_78 = NULL ;
}
static int F_42 ( struct V_2 * V_2 , struct V_2 * V_98 ,
const struct V_99 * V_99 , char * * V_1 ,
void * * V_100 , T_2 * V_101 )
{
char * V_13 = F_43 ( V_2 ) ;
char * V_102 = F_43 ( V_98 ) ;
int V_103 ;
if ( V_1 ) {
* V_1 = F_44 ( V_104 , V_14 ) ;
if ( * V_1 == NULL )
return - V_33 ;
}
if ( V_100 ) {
F_45 () ;
V_103 = F_46 ( F_21 () , V_102 , & V_105 ) ;
F_47 () ;
if ( V_103 > 0 && ( ( V_103 & V_106 ) != 0 ) &&
F_48 ( V_98 ) )
V_13 = V_102 ;
* V_100 = F_44 ( V_13 , V_14 ) ;
if ( * V_100 == NULL )
return - V_33 ;
}
if ( V_101 )
* V_101 = strlen ( V_13 ) + 1 ;
return 0 ;
}
static int F_49 ( struct V_4 * V_107 , struct V_2 * V_98 ,
struct V_4 * V_108 )
{
char * V_13 ;
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_107 ) ;
V_13 = F_43 ( V_107 -> V_75 ) ;
V_6 = F_17 ( V_13 , V_88 , & V_39 ) ;
if ( V_6 == 0 && V_108 -> V_75 != NULL ) {
V_13 = F_43 ( V_108 -> V_75 ) ;
F_34 ( & V_39 , V_108 ) ;
V_6 = F_17 ( V_13 , V_88 , & V_39 ) ;
}
return V_6 ;
}
static int F_50 ( struct V_2 * V_98 , struct V_4 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_75 ;
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
V_6 = F_17 ( F_43 ( V_3 ) , V_88 , & V_39 ) ;
if ( V_6 == 0 ) {
F_34 ( & V_39 , NULL ) ;
F_51 ( & V_39 , V_98 ) ;
V_6 = F_17 ( F_43 ( V_98 ) , V_88 , & V_39 ) ;
}
return V_6 ;
}
static int F_52 ( struct V_2 * V_98 , struct V_4 * V_4 )
{
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
V_6 = F_17 ( F_43 ( V_4 -> V_75 ) , V_88 , & V_39 ) ;
if ( V_6 == 0 ) {
F_34 ( & V_39 , NULL ) ;
F_51 ( & V_39 , V_98 ) ;
V_6 = F_17 ( F_43 ( V_98 ) , V_88 , & V_39 ) ;
}
return V_6 ;
}
static int F_53 ( struct V_2 * V_109 ,
struct V_4 * V_107 ,
struct V_2 * V_110 ,
struct V_4 * V_108 )
{
int V_6 ;
char * V_13 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_107 ) ;
V_13 = F_43 ( V_107 -> V_75 ) ;
V_6 = F_17 ( V_13 , V_42 , & V_39 ) ;
if ( V_6 == 0 && V_108 -> V_75 != NULL ) {
V_13 = F_43 ( V_108 -> V_75 ) ;
F_34 ( & V_39 , V_108 ) ;
V_6 = F_17 ( V_13 , V_42 , & V_39 ) ;
}
return V_6 ;
}
static int F_54 ( struct V_2 * V_2 , int V_111 )
{
struct V_38 V_39 ;
int V_112 = V_111 & V_113 ;
V_111 &= ( V_82 | V_88 | V_114 | V_115 ) ;
if ( V_111 == 0 )
return 0 ;
if ( V_112 )
return - V_116 ;
F_15 ( & V_39 , V_40 , V_117 ) ;
F_51 ( & V_39 , V_2 ) ;
return F_17 ( F_43 ( V_2 ) , V_111 , & V_39 ) ;
}
static int F_55 ( struct V_4 * V_4 , struct V_118 * V_118 )
{
struct V_38 V_39 ;
if ( V_118 -> V_119 & V_120 )
return 0 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
return F_17 ( F_43 ( V_4 -> V_75 ) , V_88 , & V_39 ) ;
}
static int F_56 ( struct V_89 * V_85 , struct V_4 * V_4 )
{
struct V_38 V_39 ;
struct V_84 V_84 ;
V_84 . V_4 = V_4 ;
V_84 . V_85 = V_85 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_84 ) ;
return F_17 ( F_43 ( V_4 -> V_75 ) , V_82 , & V_39 ) ;
}
static int F_57 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_100 , T_2 V_121 , int V_71 )
{
struct V_38 V_39 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_122 ) == 0 ||
strcmp ( V_1 , V_123 ) == 0 ||
strcmp ( V_1 , V_124 ) == 0 ||
strcmp ( V_1 , V_125 ) == 0 ||
strcmp ( V_1 , V_126 ) == 0 ) {
if ( ! F_22 ( V_127 ) )
V_6 = - V_128 ;
if ( V_121 == 0 || V_121 >= V_8 ||
F_2 ( V_100 , V_121 ) == NULL )
V_6 = - V_129 ;
} else if ( strcmp ( V_1 , V_130 ) == 0 ) {
if ( ! F_22 ( V_127 ) )
V_6 = - V_128 ;
if ( V_121 != V_131 ||
strncmp ( V_100 , V_132 , V_131 ) != 0 )
V_6 = - V_129 ;
} else
V_6 = F_58 ( V_4 , V_1 , V_100 , V_121 , V_71 ) ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_17 ( F_43 ( V_4 -> V_75 ) , V_88 , & V_39 ) ;
return V_6 ;
}
static void F_59 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_100 , T_2 V_121 , int V_71 )
{
char * V_77 ;
struct V_11 * V_13 = V_4 -> V_75 -> V_78 ;
if ( strcmp ( V_1 , V_122 ) == 0 ) {
V_77 = F_2 ( V_100 , V_121 ) ;
if ( V_77 != NULL )
V_13 -> V_15 = V_77 ;
else
V_13 -> V_15 = V_133 . V_48 ;
} else if ( strcmp ( V_1 , V_125 ) == 0 ) {
V_77 = F_2 ( V_100 , V_121 ) ;
if ( V_77 != NULL )
V_13 -> V_23 = V_77 ;
else
V_13 -> V_23 = V_133 . V_48 ;
} else if ( strcmp ( V_1 , V_126 ) == 0 ) {
V_77 = F_2 ( V_100 , V_121 ) ;
if ( V_77 != NULL )
V_13 -> V_134 = V_77 ;
else
V_13 -> V_134 = V_133 . V_48 ;
} else if ( strcmp ( V_1 , V_130 ) == 0 )
V_13 -> V_16 |= V_135 ;
return;
}
static int F_60 ( struct V_4 * V_4 , const char * V_1 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
return F_17 ( F_43 ( V_4 -> V_75 ) , V_82 , & V_39 ) ;
}
static int F_61 ( struct V_4 * V_4 , const char * V_1 )
{
struct V_11 * V_13 ;
struct V_38 V_39 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_122 ) == 0 ||
strcmp ( V_1 , V_123 ) == 0 ||
strcmp ( V_1 , V_124 ) == 0 ||
strcmp ( V_1 , V_125 ) == 0 ||
strcmp ( V_1 , V_130 ) == 0 ||
strcmp ( V_1 , V_126 ) ) {
if ( ! F_22 ( V_127 ) )
V_6 = - V_128 ;
} else
V_6 = F_62 ( V_4 , V_1 ) ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_17 ( F_43 ( V_4 -> V_75 ) , V_88 , & V_39 ) ;
if ( V_6 == 0 ) {
V_13 = V_4 -> V_75 -> V_78 ;
V_13 -> V_23 = NULL ;
V_13 -> V_134 = NULL ;
}
return V_6 ;
}
static int F_63 ( const struct V_2 * V_2 ,
const char * V_1 , void * * V_136 ,
bool V_137 )
{
struct V_138 * V_139 ;
struct V_140 * V_141 ;
struct V_50 * V_79 ;
struct V_2 * V_3 = (struct V_2 * ) V_2 ;
char * V_13 ;
int V_142 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_104 ) == 0 ) {
V_13 = F_43 ( V_2 ) ;
V_142 = strlen ( V_13 ) + 1 ;
* V_136 = V_13 ;
return V_142 ;
}
V_79 = V_3 -> V_143 ;
if ( V_79 -> V_144 != V_145 )
return - V_146 ;
V_141 = F_64 ( V_3 ) ;
if ( V_141 == NULL || V_141 -> V_147 == NULL )
return - V_146 ;
V_139 = V_141 -> V_147 -> V_148 ;
if ( strcmp ( V_1 , V_149 ) == 0 )
V_13 = V_139 -> V_150 ;
else if ( strcmp ( V_1 , V_151 ) == 0 )
V_13 = V_139 -> V_152 ;
else
return - V_146 ;
V_142 = strlen ( V_13 ) + 1 ;
if ( V_6 == 0 ) {
* V_136 = V_13 ;
V_6 = V_142 ;
}
return V_6 ;
}
static int F_65 ( struct V_2 * V_2 , char * V_136 ,
T_2 V_153 )
{
int V_101 = strlen ( V_122 ) ;
if ( V_136 != NULL && V_101 <= V_153 ) {
memcpy ( V_136 , V_122 , V_101 ) ;
return V_101 ;
}
return - V_129 ;
}
static void F_66 ( const struct V_2 * V_2 , T_3 * V_154 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
* V_154 = F_67 ( V_13 -> V_15 ) ;
}
static int F_68 ( struct V_96 * V_96 , int V_111 )
{
return 0 ;
}
static int F_69 ( struct V_96 * V_96 )
{
V_96 -> V_155 = F_21 () ;
return 0 ;
}
static void F_70 ( struct V_96 * V_96 )
{
V_96 -> V_155 = NULL ;
}
static int F_71 ( struct V_96 * V_96 , unsigned int V_156 ,
unsigned long V_157 )
{
int V_6 = 0 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_96 -> V_158 ) ;
if ( F_72 ( V_156 ) & V_159 )
V_6 = F_17 ( V_96 -> V_155 , V_88 , & V_39 ) ;
if ( V_6 == 0 && ( F_72 ( V_156 ) & V_160 ) )
V_6 = F_17 ( V_96 -> V_155 , V_82 , & V_39 ) ;
return V_6 ;
}
static int F_73 ( struct V_96 * V_96 , unsigned int V_156 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_96 -> V_158 ) ;
return F_17 ( V_96 -> V_155 , V_88 , & V_39 ) ;
}
static int F_74 ( struct V_96 * V_96 , unsigned int V_156 ,
unsigned long V_157 )
{
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_96 -> V_158 ) ;
switch ( V_156 ) {
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
V_6 = F_17 ( V_96 -> V_155 , V_82 , & V_39 ) ;
break;
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
V_6 = F_17 ( V_96 -> V_155 , V_88 , & V_39 ) ;
break;
default:
V_6 = F_17 ( V_96 -> V_155 , V_42 , & V_39 ) ;
}
return V_6 ;
}
static int F_75 ( struct V_96 * V_96 ,
unsigned long V_173 , unsigned long V_174 ,
unsigned long V_71 , unsigned long V_175 ,
unsigned long V_176 )
{
struct V_30 * V_177 ;
struct V_18 * V_22 ;
char * V_45 ;
char * V_178 ;
char * V_179 ;
struct V_11 * V_13 ;
struct V_4 * V_5 ;
int V_103 ;
int V_180 ;
int V_181 ;
int V_6 ;
V_6 = F_76 ( V_96 , V_173 , V_174 , V_71 , V_175 , V_176 ) ;
if ( V_6 || V_176 )
return V_6 ;
if ( V_96 == NULL || V_96 -> V_97 == NULL )
return 0 ;
V_5 = V_96 -> V_97 ;
if ( V_5 -> V_75 == NULL )
return 0 ;
V_13 = V_5 -> V_75 -> V_78 ;
if ( V_13 -> V_134 == NULL )
return 0 ;
V_178 = V_13 -> V_134 ;
V_22 = F_77 () ;
V_45 = F_21 () ;
V_6 = 0 ;
F_45 () ;
F_9 (srp, &smack_rule_list, list) {
if ( V_177 -> V_182 != V_45 )
continue;
V_179 = V_177 -> V_183 ;
if ( V_178 == V_179 )
continue;
V_103 = F_46 ( V_177 -> V_182 , V_179 ,
& V_22 -> V_25 ) ;
if ( V_103 == - V_184 )
V_103 = V_177 -> V_185 ;
else
V_103 &= V_177 -> V_185 ;
if ( V_103 == 0 )
continue;
V_180 = F_46 ( V_178 , V_179 , & V_105 ) ;
if ( V_180 == - V_184 ) {
V_6 = - V_49 ;
break;
}
V_181 = F_46 ( V_178 , V_179 , & V_22 -> V_25 ) ;
if ( V_181 != - V_184 )
V_180 &= V_181 ;
if ( ( V_103 | V_180 ) != V_180 ) {
V_6 = - V_49 ;
break;
}
}
F_47 () ;
return V_6 ;
}
static int F_78 ( struct V_96 * V_96 )
{
V_96 -> V_155 = F_21 () ;
return 0 ;
}
static int F_79 ( struct V_35 * V_186 ,
struct V_187 * V_188 , int V_189 )
{
struct V_96 * V_96 ;
int V_6 ;
char * V_22 = F_13 ( V_186 -> V_93 -> V_94 ) ;
struct V_38 V_39 ;
V_96 = F_80 ( V_188 , struct V_96 , V_190 ) ;
V_6 = V_185 ( V_96 -> V_155 , V_22 , V_88 , NULL ) ;
if ( V_6 != 0 && F_81 ( V_186 , V_46 ) )
V_6 = 0 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_186 ) ;
F_82 ( V_96 -> V_155 , V_22 , V_88 , V_6 , & V_39 ) ;
return V_6 ;
}
static int F_83 ( struct V_96 * V_96 )
{
int V_103 = 0 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_36 ( & V_39 , V_96 -> V_158 ) ;
if ( V_96 -> V_191 & V_192 )
V_103 = V_82 ;
if ( V_96 -> V_191 & V_193 )
V_103 |= V_88 ;
return F_17 ( V_96 -> V_155 , V_103 , & V_39 ) ;
}
static int F_84 ( struct V_93 * V_93 , T_1 V_21 )
{
struct V_18 * V_22 ;
V_22 = F_6 ( NULL , NULL , V_21 ) ;
if ( V_22 == NULL )
return - V_33 ;
V_93 -> V_94 = V_22 ;
return 0 ;
}
static void F_85 ( struct V_93 * V_93 )
{
struct V_18 * V_22 = V_93 -> V_94 ;
struct V_30 * V_194 ;
struct V_27 * V_195 ;
struct V_27 * V_196 ;
if ( V_22 == NULL )
return;
V_93 -> V_94 = NULL ;
F_86 (l, n, &tsp->smk_rules) {
V_194 = F_87 ( V_195 , struct V_30 , V_34 ) ;
F_88 ( & V_194 -> V_34 ) ;
F_26 ( V_194 ) ;
}
F_26 ( V_22 ) ;
}
static int F_89 ( struct V_93 * V_197 , const struct V_93 * V_198 ,
T_1 V_21 )
{
struct V_18 * V_199 = V_198 -> V_94 ;
struct V_18 * V_200 ;
int V_6 ;
V_200 = F_6 ( V_199 -> V_23 , V_199 -> V_23 , V_21 ) ;
if ( V_200 == NULL )
return - V_33 ;
V_6 = F_8 ( & V_200 -> V_25 , & V_199 -> V_25 , V_21 ) ;
if ( V_6 != 0 )
return V_6 ;
V_197 -> V_94 = V_200 ;
return 0 ;
}
static void F_90 ( struct V_93 * V_197 , const struct V_93 * V_198 )
{
struct V_18 * V_199 = V_198 -> V_94 ;
struct V_18 * V_200 = V_197 -> V_94 ;
V_200 -> V_23 = V_199 -> V_23 ;
V_200 -> V_24 = V_199 -> V_23 ;
F_5 ( & V_200 -> V_26 ) ;
F_7 ( & V_200 -> V_25 ) ;
}
static int F_91 ( struct V_93 * V_197 , T_3 V_154 )
{
struct V_18 * V_200 = V_197 -> V_94 ;
char * V_12 = F_92 ( V_154 ) ;
if ( V_12 == NULL )
return - V_129 ;
V_200 -> V_23 = V_12 ;
return 0 ;
}
static int F_93 ( struct V_93 * V_197 ,
struct V_2 * V_2 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
struct V_18 * V_22 = V_197 -> V_94 ;
V_22 -> V_24 = V_13 -> V_15 ;
V_22 -> V_23 = V_13 -> V_15 ;
return 0 ;
}
static int F_94 ( struct V_35 * V_201 , int V_202 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_201 ) ;
return F_17 ( F_13 ( F_14 ( V_201 ) ) , V_202 , & V_39 ) ;
}
static int F_95 ( struct V_35 * V_201 , T_4 V_203 )
{
return F_94 ( V_201 , V_88 ) ;
}
static int F_96 ( struct V_35 * V_201 )
{
return F_94 ( V_201 , V_82 ) ;
}
static int F_97 ( struct V_35 * V_201 )
{
return F_94 ( V_201 , V_82 ) ;
}
static void F_98 ( struct V_35 * V_201 , T_3 * V_154 )
{
* V_154 = F_67 ( F_13 ( F_14 ( V_201 ) ) ) ;
}
static int F_99 ( struct V_35 * V_201 , int V_204 )
{
int V_6 ;
V_6 = F_100 ( V_201 , V_204 ) ;
if ( V_6 == 0 )
V_6 = F_94 ( V_201 , V_88 ) ;
return V_6 ;
}
static int F_101 ( struct V_35 * V_201 , int V_205 )
{
int V_6 ;
V_6 = F_102 ( V_201 , V_205 ) ;
if ( V_6 == 0 )
V_6 = F_94 ( V_201 , V_88 ) ;
return V_6 ;
}
static int F_103 ( struct V_35 * V_201 )
{
return F_94 ( V_201 , V_82 ) ;
}
static int F_104 ( struct V_35 * V_201 )
{
int V_6 ;
V_6 = F_105 ( V_201 ) ;
if ( V_6 == 0 )
V_6 = F_94 ( V_201 , V_88 ) ;
return V_6 ;
}
static int F_106 ( struct V_35 * V_201 )
{
return F_94 ( V_201 , V_82 ) ;
}
static int F_107 ( struct V_35 * V_201 )
{
return F_94 ( V_201 , V_88 ) ;
}
static int F_108 ( struct V_35 * V_201 , struct V_206 * V_207 ,
int V_208 , T_3 V_154 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_201 ) ;
if ( V_154 == 0 )
return F_17 ( F_13 ( F_14 ( V_201 ) ) , V_88 ,
& V_39 ) ;
return V_185 ( F_92 ( V_154 ) ,
F_13 ( F_14 ( V_201 ) ) , V_88 , & V_39 ) ;
}
static int F_109 ( struct V_35 * V_201 )
{
struct V_38 V_39 ;
char * V_45 = F_21 () ;
char * V_22 = F_110 ( F_14 ( V_201 ) ) ;
int V_6 ;
V_6 = V_185 ( V_22 , V_45 , V_88 , NULL ) ;
if ( V_6 == 0 )
goto V_209;
if ( F_22 ( V_46 ) || F_81 ( V_201 , V_46 ) )
V_6 = 0 ;
V_209:
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_201 ) ;
F_82 ( V_22 , V_45 , V_88 , V_6 , & V_39 ) ;
return V_6 ;
}
static void F_111 ( struct V_35 * V_201 , struct V_2 * V_2 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
V_13 -> V_15 = F_13 ( F_14 ( V_201 ) ) ;
}
static int F_112 ( struct V_141 * V_147 , int V_210 , T_1 V_211 )
{
char * V_212 = F_21 () ;
struct V_138 * V_139 ;
V_139 = F_4 ( sizeof( struct V_138 ) , V_211 ) ;
if ( V_139 == NULL )
return - V_33 ;
V_139 -> V_150 = V_212 ;
V_139 -> V_152 = V_212 ;
V_139 -> V_213 [ 0 ] = '\0' ;
V_147 -> V_148 = V_139 ;
return 0 ;
}
static void F_113 ( struct V_141 * V_147 )
{
F_26 ( V_147 -> V_148 ) ;
}
static char * F_114 ( struct V_214 * V_215 )
{
struct V_216 * V_217 ;
struct V_218 * V_219 = & V_215 -> V_220 ;
if ( V_219 -> V_221 == 0 )
return NULL ;
F_9 (snp, &smk_netlbladdr_list, list)
if ( ( & V_217 -> V_222 . V_220 ) -> V_221 ==
( V_219 -> V_221 & ( & V_217 -> V_223 ) -> V_221 ) ) {
if ( V_217 -> V_224 == V_225 )
return NULL ;
return V_217 -> V_224 ;
}
return NULL ;
}
static void F_115 ( char * V_226 , struct V_227 * V_228 )
{
unsigned char * V_64 ;
unsigned char V_229 ;
int V_230 ;
int V_6 ;
int V_231 ;
if ( ! V_226 )
return;
V_228 -> V_71 |= V_232 ;
V_228 -> V_233 . V_234 . V_230 = F_116 ( V_235 ) ;
V_228 -> V_233 . V_234 . V_230 -> V_236 = 0 ;
for ( V_230 = 1 , V_64 = V_226 , V_231 = 0 ; V_231 < V_8 ; V_64 ++ , V_231 ++ )
for ( V_229 = 0x80 ; V_229 != 0 ; V_229 >>= 1 , V_230 ++ ) {
if ( ( V_229 & * V_64 ) == 0 )
continue;
V_6 = F_117 ( V_228 -> V_233 . V_234 . V_230 ,
V_230 , V_235 ) ;
}
}
static void F_118 ( char * V_12 , struct V_227 * V_237 )
{
struct V_238 V_239 ;
int V_6 ;
V_237 -> V_240 = V_12 ;
V_237 -> V_71 = V_241 | V_242 ;
V_6 = F_119 ( V_12 , & V_239 ) ;
if ( V_6 == 0 ) {
V_237 -> V_233 . V_234 . V_243 = V_239 . V_244 ;
F_115 ( V_239 . V_245 , V_237 ) ;
} else {
V_237 -> V_233 . V_234 . V_243 = V_246 ;
F_115 ( V_12 , V_237 ) ;
}
}
static int F_120 ( struct V_141 * V_147 , int V_247 )
{
struct V_138 * V_139 = V_147 -> V_148 ;
struct V_227 V_248 ;
int V_6 = 0 ;
F_121 () ;
F_122 ( V_147 ) ;
if ( V_139 -> V_152 == V_249 ||
V_247 == V_250 )
F_123 ( V_147 ) ;
else {
F_124 ( & V_248 ) ;
F_118 ( V_139 -> V_152 , & V_248 ) ;
V_6 = F_125 ( V_147 , V_147 -> V_251 , & V_248 ) ;
F_126 ( & V_248 ) ;
}
F_127 ( V_147 ) ;
F_128 () ;
return V_6 ;
}
static int F_129 ( struct V_141 * V_147 , struct V_214 * V_228 )
{
int V_6 ;
int V_252 ;
char * V_253 ;
struct V_138 * V_139 = V_147 -> V_148 ;
struct V_38 V_39 ;
F_45 () ;
V_253 = F_114 ( V_228 ) ;
if ( V_253 != NULL ) {
V_252 = V_250 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_254 ) ;
V_39 . V_255 . V_256 . V_257 . V_210 = V_228 -> V_258 ;
V_39 . V_255 . V_256 . V_257 . V_259 = V_228 -> V_260 ;
V_39 . V_255 . V_256 . V_257 . V_261 . V_262 = V_228 -> V_220 . V_221 ;
#endif
V_6 = V_185 ( V_139 -> V_152 , V_253 , V_88 , & V_39 ) ;
} else {
V_252 = V_263 ;
V_6 = 0 ;
}
F_47 () ;
if ( V_6 != 0 )
return V_6 ;
return F_120 ( V_147 , V_252 ) ;
}
static int F_131 ( struct V_2 * V_2 , const char * V_1 ,
const void * V_100 , T_2 V_121 , int V_71 )
{
char * V_45 ;
struct V_11 * V_77 = V_2 -> V_78 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
int V_6 = 0 ;
if ( V_100 == NULL || V_121 > V_8 || V_121 == 0 )
return - V_49 ;
V_45 = F_2 ( V_100 , V_121 ) ;
if ( V_45 == NULL )
return - V_129 ;
if ( strcmp ( V_1 , V_104 ) == 0 ) {
V_77 -> V_15 = V_45 ;
V_77 -> V_16 |= V_264 ;
return 0 ;
}
if ( V_2 -> V_143 -> V_144 != V_145 )
return - V_146 ;
V_141 = F_64 ( V_2 ) ;
if ( V_141 == NULL || V_141 -> V_147 == NULL )
return - V_146 ;
V_139 = V_141 -> V_147 -> V_148 ;
if ( strcmp ( V_1 , V_149 ) == 0 )
V_139 -> V_150 = V_45 ;
else if ( strcmp ( V_1 , V_151 ) == 0 ) {
V_139 -> V_152 = V_45 ;
if ( V_141 -> V_147 -> V_251 != V_265 ) {
V_6 = F_120 ( V_141 -> V_147 , V_263 ) ;
if ( V_6 != 0 )
F_132 ( V_266
L_2 ,
V_40 , - V_6 ) ;
}
} else
return - V_146 ;
return 0 ;
}
static int F_133 ( struct V_140 * V_141 , int V_210 ,
int type , int V_267 , int V_268 )
{
if ( V_210 != V_269 || V_141 -> V_147 == NULL )
return 0 ;
return F_120 ( V_141 -> V_147 , V_263 ) ;
}
static int F_134 ( struct V_140 * V_141 , struct V_270 * V_228 ,
int V_271 )
{
if ( V_141 -> V_147 == NULL || V_141 -> V_147 -> V_251 != V_269 )
return 0 ;
if ( V_271 < sizeof( struct V_214 ) )
return - V_129 ;
return F_129 ( V_141 -> V_147 , (struct V_214 * ) V_228 ) ;
}
static int F_135 ( int V_71 )
{
int V_103 = 0 ;
if ( V_71 & V_272 )
V_103 |= V_82 ;
if ( V_71 & V_273 )
V_103 |= V_88 ;
if ( V_71 & V_274 )
V_103 |= V_114 ;
return V_103 ;
}
static int F_136 ( struct V_275 * V_276 )
{
V_276 -> V_94 = F_21 () ;
return 0 ;
}
static void F_137 ( struct V_275 * V_276 )
{
V_276 -> V_94 = NULL ;
}
static char * F_138 ( struct V_277 * V_278 )
{
return ( char * ) V_278 -> V_279 . V_94 ;
}
static int F_139 ( struct V_277 * V_278 )
{
struct V_280 * V_13 = & V_278 -> V_279 ;
V_13 -> V_94 = F_21 () ;
return 0 ;
}
static void F_140 ( struct V_277 * V_278 )
{
struct V_280 * V_13 = & V_278 -> V_279 ;
V_13 -> V_94 = NULL ;
}
static int F_141 ( struct V_277 * V_278 , int V_202 )
{
char * V_139 = F_138 ( V_278 ) ;
struct V_38 V_39 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_281 ) ;
V_39 . V_255 . V_256 . V_282 = V_278 -> V_279 . V_283 ;
#endif
return F_17 ( V_139 , V_202 , & V_39 ) ;
}
static int F_142 ( struct V_277 * V_278 , int V_284 )
{
int V_103 ;
V_103 = F_135 ( V_284 ) ;
return F_141 ( V_278 , V_103 ) ;
}
static int F_143 ( struct V_277 * V_278 , int V_156 )
{
int V_103 ;
switch ( V_156 ) {
case V_285 :
case V_286 :
V_103 = V_82 ;
break;
case V_287 :
case V_288 :
case V_289 :
case V_290 :
V_103 = V_42 ;
break;
case V_291 :
case V_292 :
return 0 ;
default:
return - V_129 ;
}
return F_141 ( V_278 , V_103 ) ;
}
static int F_144 ( struct V_277 * V_278 , char T_5 * V_293 ,
int V_284 )
{
int V_103 ;
V_103 = F_135 ( V_284 ) ;
return F_141 ( V_278 , V_103 ) ;
}
static char * F_145 ( struct V_294 * V_295 )
{
return ( char * ) V_295 -> V_296 . V_94 ;
}
static int F_146 ( struct V_294 * V_295 )
{
struct V_280 * V_13 = & V_295 -> V_296 ;
V_13 -> V_94 = F_21 () ;
return 0 ;
}
static void F_147 ( struct V_294 * V_295 )
{
struct V_280 * V_13 = & V_295 -> V_296 ;
V_13 -> V_94 = NULL ;
}
static int F_148 ( struct V_294 * V_295 , int V_202 )
{
char * V_139 = F_145 ( V_295 ) ;
struct V_38 V_39 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_281 ) ;
V_39 . V_255 . V_256 . V_282 = V_295 -> V_296 . V_283 ;
#endif
return F_17 ( V_139 , V_202 , & V_39 ) ;
}
static int F_149 ( struct V_294 * V_295 , int V_297 )
{
int V_103 ;
V_103 = F_135 ( V_297 ) ;
return F_148 ( V_295 , V_103 ) ;
}
static int F_150 ( struct V_294 * V_295 , int V_156 )
{
int V_103 ;
switch ( V_156 ) {
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_302 :
case V_285 :
case V_303 :
V_103 = V_82 ;
break;
case V_304 :
case V_305 :
case V_290 :
case V_287 :
V_103 = V_42 ;
break;
case V_291 :
case V_306 :
return 0 ;
default:
return - V_129 ;
}
return F_148 ( V_295 , V_103 ) ;
}
static int F_151 ( struct V_294 * V_295 , struct V_307 * V_308 ,
unsigned V_309 , int V_310 )
{
return F_148 ( V_295 , V_42 ) ;
}
static int F_152 ( struct V_311 * V_312 )
{
struct V_280 * V_313 = & V_312 -> V_314 ;
V_313 -> V_94 = F_21 () ;
return 0 ;
}
static void F_153 ( struct V_311 * V_312 )
{
struct V_280 * V_313 = & V_312 -> V_314 ;
V_313 -> V_94 = NULL ;
}
static char * F_154 ( struct V_311 * V_312 )
{
return ( char * ) V_312 -> V_314 . V_94 ;
}
static int F_155 ( struct V_311 * V_312 , int V_202 )
{
char * V_315 = F_154 ( V_312 ) ;
struct V_38 V_39 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_281 ) ;
V_39 . V_255 . V_256 . V_282 = V_312 -> V_314 . V_283 ;
#endif
return F_17 ( V_315 , V_202 , & V_39 ) ;
}
static int F_156 ( struct V_311 * V_312 , int V_316 )
{
int V_103 ;
V_103 = F_135 ( V_316 ) ;
return F_155 ( V_312 , V_103 ) ;
}
static int F_157 ( struct V_311 * V_312 , int V_156 )
{
int V_103 ;
switch ( V_156 ) {
case V_285 :
case V_317 :
V_103 = V_82 ;
break;
case V_287 :
case V_290 :
V_103 = V_42 ;
break;
case V_291 :
case V_318 :
return 0 ;
default:
return - V_129 ;
}
return F_155 ( V_312 , V_103 ) ;
}
static int F_158 ( struct V_311 * V_312 , struct V_275 * V_276 ,
int V_316 )
{
int V_103 ;
V_103 = F_135 ( V_316 ) ;
return F_155 ( V_312 , V_103 ) ;
}
static int F_159 ( struct V_311 * V_312 , struct V_275 * V_276 ,
struct V_35 * V_319 , long type , int V_37 )
{
return F_155 ( V_312 , V_42 ) ;
}
static int F_160 ( struct V_280 * V_320 , short V_321 )
{
char * V_13 = V_320 -> V_94 ;
int V_103 = F_135 ( V_321 ) ;
struct V_38 V_39 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_281 ) ;
V_39 . V_255 . V_256 . V_282 = V_320 -> V_283 ;
#endif
return F_17 ( V_13 , V_103 , & V_39 ) ;
}
static void F_161 ( struct V_280 * V_320 , T_3 * V_154 )
{
char * V_12 = V_320 -> V_94 ;
* V_154 = F_67 ( V_12 ) ;
}
static void F_162 ( struct V_4 * V_322 , struct V_2 * V_2 )
{
struct V_50 * V_79 ;
struct V_52 * V_53 ;
struct V_11 * V_13 ;
char * V_212 = F_21 () ;
char * V_323 ;
char * V_324 ;
char V_325 [ V_131 ] ;
int V_326 = 0 ;
struct V_4 * V_5 ;
if ( V_2 == NULL )
return;
V_13 = V_2 -> V_78 ;
F_163 ( & V_13 -> V_17 ) ;
if ( V_13 -> V_16 & V_264 )
goto V_327;
V_79 = V_2 -> V_143 ;
V_53 = V_79 -> V_61 ;
V_324 = V_53 -> V_55 ;
if ( V_322 -> V_328 == V_322 ) {
V_13 -> V_15 = V_53 -> V_54 ;
V_13 -> V_16 |= V_264 ;
goto V_327;
}
switch ( V_79 -> V_144 ) {
case V_329 :
V_324 = V_330 . V_48 ;
break;
case V_331 :
V_324 = V_330 . V_48 ;
break;
case V_332 :
V_324 = V_212 ;
break;
case V_145 :
V_324 = V_330 . V_48 ;
break;
case V_333 :
break;
case V_334 :
V_324 = V_330 . V_48 ;
default:
if ( F_164 ( V_2 -> V_335 ) ) {
V_324 = V_330 . V_48 ;
break;
}
if ( V_2 -> V_9 -> V_10 == NULL )
break;
V_5 = F_165 ( V_322 ) ;
V_323 = F_1 ( V_122 , V_2 , V_5 ) ;
if ( V_323 != NULL ) {
V_324 = V_323 ;
if ( F_166 ( V_2 -> V_335 ) ) {
V_325 [ 0 ] = '\0' ;
V_2 -> V_9 -> V_10 ( V_5 ,
V_130 ,
V_325 , V_131 ) ;
if ( strncmp ( V_325 , V_132 ,
V_131 ) == 0 )
V_326 = V_135 ;
}
}
V_13 -> V_23 = F_1 ( V_125 , V_2 , V_5 ) ;
V_13 -> V_134 = F_1 ( V_126 , V_2 , V_5 ) ;
F_167 ( V_5 ) ;
break;
}
if ( V_324 == NULL )
V_13 -> V_15 = V_212 ;
else
V_13 -> V_15 = V_324 ;
V_13 -> V_16 |= ( V_264 | V_326 ) ;
V_327:
F_168 ( & V_13 -> V_17 ) ;
return;
}
static int F_169 ( struct V_35 * V_201 , char * V_1 , char * * V_100 )
{
char * V_64 ;
int V_336 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_129 ;
V_64 = F_44 ( F_13 ( F_14 ( V_201 ) ) , V_14 ) ;
if ( V_64 == NULL )
return - V_33 ;
V_336 = strlen ( V_64 ) ;
* V_100 = V_64 ;
return V_336 ;
}
static int F_170 ( struct V_35 * V_201 , char * V_1 ,
void * V_100 , T_2 V_121 )
{
int V_6 ;
struct V_18 * V_22 ;
struct V_18 * V_337 ;
struct V_93 * V_197 ;
char * V_338 ;
if ( V_201 != V_339 )
return - V_128 ;
if ( ! F_22 ( V_127 ) )
return - V_128 ;
if ( V_100 == NULL || V_121 == 0 || V_121 >= V_8 )
return - V_129 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_129 ;
V_338 = F_2 ( V_100 , V_121 ) ;
if ( V_338 == NULL )
return - V_129 ;
if ( V_338 == V_340 . V_48 )
return - V_128 ;
V_337 = V_201 -> V_93 -> V_94 ;
V_197 = F_171 () ;
if ( V_197 == NULL )
return - V_33 ;
V_22 = F_6 ( V_338 , V_337 -> V_24 , V_14 ) ;
if ( V_22 == NULL ) {
F_26 ( V_197 ) ;
return - V_33 ;
}
V_6 = F_8 ( & V_22 -> V_25 , & V_337 -> V_25 , V_14 ) ;
if ( V_6 != 0 )
return V_6 ;
V_197 -> V_94 = V_22 ;
F_172 ( V_197 ) ;
return V_121 ;
}
static int F_173 ( struct V_141 * V_141 ,
struct V_141 * V_341 , struct V_141 * V_342 )
{
struct V_138 * V_139 = V_141 -> V_148 ;
struct V_138 * V_343 = V_341 -> V_148 ;
struct V_38 V_39 ;
int V_6 = 0 ;
F_15 ( & V_39 , V_40 , V_254 ) ;
F_174 ( & V_39 , V_341 ) ;
if ( ! F_22 ( V_46 ) )
V_6 = V_185 ( V_139 -> V_152 , V_343 -> V_150 , V_88 , & V_39 ) ;
return V_6 ;
}
static int F_175 ( struct V_140 * V_141 , struct V_140 * V_341 )
{
struct V_138 * V_139 = V_141 -> V_147 -> V_148 ;
struct V_138 * V_343 = V_341 -> V_147 -> V_148 ;
struct V_38 V_39 ;
int V_6 = 0 ;
F_15 ( & V_39 , V_40 , V_254 ) ;
F_174 ( & V_39 , V_341 -> V_147 ) ;
if ( ! F_22 ( V_46 ) )
V_6 = V_185 ( V_139 -> V_152 , V_343 -> V_150 , V_88 , & V_39 ) ;
return V_6 ;
}
static int F_176 ( struct V_140 * V_141 , struct V_344 * V_276 ,
int V_121 )
{
struct V_214 * V_215 = (struct V_214 * ) V_276 -> V_345 ;
if ( V_215 == NULL || V_215 -> V_258 != V_346 )
return 0 ;
return F_129 ( V_141 -> V_147 , V_215 ) ;
}
static void F_177 ( struct V_227 * V_228 , char * V_215 )
{
char V_12 [ V_8 ] ;
char * V_45 ;
int V_347 ;
if ( ( V_228 -> V_71 & V_242 ) != 0 ) {
memset ( V_12 , '\0' , V_8 ) ;
if ( ( V_228 -> V_71 & V_232 ) != 0 )
for ( V_347 = - 1 ; ; ) {
V_347 = F_178 (
V_228 -> V_233 . V_234 . V_230 , V_347 + 1 ) ;
if ( V_347 < 0 )
break;
F_179 ( V_347 , V_12 ) ;
}
if ( V_228 -> V_233 . V_234 . V_243 == V_246 ) {
memcpy ( V_215 , V_12 , V_348 ) ;
return;
}
F_180 ( V_228 -> V_233 . V_234 . V_243 , V_12 , V_215 ) ;
return;
}
if ( ( V_228 -> V_71 & V_349 ) != 0 ) {
V_45 = F_92 ( V_228 -> V_233 . V_154 ) ;
F_181 ( V_45 == NULL ) ;
strncpy ( V_215 , V_45 , V_348 ) ;
return;
}
strncpy ( V_215 , V_249 , V_348 ) ;
return;
}
static int F_182 ( struct V_141 * V_147 , struct V_350 * V_351 )
{
struct V_227 V_248 ;
struct V_138 * V_139 = V_147 -> V_148 ;
char V_12 [ V_8 ] ;
char * V_212 ;
int V_6 ;
struct V_38 V_39 ;
if ( V_147 -> V_251 != V_269 && V_147 -> V_251 != V_352 )
return 0 ;
F_124 ( & V_248 ) ;
V_6 = F_183 ( V_351 , V_147 -> V_251 , & V_248 ) ;
if ( V_6 == 0 ) {
F_177 ( & V_248 , V_12 ) ;
V_212 = V_12 ;
} else
V_212 = V_249 ;
F_126 ( & V_248 ) ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_254 ) ;
V_39 . V_255 . V_256 . V_257 . V_210 = V_147 -> V_251 ;
V_39 . V_255 . V_256 . V_257 . V_353 = V_351 -> V_354 ;
F_184 ( V_351 , & V_39 . V_255 , NULL ) ;
#endif
V_6 = V_185 ( V_212 , V_139 -> V_150 , V_88 , & V_39 ) ;
if ( V_6 != 0 )
F_185 ( V_351 , V_6 , 0 ) ;
return V_6 ;
}
static int F_186 ( struct V_140 * V_141 ,
char T_5 * V_355 ,
int T_5 * V_356 , unsigned V_101 )
{
struct V_138 * V_139 ;
int V_336 ;
int V_6 = 0 ;
V_139 = V_141 -> V_147 -> V_148 ;
V_336 = strlen ( V_139 -> V_213 ) + 1 ;
if ( V_336 > V_101 )
V_6 = - V_357 ;
else if ( F_187 ( V_355 , V_139 -> V_213 , V_336 ) != 0 )
V_6 = - V_358 ;
if ( F_188 ( V_336 , V_356 ) != 0 )
V_6 = - V_358 ;
return V_6 ;
}
static int F_189 ( struct V_140 * V_141 ,
struct V_350 * V_351 , T_3 * V_154 )
{
struct V_227 V_248 ;
struct V_138 * V_45 ;
char V_12 [ V_8 ] ;
int V_210 = V_359 ;
T_3 V_360 = 0 ;
int V_6 ;
if ( V_351 != NULL ) {
if ( V_351 -> V_267 == F_190 ( V_361 ) )
V_210 = V_269 ;
else if ( V_351 -> V_267 == F_190 ( V_362 ) )
V_210 = V_352 ;
}
if ( V_210 == V_359 && V_141 != NULL )
V_210 = V_141 -> V_147 -> V_251 ;
if ( V_210 == V_265 ) {
V_45 = V_141 -> V_147 -> V_148 ;
V_360 = F_67 ( V_45 -> V_152 ) ;
} else if ( V_210 == V_269 || V_210 == V_352 ) {
F_124 ( & V_248 ) ;
V_6 = F_183 ( V_351 , V_210 , & V_248 ) ;
if ( V_6 == 0 ) {
F_177 ( & V_248 , V_12 ) ;
V_360 = F_67 ( V_12 ) ;
}
F_126 ( & V_248 ) ;
}
* V_154 = V_360 ;
if ( V_360 == 0 )
return - V_129 ;
return 0 ;
}
static void F_191 ( struct V_141 * V_147 , struct V_140 * V_363 )
{
struct V_138 * V_139 ;
if ( V_147 == NULL ||
( V_147 -> V_251 != V_269 && V_147 -> V_251 != V_352 ) )
return;
V_139 = V_147 -> V_148 ;
V_139 -> V_150 = V_139 -> V_152 = F_21 () ;
}
static int F_192 ( struct V_141 * V_147 , struct V_350 * V_351 ,
struct V_364 * V_365 )
{
T_6 V_210 = V_147 -> V_251 ;
struct V_138 * V_139 = V_147 -> V_148 ;
struct V_227 V_248 ;
struct V_214 V_175 ;
struct V_366 * V_367 ;
char V_12 [ V_8 ] ;
int V_6 ;
struct V_38 V_39 ;
if ( V_210 == V_352 && V_351 -> V_267 == F_190 ( V_361 ) )
V_210 = V_269 ;
F_124 ( & V_248 ) ;
V_6 = F_183 ( V_351 , V_210 , & V_248 ) ;
if ( V_6 == 0 )
F_177 ( & V_248 , V_12 ) ;
else
strncpy ( V_12 , V_368 . V_48 , V_348 ) ;
F_126 ( & V_248 ) ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_254 ) ;
V_39 . V_255 . V_256 . V_257 . V_210 = V_210 ;
V_39 . V_255 . V_256 . V_257 . V_353 = V_351 -> V_354 ;
F_184 ( V_351 , & V_39 . V_255 , NULL ) ;
#endif
V_6 = V_185 ( V_12 , V_139 -> V_150 , V_88 , & V_39 ) ;
if ( V_6 != 0 )
return V_6 ;
V_365 -> V_369 = F_67 ( V_12 ) ;
V_367 = F_193 ( V_351 ) ;
V_175 . V_220 . V_221 = V_367 -> V_370 ;
F_45 () ;
if ( F_114 ( & V_175 ) == NULL ) {
F_47 () ;
F_124 ( & V_248 ) ;
F_118 ( V_12 , & V_248 ) ;
V_6 = F_194 ( V_365 , & V_248 ) ;
F_126 ( & V_248 ) ;
} else {
F_47 () ;
F_195 ( V_365 ) ;
}
return V_6 ;
}
static void F_196 ( struct V_141 * V_147 ,
const struct V_364 * V_365 )
{
struct V_138 * V_139 = V_147 -> V_148 ;
char * V_12 ;
if ( V_365 -> V_369 != 0 ) {
V_12 = F_92 ( V_365 -> V_369 ) ;
strncpy ( V_139 -> V_213 , V_12 , V_348 ) ;
} else
V_139 -> V_213 [ 0 ] = '\0' ;
}
static int F_197 ( struct V_371 * V_371 , const struct V_93 * V_93 ,
unsigned long V_71 )
{
V_371 -> V_94 = F_13 ( V_93 -> V_94 ) ;
return 0 ;
}
static void F_198 ( struct V_371 * V_371 )
{
V_371 -> V_94 = NULL ;
}
static int F_199 ( T_7 V_372 ,
const struct V_93 * V_93 , T_8 V_373 )
{
struct V_371 * V_374 ;
struct V_38 V_39 ;
char * V_22 = F_13 ( V_93 -> V_94 ) ;
V_374 = F_200 ( V_372 ) ;
if ( V_374 == NULL )
return - V_129 ;
if ( V_374 -> V_94 == NULL )
return 0 ;
if ( V_22 == NULL )
return - V_49 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_375 ) ;
V_39 . V_255 . V_256 . V_376 . V_371 = V_374 -> V_377 ;
V_39 . V_255 . V_256 . V_376 . V_378 = V_374 -> V_379 ;
#endif
return V_185 ( V_22 , V_374 -> V_94 ,
V_42 , & V_39 ) ;
}
static int F_201 ( T_3 V_380 , T_3 V_76 , char * V_381 , void * * V_382 )
{
char * * V_383 = ( char * * ) V_382 ;
* V_383 = NULL ;
if ( V_380 != V_384 && V_380 != V_385 )
return - V_129 ;
if ( V_76 != V_386 && V_76 != V_387 )
return - V_129 ;
* V_383 = F_2 ( V_381 , 0 ) ;
return 0 ;
}
static int F_202 ( struct V_388 * V_389 )
{
struct V_390 * V_391 ;
int V_392 ;
for ( V_392 = 0 ; V_392 < V_389 -> V_393 ; V_392 ++ ) {
V_391 = & V_389 -> V_394 [ V_392 ] ;
if ( V_391 -> type == V_384 || V_391 -> type == V_385 )
return 1 ;
}
return 0 ;
}
static int F_203 ( T_3 V_154 , T_3 V_380 , T_3 V_76 , void * V_382 ,
struct V_395 * V_396 )
{
char * V_12 ;
char * V_383 = V_382 ;
if ( ! V_383 ) {
F_204 ( V_396 , V_14 , V_397 ,
L_4 ) ;
return - V_184 ;
}
if ( V_380 != V_384 && V_380 != V_385 )
return 0 ;
V_12 = F_92 ( V_154 ) ;
if ( V_76 == V_386 )
return ( V_383 == V_12 ) ;
if ( V_76 == V_387 )
return ( V_383 != V_12 ) ;
return 0 ;
}
static void F_205 ( void * V_382 )
{
}
static int F_206 ( T_3 V_154 , char * * V_398 , T_3 * V_399 )
{
char * V_45 = F_92 ( V_154 ) ;
if ( V_398 )
* V_398 = V_45 ;
* V_399 = strlen ( V_45 ) ;
return 0 ;
}
static int F_207 ( const char * V_398 , T_3 V_399 , T_3 * V_154 )
{
* V_154 = F_67 ( V_398 ) ;
return 0 ;
}
static void F_208 ( char * V_398 , T_3 V_399 )
{
}
static int F_209 ( struct V_2 * V_2 , void * V_400 , T_3 V_401 )
{
return F_131 ( V_2 , V_104 , V_400 , V_401 , 0 ) ;
}
static int F_210 ( struct V_4 * V_4 , void * V_400 , T_3 V_401 )
{
return F_211 ( V_4 , V_122 , V_400 , V_401 , 0 ) ;
}
static int F_212 ( struct V_2 * V_2 , void * * V_400 , T_3 * V_401 )
{
int V_101 = 0 ;
V_101 = F_63 ( V_2 , V_104 , V_400 , true ) ;
if ( V_101 < 0 )
return V_101 ;
* V_401 = V_101 ;
return 0 ;
}
static T_9 void F_213 ( void )
{
F_214 ( & V_368 . V_34 , & V_402 ) ;
F_214 ( & V_58 . V_34 , & V_402 ) ;
F_214 ( & V_330 . V_34 , & V_402 ) ;
F_214 ( & V_47 . V_34 , & V_402 ) ;
F_214 ( & V_133 . V_34 , & V_402 ) ;
F_214 ( & V_340 . V_34 , & V_402 ) ;
}
static T_9 int F_215 ( void )
{
struct V_93 * V_93 ;
struct V_18 * V_22 ;
if ( ! F_216 ( & V_403 ) )
return 0 ;
V_22 = F_6 ( V_47 . V_48 ,
V_47 . V_48 , V_14 ) ;
if ( V_22 == NULL )
return - V_33 ;
F_132 ( V_404 L_5 ) ;
V_93 = (struct V_93 * ) V_339 -> V_93 ;
V_93 -> V_94 = V_22 ;
F_213 () ;
F_24 ( & V_368 . V_405 ) ;
F_24 ( & V_58 . V_405 ) ;
F_24 ( & V_330 . V_405 ) ;
F_24 ( & V_47 . V_405 ) ;
F_24 ( & V_133 . V_405 ) ;
if ( F_217 ( & V_403 ) )
F_218 ( L_6 ) ;
return 0 ;
}

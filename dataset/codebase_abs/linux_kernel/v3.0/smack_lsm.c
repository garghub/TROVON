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
static int F_54 ( struct V_2 * V_2 , int V_111 , unsigned V_71 )
{
struct V_38 V_39 ;
V_111 &= ( V_82 | V_88 | V_112 | V_113 ) ;
if ( V_111 == 0 )
return 0 ;
if ( V_71 & V_114 )
return - V_115 ;
F_15 ( & V_39 , V_40 , V_116 ) ;
F_51 ( & V_39 , V_2 ) ;
return F_17 ( F_43 ( V_2 ) , V_111 , & V_39 ) ;
}
static int F_55 ( struct V_4 * V_4 , struct V_117 * V_117 )
{
struct V_38 V_39 ;
if ( V_117 -> V_118 & V_119 )
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
const void * V_100 , T_2 V_120 , int V_71 )
{
struct V_38 V_39 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_121 ) == 0 ||
strcmp ( V_1 , V_122 ) == 0 ||
strcmp ( V_1 , V_123 ) == 0 ||
strcmp ( V_1 , V_124 ) == 0 ||
strcmp ( V_1 , V_125 ) == 0 ) {
if ( ! F_22 ( V_126 ) )
V_6 = - V_127 ;
if ( V_120 == 0 || V_120 >= V_8 ||
F_2 ( V_100 , V_120 ) == NULL )
V_6 = - V_128 ;
} else if ( strcmp ( V_1 , V_129 ) == 0 ) {
if ( ! F_22 ( V_126 ) )
V_6 = - V_127 ;
if ( V_120 != V_130 ||
strncmp ( V_100 , V_131 , V_130 ) != 0 )
V_6 = - V_128 ;
} else
V_6 = F_58 ( V_4 , V_1 , V_100 , V_120 , V_71 ) ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_17 ( F_43 ( V_4 -> V_75 ) , V_88 , & V_39 ) ;
return V_6 ;
}
static void F_59 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_100 , T_2 V_120 , int V_71 )
{
char * V_77 ;
struct V_11 * V_13 = V_4 -> V_75 -> V_78 ;
if ( strcmp ( V_1 , V_121 ) == 0 ) {
V_77 = F_2 ( V_100 , V_120 ) ;
if ( V_77 != NULL )
V_13 -> V_15 = V_77 ;
else
V_13 -> V_15 = V_132 . V_48 ;
} else if ( strcmp ( V_1 , V_124 ) == 0 ) {
V_77 = F_2 ( V_100 , V_120 ) ;
if ( V_77 != NULL )
V_13 -> V_23 = V_77 ;
else
V_13 -> V_23 = V_132 . V_48 ;
} else if ( strcmp ( V_1 , V_125 ) == 0 ) {
V_77 = F_2 ( V_100 , V_120 ) ;
if ( V_77 != NULL )
V_13 -> V_133 = V_77 ;
else
V_13 -> V_133 = V_132 . V_48 ;
} else if ( strcmp ( V_1 , V_129 ) == 0 )
V_13 -> V_16 |= V_134 ;
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
if ( strcmp ( V_1 , V_121 ) == 0 ||
strcmp ( V_1 , V_122 ) == 0 ||
strcmp ( V_1 , V_123 ) == 0 ||
strcmp ( V_1 , V_124 ) == 0 ||
strcmp ( V_1 , V_129 ) == 0 ||
strcmp ( V_1 , V_125 ) ) {
if ( ! F_22 ( V_126 ) )
V_6 = - V_127 ;
} else
V_6 = F_62 ( V_4 , V_1 ) ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_17 ( F_43 ( V_4 -> V_75 ) , V_88 , & V_39 ) ;
if ( V_6 == 0 ) {
V_13 = V_4 -> V_75 -> V_78 ;
V_13 -> V_23 = NULL ;
V_13 -> V_133 = NULL ;
}
return V_6 ;
}
static int F_63 ( const struct V_2 * V_2 ,
const char * V_1 , void * * V_135 ,
bool V_136 )
{
struct V_137 * V_138 ;
struct V_139 * V_140 ;
struct V_50 * V_79 ;
struct V_2 * V_3 = (struct V_2 * ) V_2 ;
char * V_13 ;
int V_141 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_104 ) == 0 ) {
V_13 = F_43 ( V_2 ) ;
V_141 = strlen ( V_13 ) + 1 ;
* V_135 = V_13 ;
return V_141 ;
}
V_79 = V_3 -> V_142 ;
if ( V_79 -> V_143 != V_144 )
return - V_145 ;
V_140 = F_64 ( V_3 ) ;
if ( V_140 == NULL || V_140 -> V_146 == NULL )
return - V_145 ;
V_138 = V_140 -> V_146 -> V_147 ;
if ( strcmp ( V_1 , V_148 ) == 0 )
V_13 = V_138 -> V_149 ;
else if ( strcmp ( V_1 , V_150 ) == 0 )
V_13 = V_138 -> V_151 ;
else
return - V_145 ;
V_141 = strlen ( V_13 ) + 1 ;
if ( V_6 == 0 ) {
* V_135 = V_13 ;
V_6 = V_141 ;
}
return V_6 ;
}
static int F_65 ( struct V_2 * V_2 , char * V_135 ,
T_2 V_152 )
{
int V_101 = strlen ( V_121 ) ;
if ( V_135 != NULL && V_101 <= V_152 ) {
memcpy ( V_135 , V_121 , V_101 ) ;
return V_101 ;
}
return - V_128 ;
}
static void F_66 ( const struct V_2 * V_2 , T_3 * V_153 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
* V_153 = F_67 ( V_13 -> V_15 ) ;
}
static int F_68 ( struct V_96 * V_96 , int V_111 )
{
return 0 ;
}
static int F_69 ( struct V_96 * V_96 )
{
V_96 -> V_154 = F_21 () ;
return 0 ;
}
static void F_70 ( struct V_96 * V_96 )
{
V_96 -> V_154 = NULL ;
}
static int F_71 ( struct V_96 * V_96 , unsigned int V_155 ,
unsigned long V_156 )
{
int V_6 = 0 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_96 -> V_157 ) ;
if ( F_72 ( V_155 ) & V_158 )
V_6 = F_17 ( V_96 -> V_154 , V_88 , & V_39 ) ;
if ( V_6 == 0 && ( F_72 ( V_155 ) & V_159 ) )
V_6 = F_17 ( V_96 -> V_154 , V_82 , & V_39 ) ;
return V_6 ;
}
static int F_73 ( struct V_96 * V_96 , unsigned int V_155 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_96 -> V_157 ) ;
return F_17 ( V_96 -> V_154 , V_88 , & V_39 ) ;
}
static int F_74 ( struct V_96 * V_96 , unsigned int V_155 ,
unsigned long V_156 )
{
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_87 ) ;
F_36 ( & V_39 , V_96 -> V_157 ) ;
switch ( V_155 ) {
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
V_6 = F_17 ( V_96 -> V_154 , V_82 , & V_39 ) ;
break;
case V_166 :
case V_167 :
case V_168 :
case V_169 :
case V_170 :
case V_171 :
V_6 = F_17 ( V_96 -> V_154 , V_88 , & V_39 ) ;
break;
default:
V_6 = F_17 ( V_96 -> V_154 , V_42 , & V_39 ) ;
}
return V_6 ;
}
static int F_75 ( struct V_96 * V_96 ,
unsigned long V_172 , unsigned long V_173 ,
unsigned long V_71 , unsigned long V_174 ,
unsigned long V_175 )
{
struct V_30 * V_176 ;
struct V_18 * V_22 ;
char * V_45 ;
char * V_177 ;
char * V_178 ;
struct V_11 * V_13 ;
struct V_4 * V_5 ;
int V_103 ;
int V_179 ;
int V_180 ;
int V_6 ;
V_6 = F_76 ( V_96 , V_172 , V_173 , V_71 , V_174 , V_175 ) ;
if ( V_6 || V_175 )
return V_6 ;
if ( V_96 == NULL || V_96 -> V_97 == NULL )
return 0 ;
V_5 = V_96 -> V_97 ;
if ( V_5 -> V_75 == NULL )
return 0 ;
V_13 = V_5 -> V_75 -> V_78 ;
if ( V_13 -> V_133 == NULL )
return 0 ;
V_177 = V_13 -> V_133 ;
V_22 = F_77 () ;
V_45 = F_21 () ;
V_6 = 0 ;
F_45 () ;
F_9 (srp, &smack_rule_list, list) {
if ( V_176 -> V_181 != V_45 )
continue;
V_178 = V_176 -> V_182 ;
if ( V_177 == V_178 )
continue;
V_103 = F_46 ( V_176 -> V_181 , V_178 ,
& V_22 -> V_25 ) ;
if ( V_103 == - V_183 )
V_103 = V_176 -> V_184 ;
else
V_103 &= V_176 -> V_184 ;
if ( V_103 == 0 )
continue;
V_179 = F_46 ( V_177 , V_178 , & V_105 ) ;
if ( V_179 == - V_183 ) {
V_6 = - V_49 ;
break;
}
V_180 = F_46 ( V_177 , V_178 , & V_22 -> V_25 ) ;
if ( V_180 != - V_183 )
V_179 &= V_180 ;
if ( ( V_103 | V_179 ) != V_179 ) {
V_6 = - V_49 ;
break;
}
}
F_47 () ;
return V_6 ;
}
static int F_78 ( struct V_96 * V_96 )
{
V_96 -> V_154 = F_21 () ;
return 0 ;
}
static int F_79 ( struct V_35 * V_185 ,
struct V_186 * V_187 , int V_188 )
{
struct V_96 * V_96 ;
int V_6 ;
char * V_22 = F_13 ( V_185 -> V_93 -> V_94 ) ;
struct V_38 V_39 ;
V_96 = F_80 ( V_187 , struct V_96 , V_189 ) ;
V_6 = V_184 ( V_96 -> V_154 , V_22 , V_88 , NULL ) ;
if ( V_6 != 0 && F_81 ( V_185 , V_46 ) )
V_6 = 0 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_185 ) ;
F_82 ( V_96 -> V_154 , V_22 , V_88 , V_6 , & V_39 ) ;
return V_6 ;
}
static int F_83 ( struct V_96 * V_96 )
{
int V_103 = 0 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_36 ( & V_39 , V_96 -> V_157 ) ;
if ( V_96 -> V_190 & V_191 )
V_103 = V_82 ;
if ( V_96 -> V_190 & V_192 )
V_103 |= V_88 ;
return F_17 ( V_96 -> V_154 , V_103 , & V_39 ) ;
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
struct V_30 * V_193 ;
struct V_27 * V_194 ;
struct V_27 * V_195 ;
if ( V_22 == NULL )
return;
V_93 -> V_94 = NULL ;
F_86 (l, n, &tsp->smk_rules) {
V_193 = F_87 ( V_194 , struct V_30 , V_34 ) ;
F_88 ( & V_193 -> V_34 ) ;
F_26 ( V_193 ) ;
}
F_26 ( V_22 ) ;
}
static int F_89 ( struct V_93 * V_196 , const struct V_93 * V_197 ,
T_1 V_21 )
{
struct V_18 * V_198 = V_197 -> V_94 ;
struct V_18 * V_199 ;
int V_6 ;
V_199 = F_6 ( V_198 -> V_23 , V_198 -> V_23 , V_21 ) ;
if ( V_199 == NULL )
return - V_33 ;
V_6 = F_8 ( & V_199 -> V_25 , & V_198 -> V_25 , V_21 ) ;
if ( V_6 != 0 )
return V_6 ;
V_196 -> V_94 = V_199 ;
return 0 ;
}
static void F_90 ( struct V_93 * V_196 , const struct V_93 * V_197 )
{
struct V_18 * V_198 = V_197 -> V_94 ;
struct V_18 * V_199 = V_196 -> V_94 ;
V_199 -> V_23 = V_198 -> V_23 ;
V_199 -> V_24 = V_198 -> V_23 ;
F_5 ( & V_199 -> V_26 ) ;
F_7 ( & V_199 -> V_25 ) ;
}
static int F_91 ( struct V_93 * V_196 , T_3 V_153 )
{
struct V_18 * V_199 = V_196 -> V_94 ;
char * V_12 = F_92 ( V_153 ) ;
if ( V_12 == NULL )
return - V_128 ;
V_199 -> V_23 = V_12 ;
return 0 ;
}
static int F_93 ( struct V_93 * V_196 ,
struct V_2 * V_2 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
struct V_18 * V_22 = V_196 -> V_94 ;
V_22 -> V_24 = V_13 -> V_15 ;
V_22 -> V_23 = V_13 -> V_15 ;
return 0 ;
}
static int F_94 ( struct V_35 * V_200 , int V_201 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_200 ) ;
return F_17 ( F_13 ( F_14 ( V_200 ) ) , V_201 , & V_39 ) ;
}
static int F_95 ( struct V_35 * V_200 , T_4 V_202 )
{
return F_94 ( V_200 , V_88 ) ;
}
static int F_96 ( struct V_35 * V_200 )
{
return F_94 ( V_200 , V_82 ) ;
}
static int F_97 ( struct V_35 * V_200 )
{
return F_94 ( V_200 , V_82 ) ;
}
static void F_98 ( struct V_35 * V_200 , T_3 * V_153 )
{
* V_153 = F_67 ( F_13 ( F_14 ( V_200 ) ) ) ;
}
static int F_99 ( struct V_35 * V_200 , int V_203 )
{
int V_6 ;
V_6 = F_100 ( V_200 , V_203 ) ;
if ( V_6 == 0 )
V_6 = F_94 ( V_200 , V_88 ) ;
return V_6 ;
}
static int F_101 ( struct V_35 * V_200 , int V_204 )
{
int V_6 ;
V_6 = F_102 ( V_200 , V_204 ) ;
if ( V_6 == 0 )
V_6 = F_94 ( V_200 , V_88 ) ;
return V_6 ;
}
static int F_103 ( struct V_35 * V_200 )
{
return F_94 ( V_200 , V_82 ) ;
}
static int F_104 ( struct V_35 * V_200 )
{
int V_6 ;
V_6 = F_105 ( V_200 ) ;
if ( V_6 == 0 )
V_6 = F_94 ( V_200 , V_88 ) ;
return V_6 ;
}
static int F_106 ( struct V_35 * V_200 )
{
return F_94 ( V_200 , V_82 ) ;
}
static int F_107 ( struct V_35 * V_200 )
{
return F_94 ( V_200 , V_88 ) ;
}
static int F_108 ( struct V_35 * V_200 , struct V_205 * V_206 ,
int V_207 , T_3 V_153 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_200 ) ;
if ( V_153 == 0 )
return F_17 ( F_13 ( F_14 ( V_200 ) ) , V_88 ,
& V_39 ) ;
return V_184 ( F_92 ( V_153 ) ,
F_13 ( F_14 ( V_200 ) ) , V_88 , & V_39 ) ;
}
static int F_109 ( struct V_35 * V_200 )
{
struct V_38 V_39 ;
char * V_45 = F_21 () ;
char * V_22 = F_110 ( F_14 ( V_200 ) ) ;
int V_6 ;
V_6 = V_184 ( V_22 , V_45 , V_88 , NULL ) ;
if ( V_6 == 0 )
goto V_208;
if ( F_22 ( V_46 ) || F_81 ( V_200 , V_46 ) )
V_6 = 0 ;
V_208:
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_200 ) ;
F_82 ( V_22 , V_45 , V_88 , V_6 , & V_39 ) ;
return V_6 ;
}
static void F_111 ( struct V_35 * V_200 , struct V_2 * V_2 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
V_13 -> V_15 = F_13 ( F_14 ( V_200 ) ) ;
}
static int F_112 ( struct V_140 * V_146 , int V_209 , T_1 V_210 )
{
char * V_211 = F_21 () ;
struct V_137 * V_138 ;
V_138 = F_4 ( sizeof( struct V_137 ) , V_210 ) ;
if ( V_138 == NULL )
return - V_33 ;
V_138 -> V_149 = V_211 ;
V_138 -> V_151 = V_211 ;
V_138 -> V_212 [ 0 ] = '\0' ;
V_146 -> V_147 = V_138 ;
return 0 ;
}
static void F_113 ( struct V_140 * V_146 )
{
F_26 ( V_146 -> V_147 ) ;
}
static char * F_114 ( struct V_213 * V_214 )
{
struct V_215 * V_216 ;
struct V_217 * V_218 = & V_214 -> V_219 ;
if ( V_218 -> V_220 == 0 )
return NULL ;
F_9 (snp, &smk_netlbladdr_list, list)
if ( ( & V_216 -> V_221 . V_219 ) -> V_220 ==
( V_218 -> V_220 & ( & V_216 -> V_222 ) -> V_220 ) ) {
if ( V_216 -> V_223 == V_224 )
return NULL ;
return V_216 -> V_223 ;
}
return NULL ;
}
static void F_115 ( char * V_225 , struct V_226 * V_227 )
{
unsigned char * V_64 ;
unsigned char V_228 ;
int V_229 ;
int V_6 ;
int V_230 ;
if ( ! V_225 )
return;
V_227 -> V_71 |= V_231 ;
V_227 -> V_232 . V_233 . V_229 = F_116 ( V_234 ) ;
V_227 -> V_232 . V_233 . V_229 -> V_235 = 0 ;
for ( V_229 = 1 , V_64 = V_225 , V_230 = 0 ; V_230 < V_8 ; V_64 ++ , V_230 ++ )
for ( V_228 = 0x80 ; V_228 != 0 ; V_228 >>= 1 , V_229 ++ ) {
if ( ( V_228 & * V_64 ) == 0 )
continue;
V_6 = F_117 ( V_227 -> V_232 . V_233 . V_229 ,
V_229 , V_234 ) ;
}
}
static void F_118 ( char * V_12 , struct V_226 * V_236 )
{
struct V_237 V_238 ;
int V_6 ;
V_236 -> V_239 = V_12 ;
V_236 -> V_71 = V_240 | V_241 ;
V_6 = F_119 ( V_12 , & V_238 ) ;
if ( V_6 == 0 ) {
V_236 -> V_232 . V_233 . V_242 = V_238 . V_243 ;
F_115 ( V_238 . V_244 , V_236 ) ;
} else {
V_236 -> V_232 . V_233 . V_242 = V_245 ;
F_115 ( V_12 , V_236 ) ;
}
}
static int F_120 ( struct V_140 * V_146 , int V_246 )
{
struct V_137 * V_138 = V_146 -> V_147 ;
struct V_226 V_247 ;
int V_6 = 0 ;
F_121 () ;
F_122 ( V_146 ) ;
if ( V_138 -> V_151 == V_248 ||
V_246 == V_249 )
F_123 ( V_146 ) ;
else {
F_124 ( & V_247 ) ;
F_118 ( V_138 -> V_151 , & V_247 ) ;
V_6 = F_125 ( V_146 , V_146 -> V_250 , & V_247 ) ;
F_126 ( & V_247 ) ;
}
F_127 ( V_146 ) ;
F_128 () ;
return V_6 ;
}
static int F_129 ( struct V_140 * V_146 , struct V_213 * V_227 )
{
int V_6 ;
int V_251 ;
char * V_252 ;
struct V_137 * V_138 = V_146 -> V_147 ;
struct V_38 V_39 ;
F_45 () ;
V_252 = F_114 ( V_227 ) ;
if ( V_252 != NULL ) {
V_251 = V_249 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_253 ) ;
V_39 . V_254 . V_255 . V_256 . V_209 = V_227 -> V_257 ;
V_39 . V_254 . V_255 . V_256 . V_258 = V_227 -> V_259 ;
V_39 . V_254 . V_255 . V_256 . V_260 . V_261 = V_227 -> V_219 . V_220 ;
#endif
V_6 = V_184 ( V_138 -> V_151 , V_252 , V_88 , & V_39 ) ;
} else {
V_251 = V_262 ;
V_6 = 0 ;
}
F_47 () ;
if ( V_6 != 0 )
return V_6 ;
return F_120 ( V_146 , V_251 ) ;
}
static int F_131 ( struct V_2 * V_2 , const char * V_1 ,
const void * V_100 , T_2 V_120 , int V_71 )
{
char * V_45 ;
struct V_11 * V_77 = V_2 -> V_78 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
int V_6 = 0 ;
if ( V_100 == NULL || V_120 > V_8 || V_120 == 0 )
return - V_49 ;
V_45 = F_2 ( V_100 , V_120 ) ;
if ( V_45 == NULL )
return - V_128 ;
if ( strcmp ( V_1 , V_104 ) == 0 ) {
V_77 -> V_15 = V_45 ;
V_77 -> V_16 |= V_263 ;
return 0 ;
}
if ( V_2 -> V_142 -> V_143 != V_144 )
return - V_145 ;
V_140 = F_64 ( V_2 ) ;
if ( V_140 == NULL || V_140 -> V_146 == NULL )
return - V_145 ;
V_138 = V_140 -> V_146 -> V_147 ;
if ( strcmp ( V_1 , V_148 ) == 0 )
V_138 -> V_149 = V_45 ;
else if ( strcmp ( V_1 , V_150 ) == 0 ) {
V_138 -> V_151 = V_45 ;
if ( V_140 -> V_146 -> V_250 != V_264 ) {
V_6 = F_120 ( V_140 -> V_146 , V_262 ) ;
if ( V_6 != 0 )
F_132 ( V_265
L_2 ,
V_40 , - V_6 ) ;
}
} else
return - V_145 ;
return 0 ;
}
static int F_133 ( struct V_139 * V_140 , int V_209 ,
int type , int V_266 , int V_267 )
{
if ( V_209 != V_268 || V_140 -> V_146 == NULL )
return 0 ;
return F_120 ( V_140 -> V_146 , V_262 ) ;
}
static int F_134 ( struct V_139 * V_140 , struct V_269 * V_227 ,
int V_270 )
{
if ( V_140 -> V_146 == NULL || V_140 -> V_146 -> V_250 != V_268 )
return 0 ;
if ( V_270 < sizeof( struct V_213 ) )
return - V_128 ;
return F_129 ( V_140 -> V_146 , (struct V_213 * ) V_227 ) ;
}
static int F_135 ( int V_71 )
{
int V_103 = 0 ;
if ( V_71 & V_271 )
V_103 |= V_82 ;
if ( V_71 & V_272 )
V_103 |= V_88 ;
if ( V_71 & V_273 )
V_103 |= V_112 ;
return V_103 ;
}
static int F_136 ( struct V_274 * V_275 )
{
V_275 -> V_94 = F_21 () ;
return 0 ;
}
static void F_137 ( struct V_274 * V_275 )
{
V_275 -> V_94 = NULL ;
}
static char * F_138 ( struct V_276 * V_277 )
{
return ( char * ) V_277 -> V_278 . V_94 ;
}
static int F_139 ( struct V_276 * V_277 )
{
struct V_279 * V_13 = & V_277 -> V_278 ;
V_13 -> V_94 = F_21 () ;
return 0 ;
}
static void F_140 ( struct V_276 * V_277 )
{
struct V_279 * V_13 = & V_277 -> V_278 ;
V_13 -> V_94 = NULL ;
}
static int F_141 ( struct V_276 * V_277 , int V_201 )
{
char * V_138 = F_138 ( V_277 ) ;
struct V_38 V_39 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_280 ) ;
V_39 . V_254 . V_255 . V_281 = V_277 -> V_278 . V_282 ;
#endif
return F_17 ( V_138 , V_201 , & V_39 ) ;
}
static int F_142 ( struct V_276 * V_277 , int V_283 )
{
int V_103 ;
V_103 = F_135 ( V_283 ) ;
return F_141 ( V_277 , V_103 ) ;
}
static int F_143 ( struct V_276 * V_277 , int V_155 )
{
int V_103 ;
switch ( V_155 ) {
case V_284 :
case V_285 :
V_103 = V_82 ;
break;
case V_286 :
case V_287 :
case V_288 :
case V_289 :
V_103 = V_42 ;
break;
case V_290 :
case V_291 :
return 0 ;
default:
return - V_128 ;
}
return F_141 ( V_277 , V_103 ) ;
}
static int F_144 ( struct V_276 * V_277 , char T_5 * V_292 ,
int V_283 )
{
int V_103 ;
V_103 = F_135 ( V_283 ) ;
return F_141 ( V_277 , V_103 ) ;
}
static char * F_145 ( struct V_293 * V_294 )
{
return ( char * ) V_294 -> V_295 . V_94 ;
}
static int F_146 ( struct V_293 * V_294 )
{
struct V_279 * V_13 = & V_294 -> V_295 ;
V_13 -> V_94 = F_21 () ;
return 0 ;
}
static void F_147 ( struct V_293 * V_294 )
{
struct V_279 * V_13 = & V_294 -> V_295 ;
V_13 -> V_94 = NULL ;
}
static int F_148 ( struct V_293 * V_294 , int V_201 )
{
char * V_138 = F_145 ( V_294 ) ;
struct V_38 V_39 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_280 ) ;
V_39 . V_254 . V_255 . V_281 = V_294 -> V_295 . V_282 ;
#endif
return F_17 ( V_138 , V_201 , & V_39 ) ;
}
static int F_149 ( struct V_293 * V_294 , int V_296 )
{
int V_103 ;
V_103 = F_135 ( V_296 ) ;
return F_148 ( V_294 , V_103 ) ;
}
static int F_150 ( struct V_293 * V_294 , int V_155 )
{
int V_103 ;
switch ( V_155 ) {
case V_297 :
case V_298 :
case V_299 :
case V_300 :
case V_301 :
case V_284 :
case V_302 :
V_103 = V_82 ;
break;
case V_303 :
case V_304 :
case V_289 :
case V_286 :
V_103 = V_42 ;
break;
case V_290 :
case V_305 :
return 0 ;
default:
return - V_128 ;
}
return F_148 ( V_294 , V_103 ) ;
}
static int F_151 ( struct V_293 * V_294 , struct V_306 * V_307 ,
unsigned V_308 , int V_309 )
{
return F_148 ( V_294 , V_42 ) ;
}
static int F_152 ( struct V_310 * V_311 )
{
struct V_279 * V_312 = & V_311 -> V_313 ;
V_312 -> V_94 = F_21 () ;
return 0 ;
}
static void F_153 ( struct V_310 * V_311 )
{
struct V_279 * V_312 = & V_311 -> V_313 ;
V_312 -> V_94 = NULL ;
}
static char * F_154 ( struct V_310 * V_311 )
{
return ( char * ) V_311 -> V_313 . V_94 ;
}
static int F_155 ( struct V_310 * V_311 , int V_201 )
{
char * V_314 = F_154 ( V_311 ) ;
struct V_38 V_39 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_280 ) ;
V_39 . V_254 . V_255 . V_281 = V_311 -> V_313 . V_282 ;
#endif
return F_17 ( V_314 , V_201 , & V_39 ) ;
}
static int F_156 ( struct V_310 * V_311 , int V_315 )
{
int V_103 ;
V_103 = F_135 ( V_315 ) ;
return F_155 ( V_311 , V_103 ) ;
}
static int F_157 ( struct V_310 * V_311 , int V_155 )
{
int V_103 ;
switch ( V_155 ) {
case V_284 :
case V_316 :
V_103 = V_82 ;
break;
case V_286 :
case V_289 :
V_103 = V_42 ;
break;
case V_290 :
case V_317 :
return 0 ;
default:
return - V_128 ;
}
return F_155 ( V_311 , V_103 ) ;
}
static int F_158 ( struct V_310 * V_311 , struct V_274 * V_275 ,
int V_315 )
{
int V_103 ;
V_103 = F_135 ( V_315 ) ;
return F_155 ( V_311 , V_103 ) ;
}
static int F_159 ( struct V_310 * V_311 , struct V_274 * V_275 ,
struct V_35 * V_318 , long type , int V_37 )
{
return F_155 ( V_311 , V_42 ) ;
}
static int F_160 ( struct V_279 * V_319 , short V_320 )
{
char * V_13 = V_319 -> V_94 ;
int V_103 = F_135 ( V_320 ) ;
struct V_38 V_39 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_280 ) ;
V_39 . V_254 . V_255 . V_281 = V_319 -> V_282 ;
#endif
return F_17 ( V_13 , V_103 , & V_39 ) ;
}
static void F_161 ( struct V_279 * V_319 , T_3 * V_153 )
{
char * V_12 = V_319 -> V_94 ;
* V_153 = F_67 ( V_12 ) ;
}
static void F_162 ( struct V_4 * V_321 , struct V_2 * V_2 )
{
struct V_50 * V_79 ;
struct V_52 * V_53 ;
struct V_11 * V_13 ;
char * V_211 = F_21 () ;
char * V_322 ;
char * V_323 ;
char V_324 [ V_130 ] ;
int V_325 = 0 ;
struct V_4 * V_5 ;
if ( V_2 == NULL )
return;
V_13 = V_2 -> V_78 ;
F_163 ( & V_13 -> V_17 ) ;
if ( V_13 -> V_16 & V_263 )
goto V_326;
V_79 = V_2 -> V_142 ;
V_53 = V_79 -> V_61 ;
V_323 = V_53 -> V_55 ;
if ( V_321 -> V_327 == V_321 ) {
V_13 -> V_15 = V_53 -> V_54 ;
V_13 -> V_16 |= V_263 ;
goto V_326;
}
switch ( V_79 -> V_143 ) {
case V_328 :
V_323 = V_329 . V_48 ;
break;
case V_330 :
V_323 = V_329 . V_48 ;
break;
case V_331 :
V_323 = V_211 ;
break;
case V_144 :
V_323 = V_329 . V_48 ;
break;
case V_332 :
break;
case V_333 :
V_323 = V_329 . V_48 ;
default:
if ( F_164 ( V_2 -> V_334 ) ) {
V_323 = V_329 . V_48 ;
break;
}
if ( V_2 -> V_9 -> V_10 == NULL )
break;
V_5 = F_165 ( V_321 ) ;
V_322 = F_1 ( V_121 , V_2 , V_5 ) ;
if ( V_322 != NULL ) {
V_323 = V_322 ;
if ( F_166 ( V_2 -> V_334 ) ) {
V_324 [ 0 ] = '\0' ;
V_2 -> V_9 -> V_10 ( V_5 ,
V_129 ,
V_324 , V_130 ) ;
if ( strncmp ( V_324 , V_131 ,
V_130 ) == 0 )
V_325 = V_134 ;
}
}
V_13 -> V_23 = F_1 ( V_124 , V_2 , V_5 ) ;
V_13 -> V_133 = F_1 ( V_125 , V_2 , V_5 ) ;
F_167 ( V_5 ) ;
break;
}
if ( V_323 == NULL )
V_13 -> V_15 = V_211 ;
else
V_13 -> V_15 = V_323 ;
V_13 -> V_16 |= ( V_263 | V_325 ) ;
V_326:
F_168 ( & V_13 -> V_17 ) ;
return;
}
static int F_169 ( struct V_35 * V_200 , char * V_1 , char * * V_100 )
{
char * V_64 ;
int V_335 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_128 ;
V_64 = F_44 ( F_13 ( F_14 ( V_200 ) ) , V_14 ) ;
if ( V_64 == NULL )
return - V_33 ;
V_335 = strlen ( V_64 ) ;
* V_100 = V_64 ;
return V_335 ;
}
static int F_170 ( struct V_35 * V_200 , char * V_1 ,
void * V_100 , T_2 V_120 )
{
int V_6 ;
struct V_18 * V_22 ;
struct V_18 * V_336 ;
struct V_93 * V_196 ;
char * V_337 ;
if ( V_200 != V_338 )
return - V_127 ;
if ( ! F_22 ( V_126 ) )
return - V_127 ;
if ( V_100 == NULL || V_120 == 0 || V_120 >= V_8 )
return - V_128 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_128 ;
V_337 = F_2 ( V_100 , V_120 ) ;
if ( V_337 == NULL )
return - V_128 ;
if ( V_337 == V_339 . V_48 )
return - V_127 ;
V_336 = V_200 -> V_93 -> V_94 ;
V_196 = F_171 () ;
if ( V_196 == NULL )
return - V_33 ;
V_22 = F_6 ( V_337 , V_336 -> V_24 , V_14 ) ;
if ( V_22 == NULL ) {
F_26 ( V_196 ) ;
return - V_33 ;
}
V_6 = F_8 ( & V_22 -> V_25 , & V_336 -> V_25 , V_14 ) ;
if ( V_6 != 0 )
return V_6 ;
V_196 -> V_94 = V_22 ;
F_172 ( V_196 ) ;
return V_120 ;
}
static int F_173 ( struct V_140 * V_140 ,
struct V_140 * V_340 , struct V_140 * V_341 )
{
struct V_137 * V_138 = V_140 -> V_147 ;
struct V_137 * V_342 = V_340 -> V_147 ;
struct V_38 V_39 ;
int V_6 = 0 ;
F_15 ( & V_39 , V_40 , V_253 ) ;
F_174 ( & V_39 , V_340 ) ;
if ( ! F_22 ( V_46 ) )
V_6 = V_184 ( V_138 -> V_151 , V_342 -> V_149 , V_88 , & V_39 ) ;
return V_6 ;
}
static int F_175 ( struct V_139 * V_140 , struct V_139 * V_340 )
{
struct V_137 * V_138 = V_140 -> V_146 -> V_147 ;
struct V_137 * V_342 = V_340 -> V_146 -> V_147 ;
struct V_38 V_39 ;
int V_6 = 0 ;
F_15 ( & V_39 , V_40 , V_253 ) ;
F_174 ( & V_39 , V_340 -> V_146 ) ;
if ( ! F_22 ( V_46 ) )
V_6 = V_184 ( V_138 -> V_151 , V_342 -> V_149 , V_88 , & V_39 ) ;
return V_6 ;
}
static int F_176 ( struct V_139 * V_140 , struct V_343 * V_275 ,
int V_120 )
{
struct V_213 * V_214 = (struct V_213 * ) V_275 -> V_344 ;
if ( V_214 == NULL || V_214 -> V_257 != V_345 )
return 0 ;
return F_129 ( V_140 -> V_146 , V_214 ) ;
}
static void F_177 ( struct V_226 * V_227 , char * V_214 )
{
char V_12 [ V_8 ] ;
char * V_45 ;
int V_346 ;
if ( ( V_227 -> V_71 & V_241 ) != 0 ) {
memset ( V_12 , '\0' , V_8 ) ;
if ( ( V_227 -> V_71 & V_231 ) != 0 )
for ( V_346 = - 1 ; ; ) {
V_346 = F_178 (
V_227 -> V_232 . V_233 . V_229 , V_346 + 1 ) ;
if ( V_346 < 0 )
break;
F_179 ( V_346 , V_12 ) ;
}
if ( V_227 -> V_232 . V_233 . V_242 == V_245 ) {
memcpy ( V_214 , V_12 , V_347 ) ;
return;
}
F_180 ( V_227 -> V_232 . V_233 . V_242 , V_12 , V_214 ) ;
return;
}
if ( ( V_227 -> V_71 & V_348 ) != 0 ) {
V_45 = F_92 ( V_227 -> V_232 . V_153 ) ;
F_181 ( V_45 == NULL ) ;
strncpy ( V_214 , V_45 , V_347 ) ;
return;
}
strncpy ( V_214 , V_248 , V_347 ) ;
return;
}
static int F_182 ( struct V_140 * V_146 , struct V_349 * V_350 )
{
struct V_226 V_247 ;
struct V_137 * V_138 = V_146 -> V_147 ;
char V_12 [ V_8 ] ;
char * V_211 ;
int V_6 ;
struct V_38 V_39 ;
if ( V_146 -> V_250 != V_268 && V_146 -> V_250 != V_351 )
return 0 ;
F_124 ( & V_247 ) ;
V_6 = F_183 ( V_350 , V_146 -> V_250 , & V_247 ) ;
if ( V_6 == 0 ) {
F_177 ( & V_247 , V_12 ) ;
V_211 = V_12 ;
} else
V_211 = V_248 ;
F_126 ( & V_247 ) ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_253 ) ;
V_39 . V_254 . V_255 . V_256 . V_209 = V_146 -> V_250 ;
V_39 . V_254 . V_255 . V_256 . V_352 = V_350 -> V_353 ;
F_184 ( V_350 , & V_39 . V_254 , NULL ) ;
#endif
V_6 = V_184 ( V_211 , V_138 -> V_149 , V_88 , & V_39 ) ;
if ( V_6 != 0 )
F_185 ( V_350 , V_6 , 0 ) ;
return V_6 ;
}
static int F_186 ( struct V_139 * V_140 ,
char T_5 * V_354 ,
int T_5 * V_355 , unsigned V_101 )
{
struct V_137 * V_138 ;
int V_335 ;
int V_6 = 0 ;
V_138 = V_140 -> V_146 -> V_147 ;
V_335 = strlen ( V_138 -> V_212 ) + 1 ;
if ( V_335 > V_101 )
V_6 = - V_356 ;
else if ( F_187 ( V_354 , V_138 -> V_212 , V_335 ) != 0 )
V_6 = - V_357 ;
if ( F_188 ( V_335 , V_355 ) != 0 )
V_6 = - V_357 ;
return V_6 ;
}
static int F_189 ( struct V_139 * V_140 ,
struct V_349 * V_350 , T_3 * V_153 )
{
struct V_226 V_247 ;
struct V_137 * V_45 ;
char V_12 [ V_8 ] ;
int V_209 = V_358 ;
T_3 V_359 = 0 ;
int V_6 ;
if ( V_350 != NULL ) {
if ( V_350 -> V_266 == F_190 ( V_360 ) )
V_209 = V_268 ;
else if ( V_350 -> V_266 == F_190 ( V_361 ) )
V_209 = V_351 ;
}
if ( V_209 == V_358 && V_140 != NULL )
V_209 = V_140 -> V_146 -> V_250 ;
if ( V_209 == V_264 ) {
V_45 = V_140 -> V_146 -> V_147 ;
V_359 = F_67 ( V_45 -> V_151 ) ;
} else if ( V_209 == V_268 || V_209 == V_351 ) {
F_124 ( & V_247 ) ;
V_6 = F_183 ( V_350 , V_209 , & V_247 ) ;
if ( V_6 == 0 ) {
F_177 ( & V_247 , V_12 ) ;
V_359 = F_67 ( V_12 ) ;
}
F_126 ( & V_247 ) ;
}
* V_153 = V_359 ;
if ( V_359 == 0 )
return - V_128 ;
return 0 ;
}
static void F_191 ( struct V_140 * V_146 , struct V_139 * V_362 )
{
struct V_137 * V_138 ;
if ( V_146 == NULL ||
( V_146 -> V_250 != V_268 && V_146 -> V_250 != V_351 ) )
return;
V_138 = V_146 -> V_147 ;
V_138 -> V_149 = V_138 -> V_151 = F_21 () ;
}
static int F_192 ( struct V_140 * V_146 , struct V_349 * V_350 ,
struct V_363 * V_364 )
{
T_6 V_209 = V_146 -> V_250 ;
struct V_137 * V_138 = V_146 -> V_147 ;
struct V_226 V_247 ;
struct V_213 V_174 ;
struct V_365 * V_366 ;
char V_12 [ V_8 ] ;
int V_6 ;
struct V_38 V_39 ;
if ( V_209 == V_351 && V_350 -> V_266 == F_190 ( V_360 ) )
V_209 = V_268 ;
F_124 ( & V_247 ) ;
V_6 = F_183 ( V_350 , V_209 , & V_247 ) ;
if ( V_6 == 0 )
F_177 ( & V_247 , V_12 ) ;
else
strncpy ( V_12 , V_367 . V_48 , V_347 ) ;
F_126 ( & V_247 ) ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_253 ) ;
V_39 . V_254 . V_255 . V_256 . V_209 = V_209 ;
V_39 . V_254 . V_255 . V_256 . V_352 = V_350 -> V_353 ;
F_184 ( V_350 , & V_39 . V_254 , NULL ) ;
#endif
V_6 = V_184 ( V_12 , V_138 -> V_149 , V_88 , & V_39 ) ;
if ( V_6 != 0 )
return V_6 ;
V_364 -> V_368 = F_67 ( V_12 ) ;
V_366 = F_193 ( V_350 ) ;
V_174 . V_219 . V_220 = V_366 -> V_369 ;
F_45 () ;
if ( F_114 ( & V_174 ) == NULL ) {
F_47 () ;
F_124 ( & V_247 ) ;
F_118 ( V_12 , & V_247 ) ;
V_6 = F_194 ( V_364 , & V_247 ) ;
F_126 ( & V_247 ) ;
} else {
F_47 () ;
F_195 ( V_364 ) ;
}
return V_6 ;
}
static void F_196 ( struct V_140 * V_146 ,
const struct V_363 * V_364 )
{
struct V_137 * V_138 = V_146 -> V_147 ;
char * V_12 ;
if ( V_364 -> V_368 != 0 ) {
V_12 = F_92 ( V_364 -> V_368 ) ;
strncpy ( V_138 -> V_212 , V_12 , V_347 ) ;
} else
V_138 -> V_212 [ 0 ] = '\0' ;
}
static int F_197 ( struct V_370 * V_370 , const struct V_93 * V_93 ,
unsigned long V_71 )
{
V_370 -> V_94 = F_13 ( V_93 -> V_94 ) ;
return 0 ;
}
static void F_198 ( struct V_370 * V_370 )
{
V_370 -> V_94 = NULL ;
}
static int F_199 ( T_7 V_371 ,
const struct V_93 * V_93 , T_8 V_372 )
{
struct V_370 * V_373 ;
struct V_38 V_39 ;
char * V_22 = F_13 ( V_93 -> V_94 ) ;
V_373 = F_200 ( V_371 ) ;
if ( V_373 == NULL )
return - V_128 ;
if ( V_373 -> V_94 == NULL )
return 0 ;
if ( V_22 == NULL )
return - V_49 ;
#ifdef F_130
F_15 ( & V_39 , V_40 , V_374 ) ;
V_39 . V_254 . V_255 . V_375 . V_370 = V_373 -> V_376 ;
V_39 . V_254 . V_255 . V_375 . V_377 = V_373 -> V_378 ;
#endif
return V_184 ( V_22 , V_373 -> V_94 ,
V_42 , & V_39 ) ;
}
static int F_201 ( T_3 V_379 , T_3 V_76 , char * V_380 , void * * V_381 )
{
char * * V_382 = ( char * * ) V_381 ;
* V_382 = NULL ;
if ( V_379 != V_383 && V_379 != V_384 )
return - V_128 ;
if ( V_76 != V_385 && V_76 != V_386 )
return - V_128 ;
* V_382 = F_2 ( V_380 , 0 ) ;
return 0 ;
}
static int F_202 ( struct V_387 * V_388 )
{
struct V_389 * V_390 ;
int V_391 ;
for ( V_391 = 0 ; V_391 < V_388 -> V_392 ; V_391 ++ ) {
V_390 = & V_388 -> V_393 [ V_391 ] ;
if ( V_390 -> type == V_383 || V_390 -> type == V_384 )
return 1 ;
}
return 0 ;
}
static int F_203 ( T_3 V_153 , T_3 V_379 , T_3 V_76 , void * V_381 ,
struct V_394 * V_395 )
{
char * V_12 ;
char * V_382 = V_381 ;
if ( ! V_382 ) {
F_204 ( V_395 , V_14 , V_396 ,
L_4 ) ;
return - V_183 ;
}
if ( V_379 != V_383 && V_379 != V_384 )
return 0 ;
V_12 = F_92 ( V_153 ) ;
if ( V_76 == V_385 )
return ( V_382 == V_12 ) ;
if ( V_76 == V_386 )
return ( V_382 != V_12 ) ;
return 0 ;
}
static void F_205 ( void * V_381 )
{
}
static int F_206 ( T_3 V_153 , char * * V_397 , T_3 * V_398 )
{
char * V_45 = F_92 ( V_153 ) ;
if ( V_397 )
* V_397 = V_45 ;
* V_398 = strlen ( V_45 ) ;
return 0 ;
}
static int F_207 ( const char * V_397 , T_3 V_398 , T_3 * V_153 )
{
* V_153 = F_67 ( V_397 ) ;
return 0 ;
}
static void F_208 ( char * V_397 , T_3 V_398 )
{
}
static int F_209 ( struct V_2 * V_2 , void * V_399 , T_3 V_400 )
{
return F_131 ( V_2 , V_104 , V_399 , V_400 , 0 ) ;
}
static int F_210 ( struct V_4 * V_4 , void * V_399 , T_3 V_400 )
{
return F_211 ( V_4 , V_121 , V_399 , V_400 , 0 ) ;
}
static int F_212 ( struct V_2 * V_2 , void * * V_399 , T_3 * V_400 )
{
int V_101 = 0 ;
V_101 = F_63 ( V_2 , V_104 , V_399 , true ) ;
if ( V_101 < 0 )
return V_101 ;
* V_400 = V_101 ;
return 0 ;
}
static T_9 void F_213 ( void )
{
F_214 ( & V_367 . V_34 , & V_401 ) ;
F_214 ( & V_58 . V_34 , & V_401 ) ;
F_214 ( & V_329 . V_34 , & V_401 ) ;
F_214 ( & V_47 . V_34 , & V_401 ) ;
F_214 ( & V_132 . V_34 , & V_401 ) ;
F_214 ( & V_339 . V_34 , & V_401 ) ;
}
static T_9 int F_215 ( void )
{
struct V_93 * V_93 ;
struct V_18 * V_22 ;
if ( ! F_216 ( & V_402 ) )
return 0 ;
V_22 = F_6 ( V_47 . V_48 ,
V_47 . V_48 , V_14 ) ;
if ( V_22 == NULL )
return - V_33 ;
F_132 ( V_403 L_5 ) ;
V_93 = (struct V_93 * ) V_338 -> V_93 ;
V_93 -> V_94 = V_22 ;
F_213 () ;
F_24 ( & V_367 . V_404 ) ;
F_24 ( & V_58 . V_404 ) ;
F_24 ( & V_329 . V_404 ) ;
F_24 ( & V_47 . V_404 ) ;
F_24 ( & V_132 . V_404 ) ;
if ( F_217 ( & V_402 ) )
F_218 ( L_6 ) ;
return 0 ;
}

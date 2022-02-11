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
struct V_52 * V_79 = V_84 -> V_4 -> V_80 -> V_61 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_85 ) ;
F_36 ( & V_39 , * V_84 ) ;
return F_17 ( V_79 -> V_56 , V_86 , & V_39 ) ;
}
static int F_37 ( struct V_87 * V_88 , int V_71 )
{
struct V_52 * V_79 ;
struct V_38 V_39 ;
struct V_84 V_84 ;
V_84 . V_4 = V_88 -> V_89 ;
V_84 . V_88 = V_88 ;
F_15 ( & V_39 , V_40 , V_85 ) ;
F_36 ( & V_39 , V_84 ) ;
V_79 = V_84 . V_4 -> V_80 -> V_61 ;
return F_17 ( V_79 -> V_56 , V_86 , & V_39 ) ;
}
static int F_38 ( struct V_90 * V_91 )
{
struct V_2 * V_2 = V_91 -> V_92 -> V_93 . V_4 -> V_75 ;
struct V_18 * V_94 = V_91 -> V_95 -> V_96 ;
struct V_11 * V_13 ;
int V_6 ;
V_6 = F_39 ( V_91 ) ;
if ( V_6 != 0 )
return V_6 ;
if ( V_91 -> V_97 )
return 0 ;
V_13 = V_2 -> V_78 ;
if ( V_13 -> V_23 == NULL || V_13 -> V_23 == V_94 -> V_23 )
return 0 ;
if ( V_91 -> V_98 )
return - V_99 ;
V_94 -> V_23 = V_13 -> V_23 ;
V_91 -> V_100 |= V_101 ;
return 0 ;
}
static void F_40 ( struct V_90 * V_91 )
{
struct V_18 * V_94 = V_91 -> V_95 -> V_96 ;
if ( V_94 -> V_23 != V_94 -> V_24 )
V_102 -> V_103 = 0 ;
}
static int F_41 ( struct V_90 * V_91 )
{
struct V_18 * V_22 = F_42 () ;
int V_104 = F_43 ( V_91 ) ;
if ( ! V_104 && ( V_22 -> V_23 != V_22 -> V_24 ) )
V_104 = 1 ;
return V_104 ;
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
static int F_46 ( struct V_2 * V_2 , struct V_2 * V_105 ,
const struct V_106 * V_106 , char * * V_1 ,
void * * V_107 , T_2 * V_108 )
{
struct V_109 * V_110 ;
char * V_111 = F_21 () ;
char * V_13 = F_47 ( V_2 ) ;
char * V_112 = F_47 ( V_105 ) ;
int V_113 ;
if ( V_1 ) {
* V_1 = F_48 ( V_114 , V_14 ) ;
if ( * V_1 == NULL )
return - V_33 ;
}
if ( V_107 ) {
V_110 = F_49 ( V_111 ) ;
F_50 () ;
V_113 = F_51 ( V_111 , V_112 , & V_110 -> V_25 ) ;
F_52 () ;
if ( V_113 > 0 && ( ( V_113 & V_115 ) != 0 ) &&
F_53 ( V_105 ) )
V_13 = V_112 ;
* V_107 = F_48 ( V_13 , V_14 ) ;
if ( * V_107 == NULL )
return - V_33 ;
}
if ( V_108 )
* V_108 = strlen ( V_13 ) + 1 ;
return 0 ;
}
static int F_54 ( struct V_4 * V_116 , struct V_2 * V_105 ,
struct V_4 * V_117 )
{
char * V_13 ;
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_116 ) ;
V_13 = F_47 ( V_116 -> V_75 ) ;
V_6 = F_17 ( V_13 , V_86 , & V_39 ) ;
if ( V_6 == 0 && V_117 -> V_75 != NULL ) {
V_13 = F_47 ( V_117 -> V_75 ) ;
F_34 ( & V_39 , V_117 ) ;
V_6 = F_17 ( V_13 , V_86 , & V_39 ) ;
}
return V_6 ;
}
static int F_55 ( struct V_2 * V_105 , struct V_4 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_75 ;
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
V_6 = F_17 ( F_47 ( V_3 ) , V_86 , & V_39 ) ;
if ( V_6 == 0 ) {
F_34 ( & V_39 , NULL ) ;
F_56 ( & V_39 , V_105 ) ;
V_6 = F_17 ( F_47 ( V_105 ) , V_86 , & V_39 ) ;
}
return V_6 ;
}
static int F_57 ( struct V_2 * V_105 , struct V_4 * V_4 )
{
struct V_38 V_39 ;
int V_6 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
V_6 = F_17 ( F_47 ( V_4 -> V_75 ) , V_86 , & V_39 ) ;
if ( V_6 == 0 ) {
F_34 ( & V_39 , NULL ) ;
F_56 ( & V_39 , V_105 ) ;
V_6 = F_17 ( F_47 ( V_105 ) , V_86 , & V_39 ) ;
}
return V_6 ;
}
static int F_58 ( struct V_2 * V_118 ,
struct V_4 * V_116 ,
struct V_2 * V_119 ,
struct V_4 * V_117 )
{
int V_6 ;
char * V_13 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_116 ) ;
V_13 = F_47 ( V_116 -> V_75 ) ;
V_6 = F_17 ( V_13 , V_42 , & V_39 ) ;
if ( V_6 == 0 && V_117 -> V_75 != NULL ) {
V_13 = F_47 ( V_117 -> V_75 ) ;
F_34 ( & V_39 , V_117 ) ;
V_6 = F_17 ( V_13 , V_42 , & V_39 ) ;
}
return V_6 ;
}
static int F_59 ( struct V_2 * V_2 , int V_120 )
{
struct V_38 V_39 ;
int V_121 = V_120 & V_122 ;
V_120 &= ( V_82 | V_86 | V_123 | V_124 ) ;
if ( V_120 == 0 )
return 0 ;
if ( V_121 )
return - V_125 ;
F_15 ( & V_39 , V_40 , V_126 ) ;
F_56 ( & V_39 , V_2 ) ;
return F_17 ( F_47 ( V_2 ) , V_120 , & V_39 ) ;
}
static int F_60 ( struct V_4 * V_4 , struct V_127 * V_127 )
{
struct V_38 V_39 ;
if ( V_127 -> V_128 & V_129 )
return 0 ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
return F_17 ( F_47 ( V_4 -> V_75 ) , V_86 , & V_39 ) ;
}
static int F_61 ( struct V_87 * V_88 , struct V_4 * V_4 )
{
struct V_38 V_39 ;
struct V_84 V_84 ;
V_84 . V_4 = V_4 ;
V_84 . V_88 = V_88 ;
F_15 ( & V_39 , V_40 , V_85 ) ;
F_36 ( & V_39 , V_84 ) ;
return F_17 ( F_47 ( V_4 -> V_75 ) , V_82 , & V_39 ) ;
}
static int F_62 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_107 , T_2 V_130 , int V_71 )
{
struct V_38 V_39 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_131 ) == 0 ||
strcmp ( V_1 , V_132 ) == 0 ||
strcmp ( V_1 , V_133 ) == 0 ||
strcmp ( V_1 , V_134 ) == 0 ||
strcmp ( V_1 , V_135 ) == 0 ) {
if ( ! F_22 ( V_136 ) )
V_6 = - V_99 ;
if ( V_130 == 0 || V_130 >= V_8 ||
F_2 ( V_107 , V_130 ) == NULL )
V_6 = - V_137 ;
} else if ( strcmp ( V_1 , V_138 ) == 0 ) {
if ( ! F_22 ( V_136 ) )
V_6 = - V_99 ;
if ( V_130 != V_139 ||
strncmp ( V_107 , V_140 , V_139 ) != 0 )
V_6 = - V_137 ;
} else
V_6 = F_63 ( V_4 , V_1 , V_107 , V_130 , V_71 ) ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_17 ( F_47 ( V_4 -> V_75 ) , V_86 , & V_39 ) ;
return V_6 ;
}
static void F_64 ( struct V_4 * V_4 , const char * V_1 ,
const void * V_107 , T_2 V_130 , int V_71 )
{
char * V_77 ;
struct V_11 * V_13 = V_4 -> V_75 -> V_78 ;
if ( strcmp ( V_1 , V_131 ) == 0 ) {
V_77 = F_2 ( V_107 , V_130 ) ;
if ( V_77 != NULL )
V_13 -> V_15 = V_77 ;
else
V_13 -> V_15 = V_141 . V_48 ;
} else if ( strcmp ( V_1 , V_134 ) == 0 ) {
V_77 = F_2 ( V_107 , V_130 ) ;
if ( V_77 != NULL )
V_13 -> V_23 = V_77 ;
else
V_13 -> V_23 = V_141 . V_48 ;
} else if ( strcmp ( V_1 , V_135 ) == 0 ) {
V_77 = F_2 ( V_107 , V_130 ) ;
if ( V_77 != NULL )
V_13 -> V_142 = V_77 ;
else
V_13 -> V_142 = V_141 . V_48 ;
} else if ( strcmp ( V_1 , V_138 ) == 0 )
V_13 -> V_16 |= V_143 ;
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
if ( strcmp ( V_1 , V_131 ) == 0 ||
strcmp ( V_1 , V_132 ) == 0 ||
strcmp ( V_1 , V_133 ) == 0 ||
strcmp ( V_1 , V_134 ) == 0 ||
strcmp ( V_1 , V_138 ) == 0 ||
strcmp ( V_1 , V_135 ) ) {
if ( ! F_22 ( V_136 ) )
V_6 = - V_99 ;
} else
V_6 = F_67 ( V_4 , V_1 ) ;
F_15 ( & V_39 , V_40 , V_81 ) ;
F_34 ( & V_39 , V_4 ) ;
if ( V_6 == 0 )
V_6 = F_17 ( F_47 ( V_4 -> V_75 ) , V_86 , & V_39 ) ;
if ( V_6 == 0 ) {
V_13 = V_4 -> V_75 -> V_78 ;
V_13 -> V_23 = NULL ;
V_13 -> V_142 = NULL ;
}
return V_6 ;
}
static int F_68 ( const struct V_2 * V_2 ,
const char * V_1 , void * * V_144 ,
bool V_145 )
{
struct V_146 * V_147 ;
struct V_148 * V_149 ;
struct V_50 * V_79 ;
struct V_2 * V_3 = (struct V_2 * ) V_2 ;
char * V_13 ;
int V_150 ;
int V_6 = 0 ;
if ( strcmp ( V_1 , V_114 ) == 0 ) {
V_13 = F_47 ( V_2 ) ;
V_150 = strlen ( V_13 ) + 1 ;
* V_144 = V_13 ;
return V_150 ;
}
V_79 = V_3 -> V_151 ;
if ( V_79 -> V_152 != V_153 )
return - V_154 ;
V_149 = F_69 ( V_3 ) ;
if ( V_149 == NULL || V_149 -> V_155 == NULL )
return - V_154 ;
V_147 = V_149 -> V_155 -> V_156 ;
if ( strcmp ( V_1 , V_157 ) == 0 )
V_13 = V_147 -> V_158 ;
else if ( strcmp ( V_1 , V_159 ) == 0 )
V_13 = V_147 -> V_160 ;
else
return - V_154 ;
V_150 = strlen ( V_13 ) + 1 ;
if ( V_6 == 0 ) {
* V_144 = V_13 ;
V_6 = V_150 ;
}
return V_6 ;
}
static int F_70 ( struct V_2 * V_2 , char * V_144 ,
T_2 V_161 )
{
int V_108 = strlen ( V_131 ) ;
if ( V_144 != NULL && V_108 <= V_161 ) {
memcpy ( V_144 , V_131 , V_108 ) ;
return V_108 ;
}
return - V_137 ;
}
static void F_71 ( const struct V_2 * V_2 , T_3 * V_162 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
* V_162 = F_72 ( V_13 -> V_15 ) ;
}
static int F_73 ( struct V_92 * V_92 , int V_120 )
{
return 0 ;
}
static int F_74 ( struct V_92 * V_92 )
{
V_92 -> V_163 = F_21 () ;
return 0 ;
}
static void F_75 ( struct V_92 * V_92 )
{
V_92 -> V_163 = NULL ;
}
static int F_76 ( struct V_92 * V_92 , unsigned int V_164 ,
unsigned long V_165 )
{
int V_6 = 0 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_85 ) ;
F_36 ( & V_39 , V_92 -> V_93 ) ;
if ( F_77 ( V_164 ) & V_166 )
V_6 = F_17 ( V_92 -> V_163 , V_86 , & V_39 ) ;
if ( V_6 == 0 && ( F_77 ( V_164 ) & V_167 ) )
V_6 = F_17 ( V_92 -> V_163 , V_82 , & V_39 ) ;
return V_6 ;
}
static int F_78 ( struct V_92 * V_92 , unsigned int V_164 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_85 ) ;
F_36 ( & V_39 , V_92 -> V_93 ) ;
return F_17 ( V_92 -> V_163 , V_86 , & V_39 ) ;
}
static int F_79 ( struct V_92 * V_92 , unsigned int V_164 ,
unsigned long V_165 )
{
struct V_38 V_39 ;
int V_6 = 0 ;
switch ( V_164 ) {
case V_168 :
case V_169 :
case V_170 :
case V_171 :
case V_172 :
F_15 ( & V_39 , V_40 , V_85 ) ;
F_36 ( & V_39 , V_92 -> V_93 ) ;
V_6 = F_17 ( V_92 -> V_163 , V_86 , & V_39 ) ;
break;
default:
break;
}
return V_6 ;
}
static int F_80 ( struct V_92 * V_92 ,
unsigned long V_173 , unsigned long V_174 ,
unsigned long V_71 , unsigned long V_175 ,
unsigned long V_176 )
{
struct V_109 * V_110 ;
struct V_30 * V_177 ;
struct V_18 * V_22 ;
char * V_45 ;
char * V_178 ;
char * V_179 ;
struct V_11 * V_13 ;
struct V_4 * V_5 ;
int V_113 ;
int V_180 ;
int V_181 ;
int V_6 ;
V_6 = F_81 ( V_92 , V_173 , V_174 , V_71 , V_175 , V_176 ) ;
if ( V_6 || V_176 )
return V_6 ;
if ( V_92 == NULL || V_92 -> V_182 == NULL )
return 0 ;
V_5 = V_92 -> V_182 ;
if ( V_5 -> V_75 == NULL )
return 0 ;
V_13 = V_5 -> V_75 -> V_78 ;
if ( V_13 -> V_142 == NULL )
return 0 ;
V_178 = V_13 -> V_142 ;
V_22 = F_42 () ;
V_45 = F_21 () ;
V_110 = F_49 ( V_45 ) ;
V_6 = 0 ;
F_50 () ;
F_9 (srp, &skp->smk_rules, list) {
V_179 = V_177 -> V_183 ;
if ( V_178 == V_179 )
continue;
V_113 = F_51 ( V_177 -> V_184 , V_179 ,
& V_22 -> V_25 ) ;
if ( V_113 == - V_185 )
V_113 = V_177 -> V_186 ;
else
V_113 &= V_177 -> V_186 ;
if ( V_113 == 0 )
continue;
V_110 = F_49 ( V_178 ) ;
V_180 = F_51 ( V_178 , V_179 , & V_110 -> V_25 ) ;
if ( V_180 == - V_185 ) {
V_6 = - V_49 ;
break;
}
V_181 = F_51 ( V_178 , V_179 , & V_22 -> V_25 ) ;
if ( V_181 != - V_185 )
V_180 &= V_181 ;
if ( ( V_113 | V_180 ) != V_180 ) {
V_6 = - V_49 ;
break;
}
}
F_52 () ;
return V_6 ;
}
static int F_82 ( struct V_92 * V_92 )
{
V_92 -> V_163 = F_21 () ;
return 0 ;
}
static int F_83 ( struct V_35 * V_187 ,
struct V_188 * V_189 , int V_190 )
{
struct V_92 * V_92 ;
int V_6 ;
char * V_22 = F_13 ( V_187 -> V_95 -> V_96 ) ;
struct V_38 V_39 ;
V_92 = F_84 ( V_189 , struct V_92 , V_191 ) ;
V_6 = V_186 ( V_92 -> V_163 , V_22 , V_86 , NULL ) ;
if ( V_6 != 0 && F_85 ( V_187 , V_46 ) )
V_6 = 0 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_187 ) ;
F_86 ( V_92 -> V_163 , V_22 , V_86 , V_6 , & V_39 ) ;
return V_6 ;
}
static int F_87 ( struct V_92 * V_92 )
{
int V_113 = 0 ;
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_36 ( & V_39 , V_92 -> V_93 ) ;
if ( V_92 -> V_192 & V_193 )
V_113 = V_82 ;
if ( V_92 -> V_192 & V_194 )
V_113 |= V_86 ;
return F_17 ( V_92 -> V_163 , V_113 , & V_39 ) ;
}
static int F_88 ( struct V_92 * V_92 , const struct V_95 * V_95 )
{
struct V_11 * V_13 = V_92 -> V_93 . V_4 -> V_75 -> V_78 ;
V_92 -> V_163 = V_13 -> V_15 ;
return 0 ;
}
static int F_89 ( struct V_95 * V_95 , T_1 V_21 )
{
struct V_18 * V_22 ;
V_22 = F_6 ( NULL , NULL , V_21 ) ;
if ( V_22 == NULL )
return - V_33 ;
V_95 -> V_96 = V_22 ;
return 0 ;
}
static void F_90 ( struct V_95 * V_95 )
{
struct V_18 * V_22 = V_95 -> V_96 ;
struct V_30 * V_195 ;
struct V_27 * V_196 ;
struct V_27 * V_197 ;
if ( V_22 == NULL )
return;
V_95 -> V_96 = NULL ;
F_91 (l, n, &tsp->smk_rules) {
V_195 = F_92 ( V_196 , struct V_30 , V_34 ) ;
F_93 ( & V_195 -> V_34 ) ;
F_26 ( V_195 ) ;
}
F_26 ( V_22 ) ;
}
static int F_94 ( struct V_95 * V_198 , const struct V_95 * V_199 ,
T_1 V_21 )
{
struct V_18 * V_200 = V_199 -> V_96 ;
struct V_18 * V_201 ;
int V_6 ;
V_201 = F_6 ( V_200 -> V_23 , V_200 -> V_23 , V_21 ) ;
if ( V_201 == NULL )
return - V_33 ;
V_6 = F_8 ( & V_201 -> V_25 , & V_200 -> V_25 , V_21 ) ;
if ( V_6 != 0 )
return V_6 ;
V_198 -> V_96 = V_201 ;
return 0 ;
}
static void F_95 ( struct V_95 * V_198 , const struct V_95 * V_199 )
{
struct V_18 * V_200 = V_199 -> V_96 ;
struct V_18 * V_201 = V_198 -> V_96 ;
V_201 -> V_23 = V_200 -> V_23 ;
V_201 -> V_24 = V_200 -> V_23 ;
F_5 ( & V_201 -> V_26 ) ;
F_7 ( & V_201 -> V_25 ) ;
}
static int F_96 ( struct V_95 * V_198 , T_3 V_162 )
{
struct V_18 * V_201 = V_198 -> V_96 ;
char * V_12 = F_97 ( V_162 ) ;
if ( V_12 == NULL )
return - V_137 ;
V_201 -> V_23 = V_12 ;
return 0 ;
}
static int F_98 ( struct V_95 * V_198 ,
struct V_2 * V_2 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
struct V_18 * V_22 = V_198 -> V_96 ;
V_22 -> V_24 = V_13 -> V_15 ;
V_22 -> V_23 = V_13 -> V_15 ;
return 0 ;
}
static int F_99 ( struct V_35 * V_202 , int V_203 ,
const char * V_204 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_204 , V_41 ) ;
F_16 ( & V_39 , V_202 ) ;
return F_17 ( F_13 ( F_14 ( V_202 ) ) , V_203 , & V_39 ) ;
}
static int F_100 ( struct V_35 * V_202 , T_4 V_205 )
{
return F_99 ( V_202 , V_86 , V_40 ) ;
}
static int F_101 ( struct V_35 * V_202 )
{
return F_99 ( V_202 , V_82 , V_40 ) ;
}
static int F_102 ( struct V_35 * V_202 )
{
return F_99 ( V_202 , V_82 , V_40 ) ;
}
static void F_103 ( struct V_35 * V_202 , T_3 * V_162 )
{
* V_162 = F_72 ( F_13 ( F_14 ( V_202 ) ) ) ;
}
static int F_104 ( struct V_35 * V_202 , int V_206 )
{
int V_6 ;
V_6 = F_105 ( V_202 , V_206 ) ;
if ( V_6 == 0 )
V_6 = F_99 ( V_202 , V_86 , V_40 ) ;
return V_6 ;
}
static int F_106 ( struct V_35 * V_202 , int V_207 )
{
int V_6 ;
V_6 = F_107 ( V_202 , V_207 ) ;
if ( V_6 == 0 )
V_6 = F_99 ( V_202 , V_86 , V_40 ) ;
return V_6 ;
}
static int F_108 ( struct V_35 * V_202 )
{
return F_99 ( V_202 , V_82 , V_40 ) ;
}
static int F_109 ( struct V_35 * V_202 )
{
int V_6 ;
V_6 = F_110 ( V_202 ) ;
if ( V_6 == 0 )
V_6 = F_99 ( V_202 , V_86 , V_40 ) ;
return V_6 ;
}
static int F_111 ( struct V_35 * V_202 )
{
return F_99 ( V_202 , V_82 , V_40 ) ;
}
static int F_112 ( struct V_35 * V_202 )
{
return F_99 ( V_202 , V_86 , V_40 ) ;
}
static int F_113 ( struct V_35 * V_202 , struct V_208 * V_209 ,
int V_210 , T_3 V_162 )
{
struct V_38 V_39 ;
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_202 ) ;
if ( V_162 == 0 )
return F_17 ( F_13 ( F_14 ( V_202 ) ) , V_86 ,
& V_39 ) ;
return V_186 ( F_97 ( V_162 ) ,
F_13 ( F_14 ( V_202 ) ) , V_86 , & V_39 ) ;
}
static int F_114 ( struct V_35 * V_202 )
{
struct V_38 V_39 ;
char * V_45 = F_21 () ;
char * V_22 = F_115 ( F_14 ( V_202 ) ) ;
int V_6 ;
V_6 = V_186 ( V_22 , V_45 , V_86 , NULL ) ;
if ( V_6 == 0 )
goto V_211;
if ( F_22 ( V_46 ) || F_85 ( V_202 , V_46 ) )
V_6 = 0 ;
V_211:
F_15 ( & V_39 , V_40 , V_41 ) ;
F_16 ( & V_39 , V_202 ) ;
F_86 ( V_22 , V_45 , V_86 , V_6 , & V_39 ) ;
return V_6 ;
}
static void F_116 ( struct V_35 * V_202 , struct V_2 * V_2 )
{
struct V_11 * V_13 = V_2 -> V_78 ;
V_13 -> V_15 = F_13 ( F_14 ( V_202 ) ) ;
}
static int F_117 ( struct V_149 * V_155 , int V_212 , T_1 V_213 )
{
char * V_111 = F_21 () ;
struct V_146 * V_147 ;
V_147 = F_4 ( sizeof( struct V_146 ) , V_213 ) ;
if ( V_147 == NULL )
return - V_33 ;
V_147 -> V_158 = V_111 ;
V_147 -> V_160 = V_111 ;
V_147 -> V_214 = NULL ;
V_155 -> V_156 = V_147 ;
return 0 ;
}
static void F_118 ( struct V_149 * V_155 )
{
F_26 ( V_155 -> V_156 ) ;
}
static char * F_119 ( struct V_215 * V_216 )
{
struct V_217 * V_218 ;
struct V_219 * V_220 = & V_216 -> V_221 ;
if ( V_220 -> V_222 == 0 )
return NULL ;
F_9 (snp, &smk_netlbladdr_list, list)
if ( ( & V_218 -> V_223 . V_221 ) -> V_222 ==
( V_220 -> V_222 & ( & V_218 -> V_224 ) -> V_222 ) ) {
if ( V_218 -> V_225 == V_226 )
return NULL ;
return V_218 -> V_225 ;
}
return NULL ;
}
static void F_120 ( char * V_227 , struct V_228 * V_229 )
{
unsigned char * V_64 ;
unsigned char V_230 ;
int V_231 ;
int V_6 ;
int V_232 ;
if ( ! V_227 )
return;
V_229 -> V_71 |= V_233 ;
V_229 -> V_234 . V_235 . V_231 = F_121 ( V_236 ) ;
V_229 -> V_234 . V_235 . V_231 -> V_237 = 0 ;
for ( V_231 = 1 , V_64 = V_227 , V_232 = 0 ; V_232 < V_8 ; V_64 ++ , V_232 ++ )
for ( V_230 = 0x80 ; V_230 != 0 ; V_230 >>= 1 , V_231 ++ ) {
if ( ( V_230 & * V_64 ) == 0 )
continue;
V_6 = F_122 ( V_229 -> V_234 . V_235 . V_231 ,
V_231 , V_236 ) ;
}
}
static void F_123 ( char * V_12 , struct V_228 * V_238 )
{
struct V_239 V_240 ;
int V_6 ;
V_238 -> V_241 = V_12 ;
V_238 -> V_71 = V_242 | V_243 ;
V_6 = F_124 ( V_12 , & V_240 ) ;
if ( V_6 == 0 ) {
V_238 -> V_234 . V_235 . V_244 = V_240 . V_245 ;
F_120 ( V_240 . V_246 , V_238 ) ;
} else {
V_238 -> V_234 . V_235 . V_244 = V_247 ;
F_120 ( V_12 , V_238 ) ;
}
}
static int F_125 ( struct V_149 * V_155 , int V_248 )
{
struct V_146 * V_147 = V_155 -> V_156 ;
struct V_228 V_249 ;
int V_6 = 0 ;
F_126 () ;
F_127 ( V_155 ) ;
if ( V_147 -> V_160 == V_250 ||
V_248 == V_251 )
F_128 ( V_155 ) ;
else {
F_129 ( & V_249 ) ;
F_123 ( V_147 -> V_160 , & V_249 ) ;
V_6 = F_130 ( V_155 , V_155 -> V_252 , & V_249 ) ;
F_131 ( & V_249 ) ;
}
F_132 ( V_155 ) ;
F_133 () ;
return V_6 ;
}
static int F_134 ( struct V_149 * V_155 , struct V_215 * V_229 )
{
int V_6 ;
int V_253 ;
char * V_254 ;
struct V_146 * V_147 = V_155 -> V_156 ;
struct V_38 V_39 ;
F_50 () ;
V_254 = F_119 ( V_229 ) ;
if ( V_254 != NULL ) {
#ifdef F_135
struct V_255 V_256 ;
F_136 ( & V_39 , V_40 , V_257 , & V_256 ) ;
V_39 . V_258 . V_259 . V_256 -> V_212 = V_229 -> V_260 ;
V_39 . V_258 . V_259 . V_256 -> V_261 = V_229 -> V_262 ;
V_39 . V_258 . V_259 . V_256 -> V_263 . V_264 = V_229 -> V_221 . V_222 ;
#endif
V_253 = V_251 ;
V_6 = V_186 ( V_147 -> V_160 , V_254 , V_86 , & V_39 ) ;
} else {
V_253 = V_265 ;
V_6 = 0 ;
}
F_52 () ;
if ( V_6 != 0 )
return V_6 ;
return F_125 ( V_155 , V_253 ) ;
}
static int F_137 ( struct V_2 * V_2 , const char * V_1 ,
const void * V_107 , T_2 V_130 , int V_71 )
{
char * V_45 ;
struct V_11 * V_77 = V_2 -> V_78 ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
int V_6 = 0 ;
if ( V_107 == NULL || V_130 > V_8 || V_130 == 0 )
return - V_49 ;
V_45 = F_2 ( V_107 , V_130 ) ;
if ( V_45 == NULL )
return - V_137 ;
if ( strcmp ( V_1 , V_114 ) == 0 ) {
V_77 -> V_15 = V_45 ;
V_77 -> V_16 |= V_266 ;
return 0 ;
}
if ( V_2 -> V_151 -> V_152 != V_153 )
return - V_154 ;
V_149 = F_69 ( V_2 ) ;
if ( V_149 == NULL || V_149 -> V_155 == NULL )
return - V_154 ;
V_147 = V_149 -> V_155 -> V_156 ;
if ( strcmp ( V_1 , V_157 ) == 0 )
V_147 -> V_158 = V_45 ;
else if ( strcmp ( V_1 , V_159 ) == 0 ) {
V_147 -> V_160 = V_45 ;
if ( V_149 -> V_155 -> V_252 != V_267 ) {
V_6 = F_125 ( V_149 -> V_155 , V_265 ) ;
if ( V_6 != 0 )
F_138 ( V_268
L_2 ,
V_40 , - V_6 ) ;
}
} else
return - V_154 ;
return 0 ;
}
static int F_139 ( struct V_148 * V_149 , int V_212 ,
int type , int V_269 , int V_270 )
{
if ( V_212 != V_271 || V_149 -> V_155 == NULL )
return 0 ;
return F_125 ( V_149 -> V_155 , V_265 ) ;
}
static int F_140 ( struct V_148 * V_149 , struct V_272 * V_229 ,
int V_273 )
{
if ( V_149 -> V_155 == NULL || V_149 -> V_155 -> V_252 != V_271 )
return 0 ;
if ( V_273 < sizeof( struct V_215 ) )
return - V_137 ;
return F_134 ( V_149 -> V_155 , (struct V_215 * ) V_229 ) ;
}
static int F_141 ( int V_71 )
{
int V_113 = 0 ;
if ( V_71 & V_274 )
V_113 |= V_82 ;
if ( V_71 & V_275 )
V_113 |= V_86 ;
if ( V_71 & V_276 )
V_113 |= V_123 ;
return V_113 ;
}
static int F_142 ( struct V_277 * V_278 )
{
V_278 -> V_96 = F_21 () ;
return 0 ;
}
static void F_143 ( struct V_277 * V_278 )
{
V_278 -> V_96 = NULL ;
}
static char * F_144 ( struct V_279 * V_280 )
{
return ( char * ) V_280 -> V_281 . V_96 ;
}
static int F_145 ( struct V_279 * V_280 )
{
struct V_282 * V_13 = & V_280 -> V_281 ;
V_13 -> V_96 = F_21 () ;
return 0 ;
}
static void F_146 ( struct V_279 * V_280 )
{
struct V_282 * V_13 = & V_280 -> V_281 ;
V_13 -> V_96 = NULL ;
}
static int F_147 ( struct V_279 * V_280 , int V_203 )
{
char * V_147 = F_144 ( V_280 ) ;
struct V_38 V_39 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_283 ) ;
V_39 . V_258 . V_259 . V_284 = V_280 -> V_281 . V_285 ;
#endif
return F_17 ( V_147 , V_203 , & V_39 ) ;
}
static int F_148 ( struct V_279 * V_280 , int V_286 )
{
int V_113 ;
V_113 = F_141 ( V_286 ) ;
return F_147 ( V_280 , V_113 ) ;
}
static int F_149 ( struct V_279 * V_280 , int V_164 )
{
int V_113 ;
switch ( V_164 ) {
case V_287 :
case V_288 :
V_113 = V_82 ;
break;
case V_289 :
case V_290 :
case V_291 :
case V_292 :
V_113 = V_42 ;
break;
case V_293 :
case V_294 :
return 0 ;
default:
return - V_137 ;
}
return F_147 ( V_280 , V_113 ) ;
}
static int F_150 ( struct V_279 * V_280 , char T_5 * V_295 ,
int V_286 )
{
int V_113 ;
V_113 = F_141 ( V_286 ) ;
return F_147 ( V_280 , V_113 ) ;
}
static char * F_151 ( struct V_296 * V_297 )
{
return ( char * ) V_297 -> V_298 . V_96 ;
}
static int F_152 ( struct V_296 * V_297 )
{
struct V_282 * V_13 = & V_297 -> V_298 ;
V_13 -> V_96 = F_21 () ;
return 0 ;
}
static void F_153 ( struct V_296 * V_297 )
{
struct V_282 * V_13 = & V_297 -> V_298 ;
V_13 -> V_96 = NULL ;
}
static int F_154 ( struct V_296 * V_297 , int V_203 )
{
char * V_147 = F_151 ( V_297 ) ;
struct V_38 V_39 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_283 ) ;
V_39 . V_258 . V_259 . V_284 = V_297 -> V_298 . V_285 ;
#endif
return F_17 ( V_147 , V_203 , & V_39 ) ;
}
static int F_155 ( struct V_296 * V_297 , int V_299 )
{
int V_113 ;
V_113 = F_141 ( V_299 ) ;
return F_154 ( V_297 , V_113 ) ;
}
static int F_156 ( struct V_296 * V_297 , int V_164 )
{
int V_113 ;
switch ( V_164 ) {
case V_300 :
case V_301 :
case V_302 :
case V_303 :
case V_304 :
case V_287 :
case V_305 :
V_113 = V_82 ;
break;
case V_306 :
case V_307 :
case V_292 :
case V_289 :
V_113 = V_42 ;
break;
case V_293 :
case V_308 :
return 0 ;
default:
return - V_137 ;
}
return F_154 ( V_297 , V_113 ) ;
}
static int F_157 ( struct V_296 * V_297 , struct V_309 * V_310 ,
unsigned V_311 , int V_312 )
{
return F_154 ( V_297 , V_42 ) ;
}
static int F_158 ( struct V_313 * V_314 )
{
struct V_282 * V_315 = & V_314 -> V_316 ;
V_315 -> V_96 = F_21 () ;
return 0 ;
}
static void F_159 ( struct V_313 * V_314 )
{
struct V_282 * V_315 = & V_314 -> V_316 ;
V_315 -> V_96 = NULL ;
}
static char * F_160 ( struct V_313 * V_314 )
{
return ( char * ) V_314 -> V_316 . V_96 ;
}
static int F_161 ( struct V_313 * V_314 , int V_203 )
{
char * V_317 = F_160 ( V_314 ) ;
struct V_38 V_39 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_283 ) ;
V_39 . V_258 . V_259 . V_284 = V_314 -> V_316 . V_285 ;
#endif
return F_17 ( V_317 , V_203 , & V_39 ) ;
}
static int F_162 ( struct V_313 * V_314 , int V_318 )
{
int V_113 ;
V_113 = F_141 ( V_318 ) ;
return F_161 ( V_314 , V_113 ) ;
}
static int F_163 ( struct V_313 * V_314 , int V_164 )
{
int V_113 ;
switch ( V_164 ) {
case V_287 :
case V_319 :
V_113 = V_82 ;
break;
case V_289 :
case V_292 :
V_113 = V_42 ;
break;
case V_293 :
case V_320 :
return 0 ;
default:
return - V_137 ;
}
return F_161 ( V_314 , V_113 ) ;
}
static int F_164 ( struct V_313 * V_314 , struct V_277 * V_278 ,
int V_318 )
{
int V_113 ;
V_113 = F_141 ( V_318 ) ;
return F_161 ( V_314 , V_113 ) ;
}
static int F_165 ( struct V_313 * V_314 , struct V_277 * V_278 ,
struct V_35 * V_321 , long type , int V_37 )
{
return F_161 ( V_314 , V_42 ) ;
}
static int F_166 ( struct V_282 * V_322 , short V_323 )
{
char * V_13 = V_322 -> V_96 ;
int V_113 = F_141 ( V_323 ) ;
struct V_38 V_39 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_283 ) ;
V_39 . V_258 . V_259 . V_284 = V_322 -> V_285 ;
#endif
return F_17 ( V_13 , V_113 , & V_39 ) ;
}
static void F_167 ( struct V_282 * V_322 , T_3 * V_162 )
{
char * V_12 = V_322 -> V_96 ;
* V_162 = F_72 ( V_12 ) ;
}
static void F_168 ( struct V_4 * V_324 , struct V_2 * V_2 )
{
struct V_50 * V_79 ;
struct V_52 * V_53 ;
struct V_11 * V_13 ;
char * V_111 = F_21 () ;
char * V_325 ;
char * V_326 ;
char V_327 [ V_139 ] ;
int V_328 = 0 ;
struct V_4 * V_5 ;
if ( V_2 == NULL )
return;
V_13 = V_2 -> V_78 ;
F_169 ( & V_13 -> V_17 ) ;
if ( V_13 -> V_16 & V_266 )
goto V_329;
V_79 = V_2 -> V_151 ;
V_53 = V_79 -> V_61 ;
V_326 = V_53 -> V_55 ;
if ( V_324 -> V_330 == V_324 ) {
V_13 -> V_15 = V_53 -> V_54 ;
V_13 -> V_16 |= V_266 ;
goto V_329;
}
switch ( V_79 -> V_152 ) {
case V_331 :
V_326 = V_332 . V_48 ;
break;
case V_333 :
V_326 = V_332 . V_48 ;
break;
case V_334 :
V_326 = V_111 ;
break;
case V_153 :
V_326 = V_332 . V_48 ;
break;
case V_335 :
break;
case V_336 :
V_326 = V_332 . V_48 ;
default:
if ( F_170 ( V_2 -> V_337 ) ) {
V_326 = V_332 . V_48 ;
break;
}
if ( V_2 -> V_9 -> V_10 == NULL )
break;
V_5 = F_171 ( V_324 ) ;
V_325 = F_1 ( V_131 , V_2 , V_5 ) ;
if ( V_325 != NULL ) {
V_326 = V_325 ;
if ( F_172 ( V_2 -> V_337 ) ) {
V_327 [ 0 ] = '\0' ;
V_2 -> V_9 -> V_10 ( V_5 ,
V_138 ,
V_327 , V_139 ) ;
if ( strncmp ( V_327 , V_140 ,
V_139 ) == 0 )
V_328 = V_143 ;
}
}
V_13 -> V_23 = F_1 ( V_134 , V_2 , V_5 ) ;
V_13 -> V_142 = F_1 ( V_135 , V_2 , V_5 ) ;
F_173 ( V_5 ) ;
break;
}
if ( V_326 == NULL )
V_13 -> V_15 = V_111 ;
else
V_13 -> V_15 = V_326 ;
V_13 -> V_16 |= ( V_266 | V_328 ) ;
V_329:
F_174 ( & V_13 -> V_17 ) ;
return;
}
static int F_175 ( struct V_35 * V_202 , char * V_1 , char * * V_107 )
{
char * V_64 ;
int V_338 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_137 ;
V_64 = F_48 ( F_13 ( F_14 ( V_202 ) ) , V_14 ) ;
if ( V_64 == NULL )
return - V_33 ;
V_338 = strlen ( V_64 ) ;
* V_107 = V_64 ;
return V_338 ;
}
static int F_176 ( struct V_35 * V_202 , char * V_1 ,
void * V_107 , T_2 V_130 )
{
int V_6 ;
struct V_18 * V_22 ;
struct V_18 * V_339 ;
struct V_95 * V_198 ;
char * V_340 ;
if ( V_202 != V_102 )
return - V_99 ;
if ( ! F_22 ( V_136 ) )
return - V_99 ;
if ( V_107 == NULL || V_130 == 0 || V_130 >= V_8 )
return - V_137 ;
if ( strcmp ( V_1 , L_3 ) != 0 )
return - V_137 ;
V_340 = F_2 ( V_107 , V_130 ) ;
if ( V_340 == NULL )
return - V_137 ;
if ( V_340 == V_341 . V_48 )
return - V_99 ;
V_339 = V_202 -> V_95 -> V_96 ;
V_198 = F_177 () ;
if ( V_198 == NULL )
return - V_33 ;
V_22 = F_6 ( V_340 , V_339 -> V_24 , V_14 ) ;
if ( V_22 == NULL ) {
F_26 ( V_198 ) ;
return - V_33 ;
}
V_6 = F_8 ( & V_22 -> V_25 , & V_339 -> V_25 , V_14 ) ;
if ( V_6 != 0 )
return V_6 ;
V_198 -> V_96 = V_22 ;
F_178 ( V_198 ) ;
return V_130 ;
}
static int F_179 ( struct V_149 * V_149 ,
struct V_149 * V_342 , struct V_149 * V_343 )
{
struct V_146 * V_147 = V_149 -> V_156 ;
struct V_146 * V_344 = V_342 -> V_156 ;
struct V_146 * V_77 = V_343 -> V_156 ;
struct V_38 V_39 ;
int V_6 = 0 ;
#ifdef F_135
struct V_255 V_256 ;
F_136 ( & V_39 , V_40 , V_257 , & V_256 ) ;
F_180 ( & V_39 , V_342 ) ;
#endif
if ( ! F_22 ( V_46 ) )
V_6 = V_186 ( V_147 -> V_160 , V_344 -> V_158 , V_86 , & V_39 ) ;
if ( V_6 == 0 ) {
V_77 -> V_214 = V_147 -> V_160 ;
V_147 -> V_214 = V_344 -> V_160 ;
}
return V_6 ;
}
static int F_181 ( struct V_148 * V_149 , struct V_148 * V_342 )
{
struct V_146 * V_147 = V_149 -> V_155 -> V_156 ;
struct V_146 * V_344 = V_342 -> V_155 -> V_156 ;
struct V_38 V_39 ;
int V_6 = 0 ;
#ifdef F_135
struct V_255 V_256 ;
F_136 ( & V_39 , V_40 , V_257 , & V_256 ) ;
F_180 ( & V_39 , V_342 -> V_155 ) ;
#endif
if ( ! F_22 ( V_46 ) )
V_6 = V_186 ( V_147 -> V_160 , V_344 -> V_158 , V_86 , & V_39 ) ;
return V_6 ;
}
static int F_182 ( struct V_148 * V_149 , struct V_345 * V_278 ,
int V_130 )
{
struct V_215 * V_216 = (struct V_215 * ) V_278 -> V_346 ;
if ( V_216 == NULL || V_216 -> V_260 != V_347 )
return 0 ;
return F_134 ( V_149 -> V_155 , V_216 ) ;
}
static char * F_183 ( struct V_228 * V_229 ,
struct V_146 * V_147 )
{
struct V_109 * V_110 ;
char V_12 [ V_8 ] ;
char * V_45 ;
int V_348 ;
if ( ( V_229 -> V_71 & V_243 ) != 0 ) {
memset ( V_12 , '\0' , V_8 ) ;
if ( ( V_229 -> V_71 & V_233 ) != 0 )
for ( V_348 = - 1 ; ; ) {
V_348 = F_184 (
V_229 -> V_234 . V_235 . V_231 , V_348 + 1 ) ;
if ( V_348 < 0 )
break;
F_185 ( V_348 , V_12 ) ;
}
if ( V_229 -> V_234 . V_235 . V_244 == V_247 ) {
V_110 = F_49 ( V_12 ) ;
if ( V_110 != NULL )
return V_110 -> V_48 ;
if ( V_147 != NULL &&
V_147 -> V_158 == V_332 . V_48 )
return V_341 . V_48 ;
return V_332 . V_48 ;
}
V_45 = F_186 ( V_229 -> V_234 . V_235 . V_244 , V_12 ) ;
if ( V_45 != NULL )
return V_45 ;
if ( V_147 != NULL && V_147 -> V_158 == V_332 . V_48 )
return V_341 . V_48 ;
return V_332 . V_48 ;
}
if ( ( V_229 -> V_71 & V_349 ) != 0 ) {
V_45 = F_97 ( V_229 -> V_234 . V_162 ) ;
F_187 ( V_45 == NULL ) ;
return V_45 ;
}
return V_250 ;
}
static int F_188 ( struct V_149 * V_155 , struct V_350 * V_351 )
{
struct V_228 V_249 ;
struct V_146 * V_147 = V_155 -> V_156 ;
char * V_111 ;
int V_6 ;
struct V_38 V_39 ;
#ifdef F_135
struct V_255 V_256 ;
#endif
if ( V_155 -> V_252 != V_271 && V_155 -> V_252 != V_352 )
return 0 ;
F_129 ( & V_249 ) ;
V_6 = F_189 ( V_351 , V_155 -> V_252 , & V_249 ) ;
if ( V_6 == 0 )
V_111 = F_183 ( & V_249 , V_147 ) ;
else
V_111 = V_250 ;
F_131 ( & V_249 ) ;
#ifdef F_135
F_136 ( & V_39 , V_40 , V_257 , & V_256 ) ;
V_39 . V_258 . V_259 . V_256 -> V_212 = V_155 -> V_252 ;
V_39 . V_258 . V_259 . V_256 -> V_353 = V_351 -> V_354 ;
F_190 ( V_351 , & V_39 . V_258 , NULL ) ;
#endif
V_6 = V_186 ( V_111 , V_147 -> V_158 , V_86 , & V_39 ) ;
if ( V_6 != 0 )
F_191 ( V_351 , V_6 , 0 ) ;
return V_6 ;
}
static int F_192 ( struct V_148 * V_149 ,
char T_5 * V_355 ,
int T_5 * V_356 , unsigned V_108 )
{
struct V_146 * V_147 ;
char * V_357 = L_4 ;
int V_338 = 1 ;
int V_6 = 0 ;
V_147 = V_149 -> V_155 -> V_156 ;
if ( V_147 -> V_214 != NULL ) {
V_357 = V_147 -> V_214 ;
V_338 = strlen ( V_357 ) + 1 ;
}
if ( V_338 > V_108 )
V_6 = - V_358 ;
else if ( F_193 ( V_355 , V_357 , V_338 ) != 0 )
V_6 = - V_359 ;
if ( F_194 ( V_338 , V_356 ) != 0 )
V_6 = - V_359 ;
return V_6 ;
}
static int F_195 ( struct V_148 * V_149 ,
struct V_350 * V_351 , T_3 * V_162 )
{
struct V_228 V_249 ;
struct V_146 * V_147 = NULL ;
char * V_45 ;
int V_212 = V_360 ;
T_3 V_361 = 0 ;
int V_6 ;
if ( V_351 != NULL ) {
if ( V_351 -> V_269 == F_196 ( V_362 ) )
V_212 = V_271 ;
else if ( V_351 -> V_269 == F_196 ( V_363 ) )
V_212 = V_352 ;
}
if ( V_212 == V_360 && V_149 != NULL )
V_212 = V_149 -> V_155 -> V_252 ;
if ( V_212 == V_267 ) {
V_147 = V_149 -> V_155 -> V_156 ;
V_361 = F_72 ( V_147 -> V_160 ) ;
} else if ( V_212 == V_271 || V_212 == V_352 ) {
if ( V_149 != NULL && V_149 -> V_155 != NULL )
V_147 = V_149 -> V_155 -> V_156 ;
F_129 ( & V_249 ) ;
V_6 = F_189 ( V_351 , V_212 , & V_249 ) ;
if ( V_6 == 0 ) {
V_45 = F_183 ( & V_249 , V_147 ) ;
V_361 = F_72 ( V_45 ) ;
}
F_131 ( & V_249 ) ;
}
* V_162 = V_361 ;
if ( V_361 == 0 )
return - V_137 ;
return 0 ;
}
static void F_197 ( struct V_149 * V_155 , struct V_148 * V_364 )
{
struct V_146 * V_147 ;
if ( V_155 == NULL ||
( V_155 -> V_252 != V_271 && V_155 -> V_252 != V_352 ) )
return;
V_147 = V_155 -> V_156 ;
V_147 -> V_158 = V_147 -> V_160 = F_21 () ;
}
static int F_198 ( struct V_149 * V_155 , struct V_350 * V_351 ,
struct V_365 * V_366 )
{
T_6 V_212 = V_155 -> V_252 ;
struct V_146 * V_147 = V_155 -> V_156 ;
struct V_228 V_249 ;
struct V_215 V_175 ;
struct V_367 * V_368 ;
char * V_45 ;
int V_6 ;
struct V_38 V_39 ;
#ifdef F_135
struct V_255 V_256 ;
#endif
if ( V_212 == V_352 && V_351 -> V_269 == F_196 ( V_362 ) )
V_212 = V_271 ;
F_129 ( & V_249 ) ;
V_6 = F_189 ( V_351 , V_212 , & V_249 ) ;
if ( V_6 == 0 )
V_45 = F_183 ( & V_249 , V_147 ) ;
else
V_45 = V_369 . V_48 ;
F_131 ( & V_249 ) ;
#ifdef F_135
F_136 ( & V_39 , V_40 , V_257 , & V_256 ) ;
V_39 . V_258 . V_259 . V_256 -> V_212 = V_212 ;
V_39 . V_258 . V_259 . V_256 -> V_353 = V_351 -> V_354 ;
F_190 ( V_351 , & V_39 . V_258 , NULL ) ;
#endif
V_6 = V_186 ( V_45 , V_147 -> V_158 , V_86 , & V_39 ) ;
if ( V_6 != 0 )
return V_6 ;
V_366 -> V_370 = F_72 ( V_45 ) ;
V_368 = F_199 ( V_351 ) ;
V_175 . V_221 . V_222 = V_368 -> V_371 ;
F_50 () ;
if ( F_119 ( & V_175 ) == NULL ) {
F_52 () ;
F_129 ( & V_249 ) ;
F_123 ( V_45 , & V_249 ) ;
V_6 = F_200 ( V_366 , & V_249 ) ;
F_131 ( & V_249 ) ;
} else {
F_52 () ;
F_201 ( V_366 ) ;
}
return V_6 ;
}
static void F_202 ( struct V_149 * V_155 ,
const struct V_365 * V_366 )
{
struct V_146 * V_147 = V_155 -> V_156 ;
if ( V_366 -> V_370 != 0 )
V_147 -> V_214 = F_97 ( V_366 -> V_370 ) ;
else
V_147 -> V_214 = NULL ;
}
static int F_203 ( struct V_372 * V_372 , const struct V_95 * V_95 ,
unsigned long V_71 )
{
V_372 -> V_96 = F_13 ( V_95 -> V_96 ) ;
return 0 ;
}
static void F_204 ( struct V_372 * V_372 )
{
V_372 -> V_96 = NULL ;
}
static int F_205 ( T_7 V_373 ,
const struct V_95 * V_95 , T_8 V_374 )
{
struct V_372 * V_375 ;
struct V_38 V_39 ;
char * V_22 = F_13 ( V_95 -> V_96 ) ;
V_375 = F_206 ( V_373 ) ;
if ( V_375 == NULL )
return - V_137 ;
if ( V_375 -> V_96 == NULL )
return 0 ;
if ( V_22 == NULL )
return - V_49 ;
#ifdef F_135
F_15 ( & V_39 , V_40 , V_376 ) ;
V_39 . V_258 . V_259 . V_377 . V_372 = V_375 -> V_378 ;
V_39 . V_258 . V_259 . V_377 . V_379 = V_375 -> V_380 ;
#endif
return V_186 ( V_22 , V_375 -> V_96 ,
V_42 , & V_39 ) ;
}
static int F_207 ( T_3 V_381 , T_3 V_76 , char * V_382 , void * * V_383 )
{
char * * V_384 = ( char * * ) V_383 ;
* V_384 = NULL ;
if ( V_381 != V_385 && V_381 != V_386 )
return - V_137 ;
if ( V_76 != V_387 && V_76 != V_388 )
return - V_137 ;
* V_384 = F_2 ( V_382 , 0 ) ;
return 0 ;
}
static int F_208 ( struct V_389 * V_390 )
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
static int F_209 ( T_3 V_162 , T_3 V_381 , T_3 V_76 , void * V_383 ,
struct V_396 * V_397 )
{
char * V_12 ;
char * V_384 = V_383 ;
if ( ! V_384 ) {
F_210 ( V_397 , V_14 , V_398 ,
L_5 ) ;
return - V_185 ;
}
if ( V_381 != V_385 && V_381 != V_386 )
return 0 ;
V_12 = F_97 ( V_162 ) ;
if ( V_76 == V_387 )
return ( V_384 == V_12 ) ;
if ( V_76 == V_388 )
return ( V_384 != V_12 ) ;
return 0 ;
}
static void F_211 ( void * V_383 )
{
}
static int F_212 ( T_3 V_162 , char * * V_399 , T_3 * V_400 )
{
char * V_45 = F_97 ( V_162 ) ;
if ( V_399 )
* V_399 = V_45 ;
* V_400 = strlen ( V_45 ) ;
return 0 ;
}
static int F_213 ( const char * V_399 , T_3 V_400 , T_3 * V_162 )
{
* V_162 = F_72 ( V_399 ) ;
return 0 ;
}
static void F_214 ( char * V_399 , T_3 V_400 )
{
}
static int F_215 ( struct V_2 * V_2 , void * V_401 , T_3 V_402 )
{
return F_137 ( V_2 , V_114 , V_401 , V_402 , 0 ) ;
}
static int F_216 ( struct V_4 * V_4 , void * V_401 , T_3 V_402 )
{
return F_217 ( V_4 , V_131 , V_401 , V_402 , 0 ) ;
}
static int F_218 ( struct V_2 * V_2 , void * * V_401 , T_3 * V_402 )
{
int V_108 = 0 ;
V_108 = F_68 ( V_2 , V_114 , V_401 , true ) ;
if ( V_108 < 0 )
return V_108 ;
* V_402 = V_108 ;
return 0 ;
}
static T_9 void F_219 ( void )
{
F_24 ( & V_369 . V_403 ) ;
F_24 ( & V_58 . V_403 ) ;
F_24 ( & V_332 . V_403 ) ;
F_24 ( & V_47 . V_403 ) ;
F_24 ( & V_141 . V_403 ) ;
F_24 ( & V_341 . V_403 ) ;
F_5 ( & V_369 . V_26 ) ;
F_5 ( & V_58 . V_26 ) ;
F_5 ( & V_47 . V_26 ) ;
F_5 ( & V_332 . V_26 ) ;
F_5 ( & V_141 . V_26 ) ;
F_5 ( & V_341 . V_26 ) ;
F_7 ( & V_369 . V_25 ) ;
F_7 ( & V_58 . V_25 ) ;
F_7 ( & V_332 . V_25 ) ;
F_7 ( & V_47 . V_25 ) ;
F_7 ( & V_141 . V_25 ) ;
F_7 ( & V_341 . V_25 ) ;
F_220 ( & V_369 . V_34 , & V_404 ) ;
F_220 ( & V_58 . V_34 , & V_404 ) ;
F_220 ( & V_332 . V_34 , & V_404 ) ;
F_220 ( & V_47 . V_34 , & V_404 ) ;
F_220 ( & V_141 . V_34 , & V_404 ) ;
F_220 ( & V_341 . V_34 , & V_404 ) ;
}
static T_9 int F_221 ( void )
{
struct V_95 * V_95 ;
struct V_18 * V_22 ;
if ( ! F_222 ( & V_405 ) )
return 0 ;
V_22 = F_6 ( V_47 . V_48 ,
V_47 . V_48 , V_14 ) ;
if ( V_22 == NULL )
return - V_33 ;
F_138 ( V_406 L_6 ) ;
V_95 = (struct V_95 * ) V_102 -> V_95 ;
V_95 -> V_96 = V_22 ;
F_219 () ;
if ( F_223 ( & V_405 ) )
F_224 ( L_7 ) ;
return 0 ;
}

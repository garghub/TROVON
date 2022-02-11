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
static inline unsigned int F_12 ( unsigned int V_38 )
{
switch ( V_38 ) {
case V_39 :
return V_40 ;
case V_41 :
return V_42 ;
}
return 0 ;
}
static int F_13 ( struct V_43 * V_44 , char * V_45 ,
unsigned int V_38 , const char * V_46 )
{
int V_7 ;
struct V_47 V_48 , * V_49 = NULL ;
struct V_21 * V_25 ;
struct V_1 * V_9 ;
if ( ( V_38 & V_50 ) == 0 ) {
F_14 ( & V_48 , V_46 , V_51 ) ;
F_15 ( & V_48 , V_44 ) ;
V_49 = & V_48 ;
}
V_25 = F_16 ( V_44 ) ;
V_9 = F_17 ( V_25 ) ;
if ( ( V_38 & V_41 ) &&
( V_52 == V_53 ||
V_52 == V_54 ) ) {
if ( V_9 -> V_55 == V_45 )
V_7 = 0 ;
else if ( V_52 == V_54 )
V_7 = - V_56 ;
else if ( F_18 ( V_57 ) )
V_7 = 0 ;
else
V_7 = - V_56 ;
if ( V_49 )
F_19 ( V_9 -> V_55 , V_45 , 0 , V_7 , V_49 ) ;
return V_7 ;
}
V_7 = F_20 ( V_25 , V_45 , F_12 ( V_38 ) , V_49 ) ;
return V_7 ;
}
static int F_21 ( struct V_43 * V_58 , unsigned int V_38 )
{
int V_7 ;
struct V_1 * V_9 ;
V_7 = F_22 ( V_58 , V_38 ) ;
if ( V_7 != 0 )
return V_7 ;
V_9 = F_17 ( F_16 ( V_58 ) ) ;
V_7 = F_13 ( V_59 , V_9 -> V_55 , V_38 , V_60 ) ;
return V_7 ;
}
static int F_23 ( struct V_43 * V_61 )
{
int V_7 ;
struct V_1 * V_9 ;
V_7 = F_24 ( V_61 ) ;
if ( V_7 != 0 )
return V_7 ;
V_9 = F_17 ( F_25 () ) ;
V_7 = F_13 ( V_61 , V_9 -> V_55 ,
V_41 , V_60 ) ;
return V_7 ;
}
static int F_26 ( int V_62 )
{
int V_7 = 0 ;
struct V_1 * V_9 = F_27 () ;
if ( F_28 ( V_63 ) )
return 0 ;
if ( V_64 != NULL && V_64 != V_9 )
V_7 = - V_56 ;
return V_7 ;
}
static int F_29 ( struct V_65 * V_66 )
{
struct V_67 * V_68 ;
V_68 = F_2 ( sizeof( struct V_67 ) , V_13 ) ;
if ( V_68 == NULL )
return - V_36 ;
V_68 -> V_69 = V_70 . V_55 ;
V_68 -> V_71 = V_70 . V_55 ;
V_68 -> V_72 = V_70 . V_55 ;
V_68 -> V_73 = V_74 . V_55 ;
V_66 -> V_75 = V_68 ;
return 0 ;
}
static void F_30 ( struct V_65 * V_66 )
{
F_4 ( V_66 -> V_75 ) ;
V_66 -> V_75 = NULL ;
}
static int F_31 ( char * V_76 , char * V_77 )
{
char * V_78 , * V_79 , * V_80 , * V_6 ;
V_80 = ( char * ) F_32 ( V_13 ) ;
if ( V_80 == NULL )
return - V_36 ;
for ( V_78 = V_76 , V_79 = V_76 ; V_79 != NULL ; V_78 = V_79 + 1 ) {
if ( strstr ( V_78 , V_81 ) == V_78 )
V_6 = V_77 ;
else if ( strstr ( V_78 , V_82 ) == V_78 )
V_6 = V_77 ;
else if ( strstr ( V_78 , V_83 ) == V_78 )
V_6 = V_77 ;
else if ( strstr ( V_78 , V_84 ) == V_78 )
V_6 = V_77 ;
else if ( strstr ( V_78 , V_85 ) == V_78 )
V_6 = V_77 ;
else
V_6 = V_80 ;
V_79 = strchr ( V_78 , ',' ) ;
if ( V_79 != NULL )
* V_79 = '\0' ;
if ( * V_6 != '\0' )
strcat ( V_6 , L_1 ) ;
strcat ( V_6 , V_78 ) ;
}
strcpy ( V_76 , V_80 ) ;
F_33 ( ( unsigned long ) V_80 ) ;
return 0 ;
}
static int F_34 ( struct V_65 * V_66 , int V_86 , void * V_87 )
{
struct V_5 * V_88 = V_66 -> V_89 ;
struct V_3 * V_3 = V_88 -> V_90 ;
struct V_67 * V_91 = V_66 -> V_75 ;
struct V_14 * V_16 ;
struct V_1 * V_9 ;
char * V_92 ;
char * V_79 ;
char * V_93 ;
int V_94 = 0 ;
int V_95 = 0 ;
if ( V_91 -> V_96 )
return 0 ;
V_91 -> V_96 = 1 ;
for ( V_92 = V_87 ; V_92 != NULL ; V_92 = V_79 ) {
V_79 = strchr ( V_92 , ',' ) ;
if ( V_79 != NULL )
* V_79 ++ = '\0' ;
if ( strncmp ( V_92 , V_83 , strlen ( V_83 ) ) == 0 ) {
V_92 += strlen ( V_83 ) ;
V_93 = F_35 ( V_92 , 0 ) ;
if ( V_93 != NULL ) {
V_91 -> V_73 = V_93 ;
V_95 = 1 ;
}
} else if ( strncmp ( V_92 , V_82 , strlen ( V_82 ) ) == 0 ) {
V_92 += strlen ( V_82 ) ;
V_93 = F_35 ( V_92 , 0 ) ;
if ( V_93 != NULL ) {
V_91 -> V_72 = V_93 ;
V_95 = 1 ;
}
} else if ( strncmp ( V_92 , V_81 ,
strlen ( V_81 ) ) == 0 ) {
V_92 += strlen ( V_81 ) ;
V_93 = F_35 ( V_92 , 0 ) ;
if ( V_93 != NULL ) {
V_91 -> V_71 = V_93 ;
V_95 = 1 ;
}
} else if ( strncmp ( V_92 , V_84 , strlen ( V_84 ) ) == 0 ) {
V_92 += strlen ( V_84 ) ;
V_93 = F_35 ( V_92 , 0 ) ;
if ( V_93 != NULL ) {
V_91 -> V_69 = V_93 ;
V_95 = 1 ;
}
} else if ( strncmp ( V_92 , V_85 , strlen ( V_85 ) ) == 0 ) {
V_92 += strlen ( V_85 ) ;
V_93 = F_35 ( V_92 , 0 ) ;
if ( V_93 != NULL ) {
V_91 -> V_69 = V_93 ;
V_94 = 1 ;
V_95 = 1 ;
}
}
}
if ( ! F_28 ( V_97 ) ) {
if ( V_95 )
return - V_98 ;
V_9 = F_27 () ;
V_91 -> V_69 = V_9 -> V_55 ;
V_91 -> V_71 = V_9 -> V_55 ;
}
V_16 = V_3 -> V_99 ;
if ( V_16 == NULL ) {
V_16 = F_5 ( V_91 -> V_69 ) ;
if ( V_16 == NULL )
return - V_36 ;
V_3 -> V_99 = V_16 ;
} else
V_16 -> V_18 = V_91 -> V_69 ;
if ( V_94 )
V_16 -> V_19 |= V_100 ;
return 0 ;
}
static int F_36 ( struct V_5 * V_5 )
{
struct V_67 * V_101 = V_5 -> V_102 -> V_75 ;
int V_7 ;
struct V_47 V_48 ;
F_14 ( & V_48 , V_60 , V_103 ) ;
F_37 ( & V_48 , V_5 ) ;
V_7 = F_38 ( V_101 -> V_72 , V_40 , & V_48 ) ;
return V_7 ;
}
static int F_39 ( struct V_104 * V_105 )
{
struct V_3 * V_3 = F_40 ( V_105 -> V_106 ) ;
struct V_21 * V_107 = V_105 -> V_108 -> V_109 ;
struct V_14 * V_16 ;
int V_7 ;
V_7 = F_41 ( V_105 ) ;
if ( V_7 != 0 )
return V_7 ;
if ( V_105 -> V_110 )
return 0 ;
V_16 = V_3 -> V_99 ;
if ( V_16 -> V_26 == NULL || V_16 -> V_26 == V_107 -> V_26 )
return 0 ;
if ( V_105 -> V_111 & ( V_112 | V_113 ) ) {
struct V_43 * V_44 ;
V_7 = 0 ;
F_42 () ;
V_44 = F_43 ( V_59 ) ;
if ( F_44 ( V_44 != NULL ) )
V_7 = F_13 ( V_44 ,
V_16 -> V_26 -> V_55 ,
V_41 ,
V_60 ) ;
F_45 () ;
if ( V_7 != 0 )
return V_7 ;
} else if ( V_105 -> V_111 )
return - V_98 ;
V_107 -> V_26 = V_16 -> V_26 ;
V_105 -> V_114 |= V_115 ;
return 0 ;
}
static void F_46 ( struct V_104 * V_105 )
{
struct V_21 * V_107 = V_105 -> V_108 -> V_109 ;
if ( V_107 -> V_26 != V_107 -> V_27 )
V_59 -> V_116 = 0 ;
}
static int F_47 ( struct V_104 * V_105 )
{
struct V_21 * V_25 = F_25 () ;
int V_117 = F_48 ( V_105 ) ;
if ( ! V_117 && ( V_25 -> V_26 != V_25 -> V_27 ) )
V_117 = 1 ;
return V_117 ;
}
static int F_49 ( struct V_3 * V_3 )
{
struct V_1 * V_9 = F_27 () ;
V_3 -> V_99 = F_5 ( V_9 -> V_55 ) ;
if ( V_3 -> V_99 == NULL )
return - V_36 ;
return 0 ;
}
static void F_50 ( struct V_3 * V_3 )
{
F_4 ( V_3 -> V_99 ) ;
V_3 -> V_99 = NULL ;
}
static int F_51 ( struct V_3 * V_3 , struct V_3 * V_118 ,
const struct V_119 * V_119 , const char * * V_2 ,
void * * V_120 , T_2 * V_121 )
{
struct V_14 * V_122 = V_3 -> V_99 ;
struct V_1 * V_9 = F_27 () ;
char * V_16 = F_52 ( V_3 ) ;
char * V_123 = F_52 ( V_118 ) ;
int V_124 ;
if ( V_2 )
* V_2 = V_125 ;
if ( V_120 ) {
F_42 () ;
V_124 = F_53 ( V_9 -> V_55 , V_123 , & V_9 -> V_28 ) ;
F_45 () ;
if ( V_124 > 0 && ( ( V_124 & V_126 ) != 0 ) &&
F_54 ( V_118 ) ) {
V_16 = V_123 ;
V_122 -> V_19 |= V_127 ;
}
* V_120 = F_55 ( V_16 , V_17 ) ;
if ( * V_120 == NULL )
return - V_36 ;
}
if ( V_121 )
* V_121 = strlen ( V_16 ) + 1 ;
return 0 ;
}
static int F_56 ( struct V_5 * V_128 , struct V_3 * V_118 ,
struct V_5 * V_129 )
{
char * V_16 ;
struct V_47 V_48 ;
int V_7 ;
F_14 ( & V_48 , V_60 , V_103 ) ;
F_37 ( & V_48 , V_128 ) ;
V_16 = F_52 ( V_128 -> V_90 ) ;
V_7 = F_38 ( V_16 , V_130 , & V_48 ) ;
if ( V_7 == 0 && V_129 -> V_90 != NULL ) {
V_16 = F_52 ( V_129 -> V_90 ) ;
F_37 ( & V_48 , V_129 ) ;
V_7 = F_38 ( V_16 , V_130 , & V_48 ) ;
}
return V_7 ;
}
static int F_57 ( struct V_3 * V_118 , struct V_5 * V_5 )
{
struct V_3 * V_4 = V_5 -> V_90 ;
struct V_47 V_48 ;
int V_7 ;
F_14 ( & V_48 , V_60 , V_103 ) ;
F_37 ( & V_48 , V_5 ) ;
V_7 = F_38 ( F_52 ( V_4 ) , V_130 , & V_48 ) ;
if ( V_7 == 0 ) {
F_14 ( & V_48 , V_60 , V_131 ) ;
F_58 ( & V_48 , V_118 ) ;
V_7 = F_38 ( F_52 ( V_118 ) , V_130 , & V_48 ) ;
}
return V_7 ;
}
static int F_59 ( struct V_3 * V_118 , struct V_5 * V_5 )
{
struct V_47 V_48 ;
int V_7 ;
F_14 ( & V_48 , V_60 , V_103 ) ;
F_37 ( & V_48 , V_5 ) ;
V_7 = F_38 ( F_52 ( V_5 -> V_90 ) , V_130 , & V_48 ) ;
if ( V_7 == 0 ) {
F_14 ( & V_48 , V_60 , V_131 ) ;
F_58 ( & V_48 , V_118 ) ;
V_7 = F_38 ( F_52 ( V_118 ) , V_130 , & V_48 ) ;
}
return V_7 ;
}
static int F_60 ( struct V_3 * V_132 ,
struct V_5 * V_128 ,
struct V_3 * V_133 ,
struct V_5 * V_129 )
{
int V_7 ;
char * V_16 ;
struct V_47 V_48 ;
F_14 ( & V_48 , V_60 , V_103 ) ;
F_37 ( & V_48 , V_128 ) ;
V_16 = F_52 ( V_128 -> V_90 ) ;
V_7 = F_38 ( V_16 , V_42 , & V_48 ) ;
if ( V_7 == 0 && V_129 -> V_90 != NULL ) {
V_16 = F_52 ( V_129 -> V_90 ) ;
F_37 ( & V_48 , V_129 ) ;
V_7 = F_38 ( V_16 , V_42 , & V_48 ) ;
}
return V_7 ;
}
static int F_61 ( struct V_3 * V_3 , int V_134 )
{
struct V_47 V_48 ;
int V_135 = V_134 & V_136 ;
V_134 &= ( V_40 | V_130 | V_137 | V_138 ) ;
if ( V_134 == 0 )
return 0 ;
if ( V_135 )
return - V_139 ;
F_14 ( & V_48 , V_60 , V_131 ) ;
F_58 ( & V_48 , V_3 ) ;
return F_38 ( F_52 ( V_3 ) , V_134 , & V_48 ) ;
}
static int F_62 ( struct V_5 * V_5 , struct V_140 * V_140 )
{
struct V_47 V_48 ;
if ( V_140 -> V_141 & V_142 )
return 0 ;
F_14 ( & V_48 , V_60 , V_103 ) ;
F_37 ( & V_48 , V_5 ) ;
return F_38 ( F_52 ( V_5 -> V_90 ) , V_130 , & V_48 ) ;
}
static int F_63 ( struct V_143 * V_144 , struct V_5 * V_5 )
{
struct V_47 V_48 ;
struct V_145 V_145 ;
V_145 . V_5 = V_5 ;
V_145 . V_144 = V_144 ;
F_14 ( & V_48 , V_60 , V_146 ) ;
F_64 ( & V_48 , V_145 ) ;
return F_38 ( F_52 ( V_5 -> V_90 ) , V_40 , & V_48 ) ;
}
static int F_65 ( struct V_5 * V_5 , const char * V_2 ,
const void * V_120 , T_2 V_147 , int V_86 )
{
struct V_47 V_48 ;
struct V_1 * V_9 ;
int V_148 = 0 ;
int V_149 = 0 ;
int V_150 = 0 ;
int V_7 = 0 ;
if ( strcmp ( V_2 , V_151 ) == 0 ||
strcmp ( V_2 , V_152 ) == 0 ||
strcmp ( V_2 , V_153 ) == 0 ) {
V_148 = 1 ;
V_149 = 1 ;
} else if ( strcmp ( V_2 , V_154 ) == 0 ||
strcmp ( V_2 , V_155 ) == 0 ) {
V_148 = 1 ;
V_149 = 1 ;
V_150 = 1 ;
} else if ( strcmp ( V_2 , V_156 ) == 0 ) {
V_148 = 1 ;
if ( V_147 != V_157 ||
strncmp ( V_120 , V_158 , V_157 ) != 0 )
V_7 = - V_159 ;
} else
V_7 = F_66 ( V_5 , V_2 , V_120 , V_147 , V_86 ) ;
if ( V_148 && ! F_28 ( V_97 ) )
V_7 = - V_98 ;
if ( V_7 == 0 && V_149 ) {
V_9 = F_3 ( V_120 , V_147 ) ;
if ( V_9 == NULL || ( V_150 &&
( V_9 == & V_160 || V_9 == & V_161 ) ) )
V_7 = - V_159 ;
}
F_14 ( & V_48 , V_60 , V_103 ) ;
F_37 ( & V_48 , V_5 ) ;
if ( V_7 == 0 )
V_7 = F_38 ( F_52 ( V_5 -> V_90 ) , V_130 , & V_48 ) ;
return V_7 ;
}
static void F_67 ( struct V_5 * V_5 , const char * V_2 ,
const void * V_120 , T_2 V_147 , int V_86 )
{
struct V_1 * V_9 ;
struct V_14 * V_16 = V_5 -> V_90 -> V_99 ;
if ( strcmp ( V_2 , V_156 ) == 0 ) {
V_16 -> V_19 |= V_100 ;
return;
}
if ( strcmp ( V_2 , V_151 ) == 0 ) {
V_9 = F_3 ( V_120 , V_147 ) ;
if ( V_9 != NULL )
V_16 -> V_18 = V_9 -> V_55 ;
else
V_16 -> V_18 = V_162 . V_55 ;
} else if ( strcmp ( V_2 , V_154 ) == 0 ) {
V_9 = F_3 ( V_120 , V_147 ) ;
if ( V_9 != NULL )
V_16 -> V_26 = V_9 ;
else
V_16 -> V_26 = & V_162 ;
} else if ( strcmp ( V_2 , V_155 ) == 0 ) {
V_9 = F_3 ( V_120 , V_147 ) ;
if ( V_9 != NULL )
V_16 -> V_163 = V_9 ;
else
V_16 -> V_163 = & V_162 ;
}
return;
}
static int F_68 ( struct V_5 * V_5 , const char * V_2 )
{
struct V_47 V_48 ;
F_14 ( & V_48 , V_60 , V_103 ) ;
F_37 ( & V_48 , V_5 ) ;
return F_38 ( F_52 ( V_5 -> V_90 ) , V_40 , & V_48 ) ;
}
static int F_69 ( struct V_5 * V_5 , const char * V_2 )
{
struct V_14 * V_16 ;
struct V_47 V_48 ;
int V_7 = 0 ;
if ( strcmp ( V_2 , V_151 ) == 0 ||
strcmp ( V_2 , V_152 ) == 0 ||
strcmp ( V_2 , V_153 ) == 0 ||
strcmp ( V_2 , V_154 ) == 0 ||
strcmp ( V_2 , V_156 ) == 0 ||
strcmp ( V_2 , V_155 ) == 0 ) {
if ( ! F_28 ( V_97 ) )
V_7 = - V_98 ;
} else
V_7 = F_70 ( V_5 , V_2 ) ;
if ( V_7 != 0 )
return V_7 ;
F_14 ( & V_48 , V_60 , V_103 ) ;
F_37 ( & V_48 , V_5 ) ;
V_7 = F_38 ( F_52 ( V_5 -> V_90 ) , V_130 , & V_48 ) ;
if ( V_7 != 0 )
return V_7 ;
V_16 = V_5 -> V_90 -> V_99 ;
if ( strcmp ( V_2 , V_151 ) == 0 )
V_16 -> V_26 = NULL ;
else if ( strcmp ( V_2 , V_155 ) == 0 )
V_16 -> V_163 = NULL ;
else if ( strcmp ( V_2 , V_156 ) == 0 )
V_16 -> V_19 &= ~ V_100 ;
return 0 ;
}
static int F_71 ( const struct V_3 * V_3 ,
const char * V_2 , void * * V_8 ,
bool V_164 )
{
struct V_165 * V_166 ;
struct V_167 * V_168 ;
struct V_65 * V_101 ;
struct V_3 * V_4 = (struct V_3 * ) V_3 ;
char * V_16 ;
int V_169 ;
int V_7 = 0 ;
if ( strcmp ( V_2 , V_125 ) == 0 ) {
V_16 = F_52 ( V_3 ) ;
V_169 = strlen ( V_16 ) + 1 ;
* V_8 = V_16 ;
return V_169 ;
}
V_101 = V_4 -> V_170 ;
if ( V_101 -> V_171 != V_172 )
return - V_173 ;
V_168 = F_72 ( V_4 ) ;
if ( V_168 == NULL || V_168 -> V_174 == NULL )
return - V_173 ;
V_166 = V_168 -> V_174 -> V_175 ;
if ( strcmp ( V_2 , V_176 ) == 0 )
V_16 = V_166 -> V_177 -> V_55 ;
else if ( strcmp ( V_2 , V_178 ) == 0 )
V_16 = V_166 -> V_179 -> V_55 ;
else
return - V_173 ;
V_169 = strlen ( V_16 ) + 1 ;
if ( V_7 == 0 ) {
* V_8 = V_16 ;
V_7 = V_169 ;
}
return V_7 ;
}
static int F_73 ( struct V_3 * V_3 , char * V_8 ,
T_2 V_180 )
{
int V_121 = strlen ( V_151 ) ;
if ( V_8 != NULL && V_121 <= V_180 ) {
memcpy ( V_8 , V_151 , V_121 ) ;
return V_121 ;
}
return - V_159 ;
}
static void F_74 ( const struct V_3 * V_3 , T_3 * V_181 )
{
struct V_14 * V_16 = V_3 -> V_99 ;
* V_181 = F_75 ( V_16 -> V_18 ) ;
}
static int F_76 ( struct V_106 * V_106 , int V_134 )
{
return 0 ;
}
static int F_77 ( struct V_106 * V_106 )
{
struct V_1 * V_9 = F_27 () ;
V_106 -> V_182 = V_9 -> V_55 ;
return 0 ;
}
static void F_78 ( struct V_106 * V_106 )
{
V_106 -> V_182 = NULL ;
}
static int F_79 ( struct V_106 * V_106 , unsigned int V_183 ,
unsigned long V_184 )
{
int V_7 = 0 ;
struct V_47 V_48 ;
F_14 ( & V_48 , V_60 , V_146 ) ;
F_64 ( & V_48 , V_106 -> V_185 ) ;
if ( F_80 ( V_183 ) & V_186 )
V_7 = F_38 ( V_106 -> V_182 , V_130 , & V_48 ) ;
if ( V_7 == 0 && ( F_80 ( V_183 ) & V_187 ) )
V_7 = F_38 ( V_106 -> V_182 , V_40 , & V_48 ) ;
return V_7 ;
}
static int F_81 ( struct V_106 * V_106 , unsigned int V_183 )
{
struct V_47 V_48 ;
F_14 ( & V_48 , V_60 , V_146 ) ;
F_64 ( & V_48 , V_106 -> V_185 ) ;
return F_38 ( V_106 -> V_182 , V_188 , & V_48 ) ;
}
static int F_82 ( struct V_106 * V_106 , unsigned int V_183 ,
unsigned long V_184 )
{
struct V_47 V_48 ;
int V_7 = 0 ;
switch ( V_183 ) {
case V_189 :
break;
case V_190 :
case V_191 :
F_14 ( & V_48 , V_60 , V_146 ) ;
F_64 ( & V_48 , V_106 -> V_185 ) ;
V_7 = F_38 ( V_106 -> V_182 , V_188 , & V_48 ) ;
break;
case V_192 :
case V_193 :
F_14 ( & V_48 , V_60 , V_146 ) ;
F_64 ( & V_48 , V_106 -> V_185 ) ;
V_7 = F_38 ( V_106 -> V_182 , V_130 , & V_48 ) ;
break;
default:
break;
}
return V_7 ;
}
static int F_83 ( struct V_106 * V_106 ,
unsigned long V_194 , unsigned long V_195 ,
unsigned long V_86 )
{
struct V_1 * V_9 ;
struct V_1 * V_196 ;
struct V_33 * V_197 ;
struct V_21 * V_25 ;
char * V_198 ;
struct V_14 * V_16 ;
int V_124 ;
int V_199 ;
int V_200 ;
int V_7 ;
if ( V_106 == NULL )
return 0 ;
V_16 = F_40 ( V_106 ) -> V_99 ;
if ( V_16 -> V_163 == NULL )
return 0 ;
V_196 = V_16 -> V_163 ;
V_25 = F_25 () ;
V_9 = F_27 () ;
V_7 = 0 ;
F_42 () ;
F_10 (srp, &skp->smk_rules, list) {
V_198 = V_197 -> V_201 ;
if ( V_196 -> V_55 == V_198 )
continue;
V_124 = F_53 ( V_197 -> V_202 -> V_55 , V_198 ,
& V_25 -> V_28 ) ;
if ( V_124 == - V_203 )
V_124 = V_197 -> V_204 ;
else
V_124 &= V_197 -> V_204 ;
if ( V_124 == 0 )
continue;
V_199 = F_53 ( V_196 -> V_55 , V_198 ,
& V_196 -> V_28 ) ;
if ( V_199 == - V_203 ) {
V_7 = - V_56 ;
break;
}
V_200 = F_53 ( V_196 -> V_55 , V_198 ,
& V_25 -> V_28 ) ;
if ( V_200 != - V_203 )
V_199 &= V_200 ;
if ( ( V_124 | V_199 ) != V_199 ) {
V_7 = - V_56 ;
break;
}
}
F_45 () ;
return V_7 ;
}
static int F_84 ( struct V_106 * V_106 )
{
struct V_1 * V_9 = F_27 () ;
V_106 -> V_182 = V_9 -> V_55 ;
return 0 ;
}
static int F_85 ( struct V_43 * V_205 ,
struct V_206 * V_207 , int V_208 )
{
struct V_1 * V_9 ;
struct V_1 * V_209 = F_17 ( V_205 -> V_108 -> V_109 ) ;
struct V_106 * V_106 ;
int V_7 ;
struct V_47 V_48 ;
V_106 = F_86 ( V_207 , struct V_106 , V_210 ) ;
V_9 = F_87 ( V_106 -> V_182 ) ;
V_7 = V_204 ( V_9 , V_209 -> V_55 , V_130 , NULL ) ;
if ( V_7 != 0 && F_88 ( V_205 , V_63 ) )
V_7 = 0 ;
F_14 ( & V_48 , V_60 , V_51 ) ;
F_15 ( & V_48 , V_205 ) ;
F_19 ( V_106 -> V_182 , V_209 -> V_55 , V_130 , V_7 , & V_48 ) ;
return V_7 ;
}
static int F_89 ( struct V_106 * V_106 )
{
int V_124 = 0 ;
struct V_47 V_48 ;
F_14 ( & V_48 , V_60 , V_146 ) ;
F_64 ( & V_48 , V_106 -> V_185 ) ;
if ( V_106 -> V_211 & V_212 )
V_124 = V_40 ;
if ( V_106 -> V_211 & V_213 )
V_124 |= V_130 ;
return F_38 ( V_106 -> V_182 , V_124 , & V_48 ) ;
}
static int F_90 ( struct V_106 * V_106 , const struct V_108 * V_108 )
{
struct V_21 * V_25 = V_108 -> V_109 ;
struct V_14 * V_16 = F_40 ( V_106 ) -> V_99 ;
struct V_47 V_48 ;
int V_7 ;
if ( F_28 ( V_63 ) )
return 0 ;
F_14 ( & V_48 , V_60 , V_146 ) ;
F_64 ( & V_48 , V_106 -> V_185 ) ;
V_7 = V_204 ( V_25 -> V_26 , V_16 -> V_18 , V_40 , & V_48 ) ;
if ( V_7 == 0 )
V_106 -> V_182 = V_16 -> V_18 ;
return V_7 ;
}
static int F_91 ( struct V_108 * V_108 , T_1 V_24 )
{
struct V_21 * V_25 ;
V_25 = F_7 ( NULL , NULL , V_24 ) ;
if ( V_25 == NULL )
return - V_36 ;
V_108 -> V_109 = V_25 ;
return 0 ;
}
static void F_92 ( struct V_108 * V_108 )
{
struct V_21 * V_25 = V_108 -> V_109 ;
struct V_33 * V_214 ;
struct V_30 * V_215 ;
struct V_30 * V_216 ;
if ( V_25 == NULL )
return;
V_108 -> V_109 = NULL ;
F_93 (l, n, &tsp->smk_rules) {
V_214 = F_94 ( V_215 , struct V_33 , V_37 ) ;
F_95 ( & V_214 -> V_37 ) ;
F_4 ( V_214 ) ;
}
F_4 ( V_25 ) ;
}
static int F_96 ( struct V_108 * V_217 , const struct V_108 * V_218 ,
T_1 V_24 )
{
struct V_21 * V_219 = V_218 -> V_109 ;
struct V_21 * V_220 ;
int V_7 ;
V_220 = F_7 ( V_219 -> V_26 , V_219 -> V_26 , V_24 ) ;
if ( V_220 == NULL )
return - V_36 ;
V_7 = F_9 ( & V_220 -> V_28 , & V_219 -> V_28 , V_24 ) ;
if ( V_7 != 0 )
return V_7 ;
V_217 -> V_109 = V_220 ;
return 0 ;
}
static void F_97 ( struct V_108 * V_217 , const struct V_108 * V_218 )
{
struct V_21 * V_219 = V_218 -> V_109 ;
struct V_21 * V_220 = V_217 -> V_109 ;
V_220 -> V_26 = V_219 -> V_26 ;
V_220 -> V_27 = V_219 -> V_26 ;
F_6 ( & V_220 -> V_29 ) ;
F_8 ( & V_220 -> V_28 ) ;
}
static int F_98 ( struct V_108 * V_217 , T_3 V_181 )
{
struct V_21 * V_220 = V_217 -> V_109 ;
struct V_1 * V_9 = F_99 ( V_181 ) ;
if ( V_9 == NULL )
return - V_159 ;
V_220 -> V_26 = V_9 ;
return 0 ;
}
static int F_100 ( struct V_108 * V_217 ,
struct V_3 * V_3 )
{
struct V_14 * V_16 = V_3 -> V_99 ;
struct V_21 * V_25 = V_217 -> V_109 ;
V_25 -> V_27 = F_87 ( V_16 -> V_18 ) ;
V_25 -> V_26 = V_25 -> V_27 ;
return 0 ;
}
static int F_101 ( struct V_43 * V_221 , int V_222 ,
const char * V_223 )
{
struct V_47 V_48 ;
struct V_1 * V_9 = F_17 ( F_16 ( V_221 ) ) ;
F_14 ( & V_48 , V_223 , V_51 ) ;
F_15 ( & V_48 , V_221 ) ;
return F_38 ( V_9 -> V_55 , V_222 , & V_48 ) ;
}
static int F_102 ( struct V_43 * V_221 , T_4 V_224 )
{
return F_101 ( V_221 , V_130 , V_60 ) ;
}
static int F_103 ( struct V_43 * V_221 )
{
return F_101 ( V_221 , V_40 , V_60 ) ;
}
static int F_104 ( struct V_43 * V_221 )
{
return F_101 ( V_221 , V_40 , V_60 ) ;
}
static void F_105 ( struct V_43 * V_221 , T_3 * V_181 )
{
struct V_1 * V_9 = F_17 ( F_16 ( V_221 ) ) ;
* V_181 = V_9 -> V_225 ;
}
static int F_106 ( struct V_43 * V_221 , int V_226 )
{
int V_7 ;
V_7 = F_107 ( V_221 , V_226 ) ;
if ( V_7 == 0 )
V_7 = F_101 ( V_221 , V_130 , V_60 ) ;
return V_7 ;
}
static int F_108 ( struct V_43 * V_221 , int V_227 )
{
int V_7 ;
V_7 = F_109 ( V_221 , V_227 ) ;
if ( V_7 == 0 )
V_7 = F_101 ( V_221 , V_130 , V_60 ) ;
return V_7 ;
}
static int F_110 ( struct V_43 * V_221 )
{
return F_101 ( V_221 , V_40 , V_60 ) ;
}
static int F_111 ( struct V_43 * V_221 )
{
int V_7 ;
V_7 = F_112 ( V_221 ) ;
if ( V_7 == 0 )
V_7 = F_101 ( V_221 , V_130 , V_60 ) ;
return V_7 ;
}
static int F_113 ( struct V_43 * V_221 )
{
return F_101 ( V_221 , V_40 , V_60 ) ;
}
static int F_114 ( struct V_43 * V_221 )
{
return F_101 ( V_221 , V_130 , V_60 ) ;
}
static int F_115 ( struct V_43 * V_221 , struct V_228 * V_229 ,
int V_230 , T_3 V_181 )
{
struct V_47 V_48 ;
struct V_1 * V_9 ;
struct V_1 * V_209 = F_17 ( F_16 ( V_221 ) ) ;
F_14 ( & V_48 , V_60 , V_51 ) ;
F_15 ( & V_48 , V_221 ) ;
if ( V_181 == 0 )
return F_38 ( V_209 -> V_55 , V_130 , & V_48 ) ;
V_9 = F_99 ( V_181 ) ;
return V_204 ( V_9 , V_209 -> V_55 , V_130 , & V_48 ) ;
}
static int F_116 ( struct V_43 * V_221 )
{
return 0 ;
}
static void F_117 ( struct V_43 * V_221 , struct V_3 * V_3 )
{
struct V_14 * V_16 = V_3 -> V_99 ;
struct V_1 * V_9 = F_17 ( F_16 ( V_221 ) ) ;
V_16 -> V_18 = V_9 -> V_55 ;
}
static int F_118 ( struct V_168 * V_174 , int V_231 , T_1 V_232 )
{
struct V_1 * V_9 = F_27 () ;
struct V_165 * V_166 ;
V_166 = F_2 ( sizeof( struct V_165 ) , V_232 ) ;
if ( V_166 == NULL )
return - V_36 ;
V_166 -> V_177 = V_9 ;
V_166 -> V_179 = V_9 ;
V_166 -> V_233 = NULL ;
V_174 -> V_175 = V_166 ;
return 0 ;
}
static void F_119 ( struct V_168 * V_174 )
{
F_4 ( V_174 -> V_175 ) ;
}
static char * F_120 ( struct V_234 * V_235 )
{
struct V_236 * V_237 ;
struct V_238 * V_239 = & V_235 -> V_240 ;
if ( V_239 -> V_241 == 0 )
return NULL ;
F_10 (snp, &smk_netlbladdr_list, list)
if ( ( & V_237 -> V_242 . V_240 ) -> V_241 ==
( V_239 -> V_241 & ( & V_237 -> V_243 ) -> V_241 ) ) {
if ( V_237 -> V_244 == V_245 )
return NULL ;
return V_237 -> V_244 ;
}
return NULL ;
}
static int F_121 ( struct V_168 * V_174 , int V_246 )
{
struct V_1 * V_9 ;
struct V_165 * V_166 = V_174 -> V_175 ;
int V_7 = 0 ;
F_122 () ;
F_123 ( V_174 ) ;
if ( V_166 -> V_179 == V_247 ||
V_246 == V_248 )
F_124 ( V_174 ) ;
else {
V_9 = V_166 -> V_179 ;
V_7 = F_125 ( V_174 , V_174 -> V_249 , & V_9 -> V_250 ) ;
}
F_126 ( V_174 ) ;
F_127 () ;
return V_7 ;
}
static int F_128 ( struct V_168 * V_174 , struct V_234 * V_251 )
{
struct V_1 * V_9 ;
int V_7 ;
int V_252 ;
char * V_253 ;
struct V_165 * V_166 = V_174 -> V_175 ;
struct V_47 V_48 ;
F_42 () ;
V_253 = F_120 ( V_251 ) ;
if ( V_253 != NULL ) {
#ifdef F_129
struct V_254 V_255 ;
F_130 ( & V_48 , V_60 , V_256 , & V_255 ) ;
V_48 . V_257 . V_258 . V_255 -> V_231 = V_251 -> V_259 ;
V_48 . V_257 . V_258 . V_255 -> V_260 = V_251 -> V_261 ;
V_48 . V_257 . V_258 . V_255 -> V_262 . V_263 = V_251 -> V_240 . V_241 ;
#endif
V_252 = V_248 ;
V_9 = V_166 -> V_179 ;
V_7 = V_204 ( V_9 , V_253 , V_130 , & V_48 ) ;
} else {
V_252 = V_264 ;
V_7 = 0 ;
}
F_45 () ;
if ( V_7 != 0 )
return V_7 ;
return F_121 ( V_174 , V_252 ) ;
}
static void F_131 ( struct V_167 * V_168 , struct V_265 * V_266 )
{
struct V_168 * V_174 = V_168 -> V_174 ;
struct V_267 * V_268 ;
struct V_165 * V_166 = V_168 -> V_174 -> V_175 ;
struct V_269 * V_270 ;
unsigned short V_271 = 0 ;
if ( V_266 == NULL ) {
F_132 (spp, &smk_ipv6_port_list, list) {
if ( V_174 != V_270 -> V_272 )
continue;
V_270 -> V_177 = V_166 -> V_177 ;
V_270 -> V_179 = V_166 -> V_179 ;
return;
}
return;
}
V_268 = (struct V_267 * ) V_266 ;
V_271 = F_133 ( V_268 -> V_273 ) ;
if ( V_271 == 0 )
return;
F_132 (spp, &smk_ipv6_port_list, list) {
if ( V_270 -> V_274 != V_271 )
continue;
V_270 -> V_274 = V_271 ;
V_270 -> V_272 = V_174 ;
V_270 -> V_177 = V_166 -> V_177 ;
V_270 -> V_179 = V_166 -> V_179 ;
return;
}
V_270 = F_2 ( sizeof( * V_270 ) , V_13 ) ;
if ( V_270 == NULL )
return;
V_270 -> V_274 = V_271 ;
V_270 -> V_272 = V_174 ;
V_270 -> V_177 = V_166 -> V_177 ;
V_270 -> V_179 = V_166 -> V_179 ;
F_134 ( & V_270 -> V_37 , & V_275 ) ;
return;
}
static int F_135 ( struct V_168 * V_174 , struct V_267 * V_266 ,
int V_276 )
{
T_5 * V_277 ;
T_6 * V_278 ;
struct V_269 * V_270 ;
struct V_165 * V_166 = V_174 -> V_175 ;
struct V_1 * V_9 ;
unsigned short V_271 = 0 ;
char * V_279 ;
struct V_47 V_48 ;
#ifdef F_129
struct V_254 V_255 ;
#endif
if ( V_276 == V_280 ) {
V_9 = V_247 ;
V_279 = V_166 -> V_177 -> V_55 ;
} else {
V_9 = V_166 -> V_179 ;
V_279 = V_247 -> V_55 ;
}
V_271 = F_133 ( V_266 -> V_273 ) ;
V_277 = ( T_5 * ) ( & V_266 -> V_281 ) ;
V_278 = ( T_6 * ) ( & V_266 -> V_281 ) ;
if ( V_278 [ 0 ] || V_278 [ 1 ] || V_278 [ 2 ] || V_277 [ 6 ] || F_133 ( V_277 [ 7 ] ) != 1 )
goto V_282;
if ( V_276 == V_280 ) {
V_9 = & V_161 ;
goto V_282;
}
F_132 (spp, &smk_ipv6_port_list, list) {
if ( V_270 -> V_274 != V_271 )
continue;
V_279 = V_270 -> V_177 -> V_55 ;
if ( V_276 == V_283 )
V_166 -> V_233 = V_270 -> V_179 ;
break;
}
V_282:
#ifdef F_129
F_130 ( & V_48 , V_60 , V_256 , & V_255 ) ;
V_48 . V_257 . V_258 . V_255 -> V_231 = V_174 -> V_249 ;
V_48 . V_257 . V_258 . V_255 -> V_260 = V_271 ;
if ( V_276 == V_280 )
V_48 . V_257 . V_258 . V_255 -> V_284 . V_285 = V_266 -> V_281 ;
else
V_48 . V_257 . V_258 . V_255 -> V_284 . V_263 = V_266 -> V_281 ;
#endif
return V_204 ( V_9 , V_279 , V_130 , & V_48 ) ;
}
static int F_136 ( struct V_3 * V_3 , const char * V_2 ,
const void * V_120 , T_2 V_147 , int V_86 )
{
struct V_1 * V_9 ;
struct V_14 * V_93 = V_3 -> V_99 ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
int V_7 = 0 ;
if ( V_120 == NULL || V_147 > V_12 || V_147 == 0 )
return - V_159 ;
V_9 = F_3 ( V_120 , V_147 ) ;
if ( V_9 == NULL )
return - V_159 ;
if ( strcmp ( V_2 , V_125 ) == 0 ) {
V_93 -> V_18 = V_9 -> V_55 ;
V_93 -> V_19 |= V_286 ;
return 0 ;
}
if ( V_3 -> V_170 -> V_171 != V_172 )
return - V_173 ;
V_168 = F_72 ( V_3 ) ;
if ( V_168 == NULL || V_168 -> V_174 == NULL )
return - V_173 ;
V_166 = V_168 -> V_174 -> V_175 ;
if ( strcmp ( V_2 , V_176 ) == 0 )
V_166 -> V_177 = V_9 ;
else if ( strcmp ( V_2 , V_178 ) == 0 ) {
V_166 -> V_179 = V_9 ;
if ( V_168 -> V_174 -> V_249 == V_287 ) {
V_7 = F_121 ( V_168 -> V_174 , V_264 ) ;
if ( V_7 != 0 )
F_137 ( V_288
L_2 ,
V_60 , - V_7 ) ;
}
} else
return - V_173 ;
if ( V_168 -> V_174 -> V_249 == V_289 )
F_131 ( V_168 , NULL ) ;
return 0 ;
}
static int F_138 ( struct V_167 * V_168 , int V_231 ,
int type , int V_290 , int V_291 )
{
if ( V_231 != V_287 || V_168 -> V_174 == NULL )
return 0 ;
return F_121 ( V_168 -> V_174 , V_264 ) ;
}
static int F_139 ( struct V_167 * V_168 , struct V_265 * V_266 ,
int V_292 )
{
if ( V_168 -> V_174 != NULL && V_168 -> V_174 -> V_249 == V_289 )
F_131 ( V_168 , V_266 ) ;
return 0 ;
}
static int F_140 ( struct V_167 * V_168 , struct V_265 * V_251 ,
int V_292 )
{
int V_7 = 0 ;
if ( V_168 -> V_174 == NULL )
return 0 ;
switch ( V_168 -> V_174 -> V_249 ) {
case V_287 :
if ( V_292 < sizeof( struct V_234 ) )
return - V_159 ;
V_7 = F_128 ( V_168 -> V_174 , (struct V_234 * ) V_251 ) ;
break;
case V_289 :
if ( V_292 < sizeof( struct V_267 ) )
return - V_159 ;
V_7 = F_135 ( V_168 -> V_174 , (struct V_267 * ) V_251 ,
V_283 ) ;
break;
}
return V_7 ;
}
static int F_141 ( int V_86 )
{
int V_124 = 0 ;
if ( V_86 & V_293 )
V_124 |= V_40 ;
if ( V_86 & V_294 )
V_124 |= V_130 ;
if ( V_86 & V_295 )
V_124 |= V_137 ;
return V_124 ;
}
static int F_142 ( struct V_296 * V_297 )
{
struct V_1 * V_9 = F_27 () ;
V_297 -> V_109 = V_9 -> V_55 ;
return 0 ;
}
static void F_143 ( struct V_296 * V_297 )
{
V_297 -> V_109 = NULL ;
}
static char * F_144 ( struct V_298 * V_299 )
{
return ( char * ) V_299 -> V_300 . V_109 ;
}
static int F_145 ( struct V_298 * V_299 )
{
struct V_301 * V_16 = & V_299 -> V_300 ;
struct V_1 * V_9 = F_27 () ;
V_16 -> V_109 = V_9 -> V_55 ;
return 0 ;
}
static void F_146 ( struct V_298 * V_299 )
{
struct V_301 * V_16 = & V_299 -> V_300 ;
V_16 -> V_109 = NULL ;
}
static int F_147 ( struct V_298 * V_299 , int V_222 )
{
char * V_166 = F_144 ( V_299 ) ;
struct V_47 V_48 ;
#ifdef F_129
F_14 ( & V_48 , V_60 , V_302 ) ;
V_48 . V_257 . V_258 . V_303 = V_299 -> V_300 . V_304 ;
#endif
return F_38 ( V_166 , V_222 , & V_48 ) ;
}
static int F_148 ( struct V_298 * V_299 , int V_305 )
{
int V_124 ;
V_124 = F_141 ( V_305 ) ;
return F_147 ( V_299 , V_124 ) ;
}
static int F_149 ( struct V_298 * V_299 , int V_183 )
{
int V_124 ;
switch ( V_183 ) {
case V_306 :
case V_307 :
V_124 = V_40 ;
break;
case V_308 :
case V_309 :
case V_310 :
case V_311 :
V_124 = V_42 ;
break;
case V_312 :
case V_313 :
return 0 ;
default:
return - V_159 ;
}
return F_147 ( V_299 , V_124 ) ;
}
static int F_150 ( struct V_298 * V_299 , char T_7 * V_314 ,
int V_305 )
{
int V_124 ;
V_124 = F_141 ( V_305 ) ;
return F_147 ( V_299 , V_124 ) ;
}
static char * F_151 ( struct V_315 * V_316 )
{
return ( char * ) V_316 -> V_317 . V_109 ;
}
static int F_152 ( struct V_315 * V_316 )
{
struct V_301 * V_16 = & V_316 -> V_317 ;
struct V_1 * V_9 = F_27 () ;
V_16 -> V_109 = V_9 -> V_55 ;
return 0 ;
}
static void F_153 ( struct V_315 * V_316 )
{
struct V_301 * V_16 = & V_316 -> V_317 ;
V_16 -> V_109 = NULL ;
}
static int F_154 ( struct V_315 * V_316 , int V_222 )
{
char * V_166 = F_151 ( V_316 ) ;
struct V_47 V_48 ;
#ifdef F_129
F_14 ( & V_48 , V_60 , V_302 ) ;
V_48 . V_257 . V_258 . V_303 = V_316 -> V_317 . V_304 ;
#endif
return F_38 ( V_166 , V_222 , & V_48 ) ;
}
static int F_155 ( struct V_315 * V_316 , int V_318 )
{
int V_124 ;
V_124 = F_141 ( V_318 ) ;
return F_154 ( V_316 , V_124 ) ;
}
static int F_156 ( struct V_315 * V_316 , int V_183 )
{
int V_124 ;
switch ( V_183 ) {
case V_319 :
case V_320 :
case V_321 :
case V_322 :
case V_323 :
case V_306 :
case V_324 :
V_124 = V_40 ;
break;
case V_325 :
case V_326 :
case V_311 :
case V_308 :
V_124 = V_42 ;
break;
case V_312 :
case V_327 :
return 0 ;
default:
return - V_159 ;
}
return F_154 ( V_316 , V_124 ) ;
}
static int F_157 ( struct V_315 * V_316 , struct V_328 * V_329 ,
unsigned V_330 , int V_331 )
{
return F_154 ( V_316 , V_42 ) ;
}
static int F_158 ( struct V_332 * V_333 )
{
struct V_301 * V_334 = & V_333 -> V_335 ;
struct V_1 * V_9 = F_27 () ;
V_334 -> V_109 = V_9 -> V_55 ;
return 0 ;
}
static void F_159 ( struct V_332 * V_333 )
{
struct V_301 * V_334 = & V_333 -> V_335 ;
V_334 -> V_109 = NULL ;
}
static char * F_160 ( struct V_332 * V_333 )
{
return ( char * ) V_333 -> V_335 . V_109 ;
}
static int F_161 ( struct V_332 * V_333 , int V_222 )
{
char * V_336 = F_160 ( V_333 ) ;
struct V_47 V_48 ;
#ifdef F_129
F_14 ( & V_48 , V_60 , V_302 ) ;
V_48 . V_257 . V_258 . V_303 = V_333 -> V_335 . V_304 ;
#endif
return F_38 ( V_336 , V_222 , & V_48 ) ;
}
static int F_162 ( struct V_332 * V_333 , int V_337 )
{
int V_124 ;
V_124 = F_141 ( V_337 ) ;
return F_161 ( V_333 , V_124 ) ;
}
static int F_163 ( struct V_332 * V_333 , int V_183 )
{
int V_124 ;
switch ( V_183 ) {
case V_306 :
case V_338 :
V_124 = V_40 ;
break;
case V_308 :
case V_311 :
V_124 = V_42 ;
break;
case V_312 :
case V_339 :
return 0 ;
default:
return - V_159 ;
}
return F_161 ( V_333 , V_124 ) ;
}
static int F_164 ( struct V_332 * V_333 , struct V_296 * V_297 ,
int V_337 )
{
int V_124 ;
V_124 = F_141 ( V_337 ) ;
return F_161 ( V_333 , V_124 ) ;
}
static int F_165 ( struct V_332 * V_333 , struct V_296 * V_297 ,
struct V_43 * V_340 , long type , int V_38 )
{
return F_161 ( V_333 , V_42 ) ;
}
static int F_166 ( struct V_301 * V_341 , short V_342 )
{
char * V_16 = V_341 -> V_109 ;
int V_124 = F_141 ( V_342 ) ;
struct V_47 V_48 ;
#ifdef F_129
F_14 ( & V_48 , V_60 , V_302 ) ;
V_48 . V_257 . V_258 . V_303 = V_341 -> V_304 ;
#endif
return F_38 ( V_16 , V_124 , & V_48 ) ;
}
static void F_167 ( struct V_301 * V_341 , T_3 * V_181 )
{
char * V_15 = V_341 -> V_109 ;
* V_181 = F_75 ( V_15 ) ;
}
static void F_168 ( struct V_5 * V_343 , struct V_3 * V_3 )
{
struct V_65 * V_101 ;
struct V_67 * V_68 ;
struct V_14 * V_16 ;
struct V_1 * V_9 ;
struct V_1 * V_344 = F_27 () ;
char * V_345 ;
char V_346 [ V_157 ] ;
int V_347 = 0 ;
int V_7 ;
struct V_5 * V_6 ;
if ( V_3 == NULL )
return;
V_16 = V_3 -> V_99 ;
F_169 ( & V_16 -> V_20 ) ;
if ( V_16 -> V_19 & V_286 )
goto V_348;
V_101 = V_3 -> V_170 ;
V_68 = V_101 -> V_75 ;
V_345 = V_68 -> V_71 ;
if ( V_343 -> V_349 == V_343 ) {
if ( V_101 -> V_171 == V_350 ) {
V_68 -> V_69 = V_160 . V_55 ;
V_68 -> V_71 = V_160 . V_55 ;
}
V_16 -> V_18 = V_68 -> V_69 ;
V_16 -> V_19 |= V_286 ;
goto V_348;
}
switch ( V_101 -> V_171 ) {
case V_351 :
case V_352 :
case V_172 :
case V_350 :
V_345 = V_160 . V_55 ;
break;
case V_353 :
V_345 = V_344 -> V_55 ;
break;
case V_354 :
break;
case V_355 :
V_345 = V_160 . V_55 ;
default:
if ( F_170 ( V_3 -> V_356 ) ) {
V_345 = V_160 . V_55 ;
break;
}
if ( V_3 -> V_10 -> V_11 == NULL )
break;
V_6 = F_171 ( V_343 ) ;
V_9 = F_1 ( V_151 , V_3 , V_6 ) ;
if ( V_9 != NULL )
V_345 = V_9 -> V_55 ;
if ( F_172 ( V_3 -> V_356 ) ) {
if ( V_16 -> V_19 & V_127 ) {
V_16 -> V_19 &= ~ V_127 ;
V_7 = V_3 -> V_10 -> V_357 ( V_6 ,
V_156 ,
V_158 , V_157 ,
0 ) ;
} else {
V_7 = V_3 -> V_10 -> V_11 ( V_6 ,
V_156 , V_346 ,
V_157 ) ;
if ( V_7 >= 0 && strncmp ( V_346 , V_158 ,
V_157 ) != 0 )
V_7 = - V_159 ;
}
if ( V_7 >= 0 )
V_347 = V_100 ;
}
V_9 = F_1 ( V_154 , V_3 , V_6 ) ;
if ( V_9 == & V_160 || V_9 == & V_161 )
V_9 = NULL ;
V_16 -> V_26 = V_9 ;
V_9 = F_1 ( V_155 , V_3 , V_6 ) ;
if ( V_9 == & V_160 || V_9 == & V_161 )
V_9 = NULL ;
V_16 -> V_163 = V_9 ;
F_173 ( V_6 ) ;
break;
}
if ( V_345 == NULL )
V_16 -> V_18 = V_344 -> V_55 ;
else
V_16 -> V_18 = V_345 ;
V_16 -> V_19 |= ( V_286 | V_347 ) ;
V_348:
F_174 ( & V_16 -> V_20 ) ;
return;
}
static int F_175 ( struct V_43 * V_221 , char * V_2 , char * * V_120 )
{
struct V_1 * V_9 = F_17 ( F_16 ( V_221 ) ) ;
char * V_78 ;
int V_358 ;
if ( strcmp ( V_2 , L_3 ) != 0 )
return - V_159 ;
V_78 = F_55 ( V_9 -> V_55 , V_13 ) ;
if ( V_78 == NULL )
return - V_36 ;
V_358 = strlen ( V_78 ) ;
* V_120 = V_78 ;
return V_358 ;
}
static int F_176 ( struct V_43 * V_221 , char * V_2 ,
void * V_120 , T_2 V_147 )
{
struct V_21 * V_25 ;
struct V_108 * V_217 ;
struct V_1 * V_9 ;
if ( V_221 != V_59 )
return - V_98 ;
if ( ! F_28 ( V_97 ) )
return - V_98 ;
if ( V_120 == NULL || V_147 == 0 || V_147 >= V_12 )
return - V_159 ;
if ( strcmp ( V_2 , L_3 ) != 0 )
return - V_159 ;
V_9 = F_3 ( V_120 , V_147 ) ;
if ( V_9 == NULL )
return - V_159 ;
if ( V_9 == & V_161 )
return - V_98 ;
V_217 = F_177 () ;
if ( V_217 == NULL )
return - V_36 ;
V_25 = V_217 -> V_109 ;
V_25 -> V_26 = V_9 ;
F_178 ( V_217 ) ;
return V_147 ;
}
static int F_179 ( struct V_168 * V_168 ,
struct V_168 * V_359 , struct V_168 * V_360 )
{
struct V_1 * V_9 ;
struct V_1 * V_361 ;
struct V_165 * V_166 = V_168 -> V_175 ;
struct V_165 * V_362 = V_359 -> V_175 ;
struct V_165 * V_93 = V_360 -> V_175 ;
struct V_47 V_48 ;
int V_7 = 0 ;
#ifdef F_129
struct V_254 V_255 ;
#endif
if ( ! F_28 ( V_63 ) ) {
V_9 = V_166 -> V_179 ;
V_361 = V_362 -> V_179 ;
#ifdef F_129
F_130 ( & V_48 , V_60 , V_256 , & V_255 ) ;
F_180 ( & V_48 , V_359 ) ;
#endif
V_7 = V_204 ( V_9 , V_361 -> V_55 , V_130 , & V_48 ) ;
if ( V_7 == 0 )
V_7 = V_204 ( V_361 , V_361 -> V_55 , V_130 , NULL ) ;
}
if ( V_7 == 0 ) {
V_93 -> V_233 = V_166 -> V_179 ;
V_166 -> V_233 = V_362 -> V_179 ;
}
return V_7 ;
}
static int F_181 ( struct V_167 * V_168 , struct V_167 * V_359 )
{
struct V_165 * V_166 = V_168 -> V_174 -> V_175 ;
struct V_165 * V_362 = V_359 -> V_174 -> V_175 ;
struct V_1 * V_9 ;
struct V_47 V_48 ;
#ifdef F_129
struct V_254 V_255 ;
F_130 ( & V_48 , V_60 , V_256 , & V_255 ) ;
F_180 ( & V_48 , V_359 -> V_174 ) ;
#endif
if ( F_28 ( V_63 ) )
return 0 ;
V_9 = V_166 -> V_179 ;
return V_204 ( V_9 , V_362 -> V_177 -> V_55 , V_130 , & V_48 ) ;
}
static int F_182 ( struct V_167 * V_168 , struct V_363 * V_297 ,
int V_147 )
{
struct V_234 * V_235 = (struct V_234 * ) V_297 -> V_364 ;
struct V_267 * V_251 = (struct V_267 * ) V_297 -> V_364 ;
int V_7 = 0 ;
if ( V_235 == NULL )
return 0 ;
switch ( V_235 -> V_259 ) {
case V_365 :
V_7 = F_128 ( V_168 -> V_174 , V_235 ) ;
break;
case V_366 :
V_7 = F_135 ( V_168 -> V_174 , V_251 , V_367 ) ;
break;
}
return V_7 ;
}
static struct V_1 * F_183 ( struct V_368 * V_251 ,
struct V_165 * V_166 )
{
struct V_1 * V_9 ;
int V_369 = 0 ;
int V_370 ;
int V_371 ;
if ( ( V_251 -> V_86 & V_372 ) != 0 ) {
F_42 () ;
F_132 (skp, &smack_known_list, list) {
if ( V_251 -> V_373 . V_374 . V_375 != V_9 -> V_250 . V_373 . V_374 . V_375 )
continue;
if ( ( V_251 -> V_86 & V_376 ) == 0 ) {
if ( ( V_9 -> V_250 . V_86 &
V_376 ) == 0 )
V_369 = 1 ;
break;
}
for ( V_370 = - 1 , V_371 = - 1 ; V_370 == V_371 ; ) {
V_370 = F_184 (
V_251 -> V_373 . V_374 . V_377 , V_370 + 1 ) ;
V_371 = F_184 (
V_9 -> V_250 . V_373 . V_374 . V_377 ,
V_371 + 1 ) ;
if ( V_370 < 0 || V_371 < 0 )
break;
}
if ( V_370 == V_371 ) {
V_369 = 1 ;
break;
}
}
F_45 () ;
if ( V_369 )
return V_9 ;
if ( V_166 != NULL && V_166 -> V_177 == & V_160 )
return & V_161 ;
return & V_160 ;
}
if ( ( V_251 -> V_86 & V_378 ) != 0 ) {
V_9 = F_99 ( V_251 -> V_373 . V_181 ) ;
F_185 ( V_9 == NULL ) ;
return V_9 ;
}
return V_247 ;
}
static int F_186 ( struct V_379 * V_380 , struct V_267 * V_235 )
{
T_8 V_381 ;
int V_382 ;
int V_383 = - V_159 ;
struct V_384 V_385 ;
struct V_384 * V_386 ;
T_5 V_387 ;
struct V_388 V_389 , * V_390 ;
struct V_391 V_392 , * V_393 ;
struct V_394 V_395 , * V_396 ;
V_235 -> V_273 = 0 ;
V_382 = F_187 ( V_380 ) ;
V_386 = F_188 ( V_380 , V_382 , sizeof( V_385 ) , & V_385 ) ;
if ( V_386 == NULL )
return - V_159 ;
V_235 -> V_281 = V_386 -> V_285 ;
V_381 = V_386 -> V_381 ;
V_382 += sizeof( V_385 ) ;
V_382 = F_189 ( V_380 , V_382 , & V_381 , & V_387 ) ;
if ( V_382 < 0 )
return - V_159 ;
V_383 = V_381 ;
switch ( V_383 ) {
case V_397 :
V_390 = F_188 ( V_380 , V_382 , sizeof( V_389 ) , & V_389 ) ;
if ( V_390 != NULL )
V_235 -> V_273 = V_390 -> V_398 ;
break;
case V_399 :
V_393 = F_188 ( V_380 , V_382 , sizeof( V_392 ) , & V_392 ) ;
if ( V_393 != NULL )
V_235 -> V_273 = V_393 -> V_398 ;
break;
case V_400 :
V_396 = F_188 ( V_380 , V_382 , sizeof( V_395 ) , & V_395 ) ;
if ( V_396 != NULL )
V_235 -> V_273 = V_396 -> V_401 ;
break;
}
return V_383 ;
}
static int F_190 ( struct V_168 * V_174 , struct V_379 * V_380 )
{
struct V_368 V_402 ;
struct V_165 * V_166 = V_174 -> V_175 ;
struct V_1 * V_9 ;
struct V_267 V_403 ;
int V_7 = 0 ;
struct V_47 V_48 ;
#ifdef F_129
struct V_254 V_255 ;
#endif
switch ( V_174 -> V_249 ) {
case V_287 :
F_191 ( & V_402 ) ;
V_7 = F_192 ( V_380 , V_174 -> V_249 , & V_402 ) ;
if ( V_7 == 0 )
V_9 = F_183 ( & V_402 , V_166 ) ;
else
V_9 = V_247 ;
F_193 ( & V_402 ) ;
#ifdef F_129
F_130 ( & V_48 , V_60 , V_256 , & V_255 ) ;
V_48 . V_257 . V_258 . V_255 -> V_231 = V_174 -> V_249 ;
V_48 . V_257 . V_258 . V_255 -> V_404 = V_380 -> V_405 ;
F_194 ( V_380 , & V_48 . V_257 , NULL ) ;
#endif
V_7 = V_204 ( V_9 , V_166 -> V_177 -> V_55 , V_130 , & V_48 ) ;
if ( V_7 != 0 )
F_195 ( V_380 , V_7 , 0 ) ;
break;
case V_289 :
V_7 = F_186 ( V_380 , & V_403 ) ;
if ( V_7 == V_399 || V_7 == V_397 )
V_7 = F_135 ( V_174 , & V_403 , V_280 ) ;
else
V_7 = 0 ;
break;
}
return V_7 ;
}
static int F_196 ( struct V_167 * V_168 ,
char T_7 * V_406 ,
int T_7 * V_407 , unsigned V_121 )
{
struct V_165 * V_166 ;
char * V_408 = L_4 ;
int V_358 = 1 ;
int V_7 = 0 ;
V_166 = V_168 -> V_174 -> V_175 ;
if ( V_166 -> V_233 != NULL ) {
V_408 = V_166 -> V_233 -> V_55 ;
V_358 = strlen ( V_408 ) + 1 ;
}
if ( V_358 > V_121 )
V_7 = - V_409 ;
else if ( F_197 ( V_406 , V_408 , V_358 ) != 0 )
V_7 = - V_410 ;
if ( F_198 ( V_358 , V_407 ) != 0 )
V_7 = - V_410 ;
return V_7 ;
}
static int F_199 ( struct V_167 * V_168 ,
struct V_379 * V_380 , T_3 * V_181 )
{
struct V_368 V_402 ;
struct V_165 * V_166 = NULL ;
struct V_1 * V_9 ;
int V_231 = V_411 ;
T_3 V_412 = 0 ;
int V_7 ;
if ( V_380 != NULL ) {
if ( V_380 -> V_290 == F_200 ( V_413 ) )
V_231 = V_287 ;
else if ( V_380 -> V_290 == F_200 ( V_414 ) )
V_231 = V_289 ;
}
if ( V_231 == V_411 && V_168 != NULL )
V_231 = V_168 -> V_174 -> V_249 ;
if ( V_231 == V_415 ) {
V_166 = V_168 -> V_174 -> V_175 ;
V_412 = V_166 -> V_179 -> V_225 ;
} else if ( V_231 == V_287 || V_231 == V_289 ) {
if ( V_168 != NULL && V_168 -> V_174 != NULL )
V_166 = V_168 -> V_174 -> V_175 ;
F_191 ( & V_402 ) ;
V_7 = F_192 ( V_380 , V_231 , & V_402 ) ;
if ( V_7 == 0 ) {
V_9 = F_183 ( & V_402 , V_166 ) ;
V_412 = V_9 -> V_225 ;
}
F_193 ( & V_402 ) ;
}
* V_181 = V_412 ;
if ( V_412 == 0 )
return - V_159 ;
return 0 ;
}
static void F_201 ( struct V_168 * V_174 , struct V_167 * V_416 )
{
struct V_165 * V_166 ;
struct V_1 * V_9 = F_27 () ;
if ( V_174 == NULL ||
( V_174 -> V_249 != V_287 && V_174 -> V_249 != V_289 ) )
return;
V_166 = V_174 -> V_175 ;
V_166 -> V_177 = V_9 ;
V_166 -> V_179 = V_9 ;
}
static int F_202 ( struct V_168 * V_174 , struct V_379 * V_380 ,
struct V_417 * V_418 )
{
T_9 V_231 = V_174 -> V_249 ;
struct V_1 * V_9 ;
struct V_165 * V_166 = V_174 -> V_175 ;
struct V_368 V_402 ;
struct V_234 V_419 ;
struct V_420 * V_421 ;
char * V_422 ;
int V_7 ;
struct V_47 V_48 ;
#ifdef F_129
struct V_254 V_255 ;
#endif
if ( V_231 == V_289 ) {
if ( V_380 -> V_290 == F_200 ( V_413 ) )
V_231 = V_287 ;
else
return 0 ;
}
F_191 ( & V_402 ) ;
V_7 = F_192 ( V_380 , V_231 , & V_402 ) ;
if ( V_7 == 0 )
V_9 = F_183 ( & V_402 , V_166 ) ;
else
V_9 = & V_423 ;
F_193 ( & V_402 ) ;
#ifdef F_129
F_130 ( & V_48 , V_60 , V_256 , & V_255 ) ;
V_48 . V_257 . V_258 . V_255 -> V_231 = V_231 ;
V_48 . V_257 . V_258 . V_255 -> V_404 = V_380 -> V_405 ;
F_194 ( V_380 , & V_48 . V_257 , NULL ) ;
#endif
V_7 = V_204 ( V_9 , V_166 -> V_177 -> V_55 , V_130 , & V_48 ) ;
if ( V_7 != 0 )
return V_7 ;
V_418 -> V_424 = V_9 -> V_225 ;
V_421 = F_203 ( V_380 ) ;
V_419 . V_240 . V_241 = V_421 -> V_285 ;
F_42 () ;
V_422 = F_120 ( & V_419 ) ;
F_45 () ;
if ( V_422 == NULL )
V_7 = F_204 ( V_418 , & V_9 -> V_250 ) ;
else
F_205 ( V_418 ) ;
return V_7 ;
}
static void F_206 ( struct V_168 * V_174 ,
const struct V_417 * V_418 )
{
struct V_165 * V_166 = V_174 -> V_175 ;
struct V_1 * V_9 ;
if ( V_418 -> V_424 != 0 ) {
V_9 = F_99 ( V_418 -> V_424 ) ;
V_166 -> V_233 = V_9 ;
} else
V_166 -> V_233 = NULL ;
}
static int F_207 ( struct V_425 * V_425 , const struct V_108 * V_108 ,
unsigned long V_86 )
{
struct V_1 * V_9 = F_17 ( V_108 -> V_109 ) ;
V_425 -> V_109 = V_9 -> V_55 ;
return 0 ;
}
static void F_208 ( struct V_425 * V_425 )
{
V_425 -> V_109 = NULL ;
}
static int F_209 ( T_10 V_426 ,
const struct V_108 * V_108 , unsigned V_427 )
{
struct V_425 * V_428 ;
struct V_47 V_48 ;
struct V_1 * V_209 = F_17 ( V_108 -> V_109 ) ;
int V_429 = 0 ;
V_428 = F_210 ( V_426 ) ;
if ( V_428 == NULL )
return - V_159 ;
if ( V_428 -> V_109 == NULL )
return 0 ;
if ( V_209 == NULL )
return - V_56 ;
#ifdef F_129
F_14 ( & V_48 , V_60 , V_430 ) ;
V_48 . V_257 . V_258 . V_431 . V_425 = V_428 -> V_432 ;
V_48 . V_257 . V_258 . V_431 . V_433 = V_428 -> V_434 ;
#endif
if ( V_427 & V_435 )
V_429 = V_40 ;
if ( V_427 & ( V_436 | V_437 | V_438 ) )
V_429 = V_130 ;
return V_204 ( V_209 , V_428 -> V_109 , V_429 , & V_48 ) ;
}
static int F_211 ( T_3 V_439 , T_3 V_92 , char * V_440 , void * * V_441 )
{
char * * V_442 = ( char * * ) V_441 ;
* V_442 = NULL ;
if ( V_439 != V_443 && V_439 != V_444 )
return - V_159 ;
if ( V_92 != V_445 && V_92 != V_446 )
return - V_159 ;
* V_442 = F_35 ( V_440 , 0 ) ;
return 0 ;
}
static int F_212 ( struct V_447 * V_448 )
{
struct V_449 * V_450 ;
int V_451 ;
for ( V_451 = 0 ; V_451 < V_448 -> V_452 ; V_451 ++ ) {
V_450 = & V_448 -> V_453 [ V_451 ] ;
if ( V_450 -> type == V_443 || V_450 -> type == V_444 )
return 1 ;
}
return 0 ;
}
static int F_213 ( T_3 V_181 , T_3 V_439 , T_3 V_92 , void * V_441 ,
struct V_454 * V_455 )
{
struct V_1 * V_9 ;
char * V_442 = V_441 ;
if ( F_214 ( ! V_442 ) ) {
F_215 ( 1 , L_5 ) ;
return - V_203 ;
}
if ( V_439 != V_443 && V_439 != V_444 )
return 0 ;
V_9 = F_99 ( V_181 ) ;
if ( V_92 == V_445 )
return ( V_442 == V_9 -> V_55 ) ;
if ( V_92 == V_446 )
return ( V_442 != V_9 -> V_55 ) ;
return 0 ;
}
static void F_216 ( void * V_441 )
{
}
static int F_217 ( const char * V_2 )
{
return ( strcmp ( V_2 , V_125 ) == 0 ) ;
}
static int F_218 ( T_3 V_181 , char * * V_456 , T_3 * V_457 )
{
struct V_1 * V_9 = F_99 ( V_181 ) ;
if ( V_456 )
* V_456 = V_9 -> V_55 ;
* V_457 = strlen ( V_9 -> V_55 ) ;
return 0 ;
}
static int F_219 ( const char * V_456 , T_3 V_457 , T_3 * V_181 )
{
* V_181 = F_75 ( V_456 ) ;
return 0 ;
}
static void F_220 ( char * V_456 , T_3 V_457 )
{
}
static int F_221 ( struct V_3 * V_3 , void * V_458 , T_3 V_459 )
{
return F_136 ( V_3 , V_125 , V_458 , V_459 , 0 ) ;
}
static int F_222 ( struct V_5 * V_5 , void * V_458 , T_3 V_459 )
{
return F_223 ( V_5 , V_151 , V_458 , V_459 , 0 ) ;
}
static int F_224 ( struct V_3 * V_3 , void * * V_458 , T_3 * V_459 )
{
int V_121 = 0 ;
V_121 = F_71 ( V_3 , V_125 , V_458 , true ) ;
if ( V_121 < 0 )
return V_121 ;
* V_459 = V_121 ;
return 0 ;
}
static T_11 void F_225 ( void )
{
F_6 ( & V_423 . V_29 ) ;
F_6 ( & V_74 . V_29 ) ;
F_6 ( & V_70 . V_29 ) ;
F_6 ( & V_160 . V_29 ) ;
F_6 ( & V_162 . V_29 ) ;
F_6 ( & V_161 . V_29 ) ;
F_8 ( & V_423 . V_28 ) ;
F_8 ( & V_74 . V_28 ) ;
F_8 ( & V_160 . V_28 ) ;
F_8 ( & V_70 . V_28 ) ;
F_8 ( & V_162 . V_28 ) ;
F_8 ( & V_161 . V_28 ) ;
F_226 ( & V_423 ) ;
F_226 ( & V_74 ) ;
F_226 ( & V_160 ) ;
F_226 ( & V_70 ) ;
F_226 ( & V_162 ) ;
F_226 ( & V_161 ) ;
}
static T_11 int F_227 ( void )
{
struct V_108 * V_108 ;
struct V_21 * V_25 ;
if ( ! F_228 ( & V_460 ) )
return 0 ;
V_25 = F_7 ( & V_70 , & V_70 ,
V_13 ) ;
if ( V_25 == NULL )
return - V_36 ;
F_137 ( V_461 L_6 ) ;
V_108 = (struct V_108 * ) V_59 -> V_108 ;
V_108 -> V_109 = V_25 ;
F_225 () ;
if ( F_229 ( & V_460 ) )
F_230 ( L_7 ) ;
return 0 ;
}

static void F_1 ( int V_1 , char * V_2 )
{
int V_3 = 0 ;
if ( V_1 & V_4 )
V_2 [ V_3 ++ ] = 'r' ;
if ( V_1 & V_5 )
V_2 [ V_3 ++ ] = 'w' ;
if ( V_1 & V_6 )
V_2 [ V_3 ++ ] = 'x' ;
if ( V_1 & V_7 )
V_2 [ V_3 ++ ] = 'a' ;
if ( V_1 & V_8 )
V_2 [ V_3 ++ ] = 't' ;
if ( V_1 & V_9 )
V_2 [ V_3 ++ ] = 'l' ;
if ( V_3 == 0 )
V_2 [ V_3 ++ ] = '-' ;
V_2 [ V_3 ] = '\0' ;
}
static int F_2 ( char * V_10 , struct V_11 * V_12 ,
struct V_11 * V_13 , int V_1 , int V_14 )
{
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_1 ,
V_12 -> V_17 , V_13 -> V_17 , V_15 , V_10 ) ;
return 0 ;
}
static int F_4 ( char * V_10 , struct V_11 * V_13 ,
int V_1 , int V_14 )
{
struct V_18 * V_19 = F_5 () ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_2 ,
V_19 -> V_20 -> V_17 , V_13 -> V_17 ,
V_15 , V_21 -> V_22 , V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_23 * V_24 , int V_1 , int V_14 )
{
struct V_18 * V_19 = F_5 () ;
struct V_11 * V_20 = F_7 ( V_24 ) ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_3 ,
V_19 -> V_20 -> V_17 , V_20 -> V_17 , V_15 ,
V_21 -> V_22 , V_24 -> V_22 ) ;
return 0 ;
}
static int F_8 ( struct V_25 * V_25 , int V_1 , int V_14 )
{
struct V_18 * V_19 = F_5 () ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_4 ,
V_19 -> V_20 -> V_17 , F_9 ( V_25 ) -> V_17 , V_15 ,
V_25 -> V_26 -> V_27 , V_25 -> V_28 , V_21 -> V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_29 * V_29 , int V_1 , int V_14 )
{
struct V_18 * V_19 = F_5 () ;
struct V_11 * V_12 = V_19 -> V_20 ;
struct V_25 * V_25 = F_11 ( V_29 ) ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_5 ,
V_12 -> V_17 , F_9 ( V_25 ) -> V_17 , V_15 ,
V_25 -> V_26 -> V_27 , V_25 -> V_28 , V_29 ,
V_21 -> V_22 ) ;
return 0 ;
}
static int F_12 ( const struct V_30 * V_30 , struct V_29 * V_29 ,
int V_1 , int V_14 )
{
struct V_18 * V_19 = V_30 -> V_31 ;
struct V_11 * V_12 = V_19 -> V_20 ;
struct V_25 * V_25 = V_29 -> V_32 ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_5 ,
V_12 -> V_17 , F_9 ( V_25 ) -> V_17 , V_15 ,
V_25 -> V_26 -> V_27 , V_25 -> V_28 , V_29 ,
V_21 -> V_22 ) ;
return 0 ;
}
static struct V_11 * F_13 ( const char * V_33 , struct V_25 * V_34 ,
struct V_35 * V_36 )
{
int V_14 ;
char * V_37 ;
struct V_11 * V_38 = NULL ;
if ( V_34 -> V_39 -> V_40 == NULL )
return NULL ;
V_37 = F_14 ( V_41 , V_42 ) ;
if ( V_37 == NULL )
return NULL ;
V_14 = V_34 -> V_39 -> V_40 ( V_36 , V_33 , V_37 , V_41 ) ;
if ( V_14 > 0 )
V_38 = F_15 ( V_37 , V_14 ) ;
F_16 ( V_37 ) ;
return V_38 ;
}
struct V_43 * F_17 ( struct V_11 * V_38 )
{
struct V_43 * V_44 ;
V_44 = F_18 ( V_45 , V_46 ) ;
if ( V_44 == NULL )
return NULL ;
V_44 -> V_47 = V_38 ;
V_44 -> V_48 = 0 ;
F_19 ( & V_44 -> V_49 ) ;
return V_44 ;
}
static struct V_18 * F_20 ( struct V_11 * V_50 ,
struct V_11 * V_51 , T_1 V_52 )
{
struct V_18 * V_19 ;
V_19 = F_14 ( sizeof( struct V_18 ) , V_52 ) ;
if ( V_19 == NULL )
return NULL ;
V_19 -> V_20 = V_50 ;
V_19 -> V_53 = V_51 ;
F_21 ( & V_19 -> V_54 ) ;
F_19 ( & V_19 -> V_55 ) ;
return V_19 ;
}
static int F_22 ( struct V_56 * V_57 , struct V_56 * V_58 ,
T_1 V_52 )
{
struct V_59 * V_60 ;
struct V_59 * V_61 ;
int V_14 = 0 ;
F_21 ( V_57 ) ;
F_23 (orp, ohead, list) {
V_60 = F_14 ( sizeof( struct V_59 ) , V_52 ) ;
if ( V_60 == NULL ) {
V_14 = - V_62 ;
break;
}
* V_60 = * V_61 ;
F_24 ( & V_60 -> V_63 , V_57 ) ;
}
return V_14 ;
}
static inline unsigned int F_25 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_64 :
return V_4 ;
case V_65 :
return V_66 ;
}
return 0 ;
}
static int F_26 ( struct V_23 * V_67 ,
struct V_11 * V_68 ,
unsigned int V_1 , const char * V_69 )
{
int V_14 ;
struct V_70 V_71 , * V_72 = NULL ;
struct V_18 * V_19 ;
struct V_11 * V_73 ;
if ( ( V_1 & V_74 ) == 0 ) {
F_27 ( & V_71 , V_69 , V_75 ) ;
F_28 ( & V_71 , V_67 ) ;
V_72 = & V_71 ;
}
F_29 () ;
V_19 = F_30 ( V_67 ) -> V_31 ;
V_73 = F_31 ( V_19 ) ;
if ( ( V_1 & V_65 ) &&
( V_76 == V_77 ||
V_76 == V_78 ) ) {
if ( V_73 -> V_17 == V_68 -> V_17 )
V_14 = 0 ;
else if ( V_76 == V_78 )
V_14 = - V_79 ;
else if ( F_32 ( V_80 ) )
V_14 = 0 ;
else
V_14 = - V_79 ;
if ( V_72 )
F_33 ( V_73 -> V_17 ,
V_68 -> V_17 ,
0 , V_14 , V_72 ) ;
F_34 () ;
return V_14 ;
}
V_14 = F_35 ( V_19 , V_68 , F_25 ( V_1 ) , V_72 ) ;
F_34 () ;
return V_14 ;
}
static int F_36 ( struct V_23 * V_81 , unsigned int V_1 )
{
int V_14 ;
struct V_11 * V_38 ;
V_14 = F_37 ( V_81 , V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
V_38 = F_7 ( V_81 ) ;
V_14 = F_26 ( V_21 , V_38 , V_1 , V_82 ) ;
return V_14 ;
}
static int F_38 ( struct V_23 * V_83 )
{
int V_14 ;
struct V_11 * V_38 ;
V_14 = F_39 ( V_83 ) ;
if ( V_14 != 0 )
return V_14 ;
V_38 = F_31 ( F_5 () ) ;
V_14 = F_26 ( V_83 , V_38 , V_65 , V_82 ) ;
return V_14 ;
}
static int F_40 ( int V_84 )
{
int V_14 = 0 ;
struct V_11 * V_38 = F_41 () ;
if ( F_42 ( V_85 ) )
return 0 ;
if ( V_86 != NULL && V_86 != V_38 )
V_14 = - V_79 ;
return V_14 ;
}
static int F_43 ( struct V_87 * V_88 )
{
struct V_89 * V_90 ;
V_90 = F_14 ( sizeof( struct V_89 ) , V_42 ) ;
if ( V_90 == NULL )
return - V_62 ;
V_90 -> V_91 = & V_92 ;
V_90 -> V_93 = & V_92 ;
V_90 -> V_94 = & V_92 ;
V_90 -> V_95 = & V_96 ;
V_88 -> V_97 = V_90 ;
return 0 ;
}
static void F_44 ( struct V_87 * V_88 )
{
F_16 ( V_88 -> V_97 ) ;
V_88 -> V_97 = NULL ;
}
static int F_45 ( char * V_98 , char * V_99 )
{
char * V_100 , * V_101 , * V_102 , * V_36 ;
V_102 = ( char * ) F_46 ( V_42 ) ;
if ( V_102 == NULL )
return - V_62 ;
for ( V_100 = V_98 , V_101 = V_98 ; V_101 != NULL ; V_100 = V_101 + 1 ) {
if ( strstr ( V_100 , V_103 ) == V_100 )
V_36 = V_99 ;
else if ( strstr ( V_100 , V_104 ) == V_100 )
V_36 = V_99 ;
else if ( strstr ( V_100 , V_105 ) == V_100 )
V_36 = V_99 ;
else if ( strstr ( V_100 , V_106 ) == V_100 )
V_36 = V_99 ;
else if ( strstr ( V_100 , V_107 ) == V_100 )
V_36 = V_99 ;
else
V_36 = V_102 ;
V_101 = strchr ( V_100 , ',' ) ;
if ( V_101 != NULL )
* V_101 = '\0' ;
if ( * V_36 != '\0' )
strcat ( V_36 , L_6 ) ;
strcat ( V_36 , V_100 ) ;
}
strcpy ( V_98 , V_102 ) ;
F_47 ( ( unsigned long ) V_102 ) ;
return 0 ;
}
static int F_48 ( struct V_87 * V_88 , int V_108 , void * V_109 )
{
struct V_35 * V_110 = V_88 -> V_111 ;
struct V_25 * V_25 = V_110 -> V_112 ;
struct V_89 * V_113 = V_88 -> V_97 ;
struct V_43 * V_44 ;
struct V_11 * V_38 ;
char * V_114 ;
char * V_101 ;
int V_115 = 0 ;
int V_116 = 0 ;
if ( V_113 -> V_117 )
return 0 ;
V_113 -> V_117 = 1 ;
for ( V_114 = V_109 ; V_114 != NULL ; V_114 = V_101 ) {
V_101 = strchr ( V_114 , ',' ) ;
if ( V_101 != NULL )
* V_101 ++ = '\0' ;
if ( strncmp ( V_114 , V_105 , strlen ( V_105 ) ) == 0 ) {
V_114 += strlen ( V_105 ) ;
V_38 = F_15 ( V_114 , 0 ) ;
if ( V_38 != NULL ) {
V_113 -> V_95 = V_38 ;
V_116 = 1 ;
}
} else if ( strncmp ( V_114 , V_104 , strlen ( V_104 ) ) == 0 ) {
V_114 += strlen ( V_104 ) ;
V_38 = F_15 ( V_114 , 0 ) ;
if ( V_38 != NULL ) {
V_113 -> V_94 = V_38 ;
V_116 = 1 ;
}
} else if ( strncmp ( V_114 , V_103 ,
strlen ( V_103 ) ) == 0 ) {
V_114 += strlen ( V_103 ) ;
V_38 = F_15 ( V_114 , 0 ) ;
if ( V_38 != NULL ) {
V_113 -> V_93 = V_38 ;
V_116 = 1 ;
}
} else if ( strncmp ( V_114 , V_106 , strlen ( V_106 ) ) == 0 ) {
V_114 += strlen ( V_106 ) ;
V_38 = F_15 ( V_114 , 0 ) ;
if ( V_38 != NULL ) {
V_113 -> V_91 = V_38 ;
V_116 = 1 ;
}
} else if ( strncmp ( V_114 , V_107 , strlen ( V_107 ) ) == 0 ) {
V_114 += strlen ( V_107 ) ;
V_38 = F_15 ( V_114 , 0 ) ;
if ( V_38 != NULL ) {
V_113 -> V_91 = V_38 ;
V_115 = 1 ;
V_116 = 1 ;
}
}
}
if ( ! F_42 ( V_118 ) ) {
if ( V_116 )
return - V_119 ;
V_38 = F_41 () ;
V_113 -> V_91 = V_38 ;
V_113 -> V_93 = V_38 ;
}
V_44 = V_25 -> V_120 ;
if ( V_44 == NULL ) {
V_44 = F_17 ( V_113 -> V_91 ) ;
if ( V_44 == NULL )
return - V_62 ;
V_25 -> V_120 = V_44 ;
} else
V_44 -> V_47 = V_113 -> V_91 ;
if ( V_115 )
V_44 -> V_48 |= V_121 ;
return 0 ;
}
static int F_49 ( struct V_35 * V_35 )
{
struct V_89 * V_122 = V_35 -> V_123 -> V_97 ;
int V_14 ;
struct V_70 V_71 ;
F_27 ( & V_71 , V_82 , V_124 ) ;
F_50 ( & V_71 , V_35 ) ;
V_14 = F_51 ( V_122 -> V_94 , V_4 , & V_71 ) ;
V_14 = F_4 ( L_7 , V_122 -> V_94 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_52 ( struct V_125 * V_126 )
{
struct V_25 * V_25 = F_11 ( V_126 -> V_29 ) ;
struct V_18 * V_127 = V_126 -> V_30 -> V_31 ;
struct V_43 * V_44 ;
int V_14 ;
V_14 = F_53 ( V_126 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( V_126 -> V_128 )
return 0 ;
V_44 = V_25 -> V_120 ;
if ( V_44 -> V_20 == NULL || V_44 -> V_20 == V_127 -> V_20 )
return 0 ;
if ( V_126 -> V_129 & ( V_130 | V_131 ) ) {
struct V_23 * V_67 ;
V_14 = 0 ;
F_29 () ;
V_67 = F_54 ( V_21 ) ;
if ( F_55 ( V_67 != NULL ) )
V_14 = F_26 ( V_67 ,
V_44 -> V_20 ,
V_65 ,
V_82 ) ;
F_34 () ;
if ( V_14 != 0 )
return V_14 ;
} else if ( V_126 -> V_129 )
return - V_119 ;
V_127 -> V_20 = V_44 -> V_20 ;
V_126 -> V_132 |= V_133 ;
return 0 ;
}
static void F_56 ( struct V_125 * V_126 )
{
struct V_18 * V_127 = V_126 -> V_30 -> V_31 ;
if ( V_127 -> V_20 != V_127 -> V_53 )
V_21 -> V_134 = 0 ;
}
static int F_57 ( struct V_125 * V_126 )
{
struct V_18 * V_19 = F_5 () ;
int V_135 = F_58 ( V_126 ) ;
if ( ! V_135 && ( V_19 -> V_20 != V_19 -> V_53 ) )
V_135 = 1 ;
return V_135 ;
}
static int F_59 ( struct V_25 * V_25 )
{
struct V_11 * V_38 = F_41 () ;
V_25 -> V_120 = F_17 ( V_38 ) ;
if ( V_25 -> V_120 == NULL )
return - V_62 ;
return 0 ;
}
static void F_60 ( struct V_25 * V_25 )
{
F_61 ( V_45 , V_25 -> V_120 ) ;
V_25 -> V_120 = NULL ;
}
static int F_62 ( struct V_25 * V_25 , struct V_25 * V_136 ,
const struct V_137 * V_137 , const char * * V_33 ,
void * * V_138 , T_2 * V_139 )
{
struct V_43 * V_140 = V_25 -> V_120 ;
struct V_11 * V_38 = F_41 () ;
struct V_11 * V_44 = F_9 ( V_25 ) ;
struct V_11 * V_141 = F_9 ( V_136 ) ;
int V_142 ;
if ( V_33 )
* V_33 = V_143 ;
if ( V_138 && V_139 ) {
F_29 () ;
V_142 = F_63 ( V_38 -> V_17 , V_141 -> V_17 ,
& V_38 -> V_54 ) ;
F_34 () ;
if ( V_142 > 0 && ( ( V_142 & V_8 ) != 0 ) &&
F_64 ( V_136 ) ) {
V_44 = V_141 ;
V_140 -> V_48 |= V_144 ;
}
* V_138 = F_65 ( V_44 -> V_17 , V_46 ) ;
if ( * V_138 == NULL )
return - V_62 ;
* V_139 = strlen ( V_44 -> V_17 ) ;
}
return 0 ;
}
static int F_66 ( struct V_35 * V_145 , struct V_25 * V_136 ,
struct V_35 * V_146 )
{
struct V_11 * V_44 ;
struct V_70 V_71 ;
int V_14 ;
F_27 ( & V_71 , V_82 , V_124 ) ;
F_50 ( & V_71 , V_145 ) ;
V_44 = F_9 ( V_145 -> V_112 ) ;
V_14 = F_51 ( V_44 , V_5 , & V_71 ) ;
V_14 = F_8 ( V_145 -> V_112 , V_5 , V_14 ) ;
if ( V_14 == 0 && F_67 ( V_146 ) ) {
V_44 = F_9 ( V_146 -> V_112 ) ;
F_50 ( & V_71 , V_146 ) ;
V_14 = F_51 ( V_44 , V_5 , & V_71 ) ;
V_14 = F_8 ( V_146 -> V_112 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_68 ( struct V_25 * V_136 , struct V_35 * V_35 )
{
struct V_25 * V_34 = V_35 -> V_112 ;
struct V_70 V_71 ;
int V_14 ;
F_27 ( & V_71 , V_82 , V_124 ) ;
F_50 ( & V_71 , V_35 ) ;
V_14 = F_51 ( F_9 ( V_34 ) , V_5 , & V_71 ) ;
V_14 = F_8 ( V_34 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_27 ( & V_71 , V_82 , V_147 ) ;
F_69 ( & V_71 , V_136 ) ;
V_14 = F_51 ( F_9 ( V_136 ) , V_5 , & V_71 ) ;
V_14 = F_8 ( V_136 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_70 ( struct V_25 * V_136 , struct V_35 * V_35 )
{
struct V_70 V_71 ;
int V_14 ;
F_27 ( & V_71 , V_82 , V_124 ) ;
F_50 ( & V_71 , V_35 ) ;
V_14 = F_51 ( F_9 ( V_35 -> V_112 ) , V_5 , & V_71 ) ;
V_14 = F_8 ( V_35 -> V_112 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_27 ( & V_71 , V_82 , V_147 ) ;
F_69 ( & V_71 , V_136 ) ;
V_14 = F_51 ( F_9 ( V_136 ) , V_5 , & V_71 ) ;
V_14 = F_8 ( V_136 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_71 ( struct V_25 * V_148 ,
struct V_35 * V_145 ,
struct V_25 * V_149 ,
struct V_35 * V_146 )
{
int V_14 ;
struct V_11 * V_44 ;
struct V_70 V_71 ;
F_27 ( & V_71 , V_82 , V_124 ) ;
F_50 ( & V_71 , V_145 ) ;
V_44 = F_9 ( V_145 -> V_112 ) ;
V_14 = F_51 ( V_44 , V_66 , & V_71 ) ;
V_14 = F_8 ( V_145 -> V_112 , V_66 , V_14 ) ;
if ( V_14 == 0 && F_67 ( V_146 ) ) {
V_44 = F_9 ( V_146 -> V_112 ) ;
F_50 ( & V_71 , V_146 ) ;
V_14 = F_51 ( V_44 , V_66 , & V_71 ) ;
V_14 = F_8 ( V_146 -> V_112 , V_66 , V_14 ) ;
}
return V_14 ;
}
static int F_72 ( struct V_25 * V_25 , int V_150 )
{
struct V_70 V_71 ;
int V_151 = V_150 & V_152 ;
int V_14 ;
V_150 &= ( V_4 | V_5 | V_6 | V_7 ) ;
if ( V_150 == 0 )
return 0 ;
if ( V_151 )
return - V_153 ;
F_27 ( & V_71 , V_82 , V_147 ) ;
F_69 ( & V_71 , V_25 ) ;
V_14 = F_51 ( F_9 ( V_25 ) , V_150 , & V_71 ) ;
V_14 = F_8 ( V_25 , V_150 , V_14 ) ;
return V_14 ;
}
static int F_73 ( struct V_35 * V_35 , struct V_154 * V_154 )
{
struct V_70 V_71 ;
int V_14 ;
if ( V_154 -> V_155 & V_156 )
return 0 ;
F_27 ( & V_71 , V_82 , V_124 ) ;
F_50 ( & V_71 , V_35 ) ;
V_14 = F_51 ( F_9 ( V_35 -> V_112 ) , V_5 , & V_71 ) ;
V_14 = F_8 ( V_35 -> V_112 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_74 ( struct V_157 * V_158 , struct V_35 * V_35 )
{
struct V_70 V_71 ;
struct V_159 V_159 ;
int V_14 ;
V_159 . V_35 = V_35 ;
V_159 . V_158 = V_158 ;
F_27 ( & V_71 , V_82 , V_160 ) ;
F_75 ( & V_71 , V_159 ) ;
V_14 = F_51 ( F_9 ( V_35 -> V_112 ) , V_4 , & V_71 ) ;
V_14 = F_8 ( V_35 -> V_112 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_76 ( struct V_35 * V_35 , const char * V_33 ,
const void * V_138 , T_2 V_161 , int V_108 )
{
struct V_70 V_71 ;
struct V_11 * V_38 ;
int V_162 = 0 ;
int V_163 = 0 ;
int V_164 = 0 ;
int V_14 = 0 ;
if ( strcmp ( V_33 , V_165 ) == 0 ||
strcmp ( V_33 , V_166 ) == 0 ||
strcmp ( V_33 , V_167 ) == 0 ) {
V_162 = 1 ;
V_163 = 1 ;
} else if ( strcmp ( V_33 , V_168 ) == 0 ||
strcmp ( V_33 , V_169 ) == 0 ) {
V_162 = 1 ;
V_163 = 1 ;
V_164 = 1 ;
} else if ( strcmp ( V_33 , V_170 ) == 0 ) {
V_162 = 1 ;
if ( V_161 != V_171 ||
strncmp ( V_138 , V_172 , V_171 ) != 0 )
V_14 = - V_173 ;
} else
V_14 = F_77 ( V_35 , V_33 , V_138 , V_161 , V_108 ) ;
if ( V_162 && ! F_42 ( V_118 ) )
V_14 = - V_119 ;
if ( V_14 == 0 && V_163 ) {
V_38 = V_161 ? F_15 ( V_138 , V_161 ) : NULL ;
if ( V_38 == NULL || ( V_164 &&
( V_38 == & V_174 || V_38 == & V_175 ) ) )
V_14 = - V_173 ;
}
F_27 ( & V_71 , V_82 , V_124 ) ;
F_50 ( & V_71 , V_35 ) ;
if ( V_14 == 0 ) {
V_14 = F_51 ( F_9 ( V_35 -> V_112 ) , V_5 , & V_71 ) ;
V_14 = F_8 ( V_35 -> V_112 , V_5 , V_14 ) ;
}
return V_14 ;
}
static void F_78 ( struct V_35 * V_35 , const char * V_33 ,
const void * V_138 , T_2 V_161 , int V_108 )
{
struct V_11 * V_38 ;
struct V_43 * V_44 = V_35 -> V_112 -> V_120 ;
if ( strcmp ( V_33 , V_170 ) == 0 ) {
V_44 -> V_48 |= V_121 ;
return;
}
if ( strcmp ( V_33 , V_165 ) == 0 ) {
V_38 = F_15 ( V_138 , V_161 ) ;
if ( V_38 != NULL )
V_44 -> V_47 = V_38 ;
else
V_44 -> V_47 = & V_176 ;
} else if ( strcmp ( V_33 , V_168 ) == 0 ) {
V_38 = F_15 ( V_138 , V_161 ) ;
if ( V_38 != NULL )
V_44 -> V_20 = V_38 ;
else
V_44 -> V_20 = & V_176 ;
} else if ( strcmp ( V_33 , V_169 ) == 0 ) {
V_38 = F_15 ( V_138 , V_161 ) ;
if ( V_38 != NULL )
V_44 -> V_177 = V_38 ;
else
V_44 -> V_177 = & V_176 ;
}
return;
}
static int F_79 ( struct V_35 * V_35 , const char * V_33 )
{
struct V_70 V_71 ;
int V_14 ;
F_27 ( & V_71 , V_82 , V_124 ) ;
F_50 ( & V_71 , V_35 ) ;
V_14 = F_51 ( F_9 ( V_35 -> V_112 ) , V_4 , & V_71 ) ;
V_14 = F_8 ( V_35 -> V_112 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_80 ( struct V_35 * V_35 , const char * V_33 )
{
struct V_43 * V_44 ;
struct V_70 V_71 ;
int V_14 = 0 ;
if ( strcmp ( V_33 , V_165 ) == 0 ||
strcmp ( V_33 , V_166 ) == 0 ||
strcmp ( V_33 , V_167 ) == 0 ||
strcmp ( V_33 , V_168 ) == 0 ||
strcmp ( V_33 , V_170 ) == 0 ||
strcmp ( V_33 , V_169 ) == 0 ) {
if ( ! F_42 ( V_118 ) )
V_14 = - V_119 ;
} else
V_14 = F_81 ( V_35 , V_33 ) ;
if ( V_14 != 0 )
return V_14 ;
F_27 ( & V_71 , V_82 , V_124 ) ;
F_50 ( & V_71 , V_35 ) ;
V_14 = F_51 ( F_9 ( V_35 -> V_112 ) , V_5 , & V_71 ) ;
V_14 = F_8 ( V_35 -> V_112 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_44 = V_35 -> V_112 -> V_120 ;
if ( strcmp ( V_33 , V_165 ) == 0 )
V_44 -> V_20 = NULL ;
else if ( strcmp ( V_33 , V_169 ) == 0 )
V_44 -> V_177 = NULL ;
else if ( strcmp ( V_33 , V_170 ) == 0 )
V_44 -> V_48 &= ~ V_121 ;
return 0 ;
}
static int F_82 ( const struct V_25 * V_25 ,
const char * V_33 , void * * V_37 ,
bool V_178 )
{
struct V_179 * V_180 ;
struct V_181 * V_182 ;
struct V_87 * V_122 ;
struct V_25 * V_34 = (struct V_25 * ) V_25 ;
struct V_11 * V_44 ;
int V_183 ;
int V_14 = 0 ;
if ( strcmp ( V_33 , V_143 ) == 0 ) {
V_44 = F_9 ( V_25 ) ;
V_183 = strlen ( V_44 -> V_17 ) ;
* V_37 = V_44 -> V_17 ;
return V_183 ;
}
V_122 = V_34 -> V_26 ;
if ( V_122 -> V_184 != V_185 )
return - V_186 ;
V_182 = F_83 ( V_34 ) ;
if ( V_182 == NULL || V_182 -> V_187 == NULL )
return - V_186 ;
V_180 = V_182 -> V_187 -> V_188 ;
if ( strcmp ( V_33 , V_189 ) == 0 )
V_44 = V_180 -> V_190 ;
else if ( strcmp ( V_33 , V_191 ) == 0 )
V_44 = V_180 -> V_192 ;
else
return - V_186 ;
V_183 = strlen ( V_44 -> V_17 ) ;
if ( V_14 == 0 ) {
* V_37 = V_44 -> V_17 ;
V_14 = V_183 ;
}
return V_14 ;
}
static int F_84 ( struct V_25 * V_25 , char * V_37 ,
T_2 V_193 )
{
int V_139 = sizeof( V_165 ) ;
if ( V_37 != NULL && V_139 <= V_193 )
memcpy ( V_37 , V_165 , V_139 ) ;
return V_139 ;
}
static void F_85 ( const struct V_25 * V_25 , T_3 * V_194 )
{
struct V_43 * V_44 = V_25 -> V_120 ;
* V_194 = V_44 -> V_47 -> V_195 ;
}
static int F_86 ( struct V_29 * V_29 , int V_150 )
{
return 0 ;
}
static int F_87 ( struct V_29 * V_29 )
{
struct V_11 * V_38 = F_41 () ;
V_29 -> V_196 = V_38 ;
return 0 ;
}
static void F_88 ( struct V_29 * V_29 )
{
V_29 -> V_196 = NULL ;
}
static int F_89 ( struct V_29 * V_29 , unsigned int V_197 ,
unsigned long V_198 )
{
int V_14 = 0 ;
struct V_70 V_71 ;
struct V_25 * V_25 = F_11 ( V_29 ) ;
F_27 ( & V_71 , V_82 , V_160 ) ;
F_75 ( & V_71 , V_29 -> V_199 ) ;
if ( F_90 ( V_197 ) & V_200 ) {
V_14 = F_51 ( F_9 ( V_25 ) , V_5 , & V_71 ) ;
V_14 = F_10 ( V_29 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_90 ( V_197 ) & V_201 ) ) {
V_14 = F_51 ( F_9 ( V_25 ) , V_4 , & V_71 ) ;
V_14 = F_10 ( V_29 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_91 ( struct V_29 * V_29 , unsigned int V_197 )
{
struct V_70 V_71 ;
int V_14 ;
struct V_25 * V_25 = F_11 ( V_29 ) ;
F_27 ( & V_71 , V_82 , V_160 ) ;
F_75 ( & V_71 , V_29 -> V_199 ) ;
V_14 = F_51 ( F_9 ( V_25 ) , V_9 , & V_71 ) ;
V_14 = F_10 ( V_29 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_92 ( struct V_29 * V_29 , unsigned int V_197 ,
unsigned long V_198 )
{
struct V_70 V_71 ;
int V_14 = 0 ;
struct V_25 * V_25 = F_11 ( V_29 ) ;
switch ( V_197 ) {
case V_202 :
break;
case V_203 :
case V_204 :
F_27 ( & V_71 , V_82 , V_160 ) ;
F_75 ( & V_71 , V_29 -> V_199 ) ;
V_14 = F_51 ( F_9 ( V_25 ) , V_9 , & V_71 ) ;
V_14 = F_10 ( V_29 , V_9 , V_14 ) ;
break;
case V_205 :
case V_206 :
F_27 ( & V_71 , V_82 , V_160 ) ;
F_75 ( & V_71 , V_29 -> V_199 ) ;
V_14 = F_51 ( F_9 ( V_25 ) , V_5 , & V_71 ) ;
V_14 = F_10 ( V_29 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_93 ( struct V_29 * V_29 ,
unsigned long V_207 , unsigned long V_208 ,
unsigned long V_108 )
{
struct V_11 * V_38 ;
struct V_11 * V_209 ;
struct V_59 * V_210 ;
struct V_18 * V_19 ;
struct V_11 * V_211 ;
struct V_43 * V_44 ;
int V_142 ;
int V_212 ;
int V_213 ;
int V_14 ;
if ( V_29 == NULL )
return 0 ;
V_44 = F_11 ( V_29 ) -> V_120 ;
if ( V_44 -> V_177 == NULL )
return 0 ;
V_209 = V_44 -> V_177 ;
V_19 = F_5 () ;
V_38 = F_41 () ;
V_14 = 0 ;
F_29 () ;
F_23 (srp, &skp->smk_rules, list) {
V_211 = V_210 -> V_214 ;
if ( V_209 -> V_17 == V_211 -> V_17 )
continue;
V_142 = F_63 ( V_210 -> V_215 -> V_17 ,
V_211 -> V_17 ,
& V_19 -> V_54 ) ;
if ( V_142 == - V_216 )
V_142 = V_210 -> V_217 ;
else
V_142 &= V_210 -> V_217 ;
if ( V_142 == 0 )
continue;
V_212 = F_63 ( V_209 -> V_17 , V_211 -> V_17 ,
& V_209 -> V_54 ) ;
if ( V_212 == - V_216 ) {
V_14 = - V_79 ;
break;
}
V_213 = F_63 ( V_209 -> V_17 , V_211 -> V_17 ,
& V_19 -> V_54 ) ;
if ( V_213 != - V_216 )
V_212 &= V_213 ;
if ( ( V_142 | V_212 ) != V_212 ) {
V_14 = - V_79 ;
break;
}
}
F_34 () ;
return V_14 ;
}
static void F_94 ( struct V_29 * V_29 )
{
V_29 -> V_196 = F_41 () ;
}
static int F_95 ( struct V_23 * V_218 ,
struct V_219 * V_220 , int V_221 )
{
struct V_11 * V_38 ;
struct V_11 * V_222 = F_31 ( V_218 -> V_30 -> V_31 ) ;
struct V_29 * V_29 ;
int V_14 ;
struct V_70 V_71 ;
V_29 = F_96 ( V_220 , struct V_29 , V_223 ) ;
V_38 = V_29 -> V_196 ;
V_14 = V_217 ( V_38 , V_222 , V_5 , NULL ) ;
V_14 = F_2 ( L_8 , V_38 , V_222 , V_5 , V_14 ) ;
if ( V_14 != 0 && F_97 ( V_218 , V_85 ) )
V_14 = 0 ;
F_27 ( & V_71 , V_82 , V_75 ) ;
F_28 ( & V_71 , V_218 ) ;
F_33 ( V_38 -> V_17 , V_222 -> V_17 , V_5 , V_14 , & V_71 ) ;
return V_14 ;
}
static int F_98 ( struct V_29 * V_29 )
{
int V_14 ;
int V_142 = 0 ;
struct V_70 V_71 ;
struct V_25 * V_25 = F_11 ( V_29 ) ;
F_27 ( & V_71 , V_82 , V_160 ) ;
F_75 ( & V_71 , V_29 -> V_199 ) ;
if ( V_29 -> V_224 & V_225 )
V_142 = V_4 ;
if ( V_29 -> V_224 & V_226 )
V_142 |= V_5 ;
V_14 = F_51 ( F_9 ( V_25 ) , V_142 , & V_71 ) ;
V_14 = F_10 ( V_29 , V_142 , V_14 ) ;
return V_14 ;
}
static int F_99 ( struct V_29 * V_29 , const struct V_30 * V_30 )
{
struct V_18 * V_19 = V_30 -> V_31 ;
struct V_25 * V_25 = F_11 ( V_29 ) ;
struct V_70 V_71 ;
int V_14 ;
if ( F_42 ( V_85 ) )
return 0 ;
F_27 ( & V_71 , V_82 , V_160 ) ;
F_75 ( & V_71 , V_29 -> V_199 ) ;
V_14 = V_217 ( V_19 -> V_20 , F_9 ( V_25 ) , V_4 , & V_71 ) ;
V_14 = F_12 ( V_30 , V_29 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_100 ( struct V_30 * V_30 , T_1 V_52 )
{
struct V_18 * V_19 ;
V_19 = F_20 ( NULL , NULL , V_52 ) ;
if ( V_19 == NULL )
return - V_62 ;
V_30 -> V_31 = V_19 ;
return 0 ;
}
static void F_101 ( struct V_30 * V_30 )
{
struct V_18 * V_19 = V_30 -> V_31 ;
struct V_59 * V_227 ;
struct V_56 * V_228 ;
struct V_56 * V_229 ;
if ( V_19 == NULL )
return;
V_30 -> V_31 = NULL ;
F_102 (l, n, &tsp->smk_rules) {
V_227 = F_103 ( V_228 , struct V_59 , V_63 ) ;
F_104 ( & V_227 -> V_63 ) ;
F_16 ( V_227 ) ;
}
F_16 ( V_19 ) ;
}
static int F_105 ( struct V_30 * V_230 , const struct V_30 * V_231 ,
T_1 V_52 )
{
struct V_18 * V_232 = V_231 -> V_31 ;
struct V_18 * V_233 ;
int V_14 ;
V_233 = F_20 ( V_232 -> V_20 , V_232 -> V_20 , V_52 ) ;
if ( V_233 == NULL )
return - V_62 ;
V_14 = F_22 ( & V_233 -> V_54 , & V_232 -> V_54 , V_52 ) ;
if ( V_14 != 0 )
return V_14 ;
V_230 -> V_31 = V_233 ;
return 0 ;
}
static void F_106 ( struct V_30 * V_230 , const struct V_30 * V_231 )
{
struct V_18 * V_232 = V_231 -> V_31 ;
struct V_18 * V_233 = V_230 -> V_31 ;
V_233 -> V_20 = V_232 -> V_20 ;
V_233 -> V_53 = V_232 -> V_20 ;
F_19 ( & V_233 -> V_55 ) ;
F_21 ( & V_233 -> V_54 ) ;
}
static int F_107 ( struct V_30 * V_230 , T_3 V_194 )
{
struct V_18 * V_233 = V_230 -> V_31 ;
struct V_11 * V_38 = F_108 ( V_194 ) ;
if ( V_38 == NULL )
return - V_173 ;
V_233 -> V_20 = V_38 ;
return 0 ;
}
static int F_109 ( struct V_30 * V_230 ,
struct V_25 * V_25 )
{
struct V_43 * V_44 = V_25 -> V_120 ;
struct V_18 * V_19 = V_230 -> V_31 ;
V_19 -> V_53 = V_44 -> V_47 ;
V_19 -> V_20 = V_19 -> V_53 ;
return 0 ;
}
static int F_110 ( struct V_23 * V_234 , int V_235 ,
const char * V_236 )
{
struct V_70 V_71 ;
struct V_11 * V_38 = F_7 ( V_234 ) ;
int V_14 ;
F_27 ( & V_71 , V_236 , V_75 ) ;
F_28 ( & V_71 , V_234 ) ;
V_14 = F_51 ( V_38 , V_235 , & V_71 ) ;
V_14 = F_6 ( V_234 , V_235 , V_14 ) ;
return V_14 ;
}
static int F_111 ( struct V_23 * V_234 , T_4 V_237 )
{
return F_110 ( V_234 , V_5 , V_82 ) ;
}
static int F_112 ( struct V_23 * V_234 )
{
return F_110 ( V_234 , V_4 , V_82 ) ;
}
static int F_113 ( struct V_23 * V_234 )
{
return F_110 ( V_234 , V_4 , V_82 ) ;
}
static void F_114 ( struct V_23 * V_234 , T_3 * V_194 )
{
struct V_11 * V_38 = F_7 ( V_234 ) ;
* V_194 = V_38 -> V_195 ;
}
static int F_115 ( struct V_23 * V_234 , int V_238 )
{
int V_14 ;
V_14 = F_116 ( V_234 , V_238 ) ;
if ( V_14 == 0 )
V_14 = F_110 ( V_234 , V_5 , V_82 ) ;
return V_14 ;
}
static int F_117 ( struct V_23 * V_234 , int V_239 )
{
int V_14 ;
V_14 = F_118 ( V_234 , V_239 ) ;
if ( V_14 == 0 )
V_14 = F_110 ( V_234 , V_5 , V_82 ) ;
return V_14 ;
}
static int F_119 ( struct V_23 * V_234 )
{
return F_110 ( V_234 , V_4 , V_82 ) ;
}
static int F_120 ( struct V_23 * V_234 )
{
int V_14 ;
V_14 = F_121 ( V_234 ) ;
if ( V_14 == 0 )
V_14 = F_110 ( V_234 , V_5 , V_82 ) ;
return V_14 ;
}
static int F_122 ( struct V_23 * V_234 )
{
return F_110 ( V_234 , V_4 , V_82 ) ;
}
static int F_123 ( struct V_23 * V_234 )
{
return F_110 ( V_234 , V_5 , V_82 ) ;
}
static int F_124 ( struct V_23 * V_234 , struct V_240 * V_241 ,
int V_242 , T_3 V_194 )
{
struct V_70 V_71 ;
struct V_11 * V_38 ;
struct V_11 * V_222 = F_7 ( V_234 ) ;
int V_14 ;
F_27 ( & V_71 , V_82 , V_75 ) ;
F_28 ( & V_71 , V_234 ) ;
if ( V_194 == 0 ) {
V_14 = F_51 ( V_222 , V_5 , & V_71 ) ;
V_14 = F_6 ( V_234 , V_5 , V_14 ) ;
return V_14 ;
}
V_38 = F_108 ( V_194 ) ;
V_14 = V_217 ( V_38 , V_222 , V_5 , & V_71 ) ;
V_14 = F_2 ( L_9 , V_38 , V_222 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_125 ( struct V_23 * V_234 )
{
return 0 ;
}
static void F_126 ( struct V_23 * V_234 , struct V_25 * V_25 )
{
struct V_43 * V_44 = V_25 -> V_120 ;
struct V_11 * V_38 = F_7 ( V_234 ) ;
V_44 -> V_47 = V_38 ;
}
static int F_127 ( struct V_182 * V_187 , int V_243 , T_1 V_244 )
{
struct V_11 * V_38 = F_41 () ;
struct V_179 * V_180 ;
V_180 = F_14 ( sizeof( struct V_179 ) , V_244 ) ;
if ( V_180 == NULL )
return - V_62 ;
V_180 -> V_190 = V_38 ;
V_180 -> V_192 = V_38 ;
V_180 -> V_245 = NULL ;
V_187 -> V_188 = V_180 ;
return 0 ;
}
static void F_128 ( struct V_182 * V_187 )
{
F_16 ( V_187 -> V_188 ) ;
}
static struct V_11 * F_129 ( struct V_246 * V_247 )
{
struct V_248 * V_249 ;
struct V_250 * V_251 = & V_247 -> V_252 ;
if ( V_251 -> V_253 == 0 )
return NULL ;
F_23 (snp, &smk_netlbladdr_list, list)
if ( ( & V_249 -> V_254 . V_252 ) -> V_253 ==
( V_251 -> V_253 & ( & V_249 -> V_255 ) -> V_253 ) ) {
if ( V_249 -> V_256 == & V_257 )
return NULL ;
return V_249 -> V_256 ;
}
return NULL ;
}
static int F_130 ( struct V_182 * V_187 , int V_258 )
{
struct V_11 * V_38 ;
struct V_179 * V_180 = V_187 -> V_188 ;
int V_14 = 0 ;
F_131 () ;
F_132 ( V_187 ) ;
if ( V_180 -> V_192 == V_259 ||
V_258 == V_260 )
F_133 ( V_187 ) ;
else {
V_38 = V_180 -> V_192 ;
V_14 = F_134 ( V_187 , V_187 -> V_261 , & V_38 -> V_262 ) ;
}
F_135 ( V_187 ) ;
F_136 () ;
return V_14 ;
}
static int F_137 ( struct V_182 * V_187 , struct V_246 * V_263 )
{
struct V_11 * V_38 ;
int V_14 ;
int V_264 ;
struct V_11 * V_265 ;
struct V_179 * V_180 = V_187 -> V_188 ;
struct V_70 V_71 ;
F_29 () ;
V_265 = F_129 ( V_263 ) ;
if ( V_265 != NULL ) {
#ifdef F_138
struct V_266 V_267 ;
F_139 ( & V_71 , V_82 , V_268 , & V_267 ) ;
V_71 . V_269 . V_270 . V_267 -> V_243 = V_263 -> V_271 ;
V_71 . V_269 . V_270 . V_267 -> V_272 = V_263 -> V_273 ;
V_71 . V_269 . V_270 . V_267 -> V_274 . V_275 = V_263 -> V_252 . V_253 ;
#endif
V_264 = V_260 ;
V_38 = V_180 -> V_192 ;
V_14 = V_217 ( V_38 , V_265 , V_5 , & V_71 ) ;
V_14 = F_2 ( L_10 , V_38 , V_265 , V_5 , V_14 ) ;
} else {
V_264 = V_276 ;
V_14 = 0 ;
}
F_34 () ;
if ( V_14 != 0 )
return V_14 ;
return F_130 ( V_187 , V_264 ) ;
}
static void F_140 ( struct V_181 * V_182 , struct V_277 * V_278 )
{
struct V_182 * V_187 = V_182 -> V_187 ;
struct V_279 * V_280 ;
struct V_179 * V_180 = V_182 -> V_187 -> V_188 ;
struct V_281 * V_282 ;
unsigned short V_283 = 0 ;
if ( V_278 == NULL ) {
F_141 (spp, &smk_ipv6_port_list, list) {
if ( V_187 != V_282 -> V_284 )
continue;
V_282 -> V_190 = V_180 -> V_190 ;
V_282 -> V_192 = V_180 -> V_192 ;
return;
}
return;
}
V_280 = (struct V_279 * ) V_278 ;
V_283 = F_142 ( V_280 -> V_285 ) ;
if ( V_283 == 0 )
return;
F_141 (spp, &smk_ipv6_port_list, list) {
if ( V_282 -> V_286 != V_283 )
continue;
V_282 -> V_286 = V_283 ;
V_282 -> V_284 = V_187 ;
V_282 -> V_190 = V_180 -> V_190 ;
V_282 -> V_192 = V_180 -> V_192 ;
return;
}
V_282 = F_14 ( sizeof( * V_282 ) , V_42 ) ;
if ( V_282 == NULL )
return;
V_282 -> V_286 = V_283 ;
V_282 -> V_284 = V_187 ;
V_282 -> V_190 = V_180 -> V_190 ;
V_282 -> V_192 = V_180 -> V_192 ;
F_143 ( & V_282 -> V_63 , & V_287 ) ;
return;
}
static int F_144 ( struct V_182 * V_187 , struct V_279 * V_278 ,
int V_288 )
{
T_5 * V_289 ;
T_6 * V_290 ;
struct V_281 * V_282 ;
struct V_179 * V_180 = V_187 -> V_188 ;
struct V_11 * V_38 ;
unsigned short V_283 = 0 ;
struct V_11 * V_291 ;
struct V_70 V_71 ;
int V_14 ;
#ifdef F_138
struct V_266 V_267 ;
#endif
if ( V_288 == V_292 ) {
V_38 = V_259 ;
V_291 = V_180 -> V_190 ;
} else {
V_38 = V_180 -> V_192 ;
V_291 = V_259 ;
}
V_283 = F_142 ( V_278 -> V_285 ) ;
V_289 = ( T_5 * ) ( & V_278 -> V_293 ) ;
V_290 = ( T_6 * ) ( & V_278 -> V_293 ) ;
if ( V_290 [ 0 ] || V_290 [ 1 ] || V_290 [ 2 ] || V_289 [ 6 ] || F_142 ( V_289 [ 7 ] ) != 1 )
goto V_294;
if ( V_288 == V_292 ) {
V_38 = & V_175 ;
goto V_294;
}
F_141 (spp, &smk_ipv6_port_list, list) {
if ( V_282 -> V_286 != V_283 )
continue;
V_291 = V_282 -> V_190 ;
if ( V_288 == V_295 )
V_180 -> V_245 = V_282 -> V_192 ;
break;
}
V_294:
#ifdef F_138
F_139 ( & V_71 , V_82 , V_268 , & V_267 ) ;
V_71 . V_269 . V_270 . V_267 -> V_243 = V_187 -> V_261 ;
V_71 . V_269 . V_270 . V_267 -> V_272 = V_283 ;
if ( V_288 == V_292 )
V_71 . V_269 . V_270 . V_267 -> V_296 . V_297 = V_278 -> V_293 ;
else
V_71 . V_269 . V_270 . V_267 -> V_296 . V_275 = V_278 -> V_293 ;
#endif
V_14 = V_217 ( V_38 , V_291 , V_5 , & V_71 ) ;
V_14 = F_2 ( L_11 , V_38 , V_291 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_145 ( struct V_25 * V_25 , const char * V_33 ,
const void * V_138 , T_2 V_161 , int V_108 )
{
struct V_11 * V_38 ;
struct V_43 * V_298 = V_25 -> V_120 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
int V_14 = 0 ;
if ( V_138 == NULL || V_161 > V_41 || V_161 == 0 )
return - V_173 ;
V_38 = F_15 ( V_138 , V_161 ) ;
if ( V_38 == NULL )
return - V_173 ;
if ( strcmp ( V_33 , V_143 ) == 0 ) {
V_298 -> V_47 = V_38 ;
V_298 -> V_48 |= V_299 ;
return 0 ;
}
if ( V_25 -> V_26 -> V_184 != V_185 )
return - V_186 ;
V_182 = F_83 ( V_25 ) ;
if ( V_182 == NULL || V_182 -> V_187 == NULL )
return - V_186 ;
V_180 = V_182 -> V_187 -> V_188 ;
if ( strcmp ( V_33 , V_189 ) == 0 )
V_180 -> V_190 = V_38 ;
else if ( strcmp ( V_33 , V_191 ) == 0 ) {
V_180 -> V_192 = V_38 ;
if ( V_182 -> V_187 -> V_261 == V_300 ) {
V_14 = F_130 ( V_182 -> V_187 , V_276 ) ;
if ( V_14 != 0 )
F_146 ( V_301
L_12 ,
V_82 , - V_14 ) ;
}
} else
return - V_186 ;
#if F_147 ( V_302 ) && ! F_148 ( V_303 )
if ( V_182 -> V_187 -> V_261 == V_304 )
F_140 ( V_182 , NULL ) ;
#endif
return 0 ;
}
static int F_149 ( struct V_181 * V_182 , int V_243 ,
int type , int V_305 , int V_306 )
{
if ( V_243 != V_300 || V_182 -> V_187 == NULL )
return 0 ;
return F_130 ( V_182 -> V_187 , V_276 ) ;
}
static int F_150 ( struct V_181 * V_182 , struct V_277 * V_278 ,
int V_307 )
{
#if F_147 ( V_302 )
if ( V_182 -> V_187 != NULL && V_182 -> V_187 -> V_261 == V_304 )
F_140 ( V_182 , V_278 ) ;
#endif
return 0 ;
}
static int F_151 ( struct V_181 * V_182 , struct V_277 * V_263 ,
int V_307 )
{
int V_14 = 0 ;
if ( V_182 -> V_187 == NULL )
return 0 ;
switch ( V_182 -> V_187 -> V_261 ) {
case V_300 :
if ( V_307 < sizeof( struct V_246 ) )
return - V_173 ;
V_14 = F_137 ( V_182 -> V_187 , (struct V_246 * ) V_263 ) ;
break;
case V_304 :
if ( V_307 < sizeof( struct V_279 ) )
return - V_173 ;
#if F_147 ( V_302 ) && ! F_148 ( V_303 )
V_14 = F_144 ( V_182 -> V_187 , (struct V_279 * ) V_263 ,
V_295 ) ;
#endif
break;
}
return V_14 ;
}
static int F_152 ( int V_108 )
{
int V_142 = 0 ;
if ( V_108 & V_308 )
V_142 |= V_4 ;
if ( V_108 & V_309 )
V_142 |= V_5 ;
if ( V_108 & V_310 )
V_142 |= V_6 ;
return V_142 ;
}
static int F_153 ( struct V_311 * V_312 )
{
struct V_11 * V_38 = F_41 () ;
V_312 -> V_31 = V_38 ;
return 0 ;
}
static void F_154 ( struct V_311 * V_312 )
{
V_312 -> V_31 = NULL ;
}
static struct V_11 * F_155 ( struct V_313 * V_314 )
{
return (struct V_11 * ) V_314 -> V_315 . V_31 ;
}
static int F_156 ( struct V_313 * V_314 )
{
struct V_316 * V_44 = & V_314 -> V_315 ;
struct V_11 * V_38 = F_41 () ;
V_44 -> V_31 = V_38 ;
return 0 ;
}
static void F_157 ( struct V_313 * V_314 )
{
struct V_316 * V_44 = & V_314 -> V_315 ;
V_44 -> V_31 = NULL ;
}
static int F_158 ( struct V_313 * V_314 , int V_235 )
{
struct V_11 * V_180 = F_155 ( V_314 ) ;
struct V_70 V_71 ;
int V_14 ;
#ifdef F_138
F_27 ( & V_71 , V_82 , V_317 ) ;
V_71 . V_269 . V_270 . V_318 = V_314 -> V_315 . V_319 ;
#endif
V_14 = F_51 ( V_180 , V_235 , & V_71 ) ;
V_14 = F_4 ( L_13 , V_180 , V_235 , V_14 ) ;
return V_14 ;
}
static int F_159 ( struct V_313 * V_314 , int V_320 )
{
int V_142 ;
V_142 = F_152 ( V_320 ) ;
return F_158 ( V_314 , V_142 ) ;
}
static int F_160 ( struct V_313 * V_314 , int V_197 )
{
int V_142 ;
switch ( V_197 ) {
case V_321 :
case V_322 :
V_142 = V_4 ;
break;
case V_323 :
case V_324 :
case V_325 :
case V_326 :
V_142 = V_66 ;
break;
case V_327 :
case V_328 :
return 0 ;
default:
return - V_173 ;
}
return F_158 ( V_314 , V_142 ) ;
}
static int F_161 ( struct V_313 * V_314 , char T_7 * V_329 ,
int V_320 )
{
int V_142 ;
V_142 = F_152 ( V_320 ) ;
return F_158 ( V_314 , V_142 ) ;
}
static struct V_11 * F_162 ( struct V_330 * V_331 )
{
return (struct V_11 * ) V_331 -> V_332 . V_31 ;
}
static int F_163 ( struct V_330 * V_331 )
{
struct V_316 * V_44 = & V_331 -> V_332 ;
struct V_11 * V_38 = F_41 () ;
V_44 -> V_31 = V_38 ;
return 0 ;
}
static void F_164 ( struct V_330 * V_331 )
{
struct V_316 * V_44 = & V_331 -> V_332 ;
V_44 -> V_31 = NULL ;
}
static int F_165 ( struct V_330 * V_331 , int V_235 )
{
struct V_11 * V_180 = F_162 ( V_331 ) ;
struct V_70 V_71 ;
int V_14 ;
#ifdef F_138
F_27 ( & V_71 , V_82 , V_317 ) ;
V_71 . V_269 . V_270 . V_318 = V_331 -> V_332 . V_319 ;
#endif
V_14 = F_51 ( V_180 , V_235 , & V_71 ) ;
V_14 = F_4 ( L_14 , V_180 , V_235 , V_14 ) ;
return V_14 ;
}
static int F_166 ( struct V_330 * V_331 , int V_333 )
{
int V_142 ;
V_142 = F_152 ( V_333 ) ;
return F_165 ( V_331 , V_142 ) ;
}
static int F_167 ( struct V_330 * V_331 , int V_197 )
{
int V_142 ;
switch ( V_197 ) {
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_321 :
case V_339 :
V_142 = V_4 ;
break;
case V_340 :
case V_341 :
case V_326 :
case V_323 :
V_142 = V_66 ;
break;
case V_327 :
case V_342 :
return 0 ;
default:
return - V_173 ;
}
return F_165 ( V_331 , V_142 ) ;
}
static int F_168 ( struct V_330 * V_331 , struct V_343 * V_344 ,
unsigned V_345 , int V_346 )
{
return F_165 ( V_331 , V_66 ) ;
}
static int F_169 ( struct V_347 * V_348 )
{
struct V_316 * V_349 = & V_348 -> V_350 ;
struct V_11 * V_38 = F_41 () ;
V_349 -> V_31 = V_38 ;
return 0 ;
}
static void F_170 ( struct V_347 * V_348 )
{
struct V_316 * V_349 = & V_348 -> V_350 ;
V_349 -> V_31 = NULL ;
}
static struct V_11 * F_171 ( struct V_347 * V_348 )
{
return (struct V_11 * ) V_348 -> V_350 . V_31 ;
}
static int F_172 ( struct V_347 * V_348 , int V_235 )
{
struct V_11 * V_351 = F_171 ( V_348 ) ;
struct V_70 V_71 ;
int V_14 ;
#ifdef F_138
F_27 ( & V_71 , V_82 , V_317 ) ;
V_71 . V_269 . V_270 . V_318 = V_348 -> V_350 . V_319 ;
#endif
V_14 = F_51 ( V_351 , V_235 , & V_71 ) ;
V_14 = F_4 ( L_15 , V_351 , V_235 , V_14 ) ;
return V_14 ;
}
static int F_173 ( struct V_347 * V_348 , int V_352 )
{
int V_142 ;
V_142 = F_152 ( V_352 ) ;
return F_172 ( V_348 , V_142 ) ;
}
static int F_174 ( struct V_347 * V_348 , int V_197 )
{
int V_142 ;
switch ( V_197 ) {
case V_321 :
case V_353 :
V_142 = V_4 ;
break;
case V_323 :
case V_326 :
V_142 = V_66 ;
break;
case V_327 :
case V_354 :
return 0 ;
default:
return - V_173 ;
}
return F_172 ( V_348 , V_142 ) ;
}
static int F_175 ( struct V_347 * V_348 , struct V_311 * V_312 ,
int V_352 )
{
int V_142 ;
V_142 = F_152 ( V_352 ) ;
return F_172 ( V_348 , V_142 ) ;
}
static int F_176 ( struct V_347 * V_348 , struct V_311 * V_312 ,
struct V_23 * V_355 , long type , int V_1 )
{
return F_172 ( V_348 , V_66 ) ;
}
static int F_177 ( struct V_316 * V_356 , short V_357 )
{
struct V_11 * V_358 = V_356 -> V_31 ;
int V_142 = F_152 ( V_357 ) ;
struct V_70 V_71 ;
int V_14 ;
#ifdef F_138
F_27 ( & V_71 , V_82 , V_317 ) ;
V_71 . V_269 . V_270 . V_318 = V_356 -> V_319 ;
#endif
V_14 = F_51 ( V_358 , V_142 , & V_71 ) ;
V_14 = F_4 ( L_16 , V_358 , V_142 , V_14 ) ;
return V_14 ;
}
static void F_178 ( struct V_316 * V_356 , T_3 * V_194 )
{
struct V_11 * V_358 = V_356 -> V_31 ;
* V_194 = V_358 -> V_195 ;
}
static void F_179 ( struct V_35 * V_359 , struct V_25 * V_25 )
{
struct V_87 * V_122 ;
struct V_89 * V_90 ;
struct V_43 * V_44 ;
struct V_11 * V_38 ;
struct V_11 * V_360 = F_41 () ;
struct V_11 * V_361 ;
char V_362 [ V_171 ] ;
int V_363 = 0 ;
int V_14 ;
struct V_35 * V_36 ;
if ( V_25 == NULL )
return;
V_44 = V_25 -> V_120 ;
F_180 ( & V_44 -> V_49 ) ;
if ( V_44 -> V_48 & V_299 )
goto V_364;
V_122 = V_25 -> V_26 ;
V_90 = V_122 -> V_97 ;
V_361 = V_90 -> V_93 ;
if ( V_359 -> V_365 == V_359 ) {
switch ( V_122 -> V_184 ) {
case V_366 :
V_90 -> V_91 = & V_174 ;
V_90 -> V_93 = & V_174 ;
V_44 -> V_47 = V_90 -> V_91 ;
break;
case V_367 :
V_44 -> V_47 = F_41 () ;
break;
default:
V_44 -> V_47 = V_90 -> V_91 ;
break;
}
V_44 -> V_48 |= V_299 ;
goto V_364;
}
switch ( V_122 -> V_184 ) {
case V_368 :
case V_369 :
case V_185 :
case V_366 :
V_361 = & V_174 ;
break;
case V_370 :
V_361 = V_360 ;
break;
case V_371 :
break;
case V_367 :
V_361 = & V_174 ;
default:
if ( F_181 ( V_25 -> V_372 ) ) {
V_361 = & V_174 ;
break;
}
if ( V_25 -> V_39 -> V_40 == NULL )
break;
V_36 = F_182 ( V_359 ) ;
V_38 = F_13 ( V_165 , V_25 , V_36 ) ;
if ( V_38 != NULL )
V_361 = V_38 ;
if ( F_183 ( V_25 -> V_372 ) ) {
if ( V_44 -> V_48 & V_144 ) {
V_44 -> V_48 &= ~ V_144 ;
V_14 = V_25 -> V_39 -> V_373 ( V_36 ,
V_170 ,
V_172 , V_171 ,
0 ) ;
} else {
V_14 = V_25 -> V_39 -> V_40 ( V_36 ,
V_170 , V_362 ,
V_171 ) ;
if ( V_14 >= 0 && strncmp ( V_362 , V_172 ,
V_171 ) != 0 )
V_14 = - V_173 ;
}
if ( V_14 >= 0 )
V_363 = V_121 ;
}
V_38 = F_13 ( V_168 , V_25 , V_36 ) ;
if ( V_38 == & V_174 || V_38 == & V_175 )
V_38 = NULL ;
V_44 -> V_20 = V_38 ;
V_38 = F_13 ( V_169 , V_25 , V_36 ) ;
if ( V_38 == & V_174 || V_38 == & V_175 )
V_38 = NULL ;
V_44 -> V_177 = V_38 ;
F_184 ( V_36 ) ;
break;
}
if ( V_361 == NULL )
V_44 -> V_47 = V_360 ;
else
V_44 -> V_47 = V_361 ;
V_44 -> V_48 |= ( V_299 | V_363 ) ;
V_364:
F_185 ( & V_44 -> V_49 ) ;
return;
}
static int F_186 ( struct V_23 * V_234 , char * V_33 , char * * V_138 )
{
struct V_11 * V_38 = F_7 ( V_234 ) ;
char * V_100 ;
int V_374 ;
if ( strcmp ( V_33 , L_17 ) != 0 )
return - V_173 ;
V_100 = F_65 ( V_38 -> V_17 , V_42 ) ;
if ( V_100 == NULL )
return - V_62 ;
V_374 = strlen ( V_100 ) ;
* V_138 = V_100 ;
return V_374 ;
}
static int F_187 ( struct V_23 * V_234 , char * V_33 ,
void * V_138 , T_2 V_161 )
{
struct V_18 * V_19 ;
struct V_30 * V_230 ;
struct V_11 * V_38 ;
if ( V_234 != V_21 )
return - V_119 ;
if ( ! F_42 ( V_118 ) )
return - V_119 ;
if ( V_138 == NULL || V_161 == 0 || V_161 >= V_41 )
return - V_173 ;
if ( strcmp ( V_33 , L_17 ) != 0 )
return - V_173 ;
V_38 = F_15 ( V_138 , V_161 ) ;
if ( V_38 == NULL )
return - V_173 ;
if ( V_38 == & V_175 )
return - V_119 ;
V_230 = F_188 () ;
if ( V_230 == NULL )
return - V_62 ;
V_19 = V_230 -> V_31 ;
V_19 -> V_20 = V_38 ;
F_189 ( V_230 ) ;
return V_161 ;
}
static int F_190 ( struct V_182 * V_182 ,
struct V_182 * V_375 , struct V_182 * V_376 )
{
struct V_11 * V_38 ;
struct V_11 * V_211 ;
struct V_179 * V_180 = V_182 -> V_188 ;
struct V_179 * V_377 = V_375 -> V_188 ;
struct V_179 * V_298 = V_376 -> V_188 ;
struct V_70 V_71 ;
int V_14 = 0 ;
#ifdef F_138
struct V_266 V_267 ;
#endif
if ( ! F_42 ( V_85 ) ) {
V_38 = V_180 -> V_192 ;
V_211 = V_377 -> V_190 ;
#ifdef F_138
F_139 ( & V_71 , V_82 , V_268 , & V_267 ) ;
F_191 ( & V_71 , V_375 ) ;
#endif
V_14 = V_217 ( V_38 , V_211 , V_5 , & V_71 ) ;
V_14 = F_2 ( L_18 , V_38 , V_211 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_211 = V_377 -> V_192 ;
V_38 = V_180 -> V_190 ;
V_14 = V_217 ( V_211 , V_38 , V_5 , & V_71 ) ;
V_14 = F_2 ( L_18 , V_211 , V_38 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_298 -> V_245 = V_180 -> V_192 ;
V_180 -> V_245 = V_377 -> V_192 ;
}
return V_14 ;
}
static int F_192 ( struct V_181 * V_182 , struct V_181 * V_375 )
{
struct V_179 * V_180 = V_182 -> V_187 -> V_188 ;
struct V_179 * V_377 = V_375 -> V_187 -> V_188 ;
struct V_70 V_71 ;
int V_14 ;
#ifdef F_138
struct V_266 V_267 ;
F_139 ( & V_71 , V_82 , V_268 , & V_267 ) ;
F_191 ( & V_71 , V_375 -> V_187 ) ;
#endif
if ( F_42 ( V_85 ) )
return 0 ;
V_14 = V_217 ( V_180 -> V_192 , V_377 -> V_190 , V_5 , & V_71 ) ;
V_14 = F_2 ( L_19 , V_180 -> V_192 , V_377 -> V_190 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_193 ( struct V_181 * V_182 , struct V_378 * V_312 ,
int V_161 )
{
struct V_246 * V_247 = (struct V_246 * ) V_312 -> V_379 ;
#if F_147 ( V_302 ) && ! F_148 ( V_303 )
struct V_279 * V_263 = (struct V_279 * ) V_312 -> V_379 ;
#endif
int V_14 = 0 ;
if ( V_247 == NULL )
return 0 ;
switch ( V_247 -> V_271 ) {
case V_380 :
V_14 = F_137 ( V_182 -> V_187 , V_247 ) ;
break;
case V_381 :
#if F_147 ( V_302 ) && ! F_148 ( V_303 )
V_14 = F_144 ( V_182 -> V_187 , V_263 , V_382 ) ;
#endif
break;
}
return V_14 ;
}
static struct V_11 * F_194 ( struct V_383 * V_263 ,
struct V_179 * V_180 )
{
struct V_11 * V_38 ;
int V_384 = 0 ;
int V_385 ;
int V_386 ;
if ( ( V_263 -> V_108 & V_387 ) != 0 ) {
F_29 () ;
F_141 (skp, &smack_known_list, list) {
if ( V_263 -> V_388 . V_389 . V_390 != V_38 -> V_262 . V_388 . V_389 . V_390 )
continue;
if ( ( V_263 -> V_108 & V_391 ) == 0 ) {
if ( ( V_38 -> V_262 . V_108 &
V_391 ) == 0 )
V_384 = 1 ;
break;
}
for ( V_385 = - 1 , V_386 = - 1 ; V_385 == V_386 ; ) {
V_385 = F_195 ( V_263 -> V_388 . V_389 . V_392 ,
V_385 + 1 ) ;
V_386 = F_195 (
V_38 -> V_262 . V_388 . V_389 . V_392 ,
V_386 + 1 ) ;
if ( V_385 < 0 || V_386 < 0 )
break;
}
if ( V_385 == V_386 ) {
V_384 = 1 ;
break;
}
}
F_34 () ;
if ( V_384 )
return V_38 ;
if ( V_180 != NULL && V_180 -> V_190 == & V_174 )
return & V_175 ;
return & V_174 ;
}
if ( ( V_263 -> V_108 & V_393 ) != 0 ) {
V_38 = F_108 ( V_263 -> V_388 . V_194 ) ;
F_196 ( V_38 == NULL ) ;
return V_38 ;
}
return V_259 ;
}
static int F_197 ( struct V_394 * V_395 , struct V_279 * V_247 )
{
T_8 V_396 ;
int V_397 ;
int V_398 = - V_173 ;
struct V_399 V_400 ;
struct V_399 * V_401 ;
T_5 V_402 ;
struct V_403 V_404 , * V_405 ;
struct V_406 V_407 , * V_408 ;
struct V_409 V_410 , * V_411 ;
V_247 -> V_285 = 0 ;
V_397 = F_198 ( V_395 ) ;
V_401 = F_199 ( V_395 , V_397 , sizeof( V_400 ) , & V_400 ) ;
if ( V_401 == NULL )
return - V_173 ;
V_247 -> V_293 = V_401 -> V_297 ;
V_396 = V_401 -> V_396 ;
V_397 += sizeof( V_400 ) ;
V_397 = F_200 ( V_395 , V_397 , & V_396 , & V_402 ) ;
if ( V_397 < 0 )
return - V_173 ;
V_398 = V_396 ;
switch ( V_398 ) {
case V_412 :
V_405 = F_199 ( V_395 , V_397 , sizeof( V_404 ) , & V_404 ) ;
if ( V_405 != NULL )
V_247 -> V_285 = V_405 -> V_413 ;
break;
case V_414 :
V_408 = F_199 ( V_395 , V_397 , sizeof( V_407 ) , & V_407 ) ;
if ( V_408 != NULL )
V_247 -> V_285 = V_408 -> V_413 ;
break;
case V_415 :
V_411 = F_199 ( V_395 , V_397 , sizeof( V_410 ) , & V_410 ) ;
if ( V_411 != NULL )
V_247 -> V_285 = V_411 -> V_416 ;
break;
}
return V_398 ;
}
static int F_201 ( struct V_182 * V_187 , struct V_394 * V_395 )
{
struct V_383 V_417 ;
struct V_179 * V_180 = V_187 -> V_188 ;
struct V_11 * V_38 = NULL ;
int V_14 = 0 ;
struct V_70 V_71 ;
#ifdef F_138
struct V_266 V_267 ;
#endif
#if F_147 ( V_302 )
struct V_279 V_418 ;
int V_398 ;
#endif
switch ( V_187 -> V_261 ) {
case V_300 :
#ifdef V_303
if ( V_395 && V_395 -> V_419 != 0 ) {
V_38 = F_108 ( V_395 -> V_419 ) ;
goto V_420;
}
#endif
F_202 ( & V_417 ) ;
V_14 = F_203 ( V_395 , V_187 -> V_261 , & V_417 ) ;
if ( V_14 == 0 )
V_38 = F_194 ( & V_417 , V_180 ) ;
else
V_38 = V_259 ;
F_204 ( & V_417 ) ;
#ifdef V_303
V_420:
#endif
#ifdef F_138
F_139 ( & V_71 , V_82 , V_268 , & V_267 ) ;
V_71 . V_269 . V_270 . V_267 -> V_243 = V_187 -> V_261 ;
V_71 . V_269 . V_270 . V_267 -> V_421 = V_395 -> V_422 ;
F_205 ( V_395 , & V_71 . V_269 , NULL ) ;
#endif
V_14 = V_217 ( V_38 , V_180 -> V_190 , V_5 , & V_71 ) ;
V_14 = F_2 ( L_20 , V_38 , V_180 -> V_190 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_206 ( V_395 , V_14 , 0 ) ;
break;
#if F_147 ( V_302 )
case V_304 :
V_398 = F_197 ( V_395 , & V_418 ) ;
if ( V_398 != V_414 && V_398 != V_412 )
break;
#ifdef V_303
if ( V_395 && V_395 -> V_419 != 0 )
V_38 = F_108 ( V_395 -> V_419 ) ;
else
V_38 = V_259 ;
#ifdef F_138
F_139 ( & V_71 , V_82 , V_268 , & V_267 ) ;
V_71 . V_269 . V_270 . V_267 -> V_243 = V_187 -> V_261 ;
V_71 . V_269 . V_270 . V_267 -> V_421 = V_395 -> V_422 ;
F_207 ( V_395 , & V_71 . V_269 , NULL ) ;
#endif
V_14 = V_217 ( V_38 , V_180 -> V_190 , V_5 , & V_71 ) ;
V_14 = F_2 ( L_21 , V_38 , V_180 -> V_190 ,
V_5 , V_14 ) ;
#else
V_14 = F_144 ( V_187 , & V_418 , V_292 ) ;
#endif
break;
#endif
}
return V_14 ;
}
static int F_208 ( struct V_181 * V_182 ,
char T_7 * V_423 ,
int T_7 * V_424 , unsigned V_139 )
{
struct V_179 * V_180 ;
char * V_425 = L_22 ;
int V_374 = 1 ;
int V_14 = 0 ;
V_180 = V_182 -> V_187 -> V_188 ;
if ( V_180 -> V_245 != NULL ) {
V_425 = V_180 -> V_245 -> V_17 ;
V_374 = strlen ( V_425 ) + 1 ;
}
if ( V_374 > V_139 )
V_14 = - V_426 ;
else if ( F_209 ( V_423 , V_425 , V_374 ) != 0 )
V_14 = - V_427 ;
if ( F_210 ( V_374 , V_424 ) != 0 )
V_14 = - V_427 ;
return V_14 ;
}
static int F_211 ( struct V_181 * V_182 ,
struct V_394 * V_395 , T_3 * V_194 )
{
struct V_383 V_417 ;
struct V_179 * V_180 = NULL ;
struct V_11 * V_38 ;
int V_243 = V_428 ;
T_3 V_2 = 0 ;
int V_14 ;
if ( V_395 != NULL ) {
if ( V_395 -> V_305 == F_212 ( V_429 ) )
V_243 = V_300 ;
#if F_147 ( V_302 )
else if ( V_395 -> V_305 == F_212 ( V_430 ) )
V_243 = V_304 ;
#endif
}
if ( V_243 == V_428 && V_182 != NULL )
V_243 = V_182 -> V_187 -> V_261 ;
switch ( V_243 ) {
case V_431 :
V_180 = V_182 -> V_187 -> V_188 ;
V_2 = V_180 -> V_192 -> V_195 ;
break;
case V_300 :
#ifdef V_303
V_2 = V_395 -> V_419 ;
if ( V_2 != 0 )
break;
#endif
if ( V_182 != NULL && V_182 -> V_187 != NULL )
V_180 = V_182 -> V_187 -> V_188 ;
F_202 ( & V_417 ) ;
V_14 = F_203 ( V_395 , V_243 , & V_417 ) ;
if ( V_14 == 0 ) {
V_38 = F_194 ( & V_417 , V_180 ) ;
V_2 = V_38 -> V_195 ;
}
F_204 ( & V_417 ) ;
break;
#if F_147 ( V_302 )
case V_304 :
#ifdef V_303
V_2 = V_395 -> V_419 ;
#endif
break;
#endif
}
* V_194 = V_2 ;
if ( V_2 == 0 )
return - V_173 ;
return 0 ;
}
static void F_213 ( struct V_182 * V_187 , struct V_181 * V_432 )
{
struct V_179 * V_180 ;
struct V_11 * V_38 = F_41 () ;
if ( V_187 == NULL ||
( V_187 -> V_261 != V_300 && V_187 -> V_261 != V_304 ) )
return;
V_180 = V_187 -> V_188 ;
V_180 -> V_190 = V_38 ;
V_180 -> V_192 = V_38 ;
}
static int F_214 ( struct V_182 * V_187 , struct V_394 * V_395 ,
struct V_433 * V_434 )
{
T_9 V_243 = V_187 -> V_261 ;
struct V_11 * V_38 ;
struct V_179 * V_180 = V_187 -> V_188 ;
struct V_383 V_417 ;
struct V_246 V_435 ;
struct V_436 * V_437 ;
struct V_11 * V_438 ;
int V_14 ;
struct V_70 V_71 ;
#ifdef F_138
struct V_266 V_267 ;
#endif
#if F_147 ( V_302 )
if ( V_243 == V_304 ) {
if ( V_395 -> V_305 == F_212 ( V_429 ) )
V_243 = V_300 ;
else
return 0 ;
}
#endif
#ifdef V_303
if ( V_395 && V_395 -> V_419 != 0 ) {
V_38 = F_108 ( V_395 -> V_419 ) ;
goto V_420;
}
#endif
F_202 ( & V_417 ) ;
V_14 = F_203 ( V_395 , V_243 , & V_417 ) ;
if ( V_14 == 0 )
V_38 = F_194 ( & V_417 , V_180 ) ;
else
V_38 = & V_439 ;
F_204 ( & V_417 ) ;
#ifdef V_303
V_420:
#endif
#ifdef F_138
F_139 ( & V_71 , V_82 , V_268 , & V_267 ) ;
V_71 . V_269 . V_270 . V_267 -> V_243 = V_243 ;
V_71 . V_269 . V_270 . V_267 -> V_421 = V_395 -> V_422 ;
F_205 ( V_395 , & V_71 . V_269 , NULL ) ;
#endif
V_14 = V_217 ( V_38 , V_180 -> V_190 , V_5 , & V_71 ) ;
V_14 = F_2 ( L_23 , V_38 , V_180 -> V_190 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_434 -> V_440 = V_38 -> V_195 ;
V_437 = F_215 ( V_395 ) ;
V_435 . V_252 . V_253 = V_437 -> V_297 ;
F_29 () ;
V_438 = F_129 ( & V_435 ) ;
F_34 () ;
if ( V_438 == NULL )
V_14 = F_216 ( V_434 , & V_38 -> V_262 ) ;
else
F_217 ( V_434 ) ;
return V_14 ;
}
static void F_218 ( struct V_182 * V_187 ,
const struct V_433 * V_434 )
{
struct V_179 * V_180 = V_187 -> V_188 ;
struct V_11 * V_38 ;
if ( V_434 -> V_440 != 0 ) {
V_38 = F_108 ( V_434 -> V_440 ) ;
V_180 -> V_245 = V_38 ;
} else
V_180 -> V_245 = NULL ;
}
static int F_219 ( struct V_441 * V_441 , const struct V_30 * V_30 ,
unsigned long V_108 )
{
struct V_11 * V_38 = F_31 ( V_30 -> V_31 ) ;
V_441 -> V_31 = V_38 ;
return 0 ;
}
static void F_220 ( struct V_441 * V_441 )
{
V_441 -> V_31 = NULL ;
}
static int F_221 ( T_10 V_442 ,
const struct V_30 * V_30 , unsigned V_443 )
{
struct V_441 * V_444 ;
struct V_70 V_71 ;
struct V_11 * V_222 = F_31 ( V_30 -> V_31 ) ;
int V_445 = 0 ;
int V_14 ;
V_444 = F_222 ( V_442 ) ;
if ( V_444 == NULL )
return - V_173 ;
if ( V_444 -> V_31 == NULL )
return 0 ;
if ( V_222 == NULL )
return - V_79 ;
#ifdef F_138
F_27 ( & V_71 , V_82 , V_446 ) ;
V_71 . V_269 . V_270 . V_447 . V_441 = V_444 -> V_448 ;
V_71 . V_269 . V_270 . V_447 . V_449 = V_444 -> V_450 ;
#endif
if ( V_443 & V_451 )
V_445 = V_4 ;
if ( V_443 & ( V_452 | V_453 | V_454 ) )
V_445 = V_5 ;
V_14 = V_217 ( V_222 , V_444 -> V_31 , V_445 , & V_71 ) ;
V_14 = F_2 ( L_24 , V_222 , V_444 -> V_31 , V_445 , V_14 ) ;
return V_14 ;
}
static int F_223 ( T_3 V_455 , T_3 V_114 , char * V_456 , void * * V_457 )
{
struct V_11 * V_38 ;
char * * V_458 = ( char * * ) V_457 ;
* V_458 = NULL ;
if ( V_455 != V_459 && V_455 != V_460 )
return - V_173 ;
if ( V_114 != V_461 && V_114 != V_462 )
return - V_173 ;
V_38 = F_15 ( V_456 , 0 ) ;
if ( V_38 )
* V_458 = V_38 -> V_17 ;
return 0 ;
}
static int F_224 ( struct V_463 * V_464 )
{
struct V_465 * V_466 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_464 -> V_467 ; V_3 ++ ) {
V_466 = & V_464 -> V_468 [ V_3 ] ;
if ( V_466 -> type == V_459 || V_466 -> type == V_460 )
return 1 ;
}
return 0 ;
}
static int F_225 ( T_3 V_194 , T_3 V_455 , T_3 V_114 , void * V_457 ,
struct V_469 * V_470 )
{
struct V_11 * V_38 ;
char * V_458 = V_457 ;
if ( F_226 ( ! V_458 ) ) {
F_227 ( 1 , L_25 ) ;
return - V_216 ;
}
if ( V_455 != V_459 && V_455 != V_460 )
return 0 ;
V_38 = F_108 ( V_194 ) ;
if ( V_114 == V_461 )
return ( V_458 == V_38 -> V_17 ) ;
if ( V_114 == V_462 )
return ( V_458 != V_38 -> V_17 ) ;
return 0 ;
}
static void F_228 ( void * V_457 )
{
}
static int F_229 ( const char * V_33 )
{
return ( strcmp ( V_33 , V_143 ) == 0 ) ;
}
static int F_230 ( T_3 V_194 , char * * V_471 , T_3 * V_472 )
{
struct V_11 * V_38 = F_108 ( V_194 ) ;
if ( V_471 )
* V_471 = V_38 -> V_17 ;
* V_472 = strlen ( V_38 -> V_17 ) ;
return 0 ;
}
static int F_231 ( const char * V_471 , T_3 V_472 , T_3 * V_194 )
{
struct V_11 * V_38 = F_232 ( V_471 ) ;
if ( V_38 )
* V_194 = V_38 -> V_195 ;
else
* V_194 = 0 ;
return 0 ;
}
static void F_233 ( char * V_471 , T_3 V_472 )
{
}
static int F_234 ( struct V_25 * V_25 , void * V_473 , T_3 V_474 )
{
return F_145 ( V_25 , V_143 , V_473 , V_474 , 0 ) ;
}
static int F_235 ( struct V_35 * V_35 , void * V_473 , T_3 V_474 )
{
return F_236 ( V_35 , V_165 , V_473 , V_474 , 0 ) ;
}
static int F_237 ( struct V_25 * V_25 , void * * V_473 , T_3 * V_474 )
{
int V_139 = 0 ;
V_139 = F_82 ( V_25 , V_143 , V_473 , true ) ;
if ( V_139 < 0 )
return V_139 ;
* V_474 = V_139 ;
return 0 ;
}
static T_11 void F_238 ( void )
{
F_19 ( & V_439 . V_55 ) ;
F_19 ( & V_96 . V_55 ) ;
F_19 ( & V_92 . V_55 ) ;
F_19 ( & V_174 . V_55 ) ;
F_19 ( & V_176 . V_55 ) ;
F_19 ( & V_175 . V_55 ) ;
F_21 ( & V_439 . V_54 ) ;
F_21 ( & V_96 . V_54 ) ;
F_21 ( & V_174 . V_54 ) ;
F_21 ( & V_92 . V_54 ) ;
F_21 ( & V_176 . V_54 ) ;
F_21 ( & V_175 . V_54 ) ;
F_239 ( & V_439 ) ;
F_239 ( & V_96 ) ;
F_239 ( & V_174 ) ;
F_239 ( & V_92 ) ;
F_239 ( & V_176 ) ;
F_239 ( & V_175 ) ;
}
static T_11 int F_240 ( void )
{
struct V_30 * V_30 ;
struct V_18 * V_19 ;
if ( ! F_241 ( & V_475 ) )
return 0 ;
V_476 = 1 ;
V_45 = F_242 ( V_43 , 0 ) ;
if ( ! V_45 )
return - V_62 ;
V_19 = F_20 ( & V_92 , & V_92 ,
V_42 ) ;
if ( V_19 == NULL ) {
F_243 ( V_45 ) ;
return - V_62 ;
}
F_146 ( V_477 L_26 ) ;
V_30 = (struct V_30 * ) V_21 -> V_30 ;
V_30 -> V_31 = V_19 ;
F_238 () ;
if ( F_244 ( & V_475 ) )
F_245 ( L_27 ) ;
return 0 ;
}

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
struct V_18 * V_25 = F_7 ( V_24 ) ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_3 ,
V_19 -> V_20 -> V_17 , V_25 -> V_20 -> V_17 , V_15 ,
V_21 -> V_22 , V_24 -> V_22 ) ;
return 0 ;
}
static int F_8 ( struct V_26 * V_26 , int V_1 , int V_14 )
{
struct V_18 * V_19 = F_5 () ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_4 ,
V_19 -> V_20 -> V_17 , F_9 ( V_26 ) -> V_17 , V_15 ,
V_26 -> V_27 -> V_28 , V_26 -> V_29 , V_21 -> V_22 ) ;
return 0 ;
}
static int F_10 ( struct V_30 * V_30 , int V_1 , int V_14 )
{
struct V_18 * V_19 = F_5 () ;
struct V_11 * V_12 = V_19 -> V_20 ;
struct V_26 * V_26 = V_30 -> V_31 ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_5 ,
V_12 -> V_17 , ( char * ) V_30 -> V_32 , V_15 ,
V_26 -> V_27 -> V_28 , V_26 -> V_29 , V_30 -> V_33 -> V_34 . V_35 ,
V_21 -> V_22 ) ;
return 0 ;
}
static int F_11 ( const struct V_36 * V_36 , struct V_30 * V_30 ,
int V_1 , int V_14 )
{
struct V_18 * V_19 = V_36 -> V_37 ;
struct V_11 * V_12 = V_19 -> V_20 ;
struct V_26 * V_26 = V_30 -> V_31 ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_5 ,
V_12 -> V_17 , F_9 ( V_26 ) -> V_17 , V_15 ,
V_26 -> V_27 -> V_28 , V_26 -> V_29 , V_30 -> V_33 -> V_34 . V_35 ,
V_21 -> V_22 ) ;
return 0 ;
}
static struct V_11 * F_12 ( const char * V_35 , struct V_26 * V_38 ,
struct V_39 * V_40 )
{
int V_14 ;
char * V_41 ;
struct V_11 * V_42 = NULL ;
if ( V_38 -> V_43 -> V_44 == NULL )
return NULL ;
V_41 = F_13 ( V_45 , V_46 ) ;
if ( V_41 == NULL )
return NULL ;
V_14 = V_38 -> V_43 -> V_44 ( V_40 , V_35 , V_41 , V_45 ) ;
if ( V_14 > 0 )
V_42 = F_14 ( V_41 , V_14 ) ;
F_15 ( V_41 ) ;
return V_42 ;
}
struct V_47 * F_16 ( struct V_11 * V_42 )
{
struct V_47 * V_48 ;
V_48 = F_13 ( sizeof( struct V_47 ) , V_49 ) ;
if ( V_48 == NULL )
return NULL ;
V_48 -> V_50 = V_42 ;
V_48 -> V_51 = 0 ;
F_17 ( & V_48 -> V_52 ) ;
return V_48 ;
}
static struct V_18 * F_18 ( struct V_11 * V_53 ,
struct V_11 * V_54 , T_1 V_55 )
{
struct V_18 * V_19 ;
V_19 = F_13 ( sizeof( struct V_18 ) , V_55 ) ;
if ( V_19 == NULL )
return NULL ;
V_19 -> V_20 = V_53 ;
V_19 -> V_56 = V_54 ;
F_19 ( & V_19 -> V_57 ) ;
F_17 ( & V_19 -> V_58 ) ;
return V_19 ;
}
static int F_20 ( struct V_59 * V_60 , struct V_59 * V_61 ,
T_1 V_55 )
{
struct V_62 * V_63 ;
struct V_62 * V_64 ;
int V_14 = 0 ;
F_19 ( V_60 ) ;
F_21 (orp, ohead, list) {
V_63 = F_13 ( sizeof( struct V_62 ) , V_55 ) ;
if ( V_63 == NULL ) {
V_14 = - V_65 ;
break;
}
* V_63 = * V_64 ;
F_22 ( & V_63 -> V_66 , V_60 ) ;
}
return V_14 ;
}
static inline unsigned int F_23 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_67 :
return V_4 ;
case V_68 :
return V_69 ;
}
return 0 ;
}
static int F_24 ( struct V_23 * V_70 ,
struct V_11 * V_71 ,
unsigned int V_1 , const char * V_72 )
{
int V_14 ;
struct V_73 V_74 , * V_75 = NULL ;
struct V_18 * V_19 ;
struct V_11 * V_76 ;
if ( ( V_1 & V_77 ) == 0 ) {
F_25 ( & V_74 , V_72 , V_78 ) ;
F_26 ( & V_74 , V_70 ) ;
V_75 = & V_74 ;
}
V_19 = F_7 ( V_70 ) ;
V_76 = F_27 ( V_19 ) ;
if ( ( V_1 & V_68 ) &&
( V_79 == V_80 ||
V_79 == V_81 ) ) {
if ( V_76 -> V_17 == V_71 -> V_17 )
V_14 = 0 ;
else if ( V_79 == V_81 )
V_14 = - V_82 ;
else if ( F_28 ( V_83 ) )
V_14 = 0 ;
else
V_14 = - V_82 ;
if ( V_75 )
F_29 ( V_76 -> V_17 ,
V_71 -> V_17 ,
0 , V_14 , V_75 ) ;
return V_14 ;
}
V_14 = F_30 ( V_19 , V_71 , F_23 ( V_1 ) , V_75 ) ;
return V_14 ;
}
static int F_31 ( struct V_23 * V_84 , unsigned int V_1 )
{
int V_14 ;
struct V_11 * V_42 ;
V_14 = F_32 ( V_84 , V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
V_42 = F_27 ( F_7 ( V_84 ) ) ;
V_14 = F_24 ( V_21 , V_42 , V_1 , V_85 ) ;
return V_14 ;
}
static int F_33 ( struct V_23 * V_86 )
{
int V_14 ;
struct V_11 * V_42 ;
V_14 = F_34 ( V_86 ) ;
if ( V_14 != 0 )
return V_14 ;
V_42 = F_27 ( F_5 () ) ;
V_14 = F_24 ( V_86 , V_42 , V_68 , V_85 ) ;
return V_14 ;
}
static int F_35 ( int V_87 )
{
int V_14 = 0 ;
struct V_11 * V_42 = F_36 () ;
if ( F_37 ( V_88 ) )
return 0 ;
if ( V_89 != NULL && V_89 != V_42 )
V_14 = - V_82 ;
return V_14 ;
}
static int F_38 ( struct V_90 * V_91 )
{
struct V_92 * V_93 ;
V_93 = F_13 ( sizeof( struct V_92 ) , V_46 ) ;
if ( V_93 == NULL )
return - V_65 ;
V_93 -> V_94 = & V_95 ;
V_93 -> V_96 = & V_95 ;
V_93 -> V_97 = & V_95 ;
V_93 -> V_98 = & V_99 ;
V_91 -> V_100 = V_93 ;
return 0 ;
}
static void F_39 ( struct V_90 * V_91 )
{
F_15 ( V_91 -> V_100 ) ;
V_91 -> V_100 = NULL ;
}
static int F_40 ( char * V_101 , char * V_102 )
{
char * V_103 , * V_104 , * V_105 , * V_40 ;
V_105 = ( char * ) F_41 ( V_46 ) ;
if ( V_105 == NULL )
return - V_65 ;
for ( V_103 = V_101 , V_104 = V_101 ; V_104 != NULL ; V_103 = V_104 + 1 ) {
if ( strstr ( V_103 , V_106 ) == V_103 )
V_40 = V_102 ;
else if ( strstr ( V_103 , V_107 ) == V_103 )
V_40 = V_102 ;
else if ( strstr ( V_103 , V_108 ) == V_103 )
V_40 = V_102 ;
else if ( strstr ( V_103 , V_109 ) == V_103 )
V_40 = V_102 ;
else if ( strstr ( V_103 , V_110 ) == V_103 )
V_40 = V_102 ;
else
V_40 = V_105 ;
V_104 = strchr ( V_103 , ',' ) ;
if ( V_104 != NULL )
* V_104 = '\0' ;
if ( * V_40 != '\0' )
strcat ( V_40 , L_6 ) ;
strcat ( V_40 , V_103 ) ;
}
strcpy ( V_101 , V_105 ) ;
F_42 ( ( unsigned long ) V_105 ) ;
return 0 ;
}
static int F_43 ( struct V_90 * V_91 , int V_111 , void * V_112 )
{
struct V_39 * V_113 = V_91 -> V_114 ;
struct V_26 * V_26 = V_113 -> V_115 ;
struct V_92 * V_116 = V_91 -> V_100 ;
struct V_47 * V_48 ;
struct V_11 * V_42 ;
char * V_117 ;
char * V_104 ;
int V_118 = 0 ;
int V_119 = 0 ;
if ( V_116 -> V_120 )
return 0 ;
V_116 -> V_120 = 1 ;
for ( V_117 = V_112 ; V_117 != NULL ; V_117 = V_104 ) {
V_104 = strchr ( V_117 , ',' ) ;
if ( V_104 != NULL )
* V_104 ++ = '\0' ;
if ( strncmp ( V_117 , V_108 , strlen ( V_108 ) ) == 0 ) {
V_117 += strlen ( V_108 ) ;
V_42 = F_14 ( V_117 , 0 ) ;
if ( V_42 != NULL ) {
V_116 -> V_98 = V_42 ;
V_119 = 1 ;
}
} else if ( strncmp ( V_117 , V_107 , strlen ( V_107 ) ) == 0 ) {
V_117 += strlen ( V_107 ) ;
V_42 = F_14 ( V_117 , 0 ) ;
if ( V_42 != NULL ) {
V_116 -> V_97 = V_42 ;
V_119 = 1 ;
}
} else if ( strncmp ( V_117 , V_106 ,
strlen ( V_106 ) ) == 0 ) {
V_117 += strlen ( V_106 ) ;
V_42 = F_14 ( V_117 , 0 ) ;
if ( V_42 != NULL ) {
V_116 -> V_96 = V_42 ;
V_119 = 1 ;
}
} else if ( strncmp ( V_117 , V_109 , strlen ( V_109 ) ) == 0 ) {
V_117 += strlen ( V_109 ) ;
V_42 = F_14 ( V_117 , 0 ) ;
if ( V_42 != NULL ) {
V_116 -> V_94 = V_42 ;
V_119 = 1 ;
}
} else if ( strncmp ( V_117 , V_110 , strlen ( V_110 ) ) == 0 ) {
V_117 += strlen ( V_110 ) ;
V_42 = F_14 ( V_117 , 0 ) ;
if ( V_42 != NULL ) {
V_116 -> V_94 = V_42 ;
V_118 = 1 ;
V_119 = 1 ;
}
}
}
if ( ! F_37 ( V_121 ) ) {
if ( V_119 )
return - V_122 ;
V_42 = F_36 () ;
V_116 -> V_94 = V_42 ;
V_116 -> V_96 = V_42 ;
}
V_48 = V_26 -> V_123 ;
if ( V_48 == NULL ) {
V_48 = F_16 ( V_116 -> V_94 ) ;
if ( V_48 == NULL )
return - V_65 ;
V_26 -> V_123 = V_48 ;
} else
V_48 -> V_50 = V_116 -> V_94 ;
if ( V_118 )
V_48 -> V_51 |= V_124 ;
return 0 ;
}
static int F_44 ( struct V_39 * V_39 )
{
struct V_92 * V_125 = V_39 -> V_126 -> V_100 ;
int V_14 ;
struct V_73 V_74 ;
F_25 ( & V_74 , V_85 , V_127 ) ;
F_45 ( & V_74 , V_39 ) ;
V_14 = F_46 ( V_125 -> V_97 , V_4 , & V_74 ) ;
V_14 = F_4 ( L_7 , V_125 -> V_97 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_47 ( struct V_128 * V_129 )
{
struct V_26 * V_26 = F_48 ( V_129 -> V_30 ) ;
struct V_18 * V_130 = V_129 -> V_36 -> V_37 ;
struct V_47 * V_48 ;
int V_14 ;
V_14 = F_49 ( V_129 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( V_129 -> V_131 )
return 0 ;
V_48 = V_26 -> V_123 ;
if ( V_48 -> V_20 == NULL || V_48 -> V_20 == V_130 -> V_20 )
return 0 ;
if ( V_129 -> V_132 & ( V_133 | V_134 ) ) {
struct V_23 * V_70 ;
V_14 = 0 ;
F_50 () ;
V_70 = F_51 ( V_21 ) ;
if ( F_52 ( V_70 != NULL ) )
V_14 = F_24 ( V_70 ,
V_48 -> V_20 ,
V_68 ,
V_85 ) ;
F_53 () ;
if ( V_14 != 0 )
return V_14 ;
} else if ( V_129 -> V_132 )
return - V_122 ;
V_130 -> V_20 = V_48 -> V_20 ;
V_129 -> V_135 |= V_136 ;
return 0 ;
}
static void F_54 ( struct V_128 * V_129 )
{
struct V_18 * V_130 = V_129 -> V_36 -> V_37 ;
if ( V_130 -> V_20 != V_130 -> V_56 )
V_21 -> V_137 = 0 ;
}
static int F_55 ( struct V_128 * V_129 )
{
struct V_18 * V_19 = F_5 () ;
int V_138 = F_56 ( V_129 ) ;
if ( ! V_138 && ( V_19 -> V_20 != V_19 -> V_56 ) )
V_138 = 1 ;
return V_138 ;
}
static int F_57 ( struct V_26 * V_26 )
{
struct V_11 * V_42 = F_36 () ;
V_26 -> V_123 = F_16 ( V_42 ) ;
if ( V_26 -> V_123 == NULL )
return - V_65 ;
return 0 ;
}
static void F_58 ( struct V_26 * V_26 )
{
F_15 ( V_26 -> V_123 ) ;
V_26 -> V_123 = NULL ;
}
static int F_59 ( struct V_26 * V_26 , struct V_26 * V_139 ,
const struct V_140 * V_140 , const char * * V_35 ,
void * * V_141 , T_2 * V_142 )
{
struct V_47 * V_143 = V_26 -> V_123 ;
struct V_11 * V_42 = F_36 () ;
struct V_11 * V_48 = F_9 ( V_26 ) ;
struct V_11 * V_144 = F_9 ( V_139 ) ;
int V_145 ;
if ( V_35 )
* V_35 = V_146 ;
if ( V_141 ) {
F_50 () ;
V_145 = F_60 ( V_42 -> V_17 , V_144 -> V_17 ,
& V_42 -> V_57 ) ;
F_53 () ;
if ( V_145 > 0 && ( ( V_145 & V_8 ) != 0 ) &&
F_61 ( V_139 ) ) {
V_48 = V_144 ;
V_143 -> V_51 |= V_147 ;
}
* V_141 = F_62 ( V_48 -> V_17 , V_49 ) ;
if ( * V_141 == NULL )
return - V_65 ;
}
if ( V_142 )
* V_142 = strlen ( V_48 -> V_17 ) ;
return 0 ;
}
static int F_63 ( struct V_39 * V_148 , struct V_26 * V_139 ,
struct V_39 * V_149 )
{
struct V_11 * V_48 ;
struct V_73 V_74 ;
int V_14 ;
F_25 ( & V_74 , V_85 , V_127 ) ;
F_45 ( & V_74 , V_148 ) ;
V_48 = F_9 ( V_148 -> V_115 ) ;
V_14 = F_46 ( V_48 , V_5 , & V_74 ) ;
V_14 = F_8 ( V_148 -> V_115 , V_5 , V_14 ) ;
if ( V_14 == 0 && V_149 -> V_115 != NULL ) {
V_48 = F_9 ( V_149 -> V_115 ) ;
F_45 ( & V_74 , V_149 ) ;
V_14 = F_46 ( V_48 , V_5 , & V_74 ) ;
V_14 = F_8 ( V_149 -> V_115 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_64 ( struct V_26 * V_139 , struct V_39 * V_39 )
{
struct V_26 * V_38 = V_39 -> V_115 ;
struct V_73 V_74 ;
int V_14 ;
F_25 ( & V_74 , V_85 , V_127 ) ;
F_45 ( & V_74 , V_39 ) ;
V_14 = F_46 ( F_9 ( V_38 ) , V_5 , & V_74 ) ;
V_14 = F_8 ( V_38 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_25 ( & V_74 , V_85 , V_150 ) ;
F_65 ( & V_74 , V_139 ) ;
V_14 = F_46 ( F_9 ( V_139 ) , V_5 , & V_74 ) ;
V_14 = F_8 ( V_139 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_66 ( struct V_26 * V_139 , struct V_39 * V_39 )
{
struct V_73 V_74 ;
int V_14 ;
F_25 ( & V_74 , V_85 , V_127 ) ;
F_45 ( & V_74 , V_39 ) ;
V_14 = F_46 ( F_9 ( V_39 -> V_115 ) , V_5 , & V_74 ) ;
V_14 = F_8 ( V_39 -> V_115 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_25 ( & V_74 , V_85 , V_150 ) ;
F_65 ( & V_74 , V_139 ) ;
V_14 = F_46 ( F_9 ( V_139 ) , V_5 , & V_74 ) ;
V_14 = F_8 ( V_139 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_67 ( struct V_26 * V_151 ,
struct V_39 * V_148 ,
struct V_26 * V_152 ,
struct V_39 * V_149 )
{
int V_14 ;
struct V_11 * V_48 ;
struct V_73 V_74 ;
F_25 ( & V_74 , V_85 , V_127 ) ;
F_45 ( & V_74 , V_148 ) ;
V_48 = F_9 ( V_148 -> V_115 ) ;
V_14 = F_46 ( V_48 , V_69 , & V_74 ) ;
V_14 = F_8 ( V_148 -> V_115 , V_69 , V_14 ) ;
if ( V_14 == 0 && V_149 -> V_115 != NULL ) {
V_48 = F_9 ( V_149 -> V_115 ) ;
F_45 ( & V_74 , V_149 ) ;
V_14 = F_46 ( V_48 , V_69 , & V_74 ) ;
V_14 = F_8 ( V_149 -> V_115 , V_69 , V_14 ) ;
}
return V_14 ;
}
static int F_68 ( struct V_26 * V_26 , int V_153 )
{
struct V_73 V_74 ;
int V_154 = V_153 & V_155 ;
int V_14 ;
V_153 &= ( V_4 | V_5 | V_6 | V_7 ) ;
if ( V_153 == 0 )
return 0 ;
if ( V_154 )
return - V_156 ;
F_25 ( & V_74 , V_85 , V_150 ) ;
F_65 ( & V_74 , V_26 ) ;
V_14 = F_46 ( F_9 ( V_26 ) , V_153 , & V_74 ) ;
V_14 = F_8 ( V_26 , V_153 , V_14 ) ;
return V_14 ;
}
static int F_69 ( struct V_39 * V_39 , struct V_157 * V_157 )
{
struct V_73 V_74 ;
int V_14 ;
if ( V_157 -> V_158 & V_159 )
return 0 ;
F_25 ( & V_74 , V_85 , V_127 ) ;
F_45 ( & V_74 , V_39 ) ;
V_14 = F_46 ( F_9 ( V_39 -> V_115 ) , V_5 , & V_74 ) ;
V_14 = F_8 ( V_39 -> V_115 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_70 ( struct V_160 * V_161 , struct V_39 * V_39 )
{
struct V_73 V_74 ;
struct V_162 V_162 ;
int V_14 ;
V_162 . V_39 = V_39 ;
V_162 . V_161 = V_161 ;
F_25 ( & V_74 , V_85 , V_163 ) ;
F_71 ( & V_74 , V_162 ) ;
V_14 = F_46 ( F_9 ( V_39 -> V_115 ) , V_4 , & V_74 ) ;
V_14 = F_8 ( V_39 -> V_115 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_72 ( struct V_39 * V_39 , const char * V_35 ,
const void * V_141 , T_2 V_164 , int V_111 )
{
struct V_73 V_74 ;
struct V_11 * V_42 ;
int V_165 = 0 ;
int V_166 = 0 ;
int V_167 = 0 ;
int V_14 = 0 ;
if ( strcmp ( V_35 , V_168 ) == 0 ||
strcmp ( V_35 , V_169 ) == 0 ||
strcmp ( V_35 , V_170 ) == 0 ) {
V_165 = 1 ;
V_166 = 1 ;
} else if ( strcmp ( V_35 , V_171 ) == 0 ||
strcmp ( V_35 , V_172 ) == 0 ) {
V_165 = 1 ;
V_166 = 1 ;
V_167 = 1 ;
} else if ( strcmp ( V_35 , V_173 ) == 0 ) {
V_165 = 1 ;
if ( V_164 != V_174 ||
strncmp ( V_141 , V_175 , V_174 ) != 0 )
V_14 = - V_176 ;
} else
V_14 = F_73 ( V_39 , V_35 , V_141 , V_164 , V_111 ) ;
if ( V_165 && ! F_37 ( V_121 ) )
V_14 = - V_122 ;
if ( V_14 == 0 && V_166 ) {
V_42 = V_164 ? F_14 ( V_141 , V_164 ) : NULL ;
if ( V_42 == NULL || ( V_167 &&
( V_42 == & V_177 || V_42 == & V_178 ) ) )
V_14 = - V_176 ;
}
F_25 ( & V_74 , V_85 , V_127 ) ;
F_45 ( & V_74 , V_39 ) ;
if ( V_14 == 0 ) {
V_14 = F_46 ( F_9 ( V_39 -> V_115 ) , V_5 , & V_74 ) ;
V_14 = F_8 ( V_39 -> V_115 , V_5 , V_14 ) ;
}
return V_14 ;
}
static void F_74 ( struct V_39 * V_39 , const char * V_35 ,
const void * V_141 , T_2 V_164 , int V_111 )
{
struct V_11 * V_42 ;
struct V_47 * V_48 = V_39 -> V_115 -> V_123 ;
if ( strcmp ( V_35 , V_173 ) == 0 ) {
V_48 -> V_51 |= V_124 ;
return;
}
if ( strcmp ( V_35 , V_168 ) == 0 ) {
V_42 = F_14 ( V_141 , V_164 ) ;
if ( V_42 != NULL )
V_48 -> V_50 = V_42 ;
else
V_48 -> V_50 = & V_179 ;
} else if ( strcmp ( V_35 , V_171 ) == 0 ) {
V_42 = F_14 ( V_141 , V_164 ) ;
if ( V_42 != NULL )
V_48 -> V_20 = V_42 ;
else
V_48 -> V_20 = & V_179 ;
} else if ( strcmp ( V_35 , V_172 ) == 0 ) {
V_42 = F_14 ( V_141 , V_164 ) ;
if ( V_42 != NULL )
V_48 -> V_180 = V_42 ;
else
V_48 -> V_180 = & V_179 ;
}
return;
}
static int F_75 ( struct V_39 * V_39 , const char * V_35 )
{
struct V_73 V_74 ;
int V_14 ;
F_25 ( & V_74 , V_85 , V_127 ) ;
F_45 ( & V_74 , V_39 ) ;
V_14 = F_46 ( F_9 ( V_39 -> V_115 ) , V_4 , & V_74 ) ;
V_14 = F_8 ( V_39 -> V_115 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_76 ( struct V_39 * V_39 , const char * V_35 )
{
struct V_47 * V_48 ;
struct V_73 V_74 ;
int V_14 = 0 ;
if ( strcmp ( V_35 , V_168 ) == 0 ||
strcmp ( V_35 , V_169 ) == 0 ||
strcmp ( V_35 , V_170 ) == 0 ||
strcmp ( V_35 , V_171 ) == 0 ||
strcmp ( V_35 , V_173 ) == 0 ||
strcmp ( V_35 , V_172 ) == 0 ) {
if ( ! F_37 ( V_121 ) )
V_14 = - V_122 ;
} else
V_14 = F_77 ( V_39 , V_35 ) ;
if ( V_14 != 0 )
return V_14 ;
F_25 ( & V_74 , V_85 , V_127 ) ;
F_45 ( & V_74 , V_39 ) ;
V_14 = F_46 ( F_9 ( V_39 -> V_115 ) , V_5 , & V_74 ) ;
V_14 = F_8 ( V_39 -> V_115 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_48 = V_39 -> V_115 -> V_123 ;
if ( strcmp ( V_35 , V_168 ) == 0 )
V_48 -> V_20 = NULL ;
else if ( strcmp ( V_35 , V_172 ) == 0 )
V_48 -> V_180 = NULL ;
else if ( strcmp ( V_35 , V_173 ) == 0 )
V_48 -> V_51 &= ~ V_124 ;
return 0 ;
}
static int F_78 ( const struct V_26 * V_26 ,
const char * V_35 , void * * V_41 ,
bool V_181 )
{
struct V_182 * V_183 ;
struct V_184 * V_185 ;
struct V_90 * V_125 ;
struct V_26 * V_38 = (struct V_26 * ) V_26 ;
struct V_11 * V_48 ;
int V_186 ;
int V_14 = 0 ;
if ( strcmp ( V_35 , V_146 ) == 0 ) {
V_48 = F_9 ( V_26 ) ;
V_186 = strlen ( V_48 -> V_17 ) ;
* V_41 = V_48 -> V_17 ;
return V_186 ;
}
V_125 = V_38 -> V_27 ;
if ( V_125 -> V_187 != V_188 )
return - V_189 ;
V_185 = F_79 ( V_38 ) ;
if ( V_185 == NULL || V_185 -> V_190 == NULL )
return - V_189 ;
V_183 = V_185 -> V_190 -> V_191 ;
if ( strcmp ( V_35 , V_192 ) == 0 )
V_48 = V_183 -> V_193 ;
else if ( strcmp ( V_35 , V_194 ) == 0 )
V_48 = V_183 -> V_195 ;
else
return - V_189 ;
V_186 = strlen ( V_48 -> V_17 ) ;
if ( V_14 == 0 ) {
* V_41 = V_48 -> V_17 ;
V_14 = V_186 ;
}
return V_14 ;
}
static int F_80 ( struct V_26 * V_26 , char * V_41 ,
T_2 V_196 )
{
int V_142 = sizeof( V_168 ) ;
if ( V_41 != NULL && V_142 <= V_196 )
memcpy ( V_41 , V_168 , V_142 ) ;
return V_142 ;
}
static void F_81 ( const struct V_26 * V_26 , T_3 * V_197 )
{
struct V_47 * V_48 = V_26 -> V_123 ;
* V_197 = V_48 -> V_50 -> V_198 ;
}
static int F_82 ( struct V_30 * V_30 , int V_153 )
{
return 0 ;
}
static int F_83 ( struct V_30 * V_30 )
{
struct V_11 * V_42 = F_36 () ;
V_30 -> V_32 = V_42 ;
return 0 ;
}
static void F_84 ( struct V_30 * V_30 )
{
V_30 -> V_32 = NULL ;
}
static int F_85 ( struct V_30 * V_30 , unsigned int V_199 ,
unsigned long V_200 )
{
int V_14 = 0 ;
struct V_73 V_74 ;
F_25 ( & V_74 , V_85 , V_163 ) ;
F_71 ( & V_74 , V_30 -> V_201 ) ;
if ( F_86 ( V_199 ) & V_202 ) {
V_14 = F_46 ( V_30 -> V_32 , V_5 , & V_74 ) ;
V_14 = F_10 ( V_30 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_86 ( V_199 ) & V_203 ) ) {
V_14 = F_46 ( V_30 -> V_32 , V_4 , & V_74 ) ;
V_14 = F_10 ( V_30 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_87 ( struct V_30 * V_30 , unsigned int V_199 )
{
struct V_73 V_74 ;
int V_14 ;
F_25 ( & V_74 , V_85 , V_163 ) ;
F_71 ( & V_74 , V_30 -> V_201 ) ;
V_14 = F_46 ( V_30 -> V_32 , V_9 , & V_74 ) ;
V_14 = F_10 ( V_30 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_88 ( struct V_30 * V_30 , unsigned int V_199 ,
unsigned long V_200 )
{
struct V_73 V_74 ;
int V_14 = 0 ;
switch ( V_199 ) {
case V_204 :
break;
case V_205 :
case V_206 :
F_25 ( & V_74 , V_85 , V_163 ) ;
F_71 ( & V_74 , V_30 -> V_201 ) ;
V_14 = F_46 ( V_30 -> V_32 , V_9 , & V_74 ) ;
V_14 = F_10 ( V_30 , V_9 , V_14 ) ;
break;
case V_207 :
case V_208 :
F_25 ( & V_74 , V_85 , V_163 ) ;
F_71 ( & V_74 , V_30 -> V_201 ) ;
V_14 = F_46 ( V_30 -> V_32 , V_5 , & V_74 ) ;
V_14 = F_10 ( V_30 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_89 ( struct V_30 * V_30 ,
unsigned long V_209 , unsigned long V_210 ,
unsigned long V_111 )
{
struct V_11 * V_42 ;
struct V_11 * V_211 ;
struct V_62 * V_212 ;
struct V_18 * V_19 ;
struct V_11 * V_213 ;
struct V_47 * V_48 ;
int V_145 ;
int V_214 ;
int V_215 ;
int V_14 ;
if ( V_30 == NULL )
return 0 ;
V_48 = F_48 ( V_30 ) -> V_123 ;
if ( V_48 -> V_180 == NULL )
return 0 ;
V_211 = V_48 -> V_180 ;
V_19 = F_5 () ;
V_42 = F_36 () ;
V_14 = 0 ;
F_50 () ;
F_21 (srp, &skp->smk_rules, list) {
V_213 = V_212 -> V_216 ;
if ( V_211 -> V_17 == V_213 -> V_17 )
continue;
V_145 = F_60 ( V_212 -> V_217 -> V_17 ,
V_213 -> V_17 ,
& V_19 -> V_57 ) ;
if ( V_145 == - V_218 )
V_145 = V_212 -> V_219 ;
else
V_145 &= V_212 -> V_219 ;
if ( V_145 == 0 )
continue;
V_214 = F_60 ( V_211 -> V_17 , V_213 -> V_17 ,
& V_211 -> V_57 ) ;
if ( V_214 == - V_218 ) {
V_14 = - V_82 ;
break;
}
V_215 = F_60 ( V_211 -> V_17 , V_213 -> V_17 ,
& V_19 -> V_57 ) ;
if ( V_215 != - V_218 )
V_214 &= V_215 ;
if ( ( V_145 | V_214 ) != V_214 ) {
V_14 = - V_82 ;
break;
}
}
F_53 () ;
return V_14 ;
}
static void F_90 ( struct V_30 * V_30 )
{
struct V_11 * V_42 = F_36 () ;
V_30 -> V_32 = V_42 ;
}
static int F_91 ( struct V_23 * V_220 ,
struct V_221 * V_222 , int V_223 )
{
struct V_11 * V_42 ;
struct V_11 * V_224 = F_27 ( V_220 -> V_36 -> V_37 ) ;
struct V_30 * V_30 ;
int V_14 ;
struct V_73 V_74 ;
V_30 = F_92 ( V_222 , struct V_30 , V_225 ) ;
V_42 = V_30 -> V_32 ;
V_14 = V_219 ( V_42 , V_224 , V_5 , NULL ) ;
V_14 = F_2 ( L_8 , V_42 , V_224 , V_5 , V_14 ) ;
if ( V_14 != 0 && F_93 ( V_220 , V_88 ) )
V_14 = 0 ;
F_25 ( & V_74 , V_85 , V_78 ) ;
F_26 ( & V_74 , V_220 ) ;
F_29 ( V_42 -> V_17 , V_224 -> V_17 , V_5 , V_14 , & V_74 ) ;
return V_14 ;
}
static int F_94 ( struct V_30 * V_30 )
{
int V_14 ;
int V_145 = 0 ;
struct V_73 V_74 ;
F_25 ( & V_74 , V_85 , V_163 ) ;
F_71 ( & V_74 , V_30 -> V_201 ) ;
if ( V_30 -> V_226 & V_227 )
V_145 = V_4 ;
if ( V_30 -> V_226 & V_228 )
V_145 |= V_5 ;
V_14 = F_46 ( V_30 -> V_32 , V_145 , & V_74 ) ;
V_14 = F_10 ( V_30 , V_145 , V_14 ) ;
return V_14 ;
}
static int F_95 ( struct V_30 * V_30 , const struct V_36 * V_36 )
{
struct V_18 * V_19 = V_36 -> V_37 ;
struct V_47 * V_48 = F_48 ( V_30 ) -> V_123 ;
struct V_73 V_74 ;
int V_14 ;
if ( F_37 ( V_88 ) ) {
V_30 -> V_32 = V_48 -> V_50 ;
return 0 ;
}
F_25 ( & V_74 , V_85 , V_163 ) ;
F_71 ( & V_74 , V_30 -> V_201 ) ;
V_14 = V_219 ( V_19 -> V_20 , V_48 -> V_50 , V_4 , & V_74 ) ;
V_14 = F_11 ( V_36 , V_30 , V_4 , V_14 ) ;
if ( V_14 == 0 )
V_30 -> V_32 = V_48 -> V_50 ;
return V_14 ;
}
static int F_96 ( struct V_36 * V_36 , T_1 V_55 )
{
struct V_18 * V_19 ;
V_19 = F_18 ( NULL , NULL , V_55 ) ;
if ( V_19 == NULL )
return - V_65 ;
V_36 -> V_37 = V_19 ;
return 0 ;
}
static void F_97 ( struct V_36 * V_36 )
{
struct V_18 * V_19 = V_36 -> V_37 ;
struct V_62 * V_229 ;
struct V_59 * V_230 ;
struct V_59 * V_231 ;
if ( V_19 == NULL )
return;
V_36 -> V_37 = NULL ;
F_98 (l, n, &tsp->smk_rules) {
V_229 = F_99 ( V_230 , struct V_62 , V_66 ) ;
F_100 ( & V_229 -> V_66 ) ;
F_15 ( V_229 ) ;
}
F_15 ( V_19 ) ;
}
static int F_101 ( struct V_36 * V_232 , const struct V_36 * V_233 ,
T_1 V_55 )
{
struct V_18 * V_234 = V_233 -> V_37 ;
struct V_18 * V_235 ;
int V_14 ;
V_235 = F_18 ( V_234 -> V_20 , V_234 -> V_20 , V_55 ) ;
if ( V_235 == NULL )
return - V_65 ;
V_14 = F_20 ( & V_235 -> V_57 , & V_234 -> V_57 , V_55 ) ;
if ( V_14 != 0 )
return V_14 ;
V_232 -> V_37 = V_235 ;
return 0 ;
}
static void F_102 ( struct V_36 * V_232 , const struct V_36 * V_233 )
{
struct V_18 * V_234 = V_233 -> V_37 ;
struct V_18 * V_235 = V_232 -> V_37 ;
V_235 -> V_20 = V_234 -> V_20 ;
V_235 -> V_56 = V_234 -> V_20 ;
F_17 ( & V_235 -> V_58 ) ;
F_19 ( & V_235 -> V_57 ) ;
}
static int F_103 ( struct V_36 * V_232 , T_3 V_197 )
{
struct V_18 * V_235 = V_232 -> V_37 ;
struct V_11 * V_42 = F_104 ( V_197 ) ;
if ( V_42 == NULL )
return - V_176 ;
V_235 -> V_20 = V_42 ;
return 0 ;
}
static int F_105 ( struct V_36 * V_232 ,
struct V_26 * V_26 )
{
struct V_47 * V_48 = V_26 -> V_123 ;
struct V_18 * V_19 = V_232 -> V_37 ;
V_19 -> V_56 = V_48 -> V_50 ;
V_19 -> V_20 = V_19 -> V_56 ;
return 0 ;
}
static int F_106 ( struct V_23 * V_236 , int V_237 ,
const char * V_238 )
{
struct V_73 V_74 ;
struct V_11 * V_42 = F_27 ( F_7 ( V_236 ) ) ;
int V_14 ;
F_25 ( & V_74 , V_238 , V_78 ) ;
F_26 ( & V_74 , V_236 ) ;
V_14 = F_46 ( V_42 , V_237 , & V_74 ) ;
V_14 = F_6 ( V_236 , V_237 , V_14 ) ;
return V_14 ;
}
static int F_107 ( struct V_23 * V_236 , T_4 V_239 )
{
return F_106 ( V_236 , V_5 , V_85 ) ;
}
static int F_108 ( struct V_23 * V_236 )
{
return F_106 ( V_236 , V_4 , V_85 ) ;
}
static int F_109 ( struct V_23 * V_236 )
{
return F_106 ( V_236 , V_4 , V_85 ) ;
}
static void F_110 ( struct V_23 * V_236 , T_3 * V_197 )
{
struct V_11 * V_42 = F_27 ( F_7 ( V_236 ) ) ;
* V_197 = V_42 -> V_198 ;
}
static int F_111 ( struct V_23 * V_236 , int V_240 )
{
int V_14 ;
V_14 = F_112 ( V_236 , V_240 ) ;
if ( V_14 == 0 )
V_14 = F_106 ( V_236 , V_5 , V_85 ) ;
return V_14 ;
}
static int F_113 ( struct V_23 * V_236 , int V_241 )
{
int V_14 ;
V_14 = F_114 ( V_236 , V_241 ) ;
if ( V_14 == 0 )
V_14 = F_106 ( V_236 , V_5 , V_85 ) ;
return V_14 ;
}
static int F_115 ( struct V_23 * V_236 )
{
return F_106 ( V_236 , V_4 , V_85 ) ;
}
static int F_116 ( struct V_23 * V_236 )
{
int V_14 ;
V_14 = F_117 ( V_236 ) ;
if ( V_14 == 0 )
V_14 = F_106 ( V_236 , V_5 , V_85 ) ;
return V_14 ;
}
static int F_118 ( struct V_23 * V_236 )
{
return F_106 ( V_236 , V_4 , V_85 ) ;
}
static int F_119 ( struct V_23 * V_236 )
{
return F_106 ( V_236 , V_5 , V_85 ) ;
}
static int F_120 ( struct V_23 * V_236 , struct V_242 * V_243 ,
int V_244 , T_3 V_197 )
{
struct V_73 V_74 ;
struct V_11 * V_42 ;
struct V_11 * V_224 = F_27 ( F_7 ( V_236 ) ) ;
int V_14 ;
F_25 ( & V_74 , V_85 , V_78 ) ;
F_26 ( & V_74 , V_236 ) ;
if ( V_197 == 0 ) {
V_14 = F_46 ( V_224 , V_5 , & V_74 ) ;
V_14 = F_6 ( V_236 , V_5 , V_14 ) ;
return V_14 ;
}
V_42 = F_104 ( V_197 ) ;
V_14 = V_219 ( V_42 , V_224 , V_5 , & V_74 ) ;
V_14 = F_2 ( L_9 , V_42 , V_224 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_121 ( struct V_23 * V_236 )
{
return 0 ;
}
static void F_122 ( struct V_23 * V_236 , struct V_26 * V_26 )
{
struct V_47 * V_48 = V_26 -> V_123 ;
struct V_11 * V_42 = F_27 ( F_7 ( V_236 ) ) ;
V_48 -> V_50 = V_42 ;
}
static int F_123 ( struct V_185 * V_190 , int V_245 , T_1 V_246 )
{
struct V_11 * V_42 = F_36 () ;
struct V_182 * V_183 ;
V_183 = F_13 ( sizeof( struct V_182 ) , V_246 ) ;
if ( V_183 == NULL )
return - V_65 ;
V_183 -> V_193 = V_42 ;
V_183 -> V_195 = V_42 ;
V_183 -> V_247 = NULL ;
V_190 -> V_191 = V_183 ;
return 0 ;
}
static void F_124 ( struct V_185 * V_190 )
{
F_15 ( V_190 -> V_191 ) ;
}
static struct V_11 * F_125 ( struct V_248 * V_249 )
{
struct V_250 * V_251 ;
struct V_252 * V_253 = & V_249 -> V_254 ;
if ( V_253 -> V_255 == 0 )
return NULL ;
F_21 (snp, &smk_netlbladdr_list, list)
if ( ( & V_251 -> V_256 . V_254 ) -> V_255 ==
( V_253 -> V_255 & ( & V_251 -> V_257 ) -> V_255 ) ) {
if ( V_251 -> V_258 == & V_259 )
return NULL ;
return V_251 -> V_258 ;
}
return NULL ;
}
static int F_126 ( struct V_185 * V_190 , int V_260 )
{
struct V_11 * V_42 ;
struct V_182 * V_183 = V_190 -> V_191 ;
int V_14 = 0 ;
F_127 () ;
F_128 ( V_190 ) ;
if ( V_183 -> V_195 == V_261 ||
V_260 == V_262 )
F_129 ( V_190 ) ;
else {
V_42 = V_183 -> V_195 ;
V_14 = F_130 ( V_190 , V_190 -> V_263 , & V_42 -> V_264 ) ;
}
F_131 ( V_190 ) ;
F_132 () ;
return V_14 ;
}
static int F_133 ( struct V_185 * V_190 , struct V_248 * V_265 )
{
struct V_11 * V_42 ;
int V_14 ;
int V_266 ;
struct V_11 * V_267 ;
struct V_182 * V_183 = V_190 -> V_191 ;
struct V_73 V_74 ;
F_50 () ;
V_267 = F_125 ( V_265 ) ;
if ( V_267 != NULL ) {
#ifdef F_134
struct V_268 V_269 ;
F_135 ( & V_74 , V_85 , V_270 , & V_269 ) ;
V_74 . V_271 . V_272 . V_269 -> V_245 = V_265 -> V_273 ;
V_74 . V_271 . V_272 . V_269 -> V_274 = V_265 -> V_275 ;
V_74 . V_271 . V_272 . V_269 -> V_276 . V_277 = V_265 -> V_254 . V_255 ;
#endif
V_266 = V_262 ;
V_42 = V_183 -> V_195 ;
V_14 = V_219 ( V_42 , V_267 , V_5 , & V_74 ) ;
V_14 = F_2 ( L_10 , V_42 , V_267 , V_5 , V_14 ) ;
} else {
V_266 = V_278 ;
V_14 = 0 ;
}
F_53 () ;
if ( V_14 != 0 )
return V_14 ;
return F_126 ( V_190 , V_266 ) ;
}
static void F_136 ( struct V_184 * V_185 , struct V_279 * V_280 )
{
struct V_185 * V_190 = V_185 -> V_190 ;
struct V_281 * V_282 ;
struct V_182 * V_183 = V_185 -> V_190 -> V_191 ;
struct V_283 * V_284 ;
unsigned short V_285 = 0 ;
if ( V_280 == NULL ) {
F_137 (spp, &smk_ipv6_port_list, list) {
if ( V_190 != V_284 -> V_286 )
continue;
V_284 -> V_193 = V_183 -> V_193 ;
V_284 -> V_195 = V_183 -> V_195 ;
return;
}
return;
}
V_282 = (struct V_281 * ) V_280 ;
V_285 = F_138 ( V_282 -> V_287 ) ;
if ( V_285 == 0 )
return;
F_137 (spp, &smk_ipv6_port_list, list) {
if ( V_284 -> V_288 != V_285 )
continue;
V_284 -> V_288 = V_285 ;
V_284 -> V_286 = V_190 ;
V_284 -> V_193 = V_183 -> V_193 ;
V_284 -> V_195 = V_183 -> V_195 ;
return;
}
V_284 = F_13 ( sizeof( * V_284 ) , V_46 ) ;
if ( V_284 == NULL )
return;
V_284 -> V_288 = V_285 ;
V_284 -> V_286 = V_190 ;
V_284 -> V_193 = V_183 -> V_193 ;
V_284 -> V_195 = V_183 -> V_195 ;
F_139 ( & V_284 -> V_66 , & V_289 ) ;
return;
}
static int F_140 ( struct V_185 * V_190 , struct V_281 * V_280 ,
int V_290 )
{
T_5 * V_291 ;
T_6 * V_292 ;
struct V_283 * V_284 ;
struct V_182 * V_183 = V_190 -> V_191 ;
struct V_11 * V_42 ;
unsigned short V_285 = 0 ;
struct V_11 * V_293 ;
struct V_73 V_74 ;
int V_14 ;
#ifdef F_134
struct V_268 V_269 ;
#endif
if ( V_290 == V_294 ) {
V_42 = V_261 ;
V_293 = V_183 -> V_193 ;
} else {
V_42 = V_183 -> V_195 ;
V_293 = V_261 ;
}
V_285 = F_138 ( V_280 -> V_287 ) ;
V_291 = ( T_5 * ) ( & V_280 -> V_295 ) ;
V_292 = ( T_6 * ) ( & V_280 -> V_295 ) ;
if ( V_292 [ 0 ] || V_292 [ 1 ] || V_292 [ 2 ] || V_291 [ 6 ] || F_138 ( V_291 [ 7 ] ) != 1 )
goto V_296;
if ( V_290 == V_294 ) {
V_42 = & V_178 ;
goto V_296;
}
F_137 (spp, &smk_ipv6_port_list, list) {
if ( V_284 -> V_288 != V_285 )
continue;
V_293 = V_284 -> V_193 ;
if ( V_290 == V_297 )
V_183 -> V_247 = V_284 -> V_195 ;
break;
}
V_296:
#ifdef F_134
F_135 ( & V_74 , V_85 , V_270 , & V_269 ) ;
V_74 . V_271 . V_272 . V_269 -> V_245 = V_190 -> V_263 ;
V_74 . V_271 . V_272 . V_269 -> V_274 = V_285 ;
if ( V_290 == V_294 )
V_74 . V_271 . V_272 . V_269 -> V_298 . V_299 = V_280 -> V_295 ;
else
V_74 . V_271 . V_272 . V_269 -> V_298 . V_277 = V_280 -> V_295 ;
#endif
V_14 = V_219 ( V_42 , V_293 , V_5 , & V_74 ) ;
V_14 = F_2 ( L_11 , V_42 , V_293 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_141 ( struct V_26 * V_26 , const char * V_35 ,
const void * V_141 , T_2 V_164 , int V_111 )
{
struct V_11 * V_42 ;
struct V_47 * V_300 = V_26 -> V_123 ;
struct V_182 * V_183 ;
struct V_184 * V_185 ;
int V_14 = 0 ;
if ( V_141 == NULL || V_164 > V_45 || V_164 == 0 )
return - V_176 ;
V_42 = F_14 ( V_141 , V_164 ) ;
if ( V_42 == NULL )
return - V_176 ;
if ( strcmp ( V_35 , V_146 ) == 0 ) {
V_300 -> V_50 = V_42 ;
V_300 -> V_51 |= V_301 ;
return 0 ;
}
if ( V_26 -> V_27 -> V_187 != V_188 )
return - V_189 ;
V_185 = F_79 ( V_26 ) ;
if ( V_185 == NULL || V_185 -> V_190 == NULL )
return - V_189 ;
V_183 = V_185 -> V_190 -> V_191 ;
if ( strcmp ( V_35 , V_192 ) == 0 )
V_183 -> V_193 = V_42 ;
else if ( strcmp ( V_35 , V_194 ) == 0 ) {
V_183 -> V_195 = V_42 ;
if ( V_185 -> V_190 -> V_263 == V_302 ) {
V_14 = F_126 ( V_185 -> V_190 , V_278 ) ;
if ( V_14 != 0 )
F_142 ( V_303
L_12 ,
V_85 , - V_14 ) ;
}
} else
return - V_189 ;
if ( V_185 -> V_190 -> V_263 == V_304 )
F_136 ( V_185 , NULL ) ;
return 0 ;
}
static int F_143 ( struct V_184 * V_185 , int V_245 ,
int type , int V_305 , int V_306 )
{
if ( V_245 != V_302 || V_185 -> V_190 == NULL )
return 0 ;
return F_126 ( V_185 -> V_190 , V_278 ) ;
}
static int F_144 ( struct V_184 * V_185 , struct V_279 * V_280 ,
int V_307 )
{
if ( V_185 -> V_190 != NULL && V_185 -> V_190 -> V_263 == V_304 )
F_136 ( V_185 , V_280 ) ;
return 0 ;
}
static int F_145 ( struct V_184 * V_185 , struct V_279 * V_265 ,
int V_307 )
{
int V_14 = 0 ;
if ( V_185 -> V_190 == NULL )
return 0 ;
switch ( V_185 -> V_190 -> V_263 ) {
case V_302 :
if ( V_307 < sizeof( struct V_248 ) )
return - V_176 ;
V_14 = F_133 ( V_185 -> V_190 , (struct V_248 * ) V_265 ) ;
break;
case V_304 :
if ( V_307 < sizeof( struct V_281 ) )
return - V_176 ;
V_14 = F_140 ( V_185 -> V_190 , (struct V_281 * ) V_265 ,
V_297 ) ;
break;
}
return V_14 ;
}
static int F_146 ( int V_111 )
{
int V_145 = 0 ;
if ( V_111 & V_308 )
V_145 |= V_4 ;
if ( V_111 & V_309 )
V_145 |= V_5 ;
if ( V_111 & V_310 )
V_145 |= V_6 ;
return V_145 ;
}
static int F_147 ( struct V_311 * V_312 )
{
struct V_11 * V_42 = F_36 () ;
V_312 -> V_37 = V_42 ;
return 0 ;
}
static void F_148 ( struct V_311 * V_312 )
{
V_312 -> V_37 = NULL ;
}
static struct V_11 * F_149 ( struct V_313 * V_314 )
{
return (struct V_11 * ) V_314 -> V_315 . V_37 ;
}
static int F_150 ( struct V_313 * V_314 )
{
struct V_316 * V_48 = & V_314 -> V_315 ;
struct V_11 * V_42 = F_36 () ;
V_48 -> V_37 = V_42 ;
return 0 ;
}
static void F_151 ( struct V_313 * V_314 )
{
struct V_316 * V_48 = & V_314 -> V_315 ;
V_48 -> V_37 = NULL ;
}
static int F_152 ( struct V_313 * V_314 , int V_237 )
{
struct V_11 * V_183 = F_149 ( V_314 ) ;
struct V_73 V_74 ;
int V_14 ;
#ifdef F_134
F_25 ( & V_74 , V_85 , V_317 ) ;
V_74 . V_271 . V_272 . V_318 = V_314 -> V_315 . V_319 ;
#endif
V_14 = F_46 ( V_183 , V_237 , & V_74 ) ;
V_14 = F_4 ( L_13 , V_183 , V_237 , V_14 ) ;
return V_14 ;
}
static int F_153 ( struct V_313 * V_314 , int V_320 )
{
int V_145 ;
V_145 = F_146 ( V_320 ) ;
return F_152 ( V_314 , V_145 ) ;
}
static int F_154 ( struct V_313 * V_314 , int V_199 )
{
int V_145 ;
switch ( V_199 ) {
case V_321 :
case V_322 :
V_145 = V_4 ;
break;
case V_323 :
case V_324 :
case V_325 :
case V_326 :
V_145 = V_69 ;
break;
case V_327 :
case V_328 :
return 0 ;
default:
return - V_176 ;
}
return F_152 ( V_314 , V_145 ) ;
}
static int F_155 ( struct V_313 * V_314 , char T_7 * V_329 ,
int V_320 )
{
int V_145 ;
V_145 = F_146 ( V_320 ) ;
return F_152 ( V_314 , V_145 ) ;
}
static struct V_11 * F_156 ( struct V_330 * V_331 )
{
return (struct V_11 * ) V_331 -> V_332 . V_37 ;
}
static int F_157 ( struct V_330 * V_331 )
{
struct V_316 * V_48 = & V_331 -> V_332 ;
struct V_11 * V_42 = F_36 () ;
V_48 -> V_37 = V_42 ;
return 0 ;
}
static void F_158 ( struct V_330 * V_331 )
{
struct V_316 * V_48 = & V_331 -> V_332 ;
V_48 -> V_37 = NULL ;
}
static int F_159 ( struct V_330 * V_331 , int V_237 )
{
struct V_11 * V_183 = F_156 ( V_331 ) ;
struct V_73 V_74 ;
int V_14 ;
#ifdef F_134
F_25 ( & V_74 , V_85 , V_317 ) ;
V_74 . V_271 . V_272 . V_318 = V_331 -> V_332 . V_319 ;
#endif
V_14 = F_46 ( V_183 , V_237 , & V_74 ) ;
V_14 = F_4 ( L_14 , V_183 , V_237 , V_14 ) ;
return V_14 ;
}
static int F_160 ( struct V_330 * V_331 , int V_333 )
{
int V_145 ;
V_145 = F_146 ( V_333 ) ;
return F_159 ( V_331 , V_145 ) ;
}
static int F_161 ( struct V_330 * V_331 , int V_199 )
{
int V_145 ;
switch ( V_199 ) {
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_321 :
case V_339 :
V_145 = V_4 ;
break;
case V_340 :
case V_341 :
case V_326 :
case V_323 :
V_145 = V_69 ;
break;
case V_327 :
case V_342 :
return 0 ;
default:
return - V_176 ;
}
return F_159 ( V_331 , V_145 ) ;
}
static int F_162 ( struct V_330 * V_331 , struct V_343 * V_344 ,
unsigned V_345 , int V_346 )
{
return F_159 ( V_331 , V_69 ) ;
}
static int F_163 ( struct V_347 * V_348 )
{
struct V_316 * V_349 = & V_348 -> V_350 ;
struct V_11 * V_42 = F_36 () ;
V_349 -> V_37 = V_42 ;
return 0 ;
}
static void F_164 ( struct V_347 * V_348 )
{
struct V_316 * V_349 = & V_348 -> V_350 ;
V_349 -> V_37 = NULL ;
}
static struct V_11 * F_165 ( struct V_347 * V_348 )
{
return (struct V_11 * ) V_348 -> V_350 . V_37 ;
}
static int F_166 ( struct V_347 * V_348 , int V_237 )
{
struct V_11 * V_351 = F_165 ( V_348 ) ;
struct V_73 V_74 ;
int V_14 ;
#ifdef F_134
F_25 ( & V_74 , V_85 , V_317 ) ;
V_74 . V_271 . V_272 . V_318 = V_348 -> V_350 . V_319 ;
#endif
V_14 = F_46 ( V_351 , V_237 , & V_74 ) ;
V_14 = F_4 ( L_15 , V_351 , V_237 , V_14 ) ;
return V_14 ;
}
static int F_167 ( struct V_347 * V_348 , int V_352 )
{
int V_145 ;
V_145 = F_146 ( V_352 ) ;
return F_166 ( V_348 , V_145 ) ;
}
static int F_168 ( struct V_347 * V_348 , int V_199 )
{
int V_145 ;
switch ( V_199 ) {
case V_321 :
case V_353 :
V_145 = V_4 ;
break;
case V_323 :
case V_326 :
V_145 = V_69 ;
break;
case V_327 :
case V_354 :
return 0 ;
default:
return - V_176 ;
}
return F_166 ( V_348 , V_145 ) ;
}
static int F_169 ( struct V_347 * V_348 , struct V_311 * V_312 ,
int V_352 )
{
int V_145 ;
V_145 = F_146 ( V_352 ) ;
return F_166 ( V_348 , V_145 ) ;
}
static int F_170 ( struct V_347 * V_348 , struct V_311 * V_312 ,
struct V_23 * V_355 , long type , int V_1 )
{
return F_166 ( V_348 , V_69 ) ;
}
static int F_171 ( struct V_316 * V_356 , short V_357 )
{
struct V_11 * V_358 = V_356 -> V_37 ;
int V_145 = F_146 ( V_357 ) ;
struct V_73 V_74 ;
int V_14 ;
#ifdef F_134
F_25 ( & V_74 , V_85 , V_317 ) ;
V_74 . V_271 . V_272 . V_318 = V_356 -> V_319 ;
#endif
V_14 = F_46 ( V_358 , V_145 , & V_74 ) ;
V_14 = F_4 ( L_16 , V_358 , V_145 , V_14 ) ;
return V_14 ;
}
static void F_172 ( struct V_316 * V_356 , T_3 * V_197 )
{
struct V_11 * V_358 = V_356 -> V_37 ;
* V_197 = V_358 -> V_198 ;
}
static void F_173 ( struct V_39 * V_359 , struct V_26 * V_26 )
{
struct V_90 * V_125 ;
struct V_92 * V_93 ;
struct V_47 * V_48 ;
struct V_11 * V_42 ;
struct V_11 * V_360 = F_36 () ;
struct V_11 * V_361 ;
char V_362 [ V_174 ] ;
int V_363 = 0 ;
int V_14 ;
struct V_39 * V_40 ;
if ( V_26 == NULL )
return;
V_48 = V_26 -> V_123 ;
F_174 ( & V_48 -> V_52 ) ;
if ( V_48 -> V_51 & V_301 )
goto V_364;
V_125 = V_26 -> V_27 ;
V_93 = V_125 -> V_100 ;
V_361 = V_93 -> V_96 ;
if ( V_359 -> V_365 == V_359 ) {
if ( V_125 -> V_187 == V_366 ) {
V_93 -> V_94 = & V_177 ;
V_93 -> V_96 = & V_177 ;
}
V_48 -> V_50 = V_93 -> V_94 ;
V_48 -> V_51 |= V_301 ;
goto V_364;
}
switch ( V_125 -> V_187 ) {
case V_367 :
case V_368 :
case V_188 :
case V_366 :
V_361 = & V_177 ;
break;
case V_369 :
V_361 = V_360 ;
break;
case V_370 :
break;
case V_371 :
V_361 = & V_177 ;
default:
if ( F_175 ( V_26 -> V_372 ) ) {
V_361 = & V_177 ;
break;
}
if ( V_26 -> V_43 -> V_44 == NULL )
break;
V_40 = F_176 ( V_359 ) ;
V_42 = F_12 ( V_168 , V_26 , V_40 ) ;
if ( V_42 != NULL )
V_361 = V_42 ;
if ( F_177 ( V_26 -> V_372 ) ) {
if ( V_48 -> V_51 & V_147 ) {
V_48 -> V_51 &= ~ V_147 ;
V_14 = V_26 -> V_43 -> V_373 ( V_40 ,
V_173 ,
V_175 , V_174 ,
0 ) ;
} else {
V_14 = V_26 -> V_43 -> V_44 ( V_40 ,
V_173 , V_362 ,
V_174 ) ;
if ( V_14 >= 0 && strncmp ( V_362 , V_175 ,
V_174 ) != 0 )
V_14 = - V_176 ;
}
if ( V_14 >= 0 )
V_363 = V_124 ;
}
V_42 = F_12 ( V_171 , V_26 , V_40 ) ;
if ( V_42 == & V_177 || V_42 == & V_178 )
V_42 = NULL ;
V_48 -> V_20 = V_42 ;
V_42 = F_12 ( V_172 , V_26 , V_40 ) ;
if ( V_42 == & V_177 || V_42 == & V_178 )
V_42 = NULL ;
V_48 -> V_180 = V_42 ;
F_178 ( V_40 ) ;
break;
}
if ( V_361 == NULL )
V_48 -> V_50 = V_360 ;
else
V_48 -> V_50 = V_361 ;
V_48 -> V_51 |= ( V_301 | V_363 ) ;
V_364:
F_179 ( & V_48 -> V_52 ) ;
return;
}
static int F_180 ( struct V_23 * V_236 , char * V_35 , char * * V_141 )
{
struct V_11 * V_42 = F_27 ( F_7 ( V_236 ) ) ;
char * V_103 ;
int V_374 ;
if ( strcmp ( V_35 , L_17 ) != 0 )
return - V_176 ;
V_103 = F_62 ( V_42 -> V_17 , V_46 ) ;
if ( V_103 == NULL )
return - V_65 ;
V_374 = strlen ( V_103 ) ;
* V_141 = V_103 ;
return V_374 ;
}
static int F_181 ( struct V_23 * V_236 , char * V_35 ,
void * V_141 , T_2 V_164 )
{
struct V_18 * V_19 ;
struct V_36 * V_232 ;
struct V_11 * V_42 ;
if ( V_236 != V_21 )
return - V_122 ;
if ( ! F_37 ( V_121 ) )
return - V_122 ;
if ( V_141 == NULL || V_164 == 0 || V_164 >= V_45 )
return - V_176 ;
if ( strcmp ( V_35 , L_17 ) != 0 )
return - V_176 ;
V_42 = F_14 ( V_141 , V_164 ) ;
if ( V_42 == NULL )
return - V_176 ;
if ( V_42 == & V_178 )
return - V_122 ;
V_232 = F_182 () ;
if ( V_232 == NULL )
return - V_65 ;
V_19 = V_232 -> V_37 ;
V_19 -> V_20 = V_42 ;
F_183 ( V_232 ) ;
return V_164 ;
}
static int F_184 ( struct V_185 * V_185 ,
struct V_185 * V_375 , struct V_185 * V_376 )
{
struct V_11 * V_42 ;
struct V_11 * V_213 ;
struct V_182 * V_183 = V_185 -> V_191 ;
struct V_182 * V_377 = V_375 -> V_191 ;
struct V_182 * V_300 = V_376 -> V_191 ;
struct V_73 V_74 ;
int V_14 = 0 ;
#ifdef F_134
struct V_268 V_269 ;
#endif
if ( ! F_37 ( V_88 ) ) {
V_42 = V_183 -> V_195 ;
V_213 = V_377 -> V_195 ;
#ifdef F_134
F_135 ( & V_74 , V_85 , V_270 , & V_269 ) ;
F_185 ( & V_74 , V_375 ) ;
#endif
V_14 = V_219 ( V_42 , V_213 , V_5 , & V_74 ) ;
V_14 = F_2 ( L_18 , V_42 , V_213 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_14 = V_219 ( V_213 , V_42 , V_5 , NULL ) ;
V_14 = F_2 ( L_18 , V_213 , V_42 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_300 -> V_247 = V_183 -> V_195 ;
V_183 -> V_247 = V_377 -> V_195 ;
}
return V_14 ;
}
static int F_186 ( struct V_184 * V_185 , struct V_184 * V_375 )
{
struct V_182 * V_183 = V_185 -> V_190 -> V_191 ;
struct V_182 * V_377 = V_375 -> V_190 -> V_191 ;
struct V_73 V_74 ;
int V_14 ;
#ifdef F_134
struct V_268 V_269 ;
F_135 ( & V_74 , V_85 , V_270 , & V_269 ) ;
F_185 ( & V_74 , V_375 -> V_190 ) ;
#endif
if ( F_37 ( V_88 ) )
return 0 ;
V_14 = V_219 ( V_183 -> V_195 , V_377 -> V_193 , V_5 , & V_74 ) ;
V_14 = F_2 ( L_19 , V_183 -> V_195 , V_377 -> V_193 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_187 ( struct V_184 * V_185 , struct V_378 * V_312 ,
int V_164 )
{
struct V_248 * V_249 = (struct V_248 * ) V_312 -> V_379 ;
struct V_281 * V_265 = (struct V_281 * ) V_312 -> V_379 ;
int V_14 = 0 ;
if ( V_249 == NULL )
return 0 ;
switch ( V_249 -> V_273 ) {
case V_380 :
V_14 = F_133 ( V_185 -> V_190 , V_249 ) ;
break;
case V_381 :
V_14 = F_140 ( V_185 -> V_190 , V_265 , V_382 ) ;
break;
}
return V_14 ;
}
static struct V_11 * F_188 ( struct V_383 * V_265 ,
struct V_182 * V_183 )
{
struct V_11 * V_42 ;
int V_384 = 0 ;
int V_385 ;
int V_386 ;
if ( ( V_265 -> V_111 & V_387 ) != 0 ) {
F_50 () ;
F_137 (skp, &smack_known_list, list) {
if ( V_265 -> V_388 . V_389 . V_390 != V_42 -> V_264 . V_388 . V_389 . V_390 )
continue;
if ( ( V_265 -> V_111 & V_391 ) == 0 ) {
if ( ( V_42 -> V_264 . V_111 &
V_391 ) == 0 )
V_384 = 1 ;
break;
}
for ( V_385 = - 1 , V_386 = - 1 ; V_385 == V_386 ; ) {
V_385 = F_189 ( V_265 -> V_388 . V_389 . V_392 ,
V_385 + 1 ) ;
V_386 = F_189 (
V_42 -> V_264 . V_388 . V_389 . V_392 ,
V_386 + 1 ) ;
if ( V_385 < 0 || V_386 < 0 )
break;
}
if ( V_385 == V_386 ) {
V_384 = 1 ;
break;
}
}
F_53 () ;
if ( V_384 )
return V_42 ;
if ( V_183 != NULL && V_183 -> V_193 == & V_177 )
return & V_178 ;
return & V_177 ;
}
if ( ( V_265 -> V_111 & V_393 ) != 0 ) {
V_42 = F_104 ( V_265 -> V_388 . V_197 ) ;
F_190 ( V_42 == NULL ) ;
return V_42 ;
}
return V_261 ;
}
static int F_191 ( struct V_394 * V_395 , struct V_281 * V_249 )
{
T_8 V_396 ;
int V_397 ;
int V_398 = - V_176 ;
struct V_399 V_400 ;
struct V_399 * V_401 ;
T_5 V_402 ;
struct V_403 V_404 , * V_405 ;
struct V_406 V_407 , * V_408 ;
struct V_409 V_410 , * V_411 ;
V_249 -> V_287 = 0 ;
V_397 = F_192 ( V_395 ) ;
V_401 = F_193 ( V_395 , V_397 , sizeof( V_400 ) , & V_400 ) ;
if ( V_401 == NULL )
return - V_176 ;
V_249 -> V_295 = V_401 -> V_299 ;
V_396 = V_401 -> V_396 ;
V_397 += sizeof( V_400 ) ;
V_397 = F_194 ( V_395 , V_397 , & V_396 , & V_402 ) ;
if ( V_397 < 0 )
return - V_176 ;
V_398 = V_396 ;
switch ( V_398 ) {
case V_412 :
V_405 = F_193 ( V_395 , V_397 , sizeof( V_404 ) , & V_404 ) ;
if ( V_405 != NULL )
V_249 -> V_287 = V_405 -> V_413 ;
break;
case V_414 :
V_408 = F_193 ( V_395 , V_397 , sizeof( V_407 ) , & V_407 ) ;
if ( V_408 != NULL )
V_249 -> V_287 = V_408 -> V_413 ;
break;
case V_415 :
V_411 = F_193 ( V_395 , V_397 , sizeof( V_410 ) , & V_410 ) ;
if ( V_411 != NULL )
V_249 -> V_287 = V_411 -> V_416 ;
break;
}
return V_398 ;
}
static int F_195 ( struct V_185 * V_190 , struct V_394 * V_395 )
{
struct V_383 V_417 ;
struct V_182 * V_183 = V_190 -> V_191 ;
struct V_11 * V_42 ;
struct V_281 V_418 ;
int V_14 = 0 ;
struct V_73 V_74 ;
#ifdef F_134
struct V_268 V_269 ;
#endif
switch ( V_190 -> V_263 ) {
case V_302 :
F_196 ( & V_417 ) ;
V_14 = F_197 ( V_395 , V_190 -> V_263 , & V_417 ) ;
if ( V_14 == 0 )
V_42 = F_188 ( & V_417 , V_183 ) ;
else
V_42 = V_261 ;
F_198 ( & V_417 ) ;
#ifdef F_134
F_135 ( & V_74 , V_85 , V_270 , & V_269 ) ;
V_74 . V_271 . V_272 . V_269 -> V_245 = V_190 -> V_263 ;
V_74 . V_271 . V_272 . V_269 -> V_419 = V_395 -> V_420 ;
F_199 ( V_395 , & V_74 . V_271 , NULL ) ;
#endif
V_14 = V_219 ( V_42 , V_183 -> V_193 , V_5 , & V_74 ) ;
V_14 = F_2 ( L_20 , V_42 , V_183 -> V_193 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_200 ( V_395 , V_14 , 0 ) ;
break;
case V_304 :
V_14 = F_191 ( V_395 , & V_418 ) ;
if ( V_14 == V_414 || V_14 == V_412 )
V_14 = F_140 ( V_190 , & V_418 , V_294 ) ;
else
V_14 = 0 ;
break;
}
return V_14 ;
}
static int F_201 ( struct V_184 * V_185 ,
char T_7 * V_421 ,
int T_7 * V_422 , unsigned V_142 )
{
struct V_182 * V_183 ;
char * V_423 = L_21 ;
int V_374 = 1 ;
int V_14 = 0 ;
V_183 = V_185 -> V_190 -> V_191 ;
if ( V_183 -> V_247 != NULL ) {
V_423 = V_183 -> V_247 -> V_17 ;
V_374 = strlen ( V_423 ) + 1 ;
}
if ( V_374 > V_142 )
V_14 = - V_424 ;
else if ( F_202 ( V_421 , V_423 , V_374 ) != 0 )
V_14 = - V_425 ;
if ( F_203 ( V_374 , V_422 ) != 0 )
V_14 = - V_425 ;
return V_14 ;
}
static int F_204 ( struct V_184 * V_185 ,
struct V_394 * V_395 , T_3 * V_197 )
{
struct V_383 V_417 ;
struct V_182 * V_183 = NULL ;
struct V_11 * V_42 ;
int V_245 = V_426 ;
T_3 V_2 = 0 ;
int V_14 ;
if ( V_395 != NULL ) {
if ( V_395 -> V_305 == F_205 ( V_427 ) )
V_245 = V_302 ;
else if ( V_395 -> V_305 == F_205 ( V_428 ) )
V_245 = V_304 ;
}
if ( V_245 == V_426 && V_185 != NULL )
V_245 = V_185 -> V_190 -> V_263 ;
if ( V_245 == V_429 ) {
V_183 = V_185 -> V_190 -> V_191 ;
V_2 = V_183 -> V_195 -> V_198 ;
} else if ( V_245 == V_302 || V_245 == V_304 ) {
if ( V_185 != NULL && V_185 -> V_190 != NULL )
V_183 = V_185 -> V_190 -> V_191 ;
F_196 ( & V_417 ) ;
V_14 = F_197 ( V_395 , V_245 , & V_417 ) ;
if ( V_14 == 0 ) {
V_42 = F_188 ( & V_417 , V_183 ) ;
V_2 = V_42 -> V_198 ;
}
F_198 ( & V_417 ) ;
}
* V_197 = V_2 ;
if ( V_2 == 0 )
return - V_176 ;
return 0 ;
}
static void F_206 ( struct V_185 * V_190 , struct V_184 * V_430 )
{
struct V_182 * V_183 ;
struct V_11 * V_42 = F_36 () ;
if ( V_190 == NULL ||
( V_190 -> V_263 != V_302 && V_190 -> V_263 != V_304 ) )
return;
V_183 = V_190 -> V_191 ;
V_183 -> V_193 = V_42 ;
V_183 -> V_195 = V_42 ;
}
static int F_207 ( struct V_185 * V_190 , struct V_394 * V_395 ,
struct V_431 * V_432 )
{
T_9 V_245 = V_190 -> V_263 ;
struct V_11 * V_42 ;
struct V_182 * V_183 = V_190 -> V_191 ;
struct V_383 V_417 ;
struct V_248 V_433 ;
struct V_434 * V_435 ;
struct V_11 * V_436 ;
int V_14 ;
struct V_73 V_74 ;
#ifdef F_134
struct V_268 V_269 ;
#endif
if ( V_245 == V_304 ) {
if ( V_395 -> V_305 == F_205 ( V_427 ) )
V_245 = V_302 ;
else
return 0 ;
}
F_196 ( & V_417 ) ;
V_14 = F_197 ( V_395 , V_245 , & V_417 ) ;
if ( V_14 == 0 )
V_42 = F_188 ( & V_417 , V_183 ) ;
else
V_42 = & V_437 ;
F_198 ( & V_417 ) ;
#ifdef F_134
F_135 ( & V_74 , V_85 , V_270 , & V_269 ) ;
V_74 . V_271 . V_272 . V_269 -> V_245 = V_245 ;
V_74 . V_271 . V_272 . V_269 -> V_419 = V_395 -> V_420 ;
F_199 ( V_395 , & V_74 . V_271 , NULL ) ;
#endif
V_14 = V_219 ( V_42 , V_183 -> V_193 , V_5 , & V_74 ) ;
V_14 = F_2 ( L_22 , V_42 , V_183 -> V_193 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_432 -> V_438 = V_42 -> V_198 ;
V_435 = F_208 ( V_395 ) ;
V_433 . V_254 . V_255 = V_435 -> V_299 ;
F_50 () ;
V_436 = F_125 ( & V_433 ) ;
F_53 () ;
if ( V_436 == NULL )
V_14 = F_209 ( V_432 , & V_42 -> V_264 ) ;
else
F_210 ( V_432 ) ;
return V_14 ;
}
static void F_211 ( struct V_185 * V_190 ,
const struct V_431 * V_432 )
{
struct V_182 * V_183 = V_190 -> V_191 ;
struct V_11 * V_42 ;
if ( V_432 -> V_438 != 0 ) {
V_42 = F_104 ( V_432 -> V_438 ) ;
V_183 -> V_247 = V_42 ;
} else
V_183 -> V_247 = NULL ;
}
static int F_212 ( struct V_439 * V_439 , const struct V_36 * V_36 ,
unsigned long V_111 )
{
struct V_11 * V_42 = F_27 ( V_36 -> V_37 ) ;
V_439 -> V_37 = V_42 ;
return 0 ;
}
static void F_213 ( struct V_439 * V_439 )
{
V_439 -> V_37 = NULL ;
}
static int F_214 ( T_10 V_440 ,
const struct V_36 * V_36 , unsigned V_441 )
{
struct V_439 * V_442 ;
struct V_73 V_74 ;
struct V_11 * V_224 = F_27 ( V_36 -> V_37 ) ;
int V_443 = 0 ;
int V_14 ;
V_442 = F_215 ( V_440 ) ;
if ( V_442 == NULL )
return - V_176 ;
if ( V_442 -> V_37 == NULL )
return 0 ;
if ( V_224 == NULL )
return - V_82 ;
#ifdef F_134
F_25 ( & V_74 , V_85 , V_444 ) ;
V_74 . V_271 . V_272 . V_445 . V_439 = V_442 -> V_446 ;
V_74 . V_271 . V_272 . V_445 . V_447 = V_442 -> V_448 ;
#endif
if ( V_441 & V_449 )
V_443 = V_4 ;
if ( V_441 & ( V_450 | V_451 | V_452 ) )
V_443 = V_5 ;
V_14 = V_219 ( V_224 , V_442 -> V_37 , V_443 , & V_74 ) ;
V_14 = F_2 ( L_23 , V_224 , V_442 -> V_37 , V_443 , V_14 ) ;
return V_14 ;
}
static int F_216 ( T_3 V_453 , T_3 V_117 , char * V_454 , void * * V_455 )
{
struct V_11 * V_42 ;
char * * V_456 = ( char * * ) V_455 ;
* V_456 = NULL ;
if ( V_453 != V_457 && V_453 != V_458 )
return - V_176 ;
if ( V_117 != V_459 && V_117 != V_460 )
return - V_176 ;
V_42 = F_14 ( V_454 , 0 ) ;
if ( V_42 )
* V_456 = V_42 -> V_17 ;
return 0 ;
}
static int F_217 ( struct V_461 * V_462 )
{
struct V_463 * V_464 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_462 -> V_465 ; V_3 ++ ) {
V_464 = & V_462 -> V_466 [ V_3 ] ;
if ( V_464 -> type == V_457 || V_464 -> type == V_458 )
return 1 ;
}
return 0 ;
}
static int F_218 ( T_3 V_197 , T_3 V_453 , T_3 V_117 , void * V_455 ,
struct V_467 * V_468 )
{
struct V_11 * V_42 ;
char * V_456 = V_455 ;
if ( F_219 ( ! V_456 ) ) {
F_220 ( 1 , L_24 ) ;
return - V_218 ;
}
if ( V_453 != V_457 && V_453 != V_458 )
return 0 ;
V_42 = F_104 ( V_197 ) ;
if ( V_117 == V_459 )
return ( V_456 == V_42 -> V_17 ) ;
if ( V_117 == V_460 )
return ( V_456 != V_42 -> V_17 ) ;
return 0 ;
}
static void F_221 ( void * V_455 )
{
}
static int F_222 ( const char * V_35 )
{
return ( strcmp ( V_35 , V_146 ) == 0 ) ;
}
static int F_223 ( T_3 V_197 , char * * V_469 , T_3 * V_470 )
{
struct V_11 * V_42 = F_104 ( V_197 ) ;
if ( V_469 )
* V_469 = V_42 -> V_17 ;
* V_470 = strlen ( V_42 -> V_17 ) ;
return 0 ;
}
static int F_224 ( const char * V_469 , T_3 V_470 , T_3 * V_197 )
{
struct V_11 * V_42 = F_225 ( V_469 ) ;
if ( V_42 )
* V_197 = V_42 -> V_198 ;
else
* V_197 = 0 ;
return 0 ;
}
static void F_226 ( char * V_469 , T_3 V_470 )
{
}
static int F_227 ( struct V_26 * V_26 , void * V_471 , T_3 V_472 )
{
return F_141 ( V_26 , V_146 , V_471 , V_472 , 0 ) ;
}
static int F_228 ( struct V_39 * V_39 , void * V_471 , T_3 V_472 )
{
return F_229 ( V_39 , V_168 , V_471 , V_472 , 0 ) ;
}
static int F_230 ( struct V_26 * V_26 , void * * V_471 , T_3 * V_472 )
{
int V_142 = 0 ;
V_142 = F_78 ( V_26 , V_146 , V_471 , true ) ;
if ( V_142 < 0 )
return V_142 ;
* V_472 = V_142 ;
return 0 ;
}
static T_11 void F_231 ( void )
{
F_17 ( & V_437 . V_58 ) ;
F_17 ( & V_99 . V_58 ) ;
F_17 ( & V_95 . V_58 ) ;
F_17 ( & V_177 . V_58 ) ;
F_17 ( & V_179 . V_58 ) ;
F_17 ( & V_178 . V_58 ) ;
F_19 ( & V_437 . V_57 ) ;
F_19 ( & V_99 . V_57 ) ;
F_19 ( & V_177 . V_57 ) ;
F_19 ( & V_95 . V_57 ) ;
F_19 ( & V_179 . V_57 ) ;
F_19 ( & V_178 . V_57 ) ;
F_232 ( & V_437 ) ;
F_232 ( & V_99 ) ;
F_232 ( & V_177 ) ;
F_232 ( & V_95 ) ;
F_232 ( & V_179 ) ;
F_232 ( & V_178 ) ;
}
static T_11 int F_233 ( void )
{
struct V_36 * V_36 ;
struct V_18 * V_19 ;
if ( ! F_234 ( & V_473 ) )
return 0 ;
V_19 = F_18 ( & V_95 , & V_95 ,
V_46 ) ;
if ( V_19 == NULL )
return - V_65 ;
F_142 ( V_474 L_25 ) ;
V_36 = (struct V_36 * ) V_21 -> V_36 ;
V_36 -> V_37 = V_19 ;
F_231 () ;
if ( F_235 ( & V_473 ) )
F_236 ( L_26 ) ;
return 0 ;
}

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
V_26 -> V_27 -> V_28 , V_26 -> V_29 , V_30 ,
V_21 -> V_22 ) ;
return 0 ;
}
static int F_11 ( const struct V_33 * V_33 , struct V_30 * V_30 ,
int V_1 , int V_14 )
{
struct V_18 * V_19 = V_33 -> V_34 ;
struct V_11 * V_12 = V_19 -> V_20 ;
struct V_26 * V_26 = V_30 -> V_31 ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_5 ,
V_12 -> V_17 , F_9 ( V_26 ) -> V_17 , V_15 ,
V_26 -> V_27 -> V_28 , V_26 -> V_29 , V_30 ,
V_21 -> V_22 ) ;
return 0 ;
}
static struct V_11 * F_12 ( const char * V_35 , struct V_26 * V_36 ,
struct V_37 * V_38 )
{
int V_14 ;
char * V_39 ;
struct V_11 * V_40 = NULL ;
if ( V_36 -> V_41 -> V_42 == NULL )
return NULL ;
V_39 = F_13 ( V_43 , V_44 ) ;
if ( V_39 == NULL )
return NULL ;
V_14 = V_36 -> V_41 -> V_42 ( V_38 , V_35 , V_39 , V_43 ) ;
if ( V_14 > 0 )
V_40 = F_14 ( V_39 , V_14 ) ;
F_15 ( V_39 ) ;
return V_40 ;
}
struct V_45 * F_16 ( struct V_11 * V_40 )
{
struct V_45 * V_46 ;
V_46 = F_17 ( V_47 , V_48 ) ;
if ( V_46 == NULL )
return NULL ;
V_46 -> V_49 = V_40 ;
V_46 -> V_50 = 0 ;
F_18 ( & V_46 -> V_51 ) ;
return V_46 ;
}
static struct V_18 * F_19 ( struct V_11 * V_52 ,
struct V_11 * V_53 , T_1 V_54 )
{
struct V_18 * V_19 ;
V_19 = F_13 ( sizeof( struct V_18 ) , V_54 ) ;
if ( V_19 == NULL )
return NULL ;
V_19 -> V_20 = V_52 ;
V_19 -> V_55 = V_53 ;
F_20 ( & V_19 -> V_56 ) ;
F_18 ( & V_19 -> V_57 ) ;
return V_19 ;
}
static int F_21 ( struct V_58 * V_59 , struct V_58 * V_60 ,
T_1 V_54 )
{
struct V_61 * V_62 ;
struct V_61 * V_63 ;
int V_14 = 0 ;
F_20 ( V_59 ) ;
F_22 (orp, ohead, list) {
V_62 = F_13 ( sizeof( struct V_61 ) , V_54 ) ;
if ( V_62 == NULL ) {
V_14 = - V_64 ;
break;
}
* V_62 = * V_63 ;
F_23 ( & V_62 -> V_65 , V_59 ) ;
}
return V_14 ;
}
static inline unsigned int F_24 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_66 :
return V_4 ;
case V_67 :
return V_68 ;
}
return 0 ;
}
static int F_25 ( struct V_23 * V_69 ,
struct V_11 * V_70 ,
unsigned int V_1 , const char * V_71 )
{
int V_14 ;
struct V_72 V_73 , * V_74 = NULL ;
struct V_18 * V_19 ;
struct V_11 * V_75 ;
if ( ( V_1 & V_76 ) == 0 ) {
F_26 ( & V_73 , V_71 , V_77 ) ;
F_27 ( & V_73 , V_69 ) ;
V_74 = & V_73 ;
}
V_19 = F_7 ( V_69 ) ;
V_75 = F_28 ( V_19 ) ;
if ( ( V_1 & V_67 ) &&
( V_78 == V_79 ||
V_78 == V_80 ) ) {
if ( V_75 -> V_17 == V_70 -> V_17 )
V_14 = 0 ;
else if ( V_78 == V_80 )
V_14 = - V_81 ;
else if ( F_29 ( V_82 ) )
V_14 = 0 ;
else
V_14 = - V_81 ;
if ( V_74 )
F_30 ( V_75 -> V_17 ,
V_70 -> V_17 ,
0 , V_14 , V_74 ) ;
return V_14 ;
}
V_14 = F_31 ( V_19 , V_70 , F_24 ( V_1 ) , V_74 ) ;
return V_14 ;
}
static int F_32 ( struct V_23 * V_83 , unsigned int V_1 )
{
int V_14 ;
struct V_11 * V_40 ;
V_14 = F_33 ( V_83 , V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
V_40 = F_28 ( F_7 ( V_83 ) ) ;
V_14 = F_25 ( V_21 , V_40 , V_1 , V_84 ) ;
return V_14 ;
}
static int F_34 ( struct V_23 * V_85 )
{
int V_14 ;
struct V_11 * V_40 ;
V_14 = F_35 ( V_85 ) ;
if ( V_14 != 0 )
return V_14 ;
V_40 = F_28 ( F_5 () ) ;
V_14 = F_25 ( V_85 , V_40 , V_67 , V_84 ) ;
return V_14 ;
}
static int F_36 ( int V_86 )
{
int V_14 = 0 ;
struct V_11 * V_40 = F_37 () ;
if ( F_38 ( V_87 ) )
return 0 ;
if ( V_88 != NULL && V_88 != V_40 )
V_14 = - V_81 ;
return V_14 ;
}
static int F_39 ( struct V_89 * V_90 )
{
struct V_91 * V_92 ;
V_92 = F_13 ( sizeof( struct V_91 ) , V_44 ) ;
if ( V_92 == NULL )
return - V_64 ;
V_92 -> V_93 = & V_94 ;
V_92 -> V_95 = & V_94 ;
V_92 -> V_96 = & V_94 ;
V_92 -> V_97 = & V_98 ;
V_90 -> V_99 = V_92 ;
return 0 ;
}
static void F_40 ( struct V_89 * V_90 )
{
F_15 ( V_90 -> V_99 ) ;
V_90 -> V_99 = NULL ;
}
static int F_41 ( char * V_100 , char * V_101 )
{
char * V_102 , * V_103 , * V_104 , * V_38 ;
V_104 = ( char * ) F_42 ( V_44 ) ;
if ( V_104 == NULL )
return - V_64 ;
for ( V_102 = V_100 , V_103 = V_100 ; V_103 != NULL ; V_102 = V_103 + 1 ) {
if ( strstr ( V_102 , V_105 ) == V_102 )
V_38 = V_101 ;
else if ( strstr ( V_102 , V_106 ) == V_102 )
V_38 = V_101 ;
else if ( strstr ( V_102 , V_107 ) == V_102 )
V_38 = V_101 ;
else if ( strstr ( V_102 , V_108 ) == V_102 )
V_38 = V_101 ;
else if ( strstr ( V_102 , V_109 ) == V_102 )
V_38 = V_101 ;
else
V_38 = V_104 ;
V_103 = strchr ( V_102 , ',' ) ;
if ( V_103 != NULL )
* V_103 = '\0' ;
if ( * V_38 != '\0' )
strcat ( V_38 , L_6 ) ;
strcat ( V_38 , V_102 ) ;
}
strcpy ( V_100 , V_104 ) ;
F_43 ( ( unsigned long ) V_104 ) ;
return 0 ;
}
static int F_44 ( struct V_89 * V_90 , int V_110 , void * V_111 )
{
struct V_37 * V_112 = V_90 -> V_113 ;
struct V_26 * V_26 = V_112 -> V_114 ;
struct V_91 * V_115 = V_90 -> V_99 ;
struct V_45 * V_46 ;
struct V_11 * V_40 ;
char * V_116 ;
char * V_103 ;
int V_117 = 0 ;
int V_118 = 0 ;
if ( V_115 -> V_119 )
return 0 ;
V_115 -> V_119 = 1 ;
for ( V_116 = V_111 ; V_116 != NULL ; V_116 = V_103 ) {
V_103 = strchr ( V_116 , ',' ) ;
if ( V_103 != NULL )
* V_103 ++ = '\0' ;
if ( strncmp ( V_116 , V_107 , strlen ( V_107 ) ) == 0 ) {
V_116 += strlen ( V_107 ) ;
V_40 = F_14 ( V_116 , 0 ) ;
if ( V_40 != NULL ) {
V_115 -> V_97 = V_40 ;
V_118 = 1 ;
}
} else if ( strncmp ( V_116 , V_106 , strlen ( V_106 ) ) == 0 ) {
V_116 += strlen ( V_106 ) ;
V_40 = F_14 ( V_116 , 0 ) ;
if ( V_40 != NULL ) {
V_115 -> V_96 = V_40 ;
V_118 = 1 ;
}
} else if ( strncmp ( V_116 , V_105 ,
strlen ( V_105 ) ) == 0 ) {
V_116 += strlen ( V_105 ) ;
V_40 = F_14 ( V_116 , 0 ) ;
if ( V_40 != NULL ) {
V_115 -> V_95 = V_40 ;
V_118 = 1 ;
}
} else if ( strncmp ( V_116 , V_108 , strlen ( V_108 ) ) == 0 ) {
V_116 += strlen ( V_108 ) ;
V_40 = F_14 ( V_116 , 0 ) ;
if ( V_40 != NULL ) {
V_115 -> V_93 = V_40 ;
V_118 = 1 ;
}
} else if ( strncmp ( V_116 , V_109 , strlen ( V_109 ) ) == 0 ) {
V_116 += strlen ( V_109 ) ;
V_40 = F_14 ( V_116 , 0 ) ;
if ( V_40 != NULL ) {
V_115 -> V_93 = V_40 ;
V_117 = 1 ;
V_118 = 1 ;
}
}
}
if ( ! F_38 ( V_120 ) ) {
if ( V_118 )
return - V_121 ;
V_40 = F_37 () ;
V_115 -> V_93 = V_40 ;
V_115 -> V_95 = V_40 ;
}
V_46 = V_26 -> V_122 ;
if ( V_46 == NULL ) {
V_46 = F_16 ( V_115 -> V_93 ) ;
if ( V_46 == NULL )
return - V_64 ;
V_26 -> V_122 = V_46 ;
} else
V_46 -> V_49 = V_115 -> V_93 ;
if ( V_117 )
V_46 -> V_50 |= V_123 ;
return 0 ;
}
static int F_45 ( struct V_37 * V_37 )
{
struct V_91 * V_124 = V_37 -> V_125 -> V_99 ;
int V_14 ;
struct V_72 V_73 ;
F_26 ( & V_73 , V_84 , V_126 ) ;
F_46 ( & V_73 , V_37 ) ;
V_14 = F_47 ( V_124 -> V_96 , V_4 , & V_73 ) ;
V_14 = F_4 ( L_7 , V_124 -> V_96 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_48 ( struct V_127 * V_128 )
{
struct V_26 * V_26 = F_49 ( V_128 -> V_30 ) ;
struct V_18 * V_129 = V_128 -> V_33 -> V_34 ;
struct V_45 * V_46 ;
int V_14 ;
V_14 = F_50 ( V_128 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( V_128 -> V_130 )
return 0 ;
V_46 = V_26 -> V_122 ;
if ( V_46 -> V_20 == NULL || V_46 -> V_20 == V_129 -> V_20 )
return 0 ;
if ( V_128 -> V_131 & ( V_132 | V_133 ) ) {
struct V_23 * V_69 ;
V_14 = 0 ;
F_51 () ;
V_69 = F_52 ( V_21 ) ;
if ( F_53 ( V_69 != NULL ) )
V_14 = F_25 ( V_69 ,
V_46 -> V_20 ,
V_67 ,
V_84 ) ;
F_54 () ;
if ( V_14 != 0 )
return V_14 ;
} else if ( V_128 -> V_131 )
return - V_121 ;
V_129 -> V_20 = V_46 -> V_20 ;
V_128 -> V_134 |= V_135 ;
return 0 ;
}
static void F_55 ( struct V_127 * V_128 )
{
struct V_18 * V_129 = V_128 -> V_33 -> V_34 ;
if ( V_129 -> V_20 != V_129 -> V_55 )
V_21 -> V_136 = 0 ;
}
static int F_56 ( struct V_127 * V_128 )
{
struct V_18 * V_19 = F_5 () ;
int V_137 = F_57 ( V_128 ) ;
if ( ! V_137 && ( V_19 -> V_20 != V_19 -> V_55 ) )
V_137 = 1 ;
return V_137 ;
}
static int F_58 ( struct V_26 * V_26 )
{
struct V_11 * V_40 = F_37 () ;
V_26 -> V_122 = F_16 ( V_40 ) ;
if ( V_26 -> V_122 == NULL )
return - V_64 ;
return 0 ;
}
static void F_59 ( struct V_26 * V_26 )
{
F_60 ( V_47 , V_26 -> V_122 ) ;
V_26 -> V_122 = NULL ;
}
static int F_61 ( struct V_26 * V_26 , struct V_26 * V_138 ,
const struct V_139 * V_139 , const char * * V_35 ,
void * * V_140 , T_2 * V_141 )
{
struct V_45 * V_142 = V_26 -> V_122 ;
struct V_11 * V_40 = F_37 () ;
struct V_11 * V_46 = F_9 ( V_26 ) ;
struct V_11 * V_143 = F_9 ( V_138 ) ;
int V_144 ;
if ( V_35 )
* V_35 = V_145 ;
if ( V_140 ) {
F_51 () ;
V_144 = F_62 ( V_40 -> V_17 , V_143 -> V_17 ,
& V_40 -> V_56 ) ;
F_54 () ;
if ( V_144 > 0 && ( ( V_144 & V_8 ) != 0 ) &&
F_63 ( V_138 ) ) {
V_46 = V_143 ;
V_142 -> V_50 |= V_146 ;
}
* V_140 = F_64 ( V_46 -> V_17 , V_48 ) ;
if ( * V_140 == NULL )
return - V_64 ;
}
if ( V_141 )
* V_141 = strlen ( V_46 -> V_17 ) ;
return 0 ;
}
static int F_65 ( struct V_37 * V_147 , struct V_26 * V_138 ,
struct V_37 * V_148 )
{
struct V_11 * V_46 ;
struct V_72 V_73 ;
int V_14 ;
F_26 ( & V_73 , V_84 , V_126 ) ;
F_46 ( & V_73 , V_147 ) ;
V_46 = F_9 ( V_147 -> V_114 ) ;
V_14 = F_47 ( V_46 , V_5 , & V_73 ) ;
V_14 = F_8 ( V_147 -> V_114 , V_5 , V_14 ) ;
if ( V_14 == 0 && V_148 -> V_114 != NULL ) {
V_46 = F_9 ( V_148 -> V_114 ) ;
F_46 ( & V_73 , V_148 ) ;
V_14 = F_47 ( V_46 , V_5 , & V_73 ) ;
V_14 = F_8 ( V_148 -> V_114 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_66 ( struct V_26 * V_138 , struct V_37 * V_37 )
{
struct V_26 * V_36 = V_37 -> V_114 ;
struct V_72 V_73 ;
int V_14 ;
F_26 ( & V_73 , V_84 , V_126 ) ;
F_46 ( & V_73 , V_37 ) ;
V_14 = F_47 ( F_9 ( V_36 ) , V_5 , & V_73 ) ;
V_14 = F_8 ( V_36 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_26 ( & V_73 , V_84 , V_149 ) ;
F_67 ( & V_73 , V_138 ) ;
V_14 = F_47 ( F_9 ( V_138 ) , V_5 , & V_73 ) ;
V_14 = F_8 ( V_138 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_68 ( struct V_26 * V_138 , struct V_37 * V_37 )
{
struct V_72 V_73 ;
int V_14 ;
F_26 ( & V_73 , V_84 , V_126 ) ;
F_46 ( & V_73 , V_37 ) ;
V_14 = F_47 ( F_9 ( V_37 -> V_114 ) , V_5 , & V_73 ) ;
V_14 = F_8 ( V_37 -> V_114 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_26 ( & V_73 , V_84 , V_149 ) ;
F_67 ( & V_73 , V_138 ) ;
V_14 = F_47 ( F_9 ( V_138 ) , V_5 , & V_73 ) ;
V_14 = F_8 ( V_138 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_69 ( struct V_26 * V_150 ,
struct V_37 * V_147 ,
struct V_26 * V_151 ,
struct V_37 * V_148 )
{
int V_14 ;
struct V_11 * V_46 ;
struct V_72 V_73 ;
F_26 ( & V_73 , V_84 , V_126 ) ;
F_46 ( & V_73 , V_147 ) ;
V_46 = F_9 ( V_147 -> V_114 ) ;
V_14 = F_47 ( V_46 , V_68 , & V_73 ) ;
V_14 = F_8 ( V_147 -> V_114 , V_68 , V_14 ) ;
if ( V_14 == 0 && V_148 -> V_114 != NULL ) {
V_46 = F_9 ( V_148 -> V_114 ) ;
F_46 ( & V_73 , V_148 ) ;
V_14 = F_47 ( V_46 , V_68 , & V_73 ) ;
V_14 = F_8 ( V_148 -> V_114 , V_68 , V_14 ) ;
}
return V_14 ;
}
static int F_70 ( struct V_26 * V_26 , int V_152 )
{
struct V_72 V_73 ;
int V_153 = V_152 & V_154 ;
int V_14 ;
V_152 &= ( V_4 | V_5 | V_6 | V_7 ) ;
if ( V_152 == 0 )
return 0 ;
if ( V_153 )
return - V_155 ;
F_26 ( & V_73 , V_84 , V_149 ) ;
F_67 ( & V_73 , V_26 ) ;
V_14 = F_47 ( F_9 ( V_26 ) , V_152 , & V_73 ) ;
V_14 = F_8 ( V_26 , V_152 , V_14 ) ;
return V_14 ;
}
static int F_71 ( struct V_37 * V_37 , struct V_156 * V_156 )
{
struct V_72 V_73 ;
int V_14 ;
if ( V_156 -> V_157 & V_158 )
return 0 ;
F_26 ( & V_73 , V_84 , V_126 ) ;
F_46 ( & V_73 , V_37 ) ;
V_14 = F_47 ( F_9 ( V_37 -> V_114 ) , V_5 , & V_73 ) ;
V_14 = F_8 ( V_37 -> V_114 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_72 ( struct V_159 * V_160 , struct V_37 * V_37 )
{
struct V_72 V_73 ;
struct V_161 V_161 ;
int V_14 ;
V_161 . V_37 = V_37 ;
V_161 . V_160 = V_160 ;
F_26 ( & V_73 , V_84 , V_162 ) ;
F_73 ( & V_73 , V_161 ) ;
V_14 = F_47 ( F_9 ( V_37 -> V_114 ) , V_4 , & V_73 ) ;
V_14 = F_8 ( V_37 -> V_114 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_74 ( struct V_37 * V_37 , const char * V_35 ,
const void * V_140 , T_2 V_163 , int V_110 )
{
struct V_72 V_73 ;
struct V_11 * V_40 ;
int V_164 = 0 ;
int V_165 = 0 ;
int V_166 = 0 ;
int V_14 = 0 ;
if ( strcmp ( V_35 , V_167 ) == 0 ||
strcmp ( V_35 , V_168 ) == 0 ||
strcmp ( V_35 , V_169 ) == 0 ) {
V_164 = 1 ;
V_165 = 1 ;
} else if ( strcmp ( V_35 , V_170 ) == 0 ||
strcmp ( V_35 , V_171 ) == 0 ) {
V_164 = 1 ;
V_165 = 1 ;
V_166 = 1 ;
} else if ( strcmp ( V_35 , V_172 ) == 0 ) {
V_164 = 1 ;
if ( V_163 != V_173 ||
strncmp ( V_140 , V_174 , V_173 ) != 0 )
V_14 = - V_175 ;
} else
V_14 = F_75 ( V_37 , V_35 , V_140 , V_163 , V_110 ) ;
if ( V_164 && ! F_38 ( V_120 ) )
V_14 = - V_121 ;
if ( V_14 == 0 && V_165 ) {
V_40 = V_163 ? F_14 ( V_140 , V_163 ) : NULL ;
if ( V_40 == NULL || ( V_166 &&
( V_40 == & V_176 || V_40 == & V_177 ) ) )
V_14 = - V_175 ;
}
F_26 ( & V_73 , V_84 , V_126 ) ;
F_46 ( & V_73 , V_37 ) ;
if ( V_14 == 0 ) {
V_14 = F_47 ( F_9 ( V_37 -> V_114 ) , V_5 , & V_73 ) ;
V_14 = F_8 ( V_37 -> V_114 , V_5 , V_14 ) ;
}
return V_14 ;
}
static void F_76 ( struct V_37 * V_37 , const char * V_35 ,
const void * V_140 , T_2 V_163 , int V_110 )
{
struct V_11 * V_40 ;
struct V_45 * V_46 = V_37 -> V_114 -> V_122 ;
if ( strcmp ( V_35 , V_172 ) == 0 ) {
V_46 -> V_50 |= V_123 ;
return;
}
if ( strcmp ( V_35 , V_167 ) == 0 ) {
V_40 = F_14 ( V_140 , V_163 ) ;
if ( V_40 != NULL )
V_46 -> V_49 = V_40 ;
else
V_46 -> V_49 = & V_178 ;
} else if ( strcmp ( V_35 , V_170 ) == 0 ) {
V_40 = F_14 ( V_140 , V_163 ) ;
if ( V_40 != NULL )
V_46 -> V_20 = V_40 ;
else
V_46 -> V_20 = & V_178 ;
} else if ( strcmp ( V_35 , V_171 ) == 0 ) {
V_40 = F_14 ( V_140 , V_163 ) ;
if ( V_40 != NULL )
V_46 -> V_179 = V_40 ;
else
V_46 -> V_179 = & V_178 ;
}
return;
}
static int F_77 ( struct V_37 * V_37 , const char * V_35 )
{
struct V_72 V_73 ;
int V_14 ;
F_26 ( & V_73 , V_84 , V_126 ) ;
F_46 ( & V_73 , V_37 ) ;
V_14 = F_47 ( F_9 ( V_37 -> V_114 ) , V_4 , & V_73 ) ;
V_14 = F_8 ( V_37 -> V_114 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_78 ( struct V_37 * V_37 , const char * V_35 )
{
struct V_45 * V_46 ;
struct V_72 V_73 ;
int V_14 = 0 ;
if ( strcmp ( V_35 , V_167 ) == 0 ||
strcmp ( V_35 , V_168 ) == 0 ||
strcmp ( V_35 , V_169 ) == 0 ||
strcmp ( V_35 , V_170 ) == 0 ||
strcmp ( V_35 , V_172 ) == 0 ||
strcmp ( V_35 , V_171 ) == 0 ) {
if ( ! F_38 ( V_120 ) )
V_14 = - V_121 ;
} else
V_14 = F_79 ( V_37 , V_35 ) ;
if ( V_14 != 0 )
return V_14 ;
F_26 ( & V_73 , V_84 , V_126 ) ;
F_46 ( & V_73 , V_37 ) ;
V_14 = F_47 ( F_9 ( V_37 -> V_114 ) , V_5 , & V_73 ) ;
V_14 = F_8 ( V_37 -> V_114 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_46 = V_37 -> V_114 -> V_122 ;
if ( strcmp ( V_35 , V_167 ) == 0 )
V_46 -> V_20 = NULL ;
else if ( strcmp ( V_35 , V_171 ) == 0 )
V_46 -> V_179 = NULL ;
else if ( strcmp ( V_35 , V_172 ) == 0 )
V_46 -> V_50 &= ~ V_123 ;
return 0 ;
}
static int F_80 ( const struct V_26 * V_26 ,
const char * V_35 , void * * V_39 ,
bool V_180 )
{
struct V_181 * V_182 ;
struct V_183 * V_184 ;
struct V_89 * V_124 ;
struct V_26 * V_36 = (struct V_26 * ) V_26 ;
struct V_11 * V_46 ;
int V_185 ;
int V_14 = 0 ;
if ( strcmp ( V_35 , V_145 ) == 0 ) {
V_46 = F_9 ( V_26 ) ;
V_185 = strlen ( V_46 -> V_17 ) ;
* V_39 = V_46 -> V_17 ;
return V_185 ;
}
V_124 = V_36 -> V_27 ;
if ( V_124 -> V_186 != V_187 )
return - V_188 ;
V_184 = F_81 ( V_36 ) ;
if ( V_184 == NULL || V_184 -> V_189 == NULL )
return - V_188 ;
V_182 = V_184 -> V_189 -> V_190 ;
if ( strcmp ( V_35 , V_191 ) == 0 )
V_46 = V_182 -> V_192 ;
else if ( strcmp ( V_35 , V_193 ) == 0 )
V_46 = V_182 -> V_194 ;
else
return - V_188 ;
V_185 = strlen ( V_46 -> V_17 ) ;
if ( V_14 == 0 ) {
* V_39 = V_46 -> V_17 ;
V_14 = V_185 ;
}
return V_14 ;
}
static int F_82 ( struct V_26 * V_26 , char * V_39 ,
T_2 V_195 )
{
int V_141 = sizeof( V_167 ) ;
if ( V_39 != NULL && V_141 <= V_195 )
memcpy ( V_39 , V_167 , V_141 ) ;
return V_141 ;
}
static void F_83 ( const struct V_26 * V_26 , T_3 * V_196 )
{
struct V_45 * V_46 = V_26 -> V_122 ;
* V_196 = V_46 -> V_49 -> V_197 ;
}
static int F_84 ( struct V_30 * V_30 , int V_152 )
{
return 0 ;
}
static int F_85 ( struct V_30 * V_30 )
{
struct V_11 * V_40 = F_37 () ;
V_30 -> V_32 = V_40 ;
return 0 ;
}
static void F_86 ( struct V_30 * V_30 )
{
V_30 -> V_32 = NULL ;
}
static int F_87 ( struct V_30 * V_30 , unsigned int V_198 ,
unsigned long V_199 )
{
int V_14 = 0 ;
struct V_72 V_73 ;
F_26 ( & V_73 , V_84 , V_162 ) ;
F_73 ( & V_73 , V_30 -> V_200 ) ;
if ( F_88 ( V_198 ) & V_201 ) {
V_14 = F_47 ( V_30 -> V_32 , V_5 , & V_73 ) ;
V_14 = F_10 ( V_30 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_88 ( V_198 ) & V_202 ) ) {
V_14 = F_47 ( V_30 -> V_32 , V_4 , & V_73 ) ;
V_14 = F_10 ( V_30 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_89 ( struct V_30 * V_30 , unsigned int V_198 )
{
struct V_72 V_73 ;
int V_14 ;
F_26 ( & V_73 , V_84 , V_162 ) ;
F_73 ( & V_73 , V_30 -> V_200 ) ;
V_14 = F_47 ( V_30 -> V_32 , V_9 , & V_73 ) ;
V_14 = F_10 ( V_30 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_90 ( struct V_30 * V_30 , unsigned int V_198 ,
unsigned long V_199 )
{
struct V_72 V_73 ;
int V_14 = 0 ;
switch ( V_198 ) {
case V_203 :
break;
case V_204 :
case V_205 :
F_26 ( & V_73 , V_84 , V_162 ) ;
F_73 ( & V_73 , V_30 -> V_200 ) ;
V_14 = F_47 ( V_30 -> V_32 , V_9 , & V_73 ) ;
V_14 = F_10 ( V_30 , V_9 , V_14 ) ;
break;
case V_206 :
case V_207 :
F_26 ( & V_73 , V_84 , V_162 ) ;
F_73 ( & V_73 , V_30 -> V_200 ) ;
V_14 = F_47 ( V_30 -> V_32 , V_5 , & V_73 ) ;
V_14 = F_10 ( V_30 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_91 ( struct V_30 * V_30 ,
unsigned long V_208 , unsigned long V_209 ,
unsigned long V_110 )
{
struct V_11 * V_40 ;
struct V_11 * V_210 ;
struct V_61 * V_211 ;
struct V_18 * V_19 ;
struct V_11 * V_212 ;
struct V_45 * V_46 ;
int V_144 ;
int V_213 ;
int V_214 ;
int V_14 ;
if ( V_30 == NULL )
return 0 ;
V_46 = F_49 ( V_30 ) -> V_122 ;
if ( V_46 -> V_179 == NULL )
return 0 ;
V_210 = V_46 -> V_179 ;
V_19 = F_5 () ;
V_40 = F_37 () ;
V_14 = 0 ;
F_51 () ;
F_22 (srp, &skp->smk_rules, list) {
V_212 = V_211 -> V_215 ;
if ( V_210 -> V_17 == V_212 -> V_17 )
continue;
V_144 = F_62 ( V_211 -> V_216 -> V_17 ,
V_212 -> V_17 ,
& V_19 -> V_56 ) ;
if ( V_144 == - V_217 )
V_144 = V_211 -> V_218 ;
else
V_144 &= V_211 -> V_218 ;
if ( V_144 == 0 )
continue;
V_213 = F_62 ( V_210 -> V_17 , V_212 -> V_17 ,
& V_210 -> V_56 ) ;
if ( V_213 == - V_217 ) {
V_14 = - V_81 ;
break;
}
V_214 = F_62 ( V_210 -> V_17 , V_212 -> V_17 ,
& V_19 -> V_56 ) ;
if ( V_214 != - V_217 )
V_213 &= V_214 ;
if ( ( V_144 | V_213 ) != V_213 ) {
V_14 = - V_81 ;
break;
}
}
F_54 () ;
return V_14 ;
}
static void F_92 ( struct V_30 * V_30 )
{
struct V_11 * V_40 = F_37 () ;
V_30 -> V_32 = V_40 ;
}
static int F_93 ( struct V_23 * V_219 ,
struct V_220 * V_221 , int V_222 )
{
struct V_11 * V_40 ;
struct V_11 * V_223 = F_28 ( V_219 -> V_33 -> V_34 ) ;
struct V_30 * V_30 ;
int V_14 ;
struct V_72 V_73 ;
V_30 = F_94 ( V_221 , struct V_30 , V_224 ) ;
V_40 = V_30 -> V_32 ;
V_14 = V_218 ( V_40 , V_223 , V_5 , NULL ) ;
V_14 = F_2 ( L_8 , V_40 , V_223 , V_5 , V_14 ) ;
if ( V_14 != 0 && F_95 ( V_219 , V_87 ) )
V_14 = 0 ;
F_26 ( & V_73 , V_84 , V_77 ) ;
F_27 ( & V_73 , V_219 ) ;
F_30 ( V_40 -> V_17 , V_223 -> V_17 , V_5 , V_14 , & V_73 ) ;
return V_14 ;
}
static int F_96 ( struct V_30 * V_30 )
{
int V_14 ;
int V_144 = 0 ;
struct V_72 V_73 ;
F_26 ( & V_73 , V_84 , V_162 ) ;
F_73 ( & V_73 , V_30 -> V_200 ) ;
if ( V_30 -> V_225 & V_226 )
V_144 = V_4 ;
if ( V_30 -> V_225 & V_227 )
V_144 |= V_5 ;
V_14 = F_47 ( V_30 -> V_32 , V_144 , & V_73 ) ;
V_14 = F_10 ( V_30 , V_144 , V_14 ) ;
return V_14 ;
}
static int F_97 ( struct V_30 * V_30 , const struct V_33 * V_33 )
{
struct V_18 * V_19 = V_33 -> V_34 ;
struct V_45 * V_46 = F_49 ( V_30 ) -> V_122 ;
struct V_72 V_73 ;
int V_14 ;
if ( F_38 ( V_87 ) ) {
V_30 -> V_32 = V_46 -> V_49 ;
return 0 ;
}
F_26 ( & V_73 , V_84 , V_162 ) ;
F_73 ( & V_73 , V_30 -> V_200 ) ;
V_14 = V_218 ( V_19 -> V_20 , V_46 -> V_49 , V_4 , & V_73 ) ;
V_14 = F_11 ( V_33 , V_30 , V_4 , V_14 ) ;
if ( V_14 == 0 )
V_30 -> V_32 = V_46 -> V_49 ;
return V_14 ;
}
static int F_98 ( struct V_33 * V_33 , T_1 V_54 )
{
struct V_18 * V_19 ;
V_19 = F_19 ( NULL , NULL , V_54 ) ;
if ( V_19 == NULL )
return - V_64 ;
V_33 -> V_34 = V_19 ;
return 0 ;
}
static void F_99 ( struct V_33 * V_33 )
{
struct V_18 * V_19 = V_33 -> V_34 ;
struct V_61 * V_228 ;
struct V_58 * V_229 ;
struct V_58 * V_230 ;
if ( V_19 == NULL )
return;
V_33 -> V_34 = NULL ;
F_100 (l, n, &tsp->smk_rules) {
V_228 = F_101 ( V_229 , struct V_61 , V_65 ) ;
F_102 ( & V_228 -> V_65 ) ;
F_15 ( V_228 ) ;
}
F_15 ( V_19 ) ;
}
static int F_103 ( struct V_33 * V_231 , const struct V_33 * V_232 ,
T_1 V_54 )
{
struct V_18 * V_233 = V_232 -> V_34 ;
struct V_18 * V_234 ;
int V_14 ;
V_234 = F_19 ( V_233 -> V_20 , V_233 -> V_20 , V_54 ) ;
if ( V_234 == NULL )
return - V_64 ;
V_14 = F_21 ( & V_234 -> V_56 , & V_233 -> V_56 , V_54 ) ;
if ( V_14 != 0 )
return V_14 ;
V_231 -> V_34 = V_234 ;
return 0 ;
}
static void F_104 ( struct V_33 * V_231 , const struct V_33 * V_232 )
{
struct V_18 * V_233 = V_232 -> V_34 ;
struct V_18 * V_234 = V_231 -> V_34 ;
V_234 -> V_20 = V_233 -> V_20 ;
V_234 -> V_55 = V_233 -> V_20 ;
F_18 ( & V_234 -> V_57 ) ;
F_20 ( & V_234 -> V_56 ) ;
}
static int F_105 ( struct V_33 * V_231 , T_3 V_196 )
{
struct V_18 * V_234 = V_231 -> V_34 ;
struct V_11 * V_40 = F_106 ( V_196 ) ;
if ( V_40 == NULL )
return - V_175 ;
V_234 -> V_20 = V_40 ;
return 0 ;
}
static int F_107 ( struct V_33 * V_231 ,
struct V_26 * V_26 )
{
struct V_45 * V_46 = V_26 -> V_122 ;
struct V_18 * V_19 = V_231 -> V_34 ;
V_19 -> V_55 = V_46 -> V_49 ;
V_19 -> V_20 = V_19 -> V_55 ;
return 0 ;
}
static int F_108 ( struct V_23 * V_235 , int V_236 ,
const char * V_237 )
{
struct V_72 V_73 ;
struct V_11 * V_40 = F_28 ( F_7 ( V_235 ) ) ;
int V_14 ;
F_26 ( & V_73 , V_237 , V_77 ) ;
F_27 ( & V_73 , V_235 ) ;
V_14 = F_47 ( V_40 , V_236 , & V_73 ) ;
V_14 = F_6 ( V_235 , V_236 , V_14 ) ;
return V_14 ;
}
static int F_109 ( struct V_23 * V_235 , T_4 V_238 )
{
return F_108 ( V_235 , V_5 , V_84 ) ;
}
static int F_110 ( struct V_23 * V_235 )
{
return F_108 ( V_235 , V_4 , V_84 ) ;
}
static int F_111 ( struct V_23 * V_235 )
{
return F_108 ( V_235 , V_4 , V_84 ) ;
}
static void F_112 ( struct V_23 * V_235 , T_3 * V_196 )
{
struct V_11 * V_40 = F_28 ( F_7 ( V_235 ) ) ;
* V_196 = V_40 -> V_197 ;
}
static int F_113 ( struct V_23 * V_235 , int V_239 )
{
int V_14 ;
V_14 = F_114 ( V_235 , V_239 ) ;
if ( V_14 == 0 )
V_14 = F_108 ( V_235 , V_5 , V_84 ) ;
return V_14 ;
}
static int F_115 ( struct V_23 * V_235 , int V_240 )
{
int V_14 ;
V_14 = F_116 ( V_235 , V_240 ) ;
if ( V_14 == 0 )
V_14 = F_108 ( V_235 , V_5 , V_84 ) ;
return V_14 ;
}
static int F_117 ( struct V_23 * V_235 )
{
return F_108 ( V_235 , V_4 , V_84 ) ;
}
static int F_118 ( struct V_23 * V_235 )
{
int V_14 ;
V_14 = F_119 ( V_235 ) ;
if ( V_14 == 0 )
V_14 = F_108 ( V_235 , V_5 , V_84 ) ;
return V_14 ;
}
static int F_120 ( struct V_23 * V_235 )
{
return F_108 ( V_235 , V_4 , V_84 ) ;
}
static int F_121 ( struct V_23 * V_235 )
{
return F_108 ( V_235 , V_5 , V_84 ) ;
}
static int F_122 ( struct V_23 * V_235 , struct V_241 * V_242 ,
int V_243 , T_3 V_196 )
{
struct V_72 V_73 ;
struct V_11 * V_40 ;
struct V_11 * V_223 = F_28 ( F_7 ( V_235 ) ) ;
int V_14 ;
F_26 ( & V_73 , V_84 , V_77 ) ;
F_27 ( & V_73 , V_235 ) ;
if ( V_196 == 0 ) {
V_14 = F_47 ( V_223 , V_5 , & V_73 ) ;
V_14 = F_6 ( V_235 , V_5 , V_14 ) ;
return V_14 ;
}
V_40 = F_106 ( V_196 ) ;
V_14 = V_218 ( V_40 , V_223 , V_5 , & V_73 ) ;
V_14 = F_2 ( L_9 , V_40 , V_223 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_123 ( struct V_23 * V_235 )
{
return 0 ;
}
static void F_124 ( struct V_23 * V_235 , struct V_26 * V_26 )
{
struct V_45 * V_46 = V_26 -> V_122 ;
struct V_11 * V_40 = F_28 ( F_7 ( V_235 ) ) ;
V_46 -> V_49 = V_40 ;
}
static int F_125 ( struct V_184 * V_189 , int V_244 , T_1 V_245 )
{
struct V_11 * V_40 = F_37 () ;
struct V_181 * V_182 ;
V_182 = F_13 ( sizeof( struct V_181 ) , V_245 ) ;
if ( V_182 == NULL )
return - V_64 ;
V_182 -> V_192 = V_40 ;
V_182 -> V_194 = V_40 ;
V_182 -> V_246 = NULL ;
V_189 -> V_190 = V_182 ;
return 0 ;
}
static void F_126 ( struct V_184 * V_189 )
{
F_15 ( V_189 -> V_190 ) ;
}
static struct V_11 * F_127 ( struct V_247 * V_248 )
{
struct V_249 * V_250 ;
struct V_251 * V_252 = & V_248 -> V_253 ;
if ( V_252 -> V_254 == 0 )
return NULL ;
F_22 (snp, &smk_netlbladdr_list, list)
if ( ( & V_250 -> V_255 . V_253 ) -> V_254 ==
( V_252 -> V_254 & ( & V_250 -> V_256 ) -> V_254 ) ) {
if ( V_250 -> V_257 == & V_258 )
return NULL ;
return V_250 -> V_257 ;
}
return NULL ;
}
static int F_128 ( struct V_184 * V_189 , int V_259 )
{
struct V_11 * V_40 ;
struct V_181 * V_182 = V_189 -> V_190 ;
int V_14 = 0 ;
F_129 () ;
F_130 ( V_189 ) ;
if ( V_182 -> V_194 == V_260 ||
V_259 == V_261 )
F_131 ( V_189 ) ;
else {
V_40 = V_182 -> V_194 ;
V_14 = F_132 ( V_189 , V_189 -> V_262 , & V_40 -> V_263 ) ;
}
F_133 ( V_189 ) ;
F_134 () ;
return V_14 ;
}
static int F_135 ( struct V_184 * V_189 , struct V_247 * V_264 )
{
struct V_11 * V_40 ;
int V_14 ;
int V_265 ;
struct V_11 * V_266 ;
struct V_181 * V_182 = V_189 -> V_190 ;
struct V_72 V_73 ;
F_51 () ;
V_266 = F_127 ( V_264 ) ;
if ( V_266 != NULL ) {
#ifdef F_136
struct V_267 V_268 ;
F_137 ( & V_73 , V_84 , V_269 , & V_268 ) ;
V_73 . V_270 . V_271 . V_268 -> V_244 = V_264 -> V_272 ;
V_73 . V_270 . V_271 . V_268 -> V_273 = V_264 -> V_274 ;
V_73 . V_270 . V_271 . V_268 -> V_275 . V_276 = V_264 -> V_253 . V_254 ;
#endif
V_265 = V_261 ;
V_40 = V_182 -> V_194 ;
V_14 = V_218 ( V_40 , V_266 , V_5 , & V_73 ) ;
V_14 = F_2 ( L_10 , V_40 , V_266 , V_5 , V_14 ) ;
} else {
V_265 = V_277 ;
V_14 = 0 ;
}
F_54 () ;
if ( V_14 != 0 )
return V_14 ;
return F_128 ( V_189 , V_265 ) ;
}
static void F_138 ( struct V_183 * V_184 , struct V_278 * V_279 )
{
struct V_184 * V_189 = V_184 -> V_189 ;
struct V_280 * V_281 ;
struct V_181 * V_182 = V_184 -> V_189 -> V_190 ;
struct V_282 * V_283 ;
unsigned short V_284 = 0 ;
if ( V_279 == NULL ) {
F_139 (spp, &smk_ipv6_port_list, list) {
if ( V_189 != V_283 -> V_285 )
continue;
V_283 -> V_192 = V_182 -> V_192 ;
V_283 -> V_194 = V_182 -> V_194 ;
return;
}
return;
}
V_281 = (struct V_280 * ) V_279 ;
V_284 = F_140 ( V_281 -> V_286 ) ;
if ( V_284 == 0 )
return;
F_139 (spp, &smk_ipv6_port_list, list) {
if ( V_283 -> V_287 != V_284 )
continue;
V_283 -> V_287 = V_284 ;
V_283 -> V_285 = V_189 ;
V_283 -> V_192 = V_182 -> V_192 ;
V_283 -> V_194 = V_182 -> V_194 ;
return;
}
V_283 = F_13 ( sizeof( * V_283 ) , V_44 ) ;
if ( V_283 == NULL )
return;
V_283 -> V_287 = V_284 ;
V_283 -> V_285 = V_189 ;
V_283 -> V_192 = V_182 -> V_192 ;
V_283 -> V_194 = V_182 -> V_194 ;
F_141 ( & V_283 -> V_65 , & V_288 ) ;
return;
}
static int F_142 ( struct V_184 * V_189 , struct V_280 * V_279 ,
int V_289 )
{
T_5 * V_290 ;
T_6 * V_291 ;
struct V_282 * V_283 ;
struct V_181 * V_182 = V_189 -> V_190 ;
struct V_11 * V_40 ;
unsigned short V_284 = 0 ;
struct V_11 * V_292 ;
struct V_72 V_73 ;
int V_14 ;
#ifdef F_136
struct V_267 V_268 ;
#endif
if ( V_289 == V_293 ) {
V_40 = V_260 ;
V_292 = V_182 -> V_192 ;
} else {
V_40 = V_182 -> V_194 ;
V_292 = V_260 ;
}
V_284 = F_140 ( V_279 -> V_286 ) ;
V_290 = ( T_5 * ) ( & V_279 -> V_294 ) ;
V_291 = ( T_6 * ) ( & V_279 -> V_294 ) ;
if ( V_291 [ 0 ] || V_291 [ 1 ] || V_291 [ 2 ] || V_290 [ 6 ] || F_140 ( V_290 [ 7 ] ) != 1 )
goto V_295;
if ( V_289 == V_293 ) {
V_40 = & V_177 ;
goto V_295;
}
F_139 (spp, &smk_ipv6_port_list, list) {
if ( V_283 -> V_287 != V_284 )
continue;
V_292 = V_283 -> V_192 ;
if ( V_289 == V_296 )
V_182 -> V_246 = V_283 -> V_194 ;
break;
}
V_295:
#ifdef F_136
F_137 ( & V_73 , V_84 , V_269 , & V_268 ) ;
V_73 . V_270 . V_271 . V_268 -> V_244 = V_189 -> V_262 ;
V_73 . V_270 . V_271 . V_268 -> V_273 = V_284 ;
if ( V_289 == V_293 )
V_73 . V_270 . V_271 . V_268 -> V_297 . V_298 = V_279 -> V_294 ;
else
V_73 . V_270 . V_271 . V_268 -> V_297 . V_276 = V_279 -> V_294 ;
#endif
V_14 = V_218 ( V_40 , V_292 , V_5 , & V_73 ) ;
V_14 = F_2 ( L_11 , V_40 , V_292 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_143 ( struct V_26 * V_26 , const char * V_35 ,
const void * V_140 , T_2 V_163 , int V_110 )
{
struct V_11 * V_40 ;
struct V_45 * V_299 = V_26 -> V_122 ;
struct V_181 * V_182 ;
struct V_183 * V_184 ;
int V_14 = 0 ;
if ( V_140 == NULL || V_163 > V_43 || V_163 == 0 )
return - V_175 ;
V_40 = F_14 ( V_140 , V_163 ) ;
if ( V_40 == NULL )
return - V_175 ;
if ( strcmp ( V_35 , V_145 ) == 0 ) {
V_299 -> V_49 = V_40 ;
V_299 -> V_50 |= V_300 ;
return 0 ;
}
if ( V_26 -> V_27 -> V_186 != V_187 )
return - V_188 ;
V_184 = F_81 ( V_26 ) ;
if ( V_184 == NULL || V_184 -> V_189 == NULL )
return - V_188 ;
V_182 = V_184 -> V_189 -> V_190 ;
if ( strcmp ( V_35 , V_191 ) == 0 )
V_182 -> V_192 = V_40 ;
else if ( strcmp ( V_35 , V_193 ) == 0 ) {
V_182 -> V_194 = V_40 ;
if ( V_184 -> V_189 -> V_262 == V_301 ) {
V_14 = F_128 ( V_184 -> V_189 , V_277 ) ;
if ( V_14 != 0 )
F_144 ( V_302
L_12 ,
V_84 , - V_14 ) ;
}
} else
return - V_188 ;
if ( V_184 -> V_189 -> V_262 == V_303 )
F_138 ( V_184 , NULL ) ;
return 0 ;
}
static int F_145 ( struct V_183 * V_184 , int V_244 ,
int type , int V_304 , int V_305 )
{
if ( V_244 != V_301 || V_184 -> V_189 == NULL )
return 0 ;
return F_128 ( V_184 -> V_189 , V_277 ) ;
}
static int F_146 ( struct V_183 * V_184 , struct V_278 * V_279 ,
int V_306 )
{
if ( V_184 -> V_189 != NULL && V_184 -> V_189 -> V_262 == V_303 )
F_138 ( V_184 , V_279 ) ;
return 0 ;
}
static int F_147 ( struct V_183 * V_184 , struct V_278 * V_264 ,
int V_306 )
{
int V_14 = 0 ;
if ( V_184 -> V_189 == NULL )
return 0 ;
switch ( V_184 -> V_189 -> V_262 ) {
case V_301 :
if ( V_306 < sizeof( struct V_247 ) )
return - V_175 ;
V_14 = F_135 ( V_184 -> V_189 , (struct V_247 * ) V_264 ) ;
break;
case V_303 :
if ( V_306 < sizeof( struct V_280 ) )
return - V_175 ;
V_14 = F_142 ( V_184 -> V_189 , (struct V_280 * ) V_264 ,
V_296 ) ;
break;
}
return V_14 ;
}
static int F_148 ( int V_110 )
{
int V_144 = 0 ;
if ( V_110 & V_307 )
V_144 |= V_4 ;
if ( V_110 & V_308 )
V_144 |= V_5 ;
if ( V_110 & V_309 )
V_144 |= V_6 ;
return V_144 ;
}
static int F_149 ( struct V_310 * V_311 )
{
struct V_11 * V_40 = F_37 () ;
V_311 -> V_34 = V_40 ;
return 0 ;
}
static void F_150 ( struct V_310 * V_311 )
{
V_311 -> V_34 = NULL ;
}
static struct V_11 * F_151 ( struct V_312 * V_313 )
{
return (struct V_11 * ) V_313 -> V_314 . V_34 ;
}
static int F_152 ( struct V_312 * V_313 )
{
struct V_315 * V_46 = & V_313 -> V_314 ;
struct V_11 * V_40 = F_37 () ;
V_46 -> V_34 = V_40 ;
return 0 ;
}
static void F_153 ( struct V_312 * V_313 )
{
struct V_315 * V_46 = & V_313 -> V_314 ;
V_46 -> V_34 = NULL ;
}
static int F_154 ( struct V_312 * V_313 , int V_236 )
{
struct V_11 * V_182 = F_151 ( V_313 ) ;
struct V_72 V_73 ;
int V_14 ;
#ifdef F_136
F_26 ( & V_73 , V_84 , V_316 ) ;
V_73 . V_270 . V_271 . V_317 = V_313 -> V_314 . V_318 ;
#endif
V_14 = F_47 ( V_182 , V_236 , & V_73 ) ;
V_14 = F_4 ( L_13 , V_182 , V_236 , V_14 ) ;
return V_14 ;
}
static int F_155 ( struct V_312 * V_313 , int V_319 )
{
int V_144 ;
V_144 = F_148 ( V_319 ) ;
return F_154 ( V_313 , V_144 ) ;
}
static int F_156 ( struct V_312 * V_313 , int V_198 )
{
int V_144 ;
switch ( V_198 ) {
case V_320 :
case V_321 :
V_144 = V_4 ;
break;
case V_322 :
case V_323 :
case V_324 :
case V_325 :
V_144 = V_68 ;
break;
case V_326 :
case V_327 :
return 0 ;
default:
return - V_175 ;
}
return F_154 ( V_313 , V_144 ) ;
}
static int F_157 ( struct V_312 * V_313 , char T_7 * V_328 ,
int V_319 )
{
int V_144 ;
V_144 = F_148 ( V_319 ) ;
return F_154 ( V_313 , V_144 ) ;
}
static struct V_11 * F_158 ( struct V_329 * V_330 )
{
return (struct V_11 * ) V_330 -> V_331 . V_34 ;
}
static int F_159 ( struct V_329 * V_330 )
{
struct V_315 * V_46 = & V_330 -> V_331 ;
struct V_11 * V_40 = F_37 () ;
V_46 -> V_34 = V_40 ;
return 0 ;
}
static void F_160 ( struct V_329 * V_330 )
{
struct V_315 * V_46 = & V_330 -> V_331 ;
V_46 -> V_34 = NULL ;
}
static int F_161 ( struct V_329 * V_330 , int V_236 )
{
struct V_11 * V_182 = F_158 ( V_330 ) ;
struct V_72 V_73 ;
int V_14 ;
#ifdef F_136
F_26 ( & V_73 , V_84 , V_316 ) ;
V_73 . V_270 . V_271 . V_317 = V_330 -> V_331 . V_318 ;
#endif
V_14 = F_47 ( V_182 , V_236 , & V_73 ) ;
V_14 = F_4 ( L_14 , V_182 , V_236 , V_14 ) ;
return V_14 ;
}
static int F_162 ( struct V_329 * V_330 , int V_332 )
{
int V_144 ;
V_144 = F_148 ( V_332 ) ;
return F_161 ( V_330 , V_144 ) ;
}
static int F_163 ( struct V_329 * V_330 , int V_198 )
{
int V_144 ;
switch ( V_198 ) {
case V_333 :
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_320 :
case V_338 :
V_144 = V_4 ;
break;
case V_339 :
case V_340 :
case V_325 :
case V_322 :
V_144 = V_68 ;
break;
case V_326 :
case V_341 :
return 0 ;
default:
return - V_175 ;
}
return F_161 ( V_330 , V_144 ) ;
}
static int F_164 ( struct V_329 * V_330 , struct V_342 * V_343 ,
unsigned V_344 , int V_345 )
{
return F_161 ( V_330 , V_68 ) ;
}
static int F_165 ( struct V_346 * V_347 )
{
struct V_315 * V_348 = & V_347 -> V_349 ;
struct V_11 * V_40 = F_37 () ;
V_348 -> V_34 = V_40 ;
return 0 ;
}
static void F_166 ( struct V_346 * V_347 )
{
struct V_315 * V_348 = & V_347 -> V_349 ;
V_348 -> V_34 = NULL ;
}
static struct V_11 * F_167 ( struct V_346 * V_347 )
{
return (struct V_11 * ) V_347 -> V_349 . V_34 ;
}
static int F_168 ( struct V_346 * V_347 , int V_236 )
{
struct V_11 * V_350 = F_167 ( V_347 ) ;
struct V_72 V_73 ;
int V_14 ;
#ifdef F_136
F_26 ( & V_73 , V_84 , V_316 ) ;
V_73 . V_270 . V_271 . V_317 = V_347 -> V_349 . V_318 ;
#endif
V_14 = F_47 ( V_350 , V_236 , & V_73 ) ;
V_14 = F_4 ( L_15 , V_350 , V_236 , V_14 ) ;
return V_14 ;
}
static int F_169 ( struct V_346 * V_347 , int V_351 )
{
int V_144 ;
V_144 = F_148 ( V_351 ) ;
return F_168 ( V_347 , V_144 ) ;
}
static int F_170 ( struct V_346 * V_347 , int V_198 )
{
int V_144 ;
switch ( V_198 ) {
case V_320 :
case V_352 :
V_144 = V_4 ;
break;
case V_322 :
case V_325 :
V_144 = V_68 ;
break;
case V_326 :
case V_353 :
return 0 ;
default:
return - V_175 ;
}
return F_168 ( V_347 , V_144 ) ;
}
static int F_171 ( struct V_346 * V_347 , struct V_310 * V_311 ,
int V_351 )
{
int V_144 ;
V_144 = F_148 ( V_351 ) ;
return F_168 ( V_347 , V_144 ) ;
}
static int F_172 ( struct V_346 * V_347 , struct V_310 * V_311 ,
struct V_23 * V_354 , long type , int V_1 )
{
return F_168 ( V_347 , V_68 ) ;
}
static int F_173 ( struct V_315 * V_355 , short V_356 )
{
struct V_11 * V_357 = V_355 -> V_34 ;
int V_144 = F_148 ( V_356 ) ;
struct V_72 V_73 ;
int V_14 ;
#ifdef F_136
F_26 ( & V_73 , V_84 , V_316 ) ;
V_73 . V_270 . V_271 . V_317 = V_355 -> V_318 ;
#endif
V_14 = F_47 ( V_357 , V_144 , & V_73 ) ;
V_14 = F_4 ( L_16 , V_357 , V_144 , V_14 ) ;
return V_14 ;
}
static void F_174 ( struct V_315 * V_355 , T_3 * V_196 )
{
struct V_11 * V_357 = V_355 -> V_34 ;
* V_196 = V_357 -> V_197 ;
}
static void F_175 ( struct V_37 * V_358 , struct V_26 * V_26 )
{
struct V_89 * V_124 ;
struct V_91 * V_92 ;
struct V_45 * V_46 ;
struct V_11 * V_40 ;
struct V_11 * V_359 = F_37 () ;
struct V_11 * V_360 ;
char V_361 [ V_173 ] ;
int V_362 = 0 ;
int V_14 ;
struct V_37 * V_38 ;
if ( V_26 == NULL )
return;
V_46 = V_26 -> V_122 ;
F_176 ( & V_46 -> V_51 ) ;
if ( V_46 -> V_50 & V_300 )
goto V_363;
V_124 = V_26 -> V_27 ;
V_92 = V_124 -> V_99 ;
V_360 = V_92 -> V_95 ;
if ( V_358 -> V_364 == V_358 ) {
if ( V_124 -> V_186 == V_365 ) {
V_92 -> V_93 = & V_176 ;
V_92 -> V_95 = & V_176 ;
}
V_46 -> V_49 = V_92 -> V_93 ;
V_46 -> V_50 |= V_300 ;
goto V_363;
}
switch ( V_124 -> V_186 ) {
case V_366 :
case V_367 :
case V_187 :
case V_365 :
V_360 = & V_176 ;
break;
case V_368 :
V_360 = V_359 ;
break;
case V_369 :
break;
case V_370 :
V_360 = & V_176 ;
default:
if ( F_177 ( V_26 -> V_371 ) ) {
V_360 = & V_176 ;
break;
}
if ( V_26 -> V_41 -> V_42 == NULL )
break;
V_38 = F_178 ( V_358 ) ;
V_40 = F_12 ( V_167 , V_26 , V_38 ) ;
if ( V_40 != NULL )
V_360 = V_40 ;
if ( F_179 ( V_26 -> V_371 ) ) {
if ( V_46 -> V_50 & V_146 ) {
V_46 -> V_50 &= ~ V_146 ;
V_14 = V_26 -> V_41 -> V_372 ( V_38 ,
V_172 ,
V_174 , V_173 ,
0 ) ;
} else {
V_14 = V_26 -> V_41 -> V_42 ( V_38 ,
V_172 , V_361 ,
V_173 ) ;
if ( V_14 >= 0 && strncmp ( V_361 , V_174 ,
V_173 ) != 0 )
V_14 = - V_175 ;
}
if ( V_14 >= 0 )
V_362 = V_123 ;
}
V_40 = F_12 ( V_170 , V_26 , V_38 ) ;
if ( V_40 == & V_176 || V_40 == & V_177 )
V_40 = NULL ;
V_46 -> V_20 = V_40 ;
V_40 = F_12 ( V_171 , V_26 , V_38 ) ;
if ( V_40 == & V_176 || V_40 == & V_177 )
V_40 = NULL ;
V_46 -> V_179 = V_40 ;
F_180 ( V_38 ) ;
break;
}
if ( V_360 == NULL )
V_46 -> V_49 = V_359 ;
else
V_46 -> V_49 = V_360 ;
V_46 -> V_50 |= ( V_300 | V_362 ) ;
V_363:
F_181 ( & V_46 -> V_51 ) ;
return;
}
static int F_182 ( struct V_23 * V_235 , char * V_35 , char * * V_140 )
{
struct V_11 * V_40 = F_28 ( F_7 ( V_235 ) ) ;
char * V_102 ;
int V_373 ;
if ( strcmp ( V_35 , L_17 ) != 0 )
return - V_175 ;
V_102 = F_64 ( V_40 -> V_17 , V_44 ) ;
if ( V_102 == NULL )
return - V_64 ;
V_373 = strlen ( V_102 ) ;
* V_140 = V_102 ;
return V_373 ;
}
static int F_183 ( struct V_23 * V_235 , char * V_35 ,
void * V_140 , T_2 V_163 )
{
struct V_18 * V_19 ;
struct V_33 * V_231 ;
struct V_11 * V_40 ;
if ( V_235 != V_21 )
return - V_121 ;
if ( ! F_38 ( V_120 ) )
return - V_121 ;
if ( V_140 == NULL || V_163 == 0 || V_163 >= V_43 )
return - V_175 ;
if ( strcmp ( V_35 , L_17 ) != 0 )
return - V_175 ;
V_40 = F_14 ( V_140 , V_163 ) ;
if ( V_40 == NULL )
return - V_175 ;
if ( V_40 == & V_177 )
return - V_121 ;
V_231 = F_184 () ;
if ( V_231 == NULL )
return - V_64 ;
V_19 = V_231 -> V_34 ;
V_19 -> V_20 = V_40 ;
F_185 ( V_231 ) ;
return V_163 ;
}
static int F_186 ( struct V_184 * V_184 ,
struct V_184 * V_374 , struct V_184 * V_375 )
{
struct V_11 * V_40 ;
struct V_11 * V_212 ;
struct V_181 * V_182 = V_184 -> V_190 ;
struct V_181 * V_376 = V_374 -> V_190 ;
struct V_181 * V_299 = V_375 -> V_190 ;
struct V_72 V_73 ;
int V_14 = 0 ;
#ifdef F_136
struct V_267 V_268 ;
#endif
if ( ! F_38 ( V_87 ) ) {
V_40 = V_182 -> V_194 ;
V_212 = V_376 -> V_194 ;
#ifdef F_136
F_137 ( & V_73 , V_84 , V_269 , & V_268 ) ;
F_187 ( & V_73 , V_374 ) ;
#endif
V_14 = V_218 ( V_40 , V_212 , V_5 , & V_73 ) ;
V_14 = F_2 ( L_18 , V_40 , V_212 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_14 = V_218 ( V_212 , V_40 , V_5 , NULL ) ;
V_14 = F_2 ( L_18 , V_212 , V_40 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_299 -> V_246 = V_182 -> V_194 ;
V_182 -> V_246 = V_376 -> V_194 ;
}
return V_14 ;
}
static int F_188 ( struct V_183 * V_184 , struct V_183 * V_374 )
{
struct V_181 * V_182 = V_184 -> V_189 -> V_190 ;
struct V_181 * V_376 = V_374 -> V_189 -> V_190 ;
struct V_72 V_73 ;
int V_14 ;
#ifdef F_136
struct V_267 V_268 ;
F_137 ( & V_73 , V_84 , V_269 , & V_268 ) ;
F_187 ( & V_73 , V_374 -> V_189 ) ;
#endif
if ( F_38 ( V_87 ) )
return 0 ;
V_14 = V_218 ( V_182 -> V_194 , V_376 -> V_192 , V_5 , & V_73 ) ;
V_14 = F_2 ( L_19 , V_182 -> V_194 , V_376 -> V_192 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_189 ( struct V_183 * V_184 , struct V_377 * V_311 ,
int V_163 )
{
struct V_247 * V_248 = (struct V_247 * ) V_311 -> V_378 ;
struct V_280 * V_264 = (struct V_280 * ) V_311 -> V_378 ;
int V_14 = 0 ;
if ( V_248 == NULL )
return 0 ;
switch ( V_248 -> V_272 ) {
case V_379 :
V_14 = F_135 ( V_184 -> V_189 , V_248 ) ;
break;
case V_380 :
V_14 = F_142 ( V_184 -> V_189 , V_264 , V_381 ) ;
break;
}
return V_14 ;
}
static struct V_11 * F_190 ( struct V_382 * V_264 ,
struct V_181 * V_182 )
{
struct V_11 * V_40 ;
int V_383 = 0 ;
int V_384 ;
int V_385 ;
if ( ( V_264 -> V_110 & V_386 ) != 0 ) {
F_51 () ;
F_139 (skp, &smack_known_list, list) {
if ( V_264 -> V_387 . V_388 . V_389 != V_40 -> V_263 . V_387 . V_388 . V_389 )
continue;
if ( ( V_264 -> V_110 & V_390 ) == 0 ) {
if ( ( V_40 -> V_263 . V_110 &
V_390 ) == 0 )
V_383 = 1 ;
break;
}
for ( V_384 = - 1 , V_385 = - 1 ; V_384 == V_385 ; ) {
V_384 = F_191 ( V_264 -> V_387 . V_388 . V_391 ,
V_384 + 1 ) ;
V_385 = F_191 (
V_40 -> V_263 . V_387 . V_388 . V_391 ,
V_385 + 1 ) ;
if ( V_384 < 0 || V_385 < 0 )
break;
}
if ( V_384 == V_385 ) {
V_383 = 1 ;
break;
}
}
F_54 () ;
if ( V_383 )
return V_40 ;
if ( V_182 != NULL && V_182 -> V_192 == & V_176 )
return & V_177 ;
return & V_176 ;
}
if ( ( V_264 -> V_110 & V_392 ) != 0 ) {
V_40 = F_106 ( V_264 -> V_387 . V_196 ) ;
F_192 ( V_40 == NULL ) ;
return V_40 ;
}
return V_260 ;
}
static int F_193 ( struct V_393 * V_394 , struct V_280 * V_248 )
{
T_8 V_395 ;
int V_396 ;
int V_397 = - V_175 ;
struct V_398 V_399 ;
struct V_398 * V_400 ;
T_5 V_401 ;
struct V_402 V_403 , * V_404 ;
struct V_405 V_406 , * V_407 ;
struct V_408 V_409 , * V_410 ;
V_248 -> V_286 = 0 ;
V_396 = F_194 ( V_394 ) ;
V_400 = F_195 ( V_394 , V_396 , sizeof( V_399 ) , & V_399 ) ;
if ( V_400 == NULL )
return - V_175 ;
V_248 -> V_294 = V_400 -> V_298 ;
V_395 = V_400 -> V_395 ;
V_396 += sizeof( V_399 ) ;
V_396 = F_196 ( V_394 , V_396 , & V_395 , & V_401 ) ;
if ( V_396 < 0 )
return - V_175 ;
V_397 = V_395 ;
switch ( V_397 ) {
case V_411 :
V_404 = F_195 ( V_394 , V_396 , sizeof( V_403 ) , & V_403 ) ;
if ( V_404 != NULL )
V_248 -> V_286 = V_404 -> V_412 ;
break;
case V_413 :
V_407 = F_195 ( V_394 , V_396 , sizeof( V_406 ) , & V_406 ) ;
if ( V_407 != NULL )
V_248 -> V_286 = V_407 -> V_412 ;
break;
case V_414 :
V_410 = F_195 ( V_394 , V_396 , sizeof( V_409 ) , & V_409 ) ;
if ( V_410 != NULL )
V_248 -> V_286 = V_410 -> V_415 ;
break;
}
return V_397 ;
}
static int F_197 ( struct V_184 * V_189 , struct V_393 * V_394 )
{
struct V_382 V_416 ;
struct V_181 * V_182 = V_189 -> V_190 ;
struct V_11 * V_40 ;
struct V_280 V_417 ;
int V_14 = 0 ;
struct V_72 V_73 ;
#ifdef F_136
struct V_267 V_268 ;
#endif
switch ( V_189 -> V_262 ) {
case V_301 :
F_198 ( & V_416 ) ;
V_14 = F_199 ( V_394 , V_189 -> V_262 , & V_416 ) ;
if ( V_14 == 0 )
V_40 = F_190 ( & V_416 , V_182 ) ;
else
V_40 = V_260 ;
F_200 ( & V_416 ) ;
#ifdef F_136
F_137 ( & V_73 , V_84 , V_269 , & V_268 ) ;
V_73 . V_270 . V_271 . V_268 -> V_244 = V_189 -> V_262 ;
V_73 . V_270 . V_271 . V_268 -> V_418 = V_394 -> V_419 ;
F_201 ( V_394 , & V_73 . V_270 , NULL ) ;
#endif
V_14 = V_218 ( V_40 , V_182 -> V_192 , V_5 , & V_73 ) ;
V_14 = F_2 ( L_20 , V_40 , V_182 -> V_192 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_202 ( V_394 , V_14 , 0 ) ;
break;
case V_303 :
V_14 = F_193 ( V_394 , & V_417 ) ;
if ( V_14 == V_413 || V_14 == V_411 )
V_14 = F_142 ( V_189 , & V_417 , V_293 ) ;
else
V_14 = 0 ;
break;
}
return V_14 ;
}
static int F_203 ( struct V_183 * V_184 ,
char T_7 * V_420 ,
int T_7 * V_421 , unsigned V_141 )
{
struct V_181 * V_182 ;
char * V_422 = L_21 ;
int V_373 = 1 ;
int V_14 = 0 ;
V_182 = V_184 -> V_189 -> V_190 ;
if ( V_182 -> V_246 != NULL ) {
V_422 = V_182 -> V_246 -> V_17 ;
V_373 = strlen ( V_422 ) + 1 ;
}
if ( V_373 > V_141 )
V_14 = - V_423 ;
else if ( F_204 ( V_420 , V_422 , V_373 ) != 0 )
V_14 = - V_424 ;
if ( F_205 ( V_373 , V_421 ) != 0 )
V_14 = - V_424 ;
return V_14 ;
}
static int F_206 ( struct V_183 * V_184 ,
struct V_393 * V_394 , T_3 * V_196 )
{
struct V_382 V_416 ;
struct V_181 * V_182 = NULL ;
struct V_11 * V_40 ;
int V_244 = V_425 ;
T_3 V_2 = 0 ;
int V_14 ;
if ( V_394 != NULL ) {
if ( V_394 -> V_304 == F_207 ( V_426 ) )
V_244 = V_301 ;
else if ( V_394 -> V_304 == F_207 ( V_427 ) )
V_244 = V_303 ;
}
if ( V_244 == V_425 && V_184 != NULL )
V_244 = V_184 -> V_189 -> V_262 ;
if ( V_244 == V_428 ) {
V_182 = V_184 -> V_189 -> V_190 ;
V_2 = V_182 -> V_194 -> V_197 ;
} else if ( V_244 == V_301 || V_244 == V_303 ) {
if ( V_184 != NULL && V_184 -> V_189 != NULL )
V_182 = V_184 -> V_189 -> V_190 ;
F_198 ( & V_416 ) ;
V_14 = F_199 ( V_394 , V_244 , & V_416 ) ;
if ( V_14 == 0 ) {
V_40 = F_190 ( & V_416 , V_182 ) ;
V_2 = V_40 -> V_197 ;
}
F_200 ( & V_416 ) ;
}
* V_196 = V_2 ;
if ( V_2 == 0 )
return - V_175 ;
return 0 ;
}
static void F_208 ( struct V_184 * V_189 , struct V_183 * V_429 )
{
struct V_181 * V_182 ;
struct V_11 * V_40 = F_37 () ;
if ( V_189 == NULL ||
( V_189 -> V_262 != V_301 && V_189 -> V_262 != V_303 ) )
return;
V_182 = V_189 -> V_190 ;
V_182 -> V_192 = V_40 ;
V_182 -> V_194 = V_40 ;
}
static int F_209 ( struct V_184 * V_189 , struct V_393 * V_394 ,
struct V_430 * V_431 )
{
T_9 V_244 = V_189 -> V_262 ;
struct V_11 * V_40 ;
struct V_181 * V_182 = V_189 -> V_190 ;
struct V_382 V_416 ;
struct V_247 V_432 ;
struct V_433 * V_434 ;
struct V_11 * V_435 ;
int V_14 ;
struct V_72 V_73 ;
#ifdef F_136
struct V_267 V_268 ;
#endif
if ( V_244 == V_303 ) {
if ( V_394 -> V_304 == F_207 ( V_426 ) )
V_244 = V_301 ;
else
return 0 ;
}
F_198 ( & V_416 ) ;
V_14 = F_199 ( V_394 , V_244 , & V_416 ) ;
if ( V_14 == 0 )
V_40 = F_190 ( & V_416 , V_182 ) ;
else
V_40 = & V_436 ;
F_200 ( & V_416 ) ;
#ifdef F_136
F_137 ( & V_73 , V_84 , V_269 , & V_268 ) ;
V_73 . V_270 . V_271 . V_268 -> V_244 = V_244 ;
V_73 . V_270 . V_271 . V_268 -> V_418 = V_394 -> V_419 ;
F_201 ( V_394 , & V_73 . V_270 , NULL ) ;
#endif
V_14 = V_218 ( V_40 , V_182 -> V_192 , V_5 , & V_73 ) ;
V_14 = F_2 ( L_22 , V_40 , V_182 -> V_192 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_431 -> V_437 = V_40 -> V_197 ;
V_434 = F_210 ( V_394 ) ;
V_432 . V_253 . V_254 = V_434 -> V_298 ;
F_51 () ;
V_435 = F_127 ( & V_432 ) ;
F_54 () ;
if ( V_435 == NULL )
V_14 = F_211 ( V_431 , & V_40 -> V_263 ) ;
else
F_212 ( V_431 ) ;
return V_14 ;
}
static void F_213 ( struct V_184 * V_189 ,
const struct V_430 * V_431 )
{
struct V_181 * V_182 = V_189 -> V_190 ;
struct V_11 * V_40 ;
if ( V_431 -> V_437 != 0 ) {
V_40 = F_106 ( V_431 -> V_437 ) ;
V_182 -> V_246 = V_40 ;
} else
V_182 -> V_246 = NULL ;
}
static int F_214 ( struct V_438 * V_438 , const struct V_33 * V_33 ,
unsigned long V_110 )
{
struct V_11 * V_40 = F_28 ( V_33 -> V_34 ) ;
V_438 -> V_34 = V_40 ;
return 0 ;
}
static void F_215 ( struct V_438 * V_438 )
{
V_438 -> V_34 = NULL ;
}
static int F_216 ( T_10 V_439 ,
const struct V_33 * V_33 , unsigned V_440 )
{
struct V_438 * V_441 ;
struct V_72 V_73 ;
struct V_11 * V_223 = F_28 ( V_33 -> V_34 ) ;
int V_442 = 0 ;
int V_14 ;
V_441 = F_217 ( V_439 ) ;
if ( V_441 == NULL )
return - V_175 ;
if ( V_441 -> V_34 == NULL )
return 0 ;
if ( V_223 == NULL )
return - V_81 ;
#ifdef F_136
F_26 ( & V_73 , V_84 , V_443 ) ;
V_73 . V_270 . V_271 . V_444 . V_438 = V_441 -> V_445 ;
V_73 . V_270 . V_271 . V_444 . V_446 = V_441 -> V_447 ;
#endif
if ( V_440 & V_448 )
V_442 = V_4 ;
if ( V_440 & ( V_449 | V_450 | V_451 ) )
V_442 = V_5 ;
V_14 = V_218 ( V_223 , V_441 -> V_34 , V_442 , & V_73 ) ;
V_14 = F_2 ( L_23 , V_223 , V_441 -> V_34 , V_442 , V_14 ) ;
return V_14 ;
}
static int F_218 ( T_3 V_452 , T_3 V_116 , char * V_453 , void * * V_454 )
{
struct V_11 * V_40 ;
char * * V_455 = ( char * * ) V_454 ;
* V_455 = NULL ;
if ( V_452 != V_456 && V_452 != V_457 )
return - V_175 ;
if ( V_116 != V_458 && V_116 != V_459 )
return - V_175 ;
V_40 = F_14 ( V_453 , 0 ) ;
if ( V_40 )
* V_455 = V_40 -> V_17 ;
return 0 ;
}
static int F_219 ( struct V_460 * V_461 )
{
struct V_462 * V_463 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_461 -> V_464 ; V_3 ++ ) {
V_463 = & V_461 -> V_465 [ V_3 ] ;
if ( V_463 -> type == V_456 || V_463 -> type == V_457 )
return 1 ;
}
return 0 ;
}
static int F_220 ( T_3 V_196 , T_3 V_452 , T_3 V_116 , void * V_454 ,
struct V_466 * V_467 )
{
struct V_11 * V_40 ;
char * V_455 = V_454 ;
if ( F_221 ( ! V_455 ) ) {
F_222 ( 1 , L_24 ) ;
return - V_217 ;
}
if ( V_452 != V_456 && V_452 != V_457 )
return 0 ;
V_40 = F_106 ( V_196 ) ;
if ( V_116 == V_458 )
return ( V_455 == V_40 -> V_17 ) ;
if ( V_116 == V_459 )
return ( V_455 != V_40 -> V_17 ) ;
return 0 ;
}
static void F_223 ( void * V_454 )
{
}
static int F_224 ( const char * V_35 )
{
return ( strcmp ( V_35 , V_145 ) == 0 ) ;
}
static int F_225 ( T_3 V_196 , char * * V_468 , T_3 * V_469 )
{
struct V_11 * V_40 = F_106 ( V_196 ) ;
if ( V_468 )
* V_468 = V_40 -> V_17 ;
* V_469 = strlen ( V_40 -> V_17 ) ;
return 0 ;
}
static int F_226 ( const char * V_468 , T_3 V_469 , T_3 * V_196 )
{
struct V_11 * V_40 = F_227 ( V_468 ) ;
if ( V_40 )
* V_196 = V_40 -> V_197 ;
else
* V_196 = 0 ;
return 0 ;
}
static void F_228 ( char * V_468 , T_3 V_469 )
{
}
static int F_229 ( struct V_26 * V_26 , void * V_470 , T_3 V_471 )
{
return F_143 ( V_26 , V_145 , V_470 , V_471 , 0 ) ;
}
static int F_230 ( struct V_37 * V_37 , void * V_470 , T_3 V_471 )
{
return F_231 ( V_37 , V_167 , V_470 , V_471 , 0 ) ;
}
static int F_232 ( struct V_26 * V_26 , void * * V_470 , T_3 * V_471 )
{
int V_141 = 0 ;
V_141 = F_80 ( V_26 , V_145 , V_470 , true ) ;
if ( V_141 < 0 )
return V_141 ;
* V_471 = V_141 ;
return 0 ;
}
static T_11 void F_233 ( void )
{
F_18 ( & V_436 . V_57 ) ;
F_18 ( & V_98 . V_57 ) ;
F_18 ( & V_94 . V_57 ) ;
F_18 ( & V_176 . V_57 ) ;
F_18 ( & V_178 . V_57 ) ;
F_18 ( & V_177 . V_57 ) ;
F_20 ( & V_436 . V_56 ) ;
F_20 ( & V_98 . V_56 ) ;
F_20 ( & V_176 . V_56 ) ;
F_20 ( & V_94 . V_56 ) ;
F_20 ( & V_178 . V_56 ) ;
F_20 ( & V_177 . V_56 ) ;
F_234 ( & V_436 ) ;
F_234 ( & V_98 ) ;
F_234 ( & V_176 ) ;
F_234 ( & V_94 ) ;
F_234 ( & V_178 ) ;
F_234 ( & V_177 ) ;
}
static T_11 int F_235 ( void )
{
struct V_33 * V_33 ;
struct V_18 * V_19 ;
if ( ! F_236 ( & V_472 ) )
return 0 ;
V_47 = F_237 ( V_45 , 0 ) ;
if ( ! V_47 )
return - V_64 ;
V_19 = F_19 ( & V_94 , & V_94 ,
V_44 ) ;
if ( V_19 == NULL ) {
F_238 ( V_47 ) ;
return - V_64 ;
}
F_144 ( V_473 L_25 ) ;
V_33 = (struct V_33 * ) V_21 -> V_33 ;
V_33 -> V_34 = V_19 ;
F_233 () ;
if ( F_239 ( & V_472 ) )
F_240 ( L_26 ) ;
return 0 ;
}

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
if ( V_14 > V_17 )
V_14 = 0 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_1 , V_18 [ V_14 ] ,
V_12 -> V_19 , V_13 -> V_19 , V_15 , V_10 ) ;
return 0 ;
}
static int F_4 ( char * V_10 , struct V_11 * V_13 ,
int V_1 , int V_14 )
{
struct V_20 * V_21 = F_5 () ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_2 , V_18 [ V_14 ] ,
V_21 -> V_22 -> V_19 , V_13 -> V_19 ,
V_15 , V_23 -> V_24 , V_10 ) ;
return 0 ;
}
static int F_6 ( struct V_25 * V_26 , int V_1 , int V_14 )
{
struct V_20 * V_21 = F_5 () ;
struct V_11 * V_22 = F_7 ( V_26 ) ;
char V_15 [ V_16 + 1 ] ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_3 , V_18 [ V_14 ] ,
V_21 -> V_22 -> V_19 , V_22 -> V_19 , V_15 ,
V_23 -> V_24 , V_26 -> V_24 ) ;
return 0 ;
}
static int F_8 ( struct V_27 * V_27 , int V_1 , int V_14 )
{
struct V_20 * V_21 = F_5 () ;
struct V_28 * V_29 = V_27 -> V_30 ;
char V_15 [ V_16 + 1 ] ;
if ( V_29 -> V_31 & V_32 )
F_3 ( L_4 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_23 -> V_24 ) ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
if ( V_14 == V_36 &&
( V_1 & ( V_5 | V_7 ) ) )
V_29 -> V_31 |= V_32 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_5 , V_18 [ V_14 ] ,
V_21 -> V_22 -> V_19 , V_29 -> V_37 -> V_19 , V_15 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_23 -> V_24 ) ;
return 0 ;
}
static int F_9 ( struct V_38 * V_38 , int V_1 , int V_14 )
{
struct V_20 * V_21 = F_5 () ;
struct V_11 * V_12 = V_21 -> V_22 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_28 * V_29 = V_27 -> V_30 ;
char V_15 [ V_16 + 1 ] ;
if ( V_29 -> V_31 & V_32 )
F_3 ( L_4 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_23 -> V_24 ) ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_6 , V_18 [ V_14 ] ,
V_12 -> V_19 , F_11 ( V_27 ) -> V_19 , V_15 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_38 ,
V_23 -> V_24 ) ;
return 0 ;
}
static int F_12 ( const struct V_39 * V_39 , struct V_38 * V_38 ,
int V_1 , int V_14 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_11 * V_12 = V_21 -> V_22 ;
struct V_27 * V_27 = V_38 -> V_41 ;
struct V_28 * V_29 = V_27 -> V_30 ;
char V_15 [ V_16 + 1 ] ;
if ( V_29 -> V_31 & V_32 )
F_3 ( L_4 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_23 -> V_24 ) ;
if ( V_14 <= 0 )
return V_14 ;
if ( V_14 > V_17 )
V_14 = 0 ;
F_1 ( V_1 , V_15 ) ;
F_3 ( L_6 , V_18 [ V_14 ] ,
V_12 -> V_19 , F_11 ( V_27 ) -> V_19 , V_15 ,
V_27 -> V_33 -> V_34 , V_27 -> V_35 , V_38 ,
V_23 -> V_24 ) ;
return 0 ;
}
static struct V_11 * F_13 ( const char * V_42 , struct V_27 * V_43 ,
struct V_44 * V_45 )
{
int V_14 ;
char * V_46 ;
struct V_11 * V_47 = NULL ;
if ( V_43 -> V_48 -> V_49 == NULL )
return F_14 ( - V_50 ) ;
V_46 = F_15 ( V_51 , V_52 ) ;
if ( V_46 == NULL )
return F_14 ( - V_53 ) ;
V_14 = V_43 -> V_48 -> V_49 ( V_45 , V_42 , V_46 , V_51 ) ;
if ( V_14 < 0 )
V_47 = F_14 ( V_14 ) ;
else if ( V_14 == 0 )
V_47 = NULL ;
else
V_47 = F_16 ( V_46 , V_14 ) ;
F_17 ( V_46 ) ;
return V_47 ;
}
struct V_28 * F_18 ( struct V_11 * V_47 )
{
struct V_28 * V_29 ;
V_29 = F_19 ( V_54 , V_55 ) ;
if ( V_29 == NULL )
return NULL ;
V_29 -> V_37 = V_47 ;
V_29 -> V_31 = 0 ;
F_20 ( & V_29 -> V_56 ) ;
return V_29 ;
}
static struct V_20 * F_21 ( struct V_11 * V_57 ,
struct V_11 * V_58 , T_1 V_59 )
{
struct V_20 * V_21 ;
V_21 = F_15 ( sizeof( struct V_20 ) , V_59 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_22 = V_57 ;
V_21 -> V_60 = V_58 ;
F_22 ( & V_21 -> V_61 ) ;
F_20 ( & V_21 -> V_62 ) ;
return V_21 ;
}
static int F_23 ( struct V_63 * V_64 , struct V_63 * V_65 ,
T_1 V_59 )
{
struct V_66 * V_67 ;
struct V_66 * V_68 ;
int V_14 = 0 ;
F_22 ( V_64 ) ;
F_24 (orp, ohead, list) {
V_67 = F_15 ( sizeof( struct V_66 ) , V_59 ) ;
if ( V_67 == NULL ) {
V_14 = - V_53 ;
break;
}
* V_67 = * V_68 ;
F_25 ( & V_67 -> V_69 , V_64 ) ;
}
return V_14 ;
}
static inline unsigned int F_26 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_70 :
return V_4 ;
case V_71 :
return V_72 ;
}
return 0 ;
}
static int F_27 ( struct V_25 * V_73 ,
struct V_11 * V_74 ,
unsigned int V_1 , const char * V_75 )
{
int V_14 ;
struct V_76 V_77 , * V_78 = NULL ;
struct V_20 * V_21 ;
struct V_11 * V_79 ;
if ( ( V_1 & V_80 ) == 0 ) {
F_28 ( & V_77 , V_75 , V_81 ) ;
F_29 ( & V_77 , V_73 ) ;
V_78 = & V_77 ;
}
F_30 () ;
V_21 = F_31 ( V_73 ) -> V_40 ;
V_79 = F_32 ( V_21 ) ;
if ( ( V_1 & V_71 ) &&
( V_82 == V_83 ||
V_82 == V_84 ) ) {
if ( V_79 -> V_19 == V_74 -> V_19 )
V_14 = 0 ;
else if ( V_82 == V_84 )
V_14 = - V_85 ;
else if ( F_33 ( V_86 ) )
V_14 = 0 ;
else
V_14 = - V_85 ;
if ( V_78 )
F_34 ( V_79 -> V_19 ,
V_74 -> V_19 ,
0 , V_14 , V_78 ) ;
F_35 () ;
return V_14 ;
}
V_14 = F_36 ( V_21 , V_74 , F_26 ( V_1 ) , V_78 ) ;
F_35 () ;
return V_14 ;
}
static int F_37 ( struct V_25 * V_87 , unsigned int V_1 )
{
struct V_11 * V_47 ;
V_47 = F_7 ( V_87 ) ;
return F_27 ( V_23 , V_47 , V_1 , V_88 ) ;
}
static int F_38 ( struct V_25 * V_89 )
{
int V_14 ;
struct V_11 * V_47 ;
V_47 = F_32 ( F_5 () ) ;
V_14 = F_27 ( V_89 , V_47 , V_71 , V_88 ) ;
return V_14 ;
}
static int F_39 ( int V_90 )
{
int V_14 = 0 ;
struct V_11 * V_47 = F_40 () ;
if ( F_41 ( V_91 ) )
return 0 ;
if ( V_92 != NULL && V_92 != V_47 )
V_14 = - V_85 ;
return V_14 ;
}
static int F_42 ( struct V_93 * V_94 )
{
struct V_95 * V_96 ;
V_96 = F_15 ( sizeof( struct V_95 ) , V_52 ) ;
if ( V_96 == NULL )
return - V_53 ;
V_96 -> V_97 = & V_98 ;
V_96 -> V_99 = & V_98 ;
V_96 -> V_100 = & V_98 ;
V_96 -> V_101 = & V_102 ;
V_94 -> V_103 = V_96 ;
return 0 ;
}
static void F_43 ( struct V_93 * V_94 )
{
F_17 ( V_94 -> V_103 ) ;
V_94 -> V_103 = NULL ;
}
static int F_44 ( char * V_104 , char * V_105 )
{
char * V_106 , * V_107 , * V_108 , * V_45 ;
V_108 = ( char * ) F_45 ( V_52 ) ;
if ( V_108 == NULL )
return - V_53 ;
for ( V_106 = V_104 , V_107 = V_104 ; V_107 != NULL ; V_106 = V_107 + 1 ) {
if ( strstr ( V_106 , V_109 ) == V_106 )
V_45 = V_105 ;
else if ( strstr ( V_106 , V_110 ) == V_106 )
V_45 = V_105 ;
else if ( strstr ( V_106 , V_111 ) == V_106 )
V_45 = V_105 ;
else if ( strstr ( V_106 , V_112 ) == V_106 )
V_45 = V_105 ;
else if ( strstr ( V_106 , V_113 ) == V_106 )
V_45 = V_105 ;
else
V_45 = V_108 ;
V_107 = strchr ( V_106 , ',' ) ;
if ( V_107 != NULL )
* V_107 = '\0' ;
if ( * V_45 != '\0' )
strcat ( V_45 , L_7 ) ;
strcat ( V_45 , V_106 ) ;
}
strcpy ( V_104 , V_108 ) ;
F_46 ( ( unsigned long ) V_108 ) ;
return 0 ;
}
static int F_47 ( struct V_93 * V_94 , int V_114 , void * V_115 )
{
struct V_44 * V_116 = V_94 -> V_117 ;
struct V_27 * V_27 = F_48 ( V_116 ) ;
struct V_95 * V_118 = V_94 -> V_103 ;
struct V_28 * V_29 ;
struct V_11 * V_47 ;
char * V_119 ;
char * V_107 ;
int V_120 = 0 ;
int V_121 = 0 ;
if ( V_118 -> V_122 )
return 0 ;
V_118 -> V_122 = 1 ;
for ( V_119 = V_115 ; V_119 != NULL ; V_119 = V_107 ) {
V_107 = strchr ( V_119 , ',' ) ;
if ( V_107 != NULL )
* V_107 ++ = '\0' ;
if ( strncmp ( V_119 , V_111 , strlen ( V_111 ) ) == 0 ) {
V_119 += strlen ( V_111 ) ;
V_47 = F_16 ( V_119 , 0 ) ;
if ( F_49 ( V_47 ) )
return F_50 ( V_47 ) ;
V_118 -> V_101 = V_47 ;
V_121 = 1 ;
} else if ( strncmp ( V_119 , V_110 , strlen ( V_110 ) ) == 0 ) {
V_119 += strlen ( V_110 ) ;
V_47 = F_16 ( V_119 , 0 ) ;
if ( F_49 ( V_47 ) )
return F_50 ( V_47 ) ;
V_118 -> V_100 = V_47 ;
V_121 = 1 ;
} else if ( strncmp ( V_119 , V_109 ,
strlen ( V_109 ) ) == 0 ) {
V_119 += strlen ( V_109 ) ;
V_47 = F_16 ( V_119 , 0 ) ;
if ( F_49 ( V_47 ) )
return F_50 ( V_47 ) ;
V_118 -> V_99 = V_47 ;
V_121 = 1 ;
} else if ( strncmp ( V_119 , V_112 , strlen ( V_112 ) ) == 0 ) {
V_119 += strlen ( V_112 ) ;
V_47 = F_16 ( V_119 , 0 ) ;
if ( F_49 ( V_47 ) )
return F_50 ( V_47 ) ;
V_118 -> V_97 = V_47 ;
V_121 = 1 ;
} else if ( strncmp ( V_119 , V_113 , strlen ( V_113 ) ) == 0 ) {
V_119 += strlen ( V_113 ) ;
V_47 = F_16 ( V_119 , 0 ) ;
if ( F_49 ( V_47 ) )
return F_50 ( V_47 ) ;
V_118 -> V_97 = V_47 ;
V_120 = 1 ;
V_121 = 1 ;
}
}
if ( ! F_41 ( V_123 ) ) {
if ( V_121 )
return - V_124 ;
V_47 = F_40 () ;
V_118 -> V_97 = V_47 ;
V_118 -> V_99 = V_47 ;
}
V_29 = V_27 -> V_30 ;
if ( V_29 == NULL ) {
V_29 = F_18 ( V_118 -> V_97 ) ;
if ( V_29 == NULL )
return - V_53 ;
V_27 -> V_30 = V_29 ;
} else
V_29 -> V_37 = V_118 -> V_97 ;
if ( V_120 )
V_29 -> V_31 |= V_125 ;
return 0 ;
}
static int F_51 ( struct V_44 * V_44 )
{
struct V_95 * V_126 = V_44 -> V_127 -> V_103 ;
int V_14 ;
struct V_76 V_77 ;
F_28 ( & V_77 , V_88 , V_128 ) ;
F_52 ( & V_77 , V_44 ) ;
V_14 = F_53 ( V_126 -> V_100 , V_4 , & V_77 ) ;
V_14 = F_4 ( L_8 , V_126 -> V_100 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_54 ( struct V_129 * V_130 )
{
struct V_27 * V_27 = F_10 ( V_130 -> V_38 ) ;
struct V_20 * V_131 = V_130 -> V_39 -> V_40 ;
struct V_28 * V_29 ;
int V_14 ;
if ( V_130 -> V_132 )
return 0 ;
V_29 = V_27 -> V_30 ;
if ( V_29 -> V_22 == NULL || V_29 -> V_22 == V_131 -> V_22 )
return 0 ;
if ( V_130 -> V_133 & ( V_134 | V_135 ) ) {
struct V_25 * V_73 ;
V_14 = 0 ;
F_30 () ;
V_73 = F_55 ( V_23 ) ;
if ( F_56 ( V_73 != NULL ) )
V_14 = F_27 ( V_73 ,
V_29 -> V_22 ,
V_71 ,
V_88 ) ;
F_35 () ;
if ( V_14 != 0 )
return V_14 ;
} else if ( V_130 -> V_133 )
return - V_124 ;
V_131 -> V_22 = V_29 -> V_22 ;
V_130 -> V_136 |= V_137 ;
return 0 ;
}
static void F_57 ( struct V_129 * V_130 )
{
struct V_20 * V_131 = V_130 -> V_39 -> V_40 ;
if ( V_131 -> V_22 != V_131 -> V_60 )
V_23 -> V_138 = 0 ;
}
static int F_58 ( struct V_129 * V_130 )
{
struct V_20 * V_21 = F_5 () ;
if ( V_21 -> V_22 != V_21 -> V_60 )
return 1 ;
return 0 ;
}
static int F_59 ( struct V_27 * V_27 )
{
struct V_11 * V_47 = F_40 () ;
V_27 -> V_30 = F_18 ( V_47 ) ;
if ( V_27 -> V_30 == NULL )
return - V_53 ;
return 0 ;
}
static void F_60 ( struct V_27 * V_27 )
{
F_61 ( V_54 , V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
static int F_62 ( struct V_27 * V_27 , struct V_27 * V_139 ,
const struct V_140 * V_140 , const char * * V_42 ,
void * * V_141 , T_2 * V_142 )
{
struct V_28 * V_143 = V_27 -> V_30 ;
struct V_11 * V_47 = F_40 () ;
struct V_11 * V_29 = F_11 ( V_27 ) ;
struct V_11 * V_144 = F_11 ( V_139 ) ;
int V_145 ;
if ( V_42 )
* V_42 = V_146 ;
if ( V_141 && V_142 ) {
F_30 () ;
V_145 = F_63 ( V_47 -> V_19 , V_144 -> V_19 ,
& V_47 -> V_61 ) ;
F_35 () ;
if ( V_145 > 0 && ( ( V_145 & V_8 ) != 0 ) &&
F_64 ( V_139 ) ) {
V_29 = V_144 ;
V_143 -> V_31 |= V_147 ;
}
* V_141 = F_65 ( V_29 -> V_19 , V_55 ) ;
if ( * V_141 == NULL )
return - V_53 ;
* V_142 = strlen ( V_29 -> V_19 ) ;
}
return 0 ;
}
static int F_66 ( struct V_44 * V_148 , struct V_27 * V_139 ,
struct V_44 * V_149 )
{
struct V_11 * V_29 ;
struct V_76 V_77 ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_128 ) ;
F_52 ( & V_77 , V_148 ) ;
V_29 = F_11 ( F_48 ( V_148 ) ) ;
V_14 = F_53 ( V_29 , V_5 , & V_77 ) ;
V_14 = F_8 ( F_48 ( V_148 ) , V_5 , V_14 ) ;
if ( V_14 == 0 && F_67 ( V_149 ) ) {
V_29 = F_11 ( F_48 ( V_149 ) ) ;
F_52 ( & V_77 , V_149 ) ;
V_14 = F_53 ( V_29 , V_5 , & V_77 ) ;
V_14 = F_8 ( F_48 ( V_149 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_68 ( struct V_27 * V_139 , struct V_44 * V_44 )
{
struct V_27 * V_43 = F_48 ( V_44 ) ;
struct V_76 V_77 ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_128 ) ;
F_52 ( & V_77 , V_44 ) ;
V_14 = F_53 ( F_11 ( V_43 ) , V_5 , & V_77 ) ;
V_14 = F_8 ( V_43 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_28 ( & V_77 , V_88 , V_150 ) ;
F_69 ( & V_77 , V_139 ) ;
V_14 = F_53 ( F_11 ( V_139 ) , V_5 , & V_77 ) ;
V_14 = F_8 ( V_139 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_70 ( struct V_27 * V_139 , struct V_44 * V_44 )
{
struct V_76 V_77 ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_128 ) ;
F_52 ( & V_77 , V_44 ) ;
V_14 = F_53 ( F_11 ( F_48 ( V_44 ) ) , V_5 , & V_77 ) ;
V_14 = F_8 ( F_48 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_28 ( & V_77 , V_88 , V_150 ) ;
F_69 ( & V_77 , V_139 ) ;
V_14 = F_53 ( F_11 ( V_139 ) , V_5 , & V_77 ) ;
V_14 = F_8 ( V_139 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_71 ( struct V_27 * V_151 ,
struct V_44 * V_148 ,
struct V_27 * V_152 ,
struct V_44 * V_149 )
{
int V_14 ;
struct V_11 * V_29 ;
struct V_76 V_77 ;
F_28 ( & V_77 , V_88 , V_128 ) ;
F_52 ( & V_77 , V_148 ) ;
V_29 = F_11 ( F_48 ( V_148 ) ) ;
V_14 = F_53 ( V_29 , V_72 , & V_77 ) ;
V_14 = F_8 ( F_48 ( V_148 ) , V_72 , V_14 ) ;
if ( V_14 == 0 && F_67 ( V_149 ) ) {
V_29 = F_11 ( F_48 ( V_149 ) ) ;
F_52 ( & V_77 , V_149 ) ;
V_14 = F_53 ( V_29 , V_72 , & V_77 ) ;
V_14 = F_8 ( F_48 ( V_149 ) , V_72 , V_14 ) ;
}
return V_14 ;
}
static int F_72 ( struct V_27 * V_27 , int V_153 )
{
struct V_76 V_77 ;
int V_154 = V_153 & V_155 ;
int V_14 ;
V_153 &= ( V_4 | V_5 | V_6 | V_7 ) ;
if ( V_153 == 0 )
return 0 ;
if ( V_154 )
return - V_156 ;
F_28 ( & V_77 , V_88 , V_150 ) ;
F_69 ( & V_77 , V_27 ) ;
V_14 = F_53 ( F_11 ( V_27 ) , V_153 , & V_77 ) ;
V_14 = F_8 ( V_27 , V_153 , V_14 ) ;
return V_14 ;
}
static int F_73 ( struct V_44 * V_44 , struct V_157 * V_157 )
{
struct V_76 V_77 ;
int V_14 ;
if ( V_157 -> V_158 & V_159 )
return 0 ;
F_28 ( & V_77 , V_88 , V_128 ) ;
F_52 ( & V_77 , V_44 ) ;
V_14 = F_53 ( F_11 ( F_48 ( V_44 ) ) , V_5 , & V_77 ) ;
V_14 = F_8 ( F_48 ( V_44 ) , V_5 , V_14 ) ;
return V_14 ;
}
static int F_74 ( const struct V_160 * V_160 )
{
struct V_76 V_77 ;
struct V_27 * V_27 = F_48 ( V_160 -> V_44 ) ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_161 ) ;
F_75 ( & V_77 , * V_160 ) ;
V_14 = F_53 ( F_11 ( V_27 ) , V_4 , & V_77 ) ;
V_14 = F_8 ( V_27 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_76 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_141 , T_2 V_162 , int V_114 )
{
struct V_76 V_77 ;
struct V_11 * V_47 ;
int V_163 = 0 ;
int V_164 = 0 ;
int V_165 = 0 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_166 ) == 0 ||
strcmp ( V_42 , V_167 ) == 0 ||
strcmp ( V_42 , V_168 ) == 0 ) {
V_163 = 1 ;
V_164 = 1 ;
} else if ( strcmp ( V_42 , V_169 ) == 0 ||
strcmp ( V_42 , V_170 ) == 0 ) {
V_163 = 1 ;
V_164 = 1 ;
V_165 = 1 ;
} else if ( strcmp ( V_42 , V_171 ) == 0 ) {
V_163 = 1 ;
if ( V_162 != V_172 ||
strncmp ( V_141 , V_173 , V_172 ) != 0 )
V_14 = - V_174 ;
} else
V_14 = F_77 ( V_44 , V_42 , V_141 , V_162 , V_114 ) ;
if ( V_163 && ! F_41 ( V_123 ) )
V_14 = - V_124 ;
if ( V_14 == 0 && V_164 ) {
V_47 = V_162 ? F_16 ( V_141 , V_162 ) : NULL ;
if ( F_49 ( V_47 ) )
V_14 = F_50 ( V_47 ) ;
else if ( V_47 == NULL || ( V_165 &&
( V_47 == & V_175 || V_47 == & V_176 ) ) )
V_14 = - V_174 ;
}
F_28 ( & V_77 , V_88 , V_128 ) ;
F_52 ( & V_77 , V_44 ) ;
if ( V_14 == 0 ) {
V_14 = F_53 ( F_11 ( F_48 ( V_44 ) ) , V_5 , & V_77 ) ;
V_14 = F_8 ( F_48 ( V_44 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static void F_78 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_141 , T_2 V_162 , int V_114 )
{
struct V_11 * V_47 ;
struct V_28 * V_29 = F_48 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_171 ) == 0 ) {
V_29 -> V_31 |= V_125 ;
return;
}
if ( strcmp ( V_42 , V_166 ) == 0 ) {
V_47 = F_16 ( V_141 , V_162 ) ;
if ( ! F_49 ( V_47 ) )
V_29 -> V_37 = V_47 ;
else
V_29 -> V_37 = & V_177 ;
} else if ( strcmp ( V_42 , V_169 ) == 0 ) {
V_47 = F_16 ( V_141 , V_162 ) ;
if ( ! F_49 ( V_47 ) )
V_29 -> V_22 = V_47 ;
else
V_29 -> V_22 = & V_177 ;
} else if ( strcmp ( V_42 , V_170 ) == 0 ) {
V_47 = F_16 ( V_141 , V_162 ) ;
if ( ! F_49 ( V_47 ) )
V_29 -> V_178 = V_47 ;
else
V_29 -> V_178 = & V_177 ;
}
return;
}
static int F_79 ( struct V_44 * V_44 , const char * V_42 )
{
struct V_76 V_77 ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_128 ) ;
F_52 ( & V_77 , V_44 ) ;
V_14 = F_53 ( F_11 ( F_48 ( V_44 ) ) , V_4 , & V_77 ) ;
V_14 = F_8 ( F_48 ( V_44 ) , V_4 , V_14 ) ;
return V_14 ;
}
static int F_80 ( struct V_44 * V_44 , const char * V_42 )
{
struct V_28 * V_29 ;
struct V_76 V_77 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_166 ) == 0 ||
strcmp ( V_42 , V_167 ) == 0 ||
strcmp ( V_42 , V_168 ) == 0 ||
strcmp ( V_42 , V_169 ) == 0 ||
strcmp ( V_42 , V_171 ) == 0 ||
strcmp ( V_42 , V_170 ) == 0 ) {
if ( ! F_41 ( V_123 ) )
V_14 = - V_124 ;
} else
V_14 = F_81 ( V_44 , V_42 ) ;
if ( V_14 != 0 )
return V_14 ;
F_28 ( & V_77 , V_88 , V_128 ) ;
F_52 ( & V_77 , V_44 ) ;
V_14 = F_53 ( F_11 ( F_48 ( V_44 ) ) , V_5 , & V_77 ) ;
V_14 = F_8 ( F_48 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_29 = F_48 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_166 ) == 0 )
V_29 -> V_22 = NULL ;
else if ( strcmp ( V_42 , V_170 ) == 0 )
V_29 -> V_178 = NULL ;
else if ( strcmp ( V_42 , V_171 ) == 0 )
V_29 -> V_31 &= ~ V_125 ;
return 0 ;
}
static int F_82 ( const struct V_27 * V_27 ,
const char * V_42 , void * * V_46 ,
bool V_179 )
{
struct V_180 * V_181 ;
struct V_182 * V_183 ;
struct V_93 * V_126 ;
struct V_27 * V_43 = (struct V_27 * ) V_27 ;
struct V_11 * V_29 ;
int V_184 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_146 ) == 0 ) {
V_29 = F_11 ( V_27 ) ;
V_184 = strlen ( V_29 -> V_19 ) ;
* V_46 = V_29 -> V_19 ;
return V_184 ;
}
V_126 = V_43 -> V_33 ;
if ( V_126 -> V_185 != V_186 )
return - V_50 ;
V_183 = F_83 ( V_43 ) ;
if ( V_183 == NULL || V_183 -> V_187 == NULL )
return - V_50 ;
V_181 = V_183 -> V_187 -> V_188 ;
if ( strcmp ( V_42 , V_189 ) == 0 )
V_29 = V_181 -> V_190 ;
else if ( strcmp ( V_42 , V_191 ) == 0 )
V_29 = V_181 -> V_192 ;
else
return - V_50 ;
V_184 = strlen ( V_29 -> V_19 ) ;
if ( V_14 == 0 ) {
* V_46 = V_29 -> V_19 ;
V_14 = V_184 ;
}
return V_14 ;
}
static int F_84 ( struct V_27 * V_27 , char * V_46 ,
T_2 V_193 )
{
int V_142 = sizeof( V_166 ) ;
if ( V_46 != NULL && V_142 <= V_193 )
memcpy ( V_46 , V_166 , V_142 ) ;
return V_142 ;
}
static void F_85 ( const struct V_27 * V_27 , T_3 * V_194 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
* V_194 = V_29 -> V_37 -> V_195 ;
}
static int F_86 ( struct V_38 * V_38 , int V_153 )
{
return 0 ;
}
static int F_87 ( struct V_38 * V_38 )
{
struct V_11 * V_47 = F_40 () ;
V_38 -> V_196 = V_47 ;
return 0 ;
}
static void F_88 ( struct V_38 * V_38 )
{
V_38 -> V_196 = NULL ;
}
static int F_89 ( struct V_38 * V_38 , unsigned int V_197 ,
unsigned long V_198 )
{
int V_14 = 0 ;
struct V_76 V_77 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_28 ( & V_77 , V_88 , V_161 ) ;
F_75 ( & V_77 , V_38 -> V_199 ) ;
if ( F_90 ( V_197 ) & V_200 ) {
V_14 = F_53 ( F_11 ( V_27 ) , V_5 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_90 ( V_197 ) & V_201 ) ) {
V_14 = F_53 ( F_11 ( V_27 ) , V_4 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_91 ( struct V_38 * V_38 , unsigned int V_197 )
{
struct V_76 V_77 ;
int V_14 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_28 ( & V_77 , V_88 , V_161 ) ;
F_75 ( & V_77 , V_38 -> V_199 ) ;
V_14 = F_53 ( F_11 ( V_27 ) , V_9 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_92 ( struct V_38 * V_38 , unsigned int V_197 ,
unsigned long V_198 )
{
struct V_76 V_77 ;
int V_14 = 0 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
switch ( V_197 ) {
case V_202 :
break;
case V_203 :
case V_204 :
F_28 ( & V_77 , V_88 , V_161 ) ;
F_75 ( & V_77 , V_38 -> V_199 ) ;
V_14 = F_53 ( F_11 ( V_27 ) , V_9 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
break;
case V_205 :
case V_206 :
F_28 ( & V_77 , V_88 , V_161 ) ;
F_75 ( & V_77 , V_38 -> V_199 ) ;
V_14 = F_53 ( F_11 ( V_27 ) , V_5 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_93 ( struct V_38 * V_38 ,
unsigned long V_207 , unsigned long V_208 ,
unsigned long V_114 )
{
struct V_11 * V_47 ;
struct V_11 * V_209 ;
struct V_66 * V_210 ;
struct V_20 * V_21 ;
struct V_11 * V_211 ;
struct V_28 * V_29 ;
int V_145 ;
int V_212 ;
int V_213 ;
int V_14 ;
if ( V_38 == NULL )
return 0 ;
V_29 = F_10 ( V_38 ) -> V_30 ;
if ( V_29 -> V_178 == NULL )
return 0 ;
V_209 = V_29 -> V_178 ;
V_21 = F_5 () ;
V_47 = F_40 () ;
V_14 = 0 ;
F_30 () ;
F_24 (srp, &skp->smk_rules, list) {
V_211 = V_210 -> V_214 ;
if ( V_209 -> V_19 == V_211 -> V_19 )
continue;
V_145 = F_63 ( V_210 -> V_215 -> V_19 ,
V_211 -> V_19 ,
& V_21 -> V_61 ) ;
if ( V_145 == - V_216 )
V_145 = V_210 -> V_217 ;
else
V_145 &= V_210 -> V_217 ;
if ( V_145 == 0 )
continue;
V_212 = F_63 ( V_209 -> V_19 , V_211 -> V_19 ,
& V_209 -> V_61 ) ;
if ( V_212 == - V_216 ) {
V_14 = - V_85 ;
break;
}
V_213 = F_63 ( V_209 -> V_19 , V_211 -> V_19 ,
& V_21 -> V_61 ) ;
if ( V_213 != - V_216 )
V_212 &= V_213 ;
if ( ( V_145 | V_212 ) != V_212 ) {
V_14 = - V_85 ;
break;
}
}
F_35 () ;
return V_14 ;
}
static void F_94 ( struct V_38 * V_38 )
{
V_38 -> V_196 = F_40 () ;
}
static int F_95 ( struct V_25 * V_218 ,
struct V_219 * V_220 , int V_221 )
{
struct V_11 * V_47 ;
struct V_11 * V_222 = F_32 ( V_218 -> V_39 -> V_40 ) ;
struct V_38 * V_38 ;
int V_14 ;
struct V_76 V_77 ;
V_38 = F_96 ( V_220 , struct V_38 , V_223 ) ;
V_47 = V_38 -> V_196 ;
V_14 = V_217 ( V_47 , V_222 , V_5 , NULL ) ;
V_14 = F_2 ( L_9 , V_47 , V_222 , V_5 , V_14 ) ;
if ( V_14 != 0 && F_97 ( V_218 , V_91 ) )
V_14 = 0 ;
F_28 ( & V_77 , V_88 , V_81 ) ;
F_29 ( & V_77 , V_218 ) ;
F_34 ( V_47 -> V_19 , V_222 -> V_19 , V_5 , V_14 , & V_77 ) ;
return V_14 ;
}
static int F_98 ( struct V_38 * V_38 )
{
int V_14 ;
int V_145 = 0 ;
struct V_76 V_77 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
if ( F_99 ( F_100 ( V_27 ) ) )
return 0 ;
F_28 ( & V_77 , V_88 , V_161 ) ;
F_75 ( & V_77 , V_38 -> V_199 ) ;
if ( V_38 -> V_224 & V_225 )
V_145 = V_4 ;
if ( V_38 -> V_224 & V_226 )
V_145 |= V_5 ;
V_14 = F_53 ( F_11 ( V_27 ) , V_145 , & V_77 ) ;
V_14 = F_9 ( V_38 , V_145 , V_14 ) ;
return V_14 ;
}
static int F_101 ( struct V_38 * V_38 , const struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_76 V_77 ;
int V_14 ;
if ( F_41 ( V_91 ) )
return 0 ;
F_28 ( & V_77 , V_88 , V_161 ) ;
F_75 ( & V_77 , V_38 -> V_199 ) ;
V_14 = V_217 ( V_21 -> V_22 , F_11 ( V_27 ) , V_4 , & V_77 ) ;
V_14 = F_12 ( V_39 , V_38 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_102 ( struct V_39 * V_39 , T_1 V_59 )
{
struct V_20 * V_21 ;
V_21 = F_21 ( NULL , NULL , V_59 ) ;
if ( V_21 == NULL )
return - V_53 ;
V_39 -> V_40 = V_21 ;
return 0 ;
}
static void F_103 ( struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_66 * V_227 ;
struct V_63 * V_228 ;
struct V_63 * V_229 ;
if ( V_21 == NULL )
return;
V_39 -> V_40 = NULL ;
F_104 (l, n, &tsp->smk_rules) {
V_227 = F_105 ( V_228 , struct V_66 , V_69 ) ;
F_106 ( & V_227 -> V_69 ) ;
F_17 ( V_227 ) ;
}
F_17 ( V_21 ) ;
}
static int F_107 ( struct V_39 * V_230 , const struct V_39 * V_231 ,
T_1 V_59 )
{
struct V_20 * V_232 = V_231 -> V_40 ;
struct V_20 * V_233 ;
int V_14 ;
V_233 = F_21 ( V_232 -> V_22 , V_232 -> V_22 , V_59 ) ;
if ( V_233 == NULL )
return - V_53 ;
V_14 = F_23 ( & V_233 -> V_61 , & V_232 -> V_61 , V_59 ) ;
if ( V_14 != 0 )
return V_14 ;
V_230 -> V_40 = V_233 ;
return 0 ;
}
static void F_108 ( struct V_39 * V_230 , const struct V_39 * V_231 )
{
struct V_20 * V_232 = V_231 -> V_40 ;
struct V_20 * V_233 = V_230 -> V_40 ;
V_233 -> V_22 = V_232 -> V_22 ;
V_233 -> V_60 = V_232 -> V_22 ;
F_20 ( & V_233 -> V_62 ) ;
F_22 ( & V_233 -> V_61 ) ;
}
static int F_109 ( struct V_39 * V_230 , T_3 V_194 )
{
struct V_20 * V_233 = V_230 -> V_40 ;
struct V_11 * V_47 = F_110 ( V_194 ) ;
if ( V_47 == NULL )
return - V_174 ;
V_233 -> V_22 = V_47 ;
return 0 ;
}
static int F_111 ( struct V_39 * V_230 ,
struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_20 * V_21 = V_230 -> V_40 ;
V_21 -> V_60 = V_29 -> V_37 ;
V_21 -> V_22 = V_21 -> V_60 ;
return 0 ;
}
static int F_112 ( struct V_25 * V_234 , int V_235 ,
const char * V_236 )
{
struct V_76 V_77 ;
struct V_11 * V_47 = F_7 ( V_234 ) ;
int V_14 ;
F_28 ( & V_77 , V_236 , V_81 ) ;
F_29 ( & V_77 , V_234 ) ;
V_14 = F_53 ( V_47 , V_235 , & V_77 ) ;
V_14 = F_6 ( V_234 , V_235 , V_14 ) ;
return V_14 ;
}
static int F_113 ( struct V_25 * V_234 , T_4 V_237 )
{
return F_112 ( V_234 , V_5 , V_88 ) ;
}
static int F_114 ( struct V_25 * V_234 )
{
return F_112 ( V_234 , V_4 , V_88 ) ;
}
static int F_115 ( struct V_25 * V_234 )
{
return F_112 ( V_234 , V_4 , V_88 ) ;
}
static void F_116 ( struct V_25 * V_234 , T_3 * V_194 )
{
struct V_11 * V_47 = F_7 ( V_234 ) ;
* V_194 = V_47 -> V_195 ;
}
static int F_117 ( struct V_25 * V_234 , int V_238 )
{
return F_112 ( V_234 , V_5 , V_88 ) ;
}
static int F_118 ( struct V_25 * V_234 , int V_239 )
{
return F_112 ( V_234 , V_5 , V_88 ) ;
}
static int F_119 ( struct V_25 * V_234 )
{
return F_112 ( V_234 , V_4 , V_88 ) ;
}
static int F_120 ( struct V_25 * V_234 )
{
return F_112 ( V_234 , V_5 , V_88 ) ;
}
static int F_121 ( struct V_25 * V_234 )
{
return F_112 ( V_234 , V_4 , V_88 ) ;
}
static int F_122 ( struct V_25 * V_234 )
{
return F_112 ( V_234 , V_5 , V_88 ) ;
}
static int F_123 ( struct V_25 * V_234 , struct V_240 * V_241 ,
int V_242 , T_3 V_194 )
{
struct V_76 V_77 ;
struct V_11 * V_47 ;
struct V_11 * V_222 = F_7 ( V_234 ) ;
int V_14 ;
F_28 ( & V_77 , V_88 , V_81 ) ;
F_29 ( & V_77 , V_234 ) ;
if ( V_194 == 0 ) {
V_14 = F_53 ( V_222 , V_5 , & V_77 ) ;
V_14 = F_6 ( V_234 , V_5 , V_14 ) ;
return V_14 ;
}
V_47 = F_110 ( V_194 ) ;
V_14 = V_217 ( V_47 , V_222 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_10 , V_47 , V_222 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_124 ( struct V_25 * V_234 )
{
return 0 ;
}
static void F_125 ( struct V_25 * V_234 , struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_11 * V_47 = F_7 ( V_234 ) ;
V_29 -> V_37 = V_47 ;
}
static int F_126 ( struct V_183 * V_187 , int V_243 , T_1 V_244 )
{
struct V_11 * V_47 = F_40 () ;
struct V_180 * V_181 ;
V_181 = F_15 ( sizeof( struct V_180 ) , V_244 ) ;
if ( V_181 == NULL )
return - V_53 ;
V_181 -> V_190 = V_47 ;
V_181 -> V_192 = V_47 ;
V_181 -> V_245 = NULL ;
V_187 -> V_188 = V_181 ;
return 0 ;
}
static void F_127 ( struct V_183 * V_187 )
{
F_17 ( V_187 -> V_188 ) ;
}
static struct V_11 * F_128 ( struct V_246 * V_247 )
{
struct V_248 * V_249 ;
struct V_250 * V_251 = & V_247 -> V_252 ;
if ( V_251 -> V_253 == 0 )
return NULL ;
F_24 (snp, &smk_netlbladdr_list, list)
if ( ( & V_249 -> V_254 . V_252 ) -> V_253 ==
( V_251 -> V_253 & ( & V_249 -> V_255 ) -> V_253 ) ) {
if ( V_249 -> V_256 == & V_257 )
return NULL ;
return V_249 -> V_256 ;
}
return NULL ;
}
static int F_129 ( struct V_183 * V_187 , int V_258 )
{
struct V_11 * V_47 ;
struct V_180 * V_181 = V_187 -> V_188 ;
int V_14 = 0 ;
F_130 () ;
F_131 ( V_187 ) ;
if ( V_181 -> V_192 == V_259 ||
V_258 == V_260 )
F_132 ( V_187 ) ;
else {
V_47 = V_181 -> V_192 ;
V_14 = F_133 ( V_187 , V_187 -> V_261 , & V_47 -> V_262 ) ;
}
F_134 ( V_187 ) ;
F_135 () ;
return V_14 ;
}
static int F_136 ( struct V_183 * V_187 , struct V_246 * V_263 )
{
struct V_11 * V_47 ;
int V_14 ;
int V_264 ;
struct V_11 * V_265 ;
struct V_180 * V_181 = V_187 -> V_188 ;
struct V_76 V_77 ;
F_30 () ;
V_265 = F_128 ( V_263 ) ;
if ( V_265 != NULL ) {
#ifdef F_137
struct V_266 V_267 ;
F_138 ( & V_77 , V_88 , V_268 , & V_267 ) ;
V_77 . V_269 . V_270 . V_267 -> V_243 = V_263 -> V_271 ;
V_77 . V_269 . V_270 . V_267 -> V_272 = V_263 -> V_273 ;
V_77 . V_269 . V_270 . V_267 -> V_274 . V_275 = V_263 -> V_252 . V_253 ;
#endif
V_264 = V_260 ;
V_47 = V_181 -> V_192 ;
V_14 = V_217 ( V_47 , V_265 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_11 , V_47 , V_265 , V_5 , V_14 ) ;
} else {
V_264 = V_276 ;
V_14 = 0 ;
}
F_35 () ;
if ( V_14 != 0 )
return V_14 ;
return F_129 ( V_187 , V_264 ) ;
}
static void F_139 ( struct V_182 * V_183 , struct V_277 * V_278 )
{
struct V_183 * V_187 = V_183 -> V_187 ;
struct V_279 * V_280 ;
struct V_180 * V_181 = V_183 -> V_187 -> V_188 ;
struct V_281 * V_282 ;
unsigned short V_283 = 0 ;
if ( V_278 == NULL ) {
F_140 (spp, &smk_ipv6_port_list, list) {
if ( V_187 != V_282 -> V_284 )
continue;
V_282 -> V_190 = V_181 -> V_190 ;
V_282 -> V_192 = V_181 -> V_192 ;
return;
}
return;
}
V_280 = (struct V_279 * ) V_278 ;
V_283 = F_141 ( V_280 -> V_285 ) ;
if ( V_283 == 0 )
return;
F_140 (spp, &smk_ipv6_port_list, list) {
if ( V_282 -> V_286 != V_283 )
continue;
V_282 -> V_286 = V_283 ;
V_282 -> V_284 = V_187 ;
V_282 -> V_190 = V_181 -> V_190 ;
V_282 -> V_192 = V_181 -> V_192 ;
return;
}
V_282 = F_15 ( sizeof( * V_282 ) , V_52 ) ;
if ( V_282 == NULL )
return;
V_282 -> V_286 = V_283 ;
V_282 -> V_284 = V_187 ;
V_282 -> V_190 = V_181 -> V_190 ;
V_282 -> V_192 = V_181 -> V_192 ;
F_142 ( & V_282 -> V_69 , & V_287 ) ;
return;
}
static int F_143 ( struct V_183 * V_187 , struct V_279 * V_278 ,
int V_288 )
{
T_5 * V_289 ;
T_6 * V_290 ;
struct V_281 * V_282 ;
struct V_180 * V_181 = V_187 -> V_188 ;
struct V_11 * V_47 ;
unsigned short V_283 = 0 ;
struct V_11 * V_291 ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_137
struct V_266 V_267 ;
#endif
if ( V_288 == V_292 ) {
V_47 = V_259 ;
V_291 = V_181 -> V_190 ;
} else {
V_47 = V_181 -> V_192 ;
V_291 = V_259 ;
}
V_283 = F_141 ( V_278 -> V_285 ) ;
V_289 = ( T_5 * ) ( & V_278 -> V_293 ) ;
V_290 = ( T_6 * ) ( & V_278 -> V_293 ) ;
if ( V_290 [ 0 ] || V_290 [ 1 ] || V_290 [ 2 ] || V_289 [ 6 ] || F_141 ( V_289 [ 7 ] ) != 1 )
goto V_294;
if ( V_288 == V_292 ) {
V_47 = & V_176 ;
goto V_294;
}
F_140 (spp, &smk_ipv6_port_list, list) {
if ( V_282 -> V_286 != V_283 )
continue;
V_291 = V_282 -> V_190 ;
if ( V_288 == V_295 )
V_181 -> V_245 = V_282 -> V_192 ;
break;
}
V_294:
#ifdef F_137
F_138 ( & V_77 , V_88 , V_268 , & V_267 ) ;
V_77 . V_269 . V_270 . V_267 -> V_243 = V_187 -> V_261 ;
V_77 . V_269 . V_270 . V_267 -> V_272 = V_283 ;
if ( V_288 == V_292 )
V_77 . V_269 . V_270 . V_267 -> V_296 . V_297 = V_278 -> V_293 ;
else
V_77 . V_269 . V_270 . V_267 -> V_296 . V_275 = V_278 -> V_293 ;
#endif
V_14 = V_217 ( V_47 , V_291 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_12 , V_47 , V_291 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_144 ( struct V_27 * V_27 , const char * V_42 ,
const void * V_141 , T_2 V_162 , int V_114 )
{
struct V_11 * V_47 ;
struct V_28 * V_298 = V_27 -> V_30 ;
struct V_180 * V_181 ;
struct V_182 * V_183 ;
int V_14 = 0 ;
if ( V_141 == NULL || V_162 > V_51 || V_162 == 0 )
return - V_174 ;
V_47 = F_16 ( V_141 , V_162 ) ;
if ( F_49 ( V_47 ) )
return F_50 ( V_47 ) ;
if ( strcmp ( V_42 , V_146 ) == 0 ) {
V_298 -> V_37 = V_47 ;
V_298 -> V_31 |= V_299 ;
return 0 ;
}
if ( V_27 -> V_33 -> V_185 != V_186 )
return - V_50 ;
V_183 = F_83 ( V_27 ) ;
if ( V_183 == NULL || V_183 -> V_187 == NULL )
return - V_50 ;
V_181 = V_183 -> V_187 -> V_188 ;
if ( strcmp ( V_42 , V_189 ) == 0 )
V_181 -> V_190 = V_47 ;
else if ( strcmp ( V_42 , V_191 ) == 0 ) {
V_181 -> V_192 = V_47 ;
if ( V_183 -> V_187 -> V_261 == V_300 ) {
V_14 = F_129 ( V_183 -> V_187 , V_276 ) ;
if ( V_14 != 0 )
F_145 ( V_301
L_13 ,
V_88 , - V_14 ) ;
}
} else
return - V_50 ;
#if F_146 ( V_302 ) && ! F_147 ( V_303 )
if ( V_183 -> V_187 -> V_261 == V_304 )
F_139 ( V_183 , NULL ) ;
#endif
return 0 ;
}
static int F_148 ( struct V_182 * V_183 , int V_243 ,
int type , int V_305 , int V_306 )
{
struct V_180 * V_181 ;
if ( V_183 -> V_187 == NULL )
return 0 ;
if ( F_99 ( V_23 -> V_114 & V_307 ) ) {
V_181 = V_183 -> V_187 -> V_188 ;
V_181 -> V_190 = & V_176 ;
V_181 -> V_192 = & V_176 ;
}
if ( V_243 != V_300 )
return 0 ;
return F_129 ( V_183 -> V_187 , V_276 ) ;
}
static int F_149 ( struct V_182 * V_183 , struct V_277 * V_278 ,
int V_308 )
{
#if F_146 ( V_302 )
if ( V_183 -> V_187 != NULL && V_183 -> V_187 -> V_261 == V_304 )
F_139 ( V_183 , V_278 ) ;
#endif
return 0 ;
}
static int F_150 ( struct V_182 * V_183 , struct V_277 * V_263 ,
int V_308 )
{
int V_14 = 0 ;
if ( V_183 -> V_187 == NULL )
return 0 ;
switch ( V_183 -> V_187 -> V_261 ) {
case V_300 :
if ( V_308 < sizeof( struct V_246 ) )
return - V_174 ;
V_14 = F_136 ( V_183 -> V_187 , (struct V_246 * ) V_263 ) ;
break;
case V_304 :
if ( V_308 < sizeof( struct V_279 ) )
return - V_174 ;
#if F_146 ( V_302 ) && ! F_147 ( V_303 )
V_14 = F_143 ( V_183 -> V_187 , (struct V_279 * ) V_263 ,
V_295 ) ;
#endif
break;
}
return V_14 ;
}
static int F_151 ( int V_114 )
{
int V_145 = 0 ;
if ( V_114 & V_309 )
V_145 |= V_4 ;
if ( V_114 & V_310 )
V_145 |= V_5 ;
if ( V_114 & V_311 )
V_145 |= V_6 ;
return V_145 ;
}
static int F_152 ( struct V_312 * V_313 )
{
struct V_11 * V_47 = F_40 () ;
V_313 -> V_40 = V_47 ;
return 0 ;
}
static void F_153 ( struct V_312 * V_313 )
{
V_313 -> V_40 = NULL ;
}
static struct V_11 * F_154 ( struct V_314 * V_315 )
{
return (struct V_11 * ) V_315 -> V_316 . V_40 ;
}
static int F_155 ( struct V_314 * V_315 )
{
struct V_317 * V_29 = & V_315 -> V_316 ;
struct V_11 * V_47 = F_40 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_156 ( struct V_314 * V_315 )
{
struct V_317 * V_29 = & V_315 -> V_316 ;
V_29 -> V_40 = NULL ;
}
static int F_157 ( struct V_314 * V_315 , int V_235 )
{
struct V_11 * V_181 = F_154 ( V_315 ) ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_137
F_28 ( & V_77 , V_88 , V_318 ) ;
V_77 . V_269 . V_270 . V_319 = V_315 -> V_316 . V_320 ;
#endif
V_14 = F_53 ( V_181 , V_235 , & V_77 ) ;
V_14 = F_4 ( L_14 , V_181 , V_235 , V_14 ) ;
return V_14 ;
}
static int F_158 ( struct V_314 * V_315 , int V_321 )
{
int V_145 ;
V_145 = F_151 ( V_321 ) ;
return F_157 ( V_315 , V_145 ) ;
}
static int F_159 ( struct V_314 * V_315 , int V_197 )
{
int V_145 ;
switch ( V_197 ) {
case V_322 :
case V_323 :
V_145 = V_4 ;
break;
case V_324 :
case V_325 :
case V_326 :
case V_327 :
V_145 = V_72 ;
break;
case V_328 :
case V_329 :
return 0 ;
default:
return - V_174 ;
}
return F_157 ( V_315 , V_145 ) ;
}
static int F_160 ( struct V_314 * V_315 , char T_7 * V_330 ,
int V_321 )
{
int V_145 ;
V_145 = F_151 ( V_321 ) ;
return F_157 ( V_315 , V_145 ) ;
}
static struct V_11 * F_161 ( struct V_331 * V_332 )
{
return (struct V_11 * ) V_332 -> V_333 . V_40 ;
}
static int F_162 ( struct V_331 * V_332 )
{
struct V_317 * V_29 = & V_332 -> V_333 ;
struct V_11 * V_47 = F_40 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_163 ( struct V_331 * V_332 )
{
struct V_317 * V_29 = & V_332 -> V_333 ;
V_29 -> V_40 = NULL ;
}
static int F_164 ( struct V_331 * V_332 , int V_235 )
{
struct V_11 * V_181 = F_161 ( V_332 ) ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_137
F_28 ( & V_77 , V_88 , V_318 ) ;
V_77 . V_269 . V_270 . V_319 = V_332 -> V_333 . V_320 ;
#endif
V_14 = F_53 ( V_181 , V_235 , & V_77 ) ;
V_14 = F_4 ( L_15 , V_181 , V_235 , V_14 ) ;
return V_14 ;
}
static int F_165 ( struct V_331 * V_332 , int V_334 )
{
int V_145 ;
V_145 = F_151 ( V_334 ) ;
return F_164 ( V_332 , V_145 ) ;
}
static int F_166 ( struct V_331 * V_332 , int V_197 )
{
int V_145 ;
switch ( V_197 ) {
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_322 :
case V_340 :
V_145 = V_4 ;
break;
case V_341 :
case V_342 :
case V_327 :
case V_324 :
V_145 = V_72 ;
break;
case V_328 :
case V_343 :
return 0 ;
default:
return - V_174 ;
}
return F_164 ( V_332 , V_145 ) ;
}
static int F_167 ( struct V_331 * V_332 , struct V_344 * V_345 ,
unsigned V_346 , int V_347 )
{
return F_164 ( V_332 , V_72 ) ;
}
static int F_168 ( struct V_348 * V_349 )
{
struct V_317 * V_350 = & V_349 -> V_351 ;
struct V_11 * V_47 = F_40 () ;
V_350 -> V_40 = V_47 ;
return 0 ;
}
static void F_169 ( struct V_348 * V_349 )
{
struct V_317 * V_350 = & V_349 -> V_351 ;
V_350 -> V_40 = NULL ;
}
static struct V_11 * F_170 ( struct V_348 * V_349 )
{
return (struct V_11 * ) V_349 -> V_351 . V_40 ;
}
static int F_171 ( struct V_348 * V_349 , int V_235 )
{
struct V_11 * V_352 = F_170 ( V_349 ) ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_137
F_28 ( & V_77 , V_88 , V_318 ) ;
V_77 . V_269 . V_270 . V_319 = V_349 -> V_351 . V_320 ;
#endif
V_14 = F_53 ( V_352 , V_235 , & V_77 ) ;
V_14 = F_4 ( L_16 , V_352 , V_235 , V_14 ) ;
return V_14 ;
}
static int F_172 ( struct V_348 * V_349 , int V_353 )
{
int V_145 ;
V_145 = F_151 ( V_353 ) ;
return F_171 ( V_349 , V_145 ) ;
}
static int F_173 ( struct V_348 * V_349 , int V_197 )
{
int V_145 ;
switch ( V_197 ) {
case V_322 :
case V_354 :
V_145 = V_4 ;
break;
case V_324 :
case V_327 :
V_145 = V_72 ;
break;
case V_328 :
case V_355 :
return 0 ;
default:
return - V_174 ;
}
return F_171 ( V_349 , V_145 ) ;
}
static int F_174 ( struct V_348 * V_349 , struct V_312 * V_313 ,
int V_353 )
{
int V_145 ;
V_145 = F_151 ( V_353 ) ;
return F_171 ( V_349 , V_145 ) ;
}
static int F_175 ( struct V_348 * V_349 , struct V_312 * V_313 ,
struct V_25 * V_356 , long type , int V_1 )
{
return F_171 ( V_349 , V_72 ) ;
}
static int F_176 ( struct V_317 * V_357 , short V_358 )
{
struct V_11 * V_359 = V_357 -> V_40 ;
int V_145 = F_151 ( V_358 ) ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_137
F_28 ( & V_77 , V_88 , V_318 ) ;
V_77 . V_269 . V_270 . V_319 = V_357 -> V_320 ;
#endif
V_14 = F_53 ( V_359 , V_145 , & V_77 ) ;
V_14 = F_4 ( L_17 , V_359 , V_145 , V_14 ) ;
return V_14 ;
}
static void F_177 ( struct V_317 * V_357 , T_3 * V_194 )
{
struct V_11 * V_359 = V_357 -> V_40 ;
* V_194 = V_359 -> V_195 ;
}
static void F_178 ( struct V_44 * V_360 , struct V_27 * V_27 )
{
struct V_93 * V_126 ;
struct V_95 * V_96 ;
struct V_28 * V_29 ;
struct V_11 * V_47 ;
struct V_11 * V_361 = F_40 () ;
struct V_11 * V_362 ;
char V_363 [ V_172 ] ;
int V_364 = 0 ;
int V_14 ;
struct V_44 * V_45 ;
if ( V_27 == NULL )
return;
V_29 = V_27 -> V_30 ;
F_179 ( & V_29 -> V_56 ) ;
if ( V_29 -> V_31 & V_299 )
goto V_365;
V_126 = V_27 -> V_33 ;
V_96 = V_126 -> V_103 ;
V_362 = V_96 -> V_99 ;
if ( V_360 -> V_366 == V_360 ) {
switch ( V_126 -> V_185 ) {
case V_367 :
V_96 -> V_97 = & V_175 ;
V_96 -> V_99 = & V_175 ;
V_29 -> V_37 = V_96 -> V_97 ;
break;
case V_368 :
V_29 -> V_37 = F_40 () ;
break;
default:
V_29 -> V_37 = V_96 -> V_97 ;
break;
}
V_29 -> V_31 |= V_299 ;
goto V_365;
}
switch ( V_126 -> V_185 ) {
case V_369 :
case V_370 :
case V_186 :
case V_367 :
V_362 = & V_175 ;
break;
case V_371 :
V_362 = V_361 ;
break;
case V_372 :
break;
case V_368 :
V_362 = & V_175 ;
default:
if ( F_180 ( V_27 -> V_373 ) ) {
V_362 = & V_175 ;
break;
}
if ( V_27 -> V_48 -> V_49 == NULL )
break;
V_45 = F_181 ( V_360 ) ;
V_47 = F_13 ( V_166 , V_27 , V_45 ) ;
if ( ! F_182 ( V_47 ) )
V_362 = V_47 ;
if ( F_183 ( V_27 -> V_373 ) ) {
if ( V_29 -> V_31 & V_147 ) {
V_29 -> V_31 &= ~ V_147 ;
V_14 = V_27 -> V_48 -> V_374 ( V_45 ,
V_171 ,
V_173 , V_172 ,
0 ) ;
} else {
V_14 = V_27 -> V_48 -> V_49 ( V_45 ,
V_171 , V_363 ,
V_172 ) ;
if ( V_14 >= 0 && strncmp ( V_363 , V_173 ,
V_172 ) != 0 )
V_14 = - V_174 ;
}
if ( V_14 >= 0 )
V_364 = V_125 ;
}
V_47 = F_13 ( V_169 , V_27 , V_45 ) ;
if ( F_49 ( V_47 ) || V_47 == & V_175 ||
V_47 == & V_176 )
V_47 = NULL ;
V_29 -> V_22 = V_47 ;
V_47 = F_13 ( V_170 , V_27 , V_45 ) ;
if ( F_49 ( V_47 ) || V_47 == & V_175 ||
V_47 == & V_176 )
V_47 = NULL ;
V_29 -> V_178 = V_47 ;
F_184 ( V_45 ) ;
break;
}
if ( V_362 == NULL )
V_29 -> V_37 = V_361 ;
else
V_29 -> V_37 = V_362 ;
V_29 -> V_31 |= ( V_299 | V_364 ) ;
V_365:
F_185 ( & V_29 -> V_56 ) ;
return;
}
static int F_186 ( struct V_25 * V_234 , char * V_42 , char * * V_141 )
{
struct V_11 * V_47 = F_7 ( V_234 ) ;
char * V_106 ;
int V_375 ;
if ( strcmp ( V_42 , L_18 ) != 0 )
return - V_174 ;
V_106 = F_65 ( V_47 -> V_19 , V_52 ) ;
if ( V_106 == NULL )
return - V_53 ;
V_375 = strlen ( V_106 ) ;
* V_141 = V_106 ;
return V_375 ;
}
static int F_187 ( struct V_25 * V_234 , char * V_42 ,
void * V_141 , T_2 V_162 )
{
struct V_20 * V_21 ;
struct V_39 * V_230 ;
struct V_11 * V_47 ;
if ( V_234 != V_23 )
return - V_124 ;
if ( ! F_41 ( V_123 ) )
return - V_124 ;
if ( V_141 == NULL || V_162 == 0 || V_162 >= V_51 )
return - V_174 ;
if ( strcmp ( V_42 , L_18 ) != 0 )
return - V_174 ;
V_47 = F_16 ( V_141 , V_162 ) ;
if ( F_49 ( V_47 ) )
return F_50 ( V_47 ) ;
if ( V_47 == & V_176 )
return - V_124 ;
V_230 = F_188 () ;
if ( V_230 == NULL )
return - V_53 ;
V_21 = V_230 -> V_40 ;
V_21 -> V_22 = V_47 ;
F_189 ( V_230 ) ;
return V_162 ;
}
static int F_190 ( struct V_183 * V_183 ,
struct V_183 * V_376 , struct V_183 * V_377 )
{
struct V_11 * V_47 ;
struct V_11 * V_211 ;
struct V_180 * V_181 = V_183 -> V_188 ;
struct V_180 * V_378 = V_376 -> V_188 ;
struct V_180 * V_298 = V_377 -> V_188 ;
struct V_76 V_77 ;
int V_14 = 0 ;
#ifdef F_137
struct V_266 V_267 ;
#endif
if ( ! F_41 ( V_91 ) ) {
V_47 = V_181 -> V_192 ;
V_211 = V_378 -> V_190 ;
#ifdef F_137
F_138 ( & V_77 , V_88 , V_268 , & V_267 ) ;
F_191 ( & V_77 , V_376 ) ;
#endif
V_14 = V_217 ( V_47 , V_211 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_19 , V_47 , V_211 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_211 = V_378 -> V_192 ;
V_47 = V_181 -> V_190 ;
V_14 = V_217 ( V_211 , V_47 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_19 , V_211 , V_47 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_298 -> V_245 = V_181 -> V_192 ;
V_181 -> V_245 = V_378 -> V_192 ;
}
return V_14 ;
}
static int F_192 ( struct V_182 * V_183 , struct V_182 * V_376 )
{
struct V_180 * V_181 = V_183 -> V_187 -> V_188 ;
struct V_180 * V_378 = V_376 -> V_187 -> V_188 ;
struct V_76 V_77 ;
int V_14 ;
#ifdef F_137
struct V_266 V_267 ;
F_138 ( & V_77 , V_88 , V_268 , & V_267 ) ;
F_191 ( & V_77 , V_376 -> V_187 ) ;
#endif
if ( F_41 ( V_91 ) )
return 0 ;
V_14 = V_217 ( V_181 -> V_192 , V_378 -> V_190 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_20 , V_181 -> V_192 , V_378 -> V_190 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_193 ( struct V_182 * V_183 , struct V_379 * V_313 ,
int V_162 )
{
struct V_246 * V_247 = (struct V_246 * ) V_313 -> V_380 ;
#if F_146 ( V_302 ) && ! F_147 ( V_303 )
struct V_279 * V_263 = (struct V_279 * ) V_313 -> V_380 ;
#endif
int V_14 = 0 ;
if ( V_247 == NULL )
return 0 ;
switch ( V_247 -> V_271 ) {
case V_381 :
V_14 = F_136 ( V_183 -> V_187 , V_247 ) ;
break;
case V_382 :
#if F_146 ( V_302 ) && ! F_147 ( V_303 )
V_14 = F_143 ( V_183 -> V_187 , V_263 , V_383 ) ;
#endif
break;
}
return V_14 ;
}
static struct V_11 * F_194 ( struct V_384 * V_263 ,
struct V_180 * V_181 )
{
struct V_11 * V_47 ;
int V_385 = 0 ;
int V_386 ;
int V_387 ;
if ( ( V_263 -> V_114 & V_388 ) != 0 ) {
F_30 () ;
F_140 (skp, &smack_known_list, list) {
if ( V_263 -> V_389 . V_390 . V_391 != V_47 -> V_262 . V_389 . V_390 . V_391 )
continue;
if ( ( V_263 -> V_114 & V_392 ) == 0 ) {
if ( ( V_47 -> V_262 . V_114 &
V_392 ) == 0 )
V_385 = 1 ;
break;
}
for ( V_386 = - 1 , V_387 = - 1 ; V_386 == V_387 ; ) {
V_386 = F_195 ( V_263 -> V_389 . V_390 . V_393 ,
V_386 + 1 ) ;
V_387 = F_195 (
V_47 -> V_262 . V_389 . V_390 . V_393 ,
V_387 + 1 ) ;
if ( V_386 < 0 || V_387 < 0 )
break;
}
if ( V_386 == V_387 ) {
V_385 = 1 ;
break;
}
}
F_35 () ;
if ( V_385 )
return V_47 ;
if ( V_181 != NULL && V_181 -> V_190 == & V_175 )
return & V_176 ;
return & V_175 ;
}
if ( ( V_263 -> V_114 & V_394 ) != 0 ) {
V_47 = F_110 ( V_263 -> V_389 . V_194 ) ;
F_196 ( V_47 == NULL ) ;
return V_47 ;
}
return V_259 ;
}
static int F_197 ( struct V_395 * V_396 , struct V_279 * V_247 )
{
T_8 V_397 ;
int V_398 ;
int V_399 = - V_174 ;
struct V_400 V_401 ;
struct V_400 * V_402 ;
T_5 V_403 ;
struct V_404 V_405 , * V_406 ;
struct V_407 V_408 , * V_409 ;
struct V_410 V_411 , * V_412 ;
V_247 -> V_285 = 0 ;
V_398 = F_198 ( V_396 ) ;
V_402 = F_199 ( V_396 , V_398 , sizeof( V_401 ) , & V_401 ) ;
if ( V_402 == NULL )
return - V_174 ;
V_247 -> V_293 = V_402 -> V_297 ;
V_397 = V_402 -> V_397 ;
V_398 += sizeof( V_401 ) ;
V_398 = F_200 ( V_396 , V_398 , & V_397 , & V_403 ) ;
if ( V_398 < 0 )
return - V_174 ;
V_399 = V_397 ;
switch ( V_399 ) {
case V_413 :
V_406 = F_199 ( V_396 , V_398 , sizeof( V_405 ) , & V_405 ) ;
if ( V_406 != NULL )
V_247 -> V_285 = V_406 -> V_414 ;
break;
case V_415 :
V_409 = F_199 ( V_396 , V_398 , sizeof( V_408 ) , & V_408 ) ;
if ( V_409 != NULL )
V_247 -> V_285 = V_409 -> V_414 ;
break;
case V_416 :
V_412 = F_199 ( V_396 , V_398 , sizeof( V_411 ) , & V_411 ) ;
if ( V_412 != NULL )
V_247 -> V_285 = V_412 -> V_417 ;
break;
}
return V_399 ;
}
static int F_201 ( struct V_183 * V_187 , struct V_395 * V_396 )
{
struct V_384 V_418 ;
struct V_180 * V_181 = V_187 -> V_188 ;
struct V_11 * V_47 = NULL ;
int V_14 = 0 ;
struct V_76 V_77 ;
#ifdef F_137
struct V_266 V_267 ;
#endif
#if F_146 ( V_302 )
struct V_279 V_419 ;
int V_399 ;
#endif
switch ( V_187 -> V_261 ) {
case V_300 :
#ifdef V_303
if ( V_396 && V_396 -> V_420 != 0 ) {
V_47 = F_110 ( V_396 -> V_420 ) ;
goto V_421;
}
#endif
F_202 ( & V_418 ) ;
V_14 = F_203 ( V_396 , V_187 -> V_261 , & V_418 ) ;
if ( V_14 == 0 )
V_47 = F_194 ( & V_418 , V_181 ) ;
else
V_47 = V_259 ;
F_204 ( & V_418 ) ;
#ifdef V_303
V_421:
#endif
#ifdef F_137
F_138 ( & V_77 , V_88 , V_268 , & V_267 ) ;
V_77 . V_269 . V_270 . V_267 -> V_243 = V_187 -> V_261 ;
V_77 . V_269 . V_270 . V_267 -> V_422 = V_396 -> V_423 ;
F_205 ( V_396 , & V_77 . V_269 , NULL ) ;
#endif
V_14 = V_217 ( V_47 , V_181 -> V_190 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_21 , V_47 , V_181 -> V_190 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_206 ( V_396 , V_14 , 0 ) ;
break;
#if F_146 ( V_302 )
case V_304 :
V_399 = F_197 ( V_396 , & V_419 ) ;
if ( V_399 != V_415 && V_399 != V_413 )
break;
#ifdef V_303
if ( V_396 && V_396 -> V_420 != 0 )
V_47 = F_110 ( V_396 -> V_420 ) ;
else
V_47 = V_259 ;
#ifdef F_137
F_138 ( & V_77 , V_88 , V_268 , & V_267 ) ;
V_77 . V_269 . V_270 . V_267 -> V_243 = V_187 -> V_261 ;
V_77 . V_269 . V_270 . V_267 -> V_422 = V_396 -> V_423 ;
F_207 ( V_396 , & V_77 . V_269 , NULL ) ;
#endif
V_14 = V_217 ( V_47 , V_181 -> V_190 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_22 , V_47 , V_181 -> V_190 ,
V_5 , V_14 ) ;
#else
V_14 = F_143 ( V_187 , & V_419 , V_292 ) ;
#endif
break;
#endif
}
return V_14 ;
}
static int F_208 ( struct V_182 * V_183 ,
char T_7 * V_424 ,
int T_7 * V_425 , unsigned V_142 )
{
struct V_180 * V_181 ;
char * V_426 = L_23 ;
int V_375 = 1 ;
int V_14 = 0 ;
V_181 = V_183 -> V_187 -> V_188 ;
if ( V_181 -> V_245 != NULL ) {
V_426 = V_181 -> V_245 -> V_19 ;
V_375 = strlen ( V_426 ) + 1 ;
}
if ( V_375 > V_142 )
V_14 = - V_427 ;
else if ( F_209 ( V_424 , V_426 , V_375 ) != 0 )
V_14 = - V_428 ;
if ( F_210 ( V_375 , V_425 ) != 0 )
V_14 = - V_428 ;
return V_14 ;
}
static int F_211 ( struct V_182 * V_183 ,
struct V_395 * V_396 , T_3 * V_194 )
{
struct V_384 V_418 ;
struct V_180 * V_181 = NULL ;
struct V_11 * V_47 ;
int V_243 = V_429 ;
T_3 V_2 = 0 ;
int V_14 ;
if ( V_396 != NULL ) {
if ( V_396 -> V_305 == F_212 ( V_430 ) )
V_243 = V_300 ;
#if F_146 ( V_302 )
else if ( V_396 -> V_305 == F_212 ( V_431 ) )
V_243 = V_304 ;
#endif
}
if ( V_243 == V_429 && V_183 != NULL )
V_243 = V_183 -> V_187 -> V_261 ;
switch ( V_243 ) {
case V_432 :
V_181 = V_183 -> V_187 -> V_188 ;
V_2 = V_181 -> V_192 -> V_195 ;
break;
case V_300 :
#ifdef V_303
V_2 = V_396 -> V_420 ;
if ( V_2 != 0 )
break;
#endif
if ( V_183 != NULL && V_183 -> V_187 != NULL )
V_181 = V_183 -> V_187 -> V_188 ;
F_202 ( & V_418 ) ;
V_14 = F_203 ( V_396 , V_243 , & V_418 ) ;
if ( V_14 == 0 ) {
V_47 = F_194 ( & V_418 , V_181 ) ;
V_2 = V_47 -> V_195 ;
}
F_204 ( & V_418 ) ;
break;
#if F_146 ( V_302 )
case V_304 :
#ifdef V_303
V_2 = V_396 -> V_420 ;
#endif
break;
#endif
}
* V_194 = V_2 ;
if ( V_2 == 0 )
return - V_174 ;
return 0 ;
}
static void F_213 ( struct V_183 * V_187 , struct V_182 * V_433 )
{
struct V_180 * V_181 ;
struct V_11 * V_47 = F_40 () ;
if ( V_187 == NULL ||
( V_187 -> V_261 != V_300 && V_187 -> V_261 != V_304 ) )
return;
V_181 = V_187 -> V_188 ;
V_181 -> V_190 = V_47 ;
V_181 -> V_192 = V_47 ;
}
static int F_214 ( struct V_183 * V_187 , struct V_395 * V_396 ,
struct V_434 * V_435 )
{
T_9 V_243 = V_187 -> V_261 ;
struct V_11 * V_47 ;
struct V_180 * V_181 = V_187 -> V_188 ;
struct V_384 V_418 ;
struct V_246 V_436 ;
struct V_437 * V_438 ;
struct V_11 * V_439 ;
int V_14 ;
struct V_76 V_77 ;
#ifdef F_137
struct V_266 V_267 ;
#endif
#if F_146 ( V_302 )
if ( V_243 == V_304 ) {
if ( V_396 -> V_305 == F_212 ( V_430 ) )
V_243 = V_300 ;
else
return 0 ;
}
#endif
#ifdef V_303
if ( V_396 && V_396 -> V_420 != 0 ) {
V_47 = F_110 ( V_396 -> V_420 ) ;
goto V_421;
}
#endif
F_202 ( & V_418 ) ;
V_14 = F_203 ( V_396 , V_243 , & V_418 ) ;
if ( V_14 == 0 )
V_47 = F_194 ( & V_418 , V_181 ) ;
else
V_47 = & V_440 ;
F_204 ( & V_418 ) ;
#ifdef V_303
V_421:
#endif
#ifdef F_137
F_138 ( & V_77 , V_88 , V_268 , & V_267 ) ;
V_77 . V_269 . V_270 . V_267 -> V_243 = V_243 ;
V_77 . V_269 . V_270 . V_267 -> V_422 = V_396 -> V_423 ;
F_205 ( V_396 , & V_77 . V_269 , NULL ) ;
#endif
V_14 = V_217 ( V_47 , V_181 -> V_190 , V_5 , & V_77 ) ;
V_14 = F_2 ( L_24 , V_47 , V_181 -> V_190 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_435 -> V_441 = V_47 -> V_195 ;
V_438 = F_215 ( V_396 ) ;
V_436 . V_252 . V_253 = V_438 -> V_297 ;
F_30 () ;
V_439 = F_128 ( & V_436 ) ;
F_35 () ;
if ( V_439 == NULL )
V_14 = F_216 ( V_435 , & V_47 -> V_262 ) ;
else
F_217 ( V_435 ) ;
return V_14 ;
}
static void F_218 ( struct V_183 * V_187 ,
const struct V_434 * V_435 )
{
struct V_180 * V_181 = V_187 -> V_188 ;
struct V_11 * V_47 ;
if ( V_435 -> V_441 != 0 ) {
V_47 = F_110 ( V_435 -> V_441 ) ;
V_181 -> V_245 = V_47 ;
} else
V_181 -> V_245 = NULL ;
}
static int F_219 ( struct V_442 * V_442 , const struct V_39 * V_39 ,
unsigned long V_114 )
{
struct V_11 * V_47 = F_32 ( V_39 -> V_40 ) ;
V_442 -> V_40 = V_47 ;
return 0 ;
}
static void F_220 ( struct V_442 * V_442 )
{
V_442 -> V_40 = NULL ;
}
static int F_221 ( T_10 V_443 ,
const struct V_39 * V_39 , unsigned V_444 )
{
struct V_442 * V_445 ;
struct V_76 V_77 ;
struct V_11 * V_222 = F_32 ( V_39 -> V_40 ) ;
int V_446 = 0 ;
int V_14 ;
V_445 = F_222 ( V_443 ) ;
if ( V_445 == NULL )
return - V_174 ;
if ( V_445 -> V_40 == NULL )
return 0 ;
if ( V_222 == NULL )
return - V_85 ;
#ifdef F_137
F_28 ( & V_77 , V_88 , V_447 ) ;
V_77 . V_269 . V_270 . V_448 . V_442 = V_445 -> V_449 ;
V_77 . V_269 . V_270 . V_448 . V_450 = V_445 -> V_451 ;
#endif
if ( V_444 & V_452 )
V_446 = V_4 ;
if ( V_444 & ( V_453 | V_454 | V_455 ) )
V_446 = V_5 ;
V_14 = V_217 ( V_222 , V_445 -> V_40 , V_446 , & V_77 ) ;
V_14 = F_2 ( L_25 , V_222 , V_445 -> V_40 , V_446 , V_14 ) ;
return V_14 ;
}
static int F_223 ( struct V_442 * V_442 , char * * V_456 )
{
struct V_11 * V_47 = V_442 -> V_40 ;
T_2 V_457 ;
char * V_458 ;
if ( V_442 -> V_40 == NULL ) {
* V_456 = NULL ;
return 0 ;
}
V_458 = F_65 ( V_47 -> V_19 , V_52 ) ;
if ( V_458 == NULL )
return - V_53 ;
V_457 = strlen ( V_458 ) + 1 ;
* V_456 = V_458 ;
return V_457 ;
}
static int F_224 ( T_3 V_459 , T_3 V_119 , char * V_460 , void * * V_461 )
{
struct V_11 * V_47 ;
char * * V_462 = ( char * * ) V_461 ;
* V_462 = NULL ;
if ( V_459 != V_463 && V_459 != V_464 )
return - V_174 ;
if ( V_119 != V_465 && V_119 != V_466 )
return - V_174 ;
V_47 = F_16 ( V_460 , 0 ) ;
if ( F_49 ( V_47 ) )
return F_50 ( V_47 ) ;
* V_462 = V_47 -> V_19 ;
return 0 ;
}
static int F_225 ( struct V_467 * V_468 )
{
struct V_469 * V_470 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_468 -> V_471 ; V_3 ++ ) {
V_470 = & V_468 -> V_472 [ V_3 ] ;
if ( V_470 -> type == V_463 || V_470 -> type == V_464 )
return 1 ;
}
return 0 ;
}
static int F_226 ( T_3 V_194 , T_3 V_459 , T_3 V_119 , void * V_461 ,
struct V_473 * V_474 )
{
struct V_11 * V_47 ;
char * V_462 = V_461 ;
if ( F_99 ( ! V_462 ) ) {
F_227 ( 1 , L_26 ) ;
return - V_216 ;
}
if ( V_459 != V_463 && V_459 != V_464 )
return 0 ;
V_47 = F_110 ( V_194 ) ;
if ( V_119 == V_465 )
return ( V_462 == V_47 -> V_19 ) ;
if ( V_119 == V_466 )
return ( V_462 != V_47 -> V_19 ) ;
return 0 ;
}
static void F_228 ( void * V_461 )
{
}
static int F_229 ( const char * V_42 )
{
return ( strcmp ( V_42 , V_146 ) == 0 ) ;
}
static int F_230 ( T_3 V_194 , char * * V_475 , T_3 * V_476 )
{
struct V_11 * V_47 = F_110 ( V_194 ) ;
if ( V_475 )
* V_475 = V_47 -> V_19 ;
* V_476 = strlen ( V_47 -> V_19 ) ;
return 0 ;
}
static int F_231 ( const char * V_475 , T_3 V_476 , T_3 * V_194 )
{
struct V_11 * V_47 = F_232 ( V_475 ) ;
if ( V_47 )
* V_194 = V_47 -> V_195 ;
else
* V_194 = 0 ;
return 0 ;
}
static void F_233 ( char * V_475 , T_3 V_476 )
{
}
static int F_234 ( struct V_27 * V_27 , void * V_477 , T_3 V_478 )
{
return F_144 ( V_27 , V_146 , V_477 , V_478 , 0 ) ;
}
static int F_235 ( struct V_44 * V_44 , void * V_477 , T_3 V_478 )
{
return F_236 ( V_44 , V_166 , V_477 , V_478 , 0 ) ;
}
static int F_237 ( struct V_27 * V_27 , void * * V_477 , T_3 * V_478 )
{
int V_142 = 0 ;
V_142 = F_82 ( V_27 , V_146 , V_477 , true ) ;
if ( V_142 < 0 )
return V_142 ;
* V_478 = V_142 ;
return 0 ;
}
static T_11 void F_238 ( void )
{
F_20 ( & V_440 . V_62 ) ;
F_20 ( & V_102 . V_62 ) ;
F_20 ( & V_98 . V_62 ) ;
F_20 ( & V_175 . V_62 ) ;
F_20 ( & V_177 . V_62 ) ;
F_20 ( & V_176 . V_62 ) ;
F_22 ( & V_440 . V_61 ) ;
F_22 ( & V_102 . V_61 ) ;
F_22 ( & V_175 . V_61 ) ;
F_22 ( & V_98 . V_61 ) ;
F_22 ( & V_177 . V_61 ) ;
F_22 ( & V_176 . V_61 ) ;
F_239 ( & V_440 ) ;
F_239 ( & V_102 ) ;
F_239 ( & V_175 ) ;
F_239 ( & V_98 ) ;
F_239 ( & V_177 ) ;
F_239 ( & V_176 ) ;
}
static T_11 int F_240 ( void )
{
struct V_39 * V_39 ;
struct V_20 * V_21 ;
if ( ! F_241 ( L_27 ) )
return 0 ;
V_479 = 1 ;
V_54 = F_242 ( V_28 , 0 ) ;
if ( ! V_54 )
return - V_53 ;
V_21 = F_21 ( & V_98 , & V_98 ,
V_52 ) ;
if ( V_21 == NULL ) {
F_243 ( V_54 ) ;
return - V_53 ;
}
F_145 ( V_480 L_28 ) ;
V_39 = (struct V_39 * ) V_23 -> V_39 ;
V_39 -> V_40 = V_21 ;
F_238 () ;
F_244 ( V_481 , F_245 ( V_481 ) ) ;
return 0 ;
}

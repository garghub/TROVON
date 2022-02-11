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
return NULL ;
V_46 = F_14 ( V_50 , V_51 ) ;
if ( V_46 == NULL )
return NULL ;
V_14 = V_43 -> V_48 -> V_49 ( V_45 , V_42 , V_46 , V_50 ) ;
if ( V_14 > 0 )
V_47 = F_15 ( V_46 , V_14 ) ;
F_16 ( V_46 ) ;
return V_47 ;
}
struct V_28 * F_17 ( struct V_11 * V_47 )
{
struct V_28 * V_29 ;
V_29 = F_18 ( V_52 , V_53 ) ;
if ( V_29 == NULL )
return NULL ;
V_29 -> V_37 = V_47 ;
V_29 -> V_31 = 0 ;
F_19 ( & V_29 -> V_54 ) ;
return V_29 ;
}
static struct V_20 * F_20 ( struct V_11 * V_55 ,
struct V_11 * V_56 , T_1 V_57 )
{
struct V_20 * V_21 ;
V_21 = F_14 ( sizeof( struct V_20 ) , V_57 ) ;
if ( V_21 == NULL )
return NULL ;
V_21 -> V_22 = V_55 ;
V_21 -> V_58 = V_56 ;
F_21 ( & V_21 -> V_59 ) ;
F_19 ( & V_21 -> V_60 ) ;
return V_21 ;
}
static int F_22 ( struct V_61 * V_62 , struct V_61 * V_63 ,
T_1 V_57 )
{
struct V_64 * V_65 ;
struct V_64 * V_66 ;
int V_14 = 0 ;
F_21 ( V_62 ) ;
F_23 (orp, ohead, list) {
V_65 = F_14 ( sizeof( struct V_64 ) , V_57 ) ;
if ( V_65 == NULL ) {
V_14 = - V_67 ;
break;
}
* V_65 = * V_66 ;
F_24 ( & V_65 -> V_68 , V_62 ) ;
}
return V_14 ;
}
static inline unsigned int F_25 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_69 :
return V_4 ;
case V_70 :
return V_71 ;
}
return 0 ;
}
static int F_26 ( struct V_25 * V_72 ,
struct V_11 * V_73 ,
unsigned int V_1 , const char * V_74 )
{
int V_14 ;
struct V_75 V_76 , * V_77 = NULL ;
struct V_20 * V_21 ;
struct V_11 * V_78 ;
if ( ( V_1 & V_79 ) == 0 ) {
F_27 ( & V_76 , V_74 , V_80 ) ;
F_28 ( & V_76 , V_72 ) ;
V_77 = & V_76 ;
}
F_29 () ;
V_21 = F_30 ( V_72 ) -> V_40 ;
V_78 = F_31 ( V_21 ) ;
if ( ( V_1 & V_70 ) &&
( V_81 == V_82 ||
V_81 == V_83 ) ) {
if ( V_78 -> V_19 == V_73 -> V_19 )
V_14 = 0 ;
else if ( V_81 == V_83 )
V_14 = - V_84 ;
else if ( F_32 ( V_85 ) )
V_14 = 0 ;
else
V_14 = - V_84 ;
if ( V_77 )
F_33 ( V_78 -> V_19 ,
V_73 -> V_19 ,
0 , V_14 , V_77 ) ;
F_34 () ;
return V_14 ;
}
V_14 = F_35 ( V_21 , V_73 , F_25 ( V_1 ) , V_77 ) ;
F_34 () ;
return V_14 ;
}
static int F_36 ( struct V_25 * V_86 , unsigned int V_1 )
{
int V_14 ;
struct V_11 * V_47 ;
V_14 = F_37 ( V_86 , V_1 ) ;
if ( V_14 != 0 )
return V_14 ;
V_47 = F_7 ( V_86 ) ;
V_14 = F_26 ( V_23 , V_47 , V_1 , V_87 ) ;
return V_14 ;
}
static int F_38 ( struct V_25 * V_88 )
{
int V_14 ;
struct V_11 * V_47 ;
V_14 = F_39 ( V_88 ) ;
if ( V_14 != 0 )
return V_14 ;
V_47 = F_31 ( F_5 () ) ;
V_14 = F_26 ( V_88 , V_47 , V_70 , V_87 ) ;
return V_14 ;
}
static int F_40 ( int V_89 )
{
int V_14 = 0 ;
struct V_11 * V_47 = F_41 () ;
if ( F_42 ( V_90 ) )
return 0 ;
if ( V_91 != NULL && V_91 != V_47 )
V_14 = - V_84 ;
return V_14 ;
}
static int F_43 ( struct V_92 * V_93 )
{
struct V_94 * V_95 ;
V_95 = F_14 ( sizeof( struct V_94 ) , V_51 ) ;
if ( V_95 == NULL )
return - V_67 ;
V_95 -> V_96 = & V_97 ;
V_95 -> V_98 = & V_97 ;
V_95 -> V_99 = & V_97 ;
V_95 -> V_100 = & V_101 ;
V_93 -> V_102 = V_95 ;
return 0 ;
}
static void F_44 ( struct V_92 * V_93 )
{
F_16 ( V_93 -> V_102 ) ;
V_93 -> V_102 = NULL ;
}
static int F_45 ( char * V_103 , char * V_104 )
{
char * V_105 , * V_106 , * V_107 , * V_45 ;
V_107 = ( char * ) F_46 ( V_51 ) ;
if ( V_107 == NULL )
return - V_67 ;
for ( V_105 = V_103 , V_106 = V_103 ; V_106 != NULL ; V_105 = V_106 + 1 ) {
if ( strstr ( V_105 , V_108 ) == V_105 )
V_45 = V_104 ;
else if ( strstr ( V_105 , V_109 ) == V_105 )
V_45 = V_104 ;
else if ( strstr ( V_105 , V_110 ) == V_105 )
V_45 = V_104 ;
else if ( strstr ( V_105 , V_111 ) == V_105 )
V_45 = V_104 ;
else if ( strstr ( V_105 , V_112 ) == V_105 )
V_45 = V_104 ;
else
V_45 = V_107 ;
V_106 = strchr ( V_105 , ',' ) ;
if ( V_106 != NULL )
* V_106 = '\0' ;
if ( * V_45 != '\0' )
strcat ( V_45 , L_7 ) ;
strcat ( V_45 , V_105 ) ;
}
strcpy ( V_103 , V_107 ) ;
F_47 ( ( unsigned long ) V_107 ) ;
return 0 ;
}
static int F_48 ( struct V_92 * V_93 , int V_113 , void * V_114 )
{
struct V_44 * V_115 = V_93 -> V_116 ;
struct V_27 * V_27 = F_49 ( V_115 ) ;
struct V_94 * V_117 = V_93 -> V_102 ;
struct V_28 * V_29 ;
struct V_11 * V_47 ;
char * V_118 ;
char * V_106 ;
int V_119 = 0 ;
int V_120 = 0 ;
if ( V_117 -> V_121 )
return 0 ;
V_117 -> V_121 = 1 ;
for ( V_118 = V_114 ; V_118 != NULL ; V_118 = V_106 ) {
V_106 = strchr ( V_118 , ',' ) ;
if ( V_106 != NULL )
* V_106 ++ = '\0' ;
if ( strncmp ( V_118 , V_110 , strlen ( V_110 ) ) == 0 ) {
V_118 += strlen ( V_110 ) ;
V_47 = F_15 ( V_118 , 0 ) ;
if ( V_47 != NULL ) {
V_117 -> V_100 = V_47 ;
V_120 = 1 ;
}
} else if ( strncmp ( V_118 , V_109 , strlen ( V_109 ) ) == 0 ) {
V_118 += strlen ( V_109 ) ;
V_47 = F_15 ( V_118 , 0 ) ;
if ( V_47 != NULL ) {
V_117 -> V_99 = V_47 ;
V_120 = 1 ;
}
} else if ( strncmp ( V_118 , V_108 ,
strlen ( V_108 ) ) == 0 ) {
V_118 += strlen ( V_108 ) ;
V_47 = F_15 ( V_118 , 0 ) ;
if ( V_47 != NULL ) {
V_117 -> V_98 = V_47 ;
V_120 = 1 ;
}
} else if ( strncmp ( V_118 , V_111 , strlen ( V_111 ) ) == 0 ) {
V_118 += strlen ( V_111 ) ;
V_47 = F_15 ( V_118 , 0 ) ;
if ( V_47 != NULL ) {
V_117 -> V_96 = V_47 ;
V_120 = 1 ;
}
} else if ( strncmp ( V_118 , V_112 , strlen ( V_112 ) ) == 0 ) {
V_118 += strlen ( V_112 ) ;
V_47 = F_15 ( V_118 , 0 ) ;
if ( V_47 != NULL ) {
V_117 -> V_96 = V_47 ;
V_119 = 1 ;
V_120 = 1 ;
}
}
}
if ( ! F_42 ( V_122 ) ) {
if ( V_120 )
return - V_123 ;
V_47 = F_41 () ;
V_117 -> V_96 = V_47 ;
V_117 -> V_98 = V_47 ;
}
V_29 = V_27 -> V_30 ;
if ( V_29 == NULL ) {
V_29 = F_17 ( V_117 -> V_96 ) ;
if ( V_29 == NULL )
return - V_67 ;
V_27 -> V_30 = V_29 ;
} else
V_29 -> V_37 = V_117 -> V_96 ;
if ( V_119 )
V_29 -> V_31 |= V_124 ;
return 0 ;
}
static int F_50 ( struct V_44 * V_44 )
{
struct V_94 * V_125 = V_44 -> V_126 -> V_102 ;
int V_14 ;
struct V_75 V_76 ;
F_27 ( & V_76 , V_87 , V_127 ) ;
F_51 ( & V_76 , V_44 ) ;
V_14 = F_52 ( V_125 -> V_99 , V_4 , & V_76 ) ;
V_14 = F_4 ( L_8 , V_125 -> V_99 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_53 ( struct V_128 * V_129 )
{
struct V_27 * V_27 = F_10 ( V_129 -> V_38 ) ;
struct V_20 * V_130 = V_129 -> V_39 -> V_40 ;
struct V_28 * V_29 ;
int V_14 ;
V_14 = F_54 ( V_129 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( V_129 -> V_131 )
return 0 ;
V_29 = V_27 -> V_30 ;
if ( V_29 -> V_22 == NULL || V_29 -> V_22 == V_130 -> V_22 )
return 0 ;
if ( V_129 -> V_132 & ( V_133 | V_134 ) ) {
struct V_25 * V_72 ;
V_14 = 0 ;
F_29 () ;
V_72 = F_55 ( V_23 ) ;
if ( F_56 ( V_72 != NULL ) )
V_14 = F_26 ( V_72 ,
V_29 -> V_22 ,
V_70 ,
V_87 ) ;
F_34 () ;
if ( V_14 != 0 )
return V_14 ;
} else if ( V_129 -> V_132 )
return - V_123 ;
V_130 -> V_22 = V_29 -> V_22 ;
V_129 -> V_135 |= V_136 ;
return 0 ;
}
static void F_57 ( struct V_128 * V_129 )
{
struct V_20 * V_130 = V_129 -> V_39 -> V_40 ;
if ( V_130 -> V_22 != V_130 -> V_58 )
V_23 -> V_137 = 0 ;
}
static int F_58 ( struct V_128 * V_129 )
{
struct V_20 * V_21 = F_5 () ;
int V_138 = F_59 ( V_129 ) ;
if ( ! V_138 && ( V_21 -> V_22 != V_21 -> V_58 ) )
V_138 = 1 ;
return V_138 ;
}
static int F_60 ( struct V_27 * V_27 )
{
struct V_11 * V_47 = F_41 () ;
V_27 -> V_30 = F_17 ( V_47 ) ;
if ( V_27 -> V_30 == NULL )
return - V_67 ;
return 0 ;
}
static void F_61 ( struct V_27 * V_27 )
{
F_62 ( V_52 , V_27 -> V_30 ) ;
V_27 -> V_30 = NULL ;
}
static int F_63 ( struct V_27 * V_27 , struct V_27 * V_139 ,
const struct V_140 * V_140 , const char * * V_42 ,
void * * V_141 , T_2 * V_142 )
{
struct V_28 * V_143 = V_27 -> V_30 ;
struct V_11 * V_47 = F_41 () ;
struct V_11 * V_29 = F_11 ( V_27 ) ;
struct V_11 * V_144 = F_11 ( V_139 ) ;
int V_145 ;
if ( V_42 )
* V_42 = V_146 ;
if ( V_141 && V_142 ) {
F_29 () ;
V_145 = F_64 ( V_47 -> V_19 , V_144 -> V_19 ,
& V_47 -> V_59 ) ;
F_34 () ;
if ( V_145 > 0 && ( ( V_145 & V_8 ) != 0 ) &&
F_65 ( V_139 ) ) {
V_29 = V_144 ;
V_143 -> V_31 |= V_147 ;
}
* V_141 = F_66 ( V_29 -> V_19 , V_53 ) ;
if ( * V_141 == NULL )
return - V_67 ;
* V_142 = strlen ( V_29 -> V_19 ) ;
}
return 0 ;
}
static int F_67 ( struct V_44 * V_148 , struct V_27 * V_139 ,
struct V_44 * V_149 )
{
struct V_11 * V_29 ;
struct V_75 V_76 ;
int V_14 ;
F_27 ( & V_76 , V_87 , V_127 ) ;
F_51 ( & V_76 , V_148 ) ;
V_29 = F_11 ( F_49 ( V_148 ) ) ;
V_14 = F_52 ( V_29 , V_5 , & V_76 ) ;
V_14 = F_8 ( F_49 ( V_148 ) , V_5 , V_14 ) ;
if ( V_14 == 0 && F_68 ( V_149 ) ) {
V_29 = F_11 ( F_49 ( V_149 ) ) ;
F_51 ( & V_76 , V_149 ) ;
V_14 = F_52 ( V_29 , V_5 , & V_76 ) ;
V_14 = F_8 ( F_49 ( V_149 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_69 ( struct V_27 * V_139 , struct V_44 * V_44 )
{
struct V_27 * V_43 = F_49 ( V_44 ) ;
struct V_75 V_76 ;
int V_14 ;
F_27 ( & V_76 , V_87 , V_127 ) ;
F_51 ( & V_76 , V_44 ) ;
V_14 = F_52 ( F_11 ( V_43 ) , V_5 , & V_76 ) ;
V_14 = F_8 ( V_43 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_27 ( & V_76 , V_87 , V_150 ) ;
F_70 ( & V_76 , V_139 ) ;
V_14 = F_52 ( F_11 ( V_139 ) , V_5 , & V_76 ) ;
V_14 = F_8 ( V_139 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_71 ( struct V_27 * V_139 , struct V_44 * V_44 )
{
struct V_75 V_76 ;
int V_14 ;
F_27 ( & V_76 , V_87 , V_127 ) ;
F_51 ( & V_76 , V_44 ) ;
V_14 = F_52 ( F_11 ( F_49 ( V_44 ) ) , V_5 , & V_76 ) ;
V_14 = F_8 ( F_49 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
F_27 ( & V_76 , V_87 , V_150 ) ;
F_70 ( & V_76 , V_139 ) ;
V_14 = F_52 ( F_11 ( V_139 ) , V_5 , & V_76 ) ;
V_14 = F_8 ( V_139 , V_5 , V_14 ) ;
}
return V_14 ;
}
static int F_72 ( struct V_27 * V_151 ,
struct V_44 * V_148 ,
struct V_27 * V_152 ,
struct V_44 * V_149 )
{
int V_14 ;
struct V_11 * V_29 ;
struct V_75 V_76 ;
F_27 ( & V_76 , V_87 , V_127 ) ;
F_51 ( & V_76 , V_148 ) ;
V_29 = F_11 ( F_49 ( V_148 ) ) ;
V_14 = F_52 ( V_29 , V_71 , & V_76 ) ;
V_14 = F_8 ( F_49 ( V_148 ) , V_71 , V_14 ) ;
if ( V_14 == 0 && F_68 ( V_149 ) ) {
V_29 = F_11 ( F_49 ( V_149 ) ) ;
F_51 ( & V_76 , V_149 ) ;
V_14 = F_52 ( V_29 , V_71 , & V_76 ) ;
V_14 = F_8 ( F_49 ( V_149 ) , V_71 , V_14 ) ;
}
return V_14 ;
}
static int F_73 ( struct V_27 * V_27 , int V_153 )
{
struct V_75 V_76 ;
int V_154 = V_153 & V_155 ;
int V_14 ;
V_153 &= ( V_4 | V_5 | V_6 | V_7 ) ;
if ( V_153 == 0 )
return 0 ;
if ( V_154 )
return - V_156 ;
F_27 ( & V_76 , V_87 , V_150 ) ;
F_70 ( & V_76 , V_27 ) ;
V_14 = F_52 ( F_11 ( V_27 ) , V_153 , & V_76 ) ;
V_14 = F_8 ( V_27 , V_153 , V_14 ) ;
return V_14 ;
}
static int F_74 ( struct V_44 * V_44 , struct V_157 * V_157 )
{
struct V_75 V_76 ;
int V_14 ;
if ( V_157 -> V_158 & V_159 )
return 0 ;
F_27 ( & V_76 , V_87 , V_127 ) ;
F_51 ( & V_76 , V_44 ) ;
V_14 = F_52 ( F_11 ( F_49 ( V_44 ) ) , V_5 , & V_76 ) ;
V_14 = F_8 ( F_49 ( V_44 ) , V_5 , V_14 ) ;
return V_14 ;
}
static int F_75 ( const struct V_160 * V_160 )
{
struct V_75 V_76 ;
struct V_27 * V_27 = F_49 ( V_160 -> V_44 ) ;
int V_14 ;
F_27 ( & V_76 , V_87 , V_161 ) ;
F_76 ( & V_76 , * V_160 ) ;
V_14 = F_52 ( F_11 ( V_27 ) , V_4 , & V_76 ) ;
V_14 = F_8 ( V_27 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_77 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_141 , T_2 V_162 , int V_113 )
{
struct V_75 V_76 ;
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
V_14 = F_78 ( V_44 , V_42 , V_141 , V_162 , V_113 ) ;
if ( V_163 && ! F_42 ( V_122 ) )
V_14 = - V_123 ;
if ( V_14 == 0 && V_164 ) {
V_47 = V_162 ? F_15 ( V_141 , V_162 ) : NULL ;
if ( V_47 == NULL || ( V_165 &&
( V_47 == & V_175 || V_47 == & V_176 ) ) )
V_14 = - V_174 ;
}
F_27 ( & V_76 , V_87 , V_127 ) ;
F_51 ( & V_76 , V_44 ) ;
if ( V_14 == 0 ) {
V_14 = F_52 ( F_11 ( F_49 ( V_44 ) ) , V_5 , & V_76 ) ;
V_14 = F_8 ( F_49 ( V_44 ) , V_5 , V_14 ) ;
}
return V_14 ;
}
static void F_79 ( struct V_44 * V_44 , const char * V_42 ,
const void * V_141 , T_2 V_162 , int V_113 )
{
struct V_11 * V_47 ;
struct V_28 * V_29 = F_49 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_171 ) == 0 ) {
V_29 -> V_31 |= V_124 ;
return;
}
if ( strcmp ( V_42 , V_166 ) == 0 ) {
V_47 = F_15 ( V_141 , V_162 ) ;
if ( V_47 != NULL )
V_29 -> V_37 = V_47 ;
else
V_29 -> V_37 = & V_177 ;
} else if ( strcmp ( V_42 , V_169 ) == 0 ) {
V_47 = F_15 ( V_141 , V_162 ) ;
if ( V_47 != NULL )
V_29 -> V_22 = V_47 ;
else
V_29 -> V_22 = & V_177 ;
} else if ( strcmp ( V_42 , V_170 ) == 0 ) {
V_47 = F_15 ( V_141 , V_162 ) ;
if ( V_47 != NULL )
V_29 -> V_178 = V_47 ;
else
V_29 -> V_178 = & V_177 ;
}
return;
}
static int F_80 ( struct V_44 * V_44 , const char * V_42 )
{
struct V_75 V_76 ;
int V_14 ;
F_27 ( & V_76 , V_87 , V_127 ) ;
F_51 ( & V_76 , V_44 ) ;
V_14 = F_52 ( F_11 ( F_49 ( V_44 ) ) , V_4 , & V_76 ) ;
V_14 = F_8 ( F_49 ( V_44 ) , V_4 , V_14 ) ;
return V_14 ;
}
static int F_81 ( struct V_44 * V_44 , const char * V_42 )
{
struct V_28 * V_29 ;
struct V_75 V_76 ;
int V_14 = 0 ;
if ( strcmp ( V_42 , V_166 ) == 0 ||
strcmp ( V_42 , V_167 ) == 0 ||
strcmp ( V_42 , V_168 ) == 0 ||
strcmp ( V_42 , V_169 ) == 0 ||
strcmp ( V_42 , V_171 ) == 0 ||
strcmp ( V_42 , V_170 ) == 0 ) {
if ( ! F_42 ( V_122 ) )
V_14 = - V_123 ;
} else
V_14 = F_82 ( V_44 , V_42 ) ;
if ( V_14 != 0 )
return V_14 ;
F_27 ( & V_76 , V_87 , V_127 ) ;
F_51 ( & V_76 , V_44 ) ;
V_14 = F_52 ( F_11 ( F_49 ( V_44 ) ) , V_5 , & V_76 ) ;
V_14 = F_8 ( F_49 ( V_44 ) , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_29 = F_49 ( V_44 ) -> V_30 ;
if ( strcmp ( V_42 , V_166 ) == 0 )
V_29 -> V_22 = NULL ;
else if ( strcmp ( V_42 , V_170 ) == 0 )
V_29 -> V_178 = NULL ;
else if ( strcmp ( V_42 , V_171 ) == 0 )
V_29 -> V_31 &= ~ V_124 ;
return 0 ;
}
static int F_83 ( const struct V_27 * V_27 ,
const char * V_42 , void * * V_46 ,
bool V_179 )
{
struct V_180 * V_181 ;
struct V_182 * V_183 ;
struct V_92 * V_125 ;
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
V_125 = V_43 -> V_33 ;
if ( V_125 -> V_185 != V_186 )
return - V_187 ;
V_183 = F_84 ( V_43 ) ;
if ( V_183 == NULL || V_183 -> V_188 == NULL )
return - V_187 ;
V_181 = V_183 -> V_188 -> V_189 ;
if ( strcmp ( V_42 , V_190 ) == 0 )
V_29 = V_181 -> V_191 ;
else if ( strcmp ( V_42 , V_192 ) == 0 )
V_29 = V_181 -> V_193 ;
else
return - V_187 ;
V_184 = strlen ( V_29 -> V_19 ) ;
if ( V_14 == 0 ) {
* V_46 = V_29 -> V_19 ;
V_14 = V_184 ;
}
return V_14 ;
}
static int F_85 ( struct V_27 * V_27 , char * V_46 ,
T_2 V_194 )
{
int V_142 = sizeof( V_166 ) ;
if ( V_46 != NULL && V_142 <= V_194 )
memcpy ( V_46 , V_166 , V_142 ) ;
return V_142 ;
}
static void F_86 ( const struct V_27 * V_27 , T_3 * V_195 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
* V_195 = V_29 -> V_37 -> V_196 ;
}
static int F_87 ( struct V_38 * V_38 , int V_153 )
{
return 0 ;
}
static int F_88 ( struct V_38 * V_38 )
{
struct V_11 * V_47 = F_41 () ;
V_38 -> V_197 = V_47 ;
return 0 ;
}
static void F_89 ( struct V_38 * V_38 )
{
V_38 -> V_197 = NULL ;
}
static int F_90 ( struct V_38 * V_38 , unsigned int V_198 ,
unsigned long V_199 )
{
int V_14 = 0 ;
struct V_75 V_76 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_27 ( & V_76 , V_87 , V_161 ) ;
F_76 ( & V_76 , V_38 -> V_200 ) ;
if ( F_91 ( V_198 ) & V_201 ) {
V_14 = F_52 ( F_11 ( V_27 ) , V_5 , & V_76 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
}
if ( V_14 == 0 && ( F_91 ( V_198 ) & V_202 ) ) {
V_14 = F_52 ( F_11 ( V_27 ) , V_4 , & V_76 ) ;
V_14 = F_9 ( V_38 , V_4 , V_14 ) ;
}
return V_14 ;
}
static int F_92 ( struct V_38 * V_38 , unsigned int V_198 )
{
struct V_75 V_76 ;
int V_14 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_27 ( & V_76 , V_87 , V_161 ) ;
F_76 ( & V_76 , V_38 -> V_200 ) ;
V_14 = F_52 ( F_11 ( V_27 ) , V_9 , & V_76 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
return V_14 ;
}
static int F_93 ( struct V_38 * V_38 , unsigned int V_198 ,
unsigned long V_199 )
{
struct V_75 V_76 ;
int V_14 = 0 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
switch ( V_198 ) {
case V_203 :
break;
case V_204 :
case V_205 :
F_27 ( & V_76 , V_87 , V_161 ) ;
F_76 ( & V_76 , V_38 -> V_200 ) ;
V_14 = F_52 ( F_11 ( V_27 ) , V_9 , & V_76 ) ;
V_14 = F_9 ( V_38 , V_9 , V_14 ) ;
break;
case V_206 :
case V_207 :
F_27 ( & V_76 , V_87 , V_161 ) ;
F_76 ( & V_76 , V_38 -> V_200 ) ;
V_14 = F_52 ( F_11 ( V_27 ) , V_5 , & V_76 ) ;
V_14 = F_9 ( V_38 , V_5 , V_14 ) ;
break;
default:
break;
}
return V_14 ;
}
static int F_94 ( struct V_38 * V_38 ,
unsigned long V_208 , unsigned long V_209 ,
unsigned long V_113 )
{
struct V_11 * V_47 ;
struct V_11 * V_210 ;
struct V_64 * V_211 ;
struct V_20 * V_21 ;
struct V_11 * V_212 ;
struct V_28 * V_29 ;
int V_145 ;
int V_213 ;
int V_214 ;
int V_14 ;
if ( V_38 == NULL )
return 0 ;
V_29 = F_10 ( V_38 ) -> V_30 ;
if ( V_29 -> V_178 == NULL )
return 0 ;
V_210 = V_29 -> V_178 ;
V_21 = F_5 () ;
V_47 = F_41 () ;
V_14 = 0 ;
F_29 () ;
F_23 (srp, &skp->smk_rules, list) {
V_212 = V_211 -> V_215 ;
if ( V_210 -> V_19 == V_212 -> V_19 )
continue;
V_145 = F_64 ( V_211 -> V_216 -> V_19 ,
V_212 -> V_19 ,
& V_21 -> V_59 ) ;
if ( V_145 == - V_217 )
V_145 = V_211 -> V_218 ;
else
V_145 &= V_211 -> V_218 ;
if ( V_145 == 0 )
continue;
V_213 = F_64 ( V_210 -> V_19 , V_212 -> V_19 ,
& V_210 -> V_59 ) ;
if ( V_213 == - V_217 ) {
V_14 = - V_84 ;
break;
}
V_214 = F_64 ( V_210 -> V_19 , V_212 -> V_19 ,
& V_21 -> V_59 ) ;
if ( V_214 != - V_217 )
V_213 &= V_214 ;
if ( ( V_145 | V_213 ) != V_213 ) {
V_14 = - V_84 ;
break;
}
}
F_34 () ;
return V_14 ;
}
static void F_95 ( struct V_38 * V_38 )
{
V_38 -> V_197 = F_41 () ;
}
static int F_96 ( struct V_25 * V_219 ,
struct V_220 * V_221 , int V_222 )
{
struct V_11 * V_47 ;
struct V_11 * V_223 = F_31 ( V_219 -> V_39 -> V_40 ) ;
struct V_38 * V_38 ;
int V_14 ;
struct V_75 V_76 ;
V_38 = F_97 ( V_221 , struct V_38 , V_224 ) ;
V_47 = V_38 -> V_197 ;
V_14 = V_218 ( V_47 , V_223 , V_5 , NULL ) ;
V_14 = F_2 ( L_9 , V_47 , V_223 , V_5 , V_14 ) ;
if ( V_14 != 0 && F_98 ( V_219 , V_90 ) )
V_14 = 0 ;
F_27 ( & V_76 , V_87 , V_80 ) ;
F_28 ( & V_76 , V_219 ) ;
F_33 ( V_47 -> V_19 , V_223 -> V_19 , V_5 , V_14 , & V_76 ) ;
return V_14 ;
}
static int F_99 ( struct V_38 * V_38 )
{
int V_14 ;
int V_145 = 0 ;
struct V_75 V_76 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
F_27 ( & V_76 , V_87 , V_161 ) ;
F_76 ( & V_76 , V_38 -> V_200 ) ;
if ( V_38 -> V_225 & V_226 )
V_145 = V_4 ;
if ( V_38 -> V_225 & V_227 )
V_145 |= V_5 ;
V_14 = F_52 ( F_11 ( V_27 ) , V_145 , & V_76 ) ;
V_14 = F_9 ( V_38 , V_145 , V_14 ) ;
return V_14 ;
}
static int F_100 ( struct V_38 * V_38 , const struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_27 * V_27 = F_10 ( V_38 ) ;
struct V_75 V_76 ;
int V_14 ;
if ( F_42 ( V_90 ) )
return 0 ;
F_27 ( & V_76 , V_87 , V_161 ) ;
F_76 ( & V_76 , V_38 -> V_200 ) ;
V_14 = V_218 ( V_21 -> V_22 , F_11 ( V_27 ) , V_4 , & V_76 ) ;
V_14 = F_12 ( V_39 , V_38 , V_4 , V_14 ) ;
return V_14 ;
}
static int F_101 ( struct V_39 * V_39 , T_1 V_57 )
{
struct V_20 * V_21 ;
V_21 = F_20 ( NULL , NULL , V_57 ) ;
if ( V_21 == NULL )
return - V_67 ;
V_39 -> V_40 = V_21 ;
return 0 ;
}
static void F_102 ( struct V_39 * V_39 )
{
struct V_20 * V_21 = V_39 -> V_40 ;
struct V_64 * V_228 ;
struct V_61 * V_229 ;
struct V_61 * V_230 ;
if ( V_21 == NULL )
return;
V_39 -> V_40 = NULL ;
F_103 (l, n, &tsp->smk_rules) {
V_228 = F_104 ( V_229 , struct V_64 , V_68 ) ;
F_105 ( & V_228 -> V_68 ) ;
F_16 ( V_228 ) ;
}
F_16 ( V_21 ) ;
}
static int F_106 ( struct V_39 * V_231 , const struct V_39 * V_232 ,
T_1 V_57 )
{
struct V_20 * V_233 = V_232 -> V_40 ;
struct V_20 * V_234 ;
int V_14 ;
V_234 = F_20 ( V_233 -> V_22 , V_233 -> V_22 , V_57 ) ;
if ( V_234 == NULL )
return - V_67 ;
V_14 = F_22 ( & V_234 -> V_59 , & V_233 -> V_59 , V_57 ) ;
if ( V_14 != 0 )
return V_14 ;
V_231 -> V_40 = V_234 ;
return 0 ;
}
static void F_107 ( struct V_39 * V_231 , const struct V_39 * V_232 )
{
struct V_20 * V_233 = V_232 -> V_40 ;
struct V_20 * V_234 = V_231 -> V_40 ;
V_234 -> V_22 = V_233 -> V_22 ;
V_234 -> V_58 = V_233 -> V_22 ;
F_19 ( & V_234 -> V_60 ) ;
F_21 ( & V_234 -> V_59 ) ;
}
static int F_108 ( struct V_39 * V_231 , T_3 V_195 )
{
struct V_20 * V_234 = V_231 -> V_40 ;
struct V_11 * V_47 = F_109 ( V_195 ) ;
if ( V_47 == NULL )
return - V_174 ;
V_234 -> V_22 = V_47 ;
return 0 ;
}
static int F_110 ( struct V_39 * V_231 ,
struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_20 * V_21 = V_231 -> V_40 ;
V_21 -> V_58 = V_29 -> V_37 ;
V_21 -> V_22 = V_21 -> V_58 ;
return 0 ;
}
static int F_111 ( struct V_25 * V_235 , int V_236 ,
const char * V_237 )
{
struct V_75 V_76 ;
struct V_11 * V_47 = F_7 ( V_235 ) ;
int V_14 ;
F_27 ( & V_76 , V_237 , V_80 ) ;
F_28 ( & V_76 , V_235 ) ;
V_14 = F_52 ( V_47 , V_236 , & V_76 ) ;
V_14 = F_6 ( V_235 , V_236 , V_14 ) ;
return V_14 ;
}
static int F_112 ( struct V_25 * V_235 , T_4 V_238 )
{
return F_111 ( V_235 , V_5 , V_87 ) ;
}
static int F_113 ( struct V_25 * V_235 )
{
return F_111 ( V_235 , V_4 , V_87 ) ;
}
static int F_114 ( struct V_25 * V_235 )
{
return F_111 ( V_235 , V_4 , V_87 ) ;
}
static void F_115 ( struct V_25 * V_235 , T_3 * V_195 )
{
struct V_11 * V_47 = F_7 ( V_235 ) ;
* V_195 = V_47 -> V_196 ;
}
static int F_116 ( struct V_25 * V_235 , int V_239 )
{
int V_14 ;
V_14 = F_117 ( V_235 , V_239 ) ;
if ( V_14 == 0 )
V_14 = F_111 ( V_235 , V_5 , V_87 ) ;
return V_14 ;
}
static int F_118 ( struct V_25 * V_235 , int V_240 )
{
int V_14 ;
V_14 = F_119 ( V_235 , V_240 ) ;
if ( V_14 == 0 )
V_14 = F_111 ( V_235 , V_5 , V_87 ) ;
return V_14 ;
}
static int F_120 ( struct V_25 * V_235 )
{
return F_111 ( V_235 , V_4 , V_87 ) ;
}
static int F_121 ( struct V_25 * V_235 )
{
int V_14 ;
V_14 = F_122 ( V_235 ) ;
if ( V_14 == 0 )
V_14 = F_111 ( V_235 , V_5 , V_87 ) ;
return V_14 ;
}
static int F_123 ( struct V_25 * V_235 )
{
return F_111 ( V_235 , V_4 , V_87 ) ;
}
static int F_124 ( struct V_25 * V_235 )
{
return F_111 ( V_235 , V_5 , V_87 ) ;
}
static int F_125 ( struct V_25 * V_235 , struct V_241 * V_242 ,
int V_243 , T_3 V_195 )
{
struct V_75 V_76 ;
struct V_11 * V_47 ;
struct V_11 * V_223 = F_7 ( V_235 ) ;
int V_14 ;
F_27 ( & V_76 , V_87 , V_80 ) ;
F_28 ( & V_76 , V_235 ) ;
if ( V_195 == 0 ) {
V_14 = F_52 ( V_223 , V_5 , & V_76 ) ;
V_14 = F_6 ( V_235 , V_5 , V_14 ) ;
return V_14 ;
}
V_47 = F_109 ( V_195 ) ;
V_14 = V_218 ( V_47 , V_223 , V_5 , & V_76 ) ;
V_14 = F_2 ( L_10 , V_47 , V_223 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_126 ( struct V_25 * V_235 )
{
return 0 ;
}
static void F_127 ( struct V_25 * V_235 , struct V_27 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 ;
struct V_11 * V_47 = F_7 ( V_235 ) ;
V_29 -> V_37 = V_47 ;
}
static int F_128 ( struct V_183 * V_188 , int V_244 , T_1 V_245 )
{
struct V_11 * V_47 = F_41 () ;
struct V_180 * V_181 ;
V_181 = F_14 ( sizeof( struct V_180 ) , V_245 ) ;
if ( V_181 == NULL )
return - V_67 ;
V_181 -> V_191 = V_47 ;
V_181 -> V_193 = V_47 ;
V_181 -> V_246 = NULL ;
V_188 -> V_189 = V_181 ;
return 0 ;
}
static void F_129 ( struct V_183 * V_188 )
{
F_16 ( V_188 -> V_189 ) ;
}
static struct V_11 * F_130 ( struct V_247 * V_248 )
{
struct V_249 * V_250 ;
struct V_251 * V_252 = & V_248 -> V_253 ;
if ( V_252 -> V_254 == 0 )
return NULL ;
F_23 (snp, &smk_netlbladdr_list, list)
if ( ( & V_250 -> V_255 . V_253 ) -> V_254 ==
( V_252 -> V_254 & ( & V_250 -> V_256 ) -> V_254 ) ) {
if ( V_250 -> V_257 == & V_258 )
return NULL ;
return V_250 -> V_257 ;
}
return NULL ;
}
static int F_131 ( struct V_183 * V_188 , int V_259 )
{
struct V_11 * V_47 ;
struct V_180 * V_181 = V_188 -> V_189 ;
int V_14 = 0 ;
F_132 () ;
F_133 ( V_188 ) ;
if ( V_181 -> V_193 == V_260 ||
V_259 == V_261 )
F_134 ( V_188 ) ;
else {
V_47 = V_181 -> V_193 ;
V_14 = F_135 ( V_188 , V_188 -> V_262 , & V_47 -> V_263 ) ;
}
F_136 ( V_188 ) ;
F_137 () ;
return V_14 ;
}
static int F_138 ( struct V_183 * V_188 , struct V_247 * V_264 )
{
struct V_11 * V_47 ;
int V_14 ;
int V_265 ;
struct V_11 * V_266 ;
struct V_180 * V_181 = V_188 -> V_189 ;
struct V_75 V_76 ;
F_29 () ;
V_266 = F_130 ( V_264 ) ;
if ( V_266 != NULL ) {
#ifdef F_139
struct V_267 V_268 ;
F_140 ( & V_76 , V_87 , V_269 , & V_268 ) ;
V_76 . V_270 . V_271 . V_268 -> V_244 = V_264 -> V_272 ;
V_76 . V_270 . V_271 . V_268 -> V_273 = V_264 -> V_274 ;
V_76 . V_270 . V_271 . V_268 -> V_275 . V_276 = V_264 -> V_253 . V_254 ;
#endif
V_265 = V_261 ;
V_47 = V_181 -> V_193 ;
V_14 = V_218 ( V_47 , V_266 , V_5 , & V_76 ) ;
V_14 = F_2 ( L_11 , V_47 , V_266 , V_5 , V_14 ) ;
} else {
V_265 = V_277 ;
V_14 = 0 ;
}
F_34 () ;
if ( V_14 != 0 )
return V_14 ;
return F_131 ( V_188 , V_265 ) ;
}
static void F_141 ( struct V_182 * V_183 , struct V_278 * V_279 )
{
struct V_183 * V_188 = V_183 -> V_188 ;
struct V_280 * V_281 ;
struct V_180 * V_181 = V_183 -> V_188 -> V_189 ;
struct V_282 * V_283 ;
unsigned short V_284 = 0 ;
if ( V_279 == NULL ) {
F_142 (spp, &smk_ipv6_port_list, list) {
if ( V_188 != V_283 -> V_285 )
continue;
V_283 -> V_191 = V_181 -> V_191 ;
V_283 -> V_193 = V_181 -> V_193 ;
return;
}
return;
}
V_281 = (struct V_280 * ) V_279 ;
V_284 = F_143 ( V_281 -> V_286 ) ;
if ( V_284 == 0 )
return;
F_142 (spp, &smk_ipv6_port_list, list) {
if ( V_283 -> V_287 != V_284 )
continue;
V_283 -> V_287 = V_284 ;
V_283 -> V_285 = V_188 ;
V_283 -> V_191 = V_181 -> V_191 ;
V_283 -> V_193 = V_181 -> V_193 ;
return;
}
V_283 = F_14 ( sizeof( * V_283 ) , V_51 ) ;
if ( V_283 == NULL )
return;
V_283 -> V_287 = V_284 ;
V_283 -> V_285 = V_188 ;
V_283 -> V_191 = V_181 -> V_191 ;
V_283 -> V_193 = V_181 -> V_193 ;
F_144 ( & V_283 -> V_68 , & V_288 ) ;
return;
}
static int F_145 ( struct V_183 * V_188 , struct V_280 * V_279 ,
int V_289 )
{
T_5 * V_290 ;
T_6 * V_291 ;
struct V_282 * V_283 ;
struct V_180 * V_181 = V_188 -> V_189 ;
struct V_11 * V_47 ;
unsigned short V_284 = 0 ;
struct V_11 * V_292 ;
struct V_75 V_76 ;
int V_14 ;
#ifdef F_139
struct V_267 V_268 ;
#endif
if ( V_289 == V_293 ) {
V_47 = V_260 ;
V_292 = V_181 -> V_191 ;
} else {
V_47 = V_181 -> V_193 ;
V_292 = V_260 ;
}
V_284 = F_143 ( V_279 -> V_286 ) ;
V_290 = ( T_5 * ) ( & V_279 -> V_294 ) ;
V_291 = ( T_6 * ) ( & V_279 -> V_294 ) ;
if ( V_291 [ 0 ] || V_291 [ 1 ] || V_291 [ 2 ] || V_290 [ 6 ] || F_143 ( V_290 [ 7 ] ) != 1 )
goto V_295;
if ( V_289 == V_293 ) {
V_47 = & V_176 ;
goto V_295;
}
F_142 (spp, &smk_ipv6_port_list, list) {
if ( V_283 -> V_287 != V_284 )
continue;
V_292 = V_283 -> V_191 ;
if ( V_289 == V_296 )
V_181 -> V_246 = V_283 -> V_193 ;
break;
}
V_295:
#ifdef F_139
F_140 ( & V_76 , V_87 , V_269 , & V_268 ) ;
V_76 . V_270 . V_271 . V_268 -> V_244 = V_188 -> V_262 ;
V_76 . V_270 . V_271 . V_268 -> V_273 = V_284 ;
if ( V_289 == V_293 )
V_76 . V_270 . V_271 . V_268 -> V_297 . V_298 = V_279 -> V_294 ;
else
V_76 . V_270 . V_271 . V_268 -> V_297 . V_276 = V_279 -> V_294 ;
#endif
V_14 = V_218 ( V_47 , V_292 , V_5 , & V_76 ) ;
V_14 = F_2 ( L_12 , V_47 , V_292 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_146 ( struct V_27 * V_27 , const char * V_42 ,
const void * V_141 , T_2 V_162 , int V_113 )
{
struct V_11 * V_47 ;
struct V_28 * V_299 = V_27 -> V_30 ;
struct V_180 * V_181 ;
struct V_182 * V_183 ;
int V_14 = 0 ;
if ( V_141 == NULL || V_162 > V_50 || V_162 == 0 )
return - V_174 ;
V_47 = F_15 ( V_141 , V_162 ) ;
if ( V_47 == NULL )
return - V_174 ;
if ( strcmp ( V_42 , V_146 ) == 0 ) {
V_299 -> V_37 = V_47 ;
V_299 -> V_31 |= V_300 ;
return 0 ;
}
if ( V_27 -> V_33 -> V_185 != V_186 )
return - V_187 ;
V_183 = F_84 ( V_27 ) ;
if ( V_183 == NULL || V_183 -> V_188 == NULL )
return - V_187 ;
V_181 = V_183 -> V_188 -> V_189 ;
if ( strcmp ( V_42 , V_190 ) == 0 )
V_181 -> V_191 = V_47 ;
else if ( strcmp ( V_42 , V_192 ) == 0 ) {
V_181 -> V_193 = V_47 ;
if ( V_183 -> V_188 -> V_262 == V_301 ) {
V_14 = F_131 ( V_183 -> V_188 , V_277 ) ;
if ( V_14 != 0 )
F_147 ( V_302
L_13 ,
V_87 , - V_14 ) ;
}
} else
return - V_187 ;
#if F_148 ( V_303 ) && ! F_149 ( V_304 )
if ( V_183 -> V_188 -> V_262 == V_305 )
F_141 ( V_183 , NULL ) ;
#endif
return 0 ;
}
static int F_150 ( struct V_182 * V_183 , int V_244 ,
int type , int V_306 , int V_307 )
{
struct V_180 * V_181 ;
if ( V_183 -> V_188 == NULL )
return 0 ;
if ( F_151 ( V_23 -> V_113 & V_308 ) ) {
V_181 = V_183 -> V_188 -> V_189 ;
V_181 -> V_191 = & V_176 ;
V_181 -> V_193 = & V_176 ;
}
if ( V_244 != V_301 )
return 0 ;
return F_131 ( V_183 -> V_188 , V_277 ) ;
}
static int F_152 ( struct V_182 * V_183 , struct V_278 * V_279 ,
int V_309 )
{
#if F_148 ( V_303 )
if ( V_183 -> V_188 != NULL && V_183 -> V_188 -> V_262 == V_305 )
F_141 ( V_183 , V_279 ) ;
#endif
return 0 ;
}
static int F_153 ( struct V_182 * V_183 , struct V_278 * V_264 ,
int V_309 )
{
int V_14 = 0 ;
if ( V_183 -> V_188 == NULL )
return 0 ;
switch ( V_183 -> V_188 -> V_262 ) {
case V_301 :
if ( V_309 < sizeof( struct V_247 ) )
return - V_174 ;
V_14 = F_138 ( V_183 -> V_188 , (struct V_247 * ) V_264 ) ;
break;
case V_305 :
if ( V_309 < sizeof( struct V_280 ) )
return - V_174 ;
#if F_148 ( V_303 ) && ! F_149 ( V_304 )
V_14 = F_145 ( V_183 -> V_188 , (struct V_280 * ) V_264 ,
V_296 ) ;
#endif
break;
}
return V_14 ;
}
static int F_154 ( int V_113 )
{
int V_145 = 0 ;
if ( V_113 & V_310 )
V_145 |= V_4 ;
if ( V_113 & V_311 )
V_145 |= V_5 ;
if ( V_113 & V_312 )
V_145 |= V_6 ;
return V_145 ;
}
static int F_155 ( struct V_313 * V_314 )
{
struct V_11 * V_47 = F_41 () ;
V_314 -> V_40 = V_47 ;
return 0 ;
}
static void F_156 ( struct V_313 * V_314 )
{
V_314 -> V_40 = NULL ;
}
static struct V_11 * F_157 ( struct V_315 * V_316 )
{
return (struct V_11 * ) V_316 -> V_317 . V_40 ;
}
static int F_158 ( struct V_315 * V_316 )
{
struct V_318 * V_29 = & V_316 -> V_317 ;
struct V_11 * V_47 = F_41 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_159 ( struct V_315 * V_316 )
{
struct V_318 * V_29 = & V_316 -> V_317 ;
V_29 -> V_40 = NULL ;
}
static int F_160 ( struct V_315 * V_316 , int V_236 )
{
struct V_11 * V_181 = F_157 ( V_316 ) ;
struct V_75 V_76 ;
int V_14 ;
#ifdef F_139
F_27 ( & V_76 , V_87 , V_319 ) ;
V_76 . V_270 . V_271 . V_320 = V_316 -> V_317 . V_321 ;
#endif
V_14 = F_52 ( V_181 , V_236 , & V_76 ) ;
V_14 = F_4 ( L_14 , V_181 , V_236 , V_14 ) ;
return V_14 ;
}
static int F_161 ( struct V_315 * V_316 , int V_322 )
{
int V_145 ;
V_145 = F_154 ( V_322 ) ;
return F_160 ( V_316 , V_145 ) ;
}
static int F_162 ( struct V_315 * V_316 , int V_198 )
{
int V_145 ;
switch ( V_198 ) {
case V_323 :
case V_324 :
V_145 = V_4 ;
break;
case V_325 :
case V_326 :
case V_327 :
case V_328 :
V_145 = V_71 ;
break;
case V_329 :
case V_330 :
return 0 ;
default:
return - V_174 ;
}
return F_160 ( V_316 , V_145 ) ;
}
static int F_163 ( struct V_315 * V_316 , char T_7 * V_331 ,
int V_322 )
{
int V_145 ;
V_145 = F_154 ( V_322 ) ;
return F_160 ( V_316 , V_145 ) ;
}
static struct V_11 * F_164 ( struct V_332 * V_333 )
{
return (struct V_11 * ) V_333 -> V_334 . V_40 ;
}
static int F_165 ( struct V_332 * V_333 )
{
struct V_318 * V_29 = & V_333 -> V_334 ;
struct V_11 * V_47 = F_41 () ;
V_29 -> V_40 = V_47 ;
return 0 ;
}
static void F_166 ( struct V_332 * V_333 )
{
struct V_318 * V_29 = & V_333 -> V_334 ;
V_29 -> V_40 = NULL ;
}
static int F_167 ( struct V_332 * V_333 , int V_236 )
{
struct V_11 * V_181 = F_164 ( V_333 ) ;
struct V_75 V_76 ;
int V_14 ;
#ifdef F_139
F_27 ( & V_76 , V_87 , V_319 ) ;
V_76 . V_270 . V_271 . V_320 = V_333 -> V_334 . V_321 ;
#endif
V_14 = F_52 ( V_181 , V_236 , & V_76 ) ;
V_14 = F_4 ( L_15 , V_181 , V_236 , V_14 ) ;
return V_14 ;
}
static int F_168 ( struct V_332 * V_333 , int V_335 )
{
int V_145 ;
V_145 = F_154 ( V_335 ) ;
return F_167 ( V_333 , V_145 ) ;
}
static int F_169 ( struct V_332 * V_333 , int V_198 )
{
int V_145 ;
switch ( V_198 ) {
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_323 :
case V_341 :
V_145 = V_4 ;
break;
case V_342 :
case V_343 :
case V_328 :
case V_325 :
V_145 = V_71 ;
break;
case V_329 :
case V_344 :
return 0 ;
default:
return - V_174 ;
}
return F_167 ( V_333 , V_145 ) ;
}
static int F_170 ( struct V_332 * V_333 , struct V_345 * V_346 ,
unsigned V_347 , int V_348 )
{
return F_167 ( V_333 , V_71 ) ;
}
static int F_171 ( struct V_349 * V_350 )
{
struct V_318 * V_351 = & V_350 -> V_352 ;
struct V_11 * V_47 = F_41 () ;
V_351 -> V_40 = V_47 ;
return 0 ;
}
static void F_172 ( struct V_349 * V_350 )
{
struct V_318 * V_351 = & V_350 -> V_352 ;
V_351 -> V_40 = NULL ;
}
static struct V_11 * F_173 ( struct V_349 * V_350 )
{
return (struct V_11 * ) V_350 -> V_352 . V_40 ;
}
static int F_174 ( struct V_349 * V_350 , int V_236 )
{
struct V_11 * V_353 = F_173 ( V_350 ) ;
struct V_75 V_76 ;
int V_14 ;
#ifdef F_139
F_27 ( & V_76 , V_87 , V_319 ) ;
V_76 . V_270 . V_271 . V_320 = V_350 -> V_352 . V_321 ;
#endif
V_14 = F_52 ( V_353 , V_236 , & V_76 ) ;
V_14 = F_4 ( L_16 , V_353 , V_236 , V_14 ) ;
return V_14 ;
}
static int F_175 ( struct V_349 * V_350 , int V_354 )
{
int V_145 ;
V_145 = F_154 ( V_354 ) ;
return F_174 ( V_350 , V_145 ) ;
}
static int F_176 ( struct V_349 * V_350 , int V_198 )
{
int V_145 ;
switch ( V_198 ) {
case V_323 :
case V_355 :
V_145 = V_4 ;
break;
case V_325 :
case V_328 :
V_145 = V_71 ;
break;
case V_329 :
case V_356 :
return 0 ;
default:
return - V_174 ;
}
return F_174 ( V_350 , V_145 ) ;
}
static int F_177 ( struct V_349 * V_350 , struct V_313 * V_314 ,
int V_354 )
{
int V_145 ;
V_145 = F_154 ( V_354 ) ;
return F_174 ( V_350 , V_145 ) ;
}
static int F_178 ( struct V_349 * V_350 , struct V_313 * V_314 ,
struct V_25 * V_357 , long type , int V_1 )
{
return F_174 ( V_350 , V_71 ) ;
}
static int F_179 ( struct V_318 * V_358 , short V_359 )
{
struct V_11 * V_360 = V_358 -> V_40 ;
int V_145 = F_154 ( V_359 ) ;
struct V_75 V_76 ;
int V_14 ;
#ifdef F_139
F_27 ( & V_76 , V_87 , V_319 ) ;
V_76 . V_270 . V_271 . V_320 = V_358 -> V_321 ;
#endif
V_14 = F_52 ( V_360 , V_145 , & V_76 ) ;
V_14 = F_4 ( L_17 , V_360 , V_145 , V_14 ) ;
return V_14 ;
}
static void F_180 ( struct V_318 * V_358 , T_3 * V_195 )
{
struct V_11 * V_360 = V_358 -> V_40 ;
* V_195 = V_360 -> V_196 ;
}
static void F_181 ( struct V_44 * V_361 , struct V_27 * V_27 )
{
struct V_92 * V_125 ;
struct V_94 * V_95 ;
struct V_28 * V_29 ;
struct V_11 * V_47 ;
struct V_11 * V_362 = F_41 () ;
struct V_11 * V_363 ;
char V_364 [ V_172 ] ;
int V_365 = 0 ;
int V_14 ;
struct V_44 * V_45 ;
if ( V_27 == NULL )
return;
V_29 = V_27 -> V_30 ;
F_182 ( & V_29 -> V_54 ) ;
if ( V_29 -> V_31 & V_300 )
goto V_366;
V_125 = V_27 -> V_33 ;
V_95 = V_125 -> V_102 ;
V_363 = V_95 -> V_98 ;
if ( V_361 -> V_367 == V_361 ) {
switch ( V_125 -> V_185 ) {
case V_368 :
V_95 -> V_96 = & V_175 ;
V_95 -> V_98 = & V_175 ;
V_29 -> V_37 = V_95 -> V_96 ;
break;
case V_369 :
V_29 -> V_37 = F_41 () ;
break;
default:
V_29 -> V_37 = V_95 -> V_96 ;
break;
}
V_29 -> V_31 |= V_300 ;
goto V_366;
}
switch ( V_125 -> V_185 ) {
case V_370 :
case V_371 :
case V_186 :
case V_368 :
V_363 = & V_175 ;
break;
case V_372 :
V_363 = V_362 ;
break;
case V_373 :
break;
case V_369 :
V_363 = & V_175 ;
default:
if ( F_183 ( V_27 -> V_374 ) ) {
V_363 = & V_175 ;
break;
}
if ( V_27 -> V_48 -> V_49 == NULL )
break;
V_45 = F_184 ( V_361 ) ;
V_47 = F_13 ( V_166 , V_27 , V_45 ) ;
if ( V_47 != NULL )
V_363 = V_47 ;
if ( F_185 ( V_27 -> V_374 ) ) {
if ( V_29 -> V_31 & V_147 ) {
V_29 -> V_31 &= ~ V_147 ;
V_14 = V_27 -> V_48 -> V_375 ( V_45 ,
V_171 ,
V_173 , V_172 ,
0 ) ;
} else {
V_14 = V_27 -> V_48 -> V_49 ( V_45 ,
V_171 , V_364 ,
V_172 ) ;
if ( V_14 >= 0 && strncmp ( V_364 , V_173 ,
V_172 ) != 0 )
V_14 = - V_174 ;
}
if ( V_14 >= 0 )
V_365 = V_124 ;
}
V_47 = F_13 ( V_169 , V_27 , V_45 ) ;
if ( V_47 == & V_175 || V_47 == & V_176 )
V_47 = NULL ;
V_29 -> V_22 = V_47 ;
V_47 = F_13 ( V_170 , V_27 , V_45 ) ;
if ( V_47 == & V_175 || V_47 == & V_176 )
V_47 = NULL ;
V_29 -> V_178 = V_47 ;
F_186 ( V_45 ) ;
break;
}
if ( V_363 == NULL )
V_29 -> V_37 = V_362 ;
else
V_29 -> V_37 = V_363 ;
V_29 -> V_31 |= ( V_300 | V_365 ) ;
V_366:
F_187 ( & V_29 -> V_54 ) ;
return;
}
static int F_188 ( struct V_25 * V_235 , char * V_42 , char * * V_141 )
{
struct V_11 * V_47 = F_7 ( V_235 ) ;
char * V_105 ;
int V_376 ;
if ( strcmp ( V_42 , L_18 ) != 0 )
return - V_174 ;
V_105 = F_66 ( V_47 -> V_19 , V_51 ) ;
if ( V_105 == NULL )
return - V_67 ;
V_376 = strlen ( V_105 ) ;
* V_141 = V_105 ;
return V_376 ;
}
static int F_189 ( struct V_25 * V_235 , char * V_42 ,
void * V_141 , T_2 V_162 )
{
struct V_20 * V_21 ;
struct V_39 * V_231 ;
struct V_11 * V_47 ;
if ( V_235 != V_23 )
return - V_123 ;
if ( ! F_42 ( V_122 ) )
return - V_123 ;
if ( V_141 == NULL || V_162 == 0 || V_162 >= V_50 )
return - V_174 ;
if ( strcmp ( V_42 , L_18 ) != 0 )
return - V_174 ;
V_47 = F_15 ( V_141 , V_162 ) ;
if ( V_47 == NULL )
return - V_174 ;
if ( V_47 == & V_176 )
return - V_123 ;
V_231 = F_190 () ;
if ( V_231 == NULL )
return - V_67 ;
V_21 = V_231 -> V_40 ;
V_21 -> V_22 = V_47 ;
F_191 ( V_231 ) ;
return V_162 ;
}
static int F_192 ( struct V_183 * V_183 ,
struct V_183 * V_377 , struct V_183 * V_378 )
{
struct V_11 * V_47 ;
struct V_11 * V_212 ;
struct V_180 * V_181 = V_183 -> V_189 ;
struct V_180 * V_379 = V_377 -> V_189 ;
struct V_180 * V_299 = V_378 -> V_189 ;
struct V_75 V_76 ;
int V_14 = 0 ;
#ifdef F_139
struct V_267 V_268 ;
#endif
if ( ! F_42 ( V_90 ) ) {
V_47 = V_181 -> V_193 ;
V_212 = V_379 -> V_191 ;
#ifdef F_139
F_140 ( & V_76 , V_87 , V_269 , & V_268 ) ;
F_193 ( & V_76 , V_377 ) ;
#endif
V_14 = V_218 ( V_47 , V_212 , V_5 , & V_76 ) ;
V_14 = F_2 ( L_19 , V_47 , V_212 , V_5 , V_14 ) ;
if ( V_14 == 0 ) {
V_212 = V_379 -> V_193 ;
V_47 = V_181 -> V_191 ;
V_14 = V_218 ( V_212 , V_47 , V_5 , & V_76 ) ;
V_14 = F_2 ( L_19 , V_212 , V_47 ,
V_5 , V_14 ) ;
}
}
if ( V_14 == 0 ) {
V_299 -> V_246 = V_181 -> V_193 ;
V_181 -> V_246 = V_379 -> V_193 ;
}
return V_14 ;
}
static int F_194 ( struct V_182 * V_183 , struct V_182 * V_377 )
{
struct V_180 * V_181 = V_183 -> V_188 -> V_189 ;
struct V_180 * V_379 = V_377 -> V_188 -> V_189 ;
struct V_75 V_76 ;
int V_14 ;
#ifdef F_139
struct V_267 V_268 ;
F_140 ( & V_76 , V_87 , V_269 , & V_268 ) ;
F_193 ( & V_76 , V_377 -> V_188 ) ;
#endif
if ( F_42 ( V_90 ) )
return 0 ;
V_14 = V_218 ( V_181 -> V_193 , V_379 -> V_191 , V_5 , & V_76 ) ;
V_14 = F_2 ( L_20 , V_181 -> V_193 , V_379 -> V_191 , V_5 , V_14 ) ;
return V_14 ;
}
static int F_195 ( struct V_182 * V_183 , struct V_380 * V_314 ,
int V_162 )
{
struct V_247 * V_248 = (struct V_247 * ) V_314 -> V_381 ;
#if F_148 ( V_303 ) && ! F_149 ( V_304 )
struct V_280 * V_264 = (struct V_280 * ) V_314 -> V_381 ;
#endif
int V_14 = 0 ;
if ( V_248 == NULL )
return 0 ;
switch ( V_248 -> V_272 ) {
case V_382 :
V_14 = F_138 ( V_183 -> V_188 , V_248 ) ;
break;
case V_383 :
#if F_148 ( V_303 ) && ! F_149 ( V_304 )
V_14 = F_145 ( V_183 -> V_188 , V_264 , V_384 ) ;
#endif
break;
}
return V_14 ;
}
static struct V_11 * F_196 ( struct V_385 * V_264 ,
struct V_180 * V_181 )
{
struct V_11 * V_47 ;
int V_386 = 0 ;
int V_387 ;
int V_388 ;
if ( ( V_264 -> V_113 & V_389 ) != 0 ) {
F_29 () ;
F_142 (skp, &smack_known_list, list) {
if ( V_264 -> V_390 . V_391 . V_392 != V_47 -> V_263 . V_390 . V_391 . V_392 )
continue;
if ( ( V_264 -> V_113 & V_393 ) == 0 ) {
if ( ( V_47 -> V_263 . V_113 &
V_393 ) == 0 )
V_386 = 1 ;
break;
}
for ( V_387 = - 1 , V_388 = - 1 ; V_387 == V_388 ; ) {
V_387 = F_197 ( V_264 -> V_390 . V_391 . V_394 ,
V_387 + 1 ) ;
V_388 = F_197 (
V_47 -> V_263 . V_390 . V_391 . V_394 ,
V_388 + 1 ) ;
if ( V_387 < 0 || V_388 < 0 )
break;
}
if ( V_387 == V_388 ) {
V_386 = 1 ;
break;
}
}
F_34 () ;
if ( V_386 )
return V_47 ;
if ( V_181 != NULL && V_181 -> V_191 == & V_175 )
return & V_176 ;
return & V_175 ;
}
if ( ( V_264 -> V_113 & V_395 ) != 0 ) {
V_47 = F_109 ( V_264 -> V_390 . V_195 ) ;
F_198 ( V_47 == NULL ) ;
return V_47 ;
}
return V_260 ;
}
static int F_199 ( struct V_396 * V_397 , struct V_280 * V_248 )
{
T_8 V_398 ;
int V_399 ;
int V_400 = - V_174 ;
struct V_401 V_402 ;
struct V_401 * V_403 ;
T_5 V_404 ;
struct V_405 V_406 , * V_407 ;
struct V_408 V_409 , * V_410 ;
struct V_411 V_412 , * V_413 ;
V_248 -> V_286 = 0 ;
V_399 = F_200 ( V_397 ) ;
V_403 = F_201 ( V_397 , V_399 , sizeof( V_402 ) , & V_402 ) ;
if ( V_403 == NULL )
return - V_174 ;
V_248 -> V_294 = V_403 -> V_298 ;
V_398 = V_403 -> V_398 ;
V_399 += sizeof( V_402 ) ;
V_399 = F_202 ( V_397 , V_399 , & V_398 , & V_404 ) ;
if ( V_399 < 0 )
return - V_174 ;
V_400 = V_398 ;
switch ( V_400 ) {
case V_414 :
V_407 = F_201 ( V_397 , V_399 , sizeof( V_406 ) , & V_406 ) ;
if ( V_407 != NULL )
V_248 -> V_286 = V_407 -> V_415 ;
break;
case V_416 :
V_410 = F_201 ( V_397 , V_399 , sizeof( V_409 ) , & V_409 ) ;
if ( V_410 != NULL )
V_248 -> V_286 = V_410 -> V_415 ;
break;
case V_417 :
V_413 = F_201 ( V_397 , V_399 , sizeof( V_412 ) , & V_412 ) ;
if ( V_413 != NULL )
V_248 -> V_286 = V_413 -> V_418 ;
break;
}
return V_400 ;
}
static int F_203 ( struct V_183 * V_188 , struct V_396 * V_397 )
{
struct V_385 V_419 ;
struct V_180 * V_181 = V_188 -> V_189 ;
struct V_11 * V_47 = NULL ;
int V_14 = 0 ;
struct V_75 V_76 ;
#ifdef F_139
struct V_267 V_268 ;
#endif
#if F_148 ( V_303 )
struct V_280 V_420 ;
int V_400 ;
#endif
switch ( V_188 -> V_262 ) {
case V_301 :
#ifdef V_304
if ( V_397 && V_397 -> V_421 != 0 ) {
V_47 = F_109 ( V_397 -> V_421 ) ;
goto V_422;
}
#endif
F_204 ( & V_419 ) ;
V_14 = F_205 ( V_397 , V_188 -> V_262 , & V_419 ) ;
if ( V_14 == 0 )
V_47 = F_196 ( & V_419 , V_181 ) ;
else
V_47 = V_260 ;
F_206 ( & V_419 ) ;
#ifdef V_304
V_422:
#endif
#ifdef F_139
F_140 ( & V_76 , V_87 , V_269 , & V_268 ) ;
V_76 . V_270 . V_271 . V_268 -> V_244 = V_188 -> V_262 ;
V_76 . V_270 . V_271 . V_268 -> V_423 = V_397 -> V_424 ;
F_207 ( V_397 , & V_76 . V_270 , NULL ) ;
#endif
V_14 = V_218 ( V_47 , V_181 -> V_191 , V_5 , & V_76 ) ;
V_14 = F_2 ( L_21 , V_47 , V_181 -> V_191 ,
V_5 , V_14 ) ;
if ( V_14 != 0 )
F_208 ( V_397 , V_14 , 0 ) ;
break;
#if F_148 ( V_303 )
case V_305 :
V_400 = F_199 ( V_397 , & V_420 ) ;
if ( V_400 != V_416 && V_400 != V_414 )
break;
#ifdef V_304
if ( V_397 && V_397 -> V_421 != 0 )
V_47 = F_109 ( V_397 -> V_421 ) ;
else
V_47 = V_260 ;
#ifdef F_139
F_140 ( & V_76 , V_87 , V_269 , & V_268 ) ;
V_76 . V_270 . V_271 . V_268 -> V_244 = V_188 -> V_262 ;
V_76 . V_270 . V_271 . V_268 -> V_423 = V_397 -> V_424 ;
F_209 ( V_397 , & V_76 . V_270 , NULL ) ;
#endif
V_14 = V_218 ( V_47 , V_181 -> V_191 , V_5 , & V_76 ) ;
V_14 = F_2 ( L_22 , V_47 , V_181 -> V_191 ,
V_5 , V_14 ) ;
#else
V_14 = F_145 ( V_188 , & V_420 , V_293 ) ;
#endif
break;
#endif
}
return V_14 ;
}
static int F_210 ( struct V_182 * V_183 ,
char T_7 * V_425 ,
int T_7 * V_426 , unsigned V_142 )
{
struct V_180 * V_181 ;
char * V_427 = L_23 ;
int V_376 = 1 ;
int V_14 = 0 ;
V_181 = V_183 -> V_188 -> V_189 ;
if ( V_181 -> V_246 != NULL ) {
V_427 = V_181 -> V_246 -> V_19 ;
V_376 = strlen ( V_427 ) + 1 ;
}
if ( V_376 > V_142 )
V_14 = - V_428 ;
else if ( F_211 ( V_425 , V_427 , V_376 ) != 0 )
V_14 = - V_429 ;
if ( F_212 ( V_376 , V_426 ) != 0 )
V_14 = - V_429 ;
return V_14 ;
}
static int F_213 ( struct V_182 * V_183 ,
struct V_396 * V_397 , T_3 * V_195 )
{
struct V_385 V_419 ;
struct V_180 * V_181 = NULL ;
struct V_11 * V_47 ;
int V_244 = V_430 ;
T_3 V_2 = 0 ;
int V_14 ;
if ( V_397 != NULL ) {
if ( V_397 -> V_306 == F_214 ( V_431 ) )
V_244 = V_301 ;
#if F_148 ( V_303 )
else if ( V_397 -> V_306 == F_214 ( V_432 ) )
V_244 = V_305 ;
#endif
}
if ( V_244 == V_430 && V_183 != NULL )
V_244 = V_183 -> V_188 -> V_262 ;
switch ( V_244 ) {
case V_433 :
V_181 = V_183 -> V_188 -> V_189 ;
V_2 = V_181 -> V_193 -> V_196 ;
break;
case V_301 :
#ifdef V_304
V_2 = V_397 -> V_421 ;
if ( V_2 != 0 )
break;
#endif
if ( V_183 != NULL && V_183 -> V_188 != NULL )
V_181 = V_183 -> V_188 -> V_189 ;
F_204 ( & V_419 ) ;
V_14 = F_205 ( V_397 , V_244 , & V_419 ) ;
if ( V_14 == 0 ) {
V_47 = F_196 ( & V_419 , V_181 ) ;
V_2 = V_47 -> V_196 ;
}
F_206 ( & V_419 ) ;
break;
#if F_148 ( V_303 )
case V_305 :
#ifdef V_304
V_2 = V_397 -> V_421 ;
#endif
break;
#endif
}
* V_195 = V_2 ;
if ( V_2 == 0 )
return - V_174 ;
return 0 ;
}
static void F_215 ( struct V_183 * V_188 , struct V_182 * V_434 )
{
struct V_180 * V_181 ;
struct V_11 * V_47 = F_41 () ;
if ( V_188 == NULL ||
( V_188 -> V_262 != V_301 && V_188 -> V_262 != V_305 ) )
return;
V_181 = V_188 -> V_189 ;
V_181 -> V_191 = V_47 ;
V_181 -> V_193 = V_47 ;
}
static int F_216 ( struct V_183 * V_188 , struct V_396 * V_397 ,
struct V_435 * V_436 )
{
T_9 V_244 = V_188 -> V_262 ;
struct V_11 * V_47 ;
struct V_180 * V_181 = V_188 -> V_189 ;
struct V_385 V_419 ;
struct V_247 V_437 ;
struct V_438 * V_439 ;
struct V_11 * V_440 ;
int V_14 ;
struct V_75 V_76 ;
#ifdef F_139
struct V_267 V_268 ;
#endif
#if F_148 ( V_303 )
if ( V_244 == V_305 ) {
if ( V_397 -> V_306 == F_214 ( V_431 ) )
V_244 = V_301 ;
else
return 0 ;
}
#endif
#ifdef V_304
if ( V_397 && V_397 -> V_421 != 0 ) {
V_47 = F_109 ( V_397 -> V_421 ) ;
goto V_422;
}
#endif
F_204 ( & V_419 ) ;
V_14 = F_205 ( V_397 , V_244 , & V_419 ) ;
if ( V_14 == 0 )
V_47 = F_196 ( & V_419 , V_181 ) ;
else
V_47 = & V_441 ;
F_206 ( & V_419 ) ;
#ifdef V_304
V_422:
#endif
#ifdef F_139
F_140 ( & V_76 , V_87 , V_269 , & V_268 ) ;
V_76 . V_270 . V_271 . V_268 -> V_244 = V_244 ;
V_76 . V_270 . V_271 . V_268 -> V_423 = V_397 -> V_424 ;
F_207 ( V_397 , & V_76 . V_270 , NULL ) ;
#endif
V_14 = V_218 ( V_47 , V_181 -> V_191 , V_5 , & V_76 ) ;
V_14 = F_2 ( L_24 , V_47 , V_181 -> V_191 , V_5 , V_14 ) ;
if ( V_14 != 0 )
return V_14 ;
V_436 -> V_442 = V_47 -> V_196 ;
V_439 = F_217 ( V_397 ) ;
V_437 . V_253 . V_254 = V_439 -> V_298 ;
F_29 () ;
V_440 = F_130 ( & V_437 ) ;
F_34 () ;
if ( V_440 == NULL )
V_14 = F_218 ( V_436 , & V_47 -> V_263 ) ;
else
F_219 ( V_436 ) ;
return V_14 ;
}
static void F_220 ( struct V_183 * V_188 ,
const struct V_435 * V_436 )
{
struct V_180 * V_181 = V_188 -> V_189 ;
struct V_11 * V_47 ;
if ( V_436 -> V_442 != 0 ) {
V_47 = F_109 ( V_436 -> V_442 ) ;
V_181 -> V_246 = V_47 ;
} else
V_181 -> V_246 = NULL ;
}
static int F_221 ( struct V_443 * V_443 , const struct V_39 * V_39 ,
unsigned long V_113 )
{
struct V_11 * V_47 = F_31 ( V_39 -> V_40 ) ;
V_443 -> V_40 = V_47 ;
return 0 ;
}
static void F_222 ( struct V_443 * V_443 )
{
V_443 -> V_40 = NULL ;
}
static int F_223 ( T_10 V_444 ,
const struct V_39 * V_39 , unsigned V_445 )
{
struct V_443 * V_446 ;
struct V_75 V_76 ;
struct V_11 * V_223 = F_31 ( V_39 -> V_40 ) ;
int V_447 = 0 ;
int V_14 ;
V_446 = F_224 ( V_444 ) ;
if ( V_446 == NULL )
return - V_174 ;
if ( V_446 -> V_40 == NULL )
return 0 ;
if ( V_223 == NULL )
return - V_84 ;
#ifdef F_139
F_27 ( & V_76 , V_87 , V_448 ) ;
V_76 . V_270 . V_271 . V_449 . V_443 = V_446 -> V_450 ;
V_76 . V_270 . V_271 . V_449 . V_451 = V_446 -> V_452 ;
#endif
if ( V_445 & V_453 )
V_447 = V_4 ;
if ( V_445 & ( V_454 | V_455 | V_456 ) )
V_447 = V_5 ;
V_14 = V_218 ( V_223 , V_446 -> V_40 , V_447 , & V_76 ) ;
V_14 = F_2 ( L_25 , V_223 , V_446 -> V_40 , V_447 , V_14 ) ;
return V_14 ;
}
static int F_225 ( struct V_443 * V_443 , char * * V_457 )
{
struct V_11 * V_47 = V_443 -> V_40 ;
T_2 V_458 ;
char * V_459 ;
if ( V_443 -> V_40 == NULL ) {
* V_457 = NULL ;
return 0 ;
}
V_459 = F_66 ( V_47 -> V_19 , V_51 ) ;
if ( V_459 == NULL )
return - V_67 ;
V_458 = strlen ( V_459 ) + 1 ;
* V_457 = V_459 ;
return V_458 ;
}
static int F_226 ( T_3 V_460 , T_3 V_118 , char * V_461 , void * * V_462 )
{
struct V_11 * V_47 ;
char * * V_463 = ( char * * ) V_462 ;
* V_463 = NULL ;
if ( V_460 != V_464 && V_460 != V_465 )
return - V_174 ;
if ( V_118 != V_466 && V_118 != V_467 )
return - V_174 ;
V_47 = F_15 ( V_461 , 0 ) ;
if ( V_47 )
* V_463 = V_47 -> V_19 ;
return 0 ;
}
static int F_227 ( struct V_468 * V_469 )
{
struct V_470 * V_471 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_469 -> V_472 ; V_3 ++ ) {
V_471 = & V_469 -> V_473 [ V_3 ] ;
if ( V_471 -> type == V_464 || V_471 -> type == V_465 )
return 1 ;
}
return 0 ;
}
static int F_228 ( T_3 V_195 , T_3 V_460 , T_3 V_118 , void * V_462 ,
struct V_474 * V_475 )
{
struct V_11 * V_47 ;
char * V_463 = V_462 ;
if ( F_151 ( ! V_463 ) ) {
F_229 ( 1 , L_26 ) ;
return - V_217 ;
}
if ( V_460 != V_464 && V_460 != V_465 )
return 0 ;
V_47 = F_109 ( V_195 ) ;
if ( V_118 == V_466 )
return ( V_463 == V_47 -> V_19 ) ;
if ( V_118 == V_467 )
return ( V_463 != V_47 -> V_19 ) ;
return 0 ;
}
static void F_230 ( void * V_462 )
{
}
static int F_231 ( const char * V_42 )
{
return ( strcmp ( V_42 , V_146 ) == 0 ) ;
}
static int F_232 ( T_3 V_195 , char * * V_476 , T_3 * V_477 )
{
struct V_11 * V_47 = F_109 ( V_195 ) ;
if ( V_476 )
* V_476 = V_47 -> V_19 ;
* V_477 = strlen ( V_47 -> V_19 ) ;
return 0 ;
}
static int F_233 ( const char * V_476 , T_3 V_477 , T_3 * V_195 )
{
struct V_11 * V_47 = F_234 ( V_476 ) ;
if ( V_47 )
* V_195 = V_47 -> V_196 ;
else
* V_195 = 0 ;
return 0 ;
}
static void F_235 ( char * V_476 , T_3 V_477 )
{
}
static int F_236 ( struct V_27 * V_27 , void * V_478 , T_3 V_479 )
{
return F_146 ( V_27 , V_146 , V_478 , V_479 , 0 ) ;
}
static int F_237 ( struct V_44 * V_44 , void * V_478 , T_3 V_479 )
{
return F_238 ( V_44 , V_166 , V_478 , V_479 , 0 ) ;
}
static int F_239 ( struct V_27 * V_27 , void * * V_478 , T_3 * V_479 )
{
int V_142 = 0 ;
V_142 = F_83 ( V_27 , V_146 , V_478 , true ) ;
if ( V_142 < 0 )
return V_142 ;
* V_479 = V_142 ;
return 0 ;
}
static T_11 void F_240 ( void )
{
F_19 ( & V_441 . V_60 ) ;
F_19 ( & V_101 . V_60 ) ;
F_19 ( & V_97 . V_60 ) ;
F_19 ( & V_175 . V_60 ) ;
F_19 ( & V_177 . V_60 ) ;
F_19 ( & V_176 . V_60 ) ;
F_21 ( & V_441 . V_59 ) ;
F_21 ( & V_101 . V_59 ) ;
F_21 ( & V_175 . V_59 ) ;
F_21 ( & V_97 . V_59 ) ;
F_21 ( & V_177 . V_59 ) ;
F_21 ( & V_176 . V_59 ) ;
F_241 ( & V_441 ) ;
F_241 ( & V_101 ) ;
F_241 ( & V_175 ) ;
F_241 ( & V_97 ) ;
F_241 ( & V_177 ) ;
F_241 ( & V_176 ) ;
}
static T_11 int F_242 ( void )
{
struct V_39 * V_39 ;
struct V_20 * V_21 ;
if ( ! F_243 ( & V_480 ) )
return 0 ;
V_481 = 1 ;
V_52 = F_244 ( V_28 , 0 ) ;
if ( ! V_52 )
return - V_67 ;
V_21 = F_20 ( & V_97 , & V_97 ,
V_51 ) ;
if ( V_21 == NULL ) {
F_245 ( V_52 ) ;
return - V_67 ;
}
F_147 ( V_482 L_27 ) ;
V_39 = (struct V_39 * ) V_23 -> V_39 ;
V_39 -> V_40 = V_21 ;
F_240 () ;
if ( F_246 ( & V_480 ) )
F_247 ( L_28 ) ;
return 0 ;
}

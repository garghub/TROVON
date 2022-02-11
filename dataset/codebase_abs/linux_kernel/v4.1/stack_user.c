static inline void F_1 ( struct V_1 * V_1 ,
int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
V_4 -> V_6 = V_2 ;
}
static inline int F_2 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
return V_4 -> V_6 ;
}
static struct V_7 * F_3 ( const char * V_8 )
{
T_1 V_9 = strlen ( V_8 ) ;
struct V_7 * V_10 ;
F_4 ( ! F_5 ( & V_11 ) ) ;
F_6 (c, &ocfs2_live_connection_list, oc_list) {
if ( ( V_10 -> V_12 -> V_13 == V_9 ) &&
! strncmp ( V_10 -> V_12 -> V_14 , V_8 , V_9 ) )
return V_10 ;
}
return NULL ;
}
static int F_7 ( struct V_15 * V_16 ,
struct V_7 * V_10 )
{
int V_17 = 0 ;
F_8 ( & V_11 ) ;
V_10 -> V_12 = V_16 ;
if ( ( V_10 -> V_18 == V_19 ) || F_9 ( & V_20 ) )
F_10 ( & V_10 -> V_21 , & V_22 ) ;
else {
F_11 ( V_23
L_1 ) ;
V_17 = - V_24 ;
}
F_12 ( & V_11 ) ;
return V_17 ;
}
static void F_13 ( struct V_7 * V_10 )
{
F_8 ( & V_11 ) ;
F_14 ( & V_10 -> V_21 ) ;
V_10 -> V_12 = NULL ;
F_12 ( & V_11 ) ;
F_15 ( V_10 ) ;
}
static int F_16 ( void * V_25 , T_1 V_26 ,
const char T_2 * V_27 , T_1 V_28 )
{
if ( ( V_28 != V_26 ) ||
( V_28 > sizeof( union V_29 ) ) )
return - V_30 ;
if ( F_17 ( V_25 , V_27 , V_26 ) )
return - V_31 ;
return 0 ;
}
static T_3 F_18 ( struct V_1 * V_1 ,
const char T_2 * V_27 ,
T_1 V_28 )
{
T_3 V_32 ;
char V_33 [ V_34 ] ;
V_32 = F_16 ( V_33 , V_34 ,
V_27 , V_28 ) ;
if ( V_32 )
return V_32 ;
if ( strncmp ( V_33 , V_35 , V_34 ) )
return - V_30 ;
F_1 ( V_1 ,
V_36 ) ;
return V_28 ;
}
static void F_19 ( const char * V_37 ,
int V_38 )
{
struct V_7 * V_10 ;
F_8 ( & V_11 ) ;
V_10 = F_3 ( V_37 ) ;
if ( V_10 ) {
F_4 ( V_10 -> V_12 == NULL ) ;
V_10 -> V_12 -> V_39 ( V_38 ,
V_10 -> V_12 -> V_40 ) ;
}
F_12 ( & V_11 ) ;
}
static int F_20 ( struct V_1 * V_1 )
{
int V_17 = 0 ;
int V_41 = 1 ;
struct V_3 * V_4 = V_1 -> V_5 ;
F_4 ( V_4 -> V_6 != V_36 ) ;
F_8 ( & V_11 ) ;
if ( V_4 -> V_42 < 0 ) {
V_41 = 0 ;
} else if ( ( V_43 >= 0 ) &&
( V_43 != V_4 -> V_42 ) ) {
V_17 = - V_30 ;
goto V_44;
}
if ( ! V_4 -> V_45 . V_46 ) {
V_41 = 0 ;
} else if ( ! F_21 ( & V_22 ) &&
( ( V_47 . V_46 != V_4 -> V_45 . V_46 ) ||
( V_47 . V_48 != V_4 -> V_45 . V_48 ) ) ) {
V_17 = - V_30 ;
goto V_44;
}
if ( V_41 ) {
V_43 = V_4 -> V_42 ;
V_47 . V_46 = V_4 -> V_45 . V_46 ;
V_47 . V_48 = V_4 -> V_45 . V_48 ;
}
V_44:
F_12 ( & V_11 ) ;
if ( ! V_17 && V_41 ) {
F_22 ( & V_20 ) ;
F_1 ( V_1 ,
V_49 ) ;
}
return V_17 ;
}
static int F_23 ( void )
{
int V_17 ;
F_8 ( & V_11 ) ;
if ( V_43 < 0 )
V_17 = - V_30 ;
else
V_17 = V_43 ;
F_12 ( & V_11 ) ;
return V_17 ;
}
static int F_24 ( struct V_1 * V_1 ,
struct V_50 * V_51 )
{
long V_38 ;
char * V_52 = NULL ;
struct V_3 * V_4 = V_1 -> V_5 ;
if ( F_2 ( V_1 ) !=
V_36 )
return - V_30 ;
if ( strncmp ( V_51 -> V_53 , V_54 ,
V_55 ) )
return - V_30 ;
if ( ( V_51 -> V_56 != ' ' ) || ( V_51 -> V_57 != '\n' ) )
return - V_30 ;
V_51 -> V_56 = V_51 -> V_57 = '\0' ;
V_38 = F_25 ( V_51 -> V_58 , & V_52 , 16 ) ;
if ( ! V_52 || * V_52 )
return - V_30 ;
if ( ( V_38 == V_59 ) || ( V_38 == V_60 ) ||
( V_38 > V_61 ) || ( V_38 < 0 ) )
return - V_62 ;
V_4 -> V_42 = V_38 ;
return F_20 ( V_1 ) ;
}
static int F_26 ( struct V_1 * V_1 ,
struct V_63 * V_51 )
{
long V_64 , V_65 ;
char * V_52 = NULL ;
struct V_3 * V_4 = V_1 -> V_5 ;
struct V_66 * V_67 =
& V_68 . V_69 ;
if ( F_2 ( V_1 ) !=
V_36 )
return - V_30 ;
if ( strncmp ( V_51 -> V_53 , V_70 ,
V_55 ) )
return - V_30 ;
if ( ( V_51 -> V_71 != ' ' ) || ( V_51 -> V_72 != ' ' ) ||
( V_51 -> V_57 != '\n' ) )
return - V_30 ;
V_51 -> V_71 = V_51 -> V_72 = V_51 -> V_57 = '\0' ;
V_64 = F_25 ( V_51 -> V_64 , & V_52 , 16 ) ;
if ( ! V_52 || * V_52 )
return - V_30 ;
V_65 = F_25 ( V_51 -> V_65 , & V_52 , 16 ) ;
if ( ! V_52 || * V_52 )
return - V_30 ;
if ( ( V_64 == V_59 ) || ( V_64 == V_60 ) ||
( V_64 > ( V_73 ) - 1 ) || ( V_64 < 1 ) )
return - V_62 ;
if ( ( V_65 == V_59 ) || ( V_65 == V_60 ) ||
( V_65 > ( V_73 ) - 1 ) || ( V_65 < 0 ) )
return - V_62 ;
if ( ( V_64 != V_67 -> V_46 ) ||
( V_65 > V_67 -> V_48 ) )
return - V_30 ;
V_4 -> V_45 . V_46 = V_64 ;
V_4 -> V_45 . V_48 = V_65 ;
return F_20 ( V_1 ) ;
}
static int F_27 ( struct V_1 * V_1 ,
struct V_74 * V_51 )
{
long V_38 ;
char * V_4 = NULL ;
if ( F_2 ( V_1 ) !=
V_49 )
return - V_30 ;
if ( strncmp ( V_51 -> V_53 , V_75 ,
V_55 ) )
return - V_30 ;
if ( ( V_51 -> V_71 != ' ' ) || ( V_51 -> V_72 != ' ' ) ||
( V_51 -> V_57 != '\n' ) )
return - V_30 ;
V_51 -> V_71 = V_51 -> V_72 = V_51 -> V_57 = '\0' ;
V_38 = F_25 ( V_51 -> V_58 , & V_4 , 16 ) ;
if ( ! V_4 || * V_4 )
return - V_30 ;
if ( ( V_38 == V_59 ) || ( V_38 == V_60 ) ||
( V_38 > V_61 ) || ( V_38 < 0 ) )
return - V_62 ;
F_19 ( V_51 -> V_37 , V_38 ) ;
return 0 ;
}
static T_3 V_29 ( struct V_1 * V_1 ,
const char T_2 * V_27 ,
T_1 V_28 )
{
T_3 V_32 ;
union V_29 V_51 ;
F_28 ( F_29 ( struct V_74 , V_37 ) !=
( sizeof( V_51 . V_76 . V_53 ) + sizeof( V_51 . V_76 . V_71 ) ) ) ;
memset ( & V_51 , 0 , sizeof( union V_29 ) ) ;
V_32 = F_16 ( & V_51 , V_28 , V_27 , V_28 ) ;
if ( V_32 )
goto V_77;
if ( ( V_28 == V_78 ) &&
! strncmp ( V_51 . V_53 , V_54 ,
V_55 ) )
V_32 = F_24 ( V_1 , & V_51 . V_79 ) ;
else if ( ( V_28 == V_80 ) &&
! strncmp ( V_51 . V_53 , V_70 ,
V_55 ) )
V_32 = F_26 ( V_1 , & V_51 . V_81 ) ;
else if ( ( V_28 == V_82 ) &&
! strncmp ( V_51 . V_53 , V_75 ,
V_55 ) )
V_32 = F_27 ( V_1 , & V_51 . V_76 ) ;
else
V_32 = - V_30 ;
V_77:
return V_32 ? V_32 : V_28 ;
}
static T_3 F_30 ( struct V_1 * V_1 ,
const char T_2 * V_27 ,
T_1 V_28 ,
T_4 * V_83 )
{
T_3 V_32 ;
switch ( F_2 ( V_1 ) ) {
case V_84 :
V_32 = - V_30 ;
break;
case V_85 :
V_32 = F_18 ( V_1 , V_27 ,
V_28 ) ;
break;
case V_36 :
case V_49 :
V_32 = V_29 ( V_1 , V_27 , V_28 ) ;
break;
default:
F_31 () ;
V_32 = - V_86 ;
break;
}
return V_32 ;
}
static T_3 F_32 ( struct V_1 * V_1 ,
char T_2 * V_27 ,
T_1 V_28 ,
T_4 * V_83 )
{
T_3 V_32 ;
V_32 = F_33 ( V_27 , V_28 , V_83 ,
V_35 , V_34 ) ;
if ( V_32 > 0 && * V_83 >= V_34 )
F_1 ( V_1 ,
V_85 ) ;
return V_32 ;
}
static int F_34 ( struct V_87 * V_87 , struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
F_8 ( & V_11 ) ;
if ( F_2 ( V_1 ) !=
V_49 )
goto V_77;
if ( F_35 ( & V_20 ) ) {
if ( ! F_21 ( & V_22 ) ) {
F_11 ( V_23
L_2
L_3
L_4 ) ;
F_36 () ;
}
V_43 = - 1 ;
V_47 . V_46 = 0 ;
V_47 . V_48 = 0 ;
}
V_77:
F_14 ( & V_4 -> V_88 ) ;
V_1 -> V_5 = NULL ;
F_12 ( & V_11 ) ;
F_15 ( V_4 ) ;
return 0 ;
}
static int F_37 ( struct V_87 * V_87 , struct V_1 * V_1 )
{
struct V_3 * V_4 ;
V_4 = F_38 ( sizeof( struct V_3 ) , V_89 ) ;
if ( ! V_4 )
return - V_90 ;
V_4 -> V_42 = - 1 ;
F_8 ( & V_11 ) ;
V_1 -> V_5 = V_4 ;
F_10 ( & V_4 -> V_88 , & V_91 ) ;
F_12 ( & V_11 ) ;
return 0 ;
}
static int F_39 ( void )
{
int V_17 ;
F_40 ( & V_20 , 0 ) ;
V_17 = F_41 ( & V_92 ) ;
if ( V_17 )
F_11 ( V_23
L_5
L_6 ,
- V_17 ) ;
return V_17 ;
}
static void F_42 ( void )
{
int V_17 ;
V_17 = F_43 ( & V_92 ) ;
if ( V_17 )
F_11 ( V_23
L_7
L_6 ,
- V_17 ) ;
}
static void F_44 ( void * V_93 )
{
struct V_94 * V_95 = V_93 ;
int V_96 = V_95 -> V_97 . V_98 ;
if ( V_96 == - V_99 || V_96 == - V_100 )
V_95 -> V_101 -> V_102 -> V_103 ( V_95 , 0 ) ;
else
V_95 -> V_101 -> V_102 -> V_104 ( V_95 ) ;
}
static void F_45 ( void * V_93 , int V_105 )
{
struct V_94 * V_95 = V_93 ;
V_95 -> V_101 -> V_102 -> V_106 ( V_95 , V_105 ) ;
}
static int F_46 ( struct V_15 * V_16 ,
int V_107 ,
struct V_94 * V_95 ,
T_5 V_108 ,
void * V_8 ,
unsigned int V_109 )
{
int V_32 ;
if ( ! V_95 -> V_97 . V_110 )
V_95 -> V_97 . V_110 = ( char * ) V_95 +
sizeof( struct V_111 ) ;
V_32 = F_47 ( V_16 -> V_112 , V_107 , & V_95 -> V_97 ,
V_108 | V_113 , V_8 , V_109 , 0 ,
F_44 , V_95 ,
F_45 ) ;
return V_32 ;
}
static int F_48 ( struct V_15 * V_16 ,
struct V_94 * V_95 ,
T_5 V_108 )
{
int V_32 ;
V_32 = F_49 ( V_16 -> V_112 , V_95 -> V_97 . V_114 ,
V_108 , & V_95 -> V_97 , V_95 ) ;
return V_32 ;
}
static int F_50 ( struct V_94 * V_95 )
{
return V_95 -> V_97 . V_98 ;
}
static int F_51 ( struct V_94 * V_95 )
{
int V_115 = V_95 -> V_97 . V_116 & V_117 ;
return ! V_115 ;
}
static void * F_52 ( struct V_94 * V_95 )
{
if ( ! V_95 -> V_97 . V_110 )
V_95 -> V_97 . V_110 = ( char * ) V_95 +
sizeof( struct V_111 ) ;
return ( void * ) ( V_95 -> V_97 . V_110 ) ;
}
static void F_53 ( struct V_94 * V_95 )
{
}
static int F_54 ( struct V_15 * V_16 ,
T_6 V_118 ,
struct V_1 * V_1 ,
int V_119 ,
struct V_120 * V_121 )
{
if ( V_119 == V_122 ) {
V_119 = V_123 ;
V_121 -> V_124 = V_125 ;
}
if ( F_55 ( V_119 ) )
return F_56 ( V_16 -> V_112 , V_118 , V_1 , V_121 ) ;
else if ( V_121 -> V_124 == V_125 )
return F_57 ( V_16 -> V_112 , V_118 , V_1 , V_121 ) ;
else
return F_58 ( V_16 -> V_112 , V_118 , V_1 , V_119 , V_121 ) ;
}
static int F_59 ( struct V_66 * V_126 ,
struct V_66 * V_127 )
{
if ( V_126 -> V_46 != V_127 -> V_46 )
return 1 ;
if ( V_126 -> V_48 > V_127 -> V_48 )
return 1 ;
if ( V_126 -> V_48 < V_127 -> V_48 )
V_127 -> V_48 = V_126 -> V_48 ;
return 0 ;
}
static void F_60 ( char * V_128 , struct V_66 * V_129 )
{
struct V_66 * V_130 =
(struct V_66 * ) V_128 ;
V_129 -> V_46 = V_130 -> V_46 ;
V_129 -> V_48 = V_130 -> V_48 ;
}
static void F_61 ( struct V_66 * V_129 , char * V_128 )
{
struct V_66 * V_130 =
(struct V_66 * ) V_128 ;
V_130 -> V_46 = V_129 -> V_46 ;
V_130 -> V_48 = V_129 -> V_48 ;
}
static void F_62 ( void * V_131 )
{
struct V_15 * V_16 = V_131 ;
struct V_7 * V_132 = V_16 -> V_133 ;
F_63 ( & V_132 -> V_134 ) ;
}
static int F_64 ( struct V_15 * V_16 ,
struct V_111 * V_95 , char * V_8 )
{
int error ;
struct V_7 * V_132 = V_16 -> V_133 ;
error = F_49 ( V_16 -> V_112 , V_95 -> V_114 , 0 , V_95 , V_16 ) ;
if ( error ) {
F_11 ( V_23 L_8 ,
V_8 , V_95 -> V_114 , error ) ;
return error ;
}
F_65 ( & V_132 -> V_134 ) ;
if ( V_95 -> V_98 != - V_99 ) {
F_11 ( V_23 L_9 ,
V_8 , V_95 -> V_114 , V_95 -> V_98 ) ;
return - 1 ;
}
return 0 ;
}
static int F_66 ( struct V_15 * V_16 ,
int V_107 , T_7 V_108 ,
struct V_111 * V_95 , char * V_8 )
{
int error , V_96 ;
struct V_7 * V_132 = V_16 -> V_133 ;
error = F_47 ( V_16 -> V_112 , V_107 , V_95 , V_108 ,
V_8 , strlen ( V_8 ) ,
0 , F_62 , V_16 , NULL ) ;
if ( error ) {
F_11 ( V_23 L_10 ,
V_8 , V_95 -> V_114 , V_108 , V_107 , error ) ;
return error ;
}
F_65 ( & V_132 -> V_134 ) ;
V_96 = V_95 -> V_98 ;
if ( V_96 && V_96 != - V_135 ) {
F_11 ( V_23 L_11 ,
V_8 , V_95 -> V_114 , V_108 , V_107 , V_96 ) ;
}
return V_96 ;
}
static int F_67 ( struct V_15 * V_16 , int V_107 ,
int V_108 )
{
struct V_7 * V_132 = V_16 -> V_133 ;
return F_66 ( V_16 , V_107 , V_108 ,
& V_132 -> V_136 , V_137 ) ;
}
static int F_68 ( struct V_15 * V_16 )
{
struct V_7 * V_132 = V_16 -> V_133 ;
return F_64 ( V_16 , & V_132 -> V_136 , V_137 ) ;
}
static int F_69 ( struct V_15 * V_16 )
{
int V_32 ;
struct V_7 * V_132 = V_16 -> V_133 ;
struct V_66 V_130 ;
V_47 . V_46 =
V_68 . V_69 . V_46 ;
V_47 . V_48 =
V_68 . V_69 . V_48 ;
V_132 -> V_136 . V_110 = V_132 -> V_138 ;
V_32 = F_67 ( V_16 , V_139 ,
V_140 | V_141 ) ;
if ( ! V_32 ) {
V_16 -> V_142 . V_46 = V_47 . V_46 ;
V_16 -> V_142 . V_48 = V_47 . V_48 ;
F_61 ( & V_47 , V_132 -> V_138 ) ;
F_67 ( V_16 , V_143 , V_144 | V_140 ) ;
} else if ( V_32 == - V_135 ) {
V_32 = F_67 ( V_16 , V_143 , V_140 ) ;
if ( V_32 )
goto V_77;
F_60 ( V_132 -> V_138 , & V_130 ) ;
if ( ( V_130 . V_46 != V_47 . V_46 ) ||
( V_130 . V_48 > V_47 . V_48 ) ) {
V_32 = - V_30 ;
goto V_77;
}
V_16 -> V_142 . V_46 = V_130 . V_46 ;
V_16 -> V_142 . V_48 = V_130 . V_48 ;
}
V_77:
return V_32 ;
}
static void F_70 ( void * V_131 )
{
}
static void F_71 ( void * V_131 , struct V_145 * V_146 )
{
struct V_15 * V_16 = V_131 ;
F_11 ( V_147 L_12 ,
V_146 -> V_148 , V_146 -> V_146 ) ;
V_16 -> V_39 ( V_146 -> V_148 , V_16 -> V_40 ) ;
}
static void F_72 ( void * V_131 , struct V_145 * V_149 ,
int V_150 , int V_151 ,
T_7 V_152 )
{
struct V_15 * V_16 = V_131 ;
struct V_7 * V_132 = V_16 -> V_133 ;
int V_153 ;
for ( V_153 = 0 ; V_153 < V_150 ; V_153 ++ )
if ( V_149 [ V_153 ] . V_146 == V_151 ) {
F_40 ( & V_132 -> V_154 , V_149 [ V_153 ] . V_148 ) ;
break;
}
V_132 -> V_155 = V_151 ;
F_73 ( & V_132 -> V_156 ) ;
}
static int F_74 ( struct V_15 * V_16 )
{
F_68 ( V_16 ) ;
F_75 ( V_16 -> V_112 , 2 ) ;
V_16 -> V_112 = NULL ;
F_13 ( V_16 -> V_133 ) ;
V_16 -> V_133 = NULL ;
return 0 ;
}
static int F_76 ( struct V_15 * V_16 )
{
T_8 * V_157 ;
struct V_7 * V_132 ;
int V_17 , V_158 ;
F_4 ( V_16 == NULL ) ;
V_132 = F_38 ( sizeof( struct V_7 ) , V_89 ) ;
if ( ! V_132 )
return - V_90 ;
F_77 ( & V_132 -> V_156 ) ;
F_78 ( & V_132 -> V_134 ) ;
F_40 ( & V_132 -> V_154 , 0 ) ;
V_16 -> V_133 = V_132 ;
V_132 -> V_18 = V_19 ;
V_17 = F_79 ( V_16 -> V_14 , V_16 -> V_159 ,
V_160 , V_161 ,
& V_162 , V_16 , & V_158 , & V_157 ) ;
if ( V_17 )
goto V_77;
if ( V_158 == - V_163 ) {
V_132 -> V_18 = V_164 ;
F_11 ( V_165 L_13
L_14
L_15 ) ;
} else if ( V_158 ) {
V_17 = V_158 ;
goto V_77;
}
V_16 -> V_112 = V_157 ;
V_17 = F_7 ( V_16 , V_132 ) ;
if ( V_17 )
goto V_77;
if ( V_132 -> V_18 == V_19 ) {
V_17 = F_69 ( V_16 ) ;
if ( V_17 ) {
F_11 ( V_23 L_16
L_17 ) ;
F_74 ( V_16 ) ;
goto V_77;
}
F_80 ( V_132 -> V_156 , ( F_9 ( & V_132 -> V_154 ) > 0 ) ) ;
}
if ( F_59 ( & V_47 , & V_16 -> V_142 ) ) {
F_11 ( V_23
L_18
L_19 ,
V_16 -> V_142 . V_46 , V_16 -> V_142 . V_48 ,
V_47 . V_46 , V_47 . V_48 ) ;
V_17 = - V_166 ;
F_13 ( V_132 ) ;
V_132 = NULL ;
}
V_77:
if ( V_17 )
F_15 ( V_132 ) ;
return V_17 ;
}
static int F_81 ( struct V_15 * V_16 ,
unsigned int * V_167 )
{
int V_17 ;
struct V_7 * V_132 = V_16 -> V_133 ;
if ( V_132 -> V_18 == V_164 )
V_17 = F_23 () ;
else if ( V_132 -> V_18 == V_19 )
V_17 = F_9 ( & V_132 -> V_154 ) ;
else
V_17 = - V_30 ;
if ( V_17 < 0 )
return V_17 ;
* V_167 = V_17 ;
return 0 ;
}
static int T_9 F_82 ( void )
{
int V_17 ;
V_17 = F_39 () ;
if ( ! V_17 ) {
V_17 = F_83 ( & V_68 ) ;
if ( V_17 )
F_42 () ;
}
return V_17 ;
}
static void T_10 F_84 ( void )
{
F_85 ( & V_68 ) ;
F_42 () ;
}

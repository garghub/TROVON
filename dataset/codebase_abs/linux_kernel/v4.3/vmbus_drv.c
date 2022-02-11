static void F_1 ( struct V_1 * V_2 )
{
static bool V_3 ;
if ( V_3 )
return;
V_3 = true ;
F_2 ( V_4 , V_2 -> V_5 ) ;
F_2 ( V_6 , V_2 -> V_7 ) ;
F_2 ( V_8 , V_2 -> V_9 ) ;
F_2 ( V_10 , V_2 -> V_11 ) ;
F_2 ( V_12 , V_2 -> V_13 ) ;
F_2 ( V_14 , V_15 ) ;
}
static int F_3 ( struct V_16 * V_17 , unsigned long V_18 ,
void * args )
{
struct V_1 * V_2 ;
V_2 = F_4 () ;
F_1 ( V_2 ) ;
return V_19 ;
}
static int F_5 ( struct V_16 * V_17 , unsigned long V_18 ,
void * args )
{
struct V_20 * V_21 = (struct V_20 * ) args ;
struct V_1 * V_2 = V_21 -> V_2 ;
F_1 ( V_2 ) ;
return V_19 ;
}
static int F_6 ( void )
{
if ( V_22 == NULL )
return - V_23 ;
return 0 ;
}
static void F_7 ( struct V_24 * V_25 , char * V_26 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 += 2 )
sprintf ( & V_26 [ V_27 ] , L_1 , V_25 -> V_29 . V_30 [ V_27 / 2 ] ) ;
}
static T_1 F_8 ( struct V_31 * V_32 )
{
return ( T_1 ) V_32 -> V_33 . V_34 / 32 ;
}
static T_1 F_9 ( struct V_31 * V_32 )
{
return ( T_1 ) V_32 -> V_33 . V_34 % 32 ;
}
static T_2 F_10 ( struct V_31 * V_32 ,
struct V_35 * V_36 )
{
T_1 V_37 = F_8 ( V_32 ) ;
return V_36 -> V_38 [ V_37 ] . V_39 ;
}
static T_2 F_11 ( struct V_31 * V_32 ,
struct V_35 * V_36 )
{
T_1 V_37 = F_8 ( V_32 ) ;
T_1 V_40 = F_9 ( V_32 ) ;
return V_36 -> V_41 [ V_37 ] [ V_40 ] ;
}
static T_2 F_12 ( struct V_31 * V_32 ,
struct V_35 * V_36 )
{
T_1 V_37 = F_8 ( V_32 ) ;
T_1 V_40 = F_9 ( V_32 ) ;
return V_36 -> V_42 [ V_37 ] [ V_40 ] . V_43 . V_44 . V_45 ;
}
static T_3 F_13 ( struct V_46 * V_47 , struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 , V_25 -> V_32 -> V_33 . V_51 ) ;
}
static T_3 F_15 ( struct V_46 * V_47 , struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 , V_25 -> V_32 -> V_52 ) ;
}
static T_3 F_16 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 , V_25 -> V_32 -> V_33 . V_34 ) ;
}
static T_3 F_17 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_3 ,
V_25 -> V_32 -> V_33 . V_53 . V_54 . V_30 ) ;
}
static T_3 F_18 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_3 ,
V_25 -> V_32 -> V_33 . V_53 . V_55 . V_30 ) ;
}
static T_3 F_19 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
char V_26 [ V_28 + 1 ] ;
F_7 ( V_25 , V_26 ) ;
return sprintf ( V_50 , L_4 , V_26 ) ;
}
static T_3 F_20 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_10 ( V_25 -> V_32 ,
V_56 . V_57 [ 1 ] ) ) ;
}
static T_3 F_21 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_10 ( V_25 -> V_32 ,
V_56 . V_57 [ 1 ] ) ) ;
}
static T_3 F_22 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_11 ( V_25 -> V_32 ,
V_56 . V_57 [ 0 ] ) ) ;
}
static T_3 F_23 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_11 ( V_25 -> V_32 ,
V_56 . V_57 [ 1 ] ) ) ;
}
static T_3 F_24 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_12 ( V_25 -> V_32 ,
V_56 . V_57 [ 0 ] ) ) ;
}
static T_3 F_25 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
if ( ! V_25 -> V_32 )
return - V_23 ;
return sprintf ( V_50 , L_2 ,
F_12 ( V_25 -> V_32 ,
V_56 . V_57 [ 1 ] ) ) ;
}
static T_3 F_26 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_59 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_59 , & V_59 ) ;
return sprintf ( V_50 , L_2 , V_59 . V_60 ) ;
}
static T_3 F_28 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_59 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_59 , & V_59 ) ;
return sprintf ( V_50 , L_2 , V_59 . V_61 ) ;
}
static T_3 F_29 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_59 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_59 , & V_59 ) ;
return sprintf ( V_50 , L_2 , V_59 . V_62 ) ;
}
static T_3 F_30 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_59 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_59 , & V_59 ) ;
return sprintf ( V_50 , L_2 , V_59 . V_63 ) ;
}
static T_3 F_31 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_59 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_59 , & V_59 ) ;
return sprintf ( V_50 , L_2 , V_59 . V_64 ) ;
}
static T_3 F_32 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_65 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_65 , & V_65 ) ;
return sprintf ( V_50 , L_2 , V_65 . V_60 ) ;
}
static T_3 F_33 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_65 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_65 , & V_65 ) ;
return sprintf ( V_50 , L_2 , V_65 . V_61 ) ;
}
static T_3 F_34 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_65 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_65 , & V_65 ) ;
return sprintf ( V_50 , L_2 , V_65 . V_62 ) ;
}
static T_3 F_35 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_65 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_65 , & V_65 ) ;
return sprintf ( V_50 , L_2 , V_65 . V_63 ) ;
}
static T_3 F_36 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_58 V_65 ;
if ( ! V_25 -> V_32 )
return - V_23 ;
F_27 ( & V_25 -> V_32 -> V_65 , & V_65 ) ;
return sprintf ( V_50 , L_2 , V_65 . V_64 ) ;
}
static T_3 F_37 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
struct V_31 * V_32 = V_25 -> V_32 , * V_66 ;
unsigned long V_67 ;
int V_68 = V_69 , V_70 , V_71 ;
struct V_72 * V_73 ;
if ( ! V_32 )
return - V_23 ;
V_71 = snprintf ( V_50 , V_68 , L_5 ,
V_32 -> V_33 . V_51 , V_32 -> V_74 ) ;
F_38 ( & V_32 -> V_75 , V_67 ) ;
F_39 (cur, &channel->sc_list) {
if ( V_71 >= V_68 - 1 )
break;
V_66 = F_40 ( V_73 , struct V_31 , V_76 ) ;
V_70 = F_41 ( V_50 + V_71 ,
V_68 - V_71 ,
L_5 ,
V_66 -> V_33 . V_51 ,
V_66 -> V_74 ) ;
V_71 += V_70 ;
}
F_42 ( & V_32 -> V_75 , V_67 ) ;
return V_71 ;
}
static int F_43 ( struct V_46 * V_46 , struct V_77 * V_78 )
{
struct V_24 * V_47 = F_14 ( V_46 ) ;
int V_79 ;
char V_26 [ V_28 + 1 ] ;
F_7 ( V_47 , V_26 ) ;
V_79 = F_44 ( V_78 , L_6 , V_26 ) ;
return V_79 ;
}
static inline bool F_45 ( const T_4 * V_80 )
{
if ( memcmp ( V_80 , & V_81 , sizeof( V_82 ) ) )
return false ;
return true ;
}
static const struct V_83 * F_46 (
const struct V_83 * V_45 ,
const T_4 * V_80 )
{
for (; ! F_45 ( V_45 -> V_80 ) ; V_45 ++ )
if ( ! memcmp ( & V_45 -> V_80 , V_80 , sizeof( V_82 ) ) )
return V_45 ;
return NULL ;
}
static int F_47 ( struct V_46 * V_46 , struct V_84 * V_85 )
{
struct V_86 * V_87 = F_48 ( V_85 ) ;
struct V_24 * V_25 = F_14 ( V_46 ) ;
if ( F_46 ( V_87 -> V_88 , V_25 -> V_29 . V_30 ) )
return 1 ;
return 0 ;
}
static int F_49 ( struct V_46 * V_89 )
{
int V_79 = 0 ;
struct V_86 * V_87 =
F_48 ( V_89 -> V_85 ) ;
struct V_24 * V_47 = F_14 ( V_89 ) ;
const struct V_83 * V_90 ;
V_90 = F_46 ( V_87 -> V_88 , V_47 -> V_29 . V_30 ) ;
if ( V_87 -> V_91 ) {
V_79 = V_87 -> V_91 ( V_47 , V_90 ) ;
if ( V_79 != 0 )
F_50 ( L_7 ,
F_51 ( V_89 ) , V_79 ) ;
} else {
F_50 ( L_8 ,
F_51 ( V_89 ) ) ;
V_79 = - V_23 ;
}
return V_79 ;
}
static int F_52 ( struct V_46 * V_89 )
{
struct V_86 * V_87 ;
struct V_24 * V_47 = F_14 ( V_89 ) ;
T_2 V_92 = V_47 -> V_32 -> V_33 . V_51 ;
if ( V_89 -> V_85 ) {
V_87 = F_48 ( V_89 -> V_85 ) ;
if ( V_87 -> remove )
V_87 -> remove ( V_47 ) ;
else {
F_53 ( V_47 -> V_32 , V_92 ) ;
F_50 ( L_9 ,
F_51 ( V_89 ) ) ;
}
} else {
F_53 ( V_47 -> V_32 , V_92 ) ;
}
return 0 ;
}
static void F_54 ( struct V_46 * V_89 )
{
struct V_86 * V_87 ;
struct V_24 * V_47 = F_14 ( V_89 ) ;
if ( ! V_89 -> V_85 )
return;
V_87 = F_48 ( V_89 -> V_85 ) ;
if ( V_87 -> V_93 )
V_87 -> V_93 ( V_47 ) ;
return;
}
static void F_55 ( struct V_46 * V_46 )
{
struct V_24 * V_25 = F_14 ( V_46 ) ;
F_56 ( V_25 ) ;
}
static void F_57 ( struct V_94 * V_95 )
{
struct V_96 * V_97 ;
if ( V_56 . V_98 == V_99 )
return;
V_97 = F_58 ( V_95 , struct V_96 ,
V_95 ) ;
F_59 ( & V_97 -> V_100 ) ;
F_56 ( V_97 ) ;
}
static void F_60 ( struct V_101 * V_100 , int V_102 )
{
struct V_103 * V_47 = V_104 . V_105 [ V_102 ] ;
if ( V_47 -> V_106 )
V_47 -> V_106 ( V_47 ) ;
V_100 -> V_107 . V_108 = V_109 ;
F_61 () ;
if ( V_100 -> V_107 . V_110 . V_111 ) {
F_2 ( V_112 , 0 ) ;
}
}
static void F_62 ( unsigned long V_113 )
{
int V_102 = F_63 () ;
void * V_114 = V_104 . V_115 [ V_102 ] ;
struct V_101 * V_100 = (struct V_101 * ) V_114 +
V_116 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
struct V_96 * V_97 ;
while ( 1 ) {
if ( V_100 -> V_107 . V_108 == V_109 )
break;
V_118 = (struct V_117 * ) V_100 -> V_44 . V_121 ;
if ( V_118 -> V_122 >= V_123 ) {
F_64 ( 1 , L_10 , V_118 -> V_122 ) ;
goto V_124;
}
V_120 = & V_125 [ V_118 -> V_122 ] ;
if ( V_120 -> V_126 == V_127 ) {
V_97 = F_65 ( sizeof( * V_97 ) , V_128 ) ;
if ( V_97 == NULL )
continue;
F_66 ( & V_97 -> V_95 , F_57 ) ;
memcpy ( & V_97 -> V_100 , V_100 , sizeof( * V_100 ) ) ;
F_67 ( V_56 . V_129 , & V_97 -> V_95 ) ;
} else
V_120 -> V_130 ( V_118 ) ;
V_124:
V_100 -> V_107 . V_108 = V_109 ;
F_61 () ;
if ( V_100 -> V_107 . V_110 . V_111 ) {
F_2 ( V_112 , 0 ) ;
}
}
}
static void F_68 ( void )
{
int V_102 = F_63 () ;
void * V_114 ;
struct V_101 * V_100 ;
union V_131 * V_132 ;
bool V_133 = false ;
V_114 = V_104 . V_134 [ V_102 ] ;
if ( V_114 == NULL )
return;
V_132 = (union V_131 * ) V_114 +
V_116 ;
if ( ( V_135 == V_136 ) ||
( V_135 == V_137 ) ) {
if ( F_69 ( 0 ,
( unsigned long * ) & V_132 -> V_138 [ 0 ] ) ) {
V_133 = true ;
}
} else {
V_133 = true ;
}
if ( V_133 )
F_70 ( V_104 . V_139 [ V_102 ] ) ;
V_114 = V_104 . V_115 [ V_102 ] ;
V_100 = (struct V_101 * ) V_114 + V_116 ;
if ( V_100 -> V_107 . V_108 != V_109 ) {
if ( V_100 -> V_107 . V_108 == V_140 )
F_60 ( V_100 , V_102 ) ;
else
F_70 ( & V_141 ) ;
}
}
static int F_71 ( int V_142 )
{
int V_79 ;
V_79 = F_72 () ;
if ( V_79 != 0 ) {
F_50 ( L_11 , V_79 ) ;
return V_79 ;
}
F_73 ( & V_141 , F_62 , 0 ) ;
V_79 = F_74 ( & V_143 ) ;
if ( V_79 )
goto V_144;
F_75 ( F_68 ) ;
V_79 = F_76 () ;
if ( V_79 )
goto V_145;
F_77 ( V_146 , NULL , 1 ) ;
V_79 = F_78 () ;
if ( V_79 )
goto V_145;
if ( V_135 > V_137 )
F_79 () ;
if ( V_147 . V_148 & V_149 ) {
F_80 ( & V_150 ) ;
F_81 ( & V_151 ,
& V_152 ) ;
}
F_82 () ;
return 0 ;
V_145:
F_83 () ;
F_84 () ;
F_85 ( & V_143 ) ;
V_144:
F_86 () ;
return V_79 ;
}
int F_87 ( struct V_86 * V_86 , struct V_153 * V_154 , const char * V_155 )
{
int V_79 ;
F_88 ( L_12 , V_86 -> V_156 ) ;
V_79 = F_6 () ;
if ( V_79 < 0 )
return V_79 ;
V_86 -> V_85 . V_156 = V_86 -> V_156 ;
V_86 -> V_85 . V_154 = V_154 ;
V_86 -> V_85 . V_155 = V_155 ;
V_86 -> V_85 . V_157 = & V_143 ;
V_79 = F_89 ( & V_86 -> V_85 ) ;
return V_79 ;
}
void F_90 ( struct V_86 * V_86 )
{
F_88 ( L_13 , V_86 -> V_156 ) ;
if ( ! F_6 () )
F_91 ( & V_86 -> V_85 ) ;
}
struct V_24 * F_92 ( const V_82 * type ,
const V_82 * V_158 ,
struct V_31 * V_32 )
{
struct V_24 * V_159 ;
V_159 = F_93 ( sizeof( struct V_24 ) , V_160 ) ;
if ( ! V_159 ) {
F_50 ( L_14 ) ;
return NULL ;
}
V_159 -> V_32 = V_32 ;
memcpy ( & V_159 -> V_29 , type , sizeof( V_82 ) ) ;
memcpy ( & V_159 -> V_161 , V_158 ,
sizeof( V_82 ) ) ;
return V_159 ;
}
int F_94 ( struct V_24 * V_159 )
{
int V_79 = 0 ;
F_95 ( & V_159 -> V_46 , L_15 ,
V_159 -> V_32 -> V_45 ) ;
V_159 -> V_46 . V_157 = & V_143 ;
V_159 -> V_46 . V_162 = & V_22 -> V_47 ;
V_159 -> V_46 . V_163 = F_55 ;
V_79 = F_96 ( & V_159 -> V_46 ) ;
if ( V_79 )
F_50 ( L_16 ) ;
else
F_97 ( L_17 ,
F_51 ( & V_159 -> V_46 ) ) ;
return V_79 ;
}
void F_98 ( struct V_24 * V_164 )
{
F_97 ( L_18 ,
F_51 ( & V_164 -> V_46 ) ) ;
F_99 ( & V_164 -> V_46 ) ;
}
static T_5 F_100 ( struct V_165 * V_166 , void * V_97 )
{
T_6 V_167 = 0 ;
T_6 V_168 = 0 ;
struct V_169 * V_170 ;
struct V_169 * * V_171 = & V_172 ;
struct V_169 * * V_173 = NULL ;
switch ( V_166 -> type ) {
case V_174 :
V_142 = V_166 -> V_113 . V_142 . V_175 [ 0 ] ;
return V_176 ;
case V_177 :
V_167 = V_166 -> V_113 . V_178 . V_179 . V_180 ;
V_168 = V_166 -> V_113 . V_178 . V_179 . V_181 ;
break;
case V_182 :
V_167 = V_166 -> V_113 . V_183 . V_179 . V_180 ;
V_168 = V_166 -> V_113 . V_183 . V_179 . V_181 ;
break;
default:
return V_176 ;
}
if ( V_168 < 0x100000 )
return V_176 ;
V_170 = F_93 ( sizeof( * V_170 ) , V_128 ) ;
if ( ! V_170 )
return V_184 ;
if ( V_168 > V_185 && V_167 < V_185 )
V_168 = V_185 ;
V_170 -> V_156 = L_19 ;
V_170 -> V_67 = V_186 ;
V_170 -> V_167 = V_167 ;
V_170 -> V_168 = V_168 ;
do {
if ( ! * V_171 ) {
* V_171 = V_170 ;
break;
}
if ( ( * V_171 ) -> V_168 < V_170 -> V_167 ) {
V_170 -> V_187 = * V_171 ;
if ( V_173 )
( * V_173 ) -> V_187 = V_170 ;
* V_171 = V_170 ;
break;
}
V_173 = V_171 ;
V_171 = & ( * V_171 ) -> V_187 ;
} while ( 1 );
return V_176 ;
}
static int F_101 ( struct V_188 * V_46 )
{
struct V_169 * V_189 ;
struct V_169 * V_190 ;
if ( V_172 ) {
for ( V_189 = V_172 ; V_189 ; V_189 = V_190 ) {
V_190 = V_189 -> V_187 ;
F_56 ( V_189 ) ;
}
}
return 0 ;
}
int F_102 ( struct V_169 * * V_191 , struct V_24 * V_164 ,
T_6 V_192 , T_6 V_193 ,
T_6 V_194 , T_6 V_195 ,
bool V_196 )
{
struct V_169 * V_197 ;
T_6 V_198 , V_199 , V_167 , V_200 , V_201 ;
const char * V_202 = F_51 ( & V_164 -> V_46 ) ;
T_2 V_203 = V_204 . V_205 + ( V_204 . V_206 << 1 ) ;
int V_27 ;
for ( V_197 = V_172 ; V_197 ; V_197 = V_197 -> V_187 ) {
if ( ( V_197 -> V_167 >= V_193 ) || ( V_197 -> V_168 <= V_192 ) )
continue;
V_198 = V_197 -> V_167 ;
V_199 = V_197 -> V_168 ;
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
V_200 = V_198 ;
V_201 = V_199 ;
if ( V_196 || ( V_198 >= V_203 ) ||
( V_199 <= V_204 . V_205 ) ) {
V_27 ++ ;
} else {
if ( ( V_198 <= V_204 . V_205 ) &&
( V_199 >= V_204 . V_205 ) ) {
V_201 = V_204 . V_205 - 1 ;
V_198 = V_203 ;
} else {
V_198 = V_203 ;
continue;
}
}
V_167 = ( V_200 + V_195 - 1 ) & ~ ( V_195 - 1 ) ;
for (; V_167 + V_194 - 1 <= V_201 ; V_167 += V_195 ) {
* V_191 = F_103 ( V_167 , V_194 ,
V_202 ) ;
if ( * V_191 )
return 0 ;
}
}
}
return - V_207 ;
}
static int F_104 ( struct V_188 * V_46 )
{
T_5 V_208 ;
int V_209 = - V_23 ;
struct V_188 * V_210 ;
V_22 = V_46 ;
V_208 = F_105 ( V_46 -> V_211 , V_212 ,
F_100 , NULL ) ;
if ( F_106 ( V_208 ) )
goto V_213;
for ( V_210 = V_46 -> V_162 ; V_210 ; V_210 = V_210 -> V_162 ) {
V_208 = F_105 ( V_210 -> V_211 , V_212 ,
F_100 , NULL ) ;
if ( F_106 ( V_208 ) )
continue;
if ( V_172 )
break;
}
V_209 = 0 ;
V_213:
F_107 ( & V_214 ) ;
if ( V_209 )
F_101 ( V_46 ) ;
return V_209 ;
}
static void F_108 ( void )
{
int V_102 ;
F_109 () ;
F_110 () ;
F_111 (cpu)
F_112 ( V_102 , V_215 , NULL , 1 ) ;
F_86 () ;
}
static void F_113 ( struct V_1 * V_2 )
{
F_110 () ;
V_215 ( NULL ) ;
F_86 () ;
}
static int T_7 F_114 ( void )
{
int V_79 , V_216 ;
if ( V_217 != & V_218 )
return - V_23 ;
F_115 ( & V_214 ) ;
V_79 = F_116 ( & V_219 ) ;
if ( V_79 )
return V_79 ;
V_216 = F_117 ( & V_214 , 5 * V_220 ) ;
if ( V_216 == 0 ) {
V_79 = - V_221 ;
goto V_222;
}
if ( V_142 <= 0 ) {
V_79 = - V_23 ;
goto V_222;
}
V_79 = F_71 ( V_142 ) ;
if ( V_79 )
goto V_222;
F_118 ( F_108 ) ;
F_119 ( F_113 ) ;
return 0 ;
V_222:
F_120 ( & V_219 ) ;
V_22 = NULL ;
return V_79 ;
}
static void T_8 F_121 ( void )
{
int V_102 ;
F_122 () ;
F_123 () ;
V_56 . V_98 = V_99 ;
F_109 () ;
F_124 () ;
F_84 () ;
F_125 ( & V_141 ) ;
F_126 () ;
if ( V_147 . V_148 & V_149 ) {
F_127 ( & V_150 ) ;
F_128 ( & V_151 ,
& V_152 ) ;
}
F_85 ( & V_143 ) ;
F_86 () ;
F_111 (cpu) {
F_125 ( V_104 . V_139 [ V_102 ] ) ;
F_112 ( V_102 , V_215 , NULL , 1 ) ;
}
F_83 () ;
F_120 ( & V_219 ) ;
if ( V_135 > V_137 )
F_129 () ;
}

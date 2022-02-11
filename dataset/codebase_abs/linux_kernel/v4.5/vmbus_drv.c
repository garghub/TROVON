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
if ( F_46 ( * V_80 , V_81 ) )
return false ;
return true ;
}
static const struct V_82 * F_47 (
const struct V_82 * V_45 ,
const T_4 * V_80 )
{
for (; ! F_45 ( & V_45 -> V_80 ) ; V_45 ++ )
if ( ! F_46 ( V_45 -> V_80 , * V_80 ) )
return V_45 ;
return NULL ;
}
static int F_48 ( struct V_46 * V_46 , struct V_83 * V_84 )
{
struct V_85 * V_86 = F_49 ( V_84 ) ;
struct V_24 * V_25 = F_14 ( V_46 ) ;
if ( F_47 ( V_86 -> V_87 , & V_25 -> V_29 ) )
return 1 ;
return 0 ;
}
static int F_50 ( struct V_46 * V_88 )
{
int V_79 = 0 ;
struct V_85 * V_86 =
F_49 ( V_88 -> V_84 ) ;
struct V_24 * V_47 = F_14 ( V_88 ) ;
const struct V_82 * V_89 ;
V_89 = F_47 ( V_86 -> V_87 , & V_47 -> V_29 ) ;
if ( V_86 -> V_90 ) {
V_79 = V_86 -> V_90 ( V_47 , V_89 ) ;
if ( V_79 != 0 )
F_51 ( L_7 ,
F_52 ( V_88 ) , V_79 ) ;
} else {
F_51 ( L_8 ,
F_52 ( V_88 ) ) ;
V_79 = - V_23 ;
}
return V_79 ;
}
static int F_53 ( struct V_46 * V_88 )
{
struct V_85 * V_86 ;
struct V_24 * V_47 = F_14 ( V_88 ) ;
if ( V_88 -> V_84 ) {
V_86 = F_49 ( V_88 -> V_84 ) ;
if ( V_86 -> remove )
V_86 -> remove ( V_47 ) ;
}
return 0 ;
}
static void F_54 ( struct V_46 * V_88 )
{
struct V_85 * V_86 ;
struct V_24 * V_47 = F_14 ( V_88 ) ;
if ( ! V_88 -> V_84 )
return;
V_86 = F_49 ( V_88 -> V_84 ) ;
if ( V_86 -> V_91 )
V_86 -> V_91 ( V_47 ) ;
return;
}
static void F_55 ( struct V_46 * V_46 )
{
struct V_24 * V_25 = F_14 ( V_46 ) ;
struct V_31 * V_32 = V_25 -> V_32 ;
F_56 ( V_32 ,
V_32 -> V_33 . V_51 ) ;
F_57 ( V_25 ) ;
}
static void F_58 ( struct V_92 * V_93 )
{
struct V_94 * V_95 ;
if ( V_56 . V_96 == V_97 )
return;
V_95 = F_59 ( V_93 , struct V_94 ,
V_93 ) ;
F_60 ( & V_95 -> V_98 ) ;
F_57 ( V_95 ) ;
}
static void F_61 ( struct V_99 * V_98 , int V_100 )
{
struct V_101 * V_47 = V_102 . V_103 [ V_100 ] ;
if ( V_47 -> V_104 )
V_47 -> V_104 ( V_47 ) ;
V_98 -> V_105 . V_106 = V_107 ;
F_62 () ;
if ( V_98 -> V_105 . V_108 . V_109 ) {
F_2 ( V_110 , 0 ) ;
}
}
static void F_63 ( unsigned long V_111 )
{
int V_100 = F_64 () ;
void * V_112 = V_102 . V_113 [ V_100 ] ;
struct V_99 * V_98 = (struct V_99 * ) V_112 +
V_114 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
struct V_94 * V_95 ;
while ( 1 ) {
if ( V_98 -> V_105 . V_106 == V_107 )
break;
V_116 = (struct V_115 * ) V_98 -> V_44 . V_119 ;
if ( V_116 -> V_120 >= V_121 ) {
F_65 ( 1 , L_9 , V_116 -> V_120 ) ;
goto V_122;
}
V_118 = & V_123 [ V_116 -> V_120 ] ;
if ( V_118 -> V_124 == V_125 ) {
V_95 = F_66 ( sizeof( * V_95 ) , V_126 ) ;
if ( V_95 == NULL )
continue;
F_67 ( & V_95 -> V_93 , F_58 ) ;
memcpy ( & V_95 -> V_98 , V_98 , sizeof( * V_98 ) ) ;
F_68 ( V_56 . V_127 , & V_95 -> V_93 ) ;
} else
V_118 -> V_128 ( V_116 ) ;
V_122:
V_98 -> V_105 . V_106 = V_107 ;
F_62 () ;
if ( V_98 -> V_105 . V_108 . V_109 ) {
F_2 ( V_110 , 0 ) ;
}
}
}
static void F_69 ( void )
{
int V_100 = F_64 () ;
void * V_112 ;
struct V_99 * V_98 ;
union V_129 * V_130 ;
bool V_131 = false ;
V_112 = V_102 . V_132 [ V_100 ] ;
if ( V_112 == NULL )
return;
V_130 = (union V_129 * ) V_112 +
V_114 ;
if ( ( V_133 == V_134 ) ||
( V_133 == V_135 ) ) {
if ( F_70 ( 0 ,
( unsigned long * ) & V_130 -> V_136 [ 0 ] ) ) {
V_131 = true ;
}
} else {
V_131 = true ;
}
if ( V_131 )
F_71 ( V_102 . V_137 [ V_100 ] ) ;
V_112 = V_102 . V_113 [ V_100 ] ;
V_98 = (struct V_99 * ) V_112 + V_114 ;
if ( V_98 -> V_105 . V_106 != V_107 ) {
if ( V_98 -> V_105 . V_106 == V_138 )
F_61 ( V_98 , V_100 ) ;
else
F_71 ( & V_139 ) ;
}
}
static int F_72 ( void )
{
int V_79 ;
V_79 = F_73 () ;
if ( V_79 != 0 ) {
F_51 ( L_10 , V_79 ) ;
return V_79 ;
}
F_74 ( & V_139 , F_63 , 0 ) ;
V_79 = F_75 ( & V_140 ) ;
if ( V_79 )
goto V_141;
F_76 ( F_69 ) ;
V_79 = F_77 () ;
if ( V_79 )
goto V_142;
F_78 ( V_143 , NULL , 1 ) ;
V_79 = F_79 () ;
if ( V_79 )
goto V_144;
if ( V_133 > V_135 )
F_80 () ;
if ( V_145 . V_146 & V_147 ) {
F_81 ( & V_148 ) ;
F_82 ( & V_149 ,
& V_150 ) ;
}
F_83 () ;
return 0 ;
V_144:
F_78 ( V_151 , NULL , 1 ) ;
V_142:
F_84 () ;
F_85 () ;
F_86 ( & V_140 ) ;
V_141:
F_87 () ;
return V_79 ;
}
int F_88 ( struct V_85 * V_85 , struct V_152 * V_153 , const char * V_154 )
{
int V_79 ;
F_89 ( L_11 , V_85 -> V_155 ) ;
V_79 = F_6 () ;
if ( V_79 < 0 )
return V_79 ;
V_85 -> V_84 . V_155 = V_85 -> V_155 ;
V_85 -> V_84 . V_153 = V_153 ;
V_85 -> V_84 . V_154 = V_154 ;
V_85 -> V_84 . V_156 = & V_140 ;
V_79 = F_90 ( & V_85 -> V_84 ) ;
return V_79 ;
}
void F_91 ( struct V_85 * V_85 )
{
F_89 ( L_12 , V_85 -> V_155 ) ;
if ( ! F_6 () )
F_92 ( & V_85 -> V_84 ) ;
}
struct V_24 * F_93 ( const T_4 * type ,
const T_4 * V_157 ,
struct V_31 * V_32 )
{
struct V_24 * V_158 ;
V_158 = F_94 ( sizeof( struct V_24 ) , V_159 ) ;
if ( ! V_158 ) {
F_51 ( L_13 ) ;
return NULL ;
}
V_158 -> V_32 = V_32 ;
memcpy ( & V_158 -> V_29 , type , sizeof( T_4 ) ) ;
memcpy ( & V_158 -> V_160 , V_157 ,
sizeof( T_4 ) ) ;
return V_158 ;
}
int F_95 ( struct V_24 * V_158 )
{
int V_79 = 0 ;
F_96 ( & V_158 -> V_46 , L_14 ,
V_158 -> V_32 -> V_45 ) ;
V_158 -> V_46 . V_156 = & V_140 ;
V_158 -> V_46 . V_161 = & V_22 -> V_47 ;
V_158 -> V_46 . V_162 = F_55 ;
V_79 = F_97 ( & V_158 -> V_46 ) ;
if ( V_79 )
F_51 ( L_15 ) ;
else
F_98 ( L_16 ,
F_52 ( & V_158 -> V_46 ) ) ;
return V_79 ;
}
void F_99 ( struct V_24 * V_163 )
{
F_98 ( L_17 ,
F_52 ( & V_163 -> V_46 ) ) ;
F_100 ( & V_163 -> V_46 ) ;
}
static T_5 F_101 ( struct V_164 * V_165 , void * V_95 )
{
T_6 V_166 = 0 ;
T_6 V_167 = 0 ;
struct V_168 * V_169 ;
struct V_168 * * V_170 = & V_171 ;
struct V_168 * * V_172 = NULL ;
switch ( V_165 -> type ) {
case V_173 :
V_166 = V_165 -> V_111 . V_174 . V_175 . V_176 ;
V_167 = V_165 -> V_111 . V_174 . V_175 . V_177 ;
break;
case V_178 :
V_166 = V_165 -> V_111 . V_179 . V_175 . V_176 ;
V_167 = V_165 -> V_111 . V_179 . V_175 . V_177 ;
break;
default:
return V_180 ;
}
if ( V_167 < 0x100000 )
return V_180 ;
V_169 = F_94 ( sizeof( * V_169 ) , V_126 ) ;
if ( ! V_169 )
return V_181 ;
if ( V_167 > V_182 && V_166 < V_182 )
V_167 = V_182 ;
V_169 -> V_155 = L_18 ;
V_169 -> V_67 = V_183 ;
V_169 -> V_166 = V_166 ;
V_169 -> V_167 = V_167 ;
do {
if ( ! * V_170 ) {
* V_170 = V_169 ;
break;
}
if ( ( ( * V_170 ) -> V_167 + 1 ) == V_169 -> V_166 ) {
( * V_170 ) -> V_167 = V_169 -> V_167 ;
F_57 ( V_169 ) ;
break;
}
if ( ( * V_170 ) -> V_166 == V_169 -> V_167 + 1 ) {
( * V_170 ) -> V_166 = V_169 -> V_166 ;
F_57 ( V_169 ) ;
break;
}
if ( ( * V_170 ) -> V_167 < V_169 -> V_166 ) {
V_169 -> V_184 = * V_170 ;
if ( V_172 )
( * V_172 ) -> V_184 = V_169 ;
* V_170 = V_169 ;
break;
}
V_172 = V_170 ;
V_170 = & ( * V_170 ) -> V_184 ;
} while ( 1 );
return V_180 ;
}
static int F_102 ( struct V_185 * V_46 )
{
struct V_168 * V_186 ;
struct V_168 * V_187 ;
if ( V_171 ) {
for ( V_186 = V_171 ; V_186 ; V_186 = V_187 ) {
V_187 = V_186 -> V_184 ;
F_57 ( V_186 ) ;
}
}
return 0 ;
}
int F_103 ( struct V_168 * * V_188 , struct V_24 * V_163 ,
T_6 V_189 , T_6 V_190 ,
T_6 V_191 , T_6 V_192 ,
bool V_193 )
{
struct V_168 * V_194 ;
T_6 V_195 , V_196 , V_166 , V_197 , V_198 ;
const char * V_199 = F_52 ( & V_163 -> V_46 ) ;
T_2 V_200 = V_201 . V_202 + ( V_201 . V_203 << 1 ) ;
int V_27 ;
for ( V_194 = V_171 ; V_194 ; V_194 = V_194 -> V_184 ) {
if ( ( V_194 -> V_166 >= V_190 ) || ( V_194 -> V_167 <= V_189 ) )
continue;
V_195 = V_194 -> V_166 ;
V_196 = V_194 -> V_167 ;
for ( V_27 = 0 ; V_27 < 2 ; V_27 ++ ) {
V_197 = V_195 ;
V_198 = V_196 ;
if ( V_193 || ( V_195 >= V_200 ) ||
( V_196 <= V_201 . V_202 ) ) {
V_27 ++ ;
} else {
if ( ( V_195 <= V_201 . V_202 ) &&
( V_196 >= V_201 . V_202 ) ) {
V_198 = V_201 . V_202 - 1 ;
V_195 = V_200 ;
} else {
V_195 = V_200 ;
continue;
}
}
V_166 = ( V_197 + V_192 - 1 ) & ~ ( V_192 - 1 ) ;
for (; V_166 + V_191 - 1 <= V_198 ; V_166 += V_192 ) {
* V_188 = F_104 ( V_166 , V_191 ,
V_199 ) ;
if ( * V_188 )
return 0 ;
}
}
}
return - V_204 ;
}
int F_105 ( int V_205 )
{
return V_102 . V_206 [ V_205 ] ;
}
static int F_106 ( struct V_185 * V_46 )
{
T_5 V_207 ;
int V_208 = - V_23 ;
struct V_185 * V_209 ;
V_22 = V_46 ;
V_207 = F_107 ( V_46 -> V_210 , V_211 ,
F_101 , NULL ) ;
if ( F_108 ( V_207 ) )
goto V_212;
for ( V_209 = V_46 -> V_161 ; V_209 ; V_209 = V_209 -> V_161 ) {
V_207 = F_107 ( V_209 -> V_210 , V_211 ,
F_101 , NULL ) ;
if ( F_108 ( V_207 ) )
continue;
if ( V_171 )
break;
}
V_208 = 0 ;
V_212:
F_109 ( & V_213 ) ;
if ( V_208 )
F_102 ( V_46 ) ;
return V_208 ;
}
static void F_110 ( void )
{
int V_100 ;
F_111 () ;
F_112 () ;
F_113 (cpu)
F_114 ( V_100 , V_151 , NULL , 1 ) ;
F_87 () ;
}
static void F_115 ( struct V_1 * V_2 )
{
F_112 () ;
V_151 ( NULL ) ;
F_87 () ;
}
static int T_7 F_116 ( void )
{
int V_79 , V_214 ;
if ( V_215 != & V_216 )
return - V_23 ;
F_117 ( & V_213 ) ;
V_79 = F_118 ( & V_217 ) ;
if ( V_79 )
return V_79 ;
V_214 = F_119 ( & V_213 , 5 * V_218 ) ;
if ( V_214 == 0 ) {
V_79 = - V_219 ;
goto V_220;
}
V_79 = F_72 () ;
if ( V_79 )
goto V_220;
F_120 ( F_110 ) ;
F_121 ( F_115 ) ;
return 0 ;
V_220:
F_122 ( & V_217 ) ;
V_22 = NULL ;
return V_79 ;
}
static void T_8 F_123 ( void )
{
int V_100 ;
F_124 () ;
F_125 () ;
V_56 . V_96 = V_97 ;
F_111 () ;
F_126 () ;
F_85 () ;
F_127 ( & V_139 ) ;
F_128 () ;
if ( V_145 . V_146 & V_147 ) {
F_129 ( & V_148 ) ;
F_130 ( & V_149 ,
& V_150 ) ;
}
F_86 ( & V_140 ) ;
F_87 () ;
F_113 (cpu) {
F_127 ( V_102 . V_137 [ V_100 ] ) ;
F_114 ( V_100 , V_151 , NULL , 1 ) ;
}
F_84 () ;
F_122 ( & V_217 ) ;
if ( V_133 > V_135 )
F_131 () ;
}

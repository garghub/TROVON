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
static T_3 F_43 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
return sprintf ( V_50 , L_6 , V_25 -> V_77 ) ;
}
static T_3 F_44 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
char * V_50 )
{
struct V_24 * V_25 = F_14 ( V_47 ) ;
return sprintf ( V_50 , L_6 , V_25 -> V_78 ) ;
}
static int F_45 ( struct V_46 * V_46 , struct V_79 * V_80 )
{
struct V_24 * V_47 = F_14 ( V_46 ) ;
int V_81 ;
char V_26 [ V_28 + 1 ] ;
F_7 ( V_47 , V_26 ) ;
V_81 = F_46 ( V_80 , L_7 , V_26 ) ;
return V_81 ;
}
static inline bool F_47 ( const T_4 * V_82 )
{
if ( F_48 ( * V_82 , V_83 ) )
return false ;
return true ;
}
static const struct V_84 * F_49 (
const struct V_84 * V_45 ,
const T_4 * V_82 )
{
for (; ! F_47 ( & V_45 -> V_82 ) ; V_45 ++ )
if ( ! F_48 ( V_45 -> V_82 , * V_82 ) )
return V_45 ;
return NULL ;
}
static int F_50 ( struct V_46 * V_46 , struct V_85 * V_86 )
{
struct V_87 * V_88 = F_51 ( V_86 ) ;
struct V_24 * V_25 = F_14 ( V_46 ) ;
if ( F_52 ( V_25 -> V_32 ) )
return V_88 -> V_89 ;
if ( F_49 ( V_88 -> V_90 , & V_25 -> V_29 ) )
return 1 ;
return 0 ;
}
static int F_53 ( struct V_46 * V_91 )
{
int V_81 = 0 ;
struct V_87 * V_88 =
F_51 ( V_91 -> V_86 ) ;
struct V_24 * V_47 = F_14 ( V_91 ) ;
const struct V_84 * V_92 ;
V_92 = F_49 ( V_88 -> V_90 , & V_47 -> V_29 ) ;
if ( V_88 -> V_93 ) {
V_81 = V_88 -> V_93 ( V_47 , V_92 ) ;
if ( V_81 != 0 )
F_54 ( L_8 ,
F_55 ( V_91 ) , V_81 ) ;
} else {
F_54 ( L_9 ,
F_55 ( V_91 ) ) ;
V_81 = - V_23 ;
}
return V_81 ;
}
static int F_56 ( struct V_46 * V_91 )
{
struct V_87 * V_88 ;
struct V_24 * V_47 = F_14 ( V_91 ) ;
if ( V_91 -> V_86 ) {
V_88 = F_51 ( V_91 -> V_86 ) ;
if ( V_88 -> remove )
V_88 -> remove ( V_47 ) ;
}
return 0 ;
}
static void F_57 ( struct V_46 * V_91 )
{
struct V_87 * V_88 ;
struct V_24 * V_47 = F_14 ( V_91 ) ;
if ( ! V_91 -> V_86 )
return;
V_88 = F_51 ( V_91 -> V_86 ) ;
if ( V_88 -> V_94 )
V_88 -> V_94 ( V_47 ) ;
return;
}
static void F_58 ( struct V_46 * V_46 )
{
struct V_24 * V_25 = F_14 ( V_46 ) ;
struct V_31 * V_32 = V_25 -> V_32 ;
F_59 ( V_32 ,
V_32 -> V_33 . V_51 ) ;
F_60 ( V_25 ) ;
}
static void F_61 ( struct V_95 * V_96 )
{
struct V_97 * V_98 ;
if ( V_56 . V_99 == V_100 )
return;
V_98 = F_62 ( V_96 , struct V_97 ,
V_96 ) ;
F_63 ( & V_98 -> V_101 ) ;
F_60 ( V_98 ) ;
}
static void F_64 ( struct V_102 * V_101 , int V_103 )
{
struct V_104 * V_47 = V_105 . V_106 [ V_103 ] ;
if ( V_47 -> V_107 )
V_47 -> V_107 ( V_47 ) ;
F_65 ( V_101 , V_108 ) ;
}
void F_66 ( unsigned long V_109 )
{
int V_103 = F_67 () ;
void * V_110 = V_105 . V_111 [ V_103 ] ;
struct V_102 * V_101 = (struct V_102 * ) V_110 +
V_112 ;
struct V_113 * V_114 ;
struct V_115 * V_116 ;
struct V_97 * V_98 ;
T_2 V_117 = V_101 -> V_118 . V_117 ;
if ( V_117 == V_119 )
return;
V_114 = (struct V_113 * ) V_101 -> V_44 . V_120 ;
if ( V_114 -> V_121 >= V_122 ) {
F_68 ( 1 , L_10 , V_114 -> V_121 ) ;
goto V_123;
}
V_116 = & V_124 [ V_114 -> V_121 ] ;
if ( V_116 -> V_125 == V_126 ) {
V_98 = F_69 ( sizeof( * V_98 ) , V_127 ) ;
if ( V_98 == NULL )
return;
F_70 ( & V_98 -> V_96 , F_61 ) ;
memcpy ( & V_98 -> V_101 , V_101 , sizeof( * V_101 ) ) ;
F_71 ( V_56 . V_128 , & V_98 -> V_96 ) ;
} else
V_116 -> V_129 ( V_114 ) ;
V_123:
F_65 ( V_101 , V_117 ) ;
}
static void F_72 ( void )
{
int V_103 = F_67 () ;
void * V_110 ;
struct V_102 * V_101 ;
union V_130 * V_131 ;
bool V_132 = false ;
V_110 = V_105 . V_133 [ V_103 ] ;
if ( V_110 == NULL )
return;
V_131 = (union V_130 * ) V_110 +
V_112 ;
if ( ( V_134 == V_135 ) ||
( V_134 == V_136 ) ) {
if ( F_73 ( 0 ,
( unsigned long * ) & V_131 -> V_137 [ 0 ] ) ) {
V_132 = true ;
}
} else {
V_132 = true ;
}
if ( V_132 )
F_74 ( V_105 . V_138 [ V_103 ] ) ;
V_110 = V_105 . V_111 [ V_103 ] ;
V_101 = (struct V_102 * ) V_110 + V_112 ;
if ( V_101 -> V_118 . V_117 != V_119 ) {
if ( V_101 -> V_118 . V_117 == V_108 )
F_64 ( V_101 , V_103 ) ;
else
F_74 ( V_105 . V_139 [ V_103 ] ) ;
}
}
static int F_75 ( void )
{
int V_81 ;
V_81 = F_76 () ;
if ( V_81 != 0 ) {
F_54 ( L_11 , V_81 ) ;
return V_81 ;
}
V_81 = F_77 ( & V_140 ) ;
if ( V_81 )
goto V_141;
F_78 ( F_72 ) ;
V_81 = F_79 () ;
if ( V_81 )
goto V_142;
F_80 ( V_143 , NULL , 1 ) ;
V_81 = F_81 () ;
if ( V_81 )
goto V_144;
if ( V_134 > V_136 )
F_82 () ;
if ( V_145 . V_146 & V_147 ) {
F_83 ( & V_148 ) ;
F_84 ( & V_149 ,
& V_150 ) ;
}
F_85 () ;
return 0 ;
V_144:
F_80 ( V_151 , NULL , 1 ) ;
V_142:
F_86 () ;
F_87 () ;
F_88 ( & V_140 ) ;
V_141:
F_89 () ;
return V_81 ;
}
int F_90 ( struct V_87 * V_87 , struct V_152 * V_153 , const char * V_154 )
{
int V_81 ;
F_91 ( L_12 , V_87 -> V_155 ) ;
V_81 = F_6 () ;
if ( V_81 < 0 )
return V_81 ;
V_87 -> V_86 . V_155 = V_87 -> V_155 ;
V_87 -> V_86 . V_153 = V_153 ;
V_87 -> V_86 . V_154 = V_154 ;
V_87 -> V_86 . V_156 = & V_140 ;
V_81 = F_92 ( & V_87 -> V_86 ) ;
return V_81 ;
}
void F_93 ( struct V_87 * V_87 )
{
F_91 ( L_13 , V_87 -> V_155 ) ;
if ( ! F_6 () )
F_94 ( & V_87 -> V_86 ) ;
}
struct V_24 * F_95 ( const T_4 * type ,
const T_4 * V_157 ,
struct V_31 * V_32 )
{
struct V_24 * V_158 ;
V_158 = F_96 ( sizeof( struct V_24 ) , V_159 ) ;
if ( ! V_158 ) {
F_54 ( L_14 ) ;
return NULL ;
}
V_158 -> V_32 = V_32 ;
memcpy ( & V_158 -> V_29 , type , sizeof( T_4 ) ) ;
memcpy ( & V_158 -> V_160 , V_157 ,
sizeof( T_4 ) ) ;
V_158 -> V_77 = 0x1414 ;
return V_158 ;
}
int F_97 ( struct V_24 * V_158 )
{
int V_81 = 0 ;
F_98 ( & V_158 -> V_46 , L_15 ,
V_158 -> V_32 -> V_45 ) ;
V_158 -> V_46 . V_156 = & V_140 ;
V_158 -> V_46 . V_161 = & V_22 -> V_47 ;
V_158 -> V_46 . V_162 = F_58 ;
V_81 = F_99 ( & V_158 -> V_46 ) ;
if ( V_81 )
F_54 ( L_16 ) ;
else
F_100 ( L_17 ,
F_55 ( & V_158 -> V_46 ) ) ;
return V_81 ;
}
void F_101 ( struct V_24 * V_163 )
{
F_100 ( L_18 ,
F_55 ( & V_163 -> V_46 ) ) ;
F_102 ( & V_163 -> V_46 ) ;
}
static T_5 F_103 ( struct V_164 * V_165 , void * V_98 )
{
T_6 V_166 = 0 ;
T_6 V_167 = 0 ;
struct V_168 * V_169 ;
struct V_168 * * V_170 = & V_171 ;
struct V_168 * * V_172 = NULL ;
switch ( V_165 -> type ) {
case V_173 :
V_166 = V_165 -> V_109 . V_174 . V_175 . V_176 ;
V_167 = V_165 -> V_109 . V_174 . V_175 . V_177 ;
break;
case V_178 :
V_166 = V_165 -> V_109 . V_179 . V_175 . V_176 ;
V_167 = V_165 -> V_109 . V_179 . V_175 . V_177 ;
break;
default:
return V_180 ;
}
if ( V_167 < 0x100000 )
return V_180 ;
V_169 = F_96 ( sizeof( * V_169 ) , V_127 ) ;
if ( ! V_169 )
return V_181 ;
if ( V_167 > V_182 && V_166 < V_182 )
V_167 = V_182 ;
V_169 -> V_155 = L_19 ;
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
F_60 ( V_169 ) ;
break;
}
if ( ( * V_170 ) -> V_166 == V_169 -> V_167 + 1 ) {
( * V_170 ) -> V_166 = V_169 -> V_166 ;
F_60 ( V_169 ) ;
break;
}
if ( ( * V_170 ) -> V_166 > V_169 -> V_167 ) {
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
static int F_104 ( struct V_185 * V_46 )
{
struct V_168 * V_186 ;
struct V_168 * V_187 ;
if ( V_171 ) {
if ( V_188 ) {
F_105 ( V_171 , V_188 -> V_166 ,
F_106 ( V_188 ) ) ;
V_188 = NULL ;
}
for ( V_186 = V_171 ; V_186 ; V_186 = V_187 ) {
V_187 = V_186 -> V_184 ;
F_60 ( V_186 ) ;
}
}
return 0 ;
}
static void F_107 ( void )
{
int V_189 ;
if ( V_190 . V_191 ) {
if ( F_108 ( V_192 ) )
V_189 = F_109 ( V_193 , V_190 . V_194 , 0x800000 ) ;
else
V_189 = F_109 ( V_193 , V_190 . V_194 , 0x4000000 ) ;
for (; ! V_188 && ( V_189 >= 0x100000 ) ; V_189 >>= 1 ) {
V_188 = F_110 ( V_171 ,
V_190 . V_191 , V_189 ,
V_195 , 0 ) ;
}
}
}
int F_111 ( struct V_168 * * V_196 , struct V_24 * V_163 ,
T_6 V_197 , T_6 V_198 ,
T_6 V_189 , T_6 V_199 ,
bool V_200 )
{
struct V_168 * V_201 , * V_202 ;
T_6 V_203 , V_204 , V_166 ;
const char * V_205 = F_55 ( & V_163 -> V_46 ) ;
int V_206 ;
V_206 = - V_207 ;
F_112 ( & V_208 ) ;
if ( V_200 && V_188 && ! ( V_197 > V_188 -> V_167 ) &&
! ( V_198 < V_188 -> V_166 ) ) {
V_203 = V_188 -> V_166 ;
V_204 = V_188 -> V_167 ;
V_166 = ( V_203 + V_199 - 1 ) & ~ ( V_199 - 1 ) ;
for (; V_166 + V_189 - 1 <= V_204 ; V_166 += V_199 ) {
* V_196 = F_113 ( V_166 , V_189 , V_205 ) ;
if ( * V_196 ) {
V_206 = 0 ;
goto exit;
}
}
}
for ( V_201 = V_171 ; V_201 ; V_201 = V_201 -> V_184 ) {
if ( ( V_201 -> V_166 >= V_198 ) || ( V_201 -> V_167 <= V_197 ) )
continue;
V_203 = V_201 -> V_166 ;
V_204 = V_201 -> V_167 ;
V_166 = ( V_203 + V_199 - 1 ) & ~ ( V_199 - 1 ) ;
for (; V_166 + V_189 - 1 <= V_204 ; V_166 += V_199 ) {
V_202 = F_110 ( V_201 , V_166 , V_189 , NULL ,
V_209 ) ;
if ( ! V_202 )
continue;
* V_196 = F_113 ( V_166 , V_189 , V_205 ) ;
if ( * V_196 ) {
V_202 -> V_155 = ( char * ) * V_196 ;
V_206 = 0 ;
goto exit;
}
F_105 ( V_201 , V_166 , V_189 ) ;
}
}
exit:
F_114 ( & V_208 ) ;
return V_206 ;
}
void F_115 ( T_6 V_166 , T_6 V_189 )
{
struct V_168 * V_201 ;
F_112 ( & V_208 ) ;
for ( V_201 = V_171 ; V_201 ; V_201 = V_201 -> V_184 ) {
if ( ( V_201 -> V_166 >= V_166 + V_189 ) || ( V_201 -> V_167 <= V_166 ) )
continue;
F_105 ( V_201 , V_166 , V_189 ) ;
}
F_116 ( V_166 , V_189 ) ;
F_114 ( & V_208 ) ;
}
int F_117 ( int V_210 )
{
return V_105 . V_211 [ V_210 ] ;
}
static int F_118 ( struct V_185 * V_46 )
{
T_5 V_212 ;
int V_213 = - V_23 ;
struct V_185 * V_214 ;
V_22 = V_46 ;
V_212 = F_119 ( V_46 -> V_215 , V_216 ,
F_103 , NULL ) ;
if ( F_120 ( V_212 ) )
goto V_217;
for ( V_214 = V_46 -> V_161 ; V_214 ; V_214 = V_214 -> V_161 ) {
V_212 = F_119 ( V_214 -> V_215 , V_216 ,
F_103 , NULL ) ;
if ( F_120 ( V_212 ) )
continue;
if ( V_171 ) {
F_107 () ;
break;
}
}
V_213 = 0 ;
V_217:
F_121 ( & V_218 ) ;
if ( V_213 )
F_104 ( V_46 ) ;
return V_213 ;
}
static void F_122 ( void )
{
int V_103 ;
F_123 () ;
F_124 ( false ) ;
F_125 (cpu)
F_126 ( V_103 , V_151 , NULL , 1 ) ;
F_89 () ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_124 ( true ) ;
V_151 ( NULL ) ;
F_89 () ;
}
static int T_7 F_128 ( void )
{
int V_81 , V_219 ;
if ( V_220 != & V_221 )
return - V_23 ;
F_129 ( & V_218 ) ;
V_81 = F_130 ( & V_222 ) ;
if ( V_81 )
return V_81 ;
V_219 = F_131 ( & V_218 , 5 * V_223 ) ;
if ( V_219 == 0 ) {
V_81 = - V_224 ;
goto V_225;
}
V_81 = F_75 () ;
if ( V_81 )
goto V_225;
F_132 ( F_122 ) ;
F_133 ( F_127 ) ;
return 0 ;
V_225:
F_134 ( & V_222 ) ;
V_22 = NULL ;
return V_81 ;
}
static void T_8 F_135 ( void )
{
int V_103 ;
F_136 () ;
F_137 () ;
V_56 . V_99 = V_100 ;
F_123 () ;
F_138 () ;
F_87 () ;
F_125 (cpu)
F_139 ( V_105 . V_139 [ V_103 ] ) ;
F_140 () ;
if ( V_145 . V_146 & V_147 ) {
F_141 ( & V_148 ) ;
F_142 ( & V_149 ,
& V_150 ) ;
}
F_88 ( & V_140 ) ;
F_89 () ;
F_125 (cpu) {
F_139 ( V_105 . V_138 [ V_103 ] ) ;
F_126 ( V_103 , V_151 , NULL , 1 ) ;
}
F_86 () ;
F_134 ( & V_222 ) ;
if ( V_134 > V_136 )
F_143 () ;
}

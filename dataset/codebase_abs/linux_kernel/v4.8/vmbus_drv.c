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
F_75 ( V_140 , 0 ) ;
}
static int F_76 ( void )
{
int V_81 ;
V_81 = F_77 () ;
if ( V_81 != 0 ) {
F_54 ( L_11 , V_81 ) ;
return V_81 ;
}
V_81 = F_78 ( & V_141 ) ;
if ( V_81 )
goto V_142;
F_79 ( F_72 ) ;
V_81 = F_80 () ;
if ( V_81 )
goto V_143;
F_81 ( V_144 , NULL , 1 ) ;
V_81 = F_82 () ;
if ( V_81 )
goto V_145;
if ( V_134 > V_136 )
F_83 () ;
if ( V_146 . V_147 & V_148 ) {
F_84 ( & V_149 ) ;
F_85 ( & V_150 ,
& V_151 ) ;
}
F_86 () ;
return 0 ;
V_145:
F_81 ( V_152 , NULL , 1 ) ;
V_143:
F_87 () ;
F_88 () ;
F_89 ( & V_141 ) ;
V_142:
F_90 () ;
return V_81 ;
}
int F_91 ( struct V_87 * V_87 , struct V_153 * V_154 , const char * V_155 )
{
int V_81 ;
F_92 ( L_12 , V_87 -> V_156 ) ;
V_81 = F_6 () ;
if ( V_81 < 0 )
return V_81 ;
V_87 -> V_86 . V_156 = V_87 -> V_156 ;
V_87 -> V_86 . V_154 = V_154 ;
V_87 -> V_86 . V_155 = V_155 ;
V_87 -> V_86 . V_157 = & V_141 ;
V_81 = F_93 ( & V_87 -> V_86 ) ;
return V_81 ;
}
void F_94 ( struct V_87 * V_87 )
{
F_92 ( L_13 , V_87 -> V_156 ) ;
if ( ! F_6 () )
F_95 ( & V_87 -> V_86 ) ;
}
struct V_24 * F_96 ( const T_4 * type ,
const T_4 * V_158 ,
struct V_31 * V_32 )
{
struct V_24 * V_159 ;
V_159 = F_97 ( sizeof( struct V_24 ) , V_160 ) ;
if ( ! V_159 ) {
F_54 ( L_14 ) ;
return NULL ;
}
V_159 -> V_32 = V_32 ;
memcpy ( & V_159 -> V_29 , type , sizeof( T_4 ) ) ;
memcpy ( & V_159 -> V_161 , V_158 ,
sizeof( T_4 ) ) ;
V_159 -> V_77 = 0x1414 ;
return V_159 ;
}
int F_98 ( struct V_24 * V_159 )
{
int V_81 = 0 ;
F_99 ( & V_159 -> V_46 , L_15 ,
V_159 -> V_32 -> V_45 ) ;
V_159 -> V_46 . V_157 = & V_141 ;
V_159 -> V_46 . V_162 = & V_22 -> V_47 ;
V_159 -> V_46 . V_163 = F_58 ;
V_81 = F_100 ( & V_159 -> V_46 ) ;
if ( V_81 )
F_54 ( L_16 ) ;
else
F_101 ( L_17 ,
F_55 ( & V_159 -> V_46 ) ) ;
return V_81 ;
}
void F_102 ( struct V_24 * V_164 )
{
F_101 ( L_18 ,
F_55 ( & V_164 -> V_46 ) ) ;
F_103 ( & V_164 -> V_46 ) ;
}
static T_5 F_104 ( struct V_165 * V_166 , void * V_98 )
{
T_6 V_167 = 0 ;
T_6 V_168 = 0 ;
struct V_169 * V_170 ;
struct V_169 * * V_171 = & V_172 ;
struct V_169 * * V_173 = NULL ;
switch ( V_166 -> type ) {
case V_174 :
V_167 = V_166 -> V_109 . V_175 . V_176 . V_177 ;
V_168 = V_166 -> V_109 . V_175 . V_176 . V_178 ;
break;
case V_179 :
V_167 = V_166 -> V_109 . V_180 . V_176 . V_177 ;
V_168 = V_166 -> V_109 . V_180 . V_176 . V_178 ;
break;
default:
return V_181 ;
}
if ( V_168 < 0x100000 )
return V_181 ;
V_170 = F_97 ( sizeof( * V_170 ) , V_127 ) ;
if ( ! V_170 )
return V_182 ;
if ( V_168 > V_183 && V_167 < V_183 )
V_168 = V_183 ;
V_170 -> V_156 = L_19 ;
V_170 -> V_67 = V_184 ;
V_170 -> V_167 = V_167 ;
V_170 -> V_168 = V_168 ;
do {
if ( ! * V_171 ) {
* V_171 = V_170 ;
break;
}
if ( ( ( * V_171 ) -> V_168 + 1 ) == V_170 -> V_167 ) {
( * V_171 ) -> V_168 = V_170 -> V_168 ;
F_60 ( V_170 ) ;
break;
}
if ( ( * V_171 ) -> V_167 == V_170 -> V_168 + 1 ) {
( * V_171 ) -> V_167 = V_170 -> V_167 ;
F_60 ( V_170 ) ;
break;
}
if ( ( * V_171 ) -> V_167 > V_170 -> V_168 ) {
V_170 -> V_185 = * V_171 ;
if ( V_173 )
( * V_173 ) -> V_185 = V_170 ;
* V_171 = V_170 ;
break;
}
V_173 = V_171 ;
V_171 = & ( * V_171 ) -> V_185 ;
} while ( 1 );
return V_181 ;
}
static int F_105 ( struct V_186 * V_46 )
{
struct V_169 * V_187 ;
struct V_169 * V_188 ;
if ( V_172 ) {
if ( V_189 ) {
F_106 ( V_172 , V_189 -> V_167 ,
F_107 ( V_189 ) ) ;
V_189 = NULL ;
}
for ( V_187 = V_172 ; V_187 ; V_187 = V_188 ) {
V_188 = V_187 -> V_185 ;
F_60 ( V_187 ) ;
}
}
return 0 ;
}
static void F_108 ( void )
{
int V_190 ;
if ( V_191 . V_192 ) {
if ( F_109 ( V_193 ) )
V_190 = F_110 ( V_194 , V_191 . V_195 , 0x800000 ) ;
else
V_190 = F_110 ( V_194 , V_191 . V_195 , 0x4000000 ) ;
for (; ! V_189 && ( V_190 >= 0x100000 ) ; V_190 >>= 1 ) {
V_189 = F_111 ( V_172 ,
V_191 . V_192 , V_190 ,
V_196 , 0 ) ;
}
}
}
int F_112 ( struct V_169 * * V_197 , struct V_24 * V_164 ,
T_6 V_198 , T_6 V_199 ,
T_6 V_190 , T_6 V_200 ,
bool V_201 )
{
struct V_169 * V_202 , * V_203 ;
T_6 V_204 , V_205 , V_167 ;
const char * V_206 = F_55 ( & V_164 -> V_46 ) ;
int V_207 ;
V_207 = - V_208 ;
F_113 ( & V_209 ) ;
if ( V_201 && V_189 && ! ( V_198 > V_189 -> V_168 ) &&
! ( V_199 < V_189 -> V_167 ) ) {
V_204 = V_189 -> V_167 ;
V_205 = V_189 -> V_168 ;
V_167 = ( V_204 + V_200 - 1 ) & ~ ( V_200 - 1 ) ;
for (; V_167 + V_190 - 1 <= V_205 ; V_167 += V_200 ) {
* V_197 = F_114 ( V_167 , V_190 , V_206 ) ;
if ( * V_197 ) {
V_207 = 0 ;
goto exit;
}
}
}
for ( V_202 = V_172 ; V_202 ; V_202 = V_202 -> V_185 ) {
if ( ( V_202 -> V_167 >= V_199 ) || ( V_202 -> V_168 <= V_198 ) )
continue;
V_204 = V_202 -> V_167 ;
V_205 = V_202 -> V_168 ;
V_167 = ( V_204 + V_200 - 1 ) & ~ ( V_200 - 1 ) ;
for (; V_167 + V_190 - 1 <= V_205 ; V_167 += V_200 ) {
V_203 = F_111 ( V_202 , V_167 , V_190 , NULL ,
V_210 ) ;
if ( ! V_203 )
continue;
* V_197 = F_114 ( V_167 , V_190 , V_206 ) ;
if ( * V_197 ) {
V_203 -> V_156 = ( char * ) * V_197 ;
V_207 = 0 ;
goto exit;
}
F_106 ( V_202 , V_167 , V_190 ) ;
}
}
exit:
F_115 ( & V_209 ) ;
return V_207 ;
}
void F_116 ( T_6 V_167 , T_6 V_190 )
{
struct V_169 * V_202 ;
F_113 ( & V_209 ) ;
for ( V_202 = V_172 ; V_202 ; V_202 = V_202 -> V_185 ) {
if ( ( V_202 -> V_167 >= V_167 + V_190 ) || ( V_202 -> V_168 <= V_167 ) )
continue;
F_106 ( V_202 , V_167 , V_190 ) ;
}
F_117 ( V_167 , V_190 ) ;
F_115 ( & V_209 ) ;
}
int F_118 ( int V_211 )
{
return V_105 . V_212 [ V_211 ] ;
}
static int F_119 ( struct V_186 * V_46 )
{
T_5 V_213 ;
int V_214 = - V_23 ;
struct V_186 * V_215 ;
V_22 = V_46 ;
V_213 = F_120 ( V_46 -> V_216 , V_217 ,
F_104 , NULL ) ;
if ( F_121 ( V_213 ) )
goto V_218;
for ( V_215 = V_46 -> V_162 ; V_215 ; V_215 = V_215 -> V_162 ) {
V_213 = F_120 ( V_215 -> V_216 , V_217 ,
F_104 , NULL ) ;
if ( F_121 ( V_213 ) )
continue;
if ( V_172 ) {
F_108 () ;
break;
}
}
V_214 = 0 ;
V_218:
F_122 ( & V_219 ) ;
if ( V_214 )
F_105 ( V_46 ) ;
return V_214 ;
}
static void F_123 ( void )
{
int V_103 ;
F_124 () ;
F_125 ( false ) ;
F_126 (cpu)
F_127 ( V_103 , V_152 , NULL , 1 ) ;
F_90 () ;
}
static void F_128 ( struct V_1 * V_2 )
{
F_125 ( true ) ;
V_152 ( NULL ) ;
F_90 () ;
}
static int T_7 F_129 ( void )
{
int V_81 , V_220 ;
if ( V_221 != & V_222 )
return - V_23 ;
F_130 ( & V_219 ) ;
V_81 = F_131 ( & V_223 ) ;
if ( V_81 )
return V_81 ;
V_220 = F_132 ( & V_219 , 5 * V_224 ) ;
if ( V_220 == 0 ) {
V_81 = - V_225 ;
goto V_226;
}
V_81 = F_76 () ;
if ( V_81 )
goto V_226;
F_133 ( F_123 ) ;
F_134 ( F_128 ) ;
return 0 ;
V_226:
F_135 ( & V_223 ) ;
V_22 = NULL ;
return V_81 ;
}
static void T_8 F_136 ( void )
{
int V_103 ;
F_137 () ;
F_138 () ;
V_56 . V_99 = V_100 ;
F_124 () ;
F_139 () ;
F_88 () ;
F_126 (cpu)
F_140 ( V_105 . V_139 [ V_103 ] ) ;
F_141 () ;
if ( V_146 . V_147 & V_148 ) {
F_142 ( & V_149 ) ;
F_143 ( & V_150 ,
& V_151 ) ;
}
F_89 ( & V_141 ) ;
F_90 () ;
F_126 (cpu) {
F_140 ( V_105 . V_138 [ V_103 ] ) ;
F_127 ( V_103 , V_152 , NULL , 1 ) ;
}
F_87 () ;
F_135 ( & V_223 ) ;
if ( V_134 > V_136 )
F_144 () ;
}

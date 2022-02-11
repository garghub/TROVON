static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 () ;
F_3 ( V_7 , V_6 -> V_8 ) ;
F_3 ( V_9 , V_6 -> V_10 ) ;
F_3 ( V_11 , V_6 -> V_12 ) ;
F_3 ( V_13 , V_6 -> V_14 ) ;
F_3 ( V_15 , V_6 -> V_16 ) ;
F_3 ( V_17 , V_18 ) ;
return V_19 ;
}
static int F_4 ( void )
{
if ( V_20 == NULL )
return - V_21 ;
return 0 ;
}
static void F_5 ( struct V_22 * V_23 , char * V_24 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 += 2 )
sprintf ( & V_24 [ V_25 ] , L_1 , V_23 -> V_27 . V_28 [ V_25 / 2 ] ) ;
}
static T_1 F_6 ( struct V_29 * V_30 )
{
return ( T_1 ) V_30 -> V_31 . V_32 / 32 ;
}
static T_1 F_7 ( struct V_29 * V_30 )
{
return ( T_1 ) V_30 -> V_31 . V_32 % 32 ;
}
static T_2 F_8 ( struct V_29 * V_30 ,
struct V_33 * V_34 )
{
T_1 V_35 = F_6 ( V_30 ) ;
return V_34 -> V_36 [ V_35 ] . V_37 ;
}
static T_2 F_9 ( struct V_29 * V_30 ,
struct V_33 * V_34 )
{
T_1 V_35 = F_6 ( V_30 ) ;
T_1 V_38 = F_7 ( V_30 ) ;
return V_34 -> V_39 [ V_35 ] [ V_38 ] ;
}
static T_2 F_10 ( struct V_29 * V_30 ,
struct V_33 * V_34 )
{
T_1 V_35 = F_6 ( V_30 ) ;
T_1 V_38 = F_7 ( V_30 ) ;
return V_34 -> V_40 [ V_35 ] [ V_38 ] . V_41 . V_42 . V_43 ;
}
static T_3 F_11 ( struct V_44 * V_45 , struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_2 , V_23 -> V_30 -> V_31 . V_49 ) ;
}
static T_3 F_13 ( struct V_44 * V_45 , struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_2 , V_23 -> V_30 -> V_50 ) ;
}
static T_3 F_14 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_2 , V_23 -> V_30 -> V_31 . V_32 ) ;
}
static T_3 F_15 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_3 ,
V_23 -> V_30 -> V_31 . V_51 . V_52 . V_28 ) ;
}
static T_3 F_16 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_3 ,
V_23 -> V_30 -> V_31 . V_51 . V_53 . V_28 ) ;
}
static T_3 F_17 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
char V_24 [ V_26 + 1 ] ;
F_5 ( V_23 , V_24 ) ;
return sprintf ( V_48 , L_4 , V_24 ) ;
}
static T_3 F_18 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_2 ,
F_8 ( V_23 -> V_30 ,
V_54 . V_55 [ 1 ] ) ) ;
}
static T_3 F_19 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_2 ,
F_8 ( V_23 -> V_30 ,
V_54 . V_55 [ 1 ] ) ) ;
}
static T_3 F_20 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_2 ,
F_9 ( V_23 -> V_30 ,
V_54 . V_55 [ 0 ] ) ) ;
}
static T_3 F_21 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_2 ,
F_9 ( V_23 -> V_30 ,
V_54 . V_55 [ 1 ] ) ) ;
}
static T_3 F_22 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_2 ,
F_10 ( V_23 -> V_30 ,
V_54 . V_55 [ 0 ] ) ) ;
}
static T_3 F_23 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
if ( ! V_23 -> V_30 )
return - V_21 ;
return sprintf ( V_48 , L_2 ,
F_10 ( V_23 -> V_30 ,
V_54 . V_55 [ 1 ] ) ) ;
}
static T_3 F_24 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
struct V_56 V_57 ;
if ( ! V_23 -> V_30 )
return - V_21 ;
F_25 ( & V_23 -> V_30 -> V_57 , & V_57 ) ;
return sprintf ( V_48 , L_2 , V_57 . V_58 ) ;
}
static T_3 F_26 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
struct V_56 V_57 ;
if ( ! V_23 -> V_30 )
return - V_21 ;
F_25 ( & V_23 -> V_30 -> V_57 , & V_57 ) ;
return sprintf ( V_48 , L_2 , V_57 . V_59 ) ;
}
static T_3 F_27 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
struct V_56 V_57 ;
if ( ! V_23 -> V_30 )
return - V_21 ;
F_25 ( & V_23 -> V_30 -> V_57 , & V_57 ) ;
return sprintf ( V_48 , L_2 , V_57 . V_60 ) ;
}
static T_3 F_28 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
struct V_56 V_57 ;
if ( ! V_23 -> V_30 )
return - V_21 ;
F_25 ( & V_23 -> V_30 -> V_57 , & V_57 ) ;
return sprintf ( V_48 , L_2 , V_57 . V_61 ) ;
}
static T_3 F_29 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
struct V_56 V_57 ;
if ( ! V_23 -> V_30 )
return - V_21 ;
F_25 ( & V_23 -> V_30 -> V_57 , & V_57 ) ;
return sprintf ( V_48 , L_2 , V_57 . V_62 ) ;
}
static T_3 F_30 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
struct V_56 V_63 ;
if ( ! V_23 -> V_30 )
return - V_21 ;
F_25 ( & V_23 -> V_30 -> V_63 , & V_63 ) ;
return sprintf ( V_48 , L_2 , V_63 . V_58 ) ;
}
static T_3 F_31 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
struct V_56 V_63 ;
if ( ! V_23 -> V_30 )
return - V_21 ;
F_25 ( & V_23 -> V_30 -> V_63 , & V_63 ) ;
return sprintf ( V_48 , L_2 , V_63 . V_59 ) ;
}
static T_3 F_32 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
struct V_56 V_63 ;
if ( ! V_23 -> V_30 )
return - V_21 ;
F_25 ( & V_23 -> V_30 -> V_63 , & V_63 ) ;
return sprintf ( V_48 , L_2 , V_63 . V_60 ) ;
}
static T_3 F_33 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
struct V_56 V_63 ;
if ( ! V_23 -> V_30 )
return - V_21 ;
F_25 ( & V_23 -> V_30 -> V_63 , & V_63 ) ;
return sprintf ( V_48 , L_2 , V_63 . V_61 ) ;
}
static T_3 F_34 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
char * V_48 )
{
struct V_22 * V_23 = F_12 ( V_45 ) ;
struct V_56 V_63 ;
if ( ! V_23 -> V_30 )
return - V_21 ;
F_25 ( & V_23 -> V_30 -> V_63 , & V_63 ) ;
return sprintf ( V_48 , L_2 , V_63 . V_62 ) ;
}
static int F_35 ( struct V_44 * V_44 , struct V_64 * V_65 )
{
struct V_22 * V_45 = F_12 ( V_44 ) ;
int V_66 ;
char V_24 [ V_26 + 1 ] ;
F_5 ( V_45 , V_24 ) ;
V_66 = F_36 ( V_65 , L_5 , V_24 ) ;
return V_66 ;
}
static inline bool F_37 ( const T_4 * V_67 )
{
if ( memcmp ( V_67 , & V_68 , sizeof( V_69 ) ) )
return false ;
return true ;
}
static const struct V_70 * F_38 (
const struct V_70 * V_43 ,
const T_4 * V_67 )
{
for (; ! F_37 ( V_43 -> V_67 ) ; V_43 ++ )
if ( ! memcmp ( & V_43 -> V_67 , V_67 , sizeof( V_69 ) ) )
return V_43 ;
return NULL ;
}
static int F_39 ( struct V_44 * V_44 , struct V_71 * V_72 )
{
struct V_73 * V_74 = F_40 ( V_72 ) ;
struct V_22 * V_23 = F_12 ( V_44 ) ;
if ( F_38 ( V_74 -> V_75 , V_23 -> V_27 . V_28 ) )
return 1 ;
return 0 ;
}
static int F_41 ( struct V_44 * V_76 )
{
int V_66 = 0 ;
struct V_73 * V_74 =
F_40 ( V_76 -> V_72 ) ;
struct V_22 * V_45 = F_12 ( V_76 ) ;
const struct V_70 * V_77 ;
V_77 = F_38 ( V_74 -> V_75 , V_45 -> V_27 . V_28 ) ;
if ( V_74 -> V_78 ) {
V_66 = V_74 -> V_78 ( V_45 , V_77 ) ;
if ( V_66 != 0 )
F_42 ( L_6 ,
F_43 ( V_76 ) , V_66 ) ;
} else {
F_42 ( L_7 ,
F_43 ( V_76 ) ) ;
V_66 = - V_21 ;
}
return V_66 ;
}
static int F_44 ( struct V_44 * V_76 )
{
struct V_73 * V_74 ;
struct V_22 * V_45 = F_12 ( V_76 ) ;
T_2 V_79 = V_45 -> V_30 -> V_31 . V_49 ;
if ( V_76 -> V_72 ) {
V_74 = F_40 ( V_76 -> V_72 ) ;
if ( V_74 -> remove )
V_74 -> remove ( V_45 ) ;
else {
F_45 ( V_45 -> V_30 , V_79 ) ;
F_42 ( L_8 ,
F_43 ( V_76 ) ) ;
}
} else {
F_45 ( V_45 -> V_30 , V_79 ) ;
}
return 0 ;
}
static void F_46 ( struct V_44 * V_76 )
{
struct V_73 * V_74 ;
struct V_22 * V_45 = F_12 ( V_76 ) ;
if ( ! V_76 -> V_72 )
return;
V_74 = F_40 ( V_76 -> V_72 ) ;
if ( V_74 -> V_80 )
V_74 -> V_80 ( V_45 ) ;
return;
}
static void F_47 ( struct V_44 * V_44 )
{
struct V_22 * V_23 = F_12 ( V_44 ) ;
F_48 ( V_23 ) ;
}
static void F_49 ( struct V_81 * V_82 )
{
struct V_83 * V_84 ;
if ( V_54 . V_85 == V_86 )
return;
V_84 = F_50 ( V_82 , struct V_83 ,
V_82 ) ;
F_51 ( & V_84 -> V_87 ) ;
F_48 ( V_84 ) ;
}
static void F_52 ( struct V_88 * V_87 , int V_89 )
{
struct V_90 * V_45 = V_91 . V_92 [ V_89 ] ;
if ( V_45 -> V_93 )
V_45 -> V_93 ( V_45 ) ;
V_87 -> V_94 . V_95 = V_96 ;
F_53 () ;
if ( V_87 -> V_94 . V_97 . V_98 ) {
F_3 ( V_99 , 0 ) ;
}
}
static void F_54 ( unsigned long V_100 )
{
int V_89 = F_55 () ;
void * V_101 = V_91 . V_102 [ V_89 ] ;
struct V_88 * V_87 = (struct V_88 * ) V_101 +
V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
struct V_83 * V_84 ;
while ( 1 ) {
if ( V_87 -> V_94 . V_95 == V_96 )
break;
V_105 = (struct V_104 * ) V_87 -> V_42 . V_108 ;
if ( V_105 -> V_109 >= V_110 ) {
F_56 ( 1 , L_9 , V_105 -> V_109 ) ;
goto V_111;
}
V_107 = & V_112 [ V_105 -> V_109 ] ;
if ( V_107 -> V_113 == V_114 ) {
V_84 = F_57 ( sizeof( * V_84 ) , V_115 ) ;
if ( V_84 == NULL )
continue;
F_58 ( & V_84 -> V_82 , F_49 ) ;
memcpy ( & V_84 -> V_87 , V_87 , sizeof( * V_87 ) ) ;
F_59 ( V_54 . V_116 , & V_84 -> V_82 ) ;
} else
V_107 -> V_117 ( V_105 ) ;
V_111:
V_87 -> V_94 . V_95 = V_96 ;
F_53 () ;
if ( V_87 -> V_94 . V_97 . V_98 ) {
F_3 ( V_99 , 0 ) ;
}
}
}
static void F_60 ( void )
{
int V_89 = F_55 () ;
void * V_101 ;
struct V_88 * V_87 ;
union V_118 * V_3 ;
bool V_119 = false ;
V_101 = V_91 . V_120 [ V_89 ] ;
if ( V_101 == NULL )
return;
V_3 = (union V_118 * ) V_101 +
V_103 ;
if ( ( V_121 == V_122 ) ||
( V_121 == V_123 ) ) {
if ( F_61 ( 0 ,
( unsigned long * ) & V_3 -> V_124 [ 0 ] ) ) {
V_119 = true ;
}
} else {
V_119 = true ;
}
if ( V_119 )
F_62 ( V_91 . V_125 [ V_89 ] ) ;
V_101 = V_91 . V_102 [ V_89 ] ;
V_87 = (struct V_88 * ) V_101 + V_103 ;
if ( V_87 -> V_94 . V_95 != V_96 ) {
if ( V_87 -> V_94 . V_95 == V_126 )
F_52 ( V_87 , V_89 ) ;
else
F_62 ( & V_127 ) ;
}
}
static int F_63 ( void )
{
return - V_128 ;
}
static void F_64 ( bool V_129 )
{
static void * V_130 ;
if ( ( V_121 == V_122 ) ||
( V_121 == V_123 ) )
return;
if ( V_129 ) {
V_130 = V_131 . V_132 ;
V_131 . V_132 = F_63 ;
F_65 ( L_10 ) ;
} else if ( V_130 )
V_131 . V_132 = V_130 ;
}
static void F_64 ( bool V_129 )
{
}
static int F_66 ( int V_133 )
{
int V_66 ;
V_66 = F_67 () ;
if ( V_66 != 0 ) {
F_42 ( L_11 , V_66 ) ;
return V_66 ;
}
F_68 ( & V_127 , F_54 , 0 ) ;
V_66 = F_69 ( & V_134 ) ;
if ( V_66 )
goto V_135;
F_70 ( F_60 ) ;
V_66 = F_71 () ;
if ( V_66 )
goto V_136;
F_72 ( V_137 , NULL , 1 ) ;
V_66 = F_73 () ;
if ( V_66 )
goto V_136;
F_64 ( true ) ;
if ( V_138 . V_139 & V_140 ) {
F_74 ( & V_141 ,
& V_142 ) ;
}
F_75 () ;
return 0 ;
V_136:
F_76 () ;
F_77 () ;
F_78 ( & V_134 ) ;
V_135:
F_79 () ;
return V_66 ;
}
int F_80 ( struct V_73 * V_73 , struct V_143 * V_144 , const char * V_145 )
{
int V_66 ;
F_81 ( L_12 , V_73 -> V_146 ) ;
V_66 = F_4 () ;
if ( V_66 < 0 )
return V_66 ;
V_73 -> V_72 . V_146 = V_73 -> V_146 ;
V_73 -> V_72 . V_144 = V_144 ;
V_73 -> V_72 . V_145 = V_145 ;
V_73 -> V_72 . V_147 = & V_134 ;
V_66 = F_82 ( & V_73 -> V_72 ) ;
return V_66 ;
}
void F_83 ( struct V_73 * V_73 )
{
F_81 ( L_13 , V_73 -> V_146 ) ;
if ( ! F_4 () )
F_84 ( & V_73 -> V_72 ) ;
}
struct V_22 * F_85 ( const V_69 * type ,
const V_69 * V_148 ,
struct V_29 * V_30 )
{
struct V_22 * V_149 ;
V_149 = F_86 ( sizeof( struct V_22 ) , V_150 ) ;
if ( ! V_149 ) {
F_42 ( L_14 ) ;
return NULL ;
}
V_149 -> V_30 = V_30 ;
memcpy ( & V_149 -> V_27 , type , sizeof( V_69 ) ) ;
memcpy ( & V_149 -> V_151 , V_148 ,
sizeof( V_69 ) ) ;
return V_149 ;
}
int F_87 ( struct V_22 * V_149 )
{
int V_66 = 0 ;
F_88 ( & V_149 -> V_44 , L_15 ,
V_149 -> V_30 -> V_43 ) ;
V_149 -> V_44 . V_147 = & V_134 ;
V_149 -> V_44 . V_152 = & V_20 -> V_45 ;
V_149 -> V_44 . V_153 = F_47 ;
V_66 = F_89 ( & V_149 -> V_44 ) ;
if ( V_66 )
F_42 ( L_16 ) ;
else
F_90 ( L_17 ,
F_43 ( & V_149 -> V_44 ) ) ;
return V_66 ;
}
void F_91 ( struct V_22 * V_154 )
{
F_90 ( L_18 ,
F_43 ( & V_154 -> V_44 ) ) ;
F_92 ( & V_154 -> V_44 ) ;
}
static T_5 F_93 ( struct V_155 * V_156 , void * V_84 )
{
switch ( V_156 -> type ) {
case V_157 :
V_133 = V_156 -> V_100 . V_133 . V_158 [ 0 ] ;
break;
case V_159 :
V_160 . V_161 = V_156 -> V_100 . V_162 . V_163 . V_164 ;
V_160 . V_165 = V_156 -> V_100 . V_162 . V_163 . V_166 ;
break;
}
return V_167 ;
}
static int F_94 ( struct V_168 * V_44 )
{
T_5 V_169 ;
int V_170 = - V_21 ;
V_20 = V_44 ;
V_169 = F_95 ( V_44 -> V_171 , V_172 ,
F_93 , NULL ) ;
if ( F_96 ( V_169 ) )
goto V_173;
if ( V_44 -> V_152 ) {
V_169 = F_95 ( V_44 -> V_152 -> V_171 ,
V_172 ,
F_93 , NULL ) ;
if ( F_96 ( V_169 ) )
goto V_173;
if ( V_160 . V_161 && V_160 . V_165 )
F_97 ( & V_174 , & V_160 ) ;
}
V_170 = 0 ;
V_173:
F_98 ( & V_175 ) ;
return V_170 ;
}
static int T_6 F_99 ( void )
{
int V_66 , V_176 ;
if ( V_177 != & V_178 )
return - V_21 ;
F_100 ( & V_175 ) ;
V_66 = F_101 ( & V_179 ) ;
if ( V_66 )
return V_66 ;
V_176 = F_102 ( & V_175 , 5 * V_180 ) ;
if ( V_176 == 0 ) {
V_66 = - V_181 ;
goto V_182;
}
if ( V_133 <= 0 ) {
V_66 = - V_21 ;
goto V_182;
}
V_66 = F_66 ( V_133 ) ;
if ( V_66 )
goto V_182;
return 0 ;
V_182:
F_103 ( & V_179 ) ;
V_20 = NULL ;
return V_66 ;
}
static void T_7 F_104 ( void )
{
int V_89 ;
V_54 . V_85 = V_86 ;
F_105 () ;
F_77 () ;
F_106 () ;
F_78 ( & V_134 ) ;
F_79 () ;
F_107 (cpu)
F_108 ( V_89 , V_183 , NULL , 1 ) ;
F_103 ( & V_179 ) ;
F_64 ( false ) ;
F_109 () ;
}

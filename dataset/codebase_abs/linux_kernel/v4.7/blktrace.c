static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
const void * V_5 , T_2 V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
int V_13 = 0 ;
int V_14 = F_2 () ;
bool V_15 = V_16 ;
if ( V_15 ) {
V_12 = V_17 -> V_18 . V_12 ;
V_13 = F_3 () ;
V_10 = F_4 ( V_12 , V_19 ,
sizeof( * V_8 ) + V_6 ,
0 , V_13 ) ;
if ( ! V_10 )
return;
V_8 = F_5 ( V_10 ) ;
goto V_20;
}
if ( ! V_2 -> V_21 )
return;
V_8 = F_6 ( V_2 -> V_21 , sizeof( * V_8 ) + V_6 ) ;
if ( V_8 ) {
V_8 -> V_22 = V_23 | V_24 ;
V_8 -> time = F_7 ( F_8 () ) ;
V_20:
V_8 -> V_25 = V_2 -> V_26 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_14 = V_14 ;
V_8 -> V_27 = V_6 ;
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_5 , V_6 ) ;
if ( V_15 )
F_9 ( V_17 , V_12 , V_10 , 0 , V_13 ) ;
}
}
static void F_10 ( struct V_28 * V_29 )
{
unsigned long V_30 ;
struct V_1 * V_2 ;
V_29 -> V_31 = V_32 ;
F_11 ( & V_33 , V_30 ) ;
F_12 (bt, &running_trace_list, running_list) {
F_1 ( V_2 , V_29 -> V_3 , V_34 , V_29 -> V_35 ,
sizeof( V_29 -> V_35 ) ) ;
}
F_13 ( & V_33 , V_30 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_36 V_37 ;
unsigned long V_30 ;
T_3 V_38 [ 2 ] ;
F_15 ( & V_37 ) ;
V_38 [ 0 ] = V_37 . V_39 ;
V_38 [ 1 ] = V_37 . V_40 ;
F_16 ( V_30 ) ;
F_1 ( V_2 , 0 , V_41 , V_38 , sizeof( V_38 ) ) ;
F_17 ( V_30 ) ;
}
void F_18 ( struct V_1 * V_2 , const char * V_42 , ... )
{
int V_43 ;
T_4 args ;
unsigned long V_30 ;
char * V_44 ;
if ( F_19 ( V_2 -> V_45 != V_46 &&
! V_16 ) )
return;
if ( ! ( V_2 -> V_47 & V_48 ) )
return;
F_16 ( V_30 ) ;
V_44 = F_20 ( V_2 -> V_49 ) ;
va_start ( args , V_42 ) ;
V_43 = F_21 ( V_44 , V_50 , V_42 , args ) ;
va_end ( args ) ;
F_1 ( V_2 , 0 , V_51 , V_44 , V_43 ) ;
F_17 ( V_30 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_52 , T_5 V_53 ,
T_1 V_3 )
{
if ( ( ( V_2 -> V_47 << V_54 ) & V_52 ) == 0 )
return 1 ;
if ( V_53 && ( V_53 < V_2 -> V_55 || V_53 > V_2 -> V_56 ) )
return 1 ;
if ( V_2 -> V_3 && V_3 != V_2 -> V_3 )
return 1 ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , T_5 V_53 , int V_57 ,
int V_58 , T_3 V_52 , int error , int V_27 , void * V_59 )
{
struct V_28 * V_29 = V_60 ;
struct V_9 * V_10 = NULL ;
struct V_11 * V_12 = NULL ;
struct V_7 * V_8 ;
unsigned long V_30 = 0 ;
unsigned long * V_61 ;
T_1 V_3 ;
int V_14 , V_13 = 0 ;
bool V_15 = V_16 ;
if ( F_19 ( V_2 -> V_45 != V_46 && ! V_15 ) )
return;
V_52 |= V_62 [ V_58 & V_63 ] ;
V_52 |= F_24 ( V_58 , V_64 ) ;
V_52 |= F_24 ( V_58 , V_65 ) ;
V_52 |= F_24 ( V_58 , V_66 ) ;
V_52 |= F_24 ( V_58 , V_67 ) ;
V_52 |= F_24 ( V_58 , V_68 ) ;
V_52 |= F_24 ( V_58 , V_69 ) ;
V_3 = V_29 -> V_3 ;
if ( F_22 ( V_2 , V_52 , V_53 , V_3 ) )
return;
V_14 = F_25 () ;
if ( V_15 ) {
F_26 ( V_60 ) ;
V_12 = V_17 -> V_18 . V_12 ;
V_13 = F_3 () ;
V_10 = F_4 ( V_12 , V_19 ,
sizeof( * V_8 ) + V_27 ,
0 , V_13 ) ;
if ( ! V_10 )
return;
V_8 = F_5 ( V_10 ) ;
goto V_20;
}
if ( F_19 ( V_29 -> V_31 != V_32 ) )
F_10 ( V_29 ) ;
F_16 ( V_30 ) ;
V_8 = F_6 ( V_2 -> V_21 , sizeof( * V_8 ) + V_27 ) ;
if ( V_8 ) {
V_61 = F_27 ( V_2 -> V_61 , V_14 ) ;
V_8 -> V_22 = V_23 | V_24 ;
V_8 -> V_61 = ++ ( * V_61 ) ;
V_8 -> time = F_7 ( F_8 () ) ;
V_20:
V_8 -> V_14 = V_14 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_53 = V_53 ;
V_8 -> V_57 = V_57 ;
V_8 -> V_4 = V_52 ;
V_8 -> V_25 = V_2 -> V_26 ;
V_8 -> error = error ;
V_8 -> V_27 = V_27 ;
if ( V_27 )
memcpy ( ( void * ) V_8 + sizeof( * V_8 ) , V_59 , V_27 ) ;
if ( V_15 ) {
F_9 ( V_17 , V_12 , V_10 , 0 , V_13 ) ;
return;
}
}
F_17 ( V_30 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_2 -> V_70 ) ;
F_29 ( V_2 -> V_71 ) ;
F_30 ( V_2 -> V_21 ) ;
F_29 ( V_2 -> V_72 ) ;
F_31 ( V_2 -> V_61 ) ;
F_31 ( V_2 -> V_49 ) ;
F_32 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_28 ( V_2 ) ;
if ( F_34 ( & V_73 ) )
F_35 () ;
}
int F_36 ( struct V_74 * V_75 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( & V_75 -> V_1 , NULL ) ;
if ( ! V_2 )
return - V_76 ;
if ( V_2 -> V_45 != V_46 )
F_33 ( V_2 ) ;
return 0 ;
}
static T_6 F_38 ( struct V_77 * V_78 , char T_7 * V_12 ,
T_2 V_79 , T_8 * V_80 )
{
struct V_1 * V_2 = V_78 -> V_81 ;
char V_44 [ 16 ] ;
snprintf ( V_44 , sizeof( V_44 ) , L_1 , F_39 ( & V_2 -> V_82 ) ) ;
return F_40 ( V_12 , V_79 , V_80 , V_44 , strlen ( V_44 ) ) ;
}
static T_6 F_41 ( struct V_77 * V_78 , const char T_7 * V_12 ,
T_2 V_79 , T_8 * V_80 )
{
char * V_83 ;
struct V_1 * V_2 ;
if ( V_79 >= V_50 )
return - V_76 ;
V_83 = F_42 ( V_12 , V_79 ) ;
if ( F_43 ( V_83 ) )
return F_44 ( V_83 ) ;
V_2 = V_78 -> V_81 ;
F_18 ( V_2 , L_2 , V_83 ) ;
F_32 ( V_83 ) ;
return V_79 ;
}
static int F_45 ( struct V_84 * V_44 , void * V_85 ,
void * V_86 , T_2 V_87 )
{
struct V_1 * V_2 ;
if ( ! F_46 ( V_44 ) )
return 1 ;
V_2 = V_44 -> V_88 -> V_81 ;
F_47 ( & V_2 -> V_82 ) ;
return 0 ;
}
static int F_48 ( struct V_89 * V_89 )
{
F_29 ( V_89 ) ;
return 0 ;
}
static struct V_89 * F_49 ( const char * V_90 ,
struct V_89 * V_91 ,
T_9 V_92 ,
struct V_84 * V_44 ,
int * V_93 )
{
return F_50 ( V_90 , V_92 , V_91 , V_44 ,
& V_94 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_97 * V_98 = NULL ;
if ( V_96 )
V_98 = V_96 -> V_99 ;
if ( V_98 ) {
V_2 -> V_55 = V_98 -> V_100 ;
V_2 -> V_56 = V_98 -> V_100 + V_98 -> V_101 ;
} else {
V_2 -> V_55 = 0 ;
V_2 -> V_56 = - 1ULL ;
}
}
int F_52 ( struct V_74 * V_75 , char * V_102 , T_10 V_26 ,
struct V_95 * V_96 ,
struct V_103 * V_104 )
{
struct V_1 * V_2 = NULL ;
struct V_89 * V_72 = NULL ;
int V_105 ;
if ( ! V_104 -> V_106 || ! V_104 -> V_107 )
return - V_76 ;
strncpy ( V_104 -> V_102 , V_102 , V_108 ) ;
V_104 -> V_102 [ V_108 - 1 ] = '\0' ;
F_53 ( V_104 -> V_102 , '/' , '_' ) ;
V_2 = F_54 ( sizeof( * V_2 ) , V_109 ) ;
if ( ! V_2 )
return - V_110 ;
V_105 = - V_110 ;
V_2 -> V_61 = F_55 (unsigned long) ;
if ( ! V_2 -> V_61 )
goto V_111;
V_2 -> V_49 = F_56 ( V_50 , F_57 ( char ) ) ;
if ( ! V_2 -> V_49 )
goto V_111;
V_105 = - V_112 ;
F_58 ( & V_113 ) ;
if ( ! V_114 ) {
V_114 = F_59 ( L_3 , NULL ) ;
if ( ! V_114 ) {
F_60 ( & V_113 ) ;
goto V_111;
}
}
F_60 ( & V_113 ) ;
V_72 = F_59 ( V_104 -> V_102 , V_114 ) ;
if ( ! V_72 )
goto V_111;
V_2 -> V_72 = V_72 ;
V_2 -> V_26 = V_26 ;
F_61 ( & V_2 -> V_82 , 0 ) ;
F_62 ( & V_2 -> V_115 ) ;
V_105 = - V_116 ;
V_2 -> V_71 = F_50 ( L_4 , 0444 , V_72 , V_2 ,
& V_117 ) ;
if ( ! V_2 -> V_71 )
goto V_111;
V_2 -> V_70 = F_50 ( L_5 , 0222 , V_72 , V_2 , & V_118 ) ;
if ( ! V_2 -> V_70 )
goto V_111;
V_2 -> V_21 = F_63 ( L_6 , V_72 , V_104 -> V_106 ,
V_104 -> V_107 , & V_119 , V_2 ) ;
if ( ! V_2 -> V_21 )
goto V_111;
V_2 -> V_47 = V_104 -> V_47 ;
if ( ! V_2 -> V_47 )
V_2 -> V_47 = ( V_120 ) - 1 ;
F_51 ( V_2 , V_96 ) ;
if ( V_104 -> V_55 )
V_2 -> V_55 = V_104 -> V_55 ;
if ( V_104 -> V_56 )
V_2 -> V_56 = V_104 -> V_56 ;
V_2 -> V_3 = V_104 -> V_3 ;
V_2 -> V_45 = V_121 ;
V_105 = - V_122 ;
if ( F_64 ( & V_75 -> V_1 , NULL , V_2 ) )
goto V_111;
if ( F_65 ( & V_73 ) == 1 )
F_66 () ;
return 0 ;
V_111:
F_28 ( V_2 ) ;
return V_105 ;
}
int F_67 ( struct V_74 * V_75 , char * V_102 , T_10 V_26 ,
struct V_95 * V_96 ,
char T_7 * V_123 )
{
struct V_103 V_104 ;
int V_105 ;
V_105 = F_68 ( & V_104 , V_123 , sizeof( V_104 ) ) ;
if ( V_105 )
return - V_124 ;
V_105 = F_52 ( V_75 , V_102 , V_26 , V_96 , & V_104 ) ;
if ( V_105 )
return V_105 ;
if ( F_69 ( V_123 , & V_104 , sizeof( V_104 ) ) ) {
F_36 ( V_75 ) ;
return - V_124 ;
}
return 0 ;
}
static int F_70 ( struct V_74 * V_75 , char * V_102 ,
T_10 V_26 , struct V_95 * V_96 ,
char T_7 * V_123 )
{
struct V_103 V_104 ;
struct V_125 V_126 ;
int V_105 ;
if ( F_68 ( & V_126 , V_123 , sizeof( V_126 ) ) )
return - V_124 ;
V_104 = (struct V_103 ) {
. V_47 = V_126 . V_47 ,
. V_106 = V_126 . V_106 ,
. V_107 = V_126 . V_107 ,
. V_55 = V_126 . V_55 ,
. V_56 = V_126 . V_56 ,
. V_3 = V_126 . V_3 ,
} ;
V_105 = F_52 ( V_75 , V_102 , V_26 , V_96 , & V_104 ) ;
if ( V_105 )
return V_105 ;
if ( F_69 ( V_123 , & V_104 . V_102 , F_71 ( V_104 . V_102 ) ) ) {
F_36 ( V_75 ) ;
return - V_124 ;
}
return 0 ;
}
int F_72 ( struct V_74 * V_75 , int V_127 )
{
int V_105 ;
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 == NULL )
return - V_76 ;
V_105 = - V_76 ;
if ( V_127 ) {
if ( V_2 -> V_45 == V_121 ||
V_2 -> V_45 == V_128 ) {
V_32 ++ ;
F_73 () ;
V_2 -> V_45 = V_46 ;
F_74 ( & V_33 ) ;
F_75 ( & V_2 -> V_115 , & V_129 ) ;
F_76 ( & V_33 ) ;
F_14 ( V_2 ) ;
V_105 = 0 ;
}
} else {
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_45 = V_128 ;
F_74 ( & V_33 ) ;
F_77 ( & V_2 -> V_115 ) ;
F_76 ( & V_33 ) ;
F_78 ( V_2 -> V_21 ) ;
V_105 = 0 ;
}
}
return V_105 ;
}
int F_79 ( struct V_95 * V_96 , unsigned V_130 , char T_7 * V_123 )
{
struct V_74 * V_75 ;
int V_105 , V_127 = 0 ;
char V_131 [ V_132 ] ;
V_75 = F_80 ( V_96 ) ;
if ( ! V_75 )
return - V_133 ;
F_58 ( & V_96 -> V_134 ) ;
switch ( V_130 ) {
case V_135 :
F_81 ( V_96 , V_131 ) ;
V_105 = F_67 ( V_75 , V_131 , V_96 -> V_136 , V_96 , V_123 ) ;
break;
#if F_82 ( V_137 ) && F_82 ( V_138 )
case V_139 :
F_81 ( V_96 , V_131 ) ;
V_105 = F_70 ( V_75 , V_131 , V_96 -> V_136 , V_96 , V_123 ) ;
break;
#endif
case V_140 :
V_127 = 1 ;
case V_141 :
V_105 = F_72 ( V_75 , V_127 ) ;
break;
case V_142 :
V_105 = F_36 ( V_75 ) ;
break;
default:
V_105 = - V_143 ;
break;
}
F_60 ( & V_96 -> V_134 ) ;
return V_105 ;
}
void F_83 ( struct V_74 * V_75 )
{
if ( V_75 -> V_1 ) {
F_72 ( V_75 , 0 ) ;
F_36 ( V_75 ) ;
}
}
static void F_84 ( struct V_74 * V_75 , struct V_144 * V_145 ,
unsigned int V_146 , T_3 V_52 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( F_85 ( ! V_2 ) )
return;
if ( V_145 -> V_147 == V_148 ) {
V_52 |= F_86 ( V_149 ) ;
F_23 ( V_2 , 0 , V_146 , V_145 -> V_150 ,
V_52 , V_145 -> V_151 , V_145 -> V_152 , V_145 -> V_130 ) ;
} else {
V_52 |= F_86 ( V_153 ) ;
F_23 ( V_2 , F_87 ( V_145 ) , V_146 ,
V_145 -> V_150 , V_52 , V_145 -> V_151 , 0 , NULL ) ;
}
}
static void F_88 ( void * V_154 ,
struct V_74 * V_75 , struct V_144 * V_145 )
{
F_84 ( V_75 , V_145 , F_89 ( V_145 ) , V_155 ) ;
}
static void F_90 ( void * V_154 ,
struct V_74 * V_75 , struct V_144 * V_145 )
{
F_84 ( V_75 , V_145 , F_89 ( V_145 ) , V_156 ) ;
}
static void F_91 ( void * V_154 ,
struct V_74 * V_75 , struct V_144 * V_145 )
{
F_84 ( V_75 , V_145 , F_89 ( V_145 ) , V_157 ) ;
}
static void F_92 ( void * V_154 ,
struct V_74 * V_75 ,
struct V_144 * V_145 )
{
F_84 ( V_75 , V_145 , F_89 ( V_145 ) , V_158 ) ;
}
static void F_93 ( void * V_154 ,
struct V_74 * V_75 ,
struct V_144 * V_145 ,
unsigned int V_146 )
{
F_84 ( V_75 , V_145 , V_146 , V_159 ) ;
}
static void F_94 ( struct V_74 * V_75 , struct V_160 * V_160 ,
T_3 V_52 , int error )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( F_85 ( ! V_2 ) )
return;
F_23 ( V_2 , V_160 -> V_161 . V_162 , V_160 -> V_161 . V_163 ,
V_160 -> V_164 , V_52 , error , 0 , NULL ) ;
}
static void F_95 ( void * V_154 ,
struct V_74 * V_75 , struct V_160 * V_160 )
{
F_94 ( V_75 , V_160 , V_165 , 0 ) ;
}
static void F_96 ( void * V_154 ,
struct V_74 * V_75 , struct V_160 * V_160 ,
int error )
{
F_94 ( V_75 , V_160 , V_159 , error ) ;
}
static void F_97 ( void * V_154 ,
struct V_74 * V_75 ,
struct V_144 * V_145 ,
struct V_160 * V_160 )
{
F_94 ( V_75 , V_160 , V_166 , 0 ) ;
}
static void F_98 ( void * V_154 ,
struct V_74 * V_75 ,
struct V_144 * V_145 ,
struct V_160 * V_160 )
{
F_94 ( V_75 , V_160 , V_167 , 0 ) ;
}
static void F_99 ( void * V_154 ,
struct V_74 * V_75 , struct V_160 * V_160 )
{
F_94 ( V_75 , V_160 , V_168 , 0 ) ;
}
static void F_100 ( void * V_154 ,
struct V_74 * V_75 ,
struct V_160 * V_160 , int V_58 )
{
if ( V_160 )
F_94 ( V_75 , V_160 , V_169 , 0 ) ;
else {
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , V_58 , V_169 , 0 , 0 , NULL ) ;
}
}
static void F_101 ( void * V_154 ,
struct V_74 * V_75 ,
struct V_160 * V_160 , int V_58 )
{
if ( V_160 )
F_94 ( V_75 , V_160 , V_170 , 0 ) ;
else {
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , V_58 , V_170 ,
0 , 0 , NULL ) ;
}
}
static void F_102 ( void * V_154 , struct V_74 * V_75 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 )
F_23 ( V_2 , 0 , 0 , 0 , V_171 , 0 , 0 , NULL ) ;
}
static void F_103 ( void * V_154 , struct V_74 * V_75 ,
unsigned int V_172 , bool V_173 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 ) {
T_11 V_174 = F_104 ( V_172 ) ;
T_3 V_52 ;
if ( V_173 )
V_52 = V_175 ;
else
V_52 = V_176 ;
F_23 ( V_2 , 0 , 0 , 0 , V_52 , 0 , sizeof( V_174 ) , & V_174 ) ;
}
}
static void F_105 ( void * V_154 ,
struct V_74 * V_75 , struct V_160 * V_160 ,
unsigned int V_177 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( V_2 ) {
T_11 V_174 = F_104 ( V_177 ) ;
F_23 ( V_2 , V_160 -> V_161 . V_162 ,
V_160 -> V_161 . V_163 , V_160 -> V_164 , V_178 ,
V_160 -> V_179 , sizeof( V_174 ) , & V_174 ) ;
}
}
static void F_106 ( void * V_154 ,
struct V_74 * V_75 , struct V_160 * V_160 ,
T_10 V_26 , T_5 V_180 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
struct V_181 V_182 ;
if ( F_85 ( ! V_2 ) )
return;
V_182 . V_183 = F_107 ( V_26 ) ;
V_182 . V_184 = F_107 ( V_160 -> V_185 -> V_136 ) ;
V_182 . V_186 = F_104 ( V_180 ) ;
F_23 ( V_2 , V_160 -> V_161 . V_162 , V_160 -> V_161 . V_163 ,
V_160 -> V_164 , V_187 , V_160 -> V_179 ,
sizeof( V_182 ) , & V_182 ) ;
}
static void F_108 ( void * V_154 ,
struct V_74 * V_75 ,
struct V_144 * V_145 , T_10 V_26 ,
T_5 V_180 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
struct V_181 V_182 ;
if ( F_85 ( ! V_2 ) )
return;
V_182 . V_183 = F_107 ( V_26 ) ;
V_182 . V_184 = F_107 ( F_109 ( V_145 -> V_188 ) ) ;
V_182 . V_186 = F_104 ( V_180 ) ;
F_23 ( V_2 , F_87 ( V_145 ) , F_89 ( V_145 ) ,
F_110 ( V_145 ) , V_187 , ! ! V_145 -> V_151 ,
sizeof( V_182 ) , & V_182 ) ;
}
void F_111 ( struct V_74 * V_75 ,
struct V_144 * V_145 ,
void * V_5 , T_2 V_6 )
{
struct V_1 * V_2 = V_75 -> V_1 ;
if ( F_85 ( ! V_2 ) )
return;
if ( V_145 -> V_147 == V_148 )
F_23 ( V_2 , 0 , F_89 ( V_145 ) , 0 ,
V_189 , V_145 -> V_151 , V_6 , V_5 ) ;
else
F_23 ( V_2 , F_87 ( V_145 ) , F_89 ( V_145 ) , 0 ,
V_189 , V_145 -> V_151 , V_6 , V_5 ) ;
}
static void F_66 ( void )
{
int V_105 ;
V_105 = F_112 ( F_88 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_114 ( F_90 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_115 ( F_91 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_116 ( F_92 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_117 ( F_93 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_118 ( F_95 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_119 ( F_96 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_120 ( F_97 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_121 ( F_98 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_122 ( F_99 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_123 ( F_100 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_124 ( F_101 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_125 ( F_102 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_126 ( F_103 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_127 ( F_105 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_128 ( F_106 , NULL ) ;
F_113 ( V_105 ) ;
V_105 = F_129 ( F_108 , NULL ) ;
F_113 ( V_105 ) ;
}
static void F_35 ( void )
{
F_130 ( F_108 , NULL ) ;
F_131 ( F_106 , NULL ) ;
F_132 ( F_105 , NULL ) ;
F_133 ( F_103 , NULL ) ;
F_134 ( F_102 , NULL ) ;
F_135 ( F_101 , NULL ) ;
F_136 ( F_100 , NULL ) ;
F_137 ( F_99 , NULL ) ;
F_138 ( F_98 , NULL ) ;
F_139 ( F_97 , NULL ) ;
F_140 ( F_96 , NULL ) ;
F_141 ( F_95 , NULL ) ;
F_142 ( F_93 , NULL ) ;
F_143 ( F_92 , NULL ) ;
F_144 ( F_91 , NULL ) ;
F_145 ( F_90 , NULL ) ;
F_146 ( F_88 , NULL ) ;
F_147 () ;
}
static void F_148 ( char * V_190 , const struct V_7 * V_8 )
{
int V_191 = 0 ;
int V_192 = V_8 -> V_4 >> V_54 ;
if ( V_8 -> V_4 == V_51 ) {
V_190 [ V_191 ++ ] = 'N' ;
goto V_193;
}
if ( V_192 & V_194 )
V_190 [ V_191 ++ ] = 'F' ;
if ( V_192 & V_195 )
V_190 [ V_191 ++ ] = 'D' ;
else if ( V_192 & V_196 )
V_190 [ V_191 ++ ] = 'W' ;
else if ( V_8 -> V_57 )
V_190 [ V_191 ++ ] = 'R' ;
else
V_190 [ V_191 ++ ] = 'N' ;
if ( V_192 & V_197 )
V_190 [ V_191 ++ ] = 'F' ;
if ( V_192 & V_198 )
V_190 [ V_191 ++ ] = 'A' ;
if ( V_192 & V_199 )
V_190 [ V_191 ++ ] = 'S' ;
if ( V_192 & V_200 )
V_190 [ V_191 ++ ] = 'M' ;
V_193:
V_190 [ V_191 ] = '\0' ;
}
static inline
const struct V_7 * F_149 ( const struct V_201 * V_202 )
{
return ( const struct V_7 * ) V_202 ;
}
static inline const void * F_150 ( const struct V_201 * V_202 )
{
return F_149 ( V_202 ) + 1 ;
}
static inline T_3 F_151 ( const struct V_201 * V_202 )
{
return F_149 ( V_202 ) -> V_4 ;
}
static inline T_3 F_152 ( const struct V_201 * V_202 )
{
return F_149 ( V_202 ) -> V_57 ;
}
static inline T_3 F_153 ( const struct V_201 * V_202 )
{
return F_149 ( V_202 ) -> V_57 >> 9 ;
}
static inline unsigned long long F_154 ( const struct V_201 * V_202 )
{
return F_149 ( V_202 ) -> V_53 ;
}
static inline T_12 F_155 ( const struct V_201 * V_202 )
{
return F_149 ( V_202 ) -> error ;
}
static T_13 F_156 ( const struct V_201 * V_202 )
{
const T_13 * V_203 = F_150 ( V_202 ) ;
return F_157 ( * V_203 ) ;
}
static void F_158 ( const struct V_201 * V_202 ,
struct V_181 * V_182 )
{
const struct V_181 * V_204 = F_150 ( V_202 ) ;
T_13 V_186 = V_204 -> V_186 ;
V_182 -> V_183 = F_159 ( V_204 -> V_183 ) ;
V_182 -> V_184 = F_159 ( V_204 -> V_184 ) ;
V_182 -> V_186 = F_157 ( V_186 ) ;
}
static void F_160 ( struct V_205 * V_206 , const char * V_207 )
{
char V_190 [ V_208 ] ;
unsigned long long V_209 = V_206 -> V_209 ;
unsigned long V_210 = F_161 ( V_209 , V_211 ) ;
unsigned V_212 = ( unsigned long ) V_209 ;
const struct V_7 * V_8 = F_149 ( V_206 -> V_202 ) ;
F_148 ( V_190 , V_8 ) ;
F_162 ( & V_206 -> V_213 ,
L_7 ,
F_163 ( V_8 -> V_25 ) , F_164 ( V_8 -> V_25 ) , V_206 -> V_14 ,
V_212 , V_210 , V_206 -> V_202 -> V_3 , V_207 , V_190 ) ;
}
static void F_165 ( struct V_205 * V_206 , const char * V_207 )
{
char V_190 [ V_208 ] ;
const struct V_7 * V_8 = F_149 ( V_206 -> V_202 ) ;
F_148 ( V_190 , V_8 ) ;
F_162 ( & V_206 -> V_213 , L_8 ,
F_163 ( V_8 -> V_25 ) , F_164 ( V_8 -> V_25 ) , V_207 , V_190 ) ;
}
static void F_166 ( struct V_214 * V_215 , const struct V_201 * V_202 )
{
const unsigned char * V_216 ;
int V_27 ;
int V_191 , V_217 ;
V_216 = F_150 ( V_202 ) ;
V_27 = F_149 ( V_202 ) -> V_27 ;
if ( ! V_27 )
return;
for ( V_217 = V_27 - 1 ; V_217 >= 0 ; V_217 -- )
if ( V_216 [ V_217 ] )
break;
V_217 ++ ;
F_167 ( V_215 , '(' ) ;
for ( V_191 = 0 ; V_191 < V_27 ; V_191 ++ ) {
F_162 ( V_215 , L_9 ,
V_191 == 0 ? L_10 : L_11 , V_216 [ V_191 ] ) ;
if ( V_191 == V_217 && V_217 != V_27 - 1 ) {
F_168 ( V_215 , L_12 ) ;
return;
}
}
F_168 ( V_215 , L_13 ) ;
}
static void F_169 ( struct V_214 * V_215 , const struct V_201 * V_202 )
{
char V_130 [ V_218 ] ;
F_170 ( V_202 -> V_3 , V_130 ) ;
if ( F_151 ( V_202 ) & F_86 ( V_149 ) ) {
F_162 ( V_215 , L_14 , F_152 ( V_202 ) ) ;
F_166 ( V_215 , V_202 ) ;
F_162 ( V_215 , L_15 , V_130 ) ;
} else {
if ( F_153 ( V_202 ) )
F_162 ( V_215 , L_16 ,
F_154 ( V_202 ) , F_153 ( V_202 ) , V_130 ) ;
else
F_162 ( V_215 , L_15 , V_130 ) ;
}
}
static void F_171 ( struct V_214 * V_215 ,
const struct V_201 * V_202 )
{
if ( F_151 ( V_202 ) & F_86 ( V_149 ) ) {
F_166 ( V_215 , V_202 ) ;
F_162 ( V_215 , L_17 , F_155 ( V_202 ) ) ;
} else {
if ( F_153 ( V_202 ) )
F_162 ( V_215 , L_18 ,
F_154 ( V_202 ) ,
F_153 ( V_202 ) , F_155 ( V_202 ) ) ;
else
F_162 ( V_215 , L_19 ,
F_154 ( V_202 ) , F_155 ( V_202 ) ) ;
}
}
static void F_172 ( struct V_214 * V_215 , const struct V_201 * V_202 )
{
struct V_181 V_182 = { . V_183 = 0 , } ;
F_158 ( V_202 , & V_182 ) ;
F_162 ( V_215 , L_20 ,
F_154 ( V_202 ) , F_153 ( V_202 ) ,
F_163 ( V_182 . V_183 ) , F_164 ( V_182 . V_183 ) ,
( unsigned long long ) V_182 . V_186 ) ;
}
static void F_173 ( struct V_214 * V_215 , const struct V_201 * V_202 )
{
char V_130 [ V_218 ] ;
F_170 ( V_202 -> V_3 , V_130 ) ;
F_162 ( V_215 , L_15 , V_130 ) ;
}
static void F_174 ( struct V_214 * V_215 , const struct V_201 * V_202 )
{
char V_130 [ V_218 ] ;
F_170 ( V_202 -> V_3 , V_130 ) ;
F_162 ( V_215 , L_21 , V_130 , F_156 ( V_202 ) ) ;
}
static void F_175 ( struct V_214 * V_215 , const struct V_201 * V_202 )
{
char V_130 [ V_218 ] ;
F_170 ( V_202 -> V_3 , V_130 ) ;
F_162 ( V_215 , L_22 , F_154 ( V_202 ) ,
F_156 ( V_202 ) , V_130 ) ;
}
static void F_176 ( struct V_214 * V_215 , const struct V_201 * V_202 )
{
const struct V_7 * V_8 = F_149 ( V_202 ) ;
F_177 ( V_215 , V_8 + 1 , V_8 -> V_27 ) ;
F_167 ( V_215 , '\n' ) ;
}
static void F_178 ( struct V_219 * V_220 )
{
if ( ! ( V_221 . V_203 & V_222 ) )
return;
F_179 ( V_220 , L_23
L_24 ) ;
}
static void F_180 ( struct V_223 * V_224 )
{
V_16 = true ;
}
static int F_181 ( struct V_223 * V_224 )
{
V_17 = V_224 ;
F_180 ( V_224 ) ;
return 0 ;
}
static void F_182 ( struct V_223 * V_224 )
{
V_16 = false ;
}
static void F_183 ( struct V_223 * V_224 )
{
F_182 ( V_224 ) ;
}
static enum V_225 F_184 ( struct V_205 * V_206 ,
bool V_226 )
{
struct V_223 * V_224 = V_206 -> V_224 ;
struct V_214 * V_215 = & V_206 -> V_213 ;
const struct V_7 * V_8 ;
V_120 V_52 ;
bool V_227 ;
T_14 * V_228 ;
V_8 = F_149 ( V_206 -> V_202 ) ;
V_52 = V_8 -> V_4 & ( ( 1 << V_54 ) - 1 ) ;
V_227 = ! ! ( V_224 -> V_229 & V_230 ) ;
V_228 = V_226 ? & F_160 : & F_165 ;
if ( V_8 -> V_4 == V_51 ) {
V_228 ( V_206 , V_227 ? L_25 : L_26 ) ;
F_176 ( V_215 , V_206 -> V_202 ) ;
return F_185 ( V_215 ) ;
}
if ( F_19 ( V_52 == 0 || V_52 >= F_71 ( V_231 ) ) )
F_162 ( V_215 , L_27 , V_52 ) ;
else {
V_228 ( V_206 , V_231 [ V_52 ] . V_207 [ V_227 ] ) ;
V_231 [ V_52 ] . F_186 ( V_215 , V_206 -> V_202 ) ;
}
return F_185 ( V_215 ) ;
}
static enum V_225 F_187 ( struct V_205 * V_206 ,
int V_30 , struct V_232 * V_10 )
{
return F_184 ( V_206 , false ) ;
}
static void F_188 ( struct V_205 * V_206 )
{
struct V_214 * V_215 = & V_206 -> V_213 ;
struct V_7 * V_8 = (struct V_7 * ) V_206 -> V_202 ;
const int V_233 = F_189 ( struct V_7 , V_53 ) ;
struct V_7 V_234 = {
. V_22 = V_23 | V_24 ,
. time = V_206 -> V_209 ,
} ;
F_177 ( V_215 , & V_234 , V_233 ) ;
F_177 ( V_215 , & V_8 -> V_53 ,
sizeof( V_234 ) - V_233 + V_8 -> V_27 ) ;
}
static enum V_225
F_190 ( struct V_205 * V_206 , int V_30 ,
struct V_232 * V_10 )
{
F_188 ( V_206 ) ;
return F_185 ( & V_206 -> V_213 ) ;
}
static enum V_225 F_191 ( struct V_205 * V_206 )
{
if ( ! ( V_221 . V_203 & V_222 ) )
return V_235 ;
return F_184 ( V_206 , true ) ;
}
static int
F_192 ( struct V_223 * V_224 , T_3 V_236 , T_3 V_237 , int V_238 )
{
if ( V_237 == V_222 ) {
if ( V_238 )
V_224 -> V_229 &= ~ V_239 ;
else
V_224 -> V_229 |= V_239 ;
}
return 0 ;
}
static int T_15 F_193 ( void )
{
if ( ! F_194 ( & V_240 ) ) {
F_195 ( L_28 ) ;
return 1 ;
}
if ( F_196 ( & V_15 ) != 0 ) {
F_195 ( L_29 ) ;
F_197 ( & V_240 ) ;
return 1 ;
}
return 0 ;
}
static int F_198 ( struct V_74 * V_75 )
{
struct V_1 * V_2 ;
V_2 = F_37 ( & V_75 -> V_1 , NULL ) ;
if ( V_2 == NULL )
return - V_76 ;
if ( F_34 ( & V_73 ) )
F_35 () ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_199 ( struct V_74 * V_75 ,
struct V_95 * V_96 )
{
struct V_1 * V_2 = NULL ;
int V_105 = - V_110 ;
V_2 = F_54 ( sizeof( * V_2 ) , V_109 ) ;
if ( ! V_2 )
return - V_110 ;
V_2 -> V_49 = F_56 ( V_50 , F_57 ( char ) ) ;
if ( ! V_2 -> V_49 )
goto V_241;
V_2 -> V_26 = V_96 -> V_136 ;
V_2 -> V_47 = ( V_120 ) - 1 ;
F_51 ( V_2 , V_96 ) ;
V_105 = - V_122 ;
if ( F_64 ( & V_75 -> V_1 , NULL , V_2 ) )
goto V_241;
if ( F_65 ( & V_73 ) == 1 )
F_66 () ;
return 0 ;
V_241:
F_28 ( V_2 ) ;
return V_105 ;
}
static int F_200 ( const char * V_242 )
{
int V_191 ;
int V_243 = 0 ;
char * V_44 , * V_215 , * V_244 ;
V_44 = F_201 ( V_242 , V_109 ) ;
if ( V_44 == NULL )
return - V_110 ;
V_215 = F_202 ( V_44 ) ;
while ( 1 ) {
V_244 = F_203 ( & V_215 , L_30 ) ;
if ( V_244 == NULL )
break;
if ( * V_244 == '\0' )
continue;
for ( V_191 = 0 ; V_191 < F_71 ( V_245 ) ; V_191 ++ ) {
if ( strcasecmp ( V_244 , V_245 [ V_191 ] . V_242 ) == 0 ) {
V_243 |= V_245 [ V_191 ] . V_243 ;
break;
}
}
if ( V_191 == F_71 ( V_245 ) ) {
V_243 = - V_76 ;
break;
}
}
F_32 ( V_44 ) ;
return V_243 ;
}
static T_6 F_204 ( char * V_44 , int V_243 )
{
int V_191 ;
char * V_246 = V_44 ;
for ( V_191 = 0 ; V_191 < F_71 ( V_245 ) ; V_191 ++ ) {
if ( V_243 & V_245 [ V_191 ] . V_243 ) {
V_246 += sprintf ( V_246 , L_31 ,
( V_246 == V_44 ) ? L_10 : L_30 , V_245 [ V_191 ] . V_242 ) ;
}
}
* V_246 ++ = '\n' ;
return V_246 - V_44 ;
}
static struct V_74 * F_205 ( struct V_95 * V_96 )
{
if ( V_96 -> V_247 == NULL )
return NULL ;
return F_80 ( V_96 ) ;
}
static T_6 F_206 ( struct V_25 * V_26 ,
struct V_248 * V_249 ,
char * V_44 )
{
struct V_97 * V_246 = F_207 ( V_26 ) ;
struct V_74 * V_75 ;
struct V_95 * V_96 ;
T_6 V_105 = - V_133 ;
V_96 = F_208 ( F_209 ( V_246 ) ) ;
if ( V_96 == NULL )
goto V_193;
V_75 = F_205 ( V_96 ) ;
if ( V_75 == NULL )
goto V_250;
F_58 ( & V_96 -> V_134 ) ;
if ( V_249 == & V_251 ) {
V_105 = sprintf ( V_44 , L_1 , ! ! V_75 -> V_1 ) ;
goto V_252;
}
if ( V_75 -> V_1 == NULL )
V_105 = sprintf ( V_44 , L_32 ) ;
else if ( V_249 == & V_253 )
V_105 = F_204 ( V_44 , V_75 -> V_1 -> V_47 ) ;
else if ( V_249 == & V_254 )
V_105 = sprintf ( V_44 , L_1 , V_75 -> V_1 -> V_3 ) ;
else if ( V_249 == & V_255 )
V_105 = sprintf ( V_44 , L_33 , V_75 -> V_1 -> V_55 ) ;
else if ( V_249 == & V_256 )
V_105 = sprintf ( V_44 , L_33 , V_75 -> V_1 -> V_56 ) ;
V_252:
F_60 ( & V_96 -> V_134 ) ;
V_250:
F_210 ( V_96 ) ;
V_193:
return V_105 ;
}
static T_6 F_211 ( struct V_25 * V_26 ,
struct V_248 * V_249 ,
const char * V_44 , T_2 V_79 )
{
struct V_95 * V_96 ;
struct V_74 * V_75 ;
struct V_97 * V_246 ;
T_16 V_257 ;
T_6 V_105 = - V_76 ;
if ( V_79 == 0 )
goto V_193;
if ( V_249 == & V_253 ) {
if ( sscanf ( V_44 , L_34 , & V_257 ) != 1 ) {
V_105 = F_200 ( V_44 ) ;
if ( V_105 < 0 )
goto V_193;
V_257 = V_105 ;
}
} else if ( sscanf ( V_44 , L_35 , & V_257 ) != 1 )
goto V_193;
V_105 = - V_133 ;
V_246 = F_207 ( V_26 ) ;
V_96 = F_208 ( F_209 ( V_246 ) ) ;
if ( V_96 == NULL )
goto V_193;
V_75 = F_205 ( V_96 ) ;
if ( V_75 == NULL )
goto V_250;
F_58 ( & V_96 -> V_134 ) ;
if ( V_249 == & V_251 ) {
if ( V_257 )
V_105 = F_199 ( V_75 , V_96 ) ;
else
V_105 = F_198 ( V_75 ) ;
goto V_252;
}
V_105 = 0 ;
if ( V_75 -> V_1 == NULL )
V_105 = F_199 ( V_75 , V_96 ) ;
if ( V_105 == 0 ) {
if ( V_249 == & V_253 )
V_75 -> V_1 -> V_47 = V_257 ;
else if ( V_249 == & V_254 )
V_75 -> V_1 -> V_3 = V_257 ;
else if ( V_249 == & V_255 )
V_75 -> V_1 -> V_55 = V_257 ;
else if ( V_249 == & V_256 )
V_75 -> V_1 -> V_56 = V_257 ;
}
V_252:
F_60 ( & V_96 -> V_134 ) ;
V_250:
F_210 ( V_96 ) ;
V_193:
return V_105 ? V_105 : V_79 ;
}
int F_212 ( struct V_25 * V_26 )
{
return F_213 ( & V_26 -> V_258 , & V_259 ) ;
}
void F_214 ( struct V_25 * V_26 )
{
F_215 ( & V_26 -> V_258 , & V_259 ) ;
}
void F_216 ( char * V_44 , struct V_144 * V_145 )
{
int V_191 , V_217 ;
int V_6 = V_145 -> V_152 ;
unsigned char * V_130 = V_145 -> V_130 ;
if ( V_145 -> V_147 != V_148 ) {
V_44 [ 0 ] = '\0' ;
return;
}
for ( V_217 = V_6 - 1 ; V_217 >= 0 ; V_217 -- )
if ( V_130 [ V_217 ] )
break;
V_217 ++ ;
for ( V_191 = 0 ; V_191 < V_6 ; V_191 ++ ) {
V_44 += sprintf ( V_44 , L_9 , V_191 == 0 ? L_10 : L_11 , V_130 [ V_191 ] ) ;
if ( V_191 == V_217 && V_217 != V_6 - 1 ) {
sprintf ( V_44 , L_36 ) ;
break;
}
}
}
void F_217 ( char * V_190 , T_3 V_58 , int V_57 )
{
int V_191 = 0 ;
if ( V_58 & V_260 )
V_190 [ V_191 ++ ] = 'F' ;
if ( V_58 & V_63 )
V_190 [ V_191 ++ ] = 'W' ;
else if ( V_58 & V_261 )
V_190 [ V_191 ++ ] = 'D' ;
else if ( V_57 )
V_190 [ V_191 ++ ] = 'R' ;
else
V_190 [ V_191 ++ ] = 'N' ;
if ( V_58 & V_262 )
V_190 [ V_191 ++ ] = 'F' ;
if ( V_58 & V_263 )
V_190 [ V_191 ++ ] = 'A' ;
if ( V_58 & V_264 )
V_190 [ V_191 ++ ] = 'S' ;
if ( V_58 & V_265 )
V_190 [ V_191 ++ ] = 'M' ;
if ( V_58 & V_266 )
V_190 [ V_191 ++ ] = 'E' ;
V_190 [ V_191 ] = '\0' ;
}

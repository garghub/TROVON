int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 = - V_5 ;
F_2 ( L_1 , V_2 -> V_6 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_8 ) ;
F_5 (cl, &svc_xprt_class_list, xcl_list) {
if ( strcmp ( V_2 -> V_6 , V_3 -> V_6 ) == 0 )
goto V_9;
}
F_6 ( & V_2 -> V_7 , & V_10 ) ;
V_4 = 0 ;
V_9:
F_7 ( & V_8 ) ;
return V_4 ;
}
void F_8 ( struct V_1 * V_2 )
{
F_2 ( L_2 , V_2 -> V_6 ) ;
F_4 ( & V_8 ) ;
F_9 ( & V_2 -> V_7 ) ;
F_7 ( & V_8 ) ;
}
int F_10 ( char * V_11 , int V_12 )
{
struct V_1 * V_2 ;
char V_13 [ 80 ] ;
int V_14 = 0 ;
V_11 [ 0 ] = '\0' ;
F_4 ( & V_8 ) ;
F_5 (xcl, &svc_xprt_class_list, xcl_list) {
int V_15 ;
sprintf ( V_13 , L_3 , V_2 -> V_6 , V_2 -> V_16 ) ;
V_15 = strlen ( V_13 ) ;
if ( V_14 + V_15 > V_12 )
break;
V_14 += V_15 ;
strcat ( V_11 , V_13 ) ;
}
F_7 ( & V_8 ) ;
return V_14 ;
}
static void F_11 ( struct V_17 * V_17 )
{
struct V_18 * V_19 =
F_12 ( V_17 , struct V_18 , V_20 ) ;
struct V_21 * V_22 = V_19 -> V_23 -> V_24 ;
if ( F_13 ( V_25 , & V_19 -> V_26 ) )
F_14 ( V_19 ) ;
F_15 ( V_19 -> V_27 ) ;
if ( V_19 -> V_28 )
F_16 ( V_19 -> V_28 ) ;
V_19 -> V_29 -> V_30 ( V_19 ) ;
F_17 ( V_22 ) ;
}
void F_18 ( struct V_18 * V_19 )
{
F_19 ( & V_19 -> V_20 , F_11 ) ;
}
void F_20 ( struct V_31 * V_31 , struct V_1 * V_2 ,
struct V_18 * V_19 , struct V_32 * V_33 )
{
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_23 = V_2 ;
V_19 -> V_29 = V_2 -> V_34 ;
F_21 ( & V_19 -> V_20 ) ;
V_19 -> V_35 = V_33 ;
F_3 ( & V_19 -> V_36 ) ;
F_3 ( & V_19 -> V_37 ) ;
F_3 ( & V_19 -> V_38 ) ;
F_3 ( & V_19 -> V_39 ) ;
F_22 ( & V_19 -> V_40 ) ;
F_23 ( & V_19 -> V_41 ) ;
F_24 ( V_42 , & V_19 -> V_26 ) ;
F_25 ( & V_19 -> V_43 , L_4 ) ;
V_19 -> V_27 = F_26 ( V_31 ) ;
}
static struct V_18 * F_27 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_31 * V_31 ,
const int V_44 ,
const unsigned short V_45 ,
int V_46 )
{
struct V_47 sin = {
. V_48 = V_49 ,
. V_50 . V_51 = F_28 ( V_52 ) ,
. V_53 = F_29 ( V_45 ) ,
} ;
#if F_30 ( V_54 )
struct V_55 V_56 = {
. V_57 = V_58 ,
. V_59 = V_60 ,
. V_61 = F_29 ( V_45 ) ,
} ;
#endif
struct V_62 * V_63 ;
T_1 V_14 ;
switch ( V_44 ) {
case V_64 :
V_63 = (struct V_62 * ) & sin ;
V_14 = sizeof( sin ) ;
break;
#if F_30 ( V_54 )
case V_65 :
V_63 = (struct V_62 * ) & V_56 ;
V_14 = sizeof( V_56 ) ;
break;
#endif
default:
return F_31 ( - V_66 ) ;
}
return V_2 -> V_34 -> V_67 ( V_33 , V_31 , V_63 , V_14 , V_46 ) ;
}
static void F_32 ( struct V_18 * V_19 )
{
if ( ! F_13 ( V_42 , & V_19 -> V_26 ) ) {
F_33 ( 1 , L_5 , V_19 ) ;
return;
}
F_34 ( V_19 ) ;
F_35 () ;
F_36 ( V_42 , & V_19 -> V_26 ) ;
V_19 -> V_35 -> V_68 -> V_69 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_37 ( struct V_32 * V_33 , struct V_18 * V_70 )
{
F_36 ( V_71 , & V_70 -> V_26 ) ;
F_38 ( & V_33 -> V_72 ) ;
F_39 ( & V_70 -> V_36 , & V_33 -> V_73 ) ;
F_40 ( & V_33 -> V_72 ) ;
F_32 ( V_70 ) ;
}
int F_41 ( struct V_32 * V_33 , const char * V_74 ,
struct V_31 * V_31 , const int V_44 ,
const unsigned short V_45 , int V_46 )
{
struct V_1 * V_2 ;
F_2 ( L_6 , V_74 , V_45 ) ;
F_4 ( & V_8 ) ;
F_5 (xcl, &svc_xprt_class_list, xcl_list) {
struct V_18 * V_75 ;
unsigned short V_76 ;
if ( strcmp ( V_74 , V_2 -> V_6 ) )
continue;
if ( ! F_42 ( V_2 -> V_24 ) )
goto V_77;
F_7 ( & V_8 ) ;
V_75 = F_27 ( V_2 , V_33 , V_31 , V_44 , V_45 , V_46 ) ;
if ( F_43 ( V_75 ) ) {
F_17 ( V_2 -> V_24 ) ;
return F_44 ( V_75 ) ;
}
F_37 ( V_33 , V_75 ) ;
V_76 = F_45 ( V_75 ) ;
return V_76 ;
}
V_77:
F_7 ( & V_8 ) ;
F_2 ( L_7 , V_74 ) ;
return - V_78 ;
}
void F_46 ( struct V_79 * V_80 , struct V_18 * V_19 )
{
memcpy ( & V_80 -> V_81 , & V_19 -> V_82 , V_19 -> V_83 ) ;
V_80 -> V_84 = V_19 -> V_83 ;
memcpy ( & V_80 -> V_85 , & V_19 -> V_86 , V_19 -> V_87 ) ;
V_80 -> V_88 = V_19 -> V_87 ;
}
char * F_47 ( struct V_79 * V_80 , char * V_11 , T_1 V_14 )
{
return F_48 ( F_49 ( V_80 ) , V_11 , V_14 ) ;
}
static bool F_50 ( struct V_18 * V_19 )
{
if ( V_19 -> V_26 & ( ( 1 << V_89 ) | ( 1 << V_90 ) ) )
return true ;
if ( V_19 -> V_26 & ( ( 1 << V_91 ) | ( 1 << V_92 ) ) )
return V_19 -> V_29 -> V_93 ( V_19 ) ;
return false ;
}
void F_51 ( struct V_18 * V_19 )
{
struct V_94 * V_95 ;
struct V_79 * V_80 = NULL ;
int V_96 ;
bool V_97 = false ;
if ( ! F_50 ( V_19 ) )
goto V_9;
if ( F_52 ( V_42 , & V_19 -> V_26 ) ) {
F_2 ( L_8 , V_19 ) ;
goto V_9;
}
V_96 = F_53 () ;
V_95 = F_54 ( V_19 -> V_35 , V_96 ) ;
F_55 ( & V_95 -> V_98 . V_99 ) ;
V_100:
F_56 () ;
F_57 (rqstp, &pool->sp_all_threads, rq_all) {
if ( F_13 ( V_101 , & V_80 -> V_102 ) )
continue;
if ( ! V_97 ) {
F_38 ( & V_80 -> V_103 ) ;
if ( F_52 ( V_101 , & V_80 -> V_102 ) ) {
F_40 ( & V_80 -> V_103 ) ;
continue;
}
V_80 -> V_104 = V_19 ;
F_34 ( V_19 ) ;
F_40 ( & V_80 -> V_103 ) ;
}
F_58 () ;
F_55 ( & V_95 -> V_98 . V_105 ) ;
F_59 ( V_80 -> V_106 ) ;
F_60 () ;
goto V_9;
}
F_58 () ;
if ( ! V_97 ) {
V_97 = true ;
F_2 ( L_9 , V_19 ) ;
F_38 ( & V_95 -> V_107 ) ;
F_6 ( & V_19 -> V_37 , & V_95 -> V_108 ) ;
V_95 -> V_98 . V_109 ++ ;
F_40 ( & V_95 -> V_107 ) ;
goto V_100;
}
V_80 = NULL ;
F_60 () ;
V_9:
F_61 ( V_19 , V_80 ) ;
}
void F_62 ( struct V_18 * V_19 )
{
if ( F_13 ( V_42 , & V_19 -> V_26 ) )
return;
V_19 -> V_35 -> V_68 -> V_69 ( V_19 ) ;
}
static struct V_18 * F_63 ( struct V_94 * V_95 )
{
struct V_18 * V_19 = NULL ;
if ( F_64 ( & V_95 -> V_108 ) )
goto V_9;
F_38 ( & V_95 -> V_107 ) ;
if ( F_65 ( ! F_64 ( & V_95 -> V_108 ) ) ) {
V_19 = F_66 ( & V_95 -> V_108 ,
struct V_18 , V_37 ) ;
F_9 ( & V_19 -> V_37 ) ;
F_34 ( V_19 ) ;
F_2 ( L_10 ,
V_19 , F_67 ( & V_19 -> V_20 . V_110 ) ) ;
}
F_40 ( & V_95 -> V_107 ) ;
V_9:
F_68 ( V_19 ) ;
return V_19 ;
}
void F_69 ( struct V_79 * V_80 , int V_111 )
{
V_111 += V_80 -> V_112 . V_113 [ 0 ] . V_114 ;
if ( V_111 < V_80 -> V_115 ) {
struct V_18 * V_19 = V_80 -> V_104 ;
F_70 ( ( V_80 -> V_115 - V_111 ) , & V_19 -> V_116 ) ;
V_80 -> V_115 = V_111 ;
if ( V_19 -> V_29 -> V_117 )
V_19 -> V_29 -> V_117 ( V_19 ) ;
F_62 ( V_19 ) ;
}
}
static void F_71 ( struct V_79 * V_80 )
{
struct V_18 * V_19 = V_80 -> V_104 ;
V_80 -> V_104 -> V_29 -> V_118 ( V_80 ) ;
F_72 ( V_80 -> V_119 ) ;
V_80 -> V_119 = NULL ;
F_73 ( V_80 ) ;
V_80 -> V_112 . V_120 = 0 ;
V_80 -> V_112 . V_121 = 0 ;
if ( ( V_80 -> V_112 . V_14 ) > V_80 -> V_115 )
F_74 ( V_122 L_11 ,
V_80 -> V_115 ,
V_80 -> V_112 . V_14 ) ;
V_80 -> V_112 . V_113 [ 0 ] . V_114 = 0 ;
F_69 ( V_80 , 0 ) ;
V_80 -> V_104 = NULL ;
F_18 ( V_19 ) ;
}
void F_75 ( struct V_32 * V_33 )
{
struct V_79 * V_80 ;
struct V_94 * V_95 ;
V_95 = & V_33 -> V_123 [ 0 ] ;
F_56 () ;
F_57 (rqstp, &pool->sp_all_threads, rq_all) {
if ( F_13 ( V_101 , & V_80 -> V_102 ) )
continue;
F_58 () ;
F_2 ( L_12 , V_80 ) ;
F_59 ( V_80 -> V_106 ) ;
F_76 ( V_80 -> V_106 -> V_124 ) ;
return;
}
F_58 () ;
F_24 ( V_125 , & V_95 -> V_126 ) ;
F_77 () ;
F_76 ( 0 ) ;
}
int F_78 ( struct V_62 * sin )
{
switch ( sin -> V_127 ) {
case V_49 :
return F_79 ( ( (struct V_47 * ) sin ) -> V_53 )
< V_128 ;
case V_58 :
return F_79 ( ( (struct V_55 * ) sin ) -> V_61 )
< V_128 ;
default:
return 0 ;
}
}
static void F_80 ( struct V_32 * V_33 )
{
unsigned int V_129 = V_33 -> V_130 ? V_33 -> V_130 :
( V_33 -> V_131 + 3 ) * 20 ;
if ( V_33 -> V_132 > V_129 ) {
struct V_18 * V_19 = NULL ;
F_38 ( & V_33 -> V_72 ) ;
if ( ! F_64 ( & V_33 -> V_133 ) ) {
F_81 ( L_13 ,
V_33 -> V_134 , V_33 -> V_130 ?
L_14 :
L_15 ) ;
V_19 = F_82 ( V_33 -> V_133 . V_135 ,
struct V_18 ,
V_36 ) ;
F_24 ( V_90 , & V_19 -> V_26 ) ;
F_34 ( V_19 ) ;
}
F_40 ( & V_33 -> V_72 ) ;
if ( V_19 ) {
F_62 ( V_19 ) ;
F_18 ( V_19 ) ;
}
}
}
static int F_83 ( struct V_79 * V_80 )
{
struct V_32 * V_33 = V_80 -> V_136 ;
struct V_137 * V_138 ;
int V_139 ;
int V_140 ;
V_139 = ( V_33 -> V_141 + V_142 ) / V_142 ;
F_84 ( V_139 >= V_143 ) ;
if ( V_139 >= V_143 )
V_139 = V_143 - 1 ;
for ( V_140 = 0 ; V_140 < V_139 ; V_140 ++ )
while ( V_80 -> V_144 [ V_140 ] == NULL ) {
struct V_145 * V_146 = F_85 ( V_147 ) ;
if ( ! V_146 ) {
F_86 ( V_148 ) ;
if ( F_87 () || F_88 () ) {
F_86 ( V_149 ) ;
return - V_150 ;
}
F_89 ( F_90 ( 500 ) ) ;
}
V_80 -> V_144 [ V_140 ] = V_146 ;
}
V_80 -> V_151 = & V_80 -> V_144 [ V_140 ] ;
V_80 -> V_144 [ V_140 ++ ] = NULL ;
V_138 = & V_80 -> V_152 ;
V_138 -> V_113 [ 0 ] . V_153 = F_91 ( V_80 -> V_144 [ 0 ] ) ;
V_138 -> V_113 [ 0 ] . V_114 = V_142 ;
V_138 -> V_139 = V_80 -> V_144 + 1 ;
V_138 -> V_121 = 0 ;
V_138 -> V_120 = ( V_139 - 2 ) * V_142 ;
V_138 -> V_14 = ( V_139 - 1 ) * V_142 ;
V_138 -> V_154 [ 0 ] . V_114 = 0 ;
return 0 ;
}
static bool
F_92 ( struct V_79 * V_80 )
{
struct V_94 * V_95 = V_80 -> V_155 ;
if ( F_93 ( V_125 , & V_95 -> V_126 ) )
return false ;
if ( ! F_64 ( & V_95 -> V_108 ) )
return false ;
if ( F_87 () || F_88 () )
return false ;
if ( F_94 ( V_156 ) )
return false ;
return true ;
}
static struct V_18 * F_95 ( struct V_79 * V_80 , long V_157 )
{
struct V_18 * V_19 ;
struct V_94 * V_95 = V_80 -> V_155 ;
long V_158 = 0 ;
F_84 ( V_80 -> V_104 ) ;
V_80 -> V_159 . V_160 = 5 * V_161 ;
V_19 = F_63 ( V_95 ) ;
if ( V_19 ) {
V_80 -> V_104 = V_19 ;
V_80 -> V_159 . V_160 = 1 * V_161 ;
F_36 ( V_125 , & V_95 -> V_126 ) ;
return V_19 ;
}
F_86 ( V_148 ) ;
F_36 ( V_101 , & V_80 -> V_102 ) ;
F_96 () ;
if ( F_65 ( F_92 ( V_80 ) ) )
V_158 = F_89 ( V_157 ) ;
else
F_97 ( V_149 ) ;
F_98 () ;
F_38 ( & V_80 -> V_103 ) ;
F_24 ( V_101 , & V_80 -> V_102 ) ;
F_40 ( & V_80 -> V_103 ) ;
V_19 = V_80 -> V_104 ;
if ( V_19 != NULL )
return V_19 ;
if ( ! V_158 )
F_55 ( & V_95 -> V_98 . V_162 ) ;
if ( F_87 () || F_88 () )
return F_31 ( - V_150 ) ;
return F_31 ( - V_163 ) ;
}
static void F_99 ( struct V_32 * V_33 , struct V_18 * V_164 )
{
F_38 ( & V_33 -> V_72 ) ;
F_24 ( V_71 , & V_164 -> V_26 ) ;
F_39 ( & V_164 -> V_36 , & V_33 -> V_133 ) ;
V_33 -> V_132 ++ ;
if ( V_33 -> V_165 . V_166 == NULL ) {
F_100 ( & V_33 -> V_165 , V_167 ,
( unsigned long ) V_33 ) ;
F_101 ( & V_33 -> V_165 ,
V_168 + V_169 * V_161 ) ;
}
F_40 ( & V_33 -> V_72 ) ;
F_32 ( V_164 ) ;
}
static int F_102 ( struct V_79 * V_80 , struct V_18 * V_19 )
{
struct V_32 * V_33 = V_80 -> V_136 ;
int V_14 = 0 ;
if ( F_13 ( V_90 , & V_19 -> V_26 ) ) {
F_2 ( L_16 ) ;
F_103 ( V_19 ) ;
goto V_9;
}
if ( F_13 ( V_170 , & V_19 -> V_26 ) ) {
struct V_18 * V_164 ;
F_104 ( V_19 -> V_23 -> V_24 ) ;
F_80 ( V_19 -> V_35 ) ;
V_164 = V_19 -> V_29 -> V_171 ( V_19 ) ;
if ( V_164 )
F_99 ( V_33 , V_164 ) ;
else
F_17 ( V_19 -> V_23 -> V_24 ) ;
} else {
F_2 ( L_17 ,
V_80 , V_80 -> V_155 -> V_172 , V_19 ,
F_67 ( & V_19 -> V_20 . V_110 ) ) ;
V_80 -> V_119 = F_105 ( V_19 ) ;
if ( V_80 -> V_119 )
V_14 = F_106 ( V_80 ) ;
else
V_14 = V_19 -> V_29 -> V_173 ( V_80 ) ;
F_2 ( L_18 , V_14 ) ;
V_80 -> V_115 = V_33 -> V_141 ;
F_107 ( V_80 -> V_115 , & V_19 -> V_116 ) ;
}
F_32 ( V_19 ) ;
V_9:
F_108 ( V_19 , V_14 ) ;
return V_14 ;
}
int F_109 ( struct V_79 * V_80 , long V_157 )
{
struct V_18 * V_19 = NULL ;
struct V_32 * V_33 = V_80 -> V_136 ;
int V_14 , V_77 ;
F_2 ( L_19 ,
V_80 , V_157 ) ;
if ( V_80 -> V_104 )
F_74 ( V_122
L_20 ,
V_80 ) ;
V_77 = F_83 ( V_80 ) ;
if ( V_77 )
goto V_9;
F_98 () ;
F_110 () ;
V_77 = - V_150 ;
if ( F_87 () || F_88 () )
goto V_9;
V_19 = F_95 ( V_80 , V_157 ) ;
if ( F_43 ( V_19 ) ) {
V_77 = F_44 ( V_19 ) ;
goto V_9;
}
V_14 = F_102 ( V_80 , V_19 ) ;
V_77 = - V_163 ;
if ( V_14 <= 0 )
goto V_174;
F_36 ( V_175 , & V_19 -> V_26 ) ;
if ( V_19 -> V_29 -> V_176 ( V_80 ) )
F_24 ( V_177 , & V_80 -> V_102 ) ;
else
F_36 ( V_177 , & V_80 -> V_102 ) ;
V_80 -> V_159 . V_178 = V_179 ;
V_80 -> V_180 = F_111 ( & V_80 -> V_152 . V_113 [ 0 ] ) ;
if ( V_33 -> V_181 )
V_33 -> V_181 -> V_182 ++ ;
F_112 ( V_80 , V_14 ) ;
return V_14 ;
V_174:
V_80 -> V_112 . V_14 = 0 ;
F_71 ( V_80 ) ;
V_9:
F_112 ( V_80 , V_77 ) ;
return V_77 ;
}
void F_113 ( struct V_79 * V_80 )
{
F_2 ( L_21 , V_80 -> V_104 ) ;
F_71 ( V_80 ) ;
}
int F_114 ( struct V_79 * V_80 )
{
struct V_18 * V_19 ;
int V_14 = - V_183 ;
struct V_137 * V_184 ;
V_19 = V_80 -> V_104 ;
if ( ! V_19 )
goto V_9;
V_80 -> V_104 -> V_29 -> V_118 ( V_80 ) ;
V_184 = & V_80 -> V_112 ;
V_184 -> V_14 = V_184 -> V_113 [ 0 ] . V_114 +
V_184 -> V_120 +
V_184 -> V_154 [ 0 ] . V_114 ;
F_115 ( & V_19 -> V_40 ) ;
if ( F_13 ( V_185 , & V_19 -> V_26 )
|| F_13 ( V_90 , & V_19 -> V_26 ) )
V_14 = - V_186 ;
else
V_14 = V_19 -> V_29 -> V_187 ( V_80 ) ;
F_116 ( & V_19 -> V_40 ) ;
F_117 ( & V_19 -> V_43 ) ;
F_71 ( V_80 ) ;
if ( V_14 == - V_188 || V_14 == - V_186 || V_14 == - V_163 )
V_14 = 0 ;
V_9:
F_118 ( V_80 , V_14 ) ;
return V_14 ;
}
static void V_167 ( unsigned long V_189 )
{
struct V_32 * V_33 = (struct V_32 * ) V_189 ;
struct V_18 * V_19 ;
struct V_190 * V_191 , * V_192 ;
F_2 ( L_22 ) ;
if ( ! F_119 ( & V_33 -> V_72 ) ) {
F_2 ( L_23 ) ;
F_101 ( & V_33 -> V_165 , V_168 + V_161 ) ;
return;
}
F_120 (le, next, &serv->sv_tempsocks) {
V_19 = F_82 ( V_191 , struct V_18 , V_36 ) ;
if ( ! F_52 ( V_175 , & V_19 -> V_26 ) )
continue;
if ( F_67 ( & V_19 -> V_20 . V_110 ) > 1 ||
F_13 ( V_42 , & V_19 -> V_26 ) )
continue;
F_9 ( V_191 ) ;
F_24 ( V_90 , & V_19 -> V_26 ) ;
F_2 ( L_24 , V_19 ) ;
F_62 ( V_19 ) ;
}
F_40 ( & V_33 -> V_72 ) ;
F_101 ( & V_33 -> V_165 , V_168 + V_169 * V_161 ) ;
}
void F_121 ( struct V_32 * V_33 , struct V_62 * V_193 )
{
struct V_18 * V_19 ;
struct V_194 * V_195 ;
struct V_196 * V_197 ;
struct V_190 * V_191 , * V_192 ;
F_122 ( V_198 ) ;
struct V_199 V_200 = {
. V_201 = 1 ,
. V_202 = 0 ,
} ;
F_38 ( & V_33 -> V_72 ) ;
F_120 (le, next, &serv->sv_tempsocks) {
V_19 = F_82 ( V_191 , struct V_18 , V_36 ) ;
if ( F_123 ( V_193 , (struct V_62 * )
& V_19 -> V_86 ) ) {
F_2 ( L_25 , V_19 ) ;
F_124 ( V_191 , & V_198 ) ;
}
}
F_40 ( & V_33 -> V_72 ) ;
while ( ! F_64 ( & V_198 ) ) {
V_191 = V_198 . V_192 ;
F_9 ( V_191 ) ;
V_19 = F_82 ( V_191 , struct V_18 , V_36 ) ;
F_2 ( L_26 , V_19 ) ;
V_195 = F_12 ( V_19 , struct V_194 , V_203 ) ;
V_197 = V_195 -> V_204 ;
F_125 ( V_197 , V_205 , V_206 ,
( char * ) & V_200 , sizeof( V_200 ) ) ;
F_126 ( V_19 ) ;
}
}
static void F_127 ( struct V_18 * V_19 )
{
struct V_207 * V_208 ;
F_4 ( & V_19 -> V_41 ) ;
while ( ! F_64 ( & V_19 -> V_39 ) ) {
V_208 = F_66 ( & V_19 -> V_39 , struct V_207 , V_209 ) ;
F_128 ( & V_208 -> V_209 ) ;
V_208 -> V_210 ( V_208 ) ;
}
F_7 ( & V_19 -> V_41 ) ;
}
static void F_103 ( struct V_18 * V_19 )
{
struct V_32 * V_33 = V_19 -> V_35 ;
struct V_211 * V_212 ;
if ( F_52 ( V_185 , & V_19 -> V_26 ) )
F_129 () ;
F_2 ( L_27 , V_19 ) ;
V_19 -> V_29 -> V_213 ( V_19 ) ;
F_38 ( & V_33 -> V_72 ) ;
F_9 ( & V_19 -> V_36 ) ;
F_84 ( ! F_64 ( & V_19 -> V_37 ) ) ;
if ( F_13 ( V_71 , & V_19 -> V_26 ) )
V_33 -> V_132 -- ;
F_40 ( & V_33 -> V_72 ) ;
while ( ( V_212 = F_105 ( V_19 ) ) != NULL )
F_72 ( V_212 ) ;
F_127 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_126 ( struct V_18 * V_19 )
{
F_24 ( V_90 , & V_19 -> V_26 ) ;
if ( F_52 ( V_42 , & V_19 -> V_26 ) )
return;
F_103 ( V_19 ) ;
}
static int F_130 ( struct V_32 * V_33 , struct V_190 * V_214 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
int V_215 = 0 ;
F_4 ( & V_33 -> V_72 ) ;
F_5 (xprt, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
V_215 ++ ;
F_24 ( V_90 , & V_19 -> V_26 ) ;
F_62 ( V_19 ) ;
}
F_7 ( & V_33 -> V_72 ) ;
return V_215 ;
}
static struct V_18 * F_131 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
struct V_94 * V_95 ;
struct V_18 * V_19 ;
struct V_18 * V_216 ;
int V_140 ;
for ( V_140 = 0 ; V_140 < V_33 -> V_217 ; V_140 ++ ) {
V_95 = & V_33 -> V_123 [ V_140 ] ;
F_38 ( & V_95 -> V_107 ) ;
F_132 (xprt, tmp, &pool->sp_sockets, xpt_ready) {
if ( V_19 -> V_27 != V_31 )
continue;
F_9 ( & V_19 -> V_37 ) ;
F_40 ( & V_95 -> V_107 ) ;
return V_19 ;
}
F_40 ( & V_95 -> V_107 ) ;
}
return NULL ;
}
static void F_133 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
while ( ( V_19 = F_131 ( V_33 , V_31 ) ) ) {
F_24 ( V_90 , & V_19 -> V_26 ) ;
F_103 ( V_19 ) ;
}
}
void F_134 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
int V_218 = 0 ;
while ( F_130 ( V_33 , & V_33 -> V_73 , V_31 ) +
F_130 ( V_33 , & V_33 -> V_133 , V_31 ) ) {
F_133 ( V_33 , V_31 ) ;
F_135 ( V_218 ++ ) ;
}
}
static void F_136 ( struct V_219 * V_220 , int V_221 )
{
struct V_211 * V_212 =
F_12 ( V_220 , struct V_211 , V_222 ) ;
struct V_18 * V_19 = V_212 -> V_19 ;
F_4 ( & V_19 -> V_41 ) ;
F_24 ( V_92 , & V_19 -> V_26 ) ;
if ( V_221 || F_13 ( V_185 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_41 ) ;
F_2 ( L_28 ) ;
F_18 ( V_19 ) ;
F_72 ( V_212 ) ;
return;
}
F_2 ( L_29 ) ;
V_212 -> V_19 = NULL ;
F_39 ( & V_212 -> V_222 . V_223 , & V_19 -> V_38 ) ;
F_7 ( & V_19 -> V_41 ) ;
F_62 ( V_19 ) ;
F_18 ( V_19 ) ;
}
static struct V_219 * V_179 ( struct V_224 * V_225 )
{
struct V_79 * V_80 = F_12 ( V_225 , struct V_79 , V_159 ) ;
struct V_211 * V_212 ;
if ( V_80 -> V_152 . V_120 || ! F_13 ( V_226 , & V_80 -> V_102 ) )
return NULL ;
if ( V_80 -> V_119 ) {
V_212 = V_80 -> V_119 ;
V_80 -> V_119 = NULL ;
} else {
T_1 V_227 ;
T_1 V_228 ;
V_228 = sizeof( struct V_211 ) + V_80 -> V_152 . V_14 ;
V_212 = F_137 ( V_228 , V_147 ) ;
if ( V_212 == NULL )
return NULL ;
V_212 -> V_222 . V_22 = V_80 -> V_136 ;
V_212 -> V_229 = V_80 -> V_230 ;
memcpy ( & V_212 -> V_231 , & V_80 -> V_81 , V_80 -> V_84 ) ;
V_212 -> V_232 = V_80 -> V_84 ;
V_212 -> V_233 = V_80 -> V_85 ;
V_212 -> V_234 = V_80 -> V_152 . V_14 >> 2 ;
V_212 -> V_235 = V_80 -> V_236 ;
V_227 = V_80 -> V_152 . V_14 - V_80 -> V_152 . V_113 [ 0 ] . V_114 ;
memcpy ( V_212 -> args , V_80 -> V_152 . V_113 [ 0 ] . V_153 - V_227 ,
V_212 -> V_234 << 2 ) ;
}
F_34 ( V_80 -> V_104 ) ;
V_212 -> V_19 = V_80 -> V_104 ;
F_24 ( V_237 , & V_80 -> V_102 ) ;
V_212 -> V_222 . V_238 = F_136 ;
return & V_212 -> V_222 ;
}
static int F_106 ( struct V_79 * V_80 )
{
struct V_211 * V_212 = V_80 -> V_119 ;
V_80 -> V_152 . V_113 [ 0 ] . V_153 = V_212 -> args + ( V_212 -> V_235 >> 2 ) ;
V_80 -> V_152 . V_113 [ 0 ] . V_114 = ( V_212 -> V_234 << 2 ) - V_212 -> V_235 ;
V_80 -> V_152 . V_120 = 0 ;
V_80 -> V_152 . V_14 = V_212 -> V_234 << 2 ;
V_80 -> V_230 = V_212 -> V_229 ;
memcpy ( & V_80 -> V_81 , & V_212 -> V_231 , V_212 -> V_232 ) ;
V_80 -> V_84 = V_212 -> V_232 ;
V_80 -> V_236 = V_212 -> V_235 ;
V_80 -> V_85 = V_212 -> V_233 ;
V_80 -> V_239 = V_80 -> V_144 ;
return ( V_212 -> V_234 << 2 ) - V_212 -> V_235 ;
}
static struct V_211 * F_105 ( struct V_18 * V_19 )
{
struct V_211 * V_212 = NULL ;
if ( ! F_13 ( V_92 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_41 ) ;
if ( ! F_64 ( & V_19 -> V_38 ) ) {
V_212 = F_82 ( V_19 -> V_38 . V_192 ,
struct V_211 ,
V_222 . V_223 ) ;
F_9 ( & V_212 -> V_222 . V_223 ) ;
} else
F_36 ( V_92 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_41 ) ;
return V_212 ;
}
struct V_18 * F_138 ( struct V_32 * V_33 , const char * V_6 ,
struct V_31 * V_31 , const T_2 V_240 ,
const unsigned short V_45 )
{
struct V_18 * V_19 ;
struct V_18 * V_241 = NULL ;
if ( V_33 == NULL || V_6 == NULL )
return V_241 ;
F_38 ( & V_33 -> V_72 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_240 != V_242 && V_240 != V_19 -> V_86 . V_243 )
continue;
if ( V_45 != 0 && V_45 != F_45 ( V_19 ) )
continue;
V_241 = V_19 ;
F_34 ( V_19 ) ;
break;
}
F_40 ( & V_33 -> V_72 ) ;
return V_241 ;
}
static int F_139 ( const struct V_18 * V_19 ,
char * V_244 , int V_245 )
{
int V_14 ;
V_14 = snprintf ( V_244 , V_245 , L_30 ,
V_19 -> V_23 -> V_6 ,
F_45 ( V_19 ) ) ;
if ( V_14 >= V_245 )
return - V_246 ;
return V_14 ;
}
int F_140 ( struct V_32 * V_33 , char * V_11 , const int V_247 )
{
struct V_18 * V_19 ;
int V_14 , V_248 ;
char * V_244 ;
if ( ! V_33 )
return 0 ;
F_38 ( & V_33 -> V_72 ) ;
V_244 = V_11 ;
V_248 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_139 ( V_19 , V_244 , V_247 - V_248 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_248 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_244 += V_14 ;
V_248 += V_14 ;
}
F_40 ( & V_33 -> V_72 ) ;
return V_248 ;
}
static void * F_141 ( struct V_249 * V_250 , T_3 * V_244 )
{
unsigned int V_251 = ( unsigned int ) * V_244 ;
struct V_32 * V_33 = V_250 -> V_252 ;
F_2 ( L_31 , V_251 ) ;
if ( ! V_251 )
return V_253 ;
return ( V_251 > V_33 -> V_217 ? NULL : & V_33 -> V_123 [ V_251 - 1 ] ) ;
}
static void * F_142 ( struct V_249 * V_250 , void * V_146 , T_3 * V_244 )
{
struct V_94 * V_95 = V_146 ;
struct V_32 * V_33 = V_250 -> V_252 ;
F_2 ( L_32 , * V_244 ) ;
if ( V_146 == V_253 ) {
V_95 = & V_33 -> V_123 [ 0 ] ;
} else {
unsigned int V_251 = ( V_95 - & V_33 -> V_123 [ 0 ] ) ;
if ( V_251 < V_33 -> V_217 - 1 )
V_95 = & V_33 -> V_123 [ V_251 + 1 ] ;
else
V_95 = NULL ;
}
++ * V_244 ;
return V_95 ;
}
static void F_143 ( struct V_249 * V_250 , void * V_146 )
{
}
static int F_144 ( struct V_249 * V_250 , void * V_146 )
{
struct V_94 * V_95 = V_146 ;
if ( V_146 == V_253 ) {
F_145 ( V_250 , L_33 ) ;
return 0 ;
}
F_146 ( V_250 , L_34 ,
V_95 -> V_172 ,
( unsigned long ) F_147 ( & V_95 -> V_98 . V_99 ) ,
V_95 -> V_98 . V_109 ,
( unsigned long ) F_147 ( & V_95 -> V_98 . V_105 ) ,
( unsigned long ) F_147 ( & V_95 -> V_98 . V_162 ) ) ;
return 0 ;
}
int F_148 ( struct V_32 * V_33 , struct V_254 * V_254 )
{
int V_77 ;
V_77 = F_149 ( V_254 , & V_255 ) ;
if ( ! V_77 )
( (struct V_249 * ) V_254 -> V_256 ) -> V_252 = V_33 ;
return V_77 ;
}

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
F_37 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_38 ( struct V_32 * V_33 , struct V_18 * V_68 )
{
F_36 ( V_69 , & V_68 -> V_26 ) ;
F_39 ( & V_33 -> V_70 ) ;
F_40 ( & V_68 -> V_36 , & V_33 -> V_71 ) ;
F_41 ( & V_33 -> V_70 ) ;
F_32 ( V_68 ) ;
}
int F_42 ( struct V_32 * V_33 , const char * V_72 ,
struct V_31 * V_31 , const int V_44 ,
const unsigned short V_45 , int V_46 )
{
struct V_1 * V_2 ;
F_2 ( L_6 , V_72 , V_45 ) ;
F_4 ( & V_8 ) ;
F_5 (xcl, &svc_xprt_class_list, xcl_list) {
struct V_18 * V_73 ;
unsigned short V_74 ;
if ( strcmp ( V_72 , V_2 -> V_6 ) )
continue;
if ( ! F_43 ( V_2 -> V_24 ) )
goto V_75;
F_7 ( & V_8 ) ;
V_73 = F_27 ( V_2 , V_33 , V_31 , V_44 , V_45 , V_46 ) ;
if ( F_44 ( V_73 ) ) {
F_17 ( V_2 -> V_24 ) ;
return F_45 ( V_73 ) ;
}
F_38 ( V_33 , V_73 ) ;
V_74 = F_46 ( V_73 ) ;
return V_74 ;
}
V_75:
F_7 ( & V_8 ) ;
F_2 ( L_7 , V_72 ) ;
return - V_76 ;
}
void F_47 ( struct V_77 * V_78 , struct V_18 * V_19 )
{
memcpy ( & V_78 -> V_79 , & V_19 -> V_80 , V_19 -> V_81 ) ;
V_78 -> V_82 = V_19 -> V_81 ;
memcpy ( & V_78 -> V_83 , & V_19 -> V_84 , V_19 -> V_85 ) ;
V_78 -> V_86 = V_19 -> V_85 ;
}
char * F_48 ( struct V_77 * V_78 , char * V_11 , T_1 V_14 )
{
return F_49 ( F_50 ( V_78 ) , V_11 , V_14 ) ;
}
static bool F_51 ( struct V_18 * V_19 )
{
if ( V_19 -> V_26 & ( ( 1 << V_87 ) | ( 1 << V_88 ) ) )
return true ;
if ( V_19 -> V_26 & ( ( 1 << V_89 ) | ( 1 << V_90 ) ) )
return V_19 -> V_29 -> V_91 ( V_19 ) ;
return false ;
}
static void F_37 ( struct V_18 * V_19 )
{
struct V_92 * V_93 ;
struct V_77 * V_78 = NULL ;
int V_94 ;
bool V_95 = false ;
if ( ! F_51 ( V_19 ) )
goto V_9;
if ( F_52 ( V_42 , & V_19 -> V_26 ) ) {
F_2 ( L_8 , V_19 ) ;
goto V_9;
}
V_94 = F_53 () ;
V_93 = F_54 ( V_19 -> V_35 , V_94 ) ;
F_55 ( & V_93 -> V_96 . V_97 ) ;
V_98:
F_56 () ;
F_57 (rqstp, &pool->sp_all_threads, rq_all) {
if ( F_13 ( V_99 , & V_78 -> V_100 ) )
continue;
if ( ! V_95 ) {
F_39 ( & V_78 -> V_101 ) ;
if ( F_52 ( V_99 , & V_78 -> V_100 ) ) {
F_41 ( & V_78 -> V_101 ) ;
continue;
}
V_78 -> V_102 = V_19 ;
F_34 ( V_19 ) ;
F_41 ( & V_78 -> V_101 ) ;
}
F_58 () ;
F_55 ( & V_93 -> V_96 . V_103 ) ;
F_59 ( V_78 -> V_104 ) ;
F_60 () ;
goto V_9;
}
F_58 () ;
if ( ! V_95 ) {
V_95 = true ;
F_2 ( L_9 , V_19 ) ;
F_39 ( & V_93 -> V_105 ) ;
F_6 ( & V_19 -> V_37 , & V_93 -> V_106 ) ;
V_93 -> V_96 . V_107 ++ ;
F_41 ( & V_93 -> V_105 ) ;
goto V_98;
}
V_78 = NULL ;
F_60 () ;
V_9:
F_61 ( V_19 , V_78 ) ;
}
void F_62 ( struct V_18 * V_19 )
{
if ( F_13 ( V_42 , & V_19 -> V_26 ) )
return;
F_37 ( V_19 ) ;
}
static struct V_18 * F_63 ( struct V_92 * V_93 )
{
struct V_18 * V_19 = NULL ;
if ( F_64 ( & V_93 -> V_106 ) )
goto V_9;
F_39 ( & V_93 -> V_105 ) ;
if ( F_65 ( ! F_64 ( & V_93 -> V_106 ) ) ) {
V_19 = F_66 ( & V_93 -> V_106 ,
struct V_18 , V_37 ) ;
F_9 ( & V_19 -> V_37 ) ;
F_34 ( V_19 ) ;
F_2 ( L_10 ,
V_19 , F_67 ( & V_19 -> V_20 . V_108 ) ) ;
}
F_41 ( & V_93 -> V_105 ) ;
V_9:
F_68 ( V_19 ) ;
return V_19 ;
}
void F_69 ( struct V_77 * V_78 , int V_109 )
{
V_109 += V_78 -> V_110 . V_111 [ 0 ] . V_112 ;
if ( V_109 < V_78 -> V_113 ) {
struct V_18 * V_19 = V_78 -> V_102 ;
F_70 ( ( V_78 -> V_113 - V_109 ) , & V_19 -> V_114 ) ;
V_78 -> V_113 = V_109 ;
if ( V_19 -> V_29 -> V_115 )
V_19 -> V_29 -> V_115 ( V_19 ) ;
F_62 ( V_19 ) ;
}
}
static void F_71 ( struct V_77 * V_78 )
{
struct V_18 * V_19 = V_78 -> V_102 ;
V_78 -> V_102 -> V_29 -> V_116 ( V_78 ) ;
F_72 ( V_78 -> V_117 ) ;
V_78 -> V_117 = NULL ;
F_73 ( V_78 ) ;
V_78 -> V_110 . V_118 = 0 ;
V_78 -> V_110 . V_119 = 0 ;
if ( ( V_78 -> V_110 . V_14 ) > V_78 -> V_113 )
F_74 ( V_120 L_11 ,
V_78 -> V_113 ,
V_78 -> V_110 . V_14 ) ;
V_78 -> V_110 . V_111 [ 0 ] . V_112 = 0 ;
F_69 ( V_78 , 0 ) ;
V_78 -> V_102 = NULL ;
F_18 ( V_19 ) ;
}
void F_75 ( struct V_32 * V_33 )
{
struct V_77 * V_78 ;
struct V_92 * V_93 ;
V_93 = & V_33 -> V_121 [ 0 ] ;
F_56 () ;
F_57 (rqstp, &pool->sp_all_threads, rq_all) {
if ( F_13 ( V_99 , & V_78 -> V_100 ) )
continue;
F_58 () ;
F_2 ( L_12 , V_78 ) ;
F_59 ( V_78 -> V_104 ) ;
F_76 ( V_78 -> V_104 -> V_122 ) ;
return;
}
F_58 () ;
F_24 ( V_123 , & V_93 -> V_124 ) ;
F_77 () ;
F_76 ( 0 ) ;
}
int F_78 ( struct V_62 * sin )
{
switch ( sin -> V_125 ) {
case V_49 :
return F_79 ( ( (struct V_47 * ) sin ) -> V_53 )
< V_126 ;
case V_58 :
return F_79 ( ( (struct V_55 * ) sin ) -> V_61 )
< V_126 ;
default:
return 0 ;
}
}
static void F_80 ( struct V_32 * V_33 )
{
unsigned int V_127 = V_33 -> V_128 ? V_33 -> V_128 :
( V_33 -> V_129 + 3 ) * 20 ;
if ( V_33 -> V_130 > V_127 ) {
struct V_18 * V_19 = NULL ;
F_39 ( & V_33 -> V_70 ) ;
if ( ! F_64 ( & V_33 -> V_131 ) ) {
F_81 ( L_13 ,
V_33 -> V_132 , V_33 -> V_128 ?
L_14 :
L_15 ) ;
V_19 = F_82 ( V_33 -> V_131 . V_133 ,
struct V_18 ,
V_36 ) ;
F_24 ( V_88 , & V_19 -> V_26 ) ;
F_34 ( V_19 ) ;
}
F_41 ( & V_33 -> V_70 ) ;
if ( V_19 ) {
F_62 ( V_19 ) ;
F_18 ( V_19 ) ;
}
}
}
static int F_83 ( struct V_77 * V_78 )
{
struct V_32 * V_33 = V_78 -> V_134 ;
struct V_135 * V_136 ;
int V_137 ;
int V_138 ;
V_137 = ( V_33 -> V_139 + V_140 ) / V_140 ;
F_84 ( V_137 >= V_141 ) ;
if ( V_137 >= V_141 )
V_137 = V_141 - 1 ;
for ( V_138 = 0 ; V_138 < V_137 ; V_138 ++ )
while ( V_78 -> V_142 [ V_138 ] == NULL ) {
struct V_143 * V_144 = F_85 ( V_145 ) ;
if ( ! V_144 ) {
F_86 ( V_146 ) ;
if ( F_87 () || F_88 () ) {
F_86 ( V_147 ) ;
return - V_148 ;
}
F_89 ( F_90 ( 500 ) ) ;
}
V_78 -> V_142 [ V_138 ] = V_144 ;
}
V_78 -> V_149 = & V_78 -> V_142 [ V_138 ] ;
V_78 -> V_142 [ V_138 ++ ] = NULL ;
V_136 = & V_78 -> V_150 ;
V_136 -> V_111 [ 0 ] . V_151 = F_91 ( V_78 -> V_142 [ 0 ] ) ;
V_136 -> V_111 [ 0 ] . V_112 = V_140 ;
V_136 -> V_137 = V_78 -> V_142 + 1 ;
V_136 -> V_119 = 0 ;
V_136 -> V_118 = ( V_137 - 2 ) * V_140 ;
V_136 -> V_14 = ( V_137 - 1 ) * V_140 ;
V_136 -> V_152 [ 0 ] . V_112 = 0 ;
return 0 ;
}
static bool
F_92 ( struct V_77 * V_78 )
{
struct V_92 * V_93 = V_78 -> V_153 ;
if ( F_93 ( V_123 , & V_93 -> V_124 ) )
return false ;
if ( ! F_64 ( & V_93 -> V_106 ) )
return false ;
if ( F_87 () || F_88 () )
return false ;
if ( F_94 ( V_154 ) )
return false ;
return true ;
}
static struct V_18 * F_95 ( struct V_77 * V_78 , long V_155 )
{
struct V_18 * V_19 ;
struct V_92 * V_93 = V_78 -> V_153 ;
long V_156 = 0 ;
F_84 ( V_78 -> V_102 ) ;
V_78 -> V_157 . V_158 = 5 * V_159 ;
V_19 = F_63 ( V_93 ) ;
if ( V_19 ) {
V_78 -> V_102 = V_19 ;
V_78 -> V_157 . V_158 = 1 * V_159 ;
F_36 ( V_123 , & V_93 -> V_124 ) ;
return V_19 ;
}
F_86 ( V_146 ) ;
F_36 ( V_99 , & V_78 -> V_100 ) ;
F_96 () ;
if ( F_65 ( F_92 ( V_78 ) ) )
V_156 = F_89 ( V_155 ) ;
else
F_97 ( V_147 ) ;
F_98 () ;
F_39 ( & V_78 -> V_101 ) ;
F_24 ( V_99 , & V_78 -> V_100 ) ;
F_41 ( & V_78 -> V_101 ) ;
V_19 = V_78 -> V_102 ;
if ( V_19 != NULL )
return V_19 ;
if ( ! V_156 )
F_55 ( & V_93 -> V_96 . V_160 ) ;
if ( F_87 () || F_88 () )
return F_31 ( - V_148 ) ;
return F_31 ( - V_161 ) ;
}
static void F_99 ( struct V_32 * V_33 , struct V_18 * V_162 )
{
F_39 ( & V_33 -> V_70 ) ;
F_24 ( V_69 , & V_162 -> V_26 ) ;
F_40 ( & V_162 -> V_36 , & V_33 -> V_131 ) ;
V_33 -> V_130 ++ ;
if ( V_33 -> V_163 . V_164 == NULL ) {
F_100 ( & V_33 -> V_163 , V_165 ,
( unsigned long ) V_33 ) ;
F_101 ( & V_33 -> V_163 ,
V_166 + V_167 * V_159 ) ;
}
F_41 ( & V_33 -> V_70 ) ;
F_32 ( V_162 ) ;
}
static int F_102 ( struct V_77 * V_78 , struct V_18 * V_19 )
{
struct V_32 * V_33 = V_78 -> V_134 ;
int V_14 = 0 ;
if ( F_13 ( V_88 , & V_19 -> V_26 ) ) {
F_2 ( L_16 ) ;
F_103 ( V_19 ) ;
goto V_9;
}
if ( F_13 ( V_168 , & V_19 -> V_26 ) ) {
struct V_18 * V_162 ;
F_104 ( V_19 -> V_23 -> V_24 ) ;
F_80 ( V_19 -> V_35 ) ;
V_162 = V_19 -> V_29 -> V_169 ( V_19 ) ;
if ( V_162 )
F_99 ( V_33 , V_162 ) ;
else
F_17 ( V_19 -> V_23 -> V_24 ) ;
} else {
F_2 ( L_17 ,
V_78 , V_78 -> V_153 -> V_170 , V_19 ,
F_67 ( & V_19 -> V_20 . V_108 ) ) ;
V_78 -> V_117 = F_105 ( V_19 ) ;
if ( V_78 -> V_117 )
V_14 = F_106 ( V_78 ) ;
else
V_14 = V_19 -> V_29 -> V_171 ( V_78 ) ;
F_2 ( L_18 , V_14 ) ;
V_78 -> V_113 = V_33 -> V_139 ;
F_107 ( V_78 -> V_113 , & V_19 -> V_114 ) ;
}
F_32 ( V_19 ) ;
V_9:
F_108 ( V_19 , V_14 ) ;
return V_14 ;
}
int F_109 ( struct V_77 * V_78 , long V_155 )
{
struct V_18 * V_19 = NULL ;
struct V_32 * V_33 = V_78 -> V_134 ;
int V_14 , V_75 ;
F_2 ( L_19 ,
V_78 , V_155 ) ;
if ( V_78 -> V_102 )
F_74 ( V_120
L_20 ,
V_78 ) ;
V_75 = F_83 ( V_78 ) ;
if ( V_75 )
goto V_9;
F_98 () ;
F_110 () ;
V_75 = - V_148 ;
if ( F_87 () || F_88 () )
goto V_9;
V_19 = F_95 ( V_78 , V_155 ) ;
if ( F_44 ( V_19 ) ) {
V_75 = F_45 ( V_19 ) ;
goto V_9;
}
V_14 = F_102 ( V_78 , V_19 ) ;
V_75 = - V_161 ;
if ( V_14 <= 0 )
goto V_172;
F_36 ( V_173 , & V_19 -> V_26 ) ;
if ( V_19 -> V_29 -> V_174 ( V_78 ) )
F_24 ( V_175 , & V_78 -> V_100 ) ;
else
F_36 ( V_175 , & V_78 -> V_100 ) ;
V_78 -> V_157 . V_176 = V_177 ;
V_78 -> V_178 = F_111 ( & V_78 -> V_150 . V_111 [ 0 ] ) ;
if ( V_33 -> V_179 )
V_33 -> V_179 -> V_180 ++ ;
F_112 ( V_78 , V_14 ) ;
return V_14 ;
V_172:
V_78 -> V_110 . V_14 = 0 ;
F_71 ( V_78 ) ;
V_9:
F_112 ( V_78 , V_75 ) ;
return V_75 ;
}
void F_113 ( struct V_77 * V_78 )
{
F_2 ( L_21 , V_78 -> V_102 ) ;
F_71 ( V_78 ) ;
}
int F_114 ( struct V_77 * V_78 )
{
struct V_18 * V_19 ;
int V_14 = - V_181 ;
struct V_135 * V_182 ;
V_19 = V_78 -> V_102 ;
if ( ! V_19 )
goto V_9;
V_78 -> V_102 -> V_29 -> V_116 ( V_78 ) ;
V_182 = & V_78 -> V_110 ;
V_182 -> V_14 = V_182 -> V_111 [ 0 ] . V_112 +
V_182 -> V_118 +
V_182 -> V_152 [ 0 ] . V_112 ;
F_115 ( & V_19 -> V_40 ) ;
if ( F_13 ( V_183 , & V_19 -> V_26 )
|| F_13 ( V_88 , & V_19 -> V_26 ) )
V_14 = - V_184 ;
else
V_14 = V_19 -> V_29 -> V_185 ( V_78 ) ;
F_116 ( & V_19 -> V_40 ) ;
F_117 ( & V_19 -> V_43 ) ;
F_71 ( V_78 ) ;
if ( V_14 == - V_186 || V_14 == - V_184 || V_14 == - V_161 )
V_14 = 0 ;
V_9:
F_118 ( V_78 , V_14 ) ;
return V_14 ;
}
static void V_165 ( unsigned long V_187 )
{
struct V_32 * V_33 = (struct V_32 * ) V_187 ;
struct V_18 * V_19 ;
struct V_188 * V_189 , * V_190 ;
F_2 ( L_22 ) ;
if ( ! F_119 ( & V_33 -> V_70 ) ) {
F_2 ( L_23 ) ;
F_101 ( & V_33 -> V_163 , V_166 + V_159 ) ;
return;
}
F_120 (le, next, &serv->sv_tempsocks) {
V_19 = F_82 ( V_189 , struct V_18 , V_36 ) ;
if ( ! F_52 ( V_173 , & V_19 -> V_26 ) )
continue;
if ( F_67 ( & V_19 -> V_20 . V_108 ) > 1 ||
F_13 ( V_42 , & V_19 -> V_26 ) )
continue;
F_9 ( V_189 ) ;
F_24 ( V_88 , & V_19 -> V_26 ) ;
F_2 ( L_24 , V_19 ) ;
F_62 ( V_19 ) ;
}
F_41 ( & V_33 -> V_70 ) ;
F_101 ( & V_33 -> V_163 , V_166 + V_167 * V_159 ) ;
}
static void F_121 ( struct V_18 * V_19 )
{
struct V_191 * V_192 ;
F_4 ( & V_19 -> V_41 ) ;
while ( ! F_64 ( & V_19 -> V_39 ) ) {
V_192 = F_66 ( & V_19 -> V_39 , struct V_191 , V_193 ) ;
F_122 ( & V_192 -> V_193 ) ;
V_192 -> V_194 ( V_192 ) ;
}
F_7 ( & V_19 -> V_41 ) ;
}
static void F_103 ( struct V_18 * V_19 )
{
struct V_32 * V_33 = V_19 -> V_35 ;
struct V_195 * V_196 ;
if ( F_52 ( V_183 , & V_19 -> V_26 ) )
F_123 () ;
F_2 ( L_25 , V_19 ) ;
V_19 -> V_29 -> V_197 ( V_19 ) ;
F_39 ( & V_33 -> V_70 ) ;
F_9 ( & V_19 -> V_36 ) ;
F_84 ( ! F_64 ( & V_19 -> V_37 ) ) ;
if ( F_13 ( V_69 , & V_19 -> V_26 ) )
V_33 -> V_130 -- ;
F_41 ( & V_33 -> V_70 ) ;
while ( ( V_196 = F_105 ( V_19 ) ) != NULL )
F_72 ( V_196 ) ;
F_121 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_124 ( struct V_18 * V_19 )
{
F_24 ( V_88 , & V_19 -> V_26 ) ;
if ( F_52 ( V_42 , & V_19 -> V_26 ) )
return;
F_103 ( V_19 ) ;
}
static int F_125 ( struct V_32 * V_33 , struct V_188 * V_198 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
int V_199 = 0 ;
F_4 ( & V_33 -> V_70 ) ;
F_5 (xprt, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
V_199 ++ ;
F_24 ( V_88 , & V_19 -> V_26 ) ;
F_62 ( V_19 ) ;
}
F_7 ( & V_33 -> V_70 ) ;
return V_199 ;
}
static struct V_18 * F_126 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
struct V_92 * V_93 ;
struct V_18 * V_19 ;
struct V_18 * V_200 ;
int V_138 ;
for ( V_138 = 0 ; V_138 < V_33 -> V_201 ; V_138 ++ ) {
V_93 = & V_33 -> V_121 [ V_138 ] ;
F_39 ( & V_93 -> V_105 ) ;
F_127 (xprt, tmp, &pool->sp_sockets, xpt_ready) {
if ( V_19 -> V_27 != V_31 )
continue;
F_9 ( & V_19 -> V_37 ) ;
F_41 ( & V_93 -> V_105 ) ;
return V_19 ;
}
F_41 ( & V_93 -> V_105 ) ;
}
return NULL ;
}
static void F_128 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
while ( ( V_19 = F_126 ( V_33 , V_31 ) ) ) {
F_24 ( V_88 , & V_19 -> V_26 ) ;
F_103 ( V_19 ) ;
}
}
void F_129 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
int V_202 = 0 ;
while ( F_125 ( V_33 , & V_33 -> V_71 , V_31 ) +
F_125 ( V_33 , & V_33 -> V_131 , V_31 ) ) {
F_128 ( V_33 , V_31 ) ;
F_130 ( V_202 ++ ) ;
}
}
static void F_131 ( struct V_203 * V_204 , int V_205 )
{
struct V_195 * V_196 =
F_12 ( V_204 , struct V_195 , V_206 ) ;
struct V_18 * V_19 = V_196 -> V_19 ;
F_4 ( & V_19 -> V_41 ) ;
F_24 ( V_90 , & V_19 -> V_26 ) ;
if ( V_205 || F_13 ( V_183 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_41 ) ;
F_2 ( L_26 ) ;
F_18 ( V_19 ) ;
F_72 ( V_196 ) ;
return;
}
F_2 ( L_27 ) ;
V_196 -> V_19 = NULL ;
F_40 ( & V_196 -> V_206 . V_207 , & V_19 -> V_38 ) ;
F_7 ( & V_19 -> V_41 ) ;
F_62 ( V_19 ) ;
F_18 ( V_19 ) ;
}
static struct V_203 * V_177 ( struct V_208 * V_209 )
{
struct V_77 * V_78 = F_12 ( V_209 , struct V_77 , V_157 ) ;
struct V_195 * V_196 ;
if ( V_78 -> V_150 . V_118 || ! F_13 ( V_210 , & V_78 -> V_100 ) )
return NULL ;
if ( V_78 -> V_117 ) {
V_196 = V_78 -> V_117 ;
V_78 -> V_117 = NULL ;
} else {
T_1 V_211 ;
T_1 V_212 ;
V_212 = sizeof( struct V_195 ) + V_78 -> V_150 . V_14 ;
V_196 = F_132 ( V_212 , V_145 ) ;
if ( V_196 == NULL )
return NULL ;
V_196 -> V_206 . V_22 = V_78 -> V_134 ;
V_196 -> V_213 = V_78 -> V_214 ;
memcpy ( & V_196 -> V_215 , & V_78 -> V_79 , V_78 -> V_82 ) ;
V_196 -> V_216 = V_78 -> V_82 ;
V_196 -> V_217 = V_78 -> V_83 ;
V_196 -> V_218 = V_78 -> V_150 . V_14 >> 2 ;
V_196 -> V_219 = V_78 -> V_220 ;
V_211 = V_78 -> V_150 . V_14 - V_78 -> V_150 . V_111 [ 0 ] . V_112 ;
memcpy ( V_196 -> args , V_78 -> V_150 . V_111 [ 0 ] . V_151 - V_211 ,
V_196 -> V_218 << 2 ) ;
}
F_34 ( V_78 -> V_102 ) ;
V_196 -> V_19 = V_78 -> V_102 ;
F_24 ( V_221 , & V_78 -> V_100 ) ;
V_196 -> V_206 . V_222 = F_131 ;
return & V_196 -> V_206 ;
}
static int F_106 ( struct V_77 * V_78 )
{
struct V_195 * V_196 = V_78 -> V_117 ;
V_78 -> V_150 . V_111 [ 0 ] . V_151 = V_196 -> args + ( V_196 -> V_219 >> 2 ) ;
V_78 -> V_150 . V_111 [ 0 ] . V_112 = ( V_196 -> V_218 << 2 ) - V_196 -> V_219 ;
V_78 -> V_150 . V_118 = 0 ;
V_78 -> V_150 . V_14 = V_196 -> V_218 << 2 ;
V_78 -> V_214 = V_196 -> V_213 ;
memcpy ( & V_78 -> V_79 , & V_196 -> V_215 , V_196 -> V_216 ) ;
V_78 -> V_82 = V_196 -> V_216 ;
V_78 -> V_220 = V_196 -> V_219 ;
V_78 -> V_83 = V_196 -> V_217 ;
V_78 -> V_223 = V_78 -> V_142 ;
return ( V_196 -> V_218 << 2 ) - V_196 -> V_219 ;
}
static struct V_195 * F_105 ( struct V_18 * V_19 )
{
struct V_195 * V_196 = NULL ;
if ( ! F_13 ( V_90 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_41 ) ;
if ( ! F_64 ( & V_19 -> V_38 ) ) {
V_196 = F_82 ( V_19 -> V_38 . V_190 ,
struct V_195 ,
V_206 . V_207 ) ;
F_9 ( & V_196 -> V_206 . V_207 ) ;
} else
F_36 ( V_90 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_41 ) ;
return V_196 ;
}
struct V_18 * F_133 ( struct V_32 * V_33 , const char * V_6 ,
struct V_31 * V_31 , const T_2 V_224 ,
const unsigned short V_45 )
{
struct V_18 * V_19 ;
struct V_18 * V_225 = NULL ;
if ( V_33 == NULL || V_6 == NULL )
return V_225 ;
F_39 ( & V_33 -> V_70 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_224 != V_226 && V_224 != V_19 -> V_84 . V_227 )
continue;
if ( V_45 != 0 && V_45 != F_46 ( V_19 ) )
continue;
V_225 = V_19 ;
F_34 ( V_19 ) ;
break;
}
F_41 ( & V_33 -> V_70 ) ;
return V_225 ;
}
static int F_134 ( const struct V_18 * V_19 ,
char * V_228 , int V_229 )
{
int V_14 ;
V_14 = snprintf ( V_228 , V_229 , L_28 ,
V_19 -> V_23 -> V_6 ,
F_46 ( V_19 ) ) ;
if ( V_14 >= V_229 )
return - V_230 ;
return V_14 ;
}
int F_135 ( struct V_32 * V_33 , char * V_11 , const int V_231 )
{
struct V_18 * V_19 ;
int V_14 , V_232 ;
char * V_228 ;
if ( ! V_33 )
return 0 ;
F_39 ( & V_33 -> V_70 ) ;
V_228 = V_11 ;
V_232 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_134 ( V_19 , V_228 , V_231 - V_232 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_232 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_228 += V_14 ;
V_232 += V_14 ;
}
F_41 ( & V_33 -> V_70 ) ;
return V_232 ;
}
static void * F_136 ( struct V_233 * V_234 , T_3 * V_228 )
{
unsigned int V_235 = ( unsigned int ) * V_228 ;
struct V_32 * V_33 = V_234 -> V_236 ;
F_2 ( L_29 , V_235 ) ;
if ( ! V_235 )
return V_237 ;
return ( V_235 > V_33 -> V_201 ? NULL : & V_33 -> V_121 [ V_235 - 1 ] ) ;
}
static void * F_137 ( struct V_233 * V_234 , void * V_144 , T_3 * V_228 )
{
struct V_92 * V_93 = V_144 ;
struct V_32 * V_33 = V_234 -> V_236 ;
F_2 ( L_30 , * V_228 ) ;
if ( V_144 == V_237 ) {
V_93 = & V_33 -> V_121 [ 0 ] ;
} else {
unsigned int V_235 = ( V_93 - & V_33 -> V_121 [ 0 ] ) ;
if ( V_235 < V_33 -> V_201 - 1 )
V_93 = & V_33 -> V_121 [ V_235 + 1 ] ;
else
V_93 = NULL ;
}
++ * V_228 ;
return V_93 ;
}
static void F_138 ( struct V_233 * V_234 , void * V_144 )
{
}
static int F_139 ( struct V_233 * V_234 , void * V_144 )
{
struct V_92 * V_93 = V_144 ;
if ( V_144 == V_237 ) {
F_140 ( V_234 , L_31 ) ;
return 0 ;
}
F_141 ( V_234 , L_32 ,
V_93 -> V_170 ,
( unsigned long ) F_142 ( & V_93 -> V_96 . V_97 ) ,
V_93 -> V_96 . V_107 ,
( unsigned long ) F_142 ( & V_93 -> V_96 . V_103 ) ,
( unsigned long ) F_142 ( & V_93 -> V_96 . V_160 ) ) ;
return 0 ;
}
int F_143 ( struct V_32 * V_33 , struct V_238 * V_238 )
{
int V_75 ;
V_75 = F_144 ( V_238 , & V_239 ) ;
if ( ! V_75 )
( (struct V_233 * ) V_238 -> V_240 ) -> V_236 = V_33 ;
return V_75 ;
}

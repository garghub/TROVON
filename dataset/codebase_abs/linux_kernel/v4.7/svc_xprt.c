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
if ( V_19 -> V_29 )
F_17 ( V_19 -> V_29 ) ;
V_19 -> V_30 -> V_31 ( V_19 ) ;
F_18 ( V_22 ) ;
}
void F_19 ( struct V_18 * V_19 )
{
F_20 ( & V_19 -> V_20 , F_11 ) ;
}
void F_21 ( struct V_32 * V_32 , struct V_1 * V_2 ,
struct V_18 * V_19 , struct V_33 * V_34 )
{
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_23 = V_2 ;
V_19 -> V_30 = V_2 -> V_35 ;
F_22 ( & V_19 -> V_20 ) ;
V_19 -> V_36 = V_34 ;
F_3 ( & V_19 -> V_37 ) ;
F_3 ( & V_19 -> V_38 ) ;
F_3 ( & V_19 -> V_39 ) ;
F_3 ( & V_19 -> V_40 ) ;
F_23 ( & V_19 -> V_41 ) ;
F_24 ( & V_19 -> V_42 ) ;
F_25 ( V_43 , & V_19 -> V_26 ) ;
F_26 ( & V_19 -> V_44 , L_4 ) ;
V_19 -> V_27 = F_27 ( V_32 ) ;
}
static struct V_18 * F_28 ( struct V_1 * V_2 ,
struct V_33 * V_34 ,
struct V_32 * V_32 ,
const int V_45 ,
const unsigned short V_46 ,
int V_47 )
{
struct V_48 sin = {
. V_49 = V_50 ,
. V_51 . V_52 = F_29 ( V_53 ) ,
. V_54 = F_30 ( V_46 ) ,
} ;
#if F_31 ( V_55 )
struct V_56 V_57 = {
. V_58 = V_59 ,
. V_60 = V_61 ,
. V_62 = F_30 ( V_46 ) ,
} ;
#endif
struct V_63 * V_64 ;
T_1 V_14 ;
switch ( V_45 ) {
case V_65 :
V_64 = (struct V_63 * ) & sin ;
V_14 = sizeof( sin ) ;
break;
#if F_31 ( V_55 )
case V_66 :
V_64 = (struct V_63 * ) & V_57 ;
V_14 = sizeof( V_57 ) ;
break;
#endif
default:
return F_32 ( - V_67 ) ;
}
return V_2 -> V_35 -> V_68 ( V_34 , V_32 , V_64 , V_14 , V_47 ) ;
}
static void F_33 ( struct V_18 * V_19 )
{
if ( ! F_13 ( V_43 , & V_19 -> V_26 ) ) {
F_34 ( 1 , L_5 , V_19 ) ;
return;
}
F_35 ( V_19 ) ;
F_36 () ;
F_37 ( V_43 , & V_19 -> V_26 ) ;
V_19 -> V_36 -> V_69 -> V_70 ( V_19 ) ;
F_19 ( V_19 ) ;
}
void F_38 ( struct V_33 * V_34 , struct V_18 * V_71 )
{
F_37 ( V_72 , & V_71 -> V_26 ) ;
F_39 ( & V_34 -> V_73 ) ;
F_40 ( & V_71 -> V_37 , & V_34 -> V_74 ) ;
F_41 ( & V_34 -> V_73 ) ;
F_33 ( V_71 ) ;
}
int F_42 ( struct V_33 * V_34 , const char * V_75 ,
struct V_32 * V_32 , const int V_45 ,
const unsigned short V_46 , int V_47 )
{
struct V_1 * V_2 ;
F_4 ( & V_8 ) ;
F_5 (xcl, &svc_xprt_class_list, xcl_list) {
struct V_18 * V_76 ;
unsigned short V_77 ;
if ( strcmp ( V_75 , V_2 -> V_6 ) )
continue;
if ( ! F_43 ( V_2 -> V_24 ) )
goto V_78;
F_7 ( & V_8 ) ;
V_76 = F_28 ( V_2 , V_34 , V_32 , V_45 , V_46 , V_47 ) ;
if ( F_44 ( V_76 ) ) {
F_18 ( V_2 -> V_24 ) ;
return F_45 ( V_76 ) ;
}
F_38 ( V_34 , V_76 ) ;
V_77 = F_46 ( V_76 ) ;
return V_77 ;
}
V_78:
F_7 ( & V_8 ) ;
return - V_79 ;
}
int F_47 ( struct V_33 * V_34 , const char * V_75 ,
struct V_32 * V_32 , const int V_45 ,
const unsigned short V_46 , int V_47 )
{
int V_78 ;
F_2 ( L_6 , V_75 , V_46 ) ;
V_78 = F_42 ( V_34 , V_75 , V_32 , V_45 , V_46 , V_47 ) ;
if ( V_78 == - V_79 ) {
F_48 ( L_7 , V_75 ) ;
V_78 = F_42 ( V_34 , V_75 , V_32 , V_45 , V_46 , V_47 ) ;
}
if ( V_78 )
F_2 ( L_8 ,
V_75 , V_78 ) ;
return V_78 ;
}
void F_49 ( struct V_80 * V_81 , struct V_18 * V_19 )
{
memcpy ( & V_81 -> V_82 , & V_19 -> V_83 , V_19 -> V_84 ) ;
V_81 -> V_85 = V_19 -> V_84 ;
memcpy ( & V_81 -> V_86 , & V_19 -> V_87 , V_19 -> V_88 ) ;
V_81 -> V_89 = V_19 -> V_88 ;
}
char * F_50 ( struct V_80 * V_81 , char * V_11 , T_1 V_14 )
{
return F_51 ( F_52 ( V_81 ) , V_11 , V_14 ) ;
}
static bool F_53 ( struct V_18 * V_19 )
{
if ( V_19 -> V_26 & ( ( 1 << V_90 ) | ( 1 << V_91 ) ) )
return true ;
if ( V_19 -> V_26 & ( ( 1 << V_92 ) | ( 1 << V_93 ) ) )
return V_19 -> V_30 -> V_94 ( V_19 ) ;
return false ;
}
void F_54 ( struct V_18 * V_19 )
{
struct V_95 * V_96 ;
struct V_80 * V_81 = NULL ;
int V_97 ;
bool V_98 = false ;
if ( ! F_53 ( V_19 ) )
goto V_9;
if ( F_55 ( V_43 , & V_19 -> V_26 ) ) {
F_2 ( L_9 , V_19 ) ;
goto V_9;
}
V_97 = F_56 () ;
V_96 = F_57 ( V_19 -> V_36 , V_97 ) ;
F_58 ( & V_96 -> V_99 . V_100 ) ;
V_101:
F_59 () ;
F_60 (rqstp, &pool->sp_all_threads, rq_all) {
if ( F_13 ( V_102 , & V_81 -> V_103 ) )
continue;
if ( ! V_98 ) {
F_39 ( & V_81 -> V_104 ) ;
if ( F_55 ( V_102 , & V_81 -> V_103 ) ) {
F_41 ( & V_81 -> V_104 ) ;
continue;
}
V_81 -> V_105 = V_19 ;
F_35 ( V_19 ) ;
F_41 ( & V_81 -> V_104 ) ;
}
F_61 () ;
F_58 ( & V_96 -> V_99 . V_106 ) ;
F_62 ( V_81 -> V_107 ) ;
F_63 () ;
goto V_9;
}
F_61 () ;
if ( ! V_98 ) {
V_98 = true ;
F_2 ( L_10 , V_19 ) ;
F_39 ( & V_96 -> V_108 ) ;
F_6 ( & V_19 -> V_38 , & V_96 -> V_109 ) ;
V_96 -> V_99 . V_110 ++ ;
F_41 ( & V_96 -> V_108 ) ;
goto V_101;
}
V_81 = NULL ;
F_63 () ;
V_9:
F_64 ( V_19 , V_81 ) ;
}
void F_65 ( struct V_18 * V_19 )
{
if ( F_13 ( V_43 , & V_19 -> V_26 ) )
return;
V_19 -> V_36 -> V_69 -> V_70 ( V_19 ) ;
}
static struct V_18 * F_66 ( struct V_95 * V_96 )
{
struct V_18 * V_19 = NULL ;
if ( F_67 ( & V_96 -> V_109 ) )
goto V_9;
F_39 ( & V_96 -> V_108 ) ;
if ( F_68 ( ! F_67 ( & V_96 -> V_109 ) ) ) {
V_19 = F_69 ( & V_96 -> V_109 ,
struct V_18 , V_38 ) ;
F_9 ( & V_19 -> V_38 ) ;
F_35 ( V_19 ) ;
F_2 ( L_11 ,
V_19 , F_70 ( & V_19 -> V_20 . V_111 ) ) ;
}
F_41 ( & V_96 -> V_108 ) ;
V_9:
F_71 ( V_19 ) ;
return V_19 ;
}
void F_72 ( struct V_80 * V_81 , int V_112 )
{
V_112 += V_81 -> V_113 . V_114 [ 0 ] . V_115 ;
if ( V_112 < V_81 -> V_116 ) {
struct V_18 * V_19 = V_81 -> V_105 ;
F_73 ( ( V_81 -> V_116 - V_112 ) , & V_19 -> V_117 ) ;
V_81 -> V_116 = V_112 ;
if ( V_19 -> V_30 -> V_118 )
V_19 -> V_30 -> V_118 ( V_19 ) ;
F_65 ( V_19 ) ;
}
}
static void F_74 ( struct V_80 * V_81 )
{
struct V_18 * V_19 = V_81 -> V_105 ;
V_81 -> V_105 -> V_30 -> V_119 ( V_81 ) ;
F_75 ( V_81 -> V_120 ) ;
V_81 -> V_120 = NULL ;
F_76 ( V_81 ) ;
V_81 -> V_113 . V_121 = 0 ;
V_81 -> V_113 . V_122 = 0 ;
if ( ( V_81 -> V_113 . V_14 ) > V_81 -> V_116 )
F_77 ( V_123 L_12 ,
V_81 -> V_116 ,
V_81 -> V_113 . V_14 ) ;
V_81 -> V_113 . V_114 [ 0 ] . V_115 = 0 ;
F_72 ( V_81 , 0 ) ;
V_81 -> V_105 = NULL ;
F_19 ( V_19 ) ;
}
void F_78 ( struct V_33 * V_34 )
{
struct V_80 * V_81 ;
struct V_95 * V_96 ;
V_96 = & V_34 -> V_124 [ 0 ] ;
F_59 () ;
F_60 (rqstp, &pool->sp_all_threads, rq_all) {
if ( F_13 ( V_102 , & V_81 -> V_103 ) )
continue;
F_61 () ;
F_2 ( L_13 , V_81 ) ;
F_62 ( V_81 -> V_107 ) ;
F_79 ( V_81 -> V_107 -> V_125 ) ;
return;
}
F_61 () ;
F_25 ( V_126 , & V_96 -> V_127 ) ;
F_80 () ;
F_79 ( 0 ) ;
}
int F_81 ( struct V_63 * sin )
{
switch ( sin -> V_128 ) {
case V_50 :
return F_82 ( ( (struct V_48 * ) sin ) -> V_54 )
< V_129 ;
case V_59 :
return F_82 ( ( (struct V_56 * ) sin ) -> V_62 )
< V_129 ;
default:
return 0 ;
}
}
static void F_83 ( struct V_33 * V_34 )
{
unsigned int V_130 = V_34 -> V_131 ? V_34 -> V_131 :
( V_34 -> V_132 + 3 ) * 20 ;
if ( V_34 -> V_133 > V_130 ) {
struct V_18 * V_19 = NULL ;
F_39 ( & V_34 -> V_73 ) ;
if ( ! F_67 ( & V_34 -> V_134 ) ) {
F_84 ( L_14 ,
V_34 -> V_135 , V_34 -> V_131 ?
L_15 :
L_16 ) ;
V_19 = F_85 ( V_34 -> V_134 . V_136 ,
struct V_18 ,
V_37 ) ;
F_25 ( V_91 , & V_19 -> V_26 ) ;
F_35 ( V_19 ) ;
}
F_41 ( & V_34 -> V_73 ) ;
if ( V_19 ) {
F_65 ( V_19 ) ;
F_19 ( V_19 ) ;
}
}
}
static int F_86 ( struct V_80 * V_81 )
{
struct V_33 * V_34 = V_81 -> V_137 ;
struct V_138 * V_139 ;
int V_140 ;
int V_141 ;
V_140 = ( V_34 -> V_142 + V_143 ) / V_143 ;
F_87 ( V_140 >= V_144 ) ;
if ( V_140 >= V_144 )
V_140 = V_144 - 1 ;
for ( V_141 = 0 ; V_141 < V_140 ; V_141 ++ )
while ( V_81 -> V_145 [ V_141 ] == NULL ) {
struct V_146 * V_147 = F_88 ( V_148 ) ;
if ( ! V_147 ) {
F_89 ( V_149 ) ;
if ( F_90 () || F_91 () ) {
F_89 ( V_150 ) ;
return - V_151 ;
}
F_92 ( F_93 ( 500 ) ) ;
}
V_81 -> V_145 [ V_141 ] = V_147 ;
}
V_81 -> V_152 = & V_81 -> V_145 [ V_141 ] ;
V_81 -> V_145 [ V_141 ++ ] = NULL ;
V_139 = & V_81 -> V_153 ;
V_139 -> V_114 [ 0 ] . V_154 = F_94 ( V_81 -> V_145 [ 0 ] ) ;
V_139 -> V_114 [ 0 ] . V_115 = V_143 ;
V_139 -> V_140 = V_81 -> V_145 + 1 ;
V_139 -> V_122 = 0 ;
V_139 -> V_121 = ( V_140 - 2 ) * V_143 ;
V_139 -> V_14 = ( V_140 - 1 ) * V_143 ;
V_139 -> V_155 [ 0 ] . V_115 = 0 ;
return 0 ;
}
static bool
F_95 ( struct V_80 * V_81 )
{
struct V_95 * V_96 = V_81 -> V_156 ;
if ( F_96 ( V_126 , & V_96 -> V_127 ) )
return false ;
if ( ! F_67 ( & V_96 -> V_109 ) )
return false ;
if ( F_90 () || F_91 () )
return false ;
if ( F_97 ( V_157 ) )
return false ;
return true ;
}
static struct V_18 * F_98 ( struct V_80 * V_81 , long V_158 )
{
struct V_18 * V_19 ;
struct V_95 * V_96 = V_81 -> V_156 ;
long V_159 = 0 ;
F_87 ( V_81 -> V_105 ) ;
V_81 -> V_160 . V_161 = 5 * V_162 ;
V_19 = F_66 ( V_96 ) ;
if ( V_19 ) {
V_81 -> V_105 = V_19 ;
V_81 -> V_160 . V_161 = 1 * V_162 ;
F_37 ( V_126 , & V_96 -> V_127 ) ;
return V_19 ;
}
F_89 ( V_149 ) ;
F_37 ( V_102 , & V_81 -> V_103 ) ;
F_99 () ;
if ( F_68 ( F_95 ( V_81 ) ) )
V_159 = F_92 ( V_158 ) ;
else
F_100 ( V_150 ) ;
F_101 () ;
F_39 ( & V_81 -> V_104 ) ;
F_25 ( V_102 , & V_81 -> V_103 ) ;
F_41 ( & V_81 -> V_104 ) ;
V_19 = V_81 -> V_105 ;
if ( V_19 != NULL )
return V_19 ;
if ( ! V_159 )
F_58 ( & V_96 -> V_99 . V_163 ) ;
if ( F_90 () || F_91 () )
return F_32 ( - V_151 ) ;
return F_32 ( - V_164 ) ;
}
static void F_102 ( struct V_33 * V_34 , struct V_18 * V_165 )
{
F_39 ( & V_34 -> V_73 ) ;
F_25 ( V_72 , & V_165 -> V_26 ) ;
F_40 ( & V_165 -> V_37 , & V_34 -> V_134 ) ;
V_34 -> V_133 ++ ;
if ( V_34 -> V_166 . V_167 == NULL ) {
F_103 ( & V_34 -> V_166 , V_168 ,
( unsigned long ) V_34 ) ;
F_104 ( & V_34 -> V_166 ,
V_169 + V_170 * V_162 ) ;
}
F_41 ( & V_34 -> V_73 ) ;
F_33 ( V_165 ) ;
}
static int F_105 ( struct V_80 * V_81 , struct V_18 * V_19 )
{
struct V_33 * V_34 = V_81 -> V_137 ;
int V_14 = 0 ;
if ( F_13 ( V_91 , & V_19 -> V_26 ) ) {
F_2 ( L_17 ) ;
F_106 ( V_19 ) ;
goto V_9;
}
if ( F_13 ( V_171 , & V_19 -> V_26 ) ) {
struct V_18 * V_165 ;
F_107 ( V_19 -> V_23 -> V_24 ) ;
F_83 ( V_19 -> V_36 ) ;
V_165 = V_19 -> V_30 -> V_172 ( V_19 ) ;
if ( V_165 )
F_102 ( V_34 , V_165 ) ;
else
F_18 ( V_19 -> V_23 -> V_24 ) ;
} else {
F_2 ( L_18 ,
V_81 , V_81 -> V_156 -> V_173 , V_19 ,
F_70 ( & V_19 -> V_20 . V_111 ) ) ;
V_81 -> V_120 = F_108 ( V_19 ) ;
if ( V_81 -> V_120 )
V_14 = F_109 ( V_81 ) ;
else
V_14 = V_19 -> V_30 -> V_174 ( V_81 ) ;
F_2 ( L_19 , V_14 ) ;
V_81 -> V_116 = V_34 -> V_142 ;
F_110 ( V_81 -> V_116 , & V_19 -> V_117 ) ;
}
F_33 ( V_19 ) ;
V_9:
F_111 ( V_19 , V_14 ) ;
return V_14 ;
}
int F_112 ( struct V_80 * V_81 , long V_158 )
{
struct V_18 * V_19 = NULL ;
struct V_33 * V_34 = V_81 -> V_137 ;
int V_14 , V_78 ;
F_2 ( L_20 ,
V_81 , V_158 ) ;
if ( V_81 -> V_105 )
F_77 ( V_123
L_21 ,
V_81 ) ;
V_78 = F_86 ( V_81 ) ;
if ( V_78 )
goto V_9;
F_101 () ;
F_113 () ;
V_78 = - V_151 ;
if ( F_90 () || F_91 () )
goto V_9;
V_19 = F_98 ( V_81 , V_158 ) ;
if ( F_44 ( V_19 ) ) {
V_78 = F_45 ( V_19 ) ;
goto V_9;
}
V_14 = F_105 ( V_81 , V_19 ) ;
V_78 = - V_164 ;
if ( V_14 <= 0 )
goto V_175;
F_37 ( V_176 , & V_19 -> V_26 ) ;
if ( V_19 -> V_30 -> V_177 ( V_81 ) )
F_25 ( V_178 , & V_81 -> V_103 ) ;
else
F_37 ( V_178 , & V_81 -> V_103 ) ;
V_81 -> V_160 . V_179 = V_180 ;
V_81 -> V_181 = F_114 ( & V_81 -> V_153 . V_114 [ 0 ] ) ;
if ( V_34 -> V_182 )
V_34 -> V_182 -> V_183 ++ ;
F_115 ( V_81 , V_14 ) ;
return V_14 ;
V_175:
V_81 -> V_113 . V_14 = 0 ;
F_74 ( V_81 ) ;
V_9:
F_115 ( V_81 , V_78 ) ;
return V_78 ;
}
void F_116 ( struct V_80 * V_81 )
{
F_2 ( L_22 , V_81 -> V_105 ) ;
F_74 ( V_81 ) ;
}
int F_117 ( struct V_80 * V_81 )
{
struct V_18 * V_19 ;
int V_14 = - V_184 ;
struct V_138 * V_185 ;
V_19 = V_81 -> V_105 ;
if ( ! V_19 )
goto V_9;
V_81 -> V_105 -> V_30 -> V_119 ( V_81 ) ;
V_185 = & V_81 -> V_113 ;
V_185 -> V_14 = V_185 -> V_114 [ 0 ] . V_115 +
V_185 -> V_121 +
V_185 -> V_155 [ 0 ] . V_115 ;
F_118 ( & V_19 -> V_41 ) ;
if ( F_13 ( V_186 , & V_19 -> V_26 )
|| F_13 ( V_91 , & V_19 -> V_26 ) )
V_14 = - V_187 ;
else
V_14 = V_19 -> V_30 -> V_188 ( V_81 ) ;
F_119 ( & V_19 -> V_41 ) ;
F_120 ( & V_19 -> V_44 ) ;
F_74 ( V_81 ) ;
if ( V_14 == - V_189 || V_14 == - V_187 || V_14 == - V_164 )
V_14 = 0 ;
V_9:
F_121 ( V_81 , V_14 ) ;
return V_14 ;
}
static void V_168 ( unsigned long V_190 )
{
struct V_33 * V_34 = (struct V_33 * ) V_190 ;
struct V_18 * V_19 ;
struct V_191 * V_192 , * V_193 ;
F_2 ( L_23 ) ;
if ( ! F_122 ( & V_34 -> V_73 ) ) {
F_2 ( L_24 ) ;
F_104 ( & V_34 -> V_166 , V_169 + V_162 ) ;
return;
}
F_123 (le, next, &serv->sv_tempsocks) {
V_19 = F_85 ( V_192 , struct V_18 , V_37 ) ;
if ( ! F_55 ( V_176 , & V_19 -> V_26 ) )
continue;
if ( F_70 ( & V_19 -> V_20 . V_111 ) > 1 ||
F_13 ( V_43 , & V_19 -> V_26 ) )
continue;
F_9 ( V_192 ) ;
F_25 ( V_91 , & V_19 -> V_26 ) ;
F_2 ( L_25 , V_19 ) ;
F_65 ( V_19 ) ;
}
F_41 ( & V_34 -> V_73 ) ;
F_104 ( & V_34 -> V_166 , V_169 + V_170 * V_162 ) ;
}
void F_124 ( struct V_33 * V_34 , struct V_63 * V_194 )
{
struct V_18 * V_19 ;
struct V_195 * V_196 ;
struct V_197 * V_198 ;
struct V_191 * V_192 , * V_193 ;
F_125 ( V_199 ) ;
struct V_200 V_201 = {
. V_202 = 1 ,
. V_203 = 0 ,
} ;
F_39 ( & V_34 -> V_73 ) ;
F_123 (le, next, &serv->sv_tempsocks) {
V_19 = F_85 ( V_192 , struct V_18 , V_37 ) ;
if ( F_126 ( V_194 , (struct V_63 * )
& V_19 -> V_87 ) ) {
F_2 ( L_26 , V_19 ) ;
F_127 ( V_192 , & V_199 ) ;
}
}
F_41 ( & V_34 -> V_73 ) ;
while ( ! F_67 ( & V_199 ) ) {
V_192 = V_199 . V_193 ;
F_9 ( V_192 ) ;
V_19 = F_85 ( V_192 , struct V_18 , V_37 ) ;
F_2 ( L_27 , V_19 ) ;
V_196 = F_12 ( V_19 , struct V_195 , V_204 ) ;
V_198 = V_196 -> V_205 ;
F_128 ( V_198 , V_206 , V_207 ,
( char * ) & V_201 , sizeof( V_201 ) ) ;
F_129 ( V_19 ) ;
}
}
static void F_130 ( struct V_18 * V_19 )
{
struct V_208 * V_209 ;
F_4 ( & V_19 -> V_42 ) ;
while ( ! F_67 ( & V_19 -> V_40 ) ) {
V_209 = F_69 ( & V_19 -> V_40 , struct V_208 , V_210 ) ;
F_131 ( & V_209 -> V_210 ) ;
V_209 -> V_211 ( V_209 ) ;
}
F_7 ( & V_19 -> V_42 ) ;
}
static void F_106 ( struct V_18 * V_19 )
{
struct V_33 * V_34 = V_19 -> V_36 ;
struct V_212 * V_213 ;
if ( F_55 ( V_186 , & V_19 -> V_26 ) )
F_132 () ;
F_2 ( L_28 , V_19 ) ;
V_19 -> V_30 -> V_214 ( V_19 ) ;
F_39 ( & V_34 -> V_73 ) ;
F_9 ( & V_19 -> V_37 ) ;
F_87 ( ! F_67 ( & V_19 -> V_38 ) ) ;
if ( F_13 ( V_72 , & V_19 -> V_26 ) )
V_34 -> V_133 -- ;
F_41 ( & V_34 -> V_73 ) ;
while ( ( V_213 = F_108 ( V_19 ) ) != NULL )
F_75 ( V_213 ) ;
F_130 ( V_19 ) ;
F_19 ( V_19 ) ;
}
void F_129 ( struct V_18 * V_19 )
{
F_25 ( V_91 , & V_19 -> V_26 ) ;
if ( F_55 ( V_43 , & V_19 -> V_26 ) )
return;
F_106 ( V_19 ) ;
}
static int F_133 ( struct V_33 * V_34 , struct V_191 * V_215 , struct V_32 * V_32 )
{
struct V_18 * V_19 ;
int V_216 = 0 ;
F_4 ( & V_34 -> V_73 ) ;
F_5 (xprt, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_32 )
continue;
V_216 ++ ;
F_25 ( V_91 , & V_19 -> V_26 ) ;
F_65 ( V_19 ) ;
}
F_7 ( & V_34 -> V_73 ) ;
return V_216 ;
}
static struct V_18 * F_134 ( struct V_33 * V_34 , struct V_32 * V_32 )
{
struct V_95 * V_96 ;
struct V_18 * V_19 ;
struct V_18 * V_217 ;
int V_141 ;
for ( V_141 = 0 ; V_141 < V_34 -> V_218 ; V_141 ++ ) {
V_96 = & V_34 -> V_124 [ V_141 ] ;
F_39 ( & V_96 -> V_108 ) ;
F_135 (xprt, tmp, &pool->sp_sockets, xpt_ready) {
if ( V_19 -> V_27 != V_32 )
continue;
F_9 ( & V_19 -> V_38 ) ;
F_41 ( & V_96 -> V_108 ) ;
return V_19 ;
}
F_41 ( & V_96 -> V_108 ) ;
}
return NULL ;
}
static void F_136 ( struct V_33 * V_34 , struct V_32 * V_32 )
{
struct V_18 * V_19 ;
while ( ( V_19 = F_134 ( V_34 , V_32 ) ) ) {
F_25 ( V_91 , & V_19 -> V_26 ) ;
F_106 ( V_19 ) ;
}
}
void F_137 ( struct V_33 * V_34 , struct V_32 * V_32 )
{
int V_219 = 0 ;
while ( F_133 ( V_34 , & V_34 -> V_74 , V_32 ) +
F_133 ( V_34 , & V_34 -> V_134 , V_32 ) ) {
F_136 ( V_34 , V_32 ) ;
F_138 ( V_219 ++ ) ;
}
}
static void F_139 ( struct V_220 * V_221 , int V_222 )
{
struct V_212 * V_213 =
F_12 ( V_221 , struct V_212 , V_223 ) ;
struct V_18 * V_19 = V_213 -> V_19 ;
F_4 ( & V_19 -> V_42 ) ;
F_25 ( V_93 , & V_19 -> V_26 ) ;
if ( V_222 || F_13 ( V_186 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_42 ) ;
F_2 ( L_29 ) ;
F_19 ( V_19 ) ;
F_75 ( V_213 ) ;
return;
}
F_2 ( L_30 ) ;
V_213 -> V_19 = NULL ;
F_40 ( & V_213 -> V_223 . V_224 , & V_19 -> V_39 ) ;
F_7 ( & V_19 -> V_42 ) ;
F_65 ( V_19 ) ;
F_19 ( V_19 ) ;
}
static struct V_220 * V_180 ( struct V_225 * V_226 )
{
struct V_80 * V_81 = F_12 ( V_226 , struct V_80 , V_160 ) ;
struct V_212 * V_213 ;
if ( V_81 -> V_153 . V_121 || ! F_13 ( V_227 , & V_81 -> V_103 ) )
return NULL ;
if ( V_81 -> V_120 ) {
V_213 = V_81 -> V_120 ;
V_81 -> V_120 = NULL ;
} else {
T_1 V_228 ;
T_1 V_229 ;
V_229 = sizeof( struct V_212 ) + V_81 -> V_153 . V_14 ;
V_213 = F_140 ( V_229 , V_148 ) ;
if ( V_213 == NULL )
return NULL ;
V_213 -> V_223 . V_22 = V_81 -> V_137 ;
V_213 -> V_230 = V_81 -> V_231 ;
memcpy ( & V_213 -> V_232 , & V_81 -> V_82 , V_81 -> V_85 ) ;
V_213 -> V_233 = V_81 -> V_85 ;
V_213 -> V_234 = V_81 -> V_86 ;
V_213 -> V_235 = V_81 -> V_153 . V_14 >> 2 ;
V_213 -> V_236 = V_81 -> V_237 ;
V_228 = V_81 -> V_153 . V_14 - V_81 -> V_153 . V_114 [ 0 ] . V_115 ;
memcpy ( V_213 -> args , V_81 -> V_153 . V_114 [ 0 ] . V_154 - V_228 ,
V_213 -> V_235 << 2 ) ;
}
F_35 ( V_81 -> V_105 ) ;
V_213 -> V_19 = V_81 -> V_105 ;
F_25 ( V_238 , & V_81 -> V_103 ) ;
V_213 -> V_223 . V_239 = F_139 ;
return & V_213 -> V_223 ;
}
static int F_109 ( struct V_80 * V_81 )
{
struct V_212 * V_213 = V_81 -> V_120 ;
V_81 -> V_153 . V_114 [ 0 ] . V_154 = V_213 -> args + ( V_213 -> V_236 >> 2 ) ;
V_81 -> V_153 . V_114 [ 0 ] . V_115 = ( V_213 -> V_235 << 2 ) - V_213 -> V_236 ;
V_81 -> V_153 . V_121 = 0 ;
V_81 -> V_153 . V_14 = V_213 -> V_235 << 2 ;
V_81 -> V_231 = V_213 -> V_230 ;
memcpy ( & V_81 -> V_82 , & V_213 -> V_232 , V_213 -> V_233 ) ;
V_81 -> V_85 = V_213 -> V_233 ;
V_81 -> V_237 = V_213 -> V_236 ;
V_81 -> V_86 = V_213 -> V_234 ;
V_81 -> V_240 = V_81 -> V_145 ;
return ( V_213 -> V_235 << 2 ) - V_213 -> V_236 ;
}
static struct V_212 * F_108 ( struct V_18 * V_19 )
{
struct V_212 * V_213 = NULL ;
if ( ! F_13 ( V_93 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_42 ) ;
if ( ! F_67 ( & V_19 -> V_39 ) ) {
V_213 = F_85 ( V_19 -> V_39 . V_193 ,
struct V_212 ,
V_223 . V_224 ) ;
F_9 ( & V_213 -> V_223 . V_224 ) ;
} else
F_37 ( V_93 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_42 ) ;
return V_213 ;
}
struct V_18 * F_141 ( struct V_33 * V_34 , const char * V_6 ,
struct V_32 * V_32 , const T_2 V_241 ,
const unsigned short V_46 )
{
struct V_18 * V_19 ;
struct V_18 * V_242 = NULL ;
if ( V_34 == NULL || V_6 == NULL )
return V_242 ;
F_39 ( & V_34 -> V_73 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( V_19 -> V_27 != V_32 )
continue;
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_241 != V_243 && V_241 != V_19 -> V_87 . V_244 )
continue;
if ( V_46 != 0 && V_46 != F_46 ( V_19 ) )
continue;
V_242 = V_19 ;
F_35 ( V_19 ) ;
break;
}
F_41 ( & V_34 -> V_73 ) ;
return V_242 ;
}
static int F_142 ( const struct V_18 * V_19 ,
char * V_245 , int V_246 )
{
int V_14 ;
V_14 = snprintf ( V_245 , V_246 , L_31 ,
V_19 -> V_23 -> V_6 ,
F_46 ( V_19 ) ) ;
if ( V_14 >= V_246 )
return - V_247 ;
return V_14 ;
}
int F_143 ( struct V_33 * V_34 , char * V_11 , const int V_248 )
{
struct V_18 * V_19 ;
int V_14 , V_249 ;
char * V_245 ;
if ( ! V_34 )
return 0 ;
F_39 ( & V_34 -> V_73 ) ;
V_245 = V_11 ;
V_249 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_142 ( V_19 , V_245 , V_248 - V_249 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_249 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_245 += V_14 ;
V_249 += V_14 ;
}
F_41 ( & V_34 -> V_73 ) ;
return V_249 ;
}
static void * F_144 ( struct V_250 * V_251 , T_3 * V_245 )
{
unsigned int V_252 = ( unsigned int ) * V_245 ;
struct V_33 * V_34 = V_251 -> V_253 ;
F_2 ( L_32 , V_252 ) ;
if ( ! V_252 )
return V_254 ;
return ( V_252 > V_34 -> V_218 ? NULL : & V_34 -> V_124 [ V_252 - 1 ] ) ;
}
static void * F_145 ( struct V_250 * V_251 , void * V_147 , T_3 * V_245 )
{
struct V_95 * V_96 = V_147 ;
struct V_33 * V_34 = V_251 -> V_253 ;
F_2 ( L_33 , * V_245 ) ;
if ( V_147 == V_254 ) {
V_96 = & V_34 -> V_124 [ 0 ] ;
} else {
unsigned int V_252 = ( V_96 - & V_34 -> V_124 [ 0 ] ) ;
if ( V_252 < V_34 -> V_218 - 1 )
V_96 = & V_34 -> V_124 [ V_252 + 1 ] ;
else
V_96 = NULL ;
}
++ * V_245 ;
return V_96 ;
}
static void F_146 ( struct V_250 * V_251 , void * V_147 )
{
}
static int F_147 ( struct V_250 * V_251 , void * V_147 )
{
struct V_95 * V_96 = V_147 ;
if ( V_147 == V_254 ) {
F_148 ( V_251 , L_34 ) ;
return 0 ;
}
F_149 ( V_251 , L_35 ,
V_96 -> V_173 ,
( unsigned long ) F_150 ( & V_96 -> V_99 . V_100 ) ,
V_96 -> V_99 . V_110 ,
( unsigned long ) F_150 ( & V_96 -> V_99 . V_106 ) ,
( unsigned long ) F_150 ( & V_96 -> V_99 . V_163 ) ) ;
return 0 ;
}
int F_151 ( struct V_33 * V_34 , struct V_255 * V_255 )
{
int V_78 ;
V_78 = F_152 ( V_255 , & V_256 ) ;
if ( ! V_78 )
( (struct V_250 * ) V_255 -> V_257 ) -> V_253 = V_34 ;
return V_78 ;
}

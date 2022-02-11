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
unsigned int V_90 = V_91 ;
int V_92 = F_54 ( & V_19 -> V_93 ) ;
return V_90 == 0 || ( V_92 >= 0 && V_92 < V_90 ) ;
}
static bool F_55 ( struct V_80 * V_81 , struct V_18 * V_19 )
{
if ( ! F_13 ( V_94 , & V_81 -> V_95 ) ) {
if ( ! F_53 ( V_19 ) )
return false ;
F_56 ( & V_19 -> V_93 ) ;
F_25 ( V_94 , & V_81 -> V_95 ) ;
}
return true ;
}
static void F_57 ( struct V_80 * V_81 )
{
struct V_18 * V_19 = V_81 -> V_96 ;
if ( F_58 ( V_94 , & V_81 -> V_95 ) ) {
F_59 ( & V_19 -> V_93 ) ;
F_60 ( V_19 ) ;
}
}
static bool F_61 ( struct V_18 * V_19 )
{
if ( V_19 -> V_26 & ( ( 1 << V_97 ) | ( 1 << V_98 ) ) )
return true ;
if ( V_19 -> V_26 & ( ( 1 << V_99 ) | ( 1 << V_100 ) ) ) {
if ( V_19 -> V_30 -> V_101 ( V_19 ) &&
F_53 ( V_19 ) )
return true ;
F_62 ( V_19 ) ;
return false ;
}
return false ;
}
void F_63 ( struct V_18 * V_19 )
{
struct V_102 * V_103 ;
struct V_80 * V_81 = NULL ;
int V_104 ;
bool V_105 = false ;
if ( ! F_61 ( V_19 ) )
goto V_9;
if ( F_64 ( V_43 , & V_19 -> V_26 ) ) {
F_2 ( L_9 , V_19 ) ;
goto V_9;
}
V_104 = F_65 () ;
V_103 = F_66 ( V_19 -> V_36 , V_104 ) ;
F_67 ( & V_103 -> V_106 . V_107 ) ;
V_108:
F_68 () ;
F_69 (rqstp, &pool->sp_all_threads, rq_all) {
if ( F_13 ( V_109 , & V_81 -> V_95 ) )
continue;
if ( ! V_105 ) {
F_39 ( & V_81 -> V_110 ) ;
if ( F_64 ( V_109 , & V_81 -> V_95 ) ) {
F_41 ( & V_81 -> V_110 ) ;
continue;
}
V_81 -> V_96 = V_19 ;
F_35 ( V_19 ) ;
F_41 ( & V_81 -> V_110 ) ;
}
F_70 () ;
F_67 ( & V_103 -> V_106 . V_111 ) ;
F_71 ( V_81 -> V_112 ) ;
F_72 () ;
goto V_9;
}
F_70 () ;
if ( ! V_105 ) {
V_105 = true ;
F_2 ( L_10 , V_19 ) ;
F_39 ( & V_103 -> V_113 ) ;
F_6 ( & V_19 -> V_38 , & V_103 -> V_114 ) ;
V_103 -> V_106 . V_115 ++ ;
F_41 ( & V_103 -> V_113 ) ;
goto V_108;
}
V_81 = NULL ;
F_72 () ;
V_9:
F_73 ( V_19 , V_81 ) ;
}
void F_60 ( struct V_18 * V_19 )
{
if ( F_13 ( V_43 , & V_19 -> V_26 ) )
return;
V_19 -> V_36 -> V_69 -> V_70 ( V_19 ) ;
}
static struct V_18 * F_74 ( struct V_102 * V_103 )
{
struct V_18 * V_19 = NULL ;
if ( F_75 ( & V_103 -> V_114 ) )
goto V_9;
F_39 ( & V_103 -> V_113 ) ;
if ( F_76 ( ! F_75 ( & V_103 -> V_114 ) ) ) {
V_19 = F_77 ( & V_103 -> V_114 ,
struct V_18 , V_38 ) ;
F_9 ( & V_19 -> V_38 ) ;
F_35 ( V_19 ) ;
F_2 ( L_11 ,
V_19 , F_54 ( & V_19 -> V_20 . V_116 ) ) ;
}
F_41 ( & V_103 -> V_113 ) ;
V_9:
F_78 ( V_19 ) ;
return V_19 ;
}
void F_79 ( struct V_80 * V_81 , int V_117 )
{
V_117 += V_81 -> V_118 . V_119 [ 0 ] . V_120 ;
if ( V_117 < V_81 -> V_121 ) {
struct V_18 * V_19 = V_81 -> V_96 ;
F_80 ( ( V_81 -> V_121 - V_117 ) , & V_19 -> V_122 ) ;
V_81 -> V_121 = V_117 ;
F_60 ( V_19 ) ;
}
}
static void F_81 ( struct V_80 * V_81 )
{
struct V_18 * V_19 = V_81 -> V_96 ;
V_81 -> V_96 -> V_30 -> V_123 ( V_81 ) ;
F_82 ( V_81 -> V_124 ) ;
V_81 -> V_124 = NULL ;
F_83 ( V_81 ) ;
V_81 -> V_118 . V_125 = 0 ;
V_81 -> V_118 . V_126 = 0 ;
if ( ( V_81 -> V_118 . V_14 ) > V_81 -> V_121 )
F_84 ( V_127 L_12 ,
V_81 -> V_121 ,
V_81 -> V_118 . V_14 ) ;
V_81 -> V_118 . V_119 [ 0 ] . V_120 = 0 ;
F_79 ( V_81 , 0 ) ;
F_57 ( V_81 ) ;
V_81 -> V_96 = NULL ;
F_19 ( V_19 ) ;
}
void F_85 ( struct V_33 * V_34 )
{
struct V_80 * V_81 ;
struct V_102 * V_103 ;
V_103 = & V_34 -> V_128 [ 0 ] ;
F_68 () ;
F_69 (rqstp, &pool->sp_all_threads, rq_all) {
if ( F_13 ( V_109 , & V_81 -> V_95 ) )
continue;
F_70 () ;
F_2 ( L_13 , V_81 ) ;
F_71 ( V_81 -> V_112 ) ;
F_86 ( V_81 -> V_112 -> V_129 ) ;
return;
}
F_70 () ;
F_25 ( V_130 , & V_103 -> V_131 ) ;
F_87 () ;
F_86 ( 0 ) ;
}
int F_88 ( struct V_63 * sin )
{
switch ( sin -> V_132 ) {
case V_50 :
return F_89 ( ( (struct V_48 * ) sin ) -> V_54 )
< V_133 ;
case V_59 :
return F_89 ( ( (struct V_56 * ) sin ) -> V_62 )
< V_133 ;
default:
return 0 ;
}
}
static void F_90 ( struct V_33 * V_34 )
{
unsigned int V_90 = V_34 -> V_134 ? V_34 -> V_134 :
( V_34 -> V_135 + 3 ) * 20 ;
if ( V_34 -> V_136 > V_90 ) {
struct V_18 * V_19 = NULL ;
F_39 ( & V_34 -> V_73 ) ;
if ( ! F_75 ( & V_34 -> V_137 ) ) {
F_91 ( L_14 ,
V_34 -> V_138 , V_34 -> V_134 ?
L_15 :
L_16 ) ;
V_19 = F_92 ( V_34 -> V_137 . V_139 ,
struct V_18 ,
V_37 ) ;
F_25 ( V_98 , & V_19 -> V_26 ) ;
F_35 ( V_19 ) ;
}
F_41 ( & V_34 -> V_73 ) ;
if ( V_19 ) {
F_60 ( V_19 ) ;
F_19 ( V_19 ) ;
}
}
}
static int F_93 ( struct V_80 * V_81 )
{
struct V_33 * V_34 = V_81 -> V_140 ;
struct V_141 * V_142 ;
int V_143 ;
int V_144 ;
V_143 = ( V_34 -> V_145 + V_146 ) / V_146 ;
F_94 ( V_143 >= V_147 ) ;
if ( V_143 >= V_147 )
V_143 = V_147 - 1 ;
for ( V_144 = 0 ; V_144 < V_143 ; V_144 ++ )
while ( V_81 -> V_148 [ V_144 ] == NULL ) {
struct V_149 * V_150 = F_95 ( V_151 ) ;
if ( ! V_150 ) {
F_96 ( V_152 ) ;
if ( F_97 () || F_98 () ) {
F_96 ( V_153 ) ;
return - V_154 ;
}
F_99 ( F_100 ( 500 ) ) ;
}
V_81 -> V_148 [ V_144 ] = V_150 ;
}
V_81 -> V_155 = & V_81 -> V_148 [ V_144 ] ;
V_81 -> V_148 [ V_144 ++ ] = NULL ;
V_142 = & V_81 -> V_156 ;
V_142 -> V_119 [ 0 ] . V_157 = F_101 ( V_81 -> V_148 [ 0 ] ) ;
V_142 -> V_119 [ 0 ] . V_120 = V_146 ;
V_142 -> V_143 = V_81 -> V_148 + 1 ;
V_142 -> V_126 = 0 ;
V_142 -> V_125 = ( V_143 - 2 ) * V_146 ;
V_142 -> V_14 = ( V_143 - 1 ) * V_146 ;
V_142 -> V_158 [ 0 ] . V_120 = 0 ;
return 0 ;
}
static bool
F_102 ( struct V_80 * V_81 )
{
struct V_102 * V_103 = V_81 -> V_159 ;
if ( F_58 ( V_130 , & V_103 -> V_131 ) )
return false ;
if ( ! F_75 ( & V_103 -> V_114 ) )
return false ;
if ( F_97 () || F_98 () )
return false ;
if ( F_103 ( V_160 ) )
return false ;
return true ;
}
static struct V_18 * F_104 ( struct V_80 * V_81 , long V_161 )
{
struct V_18 * V_19 ;
struct V_102 * V_103 = V_81 -> V_159 ;
long V_162 = 0 ;
F_94 ( V_81 -> V_96 ) ;
V_81 -> V_163 . V_164 = 5 * V_165 ;
V_19 = F_74 ( V_103 ) ;
if ( V_19 ) {
V_81 -> V_96 = V_19 ;
V_81 -> V_163 . V_164 = 1 * V_165 ;
F_37 ( V_130 , & V_103 -> V_131 ) ;
return V_19 ;
}
F_96 ( V_152 ) ;
F_37 ( V_109 , & V_81 -> V_95 ) ;
F_105 () ;
if ( F_76 ( F_102 ( V_81 ) ) )
V_162 = F_99 ( V_161 ) ;
else
F_106 ( V_153 ) ;
F_107 () ;
F_39 ( & V_81 -> V_110 ) ;
F_25 ( V_109 , & V_81 -> V_95 ) ;
F_41 ( & V_81 -> V_110 ) ;
V_19 = V_81 -> V_96 ;
if ( V_19 != NULL )
return V_19 ;
if ( ! V_162 )
F_67 ( & V_103 -> V_106 . V_166 ) ;
if ( F_97 () || F_98 () )
return F_32 ( - V_154 ) ;
return F_32 ( - V_167 ) ;
}
static void F_108 ( struct V_33 * V_34 , struct V_18 * V_168 )
{
F_39 ( & V_34 -> V_73 ) ;
F_25 ( V_72 , & V_168 -> V_26 ) ;
F_40 ( & V_168 -> V_37 , & V_34 -> V_137 ) ;
V_34 -> V_136 ++ ;
if ( V_34 -> V_169 . V_170 == NULL ) {
F_109 ( & V_34 -> V_169 , V_171 ,
( unsigned long ) V_34 ) ;
F_110 ( & V_34 -> V_169 ,
V_172 + V_173 * V_165 ) ;
}
F_41 ( & V_34 -> V_73 ) ;
F_33 ( V_168 ) ;
}
static int F_111 ( struct V_80 * V_81 , struct V_18 * V_19 )
{
struct V_33 * V_34 = V_81 -> V_140 ;
int V_14 = 0 ;
if ( F_13 ( V_98 , & V_19 -> V_26 ) ) {
F_2 ( L_17 ) ;
F_112 ( V_19 ) ;
goto V_9;
}
if ( F_13 ( V_174 , & V_19 -> V_26 ) ) {
struct V_18 * V_168 ;
F_113 ( V_19 -> V_23 -> V_24 ) ;
F_90 ( V_19 -> V_36 ) ;
V_168 = V_19 -> V_30 -> V_175 ( V_19 ) ;
if ( V_168 )
F_108 ( V_34 , V_168 ) ;
else
F_18 ( V_19 -> V_23 -> V_24 ) ;
} else if ( F_55 ( V_81 , V_19 ) ) {
F_2 ( L_18 ,
V_81 , V_81 -> V_159 -> V_176 , V_19 ,
F_54 ( & V_19 -> V_20 . V_116 ) ) ;
V_81 -> V_124 = F_114 ( V_19 ) ;
if ( V_81 -> V_124 )
V_14 = F_115 ( V_81 ) ;
else
V_14 = V_19 -> V_30 -> V_177 ( V_81 ) ;
F_2 ( L_19 , V_14 ) ;
V_81 -> V_121 = V_34 -> V_145 ;
F_116 ( V_81 -> V_121 , & V_19 -> V_122 ) ;
}
F_33 ( V_19 ) ;
V_9:
F_117 ( V_19 , V_14 ) ;
return V_14 ;
}
int F_118 ( struct V_80 * V_81 , long V_161 )
{
struct V_18 * V_19 = NULL ;
struct V_33 * V_34 = V_81 -> V_140 ;
int V_14 , V_78 ;
F_2 ( L_20 ,
V_81 , V_161 ) ;
if ( V_81 -> V_96 )
F_84 ( V_127
L_21 ,
V_81 ) ;
V_78 = F_93 ( V_81 ) ;
if ( V_78 )
goto V_9;
F_107 () ;
F_119 () ;
V_78 = - V_154 ;
if ( F_97 () || F_98 () )
goto V_9;
V_19 = F_104 ( V_81 , V_161 ) ;
if ( F_44 ( V_19 ) ) {
V_78 = F_45 ( V_19 ) ;
goto V_9;
}
V_14 = F_111 ( V_81 , V_19 ) ;
V_78 = - V_167 ;
if ( V_14 <= 0 )
goto V_178;
F_37 ( V_179 , & V_19 -> V_26 ) ;
if ( V_19 -> V_30 -> V_180 ( V_81 ) )
F_25 ( V_181 , & V_81 -> V_95 ) ;
else
F_37 ( V_181 , & V_81 -> V_95 ) ;
V_81 -> V_163 . V_182 = V_183 ;
V_81 -> V_184 = F_120 ( & V_81 -> V_156 . V_119 [ 0 ] ) ;
if ( V_34 -> V_185 )
V_34 -> V_185 -> V_186 ++ ;
F_121 ( V_81 , V_14 ) ;
return V_14 ;
V_178:
V_81 -> V_118 . V_14 = 0 ;
F_81 ( V_81 ) ;
V_9:
F_121 ( V_81 , V_78 ) ;
return V_78 ;
}
void F_122 ( struct V_80 * V_81 )
{
F_123 ( V_81 ) ;
F_2 ( L_22 , V_81 -> V_96 ) ;
F_81 ( V_81 ) ;
}
int F_124 ( struct V_80 * V_81 )
{
struct V_18 * V_19 ;
int V_14 = - V_187 ;
struct V_141 * V_188 ;
V_19 = V_81 -> V_96 ;
if ( ! V_19 )
goto V_9;
V_81 -> V_96 -> V_30 -> V_123 ( V_81 ) ;
V_188 = & V_81 -> V_118 ;
V_188 -> V_14 = V_188 -> V_119 [ 0 ] . V_120 +
V_188 -> V_125 +
V_188 -> V_158 [ 0 ] . V_120 ;
F_125 ( & V_19 -> V_41 ) ;
if ( F_13 ( V_189 , & V_19 -> V_26 )
|| F_13 ( V_98 , & V_19 -> V_26 ) )
V_14 = - V_190 ;
else
V_14 = V_19 -> V_30 -> V_191 ( V_81 ) ;
F_126 ( & V_19 -> V_41 ) ;
F_127 ( & V_19 -> V_44 ) ;
F_81 ( V_81 ) ;
if ( V_14 == - V_192 || V_14 == - V_190 || V_14 == - V_167 )
V_14 = 0 ;
V_9:
F_128 ( V_81 , V_14 ) ;
return V_14 ;
}
static void V_171 ( unsigned long V_193 )
{
struct V_33 * V_34 = (struct V_33 * ) V_193 ;
struct V_18 * V_19 ;
struct V_194 * V_195 , * V_196 ;
F_2 ( L_23 ) ;
if ( ! F_129 ( & V_34 -> V_73 ) ) {
F_2 ( L_24 ) ;
F_110 ( & V_34 -> V_169 , V_172 + V_165 ) ;
return;
}
F_130 (le, next, &serv->sv_tempsocks) {
V_19 = F_92 ( V_195 , struct V_18 , V_37 ) ;
if ( ! F_64 ( V_179 , & V_19 -> V_26 ) )
continue;
if ( F_54 ( & V_19 -> V_20 . V_116 ) > 1 ||
F_13 ( V_43 , & V_19 -> V_26 ) )
continue;
F_9 ( V_195 ) ;
F_25 ( V_98 , & V_19 -> V_26 ) ;
F_2 ( L_25 , V_19 ) ;
F_60 ( V_19 ) ;
}
F_41 ( & V_34 -> V_73 ) ;
F_110 ( & V_34 -> V_169 , V_172 + V_173 * V_165 ) ;
}
void F_131 ( struct V_33 * V_34 , struct V_63 * V_197 )
{
struct V_18 * V_19 ;
struct V_194 * V_195 , * V_196 ;
F_132 ( V_198 ) ;
F_39 ( & V_34 -> V_73 ) ;
F_130 (le, next, &serv->sv_tempsocks) {
V_19 = F_92 ( V_195 , struct V_18 , V_37 ) ;
if ( F_133 ( V_197 , (struct V_63 * )
& V_19 -> V_87 ) ) {
F_2 ( L_26 , V_19 ) ;
F_134 ( V_195 , & V_198 ) ;
}
}
F_41 ( & V_34 -> V_73 ) ;
while ( ! F_75 ( & V_198 ) ) {
V_195 = V_198 . V_196 ;
F_9 ( V_195 ) ;
V_19 = F_92 ( V_195 , struct V_18 , V_37 ) ;
F_2 ( L_27 , V_19 ) ;
V_19 -> V_30 -> V_199 ( V_19 ) ;
F_135 ( V_19 ) ;
}
}
static void F_136 ( struct V_18 * V_19 )
{
struct V_200 * V_201 ;
F_4 ( & V_19 -> V_42 ) ;
while ( ! F_75 ( & V_19 -> V_40 ) ) {
V_201 = F_77 ( & V_19 -> V_40 , struct V_200 , V_202 ) ;
F_137 ( & V_201 -> V_202 ) ;
V_201 -> V_203 ( V_201 ) ;
}
F_7 ( & V_19 -> V_42 ) ;
}
static void F_112 ( struct V_18 * V_19 )
{
struct V_33 * V_34 = V_19 -> V_36 ;
struct V_204 * V_205 ;
if ( F_64 ( V_189 , & V_19 -> V_26 ) )
F_138 () ;
F_2 ( L_28 , V_19 ) ;
V_19 -> V_30 -> V_206 ( V_19 ) ;
F_39 ( & V_34 -> V_73 ) ;
F_9 ( & V_19 -> V_37 ) ;
F_94 ( ! F_75 ( & V_19 -> V_38 ) ) ;
if ( F_13 ( V_72 , & V_19 -> V_26 ) )
V_34 -> V_136 -- ;
F_41 ( & V_34 -> V_73 ) ;
while ( ( V_205 = F_114 ( V_19 ) ) != NULL )
F_82 ( V_205 ) ;
F_136 ( V_19 ) ;
F_19 ( V_19 ) ;
}
void F_135 ( struct V_18 * V_19 )
{
F_25 ( V_98 , & V_19 -> V_26 ) ;
if ( F_64 ( V_43 , & V_19 -> V_26 ) )
return;
F_112 ( V_19 ) ;
}
static int F_139 ( struct V_33 * V_34 , struct V_194 * V_207 , struct V_32 * V_32 )
{
struct V_18 * V_19 ;
int V_208 = 0 ;
F_4 ( & V_34 -> V_73 ) ;
F_5 (xprt, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_32 )
continue;
V_208 ++ ;
F_25 ( V_98 , & V_19 -> V_26 ) ;
F_60 ( V_19 ) ;
}
F_7 ( & V_34 -> V_73 ) ;
return V_208 ;
}
static struct V_18 * F_140 ( struct V_33 * V_34 , struct V_32 * V_32 )
{
struct V_102 * V_103 ;
struct V_18 * V_19 ;
struct V_18 * V_209 ;
int V_144 ;
for ( V_144 = 0 ; V_144 < V_34 -> V_210 ; V_144 ++ ) {
V_103 = & V_34 -> V_128 [ V_144 ] ;
F_39 ( & V_103 -> V_113 ) ;
F_141 (xprt, tmp, &pool->sp_sockets, xpt_ready) {
if ( V_19 -> V_27 != V_32 )
continue;
F_9 ( & V_19 -> V_38 ) ;
F_41 ( & V_103 -> V_113 ) ;
return V_19 ;
}
F_41 ( & V_103 -> V_113 ) ;
}
return NULL ;
}
static void F_142 ( struct V_33 * V_34 , struct V_32 * V_32 )
{
struct V_18 * V_19 ;
while ( ( V_19 = F_140 ( V_34 , V_32 ) ) ) {
F_25 ( V_98 , & V_19 -> V_26 ) ;
F_112 ( V_19 ) ;
}
}
void F_143 ( struct V_33 * V_34 , struct V_32 * V_32 )
{
int V_211 = 0 ;
while ( F_139 ( V_34 , & V_34 -> V_74 , V_32 ) +
F_139 ( V_34 , & V_34 -> V_137 , V_32 ) ) {
F_142 ( V_34 , V_32 ) ;
F_144 ( V_211 ++ ) ;
}
}
static void F_145 ( struct V_212 * V_213 , int V_214 )
{
struct V_204 * V_205 =
F_12 ( V_213 , struct V_204 , V_215 ) ;
struct V_18 * V_19 = V_205 -> V_19 ;
F_4 ( & V_19 -> V_42 ) ;
F_25 ( V_100 , & V_19 -> V_26 ) ;
if ( V_214 || F_13 ( V_189 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_42 ) ;
F_2 ( L_29 ) ;
F_19 ( V_19 ) ;
F_146 ( V_205 ) ;
F_82 ( V_205 ) ;
return;
}
F_2 ( L_30 ) ;
V_205 -> V_19 = NULL ;
F_40 ( & V_205 -> V_215 . V_216 , & V_19 -> V_39 ) ;
F_7 ( & V_19 -> V_42 ) ;
F_60 ( V_19 ) ;
F_19 ( V_19 ) ;
}
static struct V_212 * V_183 ( struct V_217 * V_218 )
{
struct V_80 * V_81 = F_12 ( V_218 , struct V_80 , V_163 ) ;
struct V_204 * V_205 ;
if ( V_81 -> V_156 . V_125 || ! F_13 ( V_219 , & V_81 -> V_95 ) )
return NULL ;
if ( V_81 -> V_124 ) {
V_205 = V_81 -> V_124 ;
V_81 -> V_124 = NULL ;
} else {
T_1 V_220 ;
T_1 V_221 ;
V_221 = sizeof( struct V_204 ) + V_81 -> V_156 . V_14 ;
V_205 = F_147 ( V_221 , V_151 ) ;
if ( V_205 == NULL )
return NULL ;
V_205 -> V_215 . V_22 = V_81 -> V_140 ;
V_205 -> V_222 = V_81 -> V_223 ;
memcpy ( & V_205 -> V_224 , & V_81 -> V_82 , V_81 -> V_85 ) ;
V_205 -> V_225 = V_81 -> V_85 ;
V_205 -> V_226 = V_81 -> V_86 ;
V_205 -> V_227 = V_81 -> V_156 . V_14 >> 2 ;
V_205 -> V_228 = V_81 -> V_229 ;
V_220 = V_81 -> V_156 . V_14 - V_81 -> V_156 . V_119 [ 0 ] . V_120 ;
memcpy ( V_205 -> args , V_81 -> V_156 . V_119 [ 0 ] . V_157 - V_220 ,
V_205 -> V_227 << 2 ) ;
}
F_35 ( V_81 -> V_96 ) ;
V_205 -> V_19 = V_81 -> V_96 ;
F_25 ( V_230 , & V_81 -> V_95 ) ;
V_205 -> V_215 . V_231 = F_145 ;
F_148 ( V_81 ) ;
return & V_205 -> V_215 ;
}
static int F_115 ( struct V_80 * V_81 )
{
struct V_204 * V_205 = V_81 -> V_124 ;
V_81 -> V_156 . V_119 [ 0 ] . V_157 = V_205 -> args + ( V_205 -> V_228 >> 2 ) ;
V_81 -> V_156 . V_119 [ 0 ] . V_120 = ( V_205 -> V_227 << 2 ) - V_205 -> V_228 ;
V_81 -> V_156 . V_125 = 0 ;
V_81 -> V_156 . V_14 = V_205 -> V_227 << 2 ;
V_81 -> V_223 = V_205 -> V_222 ;
memcpy ( & V_81 -> V_82 , & V_205 -> V_224 , V_205 -> V_225 ) ;
V_81 -> V_85 = V_205 -> V_225 ;
V_81 -> V_229 = V_205 -> V_228 ;
V_81 -> V_86 = V_205 -> V_226 ;
V_81 -> V_232 = V_81 -> V_148 ;
return ( V_205 -> V_227 << 2 ) - V_205 -> V_228 ;
}
static struct V_204 * F_114 ( struct V_18 * V_19 )
{
struct V_204 * V_205 = NULL ;
if ( ! F_13 ( V_100 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_42 ) ;
if ( ! F_75 ( & V_19 -> V_39 ) ) {
V_205 = F_92 ( V_19 -> V_39 . V_196 ,
struct V_204 ,
V_215 . V_216 ) ;
F_9 ( & V_205 -> V_215 . V_216 ) ;
F_149 ( V_205 ) ;
} else
F_37 ( V_100 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_42 ) ;
return V_205 ;
}
struct V_18 * F_150 ( struct V_33 * V_34 , const char * V_6 ,
struct V_32 * V_32 , const T_2 V_233 ,
const unsigned short V_46 )
{
struct V_18 * V_19 ;
struct V_18 * V_234 = NULL ;
if ( V_34 == NULL || V_6 == NULL )
return V_234 ;
F_39 ( & V_34 -> V_73 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( V_19 -> V_27 != V_32 )
continue;
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_233 != V_235 && V_233 != V_19 -> V_87 . V_236 )
continue;
if ( V_46 != 0 && V_46 != F_46 ( V_19 ) )
continue;
V_234 = V_19 ;
F_35 ( V_19 ) ;
break;
}
F_41 ( & V_34 -> V_73 ) ;
return V_234 ;
}
static int F_151 ( const struct V_18 * V_19 ,
char * V_237 , int V_238 )
{
int V_14 ;
V_14 = snprintf ( V_237 , V_238 , L_31 ,
V_19 -> V_23 -> V_6 ,
F_46 ( V_19 ) ) ;
if ( V_14 >= V_238 )
return - V_239 ;
return V_14 ;
}
int F_152 ( struct V_33 * V_34 , char * V_11 , const int V_240 )
{
struct V_18 * V_19 ;
int V_14 , V_241 ;
char * V_237 ;
if ( ! V_34 )
return 0 ;
F_39 ( & V_34 -> V_73 ) ;
V_237 = V_11 ;
V_241 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_151 ( V_19 , V_237 , V_240 - V_241 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_241 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_237 += V_14 ;
V_241 += V_14 ;
}
F_41 ( & V_34 -> V_73 ) ;
return V_241 ;
}
static void * F_153 ( struct V_242 * V_243 , T_3 * V_237 )
{
unsigned int V_244 = ( unsigned int ) * V_237 ;
struct V_33 * V_34 = V_243 -> V_245 ;
F_2 ( L_32 , V_244 ) ;
if ( ! V_244 )
return V_246 ;
return ( V_244 > V_34 -> V_210 ? NULL : & V_34 -> V_128 [ V_244 - 1 ] ) ;
}
static void * F_154 ( struct V_242 * V_243 , void * V_150 , T_3 * V_237 )
{
struct V_102 * V_103 = V_150 ;
struct V_33 * V_34 = V_243 -> V_245 ;
F_2 ( L_33 , * V_237 ) ;
if ( V_150 == V_246 ) {
V_103 = & V_34 -> V_128 [ 0 ] ;
} else {
unsigned int V_244 = ( V_103 - & V_34 -> V_128 [ 0 ] ) ;
if ( V_244 < V_34 -> V_210 - 1 )
V_103 = & V_34 -> V_128 [ V_244 + 1 ] ;
else
V_103 = NULL ;
}
++ * V_237 ;
return V_103 ;
}
static void F_155 ( struct V_242 * V_243 , void * V_150 )
{
}
static int F_156 ( struct V_242 * V_243 , void * V_150 )
{
struct V_102 * V_103 = V_150 ;
if ( V_150 == V_246 ) {
F_157 ( V_243 , L_34 ) ;
return 0 ;
}
F_158 ( V_243 , L_35 ,
V_103 -> V_176 ,
( unsigned long ) F_159 ( & V_103 -> V_106 . V_107 ) ,
V_103 -> V_106 . V_115 ,
( unsigned long ) F_159 ( & V_103 -> V_106 . V_111 ) ,
( unsigned long ) F_159 ( & V_103 -> V_106 . V_166 ) ) ;
return 0 ;
}
int F_160 ( struct V_33 * V_34 , struct V_247 * V_247 )
{
int V_78 ;
V_78 = F_161 ( V_247 , & V_248 ) ;
if ( ! V_78 )
( (struct V_242 * ) V_247 -> V_249 ) -> V_245 = V_34 ;
return V_78 ;
}

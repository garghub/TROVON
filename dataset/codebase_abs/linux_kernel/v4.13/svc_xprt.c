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
V_19 , F_78 ( & V_19 -> V_20 ) ) ;
}
F_41 ( & V_103 -> V_113 ) ;
V_9:
F_79 ( V_19 ) ;
return V_19 ;
}
void F_80 ( struct V_80 * V_81 , int V_116 )
{
V_116 += V_81 -> V_117 . V_118 [ 0 ] . V_119 ;
if ( V_116 < V_81 -> V_120 ) {
struct V_18 * V_19 = V_81 -> V_96 ;
F_81 ( ( V_81 -> V_120 - V_116 ) , & V_19 -> V_121 ) ;
V_81 -> V_120 = V_116 ;
F_60 ( V_19 ) ;
}
}
static void F_82 ( struct V_80 * V_81 )
{
struct V_18 * V_19 = V_81 -> V_96 ;
V_81 -> V_96 -> V_30 -> V_122 ( V_81 ) ;
F_83 ( V_81 -> V_123 ) ;
V_81 -> V_123 = NULL ;
F_84 ( V_81 ) ;
V_81 -> V_117 . V_124 = 0 ;
V_81 -> V_117 . V_125 = 0 ;
if ( ( V_81 -> V_117 . V_14 ) > V_81 -> V_120 )
F_85 ( V_126 L_12 ,
V_81 -> V_120 ,
V_81 -> V_117 . V_14 ) ;
V_81 -> V_117 . V_118 [ 0 ] . V_119 = 0 ;
F_80 ( V_81 , 0 ) ;
F_57 ( V_81 ) ;
V_81 -> V_96 = NULL ;
F_19 ( V_19 ) ;
}
void F_86 ( struct V_33 * V_34 )
{
struct V_80 * V_81 ;
struct V_102 * V_103 ;
V_103 = & V_34 -> V_127 [ 0 ] ;
F_68 () ;
F_69 (rqstp, &pool->sp_all_threads, rq_all) {
if ( F_13 ( V_109 , & V_81 -> V_95 ) )
continue;
F_70 () ;
F_2 ( L_13 , V_81 ) ;
F_71 ( V_81 -> V_112 ) ;
F_87 ( V_81 -> V_112 -> V_128 ) ;
return;
}
F_70 () ;
F_25 ( V_129 , & V_103 -> V_130 ) ;
F_88 () ;
F_87 ( 0 ) ;
}
int F_89 ( struct V_63 * sin )
{
switch ( sin -> V_131 ) {
case V_50 :
return F_90 ( ( (struct V_48 * ) sin ) -> V_54 )
< V_132 ;
case V_59 :
return F_90 ( ( (struct V_56 * ) sin ) -> V_62 )
< V_132 ;
default:
return 0 ;
}
}
static void F_91 ( struct V_33 * V_34 )
{
unsigned int V_90 = V_34 -> V_133 ? V_34 -> V_133 :
( V_34 -> V_134 + 3 ) * 20 ;
if ( V_34 -> V_135 > V_90 ) {
struct V_18 * V_19 = NULL ;
F_39 ( & V_34 -> V_73 ) ;
if ( ! F_75 ( & V_34 -> V_136 ) ) {
F_92 ( L_14 ,
V_34 -> V_137 , V_34 -> V_133 ?
L_15 :
L_16 ) ;
V_19 = F_93 ( V_34 -> V_136 . V_138 ,
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
static int F_94 ( struct V_80 * V_81 )
{
struct V_33 * V_34 = V_81 -> V_139 ;
struct V_140 * V_141 ;
int V_142 ;
int V_143 ;
V_142 = ( V_34 -> V_144 + 2 * V_145 ) >> V_146 ;
if ( V_142 > V_147 ) {
F_95 ( L_17 ,
V_142 , V_147 ) ;
V_142 = V_147 ;
}
for ( V_143 = 0 ; V_143 < V_142 ; V_143 ++ )
while ( V_81 -> V_148 [ V_143 ] == NULL ) {
struct V_149 * V_150 = F_96 ( V_151 ) ;
if ( ! V_150 ) {
F_97 ( V_152 ) ;
if ( F_98 () || F_99 () ) {
F_97 ( V_153 ) ;
return - V_154 ;
}
F_100 ( F_101 ( 500 ) ) ;
}
V_81 -> V_148 [ V_143 ] = V_150 ;
}
V_81 -> V_155 = & V_81 -> V_148 [ V_143 ] ;
V_81 -> V_148 [ V_143 ++ ] = NULL ;
V_141 = & V_81 -> V_156 ;
V_141 -> V_118 [ 0 ] . V_157 = F_102 ( V_81 -> V_148 [ 0 ] ) ;
V_141 -> V_118 [ 0 ] . V_119 = V_145 ;
V_141 -> V_142 = V_81 -> V_148 + 1 ;
V_141 -> V_125 = 0 ;
V_141 -> V_124 = ( V_142 - 2 ) * V_145 ;
V_141 -> V_14 = ( V_142 - 1 ) * V_145 ;
V_141 -> V_158 [ 0 ] . V_119 = 0 ;
return 0 ;
}
static bool
F_103 ( struct V_80 * V_81 )
{
struct V_102 * V_103 = V_81 -> V_159 ;
if ( F_58 ( V_129 , & V_103 -> V_130 ) )
return false ;
if ( ! F_75 ( & V_103 -> V_114 ) )
return false ;
if ( F_98 () || F_99 () )
return false ;
if ( F_104 ( V_160 ) )
return false ;
return true ;
}
static struct V_18 * F_105 ( struct V_80 * V_81 , long V_161 )
{
struct V_18 * V_19 ;
struct V_102 * V_103 = V_81 -> V_159 ;
long V_162 = 0 ;
F_106 ( V_81 -> V_96 ) ;
V_81 -> V_163 . V_164 = 5 * V_165 ;
V_19 = F_74 ( V_103 ) ;
if ( V_19 ) {
V_81 -> V_96 = V_19 ;
V_81 -> V_163 . V_164 = 1 * V_165 ;
F_37 ( V_129 , & V_103 -> V_130 ) ;
return V_19 ;
}
F_97 ( V_152 ) ;
F_37 ( V_109 , & V_81 -> V_95 ) ;
F_107 () ;
if ( F_76 ( F_103 ( V_81 ) ) )
V_162 = F_100 ( V_161 ) ;
else
F_108 ( V_153 ) ;
F_109 () ;
F_39 ( & V_81 -> V_110 ) ;
F_25 ( V_109 , & V_81 -> V_95 ) ;
F_41 ( & V_81 -> V_110 ) ;
V_19 = V_81 -> V_96 ;
if ( V_19 != NULL )
return V_19 ;
if ( ! V_162 )
F_67 ( & V_103 -> V_106 . V_166 ) ;
if ( F_98 () || F_99 () )
return F_32 ( - V_154 ) ;
return F_32 ( - V_167 ) ;
}
static void F_110 ( struct V_33 * V_34 , struct V_18 * V_168 )
{
F_39 ( & V_34 -> V_73 ) ;
F_25 ( V_72 , & V_168 -> V_26 ) ;
F_40 ( & V_168 -> V_37 , & V_34 -> V_136 ) ;
V_34 -> V_135 ++ ;
if ( V_34 -> V_169 . V_170 == NULL ) {
F_111 ( & V_34 -> V_169 , V_171 ,
( unsigned long ) V_34 ) ;
F_112 ( & V_34 -> V_169 ,
V_172 + V_173 * V_165 ) ;
}
F_41 ( & V_34 -> V_73 ) ;
F_33 ( V_168 ) ;
}
static int F_113 ( struct V_80 * V_81 , struct V_18 * V_19 )
{
struct V_33 * V_34 = V_81 -> V_139 ;
int V_14 = 0 ;
if ( F_13 ( V_98 , & V_19 -> V_26 ) ) {
F_2 ( L_18 ) ;
if ( F_58 ( V_174 , & V_19 -> V_26 ) )
V_19 -> V_30 -> V_175 ( V_19 ) ;
F_114 ( V_19 ) ;
goto V_9;
}
if ( F_13 ( V_176 , & V_19 -> V_26 ) ) {
struct V_18 * V_168 ;
F_115 ( V_19 -> V_23 -> V_24 ) ;
F_91 ( V_19 -> V_36 ) ;
V_168 = V_19 -> V_30 -> V_177 ( V_19 ) ;
if ( V_168 )
F_110 ( V_34 , V_168 ) ;
else
F_18 ( V_19 -> V_23 -> V_24 ) ;
} else if ( F_55 ( V_81 , V_19 ) ) {
F_2 ( L_19 ,
V_81 , V_81 -> V_159 -> V_178 , V_19 ,
F_78 ( & V_19 -> V_20 ) ) ;
V_81 -> V_123 = F_116 ( V_19 ) ;
if ( V_81 -> V_123 )
V_14 = F_117 ( V_81 ) ;
else
V_14 = V_19 -> V_30 -> V_179 ( V_81 ) ;
F_2 ( L_20 , V_14 ) ;
V_81 -> V_120 = V_34 -> V_144 ;
F_118 ( V_81 -> V_120 , & V_19 -> V_121 ) ;
}
F_33 ( V_19 ) ;
V_9:
F_119 ( V_19 , V_14 ) ;
return V_14 ;
}
int F_120 ( struct V_80 * V_81 , long V_161 )
{
struct V_18 * V_19 = NULL ;
struct V_33 * V_34 = V_81 -> V_139 ;
int V_14 , V_78 ;
F_2 ( L_21 ,
V_81 , V_161 ) ;
if ( V_81 -> V_96 )
F_85 ( V_126
L_22 ,
V_81 ) ;
V_78 = F_94 ( V_81 ) ;
if ( V_78 )
goto V_9;
F_109 () ;
F_121 () ;
V_78 = - V_154 ;
if ( F_98 () || F_99 () )
goto V_9;
V_19 = F_105 ( V_81 , V_161 ) ;
if ( F_44 ( V_19 ) ) {
V_78 = F_45 ( V_19 ) ;
goto V_9;
}
V_14 = F_113 ( V_81 , V_19 ) ;
V_78 = - V_167 ;
if ( V_14 <= 0 )
goto V_180;
F_37 ( V_181 , & V_19 -> V_26 ) ;
if ( V_19 -> V_30 -> V_182 ( V_81 ) )
F_25 ( V_183 , & V_81 -> V_95 ) ;
else
F_37 ( V_183 , & V_81 -> V_95 ) ;
V_81 -> V_163 . V_184 = V_185 ;
V_81 -> V_186 = F_122 ( & V_81 -> V_156 . V_118 [ 0 ] ) ;
if ( V_34 -> V_187 )
V_34 -> V_187 -> V_188 ++ ;
F_123 ( V_81 , V_14 ) ;
return V_14 ;
V_180:
V_81 -> V_117 . V_14 = 0 ;
F_82 ( V_81 ) ;
V_9:
F_123 ( V_81 , V_78 ) ;
return V_78 ;
}
void F_124 ( struct V_80 * V_81 )
{
F_125 ( V_81 ) ;
F_2 ( L_23 , V_81 -> V_96 ) ;
F_82 ( V_81 ) ;
}
int F_126 ( struct V_80 * V_81 )
{
struct V_18 * V_19 ;
int V_14 = - V_189 ;
struct V_140 * V_190 ;
V_19 = V_81 -> V_96 ;
if ( ! V_19 )
goto V_9;
V_81 -> V_96 -> V_30 -> V_122 ( V_81 ) ;
V_190 = & V_81 -> V_117 ;
V_190 -> V_14 = V_190 -> V_118 [ 0 ] . V_119 +
V_190 -> V_124 +
V_190 -> V_158 [ 0 ] . V_119 ;
F_127 ( & V_19 -> V_41 ) ;
if ( F_13 ( V_191 , & V_19 -> V_26 )
|| F_13 ( V_98 , & V_19 -> V_26 ) )
V_14 = - V_192 ;
else
V_14 = V_19 -> V_30 -> V_193 ( V_81 ) ;
F_128 ( & V_19 -> V_41 ) ;
F_129 ( & V_19 -> V_44 ) ;
F_82 ( V_81 ) ;
if ( V_14 == - V_194 || V_14 == - V_192 || V_14 == - V_167 )
V_14 = 0 ;
V_9:
F_130 ( V_81 , V_14 ) ;
return V_14 ;
}
static void V_171 ( unsigned long V_195 )
{
struct V_33 * V_34 = (struct V_33 * ) V_195 ;
struct V_18 * V_19 ;
struct V_196 * V_197 , * V_198 ;
F_2 ( L_24 ) ;
if ( ! F_131 ( & V_34 -> V_73 ) ) {
F_2 ( L_25 ) ;
F_112 ( & V_34 -> V_169 , V_172 + V_165 ) ;
return;
}
F_132 (le, next, &serv->sv_tempsocks) {
V_19 = F_93 ( V_197 , struct V_18 , V_37 ) ;
if ( ! F_64 ( V_181 , & V_19 -> V_26 ) )
continue;
if ( F_78 ( & V_19 -> V_20 ) > 1 ||
F_13 ( V_43 , & V_19 -> V_26 ) )
continue;
F_9 ( V_197 ) ;
F_25 ( V_98 , & V_19 -> V_26 ) ;
F_2 ( L_26 , V_19 ) ;
F_60 ( V_19 ) ;
}
F_41 ( & V_34 -> V_73 ) ;
F_112 ( & V_34 -> V_169 , V_172 + V_173 * V_165 ) ;
}
void F_133 ( struct V_33 * V_34 , struct V_63 * V_199 )
{
struct V_18 * V_19 ;
struct V_196 * V_197 , * V_198 ;
F_134 ( V_200 ) ;
F_39 ( & V_34 -> V_73 ) ;
F_132 (le, next, &serv->sv_tempsocks) {
V_19 = F_93 ( V_197 , struct V_18 , V_37 ) ;
if ( F_135 ( V_199 , (struct V_63 * )
& V_19 -> V_87 ) ) {
F_2 ( L_27 , V_19 ) ;
F_136 ( V_197 , & V_200 ) ;
}
}
F_41 ( & V_34 -> V_73 ) ;
while ( ! F_75 ( & V_200 ) ) {
V_197 = V_200 . V_198 ;
F_9 ( V_197 ) ;
V_19 = F_93 ( V_197 , struct V_18 , V_37 ) ;
F_25 ( V_98 , & V_19 -> V_26 ) ;
F_25 ( V_174 , & V_19 -> V_26 ) ;
F_2 ( L_28 ,
V_19 ) ;
F_60 ( V_19 ) ;
}
}
static void F_137 ( struct V_18 * V_19 )
{
struct V_201 * V_202 ;
F_4 ( & V_19 -> V_42 ) ;
while ( ! F_75 ( & V_19 -> V_40 ) ) {
V_202 = F_77 ( & V_19 -> V_40 , struct V_201 , V_203 ) ;
F_138 ( & V_202 -> V_203 ) ;
V_202 -> V_204 ( V_202 ) ;
}
F_7 ( & V_19 -> V_42 ) ;
}
static void F_114 ( struct V_18 * V_19 )
{
struct V_33 * V_34 = V_19 -> V_36 ;
struct V_205 * V_206 ;
if ( F_64 ( V_191 , & V_19 -> V_26 ) )
F_139 () ;
F_2 ( L_29 , V_19 ) ;
V_19 -> V_30 -> V_207 ( V_19 ) ;
F_39 ( & V_34 -> V_73 ) ;
F_9 ( & V_19 -> V_37 ) ;
F_106 ( ! F_75 ( & V_19 -> V_38 ) ) ;
if ( F_13 ( V_72 , & V_19 -> V_26 ) )
V_34 -> V_135 -- ;
F_41 ( & V_34 -> V_73 ) ;
while ( ( V_206 = F_116 ( V_19 ) ) != NULL )
F_83 ( V_206 ) ;
F_137 ( V_19 ) ;
F_19 ( V_19 ) ;
}
void F_140 ( struct V_18 * V_19 )
{
F_25 ( V_98 , & V_19 -> V_26 ) ;
if ( F_64 ( V_43 , & V_19 -> V_26 ) )
return;
F_114 ( V_19 ) ;
}
static int F_141 ( struct V_33 * V_34 , struct V_196 * V_208 , struct V_32 * V_32 )
{
struct V_18 * V_19 ;
int V_209 = 0 ;
F_4 ( & V_34 -> V_73 ) ;
F_5 (xprt, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_32 )
continue;
V_209 ++ ;
F_25 ( V_98 , & V_19 -> V_26 ) ;
F_60 ( V_19 ) ;
}
F_7 ( & V_34 -> V_73 ) ;
return V_209 ;
}
static struct V_18 * F_142 ( struct V_33 * V_34 , struct V_32 * V_32 )
{
struct V_102 * V_103 ;
struct V_18 * V_19 ;
struct V_18 * V_210 ;
int V_143 ;
for ( V_143 = 0 ; V_143 < V_34 -> V_211 ; V_143 ++ ) {
V_103 = & V_34 -> V_127 [ V_143 ] ;
F_39 ( & V_103 -> V_113 ) ;
F_143 (xprt, tmp, &pool->sp_sockets, xpt_ready) {
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
static void F_144 ( struct V_33 * V_34 , struct V_32 * V_32 )
{
struct V_18 * V_19 ;
while ( ( V_19 = F_142 ( V_34 , V_32 ) ) ) {
F_25 ( V_98 , & V_19 -> V_26 ) ;
F_114 ( V_19 ) ;
}
}
void F_145 ( struct V_33 * V_34 , struct V_32 * V_32 )
{
int V_212 = 0 ;
while ( F_141 ( V_34 , & V_34 -> V_74 , V_32 ) +
F_141 ( V_34 , & V_34 -> V_136 , V_32 ) ) {
F_144 ( V_34 , V_32 ) ;
F_146 ( V_212 ++ ) ;
}
}
static void F_147 ( struct V_213 * V_214 , int V_215 )
{
struct V_205 * V_206 =
F_12 ( V_214 , struct V_205 , V_216 ) ;
struct V_18 * V_19 = V_206 -> V_19 ;
F_4 ( & V_19 -> V_42 ) ;
F_25 ( V_100 , & V_19 -> V_26 ) ;
if ( V_215 || F_13 ( V_191 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_42 ) ;
F_2 ( L_30 ) ;
F_19 ( V_19 ) ;
F_148 ( V_206 ) ;
F_83 ( V_206 ) ;
return;
}
F_2 ( L_31 ) ;
V_206 -> V_19 = NULL ;
F_40 ( & V_206 -> V_216 . V_217 , & V_19 -> V_39 ) ;
F_7 ( & V_19 -> V_42 ) ;
F_60 ( V_19 ) ;
F_19 ( V_19 ) ;
}
static struct V_213 * V_185 ( struct V_218 * V_219 )
{
struct V_80 * V_81 = F_12 ( V_219 , struct V_80 , V_163 ) ;
struct V_205 * V_206 ;
if ( V_81 -> V_156 . V_124 || ! F_13 ( V_220 , & V_81 -> V_95 ) )
return NULL ;
if ( V_81 -> V_123 ) {
V_206 = V_81 -> V_123 ;
V_81 -> V_123 = NULL ;
} else {
T_1 V_221 ;
T_1 V_222 ;
V_222 = sizeof( struct V_205 ) + V_81 -> V_156 . V_14 ;
V_206 = F_149 ( V_222 , V_151 ) ;
if ( V_206 == NULL )
return NULL ;
V_206 -> V_216 . V_22 = V_81 -> V_139 ;
V_206 -> V_223 = V_81 -> V_224 ;
memcpy ( & V_206 -> V_225 , & V_81 -> V_82 , V_81 -> V_85 ) ;
V_206 -> V_226 = V_81 -> V_85 ;
V_206 -> V_227 = V_81 -> V_86 ;
V_206 -> V_228 = V_81 -> V_156 . V_14 >> 2 ;
V_206 -> V_229 = V_81 -> V_230 ;
V_221 = V_81 -> V_156 . V_14 - V_81 -> V_156 . V_118 [ 0 ] . V_119 ;
memcpy ( V_206 -> args , V_81 -> V_156 . V_118 [ 0 ] . V_157 - V_221 ,
V_206 -> V_228 << 2 ) ;
}
F_35 ( V_81 -> V_96 ) ;
V_206 -> V_19 = V_81 -> V_96 ;
F_25 ( V_231 , & V_81 -> V_95 ) ;
V_206 -> V_216 . V_232 = F_147 ;
F_150 ( V_81 ) ;
return & V_206 -> V_216 ;
}
static int F_117 ( struct V_80 * V_81 )
{
struct V_205 * V_206 = V_81 -> V_123 ;
V_81 -> V_156 . V_118 [ 0 ] . V_157 = V_206 -> args + ( V_206 -> V_229 >> 2 ) ;
V_81 -> V_156 . V_118 [ 0 ] . V_119 = ( V_206 -> V_228 << 2 ) - V_206 -> V_229 ;
V_81 -> V_156 . V_124 = 0 ;
V_81 -> V_156 . V_14 = V_206 -> V_228 << 2 ;
V_81 -> V_224 = V_206 -> V_223 ;
memcpy ( & V_81 -> V_82 , & V_206 -> V_225 , V_206 -> V_226 ) ;
V_81 -> V_85 = V_206 -> V_226 ;
V_81 -> V_230 = V_206 -> V_229 ;
V_81 -> V_86 = V_206 -> V_227 ;
V_81 -> V_233 = V_81 -> V_148 ;
return ( V_206 -> V_228 << 2 ) - V_206 -> V_229 ;
}
static struct V_205 * F_116 ( struct V_18 * V_19 )
{
struct V_205 * V_206 = NULL ;
if ( ! F_13 ( V_100 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_42 ) ;
if ( ! F_75 ( & V_19 -> V_39 ) ) {
V_206 = F_93 ( V_19 -> V_39 . V_198 ,
struct V_205 ,
V_216 . V_217 ) ;
F_9 ( & V_206 -> V_216 . V_217 ) ;
F_151 ( V_206 ) ;
} else
F_37 ( V_100 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_42 ) ;
return V_206 ;
}
struct V_18 * F_152 ( struct V_33 * V_34 , const char * V_6 ,
struct V_32 * V_32 , const T_2 V_234 ,
const unsigned short V_46 )
{
struct V_18 * V_19 ;
struct V_18 * V_235 = NULL ;
if ( V_34 == NULL || V_6 == NULL )
return V_235 ;
F_39 ( & V_34 -> V_73 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( V_19 -> V_27 != V_32 )
continue;
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_234 != V_236 && V_234 != V_19 -> V_87 . V_237 )
continue;
if ( V_46 != 0 && V_46 != F_46 ( V_19 ) )
continue;
V_235 = V_19 ;
F_35 ( V_19 ) ;
break;
}
F_41 ( & V_34 -> V_73 ) ;
return V_235 ;
}
static int F_153 ( const struct V_18 * V_19 ,
char * V_238 , int V_239 )
{
int V_14 ;
V_14 = snprintf ( V_238 , V_239 , L_32 ,
V_19 -> V_23 -> V_6 ,
F_46 ( V_19 ) ) ;
if ( V_14 >= V_239 )
return - V_240 ;
return V_14 ;
}
int F_154 ( struct V_33 * V_34 , char * V_11 , const int V_241 )
{
struct V_18 * V_19 ;
int V_14 , V_242 ;
char * V_238 ;
if ( ! V_34 )
return 0 ;
F_39 ( & V_34 -> V_73 ) ;
V_238 = V_11 ;
V_242 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_153 ( V_19 , V_238 , V_241 - V_242 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_242 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_238 += V_14 ;
V_242 += V_14 ;
}
F_41 ( & V_34 -> V_73 ) ;
return V_242 ;
}
static void * F_155 ( struct V_243 * V_244 , T_3 * V_238 )
{
unsigned int V_245 = ( unsigned int ) * V_238 ;
struct V_33 * V_34 = V_244 -> V_246 ;
F_2 ( L_33 , V_245 ) ;
if ( ! V_245 )
return V_247 ;
return ( V_245 > V_34 -> V_211 ? NULL : & V_34 -> V_127 [ V_245 - 1 ] ) ;
}
static void * F_156 ( struct V_243 * V_244 , void * V_150 , T_3 * V_238 )
{
struct V_102 * V_103 = V_150 ;
struct V_33 * V_34 = V_244 -> V_246 ;
F_2 ( L_34 , * V_238 ) ;
if ( V_150 == V_247 ) {
V_103 = & V_34 -> V_127 [ 0 ] ;
} else {
unsigned int V_245 = ( V_103 - & V_34 -> V_127 [ 0 ] ) ;
if ( V_245 < V_34 -> V_211 - 1 )
V_103 = & V_34 -> V_127 [ V_245 + 1 ] ;
else
V_103 = NULL ;
}
++ * V_238 ;
return V_103 ;
}
static void F_157 ( struct V_243 * V_244 , void * V_150 )
{
}
static int F_158 ( struct V_243 * V_244 , void * V_150 )
{
struct V_102 * V_103 = V_150 ;
if ( V_150 == V_247 ) {
F_159 ( V_244 , L_35 ) ;
return 0 ;
}
F_160 ( V_244 , L_36 ,
V_103 -> V_178 ,
( unsigned long ) F_161 ( & V_103 -> V_106 . V_107 ) ,
V_103 -> V_106 . V_115 ,
( unsigned long ) F_161 ( & V_103 -> V_106 . V_111 ) ,
( unsigned long ) F_161 ( & V_103 -> V_106 . V_166 ) ) ;
return 0 ;
}
int F_162 ( struct V_33 * V_34 , struct V_248 * V_248 )
{
int V_78 ;
V_78 = F_163 ( V_248 , & V_249 ) ;
if ( ! V_78 )
( (struct V_243 * ) V_248 -> V_250 ) -> V_246 = V_34 ;
return V_78 ;
}

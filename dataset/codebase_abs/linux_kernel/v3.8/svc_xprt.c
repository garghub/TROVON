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
F_33 ( ! F_13 ( V_42 , & V_19 -> V_26 ) ) ;
if ( ! F_13 ( V_42 , & V_19 -> V_26 ) )
return;
F_34 ( V_19 ) ;
F_35 ( V_42 , & V_19 -> V_26 ) ;
F_36 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_37 ( struct V_32 * V_33 , struct V_18 * V_68 )
{
F_35 ( V_69 , & V_68 -> V_26 ) ;
F_38 ( & V_33 -> V_70 ) ;
F_39 ( & V_68 -> V_36 , & V_33 -> V_71 ) ;
F_40 ( & V_33 -> V_70 ) ;
F_32 ( V_68 ) ;
}
int F_41 ( struct V_32 * V_33 , const char * V_72 ,
struct V_31 * V_31 , const int V_44 ,
const unsigned short V_45 , int V_46 )
{
struct V_1 * V_2 ;
F_2 ( L_5 , V_72 , V_45 ) ;
F_4 ( & V_8 ) ;
F_5 (xcl, &svc_xprt_class_list, xcl_list) {
struct V_18 * V_73 ;
unsigned short V_74 ;
if ( strcmp ( V_72 , V_2 -> V_6 ) )
continue;
if ( ! F_42 ( V_2 -> V_24 ) )
goto V_75;
F_7 ( & V_8 ) ;
V_73 = F_27 ( V_2 , V_33 , V_31 , V_44 , V_45 , V_46 ) ;
if ( F_43 ( V_73 ) ) {
F_17 ( V_2 -> V_24 ) ;
return F_44 ( V_73 ) ;
}
F_37 ( V_33 , V_73 ) ;
V_74 = F_45 ( V_73 ) ;
return V_74 ;
}
V_75:
F_7 ( & V_8 ) ;
F_2 ( L_6 , V_72 ) ;
return - V_76 ;
}
void F_46 ( struct V_77 * V_78 , struct V_18 * V_19 )
{
memcpy ( & V_78 -> V_79 , & V_19 -> V_80 , V_19 -> V_81 ) ;
V_78 -> V_82 = V_19 -> V_81 ;
memcpy ( & V_78 -> V_83 , & V_19 -> V_84 , V_19 -> V_85 ) ;
V_78 -> V_86 = V_19 -> V_85 ;
}
char * F_47 ( struct V_77 * V_78 , char * V_11 , T_1 V_14 )
{
return F_48 ( F_49 ( V_78 ) , V_11 , V_14 ) ;
}
static void F_50 ( struct V_87 * V_88 , struct V_77 * V_78 )
{
F_39 ( & V_78 -> V_89 , & V_88 -> V_90 ) ;
}
static void F_51 ( struct V_87 * V_88 , struct V_77 * V_78 )
{
F_52 ( & V_78 -> V_89 ) ;
}
static bool F_53 ( struct V_18 * V_19 )
{
if ( V_19 -> V_26 & ( ( 1 << V_91 ) | ( 1 << V_92 ) ) )
return true ;
if ( V_19 -> V_26 & ( ( 1 << V_93 ) | ( 1 << V_94 ) ) )
return V_19 -> V_29 -> V_95 ( V_19 ) ;
return false ;
}
void F_36 ( struct V_18 * V_19 )
{
struct V_87 * V_88 ;
struct V_77 * V_78 ;
int V_96 ;
if ( ! F_53 ( V_19 ) )
return;
V_96 = F_54 () ;
V_88 = F_55 ( V_19 -> V_35 , V_96 ) ;
F_56 () ;
F_38 ( & V_88 -> V_97 ) ;
if ( ! F_57 ( & V_88 -> V_90 ) &&
! F_57 ( & V_88 -> V_98 ) )
F_58 ( V_99
L_7
L_8 ) ;
V_88 -> V_100 . V_101 ++ ;
if ( F_59 ( V_42 , & V_19 -> V_26 ) ) {
F_2 ( L_9 , V_19 ) ;
goto V_102;
}
if ( ! F_57 ( & V_88 -> V_90 ) ) {
V_78 = F_60 ( V_88 -> V_90 . V_103 ,
struct V_77 ,
V_89 ) ;
F_2 ( L_10 ,
V_19 , V_78 ) ;
F_51 ( V_88 , V_78 ) ;
if ( V_78 -> V_104 )
F_58 ( V_99
L_11 ,
V_78 , V_78 -> V_104 ) ;
V_78 -> V_104 = V_19 ;
F_34 ( V_19 ) ;
V_88 -> V_100 . V_105 ++ ;
F_61 ( & V_78 -> V_106 ) ;
} else {
F_2 ( L_12 , V_19 ) ;
F_6 ( & V_19 -> V_37 , & V_88 -> V_98 ) ;
V_88 -> V_100 . V_107 ++ ;
}
V_102:
F_40 ( & V_88 -> V_97 ) ;
}
static struct V_18 * F_62 ( struct V_87 * V_88 )
{
struct V_18 * V_19 ;
if ( F_57 ( & V_88 -> V_98 ) )
return NULL ;
V_19 = F_60 ( V_88 -> V_98 . V_103 ,
struct V_18 , V_37 ) ;
F_9 ( & V_19 -> V_37 ) ;
F_2 ( L_13 ,
V_19 , F_63 ( & V_19 -> V_20 . V_108 ) ) ;
return V_19 ;
}
void F_64 ( struct V_77 * V_78 , int V_109 )
{
V_109 += V_78 -> V_110 . V_111 [ 0 ] . V_112 ;
if ( V_109 < V_78 -> V_113 ) {
struct V_18 * V_19 = V_78 -> V_104 ;
F_65 ( ( V_78 -> V_113 - V_109 ) , & V_19 -> V_114 ) ;
V_78 -> V_113 = V_109 ;
F_36 ( V_19 ) ;
}
}
static void F_66 ( struct V_77 * V_78 )
{
struct V_18 * V_19 = V_78 -> V_104 ;
V_78 -> V_104 -> V_29 -> V_115 ( V_78 ) ;
F_67 ( V_78 -> V_116 ) ;
V_78 -> V_116 = NULL ;
F_68 ( V_78 ) ;
V_78 -> V_110 . V_117 = 0 ;
V_78 -> V_110 . V_118 = 0 ;
if ( ( V_78 -> V_110 . V_14 ) > V_78 -> V_113 )
F_58 ( V_99 L_14 ,
V_78 -> V_113 ,
V_78 -> V_110 . V_14 ) ;
V_78 -> V_110 . V_111 [ 0 ] . V_112 = 0 ;
F_64 ( V_78 , 0 ) ;
V_78 -> V_104 = NULL ;
F_18 ( V_19 ) ;
}
void F_69 ( struct V_32 * V_33 )
{
struct V_77 * V_78 ;
unsigned int V_119 ;
struct V_87 * V_88 ;
for ( V_119 = 0 ; V_119 < V_33 -> V_120 ; V_119 ++ ) {
V_88 = & V_33 -> V_121 [ V_119 ] ;
F_38 ( & V_88 -> V_97 ) ;
if ( ! F_57 ( & V_88 -> V_90 ) ) {
V_78 = F_60 ( V_88 -> V_90 . V_103 ,
struct V_77 ,
V_89 ) ;
F_2 ( L_15 , V_78 ) ;
F_61 ( & V_78 -> V_106 ) ;
}
F_40 ( & V_88 -> V_97 ) ;
}
}
int F_70 ( struct V_62 * sin )
{
switch ( sin -> V_122 ) {
case V_49 :
return F_71 ( ( (struct V_47 * ) sin ) -> V_53 )
< V_123 ;
case V_58 :
return F_71 ( ( (struct V_55 * ) sin ) -> V_61 )
< V_123 ;
default:
return 0 ;
}
}
static void F_72 ( struct V_32 * V_33 )
{
unsigned int V_124 = V_33 -> V_125 ? V_33 -> V_125 :
( V_33 -> V_126 + 3 ) * 20 ;
if ( V_33 -> V_127 > V_124 ) {
struct V_18 * V_19 = NULL ;
F_38 ( & V_33 -> V_70 ) ;
if ( ! F_57 ( & V_33 -> V_128 ) ) {
F_73 ( L_16 ,
V_33 -> V_129 , V_33 -> V_125 ?
L_17 :
L_18 ) ;
V_19 = F_60 ( V_33 -> V_128 . V_130 ,
struct V_18 ,
V_36 ) ;
F_24 ( V_92 , & V_19 -> V_26 ) ;
F_34 ( V_19 ) ;
}
F_40 ( & V_33 -> V_70 ) ;
if ( V_19 ) {
F_36 ( V_19 ) ;
F_18 ( V_19 ) ;
}
}
}
int F_74 ( struct V_77 * V_78 )
{
struct V_32 * V_33 = V_78 -> V_131 ;
struct V_132 * V_133 ;
int V_134 ;
int V_119 ;
V_134 = ( V_33 -> V_135 + V_136 ) / V_136 ;
F_33 ( V_134 >= V_137 ) ;
if ( V_134 >= V_137 )
V_134 = V_137 - 1 ;
for ( V_119 = 0 ; V_119 < V_134 ; V_119 ++ )
while ( V_78 -> V_138 [ V_119 ] == NULL ) {
struct V_139 * V_140 = F_75 ( V_141 ) ;
if ( ! V_140 ) {
F_76 ( V_142 ) ;
if ( F_77 () || F_78 () ) {
F_76 ( V_143 ) ;
return - V_144 ;
}
F_79 ( F_80 ( 500 ) ) ;
}
V_78 -> V_138 [ V_119 ] = V_140 ;
}
V_78 -> V_138 [ V_119 ++ ] = NULL ;
V_133 = & V_78 -> V_145 ;
V_133 -> V_111 [ 0 ] . V_146 = F_81 ( V_78 -> V_138 [ 0 ] ) ;
V_133 -> V_111 [ 0 ] . V_112 = V_136 ;
V_133 -> V_134 = V_78 -> V_138 + 1 ;
V_133 -> V_118 = 0 ;
V_133 -> V_117 = ( V_134 - 2 ) * V_136 ;
V_133 -> V_14 = ( V_134 - 1 ) * V_136 ;
V_133 -> V_147 [ 0 ] . V_112 = 0 ;
return 0 ;
}
struct V_18 * F_82 ( struct V_77 * V_78 , long V_148 )
{
struct V_18 * V_19 ;
struct V_87 * V_88 = V_78 -> V_149 ;
F_83 ( V_150 , V_151 ) ;
long V_152 ;
V_78 -> V_153 . V_154 = 5 * V_155 ;
F_38 ( & V_88 -> V_97 ) ;
V_19 = F_62 ( V_88 ) ;
if ( V_19 ) {
V_78 -> V_104 = V_19 ;
F_34 ( V_19 ) ;
V_78 -> V_153 . V_154 = 1 * V_155 ;
} else {
F_50 ( V_88 , V_78 ) ;
F_76 ( V_142 ) ;
if ( F_78 () ) {
F_76 ( V_143 ) ;
F_40 ( & V_88 -> V_97 ) ;
return F_31 ( - V_144 ) ;
}
F_84 ( & V_78 -> V_106 , & V_150 ) ;
F_40 ( & V_88 -> V_97 ) ;
V_152 = F_79 ( V_148 ) ;
F_85 () ;
F_38 ( & V_88 -> V_97 ) ;
F_86 ( & V_78 -> V_106 , & V_150 ) ;
if ( ! V_152 )
V_88 -> V_100 . V_156 ++ ;
V_19 = V_78 -> V_104 ;
if ( ! V_19 ) {
F_51 ( V_88 , V_78 ) ;
F_40 ( & V_88 -> V_97 ) ;
F_2 ( L_19 , V_78 ) ;
if ( F_77 () || F_78 () )
return F_31 ( - V_144 ) ;
else
return F_31 ( - V_157 ) ;
}
}
F_40 ( & V_88 -> V_97 ) ;
return V_19 ;
}
void F_87 ( struct V_32 * V_33 , struct V_18 * V_158 )
{
F_38 ( & V_33 -> V_70 ) ;
F_24 ( V_69 , & V_158 -> V_26 ) ;
F_39 ( & V_158 -> V_36 , & V_33 -> V_128 ) ;
V_33 -> V_127 ++ ;
if ( V_33 -> V_159 . V_160 == NULL ) {
F_88 ( & V_33 -> V_159 , V_161 ,
( unsigned long ) V_33 ) ;
F_89 ( & V_33 -> V_159 ,
V_162 + V_163 * V_155 ) ;
}
F_40 ( & V_33 -> V_70 ) ;
F_32 ( V_158 ) ;
}
static int F_90 ( struct V_77 * V_78 , struct V_18 * V_19 )
{
struct V_32 * V_33 = V_78 -> V_131 ;
int V_14 = 0 ;
if ( F_13 ( V_92 , & V_19 -> V_26 ) ) {
F_2 ( L_20 ) ;
F_91 ( V_19 ) ;
return 0 ;
}
if ( F_13 ( V_164 , & V_19 -> V_26 ) ) {
struct V_18 * V_158 ;
F_92 ( V_19 -> V_23 -> V_24 ) ;
F_72 ( V_19 -> V_35 ) ;
V_158 = V_19 -> V_29 -> V_165 ( V_19 ) ;
if ( V_158 )
F_87 ( V_33 , V_158 ) ;
} else if ( V_19 -> V_29 -> V_95 ( V_19 ) ) {
F_2 ( L_21 ,
V_78 , V_78 -> V_149 -> V_166 , V_19 ,
F_63 ( & V_19 -> V_20 . V_108 ) ) ;
V_78 -> V_116 = F_93 ( V_19 ) ;
if ( V_78 -> V_116 )
V_14 = F_94 ( V_78 ) ;
else
V_14 = V_19 -> V_29 -> V_167 ( V_78 ) ;
F_2 ( L_22 , V_14 ) ;
V_78 -> V_113 = V_33 -> V_135 ;
F_95 ( V_78 -> V_113 , & V_19 -> V_114 ) ;
}
F_32 ( V_19 ) ;
return V_14 ;
}
int F_96 ( struct V_77 * V_78 , long V_148 )
{
struct V_18 * V_19 = NULL ;
struct V_32 * V_33 = V_78 -> V_131 ;
int V_14 , V_75 ;
F_2 ( L_23 ,
V_78 , V_148 ) ;
if ( V_78 -> V_104 )
F_58 ( V_99
L_24 ,
V_78 ) ;
if ( F_97 ( & V_78 -> V_106 ) )
F_58 ( V_99
L_25 ,
V_78 ) ;
V_75 = F_74 ( V_78 ) ;
if ( V_75 )
return V_75 ;
F_85 () ;
F_98 () ;
if ( F_77 () || F_78 () )
return - V_144 ;
V_19 = F_82 ( V_78 , V_148 ) ;
if ( F_43 ( V_19 ) )
return F_44 ( V_19 ) ;
V_14 = F_90 ( V_78 , V_19 ) ;
if ( V_14 <= 0 )
goto V_9;
F_35 ( V_168 , & V_19 -> V_26 ) ;
V_78 -> V_169 = F_70 ( F_49 ( V_78 ) ) ;
V_78 -> V_153 . V_170 = V_171 ;
if ( V_33 -> V_172 )
V_33 -> V_172 -> V_173 ++ ;
return V_14 ;
V_9:
V_78 -> V_110 . V_14 = 0 ;
F_66 ( V_78 ) ;
return - V_157 ;
}
void F_99 ( struct V_77 * V_78 )
{
F_2 ( L_26 , V_78 -> V_104 ) ;
F_66 ( V_78 ) ;
}
int F_100 ( struct V_77 * V_78 )
{
struct V_18 * V_19 ;
int V_14 ;
struct V_132 * V_174 ;
V_19 = V_78 -> V_104 ;
if ( ! V_19 )
return - V_175 ;
V_78 -> V_104 -> V_29 -> V_115 ( V_78 ) ;
V_174 = & V_78 -> V_110 ;
V_174 -> V_14 = V_174 -> V_111 [ 0 ] . V_112 +
V_174 -> V_117 +
V_174 -> V_147 [ 0 ] . V_112 ;
F_101 ( & V_19 -> V_40 ) ;
if ( F_13 ( V_176 , & V_19 -> V_26 )
|| F_13 ( V_92 , & V_19 -> V_26 ) )
V_14 = - V_177 ;
else
V_14 = V_19 -> V_29 -> V_178 ( V_78 ) ;
F_102 ( & V_19 -> V_40 ) ;
F_103 ( & V_19 -> V_43 ) ;
F_66 ( V_78 ) ;
if ( V_14 == - V_179 || V_14 == - V_177 || V_14 == - V_157 )
return 0 ;
return V_14 ;
}
static void V_161 ( unsigned long V_180 )
{
struct V_32 * V_33 = (struct V_32 * ) V_180 ;
struct V_18 * V_19 ;
struct V_181 * V_182 , * V_103 ;
F_104 ( V_183 ) ;
F_2 ( L_27 ) ;
if ( ! F_105 ( & V_33 -> V_70 ) ) {
F_2 ( L_28 ) ;
F_89 ( & V_33 -> V_159 , V_162 + V_155 ) ;
return;
}
F_106 (le, next, &serv->sv_tempsocks) {
V_19 = F_60 ( V_182 , struct V_18 , V_36 ) ;
if ( ! F_59 ( V_168 , & V_19 -> V_26 ) )
continue;
if ( F_63 ( & V_19 -> V_20 . V_108 ) > 1 ||
F_13 ( V_42 , & V_19 -> V_26 ) )
continue;
F_34 ( V_19 ) ;
F_107 ( V_182 , & V_183 ) ;
F_24 ( V_92 , & V_19 -> V_26 ) ;
F_24 ( V_184 , & V_19 -> V_26 ) ;
}
F_40 ( & V_33 -> V_70 ) ;
while ( ! F_57 ( & V_183 ) ) {
V_182 = V_183 . V_103 ;
F_9 ( V_182 ) ;
V_19 = F_60 ( V_182 , struct V_18 , V_36 ) ;
F_2 ( L_29 , V_19 ) ;
F_36 ( V_19 ) ;
F_18 ( V_19 ) ;
}
F_89 ( & V_33 -> V_159 , V_162 + V_163 * V_155 ) ;
}
static void F_108 ( struct V_18 * V_19 )
{
struct V_185 * V_186 ;
F_4 ( & V_19 -> V_41 ) ;
while ( ! F_57 ( & V_19 -> V_39 ) ) {
V_186 = F_109 ( & V_19 -> V_39 , struct V_185 , V_187 ) ;
F_52 ( & V_186 -> V_187 ) ;
V_186 -> V_188 ( V_186 ) ;
}
F_7 ( & V_19 -> V_41 ) ;
}
static void F_91 ( struct V_18 * V_19 )
{
struct V_32 * V_33 = V_19 -> V_35 ;
struct V_189 * V_190 ;
if ( F_59 ( V_176 , & V_19 -> V_26 ) )
F_110 () ;
F_2 ( L_30 , V_19 ) ;
V_19 -> V_29 -> V_191 ( V_19 ) ;
F_38 ( & V_33 -> V_70 ) ;
if ( ! F_59 ( V_184 , & V_19 -> V_26 ) )
F_9 ( & V_19 -> V_36 ) ;
F_33 ( ! F_57 ( & V_19 -> V_37 ) ) ;
if ( F_13 ( V_69 , & V_19 -> V_26 ) )
V_33 -> V_127 -- ;
F_40 ( & V_33 -> V_70 ) ;
while ( ( V_190 = F_93 ( V_19 ) ) != NULL )
F_67 ( V_190 ) ;
F_108 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_111 ( struct V_18 * V_19 )
{
F_24 ( V_92 , & V_19 -> V_26 ) ;
if ( F_59 ( V_42 , & V_19 -> V_26 ) )
return;
F_91 ( V_19 ) ;
}
static void F_112 ( struct V_32 * V_33 , struct V_181 * V_192 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
F_4 ( & V_33 -> V_70 ) ;
F_5 (xprt, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
F_24 ( V_92 , & V_19 -> V_26 ) ;
F_24 ( V_42 , & V_19 -> V_26 ) ;
}
F_7 ( & V_33 -> V_70 ) ;
}
static void F_113 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
struct V_87 * V_88 ;
struct V_18 * V_19 ;
struct V_18 * V_193 ;
int V_119 ;
for ( V_119 = 0 ; V_119 < V_33 -> V_120 ; V_119 ++ ) {
V_88 = & V_33 -> V_121 [ V_119 ] ;
F_38 ( & V_88 -> V_97 ) ;
F_114 (xprt, tmp, &pool->sp_sockets, xpt_ready) {
if ( V_19 -> V_27 != V_31 )
continue;
F_9 ( & V_19 -> V_37 ) ;
}
F_40 ( & V_88 -> V_97 ) ;
}
}
static void F_115 ( struct V_32 * V_33 , struct V_181 * V_192 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
struct V_18 * V_193 ;
F_104 ( V_194 ) ;
F_4 ( & V_33 -> V_70 ) ;
F_114 (xprt, tmp, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
F_107 ( & V_19 -> V_36 , & V_194 ) ;
}
F_7 ( & V_33 -> V_70 ) ;
F_114 (xprt, tmp, &victims, xpt_list)
F_91 ( V_19 ) ;
}
void F_116 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
F_112 ( V_33 , & V_33 -> V_128 , V_31 ) ;
F_112 ( V_33 , & V_33 -> V_71 , V_31 ) ;
F_113 ( V_33 , V_31 ) ;
F_115 ( V_33 , & V_33 -> V_128 , V_31 ) ;
F_115 ( V_33 , & V_33 -> V_71 , V_31 ) ;
}
static void F_117 ( struct V_195 * V_196 , int V_197 )
{
struct V_189 * V_190 =
F_12 ( V_196 , struct V_189 , V_198 ) ;
struct V_18 * V_19 = V_190 -> V_19 ;
F_4 ( & V_19 -> V_41 ) ;
F_24 ( V_94 , & V_19 -> V_26 ) ;
if ( V_197 || F_13 ( V_176 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_41 ) ;
F_2 ( L_31 ) ;
F_18 ( V_19 ) ;
F_67 ( V_190 ) ;
return;
}
F_2 ( L_32 ) ;
V_190 -> V_19 = NULL ;
F_39 ( & V_190 -> V_198 . V_199 , & V_19 -> V_38 ) ;
F_7 ( & V_19 -> V_41 ) ;
F_36 ( V_19 ) ;
F_18 ( V_19 ) ;
}
static struct V_195 * V_171 ( struct V_200 * V_201 )
{
struct V_77 * V_78 = F_12 ( V_201 , struct V_77 , V_153 ) ;
struct V_189 * V_190 ;
if ( V_78 -> V_145 . V_117 || ! V_78 -> V_202 )
return NULL ;
if ( V_78 -> V_116 ) {
V_190 = V_78 -> V_116 ;
V_78 -> V_116 = NULL ;
} else {
T_1 V_203 ;
T_1 V_204 ;
V_204 = sizeof( struct V_189 ) + V_78 -> V_145 . V_14 ;
V_190 = F_118 ( V_204 , V_141 ) ;
if ( V_190 == NULL )
return NULL ;
V_190 -> V_198 . V_22 = V_78 -> V_131 ;
V_190 -> V_205 = V_78 -> V_206 ;
memcpy ( & V_190 -> V_207 , & V_78 -> V_79 , V_78 -> V_82 ) ;
V_190 -> V_208 = V_78 -> V_82 ;
V_190 -> V_209 = V_78 -> V_83 ;
V_190 -> V_210 = V_78 -> V_145 . V_14 >> 2 ;
V_190 -> V_211 = V_78 -> V_212 ;
V_203 = V_78 -> V_145 . V_14 - V_78 -> V_145 . V_111 [ 0 ] . V_112 ;
memcpy ( V_190 -> args , V_78 -> V_145 . V_111 [ 0 ] . V_146 - V_203 ,
V_190 -> V_210 << 2 ) ;
}
F_34 ( V_78 -> V_104 ) ;
V_190 -> V_19 = V_78 -> V_104 ;
V_78 -> V_213 = true ;
V_190 -> V_198 . V_214 = F_117 ;
return & V_190 -> V_198 ;
}
static int F_94 ( struct V_77 * V_78 )
{
struct V_189 * V_190 = V_78 -> V_116 ;
V_78 -> V_145 . V_111 [ 0 ] . V_146 = V_190 -> args + ( V_190 -> V_211 >> 2 ) ;
V_78 -> V_145 . V_111 [ 0 ] . V_112 = ( V_190 -> V_210 << 2 ) - V_190 -> V_211 ;
V_78 -> V_145 . V_117 = 0 ;
V_78 -> V_145 . V_14 = V_190 -> V_210 << 2 ;
V_78 -> V_206 = V_190 -> V_205 ;
memcpy ( & V_78 -> V_79 , & V_190 -> V_207 , V_190 -> V_208 ) ;
V_78 -> V_82 = V_190 -> V_208 ;
V_78 -> V_212 = V_190 -> V_211 ;
V_78 -> V_83 = V_190 -> V_209 ;
V_78 -> V_215 = V_78 -> V_138 ;
return ( V_190 -> V_210 << 2 ) - V_190 -> V_211 ;
}
static struct V_189 * F_93 ( struct V_18 * V_19 )
{
struct V_189 * V_190 = NULL ;
if ( ! F_13 ( V_94 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_41 ) ;
if ( ! F_57 ( & V_19 -> V_38 ) ) {
V_190 = F_60 ( V_19 -> V_38 . V_103 ,
struct V_189 ,
V_198 . V_199 ) ;
F_9 ( & V_190 -> V_198 . V_199 ) ;
} else
F_35 ( V_94 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_41 ) ;
return V_190 ;
}
struct V_18 * F_119 ( struct V_32 * V_33 , const char * V_6 ,
struct V_31 * V_31 , const T_2 V_216 ,
const unsigned short V_45 )
{
struct V_18 * V_19 ;
struct V_18 * V_217 = NULL ;
if ( V_33 == NULL || V_6 == NULL )
return V_217 ;
F_38 ( & V_33 -> V_70 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_216 != V_218 && V_216 != V_19 -> V_84 . V_219 )
continue;
if ( V_45 != 0 && V_45 != F_45 ( V_19 ) )
continue;
V_217 = V_19 ;
F_34 ( V_19 ) ;
break;
}
F_40 ( & V_33 -> V_70 ) ;
return V_217 ;
}
static int F_120 ( const struct V_18 * V_19 ,
char * V_220 , int V_221 )
{
int V_14 ;
V_14 = snprintf ( V_220 , V_221 , L_33 ,
V_19 -> V_23 -> V_6 ,
F_45 ( V_19 ) ) ;
if ( V_14 >= V_221 )
return - V_222 ;
return V_14 ;
}
int F_121 ( struct V_32 * V_33 , char * V_11 , const int V_223 )
{
struct V_18 * V_19 ;
int V_14 , V_224 ;
char * V_220 ;
if ( ! V_33 )
return 0 ;
F_38 ( & V_33 -> V_70 ) ;
V_220 = V_11 ;
V_224 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_120 ( V_19 , V_220 , V_223 - V_224 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_224 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_220 += V_14 ;
V_224 += V_14 ;
}
F_40 ( & V_33 -> V_70 ) ;
return V_224 ;
}
static void * F_122 ( struct V_225 * V_226 , T_3 * V_220 )
{
unsigned int V_227 = ( unsigned int ) * V_220 ;
struct V_32 * V_33 = V_226 -> V_228 ;
F_2 ( L_34 , V_227 ) ;
if ( ! V_227 )
return V_229 ;
return ( V_227 > V_33 -> V_120 ? NULL : & V_33 -> V_121 [ V_227 - 1 ] ) ;
}
static void * F_123 ( struct V_225 * V_226 , void * V_140 , T_3 * V_220 )
{
struct V_87 * V_88 = V_140 ;
struct V_32 * V_33 = V_226 -> V_228 ;
F_2 ( L_35 , * V_220 ) ;
if ( V_140 == V_229 ) {
V_88 = & V_33 -> V_121 [ 0 ] ;
} else {
unsigned int V_227 = ( V_88 - & V_33 -> V_121 [ 0 ] ) ;
if ( V_227 < V_33 -> V_120 - 1 )
V_88 = & V_33 -> V_121 [ V_227 + 1 ] ;
else
V_88 = NULL ;
}
++ * V_220 ;
return V_88 ;
}
static void F_124 ( struct V_225 * V_226 , void * V_140 )
{
}
static int F_125 ( struct V_225 * V_226 , void * V_140 )
{
struct V_87 * V_88 = V_140 ;
if ( V_140 == V_229 ) {
F_126 ( V_226 , L_36 ) ;
return 0 ;
}
F_127 ( V_226 , L_37 ,
V_88 -> V_166 ,
V_88 -> V_100 . V_101 ,
V_88 -> V_100 . V_107 ,
V_88 -> V_100 . V_105 ,
V_88 -> V_100 . V_156 ) ;
return 0 ;
}
int F_128 ( struct V_32 * V_33 , struct V_230 * V_230 )
{
int V_75 ;
V_75 = F_129 ( V_230 , & V_231 ) ;
if ( ! V_75 )
( (struct V_225 * ) V_230 -> V_232 ) -> V_228 = V_33 ;
return V_75 ;
}

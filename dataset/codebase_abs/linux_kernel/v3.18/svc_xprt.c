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
F_2 ( L_5 , V_72 , V_45 ) ;
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
F_2 ( L_6 , V_72 ) ;
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
static void F_51 ( struct V_87 * V_88 , struct V_77 * V_78 )
{
F_40 ( & V_78 -> V_89 , & V_88 -> V_90 ) ;
}
static void F_52 ( struct V_87 * V_88 , struct V_77 * V_78 )
{
F_53 ( & V_78 -> V_89 ) ;
}
static bool F_54 ( struct V_18 * V_19 )
{
if ( V_19 -> V_26 & ( ( 1 << V_91 ) | ( 1 << V_92 ) ) )
return true ;
if ( V_19 -> V_26 & ( ( 1 << V_93 ) | ( 1 << V_94 ) ) )
return V_19 -> V_29 -> V_95 ( V_19 ) ;
return false ;
}
static void F_37 ( struct V_18 * V_19 )
{
struct V_87 * V_88 ;
struct V_77 * V_78 ;
int V_96 ;
if ( ! F_54 ( V_19 ) )
return;
if ( F_55 ( V_42 , & V_19 -> V_26 ) ) {
F_2 ( L_7 , V_19 ) ;
return;
}
V_96 = F_56 () ;
V_88 = F_57 ( V_19 -> V_35 , V_96 ) ;
F_39 ( & V_88 -> V_97 ) ;
V_88 -> V_98 . V_99 ++ ;
if ( ! F_58 ( & V_88 -> V_90 ) ) {
V_78 = F_59 ( V_88 -> V_90 . V_100 ,
struct V_77 ,
V_89 ) ;
F_2 ( L_8 ,
V_19 , V_78 ) ;
F_52 ( V_88 , V_78 ) ;
if ( V_78 -> V_101 )
F_60 ( V_102
L_9 ,
V_78 , V_78 -> V_101 ) ;
F_34 ( V_19 ) ;
F_61 ( V_78 -> V_103 ) ;
V_78 -> V_101 = V_19 ;
V_88 -> V_98 . V_104 ++ ;
} else {
F_2 ( L_10 , V_19 ) ;
F_6 ( & V_19 -> V_37 , & V_88 -> V_105 ) ;
V_88 -> V_98 . V_106 ++ ;
}
F_41 ( & V_88 -> V_97 ) ;
F_62 () ;
}
void F_63 ( struct V_18 * V_19 )
{
if ( F_13 ( V_42 , & V_19 -> V_26 ) )
return;
F_37 ( V_19 ) ;
}
static struct V_18 * F_64 ( struct V_87 * V_88 )
{
struct V_18 * V_19 ;
if ( F_58 ( & V_88 -> V_105 ) )
return NULL ;
V_19 = F_59 ( V_88 -> V_105 . V_100 ,
struct V_18 , V_37 ) ;
F_9 ( & V_19 -> V_37 ) ;
F_2 ( L_11 ,
V_19 , F_65 ( & V_19 -> V_20 . V_107 ) ) ;
return V_19 ;
}
void F_66 ( struct V_77 * V_78 , int V_108 )
{
V_108 += V_78 -> V_109 . V_110 [ 0 ] . V_111 ;
if ( V_108 < V_78 -> V_112 ) {
struct V_18 * V_19 = V_78 -> V_101 ;
F_67 ( ( V_78 -> V_112 - V_108 ) , & V_19 -> V_113 ) ;
V_78 -> V_112 = V_108 ;
if ( V_19 -> V_29 -> V_114 )
V_19 -> V_29 -> V_114 ( V_19 ) ;
F_63 ( V_19 ) ;
}
}
static void F_68 ( struct V_77 * V_78 )
{
struct V_18 * V_19 = V_78 -> V_101 ;
V_78 -> V_101 -> V_29 -> V_115 ( V_78 ) ;
F_69 ( V_78 -> V_116 ) ;
V_78 -> V_116 = NULL ;
F_70 ( V_78 ) ;
V_78 -> V_109 . V_117 = 0 ;
V_78 -> V_109 . V_118 = 0 ;
if ( ( V_78 -> V_109 . V_14 ) > V_78 -> V_112 )
F_60 ( V_102 L_12 ,
V_78 -> V_112 ,
V_78 -> V_109 . V_14 ) ;
V_78 -> V_109 . V_110 [ 0 ] . V_111 = 0 ;
F_66 ( V_78 , 0 ) ;
V_78 -> V_101 = NULL ;
F_18 ( V_19 ) ;
}
void F_71 ( struct V_32 * V_33 )
{
struct V_77 * V_78 ;
unsigned int V_119 ;
struct V_87 * V_88 ;
for ( V_119 = 0 ; V_119 < V_33 -> V_120 ; V_119 ++ ) {
V_88 = & V_33 -> V_121 [ V_119 ] ;
F_39 ( & V_88 -> V_97 ) ;
if ( ! F_58 ( & V_88 -> V_90 ) ) {
V_78 = F_59 ( V_88 -> V_90 . V_100 ,
struct V_77 ,
V_89 ) ;
F_2 ( L_13 , V_78 ) ;
F_61 ( V_78 -> V_103 ) ;
} else
V_88 -> V_122 = 1 ;
F_41 ( & V_88 -> V_97 ) ;
}
}
int F_72 ( struct V_62 * sin )
{
switch ( sin -> V_123 ) {
case V_49 :
return F_73 ( ( (struct V_47 * ) sin ) -> V_53 )
< V_124 ;
case V_58 :
return F_73 ( ( (struct V_55 * ) sin ) -> V_61 )
< V_124 ;
default:
return 0 ;
}
}
static void F_74 ( struct V_32 * V_33 )
{
unsigned int V_125 = V_33 -> V_126 ? V_33 -> V_126 :
( V_33 -> V_127 + 3 ) * 20 ;
if ( V_33 -> V_128 > V_125 ) {
struct V_18 * V_19 = NULL ;
F_39 ( & V_33 -> V_70 ) ;
if ( ! F_58 ( & V_33 -> V_129 ) ) {
F_75 ( L_14 ,
V_33 -> V_130 , V_33 -> V_126 ?
L_15 :
L_16 ) ;
V_19 = F_59 ( V_33 -> V_129 . V_131 ,
struct V_18 ,
V_36 ) ;
F_24 ( V_92 , & V_19 -> V_26 ) ;
F_34 ( V_19 ) ;
}
F_41 ( & V_33 -> V_70 ) ;
if ( V_19 ) {
F_63 ( V_19 ) ;
F_18 ( V_19 ) ;
}
}
}
static int F_76 ( struct V_77 * V_78 )
{
struct V_32 * V_33 = V_78 -> V_132 ;
struct V_133 * V_134 ;
int V_135 ;
int V_119 ;
V_135 = ( V_33 -> V_136 + V_137 ) / V_137 ;
F_33 ( V_135 >= V_138 ) ;
if ( V_135 >= V_138 )
V_135 = V_138 - 1 ;
for ( V_119 = 0 ; V_119 < V_135 ; V_119 ++ )
while ( V_78 -> V_139 [ V_119 ] == NULL ) {
struct V_140 * V_141 = F_77 ( V_142 ) ;
if ( ! V_141 ) {
F_78 ( V_143 ) ;
if ( F_79 () || F_80 () ) {
F_78 ( V_144 ) ;
return - V_145 ;
}
F_81 ( F_82 ( 500 ) ) ;
}
V_78 -> V_139 [ V_119 ] = V_141 ;
}
V_78 -> V_146 = & V_78 -> V_139 [ V_119 ] ;
V_78 -> V_139 [ V_119 ++ ] = NULL ;
V_134 = & V_78 -> V_147 ;
V_134 -> V_110 [ 0 ] . V_148 = F_83 ( V_78 -> V_139 [ 0 ] ) ;
V_134 -> V_110 [ 0 ] . V_111 = V_137 ;
V_134 -> V_135 = V_78 -> V_139 + 1 ;
V_134 -> V_118 = 0 ;
V_134 -> V_117 = ( V_135 - 2 ) * V_137 ;
V_134 -> V_14 = ( V_135 - 1 ) * V_137 ;
V_134 -> V_149 [ 0 ] . V_111 = 0 ;
return 0 ;
}
static struct V_18 * F_84 ( struct V_77 * V_78 , long V_150 )
{
struct V_18 * V_19 ;
struct V_87 * V_88 = V_78 -> V_151 ;
long V_152 = 0 ;
V_78 -> V_153 . V_154 = 5 * V_155 ;
F_39 ( & V_88 -> V_97 ) ;
V_19 = F_64 ( V_88 ) ;
if ( V_19 ) {
V_78 -> V_101 = V_19 ;
F_34 ( V_19 ) ;
V_78 -> V_153 . V_154 = 1 * V_155 ;
V_88 -> V_122 = 0 ;
} else {
if ( V_88 -> V_122 ) {
V_88 -> V_122 = 0 ;
V_19 = F_31 ( - V_156 ) ;
goto V_9;
}
F_78 ( V_143 ) ;
F_51 ( V_88 , V_78 ) ;
F_41 ( & V_88 -> V_97 ) ;
if ( ! ( F_79 () || F_80 () ) ) {
V_152 = F_81 ( V_150 ) ;
F_85 ( V_144 ) ;
F_86 () ;
V_19 = V_78 -> V_101 ;
if ( V_19 != NULL )
return V_19 ;
} else
F_85 ( V_144 ) ;
F_39 ( & V_88 -> V_97 ) ;
if ( ! V_152 )
V_88 -> V_98 . V_157 ++ ;
V_19 = V_78 -> V_101 ;
if ( ! V_19 ) {
F_52 ( V_88 , V_78 ) ;
F_41 ( & V_88 -> V_97 ) ;
F_2 ( L_17 , V_78 ) ;
if ( F_79 () || F_80 () )
return F_31 ( - V_145 ) ;
else
return F_31 ( - V_156 ) ;
}
}
V_9:
F_41 ( & V_88 -> V_97 ) ;
return V_19 ;
}
static void F_87 ( struct V_32 * V_33 , struct V_18 * V_158 )
{
F_39 ( & V_33 -> V_70 ) ;
F_24 ( V_69 , & V_158 -> V_26 ) ;
F_40 ( & V_158 -> V_36 , & V_33 -> V_129 ) ;
V_33 -> V_128 ++ ;
if ( V_33 -> V_159 . V_160 == NULL ) {
F_88 ( & V_33 -> V_159 , V_161 ,
( unsigned long ) V_33 ) ;
F_89 ( & V_33 -> V_159 ,
V_162 + V_163 * V_155 ) ;
}
F_41 ( & V_33 -> V_70 ) ;
F_32 ( V_158 ) ;
}
static int F_90 ( struct V_77 * V_78 , struct V_18 * V_19 )
{
struct V_32 * V_33 = V_78 -> V_132 ;
int V_14 = 0 ;
if ( F_13 ( V_92 , & V_19 -> V_26 ) ) {
F_2 ( L_18 ) ;
F_91 ( V_19 ) ;
return 0 ;
}
if ( F_13 ( V_164 , & V_19 -> V_26 ) ) {
struct V_18 * V_158 ;
F_92 ( V_19 -> V_23 -> V_24 ) ;
F_74 ( V_19 -> V_35 ) ;
V_158 = V_19 -> V_29 -> V_165 ( V_19 ) ;
if ( V_158 )
F_87 ( V_33 , V_158 ) ;
else
F_17 ( V_19 -> V_23 -> V_24 ) ;
} else {
F_2 ( L_19 ,
V_78 , V_78 -> V_151 -> V_166 , V_19 ,
F_65 ( & V_19 -> V_20 . V_107 ) ) ;
V_78 -> V_116 = F_93 ( V_19 ) ;
if ( V_78 -> V_116 )
V_14 = F_94 ( V_78 ) ;
else
V_14 = V_19 -> V_29 -> V_167 ( V_78 ) ;
F_2 ( L_20 , V_14 ) ;
V_78 -> V_112 = V_33 -> V_136 ;
F_95 ( V_78 -> V_112 , & V_19 -> V_113 ) ;
}
F_32 ( V_19 ) ;
return V_14 ;
}
int F_96 ( struct V_77 * V_78 , long V_150 )
{
struct V_18 * V_19 = NULL ;
struct V_32 * V_33 = V_78 -> V_132 ;
int V_14 , V_75 ;
F_2 ( L_21 ,
V_78 , V_150 ) ;
if ( V_78 -> V_101 )
F_60 ( V_102
L_22 ,
V_78 ) ;
V_75 = F_76 ( V_78 ) ;
if ( V_75 )
return V_75 ;
F_86 () ;
F_97 () ;
if ( F_79 () || F_80 () )
return - V_145 ;
V_19 = F_84 ( V_78 , V_150 ) ;
if ( F_44 ( V_19 ) )
return F_45 ( V_19 ) ;
V_14 = F_90 ( V_78 , V_19 ) ;
if ( V_14 <= 0 )
goto V_9;
F_36 ( V_168 , & V_19 -> V_26 ) ;
V_78 -> V_169 = V_19 -> V_29 -> V_170 ( V_78 ) ;
V_78 -> V_153 . V_171 = V_172 ;
if ( V_33 -> V_173 )
V_33 -> V_173 -> V_174 ++ ;
return V_14 ;
V_9:
V_78 -> V_109 . V_14 = 0 ;
F_68 ( V_78 ) ;
return - V_156 ;
}
void F_98 ( struct V_77 * V_78 )
{
F_2 ( L_23 , V_78 -> V_101 ) ;
F_68 ( V_78 ) ;
}
int F_99 ( struct V_77 * V_78 )
{
struct V_18 * V_19 ;
int V_14 ;
struct V_133 * V_175 ;
V_19 = V_78 -> V_101 ;
if ( ! V_19 )
return - V_176 ;
V_78 -> V_101 -> V_29 -> V_115 ( V_78 ) ;
V_175 = & V_78 -> V_109 ;
V_175 -> V_14 = V_175 -> V_110 [ 0 ] . V_111 +
V_175 -> V_117 +
V_175 -> V_149 [ 0 ] . V_111 ;
F_100 ( & V_19 -> V_40 ) ;
if ( F_13 ( V_177 , & V_19 -> V_26 )
|| F_13 ( V_92 , & V_19 -> V_26 ) )
V_14 = - V_178 ;
else
V_14 = V_19 -> V_29 -> V_179 ( V_78 ) ;
F_101 ( & V_19 -> V_40 ) ;
F_102 ( & V_19 -> V_43 ) ;
F_68 ( V_78 ) ;
if ( V_14 == - V_180 || V_14 == - V_178 || V_14 == - V_156 )
return 0 ;
return V_14 ;
}
static void V_161 ( unsigned long V_181 )
{
struct V_32 * V_33 = (struct V_32 * ) V_181 ;
struct V_18 * V_19 ;
struct V_182 * V_183 , * V_100 ;
F_2 ( L_24 ) ;
if ( ! F_103 ( & V_33 -> V_70 ) ) {
F_2 ( L_25 ) ;
F_89 ( & V_33 -> V_159 , V_162 + V_155 ) ;
return;
}
F_104 (le, next, &serv->sv_tempsocks) {
V_19 = F_59 ( V_183 , struct V_18 , V_36 ) ;
if ( ! F_55 ( V_168 , & V_19 -> V_26 ) )
continue;
if ( F_65 ( & V_19 -> V_20 . V_107 ) > 1 ||
F_13 ( V_42 , & V_19 -> V_26 ) )
continue;
F_9 ( V_183 ) ;
F_24 ( V_92 , & V_19 -> V_26 ) ;
F_24 ( V_184 , & V_19 -> V_26 ) ;
F_2 ( L_26 , V_19 ) ;
F_63 ( V_19 ) ;
}
F_41 ( & V_33 -> V_70 ) ;
F_89 ( & V_33 -> V_159 , V_162 + V_163 * V_155 ) ;
}
static void F_105 ( struct V_18 * V_19 )
{
struct V_185 * V_186 ;
F_4 ( & V_19 -> V_41 ) ;
while ( ! F_58 ( & V_19 -> V_39 ) ) {
V_186 = F_106 ( & V_19 -> V_39 , struct V_185 , V_187 ) ;
F_53 ( & V_186 -> V_187 ) ;
V_186 -> V_188 ( V_186 ) ;
}
F_7 ( & V_19 -> V_41 ) ;
}
static void F_91 ( struct V_18 * V_19 )
{
struct V_32 * V_33 = V_19 -> V_35 ;
struct V_189 * V_190 ;
if ( F_55 ( V_177 , & V_19 -> V_26 ) )
F_107 () ;
F_2 ( L_27 , V_19 ) ;
V_19 -> V_29 -> V_191 ( V_19 ) ;
F_39 ( & V_33 -> V_70 ) ;
if ( ! F_55 ( V_184 , & V_19 -> V_26 ) )
F_9 ( & V_19 -> V_36 ) ;
F_33 ( ! F_58 ( & V_19 -> V_37 ) ) ;
if ( F_13 ( V_69 , & V_19 -> V_26 ) )
V_33 -> V_128 -- ;
F_41 ( & V_33 -> V_70 ) ;
while ( ( V_190 = F_93 ( V_19 ) ) != NULL )
F_69 ( V_190 ) ;
F_105 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_108 ( struct V_18 * V_19 )
{
F_24 ( V_92 , & V_19 -> V_26 ) ;
if ( F_55 ( V_42 , & V_19 -> V_26 ) )
return;
F_91 ( V_19 ) ;
}
static int F_109 ( struct V_32 * V_33 , struct V_182 * V_192 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
int V_193 = 0 ;
F_4 ( & V_33 -> V_70 ) ;
F_5 (xprt, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
V_193 ++ ;
F_24 ( V_92 , & V_19 -> V_26 ) ;
F_63 ( V_19 ) ;
}
F_7 ( & V_33 -> V_70 ) ;
return V_193 ;
}
static struct V_18 * F_110 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
struct V_87 * V_88 ;
struct V_18 * V_19 ;
struct V_18 * V_194 ;
int V_119 ;
for ( V_119 = 0 ; V_119 < V_33 -> V_120 ; V_119 ++ ) {
V_88 = & V_33 -> V_121 [ V_119 ] ;
F_39 ( & V_88 -> V_97 ) ;
F_111 (xprt, tmp, &pool->sp_sockets, xpt_ready) {
if ( V_19 -> V_27 != V_31 )
continue;
F_9 ( & V_19 -> V_37 ) ;
F_41 ( & V_88 -> V_97 ) ;
return V_19 ;
}
F_41 ( & V_88 -> V_97 ) ;
}
return NULL ;
}
static void F_112 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
while ( ( V_19 = F_110 ( V_33 , V_31 ) ) ) {
F_24 ( V_92 , & V_19 -> V_26 ) ;
F_91 ( V_19 ) ;
}
}
void F_113 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
int V_195 = 0 ;
while ( F_109 ( V_33 , & V_33 -> V_71 , V_31 ) +
F_109 ( V_33 , & V_33 -> V_129 , V_31 ) ) {
F_112 ( V_33 , V_31 ) ;
F_114 ( V_195 ++ ) ;
}
}
static void F_115 ( struct V_196 * V_197 , int V_198 )
{
struct V_189 * V_190 =
F_12 ( V_197 , struct V_189 , V_199 ) ;
struct V_18 * V_19 = V_190 -> V_19 ;
F_4 ( & V_19 -> V_41 ) ;
F_24 ( V_94 , & V_19 -> V_26 ) ;
if ( V_198 || F_13 ( V_177 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_41 ) ;
F_2 ( L_28 ) ;
F_18 ( V_19 ) ;
F_69 ( V_190 ) ;
return;
}
F_2 ( L_29 ) ;
V_190 -> V_19 = NULL ;
F_40 ( & V_190 -> V_199 . V_200 , & V_19 -> V_38 ) ;
F_7 ( & V_19 -> V_41 ) ;
F_63 ( V_19 ) ;
F_18 ( V_19 ) ;
}
static struct V_196 * V_172 ( struct V_201 * V_202 )
{
struct V_77 * V_78 = F_12 ( V_202 , struct V_77 , V_153 ) ;
struct V_189 * V_190 ;
if ( V_78 -> V_147 . V_117 || ! V_78 -> V_203 )
return NULL ;
if ( V_78 -> V_116 ) {
V_190 = V_78 -> V_116 ;
V_78 -> V_116 = NULL ;
} else {
T_1 V_204 ;
T_1 V_205 ;
V_205 = sizeof( struct V_189 ) + V_78 -> V_147 . V_14 ;
V_190 = F_116 ( V_205 , V_142 ) ;
if ( V_190 == NULL )
return NULL ;
V_190 -> V_199 . V_22 = V_78 -> V_132 ;
V_190 -> V_206 = V_78 -> V_207 ;
memcpy ( & V_190 -> V_208 , & V_78 -> V_79 , V_78 -> V_82 ) ;
V_190 -> V_209 = V_78 -> V_82 ;
V_190 -> V_210 = V_78 -> V_83 ;
V_190 -> V_211 = V_78 -> V_147 . V_14 >> 2 ;
V_190 -> V_212 = V_78 -> V_213 ;
V_204 = V_78 -> V_147 . V_14 - V_78 -> V_147 . V_110 [ 0 ] . V_111 ;
memcpy ( V_190 -> args , V_78 -> V_147 . V_110 [ 0 ] . V_148 - V_204 ,
V_190 -> V_211 << 2 ) ;
}
F_34 ( V_78 -> V_101 ) ;
V_190 -> V_19 = V_78 -> V_101 ;
V_78 -> V_214 = true ;
V_190 -> V_199 . V_215 = F_115 ;
return & V_190 -> V_199 ;
}
static int F_94 ( struct V_77 * V_78 )
{
struct V_189 * V_190 = V_78 -> V_116 ;
V_78 -> V_147 . V_110 [ 0 ] . V_148 = V_190 -> args + ( V_190 -> V_212 >> 2 ) ;
V_78 -> V_147 . V_110 [ 0 ] . V_111 = ( V_190 -> V_211 << 2 ) - V_190 -> V_212 ;
V_78 -> V_147 . V_117 = 0 ;
V_78 -> V_147 . V_14 = V_190 -> V_211 << 2 ;
V_78 -> V_207 = V_190 -> V_206 ;
memcpy ( & V_78 -> V_79 , & V_190 -> V_208 , V_190 -> V_209 ) ;
V_78 -> V_82 = V_190 -> V_209 ;
V_78 -> V_213 = V_190 -> V_212 ;
V_78 -> V_83 = V_190 -> V_210 ;
V_78 -> V_216 = V_78 -> V_139 ;
return ( V_190 -> V_211 << 2 ) - V_190 -> V_212 ;
}
static struct V_189 * F_93 ( struct V_18 * V_19 )
{
struct V_189 * V_190 = NULL ;
if ( ! F_13 ( V_94 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_41 ) ;
if ( ! F_58 ( & V_19 -> V_38 ) ) {
V_190 = F_59 ( V_19 -> V_38 . V_100 ,
struct V_189 ,
V_199 . V_200 ) ;
F_9 ( & V_190 -> V_199 . V_200 ) ;
} else
F_36 ( V_94 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_41 ) ;
return V_190 ;
}
struct V_18 * F_117 ( struct V_32 * V_33 , const char * V_6 ,
struct V_31 * V_31 , const T_2 V_217 ,
const unsigned short V_45 )
{
struct V_18 * V_19 ;
struct V_18 * V_218 = NULL ;
if ( V_33 == NULL || V_6 == NULL )
return V_218 ;
F_39 ( & V_33 -> V_70 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_217 != V_219 && V_217 != V_19 -> V_84 . V_220 )
continue;
if ( V_45 != 0 && V_45 != F_46 ( V_19 ) )
continue;
V_218 = V_19 ;
F_34 ( V_19 ) ;
break;
}
F_41 ( & V_33 -> V_70 ) ;
return V_218 ;
}
static int F_118 ( const struct V_18 * V_19 ,
char * V_221 , int V_222 )
{
int V_14 ;
V_14 = snprintf ( V_221 , V_222 , L_30 ,
V_19 -> V_23 -> V_6 ,
F_46 ( V_19 ) ) ;
if ( V_14 >= V_222 )
return - V_223 ;
return V_14 ;
}
int F_119 ( struct V_32 * V_33 , char * V_11 , const int V_224 )
{
struct V_18 * V_19 ;
int V_14 , V_225 ;
char * V_221 ;
if ( ! V_33 )
return 0 ;
F_39 ( & V_33 -> V_70 ) ;
V_221 = V_11 ;
V_225 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_118 ( V_19 , V_221 , V_224 - V_225 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_225 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_221 += V_14 ;
V_225 += V_14 ;
}
F_41 ( & V_33 -> V_70 ) ;
return V_225 ;
}
static void * F_120 ( struct V_226 * V_227 , T_3 * V_221 )
{
unsigned int V_228 = ( unsigned int ) * V_221 ;
struct V_32 * V_33 = V_227 -> V_229 ;
F_2 ( L_31 , V_228 ) ;
if ( ! V_228 )
return V_230 ;
return ( V_228 > V_33 -> V_120 ? NULL : & V_33 -> V_121 [ V_228 - 1 ] ) ;
}
static void * F_121 ( struct V_226 * V_227 , void * V_141 , T_3 * V_221 )
{
struct V_87 * V_88 = V_141 ;
struct V_32 * V_33 = V_227 -> V_229 ;
F_2 ( L_32 , * V_221 ) ;
if ( V_141 == V_230 ) {
V_88 = & V_33 -> V_121 [ 0 ] ;
} else {
unsigned int V_228 = ( V_88 - & V_33 -> V_121 [ 0 ] ) ;
if ( V_228 < V_33 -> V_120 - 1 )
V_88 = & V_33 -> V_121 [ V_228 + 1 ] ;
else
V_88 = NULL ;
}
++ * V_221 ;
return V_88 ;
}
static void F_122 ( struct V_226 * V_227 , void * V_141 )
{
}
static int F_123 ( struct V_226 * V_227 , void * V_141 )
{
struct V_87 * V_88 = V_141 ;
if ( V_141 == V_230 ) {
F_124 ( V_227 , L_33 ) ;
return 0 ;
}
F_125 ( V_227 , L_34 ,
V_88 -> V_166 ,
V_88 -> V_98 . V_99 ,
V_88 -> V_98 . V_106 ,
V_88 -> V_98 . V_104 ,
V_88 -> V_98 . V_157 ) ;
return 0 ;
}
int F_126 ( struct V_32 * V_33 , struct V_231 * V_231 )
{
int V_75 ;
V_75 = F_127 ( V_231 , & V_232 ) ;
if ( ! V_75 )
( (struct V_226 * ) V_231 -> V_233 ) -> V_229 = V_33 ;
return V_75 ;
}

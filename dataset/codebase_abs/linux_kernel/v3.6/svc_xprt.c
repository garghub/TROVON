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
int F_32 ( struct V_32 * V_33 , const char * V_68 ,
struct V_31 * V_31 , const int V_44 ,
const unsigned short V_45 , int V_46 )
{
struct V_1 * V_2 ;
F_2 ( L_5 , V_68 , V_45 ) ;
F_4 ( & V_8 ) ;
F_5 (xcl, &svc_xprt_class_list, xcl_list) {
struct V_18 * V_69 ;
unsigned short V_70 ;
if ( strcmp ( V_68 , V_2 -> V_6 ) )
continue;
if ( ! F_33 ( V_2 -> V_24 ) )
goto V_71;
F_7 ( & V_8 ) ;
V_69 = F_27 ( V_2 , V_33 , V_31 , V_44 , V_45 , V_46 ) ;
if ( F_34 ( V_69 ) ) {
F_17 ( V_2 -> V_24 ) ;
return F_35 ( V_69 ) ;
}
F_36 ( V_72 , & V_69 -> V_26 ) ;
F_37 ( & V_33 -> V_73 ) ;
F_38 ( & V_69 -> V_36 , & V_33 -> V_74 ) ;
F_39 ( & V_33 -> V_73 ) ;
V_70 = F_40 ( V_69 ) ;
F_36 ( V_42 , & V_69 -> V_26 ) ;
return V_70 ;
}
V_71:
F_7 ( & V_8 ) ;
F_2 ( L_6 , V_68 ) ;
return - V_75 ;
}
void F_41 ( struct V_76 * V_77 , struct V_18 * V_19 )
{
memcpy ( & V_77 -> V_78 , & V_19 -> V_79 , V_19 -> V_80 ) ;
V_77 -> V_81 = V_19 -> V_80 ;
memcpy ( & V_77 -> V_82 , & V_19 -> V_83 , V_19 -> V_84 ) ;
V_77 -> V_85 = V_19 -> V_84 ;
}
char * F_42 ( struct V_76 * V_77 , char * V_11 , T_1 V_14 )
{
return F_43 ( F_44 ( V_77 ) , V_11 , V_14 ) ;
}
static void F_45 ( struct V_86 * V_87 , struct V_76 * V_77 )
{
F_38 ( & V_77 -> V_88 , & V_87 -> V_89 ) ;
}
static void F_46 ( struct V_86 * V_87 , struct V_76 * V_77 )
{
F_47 ( & V_77 -> V_88 ) ;
}
static bool F_48 ( struct V_18 * V_19 )
{
if ( V_19 -> V_26 & ( ( 1 << V_90 ) | ( 1 << V_91 ) ) )
return true ;
if ( V_19 -> V_26 & ( ( 1 << V_92 ) | ( 1 << V_93 ) ) )
return V_19 -> V_29 -> V_94 ( V_19 ) ;
return false ;
}
void F_49 ( struct V_18 * V_19 )
{
struct V_86 * V_87 ;
struct V_76 * V_77 ;
int V_95 ;
if ( ! F_48 ( V_19 ) )
return;
V_95 = F_50 () ;
V_87 = F_51 ( V_19 -> V_35 , V_95 ) ;
F_52 () ;
F_37 ( & V_87 -> V_96 ) ;
if ( ! F_53 ( & V_87 -> V_89 ) &&
! F_53 ( & V_87 -> V_97 ) )
F_54 ( V_98
L_7
L_8 ) ;
V_87 -> V_99 . V_100 ++ ;
if ( F_55 ( V_42 , & V_19 -> V_26 ) ) {
F_2 ( L_9 , V_19 ) ;
goto V_101;
}
if ( ! F_53 ( & V_87 -> V_89 ) ) {
V_77 = F_56 ( V_87 -> V_89 . V_102 ,
struct V_76 ,
V_88 ) ;
F_2 ( L_10 ,
V_19 , V_77 ) ;
F_46 ( V_87 , V_77 ) ;
if ( V_77 -> V_103 )
F_54 ( V_98
L_11 ,
V_77 , V_77 -> V_103 ) ;
V_77 -> V_103 = V_19 ;
F_57 ( V_19 ) ;
V_87 -> V_99 . V_104 ++ ;
F_58 ( & V_77 -> V_105 ) ;
} else {
F_2 ( L_12 , V_19 ) ;
F_6 ( & V_19 -> V_37 , & V_87 -> V_97 ) ;
V_87 -> V_99 . V_106 ++ ;
}
V_101:
F_39 ( & V_87 -> V_96 ) ;
}
static struct V_18 * F_59 ( struct V_86 * V_87 )
{
struct V_18 * V_19 ;
if ( F_53 ( & V_87 -> V_97 ) )
return NULL ;
V_19 = F_56 ( V_87 -> V_97 . V_102 ,
struct V_18 , V_37 ) ;
F_9 ( & V_19 -> V_37 ) ;
F_2 ( L_13 ,
V_19 , F_60 ( & V_19 -> V_20 . V_107 ) ) ;
return V_19 ;
}
void F_61 ( struct V_18 * V_19 )
{
F_62 ( ! F_13 ( V_42 , & V_19 -> V_26 ) ) ;
F_57 ( V_19 ) ;
F_36 ( V_42 , & V_19 -> V_26 ) ;
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_63 ( struct V_76 * V_77 , int V_108 )
{
V_108 += V_77 -> V_109 . V_110 [ 0 ] . V_111 ;
if ( V_108 < V_77 -> V_112 ) {
struct V_18 * V_19 = V_77 -> V_103 ;
F_64 ( ( V_77 -> V_112 - V_108 ) , & V_19 -> V_113 ) ;
V_77 -> V_112 = V_108 ;
F_49 ( V_19 ) ;
}
}
static void F_65 ( struct V_76 * V_77 )
{
struct V_18 * V_19 = V_77 -> V_103 ;
V_77 -> V_103 -> V_29 -> V_114 ( V_77 ) ;
F_66 ( V_77 -> V_115 ) ;
V_77 -> V_115 = NULL ;
F_67 ( V_77 ) ;
V_77 -> V_109 . V_116 = 0 ;
V_77 -> V_109 . V_117 = 0 ;
if ( ( V_77 -> V_109 . V_14 ) > V_77 -> V_112 )
F_54 ( V_98 L_14 ,
V_77 -> V_112 ,
V_77 -> V_109 . V_14 ) ;
V_77 -> V_109 . V_110 [ 0 ] . V_111 = 0 ;
F_63 ( V_77 , 0 ) ;
V_77 -> V_103 = NULL ;
F_18 ( V_19 ) ;
}
void F_68 ( struct V_32 * V_33 )
{
struct V_76 * V_77 ;
unsigned int V_118 ;
struct V_86 * V_87 ;
for ( V_118 = 0 ; V_118 < V_33 -> V_119 ; V_118 ++ ) {
V_87 = & V_33 -> V_120 [ V_118 ] ;
F_37 ( & V_87 -> V_96 ) ;
if ( ! F_53 ( & V_87 -> V_89 ) ) {
V_77 = F_56 ( V_87 -> V_89 . V_102 ,
struct V_76 ,
V_88 ) ;
F_2 ( L_15 , V_77 ) ;
F_58 ( & V_77 -> V_105 ) ;
}
F_39 ( & V_87 -> V_96 ) ;
}
}
int F_69 ( struct V_62 * sin )
{
switch ( sin -> V_121 ) {
case V_49 :
return F_70 ( ( (struct V_47 * ) sin ) -> V_53 )
< V_122 ;
case V_58 :
return F_70 ( ( (struct V_55 * ) sin ) -> V_61 )
< V_122 ;
default:
return 0 ;
}
}
static void F_71 ( struct V_32 * V_33 )
{
unsigned int V_123 = V_33 -> V_124 ? V_33 -> V_124 :
( V_33 -> V_125 + 3 ) * 20 ;
if ( V_33 -> V_126 > V_123 ) {
struct V_18 * V_19 = NULL ;
F_37 ( & V_33 -> V_73 ) ;
if ( ! F_53 ( & V_33 -> V_127 ) ) {
F_72 ( L_16 ,
V_33 -> V_128 , V_33 -> V_124 ?
L_17 :
L_18 ) ;
V_19 = F_56 ( V_33 -> V_127 . V_129 ,
struct V_18 ,
V_36 ) ;
F_24 ( V_91 , & V_19 -> V_26 ) ;
F_57 ( V_19 ) ;
}
F_39 ( & V_33 -> V_73 ) ;
if ( V_19 ) {
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
}
}
int F_73 ( struct V_76 * V_77 , long V_130 )
{
struct V_18 * V_19 = NULL ;
struct V_32 * V_33 = V_77 -> V_131 ;
struct V_86 * V_87 = V_77 -> V_132 ;
int V_14 , V_118 ;
int V_133 ;
struct V_134 * V_135 ;
F_74 ( V_136 , V_137 ) ;
long V_138 ;
F_2 ( L_19 ,
V_77 , V_130 ) ;
if ( V_77 -> V_103 )
F_54 ( V_98
L_20 ,
V_77 ) ;
if ( F_75 ( & V_77 -> V_105 ) )
F_54 ( V_98
L_21 ,
V_77 ) ;
V_133 = ( V_33 -> V_139 + V_140 ) / V_140 ;
F_62 ( V_133 >= V_141 ) ;
for ( V_118 = 0 ; V_118 < V_133 ; V_118 ++ )
while ( V_77 -> V_142 [ V_118 ] == NULL ) {
struct V_143 * V_144 = F_76 ( V_145 ) ;
if ( ! V_144 ) {
F_77 ( V_146 ) ;
if ( F_78 () || F_79 () ) {
F_77 ( V_147 ) ;
return - V_148 ;
}
F_80 ( F_81 ( 500 ) ) ;
}
V_77 -> V_142 [ V_118 ] = V_144 ;
}
V_77 -> V_142 [ V_118 ++ ] = NULL ;
V_135 = & V_77 -> V_149 ;
V_135 -> V_110 [ 0 ] . V_150 = F_82 ( V_77 -> V_142 [ 0 ] ) ;
V_135 -> V_110 [ 0 ] . V_111 = V_140 ;
V_135 -> V_133 = V_77 -> V_142 + 1 ;
V_135 -> V_117 = 0 ;
V_135 -> V_116 = ( V_133 - 2 ) * V_140 ;
V_135 -> V_14 = ( V_133 - 1 ) * V_140 ;
V_135 -> V_151 [ 0 ] . V_111 = 0 ;
F_83 () ;
F_84 () ;
if ( F_78 () || F_79 () )
return - V_148 ;
V_77 -> V_152 . V_153 = 5 * V_154 ;
F_37 ( & V_87 -> V_96 ) ;
V_19 = F_59 ( V_87 ) ;
if ( V_19 ) {
V_77 -> V_103 = V_19 ;
F_57 ( V_19 ) ;
V_77 -> V_152 . V_153 = 1 * V_154 ;
} else {
F_45 ( V_87 , V_77 ) ;
F_77 ( V_146 ) ;
if ( F_79 () ) {
F_77 ( V_147 ) ;
F_39 ( & V_87 -> V_96 ) ;
return - V_148 ;
}
F_85 ( & V_77 -> V_105 , & V_136 ) ;
F_39 ( & V_87 -> V_96 ) ;
V_138 = F_80 ( V_130 ) ;
F_83 () ;
F_37 ( & V_87 -> V_96 ) ;
F_86 ( & V_77 -> V_105 , & V_136 ) ;
if ( ! V_138 )
V_87 -> V_99 . V_155 ++ ;
V_19 = V_77 -> V_103 ;
if ( ! V_19 ) {
F_46 ( V_87 , V_77 ) ;
F_39 ( & V_87 -> V_96 ) ;
F_2 ( L_22 , V_77 ) ;
if ( F_78 () || F_79 () )
return - V_148 ;
else
return - V_156 ;
}
}
F_39 ( & V_87 -> V_96 ) ;
V_14 = 0 ;
if ( F_13 ( V_91 , & V_19 -> V_26 ) ) {
F_2 ( L_23 ) ;
F_87 ( V_19 ) ;
goto V_9;
}
if ( F_13 ( V_157 , & V_19 -> V_26 ) ) {
struct V_18 * V_158 ;
V_158 = V_19 -> V_29 -> V_159 ( V_19 ) ;
if ( V_158 ) {
F_88 ( V_158 -> V_23 -> V_24 ) ;
F_71 ( V_19 -> V_35 ) ;
F_37 ( & V_33 -> V_73 ) ;
F_24 ( V_72 , & V_158 -> V_26 ) ;
F_38 ( & V_158 -> V_36 , & V_33 -> V_127 ) ;
V_33 -> V_126 ++ ;
if ( V_33 -> V_160 . V_161 == NULL ) {
F_89 ( & V_33 -> V_160 ,
V_162 ,
( unsigned long ) V_33 ) ;
F_90 ( & V_33 -> V_160 ,
V_163 + V_164 * V_154 ) ;
}
F_39 ( & V_33 -> V_73 ) ;
F_61 ( V_158 ) ;
}
} else if ( V_19 -> V_29 -> V_94 ( V_19 ) ) {
F_2 ( L_24 ,
V_77 , V_87 -> V_165 , V_19 ,
F_60 ( & V_19 -> V_20 . V_107 ) ) ;
V_77 -> V_115 = F_91 ( V_19 ) ;
if ( V_77 -> V_115 )
V_14 = F_92 ( V_77 ) ;
else
V_14 = V_19 -> V_29 -> V_166 ( V_77 ) ;
F_2 ( L_25 , V_14 ) ;
V_77 -> V_112 = V_33 -> V_139 ;
F_93 ( V_77 -> V_112 , & V_19 -> V_113 ) ;
}
F_61 ( V_19 ) ;
if ( V_14 == 0 || V_14 == - V_156 )
goto V_9;
F_36 ( V_167 , & V_19 -> V_26 ) ;
V_77 -> V_168 = F_69 ( F_44 ( V_77 ) ) ;
V_77 -> V_152 . V_169 = V_170 ;
if ( V_33 -> V_171 )
V_33 -> V_171 -> V_172 ++ ;
return V_14 ;
V_9:
V_77 -> V_109 . V_14 = 0 ;
F_65 ( V_77 ) ;
return - V_156 ;
}
void F_94 ( struct V_76 * V_77 )
{
F_2 ( L_26 , V_77 -> V_103 ) ;
F_65 ( V_77 ) ;
}
int F_95 ( struct V_76 * V_77 )
{
struct V_18 * V_19 ;
int V_14 ;
struct V_134 * V_173 ;
V_19 = V_77 -> V_103 ;
if ( ! V_19 )
return - V_174 ;
V_77 -> V_103 -> V_29 -> V_114 ( V_77 ) ;
V_173 = & V_77 -> V_109 ;
V_173 -> V_14 = V_173 -> V_110 [ 0 ] . V_111 +
V_173 -> V_116 +
V_173 -> V_151 [ 0 ] . V_111 ;
F_96 ( & V_19 -> V_40 ) ;
if ( F_13 ( V_175 , & V_19 -> V_26 )
|| F_13 ( V_91 , & V_19 -> V_26 ) )
V_14 = - V_176 ;
else
V_14 = V_19 -> V_29 -> V_177 ( V_77 ) ;
F_97 ( & V_19 -> V_40 ) ;
F_98 ( & V_19 -> V_43 ) ;
F_65 ( V_77 ) ;
if ( V_14 == - V_178 || V_14 == - V_176 || V_14 == - V_156 )
return 0 ;
return V_14 ;
}
static void V_162 ( unsigned long V_179 )
{
struct V_32 * V_33 = (struct V_32 * ) V_179 ;
struct V_18 * V_19 ;
struct V_180 * V_181 , * V_102 ;
F_99 ( V_182 ) ;
F_2 ( L_27 ) ;
if ( ! F_100 ( & V_33 -> V_73 ) ) {
F_2 ( L_28 ) ;
F_90 ( & V_33 -> V_160 , V_163 + V_154 ) ;
return;
}
F_101 (le, next, &serv->sv_tempsocks) {
V_19 = F_56 ( V_181 , struct V_18 , V_36 ) ;
if ( ! F_55 ( V_167 , & V_19 -> V_26 ) )
continue;
if ( F_60 ( & V_19 -> V_20 . V_107 ) > 1 ||
F_13 ( V_42 , & V_19 -> V_26 ) )
continue;
F_57 ( V_19 ) ;
F_102 ( V_181 , & V_182 ) ;
F_24 ( V_91 , & V_19 -> V_26 ) ;
F_24 ( V_183 , & V_19 -> V_26 ) ;
}
F_39 ( & V_33 -> V_73 ) ;
while ( ! F_53 ( & V_182 ) ) {
V_181 = V_182 . V_102 ;
F_9 ( V_181 ) ;
V_19 = F_56 ( V_181 , struct V_18 , V_36 ) ;
F_2 ( L_29 , V_19 ) ;
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
F_90 ( & V_33 -> V_160 , V_163 + V_164 * V_154 ) ;
}
static void F_103 ( struct V_18 * V_19 )
{
struct V_184 * V_185 ;
F_4 ( & V_19 -> V_41 ) ;
while ( ! F_53 ( & V_19 -> V_39 ) ) {
V_185 = F_104 ( & V_19 -> V_39 , struct V_184 , V_186 ) ;
F_47 ( & V_185 -> V_186 ) ;
V_185 -> V_187 ( V_185 ) ;
}
F_7 ( & V_19 -> V_41 ) ;
}
static void F_87 ( struct V_18 * V_19 )
{
struct V_32 * V_33 = V_19 -> V_35 ;
struct V_188 * V_189 ;
if ( F_55 ( V_175 , & V_19 -> V_26 ) )
F_105 () ;
F_2 ( L_30 , V_19 ) ;
V_19 -> V_29 -> V_190 ( V_19 ) ;
F_37 ( & V_33 -> V_73 ) ;
if ( ! F_55 ( V_183 , & V_19 -> V_26 ) )
F_9 ( & V_19 -> V_36 ) ;
F_62 ( ! F_53 ( & V_19 -> V_37 ) ) ;
if ( F_13 ( V_72 , & V_19 -> V_26 ) )
V_33 -> V_126 -- ;
F_39 ( & V_33 -> V_73 ) ;
while ( ( V_189 = F_91 ( V_19 ) ) != NULL )
F_66 ( V_189 ) ;
F_103 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_106 ( struct V_18 * V_19 )
{
F_24 ( V_91 , & V_19 -> V_26 ) ;
if ( F_55 ( V_42 , & V_19 -> V_26 ) )
return;
F_87 ( V_19 ) ;
}
static void F_107 ( struct V_180 * V_191 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
F_5 (xprt, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
F_24 ( V_91 , & V_19 -> V_26 ) ;
F_24 ( V_42 , & V_19 -> V_26 ) ;
}
}
static void F_108 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
struct V_86 * V_87 ;
struct V_18 * V_19 ;
struct V_18 * V_192 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_33 -> V_119 ; V_118 ++ ) {
V_87 = & V_33 -> V_120 [ V_118 ] ;
F_37 ( & V_87 -> V_96 ) ;
F_109 (xprt, tmp, &pool->sp_sockets, xpt_ready) {
if ( V_19 -> V_27 != V_31 )
continue;
F_9 ( & V_19 -> V_37 ) ;
}
F_39 ( & V_87 -> V_96 ) ;
}
}
static void F_110 ( struct V_180 * V_191 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
struct V_18 * V_192 ;
F_109 (xprt, tmp, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
F_87 ( V_19 ) ;
}
F_5 (xprt, xprt_list, xpt_list)
F_62 ( V_19 -> V_27 == V_31 ) ;
}
void F_111 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
F_107 ( & V_33 -> V_127 , V_31 ) ;
F_107 ( & V_33 -> V_74 , V_31 ) ;
F_108 ( V_33 , V_31 ) ;
F_110 ( & V_33 -> V_127 , V_31 ) ;
F_110 ( & V_33 -> V_74 , V_31 ) ;
}
static void F_112 ( struct V_193 * V_194 , int V_195 )
{
struct V_188 * V_189 =
F_12 ( V_194 , struct V_188 , V_196 ) ;
struct V_18 * V_19 = V_189 -> V_19 ;
F_4 ( & V_19 -> V_41 ) ;
F_24 ( V_93 , & V_19 -> V_26 ) ;
if ( V_195 || F_13 ( V_175 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_41 ) ;
F_2 ( L_31 ) ;
F_18 ( V_19 ) ;
F_66 ( V_189 ) ;
return;
}
F_2 ( L_32 ) ;
V_189 -> V_19 = NULL ;
F_38 ( & V_189 -> V_196 . V_197 , & V_19 -> V_38 ) ;
F_7 ( & V_19 -> V_41 ) ;
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
static struct V_193 * V_170 ( struct V_198 * V_199 )
{
struct V_76 * V_77 = F_12 ( V_199 , struct V_76 , V_152 ) ;
struct V_188 * V_189 ;
if ( V_77 -> V_149 . V_116 || ! V_77 -> V_200 )
return NULL ;
if ( V_77 -> V_115 ) {
V_189 = V_77 -> V_115 ;
V_77 -> V_115 = NULL ;
} else {
T_1 V_201 ;
T_1 V_202 ;
V_202 = sizeof( struct V_188 ) + V_77 -> V_149 . V_14 ;
V_189 = F_113 ( V_202 , V_145 ) ;
if ( V_189 == NULL )
return NULL ;
V_189 -> V_196 . V_22 = V_77 -> V_131 ;
V_189 -> V_203 = V_77 -> V_204 ;
memcpy ( & V_189 -> V_205 , & V_77 -> V_78 , V_77 -> V_81 ) ;
V_189 -> V_206 = V_77 -> V_81 ;
V_189 -> V_207 = V_77 -> V_82 ;
V_189 -> V_208 = V_77 -> V_149 . V_14 >> 2 ;
V_189 -> V_209 = V_77 -> V_210 ;
V_201 = V_77 -> V_149 . V_14 - V_77 -> V_149 . V_110 [ 0 ] . V_111 ;
memcpy ( V_189 -> args , V_77 -> V_149 . V_110 [ 0 ] . V_150 - V_201 ,
V_189 -> V_208 << 2 ) ;
}
F_57 ( V_77 -> V_103 ) ;
V_189 -> V_19 = V_77 -> V_103 ;
V_77 -> V_211 = true ;
V_189 -> V_196 . V_212 = F_112 ;
return & V_189 -> V_196 ;
}
static int F_92 ( struct V_76 * V_77 )
{
struct V_188 * V_189 = V_77 -> V_115 ;
V_77 -> V_149 . V_110 [ 0 ] . V_150 = V_189 -> args + ( V_189 -> V_209 >> 2 ) ;
V_77 -> V_149 . V_110 [ 0 ] . V_111 = ( V_189 -> V_208 << 2 ) - V_189 -> V_209 ;
V_77 -> V_149 . V_116 = 0 ;
V_77 -> V_149 . V_14 = V_189 -> V_208 << 2 ;
V_77 -> V_204 = V_189 -> V_203 ;
memcpy ( & V_77 -> V_78 , & V_189 -> V_205 , V_189 -> V_206 ) ;
V_77 -> V_81 = V_189 -> V_206 ;
V_77 -> V_210 = V_189 -> V_209 ;
V_77 -> V_82 = V_189 -> V_207 ;
V_77 -> V_213 = V_77 -> V_142 ;
return ( V_189 -> V_208 << 2 ) - V_189 -> V_209 ;
}
static struct V_188 * F_91 ( struct V_18 * V_19 )
{
struct V_188 * V_189 = NULL ;
if ( ! F_13 ( V_93 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_41 ) ;
if ( ! F_53 ( & V_19 -> V_38 ) ) {
V_189 = F_56 ( V_19 -> V_38 . V_102 ,
struct V_188 ,
V_196 . V_197 ) ;
F_9 ( & V_189 -> V_196 . V_197 ) ;
} else
F_36 ( V_93 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_41 ) ;
return V_189 ;
}
struct V_18 * F_114 ( struct V_32 * V_33 , const char * V_6 ,
struct V_31 * V_31 , const T_2 V_214 ,
const unsigned short V_45 )
{
struct V_18 * V_19 ;
struct V_18 * V_215 = NULL ;
if ( V_33 == NULL || V_6 == NULL )
return V_215 ;
F_37 ( & V_33 -> V_73 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_214 != V_216 && V_214 != V_19 -> V_83 . V_217 )
continue;
if ( V_45 != 0 && V_45 != F_40 ( V_19 ) )
continue;
V_215 = V_19 ;
F_57 ( V_19 ) ;
break;
}
F_39 ( & V_33 -> V_73 ) ;
return V_215 ;
}
static int F_115 ( const struct V_18 * V_19 ,
char * V_218 , int V_219 )
{
int V_14 ;
V_14 = snprintf ( V_218 , V_219 , L_33 ,
V_19 -> V_23 -> V_6 ,
F_40 ( V_19 ) ) ;
if ( V_14 >= V_219 )
return - V_220 ;
return V_14 ;
}
int F_116 ( struct V_32 * V_33 , char * V_11 , const int V_221 )
{
struct V_18 * V_19 ;
int V_14 , V_222 ;
char * V_218 ;
if ( ! V_33 )
return 0 ;
F_37 ( & V_33 -> V_73 ) ;
V_218 = V_11 ;
V_222 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_115 ( V_19 , V_218 , V_221 - V_222 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_222 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_218 += V_14 ;
V_222 += V_14 ;
}
F_39 ( & V_33 -> V_73 ) ;
return V_222 ;
}
static void * F_117 ( struct V_223 * V_224 , T_3 * V_218 )
{
unsigned int V_225 = ( unsigned int ) * V_218 ;
struct V_32 * V_33 = V_224 -> V_226 ;
F_2 ( L_34 , V_225 ) ;
if ( ! V_225 )
return V_227 ;
return ( V_225 > V_33 -> V_119 ? NULL : & V_33 -> V_120 [ V_225 - 1 ] ) ;
}
static void * F_118 ( struct V_223 * V_224 , void * V_144 , T_3 * V_218 )
{
struct V_86 * V_87 = V_144 ;
struct V_32 * V_33 = V_224 -> V_226 ;
F_2 ( L_35 , * V_218 ) ;
if ( V_144 == V_227 ) {
V_87 = & V_33 -> V_120 [ 0 ] ;
} else {
unsigned int V_225 = ( V_87 - & V_33 -> V_120 [ 0 ] ) ;
if ( V_225 < V_33 -> V_119 - 1 )
V_87 = & V_33 -> V_120 [ V_225 + 1 ] ;
else
V_87 = NULL ;
}
++ * V_218 ;
return V_87 ;
}
static void F_119 ( struct V_223 * V_224 , void * V_144 )
{
}
static int F_120 ( struct V_223 * V_224 , void * V_144 )
{
struct V_86 * V_87 = V_144 ;
if ( V_144 == V_227 ) {
F_121 ( V_224 , L_36 ) ;
return 0 ;
}
F_122 ( V_224 , L_37 ,
V_87 -> V_165 ,
V_87 -> V_99 . V_100 ,
V_87 -> V_99 . V_106 ,
V_87 -> V_99 . V_104 ,
V_87 -> V_99 . V_155 ) ;
return 0 ;
}
int F_123 ( struct V_32 * V_33 , struct V_228 * V_228 )
{
int V_71 ;
V_71 = F_124 ( V_228 , & V_229 ) ;
if ( ! V_71 )
( (struct V_223 * ) V_228 -> V_230 ) -> V_226 = V_33 ;
return V_71 ;
}

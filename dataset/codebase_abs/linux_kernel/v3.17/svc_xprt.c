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
V_96 = F_55 () ;
V_88 = F_56 ( V_19 -> V_35 , V_96 ) ;
F_57 () ;
F_39 ( & V_88 -> V_97 ) ;
if ( ! F_58 ( & V_88 -> V_90 ) &&
! F_58 ( & V_88 -> V_98 ) )
F_59 ( V_99
L_7
L_8 ) ;
V_88 -> V_100 . V_101 ++ ;
if ( F_60 ( V_42 , & V_19 -> V_26 ) ) {
F_2 ( L_9 , V_19 ) ;
goto V_102;
}
if ( ! F_58 ( & V_88 -> V_90 ) ) {
V_78 = F_61 ( V_88 -> V_90 . V_103 ,
struct V_77 ,
V_89 ) ;
F_2 ( L_10 ,
V_19 , V_78 ) ;
F_52 ( V_88 , V_78 ) ;
if ( V_78 -> V_104 )
F_59 ( V_99
L_11 ,
V_78 , V_78 -> V_104 ) ;
V_78 -> V_104 = V_19 ;
F_34 ( V_19 ) ;
V_88 -> V_100 . V_105 ++ ;
F_62 ( & V_78 -> V_106 ) ;
} else {
F_2 ( L_12 , V_19 ) ;
F_6 ( & V_19 -> V_37 , & V_88 -> V_98 ) ;
V_88 -> V_100 . V_107 ++ ;
}
V_102:
F_41 ( & V_88 -> V_97 ) ;
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
if ( F_58 ( & V_88 -> V_98 ) )
return NULL ;
V_19 = F_61 ( V_88 -> V_98 . V_103 ,
struct V_18 , V_37 ) ;
F_9 ( & V_19 -> V_37 ) ;
F_2 ( L_13 ,
V_19 , F_65 ( & V_19 -> V_20 . V_108 ) ) ;
return V_19 ;
}
void F_66 ( struct V_77 * V_78 , int V_109 )
{
V_109 += V_78 -> V_110 . V_111 [ 0 ] . V_112 ;
if ( V_109 < V_78 -> V_113 ) {
struct V_18 * V_19 = V_78 -> V_104 ;
F_67 ( ( V_78 -> V_113 - V_109 ) , & V_19 -> V_114 ) ;
V_78 -> V_113 = V_109 ;
if ( V_19 -> V_29 -> V_115 )
V_19 -> V_29 -> V_115 ( V_19 ) ;
F_63 ( V_19 ) ;
}
}
static void F_68 ( struct V_77 * V_78 )
{
struct V_18 * V_19 = V_78 -> V_104 ;
V_78 -> V_104 -> V_29 -> V_116 ( V_78 ) ;
F_69 ( V_78 -> V_117 ) ;
V_78 -> V_117 = NULL ;
F_70 ( V_78 ) ;
V_78 -> V_110 . V_118 = 0 ;
V_78 -> V_110 . V_119 = 0 ;
if ( ( V_78 -> V_110 . V_14 ) > V_78 -> V_113 )
F_59 ( V_99 L_14 ,
V_78 -> V_113 ,
V_78 -> V_110 . V_14 ) ;
V_78 -> V_110 . V_111 [ 0 ] . V_112 = 0 ;
F_66 ( V_78 , 0 ) ;
V_78 -> V_104 = NULL ;
F_18 ( V_19 ) ;
}
void F_71 ( struct V_32 * V_33 )
{
struct V_77 * V_78 ;
unsigned int V_120 ;
struct V_87 * V_88 ;
for ( V_120 = 0 ; V_120 < V_33 -> V_121 ; V_120 ++ ) {
V_88 = & V_33 -> V_122 [ V_120 ] ;
F_39 ( & V_88 -> V_97 ) ;
if ( ! F_58 ( & V_88 -> V_90 ) ) {
V_78 = F_61 ( V_88 -> V_90 . V_103 ,
struct V_77 ,
V_89 ) ;
F_2 ( L_15 , V_78 ) ;
F_62 ( & V_78 -> V_106 ) ;
} else
V_88 -> V_123 = 1 ;
F_41 ( & V_88 -> V_97 ) ;
}
}
int F_72 ( struct V_62 * sin )
{
switch ( sin -> V_124 ) {
case V_49 :
return F_73 ( ( (struct V_47 * ) sin ) -> V_53 )
< V_125 ;
case V_58 :
return F_73 ( ( (struct V_55 * ) sin ) -> V_61 )
< V_125 ;
default:
return 0 ;
}
}
static void F_74 ( struct V_32 * V_33 )
{
unsigned int V_126 = V_33 -> V_127 ? V_33 -> V_127 :
( V_33 -> V_128 + 3 ) * 20 ;
if ( V_33 -> V_129 > V_126 ) {
struct V_18 * V_19 = NULL ;
F_39 ( & V_33 -> V_70 ) ;
if ( ! F_58 ( & V_33 -> V_130 ) ) {
F_75 ( L_16 ,
V_33 -> V_131 , V_33 -> V_127 ?
L_17 :
L_18 ) ;
V_19 = F_61 ( V_33 -> V_130 . V_132 ,
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
struct V_32 * V_33 = V_78 -> V_133 ;
struct V_134 * V_135 ;
int V_136 ;
int V_120 ;
V_136 = ( V_33 -> V_137 + V_138 ) / V_138 ;
F_33 ( V_136 >= V_139 ) ;
if ( V_136 >= V_139 )
V_136 = V_139 - 1 ;
for ( V_120 = 0 ; V_120 < V_136 ; V_120 ++ )
while ( V_78 -> V_140 [ V_120 ] == NULL ) {
struct V_141 * V_142 = F_77 ( V_143 ) ;
if ( ! V_142 ) {
F_78 ( V_144 ) ;
if ( F_79 () || F_80 () ) {
F_78 ( V_145 ) ;
return - V_146 ;
}
F_81 ( F_82 ( 500 ) ) ;
}
V_78 -> V_140 [ V_120 ] = V_142 ;
}
V_78 -> V_147 = & V_78 -> V_140 [ V_120 ] ;
V_78 -> V_140 [ V_120 ++ ] = NULL ;
V_135 = & V_78 -> V_148 ;
V_135 -> V_111 [ 0 ] . V_149 = F_83 ( V_78 -> V_140 [ 0 ] ) ;
V_135 -> V_111 [ 0 ] . V_112 = V_138 ;
V_135 -> V_136 = V_78 -> V_140 + 1 ;
V_135 -> V_119 = 0 ;
V_135 -> V_118 = ( V_136 - 2 ) * V_138 ;
V_135 -> V_14 = ( V_136 - 1 ) * V_138 ;
V_135 -> V_150 [ 0 ] . V_112 = 0 ;
return 0 ;
}
static struct V_18 * F_84 ( struct V_77 * V_78 , long V_151 )
{
struct V_18 * V_19 ;
struct V_87 * V_88 = V_78 -> V_152 ;
F_85 ( V_153 , V_154 ) ;
long V_155 ;
V_78 -> V_156 . V_157 = 5 * V_158 ;
F_39 ( & V_88 -> V_97 ) ;
V_19 = F_64 ( V_88 ) ;
if ( V_19 ) {
V_78 -> V_104 = V_19 ;
F_34 ( V_19 ) ;
V_78 -> V_156 . V_157 = 1 * V_158 ;
V_88 -> V_123 = 0 ;
} else {
if ( V_88 -> V_123 ) {
V_88 -> V_123 = 0 ;
F_41 ( & V_88 -> V_97 ) ;
return F_31 ( - V_159 ) ;
}
F_51 ( V_88 , V_78 ) ;
F_78 ( V_144 ) ;
if ( F_80 () ) {
F_78 ( V_145 ) ;
F_41 ( & V_88 -> V_97 ) ;
return F_31 ( - V_146 ) ;
}
F_86 ( & V_78 -> V_106 , & V_153 ) ;
F_41 ( & V_88 -> V_97 ) ;
V_155 = F_81 ( V_151 ) ;
F_87 () ;
F_39 ( & V_88 -> V_97 ) ;
F_88 ( & V_78 -> V_106 , & V_153 ) ;
if ( ! V_155 )
V_88 -> V_100 . V_160 ++ ;
V_19 = V_78 -> V_104 ;
if ( ! V_19 ) {
F_52 ( V_88 , V_78 ) ;
F_41 ( & V_88 -> V_97 ) ;
F_2 ( L_19 , V_78 ) ;
if ( F_79 () || F_80 () )
return F_31 ( - V_146 ) ;
else
return F_31 ( - V_159 ) ;
}
}
F_41 ( & V_88 -> V_97 ) ;
return V_19 ;
}
static void F_89 ( struct V_32 * V_33 , struct V_18 * V_161 )
{
F_39 ( & V_33 -> V_70 ) ;
F_24 ( V_69 , & V_161 -> V_26 ) ;
F_40 ( & V_161 -> V_36 , & V_33 -> V_130 ) ;
V_33 -> V_129 ++ ;
if ( V_33 -> V_162 . V_163 == NULL ) {
F_90 ( & V_33 -> V_162 , V_164 ,
( unsigned long ) V_33 ) ;
F_91 ( & V_33 -> V_162 ,
V_165 + V_166 * V_158 ) ;
}
F_41 ( & V_33 -> V_70 ) ;
F_32 ( V_161 ) ;
}
static int F_92 ( struct V_77 * V_78 , struct V_18 * V_19 )
{
struct V_32 * V_33 = V_78 -> V_133 ;
int V_14 = 0 ;
if ( F_13 ( V_92 , & V_19 -> V_26 ) ) {
F_2 ( L_20 ) ;
F_93 ( V_19 ) ;
return 0 ;
}
if ( F_13 ( V_167 , & V_19 -> V_26 ) ) {
struct V_18 * V_161 ;
F_94 ( V_19 -> V_23 -> V_24 ) ;
F_74 ( V_19 -> V_35 ) ;
V_161 = V_19 -> V_29 -> V_168 ( V_19 ) ;
if ( V_161 )
F_89 ( V_33 , V_161 ) ;
else
F_17 ( V_19 -> V_23 -> V_24 ) ;
} else if ( V_19 -> V_29 -> V_95 ( V_19 ) ) {
F_2 ( L_21 ,
V_78 , V_78 -> V_152 -> V_169 , V_19 ,
F_65 ( & V_19 -> V_20 . V_108 ) ) ;
V_78 -> V_117 = F_95 ( V_19 ) ;
if ( V_78 -> V_117 )
V_14 = F_96 ( V_78 ) ;
else
V_14 = V_19 -> V_29 -> V_170 ( V_78 ) ;
F_2 ( L_22 , V_14 ) ;
V_78 -> V_113 = V_33 -> V_137 ;
F_97 ( V_78 -> V_113 , & V_19 -> V_114 ) ;
}
F_32 ( V_19 ) ;
return V_14 ;
}
int F_98 ( struct V_77 * V_78 , long V_151 )
{
struct V_18 * V_19 = NULL ;
struct V_32 * V_33 = V_78 -> V_133 ;
int V_14 , V_75 ;
F_2 ( L_23 ,
V_78 , V_151 ) ;
if ( V_78 -> V_104 )
F_59 ( V_99
L_24 ,
V_78 ) ;
if ( F_99 ( & V_78 -> V_106 ) )
F_59 ( V_99
L_25 ,
V_78 ) ;
V_75 = F_76 ( V_78 ) ;
if ( V_75 )
return V_75 ;
F_87 () ;
F_100 () ;
if ( F_79 () || F_80 () )
return - V_146 ;
V_19 = F_84 ( V_78 , V_151 ) ;
if ( F_44 ( V_19 ) )
return F_45 ( V_19 ) ;
V_14 = F_92 ( V_78 , V_19 ) ;
if ( V_14 <= 0 )
goto V_9;
F_36 ( V_171 , & V_19 -> V_26 ) ;
V_78 -> V_172 = V_19 -> V_29 -> V_173 ( V_78 ) ;
V_78 -> V_156 . V_174 = V_175 ;
if ( V_33 -> V_176 )
V_33 -> V_176 -> V_177 ++ ;
return V_14 ;
V_9:
V_78 -> V_110 . V_14 = 0 ;
F_68 ( V_78 ) ;
return - V_159 ;
}
void F_101 ( struct V_77 * V_78 )
{
F_2 ( L_26 , V_78 -> V_104 ) ;
F_68 ( V_78 ) ;
}
int F_102 ( struct V_77 * V_78 )
{
struct V_18 * V_19 ;
int V_14 ;
struct V_134 * V_178 ;
V_19 = V_78 -> V_104 ;
if ( ! V_19 )
return - V_179 ;
V_78 -> V_104 -> V_29 -> V_116 ( V_78 ) ;
V_178 = & V_78 -> V_110 ;
V_178 -> V_14 = V_178 -> V_111 [ 0 ] . V_112 +
V_178 -> V_118 +
V_178 -> V_150 [ 0 ] . V_112 ;
F_103 ( & V_19 -> V_40 ) ;
if ( F_13 ( V_180 , & V_19 -> V_26 )
|| F_13 ( V_92 , & V_19 -> V_26 ) )
V_14 = - V_181 ;
else
V_14 = V_19 -> V_29 -> V_182 ( V_78 ) ;
F_104 ( & V_19 -> V_40 ) ;
F_105 ( & V_19 -> V_43 ) ;
F_68 ( V_78 ) ;
if ( V_14 == - V_183 || V_14 == - V_181 || V_14 == - V_159 )
return 0 ;
return V_14 ;
}
static void V_164 ( unsigned long V_184 )
{
struct V_32 * V_33 = (struct V_32 * ) V_184 ;
struct V_18 * V_19 ;
struct V_185 * V_186 , * V_103 ;
F_2 ( L_27 ) ;
if ( ! F_106 ( & V_33 -> V_70 ) ) {
F_2 ( L_28 ) ;
F_91 ( & V_33 -> V_162 , V_165 + V_158 ) ;
return;
}
F_107 (le, next, &serv->sv_tempsocks) {
V_19 = F_61 ( V_186 , struct V_18 , V_36 ) ;
if ( ! F_60 ( V_171 , & V_19 -> V_26 ) )
continue;
if ( F_65 ( & V_19 -> V_20 . V_108 ) > 1 ||
F_13 ( V_42 , & V_19 -> V_26 ) )
continue;
F_9 ( V_186 ) ;
F_24 ( V_92 , & V_19 -> V_26 ) ;
F_24 ( V_187 , & V_19 -> V_26 ) ;
F_2 ( L_29 , V_19 ) ;
F_63 ( V_19 ) ;
}
F_41 ( & V_33 -> V_70 ) ;
F_91 ( & V_33 -> V_162 , V_165 + V_166 * V_158 ) ;
}
static void F_108 ( struct V_18 * V_19 )
{
struct V_188 * V_189 ;
F_4 ( & V_19 -> V_41 ) ;
while ( ! F_58 ( & V_19 -> V_39 ) ) {
V_189 = F_109 ( & V_19 -> V_39 , struct V_188 , V_190 ) ;
F_53 ( & V_189 -> V_190 ) ;
V_189 -> V_191 ( V_189 ) ;
}
F_7 ( & V_19 -> V_41 ) ;
}
static void F_93 ( struct V_18 * V_19 )
{
struct V_32 * V_33 = V_19 -> V_35 ;
struct V_192 * V_193 ;
if ( F_60 ( V_180 , & V_19 -> V_26 ) )
F_110 () ;
F_2 ( L_30 , V_19 ) ;
V_19 -> V_29 -> V_194 ( V_19 ) ;
F_39 ( & V_33 -> V_70 ) ;
if ( ! F_60 ( V_187 , & V_19 -> V_26 ) )
F_9 ( & V_19 -> V_36 ) ;
F_33 ( ! F_58 ( & V_19 -> V_37 ) ) ;
if ( F_13 ( V_69 , & V_19 -> V_26 ) )
V_33 -> V_129 -- ;
F_41 ( & V_33 -> V_70 ) ;
while ( ( V_193 = F_95 ( V_19 ) ) != NULL )
F_69 ( V_193 ) ;
F_108 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_111 ( struct V_18 * V_19 )
{
F_24 ( V_92 , & V_19 -> V_26 ) ;
if ( F_60 ( V_42 , & V_19 -> V_26 ) )
return;
F_93 ( V_19 ) ;
}
static int F_112 ( struct V_32 * V_33 , struct V_185 * V_195 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
int V_196 = 0 ;
F_4 ( & V_33 -> V_70 ) ;
F_5 (xprt, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
V_196 ++ ;
F_24 ( V_92 , & V_19 -> V_26 ) ;
F_63 ( V_19 ) ;
}
F_7 ( & V_33 -> V_70 ) ;
return V_196 ;
}
static struct V_18 * F_113 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
struct V_87 * V_88 ;
struct V_18 * V_19 ;
struct V_18 * V_197 ;
int V_120 ;
for ( V_120 = 0 ; V_120 < V_33 -> V_121 ; V_120 ++ ) {
V_88 = & V_33 -> V_122 [ V_120 ] ;
F_39 ( & V_88 -> V_97 ) ;
F_114 (xprt, tmp, &pool->sp_sockets, xpt_ready) {
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
static void F_115 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
while ( ( V_19 = F_113 ( V_33 , V_31 ) ) ) {
F_24 ( V_92 , & V_19 -> V_26 ) ;
F_93 ( V_19 ) ;
}
}
void F_116 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
int V_198 = 0 ;
while ( F_112 ( V_33 , & V_33 -> V_71 , V_31 ) +
F_112 ( V_33 , & V_33 -> V_130 , V_31 ) ) {
F_115 ( V_33 , V_31 ) ;
F_117 ( V_198 ++ ) ;
}
}
static void F_118 ( struct V_199 * V_200 , int V_201 )
{
struct V_192 * V_193 =
F_12 ( V_200 , struct V_192 , V_202 ) ;
struct V_18 * V_19 = V_193 -> V_19 ;
F_4 ( & V_19 -> V_41 ) ;
F_24 ( V_94 , & V_19 -> V_26 ) ;
if ( V_201 || F_13 ( V_180 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_41 ) ;
F_2 ( L_31 ) ;
F_18 ( V_19 ) ;
F_69 ( V_193 ) ;
return;
}
F_2 ( L_32 ) ;
V_193 -> V_19 = NULL ;
F_40 ( & V_193 -> V_202 . V_203 , & V_19 -> V_38 ) ;
F_7 ( & V_19 -> V_41 ) ;
F_63 ( V_19 ) ;
F_18 ( V_19 ) ;
}
static struct V_199 * V_175 ( struct V_204 * V_205 )
{
struct V_77 * V_78 = F_12 ( V_205 , struct V_77 , V_156 ) ;
struct V_192 * V_193 ;
if ( V_78 -> V_148 . V_118 || ! V_78 -> V_206 )
return NULL ;
if ( V_78 -> V_117 ) {
V_193 = V_78 -> V_117 ;
V_78 -> V_117 = NULL ;
} else {
T_1 V_207 ;
T_1 V_208 ;
V_208 = sizeof( struct V_192 ) + V_78 -> V_148 . V_14 ;
V_193 = F_119 ( V_208 , V_143 ) ;
if ( V_193 == NULL )
return NULL ;
V_193 -> V_202 . V_22 = V_78 -> V_133 ;
V_193 -> V_209 = V_78 -> V_210 ;
memcpy ( & V_193 -> V_211 , & V_78 -> V_79 , V_78 -> V_82 ) ;
V_193 -> V_212 = V_78 -> V_82 ;
V_193 -> V_213 = V_78 -> V_83 ;
V_193 -> V_214 = V_78 -> V_148 . V_14 >> 2 ;
V_193 -> V_215 = V_78 -> V_216 ;
V_207 = V_78 -> V_148 . V_14 - V_78 -> V_148 . V_111 [ 0 ] . V_112 ;
memcpy ( V_193 -> args , V_78 -> V_148 . V_111 [ 0 ] . V_149 - V_207 ,
V_193 -> V_214 << 2 ) ;
}
F_34 ( V_78 -> V_104 ) ;
V_193 -> V_19 = V_78 -> V_104 ;
V_78 -> V_217 = true ;
V_193 -> V_202 . V_218 = F_118 ;
return & V_193 -> V_202 ;
}
static int F_96 ( struct V_77 * V_78 )
{
struct V_192 * V_193 = V_78 -> V_117 ;
V_78 -> V_148 . V_111 [ 0 ] . V_149 = V_193 -> args + ( V_193 -> V_215 >> 2 ) ;
V_78 -> V_148 . V_111 [ 0 ] . V_112 = ( V_193 -> V_214 << 2 ) - V_193 -> V_215 ;
V_78 -> V_148 . V_118 = 0 ;
V_78 -> V_148 . V_14 = V_193 -> V_214 << 2 ;
V_78 -> V_210 = V_193 -> V_209 ;
memcpy ( & V_78 -> V_79 , & V_193 -> V_211 , V_193 -> V_212 ) ;
V_78 -> V_82 = V_193 -> V_212 ;
V_78 -> V_216 = V_193 -> V_215 ;
V_78 -> V_83 = V_193 -> V_213 ;
V_78 -> V_219 = V_78 -> V_140 ;
return ( V_193 -> V_214 << 2 ) - V_193 -> V_215 ;
}
static struct V_192 * F_95 ( struct V_18 * V_19 )
{
struct V_192 * V_193 = NULL ;
if ( ! F_13 ( V_94 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_41 ) ;
if ( ! F_58 ( & V_19 -> V_38 ) ) {
V_193 = F_61 ( V_19 -> V_38 . V_103 ,
struct V_192 ,
V_202 . V_203 ) ;
F_9 ( & V_193 -> V_202 . V_203 ) ;
} else
F_36 ( V_94 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_41 ) ;
return V_193 ;
}
struct V_18 * F_120 ( struct V_32 * V_33 , const char * V_6 ,
struct V_31 * V_31 , const T_2 V_220 ,
const unsigned short V_45 )
{
struct V_18 * V_19 ;
struct V_18 * V_221 = NULL ;
if ( V_33 == NULL || V_6 == NULL )
return V_221 ;
F_39 ( & V_33 -> V_70 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_220 != V_222 && V_220 != V_19 -> V_84 . V_223 )
continue;
if ( V_45 != 0 && V_45 != F_46 ( V_19 ) )
continue;
V_221 = V_19 ;
F_34 ( V_19 ) ;
break;
}
F_41 ( & V_33 -> V_70 ) ;
return V_221 ;
}
static int F_121 ( const struct V_18 * V_19 ,
char * V_224 , int V_225 )
{
int V_14 ;
V_14 = snprintf ( V_224 , V_225 , L_33 ,
V_19 -> V_23 -> V_6 ,
F_46 ( V_19 ) ) ;
if ( V_14 >= V_225 )
return - V_226 ;
return V_14 ;
}
int F_122 ( struct V_32 * V_33 , char * V_11 , const int V_227 )
{
struct V_18 * V_19 ;
int V_14 , V_228 ;
char * V_224 ;
if ( ! V_33 )
return 0 ;
F_39 ( & V_33 -> V_70 ) ;
V_224 = V_11 ;
V_228 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_121 ( V_19 , V_224 , V_227 - V_228 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_228 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_224 += V_14 ;
V_228 += V_14 ;
}
F_41 ( & V_33 -> V_70 ) ;
return V_228 ;
}
static void * F_123 ( struct V_229 * V_230 , T_3 * V_224 )
{
unsigned int V_231 = ( unsigned int ) * V_224 ;
struct V_32 * V_33 = V_230 -> V_232 ;
F_2 ( L_34 , V_231 ) ;
if ( ! V_231 )
return V_233 ;
return ( V_231 > V_33 -> V_121 ? NULL : & V_33 -> V_122 [ V_231 - 1 ] ) ;
}
static void * F_124 ( struct V_229 * V_230 , void * V_142 , T_3 * V_224 )
{
struct V_87 * V_88 = V_142 ;
struct V_32 * V_33 = V_230 -> V_232 ;
F_2 ( L_35 , * V_224 ) ;
if ( V_142 == V_233 ) {
V_88 = & V_33 -> V_122 [ 0 ] ;
} else {
unsigned int V_231 = ( V_88 - & V_33 -> V_122 [ 0 ] ) ;
if ( V_231 < V_33 -> V_121 - 1 )
V_88 = & V_33 -> V_122 [ V_231 + 1 ] ;
else
V_88 = NULL ;
}
++ * V_224 ;
return V_88 ;
}
static void F_125 ( struct V_229 * V_230 , void * V_142 )
{
}
static int F_126 ( struct V_229 * V_230 , void * V_142 )
{
struct V_87 * V_88 = V_142 ;
if ( V_142 == V_233 ) {
F_127 ( V_230 , L_36 ) ;
return 0 ;
}
F_128 ( V_230 , L_37 ,
V_88 -> V_169 ,
V_88 -> V_100 . V_101 ,
V_88 -> V_100 . V_107 ,
V_88 -> V_100 . V_105 ,
V_88 -> V_100 . V_160 ) ;
return 0 ;
}
int F_129 ( struct V_32 * V_33 , struct V_234 * V_234 )
{
int V_75 ;
V_75 = F_130 ( V_234 , & V_235 ) ;
if ( ! V_75 )
( (struct V_229 * ) V_234 -> V_236 ) -> V_232 = V_33 ;
return V_75 ;
}

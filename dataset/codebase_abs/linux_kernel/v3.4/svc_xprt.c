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
struct V_32 * V_33 = V_19 -> V_35 ;
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
V_77 -> V_104 = V_33 -> V_105 ;
F_58 ( V_77 -> V_104 , & V_19 -> V_106 ) ;
V_87 -> V_99 . V_107 ++ ;
F_59 ( & V_77 -> V_108 ) ;
} else {
F_2 ( L_12 , V_19 ) ;
F_6 ( & V_19 -> V_37 , & V_87 -> V_97 ) ;
V_87 -> V_99 . V_109 ++ ;
}
V_101:
F_39 ( & V_87 -> V_96 ) ;
}
static struct V_18 * F_60 ( struct V_86 * V_87 )
{
struct V_18 * V_19 ;
if ( F_53 ( & V_87 -> V_97 ) )
return NULL ;
V_19 = F_56 ( V_87 -> V_97 . V_102 ,
struct V_18 , V_37 ) ;
F_9 ( & V_19 -> V_37 ) ;
F_2 ( L_13 ,
V_19 , F_61 ( & V_19 -> V_20 . V_110 ) ) ;
return V_19 ;
}
void F_62 ( struct V_18 * V_19 )
{
F_63 ( ! F_13 ( V_42 , & V_19 -> V_26 ) ) ;
F_57 ( V_19 ) ;
F_36 ( V_42 , & V_19 -> V_26 ) ;
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_64 ( struct V_76 * V_77 , int V_111 )
{
V_111 += V_77 -> V_112 . V_113 [ 0 ] . V_114 ;
if ( V_111 < V_77 -> V_104 ) {
struct V_18 * V_19 = V_77 -> V_103 ;
F_65 ( ( V_77 -> V_104 - V_111 ) , & V_19 -> V_106 ) ;
V_77 -> V_104 = V_111 ;
F_49 ( V_19 ) ;
}
}
static void F_66 ( struct V_76 * V_77 )
{
struct V_18 * V_19 = V_77 -> V_103 ;
V_77 -> V_103 -> V_29 -> V_115 ( V_77 ) ;
F_67 ( V_77 -> V_116 ) ;
V_77 -> V_116 = NULL ;
F_68 ( V_77 ) ;
V_77 -> V_112 . V_117 = 0 ;
V_77 -> V_112 . V_118 = 0 ;
if ( ( V_77 -> V_112 . V_14 ) > V_77 -> V_104 )
F_54 ( V_98 L_14 ,
V_77 -> V_104 ,
V_77 -> V_112 . V_14 ) ;
V_77 -> V_112 . V_113 [ 0 ] . V_114 = 0 ;
F_64 ( V_77 , 0 ) ;
V_77 -> V_103 = NULL ;
F_18 ( V_19 ) ;
}
void F_69 ( struct V_32 * V_33 )
{
struct V_76 * V_77 ;
unsigned int V_119 ;
struct V_86 * V_87 ;
for ( V_119 = 0 ; V_119 < V_33 -> V_120 ; V_119 ++ ) {
V_87 = & V_33 -> V_121 [ V_119 ] ;
F_37 ( & V_87 -> V_96 ) ;
if ( ! F_53 ( & V_87 -> V_89 ) ) {
V_77 = F_56 ( V_87 -> V_89 . V_102 ,
struct V_76 ,
V_88 ) ;
F_2 ( L_15 , V_77 ) ;
F_59 ( & V_77 -> V_108 ) ;
}
F_39 ( & V_87 -> V_96 ) ;
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
F_37 ( & V_33 -> V_73 ) ;
if ( ! F_53 ( & V_33 -> V_128 ) ) {
if ( F_73 () ) {
F_54 ( V_129 L_16
L_17 ,
V_33 -> V_130 , V_33 -> V_125 ?
L_18 :
L_19 ) ;
}
V_19 = F_56 ( V_33 -> V_128 . V_131 ,
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
int F_74 ( struct V_76 * V_77 , long V_132 )
{
struct V_18 * V_19 = NULL ;
struct V_32 * V_33 = V_77 -> V_133 ;
struct V_86 * V_87 = V_77 -> V_134 ;
int V_14 , V_119 ;
int V_135 ;
struct V_136 * V_137 ;
F_75 ( V_138 , V_139 ) ;
long V_140 ;
F_2 ( L_20 ,
V_77 , V_132 ) ;
if ( V_77 -> V_103 )
F_54 ( V_98
L_21 ,
V_77 ) ;
if ( F_76 ( & V_77 -> V_108 ) )
F_54 ( V_98
L_22 ,
V_77 ) ;
V_135 = ( V_33 -> V_105 + V_141 ) / V_141 ;
for ( V_119 = 0 ; V_119 < V_135 ; V_119 ++ )
while ( V_77 -> V_142 [ V_119 ] == NULL ) {
struct V_143 * V_144 = F_77 ( V_145 ) ;
if ( ! V_144 ) {
F_78 ( V_146 ) ;
if ( F_79 () || F_80 () ) {
F_78 ( V_147 ) ;
return - V_148 ;
}
F_81 ( F_82 ( 500 ) ) ;
}
V_77 -> V_142 [ V_119 ] = V_144 ;
}
V_77 -> V_142 [ V_119 ++ ] = NULL ;
F_63 ( V_135 >= V_149 ) ;
V_137 = & V_77 -> V_150 ;
V_137 -> V_113 [ 0 ] . V_151 = F_83 ( V_77 -> V_142 [ 0 ] ) ;
V_137 -> V_113 [ 0 ] . V_114 = V_141 ;
V_137 -> V_135 = V_77 -> V_142 + 1 ;
V_137 -> V_118 = 0 ;
V_137 -> V_117 = ( V_135 - 2 ) * V_141 ;
V_137 -> V_14 = ( V_135 - 1 ) * V_141 ;
V_137 -> V_152 [ 0 ] . V_114 = 0 ;
F_84 () ;
F_85 () ;
if ( F_79 () || F_80 () )
return - V_148 ;
V_77 -> V_153 . V_154 = 5 * V_155 ;
F_37 ( & V_87 -> V_96 ) ;
V_19 = F_60 ( V_87 ) ;
if ( V_19 ) {
V_77 -> V_103 = V_19 ;
F_57 ( V_19 ) ;
V_77 -> V_104 = V_33 -> V_105 ;
F_58 ( V_77 -> V_104 , & V_19 -> V_106 ) ;
V_77 -> V_153 . V_154 = 1 * V_155 ;
} else {
F_45 ( V_87 , V_77 ) ;
F_78 ( V_146 ) ;
if ( F_80 () ) {
F_78 ( V_147 ) ;
F_39 ( & V_87 -> V_96 ) ;
return - V_148 ;
}
F_86 ( & V_77 -> V_108 , & V_138 ) ;
F_39 ( & V_87 -> V_96 ) ;
V_140 = F_81 ( V_132 ) ;
F_84 () ;
F_37 ( & V_87 -> V_96 ) ;
F_87 ( & V_77 -> V_108 , & V_138 ) ;
if ( ! V_140 )
V_87 -> V_99 . V_156 ++ ;
V_19 = V_77 -> V_103 ;
if ( ! V_19 ) {
F_46 ( V_87 , V_77 ) ;
F_39 ( & V_87 -> V_96 ) ;
F_2 ( L_23 , V_77 ) ;
if ( F_79 () || F_80 () )
return - V_148 ;
else
return - V_157 ;
}
}
F_39 ( & V_87 -> V_96 ) ;
V_14 = 0 ;
if ( F_13 ( V_91 , & V_19 -> V_26 ) ) {
F_2 ( L_24 ) ;
F_88 ( V_19 ) ;
goto V_9;
}
if ( F_13 ( V_158 , & V_19 -> V_26 ) ) {
struct V_18 * V_159 ;
V_159 = V_19 -> V_29 -> V_160 ( V_19 ) ;
if ( V_159 ) {
F_89 ( V_159 -> V_23 -> V_24 ) ;
F_72 ( V_19 -> V_35 ) ;
F_37 ( & V_33 -> V_73 ) ;
F_24 ( V_72 , & V_159 -> V_26 ) ;
F_38 ( & V_159 -> V_36 , & V_33 -> V_128 ) ;
V_33 -> V_127 ++ ;
if ( V_33 -> V_161 . V_162 == NULL ) {
F_90 ( & V_33 -> V_161 ,
V_163 ,
( unsigned long ) V_33 ) ;
F_91 ( & V_33 -> V_161 ,
V_164 + V_165 * V_155 ) ;
}
F_39 ( & V_33 -> V_73 ) ;
F_62 ( V_159 ) ;
}
} else if ( V_19 -> V_29 -> V_94 ( V_19 ) ) {
F_2 ( L_25 ,
V_77 , V_87 -> V_166 , V_19 ,
F_61 ( & V_19 -> V_20 . V_110 ) ) ;
V_77 -> V_116 = F_92 ( V_19 ) ;
if ( V_77 -> V_116 )
V_14 = F_93 ( V_77 ) ;
else
V_14 = V_19 -> V_29 -> V_167 ( V_77 ) ;
F_2 ( L_26 , V_14 ) ;
}
F_62 ( V_19 ) ;
if ( V_14 == 0 || V_14 == - V_157 )
goto V_9;
F_36 ( V_168 , & V_19 -> V_26 ) ;
V_77 -> V_169 = F_70 ( F_44 ( V_77 ) ) ;
V_77 -> V_153 . V_170 = V_171 ;
if ( V_33 -> V_172 )
V_33 -> V_172 -> V_173 ++ ;
return V_14 ;
V_9:
V_77 -> V_112 . V_14 = 0 ;
F_66 ( V_77 ) ;
return - V_157 ;
}
void F_94 ( struct V_76 * V_77 )
{
F_2 ( L_27 , V_77 -> V_103 ) ;
F_66 ( V_77 ) ;
}
int F_95 ( struct V_76 * V_77 )
{
struct V_18 * V_19 ;
int V_14 ;
struct V_136 * V_174 ;
V_19 = V_77 -> V_103 ;
if ( ! V_19 )
return - V_175 ;
V_77 -> V_103 -> V_29 -> V_115 ( V_77 ) ;
V_174 = & V_77 -> V_112 ;
V_174 -> V_14 = V_174 -> V_113 [ 0 ] . V_114 +
V_174 -> V_117 +
V_174 -> V_152 [ 0 ] . V_114 ;
F_96 ( & V_19 -> V_40 ) ;
if ( F_13 ( V_176 , & V_19 -> V_26 ) )
V_14 = - V_177 ;
else
V_14 = V_19 -> V_29 -> V_178 ( V_77 ) ;
F_97 ( & V_19 -> V_40 ) ;
F_98 ( & V_19 -> V_43 ) ;
F_66 ( V_77 ) ;
if ( V_14 == - V_179 || V_14 == - V_177 || V_14 == - V_157 )
return 0 ;
return V_14 ;
}
static void V_163 ( unsigned long V_180 )
{
struct V_32 * V_33 = (struct V_32 * ) V_180 ;
struct V_18 * V_19 ;
struct V_181 * V_182 , * V_102 ;
F_99 ( V_183 ) ;
F_2 ( L_28 ) ;
if ( ! F_100 ( & V_33 -> V_73 ) ) {
F_2 ( L_29 ) ;
F_91 ( & V_33 -> V_161 , V_164 + V_155 ) ;
return;
}
F_101 (le, next, &serv->sv_tempsocks) {
V_19 = F_56 ( V_182 , struct V_18 , V_36 ) ;
if ( ! F_55 ( V_168 , & V_19 -> V_26 ) )
continue;
if ( F_61 ( & V_19 -> V_20 . V_110 ) > 1 ||
F_13 ( V_42 , & V_19 -> V_26 ) )
continue;
F_57 ( V_19 ) ;
F_102 ( V_182 , & V_183 ) ;
F_24 ( V_91 , & V_19 -> V_26 ) ;
F_24 ( V_184 , & V_19 -> V_26 ) ;
}
F_39 ( & V_33 -> V_73 ) ;
while ( ! F_53 ( & V_183 ) ) {
V_182 = V_183 . V_102 ;
F_9 ( V_182 ) ;
V_19 = F_56 ( V_182 , struct V_18 , V_36 ) ;
F_2 ( L_30 , V_19 ) ;
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
F_91 ( & V_33 -> V_161 , V_164 + V_165 * V_155 ) ;
}
static void F_103 ( struct V_18 * V_19 )
{
struct V_185 * V_186 ;
F_4 ( & V_19 -> V_41 ) ;
while ( ! F_53 ( & V_19 -> V_39 ) ) {
V_186 = F_104 ( & V_19 -> V_39 , struct V_185 , V_187 ) ;
F_47 ( & V_186 -> V_187 ) ;
V_186 -> V_188 ( V_186 ) ;
}
F_7 ( & V_19 -> V_41 ) ;
}
static void F_88 ( struct V_18 * V_19 )
{
struct V_32 * V_33 = V_19 -> V_35 ;
struct V_189 * V_190 ;
if ( F_55 ( V_176 , & V_19 -> V_26 ) )
F_105 () ;
F_2 ( L_31 , V_19 ) ;
V_19 -> V_29 -> V_191 ( V_19 ) ;
F_37 ( & V_33 -> V_73 ) ;
if ( ! F_55 ( V_184 , & V_19 -> V_26 ) )
F_9 ( & V_19 -> V_36 ) ;
F_63 ( ! F_53 ( & V_19 -> V_37 ) ) ;
if ( F_13 ( V_72 , & V_19 -> V_26 ) )
V_33 -> V_127 -- ;
F_39 ( & V_33 -> V_73 ) ;
while ( ( V_190 = F_92 ( V_19 ) ) != NULL )
F_67 ( V_190 ) ;
F_103 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_106 ( struct V_18 * V_19 )
{
F_24 ( V_91 , & V_19 -> V_26 ) ;
if ( F_55 ( V_42 , & V_19 -> V_26 ) )
return;
F_88 ( V_19 ) ;
}
static void F_107 ( struct V_181 * V_192 , struct V_31 * V_31 )
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
struct V_18 * V_193 ;
int V_119 ;
for ( V_119 = 0 ; V_119 < V_33 -> V_120 ; V_119 ++ ) {
V_87 = & V_33 -> V_121 [ V_119 ] ;
F_37 ( & V_87 -> V_96 ) ;
F_109 (xprt, tmp, &pool->sp_sockets, xpt_ready) {
if ( V_19 -> V_27 != V_31 )
continue;
F_9 ( & V_19 -> V_37 ) ;
}
F_39 ( & V_87 -> V_96 ) ;
}
}
static void F_110 ( struct V_181 * V_192 , struct V_31 * V_31 )
{
struct V_18 * V_19 ;
struct V_18 * V_193 ;
F_109 (xprt, tmp, xprt_list, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
F_88 ( V_19 ) ;
}
F_5 (xprt, xprt_list, xpt_list)
F_63 ( V_19 -> V_27 == V_31 ) ;
}
void F_111 ( struct V_32 * V_33 , struct V_31 * V_31 )
{
F_107 ( & V_33 -> V_128 , V_31 ) ;
F_107 ( & V_33 -> V_74 , V_31 ) ;
F_108 ( V_33 , V_31 ) ;
F_110 ( & V_33 -> V_128 , V_31 ) ;
F_110 ( & V_33 -> V_74 , V_31 ) ;
}
static void F_112 ( struct V_194 * V_195 , int V_196 )
{
struct V_189 * V_190 =
F_12 ( V_195 , struct V_189 , V_197 ) ;
struct V_18 * V_19 = V_190 -> V_19 ;
F_4 ( & V_19 -> V_41 ) ;
F_24 ( V_93 , & V_19 -> V_26 ) ;
if ( V_196 || F_13 ( V_176 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_41 ) ;
F_2 ( L_32 ) ;
F_18 ( V_19 ) ;
F_67 ( V_190 ) ;
return;
}
F_2 ( L_33 ) ;
V_190 -> V_19 = NULL ;
F_38 ( & V_190 -> V_197 . V_198 , & V_19 -> V_38 ) ;
F_7 ( & V_19 -> V_41 ) ;
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
static struct V_194 * V_171 ( struct V_199 * V_200 )
{
struct V_76 * V_77 = F_12 ( V_200 , struct V_76 , V_153 ) ;
struct V_189 * V_190 ;
if ( V_77 -> V_150 . V_117 || ! V_77 -> V_201 )
return NULL ;
if ( V_77 -> V_116 ) {
V_190 = V_77 -> V_116 ;
V_77 -> V_116 = NULL ;
} else {
T_1 V_202 ;
T_1 V_203 ;
V_203 = sizeof( struct V_189 ) + V_77 -> V_150 . V_14 ;
V_190 = F_113 ( V_203 , V_145 ) ;
if ( V_190 == NULL )
return NULL ;
V_190 -> V_197 . V_22 = V_77 -> V_133 ;
V_190 -> V_204 = V_77 -> V_205 ;
memcpy ( & V_190 -> V_206 , & V_77 -> V_78 , V_77 -> V_81 ) ;
V_190 -> V_207 = V_77 -> V_81 ;
V_190 -> V_208 = V_77 -> V_82 ;
V_190 -> V_209 = V_77 -> V_150 . V_14 >> 2 ;
V_190 -> V_210 = V_77 -> V_211 ;
V_202 = V_77 -> V_150 . V_14 - V_77 -> V_150 . V_113 [ 0 ] . V_114 ;
memcpy ( V_190 -> args , V_77 -> V_150 . V_113 [ 0 ] . V_151 - V_202 ,
V_190 -> V_209 << 2 ) ;
}
F_57 ( V_77 -> V_103 ) ;
V_190 -> V_19 = V_77 -> V_103 ;
V_77 -> V_212 = true ;
V_190 -> V_197 . V_213 = F_112 ;
return & V_190 -> V_197 ;
}
static int F_93 ( struct V_76 * V_77 )
{
struct V_189 * V_190 = V_77 -> V_116 ;
V_77 -> V_150 . V_113 [ 0 ] . V_151 = V_190 -> args + ( V_190 -> V_210 >> 2 ) ;
V_77 -> V_150 . V_113 [ 0 ] . V_114 = ( V_190 -> V_209 << 2 ) - V_190 -> V_210 ;
V_77 -> V_150 . V_117 = 0 ;
V_77 -> V_150 . V_14 = V_190 -> V_209 << 2 ;
V_77 -> V_205 = V_190 -> V_204 ;
memcpy ( & V_77 -> V_78 , & V_190 -> V_206 , V_190 -> V_207 ) ;
V_77 -> V_81 = V_190 -> V_207 ;
V_77 -> V_211 = V_190 -> V_210 ;
V_77 -> V_82 = V_190 -> V_208 ;
V_77 -> V_214 = V_77 -> V_142 ;
return ( V_190 -> V_209 << 2 ) - V_190 -> V_210 ;
}
static struct V_189 * F_92 ( struct V_18 * V_19 )
{
struct V_189 * V_190 = NULL ;
if ( ! F_13 ( V_93 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_41 ) ;
if ( ! F_53 ( & V_19 -> V_38 ) ) {
V_190 = F_56 ( V_19 -> V_38 . V_102 ,
struct V_189 ,
V_197 . V_198 ) ;
F_9 ( & V_190 -> V_197 . V_198 ) ;
} else
F_36 ( V_93 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_41 ) ;
return V_190 ;
}
struct V_18 * F_114 ( struct V_32 * V_33 , const char * V_6 ,
struct V_31 * V_31 , const T_2 V_215 ,
const unsigned short V_45 )
{
struct V_18 * V_19 ;
struct V_18 * V_216 = NULL ;
if ( V_33 == NULL || V_6 == NULL )
return V_216 ;
F_37 ( & V_33 -> V_73 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( V_19 -> V_27 != V_31 )
continue;
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_215 != V_217 && V_215 != V_19 -> V_83 . V_218 )
continue;
if ( V_45 != 0 && V_45 != F_40 ( V_19 ) )
continue;
V_216 = V_19 ;
F_57 ( V_19 ) ;
break;
}
F_39 ( & V_33 -> V_73 ) ;
return V_216 ;
}
static int F_115 ( const struct V_18 * V_19 ,
char * V_219 , int V_220 )
{
int V_14 ;
V_14 = snprintf ( V_219 , V_220 , L_34 ,
V_19 -> V_23 -> V_6 ,
F_40 ( V_19 ) ) ;
if ( V_14 >= V_220 )
return - V_221 ;
return V_14 ;
}
int F_116 ( struct V_32 * V_33 , char * V_11 , const int V_222 )
{
struct V_18 * V_19 ;
int V_14 , V_223 ;
char * V_219 ;
if ( ! V_33 )
return 0 ;
F_37 ( & V_33 -> V_73 ) ;
V_219 = V_11 ;
V_223 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_115 ( V_19 , V_219 , V_222 - V_223 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_223 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_219 += V_14 ;
V_223 += V_14 ;
}
F_39 ( & V_33 -> V_73 ) ;
return V_223 ;
}
static void * F_117 ( struct V_224 * V_225 , T_3 * V_219 )
{
unsigned int V_226 = ( unsigned int ) * V_219 ;
struct V_32 * V_33 = V_225 -> V_227 ;
F_2 ( L_35 , V_226 ) ;
if ( ! V_226 )
return V_228 ;
return ( V_226 > V_33 -> V_120 ? NULL : & V_33 -> V_121 [ V_226 - 1 ] ) ;
}
static void * F_118 ( struct V_224 * V_225 , void * V_144 , T_3 * V_219 )
{
struct V_86 * V_87 = V_144 ;
struct V_32 * V_33 = V_225 -> V_227 ;
F_2 ( L_36 , * V_219 ) ;
if ( V_144 == V_228 ) {
V_87 = & V_33 -> V_121 [ 0 ] ;
} else {
unsigned int V_226 = ( V_87 - & V_33 -> V_121 [ 0 ] ) ;
if ( V_226 < V_33 -> V_120 - 1 )
V_87 = & V_33 -> V_121 [ V_226 + 1 ] ;
else
V_87 = NULL ;
}
++ * V_219 ;
return V_87 ;
}
static void F_119 ( struct V_224 * V_225 , void * V_144 )
{
}
static int F_120 ( struct V_224 * V_225 , void * V_144 )
{
struct V_86 * V_87 = V_144 ;
if ( V_144 == V_228 ) {
F_121 ( V_225 , L_37 ) ;
return 0 ;
}
F_122 ( V_225 , L_38 ,
V_87 -> V_166 ,
V_87 -> V_99 . V_100 ,
V_87 -> V_99 . V_109 ,
V_87 -> V_99 . V_107 ,
V_87 -> V_99 . V_156 ) ;
return 0 ;
}
int F_123 ( struct V_32 * V_33 , struct V_229 * V_229 )
{
int V_71 ;
V_71 = F_124 ( V_229 , & V_230 ) ;
if ( ! V_71 )
( (struct V_224 * ) V_229 -> V_231 ) -> V_227 = V_33 ;
return V_71 ;
}

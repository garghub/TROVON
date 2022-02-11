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
void F_20 ( struct V_1 * V_2 , struct V_18 * V_19 ,
struct V_31 * V_32 )
{
memset ( V_19 , 0 , sizeof( * V_19 ) ) ;
V_19 -> V_23 = V_2 ;
V_19 -> V_29 = V_2 -> V_33 ;
F_21 ( & V_19 -> V_20 ) ;
V_19 -> V_34 = V_32 ;
F_3 ( & V_19 -> V_35 ) ;
F_3 ( & V_19 -> V_36 ) ;
F_3 ( & V_19 -> V_37 ) ;
F_3 ( & V_19 -> V_38 ) ;
F_22 ( & V_19 -> V_39 ) ;
F_23 ( & V_19 -> V_40 ) ;
F_24 ( V_41 , & V_19 -> V_26 ) ;
F_25 ( & V_19 -> V_42 , L_4 ) ;
V_19 -> V_27 = F_26 ( & V_43 ) ;
}
static struct V_18 * F_27 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_44 * V_44 ,
const int V_45 ,
const unsigned short V_46 ,
int V_47 )
{
struct V_48 sin = {
. V_49 = V_50 ,
. V_51 . V_52 = F_28 ( V_53 ) ,
. V_54 = F_29 ( V_46 ) ,
} ;
#if F_30 ( V_55 ) || F_30 ( V_56 )
struct V_57 V_58 = {
. V_59 = V_60 ,
. V_61 = V_62 ,
. V_63 = F_29 ( V_46 ) ,
} ;
#endif
struct V_64 * V_65 ;
T_1 V_14 ;
switch ( V_45 ) {
case V_66 :
V_65 = (struct V_64 * ) & sin ;
V_14 = sizeof( sin ) ;
break;
#if F_30 ( V_55 ) || F_30 ( V_56 )
case V_67 :
V_65 = (struct V_64 * ) & V_58 ;
V_14 = sizeof( V_58 ) ;
break;
#endif
default:
return F_31 ( - V_68 ) ;
}
return V_2 -> V_33 -> V_69 ( V_32 , V_44 , V_65 , V_14 , V_47 ) ;
}
int F_32 ( struct V_31 * V_32 , const char * V_70 ,
struct V_44 * V_44 , const int V_45 ,
const unsigned short V_46 , int V_47 )
{
struct V_1 * V_2 ;
F_2 ( L_5 , V_70 , V_46 ) ;
F_4 ( & V_8 ) ;
F_5 (xcl, &svc_xprt_class_list, xcl_list) {
struct V_18 * V_71 ;
unsigned short V_72 ;
if ( strcmp ( V_70 , V_2 -> V_6 ) )
continue;
if ( ! F_33 ( V_2 -> V_24 ) )
goto V_73;
F_7 ( & V_8 ) ;
V_71 = F_27 ( V_2 , V_32 , V_44 , V_45 , V_46 , V_47 ) ;
if ( F_34 ( V_71 ) ) {
F_17 ( V_2 -> V_24 ) ;
return F_35 ( V_71 ) ;
}
F_36 ( V_74 , & V_71 -> V_26 ) ;
F_37 ( & V_32 -> V_75 ) ;
F_38 ( & V_71 -> V_35 , & V_32 -> V_76 ) ;
F_39 ( & V_32 -> V_75 ) ;
V_72 = F_40 ( V_71 ) ;
F_36 ( V_41 , & V_71 -> V_26 ) ;
return V_72 ;
}
V_73:
F_7 ( & V_8 ) ;
F_2 ( L_6 , V_70 ) ;
return - V_77 ;
}
void F_41 ( struct V_78 * V_79 , struct V_18 * V_19 )
{
memcpy ( & V_79 -> V_80 , & V_19 -> V_81 , V_19 -> V_82 ) ;
V_79 -> V_83 = V_19 -> V_82 ;
memcpy ( & V_79 -> V_84 , & V_19 -> V_85 , V_19 -> V_86 ) ;
V_79 -> V_87 = V_19 -> V_86 ;
}
char * F_42 ( struct V_78 * V_79 , char * V_11 , T_1 V_14 )
{
return F_43 ( F_44 ( V_79 ) , V_11 , V_14 ) ;
}
static void F_45 ( struct V_88 * V_89 , struct V_78 * V_79 )
{
F_38 ( & V_79 -> V_90 , & V_89 -> V_91 ) ;
}
static void F_46 ( struct V_88 * V_89 , struct V_78 * V_79 )
{
F_47 ( & V_79 -> V_90 ) ;
}
static bool F_48 ( struct V_18 * V_19 )
{
if ( V_19 -> V_26 & ( ( 1 << V_92 ) | ( 1 << V_93 ) ) )
return true ;
if ( V_19 -> V_26 & ( ( 1 << V_94 ) | ( 1 << V_95 ) ) )
return V_19 -> V_29 -> V_96 ( V_19 ) ;
return false ;
}
void F_49 ( struct V_18 * V_19 )
{
struct V_31 * V_32 = V_19 -> V_34 ;
struct V_88 * V_89 ;
struct V_78 * V_79 ;
int V_97 ;
if ( ! F_48 ( V_19 ) )
return;
V_97 = F_50 () ;
V_89 = F_51 ( V_19 -> V_34 , V_97 ) ;
F_52 () ;
F_37 ( & V_89 -> V_98 ) ;
if ( ! F_53 ( & V_89 -> V_91 ) &&
! F_53 ( & V_89 -> V_99 ) )
F_54 ( V_100
L_7
L_8 ) ;
V_89 -> V_101 . V_102 ++ ;
if ( F_55 ( V_41 , & V_19 -> V_26 ) ) {
F_2 ( L_9 , V_19 ) ;
goto V_103;
}
if ( ! F_53 ( & V_89 -> V_91 ) ) {
V_79 = F_56 ( V_89 -> V_91 . V_104 ,
struct V_78 ,
V_90 ) ;
F_2 ( L_10 ,
V_19 , V_79 ) ;
F_46 ( V_89 , V_79 ) ;
if ( V_79 -> V_105 )
F_54 ( V_100
L_11 ,
V_79 , V_79 -> V_105 ) ;
V_79 -> V_105 = V_19 ;
F_57 ( V_19 ) ;
V_79 -> V_106 = V_32 -> V_107 ;
F_58 ( V_79 -> V_106 , & V_19 -> V_108 ) ;
V_89 -> V_101 . V_109 ++ ;
F_59 ( & V_79 -> V_110 ) ;
} else {
F_2 ( L_12 , V_19 ) ;
F_6 ( & V_19 -> V_36 , & V_89 -> V_99 ) ;
V_89 -> V_101 . V_111 ++ ;
}
V_103:
F_39 ( & V_89 -> V_98 ) ;
}
static struct V_18 * F_60 ( struct V_88 * V_89 )
{
struct V_18 * V_19 ;
if ( F_53 ( & V_89 -> V_99 ) )
return NULL ;
V_19 = F_56 ( V_89 -> V_99 . V_104 ,
struct V_18 , V_36 ) ;
F_9 ( & V_19 -> V_36 ) ;
F_2 ( L_13 ,
V_19 , F_61 ( & V_19 -> V_20 . V_112 ) ) ;
return V_19 ;
}
void F_62 ( struct V_18 * V_19 )
{
F_63 ( ! F_13 ( V_41 , & V_19 -> V_26 ) ) ;
F_57 ( V_19 ) ;
F_36 ( V_41 , & V_19 -> V_26 ) ;
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_64 ( struct V_78 * V_79 , int V_113 )
{
V_113 += V_79 -> V_114 . V_115 [ 0 ] . V_116 ;
if ( V_113 < V_79 -> V_106 ) {
struct V_18 * V_19 = V_79 -> V_105 ;
F_65 ( ( V_79 -> V_106 - V_113 ) , & V_19 -> V_108 ) ;
V_79 -> V_106 = V_113 ;
F_49 ( V_19 ) ;
}
}
static void F_66 ( struct V_78 * V_79 )
{
struct V_18 * V_19 = V_79 -> V_105 ;
V_79 -> V_105 -> V_29 -> V_117 ( V_79 ) ;
F_67 ( V_79 -> V_118 ) ;
V_79 -> V_118 = NULL ;
F_68 ( V_79 ) ;
V_79 -> V_114 . V_119 = 0 ;
V_79 -> V_114 . V_120 = 0 ;
if ( ( V_79 -> V_114 . V_14 ) > V_79 -> V_106 )
F_54 ( V_100 L_14 ,
V_79 -> V_106 ,
V_79 -> V_114 . V_14 ) ;
V_79 -> V_114 . V_115 [ 0 ] . V_116 = 0 ;
F_64 ( V_79 , 0 ) ;
V_79 -> V_105 = NULL ;
F_18 ( V_19 ) ;
}
void F_69 ( struct V_31 * V_32 )
{
struct V_78 * V_79 ;
unsigned int V_121 ;
struct V_88 * V_89 ;
for ( V_121 = 0 ; V_121 < V_32 -> V_122 ; V_121 ++ ) {
V_89 = & V_32 -> V_123 [ V_121 ] ;
F_37 ( & V_89 -> V_98 ) ;
if ( ! F_53 ( & V_89 -> V_91 ) ) {
V_79 = F_56 ( V_89 -> V_91 . V_104 ,
struct V_78 ,
V_90 ) ;
F_2 ( L_15 , V_79 ) ;
F_59 ( & V_79 -> V_110 ) ;
}
F_39 ( & V_89 -> V_98 ) ;
}
}
int F_70 ( struct V_64 * sin )
{
switch ( sin -> V_124 ) {
case V_50 :
return F_71 ( ( (struct V_48 * ) sin ) -> V_54 )
< V_125 ;
case V_60 :
return F_71 ( ( (struct V_57 * ) sin ) -> V_63 )
< V_125 ;
default:
return 0 ;
}
}
static void F_72 ( struct V_31 * V_32 )
{
unsigned int V_126 = V_32 -> V_127 ? V_32 -> V_127 :
( V_32 -> V_128 + 3 ) * 20 ;
if ( V_32 -> V_129 > V_126 ) {
struct V_18 * V_19 = NULL ;
F_37 ( & V_32 -> V_75 ) ;
if ( ! F_53 ( & V_32 -> V_130 ) ) {
if ( F_73 () ) {
F_54 ( V_131 L_16
L_17 ,
V_32 -> V_132 , V_32 -> V_127 ?
L_18 :
L_19 ) ;
}
V_19 = F_56 ( V_32 -> V_130 . V_133 ,
struct V_18 ,
V_35 ) ;
F_24 ( V_93 , & V_19 -> V_26 ) ;
F_57 ( V_19 ) ;
}
F_39 ( & V_32 -> V_75 ) ;
if ( V_19 ) {
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
}
}
int F_74 ( struct V_78 * V_79 , long V_134 )
{
struct V_18 * V_19 = NULL ;
struct V_31 * V_32 = V_79 -> V_135 ;
struct V_88 * V_89 = V_79 -> V_136 ;
int V_14 , V_121 ;
int V_137 ;
struct V_138 * V_139 ;
F_75 ( V_140 , V_141 ) ;
long V_142 ;
F_2 ( L_20 ,
V_79 , V_134 ) ;
if ( V_79 -> V_105 )
F_54 ( V_100
L_21 ,
V_79 ) ;
if ( F_76 ( & V_79 -> V_110 ) )
F_54 ( V_100
L_22 ,
V_79 ) ;
V_137 = ( V_32 -> V_107 + V_143 ) / V_143 ;
for ( V_121 = 0 ; V_121 < V_137 ; V_121 ++ )
while ( V_79 -> V_144 [ V_121 ] == NULL ) {
struct V_145 * V_146 = F_77 ( V_147 ) ;
if ( ! V_146 ) {
F_78 ( V_148 ) ;
if ( F_79 () || F_80 () ) {
F_78 ( V_149 ) ;
return - V_150 ;
}
F_81 ( F_82 ( 500 ) ) ;
}
V_79 -> V_144 [ V_121 ] = V_146 ;
}
V_79 -> V_144 [ V_121 ++ ] = NULL ;
F_63 ( V_137 >= V_151 ) ;
V_139 = & V_79 -> V_152 ;
V_139 -> V_115 [ 0 ] . V_153 = F_83 ( V_79 -> V_144 [ 0 ] ) ;
V_139 -> V_115 [ 0 ] . V_116 = V_143 ;
V_139 -> V_137 = V_79 -> V_144 + 1 ;
V_139 -> V_120 = 0 ;
V_139 -> V_119 = ( V_137 - 2 ) * V_143 ;
V_139 -> V_14 = ( V_137 - 1 ) * V_143 ;
V_139 -> V_154 [ 0 ] . V_116 = 0 ;
F_84 () ;
F_85 () ;
if ( F_79 () || F_80 () )
return - V_150 ;
V_79 -> V_155 . V_156 = 5 * V_157 ;
F_37 ( & V_89 -> V_98 ) ;
V_19 = F_60 ( V_89 ) ;
if ( V_19 ) {
V_79 -> V_105 = V_19 ;
F_57 ( V_19 ) ;
V_79 -> V_106 = V_32 -> V_107 ;
F_58 ( V_79 -> V_106 , & V_19 -> V_108 ) ;
V_79 -> V_155 . V_156 = 1 * V_157 ;
} else {
F_45 ( V_89 , V_79 ) ;
F_78 ( V_148 ) ;
if ( F_80 () ) {
F_78 ( V_149 ) ;
F_39 ( & V_89 -> V_98 ) ;
return - V_150 ;
}
F_86 ( & V_79 -> V_110 , & V_140 ) ;
F_39 ( & V_89 -> V_98 ) ;
V_142 = F_81 ( V_134 ) ;
F_84 () ;
F_37 ( & V_89 -> V_98 ) ;
F_87 ( & V_79 -> V_110 , & V_140 ) ;
if ( ! V_142 )
V_89 -> V_101 . V_158 ++ ;
V_19 = V_79 -> V_105 ;
if ( ! V_19 ) {
F_46 ( V_89 , V_79 ) ;
F_39 ( & V_89 -> V_98 ) ;
F_2 ( L_23 , V_79 ) ;
if ( F_79 () || F_80 () )
return - V_150 ;
else
return - V_159 ;
}
}
F_39 ( & V_89 -> V_98 ) ;
V_14 = 0 ;
if ( F_13 ( V_93 , & V_19 -> V_26 ) ) {
F_2 ( L_24 ) ;
F_88 ( V_19 ) ;
goto V_9;
}
if ( F_13 ( V_160 , & V_19 -> V_26 ) ) {
struct V_18 * V_161 ;
V_161 = V_19 -> V_29 -> V_162 ( V_19 ) ;
if ( V_161 ) {
F_89 ( V_161 -> V_23 -> V_24 ) ;
F_72 ( V_19 -> V_34 ) ;
F_37 ( & V_32 -> V_75 ) ;
F_24 ( V_74 , & V_161 -> V_26 ) ;
F_38 ( & V_161 -> V_35 , & V_32 -> V_130 ) ;
V_32 -> V_129 ++ ;
if ( V_32 -> V_163 . V_164 == NULL ) {
F_90 ( & V_32 -> V_163 ,
V_165 ,
( unsigned long ) V_32 ) ;
F_91 ( & V_32 -> V_163 ,
V_166 + V_167 * V_157 ) ;
}
F_39 ( & V_32 -> V_75 ) ;
F_62 ( V_161 ) ;
}
} else if ( V_19 -> V_29 -> V_96 ( V_19 ) ) {
F_2 ( L_25 ,
V_79 , V_89 -> V_168 , V_19 ,
F_61 ( & V_19 -> V_20 . V_112 ) ) ;
V_79 -> V_118 = F_92 ( V_19 ) ;
if ( V_79 -> V_118 )
V_14 = F_93 ( V_79 ) ;
else
V_14 = V_19 -> V_29 -> V_169 ( V_79 ) ;
F_2 ( L_26 , V_14 ) ;
}
F_62 ( V_19 ) ;
if ( V_14 == 0 || V_14 == - V_159 )
goto V_9;
F_36 ( V_170 , & V_19 -> V_26 ) ;
V_79 -> V_171 = F_70 ( F_44 ( V_79 ) ) ;
V_79 -> V_155 . V_172 = V_173 ;
if ( V_32 -> V_174 )
V_32 -> V_174 -> V_175 ++ ;
return V_14 ;
V_9:
V_79 -> V_114 . V_14 = 0 ;
F_66 ( V_79 ) ;
return - V_159 ;
}
void F_94 ( struct V_78 * V_79 )
{
F_2 ( L_27 , V_79 -> V_105 ) ;
F_66 ( V_79 ) ;
}
int F_95 ( struct V_78 * V_79 )
{
struct V_18 * V_19 ;
int V_14 ;
struct V_138 * V_176 ;
V_19 = V_79 -> V_105 ;
if ( ! V_19 )
return - V_177 ;
V_79 -> V_105 -> V_29 -> V_117 ( V_79 ) ;
V_176 = & V_79 -> V_114 ;
V_176 -> V_14 = V_176 -> V_115 [ 0 ] . V_116 +
V_176 -> V_119 +
V_176 -> V_154 [ 0 ] . V_116 ;
F_96 ( & V_19 -> V_39 ) ;
if ( F_13 ( V_178 , & V_19 -> V_26 ) )
V_14 = - V_179 ;
else
V_14 = V_19 -> V_29 -> V_180 ( V_79 ) ;
F_97 ( & V_19 -> V_39 ) ;
F_98 ( & V_19 -> V_42 ) ;
F_66 ( V_79 ) ;
if ( V_14 == - V_181 || V_14 == - V_179 || V_14 == - V_159 )
return 0 ;
return V_14 ;
}
static void V_165 ( unsigned long V_182 )
{
struct V_31 * V_32 = (struct V_31 * ) V_182 ;
struct V_18 * V_19 ;
struct V_183 * V_184 , * V_104 ;
F_99 ( V_185 ) ;
F_2 ( L_28 ) ;
if ( ! F_100 ( & V_32 -> V_75 ) ) {
F_2 ( L_29 ) ;
F_91 ( & V_32 -> V_163 , V_166 + V_157 ) ;
return;
}
F_101 (le, next, &serv->sv_tempsocks) {
V_19 = F_56 ( V_184 , struct V_18 , V_35 ) ;
if ( ! F_55 ( V_170 , & V_19 -> V_26 ) )
continue;
if ( F_61 ( & V_19 -> V_20 . V_112 ) > 1 ||
F_13 ( V_41 , & V_19 -> V_26 ) )
continue;
F_57 ( V_19 ) ;
F_102 ( V_184 , & V_185 ) ;
F_24 ( V_93 , & V_19 -> V_26 ) ;
F_24 ( V_186 , & V_19 -> V_26 ) ;
}
F_39 ( & V_32 -> V_75 ) ;
while ( ! F_53 ( & V_185 ) ) {
V_184 = V_185 . V_104 ;
F_9 ( V_184 ) ;
V_19 = F_56 ( V_184 , struct V_18 , V_35 ) ;
F_2 ( L_30 , V_19 ) ;
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
F_91 ( & V_32 -> V_163 , V_166 + V_167 * V_157 ) ;
}
static void F_103 ( struct V_18 * V_19 )
{
struct V_187 * V_188 ;
F_4 ( & V_19 -> V_40 ) ;
while ( ! F_53 ( & V_19 -> V_38 ) ) {
V_188 = F_104 ( & V_19 -> V_38 , struct V_187 , V_189 ) ;
F_47 ( & V_188 -> V_189 ) ;
V_188 -> V_190 ( V_188 ) ;
}
F_7 ( & V_19 -> V_40 ) ;
}
void F_88 ( struct V_18 * V_19 )
{
struct V_31 * V_32 = V_19 -> V_34 ;
struct V_191 * V_192 ;
if ( F_55 ( V_178 , & V_19 -> V_26 ) )
F_105 () ;
F_2 ( L_31 , V_19 ) ;
V_19 -> V_29 -> V_193 ( V_19 ) ;
F_37 ( & V_32 -> V_75 ) ;
if ( ! F_55 ( V_186 , & V_19 -> V_26 ) )
F_9 ( & V_19 -> V_35 ) ;
F_9 ( & V_19 -> V_36 ) ;
if ( F_13 ( V_74 , & V_19 -> V_26 ) )
V_32 -> V_129 -- ;
F_39 ( & V_32 -> V_75 ) ;
while ( ( V_192 = F_92 ( V_19 ) ) != NULL )
F_67 ( V_192 ) ;
F_103 ( V_19 ) ;
F_18 ( V_19 ) ;
}
void F_106 ( struct V_18 * V_19 )
{
F_24 ( V_93 , & V_19 -> V_26 ) ;
if ( F_55 ( V_41 , & V_19 -> V_26 ) )
return;
F_88 ( V_19 ) ;
}
void F_107 ( struct V_183 * V_194 )
{
struct V_18 * V_19 ;
struct V_18 * V_195 ;
F_108 (xprt, tmp, xprt_list, xpt_list) {
F_24 ( V_93 , & V_19 -> V_26 ) ;
F_88 ( V_19 ) ;
}
}
static void F_109 ( struct V_196 * V_197 , int V_198 )
{
struct V_191 * V_192 =
F_12 ( V_197 , struct V_191 , V_199 ) ;
struct V_18 * V_19 = V_192 -> V_19 ;
F_4 ( & V_19 -> V_40 ) ;
F_24 ( V_95 , & V_19 -> V_26 ) ;
if ( V_198 || F_13 ( V_178 , & V_19 -> V_26 ) ) {
F_7 ( & V_19 -> V_40 ) ;
F_2 ( L_32 ) ;
F_18 ( V_19 ) ;
F_67 ( V_192 ) ;
return;
}
F_2 ( L_33 ) ;
V_192 -> V_19 = NULL ;
F_38 ( & V_192 -> V_199 . V_200 , & V_19 -> V_37 ) ;
F_7 ( & V_19 -> V_40 ) ;
F_49 ( V_19 ) ;
F_18 ( V_19 ) ;
}
static struct V_196 * V_173 ( struct V_201 * V_202 )
{
struct V_78 * V_79 = F_12 ( V_202 , struct V_78 , V_155 ) ;
struct V_191 * V_192 ;
if ( V_79 -> V_152 . V_119 || ! V_79 -> V_203 )
return NULL ;
if ( V_79 -> V_118 ) {
V_192 = V_79 -> V_118 ;
V_79 -> V_118 = NULL ;
} else {
T_1 V_204 ;
T_1 V_205 ;
V_205 = sizeof( struct V_191 ) + V_79 -> V_152 . V_14 ;
V_192 = F_110 ( V_205 , V_147 ) ;
if ( V_192 == NULL )
return NULL ;
V_192 -> V_199 . V_22 = V_79 -> V_135 ;
V_192 -> V_206 = V_79 -> V_207 ;
memcpy ( & V_192 -> V_208 , & V_79 -> V_80 , V_79 -> V_83 ) ;
V_192 -> V_209 = V_79 -> V_83 ;
V_192 -> V_210 = V_79 -> V_84 ;
V_192 -> V_211 = V_79 -> V_152 . V_14 >> 2 ;
V_192 -> V_212 = V_79 -> V_213 ;
V_204 = V_79 -> V_152 . V_14 - V_79 -> V_152 . V_115 [ 0 ] . V_116 ;
memcpy ( V_192 -> args , V_79 -> V_152 . V_115 [ 0 ] . V_153 - V_204 ,
V_192 -> V_211 << 2 ) ;
}
F_57 ( V_79 -> V_105 ) ;
V_192 -> V_19 = V_79 -> V_105 ;
V_79 -> V_214 = true ;
V_192 -> V_199 . V_215 = F_109 ;
return & V_192 -> V_199 ;
}
static int F_93 ( struct V_78 * V_79 )
{
struct V_191 * V_192 = V_79 -> V_118 ;
V_79 -> V_152 . V_115 [ 0 ] . V_153 = V_192 -> args + ( V_192 -> V_212 >> 2 ) ;
V_79 -> V_152 . V_115 [ 0 ] . V_116 = ( V_192 -> V_211 << 2 ) - V_192 -> V_212 ;
V_79 -> V_152 . V_119 = 0 ;
V_79 -> V_152 . V_14 = V_192 -> V_211 << 2 ;
V_79 -> V_207 = V_192 -> V_206 ;
memcpy ( & V_79 -> V_80 , & V_192 -> V_208 , V_192 -> V_209 ) ;
V_79 -> V_83 = V_192 -> V_209 ;
V_79 -> V_213 = V_192 -> V_212 ;
V_79 -> V_84 = V_192 -> V_210 ;
V_79 -> V_216 = V_79 -> V_144 ;
return ( V_192 -> V_211 << 2 ) - V_192 -> V_212 ;
}
static struct V_191 * F_92 ( struct V_18 * V_19 )
{
struct V_191 * V_192 = NULL ;
if ( ! F_13 ( V_95 , & V_19 -> V_26 ) )
return NULL ;
F_4 ( & V_19 -> V_40 ) ;
if ( ! F_53 ( & V_19 -> V_37 ) ) {
V_192 = F_56 ( V_19 -> V_37 . V_104 ,
struct V_191 ,
V_199 . V_200 ) ;
F_9 ( & V_192 -> V_199 . V_200 ) ;
} else
F_36 ( V_95 , & V_19 -> V_26 ) ;
F_7 ( & V_19 -> V_40 ) ;
return V_192 ;
}
struct V_18 * F_111 ( struct V_31 * V_32 , const char * V_6 ,
const T_2 V_217 , const unsigned short V_46 )
{
struct V_18 * V_19 ;
struct V_18 * V_218 = NULL ;
if ( V_32 == NULL || V_6 == NULL )
return V_218 ;
F_37 ( & V_32 -> V_75 ) ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
if ( strcmp ( V_19 -> V_23 -> V_6 , V_6 ) )
continue;
if ( V_217 != V_219 && V_217 != V_19 -> V_85 . V_220 )
continue;
if ( V_46 != 0 && V_46 != F_40 ( V_19 ) )
continue;
V_218 = V_19 ;
F_57 ( V_19 ) ;
break;
}
F_39 ( & V_32 -> V_75 ) ;
return V_218 ;
}
static int F_112 ( const struct V_18 * V_19 ,
char * V_221 , int V_222 )
{
int V_14 ;
V_14 = snprintf ( V_221 , V_222 , L_34 ,
V_19 -> V_23 -> V_6 ,
F_40 ( V_19 ) ) ;
if ( V_14 >= V_222 )
return - V_223 ;
return V_14 ;
}
int F_113 ( struct V_31 * V_32 , char * V_11 , const int V_224 )
{
struct V_18 * V_19 ;
int V_14 , V_225 ;
char * V_221 ;
if ( ! V_32 )
return 0 ;
F_37 ( & V_32 -> V_75 ) ;
V_221 = V_11 ;
V_225 = 0 ;
F_5 (xprt, &serv->sv_permsocks, xpt_list) {
V_14 = F_112 ( V_19 , V_221 , V_224 - V_225 ) ;
if ( V_14 < 0 ) {
* V_11 = '\0' ;
V_225 = V_14 ;
}
if ( V_14 <= 0 )
break;
V_221 += V_14 ;
V_225 += V_14 ;
}
F_39 ( & V_32 -> V_75 ) ;
return V_225 ;
}
static void * F_114 ( struct V_226 * V_227 , T_3 * V_221 )
{
unsigned int V_228 = ( unsigned int ) * V_221 ;
struct V_31 * V_32 = V_227 -> V_229 ;
F_2 ( L_35 , V_228 ) ;
if ( ! V_228 )
return V_230 ;
return ( V_228 > V_32 -> V_122 ? NULL : & V_32 -> V_123 [ V_228 - 1 ] ) ;
}
static void * F_115 ( struct V_226 * V_227 , void * V_146 , T_3 * V_221 )
{
struct V_88 * V_89 = V_146 ;
struct V_31 * V_32 = V_227 -> V_229 ;
F_2 ( L_36 , * V_221 ) ;
if ( V_146 == V_230 ) {
V_89 = & V_32 -> V_123 [ 0 ] ;
} else {
unsigned int V_228 = ( V_89 - & V_32 -> V_123 [ 0 ] ) ;
if ( V_228 < V_32 -> V_122 - 1 )
V_89 = & V_32 -> V_123 [ V_228 + 1 ] ;
else
V_89 = NULL ;
}
++ * V_221 ;
return V_89 ;
}
static void F_116 ( struct V_226 * V_227 , void * V_146 )
{
}
static int F_117 ( struct V_226 * V_227 , void * V_146 )
{
struct V_88 * V_89 = V_146 ;
if ( V_146 == V_230 ) {
F_118 ( V_227 , L_37 ) ;
return 0 ;
}
F_119 ( V_227 , L_38 ,
V_89 -> V_168 ,
V_89 -> V_101 . V_102 ,
V_89 -> V_101 . V_111 ,
V_89 -> V_101 . V_109 ,
V_89 -> V_101 . V_158 ) ;
return 0 ;
}
int F_120 ( struct V_31 * V_32 , struct V_231 * V_231 )
{
int V_73 ;
V_73 = F_121 ( V_231 , & V_232 ) ;
if ( ! V_73 )
( (struct V_226 * ) V_231 -> V_233 ) -> V_229 = V_32 ;
return V_73 ;
}

static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 V_5 ;
if ( ! strcmp ( V_2 -> V_6 , L_1 ) ) {
V_2 -> V_7 = true ;
V_2 -> V_8 = V_9 ;
if ( F_2 ( V_2 , V_2 -> V_8 ) < 0 )
F_3 ( L_2 ) ;
return 0 ;
}
V_2 -> V_8 = F_4 ( V_2 -> V_6 , V_10 ) ;
if ( V_2 -> V_8 < 0 ) {
int V_11 = V_12 ;
F_3 ( L_3 , V_2 -> V_6 , strerror ( V_11 ) ) ;
if ( V_11 == V_13 && ! strcmp ( V_2 -> V_6 , L_4 ) )
F_3 ( L_5 ) ;
F_3 ( L_6 ) ;
return - V_12 ;
}
if ( F_5 ( V_2 -> V_8 , & V_5 ) < 0 )
goto V_14;
if ( ! V_3 && V_5 . V_15 && ( V_5 . V_15 != F_6 () ) ) {
F_3 ( L_7 ,
V_2 -> V_6 ) ;
goto V_14;
}
if ( ! V_5 . V_16 ) {
F_7 ( L_8 ,
V_2 -> V_6 ) ;
goto V_14;
}
if ( F_2 ( V_2 , V_2 -> V_8 ) < 0 ) {
F_3 ( L_2 ) ;
goto V_14;
}
if ( ! F_8 ( V_2 -> V_17 ) ) {
F_3 ( L_9 ) ;
goto V_14;
}
if ( ! F_9 ( V_2 -> V_17 ) ) {
F_3 ( L_10 ) ;
goto V_14;
}
V_2 -> V_18 = V_5 . V_16 ;
return 0 ;
V_14:
F_10 ( V_2 -> V_8 ) ;
V_2 -> V_8 = - 1 ;
return - 1 ;
}
void F_11 ( struct V_1 * V_19 )
{
T_1 V_20 = F_12 ( V_19 -> V_17 ) ;
V_19 -> V_21 . V_20 = V_20 ;
F_13 ( & V_19 -> V_22 , V_20 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
int V_23 = F_15 ( & V_2 -> V_21 ) ;
if ( V_23 >= 0 )
V_23 = F_16 ( & V_2 -> V_22 ) ;
return V_23 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_21 ) ;
F_19 ( & V_2 -> V_22 ) ;
}
struct V_1 * F_20 ( const char * V_6 , int V_24 ,
bool V_3 , bool V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_4 V_28 ;
T_2 V_29 ;
if ( ! V_6 || ! strlen ( V_6 ) ) {
if ( ! F_5 ( V_9 , & V_28 ) && F_21 ( V_28 . V_30 ) )
V_6 = L_1 ;
else
V_6 = L_4 ;
}
V_29 = strlen ( V_6 ) ;
V_2 = F_22 ( sizeof( * V_2 ) + V_29 ) ;
if ( V_2 == NULL )
goto V_31;
memcpy ( V_2 -> V_6 , V_6 , V_29 ) ;
#if V_32 == 64
V_2 -> V_33 = V_34 ;
#else
V_2 -> V_33 = 32 * 1024 * 1024ULL ;
#endif
V_2 -> V_22 = V_35 ;
V_2 -> V_25 = V_25 ;
F_23 ( & V_2 -> V_36 . V_37 ) ;
F_23 ( & V_2 -> V_36 . V_38 ) ;
F_23 ( & V_2 -> V_36 . V_39 ) ;
F_24 ( & V_2 -> V_21 , L_11 , V_40 ) ;
F_25 ( & V_2 -> V_41 ) ;
if ( V_24 == V_10 ) {
if ( F_1 ( V_2 , V_3 ) < 0 )
goto V_42;
F_11 ( V_2 ) ;
} else if ( V_24 == V_43 ) {
if ( F_14 ( V_2 ) < 0 )
goto V_42;
}
if ( V_27 && V_27 -> V_44 &&
V_27 -> V_36 && ! F_26 ( V_2 -> V_17 ) ) {
F_27 ( L_12 ) ;
V_27 -> V_36 = false ;
}
V_31:
return V_2 ;
V_42:
F_28 ( V_2 ) ;
return NULL ;
}
static void F_29 ( struct V_45 * V_45 )
{
struct V_46 * V_47 , * V_48 ;
F_30 (t, n, &machine->dead_threads, node) {
F_31 ( & V_48 -> V_49 ) ;
F_32 ( V_48 ) ;
}
}
static void F_33 ( struct V_1 * V_19 )
{
F_29 ( & V_19 -> V_21 ) ;
}
static void F_34 ( struct V_45 * V_2 )
{
struct V_50 * V_51 = F_35 ( & V_2 -> V_52 ) ;
while ( V_51 ) {
struct V_46 * V_48 = F_36 ( V_51 , struct V_46 , V_50 ) ;
F_37 ( & V_48 -> V_50 , & V_2 -> V_52 ) ;
V_51 = F_38 ( V_51 ) ;
F_32 ( V_48 ) ;
}
}
static void F_39 ( struct V_1 * V_19 )
{
F_34 ( & V_19 -> V_21 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
F_33 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( & V_2 -> V_21 ) ;
F_10 ( V_2 -> V_8 ) ;
free ( V_2 ) ;
F_41 () ;
}
void F_42 ( struct V_45 * V_2 , struct V_46 * V_53 )
{
V_2 -> V_54 = NULL ;
F_37 ( & V_53 -> V_50 , & V_2 -> V_52 ) ;
F_43 ( & V_53 -> V_49 , & V_2 -> V_55 ) ;
}
static bool F_44 ( struct V_56 * V_57 )
{
if ( V_57 -> V_58 && ! regexec ( & V_59 , V_57 -> V_58 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_45 ( struct V_45 * V_2 , struct V_46 * V_46 ,
struct V_60 * V_61 ,
T_3 V_62 )
{
struct V_63 V_64 ;
T_2 V_65 ;
T_4 V_66 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ ) {
V_66 = V_68 [ V_65 ] ;
F_46 ( V_46 , V_2 , V_66 , V_69 ,
V_62 , & V_64 , NULL ) ;
if ( V_64 . V_57 )
goto V_70;
}
V_70:
V_61 -> V_71 = V_62 ;
V_61 -> V_72 = V_64 . V_71 ;
V_61 -> V_57 = V_64 . V_57 ;
V_61 -> V_73 = V_64 . V_73 ;
}
struct V_74 * F_47 ( struct V_45 * V_2 ,
struct V_46 * V_75 ,
struct V_76 * V_77 )
{
struct V_74 * V_78 ;
unsigned int V_65 ;
V_78 = calloc ( V_77 -> V_79 , sizeof( struct V_74 ) ) ;
if ( ! V_78 )
return NULL ;
for ( V_65 = 0 ; V_65 < V_77 -> V_79 ; V_65 ++ ) {
F_45 ( V_2 , V_75 , & V_78 [ V_65 ] . V_80 , V_77 -> V_81 [ V_65 ] . V_80 ) ;
F_45 ( V_2 , V_75 , & V_78 [ V_65 ] . V_82 , V_77 -> V_81 [ V_65 ] . V_82 ) ;
V_78 [ V_65 ] . V_83 = V_77 -> V_81 [ V_65 ] . V_83 ;
}
return V_78 ;
}
static int F_48 ( struct V_45 * V_45 ,
struct V_46 * V_46 ,
struct V_84 * V_85 ,
struct V_56 * * V_86 )
{
T_4 V_87 = V_88 ;
unsigned int V_65 ;
int V_11 ;
F_49 ( & V_89 ) ;
if ( V_85 -> V_79 > V_90 ) {
F_50 ( L_13 ) ;
return 0 ;
}
for ( V_65 = 0 ; V_65 < V_85 -> V_79 ; V_65 ++ ) {
T_3 V_62 ;
struct V_63 V_64 ;
if ( V_91 . V_92 == V_93 )
V_62 = V_85 -> V_94 [ V_65 ] ;
else
V_62 = V_85 -> V_94 [ V_85 -> V_79 - V_65 - 1 ] ;
if ( V_62 >= V_95 ) {
switch ( V_62 ) {
case V_96 :
V_87 = V_97 ;
break;
case V_98 :
V_87 = V_99 ;
break;
case V_100 :
V_87 = V_88 ;
break;
default:
F_51 ( L_14
L_15 V_101 L_6 , ( V_102 ) V_62 ) ;
F_49 ( & V_89 ) ;
return 0 ;
}
continue;
}
V_64 . V_103 = false ;
F_46 ( V_46 , V_45 , V_87 ,
V_69 , V_62 , & V_64 , NULL ) ;
if ( V_64 . V_57 != NULL ) {
if ( V_104 && ! * V_86 &&
F_44 ( V_64 . V_57 ) )
* V_86 = V_64 . V_57 ;
if ( ! V_105 . V_106 )
break;
}
V_11 = F_52 ( & V_89 ,
V_62 , V_64 . V_73 , V_64 . V_57 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_53 ( struct F_53 * V_107 , void * V_108 )
{
struct V_89 * V_109 = V_108 ;
return F_52 ( V_109 , V_107 -> V_62 ,
V_107 -> V_73 , V_107 -> V_57 ) ;
}
int F_54 ( struct V_45 * V_45 ,
struct V_110 * V_111 ,
struct V_46 * V_46 ,
struct V_112 * V_113 ,
struct V_56 * * V_86 )
{
int V_23 ;
F_49 ( & V_89 ) ;
V_23 = F_48 ( V_45 , V_46 ,
V_113 -> V_114 , V_86 ) ;
if ( V_23 )
return V_23 ;
if ( ! ( ( V_111 -> V_115 . V_116 & V_117 ) &&
( V_111 -> V_115 . V_116 & V_118 ) ) )
return 0 ;
if ( ( ! V_113 -> V_119 . V_120 ) ||
( ! V_113 -> V_121 . V_18 ) )
return 0 ;
return F_55 ( F_53 , & V_89 , V_45 ,
V_46 , V_111 -> V_115 . V_122 ,
V_113 ) ;
}
static int F_56 ( union V_123 * T_5
V_124 ,
struct V_1 * V_19
V_124 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static int F_57 ( union V_123 * T_5 V_124 ,
struct V_125 * * T_6
V_124 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static int F_58 ( struct V_26 * V_27 V_124 ,
union V_123 * T_5 V_124 ,
struct V_112 * V_113 V_124 ,
struct V_110 * V_111 V_124 ,
struct V_45 * V_45 V_124 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static int F_59 ( struct V_26 * V_27 V_124 ,
union V_123 * T_5 V_124 ,
struct V_112 * V_113 V_124 ,
struct V_45 * V_45 V_124 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static int F_60 ( struct V_26 * V_27 V_124 ,
union V_123 * T_5 V_124 ,
struct V_1 * V_1
V_124 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static int F_61 ( struct V_26 * V_27 V_124 ,
union V_123 * T_5 V_124 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static void F_62 ( struct V_26 * V_27 )
{
if ( V_27 -> V_113 == NULL )
V_27 -> V_113 = F_58 ;
if ( V_27 -> V_126 == NULL )
V_27 -> V_126 = F_59 ;
if ( V_27 -> V_127 == NULL )
V_27 -> V_127 = F_59 ;
if ( V_27 -> V_128 == NULL )
V_27 -> V_128 = F_59 ;
if ( V_27 -> exit == NULL )
V_27 -> exit = F_59 ;
if ( V_27 -> V_129 == NULL )
V_27 -> V_129 = V_130 ;
if ( V_27 -> V_131 == NULL )
V_27 -> V_131 = F_58 ;
if ( V_27 -> V_132 == NULL )
V_27 -> V_132 = F_59 ;
if ( V_27 -> V_133 == NULL )
V_27 -> V_133 = F_59 ;
if ( V_27 -> V_115 == NULL )
V_27 -> V_115 = F_57 ;
if ( V_27 -> V_134 == NULL )
V_27 -> V_134 = F_61 ;
if ( V_27 -> V_135 == NULL )
V_27 -> V_135 = F_56 ;
if ( V_27 -> V_136 == NULL )
V_27 -> V_136 = F_60 ;
if ( V_27 -> V_137 == NULL ) {
if ( V_27 -> V_36 )
V_27 -> V_137 = V_138 ;
else
V_27 -> V_137 = F_60 ;
}
}
void F_63 ( void * V_139 , int V_140 )
{
T_7 * V_66 = V_139 ;
while ( V_140 > 0 ) {
* V_66 = F_64 ( * V_66 ) ;
V_140 -= sizeof( T_7 ) ;
++ V_66 ;
}
}
void F_65 ( void * V_139 , int V_140 )
{
T_3 * V_66 = V_139 ;
while ( V_140 > 0 ) {
* V_66 = F_66 ( * V_66 ) ;
V_140 -= sizeof( T_3 ) ;
++ V_66 ;
}
}
static void F_67 ( union V_123 * T_5 , void * V_141 )
{
void * V_142 = ( void * ) T_5 + T_5 -> V_143 . V_18 ;
int V_18 = V_142 - V_141 ;
F_68 ( V_18 % sizeof( T_3 ) ) ;
F_65 ( V_141 , V_18 ) ;
}
static void F_69 ( union V_123 * T_5 ,
bool T_8 V_124 )
{
struct V_144 * V_145 = & T_5 -> V_143 ;
F_65 ( V_145 + 1 , T_5 -> V_143 . V_18 - sizeof( * V_145 ) ) ;
}
static void F_70 ( union V_123 * T_5 , bool T_8 )
{
T_5 -> V_127 . V_146 = F_64 ( T_5 -> V_127 . V_146 ) ;
T_5 -> V_127 . V_147 = F_64 ( T_5 -> V_127 . V_147 ) ;
if ( T_8 ) {
void * V_141 = & T_5 -> V_127 . V_127 ;
V_141 += F_71 ( strlen ( V_141 ) + 1 , sizeof( T_3 ) ) ;
F_67 ( T_5 , V_141 ) ;
}
}
static void F_72 ( union V_123 * T_5 ,
bool T_8 )
{
T_5 -> V_126 . V_146 = F_64 ( T_5 -> V_126 . V_146 ) ;
T_5 -> V_126 . V_147 = F_64 ( T_5 -> V_126 . V_147 ) ;
T_5 -> V_126 . V_148 = F_66 ( T_5 -> V_126 . V_148 ) ;
T_5 -> V_126 . V_29 = F_66 ( T_5 -> V_126 . V_29 ) ;
T_5 -> V_126 . V_149 = F_66 ( T_5 -> V_126 . V_149 ) ;
if ( T_8 ) {
void * V_141 = & T_5 -> V_126 . V_6 ;
V_141 += F_71 ( strlen ( V_141 ) + 1 , sizeof( T_3 ) ) ;
F_67 ( T_5 , V_141 ) ;
}
}
static void F_73 ( union V_123 * T_5 , bool T_8 )
{
T_5 -> V_128 . V_146 = F_64 ( T_5 -> V_128 . V_146 ) ;
T_5 -> V_128 . V_147 = F_64 ( T_5 -> V_128 . V_147 ) ;
T_5 -> V_128 . V_150 = F_64 ( T_5 -> V_128 . V_150 ) ;
T_5 -> V_128 . V_151 = F_64 ( T_5 -> V_128 . V_151 ) ;
T_5 -> V_128 . time = F_66 ( T_5 -> V_128 . time ) ;
if ( T_8 )
F_67 ( T_5 , & T_5 -> V_128 + 1 ) ;
}
static void F_74 ( union V_123 * T_5 , bool T_8 )
{
T_5 -> V_131 . V_146 = F_64 ( T_5 -> V_131 . V_146 ) ;
T_5 -> V_131 . V_147 = F_64 ( T_5 -> V_131 . V_147 ) ;
T_5 -> V_131 . V_152 = F_66 ( T_5 -> V_131 . V_152 ) ;
T_5 -> V_131 . V_153 = F_66 ( T_5 -> V_131 . V_153 ) ;
T_5 -> V_131 . V_154 = F_66 ( T_5 -> V_131 . V_154 ) ;
T_5 -> V_131 . V_155 = F_66 ( T_5 -> V_131 . V_155 ) ;
if ( T_8 )
F_67 ( T_5 , & T_5 -> V_131 + 1 ) ;
}
static T_4 F_75 ( T_4 V_156 )
{
int V_157 = ( V_156 >> 4 ) | ( ( V_156 & 0xf ) << 4 ) ;
V_157 = ( ( V_157 & 0xcc ) >> 2 ) | ( ( V_157 & 0x33 ) << 2 ) ;
V_157 = ( ( V_157 & 0xaa ) >> 1 ) | ( ( V_157 & 0x55 ) << 1 ) ;
return ( T_4 ) V_157 ;
}
static void F_76 ( T_4 * V_158 , unsigned V_29 )
{
unsigned V_65 ;
for ( V_65 = 0 ; V_65 < V_29 ; V_65 ++ ) {
* V_158 = F_75 ( * V_158 ) ;
V_158 ++ ;
}
}
void F_77 ( struct V_159 * V_115 )
{
V_115 -> type = F_64 ( V_115 -> type ) ;
V_115 -> V_18 = F_64 ( V_115 -> V_18 ) ;
V_115 -> V_160 = F_66 ( V_115 -> V_160 ) ;
V_115 -> V_161 = F_66 ( V_115 -> V_161 ) ;
V_115 -> V_116 = F_66 ( V_115 -> V_116 ) ;
V_115 -> V_162 = F_66 ( V_115 -> V_162 ) ;
V_115 -> V_163 = F_64 ( V_115 -> V_163 ) ;
V_115 -> V_164 = F_64 ( V_115 -> V_164 ) ;
V_115 -> V_165 = F_66 ( V_115 -> V_165 ) ;
V_115 -> V_166 = F_66 ( V_115 -> V_166 ) ;
F_76 ( ( T_4 * ) ( & V_115 -> V_162 + 1 ) , sizeof( T_3 ) ) ;
}
static void F_78 ( union V_123 * T_5 ,
bool T_8 V_124 )
{
T_2 V_18 ;
F_77 ( & T_5 -> V_115 . V_115 ) ;
V_18 = T_5 -> V_143 . V_18 ;
V_18 -= ( void * ) & T_5 -> V_115 . V_155 - ( void * ) T_5 ;
F_65 ( T_5 -> V_115 . V_155 , V_18 ) ;
}
static void F_79 ( union V_123 * T_5 ,
bool T_8 V_124 )
{
T_5 -> V_134 . V_134 . V_167 =
F_66 ( T_5 -> V_134 . V_134 . V_167 ) ;
}
static void F_80 ( union V_123 * T_5 ,
bool T_8 V_124 )
{
T_5 -> V_135 . V_18 = F_64 ( T_5 -> V_135 . V_18 ) ;
}
static void F_81 ( struct V_1 * V_19 )
{
struct V_36 * V_168 = & V_19 -> V_36 ;
while ( ! F_82 ( & V_168 -> V_39 ) ) {
struct V_169 * V_170 ;
V_170 = F_83 ( V_168 -> V_39 . V_171 , struct V_169 , V_172 ) ;
F_31 ( & V_170 -> V_172 ) ;
free ( V_170 ) ;
}
}
static int F_84 ( struct V_1 * V_173 ,
struct V_26 * V_27 )
{
struct V_36 * V_168 = & V_173 -> V_36 ;
struct V_174 * V_175 = & V_168 -> V_37 ;
struct V_169 * V_176 , * V_177 ;
struct V_112 V_113 ;
T_3 V_178 = V_168 -> V_179 ;
T_3 V_180 = V_168 -> V_181 ? V_168 -> V_181 -> V_182 : 0ULL ;
unsigned V_183 = 0 , V_184 = V_168 -> V_185 / 16 ;
int V_23 ;
if ( ! V_27 -> V_36 || ! V_178 )
return 0 ;
F_30 (iter, tmp, head, list) {
if ( V_177 -> V_182 > V_178 )
break;
V_23 = F_85 ( V_173 -> V_17 , V_177 -> T_5 , & V_113 ) ;
if ( V_23 )
F_3 ( L_17 , V_23 ) ;
else {
V_23 = F_86 ( V_173 , V_177 -> T_5 , & V_113 , V_27 ,
V_177 -> V_186 ) ;
if ( V_23 )
return V_23 ;
}
V_168 -> V_187 = V_177 -> V_182 ;
F_31 ( & V_177 -> V_172 ) ;
F_87 ( & V_177 -> V_172 , & V_168 -> V_38 ) ;
if ( ++ V_183 >= V_184 ) {
V_184 += V_168 -> V_185 / 16 ;
F_88 ( V_183 , V_168 -> V_185 ,
L_18 ) ;
}
}
if ( F_82 ( V_175 ) ) {
V_168 -> V_181 = NULL ;
} else if ( V_180 <= V_178 ) {
V_168 -> V_181 =
F_83 ( V_175 -> V_188 , struct V_169 , V_172 ) ;
}
V_168 -> V_185 = 0 ;
return 0 ;
}
static int V_138 ( struct V_26 * V_27 ,
union V_123 * T_5 V_124 ,
struct V_1 * V_19 )
{
int V_23 = F_84 ( V_19 , V_27 ) ;
if ( ! V_23 )
V_19 -> V_36 . V_179 = V_19 -> V_36 . V_189 ;
return V_23 ;
}
static void F_89 ( struct V_169 * V_190 , struct V_1 * V_173 )
{
struct V_36 * V_168 = & V_173 -> V_36 ;
struct V_169 * V_113 = V_168 -> V_181 ;
T_3 V_182 = V_190 -> V_182 ;
struct V_174 * V_158 ;
++ V_168 -> V_185 ;
V_168 -> V_181 = V_190 ;
if ( ! V_113 ) {
F_87 ( & V_190 -> V_172 , & V_168 -> V_37 ) ;
V_168 -> V_189 = V_182 ;
return;
}
if ( V_113 -> V_182 <= V_182 ) {
while ( V_113 -> V_182 <= V_182 ) {
V_158 = V_113 -> V_172 . V_171 ;
if ( V_158 == & V_168 -> V_37 ) {
F_43 ( & V_190 -> V_172 , & V_168 -> V_37 ) ;
V_168 -> V_189 = V_182 ;
return;
}
V_113 = F_83 ( V_158 , struct V_169 , V_172 ) ;
}
F_43 ( & V_190 -> V_172 , & V_113 -> V_172 ) ;
} else {
while ( V_113 -> V_182 > V_182 ) {
V_158 = V_113 -> V_172 . V_188 ;
if ( V_158 == & V_168 -> V_37 ) {
F_87 ( & V_190 -> V_172 , & V_168 -> V_37 ) ;
return;
}
V_113 = F_83 ( V_158 , struct V_169 , V_172 ) ;
}
F_87 ( & V_190 -> V_172 , & V_113 -> V_172 ) ;
}
}
static int F_90 ( struct V_1 * V_173 , union V_123 * T_5 ,
struct V_112 * V_113 , T_3 V_186 )
{
struct V_36 * V_168 = & V_173 -> V_36 ;
struct V_174 * V_191 = & V_168 -> V_38 ;
T_3 V_182 = V_113 -> time ;
struct V_169 * V_190 ;
if ( ! V_182 || V_182 == ~ 0ULL )
return - V_192 ;
if ( V_182 < V_173 -> V_36 . V_187 ) {
printf ( L_19 ) ;
return - V_193 ;
}
if ( ! F_82 ( V_191 ) ) {
V_190 = F_83 ( V_191 -> V_171 , struct V_169 , V_172 ) ;
F_31 ( & V_190 -> V_172 ) ;
} else if ( V_168 -> V_194 ) {
V_190 = V_168 -> V_194 + V_168 -> V_195 ;
if ( ++ V_168 -> V_195 == V_196 )
V_168 -> V_194 = NULL ;
} else {
V_168 -> V_194 = malloc ( V_196 * sizeof( * V_190 ) ) ;
if ( ! V_168 -> V_194 )
return - V_197 ;
F_87 ( & V_168 -> V_194 -> V_172 , & V_168 -> V_39 ) ;
V_168 -> V_195 = 2 ;
V_190 = V_168 -> V_194 + 1 ;
}
V_190 -> V_182 = V_182 ;
V_190 -> V_186 = V_186 ;
V_190 -> T_5 = T_5 ;
F_89 ( V_190 , V_173 ) ;
return 0 ;
}
static void F_91 ( struct V_112 * V_113 )
{
unsigned int V_65 ;
printf ( L_20 V_198 L_6 , V_113 -> V_114 -> V_79 ) ;
for ( V_65 = 0 ; V_65 < V_113 -> V_114 -> V_79 ; V_65 ++ )
printf ( L_21 V_199 L_6 ,
V_65 , V_113 -> V_114 -> V_94 [ V_65 ] ) ;
}
static void F_92 ( struct V_112 * V_113 )
{
T_9 V_65 ;
printf ( L_22 V_198 L_6 , V_113 -> V_76 -> V_79 ) ;
for ( V_65 = 0 ; V_65 < V_113 -> V_76 -> V_79 ; V_65 ++ )
printf ( L_23 V_198 L_24 V_199 L_25 V_199 L_6 ,
V_65 , V_113 -> V_76 -> V_81 [ V_65 ] . V_82 ,
V_113 -> V_76 -> V_81 [ V_65 ] . V_80 ) ;
}
static void F_93 ( T_3 V_200 , T_3 * V_120 )
{
unsigned V_201 , V_65 = 0 ;
F_94 (rid, (unsigned long *) &mask, sizeof(mask) * 8 ) {
T_3 V_202 = V_120 [ V_65 ++ ] ;
printf ( L_26 V_199 L_6 ,
F_95 ( V_201 ) , V_202 ) ;
}
}
static void F_96 ( struct V_112 * V_113 , T_3 V_200 )
{
struct V_203 * V_119 = & V_113 -> V_119 ;
if ( V_119 -> V_120 ) {
printf ( L_27 V_199 L_6 , V_200 ) ;
F_93 ( V_200 , V_119 -> V_120 ) ;
}
}
static void F_97 ( struct V_204 * V_205 )
{
printf ( L_28 V_198 L_29 ,
V_205 -> V_18 , V_205 -> V_206 ) ;
}
static void F_98 ( struct V_1 * V_19 ,
union V_123 * T_5 ,
struct V_112 * V_113 )
{
T_3 V_116 = F_99 ( V_19 -> V_17 ) ;
if ( T_5 -> V_143 . type != V_207 &&
! F_26 ( V_19 -> V_17 ) ) {
fputs ( L_30 , stdout ) ;
return;
}
if ( ( V_116 & V_208 ) )
printf ( L_31 , V_113 -> V_209 ) ;
if ( V_116 & V_210 )
printf ( L_15 V_198 L_32 , V_113 -> time ) ;
}
static void F_100 ( struct V_1 * V_19 , union V_123 * T_5 ,
T_3 V_186 , struct V_112 * V_113 )
{
if ( ! V_211 )
return;
printf ( L_33 V_199 L_34 ,
V_186 , T_5 -> V_143 . V_18 , T_5 -> V_143 . type ) ;
F_101 ( T_5 ) ;
if ( V_113 )
F_98 ( V_19 , T_5 , V_113 ) ;
printf ( L_35 V_199 L_36 , V_186 ,
T_5 -> V_143 . V_18 , F_102 ( T_5 -> V_143 . type ) ) ;
}
static void F_103 ( struct V_110 * V_111 , union V_123 * T_5 ,
struct V_112 * V_113 )
{
T_3 V_116 ;
if ( ! V_211 )
return;
printf ( L_37 V_199 L_38 V_198 L_39 V_199 L_6 ,
T_5 -> V_143 . V_212 , V_113 -> V_146 , V_113 -> V_147 , V_113 -> V_62 ,
V_113 -> V_213 , V_113 -> V_71 ) ;
V_116 = V_111 -> V_115 . V_116 ;
if ( V_116 & V_214 )
F_91 ( V_113 ) ;
if ( V_116 & V_215 )
F_92 ( V_113 ) ;
if ( V_116 & V_117 )
F_96 ( V_113 , V_111 -> V_115 . V_122 ) ;
if ( V_116 & V_118 )
F_97 ( & V_113 -> V_121 ) ;
}
static struct V_45 *
F_104 ( struct V_1 * V_19 ,
union V_123 * T_5 )
{
const T_4 V_87 = T_5 -> V_143 . V_212 & V_216 ;
if ( V_217 &&
( ( V_87 == V_218 ) ||
( V_87 == V_219 ) ) ) {
T_7 V_146 ;
if ( T_5 -> V_143 . type == V_220 )
V_146 = T_5 -> V_126 . V_146 ;
else
V_146 = T_5 -> V_62 . V_146 ;
return F_105 ( V_19 , V_146 ) ;
}
return F_106 ( V_19 ) ;
}
static int F_86 ( struct V_1 * V_19 ,
union V_123 * T_5 ,
struct V_112 * V_113 ,
struct V_26 * V_27 ,
T_3 V_186 )
{
struct V_110 * V_111 ;
struct V_45 * V_45 ;
F_100 ( V_19 , T_5 , V_186 , V_113 ) ;
V_111 = F_107 ( V_19 -> V_17 , V_113 -> V_155 ) ;
if ( V_111 != NULL && T_5 -> V_143 . type != V_207 ) {
F_108 ( & V_111 -> V_41 , T_5 -> V_143 . type ) ;
}
V_45 = F_104 ( V_19 , T_5 ) ;
switch ( T_5 -> V_143 . type ) {
case V_207 :
F_103 ( V_111 , T_5 , V_113 ) ;
if ( V_111 == NULL ) {
++ V_19 -> V_41 . V_221 . V_222 ;
return 0 ;
}
if ( V_45 == NULL ) {
++ V_19 -> V_41 . V_221 . V_223 ;
return 0 ;
}
return V_27 -> V_113 ( V_27 , T_5 , V_113 , V_111 , V_45 ) ;
case V_220 :
return V_27 -> V_126 ( V_27 , T_5 , V_113 , V_45 ) ;
case V_224 :
return V_27 -> V_127 ( V_27 , T_5 , V_113 , V_45 ) ;
case V_225 :
return V_27 -> V_128 ( V_27 , T_5 , V_113 , V_45 ) ;
case V_226 :
return V_27 -> exit ( V_27 , T_5 , V_113 , V_45 ) ;
case V_227 :
if ( V_27 -> V_129 == V_130 )
V_19 -> V_41 . V_221 . V_228 += T_5 -> V_129 . V_129 ;
return V_27 -> V_129 ( V_27 , T_5 , V_113 , V_45 ) ;
case V_229 :
return V_27 -> V_131 ( V_27 , T_5 , V_113 , V_111 , V_45 ) ;
case V_230 :
return V_27 -> V_132 ( V_27 , T_5 , V_113 , V_45 ) ;
case V_231 :
return V_27 -> V_133 ( V_27 , T_5 , V_113 , V_45 ) ;
default:
++ V_19 -> V_41 . V_221 . V_232 ;
return - 1 ;
}
}
static int F_109 ( struct V_1 * V_19 ,
union V_123 * T_5 , struct V_112 * V_113 )
{
if ( T_5 -> V_143 . type != V_207 ||
! ( F_99 ( V_19 -> V_17 ) & V_214 ) )
return 0 ;
if ( ! F_110 ( V_113 -> V_114 , T_5 ) ) {
F_51 ( L_40 ) ;
++ V_19 -> V_41 . V_221 . V_233 ;
V_19 -> V_41 . V_221 . V_234 += V_113 -> V_213 ;
return - V_193 ;
}
return 0 ;
}
static int F_111 ( struct V_1 * V_19 , union V_123 * T_5 ,
struct V_26 * V_27 , T_3 V_186 )
{
int V_11 ;
F_100 ( V_19 , T_5 , V_186 , NULL ) ;
switch ( T_5 -> V_143 . type ) {
case V_235 :
V_11 = V_27 -> V_115 ( T_5 , & V_19 -> V_17 ) ;
if ( V_11 == 0 )
F_11 ( V_19 ) ;
return V_11 ;
case V_236 :
return V_27 -> V_134 ( V_27 , T_5 ) ;
case V_237 :
F_112 ( V_19 -> V_8 , V_186 , V_238 ) ;
return V_27 -> V_135 ( T_5 , V_19 ) ;
case V_239 :
return V_27 -> V_136 ( V_27 , T_5 , V_19 ) ;
case V_240 :
return V_27 -> V_137 ( V_27 , T_5 , V_19 ) ;
default:
return - V_193 ;
}
}
static void F_113 ( union V_123 * T_5 , bool T_8 )
{
T_10 V_241 ;
V_241 = V_242 [ T_5 -> V_143 . type ] ;
if ( V_241 )
V_241 ( T_5 , T_8 ) ;
}
static int F_114 ( struct V_1 * V_19 ,
union V_123 * T_5 ,
struct V_26 * V_27 ,
T_3 V_186 )
{
struct V_112 V_113 ;
int V_23 ;
if ( V_19 -> V_143 . V_243 )
F_113 ( T_5 , F_26 ( V_19 -> V_17 ) ) ;
if ( T_5 -> V_143 . type >= V_244 )
return - V_193 ;
F_108 ( & V_19 -> V_41 , T_5 -> V_143 . type ) ;
if ( T_5 -> V_143 . type >= V_245 )
return F_111 ( V_19 , T_5 , V_27 , V_186 ) ;
V_23 = F_85 ( V_19 -> V_17 , T_5 , & V_113 ) ;
if ( V_23 )
return V_23 ;
if ( F_109 ( V_19 , T_5 , & V_113 ) )
return 0 ;
if ( V_27 -> V_36 ) {
V_23 = F_90 ( V_19 , T_5 , & V_113 ,
V_186 ) ;
if ( V_23 != - V_192 )
return V_23 ;
}
return F_86 ( V_19 , T_5 , & V_113 , V_27 ,
V_186 ) ;
}
void F_115 ( struct V_144 * V_2 )
{
V_2 -> type = F_64 ( V_2 -> type ) ;
V_2 -> V_212 = F_116 ( V_2 -> V_212 ) ;
V_2 -> V_18 = F_116 ( V_2 -> V_18 ) ;
}
struct V_46 * F_117 ( struct V_1 * V_19 , T_11 V_146 )
{
return F_118 ( & V_19 -> V_21 , V_146 ) ;
}
static struct V_46 * F_119 ( struct V_1 * V_2 )
{
struct V_46 * V_46 = F_117 ( V_2 , 0 ) ;
if ( V_46 == NULL || F_120 ( V_46 , L_41 ) ) {
F_3 ( L_42 ) ;
V_46 = NULL ;
}
return V_46 ;
}
static void F_121 ( const struct V_1 * V_19 ,
const struct V_26 * V_27 )
{
if ( V_27 -> V_129 == V_130 &&
V_19 -> V_41 . V_221 . V_246 [ V_227 ] != 0 ) {
F_122 ( L_43
L_44 ,
V_19 -> V_41 . V_221 . V_246 [ 0 ] ,
V_19 -> V_41 . V_221 . V_246 [ V_227 ] ) ;
}
if ( V_19 -> V_41 . V_221 . V_232 != 0 ) {
F_122 ( L_45
L_46
L_47
L_48
L_49 ,
V_19 -> V_41 . V_221 . V_232 ) ;
}
if ( V_19 -> V_41 . V_221 . V_222 != 0 ) {
F_122 ( L_50 ,
V_19 -> V_41 . V_221 . V_222 ) ;
}
if ( V_19 -> V_41 . V_221 . V_233 != 0 ) {
F_122 ( L_51
L_52
L_53 ,
V_19 -> V_41 . V_221 . V_233 ,
V_19 -> V_41 . V_221 . V_246 [ V_207 ] ) ;
}
if ( V_19 -> V_41 . V_221 . V_223 != 0 ) {
F_122 ( L_54
L_55 ,
V_19 -> V_41 . V_221 . V_223 ) ;
}
}
static int F_123 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
union V_123 * T_5 ;
T_12 V_18 , V_247 = 0 ;
void * V_248 = NULL ;
int V_249 = 0 ;
T_3 V_175 ;
int V_11 ;
void * V_158 ;
F_62 ( V_27 ) ;
V_175 = 0 ;
V_247 = sizeof( union V_123 ) ;
V_248 = malloc ( V_247 ) ;
if ( ! V_248 )
return - V_12 ;
V_250:
T_5 = V_248 ;
V_11 = F_124 ( V_2 -> V_8 , T_5 , sizeof( struct V_144 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 )
goto V_251;
F_3 ( L_56 ) ;
goto V_252;
}
if ( V_2 -> V_143 . V_243 )
F_115 ( & T_5 -> V_143 ) ;
V_18 = T_5 -> V_143 . V_18 ;
if ( V_18 == 0 )
V_18 = 8 ;
if ( V_18 > V_247 ) {
void * V_190 = realloc ( V_248 , V_18 ) ;
if ( ! V_190 ) {
F_3 ( L_57 ) ;
goto V_252;
}
V_248 = V_190 ;
V_247 = V_18 ;
T_5 = V_248 ;
}
V_158 = T_5 ;
V_158 += sizeof( struct V_144 ) ;
if ( V_18 - sizeof( struct V_144 ) ) {
V_11 = F_124 ( V_2 -> V_8 , V_158 , V_18 - sizeof( struct V_144 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 ) {
F_3 ( L_58 ) ;
goto V_251;
}
F_3 ( L_59 ) ;
goto V_252;
}
}
if ( ( V_249 = F_114 ( V_2 , T_5 , V_27 , V_175 ) ) < 0 ) {
F_3 ( L_35 V_199 L_60 ,
V_175 , T_5 -> V_143 . V_18 , T_5 -> V_143 . type ) ;
V_11 = - V_193 ;
goto V_252;
}
V_175 += V_18 ;
if ( V_249 > 0 )
V_175 += V_249 ;
if ( ! F_125 () )
goto V_250;
V_251:
V_11 = 0 ;
V_252:
free ( V_248 ) ;
F_121 ( V_2 , V_27 ) ;
F_81 ( V_2 ) ;
return V_11 ;
}
static union V_123 *
F_126 ( struct V_1 * V_19 ,
T_3 V_175 , T_2 V_253 , char * V_248 )
{
union V_123 * T_5 ;
if ( V_175 + sizeof( T_5 -> V_143 ) > V_253 )
return NULL ;
T_5 = (union V_123 * ) ( V_248 + V_175 ) ;
if ( V_19 -> V_143 . V_243 )
F_115 ( & T_5 -> V_143 ) ;
if ( V_175 + T_5 -> V_143 . V_18 > V_253 )
return NULL ;
return T_5 ;
}
int F_127 ( struct V_1 * V_19 ,
T_3 V_254 , T_3 V_255 ,
T_3 V_256 , struct V_26 * V_27 )
{
T_3 V_175 , V_257 , V_186 , V_258 , V_184 ;
int V_11 , V_259 , V_260 , V_261 = 0 ;
T_2 V_253 ;
char * V_248 , * V_262 [ 8 ] ;
union V_123 * T_5 ;
T_12 V_18 ;
F_62 ( V_27 ) ;
V_257 = V_263 * ( V_254 / V_263 ) ;
V_186 = V_257 ;
V_175 = V_254 - V_257 ;
if ( V_254 + V_255 < V_256 )
V_256 = V_254 + V_255 ;
V_184 = V_256 / 16 ;
V_253 = V_19 -> V_33 ;
if ( V_253 > V_256 )
V_253 = V_256 ;
memset ( V_262 , 0 , sizeof( V_262 ) ) ;
V_259 = V_264 ;
V_260 = V_265 ;
if ( V_19 -> V_143 . V_243 ) {
V_259 |= V_266 ;
V_260 = V_267 ;
}
V_268:
V_248 = V_126 ( NULL , V_253 , V_259 , V_260 , V_19 -> V_8 ,
V_186 ) ;
if ( V_248 == V_269 ) {
F_3 ( L_61 ) ;
V_11 = - V_12 ;
goto V_252;
}
V_262 [ V_261 ] = V_248 ;
V_261 = ( V_261 + 1 ) & ( F_128 ( V_262 ) - 1 ) ;
V_258 = V_186 + V_175 ;
V_250:
T_5 = F_126 ( V_19 , V_175 , V_253 , V_248 ) ;
if ( ! T_5 ) {
if ( V_262 [ V_261 ] ) {
F_129 ( V_262 [ V_261 ] , V_253 ) ;
V_262 [ V_261 ] = NULL ;
}
V_257 = V_263 * ( V_175 / V_263 ) ;
V_186 += V_257 ;
V_175 -= V_257 ;
goto V_268;
}
V_18 = T_5 -> V_143 . V_18 ;
if ( V_18 == 0 ||
F_114 ( V_19 , T_5 , V_27 , V_258 ) < 0 ) {
F_3 ( L_35 V_199 L_60 ,
V_186 + V_175 , T_5 -> V_143 . V_18 ,
T_5 -> V_143 . type ) ;
V_11 = - V_193 ;
goto V_252;
}
V_175 += V_18 ;
V_258 += V_18 ;
if ( V_258 >= V_184 ) {
V_184 += V_256 / 16 ;
F_88 ( V_258 , V_256 ,
L_62 ) ;
}
if ( V_258 < V_256 )
goto V_250;
V_11 = 0 ;
V_19 -> V_36 . V_179 = V_34 ;
V_11 = F_84 ( V_19 , V_27 ) ;
V_252:
F_130 () ;
F_121 ( V_19 , V_27 ) ;
F_81 ( V_19 ) ;
return V_11 ;
}
int F_131 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
int V_11 ;
if ( F_119 ( V_2 ) == NULL )
return - V_197 ;
if ( ! V_2 -> V_7 )
V_11 = F_127 ( V_2 ,
V_2 -> V_143 . V_254 ,
V_2 -> V_143 . V_255 ,
V_2 -> V_18 , V_27 ) ;
else
V_11 = F_123 ( V_2 , V_27 ) ;
return V_11 ;
}
bool F_132 ( struct V_1 * V_19 , const char * V_270 )
{
if ( ! ( F_99 ( V_19 -> V_17 ) & V_271 ) ) {
F_3 ( L_63 , V_270 ) ;
return false ;
}
return true ;
}
int F_133 ( struct V_73 * * V_272 ,
const char * V_273 , T_3 V_71 )
{
char * V_274 ;
enum V_275 V_65 ;
struct V_276 * V_277 ;
V_277 = F_22 ( sizeof( struct V_276 ) ) ;
if ( V_277 == NULL )
return - V_197 ;
V_277 -> V_58 = F_134 ( V_273 ) ;
if ( V_277 -> V_58 == NULL ) {
free ( V_277 ) ;
return - V_197 ;
}
V_274 = strchr ( V_277 -> V_58 , ']' ) ;
if ( V_274 )
* V_274 = '\0' ;
V_277 -> V_71 = V_71 ;
for ( V_65 = 0 ; V_65 < V_278 ; ++ V_65 ) {
struct V_279 * V_279 = F_135 ( V_272 [ V_65 ] ) ;
V_279 -> V_276 = V_277 ;
}
return 0 ;
}
T_2 F_136 ( struct V_1 * V_2 , T_13 * V_280 )
{
return F_137 ( & V_2 -> V_21 . V_281 , V_280 ) +
F_137 ( & V_2 -> V_21 . V_282 , V_280 ) +
F_138 ( & V_2 -> V_22 , V_280 ) ;
}
T_2 F_139 ( struct V_1 * V_2 , T_13 * V_280 ,
bool V_283 )
{
T_2 V_23 = F_140 ( & V_2 -> V_21 , V_280 , V_283 ) ;
return V_23 + F_141 ( & V_2 -> V_22 , V_280 , V_283 ) ;
}
T_2 F_142 ( struct V_1 * V_19 , T_13 * V_280 )
{
struct V_110 * V_284 ;
T_2 V_23 = fprintf ( V_280 , L_64 ) ;
V_23 += F_143 ( & V_19 -> V_41 , V_280 ) ;
F_144 (pos, &session->evlist->entries, node) {
V_23 += fprintf ( V_280 , L_65 , F_145 ( V_284 ) ) ;
V_23 += F_143 ( & V_284 -> V_41 , V_280 ) ;
}
return V_23 ;
}
T_2 F_146 ( struct V_1 * V_19 , T_13 * V_280 )
{
return F_147 ( & V_19 -> V_21 , V_280 ) ;
}
void F_148 ( struct V_1 * V_19 ,
struct V_46 * V_53 )
{
F_42 ( & V_19 -> V_21 , V_53 ) ;
}
struct V_110 * F_149 ( struct V_1 * V_19 ,
unsigned int type )
{
struct V_110 * V_284 ;
F_144 (pos, &session->evlist->entries, node) {
if ( V_284 -> V_115 . type == type )
return V_284 ;
}
return NULL ;
}
void F_150 ( struct V_110 * V_111 , union V_123 * T_5 ,
struct V_112 * V_113 , struct V_45 * V_45 ,
int V_285 , int V_286 , int V_287 )
{
struct V_63 V_64 ;
struct V_288 * V_49 ;
if ( F_151 ( T_5 , V_45 , & V_64 , V_113 ,
NULL ) < 0 ) {
error ( L_66 ,
T_5 -> V_143 . type ) ;
return;
}
if ( V_105 . V_106 && V_113 -> V_114 ) {
if ( F_54 ( V_45 , V_111 , V_64 . V_46 ,
V_113 , NULL ) != 0 ) {
if ( V_289 )
error ( L_67 ) ;
return;
}
F_152 ( & V_89 ) ;
while ( 1 ) {
V_49 = F_153 ( & V_89 ) ;
if ( ! V_49 )
break;
printf ( L_68 V_199 , V_49 -> V_62 ) ;
if ( V_285 ) {
printf ( L_32 ) ;
F_154 ( V_49 -> V_57 , stdout ) ;
}
if ( V_286 ) {
printf ( L_69 ) ;
F_155 ( V_49 -> V_73 , stdout ) ;
printf ( L_70 ) ;
}
printf ( L_6 ) ;
F_156 ( & V_89 ) ;
}
} else {
printf ( L_71 V_199 , V_113 -> V_62 ) ;
if ( V_285 ) {
printf ( L_32 ) ;
if ( V_287 )
F_157 ( V_64 . V_57 , & V_64 ,
stdout ) ;
else
F_154 ( V_64 . V_57 , stdout ) ;
}
if ( V_286 ) {
printf ( L_69 ) ;
F_155 ( V_64 . V_73 , stdout ) ;
printf ( L_70 ) ;
}
}
}
int F_158 ( struct V_1 * V_19 ,
const char * V_290 , unsigned long * V_291 )
{
int V_65 ;
struct V_292 * V_73 ;
for ( V_65 = 0 ; V_65 < V_293 ; ++ V_65 ) {
struct V_110 * V_111 ;
V_111 = F_149 ( V_19 , V_65 ) ;
if ( ! V_111 )
continue;
if ( ! ( V_111 -> V_115 . V_116 & V_208 ) ) {
F_3 ( L_72
L_73 ) ;
return - 1 ;
}
}
V_73 = F_159 ( V_290 ) ;
if ( V_73 == NULL ) {
F_3 ( L_74 ) ;
return - 1 ;
}
for ( V_65 = 0 ; V_65 < V_73 -> V_79 ; V_65 ++ ) {
int V_209 = V_73 -> V_73 [ V_65 ] ;
if ( V_209 >= V_294 ) {
F_3 ( L_75
L_76 , V_209 ) ;
return - 1 ;
}
F_160 ( V_209 , V_291 ) ;
}
return 0 ;
}
void F_161 ( struct V_1 * V_19 , T_13 * V_280 ,
bool V_295 )
{
struct V_4 V_28 ;
int V_23 ;
if ( V_19 == NULL || V_280 == NULL )
return;
V_23 = F_5 ( V_19 -> V_8 , & V_28 ) ;
if ( V_23 == - 1 )
return;
fprintf ( V_280 , L_77 ) ;
fprintf ( V_280 , L_78 , ctime ( & V_28 . V_296 ) ) ;
F_162 ( V_19 , V_280 , V_295 ) ;
fprintf ( V_280 , L_79 ) ;
}
int F_163 ( struct V_1 * V_19 ,
const struct V_297 * V_298 ,
T_2 V_299 )
{
struct V_125 * V_17 = V_19 -> V_17 ;
struct V_300 * V_301 ;
struct V_110 * V_111 ;
char * V_302 , * V_58 ;
T_2 V_65 ;
int V_11 ;
for ( V_65 = 0 ; V_65 < V_299 ; V_65 ++ ) {
V_11 = - V_197 ;
V_302 = F_134 ( V_298 [ V_65 ] . V_58 ) ;
if ( V_302 == NULL )
goto V_31;
V_11 = - V_13 ;
V_58 = strchr ( V_302 , ':' ) ;
if ( V_58 == NULL )
goto V_303;
* V_58 ++ = '\0' ;
V_301 = F_164 ( V_19 -> V_304 ,
V_302 , V_58 ) ;
if ( V_301 == NULL ) {
goto V_171;
}
V_111 = F_165 ( V_17 , V_301 -> V_155 ) ;
if ( V_111 == NULL )
goto V_171;
V_11 = - V_305 ;
if ( V_111 -> V_306 . V_307 != NULL )
goto V_303;
V_111 -> V_306 . V_307 = V_298 [ V_65 ] . V_306 ;
V_171:
free ( V_302 ) ;
}
V_11 = 0 ;
V_31:
return V_11 ;
V_303:
free ( V_302 ) ;
goto V_31;
}

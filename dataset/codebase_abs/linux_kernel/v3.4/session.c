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
void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_19 = F_12 ( V_2 -> V_17 ) ;
V_2 -> V_20 = F_13 ( V_2 -> V_19 ) ;
V_2 -> V_21 = F_14 ( V_2 -> V_17 ) ;
V_2 -> V_22 = F_15 ( V_2 -> V_17 ) ;
V_2 -> V_23 . V_22 = V_2 -> V_22 ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_24 = F_17 ( & V_2 -> V_23 ) ;
if ( V_24 >= 0 )
V_24 = F_18 ( & V_2 -> V_25 ) ;
return V_24 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_23 ) ;
F_21 ( & V_2 -> V_25 ) ;
}
struct V_1 * F_22 ( const char * V_6 , int V_26 ,
bool V_3 , bool V_27 ,
struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_4 V_30 ;
T_1 V_31 ;
if ( ! V_6 || ! strlen ( V_6 ) ) {
if ( ! F_5 ( V_9 , & V_30 ) && F_23 ( V_30 . V_32 ) )
V_6 = L_1 ;
else
V_6 = L_4 ;
}
V_31 = strlen ( V_6 ) ;
V_2 = F_24 ( sizeof( * V_2 ) + V_31 ) ;
if ( V_2 == NULL )
goto V_33;
memcpy ( V_2 -> V_6 , V_6 , V_31 ) ;
#if V_34 == 64
V_2 -> V_35 = V_36 ;
#else
V_2 -> V_35 = 32 * 1024 * 1024ULL ;
#endif
V_2 -> V_25 = V_37 ;
V_2 -> V_27 = V_27 ;
F_25 ( & V_2 -> V_38 . V_39 ) ;
F_25 ( & V_2 -> V_38 . V_40 ) ;
F_25 ( & V_2 -> V_38 . V_41 ) ;
F_26 ( & V_2 -> V_23 , L_11 , V_42 ) ;
F_27 ( & V_2 -> V_43 ) ;
if ( V_26 == V_10 ) {
if ( F_1 ( V_2 , V_3 ) < 0 )
goto V_44;
F_11 ( V_2 ) ;
} else if ( V_26 == V_45 ) {
if ( F_16 ( V_2 ) < 0 )
goto V_44;
}
if ( V_29 && V_29 -> V_46 &&
V_29 -> V_38 && ! V_2 -> V_21 ) {
F_28 ( L_12 ) ;
V_29 -> V_38 = false ;
}
V_33:
return V_2 ;
V_44:
F_29 ( V_2 ) ;
return NULL ;
}
static void F_30 ( struct V_47 * V_47 )
{
struct V_48 * V_49 , * V_50 ;
F_31 (t, n, &machine->dead_threads, node) {
F_32 ( & V_50 -> V_51 ) ;
F_33 ( V_50 ) ;
}
}
static void F_34 ( struct V_1 * V_52 )
{
F_30 ( & V_52 -> V_23 ) ;
}
static void F_35 ( struct V_47 * V_2 )
{
struct V_53 * V_54 = F_36 ( & V_2 -> V_55 ) ;
while ( V_54 ) {
struct V_48 * V_50 = F_37 ( V_54 , struct V_48 , V_53 ) ;
F_38 ( & V_50 -> V_53 , & V_2 -> V_55 ) ;
V_54 = F_39 ( V_54 ) ;
F_33 ( V_50 ) ;
}
}
static void F_40 ( struct V_1 * V_52 )
{
F_35 ( & V_52 -> V_23 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_34 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( & V_2 -> V_23 ) ;
F_10 ( V_2 -> V_8 ) ;
free ( V_2 ) ;
}
void F_42 ( struct V_47 * V_2 , struct V_48 * V_56 )
{
V_2 -> V_57 = NULL ;
F_38 ( & V_56 -> V_53 , & V_2 -> V_55 ) ;
F_43 ( & V_56 -> V_51 , & V_2 -> V_58 ) ;
}
static bool F_44 ( struct V_59 * V_60 )
{
if ( V_60 -> V_61 && ! regexec ( & V_62 , V_60 -> V_61 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_45 ( struct V_47 * V_2 , struct V_48 * V_48 ,
struct V_63 * V_64 ,
T_2 V_65 )
{
struct V_66 V_67 ;
T_1 V_68 ;
T_3 V_69 ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
for ( V_68 = 0 ; V_68 < V_70 ; V_68 ++ ) {
V_69 = V_71 [ V_68 ] ;
F_46 ( V_48 , V_2 , V_69 , V_72 ,
V_65 , & V_67 , NULL ) ;
if ( V_67 . V_60 )
goto V_73;
}
V_73:
V_64 -> V_74 = V_65 ;
V_64 -> V_75 = V_67 . V_74 ;
V_64 -> V_60 = V_67 . V_60 ;
V_64 -> V_76 = V_67 . V_76 ;
}
struct V_77 * F_47 ( struct V_47 * V_2 ,
struct V_48 * V_78 ,
struct V_79 * V_80 )
{
struct V_77 * V_81 ;
unsigned int V_68 ;
V_81 = calloc ( V_80 -> V_82 , sizeof( struct V_77 ) ) ;
if ( ! V_81 )
return NULL ;
for ( V_68 = 0 ; V_68 < V_80 -> V_82 ; V_68 ++ ) {
F_45 ( V_2 , V_78 , & V_81 [ V_68 ] . V_83 , V_80 -> V_84 [ V_68 ] . V_83 ) ;
F_45 ( V_2 , V_78 , & V_81 [ V_68 ] . V_85 , V_80 -> V_84 [ V_68 ] . V_85 ) ;
V_81 [ V_68 ] . V_86 = V_80 -> V_84 [ V_68 ] . V_86 ;
}
return V_81 ;
}
int F_48 ( struct V_47 * V_2 , struct V_87 * V_88 ,
struct V_48 * V_48 ,
struct V_89 * V_90 ,
struct V_59 * * V_91 )
{
T_3 V_92 = V_93 ;
unsigned int V_68 ;
int V_11 ;
F_49 ( & V_88 -> V_43 . V_94 ) ;
for ( V_68 = 0 ; V_68 < V_90 -> V_82 ; V_68 ++ ) {
T_2 V_65 ;
struct V_66 V_67 ;
if ( V_95 . V_96 == V_97 )
V_65 = V_90 -> V_98 [ V_68 ] ;
else
V_65 = V_90 -> V_98 [ V_90 -> V_82 - V_68 - 1 ] ;
if ( V_65 >= V_99 ) {
switch ( V_65 ) {
case V_100 :
V_92 = V_101 ; break;
case V_102 :
V_92 = V_103 ; break;
case V_104 :
V_92 = V_93 ; break;
default:
break;
}
continue;
}
V_67 . V_105 = false ;
F_46 ( V_48 , V_2 , V_92 ,
V_72 , V_65 , & V_67 , NULL ) ;
if ( V_67 . V_60 != NULL ) {
if ( V_106 && ! * V_91 &&
F_44 ( V_67 . V_60 ) )
* V_91 = V_67 . V_60 ;
if ( ! V_107 . V_108 )
break;
}
V_11 = F_50 ( & V_88 -> V_43 . V_94 ,
V_65 , V_67 . V_76 , V_67 . V_60 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_51 ( union V_109 * T_4 V_110 ,
struct V_1 * V_52 V_110 )
{
F_28 ( L_13 ) ;
return 0 ;
}
static int F_52 ( union V_109 * T_4 V_110 ,
struct V_111 * * T_5 V_110 )
{
F_28 ( L_13 ) ;
return 0 ;
}
static int F_53 ( struct V_28 * V_29 V_110 ,
union V_109 * T_4 V_110 ,
struct V_112 * T_6 V_110 ,
struct V_87 * V_88 V_110 ,
struct V_47 * V_47 V_110 )
{
F_28 ( L_13 ) ;
return 0 ;
}
static int F_54 ( struct V_28 * V_29 V_110 ,
union V_109 * T_4 V_110 ,
struct V_112 * T_6 V_110 ,
struct V_47 * V_47 V_110 )
{
F_28 ( L_13 ) ;
return 0 ;
}
static int F_55 ( struct V_28 * V_29 V_110 ,
union V_109 * T_4 V_110 ,
struct V_1 * V_1 V_110 )
{
F_28 ( L_13 ) ;
return 0 ;
}
static int F_56 ( struct V_28 * V_29 V_110 ,
union V_109 * T_4 V_110 )
{
F_28 ( L_13 ) ;
return 0 ;
}
static void F_57 ( struct V_28 * V_29 )
{
if ( V_29 -> T_6 == NULL )
V_29 -> T_6 = F_53 ;
if ( V_29 -> V_113 == NULL )
V_29 -> V_113 = F_54 ;
if ( V_29 -> V_114 == NULL )
V_29 -> V_114 = F_54 ;
if ( V_29 -> V_115 == NULL )
V_29 -> V_115 = F_54 ;
if ( V_29 -> exit == NULL )
V_29 -> exit = F_54 ;
if ( V_29 -> V_116 == NULL )
V_29 -> V_116 = V_117 ;
if ( V_29 -> V_118 == NULL )
V_29 -> V_118 = F_53 ;
if ( V_29 -> V_119 == NULL )
V_29 -> V_119 = F_54 ;
if ( V_29 -> V_120 == NULL )
V_29 -> V_120 = F_54 ;
if ( V_29 -> V_121 == NULL )
V_29 -> V_121 = F_52 ;
if ( V_29 -> V_122 == NULL )
V_29 -> V_122 = F_56 ;
if ( V_29 -> V_123 == NULL )
V_29 -> V_123 = F_51 ;
if ( V_29 -> V_124 == NULL )
V_29 -> V_124 = F_55 ;
if ( V_29 -> V_125 == NULL ) {
if ( V_29 -> V_38 )
V_29 -> V_125 = V_126 ;
else
V_29 -> V_125 = F_55 ;
}
}
void F_58 ( void * V_127 , int V_128 )
{
T_2 * V_69 = V_127 ;
while ( V_128 > 0 ) {
* V_69 = F_59 ( * V_69 ) ;
V_128 -= sizeof( T_2 ) ;
++ V_69 ;
}
}
static void F_60 ( union V_109 * T_4 )
{
struct V_129 * V_130 = & T_4 -> V_131 ;
F_58 ( V_130 + 1 , T_4 -> V_131 . V_18 - sizeof( * V_130 ) ) ;
}
static void F_61 ( union V_109 * T_4 )
{
T_4 -> V_114 . V_132 = F_62 ( T_4 -> V_114 . V_132 ) ;
T_4 -> V_114 . V_133 = F_62 ( T_4 -> V_114 . V_133 ) ;
}
static void F_63 ( union V_109 * T_4 )
{
T_4 -> V_113 . V_132 = F_62 ( T_4 -> V_113 . V_132 ) ;
T_4 -> V_113 . V_133 = F_62 ( T_4 -> V_113 . V_133 ) ;
T_4 -> V_113 . V_134 = F_59 ( T_4 -> V_113 . V_134 ) ;
T_4 -> V_113 . V_31 = F_59 ( T_4 -> V_113 . V_31 ) ;
T_4 -> V_113 . V_135 = F_59 ( T_4 -> V_113 . V_135 ) ;
}
static void F_64 ( union V_109 * T_4 )
{
T_4 -> V_115 . V_132 = F_62 ( T_4 -> V_115 . V_132 ) ;
T_4 -> V_115 . V_133 = F_62 ( T_4 -> V_115 . V_133 ) ;
T_4 -> V_115 . V_136 = F_62 ( T_4 -> V_115 . V_136 ) ;
T_4 -> V_115 . V_137 = F_62 ( T_4 -> V_115 . V_137 ) ;
T_4 -> V_115 . time = F_59 ( T_4 -> V_115 . time ) ;
}
static void F_65 ( union V_109 * T_4 )
{
T_4 -> V_118 . V_132 = F_62 ( T_4 -> V_118 . V_132 ) ;
T_4 -> V_118 . V_133 = F_62 ( T_4 -> V_118 . V_133 ) ;
T_4 -> V_118 . V_138 = F_59 ( T_4 -> V_118 . V_138 ) ;
T_4 -> V_118 . V_139 = F_59 ( T_4 -> V_118 . V_139 ) ;
T_4 -> V_118 . V_140 = F_59 ( T_4 -> V_118 . V_140 ) ;
T_4 -> V_118 . V_141 = F_59 ( T_4 -> V_118 . V_141 ) ;
}
void F_66 ( struct V_142 * V_121 )
{
V_121 -> type = F_62 ( V_121 -> type ) ;
V_121 -> V_18 = F_62 ( V_121 -> V_18 ) ;
V_121 -> V_143 = F_59 ( V_121 -> V_143 ) ;
V_121 -> V_144 = F_59 ( V_121 -> V_144 ) ;
V_121 -> V_19 = F_59 ( V_121 -> V_19 ) ;
V_121 -> V_145 = F_59 ( V_121 -> V_145 ) ;
V_121 -> V_146 = F_62 ( V_121 -> V_146 ) ;
V_121 -> V_147 = F_62 ( V_121 -> V_147 ) ;
V_121 -> V_148 = F_59 ( V_121 -> V_148 ) ;
V_121 -> V_149 = F_59 ( V_121 -> V_149 ) ;
}
static void F_67 ( union V_109 * T_4 )
{
T_1 V_18 ;
F_66 ( & T_4 -> V_121 . V_121 ) ;
V_18 = T_4 -> V_131 . V_18 ;
V_18 -= ( void * ) & T_4 -> V_121 . V_141 - ( void * ) T_4 ;
F_58 ( T_4 -> V_121 . V_141 , V_18 ) ;
}
static void F_68 ( union V_109 * T_4 )
{
T_4 -> V_122 . V_122 . V_150 =
F_59 ( T_4 -> V_122 . V_122 . V_150 ) ;
}
static void F_69 ( union V_109 * T_4 )
{
T_4 -> V_123 . V_18 = F_62 ( T_4 -> V_123 . V_18 ) ;
}
static void F_70 ( struct V_1 * V_52 )
{
struct V_38 * V_151 = & V_52 -> V_38 ;
while ( ! F_71 ( & V_151 -> V_41 ) ) {
struct V_152 * V_153 ;
V_153 = F_72 ( V_151 -> V_41 . V_154 , struct V_152 , V_155 ) ;
F_32 ( & V_153 -> V_155 ) ;
free ( V_153 ) ;
}
}
static void F_73 ( struct V_1 * V_156 ,
struct V_28 * V_29 )
{
struct V_38 * V_151 = & V_156 -> V_38 ;
struct V_157 * V_158 = & V_151 -> V_39 ;
struct V_152 * V_159 , * V_160 ;
struct V_112 T_6 ;
T_2 V_161 = V_151 -> V_162 ;
T_2 V_163 = V_151 -> V_164 ? V_151 -> V_164 -> V_165 : 0ULL ;
unsigned V_166 = 0 , V_167 = V_151 -> V_168 / 16 ;
int V_24 ;
if ( ! V_29 -> V_38 || ! V_161 )
return;
F_31 (iter, tmp, head, list) {
if ( V_160 -> V_165 > V_161 )
break;
V_24 = F_74 ( V_156 , V_160 -> T_4 , & T_6 ) ;
if ( V_24 )
F_3 ( L_14 , V_24 ) ;
else
F_75 ( V_156 , V_160 -> T_4 , & T_6 , V_29 ,
V_160 -> V_169 ) ;
V_151 -> V_170 = V_160 -> V_165 ;
F_32 ( & V_160 -> V_155 ) ;
F_76 ( & V_160 -> V_155 , & V_151 -> V_40 ) ;
if ( ++ V_166 >= V_167 ) {
V_167 += V_151 -> V_168 / 16 ;
F_77 ( V_166 , V_151 -> V_168 ,
L_15 ) ;
}
}
if ( F_71 ( V_158 ) ) {
V_151 -> V_164 = NULL ;
} else if ( V_163 <= V_161 ) {
V_151 -> V_164 =
F_72 ( V_158 -> V_171 , struct V_152 , V_155 ) ;
}
V_151 -> V_168 = 0 ;
}
static int V_126 ( struct V_28 * V_29 ,
union V_109 * T_4 V_110 ,
struct V_1 * V_52 )
{
F_73 ( V_52 , V_29 ) ;
V_52 -> V_38 . V_162 = V_52 -> V_38 . V_172 ;
return 0 ;
}
static void F_78 ( struct V_152 * V_173 , struct V_1 * V_156 )
{
struct V_38 * V_151 = & V_156 -> V_38 ;
struct V_152 * T_6 = V_151 -> V_164 ;
T_2 V_165 = V_173 -> V_165 ;
struct V_157 * V_174 ;
++ V_151 -> V_168 ;
V_151 -> V_164 = V_173 ;
if ( ! T_6 ) {
F_76 ( & V_173 -> V_155 , & V_151 -> V_39 ) ;
V_151 -> V_172 = V_165 ;
return;
}
if ( T_6 -> V_165 <= V_165 ) {
while ( T_6 -> V_165 <= V_165 ) {
V_174 = T_6 -> V_155 . V_154 ;
if ( V_174 == & V_151 -> V_39 ) {
F_43 ( & V_173 -> V_155 , & V_151 -> V_39 ) ;
V_151 -> V_172 = V_165 ;
return;
}
T_6 = F_72 ( V_174 , struct V_152 , V_155 ) ;
}
F_43 ( & V_173 -> V_155 , & T_6 -> V_155 ) ;
} else {
while ( T_6 -> V_165 > V_165 ) {
V_174 = T_6 -> V_155 . V_171 ;
if ( V_174 == & V_151 -> V_39 ) {
F_76 ( & V_173 -> V_155 , & V_151 -> V_39 ) ;
return;
}
T_6 = F_72 ( V_174 , struct V_152 , V_155 ) ;
}
F_76 ( & V_173 -> V_155 , & T_6 -> V_155 ) ;
}
}
static int F_79 ( struct V_1 * V_156 , union V_109 * T_4 ,
struct V_112 * T_6 , T_2 V_169 )
{
struct V_38 * V_151 = & V_156 -> V_38 ;
struct V_157 * V_175 = & V_151 -> V_40 ;
T_2 V_165 = T_6 -> time ;
struct V_152 * V_173 ;
if ( ! V_165 || V_165 == ~ 0ULL )
return - V_176 ;
if ( V_165 < V_156 -> V_38 . V_170 ) {
printf ( L_16 ) ;
return - V_177 ;
}
if ( ! F_71 ( V_175 ) ) {
V_173 = F_72 ( V_175 -> V_154 , struct V_152 , V_155 ) ;
F_32 ( & V_173 -> V_155 ) ;
} else if ( V_151 -> V_178 ) {
V_173 = V_151 -> V_178 + V_151 -> V_179 ;
if ( ++ V_151 -> V_179 == V_180 )
V_151 -> V_178 = NULL ;
} else {
V_151 -> V_178 = malloc ( V_180 * sizeof( * V_173 ) ) ;
if ( ! V_151 -> V_178 )
return - V_181 ;
F_76 ( & V_151 -> V_178 -> V_155 , & V_151 -> V_41 ) ;
V_151 -> V_179 = 2 ;
V_173 = V_151 -> V_178 + 1 ;
}
V_173 -> V_165 = V_165 ;
V_173 -> V_169 = V_169 ;
V_173 -> T_4 = T_4 ;
F_78 ( V_173 , V_156 ) ;
return 0 ;
}
static void F_80 ( struct V_112 * T_6 )
{
unsigned int V_68 ;
printf ( L_17 V_182 L_6 , T_6 -> V_183 -> V_82 ) ;
for ( V_68 = 0 ; V_68 < T_6 -> V_183 -> V_82 ; V_68 ++ )
printf ( L_18 V_184 L_6 ,
V_68 , T_6 -> V_183 -> V_98 [ V_68 ] ) ;
}
static void F_81 ( struct V_112 * T_6 )
{
T_7 V_68 ;
printf ( L_19 V_182 L_6 , T_6 -> V_79 -> V_82 ) ;
for ( V_68 = 0 ; V_68 < T_6 -> V_79 -> V_82 ; V_68 ++ )
printf ( L_20 V_182 L_21 V_184 L_22 V_184 L_6 ,
V_68 , T_6 -> V_79 -> V_84 [ V_68 ] . V_85 ,
T_6 -> V_79 -> V_84 [ V_68 ] . V_83 ) ;
}
static void F_82 ( struct V_1 * V_52 ,
union V_109 * T_4 ,
struct V_112 * T_6 )
{
if ( T_4 -> V_131 . type != V_185 &&
! V_52 -> V_21 ) {
fputs ( L_23 , stdout ) ;
return;
}
if ( ( V_52 -> V_19 & V_186 ) )
printf ( L_24 , T_6 -> V_187 ) ;
if ( V_52 -> V_19 & V_188 )
printf ( L_25 V_182 L_26 , T_6 -> time ) ;
}
static void F_83 ( struct V_1 * V_52 , union V_109 * T_4 ,
T_2 V_169 , struct V_112 * T_6 )
{
if ( ! V_189 )
return;
printf ( L_27 V_184 L_28 ,
V_169 , T_4 -> V_131 . V_18 , T_4 -> V_131 . type ) ;
F_84 ( T_4 ) ;
if ( T_6 )
F_82 ( V_52 , T_4 , T_6 ) ;
printf ( L_29 V_184 L_30 , V_169 ,
T_4 -> V_131 . V_18 , F_85 ( T_4 -> V_131 . type ) ) ;
}
static void F_86 ( struct V_1 * V_52 , union V_109 * T_4 ,
struct V_112 * T_6 )
{
if ( ! V_189 )
return;
printf ( L_31 V_184 L_32 V_182 L_33 V_184 L_6 ,
T_4 -> V_131 . V_190 , T_6 -> V_132 , T_6 -> V_133 , T_6 -> V_65 ,
T_6 -> V_191 , T_6 -> V_74 ) ;
if ( V_52 -> V_19 & V_192 )
F_80 ( T_6 ) ;
if ( V_52 -> V_19 & V_193 )
F_81 ( T_6 ) ;
}
static struct V_47 *
F_87 ( struct V_1 * V_52 ,
union V_109 * T_4 )
{
const T_3 V_92 = T_4 -> V_131 . V_190 & V_194 ;
if ( V_92 == V_195 && V_196 ) {
T_8 V_132 ;
if ( T_4 -> V_131 . type == V_197 )
V_132 = T_4 -> V_113 . V_132 ;
else
V_132 = T_4 -> V_65 . V_132 ;
return F_88 ( V_52 , V_132 ) ;
}
return F_89 ( V_52 ) ;
}
static int F_75 ( struct V_1 * V_52 ,
union V_109 * T_4 ,
struct V_112 * T_6 ,
struct V_28 * V_29 ,
T_2 V_169 )
{
struct V_87 * V_88 ;
struct V_47 * V_47 ;
F_83 ( V_52 , T_4 , V_169 , T_6 ) ;
V_88 = F_90 ( V_52 -> V_17 , T_6 -> V_141 ) ;
if ( V_88 != NULL && T_4 -> V_131 . type != V_185 ) {
F_91 ( & V_88 -> V_43 , T_4 -> V_131 . type ) ;
}
V_47 = F_87 ( V_52 , T_4 ) ;
switch ( T_4 -> V_131 . type ) {
case V_185 :
F_86 ( V_52 , T_4 , T_6 ) ;
if ( V_88 == NULL ) {
++ V_52 -> V_43 . V_198 . V_199 ;
return 0 ;
}
if ( V_47 == NULL ) {
++ V_52 -> V_43 . V_198 . V_200 ;
return 0 ;
}
return V_29 -> T_6 ( V_29 , T_4 , T_6 , V_88 , V_47 ) ;
case V_197 :
return V_29 -> V_113 ( V_29 , T_4 , T_6 , V_47 ) ;
case V_201 :
return V_29 -> V_114 ( V_29 , T_4 , T_6 , V_47 ) ;
case V_202 :
return V_29 -> V_115 ( V_29 , T_4 , T_6 , V_47 ) ;
case V_203 :
return V_29 -> exit ( V_29 , T_4 , T_6 , V_47 ) ;
case V_204 :
if ( V_29 -> V_116 == V_117 )
V_52 -> V_43 . V_198 . V_205 += T_4 -> V_116 . V_116 ;
return V_29 -> V_116 ( V_29 , T_4 , T_6 , V_47 ) ;
case V_206 :
return V_29 -> V_118 ( V_29 , T_4 , T_6 , V_88 , V_47 ) ;
case V_207 :
return V_29 -> V_119 ( V_29 , T_4 , T_6 , V_47 ) ;
case V_208 :
return V_29 -> V_120 ( V_29 , T_4 , T_6 , V_47 ) ;
default:
++ V_52 -> V_43 . V_198 . V_209 ;
return - 1 ;
}
}
static int F_92 ( struct V_1 * V_52 ,
union V_109 * T_4 , struct V_112 * T_6 )
{
if ( T_4 -> V_131 . type != V_185 ||
! ( V_52 -> V_19 & V_192 ) )
return 0 ;
if ( ! F_93 ( T_6 -> V_183 , T_4 ) ) {
F_94 ( L_34 ) ;
++ V_52 -> V_43 . V_198 . V_210 ;
V_52 -> V_43 . V_198 . V_211 += T_6 -> V_191 ;
return - V_177 ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_52 , union V_109 * T_4 ,
struct V_28 * V_29 , T_2 V_169 )
{
int V_11 ;
F_83 ( V_52 , T_4 , V_169 , NULL ) ;
switch ( T_4 -> V_131 . type ) {
case V_212 :
V_11 = V_29 -> V_121 ( T_4 , & V_52 -> V_17 ) ;
if ( V_11 == 0 )
F_11 ( V_52 ) ;
return V_11 ;
case V_213 :
return V_29 -> V_122 ( V_29 , T_4 ) ;
case V_214 :
F_96 ( V_52 -> V_8 , V_169 , V_215 ) ;
return V_29 -> V_123 ( T_4 , V_52 ) ;
case V_216 :
return V_29 -> V_124 ( V_29 , T_4 , V_52 ) ;
case V_217 :
return V_29 -> V_125 ( V_29 , T_4 , V_52 ) ;
default:
return - V_177 ;
}
}
static int F_97 ( struct V_1 * V_52 ,
union V_109 * T_4 ,
struct V_28 * V_29 ,
T_2 V_169 )
{
struct V_112 T_6 ;
int V_24 ;
if ( V_52 -> V_131 . V_218 &&
V_219 [ T_4 -> V_131 . type ] )
V_219 [ T_4 -> V_131 . type ] ( T_4 ) ;
if ( T_4 -> V_131 . type >= V_220 )
return - V_177 ;
F_91 ( & V_52 -> V_43 , T_4 -> V_131 . type ) ;
if ( T_4 -> V_131 . type >= V_221 )
return F_95 ( V_52 , T_4 , V_29 , V_169 ) ;
V_24 = F_74 ( V_52 , T_4 , & T_6 ) ;
if ( V_24 )
return V_24 ;
if ( F_92 ( V_52 , T_4 , & T_6 ) )
return 0 ;
if ( V_29 -> V_38 ) {
V_24 = F_79 ( V_52 , T_4 , & T_6 ,
V_169 ) ;
if ( V_24 != - V_176 )
return V_24 ;
}
return F_75 ( V_52 , T_4 , & T_6 , V_29 ,
V_169 ) ;
}
void F_98 ( struct V_129 * V_2 )
{
V_2 -> type = F_62 ( V_2 -> type ) ;
V_2 -> V_190 = F_99 ( V_2 -> V_190 ) ;
V_2 -> V_18 = F_99 ( V_2 -> V_18 ) ;
}
struct V_48 * F_100 ( struct V_1 * V_52 , T_9 V_132 )
{
return F_101 ( & V_52 -> V_23 , V_132 ) ;
}
static struct V_48 * F_102 ( struct V_1 * V_2 )
{
struct V_48 * V_48 = F_100 ( V_2 , 0 ) ;
if ( V_48 == NULL || F_103 ( V_48 , L_35 ) ) {
F_3 ( L_36 ) ;
V_48 = NULL ;
}
return V_48 ;
}
static void F_104 ( const struct V_1 * V_52 ,
const struct V_28 * V_29 )
{
if ( V_29 -> V_116 == V_117 &&
V_52 -> V_43 . V_198 . V_222 [ V_204 ] != 0 ) {
F_105 ( L_37
L_38 ,
V_52 -> V_43 . V_198 . V_222 [ 0 ] ,
V_52 -> V_43 . V_198 . V_222 [ V_204 ] ) ;
}
if ( V_52 -> V_43 . V_198 . V_209 != 0 ) {
F_105 ( L_39
L_40
L_41
L_42
L_43 ,
V_52 -> V_43 . V_198 . V_209 ) ;
}
if ( V_52 -> V_43 . V_198 . V_199 != 0 ) {
F_105 ( L_44 ,
V_52 -> V_43 . V_198 . V_199 ) ;
}
if ( V_52 -> V_43 . V_198 . V_210 != 0 ) {
F_105 ( L_45
L_46
L_47 ,
V_52 -> V_43 . V_198 . V_210 ,
V_52 -> V_43 . V_198 . V_222 [ V_185 ] ) ;
}
if ( V_52 -> V_43 . V_198 . V_200 != 0 ) {
F_105 ( L_48
L_49 ,
V_52 -> V_43 . V_198 . V_200 ) ;
}
}
static int F_106 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
union V_109 T_4 ;
T_10 V_18 ;
int V_223 = 0 ;
T_2 V_158 ;
int V_11 ;
void * V_174 ;
F_57 ( V_29 ) ;
V_158 = 0 ;
V_224:
V_11 = F_107 ( V_2 -> V_8 , & T_4 , sizeof( struct V_129 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 )
goto V_225;
F_3 ( L_50 ) ;
goto V_226;
}
if ( V_2 -> V_131 . V_218 )
F_98 ( & T_4 . V_131 ) ;
V_18 = T_4 . V_131 . V_18 ;
if ( V_18 == 0 )
V_18 = 8 ;
V_174 = & T_4 ;
V_174 += sizeof( struct V_129 ) ;
if ( V_18 - sizeof( struct V_129 ) ) {
V_11 = F_107 ( V_2 -> V_8 , V_174 , V_18 - sizeof( struct V_129 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 ) {
F_3 ( L_51 ) ;
goto V_225;
}
F_3 ( L_52 ) ;
goto V_226;
}
}
if ( ( V_223 = F_97 ( V_2 , & T_4 , V_29 , V_158 ) ) < 0 ) {
F_28 ( L_29 V_184 L_53 ,
V_158 , T_4 . V_131 . V_18 , T_4 . V_131 . type ) ;
if ( F_108 ( V_158 & 7 ) )
V_158 &= ~ 7ULL ;
V_18 = 8 ;
}
V_158 += V_18 ;
if ( V_223 > 0 )
V_158 += V_223 ;
if ( ! F_109 () )
goto V_224;
V_225:
V_11 = 0 ;
V_226:
F_104 ( V_2 , V_29 ) ;
F_70 ( V_2 ) ;
return V_11 ;
}
static union V_109 *
F_110 ( struct V_1 * V_52 ,
T_2 V_158 , T_1 V_227 , char * V_228 )
{
union V_109 * T_4 ;
if ( V_158 + sizeof( T_4 -> V_131 ) > V_227 )
return NULL ;
T_4 = (union V_109 * ) ( V_228 + V_158 ) ;
if ( V_52 -> V_131 . V_218 )
F_98 ( & T_4 -> V_131 ) ;
if ( V_158 + T_4 -> V_131 . V_18 > V_227 )
return NULL ;
return T_4 ;
}
int F_111 ( struct V_1 * V_52 ,
T_2 V_229 , T_2 V_230 ,
T_2 V_231 , struct V_28 * V_29 )
{
T_2 V_158 , V_232 , V_169 , V_233 , V_167 ;
int V_11 , V_234 , V_235 , V_236 = 0 ;
T_1 V_237 , V_227 ;
char * V_228 , * V_238 [ 8 ] ;
union V_109 * T_4 ;
T_10 V_18 ;
F_57 ( V_29 ) ;
V_237 = F_112 ( V_239 ) ;
V_232 = V_237 * ( V_229 / V_237 ) ;
V_169 = V_232 ;
V_158 = V_229 - V_232 ;
if ( V_229 + V_230 < V_231 )
V_231 = V_229 + V_230 ;
V_167 = V_231 / 16 ;
V_227 = V_52 -> V_35 ;
if ( V_227 > V_231 )
V_227 = V_231 ;
memset ( V_238 , 0 , sizeof( V_238 ) ) ;
V_234 = V_240 ;
V_235 = V_241 ;
if ( V_52 -> V_131 . V_218 ) {
V_234 |= V_242 ;
V_235 = V_243 ;
}
V_244:
V_228 = V_113 ( NULL , V_227 , V_234 , V_235 , V_52 -> V_8 ,
V_169 ) ;
if ( V_228 == V_245 ) {
F_3 ( L_54 ) ;
V_11 = - V_12 ;
goto V_226;
}
V_238 [ V_236 ] = V_228 ;
V_236 = ( V_236 + 1 ) & ( F_113 ( V_238 ) - 1 ) ;
V_233 = V_169 + V_158 ;
V_224:
T_4 = F_110 ( V_52 , V_158 , V_227 , V_228 ) ;
if ( ! T_4 ) {
if ( V_238 [ V_236 ] ) {
F_114 ( V_238 [ V_236 ] , V_227 ) ;
V_238 [ V_236 ] = NULL ;
}
V_232 = V_237 * ( V_158 / V_237 ) ;
V_169 += V_232 ;
V_158 -= V_232 ;
goto V_244;
}
V_18 = T_4 -> V_131 . V_18 ;
if ( V_18 == 0 ||
F_97 ( V_52 , T_4 , V_29 , V_233 ) < 0 ) {
F_28 ( L_29 V_184 L_53 ,
V_169 + V_158 , T_4 -> V_131 . V_18 ,
T_4 -> V_131 . type ) ;
if ( F_108 ( V_158 & 7 ) )
V_158 &= ~ 7ULL ;
V_18 = 8 ;
}
V_158 += V_18 ;
V_233 += V_18 ;
if ( V_233 >= V_167 ) {
V_167 += V_231 / 16 ;
F_77 ( V_233 , V_231 ,
L_55 ) ;
}
if ( V_233 < V_231 )
goto V_224;
V_11 = 0 ;
V_52 -> V_38 . V_162 = V_36 ;
F_73 ( V_52 , V_29 ) ;
V_226:
F_104 ( V_52 , V_29 ) ;
F_70 ( V_52 ) ;
return V_11 ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
int V_11 ;
if ( F_102 ( V_2 ) == NULL )
return - V_181 ;
if ( ! V_2 -> V_7 )
V_11 = F_111 ( V_2 ,
V_2 -> V_131 . V_229 ,
V_2 -> V_131 . V_230 ,
V_2 -> V_18 , V_29 ) ;
else
V_11 = F_106 ( V_2 , V_29 ) ;
return V_11 ;
}
bool F_116 ( struct V_1 * V_2 , const char * V_246 )
{
if ( ! ( V_2 -> V_19 & V_247 ) ) {
F_3 ( L_56 , V_246 ) ;
return false ;
}
return true ;
}
int F_117 ( struct V_76 * * V_248 ,
const char * V_249 , T_2 V_74 )
{
char * V_250 ;
enum V_251 V_68 ;
struct V_252 * V_253 ;
V_253 = F_24 ( sizeof( struct V_252 ) ) ;
if ( V_253 == NULL )
return - V_181 ;
V_253 -> V_61 = F_118 ( V_249 ) ;
if ( V_253 -> V_61 == NULL ) {
free ( V_253 ) ;
return - V_181 ;
}
V_250 = strchr ( V_253 -> V_61 , ']' ) ;
if ( V_250 )
* V_250 = '\0' ;
V_253 -> V_74 = V_74 ;
for ( V_68 = 0 ; V_68 < V_254 ; ++ V_68 ) {
struct V_255 * V_255 = F_119 ( V_248 [ V_68 ] ) ;
V_255 -> V_252 = V_253 ;
}
return 0 ;
}
T_1 F_120 ( struct V_1 * V_2 , T_11 * V_256 )
{
return F_121 ( & V_2 -> V_23 . V_257 , V_256 ) +
F_121 ( & V_2 -> V_23 . V_258 , V_256 ) +
F_122 ( & V_2 -> V_25 , V_256 ) ;
}
T_1 F_123 ( struct V_1 * V_2 , T_11 * V_256 ,
bool V_259 )
{
T_1 V_24 = F_124 ( & V_2 -> V_23 , V_256 , V_259 ) ;
return V_24 + F_125 ( & V_2 -> V_25 , V_256 , V_259 ) ;
}
T_1 F_126 ( struct V_1 * V_52 , T_11 * V_256 )
{
struct V_87 * V_260 ;
T_1 V_24 = fprintf ( V_256 , L_57 ) ;
V_24 += F_127 ( & V_52 -> V_43 , V_256 ) ;
F_128 (pos, &session->evlist->entries, node) {
V_24 += fprintf ( V_256 , L_58 , F_129 ( V_260 ) ) ;
V_24 += F_127 ( & V_260 -> V_43 , V_256 ) ;
}
return V_24 ;
}
T_1 F_130 ( struct V_1 * V_52 , T_11 * V_256 )
{
return F_131 ( & V_52 -> V_23 , V_256 ) ;
}
void F_132 ( struct V_1 * V_52 ,
struct V_48 * V_56 )
{
F_42 ( & V_52 -> V_23 , V_56 ) ;
}
struct V_87 * F_133 ( struct V_1 * V_52 ,
unsigned int type )
{
struct V_87 * V_260 ;
F_128 (pos, &session->evlist->entries, node) {
if ( V_260 -> V_121 . type == type )
return V_260 ;
}
return NULL ;
}
void F_134 ( union V_109 * T_4 , struct V_112 * T_6 ,
struct V_47 * V_47 , struct V_87 * V_88 ,
int V_261 , int V_262 , int V_263 )
{
struct V_66 V_67 ;
struct V_94 * V_264 = & V_88 -> V_43 . V_94 ;
struct V_265 * V_51 ;
if ( F_135 ( T_4 , V_47 , & V_67 , T_6 ,
NULL ) < 0 ) {
error ( L_59 ,
T_4 -> V_131 . type ) ;
return;
}
if ( V_107 . V_108 && T_6 -> V_183 ) {
if ( F_48 ( V_47 , V_88 , V_67 . V_48 ,
T_6 -> V_183 , NULL ) != 0 ) {
if ( V_266 )
error ( L_60 ) ;
return;
}
F_136 ( V_264 ) ;
while ( 1 ) {
V_51 = F_137 ( V_264 ) ;
if ( ! V_51 )
break;
printf ( L_61 V_184 , V_51 -> V_65 ) ;
if ( V_261 ) {
printf ( L_26 ) ;
F_138 ( V_51 -> V_60 , stdout ) ;
}
if ( V_262 ) {
printf ( L_62 ) ;
F_139 ( V_67 . V_76 , stdout ) ;
printf ( L_63 ) ;
}
printf ( L_6 ) ;
F_140 ( V_264 ) ;
}
} else {
printf ( L_64 V_184 , T_6 -> V_65 ) ;
if ( V_261 ) {
printf ( L_26 ) ;
if ( V_263 )
F_141 ( V_67 . V_60 , & V_67 ,
stdout ) ;
else
F_138 ( V_67 . V_60 , stdout ) ;
}
if ( V_262 ) {
printf ( L_62 ) ;
F_139 ( V_67 . V_76 , stdout ) ;
printf ( L_63 ) ;
}
}
}
int F_142 ( struct V_1 * V_52 ,
const char * V_267 , unsigned long * V_268 )
{
int V_68 ;
struct V_269 * V_76 ;
for ( V_68 = 0 ; V_68 < V_270 ; ++ V_68 ) {
struct V_87 * V_88 ;
V_88 = F_133 ( V_52 , V_68 ) ;
if ( ! V_88 )
continue;
if ( ! ( V_88 -> V_121 . V_19 & V_186 ) ) {
F_3 ( L_65
L_66 ) ;
return - 1 ;
}
}
V_76 = F_143 ( V_267 ) ;
if ( V_76 == NULL ) {
F_3 ( L_67 ) ;
return - 1 ;
}
for ( V_68 = 0 ; V_68 < V_76 -> V_82 ; V_68 ++ ) {
int V_187 = V_76 -> V_76 [ V_68 ] ;
if ( V_187 >= V_271 ) {
F_3 ( L_68
L_69 , V_187 ) ;
return - 1 ;
}
F_144 ( V_187 , V_268 ) ;
}
return 0 ;
}
void F_145 ( struct V_1 * V_52 , T_11 * V_256 ,
bool V_272 )
{
struct V_4 V_30 ;
int V_24 ;
if ( V_52 == NULL || V_256 == NULL )
return;
V_24 = F_5 ( V_52 -> V_8 , & V_30 ) ;
if ( V_24 == - 1 )
return;
fprintf ( V_256 , L_70 ) ;
fprintf ( V_256 , L_71 , ctime ( & V_30 . V_273 ) ) ;
F_146 ( V_52 , V_256 , V_272 ) ;
fprintf ( V_256 , L_72 ) ;
}

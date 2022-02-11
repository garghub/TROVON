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
static void F_11 ( struct V_1 * V_19 )
{
struct V_20 * V_21 ;
T_1 V_22 = V_19 -> V_22 ;
T_2 V_18 = 0 ;
if ( ! V_19 -> V_23 )
goto V_24;
if ( V_22 & V_25 )
V_18 += sizeof( V_21 -> V_26 ) * 2 ;
if ( V_22 & V_27 )
V_18 += sizeof( V_21 -> time ) ;
if ( V_22 & V_28 )
V_18 += sizeof( V_21 -> V_29 ) ;
if ( V_22 & V_30 )
V_18 += sizeof( V_21 -> V_31 ) ;
if ( V_22 & V_32 )
V_18 += sizeof( V_21 -> V_33 ) * 2 ;
V_24:
V_19 -> V_34 = V_18 ;
}
void F_12 ( struct V_1 * V_2 )
{
V_2 -> V_22 = F_13 ( V_2 -> V_17 ) ;
V_2 -> V_35 = F_14 ( V_2 -> V_22 ) ;
V_2 -> V_23 = F_15 ( V_2 -> V_17 ) ;
F_11 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_36 = F_17 ( & V_2 -> V_37 ) ;
if ( V_36 >= 0 )
V_36 = F_18 ( & V_2 -> V_38 ) ;
return V_36 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( & V_2 -> V_37 ) ;
F_21 ( & V_2 -> V_38 ) ;
}
struct V_1 * F_22 ( const char * V_6 , int V_39 ,
bool V_3 , bool V_40 ,
struct V_41 * V_42 )
{
T_3 V_43 = V_6 ? strlen ( V_6 ) + 1 : 0 ;
struct V_1 * V_2 = F_23 ( sizeof( * V_2 ) + V_43 ) ;
if ( V_2 == NULL )
goto V_24;
memcpy ( V_2 -> V_6 , V_6 , V_43 ) ;
V_2 -> V_44 = V_45 ;
F_24 ( & V_2 -> V_46 ) ;
V_2 -> V_47 = NULL ;
#if V_48 == 64
V_2 -> V_49 = V_50 ;
#else
V_2 -> V_49 = 32 * 1024 * 1024ULL ;
#endif
V_2 -> V_38 = V_45 ;
V_2 -> V_40 = V_40 ;
F_24 ( & V_2 -> V_51 . V_52 ) ;
F_24 ( & V_2 -> V_51 . V_53 ) ;
F_24 ( & V_2 -> V_51 . V_54 ) ;
F_25 ( & V_2 -> V_37 , L_11 , V_55 ) ;
if ( V_39 == V_10 ) {
if ( F_1 ( V_2 , V_3 ) < 0 )
goto V_56;
F_12 ( V_2 ) ;
} else if ( V_39 == V_57 ) {
if ( F_16 ( V_2 ) < 0 )
goto V_56;
}
if ( V_42 && V_42 -> V_58 &&
V_42 -> V_51 && ! V_2 -> V_23 ) {
F_26 ( L_12 ) ;
V_42 -> V_51 = false ;
}
V_24:
return V_2 ;
V_56:
F_27 ( V_2 ) ;
return NULL ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_59 * V_60 , * V_61 ;
F_29 (t, n, &self->dead_threads, node) {
F_30 ( & V_61 -> V_62 ) ;
F_31 ( V_61 ) ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = F_33 ( & V_2 -> V_44 ) ;
while ( V_64 ) {
struct V_59 * V_61 = F_34 ( V_64 , struct V_59 , V_63 ) ;
F_35 ( & V_61 -> V_63 , & V_2 -> V_44 ) ;
V_64 = F_36 ( V_64 ) ;
F_31 ( V_61 ) ;
}
}
void F_27 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_28 ( V_2 ) ;
F_32 ( V_2 ) ;
F_37 ( & V_2 -> V_37 ) ;
F_10 ( V_2 -> V_8 ) ;
free ( V_2 ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_59 * V_65 )
{
V_2 -> V_47 = NULL ;
F_35 ( & V_65 -> V_63 , & V_2 -> V_44 ) ;
F_39 ( & V_65 -> V_62 , & V_2 -> V_46 ) ;
}
static bool F_40 ( struct V_66 * V_67 )
{
if ( V_67 -> V_68 && ! regexec ( & V_69 , V_67 -> V_68 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_59 * V_59 ,
struct V_70 * V_71 ,
struct V_66 * * V_72 )
{
T_4 V_73 = V_74 ;
unsigned int V_75 ;
int V_11 ;
F_42 ( & V_2 -> V_76 ) ;
for ( V_75 = 0 ; V_75 < V_71 -> V_77 ; V_75 ++ ) {
T_1 V_78 ;
struct V_79 V_80 ;
if ( V_81 . V_82 == V_83 )
V_78 = V_71 -> V_84 [ V_75 ] ;
else
V_78 = V_71 -> V_84 [ V_71 -> V_77 - V_75 - 1 ] ;
if ( V_78 >= V_85 ) {
switch ( V_78 ) {
case V_86 :
V_73 = V_87 ; break;
case V_88 :
V_73 = V_89 ; break;
case V_90 :
V_73 = V_74 ; break;
default:
break;
}
continue;
}
V_80 . V_91 = false ;
F_43 ( V_59 , V_2 , V_73 ,
V_92 , V_59 -> V_93 , V_78 , & V_80 , NULL ) ;
if ( V_80 . V_67 != NULL ) {
if ( V_94 && ! * V_72 &&
F_40 ( V_80 . V_67 ) )
* V_72 = V_80 . V_67 ;
if ( ! V_95 . V_96 )
break;
}
V_11 = F_44 ( & V_2 -> V_76 ,
V_78 , V_80 . V_97 , V_80 . V_67 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_45 ( union V_98 * T_5 V_99 ,
struct V_1 * V_19 V_99 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static int F_46 ( union V_98 * T_5 V_99 ,
struct V_20 * T_6 V_99 ,
struct V_100 * T_7 V_99 ,
struct V_1 * V_19 V_99 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static int F_47 ( union V_98 * T_5 V_99 ,
struct V_20 * T_6 V_99 ,
struct V_1 * V_19 V_99 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static int F_48 ( union V_98 * T_5 V_99 ,
struct V_1 * V_19 V_99 ,
struct V_41 * V_42 V_99 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static void F_49 ( struct V_41 * V_101 )
{
if ( V_101 -> T_6 == NULL )
V_101 -> T_6 = F_46 ;
if ( V_101 -> V_102 == NULL )
V_101 -> V_102 = F_47 ;
if ( V_101 -> V_103 == NULL )
V_101 -> V_103 = F_47 ;
if ( V_101 -> V_104 == NULL )
V_101 -> V_104 = F_47 ;
if ( V_101 -> exit == NULL )
V_101 -> exit = F_47 ;
if ( V_101 -> V_105 == NULL )
V_101 -> V_105 = V_106 ;
if ( V_101 -> V_107 == NULL )
V_101 -> V_107 = F_47 ;
if ( V_101 -> V_108 == NULL )
V_101 -> V_108 = F_47 ;
if ( V_101 -> V_109 == NULL )
V_101 -> V_109 = F_47 ;
if ( V_101 -> V_110 == NULL )
V_101 -> V_110 = F_45 ;
if ( V_101 -> V_111 == NULL )
V_101 -> V_111 = F_45 ;
if ( V_101 -> V_112 == NULL )
V_101 -> V_112 = F_45 ;
if ( V_101 -> V_113 == NULL )
V_101 -> V_113 = F_45 ;
if ( V_101 -> V_114 == NULL ) {
if ( V_101 -> V_51 )
V_101 -> V_114 = V_115 ;
else
V_101 -> V_114 = F_48 ;
}
}
void F_50 ( void * V_116 , int V_117 )
{
T_1 * V_118 = V_116 ;
while ( V_117 > 0 ) {
* V_118 = F_51 ( * V_118 ) ;
V_117 -= sizeof( T_1 ) ;
++ V_118 ;
}
}
static void F_52 ( union V_98 * T_5 )
{
struct V_119 * V_120 = & T_5 -> V_121 ;
F_50 ( V_120 + 1 , T_5 -> V_121 . V_18 - sizeof( * V_120 ) ) ;
}
static void F_53 ( union V_98 * T_5 )
{
T_5 -> V_103 . V_93 = F_54 ( T_5 -> V_103 . V_93 ) ;
T_5 -> V_103 . V_26 = F_54 ( T_5 -> V_103 . V_26 ) ;
}
static void F_55 ( union V_98 * T_5 )
{
T_5 -> V_102 . V_93 = F_54 ( T_5 -> V_102 . V_93 ) ;
T_5 -> V_102 . V_26 = F_54 ( T_5 -> V_102 . V_26 ) ;
T_5 -> V_102 . V_122 = F_51 ( T_5 -> V_102 . V_122 ) ;
T_5 -> V_102 . V_43 = F_51 ( T_5 -> V_102 . V_43 ) ;
T_5 -> V_102 . V_123 = F_51 ( T_5 -> V_102 . V_123 ) ;
}
static void F_56 ( union V_98 * T_5 )
{
T_5 -> V_104 . V_93 = F_54 ( T_5 -> V_104 . V_93 ) ;
T_5 -> V_104 . V_26 = F_54 ( T_5 -> V_104 . V_26 ) ;
T_5 -> V_104 . V_124 = F_54 ( T_5 -> V_104 . V_124 ) ;
T_5 -> V_104 . V_125 = F_54 ( T_5 -> V_104 . V_125 ) ;
T_5 -> V_104 . time = F_51 ( T_5 -> V_104 . time ) ;
}
static void F_57 ( union V_98 * T_5 )
{
T_5 -> V_107 . V_93 = F_54 ( T_5 -> V_107 . V_93 ) ;
T_5 -> V_107 . V_26 = F_54 ( T_5 -> V_107 . V_26 ) ;
T_5 -> V_107 . V_126 = F_51 ( T_5 -> V_107 . V_126 ) ;
T_5 -> V_107 . V_127 = F_51 ( T_5 -> V_107 . V_127 ) ;
T_5 -> V_107 . V_128 = F_51 ( T_5 -> V_107 . V_128 ) ;
T_5 -> V_107 . V_29 = F_51 ( T_5 -> V_107 . V_29 ) ;
}
void F_58 ( struct V_129 * V_110 )
{
V_110 -> type = F_54 ( V_110 -> type ) ;
V_110 -> V_18 = F_54 ( V_110 -> V_18 ) ;
V_110 -> V_130 = F_51 ( V_110 -> V_130 ) ;
V_110 -> V_131 = F_51 ( V_110 -> V_131 ) ;
V_110 -> V_22 = F_51 ( V_110 -> V_22 ) ;
V_110 -> V_132 = F_51 ( V_110 -> V_132 ) ;
V_110 -> V_133 = F_54 ( V_110 -> V_133 ) ;
V_110 -> V_134 = F_54 ( V_110 -> V_134 ) ;
V_110 -> V_135 = F_51 ( V_110 -> V_135 ) ;
V_110 -> V_136 = F_51 ( V_110 -> V_136 ) ;
}
static void F_59 ( union V_98 * T_5 )
{
T_3 V_18 ;
F_58 ( & T_5 -> V_110 . V_110 ) ;
V_18 = T_5 -> V_121 . V_18 ;
V_18 -= ( void * ) & T_5 -> V_110 . V_29 - ( void * ) T_5 ;
F_50 ( T_5 -> V_110 . V_29 , V_18 ) ;
}
static void F_60 ( union V_98 * T_5 )
{
T_5 -> V_111 . V_111 . V_137 =
F_51 ( T_5 -> V_111 . V_111 . V_137 ) ;
}
static void F_61 ( union V_98 * T_5 )
{
T_5 -> V_112 . V_18 = F_54 ( T_5 -> V_112 . V_18 ) ;
}
static void F_62 ( struct V_1 * V_19 )
{
struct V_51 * V_138 = & V_19 -> V_51 ;
while ( ! F_63 ( & V_138 -> V_54 ) ) {
struct V_139 * V_140 ;
V_140 = F_64 ( V_138 -> V_54 . V_141 , struct V_139 , V_142 ) ;
F_30 ( & V_140 -> V_142 ) ;
free ( V_140 ) ;
}
}
static void F_65 ( struct V_1 * V_143 ,
struct V_41 * V_42 )
{
struct V_51 * V_138 = & V_143 -> V_51 ;
struct V_144 * V_145 = & V_138 -> V_52 ;
struct V_139 * V_146 , * V_147 ;
struct V_20 T_6 ;
T_1 V_148 = V_138 -> V_149 ;
T_1 V_150 = V_138 -> V_151 ? V_138 -> V_151 -> V_152 : 0ULL ;
int V_36 ;
if ( ! V_42 -> V_51 || ! V_148 )
return;
F_29 (iter, tmp, head, list) {
if ( V_147 -> V_152 > V_148 )
break;
V_36 = F_66 ( V_143 , V_147 -> T_5 , & T_6 ) ;
if ( V_36 )
F_3 ( L_14 , V_36 ) ;
else
F_67 ( V_143 , V_147 -> T_5 , & T_6 , V_42 ,
V_147 -> V_153 ) ;
V_138 -> V_154 = V_147 -> V_152 ;
F_30 ( & V_147 -> V_142 ) ;
F_68 ( & V_147 -> V_142 , & V_138 -> V_53 ) ;
}
if ( F_63 ( V_145 ) ) {
V_138 -> V_151 = NULL ;
} else if ( V_150 <= V_148 ) {
V_138 -> V_151 =
F_64 ( V_145 -> V_155 , struct V_139 , V_142 ) ;
}
}
static int V_115 ( union V_98 * T_5 V_99 ,
struct V_1 * V_19 ,
struct V_41 * V_42 )
{
F_65 ( V_19 , V_42 ) ;
V_19 -> V_51 . V_149 = V_19 -> V_51 . V_156 ;
return 0 ;
}
static void F_69 ( struct V_139 * V_157 , struct V_1 * V_143 )
{
struct V_51 * V_138 = & V_143 -> V_51 ;
struct V_139 * T_6 = V_138 -> V_151 ;
T_1 V_152 = V_157 -> V_152 ;
struct V_144 * V_158 ;
V_138 -> V_151 = V_157 ;
if ( ! T_6 ) {
F_68 ( & V_157 -> V_142 , & V_138 -> V_52 ) ;
V_138 -> V_156 = V_152 ;
return;
}
if ( T_6 -> V_152 <= V_152 ) {
while ( T_6 -> V_152 <= V_152 ) {
V_158 = T_6 -> V_142 . V_141 ;
if ( V_158 == & V_138 -> V_52 ) {
F_39 ( & V_157 -> V_142 , & V_138 -> V_52 ) ;
V_138 -> V_156 = V_152 ;
return;
}
T_6 = F_64 ( V_158 , struct V_139 , V_142 ) ;
}
F_39 ( & V_157 -> V_142 , & T_6 -> V_142 ) ;
} else {
while ( T_6 -> V_152 > V_152 ) {
V_158 = T_6 -> V_142 . V_155 ;
if ( V_158 == & V_138 -> V_52 ) {
F_68 ( & V_157 -> V_142 , & V_138 -> V_52 ) ;
return;
}
T_6 = F_64 ( V_158 , struct V_139 , V_142 ) ;
}
F_68 ( & V_157 -> V_142 , & T_6 -> V_142 ) ;
}
}
static int F_70 ( struct V_1 * V_143 , union V_98 * T_5 ,
struct V_20 * T_6 , T_1 V_153 )
{
struct V_51 * V_138 = & V_143 -> V_51 ;
struct V_144 * V_159 = & V_138 -> V_53 ;
T_1 V_152 = T_6 -> time ;
struct V_139 * V_157 ;
if ( ! V_152 || V_152 == ~ 0ULL )
return - V_160 ;
if ( V_152 < V_143 -> V_51 . V_154 ) {
printf ( L_15 ) ;
return - V_161 ;
}
if ( ! F_63 ( V_159 ) ) {
V_157 = F_64 ( V_159 -> V_141 , struct V_139 , V_142 ) ;
F_30 ( & V_157 -> V_142 ) ;
} else if ( V_138 -> V_162 ) {
V_157 = V_138 -> V_162 + V_138 -> V_163 ;
if ( ++ V_138 -> V_163 == V_164 )
V_138 -> V_162 = NULL ;
} else {
V_138 -> V_162 = malloc ( V_164 * sizeof( * V_157 ) ) ;
if ( ! V_138 -> V_162 )
return - V_165 ;
F_68 ( & V_138 -> V_162 -> V_142 , & V_138 -> V_54 ) ;
V_138 -> V_163 = 2 ;
V_157 = V_138 -> V_162 + 1 ;
}
V_157 -> V_152 = V_152 ;
V_157 -> V_153 = V_153 ;
V_157 -> T_5 = T_5 ;
F_69 ( V_157 , V_143 ) ;
return 0 ;
}
static void F_71 ( struct V_20 * T_6 )
{
unsigned int V_75 ;
printf ( L_16 V_166 L_6 , T_6 -> V_167 -> V_77 ) ;
for ( V_75 = 0 ; V_75 < T_6 -> V_167 -> V_77 ; V_75 ++ )
printf ( L_17 V_168 L_6 ,
V_75 , T_6 -> V_167 -> V_84 [ V_75 ] ) ;
}
static void F_72 ( struct V_1 * V_19 ,
union V_98 * T_5 ,
struct V_20 * T_6 )
{
if ( T_5 -> V_121 . type != V_169 &&
! V_19 -> V_23 ) {
fputs ( L_18 , stdout ) ;
return;
}
if ( ( V_19 -> V_22 & V_32 ) )
printf ( L_19 , T_6 -> V_33 ) ;
if ( V_19 -> V_22 & V_27 )
printf ( L_20 V_166 L_21 , T_6 -> time ) ;
}
static void F_73 ( struct V_1 * V_19 , union V_98 * T_5 ,
T_1 V_153 , struct V_20 * T_6 )
{
if ( ! V_170 )
return;
printf ( L_22 V_168 L_23 ,
V_153 , T_5 -> V_121 . V_18 , T_5 -> V_121 . type ) ;
F_74 ( T_5 ) ;
if ( T_6 )
F_72 ( V_19 , T_5 , T_6 ) ;
printf ( L_24 V_168 L_25 , V_153 ,
T_5 -> V_121 . V_18 , F_75 ( T_5 -> V_121 . type ) ) ;
}
static void F_76 ( struct V_1 * V_19 , union V_98 * T_5 ,
struct V_20 * T_6 )
{
if ( ! V_170 )
return;
printf ( L_26 V_168 L_27 V_166 L_28 V_168 L_6 ,
T_5 -> V_121 . V_171 , T_6 -> V_93 , T_6 -> V_26 , T_6 -> V_78 ,
T_6 -> V_172 , T_6 -> V_173 ) ;
if ( V_19 -> V_22 & V_174 )
F_71 ( T_6 ) ;
}
static int F_67 ( struct V_1 * V_19 ,
union V_98 * T_5 ,
struct V_20 * T_6 ,
struct V_41 * V_42 ,
T_1 V_153 )
{
struct V_100 * T_7 ;
F_73 ( V_19 , T_5 , V_153 , T_6 ) ;
switch ( T_5 -> V_121 . type ) {
case V_169 :
F_76 ( V_19 , T_5 , T_6 ) ;
T_7 = F_77 ( V_19 -> V_17 , T_6 -> V_29 ) ;
if ( T_7 == NULL ) {
++ V_19 -> V_175 . V_176 . V_177 ;
return - 1 ;
}
return V_42 -> T_6 ( T_5 , T_6 , T_7 , V_19 ) ;
case V_178 :
return V_42 -> V_102 ( T_5 , T_6 , V_19 ) ;
case V_179 :
return V_42 -> V_103 ( T_5 , T_6 , V_19 ) ;
case V_180 :
return V_42 -> V_104 ( T_5 , T_6 , V_19 ) ;
case V_181 :
return V_42 -> exit ( T_5 , T_6 , V_19 ) ;
case V_182 :
return V_42 -> V_105 ( T_5 , T_6 , V_19 ) ;
case V_183 :
return V_42 -> V_107 ( T_5 , T_6 , V_19 ) ;
case V_184 :
return V_42 -> V_108 ( T_5 , T_6 , V_19 ) ;
case V_185 :
return V_42 -> V_109 ( T_5 , T_6 , V_19 ) ;
default:
++ V_19 -> V_175 . V_176 . V_186 ;
return - 1 ;
}
}
static int F_78 ( struct V_1 * V_19 ,
union V_98 * T_5 , struct V_20 * T_6 )
{
if ( T_5 -> V_121 . type != V_169 ||
! ( V_19 -> V_22 & V_174 ) )
return 0 ;
if ( ! F_79 ( T_6 -> V_167 , T_5 ) ) {
F_80 ( L_29 ) ;
++ V_19 -> V_175 . V_176 . V_187 ;
V_19 -> V_175 . V_176 . V_188 += T_6 -> V_172 ;
return - V_161 ;
}
return 0 ;
}
static int F_81 ( struct V_1 * V_19 , union V_98 * T_5 ,
struct V_41 * V_42 , T_1 V_153 )
{
F_73 ( V_19 , T_5 , V_153 , NULL ) ;
switch ( T_5 -> V_121 . type ) {
case V_189 :
return V_42 -> V_110 ( T_5 , V_19 ) ;
case V_190 :
return V_42 -> V_111 ( T_5 , V_19 ) ;
case V_191 :
F_82 ( V_19 -> V_8 , V_153 , V_192 ) ;
return V_42 -> V_112 ( T_5 , V_19 ) ;
case V_193 :
return V_42 -> V_113 ( T_5 , V_19 ) ;
case V_194 :
return V_42 -> V_114 ( T_5 , V_19 , V_42 ) ;
default:
return - V_161 ;
}
}
static int F_83 ( struct V_1 * V_19 ,
union V_98 * T_5 ,
struct V_41 * V_42 ,
T_1 V_153 )
{
struct V_20 T_6 ;
int V_36 ;
if ( V_19 -> V_121 . V_195 &&
V_196 [ T_5 -> V_121 . type ] )
V_196 [ T_5 -> V_121 . type ] ( T_5 ) ;
if ( T_5 -> V_121 . type >= V_197 )
return - V_161 ;
F_84 ( & V_19 -> V_175 , T_5 -> V_121 . type ) ;
if ( T_5 -> V_121 . type >= V_198 )
return F_81 ( V_19 , T_5 , V_42 , V_153 ) ;
V_36 = F_66 ( V_19 , T_5 , & T_6 ) ;
if ( V_36 )
return V_36 ;
if ( F_78 ( V_19 , T_5 , & T_6 ) )
return 0 ;
if ( V_42 -> V_51 ) {
V_36 = F_70 ( V_19 , T_5 , & T_6 ,
V_153 ) ;
if ( V_36 != - V_160 )
return V_36 ;
}
return F_67 ( V_19 , T_5 , & T_6 , V_42 ,
V_153 ) ;
}
void F_85 ( struct V_119 * V_2 )
{
V_2 -> type = F_54 ( V_2 -> type ) ;
V_2 -> V_171 = F_86 ( V_2 -> V_171 ) ;
V_2 -> V_18 = F_86 ( V_2 -> V_18 ) ;
}
static struct V_59 * F_87 ( struct V_1 * V_2 )
{
struct V_59 * V_59 = F_88 ( V_2 , 0 ) ;
if ( V_59 == NULL || F_89 ( V_59 , L_30 ) ) {
F_3 ( L_31 ) ;
V_59 = NULL ;
}
return V_59 ;
}
static void F_90 ( const struct V_1 * V_19 ,
const struct V_41 * V_42 )
{
if ( V_42 -> V_105 == V_106 &&
V_19 -> V_175 . V_176 . V_199 != 0 ) {
F_91 ( L_32 V_166 L_33 V_166
L_34 ,
V_19 -> V_175 . V_176 . V_200 ,
V_19 -> V_175 . V_176 . V_199 ) ;
}
if ( V_19 -> V_175 . V_176 . V_186 != 0 ) {
F_91 ( L_35
L_36
L_37
L_38
L_39 ,
V_19 -> V_175 . V_176 . V_186 ) ;
}
if ( V_19 -> V_175 . V_176 . V_177 != 0 ) {
F_91 ( L_40 ,
V_19 -> V_175 . V_176 . V_177 ) ;
}
if ( V_19 -> V_175 . V_176 . V_187 != 0 ) {
F_91 ( L_41
L_42
L_43 ,
V_19 -> V_175 . V_176 . V_187 ,
V_19 -> V_175 . V_176 . V_201 [ V_169 ] ) ;
}
}
static int F_92 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
union V_98 T_5 ;
T_8 V_18 ;
int V_202 = 0 ;
T_1 V_145 ;
int V_11 ;
void * V_158 ;
F_49 ( V_42 ) ;
V_145 = 0 ;
V_203:
V_11 = F_93 ( V_2 -> V_8 , & T_5 , sizeof( struct V_119 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 )
goto V_204;
F_3 ( L_44 ) ;
goto V_205;
}
if ( V_2 -> V_121 . V_195 )
F_85 ( & T_5 . V_121 ) ;
V_18 = T_5 . V_121 . V_18 ;
if ( V_18 == 0 )
V_18 = 8 ;
V_158 = & T_5 ;
V_158 += sizeof( struct V_119 ) ;
if ( V_18 - sizeof( struct V_119 ) ) {
V_11 = F_93 ( V_2 -> V_8 , V_158 , V_18 - sizeof( struct V_119 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 ) {
F_3 ( L_45 ) ;
goto V_204;
}
F_3 ( L_46 ) ;
goto V_205;
}
}
if ( V_18 == 0 ||
( V_202 = F_83 ( V_2 , & T_5 , V_42 , V_145 ) ) < 0 ) {
F_26 ( L_24 V_168 L_47 ,
V_145 , T_5 . V_121 . V_18 , T_5 . V_121 . type ) ;
if ( F_94 ( V_145 & 7 ) )
V_145 &= ~ 7ULL ;
V_18 = 8 ;
}
V_145 += V_18 ;
if ( V_202 > 0 )
V_145 += V_202 ;
if ( ! F_95 () )
goto V_203;
V_204:
V_11 = 0 ;
V_205:
F_90 ( V_2 , V_42 ) ;
F_62 ( V_2 ) ;
return V_11 ;
}
static union V_98 *
F_96 ( struct V_1 * V_19 ,
T_1 V_145 , T_3 V_206 , char * V_207 )
{
union V_98 * T_5 ;
if ( V_145 + sizeof( T_5 -> V_121 ) > V_206 )
return NULL ;
T_5 = (union V_98 * ) ( V_207 + V_145 ) ;
if ( V_19 -> V_121 . V_195 )
F_85 ( & T_5 -> V_121 ) ;
if ( V_145 + T_5 -> V_121 . V_18 > V_206 )
return NULL ;
return T_5 ;
}
int F_97 ( struct V_1 * V_19 ,
T_1 V_208 , T_1 V_209 ,
T_1 V_210 , struct V_41 * V_42 )
{
T_1 V_145 , V_211 , V_153 , V_212 , V_213 ;
int V_11 , V_214 , V_215 , V_216 = 0 ;
struct V_217 * V_218 ;
T_3 V_219 , V_206 ;
char * V_207 , * V_220 [ 8 ] ;
union V_98 * T_5 ;
T_8 V_18 ;
F_49 ( V_42 ) ;
V_219 = F_98 ( V_221 ) ;
V_211 = V_219 * ( V_208 / V_219 ) ;
V_153 = V_211 ;
V_145 = V_208 - V_211 ;
if ( V_208 + V_209 < V_210 )
V_210 = V_208 + V_209 ;
V_213 = V_210 / 16 ;
V_218 = F_99 ( L_48 , V_210 ) ;
if ( V_218 == NULL )
return - 1 ;
V_206 = V_19 -> V_49 ;
if ( V_206 > V_210 )
V_206 = V_210 ;
memset ( V_220 , 0 , sizeof( V_220 ) ) ;
V_214 = V_222 ;
V_215 = V_223 ;
if ( V_19 -> V_121 . V_195 ) {
V_214 |= V_224 ;
V_215 = V_225 ;
}
V_226:
V_207 = V_102 ( NULL , V_206 , V_214 , V_215 , V_19 -> V_8 ,
V_153 ) ;
if ( V_207 == V_227 ) {
F_3 ( L_49 ) ;
V_11 = - V_12 ;
goto V_205;
}
V_220 [ V_216 ] = V_207 ;
V_216 = ( V_216 + 1 ) & ( F_100 ( V_220 ) - 1 ) ;
V_212 = V_153 + V_145 ;
V_203:
T_5 = F_96 ( V_19 , V_145 , V_206 , V_207 ) ;
if ( ! T_5 ) {
if ( V_220 [ V_216 ] ) {
F_101 ( V_220 [ V_216 ] , V_206 ) ;
V_220 [ V_216 ] = NULL ;
}
V_211 = V_219 * ( V_145 / V_219 ) ;
V_153 += V_211 ;
V_145 -= V_211 ;
goto V_226;
}
V_18 = T_5 -> V_121 . V_18 ;
if ( V_18 == 0 ||
F_83 ( V_19 , T_5 , V_42 , V_212 ) < 0 ) {
F_26 ( L_24 V_168 L_47 ,
V_153 + V_145 , T_5 -> V_121 . V_18 ,
T_5 -> V_121 . type ) ;
if ( F_94 ( V_145 & 7 ) )
V_145 &= ~ 7ULL ;
V_18 = 8 ;
}
V_145 += V_18 ;
V_212 += V_18 ;
if ( V_212 >= V_213 ) {
V_213 += V_210 / 16 ;
F_102 ( V_218 , V_212 ) ;
}
if ( V_212 < V_210 )
goto V_203;
V_11 = 0 ;
V_19 -> V_51 . V_149 = V_50 ;
F_65 ( V_19 , V_42 ) ;
V_205:
F_103 ( V_218 ) ;
F_90 ( V_19 , V_42 ) ;
F_62 ( V_19 ) ;
return V_11 ;
}
int F_104 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
int V_11 ;
if ( F_87 ( V_2 ) == NULL )
return - V_165 ;
if ( ! V_2 -> V_7 )
V_11 = F_97 ( V_2 ,
V_2 -> V_121 . V_208 ,
V_2 -> V_121 . V_209 ,
V_2 -> V_18 , V_42 ) ;
else
V_11 = F_92 ( V_2 , V_42 ) ;
return V_11 ;
}
bool F_105 ( struct V_1 * V_2 , const char * V_228 )
{
if ( ! ( V_2 -> V_22 & V_229 ) ) {
F_3 ( L_50 , V_228 ) ;
return false ;
}
return true ;
}
int F_106 ( struct V_97 * * V_230 ,
const char * V_231 ,
T_1 V_173 )
{
char * V_232 ;
enum V_233 V_75 ;
struct V_234 * V_235 ;
V_235 = F_23 ( sizeof( struct V_234 ) ) ;
if ( V_235 == NULL )
return - V_165 ;
V_235 -> V_68 = F_107 ( V_231 ) ;
if ( V_235 -> V_68 == NULL ) {
free ( V_235 ) ;
return - V_165 ;
}
V_232 = strchr ( V_235 -> V_68 , ']' ) ;
if ( V_232 )
* V_232 = '\0' ;
V_235 -> V_173 = V_173 ;
for ( V_75 = 0 ; V_75 < V_236 ; ++ V_75 ) {
struct V_237 * V_237 = F_108 ( V_230 [ V_75 ] ) ;
V_237 -> V_234 = V_235 ;
}
return 0 ;
}
T_3 F_109 ( struct V_1 * V_2 , T_9 * V_238 )
{
return F_110 ( & V_2 -> V_37 . V_239 , V_238 ) +
F_110 ( & V_2 -> V_37 . V_240 , V_238 ) +
F_111 ( & V_2 -> V_38 , V_238 ) ;
}
T_3 F_112 ( struct V_1 * V_2 , T_9 * V_238 ,
bool V_241 )
{
T_3 V_36 = F_113 ( & V_2 -> V_37 , V_238 , V_241 ) ;
return V_36 + F_114 ( & V_2 -> V_38 , V_238 , V_241 ) ;
}
T_3 F_115 ( struct V_1 * V_19 , T_9 * V_238 )
{
struct V_100 * V_242 ;
T_3 V_36 = fprintf ( V_238 , L_51 ) ;
V_36 += F_116 ( & V_19 -> V_175 , V_238 ) ;
F_117 (pos, &session->evlist->entries, node) {
V_36 += fprintf ( V_238 , L_52 , F_118 ( V_242 ) ) ;
V_36 += F_116 ( & V_242 -> V_175 , V_238 ) ;
}
return V_36 ;
}
struct V_100 * F_119 ( struct V_1 * V_19 ,
unsigned int type )
{
struct V_100 * V_242 ;
F_117 (pos, &session->evlist->entries, node) {
if ( V_242 -> V_110 . type == type )
return V_242 ;
}
return NULL ;
}
void F_120 ( union V_98 * T_5 ,
struct V_20 * T_6 ,
struct V_1 * V_19 ,
int V_243 , int V_244 )
{
struct V_79 V_80 ;
const char * V_245 , * V_246 ;
struct V_76 * V_247 = & V_19 -> V_76 ;
struct V_248 * V_62 ;
if ( F_121 ( T_5 , V_19 , & V_80 , T_6 ,
NULL ) < 0 ) {
error ( L_53 ,
T_5 -> V_121 . type ) ;
return;
}
if ( V_95 . V_96 && T_6 -> V_167 ) {
if ( F_41 ( V_19 , V_80 . V_59 ,
T_6 -> V_167 , NULL ) != 0 ) {
if ( V_249 )
error ( L_54 ) ;
return;
}
F_122 ( V_247 ) ;
while ( 1 ) {
V_62 = F_123 ( V_247 ) ;
if ( ! V_62 )
break;
printf ( L_55 V_168 , V_62 -> V_78 ) ;
if ( V_243 ) {
if ( V_62 -> V_67 && V_62 -> V_67 -> V_68 )
V_245 = V_62 -> V_67 -> V_68 ;
else
V_245 = L_11 ;
printf ( L_56 , V_245 ) ;
}
if ( V_244 ) {
if ( V_62 -> V_97 && V_62 -> V_97 -> V_250 && V_62 -> V_97 -> V_250 -> V_68 )
V_246 = V_62 -> V_97 -> V_250 -> V_68 ;
else
V_246 = L_11 ;
printf ( L_57 , V_246 ) ;
}
printf ( L_6 ) ;
F_124 ( V_247 ) ;
}
} else {
printf ( L_58 V_168 , T_6 -> V_78 ) ;
if ( V_243 ) {
if ( V_80 . V_67 && V_80 . V_67 -> V_68 )
V_245 = V_80 . V_67 -> V_68 ;
else
V_245 = L_11 ;
printf ( L_56 , V_245 ) ;
}
if ( V_244 ) {
if ( V_80 . V_97 && V_80 . V_97 -> V_250 && V_80 . V_97 -> V_250 -> V_68 )
V_246 = V_80 . V_97 -> V_250 -> V_68 ;
else
V_246 = L_11 ;
printf ( L_57 , V_246 ) ;
}
}
}
int F_125 ( struct V_1 * V_19 ,
const char * V_251 , unsigned long * V_252 )
{
int V_75 ;
struct V_253 * V_97 ;
for ( V_75 = 0 ; V_75 < V_254 ; ++ V_75 ) {
struct V_100 * T_7 ;
T_7 = F_119 ( V_19 , V_75 ) ;
if ( ! T_7 )
continue;
if ( ! ( T_7 -> V_110 . V_22 & V_32 ) ) {
F_3 ( L_59
L_60 ) ;
return - 1 ;
}
}
V_97 = F_126 ( V_251 ) ;
for ( V_75 = 0 ; V_75 < V_97 -> V_77 ; V_75 ++ ) {
int V_33 = V_97 -> V_97 [ V_75 ] ;
if ( V_33 >= V_255 ) {
F_3 ( L_61
L_62 , V_33 ) ;
return - 1 ;
}
F_127 ( V_33 , V_252 ) ;
}
return 0 ;
}

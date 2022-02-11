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
unsigned V_153 = 0 , V_154 = V_138 -> V_155 / 16 ;
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
V_147 -> V_156 ) ;
V_138 -> V_157 = V_147 -> V_152 ;
F_30 ( & V_147 -> V_142 ) ;
F_68 ( & V_147 -> V_142 , & V_138 -> V_53 ) ;
if ( ++ V_153 >= V_154 ) {
V_154 += V_138 -> V_155 / 16 ;
F_69 ( V_153 , V_138 -> V_155 ,
L_15 ) ;
}
}
if ( F_63 ( V_145 ) ) {
V_138 -> V_151 = NULL ;
} else if ( V_150 <= V_148 ) {
V_138 -> V_151 =
F_64 ( V_145 -> V_158 , struct V_139 , V_142 ) ;
}
V_138 -> V_155 = 0 ;
}
static int V_115 ( union V_98 * T_5 V_99 ,
struct V_1 * V_19 ,
struct V_41 * V_42 )
{
F_65 ( V_19 , V_42 ) ;
V_19 -> V_51 . V_149 = V_19 -> V_51 . V_159 ;
return 0 ;
}
static void F_70 ( struct V_139 * V_160 , struct V_1 * V_143 )
{
struct V_51 * V_138 = & V_143 -> V_51 ;
struct V_139 * T_6 = V_138 -> V_151 ;
T_1 V_152 = V_160 -> V_152 ;
struct V_144 * V_161 ;
++ V_138 -> V_155 ;
V_138 -> V_151 = V_160 ;
if ( ! T_6 ) {
F_68 ( & V_160 -> V_142 , & V_138 -> V_52 ) ;
V_138 -> V_159 = V_152 ;
return;
}
if ( T_6 -> V_152 <= V_152 ) {
while ( T_6 -> V_152 <= V_152 ) {
V_161 = T_6 -> V_142 . V_141 ;
if ( V_161 == & V_138 -> V_52 ) {
F_39 ( & V_160 -> V_142 , & V_138 -> V_52 ) ;
V_138 -> V_159 = V_152 ;
return;
}
T_6 = F_64 ( V_161 , struct V_139 , V_142 ) ;
}
F_39 ( & V_160 -> V_142 , & T_6 -> V_142 ) ;
} else {
while ( T_6 -> V_152 > V_152 ) {
V_161 = T_6 -> V_142 . V_158 ;
if ( V_161 == & V_138 -> V_52 ) {
F_68 ( & V_160 -> V_142 , & V_138 -> V_52 ) ;
return;
}
T_6 = F_64 ( V_161 , struct V_139 , V_142 ) ;
}
F_68 ( & V_160 -> V_142 , & T_6 -> V_142 ) ;
}
}
static int F_71 ( struct V_1 * V_143 , union V_98 * T_5 ,
struct V_20 * T_6 , T_1 V_156 )
{
struct V_51 * V_138 = & V_143 -> V_51 ;
struct V_144 * V_162 = & V_138 -> V_53 ;
T_1 V_152 = T_6 -> time ;
struct V_139 * V_160 ;
if ( ! V_152 || V_152 == ~ 0ULL )
return - V_163 ;
if ( V_152 < V_143 -> V_51 . V_157 ) {
printf ( L_16 ) ;
return - V_164 ;
}
if ( ! F_63 ( V_162 ) ) {
V_160 = F_64 ( V_162 -> V_141 , struct V_139 , V_142 ) ;
F_30 ( & V_160 -> V_142 ) ;
} else if ( V_138 -> V_165 ) {
V_160 = V_138 -> V_165 + V_138 -> V_166 ;
if ( ++ V_138 -> V_166 == V_167 )
V_138 -> V_165 = NULL ;
} else {
V_138 -> V_165 = malloc ( V_167 * sizeof( * V_160 ) ) ;
if ( ! V_138 -> V_165 )
return - V_168 ;
F_68 ( & V_138 -> V_165 -> V_142 , & V_138 -> V_54 ) ;
V_138 -> V_166 = 2 ;
V_160 = V_138 -> V_165 + 1 ;
}
V_160 -> V_152 = V_152 ;
V_160 -> V_156 = V_156 ;
V_160 -> T_5 = T_5 ;
F_70 ( V_160 , V_143 ) ;
return 0 ;
}
static void F_72 ( struct V_20 * T_6 )
{
unsigned int V_75 ;
printf ( L_17 V_169 L_6 , T_6 -> V_170 -> V_77 ) ;
for ( V_75 = 0 ; V_75 < T_6 -> V_170 -> V_77 ; V_75 ++ )
printf ( L_18 V_171 L_6 ,
V_75 , T_6 -> V_170 -> V_84 [ V_75 ] ) ;
}
static void F_73 ( struct V_1 * V_19 ,
union V_98 * T_5 ,
struct V_20 * T_6 )
{
if ( T_5 -> V_121 . type != V_172 &&
! V_19 -> V_23 ) {
fputs ( L_19 , stdout ) ;
return;
}
if ( ( V_19 -> V_22 & V_32 ) )
printf ( L_20 , T_6 -> V_33 ) ;
if ( V_19 -> V_22 & V_27 )
printf ( L_21 V_169 L_22 , T_6 -> time ) ;
}
static void F_74 ( struct V_1 * V_19 , union V_98 * T_5 ,
T_1 V_156 , struct V_20 * T_6 )
{
if ( ! V_173 )
return;
printf ( L_23 V_171 L_24 ,
V_156 , T_5 -> V_121 . V_18 , T_5 -> V_121 . type ) ;
F_75 ( T_5 ) ;
if ( T_6 )
F_73 ( V_19 , T_5 , T_6 ) ;
printf ( L_25 V_171 L_26 , V_156 ,
T_5 -> V_121 . V_18 , F_76 ( T_5 -> V_121 . type ) ) ;
}
static void F_77 ( struct V_1 * V_19 , union V_98 * T_5 ,
struct V_20 * T_6 )
{
if ( ! V_173 )
return;
printf ( L_27 V_171 L_28 V_169 L_29 V_171 L_6 ,
T_5 -> V_121 . V_174 , T_6 -> V_93 , T_6 -> V_26 , T_6 -> V_78 ,
T_6 -> V_175 , T_6 -> V_176 ) ;
if ( V_19 -> V_22 & V_177 )
F_72 ( T_6 ) ;
}
static int F_67 ( struct V_1 * V_19 ,
union V_98 * T_5 ,
struct V_20 * T_6 ,
struct V_41 * V_42 ,
T_1 V_156 )
{
struct V_100 * T_7 ;
F_74 ( V_19 , T_5 , V_156 , T_6 ) ;
T_7 = F_78 ( V_19 -> V_17 , T_6 -> V_29 ) ;
if ( T_7 != NULL && T_5 -> V_121 . type != V_172 ) {
F_79 ( & T_7 -> V_178 , T_5 -> V_121 . type ) ;
}
switch ( T_5 -> V_121 . type ) {
case V_172 :
F_77 ( V_19 , T_5 , T_6 ) ;
if ( T_7 == NULL ) {
++ V_19 -> V_178 . V_179 . V_180 ;
return - 1 ;
}
return V_42 -> T_6 ( T_5 , T_6 , T_7 , V_19 ) ;
case V_181 :
return V_42 -> V_102 ( T_5 , T_6 , V_19 ) ;
case V_182 :
return V_42 -> V_103 ( T_5 , T_6 , V_19 ) ;
case V_183 :
return V_42 -> V_104 ( T_5 , T_6 , V_19 ) ;
case V_184 :
return V_42 -> exit ( T_5 , T_6 , V_19 ) ;
case V_185 :
return V_42 -> V_105 ( T_5 , T_6 , V_19 ) ;
case V_186 :
return V_42 -> V_107 ( T_5 , T_6 , V_19 ) ;
case V_187 :
return V_42 -> V_108 ( T_5 , T_6 , V_19 ) ;
case V_188 :
return V_42 -> V_109 ( T_5 , T_6 , V_19 ) ;
default:
++ V_19 -> V_178 . V_179 . V_189 ;
return - 1 ;
}
}
static int F_80 ( struct V_1 * V_19 ,
union V_98 * T_5 , struct V_20 * T_6 )
{
if ( T_5 -> V_121 . type != V_172 ||
! ( V_19 -> V_22 & V_177 ) )
return 0 ;
if ( ! F_81 ( T_6 -> V_170 , T_5 ) ) {
F_82 ( L_30 ) ;
++ V_19 -> V_178 . V_179 . V_190 ;
V_19 -> V_178 . V_179 . V_191 += T_6 -> V_175 ;
return - V_164 ;
}
return 0 ;
}
static int F_83 ( struct V_1 * V_19 , union V_98 * T_5 ,
struct V_41 * V_42 , T_1 V_156 )
{
F_74 ( V_19 , T_5 , V_156 , NULL ) ;
switch ( T_5 -> V_121 . type ) {
case V_192 :
return V_42 -> V_110 ( T_5 , V_19 ) ;
case V_193 :
return V_42 -> V_111 ( T_5 , V_19 ) ;
case V_194 :
F_84 ( V_19 -> V_8 , V_156 , V_195 ) ;
return V_42 -> V_112 ( T_5 , V_19 ) ;
case V_196 :
return V_42 -> V_113 ( T_5 , V_19 ) ;
case V_197 :
return V_42 -> V_114 ( T_5 , V_19 , V_42 ) ;
default:
return - V_164 ;
}
}
static int F_85 ( struct V_1 * V_19 ,
union V_98 * T_5 ,
struct V_41 * V_42 ,
T_1 V_156 )
{
struct V_20 T_6 ;
int V_36 ;
if ( V_19 -> V_121 . V_198 &&
V_199 [ T_5 -> V_121 . type ] )
V_199 [ T_5 -> V_121 . type ] ( T_5 ) ;
if ( T_5 -> V_121 . type >= V_200 )
return - V_164 ;
F_79 ( & V_19 -> V_178 , T_5 -> V_121 . type ) ;
if ( T_5 -> V_121 . type >= V_201 )
return F_83 ( V_19 , T_5 , V_42 , V_156 ) ;
V_36 = F_66 ( V_19 , T_5 , & T_6 ) ;
if ( V_36 )
return V_36 ;
if ( F_80 ( V_19 , T_5 , & T_6 ) )
return 0 ;
if ( V_42 -> V_51 ) {
V_36 = F_71 ( V_19 , T_5 , & T_6 ,
V_156 ) ;
if ( V_36 != - V_163 )
return V_36 ;
}
return F_67 ( V_19 , T_5 , & T_6 , V_42 ,
V_156 ) ;
}
void F_86 ( struct V_119 * V_2 )
{
V_2 -> type = F_54 ( V_2 -> type ) ;
V_2 -> V_174 = F_87 ( V_2 -> V_174 ) ;
V_2 -> V_18 = F_87 ( V_2 -> V_18 ) ;
}
static struct V_59 * F_88 ( struct V_1 * V_2 )
{
struct V_59 * V_59 = F_89 ( V_2 , 0 ) ;
if ( V_59 == NULL || F_90 ( V_59 , L_31 ) ) {
F_3 ( L_32 ) ;
V_59 = NULL ;
}
return V_59 ;
}
static void F_91 ( const struct V_1 * V_19 ,
const struct V_41 * V_42 )
{
if ( V_42 -> V_105 == V_106 &&
V_19 -> V_178 . V_179 . V_202 [ V_185 ] != 0 ) {
F_92 ( L_33
L_34 ,
V_19 -> V_178 . V_179 . V_202 [ 0 ] ,
V_19 -> V_178 . V_179 . V_202 [ V_185 ] ) ;
}
if ( V_19 -> V_178 . V_179 . V_189 != 0 ) {
F_92 ( L_35
L_36
L_37
L_38
L_39 ,
V_19 -> V_178 . V_179 . V_189 ) ;
}
if ( V_19 -> V_178 . V_179 . V_180 != 0 ) {
F_92 ( L_40 ,
V_19 -> V_178 . V_179 . V_180 ) ;
}
if ( V_19 -> V_178 . V_179 . V_190 != 0 ) {
F_92 ( L_41
L_42
L_43 ,
V_19 -> V_178 . V_179 . V_190 ,
V_19 -> V_178 . V_179 . V_202 [ V_172 ] ) ;
}
}
static int F_93 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
union V_98 T_5 ;
T_8 V_18 ;
int V_203 = 0 ;
T_1 V_145 ;
int V_11 ;
void * V_161 ;
F_49 ( V_42 ) ;
V_145 = 0 ;
V_204:
V_11 = F_94 ( V_2 -> V_8 , & T_5 , sizeof( struct V_119 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 )
goto V_205;
F_3 ( L_44 ) ;
goto V_206;
}
if ( V_2 -> V_121 . V_198 )
F_86 ( & T_5 . V_121 ) ;
V_18 = T_5 . V_121 . V_18 ;
if ( V_18 == 0 )
V_18 = 8 ;
V_161 = & T_5 ;
V_161 += sizeof( struct V_119 ) ;
if ( V_18 - sizeof( struct V_119 ) ) {
V_11 = F_94 ( V_2 -> V_8 , V_161 , V_18 - sizeof( struct V_119 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 ) {
F_3 ( L_45 ) ;
goto V_205;
}
F_3 ( L_46 ) ;
goto V_206;
}
}
if ( V_18 == 0 ||
( V_203 = F_85 ( V_2 , & T_5 , V_42 , V_145 ) ) < 0 ) {
F_26 ( L_25 V_171 L_47 ,
V_145 , T_5 . V_121 . V_18 , T_5 . V_121 . type ) ;
if ( F_95 ( V_145 & 7 ) )
V_145 &= ~ 7ULL ;
V_18 = 8 ;
}
V_145 += V_18 ;
if ( V_203 > 0 )
V_145 += V_203 ;
if ( ! F_96 () )
goto V_204;
V_205:
V_11 = 0 ;
V_206:
F_91 ( V_2 , V_42 ) ;
F_62 ( V_2 ) ;
return V_11 ;
}
static union V_98 *
F_97 ( struct V_1 * V_19 ,
T_1 V_145 , T_3 V_207 , char * V_208 )
{
union V_98 * T_5 ;
if ( V_145 + sizeof( T_5 -> V_121 ) > V_207 )
return NULL ;
T_5 = (union V_98 * ) ( V_208 + V_145 ) ;
if ( V_19 -> V_121 . V_198 )
F_86 ( & T_5 -> V_121 ) ;
if ( V_145 + T_5 -> V_121 . V_18 > V_207 )
return NULL ;
return T_5 ;
}
int F_98 ( struct V_1 * V_19 ,
T_1 V_209 , T_1 V_210 ,
T_1 V_211 , struct V_41 * V_42 )
{
T_1 V_145 , V_212 , V_156 , V_213 , V_154 ;
int V_11 , V_214 , V_215 , V_216 = 0 ;
T_3 V_217 , V_207 ;
char * V_208 , * V_218 [ 8 ] ;
union V_98 * T_5 ;
T_8 V_18 ;
F_49 ( V_42 ) ;
V_217 = F_99 ( V_219 ) ;
V_212 = V_217 * ( V_209 / V_217 ) ;
V_156 = V_212 ;
V_145 = V_209 - V_212 ;
if ( V_209 + V_210 < V_211 )
V_211 = V_209 + V_210 ;
V_154 = V_211 / 16 ;
V_207 = V_19 -> V_49 ;
if ( V_207 > V_211 )
V_207 = V_211 ;
memset ( V_218 , 0 , sizeof( V_218 ) ) ;
V_214 = V_220 ;
V_215 = V_221 ;
if ( V_19 -> V_121 . V_198 ) {
V_214 |= V_222 ;
V_215 = V_223 ;
}
V_224:
V_208 = V_102 ( NULL , V_207 , V_214 , V_215 , V_19 -> V_8 ,
V_156 ) ;
if ( V_208 == V_225 ) {
F_3 ( L_48 ) ;
V_11 = - V_12 ;
goto V_206;
}
V_218 [ V_216 ] = V_208 ;
V_216 = ( V_216 + 1 ) & ( F_100 ( V_218 ) - 1 ) ;
V_213 = V_156 + V_145 ;
V_204:
T_5 = F_97 ( V_19 , V_145 , V_207 , V_208 ) ;
if ( ! T_5 ) {
if ( V_218 [ V_216 ] ) {
F_101 ( V_218 [ V_216 ] , V_207 ) ;
V_218 [ V_216 ] = NULL ;
}
V_212 = V_217 * ( V_145 / V_217 ) ;
V_156 += V_212 ;
V_145 -= V_212 ;
goto V_224;
}
V_18 = T_5 -> V_121 . V_18 ;
if ( V_18 == 0 ||
F_85 ( V_19 , T_5 , V_42 , V_213 ) < 0 ) {
F_26 ( L_25 V_171 L_47 ,
V_156 + V_145 , T_5 -> V_121 . V_18 ,
T_5 -> V_121 . type ) ;
if ( F_95 ( V_145 & 7 ) )
V_145 &= ~ 7ULL ;
V_18 = 8 ;
}
V_145 += V_18 ;
V_213 += V_18 ;
if ( V_213 >= V_154 ) {
V_154 += V_211 / 16 ;
F_69 ( V_213 , V_211 ,
L_49 ) ;
}
if ( V_213 < V_211 )
goto V_204;
V_11 = 0 ;
V_19 -> V_51 . V_149 = V_50 ;
F_65 ( V_19 , V_42 ) ;
V_206:
F_91 ( V_19 , V_42 ) ;
F_62 ( V_19 ) ;
return V_11 ;
}
int F_102 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
int V_11 ;
if ( F_88 ( V_2 ) == NULL )
return - V_168 ;
if ( ! V_2 -> V_7 )
V_11 = F_98 ( V_2 ,
V_2 -> V_121 . V_209 ,
V_2 -> V_121 . V_210 ,
V_2 -> V_18 , V_42 ) ;
else
V_11 = F_93 ( V_2 , V_42 ) ;
return V_11 ;
}
bool F_103 ( struct V_1 * V_2 , const char * V_226 )
{
if ( ! ( V_2 -> V_22 & V_227 ) ) {
F_3 ( L_50 , V_226 ) ;
return false ;
}
return true ;
}
int F_104 ( struct V_97 * * V_228 ,
const char * V_229 ,
T_1 V_176 )
{
char * V_230 ;
enum V_231 V_75 ;
struct V_232 * V_233 ;
V_233 = F_23 ( sizeof( struct V_232 ) ) ;
if ( V_233 == NULL )
return - V_168 ;
V_233 -> V_68 = F_105 ( V_229 ) ;
if ( V_233 -> V_68 == NULL ) {
free ( V_233 ) ;
return - V_168 ;
}
V_230 = strchr ( V_233 -> V_68 , ']' ) ;
if ( V_230 )
* V_230 = '\0' ;
V_233 -> V_176 = V_176 ;
for ( V_75 = 0 ; V_75 < V_234 ; ++ V_75 ) {
struct V_235 * V_235 = F_106 ( V_228 [ V_75 ] ) ;
V_235 -> V_232 = V_233 ;
}
return 0 ;
}
T_3 F_107 ( struct V_1 * V_2 , T_9 * V_236 )
{
return F_108 ( & V_2 -> V_37 . V_237 , V_236 ) +
F_108 ( & V_2 -> V_37 . V_238 , V_236 ) +
F_109 ( & V_2 -> V_38 , V_236 ) ;
}
T_3 F_110 ( struct V_1 * V_2 , T_9 * V_236 ,
bool V_239 )
{
T_3 V_36 = F_111 ( & V_2 -> V_37 , V_236 , V_239 ) ;
return V_36 + F_112 ( & V_2 -> V_38 , V_236 , V_239 ) ;
}
T_3 F_113 ( struct V_1 * V_19 , T_9 * V_236 )
{
struct V_100 * V_240 ;
T_3 V_36 = fprintf ( V_236 , L_51 ) ;
V_36 += F_114 ( & V_19 -> V_178 , V_236 ) ;
F_115 (pos, &session->evlist->entries, node) {
V_36 += fprintf ( V_236 , L_52 , F_116 ( V_240 ) ) ;
V_36 += F_114 ( & V_240 -> V_178 , V_236 ) ;
}
return V_36 ;
}
struct V_100 * F_117 ( struct V_1 * V_19 ,
unsigned int type )
{
struct V_100 * V_240 ;
F_115 (pos, &session->evlist->entries, node) {
if ( V_240 -> V_110 . type == type )
return V_240 ;
}
return NULL ;
}
void F_118 ( union V_98 * T_5 ,
struct V_20 * T_6 ,
struct V_1 * V_19 ,
int V_241 , int V_242 )
{
struct V_79 V_80 ;
const char * V_243 , * V_244 ;
struct V_76 * V_245 = & V_19 -> V_76 ;
struct V_246 * V_62 ;
if ( F_119 ( T_5 , V_19 , & V_80 , T_6 ,
NULL ) < 0 ) {
error ( L_53 ,
T_5 -> V_121 . type ) ;
return;
}
if ( V_95 . V_96 && T_6 -> V_170 ) {
if ( F_41 ( V_19 , V_80 . V_59 ,
T_6 -> V_170 , NULL ) != 0 ) {
if ( V_247 )
error ( L_54 ) ;
return;
}
F_120 ( V_245 ) ;
while ( 1 ) {
V_62 = F_121 ( V_245 ) ;
if ( ! V_62 )
break;
printf ( L_55 V_171 , V_62 -> V_78 ) ;
if ( V_241 ) {
if ( V_62 -> V_67 && V_62 -> V_67 -> V_68 )
V_243 = V_62 -> V_67 -> V_68 ;
else
V_243 = L_11 ;
printf ( L_56 , V_243 ) ;
}
if ( V_242 ) {
if ( V_62 -> V_97 && V_62 -> V_97 -> V_248 && V_62 -> V_97 -> V_248 -> V_68 )
V_244 = V_62 -> V_97 -> V_248 -> V_68 ;
else
V_244 = L_11 ;
printf ( L_57 , V_244 ) ;
}
printf ( L_6 ) ;
F_122 ( V_245 ) ;
}
} else {
printf ( L_58 V_171 , T_6 -> V_78 ) ;
if ( V_241 ) {
if ( V_80 . V_67 && V_80 . V_67 -> V_68 )
V_243 = V_80 . V_67 -> V_68 ;
else
V_243 = L_11 ;
printf ( L_56 , V_243 ) ;
}
if ( V_242 ) {
if ( V_80 . V_97 && V_80 . V_97 -> V_248 && V_80 . V_97 -> V_248 -> V_68 )
V_244 = V_80 . V_97 -> V_248 -> V_68 ;
else
V_244 = L_11 ;
printf ( L_57 , V_244 ) ;
}
}
}
int F_123 ( struct V_1 * V_19 ,
const char * V_249 , unsigned long * V_250 )
{
int V_75 ;
struct V_251 * V_97 ;
for ( V_75 = 0 ; V_75 < V_252 ; ++ V_75 ) {
struct V_100 * T_7 ;
T_7 = F_117 ( V_19 , V_75 ) ;
if ( ! T_7 )
continue;
if ( ! ( T_7 -> V_110 . V_22 & V_32 ) ) {
F_3 ( L_59
L_60 ) ;
return - 1 ;
}
}
V_97 = F_124 ( V_249 ) ;
if ( V_97 == NULL ) {
F_3 ( L_61 ) ;
return - 1 ;
}
for ( V_75 = 0 ; V_75 < V_97 -> V_77 ; V_75 ++ ) {
int V_33 = V_97 -> V_97 [ V_75 ] ;
if ( V_33 >= V_253 ) {
F_3 ( L_62
L_63 , V_33 ) ;
return - 1 ;
}
F_125 ( V_33 , V_250 ) ;
}
return 0 ;
}
void F_126 ( struct V_1 * V_19 , T_9 * V_236 ,
bool V_254 )
{
struct V_4 V_255 ;
int V_36 ;
if ( V_19 == NULL || V_236 == NULL )
return;
V_36 = F_5 ( V_19 -> V_8 , & V_255 ) ;
if ( V_36 == - 1 )
return;
fprintf ( V_236 , L_64 ) ;
fprintf ( V_236 , L_65 , ctime ( & V_255 . V_256 ) ) ;
F_127 ( V_19 , V_236 , V_254 ) ;
fprintf ( V_236 , L_66 ) ;
}

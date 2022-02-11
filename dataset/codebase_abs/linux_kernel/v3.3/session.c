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
if ( V_26 == V_10 ) {
if ( F_1 ( V_2 , V_3 ) < 0 )
goto V_43;
F_11 ( V_2 ) ;
} else if ( V_26 == V_44 ) {
if ( F_16 ( V_2 ) < 0 )
goto V_43;
}
if ( V_29 && V_29 -> V_45 &&
V_29 -> V_38 && ! V_2 -> V_21 ) {
F_27 ( L_12 ) ;
V_29 -> V_38 = false ;
}
V_33:
return V_2 ;
V_43:
F_28 ( V_2 ) ;
return NULL ;
}
static void F_29 ( struct V_46 * V_46 )
{
struct V_47 * V_48 , * V_49 ;
F_30 (t, n, &machine->dead_threads, node) {
F_31 ( & V_49 -> V_50 ) ;
F_32 ( V_49 ) ;
}
}
static void F_33 ( struct V_1 * V_51 )
{
F_29 ( & V_51 -> V_23 ) ;
}
static void F_34 ( struct V_46 * V_2 )
{
struct V_52 * V_53 = F_35 ( & V_2 -> V_54 ) ;
while ( V_53 ) {
struct V_47 * V_49 = F_36 ( V_53 , struct V_47 , V_52 ) ;
F_37 ( & V_49 -> V_52 , & V_2 -> V_54 ) ;
V_53 = F_38 ( V_53 ) ;
F_32 ( V_49 ) ;
}
}
static void F_39 ( struct V_1 * V_51 )
{
F_34 ( & V_51 -> V_23 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_33 ( V_2 ) ;
F_39 ( V_2 ) ;
F_40 ( & V_2 -> V_23 ) ;
F_10 ( V_2 -> V_8 ) ;
free ( V_2 ) ;
}
void F_41 ( struct V_46 * V_2 , struct V_47 * V_55 )
{
V_2 -> V_56 = NULL ;
F_37 ( & V_55 -> V_52 , & V_2 -> V_54 ) ;
F_42 ( & V_55 -> V_50 , & V_2 -> V_57 ) ;
}
static bool F_43 ( struct V_58 * V_59 )
{
if ( V_59 -> V_60 && ! regexec ( & V_61 , V_59 -> V_60 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
int F_44 ( struct V_46 * V_2 , struct V_62 * V_63 ,
struct V_47 * V_47 ,
struct V_64 * V_65 ,
struct V_58 * * V_66 )
{
T_2 V_67 = V_68 ;
unsigned int V_69 ;
int V_11 ;
F_45 ( & V_63 -> V_70 . V_71 ) ;
for ( V_69 = 0 ; V_69 < V_65 -> V_72 ; V_69 ++ ) {
T_3 V_73 ;
struct V_74 V_75 ;
if ( V_76 . V_77 == V_78 )
V_73 = V_65 -> V_79 [ V_69 ] ;
else
V_73 = V_65 -> V_79 [ V_65 -> V_72 - V_69 - 1 ] ;
if ( V_73 >= V_80 ) {
switch ( V_73 ) {
case V_81 :
V_67 = V_82 ; break;
case V_83 :
V_67 = V_84 ; break;
case V_85 :
V_67 = V_68 ; break;
default:
break;
}
continue;
}
V_75 . V_86 = false ;
F_46 ( V_47 , V_2 , V_67 ,
V_87 , V_73 , & V_75 , NULL ) ;
if ( V_75 . V_59 != NULL ) {
if ( V_88 && ! * V_66 &&
F_43 ( V_75 . V_59 ) )
* V_66 = V_75 . V_59 ;
if ( ! V_89 . V_90 )
break;
}
V_11 = F_47 ( & V_63 -> V_70 . V_71 ,
V_73 , V_75 . V_91 , V_75 . V_59 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_48 ( union V_92 * T_4 V_93 ,
struct V_1 * V_51 V_93 )
{
F_27 ( L_13 ) ;
return 0 ;
}
static int F_49 ( union V_92 * T_4 V_93 ,
struct V_94 * * T_5 V_93 )
{
F_27 ( L_13 ) ;
return 0 ;
}
static int F_50 ( struct V_28 * V_29 V_93 ,
union V_92 * T_4 V_93 ,
struct V_95 * T_6 V_93 ,
struct V_62 * V_63 V_93 ,
struct V_46 * V_46 V_93 )
{
F_27 ( L_13 ) ;
return 0 ;
}
static int F_51 ( struct V_28 * V_29 V_93 ,
union V_92 * T_4 V_93 ,
struct V_95 * T_6 V_93 ,
struct V_46 * V_46 V_93 )
{
F_27 ( L_13 ) ;
return 0 ;
}
static int F_52 ( struct V_28 * V_29 V_93 ,
union V_92 * T_4 V_93 ,
struct V_1 * V_1 V_93 )
{
F_27 ( L_13 ) ;
return 0 ;
}
static int F_53 ( struct V_28 * V_29 V_93 ,
union V_92 * T_4 V_93 )
{
F_27 ( L_13 ) ;
return 0 ;
}
static void F_54 ( struct V_28 * V_29 )
{
if ( V_29 -> T_6 == NULL )
V_29 -> T_6 = F_50 ;
if ( V_29 -> V_96 == NULL )
V_29 -> V_96 = F_51 ;
if ( V_29 -> V_97 == NULL )
V_29 -> V_97 = F_51 ;
if ( V_29 -> V_98 == NULL )
V_29 -> V_98 = F_51 ;
if ( V_29 -> exit == NULL )
V_29 -> exit = F_51 ;
if ( V_29 -> V_99 == NULL )
V_29 -> V_99 = V_100 ;
if ( V_29 -> V_101 == NULL )
V_29 -> V_101 = F_50 ;
if ( V_29 -> V_102 == NULL )
V_29 -> V_102 = F_51 ;
if ( V_29 -> V_103 == NULL )
V_29 -> V_103 = F_51 ;
if ( V_29 -> V_104 == NULL )
V_29 -> V_104 = F_49 ;
if ( V_29 -> V_105 == NULL )
V_29 -> V_105 = F_53 ;
if ( V_29 -> V_106 == NULL )
V_29 -> V_106 = F_48 ;
if ( V_29 -> V_107 == NULL )
V_29 -> V_107 = F_52 ;
if ( V_29 -> V_108 == NULL ) {
if ( V_29 -> V_38 )
V_29 -> V_108 = V_109 ;
else
V_29 -> V_108 = F_52 ;
}
}
void F_55 ( void * V_110 , int V_111 )
{
T_3 * V_112 = V_110 ;
while ( V_111 > 0 ) {
* V_112 = F_56 ( * V_112 ) ;
V_111 -= sizeof( T_3 ) ;
++ V_112 ;
}
}
static void F_57 ( union V_92 * T_4 )
{
struct V_113 * V_114 = & T_4 -> V_115 ;
F_55 ( V_114 + 1 , T_4 -> V_115 . V_18 - sizeof( * V_114 ) ) ;
}
static void F_58 ( union V_92 * T_4 )
{
T_4 -> V_97 . V_116 = F_59 ( T_4 -> V_97 . V_116 ) ;
T_4 -> V_97 . V_117 = F_59 ( T_4 -> V_97 . V_117 ) ;
}
static void F_60 ( union V_92 * T_4 )
{
T_4 -> V_96 . V_116 = F_59 ( T_4 -> V_96 . V_116 ) ;
T_4 -> V_96 . V_117 = F_59 ( T_4 -> V_96 . V_117 ) ;
T_4 -> V_96 . V_118 = F_56 ( T_4 -> V_96 . V_118 ) ;
T_4 -> V_96 . V_31 = F_56 ( T_4 -> V_96 . V_31 ) ;
T_4 -> V_96 . V_119 = F_56 ( T_4 -> V_96 . V_119 ) ;
}
static void F_61 ( union V_92 * T_4 )
{
T_4 -> V_98 . V_116 = F_59 ( T_4 -> V_98 . V_116 ) ;
T_4 -> V_98 . V_117 = F_59 ( T_4 -> V_98 . V_117 ) ;
T_4 -> V_98 . V_120 = F_59 ( T_4 -> V_98 . V_120 ) ;
T_4 -> V_98 . V_121 = F_59 ( T_4 -> V_98 . V_121 ) ;
T_4 -> V_98 . time = F_56 ( T_4 -> V_98 . time ) ;
}
static void F_62 ( union V_92 * T_4 )
{
T_4 -> V_101 . V_116 = F_59 ( T_4 -> V_101 . V_116 ) ;
T_4 -> V_101 . V_117 = F_59 ( T_4 -> V_101 . V_117 ) ;
T_4 -> V_101 . V_122 = F_56 ( T_4 -> V_101 . V_122 ) ;
T_4 -> V_101 . V_123 = F_56 ( T_4 -> V_101 . V_123 ) ;
T_4 -> V_101 . V_124 = F_56 ( T_4 -> V_101 . V_124 ) ;
T_4 -> V_101 . V_125 = F_56 ( T_4 -> V_101 . V_125 ) ;
}
void F_63 ( struct V_126 * V_104 )
{
V_104 -> type = F_59 ( V_104 -> type ) ;
V_104 -> V_18 = F_59 ( V_104 -> V_18 ) ;
V_104 -> V_127 = F_56 ( V_104 -> V_127 ) ;
V_104 -> V_128 = F_56 ( V_104 -> V_128 ) ;
V_104 -> V_19 = F_56 ( V_104 -> V_19 ) ;
V_104 -> V_129 = F_56 ( V_104 -> V_129 ) ;
V_104 -> V_130 = F_59 ( V_104 -> V_130 ) ;
V_104 -> V_131 = F_59 ( V_104 -> V_131 ) ;
V_104 -> V_132 = F_56 ( V_104 -> V_132 ) ;
V_104 -> V_133 = F_56 ( V_104 -> V_133 ) ;
}
static void F_64 ( union V_92 * T_4 )
{
T_1 V_18 ;
F_63 ( & T_4 -> V_104 . V_104 ) ;
V_18 = T_4 -> V_115 . V_18 ;
V_18 -= ( void * ) & T_4 -> V_104 . V_125 - ( void * ) T_4 ;
F_55 ( T_4 -> V_104 . V_125 , V_18 ) ;
}
static void F_65 ( union V_92 * T_4 )
{
T_4 -> V_105 . V_105 . V_134 =
F_56 ( T_4 -> V_105 . V_105 . V_134 ) ;
}
static void F_66 ( union V_92 * T_4 )
{
T_4 -> V_106 . V_18 = F_59 ( T_4 -> V_106 . V_18 ) ;
}
static void F_67 ( struct V_1 * V_51 )
{
struct V_38 * V_135 = & V_51 -> V_38 ;
while ( ! F_68 ( & V_135 -> V_41 ) ) {
struct V_136 * V_137 ;
V_137 = F_69 ( V_135 -> V_41 . V_138 , struct V_136 , V_139 ) ;
F_31 ( & V_137 -> V_139 ) ;
free ( V_137 ) ;
}
}
static void F_70 ( struct V_1 * V_140 ,
struct V_28 * V_29 )
{
struct V_38 * V_135 = & V_140 -> V_38 ;
struct V_141 * V_142 = & V_135 -> V_39 ;
struct V_136 * V_143 , * V_144 ;
struct V_95 T_6 ;
T_3 V_145 = V_135 -> V_146 ;
T_3 V_147 = V_135 -> V_148 ? V_135 -> V_148 -> V_149 : 0ULL ;
unsigned V_150 = 0 , V_151 = V_135 -> V_152 / 16 ;
int V_24 ;
if ( ! V_29 -> V_38 || ! V_145 )
return;
F_30 (iter, tmp, head, list) {
if ( V_144 -> V_149 > V_145 )
break;
V_24 = F_71 ( V_140 , V_144 -> T_4 , & T_6 ) ;
if ( V_24 )
F_3 ( L_14 , V_24 ) ;
else
F_72 ( V_140 , V_144 -> T_4 , & T_6 , V_29 ,
V_144 -> V_153 ) ;
V_135 -> V_154 = V_144 -> V_149 ;
F_31 ( & V_144 -> V_139 ) ;
F_73 ( & V_144 -> V_139 , & V_135 -> V_40 ) ;
if ( ++ V_150 >= V_151 ) {
V_151 += V_135 -> V_152 / 16 ;
F_74 ( V_150 , V_135 -> V_152 ,
L_15 ) ;
}
}
if ( F_68 ( V_142 ) ) {
V_135 -> V_148 = NULL ;
} else if ( V_147 <= V_145 ) {
V_135 -> V_148 =
F_69 ( V_142 -> V_155 , struct V_136 , V_139 ) ;
}
V_135 -> V_152 = 0 ;
}
static int V_109 ( struct V_28 * V_29 ,
union V_92 * T_4 V_93 ,
struct V_1 * V_51 )
{
F_70 ( V_51 , V_29 ) ;
V_51 -> V_38 . V_146 = V_51 -> V_38 . V_156 ;
return 0 ;
}
static void F_75 ( struct V_136 * V_157 , struct V_1 * V_140 )
{
struct V_38 * V_135 = & V_140 -> V_38 ;
struct V_136 * T_6 = V_135 -> V_148 ;
T_3 V_149 = V_157 -> V_149 ;
struct V_141 * V_158 ;
++ V_135 -> V_152 ;
V_135 -> V_148 = V_157 ;
if ( ! T_6 ) {
F_73 ( & V_157 -> V_139 , & V_135 -> V_39 ) ;
V_135 -> V_156 = V_149 ;
return;
}
if ( T_6 -> V_149 <= V_149 ) {
while ( T_6 -> V_149 <= V_149 ) {
V_158 = T_6 -> V_139 . V_138 ;
if ( V_158 == & V_135 -> V_39 ) {
F_42 ( & V_157 -> V_139 , & V_135 -> V_39 ) ;
V_135 -> V_156 = V_149 ;
return;
}
T_6 = F_69 ( V_158 , struct V_136 , V_139 ) ;
}
F_42 ( & V_157 -> V_139 , & T_6 -> V_139 ) ;
} else {
while ( T_6 -> V_149 > V_149 ) {
V_158 = T_6 -> V_139 . V_155 ;
if ( V_158 == & V_135 -> V_39 ) {
F_73 ( & V_157 -> V_139 , & V_135 -> V_39 ) ;
return;
}
T_6 = F_69 ( V_158 , struct V_136 , V_139 ) ;
}
F_73 ( & V_157 -> V_139 , & T_6 -> V_139 ) ;
}
}
static int F_76 ( struct V_1 * V_140 , union V_92 * T_4 ,
struct V_95 * T_6 , T_3 V_153 )
{
struct V_38 * V_135 = & V_140 -> V_38 ;
struct V_141 * V_159 = & V_135 -> V_40 ;
T_3 V_149 = T_6 -> time ;
struct V_136 * V_157 ;
if ( ! V_149 || V_149 == ~ 0ULL )
return - V_160 ;
if ( V_149 < V_140 -> V_38 . V_154 ) {
printf ( L_16 ) ;
return - V_161 ;
}
if ( ! F_68 ( V_159 ) ) {
V_157 = F_69 ( V_159 -> V_138 , struct V_136 , V_139 ) ;
F_31 ( & V_157 -> V_139 ) ;
} else if ( V_135 -> V_162 ) {
V_157 = V_135 -> V_162 + V_135 -> V_163 ;
if ( ++ V_135 -> V_163 == V_164 )
V_135 -> V_162 = NULL ;
} else {
V_135 -> V_162 = malloc ( V_164 * sizeof( * V_157 ) ) ;
if ( ! V_135 -> V_162 )
return - V_165 ;
F_73 ( & V_135 -> V_162 -> V_139 , & V_135 -> V_41 ) ;
V_135 -> V_163 = 2 ;
V_157 = V_135 -> V_162 + 1 ;
}
V_157 -> V_149 = V_149 ;
V_157 -> V_153 = V_153 ;
V_157 -> T_4 = T_4 ;
F_75 ( V_157 , V_140 ) ;
return 0 ;
}
static void F_77 ( struct V_95 * T_6 )
{
unsigned int V_69 ;
printf ( L_17 V_166 L_6 , T_6 -> V_167 -> V_72 ) ;
for ( V_69 = 0 ; V_69 < T_6 -> V_167 -> V_72 ; V_69 ++ )
printf ( L_18 V_168 L_6 ,
V_69 , T_6 -> V_167 -> V_79 [ V_69 ] ) ;
}
static void F_78 ( struct V_1 * V_51 ,
union V_92 * T_4 ,
struct V_95 * T_6 )
{
if ( T_4 -> V_115 . type != V_169 &&
! V_51 -> V_21 ) {
fputs ( L_19 , stdout ) ;
return;
}
if ( ( V_51 -> V_19 & V_170 ) )
printf ( L_20 , T_6 -> V_171 ) ;
if ( V_51 -> V_19 & V_172 )
printf ( L_21 V_166 L_22 , T_6 -> time ) ;
}
static void F_79 ( struct V_1 * V_51 , union V_92 * T_4 ,
T_3 V_153 , struct V_95 * T_6 )
{
if ( ! V_173 )
return;
printf ( L_23 V_168 L_24 ,
V_153 , T_4 -> V_115 . V_18 , T_4 -> V_115 . type ) ;
F_80 ( T_4 ) ;
if ( T_6 )
F_78 ( V_51 , T_4 , T_6 ) ;
printf ( L_25 V_168 L_26 , V_153 ,
T_4 -> V_115 . V_18 , F_81 ( T_4 -> V_115 . type ) ) ;
}
static void F_82 ( struct V_1 * V_51 , union V_92 * T_4 ,
struct V_95 * T_6 )
{
if ( ! V_173 )
return;
printf ( L_27 V_168 L_28 V_166 L_29 V_168 L_6 ,
T_4 -> V_115 . V_174 , T_6 -> V_116 , T_6 -> V_117 , T_6 -> V_73 ,
T_6 -> V_175 , T_6 -> V_176 ) ;
if ( V_51 -> V_19 & V_177 )
F_77 ( T_6 ) ;
}
static struct V_46 *
F_83 ( struct V_1 * V_51 ,
union V_92 * T_4 )
{
const T_2 V_67 = T_4 -> V_115 . V_174 & V_178 ;
if ( V_67 == V_179 && V_180 )
return F_84 ( V_51 , T_4 -> V_73 . V_116 ) ;
return F_85 ( V_51 ) ;
}
static int F_72 ( struct V_1 * V_51 ,
union V_92 * T_4 ,
struct V_95 * T_6 ,
struct V_28 * V_29 ,
T_3 V_153 )
{
struct V_62 * V_63 ;
struct V_46 * V_46 ;
F_79 ( V_51 , T_4 , V_153 , T_6 ) ;
V_63 = F_86 ( V_51 -> V_17 , T_6 -> V_125 ) ;
if ( V_63 != NULL && T_4 -> V_115 . type != V_169 ) {
F_87 ( & V_63 -> V_70 , T_4 -> V_115 . type ) ;
}
V_46 = F_83 ( V_51 , T_4 ) ;
switch ( T_4 -> V_115 . type ) {
case V_169 :
F_82 ( V_51 , T_4 , T_6 ) ;
if ( V_63 == NULL ) {
++ V_51 -> V_70 . V_181 . V_182 ;
return - 1 ;
}
return V_29 -> T_6 ( V_29 , T_4 , T_6 , V_63 , V_46 ) ;
case V_183 :
return V_29 -> V_96 ( V_29 , T_4 , T_6 , V_46 ) ;
case V_184 :
return V_29 -> V_97 ( V_29 , T_4 , T_6 , V_46 ) ;
case V_185 :
return V_29 -> V_98 ( V_29 , T_4 , T_6 , V_46 ) ;
case V_186 :
return V_29 -> exit ( V_29 , T_4 , T_6 , V_46 ) ;
case V_187 :
if ( V_29 -> V_99 == V_100 )
V_51 -> V_70 . V_181 . V_188 += T_4 -> V_99 . V_99 ;
return V_29 -> V_99 ( V_29 , T_4 , T_6 , V_46 ) ;
case V_189 :
return V_29 -> V_101 ( V_29 , T_4 , T_6 , V_63 , V_46 ) ;
case V_190 :
return V_29 -> V_102 ( V_29 , T_4 , T_6 , V_46 ) ;
case V_191 :
return V_29 -> V_103 ( V_29 , T_4 , T_6 , V_46 ) ;
default:
++ V_51 -> V_70 . V_181 . V_192 ;
return - 1 ;
}
}
static int F_88 ( struct V_1 * V_51 ,
union V_92 * T_4 , struct V_95 * T_6 )
{
if ( T_4 -> V_115 . type != V_169 ||
! ( V_51 -> V_19 & V_177 ) )
return 0 ;
if ( ! F_89 ( T_6 -> V_167 , T_4 ) ) {
F_90 ( L_30 ) ;
++ V_51 -> V_70 . V_181 . V_193 ;
V_51 -> V_70 . V_181 . V_194 += T_6 -> V_175 ;
return - V_161 ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_51 , union V_92 * T_4 ,
struct V_28 * V_29 , T_3 V_153 )
{
int V_11 ;
F_79 ( V_51 , T_4 , V_153 , NULL ) ;
switch ( T_4 -> V_115 . type ) {
case V_195 :
V_11 = V_29 -> V_104 ( T_4 , & V_51 -> V_17 ) ;
if ( V_11 == 0 )
F_11 ( V_51 ) ;
return V_11 ;
case V_196 :
return V_29 -> V_105 ( V_29 , T_4 ) ;
case V_197 :
F_92 ( V_51 -> V_8 , V_153 , V_198 ) ;
return V_29 -> V_106 ( T_4 , V_51 ) ;
case V_199 :
return V_29 -> V_107 ( V_29 , T_4 , V_51 ) ;
case V_200 :
return V_29 -> V_108 ( V_29 , T_4 , V_51 ) ;
default:
return - V_161 ;
}
}
static int F_93 ( struct V_1 * V_51 ,
union V_92 * T_4 ,
struct V_28 * V_29 ,
T_3 V_153 )
{
struct V_95 T_6 ;
int V_24 ;
if ( V_51 -> V_115 . V_201 &&
V_202 [ T_4 -> V_115 . type ] )
V_202 [ T_4 -> V_115 . type ] ( T_4 ) ;
if ( T_4 -> V_115 . type >= V_203 )
return - V_161 ;
F_87 ( & V_51 -> V_70 , T_4 -> V_115 . type ) ;
if ( T_4 -> V_115 . type >= V_204 )
return F_91 ( V_51 , T_4 , V_29 , V_153 ) ;
V_24 = F_71 ( V_51 , T_4 , & T_6 ) ;
if ( V_24 )
return V_24 ;
if ( F_88 ( V_51 , T_4 , & T_6 ) )
return 0 ;
if ( V_29 -> V_38 ) {
V_24 = F_76 ( V_51 , T_4 , & T_6 ,
V_153 ) ;
if ( V_24 != - V_160 )
return V_24 ;
}
return F_72 ( V_51 , T_4 , & T_6 , V_29 ,
V_153 ) ;
}
void F_94 ( struct V_113 * V_2 )
{
V_2 -> type = F_59 ( V_2 -> type ) ;
V_2 -> V_174 = F_95 ( V_2 -> V_174 ) ;
V_2 -> V_18 = F_95 ( V_2 -> V_18 ) ;
}
struct V_47 * F_96 ( struct V_1 * V_51 , T_7 V_116 )
{
return F_97 ( & V_51 -> V_23 , V_116 ) ;
}
static struct V_47 * F_98 ( struct V_1 * V_2 )
{
struct V_47 * V_47 = F_96 ( V_2 , 0 ) ;
if ( V_47 == NULL || F_99 ( V_47 , L_31 ) ) {
F_3 ( L_32 ) ;
V_47 = NULL ;
}
return V_47 ;
}
static void F_100 ( const struct V_1 * V_51 ,
const struct V_28 * V_29 )
{
if ( V_29 -> V_99 == V_100 &&
V_51 -> V_70 . V_181 . V_205 [ V_187 ] != 0 ) {
F_101 ( L_33
L_34 ,
V_51 -> V_70 . V_181 . V_205 [ 0 ] ,
V_51 -> V_70 . V_181 . V_205 [ V_187 ] ) ;
}
if ( V_51 -> V_70 . V_181 . V_192 != 0 ) {
F_101 ( L_35
L_36
L_37
L_38
L_39 ,
V_51 -> V_70 . V_181 . V_192 ) ;
}
if ( V_51 -> V_70 . V_181 . V_182 != 0 ) {
F_101 ( L_40 ,
V_51 -> V_70 . V_181 . V_182 ) ;
}
if ( V_51 -> V_70 . V_181 . V_193 != 0 ) {
F_101 ( L_41
L_42
L_43 ,
V_51 -> V_70 . V_181 . V_193 ,
V_51 -> V_70 . V_181 . V_205 [ V_169 ] ) ;
}
}
static int F_102 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
union V_92 T_4 ;
T_8 V_18 ;
int V_206 = 0 ;
T_3 V_142 ;
int V_11 ;
void * V_158 ;
F_54 ( V_29 ) ;
V_142 = 0 ;
V_207:
V_11 = F_103 ( V_2 -> V_8 , & T_4 , sizeof( struct V_113 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 )
goto V_208;
F_3 ( L_44 ) ;
goto V_209;
}
if ( V_2 -> V_115 . V_201 )
F_94 ( & T_4 . V_115 ) ;
V_18 = T_4 . V_115 . V_18 ;
if ( V_18 == 0 )
V_18 = 8 ;
V_158 = & T_4 ;
V_158 += sizeof( struct V_113 ) ;
if ( V_18 - sizeof( struct V_113 ) ) {
V_11 = F_103 ( V_2 -> V_8 , V_158 , V_18 - sizeof( struct V_113 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 ) {
F_3 ( L_45 ) ;
goto V_208;
}
F_3 ( L_46 ) ;
goto V_209;
}
}
if ( ( V_206 = F_93 ( V_2 , & T_4 , V_29 , V_142 ) ) < 0 ) {
F_27 ( L_25 V_168 L_47 ,
V_142 , T_4 . V_115 . V_18 , T_4 . V_115 . type ) ;
if ( F_104 ( V_142 & 7 ) )
V_142 &= ~ 7ULL ;
V_18 = 8 ;
}
V_142 += V_18 ;
if ( V_206 > 0 )
V_142 += V_206 ;
if ( ! F_105 () )
goto V_207;
V_208:
V_11 = 0 ;
V_209:
F_100 ( V_2 , V_29 ) ;
F_67 ( V_2 ) ;
return V_11 ;
}
static union V_92 *
F_106 ( struct V_1 * V_51 ,
T_3 V_142 , T_1 V_210 , char * V_211 )
{
union V_92 * T_4 ;
if ( V_142 + sizeof( T_4 -> V_115 ) > V_210 )
return NULL ;
T_4 = (union V_92 * ) ( V_211 + V_142 ) ;
if ( V_51 -> V_115 . V_201 )
F_94 ( & T_4 -> V_115 ) ;
if ( V_142 + T_4 -> V_115 . V_18 > V_210 )
return NULL ;
return T_4 ;
}
int F_107 ( struct V_1 * V_51 ,
T_3 V_212 , T_3 V_213 ,
T_3 V_214 , struct V_28 * V_29 )
{
T_3 V_142 , V_215 , V_153 , V_216 , V_151 ;
int V_11 , V_217 , V_218 , V_219 = 0 ;
T_1 V_220 , V_210 ;
char * V_211 , * V_221 [ 8 ] ;
union V_92 * T_4 ;
T_8 V_18 ;
F_54 ( V_29 ) ;
V_220 = F_108 ( V_222 ) ;
V_215 = V_220 * ( V_212 / V_220 ) ;
V_153 = V_215 ;
V_142 = V_212 - V_215 ;
if ( V_212 + V_213 < V_214 )
V_214 = V_212 + V_213 ;
V_151 = V_214 / 16 ;
V_210 = V_51 -> V_35 ;
if ( V_210 > V_214 )
V_210 = V_214 ;
memset ( V_221 , 0 , sizeof( V_221 ) ) ;
V_217 = V_223 ;
V_218 = V_224 ;
if ( V_51 -> V_115 . V_201 ) {
V_217 |= V_225 ;
V_218 = V_226 ;
}
V_227:
V_211 = V_96 ( NULL , V_210 , V_217 , V_218 , V_51 -> V_8 ,
V_153 ) ;
if ( V_211 == V_228 ) {
F_3 ( L_48 ) ;
V_11 = - V_12 ;
goto V_209;
}
V_221 [ V_219 ] = V_211 ;
V_219 = ( V_219 + 1 ) & ( F_109 ( V_221 ) - 1 ) ;
V_216 = V_153 + V_142 ;
V_207:
T_4 = F_106 ( V_51 , V_142 , V_210 , V_211 ) ;
if ( ! T_4 ) {
if ( V_221 [ V_219 ] ) {
F_110 ( V_221 [ V_219 ] , V_210 ) ;
V_221 [ V_219 ] = NULL ;
}
V_215 = V_220 * ( V_142 / V_220 ) ;
V_153 += V_215 ;
V_142 -= V_215 ;
goto V_227;
}
V_18 = T_4 -> V_115 . V_18 ;
if ( V_18 == 0 ||
F_93 ( V_51 , T_4 , V_29 , V_216 ) < 0 ) {
F_27 ( L_25 V_168 L_47 ,
V_153 + V_142 , T_4 -> V_115 . V_18 ,
T_4 -> V_115 . type ) ;
if ( F_104 ( V_142 & 7 ) )
V_142 &= ~ 7ULL ;
V_18 = 8 ;
}
V_142 += V_18 ;
V_216 += V_18 ;
if ( V_216 >= V_151 ) {
V_151 += V_214 / 16 ;
F_74 ( V_216 , V_214 ,
L_49 ) ;
}
if ( V_216 < V_214 )
goto V_207;
V_11 = 0 ;
V_51 -> V_38 . V_146 = V_36 ;
F_70 ( V_51 , V_29 ) ;
V_209:
F_100 ( V_51 , V_29 ) ;
F_67 ( V_51 ) ;
return V_11 ;
}
int F_111 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
int V_11 ;
if ( F_98 ( V_2 ) == NULL )
return - V_165 ;
if ( ! V_2 -> V_7 )
V_11 = F_107 ( V_2 ,
V_2 -> V_115 . V_212 ,
V_2 -> V_115 . V_213 ,
V_2 -> V_18 , V_29 ) ;
else
V_11 = F_102 ( V_2 , V_29 ) ;
return V_11 ;
}
bool F_112 ( struct V_1 * V_2 , const char * V_229 )
{
if ( ! ( V_2 -> V_19 & V_230 ) ) {
F_3 ( L_50 , V_229 ) ;
return false ;
}
return true ;
}
int F_113 ( struct V_91 * * V_231 ,
const char * V_232 , T_3 V_176 )
{
char * V_233 ;
enum V_234 V_69 ;
struct V_235 * V_236 ;
V_236 = F_24 ( sizeof( struct V_235 ) ) ;
if ( V_236 == NULL )
return - V_165 ;
V_236 -> V_60 = F_114 ( V_232 ) ;
if ( V_236 -> V_60 == NULL ) {
free ( V_236 ) ;
return - V_165 ;
}
V_233 = strchr ( V_236 -> V_60 , ']' ) ;
if ( V_233 )
* V_233 = '\0' ;
V_236 -> V_176 = V_176 ;
for ( V_69 = 0 ; V_69 < V_237 ; ++ V_69 ) {
struct V_238 * V_238 = F_115 ( V_231 [ V_69 ] ) ;
V_238 -> V_235 = V_236 ;
}
return 0 ;
}
T_1 F_116 ( struct V_1 * V_2 , T_9 * V_239 )
{
return F_117 ( & V_2 -> V_23 . V_240 , V_239 ) +
F_117 ( & V_2 -> V_23 . V_241 , V_239 ) +
F_118 ( & V_2 -> V_25 , V_239 ) ;
}
T_1 F_119 ( struct V_1 * V_2 , T_9 * V_239 ,
bool V_242 )
{
T_1 V_24 = F_120 ( & V_2 -> V_23 , V_239 , V_242 ) ;
return V_24 + F_121 ( & V_2 -> V_25 , V_239 , V_242 ) ;
}
T_1 F_122 ( struct V_1 * V_51 , T_9 * V_239 )
{
struct V_62 * V_243 ;
T_1 V_24 = fprintf ( V_239 , L_51 ) ;
V_24 += F_123 ( & V_51 -> V_70 , V_239 ) ;
F_124 (pos, &session->evlist->entries, node) {
V_24 += fprintf ( V_239 , L_52 , F_125 ( V_243 ) ) ;
V_24 += F_123 ( & V_243 -> V_70 , V_239 ) ;
}
return V_24 ;
}
T_1 F_126 ( struct V_1 * V_51 , T_9 * V_239 )
{
return F_127 ( & V_51 -> V_23 , V_239 ) ;
}
void F_128 ( struct V_1 * V_51 ,
struct V_47 * V_55 )
{
F_41 ( & V_51 -> V_23 , V_55 ) ;
}
struct V_62 * F_129 ( struct V_1 * V_51 ,
unsigned int type )
{
struct V_62 * V_243 ;
F_124 (pos, &session->evlist->entries, node) {
if ( V_243 -> V_104 . type == type )
return V_243 ;
}
return NULL ;
}
void F_130 ( union V_92 * T_4 , struct V_95 * T_6 ,
struct V_46 * V_46 , struct V_62 * V_63 ,
int V_244 , int V_245 )
{
struct V_74 V_75 ;
const char * V_246 , * V_247 ;
struct V_71 * V_248 = & V_63 -> V_70 . V_71 ;
struct V_249 * V_50 ;
if ( F_131 ( T_4 , V_46 , & V_75 , T_6 ,
NULL ) < 0 ) {
error ( L_53 ,
T_4 -> V_115 . type ) ;
return;
}
if ( V_89 . V_90 && T_6 -> V_167 ) {
if ( F_44 ( V_46 , V_63 , V_75 . V_47 ,
T_6 -> V_167 , NULL ) != 0 ) {
if ( V_250 )
error ( L_54 ) ;
return;
}
F_132 ( V_248 ) ;
while ( 1 ) {
V_50 = F_133 ( V_248 ) ;
if ( ! V_50 )
break;
printf ( L_55 V_168 , V_50 -> V_73 ) ;
if ( V_244 ) {
if ( V_50 -> V_59 && V_50 -> V_59 -> V_60 )
V_246 = V_50 -> V_59 -> V_60 ;
else
V_246 = L_11 ;
printf ( L_56 , V_246 ) ;
}
if ( V_245 ) {
if ( V_50 -> V_91 && V_50 -> V_91 -> V_251 && V_50 -> V_91 -> V_251 -> V_60 )
V_247 = V_50 -> V_91 -> V_251 -> V_60 ;
else
V_247 = L_11 ;
printf ( L_57 , V_247 ) ;
}
printf ( L_6 ) ;
F_134 ( V_248 ) ;
}
} else {
printf ( L_58 V_168 , T_6 -> V_73 ) ;
if ( V_244 ) {
if ( V_75 . V_59 && V_75 . V_59 -> V_60 )
V_246 = V_75 . V_59 -> V_60 ;
else
V_246 = L_11 ;
printf ( L_56 , V_246 ) ;
}
if ( V_245 ) {
if ( V_75 . V_91 && V_75 . V_91 -> V_251 && V_75 . V_91 -> V_251 -> V_60 )
V_247 = V_75 . V_91 -> V_251 -> V_60 ;
else
V_247 = L_11 ;
printf ( L_57 , V_247 ) ;
}
}
}
int F_135 ( struct V_1 * V_51 ,
const char * V_252 , unsigned long * V_253 )
{
int V_69 ;
struct V_254 * V_91 ;
for ( V_69 = 0 ; V_69 < V_255 ; ++ V_69 ) {
struct V_62 * V_63 ;
V_63 = F_129 ( V_51 , V_69 ) ;
if ( ! V_63 )
continue;
if ( ! ( V_63 -> V_104 . V_19 & V_170 ) ) {
F_3 ( L_59
L_60 ) ;
return - 1 ;
}
}
V_91 = F_136 ( V_252 ) ;
if ( V_91 == NULL ) {
F_3 ( L_61 ) ;
return - 1 ;
}
for ( V_69 = 0 ; V_69 < V_91 -> V_72 ; V_69 ++ ) {
int V_171 = V_91 -> V_91 [ V_69 ] ;
if ( V_171 >= V_256 ) {
F_3 ( L_62
L_63 , V_171 ) ;
return - 1 ;
}
F_137 ( V_171 , V_253 ) ;
}
return 0 ;
}
void F_138 ( struct V_1 * V_51 , T_9 * V_239 ,
bool V_257 )
{
struct V_4 V_30 ;
int V_24 ;
if ( V_51 == NULL || V_239 == NULL )
return;
V_24 = F_5 ( V_51 -> V_8 , & V_30 ) ;
if ( V_24 == - 1 )
return;
fprintf ( V_239 , L_64 ) ;
fprintf ( V_239 , L_65 , ctime ( & V_30 . V_258 ) ) ;
F_139 ( V_51 , V_239 , V_257 ) ;
fprintf ( V_239 , L_66 ) ;
}

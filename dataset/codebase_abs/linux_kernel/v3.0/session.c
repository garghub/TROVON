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
T_1 V_78 = V_71 -> V_79 [ V_75 ] ;
struct V_80 V_81 ;
if ( V_78 >= V_82 ) {
switch ( V_78 ) {
case V_83 :
V_73 = V_84 ; break;
case V_85 :
V_73 = V_86 ; break;
case V_87 :
V_73 = V_74 ; break;
default:
break;
}
continue;
}
V_81 . V_88 = false ;
F_43 ( V_59 , V_2 , V_73 ,
V_89 , V_59 -> V_90 , V_78 , & V_81 , NULL ) ;
if ( V_81 . V_67 != NULL ) {
if ( V_91 && ! * V_72 &&
F_40 ( V_81 . V_67 ) )
* V_72 = V_81 . V_67 ;
if ( ! V_92 . V_93 )
break;
}
V_11 = F_44 ( & V_2 -> V_76 ,
V_78 , V_81 . V_94 , V_81 . V_67 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_45 ( union V_95 * T_5 V_96 ,
struct V_1 * V_19 V_96 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static int F_46 ( union V_95 * T_5 V_96 ,
struct V_20 * T_6 V_96 ,
struct V_97 * T_7 V_96 ,
struct V_1 * V_19 V_96 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static int F_47 ( union V_95 * T_5 V_96 ,
struct V_20 * T_6 V_96 ,
struct V_1 * V_19 V_96 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static int F_48 ( union V_95 * T_5 V_96 ,
struct V_1 * V_19 V_96 ,
struct V_41 * V_42 V_96 )
{
F_26 ( L_13 ) ;
return 0 ;
}
static void F_49 ( struct V_41 * V_98 )
{
if ( V_98 -> T_6 == NULL )
V_98 -> T_6 = F_46 ;
if ( V_98 -> V_99 == NULL )
V_98 -> V_99 = F_47 ;
if ( V_98 -> V_100 == NULL )
V_98 -> V_100 = F_47 ;
if ( V_98 -> V_101 == NULL )
V_98 -> V_101 = F_47 ;
if ( V_98 -> exit == NULL )
V_98 -> exit = F_47 ;
if ( V_98 -> V_102 == NULL )
V_98 -> V_102 = V_103 ;
if ( V_98 -> V_104 == NULL )
V_98 -> V_104 = F_47 ;
if ( V_98 -> V_105 == NULL )
V_98 -> V_105 = F_47 ;
if ( V_98 -> V_106 == NULL )
V_98 -> V_106 = F_47 ;
if ( V_98 -> V_107 == NULL )
V_98 -> V_107 = F_45 ;
if ( V_98 -> V_108 == NULL )
V_98 -> V_108 = F_45 ;
if ( V_98 -> V_109 == NULL )
V_98 -> V_109 = F_45 ;
if ( V_98 -> V_110 == NULL )
V_98 -> V_110 = F_45 ;
if ( V_98 -> V_111 == NULL ) {
if ( V_98 -> V_51 )
V_98 -> V_111 = V_112 ;
else
V_98 -> V_111 = F_48 ;
}
}
void F_50 ( void * V_113 , int V_114 )
{
T_1 * V_115 = V_113 ;
while ( V_114 > 0 ) {
* V_115 = F_51 ( * V_115 ) ;
V_114 -= sizeof( T_1 ) ;
++ V_115 ;
}
}
static void F_52 ( union V_95 * T_5 )
{
struct V_116 * V_117 = & T_5 -> V_118 ;
F_50 ( V_117 + 1 , T_5 -> V_118 . V_18 - sizeof( * V_117 ) ) ;
}
static void F_53 ( union V_95 * T_5 )
{
T_5 -> V_100 . V_90 = F_54 ( T_5 -> V_100 . V_90 ) ;
T_5 -> V_100 . V_26 = F_54 ( T_5 -> V_100 . V_26 ) ;
}
static void F_55 ( union V_95 * T_5 )
{
T_5 -> V_99 . V_90 = F_54 ( T_5 -> V_99 . V_90 ) ;
T_5 -> V_99 . V_26 = F_54 ( T_5 -> V_99 . V_26 ) ;
T_5 -> V_99 . V_119 = F_51 ( T_5 -> V_99 . V_119 ) ;
T_5 -> V_99 . V_43 = F_51 ( T_5 -> V_99 . V_43 ) ;
T_5 -> V_99 . V_120 = F_51 ( T_5 -> V_99 . V_120 ) ;
}
static void F_56 ( union V_95 * T_5 )
{
T_5 -> V_101 . V_90 = F_54 ( T_5 -> V_101 . V_90 ) ;
T_5 -> V_101 . V_26 = F_54 ( T_5 -> V_101 . V_26 ) ;
T_5 -> V_101 . V_121 = F_54 ( T_5 -> V_101 . V_121 ) ;
T_5 -> V_101 . V_122 = F_54 ( T_5 -> V_101 . V_122 ) ;
T_5 -> V_101 . time = F_51 ( T_5 -> V_101 . time ) ;
}
static void F_57 ( union V_95 * T_5 )
{
T_5 -> V_104 . V_90 = F_54 ( T_5 -> V_104 . V_90 ) ;
T_5 -> V_104 . V_26 = F_54 ( T_5 -> V_104 . V_26 ) ;
T_5 -> V_104 . V_123 = F_51 ( T_5 -> V_104 . V_123 ) ;
T_5 -> V_104 . V_124 = F_51 ( T_5 -> V_104 . V_124 ) ;
T_5 -> V_104 . V_125 = F_51 ( T_5 -> V_104 . V_125 ) ;
T_5 -> V_104 . V_29 = F_51 ( T_5 -> V_104 . V_29 ) ;
}
static void F_58 ( union V_95 * T_5 )
{
T_3 V_18 ;
T_5 -> V_107 . V_107 . type = F_54 ( T_5 -> V_107 . V_107 . type ) ;
T_5 -> V_107 . V_107 . V_18 = F_54 ( T_5 -> V_107 . V_107 . V_18 ) ;
T_5 -> V_107 . V_107 . V_126 = F_51 ( T_5 -> V_107 . V_107 . V_126 ) ;
T_5 -> V_107 . V_107 . V_127 = F_51 ( T_5 -> V_107 . V_107 . V_127 ) ;
T_5 -> V_107 . V_107 . V_22 = F_51 ( T_5 -> V_107 . V_107 . V_22 ) ;
T_5 -> V_107 . V_107 . V_128 = F_51 ( T_5 -> V_107 . V_107 . V_128 ) ;
T_5 -> V_107 . V_107 . V_129 = F_54 ( T_5 -> V_107 . V_107 . V_129 ) ;
T_5 -> V_107 . V_107 . V_130 = F_54 ( T_5 -> V_107 . V_107 . V_130 ) ;
T_5 -> V_107 . V_107 . V_131 = F_51 ( T_5 -> V_107 . V_107 . V_131 ) ;
T_5 -> V_107 . V_107 . V_132 = F_51 ( T_5 -> V_107 . V_107 . V_132 ) ;
V_18 = T_5 -> V_118 . V_18 ;
V_18 -= ( void * ) & T_5 -> V_107 . V_29 - ( void * ) T_5 ;
F_50 ( T_5 -> V_107 . V_29 , V_18 ) ;
}
static void F_59 ( union V_95 * T_5 )
{
T_5 -> V_108 . V_108 . V_133 =
F_51 ( T_5 -> V_108 . V_108 . V_133 ) ;
}
static void F_60 ( union V_95 * T_5 )
{
T_5 -> V_109 . V_18 = F_54 ( T_5 -> V_109 . V_18 ) ;
}
static void F_61 ( struct V_1 * V_19 )
{
struct V_51 * V_134 = & V_19 -> V_51 ;
while ( ! F_62 ( & V_134 -> V_54 ) ) {
struct V_135 * V_136 ;
V_136 = F_63 ( V_134 -> V_54 . V_137 , struct V_135 , V_138 ) ;
F_30 ( & V_136 -> V_138 ) ;
free ( V_136 ) ;
}
}
static void F_64 ( struct V_1 * V_139 ,
struct V_41 * V_42 )
{
struct V_51 * V_134 = & V_139 -> V_51 ;
struct V_140 * V_141 = & V_134 -> V_52 ;
struct V_135 * V_142 , * V_143 ;
struct V_20 T_6 ;
T_1 V_144 = V_134 -> V_145 ;
T_1 V_146 = V_134 -> V_147 ? V_134 -> V_147 -> V_148 : 0ULL ;
int V_36 ;
if ( ! V_42 -> V_51 || ! V_144 )
return;
F_29 (iter, tmp, head, list) {
if ( V_143 -> V_148 > V_144 )
break;
V_36 = F_65 ( V_139 , V_143 -> T_5 , & T_6 ) ;
if ( V_36 )
F_3 ( L_14 , V_36 ) ;
else
F_66 ( V_139 , V_143 -> T_5 , & T_6 , V_42 ,
V_143 -> V_149 ) ;
V_134 -> V_150 = V_143 -> V_148 ;
F_30 ( & V_143 -> V_138 ) ;
F_67 ( & V_143 -> V_138 , & V_134 -> V_53 ) ;
}
if ( F_62 ( V_141 ) ) {
V_134 -> V_147 = NULL ;
} else if ( V_146 <= V_144 ) {
V_134 -> V_147 =
F_63 ( V_141 -> V_151 , struct V_135 , V_138 ) ;
}
}
static int V_112 ( union V_95 * T_5 V_96 ,
struct V_1 * V_19 ,
struct V_41 * V_42 )
{
F_64 ( V_19 , V_42 ) ;
V_19 -> V_51 . V_145 = V_19 -> V_51 . V_152 ;
return 0 ;
}
static void F_68 ( struct V_135 * V_153 , struct V_1 * V_139 )
{
struct V_51 * V_134 = & V_139 -> V_51 ;
struct V_135 * T_6 = V_134 -> V_147 ;
T_1 V_148 = V_153 -> V_148 ;
struct V_140 * V_154 ;
V_134 -> V_147 = V_153 ;
if ( ! T_6 ) {
F_67 ( & V_153 -> V_138 , & V_134 -> V_52 ) ;
V_134 -> V_152 = V_148 ;
return;
}
if ( T_6 -> V_148 <= V_148 ) {
while ( T_6 -> V_148 <= V_148 ) {
V_154 = T_6 -> V_138 . V_137 ;
if ( V_154 == & V_134 -> V_52 ) {
F_39 ( & V_153 -> V_138 , & V_134 -> V_52 ) ;
V_134 -> V_152 = V_148 ;
return;
}
T_6 = F_63 ( V_154 , struct V_135 , V_138 ) ;
}
F_39 ( & V_153 -> V_138 , & T_6 -> V_138 ) ;
} else {
while ( T_6 -> V_148 > V_148 ) {
V_154 = T_6 -> V_138 . V_151 ;
if ( V_154 == & V_134 -> V_52 ) {
F_67 ( & V_153 -> V_138 , & V_134 -> V_52 ) ;
return;
}
T_6 = F_63 ( V_154 , struct V_135 , V_138 ) ;
}
F_67 ( & V_153 -> V_138 , & T_6 -> V_138 ) ;
}
}
static int F_69 ( struct V_1 * V_139 , union V_95 * T_5 ,
struct V_20 * T_6 , T_1 V_149 )
{
struct V_51 * V_134 = & V_139 -> V_51 ;
struct V_140 * V_155 = & V_134 -> V_53 ;
T_1 V_148 = T_6 -> time ;
struct V_135 * V_153 ;
if ( ! V_148 || V_148 == ~ 0ULL )
return - V_156 ;
if ( V_148 < V_139 -> V_51 . V_150 ) {
printf ( L_15 ) ;
return - V_157 ;
}
if ( ! F_62 ( V_155 ) ) {
V_153 = F_63 ( V_155 -> V_137 , struct V_135 , V_138 ) ;
F_30 ( & V_153 -> V_138 ) ;
} else if ( V_134 -> V_158 ) {
V_153 = V_134 -> V_158 + V_134 -> V_159 ;
if ( ++ V_134 -> V_159 == V_160 )
V_134 -> V_158 = NULL ;
} else {
V_134 -> V_158 = malloc ( V_160 * sizeof( * V_153 ) ) ;
if ( ! V_134 -> V_158 )
return - V_161 ;
F_67 ( & V_134 -> V_158 -> V_138 , & V_134 -> V_54 ) ;
V_134 -> V_159 = 2 ;
V_153 = V_134 -> V_158 + 1 ;
}
V_153 -> V_148 = V_148 ;
V_153 -> V_149 = V_149 ;
V_153 -> T_5 = T_5 ;
F_68 ( V_153 , V_139 ) ;
return 0 ;
}
static void F_70 ( struct V_20 * T_6 )
{
unsigned int V_75 ;
printf ( L_16 V_162 L_6 , T_6 -> V_163 -> V_77 ) ;
for ( V_75 = 0 ; V_75 < T_6 -> V_163 -> V_77 ; V_75 ++ )
printf ( L_17 V_164 L_6 ,
V_75 , T_6 -> V_163 -> V_79 [ V_75 ] ) ;
}
static void F_71 ( struct V_1 * V_19 ,
union V_95 * T_5 ,
struct V_20 * T_6 )
{
if ( T_5 -> V_118 . type != V_165 &&
! V_19 -> V_23 ) {
fputs ( L_18 , stdout ) ;
return;
}
if ( ( V_19 -> V_22 & V_32 ) )
printf ( L_19 , T_6 -> V_33 ) ;
if ( V_19 -> V_22 & V_27 )
printf ( L_20 V_162 L_21 , T_6 -> time ) ;
}
static void F_72 ( struct V_1 * V_19 , union V_95 * T_5 ,
T_1 V_149 , struct V_20 * T_6 )
{
if ( ! V_166 )
return;
printf ( L_22 V_164 L_23 ,
V_149 , T_5 -> V_118 . V_18 , T_5 -> V_118 . type ) ;
F_73 ( T_5 ) ;
if ( T_6 )
F_71 ( V_19 , T_5 , T_6 ) ;
printf ( L_24 V_164 L_25 , V_149 ,
T_5 -> V_118 . V_18 , F_74 ( T_5 -> V_118 . type ) ) ;
}
static void F_75 ( struct V_1 * V_19 , union V_95 * T_5 ,
struct V_20 * T_6 )
{
if ( ! V_166 )
return;
printf ( L_26 V_164 L_27 V_162 L_6 ,
T_5 -> V_118 . V_167 , T_6 -> V_90 , T_6 -> V_26 , T_6 -> V_78 ,
T_6 -> V_168 ) ;
if ( V_19 -> V_22 & V_169 )
F_70 ( T_6 ) ;
}
static int F_66 ( struct V_1 * V_19 ,
union V_95 * T_5 ,
struct V_20 * T_6 ,
struct V_41 * V_42 ,
T_1 V_149 )
{
struct V_97 * T_7 ;
F_72 ( V_19 , T_5 , V_149 , T_6 ) ;
switch ( T_5 -> V_118 . type ) {
case V_165 :
F_75 ( V_19 , T_5 , T_6 ) ;
T_7 = F_76 ( V_19 -> V_17 , T_6 -> V_29 ) ;
if ( T_7 == NULL ) {
++ V_19 -> V_170 . V_171 . V_172 ;
return - 1 ;
}
return V_42 -> T_6 ( T_5 , T_6 , T_7 , V_19 ) ;
case V_173 :
return V_42 -> V_99 ( T_5 , T_6 , V_19 ) ;
case V_174 :
return V_42 -> V_100 ( T_5 , T_6 , V_19 ) ;
case V_175 :
return V_42 -> V_101 ( T_5 , T_6 , V_19 ) ;
case V_176 :
return V_42 -> exit ( T_5 , T_6 , V_19 ) ;
case V_177 :
return V_42 -> V_102 ( T_5 , T_6 , V_19 ) ;
case V_178 :
return V_42 -> V_104 ( T_5 , T_6 , V_19 ) ;
case V_179 :
return V_42 -> V_105 ( T_5 , T_6 , V_19 ) ;
case V_180 :
return V_42 -> V_106 ( T_5 , T_6 , V_19 ) ;
default:
++ V_19 -> V_170 . V_171 . V_181 ;
return - 1 ;
}
}
static int F_77 ( struct V_1 * V_19 ,
union V_95 * T_5 , struct V_20 * T_6 )
{
if ( T_5 -> V_118 . type != V_165 ||
! ( V_19 -> V_22 & V_169 ) )
return 0 ;
if ( ! F_78 ( T_6 -> V_163 , T_5 ) ) {
F_79 ( L_28 ) ;
++ V_19 -> V_170 . V_171 . V_182 ;
V_19 -> V_170 . V_171 . V_183 += T_6 -> V_168 ;
return - V_157 ;
}
return 0 ;
}
static int F_80 ( struct V_1 * V_19 , union V_95 * T_5 ,
struct V_41 * V_42 , T_1 V_149 )
{
F_72 ( V_19 , T_5 , V_149 , NULL ) ;
switch ( T_5 -> V_118 . type ) {
case V_184 :
return V_42 -> V_107 ( T_5 , V_19 ) ;
case V_185 :
return V_42 -> V_108 ( T_5 , V_19 ) ;
case V_186 :
F_81 ( V_19 -> V_8 , V_149 , V_187 ) ;
return V_42 -> V_109 ( T_5 , V_19 ) ;
case V_188 :
return V_42 -> V_110 ( T_5 , V_19 ) ;
case V_189 :
return V_42 -> V_111 ( T_5 , V_19 , V_42 ) ;
default:
return - V_157 ;
}
}
static int F_82 ( struct V_1 * V_19 ,
union V_95 * T_5 ,
struct V_41 * V_42 ,
T_1 V_149 )
{
struct V_20 T_6 ;
int V_36 ;
if ( V_19 -> V_118 . V_190 &&
V_191 [ T_5 -> V_118 . type ] )
V_191 [ T_5 -> V_118 . type ] ( T_5 ) ;
if ( T_5 -> V_118 . type >= V_192 )
return - V_157 ;
F_83 ( & V_19 -> V_170 , T_5 -> V_118 . type ) ;
if ( T_5 -> V_118 . type >= V_193 )
return F_80 ( V_19 , T_5 , V_42 , V_149 ) ;
V_36 = F_65 ( V_19 , T_5 , & T_6 ) ;
if ( V_36 )
return V_36 ;
if ( F_77 ( V_19 , T_5 , & T_6 ) )
return 0 ;
if ( V_42 -> V_51 ) {
V_36 = F_69 ( V_19 , T_5 , & T_6 ,
V_149 ) ;
if ( V_36 != - V_156 )
return V_36 ;
}
return F_66 ( V_19 , T_5 , & T_6 , V_42 ,
V_149 ) ;
}
void F_84 ( struct V_116 * V_2 )
{
V_2 -> type = F_54 ( V_2 -> type ) ;
V_2 -> V_167 = F_85 ( V_2 -> V_167 ) ;
V_2 -> V_18 = F_85 ( V_2 -> V_18 ) ;
}
static struct V_59 * F_86 ( struct V_1 * V_2 )
{
struct V_59 * V_59 = F_87 ( V_2 , 0 ) ;
if ( V_59 == NULL || F_88 ( V_59 , L_29 ) ) {
F_3 ( L_30 ) ;
V_59 = NULL ;
}
return V_59 ;
}
static void F_89 ( const struct V_1 * V_19 ,
const struct V_41 * V_42 )
{
if ( V_42 -> V_102 == V_103 &&
V_19 -> V_170 . V_171 . V_194 != 0 ) {
F_90 ( L_31 V_162 L_32 V_162
L_33 ,
V_19 -> V_170 . V_171 . V_195 ,
V_19 -> V_170 . V_171 . V_194 ) ;
}
if ( V_19 -> V_170 . V_171 . V_181 != 0 ) {
F_90 ( L_34
L_35
L_36
L_37
L_38 ,
V_19 -> V_170 . V_171 . V_181 ) ;
}
if ( V_19 -> V_170 . V_171 . V_172 != 0 ) {
F_90 ( L_39 ,
V_19 -> V_170 . V_171 . V_172 ) ;
}
if ( V_19 -> V_170 . V_171 . V_182 != 0 ) {
F_90 ( L_40
L_41
L_42 ,
V_19 -> V_170 . V_171 . V_182 ,
V_19 -> V_170 . V_171 . V_196 [ V_165 ] ) ;
}
}
static int F_91 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
union V_95 T_5 ;
T_8 V_18 ;
int V_197 = 0 ;
T_1 V_141 ;
int V_11 ;
void * V_154 ;
F_49 ( V_42 ) ;
V_141 = 0 ;
V_198:
V_11 = F_92 ( V_2 -> V_8 , & T_5 , sizeof( struct V_116 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 )
goto V_199;
F_3 ( L_43 ) ;
goto V_200;
}
if ( V_2 -> V_118 . V_190 )
F_84 ( & T_5 . V_118 ) ;
V_18 = T_5 . V_118 . V_18 ;
if ( V_18 == 0 )
V_18 = 8 ;
V_154 = & T_5 ;
V_154 += sizeof( struct V_116 ) ;
if ( V_18 - sizeof( struct V_116 ) ) {
V_11 = F_92 ( V_2 -> V_8 , V_154 , V_18 - sizeof( struct V_116 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 ) {
F_3 ( L_44 ) ;
goto V_199;
}
F_3 ( L_45 ) ;
goto V_200;
}
}
if ( V_18 == 0 ||
( V_197 = F_82 ( V_2 , & T_5 , V_42 , V_141 ) ) < 0 ) {
F_26 ( L_24 V_164 L_46 ,
V_141 , T_5 . V_118 . V_18 , T_5 . V_118 . type ) ;
if ( F_93 ( V_141 & 7 ) )
V_141 &= ~ 7ULL ;
V_18 = 8 ;
}
V_141 += V_18 ;
if ( V_197 > 0 )
V_141 += V_197 ;
if ( ! F_94 () )
goto V_198;
V_199:
V_11 = 0 ;
V_200:
F_89 ( V_2 , V_42 ) ;
F_61 ( V_2 ) ;
return V_11 ;
}
static union V_95 *
F_95 ( struct V_1 * V_19 ,
T_1 V_141 , T_3 V_201 , char * V_202 )
{
union V_95 * T_5 ;
if ( V_141 + sizeof( T_5 -> V_118 ) > V_201 )
return NULL ;
T_5 = (union V_95 * ) ( V_202 + V_141 ) ;
if ( V_19 -> V_118 . V_190 )
F_84 ( & T_5 -> V_118 ) ;
if ( V_141 + T_5 -> V_118 . V_18 > V_201 )
return NULL ;
return T_5 ;
}
int F_96 ( struct V_1 * V_19 ,
T_1 V_203 , T_1 V_204 ,
T_1 V_205 , struct V_41 * V_42 )
{
T_1 V_141 , V_206 , V_149 , V_207 , V_208 ;
int V_11 , V_209 , V_210 , V_211 = 0 ;
struct V_212 * V_213 ;
T_3 V_214 , V_201 ;
char * V_202 , * V_215 [ 8 ] ;
union V_95 * T_5 ;
T_8 V_18 ;
F_49 ( V_42 ) ;
V_214 = F_97 ( V_216 ) ;
V_206 = V_214 * ( V_203 / V_214 ) ;
V_149 = V_206 ;
V_141 = V_203 - V_206 ;
if ( V_203 + V_204 < V_205 )
V_205 = V_203 + V_204 ;
V_208 = V_205 / 16 ;
V_213 = F_98 ( L_47 , V_205 ) ;
if ( V_213 == NULL )
return - 1 ;
V_201 = V_19 -> V_49 ;
if ( V_201 > V_205 )
V_201 = V_205 ;
memset ( V_215 , 0 , sizeof( V_215 ) ) ;
V_209 = V_217 ;
V_210 = V_218 ;
if ( V_19 -> V_118 . V_190 ) {
V_209 |= V_219 ;
V_210 = V_220 ;
}
V_221:
V_202 = V_99 ( NULL , V_201 , V_209 , V_210 , V_19 -> V_8 ,
V_149 ) ;
if ( V_202 == V_222 ) {
F_3 ( L_48 ) ;
V_11 = - V_12 ;
goto V_200;
}
V_215 [ V_211 ] = V_202 ;
V_211 = ( V_211 + 1 ) & ( F_99 ( V_215 ) - 1 ) ;
V_207 = V_149 + V_141 ;
V_198:
T_5 = F_95 ( V_19 , V_141 , V_201 , V_202 ) ;
if ( ! T_5 ) {
if ( V_215 [ V_211 ] ) {
F_100 ( V_215 [ V_211 ] , V_201 ) ;
V_215 [ V_211 ] = NULL ;
}
V_206 = V_214 * ( V_141 / V_214 ) ;
V_149 += V_206 ;
V_141 -= V_206 ;
goto V_221;
}
V_18 = T_5 -> V_118 . V_18 ;
if ( V_18 == 0 ||
F_82 ( V_19 , T_5 , V_42 , V_207 ) < 0 ) {
F_26 ( L_24 V_164 L_46 ,
V_149 + V_141 , T_5 -> V_118 . V_18 ,
T_5 -> V_118 . type ) ;
if ( F_93 ( V_141 & 7 ) )
V_141 &= ~ 7ULL ;
V_18 = 8 ;
}
V_141 += V_18 ;
V_207 += V_18 ;
if ( V_207 >= V_208 ) {
V_208 += V_205 / 16 ;
F_101 ( V_213 , V_207 ) ;
}
if ( V_207 < V_205 )
goto V_198;
V_11 = 0 ;
V_19 -> V_51 . V_145 = V_50 ;
F_64 ( V_19 , V_42 ) ;
V_200:
F_102 ( V_213 ) ;
F_89 ( V_19 , V_42 ) ;
F_61 ( V_19 ) ;
return V_11 ;
}
int F_103 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
int V_11 ;
if ( F_86 ( V_2 ) == NULL )
return - V_161 ;
if ( ! V_2 -> V_7 )
V_11 = F_96 ( V_2 ,
V_2 -> V_118 . V_203 ,
V_2 -> V_118 . V_204 ,
V_2 -> V_18 , V_42 ) ;
else
V_11 = F_91 ( V_2 , V_42 ) ;
return V_11 ;
}
bool F_104 ( struct V_1 * V_2 , const char * V_223 )
{
if ( ! ( V_2 -> V_22 & V_224 ) ) {
F_3 ( L_49 , V_223 ) ;
return false ;
}
return true ;
}
int F_105 ( struct V_94 * * V_225 ,
const char * V_226 ,
T_1 V_227 )
{
char * V_228 ;
enum V_229 V_75 ;
struct V_230 * V_231 ;
V_231 = F_23 ( sizeof( struct V_230 ) ) ;
if ( V_231 == NULL )
return - V_161 ;
V_231 -> V_68 = F_106 ( V_226 ) ;
if ( V_231 -> V_68 == NULL ) {
free ( V_231 ) ;
return - V_161 ;
}
V_228 = strchr ( V_231 -> V_68 , ']' ) ;
if ( V_228 )
* V_228 = '\0' ;
V_231 -> V_227 = V_227 ;
for ( V_75 = 0 ; V_75 < V_232 ; ++ V_75 ) {
struct V_233 * V_233 = F_107 ( V_225 [ V_75 ] ) ;
V_233 -> V_230 = V_231 ;
}
return 0 ;
}
T_3 F_108 ( struct V_1 * V_2 , T_9 * V_234 )
{
return F_109 ( & V_2 -> V_37 . V_235 , V_234 ) +
F_109 ( & V_2 -> V_37 . V_236 , V_234 ) +
F_110 ( & V_2 -> V_38 , V_234 ) ;
}
T_3 F_111 ( struct V_1 * V_2 , T_9 * V_234 ,
bool V_237 )
{
T_3 V_36 = F_112 ( & V_2 -> V_37 , V_234 , V_237 ) ;
return V_36 + F_113 ( & V_2 -> V_38 , V_234 , V_237 ) ;
}
T_3 F_114 ( struct V_1 * V_19 , T_9 * V_234 )
{
struct V_97 * V_238 ;
T_3 V_36 = fprintf ( V_234 , L_50 ) ;
V_36 += F_115 ( & V_19 -> V_170 , V_234 ) ;
F_116 (pos, &session->evlist->entries, node) {
V_36 += fprintf ( V_234 , L_51 , F_117 ( V_238 ) ) ;
V_36 += F_115 ( & V_238 -> V_170 , V_234 ) ;
}
return V_36 ;
}
struct V_97 * F_118 ( struct V_1 * V_19 ,
unsigned int type )
{
struct V_97 * V_238 ;
F_116 (pos, &session->evlist->entries, node) {
if ( V_238 -> V_107 . type == type )
return V_238 ;
}
return NULL ;
}
void F_119 ( union V_95 * T_5 ,
struct V_20 * T_6 ,
struct V_1 * V_19 )
{
struct V_80 V_81 ;
const char * V_239 , * V_240 ;
struct V_76 * V_241 = & V_19 -> V_76 ;
struct V_242 * V_62 ;
if ( F_120 ( T_5 , V_19 , & V_81 , T_6 ,
NULL ) < 0 ) {
error ( L_52 ,
T_5 -> V_118 . type ) ;
return;
}
if ( V_92 . V_93 && T_6 -> V_163 ) {
if ( F_41 ( V_19 , V_81 . V_59 ,
T_6 -> V_163 , NULL ) != 0 ) {
if ( V_243 )
error ( L_53 ) ;
return;
}
F_121 ( V_241 ) ;
while ( 1 ) {
V_62 = F_122 ( V_241 ) ;
if ( ! V_62 )
break;
if ( V_62 -> V_67 && V_62 -> V_67 -> V_68 )
V_239 = V_62 -> V_67 -> V_68 ;
else
V_239 = L_11 ;
if ( V_62 -> V_94 && V_62 -> V_94 -> V_244 && V_62 -> V_94 -> V_244 -> V_68 )
V_240 = V_62 -> V_94 -> V_244 -> V_68 ;
else
V_240 = L_11 ;
printf ( L_54 V_164 L_55 , V_62 -> V_78 , V_239 , V_240 ) ;
F_123 ( V_241 ) ;
}
} else {
if ( V_81 . V_67 && V_81 . V_67 -> V_68 )
V_239 = V_81 . V_67 -> V_68 ;
else
V_239 = L_11 ;
if ( V_81 . V_94 && V_81 . V_94 -> V_244 && V_81 . V_94 -> V_244 -> V_68 )
V_240 = V_81 . V_94 -> V_244 -> V_68 ;
else
V_240 = L_11 ;
printf ( L_56 V_164 L_57 , V_81 . V_227 , V_239 , V_240 ) ;
}
}

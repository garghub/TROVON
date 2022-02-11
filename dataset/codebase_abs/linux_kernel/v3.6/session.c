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
}
void F_41 ( struct V_45 * V_2 , struct V_46 * V_53 )
{
V_2 -> V_54 = NULL ;
F_37 ( & V_53 -> V_50 , & V_2 -> V_52 ) ;
F_42 ( & V_53 -> V_49 , & V_2 -> V_55 ) ;
}
static bool F_43 ( struct V_56 * V_57 )
{
if ( V_57 -> V_58 && ! regexec ( & V_59 , V_57 -> V_58 , 0 , NULL , 0 ) )
return 1 ;
return 0 ;
}
static void F_44 ( struct V_45 * V_2 , struct V_46 * V_46 ,
struct V_60 * V_61 ,
T_3 V_62 )
{
struct V_63 V_64 ;
T_2 V_65 ;
T_4 V_66 ;
memset ( & V_64 , 0 , sizeof( V_64 ) ) ;
for ( V_65 = 0 ; V_65 < V_67 ; V_65 ++ ) {
V_66 = V_68 [ V_65 ] ;
F_45 ( V_46 , V_2 , V_66 , V_69 ,
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
struct V_74 * F_46 ( struct V_45 * V_2 ,
struct V_46 * V_75 ,
struct V_76 * V_77 )
{
struct V_74 * V_78 ;
unsigned int V_65 ;
V_78 = calloc ( V_77 -> V_79 , sizeof( struct V_74 ) ) ;
if ( ! V_78 )
return NULL ;
for ( V_65 = 0 ; V_65 < V_77 -> V_79 ; V_65 ++ ) {
F_44 ( V_2 , V_75 , & V_78 [ V_65 ] . V_80 , V_77 -> V_81 [ V_65 ] . V_80 ) ;
F_44 ( V_2 , V_75 , & V_78 [ V_65 ] . V_82 , V_77 -> V_81 [ V_65 ] . V_82 ) ;
V_78 [ V_65 ] . V_83 = V_77 -> V_81 [ V_65 ] . V_83 ;
}
return V_78 ;
}
int F_47 ( struct V_45 * V_2 ,
struct V_46 * V_46 ,
struct V_84 * V_85 ,
struct V_56 * * V_86 )
{
T_4 V_87 = V_88 ;
unsigned int V_65 ;
int V_11 ;
F_48 ( & V_89 ) ;
if ( V_85 -> V_79 > V_90 ) {
F_49 ( L_13 ) ;
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
V_87 = V_97 ; break;
case V_98 :
V_87 = V_99 ; break;
case V_100 :
V_87 = V_88 ; break;
default:
F_50 ( L_14
L_15 V_101 L_6 , ( V_102 ) V_62 ) ;
F_48 ( & V_89 ) ;
return 0 ;
}
continue;
}
V_64 . V_103 = false ;
F_45 ( V_46 , V_2 , V_87 ,
V_69 , V_62 , & V_64 , NULL ) ;
if ( V_64 . V_57 != NULL ) {
if ( V_104 && ! * V_86 &&
F_43 ( V_64 . V_57 ) )
* V_86 = V_64 . V_57 ;
if ( ! V_105 . V_106 )
break;
}
V_11 = F_51 ( & V_89 ,
V_62 , V_64 . V_73 , V_64 . V_57 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_52 ( union V_107 * T_5 V_108 ,
struct V_1 * V_19 V_108 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static int F_53 ( union V_107 * T_5 V_108 ,
struct V_109 * * T_6 V_108 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static int F_54 ( struct V_26 * V_27 V_108 ,
union V_107 * T_5 V_108 ,
struct V_110 * T_7 V_108 ,
struct V_111 * T_8 V_108 ,
struct V_45 * V_45 V_108 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static int F_55 ( struct V_26 * V_27 V_108 ,
union V_107 * T_5 V_108 ,
struct V_110 * T_7 V_108 ,
struct V_45 * V_45 V_108 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static int F_56 ( struct V_26 * V_27 V_108 ,
union V_107 * T_5 V_108 ,
struct V_1 * V_1 V_108 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static int F_57 ( struct V_26 * V_27 V_108 ,
union V_107 * T_5 V_108 )
{
F_27 ( L_16 ) ;
return 0 ;
}
static void F_58 ( struct V_26 * V_27 )
{
if ( V_27 -> T_7 == NULL )
V_27 -> T_7 = F_54 ;
if ( V_27 -> V_112 == NULL )
V_27 -> V_112 = F_55 ;
if ( V_27 -> V_113 == NULL )
V_27 -> V_113 = F_55 ;
if ( V_27 -> V_114 == NULL )
V_27 -> V_114 = F_55 ;
if ( V_27 -> exit == NULL )
V_27 -> exit = F_55 ;
if ( V_27 -> V_115 == NULL )
V_27 -> V_115 = V_116 ;
if ( V_27 -> V_117 == NULL )
V_27 -> V_117 = F_54 ;
if ( V_27 -> V_118 == NULL )
V_27 -> V_118 = F_55 ;
if ( V_27 -> V_119 == NULL )
V_27 -> V_119 = F_55 ;
if ( V_27 -> V_120 == NULL )
V_27 -> V_120 = F_53 ;
if ( V_27 -> V_121 == NULL )
V_27 -> V_121 = F_57 ;
if ( V_27 -> V_122 == NULL )
V_27 -> V_122 = F_52 ;
if ( V_27 -> V_123 == NULL )
V_27 -> V_123 = F_56 ;
if ( V_27 -> V_124 == NULL ) {
if ( V_27 -> V_36 )
V_27 -> V_124 = V_125 ;
else
V_27 -> V_124 = F_56 ;
}
}
void F_59 ( void * V_126 , int V_127 )
{
T_9 * V_66 = V_126 ;
while ( V_127 > 0 ) {
* V_66 = F_60 ( * V_66 ) ;
V_127 -= sizeof( T_9 ) ;
++ V_66 ;
}
}
void F_61 ( void * V_126 , int V_127 )
{
T_3 * V_66 = V_126 ;
while ( V_127 > 0 ) {
* V_66 = F_62 ( * V_66 ) ;
V_127 -= sizeof( T_3 ) ;
++ V_66 ;
}
}
static void F_63 ( union V_107 * T_5 , void * V_128 )
{
void * V_129 = ( void * ) T_5 + T_5 -> V_130 . V_18 ;
int V_18 = V_129 - V_128 ;
F_64 ( V_18 % sizeof( T_3 ) ) ;
F_61 ( V_128 , V_18 ) ;
}
static void F_65 ( union V_107 * T_5 ,
bool T_10 V_108 )
{
struct V_131 * V_132 = & T_5 -> V_130 ;
F_61 ( V_132 + 1 , T_5 -> V_130 . V_18 - sizeof( * V_132 ) ) ;
}
static void F_66 ( union V_107 * T_5 , bool T_10 )
{
T_5 -> V_113 . V_133 = F_60 ( T_5 -> V_113 . V_133 ) ;
T_5 -> V_113 . V_134 = F_60 ( T_5 -> V_113 . V_134 ) ;
if ( T_10 ) {
void * V_128 = & T_5 -> V_113 . V_113 ;
V_128 += F_67 ( strlen ( V_128 ) + 1 , sizeof( T_3 ) ) ;
F_63 ( T_5 , V_128 ) ;
}
}
static void F_68 ( union V_107 * T_5 ,
bool T_10 )
{
T_5 -> V_112 . V_133 = F_60 ( T_5 -> V_112 . V_133 ) ;
T_5 -> V_112 . V_134 = F_60 ( T_5 -> V_112 . V_134 ) ;
T_5 -> V_112 . V_135 = F_62 ( T_5 -> V_112 . V_135 ) ;
T_5 -> V_112 . V_29 = F_62 ( T_5 -> V_112 . V_29 ) ;
T_5 -> V_112 . V_136 = F_62 ( T_5 -> V_112 . V_136 ) ;
if ( T_10 ) {
void * V_128 = & T_5 -> V_112 . V_6 ;
V_128 += F_67 ( strlen ( V_128 ) + 1 , sizeof( T_3 ) ) ;
F_63 ( T_5 , V_128 ) ;
}
}
static void F_69 ( union V_107 * T_5 , bool T_10 )
{
T_5 -> V_114 . V_133 = F_60 ( T_5 -> V_114 . V_133 ) ;
T_5 -> V_114 . V_134 = F_60 ( T_5 -> V_114 . V_134 ) ;
T_5 -> V_114 . V_137 = F_60 ( T_5 -> V_114 . V_137 ) ;
T_5 -> V_114 . V_138 = F_60 ( T_5 -> V_114 . V_138 ) ;
T_5 -> V_114 . time = F_62 ( T_5 -> V_114 . time ) ;
if ( T_10 )
F_63 ( T_5 , & T_5 -> V_114 + 1 ) ;
}
static void F_70 ( union V_107 * T_5 , bool T_10 )
{
T_5 -> V_117 . V_133 = F_60 ( T_5 -> V_117 . V_133 ) ;
T_5 -> V_117 . V_134 = F_60 ( T_5 -> V_117 . V_134 ) ;
T_5 -> V_117 . V_139 = F_62 ( T_5 -> V_117 . V_139 ) ;
T_5 -> V_117 . V_140 = F_62 ( T_5 -> V_117 . V_140 ) ;
T_5 -> V_117 . V_141 = F_62 ( T_5 -> V_117 . V_141 ) ;
T_5 -> V_117 . V_142 = F_62 ( T_5 -> V_117 . V_142 ) ;
if ( T_10 )
F_63 ( T_5 , & T_5 -> V_117 + 1 ) ;
}
static T_4 F_71 ( T_4 V_143 )
{
int V_144 = ( V_143 >> 4 ) | ( ( V_143 & 0xf ) << 4 ) ;
V_144 = ( ( V_144 & 0xcc ) >> 2 ) | ( ( V_144 & 0x33 ) << 2 ) ;
V_144 = ( ( V_144 & 0xaa ) >> 1 ) | ( ( V_144 & 0x55 ) << 1 ) ;
return ( T_4 ) V_144 ;
}
static void F_72 ( T_4 * V_145 , unsigned V_29 )
{
unsigned V_65 ;
for ( V_65 = 0 ; V_65 < V_29 ; V_65 ++ ) {
* V_145 = F_71 ( * V_145 ) ;
V_145 ++ ;
}
}
void F_73 ( struct V_146 * V_120 )
{
V_120 -> type = F_60 ( V_120 -> type ) ;
V_120 -> V_18 = F_60 ( V_120 -> V_18 ) ;
V_120 -> V_147 = F_62 ( V_120 -> V_147 ) ;
V_120 -> V_148 = F_62 ( V_120 -> V_148 ) ;
V_120 -> V_149 = F_62 ( V_120 -> V_149 ) ;
V_120 -> V_150 = F_62 ( V_120 -> V_150 ) ;
V_120 -> V_151 = F_60 ( V_120 -> V_151 ) ;
V_120 -> V_152 = F_60 ( V_120 -> V_152 ) ;
V_120 -> V_153 = F_62 ( V_120 -> V_153 ) ;
V_120 -> V_154 = F_62 ( V_120 -> V_154 ) ;
F_72 ( ( T_4 * ) ( & V_120 -> V_150 + 1 ) , sizeof( T_3 ) ) ;
}
static void F_74 ( union V_107 * T_5 ,
bool T_10 V_108 )
{
T_2 V_18 ;
F_73 ( & T_5 -> V_120 . V_120 ) ;
V_18 = T_5 -> V_130 . V_18 ;
V_18 -= ( void * ) & T_5 -> V_120 . V_142 - ( void * ) T_5 ;
F_61 ( T_5 -> V_120 . V_142 , V_18 ) ;
}
static void F_75 ( union V_107 * T_5 ,
bool T_10 V_108 )
{
T_5 -> V_121 . V_121 . V_155 =
F_62 ( T_5 -> V_121 . V_121 . V_155 ) ;
}
static void F_76 ( union V_107 * T_5 ,
bool T_10 V_108 )
{
T_5 -> V_122 . V_18 = F_60 ( T_5 -> V_122 . V_18 ) ;
}
static void F_77 ( struct V_1 * V_19 )
{
struct V_36 * V_156 = & V_19 -> V_36 ;
while ( ! F_78 ( & V_156 -> V_39 ) ) {
struct V_157 * V_158 ;
V_158 = F_79 ( V_156 -> V_39 . V_159 , struct V_157 , V_160 ) ;
F_31 ( & V_158 -> V_160 ) ;
free ( V_158 ) ;
}
}
static void F_80 ( struct V_1 * V_161 ,
struct V_26 * V_27 )
{
struct V_36 * V_156 = & V_161 -> V_36 ;
struct V_162 * V_163 = & V_156 -> V_37 ;
struct V_157 * V_164 , * V_165 ;
struct V_110 T_7 ;
T_3 V_166 = V_156 -> V_167 ;
T_3 V_168 = V_156 -> V_169 ? V_156 -> V_169 -> V_170 : 0ULL ;
unsigned V_171 = 0 , V_172 = V_156 -> V_173 / 16 ;
int V_23 ;
if ( ! V_27 -> V_36 || ! V_166 )
return;
F_30 (iter, tmp, head, list) {
if ( V_165 -> V_170 > V_166 )
break;
V_23 = F_81 ( V_161 -> V_17 , V_165 -> T_5 , & T_7 ,
V_161 -> V_130 . V_174 ) ;
if ( V_23 )
F_3 ( L_17 , V_23 ) ;
else
F_82 ( V_161 , V_165 -> T_5 , & T_7 , V_27 ,
V_165 -> V_175 ) ;
V_156 -> V_176 = V_165 -> V_170 ;
F_31 ( & V_165 -> V_160 ) ;
F_83 ( & V_165 -> V_160 , & V_156 -> V_38 ) ;
if ( ++ V_171 >= V_172 ) {
V_172 += V_156 -> V_173 / 16 ;
F_84 ( V_171 , V_156 -> V_173 ,
L_18 ) ;
}
}
if ( F_78 ( V_163 ) ) {
V_156 -> V_169 = NULL ;
} else if ( V_168 <= V_166 ) {
V_156 -> V_169 =
F_79 ( V_163 -> V_177 , struct V_157 , V_160 ) ;
}
V_156 -> V_173 = 0 ;
}
static int V_125 ( struct V_26 * V_27 ,
union V_107 * T_5 V_108 ,
struct V_1 * V_19 )
{
F_80 ( V_19 , V_27 ) ;
V_19 -> V_36 . V_167 = V_19 -> V_36 . V_178 ;
return 0 ;
}
static void F_85 ( struct V_157 * V_179 , struct V_1 * V_161 )
{
struct V_36 * V_156 = & V_161 -> V_36 ;
struct V_157 * T_7 = V_156 -> V_169 ;
T_3 V_170 = V_179 -> V_170 ;
struct V_162 * V_145 ;
++ V_156 -> V_173 ;
V_156 -> V_169 = V_179 ;
if ( ! T_7 ) {
F_83 ( & V_179 -> V_160 , & V_156 -> V_37 ) ;
V_156 -> V_178 = V_170 ;
return;
}
if ( T_7 -> V_170 <= V_170 ) {
while ( T_7 -> V_170 <= V_170 ) {
V_145 = T_7 -> V_160 . V_159 ;
if ( V_145 == & V_156 -> V_37 ) {
F_42 ( & V_179 -> V_160 , & V_156 -> V_37 ) ;
V_156 -> V_178 = V_170 ;
return;
}
T_7 = F_79 ( V_145 , struct V_157 , V_160 ) ;
}
F_42 ( & V_179 -> V_160 , & T_7 -> V_160 ) ;
} else {
while ( T_7 -> V_170 > V_170 ) {
V_145 = T_7 -> V_160 . V_177 ;
if ( V_145 == & V_156 -> V_37 ) {
F_83 ( & V_179 -> V_160 , & V_156 -> V_37 ) ;
return;
}
T_7 = F_79 ( V_145 , struct V_157 , V_160 ) ;
}
F_83 ( & V_179 -> V_160 , & T_7 -> V_160 ) ;
}
}
static int F_86 ( struct V_1 * V_161 , union V_107 * T_5 ,
struct V_110 * T_7 , T_3 V_175 )
{
struct V_36 * V_156 = & V_161 -> V_36 ;
struct V_162 * V_180 = & V_156 -> V_38 ;
T_3 V_170 = T_7 -> time ;
struct V_157 * V_179 ;
if ( ! V_170 || V_170 == ~ 0ULL )
return - V_181 ;
if ( V_170 < V_161 -> V_36 . V_176 ) {
printf ( L_19 ) ;
return - V_182 ;
}
if ( ! F_78 ( V_180 ) ) {
V_179 = F_79 ( V_180 -> V_159 , struct V_157 , V_160 ) ;
F_31 ( & V_179 -> V_160 ) ;
} else if ( V_156 -> V_183 ) {
V_179 = V_156 -> V_183 + V_156 -> V_184 ;
if ( ++ V_156 -> V_184 == V_185 )
V_156 -> V_183 = NULL ;
} else {
V_156 -> V_183 = malloc ( V_185 * sizeof( * V_179 ) ) ;
if ( ! V_156 -> V_183 )
return - V_186 ;
F_83 ( & V_156 -> V_183 -> V_160 , & V_156 -> V_39 ) ;
V_156 -> V_184 = 2 ;
V_179 = V_156 -> V_183 + 1 ;
}
V_179 -> V_170 = V_170 ;
V_179 -> V_175 = V_175 ;
V_179 -> T_5 = T_5 ;
F_85 ( V_179 , V_161 ) ;
return 0 ;
}
static void F_87 ( struct V_110 * T_7 )
{
unsigned int V_65 ;
printf ( L_20 V_187 L_6 , T_7 -> V_188 -> V_79 ) ;
for ( V_65 = 0 ; V_65 < T_7 -> V_188 -> V_79 ; V_65 ++ )
printf ( L_21 V_189 L_6 ,
V_65 , T_7 -> V_188 -> V_94 [ V_65 ] ) ;
}
static void F_88 ( struct V_110 * T_7 )
{
T_11 V_65 ;
printf ( L_22 V_187 L_6 , T_7 -> V_76 -> V_79 ) ;
for ( V_65 = 0 ; V_65 < T_7 -> V_76 -> V_79 ; V_65 ++ )
printf ( L_23 V_187 L_24 V_189 L_25 V_189 L_6 ,
V_65 , T_7 -> V_76 -> V_81 [ V_65 ] . V_82 ,
T_7 -> V_76 -> V_81 [ V_65 ] . V_80 ) ;
}
static void F_89 ( struct V_1 * V_19 ,
union V_107 * T_5 ,
struct V_110 * T_7 )
{
T_3 V_149 = F_90 ( V_19 -> V_17 ) ;
if ( T_5 -> V_130 . type != V_190 &&
! F_26 ( V_19 -> V_17 ) ) {
fputs ( L_26 , stdout ) ;
return;
}
if ( ( V_149 & V_191 ) )
printf ( L_27 , T_7 -> V_192 ) ;
if ( V_149 & V_193 )
printf ( L_15 V_187 L_28 , T_7 -> time ) ;
}
static void F_91 ( struct V_1 * V_19 , union V_107 * T_5 ,
T_3 V_175 , struct V_110 * T_7 )
{
if ( ! V_194 )
return;
printf ( L_29 V_189 L_30 ,
V_175 , T_5 -> V_130 . V_18 , T_5 -> V_130 . type ) ;
F_92 ( T_5 ) ;
if ( T_7 )
F_89 ( V_19 , T_5 , T_7 ) ;
printf ( L_31 V_189 L_32 , V_175 ,
T_5 -> V_130 . V_18 , F_93 ( T_5 -> V_130 . type ) ) ;
}
static void F_94 ( struct V_1 * V_19 , union V_107 * T_5 ,
struct V_110 * T_7 )
{
T_3 V_149 ;
if ( ! V_194 )
return;
printf ( L_33 V_189 L_34 V_187 L_35 V_189 L_6 ,
T_5 -> V_130 . V_195 , T_7 -> V_133 , T_7 -> V_134 , T_7 -> V_62 ,
T_7 -> V_196 , T_7 -> V_71 ) ;
V_149 = F_90 ( V_19 -> V_17 ) ;
if ( V_149 & V_197 )
F_87 ( T_7 ) ;
if ( V_149 & V_198 )
F_88 ( T_7 ) ;
}
static struct V_45 *
F_95 ( struct V_1 * V_19 ,
union V_107 * T_5 )
{
const T_4 V_87 = T_5 -> V_130 . V_195 & V_199 ;
if ( V_200 &&
( ( V_87 == V_201 ) ||
( V_87 == V_202 ) ) ) {
T_9 V_133 ;
if ( T_5 -> V_130 . type == V_203 )
V_133 = T_5 -> V_112 . V_133 ;
else
V_133 = T_5 -> V_62 . V_133 ;
return F_96 ( V_19 , V_133 ) ;
}
return F_97 ( V_19 ) ;
}
static int F_82 ( struct V_1 * V_19 ,
union V_107 * T_5 ,
struct V_110 * T_7 ,
struct V_26 * V_27 ,
T_3 V_175 )
{
struct V_111 * T_8 ;
struct V_45 * V_45 ;
F_91 ( V_19 , T_5 , V_175 , T_7 ) ;
T_8 = F_98 ( V_19 -> V_17 , T_7 -> V_142 ) ;
if ( T_8 != NULL && T_5 -> V_130 . type != V_190 ) {
F_99 ( & T_8 -> V_41 , T_5 -> V_130 . type ) ;
}
V_45 = F_95 ( V_19 , T_5 ) ;
switch ( T_5 -> V_130 . type ) {
case V_190 :
F_94 ( V_19 , T_5 , T_7 ) ;
if ( T_8 == NULL ) {
++ V_19 -> V_41 . V_204 . V_205 ;
return 0 ;
}
if ( V_45 == NULL ) {
++ V_19 -> V_41 . V_204 . V_206 ;
return 0 ;
}
return V_27 -> T_7 ( V_27 , T_5 , T_7 , T_8 , V_45 ) ;
case V_203 :
return V_27 -> V_112 ( V_27 , T_5 , T_7 , V_45 ) ;
case V_207 :
return V_27 -> V_113 ( V_27 , T_5 , T_7 , V_45 ) ;
case V_208 :
return V_27 -> V_114 ( V_27 , T_5 , T_7 , V_45 ) ;
case V_209 :
return V_27 -> exit ( V_27 , T_5 , T_7 , V_45 ) ;
case V_210 :
if ( V_27 -> V_115 == V_116 )
V_19 -> V_41 . V_204 . V_211 += T_5 -> V_115 . V_115 ;
return V_27 -> V_115 ( V_27 , T_5 , T_7 , V_45 ) ;
case V_212 :
return V_27 -> V_117 ( V_27 , T_5 , T_7 , T_8 , V_45 ) ;
case V_213 :
return V_27 -> V_118 ( V_27 , T_5 , T_7 , V_45 ) ;
case V_214 :
return V_27 -> V_119 ( V_27 , T_5 , T_7 , V_45 ) ;
default:
++ V_19 -> V_41 . V_204 . V_215 ;
return - 1 ;
}
}
static int F_100 ( struct V_1 * V_19 ,
union V_107 * T_5 , struct V_110 * T_7 )
{
if ( T_5 -> V_130 . type != V_190 ||
! ( F_90 ( V_19 -> V_17 ) & V_197 ) )
return 0 ;
if ( ! F_101 ( T_7 -> V_188 , T_5 ) ) {
F_50 ( L_36 ) ;
++ V_19 -> V_41 . V_204 . V_216 ;
V_19 -> V_41 . V_204 . V_217 += T_7 -> V_196 ;
return - V_182 ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_19 , union V_107 * T_5 ,
struct V_26 * V_27 , T_3 V_175 )
{
int V_11 ;
F_91 ( V_19 , T_5 , V_175 , NULL ) ;
switch ( T_5 -> V_130 . type ) {
case V_218 :
V_11 = V_27 -> V_120 ( T_5 , & V_19 -> V_17 ) ;
if ( V_11 == 0 )
F_11 ( V_19 ) ;
return V_11 ;
case V_219 :
return V_27 -> V_121 ( V_27 , T_5 ) ;
case V_220 :
F_103 ( V_19 -> V_8 , V_175 , V_221 ) ;
return V_27 -> V_122 ( T_5 , V_19 ) ;
case V_222 :
return V_27 -> V_123 ( V_27 , T_5 , V_19 ) ;
case V_223 :
return V_27 -> V_124 ( V_27 , T_5 , V_19 ) ;
default:
return - V_182 ;
}
}
static void F_104 ( union V_107 * T_5 , bool T_10 )
{
T_12 V_224 ;
V_224 = V_225 [ T_5 -> V_130 . type ] ;
if ( V_224 )
V_224 ( T_5 , T_10 ) ;
}
static int F_105 ( struct V_1 * V_19 ,
union V_107 * T_5 ,
struct V_26 * V_27 ,
T_3 V_175 )
{
struct V_110 T_7 ;
int V_23 ;
if ( V_19 -> V_130 . V_174 )
F_104 ( T_5 , F_26 ( V_19 -> V_17 ) ) ;
if ( T_5 -> V_130 . type >= V_226 )
return - V_182 ;
F_99 ( & V_19 -> V_41 , T_5 -> V_130 . type ) ;
if ( T_5 -> V_130 . type >= V_227 )
return F_102 ( V_19 , T_5 , V_27 , V_175 ) ;
V_23 = F_81 ( V_19 -> V_17 , T_5 , & T_7 ,
V_19 -> V_130 . V_174 ) ;
if ( V_23 )
return V_23 ;
if ( F_100 ( V_19 , T_5 , & T_7 ) )
return 0 ;
if ( V_27 -> V_36 ) {
V_23 = F_86 ( V_19 , T_5 , & T_7 ,
V_175 ) ;
if ( V_23 != - V_181 )
return V_23 ;
}
return F_82 ( V_19 , T_5 , & T_7 , V_27 ,
V_175 ) ;
}
void F_106 ( struct V_131 * V_2 )
{
V_2 -> type = F_60 ( V_2 -> type ) ;
V_2 -> V_195 = F_107 ( V_2 -> V_195 ) ;
V_2 -> V_18 = F_107 ( V_2 -> V_18 ) ;
}
struct V_46 * F_108 ( struct V_1 * V_19 , T_13 V_133 )
{
return F_109 ( & V_19 -> V_21 , V_133 ) ;
}
static struct V_46 * F_110 ( struct V_1 * V_2 )
{
struct V_46 * V_46 = F_108 ( V_2 , 0 ) ;
if ( V_46 == NULL || F_111 ( V_46 , L_37 ) ) {
F_3 ( L_38 ) ;
V_46 = NULL ;
}
return V_46 ;
}
static void F_112 ( const struct V_1 * V_19 ,
const struct V_26 * V_27 )
{
if ( V_27 -> V_115 == V_116 &&
V_19 -> V_41 . V_204 . V_228 [ V_210 ] != 0 ) {
F_113 ( L_39
L_40 ,
V_19 -> V_41 . V_204 . V_228 [ 0 ] ,
V_19 -> V_41 . V_204 . V_228 [ V_210 ] ) ;
}
if ( V_19 -> V_41 . V_204 . V_215 != 0 ) {
F_113 ( L_41
L_42
L_43
L_44
L_45 ,
V_19 -> V_41 . V_204 . V_215 ) ;
}
if ( V_19 -> V_41 . V_204 . V_205 != 0 ) {
F_113 ( L_46 ,
V_19 -> V_41 . V_204 . V_205 ) ;
}
if ( V_19 -> V_41 . V_204 . V_216 != 0 ) {
F_113 ( L_47
L_48
L_49 ,
V_19 -> V_41 . V_204 . V_216 ,
V_19 -> V_41 . V_204 . V_228 [ V_190 ] ) ;
}
if ( V_19 -> V_41 . V_204 . V_206 != 0 ) {
F_113 ( L_50
L_51 ,
V_19 -> V_41 . V_204 . V_206 ) ;
}
}
static int F_114 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
union V_107 * T_5 ;
T_14 V_18 , V_229 = 0 ;
void * V_230 = NULL ;
int V_231 = 0 ;
T_3 V_163 ;
int V_11 ;
void * V_145 ;
F_58 ( V_27 ) ;
V_163 = 0 ;
V_229 = sizeof( union V_107 ) ;
V_230 = malloc ( V_229 ) ;
if ( ! V_230 )
return - V_12 ;
V_232:
T_5 = V_230 ;
V_11 = F_115 ( V_2 -> V_8 , T_5 , sizeof( struct V_131 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 )
goto V_233;
F_3 ( L_52 ) ;
goto V_234;
}
if ( V_2 -> V_130 . V_174 )
F_106 ( & T_5 -> V_130 ) ;
V_18 = T_5 -> V_130 . V_18 ;
if ( V_18 == 0 )
V_18 = 8 ;
if ( V_18 > V_229 ) {
void * V_179 = realloc ( V_230 , V_18 ) ;
if ( ! V_179 ) {
F_3 ( L_53 ) ;
goto V_234;
}
V_230 = V_179 ;
V_229 = V_18 ;
T_5 = V_230 ;
}
V_145 = T_5 ;
V_145 += sizeof( struct V_131 ) ;
if ( V_18 - sizeof( struct V_131 ) ) {
V_11 = F_115 ( V_2 -> V_8 , V_145 , V_18 - sizeof( struct V_131 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 ) {
F_3 ( L_54 ) ;
goto V_233;
}
F_3 ( L_55 ) ;
goto V_234;
}
}
if ( ( V_231 = F_105 ( V_2 , T_5 , V_27 , V_163 ) ) < 0 ) {
F_3 ( L_31 V_189 L_56 ,
V_163 , T_5 -> V_130 . V_18 , T_5 -> V_130 . type ) ;
V_11 = - V_182 ;
goto V_234;
}
V_163 += V_18 ;
if ( V_231 > 0 )
V_163 += V_231 ;
if ( ! F_116 () )
goto V_232;
V_233:
V_11 = 0 ;
V_234:
free ( V_230 ) ;
F_112 ( V_2 , V_27 ) ;
F_77 ( V_2 ) ;
return V_11 ;
}
static union V_107 *
F_117 ( struct V_1 * V_19 ,
T_3 V_163 , T_2 V_235 , char * V_230 )
{
union V_107 * T_5 ;
if ( V_163 + sizeof( T_5 -> V_130 ) > V_235 )
return NULL ;
T_5 = (union V_107 * ) ( V_230 + V_163 ) ;
if ( V_19 -> V_130 . V_174 )
F_106 ( & T_5 -> V_130 ) ;
if ( V_163 + T_5 -> V_130 . V_18 > V_235 )
return NULL ;
return T_5 ;
}
int F_118 ( struct V_1 * V_19 ,
T_3 V_236 , T_3 V_237 ,
T_3 V_238 , struct V_26 * V_27 )
{
T_3 V_163 , V_239 , V_175 , V_240 , V_172 ;
int V_11 , V_241 , V_242 , V_243 = 0 ;
T_2 V_244 , V_235 ;
char * V_230 , * V_245 [ 8 ] ;
union V_107 * T_5 ;
T_14 V_18 ;
F_58 ( V_27 ) ;
V_244 = F_119 ( V_246 ) ;
V_239 = V_244 * ( V_236 / V_244 ) ;
V_175 = V_239 ;
V_163 = V_236 - V_239 ;
if ( V_236 + V_237 < V_238 )
V_238 = V_236 + V_237 ;
V_172 = V_238 / 16 ;
V_235 = V_19 -> V_33 ;
if ( V_235 > V_238 )
V_235 = V_238 ;
memset ( V_245 , 0 , sizeof( V_245 ) ) ;
V_241 = V_247 ;
V_242 = V_248 ;
if ( V_19 -> V_130 . V_174 ) {
V_241 |= V_249 ;
V_242 = V_250 ;
}
V_251:
V_230 = V_112 ( NULL , V_235 , V_241 , V_242 , V_19 -> V_8 ,
V_175 ) ;
if ( V_230 == V_252 ) {
F_3 ( L_57 ) ;
V_11 = - V_12 ;
goto V_234;
}
V_245 [ V_243 ] = V_230 ;
V_243 = ( V_243 + 1 ) & ( F_120 ( V_245 ) - 1 ) ;
V_240 = V_175 + V_163 ;
V_232:
T_5 = F_117 ( V_19 , V_163 , V_235 , V_230 ) ;
if ( ! T_5 ) {
if ( V_245 [ V_243 ] ) {
F_121 ( V_245 [ V_243 ] , V_235 ) ;
V_245 [ V_243 ] = NULL ;
}
V_239 = V_244 * ( V_163 / V_244 ) ;
V_175 += V_239 ;
V_163 -= V_239 ;
goto V_251;
}
V_18 = T_5 -> V_130 . V_18 ;
if ( V_18 == 0 ||
F_105 ( V_19 , T_5 , V_27 , V_240 ) < 0 ) {
F_3 ( L_31 V_189 L_56 ,
V_175 + V_163 , T_5 -> V_130 . V_18 ,
T_5 -> V_130 . type ) ;
V_11 = - V_182 ;
goto V_234;
}
V_163 += V_18 ;
V_240 += V_18 ;
if ( V_240 >= V_172 ) {
V_172 += V_238 / 16 ;
F_84 ( V_240 , V_238 ,
L_58 ) ;
}
if ( V_240 < V_238 )
goto V_232;
V_11 = 0 ;
V_19 -> V_36 . V_167 = V_34 ;
F_80 ( V_19 , V_27 ) ;
V_234:
F_112 ( V_19 , V_27 ) ;
F_77 ( V_19 ) ;
return V_11 ;
}
int F_122 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
int V_11 ;
if ( F_110 ( V_2 ) == NULL )
return - V_186 ;
if ( ! V_2 -> V_7 )
V_11 = F_118 ( V_2 ,
V_2 -> V_130 . V_236 ,
V_2 -> V_130 . V_237 ,
V_2 -> V_18 , V_27 ) ;
else
V_11 = F_114 ( V_2 , V_27 ) ;
return V_11 ;
}
bool F_123 ( struct V_1 * V_19 , const char * V_253 )
{
if ( ! ( F_90 ( V_19 -> V_17 ) & V_254 ) ) {
F_3 ( L_59 , V_253 ) ;
return false ;
}
return true ;
}
int F_124 ( struct V_73 * * V_255 ,
const char * V_256 , T_3 V_71 )
{
char * V_257 ;
enum V_258 V_65 ;
struct V_259 * V_260 ;
V_260 = F_22 ( sizeof( struct V_259 ) ) ;
if ( V_260 == NULL )
return - V_186 ;
V_260 -> V_58 = F_125 ( V_256 ) ;
if ( V_260 -> V_58 == NULL ) {
free ( V_260 ) ;
return - V_186 ;
}
V_257 = strchr ( V_260 -> V_58 , ']' ) ;
if ( V_257 )
* V_257 = '\0' ;
V_260 -> V_71 = V_71 ;
for ( V_65 = 0 ; V_65 < V_261 ; ++ V_65 ) {
struct V_262 * V_262 = F_126 ( V_255 [ V_65 ] ) ;
V_262 -> V_259 = V_260 ;
}
return 0 ;
}
T_2 F_127 ( struct V_1 * V_2 , T_15 * V_263 )
{
return F_128 ( & V_2 -> V_21 . V_264 , V_263 ) +
F_128 ( & V_2 -> V_21 . V_265 , V_263 ) +
F_129 ( & V_2 -> V_22 , V_263 ) ;
}
T_2 F_130 ( struct V_1 * V_2 , T_15 * V_263 ,
bool V_266 )
{
T_2 V_23 = F_131 ( & V_2 -> V_21 , V_263 , V_266 ) ;
return V_23 + F_132 ( & V_2 -> V_22 , V_263 , V_266 ) ;
}
T_2 F_133 ( struct V_1 * V_19 , T_15 * V_263 )
{
struct V_111 * V_267 ;
T_2 V_23 = fprintf ( V_263 , L_60 ) ;
V_23 += F_134 ( & V_19 -> V_41 , V_263 ) ;
F_135 (pos, &session->evlist->entries, node) {
V_23 += fprintf ( V_263 , L_61 , F_136 ( V_267 ) ) ;
V_23 += F_134 ( & V_267 -> V_41 , V_263 ) ;
}
return V_23 ;
}
T_2 F_137 ( struct V_1 * V_19 , T_15 * V_263 )
{
return F_138 ( & V_19 -> V_21 , V_263 ) ;
}
void F_139 ( struct V_1 * V_19 ,
struct V_46 * V_53 )
{
F_41 ( & V_19 -> V_21 , V_53 ) ;
}
struct V_111 * F_140 ( struct V_1 * V_19 ,
unsigned int type )
{
struct V_111 * V_267 ;
F_135 (pos, &session->evlist->entries, node) {
if ( V_267 -> V_120 . type == type )
return V_267 ;
}
return NULL ;
}
void F_141 ( union V_107 * T_5 , struct V_110 * T_7 ,
struct V_45 * V_45 , int V_268 ,
int V_269 , int V_270 )
{
struct V_63 V_64 ;
struct V_271 * V_49 ;
if ( F_142 ( T_5 , V_45 , & V_64 , T_7 ,
NULL ) < 0 ) {
error ( L_62 ,
T_5 -> V_130 . type ) ;
return;
}
if ( V_105 . V_106 && T_7 -> V_188 ) {
if ( F_47 ( V_45 , V_64 . V_46 ,
T_7 -> V_188 , NULL ) != 0 ) {
if ( V_272 )
error ( L_63 ) ;
return;
}
F_143 ( & V_89 ) ;
while ( 1 ) {
V_49 = F_144 ( & V_89 ) ;
if ( ! V_49 )
break;
printf ( L_64 V_189 , V_49 -> V_62 ) ;
if ( V_268 ) {
printf ( L_28 ) ;
F_145 ( V_49 -> V_57 , stdout ) ;
}
if ( V_269 ) {
printf ( L_65 ) ;
F_146 ( V_49 -> V_73 , stdout ) ;
printf ( L_66 ) ;
}
printf ( L_6 ) ;
F_147 ( & V_89 ) ;
}
} else {
printf ( L_67 V_189 , T_7 -> V_62 ) ;
if ( V_268 ) {
printf ( L_28 ) ;
if ( V_270 )
F_148 ( V_64 . V_57 , & V_64 ,
stdout ) ;
else
F_145 ( V_64 . V_57 , stdout ) ;
}
if ( V_269 ) {
printf ( L_65 ) ;
F_146 ( V_64 . V_73 , stdout ) ;
printf ( L_66 ) ;
}
}
}
int F_149 ( struct V_1 * V_19 ,
const char * V_273 , unsigned long * V_274 )
{
int V_65 ;
struct V_275 * V_73 ;
for ( V_65 = 0 ; V_65 < V_276 ; ++ V_65 ) {
struct V_111 * T_8 ;
T_8 = F_140 ( V_19 , V_65 ) ;
if ( ! T_8 )
continue;
if ( ! ( T_8 -> V_120 . V_149 & V_191 ) ) {
F_3 ( L_68
L_69 ) ;
return - 1 ;
}
}
V_73 = F_150 ( V_273 ) ;
if ( V_73 == NULL ) {
F_3 ( L_70 ) ;
return - 1 ;
}
for ( V_65 = 0 ; V_65 < V_73 -> V_79 ; V_65 ++ ) {
int V_192 = V_73 -> V_73 [ V_65 ] ;
if ( V_192 >= V_277 ) {
F_3 ( L_71
L_72 , V_192 ) ;
return - 1 ;
}
F_151 ( V_192 , V_274 ) ;
}
return 0 ;
}
void F_152 ( struct V_1 * V_19 , T_15 * V_263 ,
bool V_278 )
{
struct V_4 V_28 ;
int V_23 ;
if ( V_19 == NULL || V_263 == NULL )
return;
V_23 = F_5 ( V_19 -> V_8 , & V_28 ) ;
if ( V_23 == - 1 )
return;
fprintf ( V_263 , L_73 ) ;
fprintf ( V_263 , L_74 , ctime ( & V_28 . V_279 ) ) ;
F_153 ( V_19 , V_263 , V_278 ) ;
fprintf ( V_263 , L_75 ) ;
}
int F_154 ( struct V_1 * V_19 ,
const struct V_280 * V_281 ,
T_2 V_282 )
{
struct V_109 * V_17 = V_19 -> V_17 ;
struct V_283 * V_284 ;
struct V_111 * T_8 ;
char * V_285 , * V_58 ;
T_2 V_65 ;
int V_11 ;
for ( V_65 = 0 ; V_65 < V_282 ; V_65 ++ ) {
V_11 = - V_186 ;
V_285 = F_125 ( V_281 [ V_65 ] . V_58 ) ;
if ( V_285 == NULL )
goto V_31;
V_11 = - V_13 ;
V_58 = strchr ( V_285 , ':' ) ;
if ( V_58 == NULL )
goto V_286;
* V_58 ++ = '\0' ;
V_284 = F_155 ( V_19 -> V_287 ,
V_285 , V_58 ) ;
if ( V_284 == NULL ) {
goto V_159;
}
T_8 = F_156 ( V_17 , V_284 -> V_142 ) ;
if ( T_8 == NULL )
goto V_159;
V_11 = - V_288 ;
if ( T_8 -> V_289 . V_290 != NULL )
goto V_286;
T_8 -> V_289 . V_290 = V_281 [ V_65 ] . V_289 ;
V_159:
free ( V_285 ) ;
}
V_11 = 0 ;
V_31:
return V_11 ;
V_286:
free ( V_285 ) ;
goto V_31;
}

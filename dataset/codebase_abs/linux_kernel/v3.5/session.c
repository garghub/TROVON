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
int F_48 ( struct V_47 * V_2 ,
struct V_87 * T_4 V_88 ,
struct V_48 * V_48 ,
struct V_89 * V_90 ,
struct V_59 * * V_91 )
{
T_3 V_92 = V_93 ;
unsigned int V_68 ;
int V_11 ;
F_49 ( & V_94 ) ;
if ( V_90 -> V_82 > V_95 ) {
F_50 ( L_13 ) ;
return 0 ;
}
for ( V_68 = 0 ; V_68 < V_90 -> V_82 ; V_68 ++ ) {
T_2 V_65 ;
struct V_66 V_67 ;
if ( V_96 . V_97 == V_98 )
V_65 = V_90 -> V_99 [ V_68 ] ;
else
V_65 = V_90 -> V_99 [ V_90 -> V_82 - V_68 - 1 ] ;
if ( V_65 >= V_100 ) {
switch ( V_65 ) {
case V_101 :
V_92 = V_102 ; break;
case V_103 :
V_92 = V_104 ; break;
case V_105 :
V_92 = V_93 ; break;
default:
F_51 ( L_14
L_15 V_106 L_6 , ( V_107 ) V_65 ) ;
F_49 ( & V_94 ) ;
return 0 ;
}
continue;
}
V_67 . V_108 = false ;
F_46 ( V_48 , V_2 , V_92 ,
V_72 , V_65 , & V_67 , NULL ) ;
if ( V_67 . V_60 != NULL ) {
if ( V_109 && ! * V_91 &&
F_44 ( V_67 . V_60 ) )
* V_91 = V_67 . V_60 ;
if ( ! V_110 . V_111 )
break;
}
V_11 = F_52 ( & V_94 ,
V_65 , V_67 . V_76 , V_67 . V_60 ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static int F_53 ( union V_112 * T_5 V_88 ,
struct V_1 * V_52 V_88 )
{
F_28 ( L_16 ) ;
return 0 ;
}
static int F_54 ( union V_112 * T_5 V_88 ,
struct V_113 * * T_6 V_88 )
{
F_28 ( L_16 ) ;
return 0 ;
}
static int F_55 ( struct V_28 * V_29 V_88 ,
union V_112 * T_5 V_88 ,
struct V_114 * T_7 V_88 ,
struct V_87 * T_4 V_88 ,
struct V_47 * V_47 V_88 )
{
F_28 ( L_16 ) ;
return 0 ;
}
static int F_56 ( struct V_28 * V_29 V_88 ,
union V_112 * T_5 V_88 ,
struct V_114 * T_7 V_88 ,
struct V_47 * V_47 V_88 )
{
F_28 ( L_16 ) ;
return 0 ;
}
static int F_57 ( struct V_28 * V_29 V_88 ,
union V_112 * T_5 V_88 ,
struct V_1 * V_1 V_88 )
{
F_28 ( L_16 ) ;
return 0 ;
}
static int F_58 ( struct V_28 * V_29 V_88 ,
union V_112 * T_5 V_88 )
{
F_28 ( L_16 ) ;
return 0 ;
}
static void F_59 ( struct V_28 * V_29 )
{
if ( V_29 -> T_7 == NULL )
V_29 -> T_7 = F_55 ;
if ( V_29 -> V_115 == NULL )
V_29 -> V_115 = F_56 ;
if ( V_29 -> V_116 == NULL )
V_29 -> V_116 = F_56 ;
if ( V_29 -> V_117 == NULL )
V_29 -> V_117 = F_56 ;
if ( V_29 -> exit == NULL )
V_29 -> exit = F_56 ;
if ( V_29 -> V_118 == NULL )
V_29 -> V_118 = V_119 ;
if ( V_29 -> V_120 == NULL )
V_29 -> V_120 = F_55 ;
if ( V_29 -> V_121 == NULL )
V_29 -> V_121 = F_56 ;
if ( V_29 -> V_122 == NULL )
V_29 -> V_122 = F_56 ;
if ( V_29 -> V_123 == NULL )
V_29 -> V_123 = F_54 ;
if ( V_29 -> V_124 == NULL )
V_29 -> V_124 = F_58 ;
if ( V_29 -> V_125 == NULL )
V_29 -> V_125 = F_53 ;
if ( V_29 -> V_126 == NULL )
V_29 -> V_126 = F_57 ;
if ( V_29 -> V_127 == NULL ) {
if ( V_29 -> V_38 )
V_29 -> V_127 = V_128 ;
else
V_29 -> V_127 = F_57 ;
}
}
void F_60 ( void * V_129 , int V_130 )
{
T_8 * V_69 = V_129 ;
while ( V_130 > 0 ) {
* V_69 = F_61 ( * V_69 ) ;
V_130 -= sizeof( T_8 ) ;
++ V_69 ;
}
}
void F_62 ( void * V_129 , int V_130 )
{
T_2 * V_69 = V_129 ;
while ( V_130 > 0 ) {
* V_69 = F_63 ( * V_69 ) ;
V_130 -= sizeof( T_2 ) ;
++ V_69 ;
}
}
static void F_64 ( union V_112 * T_5 , void * V_131 )
{
void * V_132 = ( void * ) T_5 + T_5 -> V_133 . V_18 ;
int V_18 = V_132 - V_131 ;
F_65 ( V_18 % sizeof( T_2 ) ) ;
F_62 ( V_131 , V_18 ) ;
}
static void F_66 ( union V_112 * T_5 ,
bool V_21 V_88 )
{
struct V_134 * V_135 = & T_5 -> V_133 ;
F_62 ( V_135 + 1 , T_5 -> V_133 . V_18 - sizeof( * V_135 ) ) ;
}
static void F_67 ( union V_112 * T_5 , bool V_21 )
{
T_5 -> V_116 . V_136 = F_61 ( T_5 -> V_116 . V_136 ) ;
T_5 -> V_116 . V_137 = F_61 ( T_5 -> V_116 . V_137 ) ;
if ( V_21 ) {
void * V_131 = & T_5 -> V_116 . V_116 ;
V_131 += F_68 ( strlen ( V_131 ) + 1 , sizeof( T_2 ) ) ;
F_64 ( T_5 , V_131 ) ;
}
}
static void F_69 ( union V_112 * T_5 ,
bool V_21 )
{
T_5 -> V_115 . V_136 = F_61 ( T_5 -> V_115 . V_136 ) ;
T_5 -> V_115 . V_137 = F_61 ( T_5 -> V_115 . V_137 ) ;
T_5 -> V_115 . V_138 = F_63 ( T_5 -> V_115 . V_138 ) ;
T_5 -> V_115 . V_31 = F_63 ( T_5 -> V_115 . V_31 ) ;
T_5 -> V_115 . V_139 = F_63 ( T_5 -> V_115 . V_139 ) ;
if ( V_21 ) {
void * V_131 = & T_5 -> V_115 . V_6 ;
V_131 += F_68 ( strlen ( V_131 ) + 1 , sizeof( T_2 ) ) ;
F_64 ( T_5 , V_131 ) ;
}
}
static void F_70 ( union V_112 * T_5 , bool V_21 )
{
T_5 -> V_117 . V_136 = F_61 ( T_5 -> V_117 . V_136 ) ;
T_5 -> V_117 . V_137 = F_61 ( T_5 -> V_117 . V_137 ) ;
T_5 -> V_117 . V_140 = F_61 ( T_5 -> V_117 . V_140 ) ;
T_5 -> V_117 . V_141 = F_61 ( T_5 -> V_117 . V_141 ) ;
T_5 -> V_117 . time = F_63 ( T_5 -> V_117 . time ) ;
if ( V_21 )
F_64 ( T_5 , & T_5 -> V_117 + 1 ) ;
}
static void F_71 ( union V_112 * T_5 , bool V_21 )
{
T_5 -> V_120 . V_136 = F_61 ( T_5 -> V_120 . V_136 ) ;
T_5 -> V_120 . V_137 = F_61 ( T_5 -> V_120 . V_137 ) ;
T_5 -> V_120 . V_142 = F_63 ( T_5 -> V_120 . V_142 ) ;
T_5 -> V_120 . V_143 = F_63 ( T_5 -> V_120 . V_143 ) ;
T_5 -> V_120 . V_144 = F_63 ( T_5 -> V_120 . V_144 ) ;
T_5 -> V_120 . V_145 = F_63 ( T_5 -> V_120 . V_145 ) ;
if ( V_21 )
F_64 ( T_5 , & T_5 -> V_120 + 1 ) ;
}
static T_3 F_72 ( T_3 V_146 )
{
int V_147 = ( V_146 >> 4 ) | ( ( V_146 & 0xf ) << 4 ) ;
V_147 = ( ( V_147 & 0xcc ) >> 2 ) | ( ( V_147 & 0x33 ) << 2 ) ;
V_147 = ( ( V_147 & 0xaa ) >> 1 ) | ( ( V_147 & 0x55 ) << 1 ) ;
return ( T_3 ) V_147 ;
}
static void F_73 ( T_3 * V_148 , unsigned V_31 )
{
unsigned V_68 ;
for ( V_68 = 0 ; V_68 < V_31 ; V_68 ++ ) {
* V_148 = F_72 ( * V_148 ) ;
V_148 ++ ;
}
}
void F_74 ( struct V_149 * V_123 )
{
V_123 -> type = F_61 ( V_123 -> type ) ;
V_123 -> V_18 = F_61 ( V_123 -> V_18 ) ;
V_123 -> V_150 = F_63 ( V_123 -> V_150 ) ;
V_123 -> V_151 = F_63 ( V_123 -> V_151 ) ;
V_123 -> V_19 = F_63 ( V_123 -> V_19 ) ;
V_123 -> V_152 = F_63 ( V_123 -> V_152 ) ;
V_123 -> V_153 = F_61 ( V_123 -> V_153 ) ;
V_123 -> V_154 = F_61 ( V_123 -> V_154 ) ;
V_123 -> V_155 = F_63 ( V_123 -> V_155 ) ;
V_123 -> V_156 = F_63 ( V_123 -> V_156 ) ;
F_73 ( ( T_3 * ) ( & V_123 -> V_152 + 1 ) , sizeof( T_2 ) ) ;
}
static void F_75 ( union V_112 * T_5 ,
bool V_21 V_88 )
{
T_1 V_18 ;
F_74 ( & T_5 -> V_123 . V_123 ) ;
V_18 = T_5 -> V_133 . V_18 ;
V_18 -= ( void * ) & T_5 -> V_123 . V_145 - ( void * ) T_5 ;
F_62 ( T_5 -> V_123 . V_145 , V_18 ) ;
}
static void F_76 ( union V_112 * T_5 ,
bool V_21 V_88 )
{
T_5 -> V_124 . V_124 . V_157 =
F_63 ( T_5 -> V_124 . V_124 . V_157 ) ;
}
static void F_77 ( union V_112 * T_5 ,
bool V_21 V_88 )
{
T_5 -> V_125 . V_18 = F_61 ( T_5 -> V_125 . V_18 ) ;
}
static void F_78 ( struct V_1 * V_52 )
{
struct V_38 * V_158 = & V_52 -> V_38 ;
while ( ! F_79 ( & V_158 -> V_41 ) ) {
struct V_159 * V_160 ;
V_160 = F_80 ( V_158 -> V_41 . V_161 , struct V_159 , V_162 ) ;
F_32 ( & V_160 -> V_162 ) ;
free ( V_160 ) ;
}
}
static void F_81 ( struct V_1 * V_163 ,
struct V_28 * V_29 )
{
struct V_38 * V_158 = & V_163 -> V_38 ;
struct V_164 * V_165 = & V_158 -> V_39 ;
struct V_159 * V_166 , * V_167 ;
struct V_114 T_7 ;
T_2 V_168 = V_158 -> V_169 ;
T_2 V_170 = V_158 -> V_171 ? V_158 -> V_171 -> V_172 : 0ULL ;
unsigned V_173 = 0 , V_174 = V_158 -> V_175 / 16 ;
int V_24 ;
if ( ! V_29 -> V_38 || ! V_168 )
return;
F_31 (iter, tmp, head, list) {
if ( V_167 -> V_172 > V_168 )
break;
V_24 = F_82 ( V_163 , V_167 -> T_5 , & T_7 ) ;
if ( V_24 )
F_3 ( L_17 , V_24 ) ;
else
F_83 ( V_163 , V_167 -> T_5 , & T_7 , V_29 ,
V_167 -> V_176 ) ;
V_158 -> V_177 = V_167 -> V_172 ;
F_32 ( & V_167 -> V_162 ) ;
F_84 ( & V_167 -> V_162 , & V_158 -> V_40 ) ;
if ( ++ V_173 >= V_174 ) {
V_174 += V_158 -> V_175 / 16 ;
F_85 ( V_173 , V_158 -> V_175 ,
L_18 ) ;
}
}
if ( F_79 ( V_165 ) ) {
V_158 -> V_171 = NULL ;
} else if ( V_170 <= V_168 ) {
V_158 -> V_171 =
F_80 ( V_165 -> V_178 , struct V_159 , V_162 ) ;
}
V_158 -> V_175 = 0 ;
}
static int V_128 ( struct V_28 * V_29 ,
union V_112 * T_5 V_88 ,
struct V_1 * V_52 )
{
F_81 ( V_52 , V_29 ) ;
V_52 -> V_38 . V_169 = V_52 -> V_38 . V_179 ;
return 0 ;
}
static void F_86 ( struct V_159 * V_180 , struct V_1 * V_163 )
{
struct V_38 * V_158 = & V_163 -> V_38 ;
struct V_159 * T_7 = V_158 -> V_171 ;
T_2 V_172 = V_180 -> V_172 ;
struct V_164 * V_148 ;
++ V_158 -> V_175 ;
V_158 -> V_171 = V_180 ;
if ( ! T_7 ) {
F_84 ( & V_180 -> V_162 , & V_158 -> V_39 ) ;
V_158 -> V_179 = V_172 ;
return;
}
if ( T_7 -> V_172 <= V_172 ) {
while ( T_7 -> V_172 <= V_172 ) {
V_148 = T_7 -> V_162 . V_161 ;
if ( V_148 == & V_158 -> V_39 ) {
F_43 ( & V_180 -> V_162 , & V_158 -> V_39 ) ;
V_158 -> V_179 = V_172 ;
return;
}
T_7 = F_80 ( V_148 , struct V_159 , V_162 ) ;
}
F_43 ( & V_180 -> V_162 , & T_7 -> V_162 ) ;
} else {
while ( T_7 -> V_172 > V_172 ) {
V_148 = T_7 -> V_162 . V_178 ;
if ( V_148 == & V_158 -> V_39 ) {
F_84 ( & V_180 -> V_162 , & V_158 -> V_39 ) ;
return;
}
T_7 = F_80 ( V_148 , struct V_159 , V_162 ) ;
}
F_84 ( & V_180 -> V_162 , & T_7 -> V_162 ) ;
}
}
static int F_87 ( struct V_1 * V_163 , union V_112 * T_5 ,
struct V_114 * T_7 , T_2 V_176 )
{
struct V_38 * V_158 = & V_163 -> V_38 ;
struct V_164 * V_181 = & V_158 -> V_40 ;
T_2 V_172 = T_7 -> time ;
struct V_159 * V_180 ;
if ( ! V_172 || V_172 == ~ 0ULL )
return - V_182 ;
if ( V_172 < V_163 -> V_38 . V_177 ) {
printf ( L_19 ) ;
return - V_183 ;
}
if ( ! F_79 ( V_181 ) ) {
V_180 = F_80 ( V_181 -> V_161 , struct V_159 , V_162 ) ;
F_32 ( & V_180 -> V_162 ) ;
} else if ( V_158 -> V_184 ) {
V_180 = V_158 -> V_184 + V_158 -> V_185 ;
if ( ++ V_158 -> V_185 == V_186 )
V_158 -> V_184 = NULL ;
} else {
V_158 -> V_184 = malloc ( V_186 * sizeof( * V_180 ) ) ;
if ( ! V_158 -> V_184 )
return - V_187 ;
F_84 ( & V_158 -> V_184 -> V_162 , & V_158 -> V_41 ) ;
V_158 -> V_185 = 2 ;
V_180 = V_158 -> V_184 + 1 ;
}
V_180 -> V_172 = V_172 ;
V_180 -> V_176 = V_176 ;
V_180 -> T_5 = T_5 ;
F_86 ( V_180 , V_163 ) ;
return 0 ;
}
static void F_88 ( struct V_114 * T_7 )
{
unsigned int V_68 ;
printf ( L_20 V_188 L_6 , T_7 -> V_189 -> V_82 ) ;
for ( V_68 = 0 ; V_68 < T_7 -> V_189 -> V_82 ; V_68 ++ )
printf ( L_21 V_190 L_6 ,
V_68 , T_7 -> V_189 -> V_99 [ V_68 ] ) ;
}
static void F_89 ( struct V_114 * T_7 )
{
T_9 V_68 ;
printf ( L_22 V_188 L_6 , T_7 -> V_79 -> V_82 ) ;
for ( V_68 = 0 ; V_68 < T_7 -> V_79 -> V_82 ; V_68 ++ )
printf ( L_23 V_188 L_24 V_190 L_25 V_190 L_6 ,
V_68 , T_7 -> V_79 -> V_84 [ V_68 ] . V_85 ,
T_7 -> V_79 -> V_84 [ V_68 ] . V_83 ) ;
}
static void F_90 ( struct V_1 * V_52 ,
union V_112 * T_5 ,
struct V_114 * T_7 )
{
if ( T_5 -> V_133 . type != V_191 &&
! V_52 -> V_21 ) {
fputs ( L_26 , stdout ) ;
return;
}
if ( ( V_52 -> V_19 & V_192 ) )
printf ( L_27 , T_7 -> V_193 ) ;
if ( V_52 -> V_19 & V_194 )
printf ( L_15 V_188 L_28 , T_7 -> time ) ;
}
static void F_91 ( struct V_1 * V_52 , union V_112 * T_5 ,
T_2 V_176 , struct V_114 * T_7 )
{
if ( ! V_195 )
return;
printf ( L_29 V_190 L_30 ,
V_176 , T_5 -> V_133 . V_18 , T_5 -> V_133 . type ) ;
F_92 ( T_5 ) ;
if ( T_7 )
F_90 ( V_52 , T_5 , T_7 ) ;
printf ( L_31 V_190 L_32 , V_176 ,
T_5 -> V_133 . V_18 , F_93 ( T_5 -> V_133 . type ) ) ;
}
static void F_94 ( struct V_1 * V_52 , union V_112 * T_5 ,
struct V_114 * T_7 )
{
if ( ! V_195 )
return;
printf ( L_33 V_190 L_34 V_188 L_35 V_190 L_6 ,
T_5 -> V_133 . V_196 , T_7 -> V_136 , T_7 -> V_137 , T_7 -> V_65 ,
T_7 -> V_197 , T_7 -> V_74 ) ;
if ( V_52 -> V_19 & V_198 )
F_88 ( T_7 ) ;
if ( V_52 -> V_19 & V_199 )
F_89 ( T_7 ) ;
}
static struct V_47 *
F_95 ( struct V_1 * V_52 ,
union V_112 * T_5 )
{
const T_3 V_92 = T_5 -> V_133 . V_196 & V_200 ;
if ( V_92 == V_201 && V_202 ) {
T_8 V_136 ;
if ( T_5 -> V_133 . type == V_203 )
V_136 = T_5 -> V_115 . V_136 ;
else
V_136 = T_5 -> V_65 . V_136 ;
return F_96 ( V_52 , V_136 ) ;
}
return F_97 ( V_52 ) ;
}
static int F_83 ( struct V_1 * V_52 ,
union V_112 * T_5 ,
struct V_114 * T_7 ,
struct V_28 * V_29 ,
T_2 V_176 )
{
struct V_87 * T_4 ;
struct V_47 * V_47 ;
F_91 ( V_52 , T_5 , V_176 , T_7 ) ;
T_4 = F_98 ( V_52 -> V_17 , T_7 -> V_145 ) ;
if ( T_4 != NULL && T_5 -> V_133 . type != V_191 ) {
F_99 ( & T_4 -> V_43 , T_5 -> V_133 . type ) ;
}
V_47 = F_95 ( V_52 , T_5 ) ;
switch ( T_5 -> V_133 . type ) {
case V_191 :
F_94 ( V_52 , T_5 , T_7 ) ;
if ( T_4 == NULL ) {
++ V_52 -> V_43 . V_204 . V_205 ;
return 0 ;
}
if ( V_47 == NULL ) {
++ V_52 -> V_43 . V_204 . V_206 ;
return 0 ;
}
return V_29 -> T_7 ( V_29 , T_5 , T_7 , T_4 , V_47 ) ;
case V_203 :
return V_29 -> V_115 ( V_29 , T_5 , T_7 , V_47 ) ;
case V_207 :
return V_29 -> V_116 ( V_29 , T_5 , T_7 , V_47 ) ;
case V_208 :
return V_29 -> V_117 ( V_29 , T_5 , T_7 , V_47 ) ;
case V_209 :
return V_29 -> exit ( V_29 , T_5 , T_7 , V_47 ) ;
case V_210 :
if ( V_29 -> V_118 == V_119 )
V_52 -> V_43 . V_204 . V_211 += T_5 -> V_118 . V_118 ;
return V_29 -> V_118 ( V_29 , T_5 , T_7 , V_47 ) ;
case V_212 :
return V_29 -> V_120 ( V_29 , T_5 , T_7 , T_4 , V_47 ) ;
case V_213 :
return V_29 -> V_121 ( V_29 , T_5 , T_7 , V_47 ) ;
case V_214 :
return V_29 -> V_122 ( V_29 , T_5 , T_7 , V_47 ) ;
default:
++ V_52 -> V_43 . V_204 . V_215 ;
return - 1 ;
}
}
static int F_100 ( struct V_1 * V_52 ,
union V_112 * T_5 , struct V_114 * T_7 )
{
if ( T_5 -> V_133 . type != V_191 ||
! ( V_52 -> V_19 & V_198 ) )
return 0 ;
if ( ! F_101 ( T_7 -> V_189 , T_5 ) ) {
F_51 ( L_36 ) ;
++ V_52 -> V_43 . V_204 . V_216 ;
V_52 -> V_43 . V_204 . V_217 += T_7 -> V_197 ;
return - V_183 ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_52 , union V_112 * T_5 ,
struct V_28 * V_29 , T_2 V_176 )
{
int V_11 ;
F_91 ( V_52 , T_5 , V_176 , NULL ) ;
switch ( T_5 -> V_133 . type ) {
case V_218 :
V_11 = V_29 -> V_123 ( T_5 , & V_52 -> V_17 ) ;
if ( V_11 == 0 )
F_11 ( V_52 ) ;
return V_11 ;
case V_219 :
return V_29 -> V_124 ( V_29 , T_5 ) ;
case V_220 :
F_103 ( V_52 -> V_8 , V_176 , V_221 ) ;
return V_29 -> V_125 ( T_5 , V_52 ) ;
case V_222 :
return V_29 -> V_126 ( V_29 , T_5 , V_52 ) ;
case V_223 :
return V_29 -> V_127 ( V_29 , T_5 , V_52 ) ;
default:
return - V_183 ;
}
}
static void F_104 ( union V_112 * T_5 , bool V_21 )
{
T_10 V_224 ;
V_224 = V_225 [ T_5 -> V_133 . type ] ;
if ( V_224 )
V_224 ( T_5 , V_21 ) ;
}
static int F_105 ( struct V_1 * V_52 ,
union V_112 * T_5 ,
struct V_28 * V_29 ,
T_2 V_176 )
{
struct V_114 T_7 ;
int V_24 ;
if ( V_52 -> V_133 . V_226 )
F_104 ( T_5 , V_52 -> V_21 ) ;
if ( T_5 -> V_133 . type >= V_227 )
return - V_183 ;
F_99 ( & V_52 -> V_43 , T_5 -> V_133 . type ) ;
if ( T_5 -> V_133 . type >= V_228 )
return F_102 ( V_52 , T_5 , V_29 , V_176 ) ;
V_24 = F_82 ( V_52 , T_5 , & T_7 ) ;
if ( V_24 )
return V_24 ;
if ( F_100 ( V_52 , T_5 , & T_7 ) )
return 0 ;
if ( V_29 -> V_38 ) {
V_24 = F_87 ( V_52 , T_5 , & T_7 ,
V_176 ) ;
if ( V_24 != - V_182 )
return V_24 ;
}
return F_83 ( V_52 , T_5 , & T_7 , V_29 ,
V_176 ) ;
}
void F_106 ( struct V_134 * V_2 )
{
V_2 -> type = F_61 ( V_2 -> type ) ;
V_2 -> V_196 = F_107 ( V_2 -> V_196 ) ;
V_2 -> V_18 = F_107 ( V_2 -> V_18 ) ;
}
struct V_48 * F_108 ( struct V_1 * V_52 , T_11 V_136 )
{
return F_109 ( & V_52 -> V_23 , V_136 ) ;
}
static struct V_48 * F_110 ( struct V_1 * V_2 )
{
struct V_48 * V_48 = F_108 ( V_2 , 0 ) ;
if ( V_48 == NULL || F_111 ( V_48 , L_37 ) ) {
F_3 ( L_38 ) ;
V_48 = NULL ;
}
return V_48 ;
}
static void F_112 ( const struct V_1 * V_52 ,
const struct V_28 * V_29 )
{
if ( V_29 -> V_118 == V_119 &&
V_52 -> V_43 . V_204 . V_229 [ V_210 ] != 0 ) {
F_113 ( L_39
L_40 ,
V_52 -> V_43 . V_204 . V_229 [ 0 ] ,
V_52 -> V_43 . V_204 . V_229 [ V_210 ] ) ;
}
if ( V_52 -> V_43 . V_204 . V_215 != 0 ) {
F_113 ( L_41
L_42
L_43
L_44
L_45 ,
V_52 -> V_43 . V_204 . V_215 ) ;
}
if ( V_52 -> V_43 . V_204 . V_205 != 0 ) {
F_113 ( L_46 ,
V_52 -> V_43 . V_204 . V_205 ) ;
}
if ( V_52 -> V_43 . V_204 . V_216 != 0 ) {
F_113 ( L_47
L_48
L_49 ,
V_52 -> V_43 . V_204 . V_216 ,
V_52 -> V_43 . V_204 . V_229 [ V_191 ] ) ;
}
if ( V_52 -> V_43 . V_204 . V_206 != 0 ) {
F_113 ( L_50
L_51 ,
V_52 -> V_43 . V_204 . V_206 ) ;
}
}
static int F_114 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
union V_112 * T_5 ;
T_12 V_18 , V_230 = 0 ;
void * V_231 = NULL ;
int V_232 = 0 ;
T_2 V_165 ;
int V_11 ;
void * V_148 ;
F_59 ( V_29 ) ;
V_165 = 0 ;
V_230 = sizeof( union V_112 ) ;
V_231 = malloc ( V_230 ) ;
if ( ! V_231 )
return - V_12 ;
V_233:
T_5 = V_231 ;
V_11 = F_115 ( V_2 -> V_8 , T_5 , sizeof( struct V_134 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 )
goto V_234;
F_3 ( L_52 ) ;
goto V_235;
}
if ( V_2 -> V_133 . V_226 )
F_106 ( & T_5 -> V_133 ) ;
V_18 = T_5 -> V_133 . V_18 ;
if ( V_18 == 0 )
V_18 = 8 ;
if ( V_18 > V_230 ) {
void * V_180 = realloc ( V_231 , V_18 ) ;
if ( ! V_180 ) {
F_3 ( L_53 ) ;
goto V_235;
}
V_231 = V_180 ;
V_230 = V_18 ;
T_5 = V_231 ;
}
V_148 = T_5 ;
V_148 += sizeof( struct V_134 ) ;
if ( V_18 - sizeof( struct V_134 ) ) {
V_11 = F_115 ( V_2 -> V_8 , V_148 , V_18 - sizeof( struct V_134 ) ) ;
if ( V_11 <= 0 ) {
if ( V_11 == 0 ) {
F_3 ( L_54 ) ;
goto V_234;
}
F_3 ( L_55 ) ;
goto V_235;
}
}
if ( ( V_232 = F_105 ( V_2 , T_5 , V_29 , V_165 ) ) < 0 ) {
F_3 ( L_31 V_190 L_56 ,
V_165 , T_5 -> V_133 . V_18 , T_5 -> V_133 . type ) ;
V_11 = - V_183 ;
goto V_235;
}
V_165 += V_18 ;
if ( V_232 > 0 )
V_165 += V_232 ;
if ( ! F_116 () )
goto V_233;
V_234:
V_11 = 0 ;
V_235:
free ( V_231 ) ;
F_112 ( V_2 , V_29 ) ;
F_78 ( V_2 ) ;
return V_11 ;
}
static union V_112 *
F_117 ( struct V_1 * V_52 ,
T_2 V_165 , T_1 V_236 , char * V_231 )
{
union V_112 * T_5 ;
if ( V_165 + sizeof( T_5 -> V_133 ) > V_236 )
return NULL ;
T_5 = (union V_112 * ) ( V_231 + V_165 ) ;
if ( V_52 -> V_133 . V_226 )
F_106 ( & T_5 -> V_133 ) ;
if ( V_165 + T_5 -> V_133 . V_18 > V_236 )
return NULL ;
return T_5 ;
}
int F_118 ( struct V_1 * V_52 ,
T_2 V_237 , T_2 V_238 ,
T_2 V_239 , struct V_28 * V_29 )
{
T_2 V_165 , V_240 , V_176 , V_241 , V_174 ;
int V_11 , V_242 , V_243 , V_244 = 0 ;
T_1 V_245 , V_236 ;
char * V_231 , * V_246 [ 8 ] ;
union V_112 * T_5 ;
T_12 V_18 ;
F_59 ( V_29 ) ;
V_245 = F_119 ( V_247 ) ;
V_240 = V_245 * ( V_237 / V_245 ) ;
V_176 = V_240 ;
V_165 = V_237 - V_240 ;
if ( V_237 + V_238 < V_239 )
V_239 = V_237 + V_238 ;
V_174 = V_239 / 16 ;
V_236 = V_52 -> V_35 ;
if ( V_236 > V_239 )
V_236 = V_239 ;
memset ( V_246 , 0 , sizeof( V_246 ) ) ;
V_242 = V_248 ;
V_243 = V_249 ;
if ( V_52 -> V_133 . V_226 ) {
V_242 |= V_250 ;
V_243 = V_251 ;
}
V_252:
V_231 = V_115 ( NULL , V_236 , V_242 , V_243 , V_52 -> V_8 ,
V_176 ) ;
if ( V_231 == V_253 ) {
F_3 ( L_57 ) ;
V_11 = - V_12 ;
goto V_235;
}
V_246 [ V_244 ] = V_231 ;
V_244 = ( V_244 + 1 ) & ( F_120 ( V_246 ) - 1 ) ;
V_241 = V_176 + V_165 ;
V_233:
T_5 = F_117 ( V_52 , V_165 , V_236 , V_231 ) ;
if ( ! T_5 ) {
if ( V_246 [ V_244 ] ) {
F_121 ( V_246 [ V_244 ] , V_236 ) ;
V_246 [ V_244 ] = NULL ;
}
V_240 = V_245 * ( V_165 / V_245 ) ;
V_176 += V_240 ;
V_165 -= V_240 ;
goto V_252;
}
V_18 = T_5 -> V_133 . V_18 ;
if ( V_18 == 0 ||
F_105 ( V_52 , T_5 , V_29 , V_241 ) < 0 ) {
F_3 ( L_31 V_190 L_56 ,
V_176 + V_165 , T_5 -> V_133 . V_18 ,
T_5 -> V_133 . type ) ;
V_11 = - V_183 ;
goto V_235;
}
V_165 += V_18 ;
V_241 += V_18 ;
if ( V_241 >= V_174 ) {
V_174 += V_239 / 16 ;
F_85 ( V_241 , V_239 ,
L_58 ) ;
}
if ( V_241 < V_239 )
goto V_233;
V_11 = 0 ;
V_52 -> V_38 . V_169 = V_36 ;
F_81 ( V_52 , V_29 ) ;
V_235:
F_112 ( V_52 , V_29 ) ;
F_78 ( V_52 ) ;
return V_11 ;
}
int F_122 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
int V_11 ;
if ( F_110 ( V_2 ) == NULL )
return - V_187 ;
if ( ! V_2 -> V_7 )
V_11 = F_118 ( V_2 ,
V_2 -> V_133 . V_237 ,
V_2 -> V_133 . V_238 ,
V_2 -> V_18 , V_29 ) ;
else
V_11 = F_114 ( V_2 , V_29 ) ;
return V_11 ;
}
bool F_123 ( struct V_1 * V_2 , const char * V_254 )
{
if ( ! ( V_2 -> V_19 & V_255 ) ) {
F_3 ( L_59 , V_254 ) ;
return false ;
}
return true ;
}
int F_124 ( struct V_76 * * V_256 ,
const char * V_257 , T_2 V_74 )
{
char * V_258 ;
enum V_259 V_68 ;
struct V_260 * V_261 ;
V_261 = F_24 ( sizeof( struct V_260 ) ) ;
if ( V_261 == NULL )
return - V_187 ;
V_261 -> V_61 = F_125 ( V_257 ) ;
if ( V_261 -> V_61 == NULL ) {
free ( V_261 ) ;
return - V_187 ;
}
V_258 = strchr ( V_261 -> V_61 , ']' ) ;
if ( V_258 )
* V_258 = '\0' ;
V_261 -> V_74 = V_74 ;
for ( V_68 = 0 ; V_68 < V_262 ; ++ V_68 ) {
struct V_263 * V_263 = F_126 ( V_256 [ V_68 ] ) ;
V_263 -> V_260 = V_261 ;
}
return 0 ;
}
T_1 F_127 ( struct V_1 * V_2 , T_13 * V_264 )
{
return F_128 ( & V_2 -> V_23 . V_265 , V_264 ) +
F_128 ( & V_2 -> V_23 . V_266 , V_264 ) +
F_129 ( & V_2 -> V_25 , V_264 ) ;
}
T_1 F_130 ( struct V_1 * V_2 , T_13 * V_264 ,
bool V_267 )
{
T_1 V_24 = F_131 ( & V_2 -> V_23 , V_264 , V_267 ) ;
return V_24 + F_132 ( & V_2 -> V_25 , V_264 , V_267 ) ;
}
T_1 F_133 ( struct V_1 * V_52 , T_13 * V_264 )
{
struct V_87 * V_268 ;
T_1 V_24 = fprintf ( V_264 , L_60 ) ;
V_24 += F_134 ( & V_52 -> V_43 , V_264 ) ;
F_135 (pos, &session->evlist->entries, node) {
V_24 += fprintf ( V_264 , L_61 , F_136 ( V_268 ) ) ;
V_24 += F_134 ( & V_268 -> V_43 , V_264 ) ;
}
return V_24 ;
}
T_1 F_137 ( struct V_1 * V_52 , T_13 * V_264 )
{
return F_138 ( & V_52 -> V_23 , V_264 ) ;
}
void F_139 ( struct V_1 * V_52 ,
struct V_48 * V_56 )
{
F_42 ( & V_52 -> V_23 , V_56 ) ;
}
struct V_87 * F_140 ( struct V_1 * V_52 ,
unsigned int type )
{
struct V_87 * V_268 ;
F_135 (pos, &session->evlist->entries, node) {
if ( V_268 -> V_123 . type == type )
return V_268 ;
}
return NULL ;
}
void F_141 ( union V_112 * T_5 , struct V_114 * T_7 ,
struct V_47 * V_47 , struct V_87 * T_4 ,
int V_269 , int V_270 , int V_271 )
{
struct V_66 V_67 ;
struct V_272 * V_51 ;
if ( F_142 ( T_5 , V_47 , & V_67 , T_7 ,
NULL ) < 0 ) {
error ( L_62 ,
T_5 -> V_133 . type ) ;
return;
}
if ( V_110 . V_111 && T_7 -> V_189 ) {
if ( F_48 ( V_47 , T_4 , V_67 . V_48 ,
T_7 -> V_189 , NULL ) != 0 ) {
if ( V_273 )
error ( L_63 ) ;
return;
}
F_143 ( & V_94 ) ;
while ( 1 ) {
V_51 = F_144 ( & V_94 ) ;
if ( ! V_51 )
break;
printf ( L_64 V_190 , V_51 -> V_65 ) ;
if ( V_269 ) {
printf ( L_28 ) ;
F_145 ( V_51 -> V_60 , stdout ) ;
}
if ( V_270 ) {
printf ( L_65 ) ;
F_146 ( V_51 -> V_76 , stdout ) ;
printf ( L_66 ) ;
}
printf ( L_6 ) ;
F_147 ( & V_94 ) ;
}
} else {
printf ( L_67 V_190 , T_7 -> V_65 ) ;
if ( V_269 ) {
printf ( L_28 ) ;
if ( V_271 )
F_148 ( V_67 . V_60 , & V_67 ,
stdout ) ;
else
F_145 ( V_67 . V_60 , stdout ) ;
}
if ( V_270 ) {
printf ( L_65 ) ;
F_146 ( V_67 . V_76 , stdout ) ;
printf ( L_66 ) ;
}
}
}
int F_149 ( struct V_1 * V_52 ,
const char * V_274 , unsigned long * V_275 )
{
int V_68 ;
struct V_276 * V_76 ;
for ( V_68 = 0 ; V_68 < V_277 ; ++ V_68 ) {
struct V_87 * T_4 ;
T_4 = F_140 ( V_52 , V_68 ) ;
if ( ! T_4 )
continue;
if ( ! ( T_4 -> V_123 . V_19 & V_192 ) ) {
F_3 ( L_68
L_69 ) ;
return - 1 ;
}
}
V_76 = F_150 ( V_274 ) ;
if ( V_76 == NULL ) {
F_3 ( L_70 ) ;
return - 1 ;
}
for ( V_68 = 0 ; V_68 < V_76 -> V_82 ; V_68 ++ ) {
int V_193 = V_76 -> V_76 [ V_68 ] ;
if ( V_193 >= V_278 ) {
F_3 ( L_71
L_72 , V_193 ) ;
return - 1 ;
}
F_151 ( V_193 , V_275 ) ;
}
return 0 ;
}
void F_152 ( struct V_1 * V_52 , T_13 * V_264 ,
bool V_279 )
{
struct V_4 V_30 ;
int V_24 ;
if ( V_52 == NULL || V_264 == NULL )
return;
V_24 = F_5 ( V_52 -> V_8 , & V_30 ) ;
if ( V_24 == - 1 )
return;
fprintf ( V_264 , L_73 ) ;
fprintf ( V_264 , L_74 , ctime ( & V_30 . V_280 ) ) ;
F_153 ( V_52 , V_264 , V_279 ) ;
fprintf ( V_264 , L_75 ) ;
}

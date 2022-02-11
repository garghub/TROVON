static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_5 ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
unsigned long args [ 6 ] ;
V_2 -> V_8 = F_3 ( V_4 , V_7 ) ;
V_2 -> V_9 = F_4 () ;
F_5 ( V_4 , V_7 , 0 , 6 , args ) ;
V_2 -> args [ 0 ] = args [ 0 ] ;
V_2 -> args [ 1 ] = args [ 1 ] ;
V_2 -> args [ 2 ] = args [ 2 ] ;
V_2 -> args [ 3 ] = args [ 3 ] ;
V_2 -> args [ 4 ] = args [ 4 ] ;
V_2 -> args [ 5 ] = args [ 5 ] ;
V_2 -> V_10 = F_6 ( V_4 ) ;
}
static int F_7 ( struct V_11 * V_12 , unsigned int V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_13 ; V_14 ++ ) {
struct V_11 * V_15 = & V_12 [ V_14 ] ;
T_1 V_16 = V_15 -> V_16 ;
T_2 V_17 = V_15 -> V_17 ;
switch ( V_16 ) {
case V_18 | V_19 | V_20 :
V_15 -> V_16 = V_21 | V_19 | V_20 ;
if ( V_17 >= sizeof( struct V_1 ) || V_17 & 3 )
return - V_22 ;
continue;
case V_18 | V_19 | V_23 :
V_15 -> V_16 = V_18 | V_24 ;
V_15 -> V_17 = sizeof( struct V_1 ) ;
continue;
case V_21 | V_19 | V_23 :
V_15 -> V_16 = V_21 | V_24 ;
V_15 -> V_17 = sizeof( struct V_1 ) ;
continue;
case V_25 | V_26 :
case V_25 | V_27 :
case V_28 | V_29 | V_26 :
case V_28 | V_29 | V_30 :
case V_28 | V_31 | V_26 :
case V_28 | V_31 | V_30 :
case V_28 | V_32 | V_26 :
case V_28 | V_32 | V_30 :
case V_28 | V_33 | V_26 :
case V_28 | V_33 | V_30 :
case V_28 | V_34 | V_26 :
case V_28 | V_34 | V_30 :
case V_28 | V_35 | V_26 :
case V_28 | V_35 | V_30 :
case V_28 | V_36 | V_26 :
case V_28 | V_36 | V_30 :
case V_28 | V_37 | V_26 :
case V_28 | V_37 | V_30 :
case V_28 | V_38 | V_26 :
case V_28 | V_38 | V_30 :
case V_28 | V_39 :
case V_18 | V_24 :
case V_21 | V_24 :
case V_40 | V_41 :
case V_40 | V_42 :
case V_18 | V_43 :
case V_21 | V_43 :
case V_44 :
case V_45 :
case V_46 | V_47 :
case V_46 | V_48 | V_26 :
case V_46 | V_48 | V_30 :
case V_46 | V_49 | V_26 :
case V_46 | V_49 | V_30 :
case V_46 | V_50 | V_26 :
case V_46 | V_50 | V_30 :
case V_46 | V_51 | V_26 :
case V_46 | V_51 | V_30 :
continue;
default:
return - V_22 ;
}
}
return 0 ;
}
static T_2 F_8 ( const struct V_1 * V_2 ,
struct V_52 * * V_53 )
{
struct V_1 V_54 ;
T_2 V_55 = V_56 ;
struct V_52 * V_57 =
F_9 ( V_5 -> V_58 . V_12 ) ;
if ( F_10 ( F_11 ( V_57 == NULL ) ) )
return V_59 ;
if ( ! V_2 ) {
F_1 ( & V_54 ) ;
V_2 = & V_54 ;
}
for (; V_57 ; V_57 = V_57 -> V_60 ) {
T_2 V_61 = F_12 ( V_57 -> V_62 , V_2 ) ;
if ( F_13 ( V_61 ) < F_13 ( V_55 ) ) {
V_55 = V_61 ;
* V_53 = V_57 ;
}
}
return V_55 ;
}
static inline bool F_14 ( unsigned long V_63 )
{
F_15 ( & V_5 -> V_64 -> V_65 ) ;
if ( V_5 -> V_58 . V_66 && V_5 -> V_58 . V_66 != V_63 )
return false ;
return true ;
}
static inline void F_16 ( struct V_3 * V_4 ,
unsigned long V_63 )
{
F_15 ( & V_4 -> V_64 -> V_65 ) ;
V_4 -> V_58 . V_66 = V_63 ;
F_17 () ;
F_18 ( V_4 , V_67 ) ;
}
static int F_19 ( struct V_52 * V_68 ,
struct V_52 * V_69 )
{
if ( V_68 == NULL )
return 1 ;
for (; V_69 ; V_69 = V_69 -> V_60 )
if ( V_69 == V_68 )
return 1 ;
return 0 ;
}
static inline T_3 F_20 ( void )
{
struct V_3 * V_70 , * V_71 ;
F_21 ( ! F_22 ( & V_5 -> signal -> V_72 ) ) ;
F_15 ( & V_5 -> V_64 -> V_65 ) ;
V_71 = V_5 ;
F_23 (caller, thread) {
T_3 V_73 ;
if ( V_70 == V_71 )
continue;
if ( V_70 -> V_58 . V_66 == V_74 ||
( V_70 -> V_58 . V_66 == V_75 &&
F_19 ( V_70 -> V_58 . V_12 ,
V_71 -> V_58 . V_12 ) ) )
continue;
V_73 = F_24 ( V_70 ) ;
if ( F_10 ( F_11 ( V_73 == 0 ) ) )
V_73 = - V_76 ;
return V_73 ;
}
return 0 ;
}
static inline void F_25 ( void )
{
struct V_3 * V_70 , * V_71 ;
F_21 ( ! F_22 ( & V_5 -> signal -> V_72 ) ) ;
F_15 ( & V_5 -> V_64 -> V_65 ) ;
V_71 = V_5 ;
F_23 (caller, thread) {
if ( V_70 == V_71 )
continue;
F_26 ( V_71 ) ;
F_27 ( V_70 ) ;
F_28 ( & V_70 -> V_58 . V_12 ,
V_71 -> V_58 . V_12 ) ;
if ( F_29 ( V_71 ) )
F_30 ( V_70 ) ;
if ( V_70 -> V_58 . V_66 == V_74 )
F_16 ( V_70 , V_75 ) ;
}
}
static struct V_52 * F_31 ( struct V_77 * V_78 )
{
struct V_52 * V_79 ;
int V_55 ;
const bool V_80 = F_32 ( V_81 ) ;
if ( V_78 -> V_82 == 0 || V_78 -> V_82 > V_83 )
return F_33 ( - V_22 ) ;
F_21 ( V_84 / V_78 -> V_82 < sizeof( struct V_11 ) ) ;
if ( ! F_29 ( V_5 ) &&
F_34 ( F_35 () , F_36 () ,
V_85 ) != 0 )
return F_33 ( - V_86 ) ;
V_79 = F_37 ( sizeof( * V_79 ) , V_87 | V_88 ) ;
if ( ! V_79 )
return F_33 ( - V_89 ) ;
V_55 = F_38 ( & V_79 -> V_62 , V_78 ,
F_7 , V_80 ) ;
if ( V_55 < 0 ) {
F_39 ( V_79 ) ;
return F_33 ( V_55 ) ;
}
F_40 ( & V_79 -> V_90 , 1 ) ;
return V_79 ;
}
static struct V_52 *
F_41 ( const char T_4 * V_91 )
{
struct V_77 V_78 ;
struct V_52 * V_12 = F_33 ( - V_92 ) ;
#ifdef F_42
if ( F_43 () ) {
struct V_93 V_94 ;
if ( F_44 ( & V_94 , V_91 , sizeof( V_94 ) ) )
goto V_95;
V_78 . V_82 = V_94 . V_82 ;
V_78 . V_12 = F_45 ( V_94 . V_12 ) ;
} else
#endif
if ( F_44 ( & V_78 , V_91 , sizeof( V_78 ) ) )
goto V_95;
V_12 = F_31 ( & V_78 ) ;
V_95:
return V_12 ;
}
static long F_46 ( unsigned int V_96 ,
struct V_52 * V_12 )
{
unsigned long V_97 ;
struct V_52 * V_98 ;
F_15 ( & V_5 -> V_64 -> V_65 ) ;
V_97 = V_12 -> V_62 -> V_82 ;
for ( V_98 = V_5 -> V_58 . V_12 ; V_98 ; V_98 = V_98 -> V_60 )
V_97 += V_98 -> V_62 -> V_82 + 4 ;
if ( V_97 > V_99 )
return - V_89 ;
if ( V_96 & V_100 ) {
int V_55 ;
V_55 = F_20 () ;
if ( V_55 )
return V_55 ;
}
if ( V_96 & V_101 )
V_12 -> log = true ;
V_12 -> V_60 = V_5 -> V_58 . V_12 ;
V_5 -> V_58 . V_12 = V_12 ;
if ( V_96 & V_100 )
F_25 () ;
return 0 ;
}
static void F_47 ( struct V_52 * V_12 )
{
F_48 ( & V_12 -> V_90 ) ;
}
void F_26 ( struct V_3 * V_102 )
{
struct V_52 * V_103 = V_102 -> V_58 . V_12 ;
if ( ! V_103 )
return;
F_47 ( V_103 ) ;
}
static inline void F_49 ( struct V_52 * V_12 )
{
if ( V_12 ) {
F_50 ( V_12 -> V_62 ) ;
F_39 ( V_12 ) ;
}
}
static void F_51 ( struct V_52 * V_103 )
{
while ( V_103 && F_52 ( & V_103 -> V_90 ) ) {
struct V_52 * V_104 = V_103 ;
V_103 = V_103 -> V_60 ;
F_49 ( V_104 ) ;
}
}
void F_27 ( struct V_3 * V_102 )
{
F_51 ( V_102 -> V_58 . V_12 ) ;
}
static void F_53 ( T_5 * V_105 , int V_106 , int V_107 )
{
memset ( V_105 , 0 , sizeof( * V_105 ) ) ;
V_105 -> V_108 = V_109 ;
V_105 -> V_110 = V_111 ;
V_105 -> V_112 = ( void T_4 * ) F_6 ( V_5 ) ;
V_105 -> V_113 = V_107 ;
V_105 -> V_114 = F_4 () ;
V_105 -> V_115 = V_106 ;
}
static void F_54 ( int V_106 , int V_107 )
{
struct V_116 V_105 ;
F_53 ( & V_105 , V_106 , V_107 ) ;
F_55 ( V_109 , & V_105 , V_5 ) ;
}
static inline void F_56 ( unsigned long V_106 , long V_117 , T_2 V_118 ,
bool V_119 )
{
bool log = false ;
switch ( V_118 ) {
case V_56 :
break;
case V_120 :
log = V_119 && V_121 & V_122 ;
break;
case V_123 :
log = V_119 && V_121 & V_124 ;
break;
case V_125 :
log = V_119 && V_121 & V_126 ;
break;
case V_127 :
log = V_121 & V_128 ;
break;
case V_129 :
log = V_121 & V_130 ;
break;
case V_59 :
default:
log = V_121 & V_131 ;
}
if ( log )
return F_57 ( V_106 , V_117 , V_118 ) ;
return F_58 ( V_106 , V_117 , V_118 ) ;
}
static void F_59 ( int V_132 )
{
const int * V_133 = V_134 ;
#ifdef F_42
if ( F_43 () )
V_133 = F_60 () ;
#endif
do {
if ( * V_133 == V_132 )
return;
} while ( * ++ V_133 );
#ifdef F_61
F_62 () ;
#endif
F_56 ( V_132 , V_135 , V_129 , true ) ;
F_63 ( V_135 ) ;
}
void F_64 ( int V_132 )
{
int V_66 = V_5 -> V_58 . V_66 ;
if ( F_32 ( V_81 ) &&
F_10 ( V_5 -> V_136 & V_137 ) )
return;
if ( V_66 == V_74 )
return;
else if ( V_66 == V_138 )
F_59 ( V_132 ) ;
else
F_65 () ;
}
static int F_66 ( int V_132 , const struct V_1 * V_2 ,
const bool V_139 )
{
T_2 V_140 , V_118 ;
struct V_52 * V_53 = NULL ;
int V_141 ;
F_67 () ;
V_140 = F_8 ( V_2 , & V_53 ) ;
V_141 = V_140 & V_142 ;
V_118 = V_140 & V_143 ;
switch ( V_118 ) {
case V_123 :
if ( V_141 > V_144 )
V_141 = V_144 ;
F_68 ( V_5 , F_2 ( V_5 ) ,
- V_141 , 0 ) ;
goto V_145;
case V_120 :
F_69 ( V_5 , F_2 ( V_5 ) ) ;
F_54 ( V_132 , V_141 ) ;
goto V_145;
case V_125 :
if ( V_139 )
return 0 ;
if ( ! F_70 ( V_5 , V_146 ) ) {
F_68 ( V_5 ,
F_2 ( V_5 ) ,
- V_147 , 0 ) ;
goto V_145;
}
F_71 ( V_146 , V_141 ) ;
if ( F_72 ( V_5 ) )
goto V_145;
V_132 = F_3 ( V_5 , F_2 ( V_5 ) ) ;
if ( V_132 < 0 )
goto V_145;
if ( F_66 ( V_132 , NULL , true ) )
return - 1 ;
return 0 ;
case V_127 :
F_56 ( V_132 , 0 , V_118 , true ) ;
return 0 ;
case V_56 :
return 0 ;
case V_129 :
case V_59 :
default:
F_56 ( V_132 , V_109 , V_118 , true ) ;
if ( V_118 == V_59 ||
F_73 ( V_5 ) == 1 ) {
T_5 V_105 ;
F_69 ( V_5 , F_2 ( V_5 ) ) ;
F_53 ( & V_105 , V_132 , V_141 ) ;
F_74 ( & V_105 ) ;
}
if ( V_118 == V_59 )
F_75 ( V_109 ) ;
else
F_63 ( V_109 ) ;
}
F_76 () ;
V_145:
F_56 ( V_132 , 0 , V_118 , V_53 ? V_53 -> log : false ) ;
return - 1 ;
}
static int F_66 ( int V_132 , const struct V_1 * V_2 ,
const bool V_139 )
{
F_65 () ;
}
int F_77 ( const struct V_1 * V_2 )
{
int V_66 = V_5 -> V_58 . V_66 ;
int V_132 ;
if ( F_32 ( V_81 ) &&
F_10 ( V_5 -> V_136 & V_137 ) )
return 0 ;
V_132 = V_2 ? V_2 -> V_8 :
F_3 ( V_5 , F_2 ( V_5 ) ) ;
switch ( V_66 ) {
case V_138 :
F_59 ( V_132 ) ;
return 0 ;
case V_75 :
return F_66 ( V_132 , V_2 , false ) ;
default:
F_65 () ;
}
}
long F_78 ( void )
{
return V_5 -> V_58 . V_66 ;
}
static long F_79 ( void )
{
const unsigned long V_63 = V_138 ;
long V_55 = - V_22 ;
F_80 ( & V_5 -> V_64 -> V_65 ) ;
if ( ! F_14 ( V_63 ) )
goto V_95;
#ifdef F_81
F_82 () ;
#endif
F_16 ( V_5 , V_63 ) ;
V_55 = 0 ;
V_95:
F_83 ( & V_5 -> V_64 -> V_65 ) ;
return V_55 ;
}
static long F_84 ( unsigned int V_96 ,
const char T_4 * V_12 )
{
const unsigned long V_63 = V_75 ;
struct V_52 * V_148 = NULL ;
long V_55 = - V_22 ;
if ( V_96 & ~ V_149 )
return - V_22 ;
V_148 = F_41 ( V_12 ) ;
if ( F_85 ( V_148 ) )
return F_86 ( V_148 ) ;
if ( V_96 & V_100 &&
F_87 ( & V_5 -> signal -> V_72 ) )
goto V_150;
F_80 ( & V_5 -> V_64 -> V_65 ) ;
if ( ! F_14 ( V_63 ) )
goto V_95;
V_55 = F_46 ( V_96 , V_148 ) ;
if ( V_55 )
goto V_95;
V_148 = NULL ;
F_16 ( V_5 , V_63 ) ;
V_95:
F_83 ( & V_5 -> V_64 -> V_65 ) ;
if ( V_96 & V_100 )
F_88 ( & V_5 -> signal -> V_72 ) ;
V_150:
F_49 ( V_148 ) ;
return V_55 ;
}
static inline long F_84 ( unsigned int V_96 ,
const char T_4 * V_12 )
{
return - V_22 ;
}
static long F_89 ( const char T_4 * V_151 )
{
T_2 V_118 ;
if ( F_44 ( & V_118 , V_151 , sizeof( V_118 ) ) )
return - V_92 ;
switch ( V_118 ) {
case V_59 :
case V_129 :
case V_120 :
case V_123 :
case V_125 :
case V_127 :
case V_56 :
break;
default:
return - V_152 ;
}
return 0 ;
}
static long F_90 ( unsigned int V_153 , unsigned int V_96 ,
const char T_4 * V_154 )
{
switch ( V_153 ) {
case V_155 :
if ( V_96 != 0 || V_154 != NULL )
return - V_22 ;
return F_79 () ;
case V_156 :
return F_84 ( V_96 , V_154 ) ;
case V_157 :
if ( V_96 != 0 )
return - V_22 ;
return F_89 ( V_154 ) ;
default:
return - V_22 ;
}
}
long F_91 ( unsigned long V_63 , char T_4 * V_12 )
{
unsigned int V_153 ;
char T_4 * V_154 ;
switch ( V_63 ) {
case V_138 :
V_153 = V_155 ;
V_154 = NULL ;
break;
case V_75 :
V_153 = V_156 ;
V_154 = V_12 ;
break;
default:
return - V_22 ;
}
return F_90 ( V_153 , 0 , V_154 ) ;
}
long F_92 ( struct V_3 * V_4 , unsigned long V_158 ,
void T_4 * V_141 )
{
struct V_52 * V_12 ;
struct V_159 * V_78 ;
long V_55 ;
unsigned long V_160 = 0 ;
if ( ! F_93 ( V_85 ) ||
V_5 -> V_58 . V_66 != V_74 ) {
return - V_86 ;
}
F_80 ( & V_4 -> V_64 -> V_65 ) ;
if ( V_4 -> V_58 . V_66 != V_75 ) {
V_55 = - V_22 ;
goto V_95;
}
V_12 = V_4 -> V_58 . V_12 ;
while ( V_12 ) {
V_12 = V_12 -> V_60 ;
V_160 ++ ;
}
if ( V_158 >= V_160 ) {
V_55 = - V_161 ;
goto V_95;
}
V_160 -= V_158 ;
V_12 = V_4 -> V_58 . V_12 ;
while ( V_12 && V_160 > 1 ) {
V_12 = V_12 -> V_60 ;
V_160 -- ;
}
if ( F_11 ( V_160 != 1 || ! V_12 ) ) {
V_55 = - V_161 ;
goto V_95;
}
V_78 = V_12 -> V_62 -> V_162 ;
if ( ! V_78 ) {
V_55 = - V_163 ;
goto V_95;
}
V_55 = V_78 -> V_82 ;
if ( ! V_141 )
goto V_95;
F_47 ( V_12 ) ;
F_83 ( & V_4 -> V_64 -> V_65 ) ;
if ( F_94 ( V_141 , V_78 -> V_12 , F_95 ( V_78 ) ) )
V_55 = - V_92 ;
F_51 ( V_12 ) ;
return V_55 ;
V_95:
F_83 ( & V_4 -> V_64 -> V_65 ) ;
return V_55 ;
}
static bool F_96 ( char * V_164 , T_6 V_165 ,
T_2 V_166 )
{
const struct V_167 * V_168 ;
bool V_169 = false ;
for ( V_168 = V_170 ; V_168 -> V_171 && V_165 ; V_168 ++ ) {
T_7 V_55 ;
if ( ! ( V_166 & V_168 -> log ) )
continue;
if ( V_169 ) {
V_55 = F_97 ( V_164 , L_1 , V_165 ) ;
if ( V_55 < 0 )
return false ;
V_164 += V_55 ;
V_165 -= V_55 ;
} else
V_169 = true ;
V_55 = F_97 ( V_164 , V_168 -> V_171 , V_165 ) ;
if ( V_55 < 0 )
return false ;
V_164 += V_55 ;
V_165 -= V_55 ;
}
return true ;
}
static bool F_98 ( T_2 * V_172 ,
const char * V_171 )
{
const struct V_167 * V_168 ;
for ( V_168 = V_170 ; V_168 -> V_171 ; V_168 ++ ) {
if ( ! strcmp ( V_168 -> V_171 , V_171 ) ) {
* V_172 = V_168 -> log ;
return true ;
}
}
return false ;
}
static bool F_99 ( T_2 * V_166 , char * V_164 )
{
char * V_171 ;
* V_166 = 0 ;
while ( ( V_171 = F_100 ( & V_164 , L_1 ) ) && * V_171 ) {
T_2 V_172 = 0 ;
if ( ! F_98 ( & V_172 , V_171 ) )
return false ;
* V_166 |= V_172 ;
}
return true ;
}
static int F_101 ( struct V_173 * V_174 , int V_175 ,
void T_4 * V_176 , T_6 * V_177 ,
T_8 * V_178 )
{
char V_164 [ sizeof( V_179 ) ] ;
struct V_173 V_180 ;
int V_55 ;
if ( V_175 && ! F_93 ( V_85 ) )
return - V_181 ;
memset ( V_164 , 0 , sizeof( V_164 ) ) ;
if ( ! V_175 ) {
if ( ! F_96 ( V_164 , sizeof( V_164 ) ,
V_121 ) )
return - V_22 ;
}
V_180 = * V_174 ;
V_180 . V_141 = V_164 ;
V_180 . V_182 = sizeof( V_164 ) ;
V_55 = F_102 ( & V_180 , V_175 , V_176 , V_177 , V_178 ) ;
if ( V_55 )
return V_55 ;
if ( V_175 ) {
T_2 V_166 ;
if ( ! F_99 ( & V_166 ,
V_180 . V_141 ) )
return - V_22 ;
if ( V_166 & V_183 )
return - V_22 ;
V_121 = V_166 ;
}
return 0 ;
}
static int T_9 F_103 ( void )
{
struct V_184 * V_185 ;
V_185 = F_104 ( V_186 , V_187 ) ;
if ( ! V_185 )
F_105 ( L_2 ) ;
else
F_106 ( V_185 ) ;
return 0 ;
}

static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static bool F_3 ( void )
{
char V_6 [ 1024 ] ;
int V_7 ;
if ( V_8 == NULL )
return false ;
V_7 = F_4 ( V_8 , & V_9 ) ;
if ( V_7 != 0 ) {
F_5 ( L_1 ,
V_8 ) ;
return false ;
}
F_6 ( & V_9 , & V_9 , V_10 ) ;
if ( F_7 ( & V_9 ) ) {
F_5 ( L_2 ,
V_8 ) ;
return false ;
}
F_8 ( V_6 , sizeof( V_6 ) , & V_9 ) ;
F_9 ( L_3 , V_6 ) ;
return true ;
}
static void F_10 ( unsigned long V_11 , unsigned long * V_12 )
{
F_11 ( sizeof( V_13 ) != sizeof( unsigned long ) ) ;
F_12 ( V_11 , ( V_13 * ) V_12 ) ;
}
static bool F_13 ( int V_5 , int V_14 )
{
struct V_15 * V_16 = & V_15 [ V_5 ] ;
T_1 V_17 = V_18 [ V_14 ] ;
T_2 V_19 = F_14 ( V_17 ) ;
const unsigned long V_20 = 128 ;
struct V_21 * V_22 ;
int V_23 ;
V_23 = sizeof( struct V_21 * * ) + V_20 + V_19 ;
V_22 = F_15 ( V_23 ) ;
if ( V_22 == NULL )
return false ;
F_16 ( V_22 , sizeof( struct V_21 * * ) ) ;
F_16 ( V_22 , - ( long ) V_22 -> V_24 & ( V_20 - 1 ) ) ;
* (struct V_21 * * ) ( V_22 -> V_24 - sizeof( struct V_21 * * ) ) = V_22 ;
F_17 () ;
F_18 ( & V_16 -> V_25 , V_16 -> V_26 + V_14 ,
( void * ) F_19 ( V_22 -> V_24 ) ) ;
return true ;
}
static struct V_21 * F_20 ( void * V_27 )
{
struct V_21 * * V_28 = V_27 - sizeof( * V_28 ) ;
struct V_21 * V_22 = * V_28 ;
if ( V_22 -> V_24 != V_27 ) {
F_21 ( L_4 ,
V_27 , V_22 , V_22 -> V_24 ) ;
}
return V_22 ;
}
static void F_22 ( int V_5 , int V_29 )
{
struct V_15 * V_16 = & V_15 [ V_5 ] ;
for (; ; ) {
T_3 V_30 =
( T_3 ) F_23 ( & V_16 -> V_25 ,
V_29 ) ;
if ( V_30 == 0 )
break;
F_24 ( F_20 ( F_25 ( V_30 ) ) ) ;
}
}
static void F_26 ( void )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
int V_5 , V_14 ;
for ( V_5 = 0 ; V_5 < V_34 &&
V_32 -> V_35 [ V_5 ] . V_36 ; V_5 ++ ) {
for ( V_14 = 0 ; V_14 < V_37 ; V_14 ++ ) {
while ( V_32 -> V_35 [ V_5 ] . V_38 [ V_14 ]
!= 0 ) {
if ( ! F_13 ( V_5 , V_14 ) ) {
F_28 ( L_5
L_6 ,
V_32 -> V_39 ) ;
return;
}
V_32 -> V_35 [ V_5 ] .
V_38 [ V_14 ] -- ;
}
}
}
}
static void F_29 ( struct V_3 * V_4 , struct V_21 * V_22 ,
T_4 * V_40 )
{
#ifdef F_30
if ( F_31 ( V_4 -> V_41 . V_42 != V_43 ) ) {
struct V_44 * V_45 = F_32 ( V_22 ) ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_46 = F_33 ( V_40 -> V_47 ,
V_40 -> V_48 ) ;
}
#endif
}
static void F_34 ( struct V_21 * V_22 , int V_5 )
{
#ifdef F_30
struct V_49 * V_50 = F_35 ( V_22 ) ;
if ( F_31 ( ( V_50 -> V_51 & V_52 ) != 0 ) ) {
struct V_15 * V_16 = & V_15 [ V_5 ] ;
struct V_44 V_45 ;
struct V_53 V_54 ;
V_50 -> V_51 |= V_55 ;
F_36 ( & V_16 -> V_25 , & V_54 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_46 = F_33 ( V_54 . V_56 , V_54 . V_57 ) ;
F_37 ( V_22 , & V_45 ) ;
}
#endif
}
static int F_38 ( struct V_1 * V_2 , struct V_58 * V_59 ,
int V_60 )
{
#ifdef F_30
struct V_61 V_62 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_39 ( & V_62 , V_59 -> V_63 , sizeof( V_62 ) ) )
return - V_64 ;
if ( V_62 . V_65 )
return - V_66 ;
switch ( V_62 . V_67 ) {
case V_68 :
case V_69 :
break;
default:
return - V_70 ;
}
switch ( V_62 . V_42 ) {
case V_43 :
break;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
V_62 . V_42 = V_71 ;
break;
default:
return - V_70 ;
}
if ( F_40 ( V_59 -> V_63 , & V_62 , sizeof( V_62 ) ) )
return - V_64 ;
V_4 -> V_41 = V_62 ;
return 0 ;
#else
return - V_85 ;
#endif
}
static inline bool F_41 ( struct V_1 * V_2 , void * V_6 )
{
if ( V_2 == NULL || ! ( V_2 -> V_65 & V_86 ) )
return true ;
if ( ! ( V_2 -> V_65 & V_87 ) &&
! F_42 ( V_6 ) &&
! F_43 ( V_2 -> V_88 , V_6 ) )
return true ;
return false ;
}
static void F_44 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_4 * V_40 , unsigned long V_23 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_4 -> V_5 ;
F_45 ( V_22 , V_23 ) ;
V_22 -> V_89 = F_46 ( V_22 , V_2 ) ;
if ( V_40 -> V_90 && V_40 -> V_91 == 0xFFFF )
V_22 -> V_92 = V_93 ;
F_29 ( V_4 , V_22 , V_40 ) ;
F_47 ( & V_32 -> V_35 [ V_5 ] . V_94 , V_22 ) ;
F_10 ( 1 , & V_2 -> V_95 . V_96 ) ;
F_10 ( V_23 , & V_2 -> V_95 . V_97 ) ;
if ( V_40 -> V_98 == V_18 [ 0 ] )
V_32 -> V_35 [ V_5 ] . V_38 [ 0 ] ++ ;
else if ( V_40 -> V_98 == V_18 [ 1 ] )
V_32 -> V_35 [ V_5 ] . V_38 [ 1 ] ++ ;
else
V_32 -> V_35 [ V_5 ] . V_38 [ 2 ] ++ ;
}
static bool F_48 ( int V_5 , T_4 * V_40 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
struct V_1 * V_2 = V_16 -> V_99 [ V_40 -> V_100 ] ;
T_5 V_101 ;
void * V_27 ;
void * V_6 ;
unsigned long V_23 ;
bool V_102 ;
if ( V_40 -> V_103 || V_40 -> V_104 || V_40 -> V_105 || V_40 -> V_106 ) {
if ( V_2 )
F_10 ( 1 , & V_2 -> V_95 . V_107 ) ;
goto V_108;
}
V_101 = V_109 ? 0 : F_49 ( V_40 ) ;
V_27 = F_25 ( ( unsigned long ) V_40 -> V_27 ) ;
V_6 = V_27 + V_101 ;
V_23 = V_40 -> V_110 - V_101 ;
V_27 -= V_111 ;
V_102 = F_41 ( V_2 , V_6 ) ;
if ( V_102 ) {
if ( V_2 )
F_10 ( 1 , & V_2 -> V_95 . V_112 ) ;
V_108:
F_50 ( & V_32 -> V_35 [ V_5 ] . V_113 , V_40 ) ;
} else {
struct V_21 * V_22 = F_20 ( V_27 ) ;
F_16 ( V_22 , V_111 + V_101 ) ;
F_44 ( V_2 , V_22 , V_40 , V_23 ) ;
}
F_51 ( & V_32 -> V_35 [ V_5 ] . V_113 , V_40 ) ;
return ! V_102 ;
}
static int F_52 ( struct V_114 * V_94 , int V_115 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
unsigned int V_116 = 0 ;
T_4 * V_40 ;
int V_5 , V_117 , V_118 ;
struct V_15 * V_16 ;
struct V_119 * V_119 =
F_53 ( V_94 , struct V_119 , V_94 ) ;
V_5 = V_119 -> V_5 ;
while ( ( V_118 = F_54 (
& V_119 -> V_113 ,
& V_40 ) ) > 0 ) {
for ( V_117 = 0 ; V_117 < V_118 ; V_117 ++ ) {
if ( V_117 == V_120 )
goto V_121;
if ( F_48 ( V_5 ,
V_40 + V_117 ) ) {
if ( ++ V_116 >= V_115 )
goto V_121;
}
}
}
F_55 ( & V_119 -> V_94 ) ;
V_16 = & V_15 [ V_5 ] ;
F_56 (
& V_16 -> V_25 , V_32 -> V_35 [ V_5 ] . V_113 . V_122 ) ;
if ( F_54 ( & V_119 -> V_113 , & V_40 ) > 0 )
F_57 ( & V_119 -> V_94 ) ;
V_121:
F_26 () ;
return V_116 ;
}
static T_6 F_58 ( int V_123 , void * V_124 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
F_57 ( & V_32 -> V_35 [ ( V_125 ) V_124 ] . V_94 ) ;
return V_126 ;
}
static int F_59 ( T_7 * V_127 ,
struct V_128 * V_129 ,
int V_130 , bool V_131 )
{
int V_118 = 0 ;
while ( V_129 -> V_132 < V_129 -> V_133 ) {
unsigned int V_134 = V_129 -> V_132 % V_135 ;
struct V_136 * V_137 = & V_129 -> V_138 [ V_134 ] ;
if ( ! F_60 ( V_127 , V_137 -> V_139 ,
V_131 || V_118 == 0 ) )
break;
F_24 ( V_137 -> V_22 ) ;
V_129 -> V_132 ++ ;
if ( ++ V_118 == V_130 )
break;
}
return V_118 ;
}
static void F_61 ( T_7 * V_127 ,
struct V_128 * V_129 ,
V_125 V_139 , struct V_21 * V_22 )
{
int V_134 = V_129 -> V_133 % V_135 ;
V_129 -> V_138 [ V_134 ] . V_139 = V_139 ;
V_129 -> V_138 [ V_134 ] . V_22 = V_22 ;
V_129 -> V_133 ++ ;
}
static void F_62 ( struct V_1 * V_2 ,
int V_140 )
{
struct V_31 * V_32 = & F_63 ( V_33 , V_140 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_4 -> V_5 ;
struct V_141 * V_142 =
& V_32 -> V_35 [ V_5 ] . V_142 [ V_4 -> V_143 ] ;
F_64 ( & V_142 -> V_144 ,
F_33 ( 0 , V_145 * 1000UL ) ,
V_146 ) ;
}
static enum V_147 F_65 ( struct V_148 * V_149 )
{
struct V_141 * V_142 =
F_53 ( V_149 , struct V_141 , V_144 ) ;
F_66 ( V_142 -> V_2 , V_142 -> V_140 ) ;
return V_150 ;
}
static void F_67 ( void )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
if ( ! V_32 -> V_151 ) {
F_64 ( & V_32 -> V_152 ,
F_33 ( 0 , V_153 * 1000UL ) ,
V_146 ) ;
V_32 -> V_151 = true ;
}
}
static enum V_147 F_68 ( struct V_148 * V_149 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
unsigned long V_154 ;
bool V_155 = false ;
int V_117 , V_5 ;
F_69 ( V_154 ) ;
V_32 -> V_151 = false ;
for ( V_5 = 0 ; V_5 < V_34 &&
V_32 -> V_35 [ V_5 ] . V_36 ; V_5 ++ ) {
for ( V_117 = 0 ; V_117 < V_156 ; V_117 ++ ) {
struct V_157 * V_158 =
& V_15 [ V_5 ] . V_159 [ V_117 ] ;
struct V_128 * V_129 =
V_32 -> V_35 [ V_5 ] . V_160 [ V_117 ] ;
if ( ! V_158 || V_129 -> V_132 >= V_129 -> V_133 )
continue;
F_59 ( V_158 -> V_127 , V_129 , - 1 , true ) ;
V_155 = V_155 ||
( V_129 -> V_132 < V_129 -> V_133 ) ;
}
}
if ( V_155 )
F_67 () ;
F_70 ( V_154 ) ;
return V_150 ;
}
static int F_71 ( struct V_161 * V_162 , T_8 V_163 )
{
int V_164 = 0 ;
struct V_15 * V_16 = F_53 ( V_162 , struct V_15 , V_165 ) ;
F_72 ( & V_16 -> V_166 ) ;
if ( F_73 ( & V_16 -> V_25 , V_163 ) )
V_164 = - V_66 ;
F_74 ( & V_16 -> V_166 ) ;
return V_164 ;
}
static int F_75 ( struct V_161 * V_162 , T_9 V_167 )
{
int V_164 = 0 ;
struct V_15 * V_16 = F_53 ( V_162 , struct V_15 , V_165 ) ;
F_72 ( & V_16 -> V_166 ) ;
if ( F_76 ( & V_16 -> V_25 , V_167 ) )
V_164 = - V_168 ;
F_74 ( & V_16 -> V_166 ) ;
return V_164 ;
}
static int F_77 ( struct V_161 * V_162 , struct V_53 * V_54 )
{
int V_164 = 0 ;
struct V_15 * V_16 = F_53 ( V_162 , struct V_15 , V_165 ) ;
F_72 ( & V_16 -> V_166 ) ;
if ( F_36 ( & V_16 -> V_25 , V_54 ) )
V_164 = - V_168 ;
F_74 ( & V_16 -> V_166 ) ;
return V_164 ;
}
static int F_78 ( struct V_161 * V_162 ,
const struct V_53 * V_54 )
{
int V_164 = 0 ;
struct V_15 * V_16 = F_53 ( V_162 , struct V_15 , V_165 ) ;
F_72 ( & V_16 -> V_166 ) ;
if ( F_79 ( & V_16 -> V_25 , V_54 ) )
V_164 = - V_168 ;
F_74 ( & V_16 -> V_166 ) ;
return V_164 ;
}
static int F_80 ( struct V_161 * V_162 ,
struct V_169 * V_170 , int V_171 )
{
return - V_85 ;
}
static void F_81 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
#ifdef F_30
struct V_53 V_54 ;
F_82 ( & V_54 ) ;
F_79 ( & V_16 -> V_25 , & V_54 ) ;
F_83 ( & V_16 -> V_166 ) ;
V_16 -> V_165 = V_172 ;
V_16 -> V_173 = F_84 ( & V_16 -> V_165 , NULL ) ;
if ( F_85 ( V_16 -> V_173 ) )
F_86 ( V_2 , L_7 ,
F_87 ( V_16 -> V_173 ) ) ;
#endif
}
static void F_88 ( struct V_3 * V_4 )
{
#ifdef F_30
V_4 -> V_41 . V_42 = V_43 ;
V_4 -> V_41 . V_67 = V_68 ;
#endif
}
static void F_89 ( void * V_123 )
{
F_90 ( ( long ) V_123 , 0 ) ;
}
static void F_91 ( void * V_123 )
{
F_92 ( ( long ) V_123 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
static T_10 V_174 ;
bool V_175 = false ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
int V_100 ;
int V_7 ;
int V_176 ;
V_175 = false ;
F_94 ( & V_174 , & V_16 -> V_25 ) ;
for ( V_100 = 0 ; V_100 < V_156 ; V_100 ++ ) {
if ( V_16 -> V_99 [ V_100 ] == NULL )
continue;
if ( ! V_175 ) {
V_175 = true ;
F_95 ( & V_174 , V_16 -> V_177 ,
V_16 -> V_178 , NULL ) ;
F_96 ( & V_174 , V_111 ) ;
}
F_97 ( & V_174 , V_100 ) ;
}
V_7 = F_98 ( & V_174 ) ;
if ( V_7 != 0 ) {
F_99 ( V_2 , L_8 ,
V_5 , V_7 ) ;
return - V_179 ;
}
if ( ! V_175 )
F_100 ( F_91 ,
( void * ) ( long ) ( V_16 -> V_180 ) , 1 ) ;
F_101 (cpu) {
struct V_31 * V_32 = & F_63 ( V_33 , V_176 ) ;
if ( ! V_32 -> V_35 [ V_5 ] . V_36 )
continue;
if ( V_175 ) {
if ( ! V_32 -> V_35 [ V_5 ] . V_181 ) {
F_102 ( V_2 , & V_32 -> V_35 [ V_5 ] . V_94 ,
F_52 , V_182 ) ;
V_32 -> V_35 [ V_5 ] . V_181 = true ;
}
if ( ! V_32 -> V_35 [ V_5 ] . V_183 ) {
F_103 ( & V_32 -> V_35 [ V_5 ] . V_94 ) ;
V_32 -> V_35 [ V_5 ] . V_183 = true ;
}
} else {
if ( V_32 -> V_35 [ V_5 ] . V_183 ) {
F_104 ( & V_32 -> V_35 [ V_5 ] . V_94 ) ;
V_32 -> V_35 [ V_5 ] . V_183 = false ;
}
}
}
if ( V_175 )
F_100 ( F_89 ,
( void * ) ( long ) ( V_16 -> V_180 ) , 1 ) ;
if ( V_175 )
F_105 ( V_5 , - 1 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
int V_14 , T_2 V_184 )
{
T_11 V_185 = F_107 ((pte_t) { 0 }, PAGE_HOME_HASH) ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
T_2 V_186 = F_108 ( V_184 ) ;
int V_187 = V_16 -> V_26 + V_14 ;
void * V_27 ;
int V_117 , V_7 ;
V_16 -> V_188 [ V_14 ] =
F_109 ( V_186 , 64 * 1024 ) ;
V_27 = F_110 ( V_16 -> V_188 [ V_14 ] , V_189 ) ;
if ( V_27 == NULL ) {
F_86 ( V_2 ,
L_9 ,
V_16 -> V_188 [ V_14 ] , V_14 ) ;
return - V_190 ;
}
V_7 = F_111 ( & V_16 -> V_25 , V_187 ,
V_18 [ V_14 ] , V_27 ,
V_16 -> V_188 [ V_14 ] , 0 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 , L_10 ,
V_5 , V_7 ) ;
F_112 ( V_27 , V_16 -> V_188 [ V_14 ] ) ;
return V_7 ;
}
V_16 -> V_191 [ V_14 ] = V_27 ;
V_7 = F_113 ( & V_16 -> V_25 , V_187 ,
V_185 , 0 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 ,
L_11 ,
V_5 , V_7 ) ;
return V_7 ;
}
for ( V_117 = 0 ; V_117 < V_184 ; V_117 ++ ) {
if ( ! F_13 ( V_5 , V_14 ) ) {
F_86 ( V_2 , L_12 ) ;
return - V_190 ;
}
}
return 0 ;
}
static int F_114 ( struct V_1 * V_2 ,
int V_192 )
{
int V_193 = V_37 - ( V_194 == 0 ) ;
T_2 V_184 ;
int V_7 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
V_7 = F_115 ( & V_16 -> V_25 , V_193 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 ,
L_13 ,
V_5 , V_7 ) ;
return V_7 ;
}
V_16 -> V_26 = V_7 ;
V_184 =
V_192 * ( V_195 + V_120 ) ;
if ( V_7 >= 0 )
V_7 = F_106 ( V_2 , 0 , V_184 ) ;
if ( V_7 >= 0 )
V_7 = F_106 ( V_2 , 1 , V_184 ) ;
if ( V_7 >= 0 && V_194 != 0 )
V_7 = F_106 ( V_2 , 2 , V_194 ) ;
return V_7 ;
}
static int F_116 ( struct V_1 * V_2 ,
int V_176 , int V_122 )
{
struct V_31 * V_32 = & F_63 ( V_33 , V_176 ) ;
int V_196 , V_117 , V_7 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
struct V_197 * V_197 ;
void * V_30 ;
V_196 = F_117 ( V_198 ) ;
V_197 = F_118 ( V_189 , V_196 , V_176 ) ;
if ( V_197 == NULL ) {
F_86 ( V_2 , L_14 ,
V_198 ) ;
return - V_190 ;
}
V_30 = F_119 ( F_120 ( V_197 ) ) ;
memset ( V_30 , 0 , V_198 ) ;
for ( V_117 = 0 ; V_117 < V_156 ; V_117 ++ )
V_32 -> V_35 [ V_5 ] . V_160 [ V_117 ] =
V_30 + V_117 * sizeof( struct V_128 ) ;
if ( F_121 ( V_176 , V_9 ) ) {
V_196 = F_117 ( V_199 ) ;
V_197 = F_118 ( V_189 , V_196 , V_176 ) ;
if ( V_197 == NULL ) {
F_86 ( V_2 ,
L_15 ,
V_199 ) ;
return - V_190 ;
}
V_30 = F_119 ( F_120 ( V_197 ) ) ;
V_7 = F_122 ( & V_32 -> V_35 [ V_5 ] . V_113 ,
& V_16 -> V_25 , V_122 ++ , V_30 ,
V_199 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 ,
L_16 , V_7 ) ;
return V_7 ;
}
V_32 -> V_35 [ V_5 ] . V_36 = true ;
}
return V_122 ;
}
static int F_123 ( struct V_1 * V_2 ,
int V_122 , int V_192 )
{
int V_200 , V_7 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
V_7 = F_124 ( & V_16 -> V_25 , 1 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 , L_17 ,
V_5 , V_7 ) ;
return V_7 ;
}
V_200 = V_7 ;
if ( V_192 > 4 )
V_16 -> V_178 = 256 ;
else if ( V_192 > 1 )
V_16 -> V_178 = 16 ;
V_7 = F_125 ( & V_16 -> V_25 , V_16 -> V_178 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 , L_18 ,
V_5 , V_7 ) ;
return V_7 ;
}
V_16 -> V_177 = V_7 ;
V_7 = F_126 (
& V_16 -> V_25 , V_200 , V_122 , V_192 ,
V_16 -> V_177 , V_16 -> V_178 ,
V_201 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 , L_19
L_20 , V_5 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_176 , V_7 , V_123 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
V_123 = V_16 -> V_180 ;
if ( V_123 < 0 ) {
V_123 = F_128 () ;
if ( V_123 < 0 ) {
F_86 ( V_2 ,
L_21 ,
V_5 , V_123 ) ;
return V_123 ;
}
F_129 ( V_123 , V_202 ) ;
V_7 = F_130 ( V_123 , F_58 ,
0 , L_22 , ( void * ) ( ( V_125 ) V_5 ) ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 , L_23 ,
V_5 , V_7 ) ;
F_131 ( V_123 ) ;
return V_7 ;
}
V_16 -> V_180 = V_123 ;
}
F_101 (cpu) {
struct V_31 * V_32 = & F_63 ( V_33 , V_176 ) ;
if ( V_32 -> V_35 [ V_5 ] . V_36 ) {
F_132 ( & V_16 -> V_25 ,
F_133 ( V_176 ) , F_134 ( V_176 ) , V_203 , V_123 ,
V_32 -> V_35 [ V_5 ] . V_113 . V_122 ) ;
}
}
return 0 ;
}
static void F_135 ( int V_5 )
{
int V_14 , V_176 ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
for ( V_14 = 0 ; V_14 < V_37 ; V_14 ++ ) {
if ( V_16 -> V_191 [ V_14 ] != NULL ) {
F_22 ( V_5 ,
V_16 -> V_26 +
V_14 ) ;
}
}
F_136 ( & V_16 -> V_25 ) ;
F_101 (cpu) {
struct V_31 * V_32 = & F_63 ( V_33 , V_176 ) ;
F_137 (
( unsigned long ) (
V_32 -> V_35 [ V_5 ] . V_160 [ 0 ] ) ,
F_117 ( V_198 ) ) ;
V_32 -> V_35 [ V_5 ] . V_160 [ 0 ] = NULL ;
F_137 ( ( unsigned long ) ( V_32 -> V_35 [ V_5 ] . V_113 . V_204 ) ,
F_117 ( V_199 ) ) ;
V_32 -> V_35 [ V_5 ] . V_113 . V_204 = NULL ;
}
for ( V_14 = 0 ; V_14 < V_37 ; V_14 ++ ) {
if ( V_16 -> V_191 [ V_14 ] != NULL ) {
F_112 ( V_16 -> V_191 [ V_14 ] ,
V_16 -> V_188 [ V_14 ] ) ;
V_16 -> V_191 [ V_14 ] = NULL ;
}
}
V_16 -> V_26 = - 1 ;
V_16 -> V_177 = - 1 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_7 ;
int V_176 ;
int V_205 , V_122 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
int V_192 = F_139 ( V_9 ) ;
if ( ! V_206 ) {
F_86 ( V_2 , L_24 ) ;
return - V_179 ;
}
V_7 = F_140 ( & V_16 -> V_25 , V_5 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 , L_25 ,
V_5 , V_7 ) ;
return - V_179 ;
}
V_7 = F_114 ( V_2 , V_192 ) ;
if ( V_7 != 0 )
goto V_207;
V_7 = F_141 ( & V_16 -> V_25 ,
V_192 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 , L_26 ,
V_7 ) ;
goto V_207;
}
V_205 = V_7 ;
V_122 = V_205 ;
F_101 (cpu) {
V_7 = F_116 ( V_2 , V_176 , V_122 ) ;
if ( V_7 < 0 )
goto V_207;
V_122 = V_7 ;
}
V_7 = F_123 ( V_2 , V_205 , V_192 ) ;
if ( V_7 != 0 )
goto V_207;
V_7 = F_127 ( V_2 ) ;
if ( V_7 != 0 )
goto V_207;
F_81 ( V_2 , V_16 ) ;
return 0 ;
V_207:
F_135 ( V_5 ) ;
return V_7 ;
}
static int F_142 ( struct V_1 * V_2 , int V_143 )
{
static int V_208 = - 1 ;
struct V_197 * V_209 , * V_210 , * V_211 ;
T_12 * V_212 ;
T_7 * V_127 ;
unsigned char * V_213 ;
int V_214 , V_215 , V_216 ;
T_2 V_217 ;
int V_7 = - V_190 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
if ( V_16 -> V_159 [ V_143 ] . V_127 != NULL )
return 0 ;
V_214 = F_117 ( V_218 * V_219 ) ;
V_209 = F_143 ( V_189 , V_214 ) ;
if ( V_209 == NULL ) {
F_99 ( V_2 ,
L_27 ,
V_220 << V_214 ) ;
goto V_207;
}
V_213 = F_119 ( F_120 ( V_209 ) ) ;
V_217 = V_218 * sizeof( * V_212 ) ;
V_215 = F_117 ( V_217 ) ;
V_210 = F_143 ( V_189 , V_215 ) ;
if ( V_210 == NULL ) {
F_99 ( V_2 ,
L_28 ,
V_217 ) ;
goto V_221;
}
V_212 = F_119 ( F_120 ( V_210 ) ) ;
V_216 = F_117 ( sizeof( * V_127 ) ) ;
V_211 = F_143 ( V_189 , V_216 ) ;
if ( V_211 == NULL ) {
F_99 ( V_2 ,
L_29 ,
V_220 << V_216 ) ;
goto V_222;
}
V_127 = F_119 ( F_120 ( V_211 ) ) ;
if ( V_208 < 0 ) {
V_7 = F_144 ( & V_16 -> V_25 , 1 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_99 ( V_2 , L_30
L_20 , V_5 , V_7 ) ;
goto V_223;
}
V_208 = V_7 ;
}
V_7 = F_145 ( V_127 , & V_16 -> V_25 , V_208 , V_143 ,
V_212 , V_217 , 0 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 , L_31 ,
V_5 , V_7 ) ;
goto V_223;
}
V_208 = - 1 ;
if ( V_194 != 0 ) {
if ( F_146 ( V_127 , 10368 ) < 0 ) {
F_99 ( V_2 , L_32
L_33 , V_143 ) ;
}
}
V_16 -> V_159 [ V_143 ] . V_127 = V_127 ;
V_16 -> V_159 [ V_143 ] . V_213 = V_213 ;
return 0 ;
V_223:
F_147 ( V_211 , V_216 ) ;
V_222:
F_147 ( V_210 , V_215 ) ;
V_221:
F_147 ( V_209 , V_214 ) ;
V_207:
return V_7 ;
}
static int F_148 ( struct V_1 * V_2 , T_13 * V_224 ,
const char * V_225 )
{
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
int V_7 = F_149 ( V_224 , & V_16 -> V_25 , V_225 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 , L_34 ,
V_225 , V_5 , V_7 ) ;
return V_7 ;
}
if ( V_194 != 0 ) {
T_14 V_226 = V_227 ;
V_7 = F_150 ( V_224 , V_226 , 1 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 ,
L_35 ,
V_225 ) ;
F_151 ( V_224 ) ;
return V_7 ;
}
}
V_7 = F_152 ( V_224 ) ;
if ( V_7 < 0 || V_7 >= V_156 ) {
F_86 ( V_2 , L_36 , V_7 ) ;
F_151 ( V_224 ) ;
return - V_66 ;
}
return V_7 ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_176 , V_7 , V_5 ;
F_72 ( & V_228 ) ;
V_7 = F_154 ( V_2 -> V_229 ) ;
if ( V_7 < 0 || V_7 >= V_34 ) {
F_74 ( & V_228 ) ;
return - V_179 ;
}
V_4 -> V_5 = V_7 ;
V_5 = V_7 ;
if ( ! V_15 [ V_7 ] . V_25 . V_230 ) {
V_7 = F_138 ( V_2 ) ;
if ( V_7 != 0 )
goto V_207;
}
if ( F_31 ( ( V_231 != NULL ) &&
! strcmp ( V_2 -> V_229 , V_231 ) ) ) {
V_7 = F_148 ( V_2 , & V_4 -> V_224 , L_37 ) ;
if ( V_7 < 0 )
goto V_207;
V_4 -> V_100 = V_7 ;
V_7 = F_148 ( V_2 , & V_4 -> V_232 , L_38 ) ;
if ( V_7 < 0 )
goto V_207;
V_4 -> V_233 = V_7 ;
V_4 -> V_143 = V_7 ;
} else {
V_7 = F_148 ( V_2 , & V_4 -> V_224 , V_2 -> V_229 ) ;
if ( V_7 < 0 )
goto V_207;
V_4 -> V_100 = V_7 ;
V_4 -> V_143 = V_7 ;
}
V_7 = F_142 ( V_2 , V_4 -> V_143 ) ;
if ( V_7 != 0 )
goto V_207;
V_15 [ V_5 ] . V_99 [ V_4 -> V_100 ] = V_2 ;
V_7 = F_93 ( V_2 ) ;
if ( V_7 != 0 )
goto V_207;
F_74 ( & V_228 ) ;
F_101 (cpu) {
struct V_31 * V_32 = & F_63 ( V_33 , V_176 ) ;
struct V_141 * V_142 =
& V_32 -> V_35 [ V_5 ] . V_142 [ V_4 -> V_143 ] ;
F_155 ( & V_142 -> V_144 , V_234 ,
V_235 ) ;
V_142 -> V_140 = V_176 ;
V_142 -> V_144 . V_236 = F_65 ;
V_142 -> V_2 = V_2 ;
}
F_101 (cpu)
F_156 ( V_2 , V_176 ) ;
F_157 ( V_2 ) ;
return 0 ;
V_207:
if ( V_4 -> V_233 >= 0 ) {
if ( F_151 ( & V_4 -> V_232 ) != 0 )
F_99 ( V_2 , L_39 ) ;
V_4 -> V_233 = - 1 ;
}
if ( V_4 -> V_100 >= 0 ) {
if ( F_151 ( & V_4 -> V_224 ) != 0 )
F_99 ( V_2 , L_40 ) ;
V_4 -> V_100 = - 1 ;
}
V_4 -> V_143 = - 1 ;
V_15 [ V_5 ] . V_99 [ V_4 -> V_100 ] = NULL ;
F_74 ( & V_228 ) ;
return ( V_7 > - 512 ) ? V_7 : - V_179 ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_176 ;
int V_5 = V_4 -> V_5 ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
F_101 (cpu) {
struct V_31 * V_32 = & F_63 ( V_33 , V_176 ) ;
struct V_141 * V_142 =
& V_32 -> V_35 [ V_5 ] . V_142 [ V_4 -> V_143 ] ;
F_159 ( & V_142 -> V_144 ) ;
F_160 ( V_2 , V_176 ) ;
}
F_72 ( & V_228 ) ;
V_16 -> V_99 [ V_4 -> V_100 ] = NULL ;
( void ) F_93 ( V_2 ) ;
if ( V_4 -> V_233 >= 0 ) {
if ( F_151 ( & V_4 -> V_232 ) != 0 )
F_99 ( V_2 , L_39 ) ;
V_4 -> V_233 = - 1 ;
}
if ( V_4 -> V_100 >= 0 ) {
if ( F_151 ( & V_4 -> V_224 ) != 0 )
F_99 ( V_2 , L_40 ) ;
V_4 -> V_100 = - 1 ;
}
V_4 -> V_143 = - 1 ;
F_74 ( & V_228 ) ;
return 0 ;
}
static inline void * F_161 ( T_15 * V_237 )
{
unsigned long V_238 = F_120 ( F_162 ( V_237 ) ) ;
return F_119 ( V_238 ) + V_237 -> V_239 ;
}
static T_9 F_163 ( struct V_1 * V_2 ,
int V_140 ,
struct V_128 * V_129 ,
T_7 * V_127 ,
int V_240 )
{
if ( V_129 -> V_133 - V_129 -> V_132 < V_135 - 1 ||
F_59 ( V_127 , V_129 , 32 , false ) != 0 ) {
T_9 V_241 = F_164 ( V_127 , V_240 ) ;
if ( V_241 >= 0 )
return V_241 ;
F_59 ( V_127 , V_129 , V_135 , false ) ;
V_241 = F_164 ( V_127 , V_240 ) ;
if ( V_241 >= 0 )
return V_241 ;
}
F_160 ( V_2 , V_140 ) ;
F_62 ( V_2 , V_140 ) ;
return - 1 ;
}
static int F_165 ( struct V_21 * V_22 )
{
struct V_49 * V_242 = F_35 ( V_22 ) ;
unsigned int V_243 = F_166 ( V_22 ) + F_167 ( V_22 ) ;
unsigned int V_244 = V_22 -> V_23 - V_243 ;
unsigned int V_245 = V_242 -> V_246 ;
long V_247 = - 1 ;
long V_248 = F_168 ( V_22 ) - V_243 ;
long V_249 = 0 ;
long V_118 ;
int V_240 = 0 ;
int V_250 ;
for ( V_250 = 0 ; V_250 < V_242 -> V_251 ; V_250 ++ ) {
unsigned int V_252 = 0 ;
for ( V_240 ++ ; V_252 < V_245 ; V_240 ++ ) {
while ( V_249 >= V_248 ) {
V_247 ++ ;
V_248 = F_169 ( & V_242 -> V_253 [ V_247 ] ) ;
V_249 = 0 ;
}
V_118 = V_245 - V_252 ;
if ( V_118 > V_248 - V_249 )
V_118 = V_248 - V_249 ;
V_249 += V_118 ;
V_252 += V_118 ;
}
V_244 -= V_245 ;
if ( V_244 < V_245 )
V_245 = V_244 ;
}
return V_240 ;
}
static void F_170 ( struct V_21 * V_22 , unsigned char * V_213 ,
T_9 V_241 )
{
struct V_49 * V_242 = F_35 ( V_22 ) ;
struct V_254 * V_255 ;
struct V_256 * V_257 ;
struct V_258 * V_259 ;
unsigned int V_243 = F_166 ( V_22 ) + F_167 ( V_22 ) ;
unsigned int V_244 = V_22 -> V_23 - V_243 ;
unsigned char * V_24 = V_22 -> V_24 ;
unsigned int V_260 , V_261 , V_245 ;
unsigned int V_262 , V_263 , V_264 ;
unsigned int V_265 ( V_124 ) ;
int V_266 ;
long V_247 = - 1 ;
long V_248 = F_168 ( V_22 ) - V_243 ;
long V_249 = 0 ;
long V_118 ;
int V_250 ;
V_266 = F_171 ( V_22 ) ;
if ( V_266 ) {
V_257 = F_172 ( V_22 ) ;
V_260 = F_173 ( V_22 ) ;
} else {
V_255 = F_174 ( V_22 ) ;
V_260 = F_173 ( V_22 ) ;
V_262 = ( ( 0xFFFF - V_255 -> V_267 ) +
( 0xFFFF - V_255 -> V_268 ) +
( 0xFFFF - V_255 -> V_124 ) ) ;
V_124 = F_175 ( V_255 -> V_124 ) ;
}
V_259 = F_176 ( V_22 ) ;
V_261 = F_166 ( V_22 ) ;
V_245 = V_242 -> V_246 ;
V_263 = V_259 -> V_267 + ( 0xFFFF ^ F_177 ( V_22 -> V_23 ) ) ;
V_264 = F_178 ( V_259 -> V_264 ) ;
for ( V_250 = 0 ; V_250 < V_242 -> V_251 ; V_250 ++ ) {
unsigned char * V_6 ;
unsigned int V_252 = 0 ;
V_6 = V_213 + ( V_241 % V_218 ) * V_219 +
V_111 ;
memcpy ( V_6 , V_24 , V_243 ) ;
if ( V_266 ) {
V_257 = (struct V_256 * ) ( V_6 + V_260 ) ;
V_257 -> V_269 = F_177 ( V_243 + V_245 - V_260 -
sizeof( * V_257 ) ) ;
} else {
V_255 = (struct V_254 * ) ( V_6 + V_260 ) ;
V_255 -> V_268 = F_177 ( V_243 + V_245 - V_260 ) ;
V_255 -> V_124 = F_177 ( V_124 ++ ) ;
V_255 -> V_267 = F_179 ( V_262 + V_255 -> V_268 +
V_255 -> V_124 ) ^ 0xffff ;
}
V_259 = (struct V_258 * ) ( V_6 + V_261 ) ;
V_259 -> V_264 = F_180 ( V_264 ) ;
V_259 -> V_267 = F_179 ( V_263 + F_177 ( V_243 + V_245 ) ) ;
if ( V_250 != V_242 -> V_251 - 1 ) {
V_259 -> V_270 = 0 ;
V_259 -> V_271 = 0 ;
}
V_241 ++ ;
while ( V_252 < V_245 ) {
while ( V_249 >= V_248 ) {
V_247 ++ ;
V_248 = F_169 ( & V_242 -> V_253 [ V_247 ] ) ;
V_249 = 0 ;
}
V_118 = V_245 - V_252 ;
if ( V_118 > V_248 - V_249 )
V_118 = V_248 - V_249 ;
V_249 += V_118 ;
V_252 += V_118 ;
V_241 ++ ;
}
V_264 += V_245 ;
V_244 -= V_245 ;
if ( V_244 < V_245 )
V_245 = V_244 ;
}
F_17 () ;
}
static void F_181 ( struct V_1 * V_2 , T_7 * V_127 ,
struct V_21 * V_22 , unsigned char * V_213 , T_9 V_241 )
{
struct V_49 * V_242 = F_35 ( V_22 ) ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
unsigned int V_243 = F_166 ( V_22 ) + F_167 ( V_22 ) ;
unsigned int V_244 = V_22 -> V_23 - V_243 ;
unsigned int V_245 = V_242 -> V_246 ;
T_12 V_272 = { { 0 } } ;
T_12 V_273 = { { 0 } } ;
long V_247 = - 1 ;
long V_248 = F_168 ( V_22 ) - V_243 ;
long V_249 = 0 ;
void * V_274 = V_22 -> V_24 + V_243 ;
long V_118 ;
unsigned long V_275 = 0 , V_276 = 0 ;
unsigned int V_277 ;
int V_250 ;
V_277 = F_182 ( V_22 ) ;
V_272 . V_278 = 1 ;
V_272 . V_277 = V_277 ;
V_272 . V_279 = V_277 + V_22 -> V_280 ;
V_272 . V_281 = V_243 ;
V_272 . V_187 = V_16 -> V_26 ;
V_273 . V_187 = V_16 -> V_26 ;
for ( V_250 = 0 ; V_250 < V_242 -> V_251 ; V_250 ++ ) {
unsigned char * V_6 ;
unsigned int V_252 = 0 ;
V_6 = V_213 + ( V_241 % V_218 ) * V_219 +
V_111 ;
V_272 . V_27 = F_19 ( V_6 ) ;
F_183 ( V_127 , V_272 , V_241 ) ;
V_241 ++ ;
while ( V_252 < V_245 ) {
void * V_27 ;
while ( V_249 >= V_248 ) {
V_247 ++ ;
V_248 = F_169 ( & V_242 -> V_253 [ V_247 ] ) ;
V_274 = F_161 ( & V_242 -> V_253 [ V_247 ] ) ;
V_249 = 0 ;
}
V_27 = V_274 + V_249 ;
V_118 = V_245 - V_252 ;
if ( V_118 > V_248 - V_249 )
V_118 = V_248 - V_249 ;
V_249 += V_118 ;
V_252 += V_118 ;
V_273 . V_27 = F_19 ( V_27 ) ;
V_273 . V_281 = V_118 ;
V_273 . V_282 = ! ( V_252 < V_245 ) ;
F_183 ( V_127 , V_273 , V_241 ) ;
V_241 ++ ;
}
V_275 ++ ;
V_276 += V_243 + V_245 ;
V_244 -= V_245 ;
if ( V_244 < V_245 )
V_245 = V_244 ;
}
F_10 ( V_275 , & V_2 -> V_95 . V_275 ) ;
F_10 ( V_276 , & V_2 -> V_95 . V_276 ) ;
}
static int F_184 ( struct V_21 * V_22 , struct V_1 * V_2 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_100 = V_4 -> V_143 ;
int V_5 = V_4 -> V_5 ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
struct V_157 * V_158 = & V_16 -> V_159 [ V_100 ] ;
struct V_128 * V_129 =
V_32 -> V_35 [ V_5 ] . V_160 [ V_100 ] ;
T_7 * V_127 = V_158 -> V_127 ;
unsigned long V_154 ;
int V_240 ;
T_9 V_241 ;
V_240 = F_165 ( V_22 ) ;
F_69 ( V_154 ) ;
V_241 = F_163 ( V_2 , V_22 -> V_283 , V_129 ,
V_127 , V_240 ) ;
if ( V_241 < 0 ) {
F_70 ( V_154 ) ;
return V_284 ;
}
F_170 ( V_22 , V_158 -> V_213 , V_241 ) ;
F_181 ( V_2 , V_127 , V_22 , V_158 -> V_213 , V_241 ) ;
F_61 ( V_127 , V_129 , V_241 + V_240 - 1 , V_22 ) ;
F_70 ( V_154 ) ;
F_67 () ;
return V_285 ;
}
static unsigned int F_185 ( struct V_286 * V_253 ,
struct V_21 * V_22 ,
void * V_287 , unsigned int V_288 )
{
unsigned int V_117 , V_118 = 0 ;
struct V_49 * V_242 = F_35 ( V_22 ) ;
if ( V_288 != 0 ) {
V_253 [ V_118 ] . V_6 = V_287 ;
V_253 [ V_118 ++ ] . V_289 = V_288 ;
}
for ( V_117 = 0 ; V_117 < V_242 -> V_290 ; V_117 ++ ) {
T_15 * V_237 = & V_242 -> V_253 [ V_117 ] ;
V_253 [ V_118 ] . V_6 = F_161 ( V_237 ) ;
V_253 [ V_118 ++ ] . V_289 = F_169 ( V_237 ) ;
}
return V_118 ;
}
static int F_186 ( struct V_21 * V_22 , struct V_1 * V_2 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_4 -> V_5 ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
struct V_157 * V_158 =
& V_16 -> V_159 [ V_4 -> V_143 ] ;
T_7 * V_127 = V_158 -> V_127 ;
struct V_128 * V_129 =
V_32 -> V_35 [ V_5 ] . V_160 [ V_4 -> V_143 ] ;
unsigned int V_23 = V_22 -> V_23 ;
unsigned char * V_24 = V_22 -> V_24 ;
unsigned int V_240 ;
struct V_286 V_253 [ V_291 ] ;
T_12 V_212 [ V_291 ] ;
unsigned long V_154 ;
T_12 V_292 = { { 0 } } ;
unsigned int V_117 ;
T_9 V_241 ;
if ( F_187 ( V_22 ) )
return F_184 ( V_22 , V_2 ) ;
V_240 = F_185 ( V_253 , V_22 , V_24 , F_168 ( V_22 ) ) ;
V_292 . V_187 = V_16 -> V_26 ;
for ( V_117 = 0 ; V_117 < V_240 ; V_117 ++ ) {
V_292 . V_281 = V_253 [ V_117 ] . V_289 ;
V_292 . V_27 = F_19 ( V_253 [ V_117 ] . V_6 ) ;
V_212 [ V_117 ] = V_292 ;
}
V_212 [ V_240 - 1 ] . V_282 = 1 ;
if ( V_22 -> V_92 == V_293 ) {
unsigned int V_277 = F_182 ( V_22 ) ;
V_212 [ 0 ] . V_278 = 1 ;
V_212 [ 0 ] . V_277 = V_277 ;
V_212 [ 0 ] . V_279 = V_277 + V_22 -> V_280 ;
}
F_69 ( V_154 ) ;
V_241 = F_163 ( V_2 , V_22 -> V_283 , V_129 ,
V_127 , V_240 ) ;
if ( V_241 < 0 ) {
F_70 ( V_154 ) ;
return V_284 ;
}
for ( V_117 = 0 ; V_117 < V_240 ; V_117 ++ )
F_183 ( V_127 , V_212 [ V_117 ] , V_241 ++ ) ;
F_34 ( V_22 , V_5 ) ;
F_61 ( V_127 , V_129 , V_241 - 1 , V_22 ) ;
F_10 ( 1 , & V_2 -> V_95 . V_275 ) ;
F_10 ( F_188 (unsigned int, len, ETH_ZLEN) ,
& V_2 -> V_95 . V_276 ) ;
F_70 ( V_154 ) ;
F_67 () ;
return V_285 ;
}
static T_16 F_189 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
return F_190 () ;
}
static void F_191 ( struct V_1 * V_2 )
{
int V_176 ;
F_101 (cpu)
F_66 ( V_2 , V_176 ) ;
}
static int F_192 ( struct V_1 * V_2 , struct V_58 * V_59 , int V_60 )
{
if ( V_60 == V_294 )
return F_38 ( V_2 , V_59 , V_60 ) ;
return - V_85 ;
}
static int F_193 ( struct V_1 * V_2 , int V_295 )
{
if ( V_295 < 68 )
return - V_66 ;
if ( V_295 > ( ( V_194 != 0 ) ? 9000 : 1500 ) )
return - V_66 ;
V_2 -> V_296 = V_295 ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , void * V_297 )
{
struct V_298 * V_30 = V_297 ;
if ( ! F_195 ( V_30 -> V_299 ) )
return - V_66 ;
memcpy ( V_2 -> V_88 , V_30 -> V_299 , V_2 -> V_300 ) ;
return 0 ;
}
static void F_196 ( struct V_1 * V_2 )
{
int V_5 = F_1 ( V_2 ) ;
struct V_31 * V_32 = & F_27 ( V_33 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
F_92 ( V_16 -> V_180 ) ;
F_57 ( & V_32 -> V_35 [ V_5 ] . V_94 ) ;
F_90 ( V_16 -> V_180 , 0 ) ;
}
static void F_197 ( struct V_1 * V_2 )
{
T_17 V_301 = 0 ;
F_198 ( V_2 ) ;
V_2 -> V_302 = & V_303 ;
V_2 -> V_304 = V_305 ;
V_2 -> V_296 = 1500 ;
V_301 |= V_306 ;
V_301 |= V_307 ;
V_301 |= V_308 ;
V_301 |= V_309 ;
V_2 -> V_310 |= V_301 ;
V_2 -> V_311 |= V_301 ;
V_2 -> V_301 |= V_301 ;
}
static void F_199 ( const char * V_229 , const T_5 * V_312 )
{
int V_164 ;
int V_117 ;
int V_313 = 0 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
if ( strncmp ( V_229 , L_41 , 4 ) == 0 )
return;
V_2 = F_200 ( sizeof( * V_4 ) , V_229 , F_197 ,
V_314 , 1 ) ;
if ( ! V_2 ) {
F_201 ( L_42 , V_229 ) ;
return;
}
V_4 = F_2 ( V_2 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_100 = - 1 ;
V_4 -> V_233 = - 1 ;
V_4 -> V_143 = - 1 ;
F_88 ( V_4 ) ;
for ( V_117 = 0 ; V_117 < 6 ; V_117 ++ )
V_313 |= V_312 [ V_117 ] ;
if ( V_313 ) {
memcpy ( V_2 -> V_88 , V_312 , 6 ) ;
V_2 -> V_300 = 6 ;
} else {
F_202 ( V_2 ) ;
}
V_164 = F_203 ( V_2 ) ;
if ( V_164 ) {
F_86 ( V_2 , L_43 , V_164 ) ;
F_204 ( V_2 ) ;
return;
}
}
static void F_205 ( void * V_315 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
int V_39 = F_190 () ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_34 ; V_5 ++ ) {
V_32 -> V_35 [ V_5 ] . V_36 = false ;
V_32 -> V_35 [ V_5 ] . V_5 = V_5 ;
}
V_32 -> V_39 = V_39 ;
F_155 ( & V_32 -> V_152 , V_234 , V_235 ) ;
V_32 -> V_152 . V_236 = F_68 ;
}
static int T_18 F_206 ( void )
{
int V_117 ;
char V_229 [ V_316 ] ;
T_5 V_312 [ 6 ] ;
F_9 ( L_44 ) ;
F_11 ( V_34 != 2 ) ;
F_83 ( & V_228 ) ;
F_100 ( F_205 , NULL , 1 ) ;
for ( V_117 = 0 ; F_207 ( V_117 , V_229 , V_312 ) >= 0 ; V_117 ++ )
F_199 ( V_229 , V_312 ) ;
if ( ! F_3 () )
V_9 = * V_317 ;
return 0 ;
}

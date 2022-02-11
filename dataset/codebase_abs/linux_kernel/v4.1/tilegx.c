static inline int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static bool F_3 ( void )
{
int V_6 ;
if ( V_7 == NULL )
return false ;
V_6 = F_4 ( V_7 , & V_8 ) ;
if ( V_6 != 0 ) {
F_5 ( L_1 ,
V_7 ) ;
return false ;
}
F_6 ( & V_8 , & V_8 , V_9 ) ;
if ( F_7 ( & V_8 ) ) {
F_5 ( L_2 ,
V_7 ) ;
return false ;
}
F_8 ( L_3 ,
F_9 ( & V_8 ) ) ;
return true ;
}
static void F_10 ( unsigned long V_10 , unsigned long * V_11 )
{
F_11 ( sizeof( V_12 ) != sizeof( unsigned long ) ) ;
F_12 ( V_10 , ( V_12 * ) V_11 ) ;
}
static bool F_13 ( int V_5 , int V_13 )
{
struct V_14 * V_15 = & V_14 [ V_5 ] ;
T_1 V_16 = V_17 [ V_13 ] ;
T_2 V_18 = F_14 ( V_16 ) ;
const unsigned long V_19 = 128 ;
struct V_20 * V_21 ;
int V_22 ;
V_22 = sizeof( struct V_20 * * ) + V_19 + V_18 ;
V_21 = F_15 ( V_22 ) ;
if ( V_21 == NULL )
return false ;
F_16 ( V_21 , sizeof( struct V_20 * * ) ) ;
F_16 ( V_21 , - ( long ) V_21 -> V_23 & ( V_19 - 1 ) ) ;
* (struct V_20 * * ) ( V_21 -> V_23 - sizeof( struct V_20 * * ) ) = V_21 ;
F_17 () ;
F_18 ( & V_15 -> V_24 , V_15 -> V_25 + V_13 ,
( void * ) F_19 ( V_21 -> V_23 ) ) ;
return true ;
}
static struct V_20 * F_20 ( void * V_26 )
{
struct V_20 * * V_27 = V_26 - sizeof( * V_27 ) ;
struct V_20 * V_21 = * V_27 ;
if ( V_21 -> V_23 != V_26 ) {
F_21 ( L_4 ,
V_26 , V_21 , V_21 -> V_23 ) ;
}
return V_21 ;
}
static void F_22 ( int V_5 , int V_28 )
{
struct V_14 * V_15 = & V_14 [ V_5 ] ;
for (; ; ) {
T_3 V_29 =
( T_3 ) F_23 ( & V_15 -> V_24 ,
V_28 ) ;
if ( V_29 == 0 )
break;
F_24 ( F_20 ( F_25 ( V_29 ) ) ) ;
}
}
static void F_26 ( void )
{
struct V_30 * V_31 = F_27 ( & V_32 ) ;
int V_5 , V_13 ;
for ( V_5 = 0 ; V_5 < V_33 &&
V_31 -> V_34 [ V_5 ] . V_35 ; V_5 ++ ) {
for ( V_13 = 0 ; V_13 < V_36 ; V_13 ++ ) {
while ( V_31 -> V_34 [ V_5 ] . V_37 [ V_13 ]
!= 0 ) {
if ( ! F_13 ( V_5 , V_13 ) ) {
F_28 ( L_5
L_6 ,
V_31 -> V_38 ) ;
return;
}
V_31 -> V_34 [ V_5 ] .
V_37 [ V_13 ] -- ;
}
}
}
}
static void F_29 ( struct V_3 * V_4 , struct V_20 * V_21 ,
T_4 * V_39 )
{
if ( F_30 ( V_4 -> V_40 . V_41 != V_42 ) ) {
struct V_43 * V_44 = F_31 ( V_21 ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
V_44 -> V_45 = F_32 ( V_39 -> V_46 ,
V_39 -> V_47 ) ;
}
}
static void F_33 ( struct V_20 * V_21 , int V_5 )
{
struct V_48 * V_49 = F_34 ( V_21 ) ;
if ( F_30 ( ( V_49 -> V_50 & V_51 ) != 0 ) ) {
struct V_14 * V_15 = & V_14 [ V_5 ] ;
struct V_43 V_44 ;
struct V_52 V_53 ;
V_49 -> V_50 |= V_54 ;
F_35 ( & V_15 -> V_24 , & V_53 ) ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_45 = F_32 ( V_53 . V_55 , V_53 . V_56 ) ;
F_36 ( V_21 , & V_44 ) ;
}
}
static int F_37 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
struct V_59 V_60 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_38 ( & V_60 , V_58 -> V_61 , sizeof( V_60 ) ) )
return - V_62 ;
if ( V_60 . V_63 )
return - V_64 ;
switch ( V_60 . V_65 ) {
case V_66 :
case V_67 :
break;
default:
return - V_68 ;
}
switch ( V_60 . V_41 ) {
case V_42 :
break;
case V_69 :
case V_70 :
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
V_60 . V_41 = V_69 ;
break;
default:
return - V_68 ;
}
if ( F_39 ( V_58 -> V_61 , & V_60 , sizeof( V_60 ) ) )
return - V_62 ;
V_4 -> V_40 = V_60 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_39 ( V_58 -> V_61 , & V_4 -> V_40 ,
sizeof( V_4 -> V_40 ) ) )
return - V_62 ;
return 0 ;
}
static inline bool F_41 ( struct V_1 * V_2 , void * V_83 )
{
if ( V_2 == NULL || ! ( V_2 -> V_63 & V_84 ) )
return true ;
if ( ! ( V_2 -> V_63 & V_85 ) &&
! F_42 ( V_83 ) &&
! F_43 ( V_2 -> V_86 , V_83 ) )
return true ;
return false ;
}
static void F_44 ( struct V_1 * V_2 , struct V_20 * V_21 ,
T_4 * V_39 , unsigned long V_22 )
{
struct V_30 * V_31 = F_27 ( & V_32 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_4 -> V_5 ;
F_45 ( V_21 , V_22 ) ;
V_21 -> V_87 = F_46 ( V_21 , V_2 ) ;
if ( V_39 -> V_88 && V_39 -> V_89 == 0xFFFF )
V_21 -> V_90 = V_91 ;
F_29 ( V_4 , V_21 , V_39 ) ;
F_47 ( & V_31 -> V_34 [ V_5 ] . V_92 , V_21 ) ;
F_10 ( 1 , & V_2 -> V_93 . V_94 ) ;
F_10 ( V_22 , & V_2 -> V_93 . V_95 ) ;
if ( V_39 -> V_96 == V_17 [ 0 ] )
V_31 -> V_34 [ V_5 ] . V_37 [ 0 ] ++ ;
else if ( V_39 -> V_96 == V_17 [ 1 ] )
V_31 -> V_34 [ V_5 ] . V_37 [ 1 ] ++ ;
else
V_31 -> V_34 [ V_5 ] . V_37 [ 2 ] ++ ;
}
static bool F_48 ( int V_5 , T_4 * V_39 )
{
struct V_30 * V_31 = F_27 ( & V_32 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
struct V_1 * V_2 = V_15 -> V_97 [ V_39 -> V_98 ] ;
T_5 V_99 ;
void * V_26 ;
void * V_83 ;
unsigned long V_22 ;
bool V_100 ;
if ( V_39 -> V_101 || V_39 -> V_102 || V_39 -> V_103 || V_39 -> V_104 ) {
if ( V_2 )
F_10 ( 1 , & V_2 -> V_93 . V_105 ) ;
goto V_106;
}
V_99 = V_107 ? 0 : F_49 ( V_39 ) ;
V_26 = F_25 ( ( unsigned long ) V_39 -> V_26 ) ;
V_83 = V_26 + V_99 ;
V_22 = V_39 -> V_108 - V_99 ;
V_26 -= V_109 ;
V_100 = F_41 ( V_2 , V_83 ) ;
if ( V_100 ) {
if ( V_2 )
F_10 ( 1 , & V_2 -> V_93 . V_110 ) ;
V_106:
F_50 ( & V_31 -> V_34 [ V_5 ] . V_111 , V_39 ) ;
} else {
struct V_20 * V_21 = F_20 ( V_26 ) ;
F_16 ( V_21 , V_109 + V_99 ) ;
F_44 ( V_2 , V_21 , V_39 , V_22 ) ;
}
F_51 ( & V_31 -> V_34 [ V_5 ] . V_111 , V_39 ) ;
return ! V_100 ;
}
static int F_52 ( struct V_112 * V_92 , int V_113 )
{
struct V_30 * V_31 = F_27 ( & V_32 ) ;
unsigned int V_114 = 0 ;
T_4 * V_39 ;
int V_5 , V_115 , V_116 ;
struct V_14 * V_15 ;
struct V_117 * V_117 =
F_53 ( V_92 , struct V_117 , V_92 ) ;
if ( V_113 <= 0 )
goto V_118;
V_5 = V_117 -> V_5 ;
while ( ( V_116 = F_54 (
& V_117 -> V_111 ,
& V_39 ) ) > 0 ) {
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
if ( V_115 == V_119 )
goto V_118;
if ( F_48 ( V_5 ,
V_39 + V_115 ) ) {
if ( ++ V_114 >= V_113 )
goto V_118;
}
}
}
F_55 ( & V_117 -> V_92 ) ;
V_15 = & V_14 [ V_5 ] ;
F_56 (
& V_15 -> V_24 , V_31 -> V_34 [ V_5 ] . V_111 . V_120 ) ;
if ( F_54 ( & V_117 -> V_111 , & V_39 ) > 0 )
F_57 ( & V_117 -> V_92 ) ;
V_118:
F_26 () ;
return V_114 ;
}
static T_6 F_58 ( int V_121 , void * V_122 )
{
struct V_30 * V_31 = F_27 ( & V_32 ) ;
F_57 ( & V_31 -> V_34 [ ( V_123 ) V_122 ] . V_92 ) ;
return V_124 ;
}
static int F_59 ( T_7 * V_125 ,
struct V_126 * V_127 ,
int V_128 , bool V_129 )
{
int V_116 = 0 ;
while ( V_127 -> V_130 < V_127 -> V_131 ) {
unsigned int V_132 = V_127 -> V_130 % V_133 ;
struct V_134 * V_135 = & V_127 -> V_136 [ V_132 ] ;
if ( ! F_60 ( V_125 , V_135 -> V_137 ,
V_129 || V_116 == 0 ) )
break;
F_24 ( V_135 -> V_21 ) ;
V_127 -> V_130 ++ ;
if ( ++ V_116 == V_128 )
break;
}
return V_116 ;
}
static void F_61 ( T_7 * V_125 ,
struct V_126 * V_127 ,
V_123 V_137 , struct V_20 * V_21 )
{
int V_132 = V_127 -> V_131 % V_133 ;
V_127 -> V_136 [ V_132 ] . V_137 = V_137 ;
V_127 -> V_136 [ V_132 ] . V_21 = V_21 ;
V_127 -> V_131 ++ ;
}
static void F_62 ( struct V_1 * V_2 ,
int V_138 )
{
struct V_30 * V_31 = & F_63 ( V_32 , V_138 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_4 -> V_5 ;
struct V_139 * V_140 =
& V_31 -> V_34 [ V_5 ] . V_140 [ V_4 -> V_141 ] ;
F_64 ( & V_140 -> V_142 ,
F_32 ( 0 , V_143 * 1000UL ) ,
V_144 ) ;
}
static enum V_145 F_65 ( struct V_146 * V_147 )
{
struct V_139 * V_140 =
F_53 ( V_147 , struct V_139 , V_142 ) ;
F_66 ( V_140 -> V_2 , V_140 -> V_138 ) ;
return V_148 ;
}
static void F_67 ( void )
{
struct V_30 * V_31 = F_27 ( & V_32 ) ;
if ( ! V_31 -> V_149 ) {
F_64 ( & V_31 -> V_150 ,
F_32 ( 0 , V_151 * 1000UL ) ,
V_144 ) ;
V_31 -> V_149 = true ;
}
}
static enum V_145 F_68 ( struct V_146 * V_147 )
{
struct V_30 * V_31 = F_27 ( & V_32 ) ;
unsigned long V_152 ;
bool V_153 = false ;
int V_115 , V_5 ;
F_69 ( V_152 ) ;
V_31 -> V_149 = false ;
for ( V_5 = 0 ; V_5 < V_33 &&
V_31 -> V_34 [ V_5 ] . V_35 ; V_5 ++ ) {
for ( V_115 = 0 ; V_115 < V_154 ; V_115 ++ ) {
struct V_155 * V_156 =
& V_14 [ V_5 ] . V_157 [ V_115 ] ;
struct V_126 * V_127 =
V_31 -> V_34 [ V_5 ] . V_158 [ V_115 ] ;
if ( ! V_156 || V_127 -> V_130 >= V_127 -> V_131 )
continue;
F_59 ( V_156 -> V_125 , V_127 , - 1 , true ) ;
V_153 = V_153 ||
( V_127 -> V_130 < V_127 -> V_131 ) ;
}
}
if ( V_153 )
F_67 () ;
F_70 ( V_152 ) ;
return V_148 ;
}
static int F_71 ( struct V_159 * V_160 , T_8 V_161 )
{
int V_162 = 0 ;
struct V_14 * V_15 = F_53 ( V_160 , struct V_14 , V_163 ) ;
F_72 ( & V_15 -> V_164 ) ;
if ( F_73 ( & V_15 -> V_24 , V_161 ) )
V_162 = - V_64 ;
F_74 ( & V_15 -> V_164 ) ;
return V_162 ;
}
static int F_75 ( struct V_159 * V_160 , T_9 V_165 )
{
int V_162 = 0 ;
struct V_14 * V_15 = F_53 ( V_160 , struct V_14 , V_163 ) ;
F_72 ( & V_15 -> V_164 ) ;
if ( F_76 ( & V_15 -> V_24 , V_165 ) )
V_162 = - V_166 ;
F_74 ( & V_15 -> V_164 ) ;
return V_162 ;
}
static int F_77 ( struct V_159 * V_160 ,
struct V_167 * V_53 )
{
int V_162 = 0 ;
struct V_14 * V_15 = F_53 ( V_160 , struct V_14 , V_163 ) ;
F_72 ( & V_15 -> V_164 ) ;
if ( F_35 ( & V_15 -> V_24 , V_53 ) )
V_162 = - V_166 ;
F_74 ( & V_15 -> V_164 ) ;
return V_162 ;
}
static int F_78 ( struct V_159 * V_160 ,
const struct V_167 * V_53 )
{
int V_162 = 0 ;
struct V_14 * V_15 = F_53 ( V_160 , struct V_14 , V_163 ) ;
F_72 ( & V_15 -> V_164 ) ;
if ( F_79 ( & V_15 -> V_24 , V_53 ) )
V_162 = - V_166 ;
F_74 ( & V_15 -> V_164 ) ;
return V_162 ;
}
static int F_80 ( struct V_159 * V_160 ,
struct V_168 * V_169 , int V_170 )
{
return - V_171 ;
}
static void F_81 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_52 V_53 ;
F_82 ( & V_53 ) ;
F_79 ( & V_15 -> V_24 , & V_53 ) ;
F_83 ( & V_15 -> V_164 ) ;
V_15 -> V_163 = V_172 ;
V_15 -> V_173 = F_84 ( & V_15 -> V_163 , NULL ) ;
if ( F_85 ( V_15 -> V_173 ) )
F_86 ( V_2 , L_7 ,
F_87 ( V_15 -> V_173 ) ) ;
}
static void F_88 ( struct V_3 * V_4 )
{
V_4 -> V_40 . V_41 = V_42 ;
V_4 -> V_40 . V_65 = V_66 ;
}
static void F_89 ( void * V_121 )
{
F_90 ( ( long ) V_121 , 0 ) ;
}
static void F_91 ( void * V_121 )
{
F_92 ( ( long ) V_121 ) ;
}
static int F_93 ( struct V_1 * V_2 )
{
static T_10 V_174 ;
bool V_175 = false ;
int V_5 = F_1 ( V_2 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
int V_98 ;
int V_6 ;
int V_176 ;
V_175 = false ;
F_94 ( & V_174 , & V_15 -> V_24 ) ;
for ( V_98 = 0 ; V_98 < V_154 ; V_98 ++ ) {
if ( V_15 -> V_97 [ V_98 ] == NULL )
continue;
if ( ! V_175 ) {
V_175 = true ;
F_95 ( & V_174 , V_15 -> V_177 ,
V_15 -> V_178 , NULL ) ;
F_96 ( & V_174 , V_109 ) ;
}
F_97 ( & V_174 , V_98 ) ;
}
V_6 = F_98 ( & V_174 ) ;
if ( V_6 != 0 ) {
F_99 ( V_2 , L_8 ,
V_5 , V_6 ) ;
return - V_179 ;
}
if ( ! V_175 )
F_100 ( F_91 ,
( void * ) ( long ) ( V_15 -> V_180 ) , 1 ) ;
F_101 (cpu) {
struct V_30 * V_31 = & F_63 ( V_32 , V_176 ) ;
if ( ! V_31 -> V_34 [ V_5 ] . V_35 )
continue;
if ( V_175 ) {
if ( ! V_31 -> V_34 [ V_5 ] . V_181 ) {
F_102 ( V_2 , & V_31 -> V_34 [ V_5 ] . V_92 ,
F_52 , V_182 ) ;
V_31 -> V_34 [ V_5 ] . V_181 = true ;
}
if ( ! V_31 -> V_34 [ V_5 ] . V_183 ) {
F_103 ( & V_31 -> V_34 [ V_5 ] . V_92 ) ;
V_31 -> V_34 [ V_5 ] . V_183 = true ;
}
} else {
if ( V_31 -> V_34 [ V_5 ] . V_183 ) {
F_104 ( & V_31 -> V_34 [ V_5 ] . V_92 ) ;
V_31 -> V_34 [ V_5 ] . V_183 = false ;
}
}
}
if ( V_175 )
F_100 ( F_89 ,
( void * ) ( long ) ( V_15 -> V_180 ) , 1 ) ;
if ( V_175 )
F_105 ( V_5 , - 1 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
int V_13 , T_2 V_184 )
{
T_11 V_185 = F_107 ((pte_t) { 0 }, PAGE_HOME_HASH) ;
int V_5 = F_1 ( V_2 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
T_2 V_186 = F_108 ( V_184 ) ;
int V_187 = V_15 -> V_25 + V_13 ;
void * V_26 ;
int V_115 , V_6 ;
V_15 -> V_188 [ V_13 ] =
F_109 ( V_186 , 64 * 1024 ) ;
V_26 = F_110 ( V_15 -> V_188 [ V_13 ] , V_189 ) ;
if ( V_26 == NULL ) {
F_86 ( V_2 ,
L_9 ,
V_15 -> V_188 [ V_13 ] , V_13 ) ;
return - V_190 ;
}
V_6 = F_111 ( & V_15 -> V_24 , V_187 ,
V_17 [ V_13 ] , V_26 ,
V_15 -> V_188 [ V_13 ] , 0 ) ;
if ( V_6 != 0 ) {
F_86 ( V_2 , L_10 ,
V_5 , V_6 ) ;
F_112 ( V_26 , V_15 -> V_188 [ V_13 ] ) ;
return V_6 ;
}
V_15 -> V_191 [ V_13 ] = V_26 ;
V_6 = F_113 ( & V_15 -> V_24 , V_187 ,
V_185 , 0 ) ;
if ( V_6 != 0 ) {
F_86 ( V_2 ,
L_11 ,
V_5 , V_6 ) ;
return V_6 ;
}
for ( V_115 = 0 ; V_115 < V_184 ; V_115 ++ ) {
if ( ! F_13 ( V_5 , V_13 ) ) {
F_86 ( V_2 , L_12 ) ;
return - V_190 ;
}
}
return 0 ;
}
static int F_114 ( struct V_1 * V_2 ,
int V_192 )
{
int V_193 = V_36 - ( V_194 == 0 ) ;
T_2 V_184 ;
int V_6 ;
int V_5 = F_1 ( V_2 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
V_6 = F_115 ( & V_15 -> V_24 , V_193 , 0 , 0 ) ;
if ( V_6 < 0 ) {
F_86 ( V_2 ,
L_13 ,
V_5 , V_6 ) ;
return V_6 ;
}
V_15 -> V_25 = V_6 ;
V_184 =
V_192 * ( V_195 + V_119 ) ;
if ( V_6 >= 0 )
V_6 = F_106 ( V_2 , 0 , V_184 ) ;
if ( V_6 >= 0 )
V_6 = F_106 ( V_2 , 1 , V_184 ) ;
if ( V_6 >= 0 && V_194 != 0 )
V_6 = F_106 ( V_2 , 2 , V_194 ) ;
return V_6 ;
}
static int F_116 ( struct V_1 * V_2 ,
int V_176 , int V_120 )
{
struct V_30 * V_31 = & F_63 ( V_32 , V_176 ) ;
int V_196 , V_115 , V_6 ;
int V_5 = F_1 ( V_2 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
struct V_197 * V_197 ;
void * V_29 ;
V_196 = F_117 ( V_198 ) ;
V_197 = F_118 ( V_189 , V_196 , V_176 ) ;
if ( V_197 == NULL ) {
F_86 ( V_2 , L_14 ,
V_198 ) ;
return - V_190 ;
}
V_29 = F_119 ( F_120 ( V_197 ) ) ;
memset ( V_29 , 0 , V_198 ) ;
for ( V_115 = 0 ; V_115 < V_154 ; V_115 ++ )
V_31 -> V_34 [ V_5 ] . V_158 [ V_115 ] =
V_29 + V_115 * sizeof( struct V_126 ) ;
if ( F_121 ( V_176 , & V_8 ) ) {
V_196 = F_117 ( V_199 ) ;
V_197 = F_118 ( V_189 , V_196 , V_176 ) ;
if ( V_197 == NULL ) {
F_86 ( V_2 ,
L_15 ,
V_199 ) ;
return - V_190 ;
}
V_29 = F_119 ( F_120 ( V_197 ) ) ;
V_6 = F_122 ( & V_31 -> V_34 [ V_5 ] . V_111 ,
& V_15 -> V_24 , V_120 ++ , V_29 ,
V_199 , 0 ) ;
if ( V_6 < 0 ) {
F_86 ( V_2 ,
L_16 , V_6 ) ;
return V_6 ;
}
V_31 -> V_34 [ V_5 ] . V_35 = true ;
}
return V_120 ;
}
static int F_123 ( struct V_1 * V_2 ,
int V_120 , int V_192 )
{
int V_200 , V_6 ;
int V_5 = F_1 ( V_2 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
V_6 = F_124 ( & V_15 -> V_24 , 1 , 0 , 0 ) ;
if ( V_6 < 0 ) {
F_86 ( V_2 , L_17 ,
V_5 , V_6 ) ;
return V_6 ;
}
V_200 = V_6 ;
if ( V_192 > 4 )
V_15 -> V_178 = 256 ;
else if ( V_192 > 1 )
V_15 -> V_178 = 16 ;
V_6 = F_125 ( & V_15 -> V_24 , V_15 -> V_178 , 0 , 0 ) ;
if ( V_6 < 0 ) {
F_86 ( V_2 , L_18 ,
V_5 , V_6 ) ;
return V_6 ;
}
V_15 -> V_177 = V_6 ;
V_6 = F_126 (
& V_15 -> V_24 , V_200 , V_120 , V_192 ,
V_15 -> V_177 , V_15 -> V_178 ,
V_201 ) ;
if ( V_6 != 0 ) {
F_86 ( V_2 , L_19
L_20 , V_5 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_176 , V_6 , V_121 ;
int V_5 = F_1 ( V_2 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
V_121 = V_15 -> V_180 ;
if ( V_121 < 0 ) {
V_121 = F_128 ( - 1 ) ;
if ( ! V_121 ) {
F_86 ( V_2 ,
L_21 ,
V_5 , V_121 ) ;
return V_121 ;
}
F_129 ( V_121 , V_202 ) ;
V_6 = F_130 ( V_121 , F_58 ,
0 , L_22 , ( void * ) ( ( V_123 ) V_5 ) ) ;
if ( V_6 != 0 ) {
F_86 ( V_2 , L_23 ,
V_5 , V_6 ) ;
F_131 ( V_121 ) ;
return V_6 ;
}
V_15 -> V_180 = V_121 ;
}
F_101 (cpu) {
struct V_30 * V_31 = & F_63 ( V_32 , V_176 ) ;
if ( V_31 -> V_34 [ V_5 ] . V_35 ) {
F_132 ( & V_15 -> V_24 ,
F_133 ( V_176 ) , F_134 ( V_176 ) , V_203 , V_121 ,
V_31 -> V_34 [ V_5 ] . V_111 . V_120 ) ;
}
}
return 0 ;
}
static void F_135 ( int V_5 )
{
int V_13 , V_176 ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
for ( V_13 = 0 ; V_13 < V_36 ; V_13 ++ ) {
if ( V_15 -> V_191 [ V_13 ] != NULL ) {
F_22 ( V_5 ,
V_15 -> V_25 +
V_13 ) ;
}
}
F_136 ( & V_15 -> V_24 ) ;
F_101 (cpu) {
struct V_30 * V_31 = & F_63 ( V_32 , V_176 ) ;
F_137 (
( unsigned long ) (
V_31 -> V_34 [ V_5 ] . V_158 [ 0 ] ) ,
F_117 ( V_198 ) ) ;
V_31 -> V_34 [ V_5 ] . V_158 [ 0 ] = NULL ;
F_137 ( ( unsigned long ) ( V_31 -> V_34 [ V_5 ] . V_111 . V_204 ) ,
F_117 ( V_199 ) ) ;
V_31 -> V_34 [ V_5 ] . V_111 . V_204 = NULL ;
}
for ( V_13 = 0 ; V_13 < V_36 ; V_13 ++ ) {
if ( V_15 -> V_191 [ V_13 ] != NULL ) {
F_112 ( V_15 -> V_191 [ V_13 ] ,
V_15 -> V_188 [ V_13 ] ) ;
V_15 -> V_191 [ V_13 ] = NULL ;
}
}
V_15 -> V_25 = - 1 ;
V_15 -> V_177 = - 1 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_6 ;
int V_176 ;
int V_205 , V_120 ;
int V_5 = F_1 ( V_2 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
int V_192 = F_139 ( & V_8 ) ;
if ( ! V_206 ) {
F_86 ( V_2 , L_24 ) ;
return - V_179 ;
}
V_6 = F_140 ( & V_15 -> V_24 , V_5 ) ;
if ( V_6 != 0 ) {
F_86 ( V_2 , L_25 ,
V_5 , V_6 ) ;
return - V_179 ;
}
V_6 = F_114 ( V_2 , V_192 ) ;
if ( V_6 != 0 )
goto V_207;
V_6 = F_141 ( & V_15 -> V_24 ,
V_192 , 0 , 0 ) ;
if ( V_6 < 0 ) {
F_86 ( V_2 , L_26 ,
V_6 ) ;
goto V_207;
}
V_205 = V_6 ;
V_120 = V_205 ;
F_101 (cpu) {
V_6 = F_116 ( V_2 , V_176 , V_120 ) ;
if ( V_6 < 0 )
goto V_207;
V_120 = V_6 ;
}
V_6 = F_123 ( V_2 , V_205 , V_192 ) ;
if ( V_6 != 0 )
goto V_207;
V_6 = F_127 ( V_2 ) ;
if ( V_6 != 0 )
goto V_207;
F_81 ( V_2 , V_15 ) ;
return 0 ;
V_207:
F_135 ( V_5 ) ;
return V_6 ;
}
static int F_142 ( struct V_1 * V_2 , int V_141 )
{
static int V_208 = - 1 ;
struct V_197 * V_209 , * V_210 , * V_211 ;
T_12 * V_212 ;
T_7 * V_125 ;
unsigned char * V_213 ;
int V_214 , V_215 , V_216 ;
T_2 V_217 ;
int V_6 = - V_190 ;
int V_5 = F_1 ( V_2 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
if ( V_15 -> V_157 [ V_141 ] . V_125 != NULL )
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
V_216 = F_117 ( sizeof( * V_125 ) ) ;
V_211 = F_143 ( V_189 , V_216 ) ;
if ( V_211 == NULL ) {
F_99 ( V_2 ,
L_29 ,
V_220 << V_216 ) ;
goto V_222;
}
V_125 = F_119 ( F_120 ( V_211 ) ) ;
if ( V_208 < 0 ) {
V_6 = F_144 ( & V_15 -> V_24 , 1 , 0 , 0 ) ;
if ( V_6 < 0 ) {
F_99 ( V_2 , L_30
L_20 , V_5 , V_6 ) ;
goto V_223;
}
V_208 = V_6 ;
}
V_6 = F_145 ( V_125 , & V_15 -> V_24 , V_208 , V_141 ,
V_212 , V_217 , 0 ) ;
if ( V_6 != 0 ) {
F_86 ( V_2 , L_31 ,
V_5 , V_6 ) ;
goto V_223;
}
V_208 = - 1 ;
if ( V_194 != 0 ) {
if ( F_146 ( V_125 , 10368 ) < 0 ) {
F_99 ( V_2 , L_32
L_33 , V_141 ) ;
}
}
V_15 -> V_157 [ V_141 ] . V_125 = V_125 ;
V_15 -> V_157 [ V_141 ] . V_213 = V_213 ;
return 0 ;
V_223:
F_147 ( V_211 , V_216 ) ;
V_222:
F_147 ( V_210 , V_215 ) ;
V_221:
F_147 ( V_209 , V_214 ) ;
V_207:
return V_6 ;
}
static int F_148 ( struct V_1 * V_2 , T_13 * V_224 ,
const char * V_225 )
{
int V_5 = F_1 ( V_2 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
int V_6 = F_149 ( V_224 , & V_15 -> V_24 , V_225 , 0 ) ;
if ( V_6 < 0 ) {
F_86 ( V_2 , L_34 ,
V_225 , V_5 , V_6 ) ;
return V_6 ;
}
if ( V_194 != 0 ) {
T_14 V_226 = V_227 ;
V_6 = F_150 ( V_224 , V_226 , 1 ) ;
if ( V_6 != 0 ) {
F_86 ( V_2 ,
L_35 ,
V_225 ) ;
F_151 ( V_224 ) ;
return V_6 ;
}
}
V_6 = F_152 ( V_224 ) ;
if ( V_6 < 0 || V_6 >= V_154 ) {
F_86 ( V_2 , L_36 , V_6 ) ;
F_151 ( V_224 ) ;
return - V_64 ;
}
return V_6 ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_176 , V_6 , V_5 ;
F_72 ( & V_228 ) ;
V_6 = F_154 ( V_2 -> V_229 ) ;
if ( V_6 < 0 || V_6 >= V_33 ) {
F_74 ( & V_228 ) ;
return - V_179 ;
}
V_4 -> V_5 = V_6 ;
V_5 = V_6 ;
if ( ! V_14 [ V_6 ] . V_24 . V_230 ) {
V_6 = F_138 ( V_2 ) ;
if ( V_6 != 0 )
goto V_207;
}
if ( F_30 ( ( V_231 != NULL ) &&
! strcmp ( V_2 -> V_229 , V_231 ) ) ) {
V_6 = F_148 ( V_2 , & V_4 -> V_224 , L_37 ) ;
if ( V_6 < 0 )
goto V_207;
V_4 -> V_98 = V_6 ;
V_6 = F_148 ( V_2 , & V_4 -> V_232 , L_38 ) ;
if ( V_6 < 0 )
goto V_207;
V_4 -> V_233 = V_6 ;
V_4 -> V_141 = V_6 ;
} else {
V_6 = F_148 ( V_2 , & V_4 -> V_224 , V_2 -> V_229 ) ;
if ( V_6 < 0 )
goto V_207;
V_4 -> V_98 = V_6 ;
V_4 -> V_141 = V_6 ;
}
V_6 = F_142 ( V_2 , V_4 -> V_141 ) ;
if ( V_6 != 0 )
goto V_207;
V_14 [ V_5 ] . V_97 [ V_4 -> V_98 ] = V_2 ;
V_6 = F_93 ( V_2 ) ;
if ( V_6 != 0 )
goto V_207;
F_74 ( & V_228 ) ;
F_101 (cpu) {
struct V_30 * V_31 = & F_63 ( V_32 , V_176 ) ;
struct V_139 * V_140 =
& V_31 -> V_34 [ V_5 ] . V_140 [ V_4 -> V_141 ] ;
F_155 ( & V_140 -> V_142 , V_234 ,
V_235 ) ;
V_140 -> V_138 = V_176 ;
V_140 -> V_142 . V_236 = F_65 ;
V_140 -> V_2 = V_2 ;
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
if ( V_4 -> V_98 >= 0 ) {
if ( F_151 ( & V_4 -> V_224 ) != 0 )
F_99 ( V_2 , L_40 ) ;
V_4 -> V_98 = - 1 ;
}
V_4 -> V_141 = - 1 ;
V_14 [ V_5 ] . V_97 [ V_4 -> V_98 ] = NULL ;
F_74 ( & V_228 ) ;
return ( V_6 > - 512 ) ? V_6 : - V_179 ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_176 ;
int V_5 = V_4 -> V_5 ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
F_101 (cpu) {
struct V_30 * V_31 = & F_63 ( V_32 , V_176 ) ;
struct V_139 * V_140 =
& V_31 -> V_34 [ V_5 ] . V_140 [ V_4 -> V_141 ] ;
F_159 ( & V_140 -> V_142 ) ;
F_160 ( V_2 , V_176 ) ;
}
F_72 ( & V_228 ) ;
V_15 -> V_97 [ V_4 -> V_98 ] = NULL ;
( void ) F_93 ( V_2 ) ;
if ( V_4 -> V_233 >= 0 ) {
if ( F_151 ( & V_4 -> V_232 ) != 0 )
F_99 ( V_2 , L_39 ) ;
V_4 -> V_233 = - 1 ;
}
if ( V_4 -> V_98 >= 0 ) {
if ( F_151 ( & V_4 -> V_224 ) != 0 )
F_99 ( V_2 , L_40 ) ;
V_4 -> V_98 = - 1 ;
}
V_4 -> V_141 = - 1 ;
F_74 ( & V_228 ) ;
return 0 ;
}
static inline void * F_161 ( T_15 * V_237 )
{
unsigned long V_238 = F_120 ( F_162 ( V_237 ) ) ;
return F_119 ( V_238 ) + V_237 -> V_239 ;
}
static T_9 F_163 ( struct V_1 * V_2 ,
int V_138 ,
struct V_126 * V_127 ,
T_7 * V_125 ,
int V_240 )
{
if ( V_127 -> V_131 - V_127 -> V_130 < V_133 - 1 ||
F_59 ( V_125 , V_127 , 32 , false ) != 0 ) {
T_9 V_241 = F_164 ( V_125 , V_240 ) ;
if ( V_241 >= 0 )
return V_241 ;
F_59 ( V_125 , V_127 , V_133 , false ) ;
V_241 = F_164 ( V_125 , V_240 ) ;
if ( V_241 >= 0 )
return V_241 ;
}
F_160 ( V_2 , V_138 ) ;
F_62 ( V_2 , V_138 ) ;
return - 1 ;
}
static int F_165 ( struct V_20 * V_21 )
{
struct V_48 * V_242 = F_34 ( V_21 ) ;
unsigned int V_243 = F_166 ( V_21 ) + F_167 ( V_21 ) ;
unsigned int V_244 = V_21 -> V_22 - V_243 ;
unsigned int V_245 = V_242 -> V_246 ;
long V_247 = - 1 ;
long V_248 = F_168 ( V_21 ) - V_243 ;
long V_249 = 0 ;
long V_116 ;
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
V_116 = V_245 - V_252 ;
if ( V_116 > V_248 - V_249 )
V_116 = V_248 - V_249 ;
V_249 += V_116 ;
V_252 += V_116 ;
}
V_244 -= V_245 ;
if ( V_244 < V_245 )
V_245 = V_244 ;
}
return V_240 ;
}
static void F_170 ( struct V_20 * V_21 , unsigned char * V_213 ,
T_9 V_241 )
{
struct V_48 * V_242 = F_34 ( V_21 ) ;
struct V_254 * V_255 ;
struct V_256 * V_257 ;
struct V_258 * V_259 ;
unsigned int V_243 = F_166 ( V_21 ) + F_167 ( V_21 ) ;
unsigned int V_244 = V_21 -> V_22 - V_243 ;
unsigned char * V_23 = V_21 -> V_23 ;
unsigned int V_260 , V_261 , V_245 ;
unsigned int V_262 , V_263 , V_264 ;
unsigned int V_265 ( V_122 ) ;
int V_266 ;
long V_247 = - 1 ;
long V_248 = F_168 ( V_21 ) - V_243 ;
long V_249 = 0 ;
long V_116 ;
int V_250 ;
V_266 = F_171 ( V_21 ) ;
if ( V_266 ) {
V_257 = F_172 ( V_21 ) ;
V_260 = F_173 ( V_21 ) ;
} else {
V_255 = F_174 ( V_21 ) ;
V_260 = F_173 ( V_21 ) ;
V_262 = ( ( 0xFFFF - V_255 -> V_267 ) +
( 0xFFFF - V_255 -> V_268 ) +
( 0xFFFF - V_255 -> V_122 ) ) ;
V_122 = F_175 ( V_255 -> V_122 ) ;
}
V_259 = F_176 ( V_21 ) ;
V_261 = F_166 ( V_21 ) ;
V_245 = V_242 -> V_246 ;
V_263 = V_259 -> V_267 + ( 0xFFFF ^ F_177 ( V_21 -> V_22 ) ) ;
V_264 = F_178 ( V_259 -> V_264 ) ;
for ( V_250 = 0 ; V_250 < V_242 -> V_251 ; V_250 ++ ) {
unsigned char * V_83 ;
unsigned int V_252 = 0 ;
V_83 = V_213 + ( V_241 % V_218 ) * V_219 +
V_109 ;
memcpy ( V_83 , V_23 , V_243 ) ;
if ( V_266 ) {
V_257 = (struct V_256 * ) ( V_83 + V_260 ) ;
V_257 -> V_269 = F_177 ( V_243 + V_245 - V_260 -
sizeof( * V_257 ) ) ;
} else {
V_255 = (struct V_254 * ) ( V_83 + V_260 ) ;
V_255 -> V_268 = F_177 ( V_243 + V_245 - V_260 ) ;
V_255 -> V_122 = F_177 ( V_122 ++ ) ;
V_255 -> V_267 = F_179 ( V_262 + V_255 -> V_268 +
V_255 -> V_122 ) ^ 0xffff ;
}
V_259 = (struct V_258 * ) ( V_83 + V_261 ) ;
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
V_116 = V_245 - V_252 ;
if ( V_116 > V_248 - V_249 )
V_116 = V_248 - V_249 ;
V_249 += V_116 ;
V_252 += V_116 ;
V_241 ++ ;
}
V_264 += V_245 ;
V_244 -= V_245 ;
if ( V_244 < V_245 )
V_245 = V_244 ;
}
F_17 () ;
}
static void F_181 ( struct V_1 * V_2 , T_7 * V_125 ,
struct V_20 * V_21 , unsigned char * V_213 , T_9 V_241 )
{
struct V_48 * V_242 = F_34 ( V_21 ) ;
int V_5 = F_1 ( V_2 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
unsigned int V_243 = F_166 ( V_21 ) + F_167 ( V_21 ) ;
unsigned int V_244 = V_21 -> V_22 - V_243 ;
unsigned int V_245 = V_242 -> V_246 ;
T_12 V_272 = { { 0 } } ;
T_12 V_273 = { { 0 } } ;
long V_247 = - 1 ;
long V_248 = F_168 ( V_21 ) - V_243 ;
long V_249 = 0 ;
void * V_274 = V_21 -> V_23 + V_243 ;
long V_116 ;
unsigned long V_275 = 0 , V_276 = 0 ;
unsigned int V_277 ;
int V_250 ;
V_277 = F_182 ( V_21 ) ;
V_272 . V_278 = 1 ;
V_272 . V_277 = V_277 ;
V_272 . V_279 = V_277 + V_21 -> V_280 ;
V_272 . V_281 = V_243 ;
V_272 . V_187 = V_15 -> V_25 ;
V_273 . V_187 = V_15 -> V_25 ;
for ( V_250 = 0 ; V_250 < V_242 -> V_251 ; V_250 ++ ) {
unsigned char * V_83 ;
unsigned int V_252 = 0 ;
V_83 = V_213 + ( V_241 % V_218 ) * V_219 +
V_109 ;
V_272 . V_26 = F_19 ( V_83 ) ;
F_183 ( V_125 , V_272 , V_241 ) ;
V_241 ++ ;
while ( V_252 < V_245 ) {
void * V_26 ;
while ( V_249 >= V_248 ) {
V_247 ++ ;
V_248 = F_169 ( & V_242 -> V_253 [ V_247 ] ) ;
V_274 = F_161 ( & V_242 -> V_253 [ V_247 ] ) ;
V_249 = 0 ;
}
V_26 = V_274 + V_249 ;
V_116 = V_245 - V_252 ;
if ( V_116 > V_248 - V_249 )
V_116 = V_248 - V_249 ;
V_249 += V_116 ;
V_252 += V_116 ;
V_273 . V_26 = F_19 ( V_26 ) ;
V_273 . V_281 = V_116 ;
V_273 . V_282 = ! ( V_252 < V_245 ) ;
F_183 ( V_125 , V_273 , V_241 ) ;
V_241 ++ ;
}
V_275 ++ ;
V_276 += V_243 + V_245 ;
V_244 -= V_245 ;
if ( V_244 < V_245 )
V_245 = V_244 ;
}
F_10 ( V_275 , & V_2 -> V_93 . V_275 ) ;
F_10 ( V_276 , & V_2 -> V_93 . V_276 ) ;
}
static int F_184 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_27 ( & V_32 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_98 = V_4 -> V_141 ;
int V_5 = V_4 -> V_5 ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
struct V_155 * V_156 = & V_15 -> V_157 [ V_98 ] ;
struct V_126 * V_127 =
V_31 -> V_34 [ V_5 ] . V_158 [ V_98 ] ;
T_7 * V_125 = V_156 -> V_125 ;
unsigned long V_152 ;
int V_240 ;
T_9 V_241 ;
V_240 = F_165 ( V_21 ) ;
F_69 ( V_152 ) ;
V_241 = F_163 ( V_2 , V_21 -> V_283 , V_127 ,
V_125 , V_240 ) ;
if ( V_241 < 0 ) {
F_70 ( V_152 ) ;
return V_284 ;
}
F_170 ( V_21 , V_156 -> V_213 , V_241 ) ;
F_181 ( V_2 , V_125 , V_21 , V_156 -> V_213 , V_241 ) ;
F_61 ( V_125 , V_127 , V_241 + V_240 - 1 , V_21 ) ;
F_70 ( V_152 ) ;
F_67 () ;
return V_285 ;
}
static unsigned int F_185 ( struct V_286 * V_253 ,
struct V_20 * V_21 ,
void * V_287 , unsigned int V_288 )
{
unsigned int V_115 , V_116 = 0 ;
struct V_48 * V_242 = F_34 ( V_21 ) ;
if ( V_288 != 0 ) {
V_253 [ V_116 ] . V_83 = V_287 ;
V_253 [ V_116 ++ ] . V_289 = V_288 ;
}
for ( V_115 = 0 ; V_115 < V_242 -> V_290 ; V_115 ++ ) {
T_15 * V_237 = & V_242 -> V_253 [ V_115 ] ;
V_253 [ V_116 ] . V_83 = F_161 ( V_237 ) ;
V_253 [ V_116 ++ ] . V_289 = F_169 ( V_237 ) ;
}
return V_116 ;
}
static int F_186 ( struct V_20 * V_21 , struct V_1 * V_2 )
{
struct V_30 * V_31 = F_27 ( & V_32 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_4 -> V_5 ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
struct V_155 * V_156 =
& V_15 -> V_157 [ V_4 -> V_141 ] ;
T_7 * V_125 = V_156 -> V_125 ;
struct V_126 * V_127 =
V_31 -> V_34 [ V_5 ] . V_158 [ V_4 -> V_141 ] ;
unsigned int V_22 = V_21 -> V_22 ;
unsigned char * V_23 = V_21 -> V_23 ;
unsigned int V_240 ;
struct V_286 V_253 [ V_291 ] ;
T_12 V_212 [ V_291 ] ;
unsigned long V_152 ;
T_12 V_292 = { { 0 } } ;
unsigned int V_115 ;
T_9 V_241 ;
if ( F_187 ( V_21 ) )
return F_184 ( V_21 , V_2 ) ;
V_240 = F_185 ( V_253 , V_21 , V_23 , F_168 ( V_21 ) ) ;
V_292 . V_187 = V_15 -> V_25 ;
for ( V_115 = 0 ; V_115 < V_240 ; V_115 ++ ) {
V_292 . V_281 = V_253 [ V_115 ] . V_289 ;
V_292 . V_26 = F_19 ( V_253 [ V_115 ] . V_83 ) ;
V_212 [ V_115 ] = V_292 ;
}
V_212 [ V_240 - 1 ] . V_282 = 1 ;
if ( V_21 -> V_90 == V_293 ) {
unsigned int V_277 = F_182 ( V_21 ) ;
V_212 [ 0 ] . V_278 = 1 ;
V_212 [ 0 ] . V_277 = V_277 ;
V_212 [ 0 ] . V_279 = V_277 + V_21 -> V_280 ;
}
F_69 ( V_152 ) ;
V_241 = F_163 ( V_2 , V_21 -> V_283 , V_127 ,
V_125 , V_240 ) ;
if ( V_241 < 0 ) {
F_70 ( V_152 ) ;
return V_284 ;
}
for ( V_115 = 0 ; V_115 < V_240 ; V_115 ++ )
F_183 ( V_125 , V_212 [ V_115 ] , V_241 ++ ) ;
F_33 ( V_21 , V_5 ) ;
F_61 ( V_125 , V_127 , V_241 - 1 , V_21 ) ;
F_10 ( 1 , & V_2 -> V_93 . V_275 ) ;
F_10 ( F_188 (unsigned int, len, ETH_ZLEN) ,
& V_2 -> V_93 . V_276 ) ;
F_70 ( V_152 ) ;
F_67 () ;
return V_285 ;
}
static T_16 F_189 ( struct V_1 * V_2 , struct V_20 * V_21 ,
void * V_294 , T_17 V_295 )
{
return F_190 () ;
}
static void F_191 ( struct V_1 * V_2 )
{
int V_176 ;
F_101 (cpu)
F_66 ( V_2 , V_176 ) ;
}
static int F_192 ( struct V_1 * V_2 , struct V_57 * V_58 , int V_296 )
{
if ( V_296 == V_297 )
return F_37 ( V_2 , V_58 ) ;
if ( V_296 == V_298 )
return F_40 ( V_2 , V_58 ) ;
return - V_171 ;
}
static int F_193 ( struct V_1 * V_2 , int V_299 )
{
if ( V_299 < 68 )
return - V_64 ;
if ( V_299 > ( ( V_194 != 0 ) ? 9000 : 1500 ) )
return - V_64 ;
V_2 -> V_300 = V_299 ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , void * V_301 )
{
struct V_302 * V_29 = V_301 ;
if ( ! F_195 ( V_29 -> V_303 ) )
return - V_64 ;
memcpy ( V_2 -> V_86 , V_29 -> V_303 , V_2 -> V_304 ) ;
return 0 ;
}
static void F_196 ( struct V_1 * V_2 )
{
int V_5 = F_1 ( V_2 ) ;
struct V_30 * V_31 = F_27 ( & V_32 ) ;
struct V_14 * V_15 = & V_14 [ V_5 ] ;
F_92 ( V_15 -> V_180 ) ;
F_57 ( & V_31 -> V_34 [ V_5 ] . V_92 ) ;
F_90 ( V_15 -> V_180 , 0 ) ;
}
static void F_197 ( struct V_1 * V_2 )
{
T_18 V_305 = 0 ;
F_198 ( V_2 ) ;
V_2 -> V_306 = & V_307 ;
V_2 -> V_308 = V_309 ;
V_2 -> V_300 = 1500 ;
V_305 |= V_310 ;
V_305 |= V_311 ;
V_305 |= V_312 ;
V_305 |= V_313 ;
V_2 -> V_314 |= V_305 ;
V_2 -> V_315 |= V_305 ;
V_2 -> V_305 |= V_305 ;
}
static void F_199 ( const char * V_229 , const T_5 * V_316 )
{
int V_162 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
if ( strncmp ( V_229 , L_41 , 4 ) == 0 )
return;
V_2 = F_200 ( sizeof( * V_4 ) , V_229 , V_317 ,
F_197 , V_318 , 1 ) ;
if ( ! V_2 ) {
F_201 ( L_42 , V_229 ) ;
return;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_98 = - 1 ;
V_4 -> V_233 = - 1 ;
V_4 -> V_141 = - 1 ;
F_88 ( V_4 ) ;
if ( ! F_202 ( V_316 ) )
F_203 ( V_2 -> V_86 , V_316 ) ;
else
F_204 ( V_2 ) ;
V_162 = F_205 ( V_2 ) ;
if ( V_162 ) {
F_86 ( V_2 , L_43 , V_162 ) ;
F_206 ( V_2 ) ;
return;
}
}
static void F_207 ( void * V_319 )
{
struct V_30 * V_31 = F_27 ( & V_32 ) ;
int V_38 = F_190 () ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_33 ; V_5 ++ ) {
V_31 -> V_34 [ V_5 ] . V_35 = false ;
V_31 -> V_34 [ V_5 ] . V_5 = V_5 ;
}
V_31 -> V_38 = V_38 ;
F_155 ( & V_31 -> V_150 , V_234 , V_235 ) ;
V_31 -> V_150 . V_236 = F_68 ;
}
static int T_19 F_208 ( void )
{
int V_115 ;
char V_229 [ V_320 ] ;
T_5 V_316 [ 6 ] ;
F_8 ( L_44 ) ;
F_11 ( V_33 != 2 ) ;
F_83 ( & V_228 ) ;
F_100 ( F_207 , NULL , 1 ) ;
for ( V_115 = 0 ; F_209 ( V_115 , V_229 , V_316 ) >= 0 ; V_115 ++ )
F_199 ( V_229 , V_316 ) ;
if ( ! F_3 () )
V_8 = * V_321 ;
return 0 ;
}

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
if ( F_30 ( V_4 -> V_41 . V_42 != V_43 ) ) {
struct V_44 * V_45 = F_31 ( V_22 ) ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_46 = F_32 ( V_40 -> V_47 ,
V_40 -> V_48 ) ;
}
}
static void F_33 ( struct V_21 * V_22 , int V_5 )
{
struct V_49 * V_50 = F_34 ( V_22 ) ;
if ( F_30 ( ( V_50 -> V_51 & V_52 ) != 0 ) ) {
struct V_15 * V_16 = & V_15 [ V_5 ] ;
struct V_44 V_45 ;
struct V_53 V_54 ;
V_50 -> V_51 |= V_55 ;
F_35 ( & V_16 -> V_25 , & V_54 ) ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_46 = F_32 ( V_54 . V_56 , V_54 . V_57 ) ;
F_36 ( V_22 , & V_45 ) ;
}
}
static int F_37 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
struct V_60 V_61 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_38 ( & V_61 , V_59 -> V_62 , sizeof( V_61 ) ) )
return - V_63 ;
if ( V_61 . V_64 )
return - V_65 ;
switch ( V_61 . V_66 ) {
case V_67 :
case V_68 :
break;
default:
return - V_69 ;
}
switch ( V_61 . V_42 ) {
case V_43 :
break;
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
case V_83 :
V_61 . V_42 = V_70 ;
break;
default:
return - V_69 ;
}
if ( F_39 ( V_59 -> V_62 , & V_61 , sizeof( V_61 ) ) )
return - V_63 ;
V_4 -> V_41 = V_61 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_39 ( V_59 -> V_62 , & V_4 -> V_41 ,
sizeof( V_4 -> V_41 ) ) )
return - V_63 ;
return 0 ;
}
static inline bool F_41 ( struct V_1 * V_2 , void * V_6 )
{
if ( V_2 == NULL || ! ( V_2 -> V_64 & V_84 ) )
return true ;
if ( ! ( V_2 -> V_64 & V_85 ) &&
! F_42 ( V_6 ) &&
! F_43 ( V_2 -> V_86 , V_6 ) )
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
V_22 -> V_87 = F_46 ( V_22 , V_2 ) ;
if ( V_40 -> V_88 && V_40 -> V_89 == 0xFFFF )
V_22 -> V_90 = V_91 ;
F_29 ( V_4 , V_22 , V_40 ) ;
F_47 ( & V_32 -> V_35 [ V_5 ] . V_92 , V_22 ) ;
F_10 ( 1 , & V_2 -> V_93 . V_94 ) ;
F_10 ( V_23 , & V_2 -> V_93 . V_95 ) ;
if ( V_40 -> V_96 == V_18 [ 0 ] )
V_32 -> V_35 [ V_5 ] . V_38 [ 0 ] ++ ;
else if ( V_40 -> V_96 == V_18 [ 1 ] )
V_32 -> V_35 [ V_5 ] . V_38 [ 1 ] ++ ;
else
V_32 -> V_35 [ V_5 ] . V_38 [ 2 ] ++ ;
}
static bool F_48 ( int V_5 , T_4 * V_40 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
struct V_1 * V_2 = V_16 -> V_97 [ V_40 -> V_98 ] ;
T_5 V_99 ;
void * V_27 ;
void * V_6 ;
unsigned long V_23 ;
bool V_100 ;
if ( V_40 -> V_101 || V_40 -> V_102 || V_40 -> V_103 || V_40 -> V_104 ) {
if ( V_2 )
F_10 ( 1 , & V_2 -> V_93 . V_105 ) ;
goto V_106;
}
V_99 = V_107 ? 0 : F_49 ( V_40 ) ;
V_27 = F_25 ( ( unsigned long ) V_40 -> V_27 ) ;
V_6 = V_27 + V_99 ;
V_23 = V_40 -> V_108 - V_99 ;
V_27 -= V_109 ;
V_100 = F_41 ( V_2 , V_6 ) ;
if ( V_100 ) {
if ( V_2 )
F_10 ( 1 , & V_2 -> V_93 . V_110 ) ;
V_106:
F_50 ( & V_32 -> V_35 [ V_5 ] . V_111 , V_40 ) ;
} else {
struct V_21 * V_22 = F_20 ( V_27 ) ;
F_16 ( V_22 , V_109 + V_99 ) ;
F_44 ( V_2 , V_22 , V_40 , V_23 ) ;
}
F_51 ( & V_32 -> V_35 [ V_5 ] . V_111 , V_40 ) ;
return ! V_100 ;
}
static int F_52 ( struct V_112 * V_92 , int V_113 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
unsigned int V_114 = 0 ;
T_4 * V_40 ;
int V_5 , V_115 , V_116 ;
struct V_15 * V_16 ;
struct V_117 * V_117 =
F_53 ( V_92 , struct V_117 , V_92 ) ;
if ( V_113 <= 0 )
goto V_118;
V_5 = V_117 -> V_5 ;
while ( ( V_116 = F_54 (
& V_117 -> V_111 ,
& V_40 ) ) > 0 ) {
for ( V_115 = 0 ; V_115 < V_116 ; V_115 ++ ) {
if ( V_115 == V_119 )
goto V_118;
if ( F_48 ( V_5 ,
V_40 + V_115 ) ) {
if ( ++ V_114 >= V_113 )
goto V_118;
}
}
}
F_55 ( & V_117 -> V_92 ) ;
V_16 = & V_15 [ V_5 ] ;
F_56 (
& V_16 -> V_25 , V_32 -> V_35 [ V_5 ] . V_111 . V_120 ) ;
if ( F_54 ( & V_117 -> V_111 , & V_40 ) > 0 )
F_57 ( & V_117 -> V_92 ) ;
V_118:
F_26 () ;
return V_114 ;
}
static T_6 F_58 ( int V_121 , void * V_122 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
F_57 ( & V_32 -> V_35 [ ( V_123 ) V_122 ] . V_92 ) ;
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
F_24 ( V_135 -> V_22 ) ;
V_127 -> V_130 ++ ;
if ( ++ V_116 == V_128 )
break;
}
return V_116 ;
}
static void F_61 ( T_7 * V_125 ,
struct V_126 * V_127 ,
V_123 V_137 , struct V_21 * V_22 )
{
int V_132 = V_127 -> V_131 % V_133 ;
V_127 -> V_136 [ V_132 ] . V_137 = V_137 ;
V_127 -> V_136 [ V_132 ] . V_22 = V_22 ;
V_127 -> V_131 ++ ;
}
static void F_62 ( struct V_1 * V_2 ,
int V_138 )
{
struct V_31 * V_32 = & F_63 ( V_33 , V_138 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_4 -> V_5 ;
struct V_139 * V_140 =
& V_32 -> V_35 [ V_5 ] . V_140 [ V_4 -> V_141 ] ;
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
struct V_31 * V_32 = & F_27 ( V_33 ) ;
if ( ! V_32 -> V_149 ) {
F_64 ( & V_32 -> V_150 ,
F_32 ( 0 , V_151 * 1000UL ) ,
V_144 ) ;
V_32 -> V_149 = true ;
}
}
static enum V_145 F_68 ( struct V_146 * V_147 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
unsigned long V_152 ;
bool V_153 = false ;
int V_115 , V_5 ;
F_69 ( V_152 ) ;
V_32 -> V_149 = false ;
for ( V_5 = 0 ; V_5 < V_34 &&
V_32 -> V_35 [ V_5 ] . V_36 ; V_5 ++ ) {
for ( V_115 = 0 ; V_115 < V_154 ; V_115 ++ ) {
struct V_155 * V_156 =
& V_15 [ V_5 ] . V_157 [ V_115 ] ;
struct V_126 * V_127 =
V_32 -> V_35 [ V_5 ] . V_158 [ V_115 ] ;
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
struct V_15 * V_16 = F_53 ( V_160 , struct V_15 , V_163 ) ;
F_72 ( & V_16 -> V_164 ) ;
if ( F_73 ( & V_16 -> V_25 , V_161 ) )
V_162 = - V_65 ;
F_74 ( & V_16 -> V_164 ) ;
return V_162 ;
}
static int F_75 ( struct V_159 * V_160 , T_9 V_165 )
{
int V_162 = 0 ;
struct V_15 * V_16 = F_53 ( V_160 , struct V_15 , V_163 ) ;
F_72 ( & V_16 -> V_164 ) ;
if ( F_76 ( & V_16 -> V_25 , V_165 ) )
V_162 = - V_166 ;
F_74 ( & V_16 -> V_164 ) ;
return V_162 ;
}
static int F_77 ( struct V_159 * V_160 , struct V_53 * V_54 )
{
int V_162 = 0 ;
struct V_15 * V_16 = F_53 ( V_160 , struct V_15 , V_163 ) ;
F_72 ( & V_16 -> V_164 ) ;
if ( F_35 ( & V_16 -> V_25 , V_54 ) )
V_162 = - V_166 ;
F_74 ( & V_16 -> V_164 ) ;
return V_162 ;
}
static int F_78 ( struct V_159 * V_160 ,
const struct V_53 * V_54 )
{
int V_162 = 0 ;
struct V_15 * V_16 = F_53 ( V_160 , struct V_15 , V_163 ) ;
F_72 ( & V_16 -> V_164 ) ;
if ( F_79 ( & V_16 -> V_25 , V_54 ) )
V_162 = - V_166 ;
F_74 ( & V_16 -> V_164 ) ;
return V_162 ;
}
static int F_80 ( struct V_159 * V_160 ,
struct V_167 * V_168 , int V_169 )
{
return - V_170 ;
}
static void F_81 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_53 V_54 ;
F_82 ( & V_54 ) ;
F_79 ( & V_16 -> V_25 , & V_54 ) ;
F_83 ( & V_16 -> V_164 ) ;
V_16 -> V_163 = V_171 ;
V_16 -> V_172 = F_84 ( & V_16 -> V_163 , NULL ) ;
if ( F_85 ( V_16 -> V_172 ) )
F_86 ( V_2 , L_7 ,
F_87 ( V_16 -> V_172 ) ) ;
}
static void F_88 ( struct V_3 * V_4 )
{
V_4 -> V_41 . V_42 = V_43 ;
V_4 -> V_41 . V_66 = V_67 ;
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
static T_10 V_173 ;
bool V_174 = false ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
int V_98 ;
int V_7 ;
int V_175 ;
V_174 = false ;
F_94 ( & V_173 , & V_16 -> V_25 ) ;
for ( V_98 = 0 ; V_98 < V_154 ; V_98 ++ ) {
if ( V_16 -> V_97 [ V_98 ] == NULL )
continue;
if ( ! V_174 ) {
V_174 = true ;
F_95 ( & V_173 , V_16 -> V_176 ,
V_16 -> V_177 , NULL ) ;
F_96 ( & V_173 , V_109 ) ;
}
F_97 ( & V_173 , V_98 ) ;
}
V_7 = F_98 ( & V_173 ) ;
if ( V_7 != 0 ) {
F_99 ( V_2 , L_8 ,
V_5 , V_7 ) ;
return - V_178 ;
}
if ( ! V_174 )
F_100 ( F_91 ,
( void * ) ( long ) ( V_16 -> V_179 ) , 1 ) ;
F_101 (cpu) {
struct V_31 * V_32 = & F_63 ( V_33 , V_175 ) ;
if ( ! V_32 -> V_35 [ V_5 ] . V_36 )
continue;
if ( V_174 ) {
if ( ! V_32 -> V_35 [ V_5 ] . V_180 ) {
F_102 ( V_2 , & V_32 -> V_35 [ V_5 ] . V_92 ,
F_52 , V_181 ) ;
V_32 -> V_35 [ V_5 ] . V_180 = true ;
}
if ( ! V_32 -> V_35 [ V_5 ] . V_182 ) {
F_103 ( & V_32 -> V_35 [ V_5 ] . V_92 ) ;
V_32 -> V_35 [ V_5 ] . V_182 = true ;
}
} else {
if ( V_32 -> V_35 [ V_5 ] . V_182 ) {
F_104 ( & V_32 -> V_35 [ V_5 ] . V_92 ) ;
V_32 -> V_35 [ V_5 ] . V_182 = false ;
}
}
}
if ( V_174 )
F_100 ( F_89 ,
( void * ) ( long ) ( V_16 -> V_179 ) , 1 ) ;
if ( V_174 )
F_105 ( V_5 , - 1 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 ,
int V_14 , T_2 V_183 )
{
T_11 V_184 = F_107 ((pte_t) { 0 }, PAGE_HOME_HASH) ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
T_2 V_185 = F_108 ( V_183 ) ;
int V_186 = V_16 -> V_26 + V_14 ;
void * V_27 ;
int V_115 , V_7 ;
V_16 -> V_187 [ V_14 ] =
F_109 ( V_185 , 64 * 1024 ) ;
V_27 = F_110 ( V_16 -> V_187 [ V_14 ] , V_188 ) ;
if ( V_27 == NULL ) {
F_86 ( V_2 ,
L_9 ,
V_16 -> V_187 [ V_14 ] , V_14 ) ;
return - V_189 ;
}
V_7 = F_111 ( & V_16 -> V_25 , V_186 ,
V_18 [ V_14 ] , V_27 ,
V_16 -> V_187 [ V_14 ] , 0 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 , L_10 ,
V_5 , V_7 ) ;
F_112 ( V_27 , V_16 -> V_187 [ V_14 ] ) ;
return V_7 ;
}
V_16 -> V_190 [ V_14 ] = V_27 ;
V_7 = F_113 ( & V_16 -> V_25 , V_186 ,
V_184 , 0 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 ,
L_11 ,
V_5 , V_7 ) ;
return V_7 ;
}
for ( V_115 = 0 ; V_115 < V_183 ; V_115 ++ ) {
if ( ! F_13 ( V_5 , V_14 ) ) {
F_86 ( V_2 , L_12 ) ;
return - V_189 ;
}
}
return 0 ;
}
static int F_114 ( struct V_1 * V_2 ,
int V_191 )
{
int V_192 = V_37 - ( V_193 == 0 ) ;
T_2 V_183 ;
int V_7 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
V_7 = F_115 ( & V_16 -> V_25 , V_192 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 ,
L_13 ,
V_5 , V_7 ) ;
return V_7 ;
}
V_16 -> V_26 = V_7 ;
V_183 =
V_191 * ( V_194 + V_119 ) ;
if ( V_7 >= 0 )
V_7 = F_106 ( V_2 , 0 , V_183 ) ;
if ( V_7 >= 0 )
V_7 = F_106 ( V_2 , 1 , V_183 ) ;
if ( V_7 >= 0 && V_193 != 0 )
V_7 = F_106 ( V_2 , 2 , V_193 ) ;
return V_7 ;
}
static int F_116 ( struct V_1 * V_2 ,
int V_175 , int V_120 )
{
struct V_31 * V_32 = & F_63 ( V_33 , V_175 ) ;
int V_195 , V_115 , V_7 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
struct V_196 * V_196 ;
void * V_30 ;
V_195 = F_117 ( V_197 ) ;
V_196 = F_118 ( V_188 , V_195 , V_175 ) ;
if ( V_196 == NULL ) {
F_86 ( V_2 , L_14 ,
V_197 ) ;
return - V_189 ;
}
V_30 = F_119 ( F_120 ( V_196 ) ) ;
memset ( V_30 , 0 , V_197 ) ;
for ( V_115 = 0 ; V_115 < V_154 ; V_115 ++ )
V_32 -> V_35 [ V_5 ] . V_158 [ V_115 ] =
V_30 + V_115 * sizeof( struct V_126 ) ;
if ( F_121 ( V_175 , V_9 ) ) {
V_195 = F_117 ( V_198 ) ;
V_196 = F_118 ( V_188 , V_195 , V_175 ) ;
if ( V_196 == NULL ) {
F_86 ( V_2 ,
L_15 ,
V_198 ) ;
return - V_189 ;
}
V_30 = F_119 ( F_120 ( V_196 ) ) ;
V_7 = F_122 ( & V_32 -> V_35 [ V_5 ] . V_111 ,
& V_16 -> V_25 , V_120 ++ , V_30 ,
V_198 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 ,
L_16 , V_7 ) ;
return V_7 ;
}
V_32 -> V_35 [ V_5 ] . V_36 = true ;
}
return V_120 ;
}
static int F_123 ( struct V_1 * V_2 ,
int V_120 , int V_191 )
{
int V_199 , V_7 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
V_7 = F_124 ( & V_16 -> V_25 , 1 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 , L_17 ,
V_5 , V_7 ) ;
return V_7 ;
}
V_199 = V_7 ;
if ( V_191 > 4 )
V_16 -> V_177 = 256 ;
else if ( V_191 > 1 )
V_16 -> V_177 = 16 ;
V_7 = F_125 ( & V_16 -> V_25 , V_16 -> V_177 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 , L_18 ,
V_5 , V_7 ) ;
return V_7 ;
}
V_16 -> V_176 = V_7 ;
V_7 = F_126 (
& V_16 -> V_25 , V_199 , V_120 , V_191 ,
V_16 -> V_176 , V_16 -> V_177 ,
V_200 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 , L_19
L_20 , V_5 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_175 , V_7 , V_121 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
V_121 = V_16 -> V_179 ;
if ( V_121 < 0 ) {
V_121 = F_128 ( - 1 ) ;
if ( ! V_121 ) {
F_86 ( V_2 ,
L_21 ,
V_5 , V_121 ) ;
return V_121 ;
}
F_129 ( V_121 , V_201 ) ;
V_7 = F_130 ( V_121 , F_58 ,
0 , L_22 , ( void * ) ( ( V_123 ) V_5 ) ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 , L_23 ,
V_5 , V_7 ) ;
F_131 ( V_121 ) ;
return V_7 ;
}
V_16 -> V_179 = V_121 ;
}
F_101 (cpu) {
struct V_31 * V_32 = & F_63 ( V_33 , V_175 ) ;
if ( V_32 -> V_35 [ V_5 ] . V_36 ) {
F_132 ( & V_16 -> V_25 ,
F_133 ( V_175 ) , F_134 ( V_175 ) , V_202 , V_121 ,
V_32 -> V_35 [ V_5 ] . V_111 . V_120 ) ;
}
}
return 0 ;
}
static void F_135 ( int V_5 )
{
int V_14 , V_175 ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
for ( V_14 = 0 ; V_14 < V_37 ; V_14 ++ ) {
if ( V_16 -> V_190 [ V_14 ] != NULL ) {
F_22 ( V_5 ,
V_16 -> V_26 +
V_14 ) ;
}
}
F_136 ( & V_16 -> V_25 ) ;
F_101 (cpu) {
struct V_31 * V_32 = & F_63 ( V_33 , V_175 ) ;
F_137 (
( unsigned long ) (
V_32 -> V_35 [ V_5 ] . V_158 [ 0 ] ) ,
F_117 ( V_197 ) ) ;
V_32 -> V_35 [ V_5 ] . V_158 [ 0 ] = NULL ;
F_137 ( ( unsigned long ) ( V_32 -> V_35 [ V_5 ] . V_111 . V_203 ) ,
F_117 ( V_198 ) ) ;
V_32 -> V_35 [ V_5 ] . V_111 . V_203 = NULL ;
}
for ( V_14 = 0 ; V_14 < V_37 ; V_14 ++ ) {
if ( V_16 -> V_190 [ V_14 ] != NULL ) {
F_112 ( V_16 -> V_190 [ V_14 ] ,
V_16 -> V_187 [ V_14 ] ) ;
V_16 -> V_190 [ V_14 ] = NULL ;
}
}
V_16 -> V_26 = - 1 ;
V_16 -> V_176 = - 1 ;
}
static int F_138 ( struct V_1 * V_2 )
{
int V_7 ;
int V_175 ;
int V_204 , V_120 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
int V_191 = F_139 ( V_9 ) ;
if ( ! V_205 ) {
F_86 ( V_2 , L_24 ) ;
return - V_178 ;
}
V_7 = F_140 ( & V_16 -> V_25 , V_5 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 , L_25 ,
V_5 , V_7 ) ;
return - V_178 ;
}
V_7 = F_114 ( V_2 , V_191 ) ;
if ( V_7 != 0 )
goto V_206;
V_7 = F_141 ( & V_16 -> V_25 ,
V_191 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 , L_26 ,
V_7 ) ;
goto V_206;
}
V_204 = V_7 ;
V_120 = V_204 ;
F_101 (cpu) {
V_7 = F_116 ( V_2 , V_175 , V_120 ) ;
if ( V_7 < 0 )
goto V_206;
V_120 = V_7 ;
}
V_7 = F_123 ( V_2 , V_204 , V_191 ) ;
if ( V_7 != 0 )
goto V_206;
V_7 = F_127 ( V_2 ) ;
if ( V_7 != 0 )
goto V_206;
F_81 ( V_2 , V_16 ) ;
return 0 ;
V_206:
F_135 ( V_5 ) ;
return V_7 ;
}
static int F_142 ( struct V_1 * V_2 , int V_141 )
{
static int V_207 = - 1 ;
struct V_196 * V_208 , * V_209 , * V_210 ;
T_12 * V_211 ;
T_7 * V_125 ;
unsigned char * V_212 ;
int V_213 , V_214 , V_215 ;
T_2 V_216 ;
int V_7 = - V_189 ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
if ( V_16 -> V_157 [ V_141 ] . V_125 != NULL )
return 0 ;
V_213 = F_117 ( V_217 * V_218 ) ;
V_208 = F_143 ( V_188 , V_213 ) ;
if ( V_208 == NULL ) {
F_99 ( V_2 ,
L_27 ,
V_219 << V_213 ) ;
goto V_206;
}
V_212 = F_119 ( F_120 ( V_208 ) ) ;
V_216 = V_217 * sizeof( * V_211 ) ;
V_214 = F_117 ( V_216 ) ;
V_209 = F_143 ( V_188 , V_214 ) ;
if ( V_209 == NULL ) {
F_99 ( V_2 ,
L_28 ,
V_216 ) ;
goto V_220;
}
V_211 = F_119 ( F_120 ( V_209 ) ) ;
V_215 = F_117 ( sizeof( * V_125 ) ) ;
V_210 = F_143 ( V_188 , V_215 ) ;
if ( V_210 == NULL ) {
F_99 ( V_2 ,
L_29 ,
V_219 << V_215 ) ;
goto V_221;
}
V_125 = F_119 ( F_120 ( V_210 ) ) ;
if ( V_207 < 0 ) {
V_7 = F_144 ( & V_16 -> V_25 , 1 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_99 ( V_2 , L_30
L_20 , V_5 , V_7 ) ;
goto V_222;
}
V_207 = V_7 ;
}
V_7 = F_145 ( V_125 , & V_16 -> V_25 , V_207 , V_141 ,
V_211 , V_216 , 0 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 , L_31 ,
V_5 , V_7 ) ;
goto V_222;
}
V_207 = - 1 ;
if ( V_193 != 0 ) {
if ( F_146 ( V_125 , 10368 ) < 0 ) {
F_99 ( V_2 , L_32
L_33 , V_141 ) ;
}
}
V_16 -> V_157 [ V_141 ] . V_125 = V_125 ;
V_16 -> V_157 [ V_141 ] . V_212 = V_212 ;
return 0 ;
V_222:
F_147 ( V_210 , V_215 ) ;
V_221:
F_147 ( V_209 , V_214 ) ;
V_220:
F_147 ( V_208 , V_213 ) ;
V_206:
return V_7 ;
}
static int F_148 ( struct V_1 * V_2 , T_13 * V_223 ,
const char * V_224 )
{
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
int V_7 = F_149 ( V_223 , & V_16 -> V_25 , V_224 , 0 ) ;
if ( V_7 < 0 ) {
F_86 ( V_2 , L_34 ,
V_224 , V_5 , V_7 ) ;
return V_7 ;
}
if ( V_193 != 0 ) {
T_14 V_225 = V_226 ;
V_7 = F_150 ( V_223 , V_225 , 1 ) ;
if ( V_7 != 0 ) {
F_86 ( V_2 ,
L_35 ,
V_224 ) ;
F_151 ( V_223 ) ;
return V_7 ;
}
}
V_7 = F_152 ( V_223 ) ;
if ( V_7 < 0 || V_7 >= V_154 ) {
F_86 ( V_2 , L_36 , V_7 ) ;
F_151 ( V_223 ) ;
return - V_65 ;
}
return V_7 ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_175 , V_7 , V_5 ;
F_72 ( & V_227 ) ;
V_7 = F_154 ( V_2 -> V_228 ) ;
if ( V_7 < 0 || V_7 >= V_34 ) {
F_74 ( & V_227 ) ;
return - V_178 ;
}
V_4 -> V_5 = V_7 ;
V_5 = V_7 ;
if ( ! V_15 [ V_7 ] . V_25 . V_229 ) {
V_7 = F_138 ( V_2 ) ;
if ( V_7 != 0 )
goto V_206;
}
if ( F_30 ( ( V_230 != NULL ) &&
! strcmp ( V_2 -> V_228 , V_230 ) ) ) {
V_7 = F_148 ( V_2 , & V_4 -> V_223 , L_37 ) ;
if ( V_7 < 0 )
goto V_206;
V_4 -> V_98 = V_7 ;
V_7 = F_148 ( V_2 , & V_4 -> V_231 , L_38 ) ;
if ( V_7 < 0 )
goto V_206;
V_4 -> V_232 = V_7 ;
V_4 -> V_141 = V_7 ;
} else {
V_7 = F_148 ( V_2 , & V_4 -> V_223 , V_2 -> V_228 ) ;
if ( V_7 < 0 )
goto V_206;
V_4 -> V_98 = V_7 ;
V_4 -> V_141 = V_7 ;
}
V_7 = F_142 ( V_2 , V_4 -> V_141 ) ;
if ( V_7 != 0 )
goto V_206;
V_15 [ V_5 ] . V_97 [ V_4 -> V_98 ] = V_2 ;
V_7 = F_93 ( V_2 ) ;
if ( V_7 != 0 )
goto V_206;
F_74 ( & V_227 ) ;
F_101 (cpu) {
struct V_31 * V_32 = & F_63 ( V_33 , V_175 ) ;
struct V_139 * V_140 =
& V_32 -> V_35 [ V_5 ] . V_140 [ V_4 -> V_141 ] ;
F_155 ( & V_140 -> V_142 , V_233 ,
V_234 ) ;
V_140 -> V_138 = V_175 ;
V_140 -> V_142 . V_235 = F_65 ;
V_140 -> V_2 = V_2 ;
}
F_101 (cpu)
F_156 ( V_2 , V_175 ) ;
F_157 ( V_2 ) ;
return 0 ;
V_206:
if ( V_4 -> V_232 >= 0 ) {
if ( F_151 ( & V_4 -> V_231 ) != 0 )
F_99 ( V_2 , L_39 ) ;
V_4 -> V_232 = - 1 ;
}
if ( V_4 -> V_98 >= 0 ) {
if ( F_151 ( & V_4 -> V_223 ) != 0 )
F_99 ( V_2 , L_40 ) ;
V_4 -> V_98 = - 1 ;
}
V_4 -> V_141 = - 1 ;
V_15 [ V_5 ] . V_97 [ V_4 -> V_98 ] = NULL ;
F_74 ( & V_227 ) ;
return ( V_7 > - 512 ) ? V_7 : - V_178 ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_175 ;
int V_5 = V_4 -> V_5 ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
F_101 (cpu) {
struct V_31 * V_32 = & F_63 ( V_33 , V_175 ) ;
struct V_139 * V_140 =
& V_32 -> V_35 [ V_5 ] . V_140 [ V_4 -> V_141 ] ;
F_159 ( & V_140 -> V_142 ) ;
F_160 ( V_2 , V_175 ) ;
}
F_72 ( & V_227 ) ;
V_16 -> V_97 [ V_4 -> V_98 ] = NULL ;
( void ) F_93 ( V_2 ) ;
if ( V_4 -> V_232 >= 0 ) {
if ( F_151 ( & V_4 -> V_231 ) != 0 )
F_99 ( V_2 , L_39 ) ;
V_4 -> V_232 = - 1 ;
}
if ( V_4 -> V_98 >= 0 ) {
if ( F_151 ( & V_4 -> V_223 ) != 0 )
F_99 ( V_2 , L_40 ) ;
V_4 -> V_98 = - 1 ;
}
V_4 -> V_141 = - 1 ;
F_74 ( & V_227 ) ;
return 0 ;
}
static inline void * F_161 ( T_15 * V_236 )
{
unsigned long V_237 = F_120 ( F_162 ( V_236 ) ) ;
return F_119 ( V_237 ) + V_236 -> V_238 ;
}
static T_9 F_163 ( struct V_1 * V_2 ,
int V_138 ,
struct V_126 * V_127 ,
T_7 * V_125 ,
int V_239 )
{
if ( V_127 -> V_131 - V_127 -> V_130 < V_133 - 1 ||
F_59 ( V_125 , V_127 , 32 , false ) != 0 ) {
T_9 V_240 = F_164 ( V_125 , V_239 ) ;
if ( V_240 >= 0 )
return V_240 ;
F_59 ( V_125 , V_127 , V_133 , false ) ;
V_240 = F_164 ( V_125 , V_239 ) ;
if ( V_240 >= 0 )
return V_240 ;
}
F_160 ( V_2 , V_138 ) ;
F_62 ( V_2 , V_138 ) ;
return - 1 ;
}
static int F_165 ( struct V_21 * V_22 )
{
struct V_49 * V_241 = F_34 ( V_22 ) ;
unsigned int V_242 = F_166 ( V_22 ) + F_167 ( V_22 ) ;
unsigned int V_243 = V_22 -> V_23 - V_242 ;
unsigned int V_244 = V_241 -> V_245 ;
long V_246 = - 1 ;
long V_247 = F_168 ( V_22 ) - V_242 ;
long V_248 = 0 ;
long V_116 ;
int V_239 = 0 ;
int V_249 ;
for ( V_249 = 0 ; V_249 < V_241 -> V_250 ; V_249 ++ ) {
unsigned int V_251 = 0 ;
for ( V_239 ++ ; V_251 < V_244 ; V_239 ++ ) {
while ( V_248 >= V_247 ) {
V_246 ++ ;
V_247 = F_169 ( & V_241 -> V_252 [ V_246 ] ) ;
V_248 = 0 ;
}
V_116 = V_244 - V_251 ;
if ( V_116 > V_247 - V_248 )
V_116 = V_247 - V_248 ;
V_248 += V_116 ;
V_251 += V_116 ;
}
V_243 -= V_244 ;
if ( V_243 < V_244 )
V_244 = V_243 ;
}
return V_239 ;
}
static void F_170 ( struct V_21 * V_22 , unsigned char * V_212 ,
T_9 V_240 )
{
struct V_49 * V_241 = F_34 ( V_22 ) ;
struct V_253 * V_254 ;
struct V_255 * V_256 ;
struct V_257 * V_258 ;
unsigned int V_242 = F_166 ( V_22 ) + F_167 ( V_22 ) ;
unsigned int V_243 = V_22 -> V_23 - V_242 ;
unsigned char * V_24 = V_22 -> V_24 ;
unsigned int V_259 , V_260 , V_244 ;
unsigned int V_261 , V_262 , V_263 ;
unsigned int V_264 ( V_122 ) ;
int V_265 ;
long V_246 = - 1 ;
long V_247 = F_168 ( V_22 ) - V_242 ;
long V_248 = 0 ;
long V_116 ;
int V_249 ;
V_265 = F_171 ( V_22 ) ;
if ( V_265 ) {
V_256 = F_172 ( V_22 ) ;
V_259 = F_173 ( V_22 ) ;
} else {
V_254 = F_174 ( V_22 ) ;
V_259 = F_173 ( V_22 ) ;
V_261 = ( ( 0xFFFF - V_254 -> V_266 ) +
( 0xFFFF - V_254 -> V_267 ) +
( 0xFFFF - V_254 -> V_122 ) ) ;
V_122 = F_175 ( V_254 -> V_122 ) ;
}
V_258 = F_176 ( V_22 ) ;
V_260 = F_166 ( V_22 ) ;
V_244 = V_241 -> V_245 ;
V_262 = V_258 -> V_266 + ( 0xFFFF ^ F_177 ( V_22 -> V_23 ) ) ;
V_263 = F_178 ( V_258 -> V_263 ) ;
for ( V_249 = 0 ; V_249 < V_241 -> V_250 ; V_249 ++ ) {
unsigned char * V_6 ;
unsigned int V_251 = 0 ;
V_6 = V_212 + ( V_240 % V_217 ) * V_218 +
V_109 ;
memcpy ( V_6 , V_24 , V_242 ) ;
if ( V_265 ) {
V_256 = (struct V_255 * ) ( V_6 + V_259 ) ;
V_256 -> V_268 = F_177 ( V_242 + V_244 - V_259 -
sizeof( * V_256 ) ) ;
} else {
V_254 = (struct V_253 * ) ( V_6 + V_259 ) ;
V_254 -> V_267 = F_177 ( V_242 + V_244 - V_259 ) ;
V_254 -> V_122 = F_177 ( V_122 ++ ) ;
V_254 -> V_266 = F_179 ( V_261 + V_254 -> V_267 +
V_254 -> V_122 ) ^ 0xffff ;
}
V_258 = (struct V_257 * ) ( V_6 + V_260 ) ;
V_258 -> V_263 = F_180 ( V_263 ) ;
V_258 -> V_266 = F_179 ( V_262 + F_177 ( V_242 + V_244 ) ) ;
if ( V_249 != V_241 -> V_250 - 1 ) {
V_258 -> V_269 = 0 ;
V_258 -> V_270 = 0 ;
}
V_240 ++ ;
while ( V_251 < V_244 ) {
while ( V_248 >= V_247 ) {
V_246 ++ ;
V_247 = F_169 ( & V_241 -> V_252 [ V_246 ] ) ;
V_248 = 0 ;
}
V_116 = V_244 - V_251 ;
if ( V_116 > V_247 - V_248 )
V_116 = V_247 - V_248 ;
V_248 += V_116 ;
V_251 += V_116 ;
V_240 ++ ;
}
V_263 += V_244 ;
V_243 -= V_244 ;
if ( V_243 < V_244 )
V_244 = V_243 ;
}
F_17 () ;
}
static void F_181 ( struct V_1 * V_2 , T_7 * V_125 ,
struct V_21 * V_22 , unsigned char * V_212 , T_9 V_240 )
{
struct V_49 * V_241 = F_34 ( V_22 ) ;
int V_5 = F_1 ( V_2 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
unsigned int V_242 = F_166 ( V_22 ) + F_167 ( V_22 ) ;
unsigned int V_243 = V_22 -> V_23 - V_242 ;
unsigned int V_244 = V_241 -> V_245 ;
T_12 V_271 = { { 0 } } ;
T_12 V_272 = { { 0 } } ;
long V_246 = - 1 ;
long V_247 = F_168 ( V_22 ) - V_242 ;
long V_248 = 0 ;
void * V_273 = V_22 -> V_24 + V_242 ;
long V_116 ;
unsigned long V_274 = 0 , V_275 = 0 ;
unsigned int V_276 ;
int V_249 ;
V_276 = F_182 ( V_22 ) ;
V_271 . V_277 = 1 ;
V_271 . V_276 = V_276 ;
V_271 . V_278 = V_276 + V_22 -> V_279 ;
V_271 . V_280 = V_242 ;
V_271 . V_186 = V_16 -> V_26 ;
V_272 . V_186 = V_16 -> V_26 ;
for ( V_249 = 0 ; V_249 < V_241 -> V_250 ; V_249 ++ ) {
unsigned char * V_6 ;
unsigned int V_251 = 0 ;
V_6 = V_212 + ( V_240 % V_217 ) * V_218 +
V_109 ;
V_271 . V_27 = F_19 ( V_6 ) ;
F_183 ( V_125 , V_271 , V_240 ) ;
V_240 ++ ;
while ( V_251 < V_244 ) {
void * V_27 ;
while ( V_248 >= V_247 ) {
V_246 ++ ;
V_247 = F_169 ( & V_241 -> V_252 [ V_246 ] ) ;
V_273 = F_161 ( & V_241 -> V_252 [ V_246 ] ) ;
V_248 = 0 ;
}
V_27 = V_273 + V_248 ;
V_116 = V_244 - V_251 ;
if ( V_116 > V_247 - V_248 )
V_116 = V_247 - V_248 ;
V_248 += V_116 ;
V_251 += V_116 ;
V_272 . V_27 = F_19 ( V_27 ) ;
V_272 . V_280 = V_116 ;
V_272 . V_281 = ! ( V_251 < V_244 ) ;
F_183 ( V_125 , V_272 , V_240 ) ;
V_240 ++ ;
}
V_274 ++ ;
V_275 += V_242 + V_244 ;
V_243 -= V_244 ;
if ( V_243 < V_244 )
V_244 = V_243 ;
}
F_10 ( V_274 , & V_2 -> V_93 . V_274 ) ;
F_10 ( V_275 , & V_2 -> V_93 . V_275 ) ;
}
static int F_184 ( struct V_21 * V_22 , struct V_1 * V_2 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_98 = V_4 -> V_141 ;
int V_5 = V_4 -> V_5 ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
struct V_155 * V_156 = & V_16 -> V_157 [ V_98 ] ;
struct V_126 * V_127 =
V_32 -> V_35 [ V_5 ] . V_158 [ V_98 ] ;
T_7 * V_125 = V_156 -> V_125 ;
unsigned long V_152 ;
int V_239 ;
T_9 V_240 ;
V_239 = F_165 ( V_22 ) ;
F_69 ( V_152 ) ;
V_240 = F_163 ( V_2 , V_22 -> V_282 , V_127 ,
V_125 , V_239 ) ;
if ( V_240 < 0 ) {
F_70 ( V_152 ) ;
return V_283 ;
}
F_170 ( V_22 , V_156 -> V_212 , V_240 ) ;
F_181 ( V_2 , V_125 , V_22 , V_156 -> V_212 , V_240 ) ;
F_61 ( V_125 , V_127 , V_240 + V_239 - 1 , V_22 ) ;
F_70 ( V_152 ) ;
F_67 () ;
return V_284 ;
}
static unsigned int F_185 ( struct V_285 * V_252 ,
struct V_21 * V_22 ,
void * V_286 , unsigned int V_287 )
{
unsigned int V_115 , V_116 = 0 ;
struct V_49 * V_241 = F_34 ( V_22 ) ;
if ( V_287 != 0 ) {
V_252 [ V_116 ] . V_6 = V_286 ;
V_252 [ V_116 ++ ] . V_288 = V_287 ;
}
for ( V_115 = 0 ; V_115 < V_241 -> V_289 ; V_115 ++ ) {
T_15 * V_236 = & V_241 -> V_252 [ V_115 ] ;
V_252 [ V_116 ] . V_6 = F_161 ( V_236 ) ;
V_252 [ V_116 ++ ] . V_288 = F_169 ( V_236 ) ;
}
return V_116 ;
}
static int F_186 ( struct V_21 * V_22 , struct V_1 * V_2 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = V_4 -> V_5 ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
struct V_155 * V_156 =
& V_16 -> V_157 [ V_4 -> V_141 ] ;
T_7 * V_125 = V_156 -> V_125 ;
struct V_126 * V_127 =
V_32 -> V_35 [ V_5 ] . V_158 [ V_4 -> V_141 ] ;
unsigned int V_23 = V_22 -> V_23 ;
unsigned char * V_24 = V_22 -> V_24 ;
unsigned int V_239 ;
struct V_285 V_252 [ V_290 ] ;
T_12 V_211 [ V_290 ] ;
unsigned long V_152 ;
T_12 V_291 = { { 0 } } ;
unsigned int V_115 ;
T_9 V_240 ;
if ( F_187 ( V_22 ) )
return F_184 ( V_22 , V_2 ) ;
V_239 = F_185 ( V_252 , V_22 , V_24 , F_168 ( V_22 ) ) ;
V_291 . V_186 = V_16 -> V_26 ;
for ( V_115 = 0 ; V_115 < V_239 ; V_115 ++ ) {
V_291 . V_280 = V_252 [ V_115 ] . V_288 ;
V_291 . V_27 = F_19 ( V_252 [ V_115 ] . V_6 ) ;
V_211 [ V_115 ] = V_291 ;
}
V_211 [ V_239 - 1 ] . V_281 = 1 ;
if ( V_22 -> V_90 == V_292 ) {
unsigned int V_276 = F_182 ( V_22 ) ;
V_211 [ 0 ] . V_277 = 1 ;
V_211 [ 0 ] . V_276 = V_276 ;
V_211 [ 0 ] . V_278 = V_276 + V_22 -> V_279 ;
}
F_69 ( V_152 ) ;
V_240 = F_163 ( V_2 , V_22 -> V_282 , V_127 ,
V_125 , V_239 ) ;
if ( V_240 < 0 ) {
F_70 ( V_152 ) ;
return V_283 ;
}
for ( V_115 = 0 ; V_115 < V_239 ; V_115 ++ )
F_183 ( V_125 , V_211 [ V_115 ] , V_240 ++ ) ;
F_33 ( V_22 , V_5 ) ;
F_61 ( V_125 , V_127 , V_240 - 1 , V_22 ) ;
F_10 ( 1 , & V_2 -> V_93 . V_274 ) ;
F_10 ( F_188 (unsigned int, len, ETH_ZLEN) ,
& V_2 -> V_93 . V_275 ) ;
F_70 ( V_152 ) ;
F_67 () ;
return V_284 ;
}
static T_16 F_189 ( struct V_1 * V_2 , struct V_21 * V_22 ,
void * V_293 , T_17 V_294 )
{
return F_190 () ;
}
static void F_191 ( struct V_1 * V_2 )
{
int V_175 ;
F_101 (cpu)
F_66 ( V_2 , V_175 ) ;
}
static int F_192 ( struct V_1 * V_2 , struct V_58 * V_59 , int V_295 )
{
if ( V_295 == V_296 )
return F_37 ( V_2 , V_59 ) ;
if ( V_295 == V_297 )
return F_40 ( V_2 , V_59 ) ;
return - V_170 ;
}
static int F_193 ( struct V_1 * V_2 , int V_298 )
{
if ( V_298 < 68 )
return - V_65 ;
if ( V_298 > ( ( V_193 != 0 ) ? 9000 : 1500 ) )
return - V_65 ;
V_2 -> V_299 = V_298 ;
return 0 ;
}
static int F_194 ( struct V_1 * V_2 , void * V_300 )
{
struct V_301 * V_30 = V_300 ;
if ( ! F_195 ( V_30 -> V_302 ) )
return - V_65 ;
memcpy ( V_2 -> V_86 , V_30 -> V_302 , V_2 -> V_303 ) ;
return 0 ;
}
static void F_196 ( struct V_1 * V_2 )
{
int V_5 = F_1 ( V_2 ) ;
struct V_31 * V_32 = & F_27 ( V_33 ) ;
struct V_15 * V_16 = & V_15 [ V_5 ] ;
F_92 ( V_16 -> V_179 ) ;
F_57 ( & V_32 -> V_35 [ V_5 ] . V_92 ) ;
F_90 ( V_16 -> V_179 , 0 ) ;
}
static void F_197 ( struct V_1 * V_2 )
{
T_18 V_304 = 0 ;
F_198 ( V_2 ) ;
V_2 -> V_305 = & V_306 ;
V_2 -> V_307 = V_308 ;
V_2 -> V_299 = 1500 ;
V_304 |= V_309 ;
V_304 |= V_310 ;
V_304 |= V_311 ;
V_304 |= V_312 ;
V_2 -> V_313 |= V_304 ;
V_2 -> V_314 |= V_304 ;
V_2 -> V_304 |= V_304 ;
}
static void F_199 ( const char * V_228 , const T_5 * V_315 )
{
int V_162 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
if ( strncmp ( V_228 , L_41 , 4 ) == 0 )
return;
V_2 = F_200 ( sizeof( * V_4 ) , V_228 , V_316 ,
F_197 , V_317 , 1 ) ;
if ( ! V_2 ) {
F_201 ( L_42 , V_228 ) ;
return;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_98 = - 1 ;
V_4 -> V_232 = - 1 ;
V_4 -> V_141 = - 1 ;
F_88 ( V_4 ) ;
if ( ! F_202 ( V_315 ) )
F_203 ( V_2 -> V_86 , V_315 ) ;
else
F_204 ( V_2 ) ;
V_162 = F_205 ( V_2 ) ;
if ( V_162 ) {
F_86 ( V_2 , L_43 , V_162 ) ;
F_206 ( V_2 ) ;
return;
}
}
static void F_207 ( void * V_318 )
{
struct V_31 * V_32 = & F_27 ( V_33 ) ;
int V_39 = F_190 () ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_34 ; V_5 ++ ) {
V_32 -> V_35 [ V_5 ] . V_36 = false ;
V_32 -> V_35 [ V_5 ] . V_5 = V_5 ;
}
V_32 -> V_39 = V_39 ;
F_155 ( & V_32 -> V_150 , V_233 , V_234 ) ;
V_32 -> V_150 . V_235 = F_68 ;
}
static int T_19 F_208 ( void )
{
int V_115 ;
char V_228 [ V_319 ] ;
T_5 V_315 [ 6 ] ;
F_9 ( L_44 ) ;
F_11 ( V_34 != 2 ) ;
F_83 ( & V_227 ) ;
F_100 ( F_207 , NULL , 1 ) ;
for ( V_115 = 0 ; F_209 ( V_115 , V_228 , V_315 ) >= 0 ; V_115 ++ )
F_199 ( V_228 , V_315 ) ;
if ( ! F_3 () )
V_9 = * V_320 ;
return 0 ;
}

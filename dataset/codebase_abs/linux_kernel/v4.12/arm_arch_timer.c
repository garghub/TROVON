static int T_1 F_1 ( char * V_1 )
{
return F_2 ( V_1 , & V_2 ) ;
}
static T_2
void F_3 ( int V_3 , enum V_4 V_5 , T_3 V_6 ,
struct V_7 * V_8 )
{
if ( V_3 == V_9 ) {
struct V_10 * V_11 = F_4 ( V_8 ) ;
switch ( V_5 ) {
case V_12 :
F_5 ( V_6 , V_11 -> V_13 + V_14 ) ;
break;
case V_15 :
F_5 ( V_6 , V_11 -> V_13 + V_16 ) ;
break;
}
} else if ( V_3 == V_17 ) {
struct V_10 * V_11 = F_4 ( V_8 ) ;
switch ( V_5 ) {
case V_12 :
F_5 ( V_6 , V_11 -> V_13 + V_18 ) ;
break;
case V_15 :
F_5 ( V_6 , V_11 -> V_13 + V_19 ) ;
break;
}
} else {
F_6 ( V_3 , V_5 , V_6 ) ;
}
}
static T_2
T_3 F_7 ( int V_3 , enum V_4 V_5 ,
struct V_7 * V_8 )
{
T_3 V_6 ;
if ( V_3 == V_9 ) {
struct V_10 * V_11 = F_4 ( V_8 ) ;
switch ( V_5 ) {
case V_12 :
V_6 = F_8 ( V_11 -> V_13 + V_14 ) ;
break;
case V_15 :
V_6 = F_8 ( V_11 -> V_13 + V_16 ) ;
break;
}
} else if ( V_3 == V_17 ) {
struct V_10 * V_11 = F_4 ( V_8 ) ;
switch ( V_5 ) {
case V_12 :
V_6 = F_8 ( V_11 -> V_13 + V_18 ) ;
break;
case V_15 :
V_6 = F_8 ( V_11 -> V_13 + V_19 ) ;
break;
}
} else {
V_6 = F_9 ( V_3 , V_5 ) ;
}
return V_6 ;
}
static T_4 F_10 ( struct V_20 * V_21 )
{
return F_11 () ;
}
static T_4 F_12 ( const struct V_22 * V_23 )
{
return F_11 () ;
}
static T_3 T_5 F_13 ( void )
{
return F_14 ( V_24 ) ;
}
static T_3 T_5 F_15 ( void )
{
return F_14 ( V_25 ) ;
}
static T_4 T_5 F_16 ( void )
{
return F_14 ( V_26 ) ;
}
static T_3 T_5 F_17 ( void )
{
return F_18 ( V_24 ) ;
}
static T_3 T_5 F_19 ( void )
{
return F_18 ( V_25 ) ;
}
static T_4 T_5 F_20 ( void )
{
return F_18 ( V_26 ) ;
}
static T_4 T_5 F_21 ( void )
{
T_4 V_27 , V_28 ;
V_27 = F_22 ( V_26 ) ;
V_28 = F_22 ( V_26 ) ;
return ( ( ( V_27 ^ V_28 ) >> 32 ) & 1 ) ? V_27 : V_28 ;
}
static void F_23 ( const int V_3 , unsigned long V_29 ,
struct V_7 * V_8 )
{
unsigned long V_30 ;
T_4 V_31 = V_29 + F_24 () ;
V_30 = F_7 ( V_3 , V_12 , V_8 ) ;
V_30 |= V_32 ;
V_30 &= ~ V_33 ;
if ( V_3 == V_34 )
F_25 ( V_31 , V_35 ) ;
else
F_25 ( V_31 , V_36 ) ;
F_3 ( V_3 , V_12 , V_30 , V_8 ) ;
}
static T_6 int F_26 ( unsigned long V_29 ,
struct V_7 * V_8 )
{
F_23 ( V_37 , V_29 , V_8 ) ;
return 0 ;
}
static T_6 int F_27 ( unsigned long V_29 ,
struct V_7 * V_8 )
{
F_23 ( V_34 , V_29 , V_8 ) ;
return 0 ;
}
static
bool F_28 ( const struct V_38 * V_39 ,
const void * V_40 )
{
const struct V_41 * V_42 = V_40 ;
return F_29 ( V_42 , V_39 -> V_43 ) ;
}
static
bool F_30 ( const struct V_38 * V_39 ,
const void * V_40 )
{
return F_31 ( ( V_44 ) V_39 -> V_43 ) ;
}
static
bool F_32 ( const struct V_38 * V_39 ,
const void * V_40 )
{
static const struct V_45 V_46 = {} ;
const struct V_45 * V_47 = V_39 -> V_43 ;
const struct V_48 * V_49 = V_40 ;
while ( memcmp ( V_47 , & V_46 , sizeof( * V_47 ) ) ) {
if ( ! memcmp ( V_47 -> V_50 , V_49 -> V_50 , V_51 ) &&
! memcmp ( V_47 -> V_52 , V_49 -> V_52 , V_53 ) &&
V_47 -> V_54 == V_49 -> V_54 )
return true ;
V_47 ++ ;
}
return false ;
}
static const struct V_38 *
F_33 ( enum V_55 type ,
T_7 V_56 ,
void * V_40 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < F_34 ( V_58 ) ; V_57 ++ ) {
if ( V_58 [ V_57 ] . V_59 != type )
continue;
if ( V_56 ( & V_58 [ V_57 ] , V_40 ) )
return & V_58 [ V_57 ] ;
}
return NULL ;
}
static
void F_35 ( const struct V_38 * V_39 ,
bool V_60 )
{
int V_57 ;
if ( V_60 ) {
F_36 ( V_61 , V_39 ) ;
} else {
F_37 (i)
F_38 ( V_61 , V_57 ) = V_39 ;
}
F_39 ( & V_62 ) ;
if ( V_39 -> V_63 ) {
V_64 . V_65 . V_66 = false ;
V_67 = false ;
}
}
static void F_40 ( enum V_55 type ,
void * V_40 )
{
const struct V_38 * V_39 ;
T_7 V_56 = NULL ;
bool V_60 = false ;
switch ( type ) {
case V_68 :
V_56 = F_28 ;
break;
case V_69 :
V_56 = F_30 ;
V_60 = true ;
break;
case V_70 :
V_56 = F_32 ;
break;
default:
F_41 ( 1 ) ;
return;
}
V_39 = F_33 ( type , V_56 , V_40 ) ;
if ( ! V_39 )
return;
if ( F_42 () ) {
const struct V_38 * V_71 ;
V_71 = F_43 ( V_61 ) ;
if ( V_71 && V_39 != V_71 )
F_44 ( L_1 ,
V_39 -> V_72 , V_71 -> V_72 ) ;
if ( V_71 )
return;
}
F_35 ( V_39 , V_60 ) ;
F_45 ( L_2 ,
V_60 ? L_3 : L_4 , V_39 -> V_72 ) ;
}
static bool F_46 ( void )
{
const struct V_38 * V_39 ;
V_39 = F_43 ( V_61 ) ;
return V_39 && V_39 -> V_63 ;
}
static T_2 T_8 F_47 ( const int V_3 ,
struct V_7 * V_29 )
{
unsigned long V_30 ;
V_30 = F_7 ( V_3 , V_12 , V_29 ) ;
if ( V_30 & V_73 ) {
V_30 |= V_33 ;
F_3 ( V_3 , V_12 , V_30 , V_29 ) ;
V_29 -> V_74 ( V_29 ) ;
return V_75 ;
}
return V_76 ;
}
static T_8 F_48 ( int V_77 , void * V_78 )
{
struct V_7 * V_29 = V_78 ;
return F_47 ( V_37 , V_29 ) ;
}
static T_8 F_49 ( int V_77 , void * V_78 )
{
struct V_7 * V_29 = V_78 ;
return F_47 ( V_34 , V_29 ) ;
}
static T_8 F_50 ( int V_77 , void * V_78 )
{
struct V_7 * V_29 = V_78 ;
return F_47 ( V_9 , V_29 ) ;
}
static T_8 F_51 ( int V_77 , void * V_78 )
{
struct V_7 * V_29 = V_78 ;
return F_47 ( V_17 , V_29 ) ;
}
static T_2 int F_52 ( const int V_3 ,
struct V_7 * V_8 )
{
unsigned long V_30 ;
V_30 = F_7 ( V_3 , V_12 , V_8 ) ;
V_30 &= ~ V_32 ;
F_3 ( V_3 , V_12 , V_30 , V_8 ) ;
return 0 ;
}
static int F_53 ( struct V_7 * V_8 )
{
return F_52 ( V_37 , V_8 ) ;
}
static int F_54 ( struct V_7 * V_8 )
{
return F_52 ( V_34 , V_8 ) ;
}
static int F_55 ( struct V_7 * V_8 )
{
return F_52 ( V_17 , V_8 ) ;
}
static int F_56 ( struct V_7 * V_8 )
{
return F_52 ( V_9 , V_8 ) ;
}
static T_2 void F_57 ( const int V_3 , unsigned long V_29 ,
struct V_7 * V_8 )
{
unsigned long V_30 ;
V_30 = F_7 ( V_3 , V_12 , V_8 ) ;
V_30 |= V_32 ;
V_30 &= ~ V_33 ;
F_3 ( V_3 , V_15 , V_29 , V_8 ) ;
F_3 ( V_3 , V_12 , V_30 , V_8 ) ;
}
static int F_58 ( unsigned long V_29 ,
struct V_7 * V_8 )
{
int V_79 ;
if ( F_59 ( V_80 , V_79 , V_29 , V_8 ) )
return V_79 ;
F_57 ( V_37 , V_29 , V_8 ) ;
return 0 ;
}
static int F_60 ( unsigned long V_29 ,
struct V_7 * V_8 )
{
int V_79 ;
if ( F_59 ( V_81 , V_79 , V_29 , V_8 ) )
return V_79 ;
F_57 ( V_34 , V_29 , V_8 ) ;
return 0 ;
}
static int F_61 ( unsigned long V_29 ,
struct V_7 * V_8 )
{
F_57 ( V_17 , V_29 , V_8 ) ;
return 0 ;
}
static int F_62 ( unsigned long V_29 ,
struct V_7 * V_8 )
{
F_57 ( V_9 , V_29 , V_8 ) ;
return 0 ;
}
static void F_63 ( unsigned type ,
struct V_7 * V_8 )
{
V_8 -> V_82 = V_83 ;
if ( type == V_84 ) {
if ( V_85 )
V_8 -> V_82 |= V_86 ;
V_8 -> V_87 = L_5 ;
V_8 -> V_88 = 450 ;
V_8 -> V_89 = F_64 ( F_65 () ) ;
V_8 -> V_77 = V_90 [ V_91 ] ;
switch ( V_91 ) {
case V_92 :
V_8 -> V_93 = F_53 ;
V_8 -> V_94 = F_53 ;
V_8 -> F_57 = F_58 ;
break;
case V_95 :
case V_96 :
case V_97 :
V_8 -> V_93 = F_54 ;
V_8 -> V_94 = F_54 ;
V_8 -> F_57 = F_60 ;
break;
default:
F_66 () ;
}
F_40 ( V_69 , NULL ) ;
} else {
V_8 -> V_82 |= V_98 ;
V_8 -> V_87 = L_6 ;
V_8 -> V_88 = 400 ;
V_8 -> V_89 = V_99 ;
if ( V_100 ) {
V_8 -> V_93 = F_55 ;
V_8 -> V_94 = F_55 ;
V_8 -> F_57 =
F_61 ;
} else {
V_8 -> V_93 = F_56 ;
V_8 -> V_94 = F_56 ;
V_8 -> F_57 =
F_62 ;
}
}
V_8 -> V_93 ( V_8 ) ;
F_67 ( V_8 , V_101 , 0xf , 0x7fffffff ) ;
}
static void F_68 ( int V_102 )
{
T_3 V_103 = F_69 () ;
V_103 &= ~ V_104 ;
V_103 |= ( V_102 << V_105 )
| V_106 ;
F_70 ( V_103 ) ;
V_107 |= V_108 ;
#ifdef F_71
V_109 |= V_110 ;
#endif
}
static void F_72 ( void )
{
int V_111 , V_112 ;
V_111 = V_101 / V_113 ;
V_112 = F_73 ( V_111 ) ;
if ( V_112 > 1 && ! ( V_111 & ( 1 << ( V_112 - 2 ) ) ) )
V_112 -- ;
F_68 ( F_74 ( V_112 , 15 ) ) ;
}
static void F_75 ( void )
{
T_3 V_103 = F_69 () ;
V_103 &= ~ ( V_114
| V_115
| V_116
| V_106
| V_117 ) ;
if ( F_46 () )
F_45 ( L_7 , F_65 () ) ;
else
V_103 |= V_116 ;
F_70 ( V_103 ) ;
}
static bool F_76 ( void )
{
return ( V_91 == V_95 &&
V_90 [ V_96 ] ) ;
}
static T_3 F_77 ( int V_77 )
{
T_3 V_118 = F_78 ( V_77 ) ;
if ( V_118 != V_119 && V_118 != V_120 ) {
F_44 ( L_8 , V_77 ) ;
F_44 ( L_9 ) ;
V_118 = V_120 ;
}
return V_118 ;
}
static int F_79 ( unsigned int V_121 )
{
struct V_7 * V_8 = F_80 ( V_122 ) ;
T_3 V_118 ;
F_63 ( V_84 , V_8 ) ;
V_118 = F_77 ( V_90 [ V_91 ] ) ;
F_81 ( V_90 [ V_91 ] , V_118 ) ;
if ( F_76 () ) {
V_118 = F_77 ( V_90 [ V_96 ] ) ;
F_81 ( V_90 [ V_96 ] ,
V_118 ) ;
}
F_75 () ;
if ( V_2 )
F_72 () ;
return 0 ;
}
static void F_82 ( T_3 V_123 , struct V_41 * V_42 )
{
if ( V_101 )
return;
if ( F_83 ( V_42 , L_10 , & V_101 ) )
V_101 = V_123 ;
if ( V_101 == 0 )
F_44 ( L_11 ) ;
}
static void F_84 ( unsigned type )
{
F_45 ( L_12 ,
type & V_84 ? L_13 : L_14 ,
type == ( V_84 | V_124 ) ?
L_15 : L_14 ,
type & V_124 ? L_16 : L_14 ,
( unsigned long ) V_101 / 1000000 ,
( unsigned long ) ( V_101 / 10000 ) % 100 ,
type & V_84 ?
( V_91 == V_92 ) ? L_17 : L_18 :
L_14 ,
type == ( V_84 | V_124 ) ? L_19 : L_14 ,
type & V_124 ?
V_100 ? L_17 : L_18 :
L_14 ) ;
}
T_3 F_85 ( void )
{
return V_101 ;
}
static T_4 F_86 ( void )
{
T_3 V_125 , V_126 , V_127 ;
do {
V_126 = F_8 ( V_128 + V_129 ) ;
V_125 = F_8 ( V_128 + V_130 ) ;
V_127 = F_8 ( V_128 + V_129 ) ;
} while ( V_126 != V_127 );
return ( ( T_4 ) V_126 << 32 ) | V_125 ;
}
struct V_131 * F_87 ( void )
{
return & V_131 ;
}
static void T_1 F_88 ( unsigned type )
{
T_4 V_132 ;
if ( type & V_84 ) {
if ( F_89 ( V_133 ) ||
V_91 == V_92 )
F_11 = F_24 ;
else
F_11 = V_134 ;
V_64 . V_65 . V_66 = V_67 ;
} else {
F_11 = F_86 ;
}
if ( ! V_135 )
V_64 . V_118 |= V_136 ;
V_132 = F_11 () ;
F_90 ( & V_64 , V_101 ) ;
V_22 . V_137 = V_64 . V_137 ;
V_22 . V_138 = V_64 . V_138 ;
F_91 ( & V_131 . V_139 ,
& V_22 , V_132 ) ;
F_92 ( F_11 , 56 , V_101 ) ;
}
static void F_93 ( struct V_7 * V_8 )
{
F_94 ( L_20 , V_8 -> V_77 , F_65 () ) ;
F_95 ( V_90 [ V_91 ] ) ;
if ( F_76 () )
F_95 ( V_90 [ V_96 ] ) ;
V_8 -> V_93 ( V_8 ) ;
}
static int F_96 ( unsigned int V_121 )
{
struct V_7 * V_8 = F_80 ( V_122 ) ;
F_93 ( V_8 ) ;
return 0 ;
}
static int F_97 ( struct V_140 * V_141 ,
unsigned long V_142 , void * V_143 )
{
if ( V_142 == V_144 )
F_36 ( V_145 , F_69 () ) ;
else if ( V_142 == V_146 || V_142 == V_147 )
F_70 ( F_43 ( V_145 ) ) ;
return V_148 ;
}
static int T_1 F_98 ( void )
{
return F_99 ( & V_149 ) ;
}
static void T_1 F_100 ( void )
{
F_41 ( F_101 ( & V_149 ) ) ;
}
static int T_1 F_98 ( void )
{
return 0 ;
}
static void T_1 F_100 ( void )
{
}
static int T_1 F_102 ( void )
{
int V_150 ;
int V_151 ;
V_122 = F_103 ( struct V_7 ) ;
if ( ! V_122 ) {
V_150 = - V_152 ;
goto V_153;
}
V_151 = V_90 [ V_91 ] ;
switch ( V_91 ) {
case V_92 :
V_150 = F_104 ( V_151 , F_48 ,
L_21 , V_122 ) ;
break;
case V_95 :
case V_96 :
V_150 = F_104 ( V_151 , F_49 ,
L_21 , V_122 ) ;
if ( ! V_150 && F_76 () ) {
V_151 = V_90 [ V_96 ] ;
V_150 = F_104 ( V_151 , F_49 ,
L_21 , V_122 ) ;
if ( V_150 )
F_105 ( V_90 [ V_95 ] ,
V_122 ) ;
}
break;
case V_97 :
V_150 = F_104 ( V_151 , F_49 ,
L_21 , V_122 ) ;
break;
default:
F_66 () ;
}
if ( V_150 ) {
F_106 ( L_22 , V_151 , V_150 ) ;
goto V_154;
}
V_150 = F_98 () ;
if ( V_150 )
goto V_155;
V_150 = F_107 ( V_156 ,
L_23 ,
F_79 , F_96 ) ;
if ( V_150 )
goto V_157;
return 0 ;
V_157:
F_100 () ;
V_155:
F_105 ( V_90 [ V_91 ] , V_122 ) ;
if ( F_76 () )
F_105 ( V_90 [ V_96 ] ,
V_122 ) ;
V_154:
F_108 ( V_122 ) ;
V_153:
return V_150 ;
}
static int T_1 F_109 ( void T_9 * V_13 , unsigned int V_77 )
{
int V_79 ;
T_10 V_158 ;
struct V_10 * V_159 ;
V_159 = F_110 ( sizeof( * V_159 ) , V_160 ) ;
if ( ! V_159 )
return - V_152 ;
V_159 -> V_13 = V_13 ;
V_159 -> V_29 . V_77 = V_77 ;
F_63 ( V_124 , & V_159 -> V_29 ) ;
if ( V_100 )
V_158 = F_51 ;
else
V_158 = F_50 ;
V_79 = F_111 ( V_77 , V_158 , V_161 , L_6 , & V_159 -> V_29 ) ;
if ( V_79 ) {
F_106 ( L_24 ) ;
F_112 ( V_159 ) ;
}
return V_79 ;
}
static bool T_1 F_113 ( void )
{
struct V_41 * V_162 ;
bool V_163 = false ;
unsigned int V_164 = V_84 | V_124 ;
if ( ( V_165 & V_164 ) == V_164 )
return false ;
if ( V_165 & V_84 )
V_162 = F_114 ( NULL , V_166 ) ;
else
V_162 = F_114 ( NULL , V_167 ) ;
if ( V_162 && F_115 ( V_162 ) )
V_163 = true ;
F_116 ( V_162 ) ;
return V_163 ;
}
static int T_1 F_117 ( void )
{
F_84 ( V_165 ) ;
F_88 ( V_165 ) ;
return F_118 () ;
}
static enum V_168 T_1 F_119 ( void )
{
if ( F_120 () )
return V_97 ;
if ( ! F_121 () && V_90 [ V_92 ] )
return V_92 ;
if ( F_89 ( V_133 ) )
return V_96 ;
return V_95 ;
}
static int T_1 F_122 ( struct V_41 * V_42 )
{
int V_57 , V_79 ;
T_3 V_123 ;
if ( V_165 & V_84 ) {
F_44 ( L_25 ) ;
return 0 ;
}
V_165 |= V_84 ;
for ( V_57 = V_95 ; V_57 < V_169 ; V_57 ++ )
V_90 [ V_57 ] = F_123 ( V_42 , V_57 ) ;
V_131 . V_170 = V_90 [ V_92 ] ;
V_123 = F_124 () ;
F_82 ( V_123 , V_42 ) ;
V_85 = ! F_29 ( V_42 , L_26 ) ;
F_40 ( V_68 , V_42 ) ;
if ( F_89 ( V_171 ) &&
F_29 ( V_42 , L_27 ) )
V_91 = V_95 ;
else
V_91 = F_119 () ;
if ( ! V_90 [ V_91 ] ) {
F_106 ( L_28 ) ;
return - V_172 ;
}
V_135 = F_29 ( V_42 ,
L_29 ) ;
V_79 = F_102 () ;
if ( V_79 )
return V_79 ;
if ( F_113 () )
return 0 ;
return F_117 () ;
}
static T_3 T_1
F_125 ( struct V_173 * V_174 )
{
void T_9 * V_13 ;
T_3 V_123 ;
V_13 = F_126 ( V_174 -> V_175 , V_174 -> V_176 ) ;
if ( ! V_13 ) {
F_106 ( L_30 , & V_174 -> V_175 ) ;
return 0 ;
}
V_123 = F_8 ( V_13 + V_177 ) ;
F_127 ( V_13 ) ;
return V_123 ;
}
static struct V_173 * T_1
F_128 ( struct V_178 * V_179 )
{
struct V_173 * V_174 , * V_180 = NULL ;
void T_9 * V_181 ;
T_3 V_182 ;
int V_57 ;
V_181 = F_126 ( V_179 -> V_181 , V_179 -> V_176 ) ;
if ( ! V_181 ) {
F_106 ( L_31 ,
& V_179 -> V_181 ) ;
return NULL ;
}
V_182 = F_8 ( V_181 + V_183 ) ;
for ( V_57 = 0 ; V_57 < V_184 ; V_57 ++ ) {
T_3 V_185 = V_186 | V_187 | V_188 |
V_189 | V_190 | V_191 ;
V_174 = & V_179 -> V_174 [ V_57 ] ;
if ( ! V_174 -> V_192 )
continue;
F_5 ( V_185 , V_181 + F_129 ( V_57 ) ) ;
V_185 = F_8 ( V_181 + F_129 ( V_57 ) ) ;
if ( ( V_182 & F_130 ( V_57 ) ) &&
! ( ~ V_185 & ( V_189 | V_191 ) ) ) {
V_180 = V_174 ;
V_100 = true ;
break;
}
if ( ~ V_185 & ( V_187 | V_188 ) )
continue;
V_180 = V_174 ;
}
F_127 ( V_181 ) ;
if ( ! V_180 )
F_106 ( L_32 ,
& V_179 -> V_181 ) ;
return V_180 ;
}
static int T_1
F_131 ( struct V_173 * V_174 )
{
void T_9 * V_13 ;
int V_79 , V_77 = 0 ;
if ( V_100 )
V_77 = V_174 -> V_193 ;
else
V_77 = V_174 -> V_194 ;
if ( ! V_77 ) {
F_106 ( L_33 ,
V_100 ? L_17 : L_18 ) ;
return - V_172 ;
}
if ( ! F_132 ( V_174 -> V_175 , V_174 -> V_176 ,
L_6 ) )
return - V_195 ;
V_13 = F_126 ( V_174 -> V_175 , V_174 -> V_176 ) ;
if ( ! V_13 ) {
F_106 ( L_34 ) ;
return - V_196 ;
}
V_79 = F_109 ( V_13 , V_77 ) ;
if ( V_79 ) {
F_127 ( V_13 ) ;
return V_79 ;
}
V_128 = V_13 ;
V_165 |= V_124 ;
return 0 ;
}
static int T_1 F_133 ( struct V_41 * V_42 )
{
struct V_178 * V_179 ;
struct V_173 * V_174 ;
struct V_41 * V_197 ;
struct V_198 V_199 ;
int V_79 = - V_172 ;
T_3 V_123 ;
V_179 = F_110 ( sizeof( * V_179 ) , V_160 ) ;
if ( ! V_179 )
return - V_152 ;
if ( F_134 ( V_42 , 0 , & V_199 ) )
goto V_153;
V_179 -> V_181 = V_199 . V_200 ;
V_179 -> V_176 = F_135 ( & V_199 ) ;
F_136 (np, frame_node) {
T_3 V_201 ;
struct V_173 * V_174 ;
if ( F_83 ( V_197 , L_35 , & V_201 ) ) {
F_106 ( V_202 L_36 ) ;
F_116 ( V_197 ) ;
goto V_153;
}
if ( V_201 >= V_184 ) {
F_106 ( V_202 L_37 ,
V_184 - 1 ) ;
F_116 ( V_197 ) ;
goto V_153;
}
V_174 = & V_179 -> V_174 [ V_201 ] ;
if ( V_174 -> V_192 ) {
F_106 ( V_202 L_38 ) ;
F_116 ( V_197 ) ;
goto V_153;
}
if ( F_134 ( V_197 , 0 , & V_199 ) ) {
F_116 ( V_197 ) ;
goto V_153;
}
V_174 -> V_175 = V_199 . V_200 ;
V_174 -> V_176 = F_135 ( & V_199 ) ;
V_174 -> V_193 = F_123 ( V_197 ,
V_203 ) ;
V_174 -> V_194 = F_123 ( V_197 ,
V_204 ) ;
V_174 -> V_192 = true ;
}
V_174 = F_128 ( V_179 ) ;
if ( ! V_174 ) {
V_79 = - V_172 ;
goto V_153;
}
V_123 = F_125 ( V_174 ) ;
F_82 ( V_123 , V_42 ) ;
V_79 = F_131 ( V_174 ) ;
if ( ! V_79 && ! F_113 () )
V_79 = F_117 () ;
V_153:
F_112 ( V_179 ) ;
return V_79 ;
}
static int T_1
F_137 ( struct V_178 * V_179 )
{
struct V_173 * V_174 ;
T_3 V_123 ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_184 ; V_57 ++ ) {
V_174 = & V_179 -> V_174 [ V_57 ] ;
if ( ! V_174 -> V_192 )
continue;
V_123 = F_125 ( V_174 ) ;
if ( V_123 == V_101 )
continue;
F_106 ( V_202 L_39 ,
& V_174 -> V_175 ,
( unsigned long ) V_123 , ( unsigned long ) V_101 ) ;
return - V_172 ;
}
return 0 ;
}
static int T_1 F_138 ( int V_205 )
{
struct V_178 * V_206 , * V_11 ;
struct V_173 * V_174 ;
int V_207 , V_57 , V_79 = 0 ;
V_206 = F_139 ( V_205 , sizeof( * V_206 ) ,
V_160 ) ;
if ( ! V_206 )
return - V_152 ;
V_79 = F_140 ( V_206 , & V_207 ) ;
if ( V_79 || ! V_207 )
goto V_153;
for ( V_57 = 0 ; V_57 < V_207 ; V_57 ++ ) {
V_79 = F_137 ( & V_206 [ V_57 ] ) ;
if ( V_79 ) {
F_106 ( L_40 ) ;
goto V_153;
}
}
for ( V_57 = V_57 ; V_57 < V_207 ; V_57 ++ ) {
V_11 = & V_206 [ V_57 ] ;
V_174 = F_128 ( V_11 ) ;
if ( V_174 )
break;
}
if ( V_174 )
V_79 = F_131 ( V_174 ) ;
V_153:
F_112 ( V_206 ) ;
return V_79 ;
}
static int T_1 F_141 ( struct V_48 * V_49 )
{
int V_79 , V_205 ;
if ( V_165 & V_84 ) {
F_44 ( L_41 ) ;
return - V_172 ;
}
V_165 |= V_84 ;
V_79 = F_142 ( V_49 , & V_205 ) ;
if ( V_79 ) {
F_106 ( L_42 ) ;
return V_79 ;
}
V_90 [ V_96 ] =
F_143 ( V_96 ) ;
V_90 [ V_92 ] =
F_143 ( V_92 ) ;
V_90 [ V_97 ] =
F_143 ( V_97 ) ;
V_131 . V_170 = V_90 [ V_92 ] ;
V_101 = F_124 () ;
if ( ! V_101 ) {
F_106 ( V_202 L_43 ) ;
return - V_172 ;
}
V_91 = F_119 () ;
if ( ! V_90 [ V_91 ] ) {
F_106 ( L_28 ) ;
return - V_172 ;
}
V_85 = F_144 ( V_91 ) ;
F_40 ( V_70 , V_49 ) ;
V_79 = F_102 () ;
if ( V_79 )
return V_79 ;
if ( V_205 &&
F_138 ( V_205 ) )
F_106 ( L_44 ) ;
return F_117 () ;
}

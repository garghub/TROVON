static int T_1 F_1 ( char * V_1 )
{
return F_2 ( V_1 , & V_2 ) ;
}
static T_2 T_3 F_3 ( void )
{
return F_4 ( V_3 ) ;
}
static T_2 T_3 F_5 ( void )
{
return F_4 ( V_4 ) ;
}
static T_4 T_3 F_6 ( void )
{
return F_4 ( V_5 ) ;
}
static T_2 T_3 F_7 ( void )
{
return F_8 ( V_3 ) ;
}
static T_2 T_3 F_9 ( void )
{
return F_8 ( V_4 ) ;
}
static T_4 T_3 F_10 ( void )
{
return F_8 ( V_5 ) ;
}
static T_5
void F_11 ( int V_6 , enum V_7 V_8 , T_2 V_9 ,
struct V_10 * V_11 )
{
if ( V_6 == V_12 ) {
struct V_13 * V_14 = F_12 ( V_11 ) ;
switch ( V_8 ) {
case V_15 :
F_13 ( V_9 , V_14 -> V_16 + V_17 ) ;
break;
case V_18 :
F_13 ( V_9 , V_14 -> V_16 + V_19 ) ;
break;
}
} else if ( V_6 == V_20 ) {
struct V_13 * V_14 = F_12 ( V_11 ) ;
switch ( V_8 ) {
case V_15 :
F_13 ( V_9 , V_14 -> V_16 + V_21 ) ;
break;
case V_18 :
F_13 ( V_9 , V_14 -> V_16 + V_22 ) ;
break;
}
} else {
F_14 ( V_6 , V_8 , V_9 ) ;
}
}
static T_5
T_2 F_15 ( int V_6 , enum V_7 V_8 ,
struct V_10 * V_11 )
{
T_2 V_9 ;
if ( V_6 == V_12 ) {
struct V_13 * V_14 = F_12 ( V_11 ) ;
switch ( V_8 ) {
case V_15 :
V_9 = F_16 ( V_14 -> V_16 + V_17 ) ;
break;
case V_18 :
V_9 = F_16 ( V_14 -> V_16 + V_19 ) ;
break;
}
} else if ( V_6 == V_20 ) {
struct V_13 * V_14 = F_12 ( V_11 ) ;
switch ( V_8 ) {
case V_15 :
V_9 = F_16 ( V_14 -> V_16 + V_21 ) ;
break;
case V_18 :
V_9 = F_16 ( V_14 -> V_16 + V_22 ) ;
break;
}
} else {
V_9 = F_17 ( V_6 , V_8 ) ;
}
return V_9 ;
}
static T_5 T_6 F_18 ( const int V_6 ,
struct V_10 * V_23 )
{
unsigned long V_24 ;
V_24 = F_15 ( V_6 , V_15 , V_23 ) ;
if ( V_24 & V_25 ) {
V_24 |= V_26 ;
F_11 ( V_6 , V_15 , V_24 , V_23 ) ;
V_23 -> V_27 ( V_23 ) ;
return V_28 ;
}
return V_29 ;
}
static T_6 F_19 ( int V_30 , void * V_31 )
{
struct V_10 * V_23 = V_31 ;
return F_18 ( V_32 , V_23 ) ;
}
static T_6 F_20 ( int V_30 , void * V_31 )
{
struct V_10 * V_23 = V_31 ;
return F_18 ( V_33 , V_23 ) ;
}
static T_6 F_21 ( int V_30 , void * V_31 )
{
struct V_10 * V_23 = V_31 ;
return F_18 ( V_12 , V_23 ) ;
}
static T_6 F_22 ( int V_30 , void * V_31 )
{
struct V_10 * V_23 = V_31 ;
return F_18 ( V_20 , V_23 ) ;
}
static T_5 int F_23 ( const int V_6 ,
struct V_10 * V_11 )
{
unsigned long V_24 ;
V_24 = F_15 ( V_6 , V_15 , V_11 ) ;
V_24 &= ~ V_34 ;
F_11 ( V_6 , V_15 , V_24 , V_11 ) ;
return 0 ;
}
static int F_24 ( struct V_10 * V_11 )
{
return F_23 ( V_32 , V_11 ) ;
}
static int F_25 ( struct V_10 * V_11 )
{
return F_23 ( V_33 , V_11 ) ;
}
static int F_26 ( struct V_10 * V_11 )
{
return F_23 ( V_20 , V_11 ) ;
}
static int F_27 ( struct V_10 * V_11 )
{
return F_23 ( V_12 , V_11 ) ;
}
static T_5 void F_28 ( const int V_6 , unsigned long V_23 ,
struct V_10 * V_11 )
{
unsigned long V_24 ;
V_24 = F_15 ( V_6 , V_15 , V_11 ) ;
V_24 |= V_34 ;
V_24 &= ~ V_26 ;
F_11 ( V_6 , V_18 , V_23 , V_11 ) ;
F_11 ( V_6 , V_15 , V_24 , V_11 ) ;
}
static T_5 void F_29 ( const int V_6 ,
unsigned long V_23 , struct V_10 * V_11 )
{
unsigned long V_24 ;
T_4 V_35 = V_23 + F_30 () ;
V_24 = F_15 ( V_6 , V_15 , V_11 ) ;
V_24 |= V_34 ;
V_24 &= ~ V_26 ;
if ( V_6 == V_33 )
F_31 ( V_35 , V_36 ) ;
else if ( V_6 == V_32 )
F_31 ( V_35 , V_37 ) ;
F_11 ( V_6 , V_15 , V_24 , V_11 ) ;
}
static int F_32 ( unsigned long V_23 ,
struct V_10 * V_11 )
{
F_29 ( V_32 , V_23 , V_11 ) ;
return 0 ;
}
static int F_33 ( unsigned long V_23 ,
struct V_10 * V_11 )
{
F_29 ( V_33 , V_23 , V_11 ) ;
return 0 ;
}
static int F_34 ( unsigned long V_23 ,
struct V_10 * V_11 )
{
F_28 ( V_32 , V_23 , V_11 ) ;
return 0 ;
}
static int F_35 ( unsigned long V_23 ,
struct V_10 * V_11 )
{
F_28 ( V_33 , V_23 , V_11 ) ;
return 0 ;
}
static int F_36 ( unsigned long V_23 ,
struct V_10 * V_11 )
{
F_28 ( V_20 , V_23 , V_11 ) ;
return 0 ;
}
static int F_37 ( unsigned long V_23 ,
struct V_10 * V_11 )
{
F_28 ( V_12 , V_23 , V_11 ) ;
return 0 ;
}
static void F_38 ( struct V_10 * V_11 )
{
#ifdef F_39
if ( ! F_40 ( & V_38 ) )
return;
if ( V_39 == V_40 )
V_11 -> F_28 = F_32 ;
else
V_11 -> F_28 = F_33 ;
#endif
}
static void F_41 ( unsigned type ,
struct V_10 * V_11 )
{
V_11 -> V_41 = V_42 ;
if ( type == V_43 ) {
if ( V_44 )
V_11 -> V_41 |= V_45 ;
V_11 -> V_46 = L_1 ;
V_11 -> V_47 = 450 ;
V_11 -> V_48 = F_42 ( F_43 () ) ;
V_11 -> V_30 = V_49 [ V_39 ] ;
switch ( V_39 ) {
case V_40 :
V_11 -> V_50 = F_24 ;
V_11 -> V_51 = F_24 ;
V_11 -> F_28 = F_34 ;
break;
case V_52 :
case V_53 :
case V_54 :
V_11 -> V_50 = F_25 ;
V_11 -> V_51 = F_25 ;
V_11 -> F_28 = F_35 ;
break;
default:
F_44 () ;
}
F_38 ( V_11 ) ;
} else {
V_11 -> V_41 |= V_55 ;
V_11 -> V_46 = L_2 ;
V_11 -> V_47 = 400 ;
V_11 -> V_48 = V_56 ;
if ( V_57 ) {
V_11 -> V_50 = F_26 ;
V_11 -> V_51 = F_26 ;
V_11 -> F_28 =
F_36 ;
} else {
V_11 -> V_50 = F_27 ;
V_11 -> V_51 = F_27 ;
V_11 -> F_28 =
F_37 ;
}
}
V_11 -> V_50 ( V_11 ) ;
F_45 ( V_11 , V_58 , 0xf , 0x7fffffff ) ;
}
static void F_46 ( int V_59 )
{
T_2 V_60 = F_47 () ;
V_60 &= ~ V_61 ;
V_60 |= ( V_59 << V_62 )
| V_63 ;
F_48 ( V_60 ) ;
V_64 |= V_65 ;
#ifdef F_49
V_66 |= V_67 ;
#endif
}
static void F_50 ( void )
{
int V_68 , V_69 ;
V_68 = V_58 / V_70 ;
V_69 = F_51 ( V_68 ) ;
if ( V_69 > 1 && ! ( V_68 & ( 1 << ( V_69 - 2 ) ) ) )
V_69 -- ;
F_46 ( F_52 ( V_69 , 15 ) ) ;
}
static void F_53 ( void )
{
T_2 V_60 = F_47 () ;
V_60 &= ~ ( V_71
| V_72
| V_63
| V_73 ) ;
V_60 |= V_74 ;
F_48 ( V_60 ) ;
}
static bool F_54 ( void )
{
return ( V_39 == V_52 &&
V_49 [ V_53 ] ) ;
}
static T_2 F_55 ( int V_30 )
{
T_2 V_75 = F_56 ( V_30 ) ;
if ( V_75 != V_76 && V_75 != V_77 ) {
F_57 ( L_3 , V_30 ) ;
F_57 ( L_4 ) ;
V_75 = V_77 ;
}
return V_75 ;
}
static int F_58 ( unsigned int V_78 )
{
struct V_10 * V_11 = F_59 ( V_79 ) ;
T_2 V_75 ;
F_41 ( V_43 , V_11 ) ;
V_75 = F_55 ( V_49 [ V_39 ] ) ;
F_60 ( V_49 [ V_39 ] , V_75 ) ;
if ( F_54 () ) {
V_75 = F_55 ( V_49 [ V_53 ] ) ;
F_60 ( V_49 [ V_53 ] , V_75 ) ;
}
F_53 () ;
if ( V_2 )
F_50 () ;
return 0 ;
}
static void
F_61 ( void T_7 * V_80 , struct V_81 * V_82 )
{
if ( V_58 )
return;
if ( ! V_83 ||
F_62 ( V_82 , L_5 , & V_58 ) ) {
if ( V_80 )
V_58 = F_16 ( V_80 + V_84 ) ;
else
V_58 = F_63 () ;
}
if ( V_58 == 0 )
F_57 ( L_6 ) ;
}
static void F_64 ( unsigned type )
{
F_65 ( L_7 ,
type & V_43 ? L_8 : L_9 ,
type == ( V_43 | V_85 ) ? L_10 : L_9 ,
type & V_85 ? L_11 : L_9 ,
( unsigned long ) V_58 / 1000000 ,
( unsigned long ) ( V_58 / 10000 ) % 100 ,
type & V_43 ?
( V_39 == V_40 ) ? L_12 : L_13 :
L_9 ,
type == ( V_43 | V_85 ) ? L_14 : L_9 ,
type & V_85 ?
V_57 ? L_12 : L_13 :
L_9 ) ;
}
T_2 F_66 ( void )
{
return V_58 ;
}
static T_4 F_67 ( void )
{
T_2 V_86 , V_87 , V_88 ;
do {
V_87 = F_16 ( V_89 + V_90 ) ;
V_86 = F_16 ( V_89 + V_91 ) ;
V_88 = F_16 ( V_89 + V_90 ) ;
} while ( V_87 != V_88 );
return ( ( T_4 ) V_87 << 32 ) | V_86 ;
}
static T_4 F_68 ( struct V_92 * V_93 )
{
return F_69 () ;
}
static T_4 F_70 ( const struct V_94 * V_95 )
{
return F_69 () ;
}
struct V_96 * F_71 ( void )
{
return & V_96 ;
}
static void T_1 F_72 ( unsigned type )
{
T_4 V_97 ;
if ( type & V_43 ) {
if ( F_73 ( V_98 ) || V_39 == V_40 )
F_69 = F_30 ;
else
F_69 = V_99 ;
V_100 . V_101 . V_102 = true ;
#ifdef F_39
if ( F_40 ( & V_38 ) )
V_100 . V_101 . V_102 = false ;
#endif
} else {
F_69 = F_67 ;
}
if ( ! V_103 )
V_100 . V_75 |= V_104 ;
V_97 = F_69 () ;
F_74 ( & V_100 , V_58 ) ;
V_94 . V_105 = V_100 . V_105 ;
V_94 . V_106 = V_100 . V_106 ;
F_75 ( & V_96 . V_107 ,
& V_94 , V_97 ) ;
F_76 ( F_69 , 56 , V_58 ) ;
}
static void F_77 ( struct V_10 * V_11 )
{
F_78 ( L_15 ,
V_11 -> V_30 , F_43 () ) ;
F_79 ( V_49 [ V_39 ] ) ;
if ( F_54 () )
F_79 ( V_49 [ V_53 ] ) ;
V_11 -> V_50 ( V_11 ) ;
}
static int F_80 ( unsigned int V_78 )
{
struct V_10 * V_11 = F_59 ( V_79 ) ;
F_77 ( V_11 ) ;
return 0 ;
}
static int F_81 ( struct V_108 * V_109 ,
unsigned long V_110 , void * V_111 )
{
if ( V_110 == V_112 )
V_113 = F_47 () ;
else if ( V_110 == V_114 || V_110 == V_115 )
F_48 ( V_113 ) ;
return V_116 ;
}
static int T_1 F_82 ( void )
{
return F_83 ( & V_117 ) ;
}
static void T_1 F_84 ( void )
{
F_85 ( F_86 ( & V_117 ) ) ;
}
static int T_1 F_82 ( void )
{
return 0 ;
}
static void T_1 F_84 ( void )
{
}
static int T_1 F_87 ( void )
{
int V_118 ;
int V_119 ;
V_79 = F_88 ( struct V_10 ) ;
if ( ! V_79 ) {
V_118 = - V_120 ;
goto V_121;
}
V_119 = V_49 [ V_39 ] ;
switch ( V_39 ) {
case V_40 :
V_118 = F_89 ( V_119 , F_19 ,
L_16 , V_79 ) ;
break;
case V_52 :
case V_53 :
V_118 = F_89 ( V_119 , F_20 ,
L_16 , V_79 ) ;
if ( ! V_118 && V_49 [ V_53 ] ) {
V_119 = V_49 [ V_53 ] ;
V_118 = F_89 ( V_119 , F_20 ,
L_16 , V_79 ) ;
if ( V_118 )
F_90 ( V_49 [ V_52 ] ,
V_79 ) ;
}
break;
case V_54 :
V_118 = F_89 ( V_119 , F_20 ,
L_16 , V_79 ) ;
break;
default:
F_44 () ;
}
if ( V_118 ) {
F_91 ( L_17 ,
V_119 , V_118 ) ;
goto V_122;
}
V_118 = F_82 () ;
if ( V_118 )
goto V_123;
V_118 = F_92 ( V_124 ,
L_18 ,
F_58 , F_80 ) ;
if ( V_118 )
goto V_125;
return 0 ;
V_125:
F_84 () ;
V_123:
F_90 ( V_49 [ V_39 ] , V_79 ) ;
if ( F_54 () )
F_90 ( V_49 [ V_53 ] ,
V_79 ) ;
V_122:
F_93 ( V_79 ) ;
V_121:
return V_118 ;
}
static int T_1 F_94 ( void T_7 * V_16 , unsigned int V_30 )
{
int V_126 ;
T_8 V_127 ;
struct V_13 * V_128 ;
V_128 = F_95 ( sizeof( * V_128 ) , V_129 ) ;
if ( ! V_128 )
return - V_120 ;
V_128 -> V_16 = V_16 ;
V_128 -> V_23 . V_30 = V_30 ;
F_41 ( V_85 , & V_128 -> V_23 ) ;
if ( V_57 )
V_127 = F_22 ;
else
V_127 = F_21 ;
V_126 = F_96 ( V_30 , V_127 , V_130 , L_2 , & V_128 -> V_23 ) ;
if ( V_126 ) {
F_91 ( L_19 ) ;
F_97 ( V_128 ) ;
}
return V_126 ;
}
static bool T_1
F_98 ( int type , const struct V_131 * V_132 )
{
struct V_81 * V_133 ;
bool V_134 = false ;
V_133 = F_99 ( NULL , V_132 ) ;
if ( V_133 && F_100 ( V_133 ) && ! ( V_135 & type ) )
V_134 = true ;
F_101 ( V_133 ) ;
return V_134 ;
}
static int T_1 F_102 ( void )
{
unsigned V_136 = V_43 | V_85 ;
if ( ( V_135 & V_136 ) != V_136 ) {
if ( F_98 ( V_85 , V_137 ) )
return 0 ;
if ( F_98 ( V_43 , V_138 ) )
return 0 ;
}
F_64 ( V_135 ) ;
F_72 ( V_135 ) ;
return F_103 () ;
}
static int T_1 F_104 ( void )
{
int V_126 ;
if ( F_105 () || ! V_49 [ V_40 ] ) {
bool V_139 ;
if ( F_106 () ) {
V_39 = V_54 ;
V_139 = ! ! V_49 [ V_54 ] ;
} else {
V_39 = V_52 ;
V_139 = ( ! ! V_49 [ V_52 ] ||
! ! V_49 [ V_53 ] ) ;
}
if ( ! V_139 ) {
F_57 ( L_20 ) ;
return - V_140 ;
}
}
V_126 = F_87 () ;
if ( V_126 )
return V_126 ;
V_126 = F_102 () ;
if ( V_126 )
return V_126 ;
V_96 . V_141 = V_49 [ V_40 ] ;
return 0 ;
}
static int T_1 F_107 ( struct V_81 * V_82 )
{
int V_142 ;
if ( V_135 & V_43 ) {
F_57 ( L_21 ) ;
return 0 ;
}
V_135 |= V_43 ;
for ( V_142 = V_52 ; V_142 < V_143 ; V_142 ++ )
V_49 [ V_142 ] = F_108 ( V_82 , V_142 ) ;
F_61 ( NULL , V_82 ) ;
V_44 = ! F_109 ( V_82 , L_22 ) ;
#ifdef F_39
for ( V_142 = 0 ; V_142 < F_110 ( V_144 ) ; V_142 ++ ) {
if ( F_109 ( V_82 , V_144 [ V_142 ] . V_145 ) ) {
V_146 = & V_144 [ V_142 ] ;
F_111 ( & V_38 ) ;
F_65 ( L_23 ,
V_146 -> V_145 ) ;
break;
}
}
#endif
if ( F_73 ( V_147 ) &&
F_109 ( V_82 , L_24 ) )
V_39 = V_52 ;
V_103 = F_109 ( V_82 ,
L_25 ) ;
return F_104 () ;
}
static int T_1 F_112 ( struct V_81 * V_82 )
{
struct V_81 * V_148 , * V_149 = NULL ;
void T_7 * V_150 , * V_16 ;
unsigned int V_30 , V_126 = - V_140 ;
T_2 V_151 ;
V_135 |= V_85 ;
V_150 = F_113 ( V_82 , 0 ) ;
if ( ! V_150 ) {
F_91 ( L_26 ) ;
return - V_152 ;
}
V_151 = F_16 ( V_150 + V_153 ) ;
F_114 (np, frame) {
int V_154 ;
T_2 V_155 ;
if ( F_62 ( V_148 , L_27 , & V_154 ) ) {
F_91 ( L_28 ) ;
F_101 ( V_148 ) ;
goto V_121;
}
V_155 = V_156 | V_157 | V_158 |
V_159 | V_160 | V_161 ;
F_13 ( V_155 , V_150 + F_115 ( V_154 ) ) ;
V_155 = F_16 ( V_150 + F_115 ( V_154 ) ) ;
if ( ( V_151 & F_116 ( V_154 ) ) &&
! ( ~ V_155 & ( V_159 | V_161 ) ) ) {
F_101 ( V_149 ) ;
V_149 = V_148 ;
V_57 = true ;
break;
}
if ( ~ V_155 & ( V_157 | V_158 ) )
continue;
F_101 ( V_149 ) ;
V_149 = F_117 ( V_148 ) ;
}
V_126 = - V_152 ;
V_16 = V_89 = F_118 ( V_149 , 0 ,
L_2 ) ;
if ( F_119 ( V_16 ) ) {
F_91 ( L_29 ) ;
goto V_121;
}
if ( V_57 )
V_30 = F_108 ( V_149 , 1 ) ;
else
V_30 = F_108 ( V_149 , 0 ) ;
V_126 = - V_140 ;
if ( ! V_30 ) {
F_91 ( L_30 ,
V_57 ? L_12 : L_13 ) ;
goto V_121;
}
F_61 ( V_16 , V_82 ) ;
V_126 = F_94 ( V_16 , V_30 ) ;
if ( V_126 )
goto V_121;
return F_102 () ;
V_121:
F_120 ( V_150 ) ;
F_101 ( V_149 ) ;
return V_126 ;
}
static int T_1 F_121 ( T_2 V_162 , T_2 V_75 )
{
int V_163 , V_164 ;
if ( ! V_162 )
return 0 ;
V_163 = ( V_75 & V_165 ) ? V_166
: V_167 ;
V_164 = ( V_75 & V_168 ) ? V_169
: V_170 ;
return F_122 ( NULL , V_162 , V_163 , V_164 ) ;
}
static int T_1 F_123 ( struct V_171 * V_172 )
{
struct V_173 * V_174 ;
if ( V_135 & V_43 ) {
F_57 ( L_31 ) ;
return - V_140 ;
}
V_174 = F_124 ( V_172 , struct V_173 , V_175 ) ;
V_135 |= V_43 ;
V_49 [ V_52 ] =
F_121 ( V_174 -> V_176 ,
V_174 -> V_177 ) ;
V_49 [ V_53 ] =
F_121 ( V_174 -> V_178 ,
V_174 -> V_179 ) ;
V_49 [ V_40 ] =
F_121 ( V_174 -> V_180 ,
V_174 -> V_181 ) ;
V_49 [ V_54 ] =
F_121 ( V_174 -> V_182 ,
V_174 -> V_183 ) ;
F_61 ( NULL , NULL ) ;
V_44 = ! ( V_174 -> V_179 & V_184 ) ;
F_104 () ;
return 0 ;
}

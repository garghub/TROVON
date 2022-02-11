static int T_1 F_1 ( char * V_1 )
{
return F_2 ( V_1 , & V_2 ) ;
}
static int T_1 F_3 ( char * V_1 )
{
int V_3 ;
bool V_4 ;
V_3 = F_2 ( V_1 , & V_4 ) ;
if ( V_3 )
return V_3 ;
V_5 = V_4 ;
return 0 ;
}
T_2 F_4 ( void )
{
return F_5 ( V_6 ) ;
}
T_2 F_6 ( void )
{
return F_5 ( V_7 ) ;
}
T_3 F_7 ( void )
{
return F_5 ( V_8 ) ;
}
static T_4
void F_8 ( int V_9 , enum V_10 V_11 , T_2 V_4 ,
struct V_12 * V_13 )
{
if ( V_9 == V_14 ) {
struct V_15 * V_16 = F_9 ( V_13 ) ;
switch ( V_11 ) {
case V_17 :
F_10 ( V_4 , V_16 -> V_18 + V_19 ) ;
break;
case V_20 :
F_10 ( V_4 , V_16 -> V_18 + V_21 ) ;
break;
}
} else if ( V_9 == V_22 ) {
struct V_15 * V_16 = F_9 ( V_13 ) ;
switch ( V_11 ) {
case V_17 :
F_10 ( V_4 , V_16 -> V_18 + V_23 ) ;
break;
case V_20 :
F_10 ( V_4 , V_16 -> V_18 + V_24 ) ;
break;
}
} else {
F_11 ( V_9 , V_11 , V_4 ) ;
}
}
static T_4
T_2 F_12 ( int V_9 , enum V_10 V_11 ,
struct V_12 * V_13 )
{
T_2 V_4 ;
if ( V_9 == V_14 ) {
struct V_15 * V_16 = F_9 ( V_13 ) ;
switch ( V_11 ) {
case V_17 :
V_4 = F_13 ( V_16 -> V_18 + V_19 ) ;
break;
case V_20 :
V_4 = F_13 ( V_16 -> V_18 + V_21 ) ;
break;
}
} else if ( V_9 == V_22 ) {
struct V_15 * V_16 = F_9 ( V_13 ) ;
switch ( V_11 ) {
case V_17 :
V_4 = F_13 ( V_16 -> V_18 + V_23 ) ;
break;
case V_20 :
V_4 = F_13 ( V_16 -> V_18 + V_24 ) ;
break;
}
} else {
V_4 = F_14 ( V_9 , V_11 ) ;
}
return V_4 ;
}
static T_4 T_5 F_15 ( const int V_9 ,
struct V_12 * V_25 )
{
unsigned long V_26 ;
V_26 = F_12 ( V_9 , V_17 , V_25 ) ;
if ( V_26 & V_27 ) {
V_26 |= V_28 ;
F_8 ( V_9 , V_17 , V_26 , V_25 ) ;
V_25 -> V_29 ( V_25 ) ;
return V_30 ;
}
return V_31 ;
}
static T_5 F_16 ( int V_32 , void * V_33 )
{
struct V_12 * V_25 = V_33 ;
return F_15 ( V_34 , V_25 ) ;
}
static T_5 F_17 ( int V_32 , void * V_33 )
{
struct V_12 * V_25 = V_33 ;
return F_15 ( V_35 , V_25 ) ;
}
static T_5 F_18 ( int V_32 , void * V_33 )
{
struct V_12 * V_25 = V_33 ;
return F_15 ( V_14 , V_25 ) ;
}
static T_5 F_19 ( int V_32 , void * V_33 )
{
struct V_12 * V_25 = V_33 ;
return F_15 ( V_22 , V_25 ) ;
}
static T_4 int F_20 ( const int V_9 ,
struct V_12 * V_13 )
{
unsigned long V_26 ;
V_26 = F_12 ( V_9 , V_17 , V_13 ) ;
V_26 &= ~ V_36 ;
F_8 ( V_9 , V_17 , V_26 , V_13 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_13 )
{
return F_20 ( V_34 , V_13 ) ;
}
static int F_22 ( struct V_12 * V_13 )
{
return F_20 ( V_35 , V_13 ) ;
}
static int F_23 ( struct V_12 * V_13 )
{
return F_20 ( V_22 , V_13 ) ;
}
static int F_24 ( struct V_12 * V_13 )
{
return F_20 ( V_14 , V_13 ) ;
}
static T_4 void F_25 ( const int V_9 , unsigned long V_25 ,
struct V_12 * V_13 )
{
unsigned long V_26 ;
V_26 = F_12 ( V_9 , V_17 , V_13 ) ;
V_26 |= V_36 ;
V_26 &= ~ V_28 ;
F_8 ( V_9 , V_20 , V_25 , V_13 ) ;
F_8 ( V_9 , V_17 , V_26 , V_13 ) ;
}
static T_4 void F_26 ( const int V_9 ,
unsigned long V_25 , struct V_12 * V_13 )
{
unsigned long V_26 ;
T_3 V_37 = V_25 + F_27 () ;
V_26 = F_12 ( V_9 , V_17 , V_13 ) ;
V_26 |= V_36 ;
V_26 &= ~ V_28 ;
if ( V_9 == V_35 )
F_28 ( V_37 , V_38 ) ;
else if ( V_9 == V_34 )
F_28 ( V_37 , V_39 ) ;
F_8 ( V_9 , V_17 , V_26 , V_13 ) ;
}
static int F_29 ( unsigned long V_25 ,
struct V_12 * V_13 )
{
F_26 ( V_34 , V_25 , V_13 ) ;
return 0 ;
}
static int F_30 ( unsigned long V_25 ,
struct V_12 * V_13 )
{
F_26 ( V_35 , V_25 , V_13 ) ;
return 0 ;
}
static int F_31 ( unsigned long V_25 ,
struct V_12 * V_13 )
{
F_25 ( V_34 , V_25 , V_13 ) ;
return 0 ;
}
static int F_32 ( unsigned long V_25 ,
struct V_12 * V_13 )
{
F_25 ( V_35 , V_25 , V_13 ) ;
return 0 ;
}
static int F_33 ( unsigned long V_25 ,
struct V_12 * V_13 )
{
F_25 ( V_22 , V_25 , V_13 ) ;
return 0 ;
}
static int F_34 ( unsigned long V_25 ,
struct V_12 * V_13 )
{
F_25 ( V_14 , V_25 , V_13 ) ;
return 0 ;
}
static void F_35 ( struct V_12 * V_13 )
{
#ifdef F_36
if ( ! F_37 ( & V_40 ) )
return;
if ( V_41 == V_42 )
V_13 -> F_25 = F_29 ;
else
V_13 -> F_25 = F_30 ;
#endif
}
static void F_38 ( unsigned type ,
struct V_12 * V_13 )
{
V_13 -> V_43 = V_44 ;
if ( type == V_45 ) {
if ( V_46 )
V_13 -> V_43 |= V_47 ;
V_13 -> V_48 = L_1 ;
V_13 -> V_49 = 450 ;
V_13 -> V_50 = F_39 ( F_40 () ) ;
V_13 -> V_32 = V_51 [ V_41 ] ;
switch ( V_41 ) {
case V_42 :
V_13 -> V_52 = F_21 ;
V_13 -> V_53 = F_21 ;
V_13 -> F_25 = F_31 ;
break;
case V_54 :
case V_55 :
case V_56 :
V_13 -> V_52 = F_22 ;
V_13 -> V_53 = F_22 ;
V_13 -> F_25 = F_32 ;
break;
default:
F_41 () ;
}
F_35 ( V_13 ) ;
} else {
V_13 -> V_43 |= V_57 ;
V_13 -> V_48 = L_2 ;
V_13 -> V_49 = 400 ;
V_13 -> V_50 = V_58 ;
if ( V_59 ) {
V_13 -> V_52 = F_23 ;
V_13 -> V_53 = F_23 ;
V_13 -> F_25 =
F_33 ;
} else {
V_13 -> V_52 = F_24 ;
V_13 -> V_53 = F_24 ;
V_13 -> F_25 =
F_34 ;
}
}
V_13 -> V_52 ( V_13 ) ;
F_42 ( V_13 , V_60 , 0xf , 0x7fffffff ) ;
}
static void F_43 ( int V_61 )
{
T_2 V_62 = F_44 () ;
V_62 &= ~ V_63 ;
V_62 |= ( V_61 << V_64 )
| V_65 ;
F_45 ( V_62 ) ;
V_66 |= V_67 ;
#ifdef F_46
V_68 |= V_69 ;
#endif
}
static void F_47 ( void )
{
int V_70 , V_71 ;
V_70 = V_60 / V_72 ;
V_71 = F_48 ( V_70 ) ;
if ( V_71 > 1 && ! ( V_70 & ( 1 << ( V_71 - 2 ) ) ) )
V_71 -- ;
F_43 ( F_49 ( V_71 , 15 ) ) ;
}
static void F_50 ( void )
{
T_2 V_62 = F_44 () ;
V_62 &= ~ ( V_73
| V_74
| V_65
| V_75 ) ;
V_62 |= V_76 ;
F_45 ( V_62 ) ;
}
static bool F_51 ( void )
{
return ( V_41 == V_54 &&
V_51 [ V_55 ] ) ;
}
static T_2 F_52 ( int V_32 )
{
T_2 V_77 = F_53 ( V_32 ) ;
if ( V_77 != V_78 && V_77 != V_79 ) {
F_54 ( L_3 , V_32 ) ;
F_54 ( L_4 ) ;
V_77 = V_79 ;
}
return V_77 ;
}
static int F_55 ( unsigned int V_80 )
{
struct V_12 * V_13 = F_56 ( V_81 ) ;
T_2 V_77 ;
F_38 ( V_45 , V_13 ) ;
V_77 = F_52 ( V_51 [ V_41 ] ) ;
F_57 ( V_51 [ V_41 ] , V_77 ) ;
if ( F_51 () ) {
V_77 = F_52 ( V_51 [ V_55 ] ) ;
F_57 ( V_51 [ V_55 ] , V_77 ) ;
}
F_50 () ;
if ( V_2 )
F_47 () ;
return 0 ;
}
static void
F_58 ( void T_6 * V_82 , struct V_83 * V_84 )
{
if ( V_60 )
return;
if ( ! V_85 ||
F_59 ( V_84 , L_5 , & V_60 ) ) {
if ( V_82 )
V_60 = F_13 ( V_82 + V_86 ) ;
else
V_60 = F_60 () ;
}
if ( V_60 == 0 )
F_54 ( L_6 ) ;
}
static void F_61 ( unsigned type )
{
F_62 ( L_7 ,
type & V_45 ? L_8 : L_9 ,
type == ( V_45 | V_87 ) ? L_10 : L_9 ,
type & V_87 ? L_11 : L_9 ,
( unsigned long ) V_60 / 1000000 ,
( unsigned long ) ( V_60 / 10000 ) % 100 ,
type & V_45 ?
( V_41 == V_42 ) ? L_12 : L_13 :
L_9 ,
type == ( V_45 | V_87 ) ? L_14 : L_9 ,
type & V_87 ?
V_59 ? L_12 : L_13 :
L_9 ) ;
}
T_2 F_63 ( void )
{
return V_60 ;
}
static T_3 F_64 ( void )
{
T_2 V_88 , V_89 , V_90 ;
do {
V_89 = F_13 ( V_91 + V_92 ) ;
V_88 = F_13 ( V_91 + V_93 ) ;
V_90 = F_13 ( V_91 + V_92 ) ;
} while ( V_89 != V_90 );
return ( ( T_3 ) V_89 << 32 ) | V_88 ;
}
static T_7 F_65 ( struct V_94 * V_95 )
{
return F_66 () ;
}
static T_7 F_67 ( const struct V_96 * V_97 )
{
return F_66 () ;
}
struct V_98 * F_68 ( void )
{
return & V_98 ;
}
static void T_1 F_69 ( unsigned type )
{
T_3 V_99 ;
if ( type & V_45 ) {
if ( F_70 ( V_100 ) || V_41 == V_42 )
F_66 = F_27 ;
else
F_66 = V_101 ;
V_102 . V_103 . V_104 = true ;
#ifdef F_36
if ( F_37 ( & V_40 ) )
V_102 . V_103 . V_104 = false ;
#endif
} else {
F_66 = F_64 ;
}
V_99 = F_66 () ;
F_71 ( & V_102 , V_60 ) ;
V_96 . V_105 = V_102 . V_105 ;
V_96 . V_106 = V_102 . V_106 ;
F_72 ( & V_98 . V_107 ,
& V_96 , V_99 ) ;
F_73 ( F_66 , 56 , V_60 ) ;
}
static void F_74 ( struct V_12 * V_13 )
{
F_75 ( L_15 ,
V_13 -> V_32 , F_40 () ) ;
F_76 ( V_51 [ V_41 ] ) ;
if ( F_51 () )
F_76 ( V_51 [ V_55 ] ) ;
V_13 -> V_52 ( V_13 ) ;
}
static int F_77 ( unsigned int V_80 )
{
struct V_12 * V_13 = F_56 ( V_81 ) ;
F_74 ( V_13 ) ;
return 0 ;
}
static int F_78 ( struct V_108 * V_109 ,
unsigned long V_110 , void * V_111 )
{
if ( V_110 == V_112 )
V_113 = F_44 () ;
else if ( V_110 == V_114 || V_110 == V_115 )
F_45 ( V_113 ) ;
return V_116 ;
}
static int T_1 F_79 ( void )
{
return F_80 ( & V_117 ) ;
}
static void T_1 F_81 ( void )
{
F_82 ( F_83 ( & V_117 ) ) ;
}
static int T_1 F_79 ( void )
{
return 0 ;
}
static void T_1 F_81 ( void )
{
}
static int T_1 F_84 ( void )
{
int V_118 ;
int V_119 ;
V_81 = F_85 ( struct V_12 ) ;
if ( ! V_81 ) {
V_118 = - V_120 ;
goto V_121;
}
V_119 = V_51 [ V_41 ] ;
switch ( V_41 ) {
case V_42 :
V_118 = F_86 ( V_119 , F_16 ,
L_16 , V_81 ) ;
break;
case V_54 :
case V_55 :
V_118 = F_86 ( V_119 , F_17 ,
L_16 , V_81 ) ;
if ( ! V_118 && V_51 [ V_55 ] ) {
V_119 = V_51 [ V_55 ] ;
V_118 = F_86 ( V_119 , F_17 ,
L_16 , V_81 ) ;
if ( V_118 )
F_87 ( V_51 [ V_54 ] ,
V_81 ) ;
}
break;
case V_56 :
V_118 = F_86 ( V_119 , F_17 ,
L_16 , V_81 ) ;
break;
default:
F_41 () ;
}
if ( V_118 ) {
F_88 ( L_17 ,
V_119 , V_118 ) ;
goto V_122;
}
V_118 = F_79 () ;
if ( V_118 )
goto V_123;
V_118 = F_89 ( V_124 ,
L_18 ,
F_55 , F_77 ) ;
if ( V_118 )
goto V_125;
return 0 ;
V_125:
F_81 () ;
V_123:
F_87 ( V_51 [ V_41 ] , V_81 ) ;
if ( F_51 () )
F_87 ( V_51 [ V_55 ] ,
V_81 ) ;
V_122:
F_90 ( V_81 ) ;
V_121:
return V_118 ;
}
static int T_1 F_91 ( void T_6 * V_18 , unsigned int V_32 )
{
int V_3 ;
T_8 V_126 ;
struct V_15 * V_127 ;
V_127 = F_92 ( sizeof( * V_127 ) , V_128 ) ;
if ( ! V_127 )
return - V_120 ;
V_127 -> V_18 = V_18 ;
V_127 -> V_25 . V_32 = V_32 ;
F_38 ( V_87 , & V_127 -> V_25 ) ;
if ( V_59 )
V_126 = F_19 ;
else
V_126 = F_18 ;
V_3 = F_93 ( V_32 , V_126 , V_129 , L_2 , & V_127 -> V_25 ) ;
if ( V_3 ) {
F_88 ( L_19 ) ;
F_94 ( V_127 ) ;
}
return V_3 ;
}
static bool T_1
F_95 ( int type , const struct V_130 * V_131 )
{
struct V_83 * V_132 ;
bool V_133 = false ;
V_132 = F_96 ( NULL , V_131 ) ;
if ( V_132 && F_97 ( V_132 ) && ! ( V_134 & type ) )
V_133 = true ;
F_98 ( V_132 ) ;
return V_133 ;
}
static int T_1 F_99 ( void )
{
unsigned V_135 = V_45 | V_87 ;
if ( ( V_134 & V_135 ) != V_135 ) {
if ( F_95 ( V_87 , V_136 ) )
return 0 ;
if ( F_95 ( V_45 , V_137 ) )
return 0 ;
}
F_61 ( V_134 ) ;
F_69 ( V_134 ) ;
return F_100 () ;
}
static int T_1 F_101 ( void )
{
int V_3 ;
if ( F_102 () || ! V_51 [ V_42 ] ) {
bool V_138 ;
if ( F_103 () ) {
V_41 = V_56 ;
V_138 = ! ! V_51 [ V_56 ] ;
} else {
V_41 = V_54 ;
V_138 = ( ! ! V_51 [ V_54 ] ||
! ! V_51 [ V_55 ] ) ;
}
if ( ! V_138 ) {
F_54 ( L_20 ) ;
return - V_139 ;
}
}
V_3 = F_84 () ;
if ( V_3 )
return V_3 ;
V_3 = F_99 () ;
if ( V_3 )
return V_3 ;
V_98 . V_140 = V_51 [ V_42 ] ;
return 0 ;
}
static int T_1 F_104 ( struct V_83 * V_84 )
{
int V_141 ;
if ( V_134 & V_45 ) {
F_54 ( L_21 ) ;
return 0 ;
}
V_134 |= V_45 ;
for ( V_141 = V_54 ; V_141 < V_142 ; V_141 ++ )
V_51 [ V_141 ] = F_105 ( V_84 , V_141 ) ;
F_58 ( NULL , V_84 ) ;
V_46 = ! F_106 ( V_84 , L_22 ) ;
#ifdef F_36
if ( V_5 < 0 )
V_5 = F_106 ( V_84 , L_23 ) ;
if ( V_5 ) {
F_107 ( & V_40 ) ;
F_62 ( L_24 ) ;
}
#endif
if ( F_70 ( V_143 ) &&
F_106 ( V_84 , L_25 ) )
V_41 = V_54 ;
return F_101 () ;
}
static int T_1 F_108 ( struct V_83 * V_84 )
{
struct V_83 * V_144 , * V_145 = NULL ;
void T_6 * V_146 , * V_18 ;
unsigned int V_32 , V_3 = - V_139 ;
T_2 V_147 ;
V_134 |= V_87 ;
V_146 = F_109 ( V_84 , 0 ) ;
if ( ! V_146 ) {
F_88 ( L_26 ) ;
return - V_148 ;
}
V_147 = F_13 ( V_146 + V_149 ) ;
F_110 (np, frame) {
int V_150 ;
T_2 V_151 ;
if ( F_59 ( V_144 , L_27 , & V_150 ) ) {
F_88 ( L_28 ) ;
F_98 ( V_144 ) ;
goto V_121;
}
V_151 = V_152 | V_153 | V_154 |
V_155 | V_156 | V_157 ;
F_10 ( V_151 , V_146 + F_111 ( V_150 ) ) ;
V_151 = F_13 ( V_146 + F_111 ( V_150 ) ) ;
if ( ( V_147 & F_112 ( V_150 ) ) &&
! ( ~ V_151 & ( V_155 | V_157 ) ) ) {
F_98 ( V_145 ) ;
V_145 = V_144 ;
V_59 = true ;
break;
}
if ( ~ V_151 & ( V_153 | V_154 ) )
continue;
F_98 ( V_145 ) ;
V_145 = F_113 ( V_144 ) ;
}
V_3 = - V_148 ;
V_18 = V_91 = F_109 ( V_145 , 0 ) ;
if ( ! V_18 ) {
F_88 ( L_29 ) ;
goto V_121;
}
if ( V_59 )
V_32 = F_105 ( V_145 , 1 ) ;
else
V_32 = F_105 ( V_145 , 0 ) ;
V_3 = - V_139 ;
if ( ! V_32 ) {
F_88 ( L_30 ,
V_59 ? L_12 : L_13 ) ;
goto V_121;
}
F_58 ( V_18 , V_84 ) ;
V_3 = F_91 ( V_18 , V_32 ) ;
if ( V_3 )
goto V_121;
return F_99 () ;
V_121:
F_114 ( V_146 ) ;
F_98 ( V_145 ) ;
return V_3 ;
}
static int T_1 F_115 ( T_2 V_158 , T_2 V_77 )
{
int V_159 , V_160 ;
if ( ! V_158 )
return 0 ;
V_159 = ( V_77 & V_161 ) ? V_162
: V_163 ;
V_160 = ( V_77 & V_164 ) ? V_165
: V_166 ;
return F_116 ( NULL , V_158 , V_159 , V_160 ) ;
}
static int T_1 F_117 ( struct V_167 * V_168 )
{
struct V_169 * V_170 ;
if ( V_134 & V_45 ) {
F_54 ( L_31 ) ;
return - V_139 ;
}
V_170 = F_118 ( V_168 , struct V_169 , V_171 ) ;
V_134 |= V_45 ;
V_51 [ V_54 ] =
F_115 ( V_170 -> V_172 ,
V_170 -> V_173 ) ;
V_51 [ V_55 ] =
F_115 ( V_170 -> V_174 ,
V_170 -> V_175 ) ;
V_51 [ V_42 ] =
F_115 ( V_170 -> V_176 ,
V_170 -> V_177 ) ;
V_51 [ V_56 ] =
F_115 ( V_170 -> V_178 ,
V_170 -> V_179 ) ;
F_58 ( NULL , NULL ) ;
V_46 = ! ( V_170 -> V_175 & V_180 ) ;
F_101 () ;
return 0 ;
}

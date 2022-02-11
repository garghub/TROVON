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
static T_2 T_4 F_10 ( const int V_3 ,
struct V_7 * V_20 )
{
unsigned long V_21 ;
V_21 = F_7 ( V_3 , V_12 , V_20 ) ;
if ( V_21 & V_22 ) {
V_21 |= V_23 ;
F_3 ( V_3 , V_12 , V_21 , V_20 ) ;
V_20 -> V_24 ( V_20 ) ;
return V_25 ;
}
return V_26 ;
}
static T_4 F_11 ( int V_27 , void * V_28 )
{
struct V_7 * V_20 = V_28 ;
return F_10 ( V_29 , V_20 ) ;
}
static T_4 F_12 ( int V_27 , void * V_28 )
{
struct V_7 * V_20 = V_28 ;
return F_10 ( V_30 , V_20 ) ;
}
static T_4 F_13 ( int V_27 , void * V_28 )
{
struct V_7 * V_20 = V_28 ;
return F_10 ( V_9 , V_20 ) ;
}
static T_4 F_14 ( int V_27 , void * V_28 )
{
struct V_7 * V_20 = V_28 ;
return F_10 ( V_17 , V_20 ) ;
}
static T_2 int F_15 ( const int V_3 ,
struct V_7 * V_8 )
{
unsigned long V_21 ;
V_21 = F_7 ( V_3 , V_12 , V_8 ) ;
V_21 &= ~ V_31 ;
F_3 ( V_3 , V_12 , V_21 , V_8 ) ;
return 0 ;
}
static int F_16 ( struct V_7 * V_8 )
{
return F_15 ( V_29 , V_8 ) ;
}
static int F_17 ( struct V_7 * V_8 )
{
return F_15 ( V_30 , V_8 ) ;
}
static int F_18 ( struct V_7 * V_8 )
{
return F_15 ( V_17 , V_8 ) ;
}
static int F_19 ( struct V_7 * V_8 )
{
return F_15 ( V_9 , V_8 ) ;
}
static T_2 void F_20 ( const int V_3 , unsigned long V_20 ,
struct V_7 * V_8 )
{
unsigned long V_21 ;
V_21 = F_7 ( V_3 , V_12 , V_8 ) ;
V_21 |= V_31 ;
V_21 &= ~ V_23 ;
F_3 ( V_3 , V_15 , V_20 , V_8 ) ;
F_3 ( V_3 , V_12 , V_21 , V_8 ) ;
}
static int F_21 ( unsigned long V_20 ,
struct V_7 * V_8 )
{
F_20 ( V_29 , V_20 , V_8 ) ;
return 0 ;
}
static int F_22 ( unsigned long V_20 ,
struct V_7 * V_8 )
{
F_20 ( V_30 , V_20 , V_8 ) ;
return 0 ;
}
static int F_23 ( unsigned long V_20 ,
struct V_7 * V_8 )
{
F_20 ( V_17 , V_20 , V_8 ) ;
return 0 ;
}
static int F_24 ( unsigned long V_20 ,
struct V_7 * V_8 )
{
F_20 ( V_9 , V_20 , V_8 ) ;
return 0 ;
}
static void F_25 ( unsigned type ,
struct V_7 * V_8 )
{
V_8 -> V_32 = V_33 ;
if ( type == V_34 ) {
if ( V_35 )
V_8 -> V_32 |= V_36 ;
V_8 -> V_37 = L_1 ;
V_8 -> V_38 = 450 ;
V_8 -> V_39 = F_26 ( F_27 () ) ;
V_8 -> V_27 = V_40 [ V_41 ] ;
switch ( V_41 ) {
case V_42 :
V_8 -> V_43 = F_16 ;
V_8 -> V_44 = F_16 ;
V_8 -> F_20 = F_21 ;
break;
case V_45 :
case V_46 :
case V_47 :
V_8 -> V_43 = F_17 ;
V_8 -> V_44 = F_17 ;
V_8 -> F_20 = F_22 ;
break;
default:
F_28 () ;
}
} else {
V_8 -> V_32 |= V_48 ;
V_8 -> V_37 = L_2 ;
V_8 -> V_38 = 400 ;
V_8 -> V_39 = V_49 ;
if ( V_50 ) {
V_8 -> V_43 = F_18 ;
V_8 -> V_44 = F_18 ;
V_8 -> F_20 =
F_23 ;
} else {
V_8 -> V_43 = F_19 ;
V_8 -> V_44 = F_19 ;
V_8 -> F_20 =
F_24 ;
}
}
V_8 -> V_43 ( V_8 ) ;
F_29 ( V_8 , V_51 , 0xf , 0x7fffffff ) ;
}
static void F_30 ( int V_52 )
{
T_3 V_53 = F_31 () ;
V_53 &= ~ V_54 ;
V_53 |= ( V_52 << V_55 )
| V_56 ;
F_32 ( V_53 ) ;
V_57 |= V_58 ;
#ifdef F_33
V_59 |= V_60 ;
#endif
}
static void F_34 ( void )
{
int V_61 , V_62 ;
V_61 = V_51 / V_63 ;
V_62 = F_35 ( V_61 ) ;
if ( V_62 > 1 && ! ( V_61 & ( 1 << ( V_62 - 2 ) ) ) )
V_62 -- ;
F_30 ( F_36 ( V_62 , 15 ) ) ;
}
static void F_37 ( void )
{
T_3 V_53 = F_31 () ;
V_53 &= ~ ( V_64
| V_65
| V_56
| V_66 ) ;
V_53 |= V_67 ;
F_32 ( V_53 ) ;
}
static bool F_38 ( void )
{
return ( V_41 == V_45 &&
V_40 [ V_46 ] ) ;
}
static T_3 F_39 ( int V_27 )
{
T_3 V_68 = F_40 ( V_27 ) ;
if ( V_68 != V_69 && V_68 != V_70 ) {
F_41 ( L_3 , V_27 ) ;
F_41 ( L_4 ) ;
V_68 = V_70 ;
}
return V_68 ;
}
static int F_42 ( unsigned int V_71 )
{
struct V_7 * V_8 = F_43 ( V_72 ) ;
T_3 V_68 ;
F_25 ( V_34 , V_8 ) ;
V_68 = F_39 ( V_40 [ V_41 ] ) ;
F_44 ( V_40 [ V_41 ] , V_68 ) ;
if ( F_38 () ) {
V_68 = F_39 ( V_40 [ V_46 ] ) ;
F_44 ( V_40 [ V_46 ] , V_68 ) ;
}
F_37 () ;
if ( V_2 )
F_34 () ;
return 0 ;
}
static void
F_45 ( void T_5 * V_73 , struct V_74 * V_75 )
{
if ( V_51 )
return;
if ( ! V_76 ||
F_46 ( V_75 , L_5 , & V_51 ) ) {
if ( V_73 )
V_51 = F_8 ( V_73 + V_77 ) ;
else
V_51 = F_47 () ;
}
if ( V_51 == 0 )
F_41 ( L_6 ) ;
}
static void F_48 ( unsigned type )
{
F_49 ( L_7 ,
type & V_34 ? L_8 : L_9 ,
type == ( V_34 | V_78 ) ? L_10 : L_9 ,
type & V_78 ? L_11 : L_9 ,
( unsigned long ) V_51 / 1000000 ,
( unsigned long ) ( V_51 / 10000 ) % 100 ,
type & V_34 ?
( V_41 == V_42 ) ? L_12 : L_13 :
L_9 ,
type == ( V_34 | V_78 ) ? L_14 : L_9 ,
type & V_78 ?
V_50 ? L_12 : L_13 :
L_9 ) ;
}
T_3 F_50 ( void )
{
return V_51 ;
}
static T_6 F_51 ( void )
{
T_3 V_79 , V_80 , V_81 ;
do {
V_80 = F_8 ( V_82 + V_83 ) ;
V_79 = F_8 ( V_82 + V_84 ) ;
V_81 = F_8 ( V_82 + V_83 ) ;
} while ( V_80 != V_81 );
return ( ( T_6 ) V_80 << 32 ) | V_79 ;
}
static T_7 F_52 ( struct V_85 * V_86 )
{
return F_53 () ;
}
static T_7 F_54 ( const struct V_87 * V_88 )
{
return F_53 () ;
}
struct V_89 * F_55 ( void )
{
return & V_89 ;
}
static void T_1 F_56 ( unsigned type )
{
T_6 V_90 ;
if ( type & V_34 ) {
if ( F_57 ( V_91 ) || V_41 == V_42 )
F_53 = V_92 ;
else
F_53 = V_93 ;
} else {
F_53 = F_51 ;
V_94 . V_37 = L_15 ;
}
V_90 = F_53 () ;
F_58 ( & V_94 , V_51 ) ;
V_87 . V_95 = V_94 . V_95 ;
V_87 . V_96 = V_94 . V_96 ;
F_59 ( & V_89 . V_97 ,
& V_87 , V_90 ) ;
F_60 ( F_53 , 56 , V_51 ) ;
}
static void F_61 ( struct V_7 * V_8 )
{
F_62 ( L_16 ,
V_8 -> V_27 , F_27 () ) ;
F_63 ( V_40 [ V_41 ] ) ;
if ( F_38 () )
F_63 ( V_40 [ V_46 ] ) ;
V_8 -> V_43 ( V_8 ) ;
}
static int F_64 ( unsigned int V_71 )
{
struct V_7 * V_8 = F_43 ( V_72 ) ;
F_61 ( V_8 ) ;
return 0 ;
}
static int F_65 ( struct V_98 * V_99 ,
unsigned long V_100 , void * V_101 )
{
if ( V_100 == V_102 )
V_103 = F_31 () ;
else if ( V_100 == V_104 || V_100 == V_105 )
F_32 ( V_103 ) ;
return V_106 ;
}
static int T_1 F_66 ( void )
{
return F_67 ( & V_107 ) ;
}
static void T_1 F_68 ( void )
{
F_69 ( F_70 ( & V_107 ) ) ;
}
static int T_1 F_66 ( void )
{
return 0 ;
}
static void T_1 F_68 ( void )
{
}
static int T_1 F_71 ( void )
{
int V_108 ;
int V_109 ;
V_72 = F_72 ( struct V_7 ) ;
if ( ! V_72 ) {
V_108 = - V_110 ;
goto V_111;
}
V_109 = V_40 [ V_41 ] ;
switch ( V_41 ) {
case V_42 :
V_108 = F_73 ( V_109 , F_11 ,
L_17 , V_72 ) ;
break;
case V_45 :
case V_46 :
V_108 = F_73 ( V_109 , F_12 ,
L_17 , V_72 ) ;
if ( ! V_108 && V_40 [ V_46 ] ) {
V_109 = V_40 [ V_46 ] ;
V_108 = F_73 ( V_109 , F_12 ,
L_17 , V_72 ) ;
if ( V_108 )
F_74 ( V_40 [ V_45 ] ,
V_72 ) ;
}
break;
case V_47 :
V_108 = F_73 ( V_109 , F_12 ,
L_17 , V_72 ) ;
break;
default:
F_28 () ;
}
if ( V_108 ) {
F_75 ( L_18 ,
V_109 , V_108 ) ;
goto V_112;
}
V_108 = F_66 () ;
if ( V_108 )
goto V_113;
V_108 = F_76 ( V_114 ,
L_19 ,
F_42 , F_64 ) ;
if ( V_108 )
goto V_115;
return 0 ;
V_115:
F_68 () ;
V_113:
F_74 ( V_40 [ V_41 ] , V_72 ) ;
if ( F_38 () )
F_74 ( V_40 [ V_46 ] ,
V_72 ) ;
V_112:
F_77 ( V_72 ) ;
V_111:
return V_108 ;
}
static int T_1 F_78 ( void T_5 * V_13 , unsigned int V_27 )
{
int V_116 ;
T_8 V_117 ;
struct V_10 * V_118 ;
V_118 = F_79 ( sizeof( * V_118 ) , V_119 ) ;
if ( ! V_118 )
return - V_110 ;
V_118 -> V_13 = V_13 ;
V_118 -> V_20 . V_27 = V_27 ;
F_25 ( V_78 , & V_118 -> V_20 ) ;
if ( V_50 )
V_117 = F_14 ;
else
V_117 = F_13 ;
V_116 = F_80 ( V_27 , V_117 , V_120 , L_2 , & V_118 -> V_20 ) ;
if ( V_116 ) {
F_75 ( L_20 ) ;
F_81 ( V_118 ) ;
}
return V_116 ;
}
static bool T_1
F_82 ( int type , const struct V_121 * V_122 )
{
struct V_74 * V_123 ;
bool V_124 = false ;
V_123 = F_83 ( NULL , V_122 ) ;
if ( V_123 && F_84 ( V_123 ) && ! ( V_125 & type ) )
V_124 = true ;
F_85 ( V_123 ) ;
return V_124 ;
}
static int T_1 F_86 ( void )
{
unsigned V_126 = V_34 | V_78 ;
if ( ( V_125 & V_126 ) != V_126 ) {
if ( F_82 ( V_78 , V_127 ) )
return 0 ;
if ( F_82 ( V_34 , V_128 ) )
return 0 ;
}
F_48 ( V_125 ) ;
F_56 ( V_125 ) ;
return F_87 () ;
}
static int T_1 F_88 ( void )
{
int V_116 ;
if ( F_89 () || ! V_40 [ V_42 ] ) {
bool V_129 ;
if ( F_90 () ) {
V_41 = V_47 ;
V_129 = ! ! V_40 [ V_47 ] ;
} else {
V_41 = V_45 ;
V_129 = ( ! ! V_40 [ V_45 ] ||
! ! V_40 [ V_46 ] ) ;
}
if ( ! V_129 ) {
F_41 ( L_21 ) ;
return - V_130 ;
}
}
V_116 = F_71 () ;
if ( V_116 )
return V_116 ;
V_116 = F_86 () ;
if ( V_116 )
return V_116 ;
V_89 . V_131 = V_40 [ V_42 ] ;
return 0 ;
}
static int T_1 F_91 ( struct V_74 * V_75 )
{
int V_132 ;
if ( V_125 & V_34 ) {
F_41 ( L_22 ) ;
return 0 ;
}
V_125 |= V_34 ;
for ( V_132 = V_45 ; V_132 < V_133 ; V_132 ++ )
V_40 [ V_132 ] = F_92 ( V_75 , V_132 ) ;
F_45 ( NULL , V_75 ) ;
V_35 = ! F_93 ( V_75 , L_23 ) ;
if ( F_57 ( V_134 ) &&
F_93 ( V_75 , L_24 ) )
V_41 = V_45 ;
return F_88 () ;
}
static int T_1 F_94 ( struct V_74 * V_75 )
{
struct V_74 * V_135 , * V_136 = NULL ;
void T_5 * V_137 , * V_13 ;
unsigned int V_27 , V_116 = - V_130 ;
T_3 V_138 ;
V_125 |= V_78 ;
V_137 = F_95 ( V_75 , 0 ) ;
if ( ! V_137 ) {
F_75 ( L_25 ) ;
return - V_139 ;
}
V_138 = F_8 ( V_137 + V_140 ) ;
F_96 (np, frame) {
int V_141 ;
T_3 V_142 ;
if ( F_46 ( V_135 , L_26 , & V_141 ) ) {
F_75 ( L_27 ) ;
F_85 ( V_135 ) ;
goto V_111;
}
V_142 = V_143 | V_144 | V_145 |
V_146 | V_147 | V_148 ;
F_5 ( V_142 , V_137 + F_97 ( V_141 ) ) ;
V_142 = F_8 ( V_137 + F_97 ( V_141 ) ) ;
if ( ( V_138 & F_98 ( V_141 ) ) &&
! ( ~ V_142 & ( V_146 | V_148 ) ) ) {
F_85 ( V_136 ) ;
V_136 = V_135 ;
V_50 = true ;
break;
}
if ( ~ V_142 & ( V_144 | V_145 ) )
continue;
F_85 ( V_136 ) ;
V_136 = F_99 ( V_135 ) ;
}
V_116 = - V_139 ;
V_13 = V_82 = F_95 ( V_136 , 0 ) ;
if ( ! V_13 ) {
F_75 ( L_28 ) ;
goto V_111;
}
if ( V_50 )
V_27 = F_92 ( V_136 , 1 ) ;
else
V_27 = F_92 ( V_136 , 0 ) ;
V_116 = - V_130 ;
if ( ! V_27 ) {
F_75 ( L_29 ,
V_50 ? L_12 : L_13 ) ;
goto V_111;
}
F_45 ( V_13 , V_75 ) ;
V_116 = F_78 ( V_13 , V_27 ) ;
if ( V_116 )
goto V_111;
return F_86 () ;
V_111:
F_100 ( V_137 ) ;
F_85 ( V_136 ) ;
return V_116 ;
}
static int T_1 F_101 ( T_3 V_149 , T_3 V_68 )
{
int V_150 , V_151 ;
if ( ! V_149 )
return 0 ;
V_150 = ( V_68 & V_152 ) ? V_153
: V_154 ;
V_151 = ( V_68 & V_155 ) ? V_156
: V_157 ;
return F_102 ( NULL , V_149 , V_150 , V_151 ) ;
}
static int T_1 F_103 ( struct V_158 * V_159 )
{
struct V_160 * V_161 ;
if ( V_125 & V_34 ) {
F_41 ( L_30 ) ;
return - V_130 ;
}
V_161 = F_104 ( V_159 , struct V_160 , V_162 ) ;
V_125 |= V_34 ;
V_40 [ V_45 ] =
F_101 ( V_161 -> V_163 ,
V_161 -> V_164 ) ;
V_40 [ V_46 ] =
F_101 ( V_161 -> V_165 ,
V_161 -> V_166 ) ;
V_40 [ V_42 ] =
F_101 ( V_161 -> V_167 ,
V_161 -> V_168 ) ;
V_40 [ V_47 ] =
F_101 ( V_161 -> V_169 ,
V_161 -> V_170 ) ;
F_45 ( NULL , NULL ) ;
V_35 = ! ( V_161 -> V_166 & V_171 ) ;
F_88 () ;
return 0 ;
}

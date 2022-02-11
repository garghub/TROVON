static T_1
void F_1 ( int V_1 , enum V_2 V_3 , T_2 V_4 ,
struct V_5 * V_6 )
{
if ( V_1 == V_7 ) {
struct V_8 * V_9 = F_2 ( V_6 ) ;
switch ( V_3 ) {
case V_10 :
F_3 ( V_4 , V_9 -> V_11 + V_12 ) ;
break;
case V_13 :
F_3 ( V_4 , V_9 -> V_11 + V_14 ) ;
break;
}
} else if ( V_1 == V_15 ) {
struct V_8 * V_9 = F_2 ( V_6 ) ;
switch ( V_3 ) {
case V_10 :
F_3 ( V_4 , V_9 -> V_11 + V_16 ) ;
break;
case V_13 :
F_3 ( V_4 , V_9 -> V_11 + V_17 ) ;
break;
}
} else {
F_4 ( V_1 , V_3 , V_4 ) ;
}
}
static T_1
T_2 F_5 ( int V_1 , enum V_2 V_3 ,
struct V_5 * V_6 )
{
T_2 V_4 ;
if ( V_1 == V_7 ) {
struct V_8 * V_9 = F_2 ( V_6 ) ;
switch ( V_3 ) {
case V_10 :
V_4 = F_6 ( V_9 -> V_11 + V_12 ) ;
break;
case V_13 :
V_4 = F_6 ( V_9 -> V_11 + V_14 ) ;
break;
}
} else if ( V_1 == V_15 ) {
struct V_8 * V_9 = F_2 ( V_6 ) ;
switch ( V_3 ) {
case V_10 :
V_4 = F_6 ( V_9 -> V_11 + V_16 ) ;
break;
case V_13 :
V_4 = F_6 ( V_9 -> V_11 + V_17 ) ;
break;
}
} else {
V_4 = F_7 ( V_1 , V_3 ) ;
}
return V_4 ;
}
static T_1 T_3 F_8 ( const int V_1 ,
struct V_5 * V_18 )
{
unsigned long V_19 ;
V_19 = F_5 ( V_1 , V_10 , V_18 ) ;
if ( V_19 & V_20 ) {
V_19 |= V_21 ;
F_1 ( V_1 , V_10 , V_19 , V_18 ) ;
V_18 -> V_22 ( V_18 ) ;
return V_23 ;
}
return V_24 ;
}
static T_3 F_9 ( int V_25 , void * V_26 )
{
struct V_5 * V_18 = V_26 ;
return F_8 ( V_27 , V_18 ) ;
}
static T_3 F_10 ( int V_25 , void * V_26 )
{
struct V_5 * V_18 = V_26 ;
return F_8 ( V_28 , V_18 ) ;
}
static T_3 F_11 ( int V_25 , void * V_26 )
{
struct V_5 * V_18 = V_26 ;
return F_8 ( V_7 , V_18 ) ;
}
static T_3 F_12 ( int V_25 , void * V_26 )
{
struct V_5 * V_18 = V_26 ;
return F_8 ( V_15 , V_18 ) ;
}
static T_1 int F_13 ( const int V_1 ,
struct V_5 * V_6 )
{
unsigned long V_19 ;
V_19 = F_5 ( V_1 , V_10 , V_6 ) ;
V_19 &= ~ V_29 ;
F_1 ( V_1 , V_10 , V_19 , V_6 ) ;
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
return F_13 ( V_27 , V_6 ) ;
}
static int F_15 ( struct V_5 * V_6 )
{
return F_13 ( V_28 , V_6 ) ;
}
static int F_16 ( struct V_5 * V_6 )
{
return F_13 ( V_15 , V_6 ) ;
}
static int F_17 ( struct V_5 * V_6 )
{
return F_13 ( V_7 , V_6 ) ;
}
static T_1 void F_18 ( const int V_1 , unsigned long V_18 ,
struct V_5 * V_6 )
{
unsigned long V_19 ;
V_19 = F_5 ( V_1 , V_10 , V_6 ) ;
V_19 |= V_29 ;
V_19 &= ~ V_21 ;
F_1 ( V_1 , V_13 , V_18 , V_6 ) ;
F_1 ( V_1 , V_10 , V_19 , V_6 ) ;
}
static int F_19 ( unsigned long V_18 ,
struct V_5 * V_6 )
{
F_18 ( V_27 , V_18 , V_6 ) ;
return 0 ;
}
static int F_20 ( unsigned long V_18 ,
struct V_5 * V_6 )
{
F_18 ( V_28 , V_18 , V_6 ) ;
return 0 ;
}
static int F_21 ( unsigned long V_18 ,
struct V_5 * V_6 )
{
F_18 ( V_15 , V_18 , V_6 ) ;
return 0 ;
}
static int F_22 ( unsigned long V_18 ,
struct V_5 * V_6 )
{
F_18 ( V_7 , V_18 , V_6 ) ;
return 0 ;
}
static void F_23 ( unsigned type ,
struct V_5 * V_6 )
{
V_6 -> V_30 = V_31 ;
if ( type == V_32 ) {
if ( V_33 )
V_6 -> V_30 |= V_34 ;
V_6 -> V_35 = L_1 ;
V_6 -> V_36 = 450 ;
V_6 -> V_37 = F_24 ( F_25 () ) ;
V_6 -> V_25 = V_38 [ V_39 ] ;
switch ( V_39 ) {
case V_40 :
V_6 -> V_41 = F_14 ;
V_6 -> V_42 = F_14 ;
V_6 -> F_18 = F_19 ;
break;
case V_43 :
case V_44 :
case V_45 :
V_6 -> V_41 = F_15 ;
V_6 -> V_42 = F_15 ;
V_6 -> F_18 = F_20 ;
break;
default:
F_26 () ;
}
} else {
V_6 -> V_30 |= V_46 ;
V_6 -> V_35 = L_2 ;
V_6 -> V_36 = 400 ;
V_6 -> V_37 = V_47 ;
if ( V_48 ) {
V_6 -> V_41 = F_16 ;
V_6 -> V_42 = F_16 ;
V_6 -> F_18 =
F_21 ;
} else {
V_6 -> V_41 = F_17 ;
V_6 -> V_42 = F_17 ;
V_6 -> F_18 =
F_22 ;
}
}
V_6 -> V_41 ( V_6 ) ;
F_27 ( V_6 , V_49 , 0xf , 0x7fffffff ) ;
}
static void F_28 ( int V_50 )
{
T_2 V_51 = F_29 () ;
V_51 &= ~ V_52 ;
V_51 |= ( V_50 << V_53 )
| V_54 ;
F_30 ( V_51 ) ;
V_55 |= V_56 ;
#ifdef F_31
V_57 |= V_58 ;
#endif
}
static void F_32 ( void )
{
int V_59 , V_60 ;
V_59 = V_49 / V_61 ;
V_60 = F_33 ( V_59 ) ;
if ( V_60 > 1 && ! ( V_59 & ( 1 << ( V_60 - 2 ) ) ) )
V_60 -- ;
F_28 ( F_34 ( V_60 , 15 ) ) ;
}
static void F_35 ( void )
{
T_2 V_51 = F_29 () ;
V_51 &= ~ ( V_62
| V_63
| V_54
| V_64 ) ;
V_51 |= V_65 ;
F_30 ( V_51 ) ;
}
static bool F_36 ( void )
{
return ( V_39 == V_43 &&
V_38 [ V_44 ] ) ;
}
static int F_37 ( struct V_5 * V_6 )
{
F_23 ( V_32 , V_6 ) ;
F_38 ( V_38 [ V_39 ] , 0 ) ;
if ( F_36 () )
F_38 ( V_38 [ V_44 ] , 0 ) ;
F_35 () ;
if ( F_39 ( V_66 ) )
F_32 () ;
return 0 ;
}
static void
F_40 ( void T_4 * V_67 , struct V_68 * V_69 )
{
if ( V_49 )
return;
if ( ! V_70 ||
F_41 ( V_69 , L_3 , & V_49 ) ) {
if ( V_67 )
V_49 = F_6 ( V_67 + V_71 ) ;
else
V_49 = F_42 () ;
}
if ( V_49 == 0 )
F_43 ( L_4 ) ;
}
static void F_44 ( unsigned type )
{
F_45 ( L_5 ,
type & V_32 ? L_6 : L_7 ,
type == ( V_32 | V_72 ) ? L_8 : L_7 ,
type & V_72 ? L_9 : L_7 ,
( unsigned long ) V_49 / 1000000 ,
( unsigned long ) ( V_49 / 10000 ) % 100 ,
type & V_32 ?
( V_39 == V_40 ) ? L_10 : L_11 :
L_7 ,
type == ( V_32 | V_72 ) ? L_12 : L_7 ,
type & V_72 ?
V_48 ? L_10 : L_11 :
L_7 ) ;
}
T_2 F_46 ( void )
{
return V_49 ;
}
static T_5 F_47 ( void )
{
T_2 V_73 , V_74 , V_75 ;
do {
V_74 = F_6 ( V_76 + V_77 ) ;
V_73 = F_6 ( V_76 + V_78 ) ;
V_75 = F_6 ( V_76 + V_77 ) ;
} while ( V_74 != V_75 );
return ( ( T_5 ) V_74 << 32 ) | V_73 ;
}
static T_6 F_48 ( struct V_79 * V_80 )
{
return F_49 () ;
}
static T_6 F_50 ( const struct V_81 * V_82 )
{
return F_49 () ;
}
struct V_83 * F_51 ( void )
{
return & V_83 ;
}
static void T_7 F_52 ( unsigned type )
{
T_5 V_84 ;
if ( type & V_32 ) {
if ( F_39 ( V_85 ) || V_39 == V_40 )
F_49 = V_86 ;
else
F_49 = V_87 ;
} else {
F_49 = F_47 ;
V_88 . V_35 = L_13 ;
}
V_84 = F_49 () ;
F_53 ( & V_88 , V_49 ) ;
V_81 . V_89 = V_88 . V_89 ;
V_81 . V_90 = V_88 . V_90 ;
F_54 ( & V_83 , & V_81 , V_84 ) ;
F_55 ( F_49 , 56 , V_49 ) ;
}
static void F_56 ( struct V_5 * V_6 )
{
F_57 ( L_14 ,
V_6 -> V_25 , F_25 () ) ;
F_58 ( V_38 [ V_39 ] ) ;
if ( F_36 () )
F_58 ( V_38 [ V_44 ] ) ;
V_6 -> V_41 ( V_6 ) ;
}
static int F_59 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_94 )
{
switch ( V_93 & ~ V_95 ) {
case V_96 :
F_37 ( F_60 ( V_97 ) ) ;
break;
case V_98 :
F_56 ( F_60 ( V_97 ) ) ;
break;
}
return V_99 ;
}
static int F_61 ( struct V_91 * V_92 ,
unsigned long V_93 , void * V_94 )
{
if ( V_93 == V_100 )
V_101 = F_29 () ;
else if ( V_93 == V_102 || V_93 == V_103 )
F_30 ( V_101 ) ;
return V_99 ;
}
static int T_7 F_62 ( void )
{
return F_63 ( & V_104 ) ;
}
static int T_7 F_62 ( void )
{
return 0 ;
}
static int T_7 F_64 ( void )
{
int V_105 ;
int V_106 ;
V_97 = F_65 ( struct V_5 ) ;
if ( ! V_97 ) {
V_105 = - V_107 ;
goto V_108;
}
V_106 = V_38 [ V_39 ] ;
switch ( V_39 ) {
case V_40 :
V_105 = F_66 ( V_106 , F_9 ,
L_15 , V_97 ) ;
break;
case V_43 :
case V_44 :
V_105 = F_66 ( V_106 , F_10 ,
L_15 , V_97 ) ;
if ( ! V_105 && V_38 [ V_44 ] ) {
V_106 = V_38 [ V_44 ] ;
V_105 = F_66 ( V_106 , F_10 ,
L_15 , V_97 ) ;
if ( V_105 )
F_67 ( V_38 [ V_43 ] ,
V_97 ) ;
}
break;
case V_45 :
V_105 = F_66 ( V_106 , F_10 ,
L_15 , V_97 ) ;
break;
default:
F_26 () ;
}
if ( V_105 ) {
F_68 ( L_16 ,
V_106 , V_105 ) ;
goto V_109;
}
V_105 = F_69 ( & V_110 ) ;
if ( V_105 )
goto V_111;
V_105 = F_62 () ;
if ( V_105 )
goto V_112;
F_37 ( F_60 ( V_97 ) ) ;
return 0 ;
V_112:
F_70 ( & V_110 ) ;
V_111:
F_67 ( V_38 [ V_39 ] , V_97 ) ;
if ( F_36 () )
F_67 ( V_38 [ V_44 ] ,
V_97 ) ;
V_109:
F_71 ( V_97 ) ;
V_108:
return V_105 ;
}
static int T_7 F_72 ( void T_4 * V_11 , unsigned int V_25 )
{
int V_113 ;
T_8 V_114 ;
struct V_8 * V_115 ;
V_115 = F_73 ( sizeof( * V_115 ) , V_116 ) ;
if ( ! V_115 )
return - V_107 ;
V_115 -> V_11 = V_11 ;
V_115 -> V_18 . V_25 = V_25 ;
F_23 ( V_72 , & V_115 -> V_18 ) ;
if ( V_48 )
V_114 = F_12 ;
else
V_114 = F_11 ;
V_113 = F_74 ( V_25 , V_114 , V_117 , L_2 , & V_115 -> V_18 ) ;
if ( V_113 ) {
F_68 ( L_17 ) ;
F_75 ( V_115 ) ;
}
return V_113 ;
}
static bool T_7
F_76 ( int type , const struct V_118 * V_119 )
{
struct V_68 * V_120 ;
bool V_121 = false ;
V_120 = F_77 ( NULL , V_119 ) ;
if ( V_120 && F_78 ( V_120 ) && ! ( V_122 & type ) )
V_121 = true ;
F_79 ( V_120 ) ;
return V_121 ;
}
static void T_7 F_80 ( void )
{
unsigned V_123 = V_32 | V_72 ;
if ( ( V_122 & V_123 ) != V_123 ) {
if ( F_76 ( V_72 , V_124 ) )
return;
if ( F_76 ( V_32 , V_125 ) )
return;
}
F_44 ( V_122 ) ;
F_52 ( V_122 ) ;
F_81 () ;
}
static void T_7 F_82 ( void )
{
if ( F_83 () || ! V_38 [ V_40 ] ) {
bool V_126 ;
if ( F_84 () ) {
V_39 = V_45 ;
V_126 = ! ! V_38 [ V_45 ] ;
} else {
V_39 = V_43 ;
V_126 = ( ! ! V_38 [ V_43 ] ||
! ! V_38 [ V_44 ] ) ;
}
if ( ! V_126 ) {
F_43 ( L_18 ) ;
return;
}
}
F_64 () ;
F_80 () ;
}
static void T_7 F_85 ( struct V_68 * V_69 )
{
int V_127 ;
if ( V_122 & V_32 ) {
F_43 ( L_19 ) ;
return;
}
V_122 |= V_32 ;
for ( V_127 = V_43 ; V_127 < V_128 ; V_127 ++ )
V_38 [ V_127 ] = F_86 ( V_69 , V_127 ) ;
F_40 ( NULL , V_69 ) ;
V_33 = ! F_87 ( V_69 , L_20 ) ;
if ( F_39 ( V_129 ) &&
F_87 ( V_69 , L_21 ) )
V_39 = V_43 ;
F_82 () ;
}
static void T_7 F_88 ( struct V_68 * V_69 )
{
struct V_68 * V_130 , * V_131 = NULL ;
void T_4 * V_132 , * V_11 ;
unsigned int V_25 ;
T_2 V_133 ;
V_122 |= V_72 ;
V_132 = F_89 ( V_69 , 0 ) ;
if ( ! V_132 ) {
F_68 ( L_22 ) ;
return;
}
V_133 = F_6 ( V_132 + V_134 ) ;
F_90 (np, frame) {
int V_135 ;
T_2 V_136 ;
if ( F_41 ( V_130 , L_23 , & V_135 ) ) {
F_68 ( L_24 ) ;
F_79 ( V_130 ) ;
goto V_108;
}
V_136 = V_137 | V_138 | V_139 |
V_140 | V_141 | V_142 ;
F_3 ( V_136 , V_132 + F_91 ( V_135 ) ) ;
V_136 = F_6 ( V_132 + F_91 ( V_135 ) ) ;
if ( ( V_133 & F_92 ( V_135 ) ) &&
! ( ~ V_136 & ( V_140 | V_142 ) ) ) {
F_79 ( V_131 ) ;
V_131 = V_130 ;
V_48 = true ;
break;
}
if ( ~ V_136 & ( V_138 | V_139 ) )
continue;
F_79 ( V_131 ) ;
V_131 = F_93 ( V_130 ) ;
}
V_11 = V_76 = F_89 ( V_131 , 0 ) ;
if ( ! V_11 ) {
F_68 ( L_25 ) ;
goto V_108;
}
if ( V_48 )
V_25 = F_86 ( V_131 , 1 ) ;
else
V_25 = F_86 ( V_131 , 0 ) ;
if ( ! V_25 ) {
F_68 ( L_26 ,
V_48 ? L_10 : L_11 ) ;
goto V_108;
}
F_40 ( V_11 , V_69 ) ;
F_72 ( V_11 , V_25 ) ;
F_80 () ;
V_108:
F_94 ( V_132 ) ;
F_79 ( V_131 ) ;
}
static int T_7 F_95 ( T_2 V_143 , T_2 V_144 )
{
int V_145 , V_146 ;
if ( ! V_143 )
return 0 ;
V_145 = ( V_144 & V_147 ) ? V_148
: V_149 ;
V_146 = ( V_144 & V_150 ) ? V_151
: V_152 ;
return F_96 ( NULL , V_143 , V_145 , V_146 ) ;
}
static int T_7 F_97 ( struct V_153 * V_154 )
{
struct V_155 * V_156 ;
if ( V_122 & V_32 ) {
F_43 ( L_27 ) ;
return - V_157 ;
}
V_156 = F_98 ( V_154 , struct V_155 , V_158 ) ;
V_122 |= V_32 ;
V_38 [ V_43 ] =
F_95 ( V_156 -> V_159 ,
V_156 -> V_160 ) ;
V_38 [ V_44 ] =
F_95 ( V_156 -> V_161 ,
V_156 -> V_162 ) ;
V_38 [ V_40 ] =
F_95 ( V_156 -> V_163 ,
V_156 -> V_164 ) ;
V_38 [ V_45 ] =
F_95 ( V_156 -> V_165 ,
V_156 -> V_166 ) ;
F_40 ( NULL , NULL ) ;
V_33 = ! ( V_156 -> V_162 & V_167 ) ;
F_82 () ;
return 0 ;
}

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
if ( V_38 ) {
V_6 -> V_25 = V_39 [ V_40 ] ;
V_6 -> V_41 = F_14 ;
V_6 -> F_18 = F_19 ;
} else {
V_6 -> V_25 = V_39 [ V_42 ] ;
V_6 -> V_41 = F_15 ;
V_6 -> F_18 = F_20 ;
}
} else {
V_6 -> V_30 |= V_43 ;
V_6 -> V_35 = L_2 ;
V_6 -> V_36 = 400 ;
V_6 -> V_37 = V_44 ;
if ( V_45 ) {
V_6 -> V_41 = F_16 ;
V_6 -> F_18 =
F_21 ;
} else {
V_6 -> V_41 = F_17 ;
V_6 -> F_18 =
F_22 ;
}
}
V_6 -> V_41 ( V_6 ) ;
F_26 ( V_6 , V_46 , 0xf , 0x7fffffff ) ;
}
static void F_27 ( int V_47 )
{
T_2 V_48 = F_28 () ;
V_48 &= ~ V_49 ;
V_48 |= ( V_47 << V_50 )
| V_51 ;
F_29 ( V_48 ) ;
V_52 |= V_53 ;
#ifdef F_30
V_54 |= V_55 ;
#endif
}
static void F_31 ( void )
{
int V_56 , V_57 ;
V_56 = V_46 / V_58 ;
V_57 = F_32 ( V_56 ) ;
if ( V_57 > 1 && ! ( V_56 & ( 1 << ( V_57 - 2 ) ) ) )
V_57 -- ;
F_27 ( F_33 ( V_57 , 15 ) ) ;
}
static void F_34 ( void )
{
T_2 V_48 = F_28 () ;
V_48 &= ~ ( V_59
| V_60
| V_51
| V_61 ) ;
V_48 |= V_62 ;
F_29 ( V_48 ) ;
}
static int F_35 ( struct V_5 * V_6 )
{
F_23 ( V_32 , V_6 ) ;
if ( V_38 )
F_36 ( V_39 [ V_40 ] , 0 ) ;
else {
F_36 ( V_39 [ V_42 ] , 0 ) ;
if ( V_39 [ V_63 ] )
F_36 ( V_39 [ V_63 ] , 0 ) ;
}
F_34 () ;
if ( F_37 ( V_64 ) )
F_31 () ;
return 0 ;
}
static void
F_38 ( void T_4 * V_65 , struct V_66 * V_67 )
{
if ( V_46 )
return;
if ( ! V_68 ||
F_39 ( V_67 , L_3 , & V_46 ) ) {
if ( V_65 )
V_46 = F_6 ( V_65 + V_69 ) ;
else
V_46 = F_40 () ;
}
if ( V_46 == 0 )
F_41 ( L_4 ) ;
}
static void F_42 ( unsigned type )
{
F_43 ( L_5 ,
type & V_32 ? L_6 : L_7 ,
type == ( V_32 | V_70 ) ? L_8 : L_7 ,
type & V_70 ? L_9 : L_7 ,
( unsigned long ) V_46 / 1000000 ,
( unsigned long ) ( V_46 / 10000 ) % 100 ,
type & V_32 ?
V_38 ? L_10 : L_11 :
L_7 ,
type == ( V_32 | V_70 ) ? L_12 : L_7 ,
type & V_70 ?
V_45 ? L_10 : L_11 :
L_7 ) ;
}
T_2 F_44 ( void )
{
return V_46 ;
}
static T_5 F_45 ( void )
{
T_2 V_71 , V_72 , V_73 ;
do {
V_72 = F_6 ( V_74 + V_75 ) ;
V_71 = F_6 ( V_74 + V_76 ) ;
V_73 = F_6 ( V_74 + V_75 ) ;
} while ( V_72 != V_73 );
return ( ( T_5 ) V_72 << 32 ) | V_71 ;
}
static T_6 F_46 ( struct V_77 * V_78 )
{
return F_47 () ;
}
static T_6 F_48 ( const struct V_79 * V_80 )
{
return F_47 () ;
}
struct V_81 * F_49 ( void )
{
return & V_81 ;
}
static void T_7 F_50 ( unsigned type )
{
T_5 V_82 ;
if ( type & V_32 ) {
if ( F_37 ( V_83 ) || V_38 )
F_47 = V_84 ;
else
F_47 = V_85 ;
} else {
F_47 = F_45 ;
V_86 . V_35 = L_13 ;
}
V_82 = F_47 () ;
F_51 ( & V_86 , V_46 ) ;
V_79 . V_87 = V_86 . V_87 ;
V_79 . V_88 = V_86 . V_88 ;
F_52 ( & V_81 , & V_79 , V_82 ) ;
F_53 ( F_47 , 56 , V_46 ) ;
}
static void F_54 ( struct V_5 * V_6 )
{
F_55 ( L_14 ,
V_6 -> V_25 , F_25 () ) ;
if ( V_38 )
F_56 ( V_39 [ V_40 ] ) ;
else {
F_56 ( V_39 [ V_42 ] ) ;
if ( V_39 [ V_63 ] )
F_56 ( V_39 [ V_63 ] ) ;
}
V_6 -> V_41 ( V_6 ) ;
}
static int F_57 ( struct V_89 * V_90 ,
unsigned long V_91 , void * V_92 )
{
switch ( V_91 & ~ V_93 ) {
case V_94 :
F_35 ( F_58 ( V_95 ) ) ;
break;
case V_96 :
F_54 ( F_58 ( V_95 ) ) ;
break;
}
return V_97 ;
}
static int F_59 ( struct V_89 * V_90 ,
unsigned long V_91 , void * V_92 )
{
if ( V_91 == V_98 )
V_99 = F_28 () ;
else if ( V_91 == V_100 || V_91 == V_101 )
F_29 ( V_99 ) ;
return V_97 ;
}
static int T_7 F_60 ( void )
{
return F_61 ( & V_102 ) ;
}
static int T_7 F_60 ( void )
{
return 0 ;
}
static int T_7 F_62 ( void )
{
int V_103 ;
int V_104 ;
V_95 = F_63 ( struct V_5 ) ;
if ( ! V_95 ) {
V_103 = - V_105 ;
goto V_106;
}
if ( V_38 ) {
V_104 = V_39 [ V_40 ] ;
V_103 = F_64 ( V_104 , F_9 ,
L_15 , V_95 ) ;
} else {
V_104 = V_39 [ V_42 ] ;
V_103 = F_64 ( V_104 , F_10 ,
L_15 , V_95 ) ;
if ( ! V_103 && V_39 [ V_63 ] ) {
V_104 = V_39 [ V_63 ] ;
V_103 = F_64 ( V_104 , F_10 ,
L_15 , V_95 ) ;
if ( V_103 )
F_65 ( V_39 [ V_42 ] ,
V_95 ) ;
}
}
if ( V_103 ) {
F_66 ( L_16 ,
V_104 , V_103 ) ;
goto V_107;
}
V_103 = F_67 ( & V_108 ) ;
if ( V_103 )
goto V_109;
V_103 = F_60 () ;
if ( V_103 )
goto V_110;
F_35 ( F_58 ( V_95 ) ) ;
return 0 ;
V_110:
F_68 ( & V_108 ) ;
V_109:
if ( V_38 )
F_65 ( V_39 [ V_40 ] , V_95 ) ;
else {
F_65 ( V_39 [ V_42 ] ,
V_95 ) ;
if ( V_39 [ V_63 ] )
F_65 ( V_39 [ V_63 ] ,
V_95 ) ;
}
V_107:
F_69 ( V_95 ) ;
V_106:
return V_103 ;
}
static int T_7 F_70 ( void T_4 * V_11 , unsigned int V_25 )
{
int V_111 ;
T_8 V_112 ;
struct V_8 * V_113 ;
V_113 = F_71 ( sizeof( * V_113 ) , V_114 ) ;
if ( ! V_113 )
return - V_105 ;
V_113 -> V_11 = V_11 ;
V_113 -> V_18 . V_25 = V_25 ;
F_23 ( V_70 , & V_113 -> V_18 ) ;
if ( V_45 )
V_112 = F_12 ;
else
V_112 = F_11 ;
V_111 = F_72 ( V_25 , V_112 , V_115 , L_2 , & V_113 -> V_18 ) ;
if ( V_111 ) {
F_66 ( L_17 ) ;
F_73 ( V_113 ) ;
}
return V_111 ;
}
static bool T_7
F_74 ( int type , const struct V_116 * V_117 )
{
struct V_66 * V_118 ;
bool V_119 = false ;
V_118 = F_75 ( NULL , V_117 ) ;
if ( V_118 && F_76 ( V_118 ) && ! ( V_120 & type ) )
V_119 = true ;
F_77 ( V_118 ) ;
return V_119 ;
}
static void T_7 F_78 ( void )
{
unsigned V_121 = V_32 | V_70 ;
if ( ( V_120 & V_121 ) != V_121 ) {
if ( F_74 ( V_70 , V_122 ) )
return;
if ( F_74 ( V_32 , V_123 ) )
return;
}
F_42 ( V_120 ) ;
F_50 ( V_120 ) ;
F_79 () ;
}
static void T_7 F_80 ( void )
{
if ( F_81 () || ! V_39 [ V_40 ] ) {
V_38 = false ;
if ( ! V_39 [ V_42 ] ||
! V_39 [ V_63 ] ) {
F_41 ( L_18 ) ;
return;
}
}
F_62 () ;
F_78 () ;
}
static void T_7 F_82 ( struct V_66 * V_67 )
{
int V_124 ;
if ( V_120 & V_32 ) {
F_41 ( L_19 ) ;
return;
}
V_120 |= V_32 ;
for ( V_124 = V_42 ; V_124 < V_125 ; V_124 ++ )
V_39 [ V_124 ] = F_83 ( V_67 , V_124 ) ;
F_38 ( NULL , V_67 ) ;
V_33 = ! F_84 ( V_67 , L_20 ) ;
if ( F_37 ( V_126 ) &&
F_84 ( V_67 , L_21 ) )
V_38 = false ;
F_80 () ;
}
static void T_7 F_85 ( struct V_66 * V_67 )
{
struct V_66 * V_127 , * V_128 = NULL ;
void T_4 * V_129 , * V_11 ;
unsigned int V_25 ;
T_2 V_130 ;
V_120 |= V_70 ;
V_129 = F_86 ( V_67 , 0 ) ;
if ( ! V_129 ) {
F_66 ( L_22 ) ;
return;
}
V_130 = F_6 ( V_129 + V_131 ) ;
F_87 ( V_129 ) ;
F_88 (np, frame) {
int V_132 ;
if ( F_39 ( V_127 , L_23 , & V_132 ) ) {
F_66 ( L_24 ) ;
F_77 ( V_128 ) ;
F_77 ( V_127 ) ;
return;
}
if ( V_130 & F_89 ( V_132 ) ) {
F_77 ( V_128 ) ;
V_128 = V_127 ;
V_45 = true ;
break;
}
F_77 ( V_128 ) ;
V_128 = F_90 ( V_127 ) ;
}
V_11 = V_74 = F_86 ( V_128 , 0 ) ;
if ( ! V_11 ) {
F_66 ( L_25 ) ;
F_77 ( V_128 ) ;
return;
}
if ( V_45 )
V_25 = F_83 ( V_128 , 1 ) ;
else
V_25 = F_83 ( V_128 , 0 ) ;
F_77 ( V_128 ) ;
if ( ! V_25 ) {
F_66 ( L_26 ,
V_45 ? L_10 : L_11 ) ;
return;
}
F_38 ( V_11 , V_67 ) ;
F_70 ( V_11 , V_25 ) ;
F_78 () ;
}
static int T_7 F_91 ( T_2 V_133 , T_2 V_134 )
{
int V_135 , V_136 ;
if ( ! V_133 )
return 0 ;
V_135 = ( V_134 & V_137 ) ? V_138
: V_139 ;
V_136 = ( V_134 & V_140 ) ? V_141
: V_142 ;
return F_92 ( NULL , V_133 , V_135 , V_136 ) ;
}
static int T_7 F_93 ( struct V_143 * V_144 )
{
struct V_145 * V_146 ;
if ( V_120 & V_32 ) {
F_41 ( L_27 ) ;
return - V_147 ;
}
V_146 = F_94 ( V_144 , struct V_145 , V_148 ) ;
V_120 |= V_32 ;
V_39 [ V_42 ] =
F_91 ( V_146 -> V_149 ,
V_146 -> V_150 ) ;
V_39 [ V_63 ] =
F_91 ( V_146 -> V_151 ,
V_146 -> V_152 ) ;
V_39 [ V_40 ] =
F_91 ( V_146 -> V_153 ,
V_146 -> V_154 ) ;
V_39 [ V_155 ] =
F_91 ( V_146 -> V_156 ,
V_146 -> V_157 ) ;
F_38 ( NULL , NULL ) ;
V_33 = ! ( V_146 -> V_152 & V_158 ) ;
F_80 () ;
return 0 ;
}
void T_7 F_95 ( void )
{
if ( V_68 )
return;
F_96 ( V_159 , F_93 ) ;
}

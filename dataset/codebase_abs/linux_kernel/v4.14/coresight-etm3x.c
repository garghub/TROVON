static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0x0 , V_3 ) ;
V_2 -> V_4 = true ;
F_3 () ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_5 ;
F_5 () ;
F_3 () ;
V_5 = F_6 ( V_2 , V_6 ) ;
V_5 |= V_7 ;
F_2 ( V_2 , V_5 , V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_6 ( V_2 , V_6 ) ;
V_5 &= ~ V_7 ;
F_2 ( V_2 , V_5 , V_6 ) ;
F_5 () ;
F_3 () ;
}
static void F_8 ( struct V_1 * V_2 )
{
T_1 V_8 ;
V_8 = F_9 ( V_2 -> V_9 + V_10 ) ;
V_8 |= V_11 ;
F_10 ( V_8 , V_2 -> V_9 + V_10 ) ;
F_5 () ;
F_3 () ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_8 ;
F_5 () ;
F_3 () ;
V_8 = F_9 ( V_2 -> V_9 + V_10 ) ;
V_8 &= ~ V_11 ;
F_10 ( V_8 , V_2 -> V_9 + V_10 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_12 ,
int V_13 , int V_14 )
{
int V_15 ;
T_1 V_16 ;
for ( V_15 = V_17 ; V_15 > 0 ; V_15 -- ) {
V_16 = F_6 ( V_2 , V_12 ) ;
if ( V_14 ) {
if ( V_16 & F_13 ( V_13 ) )
return 0 ;
} else {
if ( ! ( V_16 & F_13 ( V_13 ) ) )
return 0 ;
}
if ( V_15 - 1 )
F_14 ( 1 ) ;
}
return - V_18 ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_6 ( V_2 , V_6 ) ;
V_5 |= V_19 ;
F_2 ( V_2 , V_5 , V_6 ) ;
F_3 () ;
if ( F_12 ( V_2 , V_20 , V_21 , 1 ) ) {
F_16 ( V_2 -> V_22 ,
L_1 ,
V_23 , V_20 ) ;
}
}
static void F_17 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_6 ( V_2 , V_6 ) ;
V_5 &= ~ V_19 ;
F_2 ( V_2 , V_5 , V_6 ) ;
F_3 () ;
if ( F_12 ( V_2 , V_20 , V_21 , 0 ) ) {
F_16 ( V_2 -> V_22 ,
L_1 ,
V_23 , V_20 ) ;
}
}
void F_18 ( struct V_24 * V_25 )
{
int V_15 ;
if ( F_19 ( ! V_25 ) )
return;
V_25 -> V_26 = F_13 ( 24 ) ;
V_25 -> V_27 = 0x0 ;
V_25 -> V_28 = V_29 ;
V_25 -> V_30 = V_31 ;
V_25 -> V_28 = V_29 ;
V_25 -> V_32 = V_31 ;
V_25 -> V_33 = V_31 ;
V_25 -> V_34 = V_31 ;
V_25 -> V_35 = V_31 ;
V_25 -> V_36 = V_31 ;
V_25 -> V_37 = V_31 ;
V_25 -> V_38 = V_31 ;
for ( V_15 = 0 ; V_15 < V_39 ; V_15 ++ ) {
V_25 -> V_40 [ V_15 ] = 0x0 ;
V_25 -> V_41 [ V_15 ] = V_31 ;
V_25 -> V_42 [ V_15 ] = V_31 ;
V_25 -> V_43 [ V_15 ] = 0x0 ;
}
V_25 -> V_44 = 0x0 ;
V_25 -> V_45 = 0x0 ;
for ( V_15 = 0 ; V_15 < V_46 ; V_15 ++ ) {
V_25 -> V_47 [ V_15 ] = 0x0 ;
V_25 -> V_48 [ V_15 ] = 0x0 ;
}
V_25 -> V_49 = 0x0 ;
V_25 -> V_50 = 0x400 ;
}
void F_20 ( struct V_24 * V_25 )
{
T_1 V_51 , V_52 ;
V_52 = V_25 -> V_52 ;
V_52 &= ( V_53 | V_54 ) ;
if ( V_52 == ( V_53 | V_54 ) )
return;
if ( ! ( V_52 & V_53 ) && ! ( V_52 & V_54 ) )
return;
V_51 = ( 1 << 0 |
3 << 3 |
0 << 5 |
0 << 7 |
0 << 8 ) ;
V_25 -> V_27 = 0x0 ;
V_25 -> V_26 = V_55 ;
V_51 |= ( 0 << 12 | 1 << 10 ) ;
if ( V_52 & V_54 ) {
V_51 |= ( 1 << 13 | 0 << 11 ) ;
} else {
V_51 |= ( 1 << 13 | 1 << 11 ) ;
}
V_25 -> V_56 [ 0 ] = ( T_1 ) 0x0 ;
V_25 -> V_56 [ 1 ] = ( T_1 ) ~ 0x0 ;
V_25 -> V_57 [ 0 ] = V_51 ;
V_25 -> V_57 [ 1 ] = V_51 ;
V_25 -> V_58 [ 0 ] = V_59 ;
V_25 -> V_58 [ 1 ] = V_59 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_24 * V_25 = & V_2 -> V_25 ;
struct V_62 * V_63 = & V_61 -> V_63 ;
if ( ! V_63 )
return - V_64 ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
if ( V_63 -> V_65 )
V_25 -> V_52 = V_53 ;
if ( V_63 -> V_66 )
V_25 -> V_52 = V_54 ;
F_18 ( V_25 ) ;
if ( V_25 -> V_52 )
F_20 ( V_25 ) ;
if ( V_63 -> V_25 & ~ V_67 )
return - V_64 ;
V_25 -> V_68 = V_63 -> V_25 ;
if ( ( V_25 -> V_68 & V_69 ) &&
! ( V_2 -> V_70 & V_71 ) )
V_25 -> V_68 &= ~ V_69 ;
return 0 ;
}
static void F_22 ( void * V_72 )
{
int V_15 ;
T_1 V_5 ;
struct V_1 * V_2 = V_72 ;
struct V_24 * V_25 = & V_2 -> V_25 ;
F_23 ( V_2 -> V_9 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_1 ( V_2 ) ;
F_15 ( V_2 ) ;
V_5 = F_6 ( V_2 , V_6 ) ;
V_5 &= ~ V_67 ;
V_5 |= V_2 -> V_73 ;
V_5 |= V_74 ;
F_2 ( V_2 , V_25 -> V_68 | V_5 , V_6 ) ;
F_2 ( V_2 , V_25 -> V_30 , V_75 ) ;
F_2 ( V_2 , V_25 -> V_76 , V_77 ) ;
F_2 ( V_2 , V_25 -> V_28 , V_78 ) ;
F_2 ( V_2 , V_25 -> V_26 , V_79 ) ;
F_2 ( V_2 , V_25 -> V_80 , V_81 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_82 ; V_15 ++ ) {
F_2 ( V_2 , V_25 -> V_56 [ V_15 ] , F_24 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_57 [ V_15 ] , F_25 ( V_15 ) ) ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_83 ; V_15 ++ ) {
F_2 ( V_2 , V_25 -> V_40 [ V_15 ] , F_26 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_41 [ V_15 ] , F_27 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_42 [ V_15 ] ,
F_28 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_43 [ V_15 ] , F_29 ( V_15 ) ) ;
}
F_2 ( V_2 , V_25 -> V_32 , V_84 ) ;
F_2 ( V_2 , V_25 -> V_33 , V_85 ) ;
F_2 ( V_2 , V_25 -> V_34 , V_86 ) ;
F_2 ( V_2 , V_25 -> V_35 , V_87 ) ;
F_2 ( V_2 , V_25 -> V_36 , V_88 ) ;
F_2 ( V_2 , V_25 -> V_37 , V_89 ) ;
F_2 ( V_2 , V_25 -> V_44 , V_90 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_91 ; V_15 ++ )
F_2 ( V_2 , V_31 , F_30 ( V_15 ) ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_92 ; V_15 ++ )
F_2 ( V_2 , V_25 -> V_47 [ V_15 ] , F_31 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_49 , V_93 ) ;
F_2 ( V_2 , V_25 -> V_50 , V_94 ) ;
F_2 ( V_2 , 0x0 , V_95 ) ;
F_2 ( V_2 , V_25 -> V_38 , V_96 ) ;
F_2 ( V_2 , 0x0 , V_97 ) ;
F_2 ( V_2 , V_2 -> V_98 , V_99 ) ;
F_2 ( V_2 , 0x0 , V_100 ) ;
F_17 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
F_33 ( V_2 -> V_22 , L_2 , V_2 -> V_101 ) ;
}
static int F_34 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_35 ( V_103 -> V_22 . V_104 ) ;
return V_2 -> V_101 ;
}
int F_36 ( struct V_1 * V_2 )
{
unsigned long V_51 ;
int V_105 = - 1 ;
if ( ! V_2 )
goto V_106;
if ( ! F_37 ( & V_2 -> V_52 ) )
return V_2 -> V_98 ;
F_38 ( V_2 -> V_22 ) ;
F_39 ( & V_2 -> V_107 , V_51 ) ;
F_23 ( V_2 -> V_9 ) ;
V_105 = ( F_6 ( V_2 , V_99 ) & V_108 ) ;
F_32 ( V_2 -> V_9 ) ;
F_40 ( & V_2 -> V_107 , V_51 ) ;
F_41 ( V_2 -> V_22 ) ;
V_106:
return V_105 ;
}
static int F_42 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_35 ( V_103 -> V_22 . V_104 ) ;
return F_36 ( V_2 ) ;
}
static int F_43 ( struct V_102 * V_103 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_35 ( V_103 -> V_22 . V_104 ) ;
if ( F_19 ( V_2 -> V_101 != F_44 () ) )
return - V_64 ;
F_21 ( V_2 , V_61 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_35 ( V_103 -> V_22 . V_104 ) ;
int V_109 ;
F_46 ( & V_2 -> V_107 ) ;
if ( F_47 ( V_2 -> V_101 ) ) {
V_109 = F_48 ( V_2 -> V_101 ,
F_22 , V_2 , 1 ) ;
if ( V_109 )
goto V_110;
}
V_2 -> V_111 = true ;
F_49 ( & V_2 -> V_107 ) ;
F_50 ( V_2 -> V_22 , L_3 ) ;
return 0 ;
V_110:
F_49 ( & V_2 -> V_107 ) ;
return V_109 ;
}
static int F_51 ( struct V_102 * V_103 ,
struct V_60 * V_61 , T_1 V_52 )
{
int V_109 ;
T_1 V_16 ;
struct V_1 * V_2 = F_35 ( V_103 -> V_22 . V_104 ) ;
V_16 = F_52 ( & V_2 -> V_52 , V_112 , V_52 ) ;
if ( V_16 )
return - V_113 ;
switch ( V_52 ) {
case V_114 :
V_109 = F_45 ( V_103 ) ;
break;
case V_115 :
V_109 = F_43 ( V_103 , V_61 ) ;
break;
default:
V_109 = - V_64 ;
}
if ( V_109 )
F_53 ( & V_2 -> V_52 , V_112 ) ;
return V_109 ;
}
static void F_54 ( void * V_72 )
{
int V_15 ;
struct V_1 * V_2 = V_72 ;
struct V_24 * V_25 = & V_2 -> V_25 ;
F_23 ( V_2 -> V_9 ) ;
F_15 ( V_2 ) ;
V_25 -> V_44 = ( F_6 ( V_2 , V_90 ) & V_116 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_83 ; V_15 ++ )
V_25 -> V_43 [ V_15 ] = F_6 ( V_2 , F_29 ( V_15 ) ) ;
F_4 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
F_33 ( V_2 -> V_22 , L_4 , V_2 -> V_101 ) ;
}
static void F_55 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_35 ( V_103 -> V_22 . V_104 ) ;
if ( F_19 ( V_2 -> V_101 != F_44 () ) )
return;
F_23 ( V_2 -> V_9 ) ;
F_15 ( V_2 ) ;
F_4 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
}
static void F_56 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_35 ( V_103 -> V_22 . V_104 ) ;
F_57 () ;
F_46 ( & V_2 -> V_107 ) ;
F_48 ( V_2 -> V_101 , F_54 , V_2 , 1 ) ;
F_49 ( & V_2 -> V_107 ) ;
F_58 () ;
F_50 ( V_2 -> V_22 , L_5 ) ;
}
static void F_59 ( struct V_102 * V_103 ,
struct V_60 * V_61 )
{
T_1 V_52 ;
struct V_1 * V_2 = F_35 ( V_103 -> V_22 . V_104 ) ;
V_52 = F_37 ( & V_2 -> V_52 ) ;
switch ( V_52 ) {
case V_112 :
break;
case V_114 :
F_56 ( V_103 ) ;
break;
case V_115 :
F_55 ( V_103 ) ;
break;
default:
F_19 ( V_52 ) ;
return;
}
if ( V_52 )
F_53 ( & V_2 -> V_52 , V_112 ) ;
}
static int F_60 ( unsigned int V_101 )
{
if ( ! V_117 [ V_101 ] )
return 0 ;
if ( V_117 [ V_101 ] -> V_118 && ! V_117 [ V_101 ] -> V_111 )
F_61 ( V_117 [ V_101 ] -> V_103 ) ;
return 0 ;
}
static int F_62 ( unsigned int V_101 )
{
if ( ! V_117 [ V_101 ] )
return 0 ;
F_46 ( & V_117 [ V_101 ] -> V_107 ) ;
if ( ! V_117 [ V_101 ] -> V_4 ) {
F_1 ( V_117 [ V_101 ] ) ;
V_117 [ V_101 ] -> V_4 = true ;
}
if ( F_37 ( & V_117 [ V_101 ] -> V_52 ) )
F_22 ( V_117 [ V_101 ] ) ;
F_49 ( & V_117 [ V_101 ] -> V_107 ) ;
return 0 ;
}
static int F_63 ( unsigned int V_101 )
{
if ( ! V_117 [ V_101 ] )
return 0 ;
F_46 ( & V_117 [ V_101 ] -> V_107 ) ;
if ( F_37 ( & V_117 [ V_101 ] -> V_52 ) )
F_54 ( V_117 [ V_101 ] ) ;
F_49 ( & V_117 [ V_101 ] -> V_107 ) ;
return 0 ;
}
static bool F_64 ( T_2 V_119 )
{
switch ( V_119 ) {
case V_120 :
break;
case V_121 :
break;
case V_122 :
break;
case V_123 :
break;
default:
return false ;
}
return true ;
}
static void F_65 ( void * V_72 )
{
T_1 V_124 ;
T_1 V_125 ;
struct V_1 * V_2 = V_72 ;
F_1 ( V_2 ) ;
F_23 ( V_2 -> V_9 ) ;
( void ) F_6 ( V_2 , V_126 ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 ) ;
F_15 ( V_2 ) ;
V_124 = F_6 ( V_2 , V_127 ) ;
V_2 -> V_119 = F_66 ( V_124 , 4 , 11 ) ;
V_2 -> V_73 = F_6 ( V_2 , V_6 ) & V_128 ;
V_2 -> V_70 = F_6 ( V_2 , V_129 ) ;
V_125 = F_6 ( V_2 , V_130 ) ;
V_2 -> V_125 = V_125 ;
V_2 -> V_82 = F_66 ( V_125 , 0 , 3 ) * 2 ;
V_2 -> V_83 = F_66 ( V_125 , 13 , 15 ) ;
V_2 -> V_131 = F_66 ( V_125 , 17 , 19 ) ;
V_2 -> V_91 = F_66 ( V_125 , 20 , 22 ) ;
V_2 -> V_92 = F_66 ( V_125 , 24 , 25 ) ;
F_4 ( V_2 ) ;
F_11 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
V_2 -> V_98 = F_68 ( V_2 -> V_101 ) ;
}
static int F_69 ( struct V_132 * V_133 , const struct V_134 * V_135 )
{
int V_109 ;
void T_3 * V_9 ;
struct V_136 * V_22 = & V_133 -> V_22 ;
struct V_137 * V_138 = NULL ;
struct V_1 * V_2 ;
struct V_139 * V_140 = & V_133 -> V_140 ;
struct V_141 V_142 = { 0 } ;
struct V_143 * V_144 = V_133 -> V_22 . V_145 ;
V_2 = F_70 ( V_22 , sizeof( * V_2 ) , V_146 ) ;
if ( ! V_2 )
return - V_147 ;
if ( V_144 ) {
V_138 = F_71 ( V_22 , V_144 ) ;
if ( F_72 ( V_138 ) )
return F_73 ( V_138 ) ;
V_133 -> V_22 . V_148 = V_138 ;
V_2 -> V_149 = F_74 ( V_144 , L_6 ) ;
}
V_2 -> V_22 = & V_133 -> V_22 ;
F_75 ( V_22 , V_2 ) ;
V_9 = F_76 ( V_22 , V_140 ) ;
if ( F_72 ( V_9 ) )
return F_73 ( V_9 ) ;
V_2 -> V_9 = V_9 ;
F_77 ( & V_2 -> V_107 ) ;
V_2 -> V_150 = F_78 ( & V_133 -> V_22 , L_7 ) ;
if ( ! F_72 ( V_2 -> V_150 ) ) {
V_109 = F_79 ( V_2 -> V_150 ) ;
if ( V_109 )
return V_109 ;
}
V_2 -> V_101 = V_138 ? V_138 -> V_101 : 0 ;
F_57 () ;
V_117 [ V_2 -> V_101 ] = V_2 ;
if ( F_48 ( V_2 -> V_101 ,
F_65 , V_2 , 1 ) )
F_16 ( V_22 , L_8 ) ;
if ( ! V_151 ++ ) {
F_80 ( V_152 ,
L_9 ,
F_62 , F_63 ) ;
V_109 = F_80 ( V_153 ,
L_10 ,
F_60 , NULL ) ;
if ( V_109 < 0 )
goto V_154;
V_155 = V_109 ;
}
F_58 () ;
if ( F_64 ( V_2 -> V_119 ) == false ) {
V_109 = - V_64 ;
goto V_154;
}
F_67 ( V_2 ) ;
F_18 ( & V_2 -> V_25 ) ;
V_142 . type = V_156 ;
V_142 . V_157 . V_158 = V_159 ;
V_142 . V_160 = & V_161 ;
V_142 . V_138 = V_138 ;
V_142 . V_22 = V_22 ;
V_142 . V_162 = V_163 ;
V_2 -> V_103 = F_81 ( & V_142 ) ;
if ( F_72 ( V_2 -> V_103 ) ) {
V_109 = F_73 ( V_2 -> V_103 ) ;
goto V_154;
}
V_109 = F_82 ( V_2 -> V_103 , true ) ;
if ( V_109 ) {
F_83 ( V_2 -> V_103 ) ;
goto V_154;
}
F_41 ( & V_133 -> V_22 ) ;
F_50 ( V_22 , L_11 , ( char * ) V_135 -> V_164 ) ;
if ( V_118 ) {
F_61 ( V_2 -> V_103 ) ;
V_2 -> V_118 = true ;
}
return 0 ;
V_154:
if ( -- V_151 == 0 ) {
F_84 ( V_152 ) ;
if ( V_155 )
F_84 ( V_155 ) ;
}
return V_109 ;
}
static int F_85 ( struct V_136 * V_22 )
{
struct V_1 * V_2 = F_35 ( V_22 ) ;
if ( V_2 && ! F_72 ( V_2 -> V_150 ) )
F_86 ( V_2 -> V_150 ) ;
return 0 ;
}
static int F_87 ( struct V_136 * V_22 )
{
struct V_1 * V_2 = F_35 ( V_22 ) ;
if ( V_2 && ! F_72 ( V_2 -> V_150 ) )
F_79 ( V_2 -> V_150 ) ;
return 0 ;
}

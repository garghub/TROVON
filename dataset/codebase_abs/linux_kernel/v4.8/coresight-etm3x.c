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
}
void F_20 ( struct V_24 * V_25 )
{
T_1 V_50 , V_51 ;
V_51 = V_25 -> V_51 ;
V_51 &= ( V_52 | V_53 ) ;
if ( V_51 == ( V_52 | V_53 ) )
return;
if ( ! ( V_51 & V_52 ) && ! ( V_51 & V_53 ) )
return;
V_50 = ( 1 << 0 |
3 << 3 |
0 << 5 |
0 << 7 |
0 << 8 ) ;
V_25 -> V_27 = 0x0 ;
V_25 -> V_26 = V_54 ;
V_50 |= ( 0 << 12 | 1 << 10 ) ;
if ( V_51 & V_53 ) {
V_50 |= ( 1 << 13 | 0 << 11 ) ;
} else {
V_50 |= ( 1 << 13 | 1 << 11 ) ;
}
V_25 -> V_55 [ 0 ] = ( T_1 ) 0x0 ;
V_25 -> V_55 [ 1 ] = ( T_1 ) ~ 0x0 ;
V_25 -> V_56 [ 0 ] = V_50 ;
V_25 -> V_56 [ 1 ] = V_50 ;
V_25 -> V_57 [ 0 ] = V_58 ;
V_25 -> V_57 [ 1 ] = V_58 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
struct V_24 * V_25 = & V_2 -> V_25 ;
if ( ! V_60 )
return - V_61 ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
if ( V_60 -> V_62 )
V_25 -> V_51 = V_52 ;
if ( V_60 -> V_63 )
V_25 -> V_51 = V_53 ;
F_18 ( V_25 ) ;
if ( V_25 -> V_51 )
F_20 ( V_25 ) ;
if ( V_60 -> V_25 & ~ V_64 )
return - V_61 ;
V_25 -> V_65 = V_60 -> V_25 ;
return 0 ;
}
static void F_22 ( void * V_66 )
{
int V_15 ;
T_1 V_5 ;
struct V_1 * V_2 = V_66 ;
struct V_24 * V_25 = & V_2 -> V_25 ;
F_23 ( V_2 -> V_9 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_1 ( V_2 ) ;
F_15 ( V_2 ) ;
V_5 = F_6 ( V_2 , V_6 ) ;
V_5 &= ~ V_64 ;
V_5 |= V_2 -> V_67 ;
V_5 |= V_68 ;
F_2 ( V_2 , V_25 -> V_65 | V_5 , V_6 ) ;
F_2 ( V_2 , V_25 -> V_30 , V_69 ) ;
F_2 ( V_2 , V_25 -> V_70 , V_71 ) ;
F_2 ( V_2 , V_25 -> V_28 , V_72 ) ;
F_2 ( V_2 , V_25 -> V_26 , V_73 ) ;
F_2 ( V_2 , V_25 -> V_74 , V_75 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_76 ; V_15 ++ ) {
F_2 ( V_2 , V_25 -> V_55 [ V_15 ] , F_24 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_56 [ V_15 ] , F_25 ( V_15 ) ) ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_77 ; V_15 ++ ) {
F_2 ( V_2 , V_25 -> V_40 [ V_15 ] , F_26 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_41 [ V_15 ] , F_27 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_42 [ V_15 ] ,
F_28 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_43 [ V_15 ] , F_29 ( V_15 ) ) ;
}
F_2 ( V_2 , V_25 -> V_32 , V_78 ) ;
F_2 ( V_2 , V_25 -> V_33 , V_79 ) ;
F_2 ( V_2 , V_25 -> V_34 , V_80 ) ;
F_2 ( V_2 , V_25 -> V_35 , V_81 ) ;
F_2 ( V_2 , V_25 -> V_36 , V_82 ) ;
F_2 ( V_2 , V_25 -> V_37 , V_83 ) ;
F_2 ( V_2 , V_25 -> V_44 , V_84 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_85 ; V_15 ++ )
F_2 ( V_2 , V_31 , F_30 ( V_15 ) ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_86 ; V_15 ++ )
F_2 ( V_2 , V_25 -> V_47 [ V_15 ] , F_31 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_49 , V_87 ) ;
F_2 ( V_2 , V_25 -> V_88 , V_89 ) ;
F_2 ( V_2 , 0x0 , V_90 ) ;
F_2 ( V_2 , V_25 -> V_38 , V_91 ) ;
F_2 ( V_2 , 0x0 , V_92 ) ;
F_2 ( V_2 , V_2 -> V_93 , V_94 ) ;
F_2 ( V_2 , 0x0 , V_95 ) ;
F_17 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
F_33 ( V_2 -> V_22 , L_2 , V_2 -> V_96 ) ;
}
static int F_34 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_35 ( V_98 -> V_22 . V_99 ) ;
return V_2 -> V_96 ;
}
int F_36 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
int V_100 = - 1 ;
if ( ! V_2 )
goto V_101;
if ( ! F_37 ( & V_2 -> V_51 ) )
return V_2 -> V_93 ;
F_38 ( V_2 -> V_22 ) ;
F_39 ( & V_2 -> V_102 , V_50 ) ;
F_23 ( V_2 -> V_9 ) ;
V_100 = ( F_6 ( V_2 , V_94 ) & V_103 ) ;
F_32 ( V_2 -> V_9 ) ;
F_40 ( & V_2 -> V_102 , V_50 ) ;
F_41 ( V_2 -> V_22 ) ;
V_101:
return V_100 ;
}
static int F_42 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_35 ( V_98 -> V_22 . V_99 ) ;
return F_36 ( V_2 ) ;
}
static int F_43 ( struct V_97 * V_98 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_35 ( V_98 -> V_22 . V_99 ) ;
if ( F_19 ( V_2 -> V_96 != F_44 () ) )
return - V_61 ;
F_21 ( V_2 , V_60 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_35 ( V_98 -> V_22 . V_99 ) ;
int V_104 ;
F_46 ( & V_2 -> V_102 ) ;
if ( F_47 ( V_2 -> V_96 ) ) {
V_104 = F_48 ( V_2 -> V_96 ,
F_22 , V_2 , 1 ) ;
if ( V_104 )
goto V_105;
}
V_2 -> V_106 = true ;
F_49 ( & V_2 -> V_102 ) ;
F_50 ( V_2 -> V_22 , L_3 ) ;
return 0 ;
V_105:
F_49 ( & V_2 -> V_102 ) ;
return V_104 ;
}
static int F_51 ( struct V_97 * V_98 ,
struct V_59 * V_60 , T_1 V_51 )
{
int V_104 ;
T_1 V_16 ;
struct V_1 * V_2 = F_35 ( V_98 -> V_22 . V_99 ) ;
V_16 = F_52 ( & V_2 -> V_51 , V_107 , V_51 ) ;
if ( V_16 )
return - V_108 ;
switch ( V_51 ) {
case V_109 :
V_104 = F_45 ( V_98 ) ;
break;
case V_110 :
V_104 = F_43 ( V_98 , V_60 ) ;
break;
default:
V_104 = - V_61 ;
}
if ( V_104 )
F_53 ( & V_2 -> V_51 , V_107 ) ;
return V_104 ;
}
static void F_54 ( void * V_66 )
{
int V_15 ;
struct V_1 * V_2 = V_66 ;
struct V_24 * V_25 = & V_2 -> V_25 ;
F_23 ( V_2 -> V_9 ) ;
F_15 ( V_2 ) ;
V_25 -> V_44 = ( F_6 ( V_2 , V_84 ) & V_111 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_77 ; V_15 ++ )
V_25 -> V_43 [ V_15 ] = F_6 ( V_2 , F_29 ( V_15 ) ) ;
F_4 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
F_33 ( V_2 -> V_22 , L_4 , V_2 -> V_96 ) ;
}
static void F_55 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_35 ( V_98 -> V_22 . V_99 ) ;
if ( F_19 ( V_2 -> V_96 != F_44 () ) )
return;
F_23 ( V_2 -> V_9 ) ;
F_15 ( V_2 ) ;
F_4 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
}
static void F_56 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_35 ( V_98 -> V_22 . V_99 ) ;
F_57 () ;
F_46 ( & V_2 -> V_102 ) ;
F_48 ( V_2 -> V_96 , F_54 , V_2 , 1 ) ;
F_49 ( & V_2 -> V_102 ) ;
F_58 () ;
F_50 ( V_2 -> V_22 , L_5 ) ;
}
static void F_59 ( struct V_97 * V_98 )
{
T_1 V_51 ;
struct V_1 * V_2 = F_35 ( V_98 -> V_22 . V_99 ) ;
V_51 = F_37 ( & V_2 -> V_51 ) ;
switch ( V_51 ) {
case V_107 :
break;
case V_109 :
F_56 ( V_98 ) ;
break;
case V_110 :
F_55 ( V_98 ) ;
break;
default:
F_19 ( V_51 ) ;
return;
}
if ( V_51 )
F_53 ( & V_2 -> V_51 , V_107 ) ;
}
static int F_60 ( unsigned int V_96 )
{
if ( ! V_112 [ V_96 ] )
return 0 ;
if ( V_112 [ V_96 ] -> V_113 && ! V_112 [ V_96 ] -> V_106 )
F_61 ( V_112 [ V_96 ] -> V_98 ) ;
return 0 ;
}
static int F_62 ( unsigned int V_96 )
{
if ( ! V_112 [ V_96 ] )
return 0 ;
F_46 ( & V_112 [ V_96 ] -> V_102 ) ;
if ( ! V_112 [ V_96 ] -> V_4 ) {
F_1 ( V_112 [ V_96 ] ) ;
V_112 [ V_96 ] -> V_4 = true ;
}
if ( F_37 ( & V_112 [ V_96 ] -> V_51 ) )
F_22 ( V_112 [ V_96 ] ) ;
F_49 ( & V_112 [ V_96 ] -> V_102 ) ;
return 0 ;
}
static int F_63 ( unsigned int V_96 )
{
if ( ! V_112 [ V_96 ] )
return 0 ;
F_46 ( & V_112 [ V_96 ] -> V_102 ) ;
if ( F_37 ( & V_112 [ V_96 ] -> V_51 ) )
F_54 ( V_112 [ V_96 ] ) ;
F_49 ( & V_112 [ V_96 ] -> V_102 ) ;
return 0 ;
}
static bool F_64 ( T_2 V_114 )
{
switch ( V_114 ) {
case V_115 :
break;
case V_116 :
break;
case V_117 :
break;
case V_118 :
break;
default:
return false ;
}
return true ;
}
static void F_65 ( void * V_66 )
{
T_1 V_119 ;
T_1 V_120 ;
struct V_1 * V_2 = V_66 ;
F_1 ( V_2 ) ;
F_23 ( V_2 -> V_9 ) ;
( void ) F_6 ( V_2 , V_121 ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 ) ;
F_15 ( V_2 ) ;
V_119 = F_6 ( V_2 , V_122 ) ;
V_2 -> V_114 = F_66 ( V_119 , 4 , 11 ) ;
V_2 -> V_67 = F_6 ( V_2 , V_6 ) & V_123 ;
V_2 -> V_124 = F_6 ( V_2 , V_125 ) ;
V_120 = F_6 ( V_2 , V_126 ) ;
V_2 -> V_120 = V_120 ;
V_2 -> V_76 = F_66 ( V_120 , 0 , 3 ) * 2 ;
V_2 -> V_77 = F_66 ( V_120 , 13 , 15 ) ;
V_2 -> V_127 = F_66 ( V_120 , 17 , 19 ) ;
V_2 -> V_85 = F_66 ( V_120 , 20 , 22 ) ;
V_2 -> V_86 = F_66 ( V_120 , 24 , 25 ) ;
F_4 ( V_2 ) ;
F_11 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
V_2 -> V_93 = F_68 ( V_2 -> V_96 ) ;
}
static int F_69 ( struct V_128 * V_129 , const struct V_130 * V_131 )
{
int V_104 ;
void T_3 * V_9 ;
struct V_132 * V_22 = & V_129 -> V_22 ;
struct V_133 * V_134 = NULL ;
struct V_1 * V_2 ;
struct V_135 * V_136 = & V_129 -> V_136 ;
struct V_137 * V_138 ;
struct V_139 * V_140 = V_129 -> V_22 . V_141 ;
V_138 = F_70 ( V_22 , sizeof( * V_138 ) , V_142 ) ;
if ( ! V_138 )
return - V_143 ;
V_2 = F_70 ( V_22 , sizeof( * V_2 ) , V_142 ) ;
if ( ! V_2 )
return - V_143 ;
if ( V_140 ) {
V_134 = F_71 ( V_22 , V_140 ) ;
if ( F_72 ( V_134 ) )
return F_73 ( V_134 ) ;
V_129 -> V_22 . V_144 = V_134 ;
V_2 -> V_145 = F_74 ( V_140 , L_6 ) ;
}
V_2 -> V_22 = & V_129 -> V_22 ;
F_75 ( V_22 , V_2 ) ;
V_9 = F_76 ( V_22 , V_136 ) ;
if ( F_72 ( V_9 ) )
return F_73 ( V_9 ) ;
V_2 -> V_9 = V_9 ;
F_77 ( & V_2 -> V_102 ) ;
V_2 -> V_146 = F_78 ( & V_129 -> V_22 , L_7 ) ;
if ( ! F_72 ( V_2 -> V_146 ) ) {
V_104 = F_79 ( V_2 -> V_146 ) ;
if ( V_104 )
return V_104 ;
}
V_2 -> V_96 = V_134 ? V_134 -> V_96 : 0 ;
F_57 () ;
V_112 [ V_2 -> V_96 ] = V_2 ;
if ( F_48 ( V_2 -> V_96 ,
F_65 , V_2 , 1 ) )
F_16 ( V_22 , L_8 ) ;
if ( ! V_147 ++ ) {
F_80 ( V_148 ,
L_9 ,
F_62 , F_63 ) ;
V_104 = F_80 ( V_149 ,
L_10 ,
F_60 , NULL ) ;
if ( V_104 < 0 )
goto V_150;
V_151 = V_104 ;
}
F_58 () ;
if ( F_64 ( V_2 -> V_114 ) == false ) {
V_104 = - V_61 ;
goto V_150;
}
F_67 ( V_2 ) ;
F_18 ( & V_2 -> V_25 ) ;
V_138 -> type = V_152 ;
V_138 -> V_153 . V_154 = V_155 ;
V_138 -> V_156 = & V_157 ;
V_138 -> V_134 = V_134 ;
V_138 -> V_22 = V_22 ;
V_138 -> V_158 = V_159 ;
V_2 -> V_98 = F_81 ( V_138 ) ;
if ( F_72 ( V_2 -> V_98 ) ) {
V_104 = F_73 ( V_2 -> V_98 ) ;
goto V_150;
}
V_104 = F_82 ( V_2 -> V_98 , true ) ;
if ( V_104 ) {
F_83 ( V_2 -> V_98 ) ;
goto V_150;
}
F_41 ( & V_129 -> V_22 ) ;
F_50 ( V_22 , L_11 , ( char * ) V_131 -> V_160 ) ;
if ( V_113 ) {
F_61 ( V_2 -> V_98 ) ;
V_2 -> V_113 = true ;
}
return 0 ;
V_150:
if ( -- V_147 == 0 ) {
F_84 ( V_148 ) ;
if ( V_151 )
F_84 ( V_151 ) ;
}
return V_104 ;
}
static int F_85 ( struct V_132 * V_22 )
{
struct V_1 * V_2 = F_35 ( V_22 ) ;
if ( V_2 && ! F_72 ( V_2 -> V_146 ) )
F_86 ( V_2 -> V_146 ) ;
return 0 ;
}
static int F_87 ( struct V_132 * V_22 )
{
struct V_1 * V_2 = F_35 ( V_22 ) ;
if ( V_2 && ! F_72 ( V_2 -> V_146 ) )
F_79 ( V_2 -> V_146 ) ;
return 0 ;
}

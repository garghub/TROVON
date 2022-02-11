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
struct V_61 * V_62 = & V_60 -> V_62 ;
if ( ! V_62 )
return - V_63 ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
if ( V_62 -> V_64 )
V_25 -> V_51 = V_52 ;
if ( V_62 -> V_65 )
V_25 -> V_51 = V_53 ;
F_18 ( V_25 ) ;
if ( V_25 -> V_51 )
F_20 ( V_25 ) ;
if ( V_62 -> V_25 & ~ V_66 )
return - V_63 ;
V_25 -> V_67 = V_62 -> V_25 ;
return 0 ;
}
static void F_22 ( void * V_68 )
{
int V_15 ;
T_1 V_5 ;
struct V_1 * V_2 = V_68 ;
struct V_24 * V_25 = & V_2 -> V_25 ;
F_23 ( V_2 -> V_9 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_1 ( V_2 ) ;
F_15 ( V_2 ) ;
V_5 = F_6 ( V_2 , V_6 ) ;
V_5 &= ~ V_66 ;
V_5 |= V_2 -> V_69 ;
V_5 |= V_70 ;
F_2 ( V_2 , V_25 -> V_67 | V_5 , V_6 ) ;
F_2 ( V_2 , V_25 -> V_30 , V_71 ) ;
F_2 ( V_2 , V_25 -> V_72 , V_73 ) ;
F_2 ( V_2 , V_25 -> V_28 , V_74 ) ;
F_2 ( V_2 , V_25 -> V_26 , V_75 ) ;
F_2 ( V_2 , V_25 -> V_76 , V_77 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_78 ; V_15 ++ ) {
F_2 ( V_2 , V_25 -> V_55 [ V_15 ] , F_24 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_56 [ V_15 ] , F_25 ( V_15 ) ) ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_79 ; V_15 ++ ) {
F_2 ( V_2 , V_25 -> V_40 [ V_15 ] , F_26 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_41 [ V_15 ] , F_27 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_42 [ V_15 ] ,
F_28 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_43 [ V_15 ] , F_29 ( V_15 ) ) ;
}
F_2 ( V_2 , V_25 -> V_32 , V_80 ) ;
F_2 ( V_2 , V_25 -> V_33 , V_81 ) ;
F_2 ( V_2 , V_25 -> V_34 , V_82 ) ;
F_2 ( V_2 , V_25 -> V_35 , V_83 ) ;
F_2 ( V_2 , V_25 -> V_36 , V_84 ) ;
F_2 ( V_2 , V_25 -> V_37 , V_85 ) ;
F_2 ( V_2 , V_25 -> V_44 , V_86 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_87 ; V_15 ++ )
F_2 ( V_2 , V_31 , F_30 ( V_15 ) ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_88 ; V_15 ++ )
F_2 ( V_2 , V_25 -> V_47 [ V_15 ] , F_31 ( V_15 ) ) ;
F_2 ( V_2 , V_25 -> V_49 , V_89 ) ;
F_2 ( V_2 , V_25 -> V_90 , V_91 ) ;
F_2 ( V_2 , 0x0 , V_92 ) ;
F_2 ( V_2 , V_25 -> V_38 , V_93 ) ;
F_2 ( V_2 , 0x0 , V_94 ) ;
F_2 ( V_2 , V_2 -> V_95 , V_96 ) ;
F_2 ( V_2 , 0x0 , V_97 ) ;
F_17 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
F_33 ( V_2 -> V_22 , L_2 , V_2 -> V_98 ) ;
}
static int F_34 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_35 ( V_100 -> V_22 . V_101 ) ;
return V_2 -> V_98 ;
}
int F_36 ( struct V_1 * V_2 )
{
unsigned long V_50 ;
int V_102 = - 1 ;
if ( ! V_2 )
goto V_103;
if ( ! F_37 ( & V_2 -> V_51 ) )
return V_2 -> V_95 ;
F_38 ( V_2 -> V_22 ) ;
F_39 ( & V_2 -> V_104 , V_50 ) ;
F_23 ( V_2 -> V_9 ) ;
V_102 = ( F_6 ( V_2 , V_96 ) & V_105 ) ;
F_32 ( V_2 -> V_9 ) ;
F_40 ( & V_2 -> V_104 , V_50 ) ;
F_41 ( V_2 -> V_22 ) ;
V_103:
return V_102 ;
}
static int F_42 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_35 ( V_100 -> V_22 . V_101 ) ;
return F_36 ( V_2 ) ;
}
static int F_43 ( struct V_99 * V_100 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_35 ( V_100 -> V_22 . V_101 ) ;
if ( F_19 ( V_2 -> V_98 != F_44 () ) )
return - V_63 ;
F_21 ( V_2 , V_60 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
static int F_45 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_35 ( V_100 -> V_22 . V_101 ) ;
int V_106 ;
F_46 ( & V_2 -> V_104 ) ;
if ( F_47 ( V_2 -> V_98 ) ) {
V_106 = F_48 ( V_2 -> V_98 ,
F_22 , V_2 , 1 ) ;
if ( V_106 )
goto V_107;
}
V_2 -> V_108 = true ;
F_49 ( & V_2 -> V_104 ) ;
F_50 ( V_2 -> V_22 , L_3 ) ;
return 0 ;
V_107:
F_49 ( & V_2 -> V_104 ) ;
return V_106 ;
}
static int F_51 ( struct V_99 * V_100 ,
struct V_59 * V_60 , T_1 V_51 )
{
int V_106 ;
T_1 V_16 ;
struct V_1 * V_2 = F_35 ( V_100 -> V_22 . V_101 ) ;
V_16 = F_52 ( & V_2 -> V_51 , V_109 , V_51 ) ;
if ( V_16 )
return - V_110 ;
switch ( V_51 ) {
case V_111 :
V_106 = F_45 ( V_100 ) ;
break;
case V_112 :
V_106 = F_43 ( V_100 , V_60 ) ;
break;
default:
V_106 = - V_63 ;
}
if ( V_106 )
F_53 ( & V_2 -> V_51 , V_109 ) ;
return V_106 ;
}
static void F_54 ( void * V_68 )
{
int V_15 ;
struct V_1 * V_2 = V_68 ;
struct V_24 * V_25 = & V_2 -> V_25 ;
F_23 ( V_2 -> V_9 ) ;
F_15 ( V_2 ) ;
V_25 -> V_44 = ( F_6 ( V_2 , V_86 ) & V_113 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_79 ; V_15 ++ )
V_25 -> V_43 [ V_15 ] = F_6 ( V_2 , F_29 ( V_15 ) ) ;
F_4 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
F_33 ( V_2 -> V_22 , L_4 , V_2 -> V_98 ) ;
}
static void F_55 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_35 ( V_100 -> V_22 . V_101 ) ;
if ( F_19 ( V_2 -> V_98 != F_44 () ) )
return;
F_23 ( V_2 -> V_9 ) ;
F_15 ( V_2 ) ;
F_4 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
}
static void F_56 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_35 ( V_100 -> V_22 . V_101 ) ;
F_57 () ;
F_46 ( & V_2 -> V_104 ) ;
F_48 ( V_2 -> V_98 , F_54 , V_2 , 1 ) ;
F_49 ( & V_2 -> V_104 ) ;
F_58 () ;
F_50 ( V_2 -> V_22 , L_5 ) ;
}
static void F_59 ( struct V_99 * V_100 ,
struct V_59 * V_60 )
{
T_1 V_51 ;
struct V_1 * V_2 = F_35 ( V_100 -> V_22 . V_101 ) ;
V_51 = F_37 ( & V_2 -> V_51 ) ;
switch ( V_51 ) {
case V_109 :
break;
case V_111 :
F_56 ( V_100 ) ;
break;
case V_112 :
F_55 ( V_100 ) ;
break;
default:
F_19 ( V_51 ) ;
return;
}
if ( V_51 )
F_53 ( & V_2 -> V_51 , V_109 ) ;
}
static int F_60 ( unsigned int V_98 )
{
if ( ! V_114 [ V_98 ] )
return 0 ;
if ( V_114 [ V_98 ] -> V_115 && ! V_114 [ V_98 ] -> V_108 )
F_61 ( V_114 [ V_98 ] -> V_100 ) ;
return 0 ;
}
static int F_62 ( unsigned int V_98 )
{
if ( ! V_114 [ V_98 ] )
return 0 ;
F_46 ( & V_114 [ V_98 ] -> V_104 ) ;
if ( ! V_114 [ V_98 ] -> V_4 ) {
F_1 ( V_114 [ V_98 ] ) ;
V_114 [ V_98 ] -> V_4 = true ;
}
if ( F_37 ( & V_114 [ V_98 ] -> V_51 ) )
F_22 ( V_114 [ V_98 ] ) ;
F_49 ( & V_114 [ V_98 ] -> V_104 ) ;
return 0 ;
}
static int F_63 ( unsigned int V_98 )
{
if ( ! V_114 [ V_98 ] )
return 0 ;
F_46 ( & V_114 [ V_98 ] -> V_104 ) ;
if ( F_37 ( & V_114 [ V_98 ] -> V_51 ) )
F_54 ( V_114 [ V_98 ] ) ;
F_49 ( & V_114 [ V_98 ] -> V_104 ) ;
return 0 ;
}
static bool F_64 ( T_2 V_116 )
{
switch ( V_116 ) {
case V_117 :
break;
case V_118 :
break;
case V_119 :
break;
case V_120 :
break;
default:
return false ;
}
return true ;
}
static void F_65 ( void * V_68 )
{
T_1 V_121 ;
T_1 V_122 ;
struct V_1 * V_2 = V_68 ;
F_1 ( V_2 ) ;
F_23 ( V_2 -> V_9 ) ;
( void ) F_6 ( V_2 , V_123 ) ;
F_8 ( V_2 ) ;
F_7 ( V_2 ) ;
F_15 ( V_2 ) ;
V_121 = F_6 ( V_2 , V_124 ) ;
V_2 -> V_116 = F_66 ( V_121 , 4 , 11 ) ;
V_2 -> V_69 = F_6 ( V_2 , V_6 ) & V_125 ;
V_2 -> V_126 = F_6 ( V_2 , V_127 ) ;
V_122 = F_6 ( V_2 , V_128 ) ;
V_2 -> V_122 = V_122 ;
V_2 -> V_78 = F_66 ( V_122 , 0 , 3 ) * 2 ;
V_2 -> V_79 = F_66 ( V_122 , 13 , 15 ) ;
V_2 -> V_129 = F_66 ( V_122 , 17 , 19 ) ;
V_2 -> V_87 = F_66 ( V_122 , 20 , 22 ) ;
V_2 -> V_88 = F_66 ( V_122 , 24 , 25 ) ;
F_4 ( V_2 ) ;
F_11 ( V_2 ) ;
F_32 ( V_2 -> V_9 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
V_2 -> V_95 = F_68 ( V_2 -> V_98 ) ;
}
static int F_69 ( struct V_130 * V_131 , const struct V_132 * V_133 )
{
int V_106 ;
void T_3 * V_9 ;
struct V_134 * V_22 = & V_131 -> V_22 ;
struct V_135 * V_136 = NULL ;
struct V_1 * V_2 ;
struct V_137 * V_138 = & V_131 -> V_138 ;
struct V_139 V_140 = { 0 } ;
struct V_141 * V_142 = V_131 -> V_22 . V_143 ;
V_2 = F_70 ( V_22 , sizeof( * V_2 ) , V_144 ) ;
if ( ! V_2 )
return - V_145 ;
if ( V_142 ) {
V_136 = F_71 ( V_22 , V_142 ) ;
if ( F_72 ( V_136 ) )
return F_73 ( V_136 ) ;
V_131 -> V_22 . V_146 = V_136 ;
V_2 -> V_147 = F_74 ( V_142 , L_6 ) ;
}
V_2 -> V_22 = & V_131 -> V_22 ;
F_75 ( V_22 , V_2 ) ;
V_9 = F_76 ( V_22 , V_138 ) ;
if ( F_72 ( V_9 ) )
return F_73 ( V_9 ) ;
V_2 -> V_9 = V_9 ;
F_77 ( & V_2 -> V_104 ) ;
V_2 -> V_148 = F_78 ( & V_131 -> V_22 , L_7 ) ;
if ( ! F_72 ( V_2 -> V_148 ) ) {
V_106 = F_79 ( V_2 -> V_148 ) ;
if ( V_106 )
return V_106 ;
}
V_2 -> V_98 = V_136 ? V_136 -> V_98 : 0 ;
F_57 () ;
V_114 [ V_2 -> V_98 ] = V_2 ;
if ( F_48 ( V_2 -> V_98 ,
F_65 , V_2 , 1 ) )
F_16 ( V_22 , L_8 ) ;
if ( ! V_149 ++ ) {
F_80 ( V_150 ,
L_9 ,
F_62 , F_63 ) ;
V_106 = F_80 ( V_151 ,
L_10 ,
F_60 , NULL ) ;
if ( V_106 < 0 )
goto V_152;
V_153 = V_106 ;
}
F_58 () ;
if ( F_64 ( V_2 -> V_116 ) == false ) {
V_106 = - V_63 ;
goto V_152;
}
F_67 ( V_2 ) ;
F_18 ( & V_2 -> V_25 ) ;
V_140 . type = V_154 ;
V_140 . V_155 . V_156 = V_157 ;
V_140 . V_158 = & V_159 ;
V_140 . V_136 = V_136 ;
V_140 . V_22 = V_22 ;
V_140 . V_160 = V_161 ;
V_2 -> V_100 = F_81 ( & V_140 ) ;
if ( F_72 ( V_2 -> V_100 ) ) {
V_106 = F_73 ( V_2 -> V_100 ) ;
goto V_152;
}
V_106 = F_82 ( V_2 -> V_100 , true ) ;
if ( V_106 ) {
F_83 ( V_2 -> V_100 ) ;
goto V_152;
}
F_41 ( & V_131 -> V_22 ) ;
F_50 ( V_22 , L_11 , ( char * ) V_133 -> V_162 ) ;
if ( V_115 ) {
F_61 ( V_2 -> V_100 ) ;
V_2 -> V_115 = true ;
}
return 0 ;
V_152:
if ( -- V_149 == 0 ) {
F_84 ( V_150 ) ;
if ( V_153 )
F_84 ( V_153 ) ;
}
return V_106 ;
}
static int F_85 ( struct V_134 * V_22 )
{
struct V_1 * V_2 = F_35 ( V_22 ) ;
if ( V_2 && ! F_72 ( V_2 -> V_148 ) )
F_86 ( V_2 -> V_148 ) ;
return 0 ;
}
static int F_87 ( struct V_134 * V_22 )
{
struct V_1 * V_2 = F_35 ( V_22 ) ;
if ( V_2 && ! F_72 ( V_2 -> V_148 ) )
F_79 ( V_2 -> V_148 ) ;
return 0 ;
}

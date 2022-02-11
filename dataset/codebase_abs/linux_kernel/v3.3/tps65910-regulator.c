static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_5 ;
V_5 = V_2 -> V_6 -> V_7 ( V_2 -> V_6 , V_3 , 1 , & V_4 ) ;
if ( V_5 )
return V_5 ;
return V_4 ;
}
static inline int F_2 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return V_2 -> V_6 -> V_8 ( V_2 -> V_6 , V_3 , 1 , & V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_9 , T_1 V_10 )
{
int V_5 , V_11 ;
F_4 ( & V_2 -> V_12 ) ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( V_11 < 0 ) {
F_5 ( V_2 -> V_6 -> V_13 , L_1 , V_3 ) ;
V_5 = V_11 ;
goto V_14;
}
V_11 &= ~ V_10 ;
V_11 |= V_9 ;
V_5 = F_2 ( V_2 , V_3 , V_11 ) ;
if ( V_5 )
F_5 ( V_2 -> V_6 -> V_13 , L_2 , V_3 ) ;
V_14:
F_6 ( & V_2 -> V_12 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_11 ;
F_4 ( & V_2 -> V_12 ) ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( V_11 < 0 )
F_5 ( V_2 -> V_6 -> V_13 , L_1 , V_3 ) ;
F_6 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
F_4 ( & V_2 -> V_12 ) ;
V_5 = F_2 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 )
F_5 ( V_2 -> V_6 -> V_13 , L_2 , V_3 ) ;
F_6 ( & V_2 -> V_12 ) ;
return V_5 ;
}
static int F_9 ( int V_15 )
{
switch ( V_15 ) {
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
return V_31 ;
case V_32 :
return V_33 ;
case V_34 :
return V_35 ;
case V_36 :
return V_37 ;
case V_38 :
return V_39 ;
case V_40 :
return V_41 ;
default:
return - V_42 ;
}
}
static int F_10 ( int V_15 )
{
switch ( V_15 ) {
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_43 :
return V_44 ;
case V_45 :
return V_46 ;
case V_47 :
return V_48 ;
case V_49 :
return V_50 ;
case V_51 :
return V_52 ;
case V_53 :
return V_54 ;
case V_55 :
return V_56 ;
case V_57 :
return V_58 ;
case V_59 :
return V_60 ;
default:
return - V_42 ;
}
}
static int F_11 ( struct V_61 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
int V_3 , V_62 , V_15 = F_13 ( V_13 ) ;
V_3 = V_2 -> V_63 ( V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
V_62 = F_7 ( V_2 , V_3 ) ;
if ( V_62 < 0 )
return V_62 ;
return V_62 & V_64 ;
}
static int F_14 ( struct V_61 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_65 * V_6 = V_2 -> V_6 ;
int V_3 , V_15 = F_13 ( V_13 ) ;
V_3 = V_2 -> V_63 ( V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_15 ( V_6 , V_3 , V_64 ) ;
}
static int F_16 ( struct V_61 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_65 * V_6 = V_2 -> V_6 ;
int V_3 , V_15 = F_13 ( V_13 ) ;
V_3 = V_2 -> V_63 ( V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
return F_17 ( V_6 , V_3 , V_64 ) ;
}
static int F_18 ( struct V_61 * V_13 , unsigned int V_66 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
struct V_65 * V_6 = V_2 -> V_6 ;
int V_3 , V_62 , V_15 = F_13 ( V_13 ) ;
V_3 = V_2 -> V_63 ( V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
switch ( V_66 ) {
case V_67 :
return F_3 ( V_2 , V_3 , V_68 ,
V_69 ) ;
case V_70 :
V_62 = V_68 | V_69 ;
return F_15 ( V_6 , V_3 , V_62 ) ;
case V_71 :
return F_17 ( V_6 , V_3 , V_68 ) ;
}
return - V_42 ;
}
static unsigned int F_19 ( struct V_61 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
int V_3 , V_62 , V_15 = F_13 ( V_13 ) ;
V_3 = V_2 -> V_63 ( V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
V_62 = F_7 ( V_2 , V_3 ) ;
if ( V_62 < 0 )
return V_62 ;
if ( V_62 & V_68 )
return V_71 ;
else if ( V_62 & V_69 )
return V_70 ;
else
return V_67 ;
}
static int F_20 ( struct V_61 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
int V_15 = F_13 ( V_13 ) , V_72 = 0 ;
int V_73 = 0 , V_74 = 0 , V_75 = 0 , V_76 = 0 , V_77 = 0 ;
switch ( V_15 ) {
case V_20 :
V_73 = F_7 ( V_2 , V_78 ) ;
V_76 = F_7 ( V_2 , V_21 ) ;
V_76 = ( V_76 & V_79 ) >> V_80 ;
V_74 = F_7 ( V_2 , V_81 ) ;
V_77 = V_73 & V_82 ;
V_73 &= V_83 ;
V_74 &= V_84 ;
V_75 = 75 ;
break;
case V_22 :
V_73 = F_7 ( V_2 , V_85 ) ;
V_76 = F_7 ( V_2 , V_23 ) ;
V_76 = ( V_76 & V_86 ) >> V_87 ;
V_74 = F_7 ( V_2 , V_88 ) ;
V_77 = V_73 & V_89 ;
V_73 &= V_90 ;
V_74 &= V_91 ;
V_75 = 75 ;
break;
case V_43 :
V_73 = F_7 ( V_2 , V_92 ) ;
V_74 = F_7 ( V_2 , V_93 ) ;
V_77 = V_73 & V_94 ;
V_73 &= V_95 ;
V_74 &= V_96 ;
V_75 = 64 ;
break;
}
if ( ! V_76 )
V_76 = 1 ;
if ( V_77 ) {
if ( V_74 < 3 )
V_74 = 3 ;
if ( V_74 > V_75 )
V_74 = V_75 ;
V_74 -= 3 ;
V_72 = ( V_74 * V_97 + V_98 ) * 100 ;
} else {
if ( V_73 < 3 )
V_73 = 3 ;
if ( V_73 > V_75 )
V_73 = V_75 ;
V_73 -= 3 ;
V_72 = ( V_73 * V_97 + V_98 ) * 100 ;
}
V_72 *= V_76 ;
return V_72 ;
}
static int F_21 ( struct V_61 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
int V_3 , V_62 , V_15 = F_13 ( V_13 ) , V_72 = 0 ;
V_3 = V_2 -> V_63 ( V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
V_62 = F_7 ( V_2 , V_3 ) ;
if ( V_62 < 0 )
return V_62 ;
switch ( V_15 ) {
case V_18 :
case V_26 :
case V_28 :
case V_30 :
case V_32 :
case V_34 :
case V_36 :
case V_38 :
case V_40 :
V_62 &= V_99 ;
V_62 >>= V_100 ;
break;
default:
return - V_42 ;
}
V_72 = V_2 -> V_101 [ V_15 ] -> V_102 [ V_62 ] * 1000 ;
return V_72 ;
}
static int F_22 ( struct V_61 * V_13 )
{
return 5 * 1000 * 1000 ;
}
static int F_23 ( struct V_61 * V_13 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
int V_103 , V_15 = F_13 ( V_13 ) ;
T_1 V_62 , V_3 ;
V_3 = V_2 -> V_63 ( V_15 ) ;
V_62 = F_7 ( V_2 , V_3 ) ;
switch ( V_15 ) {
case V_45 :
case V_47 :
case V_51 :
V_62 &= V_104 ;
V_62 >>= V_100 ;
if ( V_62 < 5 )
V_62 = 0 ;
else
V_62 -= 4 ;
V_103 = 50 ;
break;
case V_49 :
case V_53 :
case V_55 :
case V_57 :
case V_59 :
V_62 &= V_105 ;
V_62 >>= V_100 ;
if ( V_62 < 3 )
V_62 = 0 ;
else
V_62 -= 2 ;
V_103 = 100 ;
break;
case V_18 :
return V_2 -> V_101 [ V_15 ] -> V_102 [ V_62 ] * 1000 ;
break;
default:
return - V_42 ;
}
return ( V_106 + V_62 * V_103 ) * 1000 ;
}
static int F_24 ( struct V_61 * V_13 ,
unsigned V_107 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
int V_15 = F_13 ( V_13 ) , V_108 ;
int V_109 = 0 ;
switch ( V_15 ) {
case V_20 :
V_109 = ( V_107 / V_110 ) + 1 ;
if ( V_109 == 1 )
V_109 -- ;
V_108 = ( V_107 % V_110 ) + 3 ;
F_3 ( V_2 , V_21 ,
( V_109 << V_80 ) ,
V_79 ) ;
F_8 ( V_2 , V_78 , V_108 ) ;
break;
case V_22 :
V_109 = ( V_107 / V_110 ) + 1 ;
if ( V_109 == 1 )
V_109 -- ;
V_108 = ( V_107 % V_110 ) + 3 ;
F_3 ( V_2 , V_23 ,
( V_109 << V_87 ) ,
V_79 ) ;
F_8 ( V_2 , V_85 , V_108 ) ;
break;
case V_43 :
V_108 = V_107 + 3 ;
F_8 ( V_2 , V_92 , V_108 ) ;
}
return 0 ;
}
static int F_25 ( struct V_61 * V_13 , unsigned V_107 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
int V_3 , V_15 = F_13 ( V_13 ) ;
V_3 = V_2 -> V_63 ( V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
switch ( V_15 ) {
case V_18 :
case V_26 :
case V_28 :
case V_30 :
case V_32 :
case V_34 :
case V_36 :
case V_38 :
case V_40 :
return F_3 ( V_2 , V_3 ,
( V_107 << V_100 ) , V_99 ) ;
}
return - V_42 ;
}
static int F_26 ( struct V_61 * V_13 , unsigned V_107 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
int V_3 , V_15 = F_13 ( V_13 ) ;
V_3 = V_2 -> V_63 ( V_15 ) ;
if ( V_3 < 0 )
return V_3 ;
switch ( V_15 ) {
case V_45 :
case V_47 :
case V_51 :
return F_3 ( V_2 , V_3 ,
( V_107 << V_100 ) , V_104 ) ;
case V_49 :
case V_53 :
case V_55 :
case V_57 :
case V_59 :
case V_18 :
return F_3 ( V_2 , V_3 ,
( V_107 << V_100 ) , V_105 ) ;
}
return - V_42 ;
}
static int F_27 ( struct V_61 * V_13 ,
unsigned V_107 )
{
int V_111 , V_76 = 1 , V_15 = F_13 ( V_13 ) ;
switch ( V_15 ) {
case V_20 :
case V_22 :
V_76 = ( V_107 / V_110 ) + 1 ;
V_111 = V_98 +
( V_107 % V_110 ) * V_97 ;
break;
case V_43 :
V_111 = V_112 + ( V_107 * V_113 ) ;
break;
default:
F_28 () ;
return - V_42 ;
}
return V_111 * 100 * V_76 ;
}
static int F_29 ( struct V_61 * V_13 ,
unsigned V_107 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
int V_15 = F_13 ( V_13 ) , V_72 ;
if ( V_15 < V_18 || V_15 > V_40 )
return - V_42 ;
if ( V_107 >= V_2 -> V_101 [ V_15 ] -> V_114 )
return - V_42 ;
else
V_72 = V_2 -> V_101 [ V_15 ] -> V_102 [ V_107 ] * 1000 ;
return V_72 ;
}
static int F_30 ( struct V_61 * V_13 , unsigned V_107 )
{
struct V_1 * V_2 = F_12 ( V_13 ) ;
int V_103 = 0 , V_15 = F_13 ( V_13 ) ;
switch( V_15 ) {
case V_45 :
case V_47 :
case V_51 :
if ( V_107 < 5 )
V_107 = 0 ;
else
V_107 -= 4 ;
V_103 = 50 ;
break;
case V_49 :
case V_53 :
case V_55 :
case V_57 :
case V_59 :
if ( V_107 < 3 )
V_107 = 0 ;
else
V_107 -= 2 ;
V_103 = 100 ;
break;
case V_18 :
return V_2 -> V_101 [ V_15 ] -> V_102 [ V_107 ] * 1000 ;
default:
return - V_42 ;
}
return ( V_106 + V_107 * V_103 ) * 1000 ;
}
static T_2 int F_31 ( struct V_115 * V_116 )
{
struct V_65 * V_65 = F_32 ( V_116 -> V_13 . V_117 ) ;
struct V_118 * V_101 ;
struct V_119 * V_120 ;
struct V_61 * V_121 ;
struct V_1 * V_2 ;
struct V_122 * V_123 ;
int V_124 , V_5 ;
V_123 = F_33 ( V_65 -> V_13 ) ;
if ( ! V_123 )
return - V_42 ;
V_2 = F_34 ( sizeof( * V_2 ) , V_125 ) ;
if ( ! V_2 )
return - V_126 ;
F_35 ( & V_2 -> V_12 ) ;
V_2 -> V_6 = V_65 ;
F_36 ( V_116 , V_2 ) ;
F_15 ( V_2 -> V_6 , V_127 ,
V_128 ) ;
switch( F_37 ( V_65 ) ) {
case V_129 :
V_2 -> V_63 = & F_9 ;
V_2 -> V_130 = F_38 ( V_131 ) ;
V_101 = V_131 ;
break;
case V_132 :
V_2 -> V_63 = & F_10 ;
V_2 -> V_130 = F_38 ( V_133 ) ;
V_101 = V_133 ;
break;
default:
F_39 ( L_3 ) ;
F_40 ( V_2 ) ;
return - V_134 ;
}
V_2 -> V_135 = F_41 ( V_2 -> V_130 ,
sizeof( struct V_136 ) , V_125 ) ;
if ( ! V_2 -> V_135 ) {
V_5 = - V_126 ;
goto V_137;
}
V_2 -> V_101 = F_41 ( V_2 -> V_130 ,
sizeof( struct V_118 * ) , V_125 ) ;
if ( ! V_2 -> V_101 ) {
V_5 = - V_126 ;
goto V_138;
}
V_2 -> V_121 = F_41 ( V_2 -> V_130 ,
sizeof( struct V_61 * ) , V_125 ) ;
if ( ! V_2 -> V_121 ) {
V_5 = - V_126 ;
goto V_139;
}
for ( V_124 = 0 ; V_124 < V_2 -> V_130 && V_124 < V_140 ;
V_124 ++ , V_101 ++ ) {
V_120 = V_123 -> V_141 [ V_124 ] ;
if ( ! V_120 )
continue;
V_2 -> V_101 [ V_124 ] = V_101 ;
V_2 -> V_135 [ V_124 ] . V_142 = V_101 -> V_142 ;
V_2 -> V_135 [ V_124 ] . V_15 = V_124 ;
V_2 -> V_135 [ V_124 ] . V_143 = V_101 -> V_114 ;
if ( V_124 == V_20 || V_124 == V_22 ) {
V_2 -> V_135 [ V_124 ] . V_144 = & V_145 ;
V_2 -> V_135 [ V_124 ] . V_143 = V_110 *
V_146 ;
} else if ( V_124 == V_24 ) {
if ( F_37 ( V_65 ) == V_129 )
V_2 -> V_135 [ V_124 ] . V_144 = & V_147 ;
else
V_2 -> V_135 [ V_124 ] . V_144 = & V_145 ;
} else {
if ( F_37 ( V_65 ) == V_129 )
V_2 -> V_135 [ V_124 ] . V_144 = & V_148 ;
else
V_2 -> V_135 [ V_124 ] . V_144 = & V_149 ;
}
V_2 -> V_135 [ V_124 ] . type = V_150 ;
V_2 -> V_135 [ V_124 ] . V_151 = V_152 ;
V_121 = F_42 ( & V_2 -> V_135 [ V_124 ] ,
V_65 -> V_13 , V_120 , V_2 , NULL ) ;
if ( F_43 ( V_121 ) ) {
F_5 ( V_65 -> V_13 ,
L_4 ,
V_116 -> V_142 ) ;
V_5 = F_44 ( V_121 ) ;
goto V_153;
}
V_2 -> V_121 [ V_124 ] = V_121 ;
}
return 0 ;
V_153:
while ( -- V_124 >= 0 )
F_45 ( V_2 -> V_121 [ V_124 ] ) ;
F_40 ( V_2 -> V_121 ) ;
V_139:
F_40 ( V_2 -> V_101 ) ;
V_138:
F_40 ( V_2 -> V_135 ) ;
V_137:
F_40 ( V_2 ) ;
return V_5 ;
}
static int T_3 F_46 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = F_47 ( V_116 ) ;
int V_124 ;
for ( V_124 = 0 ; V_124 < V_2 -> V_130 ; V_124 ++ )
F_45 ( V_2 -> V_121 [ V_124 ] ) ;
F_40 ( V_2 -> V_121 ) ;
F_40 ( V_2 -> V_101 ) ;
F_40 ( V_2 -> V_135 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static int T_4 F_48 ( void )
{
return F_49 ( & V_154 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_154 ) ;
}

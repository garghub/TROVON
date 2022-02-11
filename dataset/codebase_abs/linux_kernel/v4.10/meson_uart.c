static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
}
static unsigned int F_2 ( struct V_1 * V_2 )
{
return V_4 ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_7 ) ;
V_5 &= ( V_8 | V_9 ) ;
return ( V_5 == V_8 ) ? V_10 : 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 &= ~ V_12 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 &= ~ V_13 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
T_1 V_5 ;
F_9 ( V_2 -> V_15 , V_2 ) ;
F_10 ( & V_2 -> V_16 , V_14 ) ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 &= ~ V_13 ;
V_5 &= ~ ( V_17 | V_12 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
F_11 ( & V_2 -> V_16 , V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = & V_2 -> V_20 -> V_19 ;
unsigned int V_21 ;
T_1 V_5 ;
if ( F_13 ( V_2 ) ) {
F_5 ( V_2 ) ;
return;
}
while ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_22 ) ) {
if ( V_2 -> V_23 ) {
F_6 ( V_2 -> V_23 , V_2 -> V_6 + V_24 ) ;
V_2 -> V_25 . V_26 ++ ;
V_2 -> V_23 = 0 ;
continue;
}
if ( F_14 ( V_19 ) )
break;
V_21 = V_19 -> V_27 [ V_19 -> V_28 ] ;
F_6 ( V_21 , V_2 -> V_6 + V_24 ) ;
V_19 -> V_28 = ( V_19 -> V_28 + 1 ) & ( V_29 - 1 ) ;
V_2 -> V_25 . V_26 ++ ;
}
if ( ! F_14 ( V_19 ) ) {
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 |= V_12 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
}
if ( F_15 ( V_19 ) < V_30 )
F_16 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_20 -> V_2 ;
char V_33 ;
T_1 V_34 , V_21 , V_35 ;
do {
V_33 = V_36 ;
V_2 -> V_25 . V_37 ++ ;
V_34 = F_4 ( V_2 -> V_6 + V_7 ) ;
if ( V_34 & V_38 ) {
if ( V_34 & V_39 )
V_2 -> V_25 . V_40 ++ ;
else if ( V_34 & V_41 )
V_2 -> V_25 . V_42 ++ ;
else if ( V_34 & V_43 )
V_2 -> V_25 . V_42 ++ ;
V_35 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_35 |= V_44 ;
F_6 ( V_35 , V_2 -> V_6 + V_11 ) ;
V_35 &= ~ V_44 ;
F_6 ( V_35 , V_2 -> V_6 + V_11 ) ;
V_34 &= V_2 -> V_45 ;
if ( V_34 & V_41 )
V_33 = V_46 ;
else if ( V_34 & V_43 )
V_33 = V_47 ;
}
V_21 = F_4 ( V_2 -> V_6 + V_48 ) ;
V_21 &= 0xff ;
if ( ( V_34 & V_2 -> V_49 ) == 0 )
F_18 ( V_32 , V_21 , V_33 ) ;
if ( V_34 & V_39 )
F_18 ( V_32 , 0 , V_50 ) ;
} while ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_51 ) );
F_19 ( & V_2 -> V_16 ) ;
F_20 ( V_32 ) ;
F_21 ( & V_2 -> V_16 ) ;
}
static T_2 F_22 ( int V_15 , void * V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 ;
F_21 ( & V_2 -> V_16 ) ;
if ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_51 ) )
F_17 ( V_2 ) ;
if ( ! ( F_4 ( V_2 -> V_6 + V_7 ) & V_22 ) ) {
if ( F_4 ( V_2 -> V_6 + V_11 ) & V_12 )
F_12 ( V_2 ) ;
}
F_19 ( & V_2 -> V_16 ) ;
return V_53 ;
}
static const char * F_23 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_54 ) ? L_1 : NULL ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 |= ( V_55 | V_56 | V_57 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_5 &= ~ ( V_55 | V_56 | V_57 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
T_1 V_5 ;
int V_58 = 0 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 |= V_57 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_5 &= ~ V_57 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_5 |= ( V_13 | V_59 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_5 |= ( V_17 | V_12 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_5 = ( F_26 ( 1 ) | F_27 ( V_2 -> V_60 / 2 ) ) ;
F_6 ( V_5 , V_2 -> V_6 + V_61 ) ;
V_58 = F_28 ( V_2 -> V_15 , F_22 , 0 ,
F_23 ( V_2 ) , V_2 ) ;
return V_58 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned long V_62 )
{
T_1 V_5 ;
while ( ! F_3 ( V_2 ) )
F_30 () ;
V_5 = F_4 ( V_2 -> V_6 + V_63 ) ;
V_5 &= ~ V_64 ;
if ( V_2 -> V_65 == 24000000 ) {
V_5 = ( ( V_2 -> V_65 / 3 ) / V_62 ) - 1 ;
V_5 |= V_66 ;
} else {
V_5 = ( ( V_2 -> V_65 * 10 / ( V_62 * 4 ) + 5 ) / 10 ) - 1 ;
}
V_5 |= V_67 ;
F_6 ( V_5 , V_2 -> V_6 + V_63 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
struct V_68 * V_70 )
{
unsigned int V_71 , V_72 , V_62 ;
unsigned long V_14 ;
T_1 V_5 ;
F_10 ( & V_2 -> V_16 , V_14 ) ;
V_71 = V_69 -> V_73 ;
V_72 = V_69 -> V_74 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 &= ~ V_75 ;
switch ( V_71 & V_76 ) {
case V_77 :
V_5 |= V_78 ;
break;
case V_79 :
V_5 |= V_80 ;
break;
case V_81 :
V_5 |= V_82 ;
break;
case V_83 :
V_5 |= V_84 ;
break;
}
if ( V_71 & V_85 )
V_5 |= V_86 ;
else
V_5 &= ~ V_86 ;
if ( V_71 & V_87 )
V_5 |= V_88 ;
else
V_5 &= ~ V_88 ;
V_5 &= ~ V_89 ;
if ( V_71 & V_90 )
V_5 |= V_91 ;
else
V_5 &= ~ V_92 ;
if ( V_71 & V_93 )
V_5 &= ~ V_94 ;
else
V_5 |= V_94 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_62 = F_32 ( V_2 , V_69 , V_70 , 9600 , 115200 ) ;
F_29 ( V_2 , V_62 ) ;
V_2 -> V_45 = V_39 ;
if ( V_72 & V_95 )
V_2 -> V_45 |= V_43 |
V_41 ;
V_2 -> V_49 = 0 ;
if ( V_72 & V_96 )
V_2 -> V_49 |= V_43 |
V_41 ;
F_33 ( V_2 , V_69 -> V_73 , V_62 ) ;
F_11 ( & V_2 -> V_16 , V_14 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
int V_58 = 0 ;
if ( V_2 -> type != V_54 )
V_58 = - V_99 ;
if ( V_2 -> V_15 != V_98 -> V_15 )
V_58 = - V_99 ;
if ( V_98 -> V_100 < 9600 )
V_58 = - V_99 ;
return V_58 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_101 * V_102 = F_36 ( V_2 -> V_103 ) ;
struct V_104 * V_105 ;
V_105 = F_37 ( V_102 , V_106 , 0 ) ;
if ( ! V_105 ) {
F_38 ( V_2 -> V_103 , L_2 ) ;
return - V_107 ;
}
return F_39 ( V_105 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
int V_108 = F_35 ( V_2 ) ;
if ( V_2 -> V_14 & V_109 ) {
F_41 ( V_2 -> V_103 , V_2 -> V_110 , V_108 ) ;
F_42 ( V_2 -> V_103 , V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
int V_108 = F_35 ( V_2 ) ;
if ( V_108 < 0 )
return V_108 ;
if ( ! F_44 ( V_2 -> V_103 , V_2 -> V_110 , V_108 ,
F_45 ( V_2 -> V_103 ) ) ) {
F_38 ( V_2 -> V_103 , L_3 ) ;
return - V_111 ;
}
if ( V_2 -> V_14 & V_109 ) {
V_2 -> V_6 = F_46 ( V_2 -> V_103 ,
V_2 -> V_110 ,
V_108 ) ;
if ( V_2 -> V_6 == NULL )
return - V_112 ;
}
return 0 ;
}
static void F_47 ( struct V_1 * V_2 , int V_14 )
{
if ( V_14 & V_113 ) {
V_2 -> type = V_54 ;
F_43 ( V_2 ) ;
}
}
static void F_48 ( struct V_1 * V_2 , int V_21 )
{
if ( ! V_2 -> V_6 )
return;
while ( F_4 ( V_2 -> V_6 + V_7 ) & V_22 )
F_30 () ;
F_6 ( V_21 , V_2 -> V_6 + V_24 ) ;
}
static void F_49 ( struct V_1 * V_2 , const char * V_114 ,
T_3 V_115 )
{
unsigned long V_14 ;
int V_116 ;
T_1 V_5 , V_117 ;
F_50 ( V_14 ) ;
if ( V_2 -> V_118 ) {
V_116 = 0 ;
} else if ( V_119 ) {
V_116 = F_51 ( & V_2 -> V_16 ) ;
} else {
F_21 ( & V_2 -> V_16 ) ;
V_116 = 1 ;
}
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 |= V_59 ;
V_117 = V_5 & ~ ( V_12 | V_17 ) ;
F_6 ( V_117 , V_2 -> V_6 + V_11 ) ;
F_52 ( V_2 , V_114 , V_115 , F_48 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
if ( V_116 )
F_19 ( & V_2 -> V_16 ) ;
F_53 ( V_14 ) ;
}
static void F_54 ( struct V_120 * V_121 , const char * V_114 ,
T_3 V_115 )
{
struct V_1 * V_2 ;
V_2 = V_122 [ V_121 -> V_123 ] ;
if ( ! V_2 )
return;
F_49 ( V_2 , V_114 , V_115 ) ;
}
static int F_55 ( struct V_120 * V_121 , char * V_124 )
{
struct V_1 * V_2 ;
int V_62 = 115200 ;
int V_125 = 8 ;
int V_126 = 'n' ;
int V_127 = 'n' ;
if ( V_121 -> V_123 < 0 || V_121 -> V_123 >= V_128 )
return - V_99 ;
V_2 = V_122 [ V_121 -> V_123 ] ;
if ( ! V_2 || ! V_2 -> V_6 )
return - V_107 ;
if ( V_124 )
F_56 ( V_124 , & V_62 , & V_126 , & V_125 , & V_127 ) ;
return F_57 ( V_2 , V_121 , V_62 , V_126 , V_125 , V_127 ) ;
}
static int T_4 F_58 ( void )
{
F_59 ( & V_129 ) ;
return 0 ;
}
static void F_60 ( struct V_120 * V_121 ,
const char * V_114 ,
T_3 V_115 )
{
struct V_130 * V_103 = V_121 -> V_131 ;
F_49 ( & V_103 -> V_2 , V_114 , V_115 ) ;
}
static int T_4
F_61 ( struct V_130 * V_132 , const char * V_133 )
{
if ( ! V_132 -> V_2 . V_6 )
return - V_107 ;
V_132 -> V_134 -> V_135 = F_60 ;
return 0 ;
}
static int F_62 ( struct V_101 * V_102 )
{
struct V_104 * V_136 , * V_137 ;
struct V_1 * V_2 ;
struct V_138 * V_138 ;
int V_58 = 0 ;
if ( V_102 -> V_103 . V_139 )
V_102 -> V_140 = F_63 ( V_102 -> V_103 . V_139 , L_4 ) ;
if ( V_102 -> V_140 < 0 || V_102 -> V_140 >= V_128 )
return - V_99 ;
V_136 = F_37 ( V_102 , V_106 , 0 ) ;
if ( ! V_136 )
return - V_107 ;
V_137 = F_37 ( V_102 , V_141 , 0 ) ;
if ( ! V_137 )
return - V_107 ;
if ( V_122 [ V_102 -> V_140 ] ) {
F_38 ( & V_102 -> V_103 , L_5 , V_102 -> V_140 ) ;
return - V_111 ;
}
V_2 = F_64 ( & V_102 -> V_103 , sizeof( struct V_1 ) , V_142 ) ;
if ( ! V_2 )
return - V_112 ;
V_138 = F_65 ( & V_102 -> V_103 , NULL ) ;
if ( F_66 ( V_138 ) )
return F_67 ( V_138 ) ;
V_2 -> V_65 = F_68 ( V_138 ) ;
V_2 -> V_143 = V_144 ;
V_2 -> V_110 = V_136 -> V_145 ;
V_2 -> V_15 = V_137 -> V_145 ;
V_2 -> V_14 = V_146 | V_109 | V_147 ;
V_2 -> V_103 = & V_102 -> V_103 ;
V_2 -> line = V_102 -> V_140 ;
V_2 -> type = V_54 ;
V_2 -> V_23 = 0 ;
V_2 -> V_148 = & V_149 ;
V_2 -> V_60 = 64 ;
V_122 [ V_102 -> V_140 ] = V_2 ;
F_69 ( V_102 , V_2 ) ;
if ( F_43 ( V_2 ) >= 0 ) {
F_24 ( V_2 ) ;
F_40 ( V_2 ) ;
}
V_58 = F_70 ( & V_150 , V_2 ) ;
if ( V_58 )
V_122 [ V_102 -> V_140 ] = NULL ;
return V_58 ;
}
static int F_71 ( struct V_101 * V_102 )
{
struct V_1 * V_2 ;
V_2 = F_72 ( V_102 ) ;
F_73 ( & V_150 , V_2 ) ;
V_122 [ V_102 -> V_140 ] = NULL ;
return 0 ;
}
static int T_4 F_74 ( void )
{
int V_58 ;
V_58 = F_75 ( & V_150 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_76 ( & V_151 ) ;
if ( V_58 )
F_77 ( & V_150 ) ;
return V_58 ;
}
static void T_5 F_78 ( void )
{
F_79 ( & V_151 ) ;
F_77 ( & V_150 ) ;
}

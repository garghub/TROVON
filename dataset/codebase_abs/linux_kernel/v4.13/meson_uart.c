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
V_2 -> V_62 , V_2 ) ;
return V_58 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned long V_63 )
{
T_1 V_5 ;
while ( ! F_3 ( V_2 ) )
F_30 () ;
if ( V_2 -> V_64 == 24000000 ) {
V_5 = ( ( V_2 -> V_64 / 3 ) / V_63 ) - 1 ;
V_5 |= V_65 ;
} else {
V_5 = ( ( V_2 -> V_64 * 10 / ( V_63 * 4 ) + 5 ) / 10 ) - 1 ;
}
V_5 |= V_66 ;
F_6 ( V_5 , V_2 -> V_6 + V_67 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
struct V_68 * V_70 )
{
unsigned int V_71 , V_72 , V_63 ;
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
V_5 |= V_92 ;
if ( V_71 & V_93 )
V_5 &= ~ V_94 ;
else
V_5 |= V_94 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
V_63 = F_32 ( V_2 , V_69 , V_70 , 9600 , 4000000 ) ;
F_29 ( V_2 , V_63 ) ;
V_2 -> V_45 = V_39 ;
if ( V_72 & V_95 )
V_2 -> V_45 |= V_43 |
V_41 ;
V_2 -> V_49 = 0 ;
if ( V_72 & V_96 )
V_2 -> V_49 |= V_43 |
V_41 ;
F_33 ( V_2 , V_69 -> V_73 , V_63 ) ;
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
static void F_35 ( struct V_1 * V_2 )
{
F_36 ( V_2 -> V_101 , V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
F_37 ( V_2 -> V_101 , V_2 -> V_102 , V_2 -> V_103 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
if ( ! F_39 ( V_2 -> V_101 , V_2 -> V_102 , V_2 -> V_103 ,
F_40 ( V_2 -> V_101 ) ) ) {
F_41 ( V_2 -> V_101 , L_2 ) ;
return - V_104 ;
}
V_2 -> V_6 = F_42 ( V_2 -> V_101 , V_2 -> V_102 ,
V_2 -> V_103 ) ;
if ( ! V_2 -> V_6 )
return - V_105 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 , int V_14 )
{
if ( V_14 & V_106 ) {
V_2 -> type = V_54 ;
F_38 ( V_2 ) ;
}
}
static void F_44 ( struct V_1 * V_2 )
{
T_1 V_5 ;
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_5 |= V_59 ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_21 )
{
if ( ! V_2 -> V_6 )
return;
while ( F_4 ( V_2 -> V_6 + V_7 ) & V_22 )
F_30 () ;
F_6 ( V_21 , V_2 -> V_6 + V_24 ) ;
}
static void F_46 ( struct V_1 * V_2 , const char * V_107 ,
T_3 V_108 )
{
unsigned long V_14 ;
int V_109 ;
T_1 V_5 , V_110 ;
F_47 ( V_14 ) ;
if ( V_2 -> V_111 ) {
V_109 = 0 ;
} else if ( V_112 ) {
V_109 = F_48 ( & V_2 -> V_16 ) ;
} else {
F_21 ( & V_2 -> V_16 ) ;
V_109 = 1 ;
}
V_5 = F_4 ( V_2 -> V_6 + V_11 ) ;
V_110 = V_5 & ~ ( V_12 | V_17 ) ;
F_6 ( V_110 , V_2 -> V_6 + V_11 ) ;
F_49 ( V_2 , V_107 , V_108 , F_45 ) ;
F_6 ( V_5 , V_2 -> V_6 + V_11 ) ;
if ( V_109 )
F_19 ( & V_2 -> V_16 ) ;
F_50 ( V_14 ) ;
}
static void F_51 ( struct V_113 * V_114 , const char * V_107 ,
T_3 V_108 )
{
struct V_1 * V_2 ;
V_2 = V_115 [ V_114 -> V_116 ] ;
if ( ! V_2 )
return;
F_46 ( V_2 , V_107 , V_108 ) ;
}
static int F_52 ( struct V_113 * V_114 , char * V_117 )
{
struct V_1 * V_2 ;
int V_63 = 115200 ;
int V_118 = 8 ;
int V_119 = 'n' ;
int V_120 = 'n' ;
if ( V_114 -> V_116 < 0 || V_114 -> V_116 >= V_121 )
return - V_99 ;
V_2 = V_115 [ V_114 -> V_116 ] ;
if ( ! V_2 || ! V_2 -> V_6 )
return - V_122 ;
F_44 ( V_2 ) ;
if ( V_117 )
F_53 ( V_117 , & V_63 , & V_119 , & V_118 , & V_120 ) ;
return F_54 ( V_2 , V_114 , V_63 , V_119 , V_118 , V_120 ) ;
}
static int T_4 F_55 ( void )
{
F_56 ( & V_123 ) ;
return 0 ;
}
static void F_57 ( struct V_113 * V_114 ,
const char * V_107 ,
T_3 V_108 )
{
struct V_124 * V_101 = V_114 -> V_125 ;
F_46 ( & V_101 -> V_2 , V_107 , V_108 ) ;
}
static int T_4
F_58 ( struct V_124 * V_126 , const char * V_127 )
{
if ( ! V_126 -> V_2 . V_6 )
return - V_122 ;
F_44 ( & V_126 -> V_2 ) ;
V_126 -> V_128 -> V_129 = F_57 ;
return 0 ;
}
static inline struct V_130 * F_59 ( struct V_126 * V_101 ,
const char * V_131 )
{
struct V_130 * V_130 = NULL ;
int V_58 ;
V_130 = F_60 ( V_101 , V_131 ) ;
if ( F_61 ( V_130 ) )
return V_130 ;
V_58 = F_62 ( V_130 ) ;
if ( V_58 ) {
F_41 ( V_101 , L_3 ) ;
return F_63 ( V_58 ) ;
}
F_64 ( V_101 ,
( void ( * ) ( void * ) ) V_132 ,
V_130 ) ;
return V_130 ;
}
static int F_65 ( struct V_133 * V_134 ,
struct V_1 * V_2 )
{
struct V_130 * V_130 = NULL ;
V_130 = F_59 ( & V_134 -> V_101 , NULL ) ;
if ( F_61 ( V_130 ) )
return F_66 ( V_130 ) ;
V_2 -> V_64 = F_67 ( V_130 ) ;
return 0 ;
}
static int F_68 ( struct V_133 * V_134 ,
struct V_1 * V_2 )
{
struct V_130 * V_135 = NULL ;
struct V_130 * V_136 = NULL ;
struct V_130 * V_137 = NULL ;
V_136 = F_59 ( & V_134 -> V_101 , L_4 ) ;
if ( F_61 ( V_136 ) )
return F_66 ( V_136 ) ;
V_135 = F_59 ( & V_134 -> V_101 , L_5 ) ;
if ( F_61 ( V_135 ) )
return F_66 ( V_135 ) ;
V_137 = F_59 ( & V_134 -> V_101 , L_6 ) ;
if ( F_61 ( V_137 ) )
return F_66 ( V_137 ) ;
V_2 -> V_64 = F_67 ( V_137 ) ;
return 0 ;
}
static int F_69 ( struct V_133 * V_134 )
{
struct V_138 * V_139 , * V_140 ;
struct V_1 * V_2 ;
int V_58 = 0 ;
if ( V_134 -> V_101 . V_141 )
V_134 -> V_131 = F_70 ( V_134 -> V_101 . V_141 , L_7 ) ;
if ( V_134 -> V_131 < 0 || V_134 -> V_131 >= V_121 )
return - V_99 ;
V_139 = F_71 ( V_134 , V_142 , 0 ) ;
if ( ! V_139 )
return - V_122 ;
V_140 = F_71 ( V_134 , V_143 , 0 ) ;
if ( ! V_140 )
return - V_122 ;
if ( V_115 [ V_134 -> V_131 ] ) {
F_41 ( & V_134 -> V_101 , L_8 , V_134 -> V_131 ) ;
return - V_104 ;
}
V_2 = F_72 ( & V_134 -> V_101 , sizeof( struct V_1 ) , V_144 ) ;
if ( ! V_2 )
return - V_105 ;
if ( F_73 ( V_134 -> V_101 . V_141 , L_9 ) )
V_58 = F_65 ( V_134 , V_2 ) ;
else
V_58 = F_68 ( V_134 , V_2 ) ;
if ( V_58 )
return V_58 ;
V_2 -> V_145 = V_146 ;
V_2 -> V_102 = V_139 -> V_147 ;
V_2 -> V_103 = F_74 ( V_139 ) ;
V_2 -> V_15 = V_140 -> V_147 ;
V_2 -> V_14 = V_148 | V_149 ;
V_2 -> V_101 = & V_134 -> V_101 ;
V_2 -> line = V_134 -> V_131 ;
V_2 -> type = V_54 ;
V_2 -> V_23 = 0 ;
V_2 -> V_150 = & V_151 ;
V_2 -> V_60 = 64 ;
V_115 [ V_134 -> V_131 ] = V_2 ;
F_75 ( V_134 , V_2 ) ;
if ( F_38 ( V_2 ) >= 0 ) {
F_24 ( V_2 ) ;
F_35 ( V_2 ) ;
}
V_58 = F_76 ( & V_152 , V_2 ) ;
if ( V_58 )
V_115 [ V_134 -> V_131 ] = NULL ;
return V_58 ;
}
static int F_77 ( struct V_133 * V_134 )
{
struct V_1 * V_2 ;
V_2 = F_78 ( V_134 ) ;
F_79 ( & V_152 , V_2 ) ;
V_115 [ V_134 -> V_131 ] = NULL ;
return 0 ;
}
static int T_4 F_80 ( void )
{
int V_58 ;
V_58 = F_81 ( & V_152 ) ;
if ( V_58 )
return V_58 ;
V_58 = F_82 ( & V_153 ) ;
if ( V_58 )
F_83 ( & V_152 ) ;
return V_58 ;
}
static void T_5 F_84 ( void )
{
F_85 ( & V_153 ) ;
F_83 ( & V_152 ) ;
}

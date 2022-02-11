static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_6 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , V_8 ) ;
if ( V_6 & V_9 )
V_7 |= V_10 ;
else
V_7 &= ~ V_10 ;
F_1 ( V_2 , V_7 , V_8 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 )
{
unsigned int V_6 = V_11 | V_12 ;
T_1 V_13 , V_7 ;
V_7 = F_3 ( V_2 , V_8 ) ;
V_13 = F_3 ( V_2 , V_14 ) ;
if ( V_13 & V_15 )
V_6 |= V_16 ;
if ( ( V_13 & V_17 ) || ! ( V_7 & V_18 ) )
V_6 |= V_19 ;
return V_6 ;
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
T_1 V_3 ;
unsigned int V_21 ;
F_8 ( & V_2 -> V_22 , V_20 ) ;
V_3 = F_3 ( V_2 , V_14 ) ;
V_21 = ( V_3 & V_23 ) ? V_24 : 0 ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_21 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_8 ) ;
V_3 &= ~ ( V_25 | V_26 ) ;
F_1 ( V_2 , V_3 , V_8 ) ;
V_3 = F_3 ( V_2 , V_14 ) ;
V_3 |= V_27 ;
F_1 ( V_2 , V_3 , V_14 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_3 ( V_2 , V_8 ) ;
V_3 &= ~ ( V_28 | V_29 ) ;
F_1 ( V_2 , V_3 , V_8 ) ;
V_3 = F_3 ( V_2 , V_14 ) ;
V_3 |= V_30 ;
F_1 ( V_2 , V_3 , V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( F_13 ( V_2 ) ) {
F_11 ( V_2 ) ;
return;
}
V_3 = F_3 ( V_2 , V_14 ) ;
V_3 |= V_30 ;
F_1 ( V_2 , V_3 , V_14 ) ;
V_3 = F_3 ( V_2 , V_8 ) ;
V_3 |= V_28 ;
F_1 ( V_2 , V_3 , V_8 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_33 -> V_32 ;
unsigned int V_34 ;
if ( F_13 ( V_2 ) )
return;
if ( V_2 -> V_35 ) {
while ( ! ( F_3 ( V_2 , V_14 ) & V_36 ) )
F_15 () ;
F_1 ( V_2 , V_2 -> V_35 , V_37 ) ;
V_2 -> V_38 . V_39 ++ ;
V_2 -> V_35 = 0 ;
}
while ( ! ( F_3 ( V_2 , V_14 ) & V_36 ) ) {
if ( F_16 ( V_32 ) )
break;
V_34 = V_32 -> V_40 [ V_32 -> V_41 ] ;
F_1 ( V_2 , V_34 , V_37 ) ;
V_32 -> V_41 = ( V_32 -> V_41 + 1 ) & ( V_42 - 1 ) ;
V_2 -> V_38 . V_39 ++ ;
}
if ( F_17 ( V_32 ) < V_43 )
F_18 ( V_2 ) ;
if ( F_16 ( V_32 ) )
F_11 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_1 V_13 , V_3 ;
V_3 = F_3 ( V_2 , V_8 ) ;
V_3 &= ~ V_44 ;
F_1 ( V_2 , V_3 , V_8 ) ;
V_13 = F_3 ( V_2 , V_14 ) ;
while ( ! ( V_13 & V_45 ) ) {
char V_46 = V_47 ;
if ( V_13 & V_48 )
V_2 -> V_38 . V_49 ++ ;
if ( V_13 & V_50 ) {
V_2 -> V_38 . V_51 ++ ;
V_2 -> V_38 . V_52 ++ ;
V_13 &= V_2 -> V_53 ;
if ( V_13 & V_50 )
V_46 = V_54 ;
} else
V_2 -> V_38 . V_55 ++ ;
V_3 = F_3 ( V_2 , V_56 ) ;
V_3 &= 0xff ;
if ( ( V_13 & V_2 -> V_57 ) == 0 )
F_20 ( & V_2 -> V_33 -> V_2 , V_3 , V_46 ) ;
V_13 = F_3 ( V_2 , V_14 ) ;
}
F_21 ( & V_2 -> V_22 ) ;
F_22 ( & V_2 -> V_33 -> V_2 ) ;
F_23 ( & V_2 -> V_22 ) ;
}
static T_2 F_24 ( int V_58 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
unsigned long V_20 ;
T_1 V_13 ;
F_8 ( & V_2 -> V_22 , V_20 ) ;
V_13 = F_3 ( V_2 , V_14 ) ;
if ( V_13 & V_27 )
F_19 ( V_2 ) ;
if ( V_13 & V_30 )
F_14 ( V_2 ) ;
V_13 = F_3 ( V_2 , V_14 ) ;
V_13 |= V_27 | V_30 ;
F_1 ( V_2 , V_13 , V_14 ) ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
return V_60 ;
}
static void F_25 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned long V_20 ;
F_8 ( & V_2 -> V_22 , V_20 ) ;
V_3 = F_3 ( V_2 , V_8 ) ;
V_3 &= ~ ( V_28 | V_25
| V_29 | V_26 | V_61 ) ;
F_1 ( V_2 , V_3 , V_8 ) ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
F_26 ( V_2 -> V_58 , V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned long V_20 ;
int V_21 ;
V_21 = F_28 ( V_2 -> V_58 , F_24 , V_62 ,
L_1 , V_2 ) ;
if ( V_21 )
return V_21 ;
F_8 ( & V_2 -> V_22 , V_20 ) ;
V_3 = F_3 ( V_2 , V_14 ) ;
V_3 |= V_27 | V_30
| V_48 | V_63 | V_50 ;
F_1 ( V_2 , V_3 , V_14 ) ;
V_3 = F_3 ( V_2 , V_8 ) ;
V_3 |= V_25 | V_28 ;
V_3 |= V_61 ;
F_1 ( V_2 , V_3 , V_8 ) ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
return 0 ;
}
static void F_29 ( struct V_64 * V_65 ,
unsigned long V_66 )
{
F_30 ( V_65 -> V_67 , V_66 * 8 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_68 * V_69 ,
struct V_68 * V_70 )
{
struct V_64 * V_65 = F_32 ( V_2 ) ;
unsigned int V_66 ;
T_1 V_7 ;
unsigned long V_20 ;
F_8 ( & V_2 -> V_22 , V_20 ) ;
V_7 = F_3 ( V_2 , V_8 ) ;
V_7 &= ~ V_71 ;
switch ( V_69 -> V_72 & V_73 ) {
case V_74 :
V_7 |= V_75 ;
break;
case V_76 :
V_7 |= V_77 ;
break;
case V_78 :
V_7 |= V_79 ;
break;
case V_80 :
default:
V_7 |= V_81 ;
break;
}
if ( V_69 -> V_72 & V_82 )
V_7 |= V_83 ;
else
V_7 &= ~ V_83 ;
V_7 &= ~ V_84 ;
if ( V_69 -> V_72 & V_85 ) {
if ( V_69 -> V_72 & V_86 ) {
if ( V_69 -> V_72 & V_87 )
V_7 |= V_88 ;
else
V_7 |= V_89 ;
} else if ( V_69 -> V_72 & V_87 )
V_7 |= V_90 ;
else
V_7 |= V_91 ;
} else
V_7 |= V_92 ;
if ( V_69 -> V_72 & V_93 )
V_7 |= V_18 ;
else
V_7 &= ~ V_18 ;
F_1 ( V_2 , V_7 , V_8 ) ;
V_66 = F_33 ( V_2 , V_69 , V_70 , 9600 , 3200000 ) ;
F_29 ( V_65 , V_66 ) ;
if ( F_34 ( V_69 ) )
F_35 ( V_69 , V_66 , V_66 ) ;
V_2 -> V_53 |= V_48 ;
if ( V_69 -> V_94 & V_95 )
V_2 -> V_53 |= V_50 ;
F_36 ( V_2 , V_69 -> V_72 , V_66 ) ;
F_9 ( & V_2 -> V_22 , V_20 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_38 ( V_2 -> V_98 ) ;
struct V_99 * V_100 ;
V_100 = F_39 ( V_97 , V_101 , 0 ) ;
if ( ! V_100 )
return;
if ( V_2 -> V_20 & V_102 ) {
F_40 ( V_2 -> V_98 , V_2 -> V_103 ,
F_41 ( V_100 ) ) ;
F_42 ( V_2 -> V_98 , V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_96 * V_97 = F_38 ( V_2 -> V_98 ) ;
struct V_99 * V_100 ;
V_100 = F_39 ( V_97 , V_101 , 0 ) ;
if ( ! V_100 )
return - V_104 ;
if ( ! F_44 ( V_2 -> V_98 , V_2 -> V_103 ,
F_41 ( V_100 ) , F_45 ( V_2 -> V_98 ) ) )
return - V_105 ;
if ( V_2 -> V_20 & V_102 ) {
V_2 -> V_5 = F_46 ( V_2 -> V_98 , V_2 -> V_103 ,
F_41 ( V_100 ) ) ;
if ( ! V_2 -> V_5 )
return - V_105 ;
}
return 0 ;
}
static const char * F_47 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_106 ) ? L_1 : NULL ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_107 * V_108 )
{
if ( V_2 -> type != V_106 )
return - V_109 ;
if ( V_2 -> V_58 != V_108 -> V_58 )
return - V_109 ;
return 0 ;
}
static void F_49 ( struct V_1 * V_2 , int V_20 )
{
if ( V_20 & V_110 ) {
V_2 -> type = V_106 ;
F_43 ( V_2 ) ;
}
}
static void F_50 ( struct V_1 * V_2 , int V_34 )
{
if ( ! V_2 -> V_5 )
return;
while ( F_3 ( V_2 , V_14 ) & V_36 )
F_15 () ;
F_1 ( V_2 , V_34 , V_37 ) ;
}
static void F_51 ( struct V_1 * V_2 , const char * V_111 ,
T_3 V_112 )
{
T_1 V_113 , V_3 ;
unsigned long V_20 ;
int V_114 ;
F_52 ( V_20 ) ;
if ( V_2 -> V_115 )
V_114 = 0 ;
else if ( V_116 )
V_114 = F_53 ( & V_2 -> V_22 ) ;
else {
F_23 ( & V_2 -> V_22 ) ;
V_114 = 1 ;
}
V_113 = F_3 ( V_2 , V_8 ) ;
V_3 = V_113 | V_44 ;
V_3 &= ~ ( V_25 | V_28 ) ;
F_1 ( V_2 , V_3 , V_8 ) ;
F_54 ( V_2 , V_111 , V_112 , F_50 ) ;
while ( F_3 ( V_2 , V_14 ) & V_117 )
F_15 () ;
V_3 = F_3 ( V_2 , V_14 ) ;
V_3 |= V_30 | V_27 ;
F_1 ( V_2 , V_3 , V_14 ) ;
F_1 ( V_2 , V_113 , V_8 ) ;
if ( V_114 )
F_21 ( & V_2 -> V_22 ) ;
F_55 ( V_20 ) ;
}
static void F_56 ( struct V_118 * V_119 , const char * V_111 ,
T_3 V_112 )
{
struct V_64 * V_65 ;
V_65 = V_120 [ V_119 -> V_121 ] ;
if ( ! V_65 )
return;
F_51 ( & V_65 -> V_2 , V_111 , V_112 ) ;
}
static int F_57 ( struct V_118 * V_119 , char * V_122 )
{
struct V_64 * V_65 ;
int V_66 = 115200 ;
int V_123 = 8 ;
int V_124 = 'n' ;
int V_125 = 'n' ;
if ( V_119 -> V_121 < 0 || V_119 -> V_121 >= V_126 )
return - V_109 ;
V_65 = V_120 [ V_119 -> V_121 ] ;
if ( ! V_65 || ! V_65 -> V_2 . V_5 )
return - V_127 ;
if ( V_122 )
F_58 ( V_122 , & V_66 , & V_124 , & V_123 , & V_125 ) ;
return F_59 ( & V_65 -> V_2 , V_119 , V_66 , V_124 , V_123 , V_125 ) ;
}
static int T_4 F_60 ( void )
{
F_61 ( & V_128 ) ;
return 0 ;
}
static void F_62 ( struct V_118 * V_119 ,
const char * V_111 ,
T_3 V_112 )
{
struct V_129 * V_98 = V_119 -> V_130 ;
F_51 ( & V_98 -> V_2 , V_111 , V_112 ) ;
}
static int T_4
F_63 ( struct V_129 * V_131 , const char * V_132 )
{
if ( ! V_131 -> V_2 . V_5 )
return - V_127 ;
V_131 -> V_133 -> V_134 = F_62 ;
return 0 ;
}
static int F_64 ( struct V_96 * V_97 )
{
const struct V_135 * V_136 ;
const struct V_137 * V_138 = NULL ;
struct V_99 * V_139 ;
struct V_64 * V_65 ;
int V_21 , V_58 ;
if ( V_97 -> V_98 . V_140 ) {
V_97 -> V_141 = F_65 ( V_97 -> V_98 . V_140 , L_2 ) ;
V_136 = F_66 ( V_142 , V_97 -> V_98 . V_140 ) ;
if ( V_136 )
V_138 = V_136 -> V_130 ;
}
if ( V_97 -> V_141 < 0 || V_97 -> V_141 >= V_126 ) {
F_67 ( & V_97 -> V_98 , L_3 , V_97 -> V_141 ) ;
return - V_109 ;
}
V_139 = F_39 ( V_97 , V_101 , 0 ) ;
if ( ! V_139 ) {
F_67 ( & V_97 -> V_98 , L_4 ) ;
return - V_127 ;
}
V_58 = F_68 ( V_97 , 0 ) ;
if ( V_58 < 0 ) {
F_67 ( & V_97 -> V_98 , L_5 ) ;
return V_58 ;
}
if ( V_120 [ V_97 -> V_141 ] ) {
F_67 ( & V_97 -> V_98 , L_6 , V_97 -> V_141 ) ;
return - V_105 ;
}
V_65 = F_69 ( & V_97 -> V_98 , sizeof( * V_65 ) , V_143 ) ;
if ( ! V_65 )
return - V_144 ;
V_65 -> V_67 = F_70 ( & V_97 -> V_98 , NULL ) ;
if ( F_71 ( V_65 -> V_67 ) ) {
F_67 ( & V_97 -> V_98 , L_7 ) ;
return F_72 ( V_65 -> V_67 ) ;
}
V_65 -> V_2 . V_98 = & V_97 -> V_98 ;
V_65 -> V_2 . line = V_97 -> V_141 ;
V_65 -> V_2 . type = V_106 ;
V_65 -> V_2 . V_145 = V_146 ;
V_65 -> V_2 . V_103 = V_139 -> V_147 ;
V_65 -> V_2 . V_58 = V_58 ;
V_65 -> V_2 . V_148 = F_73 ( V_65 -> V_67 ) ;
if ( V_65 -> V_2 . V_148 == 0 ) {
F_67 ( & V_97 -> V_98 , L_8 ) ;
return - V_109 ;
}
V_65 -> V_2 . V_20 = V_149 | V_102 | V_150 ;
V_65 -> V_2 . V_35 = 0 ;
V_65 -> V_2 . V_151 = ( V_138 ) ? V_138 -> V_152 : 16 ;
V_65 -> V_2 . V_153 = & V_154 ;
V_120 [ V_97 -> V_141 ] = V_65 ;
F_74 ( V_97 , V_65 ) ;
V_21 = F_75 ( & V_155 , & V_65 -> V_2 ) ;
if ( V_21 )
V_120 [ V_97 -> V_141 ] = NULL ;
return V_21 ;
}
static int F_76 ( struct V_96 * V_97 )
{
struct V_64 * V_65 = F_77 ( V_97 ) ;
F_78 ( & V_155 , & V_65 -> V_2 ) ;
V_120 [ V_97 -> V_141 ] = NULL ;
return 0 ;
}
static int T_4 F_79 ( void )
{
int V_21 ;
V_21 = F_80 ( & V_155 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_81 ( & V_156 ) ;
if ( V_21 )
F_82 ( & V_155 ) ;
return V_21 ;
}
static void T_4 F_83 ( void )
{
F_84 ( & V_156 ) ;
F_82 ( & V_155 ) ;
}

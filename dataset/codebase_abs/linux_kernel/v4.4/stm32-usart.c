static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = F_4 ( V_3 -> V_7 + V_4 ) ;
V_6 |= V_5 ;
F_5 ( V_6 , V_3 -> V_7 + V_4 ) ;
}
static void F_6 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = F_4 ( V_3 -> V_7 + V_4 ) ;
V_6 &= ~ V_5 ;
F_5 ( V_6 , V_3 -> V_7 + V_4 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = & V_3 -> V_10 -> V_3 ;
unsigned long V_11 ;
T_1 V_12 ;
char V_13 ;
if ( V_3 -> V_14 )
F_8 ( V_9 -> V_15 -> V_16 , 0 ) ;
while ( ( V_12 = F_4 ( V_3 -> V_7 + V_17 ) ) & V_18 ) {
V_12 |= V_19 ;
V_11 = F_4 ( V_3 -> V_7 + V_20 ) ;
V_13 = V_21 ;
V_3 -> V_22 . V_23 ++ ;
if ( V_12 & V_24 ) {
if ( V_12 & V_25 ) {
V_3 -> V_22 . V_26 ++ ;
if ( F_9 ( V_3 ) )
continue;
} else if ( V_12 & V_27 ) {
V_3 -> V_22 . V_28 ++ ;
} else if ( V_12 & V_29 ) {
V_3 -> V_22 . V_30 ++ ;
} else if ( V_12 & V_31 ) {
V_3 -> V_22 . V_32 ++ ;
}
V_12 &= V_3 -> V_33 ;
if ( V_12 & V_25 )
V_13 = V_34 ;
else if ( V_12 & V_29 )
V_13 = V_35 ;
else if ( V_12 & V_31 )
V_13 = V_36 ;
}
if ( F_10 ( V_3 , V_11 ) )
continue;
F_11 ( V_3 , V_12 , V_27 , V_11 , V_13 ) ;
}
F_12 ( & V_3 -> V_37 ) ;
F_13 ( V_9 ) ;
F_14 ( & V_3 -> V_37 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_10 -> V_39 ;
if ( V_3 -> V_40 ) {
F_5 ( V_3 -> V_40 , V_3 -> V_7 + V_20 ) ;
V_3 -> V_40 = 0 ;
V_3 -> V_22 . V_41 ++ ;
return;
}
if ( F_16 ( V_3 ) ) {
F_17 ( V_3 ) ;
return;
}
if ( F_18 ( V_39 ) ) {
F_17 ( V_3 ) ;
return;
}
F_5 ( V_39 -> V_42 [ V_39 -> V_43 ] , V_3 -> V_7 + V_20 ) ;
V_39 -> V_43 = ( V_39 -> V_43 + 1 ) & ( V_44 - 1 ) ;
V_3 -> V_22 . V_41 ++ ;
if ( F_19 ( V_39 ) < V_45 )
F_20 ( V_3 ) ;
if ( F_18 ( V_39 ) )
F_17 ( V_3 ) ;
}
static T_2 F_21 ( int V_46 , void * V_47 )
{
struct V_2 * V_3 = V_47 ;
T_1 V_12 ;
F_14 ( & V_3 -> V_37 ) ;
V_12 = F_4 ( V_3 -> V_7 + V_17 ) ;
if ( V_12 & V_18 )
F_7 ( V_3 ) ;
if ( V_12 & V_48 )
F_15 ( V_3 ) ;
F_12 ( & V_3 -> V_37 ) ;
return V_49 ;
}
static unsigned int F_22 ( struct V_2 * V_3 )
{
return F_4 ( V_3 -> V_7 + V_17 ) & V_48 ;
}
static void F_23 ( struct V_2 * V_3 , unsigned int V_50 )
{
if ( ( V_50 & V_51 ) && ( V_3 -> V_52 & V_53 ) )
F_3 ( V_3 , V_54 , V_55 ) ;
else
F_6 ( V_3 , V_54 , V_55 ) ;
}
static unsigned int F_24 ( struct V_2 * V_3 )
{
return V_56 | V_57 | V_58 ;
}
static void F_17 ( struct V_2 * V_3 )
{
F_6 ( V_3 , V_59 , V_60 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_38 * V_39 = & V_3 -> V_10 -> V_39 ;
if ( F_18 ( V_39 ) )
return;
F_3 ( V_3 , V_59 , V_60 | V_61 ) ;
}
static void F_26 ( struct V_2 * V_3 )
{
unsigned long V_62 ;
F_27 ( & V_3 -> V_37 , V_62 ) ;
F_6 ( V_3 , V_59 , V_63 ) ;
F_28 ( & V_3 -> V_37 , V_62 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
unsigned long V_62 ;
F_27 ( & V_3 -> V_37 , V_62 ) ;
F_3 ( V_3 , V_59 , V_63 ) ;
F_28 ( & V_3 -> V_37 , V_62 ) ;
}
static void F_30 ( struct V_2 * V_3 )
{
F_6 ( V_3 , V_59 , V_63 ) ;
}
static void F_31 ( struct V_2 * V_3 , int V_64 )
{
}
static int F_32 ( struct V_2 * V_3 )
{
const char * V_65 = F_33 ( V_3 -> V_16 ) -> V_65 ;
T_1 V_6 ;
int V_66 ;
V_66 = F_34 ( V_3 -> V_46 , F_21 , 0 , V_65 , V_3 ) ;
if ( V_66 )
return V_66 ;
V_6 = V_63 | V_61 | V_67 ;
F_3 ( V_3 , V_59 , V_6 ) ;
return 0 ;
}
static void F_35 ( struct V_2 * V_3 )
{
T_1 V_6 ;
V_6 = V_60 | V_63 | V_61 | V_67 ;
F_3 ( V_3 , V_59 , V_6 ) ;
F_36 ( V_3 -> V_46 , V_3 ) ;
}
static void F_37 ( struct V_2 * V_3 , struct V_68 * V_69 ,
struct V_68 * V_70 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
unsigned int V_71 ;
T_1 V_72 , V_73 , V_74 , V_75 ;
T_3 V_76 = V_69 -> V_77 ;
T_1 V_78 , V_79 , V_80 ;
unsigned long V_62 ;
if ( ! V_1 -> V_81 )
V_76 &= ~ V_82 ;
V_71 = F_38 ( V_3 , V_69 , V_70 , 0 , V_3 -> V_83 / 8 ) ;
F_27 ( & V_3 -> V_37 , V_62 ) ;
F_5 ( 0 , V_3 -> V_7 + V_59 ) ;
V_78 = V_61 | V_67 | V_84 | V_63 ;
V_79 = 0 ;
V_80 = 0 ;
if ( V_76 & V_85 )
V_79 |= V_86 ;
if ( V_76 & V_87 ) {
V_78 |= V_88 ;
if ( ( V_76 & V_89 ) == V_90 )
V_78 |= V_91 ;
}
if ( V_76 & V_92 )
V_78 |= V_93 ;
V_3 -> V_52 &= ~ ( V_94 | V_53 ) ;
if ( V_76 & V_82 ) {
V_3 -> V_52 |= V_94 | V_53 ;
V_80 |= V_95 ;
}
V_72 = F_39 ( V_3 -> V_83 , V_71 ) ;
if ( V_72 < 16 ) {
V_75 = 8 ;
F_3 ( V_3 , V_59 , V_96 ) ;
} else {
V_75 = 16 ;
F_6 ( V_3 , V_59 , V_96 ) ;
}
V_73 = ( V_72 / V_75 ) << V_97 ;
V_74 = V_72 % V_75 ;
F_5 ( V_73 | V_74 , V_3 -> V_7 + V_98 ) ;
F_40 ( V_3 , V_76 , V_71 ) ;
V_3 -> V_33 = V_27 ;
if ( V_69 -> V_99 & V_100 )
V_3 -> V_33 |= V_29 | V_31 ;
if ( V_69 -> V_99 & ( V_101 | V_102 | V_103 ) )
V_3 -> V_33 |= V_25 ;
V_3 -> V_104 = 0 ;
if ( V_69 -> V_99 & V_105 )
V_3 -> V_104 = V_29 | V_31 ;
if ( V_69 -> V_99 & V_101 ) {
V_3 -> V_104 |= V_25 ;
if ( V_69 -> V_99 & V_105 )
V_3 -> V_104 |= V_27 ;
}
if ( ( V_69 -> V_77 & V_106 ) == 0 )
V_3 -> V_104 |= V_19 ;
F_5 ( V_80 , V_3 -> V_7 + V_54 ) ;
F_5 ( V_79 , V_3 -> V_7 + V_107 ) ;
F_5 ( V_78 , V_3 -> V_7 + V_59 ) ;
F_28 ( & V_3 -> V_37 , V_62 ) ;
}
static const char * F_41 ( struct V_2 * V_3 )
{
return ( V_3 -> type == V_108 ) ? V_109 : NULL ;
}
static void F_42 ( struct V_2 * V_3 )
{
}
static int F_43 ( struct V_2 * V_3 )
{
return 0 ;
}
static void F_44 ( struct V_2 * V_3 , int V_62 )
{
if ( V_62 & V_110 )
V_3 -> type = V_108 ;
}
static int
F_45 ( struct V_2 * V_3 , struct V_111 * V_112 )
{
return - V_113 ;
}
static void F_46 ( struct V_2 * V_3 , unsigned int V_10 ,
unsigned int V_114 )
{
struct V_1 * V_115 = F_2 ( V_3 ,
struct V_1 , V_3 ) ;
unsigned long V_62 = 0 ;
switch ( V_10 ) {
case V_116 :
F_47 ( V_115 -> V_117 ) ;
break;
case V_118 :
F_27 ( & V_3 -> V_37 , V_62 ) ;
F_6 ( V_3 , V_59 , V_84 ) ;
F_28 ( & V_3 -> V_37 , V_62 ) ;
F_48 ( V_115 -> V_117 ) ;
break;
}
}
static int F_49 ( struct V_1 * V_115 ,
struct V_119 * V_120 )
{
struct V_2 * V_3 = & V_115 -> V_3 ;
struct V_121 * V_122 ;
int V_66 ;
V_3 -> V_123 = V_124 ;
V_3 -> V_62 = V_125 ;
V_3 -> V_126 = & V_127 ;
V_3 -> V_16 = & V_120 -> V_16 ;
V_3 -> V_46 = F_50 ( V_120 , 0 ) ;
V_122 = F_51 ( V_120 , V_128 , 0 ) ;
V_3 -> V_7 = F_52 ( & V_120 -> V_16 , V_122 ) ;
if ( F_53 ( V_3 -> V_7 ) )
return F_54 ( V_3 -> V_7 ) ;
V_3 -> V_129 = V_122 -> V_130 ;
F_55 ( & V_3 -> V_37 ) ;
V_115 -> V_117 = F_56 ( & V_120 -> V_16 , NULL ) ;
if ( F_53 ( V_115 -> V_117 ) )
return F_54 ( V_115 -> V_117 ) ;
V_66 = F_47 ( V_115 -> V_117 ) ;
if ( V_66 )
return V_66 ;
V_115 -> V_3 . V_83 = F_57 ( V_115 -> V_117 ) ;
if ( ! V_115 -> V_3 . V_83 )
V_66 = - V_113 ;
F_48 ( V_115 -> V_117 ) ;
return V_66 ;
}
static struct V_1 * F_58 ( struct V_119 * V_120 )
{
struct V_131 * V_132 = V_120 -> V_16 . V_133 ;
int V_134 ;
if ( ! V_132 )
return NULL ;
V_134 = F_59 ( V_132 , L_1 ) ;
if ( V_134 < 0 )
V_134 = 0 ;
if ( F_60 ( V_134 >= V_135 ) )
return NULL ;
V_136 [ V_134 ] . V_81 = F_61 ( V_132 ,
L_2 ) ;
V_136 [ V_134 ] . V_3 . line = V_134 ;
return & V_136 [ V_134 ] ;
}
static int F_62 ( struct V_119 * V_120 )
{
int V_66 ;
struct V_1 * V_115 ;
V_115 = F_58 ( V_120 ) ;
if ( ! V_115 )
return - V_137 ;
V_66 = F_49 ( V_115 , V_120 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_63 ( & V_138 , & V_115 -> V_3 ) ;
if ( V_66 )
return V_66 ;
F_64 ( V_120 , & V_115 -> V_3 ) ;
return 0 ;
}
static int F_65 ( struct V_119 * V_120 )
{
struct V_2 * V_3 = F_66 ( V_120 ) ;
return F_67 ( & V_138 , V_3 ) ;
}
static void F_68 ( struct V_2 * V_3 , int V_139 )
{
while ( ! ( F_4 ( V_3 -> V_7 + V_17 ) & V_48 ) )
F_69 () ;
F_5 ( V_139 , V_3 -> V_7 + V_20 ) ;
}
static void F_70 ( struct V_140 * V_141 , const char * V_142 , unsigned V_143 )
{
struct V_2 * V_3 = & V_136 [ V_141 -> V_144 ] . V_3 ;
unsigned long V_62 ;
T_1 V_145 , V_146 ;
int V_147 = 1 ;
F_71 ( V_62 ) ;
if ( V_3 -> V_148 )
V_147 = 0 ;
else if ( V_149 )
V_147 = F_72 ( & V_3 -> V_37 ) ;
else
F_14 ( & V_3 -> V_37 ) ;
V_145 = F_4 ( V_3 -> V_7 + V_59 ) ;
V_146 = V_145 & ~ V_150 ;
F_5 ( V_146 , V_3 -> V_7 + V_59 ) ;
F_73 ( V_3 , V_142 , V_143 , F_68 ) ;
F_5 ( V_145 , V_3 -> V_7 + V_59 ) ;
if ( V_147 )
F_12 ( & V_3 -> V_37 ) ;
F_74 ( V_62 ) ;
}
static int F_75 ( struct V_140 * V_141 , char * V_151 )
{
struct V_1 * V_115 ;
int V_71 = 9600 ;
int V_5 = 8 ;
int V_30 = 'n' ;
int V_152 = 'n' ;
if ( V_141 -> V_144 >= V_135 )
return - V_137 ;
V_115 = & V_136 [ V_141 -> V_144 ] ;
if ( V_115 -> V_3 . V_129 == 0 || V_115 -> V_3 . V_7 == NULL )
return - V_153 ;
if ( V_151 )
F_76 ( V_151 , & V_71 , & V_30 , & V_5 , & V_152 ) ;
return F_77 ( & V_115 -> V_3 , V_141 , V_71 , V_30 , V_5 , V_152 ) ;
}
static int T_4 F_78 ( void )
{
static char V_154 [] V_155 = L_3 ;
int V_66 ;
F_79 ( L_4 , V_154 ) ;
V_66 = F_80 ( & V_138 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_81 ( & V_156 ) ;
if ( V_66 )
F_82 ( & V_138 ) ;
return V_66 ;
}
static void T_5 F_83 ( void )
{
F_84 ( & V_156 ) ;
F_82 ( & V_138 ) ;
}

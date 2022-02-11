static inline struct
V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void
F_3 ( struct V_2 * V_3 )
{
return;
}
static void
F_4 ( struct V_2 * V_3 )
{
unsigned long V_4 ;
F_5 ( & V_5 , V_4 ) ;
F_6 ( V_3 ) ;
F_7 ( & V_5 , V_4 ) ;
return;
}
static void
F_8 ( struct V_2 * V_3 )
{
F_9 ( V_6 , V_3 -> V_7 + V_8 ) ;
}
static void
F_10 ( struct V_2 * V_3 )
{
}
static int
F_11 ( struct V_2 * V_3 )
{
struct V_9 * V_10 = F_12 ( & V_3 -> V_11 -> V_3 ) ;
unsigned int V_12 = 0 , V_13 = 0 , V_14 ;
if ( ! V_10 ) {
F_13 ( V_3 -> V_15 , L_1 , V_16 ) ;
return - V_17 ;
}
V_14 =
F_14 ( V_3 -> V_7 + V_18 ) & V_19 ;
while ( V_14 -- ) {
T_1 V_20 = V_21 ;
V_12 = F_15 ( V_3 -> V_7 + V_22 ) ;
V_13 = ( F_14 ( V_3 -> V_7 + V_23 )
& V_24 ) | V_25 ;
F_16 ( V_10 ) ;
V_3 -> V_26 . V_27 ++ ;
if ( V_13 & V_24 ) {
if ( V_13 & V_28 ) {
V_3 -> V_26 . V_29 ++ ;
F_17 ( 0 , V_30 ,
V_3 -> V_7 + V_8 ) ;
} else if ( V_13 & V_31 ) {
V_3 -> V_26 . V_32 ++ ;
F_17 ( 0 , V_33 ,
V_3 -> V_7 + V_8 ) ;
}
if ( V_13 & V_34 ) {
V_3 -> V_26 . V_35 ++ ;
F_17 ( 0 , V_36 ,
V_3 -> V_7 + V_8 ) ;
}
V_13 &= V_3 -> V_37 ;
if ( V_13 & V_28 )
V_20 = V_38 ;
else if ( V_13 & V_31 )
V_20 = V_39 ;
}
if ( ( V_13 & V_3 -> V_40 ) == 0 )
F_18 ( V_10 , V_12 , V_20 ) ;
if ( V_13 & V_34 )
F_18 ( V_10 , 0 , V_41 ) ;
}
if ( V_12 != 0 )
F_16 ( V_10 ) ;
F_19 ( V_10 ) ;
return 0 ;
}
static void
F_6 ( struct V_2 * V_3 )
{
struct V_42 * V_43 = & V_3 -> V_11 -> V_43 ;
if ( F_20 ( V_3 ) ) {
F_3 ( V_3 ) ;
return;
}
while ( ( ( F_14 ( V_3 -> V_7 + V_18 ) &
V_44 ) >> V_45 ) != 0 ) {
if ( V_3 -> V_46 ) {
F_21 ( V_3 -> V_46 , V_3 -> V_7 + V_47 ) ;
V_3 -> V_26 . V_48 ++ ;
V_3 -> V_46 = 0 ;
continue;
}
if ( F_22 ( V_43 ) )
break;
F_21 ( V_3 -> V_11 -> V_43 . V_49 [ V_3 -> V_11 -> V_43 . V_50 ] ,
V_3 -> V_7 + V_47 ) ;
V_43 -> V_50 = ( V_43 -> V_50 + 1 ) & ( V_51 - 1 ) ;
V_3 -> V_26 . V_48 ++ ;
}
if ( F_23 ( V_43 ) < V_52 )
F_24 ( V_3 ) ;
}
static T_2
F_25 ( int V_53 , void * V_54 )
{
unsigned long V_4 ;
struct V_2 * V_3 = (struct V_2 * ) V_54 ;
F_5 ( & V_5 , V_4 ) ;
F_9 ( V_55 , V_3 -> V_7 + V_56 ) ;
F_7 ( & V_5 , V_4 ) ;
F_4 ( V_3 ) ;
return V_57 ;
}
static T_2
F_26 ( int V_53 , void * V_54 )
{
unsigned long V_4 ;
struct V_2 * V_3 = (struct V_2 * ) V_54 ;
F_5 ( & V_5 , V_4 ) ;
F_17 ( 0 , V_30 | V_33 |
V_36 , V_3 -> V_7 + V_8 ) ;
F_7 ( & V_5 , V_4 ) ;
return V_57 ;
}
static T_2
F_27 ( int V_53 , void * V_54 )
{
unsigned long V_4 ;
struct V_2 * V_3 = (struct V_2 * ) V_54 ;
F_5 ( & V_5 , V_4 ) ;
F_9 ( V_58 , V_3 -> V_7 + V_56 ) ;
F_11 ( V_3 ) ;
F_7 ( & V_5 , V_4 ) ;
return V_57 ;
}
static unsigned int
F_28 ( struct V_2 * V_3 )
{
int V_59 ;
V_59 = F_14 ( V_3 -> V_7 + V_18 ) & V_60 ;
return V_59 ? 0 : V_61 ;
}
static unsigned int
F_29 ( struct V_2 * V_3 )
{
return V_62 | V_63 | V_64 ;
}
static void
F_30 ( struct V_2 * V_3 , T_3 V_65 )
{
}
static void
F_31 ( struct V_2 * V_3 , int V_66 )
{
}
static int
F_32 ( struct V_2 * V_3 )
{
struct V_1 * V_67 = F_1 ( V_3 ) ;
int V_68 ;
V_3 -> V_69 = F_33 ( V_67 -> V_70 ) ;
F_17 ( V_71 | V_72 , ( 1 << V_73 ) ,
V_3 -> V_7 + V_74 ) ;
F_9 ( 0 , V_3 -> V_7 + V_75 ) ;
F_9 (
( ( V_76 << V_77 ) & V_78 ) |
V_79 | V_80 ,
V_3 -> V_7 + V_81 ) ;
F_9 (
( ( V_82 << V_83 ) & V_84 )
| V_85 | V_86 ,
V_3 -> V_7 + V_87 ) ;
F_34 () ;
F_17 ( 0 , V_88 | V_89 | V_90 |
V_91 , V_3 -> V_7 + V_92 ) ;
V_68 = F_35 ( V_67 -> V_93 , F_25 ,
V_94 , L_2 , V_3 ) ;
if ( V_68 ) {
F_36 ( L_3 ) ;
return V_68 ;
}
V_68 = F_35 ( V_67 -> V_95 , F_27 ,
V_94 , L_4 , V_3 ) ;
if ( V_68 ) {
F_36 ( L_5 ) ;
goto V_96;
}
V_68 = F_35 ( V_67 -> V_97 , F_26 ,
V_94 , L_6 , V_3 ) ;
if ( V_68 ) {
F_36 ( L_7 ) ;
goto V_98;
}
F_9 ( V_99 | V_100 | V_101 ,
V_3 -> V_7 + V_102 ) ;
return 0 ;
V_98:
F_37 ( V_67 -> V_95 , V_3 ) ;
V_96:
F_37 ( V_67 -> V_93 , V_3 ) ;
return V_68 ;
}
static void
F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_67 = F_1 ( V_3 ) ;
F_37 ( V_67 -> V_93 , V_3 ) ;
F_37 ( V_67 -> V_95 , V_3 ) ;
F_37 ( V_67 -> V_97 , V_3 ) ;
F_9 ( 0 , V_3 -> V_7 + V_92 ) ;
F_17 ( V_85 , V_86 ,
V_3 -> V_7 + V_87 ) ;
F_17 ( V_79 , V_80 ,
V_3 -> V_7 + V_81 ) ;
}
static void
F_39 ( struct V_2 * V_3 ,
struct V_103 * V_104 , struct V_103 * V_105 )
{
unsigned int V_106 ;
unsigned int V_107 ;
unsigned int V_108 ;
unsigned int V_109 ;
unsigned int V_110 = 0 ;
unsigned long V_4 ;
V_106 = V_104 -> V_111 ;
V_107 = V_104 -> V_112 ;
switch ( V_106 & V_113 ) {
case V_114 :
V_110 = V_115 ;
break;
case V_116 :
case V_117 :
default:
V_104 -> V_111 &= ~ V_113 ;
V_104 -> V_111 |= V_118 ;
V_110 = V_88 ;
break;
}
V_106 &= ~ V_119 ;
if ( V_106 & V_120 )
V_110 |= V_121 ;
if ( V_106 & V_122 ) {
if ( ! ( V_106 & V_123 ) )
V_110 &= ~ V_124 ;
else
V_110 |= V_124 ;
}
V_3 -> V_37 = V_34 ;
if ( V_107 & V_125 )
V_3 -> V_37 |= V_31 | V_28 ;
V_3 -> V_40 = 0 ;
if ( V_107 & V_126 )
V_3 -> V_40 |= V_31 | V_28 ;
if ( V_107 & V_127 ) {
if ( V_107 & V_126 )
V_3 -> V_40 |= V_34 ;
}
if ( ( V_106 & V_128 ) == 0 )
V_3 -> V_40 |= V_25 ;
V_110 |= V_89 | V_90 | V_91 ;
F_5 ( & V_5 , V_4 ) ;
F_17 ( 0 , V_110 , V_3 -> V_7 + V_92 ) ;
V_109 = F_40 ( V_3 , V_104 , V_105 , 0 , V_3 -> V_69 / 16 ) ;
V_108 = F_41 ( V_3 , V_109 ) ;
V_108 = V_108 / 2 - 1 ;
F_17 ( V_129 , 0 , V_3 -> V_7 + V_92 ) ;
F_17 ( V_130 , 0 , V_3 -> V_7 + V_92 ) ;
F_17 ( V_131 , 0 , V_3 -> V_7 + V_92 ) ;
F_9 ( V_108 , V_3 -> V_7 + V_132 ) ;
F_17 ( 0 , V_129 , V_3 -> V_7 + V_92 ) ;
F_9 ( V_133 , V_3 -> V_7 + V_8 ) ;
F_7 ( & V_5 , V_4 ) ;
if ( F_42 ( V_104 ) )
F_43 ( V_104 , V_109 , V_109 ) ;
}
static const char *
F_44 ( struct V_2 * V_3 )
{
if ( V_3 -> type == V_134 )
return V_135 ;
else
return NULL ;
}
static void
F_45 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 & V_136 ) {
F_46 ( V_3 -> V_7 ) ;
V_3 -> V_7 = NULL ;
}
}
static int
F_47 ( struct V_2 * V_3 )
{
struct V_137 * V_138 = F_48 ( V_3 -> V_15 ) ;
struct V_139 * V_140 ;
int V_141 ;
V_140 = F_49 ( V_138 , V_142 , 0 ) ;
if ( ! V_140 ) {
F_50 ( & V_138 -> V_15 , L_8 ) ;
return - V_143 ;
}
V_141 = F_51 ( V_140 ) ;
V_140 = F_52 ( & V_138 -> V_15 , V_140 -> V_144 ,
V_141 , F_53 ( & V_138 -> V_15 ) ) ;
if ( ! V_140 ) {
F_50 ( & V_138 -> V_15 , L_9 ) ;
return - V_17 ;
}
if ( V_3 -> V_4 & V_136 ) {
V_3 -> V_7 = F_54 ( & V_138 -> V_15 ,
V_3 -> V_145 , V_141 ) ;
if ( V_3 -> V_7 == NULL )
return - V_146 ;
}
return 0 ;
}
static void
F_55 ( struct V_2 * V_3 , int V_4 )
{
if ( V_4 & V_147 ) {
V_3 -> type = V_134 ;
F_47 ( V_3 ) ;
}
}
static int
F_56 ( struct V_2 * V_3 ,
struct V_148 * V_149 )
{
int V_150 = 0 ;
if ( V_149 -> type != V_151 && V_149 -> type != V_134 )
V_150 = - V_152 ;
if ( V_149 -> V_53 < 0 || V_149 -> V_53 >= V_153 )
V_150 = - V_152 ;
if ( V_149 -> V_154 < 9600 )
V_150 = - V_152 ;
return V_150 ;
}
static void
F_57 ( struct V_2 * V_3 , int V_12 )
{
int V_155 ;
if ( ! V_3 -> V_7 )
return;
do {
V_155 = ( F_14 ( V_3 -> V_7 + V_18 )
& V_44 ) >> V_45 ;
} while ( V_155 == 0 );
F_21 ( V_12 , V_3 -> V_7 + V_47 ) ;
}
static void
F_58 ( struct V_156 * V_157 , const char * V_158 , T_3 V_159 )
{
struct V_1 * V_67 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
if ( V_157 -> V_160 >= V_161 )
return;
V_67 = V_162 [ V_157 -> V_160 ] ;
if ( ! V_67 )
return;
V_3 = & V_67 -> V_3 ;
F_5 ( & V_5 , V_4 ) ;
F_59 ( V_3 , V_158 , V_159 , F_57 ) ;
F_7 ( & V_5 , V_4 ) ;
}
static int T_4
F_60 ( struct V_156 * V_157 , char * V_163 )
{
struct V_1 * V_67 ;
struct V_2 * V_3 ;
int V_109 = 115200 ;
int V_164 = 8 ;
int V_29 = 'n' ;
int V_165 = 'n' ;
if ( V_157 -> V_160 >= V_161 )
return - V_143 ;
V_67 = V_162 [ V_157 -> V_160 ] ;
if ( ! V_67 )
return - V_143 ;
V_3 = & V_67 -> V_3 ;
V_3 -> V_69 = F_33 ( V_67 -> V_70 ) ;
if ( V_163 )
F_61 ( V_163 , & V_109 , & V_29 , & V_164 , & V_165 ) ;
return F_62 ( V_3 , V_157 , V_109 , V_29 , V_164 , V_165 ) ;
}
static int T_4
F_63 ( void )
{
F_64 ( & V_166 ) ;
return 0 ;
}
static int T_4
F_65 ( struct V_137 * V_138 )
{
struct V_1 * V_67 ;
struct V_2 * V_3 ;
struct V_139 * V_167 , * V_168 ;
int V_93 , V_95 , V_97 ;
struct V_70 * V_70 ;
int V_150 ;
V_167 = F_49 ( V_138 , V_142 , 0 ) ;
V_168 = F_49 ( V_138 , V_169 , 0 ) ;
if ( ! V_167 || ! V_168 )
return - V_143 ;
if ( V_138 -> V_170 >= V_161 )
return - V_17 ;
if ( V_162 [ V_138 -> V_170 ] != NULL )
return - V_17 ;
V_70 = F_66 ( & V_138 -> V_15 , L_10 ) ;
if ( F_67 ( V_70 ) ) {
F_36 ( L_11 ) ;
return - V_171 ;
}
V_93 = F_68 ( V_138 , L_12 ) ;
V_95 = F_68 ( V_138 , L_13 ) ;
V_97 = F_68 ( V_138 , L_14 ) ;
if ( ( V_93 < 0 ) | ( V_95 < 0 ) | ( V_97 < 0 ) )
return - V_143 ;
V_67 = F_69 ( sizeof( struct V_1 ) , V_172 ) ;
if ( ! V_67 )
return - V_146 ;
V_3 = & V_67 -> V_3 ;
V_3 -> V_173 = V_174 ;
V_3 -> V_4 = V_175 | V_136 ;
V_3 -> V_176 = & V_177 ;
V_3 -> V_178 = 16 ;
V_3 -> type = V_134 ,
V_3 -> line = V_138 -> V_170 ;
V_3 -> V_15 = & V_138 -> V_15 ;
V_3 -> V_53 = V_93 ;
V_3 -> V_145 = V_167 -> V_144 ;
V_67 -> V_70 = V_70 ;
V_67 -> V_93 = V_93 ;
V_67 -> V_95 = V_95 ;
V_67 -> V_97 = V_97 ;
V_162 [ V_138 -> V_170 ] = V_67 ;
F_70 ( V_138 , V_67 ) ;
V_150 = F_71 ( & V_179 , V_3 ) ;
return V_150 ;
}
int T_4
F_72 ( void )
{
int V_150 ;
V_150 = F_73 ( & V_179 ) ;
if ( V_150 != 0 )
return V_150 ;
V_150 = F_74 ( & V_180 , F_65 ) ;
if ( V_150 != 0 )
F_75 ( & V_179 ) ;
return V_150 ;
}

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
0 , L_2 , V_3 ) ;
if ( V_68 ) {
F_36 ( L_3 ) ;
return V_68 ;
}
V_68 = F_35 ( V_67 -> V_94 , F_27 ,
0 , L_4 , V_3 ) ;
if ( V_68 ) {
F_36 ( L_5 ) ;
goto V_95;
}
V_68 = F_35 ( V_67 -> V_96 , F_26 ,
0 , L_6 , V_3 ) ;
if ( V_68 ) {
F_36 ( L_7 ) ;
goto V_97;
}
F_9 ( V_98 | V_99 | V_100 ,
V_3 -> V_7 + V_101 ) ;
return 0 ;
V_97:
F_37 ( V_67 -> V_94 , V_3 ) ;
V_95:
F_37 ( V_67 -> V_93 , V_3 ) ;
return V_68 ;
}
static void
F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_67 = F_1 ( V_3 ) ;
F_37 ( V_67 -> V_93 , V_3 ) ;
F_37 ( V_67 -> V_94 , V_3 ) ;
F_37 ( V_67 -> V_96 , V_3 ) ;
F_9 ( 0 , V_3 -> V_7 + V_92 ) ;
F_17 ( V_85 , V_86 ,
V_3 -> V_7 + V_87 ) ;
F_17 ( V_79 , V_80 ,
V_3 -> V_7 + V_81 ) ;
}
static void
F_39 ( struct V_2 * V_3 ,
struct V_102 * V_103 , struct V_102 * V_104 )
{
unsigned int V_105 ;
unsigned int V_106 ;
unsigned int V_107 ;
unsigned int V_108 ;
unsigned int V_109 = 0 ;
unsigned long V_4 ;
V_105 = V_103 -> V_110 ;
V_106 = V_103 -> V_111 ;
switch ( V_105 & V_112 ) {
case V_113 :
V_109 = V_114 ;
break;
case V_115 :
case V_116 :
default:
V_103 -> V_110 &= ~ V_112 ;
V_103 -> V_110 |= V_117 ;
V_109 = V_88 ;
break;
}
V_105 &= ~ V_118 ;
if ( V_105 & V_119 )
V_109 |= V_120 ;
if ( V_105 & V_121 ) {
if ( ! ( V_105 & V_122 ) )
V_109 &= ~ V_123 ;
else
V_109 |= V_123 ;
}
V_3 -> V_37 = V_34 ;
if ( V_106 & V_124 )
V_3 -> V_37 |= V_31 | V_28 ;
V_3 -> V_40 = 0 ;
if ( V_106 & V_125 )
V_3 -> V_40 |= V_31 | V_28 ;
if ( V_106 & V_126 ) {
if ( V_106 & V_125 )
V_3 -> V_40 |= V_34 ;
}
if ( ( V_105 & V_127 ) == 0 )
V_3 -> V_40 |= V_25 ;
V_109 |= V_89 | V_90 | V_91 ;
F_5 ( & V_5 , V_4 ) ;
F_17 ( 0 , V_109 , V_3 -> V_7 + V_92 ) ;
V_108 = F_40 ( V_3 , V_103 , V_104 , 0 , V_3 -> V_69 / 16 ) ;
V_107 = F_41 ( V_3 , V_108 ) ;
V_107 = V_107 / 2 - 1 ;
F_17 ( V_128 , 0 , V_3 -> V_7 + V_92 ) ;
F_17 ( V_129 , 0 , V_3 -> V_7 + V_92 ) ;
F_17 ( V_130 , 0 , V_3 -> V_7 + V_92 ) ;
F_9 ( V_107 , V_3 -> V_7 + V_131 ) ;
F_17 ( 0 , V_128 , V_3 -> V_7 + V_92 ) ;
F_9 ( V_132 , V_3 -> V_7 + V_8 ) ;
F_7 ( & V_5 , V_4 ) ;
if ( F_42 ( V_103 ) )
F_43 ( V_103 , V_108 , V_108 ) ;
F_44 ( V_3 , V_105 , V_108 ) ;
}
static const char *
F_45 ( struct V_2 * V_3 )
{
if ( V_3 -> type == V_133 )
return V_134 ;
else
return NULL ;
}
static void
F_46 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 & V_135 ) {
F_47 ( V_3 -> V_7 ) ;
V_3 -> V_7 = NULL ;
}
}
static int
F_48 ( struct V_2 * V_3 )
{
struct V_136 * V_137 = F_49 ( V_3 -> V_15 ) ;
struct V_138 * V_139 ;
int V_140 ;
V_139 = F_50 ( V_137 , V_141 , 0 ) ;
if ( ! V_139 ) {
F_51 ( & V_137 -> V_15 , L_8 ) ;
return - V_142 ;
}
V_140 = F_52 ( V_139 ) ;
V_139 = F_53 ( & V_137 -> V_15 , V_139 -> V_143 ,
V_140 , F_54 ( & V_137 -> V_15 ) ) ;
if ( ! V_139 ) {
F_51 ( & V_137 -> V_15 , L_9 ) ;
return - V_17 ;
}
if ( V_3 -> V_4 & V_135 ) {
V_3 -> V_7 = F_55 ( & V_137 -> V_15 ,
V_3 -> V_144 , V_140 ) ;
if ( V_3 -> V_7 == NULL )
return - V_145 ;
}
return 0 ;
}
static void
F_56 ( struct V_2 * V_3 , int V_4 )
{
if ( V_4 & V_146 ) {
V_3 -> type = V_133 ;
F_48 ( V_3 ) ;
}
}
static int
F_57 ( struct V_2 * V_3 ,
struct V_147 * V_148 )
{
int V_149 = 0 ;
if ( V_148 -> type != V_150 && V_148 -> type != V_133 )
V_149 = - V_151 ;
if ( V_148 -> V_53 < 0 || V_148 -> V_53 >= V_152 )
V_149 = - V_151 ;
if ( V_148 -> V_153 < 9600 )
V_149 = - V_151 ;
return V_149 ;
}
static void
F_58 ( struct V_2 * V_3 , int V_12 )
{
int V_154 ;
if ( ! V_3 -> V_7 )
return;
do {
V_154 = ( F_14 ( V_3 -> V_7 + V_18 )
& V_44 ) >> V_45 ;
} while ( V_154 == 0 );
F_21 ( V_12 , V_3 -> V_7 + V_47 ) ;
}
static void
F_59 ( struct V_155 * V_156 , const char * V_157 , T_3 V_158 )
{
struct V_1 * V_67 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
if ( V_156 -> V_159 >= V_160 )
return;
V_67 = V_161 [ V_156 -> V_159 ] ;
if ( ! V_67 )
return;
V_3 = & V_67 -> V_3 ;
F_5 ( & V_5 , V_4 ) ;
F_60 ( V_3 , V_157 , V_158 , F_58 ) ;
F_7 ( & V_5 , V_4 ) ;
}
static int T_4
F_61 ( struct V_155 * V_156 , char * V_162 )
{
struct V_1 * V_67 ;
struct V_2 * V_3 ;
int V_108 = 115200 ;
int V_163 = 8 ;
int V_29 = 'n' ;
int V_164 = 'n' ;
if ( V_156 -> V_159 >= V_160 )
return - V_142 ;
V_67 = V_161 [ V_156 -> V_159 ] ;
if ( ! V_67 )
return - V_142 ;
V_3 = & V_67 -> V_3 ;
V_3 -> V_69 = F_33 ( V_67 -> V_70 ) ;
if ( V_162 )
F_62 ( V_162 , & V_108 , & V_29 , & V_163 , & V_164 ) ;
return F_63 ( V_3 , V_156 , V_108 , V_29 , V_163 , V_164 ) ;
}
static int T_4
F_64 ( void )
{
F_65 ( & V_165 ) ;
return 0 ;
}
static int T_4
F_66 ( struct V_136 * V_137 )
{
struct V_1 * V_67 ;
struct V_2 * V_3 ;
struct V_138 * V_166 , * V_167 ;
int V_93 , V_94 , V_96 ;
struct V_70 * V_70 ;
int V_149 ;
V_166 = F_50 ( V_137 , V_141 , 0 ) ;
V_167 = F_50 ( V_137 , V_168 , 0 ) ;
if ( ! V_166 || ! V_167 )
return - V_142 ;
if ( V_137 -> V_169 >= V_160 )
return - V_17 ;
if ( V_161 [ V_137 -> V_169 ] != NULL )
return - V_17 ;
V_70 = F_67 ( & V_137 -> V_15 , L_10 ) ;
if ( F_68 ( V_70 ) ) {
F_36 ( L_11 ) ;
return - V_170 ;
}
V_93 = F_69 ( V_137 , L_12 ) ;
V_94 = F_69 ( V_137 , L_13 ) ;
V_96 = F_69 ( V_137 , L_14 ) ;
if ( ( V_93 < 0 ) | ( V_94 < 0 ) | ( V_96 < 0 ) )
return - V_142 ;
V_67 = F_70 ( sizeof( struct V_1 ) , V_171 ) ;
if ( ! V_67 )
return - V_145 ;
V_3 = & V_67 -> V_3 ;
V_3 -> V_172 = V_173 ;
V_3 -> V_4 = V_174 | V_135 ;
V_3 -> V_175 = & V_176 ;
V_3 -> V_177 = 16 ;
V_3 -> type = V_133 ,
V_3 -> line = V_137 -> V_169 ;
V_3 -> V_15 = & V_137 -> V_15 ;
V_3 -> V_53 = V_93 ;
V_3 -> V_144 = V_166 -> V_143 ;
V_67 -> V_70 = V_70 ;
V_67 -> V_93 = V_93 ;
V_67 -> V_94 = V_94 ;
V_67 -> V_96 = V_96 ;
V_161 [ V_137 -> V_169 ] = V_67 ;
F_71 ( V_137 , V_67 ) ;
V_149 = F_72 ( & V_178 , V_3 ) ;
return V_149 ;
}
int T_4
F_73 ( void )
{
int V_149 ;
V_149 = F_74 ( & V_178 ) ;
if ( V_149 != 0 )
return V_149 ;
V_149 = F_75 ( & V_179 , F_66 ) ;
if ( V_149 != 0 )
F_76 ( & V_178 ) ;
return V_149 ;
}

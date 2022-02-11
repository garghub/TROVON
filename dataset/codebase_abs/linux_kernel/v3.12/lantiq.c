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
struct V_9 * V_10 = & V_3 -> V_11 -> V_3 ;
unsigned int V_12 = 0 , V_13 = 0 , V_14 ;
V_14 = F_12 ( V_3 -> V_7 + V_15 ) & V_16 ;
while ( V_14 -- ) {
T_1 V_17 = V_18 ;
V_12 = F_13 ( V_3 -> V_7 + V_19 ) ;
V_13 = ( F_12 ( V_3 -> V_7 + V_20 )
& V_21 ) | V_22 ;
F_14 ( V_10 ) ;
V_3 -> V_23 . V_24 ++ ;
if ( V_13 & V_21 ) {
if ( V_13 & V_25 ) {
V_3 -> V_23 . V_26 ++ ;
F_15 ( 0 , V_27 ,
V_3 -> V_7 + V_8 ) ;
} else if ( V_13 & V_28 ) {
V_3 -> V_23 . V_29 ++ ;
F_15 ( 0 , V_30 ,
V_3 -> V_7 + V_8 ) ;
}
if ( V_13 & V_31 ) {
V_3 -> V_23 . V_32 ++ ;
F_15 ( 0 , V_33 ,
V_3 -> V_7 + V_8 ) ;
}
V_13 &= V_3 -> V_34 ;
if ( V_13 & V_25 )
V_17 = V_35 ;
else if ( V_13 & V_28 )
V_17 = V_36 ;
}
if ( ( V_13 & V_3 -> V_37 ) == 0 )
F_16 ( V_10 , V_12 , V_17 ) ;
if ( V_13 & V_31 )
F_16 ( V_10 , 0 , V_38 ) ;
}
if ( V_12 != 0 )
F_14 ( V_10 ) ;
return 0 ;
}
static void
F_6 ( struct V_2 * V_3 )
{
struct V_39 * V_40 = & V_3 -> V_11 -> V_40 ;
if ( F_17 ( V_3 ) ) {
F_3 ( V_3 ) ;
return;
}
while ( ( ( F_12 ( V_3 -> V_7 + V_15 ) &
V_41 ) >> V_42 ) != 0 ) {
if ( V_3 -> V_43 ) {
F_18 ( V_3 -> V_43 , V_3 -> V_7 + V_44 ) ;
V_3 -> V_23 . V_45 ++ ;
V_3 -> V_43 = 0 ;
continue;
}
if ( F_19 ( V_40 ) )
break;
F_18 ( V_3 -> V_11 -> V_40 . V_46 [ V_3 -> V_11 -> V_40 . V_47 ] ,
V_3 -> V_7 + V_44 ) ;
V_40 -> V_47 = ( V_40 -> V_47 + 1 ) & ( V_48 - 1 ) ;
V_3 -> V_23 . V_45 ++ ;
}
if ( F_20 ( V_40 ) < V_49 )
F_21 ( V_3 ) ;
}
static T_2
F_22 ( int V_50 , void * V_51 )
{
unsigned long V_4 ;
struct V_2 * V_3 = (struct V_2 * ) V_51 ;
F_5 ( & V_5 , V_4 ) ;
F_9 ( V_52 , V_3 -> V_7 + V_53 ) ;
F_7 ( & V_5 , V_4 ) ;
F_4 ( V_3 ) ;
return V_54 ;
}
static T_2
F_23 ( int V_50 , void * V_51 )
{
unsigned long V_4 ;
struct V_2 * V_3 = (struct V_2 * ) V_51 ;
F_5 ( & V_5 , V_4 ) ;
F_15 ( 0 , V_27 | V_30 |
V_33 , V_3 -> V_7 + V_8 ) ;
F_7 ( & V_5 , V_4 ) ;
return V_54 ;
}
static T_2
F_24 ( int V_50 , void * V_51 )
{
unsigned long V_4 ;
struct V_2 * V_3 = (struct V_2 * ) V_51 ;
F_5 ( & V_5 , V_4 ) ;
F_9 ( V_55 , V_3 -> V_7 + V_53 ) ;
F_11 ( V_3 ) ;
F_7 ( & V_5 , V_4 ) ;
return V_54 ;
}
static unsigned int
F_25 ( struct V_2 * V_3 )
{
int V_56 ;
V_56 = F_12 ( V_3 -> V_7 + V_15 ) & V_57 ;
return V_56 ? 0 : V_58 ;
}
static unsigned int
F_26 ( struct V_2 * V_3 )
{
return V_59 | V_60 | V_61 ;
}
static void
F_27 ( struct V_2 * V_3 , T_3 V_62 )
{
}
static void
F_28 ( struct V_2 * V_3 , int V_63 )
{
}
static int
F_29 ( struct V_2 * V_3 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
int V_65 ;
if ( ! F_30 ( V_64 -> V_66 ) )
F_31 ( V_64 -> V_66 ) ;
V_3 -> V_67 = F_32 ( V_64 -> V_68 ) ;
F_15 ( V_69 | V_70 , ( 1 << V_71 ) ,
V_3 -> V_7 + V_72 ) ;
F_9 ( 0 , V_3 -> V_7 + V_73 ) ;
F_9 (
( ( V_74 << V_75 ) & V_76 ) |
V_77 | V_78 ,
V_3 -> V_7 + V_79 ) ;
F_9 (
( ( V_80 << V_81 ) & V_82 )
| V_83 | V_84 ,
V_3 -> V_7 + V_85 ) ;
F_33 () ;
F_15 ( 0 , V_86 | V_87 | V_88 |
V_89 , V_3 -> V_7 + V_90 ) ;
V_65 = F_34 ( V_64 -> V_91 , F_22 ,
0 , L_1 , V_3 ) ;
if ( V_65 ) {
F_35 ( L_2 ) ;
return V_65 ;
}
V_65 = F_34 ( V_64 -> V_92 , F_24 ,
0 , L_3 , V_3 ) ;
if ( V_65 ) {
F_35 ( L_4 ) ;
goto V_93;
}
V_65 = F_34 ( V_64 -> V_94 , F_23 ,
0 , L_5 , V_3 ) ;
if ( V_65 ) {
F_35 ( L_6 ) ;
goto V_95;
}
F_9 ( V_96 | V_97 | V_98 ,
V_3 -> V_7 + V_99 ) ;
return 0 ;
V_95:
F_36 ( V_64 -> V_92 , V_3 ) ;
V_93:
F_36 ( V_64 -> V_91 , V_3 ) ;
return V_65 ;
}
static void
F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_64 = F_1 ( V_3 ) ;
F_36 ( V_64 -> V_91 , V_3 ) ;
F_36 ( V_64 -> V_92 , V_3 ) ;
F_36 ( V_64 -> V_94 , V_3 ) ;
F_9 ( 0 , V_3 -> V_7 + V_90 ) ;
F_15 ( V_83 , V_84 ,
V_3 -> V_7 + V_85 ) ;
F_15 ( V_77 , V_78 ,
V_3 -> V_7 + V_79 ) ;
if ( ! F_30 ( V_64 -> V_66 ) )
F_38 ( V_64 -> V_66 ) ;
}
static void
F_39 ( struct V_2 * V_3 ,
struct V_100 * V_101 , struct V_100 * V_102 )
{
unsigned int V_103 ;
unsigned int V_104 ;
unsigned int V_105 ;
unsigned int V_106 ;
unsigned int V_107 = 0 ;
unsigned long V_4 ;
V_103 = V_101 -> V_108 ;
V_104 = V_101 -> V_109 ;
switch ( V_103 & V_110 ) {
case V_111 :
V_107 = V_112 ;
break;
case V_113 :
case V_114 :
default:
V_101 -> V_108 &= ~ V_110 ;
V_101 -> V_108 |= V_115 ;
V_107 = V_86 ;
break;
}
V_103 &= ~ V_116 ;
if ( V_103 & V_117 )
V_107 |= V_118 ;
if ( V_103 & V_119 ) {
if ( ! ( V_103 & V_120 ) )
V_107 &= ~ V_121 ;
else
V_107 |= V_121 ;
}
V_3 -> V_34 = V_31 ;
if ( V_104 & V_122 )
V_3 -> V_34 |= V_28 | V_25 ;
V_3 -> V_37 = 0 ;
if ( V_104 & V_123 )
V_3 -> V_37 |= V_28 | V_25 ;
if ( V_104 & V_124 ) {
if ( V_104 & V_123 )
V_3 -> V_37 |= V_31 ;
}
if ( ( V_103 & V_125 ) == 0 )
V_3 -> V_37 |= V_22 ;
V_107 |= V_87 | V_88 | V_89 ;
F_5 ( & V_5 , V_4 ) ;
F_15 ( 0 , V_107 , V_3 -> V_7 + V_90 ) ;
V_106 = F_40 ( V_3 , V_101 , V_102 , 0 , V_3 -> V_67 / 16 ) ;
V_105 = F_41 ( V_3 , V_106 ) ;
V_105 = V_105 / 2 - 1 ;
F_15 ( V_126 , 0 , V_3 -> V_7 + V_90 ) ;
F_15 ( V_127 , 0 , V_3 -> V_7 + V_90 ) ;
F_15 ( V_128 , 0 , V_3 -> V_7 + V_90 ) ;
F_9 ( V_105 , V_3 -> V_7 + V_129 ) ;
F_15 ( 0 , V_126 , V_3 -> V_7 + V_90 ) ;
F_9 ( V_130 , V_3 -> V_7 + V_8 ) ;
F_7 ( & V_5 , V_4 ) ;
if ( F_42 ( V_101 ) )
F_43 ( V_101 , V_106 , V_106 ) ;
F_44 ( V_3 , V_103 , V_106 ) ;
}
static const char *
F_45 ( struct V_2 * V_3 )
{
if ( V_3 -> type == V_131 )
return V_132 ;
else
return NULL ;
}
static void
F_46 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 & V_133 ) {
F_47 ( V_3 -> V_7 ) ;
V_3 -> V_7 = NULL ;
}
}
static int
F_48 ( struct V_2 * V_3 )
{
struct V_134 * V_135 = F_49 ( V_3 -> V_136 ) ;
struct V_137 * V_138 ;
int V_139 ;
V_138 = F_50 ( V_135 , V_140 , 0 ) ;
if ( ! V_138 ) {
F_51 ( & V_135 -> V_136 , L_7 ) ;
return - V_141 ;
}
V_139 = F_52 ( V_138 ) ;
V_138 = F_53 ( & V_135 -> V_136 , V_138 -> V_142 ,
V_139 , F_54 ( & V_135 -> V_136 ) ) ;
if ( ! V_138 ) {
F_51 ( & V_135 -> V_136 , L_8 ) ;
return - V_143 ;
}
if ( V_3 -> V_4 & V_133 ) {
V_3 -> V_7 = F_55 ( & V_135 -> V_136 ,
V_3 -> V_144 , V_139 ) ;
if ( V_3 -> V_7 == NULL )
return - V_145 ;
}
return 0 ;
}
static void
F_56 ( struct V_2 * V_3 , int V_4 )
{
if ( V_4 & V_146 ) {
V_3 -> type = V_131 ;
F_48 ( V_3 ) ;
}
}
static int
F_57 ( struct V_2 * V_3 ,
struct V_147 * V_148 )
{
int V_149 = 0 ;
if ( V_148 -> type != V_150 && V_148 -> type != V_131 )
V_149 = - V_151 ;
if ( V_148 -> V_50 < 0 || V_148 -> V_50 >= V_152 )
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
V_154 = ( F_12 ( V_3 -> V_7 + V_15 )
& V_41 ) >> V_42 ;
} while ( V_154 == 0 );
F_18 ( V_12 , V_3 -> V_7 + V_44 ) ;
}
static void
F_59 ( struct V_155 * V_156 , const char * V_157 , T_3 V_158 )
{
struct V_1 * V_64 ;
struct V_2 * V_3 ;
unsigned long V_4 ;
if ( V_156 -> V_159 >= V_160 )
return;
V_64 = V_161 [ V_156 -> V_159 ] ;
if ( ! V_64 )
return;
V_3 = & V_64 -> V_3 ;
F_5 ( & V_5 , V_4 ) ;
F_60 ( V_3 , V_157 , V_158 , F_58 ) ;
F_7 ( & V_5 , V_4 ) ;
}
static int T_4
F_61 ( struct V_155 * V_156 , char * V_162 )
{
struct V_1 * V_64 ;
struct V_2 * V_3 ;
int V_106 = 115200 ;
int V_163 = 8 ;
int V_26 = 'n' ;
int V_164 = 'n' ;
if ( V_156 -> V_159 >= V_160 )
return - V_141 ;
V_64 = V_161 [ V_156 -> V_159 ] ;
if ( ! V_64 )
return - V_141 ;
V_3 = & V_64 -> V_3 ;
if ( ! F_30 ( V_64 -> V_66 ) )
F_31 ( V_64 -> V_66 ) ;
V_3 -> V_67 = F_32 ( V_64 -> V_68 ) ;
if ( V_162 )
F_62 ( V_162 , & V_106 , & V_26 , & V_163 , & V_164 ) ;
return F_63 ( V_3 , V_156 , V_106 , V_26 , V_163 , V_164 ) ;
}
static int T_4
F_64 ( void )
{
F_65 ( & V_165 ) ;
return 0 ;
}
static int T_4
F_66 ( struct V_134 * V_135 )
{
struct V_166 * V_167 = V_135 -> V_136 . V_168 ;
struct V_1 * V_64 ;
struct V_2 * V_3 ;
struct V_137 * V_169 , V_170 [ 3 ] ;
int line = 0 ;
int V_149 ;
V_169 = F_50 ( V_135 , V_140 , 0 ) ;
V_149 = F_67 ( V_167 , V_170 , 3 ) ;
if ( ! V_169 || ( V_149 != 3 ) ) {
F_51 ( & V_135 -> V_136 ,
L_9 ) ;
return - V_141 ;
}
if ( V_169 -> V_142 != F_68 ( V_171 ) )
line = 1 ;
if ( V_161 [ line ] ) {
F_51 ( & V_135 -> V_136 , L_10 , line ) ;
return - V_143 ;
}
V_64 = F_69 ( & V_135 -> V_136 , sizeof( struct V_1 ) ,
V_172 ) ;
if ( ! V_64 )
return - V_145 ;
V_3 = & V_64 -> V_3 ;
V_3 -> V_173 = V_174 ;
V_3 -> V_4 = V_175 | V_133 ;
V_3 -> V_176 = & V_177 ;
V_3 -> V_178 = 16 ;
V_3 -> type = V_131 ,
V_3 -> line = line ;
V_3 -> V_136 = & V_135 -> V_136 ;
V_3 -> V_50 = V_170 [ 0 ] . V_142 ;
V_3 -> V_144 = V_169 -> V_142 ;
V_64 -> V_68 = F_70 () ;
if ( F_30 ( V_64 -> V_68 ) ) {
F_35 ( L_11 ) ;
return - V_179 ;
}
V_64 -> V_66 = F_71 ( & V_135 -> V_136 , NULL ) ;
V_64 -> V_91 = V_170 [ 0 ] . V_142 ;
V_64 -> V_92 = V_170 [ 1 ] . V_142 ;
V_64 -> V_94 = V_170 [ 2 ] . V_142 ;
V_161 [ line ] = V_64 ;
F_72 ( V_135 , V_64 ) ;
V_149 = F_73 ( & V_180 , V_3 ) ;
return V_149 ;
}
int T_4
F_74 ( void )
{
int V_149 ;
V_149 = F_75 ( & V_180 ) ;
if ( V_149 != 0 )
return V_149 ;
V_149 = F_76 ( & V_181 , F_66 ) ;
if ( V_149 != 0 )
F_77 ( & V_180 ) ;
return V_149 ;
}

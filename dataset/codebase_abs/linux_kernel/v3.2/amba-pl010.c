static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_5 ;
V_5 = F_2 ( V_4 -> V_2 . V_6 + V_7 ) ;
V_5 &= ~ V_8 ;
F_3 ( V_5 , V_4 -> V_2 . V_6 + V_7 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_5 ;
V_5 = F_2 ( V_4 -> V_2 . V_6 + V_7 ) ;
V_5 |= V_8 ;
F_3 ( V_5 , V_4 -> V_2 . V_6 + V_7 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_5 ;
V_5 = F_2 ( V_4 -> V_2 . V_6 + V_7 ) ;
V_5 &= ~ ( V_9 | V_10 ) ;
F_3 ( V_5 , V_4 -> V_2 . V_6 + V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_5 ;
V_5 = F_2 ( V_4 -> V_2 . V_6 + V_7 ) ;
V_5 |= V_11 ;
F_3 ( V_5 , V_4 -> V_2 . V_6 + V_7 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_2 . V_14 -> V_2 . V_13 ;
unsigned int V_15 , V_16 , V_17 , V_18 , V_19 = 256 ;
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) ;
while ( F_8 ( V_15 ) && V_19 -- ) {
V_16 = F_2 ( V_4 -> V_2 . V_6 + V_21 ) ;
V_17 = V_22 ;
V_4 -> V_2 . V_23 . V_24 ++ ;
V_18 = F_2 ( V_4 -> V_2 . V_6 + V_25 ) | V_26 ;
if ( F_9 ( V_18 & V_27 ) ) {
F_3 ( 0 , V_4 -> V_2 . V_6 + V_28 ) ;
if ( V_18 & V_29 ) {
V_18 &= ~ ( V_30 | V_31 ) ;
V_4 -> V_2 . V_23 . V_32 ++ ;
if ( F_10 ( & V_4 -> V_2 ) )
goto V_33;
} else if ( V_18 & V_31 )
V_4 -> V_2 . V_23 . V_34 ++ ;
else if ( V_18 & V_30 )
V_4 -> V_2 . V_23 . V_35 ++ ;
if ( V_18 & V_36 )
V_4 -> V_2 . V_23 . V_37 ++ ;
V_18 &= V_4 -> V_2 . V_38 ;
if ( V_18 & V_29 )
V_17 = V_39 ;
else if ( V_18 & V_31 )
V_17 = V_40 ;
else if ( V_18 & V_30 )
V_17 = V_41 ;
}
if ( F_11 ( & V_4 -> V_2 , V_16 ) )
goto V_33;
F_12 ( & V_4 -> V_2 , V_18 , V_36 , V_16 , V_17 ) ;
V_33:
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) ;
}
F_13 ( & V_4 -> V_2 . V_42 ) ;
F_14 ( V_13 ) ;
F_15 ( & V_4 -> V_2 . V_42 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_43 * V_44 = & V_4 -> V_2 . V_14 -> V_44 ;
int V_45 ;
if ( V_4 -> V_2 . V_46 ) {
F_3 ( V_4 -> V_2 . V_46 , V_4 -> V_2 . V_6 + V_21 ) ;
V_4 -> V_2 . V_23 . V_47 ++ ;
V_4 -> V_2 . V_46 = 0 ;
return;
}
if ( F_17 ( V_44 ) || F_18 ( & V_4 -> V_2 ) ) {
F_1 ( & V_4 -> V_2 ) ;
return;
}
V_45 = V_4 -> V_2 . V_48 >> 1 ;
do {
F_3 ( V_44 -> V_49 [ V_44 -> V_50 ] , V_4 -> V_2 . V_6 + V_21 ) ;
V_44 -> V_50 = ( V_44 -> V_50 + 1 ) & ( V_51 - 1 ) ;
V_4 -> V_2 . V_23 . V_47 ++ ;
if ( F_17 ( V_44 ) )
break;
} while ( -- V_45 > 0 );
if ( F_19 ( V_44 ) < V_52 )
F_20 ( & V_4 -> V_2 ) ;
if ( F_17 ( V_44 ) )
F_1 ( & V_4 -> V_2 ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
unsigned int V_15 , V_53 ;
F_3 ( 0 , V_4 -> V_2 . V_6 + V_54 ) ;
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) & V_55 ;
V_53 = V_15 ^ V_4 -> V_56 ;
V_4 -> V_56 = V_15 ;
if ( ! V_53 )
return;
if ( V_53 & V_57 )
F_22 ( & V_4 -> V_2 , V_15 & V_57 ) ;
if ( V_53 & V_58 )
V_4 -> V_2 . V_23 . V_59 ++ ;
if ( V_53 & V_60 )
F_23 ( & V_4 -> V_2 , V_15 & V_60 ) ;
F_24 ( & V_4 -> V_2 . V_14 -> V_2 . V_61 ) ;
}
static T_1 F_25 ( int V_62 , void * V_63 )
{
struct V_3 * V_4 = V_63 ;
unsigned int V_15 , V_64 = V_65 ;
int V_66 = 0 ;
F_15 ( & V_4 -> V_2 . V_42 ) ;
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_67 ) ;
if ( V_15 ) {
do {
if ( V_15 & ( V_68 | V_69 ) )
F_7 ( V_4 ) ;
if ( V_15 & V_70 )
F_21 ( V_4 ) ;
if ( V_15 & V_71 )
F_16 ( V_4 ) ;
if ( V_64 -- == 0 )
break;
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_67 ) ;
} while ( V_15 & ( V_68 | V_69 |
V_71 ) );
V_66 = 1 ;
}
F_13 ( & V_4 -> V_2 . V_42 ) ;
return F_26 ( V_66 ) ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_15 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) ;
return V_15 & V_72 ? 0 : V_73 ;
}
static unsigned int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_74 = 0 ;
unsigned int V_15 ;
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) ;
if ( V_15 & V_57 )
V_74 |= V_75 ;
if ( V_15 & V_58 )
V_74 |= V_76 ;
if ( V_15 & V_60 )
V_74 |= V_77 ;
return V_74 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_78 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_4 -> V_79 )
V_4 -> V_79 -> V_80 ( V_4 -> V_81 , V_4 -> V_2 . V_6 , V_78 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_82 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_83 ;
unsigned int V_84 ;
F_31 ( & V_4 -> V_2 . V_42 , V_83 ) ;
V_84 = F_2 ( V_4 -> V_2 . V_6 + V_85 ) ;
if ( V_82 == - 1 )
V_84 |= V_86 ;
else
V_84 &= ~ V_86 ;
F_3 ( V_84 , V_4 -> V_2 . V_6 + V_85 ) ;
F_32 ( & V_4 -> V_2 . V_42 , V_83 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
int V_87 ;
V_87 = F_34 ( V_4 -> V_88 ) ;
if ( V_87 )
goto V_89;
V_87 = F_35 ( V_4 -> V_88 ) ;
if ( V_87 )
goto V_90;
V_4 -> V_2 . V_91 = F_36 ( V_4 -> V_88 ) ;
V_87 = F_37 ( V_4 -> V_2 . V_62 , F_25 , 0 , L_1 , V_4 ) ;
if ( V_87 )
goto V_92;
V_4 -> V_56 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) & V_55 ;
F_3 ( V_93 | V_9 | V_10 ,
V_4 -> V_2 . V_6 + V_7 ) ;
return 0 ;
V_92:
F_38 ( V_4 -> V_88 ) ;
V_90:
F_39 ( V_4 -> V_88 ) ;
V_89:
return V_87 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_41 ( V_4 -> V_2 . V_62 , V_4 ) ;
F_3 ( 0 , V_4 -> V_2 . V_6 + V_7 ) ;
F_3 ( F_2 ( V_4 -> V_2 . V_6 + V_85 ) &
~ ( V_86 | V_94 ) ,
V_4 -> V_2 . V_6 + V_85 ) ;
F_38 ( V_4 -> V_88 ) ;
F_39 ( V_4 -> V_88 ) ;
}
static void
F_42 ( struct V_1 * V_2 , struct V_95 * V_96 ,
struct V_95 * V_97 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_84 , V_98 ;
unsigned long V_83 ;
unsigned int V_99 , V_100 ;
V_99 = F_43 ( V_2 , V_96 , V_97 , 0 , V_4 -> V_2 . V_91 / 16 ) ;
V_100 = F_44 ( V_2 , V_99 ) ;
switch ( V_96 -> V_101 & V_102 ) {
case V_103 :
V_84 = V_104 ;
break;
case V_105 :
V_84 = V_106 ;
break;
case V_107 :
V_84 = V_108 ;
break;
default:
V_84 = V_109 ;
break;
}
if ( V_96 -> V_101 & V_110 )
V_84 |= V_111 ;
if ( V_96 -> V_101 & V_112 ) {
V_84 |= V_113 ;
if ( ! ( V_96 -> V_101 & V_114 ) )
V_84 |= V_115 ;
}
if ( V_4 -> V_2 . V_48 > 1 )
V_84 |= V_94 ;
F_31 ( & V_4 -> V_2 . V_42 , V_83 ) ;
F_45 ( V_2 , V_96 -> V_101 , V_99 ) ;
V_4 -> V_2 . V_38 = V_36 ;
if ( V_96 -> V_116 & V_117 )
V_4 -> V_2 . V_38 |= V_30 | V_31 ;
if ( V_96 -> V_116 & ( V_118 | V_119 ) )
V_4 -> V_2 . V_38 |= V_29 ;
V_4 -> V_2 . V_120 = 0 ;
if ( V_96 -> V_116 & V_121 )
V_4 -> V_2 . V_120 |= V_30 | V_31 ;
if ( V_96 -> V_116 & V_122 ) {
V_4 -> V_2 . V_120 |= V_29 ;
if ( V_96 -> V_116 & V_121 )
V_4 -> V_2 . V_120 |= V_36 ;
}
if ( ( V_96 -> V_101 & V_123 ) == 0 )
V_4 -> V_2 . V_120 |= V_26 ;
V_98 = F_2 ( V_4 -> V_2 . V_6 + V_7 ) & ~ V_11 ;
if ( F_46 ( V_2 , V_96 -> V_101 ) )
V_98 |= V_11 ;
F_3 ( 0 , V_4 -> V_2 . V_6 + V_7 ) ;
V_100 -= 1 ;
F_3 ( ( V_100 & 0xf00 ) >> 8 , V_4 -> V_2 . V_6 + V_124 ) ;
F_3 ( V_100 & 0xff , V_4 -> V_2 . V_6 + V_125 ) ;
F_3 ( V_84 , V_4 -> V_2 . V_6 + V_85 ) ;
F_3 ( V_98 , V_4 -> V_2 . V_6 + V_7 ) ;
F_32 ( & V_4 -> V_2 . V_42 , V_83 ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_126 )
{
if ( V_126 == V_127 ) {
V_2 -> V_83 |= V_128 ;
F_6 ( V_2 ) ;
} else
V_2 -> V_83 &= ~ V_128 ;
}
static const char * F_48 ( struct V_1 * V_2 )
{
return V_2 -> type == V_129 ? L_2 : NULL ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_50 ( V_2 -> V_130 , V_131 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
return F_52 ( V_2 -> V_130 , V_131 , L_1 )
!= NULL ? 0 : - V_132 ;
}
static void F_53 ( struct V_1 * V_2 , int V_83 )
{
if ( V_83 & V_133 ) {
V_2 -> type = V_129 ;
F_51 ( V_2 ) ;
}
}
static int F_54 ( struct V_1 * V_2 , struct V_134 * V_135 )
{
int V_136 = 0 ;
if ( V_135 -> type != V_137 && V_135 -> type != V_129 )
V_136 = - V_138 ;
if ( V_135 -> V_62 < 0 || V_135 -> V_62 >= V_139 )
V_136 = - V_138 ;
if ( V_135 -> V_140 < 9600 )
V_136 = - V_138 ;
return V_136 ;
}
static void F_55 ( struct V_1 * V_2 , int V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_15 ;
do {
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) ;
F_56 () ;
} while ( ! F_57 ( V_15 ) );
F_3 ( V_16 , V_4 -> V_2 . V_6 + V_21 ) ;
}
static void
F_58 ( struct V_141 * V_142 , const char * V_143 , unsigned int V_45 )
{
struct V_3 * V_4 = V_144 [ V_142 -> V_145 ] ;
unsigned int V_15 , V_98 ;
F_35 ( V_4 -> V_88 ) ;
V_98 = F_2 ( V_4 -> V_2 . V_6 + V_7 ) ;
F_3 ( V_93 , V_4 -> V_2 . V_6 + V_7 ) ;
F_59 ( & V_4 -> V_2 , V_143 , V_45 , F_55 ) ;
do {
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) ;
F_56 () ;
} while ( V_15 & V_72 );
F_3 ( V_98 , V_4 -> V_2 . V_6 + V_7 ) ;
F_38 ( V_4 -> V_88 ) ;
}
static void T_2
F_60 ( struct V_3 * V_4 , int * V_99 ,
int * V_34 , int * V_146 )
{
if ( F_2 ( V_4 -> V_2 . V_6 + V_7 ) & V_93 ) {
unsigned int V_84 , V_100 ;
V_84 = F_2 ( V_4 -> V_2 . V_6 + V_85 ) ;
* V_34 = 'n' ;
if ( V_84 & V_113 ) {
if ( V_84 & V_115 )
* V_34 = 'e' ;
else
* V_34 = 'o' ;
}
if ( ( V_84 & 0x60 ) == V_108 )
* V_146 = 7 ;
else
* V_146 = 8 ;
V_100 = F_2 ( V_4 -> V_2 . V_6 + V_125 ) |
F_2 ( V_4 -> V_2 . V_6 + V_124 ) << 8 ;
* V_99 = V_4 -> V_2 . V_91 / ( 16 * ( V_100 + 1 ) ) ;
}
}
static int T_2 F_61 ( struct V_141 * V_142 , char * V_147 )
{
struct V_3 * V_4 ;
int V_99 = 38400 ;
int V_146 = 8 ;
int V_34 = 'n' ;
int V_148 = 'n' ;
int V_136 ;
if ( V_142 -> V_145 >= V_149 )
V_142 -> V_145 = 0 ;
V_4 = V_144 [ V_142 -> V_145 ] ;
if ( ! V_4 )
return - V_150 ;
V_136 = F_34 ( V_4 -> V_88 ) ;
if ( V_136 )
return V_136 ;
V_4 -> V_2 . V_91 = F_36 ( V_4 -> V_88 ) ;
if ( V_147 )
F_62 ( V_147 , & V_99 , & V_34 , & V_146 , & V_148 ) ;
else
F_60 ( V_4 , & V_99 , & V_34 , & V_146 ) ;
return F_63 ( & V_4 -> V_2 , V_142 , V_99 , V_34 , V_146 , V_148 ) ;
}
static int F_64 ( struct V_151 * V_81 , const struct V_152 * V_153 )
{
struct V_3 * V_4 ;
void T_3 * V_154 ;
int V_155 , V_136 ;
for ( V_155 = 0 ; V_155 < F_65 ( V_144 ) ; V_155 ++ )
if ( V_144 [ V_155 ] == NULL )
break;
if ( V_155 == F_65 ( V_144 ) ) {
V_136 = - V_132 ;
goto V_89;
}
V_4 = F_66 ( sizeof( struct V_3 ) , V_156 ) ;
if ( ! V_4 ) {
V_136 = - V_157 ;
goto V_89;
}
V_154 = F_67 ( V_81 -> V_158 . V_159 , F_68 ( & V_81 -> V_158 ) ) ;
if ( ! V_154 ) {
V_136 = - V_157 ;
goto free;
}
V_4 -> V_88 = F_69 ( & V_81 -> V_81 , NULL ) ;
if ( F_70 ( V_4 -> V_88 ) ) {
V_136 = F_71 ( V_4 -> V_88 ) ;
goto V_160;
}
V_4 -> V_2 . V_81 = & V_81 -> V_81 ;
V_4 -> V_2 . V_130 = V_81 -> V_158 . V_159 ;
V_4 -> V_2 . V_6 = V_154 ;
V_4 -> V_2 . V_161 = V_162 ;
V_4 -> V_2 . V_62 = V_81 -> V_62 [ 0 ] ;
V_4 -> V_2 . V_48 = 16 ;
V_4 -> V_2 . V_163 = & V_164 ;
V_4 -> V_2 . V_83 = V_165 ;
V_4 -> V_2 . line = V_155 ;
V_4 -> V_81 = V_81 ;
V_4 -> V_79 = V_81 -> V_81 . V_166 ;
V_144 [ V_155 ] = V_4 ;
F_72 ( V_81 , V_4 ) ;
V_136 = F_73 ( & V_167 , & V_4 -> V_2 ) ;
if ( V_136 ) {
F_72 ( V_81 , NULL ) ;
V_144 [ V_155 ] = NULL ;
F_74 ( V_4 -> V_88 ) ;
V_160:
F_75 ( V_154 ) ;
free:
F_76 ( V_4 ) ;
}
V_89:
return V_136 ;
}
static int F_77 ( struct V_151 * V_81 )
{
struct V_3 * V_4 = F_78 ( V_81 ) ;
int V_155 ;
F_72 ( V_81 , NULL ) ;
F_79 ( & V_167 , & V_4 -> V_2 ) ;
for ( V_155 = 0 ; V_155 < F_65 ( V_144 ) ; V_155 ++ )
if ( V_144 [ V_155 ] == V_4 )
V_144 [ V_155 ] = NULL ;
F_75 ( V_4 -> V_2 . V_6 ) ;
F_74 ( V_4 -> V_88 ) ;
F_76 ( V_4 ) ;
return 0 ;
}
static int F_80 ( struct V_151 * V_81 , T_4 V_14 )
{
struct V_3 * V_4 = F_78 ( V_81 ) ;
if ( V_4 )
F_81 ( & V_167 , & V_4 -> V_2 ) ;
return 0 ;
}
static int F_82 ( struct V_151 * V_81 )
{
struct V_3 * V_4 = F_78 ( V_81 ) ;
if ( V_4 )
F_83 ( & V_167 , & V_4 -> V_2 ) ;
return 0 ;
}
static int T_2 F_84 ( void )
{
int V_136 ;
F_85 ( V_168 L_3 ) ;
V_136 = F_86 ( & V_167 ) ;
if ( V_136 == 0 ) {
V_136 = F_87 ( & V_169 ) ;
if ( V_136 )
F_88 ( & V_167 ) ;
}
return V_136 ;
}
static void T_5 F_89 ( void )
{
F_90 ( & V_169 ) ;
F_88 ( & V_167 ) ;
}

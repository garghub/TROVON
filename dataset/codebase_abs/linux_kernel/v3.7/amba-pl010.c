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
V_4 -> V_2 . V_90 = F_35 ( V_4 -> V_88 ) ;
V_87 = F_36 ( V_4 -> V_2 . V_62 , F_25 , 0 , L_1 , V_4 ) ;
if ( V_87 )
goto V_91;
V_4 -> V_56 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) & V_55 ;
F_3 ( V_92 | V_9 | V_10 ,
V_4 -> V_2 . V_6 + V_7 ) ;
return 0 ;
V_91:
F_37 ( V_4 -> V_88 ) ;
V_89:
return V_87 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_39 ( V_4 -> V_2 . V_62 , V_4 ) ;
F_3 ( 0 , V_4 -> V_2 . V_6 + V_7 ) ;
F_3 ( F_2 ( V_4 -> V_2 . V_6 + V_85 ) &
~ ( V_86 | V_93 ) ,
V_4 -> V_2 . V_6 + V_85 ) ;
F_37 ( V_4 -> V_88 ) ;
}
static void
F_40 ( struct V_1 * V_2 , struct V_94 * V_95 ,
struct V_94 * V_96 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_84 , V_97 ;
unsigned long V_83 ;
unsigned int V_98 , V_99 ;
V_98 = F_41 ( V_2 , V_95 , V_96 , 0 , V_4 -> V_2 . V_90 / 16 ) ;
V_99 = F_42 ( V_2 , V_98 ) ;
switch ( V_95 -> V_100 & V_101 ) {
case V_102 :
V_84 = V_103 ;
break;
case V_104 :
V_84 = V_105 ;
break;
case V_106 :
V_84 = V_107 ;
break;
default:
V_84 = V_108 ;
break;
}
if ( V_95 -> V_100 & V_109 )
V_84 |= V_110 ;
if ( V_95 -> V_100 & V_111 ) {
V_84 |= V_112 ;
if ( ! ( V_95 -> V_100 & V_113 ) )
V_84 |= V_114 ;
}
if ( V_4 -> V_2 . V_48 > 1 )
V_84 |= V_93 ;
F_31 ( & V_4 -> V_2 . V_42 , V_83 ) ;
F_43 ( V_2 , V_95 -> V_100 , V_98 ) ;
V_4 -> V_2 . V_38 = V_36 ;
if ( V_95 -> V_115 & V_116 )
V_4 -> V_2 . V_38 |= V_30 | V_31 ;
if ( V_95 -> V_115 & ( V_117 | V_118 ) )
V_4 -> V_2 . V_38 |= V_29 ;
V_4 -> V_2 . V_119 = 0 ;
if ( V_95 -> V_115 & V_120 )
V_4 -> V_2 . V_119 |= V_30 | V_31 ;
if ( V_95 -> V_115 & V_121 ) {
V_4 -> V_2 . V_119 |= V_29 ;
if ( V_95 -> V_115 & V_120 )
V_4 -> V_2 . V_119 |= V_36 ;
}
if ( ( V_95 -> V_100 & V_122 ) == 0 )
V_4 -> V_2 . V_119 |= V_26 ;
V_97 = F_2 ( V_4 -> V_2 . V_6 + V_7 ) & ~ V_11 ;
if ( F_44 ( V_2 , V_95 -> V_100 ) )
V_97 |= V_11 ;
F_3 ( 0 , V_4 -> V_2 . V_6 + V_7 ) ;
V_99 -= 1 ;
F_3 ( ( V_99 & 0xf00 ) >> 8 , V_4 -> V_2 . V_6 + V_123 ) ;
F_3 ( V_99 & 0xff , V_4 -> V_2 . V_6 + V_124 ) ;
F_3 ( V_84 , V_4 -> V_2 . V_6 + V_85 ) ;
F_3 ( V_97 , V_4 -> V_2 . V_6 + V_7 ) ;
F_32 ( & V_4 -> V_2 . V_42 , V_83 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_125 )
{
if ( V_125 == V_126 ) {
V_2 -> V_83 |= V_127 ;
F_6 ( V_2 ) ;
} else
V_2 -> V_83 &= ~ V_127 ;
}
static const char * F_46 ( struct V_1 * V_2 )
{
return V_2 -> type == V_128 ? L_2 : NULL ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_129 , V_130 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
return F_50 ( V_2 -> V_129 , V_130 , L_1 )
!= NULL ? 0 : - V_131 ;
}
static void F_51 ( struct V_1 * V_2 , int V_83 )
{
if ( V_83 & V_132 ) {
V_2 -> type = V_128 ;
F_49 ( V_2 ) ;
}
}
static int F_52 ( struct V_1 * V_2 , struct V_133 * V_134 )
{
int V_135 = 0 ;
if ( V_134 -> type != V_136 && V_134 -> type != V_128 )
V_135 = - V_137 ;
if ( V_134 -> V_62 < 0 || V_134 -> V_62 >= V_138 )
V_135 = - V_137 ;
if ( V_134 -> V_139 < 9600 )
V_135 = - V_137 ;
return V_135 ;
}
static void F_53 ( struct V_1 * V_2 , int V_16 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_15 ;
do {
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) ;
F_54 () ;
} while ( ! F_55 ( V_15 ) );
F_3 ( V_16 , V_4 -> V_2 . V_6 + V_21 ) ;
}
static void
F_56 ( struct V_140 * V_141 , const char * V_142 , unsigned int V_45 )
{
struct V_3 * V_4 = V_143 [ V_141 -> V_144 ] ;
unsigned int V_15 , V_97 ;
F_57 ( V_4 -> V_88 ) ;
V_97 = F_2 ( V_4 -> V_2 . V_6 + V_7 ) ;
F_3 ( V_92 , V_4 -> V_2 . V_6 + V_7 ) ;
F_58 ( & V_4 -> V_2 , V_142 , V_45 , F_53 ) ;
do {
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_20 ) ;
F_54 () ;
} while ( V_15 & V_72 );
F_3 ( V_97 , V_4 -> V_2 . V_6 + V_7 ) ;
F_59 ( V_4 -> V_88 ) ;
}
static void T_2
F_60 ( struct V_3 * V_4 , int * V_98 ,
int * V_34 , int * V_145 )
{
if ( F_2 ( V_4 -> V_2 . V_6 + V_7 ) & V_92 ) {
unsigned int V_84 , V_99 ;
V_84 = F_2 ( V_4 -> V_2 . V_6 + V_85 ) ;
* V_34 = 'n' ;
if ( V_84 & V_112 ) {
if ( V_84 & V_114 )
* V_34 = 'e' ;
else
* V_34 = 'o' ;
}
if ( ( V_84 & 0x60 ) == V_107 )
* V_145 = 7 ;
else
* V_145 = 8 ;
V_99 = F_2 ( V_4 -> V_2 . V_6 + V_124 ) |
F_2 ( V_4 -> V_2 . V_6 + V_123 ) << 8 ;
* V_98 = V_4 -> V_2 . V_90 / ( 16 * ( V_99 + 1 ) ) ;
}
}
static int T_2 F_61 ( struct V_140 * V_141 , char * V_146 )
{
struct V_3 * V_4 ;
int V_98 = 38400 ;
int V_145 = 8 ;
int V_34 = 'n' ;
int V_147 = 'n' ;
int V_135 ;
if ( V_141 -> V_144 >= V_148 )
V_141 -> V_144 = 0 ;
V_4 = V_143 [ V_141 -> V_144 ] ;
if ( ! V_4 )
return - V_149 ;
V_135 = F_62 ( V_4 -> V_88 ) ;
if ( V_135 )
return V_135 ;
V_4 -> V_2 . V_90 = F_35 ( V_4 -> V_88 ) ;
if ( V_146 )
F_63 ( V_146 , & V_98 , & V_34 , & V_145 , & V_147 ) ;
else
F_60 ( V_4 , & V_98 , & V_34 , & V_145 ) ;
return F_64 ( & V_4 -> V_2 , V_141 , V_98 , V_34 , V_145 , V_147 ) ;
}
static int F_65 ( struct V_150 * V_81 , const struct V_151 * V_152 )
{
struct V_3 * V_4 ;
void T_3 * V_153 ;
int V_154 , V_135 ;
for ( V_154 = 0 ; V_154 < F_66 ( V_143 ) ; V_154 ++ )
if ( V_143 [ V_154 ] == NULL )
break;
if ( V_154 == F_66 ( V_143 ) ) {
V_135 = - V_131 ;
goto V_89;
}
V_4 = F_67 ( sizeof( struct V_3 ) , V_155 ) ;
if ( ! V_4 ) {
V_135 = - V_156 ;
goto V_89;
}
V_153 = F_68 ( V_81 -> V_157 . V_158 , F_69 ( & V_81 -> V_157 ) ) ;
if ( ! V_153 ) {
V_135 = - V_156 ;
goto free;
}
V_4 -> V_88 = F_70 ( & V_81 -> V_81 , NULL ) ;
if ( F_71 ( V_4 -> V_88 ) ) {
V_135 = F_72 ( V_4 -> V_88 ) ;
goto V_159;
}
V_4 -> V_2 . V_81 = & V_81 -> V_81 ;
V_4 -> V_2 . V_129 = V_81 -> V_157 . V_158 ;
V_4 -> V_2 . V_6 = V_153 ;
V_4 -> V_2 . V_160 = V_161 ;
V_4 -> V_2 . V_62 = V_81 -> V_62 [ 0 ] ;
V_4 -> V_2 . V_48 = 16 ;
V_4 -> V_2 . V_162 = & V_163 ;
V_4 -> V_2 . V_83 = V_164 ;
V_4 -> V_2 . line = V_154 ;
V_4 -> V_81 = V_81 ;
V_4 -> V_79 = V_81 -> V_81 . V_165 ;
V_143 [ V_154 ] = V_4 ;
F_73 ( V_81 , V_4 ) ;
V_135 = F_74 ( & V_166 , & V_4 -> V_2 ) ;
if ( V_135 ) {
F_73 ( V_81 , NULL ) ;
V_143 [ V_154 ] = NULL ;
F_75 ( V_4 -> V_88 ) ;
V_159:
F_76 ( V_153 ) ;
free:
F_77 ( V_4 ) ;
}
V_89:
return V_135 ;
}
static int F_78 ( struct V_150 * V_81 )
{
struct V_3 * V_4 = F_79 ( V_81 ) ;
int V_154 ;
F_73 ( V_81 , NULL ) ;
F_80 ( & V_166 , & V_4 -> V_2 ) ;
for ( V_154 = 0 ; V_154 < F_66 ( V_143 ) ; V_154 ++ )
if ( V_143 [ V_154 ] == V_4 )
V_143 [ V_154 ] = NULL ;
F_76 ( V_4 -> V_2 . V_6 ) ;
F_75 ( V_4 -> V_88 ) ;
F_77 ( V_4 ) ;
return 0 ;
}
static int F_81 ( struct V_150 * V_81 , T_4 V_14 )
{
struct V_3 * V_4 = F_79 ( V_81 ) ;
if ( V_4 )
F_82 ( & V_166 , & V_4 -> V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_150 * V_81 )
{
struct V_3 * V_4 = F_79 ( V_81 ) ;
if ( V_4 )
F_84 ( & V_166 , & V_4 -> V_2 ) ;
return 0 ;
}
static int T_2 F_85 ( void )
{
int V_135 ;
F_86 ( V_167 L_3 ) ;
V_135 = F_87 ( & V_166 ) ;
if ( V_135 == 0 ) {
V_135 = F_88 ( & V_168 ) ;
if ( V_135 )
F_89 ( & V_166 ) ;
}
return V_135 ;
}
static void T_5 F_90 ( void )
{
F_91 ( & V_168 ) ;
F_89 ( & V_166 ) ;
}

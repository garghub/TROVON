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
unsigned int V_12 , V_13 , V_14 , V_15 , V_16 = 256 ;
V_12 = F_2 ( V_4 -> V_2 . V_6 + V_17 ) ;
while ( F_8 ( V_12 ) && V_16 -- ) {
V_13 = F_2 ( V_4 -> V_2 . V_6 + V_18 ) ;
V_14 = V_19 ;
V_4 -> V_2 . V_20 . V_21 ++ ;
V_15 = F_2 ( V_4 -> V_2 . V_6 + V_22 ) | V_23 ;
if ( F_9 ( V_15 & V_24 ) ) {
F_3 ( 0 , V_4 -> V_2 . V_6 + V_25 ) ;
if ( V_15 & V_26 ) {
V_15 &= ~ ( V_27 | V_28 ) ;
V_4 -> V_2 . V_20 . V_29 ++ ;
if ( F_10 ( & V_4 -> V_2 ) )
goto V_30;
} else if ( V_15 & V_28 )
V_4 -> V_2 . V_20 . V_31 ++ ;
else if ( V_15 & V_27 )
V_4 -> V_2 . V_20 . V_32 ++ ;
if ( V_15 & V_33 )
V_4 -> V_2 . V_20 . V_34 ++ ;
V_15 &= V_4 -> V_2 . V_35 ;
if ( V_15 & V_26 )
V_14 = V_36 ;
else if ( V_15 & V_28 )
V_14 = V_37 ;
else if ( V_15 & V_27 )
V_14 = V_38 ;
}
if ( F_11 ( & V_4 -> V_2 , V_13 ) )
goto V_30;
F_12 ( & V_4 -> V_2 , V_15 , V_33 , V_13 , V_14 ) ;
V_30:
V_12 = F_2 ( V_4 -> V_2 . V_6 + V_17 ) ;
}
F_13 ( & V_4 -> V_2 . V_39 ) ;
F_14 ( & V_4 -> V_2 . V_40 -> V_2 ) ;
F_15 ( & V_4 -> V_2 . V_39 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
struct V_41 * V_42 = & V_4 -> V_2 . V_40 -> V_42 ;
int V_43 ;
if ( V_4 -> V_2 . V_44 ) {
F_3 ( V_4 -> V_2 . V_44 , V_4 -> V_2 . V_6 + V_18 ) ;
V_4 -> V_2 . V_20 . V_45 ++ ;
V_4 -> V_2 . V_44 = 0 ;
return;
}
if ( F_17 ( V_42 ) || F_18 ( & V_4 -> V_2 ) ) {
F_1 ( & V_4 -> V_2 ) ;
return;
}
V_43 = V_4 -> V_2 . V_46 >> 1 ;
do {
F_3 ( V_42 -> V_47 [ V_42 -> V_48 ] , V_4 -> V_2 . V_6 + V_18 ) ;
V_42 -> V_48 = ( V_42 -> V_48 + 1 ) & ( V_49 - 1 ) ;
V_4 -> V_2 . V_20 . V_45 ++ ;
if ( F_17 ( V_42 ) )
break;
} while ( -- V_43 > 0 );
if ( F_19 ( V_42 ) < V_50 )
F_20 ( & V_4 -> V_2 ) ;
if ( F_17 ( V_42 ) )
F_1 ( & V_4 -> V_2 ) ;
}
static void F_21 ( struct V_3 * V_4 )
{
unsigned int V_12 , V_51 ;
F_3 ( 0 , V_4 -> V_2 . V_6 + V_52 ) ;
V_12 = F_2 ( V_4 -> V_2 . V_6 + V_17 ) & V_53 ;
V_51 = V_12 ^ V_4 -> V_54 ;
V_4 -> V_54 = V_12 ;
if ( ! V_51 )
return;
if ( V_51 & V_55 )
F_22 ( & V_4 -> V_2 , V_12 & V_55 ) ;
if ( V_51 & V_56 )
V_4 -> V_2 . V_20 . V_57 ++ ;
if ( V_51 & V_58 )
F_23 ( & V_4 -> V_2 , V_12 & V_58 ) ;
F_24 ( & V_4 -> V_2 . V_40 -> V_2 . V_59 ) ;
}
static T_1 F_25 ( int V_60 , void * V_61 )
{
struct V_3 * V_4 = V_61 ;
unsigned int V_12 , V_62 = V_63 ;
int V_64 = 0 ;
F_15 ( & V_4 -> V_2 . V_39 ) ;
V_12 = F_2 ( V_4 -> V_2 . V_6 + V_65 ) ;
if ( V_12 ) {
do {
if ( V_12 & ( V_66 | V_67 ) )
F_7 ( V_4 ) ;
if ( V_12 & V_68 )
F_21 ( V_4 ) ;
if ( V_12 & V_69 )
F_16 ( V_4 ) ;
if ( V_62 -- == 0 )
break;
V_12 = F_2 ( V_4 -> V_2 . V_6 + V_65 ) ;
} while ( V_12 & ( V_66 | V_67 |
V_69 ) );
V_64 = 1 ;
}
F_13 ( & V_4 -> V_2 . V_39 ) ;
return F_26 ( V_64 ) ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_12 = F_2 ( V_4 -> V_2 . V_6 + V_17 ) ;
return V_12 & V_70 ? 0 : V_71 ;
}
static unsigned int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_72 = 0 ;
unsigned int V_12 ;
V_12 = F_2 ( V_4 -> V_2 . V_6 + V_17 ) ;
if ( V_12 & V_55 )
V_72 |= V_73 ;
if ( V_12 & V_56 )
V_72 |= V_74 ;
if ( V_12 & V_58 )
V_72 |= V_75 ;
return V_72 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_76 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_4 -> V_77 )
V_4 -> V_77 -> V_78 ( V_4 -> V_79 , V_4 -> V_2 . V_6 , V_76 ) ;
}
static void F_30 ( struct V_1 * V_2 , int V_80 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned long V_81 ;
unsigned int V_82 ;
F_31 ( & V_4 -> V_2 . V_39 , V_81 ) ;
V_82 = F_2 ( V_4 -> V_2 . V_6 + V_83 ) ;
if ( V_80 == - 1 )
V_82 |= V_84 ;
else
V_82 &= ~ V_84 ;
F_3 ( V_82 , V_4 -> V_2 . V_6 + V_83 ) ;
F_32 ( & V_4 -> V_2 . V_39 , V_81 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
int V_85 ;
V_85 = F_34 ( V_4 -> V_86 ) ;
if ( V_85 )
goto V_87;
V_4 -> V_2 . V_88 = F_35 ( V_4 -> V_86 ) ;
V_85 = F_36 ( V_4 -> V_2 . V_60 , F_25 , 0 , L_1 , V_4 ) ;
if ( V_85 )
goto V_89;
V_4 -> V_54 = F_2 ( V_4 -> V_2 . V_6 + V_17 ) & V_53 ;
F_3 ( V_90 | V_9 | V_10 ,
V_4 -> V_2 . V_6 + V_7 ) ;
return 0 ;
V_89:
F_37 ( V_4 -> V_86 ) ;
V_87:
return V_85 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_39 ( V_4 -> V_2 . V_60 , V_4 ) ;
F_3 ( 0 , V_4 -> V_2 . V_6 + V_7 ) ;
F_3 ( F_2 ( V_4 -> V_2 . V_6 + V_83 ) &
~ ( V_84 | V_91 ) ,
V_4 -> V_2 . V_6 + V_83 ) ;
F_37 ( V_4 -> V_86 ) ;
}
static void
F_40 ( struct V_1 * V_2 , struct V_92 * V_93 ,
struct V_92 * V_94 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_82 , V_95 ;
unsigned long V_81 ;
unsigned int V_96 , V_97 ;
V_96 = F_41 ( V_2 , V_93 , V_94 , 0 , V_4 -> V_2 . V_88 / 16 ) ;
V_97 = F_42 ( V_2 , V_96 ) ;
switch ( V_93 -> V_98 & V_99 ) {
case V_100 :
V_82 = V_101 ;
break;
case V_102 :
V_82 = V_103 ;
break;
case V_104 :
V_82 = V_105 ;
break;
default:
V_82 = V_106 ;
break;
}
if ( V_93 -> V_98 & V_107 )
V_82 |= V_108 ;
if ( V_93 -> V_98 & V_109 ) {
V_82 |= V_110 ;
if ( ! ( V_93 -> V_98 & V_111 ) )
V_82 |= V_112 ;
}
if ( V_4 -> V_2 . V_46 > 1 )
V_82 |= V_91 ;
F_31 ( & V_4 -> V_2 . V_39 , V_81 ) ;
F_43 ( V_2 , V_93 -> V_98 , V_96 ) ;
V_4 -> V_2 . V_35 = V_33 ;
if ( V_93 -> V_113 & V_114 )
V_4 -> V_2 . V_35 |= V_27 | V_28 ;
if ( V_93 -> V_113 & ( V_115 | V_116 ) )
V_4 -> V_2 . V_35 |= V_26 ;
V_4 -> V_2 . V_117 = 0 ;
if ( V_93 -> V_113 & V_118 )
V_4 -> V_2 . V_117 |= V_27 | V_28 ;
if ( V_93 -> V_113 & V_119 ) {
V_4 -> V_2 . V_117 |= V_26 ;
if ( V_93 -> V_113 & V_118 )
V_4 -> V_2 . V_117 |= V_33 ;
}
if ( ( V_93 -> V_98 & V_120 ) == 0 )
V_4 -> V_2 . V_117 |= V_23 ;
V_95 = F_2 ( V_4 -> V_2 . V_6 + V_7 ) & ~ V_11 ;
if ( F_44 ( V_2 , V_93 -> V_98 ) )
V_95 |= V_11 ;
F_3 ( 0 , V_4 -> V_2 . V_6 + V_7 ) ;
V_97 -= 1 ;
F_3 ( ( V_97 & 0xf00 ) >> 8 , V_4 -> V_2 . V_6 + V_121 ) ;
F_3 ( V_97 & 0xff , V_4 -> V_2 . V_6 + V_122 ) ;
F_3 ( V_82 , V_4 -> V_2 . V_6 + V_83 ) ;
F_3 ( V_95 , V_4 -> V_2 . V_6 + V_7 ) ;
F_32 ( & V_4 -> V_2 . V_39 , V_81 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_123 )
{
if ( V_123 == V_124 ) {
V_2 -> V_81 |= V_125 ;
F_6 ( V_2 ) ;
} else
V_2 -> V_81 &= ~ V_125 ;
}
static const char * F_46 ( struct V_1 * V_2 )
{
return V_2 -> type == V_126 ? L_2 : NULL ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 -> V_127 , V_128 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
return F_50 ( V_2 -> V_127 , V_128 , L_1 )
!= NULL ? 0 : - V_129 ;
}
static void F_51 ( struct V_1 * V_2 , int V_81 )
{
if ( V_81 & V_130 ) {
V_2 -> type = V_126 ;
F_49 ( V_2 ) ;
}
}
static int F_52 ( struct V_1 * V_2 , struct V_131 * V_132 )
{
int V_133 = 0 ;
if ( V_132 -> type != V_134 && V_132 -> type != V_126 )
V_133 = - V_135 ;
if ( V_132 -> V_60 < 0 || V_132 -> V_60 >= V_136 )
V_133 = - V_135 ;
if ( V_132 -> V_137 < 9600 )
V_133 = - V_135 ;
return V_133 ;
}
static void F_53 ( struct V_1 * V_2 , int V_13 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
unsigned int V_12 ;
do {
V_12 = F_2 ( V_4 -> V_2 . V_6 + V_17 ) ;
F_54 () ;
} while ( ! F_55 ( V_12 ) );
F_3 ( V_13 , V_4 -> V_2 . V_6 + V_18 ) ;
}
static void
F_56 ( struct V_138 * V_139 , const char * V_140 , unsigned int V_43 )
{
struct V_3 * V_4 = V_141 [ V_139 -> V_142 ] ;
unsigned int V_12 , V_95 ;
F_57 ( V_4 -> V_86 ) ;
V_95 = F_2 ( V_4 -> V_2 . V_6 + V_7 ) ;
F_3 ( V_90 , V_4 -> V_2 . V_6 + V_7 ) ;
F_58 ( & V_4 -> V_2 , V_140 , V_43 , F_53 ) ;
do {
V_12 = F_2 ( V_4 -> V_2 . V_6 + V_17 ) ;
F_54 () ;
} while ( V_12 & V_70 );
F_3 ( V_95 , V_4 -> V_2 . V_6 + V_7 ) ;
F_59 ( V_4 -> V_86 ) ;
}
static void T_2
F_60 ( struct V_3 * V_4 , int * V_96 ,
int * V_31 , int * V_143 )
{
if ( F_2 ( V_4 -> V_2 . V_6 + V_7 ) & V_90 ) {
unsigned int V_82 , V_97 ;
V_82 = F_2 ( V_4 -> V_2 . V_6 + V_83 ) ;
* V_31 = 'n' ;
if ( V_82 & V_110 ) {
if ( V_82 & V_112 )
* V_31 = 'e' ;
else
* V_31 = 'o' ;
}
if ( ( V_82 & 0x60 ) == V_105 )
* V_143 = 7 ;
else
* V_143 = 8 ;
V_97 = F_2 ( V_4 -> V_2 . V_6 + V_122 ) |
F_2 ( V_4 -> V_2 . V_6 + V_121 ) << 8 ;
* V_96 = V_4 -> V_2 . V_88 / ( 16 * ( V_97 + 1 ) ) ;
}
}
static int T_2 F_61 ( struct V_138 * V_139 , char * V_144 )
{
struct V_3 * V_4 ;
int V_96 = 38400 ;
int V_143 = 8 ;
int V_31 = 'n' ;
int V_145 = 'n' ;
int V_133 ;
if ( V_139 -> V_142 >= V_146 )
V_139 -> V_142 = 0 ;
V_4 = V_141 [ V_139 -> V_142 ] ;
if ( ! V_4 )
return - V_147 ;
V_133 = F_62 ( V_4 -> V_86 ) ;
if ( V_133 )
return V_133 ;
V_4 -> V_2 . V_88 = F_35 ( V_4 -> V_86 ) ;
if ( V_144 )
F_63 ( V_144 , & V_96 , & V_31 , & V_143 , & V_145 ) ;
else
F_60 ( V_4 , & V_96 , & V_31 , & V_143 ) ;
return F_64 ( & V_4 -> V_2 , V_139 , V_96 , V_31 , V_143 , V_145 ) ;
}
static int F_65 ( struct V_148 * V_79 , const struct V_149 * V_150 )
{
struct V_3 * V_4 ;
void T_3 * V_151 ;
int V_152 , V_133 ;
for ( V_152 = 0 ; V_152 < F_66 ( V_141 ) ; V_152 ++ )
if ( V_141 [ V_152 ] == NULL )
break;
if ( V_152 == F_66 ( V_141 ) ) {
V_133 = - V_129 ;
goto V_87;
}
V_4 = F_67 ( sizeof( struct V_3 ) , V_153 ) ;
if ( ! V_4 ) {
V_133 = - V_154 ;
goto V_87;
}
V_151 = F_68 ( V_79 -> V_155 . V_156 , F_69 ( & V_79 -> V_155 ) ) ;
if ( ! V_151 ) {
V_133 = - V_154 ;
goto free;
}
V_4 -> V_86 = F_70 ( & V_79 -> V_79 , NULL ) ;
if ( F_71 ( V_4 -> V_86 ) ) {
V_133 = F_72 ( V_4 -> V_86 ) ;
goto V_157;
}
V_4 -> V_2 . V_79 = & V_79 -> V_79 ;
V_4 -> V_2 . V_127 = V_79 -> V_155 . V_156 ;
V_4 -> V_2 . V_6 = V_151 ;
V_4 -> V_2 . V_158 = V_159 ;
V_4 -> V_2 . V_60 = V_79 -> V_60 [ 0 ] ;
V_4 -> V_2 . V_46 = 16 ;
V_4 -> V_2 . V_160 = & V_161 ;
V_4 -> V_2 . V_81 = V_162 ;
V_4 -> V_2 . line = V_152 ;
V_4 -> V_79 = V_79 ;
V_4 -> V_77 = F_73 ( & V_79 -> V_79 ) ;
V_141 [ V_152 ] = V_4 ;
F_74 ( V_79 , V_4 ) ;
V_133 = F_75 ( & V_163 , & V_4 -> V_2 ) ;
if ( V_133 ) {
F_74 ( V_79 , NULL ) ;
V_141 [ V_152 ] = NULL ;
F_76 ( V_4 -> V_86 ) ;
V_157:
F_77 ( V_151 ) ;
free:
F_78 ( V_4 ) ;
}
V_87:
return V_133 ;
}
static int F_79 ( struct V_148 * V_79 )
{
struct V_3 * V_4 = F_80 ( V_79 ) ;
int V_152 ;
F_74 ( V_79 , NULL ) ;
F_81 ( & V_163 , & V_4 -> V_2 ) ;
for ( V_152 = 0 ; V_152 < F_66 ( V_141 ) ; V_152 ++ )
if ( V_141 [ V_152 ] == V_4 )
V_141 [ V_152 ] = NULL ;
F_77 ( V_4 -> V_2 . V_6 ) ;
F_76 ( V_4 -> V_86 ) ;
F_78 ( V_4 ) ;
return 0 ;
}
static int F_82 ( struct V_148 * V_79 , T_4 V_40 )
{
struct V_3 * V_4 = F_80 ( V_79 ) ;
if ( V_4 )
F_83 ( & V_163 , & V_4 -> V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_148 * V_79 )
{
struct V_3 * V_4 = F_80 ( V_79 ) ;
if ( V_4 )
F_85 ( & V_163 , & V_4 -> V_2 ) ;
return 0 ;
}
static int T_2 F_86 ( void )
{
int V_133 ;
F_87 ( V_164 L_3 ) ;
V_133 = F_88 ( & V_163 ) ;
if ( V_133 == 0 ) {
V_133 = F_89 ( & V_165 ) ;
if ( V_133 )
F_90 ( & V_163 ) ;
}
return V_133 ;
}
static void T_5 F_91 ( void )
{
F_92 ( & V_165 ) ;
F_90 ( & V_163 ) ;
}

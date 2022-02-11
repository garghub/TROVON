static int F_1 ( int V_1 , T_1 V_2 )
{
int V_3 = F_2 ( V_4 -> V_5 , V_1 , V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( V_6 L_1 ) ;
return V_3 ;
}
return 0 ;
}
static int F_4 ( int V_1 )
{
int V_3 = F_5 ( V_4 -> V_5 , V_1 ) ;
if ( V_3 < 0 )
F_3 ( V_6 L_2 ) ;
return V_3 ;
}
static int F_6 ( int V_7 )
{
if ( V_7 > 7 ) {
V_7 -= 8 ;
V_4 -> V_8 &= ~ ( 1 << V_7 ) ;
return F_1 ( V_9 ,
V_4 -> V_8 ) ;
} else {
V_4 -> V_10 &= ~ ( 1 << V_7 ) ;
return F_1 ( V_11 ,
V_4 -> V_10 ) ;
}
}
static int F_7 ( int V_7 )
{
if ( V_7 > 7 ) {
V_7 -= 8 ;
V_4 -> V_8 |= ( 1 << V_7 ) ;
return F_1 ( V_9 ,
V_4 -> V_8 ) ;
} else {
V_4 -> V_10 |= ( 1 << V_7 ) ;
return F_1 ( V_11 ,
V_4 -> V_10 ) ;
}
}
static int F_8 ( int V_7 )
{
if ( V_7 > 7 )
return F_1 ( V_12 , 1 << ( V_7 - 8 ) ) ;
else
return F_1 ( V_13 , 1 << V_7 ) ;
}
static int F_9 ( int V_7 ,
void (* F_10)( struct V_14 * ) )
{
int V_15 = 0 ;
F_11 ( & V_4 -> V_16 ) ;
V_4 -> V_17 [ V_7 ] = F_10 ;
V_15 = F_6 ( V_7 ) ;
F_12 ( & V_4 -> V_16 ) ;
return V_15 ;
}
static int F_13 ( int V_7 )
{
int V_15 = 0 ;
F_11 ( & V_4 -> V_16 ) ;
V_15 = F_7 ( V_7 ) ;
V_4 -> V_17 [ V_7 ] = NULL ;
F_12 ( & V_4 -> V_16 ) ;
return V_15 ;
}
static void F_14 ( struct V_14 * V_18 )
{
int V_1 ;
unsigned char V_19 = 0 ;
V_1 = F_4 ( V_20 ) ;
if ( V_1 < 0 )
return;
if ( ! ( V_1 & 0x1 ) )
V_19 |= V_21 ;
if ( ! ( V_1 & 0x2 ) )
V_19 |= V_22 ;
if ( V_18 -> V_23 )
V_18 -> V_23 ( V_18 -> V_24 ,
V_19 ) ;
}
int F_15 ( int V_25 , int V_26 )
{
int V_15 , V_3 ;
if ( V_25 != 1 && V_25 != 2 )
return - V_27 ;
F_11 ( & V_4 -> V_16 ) ;
V_15 = F_4 ( V_28 ) ;
if ( V_15 < 0 ) {
F_12 ( & V_4 -> V_16 ) ;
return V_15 ;
}
V_3 = V_15 ;
if ( V_25 == 1 ) {
if ( V_26 )
V_3 |= V_29 ;
else
V_3 &= ~ V_29 ;
} else {
if ( V_26 )
V_3 |= V_30 ;
else
V_3 &= ~ V_30 ;
}
V_15 = F_1 ( V_28 , V_3 ) ;
F_12 ( & V_4 -> V_16 ) ;
return V_15 ;
}
int F_16 ( int V_26 )
{
int V_15 ;
F_11 ( & V_4 -> V_16 ) ;
V_15 = F_4 ( V_31 ) ;
if ( V_15 < 0 )
goto V_32;
V_15 |= V_33 ;
if ( V_26 )
V_15 |= V_34 ;
else
V_15 &= ~ V_34 ;
V_15 = F_1 ( V_31 , V_15 ) ;
V_32:
F_12 ( & V_4 -> V_16 ) ;
return V_15 ;
}
int F_17 ( int V_25 , int V_26 , int V_35 , int V_36 )
{
int V_15 , V_3 ;
if ( V_25 != 1 && V_25 != 2 )
return - V_27 ;
if ( V_35 >= 3 )
return - V_27 ;
F_11 ( & V_4 -> V_16 ) ;
V_15 = F_4 ( V_37 ) ;
if ( V_15 < 0 )
goto V_32;
V_3 = V_15 ;
if ( V_25 == 1 ) {
if ( V_36 )
V_3 |= V_38 | V_39 ;
else
V_3 &= ~ ( V_38 | V_39 ) ;
} else {
if ( V_36 )
V_3 |= V_40 | V_41 ;
else
V_3 &= ~ ( V_40 | V_41 ) ;
}
V_15 = F_1 ( V_37 , V_3 ) ;
if ( V_15 < 0 )
goto V_32;
V_15 = F_4 ( V_42 ) ;
if ( V_15 < 0 )
goto V_32;
V_3 = V_15 ;
if ( V_25 == 1 ) {
if ( V_26 )
V_3 |= V_43 ;
else
V_3 &= ~ V_43 ;
} else {
int V_44 ;
if ( V_26 )
V_3 |= V_45 ;
else
V_3 &= ~ V_45 ;
V_44 = F_4 ( V_37 ) ;
V_44 &= ~ ( V_46 | V_47 ) ;
V_44 |= V_35 ;
V_15 = F_1 ( V_37 , V_44 ) ;
if ( V_15 < 0 )
goto V_32;
}
V_3 &= ~ ( V_48 | V_49 ) ;
V_15 = F_1 ( V_42 , V_3 ) ;
V_32:
F_12 ( & V_4 -> V_16 ) ;
return V_15 ;
}
int F_18 ( void (* F_19)( void * V_50 , T_1 V_19 ) ,
void * V_50 )
{
int V_15 = 0 ;
V_4 -> V_24 = V_50 ;
V_4 -> V_23 = F_19 ;
V_15 = F_9 ( V_51 ,
F_14 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_9 ( V_52 ,
F_14 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_9 ( V_53 ,
F_14 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_9 ( V_54 ,
F_14 ) ;
return V_15 ;
}
void F_20 ( void )
{
F_13 ( V_51 ) ;
F_13 ( V_52 ) ;
F_13 ( V_53 ) ;
F_13 ( V_54 ) ;
V_4 -> V_23 = NULL ;
V_4 -> V_24 = NULL ;
}
static int F_21 ( const struct V_55 * V_56 , int V_57 ,
int V_58 , int V_59 )
{
int V_3 , V_15 ;
struct V_60 * V_61 = V_4 -> V_5 ;
F_11 ( & V_4 -> V_16 ) ;
V_15 = F_4 ( V_56 -> V_62 ) ;
if ( V_15 < 0 )
goto V_32;
V_3 = V_15 & ~ ( ( ( 1 << V_56 -> V_63 ) - 1 ) << V_56 -> V_64 ) ;
V_3 |= V_58 << V_56 -> V_64 ;
F_22 ( & V_61 -> V_65 , L_3
L_4 ,
V_56 -> V_66 , V_57 , V_56 -> V_62 , V_3 ) ;
V_15 = F_1 ( V_56 -> V_62 , V_3 ) ;
if ( V_15 < 0 )
goto V_32;
V_15 = F_1 ( V_56 -> V_67 , V_59 ) ;
V_32:
F_12 ( & V_4 -> V_16 ) ;
if ( V_15 == 0 ) {
F_23 ( 1 ) ;
}
return V_15 ;
}
static int F_24 ( int V_56 , const struct V_68 * V_69 ,
int V_70 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ , V_69 ++ )
if ( V_69 -> V_56 == V_56 )
return V_69 -> V_3 ;
return - V_27 ;
}
int F_25 ( unsigned int V_72 , unsigned int V_73 )
{
int V_74 , V_75 , V_3 , V_15 ;
struct V_60 * V_61 = V_4 -> V_5 ;
V_75 = F_24 ( V_72 , V_76 ,
F_26 ( V_76 ) ) ;
if ( V_75 < 0 )
return - V_27 ;
V_74 = F_24 ( V_73 , V_76 ,
F_26 ( V_76 ) ) ;
if ( V_74 < 0 )
return - V_27 ;
F_22 ( & V_61 -> V_65 , L_5 ,
V_73 , V_72 ) ;
F_11 ( & V_4 -> V_16 ) ;
V_15 = F_1 ( V_77 , V_74 ) ;
if ( V_15 < 0 )
goto V_32;
V_15 = F_1 ( V_78 , V_75 ) ;
if ( V_15 < 0 )
goto V_32;
if ( ! V_4 -> V_79 ) {
V_3 = F_4 ( V_80 ) ;
V_3 |= ( V_81 | V_82 ) ;
V_15 = F_1 ( V_80 , V_3 ) ;
V_4 -> V_79 = 1 ;
}
F_23 ( 1 ) ;
V_32:
F_12 ( & V_4 -> V_16 ) ;
return V_15 ;
}
int F_27 ( unsigned int V_57 )
{
int V_3 ;
if ( V_57 == 0 )
return F_21 ( & V_83 , 0 , 0 , 0 ) ;
V_3 = F_24 ( V_57 , V_84 , F_26 ( V_84 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
return F_21 ( & V_83 , V_57 , V_3 , 0x02 ) ;
}
int F_28 ( unsigned int V_57 )
{
int V_3 ;
if ( V_57 == 0 )
return F_21 ( & V_85 , 0 , 0 , 0 ) ;
V_3 = F_24 ( V_57 , V_86 , F_26 ( V_86 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
return F_21 ( & V_85 , V_57 , V_3 , 0x02 ) ;
}
int F_29 ( int V_87 , unsigned int V_57 )
{
const struct V_55 * V_56 ;
int V_3 ;
if ( V_87 != 2 && V_87 != 3 )
return - V_27 ;
if ( V_87 == 2 )
V_56 = & V_88 ;
else
V_56 = & V_89 ;
if ( V_57 == 0 )
return F_21 ( V_56 , 0 , 0 , 0 ) ;
V_3 = F_24 ( V_57 , V_90 ,
F_26 ( V_90 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
return F_21 ( V_56 , V_57 , V_3 , 0x03 ) ;
}
int F_30 ( unsigned int V_57 )
{
int V_3 ;
if ( V_57 == 0 )
return F_21 ( & V_91 , 0 , 0 , 0 ) ;
V_3 = F_24 ( V_57 , V_92 , F_26 ( V_92 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
return F_21 ( & V_91 , V_57 , V_3 , 0x02 ) ;
}
int F_31 ( unsigned int V_57 )
{
int V_3 ;
if ( V_57 == 0 )
return F_21 ( & V_93 , 0 , 0 , 0 ) ;
V_3 = F_24 ( V_57 , V_94 , F_26 ( V_94 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
return F_21 ( & V_93 , V_57 , V_3 , 0x02 ) ;
}
int F_32 ( void )
{
return F_4 ( V_20 ) ;
}
int F_33 ( int V_26 , T_2 V_3 )
{
int V_95 , V_15 ;
struct V_60 * V_61 = V_4 -> V_5 ;
F_11 ( & V_4 -> V_16 ) ;
V_15 = F_1 ( V_96 , V_3 ) ;
if ( V_15 < 0 )
goto V_32;
F_22 ( & V_61 -> V_65 , L_6 , V_3 ) ;
V_15 = F_4 ( V_31 ) ;
if ( V_15 < 0 )
goto V_32;
V_95 = ( V_97 | V_98 ) ;
if ( V_26 )
V_15 |= V_95 ;
else
V_15 &= ~ V_95 ;
V_15 = F_1 ( V_31 , V_15 ) ;
V_32:
F_12 ( & V_4 -> V_16 ) ;
return V_15 ;
}
static void F_34 ( struct V_99 * V_100 )
{
struct V_14 * V_101 =
F_35 ( V_100 , struct V_14 , V_102 ) ;
void (* F_10)( struct V_14 * V_101 );
while ( 1 ) {
unsigned V_103 ;
V_103 = ( F_4 ( V_104 )
& ~ V_101 -> V_8 ) << 8 ;
V_103 |= F_4 ( V_105 )
& ~ V_101 -> V_10 ;
if ( ! V_103 )
break;
while ( V_103 ) {
int V_7 = F_36 ( V_103 ) - 1 ;
V_103 &= ~ ( 1 << V_7 ) ;
F_11 ( & V_101 -> V_16 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
F_10 = V_101 -> V_17 [ V_7 ] ;
if ( F_10 )
F_10 ( V_101 ) ;
F_6 ( V_7 ) ;
F_12 ( & V_101 -> V_16 ) ;
}
}
F_37 ( V_101 -> V_5 -> V_7 ) ;
}
static T_3 F_38 ( int V_7 , void * V_100 )
{
struct V_14 * V_101 = V_100 ;
F_39 ( V_7 ) ;
( void ) F_40 ( & V_101 -> V_102 ) ;
return V_106 ;
}
static void F_41 ( char * V_107 , struct V_108 * V_95 )
{
V_95 -> V_109 = F_42 ( V_107 [ 0 ] ) ;
V_95 -> V_110 = F_42 ( V_107 [ 1 ] ) ;
if ( V_4 -> V_111 & V_112 ) {
V_95 -> V_113 = F_42 ( V_107 [ 2 ] & 0x1f ) - 1 ;
if ( V_107 [ 2 ] & V_114 )
V_95 -> V_113 += 12 ;
} else
V_95 -> V_113 = F_42 ( V_107 [ 2 ] & 0x3f ) ;
V_95 -> V_115 = F_42 ( V_107 [ 3 ] ) ;
V_95 -> V_116 = F_42 ( V_107 [ 4 ] ) - 1 ;
V_95 -> V_117 = F_42 ( V_107 [ 5 ] ) + 100 ;
}
static int F_43 ( struct V_108 * V_95 , int V_118 )
{
int V_119 , V_120 ;
V_120 = F_1 ( V_118 ++ , F_44 ( V_95 -> V_109 ) ) ;
if ( V_120 < 0 )
goto V_121;
V_120 = F_1 ( V_118 ++ , F_44 ( V_95 -> V_110 ) ) ;
if ( V_120 < 0 )
goto V_121;
if ( V_4 -> V_111 & V_112 ) {
V_119 = V_95 -> V_113 + 1 ;
if ( V_119 > 12 )
V_119 = V_114 | F_44 ( V_119 - 12 ) ;
else
V_119 = F_44 ( V_119 ) ;
} else
V_119 = F_44 ( V_95 -> V_113 ) ;
V_120 = F_1 ( V_118 ++ , V_119 ) ;
if ( V_120 < 0 )
goto V_121;
V_120 = F_1 ( V_118 ++ , F_44 ( V_95 -> V_115 ) ) ;
if ( V_120 < 0 )
goto V_121;
V_120 = F_1 ( V_118 ++ , F_44 ( V_95 -> V_116 + 1 ) ) ;
if ( V_120 < 0 )
goto V_121;
V_120 = F_1 ( V_118 ++ , F_44 ( V_95 -> V_117 - 100 ) ) ;
if ( V_120 < 0 )
goto V_121;
return 0 ;
V_121:
F_45 ( & V_4 -> V_5 -> V_65 , L_7 ,
-- V_118 , V_120 ) ;
return V_120 ;
}
static int F_46 ( struct V_122 * V_65 , struct V_108 * V_95 )
{
struct V_123 V_124 [ 2 ] ;
char V_107 [ 7 ] ;
int V_120 ;
V_107 [ 0 ] = V_125 ;
V_124 [ 0 ] . V_126 = V_127 ;
V_124 [ 0 ] . V_128 = 0 ;
V_124 [ 0 ] . V_129 = 1 ;
V_124 [ 0 ] . V_130 = V_107 ;
V_124 [ 1 ] . V_126 = V_127 ;
V_124 [ 1 ] . V_128 = V_131 ;
V_124 [ 1 ] . V_129 = sizeof( V_107 ) ;
V_124 [ 1 ] . V_130 = V_107 ;
V_120 = F_47 ( V_4 -> V_5 -> V_132 , V_124 , 2 ) ;
if ( V_120 != 2 ) {
F_45 ( V_65 , L_8 , L_9 , V_120 ) ;
return - V_133 ;
}
F_41 ( V_107 , V_95 ) ;
V_95 -> V_134 = F_42 ( V_107 [ 6 ] ) ;
return 0 ;
}
static int F_48 ( struct V_122 * V_65 , struct V_108 * V_95 )
{
int V_120 ;
V_120 = F_43 ( V_95 , V_125 ) ;
if ( V_120 < 0 )
return V_120 ;
V_120 = F_1 ( V_135 , F_44 ( V_95 -> V_134 ) ) ;
if ( V_120 < 0 ) {
F_45 ( & V_4 -> V_5 -> V_65 , L_10
L_11 , V_135 , V_120 ) ;
return V_120 ;
}
V_120 = F_1 ( V_136 , V_137 ) ;
if ( V_120 < 0 )
F_45 ( & V_4 -> V_5 -> V_65 , L_12 ,
V_120 ) ;
return 0 ;
}
static int F_49 ( struct V_122 * V_65 , struct V_138 * V_139 )
{
struct V_123 V_124 [ 2 ] ;
char V_107 [ 6 ] ;
int V_120 ;
V_107 [ 0 ] = V_140 ;
V_124 [ 0 ] . V_126 = V_127 ;
V_124 [ 0 ] . V_128 = 0 ;
V_124 [ 0 ] . V_129 = 1 ;
V_124 [ 0 ] . V_130 = V_107 ;
V_124 [ 1 ] . V_126 = V_127 ;
V_124 [ 1 ] . V_128 = V_131 ;
V_124 [ 1 ] . V_129 = sizeof( V_107 ) ;
V_124 [ 1 ] . V_130 = V_107 ;
V_120 = F_47 ( V_4 -> V_5 -> V_132 , V_124 , 2 ) ;
if ( V_120 != 2 ) {
F_45 ( V_65 , L_8 , L_13 , V_120 ) ;
return - V_133 ;
}
F_41 ( V_107 , & V_139 -> time ) ;
V_139 -> V_141 = ! ! ( V_4 -> V_111 & V_142 ) ;
V_139 -> V_143 = 0 ;
return 0 ;
}
static int F_50 ( struct V_122 * V_65 , struct V_138 * V_139 )
{
int V_120 ;
if ( V_4 -> V_5 -> V_7 <= 0 && V_139 -> V_141 )
return - V_144 ;
if ( V_4 -> V_111 & V_142 ) {
V_4 -> V_111 &= ~ V_142 ;
V_120 = F_1 ( V_145 ,
V_4 -> V_111 ) ;
if ( V_120 < 0 )
return V_120 ;
}
V_120 = F_43 ( & V_139 -> time , V_140 ) ;
if ( V_120 < 0 )
return V_120 ;
if ( V_139 -> V_141 ) {
V_4 -> V_111 |= V_142 ;
V_120 = F_1 ( V_145 ,
V_4 -> V_111 ) ;
}
return V_120 ;
}
static void F_51 ( struct V_14 * V_146 )
{
F_52 ( V_146 -> V_147 , 1 , V_148 | V_149 ) ;
}
static int F_53 ( struct V_122 * V_65 , unsigned V_150 , unsigned long V_151 )
{
int V_120 ;
if ( V_4 -> V_5 -> V_7 <= 0 )
return - V_152 ;
switch ( V_150 ) {
case V_153 :
if ( V_4 -> V_111 & V_142 )
return 0 ;
V_4 -> V_111 |= V_142 ;
break;
case V_154 :
if ( ! ( V_4 -> V_111 & V_142 ) )
return 0 ;
V_4 -> V_111 &= ~ V_142 ;
break;
case V_155 :
if ( V_4 -> V_156 )
return 0 ;
V_120 = F_13 ( V_157 ) ;
V_120 = F_9 ( V_157 ,
F_51 ) ;
if ( V_120 == 0 )
V_4 -> V_156 = 1 ;
return V_120 ;
case V_158 :
if ( ! V_4 -> V_156 )
return 0 ;
V_120 = F_13 ( V_157 ) ;
if ( V_120 == 0 )
V_4 -> V_156 = 0 ;
return V_120 ;
default:
return - V_152 ;
}
return F_1 ( V_145 , V_4 -> V_111 ) ;
}
static void F_54 ( struct V_14 * V_146 )
{
F_52 ( V_146 -> V_147 , 1 , V_148 | V_159 ) ;
V_4 -> V_111 &= ~ V_142 ;
F_1 ( V_145 , V_4 -> V_111 ) ;
}
static inline void F_55 ( struct V_14 * V_146 )
{
int V_160 = ( V_146 -> V_5 -> V_7 > 0 ) ;
if ( ! ( F_4 ( V_161 ) & 0x80 ) ) {
F_22 ( & V_146 -> V_5 -> V_65 , L_14 ) ;
return;
}
if ( V_160 ) {
if ( F_9 ( V_162 ,
F_54 ) < 0 ) {
F_45 ( & V_146 -> V_5 -> V_65 , L_15 ) ;
return;
}
F_56 ( & V_146 -> V_5 -> V_65 , 1 ) ;
}
V_146 -> V_111 = F_4 ( V_145 ) ;
if ( ! ( V_146 -> V_111 & V_163 )
|| ( V_146 -> V_111 & V_142 )
|| ( V_146 -> V_111 & V_164 ) ) {
if ( ! ( V_146 -> V_111 & V_163 ) ) {
F_57 ( & V_146 -> V_5 -> V_65 , L_16 ) ;
V_146 -> V_111 |= V_163 ;
}
V_146 -> V_111 &= ~ V_164 ;
V_146 -> V_111 &= ~ V_142 ;
F_1 ( V_145 , V_146 -> V_111 ) ;
}
V_146 -> V_147 = F_58 ( V_6 ,
& V_146 -> V_5 -> V_65 ,
& V_165 , V_166 ) ;
if ( F_59 ( V_146 -> V_147 ) ) {
if ( V_160 ) {
F_13 ( V_162 ) ;
F_56 ( & V_146 -> V_5 -> V_65 , 0 ) ;
}
F_45 ( & V_146 -> V_5 -> V_65 , L_17 ,
( int ) F_60 ( V_146 -> V_147 ) ) ;
V_4 -> V_147 = NULL ;
}
}
static inline void F_55 ( struct V_14 * V_146 )
{
}
static int F_61 ( struct V_60 * V_5 ,
const struct V_167 * V_168 )
{
struct V_14 * V_101 ;
int V_169 = 0 ;
int V_170 = 0 ;
struct V_171 * V_172 =
F_62 ( & V_5 -> V_65 ) ;
if ( V_4 ) {
F_22 ( & V_5 -> V_65 , L_18 ,
V_6 ) ;
return - V_144 ;
}
V_101 = F_63 ( & V_5 -> V_65 , sizeof( * V_101 ) , V_173 ) ;
if ( ! V_101 )
return - V_174 ;
F_64 ( V_5 , V_101 ) ;
V_4 = V_101 ;
V_101 -> V_5 = V_5 ;
V_169 = F_4 ( V_175 ) ;
if ( V_169 < 0 ) {
F_3 ( V_6 L_19 ) ;
return - V_144 ;
}
F_1 ( V_13 , 0xff ) ;
F_1 ( V_12 , 0xff ) ;
F_1 ( V_11 , 0xff ) ;
F_1 ( V_9 , 0xff ) ;
V_101 -> V_10 = 0xff ;
V_101 -> V_8 = 0xff ;
F_1 ( V_28 , 0x73 ) ;
if ( V_5 -> V_7 > 0 ) {
V_170 = F_65 ( V_5 -> V_7 , F_38 , 0 ,
V_6 , V_101 ) ;
if ( V_170 ) {
F_22 ( & V_5 -> V_65 , L_20 ,
V_5 -> V_7 , V_170 ) ;
return V_170 ;
}
}
F_66 ( & V_101 -> V_16 ) ;
F_67 ( & V_101 -> V_102 , F_34 ) ;
F_68 ( L_21 , V_169 >> 4 , V_169 & 0x0f ) ;
V_170 = F_4 ( V_80 ) ;
if ( V_170 < 0 )
goto V_121;
if ( V_170 & V_81 )
V_101 -> V_79 = 1 ;
else
V_101 -> V_79 = 0 ;
if ( V_172 != NULL && V_172 -> V_176 != NULL ) {
V_170 = V_172 -> V_176 ( & V_5 -> V_65 ) ;
if ( V_170 < 0 )
goto V_121;
}
F_55 ( V_101 ) ;
return 0 ;
V_121:
F_69 ( V_5 -> V_7 , V_101 ) ;
F_70 ( & V_101 -> V_102 ) ;
return V_170 ;
}
static int F_71 ( struct V_60 * V_5 )
{
struct V_14 * V_101 = F_72 ( V_5 ) ;
F_69 ( V_5 -> V_7 , V_101 ) ;
F_70 ( & V_101 -> V_102 ) ;
V_4 = NULL ;
return 0 ;
}

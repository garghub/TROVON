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
if ( ! V_56 )
goto V_62;
V_15 = F_4 ( V_56 -> V_63 ) ;
if ( V_15 < 0 )
goto V_32;
V_3 = V_15 & ~ ( ( ( 1 << V_56 -> V_64 ) - 1 ) << V_56 -> V_65 ) ;
V_3 |= V_58 << V_56 -> V_65 ;
F_22 ( & V_61 -> V_66 , L_3
L_4 ,
V_56 -> V_67 , V_57 , V_56 -> V_63 , V_3 ) ;
V_15 = F_1 ( V_56 -> V_63 , V_3 ) ;
if ( V_15 < 0 )
goto V_32;
V_62:
V_15 = F_1 ( V_56 -> V_68 , V_59 ) ;
V_32:
F_12 ( & V_4 -> V_16 ) ;
if ( V_15 == 0 ) {
F_23 ( 1 ) ;
}
return V_15 ;
}
static int F_24 ( int V_56 , const struct V_69 * V_70 ,
int V_71 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ , V_70 ++ )
if ( V_70 -> V_56 == V_56 )
return V_70 -> V_3 ;
return - V_27 ;
}
int F_25 ( unsigned int V_57 )
{
int V_3 , V_15 ;
struct V_60 * V_61 = V_4 -> V_5 ;
V_3 = F_24 ( V_57 , V_73 ,
F_26 ( V_73 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
F_22 ( & V_61 -> V_66 , L_5 , V_57 , V_3 ) ;
F_11 ( & V_4 -> V_16 ) ;
V_15 = F_1 ( V_74 , V_3 ) ;
if ( V_15 == 0 )
V_4 -> V_75 = 0 ;
F_12 ( & V_4 -> V_16 ) ;
F_23 ( 1 ) ;
return V_15 ;
}
int F_27 ( unsigned int V_76 , unsigned int V_77 )
{
int V_78 , V_79 , V_3 , V_15 ;
struct V_60 * V_61 = V_4 -> V_5 ;
V_79 = F_24 ( V_76 , V_73 ,
F_26 ( V_73 ) ) ;
if ( V_79 < 0 )
return - V_27 ;
V_78 = F_24 ( V_77 , V_73 ,
F_26 ( V_73 ) ) ;
if ( V_78 < 0 )
return - V_27 ;
F_22 ( & V_61 -> V_66 , L_6 ,
V_77 , V_76 ) ;
F_11 ( & V_4 -> V_16 ) ;
V_15 = F_1 ( V_80 , V_78 ) ;
if ( V_15 < 0 )
goto V_32;
V_15 = F_1 ( V_81 , V_79 ) ;
if ( V_15 < 0 )
goto V_32;
if ( ! V_4 -> V_75 ) {
V_3 = F_4 ( V_74 ) ;
V_3 |= ( V_82 | V_83 ) ;
V_15 = F_1 ( V_74 , V_3 ) ;
V_4 -> V_75 = 1 ;
}
F_23 ( 1 ) ;
V_32:
F_12 ( & V_4 -> V_16 ) ;
return V_15 ;
}
int F_28 ( unsigned int V_57 )
{
int V_3 ;
if ( V_57 == 0 )
return F_21 ( & V_84 , 0 , 0 , 0 ) ;
V_3 = F_24 ( V_57 , V_85 , F_26 ( V_85 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
return F_21 ( & V_84 , V_57 , V_3 , 0x02 ) ;
}
int F_29 ( unsigned int V_57 )
{
int V_3 ;
if ( V_57 == 0 )
return F_21 ( & V_86 , 0 , 0 , 0 ) ;
V_3 = F_24 ( V_57 , V_87 , F_26 ( V_87 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
return F_21 ( & V_86 , V_57 , V_3 , 0x02 ) ;
}
int F_30 ( int V_88 , unsigned int V_57 )
{
const struct V_55 * V_56 ;
int V_3 ;
if ( V_88 != 2 && V_88 != 3 )
return - V_27 ;
if ( V_88 == 2 )
V_56 = & V_89 ;
else
V_56 = & V_90 ;
if ( V_57 == 0 )
return F_21 ( V_56 , 0 , 0 , 0 ) ;
V_3 = F_24 ( V_57 , V_91 ,
F_26 ( V_91 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
return F_21 ( V_56 , V_57 , V_3 , 0x03 ) ;
}
int F_31 ( unsigned int V_57 )
{
int V_3 ;
if ( V_57 == 0 )
return F_21 ( & V_92 , 0 , 0 , 0 ) ;
V_3 = F_24 ( V_57 , V_93 , F_26 ( V_93 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
return F_21 ( & V_92 , V_57 , V_3 , 0x02 ) ;
}
int F_32 ( unsigned int V_57 )
{
int V_3 ;
if ( V_57 == 0 )
return F_21 ( & V_94 , 0 , 0 , 0 ) ;
V_3 = F_24 ( V_57 , V_95 , F_26 ( V_95 ) ) ;
if ( V_3 < 0 )
return - V_27 ;
return F_21 ( & V_94 , V_57 , V_3 , 0x02 ) ;
}
int F_33 ( void )
{
return F_4 ( V_20 ) ;
}
int F_34 ( int V_26 , T_2 V_3 )
{
int V_96 , V_15 ;
struct V_60 * V_61 = V_4 -> V_5 ;
F_11 ( & V_4 -> V_16 ) ;
V_15 = F_1 ( V_97 , V_3 ) ;
if ( V_15 < 0 )
goto V_32;
F_22 ( & V_61 -> V_66 , L_7 , V_3 ) ;
V_15 = F_4 ( V_31 ) ;
if ( V_15 < 0 )
goto V_32;
V_96 = ( V_98 | V_99 ) ;
if ( V_26 )
V_15 |= V_96 ;
else
V_15 &= ~ V_96 ;
V_15 = F_1 ( V_31 , V_15 ) ;
V_32:
F_12 ( & V_4 -> V_16 ) ;
return V_15 ;
}
static void F_35 ( struct V_100 * V_101 )
{
struct V_14 * V_102 =
F_36 ( V_101 , struct V_14 , V_103 ) ;
void (* F_10)( struct V_14 * V_102 );
while ( 1 ) {
unsigned V_104 ;
V_104 = ( F_4 ( V_105 )
& ~ V_102 -> V_8 ) << 8 ;
V_104 |= F_4 ( V_106 )
& ~ V_102 -> V_10 ;
if ( ! V_104 )
break;
while ( V_104 ) {
int V_7 = F_37 ( V_104 ) - 1 ;
V_104 &= ~ ( 1 << V_7 ) ;
F_11 ( & V_102 -> V_16 ) ;
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
F_10 = V_102 -> V_17 [ V_7 ] ;
if ( F_10 )
F_10 ( V_102 ) ;
F_6 ( V_7 ) ;
F_12 ( & V_102 -> V_16 ) ;
}
}
F_38 ( V_102 -> V_5 -> V_7 ) ;
}
static T_3 F_39 ( int V_7 , void * V_101 )
{
struct V_14 * V_102 = V_101 ;
F_40 ( V_7 ) ;
( void ) F_41 ( & V_102 -> V_103 ) ;
return V_107 ;
}
static void F_42 ( char * V_108 , struct V_109 * V_96 )
{
V_96 -> V_110 = F_43 ( V_108 [ 0 ] ) ;
V_96 -> V_111 = F_43 ( V_108 [ 1 ] ) ;
if ( V_4 -> V_112 & V_113 ) {
V_96 -> V_114 = F_43 ( V_108 [ 2 ] & 0x1f ) - 1 ;
if ( V_108 [ 2 ] & V_115 )
V_96 -> V_114 += 12 ;
} else
V_96 -> V_114 = F_43 ( V_108 [ 2 ] & 0x3f ) ;
V_96 -> V_116 = F_43 ( V_108 [ 3 ] ) ;
V_96 -> V_117 = F_43 ( V_108 [ 4 ] ) - 1 ;
V_96 -> V_118 = F_43 ( V_108 [ 5 ] ) + 100 ;
}
static int F_44 ( struct V_109 * V_96 , int V_119 )
{
int V_120 , V_121 ;
V_121 = F_1 ( V_119 ++ , F_45 ( V_96 -> V_110 ) ) ;
if ( V_121 < 0 )
goto V_122;
V_121 = F_1 ( V_119 ++ , F_45 ( V_96 -> V_111 ) ) ;
if ( V_121 < 0 )
goto V_122;
if ( V_4 -> V_112 & V_113 ) {
V_120 = V_96 -> V_114 + 1 ;
if ( V_120 > 12 )
V_120 = V_115 | F_45 ( V_120 - 12 ) ;
else
V_120 = F_45 ( V_120 ) ;
} else
V_120 = F_45 ( V_96 -> V_114 ) ;
V_121 = F_1 ( V_119 ++ , V_120 ) ;
if ( V_121 < 0 )
goto V_122;
V_121 = F_1 ( V_119 ++ , F_45 ( V_96 -> V_116 ) ) ;
if ( V_121 < 0 )
goto V_122;
V_121 = F_1 ( V_119 ++ , F_45 ( V_96 -> V_117 + 1 ) ) ;
if ( V_121 < 0 )
goto V_122;
V_121 = F_1 ( V_119 ++ , F_45 ( V_96 -> V_118 - 100 ) ) ;
if ( V_121 < 0 )
goto V_122;
return 0 ;
V_122:
F_46 ( & V_4 -> V_5 -> V_66 , L_8 ,
-- V_119 , V_121 ) ;
return V_121 ;
}
static int F_47 ( struct V_123 * V_66 , struct V_109 * V_96 )
{
struct V_124 V_125 [ 2 ] ;
char V_108 [ 7 ] ;
int V_121 ;
V_108 [ 0 ] = V_126 ;
V_125 [ 0 ] . V_127 = V_128 ;
V_125 [ 0 ] . V_129 = 0 ;
V_125 [ 0 ] . V_130 = 1 ;
V_125 [ 0 ] . V_131 = V_108 ;
V_125 [ 1 ] . V_127 = V_128 ;
V_125 [ 1 ] . V_129 = V_132 ;
V_125 [ 1 ] . V_130 = sizeof( V_108 ) ;
V_125 [ 1 ] . V_131 = V_108 ;
V_121 = F_48 ( V_4 -> V_5 -> V_133 , V_125 , 2 ) ;
if ( V_121 != 2 ) {
F_46 ( V_66 , L_9 , L_10 , V_121 ) ;
return - V_134 ;
}
F_42 ( V_108 , V_96 ) ;
V_96 -> V_135 = F_43 ( V_108 [ 6 ] ) ;
return 0 ;
}
static int F_49 ( struct V_123 * V_66 , struct V_109 * V_96 )
{
int V_121 ;
V_121 = F_44 ( V_96 , V_126 ) ;
if ( V_121 < 0 )
return V_121 ;
V_121 = F_1 ( V_136 , F_45 ( V_96 -> V_135 ) ) ;
if ( V_121 < 0 ) {
F_46 ( & V_4 -> V_5 -> V_66 , L_11
L_12 , V_136 , V_121 ) ;
return V_121 ;
}
V_121 = F_1 ( V_137 , V_138 ) ;
if ( V_121 < 0 )
F_46 ( & V_4 -> V_5 -> V_66 , L_13 ,
V_121 ) ;
return 0 ;
}
static int F_50 ( struct V_123 * V_66 , struct V_139 * V_140 )
{
struct V_124 V_125 [ 2 ] ;
char V_108 [ 6 ] ;
int V_121 ;
V_108 [ 0 ] = V_141 ;
V_125 [ 0 ] . V_127 = V_128 ;
V_125 [ 0 ] . V_129 = 0 ;
V_125 [ 0 ] . V_130 = 1 ;
V_125 [ 0 ] . V_131 = V_108 ;
V_125 [ 1 ] . V_127 = V_128 ;
V_125 [ 1 ] . V_129 = V_132 ;
V_125 [ 1 ] . V_130 = sizeof( V_108 ) ;
V_125 [ 1 ] . V_131 = V_108 ;
V_121 = F_48 ( V_4 -> V_5 -> V_133 , V_125 , 2 ) ;
if ( V_121 != 2 ) {
F_46 ( V_66 , L_9 , L_14 , V_121 ) ;
return - V_134 ;
}
F_42 ( V_108 , & V_140 -> time ) ;
V_140 -> V_142 = ! ! ( V_4 -> V_112 & V_143 ) ;
V_140 -> V_144 = 0 ;
return 0 ;
}
static int F_51 ( struct V_123 * V_66 , struct V_139 * V_140 )
{
int V_121 ;
if ( V_4 -> V_5 -> V_7 <= 0 && V_140 -> V_142 )
return - V_145 ;
if ( V_4 -> V_112 & V_143 ) {
V_4 -> V_112 &= ~ V_143 ;
V_121 = F_1 ( V_146 ,
V_4 -> V_112 ) ;
if ( V_121 < 0 )
return V_121 ;
}
V_121 = F_44 ( & V_140 -> time , V_141 ) ;
if ( V_121 < 0 )
return V_121 ;
if ( V_140 -> V_142 ) {
V_4 -> V_112 |= V_143 ;
V_121 = F_1 ( V_146 ,
V_4 -> V_112 ) ;
}
return V_121 ;
}
static void F_52 ( struct V_14 * V_147 )
{
F_53 () ;
F_54 ( V_147 -> V_148 , 1 , V_149 | V_150 ) ;
F_55 () ;
}
static int F_56 ( struct V_123 * V_66 , unsigned V_151 , unsigned long V_152 )
{
int V_121 ;
if ( V_4 -> V_5 -> V_7 <= 0 )
return - V_153 ;
switch ( V_151 ) {
case V_154 :
if ( V_4 -> V_112 & V_143 )
return 0 ;
V_4 -> V_112 |= V_143 ;
break;
case V_155 :
if ( ! ( V_4 -> V_112 & V_143 ) )
return 0 ;
V_4 -> V_112 &= ~ V_143 ;
break;
case V_156 :
if ( V_4 -> V_157 )
return 0 ;
V_121 = F_13 ( V_158 ) ;
V_121 = F_9 ( V_158 ,
F_52 ) ;
if ( V_121 == 0 )
V_4 -> V_157 = 1 ;
return V_121 ;
case V_159 :
if ( ! V_4 -> V_157 )
return 0 ;
V_121 = F_13 ( V_158 ) ;
if ( V_121 == 0 )
V_4 -> V_157 = 0 ;
return V_121 ;
default:
return - V_153 ;
}
return F_1 ( V_146 , V_4 -> V_112 ) ;
}
static void F_57 ( struct V_14 * V_147 )
{
F_53 () ;
F_54 ( V_147 -> V_148 , 1 , V_149 | V_160 ) ;
F_55 () ;
V_4 -> V_112 &= ~ V_143 ;
F_1 ( V_146 , V_4 -> V_112 ) ;
}
static inline void F_58 ( struct V_14 * V_147 )
{
int V_161 = ( V_147 -> V_5 -> V_7 > 0 ) ;
if ( ! ( F_4 ( V_162 ) & 0x80 ) ) {
F_22 ( & V_147 -> V_5 -> V_66 , L_15 ) ;
return;
}
if ( V_161 ) {
if ( F_9 ( V_163 ,
F_57 ) < 0 ) {
F_46 ( & V_147 -> V_5 -> V_66 , L_16 ) ;
return;
}
F_59 ( & V_147 -> V_5 -> V_66 , 1 ) ;
}
V_147 -> V_112 = F_4 ( V_146 ) ;
if ( ! ( V_147 -> V_112 & V_164 )
|| ( V_147 -> V_112 & V_143 )
|| ( V_147 -> V_112 & V_165 ) ) {
if ( ! ( V_147 -> V_112 & V_164 ) ) {
F_60 ( & V_147 -> V_5 -> V_66 , L_17 ) ;
V_147 -> V_112 |= V_164 ;
}
V_147 -> V_112 &= ~ V_165 ;
V_147 -> V_112 &= ~ V_143 ;
F_1 ( V_146 , V_147 -> V_112 ) ;
}
V_147 -> V_148 = F_61 ( V_6 ,
& V_147 -> V_5 -> V_66 ,
& V_166 , V_167 ) ;
if ( F_62 ( V_147 -> V_148 ) ) {
if ( V_161 ) {
F_13 ( V_163 ) ;
F_59 ( & V_147 -> V_5 -> V_66 , 0 ) ;
}
F_46 ( & V_147 -> V_5 -> V_66 , L_18 ,
( int ) F_63 ( V_147 -> V_148 ) ) ;
V_4 -> V_148 = NULL ;
}
}
static inline void F_58 ( struct V_14 * V_147 )
{
}
static int F_64 ( struct V_60 * V_5 ,
const struct V_168 * V_169 )
{
struct V_14 * V_102 ;
int V_170 = 0 , V_3 ;
int V_171 = 0 ;
struct V_172 * V_173 =
F_65 ( & V_5 -> V_66 ) ;
if ( V_4 ) {
F_22 ( & V_5 -> V_66 , L_19 ,
V_6 ) ;
return - V_145 ;
}
V_102 = F_66 ( & V_5 -> V_66 , sizeof( * V_102 ) , V_174 ) ;
if ( ! V_102 )
return - V_175 ;
F_67 ( V_5 , V_102 ) ;
V_4 = V_102 ;
V_102 -> V_5 = V_5 ;
V_170 = F_4 ( V_176 ) ;
if ( V_170 < 0 ) {
F_3 ( V_6 L_20 ) ;
return - V_145 ;
}
F_1 ( V_13 , 0xff ) ;
F_1 ( V_12 , 0xff ) ;
F_1 ( V_11 , 0xff ) ;
F_1 ( V_9 , 0xff ) ;
V_102 -> V_10 = 0xff ;
V_102 -> V_8 = 0xff ;
F_1 ( V_28 , 0x73 ) ;
if ( V_5 -> V_7 > 0 ) {
V_171 = F_68 ( V_5 -> V_7 , F_39 , 0 ,
V_6 , V_102 ) ;
if ( V_171 ) {
F_22 ( & V_5 -> V_66 , L_21 ,
V_5 -> V_7 , V_171 ) ;
return V_171 ;
}
}
F_69 ( & V_102 -> V_16 ) ;
F_70 ( & V_102 -> V_103 , F_35 ) ;
F_71 ( L_22 , V_170 >> 4 , V_170 & 0x0f ) ;
V_3 = F_4 ( V_74 ) ;
if ( V_3 < 0 )
goto V_122;
if ( V_3 & ( 1 << 7 ) )
V_102 -> V_75 = 1 ;
else
V_102 -> V_75 = 0 ;
if ( V_173 != NULL && V_173 -> V_177 != NULL ) {
V_171 = V_173 -> V_177 ( & V_5 -> V_66 ) ;
if ( V_171 < 0 )
goto V_122;
}
F_58 ( V_102 ) ;
return 0 ;
V_122:
F_72 ( V_5 -> V_7 , V_102 ) ;
F_73 ( & V_102 -> V_103 ) ;
return V_171 ;
}
static int T_4 F_74 ( struct V_60 * V_5 )
{
struct V_14 * V_102 = F_75 ( V_5 ) ;
F_72 ( V_5 -> V_7 , V_102 ) ;
F_73 ( & V_102 -> V_103 ) ;
V_4 = NULL ;
return 0 ;
}
static int T_5 F_76 ( void )
{
int V_178 ;
V_178 = F_77 ( & V_179 ) ;
if ( V_178 < 0 ) {
F_3 ( V_6 L_23 ) ;
return V_178 ;
}
return 0 ;
}
static void T_4 F_78 ( void )
{
F_79 ( & V_179 ) ;
}

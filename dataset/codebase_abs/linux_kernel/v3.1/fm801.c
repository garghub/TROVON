static int F_1 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned short V_4 , unsigned short V_5 )
{
int V_6 ;
unsigned long V_7 ;
unsigned short V_8 , V_9 ;
F_2 ( & V_2 -> V_10 , V_7 ) ;
V_8 = F_3 ( V_2 -> V_11 + V_3 ) ;
V_9 = ( V_8 & ~ V_4 ) | V_5 ;
V_6 = V_8 != V_9 ;
if ( V_6 )
F_4 ( V_9 , V_2 -> V_11 + V_3 ) ;
F_5 ( & V_2 -> V_10 , V_7 ) ;
return V_6 ;
}
static void F_6 ( struct V_12 * V_13 ,
unsigned short V_3 ,
unsigned short V_14 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( ! ( F_3 ( F_7 ( V_2 , V_17 ) ) & V_18 ) )
goto V_19;
F_8 ( 10 ) ;
}
F_9 ( V_20 L_1 ) ;
return;
V_19:
F_4 ( V_14 , F_7 ( V_2 , V_21 ) ) ;
F_4 ( V_3 | ( V_13 -> V_22 << V_23 ) , F_7 ( V_2 , V_17 ) ) ;
for ( V_16 = 0 ; V_16 < 1000 ; V_16 ++ ) {
if ( ! ( F_3 ( F_7 ( V_2 , V_17 ) ) & V_18 ) )
return;
F_8 ( 10 ) ;
}
F_9 ( V_20 L_2 , V_13 -> V_24 ) ;
}
static unsigned short F_10 ( struct V_12 * V_13 , unsigned short V_3 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( ! ( F_3 ( F_7 ( V_2 , V_17 ) ) & V_18 ) )
goto V_19;
F_8 ( 10 ) ;
}
F_9 ( V_20 L_1 ) ;
return 0 ;
V_19:
F_4 ( V_3 | ( V_13 -> V_22 << V_23 ) | V_25 ,
F_7 ( V_2 , V_17 ) ) ;
for ( V_16 = 0 ; V_16 < 100 ; V_16 ++ ) {
if ( ! ( F_3 ( F_7 ( V_2 , V_17 ) ) & V_18 ) )
goto V_26;
F_8 ( 10 ) ;
}
F_9 ( V_20 L_2 , V_13 -> V_24 ) ;
return 0 ;
V_26:
for ( V_16 = 0 ; V_16 < 1000 ; V_16 ++ ) {
if ( F_3 ( F_7 ( V_2 , V_17 ) ) & V_27 )
goto V_28;
F_8 ( 10 ) ;
}
F_9 ( V_20 L_3 , V_13 -> V_24 ) ;
return 0 ;
V_28:
return F_3 ( F_7 ( V_2 , V_21 ) ) ;
}
static unsigned short F_11 ( unsigned int V_29 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < F_12 ( V_30 ) ; V_16 ++ )
if ( V_30 [ V_16 ] == V_29 )
return V_16 ;
F_13 () ;
return F_12 ( V_30 ) - 1 ;
}
static int F_14 ( struct V_31 * V_32 ,
int V_33 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
F_16 ( & V_2 -> V_10 ) ;
switch ( V_33 ) {
case V_34 :
V_2 -> V_35 &= ~ ( V_36 |
V_37 |
V_38 ) ;
V_2 -> V_35 |= V_39 |
V_40 ;
break;
case V_41 :
V_2 -> V_35 &= ~ ( V_39 | V_38 ) ;
break;
case V_42 :
case V_43 :
V_2 -> V_35 |= V_38 ;
break;
case V_44 :
case V_45 :
V_2 -> V_35 &= ~ V_38 ;
break;
default:
F_17 ( & V_2 -> V_10 ) ;
F_13 () ;
return - V_46 ;
}
F_4 ( V_2 -> V_35 , F_7 ( V_2 , V_47 ) ) ;
F_17 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_18 ( struct V_31 * V_32 ,
int V_33 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
F_16 ( & V_2 -> V_10 ) ;
switch ( V_33 ) {
case V_34 :
V_2 -> V_48 &= ~ ( V_36 |
V_37 |
V_38 ) ;
V_2 -> V_48 |= V_39 |
V_40 ;
break;
case V_41 :
V_2 -> V_48 &= ~ ( V_39 | V_38 ) ;
break;
case V_42 :
case V_43 :
V_2 -> V_48 |= V_38 ;
break;
case V_44 :
case V_45 :
V_2 -> V_48 &= ~ V_38 ;
break;
default:
F_17 ( & V_2 -> V_10 ) ;
F_13 () ;
return - V_46 ;
}
F_4 ( V_2 -> V_48 , F_7 ( V_2 , V_49 ) ) ;
F_17 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_19 ( struct V_31 * V_32 ,
struct V_50 * V_51 )
{
return F_20 ( V_32 , F_21 ( V_51 ) ) ;
}
static int F_22 ( struct V_31 * V_32 )
{
return F_23 ( V_32 ) ;
}
static int F_24 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
struct V_52 * V_53 = V_32 -> V_53 ;
V_2 -> V_54 = F_25 ( V_32 ) ;
V_2 -> V_55 = F_26 ( V_32 ) ;
F_27 ( & V_2 -> V_10 ) ;
V_2 -> V_35 &= ~ ( V_39 | V_56 |
V_57 | V_58 |
V_59 ) ;
if ( F_28 ( V_53 -> V_60 ) == 16 )
V_2 -> V_35 |= V_56 ;
if ( V_53 -> V_61 > 1 ) {
V_2 -> V_35 |= V_57 ;
if ( V_53 -> V_61 == 4 )
V_2 -> V_35 |= V_62 ;
else if ( V_53 -> V_61 == 6 )
V_2 -> V_35 |= V_63 ;
}
V_2 -> V_35 |= F_11 ( V_53 -> V_29 ) << V_64 ;
V_2 -> V_65 = 0 ;
F_4 ( V_2 -> V_35 , F_7 ( V_2 , V_47 ) ) ;
F_4 ( V_2 -> V_55 - 1 , F_7 ( V_2 , V_66 ) ) ;
V_2 -> V_67 = V_53 -> V_68 ;
V_2 -> V_69 = 0 ;
F_29 ( V_2 -> V_67 , F_7 ( V_2 , V_70 ) ) ;
F_29 ( V_2 -> V_67 + ( V_2 -> V_55 % V_2 -> V_54 ) , F_7 ( V_2 , V_71 ) ) ;
F_30 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_31 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
struct V_52 * V_53 = V_32 -> V_53 ;
V_2 -> V_72 = F_25 ( V_32 ) ;
V_2 -> V_73 = F_26 ( V_32 ) ;
F_27 ( & V_2 -> V_10 ) ;
V_2 -> V_48 &= ~ ( V_39 | V_56 |
V_57 | V_58 ) ;
if ( F_28 ( V_53 -> V_60 ) == 16 )
V_2 -> V_48 |= V_56 ;
if ( V_53 -> V_61 > 1 )
V_2 -> V_48 |= V_57 ;
V_2 -> V_48 |= F_11 ( V_53 -> V_29 ) << V_64 ;
V_2 -> V_74 = 0 ;
F_4 ( V_2 -> V_48 , F_7 ( V_2 , V_49 ) ) ;
F_4 ( V_2 -> V_73 - 1 , F_7 ( V_2 , V_75 ) ) ;
V_2 -> V_76 = V_53 -> V_68 ;
V_2 -> V_77 = 0 ;
F_29 ( V_2 -> V_76 , F_7 ( V_2 , V_78 ) ) ;
F_29 ( V_2 -> V_76 + ( V_2 -> V_73 % V_2 -> V_72 ) , F_7 ( V_2 , V_79 ) ) ;
F_30 ( & V_2 -> V_10 ) ;
return 0 ;
}
static T_1 F_32 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
T_2 V_80 ;
if ( ! ( V_2 -> V_35 & V_39 ) )
return 0 ;
F_16 ( & V_2 -> V_10 ) ;
V_80 = V_2 -> V_69 + ( V_2 -> V_55 - 1 ) - F_3 ( F_7 ( V_2 , V_66 ) ) ;
if ( F_3 ( F_7 ( V_2 , V_81 ) ) & V_82 ) {
V_80 += V_2 -> V_55 ;
V_80 %= V_2 -> V_54 ;
}
F_17 ( & V_2 -> V_10 ) ;
return F_33 ( V_32 -> V_53 , V_80 ) ;
}
static T_1 F_34 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
T_2 V_80 ;
if ( ! ( V_2 -> V_48 & V_39 ) )
return 0 ;
F_16 ( & V_2 -> V_10 ) ;
V_80 = V_2 -> V_77 + ( V_2 -> V_73 - 1 ) - F_3 ( F_7 ( V_2 , V_75 ) ) ;
if ( F_3 ( F_7 ( V_2 , V_81 ) ) & V_83 ) {
V_80 += V_2 -> V_73 ;
V_80 %= V_2 -> V_72 ;
}
F_17 ( & V_2 -> V_10 ) ;
return F_33 ( V_32 -> V_53 , V_80 ) ;
}
static T_3 F_35 ( int V_84 , void * V_85 )
{
struct V_1 * V_2 = V_85 ;
unsigned short V_86 ;
unsigned int V_87 ;
V_86 = F_3 ( F_7 ( V_2 , V_81 ) ) ;
V_86 &= V_82 | V_83 | V_88 | V_89 ;
if ( ! V_86 )
return V_90 ;
F_4 ( V_86 , F_7 ( V_2 , V_81 ) ) ;
if ( V_2 -> V_91 && ( V_86 & V_82 ) && V_2 -> V_92 ) {
F_16 ( & V_2 -> V_10 ) ;
V_2 -> V_65 ++ ;
V_2 -> V_69 += V_2 -> V_55 ;
V_2 -> V_69 %= V_2 -> V_54 ;
V_87 = V_2 -> V_69 + V_2 -> V_55 ;
V_87 %= V_2 -> V_54 ;
F_29 ( V_2 -> V_67 + V_87 ,
( V_2 -> V_65 & 1 ) ?
F_7 ( V_2 , V_70 ) :
F_7 ( V_2 , V_71 ) ) ;
F_17 ( & V_2 -> V_10 ) ;
F_36 ( V_2 -> V_92 ) ;
}
if ( V_2 -> V_91 && ( V_86 & V_83 ) && V_2 -> V_93 ) {
F_16 ( & V_2 -> V_10 ) ;
V_2 -> V_74 ++ ;
V_2 -> V_77 += V_2 -> V_73 ;
V_2 -> V_77 %= V_2 -> V_72 ;
V_87 = V_2 -> V_77 + V_2 -> V_73 ;
V_87 %= V_2 -> V_72 ;
F_29 ( V_2 -> V_76 + V_87 ,
( V_2 -> V_74 & 1 ) ?
F_7 ( V_2 , V_78 ) :
F_7 ( V_2 , V_79 ) ) ;
F_17 ( & V_2 -> V_10 ) ;
F_36 ( V_2 -> V_93 ) ;
}
if ( V_2 -> V_94 && ( V_86 & V_88 ) )
F_37 ( V_84 , V_2 -> V_94 -> V_15 ) ;
if ( V_86 & V_89 )
;
return V_95 ;
}
static int F_38 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
struct V_52 * V_53 = V_32 -> V_53 ;
int V_96 ;
V_2 -> V_92 = V_32 ;
V_53 -> V_97 = V_98 ;
F_39 ( V_53 , 0 , V_99 ,
& V_100 ) ;
if ( V_2 -> V_101 ) {
V_53 -> V_97 . V_102 = 6 ;
F_39 ( V_53 , 0 ,
V_103 ,
& V_104 ) ;
}
if ( ( V_96 = F_40 ( V_53 , V_105 ) ) < 0 )
return V_96 ;
return 0 ;
}
static int F_41 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
struct V_52 * V_53 = V_32 -> V_53 ;
int V_96 ;
V_2 -> V_93 = V_32 ;
V_53 -> V_97 = V_106 ;
F_39 ( V_53 , 0 , V_99 ,
& V_100 ) ;
if ( ( V_96 = F_40 ( V_53 , V_105 ) ) < 0 )
return V_96 ;
return 0 ;
}
static int F_42 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
V_2 -> V_92 = NULL ;
return 0 ;
}
static int F_43 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_15 ( V_32 ) ;
V_2 -> V_93 = NULL ;
return 0 ;
}
static int T_4 F_44 ( struct V_1 * V_2 , int V_107 , struct V_108 * * V_109 )
{
struct V_108 * V_91 ;
int V_96 ;
if ( V_109 )
* V_109 = NULL ;
if ( ( V_96 = F_45 ( V_2 -> V_110 , L_4 , V_107 , 1 , 1 , & V_91 ) ) < 0 )
return V_96 ;
F_46 ( V_91 , V_111 , & V_112 ) ;
F_46 ( V_91 , V_113 , & V_114 ) ;
V_91 -> V_15 = V_2 ;
V_91 -> V_115 = 0 ;
strcpy ( V_91 -> V_116 , L_4 ) ;
V_2 -> V_91 = V_91 ;
F_47 ( V_91 , V_117 ,
F_48 ( V_2 -> V_118 ) ,
V_2 -> V_101 ? 128 * 1024 : 64 * 1024 , 128 * 1024 ) ;
if ( V_109 )
* V_109 = V_91 ;
return 0 ;
}
static void F_49 ( struct V_119 * V_120 , T_5 V_121 )
{
struct V_1 * V_2 = V_120 -> V_15 ;
unsigned short V_3 = F_3 ( F_7 ( V_2 , V_122 ) ) ;
struct V_123 V_124 = V_125 [ ( V_2 -> V_126 & V_127 ) - 1 ] ;
V_3 &= ~ ( F_50 ( V_124 . V_128 ) |
F_50 ( V_124 . V_129 ) |
F_50 ( V_124 . V_130 ) ) ;
V_3 |= ( V_121 & V_131 ) ? F_50 ( V_124 . V_128 ) : 0 ;
V_3 |= ( V_121 & V_132 ) ? F_50 ( V_124 . V_129 ) : 0 ;
V_3 |= ( V_121 & V_133 ) ? 0 : F_50 ( V_124 . V_130 ) ;
F_4 ( V_3 , F_7 ( V_2 , V_122 ) ) ;
}
static T_5 F_51 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_15 ;
unsigned short V_3 = F_3 ( F_7 ( V_2 , V_122 ) ) ;
struct V_123 V_124 = V_125 [ ( V_2 -> V_126 & V_127 ) - 1 ] ;
return ( V_3 & F_50 ( V_124 . V_128 ) ) ? V_131 : 0 |
( V_3 & F_50 ( V_124 . V_134 ) ) ? V_135 : 0 ;
}
static void F_52 ( struct V_119 * V_120 , bool V_136 )
{
struct V_1 * V_2 = V_120 -> V_15 ;
unsigned short V_3 = F_3 ( F_7 ( V_2 , V_122 ) ) ;
struct V_123 V_124 = V_125 [ ( V_2 -> V_126 & V_127 ) - 1 ] ;
V_3 |= F_53 ( V_124 . V_128 ) |
F_53 ( V_124 . V_130 ) |
F_53 ( V_124 . V_129 ) |
F_53 ( V_124 . V_134 ) ;
if ( V_136 ) {
V_3 &= ~ ( F_54 ( V_124 . V_128 ) |
F_54 ( V_124 . V_130 ) |
F_54 ( V_124 . V_129 ) |
F_50 ( V_124 . V_128 ) |
F_50 ( V_124 . V_129 ) |
F_50 ( V_124 . V_130 ) ) ;
} else {
V_3 |= F_54 ( V_124 . V_128 ) |
F_54 ( V_124 . V_134 ) |
F_50 ( V_124 . V_128 ) |
F_50 ( V_124 . V_134 ) |
F_50 ( V_124 . V_130 ) ;
V_3 &= ~ ( F_54 ( V_124 . V_130 ) |
F_54 ( V_124 . V_129 ) |
F_50 ( V_124 . V_129 ) ) ;
}
F_4 ( V_3 , F_7 ( V_2 , V_122 ) ) ;
}
static int F_55 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
int V_4 = ( V_138 -> V_141 >> 16 ) & 0xff ;
V_140 -> type = V_4 == 1 ? V_142 : V_143 ;
V_140 -> V_144 = 1 ;
V_140 -> V_5 . integer . V_145 = 0 ;
V_140 -> V_5 . integer . V_146 = V_4 ;
return 0 ;
}
static int F_56 ( struct V_137 * V_138 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_57 ( V_138 ) ;
int V_3 = V_138 -> V_141 & 0xff ;
int V_149 = ( V_138 -> V_141 >> 8 ) & 0xff ;
int V_4 = ( V_138 -> V_141 >> 16 ) & 0xff ;
int V_150 = ( V_138 -> V_141 >> 24 ) & 0xff ;
V_148 -> V_5 . integer . V_5 [ 0 ] = ( F_3 ( V_2 -> V_11 + V_3 ) >> V_149 ) & V_4 ;
if ( V_150 )
V_148 -> V_5 . integer . V_5 [ 0 ] = V_4 - V_148 -> V_5 . integer . V_5 [ 0 ] ;
return 0 ;
}
static int F_58 ( struct V_137 * V_138 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_57 ( V_138 ) ;
int V_3 = V_138 -> V_141 & 0xff ;
int V_149 = ( V_138 -> V_141 >> 8 ) & 0xff ;
int V_4 = ( V_138 -> V_141 >> 16 ) & 0xff ;
int V_150 = ( V_138 -> V_141 >> 24 ) & 0xff ;
unsigned short V_14 ;
V_14 = ( V_148 -> V_5 . integer . V_5 [ 0 ] & V_4 ) ;
if ( V_150 )
V_14 = V_4 - V_14 ;
return F_1 ( V_2 , V_3 , V_4 << V_149 , V_14 << V_149 ) ;
}
static int F_59 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
int V_4 = ( V_138 -> V_141 >> 16 ) & 0xff ;
V_140 -> type = V_4 == 1 ? V_142 : V_143 ;
V_140 -> V_144 = 2 ;
V_140 -> V_5 . integer . V_145 = 0 ;
V_140 -> V_5 . integer . V_146 = V_4 ;
return 0 ;
}
static int F_60 ( struct V_137 * V_138 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_57 ( V_138 ) ;
int V_3 = V_138 -> V_141 & 0xff ;
int V_151 = ( V_138 -> V_141 >> 8 ) & 0x0f ;
int V_152 = ( V_138 -> V_141 >> 12 ) & 0x0f ;
int V_4 = ( V_138 -> V_141 >> 16 ) & 0xff ;
int V_150 = ( V_138 -> V_141 >> 24 ) & 0xff ;
F_27 ( & V_2 -> V_10 ) ;
V_148 -> V_5 . integer . V_5 [ 0 ] = ( F_3 ( V_2 -> V_11 + V_3 ) >> V_151 ) & V_4 ;
V_148 -> V_5 . integer . V_5 [ 1 ] = ( F_3 ( V_2 -> V_11 + V_3 ) >> V_152 ) & V_4 ;
F_30 ( & V_2 -> V_10 ) ;
if ( V_150 ) {
V_148 -> V_5 . integer . V_5 [ 0 ] = V_4 - V_148 -> V_5 . integer . V_5 [ 0 ] ;
V_148 -> V_5 . integer . V_5 [ 1 ] = V_4 - V_148 -> V_5 . integer . V_5 [ 1 ] ;
}
return 0 ;
}
static int F_61 ( struct V_137 * V_138 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_57 ( V_138 ) ;
int V_3 = V_138 -> V_141 & 0xff ;
int V_151 = ( V_138 -> V_141 >> 8 ) & 0x0f ;
int V_152 = ( V_138 -> V_141 >> 12 ) & 0x0f ;
int V_4 = ( V_138 -> V_141 >> 16 ) & 0xff ;
int V_150 = ( V_138 -> V_141 >> 24 ) & 0xff ;
unsigned short V_153 , V_154 ;
V_153 = V_148 -> V_5 . integer . V_5 [ 0 ] & V_4 ;
V_154 = V_148 -> V_5 . integer . V_5 [ 1 ] & V_4 ;
if ( V_150 ) {
V_153 = V_4 - V_153 ;
V_154 = V_4 - V_154 ;
}
return F_1 ( V_2 , V_3 ,
( V_4 << V_151 ) | ( V_4 << V_152 ) ,
( V_153 << V_151 ) | ( V_154 << V_152 ) ) ;
}
static int F_62 ( struct V_137 * V_138 ,
struct V_139 * V_140 )
{
static char * V_155 [ 5 ] = {
L_5 , L_6 , L_7 , L_8 , L_9
} ;
V_140 -> type = V_156 ;
V_140 -> V_144 = 1 ;
V_140 -> V_5 . V_157 . V_158 = 5 ;
if ( V_140 -> V_5 . V_157 . V_159 > 4 )
V_140 -> V_5 . V_157 . V_159 = 4 ;
strcpy ( V_140 -> V_5 . V_157 . V_116 , V_155 [ V_140 -> V_5 . V_157 . V_159 ] ) ;
return 0 ;
}
static int F_63 ( struct V_137 * V_138 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_57 ( V_138 ) ;
unsigned short V_14 ;
V_14 = F_3 ( F_7 ( V_2 , V_160 ) ) & 7 ;
if ( V_14 > 4 )
V_14 = 4 ;
V_148 -> V_5 . V_157 . V_159 [ 0 ] = V_14 ;
return 0 ;
}
static int F_64 ( struct V_137 * V_138 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 = F_57 ( V_138 ) ;
unsigned short V_14 ;
if ( ( V_14 = V_148 -> V_5 . V_157 . V_159 [ 0 ] ) > 4 )
return - V_46 ;
return F_1 ( V_2 , V_161 , 7 , V_14 ) ;
}
static void F_65 ( struct V_162 * V_163 )
{
struct V_1 * V_2 = V_163 -> V_15 ;
V_2 -> V_164 = NULL ;
}
static void F_66 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
if ( V_13 -> V_24 == 0 ) {
V_2 -> V_13 = NULL ;
} else {
V_2 -> V_165 = NULL ;
}
}
static int T_4 F_67 ( struct V_1 * V_2 )
{
struct V_166 V_13 ;
unsigned int V_167 ;
int V_96 ;
static struct V_168 V_169 = {
. V_170 = F_6 ,
. V_171 = F_10 ,
} ;
if ( ( V_96 = V_162 ( V_2 -> V_110 , 0 , & V_169 , V_2 , & V_2 -> V_164 ) ) < 0 )
return V_96 ;
V_2 -> V_164 -> V_172 = F_65 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_15 = V_2 ;
V_13 . V_172 = F_66 ;
if ( ( V_96 = F_68 ( V_2 -> V_164 , & V_13 , & V_2 -> V_13 ) ) < 0 )
return V_96 ;
if ( V_2 -> V_173 ) {
V_13 . V_24 = 1 ;
V_13 . V_22 = V_2 -> V_174 ;
if ( ( V_96 = F_68 ( V_2 -> V_164 , & V_13 , & V_2 -> V_165 ) ) < 0 )
return V_96 ;
}
for ( V_167 = 0 ; V_167 < V_175 ; V_167 ++ )
F_69 ( V_2 -> V_110 , F_70 ( & V_176 [ V_167 ] , V_2 ) ) ;
if ( V_2 -> V_101 ) {
for ( V_167 = 0 ; V_167 < V_177 ; V_167 ++ )
F_69 ( V_2 -> V_110 , F_70 ( & V_178 [ V_167 ] , V_2 ) ) ;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , unsigned int V_179 ,
unsigned short V_3 , unsigned long V_180 )
{
unsigned long V_181 = V_182 + V_180 ;
F_4 ( V_25 | ( V_179 << V_23 ) | V_3 ,
F_7 ( V_2 , V_17 ) ) ;
F_8 ( 5 ) ;
do {
if ( ( F_3 ( F_7 ( V_2 , V_17 ) ) & ( V_27 | V_18 ) )
== V_27 )
return 0 ;
F_72 ( 1 ) ;
} while ( F_73 ( V_181 , V_182 ) );
return - V_183 ;
}
static int F_74 ( struct V_1 * V_2 , int V_184 )
{
unsigned short V_185 ;
if ( V_2 -> V_126 & V_186 )
goto V_187;
F_4 ( ( 1 << 5 ) | ( 1 << 6 ) , F_7 ( V_2 , V_188 ) ) ;
F_3 ( F_7 ( V_2 , V_188 ) ) ;
F_8 ( 100 ) ;
F_4 ( 0 , F_7 ( V_2 , V_188 ) ) ;
if ( F_71 ( V_2 , 0 , V_189 , F_75 ( 750 ) ) < 0 )
if ( ! V_184 ) {
F_9 ( V_190 L_10
L_11 ) ;
V_2 -> V_126 = 3 | V_186 ;
goto V_187;
}
if ( V_2 -> V_101 ) {
if ( V_2 -> V_174 ) {
F_71 ( V_2 , V_2 -> V_174 ,
V_191 , F_75 ( 50 ) ) ;
} else {
int V_167 ;
for ( V_167 = 3 ; V_167 > 0 ; V_167 -- ) {
if ( ! F_71 ( V_2 , V_167 , V_191 ,
F_75 ( 50 ) ) ) {
V_185 = F_3 ( F_7 ( V_2 , V_21 ) ) ;
if ( V_185 != 0xffff && V_185 != 0 ) {
V_2 -> V_173 = 1 ;
V_2 -> V_174 = V_167 ;
break;
}
}
}
}
F_71 ( V_2 , 0 , V_191 , F_75 ( 750 ) ) ;
}
V_187:
F_4 ( 0x0808 , F_7 ( V_2 , V_192 ) ) ;
F_4 ( 0x9f1f , F_7 ( V_2 , V_193 ) ) ;
F_4 ( 0x8808 , F_7 ( V_2 , V_194 ) ) ;
F_4 ( 0x0003 , F_7 ( V_2 , V_195 ) ) ;
V_185 = F_3 ( F_7 ( V_2 , V_196 ) ) ;
if ( V_2 -> V_84 < 0 )
V_185 |= 0x00c3 ;
else
V_185 &= ~ 0x0083 ;
F_4 ( V_185 , F_7 ( V_2 , V_196 ) ) ;
F_4 ( V_82 | V_83 | V_88 , F_7 ( V_2 , V_81 ) ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 )
{
unsigned short V_185 ;
if ( V_2 -> V_84 < 0 )
goto V_197;
V_185 = F_3 ( F_7 ( V_2 , V_196 ) ) ;
V_185 |= 0x00c3 ;
F_4 ( V_185 , F_7 ( V_2 , V_196 ) ) ;
V_197:
#ifdef F_77
if ( ! ( V_2 -> V_126 & V_198 ) )
F_78 ( & V_2 -> V_120 ) ;
#endif
if ( V_2 -> V_84 >= 0 )
F_79 ( V_2 -> V_84 , V_2 ) ;
F_80 ( V_2 -> V_118 ) ;
F_81 ( V_2 -> V_118 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static int F_83 ( struct V_199 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_200 ;
return F_76 ( V_2 ) ;
}
static int T_4 F_84 ( struct V_201 * V_110 ,
struct V_202 * V_118 ,
int V_126 ,
struct V_1 * * V_203 )
{
struct V_1 * V_2 ;
int V_96 ;
static struct V_204 V_169 = {
. V_205 = F_83 ,
} ;
* V_203 = NULL ;
if ( ( V_96 = F_85 ( V_118 ) ) < 0 )
return V_96 ;
V_2 = F_86 ( sizeof( * V_2 ) , V_206 ) ;
if ( V_2 == NULL ) {
F_81 ( V_118 ) ;
return - V_207 ;
}
F_87 ( & V_2 -> V_10 ) ;
V_2 -> V_110 = V_110 ;
V_2 -> V_118 = V_118 ;
V_2 -> V_84 = - 1 ;
V_2 -> V_126 = V_126 ;
if ( ( V_96 = F_88 ( V_118 , L_4 ) ) < 0 ) {
F_82 ( V_2 ) ;
F_81 ( V_118 ) ;
return V_96 ;
}
V_2 -> V_11 = F_89 ( V_118 , 0 ) ;
if ( ( V_126 & V_186 ) == 0 ) {
if ( F_90 ( V_118 -> V_84 , F_35 , V_208 ,
V_209 , V_2 ) ) {
F_9 ( V_20 L_12 , V_2 -> V_84 ) ;
F_76 ( V_2 ) ;
return - V_210 ;
}
V_2 -> V_84 = V_118 -> V_84 ;
F_91 ( V_118 ) ;
}
if ( V_118 -> V_211 >= 0xb1 )
V_2 -> V_101 = 1 ;
F_74 ( V_2 , 0 ) ;
V_126 = V_2 -> V_126 ;
if ( V_2 -> V_84 >= 0 && ( V_126 & V_186 ) ) {
F_92 ( V_118 ) ;
F_79 ( V_2 -> V_84 , V_2 ) ;
V_2 -> V_84 = - 1 ;
}
if ( ( V_96 = F_93 ( V_110 , V_212 , V_2 , & V_169 ) ) < 0 ) {
F_76 ( V_2 ) ;
return V_96 ;
}
F_94 ( V_110 , & V_118 -> V_213 ) ;
#ifdef F_77
V_2 -> V_120 . V_15 = V_2 ;
V_2 -> V_120 . V_169 = & V_214 ;
sprintf ( V_2 -> V_120 . V_215 , L_13 , F_95 ( V_118 ) ) ;
if ( ( V_126 & V_127 ) > 0 &&
( V_126 & V_127 ) < 4 ) {
if ( F_96 ( & V_2 -> V_120 ) ) {
F_9 ( V_20 L_14 ) ;
return - V_216 ;
}
} else if ( ( V_126 & V_127 ) == 0 ) {
for ( V_126 = 1 ; V_126 <= 3 ; V_126 ++ ) {
V_2 -> V_126 = V_126 ;
if ( ! F_96 ( & V_2 -> V_120 ) ) {
F_9 ( V_190 L_15 ,
V_125 [ V_126 - 1 ] . V_116 ) ;
break;
}
}
if ( V_126 == 4 ) {
F_9 ( V_20 L_14 ) ;
V_2 -> V_126 = V_198 ;
}
}
if ( ! ( V_2 -> V_126 & V_198 ) ) {
F_97 ( V_2 -> V_120 . V_110 ,
V_125 [ ( V_126 &
V_127 ) - 1 ] . V_116 ,
sizeof( V_2 -> V_120 . V_110 ) ) ;
}
#endif
* V_203 = V_2 ;
return 0 ;
}
static int T_4 F_98 ( struct V_202 * V_118 ,
const struct V_217 * V_218 )
{
static int V_213 ;
struct V_201 * V_110 ;
struct V_1 * V_2 ;
struct V_219 * V_220 ;
int V_96 ;
if ( V_213 >= V_221 )
return - V_216 ;
if ( ! V_222 [ V_213 ] ) {
V_213 ++ ;
return - V_223 ;
}
V_96 = F_99 ( V_224 [ V_213 ] , V_225 [ V_213 ] , V_226 , 0 , & V_110 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ( V_96 = F_84 ( V_110 , V_118 , V_126 [ V_213 ] , & V_2 ) ) < 0 ) {
F_100 ( V_110 ) ;
return V_96 ;
}
V_110 -> V_15 = V_2 ;
strcpy ( V_110 -> V_227 , L_4 ) ;
strcpy ( V_110 -> V_228 , L_16 ) ;
strcat ( V_110 -> V_228 , V_2 -> V_101 ? L_17 : L_18 ) ;
sprintf ( V_110 -> V_229 , L_19 ,
V_110 -> V_228 , V_2 -> V_11 , V_2 -> V_84 ) ;
if ( V_2 -> V_126 & V_186 )
goto V_230;
if ( ( V_96 = F_44 ( V_2 , 0 , NULL ) ) < 0 ) {
F_100 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_67 ( V_2 ) ) < 0 ) {
F_100 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_101 ( V_110 , 0 , V_231 ,
F_7 ( V_2 , V_232 ) ,
V_233 ,
V_2 -> V_84 , 0 , & V_2 -> V_94 ) ) < 0 ) {
F_100 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_102 ( V_110 , F_7 ( V_2 , V_234 ) ,
F_7 ( V_2 , V_235 ) ,
V_236 , 1 , & V_220 ) ) < 0 ) {
F_100 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_103 ( V_220 , 0 , 1 , NULL ) ) < 0 ) {
F_100 ( V_110 ) ;
return V_96 ;
}
V_230:
if ( ( V_96 = F_104 ( V_110 ) ) < 0 ) {
F_100 ( V_110 ) ;
return V_96 ;
}
F_105 ( V_118 , V_110 ) ;
V_213 ++ ;
return 0 ;
}
static void T_6 F_106 ( struct V_202 * V_118 )
{
F_100 ( F_107 ( V_118 ) ) ;
F_105 ( V_118 , NULL ) ;
}
static int F_108 ( struct V_202 * V_118 , T_7 V_237 )
{
struct V_201 * V_110 = F_107 ( V_118 ) ;
struct V_1 * V_2 = V_110 -> V_15 ;
int V_167 ;
F_109 ( V_110 , V_238 ) ;
F_110 ( V_2 -> V_91 ) ;
F_111 ( V_2 -> V_13 ) ;
F_111 ( V_2 -> V_165 ) ;
for ( V_167 = 0 ; V_167 < F_12 ( V_239 ) ; V_167 ++ )
V_2 -> V_239 [ V_167 ] = F_3 ( V_2 -> V_11 + V_239 [ V_167 ] ) ;
F_81 ( V_118 ) ;
F_112 ( V_118 ) ;
F_113 ( V_118 , F_114 ( V_118 , V_237 ) ) ;
return 0 ;
}
static int F_115 ( struct V_202 * V_118 )
{
struct V_201 * V_110 = F_107 ( V_118 ) ;
struct V_1 * V_2 = V_110 -> V_15 ;
int V_167 ;
F_113 ( V_118 , V_240 ) ;
F_116 ( V_118 ) ;
if ( F_85 ( V_118 ) < 0 ) {
F_117 ( V_20 L_20
L_21 ) ;
F_118 ( V_110 ) ;
return - V_183 ;
}
F_91 ( V_118 ) ;
F_74 ( V_2 , 1 ) ;
F_119 ( V_2 -> V_13 ) ;
F_119 ( V_2 -> V_165 ) ;
for ( V_167 = 0 ; V_167 < F_12 ( V_239 ) ; V_167 ++ )
F_4 ( V_2 -> V_239 [ V_167 ] , V_2 -> V_11 + V_239 [ V_167 ] ) ;
F_109 ( V_110 , V_241 ) ;
return 0 ;
}
static int T_8 F_120 ( void )
{
return F_121 ( & V_227 ) ;
}
static void T_9 F_122 ( void )
{
F_123 ( & V_227 ) ;
}

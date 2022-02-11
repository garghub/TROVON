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
static int F_44 ( struct V_1 * V_2 , int V_107 , struct V_108 * * V_109 )
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
V_96 = F_49 ( V_91 , V_111 ,
V_119 ,
V_2 -> V_101 ? 6 : 2 , 0 ,
NULL ) ;
if ( V_96 < 0 )
return V_96 ;
if ( V_109 )
* V_109 = V_91 ;
return 0 ;
}
static void F_50 ( struct V_120 * V_121 , T_4 V_122 )
{
struct V_1 * V_2 = V_121 -> V_15 ;
unsigned short V_3 = F_3 ( F_7 ( V_2 , V_123 ) ) ;
struct V_124 V_125 = * F_51 ( V_2 ) ;
V_3 &= ~ ( F_52 ( V_125 . V_126 ) |
F_52 ( V_125 . V_127 ) |
F_52 ( V_125 . V_128 ) ) ;
V_3 |= ( V_122 & V_129 ) ? F_52 ( V_125 . V_126 ) : 0 ;
V_3 |= ( V_122 & V_130 ) ? F_52 ( V_125 . V_127 ) : 0 ;
V_3 |= ( V_122 & V_131 ) ? 0 : F_52 ( V_125 . V_128 ) ;
F_4 ( V_3 , F_7 ( V_2 , V_123 ) ) ;
}
static T_4 F_53 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = V_121 -> V_15 ;
unsigned short V_3 = F_3 ( F_7 ( V_2 , V_123 ) ) ;
struct V_124 V_125 = * F_51 ( V_2 ) ;
T_4 V_132 ;
V_132 = 0 ;
if ( V_3 & F_52 ( V_125 . V_126 ) )
V_132 |= V_129 ;
if ( V_3 & F_52 ( V_125 . V_133 ) )
V_132 |= V_134 ;
return V_132 ;
}
static void F_54 ( struct V_120 * V_121 , bool V_135 )
{
struct V_1 * V_2 = V_121 -> V_15 ;
unsigned short V_3 = F_3 ( F_7 ( V_2 , V_123 ) ) ;
struct V_124 V_125 = * F_51 ( V_2 ) ;
V_3 |= F_55 ( V_125 . V_126 ) |
F_55 ( V_125 . V_128 ) |
F_55 ( V_125 . V_127 ) |
F_55 ( V_125 . V_133 ) ;
if ( V_135 ) {
V_3 &= ~ ( F_56 ( V_125 . V_126 ) |
F_56 ( V_125 . V_128 ) |
F_56 ( V_125 . V_127 ) |
F_52 ( V_125 . V_126 ) |
F_52 ( V_125 . V_127 ) |
F_52 ( V_125 . V_128 ) ) ;
} else {
V_3 |= F_56 ( V_125 . V_126 ) |
F_56 ( V_125 . V_133 ) |
F_52 ( V_125 . V_126 ) |
F_52 ( V_125 . V_133 ) |
F_52 ( V_125 . V_128 ) ;
V_3 &= ~ ( F_56 ( V_125 . V_128 ) |
F_56 ( V_125 . V_127 ) |
F_52 ( V_125 . V_127 ) ) ;
}
F_4 ( V_3 , F_7 ( V_2 , V_123 ) ) ;
}
static int F_57 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
int V_4 = ( V_137 -> V_140 >> 16 ) & 0xff ;
V_139 -> type = V_4 == 1 ? V_141 : V_142 ;
V_139 -> V_143 = 1 ;
V_139 -> V_5 . integer . V_144 = 0 ;
V_139 -> V_5 . integer . V_145 = V_4 ;
return 0 ;
}
static int F_58 ( struct V_136 * V_137 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 = F_59 ( V_137 ) ;
int V_3 = V_137 -> V_140 & 0xff ;
int V_148 = ( V_137 -> V_140 >> 8 ) & 0xff ;
int V_4 = ( V_137 -> V_140 >> 16 ) & 0xff ;
int V_149 = ( V_137 -> V_140 >> 24 ) & 0xff ;
V_147 -> V_5 . integer . V_5 [ 0 ] = ( F_3 ( V_2 -> V_11 + V_3 ) >> V_148 ) & V_4 ;
if ( V_149 )
V_147 -> V_5 . integer . V_5 [ 0 ] = V_4 - V_147 -> V_5 . integer . V_5 [ 0 ] ;
return 0 ;
}
static int F_60 ( struct V_136 * V_137 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 = F_59 ( V_137 ) ;
int V_3 = V_137 -> V_140 & 0xff ;
int V_148 = ( V_137 -> V_140 >> 8 ) & 0xff ;
int V_4 = ( V_137 -> V_140 >> 16 ) & 0xff ;
int V_149 = ( V_137 -> V_140 >> 24 ) & 0xff ;
unsigned short V_14 ;
V_14 = ( V_147 -> V_5 . integer . V_5 [ 0 ] & V_4 ) ;
if ( V_149 )
V_14 = V_4 - V_14 ;
return F_1 ( V_2 , V_3 , V_4 << V_148 , V_14 << V_148 ) ;
}
static int F_61 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
int V_4 = ( V_137 -> V_140 >> 16 ) & 0xff ;
V_139 -> type = V_4 == 1 ? V_141 : V_142 ;
V_139 -> V_143 = 2 ;
V_139 -> V_5 . integer . V_144 = 0 ;
V_139 -> V_5 . integer . V_145 = V_4 ;
return 0 ;
}
static int F_62 ( struct V_136 * V_137 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 = F_59 ( V_137 ) ;
int V_3 = V_137 -> V_140 & 0xff ;
int V_150 = ( V_137 -> V_140 >> 8 ) & 0x0f ;
int V_151 = ( V_137 -> V_140 >> 12 ) & 0x0f ;
int V_4 = ( V_137 -> V_140 >> 16 ) & 0xff ;
int V_149 = ( V_137 -> V_140 >> 24 ) & 0xff ;
F_27 ( & V_2 -> V_10 ) ;
V_147 -> V_5 . integer . V_5 [ 0 ] = ( F_3 ( V_2 -> V_11 + V_3 ) >> V_150 ) & V_4 ;
V_147 -> V_5 . integer . V_5 [ 1 ] = ( F_3 ( V_2 -> V_11 + V_3 ) >> V_151 ) & V_4 ;
F_30 ( & V_2 -> V_10 ) ;
if ( V_149 ) {
V_147 -> V_5 . integer . V_5 [ 0 ] = V_4 - V_147 -> V_5 . integer . V_5 [ 0 ] ;
V_147 -> V_5 . integer . V_5 [ 1 ] = V_4 - V_147 -> V_5 . integer . V_5 [ 1 ] ;
}
return 0 ;
}
static int F_63 ( struct V_136 * V_137 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 = F_59 ( V_137 ) ;
int V_3 = V_137 -> V_140 & 0xff ;
int V_150 = ( V_137 -> V_140 >> 8 ) & 0x0f ;
int V_151 = ( V_137 -> V_140 >> 12 ) & 0x0f ;
int V_4 = ( V_137 -> V_140 >> 16 ) & 0xff ;
int V_149 = ( V_137 -> V_140 >> 24 ) & 0xff ;
unsigned short V_152 , V_153 ;
V_152 = V_147 -> V_5 . integer . V_5 [ 0 ] & V_4 ;
V_153 = V_147 -> V_5 . integer . V_5 [ 1 ] & V_4 ;
if ( V_149 ) {
V_152 = V_4 - V_152 ;
V_153 = V_4 - V_153 ;
}
return F_1 ( V_2 , V_3 ,
( V_4 << V_150 ) | ( V_4 << V_151 ) ,
( V_152 << V_150 ) | ( V_153 << V_151 ) ) ;
}
static int F_64 ( struct V_136 * V_137 ,
struct V_138 * V_139 )
{
static char * V_154 [ 5 ] = {
L_5 , L_6 , L_7 , L_8 , L_9
} ;
V_139 -> type = V_155 ;
V_139 -> V_143 = 1 ;
V_139 -> V_5 . V_156 . V_157 = 5 ;
if ( V_139 -> V_5 . V_156 . V_158 > 4 )
V_139 -> V_5 . V_156 . V_158 = 4 ;
strcpy ( V_139 -> V_5 . V_156 . V_116 , V_154 [ V_139 -> V_5 . V_156 . V_158 ] ) ;
return 0 ;
}
static int F_65 ( struct V_136 * V_137 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 = F_59 ( V_137 ) ;
unsigned short V_14 ;
V_14 = F_3 ( F_7 ( V_2 , V_159 ) ) & 7 ;
if ( V_14 > 4 )
V_14 = 4 ;
V_147 -> V_5 . V_156 . V_158 [ 0 ] = V_14 ;
return 0 ;
}
static int F_66 ( struct V_136 * V_137 ,
struct V_146 * V_147 )
{
struct V_1 * V_2 = F_59 ( V_137 ) ;
unsigned short V_14 ;
if ( ( V_14 = V_147 -> V_5 . V_156 . V_158 [ 0 ] ) > 4 )
return - V_46 ;
return F_1 ( V_2 , V_160 , 7 , V_14 ) ;
}
static void F_67 ( struct V_161 * V_162 )
{
struct V_1 * V_2 = V_162 -> V_15 ;
V_2 -> V_163 = NULL ;
}
static void F_68 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
if ( V_13 -> V_24 == 0 ) {
V_2 -> V_13 = NULL ;
} else {
V_2 -> V_164 = NULL ;
}
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_165 V_13 ;
unsigned int V_166 ;
int V_96 ;
static struct V_167 V_168 = {
. V_169 = F_6 ,
. V_170 = F_10 ,
} ;
if ( ( V_96 = V_161 ( V_2 -> V_110 , 0 , & V_168 , V_2 , & V_2 -> V_163 ) ) < 0 )
return V_96 ;
V_2 -> V_163 -> V_171 = F_67 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_15 = V_2 ;
V_13 . V_171 = F_68 ;
if ( ( V_96 = F_70 ( V_2 -> V_163 , & V_13 , & V_2 -> V_13 ) ) < 0 )
return V_96 ;
if ( V_2 -> V_172 ) {
V_13 . V_24 = 1 ;
V_13 . V_22 = V_2 -> V_173 ;
if ( ( V_96 = F_70 ( V_2 -> V_163 , & V_13 , & V_2 -> V_164 ) ) < 0 )
return V_96 ;
}
for ( V_166 = 0 ; V_166 < V_174 ; V_166 ++ )
F_71 ( V_2 -> V_110 , F_72 ( & V_175 [ V_166 ] , V_2 ) ) ;
if ( V_2 -> V_101 ) {
for ( V_166 = 0 ; V_166 < V_176 ; V_166 ++ )
F_71 ( V_2 -> V_110 , F_72 ( & V_177 [ V_166 ] , V_2 ) ) ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , unsigned int V_178 ,
unsigned short V_3 , unsigned long V_179 )
{
unsigned long V_180 = V_181 + V_179 ;
F_4 ( V_25 | ( V_178 << V_23 ) | V_3 ,
F_7 ( V_2 , V_17 ) ) ;
F_8 ( 5 ) ;
do {
if ( ( F_3 ( F_7 ( V_2 , V_17 ) ) & ( V_27 | V_18 ) )
== V_27 )
return 0 ;
F_74 ( 1 ) ;
} while ( F_75 ( V_180 , V_181 ) );
return - V_182 ;
}
static int F_76 ( struct V_1 * V_2 , int V_183 )
{
unsigned short V_184 ;
if ( V_2 -> V_185 & V_186 )
goto V_187;
F_4 ( ( 1 << 5 ) | ( 1 << 6 ) , F_7 ( V_2 , V_188 ) ) ;
F_3 ( F_7 ( V_2 , V_188 ) ) ;
F_8 ( 100 ) ;
F_4 ( 0 , F_7 ( V_2 , V_188 ) ) ;
if ( F_73 ( V_2 , 0 , V_189 , F_77 ( 750 ) ) < 0 )
if ( ! V_183 ) {
F_9 ( V_190 L_10
L_11 ) ;
V_2 -> V_185 = 3 | V_186 ;
goto V_187;
}
if ( V_2 -> V_101 ) {
if ( V_2 -> V_173 ) {
F_73 ( V_2 , V_2 -> V_173 ,
V_191 , F_77 ( 50 ) ) ;
} else {
int V_166 ;
for ( V_166 = 3 ; V_166 > 0 ; V_166 -- ) {
if ( ! F_73 ( V_2 , V_166 , V_191 ,
F_77 ( 50 ) ) ) {
V_184 = F_3 ( F_7 ( V_2 , V_21 ) ) ;
if ( V_184 != 0xffff && V_184 != 0 ) {
V_2 -> V_172 = 1 ;
V_2 -> V_173 = V_166 ;
break;
}
}
}
}
F_73 ( V_2 , 0 , V_191 , F_77 ( 750 ) ) ;
}
V_187:
F_4 ( 0x0808 , F_7 ( V_2 , V_192 ) ) ;
F_4 ( 0x9f1f , F_7 ( V_2 , V_193 ) ) ;
F_4 ( 0x8808 , F_7 ( V_2 , V_194 ) ) ;
F_4 ( 0x0003 , F_7 ( V_2 , V_195 ) ) ;
V_184 = F_3 ( F_7 ( V_2 , V_196 ) ) ;
if ( V_2 -> V_84 < 0 )
V_184 |= 0x00c3 ;
else
V_184 &= ~ 0x0083 ;
F_4 ( V_184 , F_7 ( V_2 , V_196 ) ) ;
F_4 ( V_82 | V_83 | V_88 , F_7 ( V_2 , V_81 ) ) ;
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
unsigned short V_184 ;
if ( V_2 -> V_84 < 0 )
goto V_197;
V_184 = F_3 ( F_7 ( V_2 , V_196 ) ) ;
V_184 |= 0x00c3 ;
F_4 ( V_184 , F_7 ( V_2 , V_196 ) ) ;
V_197:
#ifdef F_79
if ( ! ( V_2 -> V_185 & V_198 ) ) {
F_80 ( & V_2 -> V_121 ) ;
F_81 ( & V_2 -> V_199 ) ;
}
#endif
if ( V_2 -> V_84 >= 0 )
F_82 ( V_2 -> V_84 , V_2 ) ;
F_83 ( V_2 -> V_118 ) ;
F_84 ( V_2 -> V_118 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_200 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_201 ;
return F_78 ( V_2 ) ;
}
static int F_87 ( struct V_202 * V_110 ,
struct V_203 * V_118 ,
int V_185 ,
int V_204 ,
struct V_1 * * V_205 )
{
struct V_1 * V_2 ;
int V_96 ;
static struct V_206 V_168 = {
. V_207 = F_86 ,
} ;
* V_205 = NULL ;
if ( ( V_96 = F_88 ( V_118 ) ) < 0 )
return V_96 ;
V_2 = F_89 ( sizeof( * V_2 ) , V_208 ) ;
if ( V_2 == NULL ) {
F_84 ( V_118 ) ;
return - V_209 ;
}
F_90 ( & V_2 -> V_10 ) ;
V_2 -> V_110 = V_110 ;
V_2 -> V_118 = V_118 ;
V_2 -> V_84 = - 1 ;
V_2 -> V_185 = V_185 ;
if ( ( V_96 = F_91 ( V_118 , L_4 ) ) < 0 ) {
F_85 ( V_2 ) ;
F_84 ( V_118 ) ;
return V_96 ;
}
V_2 -> V_11 = F_92 ( V_118 , 0 ) ;
if ( ( V_185 & V_186 ) == 0 ) {
if ( F_93 ( V_118 -> V_84 , F_35 , V_210 ,
V_211 , V_2 ) ) {
F_9 ( V_20 L_12 , V_2 -> V_84 ) ;
F_78 ( V_2 ) ;
return - V_212 ;
}
V_2 -> V_84 = V_118 -> V_84 ;
F_94 ( V_118 ) ;
}
if ( V_118 -> V_213 >= 0xb1 )
V_2 -> V_101 = 1 ;
F_76 ( V_2 , 0 ) ;
V_185 = V_2 -> V_185 ;
if ( V_2 -> V_84 >= 0 && ( V_185 & V_186 ) ) {
F_95 ( V_118 ) ;
F_82 ( V_2 -> V_84 , V_2 ) ;
V_2 -> V_84 = - 1 ;
}
if ( ( V_96 = F_96 ( V_110 , V_214 , V_2 , & V_168 ) ) < 0 ) {
F_78 ( V_2 ) ;
return V_96 ;
}
F_97 ( V_110 , & V_118 -> V_215 ) ;
#ifdef F_79
V_96 = F_98 ( & V_118 -> V_215 , & V_2 -> V_199 ) ;
if ( V_96 < 0 ) {
F_78 ( V_2 ) ;
return V_96 ;
}
V_2 -> V_121 . V_199 = & V_2 -> V_199 ;
V_2 -> V_121 . V_204 = V_204 ;
V_2 -> V_121 . V_15 = V_2 ;
V_2 -> V_121 . V_168 = & V_216 ;
sprintf ( V_2 -> V_121 . V_217 , L_13 , F_99 ( V_118 ) ) ;
if ( ( V_185 & V_218 ) > 0 &&
( V_185 & V_218 ) < 4 ) {
if ( F_100 ( & V_2 -> V_121 , V_219 ) ) {
F_9 ( V_20 L_14 ) ;
F_78 ( V_2 ) ;
return - V_220 ;
}
} else if ( ( V_185 & V_218 ) == 0 ) {
for ( V_185 = 1 ; V_185 <= 3 ; V_185 ++ ) {
V_2 -> V_185 = V_185 ;
if ( ! F_100 ( & V_2 -> V_121 , V_219 ) ) {
F_9 ( V_190 L_15 ,
F_51 ( V_2 ) -> V_116 ) ;
break;
}
}
if ( V_185 == 4 ) {
F_9 ( V_20 L_14 ) ;
V_2 -> V_185 = V_198 ;
}
}
if ( ! ( V_2 -> V_185 & V_198 ) ) {
F_101 ( V_2 -> V_121 . V_110 , F_51 ( V_2 ) -> V_116 ,
sizeof( V_2 -> V_121 . V_110 ) ) ;
}
#endif
* V_205 = V_2 ;
return 0 ;
}
static int F_102 ( struct V_203 * V_118 ,
const struct V_221 * V_222 )
{
static int V_215 ;
struct V_202 * V_110 ;
struct V_1 * V_2 ;
struct V_223 * V_224 ;
int V_96 ;
if ( V_215 >= V_225 )
return - V_220 ;
if ( ! V_226 [ V_215 ] ) {
V_215 ++ ;
return - V_227 ;
}
V_96 = F_103 ( V_228 [ V_215 ] , V_229 [ V_215 ] , V_219 , 0 , & V_110 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ( V_96 = F_87 ( V_110 , V_118 , V_185 [ V_215 ] , V_204 [ V_215 ] , & V_2 ) ) < 0 ) {
F_104 ( V_110 ) ;
return V_96 ;
}
V_110 -> V_15 = V_2 ;
strcpy ( V_110 -> V_230 , L_4 ) ;
strcpy ( V_110 -> V_231 , L_16 ) ;
strcat ( V_110 -> V_231 , V_2 -> V_101 ? L_17 : L_18 ) ;
sprintf ( V_110 -> V_232 , L_19 ,
V_110 -> V_231 , V_2 -> V_11 , V_2 -> V_84 ) ;
if ( V_2 -> V_185 & V_186 )
goto V_233;
if ( ( V_96 = F_44 ( V_2 , 0 , NULL ) ) < 0 ) {
F_104 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_69 ( V_2 ) ) < 0 ) {
F_104 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_105 ( V_110 , 0 , V_234 ,
F_7 ( V_2 , V_235 ) ,
V_236 |
V_237 ,
- 1 , & V_2 -> V_94 ) ) < 0 ) {
F_104 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_106 ( V_110 , F_7 ( V_2 , V_238 ) ,
F_7 ( V_2 , V_239 ) ,
V_240 , 1 , & V_224 ) ) < 0 ) {
F_104 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_107 ( V_224 , 0 , 1 , NULL ) ) < 0 ) {
F_104 ( V_110 ) ;
return V_96 ;
}
V_233:
if ( ( V_96 = F_108 ( V_110 ) ) < 0 ) {
F_104 ( V_110 ) ;
return V_96 ;
}
F_109 ( V_118 , V_110 ) ;
V_215 ++ ;
return 0 ;
}
static void F_110 ( struct V_203 * V_118 )
{
F_104 ( F_111 ( V_118 ) ) ;
}
static int F_112 ( struct V_107 * V_215 )
{
struct V_203 * V_118 = F_113 ( V_215 ) ;
struct V_202 * V_110 = F_114 ( V_215 ) ;
struct V_1 * V_2 = V_110 -> V_15 ;
int V_166 ;
F_115 ( V_110 , V_241 ) ;
F_116 ( V_2 -> V_91 ) ;
F_117 ( V_2 -> V_13 ) ;
F_117 ( V_2 -> V_164 ) ;
for ( V_166 = 0 ; V_166 < F_12 ( V_242 ) ; V_166 ++ )
V_2 -> V_242 [ V_166 ] = F_3 ( V_2 -> V_11 + V_242 [ V_166 ] ) ;
F_84 ( V_118 ) ;
F_118 ( V_118 ) ;
F_119 ( V_118 , V_243 ) ;
return 0 ;
}
static int F_120 ( struct V_107 * V_215 )
{
struct V_203 * V_118 = F_113 ( V_215 ) ;
struct V_202 * V_110 = F_114 ( V_215 ) ;
struct V_1 * V_2 = V_110 -> V_15 ;
int V_166 ;
F_119 ( V_118 , V_244 ) ;
F_121 ( V_118 ) ;
if ( F_88 ( V_118 ) < 0 ) {
F_122 ( V_20 L_20
L_21 ) ;
F_123 ( V_110 ) ;
return - V_182 ;
}
F_94 ( V_118 ) ;
F_76 ( V_2 , 1 ) ;
F_124 ( V_2 -> V_13 ) ;
F_124 ( V_2 -> V_164 ) ;
for ( V_166 = 0 ; V_166 < F_12 ( V_242 ) ; V_166 ++ )
F_4 ( V_2 -> V_242 [ V_166 ] , V_2 -> V_11 + V_242 [ V_166 ] ) ;
F_115 ( V_110 , V_245 ) ;
return 0 ;
}

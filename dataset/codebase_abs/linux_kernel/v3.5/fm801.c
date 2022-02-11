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
struct V_123 V_124 = * F_50 ( V_2 ) ;
V_3 &= ~ ( F_51 ( V_124 . V_125 ) |
F_51 ( V_124 . V_126 ) |
F_51 ( V_124 . V_127 ) ) ;
V_3 |= ( V_121 & V_128 ) ? F_51 ( V_124 . V_125 ) : 0 ;
V_3 |= ( V_121 & V_129 ) ? F_51 ( V_124 . V_126 ) : 0 ;
V_3 |= ( V_121 & V_130 ) ? 0 : F_51 ( V_124 . V_127 ) ;
F_4 ( V_3 , F_7 ( V_2 , V_122 ) ) ;
}
static T_5 F_52 ( struct V_119 * V_120 )
{
struct V_1 * V_2 = V_120 -> V_15 ;
unsigned short V_3 = F_3 ( F_7 ( V_2 , V_122 ) ) ;
struct V_123 V_124 = * F_50 ( V_2 ) ;
return ( V_3 & F_51 ( V_124 . V_125 ) ) ? V_128 : 0 |
( V_3 & F_51 ( V_124 . V_131 ) ) ? V_132 : 0 ;
}
static void F_53 ( struct V_119 * V_120 , bool V_133 )
{
struct V_1 * V_2 = V_120 -> V_15 ;
unsigned short V_3 = F_3 ( F_7 ( V_2 , V_122 ) ) ;
struct V_123 V_124 = * F_50 ( V_2 ) ;
V_3 |= F_54 ( V_124 . V_125 ) |
F_54 ( V_124 . V_127 ) |
F_54 ( V_124 . V_126 ) |
F_54 ( V_124 . V_131 ) ;
if ( V_133 ) {
V_3 &= ~ ( F_55 ( V_124 . V_125 ) |
F_55 ( V_124 . V_127 ) |
F_55 ( V_124 . V_126 ) |
F_51 ( V_124 . V_125 ) |
F_51 ( V_124 . V_126 ) |
F_51 ( V_124 . V_127 ) ) ;
} else {
V_3 |= F_55 ( V_124 . V_125 ) |
F_55 ( V_124 . V_131 ) |
F_51 ( V_124 . V_125 ) |
F_51 ( V_124 . V_131 ) |
F_51 ( V_124 . V_127 ) ;
V_3 &= ~ ( F_55 ( V_124 . V_127 ) |
F_55 ( V_124 . V_126 ) |
F_51 ( V_124 . V_126 ) ) ;
}
F_4 ( V_3 , F_7 ( V_2 , V_122 ) ) ;
}
static int F_56 ( struct V_134 * V_135 ,
struct V_136 * V_137 )
{
int V_4 = ( V_135 -> V_138 >> 16 ) & 0xff ;
V_137 -> type = V_4 == 1 ? V_139 : V_140 ;
V_137 -> V_141 = 1 ;
V_137 -> V_5 . integer . V_142 = 0 ;
V_137 -> V_5 . integer . V_143 = V_4 ;
return 0 ;
}
static int F_57 ( struct V_134 * V_135 ,
struct V_144 * V_145 )
{
struct V_1 * V_2 = F_58 ( V_135 ) ;
int V_3 = V_135 -> V_138 & 0xff ;
int V_146 = ( V_135 -> V_138 >> 8 ) & 0xff ;
int V_4 = ( V_135 -> V_138 >> 16 ) & 0xff ;
int V_147 = ( V_135 -> V_138 >> 24 ) & 0xff ;
V_145 -> V_5 . integer . V_5 [ 0 ] = ( F_3 ( V_2 -> V_11 + V_3 ) >> V_146 ) & V_4 ;
if ( V_147 )
V_145 -> V_5 . integer . V_5 [ 0 ] = V_4 - V_145 -> V_5 . integer . V_5 [ 0 ] ;
return 0 ;
}
static int F_59 ( struct V_134 * V_135 ,
struct V_144 * V_145 )
{
struct V_1 * V_2 = F_58 ( V_135 ) ;
int V_3 = V_135 -> V_138 & 0xff ;
int V_146 = ( V_135 -> V_138 >> 8 ) & 0xff ;
int V_4 = ( V_135 -> V_138 >> 16 ) & 0xff ;
int V_147 = ( V_135 -> V_138 >> 24 ) & 0xff ;
unsigned short V_14 ;
V_14 = ( V_145 -> V_5 . integer . V_5 [ 0 ] & V_4 ) ;
if ( V_147 )
V_14 = V_4 - V_14 ;
return F_1 ( V_2 , V_3 , V_4 << V_146 , V_14 << V_146 ) ;
}
static int F_60 ( struct V_134 * V_135 ,
struct V_136 * V_137 )
{
int V_4 = ( V_135 -> V_138 >> 16 ) & 0xff ;
V_137 -> type = V_4 == 1 ? V_139 : V_140 ;
V_137 -> V_141 = 2 ;
V_137 -> V_5 . integer . V_142 = 0 ;
V_137 -> V_5 . integer . V_143 = V_4 ;
return 0 ;
}
static int F_61 ( struct V_134 * V_135 ,
struct V_144 * V_145 )
{
struct V_1 * V_2 = F_58 ( V_135 ) ;
int V_3 = V_135 -> V_138 & 0xff ;
int V_148 = ( V_135 -> V_138 >> 8 ) & 0x0f ;
int V_149 = ( V_135 -> V_138 >> 12 ) & 0x0f ;
int V_4 = ( V_135 -> V_138 >> 16 ) & 0xff ;
int V_147 = ( V_135 -> V_138 >> 24 ) & 0xff ;
F_27 ( & V_2 -> V_10 ) ;
V_145 -> V_5 . integer . V_5 [ 0 ] = ( F_3 ( V_2 -> V_11 + V_3 ) >> V_148 ) & V_4 ;
V_145 -> V_5 . integer . V_5 [ 1 ] = ( F_3 ( V_2 -> V_11 + V_3 ) >> V_149 ) & V_4 ;
F_30 ( & V_2 -> V_10 ) ;
if ( V_147 ) {
V_145 -> V_5 . integer . V_5 [ 0 ] = V_4 - V_145 -> V_5 . integer . V_5 [ 0 ] ;
V_145 -> V_5 . integer . V_5 [ 1 ] = V_4 - V_145 -> V_5 . integer . V_5 [ 1 ] ;
}
return 0 ;
}
static int F_62 ( struct V_134 * V_135 ,
struct V_144 * V_145 )
{
struct V_1 * V_2 = F_58 ( V_135 ) ;
int V_3 = V_135 -> V_138 & 0xff ;
int V_148 = ( V_135 -> V_138 >> 8 ) & 0x0f ;
int V_149 = ( V_135 -> V_138 >> 12 ) & 0x0f ;
int V_4 = ( V_135 -> V_138 >> 16 ) & 0xff ;
int V_147 = ( V_135 -> V_138 >> 24 ) & 0xff ;
unsigned short V_150 , V_151 ;
V_150 = V_145 -> V_5 . integer . V_5 [ 0 ] & V_4 ;
V_151 = V_145 -> V_5 . integer . V_5 [ 1 ] & V_4 ;
if ( V_147 ) {
V_150 = V_4 - V_150 ;
V_151 = V_4 - V_151 ;
}
return F_1 ( V_2 , V_3 ,
( V_4 << V_148 ) | ( V_4 << V_149 ) ,
( V_150 << V_148 ) | ( V_151 << V_149 ) ) ;
}
static int F_63 ( struct V_134 * V_135 ,
struct V_136 * V_137 )
{
static char * V_152 [ 5 ] = {
L_5 , L_6 , L_7 , L_8 , L_9
} ;
V_137 -> type = V_153 ;
V_137 -> V_141 = 1 ;
V_137 -> V_5 . V_154 . V_155 = 5 ;
if ( V_137 -> V_5 . V_154 . V_156 > 4 )
V_137 -> V_5 . V_154 . V_156 = 4 ;
strcpy ( V_137 -> V_5 . V_154 . V_116 , V_152 [ V_137 -> V_5 . V_154 . V_156 ] ) ;
return 0 ;
}
static int F_64 ( struct V_134 * V_135 ,
struct V_144 * V_145 )
{
struct V_1 * V_2 = F_58 ( V_135 ) ;
unsigned short V_14 ;
V_14 = F_3 ( F_7 ( V_2 , V_157 ) ) & 7 ;
if ( V_14 > 4 )
V_14 = 4 ;
V_145 -> V_5 . V_154 . V_156 [ 0 ] = V_14 ;
return 0 ;
}
static int F_65 ( struct V_134 * V_135 ,
struct V_144 * V_145 )
{
struct V_1 * V_2 = F_58 ( V_135 ) ;
unsigned short V_14 ;
if ( ( V_14 = V_145 -> V_5 . V_154 . V_156 [ 0 ] ) > 4 )
return - V_46 ;
return F_1 ( V_2 , V_158 , 7 , V_14 ) ;
}
static void F_66 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = V_160 -> V_15 ;
V_2 -> V_161 = NULL ;
}
static void F_67 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
if ( V_13 -> V_24 == 0 ) {
V_2 -> V_13 = NULL ;
} else {
V_2 -> V_162 = NULL ;
}
}
static int T_4 F_68 ( struct V_1 * V_2 )
{
struct V_163 V_13 ;
unsigned int V_164 ;
int V_96 ;
static struct V_165 V_166 = {
. V_167 = F_6 ,
. V_168 = F_10 ,
} ;
if ( ( V_96 = V_159 ( V_2 -> V_110 , 0 , & V_166 , V_2 , & V_2 -> V_161 ) ) < 0 )
return V_96 ;
V_2 -> V_161 -> V_169 = F_66 ;
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_15 = V_2 ;
V_13 . V_169 = F_67 ;
if ( ( V_96 = F_69 ( V_2 -> V_161 , & V_13 , & V_2 -> V_13 ) ) < 0 )
return V_96 ;
if ( V_2 -> V_170 ) {
V_13 . V_24 = 1 ;
V_13 . V_22 = V_2 -> V_171 ;
if ( ( V_96 = F_69 ( V_2 -> V_161 , & V_13 , & V_2 -> V_162 ) ) < 0 )
return V_96 ;
}
for ( V_164 = 0 ; V_164 < V_172 ; V_164 ++ )
F_70 ( V_2 -> V_110 , F_71 ( & V_173 [ V_164 ] , V_2 ) ) ;
if ( V_2 -> V_101 ) {
for ( V_164 = 0 ; V_164 < V_174 ; V_164 ++ )
F_70 ( V_2 -> V_110 , F_71 ( & V_175 [ V_164 ] , V_2 ) ) ;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , unsigned int V_176 ,
unsigned short V_3 , unsigned long V_177 )
{
unsigned long V_178 = V_179 + V_177 ;
F_4 ( V_25 | ( V_176 << V_23 ) | V_3 ,
F_7 ( V_2 , V_17 ) ) ;
F_8 ( 5 ) ;
do {
if ( ( F_3 ( F_7 ( V_2 , V_17 ) ) & ( V_27 | V_18 ) )
== V_27 )
return 0 ;
F_73 ( 1 ) ;
} while ( F_74 ( V_178 , V_179 ) );
return - V_180 ;
}
static int F_75 ( struct V_1 * V_2 , int V_181 )
{
unsigned short V_182 ;
if ( V_2 -> V_183 & V_184 )
goto V_185;
F_4 ( ( 1 << 5 ) | ( 1 << 6 ) , F_7 ( V_2 , V_186 ) ) ;
F_3 ( F_7 ( V_2 , V_186 ) ) ;
F_8 ( 100 ) ;
F_4 ( 0 , F_7 ( V_2 , V_186 ) ) ;
if ( F_72 ( V_2 , 0 , V_187 , F_76 ( 750 ) ) < 0 )
if ( ! V_181 ) {
F_9 ( V_188 L_10
L_11 ) ;
V_2 -> V_183 = 3 | V_184 ;
goto V_185;
}
if ( V_2 -> V_101 ) {
if ( V_2 -> V_171 ) {
F_72 ( V_2 , V_2 -> V_171 ,
V_189 , F_76 ( 50 ) ) ;
} else {
int V_164 ;
for ( V_164 = 3 ; V_164 > 0 ; V_164 -- ) {
if ( ! F_72 ( V_2 , V_164 , V_189 ,
F_76 ( 50 ) ) ) {
V_182 = F_3 ( F_7 ( V_2 , V_21 ) ) ;
if ( V_182 != 0xffff && V_182 != 0 ) {
V_2 -> V_170 = 1 ;
V_2 -> V_171 = V_164 ;
break;
}
}
}
}
F_72 ( V_2 , 0 , V_189 , F_76 ( 750 ) ) ;
}
V_185:
F_4 ( 0x0808 , F_7 ( V_2 , V_190 ) ) ;
F_4 ( 0x9f1f , F_7 ( V_2 , V_191 ) ) ;
F_4 ( 0x8808 , F_7 ( V_2 , V_192 ) ) ;
F_4 ( 0x0003 , F_7 ( V_2 , V_193 ) ) ;
V_182 = F_3 ( F_7 ( V_2 , V_194 ) ) ;
if ( V_2 -> V_84 < 0 )
V_182 |= 0x00c3 ;
else
V_182 &= ~ 0x0083 ;
F_4 ( V_182 , F_7 ( V_2 , V_194 ) ) ;
F_4 ( V_82 | V_83 | V_88 , F_7 ( V_2 , V_81 ) ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
unsigned short V_182 ;
if ( V_2 -> V_84 < 0 )
goto V_195;
V_182 = F_3 ( F_7 ( V_2 , V_194 ) ) ;
V_182 |= 0x00c3 ;
F_4 ( V_182 , F_7 ( V_2 , V_194 ) ) ;
V_195:
#ifdef F_78
if ( ! ( V_2 -> V_183 & V_196 ) ) {
F_79 ( & V_2 -> V_120 ) ;
F_80 ( & V_2 -> V_197 ) ;
}
#endif
if ( V_2 -> V_84 >= 0 )
F_81 ( V_2 -> V_84 , V_2 ) ;
F_82 ( V_2 -> V_118 ) ;
F_83 ( V_2 -> V_118 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static int F_85 ( struct V_198 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_199 ;
return F_77 ( V_2 ) ;
}
static int T_4 F_86 ( struct V_200 * V_110 ,
struct V_201 * V_118 ,
int V_183 ,
int V_202 ,
struct V_1 * * V_203 )
{
struct V_1 * V_2 ;
int V_96 ;
static struct V_204 V_166 = {
. V_205 = F_85 ,
} ;
* V_203 = NULL ;
if ( ( V_96 = F_87 ( V_118 ) ) < 0 )
return V_96 ;
V_2 = F_88 ( sizeof( * V_2 ) , V_206 ) ;
if ( V_2 == NULL ) {
F_83 ( V_118 ) ;
return - V_207 ;
}
F_89 ( & V_2 -> V_10 ) ;
V_2 -> V_110 = V_110 ;
V_2 -> V_118 = V_118 ;
V_2 -> V_84 = - 1 ;
V_2 -> V_183 = V_183 ;
if ( ( V_96 = F_90 ( V_118 , L_4 ) ) < 0 ) {
F_84 ( V_2 ) ;
F_83 ( V_118 ) ;
return V_96 ;
}
V_2 -> V_11 = F_91 ( V_118 , 0 ) ;
if ( ( V_183 & V_184 ) == 0 ) {
if ( F_92 ( V_118 -> V_84 , F_35 , V_208 ,
V_209 , V_2 ) ) {
F_9 ( V_20 L_12 , V_2 -> V_84 ) ;
F_77 ( V_2 ) ;
return - V_210 ;
}
V_2 -> V_84 = V_118 -> V_84 ;
F_93 ( V_118 ) ;
}
if ( V_118 -> V_211 >= 0xb1 )
V_2 -> V_101 = 1 ;
F_75 ( V_2 , 0 ) ;
V_183 = V_2 -> V_183 ;
if ( V_2 -> V_84 >= 0 && ( V_183 & V_184 ) ) {
F_94 ( V_118 ) ;
F_81 ( V_2 -> V_84 , V_2 ) ;
V_2 -> V_84 = - 1 ;
}
if ( ( V_96 = F_95 ( V_110 , V_212 , V_2 , & V_166 ) ) < 0 ) {
F_77 ( V_2 ) ;
return V_96 ;
}
F_96 ( V_110 , & V_118 -> V_213 ) ;
#ifdef F_78
V_96 = F_97 ( & V_118 -> V_213 , & V_2 -> V_197 ) ;
if ( V_96 < 0 ) {
F_77 ( V_2 ) ;
return V_96 ;
}
V_2 -> V_120 . V_197 = & V_2 -> V_197 ;
V_2 -> V_120 . V_202 = V_202 ;
V_2 -> V_120 . V_15 = V_2 ;
V_2 -> V_120 . V_166 = & V_214 ;
sprintf ( V_2 -> V_120 . V_215 , L_13 , F_98 ( V_118 ) ) ;
if ( ( V_183 & V_216 ) > 0 &&
( V_183 & V_216 ) < 4 ) {
if ( F_99 ( & V_2 -> V_120 , V_217 ) ) {
F_9 ( V_20 L_14 ) ;
F_77 ( V_2 ) ;
return - V_218 ;
}
} else if ( ( V_183 & V_216 ) == 0 ) {
for ( V_183 = 1 ; V_183 <= 3 ; V_183 ++ ) {
V_2 -> V_183 = V_183 ;
if ( ! F_99 ( & V_2 -> V_120 , V_217 ) ) {
F_9 ( V_188 L_15 ,
F_50 ( V_2 ) -> V_116 ) ;
break;
}
}
if ( V_183 == 4 ) {
F_9 ( V_20 L_14 ) ;
V_2 -> V_183 = V_196 ;
}
}
if ( ! ( V_2 -> V_183 & V_196 ) ) {
F_100 ( V_2 -> V_120 . V_110 , F_50 ( V_2 ) -> V_116 ,
sizeof( V_2 -> V_120 . V_110 ) ) ;
}
#endif
* V_203 = V_2 ;
return 0 ;
}
static int T_4 F_101 ( struct V_201 * V_118 ,
const struct V_219 * V_220 )
{
static int V_213 ;
struct V_200 * V_110 ;
struct V_1 * V_2 ;
struct V_221 * V_222 ;
int V_96 ;
if ( V_213 >= V_223 )
return - V_218 ;
if ( ! V_224 [ V_213 ] ) {
V_213 ++ ;
return - V_225 ;
}
V_96 = F_102 ( V_226 [ V_213 ] , V_227 [ V_213 ] , V_217 , 0 , & V_110 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ( V_96 = F_86 ( V_110 , V_118 , V_183 [ V_213 ] , V_202 [ V_213 ] , & V_2 ) ) < 0 ) {
F_103 ( V_110 ) ;
return V_96 ;
}
V_110 -> V_15 = V_2 ;
strcpy ( V_110 -> V_228 , L_4 ) ;
strcpy ( V_110 -> V_229 , L_16 ) ;
strcat ( V_110 -> V_229 , V_2 -> V_101 ? L_17 : L_18 ) ;
sprintf ( V_110 -> V_230 , L_19 ,
V_110 -> V_229 , V_2 -> V_11 , V_2 -> V_84 ) ;
if ( V_2 -> V_183 & V_184 )
goto V_231;
if ( ( V_96 = F_44 ( V_2 , 0 , NULL ) ) < 0 ) {
F_103 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_68 ( V_2 ) ) < 0 ) {
F_103 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_104 ( V_110 , 0 , V_232 ,
F_7 ( V_2 , V_233 ) ,
V_234 |
V_235 ,
- 1 , & V_2 -> V_94 ) ) < 0 ) {
F_103 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_105 ( V_110 , F_7 ( V_2 , V_236 ) ,
F_7 ( V_2 , V_237 ) ,
V_238 , 1 , & V_222 ) ) < 0 ) {
F_103 ( V_110 ) ;
return V_96 ;
}
if ( ( V_96 = F_106 ( V_222 , 0 , 1 , NULL ) ) < 0 ) {
F_103 ( V_110 ) ;
return V_96 ;
}
V_231:
if ( ( V_96 = F_107 ( V_110 ) ) < 0 ) {
F_103 ( V_110 ) ;
return V_96 ;
}
F_108 ( V_118 , V_110 ) ;
V_213 ++ ;
return 0 ;
}
static void T_6 F_109 ( struct V_201 * V_118 )
{
F_103 ( F_110 ( V_118 ) ) ;
F_108 ( V_118 , NULL ) ;
}
static int F_111 ( struct V_201 * V_118 , T_7 V_239 )
{
struct V_200 * V_110 = F_110 ( V_118 ) ;
struct V_1 * V_2 = V_110 -> V_15 ;
int V_164 ;
F_112 ( V_110 , V_240 ) ;
F_113 ( V_2 -> V_91 ) ;
F_114 ( V_2 -> V_13 ) ;
F_114 ( V_2 -> V_162 ) ;
for ( V_164 = 0 ; V_164 < F_12 ( V_241 ) ; V_164 ++ )
V_2 -> V_241 [ V_164 ] = F_3 ( V_2 -> V_11 + V_241 [ V_164 ] ) ;
F_83 ( V_118 ) ;
F_115 ( V_118 ) ;
F_116 ( V_118 , F_117 ( V_118 , V_239 ) ) ;
return 0 ;
}
static int F_118 ( struct V_201 * V_118 )
{
struct V_200 * V_110 = F_110 ( V_118 ) ;
struct V_1 * V_2 = V_110 -> V_15 ;
int V_164 ;
F_116 ( V_118 , V_242 ) ;
F_119 ( V_118 ) ;
if ( F_87 ( V_118 ) < 0 ) {
F_120 ( V_20 L_20
L_21 ) ;
F_121 ( V_110 ) ;
return - V_180 ;
}
F_93 ( V_118 ) ;
F_75 ( V_2 , 1 ) ;
F_122 ( V_2 -> V_13 ) ;
F_122 ( V_2 -> V_162 ) ;
for ( V_164 = 0 ; V_164 < F_12 ( V_241 ) ; V_164 ++ )
F_4 ( V_2 -> V_241 [ V_164 ] , V_2 -> V_11 + V_241 [ V_164 ] ) ;
F_112 ( V_110 , V_243 ) ;
return 0 ;
}

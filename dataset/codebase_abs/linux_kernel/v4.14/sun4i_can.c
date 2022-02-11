static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
F_3 ( V_3 , V_2 -> V_6 + V_7 ) ;
F_4 ( & V_2 -> V_5 , V_4 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_10 = V_11 ;
T_2 V_12 = 0 ;
do {
V_12 = F_7 ( V_2 -> V_6 + V_13 ) ;
V_12 &= ~ V_14 ;
F_3 ( V_12 , V_2 -> V_6 + V_13 ) ;
} while ( V_10 -- && ( V_12 & V_14 ) );
if ( F_7 ( V_2 -> V_6 + V_13 ) & V_14 ) {
F_8 ( V_9 ,
L_1 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_10 = V_11 ;
T_2 V_12 = 0 ;
do {
V_12 = F_7 ( V_2 -> V_6 + V_13 ) ;
V_12 |= V_14 ;
F_3 ( V_12 , V_2 -> V_6 + V_13 ) ;
} while ( V_10 -- && ! ( V_12 & V_14 ) );
if ( ! ( F_7 ( V_2 -> V_6 + V_13 ) &
V_14 ) ) {
F_8 ( V_9 , L_2 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_16 * V_17 = & V_2 -> V_18 . V_19 ;
T_2 V_20 ;
V_20 = ( ( V_17 -> V_21 - 1 ) & 0x3FF ) |
( ( ( V_17 -> V_22 - 1 ) & 0x3 ) << 14 ) |
( ( ( V_17 -> V_23 + V_17 -> V_24 - 1 ) & 0xf ) << 16 ) |
( ( ( V_17 -> V_25 - 1 ) & 0x7 ) << 20 ) ;
if ( V_2 -> V_18 . V_26 & V_27 )
V_20 |= 0x800000 ;
F_11 ( V_9 , L_3 , V_20 ) ;
F_3 ( V_20 , V_2 -> V_6 + V_28 ) ;
return 0 ;
}
static int F_12 ( const struct V_8 * V_9 ,
struct V_29 * V_30 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_2 V_31 ;
int V_32 ;
V_32 = F_13 ( V_2 -> V_33 ) ;
if ( V_32 ) {
F_8 ( V_9 , L_4 ) ;
return V_32 ;
}
V_31 = F_7 ( V_2 -> V_6 + V_34 ) ;
V_30 -> V_35 = V_31 & 0xFF ;
V_30 -> V_36 = ( V_31 >> 16 ) & 0xFF ;
F_14 ( V_2 -> V_33 ) ;
return 0 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_32 ;
T_2 V_12 ;
V_32 = F_9 ( V_9 ) ;
if ( V_32 ) {
F_8 ( V_9 , L_5 ) ;
return V_32 ;
}
F_3 ( 0x00000000 , V_2 -> V_6 + V_37 ) ;
F_3 ( 0xFFFFFFFF , V_2 -> V_6 + V_38 ) ;
F_3 ( 0 , V_2 -> V_6 + V_34 ) ;
if ( V_2 -> V_18 . V_26 & V_39 )
F_3 ( 0xFF , V_2 -> V_6 + V_40 ) ;
else
F_3 ( 0xFF & ~ V_41 ,
V_2 -> V_6 + V_40 ) ;
V_12 = F_7 ( V_2 -> V_6 + V_13 ) ;
if ( V_2 -> V_18 . V_26 & V_42 )
V_12 |= V_43 ;
else if ( V_2 -> V_18 . V_26 & V_44 )
V_12 |= V_45 ;
F_3 ( V_12 , V_2 -> V_6 + V_13 ) ;
V_32 = F_10 ( V_9 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_5 ( V_9 ) ;
if ( V_32 ) {
F_8 ( V_9 , L_6 ) ;
return V_32 ;
}
V_2 -> V_18 . V_46 = V_47 ;
return 0 ;
}
static int F_16 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_32 ;
V_2 -> V_18 . V_46 = V_48 ;
V_32 = F_9 ( V_9 ) ;
if ( V_32 ) {
F_8 ( V_9 , L_5 ) ;
return V_32 ;
}
F_3 ( 0 , V_2 -> V_6 + V_40 ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 , enum V_49 V_50 )
{
int V_32 ;
switch ( V_50 ) {
case V_51 :
V_32 = F_15 ( V_9 ) ;
if ( V_32 ) {
F_8 ( V_9 , L_7 ) ;
return V_32 ;
}
if ( F_18 ( V_9 ) )
F_19 ( V_9 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_20 ( struct V_53 * V_54 , struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_55 * V_56 = (struct V_55 * ) V_54 -> V_57 ;
T_1 V_58 ;
T_2 V_59 , V_60 ;
T_3 V_61 ;
int V_62 ;
if ( F_21 ( V_9 , V_54 ) )
return V_63 ;
F_22 ( V_9 ) ;
V_61 = V_56 -> V_64 ;
V_58 = V_56 -> V_65 ;
V_60 = V_58 ;
if ( V_61 & V_66 )
V_60 |= V_67 ;
if ( V_61 & V_68 ) {
V_60 |= V_69 ;
V_59 = V_70 ;
F_3 ( ( V_61 >> 21 ) & 0xFF , V_2 -> V_6 + V_71 ) ;
F_3 ( ( V_61 >> 13 ) & 0xFF , V_2 -> V_6 + V_72 ) ;
F_3 ( ( V_61 >> 5 ) & 0xFF , V_2 -> V_6 + V_73 ) ;
F_3 ( ( V_61 << 3 ) & 0xF8 , V_2 -> V_6 + V_74 ) ;
} else {
V_59 = V_73 ;
F_3 ( ( V_61 >> 3 ) & 0xFF , V_2 -> V_6 + V_71 ) ;
F_3 ( ( V_61 << 5 ) & 0xE0 , V_2 -> V_6 + V_72 ) ;
}
for ( V_62 = 0 ; V_62 < V_58 ; V_62 ++ )
F_3 ( V_56 -> V_57 [ V_62 ] , V_2 -> V_6 + ( V_59 + V_62 * 4 ) ) ;
F_3 ( V_60 , V_2 -> V_6 + V_75 ) ;
F_23 ( V_54 , V_9 , 0 ) ;
if ( V_2 -> V_18 . V_26 & V_42 )
F_1 ( V_2 , V_76 ) ;
else
F_1 ( V_2 , V_77 ) ;
return V_63 ;
}
static void F_24 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_78 * V_79 = & V_9 -> V_79 ;
struct V_55 * V_56 ;
struct V_53 * V_54 ;
T_1 V_80 ;
T_2 V_59 ;
T_3 V_61 ;
int V_62 ;
V_54 = F_25 ( V_9 , & V_56 ) ;
if ( ! V_54 )
return;
V_80 = F_7 ( V_2 -> V_6 + V_75 ) ;
V_56 -> V_65 = F_26 ( V_80 & 0x0F ) ;
if ( V_80 & V_69 ) {
V_59 = V_70 ;
V_61 = ( F_7 ( V_2 -> V_6 + V_71 ) << 21 ) |
( F_7 ( V_2 -> V_6 + V_72 ) << 13 ) |
( F_7 ( V_2 -> V_6 + V_73 ) << 5 ) |
( ( F_7 ( V_2 -> V_6 + V_74 ) >> 3 ) & 0x1f ) ;
V_61 |= V_68 ;
} else {
V_59 = V_73 ;
V_61 = ( F_7 ( V_2 -> V_6 + V_71 ) << 3 ) |
( ( F_7 ( V_2 -> V_6 + V_72 ) >> 5 ) & 0x7 ) ;
}
if ( V_80 & V_67 )
V_61 |= V_66 ;
else
for ( V_62 = 0 ; V_62 < V_56 -> V_65 ; V_62 ++ )
V_56 -> V_57 [ V_62 ] = F_7 ( V_2 -> V_6 + V_59 + V_62 * 4 ) ;
V_56 -> V_64 = V_61 ;
F_1 ( V_2 , V_81 ) ;
V_79 -> V_82 ++ ;
V_79 -> V_83 += V_56 -> V_65 ;
F_27 ( V_54 ) ;
F_28 ( V_9 , V_84 ) ;
}
static int F_29 ( struct V_8 * V_9 , T_1 V_85 , T_1 V_86 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_78 * V_79 = & V_9 -> V_79 ;
struct V_55 * V_56 ;
struct V_53 * V_54 ;
enum V_87 V_46 = V_2 -> V_18 . V_46 ;
enum V_87 V_88 , V_89 ;
unsigned int V_36 , V_35 , V_90 ;
T_2 V_91 , V_92 ;
V_54 = F_30 ( V_9 , & V_56 ) ;
V_90 = F_7 ( V_2 -> V_6 + V_34 ) ;
V_36 = ( V_90 >> 16 ) & 0xFF ;
V_35 = V_90 & 0xFF ;
if ( V_54 ) {
V_56 -> V_57 [ 6 ] = V_35 ;
V_56 -> V_57 [ 7 ] = V_36 ;
}
if ( V_85 & V_93 ) {
F_11 ( V_9 , L_8 ) ;
if ( F_31 ( V_54 ) ) {
V_56 -> V_64 |= V_94 ;
V_56 -> V_57 [ 1 ] = V_95 ;
}
V_79 -> V_96 ++ ;
V_79 -> V_97 ++ ;
F_9 ( V_9 ) ;
F_5 ( V_9 ) ;
F_1 ( V_2 , V_98 ) ;
}
if ( V_85 & V_99 ) {
F_11 ( V_9 , L_9 ) ;
if ( V_86 & V_100 )
V_46 = V_101 ;
else if ( V_86 & V_102 )
V_46 = V_103 ;
else
V_46 = V_47 ;
}
if ( V_85 & V_104 ) {
F_11 ( V_9 , L_10 ) ;
V_2 -> V_18 . V_105 . V_106 ++ ;
V_79 -> V_97 ++ ;
if ( F_31 ( V_54 ) ) {
V_91 = F_7 ( V_2 -> V_6 + V_107 ) ;
V_56 -> V_64 |= V_108 | V_109 ;
switch ( V_91 & V_110 ) {
case V_111 :
V_56 -> V_57 [ 2 ] |= V_112 ;
break;
case V_113 :
V_56 -> V_57 [ 2 ] |= V_114 ;
break;
case V_115 :
V_56 -> V_57 [ 2 ] |= V_116 ;
break;
default:
V_56 -> V_57 [ 3 ] = ( V_91 & V_117 )
>> 16 ;
break;
}
if ( ( V_91 & V_118 ) == 0 )
V_56 -> V_57 [ 2 ] |= V_119 ;
}
}
if ( V_85 & V_120 ) {
F_11 ( V_9 , L_11 ) ;
if ( V_46 == V_121 )
V_46 = V_103 ;
else
V_46 = V_121 ;
}
if ( V_85 & V_122 ) {
F_11 ( V_9 , L_12 ) ;
V_92 = F_7 ( V_2 -> V_6 + V_107 ) ;
V_2 -> V_18 . V_105 . V_123 ++ ;
V_79 -> V_124 ++ ;
if ( F_31 ( V_54 ) ) {
V_56 -> V_64 |= V_125 ;
V_56 -> V_57 [ 0 ] = ( V_92 >> 8 ) & 0x1f ;
}
}
if ( V_46 != V_2 -> V_18 . V_46 ) {
V_89 = V_35 >= V_36 ? V_46 : 0 ;
V_88 = V_35 <= V_36 ? V_46 : 0 ;
if ( F_31 ( V_54 ) )
F_32 ( V_9 , V_56 , V_89 , V_88 ) ;
else
V_2 -> V_18 . V_46 = V_46 ;
if ( V_46 == V_101 )
F_33 ( V_9 ) ;
}
if ( F_31 ( V_54 ) ) {
V_79 -> V_82 ++ ;
V_79 -> V_83 += V_56 -> V_65 ;
F_27 ( V_54 ) ;
} else {
return - V_126 ;
}
return 0 ;
}
static T_4 F_34 ( int V_127 , void * V_128 )
{
struct V_8 * V_9 = (struct V_8 * ) V_128 ;
struct V_1 * V_2 = F_6 ( V_9 ) ;
struct V_78 * V_79 = & V_9 -> V_79 ;
T_1 V_85 , V_86 ;
int V_129 = 0 ;
while ( ( V_85 = F_7 ( V_2 -> V_6 + V_130 ) ) &&
( V_129 < V_131 ) ) {
V_129 ++ ;
V_86 = F_7 ( V_2 -> V_6 + V_107 ) ;
if ( V_85 & V_132 )
F_35 ( V_9 , L_13 ) ;
if ( V_85 & V_133 ) {
V_79 -> V_134 +=
F_7 ( V_2 -> V_6 +
V_135 ) & 0xf ;
V_79 -> V_136 ++ ;
F_36 ( V_9 , 0 ) ;
F_19 ( V_9 ) ;
F_28 ( V_9 , V_137 ) ;
}
if ( ( V_85 & V_138 ) &&
! ( V_85 & V_93 ) ) {
while ( V_86 & V_139 ) {
F_24 ( V_9 ) ;
V_86 = F_7 ( V_2 -> V_6 + V_107 ) ;
}
}
if ( V_85 &
( V_93 | V_99 | V_104 |
V_120 | V_122 ) ) {
if ( F_29 ( V_9 , V_85 , V_86 ) )
F_8 ( V_9 , L_14 ) ;
}
F_3 ( V_85 , V_2 -> V_6 + V_130 ) ;
F_7 ( V_2 -> V_6 + V_130 ) ;
}
if ( V_129 >= V_131 )
F_11 ( V_9 , L_15 , V_129 ) ;
return ( V_129 ) ? V_140 : V_141 ;
}
static int F_37 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
int V_32 ;
V_32 = F_38 ( V_9 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_39 ( V_9 -> V_127 , F_34 , 0 , V_9 -> V_142 , V_9 ) ;
if ( V_32 ) {
F_8 ( V_9 , L_16 , V_32 ) ;
goto V_143;
}
V_32 = F_13 ( V_2 -> V_33 ) ;
if ( V_32 ) {
F_8 ( V_9 , L_17 ) ;
goto V_144;
}
V_32 = F_15 ( V_9 ) ;
if ( V_32 ) {
F_8 ( V_9 , L_18 ) ;
goto V_145;
}
F_28 ( V_9 , V_146 ) ;
F_40 ( V_9 ) ;
return 0 ;
V_145:
F_14 ( V_2 -> V_33 ) ;
V_144:
F_41 ( V_9 -> V_127 , V_9 ) ;
V_143:
F_42 ( V_9 ) ;
return V_32 ;
}
static int F_43 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_22 ( V_9 ) ;
F_16 ( V_9 ) ;
F_14 ( V_2 -> V_33 ) ;
F_41 ( V_9 -> V_127 , V_9 ) ;
F_42 ( V_9 ) ;
F_28 ( V_9 , V_147 ) ;
return 0 ;
}
static int F_44 ( struct V_148 * V_149 )
{
struct V_8 * V_9 = F_45 ( V_149 ) ;
F_46 ( V_9 ) ;
F_47 ( V_9 ) ;
return 0 ;
}
static int F_48 ( struct V_148 * V_149 )
{
struct V_150 * V_151 = V_149 -> V_9 . V_152 ;
struct V_153 * V_154 ;
struct V_33 * V_33 ;
void T_5 * V_155 ;
int V_32 , V_127 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
V_33 = F_49 ( V_151 , 0 ) ;
if ( F_50 ( V_33 ) ) {
F_51 ( & V_149 -> V_9 , L_19 ) ;
V_32 = - V_156 ;
goto exit;
}
V_127 = F_52 ( V_149 , 0 ) ;
if ( V_127 < 0 ) {
F_51 ( & V_149 -> V_9 , L_20 ) ;
V_32 = - V_156 ;
goto exit;
}
V_154 = F_53 ( V_149 , V_157 , 0 ) ;
V_155 = F_54 ( & V_149 -> V_9 , V_154 ) ;
if ( F_50 ( V_155 ) ) {
V_32 = - V_158 ;
goto exit;
}
V_9 = F_55 ( sizeof( struct V_1 ) , 1 ) ;
if ( ! V_9 ) {
F_51 ( & V_149 -> V_9 ,
L_21 ) ;
V_32 = - V_126 ;
goto exit;
}
V_9 -> V_159 = & V_160 ;
V_9 -> V_127 = V_127 ;
V_9 -> V_4 |= V_161 ;
V_2 = F_6 ( V_9 ) ;
V_2 -> V_18 . clock . V_162 = F_56 ( V_33 ) ;
V_2 -> V_18 . V_163 = & V_164 ;
V_2 -> V_18 . V_165 = F_17 ;
V_2 -> V_18 . V_166 = F_12 ;
V_2 -> V_18 . V_167 = V_39 |
V_44 |
V_42 |
V_27 ;
V_2 -> V_6 = V_155 ;
V_2 -> V_33 = V_33 ;
F_57 ( & V_2 -> V_5 ) ;
F_58 ( V_149 , V_9 ) ;
F_59 ( V_9 , & V_149 -> V_9 ) ;
V_32 = F_60 ( V_9 ) ;
if ( V_32 ) {
F_51 ( & V_149 -> V_9 , L_22 ,
V_168 , V_32 ) ;
goto V_169;
}
F_61 ( V_9 ) ;
F_62 ( & V_149 -> V_9 , L_23 ,
V_2 -> V_6 , V_9 -> V_127 ) ;
return 0 ;
V_169:
F_47 ( V_9 ) ;
exit:
return V_32 ;
}

static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 -> V_6 , F_3 ( V_3 ) , V_4 ) ;
if ( V_5 < 0 )
F_4 ( V_2 -> V_7 ,
L_1 ) ;
return V_5 ;
}
static T_1
F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_5 ;
T_1 V_4 ;
V_5 = F_6 ( V_2 -> V_6 , F_3 ( V_3 ) , & V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_7 ,
L_2 ) ;
return V_5 ;
}
return V_4 ;
}
static void
F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_8 , T_1 V_9 )
{
T_1 V_4 ;
V_4 = F_5 ( V_2 , V_3 ) ;
V_4 &= ~ V_8 ;
V_4 |= V_9 ;
F_1 ( V_2 , V_3 , V_4 ) ;
}
static void
F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_7 ( V_2 , V_3 , 0 , V_4 ) ;
}
static void
F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_7 ( V_2 , V_3 , V_4 , 0 ) ;
}
static int
F_10 ( struct V_1 * V_2 , int V_10 , int V_11 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_14 , V_5 ;
V_5 = V_13 -> V_15 ( V_13 , 0 , V_16 , V_11 ) ;
if ( V_5 < 0 )
goto V_17;
V_5 = V_13 -> V_15 ( V_13 , 0 , V_18 , V_10 ) ;
if ( V_5 < 0 )
goto V_17;
V_5 = V_13 -> V_15 ( V_13 , 0 , V_16 , ( V_11 | V_19 ) ) ;
if ( V_5 < 0 )
goto V_17;
V_14 = V_13 -> V_20 ( V_13 , 0 , V_18 ) ;
return V_14 ;
V_17:
F_4 ( & V_13 -> V_7 , L_3 ) ;
return V_5 ;
}
static int
F_11 ( struct V_1 * V_2 , int V_10 ,
int V_11 , T_1 V_21 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
int V_5 ;
V_5 = V_13 -> V_15 ( V_13 , 0 , V_16 , V_11 ) ;
if ( V_5 < 0 )
goto V_17;
V_5 = V_13 -> V_15 ( V_13 , 0 , V_18 , V_10 ) ;
if ( V_5 < 0 )
goto V_17;
V_5 = V_13 -> V_15 ( V_13 , 0 , V_16 , ( V_11 | V_19 ) ) ;
if ( V_5 < 0 )
goto V_17;
V_5 = V_13 -> V_15 ( V_13 , 0 , V_18 , V_21 ) ;
V_17:
if ( V_5 < 0 )
F_4 ( & V_13 -> V_7 ,
L_4 ) ;
return V_5 ;
}
static void
F_12 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_13 ( & V_13 -> V_22 , V_23 ) ;
F_11 ( V_2 , V_3 , V_24 , V_4 ) ;
F_14 ( & V_13 -> V_22 ) ;
}
static void
F_15 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_8 , T_1 V_9 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_4 ;
F_13 ( & V_13 -> V_22 , V_23 ) ;
V_4 = F_10 ( V_2 , V_3 , V_24 ) ;
V_4 &= ~ V_8 ;
V_4 |= V_9 ;
F_11 ( V_2 , V_3 , V_24 , V_4 ) ;
F_14 ( & V_13 -> V_22 ) ;
}
static void
F_16 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_15 ( V_2 , V_3 , 0 , V_4 ) ;
}
static void
F_17 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_15 ( V_2 , V_3 , V_4 , 0 ) ;
}
static int
F_18 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_2 V_25 , V_26 , V_27 , V_28 ;
int V_5 ;
V_25 = ( V_3 >> 6 ) & 0x3ff ;
V_26 = ( V_3 >> 2 ) & 0xf ;
V_27 = V_4 & 0xffff ;
V_28 = V_4 >> 16 ;
V_5 = V_13 -> V_15 ( V_13 , 0x1f , 0x1f , V_25 ) ;
if ( V_5 < 0 )
goto V_17;
V_5 = V_13 -> V_15 ( V_13 , 0x1f , V_26 , V_27 ) ;
if ( V_5 < 0 )
goto V_17;
V_5 = V_13 -> V_15 ( V_13 , 0x1f , 0x10 , V_28 ) ;
V_17:
if ( V_5 < 0 )
F_4 ( & V_13 -> V_7 ,
L_5 ) ;
return V_5 ;
}
static T_1
F_19 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_2 V_25 , V_26 , V_27 , V_28 ;
int V_5 ;
V_25 = ( V_3 >> 6 ) & 0x3ff ;
V_26 = ( V_3 >> 2 ) & 0xf ;
V_5 = V_13 -> V_15 ( V_13 , 0x1f , 0x1f , V_25 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_13 -> V_7 ,
L_6 ) ;
return V_5 ;
}
V_27 = V_13 -> V_20 ( V_13 , 0x1f , V_26 ) ;
V_28 = V_13 -> V_20 ( V_13 , 0x1f , 0x10 ) ;
return ( V_28 << 16 ) | ( V_27 & 0xffff ) ;
}
static void
F_20 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
F_13 ( & V_13 -> V_22 , V_23 ) ;
F_18 ( V_2 , V_3 , V_4 ) ;
F_14 ( & V_13 -> V_22 ) ;
}
static T_1
F_21 ( struct V_29 * V_30 )
{
struct V_12 * V_13 = V_30 -> V_2 -> V_13 ;
T_1 V_4 ;
F_13 ( & V_13 -> V_22 , V_23 ) ;
V_4 = F_19 ( V_30 -> V_2 , V_30 -> V_3 ) ;
F_14 ( & V_13 -> V_22 ) ;
return V_4 ;
}
static T_1
F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_29 V_30 ;
F_23 ( & V_30 , V_2 , V_3 ) ;
return F_21 ( & V_30 ) ;
}
static void
F_24 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_8 , T_1 V_9 )
{
struct V_12 * V_13 = V_2 -> V_13 ;
T_1 V_4 ;
F_13 ( & V_13 -> V_22 , V_23 ) ;
V_4 = F_19 ( V_2 , V_3 ) ;
V_4 &= ~ V_8 ;
V_4 |= V_9 ;
F_18 ( V_2 , V_3 , V_4 ) ;
F_14 ( & V_13 -> V_22 ) ;
}
static void
F_25 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_24 ( V_2 , V_3 , 0 , V_4 ) ;
}
static void
F_26 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_24 ( V_2 , V_3 , V_4 , 0 ) ;
}
static int
F_27 ( struct V_1 * V_2 , enum F_27 V_31 , T_1 * V_32 )
{
T_1 V_4 ;
int V_5 ;
struct V_29 V_30 ;
V_4 = V_33 | F_28 ( 0 ) | V_31 ;
F_20 ( V_2 , V_34 , V_4 ) ;
F_23 ( & V_30 , V_2 , V_34 ) ;
V_5 = F_29 ( F_21 , & V_30 , V_4 ,
! ( V_4 & V_33 ) , 20 , 20000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_7 , L_7 ) ;
return V_5 ;
}
V_4 = F_22 ( V_2 , V_34 ) ;
if ( ( V_31 == V_35 ) && ( V_4 & V_36 ) )
return - V_37 ;
if ( V_32 )
* V_32 = V_4 ;
return 0 ;
}
static void
F_30 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
T_1 V_3 [ 3 ] ;
int V_40 ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ ) {
V_3 [ V_40 ] = F_22 ( V_2 , V_41 + ( V_40 * 4 ) ) ;
F_31 ( V_2 -> V_7 , L_8 ,
V_42 , __LINE__ , V_40 , V_3 [ V_40 ] ) ;
}
V_39 -> V_43 = ( V_3 [ 1 ] >> V_44 ) & V_45 ;
V_39 -> V_46 = ( V_3 [ 2 ] >> V_47 ) & V_48 ;
V_39 -> V_49 = ( V_3 [ 2 ] >> V_50 ) & V_51 ;
V_39 -> V_52 [ 0 ] = ( V_3 [ 0 ] >> V_53 ) & V_54 ;
V_39 -> V_52 [ 1 ] = ( V_3 [ 0 ] >> V_55 ) & V_54 ;
V_39 -> V_52 [ 2 ] = ( V_3 [ 0 ] >> V_56 ) & V_54 ;
V_39 -> V_52 [ 3 ] = ( V_3 [ 0 ] >> V_57 ) & V_54 ;
V_39 -> V_52 [ 4 ] = ( V_3 [ 1 ] >> V_58 ) & V_54 ;
V_39 -> V_52 [ 5 ] = ( V_3 [ 1 ] >> V_59 ) & V_54 ;
V_39 -> V_60 = ( ( V_3 [ 2 ] >> V_61 ) & V_62 ) == V_63 ;
}
static void
F_32 ( struct V_1 * V_2 , T_2 V_43 ,
T_3 V_49 , const T_3 * V_52 ,
T_3 V_46 , T_3 type )
{
T_1 V_3 [ 3 ] = { 0 } ;
int V_40 ;
V_3 [ 1 ] |= V_43 & V_45 ;
V_3 [ 2 ] |= ( V_46 & V_48 ) << V_47 ;
V_3 [ 2 ] |= ( V_49 & V_51 ) << V_50 ;
V_3 [ 2 ] |= ( type & V_62 ) << V_61 ;
V_3 [ 1 ] |= V_52 [ 5 ] << V_59 ;
V_3 [ 1 ] |= V_52 [ 4 ] << V_58 ;
V_3 [ 0 ] |= V_52 [ 3 ] << V_57 ;
V_3 [ 0 ] |= V_52 [ 2 ] << V_56 ;
V_3 [ 0 ] |= V_52 [ 1 ] << V_55 ;
V_3 [ 0 ] |= V_52 [ 0 ] << V_53 ;
for ( V_40 = 0 ; V_40 < 3 ; V_40 ++ )
F_20 ( V_2 , V_64 + ( V_40 * 4 ) , V_3 [ V_40 ] ) ;
}
static int
F_33 ( struct V_65 * V_66 , int V_67 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_68 , V_69 , V_70 , V_40 ;
switch ( V_67 ) {
case V_71 :
V_70 = 0 ;
V_68 = 0x0c80 ;
V_69 = 0x87 ;
break;
case V_72 :
V_70 = 1 ;
V_68 = 0x1400 ;
V_69 = 0x57 ;
break;
default:
F_4 ( V_2 -> V_7 , L_9 , V_67 ) ;
return - V_37 ;
}
F_24 ( V_2 , V_73 , V_74 ,
F_34 ( V_70 ) ) ;
for ( V_40 = 0 ; V_40 < V_75 ; V_40 ++ )
F_20 ( V_2 , F_35 ( V_40 ) ,
F_36 ( 8 ) | F_37 ( 8 ) ) ;
if ( ! V_70 ) {
F_17 ( V_2 , V_76 , V_77 ) ;
F_11 ( V_2 ,
V_78 ,
V_24 ,
0 ) ;
F_12 ( V_2 , V_79 ,
F_38 ( 1 ) |
F_39 ( 25 ) ) ;
F_12 ( V_2 , V_78 ,
V_80 |
F_40 ( 2 ) |
F_41 ( 32 ) ) ;
F_16 ( V_2 , V_76 , V_77 ) ;
}
F_16 ( V_2 , V_76 , V_77 ) ;
F_12 ( V_2 , V_81 , F_42 ( V_68 ) ) ;
F_12 ( V_2 , V_82 , F_43 ( 0 ) ) ;
F_12 ( V_2 , V_83 , F_44 ( V_69 ) ) ;
F_12 ( V_2 , V_84 , F_45 ( V_69 ) ) ;
F_12 ( V_2 , V_85 ,
V_86 | V_87 |
V_88 ) ;
F_12 ( V_2 , V_89 ,
V_90 | V_91 |
F_46 ( 1 ) ) ;
F_12 ( V_2 , V_92 ,
V_93 | F_47 ( 3 ) |
V_94 | V_95 ) ;
F_16 ( V_2 , V_76 ,
V_77 | V_96 ) ;
if ( ! V_70 )
for ( V_40 = 0 ; V_40 < V_75 ; V_40 ++ )
F_24 ( V_2 , F_48 ( V_40 ) ,
V_97 , F_49 ( 16 ) ) ;
else
F_8 ( V_2 , V_98 , V_99 ) ;
return 0 ;
}
static int
F_50 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_75 ; V_40 ++ )
F_1 ( V_2 , F_51 ( V_40 ) ,
F_36 ( 8 ) | F_37 ( 8 ) ) ;
F_8 ( V_2 , V_100 , V_101 | V_102 ) ;
F_9 ( V_2 , V_100 , V_101 ) ;
return 0 ;
}
static void
F_52 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
F_20 ( V_2 , V_103 , V_104 ) ;
F_20 ( V_2 , V_103 , V_105 ) ;
}
static void
F_53 ( struct V_1 * V_2 , int V_106 , int V_107 )
{
T_1 V_8 = V_108 | V_109 ;
if ( V_107 )
F_25 ( V_2 , F_54 ( V_106 ) , V_8 ) ;
else
F_26 ( V_2 , F_54 ( V_106 ) , V_8 ) ;
}
static int F_55 ( struct V_65 * V_66 , int V_106 , int V_110 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
return F_56 ( V_2 -> V_13 , V_106 , V_110 ) ;
}
int F_57 ( struct V_65 * V_66 , int V_106 , int V_110 , T_2 V_4 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
return F_58 ( V_2 -> V_13 , V_106 , V_110 , V_4 ) ;
}
static void
F_59 ( struct V_65 * V_66 , int V_106 , T_4 * V_21 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < F_60 ( V_111 ) ; V_40 ++ )
strncpy ( V_21 + V_40 * V_112 , V_111 [ V_40 ] . V_113 ,
V_112 ) ;
}
static void
F_61 ( struct V_65 * V_66 , int V_106 ,
T_5 * V_21 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
const struct V_114 * V_115 ;
T_1 V_3 , V_40 ;
T_6 V_28 ;
for ( V_40 = 0 ; V_40 < F_60 ( V_111 ) ; V_40 ++ ) {
V_115 = & V_111 [ V_40 ] ;
V_3 = F_62 ( V_106 ) + V_115 -> V_116 ;
V_21 [ V_40 ] = F_22 ( V_2 , V_3 ) ;
if ( V_115 -> V_117 == 2 ) {
V_28 = F_22 ( V_2 , V_3 + 4 ) ;
V_21 [ V_40 ] |= V_28 << 32 ;
}
}
}
static int
F_63 ( struct V_65 * V_66 )
{
return F_60 ( V_111 ) ;
}
static void F_64 ( struct V_65 * V_66 , int V_106 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
if ( F_65 ( V_119 ) ) {
F_31 ( V_2 -> V_7 , L_10 ,
V_119 -> V_120 ) ;
F_33 ( V_66 , V_119 -> V_120 ) ;
F_50 ( V_66 ) ;
} else {
T_2 V_121 = 0 , V_122 = 0 ;
T_3 V_123 ;
T_1 V_124 = V_125 | V_126 ;
switch ( V_119 -> V_127 ) {
case V_128 :
V_124 |= V_129 ;
break;
case V_130 :
V_124 |= V_131 ;
break;
} ;
if ( V_119 -> V_132 )
V_124 |= V_133 ;
if ( V_119 -> V_134 ) {
V_124 |= V_135 ;
if ( V_119 -> V_136 )
V_122 = V_137 ;
if ( V_119 -> V_138 )
V_122 |= V_139 ;
if ( V_119 -> V_140 & V_141 )
V_121 |= V_142 ;
if ( V_119 -> V_140 & V_143 )
V_121 |= V_144 ;
V_123 = F_66 ( V_121 , V_122 ) ;
if ( V_123 & V_145 )
V_124 |= V_146 ;
if ( V_123 & V_147 )
V_124 |= V_148 ;
}
F_20 ( V_2 , F_54 ( V_106 ) , V_124 ) ;
}
}
static int
F_67 ( struct V_1 * V_2 ,
int V_106 )
{
F_20 ( V_2 , F_68 ( V_106 ) ,
V_149 ) ;
F_20 ( V_2 , F_54 ( V_106 ) , V_150 ) ;
F_25 ( V_2 , F_69 ( V_106 ) , V_151 ) ;
F_25 ( V_2 , V_152 , F_70 ( F_71 ( V_106 ) ) ) ;
F_20 ( V_2 , F_72 ( V_106 ) ,
F_73 ( V_2 -> V_66 -> V_153 ) ) ;
return 0 ;
}
static int
F_74 ( struct V_65 * V_66 , int V_106 ,
struct V_118 * V_154 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
F_75 ( & V_2 -> V_155 ) ;
F_20 ( V_2 , F_54 ( V_106 ) , V_125 ) ;
V_2 -> V_156 [ V_106 ] . V_157 |= F_73 ( F_71 ( V_158 ) ) ;
V_2 -> V_156 [ V_106 ] . V_107 = true ;
F_24 ( V_2 , F_72 ( V_106 ) , V_159 ,
V_2 -> V_156 [ V_106 ] . V_157 ) ;
F_53 ( V_2 , V_106 , 1 ) ;
F_14 ( & V_2 -> V_155 ) ;
return 0 ;
}
static void
F_76 ( struct V_65 * V_66 , int V_106 ,
struct V_118 * V_154 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
F_75 ( & V_2 -> V_155 ) ;
V_2 -> V_156 [ V_106 ] . V_107 = false ;
F_24 ( V_2 , F_72 ( V_106 ) , V_159 ,
V_160 ) ;
F_53 ( V_2 , V_106 , 0 ) ;
F_14 ( & V_2 -> V_155 ) ;
}
static void
F_77 ( struct V_65 * V_66 , int V_106 , T_3 V_161 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_162 ;
switch ( V_161 ) {
case V_163 :
V_162 = V_164 ;
break;
case V_165 :
V_162 = V_166 ;
break;
case V_167 :
V_162 = V_168 ;
break;
case V_169 :
V_162 = V_170 ;
break;
case V_171 :
default:
V_162 = V_172 ;
break;
}
F_24 ( V_2 , F_78 ( V_106 ) , V_173 , V_162 ) ;
}
static int
F_79 ( struct V_65 * V_66 , int V_106 ,
struct V_174 * V_175 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_1 V_176 = F_71 ( V_158 ) ;
int V_40 ;
F_75 ( & V_2 -> V_155 ) ;
for ( V_40 = 0 ; V_40 < V_177 ; V_40 ++ ) {
if ( V_66 -> V_153 & F_71 ( V_40 ) && V_40 != V_106 ) {
if ( V_66 -> V_156 [ V_40 ] . V_178 != V_175 )
continue;
if ( V_2 -> V_156 [ V_40 ] . V_107 )
F_25 ( V_2 , F_72 ( V_40 ) ,
F_73 ( F_71 ( V_106 ) ) ) ;
V_2 -> V_156 [ V_40 ] . V_157 |= F_73 ( F_71 ( V_106 ) ) ;
V_176 |= F_71 ( V_40 ) ;
}
}
if ( V_2 -> V_156 [ V_106 ] . V_107 )
F_24 ( V_2 , F_72 ( V_106 ) ,
V_159 , F_73 ( V_176 ) ) ;
V_2 -> V_156 [ V_106 ] . V_157 |= F_73 ( V_176 ) ;
F_14 ( & V_2 -> V_155 ) ;
return 0 ;
}
static void
F_80 ( struct V_65 * V_66 , int V_106 ,
struct V_174 * V_175 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
int V_40 ;
F_75 ( & V_2 -> V_155 ) ;
for ( V_40 = 0 ; V_40 < V_177 ; V_40 ++ ) {
if ( V_66 -> V_153 & F_71 ( V_40 ) && V_40 != V_106 ) {
if ( V_66 -> V_156 [ V_40 ] . V_178 != V_175 )
continue;
if ( V_2 -> V_156 [ V_40 ] . V_107 )
F_26 ( V_2 , F_72 ( V_40 ) ,
F_73 ( F_71 ( V_106 ) ) ) ;
V_2 -> V_156 [ V_40 ] . V_157 &= ~ F_73 ( F_71 ( V_106 ) ) ;
}
}
if ( V_2 -> V_156 [ V_106 ] . V_107 )
F_24 ( V_2 , F_72 ( V_106 ) , V_159 ,
F_73 ( F_71 ( V_158 ) ) ) ;
V_2 -> V_156 [ V_106 ] . V_157 = F_73 ( F_71 ( V_158 ) ) ;
F_14 ( & V_2 -> V_155 ) ;
}
static int
F_81 ( struct V_65 * V_66 , int V_106 ,
const struct V_179 * V_39 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
int V_5 ;
F_75 ( & V_2 -> V_155 ) ;
F_32 ( V_2 , V_39 -> V_43 , 0 , V_39 -> V_182 , - 1 , V_63 ) ;
V_5 = F_27 ( V_2 , V_183 , 0 ) ;
F_14 ( & V_2 -> V_155 ) ;
return V_5 ;
}
static void
F_82 ( struct V_65 * V_66 , int V_106 ,
const struct V_179 * V_39 ,
struct V_180 * V_181 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
T_3 V_49 = F_71 ( V_106 ) ;
F_75 ( & V_2 -> V_155 ) ;
F_32 ( V_2 , V_39 -> V_43 , V_49 , V_39 -> V_182 , - 1 , V_63 ) ;
F_27 ( V_2 , V_183 , 0 ) ;
F_14 ( & V_2 -> V_155 ) ;
}
static int
F_83 ( struct V_65 * V_66 , int V_106 ,
const struct V_179 * V_39 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
int V_5 ;
T_3 V_49 = F_71 ( V_106 ) ;
F_75 ( & V_2 -> V_155 ) ;
F_32 ( V_2 , V_39 -> V_43 , V_49 , V_39 -> V_182 , - 1 , V_184 ) ;
V_5 = F_27 ( V_2 , V_183 , 0 ) ;
F_14 ( & V_2 -> V_155 ) ;
return V_5 ;
}
static int
F_84 ( struct V_65 * V_66 , int V_106 ,
struct V_179 * V_39 ,
T_7 * V_185 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
struct V_38 V_186 = { 0 } ;
int V_187 = V_188 ;
int V_5 = 0 ;
T_1 V_32 = 0 ;
F_75 ( & V_2 -> V_155 ) ;
V_5 = F_27 ( V_2 , V_189 , & V_32 ) ;
if ( V_5 < 0 )
goto V_17;
do {
if ( V_32 & V_190 ) {
F_30 ( V_2 , & V_186 ) ;
if ( V_186 . V_49 & F_71 ( V_106 ) ) {
F_85 ( V_39 -> V_182 , V_186 . V_52 ) ;
V_39 -> V_43 = V_186 . V_43 ;
V_39 -> V_191 = V_186 . V_60 ?
V_192 : V_193 ;
V_5 = V_185 ( & V_39 -> V_194 ) ;
if ( V_5 < 0 )
break;
}
}
} while ( -- V_187 &&
! ( V_32 & V_195 ) &&
! F_27 ( V_2 , V_196 , & V_32 ) );
V_17:
F_14 ( & V_2 -> V_155 ) ;
return 0 ;
}
static enum V_197
F_86 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
if ( ! F_87 ( V_66 , V_158 ) ) {
F_88 ( V_2 -> V_7 ,
L_11 ) ;
return V_198 ;
} else {
return V_199 ;
}
}
static int
F_89 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
int V_5 , V_40 ;
T_1 V_200 , V_4 ;
struct V_201 * V_202 ;
struct V_29 V_30 ;
V_202 = V_66 -> V_203 -> V_204 -> V_205 -> V_7 . V_206 -> V_207 ;
V_2 -> V_6 = F_90 ( V_202 ) ;
if ( F_91 ( V_2 -> V_6 ) )
return F_92 ( V_2 -> V_6 ) ;
F_93 ( V_2 -> V_208 , 1000000 , 1000000 ) ;
V_5 = F_94 ( V_2 -> V_208 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_7 ,
L_12 , V_5 ) ;
return V_5 ;
}
F_93 ( V_2 -> V_209 , 3300000 , 3300000 ) ;
V_5 = F_94 ( V_2 -> V_209 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_7 , L_13 ,
V_5 ) ;
return V_5 ;
}
if ( V_2 -> V_210 ) {
F_95 ( V_2 -> V_211 ) ;
F_96 ( 1000 , 1100 ) ;
F_97 ( V_2 -> V_211 ) ;
} else {
F_98 ( V_2 -> V_212 , 0 ) ;
F_96 ( 1000 , 1100 ) ;
F_98 ( V_2 -> V_212 , 1 ) ;
}
F_23 ( & V_30 , V_2 , V_213 ) ;
V_5 = F_29 ( F_21 , & V_30 , V_4 , V_4 != 0 ,
20 , 1000000 ) ;
if ( V_5 < 0 ) {
F_4 ( V_2 -> V_7 , L_7 ) ;
return V_5 ;
}
V_200 = F_22 ( V_2 , V_214 ) ;
V_200 >>= V_215 ;
if ( V_200 != V_216 ) {
F_4 ( V_2 -> V_7 , L_14 , V_200 ) ;
return - V_217 ;
}
F_20 ( V_2 , V_218 ,
V_219 | V_220 |
V_221 ) ;
V_4 = F_22 ( V_2 , V_222 ) ;
V_4 &= ~ V_223 & ~ V_224 ;
V_4 |= V_225 ;
F_20 ( V_2 , V_222 , V_4 ) ;
F_52 ( V_66 ) ;
F_26 ( V_2 , V_152 , V_226 ) ;
for ( V_40 = 0 ; V_40 < V_177 ; V_40 ++ ) {
F_24 ( V_2 , F_72 ( V_40 ) , V_159 ,
V_160 ) ;
if ( F_87 ( V_66 , V_40 ) )
F_67 ( V_2 , V_40 ) ;
else
F_76 ( V_66 , V_40 , NULL ) ;
}
V_5 = F_27 ( V_2 , V_227 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int
F_99 ( struct V_228 * V_229 )
{
struct V_1 * V_2 ;
struct V_201 * V_202 ;
V_202 = V_229 -> V_7 . V_206 ;
V_2 = F_100 ( & V_229 -> V_7 , sizeof( * V_2 ) , V_230 ) ;
if ( ! V_2 )
return - V_231 ;
V_2 -> V_66 = F_101 ( & V_229 -> V_7 , V_232 ) ;
if ( ! V_2 -> V_66 )
return - V_231 ;
V_2 -> V_210 = F_102 ( V_202 , L_15 ) ;
if ( V_2 -> V_210 ) {
F_103 ( & V_229 -> V_7 , L_16 ) ;
V_2 -> V_211 = F_104 ( & V_229 -> V_7 , L_17 ) ;
if ( F_91 ( V_2 -> V_211 ) ) {
F_4 ( & V_229 -> V_7 , L_18 ) ;
return F_92 ( V_2 -> V_211 ) ;
}
}
V_2 -> V_208 = F_105 ( & V_229 -> V_7 , L_19 ) ;
if ( F_91 ( V_2 -> V_208 ) )
return F_92 ( V_2 -> V_208 ) ;
V_2 -> V_209 = F_105 ( & V_229 -> V_7 , L_20 ) ;
if ( F_91 ( V_2 -> V_209 ) )
return F_92 ( V_2 -> V_209 ) ;
if ( ! V_2 -> V_210 ) {
V_2 -> V_212 = F_106 ( & V_229 -> V_7 , L_21 ,
V_233 ) ;
if ( F_91 ( V_2 -> V_212 ) ) {
F_4 ( & V_229 -> V_7 , L_18 ) ;
return F_92 ( V_2 -> V_212 ) ;
}
}
V_2 -> V_13 = V_229 -> V_13 ;
V_2 -> V_7 = & V_229 -> V_7 ;
V_2 -> V_66 -> V_2 = V_2 ;
V_2 -> V_66 -> V_234 = & V_235 ;
F_107 ( & V_2 -> V_155 ) ;
F_108 ( & V_229 -> V_7 , V_2 ) ;
return F_109 ( V_2 -> V_66 ) ;
}
static void
F_110 ( struct V_228 * V_229 )
{
struct V_1 * V_2 = F_111 ( & V_229 -> V_7 ) ;
int V_5 = 0 ;
V_5 = F_112 ( V_2 -> V_208 ) ;
if ( V_5 < 0 )
F_4 ( V_2 -> V_7 ,
L_22 , V_5 ) ;
V_5 = F_112 ( V_2 -> V_209 ) ;
if ( V_5 < 0 )
F_4 ( V_2 -> V_7 , L_23 ,
V_5 ) ;
F_113 ( V_2 -> V_66 ) ;
F_114 ( & V_2 -> V_155 ) ;
}

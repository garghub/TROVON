static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 +
( V_2 -> V_6 [ V_3 ] << V_2 -> V_7 ) ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , int V_3 )
{
return F_4 ( V_2 -> V_5 +
( V_2 -> V_6 [ V_3 ] << V_2 -> V_7 ) ) ;
}
static int F_5 ( struct V_1 * V_8 )
{
T_1 V_9 = 0 , V_10 = 0 , V_11 = 0 , V_12 = 0 ;
T_1 V_13 = 0 , V_14 = 0 , V_15 = 0 , V_16 = 0 ;
unsigned long V_17 = 12000000 ;
unsigned long V_18 ;
unsigned long V_19 = 0 ;
struct V_20 * V_21 ;
if ( V_8 -> V_22 >= V_23 ) {
F_1 ( V_8 , V_24 ,
F_3 ( V_8 , V_24 ) &
~ ( V_25 ) ) ;
F_1 ( V_8 , V_26 , V_27 ) ;
V_18 = V_28 + V_29 ;
F_1 ( V_8 , V_24 , V_25 ) ;
while ( ! ( F_3 ( V_8 , V_30 ) &
V_31 ) ) {
if ( F_6 ( V_28 , V_18 ) ) {
F_7 ( V_8 -> V_8 , L_1
L_2 ) ;
return - V_32 ;
}
F_8 ( 1 ) ;
}
if ( V_8 -> V_22 == V_33 ) {
F_1 ( V_8 , V_26 ,
V_34 ) ;
} else if ( V_8 -> V_22 >= V_35 ) {
V_8 -> V_36 = V_34 ;
V_8 -> V_36 |= V_37 ;
V_8 -> V_36 |= ( V_38 <<
F_9 ( V_39 ) ) ;
V_8 -> V_36 |= ( V_40 <<
F_9 ( V_41 ) ) ;
F_1 ( V_8 , V_26 ,
V_8 -> V_36 ) ;
V_8 -> V_42 = V_43 ;
F_1 ( V_8 , V_44 ,
V_8 -> V_42 ) ;
}
}
F_1 ( V_8 , V_24 , 0 ) ;
if ( V_8 -> V_45 & V_46 ) {
V_21 = F_10 ( V_8 -> V_8 , L_3 ) ;
V_17 = F_11 ( V_21 ) ;
F_12 ( V_21 ) ;
if ( V_17 > 12000000 )
V_9 = V_17 / 12000000 ;
}
if ( ! ( V_8 -> V_45 & V_47 ) ) {
if ( V_8 -> V_48 > 400 ||
V_8 -> V_45 & V_49 )
V_19 = 19200 ;
else if ( V_8 -> V_48 > 100 )
V_19 = 9600 ;
else
V_19 = 4000 ;
V_21 = F_10 ( V_8 -> V_8 , L_3 ) ;
V_17 = F_11 ( V_21 ) / 1000 ;
F_12 ( V_21 ) ;
V_9 = V_17 / V_19 ;
V_9 = V_9 - 1 ;
if ( V_8 -> V_48 > 400 ) {
unsigned long V_50 ;
V_50 = V_19 / 400 ;
V_13 = V_50 - ( V_50 / 3 ) - 7 ;
V_14 = ( V_50 / 3 ) - 5 ;
V_50 = V_17 / V_8 -> V_48 ;
V_15 = V_50 - ( V_50 / 3 ) - 7 ;
V_16 = ( V_50 / 3 ) - 5 ;
} else if ( V_8 -> V_48 > 100 ) {
unsigned long V_50 ;
V_50 = V_19 / V_8 -> V_48 ;
V_13 = V_50 - ( V_50 / 3 ) - 7 ;
V_14 = ( V_50 / 3 ) - 5 ;
} else {
V_13 = V_19 / ( V_8 -> V_48 * 2 ) - 7 ;
V_14 = V_19 / ( V_8 -> V_48 * 2 ) - 5 ;
}
V_10 = ( V_15 << V_51 ) | V_13 ;
V_11 = ( V_16 << V_52 ) | V_14 ;
} else {
V_17 /= ( V_9 + 1 ) * 1000 ;
if ( V_9 > 2 )
V_9 = 2 ;
V_10 = V_17 / ( V_8 -> V_48 * 2 ) - 7 + V_9 ;
V_11 = V_17 / ( V_8 -> V_48 * 2 ) - 7 + V_9 ;
}
F_1 ( V_8 , V_53 , V_9 ) ;
F_1 ( V_8 , V_54 , V_10 ) ;
F_1 ( V_8 , V_55 , V_11 ) ;
F_1 ( V_8 , V_24 , V_25 ) ;
V_8 -> V_56 = ( V_57 | V_58 |
V_59 | V_60 |
V_61 ) | ( ( V_8 -> V_62 ) ?
( V_63 | V_64 ) : 0 ) ;
F_1 ( V_8 , V_65 , V_8 -> V_56 ) ;
if ( V_8 -> V_45 & V_66 ) {
V_8 -> V_67 = V_9 ;
V_8 -> V_68 = V_10 ;
V_8 -> V_69 = V_11 ;
V_8 -> V_70 = V_12 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_8 )
{
unsigned long V_18 ;
V_18 = V_28 + V_29 ;
while ( F_3 ( V_8 , V_71 ) & V_72 ) {
if ( F_6 ( V_28 , V_18 ) ) {
F_7 ( V_8 -> V_8 , L_4 ) ;
return - V_32 ;
}
F_8 ( 1 ) ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_8 , T_2 V_73 , bool V_74 )
{
T_1 V_12 ;
if ( V_8 -> V_45 & V_75 )
return;
V_8 -> V_76 = F_15 ( V_73 , ( T_2 ) 1 , V_8 -> V_62 ) ;
V_12 = F_3 ( V_8 , V_77 ) ;
if ( V_74 ) {
V_12 &= ~ ( 0x3f << 8 ) ;
V_12 |= ( ( V_8 -> V_76 - 1 ) << 8 ) | V_78 ;
} else {
V_12 &= ~ 0x3f ;
V_12 |= ( V_8 -> V_76 - 1 ) | V_79 ;
}
F_1 ( V_8 , V_77 , V_12 ) ;
if ( V_8 -> V_22 < V_80 )
V_8 -> V_81 = 1 ;
if ( V_8 -> V_82 != NULL )
V_8 -> V_83 = ( 1000000 * V_8 -> V_76 ) /
( 1000 * V_8 -> V_48 / 8 ) ;
}
static int F_16 ( struct V_84 * V_85 ,
struct V_86 * V_87 , int V_88 )
{
struct V_1 * V_8 = F_17 ( V_85 ) ;
unsigned long V_18 ;
T_1 V_89 ;
F_18 ( V_8 -> V_8 , L_5 ,
V_87 -> V_90 , V_87 -> V_91 , V_87 -> V_45 , V_88 ) ;
if ( V_87 -> V_91 == 0 )
return - V_92 ;
V_8 -> V_93 = ! ! ( V_87 -> V_45 & V_94 ) ;
F_14 ( V_8 , V_87 -> V_91 , V_8 -> V_93 ) ;
F_1 ( V_8 , V_95 , V_87 -> V_90 ) ;
V_8 -> V_12 = V_87 -> V_12 ;
V_8 -> V_96 = V_87 -> V_91 ;
F_19 () ;
F_1 ( V_8 , V_97 , V_8 -> V_96 ) ;
V_89 = F_3 ( V_8 , V_77 ) ;
V_89 |= V_78 | V_79 ;
F_1 ( V_8 , V_77 , V_89 ) ;
F_20 ( V_8 -> V_98 ) ;
V_8 -> V_99 = 0 ;
V_89 = V_25 | V_100 | V_101 ;
if ( V_8 -> V_48 > 400 )
V_89 |= V_102 ;
if ( V_87 -> V_45 & V_103 )
V_88 = 1 ;
if ( V_87 -> V_45 & V_104 )
V_89 |= V_105 ;
if ( ! ( V_87 -> V_45 & V_94 ) )
V_89 |= V_106 ;
if ( ! V_8 -> V_81 && V_88 )
V_89 |= V_107 ;
F_1 ( V_8 , V_24 , V_89 ) ;
if ( V_8 -> V_81 && V_88 ) {
unsigned long V_108 = V_28 + V_29 ;
T_1 V_109 = F_3 ( V_8 , V_24 ) ;
while ( V_109 & V_101 ) {
V_109 = F_3 ( V_8 , V_24 ) ;
if ( F_6 ( V_28 , V_108 ) ) {
F_21 ( V_8 -> V_8 , L_6
L_7 ) ;
return - V_32 ;
}
F_22 () ;
}
V_89 |= V_107 ;
V_89 &= ~ V_101 ;
F_1 ( V_8 , V_24 , V_89 ) ;
}
V_18 = F_23 ( & V_8 -> V_98 ,
V_29 ) ;
if ( V_18 == 0 ) {
F_21 ( V_8 -> V_8 , L_8 ) ;
F_5 ( V_8 ) ;
return - V_32 ;
}
if ( F_24 ( ! V_8 -> V_99 ) )
return 0 ;
if ( V_8 -> V_99 & ( V_110 | V_111 |
V_112 ) ) {
F_5 ( V_8 ) ;
return - V_113 ;
}
if ( V_8 -> V_99 & V_114 ) {
if ( V_87 -> V_45 & V_115 )
return 0 ;
if ( V_88 ) {
V_89 = F_3 ( V_8 , V_24 ) ;
V_89 |= V_107 ;
F_1 ( V_8 , V_24 , V_89 ) ;
}
return - V_116 ;
}
return - V_113 ;
}
static int
F_25 ( struct V_84 * V_85 , struct V_86 V_117 [] , int V_118 )
{
struct V_1 * V_8 = F_17 ( V_85 ) ;
int V_119 ;
int V_120 ;
V_120 = F_26 ( V_8 -> V_8 ) ;
if ( F_27 ( V_120 ) )
goto V_121;
V_120 = F_13 ( V_8 ) ;
if ( V_120 < 0 )
goto V_121;
if ( V_8 -> V_82 != NULL )
V_8 -> V_82 ( V_8 -> V_8 , V_8 -> V_83 ) ;
for ( V_119 = 0 ; V_119 < V_118 ; V_119 ++ ) {
V_120 = F_16 ( V_85 , & V_117 [ V_119 ] , ( V_119 == ( V_118 - 1 ) ) ) ;
if ( V_120 != 0 )
break;
}
if ( V_8 -> V_82 != NULL )
V_8 -> V_82 ( V_8 -> V_8 , - 1 ) ;
if ( V_120 == 0 )
V_120 = V_118 ;
F_13 ( V_8 ) ;
V_121:
F_28 ( V_8 -> V_8 ) ;
F_29 ( V_8 -> V_8 ) ;
return V_120 ;
}
static T_3
F_30 ( struct V_84 * V_85 )
{
return V_122 | ( V_123 & ~ V_124 ) |
V_125 ;
}
static inline void
F_31 ( struct V_1 * V_8 , T_1 V_126 )
{
V_8 -> V_99 |= V_126 ;
F_32 ( & V_8 -> V_98 ) ;
}
static inline void
F_33 ( struct V_1 * V_8 , T_1 V_127 )
{
F_1 ( V_8 , V_71 , V_127 ) ;
}
static inline void F_34 ( struct V_1 * V_8 , T_1 V_127 )
{
if ( V_127 & V_128 ) {
F_33 ( V_8 , V_128 ) ;
if ( ! ( F_3 ( V_8 , V_71 )
& V_72 ) ) {
if ( F_3 ( V_8 , V_71 )
& V_128 ) {
F_33 ( V_8 , V_128 ) ;
F_18 ( V_8 -> V_8 , L_9 ) ;
}
}
}
}
static T_4
F_35 ( int V_129 , void * V_130 )
{
struct V_1 * V_8 = V_130 ;
T_1 V_131 , V_89 ;
if ( F_36 ( V_8 -> V_8 ) )
return V_132 ;
V_131 = F_3 ( V_8 , V_133 ) ;
switch ( V_131 ) {
case 0x00 :
break;
case 0x01 :
F_21 ( V_8 -> V_8 , L_10 ) ;
F_31 ( V_8 , V_110 ) ;
break;
case 0x02 :
F_31 ( V_8 , V_114 ) ;
F_1 ( V_8 , V_24 , V_107 ) ;
break;
case 0x03 :
F_31 ( V_8 , 0 ) ;
break;
case 0x04 :
if ( V_8 -> V_96 ) {
V_89 = F_3 ( V_8 , V_134 ) ;
* V_8 -> V_12 ++ = V_89 ;
V_8 -> V_96 -- ;
if ( V_8 -> V_96 ) {
* V_8 -> V_12 ++ = V_89 >> 8 ;
V_8 -> V_96 -- ;
}
} else
F_21 ( V_8 -> V_8 , L_11 ) ;
break;
case 0x05 :
if ( V_8 -> V_96 ) {
V_89 = * V_8 -> V_12 ++ ;
V_8 -> V_96 -- ;
if ( V_8 -> V_96 ) {
V_89 |= * V_8 -> V_12 ++ << 8 ;
V_8 -> V_96 -- ;
}
F_1 ( V_8 , V_134 , V_89 ) ;
} else
F_21 ( V_8 -> V_8 , L_12 ) ;
break;
default:
return V_132 ;
}
return V_135 ;
}
static int F_37 ( struct V_1 * V_8 )
{
unsigned long V_18 = 10000 ;
T_1 V_127 ;
do {
V_127 = F_3 ( V_8 , V_71 ) ;
if ( V_127 & V_112 )
break;
if ( V_127 & ( V_114 | V_110 ) ) {
F_33 ( V_8 , ( V_136 |
V_137 ) ) ;
if ( V_127 & V_114 ) {
V_8 -> V_99 |= V_114 ;
F_33 ( V_8 , V_114 ) ;
}
if ( V_127 & V_110 ) {
F_21 ( V_8 -> V_8 , L_10 ) ;
V_8 -> V_99 |= V_110 ;
F_33 ( V_8 , V_114 ) ;
}
return - V_113 ;
}
F_22 () ;
} while ( -- V_18 );
if ( ! V_18 ) {
F_21 ( V_8 -> V_8 , L_13 ) ;
return 0 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_8 , T_2 V_138 ,
bool V_139 )
{
T_1 V_89 ;
while ( V_138 -- ) {
V_89 = F_3 ( V_8 , V_134 ) ;
* V_8 -> V_12 ++ = V_89 ;
V_8 -> V_96 -- ;
if ( V_8 -> V_45 & V_140 ) {
* V_8 -> V_12 ++ = V_89 >> 8 ;
V_8 -> V_96 -- ;
}
}
}
static int F_39 ( struct V_1 * V_8 , T_2 V_138 ,
bool V_141 )
{
T_1 V_89 ;
while ( V_138 -- ) {
V_89 = * V_8 -> V_12 ++ ;
V_8 -> V_96 -- ;
if ( V_8 -> V_45 & V_140 ) {
V_89 |= * V_8 -> V_12 ++ << 8 ;
V_8 -> V_96 -- ;
}
if ( V_8 -> V_142 & V_143 ) {
int V_144 ;
V_144 = F_37 ( V_8 ) ;
if ( V_144 < 0 )
return V_144 ;
}
F_1 ( V_8 , V_134 , V_89 ) ;
}
return 0 ;
}
static T_4
F_40 ( int V_145 , void * V_130 )
{
struct V_1 * V_8 = V_130 ;
T_4 V_144 = V_135 ;
T_1 V_146 ;
T_1 V_127 ;
F_41 ( & V_8 -> V_147 ) ;
V_146 = F_3 ( V_8 , V_65 ) ;
V_127 = F_3 ( V_8 , V_71 ) ;
if ( V_127 & V_146 )
V_144 = V_148 ;
F_42 ( & V_8 -> V_147 ) ;
return V_144 ;
}
static T_4
F_43 ( int V_129 , void * V_130 )
{
struct V_1 * V_8 = V_130 ;
unsigned long V_45 ;
T_1 V_149 ;
T_1 V_127 ;
int V_126 = 0 , V_150 = 0 ;
F_44 ( & V_8 -> V_147 , V_45 ) ;
do {
V_149 = F_3 ( V_8 , V_65 ) ;
V_127 = F_3 ( V_8 , V_71 ) ;
V_127 &= V_149 ;
if ( V_8 -> V_93 )
V_127 &= ~ ( V_137 | V_136 ) ;
else
V_127 &= ~ ( V_128 | V_151 ) ;
if ( ! V_127 ) {
goto V_121;
}
F_18 ( V_8 -> V_8 , L_14 , V_127 ) ;
if ( V_150 ++ == 100 ) {
F_7 ( V_8 -> V_8 , L_15 ) ;
break;
}
if ( V_127 & V_114 ) {
V_126 |= V_114 ;
F_33 ( V_8 , V_114 ) ;
break;
}
if ( V_127 & V_110 ) {
F_21 ( V_8 -> V_8 , L_10 ) ;
V_126 |= V_110 ;
F_33 ( V_8 , V_110 ) ;
break;
}
if ( V_127 & ( V_152 | V_114 |
V_110 ) ) {
F_33 ( V_8 , ( V_151 |
V_128 |
V_136 |
V_137 |
V_152 ) ) ;
break;
}
if ( V_127 & V_128 ) {
T_2 V_138 = 1 ;
if ( V_8 -> V_62 )
V_138 = V_8 -> V_96 ;
F_38 ( V_8 , V_138 , true ) ;
if ( V_8 -> V_142 & V_153 )
F_34 ( V_8 , V_127 ) ;
F_33 ( V_8 , V_128 ) ;
break;
}
if ( V_127 & V_151 ) {
T_2 V_138 = 1 ;
if ( V_8 -> V_76 )
V_138 = V_8 -> V_76 ;
F_38 ( V_8 , V_138 , false ) ;
F_33 ( V_8 , V_151 ) ;
continue;
}
if ( V_127 & V_137 ) {
T_2 V_138 = 1 ;
int V_144 ;
if ( V_8 -> V_62 )
V_138 = V_8 -> V_96 ;
V_144 = F_39 ( V_8 , V_138 , true ) ;
if ( V_144 < 0 )
break;
F_33 ( V_8 , V_137 ) ;
break;
}
if ( V_127 & V_136 ) {
T_2 V_138 = 1 ;
int V_144 ;
if ( V_8 -> V_76 )
V_138 = V_8 -> V_76 ;
V_144 = F_39 ( V_8 , V_138 , false ) ;
if ( V_144 < 0 )
break;
F_33 ( V_8 , V_136 ) ;
continue;
}
if ( V_127 & V_111 ) {
F_21 ( V_8 -> V_8 , L_16 ) ;
V_126 |= V_111 ;
F_33 ( V_8 , V_111 ) ;
break;
}
if ( V_127 & V_112 ) {
F_21 ( V_8 -> V_8 , L_17 ) ;
V_126 |= V_112 ;
F_33 ( V_8 , V_112 ) ;
break;
}
} while ( V_127 );
F_31 ( V_8 , V_126 ) ;
V_121:
F_45 ( & V_8 -> V_147 , V_45 ) ;
return V_135 ;
}
static int T_5
F_46 ( struct V_154 * V_155 )
{
struct V_1 * V_8 ;
struct V_84 * V_85 ;
struct V_156 * V_157 ;
const struct V_158 * V_159 =
V_155 -> V_8 . V_160 ;
struct V_161 * V_162 = V_155 -> V_8 . V_163 ;
const struct V_164 * V_165 ;
int V_145 ;
int V_120 ;
V_157 = F_47 ( V_155 , V_166 , 0 ) ;
if ( ! V_157 ) {
F_21 ( & V_155 -> V_8 , L_18 ) ;
return - V_167 ;
}
V_145 = F_48 ( V_155 , 0 ) ;
if ( V_145 < 0 ) {
F_21 ( & V_155 -> V_8 , L_19 ) ;
return V_145 ;
}
V_8 = F_49 ( & V_155 -> V_8 , sizeof( struct V_1 ) , V_168 ) ;
if ( ! V_8 ) {
F_21 ( & V_155 -> V_8 , L_20 ) ;
return - V_169 ;
}
V_8 -> V_5 = F_50 ( & V_155 -> V_8 , V_157 ) ;
if ( ! V_8 -> V_5 ) {
F_21 ( & V_155 -> V_8 , L_21 ) ;
return - V_169 ;
}
V_165 = F_51 ( F_52 ( V_170 ) , & V_155 -> V_8 ) ;
if ( V_165 ) {
T_3 V_171 = 100000 ;
V_159 = V_165 -> V_172 ;
V_8 -> V_173 = V_159 -> V_22 ;
V_8 -> V_45 = V_159 -> V_45 ;
F_53 ( V_162 , L_22 , & V_171 ) ;
V_8 -> V_48 = V_171 / 1000 ;
} else if ( V_159 != NULL ) {
V_8 -> V_48 = V_159 -> V_174 ;
V_8 -> V_45 = V_159 -> V_45 ;
V_8 -> V_82 = V_159 -> V_82 ;
V_8 -> V_173 = V_159 -> V_22 ;
}
V_8 -> V_8 = & V_155 -> V_8 ;
V_8 -> V_145 = V_145 ;
F_54 ( & V_8 -> V_147 ) ;
F_55 ( V_155 , V_8 ) ;
F_56 ( & V_8 -> V_98 ) ;
V_8 -> V_7 = ( V_8 -> V_45 >> V_175 ) & 3 ;
if ( V_8 -> V_173 == V_176 )
V_8 -> V_6 = ( T_2 * ) V_177 ;
else
V_8 -> V_6 = ( T_2 * ) V_178 ;
F_57 ( V_8 -> V_8 ) ;
F_58 ( V_8 -> V_8 , V_179 ) ;
F_59 ( V_8 -> V_8 ) ;
V_120 = F_26 ( V_8 -> V_8 ) ;
if ( F_27 ( V_120 ) )
goto V_180;
V_8 -> V_22 = F_3 ( V_8 , V_181 ) & 0xff ;
V_8 -> V_142 = 0 ;
if ( V_8 -> V_45 & V_182 )
V_8 -> V_142 |= V_153 ;
if ( V_8 -> V_22 <= V_35 )
V_8 -> V_142 |= V_143 ;
if ( ! ( V_8 -> V_45 & V_75 ) ) {
T_1 V_183 ;
V_183 = ( F_3 ( V_8 , V_184 ) >> 14 ) & 0x3 ;
V_8 -> V_62 = 0x8 << V_183 ;
V_8 -> V_62 = ( V_8 -> V_62 / 2 ) ;
if ( V_8 -> V_22 < V_80 )
V_8 -> V_81 = 1 ;
if ( V_8 -> V_82 != NULL )
V_8 -> V_83 = ( 1000000 * V_8 -> V_62 ) /
( 1000 * V_8 -> V_48 / 8 ) ;
}
F_5 ( V_8 ) ;
if ( V_8 -> V_22 < V_23 )
V_120 = F_60 ( & V_155 -> V_8 , V_8 -> V_145 , F_35 ,
V_185 , V_155 -> V_186 , V_8 ) ;
else
V_120 = F_61 ( & V_155 -> V_8 , V_8 -> V_145 ,
F_40 , F_43 ,
V_185 | V_187 ,
V_155 -> V_186 , V_8 ) ;
if ( V_120 ) {
F_21 ( V_8 -> V_8 , L_23 , V_8 -> V_145 ) ;
goto V_188;
}
V_85 = & V_8 -> V_189 ;
F_62 ( V_85 , V_8 ) ;
V_85 -> V_190 = V_191 ;
V_85 -> V_192 = V_193 ;
F_63 ( V_85 -> V_186 , L_24 , sizeof( V_85 -> V_186 ) ) ;
V_85 -> V_194 = & V_195 ;
V_85 -> V_8 . V_196 = & V_155 -> V_8 ;
V_85 -> V_8 . V_163 = V_155 -> V_8 . V_163 ;
V_85 -> V_197 = V_155 -> V_198 ;
V_120 = F_64 ( V_85 ) ;
if ( V_120 ) {
F_21 ( V_8 -> V_8 , L_25 ) ;
goto V_188;
}
F_65 ( V_8 -> V_8 , L_26 , V_85 -> V_197 ,
V_8 -> V_173 , V_8 -> V_22 >> 4 , V_8 -> V_22 & 0xf , V_8 -> V_48 ) ;
F_66 ( V_85 ) ;
F_28 ( V_8 -> V_8 ) ;
F_29 ( V_8 -> V_8 ) ;
return 0 ;
V_188:
F_1 ( V_8 , V_24 , 0 ) ;
F_67 ( V_8 -> V_8 ) ;
F_68 ( & V_155 -> V_8 ) ;
V_180:
F_55 ( V_155 , NULL ) ;
return V_120 ;
}
static int T_6 F_69 ( struct V_154 * V_155 )
{
struct V_1 * V_8 = F_70 ( V_155 ) ;
int V_144 ;
F_55 ( V_155 , NULL ) ;
F_71 ( & V_8 -> V_189 ) ;
V_144 = F_26 ( & V_155 -> V_8 ) ;
if ( F_27 ( V_144 ) )
return V_144 ;
F_1 ( V_8 , V_24 , 0 ) ;
F_67 ( & V_155 -> V_8 ) ;
F_68 ( & V_155 -> V_8 ) ;
return 0 ;
}
static int F_72 ( struct V_199 * V_8 )
{
struct V_154 * V_155 = F_73 ( V_8 ) ;
struct V_1 * V_200 = F_70 ( V_155 ) ;
T_1 V_131 ;
V_200 -> V_56 = F_3 ( V_200 , V_65 ) ;
F_1 ( V_200 , V_65 , 0 ) ;
if ( V_200 -> V_22 < V_23 ) {
V_131 = F_3 ( V_200 , V_133 ) ;
} else {
F_1 ( V_200 , V_71 , V_200 -> V_56 ) ;
F_3 ( V_200 , V_71 ) ;
}
return 0 ;
}
static int F_74 ( struct V_199 * V_8 )
{
struct V_154 * V_155 = F_73 ( V_8 ) ;
struct V_1 * V_200 = F_70 ( V_155 ) ;
if ( V_200 -> V_45 & V_66 ) {
F_1 ( V_200 , V_24 , 0 ) ;
F_1 ( V_200 , V_53 , V_200 -> V_67 ) ;
F_1 ( V_200 , V_54 , V_200 -> V_68 ) ;
F_1 ( V_200 , V_55 , V_200 -> V_69 ) ;
F_1 ( V_200 , V_77 , V_200 -> V_70 ) ;
F_1 ( V_200 , V_26 , V_200 -> V_36 ) ;
F_1 ( V_200 , V_44 , V_200 -> V_42 ) ;
F_1 ( V_200 , V_24 , V_25 ) ;
}
if ( V_200 -> V_56 )
F_1 ( V_200 , V_65 , V_200 -> V_56 ) ;
return 0 ;
}
static int T_7
F_75 ( void )
{
return F_76 ( & V_201 ) ;
}
static void T_8 F_77 ( void )
{
F_78 ( & V_201 ) ;
}

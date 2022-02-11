static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_6 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_8 = F_3 ( V_2 , V_9 ) & V_10 ;
F_1 ( V_2 , V_11 , V_12 ) ;
V_8 |= V_13 | F_7 ( V_2 -> V_14 ) | V_15 ;
if ( ! ( V_2 -> V_16 -> V_17 & V_18 ) )
V_8 |= V_19 ;
F_1 ( V_2 , V_8 , V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 , int error )
{
unsigned int V_20 ;
V_2 -> V_21 = 0 ;
V_2 -> V_16 = NULL ;
V_2 -> error = error ;
if ( V_2 -> V_22 ) {
F_1 ( V_2 , V_23 , V_12 ) ;
V_2 -> V_24 = V_25 ;
V_20 = F_3 ( V_2 , V_9 ) ;
V_20 |= V_26 ;
F_1 ( V_2 , V_20 , V_9 ) ;
} else {
V_2 -> V_27 = false ;
V_2 -> V_24 = V_28 ;
V_20 = F_3 ( V_2 , V_9 ) & V_10 ;
F_1 ( V_2 , V_20 , V_9 ) ;
F_9 ( & V_2 -> V_29 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
unsigned int V_30 = V_2 -> V_16 -> V_30 - V_2 -> V_21 ;
T_1 V_31 ;
V_31 = F_3 ( V_2 , V_9 ) ;
if ( V_30 > 32 ) {
V_30 = 32 ;
V_31 &= ~ V_32 ;
} else {
V_31 |= V_32 ;
}
if ( V_2 -> V_21 != 0 ) {
V_31 &= ~ V_33 ;
V_31 |= F_7 ( V_34 ) ;
}
F_1 ( V_2 , V_31 , V_9 ) ;
F_1 ( V_2 , V_30 , V_35 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_36 , V_37 ;
T_1 V_38 = 0 ;
T_1 V_8 ;
T_2 V_39 ;
for ( V_36 = 0 ; V_36 < 8 ; ++ V_36 ) {
V_8 = 0 ;
for ( V_37 = 0 ; V_37 < 4 ; ++ V_37 ) {
if ( ( V_2 -> V_21 == V_2 -> V_16 -> V_30 ) && ( V_38 != 0 ) )
break;
if ( V_2 -> V_21 == 0 && V_38 == 0 )
V_39 = ( V_2 -> V_40 & 0x7f ) << 1 ;
else
V_39 = V_2 -> V_16 -> V_41 [ V_2 -> V_21 ++ ] ;
V_8 |= V_39 << ( V_37 * 8 ) ;
V_38 ++ ;
}
F_1 ( V_2 , V_8 , V_42 + 4 * V_36 ) ;
if ( V_2 -> V_21 == V_2 -> V_16 -> V_30 )
break;
}
F_1 ( V_2 , V_38 , V_43 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_44 )
{
if ( ! ( V_44 & V_11 ) ) {
F_8 ( V_2 , - V_45 ) ;
F_13 ( V_2 -> V_46 , L_1 , V_44 ) ;
F_5 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_11 , V_7 ) ;
F_1 ( V_2 , F_3 ( V_2 , V_9 ) & ~ V_15 , V_9 ) ;
if ( V_2 -> V_14 == V_47 ) {
F_1 ( V_2 , V_48 | V_49 , V_12 ) ;
V_2 -> V_24 = V_50 ;
F_11 ( V_2 ) ;
} else {
F_1 ( V_2 , V_51 | V_49 , V_12 ) ;
V_2 -> V_24 = V_52 ;
F_10 ( V_2 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_44 )
{
if ( ! ( V_44 & V_48 ) ) {
F_8 ( V_2 , - V_45 ) ;
F_15 ( V_2 -> V_46 , L_2 , V_44 ) ;
F_5 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_48 , V_7 ) ;
if ( V_2 -> V_21 == V_2 -> V_16 -> V_30 )
F_8 ( V_2 , V_2 -> error ) ;
else
F_11 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_44 )
{
unsigned int V_36 ;
unsigned int V_30 = V_2 -> V_16 -> V_30 - V_2 -> V_21 ;
T_1 V_53 ( V_8 ) ;
T_2 V_39 ;
if ( ! ( V_44 & V_51 ) )
return;
F_1 ( V_2 , V_51 , V_7 ) ;
if ( V_30 > 32 )
V_30 = 32 ;
for ( V_36 = 0 ; V_36 < V_30 ; ++ V_36 ) {
if ( V_36 % 4 == 0 )
V_8 = F_3 ( V_2 , V_54 + ( V_36 / 4 ) * 4 ) ;
V_39 = ( V_8 >> ( ( V_36 % 4 ) * 8 ) ) & 0xff ;
V_2 -> V_16 -> V_41 [ V_2 -> V_21 ++ ] = V_39 ;
}
if ( V_2 -> V_21 == V_2 -> V_16 -> V_30 )
F_8 ( V_2 , V_2 -> error ) ;
else
F_10 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_44 )
{
unsigned int V_31 ;
if ( ! ( V_44 & V_23 ) ) {
F_8 ( V_2 , - V_45 ) ;
F_15 ( V_2 -> V_46 , L_3 , V_44 ) ;
F_5 ( V_2 ) ;
return;
}
F_1 ( V_2 , V_23 , V_7 ) ;
V_31 = F_3 ( V_2 , V_9 ) ;
V_31 &= ~ V_26 ;
F_1 ( V_2 , V_31 , V_9 ) ;
V_2 -> V_27 = false ;
V_2 -> V_24 = V_28 ;
F_9 ( & V_2 -> V_29 ) ;
}
static T_3 F_18 ( int V_55 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
unsigned int V_44 ;
F_19 ( & V_2 -> V_57 ) ;
V_44 = F_3 ( V_2 , V_7 ) ;
if ( V_2 -> V_24 == V_28 ) {
F_13 ( V_2 -> V_46 , L_4 , V_44 ) ;
F_5 ( V_2 ) ;
goto V_58;
}
F_20 ( V_2 -> V_46 , L_5 , V_2 -> V_24 , V_44 ) ;
V_44 &= ~ ( V_59 | V_60 ) ;
if ( V_44 & V_49 ) {
F_1 ( V_2 , V_49 , V_7 ) ;
V_44 &= ~ V_49 ;
if ( ! ( V_2 -> V_16 -> V_17 & V_18 ) )
F_8 ( V_2 , - V_61 ) ;
}
if ( ( V_44 & V_6 ) == 0 )
goto V_58;
switch ( V_2 -> V_24 ) {
case V_62 :
F_12 ( V_2 , V_44 ) ;
break;
case V_50 :
F_14 ( V_2 , V_44 ) ;
break;
case V_52 :
F_16 ( V_2 , V_44 ) ;
break;
case V_25 :
F_17 ( V_2 , V_44 ) ;
break;
case V_28 :
break;
}
V_58:
F_21 ( & V_2 -> V_57 ) ;
return V_63 ;
}
static const struct V_64 * F_22 ( unsigned int V_65 )
{
if ( V_65 <= 100000 )
return & V_66 ;
else if ( V_65 <= 400000 )
return & V_67 ;
else
return & V_68 ;
}
static int F_23 ( unsigned long V_69 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
unsigned long V_74 , V_75 ;
unsigned long V_76 , V_77 ;
unsigned long V_78 , V_79 ;
unsigned long V_80 , V_81 ;
unsigned long V_82 ;
unsigned long V_83 , V_84 ;
unsigned long V_85 , V_86 , V_87 ;
unsigned long V_88 = 50 ;
const struct V_64 * V_89 ;
int V_90 = 0 ;
if ( F_24 ( V_71 -> V_91 > 400000 ) )
V_71 -> V_91 = 400000 ;
if ( F_24 ( V_71 -> V_91 < 1000 ) )
V_71 -> V_91 = 1000 ;
V_89 = F_22 ( V_71 -> V_91 ) ;
V_75 = V_71 -> V_92 + V_89 -> V_75 ;
V_75 = F_25 ( V_75 , F_26 (
( V_71 -> V_92 + V_89 -> V_93 ) * 1000 , 875 ) ) ;
V_75 = F_25 ( V_75 , F_26 (
( V_71 -> V_92 + V_89 -> V_93 + V_71 -> V_94 +
V_89 -> V_75 ) , 2 ) ) ;
V_74 = V_71 -> V_95 + V_89 -> V_74 ;
V_76 = V_89 -> V_96 * 2 - V_88 ;
V_77 = V_74 + V_75 ;
V_78 = F_26 ( V_69 , 1000 ) ;
V_79 = V_71 -> V_91 / 1000 ;
V_84 = F_26 ( V_78 , V_79 * 8 ) ;
V_80 = F_26 ( V_78 * V_74 , 8 * 1000000 ) ;
V_81 = F_26 ( V_78 * V_75 , 8 * 1000000 ) ;
V_83 = ( V_80 + V_81 ) ;
V_82 = V_78 * V_76 / ( 8 * 1000000 ) ;
if ( V_80 > V_82 ) {
F_27 ( true ,
L_6 ,
V_80 , V_82 ) ;
V_82 = V_80 ;
}
if ( V_83 > V_84 ) {
V_73 -> V_97 = V_80 ;
V_73 -> V_98 = V_81 ;
} else {
V_85 = V_84 - V_83 ;
V_87 = F_26 ( V_78 * V_74 ,
V_79 * 8 * V_77 ) ;
if ( V_87 > V_82 )
V_87 = V_82 ;
if ( V_87 > V_80 + V_85 )
V_87 = V_80 + V_85 ;
V_86 = V_87 - V_80 ;
V_73 -> V_97 = V_87 ;
V_73 -> V_98 = V_81 + ( V_85 - V_86 ) ;
}
V_73 -> V_97 -- ;
V_73 -> V_98 -- ;
V_73 -> V_99 = 0 ;
if ( V_73 -> V_97 > 0xffff ) {
V_73 -> V_97 = 0xffff ;
V_90 = - V_100 ;
}
if ( V_73 -> V_98 > 0xffff ) {
V_73 -> V_98 = 0xffff ;
V_90 = - V_100 ;
}
return V_90 ;
}
static int F_28 ( unsigned long V_69 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
unsigned long V_74 , V_75 ;
unsigned long V_93 , V_101 ;
unsigned long V_102 , V_103 ;
unsigned long V_78 , V_79 ;
unsigned long V_80 , V_81 ;
unsigned long V_83 , V_84 ;
unsigned long V_85 , V_86 ;
unsigned long V_104 , V_105 , V_106 ;
const struct V_64 * V_89 ;
int V_90 = 0 ;
if ( F_24 ( V_71 -> V_91 > 1000000 ) )
V_71 -> V_91 = 1000000 ;
if ( F_24 ( V_71 -> V_91 < 1000 ) )
V_71 -> V_91 = 1000 ;
V_89 = F_22 ( V_71 -> V_91 ) ;
V_78 = F_26 ( V_69 , 1000 ) ;
V_79 = V_71 -> V_91 / 1000 ;
V_84 = F_26 ( V_78 , V_79 * 8 ) ;
V_75 = V_71 -> V_92 + V_89 -> V_75 ;
V_81 = F_26 ( V_78 * V_75 , 8 * 1000000 ) ;
V_74 = V_71 -> V_95 + V_89 -> V_74 ;
V_80 = F_26 ( V_78 * V_74 , 8 * 1000000 ) ;
V_81 = ( V_81 < 1 ) ? 2 : V_81 ;
V_80 = ( V_80 < 1 ) ? 2 : V_80 ;
V_83 = ( V_80 + V_81 ) ;
if ( V_83 >= V_84 ) {
V_73 -> V_97 = V_80 ;
V_73 -> V_98 = V_81 ;
} else {
V_85 = V_84 - V_83 ;
V_86 = F_26 ( V_80 * V_85 ,
V_83 ) ;
V_73 -> V_97 = V_80 + V_86 ;
V_73 -> V_98 = V_81 + ( V_85 - V_86 ) ;
}
for ( V_104 = 3 ; V_104 > 0 ; V_104 -- ) {
V_103 = F_26 ( ( V_104
* ( V_73 -> V_97 ) + 1 )
* 1000000 , V_78 ) ;
V_101 = F_26 ( ( ( 8 - V_104 )
* ( V_73 -> V_97 ) + 1 )
* 1000000 , V_78 ) ;
if ( ( V_103 < V_89 -> V_96 ) &&
( V_101 > V_89 -> V_107 ) )
break;
}
V_93 = V_71 -> V_92 + V_89 -> V_93 ;
V_105 = F_26 ( V_78 * V_93
- 1000000 , 8 * 1000000 * ( V_73 -> V_98 ) ) ;
V_102 = V_71 -> V_92 + V_89 -> V_102 ;
V_106 = F_26 ( V_78 * V_102
- 1000000 , 8 * 1000000 * ( V_73 -> V_98 ) ) ;
V_73 -> V_99 = F_29 ( -- V_104 ) |
F_30 ( -- V_105 ) |
F_31 ( -- V_106 ) ;
V_73 -> V_97 -- ;
V_73 -> V_98 -- ;
if ( V_73 -> V_97 > 0xffff ) {
V_73 -> V_97 = 0xffff ;
V_90 = - V_100 ;
}
if ( V_73 -> V_98 > 0xffff ) {
V_73 -> V_98 = 0xffff ;
V_90 = - V_100 ;
}
return V_90 ;
}
static void F_32 ( struct V_1 * V_2 , unsigned long V_69 )
{
struct V_70 * V_71 = & V_2 -> V_71 ;
struct V_72 V_108 ;
T_4 V_109 , V_110 ;
unsigned long V_17 ;
T_1 V_8 ;
int V_90 ;
V_90 = V_2 -> V_111 -> V_112 ( V_69 , V_71 , & V_108 ) ;
F_27 ( V_90 != 0 , L_7 , V_71 -> V_91 ) ;
F_33 ( V_2 -> V_113 ) ;
F_34 ( & V_2 -> V_57 , V_17 ) ;
V_8 = F_3 ( V_2 , V_9 ) ;
V_8 &= ~ V_10 ;
V_8 |= V_108 . V_99 ;
F_1 ( V_2 , V_8 , V_9 ) ;
F_1 ( V_2 , ( V_108 . V_98 << 16 ) | ( V_108 . V_97 & 0xffff ) ,
V_114 ) ;
F_35 ( & V_2 -> V_57 , V_17 ) ;
F_36 ( V_2 -> V_113 ) ;
V_109 = F_37 ( ( ( T_4 ) V_108 . V_97 + 1 ) * 8 * 1000000000 , V_69 ) ;
V_110 = F_37 ( ( ( T_4 ) V_108 . V_98 + 1 ) * 8 * 1000000000 ,
V_69 ) ;
F_20 ( V_2 -> V_46 ,
L_8 ,
V_69 / 1000 ,
1000000000 / V_71 -> V_91 ,
V_109 , V_110 ) ;
}
static int F_38 ( struct V_115 * V_116 , unsigned long
V_117 , void * V_118 )
{
struct V_119 * V_120 = V_118 ;
struct V_1 * V_2 = F_39 ( V_116 , struct V_1 , V_121 ) ;
struct V_72 V_108 ;
switch ( V_117 ) {
case V_122 :
if ( V_2 -> V_111 -> V_112 ( V_120 -> V_123 , & V_2 -> V_71 ,
& V_108 ) != 0 )
return V_124 ;
if ( V_120 -> V_123 > V_120 -> V_125 )
F_32 ( V_2 , V_120 -> V_123 ) ;
return V_126 ;
case V_127 :
if ( V_120 -> V_123 < V_120 -> V_125 )
F_32 ( V_2 , V_120 -> V_123 ) ;
return V_126 ;
case V_128 :
if ( V_120 -> V_123 > V_120 -> V_125 )
F_32 ( V_2 , V_120 -> V_125 ) ;
return V_126 ;
default:
return V_129 ;
}
}
static int F_40 ( struct V_1 * V_2 , struct V_130 * V_131 , int V_132 )
{
T_1 V_40 = ( V_131 [ 0 ] . V_40 & 0x7f ) << 1 ;
int V_90 = 0 ;
if ( V_132 >= 2 && V_131 [ 0 ] . V_30 < 4 &&
! ( V_131 [ 0 ] . V_17 & V_133 ) && ( V_131 [ 1 ] . V_17 & V_133 ) ) {
T_1 V_134 = 0 ;
int V_36 ;
F_20 ( V_2 -> V_46 , L_9 ,
V_40 >> 1 ) ;
for ( V_36 = 0 ; V_36 < V_131 [ 0 ] . V_30 ; ++ V_36 ) {
V_134 |= V_131 [ 0 ] . V_41 [ V_36 ] << ( V_36 * 8 ) ;
V_134 |= F_41 ( V_36 ) ;
}
V_2 -> V_16 = & V_131 [ 1 ] ;
V_2 -> V_14 = V_135 ;
F_1 ( V_2 , V_40 | F_41 ( 0 ) , V_136 ) ;
F_1 ( V_2 , V_134 , V_137 ) ;
V_90 = 2 ;
} else {
if ( V_131 [ 0 ] . V_17 & V_133 ) {
V_40 |= 1 ;
V_2 -> V_14 = V_135 ;
F_1 ( V_2 , V_40 | F_41 ( 0 ) ,
V_136 ) ;
F_1 ( V_2 , 0 , V_137 ) ;
} else {
V_2 -> V_14 = V_47 ;
}
V_2 -> V_16 = & V_131 [ 0 ] ;
V_90 = 1 ;
}
V_2 -> V_40 = V_131 [ 0 ] . V_40 ;
V_2 -> V_27 = true ;
V_2 -> V_24 = V_62 ;
V_2 -> V_21 = 0 ;
V_2 -> error = 0 ;
F_5 ( V_2 ) ;
return V_90 ;
}
static int F_42 ( struct V_138 * V_139 ,
struct V_130 * V_131 , int V_132 )
{
struct V_1 * V_2 = (struct V_1 * ) V_139 -> V_140 ;
unsigned long V_141 , V_17 ;
T_1 V_8 ;
int V_90 = 0 ;
int V_36 ;
F_34 ( & V_2 -> V_57 , V_17 ) ;
F_33 ( V_2 -> V_142 ) ;
F_33 ( V_2 -> V_113 ) ;
V_2 -> V_22 = false ;
for ( V_36 = 0 ; V_36 < V_132 ; V_36 += V_90 ) {
V_90 = F_40 ( V_2 , V_131 + V_36 , V_132 - V_36 ) ;
if ( V_90 < 0 ) {
F_15 ( V_2 -> V_46 , L_10 ) ;
break;
}
if ( V_36 + V_90 >= V_132 )
V_2 -> V_22 = true ;
F_35 ( & V_2 -> V_57 , V_17 ) ;
F_6 ( V_2 ) ;
V_141 = F_43 ( V_2 -> V_29 , ! V_2 -> V_27 ,
F_44 ( V_143 ) ) ;
F_34 ( & V_2 -> V_57 , V_17 ) ;
if ( V_141 == 0 ) {
F_15 ( V_2 -> V_46 , L_11 ,
F_3 ( V_2 , V_7 ) , V_2 -> V_24 ) ;
F_1 ( V_2 , 0 , V_12 ) ;
V_8 = F_3 ( V_2 , V_9 ) & V_10 ;
V_8 |= V_13 | V_26 ;
F_1 ( V_2 , V_8 , V_9 ) ;
V_2 -> V_24 = V_28 ;
V_90 = - V_144 ;
break;
}
if ( V_2 -> error ) {
V_90 = V_2 -> error ;
break;
}
}
F_36 ( V_2 -> V_113 ) ;
F_36 ( V_2 -> V_142 ) ;
F_35 ( & V_2 -> V_57 , V_17 ) ;
return V_90 < 0 ? V_90 : V_132 ;
}
static T_5 int F_45 ( struct V_145 * V_46 )
{
struct V_1 * V_2 = F_46 ( V_46 ) ;
F_32 ( V_2 , F_47 ( V_2 -> V_142 ) ) ;
return 0 ;
}
static T_1 F_48 ( struct V_138 * V_139 )
{
return V_146 | V_147 | V_148 ;
}
static int F_49 ( struct V_149 * V_150 )
{
struct V_151 * V_152 = V_150 -> V_46 . V_153 ;
const struct V_154 * V_155 ;
struct V_1 * V_2 ;
struct V_156 * V_157 ;
int V_90 = 0 ;
int V_158 ;
T_1 V_3 ;
int V_159 ;
unsigned long V_69 ;
V_2 = F_50 ( & V_150 -> V_46 , sizeof( struct V_1 ) , V_160 ) ;
if ( ! V_2 )
return - V_161 ;
V_155 = F_51 ( V_162 , V_152 ) ;
V_2 -> V_111 = (struct V_163 * ) V_155 -> V_118 ;
F_52 ( & V_150 -> V_46 , & V_2 -> V_71 , true ) ;
F_53 ( V_2 -> V_139 . V_164 , L_12 , sizeof( V_2 -> V_139 . V_164 ) ) ;
V_2 -> V_139 . V_165 = V_166 ;
V_2 -> V_139 . V_167 = & V_168 ;
V_2 -> V_139 . V_169 = 3 ;
V_2 -> V_139 . V_46 . V_153 = V_152 ;
V_2 -> V_139 . V_140 = V_2 ;
V_2 -> V_139 . V_46 . V_170 = & V_150 -> V_46 ;
V_2 -> V_46 = & V_150 -> V_46 ;
F_54 ( & V_2 -> V_57 ) ;
F_55 ( & V_2 -> V_29 ) ;
V_157 = F_56 ( V_150 , V_171 , 0 ) ;
V_2 -> V_5 = F_57 ( & V_150 -> V_46 , V_157 ) ;
if ( F_58 ( V_2 -> V_5 ) )
return F_59 ( V_2 -> V_5 ) ;
V_158 = F_60 ( V_152 , L_13 ) ;
if ( V_2 -> V_111 -> V_172 >= 0 ) {
struct V_173 * V_174 ;
V_174 = F_61 ( V_152 , L_14 ) ;
if ( F_58 ( V_174 ) ) {
F_15 ( & V_150 -> V_46 ,
L_15 ) ;
return F_59 ( V_174 ) ;
}
if ( V_158 < 0 ) {
F_15 ( & V_150 -> V_46 , L_16 ) ;
return - V_100 ;
}
V_3 = F_62 ( 27 + V_158 ) | F_62 ( 11 + V_158 ) ;
V_90 = F_63 ( V_174 , V_2 -> V_111 -> V_172 , V_3 ) ;
if ( V_90 != 0 ) {
F_15 ( V_2 -> V_46 , L_17 , V_90 ) ;
return V_90 ;
}
}
V_159 = F_64 ( V_150 , 0 ) ;
if ( V_159 < 0 ) {
F_15 ( & V_150 -> V_46 , L_18 ) ;
return V_159 ;
}
V_90 = F_65 ( & V_150 -> V_46 , V_159 , F_18 ,
0 , F_66 ( & V_150 -> V_46 ) , V_2 ) ;
if ( V_90 < 0 ) {
F_15 ( & V_150 -> V_46 , L_19 ) ;
return V_90 ;
}
F_67 ( V_150 , V_2 ) ;
if ( V_2 -> V_111 -> V_112 == F_23 ) {
V_2 -> V_142 = F_68 ( & V_150 -> V_46 , NULL ) ;
V_2 -> V_113 = V_2 -> V_142 ;
} else {
V_2 -> V_142 = F_68 ( & V_150 -> V_46 , L_13 ) ;
V_2 -> V_113 = F_68 ( & V_150 -> V_46 , L_20 ) ;
}
if ( F_58 ( V_2 -> V_142 ) ) {
V_90 = F_59 ( V_2 -> V_142 ) ;
if ( V_90 != - V_175 )
F_15 ( & V_150 -> V_46 , L_21 , V_90 ) ;
return V_90 ;
}
if ( F_58 ( V_2 -> V_113 ) ) {
V_90 = F_59 ( V_2 -> V_113 ) ;
if ( V_90 != - V_175 )
F_15 ( & V_150 -> V_46 , L_22 , V_90 ) ;
return V_90 ;
}
V_90 = F_69 ( V_2 -> V_142 ) ;
if ( V_90 < 0 ) {
F_15 ( & V_150 -> V_46 , L_23 , V_90 ) ;
return V_90 ;
}
V_90 = F_69 ( V_2 -> V_113 ) ;
if ( V_90 < 0 ) {
F_15 ( & V_150 -> V_46 , L_24 , V_90 ) ;
goto V_176;
}
V_2 -> V_121 . V_177 = F_38 ;
V_90 = F_70 ( V_2 -> V_142 , & V_2 -> V_121 ) ;
if ( V_90 != 0 ) {
F_15 ( & V_150 -> V_46 , L_25 ) ;
goto V_178;
}
V_69 = F_47 ( V_2 -> V_142 ) ;
F_32 ( V_2 , V_69 ) ;
V_90 = F_71 ( & V_2 -> V_139 ) ;
if ( V_90 < 0 )
goto V_179;
F_72 ( & V_150 -> V_46 , L_26 , V_2 -> V_5 ) ;
return 0 ;
V_179:
F_73 ( V_2 -> V_142 , & V_2 -> V_121 ) ;
V_178:
F_74 ( V_2 -> V_113 ) ;
V_176:
F_74 ( V_2 -> V_142 ) ;
return V_90 ;
}
static int F_75 ( struct V_149 * V_150 )
{
struct V_1 * V_2 = F_76 ( V_150 ) ;
F_77 ( & V_2 -> V_139 ) ;
F_73 ( V_2 -> V_142 , & V_2 -> V_121 ) ;
F_74 ( V_2 -> V_113 ) ;
F_74 ( V_2 -> V_142 ) ;
return 0 ;
}

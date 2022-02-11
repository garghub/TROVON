static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 ;
}
static inline T_1 F_2 ( struct V_1 * V_2 , enum V_4 type ,
unsigned int V_5 )
{
return F_3 ( V_2 -> V_6 , V_2 -> V_7 [ type ] + V_5 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , enum V_4 type ,
unsigned int V_5 , unsigned int V_8 )
{
F_5 ( V_2 -> V_6 , V_8 , V_2 -> V_7 [ type ] + V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < 1000 ; V_9 ++ ) {
if ( ! ( F_2 ( V_2 , V_10 , V_11 ) & 1 ) )
return 0 ;
F_7 ( 1 ) ;
}
F_8 ( & V_2 -> V_12 -> V_13 , L_1 ) ;
return - V_14 ;
}
static inline bool F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 < 4 )
return true ;
return false ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_4 ( V_2 , V_10 , V_16 , 1 ) ;
F_4 ( V_2 , V_10 , V_17 , 1 ) ;
F_4 ( V_2 , V_10 , V_16 , 0 ) ;
F_4 ( V_2 , V_10 , V_17 , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 , V_10 , V_18 ) &
V_19 ) ;
}
static inline T_1 F_12 ( struct V_1 * V_2 )
{
T_1 V_8 = F_2 ( V_2 , V_10 , V_20 ) ;
if ( F_9 ( V_2 ) )
V_8 = F_13 ( V_8 ) ;
return V_8 ;
}
static inline void F_14 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
F_4 ( V_2 , V_10 , V_21 ,
V_22 ) ;
}
static inline void F_15 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_10 , V_21 ,
V_23 ) ;
F_10 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 * V_24 = ( T_1 * ) V_2 -> V_25 -> V_24 ;
T_1 V_8 = 0 ;
F_17 ( & V_2 -> V_12 -> V_13 , L_2 , V_2 -> V_25 ,
V_2 -> V_25 -> V_24 , V_2 -> V_26 ) ;
while ( ! F_11 ( V_2 ) ) {
V_8 = F_12 ( V_2 ) ;
if ( F_18 ( V_2 -> V_26 >= 4 ) &&
F_19 ( ( V_27 ) V_24 , 4 ) ) {
V_24 [ V_2 -> V_28 ++ ] = V_8 ;
V_2 -> V_26 -= 4 ;
} else {
T_2 * V_29 = ( T_2 * ) & V_24 [ V_2 -> V_28 ] ;
V_8 = F_20 ( V_8 ) ;
while ( V_2 -> V_26 ) {
* V_29 ++ = ( T_2 ) V_8 ;
V_8 >>= 8 ;
V_2 -> V_26 -- ;
}
}
}
}
static void F_21 ( struct V_1 * V_2 , T_2 V_30 ,
int V_31 , int V_32 , int V_33 )
{
F_4 ( V_2 , V_10 , V_34 , 0 ) ;
F_4 ( V_2 , V_10 , V_35 , V_32 ) ;
F_4 ( V_2 , V_10 , V_36 , V_31 ) ;
F_4 ( V_2 , V_10 , V_37 , V_30 ) ;
F_4 ( V_2 , V_10 , V_34 , V_33 ) ;
}
static int F_22 ( struct V_1 * V_2 , int V_38 ,
int V_39 , int V_40 )
{
int V_32 = 0 , V_31 = 0 ;
T_2 V_41 = V_42 ;
int V_33 = 1 , V_43 = 0 ;
bool V_44 = false ;
F_17 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_38 , V_39 , V_40 ) ;
if ( V_39 == V_45 ) {
V_31 = V_46 ;
V_44 = true ;
}
V_31 |= 8 ;
switch ( V_38 ) {
case V_47 :
if ( V_39 == V_48 )
V_33 = 0 ;
else
V_41 = V_49 ;
break;
case V_50 :
V_32 = 0x00000001 ;
if ( V_40 ) {
V_32 |= 0x00010100 ;
V_31 = V_51 ;
V_41 = V_52 ;
if ( V_44 )
V_41 = V_53 ;
} else {
V_41 = V_54 ;
if ( V_44 )
V_41 = V_55 ;
}
break;
case V_56 :
V_32 = 0x00000002 ;
if ( V_40 ) {
V_32 |= 0x00020200 ;
V_31 = 4 ;
V_31 |= V_46 ;
V_41 = V_57 ;
if ( V_44 )
V_41 = V_58 ;
} else {
V_41 = V_59 ;
if ( V_44 )
V_41 = V_60 ;
}
break;
default:
V_43 = - V_61 ;
break;
}
if ( V_43 == 0 )
F_21 ( V_2 , V_41 , V_31 , V_32 ,
V_33 ) ;
return V_43 ;
}
static int F_23 ( struct V_1 * V_2 , int V_38 ,
int V_39 , int V_40 )
{
T_1 V_8 = F_2 ( V_2 , V_10 , V_62 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_38 , V_39 , V_40 ) ;
switch ( V_38 ) {
case V_47 :
V_8 &= ~ ( V_63 |
V_64 ) ;
break;
case V_56 :
V_8 &= ~ V_64 ;
V_8 |= V_63 ;
break;
case V_50 :
V_8 &= ~ V_63 ;
V_8 |= V_64 ;
break;
default:
return - V_61 ;
}
if ( V_39 == V_45 )
V_8 |= V_65 ;
else
V_8 &= ~ V_65 ;
V_8 |= V_66 ;
F_4 ( V_2 , V_10 , V_62 , V_8 ) ;
F_21 ( V_2 , V_42 , 0 , 0 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
int V_38 , int V_39 , int V_40 )
{
int error = 0 ;
V_2 -> V_67 . V_33 = true ;
if ( ! F_9 ( V_2 ) ) {
T_1 V_68 , V_69 ;
V_68 = F_2 ( V_2 , V_10 , V_62 ) ;
V_69 = V_66 ;
if ( V_68 & V_69 || V_2 -> V_70 & V_69 ) {
V_2 -> V_67 . V_33 = false ;
F_4 ( V_2 , V_10 , V_34 ,
0 ) ;
if ( ( V_68 | V_2 -> V_70 ) &
V_64 )
V_38 = V_50 ;
else if ( ( V_68 | V_2 -> V_70 ) &
V_63 )
V_38 = V_56 ;
error = F_23 ( V_2 , V_38 , V_39 ,
V_40 ) ;
}
}
if ( V_2 -> V_67 . V_33 )
error = F_22 ( V_2 , V_38 , V_39 , V_40 ) ;
if ( error ) {
F_8 ( & V_2 -> V_12 -> V_13 ,
L_5 ,
V_38 , V_39 , V_40 ) ;
} else if ( V_2 -> V_67 . V_38 != V_38 ||
V_2 -> V_67 . V_39 != V_39 ||
V_2 -> V_67 . V_40 != V_40 ) {
V_2 -> V_67 . V_38 = V_38 ;
V_2 -> V_67 . V_39 = V_39 ;
V_2 -> V_67 . V_40 = V_40 ;
F_17 ( & V_2 -> V_12 -> V_13 ,
L_6 ,
V_2 -> V_71 ,
V_2 -> V_67 . V_38 ,
V_2 -> V_67 . V_39 ,
V_2 -> V_67 . V_40 != - 1 ? L_7 : L_8 ) ;
}
return error ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) || ( V_2 -> V_72 ) )
return;
V_2 -> V_72 = 1 ;
if ( ( F_2 ( V_2 , V_10 , V_73 ) & 1 ) == 0 )
return;
F_10 ( V_2 ) ;
F_7 ( 1 ) ;
F_4 ( V_2 , V_10 , V_73 , 0 ) ;
F_7 ( 1 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) || ( ! V_2 -> V_72 ) )
return;
V_2 -> V_72 = 0 ;
if ( ( F_2 ( V_2 , V_10 , V_73 ) & 1 ) )
return;
F_6 ( V_2 ) ;
F_4 ( V_2 , V_10 , V_73 , 1 ) ;
F_7 ( 1 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_74 )
{
T_1 V_8 = 0 ;
if ( V_2 -> V_71 == V_74 )
return;
if ( V_2 -> V_7 [ V_75 ] ) {
V_8 = F_2 ( V_2 , V_75 , 0 ) ;
V_8 = ( V_8 & ~ 0xff ) | ( 1 << V_74 ) ;
F_4 ( V_2 , V_75 , 0 , V_8 ) ;
F_28 ( 10 , 20 ) ;
}
V_2 -> V_71 = V_74 ;
}
static void F_29 ( struct V_1 * V_2 ,
const struct V_76 * V_77 )
{
T_1 V_78 , V_79 = 0 ;
if ( V_77 -> V_80 )
V_79 = V_2 -> V_81 / ( 2 * V_77 -> V_80 ) ;
V_78 = F_30 ( V_79 , V_82 , V_83 ) ;
F_4 ( V_2 , V_84 , V_85 , V_78 ) ;
V_78 = V_86 ;
if ( V_77 -> V_87 != 16 )
V_78 |= V_77 -> V_87 << 2 ;
V_78 |= V_77 -> V_88 & 3 ;
F_4 ( V_2 , V_84 , V_89 , V_78 ) ;
V_2 -> V_90 = * V_77 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_91 * V_92 ,
struct V_93 * V_94 )
{
struct V_76 V_77 ;
V_77 . V_80 = V_94 -> V_80 ;
V_77 . V_87 = V_94 -> V_87 ;
V_77 . V_88 = V_92 -> V_88 ;
F_29 ( V_2 , & V_77 ) ;
}
static int F_32 ( struct V_91 * V_92 )
{
struct V_76 * V_77 ;
if ( V_92 -> V_87 > 16 )
return - V_61 ;
V_77 = F_33 ( V_92 ) ;
if ( ! V_77 ) {
V_77 = F_34 ( sizeof( * V_77 ) , V_95 ) ;
if ( ! V_77 )
return - V_96 ;
F_35 ( V_92 , V_77 ) ;
}
V_77 -> V_80 = V_92 -> V_97 ;
V_77 -> V_88 = V_92 -> V_88 ;
if ( V_92 -> V_87 )
V_77 -> V_87 = V_92 -> V_87 ;
else
V_77 -> V_87 = 8 ;
return 0 ;
}
static bool F_36 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
if ( V_99 -> V_100 &&
F_37 ( V_2 -> V_101 , V_99 -> V_94 ) )
return true ;
else
return false ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_98 * V_99 , int V_102 )
{
int V_103 = V_104 ;
if ( V_99 -> V_94 -> V_87 <= 8 )
V_99 -> V_105 ++ ;
else
V_99 -> V_105 += 2 ;
if ( V_99 -> V_105 >= V_99 -> V_94 -> V_106 ) {
if ( V_99 -> V_94 -> V_107 &&
( V_102 & V_108 ) )
V_103 |= V_108 ;
if ( V_99 -> V_94 -> V_109 &&
( V_102 & V_110 ) )
V_103 |= V_110 ;
if ( V_103 )
goto V_111;
F_17 ( & V_2 -> V_12 -> V_13 , L_9 ) ;
if ( F_36 ( V_2 , V_99 ) )
V_103 = V_112 ;
else
V_103 = V_113 ;
V_99 -> V_94 = NULL ;
}
V_111:
F_17 ( & V_2 -> V_12 -> V_13 , L_10 ,
V_99 -> V_94 , V_99 -> V_94 ? V_99 -> V_94 -> V_106 : 0 , V_99 -> V_105 , V_103 ) ;
return V_103 ;
}
static inline T_2 F_39 ( struct V_1 * V_2 , int V_114 )
{
T_1 V_115 = V_116 + ( V_114 << 3 ) + 0x4 ;
return F_2 ( V_2 , V_84 , V_115 ) & 0xff ;
}
static inline T_3 F_40 ( struct V_1 * V_2 , int V_114 )
{
T_1 V_117 = V_116 ;
T_1 V_118 = V_117 + ( V_114 << 3 ) + 0x4 ;
T_1 V_119 = V_117 + ( V_114 << 3 ) ;
return ( F_2 ( V_2 , V_84 , V_118 ) & 0xff ) |
( ( F_2 ( V_2 , V_84 , V_119 ) & 0xff ) << 8 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_120 )
{
struct V_98 V_121 ;
int V_114 ;
F_26 ( V_2 ) ;
if ( V_120 > V_122 ) {
F_42 ( & V_2 -> V_12 -> V_13 , L_11 , V_123 ) ;
return;
}
V_121 = V_2 -> V_124 ;
for ( V_114 = 0 ; V_114 < V_120 ; V_114 ++ ) {
if ( V_121 . V_94 -> V_87 <= 8 ) {
T_2 * V_24 = V_121 . V_94 -> V_125 ;
if ( V_24 )
V_24 [ V_121 . V_105 ] = F_39 ( V_2 , V_114 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_12 ,
V_24 ? V_24 [ V_121 . V_105 ] : 0xff ) ;
} else {
T_3 * V_24 = V_121 . V_94 -> V_125 ;
if ( V_24 )
V_24 [ V_121 . V_105 / 2 ] = F_40 ( V_2 ,
V_114 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_13 ,
V_24 ? V_24 [ V_121 . V_105 ] : 0xffff ) ;
}
F_38 ( V_2 , & V_121 ,
V_104 ) ;
}
V_2 -> V_124 = V_121 ;
}
static inline void F_43 ( struct V_1 * V_2 , int V_114 ,
T_2 V_68 )
{
T_1 V_117 = V_126 + ( V_114 << 3 ) ;
F_4 ( V_2 , V_84 , V_117 , V_68 ) ;
}
static inline void F_44 ( struct V_1 * V_2 , int V_114 ,
T_3 V_68 )
{
T_1 V_117 = V_126 ;
T_1 V_119 = V_117 + ( V_114 << 3 ) ;
T_1 V_118 = V_117 + ( V_114 << 3 ) + 0x4 ;
F_4 ( V_2 , V_84 , V_119 , ( V_68 >> 8 ) ) ;
F_4 ( V_2 , V_84 , V_118 , ( V_68 & 0xff ) ) ;
}
static inline T_1 F_45 ( struct V_1 * V_2 , int V_114 )
{
return F_2 ( V_2 , V_84 , V_127 + ( V_114 << 2 ) ) ;
}
static inline void F_46 ( struct V_1 * V_2 , int V_114 , T_1 V_68 )
{
F_4 ( V_2 , V_84 , ( V_127 + ( V_114 << 2 ) ) , V_68 ) ;
}
static int F_47 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_98 V_121 ;
int V_114 = 0 , V_128 = 0 ;
T_1 V_129 = 0 ;
F_26 ( V_2 ) ;
V_121 = V_2 -> V_124 ;
F_31 ( V_2 , V_92 , V_121 . V_94 ) ;
while ( ! V_128 && V_114 < V_122 ) {
if ( V_121 . V_94 -> V_87 <= 8 ) {
const T_2 * V_24 = V_121 . V_94 -> V_130 ;
T_2 V_68 = V_24 ? V_24 [ V_121 . V_105 ] : 0xff ;
F_43 ( V_2 , V_114 , V_68 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_14 , V_68 ) ;
} else {
const T_3 * V_24 = V_121 . V_94 -> V_130 ;
T_3 V_68 = V_24 ? V_24 [ V_121 . V_105 / 2 ] : 0xffff ;
F_44 ( V_2 , V_114 , V_68 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_15 , V_68 ) ;
}
V_129 = V_131 ;
V_129 |= ( ~ ( 1 << V_92 -> V_132 ) &
V_133 ) ;
V_129 |= ( ( V_121 . V_94 -> V_87 <= 8 ) ? 0 :
V_134 ) ;
F_46 ( V_2 , V_114 , V_129 ) ;
V_128 = F_38 ( V_2 , & V_121 ,
V_135 ) ;
V_114 ++ ;
}
if ( ! V_114 ) {
F_42 ( & V_2 -> V_12 -> V_13 , L_16 , V_123 ) ;
goto V_111;
}
F_17 ( & V_2 -> V_12 -> V_13 , L_17 , V_114 ) ;
F_4 ( V_2 , V_84 , V_136 , 0 ) ;
F_4 ( V_2 , V_84 , V_137 , V_114 - 1 ) ;
if ( V_128 & V_138 ) {
V_129 = F_45 ( V_2 , V_114 - 1 ) &
~ V_131 ;
F_46 ( V_2 , V_114 - 1 , V_129 ) ;
}
if ( F_1 ( V_2 ) )
F_4 ( V_2 , V_84 , V_139 , 1 ) ;
F_48 () ;
F_4 ( V_2 , V_84 , V_140 , 0xe0 ) ;
V_111:
return V_114 ;
}
static int F_49 ( struct V_91 * V_92 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = F_50 ( V_92 -> V_101 ) ;
T_1 V_143 = 0 , V_106 , V_144 , V_145 ;
int V_103 = 0 ;
unsigned long V_146 = F_51 ( 100 ) ;
struct V_147 * V_148 = V_2 -> V_148 ;
if ( F_9 ( V_2 ) )
if ( V_142 -> V_149 == V_45 )
return - V_14 ;
F_27 ( V_2 , V_92 -> V_132 ) ;
F_4 ( V_2 , V_84 , V_139 , 0 ) ;
if ( F_9 ( V_2 ) == false ) {
V_143 = V_142 -> V_150 & 0xff000000 ;
F_4 ( V_2 , V_10 ,
V_151 , V_143 ) ;
}
if ( ! V_2 -> V_67 . V_33 )
V_143 = V_142 -> V_150 ;
else
V_143 = V_142 -> V_150 & 0x00ffffff ;
if ( F_9 ( V_2 ) == true )
V_143 = ( V_143 + 0xc00000 ) & 0xffffff ;
V_106 = V_142 -> V_106 ;
V_2 -> V_28 = 0 ;
do {
if ( V_106 > V_152 )
V_144 = V_152 ;
else
V_144 = V_106 ;
F_52 ( & V_2 -> V_153 ) ;
F_25 ( V_2 ) ;
V_145 = ( V_144 + 3 ) >> 2 ;
V_2 -> V_25 = V_142 ;
V_2 -> V_154 = 0 ;
V_2 -> V_26 = V_144 ;
F_17 ( & V_2 -> V_12 -> V_13 ,
L_18 , V_143 , V_144 ) ;
F_4 ( V_2 , V_10 , V_155 , V_143 ) ;
F_4 ( V_2 , V_10 , V_156 , V_145 ) ;
F_4 ( V_2 , V_10 , V_157 , 0 ) ;
if ( V_2 -> V_148 ) {
V_148 -> V_158 ( V_148 , V_159 ) ;
V_148 -> V_160 ( V_148 , V_161 , true ) ;
}
F_48 () ;
F_14 ( V_2 ) ;
if ( ! F_53 ( & V_2 -> V_153 , V_146 ) ) {
F_42 ( & V_2 -> V_12 -> V_13 , L_19 ) ;
V_103 = - V_162 ;
break;
}
V_142 -> V_163 += V_144 ;
V_143 += V_144 ;
V_106 -= V_144 ;
} while ( V_106 );
return V_103 ;
}
static int F_54 ( struct V_164 * V_101 ,
struct V_91 * V_92 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = F_50 ( V_101 ) ;
int V_120 ;
unsigned long V_146 = F_51 ( 100 ) ;
F_27 ( V_2 , V_92 -> V_132 ) ;
V_2 -> V_124 . V_94 = V_94 ;
V_2 -> V_124 . V_105 = 0 ;
while ( V_2 -> V_124 . V_105 < V_94 -> V_106 ) {
F_52 ( & V_2 -> V_165 ) ;
V_120 = F_47 ( V_2 , V_92 ) ;
if ( ! F_53 ( & V_2 -> V_165 , V_146 ) ) {
F_42 ( & V_2 -> V_12 -> V_13 , L_20 ) ;
return - V_162 ;
}
F_41 ( V_2 , V_120 ) ;
}
return 0 ;
}
static int F_55 ( struct V_91 * V_92 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = F_50 ( V_92 -> V_101 ) ;
struct V_93 V_166 [ 2 ] ;
T_2 V_167 [ 6 ] ;
int V_103 ;
memset ( V_167 , 0 , sizeof( V_167 ) ) ;
memset ( V_166 , 0 , sizeof( V_166 ) ) ;
V_167 [ 0 ] = V_142 -> V_168 ;
V_167 [ 1 ] = V_142 -> V_150 >> ( V_142 -> V_149 * 8 - 8 ) ;
V_167 [ 2 ] = V_142 -> V_150 >> ( V_142 -> V_149 * 8 - 16 ) ;
V_167 [ 3 ] = V_142 -> V_150 >> ( V_142 -> V_149 * 8 - 24 ) ;
V_167 [ 4 ] = V_142 -> V_150 >> ( V_142 -> V_149 * 8 - 32 ) ;
V_166 [ 0 ] . V_130 = V_167 ;
V_166 [ 0 ] . V_106 = V_142 -> V_149 + V_142 -> V_169 + 1 ;
V_166 [ 0 ] . V_87 = V_92 -> V_87 ;
V_166 [ 0 ] . V_170 = V_142 -> V_171 ;
V_2 -> V_124 . V_100 = false ;
V_103 = F_54 ( V_92 -> V_101 , V_92 , & V_166 [ 0 ] ) ;
V_2 -> V_124 . V_100 = true ;
if ( ! V_103 ) {
V_166 [ 1 ] . V_125 = V_142 -> V_24 ;
V_166 [ 1 ] . V_106 = V_142 -> V_106 ;
V_166 [ 1 ] . V_172 = V_142 -> V_173 ;
V_166 [ 1 ] . V_87 = V_92 -> V_87 ;
V_103 = F_54 ( V_92 -> V_101 , V_92 , & V_166 [ 1 ] ) ;
}
if ( ! V_103 )
V_142 -> V_163 = V_142 -> V_106 ;
return V_103 ;
}
static int F_56 ( struct V_91 * V_92 ,
struct V_141 * V_142 )
{
struct V_1 * V_2 = F_50 ( V_92 -> V_101 ) ;
int V_103 = 0 ;
bool V_174 = false ;
T_1 V_175 , V_39 , V_143 , V_106 ;
T_4 * V_24 ;
V_24 = V_142 -> V_24 ;
V_143 = V_142 -> V_150 ;
V_106 = V_142 -> V_106 ;
if ( F_9 ( V_2 ) == true ) {
V_143 = ( V_143 + 0xc00000 ) & 0xffffff ;
if ( ( ~ V_176 & V_143 ) ^
( ~ V_176 & ( V_143 + V_106 - 1 ) ) )
V_174 = true ;
}
if ( ! F_19 ( ( V_27 ) V_143 , 4 ) || ! F_19 ( ( V_27 ) V_24 , 4 ) ||
V_106 < 4 )
V_174 = true ;
if ( V_174 )
return F_55 ( V_92 , V_142 ) ;
V_175 = V_142 -> V_173 ? V_142 -> V_173 : V_47 ;
V_39 = V_142 -> V_149 ;
V_103 = F_24 ( V_2 , V_175 , V_39 , - 1 ) ;
if ( ! V_103 )
V_103 = F_49 ( V_92 , V_142 ) ;
return V_103 ;
}
static void F_57 ( struct V_91 * V_92 )
{
struct V_76 * V_77 = F_33 ( V_92 ) ;
F_58 ( V_77 ) ;
}
static T_5 F_59 ( int V_177 , void * V_178 )
{
struct V_179 * V_180 = V_178 ;
struct V_1 * V_2 = V_180 -> V_13 ;
T_1 V_181 = F_2 ( V_2 , V_84 , V_182 ) ;
if ( V_181 & V_183 ) {
struct V_147 * V_148 = V_2 -> V_148 ;
V_181 &= ~ V_183 ;
F_4 ( V_2 , V_84 , V_182 , V_181 ) ;
if ( V_2 -> V_148 )
V_148 -> V_158 ( V_148 , V_184 ) ;
F_60 ( & V_2 -> V_165 ) ;
return V_185 ;
}
return V_186 ;
}
static T_5 F_61 ( int V_177 , void * V_178 )
{
struct V_179 * V_180 = V_178 ;
struct V_1 * V_2 = V_180 -> V_13 ;
struct V_147 * V_148 = V_2 -> V_148 ;
T_1 V_181 = V_180 -> V_187 -> V_69 ;
if ( V_2 -> V_72 && V_2 -> V_25 ) {
F_16 ( V_2 ) ;
if ( V_2 -> V_26 == 0 ) {
V_2 -> V_25 = NULL ;
if ( V_2 -> V_148 ) {
V_148 -> V_160 ( V_148 , V_161 ,
false ) ;
V_181 = V_188 ;
}
if ( V_2 -> V_154 )
F_15 ( V_2 ) ;
else
F_10 ( V_2 ) ;
}
if ( V_2 -> V_148 )
V_148 -> V_158 ( V_148 , V_161 ) ;
}
V_181 &= V_188 ;
if ( V_2 -> V_72 && V_181 && V_2 -> V_26 == 0 )
F_60 ( & V_2 -> V_153 ) ;
return V_185 ;
}
static T_5 F_62 ( int V_177 , void * V_178 )
{
struct V_179 * V_180 = V_178 ;
struct V_1 * V_2 = V_180 -> V_13 ;
struct V_147 * V_148 = V_2 -> V_148 ;
F_42 ( & V_2 -> V_12 -> V_13 , L_21 ) ;
V_2 -> V_154 = - V_14 ;
if ( V_2 -> V_148 )
V_148 -> V_158 ( V_148 , V_189 ) ;
F_60 ( & V_2 -> V_153 ) ;
return V_185 ;
}
static T_5 F_63 ( int V_177 , void * V_178 )
{
struct V_179 * V_180 = V_178 ;
struct V_1 * V_2 = V_180 -> V_13 ;
struct V_147 * V_148 = V_2 -> V_148 ;
T_5 V_103 = V_186 ;
if ( V_148 ) {
T_1 V_181 = V_148 -> V_190 ( V_148 ) ;
if ( V_181 & V_184 )
V_103 = F_59 ( V_177 , V_178 ) ;
else if ( V_181 & V_161 )
V_103 = F_61 ( V_177 , V_178 ) ;
else if ( V_181 & V_189 )
V_103 = F_62 ( V_177 , V_178 ) ;
}
return V_103 ;
}
static void F_64 ( struct V_1 * V_2 )
{
T_1 V_68 = 0 ;
V_68 = F_2 ( V_2 , V_10 , V_191 ) ;
V_2 -> V_15 = ( V_68 >> 8 ) & 0xff ;
V_2 -> V_192 = V_68 & 0xff ;
if ( ! ( F_9 ( V_2 ) ) ) {
F_4 ( V_2 , V_10 , V_193 , 0 ) ;
F_4 ( V_2 , V_10 , V_194 , 1 ) ;
}
V_2 -> V_72 = 1 ;
F_26 ( V_2 ) ;
F_4 ( V_2 , V_10 , V_16 , 0 ) ;
F_4 ( V_2 , V_10 , V_17 , 0 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_76 V_195 ;
F_4 ( V_2 , V_84 , V_196 , 0 ) ;
F_4 ( V_2 , V_84 , V_197 , 0 ) ;
F_4 ( V_2 , V_84 , V_136 , 0 ) ;
F_4 ( V_2 , V_84 , V_137 , 0 ) ;
F_4 ( V_2 , V_84 , V_140 , 0x20 ) ;
V_195 . V_88 = V_198 ;
V_195 . V_87 = 8 ;
V_195 . V_80 = V_2 -> V_97 ;
F_29 ( V_2 , & V_195 ) ;
if ( F_1 ( V_2 ) )
F_64 ( V_2 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_84 , V_140 , 0 ) ;
if ( F_1 ( V_2 ) )
F_4 ( V_2 , V_84 , V_139 , 0 ) ;
}
int F_67 ( struct V_199 * V_12 ,
struct V_147 * V_148 )
{
struct V_200 * V_13 = & V_12 -> V_13 ;
struct V_1 * V_2 ;
struct V_164 * V_101 ;
struct V_201 * V_202 ;
int V_177 , V_103 = 0 , V_203 = 0 ;
T_1 V_68 ;
const char * V_204 = NULL ;
int V_205 = F_68 ( V_206 ) ;
if ( ! V_13 -> V_207 )
return - V_208 ;
if ( ! F_69 ( V_209 , V_13 -> V_207 ) )
return - V_208 ;
V_101 = F_70 ( V_13 , sizeof( struct V_1 ) ) ;
if ( ! V_101 ) {
F_42 ( V_13 , L_22 ) ;
return - V_96 ;
}
V_2 = F_50 ( V_101 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_124 . V_94 = NULL ;
V_2 -> V_124 . V_105 = 0 ;
V_2 -> V_124 . V_100 = true ;
V_2 -> V_101 = V_101 ;
V_101 -> V_210 = - 1 ;
V_101 -> V_211 = V_212 | V_213 | V_214 | V_215 ;
V_101 -> V_216 = F_32 ;
V_101 -> V_217 = F_54 ;
V_101 -> V_218 = F_56 ;
V_101 -> V_219 = F_57 ;
V_101 -> V_13 . V_207 = V_13 -> V_207 ;
V_101 -> V_220 = V_221 ;
V_2 -> V_6 = F_71 ( V_13 -> V_207 ) ;
if ( ! F_72 ( V_13 -> V_207 , L_23 , & V_68 ) )
V_101 -> V_220 = V_68 ;
V_202 = F_73 ( V_12 , V_222 , L_24 ) ;
if ( ! V_202 )
V_202 = F_73 ( V_12 , V_222 ,
L_25 ) ;
if ( V_202 ) {
V_2 -> V_7 [ V_84 ] = F_74 ( V_13 , V_202 ) ;
if ( F_75 ( V_2 -> V_7 [ V_84 ] ) ) {
V_103 = F_76 ( V_2 -> V_7 [ V_84 ] ) ;
goto V_223;
}
} else {
goto V_223;
}
V_202 = F_73 ( V_12 , V_222 , L_26 ) ;
if ( V_202 ) {
V_2 -> V_7 [ V_10 ] = F_74 ( V_13 , V_202 ) ;
if ( F_75 ( V_2 -> V_7 [ V_10 ] ) ) {
V_103 = F_76 ( V_2 -> V_7 [ V_10 ] ) ;
goto V_223;
}
V_2 -> V_3 = true ;
} else {
V_2 -> V_3 = false ;
}
F_77 ( V_13 , L_27 , V_2 -> V_3 ? L_28 : L_8 ) ;
V_202 = F_73 ( V_12 , V_222 , L_29 ) ;
if ( V_202 ) {
V_2 -> V_7 [ V_75 ] = F_74 ( V_13 , V_202 ) ;
if ( F_75 ( V_2 -> V_7 [ V_75 ] ) ) {
V_103 = F_76 ( V_2 -> V_7 [ V_75 ] ) ;
goto V_223;
}
}
V_2 -> V_224 = F_78 ( V_205 , sizeof( struct V_179 ) ,
V_95 ) ;
if ( ! V_2 -> V_224 ) {
V_103 = - V_96 ;
goto V_223;
}
for ( V_68 = 0 ; V_68 < V_205 ; V_68 ++ ) {
V_177 = - 1 ;
V_204 = V_206 [ V_68 ] . V_225 ;
if ( V_206 [ V_68 ] . V_226 == V_227 ) {
V_177 = F_79 ( V_12 , V_204 ) ;
} else if ( ! V_203 && V_148 ) {
V_177 = F_80 ( V_12 , 0 ) ;
}
if ( V_177 >= 0 ) {
V_103 = F_81 ( & V_12 -> V_13 , V_177 ,
V_206 [ V_68 ] . V_228 , 0 ,
V_204 ,
& V_2 -> V_224 [ V_68 ] ) ;
if ( V_103 < 0 ) {
F_42 ( & V_12 -> V_13 , L_30 , V_204 ) ;
goto V_223;
}
V_2 -> V_224 [ V_68 ] . V_13 = V_2 ;
V_2 -> V_224 [ V_68 ] . V_187 = & V_206 [ V_68 ] ;
V_203 ++ ;
F_17 ( & V_12 -> V_13 , L_31 ,
V_206 [ V_68 ] . V_225 ,
V_177 ) ;
}
}
if ( ! V_203 ) {
F_42 ( & V_12 -> V_13 , L_32 ) ;
V_103 = - V_61 ;
goto V_223;
}
if ( V_148 ) {
V_2 -> V_148 = V_148 ;
V_148 -> V_160 ( V_148 , V_184 , true ) ;
} else {
V_2 -> V_148 = NULL ;
}
V_2 -> V_229 = F_82 ( & V_12 -> V_13 , NULL ) ;
if ( F_75 ( V_2 -> V_229 ) ) {
F_8 ( V_13 , L_33 ) ;
V_103 = F_76 ( V_2 -> V_229 ) ;
goto V_223;
}
V_103 = F_83 ( V_2 -> V_229 ) ;
if ( V_103 ) {
F_42 ( V_13 , L_34 ) ;
goto V_223;
}
V_2 -> V_81 = F_84 ( V_2 -> V_229 ) ;
V_2 -> V_97 = V_2 -> V_81 / ( V_82 * 2 ) ;
F_65 ( V_2 ) ;
F_85 ( & V_2 -> V_165 ) ;
F_85 ( & V_2 -> V_153 ) ;
V_2 -> V_71 = - 1 ;
F_86 ( V_12 , V_2 ) ;
V_2 -> V_67 . V_38 = - 1 ;
V_2 -> V_67 . V_39 = - 1 ;
V_2 -> V_67 . V_40 = - 1 ;
V_103 = F_87 ( & V_12 -> V_13 , V_101 ) ;
if ( V_103 < 0 ) {
F_42 ( V_13 , L_35 ) ;
goto V_230;
}
return 0 ;
V_230:
F_66 ( V_2 ) ;
F_88 ( V_2 -> V_229 ) ;
V_223:
F_89 ( V_101 ) ;
F_58 ( V_2 -> V_224 ) ;
return V_103 ;
}
int F_90 ( struct V_199 * V_12 )
{
struct V_1 * V_2 = F_91 ( V_12 ) ;
F_66 ( V_2 ) ;
F_88 ( V_2 -> V_229 ) ;
F_58 ( V_2 -> V_224 ) ;
F_92 ( V_2 -> V_101 ) ;
return 0 ;
}
static int T_6 F_93 ( struct V_200 * V_13 )
{
struct V_1 * V_2 = F_94 ( V_13 ) ;
F_95 ( V_2 -> V_101 ) ;
F_96 ( V_2 -> V_229 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
static int T_6 F_97 ( struct V_200 * V_13 )
{
struct V_1 * V_2 = F_94 ( V_13 ) ;
int V_103 = 0 ;
F_65 ( V_2 ) ;
F_27 ( V_2 , V_2 -> V_71 ) ;
if ( V_2 -> V_148 )
V_2 -> V_148 -> V_160 ( V_2 -> V_148 , V_184 ,
true ) ;
V_103 = F_98 ( V_2 -> V_229 ) ;
if ( ! V_103 )
F_99 ( V_2 -> V_101 ) ;
return V_103 ;
}

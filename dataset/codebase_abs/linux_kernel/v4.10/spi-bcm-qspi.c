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
static int F_36 ( struct V_1 * V_2 ,
struct V_98 * V_99 , int V_100 )
{
int V_101 = V_102 ;
if ( V_99 -> V_94 -> V_87 <= 8 )
V_99 -> V_103 ++ ;
else
V_99 -> V_103 += 2 ;
if ( V_99 -> V_103 >= V_99 -> V_94 -> V_104 ) {
if ( V_99 -> V_94 -> V_105 &&
( V_100 & V_106 ) )
V_101 |= V_106 ;
if ( V_99 -> V_94 -> V_107 &&
( V_100 & V_108 ) )
V_101 |= V_108 ;
if ( V_101 )
goto V_109;
F_17 ( & V_2 -> V_12 -> V_13 , L_9 ) ;
if ( F_37 ( V_2 -> V_110 , V_99 -> V_94 ) )
V_101 = V_111 ;
else
V_101 = V_112 ;
V_99 -> V_94 = NULL ;
}
V_109:
F_17 ( & V_2 -> V_12 -> V_13 , L_10 ,
V_99 -> V_94 , V_99 -> V_94 ? V_99 -> V_94 -> V_104 : 0 , V_99 -> V_103 , V_101 ) ;
return V_101 ;
}
static inline T_2 F_38 ( struct V_1 * V_2 , int V_113 )
{
T_1 V_114 = V_115 + ( V_113 << 3 ) + 0x4 ;
return F_2 ( V_2 , V_84 , V_114 ) & 0xff ;
}
static inline T_3 F_39 ( struct V_1 * V_2 , int V_113 )
{
T_1 V_116 = V_115 ;
T_1 V_117 = V_116 + ( V_113 << 3 ) + 0x4 ;
T_1 V_118 = V_116 + ( V_113 << 3 ) ;
return ( F_2 ( V_2 , V_84 , V_117 ) & 0xff ) |
( ( F_2 ( V_2 , V_84 , V_118 ) & 0xff ) << 8 ) ;
}
static void F_40 ( struct V_1 * V_2 , int V_119 )
{
struct V_98 V_120 ;
int V_113 ;
F_26 ( V_2 ) ;
if ( V_119 > V_121 ) {
F_41 ( & V_2 -> V_12 -> V_13 , L_11 , V_122 ) ;
return;
}
V_120 = V_2 -> V_123 ;
for ( V_113 = 0 ; V_113 < V_119 ; V_113 ++ ) {
if ( V_120 . V_94 -> V_87 <= 8 ) {
T_2 * V_24 = V_120 . V_94 -> V_124 ;
if ( V_24 )
V_24 [ V_120 . V_103 ] = F_38 ( V_2 , V_113 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_12 ,
V_24 ? V_24 [ V_120 . V_103 ] : 0xff ) ;
} else {
T_3 * V_24 = V_120 . V_94 -> V_124 ;
if ( V_24 )
V_24 [ V_120 . V_103 / 2 ] = F_39 ( V_2 ,
V_113 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_13 ,
V_24 ? V_24 [ V_120 . V_103 ] : 0xffff ) ;
}
F_36 ( V_2 , & V_120 ,
V_102 ) ;
}
V_2 -> V_123 = V_120 ;
}
static inline void F_42 ( struct V_1 * V_2 , int V_113 ,
T_2 V_68 )
{
T_1 V_116 = V_125 + ( V_113 << 3 ) ;
F_4 ( V_2 , V_84 , V_116 , V_68 ) ;
}
static inline void F_43 ( struct V_1 * V_2 , int V_113 ,
T_3 V_68 )
{
T_1 V_116 = V_125 ;
T_1 V_118 = V_116 + ( V_113 << 3 ) ;
T_1 V_117 = V_116 + ( V_113 << 3 ) + 0x4 ;
F_4 ( V_2 , V_84 , V_118 , ( V_68 >> 8 ) ) ;
F_4 ( V_2 , V_84 , V_117 , ( V_68 & 0xff ) ) ;
}
static inline T_1 F_44 ( struct V_1 * V_2 , int V_113 )
{
return F_2 ( V_2 , V_84 , V_126 + ( V_113 << 2 ) ) ;
}
static inline void F_45 ( struct V_1 * V_2 , int V_113 , T_1 V_68 )
{
F_4 ( V_2 , V_84 , ( V_126 + ( V_113 << 2 ) ) , V_68 ) ;
}
static int F_46 ( struct V_1 * V_2 , struct V_91 * V_92 )
{
struct V_98 V_120 ;
int V_113 = 0 , V_127 = 0 ;
T_1 V_128 = 0 ;
F_26 ( V_2 ) ;
V_120 = V_2 -> V_123 ;
F_31 ( V_2 , V_92 , V_120 . V_94 ) ;
while ( ! V_127 && V_113 < V_121 ) {
if ( V_120 . V_94 -> V_87 <= 8 ) {
const T_2 * V_24 = V_120 . V_94 -> V_129 ;
T_2 V_68 = V_24 ? V_24 [ V_120 . V_103 ] : 0xff ;
F_42 ( V_2 , V_113 , V_68 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_14 , V_68 ) ;
} else {
const T_3 * V_24 = V_120 . V_94 -> V_129 ;
T_3 V_68 = V_24 ? V_24 [ V_120 . V_103 / 2 ] : 0xffff ;
F_43 ( V_2 , V_113 , V_68 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_15 , V_68 ) ;
}
V_128 = V_130 ;
V_128 |= ( ~ ( 1 << V_92 -> V_131 ) &
V_132 ) ;
V_128 |= ( ( V_120 . V_94 -> V_87 <= 8 ) ? 0 :
V_133 ) ;
F_45 ( V_2 , V_113 , V_128 ) ;
V_127 = F_36 ( V_2 , & V_120 ,
V_134 ) ;
V_113 ++ ;
}
if ( ! V_113 ) {
F_41 ( & V_2 -> V_12 -> V_13 , L_16 , V_122 ) ;
goto V_109;
}
F_17 ( & V_2 -> V_12 -> V_13 , L_17 , V_113 ) ;
F_4 ( V_2 , V_84 , V_135 , 0 ) ;
F_4 ( V_2 , V_84 , V_136 , V_113 - 1 ) ;
if ( V_127 & V_137 ) {
V_128 = F_44 ( V_2 , V_113 - 1 ) &
~ V_130 ;
F_45 ( V_2 , V_113 - 1 , V_128 ) ;
}
if ( F_1 ( V_2 ) )
F_4 ( V_2 , V_84 , V_138 , 1 ) ;
F_47 () ;
F_4 ( V_2 , V_84 , V_139 , 0xe0 ) ;
V_109:
return V_113 ;
}
static int F_48 ( struct V_91 * V_92 ,
struct V_140 * V_141 )
{
struct V_1 * V_2 = F_49 ( V_92 -> V_110 ) ;
T_1 V_142 = 0 , V_104 , V_143 ;
int V_101 = 0 ;
unsigned long V_144 = F_50 ( 100 ) ;
struct V_145 * V_146 = V_2 -> V_146 ;
if ( F_9 ( V_2 ) )
if ( V_141 -> V_147 == V_45 )
return - V_14 ;
F_27 ( V_2 , V_92 -> V_131 ) ;
F_4 ( V_2 , V_84 , V_138 , 0 ) ;
if ( F_9 ( V_2 ) == false ) {
V_142 = V_141 -> V_148 & 0xff000000 ;
F_4 ( V_2 , V_10 ,
V_149 , V_142 ) ;
}
if ( ! V_2 -> V_67 . V_33 )
V_142 = V_141 -> V_148 ;
else
V_142 = V_141 -> V_148 & 0x00ffffff ;
V_104 = V_141 -> V_104 ;
if ( V_104 > V_150 )
V_104 = V_150 ;
if ( F_9 ( V_2 ) == true )
V_142 = ( V_142 + 0xc00000 ) & 0xffffff ;
F_51 ( & V_2 -> V_151 ) ;
F_25 ( V_2 ) ;
V_143 = ( V_104 + 3 ) >> 2 ;
V_2 -> V_25 = V_141 ;
V_2 -> V_152 = 0 ;
V_2 -> V_28 = 0 ;
V_2 -> V_26 = V_104 ;
F_17 ( & V_2 -> V_12 -> V_13 , L_18 , V_142 , V_104 ) ;
F_4 ( V_2 , V_10 , V_153 , V_142 ) ;
F_4 ( V_2 , V_10 , V_154 , V_143 ) ;
F_4 ( V_2 , V_10 , V_155 , 0 ) ;
if ( V_2 -> V_146 ) {
V_146 -> V_156 ( V_146 , V_157 ) ;
V_146 -> V_158 ( V_146 , V_159 , true ) ;
}
F_47 () ;
F_14 ( V_2 ) ;
if ( ! F_52 ( & V_2 -> V_151 , V_144 ) ) {
F_41 ( & V_2 -> V_12 -> V_13 , L_19 ) ;
V_101 = - V_160 ;
} else {
V_141 -> V_161 = V_104 ;
}
return V_101 ;
}
static int F_53 ( struct V_91 * V_92 ,
struct V_140 * V_141 )
{
struct V_1 * V_2 = F_49 ( V_92 -> V_110 ) ;
int V_101 = 0 ;
bool V_162 = false ;
T_1 V_163 , V_39 , V_142 , V_104 ;
T_4 * V_24 ;
V_24 = V_141 -> V_24 ;
V_142 = V_141 -> V_148 ;
V_104 = V_141 -> V_104 ;
if ( F_9 ( V_2 ) == true ) {
V_142 = ( V_142 + 0xc00000 ) & 0xffffff ;
if ( ( ~ V_164 & V_142 ) ^
( ~ V_164 & ( V_142 + V_104 - 1 ) ) )
V_162 = true ;
}
if ( ! F_19 ( ( V_27 ) V_142 , 4 ) || ! F_19 ( ( V_27 ) V_24 , 4 ) ||
V_104 < 4 )
V_162 = true ;
if ( V_162 )
return - V_165 ;
V_163 = V_141 -> V_166 ? V_141 -> V_166 : V_47 ;
V_39 = V_141 -> V_147 ;
V_101 = F_24 ( V_2 , V_163 , V_39 , - 1 ) ;
if ( ! V_101 )
V_101 = F_48 ( V_92 , V_141 ) ;
return V_101 ;
}
static int F_54 ( struct V_167 * V_110 ,
struct V_91 * V_92 ,
struct V_93 * V_94 )
{
struct V_1 * V_2 = F_49 ( V_110 ) ;
int V_119 ;
unsigned long V_144 = F_50 ( 100 ) ;
F_27 ( V_2 , V_92 -> V_131 ) ;
V_2 -> V_123 . V_94 = V_94 ;
V_2 -> V_123 . V_103 = 0 ;
while ( V_2 -> V_123 . V_103 < V_94 -> V_104 ) {
F_51 ( & V_2 -> V_168 ) ;
V_119 = F_46 ( V_2 , V_92 ) ;
if ( ! F_52 ( & V_2 -> V_168 , V_144 ) ) {
F_41 ( & V_2 -> V_12 -> V_13 , L_20 ) ;
return - V_160 ;
}
F_40 ( V_2 , V_119 ) ;
}
return 0 ;
}
static void F_55 ( struct V_91 * V_92 )
{
struct V_76 * V_77 = F_33 ( V_92 ) ;
F_56 ( V_77 ) ;
}
static T_5 F_57 ( int V_169 , void * V_170 )
{
struct V_171 * V_172 = V_170 ;
struct V_1 * V_2 = V_172 -> V_13 ;
T_1 V_173 = F_2 ( V_2 , V_84 , V_174 ) ;
if ( V_173 & V_175 ) {
struct V_145 * V_146 = V_2 -> V_146 ;
V_173 &= ~ V_175 ;
F_4 ( V_2 , V_84 , V_174 , V_173 ) ;
if ( V_2 -> V_146 )
V_146 -> V_156 ( V_146 , V_176 ) ;
F_58 ( & V_2 -> V_168 ) ;
return V_177 ;
}
return V_178 ;
}
static T_5 F_59 ( int V_169 , void * V_170 )
{
struct V_171 * V_172 = V_170 ;
struct V_1 * V_2 = V_172 -> V_13 ;
struct V_145 * V_146 = V_2 -> V_146 ;
T_1 V_173 = V_172 -> V_179 -> V_69 ;
if ( V_2 -> V_72 && V_2 -> V_25 ) {
F_16 ( V_2 ) ;
if ( V_2 -> V_26 == 0 ) {
V_2 -> V_25 = NULL ;
if ( V_2 -> V_146 ) {
V_146 -> V_158 ( V_146 , V_159 ,
false ) ;
V_173 = V_180 ;
}
if ( V_2 -> V_152 )
F_15 ( V_2 ) ;
else
F_10 ( V_2 ) ;
}
if ( V_2 -> V_146 )
V_146 -> V_156 ( V_146 , V_159 ) ;
}
V_173 &= V_180 ;
if ( V_2 -> V_72 && V_173 && V_2 -> V_26 == 0 )
F_58 ( & V_2 -> V_151 ) ;
return V_177 ;
}
static T_5 F_60 ( int V_169 , void * V_170 )
{
struct V_171 * V_172 = V_170 ;
struct V_1 * V_2 = V_172 -> V_13 ;
struct V_145 * V_146 = V_2 -> V_146 ;
F_41 ( & V_2 -> V_12 -> V_13 , L_21 ) ;
V_2 -> V_152 = - V_14 ;
if ( V_2 -> V_146 )
V_146 -> V_156 ( V_146 , V_181 ) ;
F_58 ( & V_2 -> V_151 ) ;
return V_177 ;
}
static T_5 F_61 ( int V_169 , void * V_170 )
{
struct V_171 * V_172 = V_170 ;
struct V_1 * V_2 = V_172 -> V_13 ;
struct V_145 * V_146 = V_2 -> V_146 ;
T_5 V_101 = V_178 ;
if ( V_146 ) {
T_1 V_173 = V_146 -> V_182 ( V_146 ) ;
if ( V_173 & V_176 )
V_101 = F_57 ( V_169 , V_170 ) ;
else if ( V_173 & V_159 )
V_101 = F_59 ( V_169 , V_170 ) ;
else if ( V_173 & V_181 )
V_101 = F_60 ( V_169 , V_170 ) ;
}
return V_101 ;
}
static void F_62 ( struct V_1 * V_2 )
{
T_1 V_68 = 0 ;
V_68 = F_2 ( V_2 , V_10 , V_183 ) ;
V_2 -> V_15 = ( V_68 >> 8 ) & 0xff ;
V_2 -> V_184 = V_68 & 0xff ;
if ( ! ( F_9 ( V_2 ) ) ) {
F_4 ( V_2 , V_10 , V_185 , 0 ) ;
F_4 ( V_2 , V_10 , V_186 , 1 ) ;
}
V_2 -> V_72 = 1 ;
F_26 ( V_2 ) ;
F_4 ( V_2 , V_10 , V_16 , 0 ) ;
F_4 ( V_2 , V_10 , V_17 , 0 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_76 V_187 ;
F_4 ( V_2 , V_84 , V_188 , 0 ) ;
F_4 ( V_2 , V_84 , V_189 , 0 ) ;
F_4 ( V_2 , V_84 , V_135 , 0 ) ;
F_4 ( V_2 , V_84 , V_136 , 0 ) ;
F_4 ( V_2 , V_84 , V_139 , 0x20 ) ;
V_187 . V_88 = V_190 ;
V_187 . V_87 = 8 ;
V_187 . V_80 = V_2 -> V_97 ;
F_29 ( V_2 , & V_187 ) ;
if ( F_1 ( V_2 ) )
F_62 ( V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_84 , V_139 , 0 ) ;
if ( F_1 ( V_2 ) )
F_4 ( V_2 , V_84 , V_138 , 0 ) ;
}
int F_65 ( struct V_191 * V_12 ,
struct V_145 * V_146 )
{
struct V_192 * V_13 = & V_12 -> V_13 ;
struct V_1 * V_2 ;
struct V_167 * V_110 ;
struct V_193 * V_194 ;
int V_169 , V_101 = 0 , V_195 = 0 ;
T_1 V_68 ;
const char * V_196 = NULL ;
int V_197 = F_66 ( V_198 ) ;
if ( ! V_13 -> V_199 )
return - V_200 ;
if ( ! F_67 ( V_201 , V_13 -> V_199 ) )
return - V_200 ;
V_110 = F_68 ( V_13 , sizeof( struct V_1 ) ) ;
if ( ! V_110 ) {
F_41 ( V_13 , L_22 ) ;
return - V_96 ;
}
V_2 = F_49 ( V_110 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_123 . V_94 = NULL ;
V_2 -> V_123 . V_103 = 0 ;
V_2 -> V_110 = V_110 ;
V_110 -> V_202 = - 1 ;
V_110 -> V_203 = V_204 | V_205 | V_206 | V_207 ;
V_110 -> V_208 = F_32 ;
V_110 -> V_209 = F_54 ;
V_110 -> V_210 = F_53 ;
V_110 -> V_211 = F_55 ;
V_110 -> V_13 . V_199 = V_13 -> V_199 ;
V_110 -> V_212 = V_213 ;
V_2 -> V_6 = F_69 ( V_13 -> V_199 ) ;
if ( ! F_70 ( V_13 -> V_199 , L_23 , & V_68 ) )
V_110 -> V_212 = V_68 ;
V_194 = F_71 ( V_12 , V_214 , L_24 ) ;
if ( ! V_194 )
V_194 = F_71 ( V_12 , V_214 ,
L_25 ) ;
if ( V_194 ) {
V_2 -> V_7 [ V_84 ] = F_72 ( V_13 , V_194 ) ;
if ( F_73 ( V_2 -> V_7 [ V_84 ] ) ) {
V_101 = F_74 ( V_2 -> V_7 [ V_84 ] ) ;
goto V_215;
}
} else {
goto V_215;
}
V_194 = F_71 ( V_12 , V_214 , L_26 ) ;
if ( V_194 ) {
V_2 -> V_7 [ V_10 ] = F_72 ( V_13 , V_194 ) ;
if ( F_73 ( V_2 -> V_7 [ V_10 ] ) ) {
V_101 = F_74 ( V_2 -> V_7 [ V_10 ] ) ;
goto V_215;
}
V_2 -> V_3 = true ;
} else {
V_2 -> V_3 = false ;
}
F_75 ( V_13 , L_27 , V_2 -> V_3 ? L_28 : L_8 ) ;
V_194 = F_71 ( V_12 , V_214 , L_29 ) ;
if ( V_194 ) {
V_2 -> V_7 [ V_75 ] = F_72 ( V_13 , V_194 ) ;
if ( F_73 ( V_2 -> V_7 [ V_75 ] ) ) {
V_101 = F_74 ( V_2 -> V_7 [ V_75 ] ) ;
goto V_215;
}
}
V_2 -> V_216 = F_76 ( V_197 , sizeof( struct V_171 ) ,
V_95 ) ;
if ( ! V_2 -> V_216 ) {
V_101 = - V_96 ;
goto V_215;
}
for ( V_68 = 0 ; V_68 < V_197 ; V_68 ++ ) {
V_169 = - 1 ;
V_196 = V_198 [ V_68 ] . V_217 ;
if ( V_198 [ V_68 ] . V_218 == V_219 ) {
V_169 = F_77 ( V_12 , V_196 ) ;
} else if ( ! V_195 && V_146 ) {
V_169 = F_78 ( V_12 , 0 ) ;
}
if ( V_169 >= 0 ) {
V_101 = F_79 ( & V_12 -> V_13 , V_169 ,
V_198 [ V_68 ] . V_220 , 0 ,
V_196 ,
& V_2 -> V_216 [ V_68 ] ) ;
if ( V_101 < 0 ) {
F_41 ( & V_12 -> V_13 , L_30 , V_196 ) ;
goto V_215;
}
V_2 -> V_216 [ V_68 ] . V_13 = V_2 ;
V_2 -> V_216 [ V_68 ] . V_179 = & V_198 [ V_68 ] ;
V_195 ++ ;
F_17 ( & V_12 -> V_13 , L_31 ,
V_198 [ V_68 ] . V_217 ,
V_169 ) ;
}
}
if ( ! V_195 ) {
F_41 ( & V_12 -> V_13 , L_32 ) ;
V_101 = - V_61 ;
goto V_215;
}
if ( V_146 ) {
V_2 -> V_146 = V_146 ;
V_146 -> V_158 ( V_146 , V_176 , true ) ;
} else {
V_2 -> V_146 = NULL ;
}
V_2 -> V_221 = F_80 ( & V_12 -> V_13 , NULL ) ;
if ( F_73 ( V_2 -> V_221 ) ) {
F_8 ( V_13 , L_33 ) ;
V_101 = F_74 ( V_2 -> V_221 ) ;
goto V_215;
}
V_101 = F_81 ( V_2 -> V_221 ) ;
if ( V_101 ) {
F_41 ( V_13 , L_34 ) ;
goto V_215;
}
V_2 -> V_81 = F_82 ( V_2 -> V_221 ) ;
V_2 -> V_97 = V_2 -> V_81 / ( V_82 * 2 ) ;
F_63 ( V_2 ) ;
F_83 ( & V_2 -> V_168 ) ;
F_83 ( & V_2 -> V_151 ) ;
V_2 -> V_71 = - 1 ;
F_84 ( V_12 , V_2 ) ;
V_2 -> V_67 . V_38 = - 1 ;
V_2 -> V_67 . V_39 = - 1 ;
V_2 -> V_67 . V_40 = - 1 ;
V_101 = F_85 ( & V_12 -> V_13 , V_110 ) ;
if ( V_101 < 0 ) {
F_41 ( V_13 , L_35 ) ;
goto V_222;
}
return 0 ;
V_222:
F_64 ( V_2 ) ;
F_86 ( V_2 -> V_221 ) ;
V_215:
F_87 ( V_110 ) ;
F_56 ( V_2 -> V_216 ) ;
return V_101 ;
}
int F_88 ( struct V_191 * V_12 )
{
struct V_1 * V_2 = F_89 ( V_12 ) ;
F_84 ( V_12 , NULL ) ;
F_64 ( V_2 ) ;
F_86 ( V_2 -> V_221 ) ;
F_56 ( V_2 -> V_216 ) ;
F_90 ( V_2 -> V_110 ) ;
return 0 ;
}
static int T_6 F_91 ( struct V_192 * V_13 )
{
struct V_1 * V_2 = F_92 ( V_13 ) ;
F_93 ( V_2 -> V_110 ) ;
F_94 ( V_2 -> V_221 ) ;
F_64 ( V_2 ) ;
return 0 ;
}
static int T_6 F_95 ( struct V_192 * V_13 )
{
struct V_1 * V_2 = F_92 ( V_13 ) ;
int V_101 = 0 ;
F_63 ( V_2 ) ;
F_27 ( V_2 , V_2 -> V_71 ) ;
if ( V_2 -> V_146 )
V_2 -> V_146 -> V_158 ( V_2 -> V_146 , V_176 ,
true ) ;
V_101 = F_96 ( V_2 -> V_221 ) ;
if ( ! V_101 )
F_97 ( V_2 -> V_110 ) ;
return V_101 ;
}

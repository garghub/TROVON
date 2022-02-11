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
static int F_22 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
int V_40 )
{
int V_32 = 0 , V_31 = 0 ;
T_2 V_41 = V_39 -> V_42 ;
int V_43 = V_39 -> V_44 ? V_39 -> V_44 : V_45 ;
int V_46 = V_39 -> V_47 ;
int V_48 = V_39 -> V_48 ? V_39 -> V_48 : V_45 ;
int V_33 = 1 ;
F_17 ( & V_2 -> V_12 -> V_13 , L_3 ,
V_43 , V_46 , V_40 ) ;
if ( V_46 == V_49 )
V_31 = V_50 ;
V_31 |= V_39 -> V_51 * ( 8 / V_48 ) ;
switch ( V_43 ) {
case V_45 :
if ( V_46 == V_52 )
V_33 = 0 ;
break;
case V_53 :
V_32 = 0x00000001 ;
if ( V_40 ) {
V_32 |= 0x00010100 ;
V_31 = V_54 ;
}
break;
case V_55 :
V_32 = 0x00000002 ;
if ( V_40 ) {
V_32 |= 0x00020200 ;
V_31 |= V_54 ;
}
break;
default:
return - V_56 ;
}
F_21 ( V_2 , V_41 , V_31 , V_32 , V_33 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
int V_40 )
{
int V_43 = V_39 -> V_44 ? V_39 -> V_44 : V_45 ;
int V_46 = V_39 -> V_47 ;
T_1 V_8 = F_2 ( V_2 , V_10 , V_57 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_4 ,
V_43 , V_46 , V_40 ) ;
switch ( V_43 ) {
case V_45 :
V_8 &= ~ ( V_58 |
V_59 ) ;
break;
case V_55 :
V_8 &= ~ V_59 ;
V_8 |= V_58 ;
break;
case V_53 :
V_8 &= ~ V_58 ;
V_8 |= V_59 ;
break;
default:
return - V_56 ;
}
if ( V_46 == V_49 )
V_8 |= V_60 ;
else
V_8 &= ~ V_60 ;
V_8 |= V_61 ;
F_4 ( V_2 , V_10 , V_57 , V_8 ) ;
F_21 ( V_2 , V_39 -> V_42 , 0 , 0 , 0 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_38 * V_39 , int V_40 )
{
int error = 0 ;
int V_43 = V_39 -> V_44 ? V_39 -> V_44 : V_45 ;
int V_46 = V_39 -> V_47 ;
V_2 -> V_62 . V_33 = true ;
if ( ! F_9 ( V_2 ) ) {
T_1 V_63 , V_64 ;
V_63 = F_2 ( V_2 , V_10 , V_57 ) ;
V_64 = V_61 ;
if ( V_63 & V_64 || V_2 -> V_65 & V_64 ) {
V_2 -> V_62 . V_33 = false ;
F_4 ( V_2 , V_10 , V_34 , 0 ) ;
error = F_23 ( V_2 , V_39 , V_40 ) ;
}
}
if ( V_2 -> V_62 . V_33 )
error = F_22 ( V_2 , V_39 , V_40 ) ;
if ( error ) {
F_8 ( & V_2 -> V_12 -> V_13 ,
L_5 ,
V_43 , V_46 , V_40 ) ;
} else if ( V_2 -> V_62 . V_43 != V_43 ||
V_2 -> V_62 . V_46 != V_46 ||
V_2 -> V_62 . V_40 != V_40 ) {
V_2 -> V_62 . V_43 = V_43 ;
V_2 -> V_62 . V_46 = V_46 ;
V_2 -> V_62 . V_40 = V_40 ;
F_17 ( & V_2 -> V_12 -> V_13 ,
L_6 ,
V_2 -> V_66 ,
V_2 -> V_62 . V_43 ,
V_2 -> V_62 . V_46 ,
V_2 -> V_62 . V_40 != - 1 ? L_7 : L_8 ) ;
}
return error ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) || ( V_2 -> V_67 ) )
return;
V_2 -> V_67 = 1 ;
if ( ( F_2 ( V_2 , V_10 , V_68 ) & 1 ) == 0 )
return;
F_10 ( V_2 ) ;
F_7 ( 1 ) ;
F_4 ( V_2 , V_10 , V_68 , 0 ) ;
F_7 ( 1 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) || ( ! V_2 -> V_67 ) )
return;
V_2 -> V_67 = 0 ;
if ( ( F_2 ( V_2 , V_10 , V_68 ) & 1 ) )
return;
F_6 ( V_2 ) ;
F_4 ( V_2 , V_10 , V_68 , 1 ) ;
F_7 ( 1 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_69 )
{
T_1 V_8 = 0 ;
if ( V_2 -> V_66 == V_69 )
return;
if ( V_2 -> V_7 [ V_70 ] ) {
V_8 = F_2 ( V_2 , V_70 , 0 ) ;
V_8 = ( V_8 & ~ 0xff ) | ( 1 << V_69 ) ;
F_4 ( V_2 , V_70 , 0 , V_8 ) ;
F_28 ( 10 , 20 ) ;
}
V_2 -> V_66 = V_69 ;
}
static void F_29 ( struct V_1 * V_2 ,
const struct V_71 * V_72 )
{
T_1 V_73 , V_74 = 0 ;
if ( V_72 -> V_75 )
V_74 = V_2 -> V_76 / ( 2 * V_72 -> V_75 ) ;
V_73 = F_30 ( V_74 , V_77 , V_78 ) ;
F_4 ( V_2 , V_79 , V_80 , V_73 ) ;
V_73 = V_81 ;
if ( V_72 -> V_82 != 16 )
V_73 |= V_72 -> V_82 << 2 ;
V_73 |= V_72 -> V_83 & 3 ;
F_4 ( V_2 , V_79 , V_84 , V_73 ) ;
V_2 -> V_85 = * V_72 ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_86 * V_87 ,
struct V_88 * V_89 )
{
struct V_71 V_72 ;
V_72 . V_75 = V_89 -> V_75 ;
V_72 . V_82 = V_89 -> V_82 ;
V_72 . V_83 = V_87 -> V_83 ;
F_29 ( V_2 , & V_72 ) ;
}
static int F_32 ( struct V_86 * V_87 )
{
struct V_71 * V_72 ;
if ( V_87 -> V_82 > 16 )
return - V_56 ;
V_72 = F_33 ( V_87 ) ;
if ( ! V_72 ) {
V_72 = F_34 ( sizeof( * V_72 ) , V_90 ) ;
if ( ! V_72 )
return - V_91 ;
F_35 ( V_87 , V_72 ) ;
}
V_72 -> V_75 = V_87 -> V_92 ;
V_72 -> V_83 = V_87 -> V_83 ;
if ( V_87 -> V_82 )
V_72 -> V_82 = V_87 -> V_82 ;
else
V_72 -> V_82 = 8 ;
return 0 ;
}
static bool F_36 ( struct V_1 * V_2 ,
struct V_93 * V_94 )
{
if ( V_94 -> V_95 &&
F_37 ( V_2 -> V_96 , V_94 -> V_89 ) )
return true ;
else
return false ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_93 * V_94 , int V_97 )
{
int V_98 = V_99 ;
if ( V_94 -> V_89 -> V_82 <= 8 )
V_94 -> V_100 ++ ;
else
V_94 -> V_100 += 2 ;
if ( V_94 -> V_100 >= V_94 -> V_89 -> V_101 ) {
if ( V_94 -> V_89 -> V_102 &&
( V_97 & V_103 ) )
V_98 |= V_103 ;
if ( V_94 -> V_89 -> V_104 &&
( V_97 & V_105 ) )
V_98 |= V_105 ;
if ( V_98 )
goto V_106;
F_17 ( & V_2 -> V_12 -> V_13 , L_9 ) ;
if ( F_36 ( V_2 , V_94 ) )
V_98 = V_107 ;
else
V_98 = V_108 ;
V_94 -> V_89 = NULL ;
}
V_106:
F_17 ( & V_2 -> V_12 -> V_13 , L_10 ,
V_94 -> V_89 , V_94 -> V_89 ? V_94 -> V_89 -> V_101 : 0 , V_94 -> V_100 , V_98 ) ;
return V_98 ;
}
static inline T_2 F_39 ( struct V_1 * V_2 , int V_109 )
{
T_1 V_110 = V_111 + ( V_109 << 3 ) + 0x4 ;
return F_2 ( V_2 , V_79 , V_110 ) & 0xff ;
}
static inline T_3 F_40 ( struct V_1 * V_2 , int V_109 )
{
T_1 V_112 = V_111 ;
T_1 V_113 = V_112 + ( V_109 << 3 ) + 0x4 ;
T_1 V_114 = V_112 + ( V_109 << 3 ) ;
return ( F_2 ( V_2 , V_79 , V_113 ) & 0xff ) |
( ( F_2 ( V_2 , V_79 , V_114 ) & 0xff ) << 8 ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_115 )
{
struct V_93 V_116 ;
int V_109 ;
F_26 ( V_2 ) ;
if ( V_115 > V_117 ) {
F_42 ( & V_2 -> V_12 -> V_13 , L_11 , V_118 ) ;
return;
}
V_116 = V_2 -> V_119 ;
for ( V_109 = 0 ; V_109 < V_115 ; V_109 ++ ) {
if ( V_116 . V_89 -> V_82 <= 8 ) {
T_2 * V_24 = V_116 . V_89 -> V_120 ;
if ( V_24 )
V_24 [ V_116 . V_100 ] = F_39 ( V_2 , V_109 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_12 ,
V_24 ? V_24 [ V_116 . V_100 ] : 0xff ) ;
} else {
T_3 * V_24 = V_116 . V_89 -> V_120 ;
if ( V_24 )
V_24 [ V_116 . V_100 / 2 ] = F_40 ( V_2 ,
V_109 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_13 ,
V_24 ? V_24 [ V_116 . V_100 ] : 0xffff ) ;
}
F_38 ( V_2 , & V_116 ,
V_99 ) ;
}
V_2 -> V_119 = V_116 ;
}
static inline void F_43 ( struct V_1 * V_2 , int V_109 ,
T_2 V_63 )
{
T_1 V_112 = V_121 + ( V_109 << 3 ) ;
F_4 ( V_2 , V_79 , V_112 , V_63 ) ;
}
static inline void F_44 ( struct V_1 * V_2 , int V_109 ,
T_3 V_63 )
{
T_1 V_112 = V_121 ;
T_1 V_114 = V_112 + ( V_109 << 3 ) ;
T_1 V_113 = V_112 + ( V_109 << 3 ) + 0x4 ;
F_4 ( V_2 , V_79 , V_114 , ( V_63 >> 8 ) ) ;
F_4 ( V_2 , V_79 , V_113 , ( V_63 & 0xff ) ) ;
}
static inline T_1 F_45 ( struct V_1 * V_2 , int V_109 )
{
return F_2 ( V_2 , V_79 , V_122 + ( V_109 << 2 ) ) ;
}
static inline void F_46 ( struct V_1 * V_2 , int V_109 , T_1 V_63 )
{
F_4 ( V_2 , V_79 , ( V_122 + ( V_109 << 2 ) ) , V_63 ) ;
}
static int F_47 ( struct V_1 * V_2 , struct V_86 * V_87 )
{
struct V_93 V_116 ;
int V_109 = 0 , V_123 = 0 ;
T_1 V_124 = 0 ;
F_26 ( V_2 ) ;
V_116 = V_2 -> V_119 ;
F_31 ( V_2 , V_87 , V_116 . V_89 ) ;
while ( ! V_123 && V_109 < V_117 ) {
if ( V_116 . V_89 -> V_82 <= 8 ) {
const T_2 * V_24 = V_116 . V_89 -> V_125 ;
T_2 V_63 = V_24 ? V_24 [ V_116 . V_100 ] : 0xff ;
F_43 ( V_2 , V_109 , V_63 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_14 , V_63 ) ;
} else {
const T_3 * V_24 = V_116 . V_89 -> V_125 ;
T_3 V_63 = V_24 ? V_24 [ V_116 . V_100 / 2 ] : 0xffff ;
F_44 ( V_2 , V_109 , V_63 ) ;
F_17 ( & V_2 -> V_12 -> V_13 , L_15 , V_63 ) ;
}
V_124 = V_126 ;
V_124 |= ( ~ ( 1 << V_87 -> V_127 ) &
V_128 ) ;
V_124 |= ( ( V_116 . V_89 -> V_82 <= 8 ) ? 0 :
V_129 ) ;
F_46 ( V_2 , V_109 , V_124 ) ;
V_123 = F_38 ( V_2 , & V_116 ,
V_130 ) ;
V_109 ++ ;
}
if ( ! V_109 ) {
F_42 ( & V_2 -> V_12 -> V_13 , L_16 , V_118 ) ;
goto V_106;
}
F_17 ( & V_2 -> V_12 -> V_13 , L_17 , V_109 ) ;
F_4 ( V_2 , V_79 , V_131 , 0 ) ;
F_4 ( V_2 , V_79 , V_132 , V_109 - 1 ) ;
if ( V_123 & V_133 ) {
V_124 = F_45 ( V_2 , V_109 - 1 ) &
~ V_126 ;
F_46 ( V_2 , V_109 - 1 , V_124 ) ;
}
if ( F_1 ( V_2 ) )
F_4 ( V_2 , V_79 , V_134 , 1 ) ;
F_48 () ;
F_4 ( V_2 , V_79 , V_135 , 0xe0 ) ;
V_106:
return V_109 ;
}
static int F_49 ( struct V_86 * V_87 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_50 ( V_87 -> V_96 ) ;
T_1 V_136 = 0 , V_101 , V_137 , V_138 ;
int V_98 = 0 ;
unsigned long V_139 = F_51 ( 100 ) ;
struct V_140 * V_141 = V_2 -> V_141 ;
if ( F_9 ( V_2 ) )
if ( V_39 -> V_47 == V_49 )
return - V_14 ;
F_27 ( V_2 , V_87 -> V_127 ) ;
F_4 ( V_2 , V_79 , V_134 , 0 ) ;
if ( F_9 ( V_2 ) == false ) {
V_136 = V_39 -> V_142 & 0xff000000 ;
F_4 ( V_2 , V_10 ,
V_143 , V_136 ) ;
}
if ( ! V_2 -> V_62 . V_33 )
V_136 = V_39 -> V_142 ;
else
V_136 = V_39 -> V_142 & 0x00ffffff ;
if ( F_9 ( V_2 ) == true )
V_136 = ( V_136 + 0xc00000 ) & 0xffffff ;
V_101 = V_39 -> V_101 ;
V_2 -> V_28 = 0 ;
do {
if ( V_101 > V_144 )
V_137 = V_144 ;
else
V_137 = V_101 ;
F_52 ( & V_2 -> V_145 ) ;
F_25 ( V_2 ) ;
V_138 = ( V_137 + 3 ) >> 2 ;
V_2 -> V_25 = V_39 ;
V_2 -> V_146 = 0 ;
V_2 -> V_26 = V_137 ;
F_17 ( & V_2 -> V_12 -> V_13 ,
L_18 , V_136 , V_137 ) ;
F_4 ( V_2 , V_10 , V_147 , V_136 ) ;
F_4 ( V_2 , V_10 , V_148 , V_138 ) ;
F_4 ( V_2 , V_10 , V_149 , 0 ) ;
if ( V_2 -> V_141 ) {
V_141 -> V_150 ( V_141 , V_151 ) ;
V_141 -> V_152 ( V_141 , V_153 , true ) ;
}
F_48 () ;
F_14 ( V_2 ) ;
if ( ! F_53 ( & V_2 -> V_145 , V_139 ) ) {
F_42 ( & V_2 -> V_12 -> V_13 , L_19 ) ;
V_98 = - V_154 ;
break;
}
V_39 -> V_155 += V_137 ;
V_136 += V_137 ;
V_101 -= V_137 ;
} while ( V_101 );
return V_98 ;
}
static int F_54 ( struct V_156 * V_96 ,
struct V_86 * V_87 ,
struct V_88 * V_89 )
{
struct V_1 * V_2 = F_50 ( V_96 ) ;
int V_115 ;
unsigned long V_139 = F_51 ( 100 ) ;
F_27 ( V_2 , V_87 -> V_127 ) ;
V_2 -> V_119 . V_89 = V_89 ;
V_2 -> V_119 . V_100 = 0 ;
while ( V_2 -> V_119 . V_100 < V_89 -> V_101 ) {
F_52 ( & V_2 -> V_157 ) ;
V_115 = F_47 ( V_2 , V_87 ) ;
if ( ! F_53 ( & V_2 -> V_157 , V_139 ) ) {
F_42 ( & V_2 -> V_12 -> V_13 , L_20 ) ;
return - V_154 ;
}
F_41 ( V_2 , V_115 ) ;
}
return 0 ;
}
static int F_55 ( struct V_86 * V_87 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_50 ( V_87 -> V_96 ) ;
struct V_88 V_158 [ 2 ] ;
T_2 V_159 [ 6 ] ;
int V_98 ;
memset ( V_159 , 0 , sizeof( V_159 ) ) ;
memset ( V_158 , 0 , sizeof( V_158 ) ) ;
V_159 [ 0 ] = V_39 -> V_42 ;
V_159 [ 1 ] = V_39 -> V_142 >> ( V_39 -> V_47 * 8 - 8 ) ;
V_159 [ 2 ] = V_39 -> V_142 >> ( V_39 -> V_47 * 8 - 16 ) ;
V_159 [ 3 ] = V_39 -> V_142 >> ( V_39 -> V_47 * 8 - 24 ) ;
V_159 [ 4 ] = V_39 -> V_142 >> ( V_39 -> V_47 * 8 - 32 ) ;
V_158 [ 0 ] . V_125 = V_159 ;
V_158 [ 0 ] . V_101 = V_39 -> V_47 + V_39 -> V_51 + 1 ;
V_158 [ 0 ] . V_82 = V_87 -> V_82 ;
V_158 [ 0 ] . V_160 = V_39 -> V_161 ;
V_2 -> V_119 . V_95 = false ;
V_98 = F_54 ( V_87 -> V_96 , V_87 , & V_158 [ 0 ] ) ;
V_2 -> V_119 . V_95 = true ;
if ( ! V_98 ) {
V_158 [ 1 ] . V_120 = V_39 -> V_24 ;
V_158 [ 1 ] . V_101 = V_39 -> V_101 ;
V_158 [ 1 ] . V_162 = V_39 -> V_44 ;
V_158 [ 1 ] . V_82 = V_87 -> V_82 ;
V_98 = F_54 ( V_87 -> V_96 , V_87 , & V_158 [ 1 ] ) ;
}
if ( ! V_98 )
V_39 -> V_155 = V_39 -> V_101 ;
return V_98 ;
}
static int F_56 ( struct V_86 * V_87 ,
struct V_38 * V_39 )
{
struct V_1 * V_2 = F_50 ( V_87 -> V_96 ) ;
int V_98 = 0 ;
bool V_163 = false ;
T_1 V_136 , V_101 ;
T_4 * V_24 ;
V_24 = V_39 -> V_24 ;
V_136 = V_39 -> V_142 ;
V_101 = V_39 -> V_101 ;
if ( F_9 ( V_2 ) == true ) {
V_136 = ( V_136 + 0xc00000 ) & 0xffffff ;
if ( ( ~ V_164 & V_136 ) ^
( ~ V_164 & ( V_136 + V_101 - 1 ) ) )
V_163 = true ;
}
if ( ! F_19 ( ( V_27 ) V_136 , 4 ) || ! F_19 ( ( V_27 ) V_24 , 4 ) ||
V_101 < 4 )
V_163 = true ;
if ( V_163 )
return F_55 ( V_87 , V_39 ) ;
V_98 = F_24 ( V_2 , V_39 , - 1 ) ;
if ( ! V_98 )
V_98 = F_49 ( V_87 , V_39 ) ;
return V_98 ;
}
static void F_57 ( struct V_86 * V_87 )
{
struct V_71 * V_72 = F_33 ( V_87 ) ;
F_58 ( V_72 ) ;
}
static T_5 F_59 ( int V_165 , void * V_166 )
{
struct V_167 * V_168 = V_166 ;
struct V_1 * V_2 = V_168 -> V_13 ;
T_1 V_169 = F_2 ( V_2 , V_79 , V_170 ) ;
if ( V_169 & V_171 ) {
struct V_140 * V_141 = V_2 -> V_141 ;
V_169 &= ~ V_171 ;
F_4 ( V_2 , V_79 , V_170 , V_169 ) ;
if ( V_2 -> V_141 )
V_141 -> V_150 ( V_141 , V_172 ) ;
F_60 ( & V_2 -> V_157 ) ;
return V_173 ;
}
return V_174 ;
}
static T_5 F_61 ( int V_165 , void * V_166 )
{
struct V_167 * V_168 = V_166 ;
struct V_1 * V_2 = V_168 -> V_13 ;
struct V_140 * V_141 = V_2 -> V_141 ;
T_1 V_169 = V_168 -> V_175 -> V_64 ;
if ( V_2 -> V_67 && V_2 -> V_25 ) {
F_16 ( V_2 ) ;
if ( V_2 -> V_26 == 0 ) {
V_2 -> V_25 = NULL ;
if ( V_2 -> V_141 ) {
V_141 -> V_152 ( V_141 , V_153 ,
false ) ;
V_169 = V_176 ;
}
if ( V_2 -> V_146 )
F_15 ( V_2 ) ;
else
F_10 ( V_2 ) ;
}
if ( V_2 -> V_141 )
V_141 -> V_150 ( V_141 , V_153 ) ;
}
V_169 &= V_176 ;
if ( V_2 -> V_67 && V_169 && V_2 -> V_26 == 0 )
F_60 ( & V_2 -> V_145 ) ;
return V_173 ;
}
static T_5 F_62 ( int V_165 , void * V_166 )
{
struct V_167 * V_168 = V_166 ;
struct V_1 * V_2 = V_168 -> V_13 ;
struct V_140 * V_141 = V_2 -> V_141 ;
F_42 ( & V_2 -> V_12 -> V_13 , L_21 ) ;
V_2 -> V_146 = - V_14 ;
if ( V_2 -> V_141 )
V_141 -> V_150 ( V_141 , V_177 ) ;
F_60 ( & V_2 -> V_145 ) ;
return V_173 ;
}
static T_5 F_63 ( int V_165 , void * V_166 )
{
struct V_167 * V_168 = V_166 ;
struct V_1 * V_2 = V_168 -> V_13 ;
struct V_140 * V_141 = V_2 -> V_141 ;
T_5 V_98 = V_174 ;
if ( V_141 ) {
T_1 V_169 = V_141 -> V_178 ( V_141 ) ;
if ( V_169 & V_172 )
V_98 = F_59 ( V_165 , V_166 ) ;
else if ( V_169 & V_153 )
V_98 = F_61 ( V_165 , V_166 ) ;
else if ( V_169 & V_177 )
V_98 = F_62 ( V_165 , V_166 ) ;
}
return V_98 ;
}
static void F_64 ( struct V_1 * V_2 )
{
T_1 V_63 = 0 ;
V_63 = F_2 ( V_2 , V_10 , V_179 ) ;
V_2 -> V_15 = ( V_63 >> 8 ) & 0xff ;
V_2 -> V_180 = V_63 & 0xff ;
if ( ! ( F_9 ( V_2 ) ) ) {
F_4 ( V_2 , V_10 , V_181 , 0 ) ;
F_4 ( V_2 , V_10 , V_182 , 1 ) ;
}
V_2 -> V_67 = 1 ;
F_26 ( V_2 ) ;
F_4 ( V_2 , V_10 , V_16 , 0 ) ;
F_4 ( V_2 , V_10 , V_17 , 0 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_71 V_183 ;
F_4 ( V_2 , V_79 , V_184 , 0 ) ;
F_4 ( V_2 , V_79 , V_185 , 0 ) ;
F_4 ( V_2 , V_79 , V_131 , 0 ) ;
F_4 ( V_2 , V_79 , V_132 , 0 ) ;
F_4 ( V_2 , V_79 , V_135 , 0x20 ) ;
V_183 . V_83 = V_186 ;
V_183 . V_82 = 8 ;
V_183 . V_75 = V_2 -> V_92 ;
F_29 ( V_2 , & V_183 ) ;
if ( F_1 ( V_2 ) )
F_64 ( V_2 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_79 , V_135 , 0 ) ;
if ( F_1 ( V_2 ) )
F_4 ( V_2 , V_79 , V_134 , 0 ) ;
}
int F_67 ( struct V_187 * V_12 ,
struct V_140 * V_141 )
{
struct V_188 * V_13 = & V_12 -> V_13 ;
struct V_1 * V_2 ;
struct V_156 * V_96 ;
struct V_189 * V_190 ;
int V_165 , V_98 = 0 , V_191 = 0 ;
T_1 V_63 ;
const char * V_192 = NULL ;
int V_193 = F_68 ( V_194 ) ;
if ( ! V_13 -> V_195 )
return - V_196 ;
if ( ! F_69 ( V_197 , V_13 -> V_195 ) )
return - V_196 ;
V_96 = F_70 ( V_13 , sizeof( struct V_1 ) ) ;
if ( ! V_96 ) {
F_42 ( V_13 , L_22 ) ;
return - V_91 ;
}
V_2 = F_50 ( V_96 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_119 . V_89 = NULL ;
V_2 -> V_119 . V_100 = 0 ;
V_2 -> V_119 . V_95 = true ;
V_2 -> V_96 = V_96 ;
V_96 -> V_198 = - 1 ;
V_96 -> V_199 = V_200 | V_201 | V_202 | V_203 ;
V_96 -> V_204 = F_32 ;
V_96 -> V_205 = F_54 ;
V_96 -> V_206 = F_56 ;
V_96 -> V_207 = F_57 ;
V_96 -> V_13 . V_195 = V_13 -> V_195 ;
V_96 -> V_208 = V_209 ;
V_2 -> V_6 = F_71 ( V_13 -> V_195 ) ;
if ( ! F_72 ( V_13 -> V_195 , L_23 , & V_63 ) )
V_96 -> V_208 = V_63 ;
V_190 = F_73 ( V_12 , V_210 , L_24 ) ;
if ( ! V_190 )
V_190 = F_73 ( V_12 , V_210 ,
L_25 ) ;
if ( V_190 ) {
V_2 -> V_7 [ V_79 ] = F_74 ( V_13 , V_190 ) ;
if ( F_75 ( V_2 -> V_7 [ V_79 ] ) ) {
V_98 = F_76 ( V_2 -> V_7 [ V_79 ] ) ;
goto V_211;
}
} else {
goto V_212;
}
V_190 = F_73 ( V_12 , V_210 , L_26 ) ;
if ( V_190 ) {
V_2 -> V_7 [ V_10 ] = F_74 ( V_13 , V_190 ) ;
if ( F_75 ( V_2 -> V_7 [ V_10 ] ) ) {
V_98 = F_76 ( V_2 -> V_7 [ V_10 ] ) ;
goto V_211;
}
V_2 -> V_3 = true ;
} else {
V_2 -> V_3 = false ;
}
F_77 ( V_13 , L_27 , V_2 -> V_3 ? L_28 : L_8 ) ;
V_190 = F_73 ( V_12 , V_210 , L_29 ) ;
if ( V_190 ) {
V_2 -> V_7 [ V_70 ] = F_74 ( V_13 , V_190 ) ;
if ( F_75 ( V_2 -> V_7 [ V_70 ] ) ) {
V_98 = F_76 ( V_2 -> V_7 [ V_70 ] ) ;
goto V_212;
}
}
V_2 -> V_213 = F_78 ( V_193 , sizeof( struct V_167 ) ,
V_90 ) ;
if ( ! V_2 -> V_213 ) {
V_98 = - V_91 ;
goto V_212;
}
for ( V_63 = 0 ; V_63 < V_193 ; V_63 ++ ) {
V_165 = - 1 ;
V_192 = V_194 [ V_63 ] . V_214 ;
if ( V_194 [ V_63 ] . V_215 == V_216 ) {
V_165 = F_79 ( V_12 , V_192 ) ;
} else if ( ! V_191 && V_141 ) {
V_165 = F_80 ( V_12 , 0 ) ;
}
if ( V_165 >= 0 ) {
V_98 = F_81 ( & V_12 -> V_13 , V_165 ,
V_194 [ V_63 ] . V_217 , 0 ,
V_192 ,
& V_2 -> V_213 [ V_63 ] ) ;
if ( V_98 < 0 ) {
F_42 ( & V_12 -> V_13 , L_30 , V_192 ) ;
goto V_211;
}
V_2 -> V_213 [ V_63 ] . V_13 = V_2 ;
V_2 -> V_213 [ V_63 ] . V_175 = & V_194 [ V_63 ] ;
V_191 ++ ;
F_17 ( & V_12 -> V_13 , L_31 ,
V_194 [ V_63 ] . V_214 ,
V_165 ) ;
}
}
if ( ! V_191 ) {
F_42 ( & V_12 -> V_13 , L_32 ) ;
V_98 = - V_56 ;
goto V_211;
}
if ( V_141 ) {
V_2 -> V_141 = V_141 ;
V_141 -> V_152 ( V_141 , V_172 , true ) ;
} else {
V_2 -> V_141 = NULL ;
}
V_2 -> V_218 = F_82 ( & V_12 -> V_13 , NULL ) ;
if ( F_75 ( V_2 -> V_218 ) ) {
F_8 ( V_13 , L_33 ) ;
V_98 = F_76 ( V_2 -> V_218 ) ;
goto V_211;
}
V_98 = F_83 ( V_2 -> V_218 ) ;
if ( V_98 ) {
F_42 ( V_13 , L_34 ) ;
goto V_211;
}
V_2 -> V_76 = F_84 ( V_2 -> V_218 ) ;
V_2 -> V_92 = V_2 -> V_76 / ( V_77 * 2 ) ;
F_65 ( V_2 ) ;
F_85 ( & V_2 -> V_157 ) ;
F_85 ( & V_2 -> V_145 ) ;
V_2 -> V_66 = - 1 ;
F_86 ( V_12 , V_2 ) ;
V_2 -> V_62 . V_43 = - 1 ;
V_2 -> V_62 . V_46 = - 1 ;
V_2 -> V_62 . V_40 = - 1 ;
V_98 = F_87 ( & V_12 -> V_13 , V_96 ) ;
if ( V_98 < 0 ) {
F_42 ( V_13 , L_35 ) ;
goto V_219;
}
return 0 ;
V_219:
F_66 ( V_2 ) ;
F_88 ( V_2 -> V_218 ) ;
V_211:
F_58 ( V_2 -> V_213 ) ;
V_212:
F_89 ( V_96 ) ;
return V_98 ;
}
int F_90 ( struct V_187 * V_12 )
{
struct V_1 * V_2 = F_91 ( V_12 ) ;
F_66 ( V_2 ) ;
F_88 ( V_2 -> V_218 ) ;
F_58 ( V_2 -> V_213 ) ;
F_92 ( V_2 -> V_96 ) ;
return 0 ;
}
static int T_6 F_93 ( struct V_188 * V_13 )
{
struct V_1 * V_2 = F_94 ( V_13 ) ;
if ( ! F_9 ( V_2 ) )
V_2 -> V_65 =
F_2 ( V_2 , V_10 , V_57 ) ;
F_95 ( V_2 -> V_96 ) ;
F_96 ( V_2 -> V_218 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
static int T_6 F_97 ( struct V_188 * V_13 )
{
struct V_1 * V_2 = F_94 ( V_13 ) ;
int V_98 = 0 ;
F_65 ( V_2 ) ;
F_27 ( V_2 , V_2 -> V_66 ) ;
if ( V_2 -> V_141 )
V_2 -> V_141 -> V_152 ( V_2 -> V_141 , V_172 ,
true ) ;
V_98 = F_98 ( V_2 -> V_218 ) ;
if ( ! V_98 )
F_99 ( V_2 -> V_96 ) ;
return V_98 ;
}

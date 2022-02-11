static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_6 ( V_2 , V_4 ) ;
}
static inline void F_2 ( struct V_1 * V_2 , bool V_7 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_7 ( V_2 , V_7 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
if ( V_2 -> V_5 ) {
V_2 -> V_5 -> V_10 ( V_2 , V_9 ) ;
} else {
V_2 -> V_11 = NULL ;
V_2 -> V_12 = NULL ;
}
}
static inline void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_13 ( V_2 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 -> abort ( V_2 ) ;
}
static inline void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 -> V_14 ( V_2 ) ;
}
void F_7 ( struct V_1 * V_2 , T_1 V_15 )
{
V_2 -> V_16 &= ~ ( V_15 & V_17 ) ;
F_8 ( V_2 , V_18 , V_2 -> V_16 ) ;
}
void F_9 ( struct V_1 * V_2 , T_1 V_15 )
{
V_2 -> V_16 |= ( V_15 & V_17 ) ;
F_8 ( V_2 , V_18 , V_2 -> V_16 ) ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_15 )
{
F_8 ( V_2 , V_19 , ~ V_15 ) ;
}
static void F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_20 = V_4 -> V_20 ;
V_2 -> V_21 = V_4 -> V_22 ;
V_2 -> V_23 = V_4 -> V_22 ;
V_2 -> V_24 = 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
V_2 -> V_21 = F_13 ( V_2 -> V_21 ) ;
V_2 -> V_24 = 0 ;
return -- V_2 -> V_20 ;
}
static void F_14 ( struct V_25 * V_26 , int V_7 )
{
struct V_1 * V_2 = F_15 ( V_26 ) ;
if ( V_7 && ! V_2 -> V_27 ) {
T_2 V_28 ;
F_16 ( F_17 ( V_26 ) ) ;
V_2 -> V_27 = true ;
V_2 -> V_29 = V_30 & ~ V_31 ;
V_28 = F_18 ( V_2 , V_32 ) & ~ V_30 ;
if ( V_2 -> V_9 -> V_33 & V_34 )
V_28 |= V_35 ;
F_19 ( V_2 , V_32 , V_28 ) ;
F_19 ( V_2 , V_36 , V_2 -> V_29 ) ;
} else if ( ! V_7 && V_2 -> V_27 ) {
V_2 -> V_29 = V_30 ;
F_19 ( V_2 , V_36 , V_2 -> V_29 ) ;
V_2 -> V_27 = false ;
F_20 ( F_17 ( V_26 ) ) ;
F_21 ( F_17 ( V_26 ) ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_37 , V_38 |
F_18 ( V_2 , V_37 ) ) ;
if ( ! ( V_2 -> V_9 -> V_33 & V_39 ) )
F_23 ( 10 ) ;
if ( V_2 -> V_9 -> V_33 & V_40 ) {
F_19 ( V_2 , V_41 , 0x0100 ) ;
F_23 ( 10 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 -> V_33 & V_40 ) {
F_19 ( V_2 , V_41 , 0x0000 ) ;
F_23 ( 10 ) ;
}
F_19 ( V_2 , V_37 , ~ V_38 &
F_18 ( V_2 , V_37 ) ) ;
if ( ! ( V_2 -> V_9 -> V_33 & V_39 ) )
F_23 ( 10 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
unsigned int V_42 )
{
T_1 V_43 = 0 , clock ;
if ( V_42 == 0 ) {
F_24 ( V_2 ) ;
return;
}
if ( V_2 -> V_44 )
clock = V_2 -> V_44 ( V_2 , V_42 ) / 512 ;
else
clock = V_2 -> V_26 -> V_45 ;
for ( V_43 = 0x80000080 ; V_42 >= ( clock << 1 ) ; V_43 >>= 1 )
clock <<= 1 ;
if ( ( V_2 -> V_9 -> V_33 & V_46 ) && ( ( V_43 >> 22 ) & 0x1 ) )
V_43 |= 0xff ;
if ( V_2 -> V_47 )
V_2 -> V_47 ( V_2 -> V_48 , ( V_43 >> 22 ) & 1 ) ;
F_19 ( V_2 , V_37 , ~ V_38 &
F_18 ( V_2 , V_37 ) ) ;
F_19 ( V_2 , V_37 , V_43 & V_49 ) ;
if ( ! ( V_2 -> V_9 -> V_33 & V_39 ) )
F_23 ( 10 ) ;
F_22 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_50 , 0x0000 ) ;
if ( V_2 -> V_9 -> V_33 & V_40 )
F_19 ( V_2 , V_51 , 0x0000 ) ;
F_23 ( 10 ) ;
F_19 ( V_2 , V_50 , 0x0001 ) ;
if ( V_2 -> V_9 -> V_33 & V_40 )
F_19 ( V_2 , V_51 , 0x0001 ) ;
F_23 ( 10 ) ;
if ( V_2 -> V_9 -> V_33 & V_52 ) {
F_19 ( V_2 , V_36 , V_2 -> V_29 ) ;
F_19 ( V_2 , V_53 , 0x0001 ) ;
}
}
static void F_27 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_28 ( V_55 , struct V_1 ,
V_56 . V_55 ) ;
struct V_57 * V_58 ;
unsigned long V_33 ;
F_29 ( & V_2 -> V_59 , V_33 ) ;
V_58 = V_2 -> V_58 ;
if ( F_30 ( V_58 ) ||
F_31 ( V_2 -> V_60 +
F_32 ( V_61 ) ) ) {
F_33 ( & V_2 -> V_59 , V_33 ) ;
return;
}
F_34 ( & V_2 -> V_48 -> V_62 ,
L_1 ,
V_58 -> V_63 -> V_64 ) ;
if ( V_2 -> V_4 )
V_2 -> V_4 -> error = - V_65 ;
else if ( V_2 -> V_63 )
V_2 -> V_63 -> error = - V_65 ;
else
V_58 -> V_63 -> error = - V_65 ;
V_2 -> V_63 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_66 = false ;
F_33 ( & V_2 -> V_59 , V_33 ) ;
F_26 ( V_2 ) ;
V_2 -> V_58 = NULL ;
F_5 ( V_2 ) ;
F_35 ( V_2 -> V_26 , V_58 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_67 * V_63 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_68 = V_63 -> V_64 ;
T_1 V_69 = V_70 ;
switch ( F_37 ( V_63 ) ) {
case V_71 : V_68 |= V_72 ; break;
case V_73 :
case V_74 :
V_68 |= V_75 ; break;
case V_76 : V_68 |= V_77 ; break;
case V_78 : V_68 |= V_79 ; break;
case V_80 : V_68 |= V_81 ; break;
default:
F_38 ( L_2 , F_37 ( V_63 ) ) ;
return - V_82 ;
}
V_2 -> V_63 = V_63 ;
if ( V_4 ) {
V_68 |= V_83 ;
if ( V_4 -> V_84 > 1 ) {
F_19 ( V_2 , V_85 , V_86 ) ;
V_68 |= V_87 ;
if ( ( V_2 -> V_9 -> V_33 & V_88 ) &&
( V_63 -> V_64 == V_89 || V_2 -> V_58 -> V_90 ) )
V_68 |= V_91 ;
}
if ( V_4 -> V_33 & V_92 )
V_68 |= V_93 ;
}
if ( ! V_2 -> V_94 )
V_69 &= ~ ( V_95 | V_96 ) ;
F_7 ( V_2 , V_69 ) ;
F_8 ( V_2 , V_97 , V_63 -> V_98 ) ;
F_19 ( V_2 , V_99 , V_68 ) ;
return 0 ;
}
static void F_39 ( struct V_1 * V_2 ,
unsigned short * V_100 ,
unsigned int V_101 )
{
int V_102 = V_2 -> V_4 -> V_33 & V_92 ;
T_3 * V_103 ;
if ( V_2 -> V_9 -> V_33 & V_104 ) {
T_1 V_4 = 0 ;
T_1 * V_105 = ( T_1 * ) V_100 ;
if ( V_102 )
F_40 ( V_2 , V_106 , V_105 ,
V_101 >> 2 ) ;
else
F_41 ( V_2 , V_106 , V_105 ,
V_101 >> 2 ) ;
if ( ! ( V_101 & 0x3 ) )
return;
V_105 += V_101 >> 2 ;
V_101 %= 4 ;
if ( V_102 ) {
F_40 ( V_2 , V_106 , & V_4 , 1 ) ;
memcpy ( V_105 , & V_4 , V_101 ) ;
} else {
memcpy ( & V_4 , V_105 , V_101 ) ;
F_41 ( V_2 , V_106 , & V_4 , 1 ) ;
}
return;
}
if ( V_102 )
F_42 ( V_2 , V_106 , V_100 , V_101 >> 1 ) ;
else
F_43 ( V_2 , V_106 , V_100 , V_101 >> 1 ) ;
if ( ! ( V_101 & 0x1 ) )
return;
V_103 = ( T_3 * ) ( V_100 + ( V_101 >> 1 ) ) ;
if ( V_102 )
* V_103 = F_18 ( V_2 , V_106 ) & 0xff ;
else
F_19 ( V_2 , V_106 , * V_103 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
void * V_107 ;
unsigned short * V_100 ;
unsigned int V_101 ;
unsigned long V_33 ;
if ( ( V_2 -> V_11 || V_2 -> V_12 ) && ! V_2 -> V_66 ) {
F_45 ( L_3 ) ;
return;
} else if ( ! V_4 ) {
F_38 ( L_4 ) ;
return;
}
V_107 = F_46 ( V_2 -> V_21 , & V_33 ) ;
V_100 = ( unsigned short * ) ( V_107 + V_2 -> V_24 ) ;
V_101 = V_2 -> V_21 -> V_108 - V_2 -> V_24 ;
if ( V_101 > V_4 -> V_109 )
V_101 = V_4 -> V_109 ;
F_38 ( L_5 ,
V_101 , V_2 -> V_24 , V_4 -> V_33 ) ;
F_39 ( V_2 , V_100 , V_101 ) ;
V_2 -> V_24 += V_101 ;
F_47 ( V_2 -> V_21 , & V_33 , V_107 ) ;
if ( V_2 -> V_24 == V_2 -> V_21 -> V_108 )
F_12 ( V_2 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 == & V_2 -> V_110 ) {
unsigned long V_33 ;
void * V_111 = F_46 ( V_2 -> V_23 , & V_33 ) ;
memcpy ( V_111 , V_2 -> V_112 , V_2 -> V_110 . V_108 ) ;
F_47 ( V_2 -> V_23 , & V_33 , V_111 ) ;
}
}
void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_67 * V_113 ;
V_2 -> V_4 = NULL ;
if ( ! V_4 ) {
F_34 ( & V_2 -> V_48 -> V_62 , L_6 ) ;
return;
}
V_113 = V_4 -> V_113 ;
if ( ! V_4 -> error )
V_4 -> V_114 = V_4 -> V_84 * V_4 -> V_109 ;
else
V_4 -> V_114 = 0 ;
F_38 ( L_7 ) ;
if ( V_4 -> V_33 & V_92 ) {
if ( V_2 -> V_12 && ! V_2 -> V_66 )
F_48 ( V_2 ) ;
F_50 ( & V_2 -> V_48 -> V_62 , L_8 ,
V_2 -> V_58 ) ;
} else {
F_50 ( & V_2 -> V_48 -> V_62 , L_9 ,
V_2 -> V_58 ) ;
}
if ( V_113 && ! V_2 -> V_58 -> V_90 ) {
if ( V_113 -> V_64 != V_115 || V_113 -> V_98 )
F_51 ( & V_2 -> V_48 -> V_62 , L_10 ,
V_113 -> V_64 , V_113 -> V_98 ) ;
V_113 -> V_116 [ 0 ] = F_52 ( V_2 , V_117 ) ;
F_19 ( V_2 , V_85 , 0 ) ;
}
F_53 ( & V_2 -> V_118 ) ;
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_119 )
{
struct V_3 * V_4 ;
F_55 ( & V_2 -> V_59 ) ;
V_4 = V_2 -> V_4 ;
if ( ! V_4 )
goto V_120;
if ( V_119 & V_121 || V_119 & V_122 ||
V_119 & V_123 )
V_4 -> error = - V_124 ;
if ( V_2 -> V_11 && ( V_4 -> V_33 & V_125 ) && ! V_2 -> V_66 ) {
T_1 V_126 = F_52 ( V_2 , V_19 ) ;
bool V_118 = false ;
if ( V_2 -> V_9 -> V_33 & V_127 ) {
if ( V_126 & V_128 )
V_118 = true ;
} else {
if ( ! ( V_126 & V_129 ) )
V_118 = true ;
}
if ( V_118 ) {
F_9 ( V_2 , V_130 ) ;
F_6 ( V_2 ) ;
}
} else if ( V_2 -> V_12 && ( V_4 -> V_33 & V_92 ) && ! V_2 -> V_66 ) {
F_9 ( V_2 , V_130 ) ;
F_6 ( V_2 ) ;
} else {
F_49 ( V_2 ) ;
F_9 ( V_2 , V_131 | V_132 ) ;
}
V_120:
F_56 ( & V_2 -> V_59 ) ;
}
static void F_57 ( struct V_1 * V_2 , unsigned int V_119 )
{
struct V_67 * V_63 = V_2 -> V_63 ;
int V_15 , V_133 ;
F_55 ( & V_2 -> V_59 ) ;
if ( ! V_2 -> V_63 ) {
F_38 ( L_11 ) ;
goto V_120;
}
for ( V_15 = 3 , V_133 = V_117 ; V_15 >= 0 ; V_15 -- , V_133 += 4 )
V_63 -> V_116 [ V_15 ] = F_52 ( V_2 , V_133 ) ;
if ( V_63 -> V_33 & V_134 ) {
V_63 -> V_116 [ 0 ] = ( V_63 -> V_116 [ 0 ] << 8 ) | ( V_63 -> V_116 [ 1 ] >> 24 ) ;
V_63 -> V_116 [ 1 ] = ( V_63 -> V_116 [ 1 ] << 8 ) | ( V_63 -> V_116 [ 2 ] >> 24 ) ;
V_63 -> V_116 [ 2 ] = ( V_63 -> V_116 [ 2 ] << 8 ) | ( V_63 -> V_116 [ 3 ] >> 24 ) ;
V_63 -> V_116 [ 3 ] <<= 8 ;
} else if ( V_63 -> V_33 & V_80 ) {
V_63 -> V_116 [ 0 ] = V_63 -> V_116 [ 3 ] ;
}
if ( V_119 & V_135 )
V_63 -> error = - V_65 ;
else if ( ( V_119 & V_121 && V_63 -> V_33 & V_136 ) ||
V_119 & V_122 ||
V_119 & V_137 )
V_63 -> error = - V_124 ;
if ( V_2 -> V_4 && ( ! V_63 -> error || V_63 -> error == - V_124 ) ) {
if ( V_2 -> V_4 -> V_33 & V_92 ) {
if ( V_2 -> V_66 || ! V_2 -> V_12 )
F_7 ( V_2 , V_131 ) ;
else
F_58 ( & V_2 -> V_138 ) ;
} else {
if ( V_2 -> V_66 || ! V_2 -> V_11 )
F_7 ( V_2 , V_132 ) ;
else
F_58 ( & V_2 -> V_138 ) ;
}
} else {
F_53 ( & V_2 -> V_118 ) ;
}
V_120:
F_56 ( & V_2 -> V_59 ) ;
}
static bool F_59 ( struct V_1 * V_2 ,
int V_139 , int V_126 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_139 & ( V_96 | V_95 ) ) {
F_10 ( V_2 , V_96 |
V_95 ) ;
if ( ( ( ( V_139 & V_95 ) && V_26 -> V_140 ) ||
( ( V_139 & V_96 ) && ! V_26 -> V_140 ) ) &&
! F_60 ( & V_26 -> V_141 . V_55 ) )
F_61 ( V_2 -> V_26 , F_32 ( 100 ) ) ;
return true ;
}
return false ;
}
static bool F_62 ( struct V_1 * V_2 , int V_139 ,
int V_126 )
{
if ( V_139 & ( V_142 | V_135 ) ) {
F_10 ( V_2 , V_142 |
V_135 ) ;
F_57 ( V_2 , V_126 ) ;
return true ;
}
if ( V_139 & ( V_143 | V_144 ) ) {
F_10 ( V_2 , V_143 | V_144 ) ;
F_44 ( V_2 ) ;
return true ;
}
if ( V_139 & V_130 ) {
F_10 ( V_2 , V_130 ) ;
F_54 ( V_2 , V_126 ) ;
return true ;
}
return false ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned int V_139 , V_126 ;
unsigned int V_28 ;
if ( ! ( V_9 -> V_33 & V_52 ) )
return;
V_126 = F_18 ( V_2 , V_32 ) ;
V_139 = V_126 & V_30 & ~ V_2 -> V_29 ;
V_28 = V_126 & ~ V_30 ;
if ( V_9 -> V_33 & V_34 )
V_28 |= V_35 ;
F_19 ( V_2 , V_32 , V_28 ) ;
if ( V_26 -> V_145 & V_146 && V_139 & V_31 )
F_64 ( V_26 ) ;
}
T_4 F_65 ( int V_147 , void * V_148 )
{
struct V_1 * V_2 = V_148 ;
unsigned int V_139 , V_126 ;
V_126 = F_52 ( V_2 , V_19 ) ;
V_139 = V_126 & V_17 & ~ V_2 -> V_16 ;
F_8 ( V_2 , V_19 , V_17 ) ;
if ( F_59 ( V_2 , V_139 , V_126 ) )
return V_149 ;
if ( F_62 ( V_2 , V_139 , V_126 ) )
return V_149 ;
F_63 ( V_2 ) ;
return V_149 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
F_38 ( L_12 ,
V_4 -> V_109 , V_4 -> V_84 ) ;
if ( V_2 -> V_26 -> V_150 . V_151 == V_152 ||
V_2 -> V_26 -> V_150 . V_151 == V_153 ) {
int V_154 = V_9 -> V_33 & V_155 ;
if ( V_4 -> V_109 < 2 || ( V_4 -> V_109 < 4 && ! V_154 ) ) {
F_45 ( L_13 ,
F_67 ( V_2 -> V_26 ) , V_4 -> V_109 ) ;
return - V_82 ;
}
}
F_11 ( V_2 , V_4 ) ;
V_2 -> V_4 = V_4 ;
F_19 ( V_2 , V_156 , V_4 -> V_109 ) ;
F_19 ( V_2 , V_157 , V_4 -> V_84 ) ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static void F_68 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_15 ( V_26 ) ;
if ( V_2 -> V_158 )
V_2 -> V_158 ( V_2 ) ;
}
static int F_69 ( struct V_25 * V_26 , T_1 V_64 )
{
struct V_1 * V_2 = F_15 ( V_26 ) ;
int V_15 , V_159 = 0 ;
if ( ! V_2 -> V_160 || ! V_2 -> V_161 )
goto V_120;
V_2 -> V_162 = V_2 -> V_160 ( V_2 ) ;
if ( ! V_2 -> V_162 )
goto V_120;
if ( V_2 -> V_162 * 2 >= sizeof( V_2 -> V_163 ) * V_164 ) {
F_70 ( & V_2 -> V_48 -> V_62 ,
L_14 ) ;
goto V_120;
}
F_71 ( V_2 -> V_163 , V_2 -> V_162 * 2 ) ;
for ( V_15 = 0 ; V_15 < 2 * V_2 -> V_162 ; V_15 ++ ) {
if ( V_2 -> V_165 )
V_2 -> V_165 ( V_2 , V_15 % V_2 -> V_162 ) ;
V_159 = F_72 ( V_26 , V_64 , NULL ) ;
if ( V_159 && V_159 != - V_124 )
goto V_120;
if ( V_159 == 0 )
F_73 ( V_15 , V_2 -> V_163 ) ;
F_74 ( 1 ) ;
}
V_159 = V_2 -> V_161 ( V_2 ) ;
V_120:
if ( V_159 < 0 ) {
F_34 ( & V_2 -> V_48 -> V_62 , L_15 ) ;
F_68 ( V_26 ) ;
}
return V_159 ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_67 * V_63 ;
int V_159 ;
if ( V_58 -> V_90 && V_2 -> V_63 != V_58 -> V_90 ) {
V_63 = V_58 -> V_90 ;
} else {
V_63 = V_58 -> V_63 ;
if ( V_58 -> V_4 ) {
V_159 = F_66 ( V_2 , V_58 -> V_4 ) ;
if ( V_159 )
goto V_166;
}
}
V_159 = F_36 ( V_2 , V_63 ) ;
if ( V_159 )
goto V_166;
F_76 ( & V_2 -> V_56 ,
F_32 ( V_61 ) ) ;
return;
V_166:
V_2 -> V_66 = false ;
V_2 -> V_58 = NULL ;
V_58 -> V_63 -> error = V_159 ;
F_35 ( V_2 -> V_26 , V_58 ) ;
}
static void F_77 ( struct V_25 * V_26 , struct V_57 * V_58 )
{
struct V_1 * V_2 = F_15 ( V_26 ) ;
unsigned long V_33 ;
F_29 ( & V_2 -> V_59 , V_33 ) ;
if ( V_2 -> V_58 ) {
F_38 ( L_16 ) ;
if ( F_78 ( V_2 -> V_58 ) ) {
F_33 ( & V_2 -> V_59 , V_33 ) ;
V_58 -> V_63 -> error = - V_167 ;
F_35 ( V_26 , V_58 ) ;
return;
}
}
V_2 -> V_60 = V_168 ;
F_79 () ;
V_2 -> V_58 = V_58 ;
F_33 ( & V_2 -> V_59 , V_33 ) ;
F_75 ( V_2 , V_58 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
unsigned long V_33 ;
F_29 ( & V_2 -> V_59 , V_33 ) ;
V_58 = V_2 -> V_58 ;
if ( F_30 ( V_58 ) ) {
F_33 ( & V_2 -> V_59 , V_33 ) ;
return;
}
if ( V_2 -> V_63 != V_58 -> V_90 ) {
V_2 -> V_63 = NULL ;
V_2 -> V_4 = NULL ;
V_2 -> V_66 = false ;
V_2 -> V_58 = NULL ;
}
F_81 ( & V_2 -> V_56 ) ;
F_33 ( & V_2 -> V_59 , V_33 ) ;
if ( V_58 -> V_63 -> error || ( V_58 -> V_4 && V_58 -> V_4 -> error ) )
F_5 ( V_2 ) ;
if ( V_2 -> V_169 )
V_2 -> V_169 ( V_2 ) ;
if ( V_2 -> V_58 ) {
F_75 ( V_2 , V_58 ) ;
return;
}
F_35 ( V_2 -> V_26 , V_58 ) ;
}
static void F_82 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_28 ( V_55 , struct V_1 ,
V_118 ) ;
F_80 ( V_2 ) ;
}
static int F_83 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_170 )
return - V_171 ;
return V_2 -> V_170 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
if ( V_2 -> V_172 )
V_2 -> V_172 ( V_2 ) ;
}
static void F_85 ( struct V_1 * V_2 , unsigned short V_173 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_159 = 0 ;
if ( V_2 -> V_174 )
V_2 -> V_174 ( V_2 -> V_48 , 1 ) ;
if ( ! F_78 ( V_26 -> V_175 . V_176 ) ) {
V_159 = F_86 ( V_26 , V_26 -> V_175 . V_176 , V_173 ) ;
F_87 ( 200 ) ;
}
if ( ! F_78 ( V_26 -> V_175 . V_177 ) && ! V_159 ) {
V_159 = F_88 ( V_26 -> V_175 . V_177 ) ;
F_87 ( 200 ) ;
}
if ( V_159 < 0 )
F_50 ( & V_2 -> V_48 -> V_62 , L_17 ,
V_159 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
if ( ! F_78 ( V_26 -> V_175 . V_177 ) )
F_90 ( V_26 -> V_175 . V_177 ) ;
if ( ! F_78 ( V_26 -> V_175 . V_176 ) )
F_86 ( V_26 , V_26 -> V_175 . V_176 , 0 ) ;
if ( V_2 -> V_174 )
V_2 -> V_174 ( V_2 -> V_48 , 0 ) ;
}
static void F_91 ( struct V_1 * V_2 ,
unsigned char V_151 )
{
T_2 V_178 = F_18 ( V_2 , V_179 )
& ~ ( V_180 | V_181 ) ;
if ( V_151 == V_182 )
V_178 |= V_180 ;
else if ( V_151 == V_153 )
V_178 |= V_181 ;
F_19 ( V_2 , V_179 , V_178 ) ;
}
static void F_92 ( struct V_25 * V_26 , struct V_183 * V_150 )
{
struct V_1 * V_2 = F_15 ( V_26 ) ;
struct V_184 * V_62 = & V_2 -> V_48 -> V_62 ;
unsigned long V_33 ;
F_93 ( & V_2 -> V_185 ) ;
F_29 ( & V_2 -> V_59 , V_33 ) ;
if ( V_2 -> V_58 ) {
if ( F_78 ( V_2 -> V_58 ) ) {
F_50 ( V_62 ,
L_18 ,
V_186 -> V_187 , F_94 ( V_186 ) ,
V_150 -> clock , V_150 -> V_188 ) ;
V_2 -> V_58 = F_95 ( - V_189 ) ;
} else {
F_50 ( V_62 ,
L_19 ,
V_186 -> V_187 , F_94 ( V_186 ) ,
V_2 -> V_58 -> V_63 -> V_64 , V_2 -> V_60 ,
V_168 ) ;
}
F_33 ( & V_2 -> V_59 , V_33 ) ;
F_96 ( & V_2 -> V_185 ) ;
return;
}
V_2 -> V_58 = F_95 ( - V_190 ) ;
F_33 ( & V_2 -> V_59 , V_33 ) ;
switch ( V_150 -> V_188 ) {
case V_191 :
F_89 ( V_2 ) ;
F_24 ( V_2 ) ;
break;
case V_192 :
F_85 ( V_2 , V_150 -> V_173 ) ;
F_25 ( V_2 , V_150 -> clock ) ;
F_91 ( V_2 , V_150 -> V_151 ) ;
break;
case V_193 :
F_25 ( V_2 , V_150 -> clock ) ;
F_91 ( V_2 , V_150 -> V_151 ) ;
break;
}
F_87 ( 140 ) ;
if ( F_97 ( V_2 -> V_58 ) == - V_189 )
F_50 ( & V_2 -> V_48 -> V_62 ,
L_20 ,
V_186 -> V_187 , F_94 ( V_186 ) ,
V_150 -> clock , V_150 -> V_188 ) ;
V_2 -> V_58 = NULL ;
V_2 -> V_194 = V_150 -> clock ;
F_96 ( & V_2 -> V_185 ) ;
}
static int F_98 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_15 ( V_26 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
int V_159 = F_99 ( V_26 ) ;
if ( V_159 >= 0 )
return V_159 ;
V_159 = ! ( ( V_9 -> V_33 & V_195 ) ||
( F_52 ( V_2 , V_19 ) & V_196 ) ) ;
return V_159 ;
}
static int F_100 ( struct V_197 * V_140 ,
unsigned int V_198 , int V_199 )
{
struct V_1 * V_2 = F_15 ( V_140 -> V_2 ) ;
if ( V_2 -> V_200 )
return V_2 -> V_200 ( V_140 , V_198 , V_199 ) ;
return V_199 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_25 * V_26 = V_2 -> V_26 ;
F_102 ( V_26 ) ;
if ( ! V_26 -> V_201 )
V_26 -> V_201 = V_9 -> V_202 ;
if ( ! V_26 -> V_201 )
return - V_203 ;
return 0 ;
}
static void F_103 ( struct V_204 * V_48 ,
struct V_8 * V_9 )
{
const struct V_205 * V_206 = V_48 -> V_62 . V_207 ;
if ( ! V_206 )
return;
if ( F_104 ( V_206 , L_21 , NULL ) )
V_9 -> V_33 |= V_195 ;
}
struct V_1 *
F_105 ( struct V_204 * V_48 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 ;
V_26 = F_106 ( sizeof( struct V_1 ) , & V_48 -> V_62 ) ;
if ( ! V_26 )
return NULL ;
V_2 = F_15 ( V_26 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_48 = V_48 ;
return V_2 ;
}
void F_107 ( struct V_1 * V_2 )
{
F_108 ( V_2 -> V_26 ) ;
}
int F_109 ( struct V_1 * V_208 ,
struct V_8 * V_9 ,
const struct V_209 * V_5 )
{
struct V_204 * V_48 = V_208 -> V_48 ;
struct V_25 * V_26 = V_208 -> V_26 ;
struct V_210 * V_211 ;
int V_159 ;
T_1 V_69 = V_70 ;
F_103 ( V_48 , V_9 ) ;
if ( ! ( V_9 -> V_33 & V_127 ) )
V_208 -> V_212 = NULL ;
V_211 = F_110 ( V_48 , V_213 , 0 ) ;
if ( ! V_211 )
return - V_82 ;
V_159 = F_111 ( V_26 ) ;
if ( V_159 < 0 )
return V_159 ;
V_208 -> V_9 = V_9 ;
F_112 ( V_48 , V_26 ) ;
V_208 -> V_174 = V_9 -> V_174 ;
V_208 -> V_47 = V_9 -> V_47 ;
V_159 = F_101 ( V_208 ) ;
if ( V_159 < 0 )
return V_159 ;
V_208 -> V_214 = F_113 ( & V_48 -> V_62 ,
V_211 -> V_6 , F_114 ( V_211 ) ) ;
if ( ! V_208 -> V_214 )
return - V_215 ;
V_216 . V_217 = V_208 -> V_217 ;
V_216 . V_218 =
V_208 -> V_218 ;
V_26 -> V_219 = & V_216 ;
V_26 -> V_145 |= V_220 | V_9 -> V_221 ;
V_26 -> V_222 |= V_9 -> V_223 ;
V_26 -> V_224 = V_9 -> V_224 ? : 32 ;
V_26 -> V_225 = 512 ;
V_26 -> V_226 = V_9 -> V_226 ? :
( V_227 / V_26 -> V_225 ) * V_26 -> V_224 ;
V_26 -> V_228 = V_26 -> V_225 * V_26 -> V_226 ;
if ( F_115 () ) {
unsigned int V_229 = ( 1 << V_230 ) * V_231 ;
if ( V_26 -> V_228 > V_229 )
V_26 -> V_228 = V_229 ;
}
V_26 -> V_232 = V_26 -> V_228 ;
V_208 -> V_94 = ! ( V_9 -> V_33 & V_233 ||
V_26 -> V_145 & V_234 ||
! F_116 ( V_26 ) ) ;
if ( V_9 -> V_33 & V_39 )
V_208 -> V_94 = true ;
if ( F_83 ( V_208 ) < 0 ) {
V_26 -> V_235 = V_9 -> V_236 ;
V_26 -> V_45 = V_26 -> V_235 / 512 ;
}
if ( V_26 -> V_45 == 0 )
return - V_82 ;
if ( V_208 -> V_94 )
F_117 ( & V_48 -> V_62 ) ;
V_208 -> V_27 = false ;
if ( V_9 -> V_33 & V_52 )
V_208 -> V_29 = V_30 ;
F_24 ( V_208 ) ;
F_26 ( V_208 ) ;
V_208 -> V_16 = F_52 ( V_208 , V_18 ) ;
F_9 ( V_208 , V_237 ) ;
if ( ! V_208 -> V_12 )
V_69 |= V_131 ;
if ( ! V_208 -> V_11 )
V_69 |= V_132 ;
if ( ! V_208 -> V_94 )
V_69 &= ~ ( V_95 | V_96 ) ;
V_208 -> V_16 &= ~ V_69 ;
F_118 ( & V_208 -> V_59 ) ;
F_119 ( & V_208 -> V_185 ) ;
F_120 ( & V_208 -> V_56 , F_27 ) ;
F_121 ( & V_208 -> V_118 , F_82 ) ;
V_208 -> V_5 = V_5 ;
F_3 ( V_208 , V_9 ) ;
F_122 ( & V_48 -> V_62 ) ;
F_123 ( & V_48 -> V_62 , 50 ) ;
F_124 ( & V_48 -> V_62 ) ;
F_125 ( & V_48 -> V_62 ) ;
V_159 = F_126 ( V_26 ) ;
if ( V_159 < 0 ) {
F_127 ( V_208 ) ;
return V_159 ;
}
F_128 ( & V_48 -> V_62 , 100 ) ;
if ( V_9 -> V_33 & V_233 ) {
V_159 = F_129 ( V_26 , V_9 -> V_238 , 0 ) ;
if ( V_159 < 0 ) {
F_127 ( V_208 ) ;
return V_159 ;
}
F_130 ( V_26 ) ;
}
return 0 ;
}
void F_127 ( struct V_1 * V_2 )
{
struct V_204 * V_48 = V_2 -> V_48 ;
struct V_25 * V_26 = V_2 -> V_26 ;
if ( V_2 -> V_9 -> V_33 & V_52 )
F_19 ( V_2 , V_53 , 0x0000 ) ;
if ( ! V_2 -> V_94 )
F_16 ( & V_48 -> V_62 ) ;
F_131 ( & V_48 -> V_62 ) ;
F_132 ( V_26 ) ;
F_133 ( & V_2 -> V_118 ) ;
F_134 ( & V_2 -> V_56 ) ;
F_4 ( V_2 ) ;
F_135 ( & V_48 -> V_62 ) ;
F_136 ( & V_48 -> V_62 ) ;
F_84 ( V_2 ) ;
}
int F_137 ( struct V_184 * V_62 )
{
struct V_25 * V_26 = F_138 ( V_62 ) ;
struct V_1 * V_2 = F_15 ( V_26 ) ;
F_9 ( V_2 , V_237 ) ;
if ( V_2 -> V_194 )
F_24 ( V_2 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static bool F_139 ( struct V_1 * V_2 )
{
return V_2 -> V_162 && F_140 ( V_2 -> V_26 ) ;
}
int F_141 ( struct V_184 * V_62 )
{
struct V_25 * V_26 = F_138 ( V_62 ) ;
struct V_1 * V_2 = F_15 ( V_26 ) ;
F_26 ( V_2 ) ;
F_83 ( V_2 ) ;
if ( V_2 -> V_194 )
F_25 ( V_2 , V_2 -> V_194 ) ;
F_2 ( V_2 , true ) ;
if ( F_139 ( V_2 ) && V_2 -> V_161 ( V_2 ) )
F_34 ( & V_2 -> V_48 -> V_62 , L_22 ) ;
return 0 ;
}

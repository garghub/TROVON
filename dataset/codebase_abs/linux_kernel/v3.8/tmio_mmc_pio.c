void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 &= ~ ( V_3 & V_5 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_4 ) ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
V_2 -> V_4 |= ( V_3 & V_5 ) ;
F_2 ( V_2 , V_6 , V_2 -> V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_7 , ~ V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
V_2 -> V_10 = V_9 -> V_10 ;
V_2 -> V_11 = V_9 -> V_12 ;
V_2 -> V_13 = V_9 -> V_12 ;
V_2 -> V_14 = 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
V_2 -> V_11 = F_7 ( V_2 -> V_11 ) ;
V_2 -> V_14 = 0 ;
return -- V_2 -> V_10 ;
}
static void F_8 ( T_1 V_15 )
{
int V_3 = 0 ;
F_9 ( L_1 , V_15 ) ;
F_10 ( V_16 , V_15 , V_3 ) ;
F_10 ( V_17 , V_15 , V_3 ) ;
F_10 ( V_18 , V_15 , V_3 ) ;
F_10 ( V_19 , V_15 , V_3 ) ;
F_10 ( V_20 , V_15 , V_3 ) ;
F_10 ( V_21 , V_15 , V_3 ) ;
F_10 ( V_22 , V_15 , V_3 ) ;
F_10 ( V_23 , V_15 , V_3 ) ;
F_10 ( V_24 , V_15 , V_3 ) ;
F_10 ( V_25 , V_15 , V_3 ) ;
F_10 ( V_26 , V_15 , V_3 ) ;
F_10 ( V_27 , V_15 , V_3 ) ;
F_10 ( V_28 , V_15 , V_3 ) ;
F_10 ( V_29 , V_15 , V_3 ) ;
F_10 ( V_30 , V_15 , V_3 ) ;
F_10 ( V_31 , V_15 , V_3 ) ;
F_10 ( V_32 , V_15 , V_3 ) ;
F_10 ( V_33 , V_15 , V_3 ) ;
F_10 ( V_34 , V_15 , V_3 ) ;
F_10 ( V_35 , V_15 , V_3 ) ;
F_10 ( V_36 , V_15 , V_3 ) ;
F_11 ( L_2 ) ;
}
static void F_12 ( struct V_37 * V_38 , int V_39 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
if ( V_39 ) {
V_2 -> V_40 = V_41 &
~ V_42 ;
F_14 ( V_2 , V_43 , 0x0001 ) ;
F_14 ( V_2 , V_44 , V_2 -> V_40 ) ;
} else {
V_2 -> V_40 = V_41 ;
F_14 ( V_2 , V_44 , V_2 -> V_40 ) ;
F_14 ( V_2 , V_43 , 0x0000 ) ;
}
}
static void F_15 ( struct V_1 * V_2 , int V_45 )
{
T_1 V_46 = 0 , clock ;
if ( V_45 ) {
for ( clock = V_2 -> V_38 -> V_47 , V_46 = 0x80000080 ;
V_45 >= ( clock << 1 ) ; V_46 >>= 1 )
clock <<= 1 ;
V_46 |= 0x100 ;
}
if ( V_2 -> V_48 )
V_2 -> V_48 ( V_2 -> V_49 , ( V_46 >> 22 ) & 1 ) ;
F_14 ( V_2 , V_50 , V_46 & 0x1ff ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = F_17 ( V_2 -> V_49 , V_53 , 0 ) ;
if ( F_18 ( V_52 ) > 0x100 ) {
F_14 ( V_2 , V_54 , 0x0000 ) ;
F_19 ( 10 ) ;
}
F_14 ( V_2 , V_50 , ~ 0x0100 &
F_20 ( V_2 , V_50 ) ) ;
F_19 ( 10 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = F_17 ( V_2 -> V_49 , V_53 , 0 ) ;
F_14 ( V_2 , V_50 , 0x0100 |
F_20 ( V_2 , V_50 ) ) ;
F_19 ( 10 ) ;
if ( F_18 ( V_52 ) > 0x100 ) {
F_14 ( V_2 , V_54 , 0x0100 ) ;
F_19 ( 10 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = F_17 ( V_2 -> V_49 , V_53 , 0 ) ;
F_14 ( V_2 , V_55 , 0x0000 ) ;
if ( F_18 ( V_52 ) > 0x100 )
F_14 ( V_2 , V_56 , 0x0000 ) ;
F_19 ( 10 ) ;
F_14 ( V_2 , V_55 , 0x0001 ) ;
if ( F_18 ( V_52 ) > 0x100 )
F_14 ( V_2 , V_56 , 0x0001 ) ;
F_19 ( 10 ) ;
}
static void F_23 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_24 ( V_58 , struct V_1 ,
V_59 . V_58 ) ;
struct V_60 * V_61 ;
unsigned long V_62 ;
F_25 ( & V_2 -> V_63 , V_62 ) ;
V_61 = V_2 -> V_61 ;
if ( F_26 ( V_61 )
|| F_27 ( V_2 -> V_64 +
F_28 ( 2000 ) ) ) {
F_29 ( & V_2 -> V_63 , V_62 ) ;
return;
}
F_30 ( & V_2 -> V_49 -> V_65 ,
L_3 ,
V_61 -> V_66 -> V_67 ) ;
if ( V_2 -> V_9 )
V_2 -> V_9 -> error = - V_68 ;
else if ( V_2 -> V_66 )
V_2 -> V_66 -> error = - V_68 ;
else
V_61 -> V_66 -> error = - V_68 ;
V_2 -> V_66 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_69 = false ;
F_29 ( & V_2 -> V_63 , V_62 ) ;
F_22 ( V_2 ) ;
V_2 -> V_61 = NULL ;
F_31 ( V_2 ) ;
F_32 ( V_2 -> V_38 , V_61 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
unsigned long V_62 ;
F_25 ( & V_2 -> V_63 , V_62 ) ;
V_61 = V_2 -> V_61 ;
if ( F_26 ( V_61 ) ) {
F_29 ( & V_2 -> V_63 , V_62 ) ;
return;
}
V_2 -> V_66 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_69 = false ;
F_34 ( & V_2 -> V_59 ) ;
V_2 -> V_61 = NULL ;
F_29 ( & V_2 -> V_63 , V_62 ) ;
if ( V_61 -> V_66 -> error || ( V_61 -> V_9 && V_61 -> V_9 -> error ) )
F_31 ( V_2 ) ;
F_32 ( V_2 -> V_38 , V_61 ) ;
}
static void F_35 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_24 ( V_58 , struct V_1 ,
V_70 ) ;
F_33 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_71 * V_66 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_72 = V_66 -> V_67 ;
T_1 V_73 = V_74 ;
if ( V_66 -> V_67 == V_75 && ! V_66 -> V_76 ) {
F_14 ( V_2 , V_77 , 0x001 ) ;
return 0 ;
}
switch ( F_37 ( V_66 ) ) {
case V_78 : V_72 |= V_79 ; break;
case V_80 : V_72 |= V_81 ; break;
case V_82 : V_72 |= V_83 ; break;
case V_84 : V_72 |= V_85 ; break;
case V_86 : V_72 |= V_87 ; break;
default:
F_9 ( L_4 , F_37 ( V_66 ) ) ;
return - V_88 ;
}
V_2 -> V_66 = V_66 ;
if ( V_9 ) {
V_72 |= V_89 ;
if ( V_9 -> V_90 > 1 ) {
F_14 ( V_2 , V_77 , 0x100 ) ;
V_72 |= V_91 ;
}
if ( V_9 -> V_62 & V_92 )
V_72 |= V_93 ;
}
if ( ! V_2 -> V_94 )
V_73 &= ~ ( V_95 | V_96 ) ;
F_1 ( V_2 , V_73 ) ;
F_2 ( V_2 , V_97 , V_66 -> V_76 ) ;
F_14 ( V_2 , V_98 , V_72 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_99 ;
unsigned short * V_100 ;
unsigned int V_101 ;
unsigned long V_62 ;
if ( ( V_2 -> V_102 || V_2 -> V_103 ) && ! V_2 -> V_69 ) {
F_39 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_99 = F_40 ( V_2 -> V_11 , & V_62 ) ;
V_100 = ( unsigned short * ) ( V_99 + V_2 -> V_14 ) ;
V_101 = V_2 -> V_11 -> V_104 - V_2 -> V_14 ;
if ( V_101 > V_9 -> V_105 )
V_101 = V_9 -> V_105 ;
F_9 ( L_7 ,
V_101 , V_2 -> V_14 , V_9 -> V_62 ) ;
if ( V_9 -> V_62 & V_92 )
F_41 ( V_2 , V_106 , V_100 , V_101 >> 1 ) ;
else
F_42 ( V_2 , V_106 , V_100 , V_101 >> 1 ) ;
V_2 -> V_14 += V_101 ;
F_43 ( V_2 -> V_11 , & V_62 , V_99 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_104 )
F_6 ( V_2 ) ;
return;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_107 ) {
unsigned long V_62 ;
void * V_108 = F_40 ( V_2 -> V_13 , & V_62 ) ;
memcpy ( V_108 , V_2 -> V_109 , V_2 -> V_107 . V_104 ) ;
F_43 ( V_2 -> V_13 , & V_62 , V_108 ) ;
}
}
void F_45 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_71 * V_110 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_30 ( & V_2 -> V_49 -> V_65 , L_8 ) ;
return;
}
V_110 = V_9 -> V_110 ;
if ( ! V_9 -> error )
V_9 -> V_111 = V_9 -> V_90 * V_9 -> V_105 ;
else
V_9 -> V_111 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_62 & V_92 ) {
if ( V_2 -> V_103 && ! V_2 -> V_69 )
F_44 ( V_2 ) ;
F_46 ( & V_2 -> V_49 -> V_65 , L_10 ,
V_2 -> V_61 ) ;
} else {
F_46 ( & V_2 -> V_49 -> V_65 , L_11 ,
V_2 -> V_61 ) ;
}
if ( V_110 ) {
if ( V_110 -> V_67 == V_75 && ! V_110 -> V_76 )
F_14 ( V_2 , V_77 , 0x000 ) ;
else
F_47 () ;
}
F_48 ( & V_2 -> V_70 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_50 ( & V_2 -> V_63 ) ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 )
goto V_112;
if ( V_2 -> V_102 && ( V_9 -> V_62 & V_113 ) && ! V_2 -> V_69 ) {
if ( ! ( F_51 ( V_2 , V_7 ) & V_114 ) ) {
F_3 ( V_2 , V_115 ) ;
F_52 ( & V_2 -> V_116 ) ;
}
} else if ( V_2 -> V_103 && ( V_9 -> V_62 & V_92 ) && ! V_2 -> V_69 ) {
F_3 ( V_2 , V_115 ) ;
F_52 ( & V_2 -> V_116 ) ;
} else {
F_45 ( V_2 ) ;
F_3 ( V_2 , V_117 | V_118 ) ;
}
V_112:
F_53 ( & V_2 -> V_63 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
unsigned int V_119 )
{
struct V_71 * V_66 = V_2 -> V_66 ;
int V_3 , V_120 ;
F_50 ( & V_2 -> V_63 ) ;
if ( ! V_2 -> V_66 ) {
F_9 ( L_12 ) ;
goto V_112;
}
V_2 -> V_66 = NULL ;
for ( V_3 = 3 , V_120 = V_121 ; V_3 >= 0 ; V_3 -- , V_120 += 4 )
V_66 -> V_122 [ V_3 ] = F_51 ( V_2 , V_120 ) ;
if ( V_66 -> V_62 & V_123 ) {
V_66 -> V_122 [ 0 ] = ( V_66 -> V_122 [ 0 ] << 8 ) | ( V_66 -> V_122 [ 1 ] >> 24 ) ;
V_66 -> V_122 [ 1 ] = ( V_66 -> V_122 [ 1 ] << 8 ) | ( V_66 -> V_122 [ 2 ] >> 24 ) ;
V_66 -> V_122 [ 2 ] = ( V_66 -> V_122 [ 2 ] << 8 ) | ( V_66 -> V_122 [ 3 ] >> 24 ) ;
V_66 -> V_122 [ 3 ] <<= 8 ;
} else if ( V_66 -> V_62 & V_86 ) {
V_66 -> V_122 [ 0 ] = V_66 -> V_122 [ 3 ] ;
}
if ( V_119 & V_124 )
V_66 -> error = - V_68 ;
else if ( V_119 & V_125 && V_66 -> V_62 & V_126 )
V_66 -> error = - V_127 ;
if ( V_2 -> V_9 && ! V_66 -> error ) {
if ( V_2 -> V_9 -> V_62 & V_92 ) {
if ( V_2 -> V_69 || ! V_2 -> V_103 )
F_1 ( V_2 , V_117 ) ;
else
F_52 ( & V_2 -> V_128 ) ;
} else {
if ( V_2 -> V_69 || ! V_2 -> V_102 )
F_1 ( V_2 , V_118 ) ;
else
F_52 ( & V_2 -> V_128 ) ;
}
} else {
F_48 ( & V_2 -> V_70 ) ;
}
V_112:
F_53 ( & V_2 -> V_63 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
int * V_129 , int * V_15 )
{
* V_15 = F_51 ( V_2 , V_7 ) ;
* V_129 = * V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( * V_15 ) ;
F_8 ( * V_129 ) ;
}
static bool F_56 ( struct V_1 * V_2 ,
int V_129 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_129 & ( V_96 | V_95 ) ) {
F_4 ( V_2 , V_96 |
V_95 ) ;
if ( ( ( ( V_129 & V_95 ) && V_38 -> V_130 ) ||
( ( V_129 & V_96 ) && ! V_38 -> V_130 ) ) &&
! F_57 ( & V_38 -> V_131 . V_58 ) )
F_58 ( V_2 -> V_38 , F_28 ( 100 ) ) ;
return true ;
}
return false ;
}
T_2 F_59 ( int V_132 , void * V_133 )
{
unsigned int V_129 , V_15 ;
struct V_1 * V_2 = V_133 ;
F_55 ( V_2 , & V_129 , & V_15 ) ;
F_56 ( V_2 , V_129 , V_15 ) ;
return V_134 ;
}
static bool F_60 ( struct V_1 * V_2 ,
int V_129 , int V_15 )
{
if ( V_129 & ( V_135 | V_124 ) ) {
F_4 ( V_2 ,
V_135 |
V_124 ) ;
F_54 ( V_2 , V_15 ) ;
return true ;
}
if ( V_129 & ( V_136 | V_137 ) ) {
F_4 ( V_2 , V_136 | V_137 ) ;
F_38 ( V_2 ) ;
return true ;
}
if ( V_129 & V_115 ) {
F_4 ( V_2 , V_115 ) ;
F_49 ( V_2 ) ;
return true ;
}
return false ;
}
T_2 F_61 ( int V_132 , void * V_133 )
{
unsigned int V_129 , V_15 ;
struct V_1 * V_2 = V_133 ;
F_55 ( V_2 , & V_129 , & V_15 ) ;
F_60 ( V_2 , V_129 , V_15 ) ;
return V_134 ;
}
T_2 F_62 ( int V_132 , void * V_133 )
{
struct V_1 * V_2 = V_133 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_138 * V_139 = V_2 -> V_139 ;
unsigned int V_129 , V_15 ;
if ( ! ( V_139 -> V_62 & V_140 ) )
return V_134 ;
V_15 = F_20 ( V_2 , V_141 ) ;
V_129 = V_15 & V_41 & ~ V_2 -> V_4 ;
F_14 ( V_2 , V_141 , V_15 & ~ V_41 ) ;
if ( V_38 -> V_142 & V_143 && V_129 & V_42 )
F_63 ( V_38 ) ;
return V_134 ;
}
T_2 F_64 ( int V_132 , void * V_133 )
{
struct V_1 * V_2 = V_133 ;
unsigned int V_129 , V_15 ;
F_9 ( L_13 ) ;
F_55 ( V_2 , & V_129 , & V_15 ) ;
if ( F_56 ( V_2 , V_129 , V_15 ) )
return V_134 ;
if ( F_60 ( V_2 , V_129 , V_15 ) )
return V_134 ;
F_62 ( V_132 , V_133 ) ;
return V_134 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_138 * V_139 = V_2 -> V_139 ;
F_9 ( L_14 ,
V_9 -> V_105 , V_9 -> V_90 ) ;
if ( V_2 -> V_38 -> V_144 . V_145 == V_146 ) {
int V_147 = V_139 -> V_62 & V_148 ;
if ( V_9 -> V_105 < 2 || ( V_9 -> V_105 < 4 && ! V_147 ) ) {
F_39 ( L_15 ,
F_66 ( V_2 -> V_38 ) , V_9 -> V_105 ) ;
return - V_88 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_14 ( V_2 , V_149 , V_9 -> V_105 ) ;
F_14 ( V_2 , V_150 , V_9 -> V_90 ) ;
F_67 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_68 ( struct V_37 * V_38 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_62 ;
int V_151 ;
F_25 ( & V_2 -> V_63 , V_62 ) ;
if ( V_2 -> V_61 ) {
F_9 ( L_16 ) ;
if ( F_69 ( V_2 -> V_61 ) ) {
F_29 ( & V_2 -> V_63 , V_62 ) ;
V_61 -> V_66 -> error = - V_152 ;
F_32 ( V_38 , V_61 ) ;
return;
}
}
V_2 -> V_64 = V_153 ;
F_70 () ;
V_2 -> V_61 = V_61 ;
F_29 ( & V_2 -> V_63 , V_62 ) ;
if ( V_61 -> V_9 ) {
V_151 = F_65 ( V_2 , V_61 -> V_9 ) ;
if ( V_151 )
goto V_154;
}
V_151 = F_36 ( V_2 , V_61 -> V_66 ) ;
if ( ! V_151 ) {
F_71 ( & V_2 -> V_59 ,
F_28 ( 2000 ) ) ;
return;
}
V_154:
V_2 -> V_69 = false ;
V_2 -> V_61 = NULL ;
V_61 -> V_66 -> error = V_151 ;
F_32 ( V_38 , V_61 ) ;
}
static int F_72 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_138 * V_139 = V_2 -> V_139 ;
int V_151 ;
if ( ! V_139 -> V_155 )
return - V_156 ;
V_151 = V_139 -> V_155 ( V_2 -> V_49 , & V_38 -> V_157 ) ;
if ( ! V_151 )
V_38 -> V_47 = V_38 -> V_157 / 512 ;
return V_151 ;
}
static void F_73 ( struct V_1 * V_2 , struct V_158 * V_144 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_2 -> V_159 )
V_2 -> V_159 ( V_2 -> V_49 , V_144 -> V_160 != V_161 ) ;
if ( ! F_69 ( V_38 -> V_162 . V_163 ) )
F_74 ( V_38 , V_38 -> V_162 . V_163 ,
V_144 -> V_160 ? V_144 -> V_164 : 0 ) ;
}
static void F_75 ( struct V_37 * V_38 , struct V_158 * V_144 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_165 * V_65 = & V_2 -> V_49 -> V_65 ;
unsigned long V_62 ;
F_76 ( & V_2 -> V_166 ) ;
F_25 ( & V_2 -> V_63 , V_62 ) ;
if ( V_2 -> V_61 ) {
if ( F_69 ( V_2 -> V_61 ) ) {
F_46 ( V_65 ,
L_17 ,
V_167 -> V_168 , F_77 ( V_167 ) ,
V_144 -> clock , V_144 -> V_160 ) ;
V_2 -> V_61 = F_78 ( - V_169 ) ;
} else {
F_46 ( V_65 ,
L_18 ,
V_167 -> V_168 , F_77 ( V_167 ) ,
V_2 -> V_61 -> V_66 -> V_67 , V_2 -> V_64 , V_153 ) ;
}
F_29 ( & V_2 -> V_63 , V_62 ) ;
F_79 ( & V_2 -> V_166 ) ;
return;
}
V_2 -> V_61 = F_78 ( - V_170 ) ;
F_29 ( & V_2 -> V_63 , V_62 ) ;
if ( V_144 -> V_160 == V_171 && V_144 -> clock ) {
if ( ! V_2 -> V_172 ) {
F_72 ( V_38 ) ;
F_80 ( V_65 ) ;
V_2 -> V_172 = true ;
}
F_15 ( V_2 , V_144 -> clock ) ;
F_73 ( V_2 , V_144 ) ;
F_21 ( V_2 ) ;
} else if ( V_144 -> V_160 != V_173 ) {
if ( V_144 -> V_160 == V_161 )
F_73 ( V_2 , V_144 ) ;
if ( V_2 -> V_172 ) {
struct V_138 * V_139 = V_2 -> V_139 ;
F_16 ( V_2 ) ;
V_2 -> V_172 = false ;
F_81 ( V_65 ) ;
if ( V_139 -> V_174 )
V_139 -> V_174 ( V_2 -> V_49 ) ;
}
}
if ( V_2 -> V_172 ) {
switch ( V_144 -> V_145 ) {
case V_175 :
F_14 ( V_2 , V_176 , 0x80e0 ) ;
break;
case V_146 :
F_14 ( V_2 , V_176 , 0x00e0 ) ;
break;
}
}
F_82 ( 140 ) ;
if ( F_83 ( V_2 -> V_61 ) == - V_169 )
F_46 ( & V_2 -> V_49 -> V_65 ,
L_19 ,
V_167 -> V_168 , F_77 ( V_167 ) ,
V_144 -> clock , V_144 -> V_160 ) ;
V_2 -> V_61 = NULL ;
F_79 ( & V_2 -> V_166 ) ;
}
static int F_84 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_138 * V_139 = V_2 -> V_139 ;
int V_151 = F_85 ( V_38 ) ;
if ( V_151 >= 0 )
return V_151 ;
return ! ( ( V_139 -> V_62 & V_177 ) ||
( F_51 ( V_2 , V_7 ) & V_178 ) ) ;
}
static int F_86 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_138 * V_139 = V_2 -> V_139 ;
int V_151 = F_87 ( V_38 ) ;
if ( V_151 >= 0 )
return V_151 ;
if ( ! V_139 -> V_179 )
return - V_180 ;
else
return V_139 -> V_179 ( V_2 -> V_49 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_138 * V_139 = V_2 -> V_139 ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_89 ( V_38 ) ;
if ( ! V_38 -> V_181 )
V_38 -> V_181 = V_139 -> V_182 ? : V_183 | V_184 ;
else if ( V_139 -> V_182 )
F_30 ( F_90 ( V_38 ) , L_20 ) ;
}
int F_91 ( struct V_1 * * V_2 ,
struct V_185 * V_49 ,
struct V_138 * V_139 )
{
struct V_1 * V_186 ;
struct V_37 * V_38 ;
struct V_51 * V_187 ;
int V_151 ;
T_1 V_73 = V_74 ;
V_187 = F_17 ( V_49 , V_53 , 0 ) ;
if ( ! V_187 )
return - V_88 ;
V_38 = F_92 ( sizeof( struct V_1 ) , & V_49 -> V_65 ) ;
if ( ! V_38 )
return - V_188 ;
V_139 -> V_65 = & V_49 -> V_65 ;
V_186 = F_13 ( V_38 ) ;
V_186 -> V_139 = V_139 ;
V_186 -> V_38 = V_38 ;
V_186 -> V_49 = V_49 ;
F_93 ( V_49 , V_38 ) ;
V_186 -> V_159 = V_139 -> V_159 ;
V_186 -> V_48 = V_139 -> V_48 ;
V_186 -> V_189 = F_18 ( V_187 ) >> 10 ;
V_186 -> V_190 = F_94 ( V_187 -> V_191 , F_18 ( V_187 ) ) ;
if ( ! V_186 -> V_190 ) {
V_151 = - V_188 ;
goto V_192;
}
V_38 -> V_193 = & V_194 ;
V_38 -> V_142 = V_195 | V_139 -> V_196 ;
V_38 -> V_197 = V_139 -> V_198 ;
V_38 -> V_199 = 32 ;
V_38 -> V_200 = 512 ;
V_38 -> V_201 = ( V_202 / V_38 -> V_200 ) *
V_38 -> V_199 ;
V_38 -> V_203 = V_38 -> V_200 * V_38 -> V_201 ;
V_38 -> V_204 = V_38 -> V_203 ;
F_88 ( V_186 ) ;
V_186 -> V_94 = ! ( V_139 -> V_62 & V_205 ||
V_38 -> V_142 & V_206 ||
V_38 -> V_142 & V_207 ) ;
V_186 -> V_172 = false ;
F_95 ( & V_49 -> V_65 ) ;
V_151 = F_96 ( & V_49 -> V_65 ) ;
if ( V_151 < 0 )
goto V_208;
if ( F_72 ( V_38 ) < 0 ) {
V_38 -> V_157 = V_139 -> V_209 ;
V_38 -> V_47 = V_38 -> V_157 / 512 ;
}
if ( V_186 -> V_94 )
F_97 ( & V_49 -> V_65 ) ;
F_16 ( V_186 ) ;
F_22 ( V_186 ) ;
V_186 -> V_4 = F_51 ( V_186 , V_6 ) ;
F_3 ( V_186 , V_210 ) ;
if ( ! V_186 -> V_103 )
V_73 |= V_117 ;
if ( ! V_186 -> V_102 )
V_73 |= V_118 ;
if ( ! V_186 -> V_94 )
V_73 &= ~ ( V_95 | V_96 ) ;
V_186 -> V_4 &= ~ V_73 ;
if ( V_139 -> V_62 & V_140 )
F_12 ( V_38 , 0 ) ;
F_98 ( & V_186 -> V_63 ) ;
F_99 ( & V_186 -> V_166 ) ;
F_100 ( & V_186 -> V_59 , F_23 ) ;
F_101 ( & V_186 -> V_70 , F_35 ) ;
F_102 ( V_186 , V_139 ) ;
V_151 = F_103 ( V_38 ) ;
if ( V_139 -> V_174 )
V_139 -> V_174 ( V_49 ) ;
if ( V_151 < 0 ) {
F_104 ( V_186 ) ;
return V_151 ;
}
F_105 ( & V_49 -> V_65 , 100 ) ;
if ( V_139 -> V_62 & V_205 ) {
V_151 = F_106 ( V_38 , V_139 -> V_211 ) ;
if ( V_151 < 0 ) {
F_104 ( V_186 ) ;
return V_151 ;
}
}
* V_2 = V_186 ;
return 0 ;
V_208:
F_107 ( & V_49 -> V_65 ) ;
F_108 ( V_186 -> V_190 ) ;
V_192:
F_109 ( V_38 ) ;
return V_151 ;
}
void F_104 ( struct V_1 * V_2 )
{
struct V_185 * V_49 = V_2 -> V_49 ;
struct V_138 * V_139 = V_2 -> V_139 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_139 -> V_62 & V_205 )
F_110 ( V_38 ) ;
if ( ! V_2 -> V_94 )
F_80 ( & V_49 -> V_65 ) ;
F_111 ( & V_49 -> V_65 ) ;
F_112 ( V_38 ) ;
F_113 ( & V_2 -> V_70 ) ;
F_114 ( & V_2 -> V_59 ) ;
F_115 ( V_2 ) ;
F_116 ( & V_49 -> V_65 ) ;
F_107 ( & V_49 -> V_65 ) ;
F_108 ( V_2 -> V_190 ) ;
F_109 ( V_38 ) ;
}
int F_117 ( struct V_165 * V_65 )
{
struct V_37 * V_38 = F_118 ( V_65 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
int V_151 = F_119 ( V_38 ) ;
if ( ! V_151 )
F_3 ( V_2 , V_210 ) ;
return V_151 ;
}
int F_120 ( struct V_165 * V_65 )
{
struct V_37 * V_38 = F_118 ( V_65 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_22 ( V_2 ) ;
F_121 ( V_2 , true ) ;
return F_122 ( V_38 ) ;
}
int F_123 ( struct V_165 * V_65 )
{
return 0 ;
}
int F_124 ( struct V_165 * V_65 )
{
struct V_37 * V_38 = F_118 ( V_65 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_22 ( V_2 ) ;
F_121 ( V_2 , true ) ;
return 0 ;
}

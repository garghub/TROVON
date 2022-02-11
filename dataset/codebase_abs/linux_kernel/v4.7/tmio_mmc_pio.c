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
if ( V_39 && ! V_2 -> V_40 ) {
F_14 ( F_15 ( V_38 ) ) ;
V_2 -> V_40 = true ;
V_2 -> V_41 = V_42 &
~ V_43 ;
F_16 ( V_2 , V_44 , 0x0001 ) ;
F_16 ( V_2 , V_45 , V_2 -> V_41 ) ;
} else if ( ! V_39 && V_2 -> V_40 ) {
V_2 -> V_41 = V_42 ;
F_16 ( V_2 , V_45 , V_2 -> V_41 ) ;
F_16 ( V_2 , V_44 , 0x0000 ) ;
V_2 -> V_40 = false ;
F_17 ( F_15 ( V_38 ) ) ;
F_18 ( F_15 ( V_38 ) ) ;
}
}
static void F_19 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_46 , V_47 |
F_20 ( V_2 , V_46 ) ) ;
F_21 ( V_2 -> V_48 -> V_49 & V_50 ? 1 : 10 ) ;
if ( V_2 -> V_48 -> V_49 & V_51 ) {
F_16 ( V_2 , V_52 , 0x0100 ) ;
F_21 ( 10 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_48 -> V_49 & V_51 ) {
F_16 ( V_2 , V_52 , 0x0000 ) ;
F_21 ( 10 ) ;
}
F_16 ( V_2 , V_46 , ~ V_47 &
F_20 ( V_2 , V_46 ) ) ;
F_21 ( V_2 -> V_48 -> V_49 & V_50 ? 5 : 10 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_53 )
{
T_1 V_54 = 0 , clock ;
if ( V_53 == 0 ) {
F_22 ( V_2 ) ;
return;
}
if ( V_2 -> V_55 )
clock = V_2 -> V_55 ( V_2 , V_53 ) / 512 ;
else
clock = V_2 -> V_38 -> V_56 ;
for ( V_54 = 0x80000080 ; V_53 >= ( clock << 1 ) ; V_54 >>= 1 )
clock <<= 1 ;
if ( ( V_2 -> V_48 -> V_49 & V_57 ) && ( ( V_54 >> 22 ) & 0x1 ) )
V_54 |= 0xff ;
if ( V_2 -> V_58 )
V_2 -> V_58 ( V_2 -> V_59 , ( V_54 >> 22 ) & 1 ) ;
F_16 ( V_2 , V_46 , ~ V_47 &
F_20 ( V_2 , V_46 ) ) ;
F_16 ( V_2 , V_46 , V_54 & V_60 ) ;
if ( ! ( V_2 -> V_48 -> V_49 & V_50 ) )
F_21 ( 10 ) ;
F_19 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_61 , 0x0000 ) ;
if ( V_2 -> V_48 -> V_49 & V_51 )
F_16 ( V_2 , V_62 , 0x0000 ) ;
F_21 ( 10 ) ;
F_16 ( V_2 , V_61 , 0x0001 ) ;
if ( V_2 -> V_48 -> V_49 & V_51 )
F_16 ( V_2 , V_62 , 0x0001 ) ;
F_21 ( 10 ) ;
}
static void F_25 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_26 ( V_64 , struct V_1 ,
V_65 . V_64 ) ;
struct V_66 * V_67 ;
unsigned long V_49 ;
F_27 ( & V_2 -> V_68 , V_49 ) ;
V_67 = V_2 -> V_67 ;
if ( F_28 ( V_67 )
|| F_29 ( V_2 -> V_69 +
F_30 ( V_70 ) ) ) {
F_31 ( & V_2 -> V_68 , V_49 ) ;
return;
}
F_32 ( & V_2 -> V_59 -> V_71 ,
L_3 ,
V_67 -> V_72 -> V_73 ) ;
if ( V_2 -> V_9 )
V_2 -> V_9 -> error = - V_74 ;
else if ( V_2 -> V_72 )
V_2 -> V_72 -> error = - V_74 ;
else
V_67 -> V_72 -> error = - V_74 ;
V_2 -> V_72 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_75 = false ;
F_31 ( & V_2 -> V_68 , V_49 ) ;
F_24 ( V_2 ) ;
V_2 -> V_67 = NULL ;
F_33 ( V_2 ) ;
F_34 ( V_2 -> V_38 , V_67 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_66 * V_67 ;
unsigned long V_49 ;
F_27 ( & V_2 -> V_68 , V_49 ) ;
V_67 = V_2 -> V_67 ;
if ( F_28 ( V_67 ) ) {
F_31 ( & V_2 -> V_68 , V_49 ) ;
return;
}
V_2 -> V_72 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_75 = false ;
F_36 ( & V_2 -> V_65 ) ;
V_2 -> V_67 = NULL ;
F_31 ( & V_2 -> V_68 , V_49 ) ;
if ( V_67 -> V_72 -> error || ( V_67 -> V_9 && V_67 -> V_9 -> error ) )
F_33 ( V_2 ) ;
F_34 ( V_2 -> V_38 , V_67 ) ;
}
static void F_37 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_26 ( V_64 , struct V_1 ,
V_76 ) ;
F_35 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_77 * V_72 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_78 = V_72 -> V_73 ;
T_1 V_79 = V_80 ;
if ( V_72 -> V_73 == V_81 && ! V_72 -> V_82 ) {
F_16 ( V_2 , V_83 , 0x001 ) ;
return 0 ;
}
switch ( F_39 ( V_72 ) ) {
case V_84 : V_78 |= V_85 ; break;
case V_86 : V_78 |= V_87 ; break;
case V_88 : V_78 |= V_89 ; break;
case V_90 : V_78 |= V_91 ; break;
case V_92 : V_78 |= V_93 ; break;
default:
F_9 ( L_4 , F_39 ( V_72 ) ) ;
return - V_94 ;
}
V_2 -> V_72 = V_72 ;
if ( V_9 ) {
V_78 |= V_95 ;
if ( V_9 -> V_96 > 1 ) {
F_16 ( V_2 , V_83 , 0x100 ) ;
V_78 |= V_97 ;
if ( ( V_2 -> V_48 -> V_49 & V_98 ) &&
( V_72 -> V_73 == V_99 ) )
V_78 |= V_100 ;
}
if ( V_9 -> V_49 & V_101 )
V_78 |= V_102 ;
}
if ( ! V_2 -> V_103 )
V_79 &= ~ ( V_104 | V_105 ) ;
F_1 ( V_2 , V_79 ) ;
F_2 ( V_2 , V_106 , V_72 -> V_82 ) ;
F_16 ( V_2 , V_107 , V_78 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned short * V_108 ,
unsigned int V_109 )
{
int V_110 = V_2 -> V_9 -> V_49 & V_101 ;
T_2 * V_111 ;
if ( V_110 )
F_41 ( V_2 , V_112 , V_108 , V_109 >> 1 ) ;
else
F_42 ( V_2 , V_112 , V_108 , V_109 >> 1 ) ;
if ( ! ( V_109 & 0x1 ) )
return;
V_111 = ( T_2 * ) ( V_108 + ( V_109 >> 1 ) ) ;
if ( V_110 )
* V_111 = F_20 ( V_2 , V_112 ) & 0xff ;
else
F_16 ( V_2 , V_112 , * V_111 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_113 ;
unsigned short * V_108 ;
unsigned int V_109 ;
unsigned long V_49 ;
if ( ( V_2 -> V_114 || V_2 -> V_115 ) && ! V_2 -> V_75 ) {
F_44 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_113 = F_45 ( V_2 -> V_11 , & V_49 ) ;
V_108 = ( unsigned short * ) ( V_113 + V_2 -> V_14 ) ;
V_109 = V_2 -> V_11 -> V_116 - V_2 -> V_14 ;
if ( V_109 > V_9 -> V_117 )
V_109 = V_9 -> V_117 ;
F_9 ( L_7 ,
V_109 , V_2 -> V_14 , V_9 -> V_49 ) ;
F_40 ( V_2 , V_108 , V_109 ) ;
V_2 -> V_14 += V_109 ;
F_46 ( V_2 -> V_11 , & V_49 , V_113 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_116 )
F_6 ( V_2 ) ;
return;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_118 ) {
unsigned long V_49 ;
void * V_119 = F_45 ( V_2 -> V_13 , & V_49 ) ;
memcpy ( V_119 , V_2 -> V_120 , V_2 -> V_118 . V_116 ) ;
F_46 ( V_2 -> V_13 , & V_49 , V_119 ) ;
}
}
void F_48 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_77 * V_121 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_32 ( & V_2 -> V_59 -> V_71 , L_8 ) ;
return;
}
V_121 = V_9 -> V_121 ;
if ( ! V_9 -> error )
V_9 -> V_122 = V_9 -> V_96 * V_9 -> V_117 ;
else
V_9 -> V_122 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_49 & V_101 ) {
if ( V_2 -> V_115 && ! V_2 -> V_75 )
F_47 ( V_2 ) ;
F_49 ( & V_2 -> V_59 -> V_71 , L_10 ,
V_2 -> V_67 ) ;
} else {
F_49 ( & V_2 -> V_59 -> V_71 , L_11 ,
V_2 -> V_67 ) ;
}
if ( V_121 ) {
if ( V_121 -> V_73 == V_81 && ! V_121 -> V_82 )
F_16 ( V_2 , V_83 , 0x000 ) ;
else
F_50 () ;
}
F_51 ( & V_2 -> V_76 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_53 ( & V_2 -> V_68 ) ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 )
goto V_123;
if ( V_2 -> V_114 && ( V_9 -> V_49 & V_124 ) && ! V_2 -> V_75 ) {
T_1 V_15 = F_54 ( V_2 , V_7 ) ;
bool V_76 = false ;
if ( V_2 -> V_48 -> V_49 & V_125 ) {
if ( V_15 & V_126 )
V_76 = true ;
} else {
if ( ! ( V_15 & V_127 ) )
V_76 = true ;
}
if ( V_76 ) {
F_3 ( V_2 , V_128 ) ;
F_55 ( & V_2 -> V_129 ) ;
}
} else if ( V_2 -> V_115 && ( V_9 -> V_49 & V_101 ) && ! V_2 -> V_75 ) {
F_3 ( V_2 , V_128 ) ;
F_55 ( & V_2 -> V_129 ) ;
} else {
F_48 ( V_2 ) ;
F_3 ( V_2 , V_130 | V_131 ) ;
}
V_123:
F_56 ( & V_2 -> V_68 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_132 )
{
struct V_77 * V_72 = V_2 -> V_72 ;
int V_3 , V_133 ;
F_53 ( & V_2 -> V_68 ) ;
if ( ! V_2 -> V_72 ) {
F_9 ( L_12 ) ;
goto V_123;
}
V_2 -> V_72 = NULL ;
for ( V_3 = 3 , V_133 = V_134 ; V_3 >= 0 ; V_3 -- , V_133 += 4 )
V_72 -> V_135 [ V_3 ] = F_54 ( V_2 , V_133 ) ;
if ( V_72 -> V_49 & V_136 ) {
V_72 -> V_135 [ 0 ] = ( V_72 -> V_135 [ 0 ] << 8 ) | ( V_72 -> V_135 [ 1 ] >> 24 ) ;
V_72 -> V_135 [ 1 ] = ( V_72 -> V_135 [ 1 ] << 8 ) | ( V_72 -> V_135 [ 2 ] >> 24 ) ;
V_72 -> V_135 [ 2 ] = ( V_72 -> V_135 [ 2 ] << 8 ) | ( V_72 -> V_135 [ 3 ] >> 24 ) ;
V_72 -> V_135 [ 3 ] <<= 8 ;
} else if ( V_72 -> V_49 & V_92 ) {
V_72 -> V_135 [ 0 ] = V_72 -> V_135 [ 3 ] ;
}
if ( V_132 & V_137 )
V_72 -> error = - V_74 ;
else if ( V_132 & V_138 && V_72 -> V_49 & V_139 )
V_72 -> error = - V_140 ;
if ( V_2 -> V_9 && ! V_72 -> error ) {
if ( V_2 -> V_9 -> V_49 & V_101 ) {
if ( V_2 -> V_75 || ! V_2 -> V_115 )
F_1 ( V_2 , V_130 ) ;
else
F_55 ( & V_2 -> V_141 ) ;
} else {
if ( V_2 -> V_75 || ! V_2 -> V_114 )
F_1 ( V_2 , V_131 ) ;
else
F_55 ( & V_2 -> V_141 ) ;
}
} else {
F_51 ( & V_2 -> V_76 ) ;
}
V_123:
F_56 ( & V_2 -> V_68 ) ;
}
static bool F_58 ( struct V_1 * V_2 ,
int V_142 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_142 & ( V_105 | V_104 ) ) {
F_4 ( V_2 , V_105 |
V_104 ) ;
if ( ( ( ( V_142 & V_104 ) && V_38 -> V_143 ) ||
( ( V_142 & V_105 ) && ! V_38 -> V_143 ) ) &&
! F_59 ( & V_38 -> V_144 . V_64 ) )
F_60 ( V_2 -> V_38 , F_30 ( 100 ) ) ;
return true ;
}
return false ;
}
static bool F_61 ( struct V_1 * V_2 ,
int V_142 , int V_15 )
{
if ( V_142 & ( V_145 | V_137 ) ) {
F_4 ( V_2 ,
V_145 |
V_137 ) ;
F_57 ( V_2 , V_15 ) ;
return true ;
}
if ( V_142 & ( V_146 | V_147 ) ) {
F_4 ( V_2 , V_146 | V_147 ) ;
F_43 ( V_2 ) ;
return true ;
}
if ( V_142 & V_128 ) {
F_4 ( V_2 , V_128 ) ;
F_52 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_62 ( int V_148 , void * V_149 )
{
struct V_1 * V_2 = V_149 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_150 * V_48 = V_2 -> V_48 ;
unsigned int V_142 , V_15 ;
unsigned int V_151 ;
if ( ! ( V_48 -> V_49 & V_152 ) )
return;
V_15 = F_20 ( V_2 , V_153 ) ;
V_142 = V_15 & V_42 & ~ V_2 -> V_4 ;
V_151 = V_15 & ~ V_42 ;
if ( V_48 -> V_49 & V_154 )
V_151 |= 6 ;
F_16 ( V_2 , V_153 , V_151 ) ;
if ( V_38 -> V_155 & V_156 && V_142 & V_43 )
F_63 ( V_38 ) ;
}
T_3 F_64 ( int V_148 , void * V_149 )
{
struct V_1 * V_2 = V_149 ;
unsigned int V_142 , V_15 ;
V_15 = F_54 ( V_2 , V_7 ) ;
V_142 = V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( V_15 ) ;
F_8 ( V_142 ) ;
F_2 ( V_2 , V_7 , V_5 ) ;
if ( F_58 ( V_2 , V_142 , V_15 ) )
return V_157 ;
if ( F_61 ( V_2 , V_142 , V_15 ) )
return V_157 ;
F_62 ( V_148 , V_149 ) ;
return V_157 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_150 * V_48 = V_2 -> V_48 ;
F_9 ( L_13 ,
V_9 -> V_117 , V_9 -> V_96 ) ;
if ( V_2 -> V_38 -> V_158 . V_159 == V_160 ) {
int V_161 = V_48 -> V_49 & V_162 ;
if ( V_9 -> V_117 < 2 || ( V_9 -> V_117 < 4 && ! V_161 ) ) {
F_44 ( L_14 ,
F_66 ( V_2 -> V_38 ) , V_9 -> V_117 ) ;
return - V_94 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_16 ( V_2 , V_163 , V_9 -> V_117 ) ;
F_16 ( V_2 , V_164 , V_9 -> V_96 ) ;
F_67 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_68 ( struct V_37 * V_38 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_49 ;
int V_165 ;
F_27 ( & V_2 -> V_68 , V_49 ) ;
if ( V_2 -> V_67 ) {
F_9 ( L_15 ) ;
if ( F_69 ( V_2 -> V_67 ) ) {
F_31 ( & V_2 -> V_68 , V_49 ) ;
V_67 -> V_72 -> error = - V_166 ;
F_34 ( V_38 , V_67 ) ;
return;
}
}
V_2 -> V_69 = V_167 ;
F_70 () ;
V_2 -> V_67 = V_67 ;
F_31 ( & V_2 -> V_68 , V_49 ) ;
if ( V_67 -> V_9 ) {
V_165 = F_65 ( V_2 , V_67 -> V_9 ) ;
if ( V_165 )
goto V_168;
}
V_165 = F_38 ( V_2 , V_67 -> V_72 ) ;
if ( ! V_165 ) {
F_71 ( & V_2 -> V_65 ,
F_30 ( V_70 ) ) ;
return;
}
V_168:
V_2 -> V_75 = false ;
V_2 -> V_67 = NULL ;
V_67 -> V_72 -> error = V_165 ;
F_34 ( V_38 , V_67 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_169 )
return - V_170 ;
return V_2 -> V_169 ( V_2 ) ;
}
static void F_73 ( struct V_1 * V_2 , unsigned short V_171 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_165 = 0 ;
if ( V_2 -> V_172 )
V_2 -> V_172 ( V_2 -> V_59 , 1 ) ;
if ( ! F_69 ( V_38 -> V_173 . V_174 ) ) {
V_165 = F_74 ( V_38 , V_38 -> V_173 . V_174 , V_171 ) ;
F_75 ( 200 ) ;
}
if ( ! F_69 ( V_38 -> V_173 . V_175 ) && ! V_165 ) {
V_165 = F_76 ( V_38 -> V_173 . V_175 ) ;
F_75 ( 200 ) ;
}
if ( V_165 < 0 )
F_49 ( & V_2 -> V_59 -> V_71 , L_16 ,
V_165 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! F_69 ( V_38 -> V_173 . V_175 ) )
F_78 ( V_38 -> V_173 . V_175 ) ;
if ( ! F_69 ( V_38 -> V_173 . V_174 ) )
F_74 ( V_38 , V_38 -> V_173 . V_174 , 0 ) ;
if ( V_2 -> V_172 )
V_2 -> V_172 ( V_2 -> V_59 , 0 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
unsigned char V_159 )
{
switch ( V_159 ) {
case V_176 :
F_16 ( V_2 , V_177 , 0x80e0 ) ;
break;
case V_160 :
F_16 ( V_2 , V_177 , 0x00e0 ) ;
break;
}
}
static void F_80 ( struct V_37 * V_38 , struct V_178 * V_158 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_179 * V_71 = & V_2 -> V_59 -> V_71 ;
unsigned long V_49 ;
F_81 ( & V_2 -> V_180 ) ;
F_27 ( & V_2 -> V_68 , V_49 ) ;
if ( V_2 -> V_67 ) {
if ( F_69 ( V_2 -> V_67 ) ) {
F_49 ( V_71 ,
L_17 ,
V_181 -> V_182 , F_82 ( V_181 ) ,
V_158 -> clock , V_158 -> V_183 ) ;
V_2 -> V_67 = F_83 ( - V_184 ) ;
} else {
F_49 ( V_71 ,
L_18 ,
V_181 -> V_182 , F_82 ( V_181 ) ,
V_2 -> V_67 -> V_72 -> V_73 , V_2 -> V_69 , V_167 ) ;
}
F_31 ( & V_2 -> V_68 , V_49 ) ;
F_84 ( & V_2 -> V_180 ) ;
return;
}
V_2 -> V_67 = F_83 ( - V_185 ) ;
F_31 ( & V_2 -> V_68 , V_49 ) ;
switch ( V_158 -> V_183 ) {
case V_186 :
F_77 ( V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_187 :
F_73 ( V_2 , V_158 -> V_171 ) ;
F_23 ( V_2 , V_158 -> clock ) ;
F_79 ( V_2 , V_158 -> V_159 ) ;
break;
case V_188 :
F_23 ( V_2 , V_158 -> clock ) ;
F_79 ( V_2 , V_158 -> V_159 ) ;
break;
}
F_75 ( 140 ) ;
if ( F_85 ( V_2 -> V_67 ) == - V_184 )
F_49 ( & V_2 -> V_59 -> V_71 ,
L_19 ,
V_181 -> V_182 , F_82 ( V_181 ) ,
V_158 -> clock , V_158 -> V_183 ) ;
V_2 -> V_67 = NULL ;
V_2 -> V_189 = V_158 -> clock ;
F_84 ( & V_2 -> V_180 ) ;
}
static int F_86 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_150 * V_48 = V_2 -> V_48 ;
int V_165 = F_87 ( V_38 ) ;
if ( V_165 >= 0 )
return V_165 ;
V_165 = ! ( ( V_48 -> V_49 & V_190 ) ||
( F_54 ( V_2 , V_7 ) & V_191 ) ) ;
return V_165 ;
}
static int F_88 ( struct V_192 * V_143 ,
unsigned int V_193 , int V_194 )
{
struct V_1 * V_2 = F_13 ( V_143 -> V_2 ) ;
if ( V_2 -> V_195 )
return V_2 -> V_195 ( V_143 , V_193 , V_194 ) ;
return V_194 ;
}
static int F_89 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
return ! ( F_54 ( V_2 , V_7 ) & V_196 ) ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_150 * V_48 = V_2 -> V_48 ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_91 ( V_38 ) ;
if ( ! V_38 -> V_197 )
V_38 -> V_197 = V_48 -> V_198 ;
if ( ! V_38 -> V_197 )
return - V_199 ;
return 0 ;
}
static void F_92 ( struct V_200 * V_59 ,
struct V_150 * V_48 )
{
const struct V_201 * V_202 = V_59 -> V_71 . V_203 ;
if ( ! V_202 )
return;
if ( F_93 ( V_202 , L_20 , NULL ) )
V_48 -> V_49 |= V_190 ;
}
struct V_1 *
F_94 ( struct V_200 * V_59 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
V_38 = F_95 ( sizeof( struct V_1 ) , & V_59 -> V_71 ) ;
if ( ! V_38 )
return NULL ;
V_2 = F_13 ( V_38 ) ;
V_2 -> V_38 = V_38 ;
V_2 -> V_59 = V_59 ;
return V_2 ;
}
void F_96 ( struct V_1 * V_2 )
{
F_97 ( V_2 -> V_38 ) ;
}
int F_98 ( struct V_1 * V_204 ,
struct V_150 * V_48 )
{
struct V_200 * V_59 = V_204 -> V_59 ;
struct V_37 * V_38 = V_204 -> V_38 ;
struct V_205 * V_206 ;
int V_165 ;
T_1 V_79 = V_80 ;
F_92 ( V_59 , V_48 ) ;
if ( ! ( V_48 -> V_49 & V_125 ) )
V_204 -> V_207 = NULL ;
V_206 = F_99 ( V_59 , V_208 , 0 ) ;
if ( ! V_206 )
return - V_94 ;
V_165 = F_100 ( V_38 ) ;
if ( V_165 < 0 )
goto V_209;
V_204 -> V_48 = V_48 ;
F_101 ( V_59 , V_38 ) ;
V_204 -> V_172 = V_48 -> V_172 ;
V_204 -> V_58 = V_48 -> V_58 ;
V_165 = F_90 ( V_204 ) ;
if ( V_165 < 0 )
goto V_209;
V_204 -> V_210 = F_102 ( & V_59 -> V_71 ,
V_206 -> V_211 , F_103 ( V_206 ) ) ;
if ( ! V_204 -> V_210 ) {
V_165 = - V_212 ;
goto V_209;
}
V_213 . V_214 = V_204 -> V_214 ;
V_38 -> V_215 = & V_213 ;
V_38 -> V_155 |= V_216 | V_48 -> V_217 ;
V_38 -> V_218 |= V_48 -> V_219 ;
V_38 -> V_220 = 32 ;
V_38 -> V_221 = 512 ;
V_38 -> V_222 = ( V_223 / V_38 -> V_221 ) *
V_38 -> V_220 ;
V_38 -> V_224 = V_38 -> V_221 * V_38 -> V_222 ;
V_38 -> V_225 = V_38 -> V_224 ;
V_204 -> V_103 = ! ( V_48 -> V_49 & V_226 ||
V_38 -> V_155 & V_227 ||
V_38 -> V_155 & V_228 ||
V_38 -> V_229 . V_230 >= 0 ) ;
if ( F_72 ( V_204 ) < 0 ) {
V_38 -> V_231 = V_48 -> V_232 ;
V_38 -> V_56 = V_38 -> V_231 / 512 ;
}
if ( V_38 -> V_56 == 0 ) {
V_165 = - V_94 ;
goto V_209;
}
if ( V_204 -> V_103 )
F_104 ( & V_59 -> V_71 ) ;
F_22 ( V_204 ) ;
F_24 ( V_204 ) ;
V_204 -> V_4 = F_54 ( V_204 , V_6 ) ;
F_3 ( V_204 , V_233 ) ;
if ( ! V_204 -> V_115 )
V_79 |= V_130 ;
if ( ! V_204 -> V_114 )
V_79 |= V_131 ;
if ( ! V_204 -> V_103 )
V_79 &= ~ ( V_104 | V_105 ) ;
V_204 -> V_4 &= ~ V_79 ;
V_204 -> V_40 = false ;
if ( V_48 -> V_49 & V_152 ) {
V_204 -> V_41 = V_42 ;
F_16 ( V_204 , V_45 , V_204 -> V_41 ) ;
F_16 ( V_204 , V_44 , 0x0000 ) ;
}
F_105 ( & V_204 -> V_68 ) ;
F_106 ( & V_204 -> V_180 ) ;
F_107 ( & V_204 -> V_65 , F_25 ) ;
F_108 ( & V_204 -> V_76 , F_37 ) ;
F_109 ( V_204 , V_48 ) ;
F_110 ( & V_59 -> V_71 ) ;
F_111 ( & V_59 -> V_71 , 50 ) ;
F_112 ( & V_59 -> V_71 ) ;
F_113 ( & V_59 -> V_71 ) ;
V_165 = F_114 ( V_38 ) ;
if ( V_165 < 0 ) {
F_115 ( V_204 ) ;
return V_165 ;
}
F_116 ( & V_59 -> V_71 , 100 ) ;
if ( V_48 -> V_49 & V_226 ) {
V_165 = F_117 ( V_38 , V_48 -> V_234 , 0 ) ;
if ( V_165 < 0 ) {
F_115 ( V_204 ) ;
return V_165 ;
}
F_118 ( V_38 ) ;
}
return 0 ;
V_209:
return V_165 ;
}
void F_115 ( struct V_1 * V_2 )
{
struct V_200 * V_59 = V_2 -> V_59 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! V_2 -> V_103 )
F_14 ( & V_59 -> V_71 ) ;
F_119 ( & V_59 -> V_71 ) ;
F_120 ( V_38 ) ;
F_121 ( & V_2 -> V_76 ) ;
F_122 ( & V_2 -> V_65 ) ;
F_123 ( V_2 ) ;
F_124 ( & V_59 -> V_71 ) ;
F_125 ( & V_59 -> V_71 ) ;
}
int F_126 ( struct V_179 * V_71 )
{
struct V_37 * V_38 = F_127 ( V_71 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_3 ( V_2 , V_233 ) ;
if ( V_2 -> V_189 )
F_22 ( V_2 ) ;
if ( V_2 -> V_235 )
V_2 -> V_235 ( V_2 ) ;
return 0 ;
}
int F_128 ( struct V_179 * V_71 )
{
struct V_37 * V_38 = F_127 ( V_71 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_24 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( V_2 -> V_189 )
F_23 ( V_2 , V_2 -> V_189 ) ;
F_129 ( V_2 , true ) ;
return 0 ;
}

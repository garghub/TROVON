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
case V_86 :
case V_87 :
V_78 |= V_88 ; break;
case V_89 : V_78 |= V_90 ; break;
case V_91 : V_78 |= V_92 ; break;
case V_93 : V_78 |= V_94 ; break;
default:
F_9 ( L_4 , F_39 ( V_72 ) ) ;
return - V_95 ;
}
V_2 -> V_72 = V_72 ;
if ( V_9 ) {
V_78 |= V_96 ;
if ( V_9 -> V_97 > 1 ) {
F_16 ( V_2 , V_83 , 0x100 ) ;
V_78 |= V_98 ;
if ( ( V_2 -> V_48 -> V_49 & V_99 ) &&
( V_72 -> V_73 == V_100 ) )
V_78 |= V_101 ;
}
if ( V_9 -> V_49 & V_102 )
V_78 |= V_103 ;
}
if ( ! V_2 -> V_104 )
V_79 &= ~ ( V_105 | V_106 ) ;
F_1 ( V_2 , V_79 ) ;
F_2 ( V_2 , V_107 , V_72 -> V_82 ) ;
F_16 ( V_2 , V_108 , V_78 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned short * V_109 ,
unsigned int V_110 )
{
int V_111 = V_2 -> V_9 -> V_49 & V_102 ;
T_2 * V_112 ;
if ( V_111 )
F_41 ( V_2 , V_113 , V_109 , V_110 >> 1 ) ;
else
F_42 ( V_2 , V_113 , V_109 , V_110 >> 1 ) ;
if ( ! ( V_110 & 0x1 ) )
return;
V_112 = ( T_2 * ) ( V_109 + ( V_110 >> 1 ) ) ;
if ( V_111 )
* V_112 = F_20 ( V_2 , V_113 ) & 0xff ;
else
F_16 ( V_2 , V_113 , * V_112 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_114 ;
unsigned short * V_109 ;
unsigned int V_110 ;
unsigned long V_49 ;
if ( ( V_2 -> V_115 || V_2 -> V_116 ) && ! V_2 -> V_75 ) {
F_44 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_114 = F_45 ( V_2 -> V_11 , & V_49 ) ;
V_109 = ( unsigned short * ) ( V_114 + V_2 -> V_14 ) ;
V_110 = V_2 -> V_11 -> V_117 - V_2 -> V_14 ;
if ( V_110 > V_9 -> V_118 )
V_110 = V_9 -> V_118 ;
F_9 ( L_7 ,
V_110 , V_2 -> V_14 , V_9 -> V_49 ) ;
F_40 ( V_2 , V_109 , V_110 ) ;
V_2 -> V_14 += V_110 ;
F_46 ( V_2 -> V_11 , & V_49 , V_114 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_117 )
F_6 ( V_2 ) ;
return;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_119 ) {
unsigned long V_49 ;
void * V_120 = F_45 ( V_2 -> V_13 , & V_49 ) ;
memcpy ( V_120 , V_2 -> V_121 , V_2 -> V_119 . V_117 ) ;
F_46 ( V_2 -> V_13 , & V_49 , V_120 ) ;
}
}
void F_48 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_77 * V_122 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_32 ( & V_2 -> V_59 -> V_71 , L_8 ) ;
return;
}
V_122 = V_9 -> V_122 ;
if ( ! V_9 -> error )
V_9 -> V_123 = V_9 -> V_97 * V_9 -> V_118 ;
else
V_9 -> V_123 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_49 & V_102 ) {
if ( V_2 -> V_116 && ! V_2 -> V_75 )
F_47 ( V_2 ) ;
F_49 ( & V_2 -> V_59 -> V_71 , L_10 ,
V_2 -> V_67 ) ;
} else {
F_49 ( & V_2 -> V_59 -> V_71 , L_11 ,
V_2 -> V_67 ) ;
}
if ( V_122 ) {
if ( V_122 -> V_73 == V_81 && ! V_122 -> V_82 )
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
goto V_124;
if ( V_2 -> V_115 && ( V_9 -> V_49 & V_125 ) && ! V_2 -> V_75 ) {
T_1 V_15 = F_54 ( V_2 , V_7 ) ;
bool V_76 = false ;
if ( V_2 -> V_48 -> V_49 & V_126 ) {
if ( V_15 & V_127 )
V_76 = true ;
} else {
if ( ! ( V_15 & V_128 ) )
V_76 = true ;
}
if ( V_76 ) {
F_3 ( V_2 , V_129 ) ;
F_55 ( & V_2 -> V_130 ) ;
}
} else if ( V_2 -> V_116 && ( V_9 -> V_49 & V_102 ) && ! V_2 -> V_75 ) {
F_3 ( V_2 , V_129 ) ;
F_55 ( & V_2 -> V_130 ) ;
} else {
F_48 ( V_2 ) ;
F_3 ( V_2 , V_131 | V_132 ) ;
}
V_124:
F_56 ( & V_2 -> V_68 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_133 )
{
struct V_77 * V_72 = V_2 -> V_72 ;
int V_3 , V_134 ;
F_53 ( & V_2 -> V_68 ) ;
if ( ! V_2 -> V_72 ) {
F_9 ( L_12 ) ;
goto V_124;
}
V_2 -> V_72 = NULL ;
for ( V_3 = 3 , V_134 = V_135 ; V_3 >= 0 ; V_3 -- , V_134 += 4 )
V_72 -> V_136 [ V_3 ] = F_54 ( V_2 , V_134 ) ;
if ( V_72 -> V_49 & V_137 ) {
V_72 -> V_136 [ 0 ] = ( V_72 -> V_136 [ 0 ] << 8 ) | ( V_72 -> V_136 [ 1 ] >> 24 ) ;
V_72 -> V_136 [ 1 ] = ( V_72 -> V_136 [ 1 ] << 8 ) | ( V_72 -> V_136 [ 2 ] >> 24 ) ;
V_72 -> V_136 [ 2 ] = ( V_72 -> V_136 [ 2 ] << 8 ) | ( V_72 -> V_136 [ 3 ] >> 24 ) ;
V_72 -> V_136 [ 3 ] <<= 8 ;
} else if ( V_72 -> V_49 & V_93 ) {
V_72 -> V_136 [ 0 ] = V_72 -> V_136 [ 3 ] ;
}
if ( V_133 & V_138 )
V_72 -> error = - V_74 ;
else if ( V_133 & V_139 && V_72 -> V_49 & V_140 )
V_72 -> error = - V_141 ;
if ( V_2 -> V_9 && ! V_72 -> error ) {
if ( V_2 -> V_9 -> V_49 & V_102 ) {
if ( V_2 -> V_75 || ! V_2 -> V_116 )
F_1 ( V_2 , V_131 ) ;
else
F_55 ( & V_2 -> V_142 ) ;
} else {
if ( V_2 -> V_75 || ! V_2 -> V_115 )
F_1 ( V_2 , V_132 ) ;
else
F_55 ( & V_2 -> V_142 ) ;
}
} else {
F_51 ( & V_2 -> V_76 ) ;
}
V_124:
F_56 ( & V_2 -> V_68 ) ;
}
static bool F_58 ( struct V_1 * V_2 ,
int V_143 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_143 & ( V_106 | V_105 ) ) {
F_4 ( V_2 , V_106 |
V_105 ) ;
if ( ( ( ( V_143 & V_105 ) && V_38 -> V_144 ) ||
( ( V_143 & V_106 ) && ! V_38 -> V_144 ) ) &&
! F_59 ( & V_38 -> V_145 . V_64 ) )
F_60 ( V_2 -> V_38 , F_30 ( 100 ) ) ;
return true ;
}
return false ;
}
static bool F_61 ( struct V_1 * V_2 ,
int V_143 , int V_15 )
{
if ( V_143 & ( V_146 | V_138 ) ) {
F_4 ( V_2 ,
V_146 |
V_138 ) ;
F_57 ( V_2 , V_15 ) ;
return true ;
}
if ( V_143 & ( V_147 | V_148 ) ) {
F_4 ( V_2 , V_147 | V_148 ) ;
F_43 ( V_2 ) ;
return true ;
}
if ( V_143 & V_129 ) {
F_4 ( V_2 , V_129 ) ;
F_52 ( V_2 ) ;
return true ;
}
return false ;
}
static void F_62 ( int V_149 , void * V_150 )
{
struct V_1 * V_2 = V_150 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_151 * V_48 = V_2 -> V_48 ;
unsigned int V_143 , V_15 ;
unsigned int V_152 ;
if ( ! ( V_48 -> V_49 & V_153 ) )
return;
V_15 = F_20 ( V_2 , V_154 ) ;
V_143 = V_15 & V_42 & ~ V_2 -> V_4 ;
V_152 = V_15 & ~ V_42 ;
if ( V_48 -> V_49 & V_155 )
V_152 |= 6 ;
F_16 ( V_2 , V_154 , V_152 ) ;
if ( V_38 -> V_156 & V_157 && V_143 & V_43 )
F_63 ( V_38 ) ;
}
T_3 F_64 ( int V_149 , void * V_150 )
{
struct V_1 * V_2 = V_150 ;
unsigned int V_143 , V_15 ;
V_15 = F_54 ( V_2 , V_7 ) ;
V_143 = V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( V_15 ) ;
F_8 ( V_143 ) ;
F_2 ( V_2 , V_7 , V_5 ) ;
if ( F_58 ( V_2 , V_143 , V_15 ) )
return V_158 ;
if ( F_61 ( V_2 , V_143 , V_15 ) )
return V_158 ;
F_62 ( V_149 , V_150 ) ;
return V_158 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_151 * V_48 = V_2 -> V_48 ;
F_9 ( L_13 ,
V_9 -> V_118 , V_9 -> V_97 ) ;
if ( V_2 -> V_38 -> V_159 . V_160 == V_161 ||
V_2 -> V_38 -> V_159 . V_160 == V_162 ) {
int V_163 = V_48 -> V_49 & V_164 ;
if ( V_9 -> V_118 < 2 || ( V_9 -> V_118 < 4 && ! V_163 ) ) {
F_44 ( L_14 ,
F_66 ( V_2 -> V_38 ) , V_9 -> V_118 ) ;
return - V_95 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_16 ( V_2 , V_165 , V_9 -> V_118 ) ;
F_16 ( V_2 , V_166 , V_9 -> V_97 ) ;
F_67 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_68 ( struct V_37 * V_38 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_49 ;
int V_167 ;
F_27 ( & V_2 -> V_68 , V_49 ) ;
if ( V_2 -> V_67 ) {
F_9 ( L_15 ) ;
if ( F_69 ( V_2 -> V_67 ) ) {
F_31 ( & V_2 -> V_68 , V_49 ) ;
V_67 -> V_72 -> error = - V_168 ;
F_34 ( V_38 , V_67 ) ;
return;
}
}
V_2 -> V_69 = V_169 ;
F_70 () ;
V_2 -> V_67 = V_67 ;
F_31 ( & V_2 -> V_68 , V_49 ) ;
if ( V_67 -> V_9 ) {
V_167 = F_65 ( V_2 , V_67 -> V_9 ) ;
if ( V_167 )
goto V_170;
}
V_167 = F_38 ( V_2 , V_67 -> V_72 ) ;
if ( ! V_167 ) {
F_71 ( & V_2 -> V_65 ,
F_30 ( V_70 ) ) ;
return;
}
V_170:
V_2 -> V_75 = false ;
V_2 -> V_67 = NULL ;
V_67 -> V_72 -> error = V_167 ;
F_34 ( V_38 , V_67 ) ;
}
static int F_72 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_171 )
return - V_172 ;
return V_2 -> V_171 ( V_2 ) ;
}
static void F_73 ( struct V_1 * V_2 , unsigned short V_173 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_167 = 0 ;
if ( V_2 -> V_174 )
V_2 -> V_174 ( V_2 -> V_59 , 1 ) ;
if ( ! F_69 ( V_38 -> V_175 . V_176 ) ) {
V_167 = F_74 ( V_38 , V_38 -> V_175 . V_176 , V_173 ) ;
F_75 ( 200 ) ;
}
if ( ! F_69 ( V_38 -> V_175 . V_177 ) && ! V_167 ) {
V_167 = F_76 ( V_38 -> V_175 . V_177 ) ;
F_75 ( 200 ) ;
}
if ( V_167 < 0 )
F_49 ( & V_2 -> V_59 -> V_71 , L_16 ,
V_167 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! F_69 ( V_38 -> V_175 . V_177 ) )
F_78 ( V_38 -> V_175 . V_177 ) ;
if ( ! F_69 ( V_38 -> V_175 . V_176 ) )
F_74 ( V_38 , V_38 -> V_175 . V_176 , 0 ) ;
if ( V_2 -> V_174 )
V_2 -> V_174 ( V_2 -> V_59 , 0 ) ;
}
static void F_79 ( struct V_1 * V_2 ,
unsigned char V_160 )
{
T_4 V_178 = F_20 ( V_2 , V_179 )
& ~ ( V_180 | V_181 ) ;
if ( V_160 == V_182 )
V_178 |= V_180 ;
else if ( V_160 == V_162 )
V_178 |= V_181 ;
F_16 ( V_2 , V_179 , V_178 ) ;
}
static void F_80 ( struct V_37 * V_38 , struct V_183 * V_159 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_184 * V_71 = & V_2 -> V_59 -> V_71 ;
unsigned long V_49 ;
F_81 ( & V_2 -> V_185 ) ;
F_27 ( & V_2 -> V_68 , V_49 ) ;
if ( V_2 -> V_67 ) {
if ( F_69 ( V_2 -> V_67 ) ) {
F_49 ( V_71 ,
L_17 ,
V_186 -> V_187 , F_82 ( V_186 ) ,
V_159 -> clock , V_159 -> V_188 ) ;
V_2 -> V_67 = F_83 ( - V_189 ) ;
} else {
F_49 ( V_71 ,
L_18 ,
V_186 -> V_187 , F_82 ( V_186 ) ,
V_2 -> V_67 -> V_72 -> V_73 , V_2 -> V_69 , V_169 ) ;
}
F_31 ( & V_2 -> V_68 , V_49 ) ;
F_84 ( & V_2 -> V_185 ) ;
return;
}
V_2 -> V_67 = F_83 ( - V_190 ) ;
F_31 ( & V_2 -> V_68 , V_49 ) ;
switch ( V_159 -> V_188 ) {
case V_191 :
F_77 ( V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_192 :
F_73 ( V_2 , V_159 -> V_173 ) ;
F_23 ( V_2 , V_159 -> clock ) ;
F_79 ( V_2 , V_159 -> V_160 ) ;
break;
case V_193 :
F_23 ( V_2 , V_159 -> clock ) ;
F_79 ( V_2 , V_159 -> V_160 ) ;
break;
}
F_75 ( 140 ) ;
if ( F_85 ( V_2 -> V_67 ) == - V_189 )
F_49 ( & V_2 -> V_59 -> V_71 ,
L_19 ,
V_186 -> V_187 , F_82 ( V_186 ) ,
V_159 -> clock , V_159 -> V_188 ) ;
V_2 -> V_67 = NULL ;
V_2 -> V_194 = V_159 -> clock ;
F_84 ( & V_2 -> V_185 ) ;
}
static int F_86 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_151 * V_48 = V_2 -> V_48 ;
int V_167 = F_87 ( V_38 ) ;
if ( V_167 >= 0 )
return V_167 ;
V_167 = ! ( ( V_48 -> V_49 & V_195 ) ||
( F_54 ( V_2 , V_7 ) & V_196 ) ) ;
return V_167 ;
}
static int F_88 ( struct V_197 * V_144 ,
unsigned int V_198 , int V_199 )
{
struct V_1 * V_2 = F_13 ( V_144 -> V_2 ) ;
if ( V_2 -> V_200 )
return V_2 -> V_200 ( V_144 , V_198 , V_199 ) ;
return V_199 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_151 * V_48 = V_2 -> V_48 ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_90 ( V_38 ) ;
if ( ! V_38 -> V_201 )
V_38 -> V_201 = V_48 -> V_202 ;
if ( ! V_38 -> V_201 )
return - V_203 ;
return 0 ;
}
static void F_91 ( struct V_204 * V_59 ,
struct V_151 * V_48 )
{
const struct V_205 * V_206 = V_59 -> V_71 . V_207 ;
if ( ! V_206 )
return;
if ( F_92 ( V_206 , L_20 , NULL ) )
V_48 -> V_49 |= V_195 ;
}
struct V_1 *
F_93 ( struct V_204 * V_59 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
V_38 = F_94 ( sizeof( struct V_1 ) , & V_59 -> V_71 ) ;
if ( ! V_38 )
return NULL ;
V_2 = F_13 ( V_38 ) ;
V_2 -> V_38 = V_38 ;
V_2 -> V_59 = V_59 ;
return V_2 ;
}
void F_95 ( struct V_1 * V_2 )
{
F_96 ( V_2 -> V_38 ) ;
}
int F_97 ( struct V_1 * V_208 ,
struct V_151 * V_48 )
{
struct V_204 * V_59 = V_208 -> V_59 ;
struct V_37 * V_38 = V_208 -> V_38 ;
struct V_209 * V_210 ;
int V_167 ;
T_1 V_79 = V_80 ;
F_91 ( V_59 , V_48 ) ;
if ( ! ( V_48 -> V_49 & V_126 ) )
V_208 -> V_211 = NULL ;
V_210 = F_98 ( V_59 , V_212 , 0 ) ;
if ( ! V_210 )
return - V_95 ;
V_167 = F_99 ( V_38 ) ;
if ( V_167 < 0 )
goto V_213;
V_208 -> V_48 = V_48 ;
F_100 ( V_59 , V_38 ) ;
V_208 -> V_174 = V_48 -> V_174 ;
V_208 -> V_58 = V_48 -> V_58 ;
V_167 = F_89 ( V_208 ) ;
if ( V_167 < 0 )
goto V_213;
V_208 -> V_214 = F_101 ( & V_59 -> V_71 ,
V_210 -> V_215 , F_102 ( V_210 ) ) ;
if ( ! V_208 -> V_214 ) {
V_167 = - V_216 ;
goto V_213;
}
V_217 . V_218 = V_208 -> V_218 ;
V_217 . V_219 = V_208 -> V_219 ;
V_38 -> V_220 = & V_217 ;
V_38 -> V_156 |= V_221 | V_48 -> V_222 ;
V_38 -> V_223 |= V_48 -> V_224 ;
V_38 -> V_225 = 32 ;
V_38 -> V_226 = 512 ;
V_38 -> V_227 = ( V_228 / V_38 -> V_226 ) *
V_38 -> V_225 ;
V_38 -> V_229 = V_38 -> V_226 * V_38 -> V_227 ;
V_38 -> V_230 = V_38 -> V_229 ;
V_208 -> V_104 = ! ( V_48 -> V_49 & V_231 ||
V_38 -> V_156 & V_232 ||
! F_103 ( V_38 ) ||
V_38 -> V_233 . V_234 >= 0 ) ;
if ( V_48 -> V_49 & V_50 )
V_208 -> V_104 = true ;
if ( F_72 ( V_208 ) < 0 ) {
V_38 -> V_235 = V_48 -> V_236 ;
V_38 -> V_56 = V_38 -> V_235 / 512 ;
}
if ( V_38 -> V_56 == 0 ) {
V_167 = - V_95 ;
goto V_213;
}
if ( V_208 -> V_104 )
F_104 ( & V_59 -> V_71 ) ;
F_22 ( V_208 ) ;
F_24 ( V_208 ) ;
V_208 -> V_4 = F_54 ( V_208 , V_6 ) ;
F_3 ( V_208 , V_237 ) ;
if ( ! V_208 -> V_116 )
V_79 |= V_131 ;
if ( ! V_208 -> V_115 )
V_79 |= V_132 ;
if ( ! V_208 -> V_104 )
V_79 &= ~ ( V_105 | V_106 ) ;
V_208 -> V_4 &= ~ V_79 ;
V_208 -> V_40 = false ;
if ( V_48 -> V_49 & V_153 ) {
V_208 -> V_41 = V_42 ;
F_16 ( V_208 , V_45 , V_208 -> V_41 ) ;
F_16 ( V_208 , V_44 , 0x0000 ) ;
}
F_105 ( & V_208 -> V_68 ) ;
F_106 ( & V_208 -> V_185 ) ;
F_107 ( & V_208 -> V_65 , F_25 ) ;
F_108 ( & V_208 -> V_76 , F_37 ) ;
F_109 ( V_208 , V_48 ) ;
F_110 ( & V_59 -> V_71 ) ;
F_111 ( & V_59 -> V_71 , 50 ) ;
F_112 ( & V_59 -> V_71 ) ;
F_113 ( & V_59 -> V_71 ) ;
V_167 = F_114 ( V_38 ) ;
if ( V_167 < 0 ) {
F_115 ( V_208 ) ;
return V_167 ;
}
F_116 ( & V_59 -> V_71 , 100 ) ;
if ( V_48 -> V_49 & V_231 ) {
V_167 = F_117 ( V_38 , V_48 -> V_238 , 0 ) ;
if ( V_167 < 0 ) {
F_115 ( V_208 ) ;
return V_167 ;
}
F_118 ( V_38 ) ;
}
return 0 ;
V_213:
return V_167 ;
}
void F_115 ( struct V_1 * V_2 )
{
struct V_204 * V_59 = V_2 -> V_59 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! V_2 -> V_104 )
F_14 ( & V_59 -> V_71 ) ;
F_119 ( & V_59 -> V_71 ) ;
F_120 ( V_38 ) ;
F_121 ( & V_2 -> V_76 ) ;
F_122 ( & V_2 -> V_65 ) ;
F_123 ( V_2 ) ;
F_124 ( & V_59 -> V_71 ) ;
F_125 ( & V_59 -> V_71 ) ;
}
int F_126 ( struct V_184 * V_71 )
{
struct V_37 * V_38 = F_127 ( V_71 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_3 ( V_2 , V_237 ) ;
if ( V_2 -> V_194 )
F_22 ( V_2 ) ;
if ( V_2 -> V_239 )
V_2 -> V_239 ( V_2 ) ;
return 0 ;
}
int F_128 ( struct V_184 * V_71 )
{
struct V_37 * V_38 = F_127 ( V_71 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_24 ( V_2 ) ;
F_72 ( V_2 ) ;
if ( V_2 -> V_194 )
F_23 ( V_2 , V_2 -> V_194 ) ;
F_129 ( V_2 , true ) ;
return 0 ;
}

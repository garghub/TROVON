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
T_2 V_41 ;
F_14 ( F_15 ( V_38 ) ) ;
V_2 -> V_40 = true ;
V_2 -> V_42 = V_43 &
~ V_44 ;
V_41 = F_16 ( V_2 , V_45 ) & ~ V_43 ;
if ( V_2 -> V_46 -> V_47 & V_48 )
V_41 |= V_49 ;
F_17 ( V_2 , V_45 , V_41 ) ;
F_17 ( V_2 , V_50 , V_2 -> V_42 ) ;
} else if ( ! V_39 && V_2 -> V_40 ) {
V_2 -> V_42 = V_43 ;
F_17 ( V_2 , V_50 , V_2 -> V_42 ) ;
V_2 -> V_40 = false ;
F_18 ( F_15 ( V_38 ) ) ;
F_19 ( F_15 ( V_38 ) ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_51 , V_52 |
F_16 ( V_2 , V_51 ) ) ;
F_21 ( V_2 -> V_46 -> V_47 & V_53 ? 1 : 10 ) ;
if ( V_2 -> V_46 -> V_47 & V_54 ) {
F_17 ( V_2 , V_55 , 0x0100 ) ;
F_21 ( 10 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 -> V_47 & V_54 ) {
F_17 ( V_2 , V_55 , 0x0000 ) ;
F_21 ( 10 ) ;
}
F_17 ( V_2 , V_51 , ~ V_52 &
F_16 ( V_2 , V_51 ) ) ;
F_21 ( V_2 -> V_46 -> V_47 & V_53 ? 5 : 10 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_56 )
{
T_1 V_57 = 0 , clock ;
if ( V_56 == 0 ) {
F_22 ( V_2 ) ;
return;
}
if ( V_2 -> V_58 )
clock = V_2 -> V_58 ( V_2 , V_56 ) / 512 ;
else
clock = V_2 -> V_38 -> V_59 ;
for ( V_57 = 0x80000080 ; V_56 >= ( clock << 1 ) ; V_57 >>= 1 )
clock <<= 1 ;
if ( ( V_2 -> V_46 -> V_47 & V_60 ) && ( ( V_57 >> 22 ) & 0x1 ) )
V_57 |= 0xff ;
if ( V_2 -> V_61 )
V_2 -> V_61 ( V_2 -> V_62 , ( V_57 >> 22 ) & 1 ) ;
F_17 ( V_2 , V_51 , ~ V_52 &
F_16 ( V_2 , V_51 ) ) ;
F_17 ( V_2 , V_51 , V_57 & V_63 ) ;
if ( ! ( V_2 -> V_46 -> V_47 & V_53 ) )
F_21 ( 10 ) ;
F_20 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_64 , 0x0000 ) ;
if ( V_2 -> V_46 -> V_47 & V_54 )
F_17 ( V_2 , V_65 , 0x0000 ) ;
F_21 ( 10 ) ;
F_17 ( V_2 , V_64 , 0x0001 ) ;
if ( V_2 -> V_46 -> V_47 & V_54 )
F_17 ( V_2 , V_65 , 0x0001 ) ;
F_21 ( 10 ) ;
}
static void F_25 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_26 ( V_67 , struct V_1 ,
V_68 . V_67 ) ;
struct V_69 * V_70 ;
unsigned long V_47 ;
F_27 ( & V_2 -> V_71 , V_47 ) ;
V_70 = V_2 -> V_70 ;
if ( F_28 ( V_70 )
|| F_29 ( V_2 -> V_72 +
F_30 ( V_73 ) ) ) {
F_31 ( & V_2 -> V_71 , V_47 ) ;
return;
}
F_32 ( & V_2 -> V_62 -> V_74 ,
L_3 ,
V_70 -> V_75 -> V_76 ) ;
if ( V_2 -> V_9 )
V_2 -> V_9 -> error = - V_77 ;
else if ( V_2 -> V_75 )
V_2 -> V_75 -> error = - V_77 ;
else
V_70 -> V_75 -> error = - V_77 ;
V_2 -> V_75 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_78 = false ;
F_31 ( & V_2 -> V_71 , V_47 ) ;
F_24 ( V_2 ) ;
V_2 -> V_70 = NULL ;
F_33 ( V_2 ) ;
F_34 ( V_2 -> V_38 , V_70 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_69 * V_70 ;
unsigned long V_47 ;
F_27 ( & V_2 -> V_71 , V_47 ) ;
V_70 = V_2 -> V_70 ;
if ( F_28 ( V_70 ) ) {
F_31 ( & V_2 -> V_71 , V_47 ) ;
return;
}
V_2 -> V_75 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_78 = false ;
F_36 ( & V_2 -> V_68 ) ;
V_2 -> V_70 = NULL ;
F_31 ( & V_2 -> V_71 , V_47 ) ;
if ( V_70 -> V_75 -> error || ( V_70 -> V_9 && V_70 -> V_9 -> error ) )
F_33 ( V_2 ) ;
if ( V_2 -> V_79 )
V_2 -> V_79 ( V_2 ) ;
F_34 ( V_2 -> V_38 , V_70 ) ;
}
static void F_37 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = F_26 ( V_67 , struct V_1 ,
V_80 ) ;
F_35 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_81 * V_75 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_82 = V_75 -> V_76 ;
T_1 V_83 = V_84 ;
if ( V_75 -> V_76 == V_85 && ! V_75 -> V_86 ) {
F_17 ( V_2 , V_87 , V_88 ) ;
return 0 ;
}
switch ( F_39 ( V_75 ) ) {
case V_89 : V_82 |= V_90 ; break;
case V_91 :
case V_92 :
V_82 |= V_93 ; break;
case V_94 : V_82 |= V_95 ; break;
case V_96 : V_82 |= V_97 ; break;
case V_98 : V_82 |= V_99 ; break;
default:
F_9 ( L_4 , F_39 ( V_75 ) ) ;
return - V_100 ;
}
V_2 -> V_75 = V_75 ;
if ( V_9 ) {
V_82 |= V_101 ;
if ( V_9 -> V_102 > 1 ) {
F_17 ( V_2 , V_87 , V_103 ) ;
V_82 |= V_104 ;
if ( ( V_2 -> V_46 -> V_47 & V_105 ) &&
( V_75 -> V_76 == V_106 ) )
V_82 |= V_107 ;
}
if ( V_9 -> V_47 & V_108 )
V_82 |= V_109 ;
}
if ( ! V_2 -> V_110 )
V_83 &= ~ ( V_111 | V_112 ) ;
F_1 ( V_2 , V_83 ) ;
F_2 ( V_2 , V_113 , V_75 -> V_86 ) ;
F_17 ( V_2 , V_114 , V_82 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned short * V_115 ,
unsigned int V_116 )
{
int V_117 = V_2 -> V_9 -> V_47 & V_108 ;
T_3 * V_118 ;
if ( V_2 -> V_46 -> V_47 & V_119 ) {
T_3 V_9 [ 4 ] = { } ;
if ( V_117 )
F_41 ( V_2 , V_120 , ( T_1 * ) V_115 ,
V_116 >> 2 ) ;
else
F_42 ( V_2 , V_120 , ( T_1 * ) V_115 ,
V_116 >> 2 ) ;
if ( ! ( V_116 & 0x3 ) )
return;
V_118 = ( T_3 * ) ( V_115 + ( V_116 >> 2 ) ) ;
V_116 %= 4 ;
if ( V_117 ) {
F_41 ( V_2 , V_120 ,
( T_1 * ) V_9 , 1 ) ;
memcpy ( V_118 , V_9 , V_116 ) ;
} else {
memcpy ( V_9 , V_118 , V_116 ) ;
F_42 ( V_2 , V_120 ,
( T_1 * ) V_9 , 1 ) ;
}
return;
}
if ( V_117 )
F_43 ( V_2 , V_120 , V_115 , V_116 >> 1 ) ;
else
F_44 ( V_2 , V_120 , V_115 , V_116 >> 1 ) ;
if ( ! ( V_116 & 0x1 ) )
return;
V_118 = ( T_3 * ) ( V_115 + ( V_116 >> 1 ) ) ;
if ( V_117 )
* V_118 = F_16 ( V_2 , V_120 ) & 0xff ;
else
F_17 ( V_2 , V_120 , * V_118 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_121 ;
unsigned short * V_115 ;
unsigned int V_116 ;
unsigned long V_47 ;
if ( ( V_2 -> V_122 || V_2 -> V_123 ) && ! V_2 -> V_78 ) {
F_46 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_121 = F_47 ( V_2 -> V_11 , & V_47 ) ;
V_115 = ( unsigned short * ) ( V_121 + V_2 -> V_14 ) ;
V_116 = V_2 -> V_11 -> V_124 - V_2 -> V_14 ;
if ( V_116 > V_9 -> V_125 )
V_116 = V_9 -> V_125 ;
F_9 ( L_7 ,
V_116 , V_2 -> V_14 , V_9 -> V_47 ) ;
F_40 ( V_2 , V_115 , V_116 ) ;
V_2 -> V_14 += V_116 ;
F_48 ( V_2 -> V_11 , & V_47 , V_121 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_124 )
F_6 ( V_2 ) ;
return;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_126 ) {
unsigned long V_47 ;
void * V_127 = F_47 ( V_2 -> V_13 , & V_47 ) ;
memcpy ( V_127 , V_2 -> V_128 , V_2 -> V_126 . V_124 ) ;
F_48 ( V_2 -> V_13 , & V_47 , V_127 ) ;
}
}
void F_50 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_81 * V_129 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_32 ( & V_2 -> V_62 -> V_74 , L_8 ) ;
return;
}
V_129 = V_9 -> V_129 ;
if ( ! V_9 -> error )
V_9 -> V_130 = V_9 -> V_102 * V_9 -> V_125 ;
else
V_9 -> V_130 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_47 & V_108 ) {
if ( V_2 -> V_123 && ! V_2 -> V_78 )
F_49 ( V_2 ) ;
F_51 ( & V_2 -> V_62 -> V_74 , L_10 ,
V_2 -> V_70 ) ;
} else {
F_51 ( & V_2 -> V_62 -> V_74 , L_11 ,
V_2 -> V_70 ) ;
}
if ( V_129 ) {
if ( V_129 -> V_76 != V_85 || V_129 -> V_86 )
F_52 ( & V_2 -> V_62 -> V_74 , L_12 ,
V_129 -> V_76 , V_129 -> V_86 ) ;
V_129 -> V_131 [ 0 ] = F_53 ( V_2 , V_132 ) ;
F_17 ( V_2 , V_87 , 0 ) ;
}
F_54 ( & V_2 -> V_80 ) ;
}
static void F_55 ( struct V_1 * V_2 , unsigned int V_133 )
{
struct V_8 * V_9 ;
F_56 ( & V_2 -> V_71 ) ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 )
goto V_134;
if ( V_133 & V_135 || V_133 & V_136 ||
V_133 & V_137 )
V_9 -> error = - V_138 ;
if ( V_2 -> V_122 && ( V_9 -> V_47 & V_139 ) && ! V_2 -> V_78 ) {
T_1 V_15 = F_53 ( V_2 , V_7 ) ;
bool V_80 = false ;
if ( V_2 -> V_46 -> V_47 & V_140 ) {
if ( V_15 & V_141 )
V_80 = true ;
} else {
if ( ! ( V_15 & V_142 ) )
V_80 = true ;
}
if ( V_80 ) {
F_3 ( V_2 , V_143 ) ;
F_57 ( & V_2 -> V_144 ) ;
}
} else if ( V_2 -> V_123 && ( V_9 -> V_47 & V_108 ) && ! V_2 -> V_78 ) {
F_3 ( V_2 , V_143 ) ;
F_57 ( & V_2 -> V_144 ) ;
} else {
F_50 ( V_2 ) ;
F_3 ( V_2 , V_145 | V_146 ) ;
}
V_134:
F_58 ( & V_2 -> V_71 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
unsigned int V_133 )
{
struct V_81 * V_75 = V_2 -> V_75 ;
int V_3 , V_147 ;
F_56 ( & V_2 -> V_71 ) ;
if ( ! V_2 -> V_75 ) {
F_9 ( L_13 ) ;
goto V_134;
}
for ( V_3 = 3 , V_147 = V_132 ; V_3 >= 0 ; V_3 -- , V_147 += 4 )
V_75 -> V_131 [ V_3 ] = F_53 ( V_2 , V_147 ) ;
if ( V_75 -> V_47 & V_148 ) {
V_75 -> V_131 [ 0 ] = ( V_75 -> V_131 [ 0 ] << 8 ) | ( V_75 -> V_131 [ 1 ] >> 24 ) ;
V_75 -> V_131 [ 1 ] = ( V_75 -> V_131 [ 1 ] << 8 ) | ( V_75 -> V_131 [ 2 ] >> 24 ) ;
V_75 -> V_131 [ 2 ] = ( V_75 -> V_131 [ 2 ] << 8 ) | ( V_75 -> V_131 [ 3 ] >> 24 ) ;
V_75 -> V_131 [ 3 ] <<= 8 ;
} else if ( V_75 -> V_47 & V_98 ) {
V_75 -> V_131 [ 0 ] = V_75 -> V_131 [ 3 ] ;
}
if ( V_133 & V_149 )
V_75 -> error = - V_77 ;
else if ( ( V_133 & V_135 && V_75 -> V_47 & V_150 ) ||
V_133 & V_136 ||
V_133 & V_151 )
V_75 -> error = - V_138 ;
if ( V_2 -> V_9 && ( ! V_75 -> error || V_75 -> error == - V_138 ) ) {
if ( V_2 -> V_9 -> V_47 & V_108 ) {
if ( V_2 -> V_78 || ! V_2 -> V_123 )
F_1 ( V_2 , V_145 ) ;
else
F_60 ( & V_2 -> V_152 ) ;
} else {
if ( V_2 -> V_78 || ! V_2 -> V_122 )
F_1 ( V_2 , V_146 ) ;
else
F_60 ( & V_2 -> V_152 ) ;
}
} else {
F_54 ( & V_2 -> V_80 ) ;
}
V_134:
F_58 ( & V_2 -> V_71 ) ;
}
static bool F_61 ( struct V_1 * V_2 ,
int V_153 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_153 & ( V_112 | V_111 ) ) {
F_4 ( V_2 , V_112 |
V_111 ) ;
if ( ( ( ( V_153 & V_111 ) && V_38 -> V_154 ) ||
( ( V_153 & V_112 ) && ! V_38 -> V_154 ) ) &&
! F_62 ( & V_38 -> V_155 . V_67 ) )
F_63 ( V_2 -> V_38 , F_30 ( 100 ) ) ;
return true ;
}
return false ;
}
static bool F_64 ( struct V_1 * V_2 ,
int V_153 , int V_15 )
{
if ( V_153 & ( V_156 | V_149 ) ) {
F_4 ( V_2 ,
V_156 |
V_149 ) ;
F_59 ( V_2 , V_15 ) ;
return true ;
}
if ( V_153 & ( V_157 | V_158 ) ) {
F_4 ( V_2 , V_157 | V_158 ) ;
F_45 ( V_2 ) ;
return true ;
}
if ( V_153 & V_143 ) {
F_4 ( V_2 , V_143 ) ;
F_55 ( V_2 , V_15 ) ;
return true ;
}
return false ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_159 * V_46 = V_2 -> V_46 ;
unsigned int V_153 , V_15 ;
unsigned int V_41 ;
if ( ! ( V_46 -> V_47 & V_160 ) )
return;
V_15 = F_16 ( V_2 , V_45 ) ;
V_153 = V_15 & V_43 & ~ V_2 -> V_42 ;
V_41 = V_15 & ~ V_43 ;
if ( V_46 -> V_47 & V_48 )
V_41 |= V_49 ;
F_17 ( V_2 , V_45 , V_41 ) ;
if ( V_38 -> V_161 & V_162 && V_153 & V_44 )
F_66 ( V_38 ) ;
}
T_4 F_67 ( int V_163 , void * V_164 )
{
struct V_1 * V_2 = V_164 ;
unsigned int V_153 , V_15 ;
V_15 = F_53 ( V_2 , V_7 ) ;
V_153 = V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( V_15 ) ;
F_8 ( V_153 ) ;
F_2 ( V_2 , V_7 , V_5 ) ;
if ( F_61 ( V_2 , V_153 , V_15 ) )
return V_165 ;
if ( F_64 ( V_2 , V_153 , V_15 ) )
return V_165 ;
F_65 ( V_2 ) ;
return V_165 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_159 * V_46 = V_2 -> V_46 ;
F_9 ( L_14 ,
V_9 -> V_125 , V_9 -> V_102 ) ;
if ( V_2 -> V_38 -> V_166 . V_167 == V_168 ||
V_2 -> V_38 -> V_166 . V_167 == V_169 ) {
int V_170 = V_46 -> V_47 & V_171 ;
if ( V_9 -> V_125 < 2 || ( V_9 -> V_125 < 4 && ! V_170 ) ) {
F_46 ( L_15 ,
F_69 ( V_2 -> V_38 ) , V_9 -> V_125 ) ;
return - V_100 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_17 ( V_2 , V_172 , V_9 -> V_125 ) ;
F_17 ( V_2 , V_173 , V_9 -> V_102 ) ;
F_70 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_71 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
if ( V_2 -> V_174 )
V_2 -> V_174 ( V_2 ) ;
}
static int F_72 ( struct V_37 * V_38 , T_1 V_76 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
int V_3 , V_175 = 0 ;
if ( ! V_2 -> V_176 || ! V_2 -> V_177 )
goto V_134;
V_2 -> V_178 = V_2 -> V_176 ( V_2 ) ;
if ( ! V_2 -> V_178 )
goto V_134;
if ( V_2 -> V_178 * 2 >= sizeof( V_2 -> V_179 ) * V_180 ) {
F_73 ( & V_2 -> V_62 -> V_74 ,
L_16 ) ;
goto V_134;
}
F_74 ( V_2 -> V_179 , V_2 -> V_178 * 2 ) ;
for ( V_3 = 0 ; V_3 < 2 * V_2 -> V_178 ; V_3 ++ ) {
if ( V_2 -> V_181 )
V_2 -> V_181 ( V_2 , V_3 % V_2 -> V_178 ) ;
V_175 = F_75 ( V_38 , V_76 , NULL ) ;
if ( V_175 && V_175 != - V_138 )
goto V_134;
if ( V_175 == 0 )
F_76 ( V_3 , V_2 -> V_179 ) ;
F_77 ( 1 ) ;
}
V_175 = V_2 -> V_177 ( V_2 ) ;
V_134:
if ( V_175 < 0 ) {
F_32 ( & V_2 -> V_62 -> V_74 , L_17 ) ;
F_71 ( V_38 ) ;
}
return V_175 ;
}
static void F_78 ( struct V_37 * V_38 , struct V_69 * V_70 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_47 ;
int V_175 ;
F_27 ( & V_2 -> V_71 , V_47 ) ;
if ( V_2 -> V_70 ) {
F_9 ( L_18 ) ;
if ( F_79 ( V_2 -> V_70 ) ) {
F_31 ( & V_2 -> V_71 , V_47 ) ;
V_70 -> V_75 -> error = - V_182 ;
F_34 ( V_38 , V_70 ) ;
return;
}
}
V_2 -> V_72 = V_183 ;
F_80 () ;
V_2 -> V_70 = V_70 ;
F_31 ( & V_2 -> V_71 , V_47 ) ;
if ( V_70 -> V_9 ) {
V_175 = F_68 ( V_2 , V_70 -> V_9 ) ;
if ( V_175 )
goto V_184;
}
V_175 = F_38 ( V_2 , V_70 -> V_75 ) ;
if ( ! V_175 ) {
F_81 ( & V_2 -> V_68 ,
F_30 ( V_73 ) ) ;
return;
}
V_184:
V_2 -> V_78 = false ;
V_2 -> V_70 = NULL ;
V_70 -> V_75 -> error = V_175 ;
F_34 ( V_38 , V_70 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_185 )
return - V_186 ;
return V_2 -> V_185 ( V_2 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( V_2 -> V_187 )
V_2 -> V_187 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 , unsigned short V_188 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_175 = 0 ;
if ( V_2 -> V_189 )
V_2 -> V_189 ( V_2 -> V_62 , 1 ) ;
if ( ! F_79 ( V_38 -> V_190 . V_191 ) ) {
V_175 = F_85 ( V_38 , V_38 -> V_190 . V_191 , V_188 ) ;
F_86 ( 200 ) ;
}
if ( ! F_79 ( V_38 -> V_190 . V_192 ) && ! V_175 ) {
V_175 = F_87 ( V_38 -> V_190 . V_192 ) ;
F_86 ( 200 ) ;
}
if ( V_175 < 0 )
F_51 ( & V_2 -> V_62 -> V_74 , L_19 ,
V_175 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! F_79 ( V_38 -> V_190 . V_192 ) )
F_89 ( V_38 -> V_190 . V_192 ) ;
if ( ! F_79 ( V_38 -> V_190 . V_191 ) )
F_85 ( V_38 , V_38 -> V_190 . V_191 , 0 ) ;
if ( V_2 -> V_189 )
V_2 -> V_189 ( V_2 -> V_62 , 0 ) ;
}
static void F_90 ( struct V_1 * V_2 ,
unsigned char V_167 )
{
T_2 V_193 = F_16 ( V_2 , V_194 )
& ~ ( V_195 | V_196 ) ;
if ( V_167 == V_197 )
V_193 |= V_195 ;
else if ( V_167 == V_169 )
V_193 |= V_196 ;
F_17 ( V_2 , V_194 , V_193 ) ;
}
static void F_91 ( struct V_37 * V_38 , struct V_198 * V_166 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_199 * V_74 = & V_2 -> V_62 -> V_74 ;
unsigned long V_47 ;
F_92 ( & V_2 -> V_200 ) ;
F_27 ( & V_2 -> V_71 , V_47 ) ;
if ( V_2 -> V_70 ) {
if ( F_79 ( V_2 -> V_70 ) ) {
F_51 ( V_74 ,
L_20 ,
V_201 -> V_202 , F_93 ( V_201 ) ,
V_166 -> clock , V_166 -> V_203 ) ;
V_2 -> V_70 = F_94 ( - V_204 ) ;
} else {
F_51 ( V_74 ,
L_21 ,
V_201 -> V_202 , F_93 ( V_201 ) ,
V_2 -> V_70 -> V_75 -> V_76 , V_2 -> V_72 , V_183 ) ;
}
F_31 ( & V_2 -> V_71 , V_47 ) ;
F_95 ( & V_2 -> V_200 ) ;
return;
}
V_2 -> V_70 = F_94 ( - V_205 ) ;
F_31 ( & V_2 -> V_71 , V_47 ) ;
switch ( V_166 -> V_203 ) {
case V_206 :
F_88 ( V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_207 :
F_84 ( V_2 , V_166 -> V_188 ) ;
F_23 ( V_2 , V_166 -> clock ) ;
F_90 ( V_2 , V_166 -> V_167 ) ;
break;
case V_208 :
F_23 ( V_2 , V_166 -> clock ) ;
F_90 ( V_2 , V_166 -> V_167 ) ;
break;
}
F_86 ( 140 ) ;
if ( F_96 ( V_2 -> V_70 ) == - V_204 )
F_51 ( & V_2 -> V_62 -> V_74 ,
L_22 ,
V_201 -> V_202 , F_93 ( V_201 ) ,
V_166 -> clock , V_166 -> V_203 ) ;
V_2 -> V_70 = NULL ;
V_2 -> V_209 = V_166 -> clock ;
F_95 ( & V_2 -> V_200 ) ;
}
static int F_97 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_159 * V_46 = V_2 -> V_46 ;
int V_175 = F_98 ( V_38 ) ;
if ( V_175 >= 0 )
return V_175 ;
V_175 = ! ( ( V_46 -> V_47 & V_210 ) ||
( F_53 ( V_2 , V_7 ) & V_211 ) ) ;
return V_175 ;
}
static int F_99 ( struct V_212 * V_154 ,
unsigned int V_213 , int V_214 )
{
struct V_1 * V_2 = F_13 ( V_154 -> V_2 ) ;
if ( V_2 -> V_215 )
return V_2 -> V_215 ( V_154 , V_213 , V_214 ) ;
return V_214 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_159 * V_46 = V_2 -> V_46 ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_101 ( V_38 ) ;
if ( ! V_38 -> V_216 )
V_38 -> V_216 = V_46 -> V_217 ;
if ( ! V_38 -> V_216 )
return - V_218 ;
return 0 ;
}
static void F_102 ( struct V_219 * V_62 ,
struct V_159 * V_46 )
{
const struct V_220 * V_221 = V_62 -> V_74 . V_222 ;
if ( ! V_221 )
return;
if ( F_103 ( V_221 , L_23 , NULL ) )
V_46 -> V_47 |= V_210 ;
}
struct V_1 *
F_104 ( struct V_219 * V_62 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
V_38 = F_105 ( sizeof( struct V_1 ) , & V_62 -> V_74 ) ;
if ( ! V_38 )
return NULL ;
V_2 = F_13 ( V_38 ) ;
V_2 -> V_38 = V_38 ;
V_2 -> V_62 = V_62 ;
return V_2 ;
}
void F_106 ( struct V_1 * V_2 )
{
F_107 ( V_2 -> V_38 ) ;
}
int F_108 ( struct V_1 * V_223 ,
struct V_159 * V_46 )
{
struct V_219 * V_62 = V_223 -> V_62 ;
struct V_37 * V_38 = V_223 -> V_38 ;
struct V_224 * V_225 ;
int V_175 ;
T_1 V_83 = V_84 ;
F_102 ( V_62 , V_46 ) ;
if ( ! ( V_46 -> V_47 & V_140 ) )
V_223 -> V_226 = NULL ;
V_225 = F_109 ( V_62 , V_227 , 0 ) ;
if ( ! V_225 )
return - V_100 ;
V_175 = F_110 ( V_38 ) ;
if ( V_175 < 0 )
return V_175 ;
V_223 -> V_46 = V_46 ;
F_111 ( V_62 , V_38 ) ;
V_223 -> V_189 = V_46 -> V_189 ;
V_223 -> V_61 = V_46 -> V_61 ;
V_175 = F_100 ( V_223 ) ;
if ( V_175 < 0 )
return V_175 ;
V_223 -> V_228 = F_112 ( & V_62 -> V_74 ,
V_225 -> V_229 , F_113 ( V_225 ) ) ;
if ( ! V_223 -> V_228 )
return - V_230 ;
V_231 . V_232 = V_223 -> V_232 ;
V_231 . V_233 = V_223 -> V_233 ;
V_38 -> V_234 = & V_231 ;
V_38 -> V_161 |= V_235 | V_46 -> V_236 ;
V_38 -> V_237 |= V_46 -> V_238 ;
V_38 -> V_239 = 32 ;
V_38 -> V_240 = 512 ;
V_38 -> V_241 = ( V_242 / V_38 -> V_240 ) *
V_38 -> V_239 ;
V_38 -> V_243 = V_38 -> V_240 * V_38 -> V_241 ;
V_38 -> V_244 = V_38 -> V_243 ;
V_223 -> V_110 = ! ( V_46 -> V_47 & V_245 ||
V_38 -> V_161 & V_246 ||
! F_114 ( V_38 ) ) ;
if ( V_46 -> V_47 & V_53 )
V_223 -> V_110 = true ;
if ( F_82 ( V_223 ) < 0 ) {
V_38 -> V_247 = V_46 -> V_248 ;
V_38 -> V_59 = V_38 -> V_247 / 512 ;
}
if ( V_38 -> V_59 == 0 )
return - V_100 ;
if ( V_223 -> V_110 )
F_115 ( & V_62 -> V_74 ) ;
F_22 ( V_223 ) ;
F_24 ( V_223 ) ;
V_223 -> V_4 = F_53 ( V_223 , V_6 ) ;
F_3 ( V_223 , V_249 ) ;
if ( ! V_223 -> V_123 )
V_83 |= V_145 ;
if ( ! V_223 -> V_122 )
V_83 |= V_146 ;
if ( ! V_223 -> V_110 )
V_83 &= ~ ( V_111 | V_112 ) ;
V_223 -> V_4 &= ~ V_83 ;
V_223 -> V_40 = false ;
if ( V_46 -> V_47 & V_160 ) {
V_223 -> V_42 = V_43 ;
F_17 ( V_223 , V_50 , V_223 -> V_42 ) ;
F_17 ( V_223 , V_250 , 0x0001 ) ;
}
F_116 ( & V_223 -> V_71 ) ;
F_117 ( & V_223 -> V_200 ) ;
F_118 ( & V_223 -> V_68 , F_25 ) ;
F_119 ( & V_223 -> V_80 , F_37 ) ;
F_120 ( V_223 , V_46 ) ;
F_121 ( & V_62 -> V_74 ) ;
F_122 ( & V_62 -> V_74 , 50 ) ;
F_123 ( & V_62 -> V_74 ) ;
F_124 ( & V_62 -> V_74 ) ;
V_175 = F_125 ( V_38 ) ;
if ( V_175 < 0 ) {
F_126 ( V_223 ) ;
return V_175 ;
}
F_127 ( & V_62 -> V_74 , 100 ) ;
if ( V_46 -> V_47 & V_245 ) {
V_175 = F_128 ( V_38 , V_46 -> V_251 , 0 ) ;
if ( V_175 < 0 ) {
F_126 ( V_223 ) ;
return V_175 ;
}
F_129 ( V_38 ) ;
}
return 0 ;
}
void F_126 ( struct V_1 * V_2 )
{
struct V_219 * V_62 = V_2 -> V_62 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_2 -> V_46 -> V_47 & V_160 )
F_17 ( V_2 , V_250 , 0x0000 ) ;
if ( ! V_2 -> V_110 )
F_14 ( & V_62 -> V_74 ) ;
F_130 ( & V_62 -> V_74 ) ;
F_131 ( V_38 ) ;
F_132 ( & V_2 -> V_80 ) ;
F_133 ( & V_2 -> V_68 ) ;
F_134 ( V_2 ) ;
F_135 ( & V_62 -> V_74 ) ;
F_136 ( & V_62 -> V_74 ) ;
F_83 ( V_2 ) ;
}
int F_137 ( struct V_199 * V_74 )
{
struct V_37 * V_38 = F_138 ( V_74 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_3 ( V_2 , V_249 ) ;
if ( V_2 -> V_209 )
F_22 ( V_2 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static bool F_139 ( struct V_1 * V_2 )
{
return V_2 -> V_178 && F_140 ( V_2 -> V_38 ) ;
}
int F_141 ( struct V_199 * V_74 )
{
struct V_37 * V_38 = F_138 ( V_74 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_24 ( V_2 ) ;
F_82 ( V_2 ) ;
if ( V_2 -> V_209 )
F_23 ( V_2 , V_2 -> V_209 ) ;
F_142 ( V_2 , true ) ;
if ( F_139 ( V_2 ) && V_2 -> V_177 ( V_2 ) )
F_32 ( & V_2 -> V_62 -> V_74 , L_24 ) ;
return 0 ;
}

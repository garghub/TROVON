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
F_17 ( V_2 , V_87 , 0x001 ) ;
return 0 ;
}
switch ( F_39 ( V_75 ) ) {
case V_88 : V_82 |= V_89 ; break;
case V_90 :
case V_91 :
V_82 |= V_92 ; break;
case V_93 : V_82 |= V_94 ; break;
case V_95 : V_82 |= V_96 ; break;
case V_97 : V_82 |= V_98 ; break;
default:
F_9 ( L_4 , F_39 ( V_75 ) ) ;
return - V_99 ;
}
V_2 -> V_75 = V_75 ;
if ( V_9 ) {
V_82 |= V_100 ;
if ( V_9 -> V_101 > 1 ) {
F_17 ( V_2 , V_87 , 0x100 ) ;
V_82 |= V_102 ;
if ( ( V_2 -> V_46 -> V_47 & V_103 ) &&
( V_75 -> V_76 == V_104 ) )
V_82 |= V_105 ;
}
if ( V_9 -> V_47 & V_106 )
V_82 |= V_107 ;
}
if ( ! V_2 -> V_108 )
V_83 &= ~ ( V_109 | V_110 ) ;
F_1 ( V_2 , V_83 ) ;
F_2 ( V_2 , V_111 , V_75 -> V_86 ) ;
F_17 ( V_2 , V_112 , V_82 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned short * V_113 ,
unsigned int V_114 )
{
int V_115 = V_2 -> V_9 -> V_47 & V_106 ;
T_3 * V_116 ;
if ( V_2 -> V_46 -> V_47 & V_117 ) {
T_3 V_9 [ 4 ] = { } ;
if ( V_115 )
F_41 ( V_2 , V_118 , ( T_1 * ) V_113 ,
V_114 >> 2 ) ;
else
F_42 ( V_2 , V_118 , ( T_1 * ) V_113 ,
V_114 >> 2 ) ;
if ( ! ( V_114 & 0x3 ) )
return;
V_116 = ( T_3 * ) ( V_113 + ( V_114 >> 2 ) ) ;
V_114 %= 4 ;
if ( V_115 ) {
F_41 ( V_2 , V_118 ,
( T_1 * ) V_9 , 1 ) ;
memcpy ( V_116 , V_9 , V_114 ) ;
} else {
memcpy ( V_9 , V_116 , V_114 ) ;
F_42 ( V_2 , V_118 ,
( T_1 * ) V_9 , 1 ) ;
}
return;
}
if ( V_115 )
F_43 ( V_2 , V_118 , V_113 , V_114 >> 1 ) ;
else
F_44 ( V_2 , V_118 , V_113 , V_114 >> 1 ) ;
if ( ! ( V_114 & 0x1 ) )
return;
V_116 = ( T_3 * ) ( V_113 + ( V_114 >> 1 ) ) ;
if ( V_115 )
* V_116 = F_16 ( V_2 , V_118 ) & 0xff ;
else
F_17 ( V_2 , V_118 , * V_116 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_119 ;
unsigned short * V_113 ;
unsigned int V_114 ;
unsigned long V_47 ;
if ( ( V_2 -> V_120 || V_2 -> V_121 ) && ! V_2 -> V_78 ) {
F_46 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_119 = F_47 ( V_2 -> V_11 , & V_47 ) ;
V_113 = ( unsigned short * ) ( V_119 + V_2 -> V_14 ) ;
V_114 = V_2 -> V_11 -> V_122 - V_2 -> V_14 ;
if ( V_114 > V_9 -> V_123 )
V_114 = V_9 -> V_123 ;
F_9 ( L_7 ,
V_114 , V_2 -> V_14 , V_9 -> V_47 ) ;
F_40 ( V_2 , V_113 , V_114 ) ;
V_2 -> V_14 += V_114 ;
F_48 ( V_2 -> V_11 , & V_47 , V_119 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_122 )
F_6 ( V_2 ) ;
return;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_124 ) {
unsigned long V_47 ;
void * V_125 = F_47 ( V_2 -> V_13 , & V_47 ) ;
memcpy ( V_125 , V_2 -> V_126 , V_2 -> V_124 . V_122 ) ;
F_48 ( V_2 -> V_13 , & V_47 , V_125 ) ;
}
}
void F_50 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_81 * V_127 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_32 ( & V_2 -> V_62 -> V_74 , L_8 ) ;
return;
}
V_127 = V_9 -> V_127 ;
if ( ! V_9 -> error )
V_9 -> V_128 = V_9 -> V_101 * V_9 -> V_123 ;
else
V_9 -> V_128 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_47 & V_106 ) {
if ( V_2 -> V_121 && ! V_2 -> V_78 )
F_49 ( V_2 ) ;
F_51 ( & V_2 -> V_62 -> V_74 , L_10 ,
V_2 -> V_70 ) ;
} else {
F_51 ( & V_2 -> V_62 -> V_74 , L_11 ,
V_2 -> V_70 ) ;
}
if ( V_127 ) {
if ( V_127 -> V_76 == V_85 && ! V_127 -> V_86 )
F_17 ( V_2 , V_87 , 0x000 ) ;
else
F_52 () ;
}
F_53 ( & V_2 -> V_80 ) ;
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_129 )
{
struct V_8 * V_9 ;
F_55 ( & V_2 -> V_71 ) ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 )
goto V_130;
if ( V_129 & V_131 || V_129 & V_132 ||
V_129 & V_133 )
V_9 -> error = - V_134 ;
if ( V_2 -> V_120 && ( V_9 -> V_47 & V_135 ) && ! V_2 -> V_78 ) {
T_1 V_15 = F_56 ( V_2 , V_7 ) ;
bool V_80 = false ;
if ( V_2 -> V_46 -> V_47 & V_136 ) {
if ( V_15 & V_137 )
V_80 = true ;
} else {
if ( ! ( V_15 & V_138 ) )
V_80 = true ;
}
if ( V_80 ) {
F_3 ( V_2 , V_139 ) ;
F_57 ( & V_2 -> V_140 ) ;
}
} else if ( V_2 -> V_121 && ( V_9 -> V_47 & V_106 ) && ! V_2 -> V_78 ) {
F_3 ( V_2 , V_139 ) ;
F_57 ( & V_2 -> V_140 ) ;
} else {
F_50 ( V_2 ) ;
F_3 ( V_2 , V_141 | V_142 ) ;
}
V_130:
F_58 ( & V_2 -> V_71 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
unsigned int V_129 )
{
struct V_81 * V_75 = V_2 -> V_75 ;
int V_3 , V_143 ;
F_55 ( & V_2 -> V_71 ) ;
if ( ! V_2 -> V_75 ) {
F_9 ( L_12 ) ;
goto V_130;
}
for ( V_3 = 3 , V_143 = V_144 ; V_3 >= 0 ; V_3 -- , V_143 += 4 )
V_75 -> V_145 [ V_3 ] = F_56 ( V_2 , V_143 ) ;
if ( V_75 -> V_47 & V_146 ) {
V_75 -> V_145 [ 0 ] = ( V_75 -> V_145 [ 0 ] << 8 ) | ( V_75 -> V_145 [ 1 ] >> 24 ) ;
V_75 -> V_145 [ 1 ] = ( V_75 -> V_145 [ 1 ] << 8 ) | ( V_75 -> V_145 [ 2 ] >> 24 ) ;
V_75 -> V_145 [ 2 ] = ( V_75 -> V_145 [ 2 ] << 8 ) | ( V_75 -> V_145 [ 3 ] >> 24 ) ;
V_75 -> V_145 [ 3 ] <<= 8 ;
} else if ( V_75 -> V_47 & V_97 ) {
V_75 -> V_145 [ 0 ] = V_75 -> V_145 [ 3 ] ;
}
if ( V_129 & V_147 )
V_75 -> error = - V_77 ;
else if ( ( V_129 & V_131 && V_75 -> V_47 & V_148 ) ||
V_129 & V_132 ||
V_129 & V_149 )
V_75 -> error = - V_134 ;
if ( V_2 -> V_9 && ( ! V_75 -> error || V_75 -> error == - V_134 ) ) {
if ( V_2 -> V_9 -> V_47 & V_106 ) {
if ( V_2 -> V_78 || ! V_2 -> V_121 )
F_1 ( V_2 , V_141 ) ;
else
F_57 ( & V_2 -> V_150 ) ;
} else {
if ( V_2 -> V_78 || ! V_2 -> V_120 )
F_1 ( V_2 , V_142 ) ;
else
F_57 ( & V_2 -> V_150 ) ;
}
} else {
F_53 ( & V_2 -> V_80 ) ;
}
V_130:
F_58 ( & V_2 -> V_71 ) ;
}
static bool F_60 ( struct V_1 * V_2 ,
int V_151 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_151 & ( V_110 | V_109 ) ) {
F_4 ( V_2 , V_110 |
V_109 ) ;
if ( ( ( ( V_151 & V_109 ) && V_38 -> V_152 ) ||
( ( V_151 & V_110 ) && ! V_38 -> V_152 ) ) &&
! F_61 ( & V_38 -> V_153 . V_67 ) )
F_62 ( V_2 -> V_38 , F_30 ( 100 ) ) ;
return true ;
}
return false ;
}
static bool F_63 ( struct V_1 * V_2 ,
int V_151 , int V_15 )
{
if ( V_151 & ( V_154 | V_147 ) ) {
F_4 ( V_2 ,
V_154 |
V_147 ) ;
F_59 ( V_2 , V_15 ) ;
return true ;
}
if ( V_151 & ( V_155 | V_156 ) ) {
F_4 ( V_2 , V_155 | V_156 ) ;
F_45 ( V_2 ) ;
return true ;
}
if ( V_151 & V_139 ) {
F_4 ( V_2 , V_139 ) ;
F_54 ( V_2 , V_15 ) ;
return true ;
}
return false ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_157 * V_46 = V_2 -> V_46 ;
unsigned int V_151 , V_15 ;
unsigned int V_41 ;
if ( ! ( V_46 -> V_47 & V_158 ) )
return;
V_15 = F_16 ( V_2 , V_45 ) ;
V_151 = V_15 & V_43 & ~ V_2 -> V_42 ;
V_41 = V_15 & ~ V_43 ;
if ( V_46 -> V_47 & V_48 )
V_41 |= V_49 ;
F_17 ( V_2 , V_45 , V_41 ) ;
if ( V_38 -> V_159 & V_160 && V_151 & V_44 )
F_65 ( V_38 ) ;
}
T_4 F_66 ( int V_161 , void * V_162 )
{
struct V_1 * V_2 = V_162 ;
unsigned int V_151 , V_15 ;
V_15 = F_56 ( V_2 , V_7 ) ;
V_151 = V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( V_15 ) ;
F_8 ( V_151 ) ;
F_2 ( V_2 , V_7 , V_5 ) ;
if ( F_60 ( V_2 , V_151 , V_15 ) )
return V_163 ;
if ( F_63 ( V_2 , V_151 , V_15 ) )
return V_163 ;
F_64 ( V_2 ) ;
return V_163 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_157 * V_46 = V_2 -> V_46 ;
F_9 ( L_13 ,
V_9 -> V_123 , V_9 -> V_101 ) ;
if ( V_2 -> V_38 -> V_164 . V_165 == V_166 ||
V_2 -> V_38 -> V_164 . V_165 == V_167 ) {
int V_168 = V_46 -> V_47 & V_169 ;
if ( V_9 -> V_123 < 2 || ( V_9 -> V_123 < 4 && ! V_168 ) ) {
F_46 ( L_14 ,
F_68 ( V_2 -> V_38 ) , V_9 -> V_123 ) ;
return - V_99 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_17 ( V_2 , V_170 , V_9 -> V_123 ) ;
F_17 ( V_2 , V_171 , V_9 -> V_101 ) ;
F_69 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_70 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
if ( V_2 -> V_172 )
V_2 -> V_172 ( V_2 ) ;
}
static int F_71 ( struct V_37 * V_38 , T_1 V_76 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
int V_3 , V_173 = 0 ;
if ( ! V_2 -> V_174 ) {
if ( ! V_2 -> V_175 || ! V_2 -> V_176 )
goto V_130;
V_2 -> V_174 = V_2 -> V_175 ( V_2 ) ;
if ( ! V_2 -> V_174 )
goto V_130;
}
if ( V_2 -> V_174 * 2 >= sizeof( V_2 -> V_177 ) * V_178 ) {
F_72 ( & V_2 -> V_62 -> V_74 ,
L_15 ) ;
goto V_130;
}
F_73 ( V_2 -> V_177 , V_2 -> V_174 * 2 ) ;
for ( V_3 = 0 ; V_3 < 2 * V_2 -> V_174 ; V_3 ++ ) {
if ( V_2 -> V_179 )
V_2 -> V_179 ( V_2 , V_3 % V_2 -> V_174 ) ;
V_173 = F_74 ( V_38 , V_76 , NULL ) ;
if ( V_173 && V_173 != - V_134 )
goto V_130;
if ( V_173 == 0 )
F_75 ( V_3 , V_2 -> V_177 ) ;
F_76 ( 1 ) ;
}
V_173 = V_2 -> V_176 ( V_2 ) ;
V_130:
if ( V_173 < 0 ) {
F_32 ( & V_2 -> V_62 -> V_74 , L_16 ) ;
F_70 ( V_38 ) ;
}
return V_173 ;
}
static void F_77 ( struct V_37 * V_38 , struct V_69 * V_70 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_47 ;
int V_173 ;
F_27 ( & V_2 -> V_71 , V_47 ) ;
if ( V_2 -> V_70 ) {
F_9 ( L_17 ) ;
if ( F_78 ( V_2 -> V_70 ) ) {
F_31 ( & V_2 -> V_71 , V_47 ) ;
V_70 -> V_75 -> error = - V_180 ;
F_34 ( V_38 , V_70 ) ;
return;
}
}
V_2 -> V_72 = V_181 ;
F_79 () ;
V_2 -> V_70 = V_70 ;
F_31 ( & V_2 -> V_71 , V_47 ) ;
if ( V_70 -> V_9 ) {
V_173 = F_67 ( V_2 , V_70 -> V_9 ) ;
if ( V_173 )
goto V_182;
}
V_173 = F_38 ( V_2 , V_70 -> V_75 ) ;
if ( ! V_173 ) {
F_80 ( & V_2 -> V_68 ,
F_30 ( V_73 ) ) ;
return;
}
V_182:
V_2 -> V_78 = false ;
V_2 -> V_70 = NULL ;
V_70 -> V_75 -> error = V_173 ;
F_34 ( V_38 , V_70 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_183 )
return - V_184 ;
return V_2 -> V_183 ( V_2 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
if ( V_2 -> V_185 )
V_2 -> V_185 ( V_2 ) ;
}
static void F_83 ( struct V_1 * V_2 , unsigned short V_186 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_173 = 0 ;
if ( V_2 -> V_187 )
V_2 -> V_187 ( V_2 -> V_62 , 1 ) ;
if ( ! F_78 ( V_38 -> V_188 . V_189 ) ) {
V_173 = F_84 ( V_38 , V_38 -> V_188 . V_189 , V_186 ) ;
F_85 ( 200 ) ;
}
if ( ! F_78 ( V_38 -> V_188 . V_190 ) && ! V_173 ) {
V_173 = F_86 ( V_38 -> V_188 . V_190 ) ;
F_85 ( 200 ) ;
}
if ( V_173 < 0 )
F_51 ( & V_2 -> V_62 -> V_74 , L_18 ,
V_173 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! F_78 ( V_38 -> V_188 . V_190 ) )
F_88 ( V_38 -> V_188 . V_190 ) ;
if ( ! F_78 ( V_38 -> V_188 . V_189 ) )
F_84 ( V_38 , V_38 -> V_188 . V_189 , 0 ) ;
if ( V_2 -> V_187 )
V_2 -> V_187 ( V_2 -> V_62 , 0 ) ;
}
static void F_89 ( struct V_1 * V_2 ,
unsigned char V_165 )
{
T_2 V_191 = F_16 ( V_2 , V_192 )
& ~ ( V_193 | V_194 ) ;
if ( V_165 == V_195 )
V_191 |= V_193 ;
else if ( V_165 == V_167 )
V_191 |= V_194 ;
F_17 ( V_2 , V_192 , V_191 ) ;
}
static void F_90 ( struct V_37 * V_38 , struct V_196 * V_164 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_197 * V_74 = & V_2 -> V_62 -> V_74 ;
unsigned long V_47 ;
F_91 ( & V_2 -> V_198 ) ;
F_27 ( & V_2 -> V_71 , V_47 ) ;
if ( V_2 -> V_70 ) {
if ( F_78 ( V_2 -> V_70 ) ) {
F_51 ( V_74 ,
L_19 ,
V_199 -> V_200 , F_92 ( V_199 ) ,
V_164 -> clock , V_164 -> V_201 ) ;
V_2 -> V_70 = F_93 ( - V_202 ) ;
} else {
F_51 ( V_74 ,
L_20 ,
V_199 -> V_200 , F_92 ( V_199 ) ,
V_2 -> V_70 -> V_75 -> V_76 , V_2 -> V_72 , V_181 ) ;
}
F_31 ( & V_2 -> V_71 , V_47 ) ;
F_94 ( & V_2 -> V_198 ) ;
return;
}
V_2 -> V_70 = F_93 ( - V_203 ) ;
F_31 ( & V_2 -> V_71 , V_47 ) ;
switch ( V_164 -> V_201 ) {
case V_204 :
F_87 ( V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_205 :
F_83 ( V_2 , V_164 -> V_186 ) ;
F_23 ( V_2 , V_164 -> clock ) ;
F_89 ( V_2 , V_164 -> V_165 ) ;
break;
case V_206 :
F_23 ( V_2 , V_164 -> clock ) ;
F_89 ( V_2 , V_164 -> V_165 ) ;
break;
}
F_85 ( 140 ) ;
if ( F_95 ( V_2 -> V_70 ) == - V_202 )
F_51 ( & V_2 -> V_62 -> V_74 ,
L_21 ,
V_199 -> V_200 , F_92 ( V_199 ) ,
V_164 -> clock , V_164 -> V_201 ) ;
V_2 -> V_70 = NULL ;
V_2 -> V_207 = V_164 -> clock ;
F_94 ( & V_2 -> V_198 ) ;
}
static int F_96 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_157 * V_46 = V_2 -> V_46 ;
int V_173 = F_97 ( V_38 ) ;
if ( V_173 >= 0 )
return V_173 ;
V_173 = ! ( ( V_46 -> V_47 & V_208 ) ||
( F_56 ( V_2 , V_7 ) & V_209 ) ) ;
return V_173 ;
}
static int F_98 ( struct V_210 * V_152 ,
unsigned int V_211 , int V_212 )
{
struct V_1 * V_2 = F_13 ( V_152 -> V_2 ) ;
if ( V_2 -> V_213 )
return V_2 -> V_213 ( V_152 , V_211 , V_212 ) ;
return V_212 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_157 * V_46 = V_2 -> V_46 ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_100 ( V_38 ) ;
if ( ! V_38 -> V_214 )
V_38 -> V_214 = V_46 -> V_215 ;
if ( ! V_38 -> V_214 )
return - V_216 ;
return 0 ;
}
static void F_101 ( struct V_217 * V_62 ,
struct V_157 * V_46 )
{
const struct V_218 * V_219 = V_62 -> V_74 . V_220 ;
if ( ! V_219 )
return;
if ( F_102 ( V_219 , L_22 , NULL ) )
V_46 -> V_47 |= V_208 ;
}
struct V_1 *
F_103 ( struct V_217 * V_62 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
V_38 = F_104 ( sizeof( struct V_1 ) , & V_62 -> V_74 ) ;
if ( ! V_38 )
return NULL ;
V_2 = F_13 ( V_38 ) ;
V_2 -> V_38 = V_38 ;
V_2 -> V_62 = V_62 ;
return V_2 ;
}
void F_105 ( struct V_1 * V_2 )
{
F_106 ( V_2 -> V_38 ) ;
}
int F_107 ( struct V_1 * V_221 ,
struct V_157 * V_46 )
{
struct V_217 * V_62 = V_221 -> V_62 ;
struct V_37 * V_38 = V_221 -> V_38 ;
struct V_222 * V_223 ;
int V_173 ;
T_1 V_83 = V_84 ;
F_101 ( V_62 , V_46 ) ;
if ( ! ( V_46 -> V_47 & V_136 ) )
V_221 -> V_224 = NULL ;
V_223 = F_108 ( V_62 , V_225 , 0 ) ;
if ( ! V_223 )
return - V_99 ;
V_173 = F_109 ( V_38 ) ;
if ( V_173 < 0 )
return V_173 ;
V_221 -> V_46 = V_46 ;
F_110 ( V_62 , V_38 ) ;
V_221 -> V_187 = V_46 -> V_187 ;
V_221 -> V_61 = V_46 -> V_61 ;
V_173 = F_99 ( V_221 ) ;
if ( V_173 < 0 )
return V_173 ;
V_221 -> V_226 = F_111 ( & V_62 -> V_74 ,
V_223 -> V_227 , F_112 ( V_223 ) ) ;
if ( ! V_221 -> V_226 )
return - V_228 ;
V_229 . V_230 = V_221 -> V_230 ;
V_229 . V_231 = V_221 -> V_231 ;
V_38 -> V_232 = & V_229 ;
V_38 -> V_159 |= V_233 | V_46 -> V_234 ;
V_38 -> V_235 |= V_46 -> V_236 ;
V_38 -> V_237 = 32 ;
V_38 -> V_238 = 512 ;
V_38 -> V_239 = ( V_240 / V_38 -> V_238 ) *
V_38 -> V_237 ;
V_38 -> V_241 = V_38 -> V_238 * V_38 -> V_239 ;
V_38 -> V_242 = V_38 -> V_241 ;
V_221 -> V_108 = ! ( V_46 -> V_47 & V_243 ||
V_38 -> V_159 & V_244 ||
! F_113 ( V_38 ) ) ;
if ( V_46 -> V_47 & V_53 )
V_221 -> V_108 = true ;
if ( F_81 ( V_221 ) < 0 ) {
V_38 -> V_245 = V_46 -> V_246 ;
V_38 -> V_59 = V_38 -> V_245 / 512 ;
}
if ( V_38 -> V_59 == 0 )
return - V_99 ;
if ( V_221 -> V_108 )
F_114 ( & V_62 -> V_74 ) ;
F_22 ( V_221 ) ;
F_24 ( V_221 ) ;
V_221 -> V_4 = F_56 ( V_221 , V_6 ) ;
F_3 ( V_221 , V_247 ) ;
if ( ! V_221 -> V_121 )
V_83 |= V_141 ;
if ( ! V_221 -> V_120 )
V_83 |= V_142 ;
if ( ! V_221 -> V_108 )
V_83 &= ~ ( V_109 | V_110 ) ;
V_221 -> V_4 &= ~ V_83 ;
V_221 -> V_40 = false ;
if ( V_46 -> V_47 & V_158 ) {
V_221 -> V_42 = V_43 ;
F_17 ( V_221 , V_50 , V_221 -> V_42 ) ;
F_17 ( V_221 , V_248 , 0x0001 ) ;
}
F_115 ( & V_221 -> V_71 ) ;
F_116 ( & V_221 -> V_198 ) ;
F_117 ( & V_221 -> V_68 , F_25 ) ;
F_118 ( & V_221 -> V_80 , F_37 ) ;
F_119 ( V_221 , V_46 ) ;
F_120 ( & V_62 -> V_74 ) ;
F_121 ( & V_62 -> V_74 , 50 ) ;
F_122 ( & V_62 -> V_74 ) ;
F_123 ( & V_62 -> V_74 ) ;
V_173 = F_124 ( V_38 ) ;
if ( V_173 < 0 ) {
F_125 ( V_221 ) ;
return V_173 ;
}
F_126 ( & V_62 -> V_74 , 100 ) ;
if ( V_46 -> V_47 & V_243 ) {
V_173 = F_127 ( V_38 , V_46 -> V_249 , 0 ) ;
if ( V_173 < 0 ) {
F_125 ( V_221 ) ;
return V_173 ;
}
F_128 ( V_38 ) ;
}
return 0 ;
}
void F_125 ( struct V_1 * V_2 )
{
struct V_217 * V_62 = V_2 -> V_62 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_2 -> V_46 -> V_47 & V_158 )
F_17 ( V_2 , V_248 , 0x0000 ) ;
if ( ! V_2 -> V_108 )
F_14 ( & V_62 -> V_74 ) ;
F_129 ( & V_62 -> V_74 ) ;
F_130 ( V_38 ) ;
F_131 ( & V_2 -> V_80 ) ;
F_132 ( & V_2 -> V_68 ) ;
F_133 ( V_2 ) ;
F_134 ( & V_62 -> V_74 ) ;
F_135 ( & V_62 -> V_74 ) ;
F_82 ( V_2 ) ;
}
int F_136 ( struct V_197 * V_74 )
{
struct V_37 * V_38 = F_137 ( V_74 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_3 ( V_2 , V_247 ) ;
if ( V_2 -> V_207 )
F_22 ( V_2 ) ;
F_82 ( V_2 ) ;
return 0 ;
}
static bool F_138 ( struct V_1 * V_2 )
{
return V_2 -> V_174 && F_139 ( V_2 -> V_38 ) ;
}
int F_140 ( struct V_197 * V_74 )
{
struct V_37 * V_38 = F_137 ( V_74 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_24 ( V_2 ) ;
F_81 ( V_2 ) ;
if ( V_2 -> V_207 )
F_23 ( V_2 , V_2 -> V_207 ) ;
F_141 ( V_2 , true ) ;
if ( F_138 ( V_2 ) && V_2 -> V_176 ( V_2 ) )
F_32 ( & V_2 -> V_62 -> V_74 , L_23 ) ;
return 0 ;
}

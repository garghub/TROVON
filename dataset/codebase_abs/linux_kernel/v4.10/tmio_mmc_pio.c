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
if ( V_2 -> V_76 )
V_2 -> V_76 ( V_2 ) ;
F_34 ( V_2 -> V_38 , V_67 ) ;
}
static void F_37 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_26 ( V_64 , struct V_1 ,
V_77 ) ;
F_35 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_78 * V_72 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_79 = V_72 -> V_73 ;
T_1 V_80 = V_81 ;
if ( V_72 -> V_73 == V_82 && ! V_72 -> V_83 ) {
F_16 ( V_2 , V_84 , 0x001 ) ;
return 0 ;
}
switch ( F_39 ( V_72 ) ) {
case V_85 : V_79 |= V_86 ; break;
case V_87 :
case V_88 :
V_79 |= V_89 ; break;
case V_90 : V_79 |= V_91 ; break;
case V_92 : V_79 |= V_93 ; break;
case V_94 : V_79 |= V_95 ; break;
default:
F_9 ( L_4 , F_39 ( V_72 ) ) ;
return - V_96 ;
}
V_2 -> V_72 = V_72 ;
if ( V_9 ) {
V_79 |= V_97 ;
if ( V_9 -> V_98 > 1 ) {
F_16 ( V_2 , V_84 , 0x100 ) ;
V_79 |= V_99 ;
if ( ( V_2 -> V_48 -> V_49 & V_100 ) &&
( V_72 -> V_73 == V_101 ) )
V_79 |= V_102 ;
}
if ( V_9 -> V_49 & V_103 )
V_79 |= V_104 ;
}
if ( ! V_2 -> V_105 )
V_80 &= ~ ( V_106 | V_107 ) ;
F_1 ( V_2 , V_80 ) ;
F_2 ( V_2 , V_108 , V_72 -> V_83 ) ;
F_16 ( V_2 , V_109 , V_79 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned short * V_110 ,
unsigned int V_111 )
{
int V_112 = V_2 -> V_9 -> V_49 & V_103 ;
T_2 * V_113 ;
if ( V_2 -> V_48 -> V_49 & V_114 ) {
T_2 V_9 [ 4 ] = { } ;
if ( V_112 )
F_41 ( V_2 , V_115 , ( T_1 * ) V_110 ,
V_111 >> 2 ) ;
else
F_42 ( V_2 , V_115 , ( T_1 * ) V_110 ,
V_111 >> 2 ) ;
if ( ! ( V_111 & 0x3 ) )
return;
V_113 = ( T_2 * ) ( V_110 + ( V_111 >> 2 ) ) ;
V_111 %= 4 ;
if ( V_112 ) {
F_41 ( V_2 , V_115 ,
( T_1 * ) V_9 , 1 ) ;
memcpy ( V_113 , V_9 , V_111 ) ;
} else {
memcpy ( V_9 , V_113 , V_111 ) ;
F_42 ( V_2 , V_115 ,
( T_1 * ) V_9 , 1 ) ;
}
return;
}
if ( V_112 )
F_43 ( V_2 , V_115 , V_110 , V_111 >> 1 ) ;
else
F_44 ( V_2 , V_115 , V_110 , V_111 >> 1 ) ;
if ( ! ( V_111 & 0x1 ) )
return;
V_113 = ( T_2 * ) ( V_110 + ( V_111 >> 1 ) ) ;
if ( V_112 )
* V_113 = F_20 ( V_2 , V_115 ) & 0xff ;
else
F_16 ( V_2 , V_115 , * V_113 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_116 ;
unsigned short * V_110 ;
unsigned int V_111 ;
unsigned long V_49 ;
if ( ( V_2 -> V_117 || V_2 -> V_118 ) && ! V_2 -> V_75 ) {
F_46 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_116 = F_47 ( V_2 -> V_11 , & V_49 ) ;
V_110 = ( unsigned short * ) ( V_116 + V_2 -> V_14 ) ;
V_111 = V_2 -> V_11 -> V_119 - V_2 -> V_14 ;
if ( V_111 > V_9 -> V_120 )
V_111 = V_9 -> V_120 ;
F_9 ( L_7 ,
V_111 , V_2 -> V_14 , V_9 -> V_49 ) ;
F_40 ( V_2 , V_110 , V_111 ) ;
V_2 -> V_14 += V_111 ;
F_48 ( V_2 -> V_11 , & V_49 , V_116 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_119 )
F_6 ( V_2 ) ;
return;
}
static void F_49 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_121 ) {
unsigned long V_49 ;
void * V_122 = F_47 ( V_2 -> V_13 , & V_49 ) ;
memcpy ( V_122 , V_2 -> V_123 , V_2 -> V_121 . V_119 ) ;
F_48 ( V_2 -> V_13 , & V_49 , V_122 ) ;
}
}
void F_50 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_78 * V_124 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_32 ( & V_2 -> V_59 -> V_71 , L_8 ) ;
return;
}
V_124 = V_9 -> V_124 ;
if ( ! V_9 -> error )
V_9 -> V_125 = V_9 -> V_98 * V_9 -> V_120 ;
else
V_9 -> V_125 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_49 & V_103 ) {
if ( V_2 -> V_118 && ! V_2 -> V_75 )
F_49 ( V_2 ) ;
F_51 ( & V_2 -> V_59 -> V_71 , L_10 ,
V_2 -> V_67 ) ;
} else {
F_51 ( & V_2 -> V_59 -> V_71 , L_11 ,
V_2 -> V_67 ) ;
}
if ( V_124 ) {
if ( V_124 -> V_73 == V_82 && ! V_124 -> V_83 )
F_16 ( V_2 , V_84 , 0x000 ) ;
else
F_52 () ;
}
F_53 ( & V_2 -> V_77 ) ;
}
static void F_54 ( struct V_1 * V_2 , unsigned int V_126 )
{
struct V_8 * V_9 ;
F_55 ( & V_2 -> V_68 ) ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 )
goto V_127;
if ( V_126 & V_128 || V_126 & V_129 ||
V_126 & V_130 )
V_9 -> error = - V_131 ;
if ( V_2 -> V_117 && ( V_9 -> V_49 & V_132 ) && ! V_2 -> V_75 ) {
T_1 V_15 = F_56 ( V_2 , V_7 ) ;
bool V_77 = false ;
if ( V_2 -> V_48 -> V_49 & V_133 ) {
if ( V_15 & V_134 )
V_77 = true ;
} else {
if ( ! ( V_15 & V_135 ) )
V_77 = true ;
}
if ( V_77 ) {
F_3 ( V_2 , V_136 ) ;
F_57 ( & V_2 -> V_137 ) ;
}
} else if ( V_2 -> V_118 && ( V_9 -> V_49 & V_103 ) && ! V_2 -> V_75 ) {
F_3 ( V_2 , V_136 ) ;
F_57 ( & V_2 -> V_137 ) ;
} else {
F_50 ( V_2 ) ;
F_3 ( V_2 , V_138 | V_139 ) ;
}
V_127:
F_58 ( & V_2 -> V_68 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
unsigned int V_126 )
{
struct V_78 * V_72 = V_2 -> V_72 ;
int V_3 , V_140 ;
F_55 ( & V_2 -> V_68 ) ;
if ( ! V_2 -> V_72 ) {
F_9 ( L_12 ) ;
goto V_127;
}
for ( V_3 = 3 , V_140 = V_141 ; V_3 >= 0 ; V_3 -- , V_140 += 4 )
V_72 -> V_142 [ V_3 ] = F_56 ( V_2 , V_140 ) ;
if ( V_72 -> V_49 & V_143 ) {
V_72 -> V_142 [ 0 ] = ( V_72 -> V_142 [ 0 ] << 8 ) | ( V_72 -> V_142 [ 1 ] >> 24 ) ;
V_72 -> V_142 [ 1 ] = ( V_72 -> V_142 [ 1 ] << 8 ) | ( V_72 -> V_142 [ 2 ] >> 24 ) ;
V_72 -> V_142 [ 2 ] = ( V_72 -> V_142 [ 2 ] << 8 ) | ( V_72 -> V_142 [ 3 ] >> 24 ) ;
V_72 -> V_142 [ 3 ] <<= 8 ;
} else if ( V_72 -> V_49 & V_94 ) {
V_72 -> V_142 [ 0 ] = V_72 -> V_142 [ 3 ] ;
}
if ( V_126 & V_144 )
V_72 -> error = - V_74 ;
else if ( ( V_126 & V_128 && V_72 -> V_49 & V_145 ) ||
V_126 & V_129 ||
V_126 & V_146 )
V_72 -> error = - V_131 ;
if ( V_2 -> V_9 && ( ! V_72 -> error || V_72 -> error == - V_131 ) ) {
if ( V_2 -> V_9 -> V_49 & V_103 ) {
if ( V_2 -> V_75 || ! V_2 -> V_118 )
F_1 ( V_2 , V_138 ) ;
else
F_57 ( & V_2 -> V_147 ) ;
} else {
if ( V_2 -> V_75 || ! V_2 -> V_117 )
F_1 ( V_2 , V_139 ) ;
else
F_57 ( & V_2 -> V_147 ) ;
}
} else {
F_53 ( & V_2 -> V_77 ) ;
}
V_127:
F_58 ( & V_2 -> V_68 ) ;
}
static bool F_60 ( struct V_1 * V_2 ,
int V_148 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_148 & ( V_107 | V_106 ) ) {
F_4 ( V_2 , V_107 |
V_106 ) ;
if ( ( ( ( V_148 & V_106 ) && V_38 -> V_149 ) ||
( ( V_148 & V_107 ) && ! V_38 -> V_149 ) ) &&
! F_61 ( & V_38 -> V_150 . V_64 ) )
F_62 ( V_2 -> V_38 , F_30 ( 100 ) ) ;
return true ;
}
return false ;
}
static bool F_63 ( struct V_1 * V_2 ,
int V_148 , int V_15 )
{
if ( V_148 & ( V_151 | V_144 ) ) {
F_4 ( V_2 ,
V_151 |
V_144 ) ;
F_59 ( V_2 , V_15 ) ;
return true ;
}
if ( V_148 & ( V_152 | V_153 ) ) {
F_4 ( V_2 , V_152 | V_153 ) ;
F_45 ( V_2 ) ;
return true ;
}
if ( V_148 & V_136 ) {
F_4 ( V_2 , V_136 ) ;
F_54 ( V_2 , V_15 ) ;
return true ;
}
return false ;
}
static void F_64 ( int V_154 , void * V_155 )
{
struct V_1 * V_2 = V_155 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_156 * V_48 = V_2 -> V_48 ;
unsigned int V_148 , V_15 ;
unsigned int V_157 ;
if ( ! ( V_48 -> V_49 & V_158 ) )
return;
V_15 = F_20 ( V_2 , V_159 ) ;
V_148 = V_15 & V_42 & ~ V_2 -> V_41 ;
V_157 = V_15 & ~ V_42 ;
if ( V_48 -> V_49 & V_160 )
V_157 |= 6 ;
F_16 ( V_2 , V_159 , V_157 ) ;
if ( V_38 -> V_161 & V_162 && V_148 & V_43 )
F_65 ( V_38 ) ;
}
T_3 F_66 ( int V_154 , void * V_155 )
{
struct V_1 * V_2 = V_155 ;
unsigned int V_148 , V_15 ;
V_15 = F_56 ( V_2 , V_7 ) ;
V_148 = V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( V_15 ) ;
F_8 ( V_148 ) ;
F_2 ( V_2 , V_7 , V_5 ) ;
if ( F_60 ( V_2 , V_148 , V_15 ) )
return V_163 ;
if ( F_63 ( V_2 , V_148 , V_15 ) )
return V_163 ;
F_64 ( V_154 , V_155 ) ;
return V_163 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_156 * V_48 = V_2 -> V_48 ;
F_9 ( L_13 ,
V_9 -> V_120 , V_9 -> V_98 ) ;
if ( V_2 -> V_38 -> V_164 . V_165 == V_166 ||
V_2 -> V_38 -> V_164 . V_165 == V_167 ) {
int V_168 = V_48 -> V_49 & V_169 ;
if ( V_9 -> V_120 < 2 || ( V_9 -> V_120 < 4 && ! V_168 ) ) {
F_46 ( L_14 ,
F_68 ( V_2 -> V_38 ) , V_9 -> V_120 ) ;
return - V_96 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_16 ( V_2 , V_170 , V_9 -> V_120 ) ;
F_16 ( V_2 , V_171 , V_9 -> V_98 ) ;
F_69 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_70 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
if ( V_2 -> V_172 )
V_2 -> V_172 ( V_2 ) ;
}
static int F_71 ( struct V_37 * V_38 , T_1 V_73 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
int V_3 , V_173 = 0 ;
if ( ! V_2 -> V_174 ) {
if ( ! V_2 -> V_175 || ! V_2 -> V_176 )
goto V_127;
V_2 -> V_174 = V_2 -> V_175 ( V_2 ) ;
if ( ! V_2 -> V_174 )
goto V_127;
}
if ( V_2 -> V_174 * 2 >= sizeof( V_2 -> V_177 ) * V_178 ) {
F_72 ( & V_2 -> V_59 -> V_71 ,
L_15 ) ;
goto V_127;
}
F_73 ( V_2 -> V_177 , V_2 -> V_174 * 2 ) ;
for ( V_3 = 0 ; V_3 < 2 * V_2 -> V_174 ; V_3 ++ ) {
if ( V_2 -> V_179 )
V_2 -> V_179 ( V_2 , V_3 % V_2 -> V_174 ) ;
V_173 = F_74 ( V_38 , V_73 , NULL ) ;
if ( V_173 && V_173 != - V_131 )
goto V_127;
if ( V_173 == 0 )
F_75 ( V_3 , V_2 -> V_177 ) ;
F_76 ( 1 ) ;
}
V_173 = V_2 -> V_176 ( V_2 ) ;
V_127:
if ( V_173 < 0 ) {
F_32 ( & V_2 -> V_59 -> V_71 , L_16 ) ;
F_70 ( V_38 ) ;
}
return V_173 ;
}
static void F_77 ( struct V_37 * V_38 , struct V_66 * V_67 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_49 ;
int V_173 ;
F_27 ( & V_2 -> V_68 , V_49 ) ;
if ( V_2 -> V_67 ) {
F_9 ( L_17 ) ;
if ( F_78 ( V_2 -> V_67 ) ) {
F_31 ( & V_2 -> V_68 , V_49 ) ;
V_67 -> V_72 -> error = - V_180 ;
F_34 ( V_38 , V_67 ) ;
return;
}
}
V_2 -> V_69 = V_181 ;
F_79 () ;
V_2 -> V_67 = V_67 ;
F_31 ( & V_2 -> V_68 , V_49 ) ;
if ( V_67 -> V_9 ) {
V_173 = F_67 ( V_2 , V_67 -> V_9 ) ;
if ( V_173 )
goto V_182;
}
V_173 = F_38 ( V_2 , V_67 -> V_72 ) ;
if ( ! V_173 ) {
F_80 ( & V_2 -> V_65 ,
F_30 ( V_70 ) ) ;
return;
}
V_182:
V_2 -> V_75 = false ;
V_2 -> V_67 = NULL ;
V_67 -> V_72 -> error = V_173 ;
F_34 ( V_38 , V_67 ) ;
}
static int F_81 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_183 )
return - V_184 ;
return V_2 -> V_183 ( V_2 ) ;
}
static void F_82 ( struct V_1 * V_2 , unsigned short V_185 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_173 = 0 ;
if ( V_2 -> V_186 )
V_2 -> V_186 ( V_2 -> V_59 , 1 ) ;
if ( ! F_78 ( V_38 -> V_187 . V_188 ) ) {
V_173 = F_83 ( V_38 , V_38 -> V_187 . V_188 , V_185 ) ;
F_84 ( 200 ) ;
}
if ( ! F_78 ( V_38 -> V_187 . V_189 ) && ! V_173 ) {
V_173 = F_85 ( V_38 -> V_187 . V_189 ) ;
F_84 ( 200 ) ;
}
if ( V_173 < 0 )
F_51 ( & V_2 -> V_59 -> V_71 , L_18 ,
V_173 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! F_78 ( V_38 -> V_187 . V_189 ) )
F_87 ( V_38 -> V_187 . V_189 ) ;
if ( ! F_78 ( V_38 -> V_187 . V_188 ) )
F_83 ( V_38 , V_38 -> V_187 . V_188 , 0 ) ;
if ( V_2 -> V_186 )
V_2 -> V_186 ( V_2 -> V_59 , 0 ) ;
}
static void F_88 ( struct V_1 * V_2 ,
unsigned char V_165 )
{
T_4 V_190 = F_20 ( V_2 , V_191 )
& ~ ( V_192 | V_193 ) ;
if ( V_165 == V_194 )
V_190 |= V_192 ;
else if ( V_165 == V_167 )
V_190 |= V_193 ;
F_16 ( V_2 , V_191 , V_190 ) ;
}
static void F_89 ( struct V_37 * V_38 , struct V_195 * V_164 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_196 * V_71 = & V_2 -> V_59 -> V_71 ;
unsigned long V_49 ;
F_90 ( & V_2 -> V_197 ) ;
F_27 ( & V_2 -> V_68 , V_49 ) ;
if ( V_2 -> V_67 ) {
if ( F_78 ( V_2 -> V_67 ) ) {
F_51 ( V_71 ,
L_19 ,
V_198 -> V_199 , F_91 ( V_198 ) ,
V_164 -> clock , V_164 -> V_200 ) ;
V_2 -> V_67 = F_92 ( - V_201 ) ;
} else {
F_51 ( V_71 ,
L_20 ,
V_198 -> V_199 , F_91 ( V_198 ) ,
V_2 -> V_67 -> V_72 -> V_73 , V_2 -> V_69 , V_181 ) ;
}
F_31 ( & V_2 -> V_68 , V_49 ) ;
F_93 ( & V_2 -> V_197 ) ;
return;
}
V_2 -> V_67 = F_92 ( - V_202 ) ;
F_31 ( & V_2 -> V_68 , V_49 ) ;
switch ( V_164 -> V_200 ) {
case V_203 :
F_86 ( V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_204 :
F_82 ( V_2 , V_164 -> V_185 ) ;
F_23 ( V_2 , V_164 -> clock ) ;
F_88 ( V_2 , V_164 -> V_165 ) ;
break;
case V_205 :
F_23 ( V_2 , V_164 -> clock ) ;
F_88 ( V_2 , V_164 -> V_165 ) ;
break;
}
F_84 ( 140 ) ;
if ( F_94 ( V_2 -> V_67 ) == - V_201 )
F_51 ( & V_2 -> V_59 -> V_71 ,
L_21 ,
V_198 -> V_199 , F_91 ( V_198 ) ,
V_164 -> clock , V_164 -> V_200 ) ;
V_2 -> V_67 = NULL ;
V_2 -> V_206 = V_164 -> clock ;
F_93 ( & V_2 -> V_197 ) ;
}
static int F_95 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_156 * V_48 = V_2 -> V_48 ;
int V_173 = F_96 ( V_38 ) ;
if ( V_173 >= 0 )
return V_173 ;
V_173 = ! ( ( V_48 -> V_49 & V_207 ) ||
( F_56 ( V_2 , V_7 ) & V_208 ) ) ;
return V_173 ;
}
static int F_97 ( struct V_209 * V_149 ,
unsigned int V_210 , int V_211 )
{
struct V_1 * V_2 = F_13 ( V_149 -> V_2 ) ;
if ( V_2 -> V_212 )
return V_2 -> V_212 ( V_149 , V_210 , V_211 ) ;
return V_211 ;
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_156 * V_48 = V_2 -> V_48 ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_99 ( V_38 ) ;
if ( ! V_38 -> V_213 )
V_38 -> V_213 = V_48 -> V_214 ;
if ( ! V_38 -> V_213 )
return - V_215 ;
return 0 ;
}
static void F_100 ( struct V_216 * V_59 ,
struct V_156 * V_48 )
{
const struct V_217 * V_218 = V_59 -> V_71 . V_219 ;
if ( ! V_218 )
return;
if ( F_101 ( V_218 , L_22 , NULL ) )
V_48 -> V_49 |= V_207 ;
}
struct V_1 *
F_102 ( struct V_216 * V_59 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
V_38 = F_103 ( sizeof( struct V_1 ) , & V_59 -> V_71 ) ;
if ( ! V_38 )
return NULL ;
V_2 = F_13 ( V_38 ) ;
V_2 -> V_38 = V_38 ;
V_2 -> V_59 = V_59 ;
return V_2 ;
}
void F_104 ( struct V_1 * V_2 )
{
F_105 ( V_2 -> V_38 ) ;
}
int F_106 ( struct V_1 * V_220 ,
struct V_156 * V_48 )
{
struct V_216 * V_59 = V_220 -> V_59 ;
struct V_37 * V_38 = V_220 -> V_38 ;
struct V_221 * V_222 ;
int V_173 ;
T_1 V_80 = V_81 ;
F_100 ( V_59 , V_48 ) ;
if ( ! ( V_48 -> V_49 & V_133 ) )
V_220 -> V_223 = NULL ;
V_222 = F_107 ( V_59 , V_224 , 0 ) ;
if ( ! V_222 )
return - V_96 ;
V_173 = F_108 ( V_38 ) ;
if ( V_173 < 0 )
goto V_225;
V_220 -> V_48 = V_48 ;
F_109 ( V_59 , V_38 ) ;
V_220 -> V_186 = V_48 -> V_186 ;
V_220 -> V_58 = V_48 -> V_58 ;
V_173 = F_98 ( V_220 ) ;
if ( V_173 < 0 )
goto V_225;
V_220 -> V_226 = F_110 ( & V_59 -> V_71 ,
V_222 -> V_227 , F_111 ( V_222 ) ) ;
if ( ! V_220 -> V_226 ) {
V_173 = - V_228 ;
goto V_225;
}
V_229 . V_230 = V_220 -> V_230 ;
V_229 . V_231 = V_220 -> V_231 ;
V_38 -> V_232 = & V_229 ;
V_38 -> V_161 |= V_233 | V_48 -> V_234 ;
V_38 -> V_235 |= V_48 -> V_236 ;
V_38 -> V_237 = 32 ;
V_38 -> V_238 = 512 ;
V_38 -> V_239 = ( V_240 / V_38 -> V_238 ) *
V_38 -> V_237 ;
V_38 -> V_241 = V_38 -> V_238 * V_38 -> V_239 ;
V_38 -> V_242 = V_38 -> V_241 ;
V_220 -> V_105 = ! ( V_48 -> V_49 & V_243 ||
V_38 -> V_161 & V_244 ||
! F_112 ( V_38 ) ||
V_38 -> V_245 . V_246 >= 0 ) ;
if ( V_48 -> V_49 & V_50 )
V_220 -> V_105 = true ;
if ( F_81 ( V_220 ) < 0 ) {
V_38 -> V_247 = V_48 -> V_248 ;
V_38 -> V_56 = V_38 -> V_247 / 512 ;
}
if ( V_38 -> V_56 == 0 ) {
V_173 = - V_96 ;
goto V_225;
}
if ( V_220 -> V_105 )
F_113 ( & V_59 -> V_71 ) ;
F_22 ( V_220 ) ;
F_24 ( V_220 ) ;
V_220 -> V_4 = F_56 ( V_220 , V_6 ) ;
F_3 ( V_220 , V_249 ) ;
if ( ! V_220 -> V_118 )
V_80 |= V_138 ;
if ( ! V_220 -> V_117 )
V_80 |= V_139 ;
if ( ! V_220 -> V_105 )
V_80 &= ~ ( V_106 | V_107 ) ;
V_220 -> V_4 &= ~ V_80 ;
V_220 -> V_40 = false ;
if ( V_48 -> V_49 & V_158 ) {
V_220 -> V_41 = V_42 ;
F_16 ( V_220 , V_45 , V_220 -> V_41 ) ;
F_16 ( V_220 , V_44 , 0x0000 ) ;
}
F_114 ( & V_220 -> V_68 ) ;
F_115 ( & V_220 -> V_197 ) ;
F_116 ( & V_220 -> V_65 , F_25 ) ;
F_117 ( & V_220 -> V_77 , F_37 ) ;
F_118 ( V_220 , V_48 ) ;
F_119 ( & V_59 -> V_71 ) ;
F_120 ( & V_59 -> V_71 , 50 ) ;
F_121 ( & V_59 -> V_71 ) ;
F_122 ( & V_59 -> V_71 ) ;
V_173 = F_123 ( V_38 ) ;
if ( V_173 < 0 ) {
F_124 ( V_220 ) ;
return V_173 ;
}
F_125 ( & V_59 -> V_71 , 100 ) ;
if ( V_48 -> V_49 & V_243 ) {
V_173 = F_126 ( V_38 , V_48 -> V_250 , 0 ) ;
if ( V_173 < 0 ) {
F_124 ( V_220 ) ;
return V_173 ;
}
F_127 ( V_38 ) ;
}
return 0 ;
V_225:
return V_173 ;
}
void F_124 ( struct V_1 * V_2 )
{
struct V_216 * V_59 = V_2 -> V_59 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! V_2 -> V_105 )
F_14 ( & V_59 -> V_71 ) ;
F_128 ( & V_59 -> V_71 ) ;
F_129 ( V_38 ) ;
F_130 ( & V_2 -> V_77 ) ;
F_131 ( & V_2 -> V_65 ) ;
F_132 ( V_2 ) ;
F_133 ( & V_59 -> V_71 ) ;
F_134 ( & V_59 -> V_71 ) ;
}
int F_135 ( struct V_196 * V_71 )
{
struct V_37 * V_38 = F_136 ( V_71 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_3 ( V_2 , V_249 ) ;
if ( V_2 -> V_206 )
F_22 ( V_2 ) ;
if ( V_2 -> V_251 )
V_2 -> V_251 ( V_2 ) ;
return 0 ;
}
static bool F_137 ( struct V_1 * V_2 )
{
return V_2 -> V_174 && F_138 ( V_2 -> V_38 ) ;
}
int F_139 ( struct V_196 * V_71 )
{
struct V_37 * V_38 = F_136 ( V_71 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_24 ( V_2 ) ;
F_81 ( V_2 ) ;
if ( V_2 -> V_206 )
F_23 ( V_2 , V_2 -> V_206 ) ;
F_140 ( V_2 , true ) ;
if ( F_137 ( V_2 ) && V_2 -> V_176 ( V_2 ) )
F_32 ( & V_2 -> V_59 -> V_71 , L_23 ) ;
return 0 ;
}

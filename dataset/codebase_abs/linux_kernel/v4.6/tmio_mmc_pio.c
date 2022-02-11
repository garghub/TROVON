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
static void F_19 ( struct V_1 * V_2 ,
unsigned int V_46 )
{
T_1 V_47 = 0 , clock ;
if ( V_46 ) {
for ( clock = V_2 -> V_38 -> V_48 , V_47 = 0x80000080 ;
V_46 >= ( clock << 1 ) ;
V_47 >>= 1 )
clock <<= 1 ;
if ( ( V_2 -> V_49 -> V_50 & V_51 ) &&
( ( V_47 >> 22 ) & 0x1 ) )
V_47 |= 0xff ;
}
if ( V_2 -> V_52 )
V_2 -> V_52 ( V_2 -> V_53 , ( V_47 >> 22 ) & 1 ) ;
F_16 ( V_2 , V_54 , ~ V_55 &
F_20 ( V_2 , V_54 ) ) ;
F_16 ( V_2 , V_54 , V_47 & V_56 ) ;
if ( ! ( V_2 -> V_49 -> V_50 & V_57 ) )
F_21 ( 10 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 -> V_50 & V_58 ) {
F_16 ( V_2 , V_59 , 0x0000 ) ;
F_21 ( 10 ) ;
}
F_16 ( V_2 , V_54 , ~ V_55 &
F_20 ( V_2 , V_54 ) ) ;
F_21 ( V_2 -> V_49 -> V_50 & V_57 ? 5 : 10 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_54 , V_55 |
F_20 ( V_2 , V_54 ) ) ;
F_21 ( V_2 -> V_49 -> V_50 & V_57 ? 1 : 10 ) ;
if ( V_2 -> V_49 -> V_50 & V_58 ) {
F_16 ( V_2 , V_59 , 0x0100 ) ;
F_21 ( 10 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_60 , 0x0000 ) ;
if ( V_2 -> V_49 -> V_50 & V_58 )
F_16 ( V_2 , V_61 , 0x0000 ) ;
F_21 ( 10 ) ;
F_16 ( V_2 , V_60 , 0x0001 ) ;
if ( V_2 -> V_49 -> V_50 & V_58 )
F_16 ( V_2 , V_61 , 0x0001 ) ;
F_21 ( 10 ) ;
}
static void F_25 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_26 ( V_63 , struct V_1 ,
V_64 . V_63 ) ;
struct V_65 * V_66 ;
unsigned long V_50 ;
F_27 ( & V_2 -> V_67 , V_50 ) ;
V_66 = V_2 -> V_66 ;
if ( F_28 ( V_66 )
|| F_29 ( V_2 -> V_68 +
F_30 ( V_69 ) ) ) {
F_31 ( & V_2 -> V_67 , V_50 ) ;
return;
}
F_32 ( & V_2 -> V_53 -> V_70 ,
L_3 ,
V_66 -> V_71 -> V_72 ) ;
if ( V_2 -> V_9 )
V_2 -> V_9 -> error = - V_73 ;
else if ( V_2 -> V_71 )
V_2 -> V_71 -> error = - V_73 ;
else
V_66 -> V_71 -> error = - V_73 ;
V_2 -> V_71 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_74 = false ;
F_31 ( & V_2 -> V_67 , V_50 ) ;
F_24 ( V_2 ) ;
V_2 -> V_66 = NULL ;
F_33 ( V_2 ) ;
F_34 ( V_2 -> V_38 , V_66 ) ;
F_17 ( F_15 ( V_2 -> V_38 ) ) ;
F_18 ( F_15 ( V_2 -> V_38 ) ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_65 * V_66 ;
unsigned long V_50 ;
F_27 ( & V_2 -> V_67 , V_50 ) ;
V_66 = V_2 -> V_66 ;
if ( F_28 ( V_66 ) ) {
F_31 ( & V_2 -> V_67 , V_50 ) ;
return;
}
V_2 -> V_71 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_74 = false ;
F_36 ( & V_2 -> V_64 ) ;
V_2 -> V_66 = NULL ;
F_31 ( & V_2 -> V_67 , V_50 ) ;
if ( V_66 -> V_71 -> error || ( V_66 -> V_9 && V_66 -> V_9 -> error ) )
F_33 ( V_2 ) ;
F_34 ( V_2 -> V_38 , V_66 ) ;
F_17 ( F_15 ( V_2 -> V_38 ) ) ;
F_18 ( F_15 ( V_2 -> V_38 ) ) ;
}
static void F_37 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_26 ( V_63 , struct V_1 ,
V_75 ) ;
F_35 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_76 * V_71 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_77 = V_71 -> V_72 ;
T_1 V_78 = V_79 ;
if ( V_71 -> V_72 == V_80 && ! V_71 -> V_81 ) {
F_16 ( V_2 , V_82 , 0x001 ) ;
return 0 ;
}
switch ( F_39 ( V_71 ) ) {
case V_83 : V_77 |= V_84 ; break;
case V_85 : V_77 |= V_86 ; break;
case V_87 : V_77 |= V_88 ; break;
case V_89 : V_77 |= V_90 ; break;
case V_91 : V_77 |= V_92 ; break;
default:
F_9 ( L_4 , F_39 ( V_71 ) ) ;
return - V_93 ;
}
V_2 -> V_71 = V_71 ;
if ( V_9 ) {
V_77 |= V_94 ;
if ( V_9 -> V_95 > 1 ) {
F_16 ( V_2 , V_82 , 0x100 ) ;
V_77 |= V_96 ;
if ( ( V_2 -> V_49 -> V_50 & V_97 ) &&
( V_71 -> V_72 == V_98 ) )
V_77 |= V_99 ;
}
if ( V_9 -> V_50 & V_100 )
V_77 |= V_101 ;
}
if ( ! V_2 -> V_102 )
V_78 &= ~ ( V_103 | V_104 ) ;
F_1 ( V_2 , V_78 ) ;
F_2 ( V_2 , V_105 , V_71 -> V_81 ) ;
F_16 ( V_2 , V_106 , V_77 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned short * V_107 ,
unsigned int V_108 )
{
int V_109 = V_2 -> V_9 -> V_50 & V_100 ;
T_2 * V_110 ;
if ( V_109 )
F_41 ( V_2 , V_111 , V_107 , V_108 >> 1 ) ;
else
F_42 ( V_2 , V_111 , V_107 , V_108 >> 1 ) ;
if ( ! ( V_108 & 0x1 ) )
return;
V_110 = ( T_2 * ) ( V_107 + ( V_108 >> 1 ) ) ;
if ( V_109 )
* V_110 = F_20 ( V_2 , V_111 ) & 0xff ;
else
F_16 ( V_2 , V_111 , * V_110 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_112 ;
unsigned short * V_107 ;
unsigned int V_108 ;
unsigned long V_50 ;
if ( ( V_2 -> V_113 || V_2 -> V_114 ) && ! V_2 -> V_74 ) {
F_44 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_112 = F_45 ( V_2 -> V_11 , & V_50 ) ;
V_107 = ( unsigned short * ) ( V_112 + V_2 -> V_14 ) ;
V_108 = V_2 -> V_11 -> V_115 - V_2 -> V_14 ;
if ( V_108 > V_9 -> V_116 )
V_108 = V_9 -> V_116 ;
F_9 ( L_7 ,
V_108 , V_2 -> V_14 , V_9 -> V_50 ) ;
F_40 ( V_2 , V_107 , V_108 ) ;
V_2 -> V_14 += V_108 ;
F_46 ( V_2 -> V_11 , & V_50 , V_112 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_115 )
F_6 ( V_2 ) ;
return;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_117 ) {
unsigned long V_50 ;
void * V_118 = F_45 ( V_2 -> V_13 , & V_50 ) ;
memcpy ( V_118 , V_2 -> V_119 , V_2 -> V_117 . V_115 ) ;
F_46 ( V_2 -> V_13 , & V_50 , V_118 ) ;
}
}
void F_48 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_76 * V_120 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_32 ( & V_2 -> V_53 -> V_70 , L_8 ) ;
return;
}
V_120 = V_9 -> V_120 ;
if ( ! V_9 -> error )
V_9 -> V_121 = V_9 -> V_95 * V_9 -> V_116 ;
else
V_9 -> V_121 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_50 & V_100 ) {
if ( V_2 -> V_114 && ! V_2 -> V_74 )
F_47 ( V_2 ) ;
F_49 ( & V_2 -> V_53 -> V_70 , L_10 ,
V_2 -> V_66 ) ;
} else {
F_49 ( & V_2 -> V_53 -> V_70 , L_11 ,
V_2 -> V_66 ) ;
}
if ( V_120 ) {
if ( V_120 -> V_72 == V_80 && ! V_120 -> V_81 )
F_16 ( V_2 , V_82 , 0x000 ) ;
else
F_50 () ;
}
F_51 ( & V_2 -> V_75 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_53 ( & V_2 -> V_67 ) ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 )
goto V_122;
if ( V_2 -> V_113 && ( V_9 -> V_50 & V_123 ) && ! V_2 -> V_74 ) {
T_1 V_15 = F_54 ( V_2 , V_7 ) ;
bool V_75 = false ;
if ( V_2 -> V_49 -> V_50 & V_124 ) {
if ( V_15 & V_125 )
V_75 = true ;
} else {
if ( ! ( V_15 & V_126 ) )
V_75 = true ;
}
if ( V_75 ) {
F_3 ( V_2 , V_127 ) ;
F_55 ( & V_2 -> V_128 ) ;
}
} else if ( V_2 -> V_114 && ( V_9 -> V_50 & V_100 ) && ! V_2 -> V_74 ) {
F_3 ( V_2 , V_127 ) ;
F_55 ( & V_2 -> V_128 ) ;
} else {
F_48 ( V_2 ) ;
F_3 ( V_2 , V_129 | V_130 ) ;
}
V_122:
F_56 ( & V_2 -> V_67 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_131 )
{
struct V_76 * V_71 = V_2 -> V_71 ;
int V_3 , V_132 ;
F_53 ( & V_2 -> V_67 ) ;
if ( ! V_2 -> V_71 ) {
F_9 ( L_12 ) ;
goto V_122;
}
V_2 -> V_71 = NULL ;
for ( V_3 = 3 , V_132 = V_133 ; V_3 >= 0 ; V_3 -- , V_132 += 4 )
V_71 -> V_134 [ V_3 ] = F_54 ( V_2 , V_132 ) ;
if ( V_71 -> V_50 & V_135 ) {
V_71 -> V_134 [ 0 ] = ( V_71 -> V_134 [ 0 ] << 8 ) | ( V_71 -> V_134 [ 1 ] >> 24 ) ;
V_71 -> V_134 [ 1 ] = ( V_71 -> V_134 [ 1 ] << 8 ) | ( V_71 -> V_134 [ 2 ] >> 24 ) ;
V_71 -> V_134 [ 2 ] = ( V_71 -> V_134 [ 2 ] << 8 ) | ( V_71 -> V_134 [ 3 ] >> 24 ) ;
V_71 -> V_134 [ 3 ] <<= 8 ;
} else if ( V_71 -> V_50 & V_91 ) {
V_71 -> V_134 [ 0 ] = V_71 -> V_134 [ 3 ] ;
}
if ( V_131 & V_136 )
V_71 -> error = - V_73 ;
else if ( V_131 & V_137 && V_71 -> V_50 & V_138 )
V_71 -> error = - V_139 ;
if ( V_2 -> V_9 && ! V_71 -> error ) {
if ( V_2 -> V_9 -> V_50 & V_100 ) {
if ( V_2 -> V_74 || ! V_2 -> V_114 )
F_1 ( V_2 , V_129 ) ;
else
F_55 ( & V_2 -> V_140 ) ;
} else {
if ( V_2 -> V_74 || ! V_2 -> V_113 )
F_1 ( V_2 , V_130 ) ;
else
F_55 ( & V_2 -> V_140 ) ;
}
} else {
F_51 ( & V_2 -> V_75 ) ;
}
V_122:
F_56 ( & V_2 -> V_67 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
int * V_141 , int * V_15 )
{
* V_15 = F_54 ( V_2 , V_7 ) ;
* V_141 = * V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( * V_15 ) ;
F_8 ( * V_141 ) ;
F_2 ( V_2 , V_7 , V_5 ) ;
}
static bool F_59 ( struct V_1 * V_2 ,
int V_141 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_141 & ( V_104 | V_103 ) ) {
F_4 ( V_2 , V_104 |
V_103 ) ;
if ( ( ( ( V_141 & V_103 ) && V_38 -> V_142 ) ||
( ( V_141 & V_104 ) && ! V_38 -> V_142 ) ) &&
! F_60 ( & V_38 -> V_143 . V_63 ) )
F_61 ( V_2 -> V_38 , F_30 ( 100 ) ) ;
return true ;
}
return false ;
}
T_3 F_62 ( int V_144 , void * V_145 )
{
unsigned int V_141 , V_15 ;
struct V_1 * V_2 = V_145 ;
F_58 ( V_2 , & V_141 , & V_15 ) ;
F_59 ( V_2 , V_141 , V_15 ) ;
return V_146 ;
}
static bool F_63 ( struct V_1 * V_2 ,
int V_141 , int V_15 )
{
if ( V_141 & ( V_147 | V_136 ) ) {
F_4 ( V_2 ,
V_147 |
V_136 ) ;
F_57 ( V_2 , V_15 ) ;
return true ;
}
if ( V_141 & ( V_148 | V_149 ) ) {
F_4 ( V_2 , V_148 | V_149 ) ;
F_43 ( V_2 ) ;
return true ;
}
if ( V_141 & V_127 ) {
F_4 ( V_2 , V_127 ) ;
F_52 ( V_2 ) ;
return true ;
}
return false ;
}
T_3 F_64 ( int V_144 , void * V_145 )
{
unsigned int V_141 , V_15 ;
struct V_1 * V_2 = V_145 ;
F_58 ( V_2 , & V_141 , & V_15 ) ;
F_63 ( V_2 , V_141 , V_15 ) ;
return V_146 ;
}
T_3 F_65 ( int V_144 , void * V_145 )
{
struct V_1 * V_2 = V_145 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_150 * V_49 = V_2 -> V_49 ;
unsigned int V_141 , V_15 ;
unsigned int V_151 ;
if ( ! ( V_49 -> V_50 & V_152 ) )
return V_146 ;
V_15 = F_20 ( V_2 , V_153 ) ;
V_141 = V_15 & V_42 & ~ V_2 -> V_4 ;
V_151 = V_15 & ~ V_42 ;
if ( V_49 -> V_50 & V_154 )
V_151 |= 6 ;
F_16 ( V_2 , V_153 , V_151 ) ;
if ( V_38 -> V_155 & V_156 && V_141 & V_43 )
F_66 ( V_38 ) ;
return V_146 ;
}
T_3 F_67 ( int V_144 , void * V_145 )
{
struct V_1 * V_2 = V_145 ;
unsigned int V_141 , V_15 ;
F_9 ( L_13 ) ;
F_58 ( V_2 , & V_141 , & V_15 ) ;
if ( F_59 ( V_2 , V_141 , V_15 ) )
return V_146 ;
if ( F_63 ( V_2 , V_141 , V_15 ) )
return V_146 ;
F_65 ( V_144 , V_145 ) ;
return V_146 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_150 * V_49 = V_2 -> V_49 ;
F_9 ( L_14 ,
V_9 -> V_116 , V_9 -> V_95 ) ;
if ( V_2 -> V_38 -> V_157 . V_158 == V_159 ) {
int V_160 = V_49 -> V_50 & V_161 ;
if ( V_9 -> V_116 < 2 || ( V_9 -> V_116 < 4 && ! V_160 ) ) {
F_44 ( L_15 ,
F_69 ( V_2 -> V_38 ) , V_9 -> V_116 ) ;
return - V_93 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_16 ( V_2 , V_162 , V_9 -> V_116 ) ;
F_16 ( V_2 , V_163 , V_9 -> V_95 ) ;
F_70 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_71 ( struct V_37 * V_38 , struct V_65 * V_66 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_50 ;
int V_164 ;
F_27 ( & V_2 -> V_67 , V_50 ) ;
if ( V_2 -> V_66 ) {
F_9 ( L_16 ) ;
if ( F_72 ( V_2 -> V_66 ) ) {
F_31 ( & V_2 -> V_67 , V_50 ) ;
V_66 -> V_71 -> error = - V_165 ;
F_34 ( V_38 , V_66 ) ;
return;
}
}
V_2 -> V_68 = V_166 ;
F_73 () ;
V_2 -> V_66 = V_66 ;
F_31 ( & V_2 -> V_67 , V_50 ) ;
F_14 ( F_15 ( V_38 ) ) ;
if ( V_66 -> V_9 ) {
V_164 = F_68 ( V_2 , V_66 -> V_9 ) ;
if ( V_164 )
goto V_167;
}
V_164 = F_38 ( V_2 , V_66 -> V_71 ) ;
if ( ! V_164 ) {
F_74 ( & V_2 -> V_64 ,
F_30 ( V_69 ) ) ;
return;
}
V_167:
V_2 -> V_74 = false ;
V_2 -> V_66 = NULL ;
V_66 -> V_71 -> error = V_164 ;
F_34 ( V_38 , V_66 ) ;
F_17 ( F_15 ( V_38 ) ) ;
F_18 ( F_15 ( V_38 ) ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_164 ;
if ( ! V_2 -> V_168 )
return - V_169 ;
V_164 = V_2 -> V_168 ( V_2 -> V_53 , & V_38 -> V_170 ) ;
if ( ! V_164 )
V_38 -> V_48 = V_38 -> V_170 / 512 ;
return V_164 ;
}
static void F_76 ( struct V_1 * V_2 , unsigned short V_171 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_164 = 0 ;
if ( V_2 -> V_172 )
V_2 -> V_172 ( V_2 -> V_53 , 1 ) ;
if ( ! F_72 ( V_38 -> V_173 . V_174 ) ) {
V_164 = F_77 ( V_38 , V_38 -> V_173 . V_174 , V_171 ) ;
F_78 ( 200 ) ;
}
if ( ! F_72 ( V_38 -> V_173 . V_175 ) && ! V_164 ) {
V_164 = F_79 ( V_38 -> V_173 . V_175 ) ;
F_78 ( 200 ) ;
}
if ( V_164 < 0 )
F_49 ( & V_2 -> V_53 -> V_70 , L_17 ,
V_164 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! F_72 ( V_38 -> V_173 . V_175 ) )
F_81 ( V_38 -> V_173 . V_175 ) ;
if ( ! F_72 ( V_38 -> V_173 . V_174 ) )
F_77 ( V_38 , V_38 -> V_173 . V_174 , 0 ) ;
if ( V_2 -> V_172 )
V_2 -> V_172 ( V_2 -> V_53 , 0 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
unsigned char V_158 )
{
switch ( V_158 ) {
case V_176 :
F_16 ( V_2 , V_177 , 0x80e0 ) ;
break;
case V_159 :
F_16 ( V_2 , V_177 , 0x00e0 ) ;
break;
}
}
static void F_83 ( struct V_37 * V_38 , struct V_178 * V_157 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_179 * V_70 = & V_2 -> V_53 -> V_70 ;
unsigned long V_50 ;
F_14 ( F_15 ( V_38 ) ) ;
F_84 ( & V_2 -> V_180 ) ;
F_27 ( & V_2 -> V_67 , V_50 ) ;
if ( V_2 -> V_66 ) {
if ( F_72 ( V_2 -> V_66 ) ) {
F_49 ( V_70 ,
L_18 ,
V_181 -> V_182 , F_85 ( V_181 ) ,
V_157 -> clock , V_157 -> V_183 ) ;
V_2 -> V_66 = F_86 ( - V_184 ) ;
} else {
F_49 ( V_70 ,
L_19 ,
V_181 -> V_182 , F_85 ( V_181 ) ,
V_2 -> V_66 -> V_71 -> V_72 , V_2 -> V_68 , V_166 ) ;
}
F_31 ( & V_2 -> V_67 , V_50 ) ;
F_87 ( & V_2 -> V_180 ) ;
return;
}
V_2 -> V_66 = F_86 ( - V_185 ) ;
F_31 ( & V_2 -> V_67 , V_50 ) ;
switch ( V_157 -> V_183 ) {
case V_186 :
F_80 ( V_2 ) ;
F_22 ( V_2 ) ;
break;
case V_187 :
F_19 ( V_2 , V_157 -> clock ) ;
F_76 ( V_2 , V_157 -> V_171 ) ;
F_23 ( V_2 ) ;
F_82 ( V_2 , V_157 -> V_158 ) ;
break;
case V_188 :
F_19 ( V_2 , V_157 -> clock ) ;
F_23 ( V_2 ) ;
F_82 ( V_2 , V_157 -> V_158 ) ;
break;
}
F_78 ( 140 ) ;
if ( F_88 ( V_2 -> V_66 ) == - V_184 )
F_49 ( & V_2 -> V_53 -> V_70 ,
L_20 ,
V_181 -> V_182 , F_85 ( V_181 ) ,
V_157 -> clock , V_157 -> V_183 ) ;
V_2 -> V_66 = NULL ;
V_2 -> V_189 = V_157 -> clock ;
F_87 ( & V_2 -> V_180 ) ;
F_17 ( F_15 ( V_38 ) ) ;
F_18 ( F_15 ( V_38 ) ) ;
}
static int F_89 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_150 * V_49 = V_2 -> V_49 ;
int V_164 = F_90 ( V_38 ) ;
if ( V_164 >= 0 )
return V_164 ;
F_14 ( F_15 ( V_38 ) ) ;
V_164 = ! ( ( V_49 -> V_50 & V_190 ) ||
( F_54 ( V_2 , V_7 ) & V_191 ) ) ;
F_17 ( F_15 ( V_38 ) ) ;
F_18 ( F_15 ( V_38 ) ) ;
return V_164 ;
}
static int F_91 ( struct V_192 * V_142 ,
unsigned int V_193 , int V_194 )
{
struct V_1 * V_2 = F_13 ( V_142 -> V_2 ) ;
if ( V_2 -> V_195 )
return V_2 -> V_195 ( V_142 , V_193 , V_194 ) ;
return V_194 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_150 * V_49 = V_2 -> V_49 ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_93 ( V_38 ) ;
if ( ! V_38 -> V_196 )
V_38 -> V_196 = V_49 -> V_197 ;
if ( ! V_38 -> V_196 )
return - V_198 ;
return 0 ;
}
static void F_94 ( struct V_199 * V_53 ,
struct V_150 * V_49 )
{
const struct V_200 * V_201 = V_53 -> V_70 . V_202 ;
if ( ! V_201 )
return;
if ( F_95 ( V_201 , L_21 , NULL ) )
V_49 -> V_50 |= V_190 ;
}
struct V_1 *
F_96 ( struct V_199 * V_53 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
V_38 = F_97 ( sizeof( struct V_1 ) , & V_53 -> V_70 ) ;
if ( ! V_38 )
return NULL ;
V_2 = F_13 ( V_38 ) ;
V_2 -> V_38 = V_38 ;
V_2 -> V_53 = V_53 ;
return V_2 ;
}
void F_98 ( struct V_1 * V_2 )
{
F_99 ( V_2 -> V_38 ) ;
}
int F_100 ( struct V_1 * V_203 ,
struct V_150 * V_49 )
{
struct V_199 * V_53 = V_203 -> V_53 ;
struct V_37 * V_38 = V_203 -> V_38 ;
struct V_204 * V_205 ;
int V_164 ;
T_1 V_78 = V_79 ;
F_94 ( V_53 , V_49 ) ;
if ( ! ( V_49 -> V_50 & V_124 ) )
V_203 -> V_206 = NULL ;
V_205 = F_101 ( V_53 , V_207 , 0 ) ;
if ( ! V_205 )
return - V_93 ;
V_164 = F_102 ( V_38 ) ;
if ( V_164 < 0 )
goto V_208;
V_203 -> V_49 = V_49 ;
F_103 ( V_53 , V_38 ) ;
V_203 -> V_172 = V_49 -> V_172 ;
V_203 -> V_52 = V_49 -> V_52 ;
V_164 = F_92 ( V_203 ) ;
if ( V_164 < 0 )
goto V_208;
V_203 -> V_209 = F_104 ( & V_53 -> V_70 ,
V_205 -> V_210 , F_105 ( V_205 ) ) ;
if ( ! V_203 -> V_209 ) {
V_164 = - V_211 ;
goto V_208;
}
V_38 -> V_212 = & V_213 ;
V_38 -> V_155 |= V_214 | V_49 -> V_215 ;
V_38 -> V_216 |= V_49 -> V_217 ;
V_38 -> V_218 = 32 ;
V_38 -> V_219 = 512 ;
V_38 -> V_220 = ( V_221 / V_38 -> V_219 ) *
V_38 -> V_218 ;
V_38 -> V_222 = V_38 -> V_219 * V_38 -> V_220 ;
V_38 -> V_223 = V_38 -> V_222 ;
V_203 -> V_102 = ! ( V_49 -> V_50 & V_224 ||
V_38 -> V_155 & V_225 ||
V_38 -> V_155 & V_226 ||
V_38 -> V_227 . V_228 >= 0 ) ;
if ( F_75 ( V_203 ) < 0 ) {
V_38 -> V_170 = V_49 -> V_229 ;
V_38 -> V_48 = V_38 -> V_170 / 512 ;
}
if ( V_38 -> V_48 == 0 ) {
V_164 = - V_93 ;
goto V_208;
}
if ( V_203 -> V_102 )
F_106 ( & V_53 -> V_70 ) ;
F_22 ( V_203 ) ;
F_24 ( V_203 ) ;
V_203 -> V_4 = F_54 ( V_203 , V_6 ) ;
F_3 ( V_203 , V_230 ) ;
if ( ! V_203 -> V_114 )
V_78 |= V_129 ;
if ( ! V_203 -> V_113 )
V_78 |= V_130 ;
if ( ! V_203 -> V_102 )
V_78 &= ~ ( V_103 | V_104 ) ;
V_203 -> V_4 &= ~ V_78 ;
V_203 -> V_40 = false ;
if ( V_49 -> V_50 & V_152 ) {
V_203 -> V_41 = V_42 ;
F_16 ( V_203 , V_45 , V_203 -> V_41 ) ;
F_16 ( V_203 , V_44 , 0x0000 ) ;
}
F_107 ( & V_203 -> V_67 ) ;
F_108 ( & V_203 -> V_180 ) ;
F_109 ( & V_203 -> V_64 , F_25 ) ;
F_110 ( & V_203 -> V_75 , F_37 ) ;
F_111 ( V_203 , V_49 ) ;
F_112 ( & V_53 -> V_70 ) ;
F_113 ( & V_53 -> V_70 , 50 ) ;
F_114 ( & V_53 -> V_70 ) ;
F_115 ( & V_53 -> V_70 ) ;
V_164 = F_116 ( V_38 ) ;
if ( V_164 < 0 ) {
F_117 ( V_203 ) ;
return V_164 ;
}
F_118 ( & V_53 -> V_70 , 100 ) ;
if ( V_49 -> V_50 & V_224 ) {
V_164 = F_119 ( V_38 , V_49 -> V_231 , 0 ) ;
if ( V_164 < 0 ) {
F_117 ( V_203 ) ;
return V_164 ;
}
F_120 ( V_38 ) ;
}
return 0 ;
V_208:
return V_164 ;
}
void F_117 ( struct V_1 * V_2 )
{
struct V_199 * V_53 = V_2 -> V_53 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! V_2 -> V_102 )
F_14 ( & V_53 -> V_70 ) ;
F_121 ( & V_53 -> V_70 ) ;
F_122 ( V_38 ) ;
F_123 ( & V_2 -> V_75 ) ;
F_124 ( & V_2 -> V_64 ) ;
F_125 ( V_2 ) ;
F_126 ( & V_53 -> V_70 ) ;
F_127 ( & V_53 -> V_70 ) ;
}
int F_128 ( struct V_179 * V_70 )
{
struct V_37 * V_38 = F_129 ( V_70 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_3 ( V_2 , V_230 ) ;
if ( V_2 -> V_189 )
F_22 ( V_2 ) ;
if ( V_2 -> V_232 )
V_2 -> V_232 ( V_2 -> V_53 ) ;
return 0 ;
}
int F_130 ( struct V_179 * V_70 )
{
struct V_37 * V_38 = F_129 ( V_70 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_24 ( V_2 ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_189 ) {
F_19 ( V_2 , V_2 -> V_189 ) ;
F_23 ( V_2 ) ;
}
F_131 ( V_2 , true ) ;
return 0 ;
}

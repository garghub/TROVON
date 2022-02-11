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
V_46 >= ( clock << 1 ) ; V_47 >>= 1 )
clock <<= 1 ;
if ( ( V_2 -> V_49 -> V_50 & V_51 ) &&
( ( V_47 >> 22 ) & 0x1 ) )
V_47 |= 0xff ;
}
if ( V_2 -> V_52 )
V_2 -> V_52 ( V_2 -> V_53 , ( V_47 >> 22 ) & 1 ) ;
F_16 ( V_2 , V_54 , V_47 & 0x1ff ) ;
F_20 ( 10 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 -> V_50 & V_55 ) {
F_16 ( V_2 , V_56 , 0x0000 ) ;
F_20 ( 10 ) ;
}
F_16 ( V_2 , V_54 , ~ 0x0100 &
F_22 ( V_2 , V_54 ) ) ;
F_20 ( 10 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_54 , 0x0100 |
F_22 ( V_2 , V_54 ) ) ;
F_20 ( 10 ) ;
if ( V_2 -> V_49 -> V_50 & V_55 ) {
F_16 ( V_2 , V_56 , 0x0100 ) ;
F_20 ( 10 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_57 , 0x0000 ) ;
if ( V_2 -> V_49 -> V_50 & V_55 )
F_16 ( V_2 , V_58 , 0x0000 ) ;
F_20 ( 10 ) ;
F_16 ( V_2 , V_57 , 0x0001 ) ;
if ( V_2 -> V_49 -> V_50 & V_55 )
F_16 ( V_2 , V_58 , 0x0001 ) ;
F_20 ( 10 ) ;
}
static void F_25 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_26 ( V_60 , struct V_1 ,
V_61 . V_60 ) ;
struct V_62 * V_63 ;
unsigned long V_50 ;
F_27 ( & V_2 -> V_64 , V_50 ) ;
V_63 = V_2 -> V_63 ;
if ( F_28 ( V_63 )
|| F_29 ( V_2 -> V_65 +
F_30 ( V_66 ) ) ) {
F_31 ( & V_2 -> V_64 , V_50 ) ;
return;
}
F_32 ( & V_2 -> V_53 -> V_67 ,
L_3 ,
V_63 -> V_68 -> V_69 ) ;
if ( V_2 -> V_9 )
V_2 -> V_9 -> error = - V_70 ;
else if ( V_2 -> V_68 )
V_2 -> V_68 -> error = - V_70 ;
else
V_63 -> V_68 -> error = - V_70 ;
V_2 -> V_68 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_71 = false ;
F_31 ( & V_2 -> V_64 , V_50 ) ;
F_24 ( V_2 ) ;
V_2 -> V_63 = NULL ;
F_33 ( V_2 ) ;
F_34 ( V_2 -> V_38 , V_63 ) ;
F_17 ( F_15 ( V_2 -> V_38 ) ) ;
F_18 ( F_15 ( V_2 -> V_38 ) ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
unsigned long V_50 ;
F_27 ( & V_2 -> V_64 , V_50 ) ;
V_63 = V_2 -> V_63 ;
if ( F_28 ( V_63 ) ) {
F_31 ( & V_2 -> V_64 , V_50 ) ;
return;
}
V_2 -> V_68 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_71 = false ;
F_36 ( & V_2 -> V_61 ) ;
V_2 -> V_63 = NULL ;
F_31 ( & V_2 -> V_64 , V_50 ) ;
if ( V_63 -> V_68 -> error || ( V_63 -> V_9 && V_63 -> V_9 -> error ) )
F_33 ( V_2 ) ;
F_34 ( V_2 -> V_38 , V_63 ) ;
F_17 ( F_15 ( V_2 -> V_38 ) ) ;
F_18 ( F_15 ( V_2 -> V_38 ) ) ;
}
static void F_37 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_26 ( V_60 , struct V_1 ,
V_72 ) ;
F_35 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_73 * V_68 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_74 = V_68 -> V_69 ;
T_1 V_75 = V_76 ;
if ( V_68 -> V_69 == V_77 && ! V_68 -> V_78 ) {
F_16 ( V_2 , V_79 , 0x001 ) ;
return 0 ;
}
switch ( F_39 ( V_68 ) ) {
case V_80 : V_74 |= V_81 ; break;
case V_82 : V_74 |= V_83 ; break;
case V_84 : V_74 |= V_85 ; break;
case V_86 : V_74 |= V_87 ; break;
case V_88 : V_74 |= V_89 ; break;
default:
F_9 ( L_4 , F_39 ( V_68 ) ) ;
return - V_90 ;
}
V_2 -> V_68 = V_68 ;
if ( V_9 ) {
V_74 |= V_91 ;
if ( V_9 -> V_92 > 1 ) {
F_16 ( V_2 , V_79 , 0x100 ) ;
V_74 |= V_93 ;
if ( ( V_2 -> V_49 -> V_50 & V_94 ) &&
( V_68 -> V_69 == V_95 ) )
V_74 |= V_96 ;
}
if ( V_9 -> V_50 & V_97 )
V_74 |= V_98 ;
}
if ( ! V_2 -> V_99 )
V_75 &= ~ ( V_100 | V_101 ) ;
F_1 ( V_2 , V_75 ) ;
F_2 ( V_2 , V_102 , V_68 -> V_78 ) ;
F_16 ( V_2 , V_103 , V_74 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned short * V_104 ,
unsigned int V_105 )
{
int V_106 = V_2 -> V_9 -> V_50 & V_97 ;
T_2 * V_107 ;
if ( V_106 )
F_41 ( V_2 , V_108 , V_104 , V_105 >> 1 ) ;
else
F_42 ( V_2 , V_108 , V_104 , V_105 >> 1 ) ;
if ( ! ( V_105 & 0x1 ) )
return;
V_107 = ( T_2 * ) ( V_104 + ( V_105 >> 1 ) ) ;
if ( V_106 )
* V_107 = F_22 ( V_2 , V_108 ) & 0xff ;
else
F_16 ( V_2 , V_108 , * V_107 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_109 ;
unsigned short * V_104 ;
unsigned int V_105 ;
unsigned long V_50 ;
if ( ( V_2 -> V_110 || V_2 -> V_111 ) && ! V_2 -> V_71 ) {
F_44 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_109 = F_45 ( V_2 -> V_11 , & V_50 ) ;
V_104 = ( unsigned short * ) ( V_109 + V_2 -> V_14 ) ;
V_105 = V_2 -> V_11 -> V_112 - V_2 -> V_14 ;
if ( V_105 > V_9 -> V_113 )
V_105 = V_9 -> V_113 ;
F_9 ( L_7 ,
V_105 , V_2 -> V_14 , V_9 -> V_50 ) ;
F_40 ( V_2 , V_104 , V_105 ) ;
V_2 -> V_14 += V_105 ;
F_46 ( V_2 -> V_11 , & V_50 , V_109 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_112 )
F_6 ( V_2 ) ;
return;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_114 ) {
unsigned long V_50 ;
void * V_115 = F_45 ( V_2 -> V_13 , & V_50 ) ;
memcpy ( V_115 , V_2 -> V_116 , V_2 -> V_114 . V_112 ) ;
F_46 ( V_2 -> V_13 , & V_50 , V_115 ) ;
}
}
void F_48 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_73 * V_117 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_32 ( & V_2 -> V_53 -> V_67 , L_8 ) ;
return;
}
V_117 = V_9 -> V_117 ;
if ( ! V_9 -> error )
V_9 -> V_118 = V_9 -> V_92 * V_9 -> V_113 ;
else
V_9 -> V_118 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_50 & V_97 ) {
if ( V_2 -> V_111 && ! V_2 -> V_71 )
F_47 ( V_2 ) ;
F_49 ( & V_2 -> V_53 -> V_67 , L_10 ,
V_2 -> V_63 ) ;
} else {
F_49 ( & V_2 -> V_53 -> V_67 , L_11 ,
V_2 -> V_63 ) ;
}
if ( V_117 ) {
if ( V_117 -> V_69 == V_77 && ! V_117 -> V_78 )
F_16 ( V_2 , V_79 , 0x000 ) ;
else
F_50 () ;
}
F_51 ( & V_2 -> V_72 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_53 ( & V_2 -> V_64 ) ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 )
goto V_119;
if ( V_2 -> V_110 && ( V_9 -> V_50 & V_120 ) && ! V_2 -> V_71 ) {
T_1 V_15 = F_54 ( V_2 , V_7 ) ;
bool V_72 = false ;
if ( V_2 -> V_49 -> V_50 & V_121 ) {
if ( V_15 & V_122 )
V_72 = true ;
} else {
if ( ! ( V_15 & V_123 ) )
V_72 = true ;
}
if ( V_72 ) {
F_3 ( V_2 , V_124 ) ;
F_55 ( & V_2 -> V_125 ) ;
}
} else if ( V_2 -> V_111 && ( V_9 -> V_50 & V_97 ) && ! V_2 -> V_71 ) {
F_3 ( V_2 , V_124 ) ;
F_55 ( & V_2 -> V_125 ) ;
} else {
F_48 ( V_2 ) ;
F_3 ( V_2 , V_126 | V_127 ) ;
}
V_119:
F_56 ( & V_2 -> V_64 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_128 )
{
struct V_73 * V_68 = V_2 -> V_68 ;
int V_3 , V_129 ;
F_53 ( & V_2 -> V_64 ) ;
if ( ! V_2 -> V_68 ) {
F_9 ( L_12 ) ;
goto V_119;
}
V_2 -> V_68 = NULL ;
for ( V_3 = 3 , V_129 = V_130 ; V_3 >= 0 ; V_3 -- , V_129 += 4 )
V_68 -> V_131 [ V_3 ] = F_54 ( V_2 , V_129 ) ;
if ( V_68 -> V_50 & V_132 ) {
V_68 -> V_131 [ 0 ] = ( V_68 -> V_131 [ 0 ] << 8 ) | ( V_68 -> V_131 [ 1 ] >> 24 ) ;
V_68 -> V_131 [ 1 ] = ( V_68 -> V_131 [ 1 ] << 8 ) | ( V_68 -> V_131 [ 2 ] >> 24 ) ;
V_68 -> V_131 [ 2 ] = ( V_68 -> V_131 [ 2 ] << 8 ) | ( V_68 -> V_131 [ 3 ] >> 24 ) ;
V_68 -> V_131 [ 3 ] <<= 8 ;
} else if ( V_68 -> V_50 & V_88 ) {
V_68 -> V_131 [ 0 ] = V_68 -> V_131 [ 3 ] ;
}
if ( V_128 & V_133 )
V_68 -> error = - V_70 ;
else if ( V_128 & V_134 && V_68 -> V_50 & V_135 )
V_68 -> error = - V_136 ;
if ( V_2 -> V_9 && ! V_68 -> error ) {
if ( V_2 -> V_9 -> V_50 & V_97 ) {
if ( V_2 -> V_71 || ! V_2 -> V_111 )
F_1 ( V_2 , V_126 ) ;
else
F_55 ( & V_2 -> V_137 ) ;
} else {
if ( V_2 -> V_71 || ! V_2 -> V_110 )
F_1 ( V_2 , V_127 ) ;
else
F_55 ( & V_2 -> V_137 ) ;
}
} else {
F_51 ( & V_2 -> V_72 ) ;
}
V_119:
F_56 ( & V_2 -> V_64 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
int * V_138 , int * V_15 )
{
* V_15 = F_54 ( V_2 , V_7 ) ;
* V_138 = * V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( * V_15 ) ;
F_8 ( * V_138 ) ;
F_2 ( V_2 , V_7 , V_5 ) ;
}
static bool F_59 ( struct V_1 * V_2 ,
int V_138 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_138 & ( V_101 | V_100 ) ) {
F_4 ( V_2 , V_101 |
V_100 ) ;
if ( ( ( ( V_138 & V_100 ) && V_38 -> V_139 ) ||
( ( V_138 & V_101 ) && ! V_38 -> V_139 ) ) &&
! F_60 ( & V_38 -> V_140 . V_60 ) )
F_61 ( V_2 -> V_38 , F_30 ( 100 ) ) ;
return true ;
}
return false ;
}
T_3 F_62 ( int V_141 , void * V_142 )
{
unsigned int V_138 , V_15 ;
struct V_1 * V_2 = V_142 ;
F_58 ( V_2 , & V_138 , & V_15 ) ;
F_59 ( V_2 , V_138 , V_15 ) ;
return V_143 ;
}
static bool F_63 ( struct V_1 * V_2 ,
int V_138 , int V_15 )
{
if ( V_138 & ( V_144 | V_133 ) ) {
F_4 ( V_2 ,
V_144 |
V_133 ) ;
F_57 ( V_2 , V_15 ) ;
return true ;
}
if ( V_138 & ( V_145 | V_146 ) ) {
F_4 ( V_2 , V_145 | V_146 ) ;
F_43 ( V_2 ) ;
return true ;
}
if ( V_138 & V_124 ) {
F_4 ( V_2 , V_124 ) ;
F_52 ( V_2 ) ;
return true ;
}
return false ;
}
T_3 F_64 ( int V_141 , void * V_142 )
{
unsigned int V_138 , V_15 ;
struct V_1 * V_2 = V_142 ;
F_58 ( V_2 , & V_138 , & V_15 ) ;
F_63 ( V_2 , V_138 , V_15 ) ;
return V_143 ;
}
T_3 F_65 ( int V_141 , void * V_142 )
{
struct V_1 * V_2 = V_142 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_147 * V_49 = V_2 -> V_49 ;
unsigned int V_138 , V_15 ;
unsigned int V_148 ;
if ( ! ( V_49 -> V_50 & V_149 ) )
return V_143 ;
V_15 = F_22 ( V_2 , V_150 ) ;
V_138 = V_15 & V_42 & ~ V_2 -> V_4 ;
V_148 = V_15 & ~ V_42 ;
if ( V_49 -> V_50 & V_151 )
V_148 |= 6 ;
F_16 ( V_2 , V_150 , V_148 ) ;
if ( V_38 -> V_152 & V_153 && V_138 & V_43 )
F_66 ( V_38 ) ;
return V_143 ;
}
T_3 F_67 ( int V_141 , void * V_142 )
{
struct V_1 * V_2 = V_142 ;
unsigned int V_138 , V_15 ;
F_9 ( L_13 ) ;
F_58 ( V_2 , & V_138 , & V_15 ) ;
if ( F_59 ( V_2 , V_138 , V_15 ) )
return V_143 ;
if ( F_63 ( V_2 , V_138 , V_15 ) )
return V_143 ;
F_65 ( V_141 , V_142 ) ;
return V_143 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_147 * V_49 = V_2 -> V_49 ;
F_9 ( L_14 ,
V_9 -> V_113 , V_9 -> V_92 ) ;
if ( V_2 -> V_38 -> V_154 . V_155 == V_156 ) {
int V_157 = V_49 -> V_50 & V_158 ;
if ( V_9 -> V_113 < 2 || ( V_9 -> V_113 < 4 && ! V_157 ) ) {
F_44 ( L_15 ,
F_69 ( V_2 -> V_38 ) , V_9 -> V_113 ) ;
return - V_90 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_16 ( V_2 , V_159 , V_9 -> V_113 ) ;
F_16 ( V_2 , V_160 , V_9 -> V_92 ) ;
F_70 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_71 ( struct V_37 * V_38 , struct V_62 * V_63 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_50 ;
int V_161 ;
F_27 ( & V_2 -> V_64 , V_50 ) ;
if ( V_2 -> V_63 ) {
F_9 ( L_16 ) ;
if ( F_72 ( V_2 -> V_63 ) ) {
F_31 ( & V_2 -> V_64 , V_50 ) ;
V_63 -> V_68 -> error = - V_162 ;
F_34 ( V_38 , V_63 ) ;
return;
}
}
V_2 -> V_65 = V_163 ;
F_73 () ;
V_2 -> V_63 = V_63 ;
F_31 ( & V_2 -> V_64 , V_50 ) ;
F_14 ( F_15 ( V_38 ) ) ;
if ( V_63 -> V_9 ) {
V_161 = F_68 ( V_2 , V_63 -> V_9 ) ;
if ( V_161 )
goto V_164;
}
V_161 = F_38 ( V_2 , V_63 -> V_68 ) ;
if ( ! V_161 ) {
F_74 ( & V_2 -> V_61 ,
F_30 ( V_66 ) ) ;
return;
}
V_164:
V_2 -> V_71 = false ;
V_2 -> V_63 = NULL ;
V_63 -> V_68 -> error = V_161 ;
F_34 ( V_38 , V_63 ) ;
F_17 ( F_15 ( V_38 ) ) ;
F_18 ( F_15 ( V_38 ) ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_161 ;
if ( ! V_2 -> V_165 )
return - V_166 ;
V_161 = V_2 -> V_165 ( V_2 -> V_53 , & V_38 -> V_167 ) ;
if ( ! V_161 )
V_38 -> V_48 = V_38 -> V_167 / 512 ;
return V_161 ;
}
static void F_76 ( struct V_1 * V_2 , unsigned short V_168 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_161 = 0 ;
if ( V_2 -> V_169 )
V_2 -> V_169 ( V_2 -> V_53 , 1 ) ;
if ( ! F_72 ( V_38 -> V_170 . V_171 ) ) {
V_161 = F_77 ( V_38 , V_38 -> V_170 . V_171 , V_168 ) ;
F_78 ( 200 ) ;
}
if ( ! F_72 ( V_38 -> V_170 . V_172 ) && ! V_161 ) {
V_161 = F_79 ( V_38 -> V_170 . V_172 ) ;
F_78 ( 200 ) ;
}
if ( V_161 < 0 )
F_49 ( & V_2 -> V_53 -> V_67 , L_17 ,
V_161 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! F_72 ( V_38 -> V_170 . V_172 ) )
F_81 ( V_38 -> V_170 . V_172 ) ;
if ( ! F_72 ( V_38 -> V_170 . V_171 ) )
F_77 ( V_38 , V_38 -> V_170 . V_171 , 0 ) ;
if ( V_2 -> V_169 )
V_2 -> V_169 ( V_2 -> V_53 , 0 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
unsigned char V_155 )
{
switch ( V_155 ) {
case V_173 :
F_16 ( V_2 , V_174 , 0x80e0 ) ;
break;
case V_156 :
F_16 ( V_2 , V_174 , 0x00e0 ) ;
break;
}
}
static void F_83 ( struct V_37 * V_38 , struct V_175 * V_154 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_176 * V_67 = & V_2 -> V_53 -> V_67 ;
unsigned long V_50 ;
F_14 ( F_15 ( V_38 ) ) ;
F_84 ( & V_2 -> V_177 ) ;
F_27 ( & V_2 -> V_64 , V_50 ) ;
if ( V_2 -> V_63 ) {
if ( F_72 ( V_2 -> V_63 ) ) {
F_49 ( V_67 ,
L_18 ,
V_178 -> V_179 , F_85 ( V_178 ) ,
V_154 -> clock , V_154 -> V_180 ) ;
V_2 -> V_63 = F_86 ( - V_181 ) ;
} else {
F_49 ( V_67 ,
L_19 ,
V_178 -> V_179 , F_85 ( V_178 ) ,
V_2 -> V_63 -> V_68 -> V_69 , V_2 -> V_65 , V_163 ) ;
}
F_31 ( & V_2 -> V_64 , V_50 ) ;
F_87 ( & V_2 -> V_177 ) ;
return;
}
V_2 -> V_63 = F_86 ( - V_182 ) ;
F_31 ( & V_2 -> V_64 , V_50 ) ;
switch ( V_154 -> V_180 ) {
case V_183 :
F_80 ( V_2 ) ;
F_21 ( V_2 ) ;
break;
case V_184 :
F_19 ( V_2 , V_154 -> clock ) ;
F_76 ( V_2 , V_154 -> V_168 ) ;
F_23 ( V_2 ) ;
F_82 ( V_2 , V_154 -> V_155 ) ;
break;
case V_185 :
F_19 ( V_2 , V_154 -> clock ) ;
F_23 ( V_2 ) ;
F_82 ( V_2 , V_154 -> V_155 ) ;
break;
}
F_78 ( 140 ) ;
if ( F_88 ( V_2 -> V_63 ) == - V_181 )
F_49 ( & V_2 -> V_53 -> V_67 ,
L_20 ,
V_178 -> V_179 , F_85 ( V_178 ) ,
V_154 -> clock , V_154 -> V_180 ) ;
V_2 -> V_63 = NULL ;
V_2 -> V_186 = V_154 -> clock ;
F_87 ( & V_2 -> V_177 ) ;
F_17 ( F_15 ( V_38 ) ) ;
F_18 ( F_15 ( V_38 ) ) ;
}
static int F_89 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_147 * V_49 = V_2 -> V_49 ;
int V_161 = F_90 ( V_38 ) ;
if ( V_161 >= 0 )
return V_161 ;
F_14 ( F_15 ( V_38 ) ) ;
V_161 = ! ( ( V_49 -> V_50 & V_187 ) ||
( F_54 ( V_2 , V_7 ) & V_188 ) ) ;
F_17 ( F_15 ( V_38 ) ) ;
F_18 ( F_15 ( V_38 ) ) ;
return V_161 ;
}
static int F_91 ( struct V_189 * V_139 ,
unsigned int V_190 , int V_191 )
{
struct V_1 * V_2 = F_13 ( V_139 -> V_2 ) ;
if ( V_2 -> V_192 )
return V_2 -> V_192 ( V_139 , V_190 , V_191 ) ;
return V_191 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_147 * V_49 = V_2 -> V_49 ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_93 ( V_38 ) ;
if ( ! V_38 -> V_193 )
V_38 -> V_193 = V_49 -> V_194 ;
if ( ! V_38 -> V_193 )
return - V_195 ;
return 0 ;
}
static void F_94 ( struct V_196 * V_53 ,
struct V_147 * V_49 )
{
const struct V_197 * V_198 = V_53 -> V_67 . V_199 ;
if ( ! V_198 )
return;
if ( F_95 ( V_198 , L_21 , NULL ) )
V_49 -> V_50 |= V_187 ;
}
struct V_1 *
F_96 ( struct V_196 * V_53 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
V_38 = F_97 ( sizeof( struct V_1 ) , & V_53 -> V_67 ) ;
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
int F_100 ( struct V_1 * V_200 ,
struct V_147 * V_49 )
{
struct V_196 * V_53 = V_200 -> V_53 ;
struct V_37 * V_38 = V_200 -> V_38 ;
struct V_201 * V_202 ;
int V_161 ;
T_1 V_75 = V_76 ;
F_94 ( V_53 , V_49 ) ;
if ( ! ( V_49 -> V_50 & V_121 ) )
V_200 -> V_203 = NULL ;
V_202 = F_101 ( V_53 , V_204 , 0 ) ;
if ( ! V_202 )
return - V_90 ;
V_161 = F_102 ( V_38 ) ;
if ( V_161 < 0 )
goto V_205;
V_200 -> V_49 = V_49 ;
F_103 ( V_53 , V_38 ) ;
V_200 -> V_169 = V_49 -> V_169 ;
V_200 -> V_52 = V_49 -> V_52 ;
V_161 = F_92 ( V_200 ) ;
if ( V_161 < 0 )
goto V_205;
V_200 -> V_206 = F_104 ( & V_53 -> V_67 ,
V_202 -> V_207 , F_105 ( V_202 ) ) ;
if ( ! V_200 -> V_206 ) {
V_161 = - V_208 ;
goto V_205;
}
V_38 -> V_209 = & V_210 ;
V_38 -> V_152 |= V_211 | V_49 -> V_212 ;
V_38 -> V_213 |= V_49 -> V_214 ;
V_38 -> V_215 = 32 ;
V_38 -> V_216 = 512 ;
V_38 -> V_217 = ( V_218 / V_38 -> V_216 ) *
V_38 -> V_215 ;
V_38 -> V_219 = V_38 -> V_216 * V_38 -> V_217 ;
V_38 -> V_220 = V_38 -> V_219 ;
V_200 -> V_99 = ! ( V_49 -> V_50 & V_221 ||
V_38 -> V_152 & V_222 ||
V_38 -> V_152 & V_223 ||
V_38 -> V_224 . V_225 >= 0 ) ;
if ( F_75 ( V_200 ) < 0 ) {
V_38 -> V_167 = V_49 -> V_226 ;
V_38 -> V_48 = V_38 -> V_167 / 512 ;
}
if ( V_38 -> V_48 == 0 ) {
V_161 = - V_90 ;
goto V_205;
}
if ( V_200 -> V_99 )
F_106 ( & V_53 -> V_67 ) ;
F_21 ( V_200 ) ;
F_24 ( V_200 ) ;
V_200 -> V_4 = F_54 ( V_200 , V_6 ) ;
F_3 ( V_200 , V_227 ) ;
if ( ! V_200 -> V_111 )
V_75 |= V_126 ;
if ( ! V_200 -> V_110 )
V_75 |= V_127 ;
if ( ! V_200 -> V_99 )
V_75 &= ~ ( V_100 | V_101 ) ;
V_200 -> V_4 &= ~ V_75 ;
V_200 -> V_40 = false ;
if ( V_49 -> V_50 & V_149 ) {
V_200 -> V_41 = V_42 ;
F_16 ( V_200 , V_45 , V_200 -> V_41 ) ;
F_16 ( V_200 , V_44 , 0x0000 ) ;
}
F_107 ( & V_200 -> V_64 ) ;
F_108 ( & V_200 -> V_177 ) ;
F_109 ( & V_200 -> V_61 , F_25 ) ;
F_110 ( & V_200 -> V_72 , F_37 ) ;
F_111 ( V_200 , V_49 ) ;
F_112 ( & V_53 -> V_67 ) ;
F_113 ( & V_53 -> V_67 , 50 ) ;
F_114 ( & V_53 -> V_67 ) ;
F_115 ( & V_53 -> V_67 ) ;
V_161 = F_116 ( V_38 ) ;
if ( V_161 < 0 ) {
F_117 ( V_200 ) ;
return V_161 ;
}
F_118 ( & V_53 -> V_67 , 100 ) ;
if ( V_49 -> V_50 & V_221 ) {
V_161 = F_119 ( V_38 , V_49 -> V_228 , 0 ) ;
if ( V_161 < 0 ) {
F_117 ( V_200 ) ;
return V_161 ;
}
F_120 ( V_38 ) ;
}
return 0 ;
V_205:
return V_161 ;
}
void F_117 ( struct V_1 * V_2 )
{
struct V_196 * V_53 = V_2 -> V_53 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! V_2 -> V_99 )
F_14 ( & V_53 -> V_67 ) ;
F_121 ( & V_53 -> V_67 ) ;
F_122 ( V_38 ) ;
F_123 ( & V_2 -> V_72 ) ;
F_124 ( & V_2 -> V_61 ) ;
F_125 ( V_2 ) ;
F_126 ( & V_53 -> V_67 ) ;
F_127 ( & V_53 -> V_67 ) ;
}
int F_128 ( struct V_176 * V_67 )
{
struct V_37 * V_38 = F_129 ( V_67 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_3 ( V_2 , V_227 ) ;
if ( V_2 -> V_186 )
F_21 ( V_2 ) ;
if ( V_2 -> V_229 )
V_2 -> V_229 ( V_2 -> V_53 ) ;
return 0 ;
}
int F_130 ( struct V_176 * V_67 )
{
struct V_37 * V_38 = F_129 ( V_67 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_24 ( V_2 ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_186 ) {
F_19 ( V_2 , V_2 -> V_186 ) ;
F_23 ( V_2 ) ;
}
F_131 ( V_2 , true ) ;
return 0 ;
}

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
F_30 ( 2000 ) ) ) {
F_31 ( & V_2 -> V_64 , V_50 ) ;
return;
}
F_32 ( & V_2 -> V_53 -> V_66 ,
L_3 ,
V_63 -> V_67 -> V_68 ) ;
if ( V_2 -> V_9 )
V_2 -> V_9 -> error = - V_69 ;
else if ( V_2 -> V_67 )
V_2 -> V_67 -> error = - V_69 ;
else
V_63 -> V_67 -> error = - V_69 ;
V_2 -> V_67 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_70 = false ;
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
V_2 -> V_67 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_70 = false ;
F_36 ( & V_2 -> V_61 ) ;
V_2 -> V_63 = NULL ;
F_31 ( & V_2 -> V_64 , V_50 ) ;
if ( V_63 -> V_67 -> error || ( V_63 -> V_9 && V_63 -> V_9 -> error ) )
F_33 ( V_2 ) ;
F_34 ( V_2 -> V_38 , V_63 ) ;
F_17 ( F_15 ( V_2 -> V_38 ) ) ;
F_18 ( F_15 ( V_2 -> V_38 ) ) ;
}
static void F_37 ( struct V_59 * V_60 )
{
struct V_1 * V_2 = F_26 ( V_60 , struct V_1 ,
V_71 ) ;
F_35 ( V_2 ) ;
}
static int F_38 ( struct V_1 * V_2 , struct V_72 * V_67 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_73 = V_67 -> V_68 ;
T_1 V_74 = V_75 ;
if ( V_67 -> V_68 == V_76 && ! V_67 -> V_77 ) {
F_16 ( V_2 , V_78 , 0x001 ) ;
return 0 ;
}
switch ( F_39 ( V_67 ) ) {
case V_79 : V_73 |= V_80 ; break;
case V_81 : V_73 |= V_82 ; break;
case V_83 : V_73 |= V_84 ; break;
case V_85 : V_73 |= V_86 ; break;
case V_87 : V_73 |= V_88 ; break;
default:
F_9 ( L_4 , F_39 ( V_67 ) ) ;
return - V_89 ;
}
V_2 -> V_67 = V_67 ;
if ( V_9 ) {
V_73 |= V_90 ;
if ( V_9 -> V_91 > 1 ) {
F_16 ( V_2 , V_78 , 0x100 ) ;
V_73 |= V_92 ;
if ( ( V_2 -> V_49 -> V_50 & V_93 ) &&
( V_67 -> V_68 == V_94 ) )
V_73 |= V_95 ;
}
if ( V_9 -> V_50 & V_96 )
V_73 |= V_97 ;
}
if ( ! V_2 -> V_98 )
V_74 &= ~ ( V_99 | V_100 ) ;
F_1 ( V_2 , V_74 ) ;
F_2 ( V_2 , V_101 , V_67 -> V_77 ) ;
F_16 ( V_2 , V_102 , V_73 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned short * V_103 ,
unsigned int V_104 )
{
int V_105 = V_2 -> V_9 -> V_50 & V_96 ;
T_2 * V_106 ;
if ( V_105 )
F_41 ( V_2 , V_107 , V_103 , V_104 >> 1 ) ;
else
F_42 ( V_2 , V_107 , V_103 , V_104 >> 1 ) ;
if ( ! ( V_104 & 0x1 ) )
return;
V_106 = ( T_2 * ) ( V_103 + ( V_104 >> 1 ) ) ;
if ( V_105 )
* V_106 = F_22 ( V_2 , V_107 ) & 0xff ;
else
F_16 ( V_2 , V_107 , * V_106 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_108 ;
unsigned short * V_103 ;
unsigned int V_104 ;
unsigned long V_50 ;
if ( ( V_2 -> V_109 || V_2 -> V_110 ) && ! V_2 -> V_70 ) {
F_44 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_108 = F_45 ( V_2 -> V_11 , & V_50 ) ;
V_103 = ( unsigned short * ) ( V_108 + V_2 -> V_14 ) ;
V_104 = V_2 -> V_11 -> V_111 - V_2 -> V_14 ;
if ( V_104 > V_9 -> V_112 )
V_104 = V_9 -> V_112 ;
F_9 ( L_7 ,
V_104 , V_2 -> V_14 , V_9 -> V_50 ) ;
F_40 ( V_2 , V_103 , V_104 ) ;
V_2 -> V_14 += V_104 ;
F_46 ( V_2 -> V_11 , & V_50 , V_108 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_111 )
F_6 ( V_2 ) ;
return;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_113 ) {
unsigned long V_50 ;
void * V_114 = F_45 ( V_2 -> V_13 , & V_50 ) ;
memcpy ( V_114 , V_2 -> V_115 , V_2 -> V_113 . V_111 ) ;
F_46 ( V_2 -> V_13 , & V_50 , V_114 ) ;
}
}
void F_48 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_72 * V_116 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_32 ( & V_2 -> V_53 -> V_66 , L_8 ) ;
return;
}
V_116 = V_9 -> V_116 ;
if ( ! V_9 -> error )
V_9 -> V_117 = V_9 -> V_91 * V_9 -> V_112 ;
else
V_9 -> V_117 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_50 & V_96 ) {
if ( V_2 -> V_110 && ! V_2 -> V_70 )
F_47 ( V_2 ) ;
F_49 ( & V_2 -> V_53 -> V_66 , L_10 ,
V_2 -> V_63 ) ;
} else {
F_49 ( & V_2 -> V_53 -> V_66 , L_11 ,
V_2 -> V_63 ) ;
}
if ( V_116 ) {
if ( V_116 -> V_68 == V_76 && ! V_116 -> V_77 )
F_16 ( V_2 , V_78 , 0x000 ) ;
else
F_50 () ;
}
F_51 ( & V_2 -> V_71 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_53 ( & V_2 -> V_64 ) ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 )
goto V_118;
if ( V_2 -> V_109 && ( V_9 -> V_50 & V_119 ) && ! V_2 -> V_70 ) {
T_1 V_15 = F_54 ( V_2 , V_7 ) ;
bool V_71 = false ;
if ( V_2 -> V_49 -> V_50 & V_120 ) {
if ( V_15 & V_121 )
V_71 = true ;
} else {
if ( ! ( V_15 & V_122 ) )
V_71 = true ;
}
if ( V_71 ) {
F_3 ( V_2 , V_123 ) ;
F_55 ( & V_2 -> V_124 ) ;
}
} else if ( V_2 -> V_110 && ( V_9 -> V_50 & V_96 ) && ! V_2 -> V_70 ) {
F_3 ( V_2 , V_123 ) ;
F_55 ( & V_2 -> V_124 ) ;
} else {
F_48 ( V_2 ) ;
F_3 ( V_2 , V_125 | V_126 ) ;
}
V_118:
F_56 ( & V_2 -> V_64 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
unsigned int V_127 )
{
struct V_72 * V_67 = V_2 -> V_67 ;
int V_3 , V_128 ;
F_53 ( & V_2 -> V_64 ) ;
if ( ! V_2 -> V_67 ) {
F_9 ( L_12 ) ;
goto V_118;
}
V_2 -> V_67 = NULL ;
for ( V_3 = 3 , V_128 = V_129 ; V_3 >= 0 ; V_3 -- , V_128 += 4 )
V_67 -> V_130 [ V_3 ] = F_54 ( V_2 , V_128 ) ;
if ( V_67 -> V_50 & V_131 ) {
V_67 -> V_130 [ 0 ] = ( V_67 -> V_130 [ 0 ] << 8 ) | ( V_67 -> V_130 [ 1 ] >> 24 ) ;
V_67 -> V_130 [ 1 ] = ( V_67 -> V_130 [ 1 ] << 8 ) | ( V_67 -> V_130 [ 2 ] >> 24 ) ;
V_67 -> V_130 [ 2 ] = ( V_67 -> V_130 [ 2 ] << 8 ) | ( V_67 -> V_130 [ 3 ] >> 24 ) ;
V_67 -> V_130 [ 3 ] <<= 8 ;
} else if ( V_67 -> V_50 & V_87 ) {
V_67 -> V_130 [ 0 ] = V_67 -> V_130 [ 3 ] ;
}
if ( V_127 & V_132 )
V_67 -> error = - V_69 ;
else if ( V_127 & V_133 && V_67 -> V_50 & V_134 )
V_67 -> error = - V_135 ;
if ( V_2 -> V_9 && ! V_67 -> error ) {
if ( V_2 -> V_9 -> V_50 & V_96 ) {
if ( V_2 -> V_70 || ! V_2 -> V_110 )
F_1 ( V_2 , V_125 ) ;
else
F_55 ( & V_2 -> V_136 ) ;
} else {
if ( V_2 -> V_70 || ! V_2 -> V_109 )
F_1 ( V_2 , V_126 ) ;
else
F_55 ( & V_2 -> V_136 ) ;
}
} else {
F_51 ( & V_2 -> V_71 ) ;
}
V_118:
F_56 ( & V_2 -> V_64 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
int * V_137 , int * V_15 )
{
* V_15 = F_54 ( V_2 , V_7 ) ;
* V_137 = * V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( * V_15 ) ;
F_8 ( * V_137 ) ;
F_2 ( V_2 , V_7 , V_5 ) ;
}
static bool F_59 ( struct V_1 * V_2 ,
int V_137 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_137 & ( V_100 | V_99 ) ) {
F_4 ( V_2 , V_100 |
V_99 ) ;
if ( ( ( ( V_137 & V_99 ) && V_38 -> V_138 ) ||
( ( V_137 & V_100 ) && ! V_38 -> V_138 ) ) &&
! F_60 ( & V_38 -> V_139 . V_60 ) )
F_61 ( V_2 -> V_38 , F_30 ( 100 ) ) ;
return true ;
}
return false ;
}
T_3 F_62 ( int V_140 , void * V_141 )
{
unsigned int V_137 , V_15 ;
struct V_1 * V_2 = V_141 ;
F_58 ( V_2 , & V_137 , & V_15 ) ;
F_59 ( V_2 , V_137 , V_15 ) ;
return V_142 ;
}
static bool F_63 ( struct V_1 * V_2 ,
int V_137 , int V_15 )
{
if ( V_137 & ( V_143 | V_132 ) ) {
F_4 ( V_2 ,
V_143 |
V_132 ) ;
F_57 ( V_2 , V_15 ) ;
return true ;
}
if ( V_137 & ( V_144 | V_145 ) ) {
F_4 ( V_2 , V_144 | V_145 ) ;
F_43 ( V_2 ) ;
return true ;
}
if ( V_137 & V_123 ) {
F_4 ( V_2 , V_123 ) ;
F_52 ( V_2 ) ;
return true ;
}
return false ;
}
T_3 F_64 ( int V_140 , void * V_141 )
{
unsigned int V_137 , V_15 ;
struct V_1 * V_2 = V_141 ;
F_58 ( V_2 , & V_137 , & V_15 ) ;
F_63 ( V_2 , V_137 , V_15 ) ;
return V_142 ;
}
T_3 F_65 ( int V_140 , void * V_141 )
{
struct V_1 * V_2 = V_141 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_146 * V_49 = V_2 -> V_49 ;
unsigned int V_137 , V_15 ;
unsigned int V_147 ;
if ( ! ( V_49 -> V_50 & V_148 ) )
return V_142 ;
V_15 = F_22 ( V_2 , V_149 ) ;
V_137 = V_15 & V_42 & ~ V_2 -> V_4 ;
V_147 = V_15 & ~ V_42 ;
if ( V_49 -> V_50 & V_150 )
V_147 |= 6 ;
F_16 ( V_2 , V_149 , V_147 ) ;
if ( V_38 -> V_151 & V_152 && V_137 & V_43 )
F_66 ( V_38 ) ;
return V_142 ;
}
T_3 F_67 ( int V_140 , void * V_141 )
{
struct V_1 * V_2 = V_141 ;
unsigned int V_137 , V_15 ;
F_9 ( L_13 ) ;
F_58 ( V_2 , & V_137 , & V_15 ) ;
if ( F_59 ( V_2 , V_137 , V_15 ) )
return V_142 ;
if ( F_63 ( V_2 , V_137 , V_15 ) )
return V_142 ;
F_65 ( V_140 , V_141 ) ;
return V_142 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_146 * V_49 = V_2 -> V_49 ;
F_9 ( L_14 ,
V_9 -> V_112 , V_9 -> V_91 ) ;
if ( V_2 -> V_38 -> V_153 . V_154 == V_155 ) {
int V_156 = V_49 -> V_50 & V_157 ;
if ( V_9 -> V_112 < 2 || ( V_9 -> V_112 < 4 && ! V_156 ) ) {
F_44 ( L_15 ,
F_69 ( V_2 -> V_38 ) , V_9 -> V_112 ) ;
return - V_89 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_16 ( V_2 , V_158 , V_9 -> V_112 ) ;
F_16 ( V_2 , V_159 , V_9 -> V_91 ) ;
F_70 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_71 ( struct V_37 * V_38 , struct V_62 * V_63 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_50 ;
int V_160 ;
F_27 ( & V_2 -> V_64 , V_50 ) ;
if ( V_2 -> V_63 ) {
F_9 ( L_16 ) ;
if ( F_72 ( V_2 -> V_63 ) ) {
F_31 ( & V_2 -> V_64 , V_50 ) ;
V_63 -> V_67 -> error = - V_161 ;
F_34 ( V_38 , V_63 ) ;
return;
}
}
V_2 -> V_65 = V_162 ;
F_73 () ;
V_2 -> V_63 = V_63 ;
F_31 ( & V_2 -> V_64 , V_50 ) ;
F_14 ( F_15 ( V_38 ) ) ;
if ( V_63 -> V_9 ) {
V_160 = F_68 ( V_2 , V_63 -> V_9 ) ;
if ( V_160 )
goto V_163;
}
V_160 = F_38 ( V_2 , V_63 -> V_67 ) ;
if ( ! V_160 ) {
F_74 ( & V_2 -> V_61 ,
F_30 ( 2000 ) ) ;
return;
}
V_163:
V_2 -> V_70 = false ;
V_2 -> V_63 = NULL ;
V_63 -> V_67 -> error = V_160 ;
F_34 ( V_38 , V_63 ) ;
F_17 ( F_15 ( V_38 ) ) ;
F_18 ( F_15 ( V_38 ) ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_160 ;
if ( ! V_2 -> V_164 )
return - V_165 ;
V_160 = V_2 -> V_164 ( V_2 -> V_53 , & V_38 -> V_166 ) ;
if ( ! V_160 )
V_38 -> V_48 = V_38 -> V_166 / 512 ;
return V_160 ;
}
static void F_76 ( struct V_1 * V_2 , unsigned short V_167 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_160 = 0 ;
if ( V_2 -> V_168 )
V_2 -> V_168 ( V_2 -> V_53 , 1 ) ;
if ( ! F_72 ( V_38 -> V_169 . V_170 ) ) {
V_160 = F_77 ( V_38 , V_38 -> V_169 . V_170 , V_167 ) ;
F_78 ( 200 ) ;
}
if ( ! F_72 ( V_38 -> V_169 . V_171 ) && ! V_160 ) {
V_160 = F_79 ( V_38 -> V_169 . V_171 ) ;
F_78 ( 200 ) ;
}
if ( V_160 < 0 )
F_49 ( & V_2 -> V_53 -> V_66 , L_17 ,
V_160 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! F_72 ( V_38 -> V_169 . V_171 ) )
F_81 ( V_38 -> V_169 . V_171 ) ;
if ( ! F_72 ( V_38 -> V_169 . V_170 ) )
F_77 ( V_38 , V_38 -> V_169 . V_170 , 0 ) ;
if ( V_2 -> V_168 )
V_2 -> V_168 ( V_2 -> V_53 , 0 ) ;
}
static void F_82 ( struct V_1 * V_2 ,
unsigned char V_154 )
{
switch ( V_154 ) {
case V_172 :
F_16 ( V_2 , V_173 , 0x80e0 ) ;
break;
case V_155 :
F_16 ( V_2 , V_173 , 0x00e0 ) ;
break;
}
}
static void F_83 ( struct V_37 * V_38 , struct V_174 * V_153 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_175 * V_66 = & V_2 -> V_53 -> V_66 ;
unsigned long V_50 ;
F_14 ( F_15 ( V_38 ) ) ;
F_84 ( & V_2 -> V_176 ) ;
F_27 ( & V_2 -> V_64 , V_50 ) ;
if ( V_2 -> V_63 ) {
if ( F_72 ( V_2 -> V_63 ) ) {
F_49 ( V_66 ,
L_18 ,
V_177 -> V_178 , F_85 ( V_177 ) ,
V_153 -> clock , V_153 -> V_179 ) ;
V_2 -> V_63 = F_86 ( - V_180 ) ;
} else {
F_49 ( V_66 ,
L_19 ,
V_177 -> V_178 , F_85 ( V_177 ) ,
V_2 -> V_63 -> V_67 -> V_68 , V_2 -> V_65 , V_162 ) ;
}
F_31 ( & V_2 -> V_64 , V_50 ) ;
F_87 ( & V_2 -> V_176 ) ;
return;
}
V_2 -> V_63 = F_86 ( - V_181 ) ;
F_31 ( & V_2 -> V_64 , V_50 ) ;
switch ( V_153 -> V_179 ) {
case V_182 :
F_80 ( V_2 ) ;
F_21 ( V_2 ) ;
break;
case V_183 :
F_19 ( V_2 , V_153 -> clock ) ;
F_76 ( V_2 , V_153 -> V_167 ) ;
F_23 ( V_2 ) ;
F_82 ( V_2 , V_153 -> V_154 ) ;
break;
case V_184 :
F_19 ( V_2 , V_153 -> clock ) ;
F_23 ( V_2 ) ;
F_82 ( V_2 , V_153 -> V_154 ) ;
break;
}
F_78 ( 140 ) ;
if ( F_88 ( V_2 -> V_63 ) == - V_180 )
F_49 ( & V_2 -> V_53 -> V_66 ,
L_20 ,
V_177 -> V_178 , F_85 ( V_177 ) ,
V_153 -> clock , V_153 -> V_179 ) ;
V_2 -> V_63 = NULL ;
V_2 -> V_185 = V_153 -> clock ;
F_87 ( & V_2 -> V_176 ) ;
F_17 ( F_15 ( V_38 ) ) ;
F_18 ( F_15 ( V_38 ) ) ;
}
static int F_89 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_146 * V_49 = V_2 -> V_49 ;
int V_160 = F_90 ( V_38 ) ;
if ( V_160 >= 0 )
return V_160 ;
F_14 ( F_15 ( V_38 ) ) ;
V_160 = ! ( ( V_49 -> V_50 & V_186 ) ||
( F_54 ( V_2 , V_7 ) & V_187 ) ) ;
F_17 ( F_15 ( V_38 ) ) ;
F_18 ( F_15 ( V_38 ) ) ;
return V_160 ;
}
static int F_91 ( struct V_188 * V_138 ,
unsigned int V_189 , int V_190 )
{
struct V_1 * V_2 = F_13 ( V_138 -> V_2 ) ;
if ( V_2 -> V_191 )
return V_2 -> V_191 ( V_138 , V_189 , V_190 ) ;
return V_190 ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_146 * V_49 = V_2 -> V_49 ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_93 ( V_38 ) ;
if ( ! V_38 -> V_192 )
V_38 -> V_192 = V_49 -> V_193 ;
if ( ! V_38 -> V_192 )
return - V_194 ;
return 0 ;
}
static void F_94 ( struct V_195 * V_53 ,
struct V_146 * V_49 )
{
const struct V_196 * V_197 = V_53 -> V_66 . V_198 ;
if ( ! V_197 )
return;
if ( F_95 ( V_197 , L_21 , NULL ) )
V_49 -> V_50 |= V_186 ;
}
struct V_1 *
F_96 ( struct V_195 * V_53 )
{
struct V_1 * V_2 ;
struct V_37 * V_38 ;
V_38 = F_97 ( sizeof( struct V_1 ) , & V_53 -> V_66 ) ;
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
int F_100 ( struct V_1 * V_199 ,
struct V_146 * V_49 )
{
struct V_195 * V_53 = V_199 -> V_53 ;
struct V_37 * V_38 = V_199 -> V_38 ;
struct V_200 * V_201 ;
int V_160 ;
T_1 V_74 = V_75 ;
F_94 ( V_53 , V_49 ) ;
if ( ! ( V_49 -> V_50 & V_120 ) )
V_199 -> V_202 = NULL ;
V_201 = F_101 ( V_53 , V_203 , 0 ) ;
if ( ! V_201 )
return - V_89 ;
V_160 = F_102 ( V_38 ) ;
if ( V_160 < 0 )
goto V_204;
V_199 -> V_49 = V_49 ;
F_103 ( V_53 , V_38 ) ;
V_199 -> V_168 = V_49 -> V_168 ;
V_199 -> V_52 = V_49 -> V_52 ;
V_160 = F_92 ( V_199 ) ;
if ( V_160 < 0 )
goto V_204;
V_199 -> V_205 = F_104 ( V_201 -> V_206 , F_105 ( V_201 ) ) ;
if ( ! V_199 -> V_205 ) {
V_160 = - V_207 ;
goto V_204;
}
V_38 -> V_208 = & V_209 ;
V_38 -> V_151 |= V_210 | V_49 -> V_211 ;
V_38 -> V_212 |= V_49 -> V_213 ;
V_38 -> V_214 = 32 ;
V_38 -> V_215 = 512 ;
V_38 -> V_216 = ( V_217 / V_38 -> V_215 ) *
V_38 -> V_214 ;
V_38 -> V_218 = V_38 -> V_215 * V_38 -> V_216 ;
V_38 -> V_219 = V_38 -> V_218 ;
V_199 -> V_98 = ! ( V_49 -> V_50 & V_220 ||
V_38 -> V_151 & V_221 ||
V_38 -> V_151 & V_222 ||
V_38 -> V_223 . V_224 >= 0 ) ;
if ( F_75 ( V_199 ) < 0 ) {
V_38 -> V_166 = V_49 -> V_225 ;
V_38 -> V_48 = V_38 -> V_166 / 512 ;
}
if ( V_38 -> V_48 == 0 ) {
V_160 = - V_89 ;
goto V_204;
}
if ( V_199 -> V_98 )
F_106 ( & V_53 -> V_66 ) ;
F_21 ( V_199 ) ;
F_24 ( V_199 ) ;
V_199 -> V_4 = F_54 ( V_199 , V_6 ) ;
F_3 ( V_199 , V_226 ) ;
if ( ! V_199 -> V_110 )
V_74 |= V_125 ;
if ( ! V_199 -> V_109 )
V_74 |= V_126 ;
if ( ! V_199 -> V_98 )
V_74 &= ~ ( V_99 | V_100 ) ;
V_199 -> V_4 &= ~ V_74 ;
V_199 -> V_40 = false ;
if ( V_49 -> V_50 & V_148 ) {
V_199 -> V_41 = V_42 ;
F_16 ( V_199 , V_45 , V_199 -> V_41 ) ;
F_16 ( V_199 , V_44 , 0x0000 ) ;
}
F_107 ( & V_199 -> V_64 ) ;
F_108 ( & V_199 -> V_176 ) ;
F_109 ( & V_199 -> V_61 , F_25 ) ;
F_110 ( & V_199 -> V_71 , F_37 ) ;
F_111 ( V_199 , V_49 ) ;
F_112 ( & V_53 -> V_66 ) ;
F_113 ( & V_53 -> V_66 , 50 ) ;
F_114 ( & V_53 -> V_66 ) ;
F_115 ( & V_53 -> V_66 ) ;
V_160 = F_116 ( V_38 ) ;
if ( V_160 < 0 ) {
F_117 ( V_199 ) ;
return V_160 ;
}
F_118 ( & V_53 -> V_66 , 100 ) ;
if ( V_49 -> V_50 & V_220 ) {
V_160 = F_119 ( V_38 , V_49 -> V_227 , 0 ) ;
if ( V_160 < 0 ) {
F_117 ( V_199 ) ;
return V_160 ;
}
F_120 ( V_38 ) ;
}
return 0 ;
V_204:
return V_160 ;
}
void F_117 ( struct V_1 * V_2 )
{
struct V_195 * V_53 = V_2 -> V_53 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! V_2 -> V_98 )
F_14 ( & V_53 -> V_66 ) ;
F_121 ( & V_53 -> V_66 ) ;
F_122 ( V_38 ) ;
F_123 ( & V_2 -> V_71 ) ;
F_124 ( & V_2 -> V_61 ) ;
F_125 ( V_2 ) ;
F_126 ( & V_53 -> V_66 ) ;
F_127 ( & V_53 -> V_66 ) ;
F_128 ( V_2 -> V_205 ) ;
}
int F_129 ( struct V_175 * V_66 )
{
struct V_37 * V_38 = F_130 ( V_66 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_3 ( V_2 , V_226 ) ;
if ( V_2 -> V_185 )
F_21 ( V_2 ) ;
if ( V_2 -> V_228 )
V_2 -> V_228 ( V_2 -> V_53 ) ;
return 0 ;
}
int F_131 ( struct V_175 * V_66 )
{
struct V_37 * V_38 = F_130 ( V_66 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_24 ( V_2 ) ;
F_75 ( V_2 ) ;
if ( V_2 -> V_185 ) {
F_19 ( V_2 , V_2 -> V_185 ) ;
F_23 ( V_2 ) ;
}
F_132 ( V_2 , true ) ;
return 0 ;
}

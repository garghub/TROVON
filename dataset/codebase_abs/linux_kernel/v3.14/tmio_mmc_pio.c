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
F_16 ( 10 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 -> V_52 & V_53 ) {
F_14 ( V_2 , V_54 , 0x0000 ) ;
F_16 ( 10 ) ;
}
F_14 ( V_2 , V_50 , ~ 0x0100 &
F_18 ( V_2 , V_50 ) ) ;
F_16 ( 10 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_50 , 0x0100 |
F_18 ( V_2 , V_50 ) ) ;
F_16 ( 10 ) ;
if ( V_2 -> V_51 -> V_52 & V_53 ) {
F_14 ( V_2 , V_54 , 0x0100 ) ;
F_16 ( 10 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_55 , 0x0000 ) ;
if ( V_2 -> V_51 -> V_52 & V_53 )
F_14 ( V_2 , V_56 , 0x0000 ) ;
F_16 ( 10 ) ;
F_14 ( V_2 , V_55 , 0x0001 ) ;
if ( V_2 -> V_51 -> V_52 & V_53 )
F_14 ( V_2 , V_56 , 0x0001 ) ;
F_16 ( 10 ) ;
}
static void F_21 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_22 ( V_58 , struct V_1 ,
V_59 . V_58 ) ;
struct V_60 * V_61 ;
unsigned long V_52 ;
F_23 ( & V_2 -> V_62 , V_52 ) ;
V_61 = V_2 -> V_61 ;
if ( F_24 ( V_61 )
|| F_25 ( V_2 -> V_63 +
F_26 ( 2000 ) ) ) {
F_27 ( & V_2 -> V_62 , V_52 ) ;
return;
}
F_28 ( & V_2 -> V_49 -> V_64 ,
L_3 ,
V_61 -> V_65 -> V_66 ) ;
if ( V_2 -> V_9 )
V_2 -> V_9 -> error = - V_67 ;
else if ( V_2 -> V_65 )
V_2 -> V_65 -> error = - V_67 ;
else
V_61 -> V_65 -> error = - V_67 ;
V_2 -> V_65 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_68 = false ;
F_27 ( & V_2 -> V_62 , V_52 ) ;
F_20 ( V_2 ) ;
V_2 -> V_61 = NULL ;
F_29 ( V_2 ) ;
F_30 ( V_2 -> V_38 , V_61 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
unsigned long V_52 ;
F_23 ( & V_2 -> V_62 , V_52 ) ;
V_61 = V_2 -> V_61 ;
if ( F_24 ( V_61 ) ) {
F_27 ( & V_2 -> V_62 , V_52 ) ;
return;
}
V_2 -> V_65 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_68 = false ;
F_32 ( & V_2 -> V_59 ) ;
V_2 -> V_61 = NULL ;
F_27 ( & V_2 -> V_62 , V_52 ) ;
if ( V_61 -> V_65 -> error || ( V_61 -> V_9 && V_61 -> V_9 -> error ) )
F_29 ( V_2 ) ;
F_30 ( V_2 -> V_38 , V_61 ) ;
}
static void F_33 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_22 ( V_58 , struct V_1 ,
V_69 ) ;
F_31 ( V_2 ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_70 * V_65 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_71 = V_65 -> V_66 ;
T_1 V_72 = V_73 ;
if ( V_65 -> V_66 == V_74 && ! V_65 -> V_75 ) {
F_14 ( V_2 , V_76 , 0x001 ) ;
return 0 ;
}
switch ( F_35 ( V_65 ) ) {
case V_77 : V_71 |= V_78 ; break;
case V_79 : V_71 |= V_80 ; break;
case V_81 : V_71 |= V_82 ; break;
case V_83 : V_71 |= V_84 ; break;
case V_85 : V_71 |= V_86 ; break;
default:
F_9 ( L_4 , F_35 ( V_65 ) ) ;
return - V_87 ;
}
V_2 -> V_65 = V_65 ;
if ( V_9 ) {
V_71 |= V_88 ;
if ( V_9 -> V_89 > 1 ) {
F_14 ( V_2 , V_76 , 0x100 ) ;
V_71 |= V_90 ;
}
if ( V_9 -> V_52 & V_91 )
V_71 |= V_92 ;
}
if ( ! V_2 -> V_93 )
V_72 &= ~ ( V_94 | V_95 ) ;
F_1 ( V_2 , V_72 ) ;
F_2 ( V_2 , V_96 , V_65 -> V_75 ) ;
F_14 ( V_2 , V_97 , V_71 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_98 ;
unsigned short * V_99 ;
unsigned int V_100 ;
unsigned long V_52 ;
if ( ( V_2 -> V_101 || V_2 -> V_102 ) && ! V_2 -> V_68 ) {
F_37 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_98 = F_38 ( V_2 -> V_11 , & V_52 ) ;
V_99 = ( unsigned short * ) ( V_98 + V_2 -> V_14 ) ;
V_100 = V_2 -> V_11 -> V_103 - V_2 -> V_14 ;
if ( V_100 > V_9 -> V_104 )
V_100 = V_9 -> V_104 ;
F_9 ( L_7 ,
V_100 , V_2 -> V_14 , V_9 -> V_52 ) ;
if ( V_9 -> V_52 & V_91 )
F_39 ( V_2 , V_105 , V_99 , V_100 >> 1 ) ;
else
F_40 ( V_2 , V_105 , V_99 , V_100 >> 1 ) ;
V_2 -> V_14 += V_100 ;
F_41 ( V_2 -> V_11 , & V_52 , V_98 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_103 )
F_6 ( V_2 ) ;
return;
}
static void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_106 ) {
unsigned long V_52 ;
void * V_107 = F_38 ( V_2 -> V_13 , & V_52 ) ;
memcpy ( V_107 , V_2 -> V_108 , V_2 -> V_106 . V_103 ) ;
F_41 ( V_2 -> V_13 , & V_52 , V_107 ) ;
}
}
void F_43 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_70 * V_109 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_28 ( & V_2 -> V_49 -> V_64 , L_8 ) ;
return;
}
V_109 = V_9 -> V_109 ;
if ( ! V_9 -> error )
V_9 -> V_110 = V_9 -> V_89 * V_9 -> V_104 ;
else
V_9 -> V_110 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_52 & V_91 ) {
if ( V_2 -> V_102 && ! V_2 -> V_68 )
F_42 ( V_2 ) ;
F_44 ( & V_2 -> V_49 -> V_64 , L_10 ,
V_2 -> V_61 ) ;
} else {
F_44 ( & V_2 -> V_49 -> V_64 , L_11 ,
V_2 -> V_61 ) ;
}
if ( V_109 ) {
if ( V_109 -> V_66 == V_74 && ! V_109 -> V_75 )
F_14 ( V_2 , V_76 , 0x000 ) ;
else
F_45 () ;
}
F_46 ( & V_2 -> V_69 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_48 ( & V_2 -> V_62 ) ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 )
goto V_111;
if ( V_2 -> V_101 && ( V_9 -> V_52 & V_112 ) && ! V_2 -> V_68 ) {
if ( ! ( F_49 ( V_2 , V_7 ) & V_113 ) ) {
F_3 ( V_2 , V_114 ) ;
F_50 ( & V_2 -> V_115 ) ;
}
} else if ( V_2 -> V_102 && ( V_9 -> V_52 & V_91 ) && ! V_2 -> V_68 ) {
F_3 ( V_2 , V_114 ) ;
F_50 ( & V_2 -> V_115 ) ;
} else {
F_43 ( V_2 ) ;
F_3 ( V_2 , V_116 | V_117 ) ;
}
V_111:
F_51 ( & V_2 -> V_62 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
unsigned int V_118 )
{
struct V_70 * V_65 = V_2 -> V_65 ;
int V_3 , V_119 ;
F_48 ( & V_2 -> V_62 ) ;
if ( ! V_2 -> V_65 ) {
F_9 ( L_12 ) ;
goto V_111;
}
V_2 -> V_65 = NULL ;
for ( V_3 = 3 , V_119 = V_120 ; V_3 >= 0 ; V_3 -- , V_119 += 4 )
V_65 -> V_121 [ V_3 ] = F_49 ( V_2 , V_119 ) ;
if ( V_65 -> V_52 & V_122 ) {
V_65 -> V_121 [ 0 ] = ( V_65 -> V_121 [ 0 ] << 8 ) | ( V_65 -> V_121 [ 1 ] >> 24 ) ;
V_65 -> V_121 [ 1 ] = ( V_65 -> V_121 [ 1 ] << 8 ) | ( V_65 -> V_121 [ 2 ] >> 24 ) ;
V_65 -> V_121 [ 2 ] = ( V_65 -> V_121 [ 2 ] << 8 ) | ( V_65 -> V_121 [ 3 ] >> 24 ) ;
V_65 -> V_121 [ 3 ] <<= 8 ;
} else if ( V_65 -> V_52 & V_85 ) {
V_65 -> V_121 [ 0 ] = V_65 -> V_121 [ 3 ] ;
}
if ( V_118 & V_123 )
V_65 -> error = - V_67 ;
else if ( V_118 & V_124 && V_65 -> V_52 & V_125 )
V_65 -> error = - V_126 ;
if ( V_2 -> V_9 && ! V_65 -> error ) {
if ( V_2 -> V_9 -> V_52 & V_91 ) {
if ( V_2 -> V_68 || ! V_2 -> V_102 )
F_1 ( V_2 , V_116 ) ;
else
F_50 ( & V_2 -> V_127 ) ;
} else {
if ( V_2 -> V_68 || ! V_2 -> V_101 )
F_1 ( V_2 , V_117 ) ;
else
F_50 ( & V_2 -> V_127 ) ;
}
} else {
F_46 ( & V_2 -> V_69 ) ;
}
V_111:
F_51 ( & V_2 -> V_62 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
int * V_128 , int * V_15 )
{
* V_15 = F_49 ( V_2 , V_7 ) ;
* V_128 = * V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( * V_15 ) ;
F_8 ( * V_128 ) ;
}
static bool F_54 ( struct V_1 * V_2 ,
int V_128 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_128 & ( V_95 | V_94 ) ) {
F_4 ( V_2 , V_95 |
V_94 ) ;
if ( ( ( ( V_128 & V_94 ) && V_38 -> V_129 ) ||
( ( V_128 & V_95 ) && ! V_38 -> V_129 ) ) &&
! F_55 ( & V_38 -> V_130 . V_58 ) )
F_56 ( V_2 -> V_38 , F_26 ( 100 ) ) ;
return true ;
}
return false ;
}
T_2 F_57 ( int V_131 , void * V_132 )
{
unsigned int V_128 , V_15 ;
struct V_1 * V_2 = V_132 ;
F_53 ( V_2 , & V_128 , & V_15 ) ;
F_54 ( V_2 , V_128 , V_15 ) ;
return V_133 ;
}
static bool F_58 ( struct V_1 * V_2 ,
int V_128 , int V_15 )
{
if ( V_128 & ( V_134 | V_123 ) ) {
F_4 ( V_2 ,
V_134 |
V_123 ) ;
F_52 ( V_2 , V_15 ) ;
return true ;
}
if ( V_128 & ( V_135 | V_136 ) ) {
F_4 ( V_2 , V_135 | V_136 ) ;
F_36 ( V_2 ) ;
return true ;
}
if ( V_128 & V_114 ) {
F_4 ( V_2 , V_114 ) ;
F_47 ( V_2 ) ;
return true ;
}
return false ;
}
T_2 F_59 ( int V_131 , void * V_132 )
{
unsigned int V_128 , V_15 ;
struct V_1 * V_2 = V_132 ;
F_53 ( V_2 , & V_128 , & V_15 ) ;
F_58 ( V_2 , V_128 , V_15 ) ;
return V_133 ;
}
T_2 F_60 ( int V_131 , void * V_132 )
{
struct V_1 * V_2 = V_132 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_137 * V_51 = V_2 -> V_51 ;
unsigned int V_128 , V_15 ;
if ( ! ( V_51 -> V_52 & V_138 ) )
return V_133 ;
V_15 = F_18 ( V_2 , V_139 ) ;
V_128 = V_15 & V_41 & ~ V_2 -> V_4 ;
F_14 ( V_2 , V_139 , V_15 & ~ V_41 ) ;
if ( V_38 -> V_140 & V_141 && V_128 & V_42 )
F_61 ( V_38 ) ;
return V_133 ;
}
T_2 F_62 ( int V_131 , void * V_132 )
{
struct V_1 * V_2 = V_132 ;
unsigned int V_128 , V_15 ;
F_9 ( L_13 ) ;
F_53 ( V_2 , & V_128 , & V_15 ) ;
if ( F_54 ( V_2 , V_128 , V_15 ) )
return V_133 ;
if ( F_58 ( V_2 , V_128 , V_15 ) )
return V_133 ;
F_60 ( V_131 , V_132 ) ;
return V_133 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_137 * V_51 = V_2 -> V_51 ;
F_9 ( L_14 ,
V_9 -> V_104 , V_9 -> V_89 ) ;
if ( V_2 -> V_38 -> V_142 . V_143 == V_144 ) {
int V_145 = V_51 -> V_52 & V_146 ;
if ( V_9 -> V_104 < 2 || ( V_9 -> V_104 < 4 && ! V_145 ) ) {
F_37 ( L_15 ,
F_64 ( V_2 -> V_38 ) , V_9 -> V_104 ) ;
return - V_87 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_14 ( V_2 , V_147 , V_9 -> V_104 ) ;
F_14 ( V_2 , V_148 , V_9 -> V_89 ) ;
F_65 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_66 ( struct V_37 * V_38 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_52 ;
int V_149 ;
F_23 ( & V_2 -> V_62 , V_52 ) ;
if ( V_2 -> V_61 ) {
F_9 ( L_16 ) ;
if ( F_67 ( V_2 -> V_61 ) ) {
F_27 ( & V_2 -> V_62 , V_52 ) ;
V_61 -> V_65 -> error = - V_150 ;
F_30 ( V_38 , V_61 ) ;
return;
}
}
V_2 -> V_63 = V_151 ;
F_68 () ;
V_2 -> V_61 = V_61 ;
F_27 ( & V_2 -> V_62 , V_52 ) ;
if ( V_61 -> V_9 ) {
V_149 = F_63 ( V_2 , V_61 -> V_9 ) ;
if ( V_149 )
goto V_152;
}
V_149 = F_34 ( V_2 , V_61 -> V_65 ) ;
if ( ! V_149 ) {
F_69 ( & V_2 -> V_59 ,
F_26 ( 2000 ) ) ;
return;
}
V_152:
V_2 -> V_68 = false ;
V_2 -> V_61 = NULL ;
V_61 -> V_65 -> error = V_149 ;
F_30 ( V_38 , V_61 ) ;
}
static int F_70 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_137 * V_51 = V_2 -> V_51 ;
int V_149 ;
if ( ! V_51 -> V_153 )
return - V_154 ;
V_149 = V_51 -> V_153 ( V_2 -> V_49 , & V_38 -> V_155 ) ;
if ( ! V_149 )
V_38 -> V_47 = V_38 -> V_155 / 512 ;
return V_149 ;
}
static void F_71 ( struct V_1 * V_2 , unsigned short V_156 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
int V_149 = 0 ;
if ( V_2 -> V_157 )
V_2 -> V_157 ( V_2 -> V_49 , 1 ) ;
if ( ! F_67 ( V_38 -> V_158 . V_159 ) ) {
V_149 = F_72 ( V_38 , V_38 -> V_158 . V_159 , V_156 ) ;
F_73 ( 200 ) ;
}
if ( ! F_67 ( V_38 -> V_158 . V_160 ) && ! V_149 ) {
V_149 = F_74 ( V_38 -> V_158 . V_160 ) ;
F_73 ( 200 ) ;
}
if ( V_149 < 0 )
F_44 ( & V_2 -> V_49 -> V_64 , L_17 ,
V_149 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! F_67 ( V_38 -> V_158 . V_160 ) )
F_76 ( V_38 -> V_158 . V_160 ) ;
if ( ! F_67 ( V_38 -> V_158 . V_159 ) )
F_72 ( V_38 , V_38 -> V_158 . V_159 , 0 ) ;
if ( V_2 -> V_157 )
V_2 -> V_157 ( V_2 -> V_49 , 0 ) ;
}
static void F_77 ( struct V_37 * V_38 , struct V_161 * V_142 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_162 * V_64 = & V_2 -> V_49 -> V_64 ;
unsigned long V_52 ;
F_78 ( & V_2 -> V_163 ) ;
F_23 ( & V_2 -> V_62 , V_52 ) ;
if ( V_2 -> V_61 ) {
if ( F_67 ( V_2 -> V_61 ) ) {
F_44 ( V_64 ,
L_18 ,
V_164 -> V_165 , F_79 ( V_164 ) ,
V_142 -> clock , V_142 -> V_166 ) ;
V_2 -> V_61 = F_80 ( - V_167 ) ;
} else {
F_44 ( V_64 ,
L_19 ,
V_164 -> V_165 , F_79 ( V_164 ) ,
V_2 -> V_61 -> V_65 -> V_66 , V_2 -> V_63 , V_151 ) ;
}
F_27 ( & V_2 -> V_62 , V_52 ) ;
F_81 ( & V_2 -> V_163 ) ;
return;
}
V_2 -> V_61 = F_80 ( - V_168 ) ;
F_27 ( & V_2 -> V_62 , V_52 ) ;
if ( V_142 -> V_166 == V_169 && V_142 -> clock ) {
if ( V_2 -> V_170 != V_171 ) {
F_70 ( V_38 ) ;
F_82 ( V_64 ) ;
if ( V_2 -> V_172 ) {
F_20 ( V_2 ) ;
V_2 -> V_172 = false ;
}
}
if ( V_2 -> V_170 == V_173 )
F_20 ( V_2 ) ;
F_15 ( V_2 , V_142 -> clock ) ;
if ( V_2 -> V_170 == V_173 )
F_71 ( V_2 , V_142 -> V_156 ) ;
V_2 -> V_170 = V_171 ;
F_19 ( V_2 ) ;
} else if ( V_142 -> V_166 != V_174 ) {
struct V_137 * V_51 = V_2 -> V_51 ;
unsigned int V_175 = V_2 -> V_170 ;
if ( V_175 != V_173 ) {
if ( V_142 -> V_166 == V_176 ) {
F_75 ( V_2 ) ;
V_2 -> V_170 = V_173 ;
} else {
V_2 -> V_170 = V_177 ;
}
}
if ( V_175 == V_171 ) {
F_17 ( V_2 ) ;
F_83 ( V_64 ) ;
if ( V_51 -> V_178 )
V_51 -> V_178 ( V_2 -> V_49 ) ;
}
}
if ( V_2 -> V_170 != V_173 ) {
switch ( V_142 -> V_143 ) {
case V_179 :
F_14 ( V_2 , V_180 , 0x80e0 ) ;
break;
case V_144 :
F_14 ( V_2 , V_180 , 0x00e0 ) ;
break;
}
}
F_73 ( 140 ) ;
if ( F_84 ( V_2 -> V_61 ) == - V_167 )
F_44 ( & V_2 -> V_49 -> V_64 ,
L_20 ,
V_164 -> V_165 , F_79 ( V_164 ) ,
V_142 -> clock , V_142 -> V_166 ) ;
V_2 -> V_61 = NULL ;
F_81 ( & V_2 -> V_163 ) ;
}
static int F_85 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_137 * V_51 = V_2 -> V_51 ;
int V_149 = F_86 ( V_38 ) ;
if ( V_149 >= 0 )
return V_149 ;
return ! ( ( V_51 -> V_52 & V_181 ) ||
( F_49 ( V_2 , V_7 ) & V_182 ) ) ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_137 * V_51 = V_2 -> V_51 ;
struct V_37 * V_38 = V_2 -> V_38 ;
F_88 ( V_38 ) ;
if ( ! V_38 -> V_183 )
V_38 -> V_183 = V_51 -> V_184 ;
if ( ! V_38 -> V_183 )
return - V_185 ;
return 0 ;
}
static void F_89 ( struct V_186 * V_49 ,
struct V_137 * V_51 )
{
const struct V_187 * V_188 = V_49 -> V_64 . V_189 ;
if ( ! V_188 )
return;
if ( F_90 ( V_188 , L_21 , NULL ) )
V_51 -> V_52 |= V_181 ;
}
int F_91 ( struct V_1 * * V_2 ,
struct V_186 * V_49 ,
struct V_137 * V_51 )
{
struct V_1 * V_190 ;
struct V_37 * V_38 ;
struct V_191 * V_192 ;
int V_149 ;
T_1 V_72 = V_73 ;
F_89 ( V_49 , V_51 ) ;
if ( ! ( V_51 -> V_52 & V_193 ) )
V_51 -> V_194 = NULL ;
V_192 = F_92 ( V_49 , V_195 , 0 ) ;
if ( ! V_192 )
return - V_87 ;
V_38 = F_93 ( sizeof( struct V_1 ) , & V_49 -> V_64 ) ;
if ( ! V_38 )
return - V_196 ;
V_149 = F_94 ( V_38 ) ;
if ( V_149 < 0 )
goto V_197;
V_51 -> V_64 = & V_49 -> V_64 ;
V_190 = F_13 ( V_38 ) ;
V_190 -> V_51 = V_51 ;
V_190 -> V_38 = V_38 ;
V_190 -> V_49 = V_49 ;
F_95 ( V_49 , V_38 ) ;
V_190 -> V_157 = V_51 -> V_157 ;
V_190 -> V_48 = V_51 -> V_48 ;
V_149 = F_87 ( V_190 ) ;
if ( V_149 < 0 )
goto V_197;
V_190 -> V_198 = F_96 ( V_192 -> V_199 , F_97 ( V_192 ) ) ;
if ( ! V_190 -> V_198 ) {
V_149 = - V_196 ;
goto V_197;
}
V_38 -> V_200 = & V_201 ;
V_38 -> V_140 |= V_202 | V_51 -> V_203 ;
V_38 -> V_204 |= V_51 -> V_205 ;
V_38 -> V_206 = 32 ;
V_38 -> V_207 = 512 ;
V_38 -> V_208 = ( V_209 / V_38 -> V_207 ) *
V_38 -> V_206 ;
V_38 -> V_210 = V_38 -> V_207 * V_38 -> V_208 ;
V_38 -> V_211 = V_38 -> V_210 ;
V_190 -> V_93 = ! ( V_51 -> V_52 & V_212 ||
V_38 -> V_140 & V_213 ||
V_38 -> V_140 & V_214 ||
V_38 -> V_215 . V_216 >= 0 ) ;
V_190 -> V_170 = V_173 ;
F_98 ( & V_49 -> V_64 ) ;
V_149 = F_99 ( & V_49 -> V_64 ) ;
if ( V_149 < 0 )
goto V_217;
if ( F_70 ( V_38 ) < 0 ) {
V_38 -> V_155 = V_51 -> V_218 ;
V_38 -> V_47 = V_38 -> V_155 / 512 ;
}
if ( V_190 -> V_93 )
F_100 ( & V_49 -> V_64 ) ;
F_17 ( V_190 ) ;
F_20 ( V_190 ) ;
V_190 -> V_4 = F_49 ( V_190 , V_6 ) ;
F_3 ( V_190 , V_219 ) ;
if ( ! V_190 -> V_102 )
V_72 |= V_116 ;
if ( ! V_190 -> V_101 )
V_72 |= V_117 ;
if ( ! V_190 -> V_93 )
V_72 &= ~ ( V_94 | V_95 ) ;
V_190 -> V_4 &= ~ V_72 ;
if ( V_51 -> V_52 & V_138 )
F_12 ( V_38 , 0 ) ;
F_101 ( & V_190 -> V_62 ) ;
F_102 ( & V_190 -> V_163 ) ;
F_103 ( & V_190 -> V_59 , F_21 ) ;
F_104 ( & V_190 -> V_69 , F_33 ) ;
F_105 ( V_190 , V_51 ) ;
V_149 = F_106 ( V_38 ) ;
if ( V_51 -> V_178 )
V_51 -> V_178 ( V_49 ) ;
if ( V_149 < 0 ) {
F_107 ( V_190 ) ;
return V_149 ;
}
F_108 ( & V_49 -> V_64 , 100 ) ;
if ( V_51 -> V_52 & V_212 ) {
V_149 = F_109 ( V_38 , V_51 -> V_220 , 0 ) ;
if ( V_149 < 0 ) {
F_107 ( V_190 ) ;
return V_149 ;
}
}
* V_2 = V_190 ;
return 0 ;
V_217:
F_110 ( & V_49 -> V_64 ) ;
F_111 ( V_190 -> V_198 ) ;
V_197:
F_112 ( V_38 ) ;
return V_149 ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_186 * V_49 = V_2 -> V_49 ;
struct V_37 * V_38 = V_2 -> V_38 ;
if ( ! V_2 -> V_93 )
F_82 ( & V_49 -> V_64 ) ;
F_113 ( & V_49 -> V_64 ) ;
F_114 ( V_38 ) ;
F_115 ( & V_2 -> V_69 ) ;
F_116 ( & V_2 -> V_59 ) ;
F_117 ( V_2 ) ;
F_118 ( & V_49 -> V_64 ) ;
F_110 ( & V_49 -> V_64 ) ;
F_111 ( V_2 -> V_198 ) ;
F_112 ( V_38 ) ;
}
int F_119 ( struct V_162 * V_64 )
{
struct V_37 * V_38 = F_120 ( V_64 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_3 ( V_2 , V_219 ) ;
return 0 ;
}
int F_121 ( struct V_162 * V_64 )
{
struct V_37 * V_38 = F_120 ( V_64 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_122 ( V_2 , true ) ;
V_2 -> V_172 = true ;
return 0 ;
}
int F_123 ( struct V_162 * V_64 )
{
return 0 ;
}
int F_124 ( struct V_162 * V_64 )
{
struct V_37 * V_38 = F_120 ( V_64 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
F_122 ( V_2 , true ) ;
return 0 ;
}

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
V_2 -> V_40 = 1 ;
V_2 -> V_41 = V_42 &
~ V_43 ;
F_14 ( V_2 , V_44 , 0x0001 ) ;
F_14 ( V_2 , V_45 , V_2 -> V_41 ) ;
} else {
V_2 -> V_41 = V_42 ;
F_14 ( V_2 , V_45 , V_2 -> V_41 ) ;
F_14 ( V_2 , V_44 , 0x0000 ) ;
V_2 -> V_40 = 0 ;
}
}
static void F_15 ( struct V_1 * V_2 , int V_46 )
{
T_1 V_47 = 0 , clock ;
if ( V_46 ) {
for ( clock = V_2 -> V_38 -> V_48 , V_47 = 0x80000080 ;
V_46 >= ( clock << 1 ) ; V_47 >>= 1 )
clock <<= 1 ;
V_47 |= 0x100 ;
}
if ( V_2 -> V_49 )
V_2 -> V_49 ( V_2 -> V_50 , ( V_47 >> 22 ) & 1 ) ;
F_14 ( V_2 , V_51 , V_47 & 0x1ff ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = F_17 ( V_2 -> V_50 , V_54 , 0 ) ;
if ( F_18 ( V_53 ) > 0x100 ) {
F_14 ( V_2 , V_55 , 0x0000 ) ;
F_19 ( 10 ) ;
}
F_14 ( V_2 , V_51 , ~ 0x0100 &
F_20 ( V_2 , V_51 ) ) ;
F_19 ( 10 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = F_17 ( V_2 -> V_50 , V_54 , 0 ) ;
F_14 ( V_2 , V_51 , 0x0100 |
F_20 ( V_2 , V_51 ) ) ;
F_19 ( 10 ) ;
if ( F_18 ( V_53 ) > 0x100 ) {
F_14 ( V_2 , V_55 , 0x0100 ) ;
F_19 ( 10 ) ;
}
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = F_17 ( V_2 -> V_50 , V_54 , 0 ) ;
F_14 ( V_2 , V_56 , 0x0000 ) ;
if ( F_18 ( V_53 ) > 0x100 )
F_14 ( V_2 , V_57 , 0x0000 ) ;
F_19 ( 10 ) ;
F_14 ( V_2 , V_56 , 0x0001 ) ;
if ( F_18 ( V_53 ) > 0x100 )
F_14 ( V_2 , V_57 , 0x0001 ) ;
F_19 ( 10 ) ;
}
static void F_23 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_24 ( V_59 , struct V_1 ,
V_60 . V_59 ) ;
struct V_61 * V_62 ;
unsigned long V_63 ;
F_25 ( & V_2 -> V_64 , V_63 ) ;
V_62 = V_2 -> V_62 ;
if ( F_26 ( V_62 )
|| F_27 ( V_2 -> V_65 +
F_28 ( 2000 ) ) ) {
F_29 ( & V_2 -> V_64 , V_63 ) ;
return;
}
F_30 ( & V_2 -> V_50 -> V_66 ,
L_3 ,
V_62 -> V_67 -> V_68 ) ;
if ( V_2 -> V_9 )
V_2 -> V_9 -> error = - V_69 ;
else if ( V_2 -> V_67 )
V_2 -> V_67 -> error = - V_69 ;
else
V_62 -> V_67 -> error = - V_69 ;
V_2 -> V_67 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_70 = false ;
F_29 ( & V_2 -> V_64 , V_63 ) ;
F_22 ( V_2 ) ;
V_2 -> V_62 = NULL ;
F_31 ( V_2 ) ;
F_32 ( V_2 -> V_38 , V_62 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
unsigned long V_63 ;
F_25 ( & V_2 -> V_64 , V_63 ) ;
V_62 = V_2 -> V_62 ;
if ( F_26 ( V_62 ) ) {
F_29 ( & V_2 -> V_64 , V_63 ) ;
return;
}
V_2 -> V_67 = NULL ;
V_2 -> V_9 = NULL ;
V_2 -> V_70 = false ;
F_34 ( & V_2 -> V_60 ) ;
V_2 -> V_62 = NULL ;
F_29 ( & V_2 -> V_64 , V_63 ) ;
if ( V_62 -> V_67 -> error || ( V_62 -> V_9 && V_62 -> V_9 -> error ) )
F_31 ( V_2 ) ;
F_32 ( V_2 -> V_38 , V_62 ) ;
}
static void F_35 ( struct V_58 * V_59 )
{
struct V_1 * V_2 = F_24 ( V_59 , struct V_1 ,
V_71 ) ;
F_33 ( V_2 ) ;
}
static int F_36 ( struct V_1 * V_2 , struct V_72 * V_67 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_73 = V_67 -> V_68 ;
if ( V_67 -> V_68 == 12 && ! V_67 -> V_74 ) {
F_14 ( V_2 , V_75 , 0x001 ) ;
return 0 ;
}
switch ( F_37 ( V_67 ) ) {
case V_76 : V_73 |= V_77 ; break;
case V_78 : V_73 |= V_79 ; break;
case V_80 : V_73 |= V_81 ; break;
case V_82 : V_73 |= V_83 ; break;
case V_84 : V_73 |= V_85 ; break;
default:
F_9 ( L_4 , F_37 ( V_67 ) ) ;
return - V_86 ;
}
V_2 -> V_67 = V_67 ;
if ( V_9 ) {
V_73 |= V_87 ;
if ( V_9 -> V_88 > 1 ) {
F_14 ( V_2 , V_75 , 0x100 ) ;
V_73 |= V_89 ;
}
if ( V_9 -> V_63 & V_90 )
V_73 |= V_91 ;
}
F_1 ( V_2 , V_92 ) ;
F_2 ( V_2 , V_93 , V_67 -> V_74 ) ;
F_14 ( V_2 , V_94 , V_73 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
void * V_95 ;
unsigned short * V_96 ;
unsigned int V_97 ;
unsigned long V_63 ;
if ( ( V_2 -> V_98 || V_2 -> V_99 ) && ! V_2 -> V_70 ) {
F_39 ( L_5 ) ;
return;
} else if ( ! V_9 ) {
F_9 ( L_6 ) ;
return;
}
V_95 = F_40 ( V_2 -> V_11 , & V_63 ) ;
V_96 = ( unsigned short * ) ( V_95 + V_2 -> V_14 ) ;
V_97 = V_2 -> V_11 -> V_100 - V_2 -> V_14 ;
if ( V_97 > V_9 -> V_101 )
V_97 = V_9 -> V_101 ;
F_9 ( L_7 ,
V_97 , V_2 -> V_14 , V_9 -> V_63 ) ;
if ( V_9 -> V_63 & V_90 )
F_41 ( V_2 , V_102 , V_96 , V_97 >> 1 ) ;
else
F_42 ( V_2 , V_102 , V_96 , V_97 >> 1 ) ;
V_2 -> V_14 += V_97 ;
F_43 ( V_2 -> V_11 , & V_63 , V_95 ) ;
if ( V_2 -> V_14 == V_2 -> V_11 -> V_100 )
F_6 ( V_2 ) ;
return;
}
static void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 == & V_2 -> V_103 ) {
unsigned long V_63 ;
void * V_104 = F_40 ( V_2 -> V_13 , & V_63 ) ;
memcpy ( V_104 , V_2 -> V_105 , V_2 -> V_103 . V_100 ) ;
F_43 ( V_2 -> V_13 , & V_63 , V_104 ) ;
}
}
void F_45 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_72 * V_106 ;
V_2 -> V_9 = NULL ;
if ( ! V_9 ) {
F_30 ( & V_2 -> V_50 -> V_66 , L_8 ) ;
return;
}
V_106 = V_9 -> V_106 ;
if ( ! V_9 -> error )
V_9 -> V_107 = V_9 -> V_88 * V_9 -> V_101 ;
else
V_9 -> V_107 = 0 ;
F_9 ( L_9 ) ;
if ( V_9 -> V_63 & V_90 ) {
if ( V_2 -> V_99 && ! V_2 -> V_70 )
F_44 ( V_2 ) ;
F_46 ( & V_2 -> V_50 -> V_66 , L_10 ,
V_2 -> V_62 ) ;
} else {
F_46 ( & V_2 -> V_50 -> V_66 , L_11 ,
V_2 -> V_62 ) ;
}
if ( V_106 ) {
if ( V_106 -> V_68 == 12 && ! V_106 -> V_74 )
F_14 ( V_2 , V_75 , 0x000 ) ;
else
F_47 () ;
}
F_48 ( & V_2 -> V_71 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
F_50 ( & V_2 -> V_64 ) ;
V_9 = V_2 -> V_9 ;
if ( ! V_9 )
goto V_108;
if ( V_2 -> V_98 && ( V_9 -> V_63 & V_109 ) && ! V_2 -> V_70 ) {
if ( ! ( F_51 ( V_2 , V_7 ) & V_110 ) ) {
F_3 ( V_2 , V_111 ) ;
F_52 ( & V_2 -> V_112 ) ;
}
} else if ( V_2 -> V_99 && ( V_9 -> V_63 & V_90 ) && ! V_2 -> V_70 ) {
F_3 ( V_2 , V_111 ) ;
F_52 ( & V_2 -> V_112 ) ;
} else {
F_45 ( V_2 ) ;
F_3 ( V_2 , V_113 | V_114 ) ;
}
V_108:
F_53 ( & V_2 -> V_64 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
unsigned int V_115 )
{
struct V_72 * V_67 = V_2 -> V_67 ;
int V_3 , V_116 ;
F_50 ( & V_2 -> V_64 ) ;
if ( ! V_2 -> V_67 ) {
F_9 ( L_12 ) ;
goto V_108;
}
V_2 -> V_67 = NULL ;
for ( V_3 = 3 , V_116 = V_117 ; V_3 >= 0 ; V_3 -- , V_116 += 4 )
V_67 -> V_118 [ V_3 ] = F_51 ( V_2 , V_116 ) ;
if ( V_67 -> V_63 & V_119 ) {
V_67 -> V_118 [ 0 ] = ( V_67 -> V_118 [ 0 ] << 8 ) | ( V_67 -> V_118 [ 1 ] >> 24 ) ;
V_67 -> V_118 [ 1 ] = ( V_67 -> V_118 [ 1 ] << 8 ) | ( V_67 -> V_118 [ 2 ] >> 24 ) ;
V_67 -> V_118 [ 2 ] = ( V_67 -> V_118 [ 2 ] << 8 ) | ( V_67 -> V_118 [ 3 ] >> 24 ) ;
V_67 -> V_118 [ 3 ] <<= 8 ;
} else if ( V_67 -> V_63 & V_84 ) {
V_67 -> V_118 [ 0 ] = V_67 -> V_118 [ 3 ] ;
}
if ( V_115 & V_120 )
V_67 -> error = - V_69 ;
else if ( V_115 & V_121 && V_67 -> V_63 & V_122 )
V_67 -> error = - V_123 ;
if ( V_2 -> V_9 && ! V_67 -> error ) {
if ( V_2 -> V_9 -> V_63 & V_90 ) {
if ( V_2 -> V_70 || ! V_2 -> V_99 )
F_1 ( V_2 , V_113 ) ;
else
F_52 ( & V_2 -> V_124 ) ;
} else {
if ( V_2 -> V_70 || ! V_2 -> V_98 )
F_1 ( V_2 , V_114 ) ;
else
F_52 ( & V_2 -> V_124 ) ;
}
} else {
F_48 ( & V_2 -> V_71 ) ;
}
V_108:
F_53 ( & V_2 -> V_64 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
int * V_125 , int * V_15 )
{
* V_15 = F_51 ( V_2 , V_7 ) ;
* V_125 = * V_15 & V_5 & ~ V_2 -> V_4 ;
F_8 ( * V_15 ) ;
F_8 ( * V_125 ) ;
}
static bool F_56 ( struct V_1 * V_2 ,
int V_125 , int V_15 )
{
struct V_37 * V_38 = V_2 -> V_38 ;
if ( V_125 & ( V_126 | V_127 ) ) {
F_4 ( V_2 , V_126 |
V_127 ) ;
if ( ( ( ( V_125 & V_127 ) && V_38 -> V_128 ) ||
( ( V_125 & V_126 ) && ! V_38 -> V_128 ) ) &&
! F_57 ( & V_38 -> V_129 . V_59 ) )
F_58 ( V_2 -> V_38 , F_28 ( 100 ) ) ;
return true ;
}
return false ;
}
T_2 F_59 ( int V_130 , void * V_131 )
{
unsigned int V_125 , V_15 ;
struct V_1 * V_2 = V_131 ;
F_55 ( V_2 , & V_125 , & V_15 ) ;
F_56 ( V_2 , V_125 , V_15 ) ;
return V_132 ;
}
static bool F_60 ( struct V_1 * V_2 ,
int V_125 , int V_15 )
{
if ( V_125 & ( V_133 | V_120 ) ) {
F_4 ( V_2 ,
V_133 |
V_120 ) ;
F_54 ( V_2 , V_15 ) ;
return true ;
}
if ( V_125 & ( V_134 | V_135 ) ) {
F_4 ( V_2 , V_134 | V_135 ) ;
F_38 ( V_2 ) ;
return true ;
}
if ( V_125 & V_111 ) {
F_4 ( V_2 , V_111 ) ;
F_49 ( V_2 ) ;
return true ;
}
return false ;
}
T_2 F_61 ( int V_130 , void * V_131 )
{
unsigned int V_125 , V_15 ;
struct V_1 * V_2 = V_131 ;
F_55 ( V_2 , & V_125 , & V_15 ) ;
F_60 ( V_2 , V_125 , V_15 ) ;
return V_132 ;
}
T_2 F_62 ( int V_130 , void * V_131 )
{
struct V_1 * V_2 = V_131 ;
struct V_37 * V_38 = V_2 -> V_38 ;
struct V_136 * V_137 = V_2 -> V_137 ;
unsigned int V_125 , V_15 ;
if ( ! ( V_137 -> V_63 & V_138 ) )
return V_132 ;
V_15 = F_20 ( V_2 , V_139 ) ;
V_125 = V_15 & V_42 & ~ V_2 -> V_4 ;
F_14 ( V_2 , V_139 , V_15 & ~ V_42 ) ;
if ( V_38 -> V_140 & V_141 && V_125 & V_43 )
F_63 ( V_38 ) ;
return V_132 ;
}
T_2 F_64 ( int V_130 , void * V_131 )
{
struct V_1 * V_2 = V_131 ;
unsigned int V_125 , V_15 ;
F_9 ( L_13 ) ;
F_55 ( V_2 , & V_125 , & V_15 ) ;
if ( F_56 ( V_2 , V_125 , V_15 ) )
return V_132 ;
if ( F_60 ( V_2 , V_125 , V_15 ) )
return V_132 ;
F_62 ( V_130 , V_131 ) ;
return V_132 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_136 * V_137 = V_2 -> V_137 ;
F_9 ( L_14 ,
V_9 -> V_101 , V_9 -> V_88 ) ;
if ( V_2 -> V_38 -> V_142 . V_143 == V_144 ) {
int V_145 = V_137 -> V_63 & V_146 ;
if ( V_9 -> V_101 < 2 || ( V_9 -> V_101 < 4 && ! V_145 ) ) {
F_39 ( L_15 ,
F_66 ( V_2 -> V_38 ) , V_9 -> V_101 ) ;
return - V_86 ;
}
}
F_5 ( V_2 , V_9 ) ;
V_2 -> V_9 = V_9 ;
F_14 ( V_2 , V_147 , V_9 -> V_101 ) ;
F_14 ( V_2 , V_148 , V_9 -> V_88 ) ;
F_67 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_68 ( struct V_37 * V_38 , struct V_61 * V_62 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
unsigned long V_63 ;
int V_149 ;
F_25 ( & V_2 -> V_64 , V_63 ) ;
if ( V_2 -> V_62 ) {
F_9 ( L_16 ) ;
if ( F_69 ( V_2 -> V_62 ) ) {
F_29 ( & V_2 -> V_64 , V_63 ) ;
V_62 -> V_67 -> error = - V_150 ;
F_32 ( V_38 , V_62 ) ;
return;
}
}
V_2 -> V_65 = V_151 ;
F_70 () ;
V_2 -> V_62 = V_62 ;
F_29 ( & V_2 -> V_64 , V_63 ) ;
if ( V_62 -> V_9 ) {
V_149 = F_65 ( V_2 , V_62 -> V_9 ) ;
if ( V_149 )
goto V_152;
}
V_149 = F_36 ( V_2 , V_62 -> V_67 ) ;
if ( ! V_149 ) {
F_71 ( & V_2 -> V_60 ,
F_28 ( 2000 ) ) ;
return;
}
V_152:
V_2 -> V_70 = false ;
V_2 -> V_62 = NULL ;
V_62 -> V_67 -> error = V_149 ;
F_32 ( V_38 , V_62 ) ;
}
static void F_72 ( struct V_37 * V_38 , struct V_153 * V_142 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_136 * V_137 = V_2 -> V_137 ;
unsigned long V_63 ;
F_73 ( & V_2 -> V_154 ) ;
F_25 ( & V_2 -> V_64 , V_63 ) ;
if ( V_2 -> V_62 ) {
if ( F_69 ( V_2 -> V_62 ) ) {
F_46 ( & V_2 -> V_50 -> V_66 ,
L_17 ,
V_155 -> V_156 , F_74 ( V_155 ) ,
V_142 -> clock , V_142 -> V_157 ) ;
V_2 -> V_62 = F_75 ( - V_158 ) ;
} else {
F_46 ( & V_2 -> V_50 -> V_66 ,
L_18 ,
V_155 -> V_156 , F_74 ( V_155 ) ,
V_2 -> V_62 -> V_67 -> V_68 , V_2 -> V_65 , V_151 ) ;
}
F_29 ( & V_2 -> V_64 , V_63 ) ;
F_76 ( & V_2 -> V_154 ) ;
return;
}
V_2 -> V_62 = F_75 ( - V_159 ) ;
F_29 ( & V_2 -> V_64 , V_63 ) ;
if ( V_142 -> V_157 == V_160 && V_142 -> clock ) {
if ( ! V_137 -> V_161 ) {
F_77 ( & V_2 -> V_50 -> V_66 ) ;
V_137 -> V_161 = true ;
}
F_15 ( V_2 , V_142 -> clock ) ;
if ( V_2 -> V_162 )
V_2 -> V_162 ( V_2 -> V_50 , 1 ) ;
F_21 ( V_2 ) ;
} else if ( V_142 -> V_157 != V_163 ) {
if ( V_2 -> V_162 && V_142 -> V_157 == V_164 )
V_2 -> V_162 ( V_2 -> V_50 , 0 ) ;
if ( V_137 -> V_161 ) {
V_137 -> V_161 = false ;
F_78 ( & V_2 -> V_50 -> V_66 ) ;
}
F_16 ( V_2 ) ;
}
switch ( V_142 -> V_143 ) {
case V_165 :
F_14 ( V_2 , V_166 , 0x80e0 ) ;
break;
case V_144 :
F_14 ( V_2 , V_166 , 0x00e0 ) ;
break;
}
F_79 ( 140 ) ;
if ( F_80 ( V_2 -> V_62 ) == - V_158 )
F_46 ( & V_2 -> V_50 -> V_66 ,
L_19 ,
V_155 -> V_156 , F_74 ( V_155 ) ,
V_142 -> clock , V_142 -> V_157 ) ;
V_2 -> V_62 = NULL ;
F_76 ( & V_2 -> V_154 ) ;
}
static int F_81 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_136 * V_137 = V_2 -> V_137 ;
return ! ( ( V_137 -> V_63 & V_167 ) ||
( F_51 ( V_2 , V_7 ) & V_168 ) ) ;
}
static int F_82 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_136 * V_137 = V_2 -> V_137 ;
if ( ! V_137 -> V_169 )
return - V_170 ;
else
return V_137 -> V_169 ( V_2 -> V_50 ) ;
}
int T_3 F_83 ( struct V_1 * * V_2 ,
struct V_171 * V_50 ,
struct V_136 * V_137 )
{
struct V_1 * V_172 ;
struct V_37 * V_38 ;
struct V_52 * V_173 ;
int V_149 ;
T_1 V_174 = V_92 ;
V_173 = F_17 ( V_50 , V_54 , 0 ) ;
if ( ! V_173 )
return - V_86 ;
V_38 = F_84 ( sizeof( struct V_1 ) , & V_50 -> V_66 ) ;
if ( ! V_38 )
return - V_175 ;
V_137 -> V_66 = & V_50 -> V_66 ;
V_172 = F_13 ( V_38 ) ;
V_172 -> V_137 = V_137 ;
V_172 -> V_38 = V_38 ;
V_172 -> V_50 = V_50 ;
F_85 ( V_50 , V_38 ) ;
V_172 -> V_162 = V_137 -> V_162 ;
V_172 -> V_49 = V_137 -> V_49 ;
V_172 -> V_176 = F_18 ( V_173 ) >> 10 ;
V_172 -> V_177 = F_86 ( V_173 -> V_178 , F_18 ( V_173 ) ) ;
if ( ! V_172 -> V_177 ) {
V_149 = - V_175 ;
goto V_179;
}
V_38 -> V_180 = & V_181 ;
V_38 -> V_140 = V_182 | V_137 -> V_183 ;
V_38 -> V_184 = V_137 -> V_185 ;
V_38 -> V_48 = V_38 -> V_184 / 512 ;
V_38 -> V_186 = 32 ;
V_38 -> V_187 = 512 ;
V_38 -> V_188 = ( V_189 / V_38 -> V_187 ) *
V_38 -> V_186 ;
V_38 -> V_190 = V_38 -> V_187 * V_38 -> V_188 ;
V_38 -> V_191 = V_38 -> V_190 ;
if ( V_137 -> V_192 )
V_38 -> V_193 = V_137 -> V_192 ;
else
V_38 -> V_193 = V_194 | V_195 ;
V_137 -> V_161 = false ;
F_87 ( & V_50 -> V_66 ) ;
V_149 = F_88 ( & V_50 -> V_66 ) ;
if ( V_149 < 0 )
goto V_196;
if ( ! ( V_137 -> V_63 & V_197
|| V_38 -> V_140 & V_198
|| V_38 -> V_140 & V_199 ) )
F_89 ( & V_50 -> V_66 ) ;
F_16 ( V_172 ) ;
F_22 ( V_172 ) ;
V_172 -> V_4 = F_51 ( V_172 , V_6 ) ;
F_3 ( V_172 , V_200 ) ;
if ( V_137 -> V_63 & V_138 )
F_12 ( V_38 , 0 ) ;
F_90 ( & V_172 -> V_64 ) ;
F_91 ( & V_172 -> V_154 ) ;
F_92 ( & V_172 -> V_60 , F_23 ) ;
F_93 ( & V_172 -> V_71 , F_35 ) ;
F_94 ( V_172 , V_137 ) ;
F_95 ( V_38 ) ;
if ( ! V_172 -> V_99 )
V_174 |= V_113 ;
if ( ! V_172 -> V_98 )
V_174 |= V_114 ;
F_1 ( V_172 , V_174 ) ;
* V_2 = V_172 ;
return 0 ;
V_196:
F_96 ( & V_50 -> V_66 ) ;
F_97 ( V_172 -> V_177 ) ;
V_179:
F_98 ( V_38 ) ;
return V_149 ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_171 * V_50 = V_2 -> V_50 ;
if ( V_2 -> V_137 -> V_63 & V_197
|| V_2 -> V_38 -> V_140 & V_198
|| V_2 -> V_38 -> V_140 & V_199 )
F_77 ( & V_50 -> V_66 ) ;
F_100 ( V_2 -> V_38 ) ;
F_101 ( & V_2 -> V_71 ) ;
F_102 ( & V_2 -> V_60 ) ;
F_103 ( V_2 ) ;
F_104 ( & V_50 -> V_66 ) ;
F_96 ( & V_50 -> V_66 ) ;
F_97 ( V_2 -> V_177 ) ;
F_98 ( V_2 -> V_38 ) ;
}
int F_105 ( struct V_201 * V_66 )
{
struct V_37 * V_38 = F_106 ( V_66 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
int V_149 = F_107 ( V_38 ) ;
if ( ! V_149 )
F_3 ( V_2 , V_200 ) ;
V_2 -> V_202 = F_104 ( V_66 ) ;
return V_149 ;
}
int F_108 ( struct V_201 * V_66 )
{
struct V_37 * V_38 = F_106 ( V_66 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
V_2 -> V_137 -> V_161 = false ;
V_2 -> V_203 = true ;
if ( ! V_2 -> V_202 )
F_77 ( V_66 ) ;
if ( V_2 -> V_203 ) {
F_22 ( V_2 ) ;
F_109 ( V_2 , true ) ;
V_2 -> V_203 = false ;
}
return F_110 ( V_38 ) ;
}
int F_111 ( struct V_201 * V_66 )
{
return 0 ;
}
int F_112 ( struct V_201 * V_66 )
{
struct V_37 * V_38 = F_106 ( V_66 ) ;
struct V_1 * V_2 = F_13 ( V_38 ) ;
struct V_136 * V_137 = V_2 -> V_137 ;
F_22 ( V_2 ) ;
F_109 ( V_2 , true ) ;
if ( V_137 -> V_161 ) {
if ( ! V_38 -> V_128 )
F_72 ( V_38 , & V_38 -> V_142 ) ;
F_58 ( V_38 , F_28 ( 100 ) ) ;
}
V_2 -> V_203 = false ;
return 0 ;
}

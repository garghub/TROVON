static void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 -> V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
T_1 V_6 ;
F_4 ( V_6 ) ;
F_5 ( V_7 , V_6 ) ;
V_2 -> V_4 = F_6 ( V_6 , NULL , V_2 ) ;
if ( ! V_2 -> V_4 ) {
F_7 ( F_8 ( V_2 -> V_8 ) , L_1 ) ;
return - V_9 ;
}
V_2 -> V_5 = F_6 ( V_6 , NULL , V_2 ) ;
if ( ! V_2 -> V_5 ) {
F_7 ( F_8 ( V_2 -> V_8 ) , L_2 ) ;
goto V_10;
}
V_2 -> V_11 . V_12 = 1 ;
return 0 ;
V_10:
F_2 ( V_2 -> V_4 ) ;
return - V_9 ;
}
static inline struct V_13 * F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
return ( V_15 -> V_16 & V_17 ) ? V_2 -> V_5 : V_2 -> V_4 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_13 * V_18 = F_9 ( V_2 , V_15 ) ;
enum V_19 V_20 = F_11 ( V_15 ) ;
F_12 ( V_18 -> V_21 -> V_22 , V_15 -> V_23 , V_15 -> V_24 , V_20 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
struct V_25 * V_26 ,
struct V_13 * V_18 )
{
struct V_25 * V_11 = & V_2 -> V_11 ;
enum V_19 V_20 = F_11 ( V_15 ) ;
int V_24 ;
if ( ! V_26 && V_15 -> V_27 &&
V_15 -> V_27 != V_2 -> V_11 . V_12 ) {
F_14 ( F_8 ( V_2 -> V_8 ) ,
L_3 ,
V_28 ,
V_15 -> V_27 ,
V_2 -> V_11 . V_12 ) ;
V_15 -> V_27 = 0 ;
}
if ( V_26 || V_15 -> V_27 != V_2 -> V_11 . V_12 ) {
V_24 = F_15 ( V_18 -> V_21 -> V_22 ,
V_15 -> V_23 ,
V_15 -> V_24 ,
V_20 ) ;
} else {
V_24 = V_11 -> V_24 ;
V_11 -> V_24 = 0 ;
}
if ( V_24 <= 0 ) {
F_7 ( F_8 ( V_2 -> V_8 ) ,
L_4 ) ;
return - V_29 ;
}
if ( V_26 ) {
V_26 -> V_24 = V_24 ;
V_15 -> V_27 = ++ V_26 -> V_12 < 0 ? 1 : V_26 -> V_12 ;
} else
V_2 -> V_24 = V_24 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_30 ;
struct V_13 * V_18 ;
struct V_31 * V_32 ;
struct V_33 V_34 = {
. V_35 = V_36 ,
. V_37 = V_36 ,
. V_38 = V_39 ,
. V_40 = V_39 ,
} ;
if ( V_15 -> V_16 & V_41 ) {
V_34 . V_42 = V_43 ;
V_34 . V_44 = V_2 -> V_45 -> V_46 + V_47 ;
V_34 . V_48 = V_49 ;
V_18 = V_2 -> V_4 ;
} else {
V_34 . V_42 = V_50 ;
V_34 . V_51 = V_2 -> V_45 -> V_46 + V_52 ;
V_34 . V_48 = V_53 ;
V_18 = V_2 -> V_5 ;
}
V_30 = F_13 ( V_2 , V_15 , NULL , V_18 ) ;
if ( V_30 )
return V_30 ;
F_17 ( V_18 , & V_34 ) ;
V_32 = F_18 ( V_18 ,
V_15 -> V_23 ,
V_2 -> V_24 ,
V_34 . V_42 ,
V_54 | V_55 ) ;
if ( ! V_32 ) {
F_7 ( F_8 ( V_2 -> V_8 ) ,
L_5 ,
V_34 . V_42 == V_43 ? L_6 : L_7 ) ;
goto V_56;
}
F_19 ( V_32 ) ;
F_20 ( V_18 ) ;
return 0 ;
V_56:
F_10 ( V_2 , V_15 ) ;
return - V_57 ;
}
static void F_21 ( struct V_58 * V_8 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
struct V_14 * V_15 = V_60 -> V_15 ;
struct V_25 * V_11 = & V_2 -> V_11 ;
F_23 ( V_15 -> V_27 ) ;
if ( V_2 -> V_3 ) {
struct V_13 * V_18 = F_9 ( V_2 , V_15 ) ;
if ( F_13 ( V_2 , V_15 , V_11 , V_18 ) )
V_15 -> V_27 = 0 ;
}
}
static void F_24 ( struct V_58 * V_8 ,
struct V_59 * V_60 ,
int V_61 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
struct V_14 * V_15 = V_60 -> V_15 ;
if ( V_2 -> V_3 && V_15 -> V_27 ) {
F_10 ( V_2 , V_15 ) ;
V_15 -> V_27 = 0 ;
}
if ( V_61 ) {
struct V_13 * V_18 = F_9 ( V_2 , V_15 ) ;
F_25 ( V_18 ) ;
}
}
static void F_26 ( struct V_1 * V_2 ,
unsigned int V_62 , bool V_63 )
{
unsigned long V_16 ;
F_27 ( & V_2 -> V_64 , V_16 ) ;
if ( V_63 )
V_2 -> V_65 &= ~ V_62 ;
else
V_2 -> V_65 |= V_62 ;
F_28 ( & V_2 -> V_64 , V_16 ) ;
F_29 ( V_2 -> V_65 , V_2 -> V_66 + V_67 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
bool V_68 )
{
T_2 V_69 = V_70 ;
if ( V_68 )
V_69 |= V_71 ;
F_29 ( V_69 , V_2 -> V_66 + V_72 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_3 V_73 ;
unsigned int V_74 = 1000 ;
F_29 ( V_75 , V_2 -> V_66 + V_72 ) ;
do {
V_73 = F_32 ( V_2 -> V_66 + V_76 ) ;
} while ( V_73 & V_77 && -- V_74 );
}
static void F_33 ( struct V_1 * V_2 )
{
T_3 V_73 ;
unsigned int V_74 = 1000 ;
F_29 ( V_78 , V_2 -> V_66 + V_72 ) ;
F_34 ( 10 ) ;
do {
V_73 = F_32 ( V_2 -> V_66 + V_76 ) ;
} while ( V_73 & V_79 && -- V_74 );
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_59 * V_80 ;
V_80 = V_2 -> V_80 ;
V_2 -> V_80 = NULL ;
F_36 ( V_2 -> V_8 , V_80 ) ;
}
static unsigned int F_37 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
unsigned int V_74 = 0x800 ;
T_2 V_73 ;
do {
V_73 = F_38 ( V_2 -> V_66 + V_81 ) ;
} while ( ! ( V_73 & V_62 ) && -- V_74 );
if ( V_74 == 0 ) {
F_39 ( 0 , & V_2 -> V_82 ) ;
F_40 ( & V_2 -> V_83 , V_84 + 5 * V_85 ) ;
F_26 ( V_2 , V_62 , true ) ;
return true ;
}
return false ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_73 ;
V_73 = F_32 ( V_2 -> V_66 + V_76 ) ;
if ( V_73 & V_86 ) {
if ( V_73 & ( V_87 ) ) {
V_2 -> V_80 -> V_88 -> error = - V_89 ;
V_15 -> error = - V_89 ;
} else {
V_2 -> V_80 -> V_88 -> error = - V_90 ;
V_15 -> error = - V_90 ;
}
} else if ( V_73 & V_91 ) {
if ( V_73 & ( V_92 ) ) {
V_2 -> V_80 -> V_88 -> error = - V_89 ;
V_15 -> error = - V_89 ;
} else {
V_2 -> V_80 -> V_88 -> error = - V_90 ;
V_15 -> error = - V_90 ;
}
}
}
static bool F_42 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_93 * V_94 = & V_2 -> V_94 ;
void T_4 * V_95 = V_2 -> V_66 + V_47 ;
T_3 * V_96 ;
bool V_74 ;
T_5 V_97 , V_98 ;
while ( F_43 ( V_94 ) ) {
V_96 = V_94 -> V_99 ;
V_97 = V_94 -> V_100 / 4 ;
V_98 = V_97 / 8 ;
V_97 = V_97 & 0x7 ;
while ( V_98 ) {
V_74 = F_37 ( V_2 , V_101 ) ;
if ( F_44 ( V_74 ) )
goto V_102;
F_45 ( V_96 [ 0 ] , V_95 ) ;
F_45 ( V_96 [ 1 ] , V_95 ) ;
F_45 ( V_96 [ 2 ] , V_95 ) ;
F_45 ( V_96 [ 3 ] , V_95 ) ;
F_45 ( V_96 [ 4 ] , V_95 ) ;
F_45 ( V_96 [ 5 ] , V_95 ) ;
F_45 ( V_96 [ 6 ] , V_95 ) ;
F_45 ( V_96 [ 7 ] , V_95 ) ;
V_96 += 8 ;
-- V_98 ;
}
if ( F_44 ( V_97 ) ) {
V_74 = F_37 ( V_2 , V_101 ) ;
if ( F_44 ( V_74 ) )
goto V_102;
while ( V_97 ) {
F_45 ( * V_96 , V_95 ) ;
++ V_96 ;
-- V_97 ;
}
}
V_15 -> V_103 += V_94 -> V_100 ;
}
F_46 ( V_94 ) ;
return false ;
V_102:
V_94 -> V_104 = ( void * ) V_96 - V_94 -> V_99 ;
V_15 -> V_103 += V_94 -> V_104 ;
F_46 ( V_94 ) ;
return true ;
}
static bool F_47 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_93 * V_94 = & V_2 -> V_94 ;
void T_4 * V_95 = V_2 -> V_66 + V_52 ;
T_3 * V_96 ;
T_3 V_105 ;
T_2 V_73 ;
T_5 V_97 , V_98 ;
unsigned int V_74 ;
while ( F_43 ( V_94 ) ) {
V_96 = V_94 -> V_99 ;
V_97 = V_94 -> V_100 ;
V_98 = V_97 / 32 ;
V_97 = V_97 & 0x1f ;
while ( V_98 ) {
V_74 = F_37 ( V_2 , V_106 ) ;
if ( F_44 ( V_74 ) )
goto V_102;
V_96 [ 0 ] = F_32 ( V_95 ) ;
V_96 [ 1 ] = F_32 ( V_95 ) ;
V_96 [ 2 ] = F_32 ( V_95 ) ;
V_96 [ 3 ] = F_32 ( V_95 ) ;
V_96 [ 4 ] = F_32 ( V_95 ) ;
V_96 [ 5 ] = F_32 ( V_95 ) ;
V_96 [ 6 ] = F_32 ( V_95 ) ;
V_96 [ 7 ] = F_32 ( V_95 ) ;
V_96 += 8 ;
-- V_98 ;
}
if ( F_44 ( V_97 ) ) {
V_74 = F_37 ( V_2 , V_106 ) ;
if ( F_44 ( V_74 ) )
goto V_102;
while ( V_97 >= 4 ) {
* V_96 ++ = F_32 ( V_95 ) ;
V_97 -= 4 ;
}
if ( F_44 ( V_97 > 0 ) ) {
V_105 = F_32 ( V_95 ) ;
memcpy ( V_96 , & V_105 , V_97 ) ;
}
}
V_15 -> V_103 += V_94 -> V_100 ;
F_48 ( V_94 -> V_107 ) ;
}
F_46 ( V_94 ) ;
V_74 = 1000 ;
V_73 = F_32 ( V_2 -> V_66 + V_76 ) ;
while ( ! ( V_73 & V_108 ) && -- V_74 ) {
V_105 = F_32 ( V_95 ) ;
V_73 = F_32 ( V_2 -> V_66 + V_76 ) ;
}
return false ;
V_102:
V_94 -> V_104 = ( void * ) V_96 - V_94 -> V_99 ;
V_15 -> V_103 += V_94 -> V_104 ;
F_46 ( V_94 ) ;
return true ;
}
static void F_49 ( unsigned long V_15 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 ;
if ( ! F_50 ( 0 , & V_2 -> V_82 ) )
return;
F_26 ( V_2 , V_109 , false ) ;
V_2 -> V_80 -> V_88 -> error = - V_89 ;
F_35 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_110 * V_88 )
{
int V_97 ;
T_2 V_111 ;
void T_4 * V_95 = V_2 -> V_66 + V_112 ;
if ( V_88 -> V_16 & V_113 ) {
V_111 = F_38 ( V_95 ) ;
for ( V_97 = 0 ; V_97 < 4 ; ++ V_97 ) {
V_88 -> V_114 [ V_97 ] = V_111 << 24 ;
V_111 = F_38 ( V_95 ) ;
V_88 -> V_114 [ V_97 ] |= V_111 << 8 ;
V_111 = F_38 ( V_95 ) ;
V_88 -> V_114 [ V_97 ] |= V_111 >> 8 ;
}
} else {
V_88 -> V_114 [ 0 ] = F_38 ( V_95 ) << 24 ;
V_88 -> V_114 [ 0 ] |= F_38 ( V_95 ) << 8 ;
V_88 -> V_114 [ 0 ] |= F_38 ( V_95 ) & 0xff ;
}
}
static void F_52 ( struct V_1 * V_2 ,
struct V_110 * V_88 )
{
T_3 V_115 = V_2 -> V_115 ;
V_2 -> V_115 &= ~ V_116 ;
F_31 ( V_2 ) ;
V_2 -> V_88 = V_88 ;
if ( V_88 -> V_16 & V_117 )
V_115 |= V_118 ;
switch ( F_53 ( V_88 ) ) {
case V_119 :
case V_120 :
V_115 |= V_121 ;
break;
case V_122 :
V_115 |= V_123 ;
break;
case V_124 :
V_115 |= V_125 ;
break;
default:
break;
}
if ( V_88 -> V_15 ) {
V_115 |= V_126 ;
if ( V_88 -> V_15 -> V_16 & V_41 )
V_115 |= V_127 ;
if ( V_2 -> V_3 )
V_115 |= V_128 ;
F_29 ( V_88 -> V_15 -> V_129 , V_2 -> V_66 + V_130 ) ;
F_29 ( V_88 -> V_15 -> V_131 , V_2 -> V_66 + V_132 ) ;
}
F_54 ( V_88 -> V_133 , V_2 -> V_66 + V_134 ) ;
F_45 ( V_88 -> V_135 , V_2 -> V_66 + V_136 ) ;
F_45 ( V_115 , V_2 -> V_66 + V_137 ) ;
F_30 ( V_2 , 1 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_110 * V_88 = V_2 -> V_80 -> V_88 ;
struct V_14 * V_15 = V_88 -> V_15 ;
int V_42 ;
if ( V_15 -> V_16 & V_17 )
V_42 = V_138 ;
else
V_42 = V_139 ;
F_56 ( & V_2 -> V_94 , V_15 -> V_23 , V_15 -> V_24 , V_42 ) ;
}
static T_6 F_57 ( int V_62 , void * V_140 )
{
struct V_1 * V_2 = (struct V_1 * ) V_140 ;
struct V_110 * V_88 = V_2 -> V_80 -> V_88 ;
struct V_59 * V_80 = V_2 -> V_80 ;
struct V_14 * V_15 = V_88 -> V_15 ;
bool V_74 = false ;
if ( V_88 -> error )
V_2 -> V_141 = V_142 ;
switch ( V_2 -> V_141 ) {
case V_143 :
if ( V_88 -> V_16 & V_144 )
F_51 ( V_2 , V_88 ) ;
if ( ! V_15 )
break;
F_55 ( V_2 ) ;
case V_145 :
if ( V_2 -> V_3 ) {
V_74 = F_16 ( V_2 , V_15 ) ;
V_15 -> V_103 = V_15 -> V_131 * V_15 -> V_129 ;
} else if ( V_15 -> V_16 & V_17 )
V_74 = F_47 ( V_2 , V_15 ) ;
else
V_74 = F_42 ( V_2 , V_15 ) ;
if ( F_44 ( V_74 ) ) {
V_2 -> V_141 = V_145 ;
break;
}
F_41 ( V_2 , V_15 ) ;
V_74 = F_37 ( V_2 , V_146 ) ;
if ( F_44 ( V_74 ) ) {
V_2 -> V_141 = V_147 ;
break;
}
F_29 ( V_146 , V_2 -> V_66 + V_81 ) ;
case V_147 :
if ( ! V_80 -> V_148 )
break;
F_52 ( V_2 , V_80 -> V_148 ) ;
if ( F_53 ( V_80 -> V_148 ) & V_117 ) {
V_74 = F_37 ( V_2 ,
V_149 ) ;
if ( V_74 ) {
V_2 -> V_141 = V_142 ;
break;
}
}
case V_142 :
break;
}
if ( ! V_74 )
F_35 ( V_2 ) ;
return V_150 ;
}
static T_6 F_58 ( int V_62 , void * V_140 )
{
struct V_1 * V_2 = V_140 ;
struct V_110 * V_88 = V_2 -> V_88 ;
T_2 V_151 , V_73 , V_111 ;
V_151 = F_38 ( V_2 -> V_66 + V_81 ) ;
V_111 = V_151 ;
V_151 &= ~ V_2 -> V_65 ;
V_111 &= ~ ( V_101 | V_106 |
V_149 | V_146 ) ;
if ( V_111 != V_151 )
F_29 ( V_111 & ~ V_151 , V_2 -> V_66 + V_81 ) ;
if ( V_151 & V_152 ) {
F_29 ( V_152 , V_2 -> V_66 + V_81 ) ;
F_59 ( V_2 -> V_8 ) ;
V_151 &= ~ V_152 ;
}
if ( V_2 -> V_80 && V_88 && V_151 ) {
if ( F_50 ( 0 , & V_2 -> V_82 ) ) {
F_60 ( & V_2 -> V_83 ) ;
V_73 = F_32 ( V_2 -> V_66 + V_76 ) ;
if ( V_73 & V_153 ) {
V_88 -> error = - V_89 ;
} else if ( V_73 & V_154 ) {
V_88 -> error = - V_90 ;
} else if ( V_73 & ( V_155 |
V_156 ) ) {
if ( V_88 -> V_15 )
V_88 -> V_15 -> error = - V_90 ;
V_88 -> error = - V_90 ;
}
F_26 ( V_2 , V_151 , false ) ;
F_29 ( V_151 , V_2 -> V_66 + V_81 ) ;
return V_157 ;
}
}
return V_150 ;
}
static int F_61 ( struct V_1 * V_2 , int V_158 )
{
int div = 0 ;
int V_159 ;
F_31 ( V_2 ) ;
F_62 ( V_2 -> V_160 , V_161 ) ;
V_159 = F_63 ( V_2 -> V_160 ) ;
while ( V_159 > V_158 && div < 7 ) {
++ div ;
V_159 >>= 1 ;
}
F_29 ( div , V_2 -> V_66 + V_162 ) ;
return V_159 ;
}
static void F_64 ( struct V_58 * V_8 , struct V_59 * V_80 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
V_2 -> V_80 = V_80 ;
F_29 ( 0xffff , V_2 -> V_66 + V_81 ) ;
F_29 ( V_109 , V_2 -> V_66 + V_81 ) ;
F_26 ( V_2 , V_109 , true ) ;
V_2 -> V_141 = V_143 ;
F_39 ( 0 , & V_2 -> V_82 ) ;
F_40 ( & V_2 -> V_83 , V_84 + 5 * V_85 ) ;
F_52 ( V_2 , V_80 -> V_88 ) ;
}
static void F_65 ( struct V_58 * V_8 , struct V_163 * V_164 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
if ( V_164 -> clock )
F_61 ( V_2 , V_164 -> clock ) ;
switch ( V_164 -> V_165 ) {
case V_166 :
F_33 ( V_2 ) ;
if ( F_66 ( V_2 -> V_167 -> V_168 ) )
F_67 ( V_2 -> V_167 -> V_168 ,
! V_2 -> V_167 -> V_169 ) ;
V_2 -> V_115 |= V_116 ;
F_68 ( V_2 -> V_160 ) ;
break;
case V_170 :
break;
default:
if ( F_66 ( V_2 -> V_167 -> V_168 ) )
F_67 ( V_2 -> V_167 -> V_168 ,
V_2 -> V_167 -> V_169 ) ;
F_69 ( V_2 -> V_160 ) ;
break;
}
switch ( V_164 -> V_171 ) {
case V_172 :
V_2 -> V_115 &= ~ V_173 ;
break;
case V_174 :
V_2 -> V_115 |= V_173 ;
break;
default:
break;
}
}
static void F_70 ( struct V_58 * V_8 , int V_175 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
F_26 ( V_2 , V_152 , V_175 ) ;
}
static int F_71 ( struct V_21 * V_22 , int V_176 ,
const char * V_177 , bool V_178 , int V_179 )
{
int V_30 ;
if ( ! F_66 ( V_176 ) )
return 0 ;
V_30 = F_72 ( V_176 , V_177 ) ;
if ( V_30 ) {
F_7 ( V_22 , L_8 , V_177 , V_30 ) ;
return V_30 ;
}
if ( V_178 )
F_73 ( V_176 , V_179 ) ;
else
F_74 ( V_176 ) ;
return 0 ;
}
static int F_75 ( struct V_58 * V_8 ,
struct V_180 * V_181 )
{
struct V_182 * V_167 = V_181 -> V_22 . V_183 ;
int V_30 = 0 ;
if ( ! V_167 )
return 0 ;
if ( ! V_167 -> V_184 )
V_8 -> V_185 |= V_186 ;
if ( ! V_167 -> V_187 )
V_8 -> V_185 |= V_188 ;
if ( F_66 ( V_167 -> V_189 ) ) {
V_30 = F_76 ( V_8 , V_167 -> V_189 , 0 ) ;
if ( V_30 )
return V_30 ;
}
if ( F_66 ( V_167 -> V_190 ) ) {
V_30 = F_77 ( V_8 , V_167 -> V_190 ) ;
if ( V_30 )
return V_30 ;
}
return F_71 ( & V_181 -> V_22 , V_167 -> V_168 ,
L_9 , true , V_167 -> V_169 ) ;
}
static void F_78 ( struct V_180 * V_181 )
{
struct V_182 * V_167 = V_181 -> V_22 . V_183 ;
if ( ! V_167 )
return;
if ( F_66 ( V_167 -> V_168 ) )
F_79 ( V_167 -> V_168 ) ;
}
static int F_80 ( struct V_180 * V_181 )
{
int V_30 ;
struct V_58 * V_8 ;
struct V_1 * V_2 ;
struct V_182 * V_167 ;
V_167 = V_181 -> V_22 . V_183 ;
V_8 = F_81 ( sizeof( struct V_1 ) , & V_181 -> V_22 ) ;
if ( ! V_8 ) {
F_7 ( & V_181 -> V_22 , L_10 ) ;
return - V_57 ;
}
V_2 = F_22 ( V_8 ) ;
V_2 -> V_167 = V_167 ;
V_2 -> V_62 = F_82 ( V_181 , 0 ) ;
if ( V_2 -> V_62 < 0 ) {
V_30 = V_2 -> V_62 ;
F_7 ( & V_181 -> V_22 , L_11 , V_30 ) ;
goto V_191;
}
V_2 -> V_160 = F_83 ( & V_181 -> V_22 , L_12 ) ;
if ( F_84 ( V_2 -> V_160 ) ) {
V_30 = F_85 ( V_2 -> V_160 ) ;
F_7 ( & V_181 -> V_22 , L_13 ) ;
goto V_191;
}
V_2 -> V_45 = F_86 ( V_181 , V_192 , 0 ) ;
V_2 -> V_66 = F_87 ( & V_181 -> V_22 , V_2 -> V_45 ) ;
if ( F_84 ( V_2 -> V_66 ) ) {
V_30 = F_85 ( V_2 -> V_66 ) ;
F_7 ( & V_181 -> V_22 , L_14 ) ;
goto V_191;
}
V_30 = F_75 ( V_8 , V_181 ) ;
if ( V_30 )
goto V_193;
V_8 -> V_194 = & V_195 ;
V_8 -> V_196 = V_161 / 128 ;
V_8 -> V_197 = V_161 ;
V_8 -> V_198 = V_199 | V_200 ;
V_8 -> V_201 = ( V_167 && V_167 -> V_202 ) ? 0 : V_203 ;
V_8 -> V_201 |= V_204 ;
V_8 -> V_205 = ( 1 << 10 ) - 1 ;
V_8 -> V_206 = ( 1 << 15 ) - 1 ;
V_8 -> V_207 = V_8 -> V_205 * V_8 -> V_206 ;
V_8 -> V_208 = 128 ;
V_8 -> V_209 = V_8 -> V_207 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_181 = V_181 ;
F_88 ( & V_2 -> V_64 ) ;
V_2 -> V_65 = 0xffff ;
V_30 = F_89 ( V_2 -> V_62 , F_58 , F_57 , 0 ,
F_90 ( & V_181 -> V_22 ) , V_2 ) ;
if ( V_30 ) {
F_7 ( & V_181 -> V_22 , L_15 , V_30 ) ;
goto V_210;
}
F_33 ( V_2 ) ;
F_31 ( V_2 ) ;
F_91 ( & V_2 -> V_83 , F_49 ,
( unsigned long ) V_2 ) ;
V_2 -> V_3 = true ;
if ( V_2 -> V_3 && F_3 ( V_2 ) != 0 )
V_2 -> V_3 = false ;
F_92 ( V_181 , V_2 ) ;
V_30 = F_93 ( V_8 ) ;
if ( V_30 ) {
F_7 ( & V_181 -> V_22 , L_16 , V_30 ) ;
goto V_211;
}
F_94 ( & V_181 -> V_22 , L_17 ) ;
F_94 ( & V_181 -> V_22 , L_18 ,
V_2 -> V_3 ? L_19 : L_20 ,
( V_8 -> V_201 & V_203 ) ? 4 : 1 ) ;
return 0 ;
V_211:
F_95 ( V_2 -> V_62 , V_2 ) ;
V_210:
F_78 ( V_181 ) ;
V_193:
if ( V_2 -> V_3 )
F_1 ( V_2 ) ;
V_191:
F_96 ( V_8 ) ;
return V_30 ;
}
static int F_97 ( struct V_180 * V_181 )
{
struct V_1 * V_2 = F_98 ( V_181 ) ;
F_99 ( & V_2 -> V_83 ) ;
F_26 ( V_2 , 0xff , false ) ;
F_33 ( V_2 ) ;
F_100 ( V_2 -> V_8 ) ;
F_95 ( V_2 -> V_62 , V_2 ) ;
F_78 ( V_181 ) ;
if ( V_2 -> V_3 )
F_1 ( V_2 ) ;
F_96 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_101 ( struct V_21 * V_22 )
{
return F_102 ( V_22 ) ;
}
static int F_103 ( struct V_21 * V_22 )
{
return F_104 ( V_22 ) ;
}

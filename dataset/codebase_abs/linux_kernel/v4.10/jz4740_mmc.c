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
static inline int F_9 ( struct V_13 * V_14 )
{
return ( V_14 -> V_15 & V_16 ) ? V_17 : V_18 ;
}
static inline struct V_19 * F_10 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
return ( V_14 -> V_15 & V_16 ) ? V_2 -> V_5 : V_2 -> V_4 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_19 * V_20 = F_10 ( V_2 , V_14 ) ;
enum V_21 V_22 = F_9 ( V_14 ) ;
F_12 ( V_20 -> V_23 -> V_24 , V_14 -> V_25 , V_14 -> V_26 , V_22 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_27 * V_28 ,
struct V_19 * V_20 )
{
struct V_27 * V_11 = & V_2 -> V_11 ;
enum V_21 V_22 = F_9 ( V_14 ) ;
int V_26 ;
if ( ! V_28 && V_14 -> V_29 &&
V_14 -> V_29 != V_2 -> V_11 . V_12 ) {
F_14 ( F_8 ( V_2 -> V_8 ) ,
L_3 ,
V_30 ,
V_14 -> V_29 ,
V_2 -> V_11 . V_12 ) ;
V_14 -> V_29 = 0 ;
}
if ( V_28 || V_14 -> V_29 != V_2 -> V_11 . V_12 ) {
V_26 = F_15 ( V_20 -> V_23 -> V_24 ,
V_14 -> V_25 ,
V_14 -> V_26 ,
V_22 ) ;
} else {
V_26 = V_11 -> V_26 ;
V_11 -> V_26 = 0 ;
}
if ( V_26 <= 0 ) {
F_7 ( F_8 ( V_2 -> V_8 ) ,
L_4 ) ;
return - V_31 ;
}
if ( V_28 ) {
V_28 -> V_26 = V_26 ;
V_14 -> V_29 = ++ V_28 -> V_12 < 0 ? 1 : V_28 -> V_12 ;
} else
V_2 -> V_26 = V_26 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_32 ;
struct V_19 * V_20 ;
struct V_33 * V_34 ;
struct V_35 V_36 = {
. V_37 = V_38 ,
. V_39 = V_38 ,
. V_40 = V_41 ,
. V_42 = V_41 ,
} ;
if ( V_14 -> V_15 & V_43 ) {
V_36 . V_44 = V_45 ;
V_36 . V_46 = V_2 -> V_47 -> V_48 + V_49 ;
V_36 . V_50 = V_51 ;
V_20 = V_2 -> V_4 ;
} else {
V_36 . V_44 = V_52 ;
V_36 . V_53 = V_2 -> V_47 -> V_48 + V_54 ;
V_36 . V_50 = V_55 ;
V_20 = V_2 -> V_5 ;
}
V_32 = F_13 ( V_2 , V_14 , NULL , V_20 ) ;
if ( V_32 )
return V_32 ;
F_17 ( V_20 , & V_36 ) ;
V_34 = F_18 ( V_20 ,
V_14 -> V_25 ,
V_2 -> V_26 ,
V_36 . V_44 ,
V_56 | V_57 ) ;
if ( ! V_34 ) {
F_7 ( F_8 ( V_2 -> V_8 ) ,
L_5 ,
V_36 . V_44 == V_45 ? L_6 : L_7 ) ;
goto V_58;
}
F_19 ( V_34 ) ;
F_20 ( V_20 ) ;
return 0 ;
V_58:
F_11 ( V_2 , V_14 ) ;
return - V_59 ;
}
static void F_21 ( struct V_60 * V_8 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
struct V_27 * V_11 = & V_2 -> V_11 ;
F_23 ( V_14 -> V_29 ) ;
if ( V_2 -> V_3 ) {
struct V_19 * V_20 = F_10 ( V_2 , V_14 ) ;
if ( F_13 ( V_2 , V_14 , V_11 , V_20 ) )
V_14 -> V_29 = 0 ;
}
}
static void F_24 ( struct V_60 * V_8 ,
struct V_61 * V_62 ,
int V_63 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
if ( V_2 -> V_3 && V_14 -> V_29 ) {
F_11 ( V_2 , V_14 ) ;
V_14 -> V_29 = 0 ;
}
if ( V_63 ) {
struct V_19 * V_20 = F_10 ( V_2 , V_14 ) ;
F_25 ( V_20 ) ;
}
}
static void F_26 ( struct V_1 * V_2 ,
unsigned int V_64 , bool V_65 )
{
unsigned long V_15 ;
F_27 ( & V_2 -> V_66 , V_15 ) ;
if ( V_65 )
V_2 -> V_67 &= ~ V_64 ;
else
V_2 -> V_67 |= V_64 ;
F_28 ( & V_2 -> V_66 , V_15 ) ;
F_29 ( V_2 -> V_67 , V_2 -> V_68 + V_69 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
bool V_70 )
{
T_2 V_71 = V_72 ;
if ( V_70 )
V_71 |= V_73 ;
F_29 ( V_71 , V_2 -> V_68 + V_74 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_3 V_75 ;
unsigned int V_76 = 1000 ;
F_29 ( V_77 , V_2 -> V_68 + V_74 ) ;
do {
V_75 = F_32 ( V_2 -> V_68 + V_78 ) ;
} while ( V_75 & V_79 && -- V_76 );
}
static void F_33 ( struct V_1 * V_2 )
{
T_3 V_75 ;
unsigned int V_76 = 1000 ;
F_29 ( V_80 , V_2 -> V_68 + V_74 ) ;
F_34 ( 10 ) ;
do {
V_75 = F_32 ( V_2 -> V_68 + V_78 ) ;
} while ( V_75 & V_81 && -- V_76 );
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_61 * V_82 ;
V_82 = V_2 -> V_82 ;
V_2 -> V_82 = NULL ;
F_36 ( V_2 -> V_8 , V_82 ) ;
}
static unsigned int F_37 ( struct V_1 * V_2 ,
unsigned int V_64 )
{
unsigned int V_76 = 0x800 ;
T_2 V_75 ;
do {
V_75 = F_38 ( V_2 -> V_68 + V_83 ) ;
} while ( ! ( V_75 & V_64 ) && -- V_76 );
if ( V_76 == 0 ) {
F_39 ( 0 , & V_2 -> V_84 ) ;
F_40 ( & V_2 -> V_85 , V_86 + 5 * V_87 ) ;
F_26 ( V_2 , V_64 , true ) ;
return true ;
}
return false ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_75 ;
V_75 = F_32 ( V_2 -> V_68 + V_78 ) ;
if ( V_75 & V_88 ) {
if ( V_75 & ( V_89 ) ) {
V_2 -> V_82 -> V_90 -> error = - V_91 ;
V_14 -> error = - V_91 ;
} else {
V_2 -> V_82 -> V_90 -> error = - V_92 ;
V_14 -> error = - V_92 ;
}
} else if ( V_75 & V_93 ) {
if ( V_75 & ( V_94 ) ) {
V_2 -> V_82 -> V_90 -> error = - V_91 ;
V_14 -> error = - V_91 ;
} else {
V_2 -> V_82 -> V_90 -> error = - V_92 ;
V_14 -> error = - V_92 ;
}
}
}
static bool F_42 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_95 * V_96 = & V_2 -> V_96 ;
void T_4 * V_97 = V_2 -> V_68 + V_49 ;
T_3 * V_98 ;
bool V_76 ;
T_5 V_99 , V_100 ;
while ( F_43 ( V_96 ) ) {
V_98 = V_96 -> V_101 ;
V_99 = V_96 -> V_102 / 4 ;
V_100 = V_99 / 8 ;
V_99 = V_99 & 0x7 ;
while ( V_100 ) {
V_76 = F_37 ( V_2 , V_103 ) ;
if ( F_44 ( V_76 ) )
goto V_104;
F_45 ( V_98 [ 0 ] , V_97 ) ;
F_45 ( V_98 [ 1 ] , V_97 ) ;
F_45 ( V_98 [ 2 ] , V_97 ) ;
F_45 ( V_98 [ 3 ] , V_97 ) ;
F_45 ( V_98 [ 4 ] , V_97 ) ;
F_45 ( V_98 [ 5 ] , V_97 ) ;
F_45 ( V_98 [ 6 ] , V_97 ) ;
F_45 ( V_98 [ 7 ] , V_97 ) ;
V_98 += 8 ;
-- V_100 ;
}
if ( F_44 ( V_99 ) ) {
V_76 = F_37 ( V_2 , V_103 ) ;
if ( F_44 ( V_76 ) )
goto V_104;
while ( V_99 ) {
F_45 ( * V_98 , V_97 ) ;
++ V_98 ;
-- V_99 ;
}
}
V_14 -> V_105 += V_96 -> V_102 ;
}
F_46 ( V_96 ) ;
return false ;
V_104:
V_96 -> V_106 = ( void * ) V_98 - V_96 -> V_101 ;
V_14 -> V_105 += V_96 -> V_106 ;
F_46 ( V_96 ) ;
return true ;
}
static bool F_47 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_95 * V_96 = & V_2 -> V_96 ;
void T_4 * V_97 = V_2 -> V_68 + V_54 ;
T_3 * V_98 ;
T_3 V_107 ;
T_2 V_75 ;
T_5 V_99 , V_100 ;
unsigned int V_76 ;
while ( F_43 ( V_96 ) ) {
V_98 = V_96 -> V_101 ;
V_99 = V_96 -> V_102 ;
V_100 = V_99 / 32 ;
V_99 = V_99 & 0x1f ;
while ( V_100 ) {
V_76 = F_37 ( V_2 , V_108 ) ;
if ( F_44 ( V_76 ) )
goto V_104;
V_98 [ 0 ] = F_32 ( V_97 ) ;
V_98 [ 1 ] = F_32 ( V_97 ) ;
V_98 [ 2 ] = F_32 ( V_97 ) ;
V_98 [ 3 ] = F_32 ( V_97 ) ;
V_98 [ 4 ] = F_32 ( V_97 ) ;
V_98 [ 5 ] = F_32 ( V_97 ) ;
V_98 [ 6 ] = F_32 ( V_97 ) ;
V_98 [ 7 ] = F_32 ( V_97 ) ;
V_98 += 8 ;
-- V_100 ;
}
if ( F_44 ( V_99 ) ) {
V_76 = F_37 ( V_2 , V_108 ) ;
if ( F_44 ( V_76 ) )
goto V_104;
while ( V_99 >= 4 ) {
* V_98 ++ = F_32 ( V_97 ) ;
V_99 -= 4 ;
}
if ( F_44 ( V_99 > 0 ) ) {
V_107 = F_32 ( V_97 ) ;
memcpy ( V_98 , & V_107 , V_99 ) ;
}
}
V_14 -> V_105 += V_96 -> V_102 ;
F_48 ( V_96 -> V_109 ) ;
}
F_46 ( V_96 ) ;
V_76 = 1000 ;
V_75 = F_32 ( V_2 -> V_68 + V_78 ) ;
while ( ! ( V_75 & V_110 ) && -- V_76 ) {
V_107 = F_32 ( V_97 ) ;
V_75 = F_32 ( V_2 -> V_68 + V_78 ) ;
}
return false ;
V_104:
V_96 -> V_106 = ( void * ) V_98 - V_96 -> V_101 ;
V_14 -> V_105 += V_96 -> V_106 ;
F_46 ( V_96 ) ;
return true ;
}
static void F_49 ( unsigned long V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
if ( ! F_50 ( 0 , & V_2 -> V_84 ) )
return;
F_26 ( V_2 , V_111 , false ) ;
V_2 -> V_82 -> V_90 -> error = - V_91 ;
F_35 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_112 * V_90 )
{
int V_99 ;
T_2 V_113 ;
void T_4 * V_97 = V_2 -> V_68 + V_114 ;
if ( V_90 -> V_15 & V_115 ) {
V_113 = F_38 ( V_97 ) ;
for ( V_99 = 0 ; V_99 < 4 ; ++ V_99 ) {
V_90 -> V_116 [ V_99 ] = V_113 << 24 ;
V_113 = F_38 ( V_97 ) ;
V_90 -> V_116 [ V_99 ] |= V_113 << 8 ;
V_113 = F_38 ( V_97 ) ;
V_90 -> V_116 [ V_99 ] |= V_113 >> 8 ;
}
} else {
V_90 -> V_116 [ 0 ] = F_38 ( V_97 ) << 24 ;
V_90 -> V_116 [ 0 ] |= F_38 ( V_97 ) << 8 ;
V_90 -> V_116 [ 0 ] |= F_38 ( V_97 ) & 0xff ;
}
}
static void F_52 ( struct V_1 * V_2 ,
struct V_112 * V_90 )
{
T_3 V_117 = V_2 -> V_117 ;
V_2 -> V_117 &= ~ V_118 ;
F_31 ( V_2 ) ;
V_2 -> V_90 = V_90 ;
if ( V_90 -> V_15 & V_119 )
V_117 |= V_120 ;
switch ( F_53 ( V_90 ) ) {
case V_121 :
case V_122 :
V_117 |= V_123 ;
break;
case V_124 :
V_117 |= V_125 ;
break;
case V_126 :
V_117 |= V_127 ;
break;
default:
break;
}
if ( V_90 -> V_14 ) {
V_117 |= V_128 ;
if ( V_90 -> V_14 -> V_15 & V_43 )
V_117 |= V_129 ;
if ( V_2 -> V_3 )
V_117 |= V_130 ;
F_29 ( V_90 -> V_14 -> V_131 , V_2 -> V_68 + V_132 ) ;
F_29 ( V_90 -> V_14 -> V_133 , V_2 -> V_68 + V_134 ) ;
}
F_54 ( V_90 -> V_135 , V_2 -> V_68 + V_136 ) ;
F_45 ( V_90 -> V_137 , V_2 -> V_68 + V_138 ) ;
F_45 ( V_117 , V_2 -> V_68 + V_139 ) ;
F_30 ( V_2 , 1 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_112 * V_90 = V_2 -> V_82 -> V_90 ;
struct V_13 * V_14 = V_90 -> V_14 ;
int V_44 ;
if ( V_14 -> V_15 & V_16 )
V_44 = V_140 ;
else
V_44 = V_141 ;
F_56 ( & V_2 -> V_96 , V_14 -> V_25 , V_14 -> V_26 , V_44 ) ;
}
static T_6 F_57 ( int V_64 , void * V_142 )
{
struct V_1 * V_2 = (struct V_1 * ) V_142 ;
struct V_112 * V_90 = V_2 -> V_82 -> V_90 ;
struct V_61 * V_82 = V_2 -> V_82 ;
struct V_13 * V_14 = V_90 -> V_14 ;
bool V_76 = false ;
if ( V_90 -> error )
V_2 -> V_143 = V_144 ;
switch ( V_2 -> V_143 ) {
case V_145 :
if ( V_90 -> V_15 & V_146 )
F_51 ( V_2 , V_90 ) ;
if ( ! V_14 )
break;
F_55 ( V_2 ) ;
case V_147 :
if ( V_2 -> V_3 ) {
V_76 = F_16 ( V_2 , V_14 ) ;
V_14 -> V_105 = V_14 -> V_133 * V_14 -> V_131 ;
} else if ( V_14 -> V_15 & V_16 )
V_76 = F_47 ( V_2 , V_14 ) ;
else
V_76 = F_42 ( V_2 , V_14 ) ;
if ( F_44 ( V_76 ) ) {
V_2 -> V_143 = V_147 ;
break;
}
F_41 ( V_2 , V_14 ) ;
V_76 = F_37 ( V_2 , V_148 ) ;
if ( F_44 ( V_76 ) ) {
V_2 -> V_143 = V_149 ;
break;
}
F_29 ( V_148 , V_2 -> V_68 + V_83 ) ;
case V_149 :
if ( ! V_82 -> V_150 )
break;
F_52 ( V_2 , V_82 -> V_150 ) ;
if ( F_53 ( V_82 -> V_150 ) & V_119 ) {
V_76 = F_37 ( V_2 ,
V_151 ) ;
if ( V_76 ) {
V_2 -> V_143 = V_144 ;
break;
}
}
case V_144 :
break;
}
if ( ! V_76 )
F_35 ( V_2 ) ;
return V_152 ;
}
static T_6 F_58 ( int V_64 , void * V_142 )
{
struct V_1 * V_2 = V_142 ;
struct V_112 * V_90 = V_2 -> V_90 ;
T_2 V_153 , V_75 , V_113 ;
V_153 = F_38 ( V_2 -> V_68 + V_83 ) ;
V_113 = V_153 ;
V_153 &= ~ V_2 -> V_67 ;
V_113 &= ~ ( V_103 | V_108 |
V_151 | V_148 ) ;
if ( V_113 != V_153 )
F_29 ( V_113 & ~ V_153 , V_2 -> V_68 + V_83 ) ;
if ( V_153 & V_154 ) {
F_29 ( V_154 , V_2 -> V_68 + V_83 ) ;
F_59 ( V_2 -> V_8 ) ;
V_153 &= ~ V_154 ;
}
if ( V_2 -> V_82 && V_90 && V_153 ) {
if ( F_50 ( 0 , & V_2 -> V_84 ) ) {
F_60 ( & V_2 -> V_85 ) ;
V_75 = F_32 ( V_2 -> V_68 + V_78 ) ;
if ( V_75 & V_155 ) {
V_90 -> error = - V_91 ;
} else if ( V_75 & V_156 ) {
V_90 -> error = - V_92 ;
} else if ( V_75 & ( V_157 |
V_158 ) ) {
if ( V_90 -> V_14 )
V_90 -> V_14 -> error = - V_92 ;
V_90 -> error = - V_92 ;
}
F_26 ( V_2 , V_153 , false ) ;
F_29 ( V_153 , V_2 -> V_68 + V_83 ) ;
return V_159 ;
}
}
return V_152 ;
}
static int F_61 ( struct V_1 * V_2 , int V_160 )
{
int div = 0 ;
int V_161 ;
F_31 ( V_2 ) ;
F_62 ( V_2 -> V_162 , V_163 ) ;
V_161 = F_63 ( V_2 -> V_162 ) ;
while ( V_161 > V_160 && div < 7 ) {
++ div ;
V_161 >>= 1 ;
}
F_29 ( div , V_2 -> V_68 + V_164 ) ;
return V_161 ;
}
static void F_64 ( struct V_60 * V_8 , struct V_61 * V_82 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
V_2 -> V_82 = V_82 ;
F_29 ( 0xffff , V_2 -> V_68 + V_83 ) ;
F_29 ( V_111 , V_2 -> V_68 + V_83 ) ;
F_26 ( V_2 , V_111 , true ) ;
V_2 -> V_143 = V_145 ;
F_39 ( 0 , & V_2 -> V_84 ) ;
F_40 ( & V_2 -> V_85 , V_86 + 5 * V_87 ) ;
F_52 ( V_2 , V_82 -> V_90 ) ;
}
static void F_65 ( struct V_60 * V_8 , struct V_165 * V_166 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
if ( V_166 -> clock )
F_61 ( V_2 , V_166 -> clock ) ;
switch ( V_166 -> V_167 ) {
case V_168 :
F_33 ( V_2 ) ;
if ( F_66 ( V_2 -> V_169 -> V_170 ) )
F_67 ( V_2 -> V_169 -> V_170 ,
! V_2 -> V_169 -> V_171 ) ;
V_2 -> V_117 |= V_118 ;
F_68 ( V_2 -> V_162 ) ;
break;
case V_172 :
break;
default:
if ( F_66 ( V_2 -> V_169 -> V_170 ) )
F_67 ( V_2 -> V_169 -> V_170 ,
V_2 -> V_169 -> V_171 ) ;
F_69 ( V_2 -> V_162 ) ;
break;
}
switch ( V_166 -> V_173 ) {
case V_174 :
V_2 -> V_117 &= ~ V_175 ;
break;
case V_176 :
V_2 -> V_117 |= V_175 ;
break;
default:
break;
}
}
static void F_70 ( struct V_60 * V_8 , int V_177 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
F_26 ( V_2 , V_154 , V_177 ) ;
}
static int F_71 ( struct V_23 * V_24 , int V_178 ,
const char * V_179 , bool V_180 , int V_181 )
{
int V_32 ;
if ( ! F_66 ( V_178 ) )
return 0 ;
V_32 = F_72 ( V_178 , V_179 ) ;
if ( V_32 ) {
F_7 ( V_24 , L_8 , V_179 , V_32 ) ;
return V_32 ;
}
if ( V_180 )
F_73 ( V_178 , V_181 ) ;
else
F_74 ( V_178 ) ;
return 0 ;
}
static int F_75 ( struct V_60 * V_8 ,
struct V_182 * V_183 )
{
struct V_184 * V_169 = V_183 -> V_24 . V_185 ;
int V_32 = 0 ;
if ( ! V_169 )
return 0 ;
if ( ! V_169 -> V_186 )
V_8 -> V_187 |= V_188 ;
if ( ! V_169 -> V_189 )
V_8 -> V_187 |= V_190 ;
if ( F_66 ( V_169 -> V_191 ) ) {
V_32 = F_76 ( V_8 , V_169 -> V_191 , 0 ) ;
if ( V_32 )
return V_32 ;
}
if ( F_66 ( V_169 -> V_192 ) ) {
V_32 = F_77 ( V_8 , V_169 -> V_192 ) ;
if ( V_32 )
return V_32 ;
}
return F_71 ( & V_183 -> V_24 , V_169 -> V_170 ,
L_9 , true , V_169 -> V_171 ) ;
}
static void F_78 ( struct V_182 * V_183 )
{
struct V_184 * V_169 = V_183 -> V_24 . V_185 ;
if ( ! V_169 )
return;
if ( F_66 ( V_169 -> V_170 ) )
F_79 ( V_169 -> V_170 ) ;
}
static inline T_5 F_80 ( struct V_1 * V_2 )
{
T_5 V_193 = F_81 ( V_194 ) ;
if ( V_2 -> V_169 && V_2 -> V_169 -> V_195 )
V_193 -= 3 ;
return V_193 ;
}
static int F_82 ( struct V_182 * V_183 )
{
int V_32 ;
struct V_60 * V_8 ;
struct V_1 * V_2 ;
struct V_184 * V_169 ;
V_169 = V_183 -> V_24 . V_185 ;
V_8 = F_83 ( sizeof( struct V_1 ) , & V_183 -> V_24 ) ;
if ( ! V_8 ) {
F_7 ( & V_183 -> V_24 , L_10 ) ;
return - V_59 ;
}
V_2 = F_22 ( V_8 ) ;
V_2 -> V_169 = V_169 ;
V_2 -> V_64 = F_84 ( V_183 , 0 ) ;
if ( V_2 -> V_64 < 0 ) {
V_32 = V_2 -> V_64 ;
F_7 ( & V_183 -> V_24 , L_11 , V_32 ) ;
goto V_196;
}
V_2 -> V_162 = F_85 ( & V_183 -> V_24 , L_12 ) ;
if ( F_86 ( V_2 -> V_162 ) ) {
V_32 = F_87 ( V_2 -> V_162 ) ;
F_7 ( & V_183 -> V_24 , L_13 ) ;
goto V_196;
}
V_2 -> V_47 = F_88 ( V_183 , V_197 , 0 ) ;
V_2 -> V_68 = F_89 ( & V_183 -> V_24 , V_2 -> V_47 ) ;
if ( F_86 ( V_2 -> V_68 ) ) {
V_32 = F_87 ( V_2 -> V_68 ) ;
F_7 ( & V_183 -> V_24 , L_14 ) ;
goto V_196;
}
V_32 = F_90 ( V_194 , F_80 ( V_2 ) ) ;
if ( V_32 ) {
F_7 ( & V_183 -> V_24 , L_15 , V_32 ) ;
goto V_196;
}
V_32 = F_75 ( V_8 , V_183 ) ;
if ( V_32 )
goto V_198;
V_8 -> V_199 = & V_200 ;
V_8 -> V_201 = V_163 / 128 ;
V_8 -> V_202 = V_163 ;
V_8 -> V_203 = V_204 | V_205 ;
V_8 -> V_206 = ( V_169 && V_169 -> V_195 ) ? 0 : V_207 ;
V_8 -> V_206 |= V_208 ;
V_8 -> V_209 = ( 1 << 10 ) - 1 ;
V_8 -> V_210 = ( 1 << 15 ) - 1 ;
V_8 -> V_211 = V_8 -> V_209 * V_8 -> V_210 ;
V_8 -> V_212 = 128 ;
V_8 -> V_213 = V_8 -> V_211 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_183 = V_183 ;
F_91 ( & V_2 -> V_66 ) ;
V_2 -> V_67 = 0xffff ;
V_32 = F_92 ( V_2 -> V_64 , F_58 , F_57 , 0 ,
F_93 ( & V_183 -> V_24 ) , V_2 ) ;
if ( V_32 ) {
F_7 ( & V_183 -> V_24 , L_16 , V_32 ) ;
goto V_214;
}
F_33 ( V_2 ) ;
F_31 ( V_2 ) ;
F_94 ( & V_2 -> V_85 , F_49 ,
( unsigned long ) V_2 ) ;
V_2 -> V_3 = true ;
if ( V_2 -> V_3 && F_3 ( V_2 ) != 0 )
V_2 -> V_3 = false ;
F_95 ( V_183 , V_2 ) ;
V_32 = F_96 ( V_8 ) ;
if ( V_32 ) {
F_7 ( & V_183 -> V_24 , L_17 , V_32 ) ;
goto V_215;
}
F_97 ( & V_183 -> V_24 , L_18 ) ;
F_97 ( & V_183 -> V_24 , L_19 ,
V_2 -> V_3 ? L_20 : L_21 ,
( V_8 -> V_206 & V_207 ) ? 4 : 1 ) ;
return 0 ;
V_215:
F_98 ( V_2 -> V_64 , V_2 ) ;
V_214:
F_78 ( V_183 ) ;
V_198:
if ( V_2 -> V_3 )
F_1 ( V_2 ) ;
F_99 ( V_194 , F_80 ( V_2 ) ) ;
V_196:
F_100 ( V_8 ) ;
return V_32 ;
}
static int F_101 ( struct V_182 * V_183 )
{
struct V_1 * V_2 = F_102 ( V_183 ) ;
F_103 ( & V_2 -> V_85 ) ;
F_26 ( V_2 , 0xff , false ) ;
F_33 ( V_2 ) ;
F_104 ( V_2 -> V_8 ) ;
F_98 ( V_2 -> V_64 , V_2 ) ;
F_78 ( V_183 ) ;
F_99 ( V_194 , F_80 ( V_2 ) ) ;
if ( V_2 -> V_3 )
F_1 ( V_2 ) ;
F_100 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_105 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_106 ( V_24 ) ;
F_107 ( V_194 , F_80 ( V_2 ) ) ;
return 0 ;
}
static int F_108 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_106 ( V_24 ) ;
F_109 ( V_194 , F_80 ( V_2 ) ) ;
return 0 ;
}

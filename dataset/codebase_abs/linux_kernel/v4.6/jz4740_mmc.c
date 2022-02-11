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
struct V_61 * V_62 ,
bool V_63 )
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
int V_64 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
struct V_13 * V_14 = V_62 -> V_14 ;
if ( V_2 -> V_3 && V_14 -> V_29 ) {
F_11 ( V_2 , V_14 ) ;
V_14 -> V_29 = 0 ;
}
if ( V_64 ) {
struct V_19 * V_20 = F_10 ( V_2 , V_14 ) ;
F_25 ( V_20 ) ;
}
}
static void F_26 ( struct V_1 * V_2 ,
unsigned int V_65 , bool V_66 )
{
unsigned long V_15 ;
F_27 ( & V_2 -> V_67 , V_15 ) ;
if ( V_66 )
V_2 -> V_68 &= ~ V_65 ;
else
V_2 -> V_68 |= V_65 ;
F_28 ( & V_2 -> V_67 , V_15 ) ;
F_29 ( V_2 -> V_68 , V_2 -> V_69 + V_70 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
bool V_71 )
{
T_2 V_72 = V_73 ;
if ( V_71 )
V_72 |= V_74 ;
F_29 ( V_72 , V_2 -> V_69 + V_75 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_3 V_76 ;
unsigned int V_77 = 1000 ;
F_29 ( V_78 , V_2 -> V_69 + V_75 ) ;
do {
V_76 = F_32 ( V_2 -> V_69 + V_79 ) ;
} while ( V_76 & V_80 && -- V_77 );
}
static void F_33 ( struct V_1 * V_2 )
{
T_3 V_76 ;
unsigned int V_77 = 1000 ;
F_29 ( V_81 , V_2 -> V_69 + V_75 ) ;
F_34 ( 10 ) ;
do {
V_76 = F_32 ( V_2 -> V_69 + V_79 ) ;
} while ( V_76 & V_82 && -- V_77 );
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_61 * V_83 ;
V_83 = V_2 -> V_83 ;
V_2 -> V_83 = NULL ;
F_36 ( V_2 -> V_8 , V_83 ) ;
}
static unsigned int F_37 ( struct V_1 * V_2 ,
unsigned int V_65 )
{
unsigned int V_77 = 0x800 ;
T_2 V_76 ;
do {
V_76 = F_38 ( V_2 -> V_69 + V_84 ) ;
} while ( ! ( V_76 & V_65 ) && -- V_77 );
if ( V_77 == 0 ) {
F_39 ( 0 , & V_2 -> V_85 ) ;
F_40 ( & V_2 -> V_86 , V_87 + 5 * V_88 ) ;
F_26 ( V_2 , V_65 , true ) ;
return true ;
}
return false ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
int V_76 ;
V_76 = F_32 ( V_2 -> V_69 + V_79 ) ;
if ( V_76 & V_89 ) {
if ( V_76 & ( V_90 ) ) {
V_2 -> V_83 -> V_91 -> error = - V_92 ;
V_14 -> error = - V_92 ;
} else {
V_2 -> V_83 -> V_91 -> error = - V_93 ;
V_14 -> error = - V_93 ;
}
} else if ( V_76 & V_94 ) {
if ( V_76 & ( V_95 ) ) {
V_2 -> V_83 -> V_91 -> error = - V_92 ;
V_14 -> error = - V_92 ;
} else {
V_2 -> V_83 -> V_91 -> error = - V_93 ;
V_14 -> error = - V_93 ;
}
}
}
static bool F_42 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_96 * V_97 = & V_2 -> V_97 ;
void T_4 * V_98 = V_2 -> V_69 + V_49 ;
T_3 * V_99 ;
bool V_77 ;
T_5 V_100 , V_101 ;
while ( F_43 ( V_97 ) ) {
V_99 = V_97 -> V_102 ;
V_100 = V_97 -> V_103 / 4 ;
V_101 = V_100 / 8 ;
V_100 = V_100 & 0x7 ;
while ( V_101 ) {
V_77 = F_37 ( V_2 , V_104 ) ;
if ( F_44 ( V_77 ) )
goto V_105;
F_45 ( V_99 [ 0 ] , V_98 ) ;
F_45 ( V_99 [ 1 ] , V_98 ) ;
F_45 ( V_99 [ 2 ] , V_98 ) ;
F_45 ( V_99 [ 3 ] , V_98 ) ;
F_45 ( V_99 [ 4 ] , V_98 ) ;
F_45 ( V_99 [ 5 ] , V_98 ) ;
F_45 ( V_99 [ 6 ] , V_98 ) ;
F_45 ( V_99 [ 7 ] , V_98 ) ;
V_99 += 8 ;
-- V_101 ;
}
if ( F_44 ( V_100 ) ) {
V_77 = F_37 ( V_2 , V_104 ) ;
if ( F_44 ( V_77 ) )
goto V_105;
while ( V_100 ) {
F_45 ( * V_99 , V_98 ) ;
++ V_99 ;
-- V_100 ;
}
}
V_14 -> V_106 += V_97 -> V_103 ;
}
F_46 ( V_97 ) ;
return false ;
V_105:
V_97 -> V_107 = ( void * ) V_99 - V_97 -> V_102 ;
V_14 -> V_106 += V_97 -> V_107 ;
F_46 ( V_97 ) ;
return true ;
}
static bool F_47 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_96 * V_97 = & V_2 -> V_97 ;
void T_4 * V_98 = V_2 -> V_69 + V_54 ;
T_3 * V_99 ;
T_3 V_108 ;
T_2 V_76 ;
T_5 V_100 , V_101 ;
unsigned int V_77 ;
while ( F_43 ( V_97 ) ) {
V_99 = V_97 -> V_102 ;
V_100 = V_97 -> V_103 ;
V_101 = V_100 / 32 ;
V_100 = V_100 & 0x1f ;
while ( V_101 ) {
V_77 = F_37 ( V_2 , V_109 ) ;
if ( F_44 ( V_77 ) )
goto V_105;
V_99 [ 0 ] = F_32 ( V_98 ) ;
V_99 [ 1 ] = F_32 ( V_98 ) ;
V_99 [ 2 ] = F_32 ( V_98 ) ;
V_99 [ 3 ] = F_32 ( V_98 ) ;
V_99 [ 4 ] = F_32 ( V_98 ) ;
V_99 [ 5 ] = F_32 ( V_98 ) ;
V_99 [ 6 ] = F_32 ( V_98 ) ;
V_99 [ 7 ] = F_32 ( V_98 ) ;
V_99 += 8 ;
-- V_101 ;
}
if ( F_44 ( V_100 ) ) {
V_77 = F_37 ( V_2 , V_109 ) ;
if ( F_44 ( V_77 ) )
goto V_105;
while ( V_100 >= 4 ) {
* V_99 ++ = F_32 ( V_98 ) ;
V_100 -= 4 ;
}
if ( F_44 ( V_100 > 0 ) ) {
V_108 = F_32 ( V_98 ) ;
memcpy ( V_99 , & V_108 , V_100 ) ;
}
}
V_14 -> V_106 += V_97 -> V_103 ;
F_48 ( V_97 -> V_110 ) ;
}
F_46 ( V_97 ) ;
V_77 = 1000 ;
V_76 = F_32 ( V_2 -> V_69 + V_79 ) ;
while ( ! ( V_76 & V_111 ) && -- V_77 ) {
V_108 = F_32 ( V_98 ) ;
V_76 = F_32 ( V_2 -> V_69 + V_79 ) ;
}
return false ;
V_105:
V_97 -> V_107 = ( void * ) V_99 - V_97 -> V_102 ;
V_14 -> V_106 += V_97 -> V_107 ;
F_46 ( V_97 ) ;
return true ;
}
static void F_49 ( unsigned long V_14 )
{
struct V_1 * V_2 = (struct V_1 * ) V_14 ;
if ( ! F_50 ( 0 , & V_2 -> V_85 ) )
return;
F_26 ( V_2 , V_112 , false ) ;
V_2 -> V_83 -> V_91 -> error = - V_92 ;
F_35 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 ,
struct V_113 * V_91 )
{
int V_100 ;
T_2 V_114 ;
void T_4 * V_98 = V_2 -> V_69 + V_115 ;
if ( V_91 -> V_15 & V_116 ) {
V_114 = F_38 ( V_98 ) ;
for ( V_100 = 0 ; V_100 < 4 ; ++ V_100 ) {
V_91 -> V_117 [ V_100 ] = V_114 << 24 ;
V_114 = F_38 ( V_98 ) ;
V_91 -> V_117 [ V_100 ] |= V_114 << 8 ;
V_114 = F_38 ( V_98 ) ;
V_91 -> V_117 [ V_100 ] |= V_114 >> 8 ;
}
} else {
V_91 -> V_117 [ 0 ] = F_38 ( V_98 ) << 24 ;
V_91 -> V_117 [ 0 ] |= F_38 ( V_98 ) << 8 ;
V_91 -> V_117 [ 0 ] |= F_38 ( V_98 ) & 0xff ;
}
}
static void F_52 ( struct V_1 * V_2 ,
struct V_113 * V_91 )
{
T_3 V_118 = V_2 -> V_118 ;
V_2 -> V_118 &= ~ V_119 ;
F_31 ( V_2 ) ;
V_2 -> V_91 = V_91 ;
if ( V_91 -> V_15 & V_120 )
V_118 |= V_121 ;
switch ( F_53 ( V_91 ) ) {
case V_122 :
case V_123 :
V_118 |= V_124 ;
break;
case V_125 :
V_118 |= V_126 ;
break;
case V_127 :
V_118 |= V_128 ;
break;
default:
break;
}
if ( V_91 -> V_14 ) {
V_118 |= V_129 ;
if ( V_91 -> V_14 -> V_15 & V_43 )
V_118 |= V_130 ;
if ( V_2 -> V_3 )
V_118 |= V_131 ;
F_29 ( V_91 -> V_14 -> V_132 , V_2 -> V_69 + V_133 ) ;
F_29 ( V_91 -> V_14 -> V_134 , V_2 -> V_69 + V_135 ) ;
}
F_54 ( V_91 -> V_136 , V_2 -> V_69 + V_137 ) ;
F_45 ( V_91 -> V_138 , V_2 -> V_69 + V_139 ) ;
F_45 ( V_118 , V_2 -> V_69 + V_140 ) ;
F_30 ( V_2 , 1 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_113 * V_91 = V_2 -> V_83 -> V_91 ;
struct V_13 * V_14 = V_91 -> V_14 ;
int V_44 ;
if ( V_14 -> V_15 & V_16 )
V_44 = V_141 ;
else
V_44 = V_142 ;
F_56 ( & V_2 -> V_97 , V_14 -> V_25 , V_14 -> V_26 , V_44 ) ;
}
static T_6 F_57 ( int V_65 , void * V_143 )
{
struct V_1 * V_2 = (struct V_1 * ) V_143 ;
struct V_113 * V_91 = V_2 -> V_83 -> V_91 ;
struct V_61 * V_83 = V_2 -> V_83 ;
struct V_13 * V_14 = V_91 -> V_14 ;
bool V_77 = false ;
if ( V_91 -> error )
V_2 -> V_144 = V_145 ;
switch ( V_2 -> V_144 ) {
case V_146 :
if ( V_91 -> V_15 & V_147 )
F_51 ( V_2 , V_91 ) ;
if ( ! V_14 )
break;
F_55 ( V_2 ) ;
case V_148 :
if ( V_2 -> V_3 ) {
V_77 = F_16 ( V_2 , V_14 ) ;
V_14 -> V_106 = V_14 -> V_134 * V_14 -> V_132 ;
} else if ( V_14 -> V_15 & V_16 )
V_77 = F_47 ( V_2 , V_14 ) ;
else
V_77 = F_42 ( V_2 , V_14 ) ;
if ( F_44 ( V_77 ) ) {
V_2 -> V_144 = V_148 ;
break;
}
F_41 ( V_2 , V_14 ) ;
V_77 = F_37 ( V_2 , V_149 ) ;
if ( F_44 ( V_77 ) ) {
V_2 -> V_144 = V_150 ;
break;
}
F_29 ( V_149 , V_2 -> V_69 + V_84 ) ;
case V_150 :
if ( ! V_83 -> V_151 )
break;
F_52 ( V_2 , V_83 -> V_151 ) ;
if ( F_53 ( V_83 -> V_151 ) & V_120 ) {
V_77 = F_37 ( V_2 ,
V_152 ) ;
if ( V_77 ) {
V_2 -> V_144 = V_145 ;
break;
}
}
case V_145 :
break;
}
if ( ! V_77 )
F_35 ( V_2 ) ;
return V_153 ;
}
static T_6 F_58 ( int V_65 , void * V_143 )
{
struct V_1 * V_2 = V_143 ;
struct V_113 * V_91 = V_2 -> V_91 ;
T_2 V_154 , V_76 , V_114 ;
V_154 = F_38 ( V_2 -> V_69 + V_84 ) ;
V_114 = V_154 ;
V_154 &= ~ V_2 -> V_68 ;
V_114 &= ~ ( V_104 | V_109 |
V_152 | V_149 ) ;
if ( V_114 != V_154 )
F_29 ( V_114 & ~ V_154 , V_2 -> V_69 + V_84 ) ;
if ( V_154 & V_155 ) {
F_29 ( V_155 , V_2 -> V_69 + V_84 ) ;
F_59 ( V_2 -> V_8 ) ;
V_154 &= ~ V_155 ;
}
if ( V_2 -> V_83 && V_91 && V_154 ) {
if ( F_50 ( 0 , & V_2 -> V_85 ) ) {
F_60 ( & V_2 -> V_86 ) ;
V_76 = F_32 ( V_2 -> V_69 + V_79 ) ;
if ( V_76 & V_156 ) {
V_91 -> error = - V_92 ;
} else if ( V_76 & V_157 ) {
V_91 -> error = - V_93 ;
} else if ( V_76 & ( V_158 |
V_159 ) ) {
if ( V_91 -> V_14 )
V_91 -> V_14 -> error = - V_93 ;
V_91 -> error = - V_93 ;
}
F_26 ( V_2 , V_154 , false ) ;
F_29 ( V_154 , V_2 -> V_69 + V_84 ) ;
return V_160 ;
}
}
return V_153 ;
}
static int F_61 ( struct V_1 * V_2 , int V_161 )
{
int div = 0 ;
int V_162 ;
F_31 ( V_2 ) ;
F_62 ( V_2 -> V_163 , V_164 ) ;
V_162 = F_63 ( V_2 -> V_163 ) ;
while ( V_162 > V_161 && div < 7 ) {
++ div ;
V_162 >>= 1 ;
}
F_29 ( div , V_2 -> V_69 + V_165 ) ;
return V_162 ;
}
static void F_64 ( struct V_60 * V_8 , struct V_61 * V_83 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
V_2 -> V_83 = V_83 ;
F_29 ( 0xffff , V_2 -> V_69 + V_84 ) ;
F_29 ( V_112 , V_2 -> V_69 + V_84 ) ;
F_26 ( V_2 , V_112 , true ) ;
V_2 -> V_144 = V_146 ;
F_39 ( 0 , & V_2 -> V_85 ) ;
F_40 ( & V_2 -> V_86 , V_87 + 5 * V_88 ) ;
F_52 ( V_2 , V_83 -> V_91 ) ;
}
static void F_65 ( struct V_60 * V_8 , struct V_166 * V_167 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
if ( V_167 -> clock )
F_61 ( V_2 , V_167 -> clock ) ;
switch ( V_167 -> V_168 ) {
case V_169 :
F_33 ( V_2 ) ;
if ( F_66 ( V_2 -> V_170 -> V_171 ) )
F_67 ( V_2 -> V_170 -> V_171 ,
! V_2 -> V_170 -> V_172 ) ;
V_2 -> V_118 |= V_119 ;
F_68 ( V_2 -> V_163 ) ;
break;
case V_173 :
break;
default:
if ( F_66 ( V_2 -> V_170 -> V_171 ) )
F_67 ( V_2 -> V_170 -> V_171 ,
V_2 -> V_170 -> V_172 ) ;
F_69 ( V_2 -> V_163 ) ;
break;
}
switch ( V_167 -> V_174 ) {
case V_175 :
V_2 -> V_118 &= ~ V_176 ;
break;
case V_177 :
V_2 -> V_118 |= V_176 ;
break;
default:
break;
}
}
static void F_70 ( struct V_60 * V_8 , int V_178 )
{
struct V_1 * V_2 = F_22 ( V_8 ) ;
F_26 ( V_2 , V_155 , V_178 ) ;
}
static int F_71 ( struct V_23 * V_24 , int V_179 ,
const char * V_180 , bool V_181 , int V_182 )
{
int V_32 ;
if ( ! F_66 ( V_179 ) )
return 0 ;
V_32 = F_72 ( V_179 , V_180 ) ;
if ( V_32 ) {
F_7 ( V_24 , L_8 , V_180 , V_32 ) ;
return V_32 ;
}
if ( V_181 )
F_73 ( V_179 , V_182 ) ;
else
F_74 ( V_179 ) ;
return 0 ;
}
static int F_75 ( struct V_60 * V_8 ,
struct V_183 * V_184 )
{
struct V_185 * V_170 = V_184 -> V_24 . V_186 ;
int V_32 = 0 ;
if ( ! V_170 )
return 0 ;
if ( ! V_170 -> V_187 )
V_8 -> V_188 |= V_189 ;
if ( ! V_170 -> V_190 )
V_8 -> V_188 |= V_191 ;
if ( F_66 ( V_170 -> V_192 ) ) {
V_32 = F_76 ( V_8 , V_170 -> V_192 , 0 ) ;
if ( V_32 )
return V_32 ;
}
if ( F_66 ( V_170 -> V_193 ) ) {
V_32 = F_77 ( V_8 , V_170 -> V_193 ) ;
if ( V_32 )
return V_32 ;
}
return F_71 ( & V_184 -> V_24 , V_170 -> V_171 ,
L_9 , true , V_170 -> V_172 ) ;
}
static void F_78 ( struct V_183 * V_184 )
{
struct V_185 * V_170 = V_184 -> V_24 . V_186 ;
if ( ! V_170 )
return;
if ( F_66 ( V_170 -> V_171 ) )
F_79 ( V_170 -> V_171 ) ;
}
static inline T_5 F_80 ( struct V_1 * V_2 )
{
T_5 V_194 = F_81 ( V_195 ) ;
if ( V_2 -> V_170 && V_2 -> V_170 -> V_196 )
V_194 -= 3 ;
return V_194 ;
}
static int F_82 ( struct V_183 * V_184 )
{
int V_32 ;
struct V_60 * V_8 ;
struct V_1 * V_2 ;
struct V_185 * V_170 ;
V_170 = V_184 -> V_24 . V_186 ;
V_8 = F_83 ( sizeof( struct V_1 ) , & V_184 -> V_24 ) ;
if ( ! V_8 ) {
F_7 ( & V_184 -> V_24 , L_10 ) ;
return - V_59 ;
}
V_2 = F_22 ( V_8 ) ;
V_2 -> V_170 = V_170 ;
V_2 -> V_65 = F_84 ( V_184 , 0 ) ;
if ( V_2 -> V_65 < 0 ) {
V_32 = V_2 -> V_65 ;
F_7 ( & V_184 -> V_24 , L_11 , V_32 ) ;
goto V_197;
}
V_2 -> V_163 = F_85 ( & V_184 -> V_24 , L_12 ) ;
if ( F_86 ( V_2 -> V_163 ) ) {
V_32 = F_87 ( V_2 -> V_163 ) ;
F_7 ( & V_184 -> V_24 , L_13 ) ;
goto V_197;
}
V_2 -> V_47 = F_88 ( V_184 , V_198 , 0 ) ;
V_2 -> V_69 = F_89 ( & V_184 -> V_24 , V_2 -> V_47 ) ;
if ( F_86 ( V_2 -> V_69 ) ) {
V_32 = F_87 ( V_2 -> V_69 ) ;
F_7 ( & V_184 -> V_24 , L_14 ) ;
goto V_197;
}
V_32 = F_90 ( V_195 , F_80 ( V_2 ) ) ;
if ( V_32 ) {
F_7 ( & V_184 -> V_24 , L_15 , V_32 ) ;
goto V_197;
}
V_32 = F_75 ( V_8 , V_184 ) ;
if ( V_32 )
goto V_199;
V_8 -> V_200 = & V_201 ;
V_8 -> V_202 = V_164 / 128 ;
V_8 -> V_203 = V_164 ;
V_8 -> V_204 = V_205 | V_206 ;
V_8 -> V_207 = ( V_170 && V_170 -> V_196 ) ? 0 : V_208 ;
V_8 -> V_207 |= V_209 ;
V_8 -> V_210 = ( 1 << 10 ) - 1 ;
V_8 -> V_211 = ( 1 << 15 ) - 1 ;
V_8 -> V_212 = V_8 -> V_210 * V_8 -> V_211 ;
V_8 -> V_213 = 128 ;
V_8 -> V_214 = V_8 -> V_212 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_184 = V_184 ;
F_91 ( & V_2 -> V_67 ) ;
V_2 -> V_68 = 0xffff ;
V_32 = F_92 ( V_2 -> V_65 , F_58 , F_57 , 0 ,
F_93 ( & V_184 -> V_24 ) , V_2 ) ;
if ( V_32 ) {
F_7 ( & V_184 -> V_24 , L_16 , V_32 ) ;
goto V_215;
}
F_33 ( V_2 ) ;
F_31 ( V_2 ) ;
F_94 ( & V_2 -> V_86 , F_49 ,
( unsigned long ) V_2 ) ;
F_95 ( & V_2 -> V_86 , V_88 ) ;
V_2 -> V_3 = true ;
if ( V_2 -> V_3 && F_3 ( V_2 ) != 0 )
V_2 -> V_3 = false ;
F_96 ( V_184 , V_2 ) ;
V_32 = F_97 ( V_8 ) ;
if ( V_32 ) {
F_7 ( & V_184 -> V_24 , L_17 , V_32 ) ;
goto V_216;
}
F_98 ( & V_184 -> V_24 , L_18 ) ;
F_98 ( & V_184 -> V_24 , L_19 ,
V_2 -> V_3 ? L_20 : L_21 ,
( V_8 -> V_207 & V_208 ) ? 4 : 1 ) ;
return 0 ;
V_216:
F_99 ( V_2 -> V_65 , V_2 ) ;
V_215:
F_78 ( V_184 ) ;
V_199:
if ( V_2 -> V_3 )
F_1 ( V_2 ) ;
F_100 ( V_195 , F_80 ( V_2 ) ) ;
V_197:
F_101 ( V_8 ) ;
return V_32 ;
}
static int F_102 ( struct V_183 * V_184 )
{
struct V_1 * V_2 = F_103 ( V_184 ) ;
F_104 ( & V_2 -> V_86 ) ;
F_26 ( V_2 , 0xff , false ) ;
F_33 ( V_2 ) ;
F_105 ( V_2 -> V_8 ) ;
F_99 ( V_2 -> V_65 , V_2 ) ;
F_78 ( V_184 ) ;
F_100 ( V_195 , F_80 ( V_2 ) ) ;
if ( V_2 -> V_3 )
F_1 ( V_2 ) ;
F_101 ( V_2 -> V_8 ) ;
return 0 ;
}
static int F_106 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_107 ( V_24 ) ;
F_108 ( V_195 , F_80 ( V_2 ) ) ;
return 0 ;
}
static int F_109 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_107 ( V_24 ) ;
F_110 ( V_195 , F_80 ( V_2 ) ) ;
return 0 ;
}

static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , bool V_4 )
{
unsigned long V_5 ;
F_2 ( & V_2 -> V_6 , V_5 ) ;
if ( V_4 )
V_2 -> V_7 &= ~ V_3 ;
else
V_2 -> V_7 |= V_3 ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
F_4 ( V_2 -> V_7 , V_2 -> V_8 + V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
bool V_10 )
{
T_1 V_11 = V_12 ;
if ( V_10 )
V_11 |= V_13 ;
F_4 ( V_11 , V_2 -> V_8 + V_14 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_2 V_15 ;
unsigned int V_16 = 1000 ;
F_4 ( V_17 , V_2 -> V_8 + V_14 ) ;
do {
V_15 = F_7 ( V_2 -> V_8 + V_18 ) ;
} while ( V_15 & V_19 && -- V_16 );
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_15 ;
unsigned int V_16 = 1000 ;
F_4 ( V_20 , V_2 -> V_8 + V_14 ) ;
F_9 ( 10 ) ;
do {
V_15 = F_7 ( V_2 -> V_8 + V_18 ) ;
} while ( V_15 & V_21 && -- V_16 );
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = V_2 -> V_23 ;
V_2 -> V_23 = NULL ;
F_11 ( V_2 -> V_24 , V_23 ) ;
}
static unsigned int F_12 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned int V_16 = 0x800 ;
T_1 V_15 ;
do {
V_15 = F_13 ( V_2 -> V_8 + V_25 ) ;
} while ( ! ( V_15 & V_3 ) && -- V_16 );
if ( V_16 == 0 ) {
F_14 ( 0 , & V_2 -> V_26 ) ;
F_15 ( & V_2 -> V_27 , V_28 + 5 * V_29 ) ;
F_1 ( V_2 , V_3 , true ) ;
return true ;
}
return false ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
int V_15 ;
V_15 = F_7 ( V_2 -> V_8 + V_18 ) ;
if ( V_15 & V_32 ) {
if ( V_15 & ( V_33 ) ) {
V_2 -> V_23 -> V_34 -> error = - V_35 ;
V_31 -> error = - V_35 ;
} else {
V_2 -> V_23 -> V_34 -> error = - V_36 ;
V_31 -> error = - V_36 ;
}
} else if ( V_15 & V_37 ) {
if ( V_15 & ( V_38 ) ) {
V_2 -> V_23 -> V_34 -> error = - V_35 ;
V_31 -> error = - V_35 ;
} else {
V_2 -> V_23 -> V_34 -> error = - V_36 ;
V_31 -> error = - V_36 ;
}
}
}
static bool F_17 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_39 * V_40 = & V_2 -> V_40 ;
void T_3 * V_41 = V_2 -> V_8 + V_42 ;
T_2 * V_43 ;
bool V_16 ;
T_4 V_44 , V_45 ;
while ( F_18 ( V_40 ) ) {
V_43 = V_40 -> V_46 ;
V_44 = V_40 -> V_47 / 4 ;
V_45 = V_44 / 8 ;
V_44 = V_44 & 0x7 ;
while ( V_45 ) {
V_16 = F_12 ( V_2 , V_48 ) ;
if ( F_19 ( V_16 ) )
goto V_49;
F_20 ( V_43 [ 0 ] , V_41 ) ;
F_20 ( V_43 [ 1 ] , V_41 ) ;
F_20 ( V_43 [ 2 ] , V_41 ) ;
F_20 ( V_43 [ 3 ] , V_41 ) ;
F_20 ( V_43 [ 4 ] , V_41 ) ;
F_20 ( V_43 [ 5 ] , V_41 ) ;
F_20 ( V_43 [ 6 ] , V_41 ) ;
F_20 ( V_43 [ 7 ] , V_41 ) ;
V_43 += 8 ;
-- V_45 ;
}
if ( F_19 ( V_44 ) ) {
V_16 = F_12 ( V_2 , V_48 ) ;
if ( F_19 ( V_16 ) )
goto V_49;
while ( V_44 ) {
F_20 ( * V_43 , V_41 ) ;
++ V_43 ;
-- V_44 ;
}
}
V_31 -> V_50 += V_40 -> V_47 ;
}
F_21 ( V_40 ) ;
return false ;
V_49:
V_40 -> V_51 = ( void * ) V_43 - V_40 -> V_46 ;
V_31 -> V_50 += V_40 -> V_51 ;
F_21 ( V_40 ) ;
return true ;
}
static bool F_22 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_39 * V_40 = & V_2 -> V_40 ;
void T_3 * V_41 = V_2 -> V_8 + V_52 ;
T_2 * V_43 ;
T_2 V_53 ;
T_1 V_15 ;
T_4 V_44 , V_45 ;
unsigned int V_16 ;
while ( F_18 ( V_40 ) ) {
V_43 = V_40 -> V_46 ;
V_44 = V_40 -> V_47 ;
V_45 = V_44 / 32 ;
V_44 = V_44 & 0x1f ;
while ( V_45 ) {
V_16 = F_12 ( V_2 , V_54 ) ;
if ( F_19 ( V_16 ) )
goto V_49;
V_43 [ 0 ] = F_7 ( V_41 ) ;
V_43 [ 1 ] = F_7 ( V_41 ) ;
V_43 [ 2 ] = F_7 ( V_41 ) ;
V_43 [ 3 ] = F_7 ( V_41 ) ;
V_43 [ 4 ] = F_7 ( V_41 ) ;
V_43 [ 5 ] = F_7 ( V_41 ) ;
V_43 [ 6 ] = F_7 ( V_41 ) ;
V_43 [ 7 ] = F_7 ( V_41 ) ;
V_43 += 8 ;
-- V_45 ;
}
if ( F_19 ( V_44 ) ) {
V_16 = F_12 ( V_2 , V_54 ) ;
if ( F_19 ( V_16 ) )
goto V_49;
while ( V_44 >= 4 ) {
* V_43 ++ = F_7 ( V_41 ) ;
V_44 -= 4 ;
}
if ( F_19 ( V_44 > 0 ) ) {
V_53 = F_7 ( V_41 ) ;
memcpy ( V_43 , & V_53 , V_44 ) ;
}
}
V_31 -> V_50 += V_40 -> V_47 ;
F_23 ( V_40 -> V_55 ) ;
}
F_21 ( V_40 ) ;
V_16 = 1000 ;
V_15 = F_7 ( V_2 -> V_8 + V_18 ) ;
while ( ! ( V_15 & V_56 ) && -- V_16 ) {
V_53 = F_7 ( V_41 ) ;
V_15 = F_7 ( V_2 -> V_8 + V_18 ) ;
}
return false ;
V_49:
V_40 -> V_51 = ( void * ) V_43 - V_40 -> V_46 ;
V_31 -> V_50 += V_40 -> V_51 ;
F_21 ( V_40 ) ;
return true ;
}
static void F_24 ( unsigned long V_31 )
{
struct V_1 * V_2 = (struct V_1 * ) V_31 ;
if ( ! F_25 ( 0 , & V_2 -> V_26 ) )
return;
F_1 ( V_2 , V_57 , false ) ;
V_2 -> V_23 -> V_34 -> error = - V_35 ;
F_10 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_58 * V_34 )
{
int V_44 ;
T_1 V_59 ;
void T_3 * V_41 = V_2 -> V_8 + V_60 ;
if ( V_34 -> V_5 & V_61 ) {
V_59 = F_13 ( V_41 ) ;
for ( V_44 = 0 ; V_44 < 4 ; ++ V_44 ) {
V_34 -> V_62 [ V_44 ] = V_59 << 24 ;
V_59 = F_13 ( V_41 ) ;
V_34 -> V_62 [ V_44 ] |= V_59 << 8 ;
V_59 = F_13 ( V_41 ) ;
V_34 -> V_62 [ V_44 ] |= V_59 >> 8 ;
}
} else {
V_34 -> V_62 [ 0 ] = F_13 ( V_41 ) << 24 ;
V_34 -> V_62 [ 0 ] |= F_13 ( V_41 ) << 8 ;
V_34 -> V_62 [ 0 ] |= F_13 ( V_41 ) & 0xff ;
}
}
static void F_27 ( struct V_1 * V_2 ,
struct V_58 * V_34 )
{
T_2 V_63 = V_2 -> V_63 ;
V_2 -> V_63 &= ~ V_64 ;
F_6 ( V_2 ) ;
V_2 -> V_34 = V_34 ;
if ( V_34 -> V_5 & V_65 )
V_63 |= V_66 ;
switch ( F_28 ( V_34 ) ) {
case V_67 :
case V_68 :
V_63 |= V_69 ;
break;
case V_70 :
V_63 |= V_71 ;
break;
case V_72 :
V_63 |= V_73 ;
break;
default:
break;
}
if ( V_34 -> V_31 ) {
V_63 |= V_74 ;
if ( V_34 -> V_31 -> V_5 & V_75 )
V_63 |= V_76 ;
if ( V_34 -> V_31 -> V_5 & V_77 )
V_63 |= V_78 ;
F_4 ( V_34 -> V_31 -> V_79 , V_2 -> V_8 + V_80 ) ;
F_4 ( V_34 -> V_31 -> V_81 , V_2 -> V_8 + V_82 ) ;
}
F_29 ( V_34 -> V_83 , V_2 -> V_8 + V_84 ) ;
F_20 ( V_34 -> V_85 , V_2 -> V_8 + V_86 ) ;
F_20 ( V_63 , V_2 -> V_8 + V_87 ) ;
F_5 ( V_2 , 1 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_58 * V_34 = V_2 -> V_23 -> V_34 ;
struct V_30 * V_31 = V_34 -> V_31 ;
int V_88 ;
if ( V_31 -> V_5 & V_89 )
V_88 = V_90 ;
else
V_88 = V_91 ;
F_31 ( & V_2 -> V_40 , V_31 -> V_92 , V_31 -> V_93 , V_88 ) ;
}
static T_5 F_32 ( int V_3 , void * V_94 )
{
struct V_1 * V_2 = (struct V_1 * ) V_94 ;
struct V_58 * V_34 = V_2 -> V_23 -> V_34 ;
struct V_22 * V_23 = V_2 -> V_23 ;
bool V_16 = false ;
if ( V_34 -> error )
V_2 -> V_95 = V_96 ;
switch ( V_2 -> V_95 ) {
case V_97 :
if ( V_34 -> V_5 & V_98 )
F_26 ( V_2 , V_34 ) ;
if ( ! V_34 -> V_31 )
break;
F_30 ( V_2 ) ;
case V_99 :
if ( V_34 -> V_31 -> V_5 & V_89 )
V_16 = F_22 ( V_2 , V_34 -> V_31 ) ;
else
V_16 = F_17 ( V_2 , V_34 -> V_31 ) ;
if ( F_19 ( V_16 ) ) {
V_2 -> V_95 = V_99 ;
break;
}
F_16 ( V_2 , V_34 -> V_31 ) ;
V_16 = F_12 ( V_2 , V_100 ) ;
if ( F_19 ( V_16 ) ) {
V_2 -> V_95 = V_101 ;
break;
}
F_4 ( V_100 , V_2 -> V_8 + V_25 ) ;
case V_101 :
if ( ! V_23 -> V_102 )
break;
F_27 ( V_2 , V_23 -> V_102 ) ;
if ( F_28 ( V_23 -> V_102 ) & V_65 ) {
V_16 = F_12 ( V_2 ,
V_103 ) ;
if ( V_16 ) {
V_2 -> V_95 = V_96 ;
break;
}
}
case V_96 :
break;
}
if ( ! V_16 )
F_10 ( V_2 ) ;
return V_104 ;
}
static T_5 F_33 ( int V_3 , void * V_94 )
{
struct V_1 * V_2 = V_94 ;
struct V_58 * V_34 = V_2 -> V_34 ;
T_1 V_105 , V_15 , V_59 ;
V_105 = F_13 ( V_2 -> V_8 + V_25 ) ;
V_59 = V_105 ;
V_105 &= ~ V_2 -> V_7 ;
V_59 &= ~ ( V_48 | V_54 |
V_103 | V_100 ) ;
if ( V_59 != V_105 )
F_4 ( V_59 & ~ V_105 , V_2 -> V_8 + V_25 ) ;
if ( V_105 & V_106 ) {
F_4 ( V_106 , V_2 -> V_8 + V_25 ) ;
F_34 ( V_2 -> V_24 ) ;
V_105 &= ~ V_106 ;
}
if ( V_2 -> V_23 && V_34 && V_105 ) {
if ( F_25 ( 0 , & V_2 -> V_26 ) ) {
F_35 ( & V_2 -> V_27 ) ;
V_15 = F_7 ( V_2 -> V_8 + V_18 ) ;
if ( V_15 & V_107 ) {
V_34 -> error = - V_35 ;
} else if ( V_15 & V_108 ) {
V_34 -> error = - V_36 ;
} else if ( V_15 & ( V_109 |
V_110 ) ) {
if ( V_34 -> V_31 )
V_34 -> V_31 -> error = - V_36 ;
V_34 -> error = - V_36 ;
}
F_1 ( V_2 , V_105 , false ) ;
F_4 ( V_105 , V_2 -> V_8 + V_25 ) ;
return V_111 ;
}
}
return V_104 ;
}
static int F_36 ( struct V_1 * V_2 , int V_112 )
{
int div = 0 ;
int V_113 ;
F_6 ( V_2 ) ;
F_37 ( V_2 -> V_114 , V_115 ) ;
V_113 = F_38 ( V_2 -> V_114 ) ;
while ( V_113 > V_112 && div < 7 ) {
++ div ;
V_113 >>= 1 ;
}
F_4 ( div , V_2 -> V_8 + V_116 ) ;
return V_113 ;
}
static void F_39 ( struct V_117 * V_24 , struct V_22 * V_23 )
{
struct V_1 * V_2 = F_40 ( V_24 ) ;
V_2 -> V_23 = V_23 ;
F_4 ( 0xffff , V_2 -> V_8 + V_25 ) ;
F_4 ( V_57 , V_2 -> V_8 + V_25 ) ;
F_1 ( V_2 , V_57 , true ) ;
V_2 -> V_95 = V_97 ;
F_14 ( 0 , & V_2 -> V_26 ) ;
F_15 ( & V_2 -> V_27 , V_28 + 5 * V_29 ) ;
F_27 ( V_2 , V_23 -> V_34 ) ;
}
static void F_41 ( struct V_117 * V_24 , struct V_118 * V_119 )
{
struct V_1 * V_2 = F_40 ( V_24 ) ;
if ( V_119 -> clock )
F_36 ( V_2 , V_119 -> clock ) ;
switch ( V_119 -> V_120 ) {
case V_121 :
F_8 ( V_2 ) ;
if ( F_42 ( V_2 -> V_122 -> V_123 ) )
F_43 ( V_2 -> V_122 -> V_123 ,
! V_2 -> V_122 -> V_124 ) ;
V_2 -> V_63 |= V_64 ;
F_44 ( V_2 -> V_114 ) ;
break;
case V_125 :
break;
default:
if ( F_42 ( V_2 -> V_122 -> V_123 ) )
F_43 ( V_2 -> V_122 -> V_123 ,
V_2 -> V_122 -> V_124 ) ;
F_45 ( V_2 -> V_114 ) ;
break;
}
switch ( V_119 -> V_126 ) {
case V_127 :
V_2 -> V_63 &= ~ V_128 ;
break;
case V_129 :
V_2 -> V_63 |= V_128 ;
break;
default:
break;
}
}
static void F_46 ( struct V_117 * V_24 , int V_130 )
{
struct V_1 * V_2 = F_40 ( V_24 ) ;
F_1 ( V_2 , V_106 , V_130 ) ;
}
static int F_47 ( struct V_131 * V_132 , int V_133 ,
const char * V_134 , bool V_135 , int V_136 )
{
int V_137 ;
if ( ! F_42 ( V_133 ) )
return 0 ;
V_137 = F_48 ( V_133 , V_134 ) ;
if ( V_137 ) {
F_49 ( V_132 , L_1 , V_134 , V_137 ) ;
return V_137 ;
}
if ( V_135 )
F_50 ( V_133 , V_136 ) ;
else
F_51 ( V_133 ) ;
return 0 ;
}
static int F_52 ( struct V_117 * V_24 ,
struct V_138 * V_139 )
{
struct V_140 * V_122 = V_139 -> V_132 . V_141 ;
int V_137 = 0 ;
if ( ! V_122 )
return 0 ;
if ( ! V_122 -> V_142 )
V_24 -> V_143 |= V_144 ;
if ( ! V_122 -> V_145 )
V_24 -> V_143 |= V_146 ;
if ( F_42 ( V_122 -> V_147 ) ) {
V_137 = F_53 ( V_24 , V_122 -> V_147 , 0 ) ;
if ( V_137 )
return V_137 ;
}
if ( F_42 ( V_122 -> V_148 ) ) {
V_137 = F_54 ( V_24 , V_122 -> V_148 ) ;
if ( V_137 )
return V_137 ;
}
return F_47 ( & V_139 -> V_132 , V_122 -> V_123 ,
L_2 , true , V_122 -> V_124 ) ;
}
static void F_55 ( struct V_138 * V_139 )
{
struct V_140 * V_122 = V_139 -> V_132 . V_141 ;
if ( ! V_122 )
return;
if ( F_42 ( V_122 -> V_123 ) )
F_56 ( V_122 -> V_123 ) ;
}
static inline T_4 F_57 ( struct V_1 * V_2 )
{
T_4 V_149 = F_58 ( V_150 ) ;
if ( V_2 -> V_122 && V_2 -> V_122 -> V_151 )
V_149 -= 3 ;
return V_149 ;
}
static int F_59 ( struct V_138 * V_139 )
{
int V_137 ;
struct V_117 * V_24 ;
struct V_1 * V_2 ;
struct V_140 * V_122 ;
struct V_152 * V_153 ;
V_122 = V_139 -> V_132 . V_141 ;
V_24 = F_60 ( sizeof( struct V_1 ) , & V_139 -> V_132 ) ;
if ( ! V_24 ) {
F_49 ( & V_139 -> V_132 , L_3 ) ;
return - V_154 ;
}
V_2 = F_40 ( V_24 ) ;
V_2 -> V_122 = V_122 ;
V_2 -> V_3 = F_61 ( V_139 , 0 ) ;
if ( V_2 -> V_3 < 0 ) {
V_137 = V_2 -> V_3 ;
F_49 ( & V_139 -> V_132 , L_4 , V_137 ) ;
goto V_155;
}
V_2 -> V_114 = F_62 ( & V_139 -> V_132 , L_5 ) ;
if ( F_63 ( V_2 -> V_114 ) ) {
V_137 = F_64 ( V_2 -> V_114 ) ;
F_49 ( & V_139 -> V_132 , L_6 ) ;
goto V_155;
}
V_153 = F_65 ( V_139 , V_156 , 0 ) ;
V_2 -> V_8 = F_66 ( & V_139 -> V_132 , V_153 ) ;
if ( F_63 ( V_2 -> V_8 ) ) {
V_137 = F_64 ( V_2 -> V_8 ) ;
goto V_155;
}
V_137 = F_67 ( V_150 , F_57 ( V_2 ) ) ;
if ( V_137 ) {
F_49 ( & V_139 -> V_132 , L_7 , V_137 ) ;
goto V_155;
}
V_137 = F_52 ( V_24 , V_139 ) ;
if ( V_137 )
goto V_157;
V_24 -> V_158 = & V_159 ;
V_24 -> V_160 = V_115 / 128 ;
V_24 -> V_161 = V_115 ;
V_24 -> V_162 = V_163 | V_164 ;
V_24 -> V_165 = ( V_122 && V_122 -> V_151 ) ? 0 : V_166 ;
V_24 -> V_165 |= V_167 ;
V_24 -> V_168 = ( 1 << 10 ) - 1 ;
V_24 -> V_169 = ( 1 << 15 ) - 1 ;
V_24 -> V_170 = V_24 -> V_168 * V_24 -> V_169 ;
V_24 -> V_171 = 128 ;
V_24 -> V_172 = V_24 -> V_170 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_139 = V_139 ;
F_68 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = 0xffff ;
V_137 = F_69 ( V_2 -> V_3 , F_33 , F_32 , 0 ,
F_70 ( & V_139 -> V_132 ) , V_2 ) ;
if ( V_137 ) {
F_49 ( & V_139 -> V_132 , L_8 , V_137 ) ;
goto V_173;
}
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
F_71 ( & V_2 -> V_27 , F_24 ,
( unsigned long ) V_2 ) ;
F_72 ( & V_2 -> V_27 , V_29 ) ;
F_73 ( V_139 , V_2 ) ;
V_137 = F_74 ( V_24 ) ;
if ( V_137 ) {
F_49 ( & V_139 -> V_132 , L_9 , V_137 ) ;
goto V_174;
}
F_75 ( & V_139 -> V_132 , L_10 ) ;
return 0 ;
V_174:
F_76 ( V_2 -> V_3 , V_2 ) ;
V_173:
F_55 ( V_139 ) ;
V_157:
F_77 ( V_150 , F_57 ( V_2 ) ) ;
V_155:
F_78 ( V_24 ) ;
return V_137 ;
}
static int F_79 ( struct V_138 * V_139 )
{
struct V_1 * V_2 = F_80 ( V_139 ) ;
F_81 ( & V_2 -> V_27 ) ;
F_1 ( V_2 , 0xff , false ) ;
F_8 ( V_2 ) ;
F_82 ( V_2 -> V_24 ) ;
F_76 ( V_2 -> V_3 , V_2 ) ;
F_55 ( V_139 ) ;
F_77 ( V_150 , F_57 ( V_2 ) ) ;
F_78 ( V_2 -> V_24 ) ;
return 0 ;
}
static int F_83 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_84 ( V_132 ) ;
F_85 ( V_150 , F_57 ( V_2 ) ) ;
return 0 ;
}
static int F_86 ( struct V_131 * V_132 )
{
struct V_1 * V_2 = F_84 ( V_132 ) ;
F_87 ( V_150 , F_57 ( V_2 ) ) ;
return 0 ;
}

static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( ! V_4 -> V_5 ( V_4 ) )
return V_6 ;
V_4 -> V_7 ( V_4 , 0 ) ;
F_2 ( & V_4 -> V_8 ) ;
return V_9 ;
}
static int F_3 ( struct V_3 * V_4 )
{
T_2 V_10 ;
V_10 = F_4 ( V_11 ) ;
if ( ! ( V_10 & V_12 ) )
return 0 ;
V_10 &= ~ V_12 ;
F_5 ( V_10 , V_11 ) ;
return 1 ;
}
static int F_6 ( struct V_3 * V_4 )
{
T_2 V_10 ;
V_10 = F_7 ( V_13 ) ;
if ( ! ( V_10 & V_14 ) )
return 0 ;
if ( ! F_8 () )
F_9 ( V_10 & ~ V_14 , V_13 ) ;
return 1 ;
}
static void F_10 ( struct V_3 * V_4 , int V_15 )
{
if ( V_15 )
F_11 ( V_4 -> V_1 ) ;
else
F_12 ( V_4 -> V_1 ) ;
}
static void F_13 ( struct V_3 * V_4 , int V_15 )
{
T_3 V_10 ;
V_10 = F_7 ( V_16 ) ;
if ( V_15 )
V_10 &= ~ V_17 ;
else
V_10 |= V_17 ;
F_9 ( V_10 , V_16 ) ;
}
static void F_14 ( struct V_3 * V_4 , int V_15 )
{
T_2 V_10 ;
V_10 = F_4 ( V_18 ) ;
if ( V_15 )
V_10 &= ~ V_19 ;
else
V_10 |= V_19 ;
F_5 ( V_10 , V_18 ) ;
}
static void F_15 ( struct V_3 * V_4 , int V_20 )
{
int V_21 = 8000 ;
if ( V_20 ) {
if ( ! V_4 -> V_5 ( V_4 ) ) {
F_16 ( V_4 -> V_8 ) ;
V_4 -> V_7 ( V_4 , 1 ) ;
F_17 ( & V_4 -> V_8 ) ;
}
} else {
while ( V_21 -- > 0 ) {
if ( V_4 -> V_5 ( V_4 ) )
break;
F_18 ( 1 ) ;
}
if ( V_21 < 0 )
F_19 ( V_22 , L_1 ,
V_23 ) ;
}
}
static void F_20 ( struct V_3 * V_4 , T_3 V_24 , int V_20 )
{
F_5 ( V_24 , V_25 ) ;
F_5 ( V_26 , V_27 ) ;
F_15 ( V_4 , V_20 ) ;
}
static void F_21 ( struct V_3 * V_4 , T_3 V_24 , int V_20 )
{
F_19 ( V_28 , L_2 , V_24 , V_20 ) ;
F_9 ( V_24 , V_29 ) ;
F_9 ( V_26 , V_13 ) ;
if ( F_8 () && ( V_24 == V_30 ) ) {
int V_21 = 100 ;
while ( V_21 -- > 0 ) {
if ( F_7 ( V_13 ) == 0 ) {
break;
}
F_18 ( 1 ) ;
}
if ( V_21 < 0 )
F_19 ( V_22 , L_3 ,
V_23 ) ;
} else {
F_15 ( V_4 , V_20 ) ;
}
}
static void F_22 ( struct V_3 * V_4 , T_3 V_31 , int V_32 )
{
F_5 ( V_31 , V_33 ) ;
F_5 ( V_34 , V_27 ) ;
F_15 ( V_4 , 0 ) ;
}
static void F_23 ( struct V_3 * V_4 , T_3 V_31 , int V_32 )
{
F_19 ( V_28 , L_4 , V_31 , V_32 ) ;
F_9 ( V_31 , V_35 ) ;
F_9 ( V_34 , V_13 ) ;
F_15 ( V_4 , V_32 ) ;
}
static void F_24 ( struct V_36 * V_37 , unsigned int V_38 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
T_2 V_10 ;
V_10 = F_4 ( V_41 ) ;
V_10 &= ~ ( 7 << 4 ) ;
F_5 ( V_10 , V_41 ) ;
F_5 ( V_38 , V_27 ) ;
F_15 ( V_4 , false ) ;
}
static void F_25 ( struct V_36 * V_37 , unsigned int V_38 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
int V_42 , V_43 ;
if ( F_26 () && V_37 -> V_44 > 512 )
V_42 = 4 ;
else
V_42 = 1 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
F_9 ( ( V_4 -> V_45 << 4 ) | V_43 , V_46 ) ;
F_9 ( V_38 , V_13 ) ;
F_15 ( V_4 , true ) ;
}
}
static void F_27 ( struct V_3 * V_4 )
{
F_5 ( V_47 , V_27 ) ;
F_15 ( V_4 , true ) ;
memcpy ( V_4 -> V_48 , V_4 -> V_49 , 16 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_39 * V_50 = & V_4 -> V_51 ;
F_9 ( V_4 -> V_45 << 4 , V_46 ) ;
F_9 ( V_47 , V_13 ) ;
F_15 ( V_4 , true ) ;
memcpy ( V_4 -> V_48 , V_4 -> V_49 , 16 ) ;
if ( V_50 -> V_52 & V_53 ) {
V_4 -> V_48 [ 1 ] = V_4 -> V_48 [ 2 ] ;
V_4 -> V_48 [ 2 ] = V_4 -> V_48 [ 4 ] ;
V_4 -> V_48 [ 3 ] = V_4 -> V_48 [ 6 ] ;
V_4 -> V_48 [ 4 ] = V_4 -> V_48 [ 8 ] ;
V_4 -> V_48 [ 5 ] = V_4 -> V_48 [ 10 ] ;
}
}
static T_3 F_29 ( struct V_3 * V_4 )
{
F_9 ( V_54 , V_27 ) ;
F_15 ( V_4 , true ) ;
return F_4 ( V_41 ) >> 16 ;
}
static T_3 F_30 ( struct V_3 * V_4 )
{
void T_4 * V_55 = V_4 -> V_49 ;
T_2 V_56 ;
T_3 V_57 ;
F_9 ( V_4 -> V_45 << 4 , V_46 ) ;
V_56 = F_4 ( V_55 ) ;
F_9 ( V_54 , V_13 ) ;
F_15 ( V_4 , true ) ;
V_57 = F_7 ( V_55 ) ;
F_5 ( V_56 , V_55 ) ;
return V_57 ;
}
static int F_31 ( struct V_36 * V_37 )
{
return 1 ;
}
static void F_32 ( struct V_36 * V_37 , int V_58 )
{
}
static int F_33 ( struct V_36 * V_37 , T_5 * V_59 ,
T_5 * V_60 , T_5 * V_61 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
T_3 V_62 = F_7 ( V_63 ) ;
if ( ( ( V_62 & 0x3 ) == 2 ) || ( ( V_62 >> 2 ) == 2 ) ) {
F_19 ( V_22 ,
L_5 ) ;
return - 1 ;
}
return 0 ;
}
static int F_34 ( struct V_36 * V_37 , T_5 * V_59 ,
T_5 * V_60 , T_5 * V_61 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
T_6 V_64 , V_65 ;
int V_66 = 1 ;
int V_57 = 0 ;
T_7 V_67 , V_68 ;
V_67 = ( V_4 -> V_69 == 4 ) ? 0x7 : 0xf ;
V_68 = ( V_4 -> V_69 == 4 ) ? 0x4 : 0x8 ;
V_66 = V_37 -> V_44 >> 9 ;
if ( F_35 () )
V_64 = F_4 ( V_63 ) ;
else
V_64 = F_4 ( V_70 ) ;
do {
V_65 = V_64 & V_67 ;
if ( V_65 > V_68 ) {
F_36 ( V_71 L_6 ) ;
return - 1 ;
} else {
V_57 += V_65 ;
}
V_64 >>= 4 ;
} while ( -- V_66 );
V_37 -> V_72 . V_73 += V_57 ;
F_37 ( L_7 , V_57 ) ;
return V_57 ;
}
static int F_38 ( struct V_36 * V_37 , const T_5 * V_59 ,
T_5 * V_74 )
{
return 0 ;
}
static T_5 F_39 ( struct V_36 * V_37 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
T_8 V_57 ;
if ( V_4 -> V_75 )
return V_4 -> V_76 ( V_4 ) & 0xFF ;
V_57 = * ( T_8 * ) ( V_4 -> V_48 + V_4 -> V_77 ) ;
V_4 -> V_77 ++ ;
return V_57 ;
}
static T_3 F_40 ( struct V_36 * V_37 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
T_3 V_57 ;
V_57 = * ( T_3 * ) ( V_4 -> V_48 + V_4 -> V_77 ) ;
V_4 -> V_77 += 2 ;
return V_57 ;
}
static void F_41 ( struct V_36 * V_37 ,
const T_5 * V_78 , int V_79 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
T_9 V_80 = V_4 -> V_77 ;
int V_81 = V_37 -> V_82 + V_37 -> V_44 - V_80 ;
V_81 = F_42 ( V_81 , V_79 ) ;
memcpy ( V_4 -> V_48 + V_80 , V_78 , V_81 ) ;
V_4 -> V_77 += V_81 ;
}
static void F_43 ( struct V_36 * V_37 , T_5 * V_78 , int V_79 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
T_9 V_80 = V_4 -> V_77 ;
int V_81 = V_37 -> V_82 + V_37 -> V_44 - V_80 ;
V_81 = F_42 ( V_81 , V_79 ) ;
memcpy ( V_78 , V_4 -> V_48 + V_80 , V_81 ) ;
V_4 -> V_77 += V_81 ;
}
static int F_44 ( struct V_36 * V_37 ,
const T_5 * V_78 , int V_79 )
{
return - V_83 ;
}
static void F_45 ( struct V_36 * V_37 , int V_84 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
if ( V_84 == - 1 ) {
if ( V_4 -> V_85 ) {
F_46 ( V_4 -> V_86 ) ;
V_4 -> V_85 = 0 ;
}
return;
}
if ( ! V_4 -> V_85 ) {
F_47 ( V_4 -> V_86 ) ;
V_4 -> V_85 = 1 ;
}
if ( F_35 () ) {
V_4 -> V_45 = V_84 ;
F_9 ( V_4 -> V_45 << 4 , V_46 ) ;
}
}
static void F_48 ( struct V_36 * V_37 , bool V_87 )
{
struct V_39 * V_50 = V_37 -> V_40 ;
struct V_3 * V_4 = V_50 -> V_40 ;
T_9 V_43 , V_88 ;
T_9 V_81 = V_37 -> V_44 >> 9 ;
T_7 * V_89 = V_4 -> V_48 + V_37 -> V_44 ;
T_7 * V_90 = V_4 -> V_91 ;
T_9 V_92 = V_4 -> V_93 ;
V_88 = ( V_37 -> V_82 / V_81 >> 1 ) << 1 ;
if ( V_87 ) {
for ( V_43 = 0 ; V_43 < V_81 - 1 ; V_43 ++ )
memcpy ( V_89 + V_43 * V_88 , V_90 + V_43 * V_92 , V_88 ) ;
memcpy ( V_89 + V_43 * V_88 , V_90 + V_43 * V_92 , V_37 -> V_82 - V_43 * V_88 ) ;
} else {
for ( V_43 = 0 ; V_43 < V_81 - 1 ; V_43 ++ )
memcpy ( & V_90 [ V_43 * V_92 ] , & V_89 [ V_43 * V_88 ] , V_88 ) ;
memcpy ( & V_90 [ V_43 * V_92 ] , & V_89 [ V_43 * V_88 ] , V_37 -> V_82 - V_43 * V_88 ) ;
}
}
static void F_49 ( struct V_36 * V_37 , int V_94 , int V_95 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
if ( V_94 != - 1 ) {
V_4 -> V_96 ( V_4 , 0 , V_95 == - 1 ) ;
if ( V_37 -> V_44 > 512 )
V_4 -> V_96 ( V_4 , 0 , false ) ;
}
if ( V_95 != - 1 ) {
V_4 -> V_96 ( V_4 , ( V_95 & 0xff ) , false ) ;
if ( V_37 -> V_44 > 512 ) {
if ( V_37 -> V_97 >= 0x10000000 ) {
V_4 -> V_96 ( V_4 , ( V_95 >> 8 ) & 0xff , false ) ;
V_4 -> V_96 ( V_4 , ( V_95 >> 16 ) & 0xff , true ) ;
} else
V_4 -> V_96 ( V_4 , ( V_95 >> 8 ) & 0xff , true ) ;
} else {
if ( V_37 -> V_97 >= 0x4000000 ) {
V_4 -> V_96 ( V_4 , ( V_95 >> 8 ) & 0xff , false ) ;
V_4 -> V_96 ( V_4 , ( V_95 >> 16 ) & 0xff , true ) ;
} else
V_4 -> V_96 ( V_4 , ( V_95 >> 8 ) & 0xff , true ) ;
}
}
}
static int F_50 ( struct V_36 * V_37 )
{
int V_98 = 0 ;
V_98 = V_37 -> V_82 * 512 / V_37 -> V_44 ;
if ( V_98 < 26 )
return 4 ;
else
return 8 ;
}
static void F_51 ( struct V_36 * V_37 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
T_3 V_99 = 0 ;
if ( V_39 -> V_100 . V_58 == V_101 )
V_99 |= V_102 ;
if ( F_35 () )
V_99 |= V_103 ;
if ( ! F_8 () )
V_99 |= V_17 ;
if ( F_35 () && V_37 -> V_44 ) {
T_3 V_104 = V_37 -> V_105 / V_37 -> V_44 ;
V_4 -> V_69 = F_50 ( V_37 ) ;
if ( V_4 -> V_69 == 4 )
V_99 |= V_106 ;
V_99 |= F_52 ( F_53 ( V_104 ) - 6 ) ;
} else {
V_4 -> V_69 = 1 ;
}
F_9 ( V_99 , V_16 ) ;
F_9 ( 0x2 , V_107 ) ;
if ( F_35 () ) {
F_9 ( 0x0 , V_108 ) ;
F_9 ( 0x0 , V_109 ) ;
F_9 ( 0x0 , V_110 ) ;
F_9 ( 0x0 , V_111 ) ;
F_9 ( 0xffff , V_112 ) ;
F_9 ( 0xffff , V_113 ) ;
F_9 ( 0xffff , V_114 ) ;
F_9 ( 0xffff , V_115 ) ;
} else if ( F_26 () ) {
F_9 ( 0x0 , V_116 ) ;
F_9 ( 0x4000 , V_117 ) ;
} else
F_54 () ;
F_9 ( 0x4 , V_118 ) ;
}
static void F_55 ( struct V_36 * V_37 )
{
struct V_39 * V_84 = V_37 -> V_40 ;
struct V_3 * V_4 = V_84 -> V_40 ;
T_2 V_119 , V_120 ;
int V_43 , V_121 ;
F_5 ( F_56 ( 0 ) , V_41 ) ;
F_5 ( V_122 , V_11 ) ;
F_5 ( V_123 | V_124 ,
V_125 ) ;
for ( V_43 = 0 ; V_43 < V_126 ; V_43 ++ )
F_5 ( 0x0 | ( 0xffff << 16 ) ,
V_127 + ( V_43 << 2 ) ) ;
F_5 ( 0 , V_11 ) ;
V_119 = V_128 |
V_129 |
F_57 ( V_37 -> V_82 >> 1 ) |
F_58 ( 0x70 ) |
V_19 |
V_130 ;
if ( V_84 -> V_100 . V_58 == V_101 )
V_119 |= V_131 ;
V_121 = F_59 ( V_84 -> V_132 ) >> 3 ;
if ( V_37 -> V_44 == 2048 ) {
V_119 |= V_133 ;
V_119 |= F_60 ( V_121 ) ;
} else if ( V_37 -> V_44 == 4096 ) {
V_119 |= V_134 ;
V_119 |= F_60 ( V_121 ) ;
} else {
V_119 |= V_135 ;
V_119 |= F_60 ( V_121 - 1 ) ;
}
if ( V_37 -> V_44 ) {
V_119 |= F_61 ( F_53 ( V_37 -> V_105 / V_37 -> V_44 ) - 6 ) ;
V_4 -> V_69 = F_50 ( V_37 ) ;
if ( V_4 -> V_69 == 8 )
V_119 |= V_136 ;
}
F_5 ( V_119 , V_18 ) ;
V_120 = F_62 ( 0 ) |
V_137 |
V_138 |
F_63 ( 6 ) |
F_64 ( 0 ) ;
if ( ! ( V_84 -> V_52 & V_53 ) )
V_120 |= V_139 ;
F_5 ( V_120 , V_140 ) ;
F_5 ( 0 , V_141 ) ;
}
static void F_65 ( struct V_36 * V_37 , unsigned V_142 ,
int V_94 , int V_95 )
{
struct V_39 * V_39 = V_37 -> V_40 ;
struct V_3 * V_4 = V_39 -> V_40 ;
F_19 ( V_28 ,
L_8 ,
V_142 , V_94 , V_95 ) ;
V_4 -> V_75 = false ;
switch ( V_142 ) {
case V_30 :
V_4 -> V_143 ( V_37 ) ;
V_4 -> V_144 ( V_4 , V_142 , false ) ;
break;
case V_145 :
V_4 -> V_77 = 0 ;
V_4 -> V_75 = true ;
V_4 -> V_144 ( V_4 , V_142 , true ) ;
F_49 ( V_37 , V_94 , V_95 ) ;
break;
case V_146 :
case V_147 :
if ( V_142 == V_146 )
V_4 -> V_77 = V_94 ;
else
V_4 -> V_77 = V_94 + V_37 -> V_44 ;
V_142 = V_146 ;
V_4 -> V_144 ( V_4 , V_142 , false ) ;
F_49 ( V_37 , V_94 , V_95 ) ;
if ( V_37 -> V_44 > 512 )
V_4 -> V_144 ( V_4 , V_148 , true ) ;
V_4 -> V_149 ( V_37 , V_150 ) ;
memcpy ( V_4 -> V_48 , V_4 -> V_49 , V_37 -> V_44 ) ;
F_48 ( V_37 , true ) ;
break;
case V_151 :
if ( V_94 >= V_37 -> V_44 )
F_65 ( V_37 , V_146 , 0 , V_95 ) ;
V_4 -> V_77 = V_94 ;
V_4 -> V_144 ( V_4 , V_142 , false ) ;
F_49 ( V_37 , V_94 , V_95 ) ;
break;
case V_152 :
memcpy ( V_4 -> V_49 , V_4 -> V_48 , V_37 -> V_44 ) ;
F_48 ( V_37 , false ) ;
V_4 -> V_149 ( V_37 , V_153 ) ;
V_4 -> V_144 ( V_4 , V_142 , true ) ;
F_49 ( V_37 , V_94 , V_95 ) ;
break;
case V_154 :
V_4 -> V_144 ( V_4 , V_142 , true ) ;
F_49 ( V_37 , V_94 , V_95 ) ;
V_4 -> V_155 ( V_4 ) ;
V_4 -> V_77 = V_94 ;
break;
case V_156 :
case V_157 :
V_4 -> V_144 ( V_4 , V_142 , false ) ;
F_49 ( V_37 , V_94 , V_95 ) ;
break;
}
}
static int T_10 F_66 ( struct V_158 * V_159 )
{
struct V_39 * V_50 ;
struct V_36 * V_37 ;
struct V_160 * V_161 = V_159 -> V_162 . V_163 ;
struct V_3 * V_4 ;
struct V_164 * V_165 ;
int V_65 = 0 , V_166 V_167 = 0 ;
struct V_168 * V_169 , * V_170 ;
V_4 = F_67 ( sizeof( struct V_3 ) + V_171 +
V_172 , V_173 ) ;
if ( ! V_4 )
return - V_174 ;
V_4 -> V_48 = ( T_8 * ) ( V_4 + 1 ) ;
V_4 -> V_162 = & V_159 -> V_162 ;
V_50 = & V_4 -> V_51 ;
V_37 = & V_4 -> V_37 ;
V_37 -> V_40 = V_50 ;
V_37 -> V_175 = V_176 ;
V_37 -> V_162 . V_177 = & V_159 -> V_162 ;
V_37 -> V_178 = V_179 ;
V_50 -> V_180 = 5 ;
V_50 -> V_40 = V_4 ;
V_50 -> V_181 = F_31 ;
V_50 -> V_182 = F_65 ;
V_50 -> V_183 = F_45 ;
V_50 -> V_184 = F_39 ;
V_50 -> V_185 = F_40 ;
V_50 -> V_186 = F_41 ;
V_50 -> V_187 = F_43 ;
V_50 -> V_188 = F_44 ;
V_4 -> V_86 = F_68 ( & V_159 -> V_162 , L_9 ) ;
if ( F_69 ( V_4 -> V_86 ) ) {
V_65 = F_70 ( V_4 -> V_86 ) ;
goto V_189;
}
F_47 ( V_4 -> V_86 ) ;
V_4 -> V_85 = 1 ;
V_165 = F_71 ( V_159 , V_190 , 0 ) ;
if ( ! V_165 ) {
V_65 = - V_191 ;
goto V_192;
}
V_4 -> V_193 = F_72 ( V_165 -> V_194 , F_73 ( V_165 ) ) ;
if ( ! V_4 -> V_193 ) {
V_65 = - V_174 ;
goto V_192;
}
V_4 -> V_49 = V_4 -> V_193 ;
if ( F_26 () || F_35 () ) {
V_4 -> V_143 = F_51 ;
V_4 -> V_144 = F_21 ;
V_4 -> V_96 = F_23 ;
V_4 -> V_149 = F_25 ;
V_4 -> V_155 = F_28 ;
V_4 -> V_76 = F_30 ;
V_4 -> V_5 = F_6 ;
if ( F_8 () )
V_4 -> V_7 = F_10 ;
else
V_4 -> V_7 = F_13 ;
}
if ( F_35 () ) {
V_4 -> V_195 = V_4 -> V_193 + 0x1e00 ;
V_4 -> V_91 = V_4 -> V_193 + 0x1000 ;
V_4 -> V_93 = 64 ;
V_169 = & V_196 ;
V_170 = & V_197 ;
V_50 -> V_100 . V_198 = 9 ;
} else if ( F_26 () ) {
V_4 -> V_195 = V_4 -> V_193 + 0xe00 ;
V_4 -> V_91 = V_4 -> V_193 + 0x800 ;
V_4 -> V_93 = 16 ;
V_169 = & V_199 ;
V_170 = & V_200 ;
V_50 -> V_100 . V_198 = 3 ;
V_4 -> V_69 = 1 ;
} else if ( F_74 () ) {
V_165 = F_71 ( V_159 , V_190 , 1 ) ;
if ( ! V_165 ) {
V_65 = - V_191 ;
goto V_201;
}
V_4 -> V_202 = F_72 ( V_165 -> V_194 , F_73 ( V_165 ) ) ;
if ( ! V_4 -> V_202 ) {
V_65 = - V_174 ;
goto V_201;
}
V_4 -> V_203 = V_4 -> V_193 + 0x1e00 ;
V_4 -> V_91 = V_4 -> V_193 + 0x1000 ;
V_4 -> V_93 = 64 ;
V_4 -> V_143 = F_55 ;
V_4 -> V_144 = F_20 ;
V_4 -> V_96 = F_22 ;
V_4 -> V_149 = F_24 ;
V_4 -> V_155 = F_27 ;
V_4 -> V_5 = F_3 ;
V_4 -> V_76 = F_29 ;
V_4 -> V_7 = F_14 ;
V_169 = & V_196 ;
V_170 = & V_197 ;
} else
F_54 () ;
V_50 -> V_100 . V_97 = 512 ;
V_50 -> V_100 . V_204 = V_169 ;
if ( V_161 -> V_205 ) {
V_50 -> V_100 . V_206 = F_38 ;
V_50 -> V_100 . V_207 = F_32 ;
if ( F_26 () )
V_50 -> V_100 . V_208 = F_33 ;
else
V_50 -> V_100 . V_208 = F_34 ;
V_50 -> V_100 . V_58 = V_101 ;
} else {
V_50 -> V_100 . V_58 = V_209 ;
}
if ( V_161 -> V_210 == 2 )
V_50 -> V_52 |= V_53 ;
if ( V_161 -> V_211 ) {
V_50 -> V_212 = & V_213 ;
V_50 -> V_214 = & V_215 ;
V_50 -> V_52 |= V_216 ;
}
F_75 ( & V_4 -> V_8 ) ;
V_4 -> V_1 = F_76 ( V_159 , 0 ) ;
if ( F_8 () )
F_13 ( V_4 , 0 ) ;
else
V_4 -> V_7 ( V_4 , 0 ) ;
V_65 = F_77 ( V_4 -> V_1 , F_1 , V_217 , V_179 , V_4 ) ;
if ( V_65 )
goto V_201;
V_4 -> V_7 ( V_4 , 0 ) ;
if ( F_8 () )
F_13 ( V_4 , 1 ) ;
if ( F_78 ( V_37 , F_35 () ? 4 : 1 , NULL ) ) {
V_65 = - V_218 ;
goto V_219;
}
V_4 -> V_143 ( V_37 ) ;
if ( V_37 -> V_44 == 2048 )
V_50 -> V_100 . V_204 = V_170 ;
if ( F_35 () && V_37 -> V_44 == 4096 )
V_50 -> V_100 . V_204 = & V_220 ;
if ( F_79 ( V_37 ) ) {
V_65 = - V_218 ;
goto V_219;
}
V_167 =
F_80 ( V_37 , V_221 , & V_4 -> V_222 , 0 ) ;
if ( V_167 > 0 )
F_81 ( V_37 , V_4 -> V_222 , V_167 ) ;
else if ( V_161 -> V_222 )
F_81 ( V_37 , V_161 -> V_222 , V_161 -> V_167 ) ;
else {
F_82 ( L_10 , V_37 -> V_178 ) ;
F_81 ( V_37 , NULL , 0 ) ;
}
F_83 ( V_159 , V_4 ) ;
return 0 ;
V_219:
F_84 ( V_4 -> V_1 , V_4 ) ;
V_201:
if ( V_4 -> V_202 )
F_85 ( V_4 -> V_202 ) ;
F_85 ( V_4 -> V_193 ) ;
V_192:
F_86 ( V_4 -> V_86 ) ;
V_189:
F_87 ( V_4 ) ;
return V_65 ;
}
static int T_11 F_88 ( struct V_158 * V_159 )
{
struct V_3 * V_4 = F_89 ( V_159 ) ;
F_86 ( V_4 -> V_86 ) ;
F_83 ( V_159 , NULL ) ;
F_90 ( & V_4 -> V_37 ) ;
F_84 ( V_4 -> V_1 , V_4 ) ;
if ( V_4 -> V_202 )
F_85 ( V_4 -> V_202 ) ;
F_85 ( V_4 -> V_193 ) ;
F_87 ( V_4 ) ;
return 0 ;
}
static int T_10 F_91 ( void )
{
return F_92 ( & V_223 , F_66 ) ;
}
static void T_12 F_93 ( void )
{
F_94 ( & V_223 ) ;
}

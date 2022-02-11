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
F_19 ( L_1 , V_22 ) ;
}
}
static void F_20 ( struct V_3 * V_4 , T_3 V_23 , int V_20 )
{
F_5 ( V_23 , V_24 ) ;
F_5 ( V_25 , V_26 ) ;
F_15 ( V_4 , V_20 ) ;
}
static void F_21 ( struct V_3 * V_4 , T_3 V_23 , int V_20 )
{
F_19 ( L_2 , V_23 , V_20 ) ;
F_9 ( V_23 , V_27 ) ;
F_9 ( V_25 , V_13 ) ;
if ( F_8 () && ( V_23 == V_28 ) ) {
int V_21 = 100 ;
while ( V_21 -- > 0 ) {
if ( F_7 ( V_13 ) == 0 ) {
break;
}
F_18 ( 1 ) ;
}
if ( V_21 < 0 )
F_19 ( L_3 , V_22 ) ;
} else {
F_15 ( V_4 , V_20 ) ;
}
}
static void F_22 ( struct V_3 * V_4 , T_3 V_29 , int V_30 )
{
F_5 ( V_29 , V_31 ) ;
F_5 ( V_32 , V_26 ) ;
F_15 ( V_4 , 0 ) ;
}
static void F_23 ( struct V_3 * V_4 , T_3 V_29 , int V_30 )
{
F_19 ( L_4 , V_29 , V_30 ) ;
F_9 ( V_29 , V_33 ) ;
F_9 ( V_32 , V_13 ) ;
F_15 ( V_4 , V_30 ) ;
}
static void F_24 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
T_2 V_10 ;
V_10 = F_4 ( V_39 ) ;
V_10 &= ~ ( 7 << 4 ) ;
F_5 ( V_10 , V_39 ) ;
F_5 ( V_36 , V_26 ) ;
F_15 ( V_4 , false ) ;
}
static void F_25 ( struct V_34 * V_35 , unsigned int V_36 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
int V_40 , V_41 ;
if ( F_26 () && V_35 -> V_42 > 512 )
V_40 = 4 ;
else
V_40 = 1 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
F_9 ( ( V_4 -> V_43 << 4 ) | V_41 , V_44 ) ;
F_9 ( V_36 , V_13 ) ;
F_15 ( V_4 , true ) ;
}
}
static void F_27 ( struct V_3 * V_4 )
{
F_5 ( V_45 , V_26 ) ;
F_15 ( V_4 , true ) ;
memcpy ( V_4 -> V_46 , V_4 -> V_47 , 16 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_37 * V_48 = & V_4 -> V_49 ;
F_9 ( V_4 -> V_43 << 4 , V_44 ) ;
F_9 ( V_45 , V_13 ) ;
F_15 ( V_4 , true ) ;
memcpy ( V_4 -> V_46 , V_4 -> V_47 , 16 ) ;
if ( V_48 -> V_50 & V_51 ) {
V_4 -> V_46 [ 1 ] = V_4 -> V_46 [ 2 ] ;
V_4 -> V_46 [ 2 ] = V_4 -> V_46 [ 4 ] ;
V_4 -> V_46 [ 3 ] = V_4 -> V_46 [ 6 ] ;
V_4 -> V_46 [ 4 ] = V_4 -> V_46 [ 8 ] ;
V_4 -> V_46 [ 5 ] = V_4 -> V_46 [ 10 ] ;
}
}
static T_3 F_29 ( struct V_3 * V_4 )
{
F_9 ( V_52 , V_26 ) ;
F_15 ( V_4 , true ) ;
return F_4 ( V_39 ) >> 16 ;
}
static T_3 F_30 ( struct V_3 * V_4 )
{
void T_4 * V_53 = V_4 -> V_47 ;
T_2 V_54 ;
T_3 V_55 ;
F_9 ( V_4 -> V_43 << 4 , V_44 ) ;
V_54 = F_4 ( V_53 ) ;
F_9 ( V_52 , V_13 ) ;
F_15 ( V_4 , true ) ;
V_55 = F_7 ( V_53 ) ;
F_5 ( V_54 , V_53 ) ;
return V_55 ;
}
static int F_31 ( struct V_34 * V_35 )
{
return 1 ;
}
static void F_32 ( struct V_34 * V_35 , int V_56 )
{
}
static int F_33 ( struct V_34 * V_35 , T_5 * V_57 ,
T_5 * V_58 , T_5 * V_59 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
T_3 V_60 = F_7 ( V_61 ) ;
if ( ( ( V_60 & 0x3 ) == 2 ) || ( ( V_60 >> 2 ) == 2 ) ) {
F_19 ( L_5 ) ;
return - 1 ;
}
return 0 ;
}
static int F_34 ( struct V_34 * V_35 , T_5 * V_57 ,
T_5 * V_58 , T_5 * V_59 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
T_6 V_62 , V_63 ;
int V_64 = 1 ;
int V_55 = 0 ;
T_7 V_65 , V_66 ;
V_65 = ( V_4 -> V_67 == 4 ) ? 0x7 : 0xf ;
V_66 = ( V_4 -> V_67 == 4 ) ? 0x4 : 0x8 ;
V_64 = V_35 -> V_42 >> 9 ;
if ( F_35 () )
V_62 = F_4 ( V_61 ) ;
else
V_62 = F_4 ( V_68 ) ;
do {
V_63 = V_62 & V_65 ;
if ( V_63 > V_66 ) {
F_36 ( V_69 L_6 ) ;
return - 1 ;
} else {
V_55 += V_63 ;
}
V_62 >>= 4 ;
} while ( -- V_64 );
V_35 -> V_70 . V_71 += V_55 ;
F_19 ( L_7 , V_55 ) ;
return V_55 ;
}
static int F_37 ( struct V_34 * V_35 , const T_5 * V_57 ,
T_5 * V_72 )
{
return 0 ;
}
static T_5 F_38 ( struct V_34 * V_35 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
T_8 V_55 ;
if ( V_4 -> V_73 )
return V_4 -> V_74 ( V_4 ) & 0xFF ;
V_55 = * ( T_8 * ) ( V_4 -> V_46 + V_4 -> V_75 ) ;
V_4 -> V_75 ++ ;
return V_55 ;
}
static T_3 F_39 ( struct V_34 * V_35 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
T_3 V_55 ;
V_55 = * ( T_3 * ) ( V_4 -> V_46 + V_4 -> V_75 ) ;
V_4 -> V_75 += 2 ;
return V_55 ;
}
static void F_40 ( struct V_34 * V_35 ,
const T_5 * V_76 , int V_77 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
T_9 V_78 = V_4 -> V_75 ;
int V_79 = V_35 -> V_80 + V_35 -> V_42 - V_78 ;
V_79 = F_41 ( V_79 , V_77 ) ;
memcpy ( V_4 -> V_46 + V_78 , V_76 , V_79 ) ;
V_4 -> V_75 += V_79 ;
}
static void F_42 ( struct V_34 * V_35 , T_5 * V_76 , int V_77 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
T_9 V_78 = V_4 -> V_75 ;
int V_79 = V_35 -> V_80 + V_35 -> V_42 - V_78 ;
V_79 = F_41 ( V_79 , V_77 ) ;
memcpy ( V_76 , V_4 -> V_46 + V_78 , V_79 ) ;
V_4 -> V_75 += V_79 ;
}
static int F_43 ( struct V_34 * V_35 ,
const T_5 * V_76 , int V_77 )
{
return - V_81 ;
}
static void F_44 ( struct V_34 * V_35 , int V_82 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
if ( V_82 == - 1 ) {
if ( V_4 -> V_83 ) {
F_45 ( V_4 -> V_84 ) ;
V_4 -> V_83 = 0 ;
}
return;
}
if ( ! V_4 -> V_83 ) {
F_46 ( V_4 -> V_84 ) ;
V_4 -> V_83 = 1 ;
}
if ( F_35 () ) {
V_4 -> V_43 = V_82 ;
F_9 ( V_4 -> V_43 << 4 , V_44 ) ;
}
}
static void F_47 ( struct V_34 * V_35 , bool V_85 )
{
struct V_37 * V_48 = V_35 -> V_38 ;
struct V_3 * V_4 = V_48 -> V_38 ;
T_9 V_41 , V_86 ;
T_9 V_79 = V_35 -> V_42 >> 9 ;
T_7 * V_87 = V_4 -> V_46 + V_35 -> V_42 ;
T_7 * V_88 = V_4 -> V_89 ;
T_9 V_90 = V_4 -> V_91 ;
V_86 = ( V_35 -> V_80 / V_79 >> 1 ) << 1 ;
if ( V_85 ) {
for ( V_41 = 0 ; V_41 < V_79 - 1 ; V_41 ++ )
memcpy ( V_87 + V_41 * V_86 , V_88 + V_41 * V_90 , V_86 ) ;
memcpy ( V_87 + V_41 * V_86 , V_88 + V_41 * V_90 , V_35 -> V_80 - V_41 * V_86 ) ;
} else {
for ( V_41 = 0 ; V_41 < V_79 - 1 ; V_41 ++ )
memcpy ( & V_88 [ V_41 * V_90 ] , & V_87 [ V_41 * V_86 ] , V_86 ) ;
memcpy ( & V_88 [ V_41 * V_90 ] , & V_87 [ V_41 * V_86 ] , V_35 -> V_80 - V_41 * V_86 ) ;
}
}
static void F_48 ( struct V_34 * V_35 , int V_92 , int V_93 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
if ( V_92 != - 1 ) {
V_4 -> V_94 ( V_4 , 0 , V_93 == - 1 ) ;
if ( V_35 -> V_42 > 512 )
V_4 -> V_94 ( V_4 , 0 , false ) ;
}
if ( V_93 != - 1 ) {
V_4 -> V_94 ( V_4 , ( V_93 & 0xff ) , false ) ;
if ( V_35 -> V_42 > 512 ) {
if ( V_35 -> V_95 >= 0x10000000 ) {
V_4 -> V_94 ( V_4 , ( V_93 >> 8 ) & 0xff , false ) ;
V_4 -> V_94 ( V_4 , ( V_93 >> 16 ) & 0xff , true ) ;
} else
V_4 -> V_94 ( V_4 , ( V_93 >> 8 ) & 0xff , true ) ;
} else {
if ( V_35 -> V_95 >= 0x4000000 ) {
V_4 -> V_94 ( V_4 , ( V_93 >> 8 ) & 0xff , false ) ;
V_4 -> V_94 ( V_4 , ( V_93 >> 16 ) & 0xff , true ) ;
} else
V_4 -> V_94 ( V_4 , ( V_93 >> 8 ) & 0xff , true ) ;
}
}
}
static int F_49 ( struct V_34 * V_35 )
{
int V_96 = 0 ;
V_96 = V_35 -> V_80 * 512 / V_35 -> V_42 ;
if ( V_96 < 26 )
return 4 ;
else
return 8 ;
}
static void F_50 ( struct V_34 * V_35 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
T_3 V_97 = 0 ;
if ( V_37 -> V_98 . V_56 == V_99 )
V_97 |= V_100 ;
if ( F_35 () )
V_97 |= V_101 ;
if ( ! F_8 () )
V_97 |= V_17 ;
if ( F_35 () && V_35 -> V_42 ) {
T_3 V_102 = V_35 -> V_103 / V_35 -> V_42 ;
V_4 -> V_67 = F_49 ( V_35 ) ;
if ( V_4 -> V_67 == 4 )
V_97 |= V_104 ;
V_97 |= F_51 ( F_52 ( V_102 ) - 6 ) ;
} else {
V_4 -> V_67 = 1 ;
}
F_9 ( V_97 , V_16 ) ;
F_9 ( 0x2 , V_105 ) ;
if ( F_35 () ) {
F_9 ( 0x0 , V_106 ) ;
F_9 ( 0x0 , V_107 ) ;
F_9 ( 0x0 , V_108 ) ;
F_9 ( 0x0 , V_109 ) ;
F_9 ( 0xffff , V_110 ) ;
F_9 ( 0xffff , V_111 ) ;
F_9 ( 0xffff , V_112 ) ;
F_9 ( 0xffff , V_113 ) ;
} else if ( F_26 () ) {
F_9 ( 0x0 , V_114 ) ;
F_9 ( 0xffff , V_115 ) ;
} else
F_53 () ;
F_9 ( 0x4 , V_116 ) ;
}
static void F_54 ( struct V_34 * V_35 )
{
struct V_37 * V_82 = V_35 -> V_38 ;
struct V_3 * V_4 = V_82 -> V_38 ;
T_2 V_117 , V_118 ;
int V_41 , V_119 ;
F_5 ( F_55 ( 0 ) , V_39 ) ;
F_5 ( V_120 , V_11 ) ;
F_5 ( V_121 | V_122 ,
V_123 ) ;
for ( V_41 = 0 ; V_41 < V_124 ; V_41 ++ )
F_5 ( 0x0 | ( 0xffff << 16 ) ,
V_125 + ( V_41 << 2 ) ) ;
F_5 ( 0 , V_11 ) ;
V_117 = V_126 |
V_127 |
F_56 ( V_35 -> V_80 >> 1 ) |
F_57 ( 0x70 ) |
V_19 |
V_128 ;
if ( V_82 -> V_98 . V_56 == V_99 )
V_117 |= V_129 ;
V_119 = F_58 ( V_82 -> V_130 ) >> 3 ;
if ( V_35 -> V_42 == 2048 ) {
V_117 |= V_131 ;
V_117 |= F_59 ( V_119 ) ;
} else if ( V_35 -> V_42 == 4096 ) {
V_117 |= V_132 ;
V_117 |= F_59 ( V_119 ) ;
} else {
V_117 |= V_133 ;
V_117 |= F_59 ( V_119 - 1 ) ;
}
if ( V_35 -> V_42 ) {
V_117 |= F_60 ( F_52 ( V_35 -> V_103 / V_35 -> V_42 ) - 6 ) ;
V_4 -> V_67 = F_49 ( V_35 ) ;
if ( V_4 -> V_67 == 8 )
V_117 |= V_134 ;
}
F_5 ( V_117 , V_18 ) ;
V_118 = F_61 ( 0 ) |
V_135 |
V_136 |
F_62 ( 6 ) |
F_63 ( 0 ) ;
if ( ! ( V_82 -> V_50 & V_51 ) )
V_118 |= V_137 ;
F_5 ( V_118 , V_138 ) ;
F_5 ( 0 , V_139 ) ;
}
static void F_64 ( struct V_34 * V_35 , unsigned V_140 ,
int V_92 , int V_93 )
{
struct V_37 * V_37 = V_35 -> V_38 ;
struct V_3 * V_4 = V_37 -> V_38 ;
F_19 ( L_8 ,
V_140 , V_92 , V_93 ) ;
V_4 -> V_73 = false ;
switch ( V_140 ) {
case V_28 :
V_4 -> V_141 ( V_35 ) ;
V_4 -> V_142 ( V_4 , V_140 , false ) ;
break;
case V_143 :
V_4 -> V_75 = 0 ;
V_4 -> V_73 = true ;
V_4 -> V_142 ( V_4 , V_140 , true ) ;
F_48 ( V_35 , V_92 , V_93 ) ;
break;
case V_144 :
case V_145 :
if ( V_140 == V_144 )
V_4 -> V_75 = V_92 ;
else
V_4 -> V_75 = V_92 + V_35 -> V_42 ;
V_140 = V_144 ;
V_4 -> V_142 ( V_4 , V_140 , false ) ;
F_48 ( V_35 , V_92 , V_93 ) ;
if ( V_35 -> V_42 > 512 )
V_4 -> V_142 ( V_4 , V_146 , true ) ;
V_4 -> V_147 ( V_35 , V_148 ) ;
memcpy ( V_4 -> V_46 , V_4 -> V_47 , V_35 -> V_42 ) ;
F_47 ( V_35 , true ) ;
break;
case V_149 :
if ( V_92 >= V_35 -> V_42 )
F_64 ( V_35 , V_144 , 0 , V_93 ) ;
V_4 -> V_75 = V_92 ;
V_4 -> V_142 ( V_4 , V_140 , false ) ;
F_48 ( V_35 , V_92 , V_93 ) ;
break;
case V_150 :
memcpy ( V_4 -> V_47 , V_4 -> V_46 , V_35 -> V_42 ) ;
F_47 ( V_35 , false ) ;
V_4 -> V_147 ( V_35 , V_151 ) ;
V_4 -> V_142 ( V_4 , V_140 , true ) ;
F_48 ( V_35 , V_92 , V_93 ) ;
break;
case V_152 :
V_4 -> V_142 ( V_4 , V_140 , true ) ;
F_48 ( V_35 , V_92 , V_93 ) ;
V_4 -> V_153 ( V_4 ) ;
V_4 -> V_75 = V_92 ;
break;
case V_154 :
case V_155 :
V_4 -> V_142 ( V_4 , V_140 , false ) ;
F_48 ( V_35 , V_92 , V_93 ) ;
break;
}
}
static int T_10 F_65 ( struct V_156 * V_157 )
{
struct V_37 * V_48 ;
struct V_34 * V_35 ;
struct V_158 * V_159 = V_157 -> V_160 . V_161 ;
struct V_3 * V_4 ;
struct V_162 * V_163 ;
int V_63 = 0 ;
struct V_164 * V_165 , * V_166 ;
V_4 = F_66 ( sizeof( struct V_3 ) + V_167 +
V_168 , V_169 ) ;
if ( ! V_4 )
return - V_170 ;
V_4 -> V_46 = ( T_8 * ) ( V_4 + 1 ) ;
V_4 -> V_160 = & V_157 -> V_160 ;
V_48 = & V_4 -> V_49 ;
V_35 = & V_4 -> V_35 ;
V_35 -> V_38 = V_48 ;
V_35 -> V_171 = V_172 ;
V_35 -> V_160 . V_173 = & V_157 -> V_160 ;
V_35 -> V_174 = V_175 ;
V_48 -> V_176 = 5 ;
V_48 -> V_38 = V_4 ;
V_48 -> V_177 = F_31 ;
V_48 -> V_178 = F_64 ;
V_48 -> V_179 = F_44 ;
V_48 -> V_180 = F_38 ;
V_48 -> V_181 = F_39 ;
V_48 -> V_182 = F_40 ;
V_48 -> V_183 = F_42 ;
V_48 -> V_184 = F_43 ;
V_4 -> V_84 = F_67 ( & V_157 -> V_160 , L_9 ) ;
if ( F_68 ( V_4 -> V_84 ) ) {
V_63 = F_69 ( V_4 -> V_84 ) ;
goto V_185;
}
F_46 ( V_4 -> V_84 ) ;
V_4 -> V_83 = 1 ;
V_163 = F_70 ( V_157 , V_186 , 0 ) ;
if ( ! V_163 ) {
V_63 = - V_187 ;
goto V_188;
}
V_4 -> V_189 = F_71 ( V_163 -> V_190 , F_72 ( V_163 ) ) ;
if ( ! V_4 -> V_189 ) {
V_63 = - V_170 ;
goto V_188;
}
V_4 -> V_47 = V_4 -> V_189 ;
if ( F_26 () || F_35 () ) {
V_4 -> V_141 = F_50 ;
V_4 -> V_142 = F_21 ;
V_4 -> V_94 = F_23 ;
V_4 -> V_147 = F_25 ;
V_4 -> V_153 = F_28 ;
V_4 -> V_74 = F_30 ;
V_4 -> V_5 = F_6 ;
if ( F_8 () )
V_4 -> V_7 = F_10 ;
else
V_4 -> V_7 = F_13 ;
}
if ( F_35 () ) {
V_4 -> V_191 = V_4 -> V_189 + 0x1e00 ;
V_4 -> V_89 = V_4 -> V_189 + 0x1000 ;
V_4 -> V_91 = 64 ;
V_165 = & V_192 ;
V_166 = & V_193 ;
V_48 -> V_98 . V_194 = 9 ;
} else if ( F_26 () ) {
V_4 -> V_191 = V_4 -> V_189 + 0xe00 ;
V_4 -> V_89 = V_4 -> V_189 + 0x800 ;
V_4 -> V_91 = 16 ;
V_165 = & V_195 ;
V_166 = & V_196 ;
V_48 -> V_98 . V_194 = 3 ;
V_4 -> V_67 = 1 ;
} else if ( F_73 () ) {
V_163 = F_70 ( V_157 , V_186 , 1 ) ;
if ( ! V_163 ) {
V_63 = - V_187 ;
goto V_197;
}
V_4 -> V_198 = F_71 ( V_163 -> V_190 , F_72 ( V_163 ) ) ;
if ( ! V_4 -> V_198 ) {
V_63 = - V_170 ;
goto V_197;
}
V_4 -> V_199 = V_4 -> V_189 + 0x1e00 ;
V_4 -> V_89 = V_4 -> V_189 + 0x1000 ;
V_4 -> V_91 = 64 ;
V_4 -> V_141 = F_54 ;
V_4 -> V_142 = F_20 ;
V_4 -> V_94 = F_22 ;
V_4 -> V_147 = F_24 ;
V_4 -> V_153 = F_27 ;
V_4 -> V_5 = F_3 ;
V_4 -> V_74 = F_29 ;
V_4 -> V_7 = F_14 ;
V_165 = & V_192 ;
V_166 = & V_193 ;
} else
F_53 () ;
V_48 -> V_98 . V_95 = 512 ;
V_48 -> V_98 . V_200 = V_165 ;
if ( V_159 -> V_201 ) {
V_48 -> V_98 . V_202 = F_37 ;
V_48 -> V_98 . V_203 = F_32 ;
if ( F_26 () )
V_48 -> V_98 . V_204 = F_33 ;
else
V_48 -> V_98 . V_204 = F_34 ;
V_48 -> V_98 . V_56 = V_99 ;
} else {
V_48 -> V_98 . V_56 = V_205 ;
}
if ( V_159 -> V_206 == 2 )
V_48 -> V_50 |= V_51 ;
if ( V_159 -> V_207 ) {
V_48 -> V_208 = & V_209 ;
V_48 -> V_210 = & V_211 ;
V_48 -> V_212 |= V_213 ;
}
F_74 ( & V_4 -> V_8 ) ;
V_4 -> V_1 = F_75 ( V_157 , 0 ) ;
if ( F_8 () )
F_13 ( V_4 , 0 ) ;
else
V_4 -> V_7 ( V_4 , 0 ) ;
V_63 = F_76 ( V_4 -> V_1 , F_1 , V_214 , V_175 , V_4 ) ;
if ( V_63 )
goto V_197;
V_4 -> V_7 ( V_4 , 0 ) ;
if ( F_8 () )
F_13 ( V_4 , 1 ) ;
if ( F_77 ( V_35 , F_35 () ? 4 : 1 , NULL ) ) {
V_63 = - V_215 ;
goto V_216;
}
V_4 -> V_141 ( V_35 ) ;
if ( V_35 -> V_42 == 2048 )
V_48 -> V_98 . V_200 = V_166 ;
if ( F_35 () && V_35 -> V_42 == 4096 )
V_48 -> V_98 . V_200 = & V_217 ;
if ( F_78 ( V_35 ) ) {
V_63 = - V_215 ;
goto V_216;
}
F_79 ( V_35 , V_218 , 0 ,
V_159 -> V_219 , V_159 -> V_220 ) ;
F_80 ( V_157 , V_4 ) ;
return 0 ;
V_216:
F_81 ( V_4 -> V_1 , V_4 ) ;
V_197:
if ( V_4 -> V_198 )
F_82 ( V_4 -> V_198 ) ;
F_82 ( V_4 -> V_189 ) ;
V_188:
F_83 ( V_4 -> V_84 ) ;
V_185:
F_84 ( V_4 ) ;
return V_63 ;
}
static int T_11 F_85 ( struct V_156 * V_157 )
{
struct V_3 * V_4 = F_86 ( V_157 ) ;
F_83 ( V_4 -> V_84 ) ;
F_80 ( V_157 , NULL ) ;
F_87 ( & V_4 -> V_35 ) ;
F_81 ( V_4 -> V_1 , V_4 ) ;
if ( V_4 -> V_198 )
F_82 ( V_4 -> V_198 ) ;
F_82 ( V_4 -> V_189 ) ;
F_84 ( V_4 ) ;
return 0 ;
}
static int T_10 F_88 ( void )
{
return F_89 ( & V_221 , F_65 ) ;
}
static void T_12 F_90 ( void )
{
F_91 ( & V_221 ) ;
}

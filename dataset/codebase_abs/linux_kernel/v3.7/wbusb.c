static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 ;
if ( V_2 -> V_5 )
return;
V_2 -> V_6 = V_3 ;
V_4 = V_2 -> V_6 << 16 ;
V_4 |= V_2 -> V_7 ;
F_2 ( V_2 , 0x0848 , V_4 ) ;
}
static int F_3 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_9 -> V_13 ;
F_1 ( & V_13 -> V_14 , V_11 -> V_15 . V_16 ) ;
return 0 ;
}
static void F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
F_5 ( L_1 ) ;
}
static void F_6 ( struct V_8 * V_17 )
{
F_5 ( V_18 L_2 , V_19 ) ;
}
static int F_7 ( struct V_8 * V_17 ,
struct V_20 * V_21 )
{
F_5 ( V_18 L_2 , V_19 ) ;
return 0 ;
}
static T_3 F_8 ( struct V_8 * V_17 ,
struct V_22 * V_23 )
{
return F_9 ( V_23 ) ;
}
static void F_10 ( struct V_8 * V_9 ,
unsigned int V_24 ,
unsigned int * V_25 ,
T_3 V_26 )
{
unsigned int V_27 ;
V_27 = 0 ;
if ( * V_25 & V_28 )
V_27 |= V_28 ;
else if ( ( * V_25 & V_29 ) || ( V_26 > 32 ) )
V_27 |= V_29 ;
V_9 -> V_30 &= ~ V_31 ;
* V_25 = V_27 ;
}
static void F_11 ( struct V_8 * V_9 ,
struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_12 * V_13 = V_9 -> V_13 ;
if ( V_13 -> V_36 . V_37 != V_38 ) {
V_13 -> V_36 . V_39 ++ ;
F_12 ( V_35 ) ;
return;
}
V_13 -> V_36 . V_37 = V_40 ;
V_13 -> V_36 . V_41 = V_35 -> V_42 ;
V_13 -> V_36 . V_43 = V_44 ;
V_13 -> V_36 . V_45 = V_35 -> V_45 ;
V_13 -> V_36 . V_46 ++ ;
F_13 ( V_13 ) ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_13 ;
V_13 -> V_47 = true ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , unsigned char V_48 )
{
struct V_49 * V_50 = & V_2 -> V_50 ;
if ( V_2 -> V_5 )
return;
if ( V_48 ) {
V_2 -> V_51 = 1 ;
V_50 -> V_52 &= 0xffffffbf ;
} else {
V_2 -> V_51 = 0 ;
V_50 -> V_52 |= 0x00000040 ;
}
F_2 ( V_2 , 0x0824 , V_50 -> V_52 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_53 V_54 )
{
struct V_49 * V_50 = & V_2 -> V_50 ;
if ( V_2 -> V_5 )
return;
F_5 ( L_3 , V_54 . V_55 , V_54 . V_56 ) ;
F_17 ( V_2 , V_54 ) ;
V_2 -> V_57 = V_54 . V_56 ;
V_2 -> V_55 = V_54 . V_55 ;
F_18 ( L_4 , V_2 -> V_57 , V_2 -> V_55 ) ;
V_50 -> V_58 &= ~ 0xff ;
V_50 -> V_58 |= V_54 . V_56 ;
F_19 ( V_2 , 0x0828 , V_50 -> V_58 ,
( V_59 * ) & V_54 ,
sizeof( struct V_53 ) ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_53 V_54 )
{
F_16 ( V_2 , V_54 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_4 V_60 )
{
struct V_49 * V_50 = & V_2 -> V_50 ;
if ( V_2 -> V_5 )
return;
V_50 -> V_61 &= ~ 0x02000000 ;
if ( V_60 )
V_50 -> V_61 |= 0x02000000 ;
F_2 ( V_2 , 0x0800 , V_50 -> V_61 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_4 V_60 )
{
struct V_49 * V_50 = & V_2 -> V_50 ;
if ( V_2 -> V_5 )
return;
if ( V_60 ) {
V_50 -> V_61 |= 0x00400000 ;
F_2 ( V_2 , 0x0800 , V_50 -> V_61 ) ;
} else {
V_50 -> V_61 &= ~ 0x00400000 ;
F_2 ( V_2 , 0x0800 , V_50 -> V_61 ) ;
}
}
static void F_23 ( struct V_1 * V_2 , T_4 V_60 )
{
struct V_49 * V_50 = & V_2 -> V_50 ;
if ( V_2 -> V_5 )
return;
V_50 -> V_61 &= ~ 0x01000000 ;
if ( V_60 )
V_50 -> V_61 |= 0x01000000 ;
F_2 ( V_2 , 0x0800 , V_50 -> V_61 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_4 V_60 )
{
struct V_49 * V_50 = & V_2 -> V_50 ;
if ( V_2 -> V_5 )
return;
if ( ! V_60 )
return;
V_50 -> V_61 &= ~ 0x04000000 ;
if ( V_60 )
V_50 -> V_61 |= 0x04000000 ;
F_2 ( V_2 , 0x0800 , V_50 -> V_61 ) ;
}
static int F_25 ( struct V_8 * V_9 , T_2 V_62 )
{
struct V_12 * V_13 = V_9 -> V_13 ;
struct V_53 V_63 ;
F_5 ( L_5 ) ;
V_63 . V_55 = 1 ;
V_63 . V_56 = 1 ;
F_20 ( & V_13 -> V_14 , V_63 ) ;
F_21 ( & V_13 -> V_14 , 1 ) ;
F_22 ( & V_13 -> V_14 , 1 ) ;
F_23 ( & V_13 -> V_14 , 1 ) ;
F_24 ( & V_13 -> V_14 , 1 ) ;
F_15 ( & V_13 -> V_14 , 0 ) ;
return 0 ;
}
static T_3 F_26 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
F_5 ( L_6 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 , T_4 * V_64 )
{
T_2 V_65 [ 2 ] ;
if ( V_2 -> V_5 )
return;
memcpy ( V_2 -> V_66 , V_64 , V_67 ) ;
V_65 [ 0 ] = F_28 ( * ( T_2 * ) V_2 -> V_66 ) ;
V_65 [ 1 ] = F_28 ( * ( T_2 * ) ( V_2 -> V_66 + 4 ) ) & 0xffff ;
F_29 ( V_2 , 0x03e8 , V_65 , 2 , V_68 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_4 * V_69 )
{
if ( V_2 -> V_5 )
return;
memcpy ( V_69 , V_2 -> V_70 , 6 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = & V_2 -> V_50 ;
V_2 -> V_71 . V_72 = 1 ;
F_32 ( V_2 ) ;
V_2 -> V_73 . V_74 = 1 ;
F_33 ( V_2 ) ;
V_50 -> V_75 &= ~ 0xc0000000 ;
F_2 ( V_2 , 0x0400 , V_50 -> V_75 ) ;
}
static unsigned char F_34 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = & V_2 -> V_50 ;
if ( ! V_2 -> V_5 && V_50 -> V_76 != V_77 )
return false ;
return true ;
}
T_4 F_35 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = & V_2 -> V_50 ;
if ( ( V_50 -> V_78 & F_36 ( 11 ) ) == 0 )
return 0 ;
else
return 1 ;
}
static T_4 F_37 ( struct V_1 * V_2 )
{
struct V_49 * V_50 = & V_2 -> V_50 ;
if ( V_2 -> V_5 )
return 1 ;
F_38 ( V_2 , 0x3b0 , & V_50 -> V_79 ) ;
if ( ( V_50 -> V_79 & 0x00010000 ) ) {
V_2 -> V_80 = 1 ;
return 1 ;
} else {
V_2 -> V_80 = 0 ;
return 0 ;
}
}
static void F_39 ( unsigned long V_42 )
{
struct V_12 * V_81 = (struct V_12 * ) V_42 ;
struct V_1 * V_2 = & V_81 -> V_14 ;
struct V_49 * V_50 = & V_2 -> V_50 ;
T_2 V_82 = ( V_2 -> V_83 & V_84 ) >> V_85 ;
T_2 V_86 = 500 , V_65 , V_87 ;
V_65 = 0 ;
if ( V_2 -> V_5 )
return;
if ( V_2 -> V_88 ) {
V_87 = V_2 -> V_88 & 0xff ;
if ( V_87 == 5 ) {
V_86 = 100 ;
V_87 = ( V_2 -> V_88 >> 8 ) & 0xff ;
switch ( V_87 ) {
case 1 :
V_2 -> V_89 %= 3 ;
V_65 = 0x1010 ;
if ( V_2 -> V_89 == 2 )
V_65 = 0 ;
break;
case 2 :
V_2 -> V_89 %= 2 ;
V_65 = 0x0010 ;
if ( V_2 -> V_89 )
V_65 = 0 ;
break;
case 3 :
V_2 -> V_89 %= 15 ;
V_65 = 0x0010 ;
if ( ( V_2 -> V_89 >= 9 ) || ( V_2 -> V_89 % 2 ) )
V_65 = 0 ;
break;
case 4 :
V_65 = 0x1000 ;
if ( V_2 -> V_89 >= 3000 )
V_65 = 0 ;
break;
}
V_2 -> V_89 ++ ;
V_50 -> V_90 = V_65 ;
if ( V_82 != 7 ) {
V_50 -> V_90 |= ( V_65 & 0xff ) << 8 ;
V_50 -> V_90 |= ( V_65 & 0xff00 ) >> 8 ;
}
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
}
} else if ( V_2 -> V_51 || V_2 -> V_80 ) {
if ( V_50 -> V_90 & 0x1010 ) {
V_50 -> V_90 &= ~ 0x1010 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
}
} else {
switch ( V_82 ) {
case 4 :
if ( ! V_2 -> V_91 ) {
if ( V_2 -> V_92 ) {
if ( V_2 -> V_89 == 0 ) {
V_50 -> V_90 |= 0x10 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
V_2 -> V_89 = 1 ;
V_86 = 300 ;
} else {
V_50 -> V_90 &= ~ 0x10 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
V_2 -> V_89 = 0 ;
V_86 = 300 ;
}
} else {
if ( V_50 -> V_90 & 0x10 ) {
V_50 -> V_90 &= ~ 0x10 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
}
}
} else {
if ( ( V_50 -> V_90 & 0x10 ) == 0 ) {
V_50 -> V_90 |= 0x10 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
}
}
break;
case 6 :
if ( ! V_2 -> V_91 ) {
if ( V_2 -> V_92 ) {
if ( V_2 -> V_89 == 0 ) {
V_50 -> V_90 &= ~ 0xf ;
V_50 -> V_90 |= 0x10 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
V_2 -> V_89 = 1 ;
V_86 = 300 ;
} else {
V_50 -> V_90 &= ~ 0x1f ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
V_2 -> V_89 = 0 ;
V_86 = 300 ;
}
} else {
V_65 = V_50 -> V_90 ;
V_50 -> V_90 &= ~ 0x1f ;
if ( V_93 [ ( V_2 -> V_89 % 30 ) ] ) {
V_50 -> V_90 |= 0x10 ;
V_50 -> V_90 |=
V_93 [ ( V_2 -> V_89 % 30 ) ] ;
}
V_2 -> V_89 ++ ;
if ( V_50 -> V_90 != V_65 )
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
V_86 = 100 ;
}
} else {
if ( ( V_50 -> V_90 & 0x10 ) == 0 ) {
V_50 -> V_90 |= 0x10 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
}
}
break;
case 5 :
if ( ! V_2 -> V_91 ) {
if ( V_2 -> V_92 ) {
if ( V_2 -> V_89 == 0 ) {
V_50 -> V_90 |= 0x1000 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
V_2 -> V_89 = 1 ;
V_86 = 300 ;
} else {
V_50 -> V_90 &= ~ 0x1000 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
V_2 -> V_89 = 0 ;
V_86 = 300 ;
}
} else {
if ( V_50 -> V_90 & 0x1000 ) {
V_50 -> V_90 &= ~ 0x1000 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
}
}
} else {
if ( ( V_81 -> V_94 !=
V_2 -> V_95 )
|| ( V_81 -> V_96 !=
V_2 -> V_97 ) ) {
if ( ( V_50 -> V_90 & 0x3000 ) !=
0x3000 ) {
V_50 -> V_90 |= 0x3000 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
}
V_2 -> V_95 =
V_81 -> V_94 ;
V_2 -> V_97 =
V_81 -> V_96 ;
V_86 = 200 ;
} else {
if ( ( V_50 -> V_90 & 0x3000 ) !=
0x1000 ) {
V_50 -> V_90 &=
~ 0x3000 ;
V_50 -> V_90 |=
0x1000 ;
F_2 ( V_2 , 0x03bc , V_50 -> V_90 ) ;
}
}
}
break;
default:
if ( ( V_50 -> V_90 & 0x3000 ) != 0x3000 ) {
V_50 -> V_90 |= 0x3000 ;
F_2 ( V_2 , 0x03bc ,
V_50 -> V_90 ) ;
}
if ( V_2 -> V_89 ) {
V_50 -> V_90 &= ~ 0x0f ;
V_50 -> V_90 |= 0x10 ;
V_50 -> V_90 |=
V_98 [ ( V_2 -> V_89 - 1 ) % 20 ] ;
F_2 ( V_2 , 0x03bc ,
V_50 -> V_90 ) ;
V_2 -> V_89 += 2 ;
if ( V_2 -> V_89 < 40 )
V_86 = 100 ;
else {
V_2 -> V_89 = 0 ;
V_50 -> V_90 &= ~ 0x0f ;
F_2 ( V_2 , 0x03bc ,
V_50 -> V_90 ) ;
}
break;
}
if ( V_2 -> V_91 ) {
if ( ! ( V_50 -> V_90 & 0x10 ) ) {
V_50 -> V_90 |= 0x10 ;
V_2 -> V_89 = 1 ;
V_86 = 50 ;
}
} else {
if ( V_50 -> V_90 & 0x10 ) {
V_50 -> V_90 &= ~ 0x10 ;
F_2 ( V_2 , 0x03bc ,
V_50 -> V_90 ) ;
}
}
break;
}
}
V_2 -> V_99 += V_86 ;
F_40 ( V_81 , V_2 -> V_99 ) ;
V_2 -> V_100 . V_101 = V_102 + F_41 ( V_86 ) ;
F_42 ( & V_2 -> V_100 ) ;
}
static int F_43 ( struct V_8 * V_17 )
{
struct V_12 * V_13 = V_17 -> V_13 ;
struct V_1 * V_2 = & V_13 -> V_14 ;
T_1 V_83 ;
V_2 -> V_103 = V_104 ;
V_2 -> V_105 = V_106 ;
if ( ! F_44 ( V_2 ) )
goto V_107;
if ( ! F_45 ( V_2 ) )
goto V_108;
if ( ! F_46 ( V_2 ) )
goto V_109;
F_47 ( & V_2 -> V_100 ) ;
V_2 -> V_100 . V_110 = F_39 ;
V_2 -> V_100 . V_42 = ( unsigned long ) V_13 ;
V_2 -> V_100 . V_101 = V_102 + F_41 ( 1000 ) ;
F_42 ( & V_2 -> V_100 ) ;
V_83 = F_48 ( V_2 ) ;
F_49 ( V_17 ) ;
F_50 ( V_13 ) ;
return 0 ;
V_109:
F_51 ( V_2 ) ;
V_108:
F_52 ( V_2 ) ;
V_107:
F_53 ( V_2 ) ;
V_2 -> V_5 = 1 ;
return - V_111 ;
}
static int F_54 ( struct V_8 * V_17 )
{
struct V_12 * V_13 = V_17 -> V_13 ;
struct V_1 * V_2 = & V_13 -> V_14 ;
T_4 V_112 ;
T_4 V_113 ;
T_4 * V_114 ;
T_4 * V_115 ;
int V_116 ;
V_2 -> V_117 = V_118 ;
V_13 -> V_119 . V_120 = V_121 ;
V_13 -> V_119 . V_122 = V_106 ;
V_13 -> V_123 . V_124 = V_125 ;
V_13 -> V_123 . V_126 = V_127 ;
V_13 -> V_123 . V_128 = V_129 ;
V_13 -> V_123 . V_130 = V_131 ;
V_13 -> V_123 . V_132 = V_133 ;
V_13 -> V_123 . V_134 = false ;
V_13 -> V_123 . V_135 = false ;
V_13 -> V_123 . V_136 = 2 * 100 ;
V_13 -> V_123 . V_137 . V_138 = false ;
V_116 = F_43 ( V_17 ) ;
if ( V_116 )
goto error;
V_112 = F_55 ( V_2 ) ;
if ( V_112 != V_125 )
V_13 -> V_123 . V_139 = V_112 ;
else {
if ( V_13 -> V_123 . V_124 != V_125 )
V_13 -> V_123 . V_139 = V_13 -> V_123 . V_124 ;
else
V_13 -> V_123 . V_139 = V_140 ;
}
F_56 ( V_13 ) ;
V_115 = V_13 -> V_123 . V_141 ;
V_114 = V_13 -> V_123 . V_142 ;
F_30 ( V_2 , V_13 -> V_123 . V_142 ) ;
if ( memcmp ( V_115 , L_7 , V_143 ) == 0 )
memcpy ( V_115 , V_114 , V_143 ) ;
else {
F_27 ( V_2 ,
V_13 -> V_123 . V_141 ) ;
}
V_13 -> V_123 . V_144 = F_35 ( V_2 ) ;
F_18 ( L_8 , V_13 -> V_123 . V_144 ) ;
F_37 ( V_2 ) ;
while ( ! F_34 ( V_2 ) )
F_57 ( 10 ) ;
F_58 ( V_13 ) ;
V_113 = F_37 ( V_2 ) ;
V_13 -> V_123 . V_137 . V_145 = ! ! V_113 ;
F_15 ( V_2 ,
( unsigned char ) ( V_13 -> V_123 . V_137 .
V_138
|| V_13 -> V_123 . V_137 .
V_145 ) ) ;
F_59 ( V_2 ) = 1 ;
error:
return V_116 ;
}
static int F_60 ( struct V_146 * V_147 ,
const struct V_148 * V_149 )
{
struct V_150 * V_151 = F_61 ( V_147 ) ;
struct V_152 * V_153 ;
struct V_154 * V_155 ;
struct V_8 * V_9 ;
struct V_12 * V_13 ;
int V_116 ;
T_2 V_65 ;
F_62 ( V_151 ) ;
V_116 = F_63 ( V_151 , F_64 ( V_151 , 0 ) ,
0x01 ,
V_156 | V_157 | V_158 ,
0x0 , 0x400 , & V_65 , 4 , V_159 * 100 ) ;
if ( V_116 < 0 )
goto error;
V_65 = F_28 ( V_65 ) ;
if ( V_65 ) {
V_116 = - V_160 ;
goto error;
}
V_9 = F_65 ( sizeof( * V_13 ) , & V_161 ) ;
if ( ! V_9 ) {
V_116 = - V_162 ;
goto error;
}
V_13 = V_9 -> V_13 ;
V_13 -> V_14 . V_151 = V_151 ;
V_155 = V_147 -> V_163 ;
V_153 = & V_155 -> V_153 [ 0 ] . V_164 ;
if ( V_153 [ 2 ] . V_165 == 512 )
F_5 ( L_9 ) ;
V_116 = F_54 ( V_9 ) ;
if ( V_116 )
goto V_166;
F_66 ( V_9 , & V_151 -> V_9 ) ;
{
struct V_1 * V_2 = & V_13 -> V_14 ;
unsigned char V_167 [ V_168 ] ;
F_30 ( V_2 , V_167 ) ;
F_67 ( V_9 , V_167 ) ;
}
V_9 -> V_169 = 12 ;
V_9 -> V_30 = V_170 ;
V_9 -> V_171 -> V_172 = F_36 ( V_173 ) ;
V_9 -> V_174 = 1000 ;
V_9 -> V_175 = 100 ;
V_9 -> V_176 = 1 ;
V_9 -> V_171 -> V_177 [ V_178 ] = & V_179 ;
V_116 = F_68 ( V_9 ) ;
if ( V_116 )
goto V_166;
F_69 ( V_147 , V_9 ) ;
return 0 ;
V_166:
F_70 ( V_9 ) ;
error:
F_71 ( V_151 ) ;
return V_116 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_73 ( & V_2 -> V_100 ) ;
F_57 ( 100 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static void F_74 ( struct V_12 * V_81 )
{
F_31 ( & V_81 -> V_14 ) ;
F_18 ( L_10 ) ;
F_57 ( 100 ) ;
F_72 ( & V_81 -> V_14 ) ;
}
static void F_75 ( struct V_146 * V_147 )
{
struct V_8 * V_17 = F_76 ( V_147 ) ;
struct V_12 * V_13 = V_17 -> V_13 ;
F_74 ( V_13 ) ;
F_77 ( V_17 ) ;
F_78 ( V_17 ) ;
F_70 ( V_17 ) ;
F_69 ( V_147 , NULL ) ;
F_71 ( F_61 ( V_147 ) ) ;
}

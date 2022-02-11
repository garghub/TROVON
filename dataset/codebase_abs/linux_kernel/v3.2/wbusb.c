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
static void F_11 ( struct V_8 * V_9 , struct V_32 * V_33 )
{
struct V_12 * V_13 = V_9 -> V_13 ;
if ( V_13 -> V_34 . V_35 != V_36 ) {
V_13 -> V_34 . V_37 ++ ;
F_12 ( V_33 ) ;
return;
}
V_13 -> V_34 . V_35 = V_38 ;
V_13 -> V_34 . V_39 = V_33 -> V_40 ;
V_13 -> V_34 . V_41 = V_42 ;
V_13 -> V_34 . V_43 = V_33 -> V_43 ;
V_13 -> V_34 . V_44 ++ ;
F_13 ( V_13 ) ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = V_9 -> V_13 ;
V_13 -> V_45 = true ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 , unsigned char V_46 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
if ( V_2 -> V_5 )
return;
if ( V_46 ) {
V_2 -> V_49 = 1 ;
V_48 -> V_50 &= 0xffffffbf ;
} else {
V_2 -> V_49 = 0 ;
V_48 -> V_50 |= 0x00000040 ;
}
F_2 ( V_2 , 0x0824 , V_48 -> V_50 ) ;
}
static void F_16 ( struct V_1 * V_2 , struct V_51 V_52 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
if ( V_2 -> V_5 )
return;
F_5 ( L_3 , V_52 . V_53 , V_52 . V_54 ) ;
F_17 ( V_2 , V_52 ) ;
V_2 -> V_55 = V_52 . V_54 ;
V_2 -> V_53 = V_52 . V_53 ;
F_18 ( L_4 , V_2 -> V_55 , V_2 -> V_53 ) ;
V_48 -> V_56 &= ~ 0xff ;
V_48 -> V_56 |= V_52 . V_54 ;
F_19 ( V_2 , 0x0828 , V_48 -> V_56 ,
( V_57 * ) & V_52 ,
sizeof( struct V_51 ) ) ;
}
static void F_20 ( struct V_1 * V_2 , struct V_51 V_52 )
{
F_16 ( V_2 , V_52 ) ;
}
static void F_21 ( struct V_1 * V_2 , T_4 V_58 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
if ( V_2 -> V_5 )
return;
V_48 -> V_59 &= ~ 0x02000000 ;
if ( V_58 )
V_48 -> V_59 |= 0x02000000 ;
F_2 ( V_2 , 0x0800 , V_48 -> V_59 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_4 V_58 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
if ( V_2 -> V_5 )
return;
if ( V_58 ) {
V_48 -> V_59 |= 0x00400000 ;
F_2 ( V_2 , 0x0800 , V_48 -> V_59 ) ;
} else {
V_48 -> V_59 &= ~ 0x00400000 ;
F_2 ( V_2 , 0x0800 , V_48 -> V_59 ) ;
}
}
static void F_23 ( struct V_1 * V_2 , T_4 V_58 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
if ( V_2 -> V_5 )
return;
V_48 -> V_59 &= ~ 0x01000000 ;
if ( V_58 )
V_48 -> V_59 |= 0x01000000 ;
F_2 ( V_2 , 0x0800 , V_48 -> V_59 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_4 V_58 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
if ( V_2 -> V_5 )
return;
if ( ! V_58 )
return;
V_48 -> V_59 &= ~ 0x04000000 ;
if ( V_58 )
V_48 -> V_59 |= 0x04000000 ;
F_2 ( V_2 , 0x0800 , V_48 -> V_59 ) ;
}
static int F_25 ( struct V_8 * V_9 , T_2 V_60 )
{
struct V_12 * V_13 = V_9 -> V_13 ;
struct V_51 V_61 ;
F_5 ( L_5 ) ;
V_61 . V_53 = 1 ;
V_61 . V_54 = 1 ;
F_20 ( & V_13 -> V_14 , V_61 ) ;
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
static void F_27 ( struct V_1 * V_2 , T_4 * V_62 )
{
T_2 V_63 [ 2 ] ;
if ( V_2 -> V_5 )
return;
memcpy ( V_2 -> V_64 , V_62 , V_65 ) ;
V_63 [ 0 ] = F_28 ( * ( T_2 * ) V_2 -> V_64 ) ;
V_63 [ 1 ] = F_28 ( * ( T_2 * ) ( V_2 -> V_64 + 4 ) ) & 0xffff ;
F_29 ( V_2 , 0x03e8 , V_63 , 2 , V_66 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_4 * V_67 )
{
if ( V_2 -> V_5 )
return;
memcpy ( V_67 , V_2 -> V_68 , 6 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
V_2 -> V_69 . V_70 = 1 ;
F_32 ( V_2 ) ;
V_2 -> V_71 . V_72 = 1 ;
F_33 ( V_2 ) ;
V_48 -> V_73 &= ~ 0xc0000000 ;
F_2 ( V_2 , 0x0400 , V_48 -> V_73 ) ;
}
static unsigned char F_34 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
if ( ! V_2 -> V_5 && V_48 -> V_74 != V_75 )
return false ;
return true ;
}
T_4 F_35 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
if ( ( V_48 -> V_76 & F_36 ( 11 ) ) == 0 )
return 0 ;
else
return 1 ;
}
static T_4 F_37 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = & V_2 -> V_48 ;
if ( V_2 -> V_5 )
return 1 ;
F_38 ( V_2 , 0x3b0 , & V_48 -> V_77 ) ;
if ( ( V_48 -> V_77 & 0x00010000 ) ) {
V_2 -> V_78 = 1 ;
return 1 ;
} else {
V_2 -> V_78 = 0 ;
return 0 ;
}
}
static void F_39 ( unsigned long V_40 )
{
struct V_12 * V_79 = (struct V_12 * ) V_40 ;
struct V_1 * V_2 = & V_79 -> V_14 ;
struct V_47 * V_48 = & V_2 -> V_48 ;
T_2 V_80 = ( V_2 -> V_81 & V_82 ) >> V_83 ;
T_2 V_84 = 500 , V_63 , V_85 ;
V_63 = 0 ;
if ( V_2 -> V_5 )
return;
if ( V_2 -> V_86 ) {
V_85 = V_2 -> V_86 & 0xff ;
if ( V_85 == 5 ) {
V_84 = 100 ;
V_85 = ( V_2 -> V_86 >> 8 ) & 0xff ;
switch ( V_85 ) {
case 1 :
V_2 -> V_87 %= 3 ;
V_63 = 0x1010 ;
if ( V_2 -> V_87 == 2 )
V_63 = 0 ;
break;
case 2 :
V_2 -> V_87 %= 2 ;
V_63 = 0x0010 ;
if ( V_2 -> V_87 )
V_63 = 0 ;
break;
case 3 :
V_2 -> V_87 %= 15 ;
V_63 = 0x0010 ;
if ( ( V_2 -> V_87 >= 9 ) || ( V_2 -> V_87 % 2 ) )
V_63 = 0 ;
break;
case 4 :
V_63 = 0x1000 ;
if ( V_2 -> V_87 >= 3000 )
V_63 = 0 ;
break;
}
V_2 -> V_87 ++ ;
V_48 -> V_88 = V_63 ;
if ( V_80 != 7 ) {
V_48 -> V_88 |= ( V_63 & 0xff ) << 8 ;
V_48 -> V_88 |= ( V_63 & 0xff00 ) >> 8 ;
}
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
}
} else if ( V_2 -> V_49 || V_2 -> V_78 ) {
if ( V_48 -> V_88 & 0x1010 ) {
V_48 -> V_88 &= ~ 0x1010 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
}
} else {
switch ( V_80 ) {
case 4 :
if ( ! V_2 -> V_89 ) {
if ( V_2 -> V_90 ) {
if ( V_2 -> V_87 == 0 ) {
V_48 -> V_88 |= 0x10 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
V_2 -> V_87 = 1 ;
V_84 = 300 ;
} else {
V_48 -> V_88 &= ~ 0x10 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
V_2 -> V_87 = 0 ;
V_84 = 300 ;
}
} else {
if ( V_48 -> V_88 & 0x10 ) {
V_48 -> V_88 &= ~ 0x10 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
}
}
} else {
if ( ( V_48 -> V_88 & 0x10 ) == 0 ) {
V_48 -> V_88 |= 0x10 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
}
}
break;
case 6 :
if ( ! V_2 -> V_89 ) {
if ( V_2 -> V_90 ) {
if ( V_2 -> V_87 == 0 ) {
V_48 -> V_88 &= ~ 0xf ;
V_48 -> V_88 |= 0x10 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
V_2 -> V_87 = 1 ;
V_84 = 300 ;
} else {
V_48 -> V_88 &= ~ 0x1f ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
V_2 -> V_87 = 0 ;
V_84 = 300 ;
}
} else {
V_63 = V_48 -> V_88 ;
V_48 -> V_88 &= ~ 0x1f ;
if ( V_91 [ ( V_2 -> V_87 % 30 ) ] ) {
V_48 -> V_88 |= 0x10 ;
V_48 -> V_88 |=
V_91 [ ( V_2 -> V_87 % 30 ) ] ;
}
V_2 -> V_87 ++ ;
if ( V_48 -> V_88 != V_63 )
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
V_84 = 100 ;
}
} else {
if ( ( V_48 -> V_88 & 0x10 ) == 0 ) {
V_48 -> V_88 |= 0x10 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
}
}
break;
case 5 :
if ( ! V_2 -> V_89 ) {
if ( V_2 -> V_90 ) {
if ( V_2 -> V_87 == 0 ) {
V_48 -> V_88 |= 0x1000 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
V_2 -> V_87 = 1 ;
V_84 = 300 ;
} else {
V_48 -> V_88 &= ~ 0x1000 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
V_2 -> V_87 = 0 ;
V_84 = 300 ;
}
} else {
if ( V_48 -> V_88 & 0x1000 ) {
V_48 -> V_88 &= ~ 0x1000 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
}
}
} else {
if ( ( V_79 -> V_92 !=
V_2 -> V_93 )
|| ( V_79 -> V_94 !=
V_2 -> V_95 ) ) {
if ( ( V_48 -> V_88 & 0x3000 ) !=
0x3000 ) {
V_48 -> V_88 |= 0x3000 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
}
V_2 -> V_93 =
V_79 -> V_92 ;
V_2 -> V_95 =
V_79 -> V_94 ;
V_84 = 200 ;
} else {
if ( ( V_48 -> V_88 & 0x3000 ) !=
0x1000 ) {
V_48 -> V_88 &=
~ 0x3000 ;
V_48 -> V_88 |=
0x1000 ;
F_2 ( V_2 , 0x03bc , V_48 -> V_88 ) ;
}
}
}
break;
default:
if ( ( V_48 -> V_88 & 0x3000 ) != 0x3000 ) {
V_48 -> V_88 |= 0x3000 ;
F_2 ( V_2 , 0x03bc ,
V_48 -> V_88 ) ;
}
if ( V_2 -> V_87 ) {
V_48 -> V_88 &= ~ 0x0f ;
V_48 -> V_88 |= 0x10 ;
V_48 -> V_88 |=
V_96 [ ( V_2 -> V_87 - 1 ) % 20 ] ;
F_2 ( V_2 , 0x03bc ,
V_48 -> V_88 ) ;
V_2 -> V_87 += 2 ;
if ( V_2 -> V_87 < 40 )
V_84 = 100 ;
else {
V_2 -> V_87 = 0 ;
V_48 -> V_88 &= ~ 0x0f ;
F_2 ( V_2 , 0x03bc ,
V_48 -> V_88 ) ;
}
break;
}
if ( V_2 -> V_89 ) {
if ( ! ( V_48 -> V_88 & 0x10 ) ) {
V_48 -> V_88 |= 0x10 ;
V_2 -> V_87 = 1 ;
V_84 = 50 ;
}
} else {
if ( V_48 -> V_88 & 0x10 ) {
V_48 -> V_88 &= ~ 0x10 ;
F_2 ( V_2 , 0x03bc ,
V_48 -> V_88 ) ;
}
}
break;
}
}
V_2 -> V_97 += V_84 ;
F_40 ( V_79 , V_2 -> V_97 ) ;
V_2 -> V_98 . V_99 = V_100 + F_41 ( V_84 ) ;
F_42 ( & V_2 -> V_98 ) ;
}
static int F_43 ( struct V_8 * V_17 )
{
struct V_12 * V_13 = V_17 -> V_13 ;
struct V_1 * V_2 = & V_13 -> V_14 ;
T_1 V_81 ;
V_2 -> V_101 = V_102 ;
V_2 -> V_103 = V_104 ;
if ( ! F_44 ( V_2 ) )
goto V_105;
if ( ! F_45 ( V_2 ) )
goto V_106;
if ( ! F_46 ( V_2 ) )
goto V_107;
F_47 ( & V_2 -> V_98 ) ;
V_2 -> V_98 . V_108 = F_39 ;
V_2 -> V_98 . V_40 = ( unsigned long ) V_13 ;
V_2 -> V_98 . V_99 = V_100 + F_41 ( 1000 ) ;
F_42 ( & V_2 -> V_98 ) ;
V_81 = F_48 ( V_2 ) ;
F_49 ( V_17 ) ;
F_50 ( V_13 ) ;
return 0 ;
V_107:
F_51 ( V_2 ) ;
V_106:
F_52 ( V_2 ) ;
V_105:
F_53 ( V_2 ) ;
V_2 -> V_5 = 1 ;
return - V_109 ;
}
static int F_54 ( struct V_8 * V_17 )
{
struct V_12 * V_13 = V_17 -> V_13 ;
struct V_1 * V_2 = & V_13 -> V_14 ;
T_4 V_110 ;
T_4 V_111 ;
T_4 * V_112 ;
T_4 * V_113 ;
int V_114 ;
V_2 -> V_115 = V_116 ;
V_13 -> V_117 . V_118 = V_119 ;
V_13 -> V_117 . V_120 = V_104 ;
V_13 -> V_121 . V_122 = V_123 ;
V_13 -> V_121 . V_124 = V_125 ;
V_13 -> V_121 . V_126 = V_127 ;
V_13 -> V_121 . V_128 = V_129 ;
V_13 -> V_121 . V_130 = V_131 ;
V_13 -> V_121 . V_132 = false ;
V_13 -> V_121 . V_133 = false ;
V_13 -> V_121 . V_134 = 2 * 100 ;
V_13 -> V_121 . V_135 . V_136 = false ;
V_114 = F_43 ( V_17 ) ;
if ( V_114 )
goto error;
V_110 = F_55 ( V_2 ) ;
if ( V_110 != V_123 )
V_13 -> V_121 . V_137 = V_110 ;
else {
if ( V_13 -> V_121 . V_122 != V_123 )
V_13 -> V_121 . V_137 = V_13 -> V_121 . V_122 ;
else
V_13 -> V_121 . V_137 = V_138 ;
}
F_56 ( V_13 ) ;
V_113 = V_13 -> V_121 . V_139 ;
V_112 = V_13 -> V_121 . V_140 ;
F_30 ( V_2 , V_13 -> V_121 . V_140 ) ;
if ( memcmp ( V_113 , L_7 , V_141 ) == 0 )
memcpy ( V_113 , V_112 , V_141 ) ;
else {
F_27 ( V_2 ,
V_13 -> V_121 . V_139 ) ;
}
V_13 -> V_121 . V_142 = F_35 ( V_2 ) ;
F_18 ( L_8 , V_13 -> V_121 . V_142 ) ;
F_37 ( V_2 ) ;
while ( ! F_34 ( V_2 ) )
F_57 ( 10 ) ;
F_58 ( V_13 ) ;
V_111 = F_37 ( V_2 ) ;
V_13 -> V_121 . V_135 . V_143 = ! ! V_111 ;
F_15 ( V_2 ,
( unsigned char ) ( V_13 -> V_121 . V_135 .
V_136
|| V_13 -> V_121 . V_135 .
V_143 ) ) ;
F_59 ( V_2 ) = 1 ;
error:
return V_114 ;
}
static int F_60 ( struct V_144 * V_145 ,
const struct V_146 * V_147 )
{
struct V_148 * V_149 = F_61 ( V_145 ) ;
struct V_150 * V_151 ;
struct V_152 * V_153 ;
struct V_8 * V_9 ;
struct V_12 * V_13 ;
int V_154 , V_114 ;
T_2 V_63 ;
F_62 ( V_149 ) ;
V_154 = F_63 ( V_149 , F_64 ( V_149 , 0 ) ,
0x01 ,
V_155 | V_156 | V_157 ,
0x0 , 0x400 , & V_63 , 4 , V_158 * 100 ) ;
if ( V_154 < 0 ) {
V_114 = V_154 ;
goto error;
}
V_63 = F_28 ( V_63 ) ;
if ( V_63 ) {
V_114 = - V_159 ;
goto error;
}
V_9 = F_65 ( sizeof( * V_13 ) , & V_160 ) ;
if ( ! V_9 ) {
V_114 = - V_161 ;
goto error;
}
V_13 = V_9 -> V_13 ;
V_13 -> V_14 . V_149 = V_149 ;
V_153 = V_145 -> V_162 ;
V_151 = & V_153 -> V_151 [ 0 ] . V_163 ;
if ( V_151 [ 2 ] . V_164 == 512 )
F_5 ( L_9 ) ;
V_114 = F_54 ( V_9 ) ;
if ( V_114 )
goto V_165;
F_66 ( V_9 , & V_149 -> V_9 ) ;
{
struct V_1 * V_2 = & V_13 -> V_14 ;
unsigned char V_166 [ V_167 ] ;
F_30 ( V_2 , V_166 ) ;
F_67 ( V_9 , V_166 ) ;
}
V_9 -> V_168 = 12 ;
V_9 -> V_30 = V_169 ;
V_9 -> V_170 -> V_171 = F_36 ( V_172 ) ;
V_9 -> V_173 = 1000 ;
V_9 -> V_174 = 100 ;
V_9 -> V_175 = 1 ;
V_9 -> V_170 -> V_176 [ V_177 ] = & V_178 ;
V_114 = F_68 ( V_9 ) ;
if ( V_114 )
goto V_165;
F_69 ( V_145 , V_9 ) ;
return 0 ;
V_165:
F_70 ( V_9 ) ;
error:
F_71 ( V_149 ) ;
return V_114 ;
}
static void F_72 ( struct V_1 * V_2 )
{
F_73 ( & V_2 -> V_98 ) ;
F_57 ( 100 ) ;
F_51 ( V_2 ) ;
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static void F_74 ( struct V_12 * V_79 )
{
F_31 ( & V_79 -> V_14 ) ;
F_18 ( L_10 ) ;
F_57 ( 100 ) ;
F_72 ( & V_79 -> V_14 ) ;
}
static void F_75 ( struct V_144 * V_145 )
{
struct V_8 * V_17 = F_76 ( V_145 ) ;
struct V_12 * V_13 = V_17 -> V_13 ;
F_74 ( V_13 ) ;
F_77 ( V_17 ) ;
F_78 ( V_17 ) ;
F_70 ( V_17 ) ;
F_69 ( V_145 , NULL ) ;
F_71 ( F_61 ( V_145 ) ) ;
}
static int T_5 F_79 ( void )
{
return F_80 ( & V_179 ) ;
}
static void T_6 F_81 ( void )
{
F_82 ( & V_179 ) ;
}

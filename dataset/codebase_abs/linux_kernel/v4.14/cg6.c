static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
struct V_5 T_1 * V_6 = V_4 -> V_6 ;
int V_7 = 10000 ;
do {
if ( ! ( F_2 ( & V_6 -> V_8 ) & 0x10000000 ) )
break;
F_3 ( 10 ) ;
} while ( -- V_7 > 0 );
return 0 ;
}
static void F_4 ( struct V_3 * V_4 )
{
struct V_9 T_1 * V_10 = V_4 -> V_10 ;
unsigned long V_11 ;
F_5 ( & V_4 -> V_12 , V_11 ) ;
F_6 ( V_13 , & V_10 -> V_14 ) ;
F_7 ( & V_4 -> V_12 , V_11 ) ;
}
static int F_8 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
F_4 ( V_4 ) ;
if ( V_16 -> V_17 || V_16 -> V_18 || V_16 -> V_19 )
return - V_20 ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 , const struct V_21 * V_22 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
struct V_5 T_1 * V_6 = V_4 -> V_6 ;
unsigned long V_11 ;
T_2 V_23 ;
F_5 ( & V_4 -> V_12 , V_11 ) ;
F_1 ( V_2 ) ;
F_6 ( V_22 -> V_24 , & V_6 -> V_25 ) ;
F_6 ( ~ ( V_26 ) 0 , & V_6 -> V_27 ) ;
F_6 ( 0xea80ff00 , & V_6 -> V_28 ) ;
F_6 ( 0 , & V_6 -> V_8 ) ;
F_6 ( 0 , & V_6 -> V_29 ) ;
F_6 ( ~ ( V_26 ) 0 , & V_6 -> V_30 ) ;
F_6 ( V_22 -> V_31 , & V_6 -> V_32 ) ;
F_6 ( V_22 -> V_33 , & V_6 -> V_34 ) ;
F_6 ( V_22 -> V_31 + V_22 -> V_35 , & V_6 -> V_32 ) ;
F_6 ( V_22 -> V_33 + V_22 -> V_36 , & V_6 -> V_34 ) ;
do {
V_23 = F_2 ( & V_6 -> V_37 ) ;
} while ( V_23 < 0 && ( V_23 & 0x20000000 ) );
F_7 ( & V_4 -> V_12 , V_11 ) ;
}
static void F_10 ( struct V_1 * V_2 , const struct V_38 * V_39 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
struct V_5 T_1 * V_6 = V_4 -> V_6 ;
unsigned long V_11 ;
int V_40 ;
F_5 ( & V_4 -> V_12 , V_11 ) ;
F_1 ( V_2 ) ;
F_6 ( 0xff , & V_6 -> V_25 ) ;
F_6 ( 0x00 , & V_6 -> V_41 ) ;
F_6 ( ~ 0 , & V_6 -> V_27 ) ;
F_6 ( 0xe880cccc , & V_6 -> V_28 ) ;
F_6 ( 0 , & V_6 -> V_8 ) ;
F_6 ( 0 , & V_6 -> V_29 ) ;
F_6 ( V_39 -> V_42 , & V_6 -> y0 ) ;
F_6 ( V_39 -> V_43 , & V_6 -> V_44 ) ;
F_6 ( V_39 -> V_42 + V_39 -> V_35 - 1 , & V_6 -> y1 ) ;
F_6 ( V_39 -> V_43 + V_39 -> V_36 - 1 , & V_6 -> V_45 ) ;
F_6 ( V_39 -> V_31 , & V_6 -> V_46 ) ;
F_6 ( V_39 -> V_33 , & V_6 -> V_47 ) ;
F_6 ( V_39 -> V_31 + V_39 -> V_35 - 1 , & V_6 -> V_48 ) ;
F_6 ( V_39 -> V_33 + V_39 -> V_36 - 1 , & V_6 -> V_49 ) ;
do {
V_40 = F_2 ( & V_6 -> V_50 ) ;
} while ( V_40 < 0 && ( V_40 & 0x20000000 ) );
F_7 ( & V_4 -> V_12 , V_11 ) ;
}
static void F_11 ( struct V_1 * V_2 , const struct V_51 * V_52 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
struct V_5 T_1 * V_6 = V_4 -> V_6 ;
const T_3 * V_53 = V_52 -> V_53 ;
unsigned long V_11 ;
V_26 V_54 , V_55 ;
int V_40 , V_36 ;
if ( V_52 -> V_56 > 1 ) {
F_12 ( V_2 , V_52 ) ;
return;
}
F_5 ( & V_4 -> V_12 , V_11 ) ;
F_1 ( V_2 ) ;
F_6 ( V_52 -> V_57 , & V_6 -> V_25 ) ;
F_6 ( V_52 -> V_58 , & V_6 -> V_41 ) ;
F_6 ( 0x140000 , & V_6 -> V_59 ) ;
F_6 ( 0xe880fc30 , & V_6 -> V_28 ) ;
F_6 ( ~ ( V_26 ) 0 , & V_6 -> V_27 ) ;
F_6 ( 0 , & V_6 -> V_8 ) ;
F_6 ( 0 , & V_6 -> V_29 ) ;
F_6 ( 0xff , & V_6 -> V_30 ) ;
F_6 ( 32 , & V_6 -> V_60 ) ;
F_6 ( 0 , & V_6 -> V_61 ) ;
V_54 = V_52 -> V_33 ;
V_55 = V_52 -> V_31 ;
for ( V_40 = 0 ; V_40 < V_52 -> V_35 ; V_40 ++ ) {
V_36 = V_52 -> V_36 ;
while ( V_36 >= 32 ) {
V_26 V_23 ;
F_6 ( V_55 , & V_6 -> y0 ) ;
F_6 ( V_54 , & V_6 -> V_44 ) ;
F_6 ( V_54 + 32 - 1 , & V_6 -> V_45 ) ;
V_23 = ( ( V_26 ) V_53 [ 0 ] << 24 ) |
( ( V_26 ) V_53 [ 1 ] << 16 ) |
( ( V_26 ) V_53 [ 2 ] << 8 ) |
( ( V_26 ) V_53 [ 3 ] << 0 ) ;
F_6 ( V_23 , & V_6 -> V_62 ) ;
V_53 += 4 ;
V_54 += 32 ;
V_36 -= 32 ;
}
if ( V_36 ) {
V_26 V_23 ;
F_6 ( V_55 , & V_6 -> y0 ) ;
F_6 ( V_54 , & V_6 -> V_44 ) ;
F_6 ( V_54 + V_36 - 1 , & V_6 -> V_45 ) ;
if ( V_36 <= 8 ) {
V_23 = ( V_26 ) V_53 [ 0 ] << 24 ;
V_53 += 1 ;
} else if ( V_36 <= 16 ) {
V_23 = ( ( V_26 ) V_53 [ 0 ] << 24 ) |
( ( V_26 ) V_53 [ 1 ] << 16 ) ;
V_53 += 2 ;
} else {
V_23 = ( ( V_26 ) V_53 [ 0 ] << 24 ) |
( ( V_26 ) V_53 [ 1 ] << 16 ) |
( ( V_26 ) V_53 [ 2 ] << 8 ) ;
V_53 += 3 ;
}
F_6 ( V_23 , & V_6 -> V_62 ) ;
}
V_55 += 1 ;
V_54 = V_52 -> V_33 ;
}
F_7 ( & V_4 -> V_12 , V_11 ) ;
}
static int F_13 ( unsigned V_63 ,
unsigned V_64 , unsigned V_65 , unsigned V_66 ,
unsigned V_67 , struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
struct V_68 T_1 * V_69 = V_4 -> V_69 ;
unsigned long V_11 ;
if ( V_63 >= 256 )
return 1 ;
V_64 >>= 8 ;
V_65 >>= 8 ;
V_66 >>= 8 ;
F_5 ( & V_4 -> V_12 , V_11 ) ;
F_6 ( ( V_26 ) V_63 << 24 , & V_69 -> V_70 ) ;
F_6 ( ( V_26 ) V_64 << 24 , & V_69 -> V_71 ) ;
F_6 ( ( V_26 ) V_65 << 24 , & V_69 -> V_71 ) ;
F_6 ( ( V_26 ) V_66 << 24 , & V_69 -> V_71 ) ;
F_7 ( & V_4 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_14 ( int V_72 , struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
struct V_9 T_1 * V_10 = V_4 -> V_10 ;
unsigned long V_11 ;
V_26 V_23 ;
F_5 ( & V_4 -> V_12 , V_11 ) ;
V_23 = F_2 ( & V_10 -> V_73 ) ;
switch ( V_72 ) {
case V_74 :
V_23 |= V_75 ;
V_4 -> V_11 &= ~ V_76 ;
break;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_23 &= ~ V_75 ;
V_4 -> V_11 |= V_76 ;
break;
}
F_6 ( V_23 , & V_10 -> V_73 ) ;
F_7 ( & V_4 -> V_12 , V_11 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_81 * V_82 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
return F_16 ( V_83 ,
V_2 -> V_84 . V_85 , V_2 -> V_84 . V_86 ,
V_4 -> V_87 , V_82 ) ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_88 , unsigned long V_89 )
{
return F_18 ( V_88 , V_89 , V_2 ,
V_90 , 8 , V_2 -> V_84 . V_86 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_91 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
const char * V_92 , * V_93 ;
V_26 V_94 ;
V_94 = F_2 ( V_4 -> V_95 ) ;
switch ( V_94 & V_96 ) {
case V_97 :
V_92 = L_1 ;
break;
case V_98 :
V_92 = L_2 ;
break;
default:
V_92 = L_3 ;
break;
}
if ( ( ( V_94 >> V_99 ) & V_100 ) >= 11 ) {
if ( V_2 -> V_84 . V_86 <= 0x100000 )
V_93 = L_4 ;
else
V_93 = L_5 ;
} else {
if ( V_2 -> V_84 . V_86 <= 0x100000 )
V_93 = L_6 ;
else
V_93 = L_7 ;
}
sprintf ( V_2 -> V_84 . V_101 , L_8 , V_93 , V_92 ) ;
V_2 -> V_84 . V_101 [ sizeof( V_2 -> V_84 . V_101 ) - 1 ] = 0 ;
V_2 -> V_84 . type = V_102 ;
V_2 -> V_84 . V_103 = V_104 ;
V_2 -> V_84 . V_105 = V_91 ;
V_2 -> V_84 . V_106 = V_107 ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_68 T_1 * V_69 = V_4 -> V_69 ;
F_6 ( 0x04 << 24 , & V_69 -> V_70 ) ;
F_6 ( 0xff << 24 , & V_69 -> V_108 ) ;
F_6 ( 0x05 << 24 , & V_69 -> V_70 ) ;
F_6 ( 0x00 << 24 , & V_69 -> V_108 ) ;
F_6 ( 0x06 << 24 , & V_69 -> V_70 ) ;
F_6 ( 0x73 << 24 , & V_69 -> V_108 ) ;
F_6 ( 0x07 << 24 , & V_69 -> V_70 ) ;
F_6 ( 0x00 << 24 , & V_69 -> V_108 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_4 ;
struct V_109 T_1 * V_110 = V_4 -> V_110 ;
struct V_5 T_1 * V_6 = V_4 -> V_6 ;
struct V_9 T_1 * V_10 = V_4 -> V_10 ;
V_26 V_111 , V_94 , V_59 ;
int V_40 ;
F_6 ( V_13 , & V_10 -> V_14 ) ;
F_6 ( 0 , & V_110 -> V_112 ) ;
F_6 ( 0 , & V_110 -> V_113 ) ;
F_6 ( 0 , & V_110 -> V_114 ) ;
V_111 = ( F_2 ( V_4 -> V_95 ) >> V_99 ) & V_100 ;
if ( V_111 < 5 ) {
V_94 = ( F_2 ( V_4 -> V_95 ) & V_115 ) |
V_98 | V_116 |
( 11 << V_117 ) |
( 11 << V_118 ) ;
if ( V_111 < 2 )
V_94 |= V_119 ;
F_6 ( V_94 , V_4 -> V_95 ) ;
}
V_59 = F_2 ( & V_6 -> V_59 ) ;
do {
V_40 = F_2 ( & V_6 -> V_8 ) ;
} while ( V_40 & 0x10000000 );
V_59 &= ~ ( V_120 | V_121 |
V_122 | V_123 |
V_124 | V_125 |
V_126 ) ;
V_59 |= ( V_127 | V_128 |
V_129 | V_130 |
V_131 | V_132 |
V_133 ) ;
F_6 ( V_59 , & V_6 -> V_59 ) ;
F_6 ( 0 , & V_6 -> V_29 ) ;
F_6 ( 0 , & V_6 -> V_134 ) ;
F_6 ( 0 , & V_6 -> V_135 ) ;
F_6 ( 0 , & V_6 -> V_136 ) ;
F_6 ( 0 , & V_6 -> V_137 ) ;
F_6 ( V_2 -> V_16 . V_138 - 1 , & V_6 -> V_139 ) ;
F_6 ( V_2 -> V_16 . V_140 - 1 , & V_6 -> V_141 ) ;
}
static void F_22 ( struct V_142 * V_143 , struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_6 )
F_23 ( & V_143 -> V_144 [ 0 ] , V_4 -> V_6 , 4096 ) ;
if ( V_4 -> V_110 )
F_23 ( & V_143 -> V_144 [ 0 ] , V_4 -> V_110 , sizeof( struct V_109 ) ) ;
if ( V_4 -> V_10 )
F_23 ( & V_143 -> V_144 [ 0 ] , V_4 -> V_10 , sizeof( struct V_9 ) ) ;
if ( V_4 -> V_69 )
F_23 ( & V_143 -> V_144 [ 0 ] , V_4 -> V_69 , sizeof( struct V_68 ) ) ;
if ( V_4 -> V_95 )
F_23 ( & V_143 -> V_144 [ 0 ] , V_4 -> V_95 , sizeof( V_26 ) ) ;
if ( V_2 -> V_145 )
F_23 ( & V_143 -> V_144 [ 0 ] , V_2 -> V_145 ,
V_2 -> V_84 . V_86 ) ;
}
static int F_24 ( struct V_142 * V_143 )
{
struct V_146 * V_147 = V_143 -> V_148 . V_149 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_91 , V_150 ;
int V_151 ;
V_2 = F_25 ( sizeof( struct V_3 ) , & V_143 -> V_148 ) ;
V_150 = - V_152 ;
if ( ! V_2 )
goto V_153;
V_4 = V_2 -> V_4 ;
F_26 ( & V_4 -> V_12 ) ;
V_2 -> V_84 . V_85 = V_143 -> V_144 [ 0 ] . V_154 ;
V_4 -> V_87 = V_143 -> V_144 [ 0 ] . V_11 & V_155 ;
F_27 ( & V_2 -> V_16 , V_147 , 8 ) ;
V_2 -> V_16 . V_64 . V_156 = 8 ;
V_2 -> V_16 . V_65 . V_156 = 8 ;
V_2 -> V_16 . V_66 . V_156 = 8 ;
V_91 = F_28 ( V_147 , L_9 ,
V_2 -> V_16 . V_138 ) ;
V_2 -> V_84 . V_86 = F_29 ( V_91 * V_2 -> V_16 . V_140 ) ;
V_151 = F_28 ( V_147 , L_10 , 0 ) ;
if ( V_151 )
V_2 -> V_84 . V_86 *= 4 ;
V_4 -> V_6 = F_30 ( & V_143 -> V_144 [ 0 ] , V_157 ,
4096 , L_11 ) ;
V_4 -> V_110 = F_30 ( & V_143 -> V_144 [ 0 ] , V_158 ,
sizeof( struct V_109 ) , L_12 ) ;
V_4 -> V_10 = F_30 ( & V_143 -> V_144 [ 0 ] , V_159 ,
sizeof( struct V_9 ) , L_13 ) ;
V_4 -> V_69 = F_30 ( & V_143 -> V_144 [ 0 ] , V_160 ,
sizeof( struct V_68 ) , L_14 ) ;
V_4 -> V_95 = F_30 ( & V_143 -> V_144 [ 0 ] , V_161 ,
sizeof( V_26 ) , L_15 ) ;
V_2 -> V_11 = V_162 | V_163 |
V_164 | V_165 |
V_166 ;
V_2 -> V_167 = & V_168 ;
V_2 -> V_145 = F_30 ( & V_143 -> V_144 [ 0 ] , V_169 ,
V_2 -> V_84 . V_86 , L_16 ) ;
if ( ! V_4 -> V_6 || ! V_4 -> V_110 || ! V_4 -> V_10 ||
! V_4 -> V_69 || ! V_4 -> V_95 || ! V_2 -> V_145 )
goto V_170;
V_2 -> V_16 . V_171 = V_172 ;
F_20 ( V_4 ) ;
F_21 ( V_2 ) ;
F_14 ( V_74 , V_2 ) ;
if ( F_31 ( & V_2 -> V_173 , 256 , 0 ) )
goto V_170;
F_32 ( & V_2 -> V_173 , V_2 ) ;
F_19 ( V_2 , V_91 ) ;
V_150 = F_33 ( V_2 ) ;
if ( V_150 < 0 )
goto V_174;
F_34 ( & V_143 -> V_148 , V_2 ) ;
F_35 ( V_175 L_17 ,
V_147 , V_2 -> V_84 . V_101 ,
V_4 -> V_87 , V_2 -> V_84 . V_85 ) ;
return 0 ;
V_174:
F_36 ( & V_2 -> V_173 ) ;
V_170:
F_22 ( V_143 , V_2 , V_4 ) ;
F_37 ( V_2 ) ;
V_153:
return V_150 ;
}
static int F_38 ( struct V_142 * V_143 )
{
struct V_1 * V_2 = F_39 ( & V_143 -> V_148 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_40 ( V_2 ) ;
F_36 ( & V_2 -> V_173 ) ;
F_22 ( V_143 , V_2 , V_4 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int T_4 F_41 ( void )
{
if ( F_42 ( L_18 , NULL ) )
return - V_176 ;
return F_43 ( & V_177 ) ;
}
static void T_5 F_44 ( void )
{
F_45 ( & V_177 ) ;
}

static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 -> V_4 , struct V_1 , V_5 ) ;
}
static inline struct V_1 * F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = NULL ;
F_3 ( & V_7 ) ;
if ( V_3 -> V_4 == NULL )
goto V_8;
V_6 = V_1 ( V_3 ) ;
F_4 ( & V_6 -> V_9 ) ;
if ( F_5 ( V_6 -> V_10 ) )
goto V_11;
goto V_8;
V_11:
F_6 ( & V_6 -> V_9 , V_12 ) ;
V_6 = NULL ;
V_8:
F_7 ( & V_7 ) ;
return V_6 ;
}
static void F_8 ( struct V_1 * V_6 )
{
struct V_13 * V_14 = V_6 -> V_10 ;
F_3 ( & V_7 ) ;
F_6 ( & V_6 -> V_9 , V_12 ) ;
F_9 ( V_14 ) ;
F_7 ( & V_7 ) ;
}
static unsigned int F_10 ( struct V_13 * V_14 )
{
T_1 V_15 [ 8 ] ;
T_1 V_16 [] = { V_17 ,
1 ,
0 , 0 ,
1 << 4 ,
0 , 0 ,
0 , sizeof( V_15 ) ,
0 ,
} ;
struct V_18 * V_19 = ( void * ) V_15 ;
struct V_20 * V_21 = ( void * ) ( V_15 + 4 ) ;
struct V_22 V_23 ;
int V_24 ;
V_24 = F_11 ( V_14 , V_16 , V_25 , V_15 , sizeof( V_15 ) ,
& V_23 , V_26 , V_27 , NULL ) ;
if ( F_12 ( & V_23 ) && V_23 . V_28 == V_29 )
return V_30 ;
if ( V_24 || F_13 ( V_19 -> V_31 ) < sizeof( * V_21 ) )
return 0 ;
if ( V_19 -> V_32 || V_19 -> V_33 != 0x4 )
return 0 ;
if ( V_21 -> V_34 == 1 )
return V_35 ;
else if ( V_21 -> V_34 == 2 )
return V_30 ;
return 0 ;
}
static unsigned int F_14 ( struct V_36 * V_37 ,
unsigned int V_38 , int V_39 )
{
struct V_1 * V_6 = V_37 -> V_40 ;
bool V_41 ;
struct V_22 V_23 ;
unsigned int V_42 ;
int V_43 ;
if ( V_44 != V_39 )
return 0 ;
V_42 = F_10 ( V_6 -> V_10 ) ;
if ( ! ( V_38 & V_30 ) )
goto V_45;
V_41 = V_6 -> V_46 ;
V_43 = F_15 ( V_6 -> V_10 , V_26 , V_27 , & V_23 ) ;
V_6 -> V_46 = F_16 ( V_43 ) ||
( F_12 ( & V_23 ) && V_23 . V_47 != 0x3a ) ;
if ( V_41 != V_6 -> V_46 )
V_42 |= V_30 ;
V_45:
if ( V_6 -> V_10 -> V_48 ) {
V_42 |= V_30 ;
V_6 -> V_10 -> V_48 = 0 ;
}
return V_42 ;
}
static int F_17 ( struct V_49 * V_50 )
{
int V_24 = V_50 -> V_24 ;
int V_51 = F_18 ( V_50 ) ;
int V_52 = ( V_24 == 0 ? V_51 : 0 ) ;
int V_53 = 0 ;
long V_54 ;
struct V_1 * V_6 = V_1 ( V_50 -> V_55 -> V_56 ) ;
#ifdef F_19
F_20 ( L_1 , V_24 ) ;
#endif
if ( F_21 ( V_24 ) != 0 &&
( V_50 -> V_57 [ 0 ] & 0x7f ) == 0x70 ) {
switch ( V_50 -> V_57 [ 2 ] ) {
case V_58 :
case V_59 :
case V_60 :
if ( ! ( V_50 -> V_57 [ 0 ] & 0x90 ) )
break;
V_54 = ( V_50 -> V_57 [ 3 ] << 24 ) |
( V_50 -> V_57 [ 4 ] << 16 ) |
( V_50 -> V_57 [ 5 ] << 8 ) |
V_50 -> V_57 [ 6 ] ;
if ( V_50 -> V_55 -> V_61 != NULL )
V_53 =
F_22 ( V_50 -> V_55 -> V_61 ) ;
if ( V_53 < 4 )
V_53 = 4 ;
if ( V_6 -> V_10 -> V_62 == 2048 )
V_54 <<= 2 ;
V_54 &= ~ ( V_53 - 1 ) ;
V_52 = ( V_54 -
F_23 ( V_50 -> V_55 ) ) << 9 ;
if ( V_52 < 0 || V_52 >= V_51 )
V_52 = 0 ;
if ( V_54 < F_24 ( V_6 -> V_3 ) &&
V_6 -> V_63 - V_54 < 4 * 75 )
F_25 ( V_6 -> V_3 , V_54 ) ;
break;
case V_64 :
V_52 = V_51 ;
break;
default:
break;
}
}
return V_52 ;
}
static int F_26 ( struct V_65 * V_66 , struct V_55 * V_67 )
{
int V_68 = 0 , V_51 , V_69 ;
struct V_1 * V_6 ;
struct V_49 * V_50 ;
struct V_13 * V_70 = V_66 -> V_71 ;
int V_43 ;
if ( V_67 -> V_72 == V_73 ) {
V_43 = F_27 ( V_70 , V_67 ) ;
goto V_8;
} else if ( V_67 -> V_72 != V_74 ) {
V_43 = V_75 ;
goto V_8;
}
V_43 = F_28 ( V_70 , V_67 ) ;
if ( V_43 != V_76 )
goto V_8;
V_50 = V_67 -> V_77 ;
V_6 = V_1 ( V_67 -> V_56 ) ;
V_43 = V_75 ;
F_29 ( 1 , F_20 ( L_2 ,
V_6 -> V_3 -> V_78 , V_68 ) ) ;
if ( ! V_6 -> V_10 || ! F_30 ( V_6 -> V_10 ) ) {
F_29 ( 2 , F_20 ( L_3 ,
F_31 ( V_67 ) ) ) ;
F_29 ( 2 , F_20 ( L_4 , V_50 ) ) ;
goto V_8;
}
if ( V_6 -> V_10 -> V_48 ) {
goto V_8;
}
V_69 = V_6 -> V_10 -> V_62 ;
if ( V_69 > 2048 ) {
if ( ! F_32 () )
F_33 ( V_6 , 2048 ) ;
else
F_20 ( L_5 ) ;
}
if ( V_69 != 512 && V_69 != 1024 && V_69 != 2048 ) {
F_34 ( V_79 , V_50 , L_6 , V_69 ) ;
goto V_8;
}
if ( F_35 ( V_67 ) == V_80 ) {
if ( ! V_6 -> V_10 -> V_81 )
goto V_8;
V_50 -> V_82 [ 0 ] = V_83 ;
V_50 -> V_84 = V_85 ;
V_6 -> V_37 . V_86 = 1 ;
} else if ( F_35 ( V_67 ) == V_87 ) {
V_50 -> V_82 [ 0 ] = V_88 ;
V_50 -> V_84 = V_25 ;
} else {
F_36 ( V_67 , L_7 ) ;
goto V_8;
}
{
struct V_89 * V_90 ;
int V_91 , V_92 = 0 , V_93 = F_37 ( V_50 ) ;
F_38 (SCpnt, sg, sg_count, i)
V_92 += V_90 -> V_94 ;
if ( V_92 != F_18 ( V_50 ) ) {
F_34 ( V_79 , V_50 ,
L_8 ,
V_92 , F_18 ( V_50 ) ) ;
if ( F_18 ( V_50 ) > V_92 )
V_50 -> V_95 . V_94 = V_92 ;
}
}
if ( ( ( unsigned int ) F_23 ( V_67 ) % ( V_69 >> 9 ) ) ||
( F_18 ( V_50 ) % V_69 ) ) {
F_34 ( V_96 , V_50 , L_9 ) ;
goto V_8;
}
V_51 = ( F_18 ( V_50 ) >> 9 ) / ( V_69 >> 9 ) ;
F_29 ( 2 , F_20 ( L_10 ,
V_6 -> V_37 . V_97 ,
( F_35 ( V_67 ) == V_80 ) ?
L_11 : L_12 ,
V_51 , F_31 ( V_67 ) ) ) ;
V_50 -> V_82 [ 1 ] = 0 ;
V_68 = ( unsigned int ) F_23 ( V_67 ) / ( V_69 >> 9 ) ;
if ( V_51 > 0xffff ) {
V_51 = 0xffff ;
V_50 -> V_95 . V_94 = V_51 * V_69 ;
}
V_50 -> V_82 [ 2 ] = ( unsigned char ) ( V_68 >> 24 ) & 0xff ;
V_50 -> V_82 [ 3 ] = ( unsigned char ) ( V_68 >> 16 ) & 0xff ;
V_50 -> V_82 [ 4 ] = ( unsigned char ) ( V_68 >> 8 ) & 0xff ;
V_50 -> V_82 [ 5 ] = ( unsigned char ) V_68 & 0xff ;
V_50 -> V_82 [ 6 ] = V_50 -> V_82 [ 9 ] = 0 ;
V_50 -> V_82 [ 7 ] = ( unsigned char ) ( V_51 >> 8 ) & 0xff ;
V_50 -> V_82 [ 8 ] = ( unsigned char ) V_51 & 0xff ;
V_50 -> V_98 = V_6 -> V_10 -> V_62 ;
V_50 -> V_99 = V_51 << 9 ;
V_50 -> V_100 = V_27 ;
V_43 = V_76 ;
V_8:
return F_39 ( V_66 , V_67 , V_43 ) ;
}
static int F_40 ( struct V_101 * V_102 , T_2 V_103 )
{
struct V_1 * V_6 ;
int V_43 = - V_104 ;
F_3 ( & V_105 ) ;
V_6 = F_2 ( V_102 -> V_106 ) ;
if ( V_6 ) {
V_43 = F_41 ( & V_6 -> V_37 , V_102 , V_103 ) ;
if ( V_43 )
F_8 ( V_6 ) ;
}
F_7 ( & V_105 ) ;
return V_43 ;
}
static int F_42 ( struct V_2 * V_3 , T_2 V_103 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
F_3 ( & V_105 ) ;
F_43 ( & V_6 -> V_37 , V_103 ) ;
F_8 ( V_6 ) ;
F_7 ( & V_105 ) ;
return 0 ;
}
static int F_44 ( struct V_101 * V_102 , T_2 V_103 , unsigned V_16 ,
unsigned long V_107 )
{
struct V_1 * V_6 = V_1 ( V_102 -> V_106 ) ;
struct V_13 * V_14 = V_6 -> V_10 ;
void T_3 * V_108 = ( void T_3 * ) V_107 ;
int V_43 ;
F_3 ( & V_105 ) ;
switch ( V_16 ) {
case V_109 :
case V_110 :
V_43 = F_45 ( V_14 , V_16 , V_108 ) ;
goto V_8;
}
V_43 = F_46 ( & V_6 -> V_37 , V_102 , V_103 , V_16 , V_107 ) ;
if ( V_43 != - V_111 )
goto V_8;
V_43 = F_47 ( V_14 , V_16 , V_108 ,
( V_103 & V_112 ) != 0 ) ;
if ( V_43 != - V_113 )
goto V_8;
V_43 = F_45 ( V_14 , V_16 , V_108 ) ;
V_8:
F_7 ( & V_105 ) ;
return V_43 ;
}
static unsigned int F_48 ( struct V_2 * V_3 ,
unsigned int V_38 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
return F_49 ( & V_6 -> V_37 , V_38 ) ;
}
static int F_50 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
struct V_22 V_23 ;
if ( F_15 ( V_6 -> V_10 , V_26 , V_27 , & V_23 ) )
return 0 ;
F_51 ( & V_6 -> V_37 ) ;
F_52 ( V_6 ) ;
return 0 ;
}
static int F_53 ( struct V_36 * V_37 , int V_114 )
{
struct V_1 * V_6 = V_37 -> V_40 ;
struct V_13 * V_14 = V_6 -> V_10 ;
int V_115 ;
V_115 = - V_104 ;
if ( ! F_54 ( V_14 ) )
goto V_116;
return 0 ;
V_116:
return V_115 ;
}
static void F_55 ( struct V_36 * V_37 )
{
struct V_1 * V_6 = V_37 -> V_40 ;
if ( V_6 -> V_10 -> V_62 > 2048 )
F_33 ( V_6 , 2048 ) ;
}
static int F_56 ( struct V_10 * V_117 )
{
struct V_13 * V_14 = F_57 ( V_117 ) ;
struct V_2 * V_3 ;
struct V_1 * V_6 ;
int V_118 , error ;
error = - V_113 ;
if ( V_14 -> type != V_119 && V_14 -> type != V_120 )
goto V_121;
error = - V_122 ;
V_6 = F_58 ( sizeof( * V_6 ) , V_123 ) ;
if ( ! V_6 )
goto V_121;
F_59 ( & V_6 -> V_9 ) ;
V_3 = F_60 ( 1 ) ;
if ( ! V_3 )
goto V_124;
F_61 ( & V_125 ) ;
V_118 = F_62 ( V_126 , V_127 ) ;
if ( V_118 == V_127 ) {
F_63 ( & V_125 ) ;
error = - V_128 ;
goto V_129;
}
F_64 ( V_118 , V_126 ) ;
F_63 ( & V_125 ) ;
V_3 -> V_130 = V_131 ;
V_3 -> V_132 = V_118 ;
sprintf ( V_3 -> V_78 , L_13 , V_118 ) ;
V_3 -> V_133 = & V_134 ;
V_3 -> V_135 = V_136 | V_137 ;
V_3 -> V_42 = V_30 | V_35 ;
F_65 ( V_14 -> V_65 , V_26 ) ;
V_6 -> V_10 = V_14 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_5 = & V_138 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_63 = 0x1fffff ;
V_6 -> V_10 -> V_48 = 1 ;
V_6 -> V_46 = 1 ;
V_6 -> V_139 = 1 ;
V_6 -> V_140 = 0 ;
V_6 -> V_141 = 0 ;
V_6 -> V_37 . V_142 = & V_143 ;
V_6 -> V_37 . V_40 = V_6 ;
V_6 -> V_37 . V_144 = 0 ;
V_6 -> V_37 . V_63 = 1 ;
sprintf ( V_6 -> V_37 . V_97 , L_13 , V_118 ) ;
V_14 -> V_62 = 2048 ;
F_66 ( V_6 ) ;
F_67 ( V_14 -> V_65 , F_26 ) ;
F_68 ( V_6 ) ;
V_3 -> V_145 = & V_14 -> V_146 ;
F_25 ( V_3 , V_6 -> V_63 ) ;
V_3 -> V_4 = & V_6 -> V_5 ;
V_3 -> V_147 = V_14 -> V_65 ;
V_6 -> V_37 . V_3 = V_3 ;
if ( F_69 ( & V_6 -> V_37 ) )
goto V_129;
F_70 ( V_117 , V_6 ) ;
V_3 -> V_135 |= V_148 ;
F_71 ( V_3 ) ;
F_72 ( V_149 , V_14 ,
L_14 , V_6 -> V_37 . V_97 ) ;
return 0 ;
V_129:
F_73 ( V_3 ) ;
V_124:
F_74 ( V_6 ) ;
V_121:
return error ;
}
static void F_52 ( struct V_1 * V_6 )
{
unsigned char V_16 [ 10 ] ;
unsigned char V_150 [ 8 ] ;
int V_151 , V_152 = 3 ;
int V_62 ;
struct V_65 * V_147 ;
do {
V_16 [ 0 ] = V_153 ;
memset ( ( void * ) & V_16 [ 1 ] , 0 , 9 ) ;
memset ( V_150 , 0 , sizeof( V_150 ) ) ;
V_151 = F_11 ( V_6 -> V_10 , V_16 , V_25 ,
V_150 , sizeof( V_150 ) , NULL ,
V_26 , V_27 , NULL ) ;
V_152 -- ;
} while ( V_151 && V_152 );
if ( V_151 ) {
V_6 -> V_63 = 0x1fffff ;
V_62 = 2048 ;
} else {
long V_154 ;
V_6 -> V_63 = 1 + ( ( V_150 [ 0 ] << 24 ) | ( V_150 [ 1 ] << 16 ) |
( V_150 [ 2 ] << 8 ) | V_150 [ 3 ] ) ;
if ( ! F_75 ( & V_6 -> V_37 , & V_154 ) )
V_6 -> V_63 = F_76 ( long , V_6 -> V_63 , V_154 ) ;
V_62 = ( V_150 [ 4 ] << 24 ) |
( V_150 [ 5 ] << 16 ) | ( V_150 [ 6 ] << 8 ) | V_150 [ 7 ] ;
switch ( V_62 ) {
case 0 :
case 2340 :
case 2352 :
V_62 = 2048 ;
case 2048 :
V_6 -> V_63 *= 4 ;
case 512 :
break;
default:
F_20 ( L_15 ,
V_6 -> V_37 . V_97 , V_62 ) ;
V_6 -> V_63 = 0 ;
}
V_6 -> V_10 -> V_62 = V_62 ;
F_25 ( V_6 -> V_3 , V_6 -> V_63 ) ;
}
V_147 = V_6 -> V_10 -> V_65 ;
F_77 ( V_147 , V_62 ) ;
return;
}
static void F_66 ( struct V_1 * V_6 )
{
unsigned char * V_150 ;
struct V_155 V_156 ;
struct V_22 V_23 ;
int V_157 , V_158 ;
static const char * V_159 [] =
{
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_19 ,
L_19
} ;
V_150 = F_78 ( 512 , V_123 | V_160 ) ;
if ( ! V_150 ) {
F_20 ( V_79 L_22 ) ;
return;
}
F_15 ( V_6 -> V_10 , V_26 , V_27 , & V_23 ) ;
V_157 = F_79 ( V_6 -> V_10 , 0 , 0x2a , V_150 , 128 ,
V_26 , 3 , & V_156 , NULL ) ;
if ( ! F_16 ( V_157 ) ) {
V_6 -> V_37 . V_161 = 1 ;
V_6 -> V_37 . V_144 |= ( V_162 | V_163 | V_164 |
V_165 | V_166 |
V_167 | V_168 |
V_169 | V_170 | V_171 ) ;
F_74 ( V_150 ) ;
F_20 ( L_23 , V_6 -> V_37 . V_97 ) ;
return;
}
V_158 = V_156 . V_172 + V_156 . V_173 ;
V_6 -> V_37 . V_161 = ( ( V_150 [ V_158 + 8 ] << 8 ) + V_150 [ V_158 + 9 ] ) / 176 ;
V_6 -> V_140 = 1 ;
V_6 -> V_141 = V_150 [ V_158 + 5 ] & 0x01 ;
F_20 ( L_24 , V_6 -> V_37 . V_97 ,
( ( V_150 [ V_158 + 14 ] << 8 ) + V_150 [ V_158 + 15 ] ) / 176 ,
V_6 -> V_37 . V_161 ,
V_150 [ V_158 + 3 ] & 0x01 ? L_25 : L_19 ,
V_150 [ V_158 + 3 ] & 0x20 ? L_26 : L_19 ,
V_150 [ V_158 + 2 ] & 0x02 ? L_27 : L_19 ,
V_150 [ V_158 + 4 ] & 0x20 ? L_28 : L_19 ,
V_150 [ V_158 + 5 ] & 0x01 ? L_29 : L_19 ,
V_159 [ V_150 [ V_158 + 6 ] >> 5 ] ) ;
if ( ( V_150 [ V_158 + 6 ] >> 5 ) == 0 )
V_6 -> V_37 . V_144 |= V_174 ;
if ( ( V_150 [ V_158 + 2 ] & 0x8 ) == 0 )
V_6 -> V_37 . V_144 |= V_165 ;
if ( ( V_150 [ V_158 + 3 ] & 0x20 ) == 0 )
V_6 -> V_37 . V_144 |= V_166 ;
if ( ( V_150 [ V_158 + 3 ] & 0x10 ) == 0 )
V_6 -> V_37 . V_144 |= V_164 ;
if ( ( V_150 [ V_158 + 3 ] & 0x2 ) == 0 )
V_6 -> V_37 . V_144 |= V_163 ;
if ( ( V_150 [ V_158 + 3 ] & 0x1 ) == 0 )
V_6 -> V_37 . V_144 |= V_162 ;
if ( ( V_150 [ V_158 + 6 ] & 0x8 ) == 0 )
V_6 -> V_37 . V_144 |= V_175 ;
if ( ( V_150 [ V_158 + 6 ] >> 5 ) == V_176 ||
( V_150 [ V_158 + 6 ] >> 5 ) == V_177 )
V_6 -> V_37 . V_63 =
F_80 ( & V_6 -> V_37 ) ;
if ( V_6 -> V_37 . V_63 <= 1 )
V_6 -> V_37 . V_144 |= V_167 ;
if ( ( V_6 -> V_37 . V_144 & ( V_166 | V_170 | V_171 | V_163 ) ) !=
( V_166 | V_170 | V_171 | V_163 ) ) {
V_6 -> V_10 -> V_81 = 1 ;
}
F_74 ( V_150 ) ;
}
static int F_81 ( struct V_36 * V_37 ,
struct V_178 * V_179 )
{
struct V_1 * V_6 = V_37 -> V_40 ;
struct V_13 * V_14 = V_6 -> V_10 ;
if ( V_179 -> V_16 [ 0 ] == V_180 && V_14 -> V_181 )
return - V_182 ;
if ( V_179 -> V_183 <= 0 )
V_179 -> V_183 = V_184 ;
F_82 ( V_6 , V_179 ) ;
return V_179 -> V_185 ;
}
static void V_12 ( struct V_9 * V_9 )
{
struct V_1 * V_6 = F_1 ( V_9 , struct V_1 , V_9 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
F_61 ( & V_125 ) ;
F_83 ( F_84 ( F_85 ( V_3 ) ) , V_126 ) ;
F_63 ( & V_125 ) ;
F_86 ( & V_6 -> V_37 ) ;
V_3 -> V_4 = NULL ;
F_73 ( V_3 ) ;
F_74 ( V_6 ) ;
}
static int F_87 ( struct V_10 * V_117 )
{
struct V_1 * V_6 = F_88 ( V_117 ) ;
F_67 ( V_6 -> V_10 -> V_65 , V_186 ) ;
F_89 ( V_6 -> V_3 ) ;
F_3 ( & V_7 ) ;
F_6 ( & V_6 -> V_9 , V_12 ) ;
F_7 ( & V_7 ) ;
return 0 ;
}
static int T_4 F_90 ( void )
{
int V_157 ;
V_157 = F_91 ( V_131 , L_30 ) ;
if ( V_157 )
return V_157 ;
V_157 = F_92 ( & V_138 . V_187 ) ;
if ( V_157 )
F_93 ( V_131 , L_30 ) ;
return V_157 ;
}
static void T_5 F_94 ( void )
{
F_95 ( & V_138 . V_187 ) ;
F_93 ( V_131 , L_30 ) ;
}

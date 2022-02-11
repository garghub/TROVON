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
V_6 -> V_45 |= V_42 & V_30 ;
if ( V_6 -> V_46 ) {
V_42 &= ~ V_30 ;
goto V_47;
}
if ( V_6 -> V_10 -> V_48 ) {
V_42 |= V_30 ;
V_6 -> V_10 -> V_48 = 0 ;
V_6 -> V_49 = true ;
}
if ( ! ( V_38 & V_30 ) )
return V_42 ;
V_47:
V_41 = V_6 -> V_50 ;
V_43 = F_15 ( V_6 -> V_10 , V_26 , V_27 , & V_23 ) ;
V_6 -> V_50 = F_16 ( V_43 ) ||
( F_12 ( & V_23 ) && V_23 . V_51 != 0x3a ) ;
if ( V_41 != V_6 -> V_50 )
V_6 -> V_10 -> V_48 = 1 ;
if ( V_6 -> V_10 -> V_48 ) {
V_42 |= V_30 ;
V_6 -> V_10 -> V_48 = 0 ;
V_6 -> V_49 = true ;
}
if ( V_6 -> V_46 )
return V_42 ;
if ( ! V_6 -> V_49 ) {
if ( V_6 -> V_45 ) {
if ( V_6 -> V_52 ++ > 8 ) {
F_17 ( V_53 , V_6 -> V_10 ,
L_1 ) ;
V_6 -> V_46 = true ;
}
} else {
V_6 -> V_52 = 0 ;
}
}
V_6 -> V_49 = false ;
V_6 -> V_45 = false ;
return V_42 ;
}
static int F_18 ( struct V_54 * V_55 )
{
int V_24 = V_55 -> V_24 ;
int V_56 = F_19 ( V_55 ) ;
int V_57 = ( V_24 == 0 ? V_56 : 0 ) ;
int V_58 = 0 ;
long V_59 ;
struct V_1 * V_6 = V_1 ( V_55 -> V_60 -> V_61 ) ;
#ifdef F_20
F_21 ( L_2 , V_24 ) ;
#endif
if ( F_22 ( V_24 ) != 0 &&
( V_55 -> V_62 [ 0 ] & 0x7f ) == 0x70 ) {
switch ( V_55 -> V_62 [ 2 ] ) {
case V_63 :
case V_64 :
case V_65 :
if ( ! ( V_55 -> V_62 [ 0 ] & 0x90 ) )
break;
V_59 = ( V_55 -> V_62 [ 3 ] << 24 ) |
( V_55 -> V_62 [ 4 ] << 16 ) |
( V_55 -> V_62 [ 5 ] << 8 ) |
V_55 -> V_62 [ 6 ] ;
if ( V_55 -> V_60 -> V_66 != NULL )
V_58 =
F_23 ( V_55 -> V_60 -> V_66 ) ;
if ( V_58 < 4 )
V_58 = 4 ;
if ( V_6 -> V_10 -> V_67 == 2048 )
V_59 <<= 2 ;
V_59 &= ~ ( V_58 - 1 ) ;
V_57 = ( V_59 -
F_24 ( V_55 -> V_60 ) ) << 9 ;
if ( V_57 < 0 || V_57 >= V_56 )
V_57 = 0 ;
if ( V_59 < F_25 ( V_6 -> V_3 ) &&
V_6 -> V_68 - V_59 < 4 * 75 )
F_26 ( V_6 -> V_3 , V_59 ) ;
break;
case V_69 :
V_57 = V_56 ;
break;
default:
break;
}
}
return V_57 ;
}
static int F_27 ( struct V_70 * V_71 , struct V_60 * V_72 )
{
int V_73 = 0 , V_56 , V_74 ;
struct V_1 * V_6 ;
struct V_54 * V_55 ;
struct V_13 * V_75 = V_71 -> V_76 ;
int V_43 ;
if ( V_72 -> V_77 == V_78 ) {
V_43 = F_28 ( V_75 , V_72 ) ;
goto V_8;
} else if ( V_72 -> V_77 != V_79 ) {
V_43 = V_80 ;
goto V_8;
}
V_43 = F_29 ( V_75 , V_72 ) ;
if ( V_43 != V_81 )
goto V_8;
V_55 = V_72 -> V_82 ;
V_6 = V_1 ( V_72 -> V_61 ) ;
V_43 = V_80 ;
F_30 ( 1 , F_21 ( L_3 ,
V_6 -> V_3 -> V_83 , V_73 ) ) ;
if ( ! V_6 -> V_10 || ! F_31 ( V_6 -> V_10 ) ) {
F_30 ( 2 , F_21 ( L_4 ,
F_32 ( V_72 ) ) ) ;
F_30 ( 2 , F_21 ( L_5 , V_55 ) ) ;
goto V_8;
}
if ( V_6 -> V_10 -> V_48 ) {
goto V_8;
}
V_74 = V_6 -> V_10 -> V_67 ;
if ( V_74 > 2048 ) {
if ( ! F_33 () )
F_34 ( V_6 , 2048 ) ;
else
F_21 ( L_6 ) ;
}
if ( V_74 != 512 && V_74 != 1024 && V_74 != 2048 ) {
F_35 ( V_84 , V_55 , L_7 , V_74 ) ;
goto V_8;
}
if ( F_36 ( V_72 ) == V_85 ) {
if ( ! V_6 -> V_10 -> V_86 )
goto V_8;
V_55 -> V_87 [ 0 ] = V_88 ;
V_55 -> V_89 = V_90 ;
V_6 -> V_37 . V_91 = 1 ;
} else if ( F_36 ( V_72 ) == V_92 ) {
V_55 -> V_87 [ 0 ] = V_93 ;
V_55 -> V_89 = V_25 ;
} else {
F_37 ( V_72 , L_8 ) ;
goto V_8;
}
{
struct V_94 * V_95 ;
int V_96 , V_97 = 0 , V_98 = F_38 ( V_55 ) ;
F_39 (SCpnt, sg, sg_count, i)
V_97 += V_95 -> V_99 ;
if ( V_97 != F_19 ( V_55 ) ) {
F_35 ( V_84 , V_55 ,
L_9 ,
V_97 , F_19 ( V_55 ) ) ;
if ( F_19 ( V_55 ) > V_97 )
V_55 -> V_100 . V_99 = V_97 ;
}
}
if ( ( ( unsigned int ) F_24 ( V_72 ) % ( V_74 >> 9 ) ) ||
( F_19 ( V_55 ) % V_74 ) ) {
F_35 ( V_101 , V_55 , L_10 ) ;
goto V_8;
}
V_56 = ( F_19 ( V_55 ) >> 9 ) / ( V_74 >> 9 ) ;
F_30 ( 2 , F_21 ( L_11 ,
V_6 -> V_37 . V_102 ,
( F_36 ( V_72 ) == V_85 ) ?
L_12 : L_13 ,
V_56 , F_32 ( V_72 ) ) ) ;
V_55 -> V_87 [ 1 ] = 0 ;
V_73 = ( unsigned int ) F_24 ( V_72 ) / ( V_74 >> 9 ) ;
if ( V_56 > 0xffff ) {
V_56 = 0xffff ;
V_55 -> V_100 . V_99 = V_56 * V_74 ;
}
V_55 -> V_87 [ 2 ] = ( unsigned char ) ( V_73 >> 24 ) & 0xff ;
V_55 -> V_87 [ 3 ] = ( unsigned char ) ( V_73 >> 16 ) & 0xff ;
V_55 -> V_87 [ 4 ] = ( unsigned char ) ( V_73 >> 8 ) & 0xff ;
V_55 -> V_87 [ 5 ] = ( unsigned char ) V_73 & 0xff ;
V_55 -> V_87 [ 6 ] = V_55 -> V_87 [ 9 ] = 0 ;
V_55 -> V_87 [ 7 ] = ( unsigned char ) ( V_56 >> 8 ) & 0xff ;
V_55 -> V_87 [ 8 ] = ( unsigned char ) V_56 & 0xff ;
V_55 -> V_103 = V_6 -> V_10 -> V_67 ;
V_55 -> V_104 = V_56 << 9 ;
V_55 -> V_105 = V_27 ;
V_43 = V_81 ;
V_8:
return F_40 ( V_71 , V_72 , V_43 ) ;
}
static int F_41 ( struct V_106 * V_107 , T_2 V_108 )
{
struct V_1 * V_6 ;
int V_43 = - V_109 ;
F_3 ( & V_110 ) ;
V_6 = F_2 ( V_107 -> V_111 ) ;
if ( V_6 ) {
V_43 = F_42 ( & V_6 -> V_37 , V_107 , V_108 ) ;
if ( V_43 )
F_8 ( V_6 ) ;
}
F_7 ( & V_110 ) ;
return V_43 ;
}
static int F_43 ( struct V_2 * V_3 , T_2 V_108 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
F_3 ( & V_110 ) ;
F_44 ( & V_6 -> V_37 , V_108 ) ;
F_8 ( V_6 ) ;
F_7 ( & V_110 ) ;
return 0 ;
}
static int F_45 ( struct V_106 * V_107 , T_2 V_108 , unsigned V_16 ,
unsigned long V_112 )
{
struct V_1 * V_6 = V_1 ( V_107 -> V_111 ) ;
struct V_13 * V_14 = V_6 -> V_10 ;
void T_3 * V_113 = ( void T_3 * ) V_112 ;
int V_43 ;
F_3 ( & V_110 ) ;
switch ( V_16 ) {
case V_114 :
case V_115 :
V_43 = F_46 ( V_14 , V_16 , V_113 ) ;
goto V_8;
}
V_43 = F_47 ( & V_6 -> V_37 , V_107 , V_108 , V_16 , V_112 ) ;
if ( V_43 != - V_116 )
goto V_8;
V_43 = F_48 ( V_14 , V_16 , V_113 ,
( V_108 & V_117 ) != 0 ) ;
if ( V_43 != - V_118 )
goto V_8;
V_43 = F_46 ( V_14 , V_16 , V_113 ) ;
V_8:
F_7 ( & V_110 ) ;
return V_43 ;
}
static unsigned int F_49 ( struct V_2 * V_3 ,
unsigned int V_38 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
return F_50 ( & V_6 -> V_37 , V_38 ) ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = V_1 ( V_3 ) ;
struct V_22 V_23 ;
if ( F_15 ( V_6 -> V_10 , V_26 , V_27 , & V_23 ) )
return 0 ;
F_52 ( & V_6 -> V_37 ) ;
F_53 ( V_6 ) ;
return 0 ;
}
static int F_54 ( struct V_36 * V_37 , int V_119 )
{
struct V_1 * V_6 = V_37 -> V_40 ;
struct V_13 * V_14 = V_6 -> V_10 ;
int V_120 ;
V_120 = - V_109 ;
if ( ! F_55 ( V_14 ) )
goto V_121;
return 0 ;
V_121:
return V_120 ;
}
static void F_56 ( struct V_36 * V_37 )
{
struct V_1 * V_6 = V_37 -> V_40 ;
if ( V_6 -> V_10 -> V_67 > 2048 )
F_34 ( V_6 , 2048 ) ;
}
static int F_57 ( struct V_10 * V_122 )
{
struct V_13 * V_14 = F_58 ( V_122 ) ;
struct V_2 * V_3 ;
struct V_1 * V_6 ;
int V_123 , error ;
error = - V_118 ;
if ( V_14 -> type != V_124 && V_14 -> type != V_125 )
goto V_126;
error = - V_127 ;
V_6 = F_59 ( sizeof( * V_6 ) , V_128 ) ;
if ( ! V_6 )
goto V_126;
F_60 ( & V_6 -> V_9 ) ;
V_3 = F_61 ( 1 ) ;
if ( ! V_3 )
goto V_129;
F_62 ( & V_130 ) ;
V_123 = F_63 ( V_131 , V_132 ) ;
if ( V_123 == V_132 ) {
F_64 ( & V_130 ) ;
error = - V_133 ;
goto V_134;
}
F_65 ( V_123 , V_131 ) ;
F_64 ( & V_130 ) ;
V_3 -> V_135 = V_136 ;
V_3 -> V_137 = V_123 ;
sprintf ( V_3 -> V_83 , L_14 , V_123 ) ;
V_3 -> V_138 = & V_139 ;
V_3 -> V_140 = V_141 | V_142 ;
V_3 -> V_42 = V_30 | V_35 ;
F_66 ( V_14 -> V_70 , V_26 ) ;
V_6 -> V_10 = V_14 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_5 = & V_143 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_68 = 0x1fffff ;
V_6 -> V_10 -> V_48 = 1 ;
V_6 -> V_50 = 1 ;
V_6 -> V_144 = 1 ;
V_6 -> V_145 = 0 ;
V_6 -> V_146 = 0 ;
V_6 -> V_37 . V_147 = & V_148 ;
V_6 -> V_37 . V_40 = V_6 ;
V_6 -> V_37 . V_149 = 0 ;
V_6 -> V_37 . V_68 = 1 ;
sprintf ( V_6 -> V_37 . V_102 , L_14 , V_123 ) ;
V_14 -> V_67 = 2048 ;
F_67 ( V_6 ) ;
F_68 ( V_14 -> V_70 , F_27 ) ;
F_69 ( V_6 ) ;
V_3 -> V_150 = & V_14 -> V_151 ;
F_26 ( V_3 , V_6 -> V_68 ) ;
V_3 -> V_4 = & V_6 -> V_5 ;
V_3 -> V_152 = V_14 -> V_70 ;
V_6 -> V_37 . V_3 = V_3 ;
if ( F_70 ( & V_6 -> V_37 ) )
goto V_134;
F_71 ( V_122 , V_6 ) ;
V_3 -> V_140 |= V_153 ;
F_72 ( V_3 ) ;
F_17 ( V_154 , V_14 ,
L_15 , V_6 -> V_37 . V_102 ) ;
return 0 ;
V_134:
F_73 ( V_3 ) ;
V_129:
F_74 ( V_6 ) ;
V_126:
return error ;
}
static void F_53 ( struct V_1 * V_6 )
{
unsigned char V_16 [ 10 ] ;
unsigned char V_155 [ 8 ] ;
int V_156 , V_157 = 3 ;
int V_67 ;
struct V_70 * V_152 ;
do {
V_16 [ 0 ] = V_158 ;
memset ( ( void * ) & V_16 [ 1 ] , 0 , 9 ) ;
memset ( V_155 , 0 , sizeof( V_155 ) ) ;
V_156 = F_11 ( V_6 -> V_10 , V_16 , V_25 ,
V_155 , sizeof( V_155 ) , NULL ,
V_26 , V_27 , NULL ) ;
V_157 -- ;
} while ( V_156 && V_157 );
if ( V_156 ) {
V_6 -> V_68 = 0x1fffff ;
V_67 = 2048 ;
} else {
long V_159 ;
V_6 -> V_68 = 1 + ( ( V_155 [ 0 ] << 24 ) | ( V_155 [ 1 ] << 16 ) |
( V_155 [ 2 ] << 8 ) | V_155 [ 3 ] ) ;
if ( ! F_75 ( & V_6 -> V_37 , & V_159 ) )
V_6 -> V_68 = F_76 ( long , V_6 -> V_68 , V_159 ) ;
V_67 = ( V_155 [ 4 ] << 24 ) |
( V_155 [ 5 ] << 16 ) | ( V_155 [ 6 ] << 8 ) | V_155 [ 7 ] ;
switch ( V_67 ) {
case 0 :
case 2340 :
case 2352 :
V_67 = 2048 ;
case 2048 :
V_6 -> V_68 *= 4 ;
case 512 :
break;
default:
F_21 ( L_16 ,
V_6 -> V_37 . V_102 , V_67 ) ;
V_6 -> V_68 = 0 ;
}
V_6 -> V_10 -> V_67 = V_67 ;
F_26 ( V_6 -> V_3 , V_6 -> V_68 ) ;
}
V_152 = V_6 -> V_10 -> V_70 ;
F_77 ( V_152 , V_67 ) ;
return;
}
static void F_67 ( struct V_1 * V_6 )
{
unsigned char * V_155 ;
struct V_160 V_161 ;
struct V_22 V_23 ;
int V_162 , V_163 ;
static const char * V_164 [] =
{
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_20 ,
L_20
} ;
V_155 = F_78 ( 512 , V_128 | V_165 ) ;
if ( ! V_155 ) {
F_21 ( V_84 L_23 ) ;
return;
}
F_15 ( V_6 -> V_10 , V_26 , V_27 , & V_23 ) ;
V_162 = F_79 ( V_6 -> V_10 , 0 , 0x2a , V_155 , 128 ,
V_26 , 3 , & V_161 , NULL ) ;
if ( ! F_16 ( V_162 ) ) {
V_6 -> V_37 . V_166 = 1 ;
V_6 -> V_37 . V_149 |= ( V_167 | V_168 | V_169 |
V_170 | V_171 |
V_172 | V_173 |
V_174 | V_175 | V_176 ) ;
F_74 ( V_155 ) ;
F_21 ( L_24 , V_6 -> V_37 . V_102 ) ;
return;
}
V_163 = V_161 . V_177 + V_161 . V_178 ;
V_6 -> V_37 . V_166 = ( ( V_155 [ V_163 + 8 ] << 8 ) + V_155 [ V_163 + 9 ] ) / 176 ;
V_6 -> V_145 = 1 ;
V_6 -> V_146 = V_155 [ V_163 + 5 ] & 0x01 ;
F_21 ( L_25 , V_6 -> V_37 . V_102 ,
( ( V_155 [ V_163 + 14 ] << 8 ) + V_155 [ V_163 + 15 ] ) / 176 ,
V_6 -> V_37 . V_166 ,
V_155 [ V_163 + 3 ] & 0x01 ? L_26 : L_20 ,
V_155 [ V_163 + 3 ] & 0x20 ? L_27 : L_20 ,
V_155 [ V_163 + 2 ] & 0x02 ? L_28 : L_20 ,
V_155 [ V_163 + 4 ] & 0x20 ? L_29 : L_20 ,
V_155 [ V_163 + 5 ] & 0x01 ? L_30 : L_20 ,
V_164 [ V_155 [ V_163 + 6 ] >> 5 ] ) ;
if ( ( V_155 [ V_163 + 6 ] >> 5 ) == 0 )
V_6 -> V_37 . V_149 |= V_179 ;
if ( ( V_155 [ V_163 + 2 ] & 0x8 ) == 0 )
V_6 -> V_37 . V_149 |= V_170 ;
if ( ( V_155 [ V_163 + 3 ] & 0x20 ) == 0 )
V_6 -> V_37 . V_149 |= V_171 ;
if ( ( V_155 [ V_163 + 3 ] & 0x10 ) == 0 )
V_6 -> V_37 . V_149 |= V_169 ;
if ( ( V_155 [ V_163 + 3 ] & 0x2 ) == 0 )
V_6 -> V_37 . V_149 |= V_168 ;
if ( ( V_155 [ V_163 + 3 ] & 0x1 ) == 0 )
V_6 -> V_37 . V_149 |= V_167 ;
if ( ( V_155 [ V_163 + 6 ] & 0x8 ) == 0 )
V_6 -> V_37 . V_149 |= V_180 ;
if ( ( V_155 [ V_163 + 6 ] >> 5 ) == V_181 ||
( V_155 [ V_163 + 6 ] >> 5 ) == V_182 )
V_6 -> V_37 . V_68 =
F_80 ( & V_6 -> V_37 ) ;
if ( V_6 -> V_37 . V_68 <= 1 )
V_6 -> V_37 . V_149 |= V_172 ;
if ( ( V_6 -> V_37 . V_149 & ( V_171 | V_175 | V_176 | V_168 ) ) !=
( V_171 | V_175 | V_176 | V_168 ) ) {
V_6 -> V_10 -> V_86 = 1 ;
}
F_74 ( V_155 ) ;
}
static int F_81 ( struct V_36 * V_37 ,
struct V_183 * V_184 )
{
struct V_1 * V_6 = V_37 -> V_40 ;
struct V_13 * V_14 = V_6 -> V_10 ;
if ( V_184 -> V_16 [ 0 ] == V_185 && V_14 -> V_186 )
return - V_187 ;
if ( V_184 -> V_188 <= 0 )
V_184 -> V_188 = V_189 ;
F_82 ( V_6 , V_184 ) ;
return V_184 -> V_190 ;
}
static void V_12 ( struct V_9 * V_9 )
{
struct V_1 * V_6 = F_1 ( V_9 , struct V_1 , V_9 ) ;
struct V_2 * V_3 = V_6 -> V_3 ;
F_62 ( & V_130 ) ;
F_83 ( F_84 ( F_85 ( V_3 ) ) , V_131 ) ;
F_64 ( & V_130 ) ;
F_86 ( & V_6 -> V_37 ) ;
V_3 -> V_4 = NULL ;
F_73 ( V_3 ) ;
F_74 ( V_6 ) ;
}
static int F_87 ( struct V_10 * V_122 )
{
struct V_1 * V_6 = F_88 ( V_122 ) ;
F_68 ( V_6 -> V_10 -> V_70 , V_191 ) ;
F_89 ( V_6 -> V_3 ) ;
F_3 ( & V_7 ) ;
F_6 ( & V_6 -> V_9 , V_12 ) ;
F_7 ( & V_7 ) ;
return 0 ;
}
static int T_4 F_90 ( void )
{
int V_162 ;
V_162 = F_91 ( V_136 , L_31 ) ;
if ( V_162 )
return V_162 ;
V_162 = F_92 ( & V_143 . V_192 ) ;
if ( V_162 )
F_93 ( V_136 , L_31 ) ;
return V_162 ;
}
static void T_5 F_94 ( void )
{
F_95 ( & V_143 . V_192 ) ;
F_93 ( V_136 , L_31 ) ;
}

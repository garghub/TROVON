static inline struct V_1 * V_1 ( struct V_2 * V_3 )
{
return F_1 ( V_3 -> V_4 , struct V_1 , V_5 ) ;
}
static int F_2 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
if ( ! V_8 )
return 0 ;
if ( V_8 -> V_9 )
return - V_10 ;
else
return 0 ;
}
static inline struct V_1 * F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = NULL ;
F_5 ( & V_11 ) ;
if ( V_3 -> V_4 == NULL )
goto V_12;
V_8 = V_1 ( V_3 ) ;
F_6 ( & V_8 -> V_13 ) ;
if ( F_7 ( V_8 -> V_6 ) ) {
F_8 ( & V_8 -> V_13 , V_14 ) ;
V_8 = NULL ;
}
V_12:
F_9 ( & V_11 ) ;
return V_8 ;
}
static void F_10 ( struct V_1 * V_8 )
{
struct V_15 * V_16 = V_8 -> V_6 ;
F_5 ( & V_11 ) ;
F_8 ( & V_8 -> V_13 , V_14 ) ;
F_11 ( V_16 ) ;
F_9 ( & V_11 ) ;
}
static unsigned int F_12 ( struct V_15 * V_16 )
{
T_1 V_17 [ 8 ] ;
T_1 V_18 [] = { V_19 ,
1 ,
0 , 0 ,
1 << 4 ,
0 , 0 ,
0 , sizeof( V_17 ) ,
0 ,
} ;
struct V_20 * V_21 = ( void * ) V_17 ;
struct V_22 * V_23 = ( void * ) ( V_17 + 4 ) ;
struct V_24 V_25 ;
int V_26 ;
V_26 = F_13 ( V_16 , V_18 , V_27 , V_17 , sizeof( V_17 ) ,
& V_25 , V_28 , V_29 , NULL ) ;
if ( F_14 ( & V_25 ) && V_25 . V_30 == V_31 )
return V_32 ;
if ( V_26 || F_15 ( V_21 -> V_33 ) < sizeof( * V_23 ) )
return 0 ;
if ( V_21 -> V_34 || V_21 -> V_35 != 0x4 )
return 0 ;
if ( V_23 -> V_36 == 1 )
return V_37 ;
else if ( V_23 -> V_36 == 2 )
return V_32 ;
return 0 ;
}
static unsigned int F_16 ( struct V_38 * V_39 ,
unsigned int V_40 , int V_41 )
{
struct V_1 * V_8 = V_39 -> V_42 ;
bool V_43 ;
struct V_24 V_25 ;
unsigned int V_44 ;
int V_45 ;
if ( V_46 != V_41 )
return 0 ;
V_44 = F_12 ( V_8 -> V_6 ) ;
V_8 -> V_47 |= V_44 & V_32 ;
if ( V_8 -> V_48 ) {
V_44 &= ~ V_32 ;
goto V_49;
}
if ( V_8 -> V_6 -> V_50 ) {
V_44 |= V_32 ;
V_8 -> V_6 -> V_50 = 0 ;
V_8 -> V_51 = true ;
}
if ( ! ( V_40 & V_32 ) )
return V_44 ;
V_49:
V_43 = V_8 -> V_9 ;
V_45 = F_17 ( V_8 -> V_6 , V_28 , V_29 , & V_25 ) ;
V_8 -> V_9 = F_18 ( V_45 ) ||
( F_14 ( & V_25 ) && V_25 . V_52 != 0x3a ) ;
if ( V_43 != V_8 -> V_9 )
V_8 -> V_6 -> V_50 = 1 ;
if ( V_8 -> V_6 -> V_50 ) {
V_44 |= V_32 ;
V_8 -> V_6 -> V_50 = 0 ;
V_8 -> V_51 = true ;
}
if ( V_8 -> V_48 )
return V_44 ;
if ( ! V_8 -> V_51 ) {
if ( V_8 -> V_47 ) {
if ( V_8 -> V_53 ++ > 8 ) {
F_19 ( V_54 , V_8 ,
L_1 ) ;
V_8 -> V_48 = true ;
}
} else {
V_8 -> V_53 = 0 ;
}
}
V_8 -> V_51 = false ;
V_8 -> V_47 = false ;
return V_44 ;
}
static int F_20 ( struct V_55 * V_56 )
{
int V_26 = V_56 -> V_26 ;
int V_57 = F_21 ( V_56 ) ;
int V_58 = ( V_26 == 0 ? V_57 : 0 ) ;
int V_59 = 0 ;
long V_60 ;
struct V_1 * V_8 = V_1 ( V_56 -> V_61 -> V_62 ) ;
#ifdef F_22
F_23 ( V_63 , V_56 , L_2 , V_26 ) ;
#endif
if ( F_24 ( V_26 ) != 0 &&
( V_56 -> V_64 [ 0 ] & 0x7f ) == 0x70 ) {
switch ( V_56 -> V_64 [ 2 ] ) {
case V_65 :
case V_66 :
case V_67 :
if ( ! ( V_56 -> V_64 [ 0 ] & 0x90 ) )
break;
V_60 = ( V_56 -> V_64 [ 3 ] << 24 ) |
( V_56 -> V_64 [ 4 ] << 16 ) |
( V_56 -> V_64 [ 5 ] << 8 ) |
V_56 -> V_64 [ 6 ] ;
if ( V_56 -> V_61 -> V_68 != NULL )
V_59 =
F_25 ( V_56 -> V_61 -> V_68 ) ;
if ( V_59 < 4 )
V_59 = 4 ;
if ( V_8 -> V_6 -> V_69 == 2048 )
V_60 <<= 2 ;
V_60 &= ~ ( V_59 - 1 ) ;
V_58 = ( V_60 -
F_26 ( V_56 -> V_61 ) ) << 9 ;
if ( V_58 < 0 || V_58 >= V_57 )
V_58 = 0 ;
if ( V_60 < F_27 ( V_8 -> V_3 ) &&
V_8 -> V_70 - V_60 < 4 * 75 )
F_28 ( V_8 -> V_3 , V_60 ) ;
break;
case V_71 :
V_58 = V_57 ;
break;
default:
break;
}
}
return V_58 ;
}
static int F_29 ( struct V_55 * V_56 )
{
int V_72 = 0 , V_57 , V_73 ;
struct V_1 * V_8 ;
struct V_61 * V_74 = V_56 -> V_61 ;
int V_45 ;
V_45 = F_30 ( V_56 ) ;
if ( V_45 != V_75 )
goto V_12;
V_56 = V_74 -> V_76 ;
V_8 = V_1 ( V_74 -> V_62 ) ;
V_45 = V_77 ;
F_31 ( 1 , F_23 ( V_63 , V_56 ,
L_3 , V_72 ) ) ;
if ( ! V_8 -> V_6 || ! F_32 ( V_8 -> V_6 ) ) {
F_31 ( 2 , F_23 ( V_63 , V_56 ,
L_4 , F_33 ( V_74 ) ) ) ;
F_31 ( 2 , F_23 ( V_63 , V_56 ,
L_5 , V_56 ) ) ;
goto V_12;
}
if ( V_8 -> V_6 -> V_50 ) {
goto V_12;
}
V_73 = V_8 -> V_6 -> V_69 ;
if ( V_73 > 2048 ) {
if ( ! F_34 () )
F_35 ( V_8 , 2048 ) ;
else
F_23 ( V_63 , V_56 ,
L_6 ) ;
}
if ( V_73 != 512 && V_73 != 1024 && V_73 != 2048 ) {
F_23 ( V_78 , V_56 , L_7 , V_73 ) ;
goto V_12;
}
if ( F_36 ( V_74 ) == V_79 ) {
if ( ! V_8 -> V_80 )
goto V_12;
V_56 -> V_81 [ 0 ] = V_82 ;
V_8 -> V_39 . V_83 = 1 ;
} else if ( F_36 ( V_74 ) == V_84 ) {
V_56 -> V_81 [ 0 ] = V_85 ;
} else {
F_37 ( V_74 , L_8 ) ;
goto V_12;
}
{
struct V_86 * V_87 ;
int V_88 , V_89 = 0 , V_90 = F_38 ( V_56 ) ;
F_39 (SCpnt, sg, sg_count, i)
V_89 += V_87 -> V_91 ;
if ( V_89 != F_21 ( V_56 ) ) {
F_23 ( V_78 , V_56 ,
L_9 ,
V_89 , F_21 ( V_56 ) ) ;
if ( F_21 ( V_56 ) > V_89 )
V_56 -> V_92 . V_91 = V_89 ;
}
}
if ( ( ( unsigned int ) F_26 ( V_74 ) % ( V_73 >> 9 ) ) ||
( F_21 ( V_56 ) % V_73 ) ) {
F_23 ( V_93 , V_56 , L_10 ) ;
goto V_12;
}
V_57 = ( F_21 ( V_56 ) >> 9 ) / ( V_73 >> 9 ) ;
F_31 ( 2 , F_23 ( V_63 , V_56 ,
L_11 ,
( F_36 ( V_74 ) == V_79 ) ?
L_12 : L_13 ,
V_57 , F_33 ( V_74 ) ) ) ;
V_56 -> V_81 [ 1 ] = 0 ;
V_72 = ( unsigned int ) F_26 ( V_74 ) / ( V_73 >> 9 ) ;
if ( V_57 > 0xffff ) {
V_57 = 0xffff ;
V_56 -> V_92 . V_91 = V_57 * V_73 ;
}
V_56 -> V_81 [ 2 ] = ( unsigned char ) ( V_72 >> 24 ) & 0xff ;
V_56 -> V_81 [ 3 ] = ( unsigned char ) ( V_72 >> 16 ) & 0xff ;
V_56 -> V_81 [ 4 ] = ( unsigned char ) ( V_72 >> 8 ) & 0xff ;
V_56 -> V_81 [ 5 ] = ( unsigned char ) V_72 & 0xff ;
V_56 -> V_81 [ 6 ] = V_56 -> V_81 [ 9 ] = 0 ;
V_56 -> V_81 [ 7 ] = ( unsigned char ) ( V_57 >> 8 ) & 0xff ;
V_56 -> V_81 [ 8 ] = ( unsigned char ) V_57 & 0xff ;
V_56 -> V_94 = V_8 -> V_6 -> V_69 ;
V_56 -> V_95 = V_57 << 9 ;
V_56 -> V_96 = V_29 ;
V_45 = V_75 ;
V_12:
return V_45 ;
}
static int F_40 ( struct V_97 * V_98 , T_2 V_99 )
{
struct V_1 * V_8 ;
int V_45 = - V_100 ;
F_5 ( & V_101 ) ;
V_8 = F_4 ( V_98 -> V_102 ) ;
if ( V_8 ) {
V_45 = F_41 ( & V_8 -> V_39 , V_98 , V_99 ) ;
if ( V_45 )
F_10 ( V_8 ) ;
}
F_9 ( & V_101 ) ;
return V_45 ;
}
static void F_42 ( struct V_2 * V_3 , T_2 V_99 )
{
struct V_1 * V_8 = V_1 ( V_3 ) ;
F_5 ( & V_101 ) ;
F_43 ( & V_8 -> V_39 , V_99 ) ;
F_10 ( V_8 ) ;
F_9 ( & V_101 ) ;
}
static int F_44 ( struct V_97 * V_98 , T_2 V_99 , unsigned V_18 ,
unsigned long V_103 )
{
struct V_1 * V_8 = V_1 ( V_98 -> V_102 ) ;
struct V_15 * V_16 = V_8 -> V_6 ;
void T_3 * V_104 = ( void T_3 * ) V_103 ;
int V_45 ;
F_5 ( & V_101 ) ;
V_45 = F_45 ( V_16 , V_18 ,
( V_99 & V_105 ) != 0 ) ;
if ( V_45 )
goto V_12;
switch ( V_18 ) {
case V_106 :
case V_107 :
V_45 = F_46 ( V_16 , V_18 , V_104 ) ;
goto V_12;
}
V_45 = F_47 ( & V_8 -> V_39 , V_98 , V_99 , V_18 , V_103 ) ;
if ( V_45 != - V_108 )
goto V_12;
V_45 = F_46 ( V_16 , V_18 , V_104 ) ;
V_12:
F_9 ( & V_101 ) ;
return V_45 ;
}
static unsigned int F_48 ( struct V_2 * V_3 ,
unsigned int V_40 )
{
struct V_1 * V_8 = V_1 ( V_3 ) ;
if ( F_49 ( & V_8 -> V_6 -> V_109 ) )
return 0 ;
return F_50 ( & V_8 -> V_39 , V_40 ) ;
}
static int F_51 ( struct V_2 * V_3 )
{
struct V_1 * V_8 = V_1 ( V_3 ) ;
struct V_24 V_25 ;
if ( F_17 ( V_8 -> V_6 , V_28 , V_29 , & V_25 ) )
goto V_12;
F_52 ( & V_8 -> V_39 ) ;
F_53 ( V_8 ) ;
V_12:
return 0 ;
}
static int F_54 ( struct V_38 * V_39 , int V_110 )
{
struct V_1 * V_8 = V_39 -> V_42 ;
struct V_15 * V_16 = V_8 -> V_6 ;
int V_111 ;
V_111 = - V_100 ;
if ( ! F_55 ( V_16 ) )
goto V_112;
return 0 ;
V_112:
return V_111 ;
}
static void F_56 ( struct V_38 * V_39 )
{
struct V_1 * V_8 = V_39 -> V_42 ;
if ( V_8 -> V_6 -> V_69 > 2048 )
F_35 ( V_8 , 2048 ) ;
}
static int F_57 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = F_58 ( V_7 ) ;
struct V_2 * V_3 ;
struct V_1 * V_8 ;
int V_113 , error ;
F_59 ( V_16 ) ;
error = - V_114 ;
if ( V_16 -> type != V_115 && V_16 -> type != V_116 )
goto V_117;
error = - V_118 ;
V_8 = F_60 ( sizeof( * V_8 ) , V_119 ) ;
if ( ! V_8 )
goto V_117;
F_61 ( & V_8 -> V_13 ) ;
V_3 = F_62 ( 1 ) ;
if ( ! V_3 )
goto V_120;
F_63 ( & V_121 ) ;
V_113 = F_64 ( V_122 , V_123 ) ;
if ( V_113 == V_123 ) {
F_65 ( & V_121 ) ;
error = - V_10 ;
goto V_124;
}
F_66 ( V_113 , V_122 ) ;
F_65 ( & V_121 ) ;
V_3 -> V_125 = V_126 ;
V_3 -> V_127 = V_113 ;
sprintf ( V_3 -> V_128 , L_14 , V_113 ) ;
V_3 -> V_129 = & V_130 ;
V_3 -> V_131 = V_132 | V_133 ;
V_3 -> V_44 = V_32 | V_37 ;
F_67 ( V_16 -> V_134 , V_28 ) ;
V_8 -> V_6 = V_16 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_5 = & V_135 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_70 = 0x1fffff ;
V_8 -> V_6 -> V_50 = 1 ;
V_8 -> V_9 = 1 ;
V_8 -> V_136 = 1 ;
V_8 -> V_137 = 0 ;
V_8 -> V_138 = 0 ;
V_8 -> V_39 . V_139 = & V_140 ;
V_8 -> V_39 . V_42 = V_8 ;
V_8 -> V_39 . V_141 = 0 ;
V_8 -> V_39 . V_70 = 1 ;
sprintf ( V_8 -> V_39 . V_142 , L_14 , V_113 ) ;
V_16 -> V_69 = 2048 ;
F_68 ( V_8 ) ;
F_69 ( V_8 ) ;
V_3 -> V_143 = & V_16 -> V_144 ;
F_28 ( V_3 , V_8 -> V_70 ) ;
V_3 -> V_4 = & V_8 -> V_5 ;
V_3 -> V_145 = V_16 -> V_134 ;
V_8 -> V_39 . V_3 = V_3 ;
if ( F_70 ( & V_8 -> V_39 ) )
goto V_124;
F_71 ( V_16 -> V_134 , V_7 ) ;
F_72 ( V_7 , V_8 ) ;
V_3 -> V_131 |= V_146 ;
F_73 ( V_3 ) ;
F_74 ( V_147 , V_16 ,
L_15 , V_8 -> V_39 . V_142 ) ;
F_75 ( V_8 -> V_6 ) ;
return 0 ;
V_124:
F_76 ( V_3 ) ;
V_120:
F_77 ( V_8 ) ;
V_117:
F_75 ( V_16 ) ;
return error ;
}
static void F_53 ( struct V_1 * V_8 )
{
unsigned char V_18 [ 10 ] ;
unsigned char V_148 [ 8 ] ;
int V_149 , V_150 = 3 ;
int V_69 ;
struct V_134 * V_145 ;
do {
V_18 [ 0 ] = V_151 ;
memset ( ( void * ) & V_18 [ 1 ] , 0 , 9 ) ;
memset ( V_148 , 0 , sizeof( V_148 ) ) ;
V_149 = F_13 ( V_8 -> V_6 , V_18 , V_27 ,
V_148 , sizeof( V_148 ) , NULL ,
V_28 , V_29 , NULL ) ;
V_150 -- ;
} while ( V_149 && V_150 );
if ( V_149 ) {
V_8 -> V_70 = 0x1fffff ;
V_69 = 2048 ;
} else {
long V_152 ;
V_8 -> V_70 = 1 + ( ( V_148 [ 0 ] << 24 ) | ( V_148 [ 1 ] << 16 ) |
( V_148 [ 2 ] << 8 ) | V_148 [ 3 ] ) ;
if ( ! F_78 ( & V_8 -> V_39 , & V_152 ) )
V_8 -> V_70 = F_79 ( long , V_8 -> V_70 , V_152 ) ;
V_69 = ( V_148 [ 4 ] << 24 ) |
( V_148 [ 5 ] << 16 ) | ( V_148 [ 6 ] << 8 ) | V_148 [ 7 ] ;
switch ( V_69 ) {
case 0 :
case 2340 :
case 2352 :
V_69 = 2048 ;
case 2048 :
V_8 -> V_70 *= 4 ;
case 512 :
break;
default:
F_19 ( V_63 , V_8 ,
L_16 , V_69 ) ;
V_8 -> V_70 = 0 ;
}
V_8 -> V_6 -> V_69 = V_69 ;
F_28 ( V_8 -> V_3 , V_8 -> V_70 ) ;
}
V_145 = V_8 -> V_6 -> V_134 ;
F_80 ( V_145 , V_69 ) ;
return;
}
static void F_68 ( struct V_1 * V_8 )
{
unsigned char * V_148 ;
struct V_153 V_154 ;
struct V_24 V_25 ;
int V_155 , V_156 ;
static const char * V_157 [] =
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
V_148 = F_81 ( 512 , V_119 | V_158 ) ;
if ( ! V_148 ) {
F_19 ( V_78 , V_8 , L_23 ) ;
return;
}
F_17 ( V_8 -> V_6 , V_28 , V_29 , & V_25 ) ;
V_155 = F_82 ( V_8 -> V_6 , 0 , 0x2a , V_148 , 128 ,
V_28 , 3 , & V_154 , NULL ) ;
if ( ! F_18 ( V_155 ) ) {
V_8 -> V_39 . V_159 = 1 ;
V_8 -> V_39 . V_141 |= ( V_160 | V_161 | V_162 |
V_163 | V_164 |
V_165 | V_166 |
V_167 | V_168 | V_169 ) ;
F_77 ( V_148 ) ;
F_19 ( V_63 , V_8 , L_24 ) ;
return;
}
V_156 = V_154 . V_170 + V_154 . V_171 ;
V_8 -> V_39 . V_159 = ( ( V_148 [ V_156 + 8 ] << 8 ) + V_148 [ V_156 + 9 ] ) / 176 ;
V_8 -> V_137 = 1 ;
V_8 -> V_138 = V_148 [ V_156 + 5 ] & 0x01 ;
F_19 ( V_63 , V_8 ,
L_25 ,
( ( V_148 [ V_156 + 14 ] << 8 ) + V_148 [ V_156 + 15 ] ) / 176 ,
V_8 -> V_39 . V_159 ,
V_148 [ V_156 + 3 ] & 0x01 ? L_26 : L_20 ,
V_148 [ V_156 + 3 ] & 0x20 ? L_27 : L_20 ,
V_148 [ V_156 + 2 ] & 0x02 ? L_28 : L_20 ,
V_148 [ V_156 + 4 ] & 0x20 ? L_29 : L_20 ,
V_148 [ V_156 + 5 ] & 0x01 ? L_30 : L_20 ,
V_157 [ V_148 [ V_156 + 6 ] >> 5 ] ) ;
if ( ( V_148 [ V_156 + 6 ] >> 5 ) == 0 )
V_8 -> V_39 . V_141 |= V_172 ;
if ( ( V_148 [ V_156 + 2 ] & 0x8 ) == 0 )
V_8 -> V_39 . V_141 |= V_163 ;
if ( ( V_148 [ V_156 + 3 ] & 0x20 ) == 0 )
V_8 -> V_39 . V_141 |= V_164 ;
if ( ( V_148 [ V_156 + 3 ] & 0x10 ) == 0 )
V_8 -> V_39 . V_141 |= V_162 ;
if ( ( V_148 [ V_156 + 3 ] & 0x2 ) == 0 )
V_8 -> V_39 . V_141 |= V_161 ;
if ( ( V_148 [ V_156 + 3 ] & 0x1 ) == 0 )
V_8 -> V_39 . V_141 |= V_160 ;
if ( ( V_148 [ V_156 + 6 ] & 0x8 ) == 0 )
V_8 -> V_39 . V_141 |= V_173 ;
if ( ( V_148 [ V_156 + 6 ] >> 5 ) == V_174 ||
( V_148 [ V_156 + 6 ] >> 5 ) == V_175 )
V_8 -> V_39 . V_70 =
F_83 ( & V_8 -> V_39 ) ;
if ( V_8 -> V_39 . V_70 <= 1 )
V_8 -> V_39 . V_141 |= V_165 ;
if ( ( V_8 -> V_39 . V_141 & ( V_164 | V_168 | V_169 | V_161 ) ) !=
( V_164 | V_168 | V_169 | V_161 ) ) {
V_8 -> V_80 = 1 ;
}
F_77 ( V_148 ) ;
}
static int F_84 ( struct V_38 * V_39 ,
struct V_176 * V_177 )
{
struct V_1 * V_8 = V_39 -> V_42 ;
struct V_15 * V_16 = V_8 -> V_6 ;
if ( V_177 -> V_18 [ 0 ] == V_178 && V_16 -> V_179 )
return - V_180 ;
if ( V_177 -> V_181 <= 0 )
V_177 -> V_181 = V_182 ;
F_85 ( V_8 , V_177 ) ;
return V_177 -> V_183 ;
}
static void V_14 ( struct V_13 * V_13 )
{
struct V_1 * V_8 = F_1 ( V_13 , struct V_1 , V_13 ) ;
struct V_2 * V_3 = V_8 -> V_3 ;
F_63 ( & V_121 ) ;
F_86 ( F_87 ( F_88 ( V_3 ) ) , V_122 ) ;
F_65 ( & V_121 ) ;
F_89 ( & V_8 -> V_39 ) ;
V_3 -> V_4 = NULL ;
F_76 ( V_3 ) ;
F_77 ( V_8 ) ;
}
static int F_90 ( struct V_6 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
F_59 ( V_8 -> V_6 ) ;
F_91 ( V_8 -> V_3 ) ;
F_72 ( V_7 , NULL ) ;
F_5 ( & V_11 ) ;
F_8 ( & V_8 -> V_13 , V_14 ) ;
F_9 ( & V_11 ) ;
return 0 ;
}
static int T_4 F_92 ( void )
{
int V_155 ;
V_155 = F_93 ( V_126 , L_31 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_94 ( & V_135 . V_184 ) ;
if ( V_155 )
F_95 ( V_126 , L_31 ) ;
return V_155 ;
}
static void T_5 F_96 ( void )
{
F_97 ( & V_135 . V_184 ) ;
F_95 ( V_126 , L_31 ) ;
}

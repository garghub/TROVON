static inline unsigned int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
int V_3 , unsigned long V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_6 * V_7 , int V_8 ,
unsigned int V_9 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_10 = V_2 -> V_11 ;
struct V_12 * V_13 = V_7 -> V_14 ;
if ( V_9 & V_15 ) {
if ( ( V_9 & V_16 ) == V_16 )
V_10 |= V_2 -> V_17 ;
else if ( ( V_9 & V_18 ) == V_18 )
V_10 |= V_2 -> V_19 ;
V_13 -> V_20 = ( void V_21 V_22 * ) V_10 ;
}
if ( V_8 != V_23 )
F_7 ( V_8 , V_13 -> V_20 ) ;
}
static void F_8 ( struct V_6 * V_7 , int V_24 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_10 = V_2 -> V_25 ;
if ( V_24 > 0 )
V_10 |= V_2 -> V_26 ;
V_2 -> V_11 = V_10 ;
V_2 -> V_24 . V_20 = ( void V_21 V_22 * ) V_10 ;
V_2 -> V_24 . V_27 = V_2 -> V_24 . V_20 ;
}
static inline T_1 F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return F_1 ( V_2 , V_28
+ 4 * V_2 -> V_29 ) ;
}
static void F_10 ( struct V_6 * V_7 , int V_30 )
{
struct V_1 * V_2 ;
T_1 V_31 ;
unsigned long V_32 ;
V_2 = F_6 ( V_7 ) ;
F_9 ( V_7 ) ;
F_11 ( & V_33 , V_32 ) ;
V_31 = F_1 ( V_2 , V_34 ) ;
V_31 |= F_12 ( 8 + V_2 -> V_29 ) ;
F_3 ( V_2 , V_34 , V_31 ) ;
F_13 ( & V_33 , V_32 ) ;
}
static int F_14 ( struct V_6 * V_7 ,
const T_2 * V_35 , T_2 * V_36 )
{
unsigned int V_37 = F_9 ( V_7 ) ;
unsigned int V_38 = ( V_37 & 0x0fff ) | ( ( V_37 & 0x0fff0000 ) >> 4 ) ;
V_38 = ~ V_38 ;
V_36 [ 0 ] = ( T_2 ) ( V_38 ) ;
V_36 [ 1 ] = ( T_2 ) ( V_38 >> 8 ) ;
V_36 [ 2 ] = ( T_2 ) ( V_38 >> 16 ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 , T_2 * V_35 ,
T_2 * V_39 , T_2 * V_40 )
{
struct V_12 * V_24 = V_7 -> V_14 ;
T_1 V_41 = V_39 [ 0 ] | ( V_39 [ 1 ] << 8 ) |
( V_39 [ 2 ] << 16 ) ;
T_1 V_42 = V_40 [ 0 ] | ( V_40 [ 1 ] << 8 ) |
( V_40 [ 2 ] << 16 ) ;
T_1 V_43 = V_42 ^ V_41 ;
if ( V_43 ) {
if ( ( ( ( V_43 >> 12 ) ^ V_43 ) & 0xfff ) == 0xfff ) {
if ( ( V_43 >> ( 12 + 3 ) ) < V_24 -> V_44 . V_45 ) {
V_35 [ V_43 >> ( 12 + 3 ) ] ^= F_12 ( ( V_43 >> 12 ) & 7 ) ;
return 1 ;
} else {
return - 1 ;
}
} else if ( ! ( V_43 & ( V_43 - 1 ) ) ) {
return 1 ;
} else {
return - 1 ;
}
}
return 0 ;
}
static void F_16 ( struct V_6 * V_7 , int V_30 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned long V_32 ;
T_3 V_46 ;
F_11 ( & V_33 , V_32 ) ;
V_46 = F_1 ( V_2 , V_34 ) ;
V_46 &= ~ ( 0x03 << 4 ) ;
V_46 |= ( V_2 -> V_29 << 4 ) | F_12 ( 12 ) ;
F_3 ( V_2 , V_34 , V_46 ) ;
V_2 -> V_47 = ( V_30 == V_48 ) ;
F_13 ( & V_33 , V_32 ) ;
}
static void
F_17 ( struct V_1 * V_2 , T_3 V_49 [ 4 ] )
{
const T_3 V_50 = 0x03ff03ff ;
V_49 [ 0 ] = F_1 ( V_2 , V_51 ) & V_50 ;
V_49 [ 1 ] = F_1 ( V_2 , V_52 ) & V_50 ;
V_49 [ 2 ] = F_1 ( V_2 , V_53 ) & V_50 ;
V_49 [ 3 ] = F_1 ( V_2 , V_54 ) & V_50 ;
}
static int F_18 ( struct V_6 * V_7 ,
const T_2 * V_35 , T_2 * V_36 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_3 V_55 [ 4 ] , * V_56 ;
unsigned V_57 ;
if ( V_2 -> V_47 ) {
F_1 ( V_2 , V_51 ) ;
return 0 ;
}
F_17 ( V_2 , V_55 ) ;
for ( V_57 = 0 , V_56 = V_55 ; V_57 < 2 ; V_57 ++ , V_56 += 2 ) {
* V_36 ++ = V_56 [ 0 ] & 0xff ;
* V_36 ++ = ( ( V_56 [ 0 ] >> 8 ) & 0x03 ) | ( ( V_56 [ 0 ] >> 14 ) & 0xfc ) ;
* V_36 ++ = ( ( V_56 [ 0 ] >> 22 ) & 0x0f ) | ( ( V_56 [ 1 ] << 4 ) & 0xf0 ) ;
* V_36 ++ = ( ( V_56 [ 1 ] >> 4 ) & 0x3f ) | ( ( V_56 [ 1 ] >> 10 ) & 0xc0 ) ;
* V_36 ++ = ( V_56 [ 1 ] >> 18 ) & 0xff ;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 ,
T_2 * V_58 , T_2 * V_36 , T_2 * null )
{
int V_57 ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
unsigned short V_59 [ 8 ] ;
unsigned short * V_60 ;
T_3 V_61 [ 4 ] ;
T_3 V_62 ;
unsigned V_63 , V_64 ;
unsigned long V_65 ;
for ( V_57 = 0 ; V_57 < 10 ; V_57 ++ ) {
if ( V_36 [ V_57 ] != 0xff )
goto V_66;
}
return 0 ;
V_66:
if ( F_20 ( 0x01 & ( unsigned ) V_36 ) )
return - V_67 ;
V_60 = ( unsigned short * ) V_36 ;
V_59 [ 0 ] = ( V_60 [ 0 ] >> 0 ) & 0x3ff ;
V_59 [ 1 ] = ( ( V_60 [ 0 ] >> 10 ) & 0x3f ) | ( ( V_60 [ 1 ] << 6 ) & 0x3c0 ) ;
V_59 [ 2 ] = ( V_60 [ 1 ] >> 4 ) & 0x3ff ;
V_59 [ 3 ] = ( ( V_60 [ 1 ] >> 14 ) & 0x3 ) | ( ( V_60 [ 2 ] << 2 ) & 0x3fc ) ;
V_59 [ 4 ] = ( V_60 [ 2 ] >> 8 ) | ( ( V_60 [ 3 ] << 8 ) & 0x300 ) ;
V_59 [ 5 ] = ( V_60 [ 3 ] >> 2 ) & 0x3ff ;
V_59 [ 6 ] = ( ( V_60 [ 3 ] >> 12 ) & 0xf ) | ( ( V_60 [ 4 ] << 4 ) & 0x3f0 ) ;
V_59 [ 7 ] = ( V_60 [ 4 ] >> 6 ) & 0x3ff ;
for ( V_57 = 7 ; V_57 >= 0 ; V_57 -- )
F_3 ( V_2 , V_68 , V_59 [ V_57 ] ) ;
F_1 ( V_2 , V_69 ) ;
F_17 ( V_2 , V_61 ) ;
if ( ! ( V_61 [ 0 ] | V_61 [ 1 ] | V_61 [ 2 ] | V_61 [ 3 ] ) )
return 0 ;
F_1 ( V_2 , V_70 ) ;
F_3 ( V_2 , V_34 ,
F_1 ( V_2 , V_34 ) | F_12 ( 13 ) ) ;
V_65 = V_71 + F_21 ( 100 ) ;
do {
V_62 = ( F_1 ( V_2 ,
V_69 ) >> 8 ) & 0x0f ;
F_22 () ;
} while ( ( V_62 < 4 ) && F_23 ( V_71 , V_65 ) );
for (; ; ) {
T_3 V_72 = F_1 ( V_2 , V_69 ) ;
switch ( ( V_72 >> 8 ) & 0x0f ) {
case 0 :
F_1 ( V_2 , V_73 ) ;
return 0 ;
case 1 :
F_1 ( V_2 , V_73 ) ;
return - V_74 ;
case 2 :
case 3 :
V_63 = 1 + ( ( V_72 >> 16 ) & 0x03 ) ;
goto V_75;
default:
F_22 () ;
continue;
}
}
V_75:
for ( V_57 = 0 , V_64 = 0 ; V_57 < V_63 ; V_57 ++ ) {
int V_76 , V_77 ;
if ( V_57 > 1 ) {
V_76 = F_1 ( V_2 ,
V_78 ) ;
V_77 = F_1 ( V_2 ,
V_79 ) ;
} else {
V_76 = F_1 ( V_2 ,
V_70 ) ;
V_77 = F_1 ( V_2 ,
V_73 ) ;
}
if ( V_57 & 1 ) {
V_76 >>= 16 ;
V_77 >>= 16 ;
}
V_76 &= 0x3ff ;
V_76 = ( 512 + 7 ) - V_76 ;
if ( V_76 < 512 ) {
V_58 [ V_76 ] ^= V_77 ;
V_64 ++ ;
}
}
return V_64 ;
}
static void F_24 ( struct V_6 * V_7 , T_4 * V_80 , int V_81 )
{
struct V_12 * V_24 = V_7 -> V_14 ;
if ( ( 0x03 & ( ( unsigned ) V_80 ) ) == 0 && ( 0x03 & V_81 ) == 0 )
F_25 ( V_24 -> V_27 , V_80 , V_81 >> 2 ) ;
else if ( ( 0x01 & ( ( unsigned ) V_80 ) ) == 0 && ( 0x01 & V_81 ) == 0 )
F_26 ( V_24 -> V_27 , V_80 , V_81 >> 1 ) ;
else
F_27 ( V_24 -> V_27 , V_80 , V_81 ) ;
}
static void F_28 ( struct V_6 * V_7 ,
const T_4 * V_80 , int V_81 )
{
struct V_12 * V_24 = V_7 -> V_14 ;
if ( ( 0x03 & ( ( unsigned ) V_80 ) ) == 0 && ( 0x03 & V_81 ) == 0 )
F_29 ( V_24 -> V_27 , V_80 , V_81 >> 2 ) ;
else if ( ( 0x01 & ( ( unsigned ) V_80 ) ) == 0 && ( 0x01 & V_81 ) == 0 )
F_30 ( V_24 -> V_27 , V_80 , V_81 >> 1 ) ;
else
F_31 ( V_24 -> V_27 , V_80 , V_81 ) ;
}
static int F_32 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
return F_1 ( V_2 , V_69 ) & F_12 ( 0 ) ;
}
static struct V_82
* F_33 ( struct V_83 * V_84 )
{
if ( ! V_84 -> V_85 . V_86 && V_84 -> V_85 . V_87 ) {
struct V_82 * V_88 ;
const char * V_30 ;
T_3 V_89 ;
int V_81 ;
V_88 = F_34 ( & V_84 -> V_85 ,
sizeof( struct V_82 ) ,
V_90 ) ;
V_84 -> V_85 . V_86 = V_88 ;
if ( ! V_88 )
return NULL ;
if ( ! F_35 ( V_84 -> V_85 . V_87 ,
L_1 , & V_89 ) )
V_84 -> V_91 = V_89 ;
if ( ! F_35 ( V_84 -> V_85 . V_87 ,
L_2 , & V_89 ) )
V_88 -> V_19 = V_89 ;
if ( ! F_35 ( V_84 -> V_85 . V_87 ,
L_3 , & V_89 ) )
V_88 -> V_17 = V_89 ;
if ( ! F_35 ( V_84 -> V_85 . V_87 ,
L_4 , & V_89 ) )
V_88 -> V_26 = V_89 ;
if ( ! F_36 ( V_84 -> V_85 . V_87 ,
L_5 , & V_30 ) ) {
if ( ! strncmp ( L_6 , V_30 , 4 ) )
V_88 -> V_92 = V_93 ;
if ( ! strncmp ( L_7 , V_30 , 4 ) )
V_88 -> V_92 = V_94 ;
if ( ! strncmp ( L_8 , V_30 , 2 ) )
V_88 -> V_92 = V_95 ;
}
if ( ! F_35 ( V_84 -> V_85 . V_87 ,
L_9 , & V_89 ) )
V_88 -> V_96 = V_89 ;
if ( ! F_35 ( V_84 -> V_85 . V_87 ,
L_10 , & V_89 ) )
if ( V_89 == 16 )
V_88 -> V_97 |= V_98 ;
if ( F_37 ( V_84 -> V_85 . V_87 ,
L_11 , & V_81 ) )
V_88 -> V_99 = V_100 ;
}
return V_84 -> V_85 . V_86 ;
}
static struct V_82
* F_33 ( struct V_83 * V_84 )
{
return V_84 -> V_85 . V_86 ;
}
static int T_5 F_38 ( struct V_83 * V_84 )
{
struct V_82 * V_88 ;
struct V_1 * V_2 ;
struct V_101 * V_102 ;
struct V_101 * V_103 ;
void V_21 * V_104 ;
void V_21 * V_4 ;
int V_105 ;
T_1 V_46 ;
T_6 V_92 ;
V_88 = F_33 ( V_84 ) ;
if ( ! V_88 )
return - V_106 ;
if ( V_84 -> V_91 < 0 || V_84 -> V_91 > 3 )
return - V_106 ;
V_2 = F_34 ( & V_84 -> V_85 , sizeof( * V_2 ) , V_90 ) ;
if ( ! V_2 ) {
F_39 ( & V_84 -> V_85 , L_12 ) ;
V_105 = - V_107 ;
goto V_108;
}
F_40 ( V_84 , V_2 ) ;
V_102 = F_41 ( V_84 , V_109 , 0 ) ;
V_103 = F_41 ( V_84 , V_109 , 1 ) ;
if ( ! V_102 || ! V_103 ) {
F_39 ( & V_84 -> V_85 , L_13 ) ;
V_105 = - V_67 ;
goto V_108;
}
V_104 = F_42 ( & V_84 -> V_85 , V_102 ) ;
V_4 = F_42 ( & V_84 -> V_85 , V_103 ) ;
if ( ! V_104 || ! V_4 ) {
F_39 ( & V_84 -> V_85 , L_14 ) ;
V_105 = - V_110 ;
goto V_111;
}
V_2 -> V_85 = & V_84 -> V_85 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_104 = V_104 ;
V_2 -> V_7 . V_14 = & V_2 -> V_24 ;
V_2 -> V_7 . V_112 = F_43 ( & V_84 -> V_85 ) ;
V_2 -> V_7 . V_113 = V_114 ;
V_2 -> V_7 . V_85 . V_115 = & V_84 -> V_85 ;
V_2 -> V_24 . V_27 = V_104 ;
V_2 -> V_24 . V_20 = V_104 ;
V_2 -> V_24 . V_116 = 0 ;
V_2 -> V_24 . V_117 = F_8 ;
V_2 -> V_24 . V_99 = V_88 -> V_99 ;
V_2 -> V_24 . V_97 = V_88 -> V_97 ;
V_2 -> V_24 . V_118 = V_88 -> V_118 ;
V_2 -> V_24 . V_119 = V_88 -> V_119 ;
V_2 -> V_120 = V_88 -> V_120 ;
V_2 -> V_25 = ( T_1 V_22 ) V_104 ;
V_2 -> V_11 = V_2 -> V_25 ;
V_2 -> V_29 = V_84 -> V_91 ;
V_2 -> V_26 = V_88 -> V_26 ;
V_2 -> V_19 = V_88 -> V_19 ? : V_121 ;
V_2 -> V_17 = V_88 -> V_17 ? : V_122 ;
V_2 -> V_24 . V_123 = F_5 ;
V_2 -> V_24 . V_124 = F_32 ;
V_2 -> V_24 . V_125 = F_24 ;
V_2 -> V_24 . V_126 = F_28 ;
V_92 = V_88 -> V_92 ;
V_105 = - V_67 ;
switch ( V_92 ) {
case V_93 :
case V_94 :
V_88 -> V_96 = 0 ;
break;
case V_95 :
if ( V_88 -> V_96 == 4 ) {
F_44 ( & V_33 ) ;
if ( V_127 )
V_105 = - V_128 ;
else
V_127 = true ;
F_45 ( & V_33 ) ;
if ( V_105 == - V_128 )
goto V_129;
V_2 -> V_24 . V_44 . V_130 = F_18 ;
V_2 -> V_24 . V_44 . V_75 = F_19 ;
V_2 -> V_24 . V_44 . V_131 = F_16 ;
V_2 -> V_24 . V_44 . V_132 = 10 ;
} else {
V_2 -> V_24 . V_44 . V_130 = F_14 ;
V_2 -> V_24 . V_44 . V_75 = F_15 ;
V_2 -> V_24 . V_44 . V_131 = F_10 ;
V_2 -> V_24 . V_44 . V_132 = 3 ;
}
V_2 -> V_24 . V_44 . V_45 = 512 ;
V_2 -> V_24 . V_44 . V_133 = V_88 -> V_96 ;
break;
default:
V_105 = - V_67 ;
goto V_129;
}
V_2 -> V_24 . V_44 . V_30 = V_92 ;
V_2 -> V_134 = F_46 ( & V_84 -> V_85 , L_15 ) ;
if ( F_47 ( V_2 -> V_134 ) ) {
V_105 = F_48 ( V_2 -> V_134 ) ;
F_49 ( & V_84 -> V_85 , L_16 , V_105 ) ;
goto V_135;
}
V_105 = F_50 ( V_2 -> V_134 ) ;
if ( V_105 < 0 ) {
F_49 ( & V_84 -> V_85 , L_17 ,
V_105 ) ;
goto V_136;
}
V_46 = F_1 ( V_2 , V_137 + V_2 -> V_29 * 4 ) ;
V_46 &= ~ ( V_138 | V_139 | V_140 ) ;
if ( V_2 -> V_24 . V_97 & V_98 )
V_46 |= 0x1 ;
F_3 ( V_2 , V_137 + V_2 -> V_29 * 4 , V_46 ) ;
V_105 = 0 ;
if ( V_2 -> V_120 )
V_105 = F_51 ( V_2 -> V_120 , V_2 -> V_4 ,
V_2 -> V_29 ) ;
if ( V_105 < 0 ) {
F_49 ( & V_84 -> V_85 , L_18 ) ;
goto V_141;
}
F_44 ( & V_33 ) ;
V_46 = F_1 ( V_2 , V_34 ) ;
V_46 |= F_12 ( V_2 -> V_29 ) ;
F_3 ( V_2 , V_34 , V_46 ) ;
F_45 ( & V_33 ) ;
V_105 = F_52 ( & V_2 -> V_7 , V_88 -> V_26 ? 2 : 1 , NULL ) ;
if ( V_105 < 0 ) {
F_49 ( & V_84 -> V_85 , L_19 ) ;
goto V_142;
}
if ( V_88 -> V_96 == 4 ) {
int V_143 = V_2 -> V_7 . V_144 / 512 ;
if ( ! V_143 || V_2 -> V_7 . V_145 < 16 ) {
F_49 ( & V_84 -> V_85 , L_20 ) ;
V_105 = - V_67 ;
goto V_142;
}
if ( V_143 == 1 ) {
V_2 -> V_146 = V_147 ;
V_2 -> V_146 . V_148 [ 1 ] . V_149 =
V_2 -> V_7 . V_145 - 16 ;
goto V_150;
}
if ( V_143 == 4 ) {
V_2 -> V_146 = V_151 ;
V_2 -> V_24 . V_44 . V_30 = V_152 ;
goto V_150;
}
F_53 ( & V_84 -> V_85 , L_21
L_22 ) ;
V_105 = - V_74 ;
goto V_142;
V_150:
V_2 -> V_24 . V_44 . V_153 = & V_2 -> V_146 ;
}
V_105 = F_54 ( & V_2 -> V_7 ) ;
if ( V_105 < 0 )
goto V_142;
if ( V_88 -> V_154 )
V_105 = F_55 ( & V_2 -> V_7 , NULL , NULL ,
V_88 -> V_154 , V_88 -> V_155 ) ;
else {
struct V_156 V_157 ;
V_157 . V_87 = V_84 -> V_85 . V_87 ;
V_105 = F_55 ( & V_2 -> V_7 , NULL , & V_157 ,
NULL , 0 ) ;
}
if ( V_105 < 0 )
goto V_142;
V_46 = F_1 ( V_2 , V_158 ) ;
F_56 ( & V_84 -> V_85 , L_23 ,
( V_46 >> 8 ) & 0xff , V_46 & 0xff ) ;
return 0 ;
V_142:
V_141:
F_57 ( V_2 -> V_134 ) ;
V_136:
F_44 ( & V_33 ) ;
if ( V_92 == V_159 )
V_127 = false ;
F_45 ( & V_33 ) ;
V_129:
V_135:
V_111:
V_108:
return V_105 ;
}
static int T_7 F_58 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_59 ( V_84 ) ;
F_44 ( & V_33 ) ;
if ( V_2 -> V_24 . V_44 . V_30 == V_159 )
V_127 = false ;
F_45 ( & V_33 ) ;
F_60 ( & V_2 -> V_7 ) ;
F_57 ( V_2 -> V_134 ) ;
return 0 ;
}
static int T_5 F_61 ( void )
{
return F_62 ( & V_160 , F_38 ) ;
}
static void T_7 F_63 ( void )
{
F_64 ( & V_160 ) ;
}

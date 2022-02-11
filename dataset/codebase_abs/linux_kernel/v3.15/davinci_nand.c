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
if ( ! F_34 ( & V_84 -> V_85 ) && V_84 -> V_85 . V_86 ) {
struct V_82 * V_87 ;
const char * V_30 ;
T_3 V_88 ;
V_87 = F_35 ( & V_84 -> V_85 ,
sizeof( struct V_82 ) ,
V_89 ) ;
V_84 -> V_85 . V_90 = V_87 ;
if ( ! V_87 )
return F_36 ( - V_91 ) ;
if ( ! F_37 ( V_84 -> V_85 . V_86 ,
L_1 , & V_88 ) )
V_84 -> V_92 = V_88 ;
else
return F_36 ( - V_67 ) ;
if ( ! F_37 ( V_84 -> V_85 . V_86 ,
L_2 , & V_88 ) )
V_87 -> V_19 = V_88 ;
if ( ! F_37 ( V_84 -> V_85 . V_86 ,
L_3 , & V_88 ) )
V_87 -> V_17 = V_88 ;
if ( ! F_37 ( V_84 -> V_85 . V_86 ,
L_4 , & V_88 ) )
V_87 -> V_26 = V_88 ;
if ( ! F_38 ( V_84 -> V_85 . V_86 ,
L_5 , & V_30 ) ||
! F_38 ( V_84 -> V_85 . V_86 ,
L_6 , & V_30 ) ) {
if ( ! strncmp ( L_7 , V_30 , 4 ) )
V_87 -> V_93 = V_94 ;
if ( ! strncmp ( L_8 , V_30 , 4 ) )
V_87 -> V_93 = V_95 ;
if ( ! strncmp ( L_9 , V_30 , 2 ) )
V_87 -> V_93 = V_96 ;
}
if ( ! F_37 ( V_84 -> V_85 . V_86 ,
L_10 , & V_88 ) )
V_87 -> V_97 = V_88 ;
V_88 = F_39 ( V_84 -> V_85 . V_86 ) ;
if ( 0 < V_88 || ! F_37 ( V_84 -> V_85 . V_86 ,
L_11 , & V_88 ) )
if ( V_88 == 16 )
V_87 -> V_98 |= V_99 ;
if ( F_40 ( V_84 -> V_85 . V_86 ,
L_12 ) ||
F_40 ( V_84 -> V_85 . V_86 ,
L_13 ) )
V_87 -> V_100 = V_101 ;
if ( F_41 ( V_84 -> V_85 . V_86 ,
L_14 ) ) {
V_87 -> V_98 |= V_102 ;
}
}
return F_34 ( & V_84 -> V_85 ) ;
}
static struct V_82
* F_33 ( struct V_83 * V_84 )
{
return F_34 ( & V_84 -> V_85 ) ;
}
static int F_42 ( struct V_83 * V_84 )
{
struct V_82 * V_87 ;
struct V_1 * V_2 ;
struct V_103 * V_104 ;
struct V_103 * V_105 ;
void V_21 * V_106 ;
void V_21 * V_4 ;
int V_107 ;
T_1 V_46 ;
T_5 V_93 ;
V_87 = F_33 ( V_84 ) ;
if ( F_43 ( V_87 ) )
return F_44 ( V_87 ) ;
if ( ! V_87 )
return - V_108 ;
if ( V_84 -> V_92 < 0 || V_84 -> V_92 > 3 )
return - V_108 ;
V_2 = F_35 ( & V_84 -> V_85 , sizeof( * V_2 ) , V_89 ) ;
if ( ! V_2 )
return - V_91 ;
F_45 ( V_84 , V_2 ) ;
V_104 = F_46 ( V_84 , V_109 , 0 ) ;
V_105 = F_46 ( V_84 , V_109 , 1 ) ;
if ( ! V_104 || ! V_105 ) {
F_47 ( & V_84 -> V_85 , L_15 ) ;
return - V_67 ;
}
V_106 = F_48 ( & V_84 -> V_85 , V_104 ) ;
if ( F_43 ( V_106 ) )
return F_44 ( V_106 ) ;
V_4 = F_49 ( & V_84 -> V_85 , V_105 -> V_110 , F_50 ( V_105 ) ) ;
if ( ! V_4 ) {
F_47 ( & V_84 -> V_85 , L_16 , V_105 ) ;
return - V_111 ;
}
V_2 -> V_85 = & V_84 -> V_85 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_106 = V_106 ;
V_2 -> V_7 . V_14 = & V_2 -> V_24 ;
V_2 -> V_7 . V_112 = F_51 ( & V_84 -> V_85 ) ;
V_2 -> V_7 . V_113 = V_114 ;
V_2 -> V_7 . V_85 . V_115 = & V_84 -> V_85 ;
V_2 -> V_24 . V_27 = V_106 ;
V_2 -> V_24 . V_20 = V_106 ;
V_2 -> V_24 . V_116 = 0 ;
V_2 -> V_24 . V_117 = F_8 ;
V_2 -> V_24 . V_100 = V_87 -> V_100 ;
V_2 -> V_24 . V_98 = V_87 -> V_98 ;
V_2 -> V_24 . V_118 = V_87 -> V_118 ;
V_2 -> V_24 . V_119 = V_87 -> V_119 ;
V_2 -> V_120 = V_87 -> V_120 ;
V_2 -> V_25 = ( T_1 V_22 ) V_106 ;
V_2 -> V_11 = V_2 -> V_25 ;
V_2 -> V_29 = V_84 -> V_92 ;
V_2 -> V_26 = V_87 -> V_26 ;
V_2 -> V_19 = V_87 -> V_19 ? : V_121 ;
V_2 -> V_17 = V_87 -> V_17 ? : V_122 ;
V_2 -> V_24 . V_123 = F_5 ;
V_2 -> V_24 . V_124 = F_32 ;
V_2 -> V_24 . V_125 = F_24 ;
V_2 -> V_24 . V_126 = F_28 ;
V_93 = V_87 -> V_93 ;
V_107 = - V_67 ;
switch ( V_93 ) {
case V_94 :
case V_95 :
V_87 -> V_97 = 0 ;
break;
case V_96 :
if ( V_87 -> V_97 == 4 ) {
F_52 ( & V_33 ) ;
if ( V_127 )
V_107 = - V_128 ;
else
V_127 = true ;
F_53 ( & V_33 ) ;
if ( V_107 == - V_128 )
return V_107 ;
V_2 -> V_24 . V_44 . V_129 = F_18 ;
V_2 -> V_24 . V_44 . V_75 = F_19 ;
V_2 -> V_24 . V_44 . V_130 = F_16 ;
V_2 -> V_24 . V_44 . V_131 = 10 ;
} else {
V_2 -> V_24 . V_44 . V_129 = F_14 ;
V_2 -> V_24 . V_44 . V_75 = F_15 ;
V_2 -> V_24 . V_44 . V_130 = F_10 ;
V_2 -> V_24 . V_44 . V_131 = 3 ;
}
V_2 -> V_24 . V_44 . V_45 = 512 ;
V_2 -> V_24 . V_44 . V_132 = V_87 -> V_97 ;
break;
default:
return - V_67 ;
}
V_2 -> V_24 . V_44 . V_30 = V_93 ;
V_2 -> V_133 = F_54 ( & V_84 -> V_85 , L_17 ) ;
if ( F_43 ( V_2 -> V_133 ) ) {
V_107 = F_44 ( V_2 -> V_133 ) ;
F_55 ( & V_84 -> V_85 , L_18 , V_107 ) ;
return V_107 ;
}
V_107 = F_56 ( V_2 -> V_133 ) ;
if ( V_107 < 0 ) {
F_55 ( & V_84 -> V_85 , L_19 ,
V_107 ) ;
goto V_134;
}
F_52 ( & V_33 ) ;
V_46 = F_1 ( V_2 , V_34 ) ;
V_46 |= F_12 ( V_2 -> V_29 ) ;
F_3 ( V_2 , V_34 , V_46 ) ;
F_53 ( & V_33 ) ;
V_107 = F_57 ( & V_2 -> V_7 , V_87 -> V_26 ? 2 : 1 , NULL ) ;
if ( V_107 < 0 ) {
F_55 ( & V_84 -> V_85 , L_20 ) ;
goto V_135;
}
if ( V_87 -> V_97 == 4 ) {
int V_136 = V_2 -> V_7 . V_137 / 512 ;
if ( ! V_136 || V_2 -> V_7 . V_138 < 16 ) {
F_55 ( & V_84 -> V_85 , L_21 ) ;
V_107 = - V_67 ;
goto V_135;
}
if ( V_136 == 1 ) {
V_2 -> V_139 = V_140 ;
V_2 -> V_139 . V_141 [ 1 ] . V_142 =
V_2 -> V_7 . V_138 - 16 ;
goto V_143;
}
if ( V_136 == 4 ) {
V_2 -> V_139 = V_144 ;
V_2 -> V_24 . V_44 . V_30 = V_145 ;
goto V_143;
}
F_58 ( & V_84 -> V_85 , L_22
L_23 ) ;
V_107 = - V_74 ;
goto V_135;
V_143:
V_2 -> V_24 . V_44 . V_146 = & V_2 -> V_139 ;
}
V_107 = F_59 ( & V_2 -> V_7 ) ;
if ( V_107 < 0 )
goto V_135;
if ( V_87 -> V_147 )
V_107 = F_60 ( & V_2 -> V_7 , NULL , NULL ,
V_87 -> V_147 , V_87 -> V_148 ) ;
else {
struct V_149 V_150 ;
V_150 . V_86 = V_84 -> V_85 . V_86 ;
V_107 = F_60 ( & V_2 -> V_7 , NULL , & V_150 ,
NULL , 0 ) ;
}
if ( V_107 < 0 )
goto V_135;
V_46 = F_1 ( V_2 , V_151 ) ;
F_61 ( & V_84 -> V_85 , L_24 ,
( V_46 >> 8 ) & 0xff , V_46 & 0xff ) ;
return 0 ;
V_135:
F_62 ( V_2 -> V_133 ) ;
V_134:
F_52 ( & V_33 ) ;
if ( V_93 == V_152 )
V_127 = false ;
F_53 ( & V_33 ) ;
return V_107 ;
}
static int F_63 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_64 ( V_84 ) ;
F_52 ( & V_33 ) ;
if ( V_2 -> V_24 . V_44 . V_30 == V_152 )
V_127 = false ;
F_53 ( & V_33 ) ;
F_65 ( & V_2 -> V_7 ) ;
F_62 ( V_2 -> V_133 ) ;
return 0 ;
}

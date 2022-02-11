static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( F_3 ( V_3 ) , struct V_1 , V_4 ) ;
}
static inline unsigned int F_4 ( struct V_1 * V_5 ,
int V_6 )
{
return F_5 ( V_5 -> V_7 + V_6 ) ;
}
static inline void F_6 ( struct V_1 * V_5 ,
int V_6 , unsigned long V_8 )
{
F_7 ( V_8 , V_5 -> V_7 + V_6 ) ;
}
static void F_8 ( struct V_2 * V_3 , int V_9 ,
unsigned int V_10 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_11 = V_5 -> V_12 ;
struct V_13 * V_14 = F_3 ( V_3 ) ;
if ( V_10 & V_15 ) {
if ( ( V_10 & V_16 ) == V_16 )
V_11 |= V_5 -> V_17 ;
else if ( ( V_10 & V_18 ) == V_18 )
V_11 |= V_5 -> V_19 ;
V_14 -> V_20 = ( void V_21 V_22 * ) V_11 ;
}
if ( V_9 != V_23 )
F_9 ( V_9 , V_14 -> V_20 ) ;
}
static void F_10 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_11 = V_5 -> V_24 ;
if ( V_4 > 0 )
V_11 |= V_5 -> V_25 ;
V_5 -> V_12 = V_11 ;
V_5 -> V_4 . V_20 = ( void V_21 V_22 * ) V_11 ;
V_5 -> V_4 . V_26 = V_5 -> V_4 . V_20 ;
}
static inline T_1 F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return F_4 ( V_5 , V_27
+ 4 * V_5 -> V_28 ) ;
}
static void F_12 ( struct V_2 * V_3 , int V_29 )
{
struct V_1 * V_5 ;
T_1 V_30 ;
unsigned long V_31 ;
V_5 = F_1 ( V_3 ) ;
F_11 ( V_3 ) ;
F_13 ( & V_32 , V_31 ) ;
V_30 = F_4 ( V_5 , V_33 ) ;
V_30 |= F_14 ( 8 + V_5 -> V_28 ) ;
F_6 ( V_5 , V_33 , V_30 ) ;
F_15 ( & V_32 , V_31 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
const T_2 * V_34 , T_2 * V_35 )
{
unsigned int V_36 = F_11 ( V_3 ) ;
unsigned int V_37 = ( V_36 & 0x0fff ) | ( ( V_36 & 0x0fff0000 ) >> 4 ) ;
V_37 = ~ V_37 ;
V_35 [ 0 ] = ( T_2 ) ( V_37 ) ;
V_35 [ 1 ] = ( T_2 ) ( V_37 >> 8 ) ;
V_35 [ 2 ] = ( T_2 ) ( V_37 >> 16 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , T_2 * V_34 ,
T_2 * V_38 , T_2 * V_39 )
{
struct V_13 * V_4 = F_3 ( V_3 ) ;
T_1 V_40 = V_38 [ 0 ] | ( V_38 [ 1 ] << 8 ) |
( V_38 [ 2 ] << 16 ) ;
T_1 V_41 = V_39 [ 0 ] | ( V_39 [ 1 ] << 8 ) |
( V_39 [ 2 ] << 16 ) ;
T_1 V_42 = V_41 ^ V_40 ;
if ( V_42 ) {
if ( ( ( ( V_42 >> 12 ) ^ V_42 ) & 0xfff ) == 0xfff ) {
if ( ( V_42 >> ( 12 + 3 ) ) < V_4 -> V_43 . V_44 ) {
V_34 [ V_42 >> ( 12 + 3 ) ] ^= F_14 ( ( V_42 >> 12 ) & 7 ) ;
return 1 ;
} else {
return - V_45 ;
}
} else if ( ! ( V_42 & ( V_42 - 1 ) ) ) {
return 1 ;
} else {
return - V_45 ;
}
}
return 0 ;
}
static void F_18 ( struct V_2 * V_3 , int V_29 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned long V_31 ;
T_3 V_46 ;
F_4 ( V_5 , V_47 ) ;
F_13 ( & V_32 , V_31 ) ;
V_46 = F_4 ( V_5 , V_33 ) ;
V_46 &= ~ ( 0x03 << 4 ) ;
V_46 |= ( V_5 -> V_28 << 4 ) | F_14 ( 12 ) ;
F_6 ( V_5 , V_33 , V_46 ) ;
V_5 -> V_48 = ( V_29 == V_49 ) ;
F_15 ( & V_32 , V_31 ) ;
}
static void
F_19 ( struct V_1 * V_5 , T_3 V_50 [ 4 ] )
{
const T_3 V_51 = 0x03ff03ff ;
V_50 [ 0 ] = F_4 ( V_5 , V_47 ) & V_51 ;
V_50 [ 1 ] = F_4 ( V_5 , V_52 ) & V_51 ;
V_50 [ 2 ] = F_4 ( V_5 , V_53 ) & V_51 ;
V_50 [ 3 ] = F_4 ( V_5 , V_54 ) & V_51 ;
}
static int F_20 ( struct V_2 * V_3 ,
const T_2 * V_34 , T_2 * V_35 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 V_55 [ 4 ] , * V_56 ;
unsigned V_57 ;
if ( V_5 -> V_48 ) {
F_4 ( V_5 , V_47 ) ;
return 0 ;
}
F_19 ( V_5 , V_55 ) ;
for ( V_57 = 0 , V_56 = V_55 ; V_57 < 2 ; V_57 ++ , V_56 += 2 ) {
* V_35 ++ = V_56 [ 0 ] & 0xff ;
* V_35 ++ = ( ( V_56 [ 0 ] >> 8 ) & 0x03 ) | ( ( V_56 [ 0 ] >> 14 ) & 0xfc ) ;
* V_35 ++ = ( ( V_56 [ 0 ] >> 22 ) & 0x0f ) | ( ( V_56 [ 1 ] << 4 ) & 0xf0 ) ;
* V_35 ++ = ( ( V_56 [ 1 ] >> 4 ) & 0x3f ) | ( ( V_56 [ 1 ] >> 10 ) & 0xc0 ) ;
* V_35 ++ = ( V_56 [ 1 ] >> 18 ) & 0xff ;
}
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
T_2 * V_58 , T_2 * V_35 , T_2 * null )
{
int V_57 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned short V_59 [ 8 ] ;
unsigned short * V_60 ;
T_3 V_61 [ 4 ] ;
T_3 V_62 ;
unsigned V_63 , V_64 ;
unsigned long V_65 ;
if ( F_22 ( 0x01 & ( unsigned ) V_35 ) )
return - V_66 ;
V_60 = ( unsigned short * ) V_35 ;
V_59 [ 0 ] = ( V_60 [ 0 ] >> 0 ) & 0x3ff ;
V_59 [ 1 ] = ( ( V_60 [ 0 ] >> 10 ) & 0x3f ) | ( ( V_60 [ 1 ] << 6 ) & 0x3c0 ) ;
V_59 [ 2 ] = ( V_60 [ 1 ] >> 4 ) & 0x3ff ;
V_59 [ 3 ] = ( ( V_60 [ 1 ] >> 14 ) & 0x3 ) | ( ( V_60 [ 2 ] << 2 ) & 0x3fc ) ;
V_59 [ 4 ] = ( V_60 [ 2 ] >> 8 ) | ( ( V_60 [ 3 ] << 8 ) & 0x300 ) ;
V_59 [ 5 ] = ( V_60 [ 3 ] >> 2 ) & 0x3ff ;
V_59 [ 6 ] = ( ( V_60 [ 3 ] >> 12 ) & 0xf ) | ( ( V_60 [ 4 ] << 4 ) & 0x3f0 ) ;
V_59 [ 7 ] = ( V_60 [ 4 ] >> 6 ) & 0x3ff ;
for ( V_57 = 7 ; V_57 >= 0 ; V_57 -- )
F_6 ( V_5 , V_67 , V_59 [ V_57 ] ) ;
F_4 ( V_5 , V_68 ) ;
F_19 ( V_5 , V_61 ) ;
if ( ! ( V_61 [ 0 ] | V_61 [ 1 ] | V_61 [ 2 ] | V_61 [ 3 ] ) )
return 0 ;
F_4 ( V_5 , V_69 ) ;
F_6 ( V_5 , V_33 ,
F_4 ( V_5 , V_33 ) | F_14 ( 13 ) ) ;
V_65 = V_70 + F_23 ( 100 ) ;
do {
V_62 = ( F_4 ( V_5 ,
V_68 ) >> 8 ) & 0x0f ;
F_24 () ;
} while ( ( V_62 < 4 ) && F_25 ( V_70 , V_65 ) );
for (; ; ) {
T_3 V_71 = F_4 ( V_5 , V_68 ) ;
switch ( ( V_71 >> 8 ) & 0x0f ) {
case 0 :
F_4 ( V_5 , V_72 ) ;
return 0 ;
case 1 :
F_4 ( V_5 , V_72 ) ;
return - V_45 ;
case 2 :
case 3 :
V_63 = 1 + ( ( V_71 >> 16 ) & 0x03 ) ;
goto V_73;
default:
F_24 () ;
continue;
}
}
V_73:
for ( V_57 = 0 , V_64 = 0 ; V_57 < V_63 ; V_57 ++ ) {
int V_74 , V_75 ;
if ( V_57 > 1 ) {
V_74 = F_4 ( V_5 ,
V_76 ) ;
V_75 = F_4 ( V_5 ,
V_77 ) ;
} else {
V_74 = F_4 ( V_5 ,
V_69 ) ;
V_75 = F_4 ( V_5 ,
V_72 ) ;
}
if ( V_57 & 1 ) {
V_74 >>= 16 ;
V_75 >>= 16 ;
}
V_74 &= 0x3ff ;
V_74 = ( 512 + 7 ) - V_74 ;
if ( V_74 < 512 ) {
V_58 [ V_74 ] ^= V_75 ;
V_64 ++ ;
}
}
return V_64 ;
}
static void F_26 ( struct V_2 * V_3 , T_4 * V_78 , int V_79 )
{
struct V_13 * V_4 = F_3 ( V_3 ) ;
if ( ( 0x03 & ( ( unsigned ) V_78 ) ) == 0 && ( 0x03 & V_79 ) == 0 )
F_27 ( V_4 -> V_26 , V_78 , V_79 >> 2 ) ;
else if ( ( 0x01 & ( ( unsigned ) V_78 ) ) == 0 && ( 0x01 & V_79 ) == 0 )
F_28 ( V_4 -> V_26 , V_78 , V_79 >> 1 ) ;
else
F_29 ( V_4 -> V_26 , V_78 , V_79 ) ;
}
static void F_30 ( struct V_2 * V_3 ,
const T_4 * V_78 , int V_79 )
{
struct V_13 * V_4 = F_3 ( V_3 ) ;
if ( ( 0x03 & ( ( unsigned ) V_78 ) ) == 0 && ( 0x03 & V_79 ) == 0 )
F_31 ( V_4 -> V_26 , V_78 , V_79 >> 2 ) ;
else if ( ( 0x01 & ( ( unsigned ) V_78 ) ) == 0 && ( 0x01 & V_79 ) == 0 )
F_32 ( V_4 -> V_26 , V_78 , V_79 >> 1 ) ;
else
F_33 ( V_4 -> V_26 , V_78 , V_79 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return F_4 ( V_5 , V_68 ) & F_14 ( 0 ) ;
}
static int F_35 ( struct V_2 * V_3 , int V_80 ,
struct V_81 * V_82 )
{
if ( V_80 > 2 )
return - V_83 ;
if ( ! V_80 ) {
V_82 -> V_6 = 0 ;
V_82 -> V_84 = 5 ;
} else if ( V_80 == 1 ) {
V_82 -> V_6 = 6 ;
V_82 -> V_84 = 2 ;
} else {
V_82 -> V_6 = 13 ;
V_82 -> V_84 = 3 ;
}
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , int V_80 ,
struct V_81 * V_82 )
{
if ( V_80 > 1 )
return - V_83 ;
if ( ! V_80 ) {
V_82 -> V_6 = 8 ;
V_82 -> V_84 = 5 ;
} else {
V_82 -> V_6 = 16 ;
V_82 -> V_84 = V_3 -> V_85 - 16 ;
}
return 0 ;
}
static struct V_86
* F_37 ( struct V_87 * V_88 )
{
if ( ! F_38 ( & V_88 -> V_89 ) && V_88 -> V_89 . V_90 ) {
struct V_86 * V_91 ;
const char * V_29 ;
T_3 V_92 ;
V_91 = F_39 ( & V_88 -> V_89 ,
sizeof( struct V_86 ) ,
V_93 ) ;
V_88 -> V_89 . V_94 = V_91 ;
if ( ! V_91 )
return F_40 ( - V_95 ) ;
if ( ! F_41 ( V_88 -> V_89 . V_90 ,
L_1 , & V_92 ) )
V_88 -> V_96 = V_92 ;
else
return F_40 ( - V_66 ) ;
if ( ! F_41 ( V_88 -> V_89 . V_90 ,
L_2 , & V_92 ) )
V_91 -> V_19 = V_92 ;
if ( ! F_41 ( V_88 -> V_89 . V_90 ,
L_3 , & V_92 ) )
V_91 -> V_17 = V_92 ;
if ( ! F_41 ( V_88 -> V_89 . V_90 ,
L_4 , & V_92 ) )
V_91 -> V_25 = V_92 ;
if ( ! F_42 ( V_88 -> V_89 . V_90 ,
L_5 , & V_29 ) ) {
if ( ! strncmp ( L_6 , V_29 , 4 ) )
V_91 -> V_97 = V_98 ;
if ( ! strncmp ( L_7 , V_29 , 4 ) )
V_91 -> V_97 = V_99 ;
if ( ! strncmp ( L_8 , V_29 , 2 ) )
V_91 -> V_97 = V_100 ;
}
if ( ! F_41 ( V_88 -> V_89 . V_90 ,
L_9 , & V_92 ) )
V_91 -> V_101 = V_92 ;
if ( ! F_41 ( V_88 -> V_89 . V_90 ,
L_10 , & V_92 ) && V_92 == 16 )
V_91 -> V_102 |= V_103 ;
if ( F_43 ( V_88 -> V_89 . V_90 ,
L_11 ) )
V_91 -> V_104 = V_105 ;
if ( F_44 ( V_88 -> V_89 . V_90 ,
L_12 ) ) {
V_91 -> V_102 |= V_106 ;
}
}
return F_38 ( & V_88 -> V_89 ) ;
}
static struct V_86
* F_37 ( struct V_87 * V_88 )
{
return F_38 ( & V_88 -> V_89 ) ;
}
static int F_45 ( struct V_87 * V_88 )
{
struct V_86 * V_91 ;
struct V_1 * V_5 ;
struct V_107 * V_108 ;
struct V_107 * V_109 ;
void V_21 * V_110 ;
void V_21 * V_7 ;
int V_111 ;
T_1 V_46 ;
struct V_2 * V_3 ;
V_91 = F_37 ( V_88 ) ;
if ( F_46 ( V_91 ) )
return F_47 ( V_91 ) ;
if ( ! V_91 )
return - V_112 ;
if ( V_88 -> V_96 < 0 || V_88 -> V_96 > 3 )
return - V_112 ;
V_5 = F_39 ( & V_88 -> V_89 , sizeof( * V_5 ) , V_93 ) ;
if ( ! V_5 )
return - V_95 ;
F_48 ( V_88 , V_5 ) ;
V_108 = F_49 ( V_88 , V_113 , 0 ) ;
V_109 = F_49 ( V_88 , V_113 , 1 ) ;
if ( ! V_108 || ! V_109 ) {
F_50 ( & V_88 -> V_89 , L_13 ) ;
return - V_66 ;
}
V_110 = F_51 ( & V_88 -> V_89 , V_108 ) ;
if ( F_46 ( V_110 ) )
return F_47 ( V_110 ) ;
V_7 = F_52 ( & V_88 -> V_89 , V_109 -> V_114 , F_53 ( V_109 ) ) ;
if ( ! V_7 ) {
F_50 ( & V_88 -> V_89 , L_14 , V_109 ) ;
return - V_115 ;
}
V_5 -> V_89 = & V_88 -> V_89 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_110 = V_110 ;
V_3 = F_54 ( & V_5 -> V_4 ) ;
V_3 -> V_89 . V_116 = & V_88 -> V_89 ;
F_55 ( & V_5 -> V_4 , V_88 -> V_89 . V_90 ) ;
V_5 -> V_4 . V_26 = V_110 ;
V_5 -> V_4 . V_20 = V_110 ;
V_5 -> V_4 . V_117 = 0 ;
V_5 -> V_4 . V_118 = F_10 ;
V_5 -> V_4 . V_104 = V_91 -> V_104 ;
V_5 -> V_4 . V_102 = V_91 -> V_102 ;
V_5 -> V_4 . V_119 = V_91 -> V_119 ;
V_5 -> V_4 . V_120 = V_91 -> V_120 ;
V_5 -> V_121 = V_91 -> V_121 ;
V_5 -> V_24 = ( T_1 V_22 ) V_110 ;
V_5 -> V_12 = V_5 -> V_24 ;
V_5 -> V_28 = V_88 -> V_96 ;
V_5 -> V_25 = V_91 -> V_25 ;
V_5 -> V_19 = V_91 -> V_19 ? : V_122 ;
V_5 -> V_17 = V_91 -> V_17 ? : V_123 ;
V_5 -> V_4 . V_124 = F_8 ;
V_5 -> V_4 . V_125 = F_34 ;
V_5 -> V_4 . V_126 = F_26 ;
V_5 -> V_4 . V_127 = F_30 ;
V_5 -> V_4 . V_43 . V_29 = V_91 -> V_97 ;
V_111 = - V_66 ;
V_5 -> V_128 = F_56 ( & V_88 -> V_89 , L_15 ) ;
if ( F_46 ( V_5 -> V_128 ) ) {
V_111 = F_47 ( V_5 -> V_128 ) ;
F_57 ( & V_88 -> V_89 , L_16 , V_111 ) ;
return V_111 ;
}
V_111 = F_58 ( V_5 -> V_128 ) ;
if ( V_111 < 0 ) {
F_57 ( & V_88 -> V_89 , L_17 ,
V_111 ) ;
goto V_129;
}
F_59 ( & V_32 ) ;
V_46 = F_4 ( V_5 , V_33 ) ;
V_46 |= F_14 ( V_5 -> V_28 ) ;
F_6 ( V_5 , V_33 , V_46 ) ;
F_60 ( & V_32 ) ;
V_111 = F_61 ( V_3 , V_91 -> V_25 ? 2 : 1 , NULL ) ;
if ( V_111 < 0 ) {
F_57 ( & V_88 -> V_89 , L_18 ) ;
goto V_130;
}
switch ( V_5 -> V_4 . V_43 . V_29 ) {
case V_98 :
V_91 -> V_101 = 0 ;
break;
case V_99 :
V_91 -> V_101 = 0 ;
V_5 -> V_4 . V_43 . V_131 = V_132 ;
break;
case V_100 :
if ( V_91 -> V_101 == 4 ) {
F_59 ( & V_32 ) ;
if ( V_133 )
V_111 = - V_134 ;
else
V_133 = true ;
F_60 ( & V_32 ) ;
if ( V_111 == - V_134 )
return V_111 ;
V_5 -> V_4 . V_43 . V_135 = F_20 ;
V_5 -> V_4 . V_43 . V_73 = F_21 ;
V_5 -> V_4 . V_43 . V_136 = F_18 ;
V_5 -> V_4 . V_43 . V_137 = 10 ;
V_5 -> V_4 . V_43 . V_102 = V_138 ;
V_5 -> V_4 . V_43 . V_131 = V_139 ;
} else {
V_5 -> V_4 . V_43 . V_135 = F_16 ;
V_5 -> V_4 . V_43 . V_73 = F_17 ;
V_5 -> V_4 . V_43 . V_136 = F_12 ;
V_5 -> V_4 . V_43 . V_137 = 3 ;
V_5 -> V_4 . V_43 . V_131 = V_132 ;
}
V_5 -> V_4 . V_43 . V_44 = 512 ;
V_5 -> V_4 . V_43 . V_140 = V_91 -> V_101 ;
break;
default:
return - V_66 ;
}
if ( V_91 -> V_101 == 4 ) {
int V_141 = V_3 -> V_142 / 512 ;
if ( ! V_141 || V_3 -> V_85 < 16 ) {
F_57 ( & V_88 -> V_89 , L_19 ) ;
V_111 = - V_66 ;
goto V_130;
}
if ( V_141 == 1 ) {
F_62 ( V_3 , & V_143 ) ;
} else if ( V_141 == 4 || V_141 == 8 ) {
F_62 ( V_3 , & V_144 ) ;
V_5 -> V_4 . V_43 . V_29 = V_145 ;
} else {
V_111 = - V_146 ;
goto V_130;
}
}
V_111 = F_63 ( V_3 ) ;
if ( V_111 < 0 )
goto V_130;
if ( V_91 -> V_147 )
V_111 = F_64 ( V_3 , NULL , NULL ,
V_91 -> V_147 , V_91 -> V_148 ) ;
else
V_111 = F_65 ( V_3 , NULL , 0 ) ;
if ( V_111 < 0 )
goto V_130;
V_46 = F_4 ( V_5 , V_149 ) ;
F_66 ( & V_88 -> V_89 , L_20 ,
( V_46 >> 8 ) & 0xff , V_46 & 0xff ) ;
return 0 ;
V_130:
F_67 ( V_5 -> V_128 ) ;
V_129:
F_59 ( & V_32 ) ;
if ( V_5 -> V_4 . V_43 . V_29 == V_150 )
V_133 = false ;
F_60 ( & V_32 ) ;
return V_111 ;
}
static int F_68 ( struct V_87 * V_88 )
{
struct V_1 * V_5 = F_69 ( V_88 ) ;
F_59 ( & V_32 ) ;
if ( V_5 -> V_4 . V_43 . V_29 == V_150 )
V_133 = false ;
F_60 ( & V_32 ) ;
F_70 ( F_54 ( & V_5 -> V_4 ) ) ;
F_67 ( V_5 -> V_128 ) ;
return 0 ;
}

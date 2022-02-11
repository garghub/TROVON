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
F_13 ( & V_32 , V_31 ) ;
V_46 = F_4 ( V_5 , V_33 ) ;
V_46 &= ~ ( 0x03 << 4 ) ;
V_46 |= ( V_5 -> V_28 << 4 ) | F_14 ( 12 ) ;
F_6 ( V_5 , V_33 , V_46 ) ;
V_5 -> V_47 = ( V_29 == V_48 ) ;
F_15 ( & V_32 , V_31 ) ;
}
static void
F_19 ( struct V_1 * V_5 , T_3 V_49 [ 4 ] )
{
const T_3 V_50 = 0x03ff03ff ;
V_49 [ 0 ] = F_4 ( V_5 , V_51 ) & V_50 ;
V_49 [ 1 ] = F_4 ( V_5 , V_52 ) & V_50 ;
V_49 [ 2 ] = F_4 ( V_5 , V_53 ) & V_50 ;
V_49 [ 3 ] = F_4 ( V_5 , V_54 ) & V_50 ;
}
static int F_20 ( struct V_2 * V_3 ,
const T_2 * V_34 , T_2 * V_35 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_3 V_55 [ 4 ] , * V_56 ;
unsigned V_57 ;
if ( V_5 -> V_47 ) {
F_4 ( V_5 , V_51 ) ;
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
static struct V_80
* F_35 ( struct V_81 * V_82 )
{
if ( ! F_36 ( & V_82 -> V_83 ) && V_82 -> V_83 . V_84 ) {
struct V_80 * V_85 ;
const char * V_29 ;
T_3 V_86 ;
V_85 = F_37 ( & V_82 -> V_83 ,
sizeof( struct V_80 ) ,
V_87 ) ;
V_82 -> V_83 . V_88 = V_85 ;
if ( ! V_85 )
return F_38 ( - V_89 ) ;
if ( ! F_39 ( V_82 -> V_83 . V_84 ,
L_1 , & V_86 ) )
V_82 -> V_90 = V_86 ;
else
return F_38 ( - V_66 ) ;
if ( ! F_39 ( V_82 -> V_83 . V_84 ,
L_2 , & V_86 ) )
V_85 -> V_19 = V_86 ;
if ( ! F_39 ( V_82 -> V_83 . V_84 ,
L_3 , & V_86 ) )
V_85 -> V_17 = V_86 ;
if ( ! F_39 ( V_82 -> V_83 . V_84 ,
L_4 , & V_86 ) )
V_85 -> V_25 = V_86 ;
if ( ! F_40 ( V_82 -> V_83 . V_84 ,
L_5 , & V_29 ) ||
! F_40 ( V_82 -> V_83 . V_84 ,
L_6 , & V_29 ) ) {
if ( ! strncmp ( L_7 , V_29 , 4 ) )
V_85 -> V_91 = V_92 ;
if ( ! strncmp ( L_8 , V_29 , 4 ) )
V_85 -> V_91 = V_93 ;
if ( ! strncmp ( L_9 , V_29 , 2 ) )
V_85 -> V_91 = V_94 ;
}
if ( ! F_39 ( V_82 -> V_83 . V_84 ,
L_10 , & V_86 ) )
V_85 -> V_95 = V_86 ;
V_86 = F_41 ( V_82 -> V_83 . V_84 ) ;
if ( 0 < V_86 || ! F_39 ( V_82 -> V_83 . V_84 ,
L_11 , & V_86 ) )
if ( V_86 == 16 )
V_85 -> V_96 |= V_97 ;
if ( F_42 ( V_82 -> V_83 . V_84 ,
L_12 ) ||
F_42 ( V_82 -> V_83 . V_84 ,
L_13 ) )
V_85 -> V_98 = V_99 ;
if ( F_43 ( V_82 -> V_83 . V_84 ,
L_14 ) ) {
V_85 -> V_96 |= V_100 ;
}
}
return F_36 ( & V_82 -> V_83 ) ;
}
static struct V_80
* F_35 ( struct V_81 * V_82 )
{
return F_36 ( & V_82 -> V_83 ) ;
}
static int F_44 ( struct V_81 * V_82 )
{
struct V_80 * V_85 ;
struct V_1 * V_5 ;
struct V_101 * V_102 ;
struct V_101 * V_103 ;
void V_21 * V_104 ;
void V_21 * V_7 ;
int V_105 ;
T_1 V_46 ;
T_5 V_91 ;
struct V_2 * V_3 ;
V_85 = F_35 ( V_82 ) ;
if ( F_45 ( V_85 ) )
return F_46 ( V_85 ) ;
if ( ! V_85 )
return - V_106 ;
if ( V_82 -> V_90 < 0 || V_82 -> V_90 > 3 )
return - V_106 ;
V_5 = F_37 ( & V_82 -> V_83 , sizeof( * V_5 ) , V_87 ) ;
if ( ! V_5 )
return - V_89 ;
F_47 ( V_82 , V_5 ) ;
V_102 = F_48 ( V_82 , V_107 , 0 ) ;
V_103 = F_48 ( V_82 , V_107 , 1 ) ;
if ( ! V_102 || ! V_103 ) {
F_49 ( & V_82 -> V_83 , L_15 ) ;
return - V_66 ;
}
V_104 = F_50 ( & V_82 -> V_83 , V_102 ) ;
if ( F_45 ( V_104 ) )
return F_46 ( V_104 ) ;
V_7 = F_51 ( & V_82 -> V_83 , V_103 -> V_108 , F_52 ( V_103 ) ) ;
if ( ! V_7 ) {
F_49 ( & V_82 -> V_83 , L_16 , V_103 ) ;
return - V_109 ;
}
V_5 -> V_83 = & V_82 -> V_83 ;
V_5 -> V_7 = V_7 ;
V_5 -> V_104 = V_104 ;
V_3 = F_53 ( & V_5 -> V_4 ) ;
V_3 -> V_83 . V_110 = & V_82 -> V_83 ;
F_54 ( & V_5 -> V_4 , V_82 -> V_83 . V_84 ) ;
V_5 -> V_4 . V_26 = V_104 ;
V_5 -> V_4 . V_20 = V_104 ;
V_5 -> V_4 . V_111 = 0 ;
V_5 -> V_4 . V_112 = F_10 ;
V_5 -> V_4 . V_98 = V_85 -> V_98 ;
V_5 -> V_4 . V_96 = V_85 -> V_96 ;
V_5 -> V_4 . V_113 = V_85 -> V_113 ;
V_5 -> V_4 . V_114 = V_85 -> V_114 ;
V_5 -> V_115 = V_85 -> V_115 ;
V_5 -> V_24 = ( T_1 V_22 ) V_104 ;
V_5 -> V_12 = V_5 -> V_24 ;
V_5 -> V_28 = V_82 -> V_90 ;
V_5 -> V_25 = V_85 -> V_25 ;
V_5 -> V_19 = V_85 -> V_19 ? : V_116 ;
V_5 -> V_17 = V_85 -> V_17 ? : V_117 ;
V_5 -> V_4 . V_118 = F_8 ;
V_5 -> V_4 . V_119 = F_34 ;
V_5 -> V_4 . V_120 = F_26 ;
V_5 -> V_4 . V_121 = F_30 ;
V_91 = V_85 -> V_91 ;
V_105 = - V_66 ;
switch ( V_91 ) {
case V_92 :
case V_93 :
V_85 -> V_95 = 0 ;
break;
case V_94 :
if ( V_85 -> V_95 == 4 ) {
F_55 ( & V_32 ) ;
if ( V_122 )
V_105 = - V_123 ;
else
V_122 = true ;
F_56 ( & V_32 ) ;
if ( V_105 == - V_123 )
return V_105 ;
V_5 -> V_4 . V_43 . V_124 = F_20 ;
V_5 -> V_4 . V_43 . V_73 = F_21 ;
V_5 -> V_4 . V_43 . V_125 = F_18 ;
V_5 -> V_4 . V_43 . V_126 = 10 ;
V_5 -> V_4 . V_43 . V_96 = V_127 ;
} else {
V_5 -> V_4 . V_43 . V_124 = F_16 ;
V_5 -> V_4 . V_43 . V_73 = F_17 ;
V_5 -> V_4 . V_43 . V_125 = F_12 ;
V_5 -> V_4 . V_43 . V_126 = 3 ;
}
V_5 -> V_4 . V_43 . V_44 = 512 ;
V_5 -> V_4 . V_43 . V_128 = V_85 -> V_95 ;
break;
default:
return - V_66 ;
}
V_5 -> V_4 . V_43 . V_29 = V_91 ;
V_5 -> V_129 = F_57 ( & V_82 -> V_83 , L_17 ) ;
if ( F_45 ( V_5 -> V_129 ) ) {
V_105 = F_46 ( V_5 -> V_129 ) ;
F_58 ( & V_82 -> V_83 , L_18 , V_105 ) ;
return V_105 ;
}
V_105 = F_59 ( V_5 -> V_129 ) ;
if ( V_105 < 0 ) {
F_58 ( & V_82 -> V_83 , L_19 ,
V_105 ) ;
goto V_130;
}
F_55 ( & V_32 ) ;
V_46 = F_4 ( V_5 , V_33 ) ;
V_46 |= F_14 ( V_5 -> V_28 ) ;
F_6 ( V_5 , V_33 , V_46 ) ;
F_56 ( & V_32 ) ;
V_105 = F_60 ( V_3 , V_85 -> V_25 ? 2 : 1 , NULL ) ;
if ( V_105 < 0 ) {
F_58 ( & V_82 -> V_83 , L_20 ) ;
goto V_131;
}
if ( V_85 -> V_95 == 4 ) {
int V_132 = V_3 -> V_133 / 512 ;
if ( ! V_132 || V_3 -> V_134 < 16 ) {
F_58 ( & V_82 -> V_83 , L_21 ) ;
V_105 = - V_66 ;
goto V_131;
}
if ( V_132 == 1 ) {
V_5 -> V_135 = V_136 ;
V_5 -> V_135 . V_137 [ 1 ] . V_138 = V_3 -> V_134 - 16 ;
goto V_139;
}
if ( V_132 == 4 ) {
V_5 -> V_135 = V_140 ;
V_5 -> V_4 . V_43 . V_29 = V_141 ;
goto V_139;
}
if ( V_132 == 8 ) {
V_5 -> V_135 = V_142 ;
V_5 -> V_4 . V_43 . V_29 = V_141 ;
goto V_139;
}
V_105 = - V_143 ;
goto V_131;
V_139:
V_5 -> V_4 . V_43 . V_144 = & V_5 -> V_135 ;
}
V_105 = F_61 ( V_3 ) ;
if ( V_105 < 0 )
goto V_131;
if ( V_85 -> V_145 )
V_105 = F_62 ( V_3 , NULL , NULL ,
V_85 -> V_145 , V_85 -> V_146 ) ;
else
V_105 = F_63 ( V_3 , NULL , 0 ) ;
if ( V_105 < 0 )
goto V_131;
V_46 = F_4 ( V_5 , V_147 ) ;
F_64 ( & V_82 -> V_83 , L_22 ,
( V_46 >> 8 ) & 0xff , V_46 & 0xff ) ;
return 0 ;
V_131:
F_65 ( V_5 -> V_129 ) ;
V_130:
F_55 ( & V_32 ) ;
if ( V_91 == V_148 )
V_122 = false ;
F_56 ( & V_32 ) ;
return V_105 ;
}
static int F_66 ( struct V_81 * V_82 )
{
struct V_1 * V_5 = F_67 ( V_82 ) ;
F_55 ( & V_32 ) ;
if ( V_5 -> V_4 . V_43 . V_29 == V_148 )
V_122 = false ;
F_56 ( & V_32 ) ;
F_68 ( F_53 ( & V_5 -> V_4 ) ) ;
F_65 ( V_5 -> V_129 ) ;
return 0 ;
}

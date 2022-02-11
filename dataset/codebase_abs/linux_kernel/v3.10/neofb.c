static inline void F_1 ( int V_1 , T_1 V_2 , const struct V_3 * V_4 )
{
F_2 ( V_2 , V_4 -> V_5 + V_4 -> V_6 + V_1 ) ;
}
static int F_3 ( int V_7 , int V_8 , int V_9 )
{
int V_10 ;
int V_11 , V_12 ;
T_2 * V_13 ;
switch ( V_9 ) {
case 8 :
V_12 = F_4 ( V_14 ) ;
V_13 = V_14 ;
break;
case 16 :
V_12 = F_4 ( V_15 ) ;
V_13 = V_15 ;
break;
case 24 :
V_12 = F_4 ( V_16 ) ;
V_13 = V_16 ;
break;
#ifdef F_5
case 32 :
V_12 = F_4 ( V_17 ) ;
V_13 = V_17 ;
break;
#endif
default:
return 0 ;
}
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( V_7 <= V_13 [ V_11 ] . V_18 ) {
V_10 = V_13 [ V_11 ] . V_18 ;
for (; V_11 < V_12 ; V_11 ++ ) {
if ( V_13 [ V_11 ] . V_18 != V_10 )
return V_13 [ V_11 - 1 ] . V_13 ;
if ( V_8 <= V_13 [ V_11 ] . V_19 )
return V_13 [ V_11 ] . V_13 ;
}
}
}
return V_13 [ V_12 - 1 ] . V_13 ;
}
static void F_6 ( const struct V_20 * V_21 ,
struct V_3 * V_4 , long V_22 )
{
int V_23 , V_24 , V_25 ;
int V_26 = 0 , V_27 = 0 , V_28 = 0 ;
long V_29 = 0x7ffff ;
for ( V_25 = 0 ; V_25 <= V_30 ; V_25 ++ )
for ( V_24 = 0 ; V_24 <= V_31 ; V_24 ++ )
for ( V_23 = 0 ; V_23 <= V_32 ; V_23 ++ ) {
long V_33 ;
long V_34 ;
V_33 = ( ( 14318 * ( V_23 + 1 ) ) / ( V_24 + 1 ) ) >> V_25 ;
V_34 = abs ( V_33 - V_22 ) ;
if ( V_34 <= V_29 ) {
V_29 = V_34 ;
V_26 = V_23 ;
V_27 = V_24 ;
V_28 = V_25 ;
}
if ( V_33 > V_22 )
break;
}
if ( V_21 -> V_35 . V_36 == V_37 ||
V_21 -> V_35 . V_36 == V_38 ||
V_21 -> V_35 . V_36 == V_39 ||
V_21 -> V_35 . V_36 == V_40 ) {
V_4 -> V_41 = V_26 ;
V_4 -> V_42 = ( V_28 << 7 ) ;
} else
V_4 -> V_41 = V_26 | ( V_28 << 7 ) ;
V_4 -> V_43 = V_27 ;
#ifdef F_7
F_8 ( V_44 L_1 ,
V_22 ,
V_4 -> V_41 ,
V_4 -> V_42 ,
V_4 -> V_43 , V_29 ) ;
#endif
}
static int F_9 ( const struct V_45 * V_46 ,
struct V_3 * V_4 )
{
int V_47 = V_46 -> V_7 + V_46 -> V_48 + V_46 -> V_49 ;
int V_50 = ( V_47 + V_46 -> V_51 ) >> 3 ;
int V_52 = V_46 -> V_8 + V_46 -> V_53 ;
int V_54 = V_52 + V_46 -> V_55 ;
int V_56 = V_54 + V_46 -> V_57 ;
V_4 -> V_58 = 0x23 ;
if ( ! ( V_46 -> V_59 & V_60 ) )
V_4 -> V_58 |= 0x40 ;
if ( ! ( V_46 -> V_59 & V_61 ) )
V_4 -> V_58 |= 0x80 ;
V_4 -> V_62 [ 0 ] = 0x00 ;
V_4 -> V_62 [ 1 ] = 0x01 ;
V_4 -> V_62 [ 2 ] = 0x0F ;
V_4 -> V_62 [ 3 ] = 0x00 ;
V_4 -> V_62 [ 4 ] = 0x0E ;
V_4 -> V_63 [ 0 ] = V_50 - 5 ;
V_4 -> V_63 [ 1 ] = ( V_46 -> V_7 >> 3 ) - 1 ;
V_4 -> V_63 [ 2 ] = ( V_46 -> V_7 >> 3 ) - 1 ;
V_4 -> V_63 [ 3 ] = ( ( V_50 - 1 ) & 0x1F ) | 0x80 ;
V_4 -> V_63 [ 4 ] = ( ( V_46 -> V_7 + V_46 -> V_48 ) >> 3 ) ;
V_4 -> V_63 [ 5 ] = ( ( ( V_50 - 1 ) & 0x20 ) << 2 )
| ( ( ( V_47 >> 3 ) ) & 0x1F ) ;
V_4 -> V_63 [ 6 ] = ( V_56 - 2 ) & 0xFF ;
V_4 -> V_63 [ 7 ] = ( ( ( V_56 - 2 ) & 0x100 ) >> 8 )
| ( ( ( V_46 -> V_8 - 1 ) & 0x100 ) >> 7 )
| ( ( V_52 & 0x100 ) >> 6 )
| ( ( ( V_46 -> V_8 - 1 ) & 0x100 ) >> 5 )
| 0x10 | ( ( ( V_56 - 2 ) & 0x200 ) >> 4 )
| ( ( ( V_46 -> V_8 - 1 ) & 0x200 ) >> 3 )
| ( ( V_52 & 0x200 ) >> 2 ) ;
V_4 -> V_63 [ 8 ] = 0x00 ;
V_4 -> V_63 [ 9 ] = ( ( ( V_46 -> V_8 - 1 ) & 0x200 ) >> 4 ) | 0x40 ;
if ( V_46 -> V_64 & V_65 )
V_4 -> V_63 [ 9 ] |= 0x80 ;
V_4 -> V_63 [ 10 ] = 0x00 ;
V_4 -> V_63 [ 11 ] = 0x00 ;
V_4 -> V_63 [ 12 ] = 0x00 ;
V_4 -> V_63 [ 13 ] = 0x00 ;
V_4 -> V_63 [ 14 ] = 0x00 ;
V_4 -> V_63 [ 15 ] = 0x00 ;
V_4 -> V_63 [ 16 ] = V_52 & 0xFF ;
V_4 -> V_63 [ 17 ] = ( V_54 & 0x0F ) | 0x20 ;
V_4 -> V_63 [ 18 ] = ( V_46 -> V_8 - 1 ) & 0xFF ;
V_4 -> V_63 [ 19 ] = V_46 -> V_66 >> 4 ;
V_4 -> V_63 [ 20 ] = 0x00 ;
V_4 -> V_63 [ 21 ] = ( V_46 -> V_8 - 1 ) & 0xFF ;
V_4 -> V_63 [ 22 ] = ( V_56 - 1 ) & 0xFF ;
V_4 -> V_63 [ 23 ] = 0xC3 ;
V_4 -> V_63 [ 24 ] = 0xFF ;
V_4 -> V_67 [ 0 ] = 0x00 ;
V_4 -> V_67 [ 1 ] = 0x00 ;
V_4 -> V_67 [ 2 ] = 0x00 ;
V_4 -> V_67 [ 3 ] = 0x00 ;
V_4 -> V_67 [ 4 ] = 0x00 ;
V_4 -> V_67 [ 5 ] = 0x40 ;
V_4 -> V_67 [ 6 ] = 0x05 ;
V_4 -> V_67 [ 7 ] = 0x0F ;
V_4 -> V_67 [ 8 ] = 0xFF ;
V_4 -> V_68 [ 0 ] = 0x00 ;
V_4 -> V_68 [ 1 ] = 0x01 ;
V_4 -> V_68 [ 2 ] = 0x02 ;
V_4 -> V_68 [ 3 ] = 0x03 ;
V_4 -> V_68 [ 4 ] = 0x04 ;
V_4 -> V_68 [ 5 ] = 0x05 ;
V_4 -> V_68 [ 6 ] = 0x06 ;
V_4 -> V_68 [ 7 ] = 0x07 ;
V_4 -> V_68 [ 8 ] = 0x08 ;
V_4 -> V_68 [ 9 ] = 0x09 ;
V_4 -> V_68 [ 10 ] = 0x0A ;
V_4 -> V_68 [ 11 ] = 0x0B ;
V_4 -> V_68 [ 12 ] = 0x0C ;
V_4 -> V_68 [ 13 ] = 0x0D ;
V_4 -> V_68 [ 14 ] = 0x0E ;
V_4 -> V_68 [ 15 ] = 0x0F ;
V_4 -> V_68 [ 16 ] = 0x41 ;
V_4 -> V_68 [ 17 ] = 0xFF ;
V_4 -> V_68 [ 18 ] = 0x0F ;
V_4 -> V_68 [ 19 ] = 0x00 ;
V_4 -> V_68 [ 20 ] = 0x00 ;
return 0 ;
}
static void F_10 ( struct V_69 * V_70 )
{
F_11 ( V_70 -> V_71 , 0x11 , F_12 ( V_70 -> V_71 , 0x11 ) | 0x80 ) ;
}
static void F_13 ( void )
{
F_11 ( NULL , 0x11 , F_12 ( NULL , 0x11 ) & ~ 0x80 ) ;
}
static void F_14 ( struct V_69 * V_70 )
{
F_15 ( V_70 -> V_71 , 0x09 , 0x00 ) ;
F_10 ( V_70 ) ;
}
static void F_16 ( void )
{
F_13 () ;
F_15 ( NULL , 0x09 , 0x26 ) ;
}
static inline void F_17 ( void )
{
F_18 ( NULL , V_72 ) ;
F_19 ( NULL , V_73 , 0x00 ) ;
V_74 = 1 ;
}
static inline void F_20 ( void )
{
F_18 ( NULL , V_72 ) ;
F_19 ( NULL , V_73 , 0x20 ) ;
V_74 = 0 ;
}
static inline void F_21 ( T_3 V_75 , T_3 V_76 )
{
if ( V_74 )
V_75 &= ~ 0x20 ;
else
V_75 |= 0x20 ;
F_18 ( NULL , V_72 ) ;
F_22 ( NULL , V_75 , V_76 ) ;
}
static void F_23 ( int V_77 )
{
unsigned char V_78 ;
V_78 = F_24 ( NULL , 0x01 ) ;
if ( V_77 ) {
F_25 ( NULL , 0x00 , 0x01 ) ;
F_25 ( NULL , 0x01 , V_78 | 0x20 ) ;
F_17 () ;
} else {
F_25 ( NULL , 0x01 , V_78 & ~ 0x20 ) ;
F_25 ( NULL , 0x00 , 0x03 ) ;
F_20 () ;
}
}
static void F_26 ( const struct V_20 * V_21 ,
const struct V_3 * V_4 )
{
int V_11 ;
F_19 ( NULL , V_79 , V_4 -> V_58 ) ;
for ( V_11 = 1 ; V_11 < 5 ; V_11 ++ )
F_25 ( NULL , V_11 , V_4 -> V_62 [ V_11 ] ) ;
F_11 ( NULL , 17 , V_4 -> V_63 [ 17 ] & ~ 0x80 ) ;
for ( V_11 = 0 ; V_11 < 25 ; V_11 ++ )
F_11 ( NULL , V_11 , V_4 -> V_63 [ V_11 ] ) ;
for ( V_11 = 0 ; V_11 < 9 ; V_11 ++ )
F_15 ( NULL , V_11 , V_4 -> V_67 [ V_11 ] ) ;
F_17 () ;
for ( V_11 = 0 ; V_11 < 21 ; V_11 ++ )
F_21 ( V_11 , V_4 -> V_68 [ V_11 ] ) ;
F_20 () ;
}
static inline int F_27 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
while ( F_28 ( & V_4 -> V_5 -> V_80 ) & 1 )
F_29 () ;
return 0 ;
}
static inline void F_30 ( struct V_20 * V_21 ,
int V_81 )
{
F_27 ( V_21 ) ;
}
static inline void F_31 ( struct V_20 * V_21 ,
struct V_45 * V_46 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
T_4 T_5 * V_5 = V_4 -> V_5 ;
T_1 V_82 , V_83 ;
F_27 ( V_21 ) ;
switch ( V_46 -> V_84 ) {
case 8 :
V_82 = V_85 ;
V_83 = V_46 -> V_66 ;
break;
case 15 :
case 16 :
V_82 = V_86 ;
V_83 = V_46 -> V_66 * 2 ;
break;
case 24 :
V_82 = V_87 ;
V_83 = V_46 -> V_66 * 3 ;
break;
default:
F_8 ( V_88
L_2 ) ;
return;
}
F_2 ( V_82 << 16 , & V_5 -> V_80 ) ;
F_2 ( ( V_83 << 16 ) | V_83 , & V_5 -> V_83 ) ;
}
static int
F_32 ( struct V_20 * V_21 , int V_89 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
if ( ! V_4 -> V_90 ) {
memset ( & V_4 -> V_70 , 0 , sizeof( struct V_69 ) ) ;
V_4 -> V_70 . V_91 = V_92 | V_93 ;
F_33 ( & V_4 -> V_70 ) ;
}
V_4 -> V_90 ++ ;
return 0 ;
}
static int
F_34 ( struct V_20 * V_21 , int V_89 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
if ( ! V_4 -> V_90 )
return - V_94 ;
if ( V_4 -> V_90 == 1 ) {
F_35 ( & V_4 -> V_70 ) ;
}
V_4 -> V_90 -- ;
return 0 ;
}
static int
F_36 ( struct V_45 * V_46 , struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
int V_95 , V_96 ;
int V_97 = 0 ;
F_37 ( L_3 ) ;
if ( F_38 ( V_46 -> V_98 ) > V_4 -> V_99 )
return - V_94 ;
if ( V_4 -> V_100 &&
( ( V_46 -> V_7 > V_4 -> V_101 ) ||
( V_46 -> V_8 > V_4 -> V_102 ) ) ) {
F_8 ( V_103
L_4 ,
V_46 -> V_7 , V_46 -> V_8 , V_4 -> V_101 ,
V_4 -> V_102 ) ;
return - V_94 ;
}
if ( ! V_4 -> V_100 )
V_97 = 1 ;
else {
switch ( V_46 -> V_7 ) {
case 1280 :
if ( V_46 -> V_8 == 1024 )
V_97 = 1 ;
break;
case 1024 :
if ( V_46 -> V_8 == 768 )
V_97 = 1 ;
break;
case 800 :
if ( V_46 -> V_8 == ( V_4 -> V_104 ? 480 : 600 ) )
V_97 = 1 ;
break;
case 640 :
if ( V_46 -> V_8 == 480 )
V_97 = 1 ;
break;
}
}
if ( ! V_97 ) {
F_8 ( V_103
L_5 ,
V_46 -> V_7 , V_46 -> V_8 ) ;
return - V_94 ;
}
V_46 -> V_105 . V_106 = 0 ;
V_46 -> V_107 . V_106 = 0 ;
V_46 -> V_108 . V_106 = 0 ;
V_46 -> V_109 . V_106 = 0 ;
V_46 -> V_109 . V_110 = 0 ;
V_46 -> V_109 . V_111 = 0 ;
switch ( V_46 -> V_84 ) {
case 8 :
V_46 -> V_105 . V_110 = 0 ;
V_46 -> V_105 . V_111 = 8 ;
V_46 -> V_107 . V_110 = 0 ;
V_46 -> V_107 . V_111 = 8 ;
V_46 -> V_108 . V_110 = 0 ;
V_46 -> V_108 . V_111 = 8 ;
break;
case 16 :
V_46 -> V_105 . V_110 = 11 ;
V_46 -> V_105 . V_111 = 5 ;
V_46 -> V_107 . V_110 = 5 ;
V_46 -> V_107 . V_111 = 6 ;
V_46 -> V_108 . V_110 = 0 ;
V_46 -> V_108 . V_111 = 5 ;
break;
case 24 :
V_46 -> V_105 . V_110 = 16 ;
V_46 -> V_105 . V_111 = 8 ;
V_46 -> V_107 . V_110 = 8 ;
V_46 -> V_107 . V_111 = 8 ;
V_46 -> V_108 . V_110 = 0 ;
V_46 -> V_108 . V_111 = 8 ;
break;
#ifdef F_5
case 32 :
V_46 -> V_109 . V_110 = 24 ;
V_46 -> V_109 . V_111 = 8 ;
V_46 -> V_105 . V_110 = 16 ;
V_46 -> V_105 . V_111 = 8 ;
V_46 -> V_107 . V_110 = 8 ;
V_46 -> V_107 . V_111 = 8 ;
V_46 -> V_108 . V_110 = 0 ;
V_46 -> V_108 . V_111 = 8 ;
break;
#endif
default:
F_8 ( V_112 L_6 ,
V_46 -> V_84 ) ;
return - V_94 ;
}
V_96 = V_21 -> V_35 . V_113 ;
if ( V_96 > 4 * 1024 * 1024 )
V_96 = 4 * 1024 * 1024 ;
if ( V_46 -> V_66 < V_46 -> V_7 )
V_46 -> V_66 = V_46 -> V_7 ;
V_95 = V_46 -> V_66 * V_46 -> V_84 * V_46 -> V_114 >> 3 ;
if ( V_95 > V_96 ) {
V_46 -> V_114 = V_96 * 8 / ( V_46 -> V_66 *
V_46 -> V_84 ) ;
V_95 = V_46 -> V_66 * V_46 -> V_84 *
V_46 -> V_114 / 8 ;
}
if ( V_46 -> V_114 < V_46 -> V_8 )
V_46 -> V_8 = V_46 -> V_114 ;
if ( V_46 -> V_115 + V_46 -> V_7 > V_46 -> V_66 )
V_46 -> V_115 = V_46 -> V_66 - V_46 -> V_7 ;
if ( V_46 -> V_116 + V_46 -> V_8 > V_46 -> V_114 )
V_46 -> V_116 = V_46 -> V_114 - V_46 -> V_8 ;
V_46 -> V_117 = 0 ;
V_46 -> V_118 = - 1 ;
V_46 -> V_119 = - 1 ;
if ( V_46 -> V_84 >= 24 || ! V_4 -> V_5 )
V_46 -> V_120 &= ~ V_121 ;
return 0 ;
}
static int F_39 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
unsigned char V_122 ;
int V_11 , V_123 = 0 ;
int V_124 ;
int V_125 , V_126 ;
int V_52 , V_56 ;
F_37 ( L_7 ) ;
F_16 () ;
F_23 ( 1 ) ;
V_52 = V_21 -> V_46 . V_8 + V_21 -> V_46 . V_53 ;
V_56 = V_52 + V_21 -> V_46 . V_55 + V_21 -> V_46 . V_57 ;
if ( F_9 ( & V_21 -> V_46 , V_4 ) )
return - V_94 ;
V_4 -> V_68 [ 16 ] = 0x01 ;
switch ( V_21 -> V_46 . V_84 ) {
case 8 :
V_4 -> V_63 [ 0x13 ] = V_21 -> V_46 . V_66 >> 3 ;
V_4 -> V_127 = V_21 -> V_46 . V_66 >> 11 ;
V_4 -> V_128 = 0x11 ;
break;
case 16 :
V_4 -> V_63 [ 0x13 ] = V_21 -> V_46 . V_66 >> 2 ;
V_4 -> V_127 = V_21 -> V_46 . V_66 >> 10 ;
V_4 -> V_128 = 0x13 ;
break;
case 24 :
V_4 -> V_63 [ 0x13 ] = ( V_21 -> V_46 . V_66 * 3 ) >> 3 ;
V_4 -> V_127 = ( V_21 -> V_46 . V_66 * 3 ) >> 11 ;
V_4 -> V_128 = 0x14 ;
break;
#ifdef F_5
case 32 :
V_4 -> V_63 [ 0x13 ] = V_21 -> V_46 . V_66 >> 1 ;
V_4 -> V_127 = V_21 -> V_46 . V_66 >> 9 ;
V_4 -> V_128 = 0x15 ;
break;
#endif
default:
break;
}
V_4 -> V_129 = 0x10 ;
V_4 -> V_130 = ( ( ( V_56 - 2 ) & 0x400 ) >> 10 )
| ( ( ( V_21 -> V_46 . V_8 - 1 ) & 0x400 ) >> 9 )
| ( ( ( V_52 ) & 0x400 ) >> 8 )
| ( ( ( V_52 ) & 0x400 ) >> 7 ) ;
if ( V_4 -> V_131 )
V_4 -> V_132 = 0x30 ;
else
V_4 -> V_132 = 0x00 ;
V_4 -> V_133 = 0xc0 ;
V_4 -> V_134 = 1 ;
V_4 -> V_135 = 0x00 ;
if ( V_4 -> V_100 )
V_4 -> V_135 |= 0x02 ;
if ( V_4 -> V_136 )
V_4 -> V_135 |= 0x01 ;
if ( V_4 -> V_135 == 0x00 ) {
V_4 -> V_135 = F_40 ( NULL , 0x20 ) & 0x03 ;
}
switch ( V_21 -> V_46 . V_7 ) {
case 1280 :
V_4 -> V_135 |= 0x60 ;
break;
case 1024 :
V_4 -> V_135 |= 0x40 ;
break;
case 800 :
V_4 -> V_135 |= 0x20 ;
break;
case 640 :
default:
break;
}
switch ( V_4 -> V_135 & 0x03 ) {
case 0x01 :
V_4 -> V_137 = 0x00 ;
V_4 -> V_138 = 1 ;
break;
case 0x02 :
case 0x03 :
V_4 -> V_137 = 0x01 ;
V_4 -> V_138 = 0 ;
break;
}
V_4 -> V_139 = 0x00 ;
V_4 -> V_140 = 0x00 ;
if ( V_4 -> V_124 && ( V_4 -> V_135 == 0x02 ) &&
( V_21 -> V_46 . V_7 != V_4 -> V_101 ) ) {
switch ( V_21 -> V_46 . V_7 ) {
case 320 :
case 400 :
case 640 :
case 800 :
case 1024 :
V_124 = 1 ;
V_4 -> V_139 |= 0xC6 ;
break;
default:
V_124 = 0 ;
}
} else
V_124 = 0 ;
V_4 -> V_141 = 0x00 ;
V_4 -> V_142 = 0x00 ;
V_4 -> V_143 = 0x00 ;
V_4 -> V_144 = 0x00 ;
V_4 -> V_145 = 0x00 ;
V_4 -> V_146 = 0x00 ;
V_4 -> V_147 = 0x00 ;
V_4 -> V_148 = 0x00 ;
V_4 -> V_149 = 0x00 ;
V_4 -> V_150 = 0x00 ;
if ( V_4 -> V_135 & 0x02 ) {
if ( V_21 -> V_46 . V_7 == V_4 -> V_101 ) {
} else {
V_4 -> V_139 |= 0x01 ;
V_4 -> V_140 |= 0x10 ;
if ( ! V_124 ) {
V_125 =
( ( V_4 -> V_101 -
V_21 -> V_46 . V_7 ) >> 4 ) - 1 ;
V_126 =
( ( V_4 -> V_102 -
V_21 -> V_46 . V_8 ) >> 1 ) - 2 ;
} else {
V_125 = 0 ;
V_126 = 0 ;
}
switch ( V_21 -> V_46 . V_7 ) {
case 320 :
V_4 -> V_148 = V_125 ;
V_4 -> V_142 = V_126 ;
break;
case 400 :
V_4 -> V_149 = V_125 ;
V_4 -> V_141 = V_126 ;
break;
case 640 :
V_4 -> V_146 = V_125 ;
V_4 -> V_143 = V_126 ;
break;
case 800 :
V_4 -> V_147 = V_125 ;
V_4 -> V_144 = V_126 ;
break;
case 1024 :
V_4 -> V_150 = V_125 ;
V_4 -> V_145 = V_126 ;
break;
case 1280 :
default:
break;
}
}
}
V_4 -> T_2 =
F_3 ( V_21 -> V_46 . V_7 , V_21 -> V_46 . V_8 ,
V_21 -> V_46 . V_84 ) ;
F_6 ( V_21 , V_4 , F_38 ( V_21 -> V_46 . V_98 ) ) ;
V_4 -> V_58 |= 0x0C ;
F_15 ( NULL , 0x15 , 0x00 ) ;
F_15 ( NULL , 0x0A , V_4 -> V_137 ) ;
V_122 = F_40 ( NULL , 0x90 ) ;
switch ( V_21 -> V_35 . V_36 ) {
case V_151 :
V_122 &= 0xF0 ;
V_122 |= ( V_4 -> V_128 & ~ 0xF0 ) ;
break;
case V_152 :
case V_153 :
case V_154 :
case V_155 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_122 &= 0x70 ;
V_122 |= ( V_4 -> V_128 & ~ 0x70 ) ;
break;
}
F_15 ( NULL , 0x90 , V_122 ) ;
V_122 = F_40 ( NULL , 0x25 ) ;
V_122 &= 0x39 ;
F_15 ( NULL , 0x25 , V_122 ) ;
F_41 ( 200 ) ;
F_26 ( V_21 , V_4 ) ;
switch ( V_21 -> V_46 . V_84 ) {
case 8 :
V_21 -> V_35 . V_156 = V_157 ;
break;
case 16 :
V_21 -> V_35 . V_156 = V_158 ;
for ( V_11 = 0 ; V_11 < 64 ; V_11 ++ ) {
F_42 ( V_11 , 0x3c8 ) ;
F_42 ( V_11 << 1 , 0x3c9 ) ;
F_42 ( V_11 , 0x3c9 ) ;
F_42 ( V_11 << 1 , 0x3c9 ) ;
}
break;
case 24 :
#ifdef F_5
case 32 :
#endif
V_21 -> V_35 . V_156 = V_158 ;
for ( V_11 = 0 ; V_11 < 256 ; V_11 ++ ) {
F_42 ( V_11 , 0x3c8 ) ;
F_42 ( V_11 , 0x3c9 ) ;
F_42 ( V_11 , 0x3c9 ) ;
F_42 ( V_11 , 0x3c9 ) ;
}
break;
}
F_15 ( NULL , 0x0E , V_4 -> V_129 ) ;
F_15 ( NULL , 0x0F , V_4 -> V_127 ) ;
V_122 = F_40 ( NULL , 0x10 ) ;
V_122 &= 0x0F ;
V_122 |= ( V_4 -> V_132 & ~ 0x0F ) ;
F_15 ( NULL , 0x10 , V_122 ) ;
F_15 ( NULL , 0x11 , V_4 -> V_133 ) ;
F_15 ( NULL , 0x15 , 0 ) ;
F_15 ( NULL , 0x16 , 0 ) ;
V_122 = F_40 ( NULL , 0x20 ) ;
switch ( V_21 -> V_35 . V_36 ) {
case V_151 :
V_122 &= 0xFC ;
V_122 |= ( V_4 -> V_135 & ~ 0xFC ) ;
break;
case V_152 :
case V_153 :
case V_154 :
case V_155 :
V_122 &= 0xDC ;
V_122 |= ( V_4 -> V_135 & ~ 0xDC ) ;
break;
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_122 &= 0x98 ;
V_122 |= ( V_4 -> V_135 & ~ 0x98 ) ;
break;
}
F_15 ( NULL , 0x20 , V_122 ) ;
V_122 = F_40 ( NULL , 0x25 ) ;
V_122 &= 0x38 ;
V_122 |= ( V_4 -> V_139 & ~ 0x38 ) ;
F_15 ( NULL , 0x25 , V_122 ) ;
if ( V_21 -> V_35 . V_36 != V_151 ) {
V_122 = F_40 ( NULL , 0x30 ) ;
V_122 &= 0xEF ;
V_122 |= ( V_4 -> V_140 & ~ 0xEF ) ;
F_15 ( NULL , 0x30 , V_122 ) ;
}
F_15 ( NULL , 0x28 , V_4 -> V_141 ) ;
F_15 ( NULL , 0x29 , V_4 -> V_142 ) ;
F_15 ( NULL , 0x2a , V_4 -> V_143 ) ;
if ( V_21 -> V_35 . V_36 != V_151 ) {
F_15 ( NULL , 0x32 , V_4 -> V_144 ) ;
F_15 ( NULL , 0x33 , V_4 -> V_146 ) ;
F_15 ( NULL , 0x34 , V_4 -> V_147 ) ;
F_15 ( NULL , 0x35 , V_4 -> V_148 ) ;
}
if ( V_21 -> V_35 . V_36 == V_155 )
F_15 ( NULL , 0x36 , V_4 -> V_149 ) ;
if ( V_21 -> V_35 . V_36 == V_37 ||
V_21 -> V_35 . V_36 == V_38 ||
V_21 -> V_35 . V_36 == V_39 ||
V_21 -> V_35 . V_36 == V_40 ) {
F_15 ( NULL , 0x36 , V_4 -> V_149 ) ;
F_15 ( NULL , 0x37 , V_4 -> V_145 ) ;
F_15 ( NULL , 0x38 , V_4 -> V_150 ) ;
V_123 = 1 ;
}
if ( V_4 -> V_138 && ( ( F_40 ( NULL , 0x9B ) != V_4 -> V_41 )
|| ( F_40 ( NULL , 0x9F ) != V_4 -> V_43 )
|| ( V_123 && ( ( F_40 ( NULL , 0x8F ) & ~ 0x0f )
!= ( V_4 -> V_42 &
~ 0x0F ) ) ) ) ) {
F_15 ( NULL , 0x9B , V_4 -> V_41 ) ;
if ( V_123 ) {
V_122 = F_40 ( NULL , 0x8F ) ;
V_122 &= 0x0F ;
V_122 |= ( V_4 -> V_42 & ~ 0x0F ) ;
F_15 ( NULL , 0x8F , V_122 ) ;
}
F_15 ( NULL , 0x9F , V_4 -> V_43 ) ;
}
if ( V_4 -> T_2 )
F_11 ( NULL , 0x23 , V_4 -> T_2 ) ;
F_15 ( NULL , 0x93 , 0xc0 ) ;
if ( V_21 -> V_35 . V_36 == V_37 ||
V_21 -> V_35 . V_36 == V_38 ||
V_21 -> V_35 . V_36 == V_39 ||
V_21 -> V_35 . V_36 == V_40 ) {
F_11 ( NULL , 0x70 , V_4 -> V_130 ) ;
}
F_23 ( 0 ) ;
F_14 ( & V_4 -> V_70 ) ;
V_21 -> V_35 . V_159 =
V_21 -> V_46 . V_66 * ( V_21 -> V_46 . V_84 >> 3 ) ;
switch ( V_21 -> V_35 . V_36 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
F_31 ( V_21 , & V_21 -> V_46 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_43 ( struct V_45 * V_46 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
struct V_69 * V_70 = & V_4 -> V_70 ;
int V_160 ;
int V_161 ;
F_37 ( L_8 ) ;
V_161 = ( V_46 -> V_116 * V_21 -> V_46 . V_66 + V_46 -> V_115 ) >> 2 ;
V_161 *= ( V_21 -> V_46 . V_84 + 7 ) / 8 ;
F_16 () ;
F_11 ( V_70 -> V_71 , 0x0C , ( V_161 & 0x00FF00 ) >> 8 ) ;
F_11 ( V_70 -> V_71 , 0x0D , ( V_161 & 0x00FF ) ) ;
V_160 = F_40 ( NULL , 0x0E ) ;
F_15 ( V_70 -> V_71 , 0x0E , ( ( ( V_161 >> 16 ) & 0x0f ) | ( V_160 & 0xf0 ) ) ) ;
F_14 ( V_70 ) ;
return 0 ;
}
static int F_44 ( T_6 V_162 , T_6 V_105 , T_6 V_107 , T_6 V_108 ,
T_6 V_109 , struct V_20 * V_163 )
{
if ( V_162 >= V_163 -> V_164 . V_165 || V_162 > 255 )
return - V_94 ;
if ( V_163 -> V_46 . V_84 <= 8 ) {
F_42 ( V_162 , 0x3c8 ) ;
F_42 ( V_105 >> 10 , 0x3c9 ) ;
F_42 ( V_107 >> 10 , 0x3c9 ) ;
F_42 ( V_108 >> 10 , 0x3c9 ) ;
} else if ( V_162 < 16 ) {
switch ( V_163 -> V_46 . V_84 ) {
case 16 :
( ( T_1 * ) V_163 -> V_166 ) [ V_162 ] =
( ( V_105 & 0xf800 ) ) | ( ( V_107 & 0xfc00 ) >> 5 ) |
( ( V_108 & 0xf800 ) >> 11 ) ;
break;
case 24 :
( ( T_1 * ) V_163 -> V_166 ) [ V_162 ] =
( ( V_105 & 0xff00 ) << 8 ) | ( ( V_107 & 0xff00 ) ) |
( ( V_108 & 0xff00 ) >> 8 ) ;
break;
#ifdef F_5
case 32 :
( ( T_1 * ) V_163 -> V_166 ) [ V_162 ] =
( ( V_109 & 0xff00 ) << 16 ) | ( ( V_105 & 0xff00 ) << 8 ) |
( ( V_107 & 0xff00 ) ) | ( ( V_108 & 0xff00 ) >> 8 ) ;
break;
#endif
default:
return 1 ;
}
}
return 0 ;
}
static int F_45 ( int V_167 , struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
int V_168 , V_169 , V_170 , V_171 , V_172 ;
F_16 () ;
V_172 = F_40 ( NULL , 0x20 ) & 0x03 ;
F_14 ( & V_4 -> V_70 ) ;
if ( V_4 -> V_134 ) {
V_4 -> V_135 = V_172 ;
}
V_4 -> V_134 = ! V_167 ;
switch ( V_167 ) {
case V_173 :
V_168 = V_174 ;
V_169 = 0 ;
V_170 = V_175 |
V_176 ;
#ifdef F_46
{
T_7 V_177 ;
V_177 . V_178 = 0xff00 ;
V_177 . V_179 = 0x0002 ;
V_177 . V_180 = 0x0000 ;
F_47 ( & V_177 ) ;
}
#endif
break;
case V_181 :
V_168 = V_174 ;
V_169 = 0 ;
V_170 = V_175 ;
break;
case V_182 :
V_168 = V_174 ;
V_169 = 0 ;
V_170 = V_176 ;
break;
case V_183 :
V_168 = V_174 ;
V_169 = ( ( V_4 -> V_135 | V_172 ) & 0x02 ) ;
V_170 = 0x00 ;
break;
case V_184 :
V_168 = 0 ;
V_169 = ( ( V_4 -> V_135 | V_172 ) & 0x02 ) ;
V_170 = 0x00 ;
#ifdef F_46
{
T_7 V_177 ;
V_177 . V_178 = 0xff00 ;
V_177 . V_179 = 0x0002 ;
V_177 . V_180 = 0x0001 ;
F_47 ( & V_177 ) ;
}
#endif
break;
default:
return 1 ;
}
F_16 () ;
V_171 = ( F_24 ( NULL , 0x01 ) & ~ 0x20 ) | V_168 ;
F_25 ( NULL , 0x01 , V_171 ) ;
V_171 = ( F_40 ( NULL , 0x20 ) & ~ 0x02 ) | V_169 ;
F_15 ( NULL , 0x20 , V_171 ) ;
V_171 = ( F_40 ( NULL , 0x01 ) & ~ 0xF0 ) | 0x80 | V_170 ;
F_15 ( NULL , 0x01 , V_171 ) ;
F_14 ( & V_4 -> V_70 ) ;
return 0 ;
}
static void
F_48 ( struct V_20 * V_21 , const struct V_185 * V_186 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
T_8 V_187 , V_188 ;
V_187 = V_186 -> V_189 + V_186 -> V_190 * V_21 -> V_46 . V_66 ;
V_188 = V_186 -> V_188 ? 0x060000 : 0x0c0000 ;
F_30 ( V_21 , 4 ) ;
F_2 ( V_191 |
V_192 | V_193 |
V_188 , & V_4 -> V_5 -> V_194 ) ;
switch ( V_21 -> V_46 . V_84 ) {
case 8 :
F_2 ( V_186 -> V_195 , & V_4 -> V_5 -> V_196 ) ;
break;
case 16 :
case 24 :
F_2 ( ( ( T_1 * ) ( V_21 -> V_166 ) ) [ V_186 -> V_195 ] ,
& V_4 -> V_5 -> V_196 ) ;
break;
}
F_2 ( V_187 * ( ( V_21 -> V_46 . V_84 + 7 ) >> 3 ) ,
& V_4 -> V_5 -> V_197 ) ;
F_2 ( ( V_186 -> V_118 << 16 ) | ( V_186 -> V_119 & 0xffff ) ,
& V_4 -> V_5 -> V_198 ) ;
}
static void
F_49 ( struct V_20 * V_21 , const struct V_199 * V_200 )
{
T_1 V_201 = V_200 -> V_201 , V_202 = V_200 -> V_202 , V_189 = V_200 -> V_189 , V_190 = V_200 -> V_190 ;
struct V_3 * V_4 = V_21 -> V_4 ;
T_8 V_203 , V_187 , V_194 ;
V_194 = V_191 | V_193 | 0x0C0000 ;
if ( ( V_190 > V_202 ) || ( ( V_190 == V_202 ) && ( V_189 > V_201 ) ) ) {
V_202 += ( V_200 -> V_118 - 1 ) ;
V_190 += ( V_200 -> V_118 - 1 ) ;
V_201 += ( V_200 -> V_119 - 1 ) ;
V_189 += ( V_200 -> V_119 - 1 ) ;
V_194 |= V_204 | V_205 | V_206 ;
}
V_203 = V_201 * ( V_21 -> V_46 . V_84 >> 3 ) + V_202 * V_21 -> V_35 . V_159 ;
V_187 = V_189 * ( V_21 -> V_46 . V_84 >> 3 ) + V_190 * V_21 -> V_35 . V_159 ;
F_30 ( V_21 , 4 ) ;
F_2 ( V_194 , & V_4 -> V_5 -> V_194 ) ;
F_2 ( V_203 , & V_4 -> V_5 -> V_207 ) ;
F_2 ( V_187 , & V_4 -> V_5 -> V_197 ) ;
F_2 ( ( V_200 -> V_118 << 16 ) | ( V_200 -> V_119 & 0xffff ) ,
& V_4 -> V_5 -> V_198 ) ;
}
static void
F_50 ( struct V_20 * V_21 , const struct V_208 * V_209 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
int V_210 = ( V_209 -> V_119 * V_209 -> V_9 + 7 ) >> 3 ;
int V_211 = V_21 -> V_212 . V_211 - 1 ;
int V_213 = V_21 -> V_212 . V_213 - 1 ;
int V_214 , V_215 , V_216 ;
V_215 = ( V_210 + V_211 ) & ~ V_211 ;
V_216 = ( ( V_215 * V_209 -> V_118 ) + V_213 ) & ~ V_213 ;
F_27 ( V_21 ) ;
if ( V_209 -> V_9 == 1 ) {
if ( V_21 -> V_46 . V_84 == 24 && V_209 -> V_119 < 16 ) {
F_51 ( V_21 , V_209 ) ;
return;
}
V_214 = V_217 ;
} else if ( V_209 -> V_9 == V_21 -> V_46 . V_84 ) {
V_214 = 0 ;
} else {
F_51 ( V_21 , V_209 ) ;
return;
}
switch ( V_21 -> V_46 . V_84 ) {
case 8 :
F_2 ( V_209 -> V_218 , & V_4 -> V_5 -> V_196 ) ;
F_2 ( V_209 -> V_219 , & V_4 -> V_5 -> V_220 ) ;
break;
case 16 :
case 24 :
F_2 ( ( ( T_1 * ) ( V_21 -> V_166 ) ) [ V_209 -> V_218 ] ,
& V_4 -> V_5 -> V_196 ) ;
F_2 ( ( ( T_1 * ) ( V_21 -> V_166 ) ) [ V_209 -> V_219 ] ,
& V_4 -> V_5 -> V_220 ) ;
break;
}
F_2 ( V_221 |
V_193 | V_214 |
0x0c0000 , & V_4 -> V_5 -> V_194 ) ;
F_2 ( 0 , & V_4 -> V_5 -> V_207 ) ;
F_2 ( ( ( V_209 -> V_189 & 0xffff ) * ( V_21 -> V_46 . V_84 >> 3 ) +
V_209 -> V_190 * V_21 -> V_35 . V_159 ) , & V_4 -> V_5 -> V_197 ) ;
F_2 ( ( V_209 -> V_118 << 16 ) | ( V_209 -> V_119 & 0xffff ) ,
& V_4 -> V_5 -> V_198 ) ;
F_52 ( V_4 -> V_222 + 0x100000 , V_209 -> V_223 , V_216 ) ;
}
static void
F_53 ( struct V_20 * V_21 , const struct V_185 * V_186 )
{
switch ( V_21 -> V_35 . V_36 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
F_48 ( V_21 , V_186 ) ;
break;
default:
F_54 ( V_21 , V_186 ) ;
break;
}
}
static void
F_55 ( struct V_20 * V_21 , const struct V_199 * V_200 )
{
switch ( V_21 -> V_35 . V_36 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
F_49 ( V_21 , V_200 ) ;
break;
default:
F_56 ( V_21 , V_200 ) ;
break;
}
}
static void
F_57 ( struct V_20 * V_21 , const struct V_208 * V_209 )
{
switch ( V_21 -> V_35 . V_36 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
F_50 ( V_21 , V_209 ) ;
break;
default:
F_51 ( V_21 , V_209 ) ;
break;
}
}
static int
F_58 ( struct V_20 * V_21 )
{
switch ( V_21 -> V_35 . V_36 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
F_27 ( V_21 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_59 ( struct V_20 * V_21 , struct V_224 * V_225 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
F_37 ( L_9 ) ;
switch ( V_21 -> V_35 . V_36 ) {
case V_151 :
V_21 -> V_35 . V_226 = F_60 ( V_225 , 0 ) +
0x100000 ;
break;
case V_152 :
case V_153 :
V_21 -> V_35 . V_226 = F_60 ( V_225 , 0 ) +
0x200000 ;
break;
case V_155 :
case V_154 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_21 -> V_35 . V_226 = F_60 ( V_225 , 1 ) ;
break;
default:
V_21 -> V_35 . V_226 = F_60 ( V_225 , 0 ) ;
}
V_21 -> V_35 . V_227 = V_228 ;
if ( ! F_61
( V_21 -> V_35 . V_226 , V_228 , L_10 ) ) {
F_8 ( L_11 ) ;
return - V_229 ;
}
V_4 -> V_222 = F_62 ( V_21 -> V_35 . V_226 , V_228 ) ;
if ( ! V_4 -> V_222 ) {
F_8 ( L_12 ) ;
F_63 ( V_21 -> V_35 . V_226 ,
V_21 -> V_35 . V_227 ) ;
return - V_230 ;
} else
F_8 ( V_103 L_13 ,
V_4 -> V_222 ) ;
return 0 ;
}
static void F_64 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
F_37 ( L_14 ) ;
F_65 ( V_4 -> V_222 ) ;
V_4 -> V_222 = NULL ;
F_63 ( V_21 -> V_35 . V_226 ,
V_21 -> V_35 . V_227 ) ;
}
static int F_66 ( struct V_20 * V_21 , struct V_224 * V_225 ,
int V_231 )
{
F_37 ( L_15 ) ;
V_21 -> V_35 . V_232 = F_60 ( V_225 , 0 ) ;
V_21 -> V_35 . V_113 = V_231 ;
if ( ! F_61 ( V_21 -> V_35 . V_232 , V_21 -> V_35 . V_113 ,
L_16 ) ) {
F_8 ( L_17 ) ;
return - V_229 ;
}
V_21 -> V_233 =
F_62 ( V_21 -> V_35 . V_232 , V_21 -> V_35 . V_113 ) ;
if ( ! V_21 -> V_233 ) {
F_8 ( L_18 ) ;
F_63 ( V_21 -> V_35 . V_232 ,
V_21 -> V_35 . V_113 ) ;
return - V_230 ;
} else
F_8 ( V_103 L_19 ,
V_21 -> V_233 ) ;
#ifdef F_67
( (struct V_3 * ) ( V_21 -> V_4 ) ) -> V_234 =
F_68 ( V_21 -> V_35 . V_232 , F_69 ( V_225 , 0 ) ,
V_235 , 1 ) ;
#endif
F_70 ( V_21 -> V_233 , 0 , V_21 -> V_35 . V_113 ) ;
return 0 ;
}
static void F_71 ( struct V_20 * V_21 )
{
F_37 ( L_20 ) ;
#ifdef F_67
{
struct V_3 * V_4 = V_21 -> V_4 ;
F_72 ( V_4 -> V_234 , V_21 -> V_35 . V_232 ,
V_21 -> V_35 . V_113 ) ;
}
#endif
F_65 ( V_21 -> V_233 ) ;
V_21 -> V_233 = NULL ;
F_63 ( V_21 -> V_35 . V_232 ,
V_21 -> V_35 . V_113 ) ;
}
static int F_73 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
unsigned char type , V_236 ;
int V_237 ;
V_21 -> V_238 . V_239 = F_74 ( sizeof( struct V_240 ) , V_241 ) ;
if ( ! V_21 -> V_238 . V_239 )
return - V_230 ;
V_21 -> V_238 . V_242 = 1 ;
F_15 ( NULL , 0x09 , 0x26 ) ;
type = F_40 ( NULL , 0x21 ) ;
V_236 = F_40 ( NULL , 0x20 ) ;
if ( ! V_4 -> V_100 && ! V_4 -> V_136 ) {
V_4 -> V_100 = V_236 & 2 || ! ( V_236 & 3 ) ? 1 : 0 ;
V_4 -> V_136 = V_236 & 1 ;
F_8 ( V_103 L_21 ,
V_4 -> V_100 && V_4 -> V_136 ? L_22 :
V_4 -> V_100 ? L_23 : L_24 ) ;
}
V_237 = F_40 ( NULL , 0x20 ) ;
F_15 ( NULL , 0x09 , 0x00 ) ;
switch ( ( V_237 & 0x18 ) >> 3 ) {
case 0x00 :
V_4 -> V_101 = 640 ;
V_4 -> V_102 = 480 ;
memcpy ( V_21 -> V_238 . V_239 , & V_243 [ 3 ] , sizeof( struct V_240 ) ) ;
break;
case 0x01 :
V_4 -> V_101 = 800 ;
if ( V_4 -> V_104 ) {
V_4 -> V_102 = 480 ;
memcpy ( V_21 -> V_238 . V_239 , & V_244 , sizeof( struct V_240 ) ) ;
} else {
V_4 -> V_102 = 600 ;
memcpy ( V_21 -> V_238 . V_239 , & V_243 [ 8 ] , sizeof( struct V_240 ) ) ;
}
break;
case 0x02 :
V_4 -> V_101 = 1024 ;
V_4 -> V_102 = 768 ;
memcpy ( V_21 -> V_238 . V_239 , & V_243 [ 13 ] , sizeof( struct V_240 ) ) ;
break;
case 0x03 :
#ifdef F_75
V_4 -> V_101 = 1280 ;
V_4 -> V_102 = 1024 ;
memcpy ( V_21 -> V_238 . V_239 , & V_243 [ 20 ] , sizeof( struct V_240 ) ) ;
break;
#else
F_8 ( V_88
L_25 ) ;
return - 1 ;
#endif
default:
V_4 -> V_101 = 640 ;
V_4 -> V_102 = 480 ;
memcpy ( V_21 -> V_238 . V_239 , & V_243 [ 3 ] , sizeof( struct V_240 ) ) ;
break;
}
F_8 ( V_103 L_26 ,
V_4 -> V_101 ,
V_4 -> V_102 ,
( type & 0x02 ) ? L_27 : L_28 ,
( type & 0x10 ) ? L_29 : L_30 ) ;
return 0 ;
}
static int F_76 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = V_21 -> V_4 ;
int V_245 = 896 ;
int V_99 = 65000 ;
int V_246 = 1024 ;
int V_247 = 0x100 ;
F_37 ( L_31 ) ;
F_16 () ;
#if 0
printk(KERN_DEBUG "--- Neo extended register dump ---\n");
for (int w = 0; w < 0x85; w++)
printk(KERN_DEBUG "CR %p: %p\n", (void *) w,
(void *) vga_rcrt(NULL, w));
for (int w = 0; w < 0xC7; w++)
printk(KERN_DEBUG "GR %p: %p\n", (void *) w,
(void *) vga_rgfx(NULL, w));
#endif
switch ( V_21 -> V_35 . V_36 ) {
case V_151 :
V_245 = 896 ;
V_99 = 65000 ;
break;
case V_152 :
case V_153 :
case V_154 :
V_245 = 1152 ;
V_99 = 80000 ;
break;
case V_155 :
V_245 = 2048 ;
V_99 = 90000 ;
break;
case V_37 :
V_245 = 2560 ;
V_99 = 110000 ;
break;
case V_38 :
V_245 = 3008 ;
V_99 = 110000 ;
break;
case V_39 :
V_245 = 4096 ;
V_99 = 110000 ;
break;
case V_40 :
V_245 = 6144 ;
V_99 = 110000 ;
break;
}
switch ( V_21 -> V_35 . V_36 ) {
case V_151 :
case V_152 :
case V_153 :
V_246 = 2048 ;
V_247 = 0x100 ;
break;
case V_154 :
case V_155 :
V_246 = 1024 ;
V_247 = 0x100 ;
break;
case V_37 :
case V_38 :
case V_39 :
case V_40 :
V_246 = 1024 ;
V_247 = 0x1000 ;
V_4 -> V_5 = ( T_4 T_5 * ) V_4 -> V_222 ;
break;
}
V_4 -> V_99 = V_99 ;
V_4 -> V_6 = V_247 ;
return V_245 * 1024 ;
}
static struct V_20 * F_77 ( struct V_224 * V_225 ,
const struct V_248 * V_249 )
{
struct V_20 * V_21 ;
struct V_3 * V_4 ;
V_21 = F_78 ( sizeof( struct V_3 ) , & V_225 -> V_225 ) ;
if ( ! V_21 )
return NULL ;
V_4 = V_21 -> V_4 ;
V_21 -> V_35 . V_36 = V_249 -> V_250 ;
V_4 -> V_131 = ! V_251 ;
V_4 -> V_124 = ! V_252 ;
V_4 -> V_104 = V_104 ;
V_4 -> V_100 = V_253 ;
V_4 -> V_136 = V_254 ;
V_21 -> V_91 = V_255 | V_256 ;
switch ( V_21 -> V_35 . V_36 ) {
case V_151 :
snprintf ( V_21 -> V_35 . V_249 , sizeof( V_21 -> V_35 . V_249 ) ,
L_32 ) ;
break;
case V_152 :
snprintf ( V_21 -> V_35 . V_249 , sizeof( V_21 -> V_35 . V_249 ) ,
L_33 ) ;
break;
case V_153 :
snprintf ( V_21 -> V_35 . V_249 , sizeof( V_21 -> V_35 . V_249 ) ,
L_34 ) ;
break;
case V_154 :
snprintf ( V_21 -> V_35 . V_249 , sizeof( V_21 -> V_35 . V_249 ) ,
L_35 ) ;
break;
case V_155 :
snprintf ( V_21 -> V_35 . V_249 , sizeof( V_21 -> V_35 . V_249 ) ,
L_36 ) ;
break;
case V_37 :
snprintf ( V_21 -> V_35 . V_249 , sizeof( V_21 -> V_35 . V_249 ) ,
L_37 ) ;
V_21 -> V_91 |= V_257 |
V_258 |
V_259 ;
break;
case V_38 :
snprintf ( V_21 -> V_35 . V_249 , sizeof( V_21 -> V_35 . V_249 ) ,
L_38 ) ;
V_21 -> V_91 |= V_257 |
V_258 |
V_259 ;
break;
case V_39 :
snprintf ( V_21 -> V_35 . V_249 , sizeof( V_21 -> V_35 . V_249 ) ,
L_39 ) ;
V_21 -> V_91 |= V_257 |
V_258 |
V_259 ;
break;
case V_40 :
snprintf ( V_21 -> V_35 . V_249 , sizeof( V_21 -> V_35 . V_249 ) ,
L_40 ) ;
V_21 -> V_91 |= V_257 |
V_258 |
V_259 ;
break;
}
V_21 -> V_35 . type = V_260 ;
V_21 -> V_35 . V_261 = 0 ;
V_21 -> V_35 . V_262 = 0 ;
V_21 -> V_35 . V_263 = 4 ;
V_21 -> V_35 . V_264 = 0 ;
V_21 -> V_35 . V_36 = V_249 -> V_250 ;
V_21 -> V_265 = & V_266 ;
V_21 -> V_166 = V_4 -> V_267 ;
return V_21 ;
}
static void F_79 ( struct V_20 * V_21 )
{
if ( V_21 ) {
F_80 ( & V_21 -> V_164 ) ;
F_81 ( V_21 ) ;
}
}
static int F_82 ( struct V_224 * V_225 , const struct V_248 * V_249 )
{
struct V_20 * V_21 ;
T_6 V_268 , V_269 ;
int V_231 , V_270 ;
F_37 ( L_41 ) ;
V_270 = F_83 ( V_225 ) ;
if ( V_270 )
return V_270 ;
V_270 = - V_230 ;
V_21 = F_77 ( V_225 , V_249 ) ;
if ( ! V_21 )
return V_270 ;
V_270 = F_59 ( V_21 , V_225 ) ;
if ( V_270 )
goto V_271;
V_270 = F_73 ( V_21 ) ;
if ( V_270 )
goto V_272;
V_231 = F_76 ( V_21 ) ;
if ( V_231 < 0 ) {
V_270 = V_231 ;
goto V_273;
}
V_270 = F_66 ( V_21 , V_225 , V_231 ) ;
if ( V_270 )
goto V_273;
if ( ! F_84 ( & V_21 -> V_46 , V_21 , V_274 , NULL , 0 ,
V_21 -> V_238 . V_239 , 16 ) ) {
F_8 ( V_88 L_42 ) ;
goto V_275;
}
V_268 = 1953125000 / V_21 -> V_46 . V_98 ;
V_268 =
V_268 * 512 / ( V_21 -> V_46 . V_7 + V_21 -> V_46 . V_51 +
V_21 -> V_46 . V_48 + V_21 -> V_46 . V_49 ) ;
V_269 =
V_268 / ( V_21 -> V_46 . V_8 + V_21 -> V_46 . V_57 +
V_21 -> V_46 . V_53 + V_21 -> V_46 . V_55 ) ;
F_8 ( V_103 L_43 V_276
L_44 ,
V_21 -> V_35 . V_113 >> 10 , V_21 -> V_46 . V_7 ,
V_21 -> V_46 . V_8 , V_268 / 1000 , V_268 % 1000 , V_269 ) ;
if ( F_85 ( & V_21 -> V_164 , 256 , 0 ) < 0 )
goto V_275;
V_270 = F_86 ( V_21 ) ;
if ( V_270 < 0 )
goto V_277;
F_8 ( V_103 L_45 ,
V_21 -> V_278 , V_21 -> V_35 . V_249 ) ;
F_87 ( V_225 , V_21 ) ;
return 0 ;
V_277:
F_80 ( & V_21 -> V_164 ) ;
V_275:
F_71 ( V_21 ) ;
V_273:
F_88 ( V_21 -> V_238 . V_239 ) ;
V_272:
F_64 ( V_21 ) ;
V_271:
F_79 ( V_21 ) ;
return V_270 ;
}
static void F_89 ( struct V_224 * V_225 )
{
struct V_20 * V_21 = F_90 ( V_225 ) ;
F_37 ( L_46 ) ;
if ( V_21 ) {
if ( F_91 ( V_21 ) )
F_8 ( V_112
L_47 ) ;
F_71 ( V_21 ) ;
F_88 ( V_21 -> V_238 . V_239 ) ;
F_64 ( V_21 ) ;
F_79 ( V_21 ) ;
F_87 ( V_225 , NULL ) ;
}
}
static int T_9 F_92 ( char * V_279 )
{
char * V_280 ;
F_37 ( L_48 ) ;
if ( ! V_279 || ! * V_279 )
return 0 ;
while ( ( V_280 = F_93 ( & V_279 , L_49 ) ) != NULL ) {
if ( ! * V_280 )
continue;
if ( ! strncmp ( V_280 , L_23 , 8 ) )
V_253 = 1 ;
else if ( ! strncmp ( V_280 , L_24 , 8 ) )
V_254 = 1 ;
else if ( ! strncmp ( V_280 , L_50 , 9 ) )
V_252 = 1 ;
else if ( ! strncmp ( V_280 , L_51 , 10 ) )
V_251 = 1 ;
else if ( ! strncmp ( V_280 , L_52 , 8 ) )
V_104 = 1 ;
else
V_274 = V_280 ;
}
return 0 ;
}
static int T_9 F_94 ( void )
{
#ifndef F_95
char * V_281 = NULL ;
if ( F_96 ( L_53 , & V_281 ) )
return - V_282 ;
F_92 ( V_281 ) ;
#endif
return F_97 ( & V_283 ) ;
}
static void T_10 F_98 ( void )
{
F_99 ( & V_283 ) ;
}

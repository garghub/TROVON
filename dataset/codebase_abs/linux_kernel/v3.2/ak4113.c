static void F_1 ( struct V_1 * V_1 , unsigned char V_2 ,
unsigned char V_3 )
{
V_1 -> V_4 ( V_1 -> V_5 , V_2 , V_3 ) ;
if ( V_2 < sizeof( V_1 -> V_6 ) )
V_1 -> V_6 [ V_2 ] = V_3 ;
}
static inline unsigned char F_2 ( struct V_1 * V_1 , unsigned char V_2 )
{
return V_1 -> V_7 ( V_1 -> V_5 , V_2 ) ;
}
static void F_3 ( struct V_1 * V_8 )
{
V_8 -> V_9 = 1 ;
F_4 () ;
F_5 ( & V_8 -> V_10 ) ;
F_6 ( V_8 ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_1 * V_8 = V_12 -> V_13 ;
F_3 ( V_8 ) ;
return 0 ;
}
int F_8 ( struct V_14 * V_15 , T_1 * V_7 ,
T_2 * V_4 , const unsigned char * V_16 ,
void * V_5 , struct V_1 * * V_17 )
{
struct V_1 * V_8 ;
int V_18 = 0 ;
unsigned char V_2 ;
static struct V_19 V_20 = {
. V_21 = F_7 ,
} ;
V_8 = F_9 ( sizeof( * V_8 ) , V_22 ) ;
if ( V_8 == NULL )
return - V_23 ;
F_10 ( & V_8 -> V_24 ) ;
V_8 -> V_15 = V_15 ;
V_8 -> V_7 = V_7 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_5 = V_5 ;
F_11 ( & V_8 -> V_10 , V_25 ) ;
for ( V_2 = 0 ; V_2 < V_26 ; V_2 ++ )
V_8 -> V_6 [ V_2 ] = V_16 [ V_2 ] ;
F_12 ( V_8 ) ;
V_8 -> V_27 = F_2 ( V_8 , V_28 ) & ~ ( V_29 |
V_30 | V_31 ) ;
V_8 -> V_32 = F_2 ( V_8 , V_33 ) ;
V_8 -> V_34 = F_2 ( V_8 , V_35 ) ;
V_18 = F_13 ( V_15 , V_36 , V_8 , & V_20 ) ;
if ( V_18 < 0 )
goto V_37;
if ( V_17 )
* V_17 = V_8 ;
return 0 ;
V_37:
F_3 ( V_8 ) ;
return V_18 < 0 ? V_18 : - V_38 ;
}
void F_14 ( struct V_1 * V_8 , unsigned char V_2 ,
unsigned char V_39 , unsigned char V_3 )
{
if ( V_2 >= V_26 )
return;
F_1 ( V_8 , V_2 , ( V_8 -> V_6 [ V_2 ] & ~ V_39 ) | V_3 ) ;
}
static void F_12 ( struct V_1 * V_8 )
{
unsigned char V_40 = V_8 -> V_6 [ V_41 ] , V_2 ;
F_1 ( V_8 , V_41 , V_40 & ~ ( V_42 | V_43 ) ) ;
F_15 ( 200 ) ;
F_1 ( V_8 , V_41 , ( V_40 | V_42 ) & ~ V_43 ) ;
F_15 ( 200 ) ;
for ( V_2 = 1 ; V_2 < V_26 ; V_2 ++ )
F_1 ( V_8 , V_2 , V_8 -> V_6 [ V_2 ] ) ;
F_1 ( V_8 , V_41 , V_40 | V_42 | V_43 ) ;
}
void F_16 ( struct V_1 * V_8 )
{
V_8 -> V_9 = 1 ;
F_4 () ;
F_17 ( & V_8 -> V_10 ) ;
F_12 ( V_8 ) ;
V_8 -> V_9 = 0 ;
if ( V_8 -> V_44 [ 0 ] )
F_18 ( & V_8 -> V_10 , V_45 / 10 ) ;
}
static unsigned int F_19 ( unsigned char V_32 )
{
switch ( V_32 & ( V_46 | V_47 | V_48 | V_49 ) ) {
case V_50 :
return 8000 ;
case V_51 :
return 11025 ;
case V_52 :
return 16000 ;
case V_53 :
return 22050 ;
case V_54 :
return 24000 ;
case V_55 :
return 32000 ;
case V_56 :
return 44100 ;
case V_57 :
return 48000 ;
case V_58 :
return 64000 ;
case V_59 :
return 88200 ;
case V_60 :
return 96000 ;
case V_61 :
return 176400 ;
case V_62 :
return 192000 ;
default:
return 0 ;
}
}
static int F_20 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_67 ;
V_66 -> V_68 = 1 ;
V_66 -> V_69 . integer . V_70 = 0 ;
V_66 -> V_69 . integer . V_71 = V_72 ;
return 0 ;
}
static int F_21 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_22 ( V_64 ) ;
long * V_75 ;
F_23 ( & V_8 -> V_24 ) ;
V_75 = ( long * ) ( ( ( char * ) V_8 ) + V_64 -> V_76 ) ;
V_74 -> V_69 . integer . V_69 [ 0 ] = * V_75 ;
* V_75 = 0 ;
F_24 ( & V_8 -> V_24 ) ;
return 0 ;
}
static int F_25 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_22 ( V_64 ) ;
unsigned char V_2 = V_64 -> V_76 & 0xff ;
unsigned char V_77 = ( V_64 -> V_76 >> 8 ) & 0xff ;
unsigned char V_78 = ( V_64 -> V_76 >> 31 ) & 1 ;
V_74 -> V_69 . integer . V_69 [ 0 ] =
( ( F_2 ( V_8 , V_2 ) & ( 1 << V_77 ) ) ? 1 : 0 ) ^ V_78 ;
return 0 ;
}
static int F_26 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_67 ;
V_66 -> V_68 = 1 ;
V_66 -> V_69 . integer . V_70 = 0 ;
V_66 -> V_69 . integer . V_71 = 5 ;
return 0 ;
}
static int F_27 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_22 ( V_64 ) ;
V_74 -> V_69 . integer . V_69 [ 0 ] =
( F_28 ( V_8 -> V_6 [ V_79 ] ) ) ;
return 0 ;
}
static int F_29 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_22 ( V_64 ) ;
int V_80 ;
T_3 V_81 ;
F_23 ( & V_8 -> V_24 ) ;
V_81 = V_8 -> V_6 [ V_79 ] ;
V_80 = V_74 -> V_69 . integer . V_69 [ 0 ] != F_28 ( V_81 ) ;
if ( V_80 )
F_1 ( V_8 , V_79 ,
( V_81 & ( ~ F_28 ( 0xff ) ) ) |
( F_28 ( V_74 -> V_69 . integer . V_69 [ 0 ] ) ) ) ;
F_24 ( & V_8 -> V_24 ) ;
return V_80 ;
}
static int F_30 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_67 ;
V_66 -> V_68 = 1 ;
V_66 -> V_69 . integer . V_70 = 0 ;
V_66 -> V_69 . integer . V_71 = 192000 ;
return 0 ;
}
static int F_31 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_22 ( V_64 ) ;
V_74 -> V_69 . integer . V_69 [ 0 ] = F_19 ( F_2 ( V_8 ,
V_33 ) ) ;
return 0 ;
}
static int F_32 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_82 ;
V_66 -> V_68 = 1 ;
return 0 ;
}
static int F_33 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_22 ( V_64 ) ;
unsigned V_83 ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ )
V_74 -> V_69 . V_85 . V_86 [ V_83 ] = F_2 ( V_8 ,
V_87 + V_83 ) ;
return 0 ;
}
static int F_34 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_82 ;
V_66 -> V_68 = 1 ;
return 0 ;
}
static int F_35 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
memset ( V_74 -> V_69 . V_85 . V_86 , 0xff , V_84 ) ;
return 0 ;
}
static int F_36 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_67 ;
V_66 -> V_69 . integer . V_70 = 0 ;
V_66 -> V_69 . integer . V_71 = 0xffff ;
V_66 -> V_68 = 4 ;
return 0 ;
}
static int F_37 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_22 ( V_64 ) ;
unsigned short V_88 ;
V_74 -> V_69 . integer . V_69 [ 0 ] = 0xf8f2 ;
V_74 -> V_69 . integer . V_69 [ 1 ] = 0x4e1f ;
V_88 = F_2 ( V_8 , V_89 ) |
( F_2 ( V_8 , V_90 ) << 8 ) ;
V_74 -> V_69 . integer . V_69 [ 2 ] = V_88 ;
V_88 = F_2 ( V_8 , V_91 ) |
( F_2 ( V_8 , V_92 ) << 8 ) ;
V_74 -> V_69 . integer . V_69 [ 3 ] = V_88 ;
return 0 ;
}
static int F_38 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_93 ;
V_66 -> V_68 = V_94 ;
return 0 ;
}
static int F_39 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_22 ( V_64 ) ;
unsigned V_83 ;
for ( V_83 = 0 ; V_83 < V_94 ; V_83 ++ )
V_74 -> V_69 . V_95 . V_96 [ V_83 ] = F_2 ( V_8 ,
V_97 + V_83 ) ;
return 0 ;
}
static void F_40 ( struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_1 * V_1 = V_99 -> V_5 ;
int V_2 , V_3 ;
for ( V_2 = 0 ; V_2 < 0x1d ; V_2 ++ ) {
V_3 = F_2 ( V_1 , V_2 ) ;
F_41 ( V_101 , L_1 , V_2 , V_3 ) ;
}
}
static void F_42 ( struct V_1 * V_1 )
{
struct V_98 * V_99 ;
if ( ! F_43 ( V_1 -> V_15 , L_2 , & V_99 ) )
F_44 ( V_99 , V_1 , F_40 ) ;
}
int F_45 ( struct V_1 * V_1 ,
struct V_102 * V_103 )
{
struct V_63 * V_104 ;
unsigned int V_105 ;
int V_18 ;
if ( F_46 ( ! V_103 ) )
return - V_106 ;
V_1 -> V_107 = V_103 ;
for ( V_105 = 0 ; V_105 < V_108 ; V_105 ++ ) {
V_104 = F_47 ( & V_109 [ V_105 ] , V_1 ) ;
if ( V_104 == NULL )
return - V_23 ;
V_104 -> V_110 . V_12 = V_103 -> V_111 -> V_12 ;
V_104 -> V_110 . V_112 = V_103 -> V_113 ;
V_18 = F_48 ( V_1 -> V_15 , V_104 ) ;
if ( V_18 < 0 )
return V_18 ;
V_1 -> V_44 [ V_105 ] = V_104 ;
}
F_42 ( V_1 ) ;
F_18 ( & V_1 -> V_10 , V_45 / 10 ) ;
return 0 ;
}
int F_49 ( struct V_1 * V_1 )
{
unsigned char V_32 ;
V_32 = F_2 ( V_1 , V_33 ) ;
return F_19 ( V_32 ) ;
}
int F_50 ( struct V_1 * V_1 , unsigned int V_114 )
{
struct V_115 * V_116 =
V_1 -> V_107 ? V_1 -> V_107 -> V_116 : NULL ;
unsigned long V_117 ;
int V_118 = 0 ;
unsigned char V_27 , V_32 , V_34 ;
unsigned char V_119 , V_120 ;
V_32 = F_2 ( V_1 , V_33 ) ;
if ( V_114 & V_121 )
goto V_122;
V_27 = F_2 ( V_1 , V_28 ) ;
V_34 = F_2 ( V_1 , V_35 ) ;
F_51 ( & V_1 -> V_24 , V_117 ) ;
if ( V_27 & V_123 )
V_1 -> V_124 ++ ;
if ( V_27 & V_125 )
V_1 -> V_126 ++ ;
if ( V_34 & V_127 )
V_1 -> V_128 ++ ;
if ( V_34 & V_129 )
V_1 -> V_130 ++ ;
V_119 = ( V_1 -> V_27 & ( V_29 | V_30 | V_31 |
V_131 | V_132 | V_133 ) ) ^
( V_27 & ( V_29 | V_30 | V_31 |
V_131 | V_132 | V_133 ) ) ;
V_120 = ( V_1 -> V_32 & ( V_134 | V_135 | V_136 |
V_137 | 0xf0 ) ) ^
( V_32 & ( V_134 | V_135 | V_136 |
V_137 | 0xf0 ) ) ;
V_1 -> V_27 = V_27 & ~ ( V_29 | V_30 | V_31 ) ;
V_1 -> V_32 = V_32 ;
V_1 -> V_34 = V_34 ;
F_52 ( & V_1 -> V_24 , V_117 ) ;
if ( V_27 & V_123 )
F_53 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_44 [ 0 ] -> V_110 ) ;
if ( V_27 & V_125 )
F_53 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_44 [ 1 ] -> V_110 ) ;
if ( V_34 & V_127 )
F_53 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_44 [ 2 ] -> V_110 ) ;
if ( V_34 & V_129 )
F_53 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_44 [ 3 ] -> V_110 ) ;
if ( V_120 & 0xf0 )
F_53 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_44 [ 4 ] -> V_110 ) ;
if ( ( V_120 & V_136 ) | ( V_119 & V_30 ) )
F_53 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_44 [ 6 ] -> V_110 ) ;
if ( V_119 & V_29 )
F_53 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_44 [ 8 ] -> V_110 ) ;
if ( V_119 & V_131 )
F_53 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_44 [ 9 ] -> V_110 ) ;
if ( V_120 & V_135 )
F_53 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_44 [ 10 ] -> V_110 ) ;
if ( V_120 & V_134 )
F_53 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_44 [ 11 ] -> V_110 ) ;
if ( V_1 -> V_139 && ( V_119 | V_120 ) != 0 )
V_1 -> V_139 ( V_1 , V_119 , V_120 ) ;
V_122:
V_118 = F_19 ( V_32 ) ;
if ( ! ( V_114 & V_140 ) && V_116 &&
( V_116 -> V_141 != V_118 ) ) {
F_54 ( V_1 -> V_107 , V_117 ) ;
if ( F_55 ( V_1 -> V_107 ) ) {
F_56 ( V_1 -> V_107 ,
V_142 ) ;
F_57 ( & V_116 -> V_143 ) ;
V_118 = 1 ;
}
F_58 ( V_1 -> V_107 , V_117 ) ;
}
return V_118 ;
}
static void V_25 ( struct V_144 * V_10 )
{
struct V_1 * V_8 = F_59 ( V_10 , struct V_1 , V_10 . V_10 ) ;
if ( ! V_8 -> V_9 )
F_50 ( V_8 , V_8 -> V_145 ) ;
F_18 ( & V_8 -> V_10 , V_45 / 10 ) ;
}

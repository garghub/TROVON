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
F_4 ( & V_8 -> V_9 ) ;
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
F_12 ( & V_8 -> V_9 , 0 ) ;
F_13 ( & V_8 -> V_26 ) ;
for ( V_2 = 0 ; V_2 < V_27 ; V_2 ++ )
V_8 -> V_6 [ V_2 ] = V_16 [ V_2 ] ;
F_14 ( V_8 ) ;
V_8 -> V_28 = F_2 ( V_8 , V_29 ) & ~ ( V_30 |
V_31 | V_32 ) ;
V_8 -> V_33 = F_2 ( V_8 , V_34 ) ;
V_8 -> V_35 = F_2 ( V_8 , V_36 ) ;
V_18 = F_15 ( V_15 , V_37 , V_8 , & V_20 ) ;
if ( V_18 < 0 )
goto V_38;
if ( V_17 )
* V_17 = V_8 ;
return 0 ;
V_38:
F_3 ( V_8 ) ;
return V_18 < 0 ? V_18 : - V_39 ;
}
void F_16 ( struct V_1 * V_8 , unsigned char V_2 ,
unsigned char V_40 , unsigned char V_3 )
{
if ( V_2 >= V_27 )
return;
F_1 ( V_8 , V_2 , ( V_8 -> V_6 [ V_2 ] & ~ V_40 ) | V_3 ) ;
}
static void F_14 ( struct V_1 * V_8 )
{
unsigned char V_41 = V_8 -> V_6 [ V_42 ] , V_2 ;
F_1 ( V_8 , V_42 , V_41 & ~ ( V_43 | V_44 ) ) ;
F_17 ( 200 ) ;
F_1 ( V_8 , V_42 , ( V_41 | V_43 ) & ~ V_44 ) ;
F_17 ( 200 ) ;
for ( V_2 = 1 ; V_2 < V_27 ; V_2 ++ )
F_1 ( V_8 , V_2 , V_8 -> V_6 [ V_2 ] ) ;
F_1 ( V_8 , V_42 , V_41 | V_43 | V_44 ) ;
}
void F_18 ( struct V_1 * V_8 )
{
if ( F_19 ( & V_8 -> V_9 ) == 1 )
F_5 ( & V_8 -> V_10 ) ;
F_20 ( & V_8 -> V_26 ) ;
F_14 ( V_8 ) ;
F_21 ( & V_8 -> V_26 ) ;
if ( F_22 ( & V_8 -> V_9 ) )
F_23 ( & V_8 -> V_10 , V_45 / 10 ) ;
}
static unsigned int F_24 ( unsigned char V_33 )
{
switch ( V_33 & ( V_46 | V_47 | V_48 | V_49 ) ) {
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
static int F_25 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_67 ;
V_66 -> V_68 = 1 ;
V_66 -> V_69 . integer . V_70 = 0 ;
V_66 -> V_69 . integer . V_71 = V_72 ;
return 0 ;
}
static int F_26 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_27 ( V_64 ) ;
long * V_75 ;
F_28 ( & V_8 -> V_24 ) ;
V_75 = ( long * ) ( ( ( char * ) V_8 ) + V_64 -> V_76 ) ;
V_74 -> V_69 . integer . V_69 [ 0 ] = * V_75 ;
* V_75 = 0 ;
F_29 ( & V_8 -> V_24 ) ;
return 0 ;
}
static int F_30 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_27 ( V_64 ) ;
unsigned char V_2 = V_64 -> V_76 & 0xff ;
unsigned char V_77 = ( V_64 -> V_76 >> 8 ) & 0xff ;
unsigned char V_78 = ( V_64 -> V_76 >> 31 ) & 1 ;
V_74 -> V_69 . integer . V_69 [ 0 ] =
( ( F_2 ( V_8 , V_2 ) & ( 1 << V_77 ) ) ? 1 : 0 ) ^ V_78 ;
return 0 ;
}
static int F_31 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_67 ;
V_66 -> V_68 = 1 ;
V_66 -> V_69 . integer . V_70 = 0 ;
V_66 -> V_69 . integer . V_71 = 5 ;
return 0 ;
}
static int F_32 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_27 ( V_64 ) ;
V_74 -> V_69 . integer . V_69 [ 0 ] =
( F_33 ( V_8 -> V_6 [ V_79 ] ) ) ;
return 0 ;
}
static int F_34 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_27 ( V_64 ) ;
int V_80 ;
T_3 V_81 ;
F_28 ( & V_8 -> V_24 ) ;
V_81 = V_8 -> V_6 [ V_79 ] ;
V_80 = V_74 -> V_69 . integer . V_69 [ 0 ] != F_33 ( V_81 ) ;
if ( V_80 )
F_1 ( V_8 , V_79 ,
( V_81 & ( ~ F_33 ( 0xff ) ) ) |
( F_33 ( V_74 -> V_69 . integer . V_69 [ 0 ] ) ) ) ;
F_29 ( & V_8 -> V_24 ) ;
return V_80 ;
}
static int F_35 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_67 ;
V_66 -> V_68 = 1 ;
V_66 -> V_69 . integer . V_70 = 0 ;
V_66 -> V_69 . integer . V_71 = 192000 ;
return 0 ;
}
static int F_36 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_27 ( V_64 ) ;
V_74 -> V_69 . integer . V_69 [ 0 ] = F_24 ( F_2 ( V_8 ,
V_34 ) ) ;
return 0 ;
}
static int F_37 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_82 ;
V_66 -> V_68 = 1 ;
return 0 ;
}
static int F_38 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_27 ( V_64 ) ;
unsigned V_83 ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ )
V_74 -> V_69 . V_85 . V_86 [ V_83 ] = F_2 ( V_8 ,
V_87 + V_83 ) ;
return 0 ;
}
static int F_39 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_82 ;
V_66 -> V_68 = 1 ;
return 0 ;
}
static int F_40 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
memset ( V_74 -> V_69 . V_85 . V_86 , 0xff , V_84 ) ;
return 0 ;
}
static int F_41 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_67 ;
V_66 -> V_69 . integer . V_70 = 0 ;
V_66 -> V_69 . integer . V_71 = 0xffff ;
V_66 -> V_68 = 4 ;
return 0 ;
}
static int F_42 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_27 ( V_64 ) ;
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
static int F_43 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
V_66 -> type = V_93 ;
V_66 -> V_68 = V_94 ;
return 0 ;
}
static int F_44 ( struct V_63 * V_64 ,
struct V_73 * V_74 )
{
struct V_1 * V_8 = F_27 ( V_64 ) ;
unsigned V_83 ;
for ( V_83 = 0 ; V_83 < V_94 ; V_83 ++ )
V_74 -> V_69 . V_95 . V_96 [ V_83 ] = F_2 ( V_8 ,
V_97 + V_83 ) ;
return 0 ;
}
static void F_45 ( struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_1 * V_1 = V_99 -> V_5 ;
int V_2 , V_3 ;
for ( V_2 = 0 ; V_2 < 0x1d ; V_2 ++ ) {
V_3 = F_2 ( V_1 , V_2 ) ;
F_46 ( V_101 , L_1 , V_2 , V_3 ) ;
}
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_98 * V_99 ;
if ( ! F_48 ( V_1 -> V_15 , L_2 , & V_99 ) )
F_49 ( V_99 , V_1 , F_45 ) ;
}
int F_50 ( struct V_1 * V_1 ,
struct V_102 * V_103 )
{
struct V_63 * V_104 ;
unsigned int V_105 ;
int V_18 ;
if ( F_51 ( ! V_103 ) )
return - V_106 ;
V_1 -> V_107 = V_103 ;
for ( V_105 = 0 ; V_105 < V_108 ; V_105 ++ ) {
V_104 = F_52 ( & V_109 [ V_105 ] , V_1 ) ;
if ( V_104 == NULL )
return - V_23 ;
V_104 -> V_110 . V_12 = V_103 -> V_111 -> V_12 ;
V_104 -> V_110 . V_112 = V_103 -> V_113 ;
V_18 = F_53 ( V_1 -> V_15 , V_104 ) ;
if ( V_18 < 0 )
return V_18 ;
V_1 -> V_114 [ V_105 ] = V_104 ;
}
F_47 ( V_1 ) ;
F_23 ( & V_1 -> V_10 , V_45 / 10 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_1 )
{
unsigned char V_33 ;
V_33 = F_2 ( V_1 , V_34 ) ;
return F_24 ( V_33 ) ;
}
int F_55 ( struct V_1 * V_1 , unsigned int V_115 )
{
struct V_116 * V_117 =
V_1 -> V_107 ? V_1 -> V_107 -> V_117 : NULL ;
unsigned long V_118 ;
int V_119 = 0 ;
unsigned char V_28 , V_33 , V_35 ;
unsigned char V_120 , V_121 ;
V_33 = F_2 ( V_1 , V_34 ) ;
if ( V_115 & V_122 )
goto V_123;
V_28 = F_2 ( V_1 , V_29 ) ;
V_35 = F_2 ( V_1 , V_36 ) ;
F_56 ( & V_1 -> V_24 , V_118 ) ;
if ( V_28 & V_124 )
V_1 -> V_125 ++ ;
if ( V_28 & V_126 )
V_1 -> V_127 ++ ;
if ( V_35 & V_128 )
V_1 -> V_129 ++ ;
if ( V_35 & V_130 )
V_1 -> V_131 ++ ;
V_120 = ( V_1 -> V_28 & ( V_30 | V_31 | V_32 |
V_132 | V_133 | V_134 ) ) ^
( V_28 & ( V_30 | V_31 | V_32 |
V_132 | V_133 | V_134 ) ) ;
V_121 = ( V_1 -> V_33 & ( V_135 | V_136 | V_137 |
V_138 | 0xf0 ) ) ^
( V_33 & ( V_135 | V_136 | V_137 |
V_138 | 0xf0 ) ) ;
V_1 -> V_28 = V_28 & ~ ( V_30 | V_31 | V_32 ) ;
V_1 -> V_33 = V_33 ;
V_1 -> V_35 = V_35 ;
F_57 ( & V_1 -> V_24 , V_118 ) ;
if ( V_28 & V_124 )
F_58 ( V_1 -> V_15 , V_139 ,
& V_1 -> V_114 [ 0 ] -> V_110 ) ;
if ( V_28 & V_126 )
F_58 ( V_1 -> V_15 , V_139 ,
& V_1 -> V_114 [ 1 ] -> V_110 ) ;
if ( V_35 & V_128 )
F_58 ( V_1 -> V_15 , V_139 ,
& V_1 -> V_114 [ 2 ] -> V_110 ) ;
if ( V_35 & V_130 )
F_58 ( V_1 -> V_15 , V_139 ,
& V_1 -> V_114 [ 3 ] -> V_110 ) ;
if ( V_121 & 0xf0 )
F_58 ( V_1 -> V_15 , V_139 ,
& V_1 -> V_114 [ 4 ] -> V_110 ) ;
if ( ( V_121 & V_137 ) | ( V_120 & V_31 ) )
F_58 ( V_1 -> V_15 , V_139 ,
& V_1 -> V_114 [ 6 ] -> V_110 ) ;
if ( V_120 & V_30 )
F_58 ( V_1 -> V_15 , V_139 ,
& V_1 -> V_114 [ 8 ] -> V_110 ) ;
if ( V_120 & V_132 )
F_58 ( V_1 -> V_15 , V_139 ,
& V_1 -> V_114 [ 9 ] -> V_110 ) ;
if ( V_121 & V_136 )
F_58 ( V_1 -> V_15 , V_139 ,
& V_1 -> V_114 [ 10 ] -> V_110 ) ;
if ( V_121 & V_135 )
F_58 ( V_1 -> V_15 , V_139 ,
& V_1 -> V_114 [ 11 ] -> V_110 ) ;
if ( V_1 -> V_140 && ( V_120 | V_121 ) != 0 )
V_1 -> V_140 ( V_1 , V_120 , V_121 ) ;
V_123:
V_119 = F_24 ( V_33 ) ;
if ( ! ( V_115 & V_141 ) && V_117 &&
( V_117 -> V_142 != V_119 ) ) {
F_59 ( V_1 -> V_107 , V_118 ) ;
if ( F_60 ( V_1 -> V_107 ) ) {
F_61 ( V_1 -> V_107 ,
V_143 ) ;
F_62 ( & V_117 -> V_144 ) ;
V_119 = 1 ;
}
F_63 ( V_1 -> V_107 , V_118 ) ;
}
return V_119 ;
}
static void V_25 ( struct V_145 * V_10 )
{
struct V_1 * V_8 = F_64 ( V_10 , struct V_1 , V_10 . V_10 ) ;
if ( F_19 ( & V_8 -> V_9 ) == 1 )
F_55 ( V_8 , V_8 -> V_146 ) ;
if ( F_22 ( & V_8 -> V_9 ) )
F_23 ( & V_8 -> V_10 , V_45 / 10 ) ;
}
void F_65 ( struct V_1 * V_8 )
{
F_4 ( & V_8 -> V_9 ) ;
F_5 ( & V_8 -> V_10 ) ;
}
void F_66 ( struct V_1 * V_8 )
{
F_67 ( & V_8 -> V_9 ) ;
F_18 ( V_8 ) ;
}

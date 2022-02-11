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
int V_18 ;
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
return V_18 ;
}
void F_16 ( struct V_1 * V_8 , unsigned char V_2 ,
unsigned char V_39 , unsigned char V_3 )
{
if ( V_2 >= V_27 )
return;
F_1 ( V_8 , V_2 , ( V_8 -> V_6 [ V_2 ] & ~ V_39 ) | V_3 ) ;
}
static void F_14 ( struct V_1 * V_8 )
{
unsigned char V_40 = V_8 -> V_6 [ V_41 ] , V_2 ;
F_1 ( V_8 , V_41 , V_40 & ~ ( V_42 | V_43 ) ) ;
F_17 ( 200 ) ;
F_1 ( V_8 , V_41 , ( V_40 | V_42 ) & ~ V_43 ) ;
F_17 ( 200 ) ;
for ( V_2 = 1 ; V_2 < V_27 ; V_2 ++ )
F_1 ( V_8 , V_2 , V_8 -> V_6 [ V_2 ] ) ;
F_1 ( V_8 , V_41 , V_40 | V_42 | V_43 ) ;
}
void F_18 ( struct V_1 * V_8 )
{
if ( F_19 ( & V_8 -> V_9 ) == 1 )
F_5 ( & V_8 -> V_10 ) ;
F_20 ( & V_8 -> V_26 ) ;
F_14 ( V_8 ) ;
F_21 ( & V_8 -> V_26 ) ;
if ( F_22 ( & V_8 -> V_9 ) )
F_23 ( & V_8 -> V_10 , V_44 / 10 ) ;
}
static unsigned int F_24 ( unsigned char V_33 )
{
switch ( V_33 & ( V_45 | V_46 | V_47 | V_48 ) ) {
case V_49 :
return 8000 ;
case V_50 :
return 11025 ;
case V_51 :
return 16000 ;
case V_52 :
return 22050 ;
case V_53 :
return 24000 ;
case V_54 :
return 32000 ;
case V_55 :
return 44100 ;
case V_56 :
return 48000 ;
case V_57 :
return 64000 ;
case V_58 :
return 88200 ;
case V_59 :
return 96000 ;
case V_60 :
return 176400 ;
case V_61 :
return 192000 ;
default:
return 0 ;
}
}
static int F_25 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
V_65 -> type = V_66 ;
V_65 -> V_67 = 1 ;
V_65 -> V_68 . integer . V_69 = 0 ;
V_65 -> V_68 . integer . V_70 = V_71 ;
return 0 ;
}
static int F_26 ( struct V_62 * V_63 ,
struct V_72 * V_73 )
{
struct V_1 * V_8 = F_27 ( V_63 ) ;
F_28 ( & V_8 -> V_24 ) ;
V_73 -> V_68 . integer . V_68 [ 0 ] =
V_8 -> V_74 [ V_63 -> V_75 ] ;
V_8 -> V_74 [ V_63 -> V_75 ] = 0 ;
F_29 ( & V_8 -> V_24 ) ;
return 0 ;
}
static int F_30 ( struct V_62 * V_63 ,
struct V_72 * V_73 )
{
struct V_1 * V_8 = F_27 ( V_63 ) ;
unsigned char V_2 = V_63 -> V_75 & 0xff ;
unsigned char V_76 = ( V_63 -> V_75 >> 8 ) & 0xff ;
unsigned char V_77 = ( V_63 -> V_75 >> 31 ) & 1 ;
V_73 -> V_68 . integer . V_68 [ 0 ] =
( ( F_2 ( V_8 , V_2 ) & ( 1 << V_76 ) ) ? 1 : 0 ) ^ V_77 ;
return 0 ;
}
static int F_31 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
V_65 -> type = V_66 ;
V_65 -> V_67 = 1 ;
V_65 -> V_68 . integer . V_69 = 0 ;
V_65 -> V_68 . integer . V_70 = 5 ;
return 0 ;
}
static int F_32 ( struct V_62 * V_63 ,
struct V_72 * V_73 )
{
struct V_1 * V_8 = F_27 ( V_63 ) ;
V_73 -> V_68 . integer . V_68 [ 0 ] =
( F_33 ( V_8 -> V_6 [ V_78 ] ) ) ;
return 0 ;
}
static int F_34 ( struct V_62 * V_63 ,
struct V_72 * V_73 )
{
struct V_1 * V_8 = F_27 ( V_63 ) ;
int V_79 ;
T_3 V_80 ;
F_28 ( & V_8 -> V_24 ) ;
V_80 = V_8 -> V_6 [ V_78 ] ;
V_79 = V_73 -> V_68 . integer . V_68 [ 0 ] != F_33 ( V_80 ) ;
if ( V_79 )
F_1 ( V_8 , V_78 ,
( V_80 & ( ~ F_33 ( 0xff ) ) ) |
( F_33 ( V_73 -> V_68 . integer . V_68 [ 0 ] ) ) ) ;
F_29 ( & V_8 -> V_24 ) ;
return V_79 ;
}
static int F_35 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
V_65 -> type = V_66 ;
V_65 -> V_67 = 1 ;
V_65 -> V_68 . integer . V_69 = 0 ;
V_65 -> V_68 . integer . V_70 = 192000 ;
return 0 ;
}
static int F_36 ( struct V_62 * V_63 ,
struct V_72 * V_73 )
{
struct V_1 * V_8 = F_27 ( V_63 ) ;
V_73 -> V_68 . integer . V_68 [ 0 ] = F_24 ( F_2 ( V_8 ,
V_34 ) ) ;
return 0 ;
}
static int F_37 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
V_65 -> type = V_81 ;
V_65 -> V_67 = 1 ;
return 0 ;
}
static int F_38 ( struct V_62 * V_63 ,
struct V_72 * V_73 )
{
struct V_1 * V_8 = F_27 ( V_63 ) ;
unsigned V_82 ;
for ( V_82 = 0 ; V_82 < V_83 ; V_82 ++ )
V_73 -> V_68 . V_84 . V_85 [ V_82 ] = F_2 ( V_8 ,
V_86 + V_82 ) ;
return 0 ;
}
static int F_39 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
V_65 -> type = V_81 ;
V_65 -> V_67 = 1 ;
return 0 ;
}
static int F_40 ( struct V_62 * V_63 ,
struct V_72 * V_73 )
{
memset ( V_73 -> V_68 . V_84 . V_85 , 0xff , V_83 ) ;
return 0 ;
}
static int F_41 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
V_65 -> type = V_66 ;
V_65 -> V_68 . integer . V_69 = 0 ;
V_65 -> V_68 . integer . V_70 = 0xffff ;
V_65 -> V_67 = 4 ;
return 0 ;
}
static int F_42 ( struct V_62 * V_63 ,
struct V_72 * V_73 )
{
struct V_1 * V_8 = F_27 ( V_63 ) ;
unsigned short V_87 ;
V_73 -> V_68 . integer . V_68 [ 0 ] = 0xf8f2 ;
V_73 -> V_68 . integer . V_68 [ 1 ] = 0x4e1f ;
V_87 = F_2 ( V_8 , V_88 ) |
( F_2 ( V_8 , V_89 ) << 8 ) ;
V_73 -> V_68 . integer . V_68 [ 2 ] = V_87 ;
V_87 = F_2 ( V_8 , V_90 ) |
( F_2 ( V_8 , V_91 ) << 8 ) ;
V_73 -> V_68 . integer . V_68 [ 3 ] = V_87 ;
return 0 ;
}
static int F_43 ( struct V_62 * V_63 ,
struct V_64 * V_65 )
{
V_65 -> type = V_92 ;
V_65 -> V_67 = V_93 ;
return 0 ;
}
static int F_44 ( struct V_62 * V_63 ,
struct V_72 * V_73 )
{
struct V_1 * V_8 = F_27 ( V_63 ) ;
unsigned V_82 ;
for ( V_82 = 0 ; V_82 < V_93 ; V_82 ++ )
V_73 -> V_68 . V_94 . V_95 [ V_82 ] = F_2 ( V_8 ,
V_96 + V_82 ) ;
return 0 ;
}
static void F_45 ( struct V_97 * V_98 ,
struct V_99 * V_100 )
{
struct V_1 * V_1 = V_98 -> V_5 ;
int V_2 , V_3 ;
for ( V_2 = 0 ; V_2 < 0x1d ; V_2 ++ ) {
V_3 = F_2 ( V_1 , V_2 ) ;
F_46 ( V_100 , L_1 , V_2 , V_3 ) ;
}
}
static void F_47 ( struct V_1 * V_1 )
{
struct V_97 * V_98 ;
if ( ! F_48 ( V_1 -> V_15 , L_2 , & V_98 ) )
F_49 ( V_98 , V_1 , F_45 ) ;
}
int F_50 ( struct V_1 * V_1 ,
struct V_101 * V_102 )
{
struct V_62 * V_103 ;
unsigned int V_104 ;
int V_18 ;
if ( F_51 ( ! V_102 ) )
return - V_105 ;
V_1 -> V_106 = V_102 ;
for ( V_104 = 0 ; V_104 < V_107 ; V_104 ++ ) {
V_103 = F_52 ( & V_108 [ V_104 ] , V_1 ) ;
if ( V_103 == NULL )
return - V_23 ;
V_103 -> V_109 . V_12 = V_102 -> V_110 -> V_12 ;
V_103 -> V_109 . V_111 = V_102 -> V_112 ;
V_18 = F_53 ( V_1 -> V_15 , V_103 ) ;
if ( V_18 < 0 )
return V_18 ;
V_1 -> V_113 [ V_104 ] = V_103 ;
}
F_47 ( V_1 ) ;
F_23 ( & V_1 -> V_10 , V_44 / 10 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_1 )
{
unsigned char V_33 ;
V_33 = F_2 ( V_1 , V_34 ) ;
return F_24 ( V_33 ) ;
}
int F_55 ( struct V_1 * V_1 , unsigned int V_114 )
{
struct V_115 * V_116 =
V_1 -> V_106 ? V_1 -> V_106 -> V_116 : NULL ;
unsigned long V_117 ;
int V_118 = 0 ;
unsigned char V_28 , V_33 , V_35 ;
unsigned char V_119 , V_120 ;
V_33 = F_2 ( V_1 , V_34 ) ;
if ( V_114 & V_121 )
goto V_122;
V_28 = F_2 ( V_1 , V_29 ) ;
V_35 = F_2 ( V_1 , V_36 ) ;
F_56 ( & V_1 -> V_24 , V_117 ) ;
if ( V_28 & V_123 )
V_1 -> V_74 [ V_124 ] ++ ;
if ( V_28 & V_125 )
V_1 -> V_74 [ V_126 ] ++ ;
if ( V_35 & V_127 )
V_1 -> V_74 [ V_128 ] ++ ;
if ( V_35 & V_129 )
V_1 -> V_74 [ V_130 ] ++ ;
V_119 = ( V_1 -> V_28 & ( V_30 | V_31 | V_32 |
V_131 | V_132 | V_133 ) ) ^
( V_28 & ( V_30 | V_31 | V_32 |
V_131 | V_132 | V_133 ) ) ;
V_120 = ( V_1 -> V_33 & ( V_134 | V_135 | V_136 |
V_137 | 0xf0 ) ) ^
( V_33 & ( V_134 | V_135 | V_136 |
V_137 | 0xf0 ) ) ;
V_1 -> V_28 = V_28 & ~ ( V_30 | V_31 | V_32 ) ;
V_1 -> V_33 = V_33 ;
V_1 -> V_35 = V_35 ;
F_57 ( & V_1 -> V_24 , V_117 ) ;
if ( V_28 & V_123 )
F_58 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_113 [ 0 ] -> V_109 ) ;
if ( V_28 & V_125 )
F_58 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_113 [ 1 ] -> V_109 ) ;
if ( V_35 & V_127 )
F_58 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_113 [ 2 ] -> V_109 ) ;
if ( V_35 & V_129 )
F_58 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_113 [ 3 ] -> V_109 ) ;
if ( V_120 & 0xf0 )
F_58 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_113 [ 4 ] -> V_109 ) ;
if ( ( V_120 & V_136 ) | ( V_119 & V_31 ) )
F_58 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_113 [ 6 ] -> V_109 ) ;
if ( V_119 & V_30 )
F_58 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_113 [ 8 ] -> V_109 ) ;
if ( V_119 & V_131 )
F_58 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_113 [ 9 ] -> V_109 ) ;
if ( V_120 & V_135 )
F_58 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_113 [ 10 ] -> V_109 ) ;
if ( V_120 & V_134 )
F_58 ( V_1 -> V_15 , V_138 ,
& V_1 -> V_113 [ 11 ] -> V_109 ) ;
if ( V_1 -> V_139 && ( V_119 | V_120 ) != 0 )
V_1 -> V_139 ( V_1 , V_119 , V_120 ) ;
V_122:
V_118 = F_24 ( V_33 ) ;
if ( ! ( V_114 & V_140 ) && V_116 &&
( V_116 -> V_141 != V_118 ) ) {
F_59 ( V_1 -> V_106 , V_117 ) ;
if ( F_60 ( V_1 -> V_106 ) ) {
F_61 ( V_1 -> V_106 ,
V_142 ) ;
F_62 ( & V_116 -> V_143 ) ;
V_118 = 1 ;
}
F_63 ( V_1 -> V_106 , V_117 ) ;
}
return V_118 ;
}
static void V_25 ( struct V_144 * V_10 )
{
struct V_1 * V_8 = F_64 ( V_10 , struct V_1 , V_10 . V_10 ) ;
if ( F_19 ( & V_8 -> V_9 ) == 1 )
F_55 ( V_8 , V_8 -> V_145 ) ;
if ( F_22 ( & V_8 -> V_9 ) )
F_23 ( & V_8 -> V_10 , V_44 / 10 ) ;
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

static void F_1 ( struct V_1 * V_1 , unsigned char V_2 , unsigned char V_3 )
{
V_1 -> V_4 ( V_1 -> V_5 , V_2 , V_3 ) ;
if ( V_2 <= V_6 )
V_1 -> V_7 [ V_2 ] = V_3 ;
else if ( V_2 >= V_8 && V_2 <= V_9 )
V_1 -> V_10 [ V_2 - V_8 ] = V_3 ;
}
static inline unsigned char F_2 ( struct V_1 * V_1 , unsigned char V_2 )
{
return V_1 -> V_11 ( V_1 -> V_5 , V_2 ) ;
}
static void F_3 ( struct V_1 * V_12 )
{
F_4 ( & V_12 -> V_13 ) ;
F_5 ( & V_12 -> V_14 ) ;
F_6 ( V_12 ) ;
}
static int F_7 ( struct V_15 * V_16 )
{
struct V_1 * V_12 = V_16 -> V_17 ;
F_3 ( V_12 ) ;
return 0 ;
}
int F_8 ( struct V_18 * V_19 ,
T_1 * V_11 , T_2 * V_4 ,
const unsigned char V_20 [ 6 ] , const unsigned char V_10 [ 5 ] ,
void * V_5 , struct V_1 * * V_21 )
{
struct V_1 * V_12 ;
int V_22 = 0 ;
unsigned char V_2 ;
static struct V_23 V_24 = {
. V_25 = F_7 ,
} ;
V_12 = F_9 ( sizeof( * V_12 ) , V_26 ) ;
if ( V_12 == NULL )
return - V_27 ;
F_10 ( & V_12 -> V_28 ) ;
V_12 -> V_19 = V_19 ;
V_12 -> V_11 = V_11 ;
V_12 -> V_4 = V_4 ;
V_12 -> V_5 = V_5 ;
F_11 ( & V_12 -> V_14 , V_29 ) ;
F_12 ( & V_12 -> V_13 , 0 ) ;
F_13 ( & V_12 -> V_30 ) ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ )
V_12 -> V_7 [ V_2 ] = V_20 [ V_2 ] ;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ )
V_12 -> V_10 [ V_2 ] = V_10 [ V_2 ] ;
F_14 ( V_12 ) ;
V_12 -> V_31 = F_2 ( V_12 , V_32 ) & ~ ( V_33 | V_34 ) ;
V_12 -> V_35 = F_2 ( V_12 , V_36 ) ;
if ( ( V_22 = F_15 ( V_19 , V_37 , V_12 , & V_24 ) ) < 0 )
goto V_38;
if ( V_21 )
* V_21 = V_12 ;
return 0 ;
V_38:
F_3 ( V_12 ) ;
return V_22 ;
}
void F_16 ( struct V_1 * V_12 , unsigned char V_2 , unsigned char V_39 , unsigned char V_3 )
{
if ( V_2 <= V_6 )
F_1 ( V_12 , V_2 , ( V_12 -> V_7 [ V_2 ] & ~ V_39 ) | V_3 ) ;
else if ( V_2 >= V_8 && V_2 <= V_9 )
F_1 ( V_12 , V_2 ,
( V_12 -> V_10 [ V_2 - V_8 ] & ~ V_39 ) | V_3 ) ;
}
static void F_14 ( struct V_1 * V_12 )
{
unsigned char V_40 = V_12 -> V_7 [ V_41 ] , V_2 ;
F_1 ( V_12 , V_41 , V_40 & ~ ( V_42 | V_43 ) ) ;
F_17 ( 200 ) ;
F_1 ( V_12 , V_41 , ( V_40 | V_42 ) & ~ V_43 ) ;
F_17 ( 200 ) ;
for ( V_2 = 1 ; V_2 < 6 ; V_2 ++ )
F_1 ( V_12 , V_2 , V_12 -> V_7 [ V_2 ] ) ;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ )
F_1 ( V_12 , V_2 + V_8 , V_12 -> V_10 [ V_2 ] ) ;
F_1 ( V_12 , V_41 , V_40 | V_42 | V_43 ) ;
}
void F_18 ( struct V_1 * V_12 )
{
if ( F_19 ( & V_12 -> V_13 ) == 1 )
F_5 ( & V_12 -> V_14 ) ;
F_20 ( & V_12 -> V_30 ) ;
F_14 ( V_12 ) ;
F_21 ( & V_12 -> V_30 ) ;
if ( F_22 ( & V_12 -> V_13 ) )
F_23 ( & V_12 -> V_14 , V_44 / 10 ) ;
}
static unsigned int F_24 ( unsigned char V_35 )
{
switch ( V_35 & ( V_45 | V_46 | V_47 | V_48 ) ) {
case V_49 : return 32000 ;
case V_50 : return 44100 ;
case V_51 : return 48000 ;
case V_52 : return 88200 ;
case V_53 : return 96000 ;
case V_54 : return 176400 ;
case V_55 : return 192000 ;
default: return 0 ;
}
}
static int F_25 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
V_59 -> type = V_60 ;
V_59 -> V_61 = 1 ;
V_59 -> V_62 . integer . V_63 = 0 ;
V_59 -> V_62 . integer . V_64 = V_65 ;
return 0 ;
}
static int F_26 ( struct V_56 * V_57 ,
struct V_66 * V_67 )
{
struct V_1 * V_12 = F_27 ( V_57 ) ;
F_28 ( & V_12 -> V_28 ) ;
V_67 -> V_62 . integer . V_62 [ 0 ] =
V_12 -> V_68 [ V_57 -> V_69 ] ;
V_12 -> V_68 [ V_57 -> V_69 ] = 0 ;
F_29 ( & V_12 -> V_28 ) ;
return 0 ;
}
static int F_30 ( struct V_56 * V_57 ,
struct V_66 * V_67 )
{
struct V_1 * V_12 = F_27 ( V_57 ) ;
unsigned char V_2 = V_57 -> V_69 & 0xff ;
unsigned char V_70 = ( V_57 -> V_69 >> 8 ) & 0xff ;
unsigned char V_71 = ( V_57 -> V_69 >> 31 ) & 1 ;
V_67 -> V_62 . integer . V_62 [ 0 ] = ( ( F_2 ( V_12 , V_2 ) & ( 1 << V_70 ) ) ? 1 : 0 ) ^ V_71 ;
return 0 ;
}
static int F_31 ( struct V_56 * V_57 ,
struct V_58 * V_59 )
{
V_59 -> type = V_60 ;
V_59 -> V_61 = 1 ;
V_59 -> V_62 . integer . V_63 = 0 ;
V_59 -> V_62 . integer . V_64 = 192000 ;
return 0 ;
}
static int F_32 ( struct V_56 * V_57 ,
struct V_66 * V_67 )
{
struct V_1 * V_12 = F_27 ( V_57 ) ;
V_67 -> V_62 . integer . V_62 [ 0 ] = F_24 ( F_2 ( V_12 , V_36 ) ) ;
return 0 ;
}
static int F_33 ( struct V_56 * V_57 , struct V_58 * V_59 )
{
V_59 -> type = V_72 ;
V_59 -> V_61 = 1 ;
return 0 ;
}
static int F_34 ( struct V_56 * V_57 ,
struct V_66 * V_67 )
{
struct V_1 * V_12 = F_27 ( V_57 ) ;
unsigned V_73 ;
for ( V_73 = 0 ; V_73 < V_74 ; V_73 ++ )
V_67 -> V_62 . V_75 . V_76 [ V_73 ] = F_2 ( V_12 , V_77 + V_73 ) ;
return 0 ;
}
static int F_35 ( struct V_56 * V_57 ,
struct V_66 * V_67 )
{
struct V_1 * V_12 = F_27 ( V_57 ) ;
unsigned V_73 ;
for ( V_73 = 0 ; V_73 < V_78 ; V_73 ++ )
V_67 -> V_62 . V_75 . V_76 [ V_73 ] = V_12 -> V_10 [ V_73 ] ;
return 0 ;
}
static int F_36 ( struct V_56 * V_57 ,
struct V_66 * V_67 )
{
struct V_1 * V_12 = F_27 ( V_57 ) ;
unsigned V_73 ;
for ( V_73 = 0 ; V_73 < V_78 ; V_73 ++ )
F_1 ( V_12 , V_8 + V_73 , V_67 -> V_62 . V_75 . V_76 [ V_73 ] ) ;
return 0 ;
}
static int F_37 ( struct V_56 * V_57 , struct V_58 * V_59 )
{
V_59 -> type = V_72 ;
V_59 -> V_61 = 1 ;
return 0 ;
}
static int F_38 ( struct V_56 * V_57 ,
struct V_66 * V_67 )
{
memset ( V_67 -> V_62 . V_75 . V_76 , 0xff , V_74 ) ;
return 0 ;
}
static int F_39 ( struct V_56 * V_57 , struct V_58 * V_59 )
{
V_59 -> type = V_60 ;
V_59 -> V_62 . integer . V_63 = 0 ;
V_59 -> V_62 . integer . V_64 = 0xffff ;
V_59 -> V_61 = 4 ;
return 0 ;
}
static int F_40 ( struct V_56 * V_57 ,
struct V_66 * V_67 )
{
struct V_1 * V_12 = F_27 ( V_57 ) ;
unsigned short V_79 ;
V_67 -> V_62 . integer . V_62 [ 0 ] = 0xf8f2 ;
V_67 -> V_62 . integer . V_62 [ 1 ] = 0x4e1f ;
V_79 = F_2 ( V_12 , V_80 ) | ( F_2 ( V_12 , V_81 ) << 8 ) ;
V_67 -> V_62 . integer . V_62 [ 2 ] = V_79 ;
V_79 = F_2 ( V_12 , V_82 ) | ( F_2 ( V_12 , V_83 ) << 8 ) ;
V_67 -> V_62 . integer . V_62 [ 3 ] = V_79 ;
return 0 ;
}
static int F_41 ( struct V_56 * V_57 , struct V_58 * V_59 )
{
V_59 -> type = V_84 ;
V_59 -> V_61 = V_85 ;
return 0 ;
}
static int F_42 ( struct V_56 * V_57 ,
struct V_66 * V_67 )
{
struct V_1 * V_12 = F_27 ( V_57 ) ;
unsigned V_73 ;
for ( V_73 = 0 ; V_73 < V_85 ; V_73 ++ )
V_67 -> V_62 . V_86 . V_87 [ V_73 ] = F_2 ( V_12 , V_88 + V_73 ) ;
return 0 ;
}
static void F_43 ( struct V_89 * V_90 ,
struct V_91 * V_92 )
{
struct V_1 * V_1 = V_90 -> V_5 ;
int V_2 , V_3 ;
for ( V_2 = 0 ; V_2 < 0x20 ; V_2 ++ ) {
V_3 = F_2 ( V_1 , V_2 ) ;
F_44 ( V_92 , L_1 , V_2 , V_3 ) ;
}
}
static void F_45 ( struct V_1 * V_1 )
{
struct V_89 * V_90 ;
if ( ! F_46 ( V_1 -> V_19 , L_2 , & V_90 ) )
F_47 ( V_90 , V_1 , F_43 ) ;
}
int F_48 ( struct V_1 * V_1 ,
struct V_93 * V_94 ,
struct V_93 * V_95 )
{
struct V_56 * V_96 ;
unsigned int V_97 ;
int V_22 ;
if ( F_49 ( ! V_95 ) )
return - V_98 ;
V_1 -> V_99 = V_94 ;
V_1 -> V_100 = V_95 ;
for ( V_97 = 0 ; V_97 < V_101 ; V_97 ++ ) {
V_96 = F_50 ( & V_102 [ V_97 ] , V_1 ) ;
if ( V_96 == NULL )
return - V_27 ;
if ( strstr ( V_96 -> V_103 . V_104 , L_3 ) ) {
if ( V_94 == NULL ) {
F_51 ( V_96 ) ;
V_1 -> V_105 [ V_97 ] = NULL ;
continue;
}
V_96 -> V_103 . V_16 = V_94 -> V_106 -> V_16 ;
V_96 -> V_103 . V_107 = V_94 -> V_108 ;
} else {
V_96 -> V_103 . V_16 = V_95 -> V_106 -> V_16 ;
V_96 -> V_103 . V_107 = V_95 -> V_108 ;
}
V_22 = F_52 ( V_1 -> V_19 , V_96 ) ;
if ( V_22 < 0 )
return V_22 ;
V_1 -> V_105 [ V_97 ] = V_96 ;
}
F_45 ( V_1 ) ;
F_23 ( & V_1 -> V_14 , V_44 / 10 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_1 ,
unsigned char V_31 , unsigned char V_35 ,
unsigned char V_109 , unsigned char V_110 )
{
if ( ! V_1 -> V_105 [ 0 ] )
return;
if ( V_31 & V_111 )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 0 ] -> V_103 ) ;
if ( V_31 & V_113 )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 1 ] -> V_103 ) ;
if ( V_35 & V_114 )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 2 ] -> V_103 ) ;
if ( V_35 & V_115 )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 3 ] -> V_103 ) ;
if ( V_110 & 0xf0 )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 4 ] -> V_103 ) ;
if ( ( V_109 & V_116 ) | ( V_109 & V_34 ) )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 9 ] -> V_103 ) ;
if ( V_109 & V_33 )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 10 ] -> V_103 ) ;
if ( V_109 & V_117 )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 11 ] -> V_103 ) ;
if ( V_109 & V_118 )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 12 ] -> V_103 ) ;
if ( V_109 & V_119 )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 13 ] -> V_103 ) ;
if ( V_109 & V_120 )
F_54 ( V_1 -> V_19 , V_112 ,
& V_1 -> V_105 [ 14 ] -> V_103 ) ;
}
int F_55 ( struct V_1 * V_1 )
{
unsigned char V_35 ;
V_35 = F_2 ( V_1 , V_36 ) ;
return F_24 ( V_35 ) ;
}
int F_56 ( struct V_1 * V_1 , unsigned int V_121 )
{
struct V_122 * V_123 = V_1 -> V_100 ? V_1 -> V_100 -> V_123 : NULL ;
unsigned long V_124 ;
int V_125 = 0 ;
unsigned char V_31 , V_35 ;
unsigned char V_109 , V_110 ;
V_35 = F_2 ( V_1 , V_36 ) ;
if ( V_121 & V_126 )
goto V_127;
V_31 = F_2 ( V_1 , V_32 ) ;
F_57 ( & V_1 -> V_28 , V_124 ) ;
if ( V_31 & V_111 )
V_1 -> V_68 [ V_128 ] ++ ;
if ( V_35 & V_113 )
V_1 -> V_68 [ V_129 ] ++ ;
if ( V_35 & V_114 )
V_1 -> V_68 [ V_130 ] ++ ;
if ( V_35 & V_115 )
V_1 -> V_68 [ V_131 ] ++ ;
V_109 = ( V_1 -> V_31 & ( V_33 | V_34 | V_116 | V_117 | V_118 | V_120 ) ) ^
( V_31 & ( V_33 | V_34 | V_116 | V_117 | V_118 | V_120 ) ) ;
V_110 = ( V_1 -> V_35 & 0xf0 ) ^ ( V_35 & 0xf0 ) ;
V_1 -> V_31 = V_31 & ~ ( V_33 | V_34 ) ;
V_1 -> V_35 = V_35 ;
F_58 ( & V_1 -> V_28 , V_124 ) ;
F_53 ( V_1 , V_31 , V_35 , V_109 , V_110 ) ;
if ( V_1 -> V_132 && ( V_109 | V_110 ) != 0 )
V_1 -> V_132 ( V_1 , V_109 , V_110 ) ;
V_127:
V_125 = F_24 ( V_35 ) ;
if ( ! ( V_121 & V_133 ) && V_123 && V_123 -> V_134 != V_125 ) {
F_59 ( V_1 -> V_100 , V_124 ) ;
if ( F_60 ( V_1 -> V_100 ) ) {
F_61 ( V_1 -> V_100 , V_135 ) ;
V_125 = 1 ;
}
F_62 ( V_1 -> V_100 , V_124 ) ;
}
return V_125 ;
}
static void V_29 ( struct V_136 * V_14 )
{
struct V_1 * V_12 = F_63 ( V_14 , struct V_1 , V_14 . V_14 ) ;
if ( F_19 ( & V_12 -> V_13 ) == 1 )
F_56 ( V_12 , V_12 -> V_137 ) ;
if ( F_22 ( & V_12 -> V_13 ) )
F_23 ( & V_12 -> V_14 , V_44 / 10 ) ;
}
void F_64 ( struct V_1 * V_12 )
{
F_4 ( & V_12 -> V_13 ) ;
F_5 ( & V_12 -> V_14 ) ;
}
void F_65 ( struct V_1 * V_12 )
{
F_66 ( & V_12 -> V_13 ) ;
F_18 ( V_12 ) ;
}

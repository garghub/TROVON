static void F_1 ( struct V_1 * V_1 , unsigned char V_2 , unsigned char V_3 )
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
F_5 ( V_8 ) ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_8 = V_11 -> V_12 ;
F_3 ( V_8 ) ;
return 0 ;
}
int F_7 ( struct V_13 * V_14 , T_1 * V_7 , T_2 * V_4 ,
const unsigned char V_15 [ 5 ] , void * V_5 , struct V_1 * * V_16 )
{
struct V_1 * V_8 ;
int V_17 = 0 ;
unsigned char V_2 ;
static struct V_18 V_19 = {
. V_20 = F_6 ,
} ;
V_8 = F_8 ( sizeof( * V_8 ) , V_21 ) ;
if ( V_8 == NULL )
return - V_22 ;
F_9 ( & V_8 -> V_23 ) ;
V_8 -> V_14 = V_14 ;
V_8 -> V_7 = V_7 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_5 = V_5 ;
F_10 ( & V_8 -> V_9 , V_24 , ( unsigned long ) V_8 ) ;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ )
V_8 -> V_6 [ V_2 ] = V_15 [ V_2 ] ;
F_11 ( V_8 ) ;
V_8 -> V_25 = F_2 ( V_8 , V_26 ) & ~ ( V_27 | V_28 | V_29 ) ;
V_8 -> V_30 = F_2 ( V_8 , V_31 ) ;
V_8 -> V_32 = F_2 ( V_8 , V_33 ) ;
if ( ( V_17 = F_12 ( V_14 , V_34 , V_8 , & V_19 ) ) < 0 )
goto V_35;
if ( V_16 )
* V_16 = V_8 ;
return 0 ;
V_35:
F_3 ( V_8 ) ;
return V_17 ;
}
void F_13 ( struct V_1 * V_8 , unsigned char V_2 , unsigned char V_36 , unsigned char V_3 )
{
if ( V_2 >= 5 )
return;
F_1 ( V_8 , V_2 , ( V_8 -> V_6 [ V_2 ] & ~ V_36 ) | V_3 ) ;
}
void F_11 ( struct V_1 * V_8 )
{
unsigned char V_37 = V_8 -> V_6 [ V_38 ] , V_2 ;
F_14 ( & V_8 -> V_9 ) ;
V_8 -> V_39 = 1 ;
F_1 ( V_8 , V_38 , 0 ) ;
F_15 ( 200 ) ;
F_1 ( V_8 , V_38 , ( V_37 | V_40 ) & ~ V_41 ) ;
F_15 ( 200 ) ;
for ( V_2 = 1 ; V_2 < 5 ; V_2 ++ )
F_1 ( V_8 , V_2 , V_8 -> V_6 [ V_2 ] ) ;
F_1 ( V_8 , V_38 , V_37 | V_40 | V_41 ) ;
V_8 -> V_39 = 0 ;
F_16 ( & V_8 -> V_9 , 1 + V_42 ) ;
}
static unsigned int F_17 ( unsigned char V_30 )
{
switch ( V_30 & ( V_43 | V_44 | V_45 | V_46 ) ) {
case V_47 : return 32000 ;
case V_48 : return 44100 ;
case V_49 : return 48000 ;
case V_50 : return 88200 ;
case V_51 : return 96000 ;
case V_52 : return 176400 ;
case V_53 : return 192000 ;
default: return 0 ;
}
}
static int F_18 ( struct V_54 * V_55 ,
struct V_56 * V_57 )
{
V_57 -> type = V_58 ;
V_57 -> V_59 = 1 ;
V_57 -> V_60 . integer . V_61 = 0 ;
V_57 -> V_60 . integer . V_62 = V_63 ;
return 0 ;
}
static int F_19 ( struct V_54 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_8 = F_20 ( V_55 ) ;
F_21 ( & V_8 -> V_23 ) ;
V_65 -> V_60 . integer . V_60 [ 0 ] =
V_8 -> V_66 [ V_55 -> V_67 ] ;
V_8 -> V_66 [ V_55 -> V_67 ] = 0 ;
F_22 ( & V_8 -> V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_54 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_8 = F_20 ( V_55 ) ;
unsigned char V_2 = V_55 -> V_67 & 0xff ;
unsigned char V_68 = ( V_55 -> V_67 >> 8 ) & 0xff ;
unsigned char V_69 = ( V_55 -> V_67 >> 31 ) & 1 ;
V_65 -> V_60 . integer . V_60 [ 0 ] = ( ( F_2 ( V_8 , V_2 ) & ( 1 << V_68 ) ) ? 1 : 0 ) ^ V_69 ;
return 0 ;
}
static int F_24 ( struct V_54 * V_55 ,
struct V_56 * V_57 )
{
V_57 -> type = V_58 ;
V_57 -> V_59 = 1 ;
V_57 -> V_60 . integer . V_61 = 0 ;
V_57 -> V_60 . integer . V_62 = 1 ;
return 0 ;
}
static int F_25 ( struct V_54 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_8 = F_20 ( V_55 ) ;
V_65 -> V_60 . integer . V_60 [ 0 ] = ( V_8 -> V_6 [ V_70 ] & V_71 ) ? 1 : 0 ;
return 0 ;
}
static int F_26 ( struct V_54 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_8 = F_20 ( V_55 ) ;
int V_72 ;
T_3 V_73 ;
F_21 ( & V_8 -> V_23 ) ;
V_73 = V_8 -> V_6 [ V_70 ] ;
V_72 = ! ! V_65 -> V_60 . integer . V_60 [ 0 ] != ( ( V_73 & V_71 ) ? 1 : 0 ) ;
if ( V_72 )
F_1 ( V_8 , V_70 , ( V_73 & ~ V_71 ) | ( V_65 -> V_60 . integer . V_60 [ 0 ] ? V_71 : 0 ) ) ;
F_22 ( & V_8 -> V_23 ) ;
return V_72 ;
}
static int F_27 ( struct V_54 * V_55 ,
struct V_56 * V_57 )
{
V_57 -> type = V_58 ;
V_57 -> V_59 = 1 ;
V_57 -> V_60 . integer . V_61 = 0 ;
V_57 -> V_60 . integer . V_62 = 192000 ;
return 0 ;
}
static int F_28 ( struct V_54 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_8 = F_20 ( V_55 ) ;
V_65 -> V_60 . integer . V_60 [ 0 ] = F_17 ( F_2 ( V_8 , V_31 ) ) ;
return 0 ;
}
static int F_29 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
V_57 -> type = V_74 ;
V_57 -> V_59 = 1 ;
return 0 ;
}
static int F_30 ( struct V_54 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_8 = F_20 ( V_55 ) ;
unsigned V_75 ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ )
V_65 -> V_60 . V_77 . V_78 [ V_75 ] = F_2 ( V_8 , V_79 + V_75 ) ;
return 0 ;
}
static int F_31 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
V_57 -> type = V_74 ;
V_57 -> V_59 = 1 ;
return 0 ;
}
static int F_32 ( struct V_54 * V_55 ,
struct V_64 * V_65 )
{
memset ( V_65 -> V_60 . V_77 . V_78 , 0xff , V_76 ) ;
return 0 ;
}
static int F_33 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
V_57 -> type = V_58 ;
V_57 -> V_60 . integer . V_61 = 0 ;
V_57 -> V_60 . integer . V_62 = 0xffff ;
V_57 -> V_59 = 4 ;
return 0 ;
}
static int F_34 ( struct V_54 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_8 = F_20 ( V_55 ) ;
unsigned short V_80 ;
V_65 -> V_60 . integer . V_60 [ 0 ] = 0xf8f2 ;
V_65 -> V_60 . integer . V_60 [ 1 ] = 0x4e1f ;
V_80 = F_2 ( V_8 , V_81 ) | ( F_2 ( V_8 , V_82 ) << 8 ) ;
V_65 -> V_60 . integer . V_60 [ 2 ] = V_80 ;
V_80 = F_2 ( V_8 , V_83 ) | ( F_2 ( V_8 , V_84 ) << 8 ) ;
V_65 -> V_60 . integer . V_60 [ 3 ] = V_80 ;
return 0 ;
}
static int F_35 ( struct V_54 * V_55 , struct V_56 * V_57 )
{
V_57 -> type = V_85 ;
V_57 -> V_59 = V_86 ;
return 0 ;
}
static int F_36 ( struct V_54 * V_55 ,
struct V_64 * V_65 )
{
struct V_1 * V_8 = F_20 ( V_55 ) ;
unsigned V_75 ;
for ( V_75 = 0 ; V_75 < V_86 ; V_75 ++ )
V_65 -> V_60 . V_87 . V_88 [ V_75 ] = F_2 ( V_8 , V_89 + V_75 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_1 , struct V_90 * V_91 )
{
struct V_54 * V_92 ;
unsigned int V_93 ;
int V_17 ;
if ( F_38 ( ! V_91 ) )
return - V_94 ;
V_1 -> V_95 = V_91 ;
for ( V_93 = 0 ; V_93 < V_96 ; V_93 ++ ) {
V_92 = F_39 ( & V_97 [ V_93 ] , V_1 ) ;
if ( V_92 == NULL )
return - V_22 ;
V_92 -> V_98 . V_11 = V_91 -> V_99 -> V_11 ;
V_92 -> V_98 . V_100 = V_91 -> V_101 ;
V_17 = F_40 ( V_1 -> V_14 , V_92 ) ;
if ( V_17 < 0 )
return V_17 ;
V_1 -> V_102 [ V_93 ] = V_92 ;
}
return 0 ;
}
int F_41 ( struct V_1 * V_1 )
{
unsigned char V_30 ;
V_30 = F_2 ( V_1 , V_31 ) ;
return F_17 ( V_30 ) ;
}
int F_42 ( struct V_1 * V_1 , unsigned int V_103 )
{
struct V_104 * V_105 = V_1 -> V_95 ? V_1 -> V_95 -> V_105 : NULL ;
unsigned long V_106 ;
int V_107 = 0 ;
unsigned char V_25 , V_30 , V_32 ;
unsigned char V_108 , V_109 ;
V_30 = F_2 ( V_1 , V_31 ) ;
if ( V_103 & V_110 )
goto V_111;
V_25 = F_2 ( V_1 , V_26 ) ;
V_32 = F_2 ( V_1 , V_33 ) ;
F_43 ( & V_1 -> V_23 , V_106 ) ;
if ( V_25 & V_112 )
V_1 -> V_66 [ V_113 ] ++ ;
if ( V_25 & V_114 )
V_1 -> V_66 [ V_115 ] ++ ;
if ( V_32 & V_116 )
V_1 -> V_66 [ V_117 ] ++ ;
if ( V_32 & V_118 )
V_1 -> V_66 [ V_119 ] ++ ;
V_108 = ( V_1 -> V_25 & ( V_27 | V_28 | V_29 | V_120 | V_121 | V_122 ) ) ^
( V_25 & ( V_27 | V_28 | V_29 | V_120 | V_121 | V_122 ) ) ;
V_109 = ( V_1 -> V_30 & ( V_123 | V_124 | V_125 | 0x0f ) ) ^
( V_30 & ( V_123 | V_124 | V_125 | 0x0f ) ) ;
V_1 -> V_25 = V_25 & ~ ( V_27 | V_28 | V_29 ) ;
V_1 -> V_30 = V_30 ;
V_1 -> V_32 = V_32 ;
F_44 ( & V_1 -> V_23 , V_106 ) ;
if ( V_25 & V_112 )
F_45 ( V_1 -> V_14 , V_126 , & V_1 -> V_102 [ 0 ] -> V_98 ) ;
if ( V_25 & V_114 )
F_45 ( V_1 -> V_14 , V_126 , & V_1 -> V_102 [ 1 ] -> V_98 ) ;
if ( V_32 & V_116 )
F_45 ( V_1 -> V_14 , V_126 , & V_1 -> V_102 [ 2 ] -> V_98 ) ;
if ( V_32 & V_118 )
F_45 ( V_1 -> V_14 , V_126 , & V_1 -> V_102 [ 3 ] -> V_98 ) ;
if ( V_109 & 0x0f )
F_45 ( V_1 -> V_14 , V_126 , & V_1 -> V_102 [ 4 ] -> V_98 ) ;
if ( ( V_109 & V_125 ) | ( V_108 & V_28 ) )
F_45 ( V_1 -> V_14 , V_126 , & V_1 -> V_102 [ 6 ] -> V_98 ) ;
if ( V_108 & V_27 )
F_45 ( V_1 -> V_14 , V_126 , & V_1 -> V_102 [ 8 ] -> V_98 ) ;
if ( V_108 & V_120 )
F_45 ( V_1 -> V_14 , V_126 , & V_1 -> V_102 [ 9 ] -> V_98 ) ;
if ( V_109 & V_124 )
F_45 ( V_1 -> V_14 , V_126 , & V_1 -> V_102 [ 10 ] -> V_98 ) ;
if ( V_109 & V_123 )
F_45 ( V_1 -> V_14 , V_126 , & V_1 -> V_102 [ 11 ] -> V_98 ) ;
if ( V_1 -> V_127 && ( V_108 | V_109 ) != 0 )
V_1 -> V_127 ( V_1 , V_108 , V_109 ) ;
V_111:
V_107 = F_17 ( V_30 ) ;
if ( ! ( V_103 & V_128 ) && V_105 && V_105 -> V_129 != V_107 ) {
F_46 ( V_1 -> V_95 , V_106 ) ;
if ( F_47 ( V_1 -> V_95 ) ) {
F_48 ( V_1 -> V_95 , V_130 ) ;
F_49 ( & V_105 -> V_131 ) ;
V_107 = 1 ;
}
F_50 ( V_1 -> V_95 , V_106 ) ;
}
return V_107 ;
}
static void V_24 ( unsigned long V_88 )
{
struct V_1 * V_8 = (struct V_1 * ) V_88 ;
if ( V_8 -> V_39 )
return;
F_42 ( V_8 , 0 ) ;
F_16 ( & V_8 -> V_9 , 1 + V_42 ) ;
}

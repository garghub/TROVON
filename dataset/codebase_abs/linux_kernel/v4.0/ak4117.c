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
return V_17 < 0 ? V_17 : - V_36 ;
}
void F_13 ( struct V_1 * V_8 , unsigned char V_2 , unsigned char V_37 , unsigned char V_3 )
{
if ( V_2 >= 5 )
return;
F_1 ( V_8 , V_2 , ( V_8 -> V_6 [ V_2 ] & ~ V_37 ) | V_3 ) ;
}
void F_11 ( struct V_1 * V_8 )
{
unsigned char V_38 = V_8 -> V_6 [ V_39 ] , V_2 ;
F_14 ( & V_8 -> V_9 ) ;
V_8 -> V_40 = 1 ;
F_1 ( V_8 , V_39 , 0 ) ;
F_15 ( 200 ) ;
F_1 ( V_8 , V_39 , ( V_38 | V_41 ) & ~ V_42 ) ;
F_15 ( 200 ) ;
for ( V_2 = 1 ; V_2 < 5 ; V_2 ++ )
F_1 ( V_8 , V_2 , V_8 -> V_6 [ V_2 ] ) ;
F_1 ( V_8 , V_39 , V_38 | V_41 | V_42 ) ;
V_8 -> V_40 = 0 ;
F_16 ( & V_8 -> V_9 , 1 + V_43 ) ;
}
static unsigned int F_17 ( unsigned char V_30 )
{
switch ( V_30 & ( V_44 | V_45 | V_46 | V_47 ) ) {
case V_48 : return 32000 ;
case V_49 : return 44100 ;
case V_50 : return 48000 ;
case V_51 : return 88200 ;
case V_52 : return 96000 ;
case V_53 : return 176400 ;
case V_54 : return 192000 ;
default: return 0 ;
}
}
static int F_18 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
V_58 -> type = V_59 ;
V_58 -> V_60 = 1 ;
V_58 -> V_61 . integer . V_62 = 0 ;
V_58 -> V_61 . integer . V_63 = V_64 ;
return 0 ;
}
static int F_19 ( struct V_55 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_8 = F_20 ( V_56 ) ;
long * V_67 ;
F_21 ( & V_8 -> V_23 ) ;
V_67 = ( long * ) ( ( ( char * ) V_8 ) + V_56 -> V_68 ) ;
V_66 -> V_61 . integer . V_61 [ 0 ] = * V_67 ;
* V_67 = 0 ;
F_22 ( & V_8 -> V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_55 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_8 = F_20 ( V_56 ) ;
unsigned char V_2 = V_56 -> V_68 & 0xff ;
unsigned char V_69 = ( V_56 -> V_68 >> 8 ) & 0xff ;
unsigned char V_70 = ( V_56 -> V_68 >> 31 ) & 1 ;
V_66 -> V_61 . integer . V_61 [ 0 ] = ( ( F_2 ( V_8 , V_2 ) & ( 1 << V_69 ) ) ? 1 : 0 ) ^ V_70 ;
return 0 ;
}
static int F_24 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
V_58 -> type = V_59 ;
V_58 -> V_60 = 1 ;
V_58 -> V_61 . integer . V_62 = 0 ;
V_58 -> V_61 . integer . V_63 = 1 ;
return 0 ;
}
static int F_25 ( struct V_55 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_8 = F_20 ( V_56 ) ;
V_66 -> V_61 . integer . V_61 [ 0 ] = ( V_8 -> V_6 [ V_71 ] & V_72 ) ? 1 : 0 ;
return 0 ;
}
static int F_26 ( struct V_55 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_8 = F_20 ( V_56 ) ;
int V_73 ;
T_3 V_74 ;
F_21 ( & V_8 -> V_23 ) ;
V_74 = V_8 -> V_6 [ V_71 ] ;
V_73 = ! ! V_66 -> V_61 . integer . V_61 [ 0 ] != ( ( V_74 & V_72 ) ? 1 : 0 ) ;
if ( V_73 )
F_1 ( V_8 , V_71 , ( V_74 & ~ V_72 ) | ( V_66 -> V_61 . integer . V_61 [ 0 ] ? V_72 : 0 ) ) ;
F_22 ( & V_8 -> V_23 ) ;
return V_73 ;
}
static int F_27 ( struct V_55 * V_56 ,
struct V_57 * V_58 )
{
V_58 -> type = V_59 ;
V_58 -> V_60 = 1 ;
V_58 -> V_61 . integer . V_62 = 0 ;
V_58 -> V_61 . integer . V_63 = 192000 ;
return 0 ;
}
static int F_28 ( struct V_55 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_8 = F_20 ( V_56 ) ;
V_66 -> V_61 . integer . V_61 [ 0 ] = F_17 ( F_2 ( V_8 , V_31 ) ) ;
return 0 ;
}
static int F_29 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
V_58 -> type = V_75 ;
V_58 -> V_60 = 1 ;
return 0 ;
}
static int F_30 ( struct V_55 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_8 = F_20 ( V_56 ) ;
unsigned V_76 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ )
V_66 -> V_61 . V_78 . V_79 [ V_76 ] = F_2 ( V_8 , V_80 + V_76 ) ;
return 0 ;
}
static int F_31 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
V_58 -> type = V_75 ;
V_58 -> V_60 = 1 ;
return 0 ;
}
static int F_32 ( struct V_55 * V_56 ,
struct V_65 * V_66 )
{
memset ( V_66 -> V_61 . V_78 . V_79 , 0xff , V_77 ) ;
return 0 ;
}
static int F_33 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
V_58 -> type = V_59 ;
V_58 -> V_61 . integer . V_62 = 0 ;
V_58 -> V_61 . integer . V_63 = 0xffff ;
V_58 -> V_60 = 4 ;
return 0 ;
}
static int F_34 ( struct V_55 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_8 = F_20 ( V_56 ) ;
unsigned short V_81 ;
V_66 -> V_61 . integer . V_61 [ 0 ] = 0xf8f2 ;
V_66 -> V_61 . integer . V_61 [ 1 ] = 0x4e1f ;
V_81 = F_2 ( V_8 , V_82 ) | ( F_2 ( V_8 , V_83 ) << 8 ) ;
V_66 -> V_61 . integer . V_61 [ 2 ] = V_81 ;
V_81 = F_2 ( V_8 , V_84 ) | ( F_2 ( V_8 , V_85 ) << 8 ) ;
V_66 -> V_61 . integer . V_61 [ 3 ] = V_81 ;
return 0 ;
}
static int F_35 ( struct V_55 * V_56 , struct V_57 * V_58 )
{
V_58 -> type = V_86 ;
V_58 -> V_60 = V_87 ;
return 0 ;
}
static int F_36 ( struct V_55 * V_56 ,
struct V_65 * V_66 )
{
struct V_1 * V_8 = F_20 ( V_56 ) ;
unsigned V_76 ;
for ( V_76 = 0 ; V_76 < V_87 ; V_76 ++ )
V_66 -> V_61 . V_88 . V_89 [ V_76 ] = F_2 ( V_8 , V_90 + V_76 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_1 , struct V_91 * V_92 )
{
struct V_55 * V_93 ;
unsigned int V_94 ;
int V_17 ;
if ( F_38 ( ! V_92 ) )
return - V_95 ;
V_1 -> V_96 = V_92 ;
for ( V_94 = 0 ; V_94 < V_97 ; V_94 ++ ) {
V_93 = F_39 ( & V_98 [ V_94 ] , V_1 ) ;
if ( V_93 == NULL )
return - V_22 ;
V_93 -> V_99 . V_11 = V_92 -> V_100 -> V_11 ;
V_93 -> V_99 . V_101 = V_92 -> V_102 ;
V_17 = F_40 ( V_1 -> V_14 , V_93 ) ;
if ( V_17 < 0 )
return V_17 ;
V_1 -> V_103 [ V_94 ] = V_93 ;
}
return 0 ;
}
int F_41 ( struct V_1 * V_1 )
{
unsigned char V_30 ;
V_30 = F_2 ( V_1 , V_31 ) ;
return F_17 ( V_30 ) ;
}
int F_42 ( struct V_1 * V_1 , unsigned int V_104 )
{
struct V_105 * V_106 = V_1 -> V_96 ? V_1 -> V_96 -> V_106 : NULL ;
unsigned long V_107 ;
int V_108 = 0 ;
unsigned char V_25 , V_30 , V_32 ;
unsigned char V_109 , V_110 ;
V_30 = F_2 ( V_1 , V_31 ) ;
if ( V_104 & V_111 )
goto V_112;
V_25 = F_2 ( V_1 , V_26 ) ;
V_32 = F_2 ( V_1 , V_33 ) ;
F_43 ( & V_1 -> V_23 , V_107 ) ;
if ( V_25 & V_113 )
V_1 -> V_114 ++ ;
if ( V_25 & V_115 )
V_1 -> V_116 ++ ;
if ( V_32 & V_117 )
V_1 -> V_118 ++ ;
if ( V_32 & V_119 )
V_1 -> V_120 ++ ;
V_109 = ( V_1 -> V_25 & ( V_27 | V_28 | V_29 | V_121 | V_122 | V_123 ) ) ^
( V_25 & ( V_27 | V_28 | V_29 | V_121 | V_122 | V_123 ) ) ;
V_110 = ( V_1 -> V_30 & ( V_124 | V_125 | V_126 | 0x0f ) ) ^
( V_30 & ( V_124 | V_125 | V_126 | 0x0f ) ) ;
V_1 -> V_25 = V_25 & ~ ( V_27 | V_28 | V_29 ) ;
V_1 -> V_30 = V_30 ;
V_1 -> V_32 = V_32 ;
F_44 ( & V_1 -> V_23 , V_107 ) ;
if ( V_25 & V_113 )
F_45 ( V_1 -> V_14 , V_127 , & V_1 -> V_103 [ 0 ] -> V_99 ) ;
if ( V_25 & V_115 )
F_45 ( V_1 -> V_14 , V_127 , & V_1 -> V_103 [ 1 ] -> V_99 ) ;
if ( V_32 & V_117 )
F_45 ( V_1 -> V_14 , V_127 , & V_1 -> V_103 [ 2 ] -> V_99 ) ;
if ( V_32 & V_119 )
F_45 ( V_1 -> V_14 , V_127 , & V_1 -> V_103 [ 3 ] -> V_99 ) ;
if ( V_110 & 0x0f )
F_45 ( V_1 -> V_14 , V_127 , & V_1 -> V_103 [ 4 ] -> V_99 ) ;
if ( ( V_110 & V_126 ) | ( V_109 & V_28 ) )
F_45 ( V_1 -> V_14 , V_127 , & V_1 -> V_103 [ 6 ] -> V_99 ) ;
if ( V_109 & V_27 )
F_45 ( V_1 -> V_14 , V_127 , & V_1 -> V_103 [ 8 ] -> V_99 ) ;
if ( V_109 & V_121 )
F_45 ( V_1 -> V_14 , V_127 , & V_1 -> V_103 [ 9 ] -> V_99 ) ;
if ( V_110 & V_125 )
F_45 ( V_1 -> V_14 , V_127 , & V_1 -> V_103 [ 10 ] -> V_99 ) ;
if ( V_110 & V_124 )
F_45 ( V_1 -> V_14 , V_127 , & V_1 -> V_103 [ 11 ] -> V_99 ) ;
if ( V_1 -> V_128 && ( V_109 | V_110 ) != 0 )
V_1 -> V_128 ( V_1 , V_109 , V_110 ) ;
V_112:
V_108 = F_17 ( V_30 ) ;
if ( ! ( V_104 & V_129 ) && V_106 && V_106 -> V_130 != V_108 ) {
F_46 ( V_1 -> V_96 , V_107 ) ;
if ( F_47 ( V_1 -> V_96 ) ) {
F_48 ( V_1 -> V_96 , V_131 ) ;
F_49 ( & V_106 -> V_132 ) ;
V_108 = 1 ;
}
F_50 ( V_1 -> V_96 , V_107 ) ;
}
return V_108 ;
}
static void V_24 ( unsigned long V_89 )
{
struct V_1 * V_8 = (struct V_1 * ) V_89 ;
if ( V_8 -> V_40 )
return;
F_42 ( V_8 , 0 ) ;
F_16 ( & V_8 -> V_9 , 1 + V_43 ) ;
}

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
F_10 ( & V_8 -> V_9 ) ;
V_8 -> V_9 . V_24 = ( unsigned long ) V_8 ;
V_8 -> V_9 . V_25 = V_26 ;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ )
V_8 -> V_6 [ V_2 ] = V_15 [ V_2 ] ;
F_11 ( V_8 ) ;
V_8 -> V_27 = F_2 ( V_8 , V_28 ) & ~ ( V_29 | V_30 | V_31 ) ;
V_8 -> V_32 = F_2 ( V_8 , V_33 ) ;
V_8 -> V_34 = F_2 ( V_8 , V_35 ) ;
if ( ( V_17 = F_12 ( V_14 , V_36 , V_8 , & V_19 ) ) < 0 )
goto V_37;
if ( V_16 )
* V_16 = V_8 ;
return 0 ;
V_37:
F_3 ( V_8 ) ;
return V_17 < 0 ? V_17 : - V_38 ;
}
void F_13 ( struct V_1 * V_8 , unsigned char V_2 , unsigned char V_39 , unsigned char V_3 )
{
if ( V_2 >= 5 )
return;
F_1 ( V_8 , V_2 , ( V_8 -> V_6 [ V_2 ] & ~ V_39 ) | V_3 ) ;
}
void F_11 ( struct V_1 * V_8 )
{
unsigned char V_40 = V_8 -> V_6 [ V_41 ] , V_2 ;
F_14 ( & V_8 -> V_9 ) ;
V_8 -> V_42 = 1 ;
F_1 ( V_8 , V_41 , 0 ) ;
F_15 ( 200 ) ;
F_1 ( V_8 , V_41 , ( V_40 | V_43 ) & ~ V_44 ) ;
F_15 ( 200 ) ;
for ( V_2 = 1 ; V_2 < 5 ; V_2 ++ )
F_1 ( V_8 , V_2 , V_8 -> V_6 [ V_2 ] ) ;
F_1 ( V_8 , V_41 , V_40 | V_43 | V_44 ) ;
V_8 -> V_42 = 0 ;
V_8 -> V_9 . V_45 = 1 + V_46 ;
F_16 ( & V_8 -> V_9 ) ;
}
static unsigned int F_17 ( unsigned char V_32 )
{
switch ( V_32 & ( V_47 | V_48 | V_49 | V_50 ) ) {
case V_51 : return 32000 ;
case V_52 : return 44100 ;
case V_53 : return 48000 ;
case V_54 : return 88200 ;
case V_55 : return 96000 ;
case V_56 : return 176400 ;
case V_57 : return 192000 ;
default: return 0 ;
}
}
static int F_18 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
V_61 -> type = V_62 ;
V_61 -> V_63 = 1 ;
V_61 -> V_64 . integer . V_65 = 0 ;
V_61 -> V_64 . integer . V_66 = V_67 ;
return 0 ;
}
static int F_19 ( struct V_58 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_8 = F_20 ( V_59 ) ;
long * V_70 ;
F_21 ( & V_8 -> V_23 ) ;
V_70 = ( long * ) ( ( ( char * ) V_8 ) + V_59 -> V_71 ) ;
V_69 -> V_64 . integer . V_64 [ 0 ] = * V_70 ;
* V_70 = 0 ;
F_22 ( & V_8 -> V_23 ) ;
return 0 ;
}
static int F_23 ( struct V_58 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_8 = F_20 ( V_59 ) ;
unsigned char V_2 = V_59 -> V_71 & 0xff ;
unsigned char V_72 = ( V_59 -> V_71 >> 8 ) & 0xff ;
unsigned char V_73 = ( V_59 -> V_71 >> 31 ) & 1 ;
V_69 -> V_64 . integer . V_64 [ 0 ] = ( ( F_2 ( V_8 , V_2 ) & ( 1 << V_72 ) ) ? 1 : 0 ) ^ V_73 ;
return 0 ;
}
static int F_24 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
V_61 -> type = V_62 ;
V_61 -> V_63 = 1 ;
V_61 -> V_64 . integer . V_65 = 0 ;
V_61 -> V_64 . integer . V_66 = 1 ;
return 0 ;
}
static int F_25 ( struct V_58 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_8 = F_20 ( V_59 ) ;
V_69 -> V_64 . integer . V_64 [ 0 ] = ( V_8 -> V_6 [ V_74 ] & V_75 ) ? 1 : 0 ;
return 0 ;
}
static int F_26 ( struct V_58 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_8 = F_20 ( V_59 ) ;
int V_76 ;
T_3 V_77 ;
F_21 ( & V_8 -> V_23 ) ;
V_77 = V_8 -> V_6 [ V_74 ] ;
V_76 = ! ! V_69 -> V_64 . integer . V_64 [ 0 ] != ( ( V_77 & V_75 ) ? 1 : 0 ) ;
if ( V_76 )
F_1 ( V_8 , V_74 , ( V_77 & ~ V_75 ) | ( V_69 -> V_64 . integer . V_64 [ 0 ] ? V_75 : 0 ) ) ;
F_22 ( & V_8 -> V_23 ) ;
return V_76 ;
}
static int F_27 ( struct V_58 * V_59 ,
struct V_60 * V_61 )
{
V_61 -> type = V_62 ;
V_61 -> V_63 = 1 ;
V_61 -> V_64 . integer . V_65 = 0 ;
V_61 -> V_64 . integer . V_66 = 192000 ;
return 0 ;
}
static int F_28 ( struct V_58 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_8 = F_20 ( V_59 ) ;
V_69 -> V_64 . integer . V_64 [ 0 ] = F_17 ( F_2 ( V_8 , V_33 ) ) ;
return 0 ;
}
static int F_29 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
V_61 -> type = V_78 ;
V_61 -> V_63 = 1 ;
return 0 ;
}
static int F_30 ( struct V_58 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_8 = F_20 ( V_59 ) ;
unsigned V_79 ;
for ( V_79 = 0 ; V_79 < V_80 ; V_79 ++ )
V_69 -> V_64 . V_81 . V_82 [ V_79 ] = F_2 ( V_8 , V_83 + V_79 ) ;
return 0 ;
}
static int F_31 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
V_61 -> type = V_78 ;
V_61 -> V_63 = 1 ;
return 0 ;
}
static int F_32 ( struct V_58 * V_59 ,
struct V_68 * V_69 )
{
memset ( V_69 -> V_64 . V_81 . V_82 , 0xff , V_80 ) ;
return 0 ;
}
static int F_33 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
V_61 -> type = V_62 ;
V_61 -> V_64 . integer . V_65 = 0 ;
V_61 -> V_64 . integer . V_66 = 0xffff ;
V_61 -> V_63 = 4 ;
return 0 ;
}
static int F_34 ( struct V_58 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_8 = F_20 ( V_59 ) ;
unsigned short V_84 ;
V_69 -> V_64 . integer . V_64 [ 0 ] = 0xf8f2 ;
V_69 -> V_64 . integer . V_64 [ 1 ] = 0x4e1f ;
V_84 = F_2 ( V_8 , V_85 ) | ( F_2 ( V_8 , V_86 ) << 8 ) ;
V_69 -> V_64 . integer . V_64 [ 2 ] = V_84 ;
V_84 = F_2 ( V_8 , V_87 ) | ( F_2 ( V_8 , V_88 ) << 8 ) ;
V_69 -> V_64 . integer . V_64 [ 3 ] = V_84 ;
return 0 ;
}
static int F_35 ( struct V_58 * V_59 , struct V_60 * V_61 )
{
V_61 -> type = V_89 ;
V_61 -> V_63 = V_90 ;
return 0 ;
}
static int F_36 ( struct V_58 * V_59 ,
struct V_68 * V_69 )
{
struct V_1 * V_8 = F_20 ( V_59 ) ;
unsigned V_79 ;
for ( V_79 = 0 ; V_79 < V_90 ; V_79 ++ )
V_69 -> V_64 . V_91 . V_24 [ V_79 ] = F_2 ( V_8 , V_92 + V_79 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_1 , struct V_93 * V_94 )
{
struct V_58 * V_95 ;
unsigned int V_96 ;
int V_17 ;
if ( F_38 ( ! V_94 ) )
return - V_97 ;
V_1 -> V_98 = V_94 ;
for ( V_96 = 0 ; V_96 < V_99 ; V_96 ++ ) {
V_95 = F_39 ( & V_100 [ V_96 ] , V_1 ) ;
if ( V_95 == NULL )
return - V_22 ;
V_95 -> V_101 . V_11 = V_94 -> V_102 -> V_11 ;
V_95 -> V_101 . V_103 = V_94 -> V_104 ;
V_17 = F_40 ( V_1 -> V_14 , V_95 ) ;
if ( V_17 < 0 )
return V_17 ;
V_1 -> V_105 [ V_96 ] = V_95 ;
}
return 0 ;
}
int F_41 ( struct V_1 * V_1 )
{
unsigned char V_32 ;
V_32 = F_2 ( V_1 , V_33 ) ;
return F_17 ( V_32 ) ;
}
int F_42 ( struct V_1 * V_1 , unsigned int V_106 )
{
struct V_107 * V_108 = V_1 -> V_98 ? V_1 -> V_98 -> V_108 : NULL ;
unsigned long V_109 ;
int V_110 = 0 ;
unsigned char V_27 , V_32 , V_34 ;
unsigned char V_111 , V_112 ;
V_32 = F_2 ( V_1 , V_33 ) ;
if ( V_106 & V_113 )
goto V_114;
V_27 = F_2 ( V_1 , V_28 ) ;
V_34 = F_2 ( V_1 , V_35 ) ;
F_43 ( & V_1 -> V_23 , V_109 ) ;
if ( V_27 & V_115 )
V_1 -> V_116 ++ ;
if ( V_27 & V_117 )
V_1 -> V_118 ++ ;
if ( V_34 & V_119 )
V_1 -> V_120 ++ ;
if ( V_34 & V_121 )
V_1 -> V_122 ++ ;
V_111 = ( V_1 -> V_27 & ( V_29 | V_30 | V_31 | V_123 | V_124 | V_125 ) ) ^
( V_27 & ( V_29 | V_30 | V_31 | V_123 | V_124 | V_125 ) ) ;
V_112 = ( V_1 -> V_32 & ( V_126 | V_127 | V_128 | 0x0f ) ) ^
( V_32 & ( V_126 | V_127 | V_128 | 0x0f ) ) ;
V_1 -> V_27 = V_27 & ~ ( V_29 | V_30 | V_31 ) ;
V_1 -> V_32 = V_32 ;
V_1 -> V_34 = V_34 ;
F_44 ( & V_1 -> V_23 , V_109 ) ;
if ( V_27 & V_115 )
F_45 ( V_1 -> V_14 , V_129 , & V_1 -> V_105 [ 0 ] -> V_101 ) ;
if ( V_27 & V_117 )
F_45 ( V_1 -> V_14 , V_129 , & V_1 -> V_105 [ 1 ] -> V_101 ) ;
if ( V_34 & V_119 )
F_45 ( V_1 -> V_14 , V_129 , & V_1 -> V_105 [ 2 ] -> V_101 ) ;
if ( V_34 & V_121 )
F_45 ( V_1 -> V_14 , V_129 , & V_1 -> V_105 [ 3 ] -> V_101 ) ;
if ( V_112 & 0x0f )
F_45 ( V_1 -> V_14 , V_129 , & V_1 -> V_105 [ 4 ] -> V_101 ) ;
if ( ( V_112 & V_128 ) | ( V_111 & V_30 ) )
F_45 ( V_1 -> V_14 , V_129 , & V_1 -> V_105 [ 6 ] -> V_101 ) ;
if ( V_111 & V_29 )
F_45 ( V_1 -> V_14 , V_129 , & V_1 -> V_105 [ 8 ] -> V_101 ) ;
if ( V_111 & V_123 )
F_45 ( V_1 -> V_14 , V_129 , & V_1 -> V_105 [ 9 ] -> V_101 ) ;
if ( V_112 & V_127 )
F_45 ( V_1 -> V_14 , V_129 , & V_1 -> V_105 [ 10 ] -> V_101 ) ;
if ( V_112 & V_126 )
F_45 ( V_1 -> V_14 , V_129 , & V_1 -> V_105 [ 11 ] -> V_101 ) ;
if ( V_1 -> V_130 && ( V_111 | V_112 ) != 0 )
V_1 -> V_130 ( V_1 , V_111 , V_112 ) ;
V_114:
V_110 = F_17 ( V_32 ) ;
if ( ! ( V_106 & V_131 ) && V_108 && V_108 -> V_132 != V_110 ) {
F_46 ( V_1 -> V_98 , V_109 ) ;
if ( F_47 ( V_1 -> V_98 ) ) {
F_48 ( V_1 -> V_98 , V_133 ) ;
F_49 ( & V_108 -> V_134 ) ;
V_110 = 1 ;
}
F_50 ( V_1 -> V_98 , V_109 ) ;
}
return V_110 ;
}
static void V_26 ( unsigned long V_24 )
{
struct V_1 * V_8 = (struct V_1 * ) V_24 ;
if ( V_8 -> V_42 )
return;
F_42 ( V_8 , 0 ) ;
V_8 -> V_9 . V_45 = 1 + V_46 ;
F_16 ( & V_8 -> V_9 ) ;
}

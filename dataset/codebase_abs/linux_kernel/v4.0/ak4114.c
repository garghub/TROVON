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
return V_22 < 0 ? V_22 : - V_39 ;
}
void F_16 ( struct V_1 * V_12 , unsigned char V_2 , unsigned char V_40 , unsigned char V_3 )
{
if ( V_2 <= V_6 )
F_1 ( V_12 , V_2 , ( V_12 -> V_7 [ V_2 ] & ~ V_40 ) | V_3 ) ;
else if ( V_2 >= V_8 && V_2 <= V_9 )
F_1 ( V_12 , V_2 ,
( V_12 -> V_10 [ V_2 - V_8 ] & ~ V_40 ) | V_3 ) ;
}
static void F_14 ( struct V_1 * V_12 )
{
unsigned char V_41 = V_12 -> V_7 [ V_42 ] , V_2 ;
F_1 ( V_12 , V_42 , V_41 & ~ ( V_43 | V_44 ) ) ;
F_17 ( 200 ) ;
F_1 ( V_12 , V_42 , ( V_41 | V_43 ) & ~ V_44 ) ;
F_17 ( 200 ) ;
for ( V_2 = 1 ; V_2 < 6 ; V_2 ++ )
F_1 ( V_12 , V_2 , V_12 -> V_7 [ V_2 ] ) ;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ )
F_1 ( V_12 , V_2 + V_8 , V_12 -> V_10 [ V_2 ] ) ;
F_1 ( V_12 , V_42 , V_41 | V_43 | V_44 ) ;
}
void F_18 ( struct V_1 * V_12 )
{
if ( F_19 ( & V_12 -> V_13 ) == 1 )
F_5 ( & V_12 -> V_14 ) ;
F_20 ( & V_12 -> V_30 ) ;
F_14 ( V_12 ) ;
F_21 ( & V_12 -> V_30 ) ;
if ( F_22 ( & V_12 -> V_13 ) )
F_23 ( & V_12 -> V_14 , V_45 / 10 ) ;
}
static unsigned int F_24 ( unsigned char V_35 )
{
switch ( V_35 & ( V_46 | V_47 | V_48 | V_49 ) ) {
case V_50 : return 32000 ;
case V_51 : return 44100 ;
case V_52 : return 48000 ;
case V_53 : return 88200 ;
case V_54 : return 96000 ;
case V_55 : return 176400 ;
case V_56 : return 192000 ;
default: return 0 ;
}
}
static int F_25 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
V_60 -> type = V_61 ;
V_60 -> V_62 = 1 ;
V_60 -> V_63 . integer . V_64 = 0 ;
V_60 -> V_63 . integer . V_65 = V_66 ;
return 0 ;
}
static int F_26 ( struct V_57 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_12 = F_27 ( V_58 ) ;
long * V_69 ;
F_28 ( & V_12 -> V_28 ) ;
V_69 = ( long * ) ( ( ( char * ) V_12 ) + V_58 -> V_70 ) ;
V_68 -> V_63 . integer . V_63 [ 0 ] = * V_69 ;
* V_69 = 0 ;
F_29 ( & V_12 -> V_28 ) ;
return 0 ;
}
static int F_30 ( struct V_57 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_12 = F_27 ( V_58 ) ;
unsigned char V_2 = V_58 -> V_70 & 0xff ;
unsigned char V_71 = ( V_58 -> V_70 >> 8 ) & 0xff ;
unsigned char V_72 = ( V_58 -> V_70 >> 31 ) & 1 ;
V_68 -> V_63 . integer . V_63 [ 0 ] = ( ( F_2 ( V_12 , V_2 ) & ( 1 << V_71 ) ) ? 1 : 0 ) ^ V_72 ;
return 0 ;
}
static int F_31 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
V_60 -> type = V_61 ;
V_60 -> V_62 = 1 ;
V_60 -> V_63 . integer . V_64 = 0 ;
V_60 -> V_63 . integer . V_65 = 192000 ;
return 0 ;
}
static int F_32 ( struct V_57 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_12 = F_27 ( V_58 ) ;
V_68 -> V_63 . integer . V_63 [ 0 ] = F_24 ( F_2 ( V_12 , V_36 ) ) ;
return 0 ;
}
static int F_33 ( struct V_57 * V_58 , struct V_59 * V_60 )
{
V_60 -> type = V_73 ;
V_60 -> V_62 = 1 ;
return 0 ;
}
static int F_34 ( struct V_57 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_12 = F_27 ( V_58 ) ;
unsigned V_74 ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ )
V_68 -> V_63 . V_76 . V_77 [ V_74 ] = F_2 ( V_12 , V_78 + V_74 ) ;
return 0 ;
}
static int F_35 ( struct V_57 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_12 = F_27 ( V_58 ) ;
unsigned V_74 ;
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ )
V_68 -> V_63 . V_76 . V_77 [ V_74 ] = V_12 -> V_10 [ V_74 ] ;
return 0 ;
}
static int F_36 ( struct V_57 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_12 = F_27 ( V_58 ) ;
unsigned V_74 ;
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ )
F_1 ( V_12 , V_8 + V_74 , V_68 -> V_63 . V_76 . V_77 [ V_74 ] ) ;
return 0 ;
}
static int F_37 ( struct V_57 * V_58 , struct V_59 * V_60 )
{
V_60 -> type = V_73 ;
V_60 -> V_62 = 1 ;
return 0 ;
}
static int F_38 ( struct V_57 * V_58 ,
struct V_67 * V_68 )
{
memset ( V_68 -> V_63 . V_76 . V_77 , 0xff , V_75 ) ;
return 0 ;
}
static int F_39 ( struct V_57 * V_58 , struct V_59 * V_60 )
{
V_60 -> type = V_61 ;
V_60 -> V_63 . integer . V_64 = 0 ;
V_60 -> V_63 . integer . V_65 = 0xffff ;
V_60 -> V_62 = 4 ;
return 0 ;
}
static int F_40 ( struct V_57 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_12 = F_27 ( V_58 ) ;
unsigned short V_80 ;
V_68 -> V_63 . integer . V_63 [ 0 ] = 0xf8f2 ;
V_68 -> V_63 . integer . V_63 [ 1 ] = 0x4e1f ;
V_80 = F_2 ( V_12 , V_81 ) | ( F_2 ( V_12 , V_82 ) << 8 ) ;
V_68 -> V_63 . integer . V_63 [ 2 ] = V_80 ;
V_80 = F_2 ( V_12 , V_83 ) | ( F_2 ( V_12 , V_84 ) << 8 ) ;
V_68 -> V_63 . integer . V_63 [ 3 ] = V_80 ;
return 0 ;
}
static int F_41 ( struct V_57 * V_58 , struct V_59 * V_60 )
{
V_60 -> type = V_85 ;
V_60 -> V_62 = V_86 ;
return 0 ;
}
static int F_42 ( struct V_57 * V_58 ,
struct V_67 * V_68 )
{
struct V_1 * V_12 = F_27 ( V_58 ) ;
unsigned V_74 ;
for ( V_74 = 0 ; V_74 < V_86 ; V_74 ++ )
V_68 -> V_63 . V_87 . V_88 [ V_74 ] = F_2 ( V_12 , V_89 + V_74 ) ;
return 0 ;
}
static void F_43 ( struct V_90 * V_91 ,
struct V_92 * V_93 )
{
struct V_1 * V_1 = V_91 -> V_5 ;
int V_2 , V_3 ;
for ( V_2 = 0 ; V_2 < 0x20 ; V_2 ++ ) {
V_3 = F_2 ( V_1 , V_2 ) ;
F_44 ( V_93 , L_1 , V_2 , V_3 ) ;
}
}
static void F_45 ( struct V_1 * V_1 )
{
struct V_90 * V_91 ;
if ( ! F_46 ( V_1 -> V_19 , L_2 , & V_91 ) )
F_47 ( V_91 , V_1 , F_43 ) ;
}
int F_48 ( struct V_1 * V_1 ,
struct V_94 * V_95 ,
struct V_94 * V_96 )
{
struct V_57 * V_97 ;
unsigned int V_98 ;
int V_22 ;
if ( F_49 ( ! V_96 ) )
return - V_99 ;
V_1 -> V_100 = V_95 ;
V_1 -> V_101 = V_96 ;
for ( V_98 = 0 ; V_98 < V_102 ; V_98 ++ ) {
V_97 = F_50 ( & V_103 [ V_98 ] , V_1 ) ;
if ( V_97 == NULL )
return - V_27 ;
if ( strstr ( V_97 -> V_104 . V_105 , L_3 ) ) {
if ( V_95 == NULL ) {
F_51 ( V_97 ) ;
V_1 -> V_106 [ V_98 ] = NULL ;
continue;
}
V_97 -> V_104 . V_16 = V_95 -> V_107 -> V_16 ;
V_97 -> V_104 . V_108 = V_95 -> V_109 ;
} else {
V_97 -> V_104 . V_16 = V_96 -> V_107 -> V_16 ;
V_97 -> V_104 . V_108 = V_96 -> V_109 ;
}
V_22 = F_52 ( V_1 -> V_19 , V_97 ) ;
if ( V_22 < 0 )
return V_22 ;
V_1 -> V_106 [ V_98 ] = V_97 ;
}
F_45 ( V_1 ) ;
F_23 ( & V_1 -> V_14 , V_45 / 10 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_1 ,
unsigned char V_31 , unsigned char V_35 ,
unsigned char V_110 , unsigned char V_111 )
{
if ( ! V_1 -> V_106 [ 0 ] )
return;
if ( V_31 & V_112 )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 0 ] -> V_104 ) ;
if ( V_31 & V_114 )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 1 ] -> V_104 ) ;
if ( V_35 & V_115 )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 2 ] -> V_104 ) ;
if ( V_35 & V_116 )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 3 ] -> V_104 ) ;
if ( V_111 & 0xf0 )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 4 ] -> V_104 ) ;
if ( ( V_110 & V_117 ) | ( V_110 & V_34 ) )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 9 ] -> V_104 ) ;
if ( V_110 & V_33 )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 10 ] -> V_104 ) ;
if ( V_110 & V_118 )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 11 ] -> V_104 ) ;
if ( V_110 & V_119 )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 12 ] -> V_104 ) ;
if ( V_110 & V_120 )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 13 ] -> V_104 ) ;
if ( V_110 & V_121 )
F_54 ( V_1 -> V_19 , V_113 ,
& V_1 -> V_106 [ 14 ] -> V_104 ) ;
}
int F_55 ( struct V_1 * V_1 )
{
unsigned char V_35 ;
V_35 = F_2 ( V_1 , V_36 ) ;
return F_24 ( V_35 ) ;
}
int F_56 ( struct V_1 * V_1 , unsigned int V_122 )
{
struct V_123 * V_124 = V_1 -> V_101 ? V_1 -> V_101 -> V_124 : NULL ;
unsigned long V_125 ;
int V_126 = 0 ;
unsigned char V_31 , V_35 ;
unsigned char V_110 , V_111 ;
V_35 = F_2 ( V_1 , V_36 ) ;
if ( V_122 & V_127 )
goto V_128;
V_31 = F_2 ( V_1 , V_32 ) ;
F_57 ( & V_1 -> V_28 , V_125 ) ;
if ( V_31 & V_112 )
V_1 -> V_129 ++ ;
if ( V_35 & V_114 )
V_1 -> V_130 ++ ;
if ( V_35 & V_115 )
V_1 -> V_131 ++ ;
if ( V_35 & V_116 )
V_1 -> V_132 ++ ;
V_110 = ( V_1 -> V_31 & ( V_33 | V_34 | V_117 | V_118 | V_119 | V_121 ) ) ^
( V_31 & ( V_33 | V_34 | V_117 | V_118 | V_119 | V_121 ) ) ;
V_111 = ( V_1 -> V_35 & 0xf0 ) ^ ( V_35 & 0xf0 ) ;
V_1 -> V_31 = V_31 & ~ ( V_33 | V_34 ) ;
V_1 -> V_35 = V_35 ;
F_58 ( & V_1 -> V_28 , V_125 ) ;
F_53 ( V_1 , V_31 , V_35 , V_110 , V_111 ) ;
if ( V_1 -> V_133 && ( V_110 | V_111 ) != 0 )
V_1 -> V_133 ( V_1 , V_110 , V_111 ) ;
V_128:
V_126 = F_24 ( V_35 ) ;
if ( ! ( V_122 & V_134 ) && V_124 && V_124 -> V_135 != V_126 ) {
F_59 ( V_1 -> V_101 , V_125 ) ;
if ( F_60 ( V_1 -> V_101 ) ) {
F_61 ( V_1 -> V_101 , V_136 ) ;
V_126 = 1 ;
}
F_62 ( V_1 -> V_101 , V_125 ) ;
}
return V_126 ;
}
static void V_29 ( struct V_137 * V_14 )
{
struct V_1 * V_12 = F_63 ( V_14 , struct V_1 , V_14 . V_14 ) ;
if ( F_19 ( & V_12 -> V_13 ) == 1 )
F_56 ( V_12 , V_12 -> V_138 ) ;
if ( F_22 ( & V_12 -> V_13 ) )
F_23 ( & V_12 -> V_14 , V_45 / 10 ) ;
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
